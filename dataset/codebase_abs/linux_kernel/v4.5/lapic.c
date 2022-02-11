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
int V_82 ;
if ( ! F_51 ( V_9 ) )
return 0 ;
V_82 = F_63 ( V_9 -> V_11 . V_2 ) ;
return V_82 ;
}
int F_72 ( struct V_8 * V_9 , struct V_83 * V_84 ,
unsigned long * V_85 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_73 ( V_2 , V_84 -> V_86 , V_84 -> V_10 ,
V_84 -> V_87 , V_84 -> V_88 , V_85 ) ;
}
static int F_74 ( struct V_8 * V_9 , T_3 V_4 )
{
return F_75 ( V_9 -> V_24 , & V_9 -> V_11 . V_89 . V_90 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_76 ( struct V_8 * V_9 , T_3 * V_4 )
{
return F_77 ( V_9 -> V_24 , & V_9 -> V_11 . V_89 . V_90 , V_4 ,
sizeof( * V_4 ) ) ;
}
static inline bool F_78 ( struct V_8 * V_9 )
{
return V_9 -> V_11 . V_89 . V_91 & V_92 ;
}
static bool F_79 ( struct V_8 * V_9 )
{
T_3 V_4 ;
if ( F_76 ( V_9 , & V_4 ) < 0 )
F_80 ( L_1 ,
( unsigned long long ) V_9 -> V_11 . V_89 . V_91 ) ;
return V_4 & 0x1 ;
}
static void F_81 ( struct V_8 * V_9 )
{
if ( F_74 ( V_9 , V_93 ) < 0 ) {
F_80 ( L_2 ,
( unsigned long long ) V_9 -> V_11 . V_89 . V_91 ) ;
return;
}
F_82 ( V_94 , & V_9 -> V_11 . V_95 ) ;
}
static void F_83 ( struct V_8 * V_9 )
{
if ( F_74 ( V_9 , V_96 ) < 0 ) {
F_80 ( L_3 ,
( unsigned long long ) V_9 -> V_11 . V_89 . V_91 ) ;
return;
}
F_84 ( V_94 , & V_9 -> V_11 . V_95 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
T_1 V_97 , V_98 , V_99 , V_100 ;
int V_101 ;
V_100 = F_27 ( V_2 , V_102 ) ;
V_97 = F_27 ( V_2 , V_103 ) ;
V_101 = F_68 ( V_2 ) ;
V_98 = ( V_101 != - 1 ) ? V_101 : 0 ;
if ( ( V_97 & 0xf0 ) >= ( V_98 & 0xf0 ) )
V_99 = V_97 & 0xff ;
else
V_99 = V_98 & 0xf0 ;
F_80 ( L_4 ,
V_2 , V_99 , V_101 , V_98 ) ;
if ( V_100 != V_99 ) {
F_1 ( V_2 , V_102 , V_99 ) ;
if ( V_99 < V_100 )
F_60 ( V_73 , V_2 -> V_9 ) ;
}
}
static void F_86 ( struct V_1 * V_2 , T_1 V_97 )
{
F_1 ( V_2 , V_103 , V_97 ) ;
F_85 ( V_2 ) ;
}
static bool F_87 ( struct V_1 * V_2 , T_1 V_104 )
{
if ( F_29 ( V_2 ) )
return V_104 == V_105 ;
return F_88 ( V_104 ) == V_106 ;
}
static bool F_89 ( struct V_1 * V_2 , T_1 V_104 )
{
if ( F_87 ( V_2 , V_104 ) )
return true ;
if ( F_29 ( V_2 ) )
return V_104 == F_26 ( V_2 ) ;
return V_104 == F_90 ( F_26 ( V_2 ) ) ;
}
static bool F_91 ( struct V_1 * V_2 , T_1 V_104 )
{
T_1 V_107 ;
if ( F_87 ( V_2 , V_104 ) )
return true ;
V_107 = F_27 ( V_2 , V_33 ) ;
if ( F_29 ( V_2 ) )
return ( ( V_107 >> 16 ) == ( V_104 >> 16 ) )
&& ( V_107 & V_104 & 0xffff ) != 0 ;
V_107 = F_30 ( V_107 ) ;
V_104 = F_88 ( V_104 ) ;
switch ( F_27 ( V_2 , V_35 ) ) {
case V_36 :
return ( V_107 & V_104 ) != 0 ;
case V_108 :
return ( ( V_107 >> 4 ) == ( V_104 >> 4 ) )
&& ( V_107 & V_104 & 0xf ) != 0 ;
default:
F_80 ( L_5 ,
V_2 -> V_9 -> V_109 , F_27 ( V_2 , V_35 ) ) ;
return false ;
}
}
static T_1 F_92 ( unsigned int V_17 , struct V_1 * V_110 ,
struct V_1 * V_111 )
{
bool V_112 = V_110 != NULL ;
bool V_113 = F_29 ( V_112 ? V_110 : V_111 ) ;
if ( ! V_112 && V_17 == V_106 && V_113 )
return V_105 ;
return V_113 ? V_17 : F_90 ( V_17 ) ;
}
bool F_93 ( struct V_8 * V_9 , struct V_1 * V_110 ,
int V_114 , unsigned int V_115 , int V_116 )
{
struct V_1 * V_111 = V_9 -> V_11 . V_2 ;
T_1 V_104 = F_92 ( V_115 , V_110 , V_111 ) ;
F_80 ( L_6
L_7 ,
V_111 , V_110 , V_115 , V_116 , V_114 ) ;
ASSERT ( V_111 ) ;
switch ( V_114 ) {
case V_117 :
if ( V_116 == V_118 )
return F_89 ( V_111 , V_104 ) ;
else
return F_91 ( V_111 , V_104 ) ;
case V_119 :
return V_111 == V_110 ;
case V_120 :
return true ;
case V_121 :
return V_111 != V_110 ;
default:
F_80 ( L_8 ,
V_114 ) ;
return false ;
}
}
bool F_94 ( struct V_24 * V_24 , struct V_1 * V_122 ,
struct V_83 * V_84 , int * V_123 , unsigned long * V_85 )
{
struct V_14 * V_15 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_124 ;
int V_27 ;
bool V_125 , V_126 ;
* V_123 = - 1 ;
if ( V_84 -> V_127 == V_119 ) {
* V_123 = F_72 ( V_122 -> V_9 , V_84 , V_85 ) ;
return true ;
}
if ( V_84 -> V_127 )
return false ;
V_126 = V_122 && F_29 ( V_122 ) ;
if ( V_84 -> V_17 == ( V_126 ? V_105 : V_106 ) )
return false ;
V_125 = true ;
F_95 () ;
V_15 = F_96 ( V_24 -> V_11 . V_38 ) ;
if ( ! V_15 ) {
V_125 = false ;
goto V_30;
}
if ( V_84 -> V_116 == V_118 ) {
if ( V_84 -> V_17 >= F_28 ( V_15 -> V_34 ) )
goto V_30;
V_124 = & V_15 -> V_34 [ V_84 -> V_17 ] ;
} else {
T_2 V_18 ;
if ( ! F_18 ( V_15 ) ) {
V_125 = false ;
goto V_30;
}
F_19 ( V_15 , V_84 -> V_17 , & V_18 , ( T_2 * ) & V_7 ) ;
if ( V_18 >= F_28 ( V_15 -> V_37 ) )
goto V_30;
V_124 = V_15 -> V_37 [ V_18 ] ;
if ( F_97 ( V_84 ) ) {
int V_128 = - 1 ;
F_98 (i, &bitmap, 16 ) {
if ( ! V_124 [ V_27 ] )
continue;
if ( V_128 < 0 )
V_128 = V_27 ;
else if ( F_99 ( V_124 [ V_27 ] -> V_9 , V_124 [ V_128 ] -> V_9 ) < 0 )
V_128 = V_27 ;
}
V_7 = ( V_128 >= 0 ) ? 1 << V_128 : 0 ;
}
}
F_98 (i, &bitmap, 16 ) {
if ( ! V_124 [ V_27 ] )
continue;
if ( * V_123 < 0 )
* V_123 = 0 ;
* V_123 += F_72 ( V_124 [ V_27 ] -> V_9 , V_84 , V_85 ) ;
}
V_30:
F_100 () ;
return V_125 ;
}
bool F_101 ( struct V_24 * V_24 , struct V_83 * V_84 ,
struct V_8 * * V_129 )
{
struct V_14 * V_15 ;
bool V_125 = false ;
struct V_1 * V_124 = NULL ;
if ( V_84 -> V_127 )
return false ;
F_95 () ;
V_15 = F_96 ( V_24 -> V_11 . V_38 ) ;
if ( ! V_15 )
goto V_30;
if ( V_84 -> V_116 == V_118 ) {
if ( V_84 -> V_17 == 0xFF )
goto V_30;
if ( V_84 -> V_17 >= F_28 ( V_15 -> V_34 ) )
goto V_30;
V_124 = V_15 -> V_34 [ V_84 -> V_17 ] ;
if ( V_124 && F_25 ( V_124 -> V_9 ) )
* V_129 = V_124 -> V_9 ;
else
goto V_30;
} else {
T_2 V_18 ;
unsigned long V_7 = 1 ;
int V_27 , V_123 = 0 ;
if ( ! F_18 ( V_15 ) )
goto V_30;
F_19 ( V_15 , V_84 -> V_17 , & V_18 , ( T_2 * ) & V_7 ) ;
if ( V_18 >= F_28 ( V_15 -> V_37 ) )
goto V_30;
F_98 (i, &bitmap, 16 ) {
V_124 = V_15 -> V_37 [ V_18 ] [ V_27 ] ;
if ( ++ V_123 == 2 )
goto V_30;
}
if ( V_124 && F_25 ( V_124 -> V_9 ) )
* V_129 = V_124 -> V_9 ;
else
goto V_30;
}
V_125 = true ;
V_30:
F_100 () ;
return V_125 ;
}
static int F_73 ( struct V_1 * V_2 , int V_86 ,
int V_10 , int V_87 , int V_88 ,
unsigned long * V_85 )
{
int V_75 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_102 ( V_9 -> V_109 , V_86 ,
V_88 , V_10 ) ;
switch ( V_86 ) {
case V_130 :
V_9 -> V_11 . V_131 ++ ;
case V_132 :
if ( F_65 ( V_88 && ! V_87 ) )
break;
if ( F_65 ( ! F_15 ( V_2 ) ) )
break;
V_75 = 1 ;
if ( V_85 )
F_82 ( V_9 -> V_109 , V_85 ) ;
if ( F_2 ( V_10 , V_2 -> V_5 + V_133 ) != ! ! V_88 ) {
if ( V_88 )
F_7 ( V_10 , V_2 -> V_5 + V_133 ) ;
else
F_9 ( V_10 , V_2 -> V_5 + V_133 ) ;
}
if ( V_9 -> V_11 . V_76 )
V_77 -> V_134 ( V_9 , V_10 ) ;
else {
F_61 ( V_10 , V_2 ) ;
F_60 ( V_73 , V_9 ) ;
F_103 ( V_9 ) ;
}
break;
case V_135 :
V_75 = 1 ;
V_9 -> V_11 . V_136 . V_137 = 1 ;
F_60 ( V_73 , V_9 ) ;
F_103 ( V_9 ) ;
break;
case V_138 :
V_75 = 1 ;
F_60 ( V_139 , V_9 ) ;
F_103 ( V_9 ) ;
break;
case V_58 :
V_75 = 1 ;
F_104 ( V_9 ) ;
F_103 ( V_9 ) ;
break;
case V_140 :
if ( ! V_88 || V_87 ) {
V_75 = 1 ;
V_2 -> V_141 = ( 1UL << V_142 ) ;
F_105 () ;
F_60 ( V_73 , V_9 ) ;
F_103 ( V_9 ) ;
} else {
F_80 ( L_9 ,
V_9 -> V_109 ) ;
}
break;
case V_143 :
F_80 ( L_10 ,
V_9 -> V_109 , V_10 ) ;
V_75 = 1 ;
V_2 -> V_144 = V_10 ;
F_105 () ;
F_8 ( V_145 , & V_2 -> V_141 ) ;
F_60 ( V_73 , V_9 ) ;
F_103 ( V_9 ) ;
break;
case V_146 :
break;
default:
F_106 ( V_147 L_11 ,
V_86 ) ;
break;
}
return V_75 ;
}
int F_99 ( struct V_8 * V_148 , struct V_8 * V_149 )
{
return V_148 -> V_11 . V_131 - V_149 -> V_11 . V_131 ;
}
static bool F_107 ( struct V_1 * V_2 , int V_10 )
{
return F_3 ( V_10 , V_2 -> V_9 -> V_11 . V_150 ) ;
}
static void F_108 ( struct V_1 * V_2 , int V_10 )
{
int V_151 ;
if ( ! F_107 ( V_2 , V_10 ) )
return;
if ( F_109 ( V_2 -> V_9 -> V_24 ) ) {
V_2 -> V_9 -> V_11 . V_152 = V_10 ;
F_60 ( V_153 , V_2 -> V_9 ) ;
return;
}
if ( F_2 ( V_10 , V_2 -> V_5 + V_133 ) )
V_151 = V_154 ;
else
V_151 = V_155 ;
F_110 ( V_2 -> V_9 , V_10 , V_151 ) ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_10 = F_68 ( V_2 ) ;
F_112 ( V_2 , V_10 ) ;
if ( V_10 == - 1 )
return V_10 ;
F_70 ( V_10 , V_2 ) ;
F_85 ( V_2 ) ;
if ( F_3 ( V_10 , F_113 ( V_2 -> V_9 ) -> V_156 ) )
F_114 ( V_2 -> V_9 , V_10 ) ;
F_108 ( V_2 , V_10 ) ;
F_60 ( V_73 , V_2 -> V_9 ) ;
return V_10 ;
}
void F_115 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_112 ( V_2 , V_10 ) ;
F_108 ( V_2 , V_10 ) ;
F_60 ( V_73 , V_2 -> V_9 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
T_1 V_157 = F_27 ( V_2 , V_158 ) ;
T_1 V_159 = F_27 ( V_2 , V_160 ) ;
struct V_83 V_84 ;
V_84 . V_10 = V_157 & V_50 ;
V_84 . V_86 = V_157 & V_57 ;
V_84 . V_116 = V_157 & V_161 ;
V_84 . V_87 = ( V_157 & V_162 ) != 0 ;
V_84 . V_88 = V_157 & V_163 ;
V_84 . V_127 = V_157 & V_164 ;
V_84 . V_165 = false ;
if ( F_29 ( V_2 ) )
V_84 . V_17 = V_159 ;
else
V_84 . V_17 = F_88 ( V_159 ) ;
F_117 ( V_157 , V_84 . V_17 ) ;
F_80 ( L_12
L_13
L_14
L_15 ,
V_159 , V_157 , V_84 . V_127 , V_84 . V_17 ,
V_84 . V_88 , V_84 . V_87 , V_84 . V_116 , V_84 . V_86 ,
V_84 . V_10 , V_84 . V_165 ) ;
F_118 ( V_2 -> V_9 -> V_24 , V_2 , & V_84 , NULL ) ;
}
static T_1 F_119 ( struct V_1 * V_2 )
{
T_4 V_166 ;
T_5 V_167 ;
T_1 V_168 ;
ASSERT ( V_2 != NULL ) ;
if ( F_27 ( V_2 , V_169 ) == 0 ||
V_2 -> V_51 . V_170 == 0 )
return 0 ;
V_166 = F_120 ( & V_2 -> V_51 . V_171 ) ;
if ( F_121 ( V_166 ) < 0 )
V_166 = F_122 ( 0 , 0 ) ;
V_167 = F_123 ( F_121 ( V_166 ) , V_2 -> V_51 . V_170 ) ;
V_168 = F_124 ( V_167 ,
( V_172 * V_2 -> V_173 ) ) ;
return V_168 ;
}
static void F_125 ( struct V_1 * V_2 , bool V_174 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_175 * V_176 = V_9 -> V_176 ;
F_60 ( V_177 , V_9 ) ;
V_176 -> V_178 . V_179 = F_126 ( V_9 ) ;
V_176 -> V_178 . V_180 = V_174 ;
}
static inline void F_127 ( struct V_1 * V_2 , bool V_174 )
{
if ( V_2 -> V_9 -> V_11 . V_181 )
F_125 ( V_2 , V_174 ) ;
}
static T_1 F_128 ( struct V_1 * V_2 , unsigned int V_182 )
{
T_1 V_4 = 0 ;
if ( V_182 >= V_183 )
return 0 ;
switch ( V_182 ) {
case V_47 :
if ( F_29 ( V_2 ) )
V_4 = F_26 ( V_2 ) ;
else
V_4 = F_26 ( V_2 ) << 24 ;
break;
case V_184 :
F_80 ( L_16 ) ;
break;
case V_185 :
if ( F_48 ( V_2 ) )
return 0 ;
V_4 = F_119 ( V_2 ) ;
break;
case V_102 :
F_85 ( V_2 ) ;
V_4 = F_27 ( V_2 , V_182 ) ;
break;
case V_103 :
F_127 ( V_2 , false ) ;
default:
V_4 = F_27 ( V_2 , V_182 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_129 ( struct V_186 * V_187 )
{
return F_130 ( V_187 , struct V_1 , V_187 ) ;
}
static int F_131 ( struct V_1 * V_2 , T_1 V_182 , int V_188 ,
void * V_90 )
{
unsigned char V_189 = V_182 & 0xf ;
T_1 V_75 ;
static const T_6 V_190 = 0x43ff01ffffffe70cULL ;
if ( ( V_189 + V_188 ) > 4 ) {
F_80 ( L_17 ,
V_182 , V_188 ) ;
return 1 ;
}
if ( V_182 > 0x3f0 || ! ( V_190 & ( 1ULL << ( V_182 >> 4 ) ) ) ) {
F_80 ( L_18 ,
V_182 ) ;
return 1 ;
}
V_75 = F_128 ( V_2 , V_182 & ~ 0xf ) ;
F_132 ( V_182 , V_75 ) ;
switch ( V_188 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_90 , ( char * ) & V_75 + V_189 , V_188 ) ;
break;
default:
F_106 ( V_147 L_19
L_20 , V_188 ) ;
break;
}
return 0 ;
}
static int F_133 ( struct V_1 * V_2 , T_7 V_191 )
{
return F_17 ( V_2 ) &&
V_191 >= V_2 -> V_192 &&
V_191 < V_2 -> V_192 + V_183 ;
}
static int F_134 ( struct V_8 * V_9 , struct V_186 * V_193 ,
T_7 V_194 , int V_188 , void * V_90 )
{
struct V_1 * V_2 = F_129 ( V_193 ) ;
T_1 V_182 = V_194 - V_2 -> V_192 ;
if ( ! F_133 ( V_2 , V_194 ) )
return - V_195 ;
F_131 ( V_2 , V_182 , V_188 , V_90 ) ;
return 0 ;
}
static void F_135 ( struct V_1 * V_2 )
{
T_1 V_196 , V_197 , V_198 ;
V_198 = F_27 ( V_2 , V_199 ) ;
V_196 = V_198 & 0xf ;
V_197 = ( ( V_196 & 0x3 ) | ( ( V_196 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_173 = 0x1 << ( V_197 & 0x7 ) ;
F_80 ( L_21 ,
V_2 -> V_173 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
T_1 V_52 = F_27 ( V_2 , V_200 ) &
V_2 -> V_51 . V_201 ;
if ( V_2 -> V_51 . V_52 != V_52 ) {
V_2 -> V_51 . V_52 = V_52 ;
F_137 ( & V_2 -> V_51 . V_171 ) ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_8 * V_202 = & V_9 -> V_203 ;
struct V_204 * V_205 = & V_2 -> V_51 ;
if ( F_139 ( & V_2 -> V_51 . V_206 ) )
return;
F_140 ( & V_2 -> V_51 . V_206 ) ;
F_141 ( V_9 ) ;
if ( F_142 ( V_202 ) )
F_143 ( V_202 ) ;
if ( F_48 ( V_2 ) )
V_205 -> V_207 = V_205 -> V_208 ;
}
static bool F_144 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = F_27 ( V_2 , V_200 ) ;
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
void F_145 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_6 V_209 , V_210 ;
if ( ! F_51 ( V_9 ) )
return;
if ( V_2 -> V_51 . V_207 == 0 )
return;
if ( ! F_144 ( V_9 ) )
return;
V_210 = V_2 -> V_51 . V_207 ;
V_2 -> V_51 . V_207 = 0 ;
V_209 = F_146 ( V_9 , F_147 () ) ;
F_148 ( V_9 -> V_109 , V_209 - V_210 ) ;
if ( V_209 < V_210 )
F_149 ( V_210 - V_209 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
T_4 V_211 ;
F_151 ( & V_2 -> V_51 . V_206 , 0 ) ;
if ( F_47 ( V_2 ) || F_46 ( V_2 ) ) {
V_211 = V_2 -> V_51 . V_171 . V_212 -> V_213 () ;
V_2 -> V_51 . V_170 = ( T_6 ) F_27 ( V_2 , V_169 )
* V_172 * V_2 -> V_173 ;
if ( ! V_2 -> V_51 . V_170 )
return;
if ( F_47 ( V_2 ) ) {
T_5 V_214 = V_215 * 1000LL ;
if ( V_2 -> V_51 . V_170 < V_214 ) {
F_152 (
L_22
L_23 ,
V_2 -> V_9 -> V_109 ,
V_2 -> V_51 . V_170 , V_214 ) ;
V_2 -> V_51 . V_170 = V_214 ;
}
}
F_153 ( & V_2 -> V_51 . V_171 ,
F_154 ( V_211 , V_2 -> V_51 . V_170 ) ,
V_216 ) ;
F_80 ( L_24 V_217 L_25
V_218 L_26
L_27
L_28 V_218 L_29 , V_219 ,
V_172 , F_121 ( V_211 ) ,
F_27 ( V_2 , V_169 ) ,
V_2 -> V_51 . V_170 ,
F_121 ( F_154 ( V_211 ,
V_2 -> V_51 . V_170 ) ) ) ;
} else if ( F_48 ( V_2 ) ) {
T_6 V_209 , V_208 = V_2 -> V_51 . V_208 ;
T_6 V_167 = 0 ;
T_4 V_220 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_221 = V_9 -> V_11 . V_222 ;
unsigned long V_223 ;
if ( F_65 ( ! V_208 || ! V_221 ) )
return;
F_155 ( V_223 ) ;
V_211 = V_2 -> V_51 . V_171 . V_212 -> V_213 () ;
V_209 = F_146 ( V_9 , F_147 () ) ;
if ( F_69 ( V_208 > V_209 ) ) {
V_167 = ( V_208 - V_209 ) * 1000000ULL ;
F_156 ( V_167 , V_221 ) ;
V_220 = F_154 ( V_211 , V_167 ) ;
V_220 = F_157 ( V_220 , V_224 ) ;
F_153 ( & V_2 -> V_51 . V_171 ,
V_220 , V_216 ) ;
} else
F_138 ( V_2 ) ;
F_158 ( V_223 ) ;
}
}
static void F_159 ( struct V_1 * V_2 , T_1 V_225 )
{
bool V_226 = F_49 ( V_225 ) ;
if ( V_2 -> V_226 != V_226 ) {
V_2 -> V_226 = V_226 ;
if ( V_226 ) {
F_80 ( L_30
L_31 , V_2 -> V_9 -> V_109 ) ;
F_140 ( & V_2 -> V_9 -> V_24 -> V_11 . V_227 ) ;
} else
F_160 ( & V_2 -> V_9 -> V_24 -> V_11 . V_227 ) ;
}
}
static int F_161 ( struct V_1 * V_2 , T_1 V_67 , T_1 V_4 )
{
int V_125 = 0 ;
F_162 ( V_67 , V_4 ) ;
switch ( V_67 ) {
case V_47 :
if ( ! F_29 ( V_2 ) )
F_41 ( V_2 , V_4 >> 24 ) ;
else
V_125 = 1 ;
break;
case V_103 :
F_127 ( V_2 , true ) ;
F_86 ( V_2 , V_4 & 0xff ) ;
break;
case V_228 :
F_111 ( V_2 ) ;
break;
case V_33 :
if ( ! F_29 ( V_2 ) )
F_42 ( V_2 , V_4 & V_229 ) ;
else
V_125 = 1 ;
break;
case V_35 :
if ( ! F_29 ( V_2 ) ) {
F_1 ( V_2 , V_35 , V_4 | 0x0FFFFFFF ) ;
F_21 ( V_2 -> V_9 -> V_24 ) ;
} else
V_125 = 1 ;
break;
case V_42 : {
T_1 V_230 = 0x3ff ;
if ( F_27 ( V_2 , V_66 ) & V_65 )
V_230 |= V_231 ;
F_38 ( V_2 , V_4 & V_230 ) ;
if ( ! ( V_4 & V_41 ) ) {
int V_27 ;
T_1 V_56 ;
for ( V_27 = 0 ; V_27 < V_232 ; V_27 ++ ) {
V_56 = F_27 ( V_2 ,
V_200 + 0x10 * V_27 ) ;
F_1 ( V_2 , V_200 + 0x10 * V_27 ,
V_56 | V_49 ) ;
}
F_136 ( V_2 ) ;
F_151 ( & V_2 -> V_51 . V_206 , 0 ) ;
}
break;
}
case V_158 :
F_1 ( V_2 , V_158 , V_4 & ~ ( 1 << 12 ) ) ;
F_116 ( V_2 ) ;
break;
case V_160 :
if ( ! F_29 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_160 , V_4 ) ;
break;
case V_233 :
F_159 ( V_2 , V_4 ) ;
case V_234 :
case V_235 :
case V_236 :
case V_237 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= V_238 [ ( V_67 - V_200 ) >> 4 ] ;
F_1 ( V_2 , V_67 , V_4 ) ;
break;
case V_200 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= ( V_238 [ 0 ] | V_2 -> V_51 . V_201 ) ;
F_1 ( V_2 , V_200 , V_4 ) ;
F_136 ( V_2 ) ;
break;
case V_169 :
if ( F_48 ( V_2 ) )
break;
F_137 ( & V_2 -> V_51 . V_171 ) ;
F_1 ( V_2 , V_169 , V_4 ) ;
F_150 ( V_2 ) ;
break;
case V_199 :
if ( V_4 & 4 )
F_80 ( L_32 , V_4 ) ;
F_1 ( V_2 , V_199 , V_4 ) ;
F_135 ( V_2 ) ;
break;
case V_239 :
if ( F_29 ( V_2 ) && V_4 != 0 ) {
F_80 ( L_33 , V_4 ) ;
V_125 = 1 ;
}
break;
case V_240 :
if ( F_29 ( V_2 ) ) {
F_161 ( V_2 , V_158 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_125 = 1 ;
break;
default:
V_125 = 1 ;
break;
}
if ( V_125 )
F_80 ( L_34 , V_67 ) ;
return V_125 ;
}
static int F_163 ( struct V_8 * V_9 , struct V_186 * V_193 ,
T_7 V_194 , int V_188 , const void * V_90 )
{
struct V_1 * V_2 = F_129 ( V_193 ) ;
unsigned int V_182 = V_194 - V_2 -> V_192 ;
T_1 V_4 ;
if ( ! F_133 ( V_2 , V_194 ) )
return - V_195 ;
if ( V_188 != 4 || ( V_182 & 0xf ) ) {
F_80 ( L_35 , V_188 , ( long ) V_194 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_90 ;
if ( V_182 != V_228 )
F_80 ( L_36
L_37 , V_219 , V_182 , V_188 , V_4 ) ;
F_161 ( V_2 , V_182 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_164 ( struct V_8 * V_9 )
{
if ( F_51 ( V_9 ) )
F_161 ( V_9 -> V_11 . V_2 , V_228 , 0 ) ;
}
void F_165 ( struct V_8 * V_9 , T_1 V_182 )
{
T_1 V_4 = 0 ;
V_182 &= 0xff0 ;
F_131 ( V_9 -> V_11 . V_2 , V_182 , 4 , & V_4 ) ;
F_161 ( V_9 -> V_11 . V_2 , V_182 , V_4 ) ;
}
void F_166 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_9 -> V_11 . V_2 )
return;
F_137 ( & V_2 -> V_51 . V_171 ) ;
if ( ! ( V_9 -> V_11 . V_241 & V_242 ) )
F_39 ( & V_243 ) ;
if ( ! V_2 -> V_43 )
F_39 ( & V_44 ) ;
if ( V_2 -> V_5 )
F_167 ( ( unsigned long ) V_2 -> V_5 ) ;
F_168 ( V_2 ) ;
}
T_6 F_169 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return 0 ;
return V_2 -> V_51 . V_208 ;
}
void F_170 ( struct V_8 * V_9 , T_6 V_90 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return;
F_137 ( & V_2 -> V_51 . V_171 ) ;
V_2 -> V_51 . V_208 = V_90 ;
F_150 ( V_2 ) ;
}
void F_171 ( struct V_8 * V_9 , unsigned long V_244 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return;
F_86 ( V_2 , ( ( V_244 & 0x0f ) << 4 )
| ( F_27 ( V_2 , V_103 ) & 4 ) ) ;
}
T_6 F_172 ( struct V_8 * V_9 )
{
T_6 V_97 ;
if ( ! F_51 ( V_9 ) )
return 0 ;
V_97 = ( T_6 ) F_27 ( V_9 -> V_11 . V_2 , V_103 ) ;
return ( V_97 & 0xf0 ) >> 4 ;
}
void F_173 ( struct V_8 * V_9 , T_6 V_245 )
{
T_6 V_246 = V_9 -> V_11 . V_241 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_2 ) {
V_245 |= V_247 ;
V_9 -> V_11 . V_241 = V_245 ;
return;
}
V_9 -> V_11 . V_241 = V_245 ;
if ( ( V_246 ^ V_245 ) & V_242 ) {
if ( V_245 & V_242 )
F_39 ( & V_243 ) ;
else
F_40 ( & V_243 . V_45 ) ;
F_21 ( V_9 -> V_24 ) ;
}
if ( ( V_246 ^ V_245 ) & V_248 ) {
if ( V_245 & V_248 ) {
F_43 ( V_2 , V_9 -> V_109 ) ;
V_77 -> V_249 ( V_9 , true ) ;
} else
V_77 -> V_249 ( V_9 , false ) ;
}
V_2 -> V_192 = V_2 -> V_9 -> V_11 . V_241 &
V_250 ;
if ( ( V_245 & V_242 ) &&
V_2 -> V_192 != V_251 )
F_174 ( L_38 ) ;
F_80 ( L_39 V_218 L_40
L_41 , V_2 -> V_9 -> V_11 . V_241 , V_2 -> V_192 ) ;
}
void F_175 ( struct V_8 * V_9 , bool V_252 )
{
struct V_1 * V_2 ;
int V_27 ;
F_80 ( L_42 , V_219 ) ;
ASSERT ( V_9 ) ;
V_2 = V_9 -> V_11 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_137 ( & V_2 -> V_51 . V_171 ) ;
if ( ! V_252 )
F_41 ( V_2 , V_9 -> V_109 ) ;
F_50 ( V_2 -> V_9 ) ;
for ( V_27 = 0 ; V_27 < V_232 ; V_27 ++ )
F_1 ( V_2 , V_200 + 0x10 * V_27 , V_49 ) ;
F_136 ( V_2 ) ;
if ( F_176 ( V_9 -> V_24 , V_253 ) )
F_1 ( V_2 , V_233 ,
F_177 ( 0 , V_254 ) ) ;
F_159 ( V_2 , F_27 ( V_2 , V_233 ) ) ;
F_1 ( V_2 , V_35 , 0xffffffffU ) ;
F_38 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_103 , 0 ) ;
if ( ! F_29 ( V_2 ) )
F_42 ( V_2 , 0 ) ;
F_1 ( V_2 , V_239 , 0 ) ;
F_1 ( V_2 , V_158 , 0 ) ;
F_1 ( V_2 , V_160 , 0 ) ;
F_1 ( V_2 , V_199 , 0 ) ;
F_1 ( V_2 , V_169 , 0 ) ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
F_1 ( V_2 , V_13 + 0x10 * V_27 , 0 ) ;
F_1 ( V_2 , V_12 + 0x10 * V_27 , 0 ) ;
F_1 ( V_2 , V_133 + 0x10 * V_27 , 0 ) ;
}
V_2 -> V_74 = V_9 -> V_11 . V_76 ;
V_2 -> V_80 = V_9 -> V_11 . V_76 ? 1 : 0 ;
V_2 -> V_81 = - 1 ;
F_135 ( V_2 ) ;
F_151 ( & V_2 -> V_51 . V_206 , 0 ) ;
if ( F_178 ( V_9 ) )
F_173 ( V_9 ,
V_9 -> V_11 . V_241 | V_247 ) ;
V_9 -> V_11 . V_89 . V_91 = 0 ;
F_85 ( V_2 ) ;
V_9 -> V_11 . V_131 = 0 ;
V_9 -> V_11 . V_95 = 0 ;
F_80 ( L_43
L_44 V_218 L_45 , V_219 ,
V_9 , F_26 ( V_2 ) ,
V_9 -> V_11 . V_241 , V_2 -> V_192 ) ;
}
static bool F_179 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ) ;
}
int F_180 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_51 ( V_9 ) && F_15 ( V_2 ) &&
F_44 ( V_2 , V_200 ) )
return F_139 ( & V_2 -> V_51 . V_206 ) ;
return 0 ;
}
int F_181 ( struct V_1 * V_2 , int V_48 )
{
T_1 V_67 = F_27 ( V_2 , V_48 ) ;
int V_10 , V_16 , V_88 ;
if ( F_17 ( V_2 ) && ! ( V_67 & V_49 ) ) {
V_10 = V_67 & V_50 ;
V_16 = V_67 & V_57 ;
V_88 = V_67 & V_255 ;
return F_73 ( V_2 , V_16 , V_10 , 1 , V_88 ,
NULL ) ;
}
return 0 ;
}
void F_182 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_2 )
F_181 ( V_2 , V_233 ) ;
}
static enum V_256 F_183 ( struct V_257 * V_90 )
{
struct V_204 * V_205 = F_130 ( V_90 , struct V_204 , V_171 ) ;
struct V_1 * V_2 = F_130 ( V_205 , struct V_1 , V_51 ) ;
F_138 ( V_2 ) ;
if ( F_179 ( V_2 ) ) {
F_184 ( & V_205 -> V_171 , V_205 -> V_170 ) ;
return V_258 ;
} else
return V_259 ;
}
int F_185 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
ASSERT ( V_9 != NULL ) ;
F_80 ( L_46 , V_9 -> V_109 ) ;
V_2 = F_22 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
goto V_260;
V_9 -> V_11 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_186 ( V_28 ) ;
if ( ! V_2 -> V_5 ) {
F_106 ( V_147 L_47 ,
V_9 -> V_109 ) ;
goto V_261;
}
V_2 -> V_9 = V_9 ;
F_187 ( & V_2 -> V_51 . V_171 , V_262 ,
V_216 ) ;
V_2 -> V_51 . V_171 . V_263 = F_183 ;
V_9 -> V_11 . V_241 = V_242 ;
F_173 ( V_9 ,
V_251 | V_242 ) ;
F_40 ( & V_44 . V_45 ) ;
F_175 ( V_9 , false ) ;
F_188 ( & V_2 -> V_187 , & V_264 ) ;
return 0 ;
V_261:
F_168 ( V_2 ) ;
V_260:
return - V_265 ;
}
int F_189 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_82 ;
if ( ! F_51 ( V_9 ) || ! F_15 ( V_2 ) )
return - 1 ;
F_85 ( V_2 ) ;
V_82 = F_63 ( V_2 ) ;
if ( ( V_82 == - 1 ) ||
( ( V_82 & 0xF0 ) <= F_27 ( V_2 , V_102 ) ) )
return - 1 ;
return V_82 ;
}
int F_190 ( struct V_8 * V_9 )
{
T_1 V_266 = F_27 ( V_9 -> V_11 . V_2 , V_233 ) ;
int V_123 = 0 ;
if ( ! F_17 ( V_9 -> V_11 . V_2 ) )
V_123 = 1 ;
if ( ( V_266 & V_49 ) == 0 &&
F_191 ( V_266 ) == V_254 )
V_123 = 1 ;
return V_123 ;
}
void F_192 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return;
if ( F_139 ( & V_2 -> V_51 . V_206 ) > 0 ) {
F_181 ( V_2 , V_200 ) ;
if ( F_48 ( V_2 ) )
V_2 -> V_51 . V_208 = 0 ;
F_151 ( & V_2 -> V_51 . V_206 , 0 ) ;
}
}
int F_193 ( struct V_8 * V_9 )
{
int V_10 = F_189 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_10 == - 1 )
return - 1 ;
F_66 ( V_10 , V_2 ) ;
F_85 ( V_2 ) ;
F_64 ( V_10 , V_2 ) ;
if ( F_3 ( V_10 , F_113 ( V_9 ) -> V_267 ) ) {
F_70 ( V_10 , V_2 ) ;
F_85 ( V_2 ) ;
}
return V_10 ;
}
void F_194 ( struct V_8 * V_9 ,
struct V_268 * V_269 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_173 ( V_9 , V_9 -> V_11 . V_241 ) ;
F_38 ( V_2 , * ( ( T_1 * ) ( V_269 -> V_5 + V_42 ) ) ) ;
memcpy ( V_9 -> V_11 . V_2 -> V_5 , V_269 -> V_5 , sizeof *V_269 ) ;
F_41 ( V_2 , F_26 ( V_2 ) ) ;
F_50 ( V_9 ) ;
F_85 ( V_2 ) ;
F_137 ( & V_2 -> V_51 . V_171 ) ;
F_136 ( V_2 ) ;
F_159 ( V_2 , F_27 ( V_2 , V_233 ) ) ;
F_135 ( V_2 ) ;
F_150 ( V_2 ) ;
V_2 -> V_74 = true ;
V_2 -> V_80 = V_9 -> V_11 . V_76 ?
1 : F_55 ( V_2 -> V_5 + V_12 ) ;
V_2 -> V_81 = - 1 ;
if ( V_9 -> V_11 . V_76 ) {
V_77 -> V_270 ( V_9 ,
F_63 ( V_2 ) ) ;
V_77 -> V_79 ( V_9 -> V_24 ,
F_68 ( V_2 ) ) ;
}
F_60 ( V_73 , V_9 ) ;
if ( F_195 ( V_9 -> V_24 ) )
F_196 ( V_9 ) ;
V_9 -> V_11 . V_131 = 0 ;
}
void F_197 ( struct V_8 * V_9 )
{
struct V_257 * V_171 ;
if ( ! F_51 ( V_9 ) )
return;
V_171 = & V_9 -> V_11 . V_2 -> V_51 . V_171 ;
if ( F_137 ( V_171 ) )
F_198 ( V_171 , V_216 ) ;
}
static void F_199 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
bool V_206 ;
int V_10 ;
F_67 ( ! F_78 ( V_9 ) ) ;
V_206 = F_79 ( V_9 ) ;
F_83 ( V_9 ) ;
if ( V_206 )
return;
V_10 = F_111 ( V_2 ) ;
F_200 ( V_2 , V_10 ) ;
}
void F_201 ( struct V_8 * V_9 )
{
T_1 V_90 ;
if ( F_3 ( V_94 , & V_9 -> V_11 . V_95 ) )
F_199 ( V_9 , V_9 -> V_11 . V_2 ) ;
if ( ! F_3 ( V_271 , & V_9 -> V_11 . V_95 ) )
return;
if ( F_77 ( V_9 -> V_24 , & V_9 -> V_11 . V_2 -> V_272 , & V_90 ,
sizeof( T_1 ) ) )
return;
F_86 ( V_9 -> V_11 . V_2 , V_90 & 0xff ) ;
}
static void F_202 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( ! F_78 ( V_9 ) ||
V_2 -> V_74 ||
V_2 -> V_81 == - 1 ||
F_107 ( V_2 , V_2 -> V_81 ) ) {
return;
}
F_81 ( V_2 -> V_9 ) ;
}
void F_203 ( struct V_8 * V_9 )
{
T_1 V_90 , V_97 ;
int V_273 , V_274 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_202 ( V_9 , V_2 ) ;
if ( ! F_3 ( V_271 , & V_9 -> V_11 . V_95 ) )
return;
V_97 = F_27 ( V_2 , V_103 ) & 0xff ;
V_273 = F_63 ( V_2 ) ;
if ( V_273 < 0 )
V_273 = 0 ;
V_274 = F_68 ( V_2 ) ;
if ( V_274 < 0 )
V_274 = 0 ;
V_90 = ( V_97 & 0xff ) | ( ( V_274 & 0xf0 ) << 8 ) | ( V_273 << 24 ) ;
F_75 ( V_9 -> V_24 , & V_9 -> V_11 . V_2 -> V_272 , & V_90 ,
sizeof( T_1 ) ) ;
}
int F_204 ( struct V_8 * V_9 , T_7 V_275 )
{
if ( V_275 ) {
if ( F_205 ( V_9 -> V_24 ,
& V_9 -> V_11 . V_2 -> V_272 ,
V_275 , sizeof( T_1 ) ) )
return - V_276 ;
F_82 ( V_271 , & V_9 -> V_11 . V_95 ) ;
} else {
F_84 ( V_271 , & V_9 -> V_11 . V_95 ) ;
}
V_9 -> V_11 . V_2 -> V_275 = V_275 ;
return 0 ;
}
int F_206 ( struct V_8 * V_9 , T_1 V_277 , T_6 V_90 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_277 - V_278 ) << 4 ;
if ( ! F_207 ( V_9 ) || ! F_29 ( V_2 ) )
return 1 ;
if ( V_67 == V_160 )
return 1 ;
if ( V_67 == V_158 )
F_161 ( V_2 , V_160 , ( T_1 ) ( V_90 >> 32 ) ) ;
return F_161 ( V_2 , V_67 , ( T_1 ) V_90 ) ;
}
int F_208 ( struct V_8 * V_9 , T_1 V_277 , T_6 * V_90 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_277 - V_278 ) << 4 , V_279 , V_280 = 0 ;
if ( ! F_207 ( V_9 ) || ! F_29 ( V_2 ) )
return 1 ;
if ( V_67 == V_35 || V_67 == V_160 ) {
F_80 ( L_48 ,
V_67 ) ;
return 1 ;
}
if ( F_131 ( V_2 , V_67 , 4 , & V_279 ) )
return 1 ;
if ( V_67 == V_158 )
F_131 ( V_2 , V_160 , 4 , & V_280 ) ;
* V_90 = ( ( ( T_6 ) V_280 ) << 32 ) | V_279 ;
return 0 ;
}
int F_209 ( struct V_8 * V_9 , T_1 V_67 , T_6 V_90 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return 1 ;
if ( V_67 == V_158 )
F_161 ( V_2 , V_160 , ( T_1 ) ( V_90 >> 32 ) ) ;
return F_161 ( V_2 , V_67 , ( T_1 ) V_90 ) ;
}
int F_210 ( struct V_8 * V_9 , T_1 V_67 , T_6 * V_90 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_279 , V_280 = 0 ;
if ( ! F_51 ( V_9 ) )
return 1 ;
if ( F_131 ( V_2 , V_67 , 4 , & V_279 ) )
return 1 ;
if ( V_67 == V_158 )
F_131 ( V_2 , V_160 , 4 , & V_280 ) ;
* V_90 = ( ( ( T_6 ) V_280 ) << 32 ) | V_279 ;
return 0 ;
}
int F_211 ( struct V_8 * V_9 , T_6 V_90 )
{
T_6 V_191 = V_90 & ~ V_92 ;
if ( ! F_212 ( V_191 , 4 ) )
return 1 ;
V_9 -> V_11 . V_89 . V_91 = V_90 ;
if ( ! F_78 ( V_9 ) )
return 0 ;
return F_205 ( V_9 -> V_24 , & V_9 -> V_11 . V_89 . V_90 ,
V_191 , sizeof( T_3 ) ) ;
}
void F_213 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_3 V_144 ;
unsigned long V_281 ;
if ( ! F_51 ( V_9 ) || ! V_2 -> V_141 )
return;
if ( F_214 ( V_9 ) ) {
F_215 ( V_9 -> V_11 . V_282 == V_283 ) ;
if ( F_3 ( V_145 , & V_2 -> V_141 ) )
F_10 ( V_145 , & V_2 -> V_141 ) ;
return;
}
V_281 = F_58 ( & V_2 -> V_141 , 0 ) ;
if ( F_3 ( V_142 , & V_281 ) ) {
F_175 ( V_9 , true ) ;
F_216 ( V_9 , true ) ;
if ( F_178 ( V_2 -> V_9 ) )
V_9 -> V_11 . V_282 = V_284 ;
else
V_9 -> V_11 . V_282 = V_283 ;
}
if ( F_3 ( V_145 , & V_281 ) &&
V_9 -> V_11 . V_282 == V_283 ) {
F_217 () ;
V_144 = V_2 -> V_144 ;
F_80 ( L_49 ,
V_9 -> V_109 , V_144 ) ;
F_218 ( V_9 , V_144 ) ;
V_9 -> V_11 . V_282 = V_284 ;
}
}
void F_219 ( void )
{
F_220 ( & V_243 , V_285 ) ;
F_220 ( & V_44 , V_285 ) ;
}
