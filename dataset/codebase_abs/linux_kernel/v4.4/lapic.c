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
F_60 ( V_73 , V_9 ) ;
}
static inline void F_61 ( int V_6 , struct V_1 * V_2 )
{
F_7 ( V_6 , V_2 -> V_5 + V_13 ) ;
V_2 -> V_74 = true ;
}
static inline int F_62 ( struct V_1 * V_2 )
{
return F_53 ( V_2 -> V_5 + V_13 ) ;
}
static inline int F_63 ( struct V_1 * V_2 )
{
int V_75 ;
if ( ! V_2 -> V_74 )
return - 1 ;
V_76 -> V_77 ( V_2 -> V_9 ) ;
V_75 = F_62 ( V_2 ) ;
ASSERT ( V_75 == - 1 || V_75 >= 16 ) ;
return V_75 ;
}
static inline void F_64 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = V_2 -> V_9 ;
if ( F_65 ( F_66 ( V_9 ) ) ) {
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
F_60 ( V_73 , V_9 ) ;
} else {
V_2 -> V_74 = false ;
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
if ( F_62 ( V_2 ) != - 1 )
V_2 -> V_74 = true ;
}
}
static inline void F_67 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( F_11 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_65 ( V_76 -> V_78 ) )
V_76 -> V_78 ( V_9 -> V_25 , V_6 ) ;
else {
++ V_2 -> V_79 ;
F_68 ( V_2 -> V_79 > V_68 ) ;
V_2 -> V_80 = V_6 ;
}
}
static inline int F_69 ( struct V_1 * V_2 )
{
int V_75 ;
if ( ! V_2 -> V_79 )
return - 1 ;
if ( F_70 ( V_2 -> V_80 != - 1 ) )
return V_2 -> V_80 ;
V_75 = F_53 ( V_2 -> V_5 + V_12 ) ;
ASSERT ( V_75 == - 1 || V_75 >= 16 ) ;
return V_75 ;
}
static inline void F_71 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( ! F_13 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_65 ( V_76 -> V_78 ) )
V_76 -> V_78 ( V_9 -> V_25 ,
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
V_81 = F_63 ( V_9 -> V_11 . V_2 ) ;
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
static void F_86 ( struct V_1 * V_2 )
{
T_1 V_96 , V_97 , V_98 , V_99 ;
int V_100 ;
V_99 = F_19 ( V_2 , V_101 ) ;
V_96 = F_19 ( V_2 , V_102 ) ;
V_100 = F_69 ( V_2 ) ;
V_97 = ( V_100 != - 1 ) ? V_100 : 0 ;
if ( ( V_96 & 0xf0 ) >= ( V_97 & 0xf0 ) )
V_98 = V_96 & 0xff ;
else
V_98 = V_97 & 0xf0 ;
F_81 ( L_4 ,
V_2 , V_98 , V_100 , V_97 ) ;
if ( V_99 != V_98 ) {
F_1 ( V_2 , V_101 , V_98 ) ;
if ( V_98 < V_99 )
F_60 ( V_73 , V_2 -> V_9 ) ;
}
}
static void F_87 ( struct V_1 * V_2 , T_1 V_96 )
{
F_1 ( V_2 , V_102 , V_96 ) ;
F_86 ( V_2 ) ;
}
static bool F_88 ( struct V_1 * V_2 , T_1 V_103 )
{
if ( F_29 ( V_2 ) )
return V_103 == V_104 ;
return F_89 ( V_103 ) == V_105 ;
}
static bool F_90 ( struct V_1 * V_2 , T_1 V_103 )
{
if ( F_88 ( V_2 , V_103 ) )
return true ;
if ( F_29 ( V_2 ) )
return V_103 == F_18 ( V_2 ) ;
return V_103 == F_91 ( F_18 ( V_2 ) ) ;
}
static bool F_92 ( struct V_1 * V_2 , T_1 V_103 )
{
T_1 V_106 ;
if ( F_88 ( V_2 , V_103 ) )
return true ;
V_106 = F_19 ( V_2 , V_34 ) ;
if ( F_29 ( V_2 ) )
return ( ( V_106 >> 16 ) == ( V_103 >> 16 ) )
&& ( V_106 & V_103 & 0xffff ) != 0 ;
V_106 = F_30 ( V_106 ) ;
V_103 = F_89 ( V_103 ) ;
switch ( F_19 ( V_2 , V_36 ) ) {
case V_37 :
return ( V_106 & V_103 ) != 0 ;
case V_107 :
return ( ( V_106 >> 4 ) == ( V_103 >> 4 ) )
&& ( V_106 & V_103 & 0xf ) != 0 ;
default:
F_81 ( L_5 ,
V_2 -> V_9 -> V_108 , F_19 ( V_2 , V_36 ) ) ;
return false ;
}
}
static T_1 F_93 ( unsigned int V_18 , struct V_1 * V_109 ,
struct V_1 * V_110 )
{
bool V_111 = V_109 != NULL ;
bool V_112 = F_29 ( V_111 ? V_109 : V_110 ) ;
if ( ! V_111 && V_18 == V_105 && V_112 )
return V_104 ;
return V_112 ? V_18 : F_91 ( V_18 ) ;
}
bool F_94 ( struct V_8 * V_9 , struct V_1 * V_109 ,
int V_113 , unsigned int V_114 , int V_115 )
{
struct V_1 * V_110 = V_9 -> V_11 . V_2 ;
T_1 V_103 = F_93 ( V_114 , V_109 , V_110 ) ;
F_81 ( L_6
L_7 ,
V_110 , V_109 , V_114 , V_115 , V_113 ) ;
ASSERT ( V_110 ) ;
switch ( V_113 ) {
case V_116 :
if ( V_115 == V_117 )
return F_90 ( V_110 , V_103 ) ;
else
return F_92 ( V_110 , V_103 ) ;
case V_118 :
return V_110 == V_109 ;
case V_119 :
return true ;
case V_120 :
return V_110 != V_109 ;
default:
F_81 ( L_8 ,
V_113 ) ;
return false ;
}
}
bool F_95 ( struct V_25 * V_25 , struct V_1 * V_121 ,
struct V_82 * V_83 , int * V_122 , unsigned long * V_84 )
{
struct V_15 * V_16 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_123 ;
int V_28 ;
bool V_124 , V_125 ;
* V_122 = - 1 ;
if ( V_83 -> V_126 == V_118 ) {
* V_122 = F_73 ( V_121 -> V_9 , V_83 , V_84 ) ;
return true ;
}
if ( V_83 -> V_126 )
return false ;
V_125 = V_121 && F_29 ( V_121 ) ;
if ( V_83 -> V_18 == ( V_125 ? V_104 : V_105 ) )
return false ;
V_124 = true ;
F_96 () ;
V_16 = F_97 ( V_25 -> V_11 . V_39 ) ;
if ( ! V_16 ) {
V_124 = false ;
goto V_31;
}
if ( V_83 -> V_115 == V_117 ) {
if ( V_83 -> V_18 >= F_28 ( V_16 -> V_35 ) )
goto V_31;
V_123 = & V_16 -> V_35 [ V_83 -> V_18 ] ;
} else {
T_2 V_19 ;
if ( ! F_20 ( V_16 ) ) {
V_124 = false ;
goto V_31;
}
F_21 ( V_16 , V_83 -> V_18 , & V_19 , ( T_2 * ) & V_7 ) ;
if ( V_19 >= F_28 ( V_16 -> V_38 ) )
goto V_31;
V_123 = V_16 -> V_38 [ V_19 ] ;
if ( F_98 ( V_83 ) ) {
int V_127 = - 1 ;
F_99 (i, &bitmap, 16 ) {
if ( ! V_123 [ V_28 ] )
continue;
if ( V_127 < 0 )
V_127 = V_28 ;
else if ( F_100 ( V_123 [ V_28 ] -> V_9 , V_123 [ V_127 ] -> V_9 ) < 0 )
V_127 = V_28 ;
}
V_7 = ( V_127 >= 0 ) ? 1 << V_127 : 0 ;
}
}
F_99 (i, &bitmap, 16 ) {
if ( ! V_123 [ V_28 ] )
continue;
if ( * V_122 < 0 )
* V_122 = 0 ;
* V_122 += F_73 ( V_123 [ V_28 ] -> V_9 , V_83 , V_84 ) ;
}
V_31:
F_101 () ;
return V_124 ;
}
bool F_102 ( struct V_25 * V_25 , struct V_82 * V_83 ,
struct V_8 * * V_128 )
{
struct V_15 * V_16 ;
bool V_124 = false ;
struct V_1 * V_123 = NULL ;
if ( V_83 -> V_126 )
return false ;
F_96 () ;
V_16 = F_97 ( V_25 -> V_11 . V_39 ) ;
if ( ! V_16 )
goto V_31;
if ( V_83 -> V_115 == V_117 ) {
if ( V_83 -> V_18 == 0xFF )
goto V_31;
if ( V_83 -> V_18 >= F_28 ( V_16 -> V_35 ) )
goto V_31;
V_123 = V_16 -> V_35 [ V_83 -> V_18 ] ;
if ( V_123 && F_27 ( V_123 -> V_9 ) )
* V_128 = V_123 -> V_9 ;
else
goto V_31;
} else {
T_2 V_19 ;
unsigned long V_7 = 1 ;
int V_28 , V_122 = 0 ;
if ( ! F_20 ( V_16 ) )
goto V_31;
F_21 ( V_16 , V_83 -> V_18 , & V_19 , ( T_2 * ) & V_7 ) ;
if ( V_19 >= F_28 ( V_16 -> V_38 ) )
goto V_31;
F_99 (i, &bitmap, 16 ) {
V_123 = V_16 -> V_38 [ V_19 ] [ V_28 ] ;
if ( ++ V_122 == 2 )
goto V_31;
}
if ( V_123 && F_27 ( V_123 -> V_9 ) )
* V_128 = V_123 -> V_9 ;
else
goto V_31;
}
V_124 = true ;
V_31:
F_101 () ;
return V_124 ;
}
static int F_74 ( struct V_1 * V_2 , int V_85 ,
int V_10 , int V_86 , int V_87 ,
unsigned long * V_84 )
{
int V_75 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_103 ( V_9 -> V_108 , V_85 ,
V_87 , V_10 ) ;
switch ( V_85 ) {
case V_129 :
V_9 -> V_11 . V_130 ++ ;
case V_131 :
if ( F_65 ( V_87 && ! V_86 ) )
break;
if ( F_65 ( ! F_15 ( V_2 ) ) )
break;
V_75 = 1 ;
if ( V_84 )
F_83 ( V_9 -> V_108 , V_84 ) ;
if ( F_2 ( V_10 , V_2 -> V_5 + V_132 ) != ! ! V_87 ) {
if ( V_87 )
F_7 ( V_10 , V_2 -> V_5 + V_132 ) ;
else
F_9 ( V_10 , V_2 -> V_5 + V_132 ) ;
}
if ( V_76 -> V_133 )
V_76 -> V_133 ( V_9 , V_10 ) ;
else {
F_61 ( V_10 , V_2 ) ;
F_60 ( V_73 , V_9 ) ;
F_104 ( V_9 ) ;
}
break;
case V_134 :
V_75 = 1 ;
V_9 -> V_11 . V_135 . V_136 = 1 ;
F_60 ( V_73 , V_9 ) ;
F_104 ( V_9 ) ;
break;
case V_137 :
V_75 = 1 ;
F_60 ( V_138 , V_9 ) ;
F_104 ( V_9 ) ;
break;
case V_58 :
V_75 = 1 ;
F_105 ( V_9 ) ;
F_104 ( V_9 ) ;
break;
case V_139 :
if ( ! V_87 || V_86 ) {
V_75 = 1 ;
V_2 -> V_140 = ( 1UL << V_141 ) ;
F_106 () ;
F_60 ( V_73 , V_9 ) ;
F_104 ( V_9 ) ;
} else {
F_81 ( L_9 ,
V_9 -> V_108 ) ;
}
break;
case V_142 :
F_81 ( L_10 ,
V_9 -> V_108 , V_10 ) ;
V_75 = 1 ;
V_2 -> V_143 = V_10 ;
F_106 () ;
F_8 ( V_144 , & V_2 -> V_140 ) ;
F_60 ( V_73 , V_9 ) ;
F_104 ( V_9 ) ;
break;
case V_145 :
break;
default:
F_107 ( V_146 L_11 ,
V_85 ) ;
break;
}
return V_75 ;
}
int F_100 ( struct V_8 * V_147 , struct V_8 * V_148 )
{
return V_147 -> V_11 . V_130 - V_148 -> V_11 . V_130 ;
}
static bool F_108 ( struct V_1 * V_2 , int V_10 )
{
return F_3 ( V_10 , ( V_149 * ) V_2 -> V_9 -> V_11 . V_150 ) ;
}
static void F_109 ( struct V_1 * V_2 , int V_10 )
{
int V_151 ;
if ( ! F_108 ( V_2 , V_10 ) )
return;
if ( F_110 ( V_2 -> V_9 -> V_25 ) ) {
V_2 -> V_9 -> V_11 . V_152 = V_10 ;
F_60 ( V_153 , V_2 -> V_9 ) ;
return;
}
if ( F_2 ( V_10 , V_2 -> V_5 + V_132 ) )
V_151 = V_154 ;
else
V_151 = V_155 ;
F_111 ( V_2 -> V_9 , V_10 , V_151 ) ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_10 = F_69 ( V_2 ) ;
F_113 ( V_2 , V_10 ) ;
if ( V_10 == - 1 )
return V_10 ;
F_71 ( V_10 , V_2 ) ;
F_86 ( V_2 ) ;
F_109 ( V_2 , V_10 ) ;
F_60 ( V_73 , V_2 -> V_9 ) ;
return V_10 ;
}
void F_114 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_113 ( V_2 , V_10 ) ;
F_109 ( V_2 , V_10 ) ;
F_60 ( V_73 , V_2 -> V_9 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
T_1 V_156 = F_19 ( V_2 , V_157 ) ;
T_1 V_158 = F_19 ( V_2 , V_159 ) ;
struct V_82 V_83 ;
V_83 . V_10 = V_156 & V_50 ;
V_83 . V_85 = V_156 & V_57 ;
V_83 . V_115 = V_156 & V_160 ;
V_83 . V_86 = ( V_156 & V_161 ) != 0 ;
V_83 . V_87 = V_156 & V_162 ;
V_83 . V_126 = V_156 & V_163 ;
V_83 . V_164 = false ;
if ( F_29 ( V_2 ) )
V_83 . V_18 = V_158 ;
else
V_83 . V_18 = F_89 ( V_158 ) ;
F_116 ( V_156 , V_83 . V_18 ) ;
F_81 ( L_12
L_13
L_14
L_15 ,
V_158 , V_156 , V_83 . V_126 , V_83 . V_18 ,
V_83 . V_87 , V_83 . V_86 , V_83 . V_115 , V_83 . V_85 ,
V_83 . V_10 , V_83 . V_164 ) ;
F_117 ( V_2 -> V_9 -> V_25 , V_2 , & V_83 , NULL ) ;
}
static T_1 F_118 ( struct V_1 * V_2 )
{
T_4 V_165 ;
T_5 V_166 ;
T_1 V_167 ;
ASSERT ( V_2 != NULL ) ;
if ( F_19 ( V_2 , V_168 ) == 0 ||
V_2 -> V_51 . V_169 == 0 )
return 0 ;
V_165 = F_119 ( & V_2 -> V_51 . V_170 ) ;
if ( F_120 ( V_165 ) < 0 )
V_165 = F_121 ( 0 , 0 ) ;
V_166 = F_122 ( F_120 ( V_165 ) , V_2 -> V_51 . V_169 ) ;
V_167 = F_123 ( V_166 ,
( V_171 * V_2 -> V_172 ) ) ;
return V_167 ;
}
static void F_124 ( struct V_1 * V_2 , bool V_173 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_174 * V_175 = V_9 -> V_175 ;
F_60 ( V_176 , V_9 ) ;
V_175 -> V_177 . V_178 = F_125 ( V_9 ) ;
V_175 -> V_177 . V_179 = V_173 ;
}
static inline void F_126 ( struct V_1 * V_2 , bool V_173 )
{
if ( V_2 -> V_9 -> V_11 . V_180 )
F_124 ( V_2 , V_173 ) ;
}
static T_1 F_127 ( struct V_1 * V_2 , unsigned int V_181 )
{
T_1 V_4 = 0 ;
if ( V_181 >= V_182 )
return 0 ;
switch ( V_181 ) {
case V_14 :
if ( F_29 ( V_2 ) )
V_4 = F_18 ( V_2 ) ;
else
V_4 = F_18 ( V_2 ) << 24 ;
break;
case V_183 :
F_81 ( L_16 ) ;
break;
case V_184 :
if ( F_48 ( V_2 ) )
return 0 ;
V_4 = F_118 ( V_2 ) ;
break;
case V_101 :
F_86 ( V_2 ) ;
V_4 = F_19 ( V_2 , V_181 ) ;
break;
case V_102 :
F_126 ( V_2 , false ) ;
default:
V_4 = F_19 ( V_2 , V_181 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_128 ( struct V_185 * V_186 )
{
return F_129 ( V_186 , struct V_1 , V_186 ) ;
}
static int F_130 ( struct V_1 * V_2 , T_1 V_181 , int V_187 ,
void * V_89 )
{
unsigned char V_188 = V_181 & 0xf ;
T_1 V_75 ;
static const T_6 V_189 = 0x43ff01ffffffe70cULL ;
if ( ( V_188 + V_187 ) > 4 ) {
F_81 ( L_17 ,
V_181 , V_187 ) ;
return 1 ;
}
if ( V_181 > 0x3f0 || ! ( V_189 & ( 1ULL << ( V_181 >> 4 ) ) ) ) {
F_81 ( L_18 ,
V_181 ) ;
return 1 ;
}
V_75 = F_127 ( V_2 , V_181 & ~ 0xf ) ;
F_131 ( V_181 , V_75 ) ;
switch ( V_187 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_89 , ( char * ) & V_75 + V_188 , V_187 ) ;
break;
default:
F_107 ( V_146 L_19
L_20 , V_187 ) ;
break;
}
return 0 ;
}
static int F_132 ( struct V_1 * V_2 , T_7 V_190 )
{
return F_17 ( V_2 ) &&
V_190 >= V_2 -> V_191 &&
V_190 < V_2 -> V_191 + V_182 ;
}
static int F_133 ( struct V_8 * V_9 , struct V_185 * V_192 ,
T_7 V_193 , int V_187 , void * V_89 )
{
struct V_1 * V_2 = F_128 ( V_192 ) ;
T_1 V_181 = V_193 - V_2 -> V_191 ;
if ( ! F_132 ( V_2 , V_193 ) )
return - V_194 ;
F_130 ( V_2 , V_181 , V_187 , V_89 ) ;
return 0 ;
}
static void F_134 ( struct V_1 * V_2 )
{
T_1 V_195 , V_196 , V_197 ;
V_197 = F_19 ( V_2 , V_198 ) ;
V_195 = V_197 & 0xf ;
V_196 = ( ( V_195 & 0x3 ) | ( ( V_195 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_172 = 0x1 << ( V_196 & 0x7 ) ;
F_81 ( L_21 ,
V_2 -> V_172 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
T_1 V_52 = F_19 ( V_2 , V_199 ) &
V_2 -> V_51 . V_200 ;
if ( V_2 -> V_51 . V_52 != V_52 ) {
V_2 -> V_51 . V_52 = V_52 ;
F_136 ( & V_2 -> V_51 . V_170 ) ;
}
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_8 * V_201 = & V_9 -> V_202 ;
struct V_203 * V_204 = & V_2 -> V_51 ;
if ( F_138 ( & V_2 -> V_51 . V_205 ) )
return;
F_139 ( & V_2 -> V_51 . V_205 ) ;
F_140 ( V_9 ) ;
if ( F_141 ( V_201 ) )
F_142 ( V_201 ) ;
if ( F_48 ( V_2 ) )
V_204 -> V_206 = V_204 -> V_207 ;
}
static bool F_143 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = F_19 ( V_2 , V_199 ) ;
if ( F_17 ( V_2 ) ) {
int V_6 = V_67 & V_50 ;
void * V_7 = V_2 -> V_5 + V_12 ;
if ( V_76 -> V_133 )
V_7 = V_2 -> V_5 + V_13 ;
if ( F_2 ( V_6 , V_7 ) )
return true ;
}
return false ;
}
void F_144 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_6 V_208 , V_209 ;
if ( ! F_51 ( V_9 ) )
return;
if ( V_2 -> V_51 . V_206 == 0 )
return;
if ( ! F_143 ( V_9 ) )
return;
V_209 = V_2 -> V_51 . V_206 ;
V_2 -> V_51 . V_206 = 0 ;
V_208 = F_145 ( V_9 , F_146 () ) ;
F_147 ( V_9 -> V_108 , V_208 - V_209 ) ;
if ( V_208 < V_209 )
F_148 ( V_209 - V_208 ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
T_4 V_210 ;
F_150 ( & V_2 -> V_51 . V_205 , 0 ) ;
if ( F_47 ( V_2 ) || F_46 ( V_2 ) ) {
V_210 = V_2 -> V_51 . V_170 . V_211 -> V_212 () ;
V_2 -> V_51 . V_169 = ( T_6 ) F_19 ( V_2 , V_168 )
* V_171 * V_2 -> V_172 ;
if ( ! V_2 -> V_51 . V_169 )
return;
if ( F_47 ( V_2 ) ) {
T_5 V_213 = V_214 * 1000LL ;
if ( V_2 -> V_51 . V_169 < V_213 ) {
F_151 (
L_22
L_23 ,
V_2 -> V_9 -> V_108 ,
V_2 -> V_51 . V_169 , V_213 ) ;
V_2 -> V_51 . V_169 = V_213 ;
}
}
F_152 ( & V_2 -> V_51 . V_170 ,
F_153 ( V_210 , V_2 -> V_51 . V_169 ) ,
V_215 ) ;
F_81 ( L_24 V_216 L_25
V_217 L_26
L_27
L_28 V_217 L_29 , V_218 ,
V_171 , F_120 ( V_210 ) ,
F_19 ( V_2 , V_168 ) ,
V_2 -> V_51 . V_169 ,
F_120 ( F_153 ( V_210 ,
V_2 -> V_51 . V_169 ) ) ) ;
} else if ( F_48 ( V_2 ) ) {
T_6 V_208 , V_207 = V_2 -> V_51 . V_207 ;
T_6 V_166 = 0 ;
T_4 V_219 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_220 = V_9 -> V_11 . V_221 ;
unsigned long V_222 ;
if ( F_65 ( ! V_207 || ! V_220 ) )
return;
F_154 ( V_222 ) ;
V_210 = V_2 -> V_51 . V_170 . V_211 -> V_212 () ;
V_208 = F_145 ( V_9 , F_146 () ) ;
if ( F_70 ( V_207 > V_208 ) ) {
V_166 = ( V_207 - V_208 ) * 1000000ULL ;
F_155 ( V_166 , V_220 ) ;
V_219 = F_153 ( V_210 , V_166 ) ;
V_219 = F_156 ( V_219 , V_223 ) ;
F_152 ( & V_2 -> V_51 . V_170 ,
V_219 , V_215 ) ;
} else
F_137 ( V_2 ) ;
F_157 ( V_222 ) ;
}
}
static void F_158 ( struct V_1 * V_2 , T_1 V_224 )
{
bool V_225 = F_49 ( V_224 ) ;
if ( V_2 -> V_225 != V_225 ) {
V_2 -> V_225 = V_225 ;
if ( V_225 ) {
F_81 ( L_30
L_31 , V_2 -> V_9 -> V_108 ) ;
F_139 ( & V_2 -> V_9 -> V_25 -> V_11 . V_226 ) ;
} else
F_159 ( & V_2 -> V_9 -> V_25 -> V_11 . V_226 ) ;
}
}
static int F_160 ( struct V_1 * V_2 , T_1 V_67 , T_1 V_4 )
{
int V_124 = 0 ;
F_161 ( V_67 , V_4 ) ;
switch ( V_67 ) {
case V_14 :
if ( ! F_29 ( V_2 ) )
F_41 ( V_2 , V_4 >> 24 ) ;
else
V_124 = 1 ;
break;
case V_102 :
F_126 ( V_2 , true ) ;
F_87 ( V_2 , V_4 & 0xff ) ;
break;
case V_227 :
F_112 ( V_2 ) ;
break;
case V_34 :
if ( ! F_29 ( V_2 ) )
F_42 ( V_2 , V_4 & V_228 ) ;
else
V_124 = 1 ;
break;
case V_36 :
if ( ! F_29 ( V_2 ) ) {
F_1 ( V_2 , V_36 , V_4 | 0x0FFFFFFF ) ;
F_23 ( V_2 -> V_9 -> V_25 ) ;
} else
V_124 = 1 ;
break;
case V_43 : {
T_1 V_229 = 0x3ff ;
if ( F_19 ( V_2 , V_66 ) & V_65 )
V_229 |= V_230 ;
F_38 ( V_2 , V_4 & V_229 ) ;
if ( ! ( V_4 & V_42 ) ) {
int V_28 ;
T_1 V_56 ;
for ( V_28 = 0 ; V_28 < V_231 ; V_28 ++ ) {
V_56 = F_19 ( V_2 ,
V_199 + 0x10 * V_28 ) ;
F_1 ( V_2 , V_199 + 0x10 * V_28 ,
V_56 | V_49 ) ;
}
F_135 ( V_2 ) ;
F_150 ( & V_2 -> V_51 . V_205 , 0 ) ;
}
break;
}
case V_157 :
F_1 ( V_2 , V_157 , V_4 & ~ ( 1 << 12 ) ) ;
F_115 ( V_2 ) ;
break;
case V_159 :
if ( ! F_29 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_159 , V_4 ) ;
break;
case V_232 :
F_158 ( V_2 , V_4 ) ;
case V_233 :
case V_234 :
case V_235 :
case V_236 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= V_237 [ ( V_67 - V_199 ) >> 4 ] ;
F_1 ( V_2 , V_67 , V_4 ) ;
break;
case V_199 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= ( V_237 [ 0 ] | V_2 -> V_51 . V_200 ) ;
F_1 ( V_2 , V_199 , V_4 ) ;
F_135 ( V_2 ) ;
break;
case V_168 :
if ( F_48 ( V_2 ) )
break;
F_136 ( & V_2 -> V_51 . V_170 ) ;
F_1 ( V_2 , V_168 , V_4 ) ;
F_149 ( V_2 ) ;
break;
case V_198 :
if ( V_4 & 4 )
F_81 ( L_32 , V_4 ) ;
F_1 ( V_2 , V_198 , V_4 ) ;
F_134 ( V_2 ) ;
break;
case V_238 :
if ( F_29 ( V_2 ) && V_4 != 0 ) {
F_81 ( L_33 , V_4 ) ;
V_124 = 1 ;
}
break;
case V_239 :
if ( F_29 ( V_2 ) ) {
F_160 ( V_2 , V_157 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_124 = 1 ;
break;
default:
V_124 = 1 ;
break;
}
if ( V_124 )
F_81 ( L_34 , V_67 ) ;
return V_124 ;
}
static int F_162 ( struct V_8 * V_9 , struct V_185 * V_192 ,
T_7 V_193 , int V_187 , const void * V_89 )
{
struct V_1 * V_2 = F_128 ( V_192 ) ;
unsigned int V_181 = V_193 - V_2 -> V_191 ;
T_1 V_4 ;
if ( ! F_132 ( V_2 , V_193 ) )
return - V_194 ;
if ( V_187 != 4 || ( V_181 & 0xf ) ) {
F_81 ( L_35 , V_187 , ( long ) V_193 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_89 ;
if ( V_181 != V_227 )
F_81 ( L_36
L_37 , V_218 , V_181 , V_187 , V_4 ) ;
F_160 ( V_2 , V_181 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_163 ( struct V_8 * V_9 )
{
if ( F_51 ( V_9 ) )
F_160 ( V_9 -> V_11 . V_2 , V_227 , 0 ) ;
}
void F_164 ( struct V_8 * V_9 , T_1 V_181 )
{
T_1 V_4 = 0 ;
V_181 &= 0xff0 ;
F_130 ( V_9 -> V_11 . V_2 , V_181 , 4 , & V_4 ) ;
F_160 ( V_9 -> V_11 . V_2 , V_181 , V_4 ) ;
}
void F_165 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_9 -> V_11 . V_2 )
return;
F_136 ( & V_2 -> V_51 . V_170 ) ;
if ( ! ( V_9 -> V_11 . V_240 & V_241 ) )
F_39 ( & V_242 ) ;
if ( ! V_2 -> V_44 )
F_39 ( & V_45 ) ;
if ( V_2 -> V_5 )
F_166 ( ( unsigned long ) V_2 -> V_5 ) ;
F_167 ( V_2 ) ;
}
T_6 F_168 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return 0 ;
return V_2 -> V_51 . V_207 ;
}
void F_169 ( struct V_8 * V_9 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return;
F_136 ( & V_2 -> V_51 . V_170 ) ;
V_2 -> V_51 . V_207 = V_89 ;
F_149 ( V_2 ) ;
}
void F_170 ( struct V_8 * V_9 , unsigned long V_243 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return;
F_87 ( V_2 , ( ( V_243 & 0x0f ) << 4 )
| ( F_19 ( V_2 , V_102 ) & 4 ) ) ;
}
T_6 F_171 ( struct V_8 * V_9 )
{
T_6 V_96 ;
if ( ! F_51 ( V_9 ) )
return 0 ;
V_96 = ( T_6 ) F_19 ( V_9 -> V_11 . V_2 , V_102 ) ;
return ( V_96 & 0xf0 ) >> 4 ;
}
void F_172 ( struct V_8 * V_9 , T_6 V_244 )
{
T_6 V_245 = V_9 -> V_11 . V_240 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_2 ) {
V_244 |= V_246 ;
V_9 -> V_11 . V_240 = V_244 ;
return;
}
V_9 -> V_11 . V_240 = V_244 ;
if ( ( V_245 ^ V_244 ) & V_241 ) {
if ( V_244 & V_241 )
F_39 ( & V_242 ) ;
else
F_40 ( & V_242 . V_46 ) ;
F_23 ( V_9 -> V_25 ) ;
}
if ( ( V_245 ^ V_244 ) & V_247 ) {
if ( V_244 & V_247 ) {
F_43 ( V_2 , V_9 -> V_108 ) ;
V_76 -> V_248 ( V_9 , true ) ;
} else
V_76 -> V_248 ( V_9 , false ) ;
}
V_2 -> V_191 = V_2 -> V_9 -> V_11 . V_240 &
V_249 ;
if ( ( V_244 & V_241 ) &&
V_2 -> V_191 != V_250 )
F_173 ( L_38 ) ;
F_81 ( L_39 V_217 L_40
L_41 , V_2 -> V_9 -> V_11 . V_240 , V_2 -> V_191 ) ;
}
void F_174 ( struct V_8 * V_9 , bool V_251 )
{
struct V_1 * V_2 ;
int V_28 ;
F_81 ( L_42 , V_218 ) ;
ASSERT ( V_9 ) ;
V_2 = V_9 -> V_11 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_136 ( & V_2 -> V_51 . V_170 ) ;
if ( ! V_251 )
F_41 ( V_2 , V_9 -> V_108 ) ;
F_50 ( V_2 -> V_9 ) ;
for ( V_28 = 0 ; V_28 < V_231 ; V_28 ++ )
F_1 ( V_2 , V_199 + 0x10 * V_28 , V_49 ) ;
F_135 ( V_2 ) ;
if ( F_175 ( V_9 -> V_25 , V_252 ) )
F_1 ( V_2 , V_232 ,
F_176 ( 0 , V_253 ) ) ;
F_158 ( V_2 , F_19 ( V_2 , V_232 ) ) ;
F_1 ( V_2 , V_36 , 0xffffffffU ) ;
F_38 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_102 , 0 ) ;
if ( ! F_29 ( V_2 ) )
F_42 ( V_2 , 0 ) ;
F_1 ( V_2 , V_238 , 0 ) ;
F_1 ( V_2 , V_157 , 0 ) ;
F_1 ( V_2 , V_159 , 0 ) ;
F_1 ( V_2 , V_198 , 0 ) ;
F_1 ( V_2 , V_168 , 0 ) ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
F_1 ( V_2 , V_13 + 0x10 * V_28 , 0 ) ;
F_1 ( V_2 , V_12 + 0x10 * V_28 , 0 ) ;
F_1 ( V_2 , V_132 + 0x10 * V_28 , 0 ) ;
}
V_2 -> V_74 = F_66 ( V_9 ) ;
V_2 -> V_79 = V_76 -> V_78 ? 1 : 0 ;
V_2 -> V_80 = - 1 ;
F_134 ( V_2 ) ;
F_150 ( & V_2 -> V_51 . V_205 , 0 ) ;
if ( F_177 ( V_9 ) )
F_172 ( V_9 ,
V_9 -> V_11 . V_240 | V_246 ) ;
V_9 -> V_11 . V_88 . V_90 = 0 ;
F_86 ( V_2 ) ;
V_9 -> V_11 . V_130 = 0 ;
V_9 -> V_11 . V_94 = 0 ;
F_81 ( L_43
L_44 V_217 L_45 , V_218 ,
V_9 , F_18 ( V_2 ) ,
V_9 -> V_11 . V_240 , V_2 -> V_191 ) ;
}
static bool F_178 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ) ;
}
int F_179 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_51 ( V_9 ) && F_15 ( V_2 ) &&
F_44 ( V_2 , V_199 ) )
return F_138 ( & V_2 -> V_51 . V_205 ) ;
return 0 ;
}
int F_180 ( struct V_1 * V_2 , int V_48 )
{
T_1 V_67 = F_19 ( V_2 , V_48 ) ;
int V_10 , V_17 , V_87 ;
if ( F_17 ( V_2 ) && ! ( V_67 & V_49 ) ) {
V_10 = V_67 & V_50 ;
V_17 = V_67 & V_57 ;
V_87 = V_67 & V_254 ;
return F_74 ( V_2 , V_17 , V_10 , 1 , V_87 ,
NULL ) ;
}
return 0 ;
}
void F_181 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_2 )
F_180 ( V_2 , V_232 ) ;
}
static enum V_255 F_182 ( struct V_256 * V_89 )
{
struct V_203 * V_204 = F_129 ( V_89 , struct V_203 , V_170 ) ;
struct V_1 * V_2 = F_129 ( V_204 , struct V_1 , V_51 ) ;
F_137 ( V_2 ) ;
if ( F_178 ( V_2 ) ) {
F_183 ( & V_204 -> V_170 , V_204 -> V_169 ) ;
return V_257 ;
} else
return V_258 ;
}
int F_184 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
ASSERT ( V_9 != NULL ) ;
F_81 ( L_46 , V_9 -> V_108 ) ;
V_2 = F_24 ( sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
goto V_259;
V_9 -> V_11 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_185 ( V_29 ) ;
if ( ! V_2 -> V_5 ) {
F_107 ( V_146 L_47 ,
V_9 -> V_108 ) ;
goto V_260;
}
V_2 -> V_9 = V_9 ;
F_186 ( & V_2 -> V_51 . V_170 , V_261 ,
V_215 ) ;
V_2 -> V_51 . V_170 . V_262 = F_182 ;
V_9 -> V_11 . V_240 = V_241 ;
F_172 ( V_9 ,
V_250 | V_241 ) ;
F_40 ( & V_45 . V_46 ) ;
F_174 ( V_9 , false ) ;
F_187 ( & V_2 -> V_186 , & V_263 ) ;
return 0 ;
V_260:
F_167 ( V_2 ) ;
V_259:
return - V_264 ;
}
int F_188 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_81 ;
if ( ! F_51 ( V_9 ) || ! F_15 ( V_2 ) )
return - 1 ;
F_86 ( V_2 ) ;
V_81 = F_63 ( V_2 ) ;
if ( ( V_81 == - 1 ) ||
( ( V_81 & 0xF0 ) <= F_19 ( V_2 , V_101 ) ) )
return - 1 ;
return V_81 ;
}
int F_189 ( struct V_8 * V_9 )
{
T_1 V_265 = F_19 ( V_9 -> V_11 . V_2 , V_232 ) ;
int V_122 = 0 ;
if ( ! F_17 ( V_9 -> V_11 . V_2 ) )
V_122 = 1 ;
if ( ( V_265 & V_49 ) == 0 &&
F_190 ( V_265 ) == V_253 )
V_122 = 1 ;
return V_122 ;
}
void F_191 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return;
if ( F_138 ( & V_2 -> V_51 . V_205 ) > 0 ) {
F_180 ( V_2 , V_199 ) ;
if ( F_48 ( V_2 ) )
V_2 -> V_51 . V_207 = 0 ;
F_150 ( & V_2 -> V_51 . V_205 , 0 ) ;
}
}
int F_192 ( struct V_8 * V_9 )
{
int V_10 = F_188 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_10 == - 1 )
return - 1 ;
F_67 ( V_10 , V_2 ) ;
F_86 ( V_2 ) ;
F_64 ( V_10 , V_2 ) ;
return V_10 ;
}
void F_193 ( struct V_8 * V_9 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_172 ( V_9 , V_9 -> V_11 . V_240 ) ;
F_38 ( V_2 , * ( ( T_1 * ) ( V_267 -> V_5 + V_43 ) ) ) ;
memcpy ( V_9 -> V_11 . V_2 -> V_5 , V_267 -> V_5 , sizeof *V_267 ) ;
F_41 ( V_2 , F_18 ( V_2 ) ) ;
F_50 ( V_9 ) ;
F_86 ( V_2 ) ;
F_136 ( & V_2 -> V_51 . V_170 ) ;
F_135 ( V_2 ) ;
F_158 ( V_2 , F_19 ( V_2 , V_232 ) ) ;
F_134 ( V_2 ) ;
F_149 ( V_2 ) ;
V_2 -> V_74 = true ;
V_2 -> V_79 = V_76 -> V_78 ?
1 : F_55 ( V_2 -> V_5 + V_12 ) ;
V_2 -> V_80 = - 1 ;
if ( V_76 -> V_268 )
V_76 -> V_268 ( V_9 ,
F_63 ( V_2 ) ) ;
if ( F_65 ( V_76 -> V_78 ) )
V_76 -> V_78 ( V_9 -> V_25 ,
F_69 ( V_2 ) ) ;
F_60 ( V_73 , V_9 ) ;
if ( F_194 ( V_9 -> V_25 ) )
F_195 ( V_9 ) ;
V_9 -> V_11 . V_130 = 0 ;
}
void F_196 ( struct V_8 * V_9 )
{
struct V_256 * V_170 ;
if ( ! F_51 ( V_9 ) )
return;
V_170 = & V_9 -> V_11 . V_2 -> V_51 . V_170 ;
if ( F_136 ( V_170 ) )
F_197 ( V_170 , V_215 ) ;
}
static void F_198 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
bool V_205 ;
int V_10 ;
F_68 ( ! F_79 ( V_9 ) ) ;
V_205 = F_80 ( V_9 ) ;
F_84 ( V_9 ) ;
if ( V_205 )
return;
V_10 = F_112 ( V_2 ) ;
F_199 ( V_2 , V_10 ) ;
}
void F_200 ( struct V_8 * V_9 )
{
T_1 V_89 ;
if ( F_3 ( V_93 , & V_9 -> V_11 . V_94 ) )
F_198 ( V_9 , V_9 -> V_11 . V_2 ) ;
if ( ! F_3 ( V_269 , & V_9 -> V_11 . V_94 ) )
return;
if ( F_78 ( V_9 -> V_25 , & V_9 -> V_11 . V_2 -> V_270 , & V_89 ,
sizeof( T_1 ) ) )
return;
F_87 ( V_9 -> V_11 . V_2 , V_89 & 0xff ) ;
}
static void F_201 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( ! F_79 ( V_9 ) ||
V_2 -> V_74 ||
V_2 -> V_80 == - 1 ||
F_108 ( V_2 , V_2 -> V_80 ) ) {
return;
}
F_82 ( V_2 -> V_9 ) ;
}
void F_202 ( struct V_8 * V_9 )
{
T_1 V_89 , V_96 ;
int V_271 , V_272 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_201 ( V_9 , V_2 ) ;
if ( ! F_3 ( V_269 , & V_9 -> V_11 . V_94 ) )
return;
V_96 = F_19 ( V_2 , V_102 ) & 0xff ;
V_271 = F_63 ( V_2 ) ;
if ( V_271 < 0 )
V_271 = 0 ;
V_272 = F_69 ( V_2 ) ;
if ( V_272 < 0 )
V_272 = 0 ;
V_89 = ( V_96 & 0xff ) | ( ( V_272 & 0xf0 ) << 8 ) | ( V_271 << 24 ) ;
F_76 ( V_9 -> V_25 , & V_9 -> V_11 . V_2 -> V_270 , & V_89 ,
sizeof( T_1 ) ) ;
}
int F_203 ( struct V_8 * V_9 , T_7 V_273 )
{
if ( V_273 ) {
if ( F_204 ( V_9 -> V_25 ,
& V_9 -> V_11 . V_2 -> V_270 ,
V_273 , sizeof( T_1 ) ) )
return - V_274 ;
F_83 ( V_269 , & V_9 -> V_11 . V_94 ) ;
} else {
F_85 ( V_269 , & V_9 -> V_11 . V_94 ) ;
}
V_9 -> V_11 . V_2 -> V_273 = V_273 ;
return 0 ;
}
int F_205 ( struct V_8 * V_9 , T_1 V_275 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_275 - V_276 ) << 4 ;
if ( ! F_206 ( V_9 ) || ! F_29 ( V_2 ) )
return 1 ;
if ( V_67 == V_159 )
return 1 ;
if ( V_67 == V_157 )
F_160 ( V_2 , V_159 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_160 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_207 ( struct V_8 * V_9 , T_1 V_275 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_275 - V_276 ) << 4 , V_277 , V_278 = 0 ;
if ( ! F_206 ( V_9 ) || ! F_29 ( V_2 ) )
return 1 ;
if ( V_67 == V_36 || V_67 == V_159 ) {
F_81 ( L_48 ,
V_67 ) ;
return 1 ;
}
if ( F_130 ( V_2 , V_67 , 4 , & V_277 ) )
return 1 ;
if ( V_67 == V_157 )
F_130 ( V_2 , V_159 , 4 , & V_278 ) ;
* V_89 = ( ( ( T_6 ) V_278 ) << 32 ) | V_277 ;
return 0 ;
}
int F_208 ( struct V_8 * V_9 , T_1 V_67 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return 1 ;
if ( V_67 == V_157 )
F_160 ( V_2 , V_159 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_160 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_209 ( struct V_8 * V_9 , T_1 V_67 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_277 , V_278 = 0 ;
if ( ! F_51 ( V_9 ) )
return 1 ;
if ( F_130 ( V_2 , V_67 , 4 , & V_277 ) )
return 1 ;
if ( V_67 == V_157 )
F_130 ( V_2 , V_159 , 4 , & V_278 ) ;
* V_89 = ( ( ( T_6 ) V_278 ) << 32 ) | V_277 ;
return 0 ;
}
int F_210 ( struct V_8 * V_9 , T_6 V_89 )
{
T_6 V_190 = V_89 & ~ V_91 ;
if ( ! F_211 ( V_190 , 4 ) )
return 1 ;
V_9 -> V_11 . V_88 . V_90 = V_89 ;
if ( ! F_79 ( V_9 ) )
return 0 ;
return F_204 ( V_9 -> V_25 , & V_9 -> V_11 . V_88 . V_89 ,
V_190 , sizeof( T_3 ) ) ;
}
void F_212 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_3 V_143 ;
unsigned long V_279 ;
if ( ! F_51 ( V_9 ) || ! V_2 -> V_140 )
return;
if ( F_213 ( V_9 ) ) {
F_214 ( V_9 -> V_11 . V_280 == V_281 ) ;
if ( F_3 ( V_144 , & V_2 -> V_140 ) )
F_10 ( V_144 , & V_2 -> V_140 ) ;
return;
}
V_279 = F_58 ( & V_2 -> V_140 , 0 ) ;
if ( F_3 ( V_141 , & V_279 ) ) {
F_174 ( V_9 , true ) ;
F_215 ( V_9 , true ) ;
if ( F_177 ( V_2 -> V_9 ) )
V_9 -> V_11 . V_280 = V_282 ;
else
V_9 -> V_11 . V_280 = V_281 ;
}
if ( F_3 ( V_144 , & V_279 ) &&
V_9 -> V_11 . V_280 == V_281 ) {
F_216 () ;
V_143 = V_2 -> V_143 ;
F_81 ( L_49 ,
V_9 -> V_108 , V_143 ) ;
F_217 ( V_9 , V_143 ) ;
V_9 -> V_11 . V_280 = V_282 ;
}
}
void F_218 ( void )
{
F_219 ( & V_242 , V_283 ) ;
F_219 ( & V_45 , V_283 ) ;
}
