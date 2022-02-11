void F_1 ( T_1 V_1 )
{
V_2 = V_1 ;
}
static T_1 F_2 ( unsigned int V_3 )
{
T_1 V_4 ;
F_3 ( V_3 & ~ V_5 ) ;
V_4 = ( V_3 & V_6 ) << V_7 ;
V_4 |= ( ( T_1 ) V_3 >> V_8 ) << V_9 ;
return V_4 ;
}
static unsigned int F_4 ( T_1 V_10 )
{
unsigned int V_3 ;
V_10 &= ~ V_2 ;
V_3 = ( V_10 >> V_7 ) & V_6 ;
V_3 |= ( V_10 >> V_9 ) << V_8 ;
return V_3 ;
}
static unsigned int F_5 ( struct V_11 * V_12 )
{
return F_6 ( V_12 ) -> V_13 & V_5 ;
}
static void F_7 ( struct V_11 * V_12 , T_1 * V_14 , T_1 V_15 ,
unsigned V_16 )
{
unsigned int V_3 = F_5 ( V_12 ) ;
T_1 V_4 = F_2 ( V_3 ) ;
V_16 &= V_17 | V_18 ;
V_4 |= V_2 | V_16 | V_15 << V_19 ;
F_8 ( V_14 , V_15 , V_16 , V_3 ) ;
F_9 ( V_14 , V_4 ) ;
}
static bool F_10 ( T_1 V_10 )
{
return ( V_10 & V_2 ) == V_2 ;
}
static T_2 F_11 ( T_1 V_10 )
{
T_1 V_4 = F_2 ( V_5 ) | V_2 ;
return ( V_10 & ~ V_4 ) >> V_19 ;
}
static unsigned F_12 ( T_1 V_10 )
{
T_1 V_4 = F_2 ( V_5 ) | V_2 ;
return ( V_10 & ~ V_4 ) & ~ V_20 ;
}
static bool F_13 ( struct V_11 * V_12 , T_1 * V_14 , T_2 V_15 ,
T_3 V_21 , unsigned V_16 )
{
if ( F_14 ( F_15 ( V_21 ) ) ) {
F_7 ( V_12 , V_14 , V_15 , V_16 ) ;
return true ;
}
return false ;
}
static bool F_16 ( struct V_11 * V_12 , T_1 V_10 )
{
unsigned int V_22 , V_23 ;
V_22 = F_5 ( V_12 ) ;
V_23 = F_4 ( V_10 ) ;
F_17 ( V_10 , V_22 , V_23 ) ;
return F_18 ( V_22 == V_23 ) ;
}
void F_19 ( T_1 V_24 , T_1 V_25 ,
T_1 V_26 , T_1 V_27 , T_1 V_28 , T_1 V_29 )
{
V_30 = V_24 ;
V_31 = V_25 ;
V_32 = V_26 ;
V_33 = V_27 ;
V_34 = V_28 ;
V_35 = V_29 ;
}
static int F_20 ( void )
{
return 1 ;
}
static int F_21 ( struct V_11 * V_12 )
{
return V_12 -> V_36 . V_37 & V_38 ;
}
static int F_22 ( T_1 V_39 )
{
return ( V_39 & 0xFFFFFFFFull ) && ! F_10 ( V_39 ) ;
}
static int F_23 ( T_1 V_39 )
{
return V_39 & V_40 ;
}
static int F_24 ( T_1 V_39 , int V_41 )
{
if ( V_41 == V_42 )
return 1 ;
if ( F_23 ( V_39 ) )
return 1 ;
return 0 ;
}
static T_3 F_25 ( T_1 V_39 )
{
return ( V_39 & V_43 ) >> V_19 ;
}
static T_2 F_26 ( T_4 V_44 )
{
int V_45 = 32 - V_46 - V_19 ;
return ( V_44 & V_47 ) << V_45 ;
}
static void F_27 ( T_1 * V_14 , T_1 V_10 )
{
F_28 ( * V_14 , V_10 ) ;
}
static void F_29 ( T_1 * V_14 , T_1 V_10 )
{
F_28 ( * V_14 , V_10 ) ;
}
static T_1 F_30 ( T_1 * V_14 , T_1 V_10 )
{
return F_31 ( V_14 , V_10 ) ;
}
static T_1 F_32 ( T_1 * V_14 )
{
return F_33 ( * V_14 ) ;
}
static void F_34 ( T_1 * V_14 , T_1 V_10 )
{
struct V_48 * V_49 = F_35 ( F_36 ( V_14 ) ) ;
if ( F_22 ( V_10 ) )
return;
F_37 () ;
V_49 -> V_50 ++ ;
}
static void F_27 ( T_1 * V_14 , T_1 V_10 )
{
union V_51 * V_52 , V_53 ;
V_52 = (union V_51 * ) V_14 ;
V_53 = (union V_51 ) V_10 ;
V_52 -> V_54 = V_53 . V_54 ;
F_37 () ;
F_28 ( V_52 -> V_55 , V_53 . V_55 ) ;
}
static void F_29 ( T_1 * V_14 , T_1 V_10 )
{
union V_51 * V_52 , V_53 ;
V_52 = (union V_51 * ) V_14 ;
V_53 = (union V_51 ) V_10 ;
F_28 ( V_52 -> V_55 , V_53 . V_55 ) ;
F_37 () ;
V_52 -> V_54 = V_53 . V_54 ;
F_34 ( V_14 , V_10 ) ;
}
static T_1 F_30 ( T_1 * V_14 , T_1 V_10 )
{
union V_51 * V_52 , V_53 , V_56 ;
V_52 = (union V_51 * ) V_14 ;
V_53 = (union V_51 ) V_10 ;
V_56 . V_55 = F_31 ( & V_52 -> V_55 , V_53 . V_55 ) ;
V_56 . V_54 = V_52 -> V_54 ;
V_52 -> V_54 = V_53 . V_54 ;
F_34 ( V_14 , V_10 ) ;
return V_56 . V_10 ;
}
static T_1 F_32 ( T_1 * V_14 )
{
struct V_48 * V_49 = F_35 ( F_36 ( V_14 ) ) ;
union V_51 V_10 , * V_56 = (union V_51 * ) V_14 ;
int V_57 ;
V_58:
V_57 = V_49 -> V_50 ;
F_38 () ;
V_10 . V_55 = V_56 -> V_55 ;
F_38 () ;
V_10 . V_54 = V_56 -> V_54 ;
F_38 () ;
if ( F_14 ( V_10 . V_55 != V_56 -> V_55 ||
V_57 != V_49 -> V_50 ) )
goto V_58;
return V_10 . V_10 ;
}
static bool F_39 ( T_1 V_10 )
{
return ( V_10 & ( V_59 | V_60 ) ) ==
( V_59 | V_60 ) ;
}
static bool F_40 ( T_1 V_10 )
{
if ( F_39 ( V_10 ) )
return true ;
if ( ! V_31 )
return false ;
if ( ! F_22 ( V_10 ) )
return false ;
if ( ( V_10 & V_31 ) &&
( ! F_41 ( V_10 ) || ( V_10 & V_32 ) ) )
return false ;
return true ;
}
static bool F_42 ( T_1 V_61 , T_1 V_62 , T_1 V_63 )
{
return ( V_61 & V_63 ) && ! ( V_62 & V_63 ) ;
}
static bool F_43 ( T_1 V_61 , T_1 V_62 , T_1 V_63 )
{
return ( V_61 & V_63 ) != ( V_62 & V_63 ) ;
}
static void F_9 ( T_1 * V_14 , T_1 V_62 )
{
F_3 ( F_22 ( * V_14 ) ) ;
F_27 ( V_14 , V_62 ) ;
}
static bool F_44 ( T_1 * V_14 , T_1 V_62 )
{
T_1 V_61 = * V_14 ;
bool V_64 = false ;
F_3 ( ! F_22 ( V_62 ) ) ;
if ( ! F_22 ( V_61 ) ) {
F_9 ( V_14 , V_62 ) ;
return V_64 ;
}
if ( ! F_40 ( V_61 ) )
F_29 ( V_14 , V_62 ) ;
else
V_61 = F_30 ( V_14 , V_62 ) ;
if ( F_39 ( V_61 ) &&
! F_41 ( V_62 ) )
V_64 = true ;
if ( ! V_31 ) {
if ( V_64 )
F_45 ( F_25 ( V_61 ) ) ;
return V_64 ;
}
if ( F_43 ( V_61 , V_62 ,
V_31 | V_32 ) )
V_64 = true ;
if ( F_42 ( V_61 , V_62 , V_31 ) )
F_46 ( F_25 ( V_61 ) ) ;
if ( F_42 ( V_61 , V_62 , V_32 ) )
F_45 ( F_25 ( V_61 ) ) ;
return V_64 ;
}
static int F_47 ( T_1 * V_14 )
{
T_3 V_21 ;
T_1 V_61 = * V_14 ;
if ( ! F_40 ( V_61 ) )
F_29 ( V_14 , 0ull ) ;
else
V_61 = F_30 ( V_14 , 0ull ) ;
if ( ! F_22 ( V_61 ) )
return 0 ;
V_21 = F_25 ( V_61 ) ;
F_3 ( ! F_48 ( V_21 ) && ! F_49 ( F_50 ( V_21 ) ) ) ;
if ( ! V_31 || V_61 & V_31 )
F_46 ( V_21 ) ;
if ( V_61 & ( V_32 ? V_32 :
V_65 ) )
F_45 ( V_21 ) ;
return 1 ;
}
static void F_51 ( T_1 * V_14 )
{
F_29 ( V_14 , 0ull ) ;
}
static T_1 F_52 ( T_1 * V_14 )
{
return F_32 ( V_14 ) ;
}
static void F_53 ( struct V_11 * V_12 )
{
F_54 () ;
F_55 ( V_12 -> V_66 , V_67 ) ;
}
static void F_56 ( struct V_11 * V_12 )
{
F_57 ( & V_12 -> V_66 , V_68 ) ;
F_58 () ;
}
static int F_59 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
void * V_74 ;
if ( V_70 -> V_75 >= V_73 )
return 0 ;
while ( V_70 -> V_75 < F_60 ( V_70 -> V_76 ) ) {
V_74 = F_61 ( V_72 , V_77 ) ;
if ( ! V_74 )
return - V_78 ;
V_70 -> V_76 [ V_70 -> V_75 ++ ] = V_74 ;
}
return 0 ;
}
static int F_62 ( struct V_69 * V_70 )
{
return V_70 -> V_75 ;
}
static void F_63 ( struct V_69 * V_79 ,
struct V_71 * V_70 )
{
while ( V_79 -> V_75 )
F_64 ( V_70 , V_79 -> V_76 [ -- V_79 -> V_75 ] ) ;
}
static int F_65 ( struct V_69 * V_70 ,
int V_73 )
{
void * V_80 ;
if ( V_70 -> V_75 >= V_73 )
return 0 ;
while ( V_70 -> V_75 < F_60 ( V_70 -> V_76 ) ) {
V_80 = ( void * ) F_66 ( V_77 ) ;
if ( ! V_80 )
return - V_78 ;
V_70 -> V_76 [ V_70 -> V_75 ++ ] = V_80 ;
}
return 0 ;
}
static void F_67 ( struct V_69 * V_79 )
{
while ( V_79 -> V_75 )
F_68 ( ( unsigned long ) V_79 -> V_76 [ -- V_79 -> V_75 ] ) ;
}
static int F_69 ( struct V_11 * V_12 )
{
int V_81 ;
V_81 = F_59 ( & V_12 -> V_36 . V_82 ,
V_83 , 8 + V_84 ) ;
if ( V_81 )
goto V_85;
V_81 = F_65 ( & V_12 -> V_36 . V_86 , 8 ) ;
if ( V_81 )
goto V_85;
V_81 = F_59 ( & V_12 -> V_36 . V_87 ,
V_87 , 4 ) ;
V_85:
return V_81 ;
}
static void F_70 ( struct V_11 * V_12 )
{
F_63 ( & V_12 -> V_36 . V_82 ,
V_83 ) ;
F_67 ( & V_12 -> V_36 . V_86 ) ;
F_63 ( & V_12 -> V_36 . V_87 ,
V_87 ) ;
}
static void * F_71 ( struct V_69 * V_79 )
{
void * V_88 ;
F_72 ( ! V_79 -> V_75 ) ;
V_88 = V_79 -> V_76 [ -- V_79 -> V_75 ] ;
return V_88 ;
}
static struct V_89 * F_73 ( struct V_11 * V_12 )
{
return F_71 ( & V_12 -> V_36 . V_82 ) ;
}
static void F_74 ( struct V_89 * V_89 )
{
F_64 ( V_83 , V_89 ) ;
}
static T_2 F_75 ( struct V_48 * V_49 , int V_90 )
{
if ( ! V_49 -> V_91 . V_92 )
return V_49 -> V_93 [ V_90 ] ;
return V_49 -> V_15 + ( V_90 << ( ( V_49 -> V_91 . V_41 - 1 ) * V_94 ) ) ;
}
static void F_76 ( struct V_48 * V_49 , int V_90 , T_2 V_15 )
{
if ( V_49 -> V_91 . V_92 )
F_72 ( V_15 != F_75 ( V_49 , V_90 ) ) ;
else
V_49 -> V_93 [ V_90 ] = V_15 ;
}
static struct V_95 * F_77 ( T_2 V_15 ,
struct V_96 * V_97 ,
int V_41 )
{
unsigned long V_98 ;
V_98 = F_78 ( V_15 , V_97 -> V_99 , V_41 ) ;
return & V_97 -> V_36 . V_100 [ V_41 - 2 ] [ V_98 ] ;
}
static void F_79 ( struct V_96 * V_97 ,
T_2 V_15 , int V_57 )
{
struct V_95 * V_101 ;
int V_102 ;
for ( V_102 = V_103 ; V_102 <= V_104 ; ++ V_102 ) {
V_101 = F_77 ( V_15 , V_97 , V_102 ) ;
V_101 -> V_105 += V_57 ;
F_3 ( V_101 -> V_105 < 0 ) ;
}
}
void F_80 ( struct V_96 * V_97 , T_2 V_15 )
{
F_79 ( V_97 , V_15 , 1 ) ;
}
void F_81 ( struct V_96 * V_97 , T_2 V_15 )
{
F_79 ( V_97 , V_15 , - 1 ) ;
}
static void F_82 ( struct V_106 * V_106 , struct V_48 * V_49 )
{
struct V_107 * V_108 ;
struct V_96 * V_97 ;
T_2 V_15 ;
V_106 -> V_36 . V_109 ++ ;
V_15 = V_49 -> V_15 ;
V_108 = F_83 ( V_106 , V_49 -> V_91 ) ;
V_97 = F_84 ( V_108 , V_15 ) ;
if ( V_49 -> V_91 . V_41 > V_42 )
return F_85 ( V_106 , V_97 , V_15 ,
V_110 ) ;
F_80 ( V_97 , V_15 ) ;
}
static void F_86 ( struct V_106 * V_106 , struct V_48 * V_49 )
{
struct V_107 * V_108 ;
struct V_96 * V_97 ;
T_2 V_15 ;
V_106 -> V_36 . V_109 -- ;
V_15 = V_49 -> V_15 ;
V_108 = F_83 ( V_106 , V_49 -> V_91 ) ;
V_97 = F_84 ( V_108 , V_15 ) ;
if ( V_49 -> V_91 . V_41 > V_42 )
return F_87 ( V_106 , V_97 , V_15 ,
V_110 ) ;
F_81 ( V_97 , V_15 ) ;
}
static bool F_88 ( T_2 V_15 , int V_41 ,
struct V_96 * V_97 )
{
struct V_95 * V_101 ;
if ( V_97 ) {
V_101 = F_77 ( V_15 , V_97 , V_41 ) ;
return ! ! V_101 -> V_105 ;
}
return true ;
}
static bool F_89 ( struct V_11 * V_12 , T_2 V_15 ,
int V_41 )
{
struct V_96 * V_97 ;
V_97 = F_90 ( V_12 , V_15 ) ;
return F_88 ( V_15 , V_41 , V_97 ) ;
}
static int F_91 ( struct V_106 * V_106 , T_2 V_15 )
{
unsigned long V_111 ;
int V_102 , V_64 = 0 ;
V_111 = F_92 ( V_106 , V_15 ) ;
for ( V_102 = V_42 ; V_102 <= V_104 ; ++ V_102 ) {
if ( V_111 >= F_93 ( V_102 ) )
V_64 = V_102 ;
else
break;
}
return V_64 ;
}
static inline bool F_94 ( struct V_96 * V_97 ,
bool V_112 )
{
if ( ! V_97 || V_97 -> V_113 & V_114 )
return false ;
if ( V_112 && V_97 -> V_115 )
return false ;
return true ;
}
static struct V_96 *
F_95 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_112 )
{
struct V_96 * V_97 ;
V_97 = F_90 ( V_12 , V_15 ) ;
if ( ! F_94 ( V_97 , V_112 ) )
V_97 = NULL ;
return V_97 ;
}
static int F_96 ( struct V_11 * V_12 , T_2 V_116 ,
bool * V_117 )
{
int V_118 , V_41 , V_119 ;
struct V_96 * V_97 ;
if ( F_14 ( * V_117 ) )
return V_42 ;
V_97 = F_90 ( V_12 , V_116 ) ;
* V_117 = ! F_94 ( V_97 , true ) ;
if ( F_14 ( * V_117 ) )
return V_42 ;
V_118 = F_91 ( V_12 -> V_106 , V_116 ) ;
if ( V_118 == V_42 )
return V_118 ;
V_119 = V_73 ( V_120 -> V_121 () , V_118 ) ;
for ( V_41 = V_103 ; V_41 <= V_119 ; ++ V_41 )
if ( F_88 ( V_116 , V_41 , V_97 ) )
break;
return V_41 - 1 ;
}
static int F_97 ( struct V_11 * V_12 , T_1 * V_10 ,
struct V_122 * V_123 )
{
struct V_89 * V_124 ;
int V_102 , V_57 = 0 ;
if ( ! V_123 -> V_125 ) {
F_98 ( L_1 , V_10 , * V_10 ) ;
V_123 -> V_125 = ( unsigned long ) V_10 ;
} else if ( ! ( V_123 -> V_125 & 1 ) ) {
F_98 ( L_2 , V_10 , * V_10 ) ;
V_124 = F_73 ( V_12 ) ;
V_124 -> V_126 [ 0 ] = ( T_1 * ) V_123 -> V_125 ;
V_124 -> V_126 [ 1 ] = V_10 ;
V_123 -> V_125 = ( unsigned long ) V_124 | 1 ;
++ V_57 ;
} else {
F_98 ( L_3 , V_10 , * V_10 ) ;
V_124 = (struct V_89 * ) ( V_123 -> V_125 & ~ 1ul ) ;
while ( V_124 -> V_126 [ V_127 - 1 ] && V_124 -> V_128 ) {
V_124 = V_124 -> V_128 ;
V_57 += V_127 ;
}
if ( V_124 -> V_126 [ V_127 - 1 ] ) {
V_124 -> V_128 = F_73 ( V_12 ) ;
V_124 = V_124 -> V_128 ;
}
for ( V_102 = 0 ; V_124 -> V_126 [ V_102 ] ; ++ V_102 )
++ V_57 ;
V_124 -> V_126 [ V_102 ] = V_10 ;
}
return V_57 ;
}
static void
F_99 ( struct V_122 * V_123 ,
struct V_89 * V_124 , int V_102 ,
struct V_89 * V_129 )
{
int V_130 ;
for ( V_130 = V_127 - 1 ; ! V_124 -> V_126 [ V_130 ] && V_130 > V_102 ; -- V_130 )
;
V_124 -> V_126 [ V_102 ] = V_124 -> V_126 [ V_130 ] ;
V_124 -> V_126 [ V_130 ] = NULL ;
if ( V_130 != 0 )
return;
if ( ! V_129 && ! V_124 -> V_128 )
V_123 -> V_125 = ( unsigned long ) V_124 -> V_126 [ 0 ] ;
else
if ( V_129 )
V_129 -> V_128 = V_124 -> V_128 ;
else
V_123 -> V_125 = ( unsigned long ) V_124 -> V_128 | 1 ;
F_74 ( V_124 ) ;
}
static void F_100 ( T_1 * V_10 , struct V_122 * V_123 )
{
struct V_89 * V_124 ;
struct V_89 * V_129 ;
int V_102 ;
if ( ! V_123 -> V_125 ) {
F_101 ( V_131 L_4 , V_10 ) ;
F_102 () ;
} else if ( ! ( V_123 -> V_125 & 1 ) ) {
F_98 ( L_5 , V_10 ) ;
if ( ( T_1 * ) V_123 -> V_125 != V_10 ) {
F_101 ( V_131 L_6 , V_10 ) ;
F_102 () ;
}
V_123 -> V_125 = 0 ;
} else {
F_98 ( L_7 , V_10 ) ;
V_124 = (struct V_89 * ) ( V_123 -> V_125 & ~ 1ul ) ;
V_129 = NULL ;
while ( V_124 ) {
for ( V_102 = 0 ; V_102 < V_127 && V_124 -> V_126 [ V_102 ] ; ++ V_102 ) {
if ( V_124 -> V_126 [ V_102 ] == V_10 ) {
F_99 ( V_123 ,
V_124 , V_102 , V_129 ) ;
return;
}
}
V_129 = V_124 ;
V_124 = V_124 -> V_128 ;
}
F_103 ( L_8 , V_10 ) ;
F_102 () ;
}
}
static struct V_122 * F_104 ( T_2 V_15 , int V_41 ,
struct V_96 * V_97 )
{
unsigned long V_98 ;
V_98 = F_78 ( V_15 , V_97 -> V_99 , V_41 ) ;
return & V_97 -> V_36 . V_132 [ V_41 - V_42 ] [ V_98 ] ;
}
static struct V_122 * F_105 ( struct V_106 * V_106 , T_2 V_15 ,
struct V_48 * V_49 )
{
struct V_107 * V_108 ;
struct V_96 * V_97 ;
V_108 = F_83 ( V_106 , V_49 -> V_91 ) ;
V_97 = F_84 ( V_108 , V_15 ) ;
return F_104 ( V_15 , V_49 -> V_91 . V_41 , V_97 ) ;
}
static bool F_106 ( struct V_11 * V_12 )
{
struct V_69 * V_70 ;
V_70 = & V_12 -> V_36 . V_82 ;
return F_62 ( V_70 ) ;
}
static int F_107 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
struct V_48 * V_49 ;
struct V_122 * V_123 ;
V_49 = F_35 ( F_36 ( V_10 ) ) ;
F_76 ( V_49 , V_10 - V_49 -> V_133 , V_15 ) ;
V_123 = F_105 ( V_12 -> V_106 , V_15 , V_49 ) ;
return F_97 ( V_12 , V_10 , V_123 ) ;
}
static void F_108 ( struct V_106 * V_106 , T_1 * V_10 )
{
struct V_48 * V_49 ;
T_2 V_15 ;
struct V_122 * V_123 ;
V_49 = F_35 ( F_36 ( V_10 ) ) ;
V_15 = F_75 ( V_49 , V_10 - V_49 -> V_133 ) ;
V_123 = F_105 ( V_106 , V_15 , V_49 ) ;
F_100 ( V_10 , V_123 ) ;
}
static T_1 * F_109 ( struct V_122 * V_123 ,
struct V_134 * V_135 )
{
T_1 * V_14 ;
if ( ! V_123 -> V_125 )
return NULL ;
if ( ! ( V_123 -> V_125 & 1 ) ) {
V_135 -> V_124 = NULL ;
V_14 = ( T_1 * ) V_123 -> V_125 ;
goto V_85;
}
V_135 -> V_124 = (struct V_89 * ) ( V_123 -> V_125 & ~ 1ul ) ;
V_135 -> V_136 = 0 ;
V_14 = V_135 -> V_124 -> V_126 [ V_135 -> V_136 ] ;
V_85:
F_72 ( ! F_22 ( * V_14 ) ) ;
return V_14 ;
}
static T_1 * F_110 ( struct V_134 * V_135 )
{
T_1 * V_14 ;
if ( V_135 -> V_124 ) {
if ( V_135 -> V_136 < V_127 - 1 ) {
++ V_135 -> V_136 ;
V_14 = V_135 -> V_124 -> V_126 [ V_135 -> V_136 ] ;
if ( V_14 )
goto V_85;
}
V_135 -> V_124 = V_135 -> V_124 -> V_128 ;
if ( V_135 -> V_124 ) {
V_135 -> V_136 = 0 ;
V_14 = V_135 -> V_124 -> V_126 [ V_135 -> V_136 ] ;
goto V_85;
}
}
return NULL ;
V_85:
F_72 ( ! F_22 ( * V_14 ) ) ;
return V_14 ;
}
static void F_111 ( struct V_106 * V_106 , T_1 * V_14 )
{
if ( F_47 ( V_14 ) )
F_108 ( V_106 , V_14 ) ;
}
static bool F_112 ( struct V_106 * V_106 , T_1 * V_14 )
{
if ( F_23 ( * V_14 ) ) {
F_3 ( F_35 ( F_36 ( V_14 ) ) -> V_91 . V_41 ==
V_42 ) ;
F_111 ( V_106 , V_14 ) ;
-- V_106 -> V_137 . V_138 ;
return true ;
}
return false ;
}
static void F_113 ( struct V_11 * V_12 , T_1 * V_14 )
{
if ( F_112 ( V_12 -> V_106 , V_14 ) )
F_114 ( V_12 -> V_106 ) ;
}
static bool F_115 ( T_1 * V_14 , bool V_139 )
{
T_1 V_10 = * V_14 ;
if ( ! F_41 ( V_10 ) &&
! ( V_139 && F_39 ( V_10 ) ) )
return false ;
F_98 ( L_9 , V_14 , * V_14 ) ;
if ( V_139 )
V_10 &= ~ V_60 ;
V_10 = V_10 & ~ V_65 ;
return F_44 ( V_14 , V_10 ) ;
}
static bool F_116 ( struct V_106 * V_106 ,
struct V_122 * V_123 ,
bool V_139 )
{
T_1 * V_14 ;
struct V_134 V_135 ;
bool V_140 = false ;
F_117 (rmap_head, &iter, sptep)
V_140 |= F_115 ( V_14 , V_139 ) ;
return V_140 ;
}
static bool F_118 ( T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_98 ( L_10 , V_14 , * V_14 ) ;
V_10 &= ~ V_32 ;
return F_44 ( V_14 , V_10 ) ;
}
static bool F_119 ( struct V_106 * V_106 , struct V_122 * V_123 )
{
T_1 * V_14 ;
struct V_134 V_135 ;
bool V_140 = false ;
F_117 (rmap_head, &iter, sptep)
V_140 |= F_118 ( V_14 ) ;
return V_140 ;
}
static bool F_120 ( T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_98 ( L_11 , V_14 , * V_14 ) ;
V_10 |= V_32 ;
return F_44 ( V_14 , V_10 ) ;
}
static bool F_121 ( struct V_106 * V_106 , struct V_122 * V_123 )
{
T_1 * V_14 ;
struct V_134 V_135 ;
bool V_140 = false ;
F_117 (rmap_head, &iter, sptep)
V_140 |= F_120 ( V_14 ) ;
return V_140 ;
}
static void F_122 ( struct V_106 * V_106 ,
struct V_96 * V_97 ,
T_2 V_141 , unsigned long V_4 )
{
struct V_122 * V_123 ;
while ( V_4 ) {
V_123 = F_104 ( V_97 -> V_99 + V_141 + F_123 ( V_4 ) ,
V_42 , V_97 ) ;
F_116 ( V_106 , V_123 , false ) ;
V_4 &= V_4 - 1 ;
}
}
void F_124 ( struct V_106 * V_106 ,
struct V_96 * V_97 ,
T_2 V_141 , unsigned long V_4 )
{
struct V_122 * V_123 ;
while ( V_4 ) {
V_123 = F_104 ( V_97 -> V_99 + V_141 + F_123 ( V_4 ) ,
V_42 , V_97 ) ;
F_119 ( V_106 , V_123 ) ;
V_4 &= V_4 - 1 ;
}
}
void F_125 ( struct V_106 * V_106 ,
struct V_96 * V_97 ,
T_2 V_141 , unsigned long V_4 )
{
if ( V_120 -> V_142 )
V_120 -> V_142 ( V_106 , V_97 , V_141 ,
V_4 ) ;
else
F_122 ( V_106 , V_97 , V_141 , V_4 ) ;
}
bool F_126 ( struct V_106 * V_106 ,
struct V_96 * V_97 , T_1 V_15 )
{
struct V_122 * V_123 ;
int V_102 ;
bool V_143 = false ;
for ( V_102 = V_42 ; V_102 <= V_104 ; ++ V_102 ) {
V_123 = F_104 ( V_15 , V_102 , V_97 ) ;
V_143 |= F_116 ( V_106 , V_123 , true ) ;
}
return V_143 ;
}
static bool F_127 ( struct V_11 * V_12 , T_1 V_15 )
{
struct V_96 * V_97 ;
V_97 = F_90 ( V_12 , V_15 ) ;
return F_126 ( V_12 -> V_106 , V_97 , V_15 ) ;
}
static bool F_128 ( struct V_106 * V_106 , struct V_122 * V_123 )
{
T_1 * V_14 ;
struct V_134 V_135 ;
bool V_140 = false ;
while ( ( V_14 = F_109 ( V_123 , & V_135 ) ) ) {
F_98 ( L_12 , V_144 , V_14 , * V_14 ) ;
F_111 ( V_106 , V_14 ) ;
V_140 = true ;
}
return V_140 ;
}
static int F_129 ( struct V_106 * V_106 , struct V_122 * V_123 ,
struct V_96 * V_97 , T_2 V_15 , int V_41 ,
unsigned long V_145 )
{
return F_128 ( V_106 , V_123 ) ;
}
static int F_130 ( struct V_106 * V_106 , struct V_122 * V_123 ,
struct V_96 * V_97 , T_2 V_15 , int V_41 ,
unsigned long V_145 )
{
T_1 * V_14 ;
struct V_134 V_135 ;
int V_146 = 0 ;
T_1 V_62 ;
T_5 * V_147 = ( T_5 * ) V_145 ;
T_3 V_148 ;
F_3 ( F_131 ( * V_147 ) ) ;
V_148 = F_132 ( * V_147 ) ;
V_149:
F_117 (rmap_head, &iter, sptep) {
F_98 ( L_13 ,
V_14 , * V_14 , V_15 , V_41 ) ;
V_146 = 1 ;
if ( F_133 ( * V_147 ) ) {
F_111 ( V_106 , V_14 ) ;
goto V_149;
} else {
V_62 = * V_14 & ~ V_43 ;
V_62 |= ( T_1 ) V_148 << V_19 ;
V_62 &= ~ V_65 ;
V_62 &= ~ V_59 ;
V_62 &= ~ V_31 ;
F_47 ( V_14 ) ;
F_9 ( V_14 , V_62 ) ;
}
}
if ( V_146 )
F_114 ( V_106 ) ;
return 0 ;
}
static void
F_134 ( struct V_150 * V_151 , int V_41 )
{
V_151 -> V_41 = V_41 ;
V_151 -> V_15 = V_151 -> V_152 ;
V_151 -> V_132 = F_104 ( V_151 -> V_15 , V_41 , V_151 -> V_97 ) ;
V_151 -> V_153 = F_104 ( V_151 -> V_154 , V_41 ,
V_151 -> V_97 ) ;
}
static void
F_135 ( struct V_150 * V_151 ,
struct V_96 * V_97 , int V_155 ,
int V_156 , T_2 V_152 , T_2 V_154 )
{
V_151 -> V_97 = V_97 ;
V_151 -> V_155 = V_155 ;
V_151 -> V_156 = V_156 ;
V_151 -> V_152 = V_152 ;
V_151 -> V_154 = V_154 ;
F_134 ( V_151 , V_151 -> V_155 ) ;
}
static bool F_136 ( struct V_150 * V_151 )
{
return ! ! V_151 -> V_132 ;
}
static void F_137 ( struct V_150 * V_151 )
{
if ( ++ V_151 -> V_132 <= V_151 -> V_153 ) {
V_151 -> V_15 += ( 1UL << F_138 ( V_151 -> V_41 ) ) ;
return;
}
if ( ++ V_151 -> V_41 > V_151 -> V_156 ) {
V_151 -> V_132 = NULL ;
return;
}
F_134 ( V_151 , V_151 -> V_41 ) ;
}
static int F_139 ( struct V_106 * V_106 ,
unsigned long V_157 ,
unsigned long V_158 ,
unsigned long V_145 ,
int (* F_140)( struct V_106 * V_106 ,
struct V_122 * V_123 ,
struct V_96 * V_97 ,
T_2 V_15 ,
int V_41 ,
unsigned long V_145 ) )
{
struct V_107 * V_108 ;
struct V_96 * V_159 ;
struct V_150 V_151 ;
int V_64 = 0 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_160 ; V_102 ++ ) {
V_108 = F_141 ( V_106 , V_102 ) ;
F_142 (memslot, slots) {
unsigned long V_161 , V_162 ;
T_2 V_163 , V_164 ;
V_161 = F_143 ( V_157 , V_159 -> V_165 ) ;
V_162 = V_73 ( V_158 , V_159 -> V_165 +
( V_159 -> V_166 << V_19 ) ) ;
if ( V_161 >= V_162 )
continue;
V_163 = F_144 ( V_161 , V_159 ) ;
V_164 = F_144 ( V_162 + V_167 - 1 , V_159 ) ;
F_145 (memslot, PT_PAGE_TABLE_LEVEL,
PT_MAX_HUGEPAGE_LEVEL,
gfn_start, gfn_end - 1 ,
&iterator)
V_64 |= F_140 ( V_106 , V_151 . V_132 , V_159 ,
V_151 . V_15 , V_151 . V_41 , V_145 ) ;
}
}
return V_64 ;
}
static int F_146 ( struct V_106 * V_106 , unsigned long V_168 ,
unsigned long V_145 ,
int (* F_140)( struct V_106 * V_106 ,
struct V_122 * V_123 ,
struct V_96 * V_97 ,
T_2 V_15 , int V_41 ,
unsigned long V_145 ) )
{
return F_139 ( V_106 , V_168 , V_168 + 1 , V_145 , F_140 ) ;
}
int F_147 ( struct V_106 * V_106 , unsigned long V_168 )
{
return F_146 ( V_106 , V_168 , 0 , F_129 ) ;
}
int F_148 ( struct V_106 * V_106 , unsigned long V_157 , unsigned long V_158 )
{
return F_139 ( V_106 , V_157 , V_158 , 0 , F_129 ) ;
}
void F_149 ( struct V_106 * V_106 , unsigned long V_168 , T_5 V_39 )
{
F_146 ( V_106 , V_168 , ( unsigned long ) & V_39 , F_130 ) ;
}
static int F_150 ( struct V_106 * V_106 , struct V_122 * V_123 ,
struct V_96 * V_97 , T_2 V_15 , int V_41 ,
unsigned long V_145 )
{
T_1 * V_14 ;
struct V_134 V_169 ( V_135 ) ;
int V_170 = 0 ;
F_72 ( ! V_31 ) ;
F_117 (rmap_head, &iter, sptep) {
if ( * V_14 & V_31 ) {
V_170 = 1 ;
F_151 ( ( F_152 ( V_31 ) - 1 ) ,
( unsigned long * ) V_14 ) ;
}
}
F_153 ( V_15 , V_41 , V_97 , V_170 ) ;
return V_170 ;
}
static int F_154 ( struct V_106 * V_106 , struct V_122 * V_123 ,
struct V_96 * V_97 , T_2 V_15 ,
int V_41 , unsigned long V_145 )
{
T_1 * V_14 ;
struct V_134 V_135 ;
int V_170 = 0 ;
if ( ! V_31 )
goto V_85;
F_117 (rmap_head, &iter, sptep) {
if ( * V_14 & V_31 ) {
V_170 = 1 ;
break;
}
}
V_85:
return V_170 ;
}
static void F_155 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
struct V_122 * V_123 ;
struct V_48 * V_49 ;
V_49 = F_35 ( F_36 ( V_10 ) ) ;
V_123 = F_105 ( V_12 -> V_106 , V_15 , V_49 ) ;
F_129 ( V_12 -> V_106 , V_123 , NULL , V_15 , V_49 -> V_91 . V_41 , 0 ) ;
F_114 ( V_12 -> V_106 ) ;
}
int F_156 ( struct V_106 * V_106 , unsigned long V_157 , unsigned long V_158 )
{
if ( ! V_31 )
return F_139 ( V_106 , V_157 , V_158 , 0 ,
F_129 ) ;
return F_139 ( V_106 , V_157 , V_158 , 0 , F_150 ) ;
}
int F_157 ( struct V_106 * V_106 , unsigned long V_168 )
{
return F_146 ( V_106 , V_168 , 0 , F_154 ) ;
}
static int F_158 ( T_1 * V_133 )
{
T_1 * V_136 ;
T_1 * V_158 ;
for ( V_136 = V_133 , V_158 = V_136 + V_167 / sizeof( T_1 ) ; V_136 != V_158 ; V_136 ++ )
if ( F_22 ( * V_136 ) ) {
F_101 ( V_131 L_14 , V_144 ,
V_136 , * V_136 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_159 ( struct V_106 * V_106 , int V_171 )
{
V_106 -> V_36 . V_172 += V_171 ;
F_160 ( & V_173 , V_171 ) ;
}
static void F_161 ( struct V_48 * V_49 )
{
F_162 ( ! F_158 ( V_49 -> V_133 ) ) ;
F_163 ( & V_49 -> V_174 ) ;
F_164 ( & V_49 -> V_175 ) ;
F_68 ( ( unsigned long ) V_49 -> V_133 ) ;
if ( ! V_49 -> V_91 . V_92 )
F_68 ( ( unsigned long ) V_49 -> V_93 ) ;
F_64 ( V_87 , V_49 ) ;
}
static unsigned F_165 ( T_2 V_15 )
{
return V_15 & ( ( 1 << V_176 ) - 1 ) ;
}
static void F_166 ( struct V_11 * V_12 ,
struct V_48 * V_49 , T_1 * V_177 )
{
if ( ! V_177 )
return;
F_97 ( V_12 , V_177 , & V_49 -> V_178 ) ;
}
static void F_167 ( struct V_48 * V_49 ,
T_1 * V_177 )
{
F_100 ( V_177 , & V_49 -> V_178 ) ;
}
static void F_168 ( struct V_48 * V_49 ,
T_1 * V_177 )
{
F_167 ( V_49 , V_177 ) ;
F_51 ( V_177 ) ;
}
static struct V_48 * F_169 ( struct V_11 * V_12 , int V_92 )
{
struct V_48 * V_49 ;
V_49 = F_71 ( & V_12 -> V_36 . V_87 ) ;
V_49 -> V_133 = F_71 ( & V_12 -> V_36 . V_86 ) ;
if ( ! V_92 )
V_49 -> V_93 = F_71 ( & V_12 -> V_36 . V_86 ) ;
F_170 ( F_171 ( V_49 -> V_133 ) , ( unsigned long ) V_49 ) ;
F_172 ( & V_49 -> V_175 , & V_12 -> V_106 -> V_36 . V_179 ) ;
F_159 ( V_12 -> V_106 , + 1 ) ;
return V_49 ;
}
static void F_173 ( struct V_48 * V_49 )
{
T_1 * V_14 ;
struct V_134 V_135 ;
F_117 (&sp->parent_ptes, &iter, sptep) {
F_174 ( V_14 ) ;
}
}
static void F_174 ( T_1 * V_10 )
{
struct V_48 * V_49 ;
unsigned int V_90 ;
V_49 = F_35 ( F_36 ( V_10 ) ) ;
V_90 = V_10 - V_49 -> V_133 ;
if ( F_175 ( V_90 , V_49 -> V_180 ) )
return;
if ( V_49 -> V_181 ++ )
return;
F_173 ( V_49 ) ;
}
static int F_176 ( struct V_11 * V_12 ,
struct V_48 * V_49 )
{
return 0 ;
}
static void F_177 ( struct V_11 * V_12 , T_6 V_182 )
{
}
static void F_178 ( struct V_11 * V_12 ,
struct V_48 * V_49 , T_1 * V_10 ,
const void * V_39 )
{
F_3 ( 1 ) ;
}
static int F_179 ( struct V_183 * V_184 , struct V_48 * V_49 ,
int V_98 )
{
int V_102 ;
if ( V_49 -> V_185 )
for ( V_102 = 0 ; V_102 < V_184 -> V_171 ; V_102 ++ )
if ( V_184 -> V_80 [ V_102 ] . V_49 == V_49 )
return 0 ;
V_184 -> V_80 [ V_184 -> V_171 ] . V_49 = V_49 ;
V_184 -> V_80 [ V_184 -> V_171 ] . V_98 = V_98 ;
V_184 -> V_171 ++ ;
return ( V_184 -> V_171 == V_186 ) ;
}
static inline void F_180 ( struct V_48 * V_49 , int V_98 )
{
-- V_49 -> V_181 ;
F_3 ( ( int ) V_49 -> V_181 < 0 ) ;
F_181 ( V_98 , V_49 -> V_180 ) ;
}
static int F_182 ( struct V_48 * V_49 ,
struct V_183 * V_184 )
{
int V_102 , V_64 , V_187 = 0 ;
F_183 (i, sp->unsync_child_bitmap, 512 ) {
struct V_48 * V_188 ;
T_1 V_189 = V_49 -> V_133 [ V_102 ] ;
if ( ! F_22 ( V_189 ) || F_23 ( V_189 ) ) {
F_180 ( V_49 , V_102 ) ;
continue;
}
V_188 = F_35 ( V_189 & V_43 ) ;
if ( V_188 -> V_181 ) {
if ( F_179 ( V_184 , V_188 , V_102 ) )
return - V_190 ;
V_64 = F_182 ( V_188 , V_184 ) ;
if ( ! V_64 ) {
F_180 ( V_49 , V_102 ) ;
continue;
} else if ( V_64 > 0 ) {
V_187 += V_64 ;
} else
return V_64 ;
} else if ( V_188 -> V_185 ) {
V_187 ++ ;
if ( F_179 ( V_184 , V_188 , V_102 ) )
return - V_190 ;
} else
F_180 ( V_49 , V_102 ) ;
}
return V_187 ;
}
static int F_184 ( struct V_48 * V_49 ,
struct V_183 * V_184 )
{
V_184 -> V_171 = 0 ;
if ( ! V_49 -> V_181 )
return 0 ;
F_179 ( V_184 , V_49 , V_191 ) ;
return F_182 ( V_49 , V_184 ) ;
}
static void F_185 ( struct V_106 * V_106 , struct V_48 * V_49 )
{
F_3 ( ! V_49 -> V_185 ) ;
F_186 ( V_49 ) ;
V_49 -> V_185 = 0 ;
-- V_106 -> V_137 . V_192 ;
}
static bool F_187 ( struct V_11 * V_12 , struct V_48 * V_49 ,
struct V_193 * V_194 )
{
if ( V_49 -> V_91 . V_195 != ! ! F_188 ( V_12 ) ) {
F_189 ( V_12 -> V_106 , V_49 , V_194 ) ;
return false ;
}
if ( V_12 -> V_36 . V_196 . V_197 ( V_12 , V_49 ) == 0 ) {
F_189 ( V_12 -> V_106 , V_49 , V_194 ) ;
return false ;
}
return true ;
}
static void F_190 ( struct V_11 * V_12 ,
struct V_193 * V_194 ,
bool V_198 , bool V_199 )
{
if ( ! F_191 ( V_194 ) ) {
F_192 ( V_12 -> V_106 , V_194 ) ;
return;
}
if ( V_198 )
F_114 ( V_12 -> V_106 ) ;
else if ( V_199 )
F_193 ( V_200 , V_12 ) ;
}
static void F_194 ( struct V_11 * V_12 , int V_201 ) { }
static void F_195 ( void ) { }
static bool F_196 ( struct V_106 * V_106 , struct V_48 * V_49 )
{
return F_14 ( V_49 -> V_202 != V_106 -> V_36 . V_202 ) ;
}
static bool F_197 ( struct V_11 * V_12 , struct V_48 * V_49 ,
struct V_193 * V_194 )
{
F_185 ( V_12 -> V_106 , V_49 ) ;
return F_187 ( V_12 , V_49 , V_194 ) ;
}
static bool F_198 ( struct V_11 * V_12 , T_2 V_15 ,
struct V_193 * V_194 )
{
struct V_48 * V_203 ;
bool V_64 = false ;
F_199 (vcpu->kvm, s, gfn) {
if ( ! V_203 -> V_185 )
continue;
F_3 ( V_203 -> V_91 . V_41 != V_42 ) ;
V_64 |= F_197 ( V_12 , V_203 , V_194 ) ;
}
return V_64 ;
}
static int F_200 ( struct V_183 * V_184 ,
struct V_204 * V_205 ,
int V_102 )
{
int V_206 ;
for ( V_206 = V_102 + 1 ; V_206 < V_184 -> V_171 ; V_206 ++ ) {
struct V_48 * V_49 = V_184 -> V_80 [ V_206 ] . V_49 ;
unsigned V_98 = V_184 -> V_80 [ V_206 ] . V_98 ;
int V_41 = V_49 -> V_91 . V_41 ;
V_205 -> V_98 [ V_41 - 1 ] = V_98 ;
if ( V_41 == V_42 )
break;
V_205 -> V_207 [ V_41 - 2 ] = V_49 ;
}
return V_206 ;
}
static int F_201 ( struct V_183 * V_184 ,
struct V_204 * V_205 )
{
struct V_48 * V_49 ;
int V_41 ;
if ( V_184 -> V_171 == 0 )
return 0 ;
F_3 ( V_184 -> V_80 [ 0 ] . V_98 != V_191 ) ;
V_49 = V_184 -> V_80 [ 0 ] . V_49 ;
V_41 = V_49 -> V_91 . V_41 ;
F_3 ( V_41 == V_42 ) ;
V_205 -> V_207 [ V_41 - 2 ] = V_49 ;
V_205 -> V_207 [ V_41 - 1 ] = NULL ;
return F_200 ( V_184 , V_205 , 0 ) ;
}
static void F_202 ( struct V_204 * V_205 )
{
struct V_48 * V_49 ;
unsigned int V_41 = 0 ;
do {
unsigned int V_98 = V_205 -> V_98 [ V_41 ] ;
V_49 = V_205 -> V_207 [ V_41 ] ;
if ( ! V_49 )
return;
F_3 ( V_98 == V_191 ) ;
F_180 ( V_49 , V_98 ) ;
V_41 ++ ;
} while ( ! V_49 -> V_181 );
}
static void F_203 ( struct V_11 * V_12 ,
struct V_48 * V_207 )
{
int V_102 ;
struct V_48 * V_49 ;
struct V_204 V_205 ;
struct V_183 V_208 ;
F_204 ( V_194 ) ;
bool V_140 = false ;
while ( F_184 ( V_207 , & V_208 ) ) {
bool V_209 = false ;
F_205 (pages, sp, parents, i)
V_209 |= F_127 ( V_12 , V_49 -> V_15 ) ;
if ( V_209 ) {
F_114 ( V_12 -> V_106 ) ;
V_140 = false ;
}
F_205 (pages, sp, parents, i) {
V_140 |= F_197 ( V_12 , V_49 , & V_194 ) ;
F_202 ( & V_205 ) ;
}
if ( F_206 () || F_207 ( & V_12 -> V_106 -> V_210 ) ) {
F_190 ( V_12 , & V_194 , false , V_140 ) ;
F_208 ( & V_12 -> V_106 -> V_210 ) ;
V_140 = false ;
}
}
F_190 ( V_12 , & V_194 , false , V_140 ) ;
}
static void F_209 ( struct V_48 * V_49 )
{
F_210 ( & V_49 -> V_211 , 0 ) ;
}
static void F_211 ( T_1 * V_10 )
{
struct V_48 * V_49 = F_35 ( F_36 ( V_10 ) ) ;
F_209 ( V_49 ) ;
}
static struct V_48 * F_212 ( struct V_11 * V_12 ,
T_2 V_15 ,
T_6 V_212 ,
unsigned V_41 ,
int V_92 ,
unsigned V_16 )
{
union V_213 V_91 ;
unsigned V_214 ;
struct V_48 * V_49 ;
bool V_215 = false ;
bool V_140 = false ;
F_204 ( V_194 ) ;
V_91 = V_12 -> V_36 . V_196 . V_216 ;
V_91 . V_41 = V_41 ;
V_91 . V_92 = V_92 ;
if ( V_91 . V_92 )
V_91 . V_195 = 0 ;
V_91 . V_16 = V_16 ;
if ( ! V_12 -> V_36 . V_196 . V_217
&& V_12 -> V_36 . V_196 . V_218 <= V_219 ) {
V_214 = V_212 >> ( V_19 + ( V_220 * V_41 ) ) ;
V_214 &= ( 1 << ( ( V_221 - V_220 ) * V_41 ) ) - 1 ;
V_91 . V_214 = V_214 ;
}
F_213 (vcpu->kvm, sp, gfn) {
if ( ! V_215 && V_49 -> V_185 )
V_215 = true ;
if ( V_49 -> V_91 . V_222 != V_91 . V_222 )
continue;
if ( V_49 -> V_185 ) {
if ( ! F_187 ( V_12 , V_49 , & V_194 ) )
break;
F_3 ( ! F_191 ( & V_194 ) ) ;
F_193 ( V_200 , V_12 ) ;
}
if ( V_49 -> V_181 )
F_193 ( V_223 , V_12 ) ;
F_209 ( V_49 ) ;
F_214 ( V_49 , false ) ;
return V_49 ;
}
++ V_12 -> V_106 -> V_137 . V_224 ;
V_49 = F_169 ( V_12 , V_92 ) ;
V_49 -> V_15 = V_15 ;
V_49 -> V_91 = V_91 ;
F_215 ( & V_49 -> V_174 ,
& V_12 -> V_106 -> V_36 . V_225 [ F_165 ( V_15 ) ] ) ;
if ( ! V_92 ) {
F_82 ( V_12 -> V_106 , V_49 ) ;
if ( V_41 == V_42 &&
F_127 ( V_12 , V_15 ) )
F_114 ( V_12 -> V_106 ) ;
if ( V_41 > V_42 && V_215 )
V_140 |= F_198 ( V_12 , V_15 , & V_194 ) ;
}
V_49 -> V_202 = V_12 -> V_106 -> V_36 . V_202 ;
F_216 ( V_49 -> V_133 ) ;
F_214 ( V_49 , true ) ;
F_190 ( V_12 , & V_194 , false , V_140 ) ;
return V_49 ;
}
static void F_217 ( struct V_226 * V_151 ,
struct V_11 * V_12 , T_1 V_227 )
{
V_151 -> V_227 = V_227 ;
V_151 -> V_228 = V_12 -> V_36 . V_196 . V_229 ;
V_151 -> V_41 = V_12 -> V_36 . V_196 . V_230 ;
if ( V_151 -> V_41 == V_231 &&
V_12 -> V_36 . V_196 . V_218 < V_231 &&
! V_12 -> V_36 . V_196 . V_217 )
-- V_151 -> V_41 ;
if ( V_151 -> V_41 == V_232 ) {
V_151 -> V_228
= V_12 -> V_36 . V_196 . V_233 [ ( V_227 >> 30 ) & 3 ] ;
V_151 -> V_228 &= V_43 ;
-- V_151 -> V_41 ;
if ( ! V_151 -> V_228 )
V_151 -> V_41 = 0 ;
}
}
static bool F_218 ( struct V_226 * V_151 )
{
if ( V_151 -> V_41 < V_42 )
return false ;
V_151 -> V_90 = F_219 ( V_151 -> V_227 , V_151 -> V_41 ) ;
V_151 -> V_14 = ( ( T_1 * ) F_220 ( V_151 -> V_228 ) ) + V_151 -> V_90 ;
return true ;
}
static void F_221 ( struct V_226 * V_151 ,
T_1 V_10 )
{
if ( F_24 ( V_10 , V_151 -> V_41 ) ) {
V_151 -> V_41 = 0 ;
return;
}
V_151 -> V_228 = V_10 & V_43 ;
-- V_151 -> V_41 ;
}
static void F_222 ( struct V_226 * V_151 )
{
return F_221 ( V_151 , * V_151 -> V_14 ) ;
}
static void F_223 ( struct V_11 * V_12 , T_1 * V_14 ,
struct V_48 * V_49 )
{
T_1 V_10 ;
F_224 ( V_234 != V_65 ) ;
V_10 = F_36 ( V_49 -> V_133 ) | V_35 | V_65 |
V_30 | V_34 | V_31 ;
F_9 ( V_14 , V_10 ) ;
F_166 ( V_12 , V_49 , V_14 ) ;
if ( V_49 -> V_181 || V_49 -> V_185 )
F_174 ( V_14 ) ;
}
static void F_225 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_235 )
{
if ( F_22 ( * V_14 ) && ! F_23 ( * V_14 ) ) {
struct V_48 * V_188 ;
V_188 = F_35 ( * V_14 & V_43 ) ;
if ( V_188 -> V_91 . V_16 == V_235 )
return;
F_168 ( V_188 , V_14 ) ;
F_114 ( V_12 -> V_106 ) ;
}
}
static bool F_226 ( struct V_106 * V_106 , struct V_48 * V_49 ,
T_1 * V_10 )
{
T_1 V_39 ;
struct V_48 * V_188 ;
V_39 = * V_10 ;
if ( F_22 ( V_39 ) ) {
if ( F_24 ( V_39 , V_49 -> V_91 . V_41 ) ) {
F_111 ( V_106 , V_10 ) ;
if ( F_23 ( V_39 ) )
-- V_106 -> V_137 . V_138 ;
} else {
V_188 = F_35 ( V_39 & V_43 ) ;
F_168 ( V_188 , V_10 ) ;
}
return true ;
}
if ( F_10 ( V_39 ) )
F_51 ( V_10 ) ;
return false ;
}
static void F_227 ( struct V_106 * V_106 ,
struct V_48 * V_49 )
{
unsigned V_102 ;
for ( V_102 = 0 ; V_102 < V_236 ; ++ V_102 )
F_226 ( V_106 , V_49 , V_49 -> V_133 + V_102 ) ;
}
static void F_228 ( struct V_106 * V_106 , struct V_48 * V_49 )
{
T_1 * V_14 ;
struct V_134 V_135 ;
while ( ( V_14 = F_109 ( & V_49 -> V_178 , & V_135 ) ) )
F_168 ( V_49 , V_14 ) ;
}
static int F_229 ( struct V_106 * V_106 ,
struct V_48 * V_207 ,
struct V_193 * V_194 )
{
int V_102 , V_237 = 0 ;
struct V_204 V_205 ;
struct V_183 V_208 ;
if ( V_207 -> V_91 . V_41 == V_42 )
return 0 ;
while ( F_184 ( V_207 , & V_208 ) ) {
struct V_48 * V_49 ;
F_205 (pages, sp, parents, i) {
F_189 ( V_106 , V_49 , V_194 ) ;
F_202 ( & V_205 ) ;
V_237 ++ ;
}
}
return V_237 ;
}
static int F_189 ( struct V_106 * V_106 , struct V_48 * V_49 ,
struct V_193 * V_194 )
{
int V_64 ;
F_230 ( V_49 ) ;
++ V_106 -> V_137 . V_238 ;
V_64 = F_229 ( V_106 , V_49 , V_194 ) ;
F_227 ( V_106 , V_49 ) ;
F_228 ( V_106 , V_49 ) ;
if ( ! V_49 -> V_91 . V_239 && ! V_49 -> V_91 . V_92 )
F_86 ( V_106 , V_49 ) ;
if ( V_49 -> V_185 )
F_185 ( V_106 , V_49 ) ;
if ( ! V_49 -> V_240 ) {
V_64 ++ ;
F_231 ( & V_49 -> V_175 , V_194 ) ;
F_159 ( V_106 , - 1 ) ;
} else {
F_231 ( & V_49 -> V_175 , & V_106 -> V_36 . V_179 ) ;
if ( ! V_49 -> V_91 . V_239 && ! F_196 ( V_106 , V_49 ) )
F_232 ( V_106 ) ;
}
V_49 -> V_91 . V_239 = 1 ;
return V_64 ;
}
static void F_192 ( struct V_106 * V_106 ,
struct V_193 * V_194 )
{
struct V_48 * V_49 , * V_241 ;
if ( F_191 ( V_194 ) )
return;
F_114 ( V_106 ) ;
F_233 (sp, nsp, invalid_list, link) {
F_3 ( ! V_49 -> V_91 . V_239 || V_49 -> V_240 ) ;
F_161 ( V_49 ) ;
}
}
static bool F_234 ( struct V_106 * V_106 ,
struct V_193 * V_194 )
{
struct V_48 * V_49 ;
if ( F_191 ( & V_106 -> V_36 . V_179 ) )
return false ;
V_49 = F_235 ( & V_106 -> V_36 . V_179 ,
struct V_48 , V_175 ) ;
F_189 ( V_106 , V_49 , V_194 ) ;
return true ;
}
void F_236 ( struct V_106 * V_106 , unsigned int V_242 )
{
F_204 ( V_194 ) ;
F_237 ( & V_106 -> V_210 ) ;
if ( V_106 -> V_36 . V_172 > V_242 ) {
while ( V_106 -> V_36 . V_172 > V_242 )
if ( ! F_234 ( V_106 , & V_194 ) )
break;
F_192 ( V_106 , & V_194 ) ;
V_242 = V_106 -> V_36 . V_172 ;
}
V_106 -> V_36 . V_243 = V_242 ;
F_238 ( & V_106 -> V_210 ) ;
}
int F_239 ( struct V_106 * V_106 , T_2 V_15 )
{
struct V_48 * V_49 ;
F_204 ( V_194 ) ;
int V_81 ;
F_240 ( L_15 , V_144 , V_15 ) ;
V_81 = 0 ;
F_237 ( & V_106 -> V_210 ) ;
F_199 (kvm, sp, gfn) {
F_240 ( L_16 , V_144 , V_15 ,
V_49 -> V_91 . V_222 ) ;
V_81 = 1 ;
F_189 ( V_106 , V_49 , & V_194 ) ;
}
F_192 ( V_106 , & V_194 ) ;
F_238 ( & V_106 -> V_210 ) ;
return V_81 ;
}
static void F_241 ( struct V_11 * V_12 , struct V_48 * V_49 )
{
F_242 ( V_49 ) ;
++ V_12 -> V_106 -> V_137 . V_192 ;
V_49 -> V_185 = 1 ;
F_173 ( V_49 ) ;
}
static bool F_243 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_244 )
{
struct V_48 * V_49 ;
if ( F_244 ( V_12 , V_15 , V_110 ) )
return true ;
F_199 (vcpu->kvm, sp, gfn) {
if ( ! V_244 )
return true ;
if ( V_49 -> V_185 )
continue;
F_3 ( V_49 -> V_91 . V_41 != V_42 ) ;
F_241 ( V_12 , V_49 ) ;
}
return false ;
}
static bool F_245 ( T_3 V_21 )
{
if ( F_246 ( V_21 ) )
return ! F_247 ( V_21 ) && F_248 ( F_50 ( V_21 ) ) ;
return true ;
}
static int F_249 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_245 , int V_41 ,
T_2 V_15 , T_3 V_21 , bool V_246 ,
bool V_244 , bool V_247 )
{
T_1 V_10 = 0 ;
int V_64 = 0 ;
if ( F_13 ( V_12 , V_14 , V_15 , V_21 , V_245 ) )
return 0 ;
V_10 |= V_35 ;
if ( ! V_246 )
V_10 |= V_31 ;
if ( V_245 & V_248 )
V_10 |= V_34 ;
else
V_10 |= V_33 ;
if ( V_245 & V_18 )
V_10 |= V_30 ;
if ( V_41 > V_42 )
V_10 |= V_40 ;
if ( V_249 )
V_10 |= V_120 -> V_250 ( V_12 , V_15 ,
F_245 ( V_21 ) ) ;
if ( V_247 )
V_10 |= V_59 ;
else
V_245 &= ~ V_17 ;
V_10 |= ( T_1 ) V_21 << V_19 ;
if ( V_245 & V_17 ) {
if ( V_41 > V_42 &&
F_89 ( V_12 , V_15 , V_41 ) )
goto V_251;
V_10 |= V_65 | V_60 ;
if ( ! V_244 && F_41 ( * V_14 ) )
goto V_252;
if ( F_243 ( V_12 , V_15 , V_244 ) ) {
F_240 ( L_17 ,
V_144 , V_15 ) ;
V_64 = 1 ;
V_245 &= ~ V_17 ;
V_10 &= ~ ( V_65 | V_60 ) ;
}
}
if ( V_245 & V_17 ) {
F_250 ( V_12 , V_15 ) ;
V_10 |= V_32 ;
}
V_252:
if ( F_44 ( V_14 , V_10 ) )
F_114 ( V_12 -> V_106 ) ;
V_251:
return V_64 ;
}
static bool F_251 ( struct V_11 * V_12 , T_1 * V_14 , unsigned V_245 ,
int V_253 , int V_41 , T_2 V_15 , T_3 V_21 ,
bool V_246 , bool V_247 )
{
int V_254 = 0 ;
int V_255 ;
bool V_256 = false ;
F_240 ( L_18 , V_144 ,
* V_14 , V_253 , V_15 ) ;
if ( F_22 ( * V_14 ) ) {
if ( V_41 > V_42 &&
! F_23 ( * V_14 ) ) {
struct V_48 * V_188 ;
T_1 V_39 = * V_14 ;
V_188 = F_35 ( V_39 & V_43 ) ;
F_168 ( V_188 , V_14 ) ;
F_114 ( V_12 -> V_106 ) ;
} else if ( V_21 != F_25 ( * V_14 ) ) {
F_240 ( L_19 ,
F_25 ( * V_14 ) , V_21 ) ;
F_111 ( V_12 -> V_106 , V_14 ) ;
F_114 ( V_12 -> V_106 ) ;
} else
V_254 = 1 ;
}
if ( F_249 ( V_12 , V_14 , V_245 , V_41 , V_15 , V_21 , V_246 ,
true , V_247 ) ) {
if ( V_253 )
V_256 = true ;
F_193 ( V_200 , V_12 ) ;
}
if ( F_14 ( F_10 ( * V_14 ) ) )
V_256 = true ;
F_240 ( L_20 , V_144 , * V_14 ) ;
F_240 ( L_21 ,
F_23 ( * V_14 ) ? L_22 : L_23 ,
* V_14 & V_257 ? L_24 : L_25 , V_15 ,
* V_14 , V_14 ) ;
if ( ! V_254 && F_23 ( * V_14 ) )
++ V_12 -> V_106 -> V_137 . V_138 ;
if ( F_22 ( * V_14 ) ) {
if ( ! V_254 ) {
V_255 = F_107 ( V_12 , V_14 , V_15 ) ;
if ( V_255 > V_258 )
F_155 ( V_12 , V_14 , V_15 ) ;
}
}
F_252 ( V_21 ) ;
return V_256 ;
}
static T_3 F_253 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_112 )
{
struct V_96 * V_97 ;
V_97 = F_95 ( V_12 , V_15 , V_112 ) ;
if ( ! V_97 )
return V_259 ;
return F_254 ( V_97 , V_15 ) ;
}
static int F_255 ( struct V_11 * V_12 ,
struct V_48 * V_49 ,
T_1 * V_157 , T_1 * V_158 )
{
struct V_80 * V_208 [ V_84 ] ;
struct V_96 * V_97 ;
unsigned V_16 = V_49 -> V_91 . V_16 ;
int V_102 , V_64 ;
T_2 V_15 ;
V_15 = F_75 ( V_49 , V_157 - V_49 -> V_133 ) ;
V_97 = F_95 ( V_12 , V_15 , V_16 & V_17 ) ;
if ( ! V_97 )
return - 1 ;
V_64 = F_256 ( V_97 , V_15 , V_208 , V_158 - V_157 ) ;
if ( V_64 <= 0 )
return - 1 ;
for ( V_102 = 0 ; V_102 < V_64 ; V_102 ++ , V_15 ++ , V_157 ++ )
F_251 ( V_12 , V_157 , V_16 , 0 , V_49 -> V_91 . V_41 , V_15 ,
F_257 ( V_208 [ V_102 ] ) , true , true ) ;
return 0 ;
}
static void F_258 ( struct V_11 * V_12 ,
struct V_48 * V_49 , T_1 * V_14 )
{
T_1 * V_10 , * V_157 = NULL ;
int V_102 ;
F_3 ( ! V_49 -> V_91 . V_92 ) ;
V_102 = ( V_14 - V_49 -> V_133 ) & ~ ( V_84 - 1 ) ;
V_10 = V_49 -> V_133 + V_102 ;
for ( V_102 = 0 ; V_102 < V_84 ; V_102 ++ , V_10 ++ ) {
if ( F_22 ( * V_10 ) || V_10 == V_14 ) {
if ( ! V_157 )
continue;
if ( F_255 ( V_12 , V_49 , V_157 , V_10 ) < 0 )
break;
V_157 = NULL ;
} else if ( ! V_157 )
V_157 = V_10 ;
}
}
static void F_259 ( struct V_11 * V_12 , T_1 * V_14 )
{
struct V_48 * V_49 ;
if ( ! V_31 )
return;
V_49 = F_35 ( F_36 ( V_14 ) ) ;
if ( V_49 -> V_91 . V_41 > V_42 )
return;
F_258 ( V_12 , V_49 , V_14 ) ;
}
static int F_260 ( struct V_11 * V_12 , int V_260 , int V_261 ,
int V_41 , T_2 V_15 , T_3 V_21 , bool V_262 )
{
struct V_226 V_151 ;
struct V_48 * V_49 ;
int V_256 = 0 ;
T_2 V_263 ;
if ( ! F_261 ( V_12 -> V_36 . V_196 . V_229 ) )
return 0 ;
F_262 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_151 . V_41 == V_41 ) {
V_256 = F_251 ( V_12 , V_151 . V_14 , V_264 ,
V_260 , V_41 , V_15 , V_21 , V_262 ,
V_261 ) ;
F_259 ( V_12 , V_151 . V_14 ) ;
++ V_12 -> V_137 . V_265 ;
break;
}
F_113 ( V_12 , V_151 . V_14 ) ;
if ( ! F_22 ( * V_151 . V_14 ) ) {
T_1 V_266 = V_151 . V_227 ;
V_266 &= F_263 ( V_151 . V_41 ) ;
V_263 = V_266 >> V_19 ;
V_49 = F_212 ( V_12 , V_263 , V_151 . V_227 ,
V_151 . V_41 - 1 , 1 , V_264 ) ;
F_223 ( V_12 , V_151 . V_14 , V_49 ) ;
}
}
return V_256 ;
}
static void F_264 ( unsigned long V_267 , struct V_268 * V_269 )
{
T_7 V_270 ;
V_270 . V_271 = V_272 ;
V_270 . V_273 = 0 ;
V_270 . V_274 = V_275 ;
V_270 . V_276 = ( void V_277 * ) V_267 ;
V_270 . V_278 = V_19 ;
F_265 ( V_272 , & V_270 , V_269 ) ;
}
static int F_266 ( struct V_11 * V_12 , T_2 V_15 , T_3 V_21 )
{
if ( V_21 == V_279 )
return 1 ;
if ( V_21 == V_280 ) {
F_264 ( F_267 ( V_12 , V_15 ) , V_281 ) ;
return 0 ;
}
return - V_282 ;
}
static void F_268 ( struct V_11 * V_12 ,
T_2 * V_283 , T_3 * V_284 ,
int * V_285 )
{
T_3 V_21 = * V_284 ;
T_2 V_15 = * V_283 ;
int V_41 = * V_285 ;
if ( ! F_269 ( V_21 ) && ! F_48 ( V_21 ) &&
V_41 == V_42 &&
F_270 ( F_50 ( V_21 ) ) &&
! F_89 ( V_12 , V_15 , V_103 ) ) {
unsigned long V_4 ;
* V_285 = V_41 = V_103 ;
V_4 = F_271 ( V_41 ) - 1 ;
F_272 ( ( V_15 & V_4 ) != ( V_21 & V_4 ) ) ;
if ( V_21 & V_4 ) {
V_15 &= ~ V_4 ;
* V_283 = V_15 ;
F_252 ( V_21 ) ;
V_21 &= ~ V_4 ;
F_273 ( V_21 ) ;
* V_284 = V_21 ;
}
}
}
static bool F_274 ( struct V_11 * V_12 , T_6 V_182 , T_2 V_15 ,
T_3 V_21 , unsigned V_16 , int * V_286 )
{
if ( F_14 ( F_275 ( V_21 ) ) ) {
* V_286 = F_266 ( V_12 , V_15 , V_21 ) ;
return true ;
}
if ( F_14 ( F_15 ( V_21 ) ) )
F_276 ( V_12 , V_182 , V_15 , V_16 ) ;
return false ;
}
static bool F_277 ( T_4 V_287 )
{
if ( F_14 ( V_287 & V_288 ) )
return false ;
if ( ! ( V_287 & V_289 ) ||
! ( V_287 & V_290 ) )
return false ;
return true ;
}
static bool
F_278 ( struct V_11 * V_12 , struct V_48 * V_49 ,
T_1 * V_14 , T_1 V_10 )
{
T_2 V_15 ;
F_3 ( ! V_49 -> V_91 . V_92 ) ;
V_15 = F_75 ( V_49 , V_14 - V_49 -> V_133 ) ;
if ( F_279 ( V_14 , V_10 , V_10 | V_65 ) == V_10 )
F_250 ( V_12 , V_15 ) ;
return true ;
}
static bool F_280 ( struct V_11 * V_12 , T_6 V_182 , int V_41 ,
T_4 V_287 )
{
struct V_226 V_151 ;
struct V_48 * V_49 ;
bool V_64 = false ;
T_1 V_10 = 0ull ;
if ( ! F_261 ( V_12 -> V_36 . V_196 . V_229 ) )
return false ;
if ( ! F_277 ( V_287 ) )
return false ;
F_53 ( V_12 ) ;
F_281 (vcpu, gva, iterator, spte)
if ( ! F_22 ( V_10 ) || V_151 . V_41 < V_41 )
break;
if ( ! F_22 ( V_10 ) ) {
V_64 = true ;
goto exit;
}
V_49 = F_35 ( F_36 ( V_151 . V_14 ) ) ;
if ( ! F_24 ( V_10 , V_49 -> V_91 . V_41 ) )
goto exit;
if ( F_41 ( V_10 ) ) {
V_64 = true ;
goto exit;
}
if ( ! F_39 ( V_10 ) )
goto exit;
if ( V_49 -> V_91 . V_41 > V_42 )
goto exit;
V_64 = F_278 ( V_12 , V_49 , V_151 . V_14 , V_10 ) ;
exit:
F_282 ( V_12 , V_182 , V_287 , V_151 . V_14 ,
V_10 , V_64 ) ;
F_56 ( V_12 ) ;
return V_64 ;
}
static int F_283 ( struct V_11 * V_12 , T_6 V_291 , T_4 V_287 ,
T_2 V_15 , bool V_262 )
{
int V_81 ;
int V_41 ;
bool V_117 = false ;
T_3 V_21 ;
unsigned long V_292 ;
bool V_261 , V_260 = V_287 & V_290 ;
V_41 = F_96 ( V_12 , V_15 , & V_117 ) ;
if ( F_18 ( ! V_117 ) ) {
if ( V_41 > V_103 )
V_41 = V_103 ;
V_15 &= ~ ( F_271 ( V_41 ) - 1 ) ;
}
if ( F_280 ( V_12 , V_291 , V_41 , V_287 ) )
return 0 ;
V_292 = V_12 -> V_106 -> V_293 ;
F_38 () ;
if ( F_284 ( V_12 , V_262 , V_15 , V_291 , & V_21 , V_260 , & V_261 ) )
return 0 ;
if ( F_274 ( V_12 , V_291 , V_15 , V_21 , V_264 , & V_81 ) )
return V_81 ;
F_237 ( & V_12 -> V_106 -> V_210 ) ;
if ( F_285 ( V_12 -> V_106 , V_292 ) )
goto V_294;
F_286 ( V_12 ) ;
if ( F_18 ( ! V_117 ) )
F_268 ( V_12 , & V_15 , & V_21 , & V_41 ) ;
V_81 = F_260 ( V_12 , V_260 , V_261 , V_41 , V_15 , V_21 , V_262 ) ;
F_238 ( & V_12 -> V_106 -> V_210 ) ;
return V_81 ;
V_294:
F_238 ( & V_12 -> V_106 -> V_210 ) ;
F_252 ( V_21 ) ;
return 0 ;
}
static void F_287 ( struct V_11 * V_12 )
{
int V_102 ;
struct V_48 * V_49 ;
F_204 ( V_194 ) ;
if ( ! F_261 ( V_12 -> V_36 . V_196 . V_229 ) )
return;
if ( V_12 -> V_36 . V_196 . V_230 == V_231 &&
( V_12 -> V_36 . V_196 . V_218 == V_231 ||
V_12 -> V_36 . V_196 . V_217 ) ) {
T_8 V_295 = V_12 -> V_36 . V_196 . V_229 ;
F_237 ( & V_12 -> V_106 -> V_210 ) ;
V_49 = F_35 ( V_295 ) ;
-- V_49 -> V_240 ;
if ( ! V_49 -> V_240 && V_49 -> V_91 . V_239 ) {
F_189 ( V_12 -> V_106 , V_49 , & V_194 ) ;
F_192 ( V_12 -> V_106 , & V_194 ) ;
}
F_238 ( & V_12 -> V_106 -> V_210 ) ;
V_12 -> V_36 . V_196 . V_229 = V_296 ;
return;
}
F_237 ( & V_12 -> V_106 -> V_210 ) ;
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_8 V_295 = V_12 -> V_36 . V_196 . V_233 [ V_102 ] ;
if ( V_295 ) {
V_295 &= V_43 ;
V_49 = F_35 ( V_295 ) ;
-- V_49 -> V_240 ;
if ( ! V_49 -> V_240 && V_49 -> V_91 . V_239 )
F_189 ( V_12 -> V_106 , V_49 ,
& V_194 ) ;
}
V_12 -> V_36 . V_196 . V_233 [ V_102 ] = V_296 ;
}
F_192 ( V_12 -> V_106 , & V_194 ) ;
F_238 ( & V_12 -> V_106 -> V_210 ) ;
V_12 -> V_36 . V_196 . V_229 = V_296 ;
}
static int F_288 ( struct V_11 * V_12 , T_2 V_297 )
{
int V_64 = 0 ;
if ( ! F_289 ( V_12 -> V_106 , V_297 ) ) {
F_193 ( V_298 , V_12 ) ;
V_64 = 1 ;
}
return V_64 ;
}
static int F_290 ( struct V_11 * V_12 )
{
struct V_48 * V_49 ;
unsigned V_102 ;
if ( V_12 -> V_36 . V_196 . V_230 == V_231 ) {
F_237 ( & V_12 -> V_106 -> V_210 ) ;
F_286 ( V_12 ) ;
V_49 = F_212 ( V_12 , 0 , 0 , V_231 , 1 , V_264 ) ;
++ V_49 -> V_240 ;
F_238 ( & V_12 -> V_106 -> V_210 ) ;
V_12 -> V_36 . V_196 . V_229 = F_36 ( V_49 -> V_133 ) ;
} else if ( V_12 -> V_36 . V_196 . V_230 == V_232 ) {
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_8 V_295 = V_12 -> V_36 . V_196 . V_233 [ V_102 ] ;
F_162 ( F_261 ( V_295 ) ) ;
F_237 ( & V_12 -> V_106 -> V_210 ) ;
F_286 ( V_12 ) ;
V_49 = F_212 ( V_12 , V_102 << ( 30 - V_19 ) ,
V_102 << 30 , V_219 , 1 , V_264 ) ;
V_295 = F_36 ( V_49 -> V_133 ) ;
++ V_49 -> V_240 ;
F_238 ( & V_12 -> V_106 -> V_210 ) ;
V_12 -> V_36 . V_196 . V_233 [ V_102 ] = V_295 | V_257 ;
}
V_12 -> V_36 . V_196 . V_229 = F_36 ( V_12 -> V_36 . V_196 . V_233 ) ;
} else
F_102 () ;
return 0 ;
}
static int F_291 ( struct V_11 * V_12 )
{
struct V_48 * V_49 ;
T_1 V_299 , V_300 ;
T_2 V_297 ;
int V_102 ;
V_297 = V_12 -> V_36 . V_196 . V_301 ( V_12 ) >> V_19 ;
if ( F_288 ( V_12 , V_297 ) )
return 1 ;
if ( V_12 -> V_36 . V_196 . V_218 == V_231 ) {
T_8 V_295 = V_12 -> V_36 . V_196 . V_229 ;
F_162 ( F_261 ( V_295 ) ) ;
F_237 ( & V_12 -> V_106 -> V_210 ) ;
F_286 ( V_12 ) ;
V_49 = F_212 ( V_12 , V_297 , 0 , V_231 ,
0 , V_264 ) ;
V_295 = F_36 ( V_49 -> V_133 ) ;
++ V_49 -> V_240 ;
F_238 ( & V_12 -> V_106 -> V_210 ) ;
V_12 -> V_36 . V_196 . V_229 = V_295 ;
return 0 ;
}
V_300 = V_257 ;
if ( V_12 -> V_36 . V_196 . V_230 == V_231 )
V_300 |= V_302 | V_65 | V_303 ;
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_8 V_295 = V_12 -> V_36 . V_196 . V_233 [ V_102 ] ;
F_162 ( F_261 ( V_295 ) ) ;
if ( V_12 -> V_36 . V_196 . V_218 == V_232 ) {
V_299 = V_12 -> V_36 . V_196 . V_304 ( V_12 , V_102 ) ;
if ( ! ( V_299 & V_257 ) ) {
V_12 -> V_36 . V_196 . V_233 [ V_102 ] = 0 ;
continue;
}
V_297 = V_299 >> V_19 ;
if ( F_288 ( V_12 , V_297 ) )
return 1 ;
}
F_237 ( & V_12 -> V_106 -> V_210 ) ;
F_286 ( V_12 ) ;
V_49 = F_212 ( V_12 , V_297 , V_102 << 30 , V_219 ,
0 , V_264 ) ;
V_295 = F_36 ( V_49 -> V_133 ) ;
++ V_49 -> V_240 ;
F_238 ( & V_12 -> V_106 -> V_210 ) ;
V_12 -> V_36 . V_196 . V_233 [ V_102 ] = V_295 | V_300 ;
}
V_12 -> V_36 . V_196 . V_229 = F_36 ( V_12 -> V_36 . V_196 . V_233 ) ;
if ( V_12 -> V_36 . V_196 . V_230 == V_231 ) {
if ( V_12 -> V_36 . V_196 . V_305 == NULL ) {
T_1 * V_305 ;
V_305 = ( void * ) F_292 ( V_77 ) ;
if ( V_305 == NULL )
return 1 ;
V_305 [ 0 ] = F_36 ( V_12 -> V_36 . V_196 . V_233 ) | V_300 ;
V_12 -> V_36 . V_196 . V_305 = V_305 ;
}
V_12 -> V_36 . V_196 . V_229 = F_36 ( V_12 -> V_36 . V_196 . V_305 ) ;
}
return 0 ;
}
static int F_293 ( struct V_11 * V_12 )
{
if ( V_12 -> V_36 . V_196 . V_217 )
return F_290 ( V_12 ) ;
else
return F_291 ( V_12 ) ;
}
static void F_294 ( struct V_11 * V_12 )
{
int V_102 ;
struct V_48 * V_49 ;
if ( V_12 -> V_36 . V_196 . V_217 )
return;
if ( ! F_261 ( V_12 -> V_36 . V_196 . V_229 ) )
return;
F_295 ( V_12 , V_306 ) ;
F_194 ( V_12 , V_307 ) ;
if ( V_12 -> V_36 . V_196 . V_218 == V_231 ) {
T_8 V_295 = V_12 -> V_36 . V_196 . V_229 ;
V_49 = F_35 ( V_295 ) ;
F_203 ( V_12 , V_49 ) ;
F_194 ( V_12 , V_308 ) ;
return;
}
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_8 V_295 = V_12 -> V_36 . V_196 . V_233 [ V_102 ] ;
if ( V_295 && F_261 ( V_295 ) ) {
V_295 &= V_43 ;
V_49 = F_35 ( V_295 ) ;
F_203 ( V_12 , V_49 ) ;
}
}
F_194 ( V_12 , V_308 ) ;
}
void F_296 ( struct V_11 * V_12 )
{
F_237 ( & V_12 -> V_106 -> V_210 ) ;
F_294 ( V_12 ) ;
F_238 ( & V_12 -> V_106 -> V_210 ) ;
}
static T_9 F_297 ( struct V_11 * V_12 , T_6 V_309 ,
T_4 V_16 , struct V_310 * V_311 )
{
if ( V_311 )
V_311 -> V_287 = 0 ;
return V_309 ;
}
static T_9 F_298 ( struct V_11 * V_12 , T_6 V_309 ,
T_4 V_16 ,
struct V_310 * V_311 )
{
if ( V_311 )
V_311 -> V_287 = 0 ;
return V_12 -> V_36 . V_312 . V_313 ( V_12 , V_309 , V_16 , V_311 ) ;
}
static bool
F_299 ( struct V_314 * V_315 , T_1 V_39 , int V_41 )
{
int V_316 = ( V_39 >> 7 ) & 1 , V_317 = V_39 & 0x3f ;
return ( V_39 & V_315 -> V_318 [ V_316 ] [ V_41 - 1 ] ) |
( ( V_315 -> V_319 & ( 1ull << V_317 ) ) != 0 ) ;
}
static bool F_300 ( struct V_320 * V_196 , T_1 V_44 , int V_41 )
{
return F_299 ( & V_196 -> V_321 , V_44 , V_41 ) ;
}
static bool F_301 ( struct V_320 * V_196 , T_1 V_10 , int V_41 )
{
return F_299 ( & V_196 -> V_322 , V_10 , V_41 ) ;
}
static bool F_302 ( struct V_11 * V_12 , T_1 V_227 , bool V_92 )
{
if ( V_92 )
return F_303 ( V_12 , V_227 ) ;
return F_304 ( V_12 , V_227 ) ;
}
static bool
F_305 ( struct V_11 * V_12 , T_1 V_227 , T_1 * V_14 )
{
struct V_226 V_151 ;
T_1 V_126 [ V_231 ] , V_10 = 0ull ;
int V_295 , V_323 ;
bool V_324 = false ;
if ( ! F_261 ( V_12 -> V_36 . V_196 . V_229 ) )
goto exit;
F_53 ( V_12 ) ;
for ( F_217 ( & V_151 , V_12 , V_227 ) ,
V_323 = V_295 = V_151 . V_41 ;
F_218 ( & V_151 ) ;
F_221 ( & V_151 , V_10 ) ) {
V_10 = F_52 ( V_151 . V_14 ) ;
V_126 [ V_323 - 1 ] = V_10 ;
V_323 -- ;
if ( ! F_22 ( V_10 ) )
break;
V_324 |= F_301 ( & V_12 -> V_36 . V_196 , V_10 ,
V_151 . V_41 ) ;
}
F_56 ( V_12 ) ;
if ( V_324 ) {
F_103 ( L_26 ,
V_144 , V_227 ) ;
while ( V_295 > V_323 ) {
F_103 ( L_27 ,
V_126 [ V_295 - 1 ] , V_295 ) ;
V_295 -- ;
}
}
exit:
* V_14 = V_10 ;
return V_324 ;
}
int F_306 ( struct V_11 * V_12 , T_1 V_227 , bool V_92 )
{
T_1 V_10 ;
bool V_324 ;
if ( F_302 ( V_12 , V_227 , V_92 ) )
return V_325 ;
V_324 = F_305 ( V_12 , V_227 , & V_10 ) ;
if ( F_3 ( V_324 ) )
return V_326 ;
if ( F_10 ( V_10 ) ) {
T_2 V_15 = F_11 ( V_10 ) ;
unsigned V_16 = F_12 ( V_10 ) ;
if ( ! F_16 ( V_12 , V_10 ) )
return V_327 ;
if ( V_92 )
V_227 = 0 ;
F_307 ( V_227 , V_15 , V_16 ) ;
F_276 ( V_12 , V_227 , V_15 , V_16 ) ;
return V_325 ;
}
return V_328 ;
}
static bool F_308 ( struct V_11 * V_12 ,
T_4 V_287 , T_2 V_15 )
{
if ( F_14 ( V_287 & V_288 ) )
return false ;
if ( ! ( V_287 & V_289 ) ||
! ( V_287 & V_290 ) )
return false ;
if ( F_244 ( V_12 , V_15 , V_110 ) )
return true ;
return false ;
}
static void F_309 ( struct V_11 * V_12 , T_6 V_227 )
{
struct V_226 V_151 ;
T_1 V_10 ;
if ( ! F_261 ( V_12 -> V_36 . V_196 . V_229 ) )
return;
F_53 ( V_12 ) ;
F_281 (vcpu, addr, iterator, spte) {
F_211 ( V_151 . V_14 ) ;
if ( ! F_22 ( V_10 ) )
break;
}
F_56 ( V_12 ) ;
}
static int F_310 ( struct V_11 * V_12 , T_6 V_182 ,
T_4 V_287 , bool V_262 )
{
T_2 V_15 = V_182 >> V_19 ;
int V_81 ;
F_240 ( L_28 , V_144 , V_182 , V_287 ) ;
if ( F_308 ( V_12 , V_287 , V_15 ) )
return 1 ;
V_81 = F_69 ( V_12 ) ;
if ( V_81 )
return V_81 ;
F_162 ( ! F_261 ( V_12 -> V_36 . V_196 . V_229 ) ) ;
return F_283 ( V_12 , V_182 & V_20 ,
V_287 , V_15 , V_262 ) ;
}
static int F_311 ( struct V_11 * V_12 , T_6 V_182 , T_2 V_15 )
{
struct V_329 V_36 ;
V_36 . V_330 = ( V_12 -> V_36 . V_331 . V_332 ++ << 12 ) | V_12 -> V_333 ;
V_36 . V_15 = V_15 ;
V_36 . V_217 = V_12 -> V_36 . V_196 . V_217 ;
V_36 . V_334 = V_12 -> V_36 . V_196 . V_301 ( V_12 ) ;
return F_312 ( V_12 , V_182 , F_267 ( V_12 , V_15 ) , & V_36 ) ;
}
static bool F_313 ( struct V_11 * V_12 )
{
if ( F_14 ( ! F_314 ( V_12 ) ||
F_315 ( V_12 ) ) )
return false ;
return V_120 -> V_335 ( V_12 ) ;
}
static bool F_284 ( struct V_11 * V_12 , bool V_262 , T_2 V_15 ,
T_6 V_182 , T_3 * V_21 , bool V_260 , bool * V_336 )
{
struct V_96 * V_97 ;
bool V_337 ;
V_97 = F_90 ( V_12 , V_15 ) ;
V_337 = false ;
* V_21 = F_316 ( V_97 , V_15 , false , & V_337 , V_260 , V_336 ) ;
if ( ! V_337 )
return false ;
if ( ! V_262 && F_313 ( V_12 ) ) {
F_317 ( V_182 , V_15 ) ;
if ( F_318 ( V_12 , V_15 ) ) {
F_319 ( V_182 , V_15 ) ;
F_193 ( V_338 , V_12 ) ;
return true ;
} else if ( F_311 ( V_12 , V_182 , V_15 ) )
return true ;
}
* V_21 = F_316 ( V_97 , V_15 , false , NULL , V_260 , V_336 ) ;
return false ;
}
static bool
F_320 ( struct V_11 * V_12 , T_2 V_15 , int V_41 )
{
int V_339 = F_271 ( V_41 ) ;
V_15 &= ~ ( V_339 - 1 ) ;
return F_321 ( V_12 , V_15 , V_339 ) ;
}
static int F_322 ( struct V_11 * V_12 , T_6 V_340 , T_4 V_287 ,
bool V_262 )
{
T_3 V_21 ;
int V_81 ;
int V_41 ;
bool V_117 ;
T_2 V_15 = V_340 >> V_19 ;
unsigned long V_292 ;
int V_260 = V_287 & V_290 ;
bool V_261 ;
F_162 ( ! F_261 ( V_12 -> V_36 . V_196 . V_229 ) ) ;
if ( F_308 ( V_12 , V_287 , V_15 ) )
return 1 ;
V_81 = F_69 ( V_12 ) ;
if ( V_81 )
return V_81 ;
V_117 = ! F_320 ( V_12 , V_15 ,
V_103 ) ;
V_41 = F_96 ( V_12 , V_15 , & V_117 ) ;
if ( F_18 ( ! V_117 ) ) {
if ( V_41 > V_103 &&
! F_320 ( V_12 , V_15 , V_41 ) )
V_41 = V_103 ;
V_15 &= ~ ( F_271 ( V_41 ) - 1 ) ;
}
if ( F_280 ( V_12 , V_340 , V_41 , V_287 ) )
return 0 ;
V_292 = V_12 -> V_106 -> V_293 ;
F_38 () ;
if ( F_284 ( V_12 , V_262 , V_15 , V_340 , & V_21 , V_260 , & V_261 ) )
return 0 ;
if ( F_274 ( V_12 , 0 , V_15 , V_21 , V_264 , & V_81 ) )
return V_81 ;
F_237 ( & V_12 -> V_106 -> V_210 ) ;
if ( F_285 ( V_12 -> V_106 , V_292 ) )
goto V_294;
F_286 ( V_12 ) ;
if ( F_18 ( ! V_117 ) )
F_268 ( V_12 , & V_15 , & V_21 , & V_41 ) ;
V_81 = F_260 ( V_12 , V_260 , V_261 , V_41 , V_15 , V_21 , V_262 ) ;
F_238 ( & V_12 -> V_106 -> V_210 ) ;
return V_81 ;
V_294:
F_238 ( & V_12 -> V_106 -> V_210 ) ;
F_252 ( V_21 ) ;
return 0 ;
}
static void F_323 ( struct V_11 * V_12 ,
struct V_320 * V_341 )
{
V_341 -> V_342 = F_310 ;
V_341 -> V_343 = F_297 ;
V_341 -> V_197 = F_176 ;
V_341 -> V_344 = F_177 ;
V_341 -> V_345 = F_178 ;
V_341 -> V_218 = 0 ;
V_341 -> V_230 = V_232 ;
V_341 -> V_229 = V_296 ;
V_341 -> V_217 = true ;
V_341 -> V_346 = false ;
}
void F_324 ( struct V_11 * V_12 )
{
F_287 ( V_12 ) ;
}
static unsigned long V_301 ( struct V_11 * V_12 )
{
return F_325 ( V_12 ) ;
}
static void F_326 ( struct V_11 * V_12 ,
struct V_310 * V_347 )
{
V_12 -> V_36 . V_196 . F_326 ( V_12 , V_347 ) ;
}
static bool F_327 ( struct V_11 * V_12 , T_1 * V_14 , T_2 V_15 ,
unsigned V_16 , int * V_348 )
{
if ( F_14 ( F_10 ( * V_14 ) ) ) {
if ( V_15 != F_11 ( * V_14 ) ) {
F_51 ( V_14 ) ;
return true ;
}
( * V_348 ) ++ ;
F_7 ( V_12 , V_14 , V_15 , V_16 ) ;
return true ;
}
return false ;
}
static inline bool F_328 ( struct V_320 * V_196 ,
unsigned V_41 , unsigned V_44 )
{
V_44 |= V_41 - V_42 - 1 ;
V_44 &= V_41 - V_196 -> V_349 ;
return V_44 & V_40 ;
}
static void
F_329 ( struct V_11 * V_12 ,
struct V_314 * V_315 ,
int V_350 , int V_41 , bool V_346 , bool V_351 ,
bool V_352 , bool V_353 )
{
T_1 V_354 = 0 ;
T_1 V_355 = 0 ;
T_1 V_356 = 0 ;
V_315 -> V_319 = 0 ;
if ( ! V_346 )
V_354 = F_330 ( 63 , 63 ) ;
if ( ! V_351 )
V_355 = F_330 ( 7 , 7 ) ;
if ( V_353 )
V_356 = F_330 ( 8 , 8 ) ;
switch ( V_41 ) {
case V_219 :
V_315 -> V_318 [ 0 ] [ 1 ] = 0 ;
V_315 -> V_318 [ 0 ] [ 0 ] = 0 ;
V_315 -> V_318 [ 1 ] [ 0 ] =
V_315 -> V_318 [ 0 ] [ 0 ] ;
if ( ! V_352 ) {
V_315 -> V_318 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_20 () )
V_315 -> V_318 [ 1 ] [ 1 ] = F_330 ( 17 , 21 ) ;
else
V_315 -> V_318 [ 1 ] [ 1 ] = F_330 ( 13 , 21 ) ;
break;
case V_232 :
V_315 -> V_318 [ 0 ] [ 2 ] =
F_330 ( V_350 , 63 ) |
F_330 ( 5 , 8 ) | F_330 ( 1 , 2 ) ;
V_315 -> V_318 [ 0 ] [ 1 ] = V_354 |
F_330 ( V_350 , 62 ) ;
V_315 -> V_318 [ 0 ] [ 0 ] = V_354 |
F_330 ( V_350 , 62 ) ;
V_315 -> V_318 [ 1 ] [ 1 ] = V_354 |
F_330 ( V_350 , 62 ) |
F_330 ( 13 , 20 ) ;
V_315 -> V_318 [ 1 ] [ 0 ] =
V_315 -> V_318 [ 0 ] [ 0 ] ;
break;
case V_231 :
V_315 -> V_318 [ 0 ] [ 3 ] = V_354 |
V_356 | F_330 ( 7 , 7 ) |
F_330 ( V_350 , 51 ) ;
V_315 -> V_318 [ 0 ] [ 2 ] = V_354 |
V_356 | V_355 |
F_330 ( V_350 , 51 ) ;
V_315 -> V_318 [ 0 ] [ 1 ] = V_354 |
F_330 ( V_350 , 51 ) ;
V_315 -> V_318 [ 0 ] [ 0 ] = V_354 |
F_330 ( V_350 , 51 ) ;
V_315 -> V_318 [ 1 ] [ 3 ] =
V_315 -> V_318 [ 0 ] [ 3 ] ;
V_315 -> V_318 [ 1 ] [ 2 ] = V_354 |
V_355 | F_330 ( V_350 , 51 ) |
F_330 ( 13 , 29 ) ;
V_315 -> V_318 [ 1 ] [ 1 ] = V_354 |
F_330 ( V_350 , 51 ) |
F_330 ( 13 , 20 ) ;
V_315 -> V_318 [ 1 ] [ 0 ] =
V_315 -> V_318 [ 0 ] [ 0 ] ;
break;
}
}
static void F_331 ( struct V_11 * V_12 ,
struct V_320 * V_341 )
{
F_329 ( V_12 , & V_341 -> V_321 ,
F_332 ( V_12 ) , V_341 -> V_218 ,
V_341 -> V_346 , F_333 ( V_12 ) ,
F_334 ( V_12 ) , F_335 ( V_12 ) ) ;
}
static void
F_336 ( struct V_314 * V_315 ,
int V_350 , bool V_357 )
{
T_1 V_319 ;
V_315 -> V_318 [ 0 ] [ 3 ] =
F_330 ( V_350 , 51 ) | F_330 ( 3 , 7 ) ;
V_315 -> V_318 [ 0 ] [ 2 ] =
F_330 ( V_350 , 51 ) | F_330 ( 3 , 6 ) ;
V_315 -> V_318 [ 0 ] [ 1 ] =
F_330 ( V_350 , 51 ) | F_330 ( 3 , 6 ) ;
V_315 -> V_318 [ 0 ] [ 0 ] = F_330 ( V_350 , 51 ) ;
V_315 -> V_318 [ 1 ] [ 3 ] = V_315 -> V_318 [ 0 ] [ 3 ] ;
V_315 -> V_318 [ 1 ] [ 2 ] =
F_330 ( V_350 , 51 ) | F_330 ( 12 , 29 ) ;
V_315 -> V_318 [ 1 ] [ 1 ] =
F_330 ( V_350 , 51 ) | F_330 ( 12 , 20 ) ;
V_315 -> V_318 [ 1 ] [ 0 ] = V_315 -> V_318 [ 0 ] [ 0 ] ;
V_319 = 0xFFull << ( 2 * 8 ) ;
V_319 |= 0xFFull << ( 3 * 8 ) ;
V_319 |= 0xFFull << ( 7 * 8 ) ;
V_319 |= F_337 ( 1ull << 2 ) ;
V_319 |= F_337 ( 1ull << 6 ) ;
if ( ! V_357 ) {
V_319 |= F_337 ( 1ull << 4 ) ;
}
V_315 -> V_319 = V_319 ;
}
static void F_338 ( struct V_11 * V_12 ,
struct V_320 * V_341 , bool V_357 )
{
F_336 ( & V_341 -> V_321 ,
F_332 ( V_12 ) , V_357 ) ;
}
void
F_339 ( struct V_11 * V_12 , struct V_320 * V_341 )
{
bool V_358 = V_341 -> V_346 || V_341 -> V_216 . V_359 ;
F_329 ( V_12 , & V_341 -> V_322 ,
V_360 . V_361 ,
V_341 -> V_230 , V_358 ,
F_333 ( V_12 ) , F_334 ( V_12 ) ,
true ) ;
}
static inline bool F_340 ( void )
{
F_341 ( ! V_249 ) ;
return V_34 == 0 ;
}
static void
F_342 ( struct V_11 * V_12 ,
struct V_320 * V_341 )
{
if ( F_340 () )
F_329 ( V_12 , & V_341 -> V_322 ,
V_360 . V_361 ,
V_341 -> V_230 , false ,
F_343 ( V_362 ) ,
true , true ) ;
else
F_336 ( & V_341 -> V_322 ,
V_360 . V_361 ,
false ) ;
}
static void
F_344 ( struct V_11 * V_12 ,
struct V_320 * V_341 , bool V_357 )
{
F_336 ( & V_341 -> V_322 ,
V_360 . V_361 , V_357 ) ;
}
static void F_345 ( struct V_11 * V_12 ,
struct V_320 * V_196 , bool V_363 )
{
unsigned V_364 , V_365 , V_366 ;
T_10 V_367 ;
bool V_347 , V_368 , V_369 , V_370 , V_371 , V_372 , V_373 , V_374 , V_375 , V_376 , V_377 = 0 ;
V_376 = F_346 ( V_12 , V_378 ) ;
V_375 = F_346 ( V_12 , V_379 ) ;
for ( V_365 = 0 ; V_365 < F_60 ( V_196 -> V_380 ) ; ++ V_365 ) {
V_366 = V_365 << 1 ;
V_367 = 0 ;
V_371 = V_366 & V_290 ;
V_372 = V_366 & V_381 ;
V_373 = V_366 & V_382 ;
V_374 = ! ( V_366 & V_288 ) ;
for ( V_364 = 0 ; V_364 < 8 ; ++ V_364 ) {
V_368 = V_364 & V_248 ;
V_369 = V_364 & V_17 ;
V_370 = V_364 & V_18 ;
if ( ! V_363 ) {
V_368 |= ! V_196 -> V_346 ;
V_369 |= ! F_347 ( V_12 ) && ! V_372 ;
V_368 &= ! ( V_376 && V_370 && ! V_372 ) ;
V_377 = V_375 && V_370 && ! V_372 && ! V_373 ;
}
V_347 = ( V_373 && ! V_368 ) || ( V_372 && ! V_370 ) || ( V_371 && ! V_369 ) ||
( V_374 && V_377 ) ;
V_367 |= V_347 << V_364 ;
}
V_196 -> V_380 [ V_365 ] = V_367 ;
}
}
static void F_348 ( struct V_11 * V_12 , struct V_320 * V_196 ,
bool V_363 )
{
unsigned V_364 ;
bool V_383 ;
if ( V_363 ) {
V_196 -> V_384 = 0 ;
return;
}
if ( ! F_346 ( V_12 , V_385 ) || ! F_349 ( V_12 ) ) {
V_196 -> V_384 = 0 ;
return;
}
V_383 = F_347 ( V_12 ) ;
for ( V_364 = 0 ; V_364 < F_60 ( V_196 -> V_380 ) ; ++ V_364 ) {
unsigned V_366 , V_386 ;
bool V_387 , V_388 , V_373 , V_372 , V_371 , V_389 ;
V_366 = V_364 << 1 ;
V_373 = V_366 & V_382 ;
V_372 = V_366 & V_381 ;
V_371 = V_366 & V_290 ;
V_389 = V_366 & V_288 ;
V_387 = ( ! V_373 && V_389 ) ;
V_388 = V_387 && V_371 && ( V_372 || V_383 ) ;
V_386 = ! ! V_387 ;
V_386 |= ( ! ! V_388 ) << 1 ;
V_196 -> V_384 |= ( V_386 & 3 ) << V_366 ;
}
}
static void F_350 ( struct V_11 * V_12 , struct V_320 * V_196 )
{
unsigned V_218 = V_196 -> V_218 ;
V_196 -> V_349 = V_218 ;
if ( V_218 == V_219 && F_334 ( V_12 ) )
V_196 -> V_349 ++ ;
}
static void F_351 ( struct V_11 * V_12 ,
struct V_320 * V_341 ,
int V_41 )
{
V_341 -> V_346 = F_21 ( V_12 ) ;
V_341 -> V_218 = V_41 ;
F_331 ( V_12 , V_341 ) ;
F_345 ( V_12 , V_341 , false ) ;
F_348 ( V_12 , V_341 , false ) ;
F_350 ( V_12 , V_341 ) ;
F_162 ( ! F_188 ( V_12 ) ) ;
V_341 -> V_342 = V_390 ;
V_341 -> V_343 = V_391 ;
V_341 -> V_197 = V_392 ;
V_341 -> V_344 = V_393 ;
V_341 -> V_345 = V_394 ;
V_341 -> V_230 = V_41 ;
V_341 -> V_229 = V_296 ;
V_341 -> V_217 = false ;
}
static void F_352 ( struct V_11 * V_12 ,
struct V_320 * V_341 )
{
F_351 ( V_12 , V_341 , V_231 ) ;
}
static void F_353 ( struct V_11 * V_12 ,
struct V_320 * V_341 )
{
V_341 -> V_346 = false ;
V_341 -> V_218 = V_219 ;
F_331 ( V_12 , V_341 ) ;
F_345 ( V_12 , V_341 , false ) ;
F_348 ( V_12 , V_341 , false ) ;
F_350 ( V_12 , V_341 ) ;
V_341 -> V_342 = V_395 ;
V_341 -> V_343 = V_396 ;
V_341 -> V_197 = V_397 ;
V_341 -> V_344 = V_398 ;
V_341 -> V_345 = V_399 ;
V_341 -> V_230 = V_232 ;
V_341 -> V_229 = V_296 ;
V_341 -> V_217 = false ;
}
static void F_354 ( struct V_11 * V_12 ,
struct V_320 * V_341 )
{
F_351 ( V_12 , V_341 , V_232 ) ;
}
static void F_355 ( struct V_11 * V_12 )
{
struct V_320 * V_341 = & V_12 -> V_36 . V_196 ;
V_341 -> V_216 . V_222 = 0 ;
V_341 -> V_216 . V_400 = F_356 ( V_12 ) ;
V_341 -> V_342 = F_322 ;
V_341 -> V_197 = F_176 ;
V_341 -> V_344 = F_177 ;
V_341 -> V_345 = F_178 ;
V_341 -> V_230 = V_120 -> V_401 () ;
V_341 -> V_229 = V_296 ;
V_341 -> V_217 = true ;
V_341 -> V_402 = V_120 -> V_403 ;
V_341 -> V_301 = V_301 ;
V_341 -> V_304 = V_404 ;
V_341 -> F_326 = V_405 ;
if ( ! F_357 ( V_12 ) ) {
V_341 -> V_346 = false ;
V_341 -> V_343 = F_297 ;
V_341 -> V_218 = 0 ;
} else if ( F_349 ( V_12 ) ) {
V_341 -> V_346 = F_21 ( V_12 ) ;
V_341 -> V_218 = V_231 ;
F_331 ( V_12 , V_341 ) ;
V_341 -> V_343 = V_391 ;
} else if ( F_188 ( V_12 ) ) {
V_341 -> V_346 = F_21 ( V_12 ) ;
V_341 -> V_218 = V_232 ;
F_331 ( V_12 , V_341 ) ;
V_341 -> V_343 = V_391 ;
} else {
V_341 -> V_346 = false ;
V_341 -> V_218 = V_219 ;
F_331 ( V_12 , V_341 ) ;
V_341 -> V_343 = V_396 ;
}
F_345 ( V_12 , V_341 , false ) ;
F_348 ( V_12 , V_341 , false ) ;
F_350 ( V_12 , V_341 ) ;
F_342 ( V_12 , V_341 ) ;
}
void F_358 ( struct V_11 * V_12 )
{
bool V_406 = F_346 ( V_12 , V_378 ) ;
bool V_377 = F_346 ( V_12 , V_379 ) ;
struct V_320 * V_341 = & V_12 -> V_36 . V_196 ;
F_162 ( F_261 ( V_341 -> V_229 ) ) ;
if ( ! F_357 ( V_12 ) )
F_323 ( V_12 , V_341 ) ;
else if ( F_349 ( V_12 ) )
F_352 ( V_12 , V_341 ) ;
else if ( F_188 ( V_12 ) )
F_354 ( V_12 , V_341 ) ;
else
F_353 ( V_12 , V_341 ) ;
V_341 -> V_216 . V_407 = F_21 ( V_12 ) ;
V_341 -> V_216 . V_195 = ! ! F_188 ( V_12 ) ;
V_341 -> V_216 . V_408 = F_347 ( V_12 ) ;
V_341 -> V_216 . V_359
= V_406 && ! F_347 ( V_12 ) ;
V_341 -> V_216 . V_409
= V_377 && ! F_347 ( V_12 ) ;
V_341 -> V_216 . V_400 = F_356 ( V_12 ) ;
F_339 ( V_12 , V_341 ) ;
}
void F_359 ( struct V_11 * V_12 , bool V_357 )
{
struct V_320 * V_341 = & V_12 -> V_36 . V_196 ;
F_162 ( F_261 ( V_341 -> V_229 ) ) ;
V_341 -> V_230 = V_120 -> V_401 () ;
V_341 -> V_346 = true ;
V_341 -> V_342 = V_410 ;
V_341 -> V_343 = V_411 ;
V_341 -> V_197 = V_412 ;
V_341 -> V_344 = V_413 ;
V_341 -> V_345 = V_414 ;
V_341 -> V_218 = V_341 -> V_230 ;
V_341 -> V_229 = V_296 ;
V_341 -> V_217 = false ;
F_345 ( V_12 , V_341 , true ) ;
F_348 ( V_12 , V_341 , true ) ;
F_338 ( V_12 , V_341 , V_357 ) ;
F_344 ( V_12 , V_341 , V_357 ) ;
}
static void F_360 ( struct V_11 * V_12 )
{
struct V_320 * V_341 = & V_12 -> V_36 . V_196 ;
F_358 ( V_12 ) ;
V_341 -> V_402 = V_120 -> V_402 ;
V_341 -> V_301 = V_301 ;
V_341 -> V_304 = V_404 ;
V_341 -> F_326 = V_405 ;
}
static void F_361 ( struct V_11 * V_12 )
{
struct V_320 * V_415 = & V_12 -> V_36 . V_312 ;
V_415 -> V_301 = V_301 ;
V_415 -> V_304 = V_404 ;
V_415 -> F_326 = V_405 ;
if ( ! F_357 ( V_12 ) ) {
V_415 -> V_346 = false ;
V_415 -> V_218 = 0 ;
V_415 -> V_343 = F_298 ;
} else if ( F_349 ( V_12 ) ) {
V_415 -> V_346 = F_21 ( V_12 ) ;
V_415 -> V_218 = V_231 ;
F_331 ( V_12 , V_415 ) ;
V_415 -> V_343 = V_416 ;
} else if ( F_188 ( V_12 ) ) {
V_415 -> V_346 = F_21 ( V_12 ) ;
V_415 -> V_218 = V_232 ;
F_331 ( V_12 , V_415 ) ;
V_415 -> V_343 = V_416 ;
} else {
V_415 -> V_346 = false ;
V_415 -> V_218 = V_219 ;
F_331 ( V_12 , V_415 ) ;
V_415 -> V_343 = V_417 ;
}
F_345 ( V_12 , V_415 , false ) ;
F_348 ( V_12 , V_415 , false ) ;
F_350 ( V_12 , V_415 ) ;
}
static void F_362 ( struct V_11 * V_12 )
{
if ( F_363 ( V_12 ) )
F_361 ( V_12 ) ;
else if ( V_249 )
F_355 ( V_12 ) ;
else
F_360 ( V_12 ) ;
}
void F_364 ( struct V_11 * V_12 )
{
F_365 ( V_12 ) ;
F_362 ( V_12 ) ;
}
int F_366 ( struct V_11 * V_12 )
{
int V_81 ;
V_81 = F_69 ( V_12 ) ;
if ( V_81 )
goto V_85;
V_81 = F_293 ( V_12 ) ;
F_296 ( V_12 ) ;
if ( V_81 )
goto V_85;
V_12 -> V_36 . V_196 . V_402 ( V_12 , V_12 -> V_36 . V_196 . V_229 ) ;
V_85:
return V_81 ;
}
void F_365 ( struct V_11 * V_12 )
{
F_287 ( V_12 ) ;
F_3 ( F_261 ( V_12 -> V_36 . V_196 . V_229 ) ) ;
}
static void F_367 ( struct V_11 * V_12 ,
struct V_48 * V_49 , T_1 * V_10 ,
const void * V_418 )
{
if ( V_49 -> V_91 . V_41 != V_42 ) {
++ V_12 -> V_106 -> V_137 . V_419 ;
return;
}
++ V_12 -> V_106 -> V_137 . V_420 ;
V_12 -> V_36 . V_196 . V_345 ( V_12 , V_49 , V_10 , V_418 ) ;
}
static bool F_368 ( T_1 V_421 , T_1 V_418 )
{
if ( ! F_22 ( V_421 ) )
return false ;
if ( ! F_22 ( V_418 ) )
return true ;
if ( ( V_421 ^ V_418 ) & V_43 )
return true ;
V_421 ^= V_33 ;
V_418 ^= V_33 ;
return ( V_421 & ~ V_418 & V_422 ) != 0 ;
}
static T_1 F_369 ( struct V_11 * V_12 , T_9 * V_340 ,
const T_10 * V_418 , int * V_423 )
{
T_1 V_424 ;
int V_81 ;
if ( F_188 ( V_12 ) && * V_423 == 4 ) {
* V_340 &= ~ ( T_9 ) 7 ;
* V_423 = 8 ;
V_81 = F_370 ( V_12 , * V_340 , & V_424 , 8 ) ;
if ( V_81 )
V_424 = 0 ;
V_418 = ( const T_10 * ) & V_424 ;
}
switch ( * V_423 ) {
case 4 :
V_424 = * ( const T_4 * ) V_418 ;
break;
case 8 :
V_424 = * ( const T_1 * ) V_418 ;
break;
default:
V_424 = 0 ;
break;
}
return V_424 ;
}
static bool F_371 ( struct V_48 * V_49 )
{
if ( V_49 -> V_91 . V_41 == V_42 )
return false ;
F_372 ( & V_49 -> V_211 ) ;
return F_373 ( & V_49 -> V_211 ) >= 3 ;
}
static bool F_374 ( struct V_48 * V_49 , T_9 V_340 ,
int V_423 )
{
unsigned V_425 , V_426 , V_427 ;
F_240 ( L_29 ,
V_340 , V_423 , V_49 -> V_91 . V_222 ) ;
V_425 = F_375 ( V_340 ) ;
V_426 = V_49 -> V_91 . V_195 ? 8 : 4 ;
if ( ! ( V_425 & ( V_426 - 1 ) ) && V_423 == 1 )
return false ;
V_427 = ( V_425 ^ ( V_425 + V_423 - 1 ) ) & ~ ( V_426 - 1 ) ;
V_427 |= V_423 < 4 ;
return V_427 ;
}
static T_1 * F_376 ( struct V_48 * V_49 , T_9 V_340 , int * V_428 )
{
unsigned V_429 , V_214 ;
T_1 * V_10 ;
int V_41 ;
V_429 = F_375 ( V_340 ) ;
V_41 = V_49 -> V_91 . V_41 ;
* V_428 = 1 ;
if ( ! V_49 -> V_91 . V_195 ) {
V_429 <<= 1 ;
if ( V_41 == V_219 ) {
V_429 &= ~ 7 ;
V_429 <<= 1 ;
* V_428 = 2 ;
}
V_214 = V_429 >> V_19 ;
V_429 &= ~ V_20 ;
if ( V_214 != V_49 -> V_91 . V_214 )
return NULL ;
}
V_10 = & V_49 -> V_133 [ V_429 / sizeof( * V_10 ) ] ;
return V_10 ;
}
static void F_377 ( struct V_11 * V_12 , T_9 V_340 ,
const T_10 * V_418 , int V_423 ,
struct V_430 * V_431 )
{
T_2 V_15 = V_340 >> V_19 ;
struct V_48 * V_49 ;
F_204 ( V_194 ) ;
T_1 V_432 , V_424 , * V_10 ;
int V_433 ;
bool V_198 , V_199 ;
union V_213 V_4 = { } ;
V_4 . V_408 = 1 ;
V_4 . V_195 = 1 ;
V_4 . V_407 = 1 ;
V_4 . V_359 = 1 ;
V_4 . V_409 = 1 ;
V_4 . V_400 = 1 ;
if ( ! F_33 ( V_12 -> V_106 -> V_36 . V_109 ) )
return;
V_198 = V_199 = false ;
F_240 ( L_30 , V_144 , V_340 , V_423 ) ;
V_424 = F_369 ( V_12 , & V_340 , V_418 , & V_423 ) ;
F_69 ( V_12 ) ;
F_237 ( & V_12 -> V_106 -> V_210 ) ;
++ V_12 -> V_106 -> V_137 . V_434 ;
F_194 ( V_12 , V_435 ) ;
F_199 (vcpu->kvm, sp, gfn) {
if ( F_374 ( V_49 , V_340 , V_423 ) ||
F_371 ( V_49 ) ) {
F_189 ( V_12 -> V_106 , V_49 , & V_194 ) ;
++ V_12 -> V_106 -> V_137 . V_436 ;
continue;
}
V_10 = F_376 ( V_49 , V_340 , & V_433 ) ;
if ( ! V_10 )
continue;
V_199 = true ;
while ( V_433 -- ) {
V_432 = * V_10 ;
F_226 ( V_12 -> V_106 , V_49 , V_10 ) ;
if ( V_424 &&
! ( ( V_49 -> V_91 . V_222 ^ V_12 -> V_36 . V_196 . V_216 . V_222 )
& V_4 . V_222 ) && F_106 ( V_12 ) )
F_367 ( V_12 , V_49 , V_10 , & V_424 ) ;
if ( F_368 ( V_432 , * V_10 ) )
V_198 = true ;
++ V_10 ;
}
}
F_190 ( V_12 , & V_194 , V_198 , V_199 ) ;
F_194 ( V_12 , V_437 ) ;
F_238 ( & V_12 -> V_106 -> V_210 ) ;
}
int F_378 ( struct V_11 * V_12 , T_6 V_182 )
{
T_9 V_340 ;
int V_81 ;
if ( V_12 -> V_36 . V_196 . V_217 )
return 0 ;
V_340 = F_379 ( V_12 , V_182 , NULL ) ;
V_81 = F_239 ( V_12 -> V_106 , V_340 >> V_19 ) ;
return V_81 ;
}
static void F_286 ( struct V_11 * V_12 )
{
F_204 ( V_194 ) ;
if ( F_18 ( F_380 ( V_12 -> V_106 ) >= V_438 ) )
return;
while ( F_380 ( V_12 -> V_106 ) < V_439 ) {
if ( ! F_234 ( V_12 -> V_106 , & V_194 ) )
break;
++ V_12 -> V_106 -> V_137 . V_440 ;
}
F_192 ( V_12 -> V_106 , & V_194 ) ;
}
int F_381 ( struct V_11 * V_12 , T_6 V_441 , T_1 V_287 ,
void * V_442 , int V_443 )
{
int V_81 , V_444 = V_445 ;
enum V_446 V_447 ;
bool V_92 = V_12 -> V_36 . V_196 . V_217 || F_363 ( V_12 ) ;
if ( F_14 ( V_287 & V_288 ) ) {
V_81 = F_306 ( V_12 , V_441 , V_92 ) ;
if ( V_81 == V_325 ) {
V_444 = 0 ;
goto V_256;
}
if ( V_81 == V_328 )
return 1 ;
if ( V_81 < 0 )
return V_81 ;
}
V_81 = V_12 -> V_36 . V_196 . V_342 ( V_12 , V_441 , F_382 ( V_287 ) ,
false ) ;
if ( V_81 < 0 )
return V_81 ;
if ( ! V_81 )
return 1 ;
if ( V_287 == V_448 ) {
F_239 ( V_12 -> V_106 , F_383 ( V_441 ) ) ;
return 1 ;
}
if ( F_302 ( V_12 , V_441 , V_92 ) )
V_444 = 0 ;
V_256:
V_447 = F_384 ( V_12 , V_441 , V_444 , V_442 , V_443 ) ;
switch ( V_447 ) {
case V_449 :
return 1 ;
case V_450 :
++ V_12 -> V_137 . V_451 ;
case V_452 :
return 0 ;
default:
F_102 () ;
}
}
void F_385 ( struct V_11 * V_12 , T_6 V_182 )
{
V_12 -> V_36 . V_196 . V_344 ( V_12 , V_182 ) ;
F_193 ( V_200 , V_12 ) ;
++ V_12 -> V_137 . V_344 ;
}
void F_386 ( void )
{
V_249 = true ;
}
void F_387 ( void )
{
V_249 = false ;
}
static void F_388 ( struct V_11 * V_12 )
{
F_68 ( ( unsigned long ) V_12 -> V_36 . V_196 . V_233 ) ;
if ( V_12 -> V_36 . V_196 . V_305 != NULL )
F_68 ( ( unsigned long ) V_12 -> V_36 . V_196 . V_305 ) ;
}
static int F_389 ( struct V_11 * V_12 )
{
struct V_80 * V_80 ;
int V_102 ;
V_80 = F_390 ( V_77 | V_453 ) ;
if ( ! V_80 )
return - V_78 ;
V_12 -> V_36 . V_196 . V_233 = F_391 ( V_80 ) ;
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 )
V_12 -> V_36 . V_196 . V_233 [ V_102 ] = V_296 ;
return 0 ;
}
int F_392 ( struct V_11 * V_12 )
{
V_12 -> V_36 . V_454 = & V_12 -> V_36 . V_196 ;
V_12 -> V_36 . V_196 . V_229 = V_296 ;
V_12 -> V_36 . V_196 . V_313 = V_313 ;
V_12 -> V_36 . V_312 . V_313 = V_455 ;
return F_389 ( V_12 ) ;
}
void F_393 ( struct V_11 * V_12 )
{
F_162 ( F_261 ( V_12 -> V_36 . V_196 . V_229 ) ) ;
F_362 ( V_12 ) ;
}
static void F_394 ( struct V_106 * V_106 ,
struct V_96 * V_97 ,
struct V_430 * V_431 )
{
F_395 ( V_106 ) ;
}
void F_396 ( struct V_106 * V_106 )
{
struct V_430 * V_431 = & V_106 -> V_36 . V_456 ;
V_431 -> V_457 = F_377 ;
V_431 -> V_458 = F_394 ;
F_397 ( V_106 , V_431 ) ;
}
void F_398 ( struct V_106 * V_106 )
{
struct V_430 * V_431 = & V_106 -> V_36 . V_456 ;
F_399 ( V_106 , V_431 ) ;
}
static bool
F_400 ( struct V_106 * V_106 , struct V_96 * V_159 ,
T_11 V_459 , int V_155 , int V_156 ,
T_2 V_152 , T_2 V_154 , bool V_460 )
{
struct V_150 V_151 ;
bool V_140 = false ;
F_145 (memslot, start_level, end_level, start_gfn,
end_gfn, &iterator) {
if ( V_151 . V_132 )
V_140 |= V_459 ( V_106 , V_151 . V_132 ) ;
if ( F_206 () || F_207 ( & V_106 -> V_210 ) ) {
if ( V_140 && V_460 ) {
F_114 ( V_106 ) ;
V_140 = false ;
}
F_208 ( & V_106 -> V_210 ) ;
}
}
if ( V_140 && V_460 ) {
F_114 ( V_106 ) ;
V_140 = false ;
}
return V_140 ;
}
static bool
F_401 ( struct V_106 * V_106 , struct V_96 * V_159 ,
T_11 V_459 , int V_155 , int V_156 ,
bool V_460 )
{
return F_400 ( V_106 , V_159 , V_459 , V_155 ,
V_156 , V_159 -> V_99 ,
V_159 -> V_99 + V_159 -> V_166 - 1 ,
V_460 ) ;
}
static bool
F_402 ( struct V_106 * V_106 , struct V_96 * V_159 ,
T_11 V_459 , bool V_460 )
{
return F_401 ( V_106 , V_159 , V_459 , V_42 ,
V_104 , V_460 ) ;
}
static bool
F_403 ( struct V_106 * V_106 , struct V_96 * V_159 ,
T_11 V_459 , bool V_460 )
{
return F_401 ( V_106 , V_159 , V_459 , V_42 + 1 ,
V_104 , V_460 ) ;
}
static bool
F_404 ( struct V_106 * V_106 , struct V_96 * V_159 ,
T_11 V_459 , bool V_460 )
{
return F_401 ( V_106 , V_159 , V_459 , V_42 ,
V_42 , V_460 ) ;
}
void F_405 ( struct V_106 * V_106 , T_2 V_163 , T_2 V_164 )
{
struct V_107 * V_108 ;
struct V_96 * V_159 ;
int V_102 ;
F_237 ( & V_106 -> V_210 ) ;
for ( V_102 = 0 ; V_102 < V_160 ; V_102 ++ ) {
V_108 = F_141 ( V_106 , V_102 ) ;
F_142 (memslot, slots) {
T_2 V_157 , V_158 ;
V_157 = F_143 ( V_163 , V_159 -> V_99 ) ;
V_158 = V_73 ( V_164 , V_159 -> V_99 + V_159 -> V_166 ) ;
if ( V_157 >= V_158 )
continue;
F_400 ( V_106 , V_159 , F_128 ,
V_42 , V_104 ,
V_157 , V_158 - 1 , true ) ;
}
}
F_238 ( & V_106 -> V_210 ) ;
}
static bool F_406 ( struct V_106 * V_106 ,
struct V_122 * V_123 )
{
return F_116 ( V_106 , V_123 , false ) ;
}
void F_407 ( struct V_106 * V_106 ,
struct V_96 * V_159 )
{
bool V_140 ;
F_237 ( & V_106 -> V_210 ) ;
V_140 = F_402 ( V_106 , V_159 , F_406 ,
false ) ;
F_238 ( & V_106 -> V_210 ) ;
F_408 ( & V_106 -> V_461 ) ;
if ( V_140 )
F_114 ( V_106 ) ;
}
static bool F_409 ( struct V_106 * V_106 ,
struct V_122 * V_123 )
{
T_1 * V_14 ;
struct V_134 V_135 ;
int V_462 = 0 ;
T_3 V_21 ;
struct V_48 * V_49 ;
V_149:
F_117 (rmap_head, &iter, sptep) {
V_49 = F_35 ( F_36 ( V_14 ) ) ;
V_21 = F_25 ( * V_14 ) ;
if ( V_49 -> V_91 . V_92 &&
! F_48 ( V_21 ) &&
F_270 ( F_50 ( V_21 ) ) ) {
F_111 ( V_106 , V_14 ) ;
V_462 = 1 ;
goto V_149;
}
}
return V_462 ;
}
void F_410 ( struct V_106 * V_106 ,
const struct V_96 * V_159 )
{
F_237 ( & V_106 -> V_210 ) ;
F_404 ( V_106 , (struct V_96 * ) V_159 ,
F_409 , true ) ;
F_238 ( & V_106 -> V_210 ) ;
}
void F_411 ( struct V_106 * V_106 ,
struct V_96 * V_159 )
{
bool V_140 ;
F_237 ( & V_106 -> V_210 ) ;
V_140 = F_404 ( V_106 , V_159 , F_119 , false ) ;
F_238 ( & V_106 -> V_210 ) ;
F_408 ( & V_106 -> V_461 ) ;
if ( V_140 )
F_114 ( V_106 ) ;
}
void F_412 ( struct V_106 * V_106 ,
struct V_96 * V_159 )
{
bool V_140 ;
F_237 ( & V_106 -> V_210 ) ;
V_140 = F_403 ( V_106 , V_159 , F_406 ,
false ) ;
F_238 ( & V_106 -> V_210 ) ;
F_408 ( & V_106 -> V_461 ) ;
if ( V_140 )
F_114 ( V_106 ) ;
}
void F_413 ( struct V_106 * V_106 ,
struct V_96 * V_159 )
{
bool V_140 ;
F_237 ( & V_106 -> V_210 ) ;
V_140 = F_402 ( V_106 , V_159 , F_121 , false ) ;
F_238 ( & V_106 -> V_210 ) ;
F_408 ( & V_106 -> V_461 ) ;
if ( V_140 )
F_114 ( V_106 ) ;
}
static void F_414 ( struct V_106 * V_106 )
{
struct V_48 * V_49 , * V_431 ;
int V_463 = 0 ;
V_149:
F_415 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_64 ;
if ( ! F_196 ( V_106 , V_49 ) )
break;
if ( V_49 -> V_91 . V_239 )
continue;
if ( V_463 >= V_464 &&
F_208 ( & V_106 -> V_210 ) ) {
V_463 = 0 ;
goto V_149;
}
V_64 = F_189 ( V_106 , V_49 ,
& V_106 -> V_36 . V_465 ) ;
V_463 += V_64 ;
if ( V_64 )
goto V_149;
}
F_192 ( V_106 , & V_106 -> V_36 . V_465 ) ;
}
void F_395 ( struct V_106 * V_106 )
{
F_237 ( & V_106 -> V_210 ) ;
F_416 ( V_106 ) ;
V_106 -> V_36 . V_202 ++ ;
F_232 ( V_106 ) ;
F_414 ( V_106 ) ;
F_238 ( & V_106 -> V_210 ) ;
}
static bool F_417 ( struct V_106 * V_106 )
{
return F_14 ( ! F_418 ( & V_106 -> V_36 . V_465 ) ) ;
}
void F_419 ( struct V_106 * V_106 , struct V_107 * V_108 )
{
if ( F_14 ( ( V_108 -> V_13 & V_5 ) == 0 ) ) {
F_420 ( L_31 ) ;
F_395 ( V_106 ) ;
}
}
static unsigned long
F_421 ( struct V_466 * V_467 , struct V_468 * V_469 )
{
struct V_106 * V_106 ;
int V_470 = V_469 -> V_470 ;
unsigned long V_471 = 0 ;
F_237 ( & V_472 ) ;
F_422 (kvm, &vm_list, vm_list) {
int V_98 ;
F_204 ( V_194 ) ;
if ( ! V_470 -- )
break;
if ( ! V_106 -> V_36 . V_172 &&
! F_417 ( V_106 ) )
continue;
V_98 = F_423 ( & V_106 -> V_473 ) ;
F_237 ( & V_106 -> V_210 ) ;
if ( F_417 ( V_106 ) ) {
F_192 ( V_106 ,
& V_106 -> V_36 . V_465 ) ;
goto V_474;
}
if ( F_234 ( V_106 , & V_194 ) )
V_471 ++ ;
F_192 ( V_106 , & V_194 ) ;
V_474:
F_238 ( & V_106 -> V_210 ) ;
F_424 ( & V_106 -> V_473 , V_98 ) ;
F_425 ( & V_106 -> V_475 , & V_475 ) ;
break;
}
F_238 ( & V_472 ) ;
return V_471 ;
}
static unsigned long
F_426 ( struct V_466 * V_467 , struct V_468 * V_469 )
{
return F_427 ( & V_173 ) ;
}
static void F_428 ( void )
{
if ( V_83 )
F_429 ( V_83 ) ;
if ( V_87 )
F_429 ( V_87 ) ;
}
int F_430 ( void )
{
V_83 = F_431 ( L_32 ,
sizeof( struct V_89 ) ,
0 , 0 , NULL ) ;
if ( ! V_83 )
goto V_476;
V_87 = F_431 ( L_33 ,
sizeof( struct V_48 ) ,
0 , 0 , NULL ) ;
if ( ! V_87 )
goto V_476;
if ( F_432 ( & V_173 , 0 , V_77 ) )
goto V_476;
F_433 ( & V_477 ) ;
return 0 ;
V_476:
F_428 () ;
return - V_78 ;
}
unsigned int F_434 ( struct V_106 * V_106 )
{
unsigned int V_478 ;
unsigned int V_479 = 0 ;
struct V_107 * V_108 ;
struct V_96 * V_159 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_160 ; V_102 ++ ) {
V_108 = F_141 ( V_106 , V_102 ) ;
F_142 (memslot, slots)
V_479 += V_159 -> V_166 ;
}
V_478 = V_479 * V_480 / 1000 ;
V_478 = F_143 ( V_478 ,
( unsigned int ) V_481 ) ;
return V_478 ;
}
void F_435 ( struct V_11 * V_12 )
{
F_365 ( V_12 ) ;
F_388 ( V_12 ) ;
F_70 ( V_12 ) ;
}
void F_436 ( void )
{
F_428 () ;
F_437 ( & V_173 ) ;
F_438 ( & V_477 ) ;
F_195 () ;
}
