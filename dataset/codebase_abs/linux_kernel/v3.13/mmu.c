void F_1 ( T_1 V_1 )
{
V_2 = V_1 ;
}
static T_1 F_2 ( unsigned int V_3 )
{
T_1 V_4 ;
F_3 ( V_3 > V_5 ) ;
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
static unsigned int F_5 ( struct V_11 * V_11 )
{
return ( F_6 ( V_11 ) -> V_12 +
V_5 - 150 ) & V_13 ;
}
static void F_7 ( struct V_11 * V_11 , T_1 * V_14 , T_1 V_15 ,
unsigned V_16 )
{
unsigned int V_3 = F_5 ( V_11 ) ;
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
static bool F_13 ( struct V_11 * V_11 , T_1 * V_14 , T_2 V_15 ,
T_3 V_21 , unsigned V_16 )
{
if ( F_14 ( F_15 ( V_21 ) ) ) {
F_7 ( V_11 , V_14 , V_15 , V_16 ) ;
return true ;
}
return false ;
}
static bool F_16 ( struct V_11 * V_11 , T_1 V_10 )
{
unsigned int V_22 , V_23 ;
V_22 = F_5 ( V_11 ) ;
V_23 = F_4 ( V_10 ) ;
F_17 ( V_10 , V_22 , V_23 ) ;
return F_18 ( V_22 == V_23 ) ;
}
static inline T_1 F_19 ( int V_24 , int V_25 )
{
return ( ( 1ULL << ( V_25 - V_24 + 1 ) ) - 1 ) << V_24 ;
}
void F_20 ( T_1 V_26 , T_1 V_27 ,
T_1 V_28 , T_1 V_29 , T_1 V_30 )
{
V_31 = V_26 ;
V_32 = V_27 ;
V_33 = V_28 ;
V_34 = V_29 ;
V_35 = V_30 ;
}
static int F_21 ( void )
{
return 1 ;
}
static int F_22 ( struct V_36 * V_37 )
{
return V_37 -> V_38 . V_39 & V_40 ;
}
static int F_23 ( T_1 V_41 )
{
return V_41 & V_42 && ! F_10 ( V_41 ) ;
}
static int F_24 ( T_1 V_41 )
{
return V_41 & V_43 ;
}
static int F_25 ( T_1 V_41 )
{
return F_23 ( V_41 ) ;
}
static int F_26 ( T_1 V_41 , int V_44 )
{
if ( V_44 == V_45 )
return 1 ;
if ( F_24 ( V_41 ) )
return 1 ;
return 0 ;
}
static T_3 F_27 ( T_1 V_41 )
{
return ( V_41 & V_46 ) >> V_19 ;
}
static T_2 F_28 ( T_4 V_47 )
{
int V_48 = 32 - V_49 - V_19 ;
return ( V_47 & V_50 ) << V_48 ;
}
static void F_29 ( T_1 * V_14 , T_1 V_10 )
{
* V_14 = V_10 ;
}
static void F_30 ( T_1 * V_14 , T_1 V_10 )
{
* V_14 = V_10 ;
}
static T_1 F_31 ( T_1 * V_14 , T_1 V_10 )
{
return F_32 ( V_14 , V_10 ) ;
}
static T_1 F_33 ( T_1 * V_14 )
{
return F_34 ( * V_14 ) ;
}
static bool F_35 ( T_1 V_10 )
{
return V_10 == 0ull ;
}
static void F_36 ( T_1 * V_14 , T_1 V_10 )
{
struct V_51 * V_52 = F_37 ( F_38 ( V_14 ) ) ;
if ( F_23 ( V_10 ) )
return;
F_39 () ;
V_52 -> V_53 ++ ;
}
static void F_29 ( T_1 * V_14 , T_1 V_10 )
{
union V_54 * V_55 , V_56 ;
V_55 = (union V_54 * ) V_14 ;
V_56 = (union V_54 ) V_10 ;
V_55 -> V_57 = V_56 . V_57 ;
F_39 () ;
V_55 -> V_58 = V_56 . V_58 ;
}
static void F_30 ( T_1 * V_14 , T_1 V_10 )
{
union V_54 * V_55 , V_56 ;
V_55 = (union V_54 * ) V_14 ;
V_56 = (union V_54 ) V_10 ;
V_55 -> V_58 = V_56 . V_58 ;
F_39 () ;
V_55 -> V_57 = V_56 . V_57 ;
F_36 ( V_14 , V_10 ) ;
}
static T_1 F_31 ( T_1 * V_14 , T_1 V_10 )
{
union V_54 * V_55 , V_56 , V_59 ;
V_55 = (union V_54 * ) V_14 ;
V_56 = (union V_54 ) V_10 ;
V_59 . V_58 = F_32 ( & V_55 -> V_58 , V_56 . V_58 ) ;
V_59 . V_57 = V_55 -> V_57 ;
V_55 -> V_57 = V_56 . V_57 ;
F_36 ( V_14 , V_10 ) ;
return V_59 . V_10 ;
}
static T_1 F_33 ( T_1 * V_14 )
{
struct V_51 * V_52 = F_37 ( F_38 ( V_14 ) ) ;
union V_54 V_10 , * V_59 = (union V_54 * ) V_14 ;
int V_60 ;
V_61:
V_60 = V_52 -> V_53 ;
F_40 () ;
V_10 . V_58 = V_59 -> V_58 ;
F_40 () ;
V_10 . V_57 = V_59 -> V_57 ;
F_40 () ;
if ( F_14 ( V_10 . V_58 != V_59 -> V_58 ||
V_60 != V_52 -> V_53 ) )
goto V_61;
return V_10 . V_10 ;
}
static bool F_35 ( T_1 V_10 )
{
union V_54 V_56 = (union V_54 ) V_10 ;
T_4 V_62 = V_2 >> 32 ;
if ( V_10 == 0ull )
return true ;
if ( V_56 . V_58 == 0ull &&
( V_56 . V_57 & V_62 ) == V_62 )
return true ;
return false ;
}
static bool F_41 ( T_1 V_10 )
{
return ( V_10 & ( V_63 | V_64 ) ) ==
( V_63 | V_64 ) ;
}
static bool F_42 ( T_1 V_10 )
{
if ( F_41 ( V_10 ) )
return true ;
if ( ! V_32 )
return false ;
if ( ! F_23 ( V_10 ) )
return false ;
if ( ( V_10 & V_32 ) &&
( ! F_43 ( V_10 ) || ( V_10 & V_33 ) ) )
return false ;
return true ;
}
static bool F_44 ( T_1 V_65 , T_1 V_66 , T_1 V_67 )
{
return ( V_65 & V_67 ) && ! ( V_66 & V_67 ) ;
}
static void F_9 ( T_1 * V_14 , T_1 V_66 )
{
F_3 ( F_23 ( * V_14 ) ) ;
F_29 ( V_14 , V_66 ) ;
}
static bool F_45 ( T_1 * V_14 , T_1 V_66 )
{
T_1 V_65 = * V_14 ;
bool V_68 = false ;
F_3 ( ! F_25 ( V_66 ) ) ;
if ( ! F_23 ( V_65 ) ) {
F_9 ( V_14 , V_66 ) ;
return V_68 ;
}
if ( ! F_42 ( V_65 ) )
F_30 ( V_14 , V_66 ) ;
else
V_65 = F_31 ( V_14 , V_66 ) ;
if ( F_43 ( V_65 ) && ! F_43 ( V_66 ) )
V_68 = true ;
if ( ! V_32 )
return V_68 ;
if ( F_44 ( V_65 , V_66 , V_32 ) )
F_46 ( F_27 ( V_65 ) ) ;
if ( F_44 ( V_65 , V_66 , V_33 ) )
F_47 ( F_27 ( V_65 ) ) ;
return V_68 ;
}
static int F_48 ( T_1 * V_14 )
{
T_3 V_21 ;
T_1 V_65 = * V_14 ;
if ( ! F_42 ( V_65 ) )
F_30 ( V_14 , 0ull ) ;
else
V_65 = F_31 ( V_14 , 0ull ) ;
if ( ! F_25 ( V_65 ) )
return 0 ;
V_21 = F_27 ( V_65 ) ;
F_3 ( ! F_49 ( V_21 ) && ! F_50 ( F_51 ( V_21 ) ) ) ;
if ( ! V_32 || V_65 & V_32 )
F_46 ( V_21 ) ;
if ( ! V_33 || ( V_65 & V_33 ) )
F_47 ( V_21 ) ;
return 1 ;
}
static void F_52 ( T_1 * V_14 )
{
F_30 ( V_14 , 0ull ) ;
}
static T_1 F_53 ( T_1 * V_14 )
{
return F_33 ( V_14 ) ;
}
static void F_54 ( struct V_36 * V_37 )
{
F_55 () ;
V_37 -> V_69 = V_70 ;
F_56 () ;
}
static void F_57 ( struct V_36 * V_37 )
{
F_56 () ;
V_37 -> V_69 = V_71 ;
F_58 () ;
}
static int F_59 ( struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
void * V_77 ;
if ( V_73 -> V_78 >= V_76 )
return 0 ;
while ( V_73 -> V_78 < F_60 ( V_73 -> V_79 ) ) {
V_77 = F_61 ( V_75 , V_80 ) ;
if ( ! V_77 )
return - V_81 ;
V_73 -> V_79 [ V_73 -> V_78 ++ ] = V_77 ;
}
return 0 ;
}
static int F_62 ( struct V_72 * V_73 )
{
return V_73 -> V_78 ;
}
static void F_63 ( struct V_72 * V_82 ,
struct V_74 * V_73 )
{
while ( V_82 -> V_78 )
F_64 ( V_73 , V_82 -> V_79 [ -- V_82 -> V_78 ] ) ;
}
static int F_65 ( struct V_72 * V_73 ,
int V_76 )
{
void * V_83 ;
if ( V_73 -> V_78 >= V_76 )
return 0 ;
while ( V_73 -> V_78 < F_60 ( V_73 -> V_79 ) ) {
V_83 = ( void * ) F_66 ( V_80 ) ;
if ( ! V_83 )
return - V_81 ;
V_73 -> V_79 [ V_73 -> V_78 ++ ] = V_83 ;
}
return 0 ;
}
static void F_67 ( struct V_72 * V_82 )
{
while ( V_82 -> V_78 )
F_68 ( ( unsigned long ) V_82 -> V_79 [ -- V_82 -> V_78 ] ) ;
}
static int F_69 ( struct V_36 * V_37 )
{
int V_84 ;
V_84 = F_59 ( & V_37 -> V_38 . V_85 ,
V_86 , 8 + V_87 ) ;
if ( V_84 )
goto V_88;
V_84 = F_65 ( & V_37 -> V_38 . V_89 , 8 ) ;
if ( V_84 )
goto V_88;
V_84 = F_59 ( & V_37 -> V_38 . V_90 ,
V_90 , 4 ) ;
V_88:
return V_84 ;
}
static void F_70 ( struct V_36 * V_37 )
{
F_63 ( & V_37 -> V_38 . V_85 ,
V_86 ) ;
F_67 ( & V_37 -> V_38 . V_89 ) ;
F_63 ( & V_37 -> V_38 . V_90 ,
V_90 ) ;
}
static void * F_71 ( struct V_72 * V_82 )
{
void * V_91 ;
F_72 ( ! V_82 -> V_78 ) ;
V_91 = V_82 -> V_79 [ -- V_82 -> V_78 ] ;
return V_91 ;
}
static struct V_92 * F_73 ( struct V_36 * V_37 )
{
return F_71 ( & V_37 -> V_38 . V_85 ) ;
}
static void F_74 ( struct V_92 * V_92 )
{
F_64 ( V_86 , V_92 ) ;
}
static T_2 F_75 ( struct V_51 * V_52 , int V_93 )
{
if ( ! V_52 -> V_94 . V_95 )
return V_52 -> V_96 [ V_93 ] ;
return V_52 -> V_15 + ( V_93 << ( ( V_52 -> V_94 . V_44 - 1 ) * V_97 ) ) ;
}
static void F_76 ( struct V_51 * V_52 , int V_93 , T_2 V_15 )
{
if ( V_52 -> V_94 . V_95 )
F_72 ( V_15 != F_75 ( V_52 , V_93 ) ) ;
else
V_52 -> V_96 [ V_93 ] = V_15 ;
}
static struct V_98 * F_77 ( T_2 V_15 ,
struct V_99 * V_100 ,
int V_44 )
{
unsigned long V_101 ;
V_101 = F_78 ( V_15 , V_100 -> V_102 , V_44 ) ;
return & V_100 -> V_38 . V_103 [ V_44 - 2 ] [ V_101 ] ;
}
static void F_79 ( struct V_11 * V_11 , T_2 V_15 )
{
struct V_99 * V_100 ;
struct V_98 * V_104 ;
int V_105 ;
V_100 = F_80 ( V_11 , V_15 ) ;
for ( V_105 = V_106 ;
V_105 < V_45 + V_107 ; ++ V_105 ) {
V_104 = F_77 ( V_15 , V_100 , V_105 ) ;
V_104 -> V_108 += 1 ;
}
V_11 -> V_38 . V_109 ++ ;
}
static void F_81 ( struct V_11 * V_11 , T_2 V_15 )
{
struct V_99 * V_100 ;
struct V_98 * V_104 ;
int V_105 ;
V_100 = F_80 ( V_11 , V_15 ) ;
for ( V_105 = V_106 ;
V_105 < V_45 + V_107 ; ++ V_105 ) {
V_104 = F_77 ( V_15 , V_100 , V_105 ) ;
V_104 -> V_108 -= 1 ;
F_3 ( V_104 -> V_108 < 0 ) ;
}
V_11 -> V_38 . V_109 -- ;
}
static int F_82 ( struct V_11 * V_11 ,
T_2 V_15 ,
int V_44 )
{
struct V_99 * V_100 ;
struct V_98 * V_104 ;
V_100 = F_80 ( V_11 , V_15 ) ;
if ( V_100 ) {
V_104 = F_77 ( V_15 , V_100 , V_44 ) ;
return V_104 -> V_108 ;
}
return 1 ;
}
static int F_83 ( struct V_11 * V_11 , T_2 V_15 )
{
unsigned long V_110 ;
int V_105 , V_68 = 0 ;
V_110 = F_84 ( V_11 , V_15 ) ;
for ( V_105 = V_45 ;
V_105 < ( V_45 + V_107 ) ; ++ V_105 ) {
if ( V_110 >= F_85 ( V_105 ) )
V_68 = V_105 ;
else
break;
}
return V_68 ;
}
static struct V_99 *
F_86 ( struct V_36 * V_37 , T_2 V_15 ,
bool V_111 )
{
struct V_99 * V_100 ;
V_100 = F_80 ( V_37 -> V_11 , V_15 ) ;
if ( ! V_100 || V_100 -> V_112 & V_113 ||
( V_111 && V_100 -> V_114 ) )
V_100 = NULL ;
return V_100 ;
}
static bool F_87 ( struct V_36 * V_37 , T_2 V_115 )
{
return ! F_86 ( V_37 , V_115 , true ) ;
}
static int F_88 ( struct V_36 * V_37 , T_2 V_115 )
{
int V_116 , V_44 , V_117 ;
V_116 = F_83 ( V_37 -> V_11 , V_115 ) ;
if ( V_116 == V_45 )
return V_116 ;
V_117 = V_76 ( V_118 -> V_119 () , V_116 ) ;
for ( V_44 = V_106 ; V_44 <= V_117 ; ++ V_44 )
if ( F_82 ( V_37 -> V_11 , V_115 , V_44 ) )
break;
return V_44 - 1 ;
}
static int F_89 ( struct V_36 * V_37 , T_1 * V_10 ,
unsigned long * V_120 )
{
struct V_92 * V_121 ;
int V_105 , V_60 = 0 ;
if ( ! * V_120 ) {
F_90 ( L_1 , V_10 , * V_10 ) ;
* V_120 = ( unsigned long ) V_10 ;
} else if ( ! ( * V_120 & 1 ) ) {
F_90 ( L_2 , V_10 , * V_10 ) ;
V_121 = F_73 ( V_37 ) ;
V_121 -> V_122 [ 0 ] = ( T_1 * ) * V_120 ;
V_121 -> V_122 [ 1 ] = V_10 ;
* V_120 = ( unsigned long ) V_121 | 1 ;
++ V_60 ;
} else {
F_90 ( L_3 , V_10 , * V_10 ) ;
V_121 = (struct V_92 * ) ( * V_120 & ~ 1ul ) ;
while ( V_121 -> V_122 [ V_123 - 1 ] && V_121 -> V_124 ) {
V_121 = V_121 -> V_124 ;
V_60 += V_123 ;
}
if ( V_121 -> V_122 [ V_123 - 1 ] ) {
V_121 -> V_124 = F_73 ( V_37 ) ;
V_121 = V_121 -> V_124 ;
}
for ( V_105 = 0 ; V_121 -> V_122 [ V_105 ] ; ++ V_105 )
++ V_60 ;
V_121 -> V_122 [ V_105 ] = V_10 ;
}
return V_60 ;
}
static void
F_91 ( unsigned long * V_120 , struct V_92 * V_121 ,
int V_105 , struct V_92 * V_125 )
{
int V_126 ;
for ( V_126 = V_123 - 1 ; ! V_121 -> V_122 [ V_126 ] && V_126 > V_105 ; -- V_126 )
;
V_121 -> V_122 [ V_105 ] = V_121 -> V_122 [ V_126 ] ;
V_121 -> V_122 [ V_126 ] = NULL ;
if ( V_126 != 0 )
return;
if ( ! V_125 && ! V_121 -> V_124 )
* V_120 = ( unsigned long ) V_121 -> V_122 [ 0 ] ;
else
if ( V_125 )
V_125 -> V_124 = V_121 -> V_124 ;
else
* V_120 = ( unsigned long ) V_121 -> V_124 | 1 ;
F_74 ( V_121 ) ;
}
static void F_92 ( T_1 * V_10 , unsigned long * V_120 )
{
struct V_92 * V_121 ;
struct V_92 * V_125 ;
int V_105 ;
if ( ! * V_120 ) {
F_93 ( V_127 L_4 , V_10 ) ;
F_94 () ;
} else if ( ! ( * V_120 & 1 ) ) {
F_90 ( L_5 , V_10 ) ;
if ( ( T_1 * ) * V_120 != V_10 ) {
F_93 ( V_127 L_6 , V_10 ) ;
F_94 () ;
}
* V_120 = 0 ;
} else {
F_90 ( L_7 , V_10 ) ;
V_121 = (struct V_92 * ) ( * V_120 & ~ 1ul ) ;
V_125 = NULL ;
while ( V_121 ) {
for ( V_105 = 0 ; V_105 < V_123 && V_121 -> V_122 [ V_105 ] ; ++ V_105 )
if ( V_121 -> V_122 [ V_105 ] == V_10 ) {
F_91 ( V_120 ,
V_121 , V_105 ,
V_125 ) ;
return;
}
V_125 = V_121 ;
V_121 = V_121 -> V_124 ;
}
F_95 ( L_8 , V_10 ) ;
F_94 () ;
}
}
static void F_96 ( unsigned long * V_120 , T_5 V_128 )
{
struct V_92 * V_121 ;
int V_105 ;
if ( ! * V_120 )
return;
if ( ! ( * V_120 & 1 ) )
return V_128 ( ( T_1 * ) * V_120 ) ;
V_121 = (struct V_92 * ) ( * V_120 & ~ 1ul ) ;
while ( V_121 ) {
for ( V_105 = 0 ; V_105 < V_123 && V_121 -> V_122 [ V_105 ] ; ++ V_105 )
V_128 ( V_121 -> V_122 [ V_105 ] ) ;
V_121 = V_121 -> V_124 ;
}
}
static unsigned long * F_97 ( T_2 V_15 , int V_44 ,
struct V_99 * V_100 )
{
unsigned long V_101 ;
V_101 = F_78 ( V_15 , V_100 -> V_102 , V_44 ) ;
return & V_100 -> V_38 . V_129 [ V_44 - V_45 ] [ V_101 ] ;
}
static unsigned long * F_98 ( struct V_11 * V_11 , T_2 V_15 , int V_44 )
{
struct V_99 * V_100 ;
V_100 = F_80 ( V_11 , V_15 ) ;
return F_97 ( V_15 , V_44 , V_100 ) ;
}
static bool F_99 ( struct V_36 * V_37 )
{
struct V_72 * V_73 ;
V_73 = & V_37 -> V_38 . V_85 ;
return F_62 ( V_73 ) ;
}
static int F_100 ( struct V_36 * V_37 , T_1 * V_10 , T_2 V_15 )
{
struct V_51 * V_52 ;
unsigned long * V_130 ;
V_52 = F_37 ( F_38 ( V_10 ) ) ;
F_76 ( V_52 , V_10 - V_52 -> V_131 , V_15 ) ;
V_130 = F_98 ( V_37 -> V_11 , V_15 , V_52 -> V_94 . V_44 ) ;
return F_89 ( V_37 , V_10 , V_130 ) ;
}
static void F_101 ( struct V_11 * V_11 , T_1 * V_10 )
{
struct V_51 * V_52 ;
T_2 V_15 ;
unsigned long * V_130 ;
V_52 = F_37 ( F_38 ( V_10 ) ) ;
V_15 = F_75 ( V_52 , V_10 - V_52 -> V_131 ) ;
V_130 = F_98 ( V_11 , V_15 , V_52 -> V_94 . V_44 ) ;
F_92 ( V_10 , V_130 ) ;
}
static T_1 * F_102 ( unsigned long V_129 , struct V_132 * V_133 )
{
if ( ! V_129 )
return NULL ;
if ( ! ( V_129 & 1 ) ) {
V_133 -> V_121 = NULL ;
return ( T_1 * ) V_129 ;
}
V_133 -> V_121 = (struct V_92 * ) ( V_129 & ~ 1ul ) ;
V_133 -> V_134 = 0 ;
return V_133 -> V_121 -> V_122 [ V_133 -> V_134 ] ;
}
static T_1 * F_103 ( struct V_132 * V_133 )
{
if ( V_133 -> V_121 ) {
if ( V_133 -> V_134 < V_123 - 1 ) {
T_1 * V_14 ;
++ V_133 -> V_134 ;
V_14 = V_133 -> V_121 -> V_122 [ V_133 -> V_134 ] ;
if ( V_14 )
return V_14 ;
}
V_133 -> V_121 = V_133 -> V_121 -> V_124 ;
if ( V_133 -> V_121 ) {
V_133 -> V_134 = 0 ;
return V_133 -> V_121 -> V_122 [ V_133 -> V_134 ] ;
}
}
return NULL ;
}
static void F_104 ( struct V_11 * V_11 , T_1 * V_14 )
{
if ( F_48 ( V_14 ) )
F_101 ( V_11 , V_14 ) ;
}
static bool F_105 ( struct V_11 * V_11 , T_1 * V_14 )
{
if ( F_24 ( * V_14 ) ) {
F_3 ( F_37 ( F_38 ( V_14 ) ) -> V_94 . V_44 ==
V_45 ) ;
F_104 ( V_11 , V_14 ) ;
-- V_11 -> V_135 . V_136 ;
return true ;
}
return false ;
}
static void F_106 ( struct V_36 * V_37 , T_1 * V_14 )
{
if ( F_105 ( V_37 -> V_11 , V_14 ) )
F_107 ( V_37 -> V_11 ) ;
}
static bool
F_108 ( struct V_11 * V_11 , T_1 * V_14 , bool * V_137 , bool V_138 )
{
T_1 V_10 = * V_14 ;
if ( ! F_43 ( V_10 ) &&
! ( V_138 && F_41 ( V_10 ) ) )
return false ;
F_90 ( L_9 , V_14 , * V_14 ) ;
if ( F_105 ( V_11 , V_14 ) ) {
* V_137 |= true ;
return true ;
}
if ( V_138 )
V_10 &= ~ V_64 ;
V_10 = V_10 & ~ V_139 ;
* V_137 |= F_45 ( V_14 , V_10 ) ;
return false ;
}
static bool F_109 ( struct V_11 * V_11 , unsigned long * V_130 ,
bool V_138 )
{
T_1 * V_14 ;
struct V_132 V_133 ;
bool V_137 = false ;
for ( V_14 = F_102 ( * V_130 , & V_133 ) ; V_14 ; ) {
F_72 ( ! ( * V_14 & V_42 ) ) ;
if ( F_108 ( V_11 , V_14 , & V_137 , V_138 ) ) {
V_14 = F_102 ( * V_130 , & V_133 ) ;
continue;
}
V_14 = F_103 ( & V_133 ) ;
}
return V_137 ;
}
void F_110 ( struct V_11 * V_11 ,
struct V_99 * V_100 ,
T_2 V_140 , unsigned long V_4 )
{
unsigned long * V_130 ;
while ( V_4 ) {
V_130 = F_97 ( V_100 -> V_102 + V_140 + F_111 ( V_4 ) ,
V_45 , V_100 ) ;
F_109 ( V_11 , V_130 , false ) ;
V_4 &= V_4 - 1 ;
}
}
static bool F_112 ( struct V_11 * V_11 , T_1 V_15 )
{
struct V_99 * V_100 ;
unsigned long * V_130 ;
int V_105 ;
bool V_141 = false ;
V_100 = F_80 ( V_11 , V_15 ) ;
for ( V_105 = V_45 ;
V_105 < V_45 + V_107 ; ++ V_105 ) {
V_130 = F_97 ( V_15 , V_105 , V_100 ) ;
V_141 |= F_109 ( V_11 , V_130 , true ) ;
}
return V_141 ;
}
static int F_113 ( struct V_11 * V_11 , unsigned long * V_130 ,
struct V_99 * V_100 , unsigned long V_142 )
{
T_1 * V_14 ;
struct V_132 V_133 ;
int V_143 = 0 ;
while ( ( V_14 = F_102 ( * V_130 , & V_133 ) ) ) {
F_72 ( ! ( * V_14 & V_42 ) ) ;
F_90 ( L_10 , V_14 , * V_14 ) ;
F_104 ( V_11 , V_14 ) ;
V_143 = 1 ;
}
return V_143 ;
}
static int F_114 ( struct V_11 * V_11 , unsigned long * V_130 ,
struct V_99 * V_100 , unsigned long V_142 )
{
T_1 * V_14 ;
struct V_132 V_133 ;
int V_144 = 0 ;
T_1 V_66 ;
T_6 * V_145 = ( T_6 * ) V_142 ;
T_3 V_146 ;
F_3 ( F_115 ( * V_145 ) ) ;
V_146 = F_116 ( * V_145 ) ;
for ( V_14 = F_102 ( * V_130 , & V_133 ) ; V_14 ; ) {
F_72 ( ! F_23 ( * V_14 ) ) ;
F_90 ( L_11 , V_14 , * V_14 ) ;
V_144 = 1 ;
if ( F_117 ( * V_145 ) ) {
F_104 ( V_11 , V_14 ) ;
V_14 = F_102 ( * V_130 , & V_133 ) ;
} else {
V_66 = * V_14 & ~ V_46 ;
V_66 |= ( T_1 ) V_146 << V_19 ;
V_66 &= ~ V_139 ;
V_66 &= ~ V_63 ;
V_66 &= ~ V_32 ;
F_48 ( V_14 ) ;
F_9 ( V_14 , V_66 ) ;
V_14 = F_103 ( & V_133 ) ;
}
}
if ( V_144 )
F_107 ( V_11 ) ;
return 0 ;
}
static int F_118 ( struct V_11 * V_11 ,
unsigned long V_147 ,
unsigned long V_148 ,
unsigned long V_142 ,
int (* F_119)( struct V_11 * V_11 ,
unsigned long * V_130 ,
struct V_99 * V_100 ,
unsigned long V_142 ) )
{
int V_126 ;
int V_68 = 0 ;
struct F_6 * V_149 ;
struct V_99 * V_150 ;
V_149 = F_6 ( V_11 ) ;
F_120 (memslot, slots) {
unsigned long V_151 , V_152 ;
T_2 V_153 , V_154 ;
V_151 = F_121 ( V_147 , V_150 -> V_155 ) ;
V_152 = V_76 ( V_148 , V_150 -> V_155 +
( V_150 -> V_156 << V_19 ) ) ;
if ( V_151 >= V_152 )
continue;
V_153 = F_122 ( V_151 , V_150 ) ;
V_154 = F_122 ( V_152 + V_157 - 1 , V_150 ) ;
for ( V_126 = V_45 ;
V_126 < V_45 + V_107 ; ++ V_126 ) {
unsigned long V_101 , V_158 ;
unsigned long * V_130 ;
V_101 = F_78 ( V_153 , V_150 -> V_102 , V_126 ) ;
V_158 = F_78 ( V_154 - 1 , V_150 -> V_102 , V_126 ) ;
V_130 = F_97 ( V_153 , V_126 , V_150 ) ;
for (; V_101 <= V_158 ; ++ V_101 )
V_68 |= F_119 ( V_11 , V_130 ++ , V_150 , V_142 ) ;
}
}
return V_68 ;
}
static int F_123 ( struct V_11 * V_11 , unsigned long V_159 ,
unsigned long V_142 ,
int (* F_119)( struct V_11 * V_11 , unsigned long * V_130 ,
struct V_99 * V_100 ,
unsigned long V_142 ) )
{
return F_118 ( V_11 , V_159 , V_159 + 1 , V_142 , F_119 ) ;
}
int F_124 ( struct V_11 * V_11 , unsigned long V_159 )
{
return F_123 ( V_11 , V_159 , 0 , F_113 ) ;
}
int F_125 ( struct V_11 * V_11 , unsigned long V_147 , unsigned long V_148 )
{
return F_118 ( V_11 , V_147 , V_148 , 0 , F_113 ) ;
}
void F_126 ( struct V_11 * V_11 , unsigned long V_159 , T_6 V_41 )
{
F_123 ( V_11 , V_159 , ( unsigned long ) & V_41 , F_114 ) ;
}
static int F_127 ( struct V_11 * V_11 , unsigned long * V_130 ,
struct V_99 * V_100 , unsigned long V_142 )
{
T_1 * V_14 ;
struct V_132 V_160 ( V_133 ) ;
int V_161 = 0 ;
if ( ! V_32 ) {
V_161 = F_113 ( V_11 , V_130 , V_100 , V_142 ) ;
goto V_88;
}
for ( V_14 = F_102 ( * V_130 , & V_133 ) ; V_14 ;
V_14 = F_103 ( & V_133 ) ) {
F_72 ( ! F_23 ( * V_14 ) ) ;
if ( * V_14 & V_32 ) {
V_161 = 1 ;
F_128 ( ( F_129 ( V_32 ) - 1 ) ,
( unsigned long * ) V_14 ) ;
}
}
V_88:
F_130 ( V_142 , V_100 , V_161 ) ;
return V_161 ;
}
static int F_131 ( struct V_11 * V_11 , unsigned long * V_130 ,
struct V_99 * V_100 , unsigned long V_142 )
{
T_1 * V_14 ;
struct V_132 V_133 ;
int V_161 = 0 ;
if ( ! V_32 )
goto V_88;
for ( V_14 = F_102 ( * V_130 , & V_133 ) ; V_14 ;
V_14 = F_103 ( & V_133 ) ) {
F_72 ( ! F_23 ( * V_14 ) ) ;
if ( * V_14 & V_32 ) {
V_161 = 1 ;
break;
}
}
V_88:
return V_161 ;
}
static void F_132 ( struct V_36 * V_37 , T_1 * V_10 , T_2 V_15 )
{
unsigned long * V_130 ;
struct V_51 * V_52 ;
V_52 = F_37 ( F_38 ( V_10 ) ) ;
V_130 = F_98 ( V_37 -> V_11 , V_15 , V_52 -> V_94 . V_44 ) ;
F_113 ( V_37 -> V_11 , V_130 , NULL , 0 ) ;
F_107 ( V_37 -> V_11 ) ;
}
int F_133 ( struct V_11 * V_11 , unsigned long V_159 )
{
return F_123 ( V_11 , V_159 , V_159 , F_127 ) ;
}
int F_134 ( struct V_11 * V_11 , unsigned long V_159 )
{
return F_123 ( V_11 , V_159 , 0 , F_131 ) ;
}
static int F_135 ( T_1 * V_131 )
{
T_1 * V_134 ;
T_1 * V_148 ;
for ( V_134 = V_131 , V_148 = V_134 + V_157 / sizeof( T_1 ) ; V_134 != V_148 ; V_134 ++ )
if ( F_23 ( * V_134 ) ) {
F_93 ( V_127 L_12 , V_162 ,
V_134 , * V_134 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_136 ( struct V_11 * V_11 , int V_163 )
{
V_11 -> V_38 . V_164 += V_163 ;
F_137 ( & V_165 , V_163 ) ;
}
static void F_138 ( struct V_51 * V_52 )
{
ASSERT ( F_135 ( V_52 -> V_131 ) ) ;
F_139 ( & V_52 -> V_166 ) ;
F_140 ( & V_52 -> V_167 ) ;
F_68 ( ( unsigned long ) V_52 -> V_131 ) ;
if ( ! V_52 -> V_94 . V_95 )
F_68 ( ( unsigned long ) V_52 -> V_96 ) ;
F_64 ( V_90 , V_52 ) ;
}
static unsigned F_141 ( T_2 V_15 )
{
return V_15 & ( ( 1 << V_168 ) - 1 ) ;
}
static void F_142 ( struct V_36 * V_37 ,
struct V_51 * V_52 , T_1 * V_169 )
{
if ( ! V_169 )
return;
F_89 ( V_37 , V_169 , & V_52 -> V_170 ) ;
}
static void F_143 ( struct V_51 * V_52 ,
T_1 * V_169 )
{
F_92 ( V_169 , & V_52 -> V_170 ) ;
}
static void F_144 ( struct V_51 * V_52 ,
T_1 * V_169 )
{
F_143 ( V_52 , V_169 ) ;
F_52 ( V_169 ) ;
}
static struct V_51 * F_145 ( struct V_36 * V_37 ,
T_1 * V_169 , int V_95 )
{
struct V_51 * V_52 ;
V_52 = F_71 ( & V_37 -> V_38 . V_90 ) ;
V_52 -> V_131 = F_71 ( & V_37 -> V_38 . V_89 ) ;
if ( ! V_95 )
V_52 -> V_96 = F_71 ( & V_37 -> V_38 . V_89 ) ;
F_146 ( F_147 ( V_52 -> V_131 ) , ( unsigned long ) V_52 ) ;
F_148 ( & V_52 -> V_167 , & V_37 -> V_11 -> V_38 . V_171 ) ;
V_52 -> V_170 = 0 ;
F_142 ( V_37 , V_52 , V_169 ) ;
F_136 ( V_37 -> V_11 , + 1 ) ;
return V_52 ;
}
static void F_149 ( struct V_51 * V_52 )
{
F_96 ( & V_52 -> V_170 , V_172 ) ;
}
static void V_172 ( T_1 * V_10 )
{
struct V_51 * V_52 ;
unsigned int V_93 ;
V_52 = F_37 ( F_38 ( V_10 ) ) ;
V_93 = V_10 - V_52 -> V_131 ;
if ( F_150 ( V_93 , V_52 -> V_173 ) )
return;
if ( V_52 -> V_174 ++ )
return;
F_149 ( V_52 ) ;
}
static int F_151 ( struct V_36 * V_37 ,
struct V_51 * V_52 )
{
return 1 ;
}
static void F_152 ( struct V_36 * V_37 , T_7 V_175 )
{
}
static void F_153 ( struct V_36 * V_37 ,
struct V_51 * V_52 , T_1 * V_10 ,
const void * V_41 )
{
F_3 ( 1 ) ;
}
static int F_154 ( struct V_176 * V_177 , struct V_51 * V_52 ,
int V_101 )
{
int V_105 ;
if ( V_52 -> V_178 )
for ( V_105 = 0 ; V_105 < V_177 -> V_163 ; V_105 ++ )
if ( V_177 -> V_83 [ V_105 ] . V_52 == V_52 )
return 0 ;
V_177 -> V_83 [ V_177 -> V_163 ] . V_52 = V_52 ;
V_177 -> V_83 [ V_177 -> V_163 ] . V_101 = V_101 ;
V_177 -> V_163 ++ ;
return ( V_177 -> V_163 == V_179 ) ;
}
static int F_155 ( struct V_51 * V_52 ,
struct V_176 * V_177 )
{
int V_105 , V_68 , V_180 = 0 ;
F_156 (i, sp->unsync_child_bitmap, 512 ) {
struct V_51 * V_181 ;
T_1 V_182 = V_52 -> V_131 [ V_105 ] ;
if ( ! F_23 ( V_182 ) || F_24 ( V_182 ) )
goto V_183;
V_181 = F_37 ( V_182 & V_46 ) ;
if ( V_181 -> V_174 ) {
if ( F_154 ( V_177 , V_181 , V_105 ) )
return - V_184 ;
V_68 = F_155 ( V_181 , V_177 ) ;
if ( ! V_68 )
goto V_183;
else if ( V_68 > 0 )
V_180 += V_68 ;
else
return V_68 ;
} else if ( V_181 -> V_178 ) {
V_180 ++ ;
if ( F_154 ( V_177 , V_181 , V_105 ) )
return - V_184 ;
} else
goto V_183;
continue;
V_183:
F_157 ( V_105 , V_52 -> V_173 ) ;
V_52 -> V_174 -- ;
F_3 ( ( int ) V_52 -> V_174 < 0 ) ;
}
return V_180 ;
}
static int F_158 ( struct V_51 * V_52 ,
struct V_176 * V_177 )
{
if ( ! V_52 -> V_174 )
return 0 ;
F_154 ( V_177 , V_52 , 0 ) ;
return F_155 ( V_52 , V_177 ) ;
}
static void F_159 ( struct V_11 * V_11 , struct V_51 * V_52 )
{
F_3 ( ! V_52 -> V_178 ) ;
F_160 ( V_52 ) ;
V_52 -> V_178 = 0 ;
-- V_11 -> V_135 . V_185 ;
}
static int F_161 ( struct V_36 * V_37 , struct V_51 * V_52 ,
struct V_186 * V_187 , bool V_188 )
{
if ( V_52 -> V_94 . V_189 != ! ! F_162 ( V_37 ) ) {
F_163 ( V_37 -> V_11 , V_52 , V_187 ) ;
return 1 ;
}
if ( V_188 )
F_159 ( V_37 -> V_11 , V_52 ) ;
if ( V_37 -> V_38 . V_190 . V_191 ( V_37 , V_52 ) ) {
F_163 ( V_37 -> V_11 , V_52 , V_187 ) ;
return 1 ;
}
F_164 ( V_37 ) ;
return 0 ;
}
static int F_165 ( struct V_36 * V_37 ,
struct V_51 * V_52 )
{
F_166 ( V_187 ) ;
int V_68 ;
V_68 = F_161 ( V_37 , V_52 , & V_187 , false ) ;
if ( V_68 )
F_167 ( V_37 -> V_11 , & V_187 ) ;
return V_68 ;
}
static void F_168 ( struct V_36 * V_37 , int V_192 ) { }
static void F_169 ( void ) { }
static int F_170 ( struct V_36 * V_37 , struct V_51 * V_52 ,
struct V_186 * V_187 )
{
return F_161 ( V_37 , V_52 , V_187 , true ) ;
}
static void F_171 ( struct V_36 * V_37 , T_2 V_15 )
{
struct V_51 * V_24 ;
F_166 ( V_187 ) ;
bool V_137 = false ;
F_172 (vcpu->kvm, s, gfn) {
if ( ! V_24 -> V_178 )
continue;
F_3 ( V_24 -> V_94 . V_44 != V_45 ) ;
F_159 ( V_37 -> V_11 , V_24 ) ;
if ( ( V_24 -> V_94 . V_189 != ! ! F_162 ( V_37 ) ) ||
( V_37 -> V_38 . V_190 . V_191 ( V_37 , V_24 ) ) ) {
F_163 ( V_37 -> V_11 , V_24 , & V_187 ) ;
continue;
}
V_137 = true ;
}
F_167 ( V_37 -> V_11 , & V_187 ) ;
if ( V_137 )
F_164 ( V_37 ) ;
}
static int F_173 ( struct V_176 * V_177 ,
struct V_193 * V_194 ,
int V_105 )
{
int V_195 ;
for ( V_195 = V_105 + 1 ; V_195 < V_177 -> V_163 ; V_195 ++ ) {
struct V_51 * V_52 = V_177 -> V_83 [ V_195 ] . V_52 ;
if ( V_52 -> V_94 . V_44 == V_45 ) {
V_194 -> V_101 [ 0 ] = V_177 -> V_83 [ V_195 ] . V_101 ;
return V_195 ;
}
V_194 -> V_196 [ V_52 -> V_94 . V_44 - 2 ] = V_52 ;
V_194 -> V_101 [ V_52 -> V_94 . V_44 - 1 ] = V_177 -> V_83 [ V_195 ] . V_101 ;
}
return V_195 ;
}
static void F_174 ( struct V_193 * V_194 )
{
struct V_51 * V_52 ;
unsigned int V_44 = 0 ;
do {
unsigned int V_101 = V_194 -> V_101 [ V_44 ] ;
V_52 = V_194 -> V_196 [ V_44 ] ;
if ( ! V_52 )
return;
-- V_52 -> V_174 ;
F_3 ( ( int ) V_52 -> V_174 < 0 ) ;
F_157 ( V_101 , V_52 -> V_173 ) ;
V_44 ++ ;
} while ( V_44 < V_197 - 1 && ! V_52 -> V_174 );
}
static void F_175 ( struct V_51 * V_196 ,
struct V_193 * V_194 ,
struct V_176 * V_177 )
{
V_194 -> V_196 [ V_196 -> V_94 . V_44 - 1 ] = NULL ;
V_177 -> V_163 = 0 ;
}
static void F_176 ( struct V_36 * V_37 ,
struct V_51 * V_196 )
{
int V_105 ;
struct V_51 * V_52 ;
struct V_193 V_194 ;
struct V_176 V_198 ;
F_166 ( V_187 ) ;
F_175 ( V_196 , & V_194 , & V_198 ) ;
while ( F_158 ( V_196 , & V_198 ) ) {
bool V_199 = false ;
F_177 (pages, sp, parents, i)
V_199 |= F_112 ( V_37 -> V_11 , V_52 -> V_15 ) ;
if ( V_199 )
F_107 ( V_37 -> V_11 ) ;
F_177 (pages, sp, parents, i) {
F_170 ( V_37 , V_52 , & V_187 ) ;
F_174 ( & V_194 ) ;
}
F_167 ( V_37 -> V_11 , & V_187 ) ;
F_178 ( & V_37 -> V_11 -> V_200 ) ;
F_175 ( V_196 , & V_194 , & V_198 ) ;
}
}
static void F_179 ( struct V_51 * V_52 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_201 ; ++ V_105 )
V_52 -> V_131 [ V_105 ] = 0ull ;
}
static void F_180 ( struct V_51 * V_52 )
{
V_52 -> V_202 = 0 ;
}
static void F_181 ( T_1 * V_10 )
{
struct V_51 * V_52 = F_37 ( F_38 ( V_10 ) ) ;
F_180 ( V_52 ) ;
}
static bool F_182 ( struct V_11 * V_11 , struct V_51 * V_52 )
{
return F_14 ( V_52 -> V_203 != V_11 -> V_38 . V_203 ) ;
}
static struct V_51 * F_183 ( struct V_36 * V_37 ,
T_2 V_15 ,
T_7 V_204 ,
unsigned V_44 ,
int V_95 ,
unsigned V_16 ,
T_1 * V_169 )
{
union V_205 V_94 ;
unsigned V_206 ;
struct V_51 * V_52 ;
bool V_207 = false ;
V_94 = V_37 -> V_38 . V_190 . V_208 ;
V_94 . V_44 = V_44 ;
V_94 . V_95 = V_95 ;
if ( V_94 . V_95 )
V_94 . V_189 = 0 ;
V_94 . V_16 = V_16 ;
if ( ! V_37 -> V_38 . V_190 . V_209
&& V_37 -> V_38 . V_190 . V_210 <= V_211 ) {
V_206 = V_204 >> ( V_19 + ( V_212 * V_44 ) ) ;
V_206 &= ( 1 << ( ( V_213 - V_212 ) * V_44 ) ) - 1 ;
V_94 . V_206 = V_206 ;
}
F_184 (vcpu->kvm, sp, gfn) {
if ( F_182 ( V_37 -> V_11 , V_52 ) )
continue;
if ( ! V_207 && V_52 -> V_178 )
V_207 = true ;
if ( V_52 -> V_94 . V_214 != V_94 . V_214 )
continue;
if ( V_52 -> V_178 && F_165 ( V_37 , V_52 ) )
break;
F_142 ( V_37 , V_52 , V_169 ) ;
if ( V_52 -> V_174 ) {
F_185 ( V_215 , V_37 ) ;
F_149 ( V_52 ) ;
} else if ( V_52 -> V_178 )
F_149 ( V_52 ) ;
F_180 ( V_52 ) ;
F_186 ( V_52 , false ) ;
return V_52 ;
}
++ V_37 -> V_11 -> V_135 . V_216 ;
V_52 = F_145 ( V_37 , V_169 , V_95 ) ;
if ( ! V_52 )
return V_52 ;
V_52 -> V_15 = V_15 ;
V_52 -> V_94 = V_94 ;
F_187 ( & V_52 -> V_166 ,
& V_37 -> V_11 -> V_38 . V_217 [ F_141 ( V_15 ) ] ) ;
if ( ! V_95 ) {
if ( F_112 ( V_37 -> V_11 , V_15 ) )
F_107 ( V_37 -> V_11 ) ;
if ( V_44 > V_45 && V_207 )
F_171 ( V_37 , V_15 ) ;
F_79 ( V_37 -> V_11 , V_15 ) ;
}
V_52 -> V_203 = V_37 -> V_11 -> V_38 . V_203 ;
F_179 ( V_52 ) ;
F_186 ( V_52 , true ) ;
return V_52 ;
}
static void F_188 ( struct V_218 * V_219 ,
struct V_36 * V_37 , T_1 V_220 )
{
V_219 -> V_220 = V_220 ;
V_219 -> V_221 = V_37 -> V_38 . V_190 . V_222 ;
V_219 -> V_44 = V_37 -> V_38 . V_190 . V_223 ;
if ( V_219 -> V_44 == V_197 &&
V_37 -> V_38 . V_190 . V_210 < V_197 &&
! V_37 -> V_38 . V_190 . V_209 )
-- V_219 -> V_44 ;
if ( V_219 -> V_44 == V_224 ) {
V_219 -> V_221
= V_37 -> V_38 . V_190 . V_225 [ ( V_220 >> 30 ) & 3 ] ;
V_219 -> V_221 &= V_46 ;
-- V_219 -> V_44 ;
if ( ! V_219 -> V_221 )
V_219 -> V_44 = 0 ;
}
}
static bool F_189 ( struct V_218 * V_219 )
{
if ( V_219 -> V_44 < V_45 )
return false ;
V_219 -> V_93 = F_190 ( V_219 -> V_220 , V_219 -> V_44 ) ;
V_219 -> V_14 = ( ( T_1 * ) F_191 ( V_219 -> V_221 ) ) + V_219 -> V_93 ;
return true ;
}
static void F_192 ( struct V_218 * V_219 ,
T_1 V_10 )
{
if ( F_26 ( V_10 , V_219 -> V_44 ) ) {
V_219 -> V_44 = 0 ;
return;
}
V_219 -> V_221 = V_10 & V_46 ;
-- V_219 -> V_44 ;
}
static void F_193 ( struct V_218 * V_219 )
{
return F_192 ( V_219 , * V_219 -> V_14 ) ;
}
static void F_194 ( T_1 * V_14 , struct V_51 * V_52 , bool V_226 )
{
T_1 V_10 ;
F_195 ( V_227 != V_42 ||
V_228 != V_139 ) ;
V_10 = F_38 ( V_52 -> V_131 ) | V_42 | V_139 |
V_31 | V_35 ;
if ( V_226 )
V_10 |= V_32 ;
F_9 ( V_14 , V_10 ) ;
}
static void F_196 ( struct V_36 * V_37 , T_1 * V_14 ,
unsigned V_229 )
{
if ( F_23 ( * V_14 ) && ! F_24 ( * V_14 ) ) {
struct V_51 * V_181 ;
V_181 = F_37 ( * V_14 & V_46 ) ;
if ( V_181 -> V_94 . V_16 == V_229 )
return;
F_144 ( V_181 , V_14 ) ;
F_107 ( V_37 -> V_11 ) ;
}
}
static bool F_197 ( struct V_11 * V_11 , struct V_51 * V_52 ,
T_1 * V_10 )
{
T_1 V_41 ;
struct V_51 * V_181 ;
V_41 = * V_10 ;
if ( F_23 ( V_41 ) ) {
if ( F_26 ( V_41 , V_52 -> V_94 . V_44 ) ) {
F_104 ( V_11 , V_10 ) ;
if ( F_24 ( V_41 ) )
-- V_11 -> V_135 . V_136 ;
} else {
V_181 = F_37 ( V_41 & V_46 ) ;
F_144 ( V_181 , V_10 ) ;
}
return true ;
}
if ( F_10 ( V_41 ) )
F_52 ( V_10 ) ;
return false ;
}
static void F_198 ( struct V_11 * V_11 ,
struct V_51 * V_52 )
{
unsigned V_105 ;
for ( V_105 = 0 ; V_105 < V_201 ; ++ V_105 )
F_197 ( V_11 , V_52 , V_52 -> V_131 + V_105 ) ;
}
static void F_199 ( struct V_51 * V_52 , T_1 * V_169 )
{
F_143 ( V_52 , V_169 ) ;
}
static void F_200 ( struct V_11 * V_11 , struct V_51 * V_52 )
{
T_1 * V_14 ;
struct V_132 V_133 ;
while ( ( V_14 = F_102 ( V_52 -> V_170 , & V_133 ) ) )
F_144 ( V_52 , V_14 ) ;
}
static int F_201 ( struct V_11 * V_11 ,
struct V_51 * V_196 ,
struct V_186 * V_187 )
{
int V_105 , V_230 = 0 ;
struct V_193 V_194 ;
struct V_176 V_198 ;
if ( V_196 -> V_94 . V_44 == V_45 )
return 0 ;
F_175 ( V_196 , & V_194 , & V_198 ) ;
while ( F_158 ( V_196 , & V_198 ) ) {
struct V_51 * V_52 ;
F_177 (pages, sp, parents, i) {
F_163 ( V_11 , V_52 , V_187 ) ;
F_174 ( & V_194 ) ;
V_230 ++ ;
}
F_175 ( V_196 , & V_194 , & V_198 ) ;
}
return V_230 ;
}
static int F_163 ( struct V_11 * V_11 , struct V_51 * V_52 ,
struct V_186 * V_187 )
{
int V_68 ;
F_202 ( V_52 ) ;
++ V_11 -> V_135 . V_231 ;
V_68 = F_201 ( V_11 , V_52 , V_187 ) ;
F_198 ( V_11 , V_52 ) ;
F_200 ( V_11 , V_52 ) ;
if ( ! V_52 -> V_94 . V_232 && ! V_52 -> V_94 . V_95 )
F_81 ( V_11 , V_52 -> V_15 ) ;
if ( V_52 -> V_178 )
F_159 ( V_11 , V_52 ) ;
if ( ! V_52 -> V_233 ) {
V_68 ++ ;
F_203 ( & V_52 -> V_167 , V_187 ) ;
F_136 ( V_11 , - 1 ) ;
} else {
F_203 ( & V_52 -> V_167 , & V_11 -> V_38 . V_171 ) ;
if ( ! V_52 -> V_94 . V_232 && ! F_182 ( V_11 , V_52 ) )
F_204 ( V_11 ) ;
}
V_52 -> V_94 . V_232 = 1 ;
return V_68 ;
}
static void F_167 ( struct V_11 * V_11 ,
struct V_186 * V_187 )
{
struct V_51 * V_52 , * V_234 ;
if ( F_205 ( V_187 ) )
return;
F_56 () ;
F_107 ( V_11 ) ;
F_206 (sp, nsp, invalid_list, link) {
F_3 ( ! V_52 -> V_94 . V_232 || V_52 -> V_233 ) ;
F_138 ( V_52 ) ;
}
}
static bool F_207 ( struct V_11 * V_11 ,
struct V_186 * V_187 )
{
struct V_51 * V_52 ;
if ( F_205 ( & V_11 -> V_38 . V_171 ) )
return false ;
V_52 = F_208 ( V_11 -> V_38 . V_171 . V_235 ,
struct V_51 , V_167 ) ;
F_163 ( V_11 , V_52 , V_187 ) ;
return true ;
}
void F_209 ( struct V_11 * V_11 , unsigned int V_236 )
{
F_166 ( V_187 ) ;
F_210 ( & V_11 -> V_200 ) ;
if ( V_11 -> V_38 . V_164 > V_236 ) {
while ( V_11 -> V_38 . V_164 > V_236 )
if ( ! F_207 ( V_11 , & V_187 ) )
break;
F_167 ( V_11 , & V_187 ) ;
V_236 = V_11 -> V_38 . V_164 ;
}
V_11 -> V_38 . V_237 = V_236 ;
F_211 ( & V_11 -> V_200 ) ;
}
int F_212 ( struct V_11 * V_11 , T_2 V_15 )
{
struct V_51 * V_52 ;
F_166 ( V_187 ) ;
int V_84 ;
F_213 ( L_13 , V_162 , V_15 ) ;
V_84 = 0 ;
F_210 ( & V_11 -> V_200 ) ;
F_172 (kvm, sp, gfn) {
F_213 ( L_14 , V_162 , V_15 ,
V_52 -> V_94 . V_214 ) ;
V_84 = 1 ;
F_163 ( V_11 , V_52 , & V_187 ) ;
}
F_167 ( V_11 , & V_187 ) ;
F_211 ( & V_11 -> V_200 ) ;
return V_84 ;
}
static int F_214 ( struct V_238 * V_239 ,
T_1 V_147 , T_1 V_148 )
{
int V_105 ;
T_1 V_240 , V_4 ;
T_8 V_241 , V_242 ;
int V_243 = V_244 ;
if ( ! V_239 -> V_245 )
return 0xFF ;
V_148 -- ;
if ( V_239 -> V_246 && ( V_147 < 0x100000 ) ) {
int V_101 ;
if ( V_147 < 0x80000 ) {
V_101 = 0 ;
V_101 += ( V_147 >> 16 ) ;
return V_239 -> V_247 [ V_101 ] ;
} else if ( V_147 < 0xC0000 ) {
V_101 = 1 * 8 ;
V_101 += ( ( V_147 - 0x80000 ) >> 14 ) ;
return V_239 -> V_247 [ V_101 ] ;
} else if ( V_147 < 0x1000000 ) {
V_101 = 3 * 8 ;
V_101 += ( ( V_147 - 0xC0000 ) >> 12 ) ;
return V_239 -> V_247 [ V_101 ] ;
}
}
if ( ! ( V_239 -> V_245 & 2 ) )
return V_239 -> V_248 ;
V_241 = 0xFF ;
for ( V_105 = 0 ; V_105 < V_243 ; ++ V_105 ) {
unsigned short V_249 , V_250 ;
if ( ! ( V_239 -> V_251 [ V_105 ] . V_252 & ( 1 << 11 ) ) )
continue;
V_240 = ( ( ( T_1 ) V_239 -> V_251 [ V_105 ] . V_253 ) << 32 ) +
( V_239 -> V_251 [ V_105 ] . V_254 & V_20 ) ;
V_4 = ( ( ( T_1 ) V_239 -> V_251 [ V_105 ] . V_255 ) << 32 ) +
( V_239 -> V_251 [ V_105 ] . V_252 & V_20 ) ;
V_249 = ( ( V_147 & V_4 ) == ( V_240 & V_4 ) ) ;
V_250 = ( ( V_148 & V_4 ) == ( V_240 & V_4 ) ) ;
if ( V_249 != V_250 )
return 0xFE ;
if ( ( V_147 & V_4 ) != ( V_240 & V_4 ) )
continue;
V_242 = V_239 -> V_251 [ V_105 ] . V_254 & 0xff ;
if ( V_241 == 0xFF ) {
V_241 = V_242 ;
continue;
}
if ( V_241 == V_256 ||
V_242 == V_256 )
return V_256 ;
if ( ( V_241 == V_257 &&
V_242 == V_258 ) ||
( V_241 == V_258 &&
V_242 == V_257 ) ) {
V_241 = V_258 ;
V_242 = V_258 ;
}
if ( V_241 != V_242 )
return V_256 ;
}
if ( V_241 != 0xFF )
return V_241 ;
return V_239 -> V_248 ;
}
T_8 F_215 ( struct V_36 * V_37 , T_2 V_15 )
{
T_8 V_259 ;
V_259 = F_214 ( & V_37 -> V_38 . V_239 , V_15 << V_19 ,
( V_15 << V_19 ) + V_157 ) ;
if ( V_259 == 0xfe || V_259 == 0xff )
V_259 = V_257 ;
return V_259 ;
}
static void F_216 ( struct V_36 * V_37 , struct V_51 * V_52 )
{
F_217 ( V_52 ) ;
++ V_37 -> V_11 -> V_135 . V_185 ;
V_52 -> V_178 = 1 ;
F_149 ( V_52 ) ;
}
static void F_218 ( struct V_36 * V_37 , T_2 V_15 )
{
struct V_51 * V_24 ;
F_172 (vcpu->kvm, s, gfn) {
if ( V_24 -> V_178 )
continue;
F_3 ( V_24 -> V_94 . V_44 != V_45 ) ;
F_216 ( V_37 , V_24 ) ;
}
}
static int F_219 ( struct V_36 * V_37 , T_2 V_15 ,
bool V_260 )
{
struct V_51 * V_24 ;
bool V_261 = false ;
F_172 (vcpu->kvm, s, gfn) {
if ( ! V_260 )
return 1 ;
if ( V_24 -> V_94 . V_44 != V_45 )
return 1 ;
if ( ! V_24 -> V_178 )
V_261 = true ;
}
if ( V_261 )
F_218 ( V_37 , V_15 ) ;
return 0 ;
}
static int F_220 ( struct V_36 * V_37 , T_1 * V_14 ,
unsigned V_262 , int V_44 ,
T_2 V_15 , T_3 V_21 , bool V_263 ,
bool V_260 , bool V_264 )
{
T_1 V_10 ;
int V_68 = 0 ;
if ( F_13 ( V_37 -> V_11 , V_14 , V_15 , V_21 , V_262 ) )
return 0 ;
V_10 = V_42 ;
if ( ! V_263 )
V_10 |= V_32 ;
if ( V_262 & V_265 )
V_10 |= V_35 ;
else
V_10 |= V_34 ;
if ( V_262 & V_18 )
V_10 |= V_31 ;
if ( V_44 > V_45 )
V_10 |= V_43 ;
if ( V_266 )
V_10 |= V_118 -> V_267 ( V_37 , V_15 ,
F_49 ( V_21 ) ) ;
if ( V_264 )
V_10 |= V_63 ;
else
V_262 &= ~ V_17 ;
V_10 |= ( T_1 ) V_21 << V_19 ;
if ( V_262 & V_17 ) {
if ( V_44 > V_45 &&
F_82 ( V_37 -> V_11 , V_15 , V_44 ) )
goto V_268;
V_10 |= V_139 | V_64 ;
if ( ! V_260 && F_43 ( * V_14 ) )
goto V_269;
if ( F_219 ( V_37 , V_15 , V_260 ) ) {
F_213 ( L_15 ,
V_162 , V_15 ) ;
V_68 = 1 ;
V_262 &= ~ V_17 ;
V_10 &= ~ ( V_139 | V_64 ) ;
}
}
if ( V_262 & V_17 )
F_221 ( V_37 -> V_11 , V_15 ) ;
V_269:
if ( F_45 ( V_14 , V_10 ) )
F_107 ( V_37 -> V_11 ) ;
V_268:
return V_68 ;
}
static void F_222 ( struct V_36 * V_37 , T_1 * V_14 ,
unsigned V_262 , int V_270 , int * V_271 ,
int V_44 , T_2 V_15 , T_3 V_21 , bool V_263 ,
bool V_264 )
{
int V_272 = 0 ;
int V_273 ;
F_213 ( L_16 , V_162 ,
* V_14 , V_270 , V_15 ) ;
if ( F_25 ( * V_14 ) ) {
if ( V_44 > V_45 &&
! F_24 ( * V_14 ) ) {
struct V_51 * V_181 ;
T_1 V_41 = * V_14 ;
V_181 = F_37 ( V_41 & V_46 ) ;
F_144 ( V_181 , V_14 ) ;
F_107 ( V_37 -> V_11 ) ;
} else if ( V_21 != F_27 ( * V_14 ) ) {
F_213 ( L_17 ,
F_27 ( * V_14 ) , V_21 ) ;
F_104 ( V_37 -> V_11 , V_14 ) ;
F_107 ( V_37 -> V_11 ) ;
} else
V_272 = 1 ;
}
if ( F_220 ( V_37 , V_14 , V_262 , V_44 , V_15 , V_21 , V_263 ,
true , V_264 ) ) {
if ( V_270 )
* V_271 = 1 ;
F_164 ( V_37 ) ;
}
if ( F_14 ( F_10 ( * V_14 ) && V_271 ) )
* V_271 = 1 ;
F_213 ( L_18 , V_162 , * V_14 ) ;
F_213 ( L_19 ,
F_24 ( * V_14 ) ? L_20 : L_21 ,
* V_14 & V_42 ? L_22 : L_23 , V_15 ,
* V_14 , V_14 ) ;
if ( ! V_272 && F_24 ( * V_14 ) )
++ V_37 -> V_11 -> V_135 . V_136 ;
if ( F_23 ( * V_14 ) ) {
if ( ! V_272 ) {
V_273 = F_100 ( V_37 , V_14 , V_15 ) ;
if ( V_273 > V_274 )
F_132 ( V_37 , V_14 , V_15 ) ;
}
}
F_223 ( V_21 ) ;
}
static T_3 F_224 ( struct V_36 * V_37 , T_2 V_15 ,
bool V_111 )
{
struct V_99 * V_100 ;
V_100 = F_86 ( V_37 , V_15 , V_111 ) ;
if ( ! V_100 )
return V_275 ;
return F_225 ( V_100 , V_15 ) ;
}
static int F_226 ( struct V_36 * V_37 ,
struct V_51 * V_52 ,
T_1 * V_147 , T_1 * V_148 )
{
struct V_83 * V_198 [ V_87 ] ;
unsigned V_16 = V_52 -> V_94 . V_16 ;
int V_105 , V_68 ;
T_2 V_15 ;
V_15 = F_75 ( V_52 , V_147 - V_52 -> V_131 ) ;
if ( ! F_86 ( V_37 , V_15 , V_16 & V_17 ) )
return - 1 ;
V_68 = F_227 ( V_37 -> V_11 , V_15 , V_198 , V_148 - V_147 ) ;
if ( V_68 <= 0 )
return - 1 ;
for ( V_105 = 0 ; V_105 < V_68 ; V_105 ++ , V_15 ++ , V_147 ++ )
F_222 ( V_37 , V_147 , V_16 , 0 , NULL ,
V_52 -> V_94 . V_44 , V_15 , F_228 ( V_198 [ V_105 ] ) ,
true , true ) ;
return 0 ;
}
static void F_229 ( struct V_36 * V_37 ,
struct V_51 * V_52 , T_1 * V_14 )
{
T_1 * V_10 , * V_147 = NULL ;
int V_105 ;
F_3 ( ! V_52 -> V_94 . V_95 ) ;
V_105 = ( V_14 - V_52 -> V_131 ) & ~ ( V_87 - 1 ) ;
V_10 = V_52 -> V_131 + V_105 ;
for ( V_105 = 0 ; V_105 < V_87 ; V_105 ++ , V_10 ++ ) {
if ( F_23 ( * V_10 ) || V_10 == V_14 ) {
if ( ! V_147 )
continue;
if ( F_226 ( V_37 , V_52 , V_147 , V_10 ) < 0 )
break;
V_147 = NULL ;
} else if ( ! V_147 )
V_147 = V_10 ;
}
}
static void F_230 ( struct V_36 * V_37 , T_1 * V_14 )
{
struct V_51 * V_52 ;
if ( ! V_32 )
return;
V_52 = F_37 ( F_38 ( V_14 ) ) ;
if ( V_52 -> V_94 . V_44 > V_45 )
return;
F_229 ( V_37 , V_52 , V_14 ) ;
}
static int F_231 ( struct V_36 * V_37 , T_9 V_276 , int V_277 ,
int V_278 , int V_44 , T_2 V_15 , T_3 V_21 ,
bool V_279 )
{
struct V_218 V_219 ;
struct V_51 * V_52 ;
int V_271 = 0 ;
T_2 V_280 ;
F_232 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_219 . V_44 == V_44 ) {
F_222 ( V_37 , V_219 . V_14 , V_281 ,
V_277 , & V_271 , V_44 , V_15 , V_21 ,
V_279 , V_278 ) ;
F_230 ( V_37 , V_219 . V_14 ) ;
++ V_37 -> V_135 . V_282 ;
break;
}
if ( ! F_23 ( * V_219 . V_14 ) ) {
T_1 V_283 = V_219 . V_220 ;
V_283 &= F_233 ( V_219 . V_44 ) ;
V_280 = V_283 >> V_19 ;
V_52 = F_183 ( V_37 , V_280 , V_219 . V_220 ,
V_219 . V_44 - 1 ,
1 , V_281 , V_219 . V_14 ) ;
F_194 ( V_219 . V_14 , V_52 , true ) ;
}
}
return V_271 ;
}
static void F_234 ( unsigned long V_284 , struct V_285 * V_286 )
{
T_10 V_287 ;
V_287 . V_288 = V_289 ;
V_287 . V_290 = 0 ;
V_287 . V_291 = V_292 ;
V_287 . V_293 = ( void V_294 * ) V_284 ;
V_287 . V_295 = V_19 ;
F_235 ( V_289 , & V_287 , V_286 ) ;
}
static int F_236 ( struct V_36 * V_37 , T_2 V_15 , T_3 V_21 )
{
if ( V_21 == V_296 )
return 1 ;
if ( V_21 == V_297 ) {
F_234 ( F_237 ( V_37 -> V_11 , V_15 ) , V_298 ) ;
return 0 ;
}
return - V_299 ;
}
static void F_238 ( struct V_36 * V_37 ,
T_2 * V_300 , T_3 * V_301 , int * V_302 )
{
T_3 V_21 = * V_301 ;
T_2 V_15 = * V_300 ;
int V_44 = * V_302 ;
if ( ! F_239 ( V_21 ) && ! F_49 ( V_21 ) &&
V_44 == V_45 &&
F_240 ( F_51 ( V_21 ) ) &&
! F_82 ( V_37 -> V_11 , V_15 , V_106 ) ) {
unsigned long V_4 ;
* V_302 = V_44 = V_106 ;
V_4 = F_241 ( V_44 ) - 1 ;
F_242 ( ( V_15 & V_4 ) != ( V_21 & V_4 ) ) ;
if ( V_21 & V_4 ) {
V_15 &= ~ V_4 ;
* V_300 = V_15 ;
F_223 ( V_21 ) ;
V_21 &= ~ V_4 ;
F_243 ( V_21 ) ;
* V_301 = V_21 ;
}
}
}
static bool F_244 ( struct V_36 * V_37 , T_7 V_175 , T_2 V_15 ,
T_3 V_21 , unsigned V_16 , int * V_303 )
{
bool V_68 = true ;
if ( F_14 ( F_245 ( V_21 ) ) ) {
* V_303 = F_236 ( V_37 , V_15 , V_21 ) ;
goto exit;
}
if ( F_14 ( F_15 ( V_21 ) ) )
F_246 ( V_37 , V_175 , V_15 , V_16 ) ;
V_68 = false ;
exit:
return V_68 ;
}
static bool F_247 ( T_4 V_304 )
{
if ( F_14 ( V_304 & V_305 ) )
return false ;
if ( ! ( V_304 & V_306 ) ||
! ( V_304 & V_307 ) )
return false ;
return true ;
}
static bool
F_248 ( struct V_36 * V_37 , T_1 * V_14 , T_1 V_10 )
{
struct V_51 * V_52 = F_37 ( F_38 ( V_14 ) ) ;
T_2 V_15 ;
F_3 ( ! V_52 -> V_94 . V_95 ) ;
V_15 = F_75 ( V_52 , V_14 - V_52 -> V_131 ) ;
if ( F_249 ( V_14 , V_10 , V_10 | V_139 ) == V_10 )
F_221 ( V_37 -> V_11 , V_15 ) ;
return true ;
}
static bool F_250 ( struct V_36 * V_37 , T_7 V_175 , int V_44 ,
T_4 V_304 )
{
struct V_218 V_219 ;
bool V_68 = false ;
T_1 V_10 = 0ull ;
if ( ! F_247 ( V_304 ) )
return false ;
F_54 ( V_37 ) ;
F_251 (vcpu, gva, iterator, spte)
if ( ! F_23 ( V_10 ) || V_219 . V_44 < V_44 )
break;
if ( ! F_25 ( V_10 ) ) {
V_68 = true ;
goto exit;
}
if ( ! F_26 ( V_10 , V_44 ) )
goto exit;
if ( F_43 ( V_10 ) ) {
V_68 = true ;
goto exit;
}
if ( ! F_41 ( V_10 ) )
goto exit;
V_68 = F_248 ( V_37 , V_219 . V_14 , V_10 ) ;
exit:
F_252 ( V_37 , V_175 , V_304 , V_219 . V_14 ,
V_10 , V_68 ) ;
F_57 ( V_37 ) ;
return V_68 ;
}
static int F_253 ( struct V_36 * V_37 , T_7 V_276 , T_4 V_304 ,
T_2 V_15 , bool V_279 )
{
int V_84 ;
int V_44 ;
int V_308 ;
T_3 V_21 ;
unsigned long V_309 ;
bool V_278 , V_277 = V_304 & V_307 ;
V_308 = F_87 ( V_37 , V_15 ) ;
if ( F_18 ( ! V_308 ) ) {
V_44 = F_88 ( V_37 , V_15 ) ;
if ( V_44 > V_106 )
V_44 = V_106 ;
V_15 &= ~ ( F_241 ( V_44 ) - 1 ) ;
} else
V_44 = V_45 ;
if ( F_250 ( V_37 , V_276 , V_44 , V_304 ) )
return 0 ;
V_309 = V_37 -> V_11 -> V_310 ;
F_40 () ;
if ( F_254 ( V_37 , V_279 , V_15 , V_276 , & V_21 , V_277 , & V_278 ) )
return 0 ;
if ( F_244 ( V_37 , V_276 , V_15 , V_21 , V_281 , & V_84 ) )
return V_84 ;
F_210 ( & V_37 -> V_11 -> V_200 ) ;
if ( F_255 ( V_37 -> V_11 , V_309 ) )
goto V_311;
F_256 ( V_37 ) ;
if ( F_18 ( ! V_308 ) )
F_238 ( V_37 , & V_15 , & V_21 , & V_44 ) ;
V_84 = F_231 ( V_37 , V_276 , V_277 , V_278 , V_44 , V_15 , V_21 ,
V_279 ) ;
F_211 ( & V_37 -> V_11 -> V_200 ) ;
return V_84 ;
V_311:
F_211 ( & V_37 -> V_11 -> V_200 ) ;
F_223 ( V_21 ) ;
return 0 ;
}
static void F_257 ( struct V_36 * V_37 )
{
int V_105 ;
struct V_51 * V_52 ;
F_166 ( V_187 ) ;
if ( ! F_258 ( V_37 -> V_38 . V_190 . V_222 ) )
return;
if ( V_37 -> V_38 . V_190 . V_223 == V_197 &&
( V_37 -> V_38 . V_190 . V_210 == V_197 ||
V_37 -> V_38 . V_190 . V_209 ) ) {
T_11 V_312 = V_37 -> V_38 . V_190 . V_222 ;
F_210 ( & V_37 -> V_11 -> V_200 ) ;
V_52 = F_37 ( V_312 ) ;
-- V_52 -> V_233 ;
if ( ! V_52 -> V_233 && V_52 -> V_94 . V_232 ) {
F_163 ( V_37 -> V_11 , V_52 , & V_187 ) ;
F_167 ( V_37 -> V_11 , & V_187 ) ;
}
F_211 ( & V_37 -> V_11 -> V_200 ) ;
V_37 -> V_38 . V_190 . V_222 = V_313 ;
return;
}
F_210 ( & V_37 -> V_11 -> V_200 ) ;
for ( V_105 = 0 ; V_105 < 4 ; ++ V_105 ) {
T_11 V_312 = V_37 -> V_38 . V_190 . V_225 [ V_105 ] ;
if ( V_312 ) {
V_312 &= V_46 ;
V_52 = F_37 ( V_312 ) ;
-- V_52 -> V_233 ;
if ( ! V_52 -> V_233 && V_52 -> V_94 . V_232 )
F_163 ( V_37 -> V_11 , V_52 ,
& V_187 ) ;
}
V_37 -> V_38 . V_190 . V_225 [ V_105 ] = V_313 ;
}
F_167 ( V_37 -> V_11 , & V_187 ) ;
F_211 ( & V_37 -> V_11 -> V_200 ) ;
V_37 -> V_38 . V_190 . V_222 = V_313 ;
}
static int F_259 ( struct V_36 * V_37 , T_2 V_314 )
{
int V_68 = 0 ;
if ( ! F_260 ( V_37 -> V_11 , V_314 ) ) {
F_185 ( V_315 , V_37 ) ;
V_68 = 1 ;
}
return V_68 ;
}
static int F_261 ( struct V_36 * V_37 )
{
struct V_51 * V_52 ;
unsigned V_105 ;
if ( V_37 -> V_38 . V_190 . V_223 == V_197 ) {
F_210 ( & V_37 -> V_11 -> V_200 ) ;
F_256 ( V_37 ) ;
V_52 = F_183 ( V_37 , 0 , 0 , V_197 ,
1 , V_281 , NULL ) ;
++ V_52 -> V_233 ;
F_211 ( & V_37 -> V_11 -> V_200 ) ;
V_37 -> V_38 . V_190 . V_222 = F_38 ( V_52 -> V_131 ) ;
} else if ( V_37 -> V_38 . V_190 . V_223 == V_224 ) {
for ( V_105 = 0 ; V_105 < 4 ; ++ V_105 ) {
T_11 V_312 = V_37 -> V_38 . V_190 . V_225 [ V_105 ] ;
ASSERT ( ! F_258 ( V_312 ) ) ;
F_210 ( & V_37 -> V_11 -> V_200 ) ;
F_256 ( V_37 ) ;
V_52 = F_183 ( V_37 , V_105 << ( 30 - V_19 ) ,
V_105 << 30 ,
V_211 , 1 , V_281 ,
NULL ) ;
V_312 = F_38 ( V_52 -> V_131 ) ;
++ V_52 -> V_233 ;
F_211 ( & V_37 -> V_11 -> V_200 ) ;
V_37 -> V_38 . V_190 . V_225 [ V_105 ] = V_312 | V_42 ;
}
V_37 -> V_38 . V_190 . V_222 = F_38 ( V_37 -> V_38 . V_190 . V_225 ) ;
} else
F_94 () ;
return 0 ;
}
static int F_262 ( struct V_36 * V_37 )
{
struct V_51 * V_52 ;
T_1 V_316 , V_317 ;
T_2 V_314 ;
int V_105 ;
V_314 = V_37 -> V_38 . V_190 . V_318 ( V_37 ) >> V_19 ;
if ( F_259 ( V_37 , V_314 ) )
return 1 ;
if ( V_37 -> V_38 . V_190 . V_210 == V_197 ) {
T_11 V_312 = V_37 -> V_38 . V_190 . V_222 ;
ASSERT ( ! F_258 ( V_312 ) ) ;
F_210 ( & V_37 -> V_11 -> V_200 ) ;
F_256 ( V_37 ) ;
V_52 = F_183 ( V_37 , V_314 , 0 , V_197 ,
0 , V_281 , NULL ) ;
V_312 = F_38 ( V_52 -> V_131 ) ;
++ V_52 -> V_233 ;
F_211 ( & V_37 -> V_11 -> V_200 ) ;
V_37 -> V_38 . V_190 . V_222 = V_312 ;
return 0 ;
}
V_317 = V_42 ;
if ( V_37 -> V_38 . V_190 . V_223 == V_197 )
V_317 |= V_319 | V_139 | V_320 ;
for ( V_105 = 0 ; V_105 < 4 ; ++ V_105 ) {
T_11 V_312 = V_37 -> V_38 . V_190 . V_225 [ V_105 ] ;
ASSERT ( ! F_258 ( V_312 ) ) ;
if ( V_37 -> V_38 . V_190 . V_210 == V_224 ) {
V_316 = V_37 -> V_38 . V_190 . V_321 ( V_37 , V_105 ) ;
if ( ! F_263 ( V_316 ) ) {
V_37 -> V_38 . V_190 . V_225 [ V_105 ] = 0 ;
continue;
}
V_314 = V_316 >> V_19 ;
if ( F_259 ( V_37 , V_314 ) )
return 1 ;
}
F_210 ( & V_37 -> V_11 -> V_200 ) ;
F_256 ( V_37 ) ;
V_52 = F_183 ( V_37 , V_314 , V_105 << 30 ,
V_211 , 0 ,
V_281 , NULL ) ;
V_312 = F_38 ( V_52 -> V_131 ) ;
++ V_52 -> V_233 ;
F_211 ( & V_37 -> V_11 -> V_200 ) ;
V_37 -> V_38 . V_190 . V_225 [ V_105 ] = V_312 | V_317 ;
}
V_37 -> V_38 . V_190 . V_222 = F_38 ( V_37 -> V_38 . V_190 . V_225 ) ;
if ( V_37 -> V_38 . V_190 . V_223 == V_197 ) {
if ( V_37 -> V_38 . V_190 . V_322 == NULL ) {
T_1 * V_322 ;
V_322 = ( void * ) F_264 ( V_80 ) ;
if ( V_322 == NULL )
return 1 ;
V_322 [ 0 ] = F_38 ( V_37 -> V_38 . V_190 . V_225 ) | V_317 ;
V_37 -> V_38 . V_190 . V_322 = V_322 ;
}
V_37 -> V_38 . V_190 . V_222 = F_38 ( V_37 -> V_38 . V_190 . V_322 ) ;
}
return 0 ;
}
static int F_265 ( struct V_36 * V_37 )
{
if ( V_37 -> V_38 . V_190 . V_209 )
return F_261 ( V_37 ) ;
else
return F_262 ( V_37 ) ;
}
static void F_266 ( struct V_36 * V_37 )
{
int V_105 ;
struct V_51 * V_52 ;
if ( V_37 -> V_38 . V_190 . V_209 )
return;
if ( ! F_258 ( V_37 -> V_38 . V_190 . V_222 ) )
return;
F_267 ( V_37 , ~ 0ul ) ;
F_168 ( V_37 , V_323 ) ;
if ( V_37 -> V_38 . V_190 . V_210 == V_197 ) {
T_11 V_312 = V_37 -> V_38 . V_190 . V_222 ;
V_52 = F_37 ( V_312 ) ;
F_176 ( V_37 , V_52 ) ;
F_168 ( V_37 , V_324 ) ;
return;
}
for ( V_105 = 0 ; V_105 < 4 ; ++ V_105 ) {
T_11 V_312 = V_37 -> V_38 . V_190 . V_225 [ V_105 ] ;
if ( V_312 && F_258 ( V_312 ) ) {
V_312 &= V_46 ;
V_52 = F_37 ( V_312 ) ;
F_176 ( V_37 , V_52 ) ;
}
}
F_168 ( V_37 , V_324 ) ;
}
void F_268 ( struct V_36 * V_37 )
{
F_210 ( & V_37 -> V_11 -> V_200 ) ;
F_266 ( V_37 ) ;
F_211 ( & V_37 -> V_11 -> V_200 ) ;
}
static T_9 F_269 ( struct V_36 * V_37 , T_7 V_325 ,
T_4 V_16 , struct V_326 * V_327 )
{
if ( V_327 )
V_327 -> V_304 = 0 ;
return V_325 ;
}
static T_9 F_270 ( struct V_36 * V_37 , T_7 V_325 ,
T_4 V_16 ,
struct V_326 * V_327 )
{
if ( V_327 )
V_327 -> V_304 = 0 ;
return V_37 -> V_38 . V_328 . V_329 ( V_37 , V_325 , V_16 ) ;
}
static bool F_271 ( struct V_36 * V_37 , T_1 V_220 , bool V_95 )
{
if ( V_95 )
return F_272 ( V_37 , V_220 ) ;
return F_273 ( V_37 , V_220 ) ;
}
static bool F_274 ( T_1 V_10 )
{
return F_35 ( V_10 ) ;
}
static T_1 F_275 ( struct V_36 * V_37 , T_1 V_220 )
{
struct V_218 V_219 ;
T_1 V_10 = 0ull ;
F_54 ( V_37 ) ;
F_251 (vcpu, addr, iterator, spte)
if ( ! F_23 ( V_10 ) )
break;
F_57 ( V_37 ) ;
return V_10 ;
}
int F_276 ( struct V_36 * V_37 , T_1 V_220 , bool V_95 )
{
T_1 V_10 ;
if ( F_271 ( V_37 , V_220 , V_95 ) )
return V_330 ;
V_10 = F_275 ( V_37 , V_220 ) ;
if ( F_10 ( V_10 ) ) {
T_2 V_15 = F_11 ( V_10 ) ;
unsigned V_16 = F_12 ( V_10 ) ;
if ( ! F_16 ( V_37 -> V_11 , V_10 ) )
return V_331 ;
if ( V_95 )
V_220 = 0 ;
F_277 ( V_220 , V_15 , V_16 ) ;
F_246 ( V_37 , V_220 , V_15 , V_16 ) ;
return V_330 ;
}
if ( V_95 && ! F_274 ( V_10 ) )
return V_332 ;
return V_333 ;
}
static int F_278 ( struct V_36 * V_37 , T_1 V_220 ,
T_4 V_304 , bool V_95 )
{
int V_68 ;
V_68 = F_276 ( V_37 , V_220 , V_95 ) ;
F_3 ( V_68 == V_332 ) ;
return V_68 ;
}
static int F_279 ( struct V_36 * V_37 , T_7 V_175 ,
T_4 V_304 , bool V_279 )
{
T_2 V_15 ;
int V_84 ;
F_213 ( L_24 , V_162 , V_175 , V_304 ) ;
if ( F_14 ( V_304 & V_305 ) ) {
V_84 = F_278 ( V_37 , V_175 , V_304 , true ) ;
if ( F_18 ( V_84 != V_331 ) )
return V_84 ;
}
V_84 = F_69 ( V_37 ) ;
if ( V_84 )
return V_84 ;
ASSERT ( V_37 ) ;
ASSERT ( F_258 ( V_37 -> V_38 . V_190 . V_222 ) ) ;
V_15 = V_175 >> V_19 ;
return F_253 ( V_37 , V_175 & V_20 ,
V_304 , V_15 , V_279 ) ;
}
static int F_280 ( struct V_36 * V_37 , T_7 V_175 , T_2 V_15 )
{
struct V_334 V_38 ;
V_38 . V_335 = ( V_37 -> V_38 . V_336 . V_337 ++ << 12 ) | V_37 -> V_338 ;
V_38 . V_15 = V_15 ;
V_38 . V_209 = V_37 -> V_38 . V_190 . V_209 ;
V_38 . V_339 = V_37 -> V_38 . V_190 . V_318 ( V_37 ) ;
return F_281 ( V_37 , V_175 , V_15 , & V_38 ) ;
}
static bool F_282 ( struct V_36 * V_37 )
{
if ( F_14 ( ! F_283 ( V_37 -> V_11 ) ||
F_284 ( V_37 ) ) )
return false ;
return V_118 -> V_340 ( V_37 ) ;
}
static bool F_254 ( struct V_36 * V_37 , bool V_279 , T_2 V_15 ,
T_7 V_175 , T_3 * V_21 , bool V_277 , bool * V_341 )
{
bool V_342 ;
* V_21 = F_285 ( V_37 -> V_11 , V_15 , & V_342 , V_277 , V_341 ) ;
if ( ! V_342 )
return false ;
if ( ! V_279 && F_282 ( V_37 ) ) {
F_286 ( V_175 , V_15 ) ;
if ( F_287 ( V_37 , V_15 ) ) {
F_288 ( V_175 , V_15 ) ;
F_185 ( V_343 , V_37 ) ;
return true ;
} else if ( F_280 ( V_37 , V_175 , V_15 ) )
return true ;
}
* V_21 = F_289 ( V_37 -> V_11 , V_15 , V_277 , V_341 ) ;
return false ;
}
static int F_290 ( struct V_36 * V_37 , T_7 V_344 , T_4 V_304 ,
bool V_279 )
{
T_3 V_21 ;
int V_84 ;
int V_44 ;
int V_308 ;
T_2 V_15 = V_344 >> V_19 ;
unsigned long V_309 ;
int V_277 = V_304 & V_307 ;
bool V_278 ;
ASSERT ( V_37 ) ;
ASSERT ( F_258 ( V_37 -> V_38 . V_190 . V_222 ) ) ;
if ( F_14 ( V_304 & V_305 ) ) {
V_84 = F_278 ( V_37 , V_344 , V_304 , true ) ;
if ( F_18 ( V_84 != V_331 ) )
return V_84 ;
}
V_84 = F_69 ( V_37 ) ;
if ( V_84 )
return V_84 ;
V_308 = F_87 ( V_37 , V_15 ) ;
if ( F_18 ( ! V_308 ) ) {
V_44 = F_88 ( V_37 , V_15 ) ;
V_15 &= ~ ( F_241 ( V_44 ) - 1 ) ;
} else
V_44 = V_45 ;
if ( F_250 ( V_37 , V_344 , V_44 , V_304 ) )
return 0 ;
V_309 = V_37 -> V_11 -> V_310 ;
F_40 () ;
if ( F_254 ( V_37 , V_279 , V_15 , V_344 , & V_21 , V_277 , & V_278 ) )
return 0 ;
if ( F_244 ( V_37 , 0 , V_15 , V_21 , V_281 , & V_84 ) )
return V_84 ;
F_210 ( & V_37 -> V_11 -> V_200 ) ;
if ( F_255 ( V_37 -> V_11 , V_309 ) )
goto V_311;
F_256 ( V_37 ) ;
if ( F_18 ( ! V_308 ) )
F_238 ( V_37 , & V_15 , & V_21 , & V_44 ) ;
V_84 = F_231 ( V_37 , V_344 , V_277 , V_278 ,
V_44 , V_15 , V_21 , V_279 ) ;
F_211 ( & V_37 -> V_11 -> V_200 ) ;
return V_84 ;
V_311:
F_211 ( & V_37 -> V_11 -> V_200 ) ;
F_223 ( V_21 ) ;
return 0 ;
}
static void F_291 ( struct V_36 * V_37 ,
struct V_345 * V_346 )
{
V_346 -> V_347 = F_279 ;
V_346 -> V_348 = F_269 ;
V_346 -> V_191 = F_151 ;
V_346 -> V_349 = F_152 ;
V_346 -> V_350 = F_153 ;
V_346 -> V_210 = 0 ;
V_346 -> V_223 = V_224 ;
V_346 -> V_222 = V_313 ;
V_346 -> V_209 = true ;
V_346 -> V_351 = false ;
}
void F_164 ( struct V_36 * V_37 )
{
++ V_37 -> V_135 . V_352 ;
F_185 ( V_353 , V_37 ) ;
}
void F_292 ( struct V_36 * V_37 )
{
F_257 ( V_37 ) ;
}
static unsigned long V_318 ( struct V_36 * V_37 )
{
return F_293 ( V_37 ) ;
}
static void F_294 ( struct V_36 * V_37 ,
struct V_326 * V_354 )
{
V_37 -> V_38 . V_190 . F_294 ( V_37 , V_354 ) ;
}
static bool F_295 ( struct V_11 * V_11 , T_1 * V_14 , T_2 V_15 ,
unsigned V_16 , int * V_355 )
{
if ( F_14 ( F_10 ( * V_14 ) ) ) {
if ( V_15 != F_11 ( * V_14 ) ) {
F_52 ( V_14 ) ;
return true ;
}
( * V_355 ) ++ ;
F_7 ( V_11 , V_14 , V_15 , V_16 ) ;
return true ;
}
return false ;
}
static inline bool F_296 ( struct V_345 * V_190 , unsigned V_44 , unsigned V_47 )
{
unsigned V_93 ;
V_93 = V_44 - 1 ;
V_93 |= ( V_47 & V_43 ) >> ( V_356 - 2 ) ;
return V_190 -> V_357 & ( 1 << V_93 ) ;
}
static void F_297 ( struct V_36 * V_37 ,
struct V_345 * V_346 )
{
int V_358 = F_298 ( V_37 ) ;
T_1 V_359 = 0 ;
V_346 -> V_360 = 0 ;
if ( ! V_346 -> V_351 )
V_359 = F_19 ( 63 , 63 ) ;
switch ( V_346 -> V_210 ) {
case V_211 :
V_346 -> V_361 [ 0 ] [ 1 ] = 0 ;
V_346 -> V_361 [ 0 ] [ 0 ] = 0 ;
V_346 -> V_361 [ 1 ] [ 0 ] = V_346 -> V_361 [ 0 ] [ 0 ] ;
if ( ! F_299 ( V_37 ) ) {
V_346 -> V_361 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_21 () )
V_346 -> V_361 [ 1 ] [ 1 ] = F_19 ( 17 , 21 ) ;
else
V_346 -> V_361 [ 1 ] [ 1 ] = F_19 ( 13 , 21 ) ;
break;
case V_224 :
V_346 -> V_361 [ 0 ] [ 2 ] =
F_19 ( V_358 , 63 ) |
F_19 ( 7 , 8 ) | F_19 ( 1 , 2 ) ;
V_346 -> V_361 [ 0 ] [ 1 ] = V_359 |
F_19 ( V_358 , 62 ) ;
V_346 -> V_361 [ 0 ] [ 0 ] = V_359 |
F_19 ( V_358 , 62 ) ;
V_346 -> V_361 [ 1 ] [ 1 ] = V_359 |
F_19 ( V_358 , 62 ) |
F_19 ( 13 , 20 ) ;
V_346 -> V_361 [ 1 ] [ 0 ] = V_346 -> V_361 [ 0 ] [ 0 ] ;
break;
case V_197 :
V_346 -> V_361 [ 0 ] [ 3 ] = V_359 |
F_19 ( V_358 , 51 ) | F_19 ( 7 , 8 ) ;
V_346 -> V_361 [ 0 ] [ 2 ] = V_359 |
F_19 ( V_358 , 51 ) | F_19 ( 7 , 8 ) ;
V_346 -> V_361 [ 0 ] [ 1 ] = V_359 |
F_19 ( V_358 , 51 ) ;
V_346 -> V_361 [ 0 ] [ 0 ] = V_359 |
F_19 ( V_358 , 51 ) ;
V_346 -> V_361 [ 1 ] [ 3 ] = V_346 -> V_361 [ 0 ] [ 3 ] ;
V_346 -> V_361 [ 1 ] [ 2 ] = V_359 |
F_19 ( V_358 , 51 ) |
F_19 ( 13 , 29 ) ;
V_346 -> V_361 [ 1 ] [ 1 ] = V_359 |
F_19 ( V_358 , 51 ) |
F_19 ( 13 , 20 ) ;
V_346 -> V_361 [ 1 ] [ 0 ] = V_346 -> V_361 [ 0 ] [ 0 ] ;
break;
}
}
static void F_300 ( struct V_36 * V_37 ,
struct V_345 * V_346 , bool V_362 )
{
int V_358 = F_298 ( V_37 ) ;
int V_41 ;
V_346 -> V_361 [ 0 ] [ 3 ] =
F_19 ( V_358 , 51 ) | F_19 ( 3 , 7 ) ;
V_346 -> V_361 [ 0 ] [ 2 ] =
F_19 ( V_358 , 51 ) | F_19 ( 3 , 6 ) ;
V_346 -> V_361 [ 0 ] [ 1 ] =
F_19 ( V_358 , 51 ) | F_19 ( 3 , 6 ) ;
V_346 -> V_361 [ 0 ] [ 0 ] = F_19 ( V_358 , 51 ) ;
V_346 -> V_361 [ 1 ] [ 3 ] = V_346 -> V_361 [ 0 ] [ 3 ] ;
V_346 -> V_361 [ 1 ] [ 2 ] =
F_19 ( V_358 , 51 ) | F_19 ( 12 , 29 ) ;
V_346 -> V_361 [ 1 ] [ 1 ] =
F_19 ( V_358 , 51 ) | F_19 ( 12 , 20 ) ;
V_346 -> V_361 [ 1 ] [ 0 ] = V_346 -> V_361 [ 0 ] [ 0 ] ;
for ( V_41 = 0 ; V_41 < 64 ; V_41 ++ ) {
int V_363 = V_41 & 7 ;
int V_364 = V_41 >> 3 ;
if ( V_364 == 0x2 || V_364 == 0x3 || V_364 == 0x7 ||
V_363 == 0x2 || V_363 == 0x6 ||
( V_363 == 0x4 && ! V_362 ) )
V_346 -> V_360 |= ( 1ull << V_41 ) ;
}
}
static void F_301 ( struct V_36 * V_37 ,
struct V_345 * V_190 , bool V_365 )
{
unsigned V_366 , V_367 , V_368 ;
T_8 V_369 ;
bool V_354 , V_370 , V_371 , V_372 , V_373 , V_374 , V_375 , V_376 ;
V_376 = F_302 ( V_37 , V_377 ) ;
for ( V_367 = 0 ; V_367 < F_60 ( V_190 -> V_378 ) ; ++ V_367 ) {
V_368 = V_367 << 1 ;
V_369 = 0 ;
V_373 = V_368 & V_307 ;
V_374 = V_368 & V_379 ;
V_375 = V_368 & V_380 ;
for ( V_366 = 0 ; V_366 < 8 ; ++ V_366 ) {
V_370 = V_366 & V_265 ;
V_371 = V_366 & V_17 ;
V_372 = V_366 & V_18 ;
if ( ! V_365 ) {
V_370 |= ! V_190 -> V_351 ;
V_371 |= ! F_303 ( V_37 ) && ! V_374 ;
V_370 &= ! ( V_376 && V_372 && ! V_374 ) ;
} else
V_372 = 1 ;
V_354 = ( V_375 && ! V_370 ) || ( V_374 && ! V_372 ) || ( V_373 && ! V_371 ) ;
V_369 |= V_354 << V_366 ;
}
V_190 -> V_378 [ V_367 ] = V_369 ;
}
}
static void F_304 ( struct V_36 * V_37 , struct V_345 * V_190 )
{
T_8 V_369 ;
unsigned V_44 , V_210 = V_190 -> V_210 ;
const unsigned V_381 = 1 << 2 ;
if ( V_210 == V_224 )
-- V_210 ;
V_369 = 1 | ( 1 << V_381 ) ;
for ( V_44 = V_106 ; V_44 <= V_210 ; ++ V_44 ) {
if ( V_44 <= V_382
&& ( V_190 -> V_210 >= V_224 || F_299 ( V_37 ) ) )
V_369 |= 1 << ( V_381 | ( V_44 - 1 ) ) ;
}
V_190 -> V_357 = V_369 ;
}
static void F_305 ( struct V_36 * V_37 ,
struct V_345 * V_346 ,
int V_44 )
{
V_346 -> V_351 = F_22 ( V_37 ) ;
V_346 -> V_210 = V_44 ;
F_297 ( V_37 , V_346 ) ;
F_301 ( V_37 , V_346 , false ) ;
F_304 ( V_37 , V_346 ) ;
ASSERT ( F_162 ( V_37 ) ) ;
V_346 -> V_347 = V_383 ;
V_346 -> V_348 = V_384 ;
V_346 -> V_191 = V_385 ;
V_346 -> V_349 = V_386 ;
V_346 -> V_350 = V_387 ;
V_346 -> V_223 = V_44 ;
V_346 -> V_222 = V_313 ;
V_346 -> V_209 = false ;
}
static void F_306 ( struct V_36 * V_37 ,
struct V_345 * V_346 )
{
F_305 ( V_37 , V_346 , V_197 ) ;
}
static void F_307 ( struct V_36 * V_37 ,
struct V_345 * V_346 )
{
V_346 -> V_351 = false ;
V_346 -> V_210 = V_211 ;
F_297 ( V_37 , V_346 ) ;
F_301 ( V_37 , V_346 , false ) ;
F_304 ( V_37 , V_346 ) ;
V_346 -> V_347 = V_388 ;
V_346 -> V_348 = V_389 ;
V_346 -> V_191 = V_390 ;
V_346 -> V_349 = V_391 ;
V_346 -> V_350 = V_392 ;
V_346 -> V_223 = V_224 ;
V_346 -> V_222 = V_313 ;
V_346 -> V_209 = false ;
}
static void F_308 ( struct V_36 * V_37 ,
struct V_345 * V_346 )
{
F_305 ( V_37 , V_346 , V_224 ) ;
}
static void F_309 ( struct V_36 * V_37 )
{
struct V_345 * V_346 = V_37 -> V_38 . V_393 ;
V_346 -> V_208 . V_214 = 0 ;
V_346 -> V_347 = F_290 ;
V_346 -> V_191 = F_151 ;
V_346 -> V_349 = F_152 ;
V_346 -> V_350 = F_153 ;
V_346 -> V_223 = V_118 -> V_394 () ;
V_346 -> V_222 = V_313 ;
V_346 -> V_209 = true ;
V_346 -> V_395 = V_118 -> V_396 ;
V_346 -> V_318 = V_318 ;
V_346 -> V_321 = V_397 ;
V_346 -> F_294 = V_398 ;
if ( ! F_310 ( V_37 ) ) {
V_346 -> V_351 = false ;
V_346 -> V_348 = F_269 ;
V_346 -> V_210 = 0 ;
} else if ( F_311 ( V_37 ) ) {
V_346 -> V_351 = F_22 ( V_37 ) ;
V_346 -> V_210 = V_197 ;
F_297 ( V_37 , V_346 ) ;
V_346 -> V_348 = V_384 ;
} else if ( F_162 ( V_37 ) ) {
V_346 -> V_351 = F_22 ( V_37 ) ;
V_346 -> V_210 = V_224 ;
F_297 ( V_37 , V_346 ) ;
V_346 -> V_348 = V_384 ;
} else {
V_346 -> V_351 = false ;
V_346 -> V_210 = V_211 ;
F_297 ( V_37 , V_346 ) ;
V_346 -> V_348 = V_389 ;
}
F_301 ( V_37 , V_346 , false ) ;
F_304 ( V_37 , V_346 ) ;
}
void F_312 ( struct V_36 * V_37 , struct V_345 * V_346 )
{
bool V_376 = F_302 ( V_37 , V_377 ) ;
ASSERT ( V_37 ) ;
ASSERT ( ! F_258 ( V_37 -> V_38 . V_190 . V_222 ) ) ;
if ( ! F_310 ( V_37 ) )
F_291 ( V_37 , V_346 ) ;
else if ( F_311 ( V_37 ) )
F_306 ( V_37 , V_346 ) ;
else if ( F_162 ( V_37 ) )
F_308 ( V_37 , V_346 ) ;
else
F_307 ( V_37 , V_346 ) ;
V_37 -> V_38 . V_190 . V_208 . V_399 = F_22 ( V_37 ) ;
V_37 -> V_38 . V_190 . V_208 . V_189 = ! ! F_162 ( V_37 ) ;
V_37 -> V_38 . V_190 . V_208 . V_400 = F_303 ( V_37 ) ;
V_37 -> V_38 . V_190 . V_208 . V_401
= V_376 && ! F_303 ( V_37 ) ;
}
void F_313 ( struct V_36 * V_37 , struct V_345 * V_346 ,
bool V_362 )
{
ASSERT ( V_37 ) ;
ASSERT ( ! F_258 ( V_37 -> V_38 . V_190 . V_222 ) ) ;
V_346 -> V_223 = V_118 -> V_394 () ;
V_346 -> V_351 = true ;
V_346 -> V_347 = V_402 ;
V_346 -> V_348 = V_403 ;
V_346 -> V_191 = V_404 ;
V_346 -> V_349 = V_405 ;
V_346 -> V_350 = V_406 ;
V_346 -> V_210 = V_346 -> V_223 ;
V_346 -> V_222 = V_313 ;
V_346 -> V_209 = false ;
F_301 ( V_37 , V_346 , true ) ;
F_300 ( V_37 , V_346 , V_362 ) ;
}
static void F_314 ( struct V_36 * V_37 )
{
F_312 ( V_37 , V_37 -> V_38 . V_393 ) ;
V_37 -> V_38 . V_393 -> V_395 = V_118 -> V_395 ;
V_37 -> V_38 . V_393 -> V_318 = V_318 ;
V_37 -> V_38 . V_393 -> V_321 = V_397 ;
V_37 -> V_38 . V_393 -> F_294 = V_398 ;
}
static void F_315 ( struct V_36 * V_37 )
{
struct V_345 * V_407 = & V_37 -> V_38 . V_328 ;
V_407 -> V_318 = V_318 ;
V_407 -> V_321 = V_397 ;
V_407 -> F_294 = V_398 ;
if ( ! F_310 ( V_37 ) ) {
V_407 -> V_351 = false ;
V_407 -> V_210 = 0 ;
V_407 -> V_348 = F_270 ;
} else if ( F_311 ( V_37 ) ) {
V_407 -> V_351 = F_22 ( V_37 ) ;
V_407 -> V_210 = V_197 ;
F_297 ( V_37 , V_407 ) ;
V_407 -> V_348 = V_408 ;
} else if ( F_162 ( V_37 ) ) {
V_407 -> V_351 = F_22 ( V_37 ) ;
V_407 -> V_210 = V_224 ;
F_297 ( V_37 , V_407 ) ;
V_407 -> V_348 = V_408 ;
} else {
V_407 -> V_351 = false ;
V_407 -> V_210 = V_211 ;
F_297 ( V_37 , V_407 ) ;
V_407 -> V_348 = V_409 ;
}
F_301 ( V_37 , V_407 , false ) ;
F_304 ( V_37 , V_407 ) ;
}
static void F_316 ( struct V_36 * V_37 )
{
if ( F_317 ( V_37 ) )
return F_315 ( V_37 ) ;
else if ( V_266 )
return F_309 ( V_37 ) ;
else
return F_314 ( V_37 ) ;
}
void F_318 ( struct V_36 * V_37 )
{
ASSERT ( V_37 ) ;
F_319 ( V_37 ) ;
F_316 ( V_37 ) ;
}
int F_320 ( struct V_36 * V_37 )
{
int V_84 ;
V_84 = F_69 ( V_37 ) ;
if ( V_84 )
goto V_88;
V_84 = F_265 ( V_37 ) ;
F_268 ( V_37 ) ;
if ( V_84 )
goto V_88;
V_37 -> V_38 . V_190 . V_395 ( V_37 , V_37 -> V_38 . V_190 . V_222 ) ;
V_88:
return V_84 ;
}
void F_319 ( struct V_36 * V_37 )
{
F_257 ( V_37 ) ;
F_3 ( F_258 ( V_37 -> V_38 . V_190 . V_222 ) ) ;
}
static void F_321 ( struct V_36 * V_37 ,
struct V_51 * V_52 , T_1 * V_10 ,
const void * V_410 )
{
if ( V_52 -> V_94 . V_44 != V_45 ) {
++ V_37 -> V_11 -> V_135 . V_411 ;
return;
}
++ V_37 -> V_11 -> V_135 . V_412 ;
V_37 -> V_38 . V_190 . V_350 ( V_37 , V_52 , V_10 , V_410 ) ;
}
static bool F_322 ( T_1 V_413 , T_1 V_410 )
{
if ( ! F_23 ( V_413 ) )
return false ;
if ( ! F_23 ( V_410 ) )
return true ;
if ( ( V_413 ^ V_410 ) & V_46 )
return true ;
V_413 ^= V_34 ;
V_410 ^= V_34 ;
return ( V_413 & ~ V_410 & V_414 ) != 0 ;
}
static void F_323 ( struct V_36 * V_37 , bool V_415 ,
bool V_416 , bool V_417 )
{
if ( V_415 )
return;
if ( V_416 )
F_107 ( V_37 -> V_11 ) ;
else if ( V_417 )
F_164 ( V_37 ) ;
}
static T_1 F_324 ( struct V_36 * V_37 , T_9 * V_344 ,
const T_8 * V_410 , int * V_418 )
{
T_1 V_419 ;
int V_84 ;
if ( F_162 ( V_37 ) && * V_418 == 4 ) {
* V_344 &= ~ ( T_9 ) 7 ;
* V_418 = 8 ;
V_84 = F_325 ( V_37 -> V_11 , * V_344 , & V_419 , 8 ) ;
if ( V_84 )
V_419 = 0 ;
V_410 = ( const T_8 * ) & V_419 ;
}
switch ( * V_418 ) {
case 4 :
V_419 = * ( const T_4 * ) V_410 ;
break;
case 8 :
V_419 = * ( const T_1 * ) V_410 ;
break;
default:
V_419 = 0 ;
break;
}
return V_419 ;
}
static bool F_326 ( struct V_51 * V_52 )
{
if ( V_52 -> V_94 . V_44 == V_45 )
return false ;
return ++ V_52 -> V_202 >= 3 ;
}
static bool F_327 ( struct V_51 * V_52 , T_9 V_344 ,
int V_418 )
{
unsigned V_420 , V_421 , V_422 ;
F_213 ( L_25 ,
V_344 , V_418 , V_52 -> V_94 . V_214 ) ;
V_420 = F_328 ( V_344 ) ;
V_421 = V_52 -> V_94 . V_189 ? 8 : 4 ;
if ( ! ( V_420 & ( V_421 - 1 ) ) && V_418 == 1 )
return false ;
V_422 = ( V_420 ^ ( V_420 + V_418 - 1 ) ) & ~ ( V_421 - 1 ) ;
V_422 |= V_418 < 4 ;
return V_422 ;
}
static T_1 * F_329 ( struct V_51 * V_52 , T_9 V_344 , int * V_423 )
{
unsigned V_424 , V_206 ;
T_1 * V_10 ;
int V_44 ;
V_424 = F_328 ( V_344 ) ;
V_44 = V_52 -> V_94 . V_44 ;
* V_423 = 1 ;
if ( ! V_52 -> V_94 . V_189 ) {
V_424 <<= 1 ;
if ( V_44 == V_211 ) {
V_424 &= ~ 7 ;
V_424 <<= 1 ;
* V_423 = 2 ;
}
V_206 = V_424 >> V_19 ;
V_424 &= ~ V_20 ;
if ( V_206 != V_52 -> V_94 . V_206 )
return NULL ;
}
V_10 = & V_52 -> V_131 [ V_424 / sizeof( * V_10 ) ] ;
return V_10 ;
}
void F_330 ( struct V_36 * V_37 , T_9 V_344 ,
const T_8 * V_410 , int V_418 )
{
T_2 V_15 = V_344 >> V_19 ;
union V_205 V_4 = { . V_214 = 0 } ;
struct V_51 * V_52 ;
F_166 ( V_187 ) ;
T_1 V_425 , V_419 , * V_10 ;
int V_426 ;
bool V_416 , V_417 , V_415 ;
if ( ! F_34 ( V_37 -> V_11 -> V_38 . V_109 ) )
return;
V_415 = V_416 = V_417 = false ;
F_213 ( L_26 , V_162 , V_344 , V_418 ) ;
V_419 = F_324 ( V_37 , & V_344 , V_410 , & V_418 ) ;
F_69 ( V_37 ) ;
F_210 ( & V_37 -> V_11 -> V_200 ) ;
++ V_37 -> V_11 -> V_135 . V_427 ;
F_168 ( V_37 , V_428 ) ;
V_4 . V_400 = V_4 . V_189 = V_4 . V_399 = 1 ;
F_172 (vcpu->kvm, sp, gfn) {
if ( F_327 ( V_52 , V_344 , V_418 ) ||
F_326 ( V_52 ) ) {
V_415 |= ! ! F_163 ( V_37 -> V_11 , V_52 ,
& V_187 ) ;
++ V_37 -> V_11 -> V_135 . V_429 ;
continue;
}
V_10 = F_329 ( V_52 , V_344 , & V_426 ) ;
if ( ! V_10 )
continue;
V_417 = true ;
while ( V_426 -- ) {
V_425 = * V_10 ;
F_197 ( V_37 -> V_11 , V_52 , V_10 ) ;
if ( V_419 &&
! ( ( V_52 -> V_94 . V_214 ^ V_37 -> V_38 . V_190 . V_208 . V_214 )
& V_4 . V_214 ) && F_99 ( V_37 ) )
F_321 ( V_37 , V_52 , V_10 , & V_419 ) ;
if ( F_322 ( V_425 , * V_10 ) )
V_416 = true ;
++ V_10 ;
}
}
F_323 ( V_37 , V_415 , V_416 , V_417 ) ;
F_167 ( V_37 -> V_11 , & V_187 ) ;
F_168 ( V_37 , V_430 ) ;
F_211 ( & V_37 -> V_11 -> V_200 ) ;
}
int F_331 ( struct V_36 * V_37 , T_7 V_175 )
{
T_9 V_344 ;
int V_84 ;
if ( V_37 -> V_38 . V_190 . V_209 )
return 0 ;
V_344 = F_332 ( V_37 , V_175 , NULL ) ;
V_84 = F_212 ( V_37 -> V_11 , V_344 >> V_19 ) ;
return V_84 ;
}
static void F_256 ( struct V_36 * V_37 )
{
F_166 ( V_187 ) ;
if ( F_18 ( F_333 ( V_37 -> V_11 ) >= V_431 ) )
return;
while ( F_333 ( V_37 -> V_11 ) < V_432 ) {
if ( ! F_207 ( V_37 -> V_11 , & V_187 ) )
break;
++ V_37 -> V_11 -> V_135 . V_433 ;
}
F_167 ( V_37 -> V_11 , & V_187 ) ;
}
static bool F_334 ( struct V_36 * V_37 , T_7 V_220 )
{
if ( V_37 -> V_38 . V_190 . V_209 || F_317 ( V_37 ) )
return F_272 ( V_37 , V_220 ) ;
return F_273 ( V_37 , V_220 ) ;
}
int F_335 ( struct V_36 * V_37 , T_7 V_434 , T_4 V_304 ,
void * V_435 , int V_436 )
{
int V_84 , V_437 = V_438 ;
enum V_439 V_440 ;
V_84 = V_37 -> V_38 . V_190 . V_347 ( V_37 , V_434 , V_304 , false ) ;
if ( V_84 < 0 )
goto V_88;
if ( ! V_84 ) {
V_84 = 1 ;
goto V_88;
}
if ( F_334 ( V_37 , V_434 ) )
V_437 = 0 ;
V_440 = F_336 ( V_37 , V_434 , V_437 , V_435 , V_436 ) ;
switch ( V_440 ) {
case V_441 :
return 1 ;
case V_442 :
++ V_37 -> V_135 . V_443 ;
case V_444 :
return 0 ;
default:
F_94 () ;
}
V_88:
return V_84 ;
}
void F_337 ( struct V_36 * V_37 , T_7 V_175 )
{
V_37 -> V_38 . V_190 . V_349 ( V_37 , V_175 ) ;
F_164 ( V_37 ) ;
++ V_37 -> V_135 . V_349 ;
}
void F_338 ( void )
{
V_266 = true ;
}
void F_339 ( void )
{
V_266 = false ;
}
static void F_340 ( struct V_36 * V_37 )
{
F_68 ( ( unsigned long ) V_37 -> V_38 . V_190 . V_225 ) ;
if ( V_37 -> V_38 . V_190 . V_322 != NULL )
F_68 ( ( unsigned long ) V_37 -> V_38 . V_190 . V_322 ) ;
}
static int F_341 ( struct V_36 * V_37 )
{
struct V_83 * V_83 ;
int V_105 ;
ASSERT ( V_37 ) ;
V_83 = F_342 ( V_80 | V_445 ) ;
if ( ! V_83 )
return - V_81 ;
V_37 -> V_38 . V_190 . V_225 = F_343 ( V_83 ) ;
for ( V_105 = 0 ; V_105 < 4 ; ++ V_105 )
V_37 -> V_38 . V_190 . V_225 [ V_105 ] = V_313 ;
return 0 ;
}
int F_344 ( struct V_36 * V_37 )
{
ASSERT ( V_37 ) ;
V_37 -> V_38 . V_393 = & V_37 -> V_38 . V_190 ;
V_37 -> V_38 . V_190 . V_222 = V_313 ;
V_37 -> V_38 . V_190 . V_329 = V_329 ;
V_37 -> V_38 . V_328 . V_329 = V_446 ;
return F_341 ( V_37 ) ;
}
void F_345 ( struct V_36 * V_37 )
{
ASSERT ( V_37 ) ;
ASSERT ( ! F_258 ( V_37 -> V_38 . V_190 . V_222 ) ) ;
F_316 ( V_37 ) ;
}
void F_346 ( struct V_11 * V_11 , int V_100 )
{
struct V_99 * V_150 ;
T_2 V_447 ;
int V_105 ;
V_150 = F_347 ( V_11 -> V_448 , V_100 ) ;
V_447 = V_150 -> V_102 + V_150 -> V_156 - 1 ;
F_210 ( & V_11 -> V_200 ) ;
for ( V_105 = V_45 ;
V_105 < V_45 + V_107 ; ++ V_105 ) {
unsigned long * V_130 ;
unsigned long V_449 , V_93 ;
V_130 = V_150 -> V_38 . V_129 [ V_105 - V_45 ] ;
V_449 = F_78 ( V_447 , V_150 -> V_102 , V_105 ) ;
for ( V_93 = 0 ; V_93 <= V_449 ; ++ V_93 , ++ V_130 ) {
if ( * V_130 )
F_109 ( V_11 , V_130 , false ) ;
if ( F_348 () || F_349 ( & V_11 -> V_200 ) ) {
F_107 ( V_11 ) ;
F_178 ( & V_11 -> V_200 ) ;
}
}
}
F_107 ( V_11 ) ;
F_211 ( & V_11 -> V_200 ) ;
}
static void F_350 ( struct V_11 * V_11 )
{
struct V_51 * V_52 , * V_450 ;
int V_451 = 0 ;
V_452:
F_351 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_68 ;
if ( ! F_182 ( V_11 , V_52 ) )
break;
if ( V_52 -> V_94 . V_232 )
continue;
if ( V_451 >= V_453 &&
F_178 ( & V_11 -> V_200 ) ) {
V_451 = 0 ;
goto V_452;
}
V_68 = F_163 ( V_11 , V_52 ,
& V_11 -> V_38 . V_454 ) ;
V_451 += V_68 ;
if ( V_68 )
goto V_452;
}
F_167 ( V_11 , & V_11 -> V_38 . V_454 ) ;
}
void F_352 ( struct V_11 * V_11 )
{
F_210 ( & V_11 -> V_200 ) ;
F_353 ( V_11 ) ;
V_11 -> V_38 . V_203 ++ ;
F_204 ( V_11 ) ;
F_350 ( V_11 ) ;
F_211 ( & V_11 -> V_200 ) ;
}
static bool F_354 ( struct V_11 * V_11 )
{
return F_14 ( ! F_355 ( & V_11 -> V_38 . V_454 ) ) ;
}
void F_356 ( struct V_11 * V_11 )
{
if ( F_14 ( F_5 ( V_11 ) >= V_5 ) ) {
F_357 ( V_455 L_27 ) ;
F_352 ( V_11 ) ;
}
}
static unsigned long
F_358 ( struct V_456 * V_457 , struct V_458 * V_459 )
{
struct V_11 * V_11 ;
int V_460 = V_459 -> V_460 ;
unsigned long V_461 = 0 ;
F_210 ( & V_462 ) ;
F_359 (kvm, &vm_list, vm_list) {
int V_101 ;
F_166 ( V_187 ) ;
if ( ! V_460 -- )
break;
if ( ! V_11 -> V_38 . V_164 &&
! F_354 ( V_11 ) )
continue;
V_101 = F_360 ( & V_11 -> V_463 ) ;
F_210 ( & V_11 -> V_200 ) ;
if ( F_354 ( V_11 ) ) {
F_167 ( V_11 ,
& V_11 -> V_38 . V_454 ) ;
goto V_464;
}
if ( F_207 ( V_11 , & V_187 ) )
V_461 ++ ;
F_167 ( V_11 , & V_187 ) ;
V_464:
F_211 ( & V_11 -> V_200 ) ;
F_361 ( & V_11 -> V_463 , V_101 ) ;
F_362 ( & V_11 -> V_465 , & V_465 ) ;
break;
}
F_211 ( & V_462 ) ;
return V_461 ;
}
static unsigned long
F_363 ( struct V_456 * V_457 , struct V_458 * V_459 )
{
return F_364 ( & V_165 ) ;
}
static void F_365 ( void )
{
if ( V_86 )
F_366 ( V_86 ) ;
if ( V_90 )
F_366 ( V_90 ) ;
}
int F_367 ( void )
{
V_86 = F_368 ( L_28 ,
sizeof( struct V_92 ) ,
0 , 0 , NULL ) ;
if ( ! V_86 )
goto V_466;
V_90 = F_368 ( L_29 ,
sizeof( struct V_51 ) ,
0 , 0 , NULL ) ;
if ( ! V_90 )
goto V_466;
if ( F_369 ( & V_165 , 0 ) )
goto V_466;
F_370 ( & V_467 ) ;
return 0 ;
V_466:
F_365 () ;
return - V_81 ;
}
unsigned int F_371 ( struct V_11 * V_11 )
{
unsigned int V_468 ;
unsigned int V_469 = 0 ;
struct F_6 * V_149 ;
struct V_99 * V_150 ;
V_149 = F_6 ( V_11 ) ;
F_120 (memslot, slots)
V_469 += V_150 -> V_156 ;
V_468 = V_469 * V_470 / 1000 ;
V_468 = F_121 ( V_468 ,
( unsigned int ) V_471 ) ;
return V_468 ;
}
int F_372 ( struct V_36 * V_37 , T_1 V_220 , T_1 V_122 [ 4 ] )
{
struct V_218 V_219 ;
T_1 V_10 ;
int V_472 = 0 ;
F_54 ( V_37 ) ;
F_251 (vcpu, addr, iterator, spte) {
V_122 [ V_219 . V_44 - 1 ] = V_10 ;
V_472 ++ ;
if ( ! F_23 ( V_10 ) )
break;
}
F_57 ( V_37 ) ;
return V_472 ;
}
void F_373 ( struct V_36 * V_37 )
{
ASSERT ( V_37 ) ;
F_319 ( V_37 ) ;
F_340 ( V_37 ) ;
F_70 ( V_37 ) ;
}
void F_374 ( void )
{
F_365 () ;
F_375 ( & V_165 ) ;
F_376 ( & V_467 ) ;
F_169 () ;
}
