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
static inline bool F_15 ( struct V_12 * V_13 )
{
return ! ( V_13 -> V_14 & ( V_13 -> V_14 - 1 ) ) ;
}
static inline void
F_16 ( struct V_12 * V_13 , T_1 V_15 , T_2 * V_16 , T_2 * V_17 )
{
unsigned V_18 ;
F_17 ( V_19 != 4 ) ;
F_17 ( V_20 != 8 ) ;
F_17 ( V_21 != 16 ) ;
V_18 = V_13 -> V_14 ;
* V_16 = V_15 >> V_18 ;
* V_17 = V_15 & ( ( 1 << V_18 ) - 1 ) ;
}
static void F_18 ( struct V_22 * V_22 )
{
struct V_12 * V_23 , * V_24 = NULL ;
struct V_3 * V_4 ;
int V_25 ;
V_23 = F_19 ( sizeof( struct V_12 ) , V_26 ) ;
F_20 ( & V_22 -> V_8 . V_27 ) ;
if ( ! V_23 )
goto V_28;
F_21 (i, vcpu, kvm) {
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_16 , V_17 ;
T_1 V_29 , V_30 ;
if ( ! F_22 ( V_4 ) )
continue;
V_30 = F_23 ( V_7 ) ;
V_29 = F_24 ( V_7 , V_31 ) ;
if ( V_30 < F_25 ( V_23 -> V_32 ) )
V_23 -> V_32 [ V_30 ] = V_7 ;
if ( F_26 ( V_7 ) ) {
V_23 -> V_14 |= V_21 ;
} else if ( V_29 ) {
V_29 = F_27 ( V_29 ) ;
if ( F_24 ( V_7 , V_33 ) == V_34 )
V_23 -> V_14 |= V_20 ;
else
V_23 -> V_14 |= V_19 ;
}
if ( ! F_15 ( V_23 ) )
continue;
F_16 ( V_23 , V_29 , & V_16 , & V_17 ) ;
if ( V_17 && V_16 < F_25 ( V_23 -> V_35 ) )
V_23 -> V_35 [ V_16 ] [ F_28 ( V_17 ) - 1 ] = V_7 ;
}
V_28:
V_24 = F_29 ( V_22 -> V_8 . V_36 ,
F_30 ( & V_22 -> V_8 . V_27 ) ) ;
F_31 ( V_22 -> V_8 . V_36 , V_23 ) ;
F_32 ( & V_22 -> V_8 . V_27 ) ;
if ( V_24 )
F_33 ( V_24 , V_37 ) ;
F_34 ( V_22 ) ;
}
static inline void F_35 ( struct V_6 * V_7 , T_1 V_38 )
{
bool V_39 = V_38 & V_40 ;
F_36 ( V_7 , V_41 , V_38 ) ;
if ( V_39 != V_7 -> V_42 ) {
V_7 -> V_42 = V_39 ;
if ( V_39 ) {
F_37 ( & V_43 ) ;
F_18 ( V_7 -> V_4 -> V_22 ) ;
} else
F_38 ( & V_43 . V_44 ) ;
}
}
static inline void F_39 ( struct V_6 * V_7 , T_3 V_45 )
{
F_36 ( V_7 , V_46 , V_45 << 24 ) ;
F_18 ( V_7 -> V_4 -> V_22 ) ;
}
static inline void F_40 ( struct V_6 * V_7 , T_1 V_45 )
{
F_36 ( V_7 , V_31 , V_45 ) ;
F_18 ( V_7 -> V_4 -> V_22 ) ;
}
static inline void F_41 ( struct V_6 * V_7 , T_3 V_45 )
{
T_1 V_29 = ( ( V_45 >> 4 ) << 16 ) | ( 1 << ( V_45 & 0xf ) ) ;
F_36 ( V_7 , V_46 , V_45 << 24 ) ;
F_36 ( V_7 , V_31 , V_29 ) ;
F_18 ( V_7 -> V_4 -> V_22 ) ;
}
static inline int F_42 ( struct V_6 * V_7 , int V_47 )
{
return ! ( F_24 ( V_7 , V_47 ) & V_48 ) ;
}
static inline int F_43 ( struct V_6 * V_7 , int V_47 )
{
return F_24 ( V_7 , V_47 ) & V_49 ;
}
static inline int F_44 ( struct V_6 * V_7 )
{
return V_7 -> V_50 . V_51 == V_52 ;
}
static inline int F_45 ( struct V_6 * V_7 )
{
return V_7 -> V_50 . V_51 == V_53 ;
}
static inline int F_46 ( struct V_6 * V_7 )
{
return V_7 -> V_50 . V_51 == V_54 ;
}
static inline int F_47 ( T_1 V_55 )
{
return ( V_55 & ( V_56 | V_48 ) ) == V_57 ;
}
void F_48 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
struct V_58 * V_59 ;
T_1 V_60 = V_61 ;
if ( ! F_49 ( V_4 ) )
return;
V_59 = F_50 ( V_7 -> V_4 , 0x1 , 0 ) ;
if ( V_59 && ( V_59 -> V_62 & ( 1 << ( V_63 & 31 ) ) ) )
V_60 |= V_64 ;
F_36 ( V_7 , V_65 , V_60 ) ;
}
static int F_51 ( void * V_2 )
{
int V_1 ;
T_1 * V_66 ;
for ( V_1 = V_67 - V_68 ;
V_1 >= 0 ; V_1 -= V_68 ) {
V_66 = V_2 + F_4 ( V_1 ) ;
if ( * V_66 )
return F_52 ( * V_66 ) - 1 + V_1 ;
}
return - 1 ;
}
static T_3 F_53 ( void * V_2 )
{
int V_1 ;
T_1 * V_66 ;
T_3 V_69 = 0 ;
for ( V_1 = 0 ; V_1 < V_67 ; V_1 += V_68 ) {
V_66 = V_2 + F_4 ( V_1 ) ;
V_69 += F_54 ( * V_66 ) ;
}
return V_69 ;
}
void F_55 ( T_1 * V_70 , void * V_9 )
{
T_1 V_25 , V_71 ;
for ( V_25 = 0 ; V_25 <= 7 ; V_25 ++ ) {
V_71 = F_56 ( & V_70 [ V_25 ] , 0 ) ;
if ( V_71 )
* ( ( T_1 * ) ( V_9 + V_11 + V_25 * 0x10 ) ) |= V_71 ;
}
}
void F_57 ( struct V_3 * V_4 , T_1 * V_70 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_55 ( V_70 , V_7 -> V_9 ) ;
F_58 ( V_72 , V_4 ) ;
}
static inline int F_59 ( struct V_6 * V_7 )
{
return F_51 ( V_7 -> V_9 + V_11 ) ;
}
static inline int F_60 ( struct V_6 * V_7 )
{
int V_73 ;
if ( ! V_7 -> V_74 )
return - 1 ;
if ( V_7 -> V_4 -> V_8 . V_75 )
V_76 -> V_77 ( V_7 -> V_4 ) ;
V_73 = F_59 ( V_7 ) ;
ASSERT ( V_73 == - 1 || V_73 >= 16 ) ;
return V_73 ;
}
static inline void F_61 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
V_4 = V_7 -> V_4 ;
if ( F_62 ( V_4 -> V_8 . V_75 ) ) {
F_6 ( V_1 , V_7 -> V_9 + V_11 ) ;
F_58 ( V_72 , V_4 ) ;
} else {
V_7 -> V_74 = false ;
F_6 ( V_1 , V_7 -> V_9 + V_11 ) ;
if ( F_59 ( V_7 ) != - 1 )
V_7 -> V_74 = true ;
}
}
static inline void F_63 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
if ( F_8 ( V_1 , V_7 -> V_9 + V_10 ) )
return;
V_4 = V_7 -> V_4 ;
if ( F_62 ( V_4 -> V_8 . V_75 ) )
V_76 -> V_78 ( V_4 , V_1 ) ;
else {
++ V_7 -> V_79 ;
F_64 ( V_7 -> V_79 > V_67 ) ;
V_7 -> V_80 = V_1 ;
}
}
static inline int F_65 ( struct V_6 * V_7 )
{
int V_73 ;
if ( ! V_7 -> V_79 )
return - 1 ;
if ( F_66 ( V_7 -> V_80 != - 1 ) )
return V_7 -> V_80 ;
V_73 = F_51 ( V_7 -> V_9 + V_10 ) ;
ASSERT ( V_73 == - 1 || V_73 >= 16 ) ;
return V_73 ;
}
static inline void F_67 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
if ( ! F_10 ( V_1 , V_7 -> V_9 + V_10 ) )
return;
V_4 = V_7 -> V_4 ;
if ( F_62 ( V_4 -> V_8 . V_75 ) )
V_76 -> V_78 ( V_4 ,
F_65 ( V_7 ) ) ;
else {
-- V_7 -> V_79 ;
F_64 ( V_7 -> V_79 < 0 ) ;
V_7 -> V_80 = - 1 ;
}
}
int F_68 ( struct V_3 * V_4 )
{
return F_60 ( V_4 -> V_8 . V_7 ) ;
}
int F_69 ( struct V_3 * V_4 , struct V_81 * V_82 ,
struct V_83 * V_83 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
return F_70 ( V_7 , V_82 -> V_84 , V_82 -> V_5 ,
V_82 -> V_85 , V_82 -> V_86 , V_83 ) ;
}
static int F_71 ( struct V_3 * V_4 , T_3 V_38 )
{
return F_72 ( V_4 -> V_22 , & V_4 -> V_8 . V_87 . V_88 , & V_38 ,
sizeof( V_38 ) ) ;
}
static int F_73 ( struct V_3 * V_4 , T_3 * V_38 )
{
return F_74 ( V_4 -> V_22 , & V_4 -> V_8 . V_87 . V_88 , V_38 ,
sizeof( * V_38 ) ) ;
}
static inline bool F_75 ( struct V_3 * V_4 )
{
return V_4 -> V_8 . V_87 . V_89 & V_90 ;
}
static bool F_76 ( struct V_3 * V_4 )
{
T_3 V_38 ;
if ( F_73 ( V_4 , & V_38 ) < 0 )
F_77 ( L_1 ,
( unsigned long long ) V_4 -> V_8 . V_87 . V_89 ) ;
return V_38 & 0x1 ;
}
static void F_78 ( struct V_3 * V_4 )
{
if ( F_71 ( V_4 , V_91 ) < 0 ) {
F_77 ( L_2 ,
( unsigned long long ) V_4 -> V_8 . V_87 . V_89 ) ;
return;
}
F_79 ( V_92 , & V_4 -> V_8 . V_93 ) ;
}
static void F_80 ( struct V_3 * V_4 )
{
if ( F_71 ( V_4 , V_94 ) < 0 ) {
F_77 ( L_3 ,
( unsigned long long ) V_4 -> V_8 . V_87 . V_89 ) ;
return;
}
F_81 ( V_92 , & V_4 -> V_8 . V_93 ) ;
}
static void F_82 ( struct V_6 * V_7 )
{
T_1 V_95 , V_96 , V_97 , V_98 ;
int V_99 ;
V_98 = F_24 ( V_7 , V_100 ) ;
V_95 = F_24 ( V_7 , V_101 ) ;
V_99 = F_65 ( V_7 ) ;
V_96 = ( V_99 != - 1 ) ? V_99 : 0 ;
if ( ( V_95 & 0xf0 ) >= ( V_96 & 0xf0 ) )
V_97 = V_95 & 0xff ;
else
V_97 = V_96 & 0xf0 ;
F_77 ( L_4 ,
V_7 , V_97 , V_99 , V_96 ) ;
if ( V_98 != V_97 ) {
F_36 ( V_7 , V_100 , V_97 ) ;
if ( V_97 < V_98 )
F_58 ( V_72 , V_7 -> V_4 ) ;
}
}
static void F_83 ( struct V_6 * V_7 , T_1 V_95 )
{
F_36 ( V_7 , V_101 , V_95 ) ;
F_82 ( V_7 ) ;
}
static bool F_84 ( struct V_6 * V_7 , T_1 V_102 )
{
if ( F_26 ( V_7 ) )
return V_102 == V_103 ;
return F_85 ( V_102 ) == V_104 ;
}
static bool F_86 ( struct V_6 * V_7 , T_1 V_102 )
{
if ( F_84 ( V_7 , V_102 ) )
return true ;
if ( F_26 ( V_7 ) )
return V_102 == F_23 ( V_7 ) ;
return V_102 == F_87 ( F_23 ( V_7 ) ) ;
}
static bool F_88 ( struct V_6 * V_7 , T_1 V_102 )
{
T_1 V_105 ;
if ( F_84 ( V_7 , V_102 ) )
return true ;
V_105 = F_24 ( V_7 , V_31 ) ;
if ( F_26 ( V_7 ) )
return ( ( V_105 >> 16 ) == ( V_102 >> 16 ) )
&& ( V_105 & V_102 & 0xffff ) != 0 ;
V_105 = F_27 ( V_105 ) ;
V_102 = F_85 ( V_102 ) ;
switch ( F_24 ( V_7 , V_33 ) ) {
case V_34 :
return ( V_105 & V_102 ) != 0 ;
case V_106 :
return ( ( V_105 >> 4 ) == ( V_102 >> 4 ) )
&& ( V_105 & V_102 & 0xf ) != 0 ;
default:
F_77 ( L_5 ,
V_7 -> V_4 -> V_107 , F_24 ( V_7 , V_33 ) ) ;
return false ;
}
}
static T_1 F_89 ( unsigned int V_15 , struct V_6 * V_108 ,
struct V_6 * V_109 )
{
bool V_110 = V_108 != NULL ;
bool V_111 = F_26 ( V_110 ? V_108 : V_109 ) ;
if ( ! V_110 && V_15 == V_104 && V_111 )
return V_103 ;
return V_111 ? V_15 : F_87 ( V_15 ) ;
}
bool F_90 ( struct V_3 * V_4 , struct V_6 * V_108 ,
int V_112 , unsigned int V_113 , int V_114 )
{
struct V_6 * V_109 = V_4 -> V_8 . V_7 ;
T_1 V_102 = F_89 ( V_113 , V_108 , V_109 ) ;
F_77 ( L_6
L_7 ,
V_109 , V_108 , V_113 , V_114 , V_112 ) ;
ASSERT ( V_109 ) ;
switch ( V_112 ) {
case V_115 :
if ( V_114 == V_116 )
return F_86 ( V_109 , V_102 ) ;
else
return F_88 ( V_109 , V_102 ) ;
case V_117 :
return V_109 == V_108 ;
case V_118 :
return true ;
case V_119 :
return V_109 != V_108 ;
default:
F_77 ( L_8 ,
V_112 ) ;
return false ;
}
}
int F_91 ( T_1 V_5 , T_1 V_120 ,
const unsigned long * V_2 , T_1 V_121 )
{
T_1 V_122 ;
int V_25 , V_123 = - 1 ;
V_122 = V_5 % V_120 ;
for ( V_25 = 0 ; V_25 <= V_122 ; V_25 ++ ) {
V_123 = F_92 ( V_2 , V_121 , V_123 + 1 ) ;
F_64 ( V_123 == V_121 ) ;
}
return V_123 ;
}
static void F_93 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_8 . V_124 ) {
V_22 -> V_8 . V_124 = true ;
F_94 ( V_125
L_9 ) ;
}
}
bool F_95 ( struct V_22 * V_22 , struct V_6 * V_126 ,
struct V_81 * V_82 , int * V_127 , struct V_83 * V_83 )
{
struct V_12 * V_13 ;
unsigned long V_2 = 1 ;
struct V_6 * * V_128 ;
int V_25 ;
bool V_129 , V_130 ;
* V_127 = - 1 ;
if ( V_82 -> V_131 == V_117 ) {
* V_127 = F_69 ( V_126 -> V_4 , V_82 , V_83 ) ;
return true ;
}
if ( V_82 -> V_131 )
return false ;
V_130 = V_126 && F_26 ( V_126 ) ;
if ( V_82 -> V_15 == ( V_130 ? V_103 : V_104 ) )
return false ;
V_129 = true ;
F_96 () ;
V_13 = F_97 ( V_22 -> V_8 . V_36 ) ;
if ( ! V_13 ) {
V_129 = false ;
goto V_28;
}
if ( V_82 -> V_114 == V_116 ) {
if ( V_82 -> V_15 >= F_25 ( V_13 -> V_32 ) )
goto V_28;
V_128 = & V_13 -> V_32 [ V_82 -> V_15 ] ;
} else {
T_2 V_16 ;
if ( ! F_15 ( V_13 ) ) {
V_129 = false ;
goto V_28;
}
F_16 ( V_13 , V_82 -> V_15 , & V_16 , ( T_2 * ) & V_2 ) ;
if ( V_16 >= F_25 ( V_13 -> V_35 ) )
goto V_28;
V_128 = V_13 -> V_35 [ V_16 ] ;
if ( ! F_98 ( V_82 ) )
goto V_132;
if ( ! F_99 () ) {
int V_133 = - 1 ;
F_100 (i, &bitmap, 16 ) {
if ( ! V_128 [ V_25 ] )
continue;
if ( V_133 < 0 )
V_133 = V_25 ;
else if ( F_101 ( V_128 [ V_25 ] -> V_4 ,
V_128 [ V_133 ] -> V_4 ) < 0 )
V_133 = V_25 ;
}
V_2 = ( V_133 >= 0 ) ? 1 << V_133 : 0 ;
} else {
int V_123 ;
unsigned int V_120 ;
V_120 = F_102 ( V_2 ) ;
if ( V_120 == 0 )
goto V_28;
V_123 = F_91 ( V_82 -> V_5 ,
V_120 , & V_2 , 16 ) ;
if ( ! V_128 [ V_123 ] ) {
F_93 ( V_22 ) ;
goto V_28;
}
V_2 = ( V_123 >= 0 ) ? 1 << V_123 : 0 ;
}
}
V_132:
F_100 (i, &bitmap, 16 ) {
if ( ! V_128 [ V_25 ] )
continue;
if ( * V_127 < 0 )
* V_127 = 0 ;
* V_127 += F_69 ( V_128 [ V_25 ] -> V_4 , V_82 , V_83 ) ;
}
V_28:
F_103 () ;
return V_129 ;
}
bool F_104 ( struct V_22 * V_22 , struct V_81 * V_82 ,
struct V_3 * * V_134 )
{
struct V_12 * V_13 ;
bool V_129 = false ;
struct V_6 * V_128 = NULL ;
if ( V_82 -> V_131 )
return false ;
F_96 () ;
V_13 = F_97 ( V_22 -> V_8 . V_36 ) ;
if ( ! V_13 )
goto V_28;
if ( V_82 -> V_114 == V_116 ) {
if ( V_82 -> V_15 == 0xFF )
goto V_28;
if ( V_82 -> V_15 >= F_25 ( V_13 -> V_32 ) )
goto V_28;
V_128 = V_13 -> V_32 [ V_82 -> V_15 ] ;
if ( V_128 && F_22 ( V_128 -> V_4 ) )
* V_134 = V_128 -> V_4 ;
else
goto V_28;
} else {
T_2 V_16 ;
unsigned long V_2 = 1 ;
int V_25 , V_127 = 0 ;
if ( ! F_15 ( V_13 ) )
goto V_28;
F_16 ( V_13 , V_82 -> V_15 , & V_16 , ( T_2 * ) & V_2 ) ;
if ( V_16 >= F_25 ( V_13 -> V_35 ) )
goto V_28;
if ( F_99 () &&
F_98 ( V_82 ) ) {
int V_123 ;
unsigned int V_120 ;
V_120 = F_102 ( V_2 ) ;
if ( V_120 == 0 )
goto V_28;
V_123 = F_91 ( V_82 -> V_5 , V_120 ,
& V_2 , 16 ) ;
V_128 = V_13 -> V_35 [ V_16 ] [ V_123 ] ;
if ( ! V_128 ) {
F_93 ( V_22 ) ;
goto V_28;
}
* V_134 = V_128 -> V_4 ;
} else {
F_100 (i, &bitmap, 16 ) {
V_128 = V_13 -> V_35 [ V_16 ] [ V_25 ] ;
if ( ++ V_127 == 2 )
goto V_28;
}
if ( V_128 && F_22 ( V_128 -> V_4 ) )
* V_134 = V_128 -> V_4 ;
else
goto V_28;
}
}
V_129 = true ;
V_28:
F_103 () ;
return V_129 ;
}
static int F_70 ( struct V_6 * V_7 , int V_84 ,
int V_5 , int V_85 , int V_86 ,
struct V_83 * V_83 )
{
int V_73 = 0 ;
struct V_3 * V_4 = V_7 -> V_4 ;
F_105 ( V_4 -> V_107 , V_84 ,
V_86 , V_5 ) ;
switch ( V_84 ) {
case V_135 :
V_4 -> V_8 . V_136 ++ ;
case V_137 :
if ( F_62 ( V_86 && ! V_85 ) )
break;
if ( F_62 ( ! F_12 ( V_7 ) ) )
break;
V_73 = 1 ;
if ( V_83 ) {
F_79 ( V_4 -> V_107 , V_83 -> V_13 ) ;
V_83 -> V_138 [ V_4 -> V_107 ] = V_5 ;
}
if ( F_1 ( V_5 , V_7 -> V_9 + V_139 ) != ! ! V_86 ) {
if ( V_86 )
F_106 ( V_5 , V_7 -> V_9 + V_139 ) ;
else
F_6 ( V_5 , V_7 -> V_9 + V_139 ) ;
}
if ( V_4 -> V_8 . V_75 )
V_76 -> V_140 ( V_4 , V_5 ) ;
else {
F_107 ( V_5 , V_7 ) ;
F_58 ( V_72 , V_4 ) ;
F_108 ( V_4 ) ;
}
break;
case V_141 :
V_73 = 1 ;
V_4 -> V_8 . V_142 . V_143 = 1 ;
F_58 ( V_72 , V_4 ) ;
F_108 ( V_4 ) ;
break;
case V_144 :
V_73 = 1 ;
F_58 ( V_145 , V_4 ) ;
F_108 ( V_4 ) ;
break;
case V_57 :
V_73 = 1 ;
F_109 ( V_4 ) ;
F_108 ( V_4 ) ;
break;
case V_146 :
if ( ! V_86 || V_85 ) {
V_73 = 1 ;
V_7 -> V_147 = ( 1UL << V_148 ) ;
F_110 () ;
F_58 ( V_72 , V_4 ) ;
F_108 ( V_4 ) ;
} else {
F_77 ( L_10 ,
V_4 -> V_107 ) ;
}
break;
case V_149 :
F_77 ( L_11 ,
V_4 -> V_107 , V_5 ) ;
V_73 = 1 ;
V_7 -> V_150 = V_5 ;
F_110 () ;
F_111 ( V_151 , & V_7 -> V_147 ) ;
F_58 ( V_72 , V_4 ) ;
F_108 ( V_4 ) ;
break;
case V_152 :
break;
default:
F_94 ( V_153 L_12 ,
V_84 ) ;
break;
}
return V_73 ;
}
int F_101 ( struct V_3 * V_154 , struct V_3 * V_155 )
{
return V_154 -> V_8 . V_136 - V_155 -> V_8 . V_136 ;
}
static bool F_112 ( struct V_6 * V_7 , int V_5 )
{
return F_2 ( V_5 , V_7 -> V_4 -> V_8 . V_156 ) ;
}
static void F_113 ( struct V_6 * V_7 , int V_5 )
{
int V_157 ;
if ( ! F_112 ( V_7 , V_5 ) )
return;
if ( F_114 ( V_7 -> V_4 -> V_22 ) ) {
V_7 -> V_4 -> V_8 . V_158 = V_5 ;
F_58 ( V_159 , V_7 -> V_4 ) ;
return;
}
if ( F_1 ( V_5 , V_7 -> V_9 + V_139 ) )
V_157 = V_160 ;
else
V_157 = V_161 ;
F_115 ( V_7 -> V_4 , V_5 , V_157 ) ;
}
static int F_116 ( struct V_6 * V_7 )
{
int V_5 = F_65 ( V_7 ) ;
F_117 ( V_7 , V_5 ) ;
if ( V_5 == - 1 )
return V_5 ;
F_67 ( V_5 , V_7 ) ;
F_82 ( V_7 ) ;
if ( F_2 ( V_5 , F_118 ( V_7 -> V_4 ) -> V_162 ) )
F_119 ( V_7 -> V_4 , V_5 ) ;
F_113 ( V_7 , V_5 ) ;
F_58 ( V_72 , V_7 -> V_4 ) ;
return V_5 ;
}
void F_120 ( struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_117 ( V_7 , V_5 ) ;
F_113 ( V_7 , V_5 ) ;
F_58 ( V_72 , V_7 -> V_4 ) ;
}
static void F_121 ( struct V_6 * V_7 )
{
T_1 V_163 = F_24 ( V_7 , V_164 ) ;
T_1 V_165 = F_24 ( V_7 , V_166 ) ;
struct V_81 V_82 ;
V_82 . V_5 = V_163 & V_49 ;
V_82 . V_84 = V_163 & V_56 ;
V_82 . V_114 = V_163 & V_167 ;
V_82 . V_85 = ( V_163 & V_168 ) != 0 ;
V_82 . V_86 = V_163 & V_169 ;
V_82 . V_131 = V_163 & V_170 ;
V_82 . V_171 = false ;
if ( F_26 ( V_7 ) )
V_82 . V_15 = V_165 ;
else
V_82 . V_15 = F_85 ( V_165 ) ;
F_122 ( V_163 , V_82 . V_15 ) ;
F_77 ( L_13
L_14
L_15
L_16 ,
V_165 , V_163 , V_82 . V_131 , V_82 . V_15 ,
V_82 . V_86 , V_82 . V_85 , V_82 . V_114 , V_82 . V_84 ,
V_82 . V_5 , V_82 . V_171 ) ;
F_123 ( V_7 -> V_4 -> V_22 , V_7 , & V_82 , NULL ) ;
}
static T_1 F_124 ( struct V_6 * V_7 )
{
T_4 V_172 ;
T_5 V_173 ;
T_1 V_174 ;
ASSERT ( V_7 != NULL ) ;
if ( F_24 ( V_7 , V_175 ) == 0 ||
V_7 -> V_50 . V_176 == 0 )
return 0 ;
V_172 = F_125 ( & V_7 -> V_50 . V_177 ) ;
if ( F_126 ( V_172 ) < 0 )
V_172 = F_127 ( 0 , 0 ) ;
V_173 = F_128 ( F_126 ( V_172 ) , V_7 -> V_50 . V_176 ) ;
V_174 = F_129 ( V_173 ,
( V_178 * V_7 -> V_179 ) ) ;
return V_174 ;
}
static void F_130 ( struct V_6 * V_7 , bool V_180 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_181 * V_182 = V_4 -> V_182 ;
F_58 ( V_183 , V_4 ) ;
V_182 -> V_184 . V_185 = F_131 ( V_4 ) ;
V_182 -> V_184 . V_186 = V_180 ;
}
static inline void F_132 ( struct V_6 * V_7 , bool V_180 )
{
if ( V_7 -> V_4 -> V_8 . V_187 )
F_130 ( V_7 , V_180 ) ;
}
static T_1 F_133 ( struct V_6 * V_7 , unsigned int V_188 )
{
T_1 V_38 = 0 ;
if ( V_188 >= V_189 )
return 0 ;
switch ( V_188 ) {
case V_46 :
if ( F_26 ( V_7 ) )
V_38 = F_23 ( V_7 ) ;
else
V_38 = F_23 ( V_7 ) << 24 ;
break;
case V_190 :
F_77 ( L_17 ) ;
break;
case V_191 :
if ( F_46 ( V_7 ) )
return 0 ;
V_38 = F_124 ( V_7 ) ;
break;
case V_100 :
F_82 ( V_7 ) ;
V_38 = F_24 ( V_7 , V_188 ) ;
break;
case V_101 :
F_132 ( V_7 , false ) ;
default:
V_38 = F_24 ( V_7 , V_188 ) ;
break;
}
return V_38 ;
}
static inline struct V_6 * F_134 ( struct V_192 * V_193 )
{
return F_135 ( V_193 , struct V_6 , V_193 ) ;
}
int F_136 ( struct V_6 * V_7 , T_1 V_188 , int V_194 ,
void * V_88 )
{
unsigned char V_195 = V_188 & 0xf ;
T_1 V_73 ;
static const T_6 V_196 = 0x43ff01ffffffe70cULL ;
if ( ( V_195 + V_194 ) > 4 ) {
F_77 ( L_18 ,
V_188 , V_194 ) ;
return 1 ;
}
if ( V_188 > 0x3f0 || ! ( V_196 & ( 1ULL << ( V_188 >> 4 ) ) ) ) {
F_77 ( L_19 ,
V_188 ) ;
return 1 ;
}
V_73 = F_133 ( V_7 , V_188 & ~ 0xf ) ;
F_137 ( V_188 , V_73 ) ;
switch ( V_194 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_88 , ( char * ) & V_73 + V_195 , V_194 ) ;
break;
default:
F_94 ( V_153 L_20
L_21 , V_194 ) ;
break;
}
return 0 ;
}
static int F_138 ( struct V_6 * V_7 , T_7 V_197 )
{
return F_14 ( V_7 ) &&
V_197 >= V_7 -> V_198 &&
V_197 < V_7 -> V_198 + V_189 ;
}
static int F_139 ( struct V_3 * V_4 , struct V_192 * V_199 ,
T_7 V_200 , int V_194 , void * V_88 )
{
struct V_6 * V_7 = F_134 ( V_199 ) ;
T_1 V_188 = V_200 - V_7 -> V_198 ;
if ( ! F_138 ( V_7 , V_200 ) )
return - V_201 ;
F_136 ( V_7 , V_188 , V_194 , V_88 ) ;
return 0 ;
}
static void F_140 ( struct V_6 * V_7 )
{
T_1 V_202 , V_203 , V_204 ;
V_204 = F_24 ( V_7 , V_205 ) ;
V_202 = V_204 & 0xf ;
V_203 = ( ( V_202 & 0x3 ) | ( ( V_202 & 0x8 ) >> 1 ) ) + 1 ;
V_7 -> V_179 = 0x1 << ( V_203 & 0x7 ) ;
F_77 ( L_22 ,
V_7 -> V_179 ) ;
}
static void F_141 ( struct V_6 * V_7 )
{
T_1 V_51 = F_24 ( V_7 , V_206 ) &
V_7 -> V_50 . V_207 ;
if ( V_7 -> V_50 . V_51 != V_51 ) {
V_7 -> V_50 . V_51 = V_51 ;
F_142 ( & V_7 -> V_50 . V_177 ) ;
}
}
static void F_143 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_208 * V_209 = & V_4 -> V_210 ;
struct V_211 * V_212 = & V_7 -> V_50 ;
if ( F_144 ( & V_7 -> V_50 . V_213 ) )
return;
F_145 ( & V_7 -> V_50 . V_213 ) ;
F_146 ( V_4 ) ;
if ( F_147 ( V_209 ) )
F_148 ( V_209 ) ;
if ( F_46 ( V_7 ) )
V_212 -> V_214 = V_212 -> V_215 ;
}
static bool F_149 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_1 V_66 = F_24 ( V_7 , V_206 ) ;
if ( F_14 ( V_7 ) ) {
int V_1 = V_66 & V_49 ;
void * V_2 = V_7 -> V_9 + V_10 ;
if ( V_4 -> V_8 . V_75 )
V_2 = V_7 -> V_9 + V_11 ;
if ( F_1 ( V_1 , V_2 ) )
return true ;
}
return false ;
}
void F_150 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_6 V_216 , V_217 ;
if ( ! F_49 ( V_4 ) )
return;
if ( V_7 -> V_50 . V_214 == 0 )
return;
if ( ! F_149 ( V_4 ) )
return;
V_217 = V_7 -> V_50 . V_214 ;
V_7 -> V_50 . V_214 = 0 ;
V_216 = F_151 ( V_4 , F_152 () ) ;
F_153 ( V_4 -> V_107 , V_216 - V_217 ) ;
if ( V_216 < V_217 )
F_154 ( F_155 ( V_217 - V_216 ,
F_156 ( V_4 , V_218 ) ) ) ;
}
static void F_157 ( struct V_6 * V_7 )
{
T_4 V_219 ;
F_158 ( & V_7 -> V_50 . V_213 , 0 ) ;
if ( F_45 ( V_7 ) || F_44 ( V_7 ) ) {
V_219 = V_7 -> V_50 . V_177 . V_220 -> V_221 () ;
V_7 -> V_50 . V_176 = ( T_6 ) F_24 ( V_7 , V_175 )
* V_178 * V_7 -> V_179 ;
if ( ! V_7 -> V_50 . V_176 )
return;
if ( F_45 ( V_7 ) ) {
T_5 V_222 = V_223 * 1000LL ;
if ( V_7 -> V_50 . V_176 < V_222 ) {
F_159 (
L_23
L_24 ,
V_7 -> V_4 -> V_107 ,
V_7 -> V_50 . V_176 , V_222 ) ;
V_7 -> V_50 . V_176 = V_222 ;
}
}
F_160 ( & V_7 -> V_50 . V_177 ,
F_161 ( V_219 , V_7 -> V_50 . V_176 ) ,
V_224 ) ;
F_77 ( L_25 V_225 L_26
V_226 L_27
L_28
L_29 V_226 L_30 , V_227 ,
V_178 , F_126 ( V_219 ) ,
F_24 ( V_7 , V_175 ) ,
V_7 -> V_50 . V_176 ,
F_126 ( F_161 ( V_219 ,
V_7 -> V_50 . V_176 ) ) ) ;
} else if ( F_46 ( V_7 ) ) {
T_6 V_216 , V_215 = V_7 -> V_50 . V_215 ;
T_6 V_173 = 0 ;
T_4 V_228 ;
struct V_3 * V_4 = V_7 -> V_4 ;
unsigned long V_229 = V_4 -> V_8 . V_230 ;
unsigned long V_231 ;
if ( F_62 ( ! V_215 || ! V_229 ) )
return;
F_162 ( V_231 ) ;
V_219 = V_7 -> V_50 . V_177 . V_220 -> V_221 () ;
V_216 = F_151 ( V_4 , F_152 () ) ;
if ( F_66 ( V_215 > V_216 ) ) {
V_173 = ( V_215 - V_216 ) * 1000000ULL ;
F_163 ( V_173 , V_229 ) ;
V_228 = F_161 ( V_219 , V_173 ) ;
V_228 = F_164 ( V_228 , V_218 ) ;
F_160 ( & V_7 -> V_50 . V_177 ,
V_228 , V_224 ) ;
} else
F_143 ( V_7 ) ;
F_165 ( V_231 ) ;
}
}
static void F_166 ( struct V_6 * V_7 , T_1 V_232 )
{
bool V_233 = F_47 ( V_232 ) ;
if ( V_7 -> V_233 != V_233 ) {
V_7 -> V_233 = V_233 ;
if ( V_233 ) {
F_77 ( L_31
L_32 , V_7 -> V_4 -> V_107 ) ;
F_145 ( & V_7 -> V_4 -> V_22 -> V_8 . V_234 ) ;
} else
F_167 ( & V_7 -> V_4 -> V_22 -> V_8 . V_234 ) ;
}
}
int F_168 ( struct V_6 * V_7 , T_1 V_66 , T_1 V_38 )
{
int V_129 = 0 ;
F_169 ( V_66 , V_38 ) ;
switch ( V_66 ) {
case V_46 :
if ( ! F_26 ( V_7 ) )
F_39 ( V_7 , V_38 >> 24 ) ;
else
V_129 = 1 ;
break;
case V_101 :
F_132 ( V_7 , true ) ;
F_83 ( V_7 , V_38 & 0xff ) ;
break;
case V_235 :
F_116 ( V_7 ) ;
break;
case V_31 :
if ( ! F_26 ( V_7 ) )
F_40 ( V_7 , V_38 & V_236 ) ;
else
V_129 = 1 ;
break;
case V_33 :
if ( ! F_26 ( V_7 ) ) {
F_36 ( V_7 , V_33 , V_38 | 0x0FFFFFFF ) ;
F_18 ( V_7 -> V_4 -> V_22 ) ;
} else
V_129 = 1 ;
break;
case V_41 : {
T_1 V_237 = 0x3ff ;
if ( F_24 ( V_7 , V_65 ) & V_64 )
V_237 |= V_238 ;
F_35 ( V_7 , V_38 & V_237 ) ;
if ( ! ( V_38 & V_40 ) ) {
int V_25 ;
T_1 V_55 ;
for ( V_25 = 0 ; V_25 < V_239 ; V_25 ++ ) {
V_55 = F_24 ( V_7 ,
V_206 + 0x10 * V_25 ) ;
F_36 ( V_7 , V_206 + 0x10 * V_25 ,
V_55 | V_48 ) ;
}
F_141 ( V_7 ) ;
F_158 ( & V_7 -> V_50 . V_213 , 0 ) ;
}
break;
}
case V_164 :
F_36 ( V_7 , V_164 , V_38 & ~ ( 1 << 12 ) ) ;
F_121 ( V_7 ) ;
break;
case V_166 :
if ( ! F_26 ( V_7 ) )
V_38 &= 0xff000000 ;
F_36 ( V_7 , V_166 , V_38 ) ;
break;
case V_240 :
F_166 ( V_7 , V_38 ) ;
case V_241 :
case V_242 :
case V_243 :
case V_244 :
if ( ! F_13 ( V_7 ) )
V_38 |= V_48 ;
V_38 &= V_245 [ ( V_66 - V_206 ) >> 4 ] ;
F_36 ( V_7 , V_66 , V_38 ) ;
break;
case V_206 :
if ( ! F_13 ( V_7 ) )
V_38 |= V_48 ;
V_38 &= ( V_245 [ 0 ] | V_7 -> V_50 . V_207 ) ;
F_36 ( V_7 , V_206 , V_38 ) ;
F_141 ( V_7 ) ;
break;
case V_175 :
if ( F_46 ( V_7 ) )
break;
F_142 ( & V_7 -> V_50 . V_177 ) ;
F_36 ( V_7 , V_175 , V_38 ) ;
F_157 ( V_7 ) ;
break;
case V_205 :
if ( V_38 & 4 )
F_77 ( L_33 , V_38 ) ;
F_36 ( V_7 , V_205 , V_38 ) ;
F_140 ( V_7 ) ;
break;
case V_246 :
if ( F_26 ( V_7 ) && V_38 != 0 ) {
F_77 ( L_34 , V_38 ) ;
V_129 = 1 ;
}
break;
case V_247 :
if ( F_26 ( V_7 ) ) {
F_168 ( V_7 , V_164 , 0x40000 | ( V_38 & 0xff ) ) ;
} else
V_129 = 1 ;
break;
default:
V_129 = 1 ;
break;
}
if ( V_129 )
F_77 ( L_35 , V_66 ) ;
return V_129 ;
}
static int F_170 ( struct V_3 * V_4 , struct V_192 * V_199 ,
T_7 V_200 , int V_194 , const void * V_88 )
{
struct V_6 * V_7 = F_134 ( V_199 ) ;
unsigned int V_188 = V_200 - V_7 -> V_198 ;
T_1 V_38 ;
if ( ! F_138 ( V_7 , V_200 ) )
return - V_201 ;
if ( V_194 != 4 || ( V_188 & 0xf ) ) {
F_77 ( L_36 , V_194 , ( long ) V_200 ) ;
return 0 ;
}
V_38 = * ( T_1 * ) V_88 ;
if ( V_188 != V_235 )
F_77 ( L_37
L_38 , V_227 , V_188 , V_194 , V_38 ) ;
F_168 ( V_7 , V_188 & 0xff0 , V_38 ) ;
return 0 ;
}
void F_171 ( struct V_3 * V_4 )
{
F_168 ( V_4 -> V_8 . V_7 , V_235 , 0 ) ;
}
void F_172 ( struct V_3 * V_4 , T_1 V_188 )
{
T_1 V_38 = 0 ;
V_188 &= 0xff0 ;
F_136 ( V_4 -> V_8 . V_7 , V_188 , 4 , & V_38 ) ;
F_168 ( V_4 -> V_8 . V_7 , V_188 , V_38 ) ;
}
void F_173 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! V_4 -> V_8 . V_7 )
return;
F_142 ( & V_7 -> V_50 . V_177 ) ;
if ( ! ( V_4 -> V_8 . V_248 & V_249 ) )
F_37 ( & V_250 ) ;
if ( ! V_7 -> V_42 )
F_37 ( & V_43 ) ;
if ( V_7 -> V_9 )
F_174 ( ( unsigned long ) V_7 -> V_9 ) ;
F_175 ( V_7 ) ;
}
T_6 F_176 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_49 ( V_4 ) || F_44 ( V_7 ) ||
F_45 ( V_7 ) )
return 0 ;
return V_7 -> V_50 . V_215 ;
}
void F_177 ( struct V_3 * V_4 , T_6 V_88 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_49 ( V_4 ) || F_44 ( V_7 ) ||
F_45 ( V_7 ) )
return;
F_142 ( & V_7 -> V_50 . V_177 ) ;
V_7 -> V_50 . V_215 = V_88 ;
F_157 ( V_7 ) ;
}
void F_178 ( struct V_3 * V_4 , unsigned long V_251 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_83 ( V_7 , ( ( V_251 & 0x0f ) << 4 )
| ( F_24 ( V_7 , V_101 ) & 4 ) ) ;
}
T_6 F_179 ( struct V_3 * V_4 )
{
T_6 V_95 ;
V_95 = ( T_6 ) F_24 ( V_4 -> V_8 . V_7 , V_101 ) ;
return ( V_95 & 0xf0 ) >> 4 ;
}
void F_180 ( struct V_3 * V_4 , T_6 V_252 )
{
T_6 V_253 = V_4 -> V_8 . V_248 ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! V_7 ) {
V_252 |= V_254 ;
V_4 -> V_8 . V_248 = V_252 ;
return;
}
V_4 -> V_8 . V_248 = V_252 ;
if ( ( V_253 ^ V_252 ) & V_249 ) {
if ( V_252 & V_249 )
F_37 ( & V_250 ) ;
else
F_38 ( & V_250 . V_44 ) ;
F_18 ( V_4 -> V_22 ) ;
}
if ( ( V_253 ^ V_252 ) & V_255 ) {
if ( V_252 & V_255 ) {
F_41 ( V_7 , V_4 -> V_107 ) ;
V_76 -> V_256 ( V_4 , true ) ;
} else
V_76 -> V_256 ( V_4 , false ) ;
}
V_7 -> V_198 = V_7 -> V_4 -> V_8 . V_248 &
V_257 ;
if ( ( V_252 & V_249 ) &&
V_7 -> V_198 != V_258 )
F_181 ( L_39 ) ;
F_77 ( L_40 V_226 L_41
L_42 , V_7 -> V_4 -> V_8 . V_248 , V_7 -> V_198 ) ;
}
void F_182 ( struct V_3 * V_4 , bool V_259 )
{
struct V_6 * V_7 ;
int V_25 ;
F_77 ( L_43 , V_227 ) ;
ASSERT ( V_4 ) ;
V_7 = V_4 -> V_8 . V_7 ;
ASSERT ( V_7 != NULL ) ;
F_142 ( & V_7 -> V_50 . V_177 ) ;
if ( ! V_259 )
F_39 ( V_7 , V_4 -> V_107 ) ;
F_48 ( V_7 -> V_4 ) ;
for ( V_25 = 0 ; V_25 < V_239 ; V_25 ++ )
F_36 ( V_7 , V_206 + 0x10 * V_25 , V_48 ) ;
F_141 ( V_7 ) ;
if ( F_183 ( V_4 -> V_22 , V_260 ) )
F_36 ( V_7 , V_240 ,
F_184 ( 0 , V_261 ) ) ;
F_166 ( V_7 , F_24 ( V_7 , V_240 ) ) ;
F_36 ( V_7 , V_33 , 0xffffffffU ) ;
F_35 ( V_7 , 0xff ) ;
F_36 ( V_7 , V_101 , 0 ) ;
if ( ! F_26 ( V_7 ) )
F_40 ( V_7 , 0 ) ;
F_36 ( V_7 , V_246 , 0 ) ;
F_36 ( V_7 , V_164 , 0 ) ;
F_36 ( V_7 , V_166 , 0 ) ;
F_36 ( V_7 , V_205 , 0 ) ;
F_36 ( V_7 , V_175 , 0 ) ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ ) {
F_36 ( V_7 , V_11 + 0x10 * V_25 , 0 ) ;
F_36 ( V_7 , V_10 + 0x10 * V_25 , 0 ) ;
F_36 ( V_7 , V_139 + 0x10 * V_25 , 0 ) ;
}
V_7 -> V_74 = V_4 -> V_8 . V_75 ;
V_7 -> V_79 = V_4 -> V_8 . V_75 ? 1 : 0 ;
V_7 -> V_80 = - 1 ;
F_140 ( V_7 ) ;
F_158 ( & V_7 -> V_50 . V_213 , 0 ) ;
if ( F_185 ( V_4 ) )
F_180 ( V_4 ,
V_4 -> V_8 . V_248 | V_254 ) ;
V_4 -> V_8 . V_87 . V_89 = 0 ;
F_82 ( V_7 ) ;
V_4 -> V_8 . V_136 = 0 ;
V_4 -> V_8 . V_93 = 0 ;
F_77 ( L_44
L_45 V_226 L_46 , V_227 ,
V_4 , F_23 ( V_7 ) ,
V_4 -> V_8 . V_248 , V_7 -> V_198 ) ;
}
static bool F_186 ( struct V_6 * V_7 )
{
return F_45 ( V_7 ) ;
}
int F_187 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( F_12 ( V_7 ) && F_42 ( V_7 , V_206 ) )
return F_144 ( & V_7 -> V_50 . V_213 ) ;
return 0 ;
}
int F_188 ( struct V_6 * V_7 , int V_47 )
{
T_1 V_66 = F_24 ( V_7 , V_47 ) ;
int V_5 , V_14 , V_86 ;
if ( F_14 ( V_7 ) && ! ( V_66 & V_48 ) ) {
V_5 = V_66 & V_49 ;
V_14 = V_66 & V_56 ;
V_86 = V_66 & V_262 ;
return F_70 ( V_7 , V_14 , V_5 , 1 , V_86 ,
NULL ) ;
}
return 0 ;
}
void F_189 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( V_7 )
F_188 ( V_7 , V_240 ) ;
}
static enum V_263 F_190 ( struct V_264 * V_88 )
{
struct V_211 * V_212 = F_135 ( V_88 , struct V_211 , V_177 ) ;
struct V_6 * V_7 = F_135 ( V_212 , struct V_6 , V_50 ) ;
F_143 ( V_7 ) ;
if ( F_186 ( V_7 ) ) {
F_191 ( & V_212 -> V_177 , V_212 -> V_176 ) ;
return V_265 ;
} else
return V_266 ;
}
int F_192 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
ASSERT ( V_4 != NULL ) ;
F_77 ( L_47 , V_4 -> V_107 ) ;
V_7 = F_19 ( sizeof( * V_7 ) , V_26 ) ;
if ( ! V_7 )
goto V_267;
V_4 -> V_8 . V_7 = V_7 ;
V_7 -> V_9 = ( void * ) F_193 ( V_26 ) ;
if ( ! V_7 -> V_9 ) {
F_94 ( V_153 L_48 ,
V_4 -> V_107 ) ;
goto V_268;
}
V_7 -> V_4 = V_4 ;
F_194 ( & V_7 -> V_50 . V_177 , V_269 ,
V_224 ) ;
V_7 -> V_50 . V_177 . V_270 = F_190 ;
V_4 -> V_8 . V_248 = V_249 ;
F_180 ( V_4 ,
V_258 | V_249 ) ;
F_38 ( & V_43 . V_44 ) ;
F_182 ( V_4 , false ) ;
F_195 ( & V_7 -> V_193 , & V_271 ) ;
return 0 ;
V_268:
F_175 ( V_7 ) ;
V_267:
return - V_272 ;
}
int F_196 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
int V_273 ;
if ( ! F_12 ( V_7 ) )
return - 1 ;
F_82 ( V_7 ) ;
V_273 = F_60 ( V_7 ) ;
if ( ( V_273 == - 1 ) ||
( ( V_273 & 0xF0 ) <= F_24 ( V_7 , V_100 ) ) )
return - 1 ;
return V_273 ;
}
int F_197 ( struct V_3 * V_4 )
{
T_1 V_274 = F_24 ( V_4 -> V_8 . V_7 , V_240 ) ;
int V_127 = 0 ;
if ( ! F_14 ( V_4 -> V_8 . V_7 ) )
V_127 = 1 ;
if ( ( V_274 & V_48 ) == 0 &&
F_198 ( V_274 ) == V_261 )
V_127 = 1 ;
return V_127 ;
}
void F_199 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( F_144 ( & V_7 -> V_50 . V_213 ) > 0 ) {
F_188 ( V_7 , V_206 ) ;
if ( F_46 ( V_7 ) )
V_7 -> V_50 . V_215 = 0 ;
F_158 ( & V_7 -> V_50 . V_213 , 0 ) ;
}
}
int F_200 ( struct V_3 * V_4 )
{
int V_5 = F_196 ( V_4 ) ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( V_5 == - 1 )
return - 1 ;
F_63 ( V_5 , V_7 ) ;
F_82 ( V_7 ) ;
F_61 ( V_5 , V_7 ) ;
if ( F_2 ( V_5 , F_118 ( V_4 ) -> V_275 ) ) {
F_67 ( V_5 , V_7 ) ;
F_82 ( V_7 ) ;
}
return V_5 ;
}
void F_201 ( struct V_3 * V_4 ,
struct V_276 * V_277 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_180 ( V_4 , V_4 -> V_8 . V_248 ) ;
F_35 ( V_7 , * ( ( T_1 * ) ( V_277 -> V_9 + V_41 ) ) ) ;
memcpy ( V_4 -> V_8 . V_7 -> V_9 , V_277 -> V_9 , sizeof *V_277 ) ;
F_39 ( V_7 , F_23 ( V_7 ) ) ;
F_48 ( V_4 ) ;
F_82 ( V_7 ) ;
F_142 ( & V_7 -> V_50 . V_177 ) ;
F_141 ( V_7 ) ;
F_166 ( V_7 , F_24 ( V_7 , V_240 ) ) ;
F_140 ( V_7 ) ;
F_157 ( V_7 ) ;
V_7 -> V_74 = true ;
V_7 -> V_79 = V_4 -> V_8 . V_75 ?
1 : F_53 ( V_7 -> V_9 + V_10 ) ;
V_7 -> V_80 = - 1 ;
if ( V_4 -> V_8 . V_75 ) {
if ( V_76 -> V_278 )
V_76 -> V_278 ( V_4 ) ;
V_76 -> V_279 ( V_4 ,
F_60 ( V_7 ) ) ;
V_76 -> V_78 ( V_4 ,
F_65 ( V_7 ) ) ;
}
F_58 ( V_72 , V_4 ) ;
if ( F_202 ( V_4 -> V_22 ) )
F_203 ( V_4 ) ;
V_4 -> V_8 . V_136 = 0 ;
}
void F_204 ( struct V_3 * V_4 )
{
struct V_264 * V_177 ;
if ( ! F_49 ( V_4 ) )
return;
V_177 = & V_4 -> V_8 . V_7 -> V_50 . V_177 ;
if ( F_142 ( V_177 ) )
F_205 ( V_177 , V_224 ) ;
}
static void F_206 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
bool V_213 ;
int V_5 ;
F_64 ( ! F_75 ( V_4 ) ) ;
V_213 = F_76 ( V_4 ) ;
F_80 ( V_4 ) ;
if ( V_213 )
return;
V_5 = F_116 ( V_7 ) ;
F_207 ( V_7 , V_5 ) ;
}
void F_208 ( struct V_3 * V_4 )
{
T_1 V_88 ;
if ( F_2 ( V_92 , & V_4 -> V_8 . V_93 ) )
F_206 ( V_4 , V_4 -> V_8 . V_7 ) ;
if ( ! F_2 ( V_280 , & V_4 -> V_8 . V_93 ) )
return;
if ( F_74 ( V_4 -> V_22 , & V_4 -> V_8 . V_7 -> V_281 , & V_88 ,
sizeof( T_1 ) ) )
return;
F_83 ( V_4 -> V_8 . V_7 , V_88 & 0xff ) ;
}
static void F_209 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
if ( ! F_75 ( V_4 ) ||
V_7 -> V_74 ||
V_7 -> V_80 == - 1 ||
F_112 ( V_7 , V_7 -> V_80 ) ) {
return;
}
F_78 ( V_7 -> V_4 ) ;
}
void F_210 ( struct V_3 * V_4 )
{
T_1 V_88 , V_95 ;
int V_282 , V_283 ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_209 ( V_4 , V_7 ) ;
if ( ! F_2 ( V_280 , & V_4 -> V_8 . V_93 ) )
return;
V_95 = F_24 ( V_7 , V_101 ) & 0xff ;
V_282 = F_60 ( V_7 ) ;
if ( V_282 < 0 )
V_282 = 0 ;
V_283 = F_65 ( V_7 ) ;
if ( V_283 < 0 )
V_283 = 0 ;
V_88 = ( V_95 & 0xff ) | ( ( V_283 & 0xf0 ) << 8 ) | ( V_282 << 24 ) ;
F_72 ( V_4 -> V_22 , & V_4 -> V_8 . V_7 -> V_281 , & V_88 ,
sizeof( T_1 ) ) ;
}
int F_211 ( struct V_3 * V_4 , T_7 V_284 )
{
if ( V_284 ) {
if ( F_212 ( V_4 -> V_22 ,
& V_4 -> V_8 . V_7 -> V_281 ,
V_284 , sizeof( T_1 ) ) )
return - V_285 ;
F_79 ( V_280 , & V_4 -> V_8 . V_93 ) ;
} else {
F_81 ( V_280 , & V_4 -> V_8 . V_93 ) ;
}
V_4 -> V_8 . V_7 -> V_284 = V_284 ;
return 0 ;
}
int F_213 ( struct V_3 * V_4 , T_1 V_286 , T_6 V_88 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_1 V_66 = ( V_286 - V_287 ) << 4 ;
if ( ! F_49 ( V_4 ) || ! F_26 ( V_7 ) )
return 1 ;
if ( V_66 == V_166 )
return 1 ;
if ( V_66 == V_164 )
F_168 ( V_7 , V_166 , ( T_1 ) ( V_88 >> 32 ) ) ;
return F_168 ( V_7 , V_66 , ( T_1 ) V_88 ) ;
}
int F_214 ( struct V_3 * V_4 , T_1 V_286 , T_6 * V_88 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_1 V_66 = ( V_286 - V_287 ) << 4 , V_288 , V_289 = 0 ;
if ( ! F_49 ( V_4 ) || ! F_26 ( V_7 ) )
return 1 ;
if ( V_66 == V_33 || V_66 == V_166 ) {
F_77 ( L_49 ,
V_66 ) ;
return 1 ;
}
if ( F_136 ( V_7 , V_66 , 4 , & V_288 ) )
return 1 ;
if ( V_66 == V_164 )
F_136 ( V_7 , V_166 , 4 , & V_289 ) ;
* V_88 = ( ( ( T_6 ) V_289 ) << 32 ) | V_288 ;
return 0 ;
}
int F_215 ( struct V_3 * V_4 , T_1 V_66 , T_6 V_88 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_49 ( V_4 ) )
return 1 ;
if ( V_66 == V_164 )
F_168 ( V_7 , V_166 , ( T_1 ) ( V_88 >> 32 ) ) ;
return F_168 ( V_7 , V_66 , ( T_1 ) V_88 ) ;
}
int F_216 ( struct V_3 * V_4 , T_1 V_66 , T_6 * V_88 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_1 V_288 , V_289 = 0 ;
if ( ! F_49 ( V_4 ) )
return 1 ;
if ( F_136 ( V_7 , V_66 , 4 , & V_288 ) )
return 1 ;
if ( V_66 == V_164 )
F_136 ( V_7 , V_166 , 4 , & V_289 ) ;
* V_88 = ( ( ( T_6 ) V_289 ) << 32 ) | V_288 ;
return 0 ;
}
int F_217 ( struct V_3 * V_4 , T_6 V_88 )
{
T_6 V_197 = V_88 & ~ V_90 ;
if ( ! F_218 ( V_197 , 4 ) )
return 1 ;
V_4 -> V_8 . V_87 . V_89 = V_88 ;
if ( ! F_75 ( V_4 ) )
return 0 ;
return F_212 ( V_4 -> V_22 , & V_4 -> V_8 . V_87 . V_88 ,
V_197 , sizeof( T_3 ) ) ;
}
void F_219 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_3 V_150 ;
unsigned long V_290 ;
if ( ! F_49 ( V_4 ) || ! V_7 -> V_147 )
return;
if ( F_220 ( V_4 ) ) {
F_221 ( V_4 -> V_8 . V_291 == V_292 ) ;
if ( F_2 ( V_151 , & V_7 -> V_147 ) )
F_7 ( V_151 , & V_7 -> V_147 ) ;
return;
}
V_290 = F_56 ( & V_7 -> V_147 , 0 ) ;
if ( F_2 ( V_148 , & V_290 ) ) {
F_182 ( V_4 , true ) ;
F_222 ( V_4 , true ) ;
if ( F_185 ( V_7 -> V_4 ) )
V_4 -> V_8 . V_291 = V_293 ;
else
V_4 -> V_8 . V_291 = V_292 ;
}
if ( F_2 ( V_151 , & V_290 ) &&
V_4 -> V_8 . V_291 == V_292 ) {
F_223 () ;
V_150 = V_7 -> V_150 ;
F_77 ( L_50 ,
V_4 -> V_107 , V_150 ) ;
F_224 ( V_4 , V_150 ) ;
V_4 -> V_8 . V_291 = V_293 ;
}
}
void F_225 ( void )
{
F_226 ( & V_250 , V_294 ) ;
F_226 ( & V_43 , V_294 ) ;
}
