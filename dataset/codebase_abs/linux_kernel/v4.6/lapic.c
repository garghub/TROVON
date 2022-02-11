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
static inline bool F_18 ( struct V_14 * V_15 )
{
return ! ( V_15 -> V_16 & ( V_15 -> V_16 - 1 ) ) ;
}
static inline void
F_19 ( struct V_14 * V_15 , T_1 V_17 , T_2 * V_18 , T_2 * V_19 )
{
unsigned V_20 ;
F_20 ( V_21 != 4 ) ;
F_20 ( V_22 != 8 ) ;
F_20 ( V_23 != 16 ) ;
V_20 = V_15 -> V_16 ;
* V_18 = V_17 >> V_20 ;
* V_19 = V_17 & ( ( 1 << V_20 ) - 1 ) ;
}
static void F_21 ( struct V_24 * V_24 )
{
struct V_14 * V_25 , * V_26 = NULL ;
struct V_8 * V_9 ;
int V_27 ;
V_25 = F_22 ( sizeof( struct V_14 ) , V_28 ) ;
F_23 ( & V_24 -> V_11 . V_29 ) ;
if ( ! V_25 )
goto V_30;
F_24 (i, vcpu, kvm) {
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_2 V_18 , V_19 ;
T_1 V_31 , V_32 ;
if ( ! F_25 ( V_9 ) )
continue;
V_32 = F_26 ( V_2 ) ;
V_31 = F_27 ( V_2 , V_33 ) ;
if ( V_32 < F_28 ( V_25 -> V_34 ) )
V_25 -> V_34 [ V_32 ] = V_2 ;
if ( F_29 ( V_2 ) ) {
V_25 -> V_16 |= V_23 ;
} else if ( V_31 ) {
V_31 = F_30 ( V_31 ) ;
if ( F_27 ( V_2 , V_35 ) == V_36 )
V_25 -> V_16 |= V_22 ;
else
V_25 -> V_16 |= V_21 ;
}
if ( ! F_18 ( V_25 ) )
continue;
F_19 ( V_25 , V_31 , & V_18 , & V_19 ) ;
if ( V_19 && V_18 < F_28 ( V_25 -> V_37 ) )
V_25 -> V_37 [ V_18 ] [ F_31 ( V_19 ) - 1 ] = V_2 ;
}
V_30:
V_26 = F_32 ( V_24 -> V_11 . V_38 ,
F_33 ( & V_24 -> V_11 . V_29 ) ) ;
F_34 ( V_24 -> V_11 . V_38 , V_25 ) ;
F_35 ( & V_24 -> V_11 . V_29 ) ;
if ( V_26 )
F_36 ( V_26 , V_39 ) ;
F_37 ( V_24 ) ;
}
static inline void F_38 ( struct V_1 * V_2 , T_1 V_4 )
{
bool V_40 = V_4 & V_41 ;
F_1 ( V_2 , V_42 , V_4 ) ;
if ( V_40 != V_2 -> V_43 ) {
V_2 -> V_43 = V_40 ;
if ( V_40 ) {
F_39 ( & V_44 ) ;
F_21 ( V_2 -> V_9 -> V_24 ) ;
} else
F_40 ( & V_44 . V_45 ) ;
}
}
static inline void F_41 ( struct V_1 * V_2 , T_3 V_46 )
{
F_1 ( V_2 , V_47 , V_46 << 24 ) ;
F_21 ( V_2 -> V_9 -> V_24 ) ;
}
static inline void F_42 ( struct V_1 * V_2 , T_1 V_46 )
{
F_1 ( V_2 , V_33 , V_46 ) ;
F_21 ( V_2 -> V_9 -> V_24 ) ;
}
static inline void F_43 ( struct V_1 * V_2 , T_3 V_46 )
{
T_1 V_31 = ( ( V_46 >> 4 ) << 16 ) | ( 1 << ( V_46 & 0xf ) ) ;
F_1 ( V_2 , V_47 , V_46 << 24 ) ;
F_1 ( V_2 , V_33 , V_31 ) ;
F_21 ( V_2 -> V_9 -> V_24 ) ;
}
static inline int F_44 ( struct V_1 * V_2 , int V_48 )
{
return ! ( F_27 ( V_2 , V_48 ) & V_49 ) ;
}
static inline int F_45 ( struct V_1 * V_2 , int V_48 )
{
return F_27 ( V_2 , V_48 ) & V_50 ;
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
T_1 V_27 , V_72 ;
for ( V_27 = 0 ; V_27 <= 7 ; V_27 ++ ) {
V_72 = F_58 ( & V_71 [ V_27 ] , 0 ) ;
if ( V_72 )
* ( ( T_1 * ) ( V_5 + V_13 + V_27 * 0x10 ) ) |= V_72 ;
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
if ( V_2 -> V_9 -> V_11 . V_76 )
V_77 -> V_78 ( V_2 -> V_9 ) ;
V_75 = F_62 ( V_2 ) ;
ASSERT ( V_75 == - 1 || V_75 >= 16 ) ;
return V_75 ;
}
static inline void F_64 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = V_2 -> V_9 ;
if ( F_65 ( V_9 -> V_11 . V_76 ) ) {
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
F_60 ( V_73 , V_9 ) ;
} else {
V_2 -> V_74 = false ;
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
if ( F_62 ( V_2 ) != - 1 )
V_2 -> V_74 = true ;
}
}
static inline void F_66 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( F_11 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_65 ( V_9 -> V_11 . V_76 ) )
V_77 -> V_79 ( V_9 -> V_24 , V_6 ) ;
else {
++ V_2 -> V_80 ;
F_67 ( V_2 -> V_80 > V_68 ) ;
V_2 -> V_81 = V_6 ;
}
}
static inline int F_68 ( struct V_1 * V_2 )
{
int V_75 ;
if ( ! V_2 -> V_80 )
return - 1 ;
if ( F_69 ( V_2 -> V_81 != - 1 ) )
return V_2 -> V_81 ;
V_75 = F_53 ( V_2 -> V_5 + V_12 ) ;
ASSERT ( V_75 == - 1 || V_75 >= 16 ) ;
return V_75 ;
}
static inline void F_70 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( ! F_13 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_65 ( V_9 -> V_11 . V_76 ) )
V_77 -> V_79 ( V_9 -> V_24 ,
F_68 ( V_2 ) ) ;
else {
-- V_2 -> V_80 ;
F_67 ( V_2 -> V_80 < 0 ) ;
V_2 -> V_81 = - 1 ;
}
}
int F_71 ( struct V_8 * V_9 )
{
return F_63 ( V_9 -> V_11 . V_2 ) ;
}
int F_72 ( struct V_8 * V_9 , struct V_82 * V_83 ,
struct V_84 * V_84 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_73 ( V_2 , V_83 -> V_85 , V_83 -> V_10 ,
V_83 -> V_86 , V_83 -> V_87 , V_84 ) ;
}
static int F_74 ( struct V_8 * V_9 , T_3 V_4 )
{
return F_75 ( V_9 -> V_24 , & V_9 -> V_11 . V_88 . V_89 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_76 ( struct V_8 * V_9 , T_3 * V_4 )
{
return F_77 ( V_9 -> V_24 , & V_9 -> V_11 . V_88 . V_89 , V_4 ,
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
static void F_85 ( struct V_1 * V_2 )
{
T_1 V_96 , V_97 , V_98 , V_99 ;
int V_100 ;
V_99 = F_27 ( V_2 , V_101 ) ;
V_96 = F_27 ( V_2 , V_102 ) ;
V_100 = F_68 ( V_2 ) ;
V_97 = ( V_100 != - 1 ) ? V_100 : 0 ;
if ( ( V_96 & 0xf0 ) >= ( V_97 & 0xf0 ) )
V_98 = V_96 & 0xff ;
else
V_98 = V_97 & 0xf0 ;
F_80 ( L_4 ,
V_2 , V_98 , V_100 , V_97 ) ;
if ( V_99 != V_98 ) {
F_1 ( V_2 , V_101 , V_98 ) ;
if ( V_98 < V_99 )
F_60 ( V_73 , V_2 -> V_9 ) ;
}
}
static void F_86 ( struct V_1 * V_2 , T_1 V_96 )
{
F_1 ( V_2 , V_102 , V_96 ) ;
F_85 ( V_2 ) ;
}
static bool F_87 ( struct V_1 * V_2 , T_1 V_103 )
{
if ( F_29 ( V_2 ) )
return V_103 == V_104 ;
return F_88 ( V_103 ) == V_105 ;
}
static bool F_89 ( struct V_1 * V_2 , T_1 V_103 )
{
if ( F_87 ( V_2 , V_103 ) )
return true ;
if ( F_29 ( V_2 ) )
return V_103 == F_26 ( V_2 ) ;
return V_103 == F_90 ( F_26 ( V_2 ) ) ;
}
static bool F_91 ( struct V_1 * V_2 , T_1 V_103 )
{
T_1 V_106 ;
if ( F_87 ( V_2 , V_103 ) )
return true ;
V_106 = F_27 ( V_2 , V_33 ) ;
if ( F_29 ( V_2 ) )
return ( ( V_106 >> 16 ) == ( V_103 >> 16 ) )
&& ( V_106 & V_103 & 0xffff ) != 0 ;
V_106 = F_30 ( V_106 ) ;
V_103 = F_88 ( V_103 ) ;
switch ( F_27 ( V_2 , V_35 ) ) {
case V_36 :
return ( V_106 & V_103 ) != 0 ;
case V_107 :
return ( ( V_106 >> 4 ) == ( V_103 >> 4 ) )
&& ( V_106 & V_103 & 0xf ) != 0 ;
default:
F_80 ( L_5 ,
V_2 -> V_9 -> V_108 , F_27 ( V_2 , V_35 ) ) ;
return false ;
}
}
static T_1 F_92 ( unsigned int V_17 , struct V_1 * V_109 ,
struct V_1 * V_110 )
{
bool V_111 = V_109 != NULL ;
bool V_112 = F_29 ( V_111 ? V_109 : V_110 ) ;
if ( ! V_111 && V_17 == V_105 && V_112 )
return V_104 ;
return V_112 ? V_17 : F_90 ( V_17 ) ;
}
bool F_93 ( struct V_8 * V_9 , struct V_1 * V_109 ,
int V_113 , unsigned int V_114 , int V_115 )
{
struct V_1 * V_110 = V_9 -> V_11 . V_2 ;
T_1 V_103 = F_92 ( V_114 , V_109 , V_110 ) ;
F_80 ( L_6
L_7 ,
V_110 , V_109 , V_114 , V_115 , V_113 ) ;
ASSERT ( V_110 ) ;
switch ( V_113 ) {
case V_116 :
if ( V_115 == V_117 )
return F_89 ( V_110 , V_103 ) ;
else
return F_91 ( V_110 , V_103 ) ;
case V_118 :
return V_110 == V_109 ;
case V_119 :
return true ;
case V_120 :
return V_110 != V_109 ;
default:
F_80 ( L_8 ,
V_113 ) ;
return false ;
}
}
int F_94 ( T_1 V_10 , T_1 V_121 ,
const unsigned long * V_7 , T_1 V_122 )
{
T_1 V_123 ;
int V_27 , V_124 = - 1 ;
V_123 = V_10 % V_121 ;
for ( V_27 = 0 ; V_27 <= V_123 ; V_27 ++ ) {
V_124 = F_95 ( V_7 , V_122 , V_124 + 1 ) ;
F_67 ( V_124 == V_122 ) ;
}
return V_124 ;
}
static void F_96 ( struct V_24 * V_24 )
{
if ( ! V_24 -> V_11 . V_125 ) {
V_24 -> V_11 . V_125 = true ;
F_97 ( V_126
L_9 ) ;
}
}
bool F_98 ( struct V_24 * V_24 , struct V_1 * V_127 ,
struct V_82 * V_83 , int * V_128 , struct V_84 * V_84 )
{
struct V_14 * V_15 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_129 ;
int V_27 ;
bool V_130 , V_131 ;
* V_128 = - 1 ;
if ( V_83 -> V_132 == V_118 ) {
* V_128 = F_72 ( V_127 -> V_9 , V_83 , V_84 ) ;
return true ;
}
if ( V_83 -> V_132 )
return false ;
V_131 = V_127 && F_29 ( V_127 ) ;
if ( V_83 -> V_17 == ( V_131 ? V_104 : V_105 ) )
return false ;
V_130 = true ;
F_99 () ;
V_15 = F_100 ( V_24 -> V_11 . V_38 ) ;
if ( ! V_15 ) {
V_130 = false ;
goto V_30;
}
if ( V_83 -> V_115 == V_117 ) {
if ( V_83 -> V_17 >= F_28 ( V_15 -> V_34 ) )
goto V_30;
V_129 = & V_15 -> V_34 [ V_83 -> V_17 ] ;
} else {
T_2 V_18 ;
if ( ! F_18 ( V_15 ) ) {
V_130 = false ;
goto V_30;
}
F_19 ( V_15 , V_83 -> V_17 , & V_18 , ( T_2 * ) & V_7 ) ;
if ( V_18 >= F_28 ( V_15 -> V_37 ) )
goto V_30;
V_129 = V_15 -> V_37 [ V_18 ] ;
if ( ! F_101 ( V_83 ) )
goto V_133;
if ( ! F_102 () ) {
int V_134 = - 1 ;
F_103 (i, &bitmap, 16 ) {
if ( ! V_129 [ V_27 ] )
continue;
if ( V_134 < 0 )
V_134 = V_27 ;
else if ( F_104 ( V_129 [ V_27 ] -> V_9 ,
V_129 [ V_134 ] -> V_9 ) < 0 )
V_134 = V_27 ;
}
V_7 = ( V_134 >= 0 ) ? 1 << V_134 : 0 ;
} else {
int V_124 ;
unsigned int V_121 ;
V_121 = F_105 ( V_7 ) ;
if ( V_121 == 0 )
goto V_30;
V_124 = F_94 ( V_83 -> V_10 ,
V_121 , & V_7 , 16 ) ;
if ( ! V_129 [ V_124 ] ) {
F_96 ( V_24 ) ;
goto V_30;
}
V_7 = ( V_124 >= 0 ) ? 1 << V_124 : 0 ;
}
}
V_133:
F_103 (i, &bitmap, 16 ) {
if ( ! V_129 [ V_27 ] )
continue;
if ( * V_128 < 0 )
* V_128 = 0 ;
* V_128 += F_72 ( V_129 [ V_27 ] -> V_9 , V_83 , V_84 ) ;
}
V_30:
F_106 () ;
return V_130 ;
}
bool F_107 ( struct V_24 * V_24 , struct V_82 * V_83 ,
struct V_8 * * V_135 )
{
struct V_14 * V_15 ;
bool V_130 = false ;
struct V_1 * V_129 = NULL ;
if ( V_83 -> V_132 )
return false ;
F_99 () ;
V_15 = F_100 ( V_24 -> V_11 . V_38 ) ;
if ( ! V_15 )
goto V_30;
if ( V_83 -> V_115 == V_117 ) {
if ( V_83 -> V_17 == 0xFF )
goto V_30;
if ( V_83 -> V_17 >= F_28 ( V_15 -> V_34 ) )
goto V_30;
V_129 = V_15 -> V_34 [ V_83 -> V_17 ] ;
if ( V_129 && F_25 ( V_129 -> V_9 ) )
* V_135 = V_129 -> V_9 ;
else
goto V_30;
} else {
T_2 V_18 ;
unsigned long V_7 = 1 ;
int V_27 , V_128 = 0 ;
if ( ! F_18 ( V_15 ) )
goto V_30;
F_19 ( V_15 , V_83 -> V_17 , & V_18 , ( T_2 * ) & V_7 ) ;
if ( V_18 >= F_28 ( V_15 -> V_37 ) )
goto V_30;
if ( F_102 () &&
F_101 ( V_83 ) ) {
int V_124 ;
unsigned int V_121 ;
V_121 = F_105 ( V_7 ) ;
if ( V_121 == 0 )
goto V_30;
V_124 = F_94 ( V_83 -> V_10 , V_121 ,
& V_7 , 16 ) ;
V_129 = V_15 -> V_37 [ V_18 ] [ V_124 ] ;
if ( ! V_129 ) {
F_96 ( V_24 ) ;
goto V_30;
}
* V_135 = V_129 -> V_9 ;
} else {
F_103 (i, &bitmap, 16 ) {
V_129 = V_15 -> V_37 [ V_18 ] [ V_27 ] ;
if ( ++ V_128 == 2 )
goto V_30;
}
if ( V_129 && F_25 ( V_129 -> V_9 ) )
* V_135 = V_129 -> V_9 ;
else
goto V_30;
}
}
V_130 = true ;
V_30:
F_106 () ;
return V_130 ;
}
static int F_73 ( struct V_1 * V_2 , int V_85 ,
int V_10 , int V_86 , int V_87 ,
struct V_84 * V_84 )
{
int V_75 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_108 ( V_9 -> V_108 , V_85 ,
V_87 , V_10 ) ;
switch ( V_85 ) {
case V_136 :
V_9 -> V_11 . V_137 ++ ;
case V_138 :
if ( F_65 ( V_87 && ! V_86 ) )
break;
if ( F_65 ( ! F_15 ( V_2 ) ) )
break;
V_75 = 1 ;
if ( V_84 ) {
F_82 ( V_9 -> V_108 , V_84 -> V_15 ) ;
V_84 -> V_139 [ V_9 -> V_108 ] = V_10 ;
}
if ( F_2 ( V_10 , V_2 -> V_5 + V_140 ) != ! ! V_87 ) {
if ( V_87 )
F_7 ( V_10 , V_2 -> V_5 + V_140 ) ;
else
F_9 ( V_10 , V_2 -> V_5 + V_140 ) ;
}
if ( V_9 -> V_11 . V_76 )
V_77 -> V_141 ( V_9 , V_10 ) ;
else {
F_61 ( V_10 , V_2 ) ;
F_60 ( V_73 , V_9 ) ;
F_109 ( V_9 ) ;
}
break;
case V_142 :
V_75 = 1 ;
V_9 -> V_11 . V_143 . V_144 = 1 ;
F_60 ( V_73 , V_9 ) ;
F_109 ( V_9 ) ;
break;
case V_145 :
V_75 = 1 ;
F_60 ( V_146 , V_9 ) ;
F_109 ( V_9 ) ;
break;
case V_58 :
V_75 = 1 ;
F_110 ( V_9 ) ;
F_109 ( V_9 ) ;
break;
case V_147 :
if ( ! V_87 || V_86 ) {
V_75 = 1 ;
V_2 -> V_148 = ( 1UL << V_149 ) ;
F_111 () ;
F_60 ( V_73 , V_9 ) ;
F_109 ( V_9 ) ;
} else {
F_80 ( L_10 ,
V_9 -> V_108 ) ;
}
break;
case V_150 :
F_80 ( L_11 ,
V_9 -> V_108 , V_10 ) ;
V_75 = 1 ;
V_2 -> V_151 = V_10 ;
F_111 () ;
F_8 ( V_152 , & V_2 -> V_148 ) ;
F_60 ( V_73 , V_9 ) ;
F_109 ( V_9 ) ;
break;
case V_153 :
break;
default:
F_97 ( V_154 L_12 ,
V_85 ) ;
break;
}
return V_75 ;
}
int F_104 ( struct V_8 * V_155 , struct V_8 * V_156 )
{
return V_155 -> V_11 . V_137 - V_156 -> V_11 . V_137 ;
}
static bool F_112 ( struct V_1 * V_2 , int V_10 )
{
return F_3 ( V_10 , V_2 -> V_9 -> V_11 . V_157 ) ;
}
static void F_113 ( struct V_1 * V_2 , int V_10 )
{
int V_158 ;
if ( ! F_112 ( V_2 , V_10 ) )
return;
if ( F_114 ( V_2 -> V_9 -> V_24 ) ) {
V_2 -> V_9 -> V_11 . V_159 = V_10 ;
F_60 ( V_160 , V_2 -> V_9 ) ;
return;
}
if ( F_2 ( V_10 , V_2 -> V_5 + V_140 ) )
V_158 = V_161 ;
else
V_158 = V_162 ;
F_115 ( V_2 -> V_9 , V_10 , V_158 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
int V_10 = F_68 ( V_2 ) ;
F_117 ( V_2 , V_10 ) ;
if ( V_10 == - 1 )
return V_10 ;
F_70 ( V_10 , V_2 ) ;
F_85 ( V_2 ) ;
if ( F_3 ( V_10 , F_118 ( V_2 -> V_9 ) -> V_163 ) )
F_119 ( V_2 -> V_9 , V_10 ) ;
F_113 ( V_2 , V_10 ) ;
F_60 ( V_73 , V_2 -> V_9 ) ;
return V_10 ;
}
void F_120 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_117 ( V_2 , V_10 ) ;
F_113 ( V_2 , V_10 ) ;
F_60 ( V_73 , V_2 -> V_9 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_164 = F_27 ( V_2 , V_165 ) ;
T_1 V_166 = F_27 ( V_2 , V_167 ) ;
struct V_82 V_83 ;
V_83 . V_10 = V_164 & V_50 ;
V_83 . V_85 = V_164 & V_57 ;
V_83 . V_115 = V_164 & V_168 ;
V_83 . V_86 = ( V_164 & V_169 ) != 0 ;
V_83 . V_87 = V_164 & V_170 ;
V_83 . V_132 = V_164 & V_171 ;
V_83 . V_172 = false ;
if ( F_29 ( V_2 ) )
V_83 . V_17 = V_166 ;
else
V_83 . V_17 = F_88 ( V_166 ) ;
F_122 ( V_164 , V_83 . V_17 ) ;
F_80 ( L_13
L_14
L_15
L_16 ,
V_166 , V_164 , V_83 . V_132 , V_83 . V_17 ,
V_83 . V_87 , V_83 . V_86 , V_83 . V_115 , V_83 . V_85 ,
V_83 . V_10 , V_83 . V_172 ) ;
F_123 ( V_2 -> V_9 -> V_24 , V_2 , & V_83 , NULL ) ;
}
static T_1 F_124 ( struct V_1 * V_2 )
{
T_4 V_173 ;
T_5 V_174 ;
T_1 V_175 ;
ASSERT ( V_2 != NULL ) ;
if ( F_27 ( V_2 , V_176 ) == 0 ||
V_2 -> V_51 . V_177 == 0 )
return 0 ;
V_173 = F_125 ( & V_2 -> V_51 . V_178 ) ;
if ( F_126 ( V_173 ) < 0 )
V_173 = F_127 ( 0 , 0 ) ;
V_174 = F_128 ( F_126 ( V_173 ) , V_2 -> V_51 . V_177 ) ;
V_175 = F_129 ( V_174 ,
( V_179 * V_2 -> V_180 ) ) ;
return V_175 ;
}
static void F_130 ( struct V_1 * V_2 , bool V_181 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_182 * V_183 = V_9 -> V_183 ;
F_60 ( V_184 , V_9 ) ;
V_183 -> V_185 . V_186 = F_131 ( V_9 ) ;
V_183 -> V_185 . V_187 = V_181 ;
}
static inline void F_132 ( struct V_1 * V_2 , bool V_181 )
{
if ( V_2 -> V_9 -> V_11 . V_188 )
F_130 ( V_2 , V_181 ) ;
}
static T_1 F_133 ( struct V_1 * V_2 , unsigned int V_189 )
{
T_1 V_4 = 0 ;
if ( V_189 >= V_190 )
return 0 ;
switch ( V_189 ) {
case V_47 :
if ( F_29 ( V_2 ) )
V_4 = F_26 ( V_2 ) ;
else
V_4 = F_26 ( V_2 ) << 24 ;
break;
case V_191 :
F_80 ( L_17 ) ;
break;
case V_192 :
if ( F_48 ( V_2 ) )
return 0 ;
V_4 = F_124 ( V_2 ) ;
break;
case V_101 :
F_85 ( V_2 ) ;
V_4 = F_27 ( V_2 , V_189 ) ;
break;
case V_102 :
F_132 ( V_2 , false ) ;
default:
V_4 = F_27 ( V_2 , V_189 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_134 ( struct V_193 * V_194 )
{
return F_135 ( V_194 , struct V_1 , V_194 ) ;
}
static int F_136 ( struct V_1 * V_2 , T_1 V_189 , int V_195 ,
void * V_89 )
{
unsigned char V_196 = V_189 & 0xf ;
T_1 V_75 ;
static const T_6 V_197 = 0x43ff01ffffffe70cULL ;
if ( ( V_196 + V_195 ) > 4 ) {
F_80 ( L_18 ,
V_189 , V_195 ) ;
return 1 ;
}
if ( V_189 > 0x3f0 || ! ( V_197 & ( 1ULL << ( V_189 >> 4 ) ) ) ) {
F_80 ( L_19 ,
V_189 ) ;
return 1 ;
}
V_75 = F_133 ( V_2 , V_189 & ~ 0xf ) ;
F_137 ( V_189 , V_75 ) ;
switch ( V_195 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_89 , ( char * ) & V_75 + V_196 , V_195 ) ;
break;
default:
F_97 ( V_154 L_20
L_21 , V_195 ) ;
break;
}
return 0 ;
}
static int F_138 ( struct V_1 * V_2 , T_7 V_198 )
{
return F_17 ( V_2 ) &&
V_198 >= V_2 -> V_199 &&
V_198 < V_2 -> V_199 + V_190 ;
}
static int F_139 ( struct V_8 * V_9 , struct V_193 * V_200 ,
T_7 V_201 , int V_195 , void * V_89 )
{
struct V_1 * V_2 = F_134 ( V_200 ) ;
T_1 V_189 = V_201 - V_2 -> V_199 ;
if ( ! F_138 ( V_2 , V_201 ) )
return - V_202 ;
F_136 ( V_2 , V_189 , V_195 , V_89 ) ;
return 0 ;
}
static void F_140 ( struct V_1 * V_2 )
{
T_1 V_203 , V_204 , V_205 ;
V_205 = F_27 ( V_2 , V_206 ) ;
V_203 = V_205 & 0xf ;
V_204 = ( ( V_203 & 0x3 ) | ( ( V_203 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_180 = 0x1 << ( V_204 & 0x7 ) ;
F_80 ( L_22 ,
V_2 -> V_180 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
T_1 V_52 = F_27 ( V_2 , V_207 ) &
V_2 -> V_51 . V_208 ;
if ( V_2 -> V_51 . V_52 != V_52 ) {
V_2 -> V_51 . V_52 = V_52 ;
F_142 ( & V_2 -> V_51 . V_178 ) ;
}
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_209 * V_210 = & V_9 -> V_211 ;
struct V_212 * V_213 = & V_2 -> V_51 ;
if ( F_144 ( & V_2 -> V_51 . V_214 ) )
return;
F_145 ( & V_2 -> V_51 . V_214 ) ;
F_146 ( V_9 ) ;
if ( F_147 ( V_210 ) )
F_148 ( V_210 ) ;
if ( F_48 ( V_2 ) )
V_213 -> V_215 = V_213 -> V_216 ;
}
static bool F_149 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = F_27 ( V_2 , V_207 ) ;
if ( F_17 ( V_2 ) ) {
int V_6 = V_67 & V_50 ;
void * V_7 = V_2 -> V_5 + V_12 ;
if ( V_9 -> V_11 . V_76 )
V_7 = V_2 -> V_5 + V_13 ;
if ( F_2 ( V_6 , V_7 ) )
return true ;
}
return false ;
}
void F_150 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_6 V_217 , V_218 ;
if ( ! F_51 ( V_9 ) )
return;
if ( V_2 -> V_51 . V_215 == 0 )
return;
if ( ! F_149 ( V_9 ) )
return;
V_218 = V_2 -> V_51 . V_215 ;
V_2 -> V_51 . V_215 = 0 ;
V_217 = F_151 ( V_9 , F_152 () ) ;
F_153 ( V_9 -> V_108 , V_217 - V_218 ) ;
if ( V_217 < V_218 )
F_154 ( V_218 - V_217 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
T_4 V_219 ;
F_156 ( & V_2 -> V_51 . V_214 , 0 ) ;
if ( F_47 ( V_2 ) || F_46 ( V_2 ) ) {
V_219 = V_2 -> V_51 . V_178 . V_220 -> V_221 () ;
V_2 -> V_51 . V_177 = ( T_6 ) F_27 ( V_2 , V_176 )
* V_179 * V_2 -> V_180 ;
if ( ! V_2 -> V_51 . V_177 )
return;
if ( F_47 ( V_2 ) ) {
T_5 V_222 = V_223 * 1000LL ;
if ( V_2 -> V_51 . V_177 < V_222 ) {
F_157 (
L_23
L_24 ,
V_2 -> V_9 -> V_108 ,
V_2 -> V_51 . V_177 , V_222 ) ;
V_2 -> V_51 . V_177 = V_222 ;
}
}
F_158 ( & V_2 -> V_51 . V_178 ,
F_159 ( V_219 , V_2 -> V_51 . V_177 ) ,
V_224 ) ;
F_80 ( L_25 V_225 L_26
V_226 L_27
L_28
L_29 V_226 L_30 , V_227 ,
V_179 , F_126 ( V_219 ) ,
F_27 ( V_2 , V_176 ) ,
V_2 -> V_51 . V_177 ,
F_126 ( F_159 ( V_219 ,
V_2 -> V_51 . V_177 ) ) ) ;
} else if ( F_48 ( V_2 ) ) {
T_6 V_217 , V_216 = V_2 -> V_51 . V_216 ;
T_6 V_174 = 0 ;
T_4 V_228 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_229 = V_9 -> V_11 . V_230 ;
unsigned long V_231 ;
if ( F_65 ( ! V_216 || ! V_229 ) )
return;
F_160 ( V_231 ) ;
V_219 = V_2 -> V_51 . V_178 . V_220 -> V_221 () ;
V_217 = F_151 ( V_9 , F_152 () ) ;
if ( F_69 ( V_216 > V_217 ) ) {
V_174 = ( V_216 - V_217 ) * 1000000ULL ;
F_161 ( V_174 , V_229 ) ;
V_228 = F_159 ( V_219 , V_174 ) ;
V_228 = F_162 ( V_228 , V_232 ) ;
F_158 ( & V_2 -> V_51 . V_178 ,
V_228 , V_224 ) ;
} else
F_143 ( V_2 ) ;
F_163 ( V_231 ) ;
}
}
static void F_164 ( struct V_1 * V_2 , T_1 V_233 )
{
bool V_234 = F_49 ( V_233 ) ;
if ( V_2 -> V_234 != V_234 ) {
V_2 -> V_234 = V_234 ;
if ( V_234 ) {
F_80 ( L_31
L_32 , V_2 -> V_9 -> V_108 ) ;
F_145 ( & V_2 -> V_9 -> V_24 -> V_11 . V_235 ) ;
} else
F_165 ( & V_2 -> V_9 -> V_24 -> V_11 . V_235 ) ;
}
}
static int F_166 ( struct V_1 * V_2 , T_1 V_67 , T_1 V_4 )
{
int V_130 = 0 ;
F_167 ( V_67 , V_4 ) ;
switch ( V_67 ) {
case V_47 :
if ( ! F_29 ( V_2 ) )
F_41 ( V_2 , V_4 >> 24 ) ;
else
V_130 = 1 ;
break;
case V_102 :
F_132 ( V_2 , true ) ;
F_86 ( V_2 , V_4 & 0xff ) ;
break;
case V_236 :
F_116 ( V_2 ) ;
break;
case V_33 :
if ( ! F_29 ( V_2 ) )
F_42 ( V_2 , V_4 & V_237 ) ;
else
V_130 = 1 ;
break;
case V_35 :
if ( ! F_29 ( V_2 ) ) {
F_1 ( V_2 , V_35 , V_4 | 0x0FFFFFFF ) ;
F_21 ( V_2 -> V_9 -> V_24 ) ;
} else
V_130 = 1 ;
break;
case V_42 : {
T_1 V_238 = 0x3ff ;
if ( F_27 ( V_2 , V_66 ) & V_65 )
V_238 |= V_239 ;
F_38 ( V_2 , V_4 & V_238 ) ;
if ( ! ( V_4 & V_41 ) ) {
int V_27 ;
T_1 V_56 ;
for ( V_27 = 0 ; V_27 < V_240 ; V_27 ++ ) {
V_56 = F_27 ( V_2 ,
V_207 + 0x10 * V_27 ) ;
F_1 ( V_2 , V_207 + 0x10 * V_27 ,
V_56 | V_49 ) ;
}
F_141 ( V_2 ) ;
F_156 ( & V_2 -> V_51 . V_214 , 0 ) ;
}
break;
}
case V_165 :
F_1 ( V_2 , V_165 , V_4 & ~ ( 1 << 12 ) ) ;
F_121 ( V_2 ) ;
break;
case V_167 :
if ( ! F_29 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_167 , V_4 ) ;
break;
case V_241 :
F_164 ( V_2 , V_4 ) ;
case V_242 :
case V_243 :
case V_244 :
case V_245 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= V_246 [ ( V_67 - V_207 ) >> 4 ] ;
F_1 ( V_2 , V_67 , V_4 ) ;
break;
case V_207 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= ( V_246 [ 0 ] | V_2 -> V_51 . V_208 ) ;
F_1 ( V_2 , V_207 , V_4 ) ;
F_141 ( V_2 ) ;
break;
case V_176 :
if ( F_48 ( V_2 ) )
break;
F_142 ( & V_2 -> V_51 . V_178 ) ;
F_1 ( V_2 , V_176 , V_4 ) ;
F_155 ( V_2 ) ;
break;
case V_206 :
if ( V_4 & 4 )
F_80 ( L_33 , V_4 ) ;
F_1 ( V_2 , V_206 , V_4 ) ;
F_140 ( V_2 ) ;
break;
case V_247 :
if ( F_29 ( V_2 ) && V_4 != 0 ) {
F_80 ( L_34 , V_4 ) ;
V_130 = 1 ;
}
break;
case V_248 :
if ( F_29 ( V_2 ) ) {
F_166 ( V_2 , V_165 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_130 = 1 ;
break;
default:
V_130 = 1 ;
break;
}
if ( V_130 )
F_80 ( L_35 , V_67 ) ;
return V_130 ;
}
static int F_168 ( struct V_8 * V_9 , struct V_193 * V_200 ,
T_7 V_201 , int V_195 , const void * V_89 )
{
struct V_1 * V_2 = F_134 ( V_200 ) ;
unsigned int V_189 = V_201 - V_2 -> V_199 ;
T_1 V_4 ;
if ( ! F_138 ( V_2 , V_201 ) )
return - V_202 ;
if ( V_195 != 4 || ( V_189 & 0xf ) ) {
F_80 ( L_36 , V_195 , ( long ) V_201 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_89 ;
if ( V_189 != V_236 )
F_80 ( L_37
L_38 , V_227 , V_189 , V_195 , V_4 ) ;
F_166 ( V_2 , V_189 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_169 ( struct V_8 * V_9 )
{
F_166 ( V_9 -> V_11 . V_2 , V_236 , 0 ) ;
}
void F_170 ( struct V_8 * V_9 , T_1 V_189 )
{
T_1 V_4 = 0 ;
V_189 &= 0xff0 ;
F_136 ( V_9 -> V_11 . V_2 , V_189 , 4 , & V_4 ) ;
F_166 ( V_9 -> V_11 . V_2 , V_189 , V_4 ) ;
}
void F_171 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_9 -> V_11 . V_2 )
return;
F_142 ( & V_2 -> V_51 . V_178 ) ;
if ( ! ( V_9 -> V_11 . V_249 & V_250 ) )
F_39 ( & V_251 ) ;
if ( ! V_2 -> V_43 )
F_39 ( & V_44 ) ;
if ( V_2 -> V_5 )
F_172 ( ( unsigned long ) V_2 -> V_5 ) ;
F_173 ( V_2 ) ;
}
T_6 F_174 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return 0 ;
return V_2 -> V_51 . V_216 ;
}
void F_175 ( struct V_8 * V_9 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return;
F_142 ( & V_2 -> V_51 . V_178 ) ;
V_2 -> V_51 . V_216 = V_89 ;
F_155 ( V_2 ) ;
}
void F_176 ( struct V_8 * V_9 , unsigned long V_252 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_86 ( V_2 , ( ( V_252 & 0x0f ) << 4 )
| ( F_27 ( V_2 , V_102 ) & 4 ) ) ;
}
T_6 F_177 ( struct V_8 * V_9 )
{
T_6 V_96 ;
V_96 = ( T_6 ) F_27 ( V_9 -> V_11 . V_2 , V_102 ) ;
return ( V_96 & 0xf0 ) >> 4 ;
}
void F_178 ( struct V_8 * V_9 , T_6 V_253 )
{
T_6 V_254 = V_9 -> V_11 . V_249 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_2 ) {
V_253 |= V_255 ;
V_9 -> V_11 . V_249 = V_253 ;
return;
}
V_9 -> V_11 . V_249 = V_253 ;
if ( ( V_254 ^ V_253 ) & V_250 ) {
if ( V_253 & V_250 )
F_39 ( & V_251 ) ;
else
F_40 ( & V_251 . V_45 ) ;
F_21 ( V_9 -> V_24 ) ;
}
if ( ( V_254 ^ V_253 ) & V_256 ) {
if ( V_253 & V_256 ) {
F_43 ( V_2 , V_9 -> V_108 ) ;
V_77 -> V_257 ( V_9 , true ) ;
} else
V_77 -> V_257 ( V_9 , false ) ;
}
V_2 -> V_199 = V_2 -> V_9 -> V_11 . V_249 &
V_258 ;
if ( ( V_253 & V_250 ) &&
V_2 -> V_199 != V_259 )
F_179 ( L_39 ) ;
F_80 ( L_40 V_226 L_41
L_42 , V_2 -> V_9 -> V_11 . V_249 , V_2 -> V_199 ) ;
}
void F_180 ( struct V_8 * V_9 , bool V_260 )
{
struct V_1 * V_2 ;
int V_27 ;
F_80 ( L_43 , V_227 ) ;
ASSERT ( V_9 ) ;
V_2 = V_9 -> V_11 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_142 ( & V_2 -> V_51 . V_178 ) ;
if ( ! V_260 )
F_41 ( V_2 , V_9 -> V_108 ) ;
F_50 ( V_2 -> V_9 ) ;
for ( V_27 = 0 ; V_27 < V_240 ; V_27 ++ )
F_1 ( V_2 , V_207 + 0x10 * V_27 , V_49 ) ;
F_141 ( V_2 ) ;
if ( F_181 ( V_9 -> V_24 , V_261 ) )
F_1 ( V_2 , V_241 ,
F_182 ( 0 , V_262 ) ) ;
F_164 ( V_2 , F_27 ( V_2 , V_241 ) ) ;
F_1 ( V_2 , V_35 , 0xffffffffU ) ;
F_38 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_102 , 0 ) ;
if ( ! F_29 ( V_2 ) )
F_42 ( V_2 , 0 ) ;
F_1 ( V_2 , V_247 , 0 ) ;
F_1 ( V_2 , V_165 , 0 ) ;
F_1 ( V_2 , V_167 , 0 ) ;
F_1 ( V_2 , V_206 , 0 ) ;
F_1 ( V_2 , V_176 , 0 ) ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
F_1 ( V_2 , V_13 + 0x10 * V_27 , 0 ) ;
F_1 ( V_2 , V_12 + 0x10 * V_27 , 0 ) ;
F_1 ( V_2 , V_140 + 0x10 * V_27 , 0 ) ;
}
V_2 -> V_74 = V_9 -> V_11 . V_76 ;
V_2 -> V_80 = V_9 -> V_11 . V_76 ? 1 : 0 ;
V_2 -> V_81 = - 1 ;
F_140 ( V_2 ) ;
F_156 ( & V_2 -> V_51 . V_214 , 0 ) ;
if ( F_183 ( V_9 ) )
F_178 ( V_9 ,
V_9 -> V_11 . V_249 | V_255 ) ;
V_9 -> V_11 . V_88 . V_90 = 0 ;
F_85 ( V_2 ) ;
V_9 -> V_11 . V_137 = 0 ;
V_9 -> V_11 . V_94 = 0 ;
F_80 ( L_44
L_45 V_226 L_46 , V_227 ,
V_9 , F_26 ( V_2 ) ,
V_9 -> V_11 . V_249 , V_2 -> V_199 ) ;
}
static bool F_184 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ) ;
}
int F_185 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_15 ( V_2 ) && F_44 ( V_2 , V_207 ) )
return F_144 ( & V_2 -> V_51 . V_214 ) ;
return 0 ;
}
int F_186 ( struct V_1 * V_2 , int V_48 )
{
T_1 V_67 = F_27 ( V_2 , V_48 ) ;
int V_10 , V_16 , V_87 ;
if ( F_17 ( V_2 ) && ! ( V_67 & V_49 ) ) {
V_10 = V_67 & V_50 ;
V_16 = V_67 & V_57 ;
V_87 = V_67 & V_263 ;
return F_73 ( V_2 , V_16 , V_10 , 1 , V_87 ,
NULL ) ;
}
return 0 ;
}
void F_187 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_2 )
F_186 ( V_2 , V_241 ) ;
}
static enum V_264 F_188 ( struct V_265 * V_89 )
{
struct V_212 * V_213 = F_135 ( V_89 , struct V_212 , V_178 ) ;
struct V_1 * V_2 = F_135 ( V_213 , struct V_1 , V_51 ) ;
F_143 ( V_2 ) ;
if ( F_184 ( V_2 ) ) {
F_189 ( & V_213 -> V_178 , V_213 -> V_177 ) ;
return V_266 ;
} else
return V_267 ;
}
int F_190 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
ASSERT ( V_9 != NULL ) ;
F_80 ( L_47 , V_9 -> V_108 ) ;
V_2 = F_22 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
goto V_268;
V_9 -> V_11 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_191 ( V_28 ) ;
if ( ! V_2 -> V_5 ) {
F_97 ( V_154 L_48 ,
V_9 -> V_108 ) ;
goto V_269;
}
V_2 -> V_9 = V_9 ;
F_192 ( & V_2 -> V_51 . V_178 , V_270 ,
V_224 ) ;
V_2 -> V_51 . V_178 . V_271 = F_188 ;
V_9 -> V_11 . V_249 = V_250 ;
F_178 ( V_9 ,
V_259 | V_250 ) ;
F_40 ( & V_44 . V_45 ) ;
F_180 ( V_9 , false ) ;
F_193 ( & V_2 -> V_194 , & V_272 ) ;
return 0 ;
V_269:
F_173 ( V_2 ) ;
V_268:
return - V_273 ;
}
int F_194 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_274 ;
if ( ! F_15 ( V_2 ) )
return - 1 ;
F_85 ( V_2 ) ;
V_274 = F_63 ( V_2 ) ;
if ( ( V_274 == - 1 ) ||
( ( V_274 & 0xF0 ) <= F_27 ( V_2 , V_101 ) ) )
return - 1 ;
return V_274 ;
}
int F_195 ( struct V_8 * V_9 )
{
T_1 V_275 = F_27 ( V_9 -> V_11 . V_2 , V_241 ) ;
int V_128 = 0 ;
if ( ! F_17 ( V_9 -> V_11 . V_2 ) )
V_128 = 1 ;
if ( ( V_275 & V_49 ) == 0 &&
F_196 ( V_275 ) == V_262 )
V_128 = 1 ;
return V_128 ;
}
void F_197 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_144 ( & V_2 -> V_51 . V_214 ) > 0 ) {
F_186 ( V_2 , V_207 ) ;
if ( F_48 ( V_2 ) )
V_2 -> V_51 . V_216 = 0 ;
F_156 ( & V_2 -> V_51 . V_214 , 0 ) ;
}
}
int F_198 ( struct V_8 * V_9 )
{
int V_10 = F_194 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_10 == - 1 )
return - 1 ;
F_66 ( V_10 , V_2 ) ;
F_85 ( V_2 ) ;
F_64 ( V_10 , V_2 ) ;
if ( F_3 ( V_10 , F_118 ( V_9 ) -> V_276 ) ) {
F_70 ( V_10 , V_2 ) ;
F_85 ( V_2 ) ;
}
return V_10 ;
}
void F_199 ( struct V_8 * V_9 ,
struct V_277 * V_278 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_178 ( V_9 , V_9 -> V_11 . V_249 ) ;
F_38 ( V_2 , * ( ( T_1 * ) ( V_278 -> V_5 + V_42 ) ) ) ;
memcpy ( V_9 -> V_11 . V_2 -> V_5 , V_278 -> V_5 , sizeof *V_278 ) ;
F_41 ( V_2 , F_26 ( V_2 ) ) ;
F_50 ( V_9 ) ;
F_85 ( V_2 ) ;
F_142 ( & V_2 -> V_51 . V_178 ) ;
F_141 ( V_2 ) ;
F_164 ( V_2 , F_27 ( V_2 , V_241 ) ) ;
F_140 ( V_2 ) ;
F_155 ( V_2 ) ;
V_2 -> V_74 = true ;
V_2 -> V_80 = V_9 -> V_11 . V_76 ?
1 : F_55 ( V_2 -> V_5 + V_12 ) ;
V_2 -> V_81 = - 1 ;
if ( V_9 -> V_11 . V_76 ) {
V_77 -> V_279 ( V_9 ,
F_63 ( V_2 ) ) ;
V_77 -> V_79 ( V_9 -> V_24 ,
F_68 ( V_2 ) ) ;
}
F_60 ( V_73 , V_9 ) ;
if ( F_200 ( V_9 -> V_24 ) )
F_201 ( V_9 ) ;
V_9 -> V_11 . V_137 = 0 ;
}
void F_202 ( struct V_8 * V_9 )
{
struct V_265 * V_178 ;
if ( ! F_51 ( V_9 ) )
return;
V_178 = & V_9 -> V_11 . V_2 -> V_51 . V_178 ;
if ( F_142 ( V_178 ) )
F_203 ( V_178 , V_224 ) ;
}
static void F_204 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
bool V_214 ;
int V_10 ;
F_67 ( ! F_78 ( V_9 ) ) ;
V_214 = F_79 ( V_9 ) ;
F_83 ( V_9 ) ;
if ( V_214 )
return;
V_10 = F_116 ( V_2 ) ;
F_205 ( V_2 , V_10 ) ;
}
void F_206 ( struct V_8 * V_9 )
{
T_1 V_89 ;
if ( F_3 ( V_93 , & V_9 -> V_11 . V_94 ) )
F_204 ( V_9 , V_9 -> V_11 . V_2 ) ;
if ( ! F_3 ( V_280 , & V_9 -> V_11 . V_94 ) )
return;
if ( F_77 ( V_9 -> V_24 , & V_9 -> V_11 . V_2 -> V_281 , & V_89 ,
sizeof( T_1 ) ) )
return;
F_86 ( V_9 -> V_11 . V_2 , V_89 & 0xff ) ;
}
static void F_207 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( ! F_78 ( V_9 ) ||
V_2 -> V_74 ||
V_2 -> V_81 == - 1 ||
F_112 ( V_2 , V_2 -> V_81 ) ) {
return;
}
F_81 ( V_2 -> V_9 ) ;
}
void F_208 ( struct V_8 * V_9 )
{
T_1 V_89 , V_96 ;
int V_282 , V_283 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_207 ( V_9 , V_2 ) ;
if ( ! F_3 ( V_280 , & V_9 -> V_11 . V_94 ) )
return;
V_96 = F_27 ( V_2 , V_102 ) & 0xff ;
V_282 = F_63 ( V_2 ) ;
if ( V_282 < 0 )
V_282 = 0 ;
V_283 = F_68 ( V_2 ) ;
if ( V_283 < 0 )
V_283 = 0 ;
V_89 = ( V_96 & 0xff ) | ( ( V_283 & 0xf0 ) << 8 ) | ( V_282 << 24 ) ;
F_75 ( V_9 -> V_24 , & V_9 -> V_11 . V_2 -> V_281 , & V_89 ,
sizeof( T_1 ) ) ;
}
int F_209 ( struct V_8 * V_9 , T_7 V_284 )
{
if ( V_284 ) {
if ( F_210 ( V_9 -> V_24 ,
& V_9 -> V_11 . V_2 -> V_281 ,
V_284 , sizeof( T_1 ) ) )
return - V_285 ;
F_82 ( V_280 , & V_9 -> V_11 . V_94 ) ;
} else {
F_84 ( V_280 , & V_9 -> V_11 . V_94 ) ;
}
V_9 -> V_11 . V_2 -> V_284 = V_284 ;
return 0 ;
}
int F_211 ( struct V_8 * V_9 , T_1 V_286 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_286 - V_287 ) << 4 ;
if ( ! F_51 ( V_9 ) || ! F_29 ( V_2 ) )
return 1 ;
if ( V_67 == V_167 )
return 1 ;
if ( V_67 == V_165 )
F_166 ( V_2 , V_167 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_166 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_212 ( struct V_8 * V_9 , T_1 V_286 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_286 - V_287 ) << 4 , V_288 , V_289 = 0 ;
if ( ! F_51 ( V_9 ) || ! F_29 ( V_2 ) )
return 1 ;
if ( V_67 == V_35 || V_67 == V_167 ) {
F_80 ( L_49 ,
V_67 ) ;
return 1 ;
}
if ( F_136 ( V_2 , V_67 , 4 , & V_288 ) )
return 1 ;
if ( V_67 == V_165 )
F_136 ( V_2 , V_167 , 4 , & V_289 ) ;
* V_89 = ( ( ( T_6 ) V_289 ) << 32 ) | V_288 ;
return 0 ;
}
int F_213 ( struct V_8 * V_9 , T_1 V_67 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return 1 ;
if ( V_67 == V_165 )
F_166 ( V_2 , V_167 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_166 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_214 ( struct V_8 * V_9 , T_1 V_67 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_288 , V_289 = 0 ;
if ( ! F_51 ( V_9 ) )
return 1 ;
if ( F_136 ( V_2 , V_67 , 4 , & V_288 ) )
return 1 ;
if ( V_67 == V_165 )
F_136 ( V_2 , V_167 , 4 , & V_289 ) ;
* V_89 = ( ( ( T_6 ) V_289 ) << 32 ) | V_288 ;
return 0 ;
}
int F_215 ( struct V_8 * V_9 , T_6 V_89 )
{
T_6 V_198 = V_89 & ~ V_91 ;
if ( ! F_216 ( V_198 , 4 ) )
return 1 ;
V_9 -> V_11 . V_88 . V_90 = V_89 ;
if ( ! F_78 ( V_9 ) )
return 0 ;
return F_210 ( V_9 -> V_24 , & V_9 -> V_11 . V_88 . V_89 ,
V_198 , sizeof( T_3 ) ) ;
}
void F_217 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_3 V_151 ;
unsigned long V_290 ;
if ( ! F_51 ( V_9 ) || ! V_2 -> V_148 )
return;
if ( F_218 ( V_9 ) ) {
F_219 ( V_9 -> V_11 . V_291 == V_292 ) ;
if ( F_3 ( V_152 , & V_2 -> V_148 ) )
F_10 ( V_152 , & V_2 -> V_148 ) ;
return;
}
V_290 = F_58 ( & V_2 -> V_148 , 0 ) ;
if ( F_3 ( V_149 , & V_290 ) ) {
F_180 ( V_9 , true ) ;
F_220 ( V_9 , true ) ;
if ( F_183 ( V_2 -> V_9 ) )
V_9 -> V_11 . V_291 = V_293 ;
else
V_9 -> V_11 . V_291 = V_292 ;
}
if ( F_3 ( V_152 , & V_290 ) &&
V_9 -> V_11 . V_291 == V_292 ) {
F_221 () ;
V_151 = V_2 -> V_151 ;
F_80 ( L_50 ,
V_9 -> V_108 , V_151 ) ;
F_222 ( V_9 , V_151 ) ;
V_9 -> V_11 . V_291 = V_293 ;
}
}
void F_223 ( void )
{
F_224 ( & V_251 , V_294 ) ;
F_224 ( & V_44 , V_294 ) ;
}
