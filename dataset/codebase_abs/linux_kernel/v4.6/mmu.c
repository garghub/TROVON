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
T_1 V_26 , T_1 V_27 , T_1 V_28 )
{
V_29 = V_24 ;
V_30 = V_25 ;
V_31 = V_26 ;
V_32 = V_27 ;
V_33 = V_28 ;
}
static int F_20 ( void )
{
return 1 ;
}
static int F_21 ( struct V_11 * V_12 )
{
return V_12 -> V_34 . V_35 & V_36 ;
}
static int F_22 ( T_1 V_37 )
{
return V_37 & V_38 && ! F_10 ( V_37 ) ;
}
static int F_23 ( T_1 V_37 )
{
return V_37 & V_39 ;
}
static int F_24 ( T_1 V_37 , int V_40 )
{
if ( V_40 == V_41 )
return 1 ;
if ( F_23 ( V_37 ) )
return 1 ;
return 0 ;
}
static T_3 F_25 ( T_1 V_37 )
{
return ( V_37 & V_42 ) >> V_19 ;
}
static T_2 F_26 ( T_4 V_43 )
{
int V_44 = 32 - V_45 - V_19 ;
return ( V_43 & V_46 ) << V_44 ;
}
static void F_27 ( T_1 * V_14 , T_1 V_10 )
{
* V_14 = V_10 ;
}
static void F_28 ( T_1 * V_14 , T_1 V_10 )
{
* V_14 = V_10 ;
}
static T_1 F_29 ( T_1 * V_14 , T_1 V_10 )
{
return F_30 ( V_14 , V_10 ) ;
}
static T_1 F_31 ( T_1 * V_14 )
{
return F_32 ( * V_14 ) ;
}
static void F_33 ( T_1 * V_14 , T_1 V_10 )
{
struct V_47 * V_48 = F_34 ( F_35 ( V_14 ) ) ;
if ( F_22 ( V_10 ) )
return;
F_36 () ;
V_48 -> V_49 ++ ;
}
static void F_27 ( T_1 * V_14 , T_1 V_10 )
{
union V_50 * V_51 , V_52 ;
V_51 = (union V_50 * ) V_14 ;
V_52 = (union V_50 ) V_10 ;
V_51 -> V_53 = V_52 . V_53 ;
F_36 () ;
V_51 -> V_54 = V_52 . V_54 ;
}
static void F_28 ( T_1 * V_14 , T_1 V_10 )
{
union V_50 * V_51 , V_52 ;
V_51 = (union V_50 * ) V_14 ;
V_52 = (union V_50 ) V_10 ;
V_51 -> V_54 = V_52 . V_54 ;
F_36 () ;
V_51 -> V_53 = V_52 . V_53 ;
F_33 ( V_14 , V_10 ) ;
}
static T_1 F_29 ( T_1 * V_14 , T_1 V_10 )
{
union V_50 * V_51 , V_52 , V_55 ;
V_51 = (union V_50 * ) V_14 ;
V_52 = (union V_50 ) V_10 ;
V_55 . V_54 = F_30 ( & V_51 -> V_54 , V_52 . V_54 ) ;
V_55 . V_53 = V_51 -> V_53 ;
V_51 -> V_53 = V_52 . V_53 ;
F_33 ( V_14 , V_10 ) ;
return V_55 . V_10 ;
}
static T_1 F_31 ( T_1 * V_14 )
{
struct V_47 * V_48 = F_34 ( F_35 ( V_14 ) ) ;
union V_50 V_10 , * V_55 = (union V_50 * ) V_14 ;
int V_56 ;
V_57:
V_56 = V_48 -> V_49 ;
F_37 () ;
V_10 . V_54 = V_55 -> V_54 ;
F_37 () ;
V_10 . V_53 = V_55 -> V_53 ;
F_37 () ;
if ( F_14 ( V_10 . V_54 != V_55 -> V_54 ||
V_56 != V_48 -> V_49 ) )
goto V_57;
return V_10 . V_10 ;
}
static bool F_38 ( T_1 V_10 )
{
return ( V_10 & ( V_58 | V_59 ) ) ==
( V_58 | V_59 ) ;
}
static bool F_39 ( T_1 V_10 )
{
if ( F_38 ( V_10 ) )
return true ;
if ( ! V_30 )
return false ;
if ( ! F_22 ( V_10 ) )
return false ;
if ( ( V_10 & V_30 ) &&
( ! F_40 ( V_10 ) || ( V_10 & V_31 ) ) )
return false ;
return true ;
}
static bool F_41 ( T_1 V_60 , T_1 V_61 , T_1 V_62 )
{
return ( V_60 & V_62 ) && ! ( V_61 & V_62 ) ;
}
static bool F_42 ( T_1 V_60 , T_1 V_61 , T_1 V_62 )
{
return ( V_60 & V_62 ) != ( V_61 & V_62 ) ;
}
static void F_9 ( T_1 * V_14 , T_1 V_61 )
{
F_3 ( F_22 ( * V_14 ) ) ;
F_27 ( V_14 , V_61 ) ;
}
static bool F_43 ( T_1 * V_14 , T_1 V_61 )
{
T_1 V_60 = * V_14 ;
bool V_63 = false ;
F_3 ( ! F_22 ( V_61 ) ) ;
if ( ! F_22 ( V_60 ) ) {
F_9 ( V_14 , V_61 ) ;
return V_63 ;
}
if ( ! F_39 ( V_60 ) )
F_28 ( V_14 , V_61 ) ;
else
V_60 = F_29 ( V_14 , V_61 ) ;
if ( F_38 ( V_60 ) &&
! F_40 ( V_61 ) )
V_63 = true ;
if ( ! V_30 ) {
if ( V_63 )
F_44 ( F_25 ( V_60 ) ) ;
return V_63 ;
}
if ( F_42 ( V_60 , V_61 ,
V_30 | V_31 ) )
V_63 = true ;
if ( F_41 ( V_60 , V_61 , V_30 ) )
F_45 ( F_25 ( V_60 ) ) ;
if ( F_41 ( V_60 , V_61 , V_31 ) )
F_44 ( F_25 ( V_60 ) ) ;
return V_63 ;
}
static int F_46 ( T_1 * V_14 )
{
T_3 V_21 ;
T_1 V_60 = * V_14 ;
if ( ! F_39 ( V_60 ) )
F_28 ( V_14 , 0ull ) ;
else
V_60 = F_29 ( V_14 , 0ull ) ;
if ( ! F_22 ( V_60 ) )
return 0 ;
V_21 = F_25 ( V_60 ) ;
F_3 ( ! F_47 ( V_21 ) && ! F_48 ( F_49 ( V_21 ) ) ) ;
if ( ! V_30 || V_60 & V_30 )
F_45 ( V_21 ) ;
if ( V_60 & ( V_31 ? V_31 :
V_64 ) )
F_44 ( V_21 ) ;
return 1 ;
}
static void F_50 ( T_1 * V_14 )
{
F_28 ( V_14 , 0ull ) ;
}
static T_1 F_51 ( T_1 * V_14 )
{
return F_31 ( V_14 ) ;
}
static void F_52 ( struct V_11 * V_12 )
{
F_53 () ;
F_54 ( V_12 -> V_65 , V_66 ) ;
}
static void F_55 ( struct V_11 * V_12 )
{
F_56 ( & V_12 -> V_65 , V_67 ) ;
F_57 () ;
}
static int F_58 ( struct V_68 * V_69 ,
struct V_70 * V_71 , int V_72 )
{
void * V_73 ;
if ( V_69 -> V_74 >= V_72 )
return 0 ;
while ( V_69 -> V_74 < F_59 ( V_69 -> V_75 ) ) {
V_73 = F_60 ( V_71 , V_76 ) ;
if ( ! V_73 )
return - V_77 ;
V_69 -> V_75 [ V_69 -> V_74 ++ ] = V_73 ;
}
return 0 ;
}
static int F_61 ( struct V_68 * V_69 )
{
return V_69 -> V_74 ;
}
static void F_62 ( struct V_68 * V_78 ,
struct V_70 * V_69 )
{
while ( V_78 -> V_74 )
F_63 ( V_69 , V_78 -> V_75 [ -- V_78 -> V_74 ] ) ;
}
static int F_64 ( struct V_68 * V_69 ,
int V_72 )
{
void * V_79 ;
if ( V_69 -> V_74 >= V_72 )
return 0 ;
while ( V_69 -> V_74 < F_59 ( V_69 -> V_75 ) ) {
V_79 = ( void * ) F_65 ( V_76 ) ;
if ( ! V_79 )
return - V_77 ;
V_69 -> V_75 [ V_69 -> V_74 ++ ] = V_79 ;
}
return 0 ;
}
static void F_66 ( struct V_68 * V_78 )
{
while ( V_78 -> V_74 )
F_67 ( ( unsigned long ) V_78 -> V_75 [ -- V_78 -> V_74 ] ) ;
}
static int F_68 ( struct V_11 * V_12 )
{
int V_80 ;
V_80 = F_58 ( & V_12 -> V_34 . V_81 ,
V_82 , 8 + V_83 ) ;
if ( V_80 )
goto V_84;
V_80 = F_64 ( & V_12 -> V_34 . V_85 , 8 ) ;
if ( V_80 )
goto V_84;
V_80 = F_58 ( & V_12 -> V_34 . V_86 ,
V_86 , 4 ) ;
V_84:
return V_80 ;
}
static void F_69 ( struct V_11 * V_12 )
{
F_62 ( & V_12 -> V_34 . V_81 ,
V_82 ) ;
F_66 ( & V_12 -> V_34 . V_85 ) ;
F_62 ( & V_12 -> V_34 . V_86 ,
V_86 ) ;
}
static void * F_70 ( struct V_68 * V_78 )
{
void * V_87 ;
F_71 ( ! V_78 -> V_74 ) ;
V_87 = V_78 -> V_75 [ -- V_78 -> V_74 ] ;
return V_87 ;
}
static struct V_88 * F_72 ( struct V_11 * V_12 )
{
return F_70 ( & V_12 -> V_34 . V_81 ) ;
}
static void F_73 ( struct V_88 * V_88 )
{
F_63 ( V_82 , V_88 ) ;
}
static T_2 F_74 ( struct V_47 * V_48 , int V_89 )
{
if ( ! V_48 -> V_90 . V_91 )
return V_48 -> V_92 [ V_89 ] ;
return V_48 -> V_15 + ( V_89 << ( ( V_48 -> V_90 . V_40 - 1 ) * V_93 ) ) ;
}
static void F_75 ( struct V_47 * V_48 , int V_89 , T_2 V_15 )
{
if ( V_48 -> V_90 . V_91 )
F_71 ( V_15 != F_74 ( V_48 , V_89 ) ) ;
else
V_48 -> V_92 [ V_89 ] = V_15 ;
}
static struct V_94 * F_76 ( T_2 V_15 ,
struct V_95 * V_96 ,
int V_40 )
{
unsigned long V_97 ;
V_97 = F_77 ( V_15 , V_96 -> V_98 , V_40 ) ;
return & V_96 -> V_34 . V_99 [ V_40 - 2 ] [ V_97 ] ;
}
static void F_78 ( struct V_95 * V_96 ,
T_2 V_15 , int V_56 )
{
struct V_94 * V_100 ;
int V_101 ;
for ( V_101 = V_102 ; V_101 <= V_103 ; ++ V_101 ) {
V_100 = F_76 ( V_15 , V_96 , V_101 ) ;
V_100 -> V_104 += V_56 ;
F_3 ( V_100 -> V_104 < 0 ) ;
}
}
void F_79 ( struct V_95 * V_96 , T_2 V_15 )
{
F_78 ( V_96 , V_15 , 1 ) ;
}
void F_80 ( struct V_95 * V_96 , T_2 V_15 )
{
F_78 ( V_96 , V_15 , - 1 ) ;
}
static void F_81 ( struct V_105 * V_105 , struct V_47 * V_48 )
{
struct V_106 * V_107 ;
struct V_95 * V_96 ;
T_2 V_15 ;
V_105 -> V_34 . V_108 ++ ;
V_15 = V_48 -> V_15 ;
V_107 = F_82 ( V_105 , V_48 -> V_90 ) ;
V_96 = F_83 ( V_107 , V_15 ) ;
if ( V_48 -> V_90 . V_40 > V_41 )
return F_84 ( V_105 , V_96 , V_15 ,
V_109 ) ;
F_79 ( V_96 , V_15 ) ;
}
static void F_85 ( struct V_105 * V_105 , struct V_47 * V_48 )
{
struct V_106 * V_107 ;
struct V_95 * V_96 ;
T_2 V_15 ;
V_105 -> V_34 . V_108 -- ;
V_15 = V_48 -> V_15 ;
V_107 = F_82 ( V_105 , V_48 -> V_90 ) ;
V_96 = F_83 ( V_107 , V_15 ) ;
if ( V_48 -> V_90 . V_40 > V_41 )
return F_86 ( V_105 , V_96 , V_15 ,
V_109 ) ;
F_80 ( V_96 , V_15 ) ;
}
static bool F_87 ( T_2 V_15 , int V_40 ,
struct V_95 * V_96 )
{
struct V_94 * V_100 ;
if ( V_96 ) {
V_100 = F_76 ( V_15 , V_96 , V_40 ) ;
return ! ! V_100 -> V_104 ;
}
return true ;
}
static bool F_88 ( struct V_11 * V_12 , T_2 V_15 ,
int V_40 )
{
struct V_95 * V_96 ;
V_96 = F_89 ( V_12 , V_15 ) ;
return F_87 ( V_15 , V_40 , V_96 ) ;
}
static int F_90 ( struct V_105 * V_105 , T_2 V_15 )
{
unsigned long V_110 ;
int V_101 , V_63 = 0 ;
V_110 = F_91 ( V_105 , V_15 ) ;
for ( V_101 = V_41 ; V_101 <= V_103 ; ++ V_101 ) {
if ( V_110 >= F_92 ( V_101 ) )
V_63 = V_101 ;
else
break;
}
return V_63 ;
}
static inline bool F_93 ( struct V_95 * V_96 ,
bool V_111 )
{
if ( ! V_96 || V_96 -> V_112 & V_113 )
return false ;
if ( V_111 && V_96 -> V_114 )
return false ;
return true ;
}
static struct V_95 *
F_94 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_111 )
{
struct V_95 * V_96 ;
V_96 = F_89 ( V_12 , V_15 ) ;
if ( ! F_93 ( V_96 , V_111 ) )
V_96 = NULL ;
return V_96 ;
}
static int F_95 ( struct V_11 * V_12 , T_2 V_115 ,
bool * V_116 )
{
int V_117 , V_40 , V_118 ;
struct V_95 * V_96 ;
if ( F_14 ( * V_116 ) )
return V_41 ;
V_96 = F_89 ( V_12 , V_115 ) ;
* V_116 = ! F_93 ( V_96 , true ) ;
if ( F_14 ( * V_116 ) )
return V_41 ;
V_117 = F_90 ( V_12 -> V_105 , V_115 ) ;
if ( V_117 == V_41 )
return V_117 ;
V_118 = V_72 ( V_119 -> V_120 () , V_117 ) ;
for ( V_40 = V_102 ; V_40 <= V_118 ; ++ V_40 )
if ( F_87 ( V_115 , V_40 , V_96 ) )
break;
return V_40 - 1 ;
}
static int F_96 ( struct V_11 * V_12 , T_1 * V_10 ,
struct V_121 * V_122 )
{
struct V_88 * V_123 ;
int V_101 , V_56 = 0 ;
if ( ! V_122 -> V_124 ) {
F_97 ( L_1 , V_10 , * V_10 ) ;
V_122 -> V_124 = ( unsigned long ) V_10 ;
} else if ( ! ( V_122 -> V_124 & 1 ) ) {
F_97 ( L_2 , V_10 , * V_10 ) ;
V_123 = F_72 ( V_12 ) ;
V_123 -> V_125 [ 0 ] = ( T_1 * ) V_122 -> V_124 ;
V_123 -> V_125 [ 1 ] = V_10 ;
V_122 -> V_124 = ( unsigned long ) V_123 | 1 ;
++ V_56 ;
} else {
F_97 ( L_3 , V_10 , * V_10 ) ;
V_123 = (struct V_88 * ) ( V_122 -> V_124 & ~ 1ul ) ;
while ( V_123 -> V_125 [ V_126 - 1 ] && V_123 -> V_127 ) {
V_123 = V_123 -> V_127 ;
V_56 += V_126 ;
}
if ( V_123 -> V_125 [ V_126 - 1 ] ) {
V_123 -> V_127 = F_72 ( V_12 ) ;
V_123 = V_123 -> V_127 ;
}
for ( V_101 = 0 ; V_123 -> V_125 [ V_101 ] ; ++ V_101 )
++ V_56 ;
V_123 -> V_125 [ V_101 ] = V_10 ;
}
return V_56 ;
}
static void
F_98 ( struct V_121 * V_122 ,
struct V_88 * V_123 , int V_101 ,
struct V_88 * V_128 )
{
int V_129 ;
for ( V_129 = V_126 - 1 ; ! V_123 -> V_125 [ V_129 ] && V_129 > V_101 ; -- V_129 )
;
V_123 -> V_125 [ V_101 ] = V_123 -> V_125 [ V_129 ] ;
V_123 -> V_125 [ V_129 ] = NULL ;
if ( V_129 != 0 )
return;
if ( ! V_128 && ! V_123 -> V_127 )
V_122 -> V_124 = ( unsigned long ) V_123 -> V_125 [ 0 ] ;
else
if ( V_128 )
V_128 -> V_127 = V_123 -> V_127 ;
else
V_122 -> V_124 = ( unsigned long ) V_123 -> V_127 | 1 ;
F_73 ( V_123 ) ;
}
static void F_99 ( T_1 * V_10 , struct V_121 * V_122 )
{
struct V_88 * V_123 ;
struct V_88 * V_128 ;
int V_101 ;
if ( ! V_122 -> V_124 ) {
F_100 ( V_130 L_4 , V_10 ) ;
F_101 () ;
} else if ( ! ( V_122 -> V_124 & 1 ) ) {
F_97 ( L_5 , V_10 ) ;
if ( ( T_1 * ) V_122 -> V_124 != V_10 ) {
F_100 ( V_130 L_6 , V_10 ) ;
F_101 () ;
}
V_122 -> V_124 = 0 ;
} else {
F_97 ( L_7 , V_10 ) ;
V_123 = (struct V_88 * ) ( V_122 -> V_124 & ~ 1ul ) ;
V_128 = NULL ;
while ( V_123 ) {
for ( V_101 = 0 ; V_101 < V_126 && V_123 -> V_125 [ V_101 ] ; ++ V_101 ) {
if ( V_123 -> V_125 [ V_101 ] == V_10 ) {
F_98 ( V_122 ,
V_123 , V_101 , V_128 ) ;
return;
}
}
V_128 = V_123 ;
V_123 = V_123 -> V_127 ;
}
F_102 ( L_8 , V_10 ) ;
F_101 () ;
}
}
static struct V_121 * F_103 ( T_2 V_15 , int V_40 ,
struct V_95 * V_96 )
{
unsigned long V_97 ;
V_97 = F_77 ( V_15 , V_96 -> V_98 , V_40 ) ;
return & V_96 -> V_34 . V_131 [ V_40 - V_41 ] [ V_97 ] ;
}
static struct V_121 * F_104 ( struct V_105 * V_105 , T_2 V_15 ,
struct V_47 * V_48 )
{
struct V_106 * V_107 ;
struct V_95 * V_96 ;
V_107 = F_82 ( V_105 , V_48 -> V_90 ) ;
V_96 = F_83 ( V_107 , V_15 ) ;
return F_103 ( V_15 , V_48 -> V_90 . V_40 , V_96 ) ;
}
static bool F_105 ( struct V_11 * V_12 )
{
struct V_68 * V_69 ;
V_69 = & V_12 -> V_34 . V_81 ;
return F_61 ( V_69 ) ;
}
static int F_106 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
struct V_47 * V_48 ;
struct V_121 * V_122 ;
V_48 = F_34 ( F_35 ( V_10 ) ) ;
F_75 ( V_48 , V_10 - V_48 -> V_132 , V_15 ) ;
V_122 = F_104 ( V_12 -> V_105 , V_15 , V_48 ) ;
return F_96 ( V_12 , V_10 , V_122 ) ;
}
static void F_107 ( struct V_105 * V_105 , T_1 * V_10 )
{
struct V_47 * V_48 ;
T_2 V_15 ;
struct V_121 * V_122 ;
V_48 = F_34 ( F_35 ( V_10 ) ) ;
V_15 = F_74 ( V_48 , V_10 - V_48 -> V_132 ) ;
V_122 = F_104 ( V_105 , V_15 , V_48 ) ;
F_99 ( V_10 , V_122 ) ;
}
static T_1 * F_108 ( struct V_121 * V_122 ,
struct V_133 * V_134 )
{
T_1 * V_14 ;
if ( ! V_122 -> V_124 )
return NULL ;
if ( ! ( V_122 -> V_124 & 1 ) ) {
V_134 -> V_123 = NULL ;
V_14 = ( T_1 * ) V_122 -> V_124 ;
goto V_84;
}
V_134 -> V_123 = (struct V_88 * ) ( V_122 -> V_124 & ~ 1ul ) ;
V_134 -> V_135 = 0 ;
V_14 = V_134 -> V_123 -> V_125 [ V_134 -> V_135 ] ;
V_84:
F_71 ( ! F_22 ( * V_14 ) ) ;
return V_14 ;
}
static T_1 * F_109 ( struct V_133 * V_134 )
{
T_1 * V_14 ;
if ( V_134 -> V_123 ) {
if ( V_134 -> V_135 < V_126 - 1 ) {
++ V_134 -> V_135 ;
V_14 = V_134 -> V_123 -> V_125 [ V_134 -> V_135 ] ;
if ( V_14 )
goto V_84;
}
V_134 -> V_123 = V_134 -> V_123 -> V_127 ;
if ( V_134 -> V_123 ) {
V_134 -> V_135 = 0 ;
V_14 = V_134 -> V_123 -> V_125 [ V_134 -> V_135 ] ;
goto V_84;
}
}
return NULL ;
V_84:
F_71 ( ! F_22 ( * V_14 ) ) ;
return V_14 ;
}
static void F_110 ( struct V_105 * V_105 , T_1 * V_14 )
{
if ( F_46 ( V_14 ) )
F_107 ( V_105 , V_14 ) ;
}
static bool F_111 ( struct V_105 * V_105 , T_1 * V_14 )
{
if ( F_23 ( * V_14 ) ) {
F_3 ( F_34 ( F_35 ( V_14 ) ) -> V_90 . V_40 ==
V_41 ) ;
F_110 ( V_105 , V_14 ) ;
-- V_105 -> V_136 . V_137 ;
return true ;
}
return false ;
}
static void F_112 ( struct V_11 * V_12 , T_1 * V_14 )
{
if ( F_111 ( V_12 -> V_105 , V_14 ) )
F_113 ( V_12 -> V_105 ) ;
}
static bool F_114 ( struct V_105 * V_105 , T_1 * V_14 , bool V_138 )
{
T_1 V_10 = * V_14 ;
if ( ! F_40 ( V_10 ) &&
! ( V_138 && F_38 ( V_10 ) ) )
return false ;
F_97 ( L_9 , V_14 , * V_14 ) ;
if ( V_138 )
V_10 &= ~ V_59 ;
V_10 = V_10 & ~ V_64 ;
return F_43 ( V_14 , V_10 ) ;
}
static bool F_115 ( struct V_105 * V_105 ,
struct V_121 * V_122 ,
bool V_138 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
bool V_139 = false ;
F_116 (rmap_head, &iter, sptep)
V_139 |= F_114 ( V_105 , V_14 , V_138 ) ;
return V_139 ;
}
static bool F_117 ( struct V_105 * V_105 , T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_97 ( L_10 , V_14 , * V_14 ) ;
V_10 &= ~ V_31 ;
return F_43 ( V_14 , V_10 ) ;
}
static bool F_118 ( struct V_105 * V_105 , struct V_121 * V_122 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
bool V_139 = false ;
F_116 (rmap_head, &iter, sptep)
V_139 |= F_117 ( V_105 , V_14 ) ;
return V_139 ;
}
static bool F_119 ( struct V_105 * V_105 , T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_97 ( L_11 , V_14 , * V_14 ) ;
V_10 |= V_31 ;
return F_43 ( V_14 , V_10 ) ;
}
static bool F_120 ( struct V_105 * V_105 , struct V_121 * V_122 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
bool V_139 = false ;
F_116 (rmap_head, &iter, sptep)
V_139 |= F_119 ( V_105 , V_14 ) ;
return V_139 ;
}
static void F_121 ( struct V_105 * V_105 ,
struct V_95 * V_96 ,
T_2 V_140 , unsigned long V_4 )
{
struct V_121 * V_122 ;
while ( V_4 ) {
V_122 = F_103 ( V_96 -> V_98 + V_140 + F_122 ( V_4 ) ,
V_41 , V_96 ) ;
F_115 ( V_105 , V_122 , false ) ;
V_4 &= V_4 - 1 ;
}
}
void F_123 ( struct V_105 * V_105 ,
struct V_95 * V_96 ,
T_2 V_140 , unsigned long V_4 )
{
struct V_121 * V_122 ;
while ( V_4 ) {
V_122 = F_103 ( V_96 -> V_98 + V_140 + F_122 ( V_4 ) ,
V_41 , V_96 ) ;
F_118 ( V_105 , V_122 ) ;
V_4 &= V_4 - 1 ;
}
}
void F_124 ( struct V_105 * V_105 ,
struct V_95 * V_96 ,
T_2 V_140 , unsigned long V_4 )
{
if ( V_119 -> V_141 )
V_119 -> V_141 ( V_105 , V_96 , V_140 ,
V_4 ) ;
else
F_121 ( V_105 , V_96 , V_140 , V_4 ) ;
}
bool F_125 ( struct V_105 * V_105 ,
struct V_95 * V_96 , T_1 V_15 )
{
struct V_121 * V_122 ;
int V_101 ;
bool V_142 = false ;
for ( V_101 = V_41 ; V_101 <= V_103 ; ++ V_101 ) {
V_122 = F_103 ( V_15 , V_101 , V_96 ) ;
V_142 |= F_115 ( V_105 , V_122 , true ) ;
}
return V_142 ;
}
static bool F_126 ( struct V_11 * V_12 , T_1 V_15 )
{
struct V_95 * V_96 ;
V_96 = F_89 ( V_12 , V_15 ) ;
return F_125 ( V_12 -> V_105 , V_96 , V_15 ) ;
}
static bool F_127 ( struct V_105 * V_105 , struct V_121 * V_122 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
bool V_139 = false ;
while ( ( V_14 = F_108 ( V_122 , & V_134 ) ) ) {
F_97 ( L_12 , V_143 , V_14 , * V_14 ) ;
F_110 ( V_105 , V_14 ) ;
V_139 = true ;
}
return V_139 ;
}
static int F_128 ( struct V_105 * V_105 , struct V_121 * V_122 ,
struct V_95 * V_96 , T_2 V_15 , int V_40 ,
unsigned long V_144 )
{
return F_127 ( V_105 , V_122 ) ;
}
static int F_129 ( struct V_105 * V_105 , struct V_121 * V_122 ,
struct V_95 * V_96 , T_2 V_15 , int V_40 ,
unsigned long V_144 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
int V_145 = 0 ;
T_1 V_61 ;
T_5 * V_146 = ( T_5 * ) V_144 ;
T_3 V_147 ;
F_3 ( F_130 ( * V_146 ) ) ;
V_147 = F_131 ( * V_146 ) ;
V_148:
F_116 (rmap_head, &iter, sptep) {
F_97 ( L_13 ,
V_14 , * V_14 , V_15 , V_40 ) ;
V_145 = 1 ;
if ( F_132 ( * V_146 ) ) {
F_110 ( V_105 , V_14 ) ;
goto V_148;
} else {
V_61 = * V_14 & ~ V_42 ;
V_61 |= ( T_1 ) V_147 << V_19 ;
V_61 &= ~ V_64 ;
V_61 &= ~ V_58 ;
V_61 &= ~ V_30 ;
F_46 ( V_14 ) ;
F_9 ( V_14 , V_61 ) ;
}
}
if ( V_145 )
F_113 ( V_105 ) ;
return 0 ;
}
static void
F_133 ( struct V_149 * V_150 , int V_40 )
{
V_150 -> V_40 = V_40 ;
V_150 -> V_15 = V_150 -> V_151 ;
V_150 -> V_131 = F_103 ( V_150 -> V_15 , V_40 , V_150 -> V_96 ) ;
V_150 -> V_152 = F_103 ( V_150 -> V_153 , V_40 ,
V_150 -> V_96 ) ;
}
static void
F_134 ( struct V_149 * V_150 ,
struct V_95 * V_96 , int V_154 ,
int V_155 , T_2 V_151 , T_2 V_153 )
{
V_150 -> V_96 = V_96 ;
V_150 -> V_154 = V_154 ;
V_150 -> V_155 = V_155 ;
V_150 -> V_151 = V_151 ;
V_150 -> V_153 = V_153 ;
F_133 ( V_150 , V_150 -> V_154 ) ;
}
static bool F_135 ( struct V_149 * V_150 )
{
return ! ! V_150 -> V_131 ;
}
static void F_136 ( struct V_149 * V_150 )
{
if ( ++ V_150 -> V_131 <= V_150 -> V_152 ) {
V_150 -> V_15 += ( 1UL << F_137 ( V_150 -> V_40 ) ) ;
return;
}
if ( ++ V_150 -> V_40 > V_150 -> V_155 ) {
V_150 -> V_131 = NULL ;
return;
}
F_133 ( V_150 , V_150 -> V_40 ) ;
}
static int F_138 ( struct V_105 * V_105 ,
unsigned long V_156 ,
unsigned long V_157 ,
unsigned long V_144 ,
int (* F_139)( struct V_105 * V_105 ,
struct V_121 * V_122 ,
struct V_95 * V_96 ,
T_2 V_15 ,
int V_40 ,
unsigned long V_144 ) )
{
struct V_106 * V_107 ;
struct V_95 * V_158 ;
struct V_149 V_150 ;
int V_63 = 0 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_159 ; V_101 ++ ) {
V_107 = F_140 ( V_105 , V_101 ) ;
F_141 (memslot, slots) {
unsigned long V_160 , V_161 ;
T_2 V_162 , V_163 ;
V_160 = F_142 ( V_156 , V_158 -> V_164 ) ;
V_161 = V_72 ( V_157 , V_158 -> V_164 +
( V_158 -> V_165 << V_19 ) ) ;
if ( V_160 >= V_161 )
continue;
V_162 = F_143 ( V_160 , V_158 ) ;
V_163 = F_143 ( V_161 + V_166 - 1 , V_158 ) ;
F_144 (memslot, PT_PAGE_TABLE_LEVEL,
PT_MAX_HUGEPAGE_LEVEL,
gfn_start, gfn_end - 1 ,
&iterator)
V_63 |= F_139 ( V_105 , V_150 . V_131 , V_158 ,
V_150 . V_15 , V_150 . V_40 , V_144 ) ;
}
}
return V_63 ;
}
static int F_145 ( struct V_105 * V_105 , unsigned long V_167 ,
unsigned long V_144 ,
int (* F_139)( struct V_105 * V_105 ,
struct V_121 * V_122 ,
struct V_95 * V_96 ,
T_2 V_15 , int V_40 ,
unsigned long V_144 ) )
{
return F_138 ( V_105 , V_167 , V_167 + 1 , V_144 , F_139 ) ;
}
int F_146 ( struct V_105 * V_105 , unsigned long V_167 )
{
return F_145 ( V_105 , V_167 , 0 , F_128 ) ;
}
int F_147 ( struct V_105 * V_105 , unsigned long V_156 , unsigned long V_157 )
{
return F_138 ( V_105 , V_156 , V_157 , 0 , F_128 ) ;
}
void F_148 ( struct V_105 * V_105 , unsigned long V_167 , T_5 V_37 )
{
F_145 ( V_105 , V_167 , ( unsigned long ) & V_37 , F_129 ) ;
}
static int F_149 ( struct V_105 * V_105 , struct V_121 * V_122 ,
struct V_95 * V_96 , T_2 V_15 , int V_40 ,
unsigned long V_144 )
{
T_1 * V_14 ;
struct V_133 V_168 ( V_134 ) ;
int V_169 = 0 ;
F_71 ( ! V_30 ) ;
F_116 (rmap_head, &iter, sptep) {
if ( * V_14 & V_30 ) {
V_169 = 1 ;
F_150 ( ( F_151 ( V_30 ) - 1 ) ,
( unsigned long * ) V_14 ) ;
}
}
F_152 ( V_15 , V_40 , V_96 , V_169 ) ;
return V_169 ;
}
static int F_153 ( struct V_105 * V_105 , struct V_121 * V_122 ,
struct V_95 * V_96 , T_2 V_15 ,
int V_40 , unsigned long V_144 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
int V_169 = 0 ;
if ( ! V_30 )
goto V_84;
F_116 (rmap_head, &iter, sptep) {
if ( * V_14 & V_30 ) {
V_169 = 1 ;
break;
}
}
V_84:
return V_169 ;
}
static void F_154 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
struct V_121 * V_122 ;
struct V_47 * V_48 ;
V_48 = F_34 ( F_35 ( V_10 ) ) ;
V_122 = F_104 ( V_12 -> V_105 , V_15 , V_48 ) ;
F_128 ( V_12 -> V_105 , V_122 , NULL , V_15 , V_48 -> V_90 . V_40 , 0 ) ;
F_113 ( V_12 -> V_105 ) ;
}
int F_155 ( struct V_105 * V_105 , unsigned long V_156 , unsigned long V_157 )
{
if ( ! V_30 ) {
V_105 -> V_170 ++ ;
return F_138 ( V_105 , V_156 , V_157 , 0 ,
F_128 ) ;
}
return F_138 ( V_105 , V_156 , V_157 , 0 , F_149 ) ;
}
int F_156 ( struct V_105 * V_105 , unsigned long V_167 )
{
return F_145 ( V_105 , V_167 , 0 , F_153 ) ;
}
static int F_157 ( T_1 * V_132 )
{
T_1 * V_135 ;
T_1 * V_157 ;
for ( V_135 = V_132 , V_157 = V_135 + V_166 / sizeof( T_1 ) ; V_135 != V_157 ; V_135 ++ )
if ( F_22 ( * V_135 ) ) {
F_100 ( V_130 L_14 , V_143 ,
V_135 , * V_135 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_158 ( struct V_105 * V_105 , int V_171 )
{
V_105 -> V_34 . V_172 += V_171 ;
F_159 ( & V_173 , V_171 ) ;
}
static void F_160 ( struct V_47 * V_48 )
{
F_161 ( ! F_157 ( V_48 -> V_132 ) ) ;
F_162 ( & V_48 -> V_174 ) ;
F_163 ( & V_48 -> V_175 ) ;
F_67 ( ( unsigned long ) V_48 -> V_132 ) ;
if ( ! V_48 -> V_90 . V_91 )
F_67 ( ( unsigned long ) V_48 -> V_92 ) ;
F_63 ( V_86 , V_48 ) ;
}
static unsigned F_164 ( T_2 V_15 )
{
return V_15 & ( ( 1 << V_176 ) - 1 ) ;
}
static void F_165 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_177 )
{
if ( ! V_177 )
return;
F_96 ( V_12 , V_177 , & V_48 -> V_178 ) ;
}
static void F_166 ( struct V_47 * V_48 ,
T_1 * V_177 )
{
F_99 ( V_177 , & V_48 -> V_178 ) ;
}
static void F_167 ( struct V_47 * V_48 ,
T_1 * V_177 )
{
F_166 ( V_48 , V_177 ) ;
F_50 ( V_177 ) ;
}
static struct V_47 * F_168 ( struct V_11 * V_12 , int V_91 )
{
struct V_47 * V_48 ;
V_48 = F_70 ( & V_12 -> V_34 . V_86 ) ;
V_48 -> V_132 = F_70 ( & V_12 -> V_34 . V_85 ) ;
if ( ! V_91 )
V_48 -> V_92 = F_70 ( & V_12 -> V_34 . V_85 ) ;
F_169 ( F_170 ( V_48 -> V_132 ) , ( unsigned long ) V_48 ) ;
F_171 ( & V_48 -> V_175 , & V_12 -> V_105 -> V_34 . V_179 ) ;
F_158 ( V_12 -> V_105 , + 1 ) ;
return V_48 ;
}
static void F_172 ( struct V_47 * V_48 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
F_116 (&sp->parent_ptes, &iter, sptep) {
F_173 ( V_14 ) ;
}
}
static void F_173 ( T_1 * V_10 )
{
struct V_47 * V_48 ;
unsigned int V_89 ;
V_48 = F_34 ( F_35 ( V_10 ) ) ;
V_89 = V_10 - V_48 -> V_132 ;
if ( F_174 ( V_89 , V_48 -> V_180 ) )
return;
if ( V_48 -> V_181 ++ )
return;
F_172 ( V_48 ) ;
}
static int F_175 ( struct V_11 * V_12 ,
struct V_47 * V_48 )
{
return 0 ;
}
static void F_176 ( struct V_11 * V_12 , T_6 V_182 )
{
}
static void F_177 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_10 ,
const void * V_37 )
{
F_3 ( 1 ) ;
}
static int F_178 ( struct V_183 * V_184 , struct V_47 * V_48 ,
int V_97 )
{
int V_101 ;
if ( V_48 -> V_185 )
for ( V_101 = 0 ; V_101 < V_184 -> V_171 ; V_101 ++ )
if ( V_184 -> V_79 [ V_101 ] . V_48 == V_48 )
return 0 ;
V_184 -> V_79 [ V_184 -> V_171 ] . V_48 = V_48 ;
V_184 -> V_79 [ V_184 -> V_171 ] . V_97 = V_97 ;
V_184 -> V_171 ++ ;
return ( V_184 -> V_171 == V_186 ) ;
}
static inline void F_179 ( struct V_47 * V_48 , int V_97 )
{
-- V_48 -> V_181 ;
F_3 ( ( int ) V_48 -> V_181 < 0 ) ;
F_180 ( V_97 , V_48 -> V_180 ) ;
}
static int F_181 ( struct V_47 * V_48 ,
struct V_183 * V_184 )
{
int V_101 , V_63 , V_187 = 0 ;
F_182 (i, sp->unsync_child_bitmap, 512 ) {
struct V_47 * V_188 ;
T_1 V_189 = V_48 -> V_132 [ V_101 ] ;
if ( ! F_22 ( V_189 ) || F_23 ( V_189 ) ) {
F_179 ( V_48 , V_101 ) ;
continue;
}
V_188 = F_34 ( V_189 & V_42 ) ;
if ( V_188 -> V_181 ) {
if ( F_178 ( V_184 , V_188 , V_101 ) )
return - V_190 ;
V_63 = F_181 ( V_188 , V_184 ) ;
if ( ! V_63 ) {
F_179 ( V_48 , V_101 ) ;
continue;
} else if ( V_63 > 0 ) {
V_187 += V_63 ;
} else
return V_63 ;
} else if ( V_188 -> V_185 ) {
V_187 ++ ;
if ( F_178 ( V_184 , V_188 , V_101 ) )
return - V_190 ;
} else
F_179 ( V_48 , V_101 ) ;
}
return V_187 ;
}
static int F_183 ( struct V_47 * V_48 ,
struct V_183 * V_184 )
{
V_184 -> V_171 = 0 ;
if ( ! V_48 -> V_181 )
return 0 ;
F_178 ( V_184 , V_48 , V_191 ) ;
return F_181 ( V_48 , V_184 ) ;
}
static void F_184 ( struct V_105 * V_105 , struct V_47 * V_48 )
{
F_3 ( ! V_48 -> V_185 ) ;
F_185 ( V_48 ) ;
V_48 -> V_185 = 0 ;
-- V_105 -> V_136 . V_192 ;
}
static bool F_186 ( struct V_11 * V_12 , struct V_47 * V_48 ,
struct V_193 * V_194 )
{
if ( V_48 -> V_90 . V_195 != ! ! F_187 ( V_12 ) ) {
F_188 ( V_12 -> V_105 , V_48 , V_194 ) ;
return false ;
}
if ( V_12 -> V_34 . V_196 . V_197 ( V_12 , V_48 ) == 0 ) {
F_188 ( V_12 -> V_105 , V_48 , V_194 ) ;
return false ;
}
return true ;
}
static void F_189 ( struct V_11 * V_12 ,
struct V_193 * V_194 ,
bool V_198 , bool V_199 )
{
if ( ! F_190 ( V_194 ) ) {
F_191 ( V_12 -> V_105 , V_194 ) ;
return;
}
if ( V_198 )
F_113 ( V_12 -> V_105 ) ;
else if ( V_199 )
F_192 ( V_200 , V_12 ) ;
}
static void F_193 ( struct V_11 * V_12 , int V_201 ) { }
static void F_194 ( void ) { }
static bool F_195 ( struct V_11 * V_12 , struct V_47 * V_48 ,
struct V_193 * V_194 )
{
F_184 ( V_12 -> V_105 , V_48 ) ;
return F_186 ( V_12 , V_48 , V_194 ) ;
}
static bool F_196 ( struct V_11 * V_12 , T_2 V_15 ,
struct V_193 * V_194 )
{
struct V_47 * V_202 ;
bool V_63 = false ;
F_197 (vcpu->kvm, s, gfn) {
if ( ! V_202 -> V_185 )
continue;
F_3 ( V_202 -> V_90 . V_40 != V_41 ) ;
V_63 |= F_195 ( V_12 , V_202 , V_194 ) ;
}
return V_63 ;
}
static int F_198 ( struct V_183 * V_184 ,
struct V_203 * V_204 ,
int V_101 )
{
int V_205 ;
for ( V_205 = V_101 + 1 ; V_205 < V_184 -> V_171 ; V_205 ++ ) {
struct V_47 * V_48 = V_184 -> V_79 [ V_205 ] . V_48 ;
unsigned V_97 = V_184 -> V_79 [ V_205 ] . V_97 ;
int V_40 = V_48 -> V_90 . V_40 ;
V_204 -> V_97 [ V_40 - 1 ] = V_97 ;
if ( V_40 == V_41 )
break;
V_204 -> V_206 [ V_40 - 2 ] = V_48 ;
}
return V_205 ;
}
static int F_199 ( struct V_183 * V_184 ,
struct V_203 * V_204 )
{
struct V_47 * V_48 ;
int V_40 ;
if ( V_184 -> V_171 == 0 )
return 0 ;
F_3 ( V_184 -> V_79 [ 0 ] . V_97 != V_191 ) ;
V_48 = V_184 -> V_79 [ 0 ] . V_48 ;
V_40 = V_48 -> V_90 . V_40 ;
F_3 ( V_40 == V_41 ) ;
V_204 -> V_206 [ V_40 - 2 ] = V_48 ;
V_204 -> V_206 [ V_40 - 1 ] = NULL ;
return F_198 ( V_184 , V_204 , 0 ) ;
}
static void F_200 ( struct V_203 * V_204 )
{
struct V_47 * V_48 ;
unsigned int V_40 = 0 ;
do {
unsigned int V_97 = V_204 -> V_97 [ V_40 ] ;
V_48 = V_204 -> V_206 [ V_40 ] ;
if ( ! V_48 )
return;
F_3 ( V_97 == V_191 ) ;
F_179 ( V_48 , V_97 ) ;
V_40 ++ ;
} while ( ! V_48 -> V_181 );
}
static void F_201 ( struct V_11 * V_12 ,
struct V_47 * V_206 )
{
int V_101 ;
struct V_47 * V_48 ;
struct V_203 V_204 ;
struct V_183 V_207 ;
F_202 ( V_194 ) ;
bool V_139 = false ;
while ( F_183 ( V_206 , & V_207 ) ) {
bool V_208 = false ;
F_203 (pages, sp, parents, i)
V_208 |= F_126 ( V_12 , V_48 -> V_15 ) ;
if ( V_208 ) {
F_113 ( V_12 -> V_105 ) ;
V_139 = false ;
}
F_203 (pages, sp, parents, i) {
V_139 |= F_195 ( V_12 , V_48 , & V_194 ) ;
F_200 ( & V_204 ) ;
}
if ( F_204 () || F_205 ( & V_12 -> V_105 -> V_209 ) ) {
F_189 ( V_12 , & V_194 , false , V_139 ) ;
F_206 ( & V_12 -> V_105 -> V_209 ) ;
V_139 = false ;
}
}
F_189 ( V_12 , & V_194 , false , V_139 ) ;
}
static void F_207 ( struct V_47 * V_48 )
{
F_208 ( & V_48 -> V_210 , 0 ) ;
}
static void F_209 ( T_1 * V_10 )
{
struct V_47 * V_48 = F_34 ( F_35 ( V_10 ) ) ;
F_207 ( V_48 ) ;
}
static bool F_210 ( struct V_105 * V_105 , struct V_47 * V_48 )
{
return F_14 ( V_48 -> V_211 != V_105 -> V_34 . V_211 ) ;
}
static struct V_47 * F_211 ( struct V_11 * V_12 ,
T_2 V_15 ,
T_6 V_212 ,
unsigned V_40 ,
int V_91 ,
unsigned V_16 )
{
union V_213 V_90 ;
unsigned V_214 ;
struct V_47 * V_48 ;
bool V_215 = false ;
bool V_139 = false ;
F_202 ( V_194 ) ;
V_90 = V_12 -> V_34 . V_196 . V_216 ;
V_90 . V_40 = V_40 ;
V_90 . V_91 = V_91 ;
if ( V_90 . V_91 )
V_90 . V_195 = 0 ;
V_90 . V_16 = V_16 ;
if ( ! V_12 -> V_34 . V_196 . V_217
&& V_12 -> V_34 . V_196 . V_218 <= V_219 ) {
V_214 = V_212 >> ( V_19 + ( V_220 * V_40 ) ) ;
V_214 &= ( 1 << ( ( V_221 - V_220 ) * V_40 ) ) - 1 ;
V_90 . V_214 = V_214 ;
}
F_212 (vcpu->kvm, sp, gfn) {
if ( F_210 ( V_12 -> V_105 , V_48 ) )
continue;
if ( ! V_215 && V_48 -> V_185 )
V_215 = true ;
if ( V_48 -> V_90 . V_222 != V_90 . V_222 )
continue;
if ( V_48 -> V_185 ) {
if ( ! F_186 ( V_12 , V_48 , & V_194 ) )
break;
F_3 ( ! F_190 ( & V_194 ) ) ;
F_192 ( V_200 , V_12 ) ;
}
if ( V_48 -> V_181 )
F_192 ( V_223 , V_12 ) ;
F_207 ( V_48 ) ;
F_213 ( V_48 , false ) ;
return V_48 ;
}
++ V_12 -> V_105 -> V_136 . V_224 ;
V_48 = F_168 ( V_12 , V_91 ) ;
V_48 -> V_15 = V_15 ;
V_48 -> V_90 = V_90 ;
F_214 ( & V_48 -> V_174 ,
& V_12 -> V_105 -> V_34 . V_225 [ F_164 ( V_15 ) ] ) ;
if ( ! V_91 ) {
F_81 ( V_12 -> V_105 , V_48 ) ;
if ( V_40 == V_41 &&
F_126 ( V_12 , V_15 ) )
F_113 ( V_12 -> V_105 ) ;
if ( V_40 > V_41 && V_215 )
V_139 |= F_196 ( V_12 , V_15 , & V_194 ) ;
}
V_48 -> V_211 = V_12 -> V_105 -> V_34 . V_211 ;
F_215 ( V_48 -> V_132 ) ;
F_213 ( V_48 , true ) ;
F_189 ( V_12 , & V_194 , false , V_139 ) ;
return V_48 ;
}
static void F_216 ( struct V_226 * V_150 ,
struct V_11 * V_12 , T_1 V_227 )
{
V_150 -> V_227 = V_227 ;
V_150 -> V_228 = V_12 -> V_34 . V_196 . V_229 ;
V_150 -> V_40 = V_12 -> V_34 . V_196 . V_230 ;
if ( V_150 -> V_40 == V_231 &&
V_12 -> V_34 . V_196 . V_218 < V_231 &&
! V_12 -> V_34 . V_196 . V_217 )
-- V_150 -> V_40 ;
if ( V_150 -> V_40 == V_232 ) {
V_150 -> V_228
= V_12 -> V_34 . V_196 . V_233 [ ( V_227 >> 30 ) & 3 ] ;
V_150 -> V_228 &= V_42 ;
-- V_150 -> V_40 ;
if ( ! V_150 -> V_228 )
V_150 -> V_40 = 0 ;
}
}
static bool F_217 ( struct V_226 * V_150 )
{
if ( V_150 -> V_40 < V_41 )
return false ;
V_150 -> V_89 = F_218 ( V_150 -> V_227 , V_150 -> V_40 ) ;
V_150 -> V_14 = ( ( T_1 * ) F_219 ( V_150 -> V_228 ) ) + V_150 -> V_89 ;
return true ;
}
static void F_220 ( struct V_226 * V_150 ,
T_1 V_10 )
{
if ( F_24 ( V_10 , V_150 -> V_40 ) ) {
V_150 -> V_40 = 0 ;
return;
}
V_150 -> V_228 = V_10 & V_42 ;
-- V_150 -> V_40 ;
}
static void F_221 ( struct V_226 * V_150 )
{
return F_220 ( V_150 , * V_150 -> V_14 ) ;
}
static void F_222 ( struct V_11 * V_12 , T_1 * V_14 ,
struct V_47 * V_48 )
{
T_1 V_10 ;
F_223 ( V_234 != V_38 ||
V_235 != V_64 ) ;
V_10 = F_35 ( V_48 -> V_132 ) | V_38 | V_64 |
V_29 | V_33 | V_30 ;
F_9 ( V_14 , V_10 ) ;
F_165 ( V_12 , V_48 , V_14 ) ;
if ( V_48 -> V_181 || V_48 -> V_185 )
F_173 ( V_14 ) ;
}
static void F_224 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_236 )
{
if ( F_22 ( * V_14 ) && ! F_23 ( * V_14 ) ) {
struct V_47 * V_188 ;
V_188 = F_34 ( * V_14 & V_42 ) ;
if ( V_188 -> V_90 . V_16 == V_236 )
return;
F_167 ( V_188 , V_14 ) ;
F_113 ( V_12 -> V_105 ) ;
}
}
static bool F_225 ( struct V_105 * V_105 , struct V_47 * V_48 ,
T_1 * V_10 )
{
T_1 V_37 ;
struct V_47 * V_188 ;
V_37 = * V_10 ;
if ( F_22 ( V_37 ) ) {
if ( F_24 ( V_37 , V_48 -> V_90 . V_40 ) ) {
F_110 ( V_105 , V_10 ) ;
if ( F_23 ( V_37 ) )
-- V_105 -> V_136 . V_137 ;
} else {
V_188 = F_34 ( V_37 & V_42 ) ;
F_167 ( V_188 , V_10 ) ;
}
return true ;
}
if ( F_10 ( V_37 ) )
F_50 ( V_10 ) ;
return false ;
}
static void F_226 ( struct V_105 * V_105 ,
struct V_47 * V_48 )
{
unsigned V_101 ;
for ( V_101 = 0 ; V_101 < V_237 ; ++ V_101 )
F_225 ( V_105 , V_48 , V_48 -> V_132 + V_101 ) ;
}
static void F_227 ( struct V_105 * V_105 , struct V_47 * V_48 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
while ( ( V_14 = F_108 ( & V_48 -> V_178 , & V_134 ) ) )
F_167 ( V_48 , V_14 ) ;
}
static int F_228 ( struct V_105 * V_105 ,
struct V_47 * V_206 ,
struct V_193 * V_194 )
{
int V_101 , V_238 = 0 ;
struct V_203 V_204 ;
struct V_183 V_207 ;
if ( V_206 -> V_90 . V_40 == V_41 )
return 0 ;
while ( F_183 ( V_206 , & V_207 ) ) {
struct V_47 * V_48 ;
F_203 (pages, sp, parents, i) {
F_188 ( V_105 , V_48 , V_194 ) ;
F_200 ( & V_204 ) ;
V_238 ++ ;
}
}
return V_238 ;
}
static int F_188 ( struct V_105 * V_105 , struct V_47 * V_48 ,
struct V_193 * V_194 )
{
int V_63 ;
F_229 ( V_48 ) ;
++ V_105 -> V_136 . V_239 ;
V_63 = F_228 ( V_105 , V_48 , V_194 ) ;
F_226 ( V_105 , V_48 ) ;
F_227 ( V_105 , V_48 ) ;
if ( ! V_48 -> V_90 . V_240 && ! V_48 -> V_90 . V_91 )
F_85 ( V_105 , V_48 ) ;
if ( V_48 -> V_185 )
F_184 ( V_105 , V_48 ) ;
if ( ! V_48 -> V_241 ) {
V_63 ++ ;
F_230 ( & V_48 -> V_175 , V_194 ) ;
F_158 ( V_105 , - 1 ) ;
} else {
F_230 ( & V_48 -> V_175 , & V_105 -> V_34 . V_179 ) ;
if ( ! V_48 -> V_90 . V_240 && ! F_210 ( V_105 , V_48 ) )
F_231 ( V_105 ) ;
}
V_48 -> V_90 . V_240 = 1 ;
return V_63 ;
}
static void F_191 ( struct V_105 * V_105 ,
struct V_193 * V_194 )
{
struct V_47 * V_48 , * V_242 ;
if ( F_190 ( V_194 ) )
return;
F_113 ( V_105 ) ;
F_232 (sp, nsp, invalid_list, link) {
F_3 ( ! V_48 -> V_90 . V_240 || V_48 -> V_241 ) ;
F_160 ( V_48 ) ;
}
}
static bool F_233 ( struct V_105 * V_105 ,
struct V_193 * V_194 )
{
struct V_47 * V_48 ;
if ( F_190 ( & V_105 -> V_34 . V_179 ) )
return false ;
V_48 = F_234 ( & V_105 -> V_34 . V_179 ,
struct V_47 , V_175 ) ;
F_188 ( V_105 , V_48 , V_194 ) ;
return true ;
}
void F_235 ( struct V_105 * V_105 , unsigned int V_243 )
{
F_202 ( V_194 ) ;
F_236 ( & V_105 -> V_209 ) ;
if ( V_105 -> V_34 . V_172 > V_243 ) {
while ( V_105 -> V_34 . V_172 > V_243 )
if ( ! F_233 ( V_105 , & V_194 ) )
break;
F_191 ( V_105 , & V_194 ) ;
V_243 = V_105 -> V_34 . V_172 ;
}
V_105 -> V_34 . V_244 = V_243 ;
F_237 ( & V_105 -> V_209 ) ;
}
int F_238 ( struct V_105 * V_105 , T_2 V_15 )
{
struct V_47 * V_48 ;
F_202 ( V_194 ) ;
int V_80 ;
F_239 ( L_15 , V_143 , V_15 ) ;
V_80 = 0 ;
F_236 ( & V_105 -> V_209 ) ;
F_197 (kvm, sp, gfn) {
F_239 ( L_16 , V_143 , V_15 ,
V_48 -> V_90 . V_222 ) ;
V_80 = 1 ;
F_188 ( V_105 , V_48 , & V_194 ) ;
}
F_191 ( V_105 , & V_194 ) ;
F_237 ( & V_105 -> V_209 ) ;
return V_80 ;
}
static void F_240 ( struct V_11 * V_12 , struct V_47 * V_48 )
{
F_241 ( V_48 ) ;
++ V_12 -> V_105 -> V_136 . V_192 ;
V_48 -> V_185 = 1 ;
F_172 ( V_48 ) ;
}
static bool F_242 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_245 )
{
struct V_47 * V_48 ;
if ( F_243 ( V_12 , V_15 , V_109 ) )
return true ;
F_197 (vcpu->kvm, sp, gfn) {
if ( ! V_245 )
return true ;
if ( V_48 -> V_185 )
continue;
F_3 ( V_48 -> V_90 . V_40 != V_41 ) ;
F_240 ( V_12 , V_48 ) ;
}
return false ;
}
static bool F_244 ( T_3 V_21 )
{
if ( F_245 ( V_21 ) )
return ! F_246 ( V_21 ) && F_247 ( F_49 ( V_21 ) ) ;
return true ;
}
static int F_248 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_246 , int V_40 ,
T_2 V_15 , T_3 V_21 , bool V_247 ,
bool V_245 , bool V_248 )
{
T_1 V_10 ;
int V_63 = 0 ;
if ( F_13 ( V_12 , V_14 , V_15 , V_21 , V_246 ) )
return 0 ;
V_10 = V_38 ;
if ( ! V_247 )
V_10 |= V_30 ;
if ( V_246 & V_249 )
V_10 |= V_33 ;
else
V_10 |= V_32 ;
if ( V_246 & V_18 )
V_10 |= V_29 ;
if ( V_40 > V_41 )
V_10 |= V_39 ;
if ( V_250 )
V_10 |= V_119 -> V_251 ( V_12 , V_15 ,
F_244 ( V_21 ) ) ;
if ( V_248 )
V_10 |= V_58 ;
else
V_246 &= ~ V_17 ;
V_10 |= ( T_1 ) V_21 << V_19 ;
if ( V_246 & V_17 ) {
if ( V_40 > V_41 &&
F_88 ( V_12 , V_15 , V_40 ) )
goto V_252;
V_10 |= V_64 | V_59 ;
if ( ! V_245 && F_40 ( * V_14 ) )
goto V_253;
if ( F_242 ( V_12 , V_15 , V_245 ) ) {
F_239 ( L_17 ,
V_143 , V_15 ) ;
V_63 = 1 ;
V_246 &= ~ V_17 ;
V_10 &= ~ ( V_64 | V_59 ) ;
}
}
if ( V_246 & V_17 ) {
F_249 ( V_12 , V_15 ) ;
V_10 |= V_31 ;
}
V_253:
if ( F_43 ( V_14 , V_10 ) )
F_113 ( V_12 -> V_105 ) ;
V_252:
return V_63 ;
}
static bool F_250 ( struct V_11 * V_12 , T_1 * V_14 , unsigned V_246 ,
int V_254 , int V_40 , T_2 V_15 , T_3 V_21 ,
bool V_247 , bool V_248 )
{
int V_255 = 0 ;
int V_256 ;
bool V_257 = false ;
F_239 ( L_18 , V_143 ,
* V_14 , V_254 , V_15 ) ;
if ( F_22 ( * V_14 ) ) {
if ( V_40 > V_41 &&
! F_23 ( * V_14 ) ) {
struct V_47 * V_188 ;
T_1 V_37 = * V_14 ;
V_188 = F_34 ( V_37 & V_42 ) ;
F_167 ( V_188 , V_14 ) ;
F_113 ( V_12 -> V_105 ) ;
} else if ( V_21 != F_25 ( * V_14 ) ) {
F_239 ( L_19 ,
F_25 ( * V_14 ) , V_21 ) ;
F_110 ( V_12 -> V_105 , V_14 ) ;
F_113 ( V_12 -> V_105 ) ;
} else
V_255 = 1 ;
}
if ( F_248 ( V_12 , V_14 , V_246 , V_40 , V_15 , V_21 , V_247 ,
true , V_248 ) ) {
if ( V_254 )
V_257 = true ;
F_192 ( V_200 , V_12 ) ;
}
if ( F_14 ( F_10 ( * V_14 ) ) )
V_257 = true ;
F_239 ( L_20 , V_143 , * V_14 ) ;
F_239 ( L_21 ,
F_23 ( * V_14 ) ? L_22 : L_23 ,
* V_14 & V_38 ? L_24 : L_25 , V_15 ,
* V_14 , V_14 ) ;
if ( ! V_255 && F_23 ( * V_14 ) )
++ V_12 -> V_105 -> V_136 . V_137 ;
if ( F_22 ( * V_14 ) ) {
if ( ! V_255 ) {
V_256 = F_106 ( V_12 , V_14 , V_15 ) ;
if ( V_256 > V_258 )
F_154 ( V_12 , V_14 , V_15 ) ;
}
}
F_251 ( V_21 ) ;
return V_257 ;
}
static T_3 F_252 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_111 )
{
struct V_95 * V_96 ;
V_96 = F_94 ( V_12 , V_15 , V_111 ) ;
if ( ! V_96 )
return V_259 ;
return F_253 ( V_96 , V_15 ) ;
}
static int F_254 ( struct V_11 * V_12 ,
struct V_47 * V_48 ,
T_1 * V_156 , T_1 * V_157 )
{
struct V_79 * V_207 [ V_83 ] ;
struct V_95 * V_96 ;
unsigned V_16 = V_48 -> V_90 . V_16 ;
int V_101 , V_63 ;
T_2 V_15 ;
V_15 = F_74 ( V_48 , V_156 - V_48 -> V_132 ) ;
V_96 = F_94 ( V_12 , V_15 , V_16 & V_17 ) ;
if ( ! V_96 )
return - 1 ;
V_63 = F_255 ( V_96 , V_15 , V_207 , V_157 - V_156 ) ;
if ( V_63 <= 0 )
return - 1 ;
for ( V_101 = 0 ; V_101 < V_63 ; V_101 ++ , V_15 ++ , V_156 ++ )
F_250 ( V_12 , V_156 , V_16 , 0 , V_48 -> V_90 . V_40 , V_15 ,
F_256 ( V_207 [ V_101 ] ) , true , true ) ;
return 0 ;
}
static void F_257 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_14 )
{
T_1 * V_10 , * V_156 = NULL ;
int V_101 ;
F_3 ( ! V_48 -> V_90 . V_91 ) ;
V_101 = ( V_14 - V_48 -> V_132 ) & ~ ( V_83 - 1 ) ;
V_10 = V_48 -> V_132 + V_101 ;
for ( V_101 = 0 ; V_101 < V_83 ; V_101 ++ , V_10 ++ ) {
if ( F_22 ( * V_10 ) || V_10 == V_14 ) {
if ( ! V_156 )
continue;
if ( F_254 ( V_12 , V_48 , V_156 , V_10 ) < 0 )
break;
V_156 = NULL ;
} else if ( ! V_156 )
V_156 = V_10 ;
}
}
static void F_258 ( struct V_11 * V_12 , T_1 * V_14 )
{
struct V_47 * V_48 ;
if ( ! V_30 )
return;
V_48 = F_34 ( F_35 ( V_14 ) ) ;
if ( V_48 -> V_90 . V_40 > V_41 )
return;
F_257 ( V_12 , V_48 , V_14 ) ;
}
static int F_259 ( struct V_11 * V_12 , int V_260 , int V_261 ,
int V_40 , T_2 V_15 , T_3 V_21 , bool V_262 )
{
struct V_226 V_150 ;
struct V_47 * V_48 ;
int V_257 = 0 ;
T_2 V_263 ;
if ( ! F_260 ( V_12 -> V_34 . V_196 . V_229 ) )
return 0 ;
F_261 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_150 . V_40 == V_40 ) {
V_257 = F_250 ( V_12 , V_150 . V_14 , V_264 ,
V_260 , V_40 , V_15 , V_21 , V_262 ,
V_261 ) ;
F_258 ( V_12 , V_150 . V_14 ) ;
++ V_12 -> V_136 . V_265 ;
break;
}
F_112 ( V_12 , V_150 . V_14 ) ;
if ( ! F_22 ( * V_150 . V_14 ) ) {
T_1 V_266 = V_150 . V_227 ;
V_266 &= F_262 ( V_150 . V_40 ) ;
V_263 = V_266 >> V_19 ;
V_48 = F_211 ( V_12 , V_263 , V_150 . V_227 ,
V_150 . V_40 - 1 , 1 , V_264 ) ;
F_222 ( V_12 , V_150 . V_14 , V_48 ) ;
}
}
return V_257 ;
}
static void F_263 ( unsigned long V_267 , struct V_268 * V_269 )
{
T_7 V_270 ;
V_270 . V_271 = V_272 ;
V_270 . V_273 = 0 ;
V_270 . V_274 = V_275 ;
V_270 . V_276 = ( void V_277 * ) V_267 ;
V_270 . V_278 = V_19 ;
F_264 ( V_272 , & V_270 , V_269 ) ;
}
static int F_265 ( struct V_11 * V_12 , T_2 V_15 , T_3 V_21 )
{
if ( V_21 == V_279 )
return 1 ;
if ( V_21 == V_280 ) {
F_263 ( F_266 ( V_12 , V_15 ) , V_281 ) ;
return 0 ;
}
return - V_282 ;
}
static void F_267 ( struct V_11 * V_12 ,
T_2 * V_283 , T_3 * V_284 ,
int * V_285 )
{
T_3 V_21 = * V_284 ;
T_2 V_15 = * V_283 ;
int V_40 = * V_285 ;
if ( ! F_268 ( V_21 ) && ! F_47 ( V_21 ) &&
V_40 == V_41 &&
F_269 ( F_49 ( V_21 ) ) &&
! F_88 ( V_12 , V_15 , V_102 ) ) {
unsigned long V_4 ;
* V_285 = V_40 = V_102 ;
V_4 = F_270 ( V_40 ) - 1 ;
F_271 ( ( V_15 & V_4 ) != ( V_21 & V_4 ) ) ;
if ( V_21 & V_4 ) {
V_15 &= ~ V_4 ;
* V_283 = V_15 ;
F_251 ( V_21 ) ;
V_21 &= ~ V_4 ;
F_272 ( V_21 ) ;
* V_284 = V_21 ;
}
}
}
static bool F_273 ( struct V_11 * V_12 , T_6 V_182 , T_2 V_15 ,
T_3 V_21 , unsigned V_16 , int * V_286 )
{
if ( F_14 ( F_274 ( V_21 ) ) ) {
* V_286 = F_265 ( V_12 , V_15 , V_21 ) ;
return true ;
}
if ( F_14 ( F_15 ( V_21 ) ) )
F_275 ( V_12 , V_182 , V_15 , V_16 ) ;
return false ;
}
static bool F_276 ( T_4 V_287 )
{
if ( F_14 ( V_287 & V_288 ) )
return false ;
if ( ! ( V_287 & V_289 ) ||
! ( V_287 & V_290 ) )
return false ;
return true ;
}
static bool
F_277 ( struct V_11 * V_12 , struct V_47 * V_48 ,
T_1 * V_14 , T_1 V_10 )
{
T_2 V_15 ;
F_3 ( ! V_48 -> V_90 . V_91 ) ;
V_15 = F_74 ( V_48 , V_14 - V_48 -> V_132 ) ;
if ( F_278 ( V_14 , V_10 , V_10 | V_64 ) == V_10 )
F_249 ( V_12 , V_15 ) ;
return true ;
}
static bool F_279 ( struct V_11 * V_12 , T_6 V_182 , int V_40 ,
T_4 V_287 )
{
struct V_226 V_150 ;
struct V_47 * V_48 ;
bool V_63 = false ;
T_1 V_10 = 0ull ;
if ( ! F_260 ( V_12 -> V_34 . V_196 . V_229 ) )
return false ;
if ( ! F_276 ( V_287 ) )
return false ;
F_52 ( V_12 ) ;
F_280 (vcpu, gva, iterator, spte)
if ( ! F_22 ( V_10 ) || V_150 . V_40 < V_40 )
break;
if ( ! F_22 ( V_10 ) ) {
V_63 = true ;
goto exit;
}
V_48 = F_34 ( F_35 ( V_150 . V_14 ) ) ;
if ( ! F_24 ( V_10 , V_48 -> V_90 . V_40 ) )
goto exit;
if ( F_40 ( V_10 ) ) {
V_63 = true ;
goto exit;
}
if ( ! F_38 ( V_10 ) )
goto exit;
if ( V_48 -> V_90 . V_40 > V_41 )
goto exit;
V_63 = F_277 ( V_12 , V_48 , V_150 . V_14 , V_10 ) ;
exit:
F_281 ( V_12 , V_182 , V_287 , V_150 . V_14 ,
V_10 , V_63 ) ;
F_55 ( V_12 ) ;
return V_63 ;
}
static int F_282 ( struct V_11 * V_12 , T_6 V_291 , T_4 V_287 ,
T_2 V_15 , bool V_262 )
{
int V_80 ;
int V_40 ;
bool V_116 = false ;
T_3 V_21 ;
unsigned long V_292 ;
bool V_261 , V_260 = V_287 & V_290 ;
V_40 = F_95 ( V_12 , V_15 , & V_116 ) ;
if ( F_18 ( ! V_116 ) ) {
if ( V_40 > V_102 )
V_40 = V_102 ;
V_15 &= ~ ( F_270 ( V_40 ) - 1 ) ;
}
if ( F_279 ( V_12 , V_291 , V_40 , V_287 ) )
return 0 ;
V_292 = V_12 -> V_105 -> V_170 ;
F_37 () ;
if ( F_283 ( V_12 , V_262 , V_15 , V_291 , & V_21 , V_260 , & V_261 ) )
return 0 ;
if ( F_273 ( V_12 , V_291 , V_15 , V_21 , V_264 , & V_80 ) )
return V_80 ;
F_236 ( & V_12 -> V_105 -> V_209 ) ;
if ( F_284 ( V_12 -> V_105 , V_292 ) )
goto V_293;
F_285 ( V_12 ) ;
if ( F_18 ( ! V_116 ) )
F_267 ( V_12 , & V_15 , & V_21 , & V_40 ) ;
V_80 = F_259 ( V_12 , V_260 , V_261 , V_40 , V_15 , V_21 , V_262 ) ;
F_237 ( & V_12 -> V_105 -> V_209 ) ;
return V_80 ;
V_293:
F_237 ( & V_12 -> V_105 -> V_209 ) ;
F_251 ( V_21 ) ;
return 0 ;
}
static void F_286 ( struct V_11 * V_12 )
{
int V_101 ;
struct V_47 * V_48 ;
F_202 ( V_194 ) ;
if ( ! F_260 ( V_12 -> V_34 . V_196 . V_229 ) )
return;
if ( V_12 -> V_34 . V_196 . V_230 == V_231 &&
( V_12 -> V_34 . V_196 . V_218 == V_231 ||
V_12 -> V_34 . V_196 . V_217 ) ) {
T_8 V_294 = V_12 -> V_34 . V_196 . V_229 ;
F_236 ( & V_12 -> V_105 -> V_209 ) ;
V_48 = F_34 ( V_294 ) ;
-- V_48 -> V_241 ;
if ( ! V_48 -> V_241 && V_48 -> V_90 . V_240 ) {
F_188 ( V_12 -> V_105 , V_48 , & V_194 ) ;
F_191 ( V_12 -> V_105 , & V_194 ) ;
}
F_237 ( & V_12 -> V_105 -> V_209 ) ;
V_12 -> V_34 . V_196 . V_229 = V_295 ;
return;
}
F_236 ( & V_12 -> V_105 -> V_209 ) ;
for ( V_101 = 0 ; V_101 < 4 ; ++ V_101 ) {
T_8 V_294 = V_12 -> V_34 . V_196 . V_233 [ V_101 ] ;
if ( V_294 ) {
V_294 &= V_42 ;
V_48 = F_34 ( V_294 ) ;
-- V_48 -> V_241 ;
if ( ! V_48 -> V_241 && V_48 -> V_90 . V_240 )
F_188 ( V_12 -> V_105 , V_48 ,
& V_194 ) ;
}
V_12 -> V_34 . V_196 . V_233 [ V_101 ] = V_295 ;
}
F_191 ( V_12 -> V_105 , & V_194 ) ;
F_237 ( & V_12 -> V_105 -> V_209 ) ;
V_12 -> V_34 . V_196 . V_229 = V_295 ;
}
static int F_287 ( struct V_11 * V_12 , T_2 V_296 )
{
int V_63 = 0 ;
if ( ! F_288 ( V_12 -> V_105 , V_296 ) ) {
F_192 ( V_297 , V_12 ) ;
V_63 = 1 ;
}
return V_63 ;
}
static int F_289 ( struct V_11 * V_12 )
{
struct V_47 * V_48 ;
unsigned V_101 ;
if ( V_12 -> V_34 . V_196 . V_230 == V_231 ) {
F_236 ( & V_12 -> V_105 -> V_209 ) ;
F_285 ( V_12 ) ;
V_48 = F_211 ( V_12 , 0 , 0 , V_231 , 1 , V_264 ) ;
++ V_48 -> V_241 ;
F_237 ( & V_12 -> V_105 -> V_209 ) ;
V_12 -> V_34 . V_196 . V_229 = F_35 ( V_48 -> V_132 ) ;
} else if ( V_12 -> V_34 . V_196 . V_230 == V_232 ) {
for ( V_101 = 0 ; V_101 < 4 ; ++ V_101 ) {
T_8 V_294 = V_12 -> V_34 . V_196 . V_233 [ V_101 ] ;
F_161 ( F_260 ( V_294 ) ) ;
F_236 ( & V_12 -> V_105 -> V_209 ) ;
F_285 ( V_12 ) ;
V_48 = F_211 ( V_12 , V_101 << ( 30 - V_19 ) ,
V_101 << 30 , V_219 , 1 , V_264 ) ;
V_294 = F_35 ( V_48 -> V_132 ) ;
++ V_48 -> V_241 ;
F_237 ( & V_12 -> V_105 -> V_209 ) ;
V_12 -> V_34 . V_196 . V_233 [ V_101 ] = V_294 | V_38 ;
}
V_12 -> V_34 . V_196 . V_229 = F_35 ( V_12 -> V_34 . V_196 . V_233 ) ;
} else
F_101 () ;
return 0 ;
}
static int F_290 ( struct V_11 * V_12 )
{
struct V_47 * V_48 ;
T_1 V_298 , V_299 ;
T_2 V_296 ;
int V_101 ;
V_296 = V_12 -> V_34 . V_196 . V_300 ( V_12 ) >> V_19 ;
if ( F_287 ( V_12 , V_296 ) )
return 1 ;
if ( V_12 -> V_34 . V_196 . V_218 == V_231 ) {
T_8 V_294 = V_12 -> V_34 . V_196 . V_229 ;
F_161 ( F_260 ( V_294 ) ) ;
F_236 ( & V_12 -> V_105 -> V_209 ) ;
F_285 ( V_12 ) ;
V_48 = F_211 ( V_12 , V_296 , 0 , V_231 ,
0 , V_264 ) ;
V_294 = F_35 ( V_48 -> V_132 ) ;
++ V_48 -> V_241 ;
F_237 ( & V_12 -> V_105 -> V_209 ) ;
V_12 -> V_34 . V_196 . V_229 = V_294 ;
return 0 ;
}
V_299 = V_38 ;
if ( V_12 -> V_34 . V_196 . V_230 == V_231 )
V_299 |= V_301 | V_64 | V_302 ;
for ( V_101 = 0 ; V_101 < 4 ; ++ V_101 ) {
T_8 V_294 = V_12 -> V_34 . V_196 . V_233 [ V_101 ] ;
F_161 ( F_260 ( V_294 ) ) ;
if ( V_12 -> V_34 . V_196 . V_218 == V_232 ) {
V_298 = V_12 -> V_34 . V_196 . V_303 ( V_12 , V_101 ) ;
if ( ! F_291 ( V_298 ) ) {
V_12 -> V_34 . V_196 . V_233 [ V_101 ] = 0 ;
continue;
}
V_296 = V_298 >> V_19 ;
if ( F_287 ( V_12 , V_296 ) )
return 1 ;
}
F_236 ( & V_12 -> V_105 -> V_209 ) ;
F_285 ( V_12 ) ;
V_48 = F_211 ( V_12 , V_296 , V_101 << 30 , V_219 ,
0 , V_264 ) ;
V_294 = F_35 ( V_48 -> V_132 ) ;
++ V_48 -> V_241 ;
F_237 ( & V_12 -> V_105 -> V_209 ) ;
V_12 -> V_34 . V_196 . V_233 [ V_101 ] = V_294 | V_299 ;
}
V_12 -> V_34 . V_196 . V_229 = F_35 ( V_12 -> V_34 . V_196 . V_233 ) ;
if ( V_12 -> V_34 . V_196 . V_230 == V_231 ) {
if ( V_12 -> V_34 . V_196 . V_304 == NULL ) {
T_1 * V_304 ;
V_304 = ( void * ) F_292 ( V_76 ) ;
if ( V_304 == NULL )
return 1 ;
V_304 [ 0 ] = F_35 ( V_12 -> V_34 . V_196 . V_233 ) | V_299 ;
V_12 -> V_34 . V_196 . V_304 = V_304 ;
}
V_12 -> V_34 . V_196 . V_229 = F_35 ( V_12 -> V_34 . V_196 . V_304 ) ;
}
return 0 ;
}
static int F_293 ( struct V_11 * V_12 )
{
if ( V_12 -> V_34 . V_196 . V_217 )
return F_289 ( V_12 ) ;
else
return F_290 ( V_12 ) ;
}
static void F_294 ( struct V_11 * V_12 )
{
int V_101 ;
struct V_47 * V_48 ;
if ( V_12 -> V_34 . V_196 . V_217 )
return;
if ( ! F_260 ( V_12 -> V_34 . V_196 . V_229 ) )
return;
F_295 ( V_12 , V_305 ) ;
F_193 ( V_12 , V_306 ) ;
if ( V_12 -> V_34 . V_196 . V_218 == V_231 ) {
T_8 V_294 = V_12 -> V_34 . V_196 . V_229 ;
V_48 = F_34 ( V_294 ) ;
F_201 ( V_12 , V_48 ) ;
F_193 ( V_12 , V_307 ) ;
return;
}
for ( V_101 = 0 ; V_101 < 4 ; ++ V_101 ) {
T_8 V_294 = V_12 -> V_34 . V_196 . V_233 [ V_101 ] ;
if ( V_294 && F_260 ( V_294 ) ) {
V_294 &= V_42 ;
V_48 = F_34 ( V_294 ) ;
F_201 ( V_12 , V_48 ) ;
}
}
F_193 ( V_12 , V_307 ) ;
}
void F_296 ( struct V_11 * V_12 )
{
F_236 ( & V_12 -> V_105 -> V_209 ) ;
F_294 ( V_12 ) ;
F_237 ( & V_12 -> V_105 -> V_209 ) ;
}
static T_9 F_297 ( struct V_11 * V_12 , T_6 V_308 ,
T_4 V_16 , struct V_309 * V_310 )
{
if ( V_310 )
V_310 -> V_287 = 0 ;
return V_308 ;
}
static T_9 F_298 ( struct V_11 * V_12 , T_6 V_308 ,
T_4 V_16 ,
struct V_309 * V_310 )
{
if ( V_310 )
V_310 -> V_287 = 0 ;
return V_12 -> V_34 . V_311 . V_312 ( V_12 , V_308 , V_16 , V_310 ) ;
}
static bool
F_299 ( struct V_313 * V_314 , T_1 V_37 , int V_40 )
{
int V_315 = ( V_37 >> 7 ) & 1 , V_316 = V_37 & 0x3f ;
return ( V_37 & V_314 -> V_317 [ V_315 ] [ V_40 - 1 ] ) |
( ( V_314 -> V_318 & ( 1ull << V_316 ) ) != 0 ) ;
}
static bool F_300 ( struct V_319 * V_196 , T_1 V_43 , int V_40 )
{
return F_299 ( & V_196 -> V_320 , V_43 , V_40 ) ;
}
static bool F_301 ( struct V_319 * V_196 , T_1 V_10 , int V_40 )
{
return F_299 ( & V_196 -> V_321 , V_10 , V_40 ) ;
}
static bool F_302 ( struct V_11 * V_12 , T_1 V_227 , bool V_91 )
{
if ( V_91 )
return F_303 ( V_12 , V_227 ) ;
return F_304 ( V_12 , V_227 ) ;
}
static bool
F_305 ( struct V_11 * V_12 , T_1 V_227 , T_1 * V_14 )
{
struct V_226 V_150 ;
T_1 V_125 [ V_231 ] , V_10 = 0ull ;
int V_294 , V_322 ;
bool V_323 = false ;
if ( ! F_260 ( V_12 -> V_34 . V_196 . V_229 ) )
goto exit;
F_52 ( V_12 ) ;
for ( F_216 ( & V_150 , V_12 , V_227 ) ,
V_322 = V_294 = V_150 . V_40 ;
F_217 ( & V_150 ) ;
F_220 ( & V_150 , V_10 ) ) {
V_10 = F_51 ( V_150 . V_14 ) ;
V_125 [ V_322 - 1 ] = V_10 ;
V_322 -- ;
if ( ! F_22 ( V_10 ) )
break;
V_323 |= F_301 ( & V_12 -> V_34 . V_196 , V_10 ,
V_150 . V_40 ) ;
}
F_55 ( V_12 ) ;
if ( V_323 ) {
F_102 ( L_26 ,
V_143 , V_227 ) ;
while ( V_294 > V_322 ) {
F_102 ( L_27 ,
V_125 [ V_294 - 1 ] , V_294 ) ;
V_294 -- ;
}
}
exit:
* V_14 = V_10 ;
return V_323 ;
}
int F_306 ( struct V_11 * V_12 , T_1 V_227 , bool V_91 )
{
T_1 V_10 ;
bool V_323 ;
if ( F_302 ( V_12 , V_227 , V_91 ) )
return V_324 ;
V_323 = F_305 ( V_12 , V_227 , & V_10 ) ;
if ( F_3 ( V_323 ) )
return V_325 ;
if ( F_10 ( V_10 ) ) {
T_2 V_15 = F_11 ( V_10 ) ;
unsigned V_16 = F_12 ( V_10 ) ;
if ( ! F_16 ( V_12 , V_10 ) )
return V_326 ;
if ( V_91 )
V_227 = 0 ;
F_307 ( V_227 , V_15 , V_16 ) ;
F_275 ( V_12 , V_227 , V_15 , V_16 ) ;
return V_324 ;
}
return V_327 ;
}
static bool F_308 ( struct V_11 * V_12 ,
T_4 V_287 , T_2 V_15 )
{
if ( F_14 ( V_287 & V_288 ) )
return false ;
if ( ! ( V_287 & V_289 ) ||
! ( V_287 & V_290 ) )
return false ;
if ( F_243 ( V_12 , V_15 , V_109 ) )
return true ;
return false ;
}
static void F_309 ( struct V_11 * V_12 , T_6 V_227 )
{
struct V_226 V_150 ;
T_1 V_10 ;
if ( ! F_260 ( V_12 -> V_34 . V_196 . V_229 ) )
return;
F_52 ( V_12 ) ;
F_280 (vcpu, addr, iterator, spte) {
F_209 ( V_150 . V_14 ) ;
if ( ! F_22 ( V_10 ) )
break;
}
F_55 ( V_12 ) ;
}
static int F_310 ( struct V_11 * V_12 , T_6 V_182 ,
T_4 V_287 , bool V_262 )
{
T_2 V_15 = V_182 >> V_19 ;
int V_80 ;
F_239 ( L_28 , V_143 , V_182 , V_287 ) ;
if ( F_308 ( V_12 , V_287 , V_15 ) )
return 1 ;
V_80 = F_68 ( V_12 ) ;
if ( V_80 )
return V_80 ;
F_161 ( ! F_260 ( V_12 -> V_34 . V_196 . V_229 ) ) ;
return F_282 ( V_12 , V_182 & V_20 ,
V_287 , V_15 , V_262 ) ;
}
static int F_311 ( struct V_11 * V_12 , T_6 V_182 , T_2 V_15 )
{
struct V_328 V_34 ;
V_34 . V_329 = ( V_12 -> V_34 . V_330 . V_331 ++ << 12 ) | V_12 -> V_332 ;
V_34 . V_15 = V_15 ;
V_34 . V_217 = V_12 -> V_34 . V_196 . V_217 ;
V_34 . V_333 = V_12 -> V_34 . V_196 . V_300 ( V_12 ) ;
return F_312 ( V_12 , V_182 , F_266 ( V_12 , V_15 ) , & V_34 ) ;
}
static bool F_313 ( struct V_11 * V_12 )
{
if ( F_14 ( ! F_314 ( V_12 ) ||
F_315 ( V_12 ) ) )
return false ;
return V_119 -> V_334 ( V_12 ) ;
}
static bool F_283 ( struct V_11 * V_12 , bool V_262 , T_2 V_15 ,
T_6 V_182 , T_3 * V_21 , bool V_260 , bool * V_335 )
{
struct V_95 * V_96 ;
bool V_336 ;
V_96 = F_89 ( V_12 , V_15 ) ;
V_336 = false ;
* V_21 = F_316 ( V_96 , V_15 , false , & V_336 , V_260 , V_335 ) ;
if ( ! V_336 )
return false ;
if ( ! V_262 && F_313 ( V_12 ) ) {
F_317 ( V_182 , V_15 ) ;
if ( F_318 ( V_12 , V_15 ) ) {
F_319 ( V_182 , V_15 ) ;
F_192 ( V_337 , V_12 ) ;
return true ;
} else if ( F_311 ( V_12 , V_182 , V_15 ) )
return true ;
}
* V_21 = F_316 ( V_96 , V_15 , false , NULL , V_260 , V_335 ) ;
return false ;
}
static bool
F_320 ( struct V_11 * V_12 , T_2 V_15 , int V_40 )
{
int V_338 = F_270 ( V_40 ) ;
V_15 &= ~ ( V_338 - 1 ) ;
return F_321 ( V_12 , V_15 , V_338 ) ;
}
static int F_322 ( struct V_11 * V_12 , T_6 V_339 , T_4 V_287 ,
bool V_262 )
{
T_3 V_21 ;
int V_80 ;
int V_40 ;
bool V_116 ;
T_2 V_15 = V_339 >> V_19 ;
unsigned long V_292 ;
int V_260 = V_287 & V_290 ;
bool V_261 ;
F_161 ( ! F_260 ( V_12 -> V_34 . V_196 . V_229 ) ) ;
if ( F_308 ( V_12 , V_287 , V_15 ) )
return 1 ;
V_80 = F_68 ( V_12 ) ;
if ( V_80 )
return V_80 ;
V_116 = ! F_320 ( V_12 , V_15 ,
V_102 ) ;
V_40 = F_95 ( V_12 , V_15 , & V_116 ) ;
if ( F_18 ( ! V_116 ) ) {
if ( V_40 > V_102 &&
! F_320 ( V_12 , V_15 , V_40 ) )
V_40 = V_102 ;
V_15 &= ~ ( F_270 ( V_40 ) - 1 ) ;
}
if ( F_279 ( V_12 , V_339 , V_40 , V_287 ) )
return 0 ;
V_292 = V_12 -> V_105 -> V_170 ;
F_37 () ;
if ( F_283 ( V_12 , V_262 , V_15 , V_339 , & V_21 , V_260 , & V_261 ) )
return 0 ;
if ( F_273 ( V_12 , 0 , V_15 , V_21 , V_264 , & V_80 ) )
return V_80 ;
F_236 ( & V_12 -> V_105 -> V_209 ) ;
if ( F_284 ( V_12 -> V_105 , V_292 ) )
goto V_293;
F_285 ( V_12 ) ;
if ( F_18 ( ! V_116 ) )
F_267 ( V_12 , & V_15 , & V_21 , & V_40 ) ;
V_80 = F_259 ( V_12 , V_260 , V_261 , V_40 , V_15 , V_21 , V_262 ) ;
F_237 ( & V_12 -> V_105 -> V_209 ) ;
return V_80 ;
V_293:
F_237 ( & V_12 -> V_105 -> V_209 ) ;
F_251 ( V_21 ) ;
return 0 ;
}
static void F_323 ( struct V_11 * V_12 ,
struct V_319 * V_340 )
{
V_340 -> V_341 = F_310 ;
V_340 -> V_342 = F_297 ;
V_340 -> V_197 = F_175 ;
V_340 -> V_343 = F_176 ;
V_340 -> V_344 = F_177 ;
V_340 -> V_218 = 0 ;
V_340 -> V_230 = V_232 ;
V_340 -> V_229 = V_295 ;
V_340 -> V_217 = true ;
V_340 -> V_345 = false ;
}
void F_324 ( struct V_11 * V_12 )
{
F_286 ( V_12 ) ;
}
static unsigned long V_300 ( struct V_11 * V_12 )
{
return F_325 ( V_12 ) ;
}
static void F_326 ( struct V_11 * V_12 ,
struct V_309 * V_346 )
{
V_12 -> V_34 . V_196 . F_326 ( V_12 , V_346 ) ;
}
static bool F_327 ( struct V_11 * V_12 , T_1 * V_14 , T_2 V_15 ,
unsigned V_16 , int * V_347 )
{
if ( F_14 ( F_10 ( * V_14 ) ) ) {
if ( V_15 != F_11 ( * V_14 ) ) {
F_50 ( V_14 ) ;
return true ;
}
( * V_347 ) ++ ;
F_7 ( V_12 , V_14 , V_15 , V_16 ) ;
return true ;
}
return false ;
}
static inline bool F_328 ( struct V_319 * V_196 ,
unsigned V_40 , unsigned V_43 )
{
V_43 |= V_40 - V_41 - 1 ;
V_43 &= V_40 - V_196 -> V_348 ;
return V_43 & V_39 ;
}
static void
F_329 ( struct V_11 * V_12 ,
struct V_313 * V_314 ,
int V_349 , int V_40 , bool V_345 , bool V_350 ,
bool V_351 , bool V_352 )
{
T_1 V_353 = 0 ;
T_1 V_354 = 0 ;
T_1 V_355 = 0 ;
V_314 -> V_318 = 0 ;
if ( ! V_345 )
V_353 = F_330 ( 63 , 63 ) ;
if ( ! V_350 )
V_354 = F_330 ( 7 , 7 ) ;
if ( V_352 )
V_355 = F_330 ( 8 , 8 ) ;
switch ( V_40 ) {
case V_219 :
V_314 -> V_317 [ 0 ] [ 1 ] = 0 ;
V_314 -> V_317 [ 0 ] [ 0 ] = 0 ;
V_314 -> V_317 [ 1 ] [ 0 ] =
V_314 -> V_317 [ 0 ] [ 0 ] ;
if ( ! V_351 ) {
V_314 -> V_317 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_20 () )
V_314 -> V_317 [ 1 ] [ 1 ] = F_330 ( 17 , 21 ) ;
else
V_314 -> V_317 [ 1 ] [ 1 ] = F_330 ( 13 , 21 ) ;
break;
case V_232 :
V_314 -> V_317 [ 0 ] [ 2 ] =
F_330 ( V_349 , 63 ) |
F_330 ( 5 , 8 ) | F_330 ( 1 , 2 ) ;
V_314 -> V_317 [ 0 ] [ 1 ] = V_353 |
F_330 ( V_349 , 62 ) ;
V_314 -> V_317 [ 0 ] [ 0 ] = V_353 |
F_330 ( V_349 , 62 ) ;
V_314 -> V_317 [ 1 ] [ 1 ] = V_353 |
F_330 ( V_349 , 62 ) |
F_330 ( 13 , 20 ) ;
V_314 -> V_317 [ 1 ] [ 0 ] =
V_314 -> V_317 [ 0 ] [ 0 ] ;
break;
case V_231 :
V_314 -> V_317 [ 0 ] [ 3 ] = V_353 |
V_355 | F_330 ( 7 , 7 ) |
F_330 ( V_349 , 51 ) ;
V_314 -> V_317 [ 0 ] [ 2 ] = V_353 |
V_355 | V_354 |
F_330 ( V_349 , 51 ) ;
V_314 -> V_317 [ 0 ] [ 1 ] = V_353 |
F_330 ( V_349 , 51 ) ;
V_314 -> V_317 [ 0 ] [ 0 ] = V_353 |
F_330 ( V_349 , 51 ) ;
V_314 -> V_317 [ 1 ] [ 3 ] =
V_314 -> V_317 [ 0 ] [ 3 ] ;
V_314 -> V_317 [ 1 ] [ 2 ] = V_353 |
V_354 | F_330 ( V_349 , 51 ) |
F_330 ( 13 , 29 ) ;
V_314 -> V_317 [ 1 ] [ 1 ] = V_353 |
F_330 ( V_349 , 51 ) |
F_330 ( 13 , 20 ) ;
V_314 -> V_317 [ 1 ] [ 0 ] =
V_314 -> V_317 [ 0 ] [ 0 ] ;
break;
}
}
static void F_331 ( struct V_11 * V_12 ,
struct V_319 * V_340 )
{
F_329 ( V_12 , & V_340 -> V_320 ,
F_332 ( V_12 ) , V_340 -> V_218 ,
V_340 -> V_345 , F_333 ( V_12 ) ,
F_334 ( V_12 ) , F_335 ( V_12 ) ) ;
}
static void
F_336 ( struct V_313 * V_314 ,
int V_349 , bool V_356 )
{
T_1 V_318 ;
V_314 -> V_317 [ 0 ] [ 3 ] =
F_330 ( V_349 , 51 ) | F_330 ( 3 , 7 ) ;
V_314 -> V_317 [ 0 ] [ 2 ] =
F_330 ( V_349 , 51 ) | F_330 ( 3 , 6 ) ;
V_314 -> V_317 [ 0 ] [ 1 ] =
F_330 ( V_349 , 51 ) | F_330 ( 3 , 6 ) ;
V_314 -> V_317 [ 0 ] [ 0 ] = F_330 ( V_349 , 51 ) ;
V_314 -> V_317 [ 1 ] [ 3 ] = V_314 -> V_317 [ 0 ] [ 3 ] ;
V_314 -> V_317 [ 1 ] [ 2 ] =
F_330 ( V_349 , 51 ) | F_330 ( 12 , 29 ) ;
V_314 -> V_317 [ 1 ] [ 1 ] =
F_330 ( V_349 , 51 ) | F_330 ( 12 , 20 ) ;
V_314 -> V_317 [ 1 ] [ 0 ] = V_314 -> V_317 [ 0 ] [ 0 ] ;
V_318 = 0xFFull << ( 2 * 8 ) ;
V_318 |= 0xFFull << ( 3 * 8 ) ;
V_318 |= 0xFFull << ( 7 * 8 ) ;
V_318 |= F_337 ( 1ull << 2 ) ;
V_318 |= F_337 ( 1ull << 6 ) ;
if ( ! V_356 ) {
V_318 |= F_337 ( 1ull << 4 ) ;
}
V_314 -> V_318 = V_318 ;
}
static void F_338 ( struct V_11 * V_12 ,
struct V_319 * V_340 , bool V_356 )
{
F_336 ( & V_340 -> V_320 ,
F_332 ( V_12 ) , V_356 ) ;
}
void
F_339 ( struct V_11 * V_12 , struct V_319 * V_340 )
{
bool V_357 = V_340 -> V_345 || V_340 -> V_216 . V_358 ;
F_329 ( V_12 , & V_340 -> V_321 ,
V_359 . V_360 ,
V_340 -> V_230 , V_357 ,
F_333 ( V_12 ) , F_334 ( V_12 ) ,
true ) ;
}
static inline bool F_340 ( void )
{
F_341 ( ! V_250 ) ;
return V_33 == 0 ;
}
static void
F_342 ( struct V_11 * V_12 ,
struct V_319 * V_340 )
{
if ( F_340 () )
F_329 ( V_12 , & V_340 -> V_321 ,
V_359 . V_360 ,
V_340 -> V_230 , false ,
V_361 , true , true ) ;
else
F_336 ( & V_340 -> V_321 ,
V_359 . V_360 ,
false ) ;
}
static void
F_343 ( struct V_11 * V_12 ,
struct V_319 * V_340 , bool V_356 )
{
F_336 ( & V_340 -> V_321 ,
V_359 . V_360 , V_356 ) ;
}
static void F_344 ( struct V_11 * V_12 ,
struct V_319 * V_196 , bool V_362 )
{
unsigned V_363 , V_364 , V_365 ;
T_10 V_366 ;
bool V_346 , V_367 , V_368 , V_369 , V_370 , V_371 , V_372 , V_373 , V_374 , V_375 , V_376 = 0 ;
V_375 = F_345 ( V_12 , V_377 ) ;
V_374 = F_345 ( V_12 , V_378 ) ;
for ( V_364 = 0 ; V_364 < F_59 ( V_196 -> V_379 ) ; ++ V_364 ) {
V_365 = V_364 << 1 ;
V_366 = 0 ;
V_370 = V_365 & V_290 ;
V_371 = V_365 & V_380 ;
V_372 = V_365 & V_381 ;
V_373 = ! ( V_365 & V_288 ) ;
for ( V_363 = 0 ; V_363 < 8 ; ++ V_363 ) {
V_367 = V_363 & V_249 ;
V_368 = V_363 & V_17 ;
V_369 = V_363 & V_18 ;
if ( ! V_362 ) {
V_367 |= ! V_196 -> V_345 ;
V_368 |= ! F_346 ( V_12 ) && ! V_371 ;
V_367 &= ! ( V_375 && V_369 && ! V_371 ) ;
V_376 = V_374 && V_369 && ! V_371 && ! V_372 ;
} else
V_369 = 1 ;
V_346 = ( V_372 && ! V_367 ) || ( V_371 && ! V_369 ) || ( V_370 && ! V_368 ) ||
( V_373 && V_376 ) ;
V_366 |= V_346 << V_363 ;
}
V_196 -> V_379 [ V_364 ] = V_366 ;
}
}
static void F_347 ( struct V_11 * V_12 , struct V_319 * V_196 ,
bool V_362 )
{
unsigned V_363 ;
bool V_382 ;
if ( V_362 ) {
V_196 -> V_383 = 0 ;
return;
}
if ( ! F_345 ( V_12 , V_384 ) || ! F_348 ( V_12 ) ) {
V_196 -> V_383 = 0 ;
return;
}
V_382 = F_346 ( V_12 ) ;
for ( V_363 = 0 ; V_363 < F_59 ( V_196 -> V_379 ) ; ++ V_363 ) {
unsigned V_365 , V_385 ;
bool V_386 , V_387 , V_372 , V_371 , V_370 , V_388 ;
V_365 = V_363 << 1 ;
V_372 = V_365 & V_381 ;
V_371 = V_365 & V_380 ;
V_370 = V_365 & V_290 ;
V_388 = V_365 & V_288 ;
V_386 = ( ! V_372 && V_388 ) ;
V_387 = V_386 && V_370 && ( V_371 || V_382 ) ;
V_385 = ! ! V_386 ;
V_385 |= ( ! ! V_387 ) << 1 ;
V_196 -> V_383 |= ( V_385 & 3 ) << V_365 ;
}
}
static void F_349 ( struct V_11 * V_12 , struct V_319 * V_196 )
{
unsigned V_218 = V_196 -> V_218 ;
V_196 -> V_348 = V_218 ;
if ( V_218 == V_219 && F_334 ( V_12 ) )
V_196 -> V_348 ++ ;
}
static void F_350 ( struct V_11 * V_12 ,
struct V_319 * V_340 ,
int V_40 )
{
V_340 -> V_345 = F_21 ( V_12 ) ;
V_340 -> V_218 = V_40 ;
F_331 ( V_12 , V_340 ) ;
F_344 ( V_12 , V_340 , false ) ;
F_347 ( V_12 , V_340 , false ) ;
F_349 ( V_12 , V_340 ) ;
F_161 ( ! F_187 ( V_12 ) ) ;
V_340 -> V_341 = V_389 ;
V_340 -> V_342 = V_390 ;
V_340 -> V_197 = V_391 ;
V_340 -> V_343 = V_392 ;
V_340 -> V_344 = V_393 ;
V_340 -> V_230 = V_40 ;
V_340 -> V_229 = V_295 ;
V_340 -> V_217 = false ;
}
static void F_351 ( struct V_11 * V_12 ,
struct V_319 * V_340 )
{
F_350 ( V_12 , V_340 , V_231 ) ;
}
static void F_352 ( struct V_11 * V_12 ,
struct V_319 * V_340 )
{
V_340 -> V_345 = false ;
V_340 -> V_218 = V_219 ;
F_331 ( V_12 , V_340 ) ;
F_344 ( V_12 , V_340 , false ) ;
F_347 ( V_12 , V_340 , false ) ;
F_349 ( V_12 , V_340 ) ;
V_340 -> V_341 = V_394 ;
V_340 -> V_342 = V_395 ;
V_340 -> V_197 = V_396 ;
V_340 -> V_343 = V_397 ;
V_340 -> V_344 = V_398 ;
V_340 -> V_230 = V_232 ;
V_340 -> V_229 = V_295 ;
V_340 -> V_217 = false ;
}
static void F_353 ( struct V_11 * V_12 ,
struct V_319 * V_340 )
{
F_350 ( V_12 , V_340 , V_232 ) ;
}
static void F_354 ( struct V_11 * V_12 )
{
struct V_319 * V_340 = & V_12 -> V_34 . V_196 ;
V_340 -> V_216 . V_222 = 0 ;
V_340 -> V_216 . V_399 = F_355 ( V_12 ) ;
V_340 -> V_341 = F_322 ;
V_340 -> V_197 = F_175 ;
V_340 -> V_343 = F_176 ;
V_340 -> V_344 = F_177 ;
V_340 -> V_230 = V_119 -> V_400 () ;
V_340 -> V_229 = V_295 ;
V_340 -> V_217 = true ;
V_340 -> V_401 = V_119 -> V_402 ;
V_340 -> V_300 = V_300 ;
V_340 -> V_303 = V_403 ;
V_340 -> F_326 = V_404 ;
if ( ! F_356 ( V_12 ) ) {
V_340 -> V_345 = false ;
V_340 -> V_342 = F_297 ;
V_340 -> V_218 = 0 ;
} else if ( F_348 ( V_12 ) ) {
V_340 -> V_345 = F_21 ( V_12 ) ;
V_340 -> V_218 = V_231 ;
F_331 ( V_12 , V_340 ) ;
V_340 -> V_342 = V_390 ;
} else if ( F_187 ( V_12 ) ) {
V_340 -> V_345 = F_21 ( V_12 ) ;
V_340 -> V_218 = V_232 ;
F_331 ( V_12 , V_340 ) ;
V_340 -> V_342 = V_390 ;
} else {
V_340 -> V_345 = false ;
V_340 -> V_218 = V_219 ;
F_331 ( V_12 , V_340 ) ;
V_340 -> V_342 = V_395 ;
}
F_344 ( V_12 , V_340 , false ) ;
F_347 ( V_12 , V_340 , false ) ;
F_349 ( V_12 , V_340 ) ;
F_342 ( V_12 , V_340 ) ;
}
void F_357 ( struct V_11 * V_12 )
{
bool V_405 = F_345 ( V_12 , V_377 ) ;
bool V_376 = F_345 ( V_12 , V_378 ) ;
struct V_319 * V_340 = & V_12 -> V_34 . V_196 ;
F_161 ( F_260 ( V_340 -> V_229 ) ) ;
if ( ! F_356 ( V_12 ) )
F_323 ( V_12 , V_340 ) ;
else if ( F_348 ( V_12 ) )
F_351 ( V_12 , V_340 ) ;
else if ( F_187 ( V_12 ) )
F_353 ( V_12 , V_340 ) ;
else
F_352 ( V_12 , V_340 ) ;
V_340 -> V_216 . V_406 = F_21 ( V_12 ) ;
V_340 -> V_216 . V_195 = ! ! F_187 ( V_12 ) ;
V_340 -> V_216 . V_407 = F_346 ( V_12 ) ;
V_340 -> V_216 . V_358
= V_405 && ! F_346 ( V_12 ) ;
V_340 -> V_216 . V_408
= V_376 && ! F_346 ( V_12 ) ;
V_340 -> V_216 . V_399 = F_355 ( V_12 ) ;
F_339 ( V_12 , V_340 ) ;
}
void F_358 ( struct V_11 * V_12 , bool V_356 )
{
struct V_319 * V_340 = & V_12 -> V_34 . V_196 ;
F_161 ( F_260 ( V_340 -> V_229 ) ) ;
V_340 -> V_230 = V_119 -> V_400 () ;
V_340 -> V_345 = true ;
V_340 -> V_341 = V_409 ;
V_340 -> V_342 = V_410 ;
V_340 -> V_197 = V_411 ;
V_340 -> V_343 = V_412 ;
V_340 -> V_344 = V_413 ;
V_340 -> V_218 = V_340 -> V_230 ;
V_340 -> V_229 = V_295 ;
V_340 -> V_217 = false ;
F_344 ( V_12 , V_340 , true ) ;
F_347 ( V_12 , V_340 , true ) ;
F_338 ( V_12 , V_340 , V_356 ) ;
F_343 ( V_12 , V_340 , V_356 ) ;
}
static void F_359 ( struct V_11 * V_12 )
{
struct V_319 * V_340 = & V_12 -> V_34 . V_196 ;
F_357 ( V_12 ) ;
V_340 -> V_401 = V_119 -> V_401 ;
V_340 -> V_300 = V_300 ;
V_340 -> V_303 = V_403 ;
V_340 -> F_326 = V_404 ;
}
static void F_360 ( struct V_11 * V_12 )
{
struct V_319 * V_414 = & V_12 -> V_34 . V_311 ;
V_414 -> V_300 = V_300 ;
V_414 -> V_303 = V_403 ;
V_414 -> F_326 = V_404 ;
if ( ! F_356 ( V_12 ) ) {
V_414 -> V_345 = false ;
V_414 -> V_218 = 0 ;
V_414 -> V_342 = F_298 ;
} else if ( F_348 ( V_12 ) ) {
V_414 -> V_345 = F_21 ( V_12 ) ;
V_414 -> V_218 = V_231 ;
F_331 ( V_12 , V_414 ) ;
V_414 -> V_342 = V_415 ;
} else if ( F_187 ( V_12 ) ) {
V_414 -> V_345 = F_21 ( V_12 ) ;
V_414 -> V_218 = V_232 ;
F_331 ( V_12 , V_414 ) ;
V_414 -> V_342 = V_415 ;
} else {
V_414 -> V_345 = false ;
V_414 -> V_218 = V_219 ;
F_331 ( V_12 , V_414 ) ;
V_414 -> V_342 = V_416 ;
}
F_344 ( V_12 , V_414 , false ) ;
F_347 ( V_12 , V_414 , false ) ;
F_349 ( V_12 , V_414 ) ;
}
static void F_361 ( struct V_11 * V_12 )
{
if ( F_362 ( V_12 ) )
F_360 ( V_12 ) ;
else if ( V_250 )
F_354 ( V_12 ) ;
else
F_359 ( V_12 ) ;
}
void F_363 ( struct V_11 * V_12 )
{
F_364 ( V_12 ) ;
F_361 ( V_12 ) ;
}
int F_365 ( struct V_11 * V_12 )
{
int V_80 ;
V_80 = F_68 ( V_12 ) ;
if ( V_80 )
goto V_84;
V_80 = F_293 ( V_12 ) ;
F_296 ( V_12 ) ;
if ( V_80 )
goto V_84;
V_12 -> V_34 . V_196 . V_401 ( V_12 , V_12 -> V_34 . V_196 . V_229 ) ;
V_84:
return V_80 ;
}
void F_364 ( struct V_11 * V_12 )
{
F_286 ( V_12 ) ;
F_3 ( F_260 ( V_12 -> V_34 . V_196 . V_229 ) ) ;
}
static void F_366 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_10 ,
const void * V_417 )
{
if ( V_48 -> V_90 . V_40 != V_41 ) {
++ V_12 -> V_105 -> V_136 . V_418 ;
return;
}
++ V_12 -> V_105 -> V_136 . V_419 ;
V_12 -> V_34 . V_196 . V_344 ( V_12 , V_48 , V_10 , V_417 ) ;
}
static bool F_367 ( T_1 V_420 , T_1 V_417 )
{
if ( ! F_22 ( V_420 ) )
return false ;
if ( ! F_22 ( V_417 ) )
return true ;
if ( ( V_420 ^ V_417 ) & V_42 )
return true ;
V_420 ^= V_32 ;
V_417 ^= V_32 ;
return ( V_420 & ~ V_417 & V_421 ) != 0 ;
}
static T_1 F_368 ( struct V_11 * V_12 , T_9 * V_339 ,
const T_10 * V_417 , int * V_422 )
{
T_1 V_423 ;
int V_80 ;
if ( F_187 ( V_12 ) && * V_422 == 4 ) {
* V_339 &= ~ ( T_9 ) 7 ;
* V_422 = 8 ;
V_80 = F_369 ( V_12 , * V_339 , & V_423 , 8 ) ;
if ( V_80 )
V_423 = 0 ;
V_417 = ( const T_10 * ) & V_423 ;
}
switch ( * V_422 ) {
case 4 :
V_423 = * ( const T_4 * ) V_417 ;
break;
case 8 :
V_423 = * ( const T_1 * ) V_417 ;
break;
default:
V_423 = 0 ;
break;
}
return V_423 ;
}
static bool F_370 ( struct V_47 * V_48 )
{
if ( V_48 -> V_90 . V_40 == V_41 )
return false ;
F_371 ( & V_48 -> V_210 ) ;
return F_372 ( & V_48 -> V_210 ) >= 3 ;
}
static bool F_373 ( struct V_47 * V_48 , T_9 V_339 ,
int V_422 )
{
unsigned V_424 , V_425 , V_426 ;
F_239 ( L_29 ,
V_339 , V_422 , V_48 -> V_90 . V_222 ) ;
V_424 = F_374 ( V_339 ) ;
V_425 = V_48 -> V_90 . V_195 ? 8 : 4 ;
if ( ! ( V_424 & ( V_425 - 1 ) ) && V_422 == 1 )
return false ;
V_426 = ( V_424 ^ ( V_424 + V_422 - 1 ) ) & ~ ( V_425 - 1 ) ;
V_426 |= V_422 < 4 ;
return V_426 ;
}
static T_1 * F_375 ( struct V_47 * V_48 , T_9 V_339 , int * V_427 )
{
unsigned V_428 , V_214 ;
T_1 * V_10 ;
int V_40 ;
V_428 = F_374 ( V_339 ) ;
V_40 = V_48 -> V_90 . V_40 ;
* V_427 = 1 ;
if ( ! V_48 -> V_90 . V_195 ) {
V_428 <<= 1 ;
if ( V_40 == V_219 ) {
V_428 &= ~ 7 ;
V_428 <<= 1 ;
* V_427 = 2 ;
}
V_214 = V_428 >> V_19 ;
V_428 &= ~ V_20 ;
if ( V_214 != V_48 -> V_90 . V_214 )
return NULL ;
}
V_10 = & V_48 -> V_132 [ V_428 / sizeof( * V_10 ) ] ;
return V_10 ;
}
static void F_376 ( struct V_11 * V_12 , T_9 V_339 ,
const T_10 * V_417 , int V_422 )
{
T_2 V_15 = V_339 >> V_19 ;
struct V_47 * V_48 ;
F_202 ( V_194 ) ;
T_1 V_429 , V_423 , * V_10 ;
int V_430 ;
bool V_198 , V_199 ;
union V_213 V_4 = { } ;
V_4 . V_407 = 1 ;
V_4 . V_195 = 1 ;
V_4 . V_406 = 1 ;
V_4 . V_358 = 1 ;
V_4 . V_408 = 1 ;
V_4 . V_399 = 1 ;
if ( ! F_32 ( V_12 -> V_105 -> V_34 . V_108 ) )
return;
V_198 = V_199 = false ;
F_239 ( L_30 , V_143 , V_339 , V_422 ) ;
V_423 = F_368 ( V_12 , & V_339 , V_417 , & V_422 ) ;
F_68 ( V_12 ) ;
F_236 ( & V_12 -> V_105 -> V_209 ) ;
++ V_12 -> V_105 -> V_136 . V_431 ;
F_193 ( V_12 , V_432 ) ;
F_197 (vcpu->kvm, sp, gfn) {
if ( F_373 ( V_48 , V_339 , V_422 ) ||
F_370 ( V_48 ) ) {
F_188 ( V_12 -> V_105 , V_48 , & V_194 ) ;
++ V_12 -> V_105 -> V_136 . V_433 ;
continue;
}
V_10 = F_375 ( V_48 , V_339 , & V_430 ) ;
if ( ! V_10 )
continue;
V_199 = true ;
while ( V_430 -- ) {
V_429 = * V_10 ;
F_225 ( V_12 -> V_105 , V_48 , V_10 ) ;
if ( V_423 &&
! ( ( V_48 -> V_90 . V_222 ^ V_12 -> V_34 . V_196 . V_216 . V_222 )
& V_4 . V_222 ) && F_105 ( V_12 ) )
F_366 ( V_12 , V_48 , V_10 , & V_423 ) ;
if ( F_367 ( V_429 , * V_10 ) )
V_198 = true ;
++ V_10 ;
}
}
F_189 ( V_12 , & V_194 , V_198 , V_199 ) ;
F_193 ( V_12 , V_434 ) ;
F_237 ( & V_12 -> V_105 -> V_209 ) ;
}
int F_377 ( struct V_11 * V_12 , T_6 V_182 )
{
T_9 V_339 ;
int V_80 ;
if ( V_12 -> V_34 . V_196 . V_217 )
return 0 ;
V_339 = F_378 ( V_12 , V_182 , NULL ) ;
V_80 = F_238 ( V_12 -> V_105 , V_339 >> V_19 ) ;
return V_80 ;
}
static void F_285 ( struct V_11 * V_12 )
{
F_202 ( V_194 ) ;
if ( F_18 ( F_379 ( V_12 -> V_105 ) >= V_435 ) )
return;
while ( F_379 ( V_12 -> V_105 ) < V_436 ) {
if ( ! F_233 ( V_12 -> V_105 , & V_194 ) )
break;
++ V_12 -> V_105 -> V_136 . V_437 ;
}
F_191 ( V_12 -> V_105 , & V_194 ) ;
}
int F_380 ( struct V_11 * V_12 , T_6 V_438 , T_4 V_287 ,
void * V_439 , int V_440 )
{
int V_80 , V_441 = V_442 ;
enum V_443 V_444 ;
bool V_91 = V_12 -> V_34 . V_196 . V_217 || F_362 ( V_12 ) ;
if ( F_14 ( V_287 & V_288 ) ) {
V_80 = F_306 ( V_12 , V_438 , V_91 ) ;
if ( V_80 == V_324 ) {
V_441 = 0 ;
goto V_257;
}
if ( V_80 == V_327 )
return 1 ;
if ( V_80 < 0 )
return V_80 ;
}
V_80 = V_12 -> V_34 . V_196 . V_341 ( V_12 , V_438 , V_287 , false ) ;
if ( V_80 < 0 )
return V_80 ;
if ( ! V_80 )
return 1 ;
if ( F_302 ( V_12 , V_438 , V_91 ) )
V_441 = 0 ;
V_257:
V_444 = F_381 ( V_12 , V_438 , V_441 , V_439 , V_440 ) ;
switch ( V_444 ) {
case V_445 :
return 1 ;
case V_446 :
++ V_12 -> V_136 . V_447 ;
case V_448 :
return 0 ;
default:
F_101 () ;
}
}
void F_382 ( struct V_11 * V_12 , T_6 V_182 )
{
V_12 -> V_34 . V_196 . V_343 ( V_12 , V_182 ) ;
F_192 ( V_200 , V_12 ) ;
++ V_12 -> V_136 . V_343 ;
}
void F_383 ( void )
{
V_250 = true ;
}
void F_384 ( void )
{
V_250 = false ;
}
static void F_385 ( struct V_11 * V_12 )
{
F_67 ( ( unsigned long ) V_12 -> V_34 . V_196 . V_233 ) ;
if ( V_12 -> V_34 . V_196 . V_304 != NULL )
F_67 ( ( unsigned long ) V_12 -> V_34 . V_196 . V_304 ) ;
}
static int F_386 ( struct V_11 * V_12 )
{
struct V_79 * V_79 ;
int V_101 ;
V_79 = F_387 ( V_76 | V_449 ) ;
if ( ! V_79 )
return - V_77 ;
V_12 -> V_34 . V_196 . V_233 = F_388 ( V_79 ) ;
for ( V_101 = 0 ; V_101 < 4 ; ++ V_101 )
V_12 -> V_34 . V_196 . V_233 [ V_101 ] = V_295 ;
return 0 ;
}
int F_389 ( struct V_11 * V_12 )
{
V_12 -> V_34 . V_450 = & V_12 -> V_34 . V_196 ;
V_12 -> V_34 . V_196 . V_229 = V_295 ;
V_12 -> V_34 . V_196 . V_312 = V_312 ;
V_12 -> V_34 . V_311 . V_312 = V_451 ;
return F_386 ( V_12 ) ;
}
void F_390 ( struct V_11 * V_12 )
{
F_161 ( F_260 ( V_12 -> V_34 . V_196 . V_229 ) ) ;
F_361 ( V_12 ) ;
}
void F_391 ( struct V_105 * V_105 )
{
struct V_452 * V_453 = & V_105 -> V_34 . V_454 ;
V_453 -> V_455 = F_376 ;
F_392 ( V_105 , V_453 ) ;
}
void F_393 ( struct V_105 * V_105 )
{
struct V_452 * V_453 = & V_105 -> V_34 . V_454 ;
F_394 ( V_105 , V_453 ) ;
}
static bool
F_395 ( struct V_105 * V_105 , struct V_95 * V_158 ,
T_11 V_456 , int V_154 , int V_155 ,
T_2 V_151 , T_2 V_153 , bool V_457 )
{
struct V_149 V_150 ;
bool V_139 = false ;
F_144 (memslot, start_level, end_level, start_gfn,
end_gfn, &iterator) {
if ( V_150 . V_131 )
V_139 |= V_456 ( V_105 , V_150 . V_131 ) ;
if ( F_204 () || F_205 ( & V_105 -> V_209 ) ) {
if ( V_139 && V_457 ) {
F_113 ( V_105 ) ;
V_139 = false ;
}
F_206 ( & V_105 -> V_209 ) ;
}
}
if ( V_139 && V_457 ) {
F_113 ( V_105 ) ;
V_139 = false ;
}
return V_139 ;
}
static bool
F_396 ( struct V_105 * V_105 , struct V_95 * V_158 ,
T_11 V_456 , int V_154 , int V_155 ,
bool V_457 )
{
return F_395 ( V_105 , V_158 , V_456 , V_154 ,
V_155 , V_158 -> V_98 ,
V_158 -> V_98 + V_158 -> V_165 - 1 ,
V_457 ) ;
}
static bool
F_397 ( struct V_105 * V_105 , struct V_95 * V_158 ,
T_11 V_456 , bool V_457 )
{
return F_396 ( V_105 , V_158 , V_456 , V_41 ,
V_103 , V_457 ) ;
}
static bool
F_398 ( struct V_105 * V_105 , struct V_95 * V_158 ,
T_11 V_456 , bool V_457 )
{
return F_396 ( V_105 , V_158 , V_456 , V_41 + 1 ,
V_103 , V_457 ) ;
}
static bool
F_399 ( struct V_105 * V_105 , struct V_95 * V_158 ,
T_11 V_456 , bool V_457 )
{
return F_396 ( V_105 , V_158 , V_456 , V_41 ,
V_41 , V_457 ) ;
}
void F_400 ( struct V_105 * V_105 , T_2 V_162 , T_2 V_163 )
{
struct V_106 * V_107 ;
struct V_95 * V_158 ;
int V_101 ;
F_236 ( & V_105 -> V_209 ) ;
for ( V_101 = 0 ; V_101 < V_159 ; V_101 ++ ) {
V_107 = F_140 ( V_105 , V_101 ) ;
F_141 (memslot, slots) {
T_2 V_156 , V_157 ;
V_156 = F_142 ( V_162 , V_158 -> V_98 ) ;
V_157 = V_72 ( V_163 , V_158 -> V_98 + V_158 -> V_165 ) ;
if ( V_156 >= V_157 )
continue;
F_395 ( V_105 , V_158 , F_127 ,
V_41 , V_103 ,
V_156 , V_157 - 1 , true ) ;
}
}
F_237 ( & V_105 -> V_209 ) ;
}
static bool F_401 ( struct V_105 * V_105 ,
struct V_121 * V_122 )
{
return F_115 ( V_105 , V_122 , false ) ;
}
void F_402 ( struct V_105 * V_105 ,
struct V_95 * V_158 )
{
bool V_139 ;
F_236 ( & V_105 -> V_209 ) ;
V_139 = F_397 ( V_105 , V_158 , F_401 ,
false ) ;
F_237 ( & V_105 -> V_209 ) ;
F_403 ( & V_105 -> V_458 ) ;
if ( V_139 )
F_113 ( V_105 ) ;
}
static bool F_404 ( struct V_105 * V_105 ,
struct V_121 * V_122 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
int V_459 = 0 ;
T_3 V_21 ;
struct V_47 * V_48 ;
V_148:
F_116 (rmap_head, &iter, sptep) {
V_48 = F_34 ( F_35 ( V_14 ) ) ;
V_21 = F_25 ( * V_14 ) ;
if ( V_48 -> V_90 . V_91 &&
! F_47 ( V_21 ) &&
F_269 ( F_49 ( V_21 ) ) ) {
F_110 ( V_105 , V_14 ) ;
V_459 = 1 ;
goto V_148;
}
}
return V_459 ;
}
void F_405 ( struct V_105 * V_105 ,
const struct V_95 * V_158 )
{
F_236 ( & V_105 -> V_209 ) ;
F_399 ( V_105 , (struct V_95 * ) V_158 ,
F_404 , true ) ;
F_237 ( & V_105 -> V_209 ) ;
}
void F_406 ( struct V_105 * V_105 ,
struct V_95 * V_158 )
{
bool V_139 ;
F_236 ( & V_105 -> V_209 ) ;
V_139 = F_399 ( V_105 , V_158 , F_118 , false ) ;
F_237 ( & V_105 -> V_209 ) ;
F_403 ( & V_105 -> V_458 ) ;
if ( V_139 )
F_113 ( V_105 ) ;
}
void F_407 ( struct V_105 * V_105 ,
struct V_95 * V_158 )
{
bool V_139 ;
F_236 ( & V_105 -> V_209 ) ;
V_139 = F_398 ( V_105 , V_158 , F_401 ,
false ) ;
F_237 ( & V_105 -> V_209 ) ;
F_403 ( & V_105 -> V_458 ) ;
if ( V_139 )
F_113 ( V_105 ) ;
}
void F_408 ( struct V_105 * V_105 ,
struct V_95 * V_158 )
{
bool V_139 ;
F_236 ( & V_105 -> V_209 ) ;
V_139 = F_397 ( V_105 , V_158 , F_120 , false ) ;
F_237 ( & V_105 -> V_209 ) ;
F_403 ( & V_105 -> V_458 ) ;
if ( V_139 )
F_113 ( V_105 ) ;
}
static void F_409 ( struct V_105 * V_105 )
{
struct V_47 * V_48 , * V_453 ;
int V_460 = 0 ;
V_148:
F_410 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_63 ;
if ( ! F_210 ( V_105 , V_48 ) )
break;
if ( V_48 -> V_90 . V_240 )
continue;
if ( V_460 >= V_461 &&
F_206 ( & V_105 -> V_209 ) ) {
V_460 = 0 ;
goto V_148;
}
V_63 = F_188 ( V_105 , V_48 ,
& V_105 -> V_34 . V_462 ) ;
V_460 += V_63 ;
if ( V_63 )
goto V_148;
}
F_191 ( V_105 , & V_105 -> V_34 . V_462 ) ;
}
void F_411 ( struct V_105 * V_105 )
{
F_236 ( & V_105 -> V_209 ) ;
F_412 ( V_105 ) ;
V_105 -> V_34 . V_211 ++ ;
F_231 ( V_105 ) ;
F_409 ( V_105 ) ;
F_237 ( & V_105 -> V_209 ) ;
}
static bool F_413 ( struct V_105 * V_105 )
{
return F_14 ( ! F_414 ( & V_105 -> V_34 . V_462 ) ) ;
}
void F_415 ( struct V_105 * V_105 , struct V_106 * V_107 )
{
if ( F_14 ( ( V_107 -> V_13 & V_5 ) == 0 ) ) {
F_416 ( V_463 L_31 ) ;
F_411 ( V_105 ) ;
}
}
static unsigned long
F_417 ( struct V_464 * V_465 , struct V_466 * V_467 )
{
struct V_105 * V_105 ;
int V_468 = V_467 -> V_468 ;
unsigned long V_469 = 0 ;
F_236 ( & V_470 ) ;
F_418 (kvm, &vm_list, vm_list) {
int V_97 ;
F_202 ( V_194 ) ;
if ( ! V_468 -- )
break;
if ( ! V_105 -> V_34 . V_172 &&
! F_413 ( V_105 ) )
continue;
V_97 = F_419 ( & V_105 -> V_471 ) ;
F_236 ( & V_105 -> V_209 ) ;
if ( F_413 ( V_105 ) ) {
F_191 ( V_105 ,
& V_105 -> V_34 . V_462 ) ;
goto V_472;
}
if ( F_233 ( V_105 , & V_194 ) )
V_469 ++ ;
F_191 ( V_105 , & V_194 ) ;
V_472:
F_237 ( & V_105 -> V_209 ) ;
F_420 ( & V_105 -> V_471 , V_97 ) ;
F_421 ( & V_105 -> V_473 , & V_473 ) ;
break;
}
F_237 ( & V_470 ) ;
return V_469 ;
}
static unsigned long
F_422 ( struct V_464 * V_465 , struct V_466 * V_467 )
{
return F_423 ( & V_173 ) ;
}
static void F_424 ( void )
{
if ( V_82 )
F_425 ( V_82 ) ;
if ( V_86 )
F_425 ( V_86 ) ;
}
int F_426 ( void )
{
V_82 = F_427 ( L_32 ,
sizeof( struct V_88 ) ,
0 , 0 , NULL ) ;
if ( ! V_82 )
goto V_474;
V_86 = F_427 ( L_33 ,
sizeof( struct V_47 ) ,
0 , 0 , NULL ) ;
if ( ! V_86 )
goto V_474;
if ( F_428 ( & V_173 , 0 , V_76 ) )
goto V_474;
F_429 ( & V_475 ) ;
return 0 ;
V_474:
F_424 () ;
return - V_77 ;
}
unsigned int F_430 ( struct V_105 * V_105 )
{
unsigned int V_476 ;
unsigned int V_477 = 0 ;
struct V_106 * V_107 ;
struct V_95 * V_158 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_159 ; V_101 ++ ) {
V_107 = F_140 ( V_105 , V_101 ) ;
F_141 (memslot, slots)
V_477 += V_158 -> V_165 ;
}
V_476 = V_477 * V_478 / 1000 ;
V_476 = F_142 ( V_476 ,
( unsigned int ) V_479 ) ;
return V_476 ;
}
void F_431 ( struct V_11 * V_12 )
{
F_364 ( V_12 ) ;
F_385 ( V_12 ) ;
F_69 ( V_12 ) ;
}
void F_432 ( void )
{
F_424 () ;
F_433 ( & V_173 ) ;
F_434 ( & V_475 ) ;
F_194 () ;
}
