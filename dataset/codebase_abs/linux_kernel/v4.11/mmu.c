void F_1 ( T_1 V_1 )
{
V_2 = V_1 | V_3 ;
}
static inline bool F_2 ( T_1 V_4 )
{
return ( V_4 & V_5 ) == V_6 ;
}
static T_1 F_3 ( unsigned int V_7 )
{
T_1 V_8 ;
F_4 ( V_7 & ~ V_9 ) ;
V_8 = ( V_7 & V_10 ) << V_11 ;
V_8 |= ( ( T_1 ) V_7 >> V_12 ) << V_13 ;
return V_8 ;
}
static unsigned int F_5 ( T_1 V_4 )
{
unsigned int V_7 ;
V_4 &= ~ V_2 ;
V_7 = ( V_4 >> V_11 ) & V_10 ;
V_7 |= ( V_4 >> V_13 ) << V_12 ;
return V_7 ;
}
static unsigned int F_6 ( struct V_14 * V_15 )
{
return F_7 ( V_15 ) -> V_16 & V_9 ;
}
static void F_8 ( struct V_14 * V_15 , T_1 * V_17 , T_1 V_18 ,
unsigned V_19 )
{
unsigned int V_7 = F_6 ( V_15 ) ;
T_1 V_8 = F_3 ( V_7 ) ;
V_19 &= V_20 | V_21 ;
V_8 |= V_2 | V_19 | V_18 << V_22 ;
F_9 ( V_17 , V_18 , V_19 , V_7 ) ;
F_10 ( V_17 , V_8 ) ;
}
static bool F_11 ( T_1 V_4 )
{
return ( V_4 & V_2 ) == V_2 ;
}
static T_2 F_12 ( T_1 V_4 )
{
T_1 V_8 = F_3 ( V_9 ) | V_2 ;
return ( V_4 & ~ V_8 ) >> V_22 ;
}
static unsigned F_13 ( T_1 V_4 )
{
T_1 V_8 = F_3 ( V_9 ) | V_2 ;
return ( V_4 & ~ V_8 ) & ~ V_23 ;
}
static bool F_14 ( struct V_14 * V_15 , T_1 * V_17 , T_2 V_18 ,
T_3 V_24 , unsigned V_19 )
{
if ( F_15 ( F_16 ( V_24 ) ) ) {
F_8 ( V_15 , V_17 , V_18 , V_19 ) ;
return true ;
}
return false ;
}
static bool F_17 ( struct V_14 * V_15 , T_1 V_4 )
{
unsigned int V_25 , V_26 ;
V_25 = F_6 ( V_15 ) ;
V_26 = F_5 ( V_4 ) ;
F_18 ( V_4 , V_25 , V_26 ) ;
return F_19 ( V_25 == V_26 ) ;
}
void F_20 ( T_1 V_27 , T_1 V_28 ,
T_1 V_29 , T_1 V_30 , T_1 V_31 , T_1 V_32 ,
T_1 V_33 )
{
if ( V_33 != 0 )
V_33 |= V_3 ;
V_34 = V_27 ;
V_35 = V_28 ;
V_36 = V_29 ;
V_37 = V_30 ;
V_38 = V_31 ;
V_39 = V_32 ;
V_5 = V_33 ;
F_4 ( V_35 != 0 && V_5 != 0 ) ;
}
void F_21 ( void )
{
V_34 = 0 ;
V_35 = 0 ;
V_36 = 0 ;
V_37 = 0 ;
V_38 = 0 ;
V_2 = 0 ;
V_39 = 0 ;
V_5 = 0 ;
}
static int F_22 ( void )
{
return 1 ;
}
static int F_23 ( struct V_14 * V_15 )
{
return V_15 -> V_40 . V_41 & V_42 ;
}
static int F_24 ( T_1 V_43 )
{
return ( V_43 != 0 ) && ! F_11 ( V_43 ) ;
}
static int F_25 ( T_1 V_43 )
{
return V_43 & V_44 ;
}
static int F_26 ( T_1 V_43 , int V_45 )
{
if ( V_45 == V_46 )
return 1 ;
if ( F_25 ( V_43 ) )
return 1 ;
return 0 ;
}
static bool F_27 ( T_1 V_4 )
{
return ( V_4 & ( V_38 | V_37 ) ) == V_38 ;
}
static T_3 F_28 ( T_1 V_43 )
{
return ( V_43 & V_47 ) >> V_22 ;
}
static T_2 F_29 ( T_4 V_48 )
{
int V_49 = 32 - V_50 - V_22 ;
return ( V_48 & V_51 ) << V_49 ;
}
static void F_30 ( T_1 * V_17 , T_1 V_4 )
{
F_31 ( * V_17 , V_4 ) ;
}
static void F_32 ( T_1 * V_17 , T_1 V_4 )
{
F_31 ( * V_17 , V_4 ) ;
}
static T_1 F_33 ( T_1 * V_17 , T_1 V_4 )
{
return F_34 ( V_17 , V_4 ) ;
}
static T_1 F_35 ( T_1 * V_17 )
{
return F_36 ( * V_17 ) ;
}
static void F_37 ( T_1 * V_17 , T_1 V_4 )
{
struct V_52 * V_53 = F_38 ( F_39 ( V_17 ) ) ;
if ( F_24 ( V_4 ) )
return;
F_40 () ;
V_53 -> V_54 ++ ;
}
static void F_30 ( T_1 * V_17 , T_1 V_4 )
{
union V_55 * V_56 , V_57 ;
V_56 = (union V_55 * ) V_17 ;
V_57 = (union V_55 ) V_4 ;
V_56 -> V_58 = V_57 . V_58 ;
F_40 () ;
F_31 ( V_56 -> V_59 , V_57 . V_59 ) ;
}
static void F_32 ( T_1 * V_17 , T_1 V_4 )
{
union V_55 * V_56 , V_57 ;
V_56 = (union V_55 * ) V_17 ;
V_57 = (union V_55 ) V_4 ;
F_31 ( V_56 -> V_59 , V_57 . V_59 ) ;
F_40 () ;
V_56 -> V_58 = V_57 . V_58 ;
F_37 ( V_17 , V_4 ) ;
}
static T_1 F_33 ( T_1 * V_17 , T_1 V_4 )
{
union V_55 * V_56 , V_57 , V_60 ;
V_56 = (union V_55 * ) V_17 ;
V_57 = (union V_55 ) V_4 ;
V_60 . V_59 = F_34 ( & V_56 -> V_59 , V_57 . V_59 ) ;
V_60 . V_58 = V_56 -> V_58 ;
V_56 -> V_58 = V_57 . V_58 ;
F_37 ( V_17 , V_4 ) ;
return V_60 . V_4 ;
}
static T_1 F_35 ( T_1 * V_17 )
{
struct V_52 * V_53 = F_38 ( F_39 ( V_17 ) ) ;
union V_55 V_4 , * V_60 = (union V_55 * ) V_17 ;
int V_61 ;
V_62:
V_61 = V_53 -> V_54 ;
F_41 () ;
V_4 . V_59 = V_60 -> V_59 ;
F_41 () ;
V_4 . V_58 = V_60 -> V_58 ;
F_41 () ;
if ( F_15 ( V_4 . V_59 != V_60 -> V_59 ||
V_61 != V_53 -> V_54 ) )
goto V_62;
return V_4 . V_4 ;
}
static bool F_42 ( T_1 V_4 )
{
return ( V_4 & ( V_63 | V_64 ) ) ==
( V_63 | V_64 ) ;
}
static bool F_43 ( T_1 V_4 )
{
if ( ! F_24 ( V_4 ) )
return false ;
if ( F_42 ( V_4 ) ||
F_2 ( V_4 ) )
return true ;
if ( V_35 ) {
if ( ( V_4 & V_35 ) == 0 ||
( F_44 ( V_4 ) && ( V_4 & V_36 ) == 0 ) )
return true ;
}
return false ;
}
static bool F_45 ( T_1 V_4 )
{
return V_35 ? V_4 & V_35
: ! F_2 ( V_4 ) ;
}
static bool F_46 ( T_1 V_4 )
{
return V_36 ? V_4 & V_36
: V_4 & V_65 ;
}
static void F_10 ( T_1 * V_17 , T_1 V_66 )
{
F_4 ( F_24 ( * V_17 ) ) ;
F_30 ( V_17 , V_66 ) ;
}
static T_1 F_47 ( T_1 * V_17 , T_1 V_66 )
{
T_1 V_67 = * V_17 ;
F_4 ( ! F_24 ( V_66 ) ) ;
if ( ! F_24 ( V_67 ) ) {
F_10 ( V_17 , V_66 ) ;
return V_67 ;
}
if ( ! F_43 ( V_67 ) )
F_32 ( V_17 , V_66 ) ;
else
V_67 = F_33 ( V_17 , V_66 ) ;
F_4 ( F_28 ( V_67 ) != F_28 ( V_66 ) ) ;
return V_67 ;
}
static bool F_48 ( T_1 * V_17 , T_1 V_66 )
{
bool V_68 = false ;
T_1 V_67 = F_47 ( V_17 , V_66 ) ;
if ( ! F_24 ( V_67 ) )
return false ;
if ( F_42 ( V_67 ) &&
! F_44 ( V_66 ) )
V_68 = true ;
if ( F_45 ( V_67 ) && ! F_45 ( V_66 ) ) {
V_68 = true ;
F_49 ( F_28 ( V_67 ) ) ;
}
if ( F_46 ( V_67 ) && ! F_46 ( V_66 ) ) {
V_68 = true ;
F_50 ( F_28 ( V_67 ) ) ;
}
return V_68 ;
}
static int F_51 ( T_1 * V_17 )
{
T_3 V_24 ;
T_1 V_67 = * V_17 ;
if ( ! F_43 ( V_67 ) )
F_32 ( V_17 , 0ull ) ;
else
V_67 = F_33 ( V_17 , 0ull ) ;
if ( ! F_24 ( V_67 ) )
return 0 ;
V_24 = F_28 ( V_67 ) ;
F_4 ( ! F_52 ( V_24 ) && ! F_53 ( F_54 ( V_24 ) ) ) ;
if ( F_45 ( V_67 ) )
F_49 ( V_24 ) ;
if ( F_46 ( V_67 ) )
F_50 ( V_24 ) ;
return 1 ;
}
static void F_55 ( T_1 * V_17 )
{
F_32 ( V_17 , 0ull ) ;
}
static T_1 F_56 ( T_1 * V_17 )
{
return F_35 ( V_17 ) ;
}
static T_1 F_57 ( T_1 V_4 )
{
if ( V_35 != 0 )
return V_4 & ~ V_35 ;
if ( V_5 == 0 || F_2 ( V_4 ) )
return V_4 ;
F_58 ( ( V_4 & V_65 ) &&
! F_42 ( V_4 ) ,
L_1 ) ;
F_58 ( V_4 & ( V_69 <<
V_70 ) ,
L_2 ) ;
V_4 |= ( V_4 & V_69 ) <<
V_70 ;
V_4 &= ~ V_5 ;
V_4 |= V_6 ;
return V_4 ;
}
static T_1 F_59 ( T_1 V_4 )
{
T_1 V_66 = V_4 ;
T_1 V_71 = ( V_4 >> V_70 )
& V_69 ;
F_60 ( ! F_2 ( V_4 ) ) ;
V_66 &= ~ V_5 ;
V_66 &= ~ ( V_69 <<
V_70 ) ;
V_66 |= V_71 ;
return V_66 ;
}
static bool F_61 ( T_1 * V_17 )
{
T_1 V_4 = F_56 ( V_17 ) ;
if ( ! F_45 ( V_4 ) )
return false ;
if ( V_35 ) {
F_62 ( ( F_63 ( V_35 ) - 1 ) ,
( unsigned long * ) V_17 ) ;
} else {
if ( F_44 ( V_4 ) )
F_50 ( F_28 ( V_4 ) ) ;
V_4 = F_57 ( V_4 ) ;
F_47 ( V_17 , V_4 ) ;
}
return true ;
}
static void F_64 ( struct V_14 * V_15 )
{
F_65 () ;
F_66 ( V_15 -> V_72 , V_73 ) ;
}
static void F_67 ( struct V_14 * V_15 )
{
F_68 ( & V_15 -> V_72 , V_74 ) ;
F_69 () ;
}
static int F_70 ( struct V_75 * V_76 ,
struct V_77 * V_78 , int V_79 )
{
void * V_80 ;
if ( V_76 -> V_81 >= V_79 )
return 0 ;
while ( V_76 -> V_81 < F_71 ( V_76 -> V_82 ) ) {
V_80 = F_72 ( V_78 , V_83 ) ;
if ( ! V_80 )
return - V_84 ;
V_76 -> V_82 [ V_76 -> V_81 ++ ] = V_80 ;
}
return 0 ;
}
static int F_73 ( struct V_75 * V_76 )
{
return V_76 -> V_81 ;
}
static void F_74 ( struct V_75 * V_85 ,
struct V_77 * V_76 )
{
while ( V_85 -> V_81 )
F_75 ( V_76 , V_85 -> V_82 [ -- V_85 -> V_81 ] ) ;
}
static int F_76 ( struct V_75 * V_76 ,
int V_79 )
{
void * V_86 ;
if ( V_76 -> V_81 >= V_79 )
return 0 ;
while ( V_76 -> V_81 < F_71 ( V_76 -> V_82 ) ) {
V_86 = ( void * ) F_77 ( V_83 ) ;
if ( ! V_86 )
return - V_84 ;
V_76 -> V_82 [ V_76 -> V_81 ++ ] = V_86 ;
}
return 0 ;
}
static void F_78 ( struct V_75 * V_85 )
{
while ( V_85 -> V_81 )
F_79 ( ( unsigned long ) V_85 -> V_82 [ -- V_85 -> V_81 ] ) ;
}
static int F_80 ( struct V_14 * V_15 )
{
int V_87 ;
V_87 = F_70 ( & V_15 -> V_40 . V_88 ,
V_89 , 8 + V_90 ) ;
if ( V_87 )
goto V_91;
V_87 = F_76 ( & V_15 -> V_40 . V_92 , 8 ) ;
if ( V_87 )
goto V_91;
V_87 = F_70 ( & V_15 -> V_40 . V_93 ,
V_93 , 4 ) ;
V_91:
return V_87 ;
}
static void F_81 ( struct V_14 * V_15 )
{
F_74 ( & V_15 -> V_40 . V_88 ,
V_89 ) ;
F_78 ( & V_15 -> V_40 . V_92 ) ;
F_74 ( & V_15 -> V_40 . V_93 ,
V_93 ) ;
}
static void * F_82 ( struct V_75 * V_85 )
{
void * V_94 ;
F_83 ( ! V_85 -> V_81 ) ;
V_94 = V_85 -> V_82 [ -- V_85 -> V_81 ] ;
return V_94 ;
}
static struct V_95 * F_84 ( struct V_14 * V_15 )
{
return F_82 ( & V_15 -> V_40 . V_88 ) ;
}
static void F_85 ( struct V_95 * V_95 )
{
F_75 ( V_89 , V_95 ) ;
}
static T_2 F_86 ( struct V_52 * V_53 , int V_96 )
{
if ( ! V_53 -> V_97 . V_98 )
return V_53 -> V_99 [ V_96 ] ;
return V_53 -> V_18 + ( V_96 << ( ( V_53 -> V_97 . V_45 - 1 ) * V_100 ) ) ;
}
static void F_87 ( struct V_52 * V_53 , int V_96 , T_2 V_18 )
{
if ( V_53 -> V_97 . V_98 )
F_83 ( V_18 != F_86 ( V_53 , V_96 ) ) ;
else
V_53 -> V_99 [ V_96 ] = V_18 ;
}
static struct V_101 * F_88 ( T_2 V_18 ,
struct V_102 * V_103 ,
int V_45 )
{
unsigned long V_104 ;
V_104 = F_89 ( V_18 , V_103 -> V_105 , V_45 ) ;
return & V_103 -> V_40 . V_106 [ V_45 - 2 ] [ V_104 ] ;
}
static void F_90 ( struct V_102 * V_103 ,
T_2 V_18 , int V_61 )
{
struct V_101 * V_107 ;
int V_108 ;
for ( V_108 = V_109 ; V_108 <= V_110 ; ++ V_108 ) {
V_107 = F_88 ( V_18 , V_103 , V_108 ) ;
V_107 -> V_111 += V_61 ;
F_4 ( V_107 -> V_111 < 0 ) ;
}
}
void F_91 ( struct V_102 * V_103 , T_2 V_18 )
{
F_90 ( V_103 , V_18 , 1 ) ;
}
void F_92 ( struct V_102 * V_103 , T_2 V_18 )
{
F_90 ( V_103 , V_18 , - 1 ) ;
}
static void F_93 ( struct V_112 * V_112 , struct V_52 * V_53 )
{
struct V_113 * V_114 ;
struct V_102 * V_103 ;
T_2 V_18 ;
V_112 -> V_40 . V_115 ++ ;
V_18 = V_53 -> V_18 ;
V_114 = F_94 ( V_112 , V_53 -> V_97 ) ;
V_103 = F_95 ( V_114 , V_18 ) ;
if ( V_53 -> V_97 . V_45 > V_46 )
return F_96 ( V_112 , V_103 , V_18 ,
V_116 ) ;
F_91 ( V_103 , V_18 ) ;
}
static void F_97 ( struct V_112 * V_112 , struct V_52 * V_53 )
{
struct V_113 * V_114 ;
struct V_102 * V_103 ;
T_2 V_18 ;
V_112 -> V_40 . V_115 -- ;
V_18 = V_53 -> V_18 ;
V_114 = F_94 ( V_112 , V_53 -> V_97 ) ;
V_103 = F_95 ( V_114 , V_18 ) ;
if ( V_53 -> V_97 . V_45 > V_46 )
return F_98 ( V_112 , V_103 , V_18 ,
V_116 ) ;
F_92 ( V_103 , V_18 ) ;
}
static bool F_99 ( T_2 V_18 , int V_45 ,
struct V_102 * V_103 )
{
struct V_101 * V_107 ;
if ( V_103 ) {
V_107 = F_88 ( V_18 , V_103 , V_45 ) ;
return ! ! V_107 -> V_111 ;
}
return true ;
}
static bool F_100 ( struct V_14 * V_15 , T_2 V_18 ,
int V_45 )
{
struct V_102 * V_103 ;
V_103 = F_101 ( V_15 , V_18 ) ;
return F_99 ( V_18 , V_45 , V_103 ) ;
}
static int F_102 ( struct V_112 * V_112 , T_2 V_18 )
{
unsigned long V_117 ;
int V_108 , V_118 = 0 ;
V_117 = F_103 ( V_112 , V_18 ) ;
for ( V_108 = V_46 ; V_108 <= V_110 ; ++ V_108 ) {
if ( V_117 >= F_104 ( V_108 ) )
V_118 = V_108 ;
else
break;
}
return V_118 ;
}
static inline bool F_105 ( struct V_102 * V_103 ,
bool V_119 )
{
if ( ! V_103 || V_103 -> V_120 & V_121 )
return false ;
if ( V_119 && V_103 -> V_122 )
return false ;
return true ;
}
static struct V_102 *
F_106 ( struct V_14 * V_15 , T_2 V_18 ,
bool V_119 )
{
struct V_102 * V_103 ;
V_103 = F_101 ( V_15 , V_18 ) ;
if ( ! F_105 ( V_103 , V_119 ) )
V_103 = NULL ;
return V_103 ;
}
static int F_107 ( struct V_14 * V_15 , T_2 V_123 ,
bool * V_124 )
{
int V_125 , V_45 , V_126 ;
struct V_102 * V_103 ;
if ( F_15 ( * V_124 ) )
return V_46 ;
V_103 = F_101 ( V_15 , V_123 ) ;
* V_124 = ! F_105 ( V_103 , true ) ;
if ( F_15 ( * V_124 ) )
return V_46 ;
V_125 = F_102 ( V_15 -> V_112 , V_123 ) ;
if ( V_125 == V_46 )
return V_125 ;
V_126 = V_79 ( V_127 -> V_128 () , V_125 ) ;
for ( V_45 = V_109 ; V_45 <= V_126 ; ++ V_45 )
if ( F_99 ( V_123 , V_45 , V_103 ) )
break;
return V_45 - 1 ;
}
static int F_108 ( struct V_14 * V_15 , T_1 * V_4 ,
struct V_129 * V_130 )
{
struct V_95 * V_131 ;
int V_108 , V_61 = 0 ;
if ( ! V_130 -> V_132 ) {
F_109 ( L_3 , V_4 , * V_4 ) ;
V_130 -> V_132 = ( unsigned long ) V_4 ;
} else if ( ! ( V_130 -> V_132 & 1 ) ) {
F_109 ( L_4 , V_4 , * V_4 ) ;
V_131 = F_84 ( V_15 ) ;
V_131 -> V_133 [ 0 ] = ( T_1 * ) V_130 -> V_132 ;
V_131 -> V_133 [ 1 ] = V_4 ;
V_130 -> V_132 = ( unsigned long ) V_131 | 1 ;
++ V_61 ;
} else {
F_109 ( L_5 , V_4 , * V_4 ) ;
V_131 = (struct V_95 * ) ( V_130 -> V_132 & ~ 1ul ) ;
while ( V_131 -> V_133 [ V_134 - 1 ] && V_131 -> V_135 ) {
V_131 = V_131 -> V_135 ;
V_61 += V_134 ;
}
if ( V_131 -> V_133 [ V_134 - 1 ] ) {
V_131 -> V_135 = F_84 ( V_15 ) ;
V_131 = V_131 -> V_135 ;
}
for ( V_108 = 0 ; V_131 -> V_133 [ V_108 ] ; ++ V_108 )
++ V_61 ;
V_131 -> V_133 [ V_108 ] = V_4 ;
}
return V_61 ;
}
static void
F_110 ( struct V_129 * V_130 ,
struct V_95 * V_131 , int V_108 ,
struct V_95 * V_136 )
{
int V_137 ;
for ( V_137 = V_134 - 1 ; ! V_131 -> V_133 [ V_137 ] && V_137 > V_108 ; -- V_137 )
;
V_131 -> V_133 [ V_108 ] = V_131 -> V_133 [ V_137 ] ;
V_131 -> V_133 [ V_137 ] = NULL ;
if ( V_137 != 0 )
return;
if ( ! V_136 && ! V_131 -> V_135 )
V_130 -> V_132 = ( unsigned long ) V_131 -> V_133 [ 0 ] ;
else
if ( V_136 )
V_136 -> V_135 = V_131 -> V_135 ;
else
V_130 -> V_132 = ( unsigned long ) V_131 -> V_135 | 1 ;
F_85 ( V_131 ) ;
}
static void F_111 ( T_1 * V_4 , struct V_129 * V_130 )
{
struct V_95 * V_131 ;
struct V_95 * V_136 ;
int V_108 ;
if ( ! V_130 -> V_132 ) {
F_112 ( V_138 L_6 , V_4 ) ;
F_113 () ;
} else if ( ! ( V_130 -> V_132 & 1 ) ) {
F_109 ( L_7 , V_4 ) ;
if ( ( T_1 * ) V_130 -> V_132 != V_4 ) {
F_112 ( V_138 L_8 , V_4 ) ;
F_113 () ;
}
V_130 -> V_132 = 0 ;
} else {
F_109 ( L_9 , V_4 ) ;
V_131 = (struct V_95 * ) ( V_130 -> V_132 & ~ 1ul ) ;
V_136 = NULL ;
while ( V_131 ) {
for ( V_108 = 0 ; V_108 < V_134 && V_131 -> V_133 [ V_108 ] ; ++ V_108 ) {
if ( V_131 -> V_133 [ V_108 ] == V_4 ) {
F_110 ( V_130 ,
V_131 , V_108 , V_136 ) ;
return;
}
}
V_136 = V_131 ;
V_131 = V_131 -> V_135 ;
}
F_114 ( L_10 , V_4 ) ;
F_113 () ;
}
}
static struct V_129 * F_115 ( T_2 V_18 , int V_45 ,
struct V_102 * V_103 )
{
unsigned long V_104 ;
V_104 = F_89 ( V_18 , V_103 -> V_105 , V_45 ) ;
return & V_103 -> V_40 . V_139 [ V_45 - V_46 ] [ V_104 ] ;
}
static struct V_129 * F_116 ( struct V_112 * V_112 , T_2 V_18 ,
struct V_52 * V_53 )
{
struct V_113 * V_114 ;
struct V_102 * V_103 ;
V_114 = F_94 ( V_112 , V_53 -> V_97 ) ;
V_103 = F_95 ( V_114 , V_18 ) ;
return F_115 ( V_18 , V_53 -> V_97 . V_45 , V_103 ) ;
}
static bool F_117 ( struct V_14 * V_15 )
{
struct V_75 * V_76 ;
V_76 = & V_15 -> V_40 . V_88 ;
return F_73 ( V_76 ) ;
}
static int F_118 ( struct V_14 * V_15 , T_1 * V_4 , T_2 V_18 )
{
struct V_52 * V_53 ;
struct V_129 * V_130 ;
V_53 = F_38 ( F_39 ( V_4 ) ) ;
F_87 ( V_53 , V_4 - V_53 -> V_140 , V_18 ) ;
V_130 = F_116 ( V_15 -> V_112 , V_18 , V_53 ) ;
return F_108 ( V_15 , V_4 , V_130 ) ;
}
static void F_119 ( struct V_112 * V_112 , T_1 * V_4 )
{
struct V_52 * V_53 ;
T_2 V_18 ;
struct V_129 * V_130 ;
V_53 = F_38 ( F_39 ( V_4 ) ) ;
V_18 = F_86 ( V_53 , V_4 - V_53 -> V_140 ) ;
V_130 = F_116 ( V_112 , V_18 , V_53 ) ;
F_111 ( V_4 , V_130 ) ;
}
static T_1 * F_120 ( struct V_129 * V_130 ,
struct V_141 * V_142 )
{
T_1 * V_17 ;
if ( ! V_130 -> V_132 )
return NULL ;
if ( ! ( V_130 -> V_132 & 1 ) ) {
V_142 -> V_131 = NULL ;
V_17 = ( T_1 * ) V_130 -> V_132 ;
goto V_91;
}
V_142 -> V_131 = (struct V_95 * ) ( V_130 -> V_132 & ~ 1ul ) ;
V_142 -> V_143 = 0 ;
V_17 = V_142 -> V_131 -> V_133 [ V_142 -> V_143 ] ;
V_91:
F_83 ( ! F_24 ( * V_17 ) ) ;
return V_17 ;
}
static T_1 * F_121 ( struct V_141 * V_142 )
{
T_1 * V_17 ;
if ( V_142 -> V_131 ) {
if ( V_142 -> V_143 < V_134 - 1 ) {
++ V_142 -> V_143 ;
V_17 = V_142 -> V_131 -> V_133 [ V_142 -> V_143 ] ;
if ( V_17 )
goto V_91;
}
V_142 -> V_131 = V_142 -> V_131 -> V_135 ;
if ( V_142 -> V_131 ) {
V_142 -> V_143 = 0 ;
V_17 = V_142 -> V_131 -> V_133 [ V_142 -> V_143 ] ;
goto V_91;
}
}
return NULL ;
V_91:
F_83 ( ! F_24 ( * V_17 ) ) ;
return V_17 ;
}
static void F_122 ( struct V_112 * V_112 , T_1 * V_17 )
{
if ( F_51 ( V_17 ) )
F_119 ( V_112 , V_17 ) ;
}
static bool F_123 ( struct V_112 * V_112 , T_1 * V_17 )
{
if ( F_25 ( * V_17 ) ) {
F_4 ( F_38 ( F_39 ( V_17 ) ) -> V_97 . V_45 ==
V_46 ) ;
F_122 ( V_112 , V_17 ) ;
-- V_112 -> V_144 . V_145 ;
return true ;
}
return false ;
}
static void F_124 ( struct V_14 * V_15 , T_1 * V_17 )
{
if ( F_123 ( V_15 -> V_112 , V_17 ) )
F_125 ( V_15 -> V_112 ) ;
}
static bool F_126 ( T_1 * V_17 , bool V_146 )
{
T_1 V_4 = * V_17 ;
if ( ! F_44 ( V_4 ) &&
! ( V_146 && F_42 ( V_4 ) ) )
return false ;
F_109 ( L_11 , V_17 , * V_17 ) ;
if ( V_146 )
V_4 &= ~ V_64 ;
V_4 = V_4 & ~ V_65 ;
return F_48 ( V_17 , V_4 ) ;
}
static bool F_127 ( struct V_112 * V_112 ,
struct V_129 * V_130 ,
bool V_146 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
bool V_68 = false ;
F_128 (rmap_head, &iter, sptep)
V_68 |= F_126 ( V_17 , V_146 ) ;
return V_68 ;
}
static bool F_129 ( T_1 * V_17 )
{
T_1 V_4 = * V_17 ;
F_109 ( L_12 , V_17 , * V_17 ) ;
V_4 &= ~ V_36 ;
return F_48 ( V_17 , V_4 ) ;
}
static bool F_130 ( struct V_112 * V_112 , struct V_129 * V_130 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
bool V_68 = false ;
F_128 (rmap_head, &iter, sptep)
V_68 |= F_129 ( V_17 ) ;
return V_68 ;
}
static bool F_131 ( T_1 * V_17 )
{
T_1 V_4 = * V_17 ;
F_109 ( L_13 , V_17 , * V_17 ) ;
V_4 |= V_36 ;
return F_48 ( V_17 , V_4 ) ;
}
static bool F_132 ( struct V_112 * V_112 , struct V_129 * V_130 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
bool V_68 = false ;
F_128 (rmap_head, &iter, sptep)
V_68 |= F_131 ( V_17 ) ;
return V_68 ;
}
static void F_133 ( struct V_112 * V_112 ,
struct V_102 * V_103 ,
T_2 V_147 , unsigned long V_8 )
{
struct V_129 * V_130 ;
while ( V_8 ) {
V_130 = F_115 ( V_103 -> V_105 + V_147 + F_134 ( V_8 ) ,
V_46 , V_103 ) ;
F_127 ( V_112 , V_130 , false ) ;
V_8 &= V_8 - 1 ;
}
}
void F_135 ( struct V_112 * V_112 ,
struct V_102 * V_103 ,
T_2 V_147 , unsigned long V_8 )
{
struct V_129 * V_130 ;
while ( V_8 ) {
V_130 = F_115 ( V_103 -> V_105 + V_147 + F_134 ( V_8 ) ,
V_46 , V_103 ) ;
F_130 ( V_112 , V_130 ) ;
V_8 &= V_8 - 1 ;
}
}
void F_136 ( struct V_112 * V_112 ,
struct V_102 * V_103 ,
T_2 V_147 , unsigned long V_8 )
{
if ( V_127 -> V_148 )
V_127 -> V_148 ( V_112 , V_103 , V_147 ,
V_8 ) ;
else
F_133 ( V_112 , V_103 , V_147 , V_8 ) ;
}
bool F_137 ( struct V_112 * V_112 ,
struct V_102 * V_103 , T_1 V_18 )
{
struct V_129 * V_130 ;
int V_108 ;
bool V_149 = false ;
for ( V_108 = V_46 ; V_108 <= V_110 ; ++ V_108 ) {
V_130 = F_115 ( V_18 , V_108 , V_103 ) ;
V_149 |= F_127 ( V_112 , V_130 , true ) ;
}
return V_149 ;
}
static bool F_138 ( struct V_14 * V_15 , T_1 V_18 )
{
struct V_102 * V_103 ;
V_103 = F_101 ( V_15 , V_18 ) ;
return F_137 ( V_15 -> V_112 , V_103 , V_18 ) ;
}
static bool F_139 ( struct V_112 * V_112 , struct V_129 * V_130 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
bool V_68 = false ;
while ( ( V_17 = F_120 ( V_130 , & V_142 ) ) ) {
F_109 ( L_14 , V_150 , V_17 , * V_17 ) ;
F_122 ( V_112 , V_17 ) ;
V_68 = true ;
}
return V_68 ;
}
static int F_140 ( struct V_112 * V_112 , struct V_129 * V_130 ,
struct V_102 * V_103 , T_2 V_18 , int V_45 ,
unsigned long V_151 )
{
return F_139 ( V_112 , V_130 ) ;
}
static int F_141 ( struct V_112 * V_112 , struct V_129 * V_130 ,
struct V_102 * V_103 , T_2 V_18 , int V_45 ,
unsigned long V_151 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
int V_152 = 0 ;
T_1 V_66 ;
T_5 * V_153 = ( T_5 * ) V_151 ;
T_3 V_154 ;
F_4 ( F_142 ( * V_153 ) ) ;
V_154 = F_143 ( * V_153 ) ;
V_155:
F_128 (rmap_head, &iter, sptep) {
F_109 ( L_15 ,
V_17 , * V_17 , V_18 , V_45 ) ;
V_152 = 1 ;
if ( F_144 ( * V_153 ) ) {
F_122 ( V_112 , V_17 ) ;
goto V_155;
} else {
V_66 = * V_17 & ~ V_47 ;
V_66 |= ( T_1 ) V_154 << V_22 ;
V_66 &= ~ V_65 ;
V_66 &= ~ V_63 ;
V_66 = F_57 ( V_66 ) ;
F_51 ( V_17 ) ;
F_10 ( V_17 , V_66 ) ;
}
}
if ( V_152 )
F_125 ( V_112 ) ;
return 0 ;
}
static void
F_145 ( struct V_156 * V_157 , int V_45 )
{
V_157 -> V_45 = V_45 ;
V_157 -> V_18 = V_157 -> V_158 ;
V_157 -> V_139 = F_115 ( V_157 -> V_18 , V_45 , V_157 -> V_103 ) ;
V_157 -> V_159 = F_115 ( V_157 -> V_160 , V_45 ,
V_157 -> V_103 ) ;
}
static void
F_146 ( struct V_156 * V_157 ,
struct V_102 * V_103 , int V_161 ,
int V_162 , T_2 V_158 , T_2 V_160 )
{
V_157 -> V_103 = V_103 ;
V_157 -> V_161 = V_161 ;
V_157 -> V_162 = V_162 ;
V_157 -> V_158 = V_158 ;
V_157 -> V_160 = V_160 ;
F_145 ( V_157 , V_157 -> V_161 ) ;
}
static bool F_147 ( struct V_156 * V_157 )
{
return ! ! V_157 -> V_139 ;
}
static void F_148 ( struct V_156 * V_157 )
{
if ( ++ V_157 -> V_139 <= V_157 -> V_159 ) {
V_157 -> V_18 += ( 1UL << F_149 ( V_157 -> V_45 ) ) ;
return;
}
if ( ++ V_157 -> V_45 > V_157 -> V_162 ) {
V_157 -> V_139 = NULL ;
return;
}
F_145 ( V_157 , V_157 -> V_45 ) ;
}
static int F_150 ( struct V_112 * V_112 ,
unsigned long V_163 ,
unsigned long V_164 ,
unsigned long V_151 ,
int (* F_151)( struct V_112 * V_112 ,
struct V_129 * V_130 ,
struct V_102 * V_103 ,
T_2 V_18 ,
int V_45 ,
unsigned long V_151 ) )
{
struct V_113 * V_114 ;
struct V_102 * V_165 ;
struct V_156 V_157 ;
int V_118 = 0 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_166 ; V_108 ++ ) {
V_114 = F_152 ( V_112 , V_108 ) ;
F_153 (memslot, slots) {
unsigned long V_167 , V_168 ;
T_2 V_169 , V_170 ;
V_167 = F_154 ( V_163 , V_165 -> V_171 ) ;
V_168 = V_79 ( V_164 , V_165 -> V_171 +
( V_165 -> V_172 << V_22 ) ) ;
if ( V_167 >= V_168 )
continue;
V_169 = F_155 ( V_167 , V_165 ) ;
V_170 = F_155 ( V_168 + V_173 - 1 , V_165 ) ;
F_156 (memslot, PT_PAGE_TABLE_LEVEL,
PT_MAX_HUGEPAGE_LEVEL,
gfn_start, gfn_end - 1 ,
&iterator)
V_118 |= F_151 ( V_112 , V_157 . V_139 , V_165 ,
V_157 . V_18 , V_157 . V_45 , V_151 ) ;
}
}
return V_118 ;
}
static int F_157 ( struct V_112 * V_112 , unsigned long V_174 ,
unsigned long V_151 ,
int (* F_151)( struct V_112 * V_112 ,
struct V_129 * V_130 ,
struct V_102 * V_103 ,
T_2 V_18 , int V_45 ,
unsigned long V_151 ) )
{
return F_150 ( V_112 , V_174 , V_174 + 1 , V_151 , F_151 ) ;
}
int F_158 ( struct V_112 * V_112 , unsigned long V_174 )
{
return F_157 ( V_112 , V_174 , 0 , F_140 ) ;
}
int F_159 ( struct V_112 * V_112 , unsigned long V_163 , unsigned long V_164 )
{
return F_150 ( V_112 , V_163 , V_164 , 0 , F_140 ) ;
}
void F_160 ( struct V_112 * V_112 , unsigned long V_174 , T_5 V_43 )
{
F_157 ( V_112 , V_174 , ( unsigned long ) & V_43 , F_141 ) ;
}
static int F_161 ( struct V_112 * V_112 , struct V_129 * V_130 ,
struct V_102 * V_103 , T_2 V_18 , int V_45 ,
unsigned long V_151 )
{
T_1 * V_17 ;
struct V_141 V_175 ( V_142 ) ;
int V_176 = 0 ;
F_128 (rmap_head, &iter, sptep)
V_176 |= F_61 ( V_17 ) ;
F_162 ( V_18 , V_45 , V_103 , V_176 ) ;
return V_176 ;
}
static int F_163 ( struct V_112 * V_112 , struct V_129 * V_130 ,
struct V_102 * V_103 , T_2 V_18 ,
int V_45 , unsigned long V_151 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
if ( ! V_35 && ! V_5 )
goto V_91;
F_128 (rmap_head, &iter, sptep)
if ( F_45 ( * V_17 ) )
return 1 ;
V_91:
return 0 ;
}
static void F_164 ( struct V_14 * V_15 , T_1 * V_4 , T_2 V_18 )
{
struct V_129 * V_130 ;
struct V_52 * V_53 ;
V_53 = F_38 ( F_39 ( V_4 ) ) ;
V_130 = F_116 ( V_15 -> V_112 , V_18 , V_53 ) ;
F_140 ( V_15 -> V_112 , V_130 , NULL , V_18 , V_53 -> V_97 . V_45 , 0 ) ;
F_125 ( V_15 -> V_112 ) ;
}
int F_165 ( struct V_112 * V_112 , unsigned long V_163 , unsigned long V_164 )
{
if ( ! V_35 && ! V_5 )
return F_150 ( V_112 , V_163 , V_164 , 0 ,
F_140 ) ;
return F_150 ( V_112 , V_163 , V_164 , 0 , F_161 ) ;
}
int F_166 ( struct V_112 * V_112 , unsigned long V_174 )
{
return F_157 ( V_112 , V_174 , 0 , F_163 ) ;
}
static int F_167 ( T_1 * V_140 )
{
T_1 * V_143 ;
T_1 * V_164 ;
for ( V_143 = V_140 , V_164 = V_143 + V_173 / sizeof( T_1 ) ; V_143 != V_164 ; V_143 ++ )
if ( F_24 ( * V_143 ) ) {
F_112 ( V_138 L_16 , V_150 ,
V_143 , * V_143 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_168 ( struct V_112 * V_112 , int V_177 )
{
V_112 -> V_40 . V_178 += V_177 ;
F_169 ( & V_179 , V_177 ) ;
}
static void F_170 ( struct V_52 * V_53 )
{
F_171 ( ! F_167 ( V_53 -> V_140 ) ) ;
F_172 ( & V_53 -> V_180 ) ;
F_173 ( & V_53 -> V_181 ) ;
F_79 ( ( unsigned long ) V_53 -> V_140 ) ;
if ( ! V_53 -> V_97 . V_98 )
F_79 ( ( unsigned long ) V_53 -> V_99 ) ;
F_75 ( V_93 , V_53 ) ;
}
static unsigned F_174 ( T_2 V_18 )
{
return F_175 ( V_18 , V_182 ) ;
}
static void F_176 ( struct V_14 * V_15 ,
struct V_52 * V_53 , T_1 * V_183 )
{
if ( ! V_183 )
return;
F_108 ( V_15 , V_183 , & V_53 -> V_184 ) ;
}
static void F_177 ( struct V_52 * V_53 ,
T_1 * V_183 )
{
F_111 ( V_183 , & V_53 -> V_184 ) ;
}
static void F_178 ( struct V_52 * V_53 ,
T_1 * V_183 )
{
F_177 ( V_53 , V_183 ) ;
F_55 ( V_183 ) ;
}
static struct V_52 * F_179 ( struct V_14 * V_15 , int V_98 )
{
struct V_52 * V_53 ;
V_53 = F_82 ( & V_15 -> V_40 . V_93 ) ;
V_53 -> V_140 = F_82 ( & V_15 -> V_40 . V_92 ) ;
if ( ! V_98 )
V_53 -> V_99 = F_82 ( & V_15 -> V_40 . V_92 ) ;
F_180 ( F_181 ( V_53 -> V_140 ) , ( unsigned long ) V_53 ) ;
F_182 ( & V_53 -> V_181 , & V_15 -> V_112 -> V_40 . V_185 ) ;
F_168 ( V_15 -> V_112 , + 1 ) ;
return V_53 ;
}
static void F_183 ( struct V_52 * V_53 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
F_128 (&sp->parent_ptes, &iter, sptep) {
F_184 ( V_17 ) ;
}
}
static void F_184 ( T_1 * V_4 )
{
struct V_52 * V_53 ;
unsigned int V_96 ;
V_53 = F_38 ( F_39 ( V_4 ) ) ;
V_96 = V_4 - V_53 -> V_140 ;
if ( F_185 ( V_96 , V_53 -> V_186 ) )
return;
if ( V_53 -> V_187 ++ )
return;
F_183 ( V_53 ) ;
}
static int F_186 ( struct V_14 * V_15 ,
struct V_52 * V_53 )
{
return 0 ;
}
static void F_187 ( struct V_14 * V_15 , T_6 V_188 )
{
}
static void F_188 ( struct V_14 * V_15 ,
struct V_52 * V_53 , T_1 * V_4 ,
const void * V_43 )
{
F_4 ( 1 ) ;
}
static int F_189 ( struct V_189 * V_190 , struct V_52 * V_53 ,
int V_104 )
{
int V_108 ;
if ( V_53 -> V_191 )
for ( V_108 = 0 ; V_108 < V_190 -> V_177 ; V_108 ++ )
if ( V_190 -> V_86 [ V_108 ] . V_53 == V_53 )
return 0 ;
V_190 -> V_86 [ V_190 -> V_177 ] . V_53 = V_53 ;
V_190 -> V_86 [ V_190 -> V_177 ] . V_104 = V_104 ;
V_190 -> V_177 ++ ;
return ( V_190 -> V_177 == V_192 ) ;
}
static inline void F_190 ( struct V_52 * V_53 , int V_104 )
{
-- V_53 -> V_187 ;
F_4 ( ( int ) V_53 -> V_187 < 0 ) ;
F_191 ( V_104 , V_53 -> V_186 ) ;
}
static int F_192 ( struct V_52 * V_53 ,
struct V_189 * V_190 )
{
int V_108 , V_118 , V_193 = 0 ;
F_193 (i, sp->unsync_child_bitmap, 512 ) {
struct V_52 * V_194 ;
T_1 V_195 = V_53 -> V_140 [ V_108 ] ;
if ( ! F_24 ( V_195 ) || F_25 ( V_195 ) ) {
F_190 ( V_53 , V_108 ) ;
continue;
}
V_194 = F_38 ( V_195 & V_47 ) ;
if ( V_194 -> V_187 ) {
if ( F_189 ( V_190 , V_194 , V_108 ) )
return - V_196 ;
V_118 = F_192 ( V_194 , V_190 ) ;
if ( ! V_118 ) {
F_190 ( V_53 , V_108 ) ;
continue;
} else if ( V_118 > 0 ) {
V_193 += V_118 ;
} else
return V_118 ;
} else if ( V_194 -> V_191 ) {
V_193 ++ ;
if ( F_189 ( V_190 , V_194 , V_108 ) )
return - V_196 ;
} else
F_190 ( V_53 , V_108 ) ;
}
return V_193 ;
}
static int F_194 ( struct V_52 * V_53 ,
struct V_189 * V_190 )
{
V_190 -> V_177 = 0 ;
if ( ! V_53 -> V_187 )
return 0 ;
F_189 ( V_190 , V_53 , V_197 ) ;
return F_192 ( V_53 , V_190 ) ;
}
static void F_195 ( struct V_112 * V_112 , struct V_52 * V_53 )
{
F_4 ( ! V_53 -> V_191 ) ;
F_196 ( V_53 ) ;
V_53 -> V_191 = 0 ;
-- V_112 -> V_144 . V_198 ;
}
static bool F_197 ( struct V_14 * V_15 , struct V_52 * V_53 ,
struct V_199 * V_200 )
{
if ( V_53 -> V_97 . V_201 != ! ! F_198 ( V_15 ) ) {
F_199 ( V_15 -> V_112 , V_53 , V_200 ) ;
return false ;
}
if ( V_15 -> V_40 . V_202 . V_203 ( V_15 , V_53 ) == 0 ) {
F_199 ( V_15 -> V_112 , V_53 , V_200 ) ;
return false ;
}
return true ;
}
static void F_200 ( struct V_14 * V_15 ,
struct V_199 * V_200 ,
bool V_204 , bool V_205 )
{
if ( ! F_201 ( V_200 ) ) {
F_202 ( V_15 -> V_112 , V_200 ) ;
return;
}
if ( V_204 )
F_125 ( V_15 -> V_112 ) ;
else if ( V_205 )
F_203 ( V_206 , V_15 ) ;
}
static void F_204 ( struct V_14 * V_15 , int V_207 ) { }
static void F_205 ( void ) { }
static bool F_206 ( struct V_112 * V_112 , struct V_52 * V_53 )
{
return F_15 ( V_53 -> V_208 != V_112 -> V_40 . V_208 ) ;
}
static bool F_207 ( struct V_14 * V_15 , struct V_52 * V_53 ,
struct V_199 * V_200 )
{
F_195 ( V_15 -> V_112 , V_53 ) ;
return F_197 ( V_15 , V_53 , V_200 ) ;
}
static bool F_208 ( struct V_14 * V_15 , T_2 V_18 ,
struct V_199 * V_200 )
{
struct V_52 * V_209 ;
bool V_118 = false ;
F_209 (vcpu->kvm, s, gfn) {
if ( ! V_209 -> V_191 )
continue;
F_4 ( V_209 -> V_97 . V_45 != V_46 ) ;
V_118 |= F_207 ( V_15 , V_209 , V_200 ) ;
}
return V_118 ;
}
static int F_210 ( struct V_189 * V_190 ,
struct V_210 * V_211 ,
int V_108 )
{
int V_212 ;
for ( V_212 = V_108 + 1 ; V_212 < V_190 -> V_177 ; V_212 ++ ) {
struct V_52 * V_53 = V_190 -> V_86 [ V_212 ] . V_53 ;
unsigned V_104 = V_190 -> V_86 [ V_212 ] . V_104 ;
int V_45 = V_53 -> V_97 . V_45 ;
V_211 -> V_104 [ V_45 - 1 ] = V_104 ;
if ( V_45 == V_46 )
break;
V_211 -> V_213 [ V_45 - 2 ] = V_53 ;
}
return V_212 ;
}
static int F_211 ( struct V_189 * V_190 ,
struct V_210 * V_211 )
{
struct V_52 * V_53 ;
int V_45 ;
if ( V_190 -> V_177 == 0 )
return 0 ;
F_4 ( V_190 -> V_86 [ 0 ] . V_104 != V_197 ) ;
V_53 = V_190 -> V_86 [ 0 ] . V_53 ;
V_45 = V_53 -> V_97 . V_45 ;
F_4 ( V_45 == V_46 ) ;
V_211 -> V_213 [ V_45 - 2 ] = V_53 ;
V_211 -> V_213 [ V_45 - 1 ] = NULL ;
return F_210 ( V_190 , V_211 , 0 ) ;
}
static void F_212 ( struct V_210 * V_211 )
{
struct V_52 * V_53 ;
unsigned int V_45 = 0 ;
do {
unsigned int V_104 = V_211 -> V_104 [ V_45 ] ;
V_53 = V_211 -> V_213 [ V_45 ] ;
if ( ! V_53 )
return;
F_4 ( V_104 == V_197 ) ;
F_190 ( V_53 , V_104 ) ;
V_45 ++ ;
} while ( ! V_53 -> V_187 );
}
static void F_213 ( struct V_14 * V_15 ,
struct V_52 * V_213 )
{
int V_108 ;
struct V_52 * V_53 ;
struct V_210 V_211 ;
struct V_189 V_214 ;
F_214 ( V_200 ) ;
bool V_68 = false ;
while ( F_194 ( V_213 , & V_214 ) ) {
bool V_215 = false ;
F_215 (pages, sp, parents, i)
V_215 |= F_138 ( V_15 , V_53 -> V_18 ) ;
if ( V_215 ) {
F_125 ( V_15 -> V_112 ) ;
V_68 = false ;
}
F_215 (pages, sp, parents, i) {
V_68 |= F_207 ( V_15 , V_53 , & V_200 ) ;
F_212 ( & V_211 ) ;
}
if ( F_216 () || F_217 ( & V_15 -> V_112 -> V_216 ) ) {
F_200 ( V_15 , & V_200 , false , V_68 ) ;
F_218 ( & V_15 -> V_112 -> V_216 ) ;
V_68 = false ;
}
}
F_200 ( V_15 , & V_200 , false , V_68 ) ;
}
static void F_219 ( struct V_52 * V_53 )
{
F_220 ( & V_53 -> V_217 , 0 ) ;
}
static void F_221 ( T_1 * V_4 )
{
struct V_52 * V_53 = F_38 ( F_39 ( V_4 ) ) ;
F_219 ( V_53 ) ;
}
static struct V_52 * F_222 ( struct V_14 * V_15 ,
T_2 V_18 ,
T_6 V_218 ,
unsigned V_45 ,
int V_98 ,
unsigned V_19 )
{
union V_219 V_97 ;
unsigned V_220 ;
struct V_52 * V_53 ;
bool V_221 = false ;
bool V_68 = false ;
int V_222 = 0 ;
F_214 ( V_200 ) ;
V_97 = V_15 -> V_40 . V_202 . V_223 ;
V_97 . V_45 = V_45 ;
V_97 . V_98 = V_98 ;
if ( V_97 . V_98 )
V_97 . V_201 = 0 ;
V_97 . V_19 = V_19 ;
if ( ! V_15 -> V_40 . V_202 . V_224
&& V_15 -> V_40 . V_202 . V_225 <= V_226 ) {
V_220 = V_218 >> ( V_22 + ( V_227 * V_45 ) ) ;
V_220 &= ( 1 << ( ( V_228 - V_227 ) * V_45 ) ) - 1 ;
V_97 . V_220 = V_220 ;
}
F_223 (vcpu->kvm, sp, gfn) {
if ( V_53 -> V_18 != V_18 ) {
V_222 ++ ;
continue;
}
if ( ! V_221 && V_53 -> V_191 )
V_221 = true ;
if ( V_53 -> V_97 . V_229 != V_97 . V_229 )
continue;
if ( V_53 -> V_191 ) {
if ( ! F_197 ( V_15 , V_53 , & V_200 ) )
break;
F_4 ( ! F_201 ( & V_200 ) ) ;
F_203 ( V_206 , V_15 ) ;
}
if ( V_53 -> V_187 )
F_203 ( V_230 , V_15 ) ;
F_219 ( V_53 ) ;
F_224 ( V_53 , false ) ;
goto V_91;
}
++ V_15 -> V_112 -> V_144 . V_231 ;
V_53 = F_179 ( V_15 , V_98 ) ;
V_53 -> V_18 = V_18 ;
V_53 -> V_97 = V_97 ;
F_225 ( & V_53 -> V_180 ,
& V_15 -> V_112 -> V_40 . V_232 [ F_174 ( V_18 ) ] ) ;
if ( ! V_98 ) {
F_93 ( V_15 -> V_112 , V_53 ) ;
if ( V_45 == V_46 &&
F_138 ( V_15 , V_18 ) )
F_125 ( V_15 -> V_112 ) ;
if ( V_45 > V_46 && V_221 )
V_68 |= F_208 ( V_15 , V_18 , & V_200 ) ;
}
V_53 -> V_208 = V_15 -> V_112 -> V_40 . V_208 ;
F_226 ( V_53 -> V_140 ) ;
F_224 ( V_53 , true ) ;
F_200 ( V_15 , & V_200 , false , V_68 ) ;
V_91:
if ( V_222 > V_15 -> V_112 -> V_144 . V_233 )
V_15 -> V_112 -> V_144 . V_233 = V_222 ;
return V_53 ;
}
static void F_227 ( struct V_234 * V_157 ,
struct V_14 * V_15 , T_1 V_235 )
{
V_157 -> V_235 = V_235 ;
V_157 -> V_236 = V_15 -> V_40 . V_202 . V_237 ;
V_157 -> V_45 = V_15 -> V_40 . V_202 . V_238 ;
if ( V_157 -> V_45 == V_239 &&
V_15 -> V_40 . V_202 . V_225 < V_239 &&
! V_15 -> V_40 . V_202 . V_224 )
-- V_157 -> V_45 ;
if ( V_157 -> V_45 == V_240 ) {
V_157 -> V_236
= V_15 -> V_40 . V_202 . V_241 [ ( V_235 >> 30 ) & 3 ] ;
V_157 -> V_236 &= V_47 ;
-- V_157 -> V_45 ;
if ( ! V_157 -> V_236 )
V_157 -> V_45 = 0 ;
}
}
static bool F_228 ( struct V_234 * V_157 )
{
if ( V_157 -> V_45 < V_46 )
return false ;
V_157 -> V_96 = F_229 ( V_157 -> V_235 , V_157 -> V_45 ) ;
V_157 -> V_17 = ( ( T_1 * ) F_230 ( V_157 -> V_236 ) ) + V_157 -> V_96 ;
return true ;
}
static void F_231 ( struct V_234 * V_157 ,
T_1 V_4 )
{
if ( F_26 ( V_4 , V_157 -> V_45 ) ) {
V_157 -> V_45 = 0 ;
return;
}
V_157 -> V_236 = V_4 & V_47 ;
-- V_157 -> V_45 ;
}
static void F_232 ( struct V_234 * V_157 )
{
return F_231 ( V_157 , * V_157 -> V_17 ) ;
}
static void F_233 ( struct V_14 * V_15 , T_1 * V_17 ,
struct V_52 * V_53 )
{
T_1 V_4 ;
F_234 ( V_242 != V_65 ) ;
V_4 = F_39 ( V_53 -> V_140 ) | V_39 | V_65 |
V_34 | V_38 | V_35 ;
F_10 ( V_17 , V_4 ) ;
F_176 ( V_15 , V_53 , V_17 ) ;
if ( V_53 -> V_187 || V_53 -> V_191 )
F_184 ( V_17 ) ;
}
static void F_235 ( struct V_14 * V_15 , T_1 * V_17 ,
unsigned V_243 )
{
if ( F_24 ( * V_17 ) && ! F_25 ( * V_17 ) ) {
struct V_52 * V_194 ;
V_194 = F_38 ( * V_17 & V_47 ) ;
if ( V_194 -> V_97 . V_19 == V_243 )
return;
F_178 ( V_194 , V_17 ) ;
F_125 ( V_15 -> V_112 ) ;
}
}
static bool F_236 ( struct V_112 * V_112 , struct V_52 * V_53 ,
T_1 * V_4 )
{
T_1 V_43 ;
struct V_52 * V_194 ;
V_43 = * V_4 ;
if ( F_24 ( V_43 ) ) {
if ( F_26 ( V_43 , V_53 -> V_97 . V_45 ) ) {
F_122 ( V_112 , V_4 ) ;
if ( F_25 ( V_43 ) )
-- V_112 -> V_144 . V_145 ;
} else {
V_194 = F_38 ( V_43 & V_47 ) ;
F_178 ( V_194 , V_4 ) ;
}
return true ;
}
if ( F_11 ( V_43 ) )
F_55 ( V_4 ) ;
return false ;
}
static void F_237 ( struct V_112 * V_112 ,
struct V_52 * V_53 )
{
unsigned V_108 ;
for ( V_108 = 0 ; V_108 < V_244 ; ++ V_108 )
F_236 ( V_112 , V_53 , V_53 -> V_140 + V_108 ) ;
}
static void F_238 ( struct V_112 * V_112 , struct V_52 * V_53 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
while ( ( V_17 = F_120 ( & V_53 -> V_184 , & V_142 ) ) )
F_178 ( V_53 , V_17 ) ;
}
static int F_239 ( struct V_112 * V_112 ,
struct V_52 * V_213 ,
struct V_199 * V_200 )
{
int V_108 , V_245 = 0 ;
struct V_210 V_211 ;
struct V_189 V_214 ;
if ( V_213 -> V_97 . V_45 == V_46 )
return 0 ;
while ( F_194 ( V_213 , & V_214 ) ) {
struct V_52 * V_53 ;
F_215 (pages, sp, parents, i) {
F_199 ( V_112 , V_53 , V_200 ) ;
F_212 ( & V_211 ) ;
V_245 ++ ;
}
}
return V_245 ;
}
static int F_199 ( struct V_112 * V_112 , struct V_52 * V_53 ,
struct V_199 * V_200 )
{
int V_118 ;
F_240 ( V_53 ) ;
++ V_112 -> V_144 . V_246 ;
V_118 = F_239 ( V_112 , V_53 , V_200 ) ;
F_237 ( V_112 , V_53 ) ;
F_238 ( V_112 , V_53 ) ;
if ( ! V_53 -> V_97 . V_247 && ! V_53 -> V_97 . V_98 )
F_97 ( V_112 , V_53 ) ;
if ( V_53 -> V_191 )
F_195 ( V_112 , V_53 ) ;
if ( ! V_53 -> V_248 ) {
V_118 ++ ;
F_241 ( & V_53 -> V_181 , V_200 ) ;
F_168 ( V_112 , - 1 ) ;
} else {
F_241 ( & V_53 -> V_181 , & V_112 -> V_40 . V_185 ) ;
if ( ! V_53 -> V_97 . V_247 && ! F_206 ( V_112 , V_53 ) )
F_242 ( V_112 ) ;
}
V_53 -> V_97 . V_247 = 1 ;
return V_118 ;
}
static void F_202 ( struct V_112 * V_112 ,
struct V_199 * V_200 )
{
struct V_52 * V_53 , * V_249 ;
if ( F_201 ( V_200 ) )
return;
F_125 ( V_112 ) ;
F_243 (sp, nsp, invalid_list, link) {
F_4 ( ! V_53 -> V_97 . V_247 || V_53 -> V_248 ) ;
F_170 ( V_53 ) ;
}
}
static bool F_244 ( struct V_112 * V_112 ,
struct V_199 * V_200 )
{
struct V_52 * V_53 ;
if ( F_201 ( & V_112 -> V_40 . V_185 ) )
return false ;
V_53 = F_245 ( & V_112 -> V_40 . V_185 ,
struct V_52 , V_181 ) ;
F_199 ( V_112 , V_53 , V_200 ) ;
return true ;
}
void F_246 ( struct V_112 * V_112 , unsigned int V_250 )
{
F_214 ( V_200 ) ;
F_247 ( & V_112 -> V_216 ) ;
if ( V_112 -> V_40 . V_178 > V_250 ) {
while ( V_112 -> V_40 . V_178 > V_250 )
if ( ! F_244 ( V_112 , & V_200 ) )
break;
F_202 ( V_112 , & V_200 ) ;
V_250 = V_112 -> V_40 . V_178 ;
}
V_112 -> V_40 . V_251 = V_250 ;
F_248 ( & V_112 -> V_216 ) ;
}
int F_249 ( struct V_112 * V_112 , T_2 V_18 )
{
struct V_52 * V_53 ;
F_214 ( V_200 ) ;
int V_87 ;
F_250 ( L_17 , V_150 , V_18 ) ;
V_87 = 0 ;
F_247 ( & V_112 -> V_216 ) ;
F_209 (kvm, sp, gfn) {
F_250 ( L_18 , V_150 , V_18 ,
V_53 -> V_97 . V_229 ) ;
V_87 = 1 ;
F_199 ( V_112 , V_53 , & V_200 ) ;
}
F_202 ( V_112 , & V_200 ) ;
F_248 ( & V_112 -> V_216 ) ;
return V_87 ;
}
static void F_251 ( struct V_14 * V_15 , struct V_52 * V_53 )
{
F_252 ( V_53 ) ;
++ V_15 -> V_112 -> V_144 . V_198 ;
V_53 -> V_191 = 1 ;
F_183 ( V_53 ) ;
}
static bool F_253 ( struct V_14 * V_15 , T_2 V_18 ,
bool V_252 )
{
struct V_52 * V_53 ;
if ( F_254 ( V_15 , V_18 , V_116 ) )
return true ;
F_209 (vcpu->kvm, sp, gfn) {
if ( ! V_252 )
return true ;
if ( V_53 -> V_191 )
continue;
F_4 ( V_53 -> V_97 . V_45 != V_46 ) ;
F_251 ( V_15 , V_53 ) ;
}
return false ;
}
static bool F_255 ( T_3 V_24 )
{
if ( F_256 ( V_24 ) )
return ! F_257 ( V_24 ) && F_258 ( F_54 ( V_24 ) ) ;
return true ;
}
static int F_259 ( struct V_14 * V_15 , T_1 * V_17 ,
unsigned V_253 , int V_45 ,
T_2 V_18 , T_3 V_24 , bool V_254 ,
bool V_252 , bool V_255 )
{
T_1 V_4 = 0 ;
int V_118 = 0 ;
if ( F_14 ( V_15 , V_17 , V_18 , V_24 , V_253 ) )
return 0 ;
V_4 |= V_39 ;
if ( ! V_254 )
V_4 |= V_35 ;
if ( V_253 & V_256 )
V_4 |= V_38 ;
else
V_4 |= V_37 ;
if ( V_253 & V_21 )
V_4 |= V_34 ;
if ( V_45 > V_46 )
V_4 |= V_44 ;
if ( V_257 )
V_4 |= V_127 -> V_258 ( V_15 , V_18 ,
F_255 ( V_24 ) ) ;
if ( V_255 )
V_4 |= V_63 ;
else
V_253 &= ~ V_20 ;
V_4 |= ( T_1 ) V_24 << V_22 ;
if ( V_253 & V_20 ) {
if ( V_45 > V_46 &&
F_100 ( V_15 , V_18 , V_45 ) )
goto V_259;
V_4 |= V_65 | V_64 ;
if ( ! V_252 && F_44 ( * V_17 ) )
goto V_260;
if ( F_253 ( V_15 , V_18 , V_252 ) ) {
F_250 ( L_19 ,
V_150 , V_18 ) ;
V_118 = 1 ;
V_253 &= ~ V_20 ;
V_4 &= ~ ( V_65 | V_64 ) ;
}
}
if ( V_253 & V_20 ) {
F_260 ( V_15 , V_18 ) ;
V_4 |= V_36 ;
}
if ( V_254 )
V_4 = F_57 ( V_4 ) ;
V_260:
if ( F_48 ( V_17 , V_4 ) )
F_125 ( V_15 -> V_112 ) ;
V_259:
return V_118 ;
}
static bool F_261 ( struct V_14 * V_15 , T_1 * V_17 , unsigned V_253 ,
int V_261 , int V_45 , T_2 V_18 , T_3 V_24 ,
bool V_254 , bool V_255 )
{
int V_262 = 0 ;
int V_263 ;
bool V_264 = false ;
F_250 ( L_20 , V_150 ,
* V_17 , V_261 , V_18 ) ;
if ( F_24 ( * V_17 ) ) {
if ( V_45 > V_46 &&
! F_25 ( * V_17 ) ) {
struct V_52 * V_194 ;
T_1 V_43 = * V_17 ;
V_194 = F_38 ( V_43 & V_47 ) ;
F_178 ( V_194 , V_17 ) ;
F_125 ( V_15 -> V_112 ) ;
} else if ( V_24 != F_28 ( * V_17 ) ) {
F_250 ( L_21 ,
F_28 ( * V_17 ) , V_24 ) ;
F_122 ( V_15 -> V_112 , V_17 ) ;
F_125 ( V_15 -> V_112 ) ;
} else
V_262 = 1 ;
}
if ( F_259 ( V_15 , V_17 , V_253 , V_45 , V_18 , V_24 , V_254 ,
true , V_255 ) ) {
if ( V_261 )
V_264 = true ;
F_203 ( V_206 , V_15 ) ;
}
if ( F_15 ( F_11 ( * V_17 ) ) )
V_264 = true ;
F_250 ( L_22 , V_150 , * V_17 ) ;
F_250 ( L_23 ,
F_25 ( * V_17 ) ? L_24 : L_25 ,
* V_17 & V_65 ? L_26 : L_27 , V_18 ,
* V_17 , V_17 ) ;
if ( ! V_262 && F_25 ( * V_17 ) )
++ V_15 -> V_112 -> V_144 . V_145 ;
if ( F_24 ( * V_17 ) ) {
if ( ! V_262 ) {
V_263 = F_118 ( V_15 , V_17 , V_18 ) ;
if ( V_263 > V_265 )
F_164 ( V_15 , V_17 , V_18 ) ;
}
}
F_262 ( V_24 ) ;
return V_264 ;
}
static T_3 F_263 ( struct V_14 * V_15 , T_2 V_18 ,
bool V_119 )
{
struct V_102 * V_103 ;
V_103 = F_106 ( V_15 , V_18 , V_119 ) ;
if ( ! V_103 )
return V_266 ;
return F_264 ( V_103 , V_18 ) ;
}
static int F_265 ( struct V_14 * V_15 ,
struct V_52 * V_53 ,
T_1 * V_163 , T_1 * V_164 )
{
struct V_86 * V_214 [ V_90 ] ;
struct V_102 * V_103 ;
unsigned V_19 = V_53 -> V_97 . V_19 ;
int V_108 , V_118 ;
T_2 V_18 ;
V_18 = F_86 ( V_53 , V_163 - V_53 -> V_140 ) ;
V_103 = F_106 ( V_15 , V_18 , V_19 & V_20 ) ;
if ( ! V_103 )
return - 1 ;
V_118 = F_266 ( V_103 , V_18 , V_214 , V_164 - V_163 ) ;
if ( V_118 <= 0 )
return - 1 ;
for ( V_108 = 0 ; V_108 < V_118 ; V_108 ++ , V_18 ++ , V_163 ++ )
F_261 ( V_15 , V_163 , V_19 , 0 , V_53 -> V_97 . V_45 , V_18 ,
F_267 ( V_214 [ V_108 ] ) , true , true ) ;
return 0 ;
}
static void F_268 ( struct V_14 * V_15 ,
struct V_52 * V_53 , T_1 * V_17 )
{
T_1 * V_4 , * V_163 = NULL ;
int V_108 ;
F_4 ( ! V_53 -> V_97 . V_98 ) ;
V_108 = ( V_17 - V_53 -> V_140 ) & ~ ( V_90 - 1 ) ;
V_4 = V_53 -> V_140 + V_108 ;
for ( V_108 = 0 ; V_108 < V_90 ; V_108 ++ , V_4 ++ ) {
if ( F_24 ( * V_4 ) || V_4 == V_17 ) {
if ( ! V_163 )
continue;
if ( F_265 ( V_15 , V_53 , V_163 , V_4 ) < 0 )
break;
V_163 = NULL ;
} else if ( ! V_163 )
V_163 = V_4 ;
}
}
static void F_269 ( struct V_14 * V_15 , T_1 * V_17 )
{
struct V_52 * V_53 ;
if ( ! V_35 )
return;
V_53 = F_38 ( F_39 ( V_17 ) ) ;
if ( V_53 -> V_97 . V_45 > V_46 )
return;
F_268 ( V_15 , V_53 , V_17 ) ;
}
static int F_270 ( struct V_14 * V_15 , int V_267 , int V_268 ,
int V_45 , T_2 V_18 , T_3 V_24 , bool V_269 )
{
struct V_234 V_157 ;
struct V_52 * V_53 ;
int V_264 = 0 ;
T_2 V_270 ;
if ( ! F_271 ( V_15 -> V_40 . V_202 . V_237 ) )
return 0 ;
F_272 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_157 . V_45 == V_45 ) {
V_264 = F_261 ( V_15 , V_157 . V_17 , V_271 ,
V_267 , V_45 , V_18 , V_24 , V_269 ,
V_268 ) ;
F_269 ( V_15 , V_157 . V_17 ) ;
++ V_15 -> V_144 . V_272 ;
break;
}
F_124 ( V_15 , V_157 . V_17 ) ;
if ( ! F_24 ( * V_157 . V_17 ) ) {
T_1 V_273 = V_157 . V_235 ;
V_273 &= F_273 ( V_157 . V_45 ) ;
V_270 = V_273 >> V_22 ;
V_53 = F_222 ( V_15 , V_270 , V_157 . V_235 ,
V_157 . V_45 - 1 , 1 , V_271 ) ;
F_233 ( V_15 , V_157 . V_17 , V_53 ) ;
}
}
return V_264 ;
}
static void F_274 ( unsigned long V_274 , struct V_275 * V_276 )
{
T_7 V_277 ;
V_277 . V_278 = V_279 ;
V_277 . V_280 = 0 ;
V_277 . V_281 = V_282 ;
V_277 . V_283 = ( void V_284 * ) V_274 ;
V_277 . V_285 = V_22 ;
F_275 ( V_279 , & V_277 , V_276 ) ;
}
static int F_276 ( struct V_14 * V_15 , T_2 V_18 , T_3 V_24 )
{
if ( V_24 == V_286 )
return 1 ;
if ( V_24 == V_287 ) {
F_274 ( F_277 ( V_15 , V_18 ) , V_288 ) ;
return 0 ;
}
return - V_289 ;
}
static void F_278 ( struct V_14 * V_15 ,
T_2 * V_290 , T_3 * V_291 ,
int * V_292 )
{
T_3 V_24 = * V_291 ;
T_2 V_18 = * V_290 ;
int V_45 = * V_292 ;
if ( ! F_279 ( V_24 ) && ! F_52 ( V_24 ) &&
V_45 == V_46 &&
F_280 ( F_54 ( V_24 ) ) &&
! F_100 ( V_15 , V_18 , V_109 ) ) {
unsigned long V_8 ;
* V_292 = V_45 = V_109 ;
V_8 = F_281 ( V_45 ) - 1 ;
F_282 ( ( V_18 & V_8 ) != ( V_24 & V_8 ) ) ;
if ( V_24 & V_8 ) {
V_18 &= ~ V_8 ;
* V_290 = V_18 ;
F_262 ( V_24 ) ;
V_24 &= ~ V_8 ;
F_283 ( V_24 ) ;
* V_291 = V_24 ;
}
}
}
static bool F_284 ( struct V_14 * V_15 , T_6 V_188 , T_2 V_18 ,
T_3 V_24 , unsigned V_19 , int * V_293 )
{
if ( F_15 ( F_285 ( V_24 ) ) ) {
* V_293 = F_276 ( V_15 , V_18 , V_24 ) ;
return true ;
}
if ( F_15 ( F_16 ( V_24 ) ) )
F_286 ( V_15 , V_188 , V_18 , V_19 ) ;
return false ;
}
static bool F_287 ( T_4 V_294 )
{
if ( F_15 ( V_294 & V_295 ) )
return false ;
if ( F_15 ( ( ( V_294 & ( V_296 | V_297 ) )
== ( V_296 | V_297 ) ) ) )
return false ;
return V_5 != 0 ||
( ( V_294 & ( V_298 | V_297 ) )
== ( V_298 | V_297 ) ) ;
}
static bool
F_288 ( struct V_14 * V_15 , struct V_52 * V_53 ,
T_1 * V_17 , T_1 V_67 , T_1 V_66 )
{
T_2 V_18 ;
F_4 ( ! V_53 -> V_97 . V_98 ) ;
if ( F_289 ( V_17 , V_67 , V_66 ) != V_67 )
return false ;
if ( F_44 ( V_66 ) && ! F_44 ( V_67 ) ) {
V_18 = F_86 ( V_53 , V_17 - V_53 -> V_140 ) ;
F_260 ( V_15 , V_18 ) ;
}
return true ;
}
static bool F_290 ( T_4 V_299 , T_1 V_4 )
{
if ( V_299 & V_296 )
return F_27 ( V_4 ) ;
if ( V_299 & V_298 )
return F_44 ( V_4 ) ;
return V_4 & V_300 ;
}
static bool F_291 ( struct V_14 * V_15 , T_6 V_188 , int V_45 ,
T_4 V_294 )
{
struct V_234 V_157 ;
struct V_52 * V_53 ;
bool V_301 = false ;
T_1 V_4 = 0ull ;
T_8 V_302 = 0 ;
if ( ! F_271 ( V_15 -> V_40 . V_202 . V_237 ) )
return false ;
if ( ! F_287 ( V_294 ) )
return false ;
F_64 ( V_15 ) ;
do {
T_1 V_66 ;
F_292 (vcpu, gva, iterator, spte)
if ( ! F_24 ( V_4 ) ||
V_157 . V_45 < V_45 )
break;
V_53 = F_38 ( F_39 ( V_157 . V_17 ) ) ;
if ( ! F_26 ( V_4 , V_53 -> V_97 . V_45 ) )
break;
if ( F_290 ( V_294 , V_4 ) ) {
V_301 = true ;
break;
}
V_66 = V_4 ;
if ( F_2 ( V_4 ) )
V_66 = F_59 ( V_66 ) ;
if ( ( V_294 & V_298 ) &&
F_42 ( V_4 ) )
{
V_66 |= V_65 ;
if ( V_53 -> V_97 . V_45 > V_46 )
break;
}
if ( V_66 == V_4 ||
! F_290 ( V_294 , V_66 ) )
break;
V_301 = F_288 ( V_15 , V_53 ,
V_157 . V_17 , V_4 ,
V_66 ) ;
if ( V_301 )
break;
if ( ++ V_302 > 4 ) {
F_293 ( V_303
L_28 ) ;
break;
}
} while ( true );
F_294 ( V_15 , V_188 , V_294 , V_157 . V_17 ,
V_4 , V_301 ) ;
F_67 ( V_15 ) ;
return V_301 ;
}
static int F_295 ( struct V_14 * V_15 , T_6 V_304 , T_4 V_294 ,
T_2 V_18 , bool V_269 )
{
int V_87 ;
int V_45 ;
bool V_124 = false ;
T_3 V_24 ;
unsigned long V_305 ;
bool V_268 , V_267 = V_294 & V_298 ;
V_45 = F_107 ( V_15 , V_18 , & V_124 ) ;
if ( F_19 ( ! V_124 ) ) {
if ( V_45 > V_109 )
V_45 = V_109 ;
V_18 &= ~ ( F_281 ( V_45 ) - 1 ) ;
}
if ( F_291 ( V_15 , V_304 , V_45 , V_294 ) )
return 0 ;
V_305 = V_15 -> V_112 -> V_306 ;
F_41 () ;
if ( F_296 ( V_15 , V_269 , V_18 , V_304 , & V_24 , V_267 , & V_268 ) )
return 0 ;
if ( F_284 ( V_15 , V_304 , V_18 , V_24 , V_271 , & V_87 ) )
return V_87 ;
F_247 ( & V_15 -> V_112 -> V_216 ) ;
if ( F_297 ( V_15 -> V_112 , V_305 ) )
goto V_307;
F_298 ( V_15 ) ;
if ( F_19 ( ! V_124 ) )
F_278 ( V_15 , & V_18 , & V_24 , & V_45 ) ;
V_87 = F_270 ( V_15 , V_267 , V_268 , V_45 , V_18 , V_24 , V_269 ) ;
F_248 ( & V_15 -> V_112 -> V_216 ) ;
return V_87 ;
V_307:
F_248 ( & V_15 -> V_112 -> V_216 ) ;
F_262 ( V_24 ) ;
return 0 ;
}
static void F_299 ( struct V_14 * V_15 )
{
int V_108 ;
struct V_52 * V_53 ;
F_214 ( V_200 ) ;
if ( ! F_271 ( V_15 -> V_40 . V_202 . V_237 ) )
return;
if ( V_15 -> V_40 . V_202 . V_238 == V_239 &&
( V_15 -> V_40 . V_202 . V_225 == V_239 ||
V_15 -> V_40 . V_202 . V_224 ) ) {
T_9 V_308 = V_15 -> V_40 . V_202 . V_237 ;
F_247 ( & V_15 -> V_112 -> V_216 ) ;
V_53 = F_38 ( V_308 ) ;
-- V_53 -> V_248 ;
if ( ! V_53 -> V_248 && V_53 -> V_97 . V_247 ) {
F_199 ( V_15 -> V_112 , V_53 , & V_200 ) ;
F_202 ( V_15 -> V_112 , & V_200 ) ;
}
F_248 ( & V_15 -> V_112 -> V_216 ) ;
V_15 -> V_40 . V_202 . V_237 = V_309 ;
return;
}
F_247 ( & V_15 -> V_112 -> V_216 ) ;
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
T_9 V_308 = V_15 -> V_40 . V_202 . V_241 [ V_108 ] ;
if ( V_308 ) {
V_308 &= V_47 ;
V_53 = F_38 ( V_308 ) ;
-- V_53 -> V_248 ;
if ( ! V_53 -> V_248 && V_53 -> V_97 . V_247 )
F_199 ( V_15 -> V_112 , V_53 ,
& V_200 ) ;
}
V_15 -> V_40 . V_202 . V_241 [ V_108 ] = V_309 ;
}
F_202 ( V_15 -> V_112 , & V_200 ) ;
F_248 ( & V_15 -> V_112 -> V_216 ) ;
V_15 -> V_40 . V_202 . V_237 = V_309 ;
}
static int F_300 ( struct V_14 * V_15 , T_2 V_310 )
{
int V_118 = 0 ;
if ( ! F_301 ( V_15 -> V_112 , V_310 ) ) {
F_203 ( V_311 , V_15 ) ;
V_118 = 1 ;
}
return V_118 ;
}
static int F_302 ( struct V_14 * V_15 )
{
struct V_52 * V_53 ;
unsigned V_108 ;
if ( V_15 -> V_40 . V_202 . V_238 == V_239 ) {
F_247 ( & V_15 -> V_112 -> V_216 ) ;
F_298 ( V_15 ) ;
V_53 = F_222 ( V_15 , 0 , 0 , V_239 , 1 , V_271 ) ;
++ V_53 -> V_248 ;
F_248 ( & V_15 -> V_112 -> V_216 ) ;
V_15 -> V_40 . V_202 . V_237 = F_39 ( V_53 -> V_140 ) ;
} else if ( V_15 -> V_40 . V_202 . V_238 == V_240 ) {
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
T_9 V_308 = V_15 -> V_40 . V_202 . V_241 [ V_108 ] ;
F_171 ( F_271 ( V_308 ) ) ;
F_247 ( & V_15 -> V_112 -> V_216 ) ;
F_298 ( V_15 ) ;
V_53 = F_222 ( V_15 , V_108 << ( 30 - V_22 ) ,
V_108 << 30 , V_226 , 1 , V_271 ) ;
V_308 = F_39 ( V_53 -> V_140 ) ;
++ V_53 -> V_248 ;
F_248 ( & V_15 -> V_112 -> V_216 ) ;
V_15 -> V_40 . V_202 . V_241 [ V_108 ] = V_308 | V_300 ;
}
V_15 -> V_40 . V_202 . V_237 = F_39 ( V_15 -> V_40 . V_202 . V_241 ) ;
} else
F_113 () ;
return 0 ;
}
static int F_303 ( struct V_14 * V_15 )
{
struct V_52 * V_53 ;
T_1 V_312 , V_313 ;
T_2 V_310 ;
int V_108 ;
V_310 = V_15 -> V_40 . V_202 . V_314 ( V_15 ) >> V_22 ;
if ( F_300 ( V_15 , V_310 ) )
return 1 ;
if ( V_15 -> V_40 . V_202 . V_225 == V_239 ) {
T_9 V_308 = V_15 -> V_40 . V_202 . V_237 ;
F_171 ( F_271 ( V_308 ) ) ;
F_247 ( & V_15 -> V_112 -> V_216 ) ;
F_298 ( V_15 ) ;
V_53 = F_222 ( V_15 , V_310 , 0 , V_239 ,
0 , V_271 ) ;
V_308 = F_39 ( V_53 -> V_140 ) ;
++ V_53 -> V_248 ;
F_248 ( & V_15 -> V_112 -> V_216 ) ;
V_15 -> V_40 . V_202 . V_237 = V_308 ;
return 0 ;
}
V_313 = V_300 ;
if ( V_15 -> V_40 . V_202 . V_238 == V_239 )
V_313 |= V_315 | V_65 | V_316 ;
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
T_9 V_308 = V_15 -> V_40 . V_202 . V_241 [ V_108 ] ;
F_171 ( F_271 ( V_308 ) ) ;
if ( V_15 -> V_40 . V_202 . V_225 == V_240 ) {
V_312 = V_15 -> V_40 . V_202 . V_317 ( V_15 , V_108 ) ;
if ( ! ( V_312 & V_300 ) ) {
V_15 -> V_40 . V_202 . V_241 [ V_108 ] = 0 ;
continue;
}
V_310 = V_312 >> V_22 ;
if ( F_300 ( V_15 , V_310 ) )
return 1 ;
}
F_247 ( & V_15 -> V_112 -> V_216 ) ;
F_298 ( V_15 ) ;
V_53 = F_222 ( V_15 , V_310 , V_108 << 30 , V_226 ,
0 , V_271 ) ;
V_308 = F_39 ( V_53 -> V_140 ) ;
++ V_53 -> V_248 ;
F_248 ( & V_15 -> V_112 -> V_216 ) ;
V_15 -> V_40 . V_202 . V_241 [ V_108 ] = V_308 | V_313 ;
}
V_15 -> V_40 . V_202 . V_237 = F_39 ( V_15 -> V_40 . V_202 . V_241 ) ;
if ( V_15 -> V_40 . V_202 . V_238 == V_239 ) {
if ( V_15 -> V_40 . V_202 . V_318 == NULL ) {
T_1 * V_318 ;
V_318 = ( void * ) F_304 ( V_83 ) ;
if ( V_318 == NULL )
return 1 ;
V_318 [ 0 ] = F_39 ( V_15 -> V_40 . V_202 . V_241 ) | V_313 ;
V_15 -> V_40 . V_202 . V_318 = V_318 ;
}
V_15 -> V_40 . V_202 . V_237 = F_39 ( V_15 -> V_40 . V_202 . V_318 ) ;
}
return 0 ;
}
static int F_305 ( struct V_14 * V_15 )
{
if ( V_15 -> V_40 . V_202 . V_224 )
return F_302 ( V_15 ) ;
else
return F_303 ( V_15 ) ;
}
static void F_306 ( struct V_14 * V_15 )
{
int V_108 ;
struct V_52 * V_53 ;
if ( V_15 -> V_40 . V_202 . V_224 )
return;
if ( ! F_271 ( V_15 -> V_40 . V_202 . V_237 ) )
return;
F_307 ( V_15 , V_319 ) ;
F_204 ( V_15 , V_320 ) ;
if ( V_15 -> V_40 . V_202 . V_225 == V_239 ) {
T_9 V_308 = V_15 -> V_40 . V_202 . V_237 ;
V_53 = F_38 ( V_308 ) ;
F_213 ( V_15 , V_53 ) ;
F_204 ( V_15 , V_321 ) ;
return;
}
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
T_9 V_308 = V_15 -> V_40 . V_202 . V_241 [ V_108 ] ;
if ( V_308 && F_271 ( V_308 ) ) {
V_308 &= V_47 ;
V_53 = F_38 ( V_308 ) ;
F_213 ( V_15 , V_53 ) ;
}
}
F_204 ( V_15 , V_321 ) ;
}
void F_308 ( struct V_14 * V_15 )
{
F_247 ( & V_15 -> V_112 -> V_216 ) ;
F_306 ( V_15 ) ;
F_248 ( & V_15 -> V_112 -> V_216 ) ;
}
static T_10 F_309 ( struct V_14 * V_15 , T_6 V_322 ,
T_4 V_19 , struct V_323 * V_324 )
{
if ( V_324 )
V_324 -> V_294 = 0 ;
return V_322 ;
}
static T_10 F_310 ( struct V_14 * V_15 , T_6 V_322 ,
T_4 V_19 ,
struct V_323 * V_324 )
{
if ( V_324 )
V_324 -> V_294 = 0 ;
return V_15 -> V_40 . V_325 . V_326 ( V_15 , V_322 , V_19 , V_324 ) ;
}
static bool
F_311 ( struct V_327 * V_328 , T_1 V_43 , int V_45 )
{
int V_329 = ( V_43 >> 7 ) & 1 , V_330 = V_43 & 0x3f ;
return ( V_43 & V_328 -> V_331 [ V_329 ] [ V_45 - 1 ] ) |
( ( V_328 -> V_332 & ( 1ull << V_330 ) ) != 0 ) ;
}
static bool F_312 ( struct V_333 * V_202 , T_1 V_48 , int V_45 )
{
return F_311 ( & V_202 -> V_334 , V_48 , V_45 ) ;
}
static bool F_313 ( struct V_333 * V_202 , T_1 V_4 , int V_45 )
{
return F_311 ( & V_202 -> V_335 , V_4 , V_45 ) ;
}
static bool F_314 ( struct V_14 * V_15 , T_1 V_235 , bool V_98 )
{
if ( V_98 )
return F_315 ( V_15 , V_235 ) ;
return F_316 ( V_15 , V_235 ) ;
}
static bool
F_317 ( struct V_14 * V_15 , T_1 V_235 , T_1 * V_17 )
{
struct V_234 V_157 ;
T_1 V_133 [ V_239 ] , V_4 = 0ull ;
int V_308 , V_336 ;
bool V_337 = false ;
if ( ! F_271 ( V_15 -> V_40 . V_202 . V_237 ) )
goto exit;
F_64 ( V_15 ) ;
for ( F_227 ( & V_157 , V_15 , V_235 ) ,
V_336 = V_308 = V_157 . V_45 ;
F_228 ( & V_157 ) ;
F_231 ( & V_157 , V_4 ) ) {
V_4 = F_56 ( V_157 . V_17 ) ;
V_133 [ V_336 - 1 ] = V_4 ;
V_336 -- ;
if ( ! F_24 ( V_4 ) )
break;
V_337 |= F_313 ( & V_15 -> V_40 . V_202 , V_4 ,
V_157 . V_45 ) ;
}
F_67 ( V_15 ) ;
if ( V_337 ) {
F_114 ( L_29 ,
V_150 , V_235 ) ;
while ( V_308 > V_336 ) {
F_114 ( L_30 ,
V_133 [ V_308 - 1 ] , V_308 ) ;
V_308 -- ;
}
}
exit:
* V_17 = V_4 ;
return V_337 ;
}
int F_318 ( struct V_14 * V_15 , T_1 V_235 , bool V_98 )
{
T_1 V_4 ;
bool V_337 ;
if ( F_314 ( V_15 , V_235 , V_98 ) )
return V_338 ;
V_337 = F_317 ( V_15 , V_235 , & V_4 ) ;
if ( F_4 ( V_337 ) )
return V_339 ;
if ( F_11 ( V_4 ) ) {
T_2 V_18 = F_12 ( V_4 ) ;
unsigned V_19 = F_13 ( V_4 ) ;
if ( ! F_17 ( V_15 , V_4 ) )
return V_340 ;
if ( V_98 )
V_235 = 0 ;
F_319 ( V_235 , V_18 , V_19 ) ;
F_286 ( V_15 , V_235 , V_18 , V_19 ) ;
return V_338 ;
}
return V_341 ;
}
static bool F_320 ( struct V_14 * V_15 ,
T_4 V_294 , T_2 V_18 )
{
if ( F_15 ( V_294 & V_295 ) )
return false ;
if ( ! ( V_294 & V_297 ) ||
! ( V_294 & V_298 ) )
return false ;
if ( F_254 ( V_15 , V_18 , V_116 ) )
return true ;
return false ;
}
static void F_321 ( struct V_14 * V_15 , T_6 V_235 )
{
struct V_234 V_157 ;
T_1 V_4 ;
if ( ! F_271 ( V_15 -> V_40 . V_202 . V_237 ) )
return;
F_64 ( V_15 ) ;
F_292 (vcpu, addr, iterator, spte) {
F_221 ( V_157 . V_17 ) ;
if ( ! F_24 ( V_4 ) )
break;
}
F_67 ( V_15 ) ;
}
static int F_322 ( struct V_14 * V_15 , T_6 V_188 ,
T_4 V_294 , bool V_269 )
{
T_2 V_18 = V_188 >> V_22 ;
int V_87 ;
F_250 ( L_31 , V_150 , V_188 , V_294 ) ;
if ( F_320 ( V_15 , V_294 , V_18 ) )
return 1 ;
V_87 = F_80 ( V_15 ) ;
if ( V_87 )
return V_87 ;
F_171 ( ! F_271 ( V_15 -> V_40 . V_202 . V_237 ) ) ;
return F_295 ( V_15 , V_188 & V_23 ,
V_294 , V_18 , V_269 ) ;
}
static int F_323 ( struct V_14 * V_15 , T_6 V_188 , T_2 V_18 )
{
struct V_342 V_40 ;
V_40 . V_343 = ( V_15 -> V_40 . V_344 . V_345 ++ << 12 ) | V_15 -> V_346 ;
V_40 . V_18 = V_18 ;
V_40 . V_224 = V_15 -> V_40 . V_202 . V_224 ;
V_40 . V_347 = V_15 -> V_40 . V_202 . V_314 ( V_15 ) ;
return F_324 ( V_15 , V_188 , F_277 ( V_15 , V_18 ) , & V_40 ) ;
}
static bool F_325 ( struct V_14 * V_15 )
{
if ( F_15 ( ! F_326 ( V_15 ) ||
F_327 ( V_15 ) ) )
return false ;
return V_127 -> V_348 ( V_15 ) ;
}
static bool F_296 ( struct V_14 * V_15 , bool V_269 , T_2 V_18 ,
T_6 V_188 , T_3 * V_24 , bool V_267 , bool * V_349 )
{
struct V_102 * V_103 ;
bool V_350 ;
V_103 = F_101 ( V_15 , V_18 ) ;
V_350 = false ;
* V_24 = F_328 ( V_103 , V_18 , false , & V_350 , V_267 , V_349 ) ;
if ( ! V_350 )
return false ;
if ( ! V_269 && F_325 ( V_15 ) ) {
F_329 ( V_188 , V_18 ) ;
if ( F_330 ( V_15 , V_18 ) ) {
F_331 ( V_188 , V_18 ) ;
F_203 ( V_351 , V_15 ) ;
return true ;
} else if ( F_323 ( V_15 , V_188 , V_18 ) )
return true ;
}
* V_24 = F_328 ( V_103 , V_18 , false , NULL , V_267 , V_349 ) ;
return false ;
}
static bool
F_332 ( struct V_14 * V_15 , T_2 V_18 , int V_45 )
{
int V_352 = F_281 ( V_45 ) ;
V_18 &= ~ ( V_352 - 1 ) ;
return F_333 ( V_15 , V_18 , V_352 ) ;
}
static int F_334 ( struct V_14 * V_15 , T_6 V_353 , T_4 V_294 ,
bool V_269 )
{
T_3 V_24 ;
int V_87 ;
int V_45 ;
bool V_124 ;
T_2 V_18 = V_353 >> V_22 ;
unsigned long V_305 ;
int V_267 = V_294 & V_298 ;
bool V_268 ;
F_171 ( ! F_271 ( V_15 -> V_40 . V_202 . V_237 ) ) ;
if ( F_320 ( V_15 , V_294 , V_18 ) )
return 1 ;
V_87 = F_80 ( V_15 ) ;
if ( V_87 )
return V_87 ;
V_124 = ! F_332 ( V_15 , V_18 ,
V_109 ) ;
V_45 = F_107 ( V_15 , V_18 , & V_124 ) ;
if ( F_19 ( ! V_124 ) ) {
if ( V_45 > V_109 &&
! F_332 ( V_15 , V_18 , V_45 ) )
V_45 = V_109 ;
V_18 &= ~ ( F_281 ( V_45 ) - 1 ) ;
}
if ( F_291 ( V_15 , V_353 , V_45 , V_294 ) )
return 0 ;
V_305 = V_15 -> V_112 -> V_306 ;
F_41 () ;
if ( F_296 ( V_15 , V_269 , V_18 , V_353 , & V_24 , V_267 , & V_268 ) )
return 0 ;
if ( F_284 ( V_15 , 0 , V_18 , V_24 , V_271 , & V_87 ) )
return V_87 ;
F_247 ( & V_15 -> V_112 -> V_216 ) ;
if ( F_297 ( V_15 -> V_112 , V_305 ) )
goto V_307;
F_298 ( V_15 ) ;
if ( F_19 ( ! V_124 ) )
F_278 ( V_15 , & V_18 , & V_24 , & V_45 ) ;
V_87 = F_270 ( V_15 , V_267 , V_268 , V_45 , V_18 , V_24 , V_269 ) ;
F_248 ( & V_15 -> V_112 -> V_216 ) ;
return V_87 ;
V_307:
F_248 ( & V_15 -> V_112 -> V_216 ) ;
F_262 ( V_24 ) ;
return 0 ;
}
static void F_335 ( struct V_14 * V_15 ,
struct V_333 * V_354 )
{
V_354 -> V_355 = F_322 ;
V_354 -> V_356 = F_309 ;
V_354 -> V_203 = F_186 ;
V_354 -> V_357 = F_187 ;
V_354 -> V_358 = F_188 ;
V_354 -> V_225 = 0 ;
V_354 -> V_238 = V_240 ;
V_354 -> V_237 = V_309 ;
V_354 -> V_224 = true ;
V_354 -> V_359 = false ;
}
void F_336 ( struct V_14 * V_15 )
{
F_299 ( V_15 ) ;
}
static unsigned long V_314 ( struct V_14 * V_15 )
{
return F_337 ( V_15 ) ;
}
static void F_338 ( struct V_14 * V_15 ,
struct V_323 * V_360 )
{
V_15 -> V_40 . V_202 . F_338 ( V_15 , V_360 ) ;
}
static bool F_339 ( struct V_14 * V_15 , T_1 * V_17 , T_2 V_18 ,
unsigned V_19 , int * V_361 )
{
if ( F_15 ( F_11 ( * V_17 ) ) ) {
if ( V_18 != F_12 ( * V_17 ) ) {
F_55 ( V_17 ) ;
return true ;
}
( * V_361 ) ++ ;
F_8 ( V_15 , V_17 , V_18 , V_19 ) ;
return true ;
}
return false ;
}
static inline bool F_340 ( struct V_333 * V_202 ,
unsigned V_45 , unsigned V_48 )
{
V_48 |= V_45 - V_46 - 1 ;
V_48 &= V_45 - V_202 -> V_362 ;
return V_48 & V_44 ;
}
static void
F_341 ( struct V_14 * V_15 ,
struct V_327 * V_328 ,
int V_363 , int V_45 , bool V_359 , bool V_364 ,
bool V_365 , bool V_366 )
{
T_1 V_367 = 0 ;
T_1 V_368 = 0 ;
T_1 V_369 = 0 ;
V_328 -> V_332 = 0 ;
if ( ! V_359 )
V_367 = F_342 ( 63 , 63 ) ;
if ( ! V_364 )
V_368 = F_342 ( 7 , 7 ) ;
if ( V_366 )
V_369 = F_342 ( 8 , 8 ) ;
switch ( V_45 ) {
case V_226 :
V_328 -> V_331 [ 0 ] [ 1 ] = 0 ;
V_328 -> V_331 [ 0 ] [ 0 ] = 0 ;
V_328 -> V_331 [ 1 ] [ 0 ] =
V_328 -> V_331 [ 0 ] [ 0 ] ;
if ( ! V_365 ) {
V_328 -> V_331 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_22 () )
V_328 -> V_331 [ 1 ] [ 1 ] = F_342 ( 17 , 21 ) ;
else
V_328 -> V_331 [ 1 ] [ 1 ] = F_342 ( 13 , 21 ) ;
break;
case V_240 :
V_328 -> V_331 [ 0 ] [ 2 ] =
F_342 ( V_363 , 63 ) |
F_342 ( 5 , 8 ) | F_342 ( 1 , 2 ) ;
V_328 -> V_331 [ 0 ] [ 1 ] = V_367 |
F_342 ( V_363 , 62 ) ;
V_328 -> V_331 [ 0 ] [ 0 ] = V_367 |
F_342 ( V_363 , 62 ) ;
V_328 -> V_331 [ 1 ] [ 1 ] = V_367 |
F_342 ( V_363 , 62 ) |
F_342 ( 13 , 20 ) ;
V_328 -> V_331 [ 1 ] [ 0 ] =
V_328 -> V_331 [ 0 ] [ 0 ] ;
break;
case V_239 :
V_328 -> V_331 [ 0 ] [ 3 ] = V_367 |
V_369 | F_342 ( 7 , 7 ) |
F_342 ( V_363 , 51 ) ;
V_328 -> V_331 [ 0 ] [ 2 ] = V_367 |
V_369 | V_368 |
F_342 ( V_363 , 51 ) ;
V_328 -> V_331 [ 0 ] [ 1 ] = V_367 |
F_342 ( V_363 , 51 ) ;
V_328 -> V_331 [ 0 ] [ 0 ] = V_367 |
F_342 ( V_363 , 51 ) ;
V_328 -> V_331 [ 1 ] [ 3 ] =
V_328 -> V_331 [ 0 ] [ 3 ] ;
V_328 -> V_331 [ 1 ] [ 2 ] = V_367 |
V_368 | F_342 ( V_363 , 51 ) |
F_342 ( 13 , 29 ) ;
V_328 -> V_331 [ 1 ] [ 1 ] = V_367 |
F_342 ( V_363 , 51 ) |
F_342 ( 13 , 20 ) ;
V_328 -> V_331 [ 1 ] [ 0 ] =
V_328 -> V_331 [ 0 ] [ 0 ] ;
break;
}
}
static void F_343 ( struct V_14 * V_15 ,
struct V_333 * V_354 )
{
F_341 ( V_15 , & V_354 -> V_334 ,
F_344 ( V_15 ) , V_354 -> V_225 ,
V_354 -> V_359 , F_345 ( V_15 ) ,
F_346 ( V_15 ) , F_347 ( V_15 ) ) ;
}
static void
F_348 ( struct V_327 * V_328 ,
int V_363 , bool V_370 )
{
T_1 V_332 ;
V_328 -> V_331 [ 0 ] [ 3 ] =
F_342 ( V_363 , 51 ) | F_342 ( 3 , 7 ) ;
V_328 -> V_331 [ 0 ] [ 2 ] =
F_342 ( V_363 , 51 ) | F_342 ( 3 , 6 ) ;
V_328 -> V_331 [ 0 ] [ 1 ] =
F_342 ( V_363 , 51 ) | F_342 ( 3 , 6 ) ;
V_328 -> V_331 [ 0 ] [ 0 ] = F_342 ( V_363 , 51 ) ;
V_328 -> V_331 [ 1 ] [ 3 ] = V_328 -> V_331 [ 0 ] [ 3 ] ;
V_328 -> V_331 [ 1 ] [ 2 ] =
F_342 ( V_363 , 51 ) | F_342 ( 12 , 29 ) ;
V_328 -> V_331 [ 1 ] [ 1 ] =
F_342 ( V_363 , 51 ) | F_342 ( 12 , 20 ) ;
V_328 -> V_331 [ 1 ] [ 0 ] = V_328 -> V_331 [ 0 ] [ 0 ] ;
V_332 = 0xFFull << ( 2 * 8 ) ;
V_332 |= 0xFFull << ( 3 * 8 ) ;
V_332 |= 0xFFull << ( 7 * 8 ) ;
V_332 |= F_349 ( 1ull << 2 ) ;
V_332 |= F_349 ( 1ull << 6 ) ;
if ( ! V_370 ) {
V_332 |= F_349 ( 1ull << 4 ) ;
}
V_328 -> V_332 = V_332 ;
}
static void F_350 ( struct V_14 * V_15 ,
struct V_333 * V_354 , bool V_370 )
{
F_348 ( & V_354 -> V_334 ,
F_344 ( V_15 ) , V_370 ) ;
}
void
F_351 ( struct V_14 * V_15 , struct V_333 * V_354 )
{
bool V_371 = V_354 -> V_359 || V_354 -> V_223 . V_372 ;
F_341 ( V_15 , & V_354 -> V_335 ,
V_373 . V_374 ,
V_354 -> V_238 , V_371 ,
F_345 ( V_15 ) , F_346 ( V_15 ) ,
true ) ;
}
static inline bool F_352 ( void )
{
F_60 ( ! V_257 ) ;
return V_38 == 0 ;
}
static void
F_353 ( struct V_14 * V_15 ,
struct V_333 * V_354 )
{
if ( F_352 () )
F_341 ( V_15 , & V_354 -> V_335 ,
V_373 . V_374 ,
V_354 -> V_238 , false ,
F_354 ( V_375 ) ,
true , true ) ;
else
F_348 ( & V_354 -> V_335 ,
V_373 . V_374 ,
false ) ;
}
static void
F_355 ( struct V_14 * V_15 ,
struct V_333 * V_354 , bool V_370 )
{
F_348 ( & V_354 -> V_335 ,
V_373 . V_374 , V_370 ) ;
}
static void F_356 ( struct V_14 * V_15 ,
struct V_333 * V_202 , bool V_376 )
{
unsigned V_377 , V_378 , V_379 ;
T_11 V_380 ;
bool V_360 , V_381 , V_382 , V_383 , V_384 , V_385 , V_386 , V_387 , V_388 , V_389 , V_390 = 0 ;
V_389 = F_357 ( V_15 , V_391 ) ;
V_388 = F_357 ( V_15 , V_392 ) ;
for ( V_378 = 0 ; V_378 < F_71 ( V_202 -> V_393 ) ; ++ V_378 ) {
V_379 = V_378 << 1 ;
V_380 = 0 ;
V_384 = V_379 & V_298 ;
V_385 = V_379 & V_394 ;
V_386 = V_379 & V_296 ;
V_387 = ! ( V_379 & V_295 ) ;
for ( V_377 = 0 ; V_377 < 8 ; ++ V_377 ) {
V_381 = V_377 & V_256 ;
V_382 = V_377 & V_20 ;
V_383 = V_377 & V_21 ;
if ( ! V_376 ) {
V_381 |= ! V_202 -> V_359 ;
V_382 |= ! F_358 ( V_15 ) && ! V_385 ;
V_381 &= ! ( V_389 && V_383 && ! V_385 ) ;
V_390 = V_388 && V_383 && ! V_385 && ! V_386 ;
}
V_360 = ( V_386 && ! V_381 ) || ( V_385 && ! V_383 ) || ( V_384 && ! V_382 ) ||
( V_387 && V_390 ) ;
V_380 |= V_360 << V_377 ;
}
V_202 -> V_393 [ V_378 ] = V_380 ;
}
}
static void F_359 ( struct V_14 * V_15 , struct V_333 * V_202 ,
bool V_376 )
{
unsigned V_377 ;
bool V_395 ;
if ( V_376 ) {
V_202 -> V_396 = 0 ;
return;
}
if ( ! F_357 ( V_15 , V_397 ) || ! F_360 ( V_15 ) ) {
V_202 -> V_396 = 0 ;
return;
}
V_395 = F_358 ( V_15 ) ;
for ( V_377 = 0 ; V_377 < F_71 ( V_202 -> V_393 ) ; ++ V_377 ) {
unsigned V_379 , V_398 ;
bool V_399 , V_400 , V_386 , V_385 , V_384 , V_401 ;
V_379 = V_377 << 1 ;
V_386 = V_379 & V_296 ;
V_385 = V_379 & V_394 ;
V_384 = V_379 & V_298 ;
V_401 = V_379 & V_295 ;
V_399 = ( ! V_386 && V_401 ) ;
V_400 = V_399 && V_384 && ( V_385 || V_395 ) ;
V_398 = ! ! V_399 ;
V_398 |= ( ! ! V_400 ) << 1 ;
V_202 -> V_396 |= ( V_398 & 3 ) << V_379 ;
}
}
static void F_361 ( struct V_14 * V_15 , struct V_333 * V_202 )
{
unsigned V_225 = V_202 -> V_225 ;
V_202 -> V_362 = V_225 ;
if ( V_225 == V_226 && F_346 ( V_15 ) )
V_202 -> V_362 ++ ;
}
static void F_362 ( struct V_14 * V_15 ,
struct V_333 * V_354 ,
int V_45 )
{
V_354 -> V_359 = F_23 ( V_15 ) ;
V_354 -> V_225 = V_45 ;
F_343 ( V_15 , V_354 ) ;
F_356 ( V_15 , V_354 , false ) ;
F_359 ( V_15 , V_354 , false ) ;
F_361 ( V_15 , V_354 ) ;
F_171 ( ! F_198 ( V_15 ) ) ;
V_354 -> V_355 = V_402 ;
V_354 -> V_356 = V_403 ;
V_354 -> V_203 = V_404 ;
V_354 -> V_357 = V_405 ;
V_354 -> V_358 = V_406 ;
V_354 -> V_238 = V_45 ;
V_354 -> V_237 = V_309 ;
V_354 -> V_224 = false ;
}
static void F_363 ( struct V_14 * V_15 ,
struct V_333 * V_354 )
{
F_362 ( V_15 , V_354 , V_239 ) ;
}
static void F_364 ( struct V_14 * V_15 ,
struct V_333 * V_354 )
{
V_354 -> V_359 = false ;
V_354 -> V_225 = V_226 ;
F_343 ( V_15 , V_354 ) ;
F_356 ( V_15 , V_354 , false ) ;
F_359 ( V_15 , V_354 , false ) ;
F_361 ( V_15 , V_354 ) ;
V_354 -> V_355 = V_407 ;
V_354 -> V_356 = V_408 ;
V_354 -> V_203 = V_409 ;
V_354 -> V_357 = V_410 ;
V_354 -> V_358 = V_411 ;
V_354 -> V_238 = V_240 ;
V_354 -> V_237 = V_309 ;
V_354 -> V_224 = false ;
}
static void F_365 ( struct V_14 * V_15 ,
struct V_333 * V_354 )
{
F_362 ( V_15 , V_354 , V_240 ) ;
}
static void F_366 ( struct V_14 * V_15 )
{
struct V_333 * V_354 = & V_15 -> V_40 . V_202 ;
V_354 -> V_223 . V_229 = 0 ;
V_354 -> V_223 . V_412 = F_367 ( V_15 ) ;
V_354 -> V_355 = F_334 ;
V_354 -> V_203 = F_186 ;
V_354 -> V_357 = F_187 ;
V_354 -> V_358 = F_188 ;
V_354 -> V_238 = V_127 -> V_413 () ;
V_354 -> V_237 = V_309 ;
V_354 -> V_224 = true ;
V_354 -> V_414 = V_127 -> V_415 ;
V_354 -> V_314 = V_314 ;
V_354 -> V_317 = V_416 ;
V_354 -> F_338 = V_417 ;
if ( ! F_368 ( V_15 ) ) {
V_354 -> V_359 = false ;
V_354 -> V_356 = F_309 ;
V_354 -> V_225 = 0 ;
} else if ( F_360 ( V_15 ) ) {
V_354 -> V_359 = F_23 ( V_15 ) ;
V_354 -> V_225 = V_239 ;
F_343 ( V_15 , V_354 ) ;
V_354 -> V_356 = V_403 ;
} else if ( F_198 ( V_15 ) ) {
V_354 -> V_359 = F_23 ( V_15 ) ;
V_354 -> V_225 = V_240 ;
F_343 ( V_15 , V_354 ) ;
V_354 -> V_356 = V_403 ;
} else {
V_354 -> V_359 = false ;
V_354 -> V_225 = V_226 ;
F_343 ( V_15 , V_354 ) ;
V_354 -> V_356 = V_408 ;
}
F_356 ( V_15 , V_354 , false ) ;
F_359 ( V_15 , V_354 , false ) ;
F_361 ( V_15 , V_354 ) ;
F_353 ( V_15 , V_354 ) ;
}
void F_369 ( struct V_14 * V_15 )
{
bool V_418 = F_357 ( V_15 , V_391 ) ;
bool V_390 = F_357 ( V_15 , V_392 ) ;
struct V_333 * V_354 = & V_15 -> V_40 . V_202 ;
F_171 ( F_271 ( V_354 -> V_237 ) ) ;
if ( ! F_368 ( V_15 ) )
F_335 ( V_15 , V_354 ) ;
else if ( F_360 ( V_15 ) )
F_363 ( V_15 , V_354 ) ;
else if ( F_198 ( V_15 ) )
F_365 ( V_15 , V_354 ) ;
else
F_364 ( V_15 , V_354 ) ;
V_354 -> V_223 . V_419 = F_23 ( V_15 ) ;
V_354 -> V_223 . V_201 = ! ! F_198 ( V_15 ) ;
V_354 -> V_223 . V_420 = F_358 ( V_15 ) ;
V_354 -> V_223 . V_372
= V_418 && ! F_358 ( V_15 ) ;
V_354 -> V_223 . V_421
= V_390 && ! F_358 ( V_15 ) ;
V_354 -> V_223 . V_412 = F_367 ( V_15 ) ;
F_351 ( V_15 , V_354 ) ;
}
void F_370 ( struct V_14 * V_15 , bool V_370 )
{
struct V_333 * V_354 = & V_15 -> V_40 . V_202 ;
F_171 ( F_271 ( V_354 -> V_237 ) ) ;
V_354 -> V_238 = V_127 -> V_413 () ;
V_354 -> V_359 = true ;
V_354 -> V_355 = V_422 ;
V_354 -> V_356 = V_423 ;
V_354 -> V_203 = V_424 ;
V_354 -> V_357 = V_425 ;
V_354 -> V_358 = V_426 ;
V_354 -> V_225 = V_354 -> V_238 ;
V_354 -> V_237 = V_309 ;
V_354 -> V_224 = false ;
F_356 ( V_15 , V_354 , true ) ;
F_359 ( V_15 , V_354 , true ) ;
F_350 ( V_15 , V_354 , V_370 ) ;
F_355 ( V_15 , V_354 , V_370 ) ;
}
static void F_371 ( struct V_14 * V_15 )
{
struct V_333 * V_354 = & V_15 -> V_40 . V_202 ;
F_369 ( V_15 ) ;
V_354 -> V_414 = V_127 -> V_414 ;
V_354 -> V_314 = V_314 ;
V_354 -> V_317 = V_416 ;
V_354 -> F_338 = V_417 ;
}
static void F_372 ( struct V_14 * V_15 )
{
struct V_333 * V_427 = & V_15 -> V_40 . V_325 ;
V_427 -> V_314 = V_314 ;
V_427 -> V_317 = V_416 ;
V_427 -> F_338 = V_417 ;
if ( ! F_368 ( V_15 ) ) {
V_427 -> V_359 = false ;
V_427 -> V_225 = 0 ;
V_427 -> V_356 = F_310 ;
} else if ( F_360 ( V_15 ) ) {
V_427 -> V_359 = F_23 ( V_15 ) ;
V_427 -> V_225 = V_239 ;
F_343 ( V_15 , V_427 ) ;
V_427 -> V_356 = V_428 ;
} else if ( F_198 ( V_15 ) ) {
V_427 -> V_359 = F_23 ( V_15 ) ;
V_427 -> V_225 = V_240 ;
F_343 ( V_15 , V_427 ) ;
V_427 -> V_356 = V_428 ;
} else {
V_427 -> V_359 = false ;
V_427 -> V_225 = V_226 ;
F_343 ( V_15 , V_427 ) ;
V_427 -> V_356 = V_429 ;
}
F_356 ( V_15 , V_427 , false ) ;
F_359 ( V_15 , V_427 , false ) ;
F_361 ( V_15 , V_427 ) ;
}
static void F_373 ( struct V_14 * V_15 )
{
if ( F_374 ( V_15 ) )
F_372 ( V_15 ) ;
else if ( V_257 )
F_366 ( V_15 ) ;
else
F_371 ( V_15 ) ;
}
void F_375 ( struct V_14 * V_15 )
{
F_376 ( V_15 ) ;
F_373 ( V_15 ) ;
}
int F_377 ( struct V_14 * V_15 )
{
int V_87 ;
V_87 = F_80 ( V_15 ) ;
if ( V_87 )
goto V_91;
V_87 = F_305 ( V_15 ) ;
F_308 ( V_15 ) ;
if ( V_87 )
goto V_91;
V_15 -> V_40 . V_202 . V_414 ( V_15 , V_15 -> V_40 . V_202 . V_237 ) ;
V_91:
return V_87 ;
}
void F_376 ( struct V_14 * V_15 )
{
F_299 ( V_15 ) ;
F_4 ( F_271 ( V_15 -> V_40 . V_202 . V_237 ) ) ;
}
static void F_378 ( struct V_14 * V_15 ,
struct V_52 * V_53 , T_1 * V_4 ,
const void * V_430 )
{
if ( V_53 -> V_97 . V_45 != V_46 ) {
++ V_15 -> V_112 -> V_144 . V_431 ;
return;
}
++ V_15 -> V_112 -> V_144 . V_432 ;
V_15 -> V_40 . V_202 . V_358 ( V_15 , V_53 , V_4 , V_430 ) ;
}
static bool F_379 ( T_1 V_433 , T_1 V_430 )
{
if ( ! F_24 ( V_433 ) )
return false ;
if ( ! F_24 ( V_430 ) )
return true ;
if ( ( V_433 ^ V_430 ) & V_47 )
return true ;
V_433 ^= V_37 ;
V_430 ^= V_37 ;
return ( V_433 & ~ V_430 & V_434 ) != 0 ;
}
static T_1 F_380 ( struct V_14 * V_15 , T_10 * V_353 ,
const T_11 * V_430 , int * V_435 )
{
T_1 V_436 ;
int V_87 ;
if ( F_198 ( V_15 ) && * V_435 == 4 ) {
* V_353 &= ~ ( T_10 ) 7 ;
* V_435 = 8 ;
V_87 = F_381 ( V_15 , * V_353 , & V_436 , 8 ) ;
if ( V_87 )
V_436 = 0 ;
V_430 = ( const T_11 * ) & V_436 ;
}
switch ( * V_435 ) {
case 4 :
V_436 = * ( const T_4 * ) V_430 ;
break;
case 8 :
V_436 = * ( const T_1 * ) V_430 ;
break;
default:
V_436 = 0 ;
break;
}
return V_436 ;
}
static bool F_382 ( struct V_52 * V_53 )
{
if ( V_53 -> V_97 . V_45 == V_46 )
return false ;
F_383 ( & V_53 -> V_217 ) ;
return F_384 ( & V_53 -> V_217 ) >= 3 ;
}
static bool F_385 ( struct V_52 * V_53 , T_10 V_353 ,
int V_435 )
{
unsigned V_437 , V_438 , V_439 ;
F_250 ( L_32 ,
V_353 , V_435 , V_53 -> V_97 . V_229 ) ;
V_437 = F_386 ( V_353 ) ;
V_438 = V_53 -> V_97 . V_201 ? 8 : 4 ;
if ( ! ( V_437 & ( V_438 - 1 ) ) && V_435 == 1 )
return false ;
V_439 = ( V_437 ^ ( V_437 + V_435 - 1 ) ) & ~ ( V_438 - 1 ) ;
V_439 |= V_435 < 4 ;
return V_439 ;
}
static T_1 * F_387 ( struct V_52 * V_53 , T_10 V_353 , int * V_440 )
{
unsigned V_441 , V_220 ;
T_1 * V_4 ;
int V_45 ;
V_441 = F_386 ( V_353 ) ;
V_45 = V_53 -> V_97 . V_45 ;
* V_440 = 1 ;
if ( ! V_53 -> V_97 . V_201 ) {
V_441 <<= 1 ;
if ( V_45 == V_226 ) {
V_441 &= ~ 7 ;
V_441 <<= 1 ;
* V_440 = 2 ;
}
V_220 = V_441 >> V_22 ;
V_441 &= ~ V_23 ;
if ( V_220 != V_53 -> V_97 . V_220 )
return NULL ;
}
V_4 = & V_53 -> V_140 [ V_441 / sizeof( * V_4 ) ] ;
return V_4 ;
}
static void F_388 ( struct V_14 * V_15 , T_10 V_353 ,
const T_11 * V_430 , int V_435 ,
struct V_442 * V_443 )
{
T_2 V_18 = V_353 >> V_22 ;
struct V_52 * V_53 ;
F_214 ( V_200 ) ;
T_1 V_444 , V_436 , * V_4 ;
int V_445 ;
bool V_204 , V_205 ;
union V_219 V_8 = { } ;
V_8 . V_420 = 1 ;
V_8 . V_201 = 1 ;
V_8 . V_419 = 1 ;
V_8 . V_372 = 1 ;
V_8 . V_421 = 1 ;
V_8 . V_412 = 1 ;
if ( ! F_36 ( V_15 -> V_112 -> V_40 . V_115 ) )
return;
V_204 = V_205 = false ;
F_250 ( L_33 , V_150 , V_353 , V_435 ) ;
V_436 = F_380 ( V_15 , & V_353 , V_430 , & V_435 ) ;
F_80 ( V_15 ) ;
F_247 ( & V_15 -> V_112 -> V_216 ) ;
++ V_15 -> V_112 -> V_144 . V_446 ;
F_204 ( V_15 , V_447 ) ;
F_209 (vcpu->kvm, sp, gfn) {
if ( F_385 ( V_53 , V_353 , V_435 ) ||
F_382 ( V_53 ) ) {
F_199 ( V_15 -> V_112 , V_53 , & V_200 ) ;
++ V_15 -> V_112 -> V_144 . V_448 ;
continue;
}
V_4 = F_387 ( V_53 , V_353 , & V_445 ) ;
if ( ! V_4 )
continue;
V_205 = true ;
while ( V_445 -- ) {
V_444 = * V_4 ;
F_236 ( V_15 -> V_112 , V_53 , V_4 ) ;
if ( V_436 &&
! ( ( V_53 -> V_97 . V_229 ^ V_15 -> V_40 . V_202 . V_223 . V_229 )
& V_8 . V_229 ) && F_117 ( V_15 ) )
F_378 ( V_15 , V_53 , V_4 , & V_436 ) ;
if ( F_379 ( V_444 , * V_4 ) )
V_204 = true ;
++ V_4 ;
}
}
F_200 ( V_15 , & V_200 , V_204 , V_205 ) ;
F_204 ( V_15 , V_449 ) ;
F_248 ( & V_15 -> V_112 -> V_216 ) ;
}
int F_389 ( struct V_14 * V_15 , T_6 V_188 )
{
T_10 V_353 ;
int V_87 ;
if ( V_15 -> V_40 . V_202 . V_224 )
return 0 ;
V_353 = F_390 ( V_15 , V_188 , NULL ) ;
V_87 = F_249 ( V_15 -> V_112 , V_353 >> V_22 ) ;
return V_87 ;
}
static void F_298 ( struct V_14 * V_15 )
{
F_214 ( V_200 ) ;
if ( F_19 ( F_391 ( V_15 -> V_112 ) >= V_450 ) )
return;
while ( F_391 ( V_15 -> V_112 ) < V_451 ) {
if ( ! F_244 ( V_15 -> V_112 , & V_200 ) )
break;
++ V_15 -> V_112 -> V_144 . V_452 ;
}
F_202 ( V_15 -> V_112 , & V_200 ) ;
}
int F_392 ( struct V_14 * V_15 , T_6 V_453 , T_1 V_294 ,
void * V_454 , int V_455 )
{
int V_87 , V_456 = V_457 ;
enum V_458 V_459 ;
bool V_98 = V_15 -> V_40 . V_202 . V_224 || F_374 ( V_15 ) ;
if ( F_15 ( V_294 & V_295 ) ) {
V_87 = F_318 ( V_15 , V_453 , V_98 ) ;
if ( V_87 == V_338 ) {
V_456 = 0 ;
goto V_264;
}
if ( V_87 == V_341 )
return 1 ;
if ( V_87 < 0 )
return V_87 ;
}
V_87 = V_15 -> V_40 . V_202 . V_355 ( V_15 , V_453 , F_393 ( V_294 ) ,
false ) ;
if ( V_87 < 0 )
return V_87 ;
if ( ! V_87 )
return 1 ;
if ( V_294 == V_460 ) {
F_249 ( V_15 -> V_112 , F_394 ( V_453 ) ) ;
return 1 ;
}
if ( F_314 ( V_15 , V_453 , V_98 ) )
V_456 = 0 ;
V_264:
V_459 = F_395 ( V_15 , V_453 , V_456 , V_454 , V_455 ) ;
switch ( V_459 ) {
case V_461 :
return 1 ;
case V_462 :
++ V_15 -> V_144 . V_463 ;
case V_464 :
return 0 ;
default:
F_113 () ;
}
}
void F_396 ( struct V_14 * V_15 , T_6 V_188 )
{
V_15 -> V_40 . V_202 . V_357 ( V_15 , V_188 ) ;
F_203 ( V_206 , V_15 ) ;
++ V_15 -> V_144 . V_357 ;
}
void F_397 ( void )
{
V_257 = true ;
}
void F_398 ( void )
{
V_257 = false ;
}
static void F_399 ( struct V_14 * V_15 )
{
F_79 ( ( unsigned long ) V_15 -> V_40 . V_202 . V_241 ) ;
if ( V_15 -> V_40 . V_202 . V_318 != NULL )
F_79 ( ( unsigned long ) V_15 -> V_40 . V_202 . V_318 ) ;
}
static int F_400 ( struct V_14 * V_15 )
{
struct V_86 * V_86 ;
int V_108 ;
V_86 = F_401 ( V_83 | V_465 ) ;
if ( ! V_86 )
return - V_84 ;
V_15 -> V_40 . V_202 . V_241 = F_402 ( V_86 ) ;
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 )
V_15 -> V_40 . V_202 . V_241 [ V_108 ] = V_309 ;
return 0 ;
}
int F_403 ( struct V_14 * V_15 )
{
V_15 -> V_40 . V_466 = & V_15 -> V_40 . V_202 ;
V_15 -> V_40 . V_202 . V_237 = V_309 ;
V_15 -> V_40 . V_202 . V_326 = V_326 ;
V_15 -> V_40 . V_325 . V_326 = V_467 ;
return F_400 ( V_15 ) ;
}
void F_404 ( struct V_14 * V_15 )
{
F_171 ( F_271 ( V_15 -> V_40 . V_202 . V_237 ) ) ;
F_373 ( V_15 ) ;
}
static void F_405 ( struct V_112 * V_112 ,
struct V_102 * V_103 ,
struct V_442 * V_443 )
{
F_406 ( V_112 ) ;
}
void F_407 ( struct V_112 * V_112 )
{
struct V_442 * V_443 = & V_112 -> V_40 . V_468 ;
V_443 -> V_469 = F_388 ;
V_443 -> V_470 = F_405 ;
F_408 ( V_112 , V_443 ) ;
}
void F_409 ( struct V_112 * V_112 )
{
struct V_442 * V_443 = & V_112 -> V_40 . V_468 ;
F_410 ( V_112 , V_443 ) ;
}
static bool
F_411 ( struct V_112 * V_112 , struct V_102 * V_165 ,
T_12 V_471 , int V_161 , int V_162 ,
T_2 V_158 , T_2 V_160 , bool V_472 )
{
struct V_156 V_157 ;
bool V_68 = false ;
F_156 (memslot, start_level, end_level, start_gfn,
end_gfn, &iterator) {
if ( V_157 . V_139 )
V_68 |= V_471 ( V_112 , V_157 . V_139 ) ;
if ( F_216 () || F_217 ( & V_112 -> V_216 ) ) {
if ( V_68 && V_472 ) {
F_125 ( V_112 ) ;
V_68 = false ;
}
F_218 ( & V_112 -> V_216 ) ;
}
}
if ( V_68 && V_472 ) {
F_125 ( V_112 ) ;
V_68 = false ;
}
return V_68 ;
}
static bool
F_412 ( struct V_112 * V_112 , struct V_102 * V_165 ,
T_12 V_471 , int V_161 , int V_162 ,
bool V_472 )
{
return F_411 ( V_112 , V_165 , V_471 , V_161 ,
V_162 , V_165 -> V_105 ,
V_165 -> V_105 + V_165 -> V_172 - 1 ,
V_472 ) ;
}
static bool
F_413 ( struct V_112 * V_112 , struct V_102 * V_165 ,
T_12 V_471 , bool V_472 )
{
return F_412 ( V_112 , V_165 , V_471 , V_46 ,
V_110 , V_472 ) ;
}
static bool
F_414 ( struct V_112 * V_112 , struct V_102 * V_165 ,
T_12 V_471 , bool V_472 )
{
return F_412 ( V_112 , V_165 , V_471 , V_46 + 1 ,
V_110 , V_472 ) ;
}
static bool
F_415 ( struct V_112 * V_112 , struct V_102 * V_165 ,
T_12 V_471 , bool V_472 )
{
return F_412 ( V_112 , V_165 , V_471 , V_46 ,
V_46 , V_472 ) ;
}
void F_416 ( struct V_112 * V_112 , T_2 V_169 , T_2 V_170 )
{
struct V_113 * V_114 ;
struct V_102 * V_165 ;
int V_108 ;
F_247 ( & V_112 -> V_216 ) ;
for ( V_108 = 0 ; V_108 < V_166 ; V_108 ++ ) {
V_114 = F_152 ( V_112 , V_108 ) ;
F_153 (memslot, slots) {
T_2 V_163 , V_164 ;
V_163 = F_154 ( V_169 , V_165 -> V_105 ) ;
V_164 = V_79 ( V_170 , V_165 -> V_105 + V_165 -> V_172 ) ;
if ( V_163 >= V_164 )
continue;
F_411 ( V_112 , V_165 , F_139 ,
V_46 , V_110 ,
V_163 , V_164 - 1 , true ) ;
}
}
F_248 ( & V_112 -> V_216 ) ;
}
static bool F_417 ( struct V_112 * V_112 ,
struct V_129 * V_130 )
{
return F_127 ( V_112 , V_130 , false ) ;
}
void F_418 ( struct V_112 * V_112 ,
struct V_102 * V_165 )
{
bool V_68 ;
F_247 ( & V_112 -> V_216 ) ;
V_68 = F_413 ( V_112 , V_165 , F_417 ,
false ) ;
F_248 ( & V_112 -> V_216 ) ;
F_419 ( & V_112 -> V_473 ) ;
if ( V_68 )
F_125 ( V_112 ) ;
}
static bool F_420 ( struct V_112 * V_112 ,
struct V_129 * V_130 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
int V_474 = 0 ;
T_3 V_24 ;
struct V_52 * V_53 ;
V_155:
F_128 (rmap_head, &iter, sptep) {
V_53 = F_38 ( F_39 ( V_17 ) ) ;
V_24 = F_28 ( * V_17 ) ;
if ( V_53 -> V_97 . V_98 &&
! F_52 ( V_24 ) &&
F_280 ( F_54 ( V_24 ) ) ) {
F_122 ( V_112 , V_17 ) ;
V_474 = 1 ;
goto V_155;
}
}
return V_474 ;
}
void F_421 ( struct V_112 * V_112 ,
const struct V_102 * V_165 )
{
F_247 ( & V_112 -> V_216 ) ;
F_415 ( V_112 , (struct V_102 * ) V_165 ,
F_420 , true ) ;
F_248 ( & V_112 -> V_216 ) ;
}
void F_422 ( struct V_112 * V_112 ,
struct V_102 * V_165 )
{
bool V_68 ;
F_247 ( & V_112 -> V_216 ) ;
V_68 = F_415 ( V_112 , V_165 , F_130 , false ) ;
F_248 ( & V_112 -> V_216 ) ;
F_419 ( & V_112 -> V_473 ) ;
if ( V_68 )
F_125 ( V_112 ) ;
}
void F_423 ( struct V_112 * V_112 ,
struct V_102 * V_165 )
{
bool V_68 ;
F_247 ( & V_112 -> V_216 ) ;
V_68 = F_414 ( V_112 , V_165 , F_417 ,
false ) ;
F_248 ( & V_112 -> V_216 ) ;
F_419 ( & V_112 -> V_473 ) ;
if ( V_68 )
F_125 ( V_112 ) ;
}
void F_424 ( struct V_112 * V_112 ,
struct V_102 * V_165 )
{
bool V_68 ;
F_247 ( & V_112 -> V_216 ) ;
V_68 = F_413 ( V_112 , V_165 , F_132 , false ) ;
F_248 ( & V_112 -> V_216 ) ;
F_419 ( & V_112 -> V_473 ) ;
if ( V_68 )
F_125 ( V_112 ) ;
}
static void F_425 ( struct V_112 * V_112 )
{
struct V_52 * V_53 , * V_443 ;
int V_475 = 0 ;
V_155:
F_426 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_118 ;
if ( ! F_206 ( V_112 , V_53 ) )
break;
if ( V_53 -> V_97 . V_247 )
continue;
if ( V_475 >= V_476 &&
F_218 ( & V_112 -> V_216 ) ) {
V_475 = 0 ;
goto V_155;
}
V_118 = F_199 ( V_112 , V_53 ,
& V_112 -> V_40 . V_477 ) ;
V_475 += V_118 ;
if ( V_118 )
goto V_155;
}
F_202 ( V_112 , & V_112 -> V_40 . V_477 ) ;
}
void F_406 ( struct V_112 * V_112 )
{
F_247 ( & V_112 -> V_216 ) ;
F_427 ( V_112 ) ;
V_112 -> V_40 . V_208 ++ ;
F_242 ( V_112 ) ;
F_425 ( V_112 ) ;
F_248 ( & V_112 -> V_216 ) ;
}
static bool F_428 ( struct V_112 * V_112 )
{
return F_15 ( ! F_429 ( & V_112 -> V_40 . V_477 ) ) ;
}
void F_430 ( struct V_112 * V_112 , struct V_113 * V_114 )
{
if ( F_15 ( ( V_114 -> V_16 & V_9 ) == 0 ) ) {
F_431 ( L_34 ) ;
F_406 ( V_112 ) ;
}
}
static unsigned long
F_432 ( struct V_478 * V_479 , struct V_480 * V_481 )
{
struct V_112 * V_112 ;
int V_482 = V_481 -> V_482 ;
unsigned long V_483 = 0 ;
F_247 ( & V_484 ) ;
F_433 (kvm, &vm_list, vm_list) {
int V_104 ;
F_214 ( V_200 ) ;
if ( ! V_482 -- )
break;
if ( ! V_112 -> V_40 . V_178 &&
! F_428 ( V_112 ) )
continue;
V_104 = F_434 ( & V_112 -> V_485 ) ;
F_247 ( & V_112 -> V_216 ) ;
if ( F_428 ( V_112 ) ) {
F_202 ( V_112 ,
& V_112 -> V_40 . V_477 ) ;
goto V_486;
}
if ( F_244 ( V_112 , & V_200 ) )
V_483 ++ ;
F_202 ( V_112 , & V_200 ) ;
V_486:
F_248 ( & V_112 -> V_216 ) ;
F_435 ( & V_112 -> V_485 , V_104 ) ;
F_436 ( & V_112 -> V_487 , & V_487 ) ;
break;
}
F_248 ( & V_484 ) ;
return V_483 ;
}
static unsigned long
F_437 ( struct V_478 * V_479 , struct V_480 * V_481 )
{
return F_438 ( & V_179 ) ;
}
static void F_439 ( void )
{
if ( V_89 )
F_440 ( V_89 ) ;
if ( V_93 )
F_440 ( V_93 ) ;
}
int F_441 ( void )
{
F_21 () ;
V_89 = F_442 ( L_35 ,
sizeof( struct V_95 ) ,
0 , 0 , NULL ) ;
if ( ! V_89 )
goto V_488;
V_93 = F_442 ( L_36 ,
sizeof( struct V_52 ) ,
0 , 0 , NULL ) ;
if ( ! V_93 )
goto V_488;
if ( F_443 ( & V_179 , 0 , V_83 ) )
goto V_488;
F_444 ( & V_489 ) ;
return 0 ;
V_488:
F_439 () ;
return - V_84 ;
}
unsigned int F_445 ( struct V_112 * V_112 )
{
unsigned int V_490 ;
unsigned int V_491 = 0 ;
struct V_113 * V_114 ;
struct V_102 * V_165 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_166 ; V_108 ++ ) {
V_114 = F_152 ( V_112 , V_108 ) ;
F_153 (memslot, slots)
V_491 += V_165 -> V_172 ;
}
V_490 = V_491 * V_492 / 1000 ;
V_490 = F_154 ( V_490 ,
( unsigned int ) V_493 ) ;
return V_490 ;
}
void F_446 ( struct V_14 * V_15 )
{
F_376 ( V_15 ) ;
F_399 ( V_15 ) ;
F_81 ( V_15 ) ;
}
void F_447 ( void )
{
F_439 () ;
F_448 ( & V_179 ) ;
F_449 ( & V_489 ) ;
F_205 () ;
}
