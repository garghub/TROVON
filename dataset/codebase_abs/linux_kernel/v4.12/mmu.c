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
int F_137 ( struct V_14 * V_15 )
{
if ( V_127 -> V_149 )
return V_127 -> V_149 ( V_15 ) ;
return 0 ;
}
bool F_138 ( struct V_112 * V_112 ,
struct V_102 * V_103 , T_1 V_18 )
{
struct V_129 * V_130 ;
int V_108 ;
bool V_150 = false ;
for ( V_108 = V_46 ; V_108 <= V_110 ; ++ V_108 ) {
V_130 = F_115 ( V_18 , V_108 , V_103 ) ;
V_150 |= F_127 ( V_112 , V_130 , true ) ;
}
return V_150 ;
}
static bool F_139 ( struct V_14 * V_15 , T_1 V_18 )
{
struct V_102 * V_103 ;
V_103 = F_101 ( V_15 , V_18 ) ;
return F_138 ( V_15 -> V_112 , V_103 , V_18 ) ;
}
static bool F_140 ( struct V_112 * V_112 , struct V_129 * V_130 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
bool V_68 = false ;
while ( ( V_17 = F_120 ( V_130 , & V_142 ) ) ) {
F_109 ( L_14 , V_151 , V_17 , * V_17 ) ;
F_122 ( V_112 , V_17 ) ;
V_68 = true ;
}
return V_68 ;
}
static int F_141 ( struct V_112 * V_112 , struct V_129 * V_130 ,
struct V_102 * V_103 , T_2 V_18 , int V_45 ,
unsigned long V_152 )
{
return F_140 ( V_112 , V_130 ) ;
}
static int F_142 ( struct V_112 * V_112 , struct V_129 * V_130 ,
struct V_102 * V_103 , T_2 V_18 , int V_45 ,
unsigned long V_152 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
int V_153 = 0 ;
T_1 V_66 ;
T_5 * V_154 = ( T_5 * ) V_152 ;
T_3 V_155 ;
F_4 ( F_143 ( * V_154 ) ) ;
V_155 = F_144 ( * V_154 ) ;
V_156:
F_128 (rmap_head, &iter, sptep) {
F_109 ( L_15 ,
V_17 , * V_17 , V_18 , V_45 ) ;
V_153 = 1 ;
if ( F_145 ( * V_154 ) ) {
F_122 ( V_112 , V_17 ) ;
goto V_156;
} else {
V_66 = * V_17 & ~ V_47 ;
V_66 |= ( T_1 ) V_155 << V_22 ;
V_66 &= ~ V_65 ;
V_66 &= ~ V_63 ;
V_66 = F_57 ( V_66 ) ;
F_51 ( V_17 ) ;
F_10 ( V_17 , V_66 ) ;
}
}
if ( V_153 )
F_125 ( V_112 ) ;
return 0 ;
}
static void
F_146 ( struct V_157 * V_158 , int V_45 )
{
V_158 -> V_45 = V_45 ;
V_158 -> V_18 = V_158 -> V_159 ;
V_158 -> V_139 = F_115 ( V_158 -> V_18 , V_45 , V_158 -> V_103 ) ;
V_158 -> V_160 = F_115 ( V_158 -> V_161 , V_45 ,
V_158 -> V_103 ) ;
}
static void
F_147 ( struct V_157 * V_158 ,
struct V_102 * V_103 , int V_162 ,
int V_163 , T_2 V_159 , T_2 V_161 )
{
V_158 -> V_103 = V_103 ;
V_158 -> V_162 = V_162 ;
V_158 -> V_163 = V_163 ;
V_158 -> V_159 = V_159 ;
V_158 -> V_161 = V_161 ;
F_146 ( V_158 , V_158 -> V_162 ) ;
}
static bool F_148 ( struct V_157 * V_158 )
{
return ! ! V_158 -> V_139 ;
}
static void F_149 ( struct V_157 * V_158 )
{
if ( ++ V_158 -> V_139 <= V_158 -> V_160 ) {
V_158 -> V_18 += ( 1UL << F_150 ( V_158 -> V_45 ) ) ;
return;
}
if ( ++ V_158 -> V_45 > V_158 -> V_163 ) {
V_158 -> V_139 = NULL ;
return;
}
F_146 ( V_158 , V_158 -> V_45 ) ;
}
static int F_151 ( struct V_112 * V_112 ,
unsigned long V_164 ,
unsigned long V_165 ,
unsigned long V_152 ,
int (* F_152)( struct V_112 * V_112 ,
struct V_129 * V_130 ,
struct V_102 * V_103 ,
T_2 V_18 ,
int V_45 ,
unsigned long V_152 ) )
{
struct V_113 * V_114 ;
struct V_102 * V_166 ;
struct V_157 V_158 ;
int V_118 = 0 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_167 ; V_108 ++ ) {
V_114 = F_153 ( V_112 , V_108 ) ;
F_154 (memslot, slots) {
unsigned long V_168 , V_169 ;
T_2 V_170 , V_171 ;
V_168 = F_155 ( V_164 , V_166 -> V_172 ) ;
V_169 = V_79 ( V_165 , V_166 -> V_172 +
( V_166 -> V_173 << V_22 ) ) ;
if ( V_168 >= V_169 )
continue;
V_170 = F_156 ( V_168 , V_166 ) ;
V_171 = F_156 ( V_169 + V_174 - 1 , V_166 ) ;
F_157 (memslot, PT_PAGE_TABLE_LEVEL,
PT_MAX_HUGEPAGE_LEVEL,
gfn_start, gfn_end - 1 ,
&iterator)
V_118 |= F_152 ( V_112 , V_158 . V_139 , V_166 ,
V_158 . V_18 , V_158 . V_45 , V_152 ) ;
}
}
return V_118 ;
}
static int F_158 ( struct V_112 * V_112 , unsigned long V_175 ,
unsigned long V_152 ,
int (* F_152)( struct V_112 * V_112 ,
struct V_129 * V_130 ,
struct V_102 * V_103 ,
T_2 V_18 , int V_45 ,
unsigned long V_152 ) )
{
return F_151 ( V_112 , V_175 , V_175 + 1 , V_152 , F_152 ) ;
}
int F_159 ( struct V_112 * V_112 , unsigned long V_175 )
{
return F_158 ( V_112 , V_175 , 0 , F_141 ) ;
}
int F_160 ( struct V_112 * V_112 , unsigned long V_164 , unsigned long V_165 )
{
return F_151 ( V_112 , V_164 , V_165 , 0 , F_141 ) ;
}
void F_161 ( struct V_112 * V_112 , unsigned long V_175 , T_5 V_43 )
{
F_158 ( V_112 , V_175 , ( unsigned long ) & V_43 , F_142 ) ;
}
static int F_162 ( struct V_112 * V_112 , struct V_129 * V_130 ,
struct V_102 * V_103 , T_2 V_18 , int V_45 ,
unsigned long V_152 )
{
T_1 * V_17 ;
struct V_141 V_176 ( V_142 ) ;
int V_177 = 0 ;
F_128 (rmap_head, &iter, sptep)
V_177 |= F_61 ( V_17 ) ;
F_163 ( V_18 , V_45 , V_103 , V_177 ) ;
return V_177 ;
}
static int F_164 ( struct V_112 * V_112 , struct V_129 * V_130 ,
struct V_102 * V_103 , T_2 V_18 ,
int V_45 , unsigned long V_152 )
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
static void F_165 ( struct V_14 * V_15 , T_1 * V_4 , T_2 V_18 )
{
struct V_129 * V_130 ;
struct V_52 * V_53 ;
V_53 = F_38 ( F_39 ( V_4 ) ) ;
V_130 = F_116 ( V_15 -> V_112 , V_18 , V_53 ) ;
F_141 ( V_15 -> V_112 , V_130 , NULL , V_18 , V_53 -> V_97 . V_45 , 0 ) ;
F_125 ( V_15 -> V_112 ) ;
}
int F_166 ( struct V_112 * V_112 , unsigned long V_164 , unsigned long V_165 )
{
if ( ! V_35 && ! V_5 )
return F_151 ( V_112 , V_164 , V_165 , 0 ,
F_141 ) ;
return F_151 ( V_112 , V_164 , V_165 , 0 , F_162 ) ;
}
int F_167 ( struct V_112 * V_112 , unsigned long V_175 )
{
return F_158 ( V_112 , V_175 , 0 , F_164 ) ;
}
static int F_168 ( T_1 * V_140 )
{
T_1 * V_143 ;
T_1 * V_165 ;
for ( V_143 = V_140 , V_165 = V_143 + V_174 / sizeof( T_1 ) ; V_143 != V_165 ; V_143 ++ )
if ( F_24 ( * V_143 ) ) {
F_112 ( V_138 L_16 , V_151 ,
V_143 , * V_143 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_169 ( struct V_112 * V_112 , int V_178 )
{
V_112 -> V_40 . V_179 += V_178 ;
F_170 ( & V_180 , V_178 ) ;
}
static void F_171 ( struct V_52 * V_53 )
{
F_172 ( ! F_168 ( V_53 -> V_140 ) ) ;
F_173 ( & V_53 -> V_181 ) ;
F_174 ( & V_53 -> V_182 ) ;
F_79 ( ( unsigned long ) V_53 -> V_140 ) ;
if ( ! V_53 -> V_97 . V_98 )
F_79 ( ( unsigned long ) V_53 -> V_99 ) ;
F_75 ( V_93 , V_53 ) ;
}
static unsigned F_175 ( T_2 V_18 )
{
return F_176 ( V_18 , V_183 ) ;
}
static void F_177 ( struct V_14 * V_15 ,
struct V_52 * V_53 , T_1 * V_184 )
{
if ( ! V_184 )
return;
F_108 ( V_15 , V_184 , & V_53 -> V_185 ) ;
}
static void F_178 ( struct V_52 * V_53 ,
T_1 * V_184 )
{
F_111 ( V_184 , & V_53 -> V_185 ) ;
}
static void F_179 ( struct V_52 * V_53 ,
T_1 * V_184 )
{
F_178 ( V_53 , V_184 ) ;
F_55 ( V_184 ) ;
}
static struct V_52 * F_180 ( struct V_14 * V_15 , int V_98 )
{
struct V_52 * V_53 ;
V_53 = F_82 ( & V_15 -> V_40 . V_93 ) ;
V_53 -> V_140 = F_82 ( & V_15 -> V_40 . V_92 ) ;
if ( ! V_98 )
V_53 -> V_99 = F_82 ( & V_15 -> V_40 . V_92 ) ;
F_181 ( F_182 ( V_53 -> V_140 ) , ( unsigned long ) V_53 ) ;
F_183 ( & V_53 -> V_182 , & V_15 -> V_112 -> V_40 . V_186 ) ;
F_169 ( V_15 -> V_112 , + 1 ) ;
return V_53 ;
}
static void F_184 ( struct V_52 * V_53 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
F_128 (&sp->parent_ptes, &iter, sptep) {
F_185 ( V_17 ) ;
}
}
static void F_185 ( T_1 * V_4 )
{
struct V_52 * V_53 ;
unsigned int V_96 ;
V_53 = F_38 ( F_39 ( V_4 ) ) ;
V_96 = V_4 - V_53 -> V_140 ;
if ( F_186 ( V_96 , V_53 -> V_187 ) )
return;
if ( V_53 -> V_188 ++ )
return;
F_184 ( V_53 ) ;
}
static int F_187 ( struct V_14 * V_15 ,
struct V_52 * V_53 )
{
return 0 ;
}
static void F_188 ( struct V_14 * V_15 , T_6 V_189 )
{
}
static void F_189 ( struct V_14 * V_15 ,
struct V_52 * V_53 , T_1 * V_4 ,
const void * V_43 )
{
F_4 ( 1 ) ;
}
static int F_190 ( struct V_190 * V_191 , struct V_52 * V_53 ,
int V_104 )
{
int V_108 ;
if ( V_53 -> V_192 )
for ( V_108 = 0 ; V_108 < V_191 -> V_178 ; V_108 ++ )
if ( V_191 -> V_86 [ V_108 ] . V_53 == V_53 )
return 0 ;
V_191 -> V_86 [ V_191 -> V_178 ] . V_53 = V_53 ;
V_191 -> V_86 [ V_191 -> V_178 ] . V_104 = V_104 ;
V_191 -> V_178 ++ ;
return ( V_191 -> V_178 == V_193 ) ;
}
static inline void F_191 ( struct V_52 * V_53 , int V_104 )
{
-- V_53 -> V_188 ;
F_4 ( ( int ) V_53 -> V_188 < 0 ) ;
F_192 ( V_104 , V_53 -> V_187 ) ;
}
static int F_193 ( struct V_52 * V_53 ,
struct V_190 * V_191 )
{
int V_108 , V_118 , V_194 = 0 ;
F_194 (i, sp->unsync_child_bitmap, 512 ) {
struct V_52 * V_195 ;
T_1 V_196 = V_53 -> V_140 [ V_108 ] ;
if ( ! F_24 ( V_196 ) || F_25 ( V_196 ) ) {
F_191 ( V_53 , V_108 ) ;
continue;
}
V_195 = F_38 ( V_196 & V_47 ) ;
if ( V_195 -> V_188 ) {
if ( F_190 ( V_191 , V_195 , V_108 ) )
return - V_197 ;
V_118 = F_193 ( V_195 , V_191 ) ;
if ( ! V_118 ) {
F_191 ( V_53 , V_108 ) ;
continue;
} else if ( V_118 > 0 ) {
V_194 += V_118 ;
} else
return V_118 ;
} else if ( V_195 -> V_192 ) {
V_194 ++ ;
if ( F_190 ( V_191 , V_195 , V_108 ) )
return - V_197 ;
} else
F_191 ( V_53 , V_108 ) ;
}
return V_194 ;
}
static int F_195 ( struct V_52 * V_53 ,
struct V_190 * V_191 )
{
V_191 -> V_178 = 0 ;
if ( ! V_53 -> V_188 )
return 0 ;
F_190 ( V_191 , V_53 , V_198 ) ;
return F_193 ( V_53 , V_191 ) ;
}
static void F_196 ( struct V_112 * V_112 , struct V_52 * V_53 )
{
F_4 ( ! V_53 -> V_192 ) ;
F_197 ( V_53 ) ;
V_53 -> V_192 = 0 ;
-- V_112 -> V_144 . V_199 ;
}
static bool F_198 ( struct V_14 * V_15 , struct V_52 * V_53 ,
struct V_200 * V_201 )
{
if ( V_53 -> V_97 . V_202 != ! ! F_199 ( V_15 ) ) {
F_200 ( V_15 -> V_112 , V_53 , V_201 ) ;
return false ;
}
if ( V_15 -> V_40 . V_203 . V_204 ( V_15 , V_53 ) == 0 ) {
F_200 ( V_15 -> V_112 , V_53 , V_201 ) ;
return false ;
}
return true ;
}
static void F_201 ( struct V_14 * V_15 ,
struct V_200 * V_201 ,
bool V_205 , bool V_206 )
{
if ( ! F_202 ( V_201 ) ) {
F_203 ( V_15 -> V_112 , V_201 ) ;
return;
}
if ( V_205 )
F_125 ( V_15 -> V_112 ) ;
else if ( V_206 )
F_204 ( V_207 , V_15 ) ;
}
static void F_205 ( struct V_14 * V_15 , int V_208 ) { }
static void F_206 ( void ) { }
static bool F_207 ( struct V_112 * V_112 , struct V_52 * V_53 )
{
return F_15 ( V_53 -> V_209 != V_112 -> V_40 . V_209 ) ;
}
static bool F_208 ( struct V_14 * V_15 , struct V_52 * V_53 ,
struct V_200 * V_201 )
{
F_196 ( V_15 -> V_112 , V_53 ) ;
return F_198 ( V_15 , V_53 , V_201 ) ;
}
static bool F_209 ( struct V_14 * V_15 , T_2 V_18 ,
struct V_200 * V_201 )
{
struct V_52 * V_210 ;
bool V_118 = false ;
F_210 (vcpu->kvm, s, gfn) {
if ( ! V_210 -> V_192 )
continue;
F_4 ( V_210 -> V_97 . V_45 != V_46 ) ;
V_118 |= F_208 ( V_15 , V_210 , V_201 ) ;
}
return V_118 ;
}
static int F_211 ( struct V_190 * V_191 ,
struct V_211 * V_212 ,
int V_108 )
{
int V_213 ;
for ( V_213 = V_108 + 1 ; V_213 < V_191 -> V_178 ; V_213 ++ ) {
struct V_52 * V_53 = V_191 -> V_86 [ V_213 ] . V_53 ;
unsigned V_104 = V_191 -> V_86 [ V_213 ] . V_104 ;
int V_45 = V_53 -> V_97 . V_45 ;
V_212 -> V_104 [ V_45 - 1 ] = V_104 ;
if ( V_45 == V_46 )
break;
V_212 -> V_214 [ V_45 - 2 ] = V_53 ;
}
return V_213 ;
}
static int F_212 ( struct V_190 * V_191 ,
struct V_211 * V_212 )
{
struct V_52 * V_53 ;
int V_45 ;
if ( V_191 -> V_178 == 0 )
return 0 ;
F_4 ( V_191 -> V_86 [ 0 ] . V_104 != V_198 ) ;
V_53 = V_191 -> V_86 [ 0 ] . V_53 ;
V_45 = V_53 -> V_97 . V_45 ;
F_4 ( V_45 == V_46 ) ;
V_212 -> V_214 [ V_45 - 2 ] = V_53 ;
V_212 -> V_214 [ V_45 - 1 ] = NULL ;
return F_211 ( V_191 , V_212 , 0 ) ;
}
static void F_213 ( struct V_211 * V_212 )
{
struct V_52 * V_53 ;
unsigned int V_45 = 0 ;
do {
unsigned int V_104 = V_212 -> V_104 [ V_45 ] ;
V_53 = V_212 -> V_214 [ V_45 ] ;
if ( ! V_53 )
return;
F_4 ( V_104 == V_198 ) ;
F_191 ( V_53 , V_104 ) ;
V_45 ++ ;
} while ( ! V_53 -> V_188 );
}
static void F_214 ( struct V_14 * V_15 ,
struct V_52 * V_214 )
{
int V_108 ;
struct V_52 * V_53 ;
struct V_211 V_212 ;
struct V_190 V_215 ;
F_215 ( V_201 ) ;
bool V_68 = false ;
while ( F_195 ( V_214 , & V_215 ) ) {
bool V_216 = false ;
F_216 (pages, sp, parents, i)
V_216 |= F_139 ( V_15 , V_53 -> V_18 ) ;
if ( V_216 ) {
F_125 ( V_15 -> V_112 ) ;
V_68 = false ;
}
F_216 (pages, sp, parents, i) {
V_68 |= F_208 ( V_15 , V_53 , & V_201 ) ;
F_213 ( & V_212 ) ;
}
if ( F_217 () || F_218 ( & V_15 -> V_112 -> V_217 ) ) {
F_201 ( V_15 , & V_201 , false , V_68 ) ;
F_219 ( & V_15 -> V_112 -> V_217 ) ;
V_68 = false ;
}
}
F_201 ( V_15 , & V_201 , false , V_68 ) ;
}
static void F_220 ( struct V_52 * V_53 )
{
F_221 ( & V_53 -> V_218 , 0 ) ;
}
static void F_222 ( T_1 * V_4 )
{
struct V_52 * V_53 = F_38 ( F_39 ( V_4 ) ) ;
F_220 ( V_53 ) ;
}
static struct V_52 * F_223 ( struct V_14 * V_15 ,
T_2 V_18 ,
T_6 V_219 ,
unsigned V_45 ,
int V_98 ,
unsigned V_19 )
{
union V_220 V_97 ;
unsigned V_221 ;
struct V_52 * V_53 ;
bool V_222 = false ;
bool V_68 = false ;
int V_223 = 0 ;
F_215 ( V_201 ) ;
V_97 = V_15 -> V_40 . V_203 . V_224 ;
V_97 . V_45 = V_45 ;
V_97 . V_98 = V_98 ;
if ( V_97 . V_98 )
V_97 . V_202 = 0 ;
V_97 . V_19 = V_19 ;
if ( ! V_15 -> V_40 . V_203 . V_225
&& V_15 -> V_40 . V_203 . V_226 <= V_227 ) {
V_221 = V_219 >> ( V_22 + ( V_228 * V_45 ) ) ;
V_221 &= ( 1 << ( ( V_229 - V_228 ) * V_45 ) ) - 1 ;
V_97 . V_221 = V_221 ;
}
F_224 (vcpu->kvm, sp, gfn) {
if ( V_53 -> V_18 != V_18 ) {
V_223 ++ ;
continue;
}
if ( ! V_222 && V_53 -> V_192 )
V_222 = true ;
if ( V_53 -> V_97 . V_230 != V_97 . V_230 )
continue;
if ( V_53 -> V_192 ) {
if ( ! F_198 ( V_15 , V_53 , & V_201 ) )
break;
F_4 ( ! F_202 ( & V_201 ) ) ;
F_204 ( V_207 , V_15 ) ;
}
if ( V_53 -> V_188 )
F_204 ( V_231 , V_15 ) ;
F_220 ( V_53 ) ;
F_225 ( V_53 , false ) ;
goto V_91;
}
++ V_15 -> V_112 -> V_144 . V_232 ;
V_53 = F_180 ( V_15 , V_98 ) ;
V_53 -> V_18 = V_18 ;
V_53 -> V_97 = V_97 ;
F_226 ( & V_53 -> V_181 ,
& V_15 -> V_112 -> V_40 . V_233 [ F_175 ( V_18 ) ] ) ;
if ( ! V_98 ) {
F_93 ( V_15 -> V_112 , V_53 ) ;
if ( V_45 == V_46 &&
F_139 ( V_15 , V_18 ) )
F_125 ( V_15 -> V_112 ) ;
if ( V_45 > V_46 && V_222 )
V_68 |= F_209 ( V_15 , V_18 , & V_201 ) ;
}
V_53 -> V_209 = V_15 -> V_112 -> V_40 . V_209 ;
F_227 ( V_53 -> V_140 ) ;
F_225 ( V_53 , true ) ;
F_201 ( V_15 , & V_201 , false , V_68 ) ;
V_91:
if ( V_223 > V_15 -> V_112 -> V_144 . V_234 )
V_15 -> V_112 -> V_144 . V_234 = V_223 ;
return V_53 ;
}
static void F_228 ( struct V_235 * V_158 ,
struct V_14 * V_15 , T_1 V_236 )
{
V_158 -> V_236 = V_236 ;
V_158 -> V_237 = V_15 -> V_40 . V_203 . V_238 ;
V_158 -> V_45 = V_15 -> V_40 . V_203 . V_239 ;
if ( V_158 -> V_45 == V_240 &&
V_15 -> V_40 . V_203 . V_226 < V_240 &&
! V_15 -> V_40 . V_203 . V_225 )
-- V_158 -> V_45 ;
if ( V_158 -> V_45 == V_241 ) {
V_158 -> V_237
= V_15 -> V_40 . V_203 . V_242 [ ( V_236 >> 30 ) & 3 ] ;
V_158 -> V_237 &= V_47 ;
-- V_158 -> V_45 ;
if ( ! V_158 -> V_237 )
V_158 -> V_45 = 0 ;
}
}
static bool F_229 ( struct V_235 * V_158 )
{
if ( V_158 -> V_45 < V_46 )
return false ;
V_158 -> V_96 = F_230 ( V_158 -> V_236 , V_158 -> V_45 ) ;
V_158 -> V_17 = ( ( T_1 * ) F_231 ( V_158 -> V_237 ) ) + V_158 -> V_96 ;
return true ;
}
static void F_232 ( struct V_235 * V_158 ,
T_1 V_4 )
{
if ( F_26 ( V_4 , V_158 -> V_45 ) ) {
V_158 -> V_45 = 0 ;
return;
}
V_158 -> V_237 = V_4 & V_47 ;
-- V_158 -> V_45 ;
}
static void F_233 ( struct V_235 * V_158 )
{
return F_232 ( V_158 , * V_158 -> V_17 ) ;
}
static void F_234 ( struct V_14 * V_15 , T_1 * V_17 ,
struct V_52 * V_53 )
{
T_1 V_4 ;
F_235 ( V_243 != V_65 ) ;
V_4 = F_39 ( V_53 -> V_140 ) | V_39 | V_65 |
V_34 | V_38 | V_35 ;
F_10 ( V_17 , V_4 ) ;
F_177 ( V_15 , V_53 , V_17 ) ;
if ( V_53 -> V_188 || V_53 -> V_192 )
F_185 ( V_17 ) ;
}
static void F_236 ( struct V_14 * V_15 , T_1 * V_17 ,
unsigned V_244 )
{
if ( F_24 ( * V_17 ) && ! F_25 ( * V_17 ) ) {
struct V_52 * V_195 ;
V_195 = F_38 ( * V_17 & V_47 ) ;
if ( V_195 -> V_97 . V_19 == V_244 )
return;
F_179 ( V_195 , V_17 ) ;
F_125 ( V_15 -> V_112 ) ;
}
}
static bool F_237 ( struct V_112 * V_112 , struct V_52 * V_53 ,
T_1 * V_4 )
{
T_1 V_43 ;
struct V_52 * V_195 ;
V_43 = * V_4 ;
if ( F_24 ( V_43 ) ) {
if ( F_26 ( V_43 , V_53 -> V_97 . V_45 ) ) {
F_122 ( V_112 , V_4 ) ;
if ( F_25 ( V_43 ) )
-- V_112 -> V_144 . V_145 ;
} else {
V_195 = F_38 ( V_43 & V_47 ) ;
F_179 ( V_195 , V_4 ) ;
}
return true ;
}
if ( F_11 ( V_43 ) )
F_55 ( V_4 ) ;
return false ;
}
static void F_238 ( struct V_112 * V_112 ,
struct V_52 * V_53 )
{
unsigned V_108 ;
for ( V_108 = 0 ; V_108 < V_245 ; ++ V_108 )
F_237 ( V_112 , V_53 , V_53 -> V_140 + V_108 ) ;
}
static void F_239 ( struct V_112 * V_112 , struct V_52 * V_53 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
while ( ( V_17 = F_120 ( & V_53 -> V_185 , & V_142 ) ) )
F_179 ( V_53 , V_17 ) ;
}
static int F_240 ( struct V_112 * V_112 ,
struct V_52 * V_214 ,
struct V_200 * V_201 )
{
int V_108 , V_246 = 0 ;
struct V_211 V_212 ;
struct V_190 V_215 ;
if ( V_214 -> V_97 . V_45 == V_46 )
return 0 ;
while ( F_195 ( V_214 , & V_215 ) ) {
struct V_52 * V_53 ;
F_216 (pages, sp, parents, i) {
F_200 ( V_112 , V_53 , V_201 ) ;
F_213 ( & V_212 ) ;
V_246 ++ ;
}
}
return V_246 ;
}
static int F_200 ( struct V_112 * V_112 , struct V_52 * V_53 ,
struct V_200 * V_201 )
{
int V_118 ;
F_241 ( V_53 ) ;
++ V_112 -> V_144 . V_247 ;
V_118 = F_240 ( V_112 , V_53 , V_201 ) ;
F_238 ( V_112 , V_53 ) ;
F_239 ( V_112 , V_53 ) ;
if ( ! V_53 -> V_97 . V_248 && ! V_53 -> V_97 . V_98 )
F_97 ( V_112 , V_53 ) ;
if ( V_53 -> V_192 )
F_196 ( V_112 , V_53 ) ;
if ( ! V_53 -> V_249 ) {
V_118 ++ ;
F_242 ( & V_53 -> V_182 , V_201 ) ;
F_169 ( V_112 , - 1 ) ;
} else {
F_242 ( & V_53 -> V_182 , & V_112 -> V_40 . V_186 ) ;
if ( ! V_53 -> V_97 . V_248 && ! F_207 ( V_112 , V_53 ) )
F_243 ( V_112 ) ;
}
V_53 -> V_97 . V_248 = 1 ;
return V_118 ;
}
static void F_203 ( struct V_112 * V_112 ,
struct V_200 * V_201 )
{
struct V_52 * V_53 , * V_250 ;
if ( F_202 ( V_201 ) )
return;
F_125 ( V_112 ) ;
F_244 (sp, nsp, invalid_list, link) {
F_4 ( ! V_53 -> V_97 . V_248 || V_53 -> V_249 ) ;
F_171 ( V_53 ) ;
}
}
static bool F_245 ( struct V_112 * V_112 ,
struct V_200 * V_201 )
{
struct V_52 * V_53 ;
if ( F_202 ( & V_112 -> V_40 . V_186 ) )
return false ;
V_53 = F_246 ( & V_112 -> V_40 . V_186 ,
struct V_52 , V_182 ) ;
F_200 ( V_112 , V_53 , V_201 ) ;
return true ;
}
void F_247 ( struct V_112 * V_112 , unsigned int V_251 )
{
F_215 ( V_201 ) ;
F_248 ( & V_112 -> V_217 ) ;
if ( V_112 -> V_40 . V_179 > V_251 ) {
while ( V_112 -> V_40 . V_179 > V_251 )
if ( ! F_245 ( V_112 , & V_201 ) )
break;
F_203 ( V_112 , & V_201 ) ;
V_251 = V_112 -> V_40 . V_179 ;
}
V_112 -> V_40 . V_252 = V_251 ;
F_249 ( & V_112 -> V_217 ) ;
}
int F_250 ( struct V_112 * V_112 , T_2 V_18 )
{
struct V_52 * V_53 ;
F_215 ( V_201 ) ;
int V_87 ;
F_251 ( L_17 , V_151 , V_18 ) ;
V_87 = 0 ;
F_248 ( & V_112 -> V_217 ) ;
F_210 (kvm, sp, gfn) {
F_251 ( L_18 , V_151 , V_18 ,
V_53 -> V_97 . V_230 ) ;
V_87 = 1 ;
F_200 ( V_112 , V_53 , & V_201 ) ;
}
F_203 ( V_112 , & V_201 ) ;
F_249 ( & V_112 -> V_217 ) ;
return V_87 ;
}
static void F_252 ( struct V_14 * V_15 , struct V_52 * V_53 )
{
F_253 ( V_53 ) ;
++ V_15 -> V_112 -> V_144 . V_199 ;
V_53 -> V_192 = 1 ;
F_184 ( V_53 ) ;
}
static bool F_254 ( struct V_14 * V_15 , T_2 V_18 ,
bool V_253 )
{
struct V_52 * V_53 ;
if ( F_255 ( V_15 , V_18 , V_116 ) )
return true ;
F_210 (vcpu->kvm, sp, gfn) {
if ( ! V_253 )
return true ;
if ( V_53 -> V_192 )
continue;
F_4 ( V_53 -> V_97 . V_45 != V_46 ) ;
F_252 ( V_15 , V_53 ) ;
}
return false ;
}
static bool F_256 ( T_3 V_24 )
{
if ( F_257 ( V_24 ) )
return ! F_258 ( V_24 ) && F_259 ( F_54 ( V_24 ) ) ;
return true ;
}
static int F_260 ( struct V_14 * V_15 , T_1 * V_17 ,
unsigned V_254 , int V_45 ,
T_2 V_18 , T_3 V_24 , bool V_255 ,
bool V_253 , bool V_256 )
{
T_1 V_4 = 0 ;
int V_118 = 0 ;
if ( F_14 ( V_15 , V_17 , V_18 , V_24 , V_254 ) )
return 0 ;
V_4 |= V_39 ;
if ( ! V_255 )
V_4 |= V_35 ;
if ( V_254 & V_257 )
V_4 |= V_38 ;
else
V_4 |= V_37 ;
if ( V_254 & V_21 )
V_4 |= V_34 ;
if ( V_45 > V_46 )
V_4 |= V_44 ;
if ( V_258 )
V_4 |= V_127 -> V_259 ( V_15 , V_18 ,
F_256 ( V_24 ) ) ;
if ( V_256 )
V_4 |= V_63 ;
else
V_254 &= ~ V_20 ;
V_4 |= ( T_1 ) V_24 << V_22 ;
if ( V_254 & V_20 ) {
if ( V_45 > V_46 &&
F_100 ( V_15 , V_18 , V_45 ) )
goto V_260;
V_4 |= V_65 | V_64 ;
if ( ! V_253 && F_44 ( * V_17 ) )
goto V_261;
if ( F_254 ( V_15 , V_18 , V_253 ) ) {
F_251 ( L_19 ,
V_151 , V_18 ) ;
V_118 = 1 ;
V_254 &= ~ V_20 ;
V_4 &= ~ ( V_65 | V_64 ) ;
}
}
if ( V_254 & V_20 ) {
F_261 ( V_15 , V_18 ) ;
V_4 |= V_36 ;
}
if ( V_255 )
V_4 = F_57 ( V_4 ) ;
V_261:
if ( F_48 ( V_17 , V_4 ) )
F_125 ( V_15 -> V_112 ) ;
V_260:
return V_118 ;
}
static bool F_262 ( struct V_14 * V_15 , T_1 * V_17 , unsigned V_254 ,
int V_262 , int V_45 , T_2 V_18 , T_3 V_24 ,
bool V_255 , bool V_256 )
{
int V_263 = 0 ;
int V_264 ;
bool V_265 = false ;
F_251 ( L_20 , V_151 ,
* V_17 , V_262 , V_18 ) ;
if ( F_24 ( * V_17 ) ) {
if ( V_45 > V_46 &&
! F_25 ( * V_17 ) ) {
struct V_52 * V_195 ;
T_1 V_43 = * V_17 ;
V_195 = F_38 ( V_43 & V_47 ) ;
F_179 ( V_195 , V_17 ) ;
F_125 ( V_15 -> V_112 ) ;
} else if ( V_24 != F_28 ( * V_17 ) ) {
F_251 ( L_21 ,
F_28 ( * V_17 ) , V_24 ) ;
F_122 ( V_15 -> V_112 , V_17 ) ;
F_125 ( V_15 -> V_112 ) ;
} else
V_263 = 1 ;
}
if ( F_260 ( V_15 , V_17 , V_254 , V_45 , V_18 , V_24 , V_255 ,
true , V_256 ) ) {
if ( V_262 )
V_265 = true ;
F_204 ( V_207 , V_15 ) ;
}
if ( F_15 ( F_11 ( * V_17 ) ) )
V_265 = true ;
F_251 ( L_22 , V_151 , * V_17 ) ;
F_251 ( L_23 ,
F_25 ( * V_17 ) ? L_24 : L_25 ,
* V_17 & V_65 ? L_26 : L_27 , V_18 ,
* V_17 , V_17 ) ;
if ( ! V_263 && F_25 ( * V_17 ) )
++ V_15 -> V_112 -> V_144 . V_145 ;
if ( F_24 ( * V_17 ) ) {
if ( ! V_263 ) {
V_264 = F_118 ( V_15 , V_17 , V_18 ) ;
if ( V_264 > V_266 )
F_165 ( V_15 , V_17 , V_18 ) ;
}
}
F_263 ( V_24 ) ;
return V_265 ;
}
static T_3 F_264 ( struct V_14 * V_15 , T_2 V_18 ,
bool V_119 )
{
struct V_102 * V_103 ;
V_103 = F_106 ( V_15 , V_18 , V_119 ) ;
if ( ! V_103 )
return V_267 ;
return F_265 ( V_103 , V_18 ) ;
}
static int F_266 ( struct V_14 * V_15 ,
struct V_52 * V_53 ,
T_1 * V_164 , T_1 * V_165 )
{
struct V_86 * V_215 [ V_90 ] ;
struct V_102 * V_103 ;
unsigned V_19 = V_53 -> V_97 . V_19 ;
int V_108 , V_118 ;
T_2 V_18 ;
V_18 = F_86 ( V_53 , V_164 - V_53 -> V_140 ) ;
V_103 = F_106 ( V_15 , V_18 , V_19 & V_20 ) ;
if ( ! V_103 )
return - 1 ;
V_118 = F_267 ( V_103 , V_18 , V_215 , V_165 - V_164 ) ;
if ( V_118 <= 0 )
return - 1 ;
for ( V_108 = 0 ; V_108 < V_118 ; V_108 ++ , V_18 ++ , V_164 ++ )
F_262 ( V_15 , V_164 , V_19 , 0 , V_53 -> V_97 . V_45 , V_18 ,
F_268 ( V_215 [ V_108 ] ) , true , true ) ;
return 0 ;
}
static void F_269 ( struct V_14 * V_15 ,
struct V_52 * V_53 , T_1 * V_17 )
{
T_1 * V_4 , * V_164 = NULL ;
int V_108 ;
F_4 ( ! V_53 -> V_97 . V_98 ) ;
V_108 = ( V_17 - V_53 -> V_140 ) & ~ ( V_90 - 1 ) ;
V_4 = V_53 -> V_140 + V_108 ;
for ( V_108 = 0 ; V_108 < V_90 ; V_108 ++ , V_4 ++ ) {
if ( F_24 ( * V_4 ) || V_4 == V_17 ) {
if ( ! V_164 )
continue;
if ( F_266 ( V_15 , V_53 , V_164 , V_4 ) < 0 )
break;
V_164 = NULL ;
} else if ( ! V_164 )
V_164 = V_4 ;
}
}
static void F_270 ( struct V_14 * V_15 , T_1 * V_17 )
{
struct V_52 * V_53 ;
if ( ! V_35 )
return;
V_53 = F_38 ( F_39 ( V_17 ) ) ;
if ( V_53 -> V_97 . V_45 > V_46 )
return;
F_269 ( V_15 , V_53 , V_17 ) ;
}
static int F_271 ( struct V_14 * V_15 , int V_268 , int V_269 ,
int V_45 , T_2 V_18 , T_3 V_24 , bool V_270 )
{
struct V_235 V_158 ;
struct V_52 * V_53 ;
int V_265 = 0 ;
T_2 V_271 ;
if ( ! F_272 ( V_15 -> V_40 . V_203 . V_238 ) )
return 0 ;
F_273 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_158 . V_45 == V_45 ) {
V_265 = F_262 ( V_15 , V_158 . V_17 , V_272 ,
V_268 , V_45 , V_18 , V_24 , V_270 ,
V_269 ) ;
F_270 ( V_15 , V_158 . V_17 ) ;
++ V_15 -> V_144 . V_273 ;
break;
}
F_124 ( V_15 , V_158 . V_17 ) ;
if ( ! F_24 ( * V_158 . V_17 ) ) {
T_1 V_274 = V_158 . V_236 ;
V_274 &= F_274 ( V_158 . V_45 ) ;
V_271 = V_274 >> V_22 ;
V_53 = F_223 ( V_15 , V_271 , V_158 . V_236 ,
V_158 . V_45 - 1 , 1 , V_272 ) ;
F_234 ( V_15 , V_158 . V_17 , V_53 ) ;
}
}
return V_265 ;
}
static void F_275 ( unsigned long V_275 , struct V_276 * V_277 )
{
T_7 V_278 ;
V_278 . V_279 = V_280 ;
V_278 . V_281 = 0 ;
V_278 . V_282 = V_283 ;
V_278 . V_284 = ( void V_285 * ) V_275 ;
V_278 . V_286 = V_22 ;
F_276 ( V_280 , & V_278 , V_277 ) ;
}
static int F_277 ( struct V_14 * V_15 , T_2 V_18 , T_3 V_24 )
{
if ( V_24 == V_287 )
return 1 ;
if ( V_24 == V_288 ) {
F_275 ( F_278 ( V_15 , V_18 ) , V_289 ) ;
return 0 ;
}
return - V_290 ;
}
static void F_279 ( struct V_14 * V_15 ,
T_2 * V_291 , T_3 * V_292 ,
int * V_293 )
{
T_3 V_24 = * V_292 ;
T_2 V_18 = * V_291 ;
int V_45 = * V_293 ;
if ( ! F_280 ( V_24 ) && ! F_52 ( V_24 ) &&
V_45 == V_46 &&
F_281 ( F_54 ( V_24 ) ) &&
! F_100 ( V_15 , V_18 , V_109 ) ) {
unsigned long V_8 ;
* V_293 = V_45 = V_109 ;
V_8 = F_282 ( V_45 ) - 1 ;
F_283 ( ( V_18 & V_8 ) != ( V_24 & V_8 ) ) ;
if ( V_24 & V_8 ) {
V_18 &= ~ V_8 ;
* V_291 = V_18 ;
F_263 ( V_24 ) ;
V_24 &= ~ V_8 ;
F_284 ( V_24 ) ;
* V_292 = V_24 ;
}
}
}
static bool F_285 ( struct V_14 * V_15 , T_6 V_189 , T_2 V_18 ,
T_3 V_24 , unsigned V_19 , int * V_294 )
{
if ( F_15 ( F_286 ( V_24 ) ) ) {
* V_294 = F_277 ( V_15 , V_18 , V_24 ) ;
return true ;
}
if ( F_15 ( F_16 ( V_24 ) ) )
F_287 ( V_15 , V_189 , V_18 , V_19 ) ;
return false ;
}
static bool F_288 ( T_4 V_295 )
{
if ( F_15 ( V_295 & V_296 ) )
return false ;
if ( F_15 ( ( ( V_295 & ( V_297 | V_298 ) )
== ( V_297 | V_298 ) ) ) )
return false ;
return V_5 != 0 ||
( ( V_295 & ( V_299 | V_298 ) )
== ( V_299 | V_298 ) ) ;
}
static bool
F_289 ( struct V_14 * V_15 , struct V_52 * V_53 ,
T_1 * V_17 , T_1 V_67 , T_1 V_66 )
{
T_2 V_18 ;
F_4 ( ! V_53 -> V_97 . V_98 ) ;
if ( F_290 ( V_17 , V_67 , V_66 ) != V_67 )
return false ;
if ( F_44 ( V_66 ) && ! F_44 ( V_67 ) ) {
V_18 = F_86 ( V_53 , V_17 - V_53 -> V_140 ) ;
F_261 ( V_15 , V_18 ) ;
}
return true ;
}
static bool F_291 ( T_4 V_300 , T_1 V_4 )
{
if ( V_300 & V_297 )
return F_27 ( V_4 ) ;
if ( V_300 & V_299 )
return F_44 ( V_4 ) ;
return V_4 & V_301 ;
}
static bool F_292 ( struct V_14 * V_15 , T_6 V_189 , int V_45 ,
T_4 V_295 )
{
struct V_235 V_158 ;
struct V_52 * V_53 ;
bool V_302 = false ;
T_1 V_4 = 0ull ;
T_8 V_303 = 0 ;
if ( ! F_272 ( V_15 -> V_40 . V_203 . V_238 ) )
return false ;
if ( ! F_288 ( V_295 ) )
return false ;
F_64 ( V_15 ) ;
do {
T_1 V_66 ;
F_293 (vcpu, gva, iterator, spte)
if ( ! F_24 ( V_4 ) ||
V_158 . V_45 < V_45 )
break;
V_53 = F_38 ( F_39 ( V_158 . V_17 ) ) ;
if ( ! F_26 ( V_4 , V_53 -> V_97 . V_45 ) )
break;
if ( F_291 ( V_295 , V_4 ) ) {
V_302 = true ;
break;
}
V_66 = V_4 ;
if ( F_2 ( V_4 ) )
V_66 = F_59 ( V_66 ) ;
if ( ( V_295 & V_299 ) &&
F_42 ( V_4 ) )
{
V_66 |= V_65 ;
if ( V_53 -> V_97 . V_45 > V_46 )
break;
}
if ( V_66 == V_4 ||
! F_291 ( V_295 , V_66 ) )
break;
V_302 = F_289 ( V_15 , V_53 ,
V_158 . V_17 , V_4 ,
V_66 ) ;
if ( V_302 )
break;
if ( ++ V_303 > 4 ) {
F_294 ( V_304
L_28 ) ;
break;
}
} while ( true );
F_295 ( V_15 , V_189 , V_295 , V_158 . V_17 ,
V_4 , V_302 ) ;
F_67 ( V_15 ) ;
return V_302 ;
}
static int F_296 ( struct V_14 * V_15 , T_6 V_305 , T_4 V_295 ,
T_2 V_18 , bool V_270 )
{
int V_87 ;
int V_45 ;
bool V_124 = false ;
T_3 V_24 ;
unsigned long V_306 ;
bool V_269 , V_268 = V_295 & V_299 ;
V_45 = F_107 ( V_15 , V_18 , & V_124 ) ;
if ( F_19 ( ! V_124 ) ) {
if ( V_45 > V_109 )
V_45 = V_109 ;
V_18 &= ~ ( F_282 ( V_45 ) - 1 ) ;
}
if ( F_292 ( V_15 , V_305 , V_45 , V_295 ) )
return 0 ;
V_306 = V_15 -> V_112 -> V_307 ;
F_41 () ;
if ( F_297 ( V_15 , V_270 , V_18 , V_305 , & V_24 , V_268 , & V_269 ) )
return 0 ;
if ( F_285 ( V_15 , V_305 , V_18 , V_24 , V_272 , & V_87 ) )
return V_87 ;
F_248 ( & V_15 -> V_112 -> V_217 ) ;
if ( F_298 ( V_15 -> V_112 , V_306 ) )
goto V_308;
F_299 ( V_15 ) ;
if ( F_19 ( ! V_124 ) )
F_279 ( V_15 , & V_18 , & V_24 , & V_45 ) ;
V_87 = F_271 ( V_15 , V_268 , V_269 , V_45 , V_18 , V_24 , V_270 ) ;
F_249 ( & V_15 -> V_112 -> V_217 ) ;
return V_87 ;
V_308:
F_249 ( & V_15 -> V_112 -> V_217 ) ;
F_263 ( V_24 ) ;
return 0 ;
}
static void F_300 ( struct V_14 * V_15 )
{
int V_108 ;
struct V_52 * V_53 ;
F_215 ( V_201 ) ;
if ( ! F_272 ( V_15 -> V_40 . V_203 . V_238 ) )
return;
if ( V_15 -> V_40 . V_203 . V_239 == V_240 &&
( V_15 -> V_40 . V_203 . V_226 == V_240 ||
V_15 -> V_40 . V_203 . V_225 ) ) {
T_9 V_309 = V_15 -> V_40 . V_203 . V_238 ;
F_248 ( & V_15 -> V_112 -> V_217 ) ;
V_53 = F_38 ( V_309 ) ;
-- V_53 -> V_249 ;
if ( ! V_53 -> V_249 && V_53 -> V_97 . V_248 ) {
F_200 ( V_15 -> V_112 , V_53 , & V_201 ) ;
F_203 ( V_15 -> V_112 , & V_201 ) ;
}
F_249 ( & V_15 -> V_112 -> V_217 ) ;
V_15 -> V_40 . V_203 . V_238 = V_310 ;
return;
}
F_248 ( & V_15 -> V_112 -> V_217 ) ;
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
T_9 V_309 = V_15 -> V_40 . V_203 . V_242 [ V_108 ] ;
if ( V_309 ) {
V_309 &= V_47 ;
V_53 = F_38 ( V_309 ) ;
-- V_53 -> V_249 ;
if ( ! V_53 -> V_249 && V_53 -> V_97 . V_248 )
F_200 ( V_15 -> V_112 , V_53 ,
& V_201 ) ;
}
V_15 -> V_40 . V_203 . V_242 [ V_108 ] = V_310 ;
}
F_203 ( V_15 -> V_112 , & V_201 ) ;
F_249 ( & V_15 -> V_112 -> V_217 ) ;
V_15 -> V_40 . V_203 . V_238 = V_310 ;
}
static int F_301 ( struct V_14 * V_15 , T_2 V_311 )
{
int V_118 = 0 ;
if ( ! F_302 ( V_15 -> V_112 , V_311 ) ) {
F_204 ( V_312 , V_15 ) ;
V_118 = 1 ;
}
return V_118 ;
}
static int F_303 ( struct V_14 * V_15 )
{
struct V_52 * V_53 ;
unsigned V_108 ;
if ( V_15 -> V_40 . V_203 . V_239 == V_240 ) {
F_248 ( & V_15 -> V_112 -> V_217 ) ;
F_299 ( V_15 ) ;
V_53 = F_223 ( V_15 , 0 , 0 , V_240 , 1 , V_272 ) ;
++ V_53 -> V_249 ;
F_249 ( & V_15 -> V_112 -> V_217 ) ;
V_15 -> V_40 . V_203 . V_238 = F_39 ( V_53 -> V_140 ) ;
} else if ( V_15 -> V_40 . V_203 . V_239 == V_241 ) {
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
T_9 V_309 = V_15 -> V_40 . V_203 . V_242 [ V_108 ] ;
F_172 ( F_272 ( V_309 ) ) ;
F_248 ( & V_15 -> V_112 -> V_217 ) ;
F_299 ( V_15 ) ;
V_53 = F_223 ( V_15 , V_108 << ( 30 - V_22 ) ,
V_108 << 30 , V_227 , 1 , V_272 ) ;
V_309 = F_39 ( V_53 -> V_140 ) ;
++ V_53 -> V_249 ;
F_249 ( & V_15 -> V_112 -> V_217 ) ;
V_15 -> V_40 . V_203 . V_242 [ V_108 ] = V_309 | V_301 ;
}
V_15 -> V_40 . V_203 . V_238 = F_39 ( V_15 -> V_40 . V_203 . V_242 ) ;
} else
F_113 () ;
return 0 ;
}
static int F_304 ( struct V_14 * V_15 )
{
struct V_52 * V_53 ;
T_1 V_313 , V_314 ;
T_2 V_311 ;
int V_108 ;
V_311 = V_15 -> V_40 . V_203 . V_315 ( V_15 ) >> V_22 ;
if ( F_301 ( V_15 , V_311 ) )
return 1 ;
if ( V_15 -> V_40 . V_203 . V_226 == V_240 ) {
T_9 V_309 = V_15 -> V_40 . V_203 . V_238 ;
F_172 ( F_272 ( V_309 ) ) ;
F_248 ( & V_15 -> V_112 -> V_217 ) ;
F_299 ( V_15 ) ;
V_53 = F_223 ( V_15 , V_311 , 0 , V_240 ,
0 , V_272 ) ;
V_309 = F_39 ( V_53 -> V_140 ) ;
++ V_53 -> V_249 ;
F_249 ( & V_15 -> V_112 -> V_217 ) ;
V_15 -> V_40 . V_203 . V_238 = V_309 ;
return 0 ;
}
V_314 = V_301 ;
if ( V_15 -> V_40 . V_203 . V_239 == V_240 )
V_314 |= V_316 | V_65 | V_317 ;
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
T_9 V_309 = V_15 -> V_40 . V_203 . V_242 [ V_108 ] ;
F_172 ( F_272 ( V_309 ) ) ;
if ( V_15 -> V_40 . V_203 . V_226 == V_241 ) {
V_313 = V_15 -> V_40 . V_203 . V_318 ( V_15 , V_108 ) ;
if ( ! ( V_313 & V_301 ) ) {
V_15 -> V_40 . V_203 . V_242 [ V_108 ] = 0 ;
continue;
}
V_311 = V_313 >> V_22 ;
if ( F_301 ( V_15 , V_311 ) )
return 1 ;
}
F_248 ( & V_15 -> V_112 -> V_217 ) ;
F_299 ( V_15 ) ;
V_53 = F_223 ( V_15 , V_311 , V_108 << 30 , V_227 ,
0 , V_272 ) ;
V_309 = F_39 ( V_53 -> V_140 ) ;
++ V_53 -> V_249 ;
F_249 ( & V_15 -> V_112 -> V_217 ) ;
V_15 -> V_40 . V_203 . V_242 [ V_108 ] = V_309 | V_314 ;
}
V_15 -> V_40 . V_203 . V_238 = F_39 ( V_15 -> V_40 . V_203 . V_242 ) ;
if ( V_15 -> V_40 . V_203 . V_239 == V_240 ) {
if ( V_15 -> V_40 . V_203 . V_319 == NULL ) {
T_1 * V_319 ;
V_319 = ( void * ) F_305 ( V_83 ) ;
if ( V_319 == NULL )
return 1 ;
V_319 [ 0 ] = F_39 ( V_15 -> V_40 . V_203 . V_242 ) | V_314 ;
V_15 -> V_40 . V_203 . V_319 = V_319 ;
}
V_15 -> V_40 . V_203 . V_238 = F_39 ( V_15 -> V_40 . V_203 . V_319 ) ;
}
return 0 ;
}
static int F_306 ( struct V_14 * V_15 )
{
if ( V_15 -> V_40 . V_203 . V_225 )
return F_303 ( V_15 ) ;
else
return F_304 ( V_15 ) ;
}
static void F_307 ( struct V_14 * V_15 )
{
int V_108 ;
struct V_52 * V_53 ;
if ( V_15 -> V_40 . V_203 . V_225 )
return;
if ( ! F_272 ( V_15 -> V_40 . V_203 . V_238 ) )
return;
F_308 ( V_15 , V_320 ) ;
F_205 ( V_15 , V_321 ) ;
if ( V_15 -> V_40 . V_203 . V_226 == V_240 ) {
T_9 V_309 = V_15 -> V_40 . V_203 . V_238 ;
V_53 = F_38 ( V_309 ) ;
F_214 ( V_15 , V_53 ) ;
F_205 ( V_15 , V_322 ) ;
return;
}
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
T_9 V_309 = V_15 -> V_40 . V_203 . V_242 [ V_108 ] ;
if ( V_309 && F_272 ( V_309 ) ) {
V_309 &= V_47 ;
V_53 = F_38 ( V_309 ) ;
F_214 ( V_15 , V_53 ) ;
}
}
F_205 ( V_15 , V_322 ) ;
}
void F_309 ( struct V_14 * V_15 )
{
F_248 ( & V_15 -> V_112 -> V_217 ) ;
F_307 ( V_15 ) ;
F_249 ( & V_15 -> V_112 -> V_217 ) ;
}
static T_10 F_310 ( struct V_14 * V_15 , T_6 V_323 ,
T_4 V_19 , struct V_324 * V_325 )
{
if ( V_325 )
V_325 -> V_295 = 0 ;
return V_323 ;
}
static T_10 F_311 ( struct V_14 * V_15 , T_6 V_323 ,
T_4 V_19 ,
struct V_324 * V_325 )
{
if ( V_325 )
V_325 -> V_295 = 0 ;
return V_15 -> V_40 . V_326 . V_327 ( V_15 , V_323 , V_19 , V_325 ) ;
}
static bool
F_312 ( struct V_328 * V_329 , T_1 V_43 , int V_45 )
{
int V_330 = ( V_43 >> 7 ) & 1 , V_331 = V_43 & 0x3f ;
return ( V_43 & V_329 -> V_332 [ V_330 ] [ V_45 - 1 ] ) |
( ( V_329 -> V_333 & ( 1ull << V_331 ) ) != 0 ) ;
}
static bool F_313 ( struct V_334 * V_203 , T_1 V_48 , int V_45 )
{
return F_312 ( & V_203 -> V_335 , V_48 , V_45 ) ;
}
static bool F_314 ( struct V_334 * V_203 , T_1 V_4 , int V_45 )
{
return F_312 ( & V_203 -> V_336 , V_4 , V_45 ) ;
}
static bool F_315 ( struct V_14 * V_15 , T_1 V_236 , bool V_98 )
{
if ( V_98 )
return F_316 ( V_15 , V_236 ) ;
return F_317 ( V_15 , V_236 ) ;
}
static bool
F_318 ( struct V_14 * V_15 , T_1 V_236 , T_1 * V_17 )
{
struct V_235 V_158 ;
T_1 V_133 [ V_240 ] , V_4 = 0ull ;
int V_309 , V_337 ;
bool V_338 = false ;
if ( ! F_272 ( V_15 -> V_40 . V_203 . V_238 ) )
goto exit;
F_64 ( V_15 ) ;
for ( F_228 ( & V_158 , V_15 , V_236 ) ,
V_337 = V_309 = V_158 . V_45 ;
F_229 ( & V_158 ) ;
F_232 ( & V_158 , V_4 ) ) {
V_4 = F_56 ( V_158 . V_17 ) ;
V_133 [ V_337 - 1 ] = V_4 ;
V_337 -- ;
if ( ! F_24 ( V_4 ) )
break;
V_338 |= F_314 ( & V_15 -> V_40 . V_203 , V_4 ,
V_158 . V_45 ) ;
}
F_67 ( V_15 ) ;
if ( V_338 ) {
F_114 ( L_29 ,
V_151 , V_236 ) ;
while ( V_309 > V_337 ) {
F_114 ( L_30 ,
V_133 [ V_309 - 1 ] , V_309 ) ;
V_309 -- ;
}
}
exit:
* V_17 = V_4 ;
return V_338 ;
}
int F_319 ( struct V_14 * V_15 , T_1 V_236 , bool V_98 )
{
T_1 V_4 ;
bool V_338 ;
if ( F_315 ( V_15 , V_236 , V_98 ) )
return V_339 ;
V_338 = F_318 ( V_15 , V_236 , & V_4 ) ;
if ( F_4 ( V_338 ) )
return V_340 ;
if ( F_11 ( V_4 ) ) {
T_2 V_18 = F_12 ( V_4 ) ;
unsigned V_19 = F_13 ( V_4 ) ;
if ( ! F_17 ( V_15 , V_4 ) )
return V_341 ;
if ( V_98 )
V_236 = 0 ;
F_320 ( V_236 , V_18 , V_19 ) ;
F_287 ( V_15 , V_236 , V_18 , V_19 ) ;
return V_339 ;
}
return V_342 ;
}
static bool F_321 ( struct V_14 * V_15 ,
T_4 V_295 , T_2 V_18 )
{
if ( F_15 ( V_295 & V_296 ) )
return false ;
if ( ! ( V_295 & V_298 ) ||
! ( V_295 & V_299 ) )
return false ;
if ( F_255 ( V_15 , V_18 , V_116 ) )
return true ;
return false ;
}
static void F_322 ( struct V_14 * V_15 , T_6 V_236 )
{
struct V_235 V_158 ;
T_1 V_4 ;
if ( ! F_272 ( V_15 -> V_40 . V_203 . V_238 ) )
return;
F_64 ( V_15 ) ;
F_293 (vcpu, addr, iterator, spte) {
F_222 ( V_158 . V_17 ) ;
if ( ! F_24 ( V_4 ) )
break;
}
F_67 ( V_15 ) ;
}
static int F_323 ( struct V_14 * V_15 , T_6 V_189 ,
T_4 V_295 , bool V_270 )
{
T_2 V_18 = V_189 >> V_22 ;
int V_87 ;
F_251 ( L_31 , V_151 , V_189 , V_295 ) ;
if ( F_321 ( V_15 , V_295 , V_18 ) )
return 1 ;
V_87 = F_80 ( V_15 ) ;
if ( V_87 )
return V_87 ;
F_172 ( ! F_272 ( V_15 -> V_40 . V_203 . V_238 ) ) ;
return F_296 ( V_15 , V_189 & V_23 ,
V_295 , V_18 , V_270 ) ;
}
static int F_324 ( struct V_14 * V_15 , T_6 V_189 , T_2 V_18 )
{
struct V_343 V_40 ;
V_40 . V_344 = ( V_15 -> V_40 . V_345 . V_346 ++ << 12 ) | V_15 -> V_347 ;
V_40 . V_18 = V_18 ;
V_40 . V_225 = V_15 -> V_40 . V_203 . V_225 ;
V_40 . V_348 = V_15 -> V_40 . V_203 . V_315 ( V_15 ) ;
return F_325 ( V_15 , V_189 , F_278 ( V_15 , V_18 ) , & V_40 ) ;
}
bool F_326 ( struct V_14 * V_15 )
{
if ( F_15 ( ! F_327 ( V_15 ) ||
F_328 ( V_15 ) ) )
return false ;
if ( F_329 ( V_15 ) )
return false ;
return V_127 -> V_349 ( V_15 ) ;
}
static bool F_297 ( struct V_14 * V_15 , bool V_270 , T_2 V_18 ,
T_6 V_189 , T_3 * V_24 , bool V_268 , bool * V_350 )
{
struct V_102 * V_103 ;
bool V_351 ;
V_103 = F_101 ( V_15 , V_18 ) ;
V_351 = false ;
* V_24 = F_330 ( V_103 , V_18 , false , & V_351 , V_268 , V_350 ) ;
if ( ! V_351 )
return false ;
if ( ! V_270 && F_326 ( V_15 ) ) {
F_331 ( V_189 , V_18 ) ;
if ( F_332 ( V_15 , V_18 ) ) {
F_333 ( V_189 , V_18 ) ;
F_204 ( V_352 , V_15 ) ;
return true ;
} else if ( F_324 ( V_15 , V_189 , V_18 ) )
return true ;
}
* V_24 = F_330 ( V_103 , V_18 , false , NULL , V_268 , V_350 ) ;
return false ;
}
static bool
F_334 ( struct V_14 * V_15 , T_2 V_18 , int V_45 )
{
int V_353 = F_282 ( V_45 ) ;
V_18 &= ~ ( V_353 - 1 ) ;
return F_335 ( V_15 , V_18 , V_353 ) ;
}
static int F_336 ( struct V_14 * V_15 , T_6 V_354 , T_4 V_295 ,
bool V_270 )
{
T_3 V_24 ;
int V_87 ;
int V_45 ;
bool V_124 ;
T_2 V_18 = V_354 >> V_22 ;
unsigned long V_306 ;
int V_268 = V_295 & V_299 ;
bool V_269 ;
F_172 ( ! F_272 ( V_15 -> V_40 . V_203 . V_238 ) ) ;
if ( F_321 ( V_15 , V_295 , V_18 ) )
return 1 ;
V_87 = F_80 ( V_15 ) ;
if ( V_87 )
return V_87 ;
V_124 = ! F_334 ( V_15 , V_18 ,
V_109 ) ;
V_45 = F_107 ( V_15 , V_18 , & V_124 ) ;
if ( F_19 ( ! V_124 ) ) {
if ( V_45 > V_109 &&
! F_334 ( V_15 , V_18 , V_45 ) )
V_45 = V_109 ;
V_18 &= ~ ( F_282 ( V_45 ) - 1 ) ;
}
if ( F_292 ( V_15 , V_354 , V_45 , V_295 ) )
return 0 ;
V_306 = V_15 -> V_112 -> V_307 ;
F_41 () ;
if ( F_297 ( V_15 , V_270 , V_18 , V_354 , & V_24 , V_268 , & V_269 ) )
return 0 ;
if ( F_285 ( V_15 , 0 , V_18 , V_24 , V_272 , & V_87 ) )
return V_87 ;
F_248 ( & V_15 -> V_112 -> V_217 ) ;
if ( F_298 ( V_15 -> V_112 , V_306 ) )
goto V_308;
F_299 ( V_15 ) ;
if ( F_19 ( ! V_124 ) )
F_279 ( V_15 , & V_18 , & V_24 , & V_45 ) ;
V_87 = F_271 ( V_15 , V_268 , V_269 , V_45 , V_18 , V_24 , V_270 ) ;
F_249 ( & V_15 -> V_112 -> V_217 ) ;
return V_87 ;
V_308:
F_249 ( & V_15 -> V_112 -> V_217 ) ;
F_263 ( V_24 ) ;
return 0 ;
}
static void F_337 ( struct V_14 * V_15 ,
struct V_334 * V_355 )
{
V_355 -> V_356 = F_323 ;
V_355 -> V_357 = F_310 ;
V_355 -> V_204 = F_187 ;
V_355 -> V_358 = F_188 ;
V_355 -> V_359 = F_189 ;
V_355 -> V_226 = 0 ;
V_355 -> V_239 = V_241 ;
V_355 -> V_238 = V_310 ;
V_355 -> V_225 = true ;
V_355 -> V_360 = false ;
}
void F_338 ( struct V_14 * V_15 )
{
F_300 ( V_15 ) ;
}
static unsigned long V_315 ( struct V_14 * V_15 )
{
return F_339 ( V_15 ) ;
}
static void F_340 ( struct V_14 * V_15 ,
struct V_324 * V_361 )
{
V_15 -> V_40 . V_203 . F_340 ( V_15 , V_361 ) ;
}
static bool F_341 ( struct V_14 * V_15 , T_1 * V_17 , T_2 V_18 ,
unsigned V_19 , int * V_362 )
{
if ( F_15 ( F_11 ( * V_17 ) ) ) {
if ( V_18 != F_12 ( * V_17 ) ) {
F_55 ( V_17 ) ;
return true ;
}
( * V_362 ) ++ ;
F_8 ( V_15 , V_17 , V_18 , V_19 ) ;
return true ;
}
return false ;
}
static inline bool F_342 ( struct V_334 * V_203 ,
unsigned V_45 , unsigned V_48 )
{
V_48 |= V_45 - V_46 - 1 ;
V_48 &= V_45 - V_203 -> V_363 ;
return V_48 & V_44 ;
}
static void
F_343 ( struct V_14 * V_15 ,
struct V_328 * V_329 ,
int V_364 , int V_45 , bool V_360 , bool V_365 ,
bool V_366 , bool V_367 )
{
T_1 V_368 = 0 ;
T_1 V_369 = 0 ;
T_1 V_370 = 0 ;
V_329 -> V_333 = 0 ;
if ( ! V_360 )
V_368 = F_344 ( 63 , 63 ) ;
if ( ! V_365 )
V_369 = F_344 ( 7 , 7 ) ;
if ( V_367 )
V_370 = F_344 ( 8 , 8 ) ;
switch ( V_45 ) {
case V_227 :
V_329 -> V_332 [ 0 ] [ 1 ] = 0 ;
V_329 -> V_332 [ 0 ] [ 0 ] = 0 ;
V_329 -> V_332 [ 1 ] [ 0 ] =
V_329 -> V_332 [ 0 ] [ 0 ] ;
if ( ! V_366 ) {
V_329 -> V_332 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_22 () )
V_329 -> V_332 [ 1 ] [ 1 ] = F_344 ( 17 , 21 ) ;
else
V_329 -> V_332 [ 1 ] [ 1 ] = F_344 ( 13 , 21 ) ;
break;
case V_241 :
V_329 -> V_332 [ 0 ] [ 2 ] =
F_344 ( V_364 , 63 ) |
F_344 ( 5 , 8 ) | F_344 ( 1 , 2 ) ;
V_329 -> V_332 [ 0 ] [ 1 ] = V_368 |
F_344 ( V_364 , 62 ) ;
V_329 -> V_332 [ 0 ] [ 0 ] = V_368 |
F_344 ( V_364 , 62 ) ;
V_329 -> V_332 [ 1 ] [ 1 ] = V_368 |
F_344 ( V_364 , 62 ) |
F_344 ( 13 , 20 ) ;
V_329 -> V_332 [ 1 ] [ 0 ] =
V_329 -> V_332 [ 0 ] [ 0 ] ;
break;
case V_240 :
V_329 -> V_332 [ 0 ] [ 3 ] = V_368 |
V_370 | F_344 ( 7 , 7 ) |
F_344 ( V_364 , 51 ) ;
V_329 -> V_332 [ 0 ] [ 2 ] = V_368 |
V_370 | V_369 |
F_344 ( V_364 , 51 ) ;
V_329 -> V_332 [ 0 ] [ 1 ] = V_368 |
F_344 ( V_364 , 51 ) ;
V_329 -> V_332 [ 0 ] [ 0 ] = V_368 |
F_344 ( V_364 , 51 ) ;
V_329 -> V_332 [ 1 ] [ 3 ] =
V_329 -> V_332 [ 0 ] [ 3 ] ;
V_329 -> V_332 [ 1 ] [ 2 ] = V_368 |
V_369 | F_344 ( V_364 , 51 ) |
F_344 ( 13 , 29 ) ;
V_329 -> V_332 [ 1 ] [ 1 ] = V_368 |
F_344 ( V_364 , 51 ) |
F_344 ( 13 , 20 ) ;
V_329 -> V_332 [ 1 ] [ 0 ] =
V_329 -> V_332 [ 0 ] [ 0 ] ;
break;
}
}
static void F_345 ( struct V_14 * V_15 ,
struct V_334 * V_355 )
{
F_343 ( V_15 , & V_355 -> V_335 ,
F_346 ( V_15 ) , V_355 -> V_226 ,
V_355 -> V_360 , F_347 ( V_15 ) ,
F_348 ( V_15 ) , F_349 ( V_15 ) ) ;
}
static void
F_350 ( struct V_328 * V_329 ,
int V_364 , bool V_371 )
{
T_1 V_333 ;
V_329 -> V_332 [ 0 ] [ 3 ] =
F_344 ( V_364 , 51 ) | F_344 ( 3 , 7 ) ;
V_329 -> V_332 [ 0 ] [ 2 ] =
F_344 ( V_364 , 51 ) | F_344 ( 3 , 6 ) ;
V_329 -> V_332 [ 0 ] [ 1 ] =
F_344 ( V_364 , 51 ) | F_344 ( 3 , 6 ) ;
V_329 -> V_332 [ 0 ] [ 0 ] = F_344 ( V_364 , 51 ) ;
V_329 -> V_332 [ 1 ] [ 3 ] = V_329 -> V_332 [ 0 ] [ 3 ] ;
V_329 -> V_332 [ 1 ] [ 2 ] =
F_344 ( V_364 , 51 ) | F_344 ( 12 , 29 ) ;
V_329 -> V_332 [ 1 ] [ 1 ] =
F_344 ( V_364 , 51 ) | F_344 ( 12 , 20 ) ;
V_329 -> V_332 [ 1 ] [ 0 ] = V_329 -> V_332 [ 0 ] [ 0 ] ;
V_333 = 0xFFull << ( 2 * 8 ) ;
V_333 |= 0xFFull << ( 3 * 8 ) ;
V_333 |= 0xFFull << ( 7 * 8 ) ;
V_333 |= F_351 ( 1ull << 2 ) ;
V_333 |= F_351 ( 1ull << 6 ) ;
if ( ! V_371 ) {
V_333 |= F_351 ( 1ull << 4 ) ;
}
V_329 -> V_333 = V_333 ;
}
static void F_352 ( struct V_14 * V_15 ,
struct V_334 * V_355 , bool V_371 )
{
F_350 ( & V_355 -> V_335 ,
F_346 ( V_15 ) , V_371 ) ;
}
void
F_353 ( struct V_14 * V_15 , struct V_334 * V_355 )
{
bool V_372 = V_355 -> V_360 || V_355 -> V_224 . V_373 ;
F_343 ( V_15 , & V_355 -> V_336 ,
V_374 . V_375 ,
V_355 -> V_239 , V_372 ,
F_347 ( V_15 ) , F_348 ( V_15 ) ,
true ) ;
}
static inline bool F_354 ( void )
{
F_60 ( ! V_258 ) ;
return V_38 == 0 ;
}
static void
F_355 ( struct V_14 * V_15 ,
struct V_334 * V_355 )
{
if ( F_354 () )
F_343 ( V_15 , & V_355 -> V_336 ,
V_374 . V_375 ,
V_355 -> V_239 , false ,
F_356 ( V_376 ) ,
true , true ) ;
else
F_350 ( & V_355 -> V_336 ,
V_374 . V_375 ,
false ) ;
}
static void
F_357 ( struct V_14 * V_15 ,
struct V_334 * V_355 , bool V_371 )
{
F_350 ( & V_355 -> V_336 ,
V_374 . V_375 , V_371 ) ;
}
static void F_358 ( struct V_14 * V_15 ,
struct V_334 * V_203 , bool V_377 )
{
unsigned V_378 , V_379 , V_380 ;
T_11 V_381 ;
bool V_361 , V_382 , V_383 , V_384 , V_385 , V_386 , V_387 , V_388 , V_389 , V_390 , V_391 = 0 ;
V_390 = F_359 ( V_15 , V_392 ) ;
V_389 = F_359 ( V_15 , V_393 ) ;
for ( V_379 = 0 ; V_379 < F_71 ( V_203 -> V_394 ) ; ++ V_379 ) {
V_380 = V_379 << 1 ;
V_381 = 0 ;
V_385 = V_380 & V_299 ;
V_386 = V_380 & V_395 ;
V_387 = V_380 & V_297 ;
V_388 = ! ( V_380 & V_296 ) ;
for ( V_378 = 0 ; V_378 < 8 ; ++ V_378 ) {
V_382 = V_378 & V_257 ;
V_383 = V_378 & V_20 ;
V_384 = V_378 & V_21 ;
if ( ! V_377 ) {
V_382 |= ! V_203 -> V_360 ;
V_383 |= ! F_360 ( V_15 ) && ! V_386 ;
V_382 &= ! ( V_390 && V_384 && ! V_386 ) ;
V_391 = V_389 && V_384 && ! V_386 && ! V_387 ;
}
V_361 = ( V_387 && ! V_382 ) || ( V_386 && ! V_384 ) || ( V_385 && ! V_383 ) ||
( V_388 && V_391 ) ;
V_381 |= V_361 << V_378 ;
}
V_203 -> V_394 [ V_379 ] = V_381 ;
}
}
static void F_361 ( struct V_14 * V_15 , struct V_334 * V_203 ,
bool V_377 )
{
unsigned V_378 ;
bool V_396 ;
if ( V_377 ) {
V_203 -> V_397 = 0 ;
return;
}
if ( ! F_359 ( V_15 , V_398 ) || ! F_362 ( V_15 ) ) {
V_203 -> V_397 = 0 ;
return;
}
V_396 = F_360 ( V_15 ) ;
for ( V_378 = 0 ; V_378 < F_71 ( V_203 -> V_394 ) ; ++ V_378 ) {
unsigned V_380 , V_399 ;
bool V_400 , V_401 , V_387 , V_386 , V_385 , V_402 ;
V_380 = V_378 << 1 ;
V_387 = V_380 & V_297 ;
V_386 = V_380 & V_395 ;
V_385 = V_380 & V_299 ;
V_402 = V_380 & V_296 ;
V_400 = ( ! V_387 && V_402 ) ;
V_401 = V_400 && V_385 && ( V_386 || V_396 ) ;
V_399 = ! ! V_400 ;
V_399 |= ( ! ! V_401 ) << 1 ;
V_203 -> V_397 |= ( V_399 & 3 ) << V_380 ;
}
}
static void F_363 ( struct V_14 * V_15 , struct V_334 * V_203 )
{
unsigned V_226 = V_203 -> V_226 ;
V_203 -> V_363 = V_226 ;
if ( V_226 == V_227 && F_348 ( V_15 ) )
V_203 -> V_363 ++ ;
}
static void F_364 ( struct V_14 * V_15 ,
struct V_334 * V_355 ,
int V_45 )
{
V_355 -> V_360 = F_23 ( V_15 ) ;
V_355 -> V_226 = V_45 ;
F_345 ( V_15 , V_355 ) ;
F_358 ( V_15 , V_355 , false ) ;
F_361 ( V_15 , V_355 , false ) ;
F_363 ( V_15 , V_355 ) ;
F_172 ( ! F_199 ( V_15 ) ) ;
V_355 -> V_356 = V_403 ;
V_355 -> V_357 = V_404 ;
V_355 -> V_204 = V_405 ;
V_355 -> V_358 = V_406 ;
V_355 -> V_359 = V_407 ;
V_355 -> V_239 = V_45 ;
V_355 -> V_238 = V_310 ;
V_355 -> V_225 = false ;
}
static void F_365 ( struct V_14 * V_15 ,
struct V_334 * V_355 )
{
F_364 ( V_15 , V_355 , V_240 ) ;
}
static void F_366 ( struct V_14 * V_15 ,
struct V_334 * V_355 )
{
V_355 -> V_360 = false ;
V_355 -> V_226 = V_227 ;
F_345 ( V_15 , V_355 ) ;
F_358 ( V_15 , V_355 , false ) ;
F_361 ( V_15 , V_355 , false ) ;
F_363 ( V_15 , V_355 ) ;
V_355 -> V_356 = V_408 ;
V_355 -> V_357 = V_409 ;
V_355 -> V_204 = V_410 ;
V_355 -> V_358 = V_411 ;
V_355 -> V_359 = V_412 ;
V_355 -> V_239 = V_241 ;
V_355 -> V_238 = V_310 ;
V_355 -> V_225 = false ;
}
static void F_367 ( struct V_14 * V_15 ,
struct V_334 * V_355 )
{
F_364 ( V_15 , V_355 , V_241 ) ;
}
static void F_368 ( struct V_14 * V_15 )
{
struct V_334 * V_355 = & V_15 -> V_40 . V_203 ;
V_355 -> V_224 . V_230 = 0 ;
V_355 -> V_224 . V_413 = F_369 ( V_15 ) ;
V_355 -> V_356 = F_336 ;
V_355 -> V_204 = F_187 ;
V_355 -> V_358 = F_188 ;
V_355 -> V_359 = F_189 ;
V_355 -> V_239 = V_127 -> V_414 () ;
V_355 -> V_238 = V_310 ;
V_355 -> V_225 = true ;
V_355 -> V_415 = V_127 -> V_416 ;
V_355 -> V_315 = V_315 ;
V_355 -> V_318 = V_417 ;
V_355 -> F_340 = V_418 ;
if ( ! F_370 ( V_15 ) ) {
V_355 -> V_360 = false ;
V_355 -> V_357 = F_310 ;
V_355 -> V_226 = 0 ;
} else if ( F_362 ( V_15 ) ) {
V_355 -> V_360 = F_23 ( V_15 ) ;
V_355 -> V_226 = V_240 ;
F_345 ( V_15 , V_355 ) ;
V_355 -> V_357 = V_404 ;
} else if ( F_199 ( V_15 ) ) {
V_355 -> V_360 = F_23 ( V_15 ) ;
V_355 -> V_226 = V_241 ;
F_345 ( V_15 , V_355 ) ;
V_355 -> V_357 = V_404 ;
} else {
V_355 -> V_360 = false ;
V_355 -> V_226 = V_227 ;
F_345 ( V_15 , V_355 ) ;
V_355 -> V_357 = V_409 ;
}
F_358 ( V_15 , V_355 , false ) ;
F_361 ( V_15 , V_355 , false ) ;
F_363 ( V_15 , V_355 ) ;
F_355 ( V_15 , V_355 ) ;
}
void F_371 ( struct V_14 * V_15 )
{
bool V_419 = F_359 ( V_15 , V_392 ) ;
bool V_391 = F_359 ( V_15 , V_393 ) ;
struct V_334 * V_355 = & V_15 -> V_40 . V_203 ;
F_172 ( F_272 ( V_355 -> V_238 ) ) ;
if ( ! F_370 ( V_15 ) )
F_337 ( V_15 , V_355 ) ;
else if ( F_362 ( V_15 ) )
F_365 ( V_15 , V_355 ) ;
else if ( F_199 ( V_15 ) )
F_367 ( V_15 , V_355 ) ;
else
F_366 ( V_15 , V_355 ) ;
V_355 -> V_224 . V_420 = F_23 ( V_15 ) ;
V_355 -> V_224 . V_202 = ! ! F_199 ( V_15 ) ;
V_355 -> V_224 . V_421 = F_360 ( V_15 ) ;
V_355 -> V_224 . V_373
= V_419 && ! F_360 ( V_15 ) ;
V_355 -> V_224 . V_422
= V_391 && ! F_360 ( V_15 ) ;
V_355 -> V_224 . V_413 = F_369 ( V_15 ) ;
F_353 ( V_15 , V_355 ) ;
}
void F_372 ( struct V_14 * V_15 , bool V_371 ,
bool V_423 )
{
struct V_334 * V_355 = & V_15 -> V_40 . V_203 ;
F_172 ( F_272 ( V_355 -> V_238 ) ) ;
V_355 -> V_239 = V_127 -> V_414 () ;
V_355 -> V_360 = true ;
V_355 -> V_424 = V_423 ;
V_355 -> V_356 = V_425 ;
V_355 -> V_357 = V_426 ;
V_355 -> V_204 = V_427 ;
V_355 -> V_358 = V_428 ;
V_355 -> V_359 = V_429 ;
V_355 -> V_226 = V_355 -> V_239 ;
V_355 -> V_238 = V_310 ;
V_355 -> V_225 = false ;
F_358 ( V_15 , V_355 , true ) ;
F_361 ( V_15 , V_355 , true ) ;
F_352 ( V_15 , V_355 , V_371 ) ;
F_357 ( V_15 , V_355 , V_371 ) ;
}
static void F_373 ( struct V_14 * V_15 )
{
struct V_334 * V_355 = & V_15 -> V_40 . V_203 ;
F_371 ( V_15 ) ;
V_355 -> V_415 = V_127 -> V_415 ;
V_355 -> V_315 = V_315 ;
V_355 -> V_318 = V_417 ;
V_355 -> F_340 = V_418 ;
}
static void F_374 ( struct V_14 * V_15 )
{
struct V_334 * V_430 = & V_15 -> V_40 . V_326 ;
V_430 -> V_315 = V_315 ;
V_430 -> V_318 = V_417 ;
V_430 -> F_340 = V_418 ;
if ( ! F_370 ( V_15 ) ) {
V_430 -> V_360 = false ;
V_430 -> V_226 = 0 ;
V_430 -> V_357 = F_311 ;
} else if ( F_362 ( V_15 ) ) {
V_430 -> V_360 = F_23 ( V_15 ) ;
V_430 -> V_226 = V_240 ;
F_345 ( V_15 , V_430 ) ;
V_430 -> V_357 = V_431 ;
} else if ( F_199 ( V_15 ) ) {
V_430 -> V_360 = F_23 ( V_15 ) ;
V_430 -> V_226 = V_241 ;
F_345 ( V_15 , V_430 ) ;
V_430 -> V_357 = V_431 ;
} else {
V_430 -> V_360 = false ;
V_430 -> V_226 = V_227 ;
F_345 ( V_15 , V_430 ) ;
V_430 -> V_357 = V_432 ;
}
F_358 ( V_15 , V_430 , false ) ;
F_361 ( V_15 , V_430 , false ) ;
F_363 ( V_15 , V_430 ) ;
}
static void F_375 ( struct V_14 * V_15 )
{
if ( F_376 ( V_15 ) )
F_374 ( V_15 ) ;
else if ( V_258 )
F_368 ( V_15 ) ;
else
F_373 ( V_15 ) ;
}
void F_377 ( struct V_14 * V_15 )
{
F_378 ( V_15 ) ;
F_375 ( V_15 ) ;
}
int F_379 ( struct V_14 * V_15 )
{
int V_87 ;
V_87 = F_80 ( V_15 ) ;
if ( V_87 )
goto V_91;
V_87 = F_306 ( V_15 ) ;
F_309 ( V_15 ) ;
if ( V_87 )
goto V_91;
V_15 -> V_40 . V_203 . V_415 ( V_15 , V_15 -> V_40 . V_203 . V_238 ) ;
V_91:
return V_87 ;
}
void F_378 ( struct V_14 * V_15 )
{
F_300 ( V_15 ) ;
F_4 ( F_272 ( V_15 -> V_40 . V_203 . V_238 ) ) ;
}
static void F_380 ( struct V_14 * V_15 ,
struct V_52 * V_53 , T_1 * V_4 ,
const void * V_433 )
{
if ( V_53 -> V_97 . V_45 != V_46 ) {
++ V_15 -> V_112 -> V_144 . V_434 ;
return;
}
++ V_15 -> V_112 -> V_144 . V_435 ;
V_15 -> V_40 . V_203 . V_359 ( V_15 , V_53 , V_4 , V_433 ) ;
}
static bool F_381 ( T_1 V_436 , T_1 V_433 )
{
if ( ! F_24 ( V_436 ) )
return false ;
if ( ! F_24 ( V_433 ) )
return true ;
if ( ( V_436 ^ V_433 ) & V_47 )
return true ;
V_436 ^= V_37 ;
V_433 ^= V_37 ;
return ( V_436 & ~ V_433 & V_437 ) != 0 ;
}
static T_1 F_382 ( struct V_14 * V_15 , T_10 * V_354 ,
const T_11 * V_433 , int * V_438 )
{
T_1 V_439 ;
int V_87 ;
if ( F_199 ( V_15 ) && * V_438 == 4 ) {
* V_354 &= ~ ( T_10 ) 7 ;
* V_438 = 8 ;
V_87 = F_383 ( V_15 , * V_354 , & V_439 , 8 ) ;
if ( V_87 )
V_439 = 0 ;
V_433 = ( const T_11 * ) & V_439 ;
}
switch ( * V_438 ) {
case 4 :
V_439 = * ( const T_4 * ) V_433 ;
break;
case 8 :
V_439 = * ( const T_1 * ) V_433 ;
break;
default:
V_439 = 0 ;
break;
}
return V_439 ;
}
static bool F_384 ( struct V_52 * V_53 )
{
if ( V_53 -> V_97 . V_45 == V_46 )
return false ;
F_385 ( & V_53 -> V_218 ) ;
return F_386 ( & V_53 -> V_218 ) >= 3 ;
}
static bool F_387 ( struct V_52 * V_53 , T_10 V_354 ,
int V_438 )
{
unsigned V_440 , V_441 , V_442 ;
F_251 ( L_32 ,
V_354 , V_438 , V_53 -> V_97 . V_230 ) ;
V_440 = F_388 ( V_354 ) ;
V_441 = V_53 -> V_97 . V_202 ? 8 : 4 ;
if ( ! ( V_440 & ( V_441 - 1 ) ) && V_438 == 1 )
return false ;
V_442 = ( V_440 ^ ( V_440 + V_438 - 1 ) ) & ~ ( V_441 - 1 ) ;
V_442 |= V_438 < 4 ;
return V_442 ;
}
static T_1 * F_389 ( struct V_52 * V_53 , T_10 V_354 , int * V_443 )
{
unsigned V_444 , V_221 ;
T_1 * V_4 ;
int V_45 ;
V_444 = F_388 ( V_354 ) ;
V_45 = V_53 -> V_97 . V_45 ;
* V_443 = 1 ;
if ( ! V_53 -> V_97 . V_202 ) {
V_444 <<= 1 ;
if ( V_45 == V_227 ) {
V_444 &= ~ 7 ;
V_444 <<= 1 ;
* V_443 = 2 ;
}
V_221 = V_444 >> V_22 ;
V_444 &= ~ V_23 ;
if ( V_221 != V_53 -> V_97 . V_221 )
return NULL ;
}
V_4 = & V_53 -> V_140 [ V_444 / sizeof( * V_4 ) ] ;
return V_4 ;
}
static void F_390 ( struct V_14 * V_15 , T_10 V_354 ,
const T_11 * V_433 , int V_438 ,
struct V_445 * V_446 )
{
T_2 V_18 = V_354 >> V_22 ;
struct V_52 * V_53 ;
F_215 ( V_201 ) ;
T_1 V_447 , V_439 , * V_4 ;
int V_448 ;
bool V_205 , V_206 ;
union V_220 V_8 = { } ;
V_8 . V_421 = 1 ;
V_8 . V_202 = 1 ;
V_8 . V_420 = 1 ;
V_8 . V_373 = 1 ;
V_8 . V_422 = 1 ;
V_8 . V_413 = 1 ;
if ( ! F_36 ( V_15 -> V_112 -> V_40 . V_115 ) )
return;
V_205 = V_206 = false ;
F_251 ( L_33 , V_151 , V_354 , V_438 ) ;
V_439 = F_382 ( V_15 , & V_354 , V_433 , & V_438 ) ;
F_80 ( V_15 ) ;
F_248 ( & V_15 -> V_112 -> V_217 ) ;
++ V_15 -> V_112 -> V_144 . V_449 ;
F_205 ( V_15 , V_450 ) ;
F_210 (vcpu->kvm, sp, gfn) {
if ( F_387 ( V_53 , V_354 , V_438 ) ||
F_384 ( V_53 ) ) {
F_200 ( V_15 -> V_112 , V_53 , & V_201 ) ;
++ V_15 -> V_112 -> V_144 . V_451 ;
continue;
}
V_4 = F_389 ( V_53 , V_354 , & V_448 ) ;
if ( ! V_4 )
continue;
V_206 = true ;
while ( V_448 -- ) {
V_447 = * V_4 ;
F_237 ( V_15 -> V_112 , V_53 , V_4 ) ;
if ( V_439 &&
! ( ( V_53 -> V_97 . V_230 ^ V_15 -> V_40 . V_203 . V_224 . V_230 )
& V_8 . V_230 ) && F_117 ( V_15 ) )
F_380 ( V_15 , V_53 , V_4 , & V_439 ) ;
if ( F_381 ( V_447 , * V_4 ) )
V_205 = true ;
++ V_4 ;
}
}
F_201 ( V_15 , & V_201 , V_205 , V_206 ) ;
F_205 ( V_15 , V_452 ) ;
F_249 ( & V_15 -> V_112 -> V_217 ) ;
}
int F_391 ( struct V_14 * V_15 , T_6 V_189 )
{
T_10 V_354 ;
int V_87 ;
if ( V_15 -> V_40 . V_203 . V_225 )
return 0 ;
V_354 = F_392 ( V_15 , V_189 , NULL ) ;
V_87 = F_250 ( V_15 -> V_112 , V_354 >> V_22 ) ;
return V_87 ;
}
static void F_299 ( struct V_14 * V_15 )
{
F_215 ( V_201 ) ;
if ( F_19 ( F_393 ( V_15 -> V_112 ) >= V_453 ) )
return;
while ( F_393 ( V_15 -> V_112 ) < V_454 ) {
if ( ! F_245 ( V_15 -> V_112 , & V_201 ) )
break;
++ V_15 -> V_112 -> V_144 . V_455 ;
}
F_203 ( V_15 -> V_112 , & V_201 ) ;
}
int F_394 ( struct V_14 * V_15 , T_6 V_456 , T_1 V_295 ,
void * V_457 , int V_458 )
{
int V_87 , V_459 = V_460 ;
enum V_461 V_462 ;
bool V_98 = V_15 -> V_40 . V_203 . V_225 || F_376 ( V_15 ) ;
if ( F_15 ( V_295 & V_296 ) ) {
V_87 = F_319 ( V_15 , V_456 , V_98 ) ;
if ( V_87 == V_339 ) {
V_459 = 0 ;
goto V_265;
}
if ( V_87 == V_342 )
return 1 ;
if ( V_87 < 0 )
return V_87 ;
}
V_87 = V_15 -> V_40 . V_203 . V_356 ( V_15 , V_456 , F_395 ( V_295 ) ,
false ) ;
if ( V_87 < 0 )
return V_87 ;
if ( ! V_87 )
return 1 ;
if ( V_295 == V_463 ) {
F_250 ( V_15 -> V_112 , F_396 ( V_456 ) ) ;
return 1 ;
}
if ( F_315 ( V_15 , V_456 , V_98 ) )
V_459 = 0 ;
V_265:
V_462 = F_397 ( V_15 , V_456 , V_459 , V_457 , V_458 ) ;
switch ( V_462 ) {
case V_464 :
return 1 ;
case V_465 :
++ V_15 -> V_144 . V_466 ;
case V_467 :
return 0 ;
default:
F_113 () ;
}
}
void F_398 ( struct V_14 * V_15 , T_6 V_189 )
{
V_15 -> V_40 . V_203 . V_358 ( V_15 , V_189 ) ;
F_204 ( V_207 , V_15 ) ;
++ V_15 -> V_144 . V_358 ;
}
void F_399 ( void )
{
V_258 = true ;
}
void F_400 ( void )
{
V_258 = false ;
}
static void F_401 ( struct V_14 * V_15 )
{
F_79 ( ( unsigned long ) V_15 -> V_40 . V_203 . V_242 ) ;
if ( V_15 -> V_40 . V_203 . V_319 != NULL )
F_79 ( ( unsigned long ) V_15 -> V_40 . V_203 . V_319 ) ;
}
static int F_402 ( struct V_14 * V_15 )
{
struct V_86 * V_86 ;
int V_108 ;
V_86 = F_403 ( V_83 | V_468 ) ;
if ( ! V_86 )
return - V_84 ;
V_15 -> V_40 . V_203 . V_242 = F_404 ( V_86 ) ;
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 )
V_15 -> V_40 . V_203 . V_242 [ V_108 ] = V_310 ;
return 0 ;
}
int F_405 ( struct V_14 * V_15 )
{
V_15 -> V_40 . V_469 = & V_15 -> V_40 . V_203 ;
V_15 -> V_40 . V_203 . V_238 = V_310 ;
V_15 -> V_40 . V_203 . V_327 = V_327 ;
V_15 -> V_40 . V_326 . V_327 = V_470 ;
return F_402 ( V_15 ) ;
}
void F_406 ( struct V_14 * V_15 )
{
F_172 ( F_272 ( V_15 -> V_40 . V_203 . V_238 ) ) ;
F_375 ( V_15 ) ;
}
static void F_407 ( struct V_112 * V_112 ,
struct V_102 * V_103 ,
struct V_445 * V_446 )
{
F_408 ( V_112 ) ;
}
void F_409 ( struct V_112 * V_112 )
{
struct V_445 * V_446 = & V_112 -> V_40 . V_471 ;
V_446 -> V_472 = F_390 ;
V_446 -> V_473 = F_407 ;
F_410 ( V_112 , V_446 ) ;
}
void F_411 ( struct V_112 * V_112 )
{
struct V_445 * V_446 = & V_112 -> V_40 . V_471 ;
F_412 ( V_112 , V_446 ) ;
}
static bool
F_413 ( struct V_112 * V_112 , struct V_102 * V_166 ,
T_12 V_474 , int V_162 , int V_163 ,
T_2 V_159 , T_2 V_161 , bool V_475 )
{
struct V_157 V_158 ;
bool V_68 = false ;
F_157 (memslot, start_level, end_level, start_gfn,
end_gfn, &iterator) {
if ( V_158 . V_139 )
V_68 |= V_474 ( V_112 , V_158 . V_139 ) ;
if ( F_217 () || F_218 ( & V_112 -> V_217 ) ) {
if ( V_68 && V_475 ) {
F_125 ( V_112 ) ;
V_68 = false ;
}
F_219 ( & V_112 -> V_217 ) ;
}
}
if ( V_68 && V_475 ) {
F_125 ( V_112 ) ;
V_68 = false ;
}
return V_68 ;
}
static bool
F_414 ( struct V_112 * V_112 , struct V_102 * V_166 ,
T_12 V_474 , int V_162 , int V_163 ,
bool V_475 )
{
return F_413 ( V_112 , V_166 , V_474 , V_162 ,
V_163 , V_166 -> V_105 ,
V_166 -> V_105 + V_166 -> V_173 - 1 ,
V_475 ) ;
}
static bool
F_415 ( struct V_112 * V_112 , struct V_102 * V_166 ,
T_12 V_474 , bool V_475 )
{
return F_414 ( V_112 , V_166 , V_474 , V_46 ,
V_110 , V_475 ) ;
}
static bool
F_416 ( struct V_112 * V_112 , struct V_102 * V_166 ,
T_12 V_474 , bool V_475 )
{
return F_414 ( V_112 , V_166 , V_474 , V_46 + 1 ,
V_110 , V_475 ) ;
}
static bool
F_417 ( struct V_112 * V_112 , struct V_102 * V_166 ,
T_12 V_474 , bool V_475 )
{
return F_414 ( V_112 , V_166 , V_474 , V_46 ,
V_46 , V_475 ) ;
}
void F_418 ( struct V_112 * V_112 , T_2 V_170 , T_2 V_171 )
{
struct V_113 * V_114 ;
struct V_102 * V_166 ;
int V_108 ;
F_248 ( & V_112 -> V_217 ) ;
for ( V_108 = 0 ; V_108 < V_167 ; V_108 ++ ) {
V_114 = F_153 ( V_112 , V_108 ) ;
F_154 (memslot, slots) {
T_2 V_164 , V_165 ;
V_164 = F_155 ( V_170 , V_166 -> V_105 ) ;
V_165 = V_79 ( V_171 , V_166 -> V_105 + V_166 -> V_173 ) ;
if ( V_164 >= V_165 )
continue;
F_413 ( V_112 , V_166 , F_140 ,
V_46 , V_110 ,
V_164 , V_165 - 1 , true ) ;
}
}
F_249 ( & V_112 -> V_217 ) ;
}
static bool F_419 ( struct V_112 * V_112 ,
struct V_129 * V_130 )
{
return F_127 ( V_112 , V_130 , false ) ;
}
void F_420 ( struct V_112 * V_112 ,
struct V_102 * V_166 )
{
bool V_68 ;
F_248 ( & V_112 -> V_217 ) ;
V_68 = F_415 ( V_112 , V_166 , F_419 ,
false ) ;
F_249 ( & V_112 -> V_217 ) ;
F_421 ( & V_112 -> V_476 ) ;
if ( V_68 )
F_125 ( V_112 ) ;
}
static bool F_422 ( struct V_112 * V_112 ,
struct V_129 * V_130 )
{
T_1 * V_17 ;
struct V_141 V_142 ;
int V_477 = 0 ;
T_3 V_24 ;
struct V_52 * V_53 ;
V_156:
F_128 (rmap_head, &iter, sptep) {
V_53 = F_38 ( F_39 ( V_17 ) ) ;
V_24 = F_28 ( * V_17 ) ;
if ( V_53 -> V_97 . V_98 &&
! F_52 ( V_24 ) &&
F_281 ( F_54 ( V_24 ) ) ) {
F_122 ( V_112 , V_17 ) ;
V_477 = 1 ;
goto V_156;
}
}
return V_477 ;
}
void F_423 ( struct V_112 * V_112 ,
const struct V_102 * V_166 )
{
F_248 ( & V_112 -> V_217 ) ;
F_417 ( V_112 , (struct V_102 * ) V_166 ,
F_422 , true ) ;
F_249 ( & V_112 -> V_217 ) ;
}
void F_424 ( struct V_112 * V_112 ,
struct V_102 * V_166 )
{
bool V_68 ;
F_248 ( & V_112 -> V_217 ) ;
V_68 = F_417 ( V_112 , V_166 , F_130 , false ) ;
F_249 ( & V_112 -> V_217 ) ;
F_421 ( & V_112 -> V_476 ) ;
if ( V_68 )
F_125 ( V_112 ) ;
}
void F_425 ( struct V_112 * V_112 ,
struct V_102 * V_166 )
{
bool V_68 ;
F_248 ( & V_112 -> V_217 ) ;
V_68 = F_416 ( V_112 , V_166 , F_419 ,
false ) ;
F_249 ( & V_112 -> V_217 ) ;
F_421 ( & V_112 -> V_476 ) ;
if ( V_68 )
F_125 ( V_112 ) ;
}
void F_426 ( struct V_112 * V_112 ,
struct V_102 * V_166 )
{
bool V_68 ;
F_248 ( & V_112 -> V_217 ) ;
V_68 = F_415 ( V_112 , V_166 , F_132 , false ) ;
F_249 ( & V_112 -> V_217 ) ;
F_421 ( & V_112 -> V_476 ) ;
if ( V_68 )
F_125 ( V_112 ) ;
}
static void F_427 ( struct V_112 * V_112 )
{
struct V_52 * V_53 , * V_446 ;
int V_478 = 0 ;
V_156:
F_428 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_118 ;
if ( ! F_207 ( V_112 , V_53 ) )
break;
if ( V_53 -> V_97 . V_248 )
continue;
if ( V_478 >= V_479 &&
F_219 ( & V_112 -> V_217 ) ) {
V_478 = 0 ;
goto V_156;
}
V_118 = F_200 ( V_112 , V_53 ,
& V_112 -> V_40 . V_480 ) ;
V_478 += V_118 ;
if ( V_118 )
goto V_156;
}
F_203 ( V_112 , & V_112 -> V_40 . V_480 ) ;
}
void F_408 ( struct V_112 * V_112 )
{
F_248 ( & V_112 -> V_217 ) ;
F_429 ( V_112 ) ;
V_112 -> V_40 . V_209 ++ ;
F_243 ( V_112 ) ;
F_427 ( V_112 ) ;
F_249 ( & V_112 -> V_217 ) ;
}
static bool F_430 ( struct V_112 * V_112 )
{
return F_15 ( ! F_431 ( & V_112 -> V_40 . V_480 ) ) ;
}
void F_432 ( struct V_112 * V_112 , struct V_113 * V_114 )
{
if ( F_15 ( ( V_114 -> V_16 & V_9 ) == 0 ) ) {
F_433 ( L_34 ) ;
F_408 ( V_112 ) ;
}
}
static unsigned long
F_434 ( struct V_481 * V_482 , struct V_483 * V_484 )
{
struct V_112 * V_112 ;
int V_485 = V_484 -> V_485 ;
unsigned long V_486 = 0 ;
F_248 ( & V_487 ) ;
F_435 (kvm, &vm_list, vm_list) {
int V_104 ;
F_215 ( V_201 ) ;
if ( ! V_485 -- )
break;
if ( ! V_112 -> V_40 . V_179 &&
! F_430 ( V_112 ) )
continue;
V_104 = F_436 ( & V_112 -> V_488 ) ;
F_248 ( & V_112 -> V_217 ) ;
if ( F_430 ( V_112 ) ) {
F_203 ( V_112 ,
& V_112 -> V_40 . V_480 ) ;
goto V_489;
}
if ( F_245 ( V_112 , & V_201 ) )
V_486 ++ ;
F_203 ( V_112 , & V_201 ) ;
V_489:
F_249 ( & V_112 -> V_217 ) ;
F_437 ( & V_112 -> V_488 , V_104 ) ;
F_438 ( & V_112 -> V_490 , & V_490 ) ;
break;
}
F_249 ( & V_487 ) ;
return V_486 ;
}
static unsigned long
F_439 ( struct V_481 * V_482 , struct V_483 * V_484 )
{
return F_440 ( & V_180 ) ;
}
static void F_441 ( void )
{
if ( V_89 )
F_442 ( V_89 ) ;
if ( V_93 )
F_442 ( V_93 ) ;
}
int F_443 ( void )
{
F_21 () ;
V_89 = F_444 ( L_35 ,
sizeof( struct V_95 ) ,
0 , 0 , NULL ) ;
if ( ! V_89 )
goto V_491;
V_93 = F_444 ( L_36 ,
sizeof( struct V_52 ) ,
0 , 0 , NULL ) ;
if ( ! V_93 )
goto V_491;
if ( F_445 ( & V_180 , 0 , V_83 ) )
goto V_491;
F_446 ( & V_492 ) ;
return 0 ;
V_491:
F_441 () ;
return - V_84 ;
}
unsigned int F_447 ( struct V_112 * V_112 )
{
unsigned int V_493 ;
unsigned int V_494 = 0 ;
struct V_113 * V_114 ;
struct V_102 * V_166 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_167 ; V_108 ++ ) {
V_114 = F_153 ( V_112 , V_108 ) ;
F_154 (memslot, slots)
V_494 += V_166 -> V_173 ;
}
V_493 = V_494 * V_495 / 1000 ;
V_493 = F_155 ( V_493 ,
( unsigned int ) V_496 ) ;
return V_493 ;
}
void F_448 ( struct V_14 * V_15 )
{
F_378 ( V_15 ) ;
F_401 ( V_15 ) ;
F_81 ( V_15 ) ;
}
void F_449 ( void )
{
F_441 () ;
F_450 ( & V_180 ) ;
F_451 ( & V_492 ) ;
F_206 () ;
}
