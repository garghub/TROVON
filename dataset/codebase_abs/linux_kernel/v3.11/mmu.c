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
static int F_25 ( unsigned long V_41 )
{
return V_41 & V_44 ;
}
static int F_26 ( T_1 V_41 )
{
return F_23 ( V_41 ) ;
}
static int F_27 ( T_1 V_41 , int V_45 )
{
if ( V_45 == V_46 )
return 1 ;
if ( F_24 ( V_41 ) )
return 1 ;
return 0 ;
}
static T_3 F_28 ( T_1 V_41 )
{
return ( V_41 & V_47 ) >> V_19 ;
}
static T_2 F_29 ( T_4 V_48 )
{
int V_49 = 32 - V_50 - V_19 ;
return ( V_48 & V_51 ) << V_49 ;
}
static void F_30 ( T_1 * V_14 , T_1 V_10 )
{
* V_14 = V_10 ;
}
static void F_31 ( T_1 * V_14 , T_1 V_10 )
{
* V_14 = V_10 ;
}
static T_1 F_32 ( T_1 * V_14 , T_1 V_10 )
{
return F_33 ( V_14 , V_10 ) ;
}
static T_1 F_34 ( T_1 * V_14 )
{
return F_35 ( * V_14 ) ;
}
static bool F_36 ( T_1 V_10 )
{
return V_10 == 0ull ;
}
static void F_37 ( T_1 * V_14 , T_1 V_10 )
{
struct V_52 * V_53 = F_38 ( F_39 ( V_14 ) ) ;
if ( F_23 ( V_10 ) )
return;
F_40 () ;
V_53 -> V_54 ++ ;
}
static void F_30 ( T_1 * V_14 , T_1 V_10 )
{
union V_55 * V_56 , V_57 ;
V_56 = (union V_55 * ) V_14 ;
V_57 = (union V_55 ) V_10 ;
V_56 -> V_58 = V_57 . V_58 ;
F_40 () ;
V_56 -> V_59 = V_57 . V_59 ;
}
static void F_31 ( T_1 * V_14 , T_1 V_10 )
{
union V_55 * V_56 , V_57 ;
V_56 = (union V_55 * ) V_14 ;
V_57 = (union V_55 ) V_10 ;
V_56 -> V_59 = V_57 . V_59 ;
F_40 () ;
V_56 -> V_58 = V_57 . V_58 ;
F_37 ( V_14 , V_10 ) ;
}
static T_1 F_32 ( T_1 * V_14 , T_1 V_10 )
{
union V_55 * V_56 , V_57 , V_60 ;
V_56 = (union V_55 * ) V_14 ;
V_57 = (union V_55 ) V_10 ;
V_60 . V_59 = F_33 ( & V_56 -> V_59 , V_57 . V_59 ) ;
V_60 . V_58 = V_56 -> V_58 ;
V_56 -> V_58 = V_57 . V_58 ;
F_37 ( V_14 , V_10 ) ;
return V_60 . V_10 ;
}
static T_1 F_34 ( T_1 * V_14 )
{
struct V_52 * V_53 = F_38 ( F_39 ( V_14 ) ) ;
union V_55 V_10 , * V_60 = (union V_55 * ) V_14 ;
int V_61 ;
V_62:
V_61 = V_53 -> V_54 ;
F_41 () ;
V_10 . V_59 = V_60 -> V_59 ;
F_41 () ;
V_10 . V_58 = V_60 -> V_58 ;
F_41 () ;
if ( F_14 ( V_10 . V_59 != V_60 -> V_59 ||
V_61 != V_53 -> V_54 ) )
goto V_62;
return V_10 . V_10 ;
}
static bool F_36 ( T_1 V_10 )
{
union V_55 V_57 = (union V_55 ) V_10 ;
T_4 V_63 = V_2 >> 32 ;
if ( V_10 == 0ull )
return true ;
if ( V_57 . V_59 == 0ull &&
( V_57 . V_58 & V_63 ) == V_63 )
return true ;
return false ;
}
static bool F_42 ( T_1 V_10 )
{
return ( V_10 & ( V_64 | V_65 ) ) ==
( V_64 | V_65 ) ;
}
static bool F_43 ( T_1 V_10 )
{
if ( F_42 ( V_10 ) )
return true ;
if ( ! V_32 )
return false ;
if ( ! F_23 ( V_10 ) )
return false ;
if ( ( V_10 & V_32 ) &&
( ! F_44 ( V_10 ) || ( V_10 & V_33 ) ) )
return false ;
return true ;
}
static bool F_45 ( T_1 V_66 , T_1 V_67 , T_1 V_68 )
{
return ( V_66 & V_68 ) && ! ( V_67 & V_68 ) ;
}
static void F_9 ( T_1 * V_14 , T_1 V_67 )
{
F_3 ( F_23 ( * V_14 ) ) ;
F_30 ( V_14 , V_67 ) ;
}
static bool F_46 ( T_1 * V_14 , T_1 V_67 )
{
T_1 V_66 = * V_14 ;
bool V_69 = false ;
F_3 ( ! F_26 ( V_67 ) ) ;
if ( ! F_23 ( V_66 ) ) {
F_9 ( V_14 , V_67 ) ;
return V_69 ;
}
if ( ! F_43 ( V_66 ) )
F_31 ( V_14 , V_67 ) ;
else
V_66 = F_32 ( V_14 , V_67 ) ;
if ( F_44 ( V_66 ) && ! F_44 ( V_67 ) )
V_69 = true ;
if ( ! V_32 )
return V_69 ;
if ( F_45 ( V_66 , V_67 , V_32 ) )
F_47 ( F_28 ( V_66 ) ) ;
if ( F_45 ( V_66 , V_67 , V_33 ) )
F_48 ( F_28 ( V_66 ) ) ;
return V_69 ;
}
static int F_49 ( T_1 * V_14 )
{
T_3 V_21 ;
T_1 V_66 = * V_14 ;
if ( ! F_43 ( V_66 ) )
F_31 ( V_14 , 0ull ) ;
else
V_66 = F_32 ( V_14 , 0ull ) ;
if ( ! F_26 ( V_66 ) )
return 0 ;
V_21 = F_28 ( V_66 ) ;
F_3 ( ! F_50 ( V_21 ) && ! F_51 ( F_52 ( V_21 ) ) ) ;
if ( ! V_32 || V_66 & V_32 )
F_47 ( V_21 ) ;
if ( ! V_33 || ( V_66 & V_33 ) )
F_48 ( V_21 ) ;
return 1 ;
}
static void F_53 ( T_1 * V_14 )
{
F_31 ( V_14 , 0ull ) ;
}
static T_1 F_54 ( T_1 * V_14 )
{
return F_34 ( V_14 ) ;
}
static void F_55 ( struct V_36 * V_37 )
{
F_56 () ;
V_37 -> V_70 = V_71 ;
F_57 () ;
}
static void F_58 ( struct V_36 * V_37 )
{
F_57 () ;
V_37 -> V_70 = V_72 ;
F_59 () ;
}
static int F_60 ( struct V_73 * V_74 ,
struct V_75 * V_76 , int V_77 )
{
void * V_78 ;
if ( V_74 -> V_79 >= V_77 )
return 0 ;
while ( V_74 -> V_79 < F_61 ( V_74 -> V_80 ) ) {
V_78 = F_62 ( V_76 , V_81 ) ;
if ( ! V_78 )
return - V_82 ;
V_74 -> V_80 [ V_74 -> V_79 ++ ] = V_78 ;
}
return 0 ;
}
static int F_63 ( struct V_73 * V_74 )
{
return V_74 -> V_79 ;
}
static void F_64 ( struct V_73 * V_83 ,
struct V_75 * V_74 )
{
while ( V_83 -> V_79 )
F_65 ( V_74 , V_83 -> V_80 [ -- V_83 -> V_79 ] ) ;
}
static int F_66 ( struct V_73 * V_74 ,
int V_77 )
{
void * V_84 ;
if ( V_74 -> V_79 >= V_77 )
return 0 ;
while ( V_74 -> V_79 < F_61 ( V_74 -> V_80 ) ) {
V_84 = ( void * ) F_67 ( V_81 ) ;
if ( ! V_84 )
return - V_82 ;
V_74 -> V_80 [ V_74 -> V_79 ++ ] = V_84 ;
}
return 0 ;
}
static void F_68 ( struct V_73 * V_83 )
{
while ( V_83 -> V_79 )
F_69 ( ( unsigned long ) V_83 -> V_80 [ -- V_83 -> V_79 ] ) ;
}
static int F_70 ( struct V_36 * V_37 )
{
int V_85 ;
V_85 = F_60 ( & V_37 -> V_38 . V_86 ,
V_87 , 8 + V_88 ) ;
if ( V_85 )
goto V_89;
V_85 = F_66 ( & V_37 -> V_38 . V_90 , 8 ) ;
if ( V_85 )
goto V_89;
V_85 = F_60 ( & V_37 -> V_38 . V_91 ,
V_91 , 4 ) ;
V_89:
return V_85 ;
}
static void F_71 ( struct V_36 * V_37 )
{
F_64 ( & V_37 -> V_38 . V_86 ,
V_87 ) ;
F_68 ( & V_37 -> V_38 . V_90 ) ;
F_64 ( & V_37 -> V_38 . V_91 ,
V_91 ) ;
}
static void * F_72 ( struct V_73 * V_83 )
{
void * V_92 ;
F_73 ( ! V_83 -> V_79 ) ;
V_92 = V_83 -> V_80 [ -- V_83 -> V_79 ] ;
return V_92 ;
}
static struct V_93 * F_74 ( struct V_36 * V_37 )
{
return F_72 ( & V_37 -> V_38 . V_86 ) ;
}
static void F_75 ( struct V_93 * V_93 )
{
F_65 ( V_87 , V_93 ) ;
}
static T_2 F_76 ( struct V_52 * V_53 , int V_94 )
{
if ( ! V_53 -> V_95 . V_96 )
return V_53 -> V_97 [ V_94 ] ;
return V_53 -> V_15 + ( V_94 << ( ( V_53 -> V_95 . V_45 - 1 ) * V_98 ) ) ;
}
static void F_77 ( struct V_52 * V_53 , int V_94 , T_2 V_15 )
{
if ( V_53 -> V_95 . V_96 )
F_73 ( V_15 != F_76 ( V_53 , V_94 ) ) ;
else
V_53 -> V_97 [ V_94 ] = V_15 ;
}
static struct V_99 * F_78 ( T_2 V_15 ,
struct V_100 * V_101 ,
int V_45 )
{
unsigned long V_102 ;
V_102 = F_79 ( V_15 , V_101 -> V_103 , V_45 ) ;
return & V_101 -> V_38 . V_104 [ V_45 - 2 ] [ V_102 ] ;
}
static void F_80 ( struct V_11 * V_11 , T_2 V_15 )
{
struct V_100 * V_101 ;
struct V_99 * V_105 ;
int V_106 ;
V_101 = F_81 ( V_11 , V_15 ) ;
for ( V_106 = V_107 ;
V_106 < V_46 + V_108 ; ++ V_106 ) {
V_105 = F_78 ( V_15 , V_101 , V_106 ) ;
V_105 -> V_109 += 1 ;
}
V_11 -> V_38 . V_110 ++ ;
}
static void F_82 ( struct V_11 * V_11 , T_2 V_15 )
{
struct V_100 * V_101 ;
struct V_99 * V_105 ;
int V_106 ;
V_101 = F_81 ( V_11 , V_15 ) ;
for ( V_106 = V_107 ;
V_106 < V_46 + V_108 ; ++ V_106 ) {
V_105 = F_78 ( V_15 , V_101 , V_106 ) ;
V_105 -> V_109 -= 1 ;
F_3 ( V_105 -> V_109 < 0 ) ;
}
V_11 -> V_38 . V_110 -- ;
}
static int F_83 ( struct V_11 * V_11 ,
T_2 V_15 ,
int V_45 )
{
struct V_100 * V_101 ;
struct V_99 * V_105 ;
V_101 = F_81 ( V_11 , V_15 ) ;
if ( V_101 ) {
V_105 = F_78 ( V_15 , V_101 , V_45 ) ;
return V_105 -> V_109 ;
}
return 1 ;
}
static int F_84 ( struct V_11 * V_11 , T_2 V_15 )
{
unsigned long V_111 ;
int V_106 , V_69 = 0 ;
V_111 = F_85 ( V_11 , V_15 ) ;
for ( V_106 = V_46 ;
V_106 < ( V_46 + V_108 ) ; ++ V_106 ) {
if ( V_111 >= F_86 ( V_106 ) )
V_69 = V_106 ;
else
break;
}
return V_69 ;
}
static struct V_100 *
F_87 ( struct V_36 * V_37 , T_2 V_15 ,
bool V_112 )
{
struct V_100 * V_101 ;
V_101 = F_81 ( V_37 -> V_11 , V_15 ) ;
if ( ! V_101 || V_101 -> V_113 & V_114 ||
( V_112 && V_101 -> V_115 ) )
V_101 = NULL ;
return V_101 ;
}
static bool F_88 ( struct V_36 * V_37 , T_2 V_116 )
{
return ! F_87 ( V_37 , V_116 , true ) ;
}
static int F_89 ( struct V_36 * V_37 , T_2 V_116 )
{
int V_117 , V_45 , V_118 ;
V_117 = F_84 ( V_37 -> V_11 , V_116 ) ;
if ( V_117 == V_46 )
return V_117 ;
V_118 = V_77 ( V_119 -> V_120 () , V_117 ) ;
for ( V_45 = V_107 ; V_45 <= V_118 ; ++ V_45 )
if ( F_83 ( V_37 -> V_11 , V_116 , V_45 ) )
break;
return V_45 - 1 ;
}
static int F_90 ( struct V_36 * V_37 , T_1 * V_10 ,
unsigned long * V_121 )
{
struct V_93 * V_122 ;
int V_106 , V_61 = 0 ;
if ( ! * V_121 ) {
F_91 ( L_1 , V_10 , * V_10 ) ;
* V_121 = ( unsigned long ) V_10 ;
} else if ( ! ( * V_121 & 1 ) ) {
F_91 ( L_2 , V_10 , * V_10 ) ;
V_122 = F_74 ( V_37 ) ;
V_122 -> V_123 [ 0 ] = ( T_1 * ) * V_121 ;
V_122 -> V_123 [ 1 ] = V_10 ;
* V_121 = ( unsigned long ) V_122 | 1 ;
++ V_61 ;
} else {
F_91 ( L_3 , V_10 , * V_10 ) ;
V_122 = (struct V_93 * ) ( * V_121 & ~ 1ul ) ;
while ( V_122 -> V_123 [ V_124 - 1 ] && V_122 -> V_125 ) {
V_122 = V_122 -> V_125 ;
V_61 += V_124 ;
}
if ( V_122 -> V_123 [ V_124 - 1 ] ) {
V_122 -> V_125 = F_74 ( V_37 ) ;
V_122 = V_122 -> V_125 ;
}
for ( V_106 = 0 ; V_122 -> V_123 [ V_106 ] ; ++ V_106 )
++ V_61 ;
V_122 -> V_123 [ V_106 ] = V_10 ;
}
return V_61 ;
}
static void
F_92 ( unsigned long * V_121 , struct V_93 * V_122 ,
int V_106 , struct V_93 * V_126 )
{
int V_127 ;
for ( V_127 = V_124 - 1 ; ! V_122 -> V_123 [ V_127 ] && V_127 > V_106 ; -- V_127 )
;
V_122 -> V_123 [ V_106 ] = V_122 -> V_123 [ V_127 ] ;
V_122 -> V_123 [ V_127 ] = NULL ;
if ( V_127 != 0 )
return;
if ( ! V_126 && ! V_122 -> V_125 )
* V_121 = ( unsigned long ) V_122 -> V_123 [ 0 ] ;
else
if ( V_126 )
V_126 -> V_125 = V_122 -> V_125 ;
else
* V_121 = ( unsigned long ) V_122 -> V_125 | 1 ;
F_75 ( V_122 ) ;
}
static void F_93 ( T_1 * V_10 , unsigned long * V_121 )
{
struct V_93 * V_122 ;
struct V_93 * V_126 ;
int V_106 ;
if ( ! * V_121 ) {
F_94 ( V_128 L_4 , V_10 ) ;
F_95 () ;
} else if ( ! ( * V_121 & 1 ) ) {
F_91 ( L_5 , V_10 ) ;
if ( ( T_1 * ) * V_121 != V_10 ) {
F_94 ( V_128 L_6 , V_10 ) ;
F_95 () ;
}
* V_121 = 0 ;
} else {
F_91 ( L_7 , V_10 ) ;
V_122 = (struct V_93 * ) ( * V_121 & ~ 1ul ) ;
V_126 = NULL ;
while ( V_122 ) {
for ( V_106 = 0 ; V_106 < V_124 && V_122 -> V_123 [ V_106 ] ; ++ V_106 )
if ( V_122 -> V_123 [ V_106 ] == V_10 ) {
F_92 ( V_121 ,
V_122 , V_106 ,
V_126 ) ;
return;
}
V_126 = V_122 ;
V_122 = V_122 -> V_125 ;
}
F_96 ( L_8 , V_10 ) ;
F_95 () ;
}
}
static void F_97 ( unsigned long * V_121 , T_5 V_129 )
{
struct V_93 * V_122 ;
int V_106 ;
if ( ! * V_121 )
return;
if ( ! ( * V_121 & 1 ) )
return V_129 ( ( T_1 * ) * V_121 ) ;
V_122 = (struct V_93 * ) ( * V_121 & ~ 1ul ) ;
while ( V_122 ) {
for ( V_106 = 0 ; V_106 < V_124 && V_122 -> V_123 [ V_106 ] ; ++ V_106 )
V_129 ( V_122 -> V_123 [ V_106 ] ) ;
V_122 = V_122 -> V_125 ;
}
}
static unsigned long * F_98 ( T_2 V_15 , int V_45 ,
struct V_100 * V_101 )
{
unsigned long V_102 ;
V_102 = F_79 ( V_15 , V_101 -> V_103 , V_45 ) ;
return & V_101 -> V_38 . V_130 [ V_45 - V_46 ] [ V_102 ] ;
}
static unsigned long * F_99 ( struct V_11 * V_11 , T_2 V_15 , int V_45 )
{
struct V_100 * V_101 ;
V_101 = F_81 ( V_11 , V_15 ) ;
return F_98 ( V_15 , V_45 , V_101 ) ;
}
static bool F_100 ( struct V_36 * V_37 )
{
struct V_73 * V_74 ;
V_74 = & V_37 -> V_38 . V_86 ;
return F_63 ( V_74 ) ;
}
static int F_101 ( struct V_36 * V_37 , T_1 * V_10 , T_2 V_15 )
{
struct V_52 * V_53 ;
unsigned long * V_131 ;
V_53 = F_38 ( F_39 ( V_10 ) ) ;
F_77 ( V_53 , V_10 - V_53 -> V_132 , V_15 ) ;
V_131 = F_99 ( V_37 -> V_11 , V_15 , V_53 -> V_95 . V_45 ) ;
return F_90 ( V_37 , V_10 , V_131 ) ;
}
static void F_102 ( struct V_11 * V_11 , T_1 * V_10 )
{
struct V_52 * V_53 ;
T_2 V_15 ;
unsigned long * V_131 ;
V_53 = F_38 ( F_39 ( V_10 ) ) ;
V_15 = F_76 ( V_53 , V_10 - V_53 -> V_132 ) ;
V_131 = F_99 ( V_11 , V_15 , V_53 -> V_95 . V_45 ) ;
F_93 ( V_10 , V_131 ) ;
}
static T_1 * F_103 ( unsigned long V_130 , struct V_133 * V_134 )
{
if ( ! V_130 )
return NULL ;
if ( ! ( V_130 & 1 ) ) {
V_134 -> V_122 = NULL ;
return ( T_1 * ) V_130 ;
}
V_134 -> V_122 = (struct V_93 * ) ( V_130 & ~ 1ul ) ;
V_134 -> V_135 = 0 ;
return V_134 -> V_122 -> V_123 [ V_134 -> V_135 ] ;
}
static T_1 * F_104 ( struct V_133 * V_134 )
{
if ( V_134 -> V_122 ) {
if ( V_134 -> V_135 < V_124 - 1 ) {
T_1 * V_14 ;
++ V_134 -> V_135 ;
V_14 = V_134 -> V_122 -> V_123 [ V_134 -> V_135 ] ;
if ( V_14 )
return V_14 ;
}
V_134 -> V_122 = V_134 -> V_122 -> V_125 ;
if ( V_134 -> V_122 ) {
V_134 -> V_135 = 0 ;
return V_134 -> V_122 -> V_123 [ V_134 -> V_135 ] ;
}
}
return NULL ;
}
static void F_105 ( struct V_11 * V_11 , T_1 * V_14 )
{
if ( F_49 ( V_14 ) )
F_102 ( V_11 , V_14 ) ;
}
static bool F_106 ( struct V_11 * V_11 , T_1 * V_14 )
{
if ( F_24 ( * V_14 ) ) {
F_3 ( F_38 ( F_39 ( V_14 ) ) -> V_95 . V_45 ==
V_46 ) ;
F_105 ( V_11 , V_14 ) ;
-- V_11 -> V_136 . V_137 ;
return true ;
}
return false ;
}
static void F_107 ( struct V_36 * V_37 , T_1 * V_14 )
{
if ( F_106 ( V_37 -> V_11 , V_14 ) )
F_108 ( V_37 -> V_11 ) ;
}
static bool
F_109 ( struct V_11 * V_11 , T_1 * V_14 , bool * V_138 , bool V_139 )
{
T_1 V_10 = * V_14 ;
if ( ! F_44 ( V_10 ) &&
! ( V_139 && F_42 ( V_10 ) ) )
return false ;
F_91 ( L_9 , V_14 , * V_14 ) ;
if ( F_106 ( V_11 , V_14 ) ) {
* V_138 |= true ;
return true ;
}
if ( V_139 )
V_10 &= ~ V_65 ;
V_10 = V_10 & ~ V_140 ;
* V_138 |= F_46 ( V_14 , V_10 ) ;
return false ;
}
static bool F_110 ( struct V_11 * V_11 , unsigned long * V_131 ,
bool V_139 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
bool V_138 = false ;
for ( V_14 = F_103 ( * V_131 , & V_134 ) ; V_14 ; ) {
F_73 ( ! ( * V_14 & V_42 ) ) ;
if ( F_109 ( V_11 , V_14 , & V_138 , V_139 ) ) {
V_14 = F_103 ( * V_131 , & V_134 ) ;
continue;
}
V_14 = F_104 ( & V_134 ) ;
}
return V_138 ;
}
void F_111 ( struct V_11 * V_11 ,
struct V_100 * V_101 ,
T_2 V_141 , unsigned long V_4 )
{
unsigned long * V_131 ;
while ( V_4 ) {
V_131 = F_98 ( V_101 -> V_103 + V_141 + F_112 ( V_4 ) ,
V_46 , V_101 ) ;
F_110 ( V_11 , V_131 , false ) ;
V_4 &= V_4 - 1 ;
}
}
static bool F_113 ( struct V_11 * V_11 , T_1 V_15 )
{
struct V_100 * V_101 ;
unsigned long * V_131 ;
int V_106 ;
bool V_142 = false ;
V_101 = F_81 ( V_11 , V_15 ) ;
for ( V_106 = V_46 ;
V_106 < V_46 + V_108 ; ++ V_106 ) {
V_131 = F_98 ( V_15 , V_106 , V_101 ) ;
V_142 |= F_110 ( V_11 , V_131 , true ) ;
}
return V_142 ;
}
static int F_114 ( struct V_11 * V_11 , unsigned long * V_131 ,
struct V_100 * V_101 , unsigned long V_143 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
int V_144 = 0 ;
while ( ( V_14 = F_103 ( * V_131 , & V_134 ) ) ) {
F_73 ( ! ( * V_14 & V_42 ) ) ;
F_91 ( L_10 , V_14 , * V_14 ) ;
F_105 ( V_11 , V_14 ) ;
V_144 = 1 ;
}
return V_144 ;
}
static int F_115 ( struct V_11 * V_11 , unsigned long * V_131 ,
struct V_100 * V_101 , unsigned long V_143 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
int V_145 = 0 ;
T_1 V_67 ;
T_6 * V_146 = ( T_6 * ) V_143 ;
T_3 V_147 ;
F_3 ( F_116 ( * V_146 ) ) ;
V_147 = F_117 ( * V_146 ) ;
for ( V_14 = F_103 ( * V_131 , & V_134 ) ; V_14 ; ) {
F_73 ( ! F_23 ( * V_14 ) ) ;
F_91 ( L_11 , V_14 , * V_14 ) ;
V_145 = 1 ;
if ( F_118 ( * V_146 ) ) {
F_105 ( V_11 , V_14 ) ;
V_14 = F_103 ( * V_131 , & V_134 ) ;
} else {
V_67 = * V_14 & ~ V_47 ;
V_67 |= ( T_1 ) V_147 << V_19 ;
V_67 &= ~ V_140 ;
V_67 &= ~ V_64 ;
V_67 &= ~ V_32 ;
F_49 ( V_14 ) ;
F_9 ( V_14 , V_67 ) ;
V_14 = F_104 ( & V_134 ) ;
}
}
if ( V_145 )
F_108 ( V_11 ) ;
return 0 ;
}
static int F_119 ( struct V_11 * V_11 ,
unsigned long V_148 ,
unsigned long V_149 ,
unsigned long V_143 ,
int (* F_120)( struct V_11 * V_11 ,
unsigned long * V_131 ,
struct V_100 * V_101 ,
unsigned long V_143 ) )
{
int V_127 ;
int V_69 = 0 ;
struct F_6 * V_150 ;
struct V_100 * V_151 ;
V_150 = F_6 ( V_11 ) ;
F_121 (memslot, slots) {
unsigned long V_152 , V_153 ;
T_2 V_154 , V_155 ;
V_152 = F_122 ( V_148 , V_151 -> V_156 ) ;
V_153 = V_77 ( V_149 , V_151 -> V_156 +
( V_151 -> V_157 << V_19 ) ) ;
if ( V_152 >= V_153 )
continue;
V_154 = F_123 ( V_152 , V_151 ) ;
V_155 = F_123 ( V_153 + V_158 - 1 , V_151 ) ;
for ( V_127 = V_46 ;
V_127 < V_46 + V_108 ; ++ V_127 ) {
unsigned long V_102 , V_159 ;
unsigned long * V_131 ;
V_102 = F_79 ( V_154 , V_151 -> V_103 , V_127 ) ;
V_159 = F_79 ( V_155 - 1 , V_151 -> V_103 , V_127 ) ;
V_131 = F_98 ( V_154 , V_127 , V_151 ) ;
for (; V_102 <= V_159 ; ++ V_102 )
V_69 |= F_120 ( V_11 , V_131 ++ , V_151 , V_143 ) ;
}
}
return V_69 ;
}
static int F_124 ( struct V_11 * V_11 , unsigned long V_160 ,
unsigned long V_143 ,
int (* F_120)( struct V_11 * V_11 , unsigned long * V_131 ,
struct V_100 * V_101 ,
unsigned long V_143 ) )
{
return F_119 ( V_11 , V_160 , V_160 + 1 , V_143 , F_120 ) ;
}
int F_125 ( struct V_11 * V_11 , unsigned long V_160 )
{
return F_124 ( V_11 , V_160 , 0 , F_114 ) ;
}
int F_126 ( struct V_11 * V_11 , unsigned long V_148 , unsigned long V_149 )
{
return F_119 ( V_11 , V_148 , V_149 , 0 , F_114 ) ;
}
void F_127 ( struct V_11 * V_11 , unsigned long V_160 , T_6 V_41 )
{
F_124 ( V_11 , V_160 , ( unsigned long ) & V_41 , F_115 ) ;
}
static int F_128 ( struct V_11 * V_11 , unsigned long * V_131 ,
struct V_100 * V_101 , unsigned long V_143 )
{
T_1 * V_14 ;
struct V_133 V_161 ( V_134 ) ;
int V_162 = 0 ;
if ( ! V_32 ) {
V_162 = F_114 ( V_11 , V_131 , V_101 , V_143 ) ;
goto V_89;
}
for ( V_14 = F_103 ( * V_131 , & V_134 ) ; V_14 ;
V_14 = F_104 ( & V_134 ) ) {
F_73 ( ! F_23 ( * V_14 ) ) ;
if ( * V_14 & V_32 ) {
V_162 = 1 ;
F_129 ( ( F_130 ( V_32 ) - 1 ) ,
( unsigned long * ) V_14 ) ;
}
}
V_89:
F_131 ( V_143 , V_101 , V_162 ) ;
return V_162 ;
}
static int F_132 ( struct V_11 * V_11 , unsigned long * V_131 ,
struct V_100 * V_101 , unsigned long V_143 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
int V_162 = 0 ;
if ( ! V_32 )
goto V_89;
for ( V_14 = F_103 ( * V_131 , & V_134 ) ; V_14 ;
V_14 = F_104 ( & V_134 ) ) {
F_73 ( ! F_23 ( * V_14 ) ) ;
if ( * V_14 & V_32 ) {
V_162 = 1 ;
break;
}
}
V_89:
return V_162 ;
}
static void F_133 ( struct V_36 * V_37 , T_1 * V_10 , T_2 V_15 )
{
unsigned long * V_131 ;
struct V_52 * V_53 ;
V_53 = F_38 ( F_39 ( V_10 ) ) ;
V_131 = F_99 ( V_37 -> V_11 , V_15 , V_53 -> V_95 . V_45 ) ;
F_114 ( V_37 -> V_11 , V_131 , NULL , 0 ) ;
F_108 ( V_37 -> V_11 ) ;
}
int F_134 ( struct V_11 * V_11 , unsigned long V_160 )
{
return F_124 ( V_11 , V_160 , V_160 , F_128 ) ;
}
int F_135 ( struct V_11 * V_11 , unsigned long V_160 )
{
return F_124 ( V_11 , V_160 , 0 , F_132 ) ;
}
static int F_136 ( T_1 * V_132 )
{
T_1 * V_135 ;
T_1 * V_149 ;
for ( V_135 = V_132 , V_149 = V_135 + V_158 / sizeof( T_1 ) ; V_135 != V_149 ; V_135 ++ )
if ( F_23 ( * V_135 ) ) {
F_94 ( V_128 L_12 , V_163 ,
V_135 , * V_135 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_137 ( struct V_11 * V_11 , int V_164 )
{
V_11 -> V_38 . V_165 += V_164 ;
F_138 ( & V_166 , V_164 ) ;
}
static void F_139 ( struct V_52 * V_53 )
{
ASSERT ( F_136 ( V_53 -> V_132 ) ) ;
F_140 ( & V_53 -> V_167 ) ;
F_141 ( & V_53 -> V_168 ) ;
F_69 ( ( unsigned long ) V_53 -> V_132 ) ;
if ( ! V_53 -> V_95 . V_96 )
F_69 ( ( unsigned long ) V_53 -> V_97 ) ;
F_65 ( V_91 , V_53 ) ;
}
static unsigned F_142 ( T_2 V_15 )
{
return V_15 & ( ( 1 << V_169 ) - 1 ) ;
}
static void F_143 ( struct V_36 * V_37 ,
struct V_52 * V_53 , T_1 * V_170 )
{
if ( ! V_170 )
return;
F_90 ( V_37 , V_170 , & V_53 -> V_171 ) ;
}
static void F_144 ( struct V_52 * V_53 ,
T_1 * V_170 )
{
F_93 ( V_170 , & V_53 -> V_171 ) ;
}
static void F_145 ( struct V_52 * V_53 ,
T_1 * V_170 )
{
F_144 ( V_53 , V_170 ) ;
F_53 ( V_170 ) ;
}
static struct V_52 * F_146 ( struct V_36 * V_37 ,
T_1 * V_170 , int V_96 )
{
struct V_52 * V_53 ;
V_53 = F_72 ( & V_37 -> V_38 . V_91 ) ;
V_53 -> V_132 = F_72 ( & V_37 -> V_38 . V_90 ) ;
if ( ! V_96 )
V_53 -> V_97 = F_72 ( & V_37 -> V_38 . V_90 ) ;
F_147 ( F_148 ( V_53 -> V_132 ) , ( unsigned long ) V_53 ) ;
F_149 ( & V_53 -> V_168 , & V_37 -> V_11 -> V_38 . V_172 ) ;
V_53 -> V_171 = 0 ;
F_143 ( V_37 , V_53 , V_170 ) ;
F_137 ( V_37 -> V_11 , + 1 ) ;
return V_53 ;
}
static void F_150 ( struct V_52 * V_53 )
{
F_97 ( & V_53 -> V_171 , V_173 ) ;
}
static void V_173 ( T_1 * V_10 )
{
struct V_52 * V_53 ;
unsigned int V_94 ;
V_53 = F_38 ( F_39 ( V_10 ) ) ;
V_94 = V_10 - V_53 -> V_132 ;
if ( F_151 ( V_94 , V_53 -> V_174 ) )
return;
if ( V_53 -> V_175 ++ )
return;
F_150 ( V_53 ) ;
}
static int F_152 ( struct V_36 * V_37 ,
struct V_52 * V_53 )
{
return 1 ;
}
static void F_153 ( struct V_36 * V_37 , T_7 V_176 )
{
}
static void F_154 ( struct V_36 * V_37 ,
struct V_52 * V_53 , T_1 * V_10 ,
const void * V_41 )
{
F_3 ( 1 ) ;
}
static int F_155 ( struct V_177 * V_178 , struct V_52 * V_53 ,
int V_102 )
{
int V_106 ;
if ( V_53 -> V_179 )
for ( V_106 = 0 ; V_106 < V_178 -> V_164 ; V_106 ++ )
if ( V_178 -> V_84 [ V_106 ] . V_53 == V_53 )
return 0 ;
V_178 -> V_84 [ V_178 -> V_164 ] . V_53 = V_53 ;
V_178 -> V_84 [ V_178 -> V_164 ] . V_102 = V_102 ;
V_178 -> V_164 ++ ;
return ( V_178 -> V_164 == V_180 ) ;
}
static int F_156 ( struct V_52 * V_53 ,
struct V_177 * V_178 )
{
int V_106 , V_69 , V_181 = 0 ;
F_157 (i, sp->unsync_child_bitmap, 512 ) {
struct V_52 * V_182 ;
T_1 V_183 = V_53 -> V_132 [ V_106 ] ;
if ( ! F_23 ( V_183 ) || F_24 ( V_183 ) )
goto V_184;
V_182 = F_38 ( V_183 & V_47 ) ;
if ( V_182 -> V_175 ) {
if ( F_155 ( V_178 , V_182 , V_106 ) )
return - V_185 ;
V_69 = F_156 ( V_182 , V_178 ) ;
if ( ! V_69 )
goto V_184;
else if ( V_69 > 0 )
V_181 += V_69 ;
else
return V_69 ;
} else if ( V_182 -> V_179 ) {
V_181 ++ ;
if ( F_155 ( V_178 , V_182 , V_106 ) )
return - V_185 ;
} else
goto V_184;
continue;
V_184:
F_158 ( V_106 , V_53 -> V_174 ) ;
V_53 -> V_175 -- ;
F_3 ( ( int ) V_53 -> V_175 < 0 ) ;
}
return V_181 ;
}
static int F_159 ( struct V_52 * V_53 ,
struct V_177 * V_178 )
{
if ( ! V_53 -> V_175 )
return 0 ;
F_155 ( V_178 , V_53 , 0 ) ;
return F_156 ( V_53 , V_178 ) ;
}
static void F_160 ( struct V_11 * V_11 , struct V_52 * V_53 )
{
F_3 ( ! V_53 -> V_179 ) ;
F_161 ( V_53 ) ;
V_53 -> V_179 = 0 ;
-- V_11 -> V_136 . V_186 ;
}
static int F_162 ( struct V_36 * V_37 , struct V_52 * V_53 ,
struct V_187 * V_188 , bool V_189 )
{
if ( V_53 -> V_95 . V_190 != ! ! F_163 ( V_37 ) ) {
F_164 ( V_37 -> V_11 , V_53 , V_188 ) ;
return 1 ;
}
if ( V_189 )
F_160 ( V_37 -> V_11 , V_53 ) ;
if ( V_37 -> V_38 . V_191 . V_192 ( V_37 , V_53 ) ) {
F_164 ( V_37 -> V_11 , V_53 , V_188 ) ;
return 1 ;
}
F_165 ( V_37 ) ;
return 0 ;
}
static int F_166 ( struct V_36 * V_37 ,
struct V_52 * V_53 )
{
F_167 ( V_188 ) ;
int V_69 ;
V_69 = F_162 ( V_37 , V_53 , & V_188 , false ) ;
if ( V_69 )
F_168 ( V_37 -> V_11 , & V_188 ) ;
return V_69 ;
}
static void F_169 ( struct V_36 * V_37 , int V_193 ) { }
static void F_170 ( void ) { }
static int F_171 ( struct V_36 * V_37 , struct V_52 * V_53 ,
struct V_187 * V_188 )
{
return F_162 ( V_37 , V_53 , V_188 , true ) ;
}
static void F_172 ( struct V_36 * V_37 , T_2 V_15 )
{
struct V_52 * V_24 ;
F_167 ( V_188 ) ;
bool V_138 = false ;
F_173 (vcpu->kvm, s, gfn) {
if ( ! V_24 -> V_179 )
continue;
F_3 ( V_24 -> V_95 . V_45 != V_46 ) ;
F_160 ( V_37 -> V_11 , V_24 ) ;
if ( ( V_24 -> V_95 . V_190 != ! ! F_163 ( V_37 ) ) ||
( V_37 -> V_38 . V_191 . V_192 ( V_37 , V_24 ) ) ) {
F_164 ( V_37 -> V_11 , V_24 , & V_188 ) ;
continue;
}
V_138 = true ;
}
F_168 ( V_37 -> V_11 , & V_188 ) ;
if ( V_138 )
F_165 ( V_37 ) ;
}
static int F_174 ( struct V_177 * V_178 ,
struct V_194 * V_195 ,
int V_106 )
{
int V_196 ;
for ( V_196 = V_106 + 1 ; V_196 < V_178 -> V_164 ; V_196 ++ ) {
struct V_52 * V_53 = V_178 -> V_84 [ V_196 ] . V_53 ;
if ( V_53 -> V_95 . V_45 == V_46 ) {
V_195 -> V_102 [ 0 ] = V_178 -> V_84 [ V_196 ] . V_102 ;
return V_196 ;
}
V_195 -> V_197 [ V_53 -> V_95 . V_45 - 2 ] = V_53 ;
V_195 -> V_102 [ V_53 -> V_95 . V_45 - 1 ] = V_178 -> V_84 [ V_196 ] . V_102 ;
}
return V_196 ;
}
static void F_175 ( struct V_194 * V_195 )
{
struct V_52 * V_53 ;
unsigned int V_45 = 0 ;
do {
unsigned int V_102 = V_195 -> V_102 [ V_45 ] ;
V_53 = V_195 -> V_197 [ V_45 ] ;
if ( ! V_53 )
return;
-- V_53 -> V_175 ;
F_3 ( ( int ) V_53 -> V_175 < 0 ) ;
F_158 ( V_102 , V_53 -> V_174 ) ;
V_45 ++ ;
} while ( V_45 < V_198 - 1 && ! V_53 -> V_175 );
}
static void F_176 ( struct V_52 * V_197 ,
struct V_194 * V_195 ,
struct V_177 * V_178 )
{
V_195 -> V_197 [ V_197 -> V_95 . V_45 - 1 ] = NULL ;
V_178 -> V_164 = 0 ;
}
static void F_177 ( struct V_36 * V_37 ,
struct V_52 * V_197 )
{
int V_106 ;
struct V_52 * V_53 ;
struct V_194 V_195 ;
struct V_177 V_199 ;
F_167 ( V_188 ) ;
F_176 ( V_197 , & V_195 , & V_199 ) ;
while ( F_159 ( V_197 , & V_199 ) ) {
bool V_200 = false ;
F_178 (pages, sp, parents, i)
V_200 |= F_113 ( V_37 -> V_11 , V_53 -> V_15 ) ;
if ( V_200 )
F_108 ( V_37 -> V_11 ) ;
F_178 (pages, sp, parents, i) {
F_171 ( V_37 , V_53 , & V_188 ) ;
F_175 ( & V_195 ) ;
}
F_168 ( V_37 -> V_11 , & V_188 ) ;
F_179 ( & V_37 -> V_11 -> V_201 ) ;
F_176 ( V_197 , & V_195 , & V_199 ) ;
}
}
static void F_180 ( struct V_52 * V_53 )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < V_202 ; ++ V_106 )
V_53 -> V_132 [ V_106 ] = 0ull ;
}
static void F_181 ( struct V_52 * V_53 )
{
V_53 -> V_203 = 0 ;
}
static void F_182 ( T_1 * V_10 )
{
struct V_52 * V_53 = F_38 ( F_39 ( V_10 ) ) ;
F_181 ( V_53 ) ;
}
static bool F_183 ( struct V_11 * V_11 , struct V_52 * V_53 )
{
return F_14 ( V_53 -> V_204 != V_11 -> V_38 . V_204 ) ;
}
static struct V_52 * F_184 ( struct V_36 * V_37 ,
T_2 V_15 ,
T_7 V_205 ,
unsigned V_45 ,
int V_96 ,
unsigned V_16 ,
T_1 * V_170 )
{
union V_206 V_95 ;
unsigned V_207 ;
struct V_52 * V_53 ;
bool V_208 = false ;
V_95 = V_37 -> V_38 . V_191 . V_209 ;
V_95 . V_45 = V_45 ;
V_95 . V_96 = V_96 ;
if ( V_95 . V_96 )
V_95 . V_190 = 0 ;
V_95 . V_16 = V_16 ;
if ( ! V_37 -> V_38 . V_191 . V_210
&& V_37 -> V_38 . V_191 . V_211 <= V_212 ) {
V_207 = V_205 >> ( V_19 + ( V_213 * V_45 ) ) ;
V_207 &= ( 1 << ( ( V_214 - V_213 ) * V_45 ) ) - 1 ;
V_95 . V_207 = V_207 ;
}
F_185 (vcpu->kvm, sp, gfn) {
if ( F_183 ( V_37 -> V_11 , V_53 ) )
continue;
if ( ! V_208 && V_53 -> V_179 )
V_208 = true ;
if ( V_53 -> V_95 . V_215 != V_95 . V_215 )
continue;
if ( V_53 -> V_179 && F_166 ( V_37 , V_53 ) )
break;
F_143 ( V_37 , V_53 , V_170 ) ;
if ( V_53 -> V_175 ) {
F_186 ( V_216 , V_37 ) ;
F_150 ( V_53 ) ;
} else if ( V_53 -> V_179 )
F_150 ( V_53 ) ;
F_181 ( V_53 ) ;
F_187 ( V_53 , false ) ;
return V_53 ;
}
++ V_37 -> V_11 -> V_136 . V_217 ;
V_53 = F_146 ( V_37 , V_170 , V_96 ) ;
if ( ! V_53 )
return V_53 ;
V_53 -> V_15 = V_15 ;
V_53 -> V_95 = V_95 ;
F_188 ( & V_53 -> V_167 ,
& V_37 -> V_11 -> V_38 . V_218 [ F_142 ( V_15 ) ] ) ;
if ( ! V_96 ) {
if ( F_113 ( V_37 -> V_11 , V_15 ) )
F_108 ( V_37 -> V_11 ) ;
if ( V_45 > V_46 && V_208 )
F_172 ( V_37 , V_15 ) ;
F_80 ( V_37 -> V_11 , V_15 ) ;
}
V_53 -> V_204 = V_37 -> V_11 -> V_38 . V_204 ;
F_180 ( V_53 ) ;
F_187 ( V_53 , true ) ;
return V_53 ;
}
static void F_189 ( struct V_219 * V_220 ,
struct V_36 * V_37 , T_1 V_221 )
{
V_220 -> V_221 = V_221 ;
V_220 -> V_222 = V_37 -> V_38 . V_191 . V_223 ;
V_220 -> V_45 = V_37 -> V_38 . V_191 . V_224 ;
if ( V_220 -> V_45 == V_198 &&
V_37 -> V_38 . V_191 . V_211 < V_198 &&
! V_37 -> V_38 . V_191 . V_210 )
-- V_220 -> V_45 ;
if ( V_220 -> V_45 == V_225 ) {
V_220 -> V_222
= V_37 -> V_38 . V_191 . V_226 [ ( V_221 >> 30 ) & 3 ] ;
V_220 -> V_222 &= V_47 ;
-- V_220 -> V_45 ;
if ( ! V_220 -> V_222 )
V_220 -> V_45 = 0 ;
}
}
static bool F_190 ( struct V_219 * V_220 )
{
if ( V_220 -> V_45 < V_46 )
return false ;
V_220 -> V_94 = F_191 ( V_220 -> V_221 , V_220 -> V_45 ) ;
V_220 -> V_14 = ( ( T_1 * ) F_192 ( V_220 -> V_222 ) ) + V_220 -> V_94 ;
return true ;
}
static void F_193 ( struct V_219 * V_220 ,
T_1 V_10 )
{
if ( F_27 ( V_10 , V_220 -> V_45 ) ) {
V_220 -> V_45 = 0 ;
return;
}
V_220 -> V_222 = V_10 & V_47 ;
-- V_220 -> V_45 ;
}
static void F_194 ( struct V_219 * V_220 )
{
return F_193 ( V_220 , * V_220 -> V_14 ) ;
}
static void F_195 ( T_1 * V_14 , struct V_52 * V_53 )
{
T_1 V_10 ;
V_10 = F_39 ( V_53 -> V_132 ) | V_42 | V_140 |
V_31 | V_35 | V_32 ;
F_9 ( V_14 , V_10 ) ;
}
static void F_196 ( struct V_36 * V_37 , T_1 * V_14 ,
unsigned V_227 )
{
if ( F_23 ( * V_14 ) && ! F_24 ( * V_14 ) ) {
struct V_52 * V_182 ;
V_182 = F_38 ( * V_14 & V_47 ) ;
if ( V_182 -> V_95 . V_16 == V_227 )
return;
F_145 ( V_182 , V_14 ) ;
F_108 ( V_37 -> V_11 ) ;
}
}
static bool F_197 ( struct V_11 * V_11 , struct V_52 * V_53 ,
T_1 * V_10 )
{
T_1 V_41 ;
struct V_52 * V_182 ;
V_41 = * V_10 ;
if ( F_23 ( V_41 ) ) {
if ( F_27 ( V_41 , V_53 -> V_95 . V_45 ) ) {
F_105 ( V_11 , V_10 ) ;
if ( F_24 ( V_41 ) )
-- V_11 -> V_136 . V_137 ;
} else {
V_182 = F_38 ( V_41 & V_47 ) ;
F_145 ( V_182 , V_10 ) ;
}
return true ;
}
if ( F_10 ( V_41 ) )
F_53 ( V_10 ) ;
return false ;
}
static void F_198 ( struct V_11 * V_11 ,
struct V_52 * V_53 )
{
unsigned V_106 ;
for ( V_106 = 0 ; V_106 < V_202 ; ++ V_106 )
F_197 ( V_11 , V_53 , V_53 -> V_132 + V_106 ) ;
}
static void F_199 ( struct V_52 * V_53 , T_1 * V_170 )
{
F_144 ( V_53 , V_170 ) ;
}
static void F_200 ( struct V_11 * V_11 , struct V_52 * V_53 )
{
T_1 * V_14 ;
struct V_133 V_134 ;
while ( ( V_14 = F_103 ( V_53 -> V_171 , & V_134 ) ) )
F_145 ( V_53 , V_14 ) ;
}
static int F_201 ( struct V_11 * V_11 ,
struct V_52 * V_197 ,
struct V_187 * V_188 )
{
int V_106 , V_228 = 0 ;
struct V_194 V_195 ;
struct V_177 V_199 ;
if ( V_197 -> V_95 . V_45 == V_46 )
return 0 ;
F_176 ( V_197 , & V_195 , & V_199 ) ;
while ( F_159 ( V_197 , & V_199 ) ) {
struct V_52 * V_53 ;
F_178 (pages, sp, parents, i) {
F_164 ( V_11 , V_53 , V_188 ) ;
F_175 ( & V_195 ) ;
V_228 ++ ;
}
F_176 ( V_197 , & V_195 , & V_199 ) ;
}
return V_228 ;
}
static int F_164 ( struct V_11 * V_11 , struct V_52 * V_53 ,
struct V_187 * V_188 )
{
int V_69 ;
F_202 ( V_53 ) ;
++ V_11 -> V_136 . V_229 ;
V_69 = F_201 ( V_11 , V_53 , V_188 ) ;
F_198 ( V_11 , V_53 ) ;
F_200 ( V_11 , V_53 ) ;
if ( ! V_53 -> V_95 . V_230 && ! V_53 -> V_95 . V_96 )
F_82 ( V_11 , V_53 -> V_15 ) ;
if ( V_53 -> V_179 )
F_160 ( V_11 , V_53 ) ;
if ( ! V_53 -> V_231 ) {
V_69 ++ ;
F_203 ( & V_53 -> V_168 , V_188 ) ;
F_137 ( V_11 , - 1 ) ;
} else {
F_203 ( & V_53 -> V_168 , & V_11 -> V_38 . V_172 ) ;
if ( ! V_53 -> V_95 . V_230 && ! F_183 ( V_11 , V_53 ) )
F_204 ( V_11 ) ;
}
V_53 -> V_95 . V_230 = 1 ;
return V_69 ;
}
static void F_168 ( struct V_11 * V_11 ,
struct V_187 * V_188 )
{
struct V_52 * V_53 , * V_232 ;
if ( F_205 ( V_188 ) )
return;
F_57 () ;
F_108 ( V_11 ) ;
F_206 (sp, nsp, invalid_list, link) {
F_3 ( ! V_53 -> V_95 . V_230 || V_53 -> V_231 ) ;
F_139 ( V_53 ) ;
}
}
static bool F_207 ( struct V_11 * V_11 ,
struct V_187 * V_188 )
{
struct V_52 * V_53 ;
if ( F_205 ( & V_11 -> V_38 . V_172 ) )
return false ;
V_53 = F_208 ( V_11 -> V_38 . V_172 . V_233 ,
struct V_52 , V_168 ) ;
F_164 ( V_11 , V_53 , V_188 ) ;
return true ;
}
void F_209 ( struct V_11 * V_11 , unsigned int V_234 )
{
F_167 ( V_188 ) ;
F_210 ( & V_11 -> V_201 ) ;
if ( V_11 -> V_38 . V_165 > V_234 ) {
while ( V_11 -> V_38 . V_165 > V_234 )
if ( ! F_207 ( V_11 , & V_188 ) )
break;
F_168 ( V_11 , & V_188 ) ;
V_234 = V_11 -> V_38 . V_165 ;
}
V_11 -> V_38 . V_235 = V_234 ;
F_211 ( & V_11 -> V_201 ) ;
}
int F_212 ( struct V_11 * V_11 , T_2 V_15 )
{
struct V_52 * V_53 ;
F_167 ( V_188 ) ;
int V_85 ;
F_213 ( L_13 , V_163 , V_15 ) ;
V_85 = 0 ;
F_210 ( & V_11 -> V_201 ) ;
F_173 (kvm, sp, gfn) {
F_213 ( L_14 , V_163 , V_15 ,
V_53 -> V_95 . V_215 ) ;
V_85 = 1 ;
F_164 ( V_11 , V_53 , & V_188 ) ;
}
F_168 ( V_11 , & V_188 ) ;
F_211 ( & V_11 -> V_201 ) ;
return V_85 ;
}
static int F_214 ( struct V_236 * V_237 ,
T_1 V_148 , T_1 V_149 )
{
int V_106 ;
T_1 V_238 , V_4 ;
T_8 V_239 , V_240 ;
int V_241 = V_242 ;
if ( ! V_237 -> V_243 )
return 0xFF ;
V_149 -- ;
if ( V_237 -> V_244 && ( V_148 < 0x100000 ) ) {
int V_102 ;
if ( V_148 < 0x80000 ) {
V_102 = 0 ;
V_102 += ( V_148 >> 16 ) ;
return V_237 -> V_245 [ V_102 ] ;
} else if ( V_148 < 0xC0000 ) {
V_102 = 1 * 8 ;
V_102 += ( ( V_148 - 0x80000 ) >> 14 ) ;
return V_237 -> V_245 [ V_102 ] ;
} else if ( V_148 < 0x1000000 ) {
V_102 = 3 * 8 ;
V_102 += ( ( V_148 - 0xC0000 ) >> 12 ) ;
return V_237 -> V_245 [ V_102 ] ;
}
}
if ( ! ( V_237 -> V_243 & 2 ) )
return V_237 -> V_246 ;
V_239 = 0xFF ;
for ( V_106 = 0 ; V_106 < V_241 ; ++ V_106 ) {
unsigned short V_247 , V_248 ;
if ( ! ( V_237 -> V_249 [ V_106 ] . V_250 & ( 1 << 11 ) ) )
continue;
V_238 = ( ( ( T_1 ) V_237 -> V_249 [ V_106 ] . V_251 ) << 32 ) +
( V_237 -> V_249 [ V_106 ] . V_252 & V_20 ) ;
V_4 = ( ( ( T_1 ) V_237 -> V_249 [ V_106 ] . V_253 ) << 32 ) +
( V_237 -> V_249 [ V_106 ] . V_250 & V_20 ) ;
V_247 = ( ( V_148 & V_4 ) == ( V_238 & V_4 ) ) ;
V_248 = ( ( V_149 & V_4 ) == ( V_238 & V_4 ) ) ;
if ( V_247 != V_248 )
return 0xFE ;
if ( ( V_148 & V_4 ) != ( V_238 & V_4 ) )
continue;
V_240 = V_237 -> V_249 [ V_106 ] . V_252 & 0xff ;
if ( V_239 == 0xFF ) {
V_239 = V_240 ;
continue;
}
if ( V_239 == V_254 ||
V_240 == V_254 )
return V_254 ;
if ( ( V_239 == V_255 &&
V_240 == V_256 ) ||
( V_239 == V_256 &&
V_240 == V_255 ) ) {
V_239 = V_256 ;
V_240 = V_256 ;
}
if ( V_239 != V_240 )
return V_254 ;
}
if ( V_239 != 0xFF )
return V_239 ;
return V_237 -> V_246 ;
}
T_8 F_215 ( struct V_36 * V_37 , T_2 V_15 )
{
T_8 V_257 ;
V_257 = F_214 ( & V_37 -> V_38 . V_237 , V_15 << V_19 ,
( V_15 << V_19 ) + V_158 ) ;
if ( V_257 == 0xfe || V_257 == 0xff )
V_257 = V_255 ;
return V_257 ;
}
static void F_216 ( struct V_36 * V_37 , struct V_52 * V_53 )
{
F_217 ( V_53 ) ;
++ V_37 -> V_11 -> V_136 . V_186 ;
V_53 -> V_179 = 1 ;
F_150 ( V_53 ) ;
}
static void F_218 ( struct V_36 * V_37 , T_2 V_15 )
{
struct V_52 * V_24 ;
F_173 (vcpu->kvm, s, gfn) {
if ( V_24 -> V_179 )
continue;
F_3 ( V_24 -> V_95 . V_45 != V_46 ) ;
F_216 ( V_37 , V_24 ) ;
}
}
static int F_219 ( struct V_36 * V_37 , T_2 V_15 ,
bool V_258 )
{
struct V_52 * V_24 ;
bool V_259 = false ;
F_173 (vcpu->kvm, s, gfn) {
if ( ! V_258 )
return 1 ;
if ( V_24 -> V_95 . V_45 != V_46 )
return 1 ;
if ( ! V_24 -> V_179 )
V_259 = true ;
}
if ( V_259 )
F_218 ( V_37 , V_15 ) ;
return 0 ;
}
static int F_220 ( struct V_36 * V_37 , T_1 * V_14 ,
unsigned V_260 , int V_45 ,
T_2 V_15 , T_3 V_21 , bool V_261 ,
bool V_258 , bool V_262 )
{
T_1 V_10 ;
int V_69 = 0 ;
if ( F_13 ( V_37 -> V_11 , V_14 , V_15 , V_21 , V_260 ) )
return 0 ;
V_10 = V_42 ;
if ( ! V_261 )
V_10 |= V_32 ;
if ( V_260 & V_263 )
V_10 |= V_35 ;
else
V_10 |= V_34 ;
if ( V_260 & V_18 )
V_10 |= V_31 ;
if ( V_45 > V_46 )
V_10 |= V_43 ;
if ( V_264 )
V_10 |= V_119 -> V_265 ( V_37 , V_15 ,
F_50 ( V_21 ) ) ;
if ( V_262 )
V_10 |= V_64 ;
else
V_260 &= ~ V_17 ;
V_10 |= ( T_1 ) V_21 << V_19 ;
if ( V_260 & V_17 ) {
if ( V_45 > V_46 &&
F_83 ( V_37 -> V_11 , V_15 , V_45 ) )
goto V_266;
V_10 |= V_140 | V_65 ;
if ( ! V_258 && F_44 ( * V_14 ) )
goto V_267;
if ( F_219 ( V_37 , V_15 , V_258 ) ) {
F_213 ( L_15 ,
V_163 , V_15 ) ;
V_69 = 1 ;
V_260 &= ~ V_17 ;
V_10 &= ~ ( V_140 | V_65 ) ;
}
}
if ( V_260 & V_17 )
F_221 ( V_37 -> V_11 , V_15 ) ;
V_267:
if ( F_46 ( V_14 , V_10 ) )
F_108 ( V_37 -> V_11 ) ;
V_266:
return V_69 ;
}
static void F_222 ( struct V_36 * V_37 , T_1 * V_14 ,
unsigned V_260 , int V_268 , int * V_269 ,
int V_45 , T_2 V_15 , T_3 V_21 , bool V_261 ,
bool V_262 )
{
int V_270 = 0 ;
int V_271 ;
F_213 ( L_16 , V_163 ,
* V_14 , V_268 , V_15 ) ;
if ( F_26 ( * V_14 ) ) {
if ( V_45 > V_46 &&
! F_24 ( * V_14 ) ) {
struct V_52 * V_182 ;
T_1 V_41 = * V_14 ;
V_182 = F_38 ( V_41 & V_47 ) ;
F_145 ( V_182 , V_14 ) ;
F_108 ( V_37 -> V_11 ) ;
} else if ( V_21 != F_28 ( * V_14 ) ) {
F_213 ( L_17 ,
F_28 ( * V_14 ) , V_21 ) ;
F_105 ( V_37 -> V_11 , V_14 ) ;
F_108 ( V_37 -> V_11 ) ;
} else
V_270 = 1 ;
}
if ( F_220 ( V_37 , V_14 , V_260 , V_45 , V_15 , V_21 , V_261 ,
true , V_262 ) ) {
if ( V_268 )
* V_269 = 1 ;
F_165 ( V_37 ) ;
}
if ( F_14 ( F_10 ( * V_14 ) && V_269 ) )
* V_269 = 1 ;
F_213 ( L_18 , V_163 , * V_14 ) ;
F_213 ( L_19 ,
F_24 ( * V_14 ) ? L_20 : L_21 ,
* V_14 & V_42 ? L_22 : L_23 , V_15 ,
* V_14 , V_14 ) ;
if ( ! V_270 && F_24 ( * V_14 ) )
++ V_37 -> V_11 -> V_136 . V_137 ;
if ( F_23 ( * V_14 ) ) {
if ( ! V_270 ) {
V_271 = F_101 ( V_37 , V_14 , V_15 ) ;
if ( V_271 > V_272 )
F_133 ( V_37 , V_14 , V_15 ) ;
}
}
F_223 ( V_21 ) ;
}
static void F_224 ( struct V_36 * V_37 )
{
F_225 ( V_37 ) ;
}
static bool F_226 ( struct V_273 * V_191 , T_1 V_48 , int V_45 )
{
int V_274 ;
V_274 = ( V_48 >> 7 ) & 1 ;
return ( V_48 & V_191 -> V_275 [ V_274 ] [ V_45 - 1 ] ) != 0 ;
}
static T_3 F_227 ( struct V_36 * V_37 , T_2 V_15 ,
bool V_112 )
{
struct V_100 * V_101 ;
V_101 = F_87 ( V_37 , V_15 , V_112 ) ;
if ( ! V_101 )
return V_276 ;
return F_228 ( V_101 , V_15 ) ;
}
static bool F_229 ( struct V_36 * V_37 ,
struct V_52 * V_53 , T_1 * V_10 ,
T_1 V_48 )
{
if ( F_226 ( & V_37 -> V_38 . V_191 , V_48 , V_46 ) )
goto V_277;
if ( ! F_230 ( V_48 ) )
goto V_277;
if ( ! ( V_48 & V_278 ) )
goto V_277;
return false ;
V_277:
F_105 ( V_37 -> V_11 , V_10 ) ;
return true ;
}
static int F_231 ( struct V_36 * V_37 ,
struct V_52 * V_53 ,
T_1 * V_148 , T_1 * V_149 )
{
struct V_84 * V_199 [ V_88 ] ;
unsigned V_16 = V_53 -> V_95 . V_16 ;
int V_106 , V_69 ;
T_2 V_15 ;
V_15 = F_76 ( V_53 , V_148 - V_53 -> V_132 ) ;
if ( ! F_87 ( V_37 , V_15 , V_16 & V_17 ) )
return - 1 ;
V_69 = F_232 ( V_37 -> V_11 , V_15 , V_199 , V_149 - V_148 ) ;
if ( V_69 <= 0 )
return - 1 ;
for ( V_106 = 0 ; V_106 < V_69 ; V_106 ++ , V_15 ++ , V_148 ++ )
F_222 ( V_37 , V_148 , V_16 , 0 , NULL ,
V_53 -> V_95 . V_45 , V_15 , F_233 ( V_199 [ V_106 ] ) ,
true , true ) ;
return 0 ;
}
static void F_234 ( struct V_36 * V_37 ,
struct V_52 * V_53 , T_1 * V_14 )
{
T_1 * V_10 , * V_148 = NULL ;
int V_106 ;
F_3 ( ! V_53 -> V_95 . V_96 ) ;
V_106 = ( V_14 - V_53 -> V_132 ) & ~ ( V_88 - 1 ) ;
V_10 = V_53 -> V_132 + V_106 ;
for ( V_106 = 0 ; V_106 < V_88 ; V_106 ++ , V_10 ++ ) {
if ( F_23 ( * V_10 ) || V_10 == V_14 ) {
if ( ! V_148 )
continue;
if ( F_231 ( V_37 , V_53 , V_148 , V_10 ) < 0 )
break;
V_148 = NULL ;
} else if ( ! V_148 )
V_148 = V_10 ;
}
}
static void F_235 ( struct V_36 * V_37 , T_1 * V_14 )
{
struct V_52 * V_53 ;
if ( ! V_32 )
return;
V_53 = F_38 ( F_39 ( V_14 ) ) ;
if ( V_53 -> V_95 . V_45 > V_46 )
return;
F_234 ( V_37 , V_53 , V_14 ) ;
}
static int F_236 ( struct V_36 * V_37 , T_9 V_279 , int V_280 ,
int V_281 , int V_45 , T_2 V_15 , T_3 V_21 ,
bool V_282 )
{
struct V_219 V_220 ;
struct V_52 * V_53 ;
int V_269 = 0 ;
T_2 V_283 ;
F_237 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_220 . V_45 == V_45 ) {
F_222 ( V_37 , V_220 . V_14 , V_284 ,
V_280 , & V_269 , V_45 , V_15 , V_21 ,
V_282 , V_281 ) ;
F_235 ( V_37 , V_220 . V_14 ) ;
++ V_37 -> V_136 . V_285 ;
break;
}
if ( ! F_23 ( * V_220 . V_14 ) ) {
T_1 V_286 = V_220 . V_221 ;
V_286 &= F_238 ( V_220 . V_45 ) ;
V_283 = V_286 >> V_19 ;
V_53 = F_184 ( V_37 , V_283 , V_220 . V_221 ,
V_220 . V_45 - 1 ,
1 , V_284 , V_220 . V_14 ) ;
F_195 ( V_220 . V_14 , V_53 ) ;
}
}
return V_269 ;
}
static void F_239 ( unsigned long V_287 , struct V_288 * V_289 )
{
T_10 V_290 ;
V_290 . V_291 = V_292 ;
V_290 . V_293 = 0 ;
V_290 . V_294 = V_295 ;
V_290 . V_296 = ( void V_297 * ) V_287 ;
V_290 . V_298 = V_19 ;
F_240 ( V_292 , & V_290 , V_289 ) ;
}
static int F_241 ( struct V_36 * V_37 , T_2 V_15 , T_3 V_21 )
{
if ( V_21 == V_299 )
return 1 ;
if ( V_21 == V_300 ) {
F_239 ( F_242 ( V_37 -> V_11 , V_15 ) , V_301 ) ;
return 0 ;
}
return - V_302 ;
}
static void F_243 ( struct V_36 * V_37 ,
T_2 * V_303 , T_3 * V_304 , int * V_305 )
{
T_3 V_21 = * V_304 ;
T_2 V_15 = * V_303 ;
int V_45 = * V_305 ;
if ( ! F_244 ( V_21 ) && ! F_50 ( V_21 ) &&
V_45 == V_46 &&
F_245 ( F_52 ( V_21 ) ) &&
! F_83 ( V_37 -> V_11 , V_15 , V_107 ) ) {
unsigned long V_4 ;
* V_305 = V_45 = V_107 ;
V_4 = F_246 ( V_45 ) - 1 ;
F_247 ( ( V_15 & V_4 ) != ( V_21 & V_4 ) ) ;
if ( V_21 & V_4 ) {
V_15 &= ~ V_4 ;
* V_303 = V_15 ;
F_223 ( V_21 ) ;
V_21 &= ~ V_4 ;
F_248 ( V_21 ) ;
* V_304 = V_21 ;
}
}
}
static bool F_249 ( struct V_36 * V_37 , T_7 V_176 , T_2 V_15 ,
T_3 V_21 , unsigned V_16 , int * V_306 )
{
bool V_69 = true ;
if ( F_14 ( F_250 ( V_21 ) ) ) {
* V_306 = F_241 ( V_37 , V_15 , V_21 ) ;
goto exit;
}
if ( F_14 ( F_15 ( V_21 ) ) )
F_251 ( V_37 , V_176 , V_15 , V_16 ) ;
V_69 = false ;
exit:
return V_69 ;
}
static bool F_252 ( struct V_36 * V_37 , T_4 V_307 )
{
if ( F_14 ( V_307 & V_308 ) )
return false ;
if ( ! ( V_307 & V_309 ) ||
! ( V_307 & V_310 ) )
return false ;
return true ;
}
static bool
F_253 ( struct V_36 * V_37 , T_1 * V_14 , T_1 V_10 )
{
struct V_52 * V_53 = F_38 ( F_39 ( V_14 ) ) ;
T_2 V_15 ;
F_3 ( ! V_53 -> V_95 . V_96 ) ;
V_15 = F_76 ( V_53 , V_14 - V_53 -> V_132 ) ;
if ( F_254 ( V_14 , V_10 , V_10 | V_140 ) == V_10 )
F_221 ( V_37 -> V_11 , V_15 ) ;
return true ;
}
static bool F_255 ( struct V_36 * V_37 , T_7 V_176 , int V_45 ,
T_4 V_307 )
{
struct V_219 V_220 ;
bool V_69 = false ;
T_1 V_10 = 0ull ;
if ( ! F_252 ( V_37 , V_307 ) )
return false ;
F_55 ( V_37 ) ;
F_256 (vcpu, gva, iterator, spte)
if ( ! F_23 ( V_10 ) || V_220 . V_45 < V_45 )
break;
if ( ! F_26 ( V_10 ) ) {
V_69 = true ;
goto exit;
}
if ( ! F_27 ( V_10 , V_45 ) )
goto exit;
if ( F_44 ( V_10 ) ) {
V_69 = true ;
goto exit;
}
if ( ! F_42 ( V_10 ) )
goto exit;
V_69 = F_253 ( V_37 , V_220 . V_14 , V_10 ) ;
exit:
F_257 ( V_37 , V_176 , V_307 , V_220 . V_14 ,
V_10 , V_69 ) ;
F_58 ( V_37 ) ;
return V_69 ;
}
static int F_258 ( struct V_36 * V_37 , T_7 V_279 , T_4 V_307 ,
T_2 V_15 , bool V_282 )
{
int V_85 ;
int V_45 ;
int V_311 ;
T_3 V_21 ;
unsigned long V_312 ;
bool V_281 , V_280 = V_307 & V_310 ;
V_311 = F_88 ( V_37 , V_15 ) ;
if ( F_18 ( ! V_311 ) ) {
V_45 = F_89 ( V_37 , V_15 ) ;
if ( V_45 > V_107 )
V_45 = V_107 ;
V_15 &= ~ ( F_246 ( V_45 ) - 1 ) ;
} else
V_45 = V_46 ;
if ( F_255 ( V_37 , V_279 , V_45 , V_307 ) )
return 0 ;
V_312 = V_37 -> V_11 -> V_313 ;
F_41 () ;
if ( F_259 ( V_37 , V_282 , V_15 , V_279 , & V_21 , V_280 , & V_281 ) )
return 0 ;
if ( F_249 ( V_37 , V_279 , V_15 , V_21 , V_284 , & V_85 ) )
return V_85 ;
F_210 ( & V_37 -> V_11 -> V_201 ) ;
if ( F_260 ( V_37 -> V_11 , V_312 ) )
goto V_314;
F_261 ( V_37 ) ;
if ( F_18 ( ! V_311 ) )
F_243 ( V_37 , & V_15 , & V_21 , & V_45 ) ;
V_85 = F_236 ( V_37 , V_279 , V_280 , V_281 , V_45 , V_15 , V_21 ,
V_282 ) ;
F_211 ( & V_37 -> V_11 -> V_201 ) ;
return V_85 ;
V_314:
F_211 ( & V_37 -> V_11 -> V_201 ) ;
F_223 ( V_21 ) ;
return 0 ;
}
static void F_225 ( struct V_36 * V_37 )
{
int V_106 ;
struct V_52 * V_53 ;
F_167 ( V_188 ) ;
if ( ! F_262 ( V_37 -> V_38 . V_191 . V_223 ) )
return;
if ( V_37 -> V_38 . V_191 . V_224 == V_198 &&
( V_37 -> V_38 . V_191 . V_211 == V_198 ||
V_37 -> V_38 . V_191 . V_210 ) ) {
T_11 V_315 = V_37 -> V_38 . V_191 . V_223 ;
F_210 ( & V_37 -> V_11 -> V_201 ) ;
V_53 = F_38 ( V_315 ) ;
-- V_53 -> V_231 ;
if ( ! V_53 -> V_231 && V_53 -> V_95 . V_230 ) {
F_164 ( V_37 -> V_11 , V_53 , & V_188 ) ;
F_168 ( V_37 -> V_11 , & V_188 ) ;
}
F_211 ( & V_37 -> V_11 -> V_201 ) ;
V_37 -> V_38 . V_191 . V_223 = V_316 ;
return;
}
F_210 ( & V_37 -> V_11 -> V_201 ) ;
for ( V_106 = 0 ; V_106 < 4 ; ++ V_106 ) {
T_11 V_315 = V_37 -> V_38 . V_191 . V_226 [ V_106 ] ;
if ( V_315 ) {
V_315 &= V_47 ;
V_53 = F_38 ( V_315 ) ;
-- V_53 -> V_231 ;
if ( ! V_53 -> V_231 && V_53 -> V_95 . V_230 )
F_164 ( V_37 -> V_11 , V_53 ,
& V_188 ) ;
}
V_37 -> V_38 . V_191 . V_226 [ V_106 ] = V_316 ;
}
F_168 ( V_37 -> V_11 , & V_188 ) ;
F_211 ( & V_37 -> V_11 -> V_201 ) ;
V_37 -> V_38 . V_191 . V_223 = V_316 ;
}
static int F_263 ( struct V_36 * V_37 , T_2 V_317 )
{
int V_69 = 0 ;
if ( ! F_264 ( V_37 -> V_11 , V_317 ) ) {
F_186 ( V_318 , V_37 ) ;
V_69 = 1 ;
}
return V_69 ;
}
static int F_265 ( struct V_36 * V_37 )
{
struct V_52 * V_53 ;
unsigned V_106 ;
if ( V_37 -> V_38 . V_191 . V_224 == V_198 ) {
F_210 ( & V_37 -> V_11 -> V_201 ) ;
F_261 ( V_37 ) ;
V_53 = F_184 ( V_37 , 0 , 0 , V_198 ,
1 , V_284 , NULL ) ;
++ V_53 -> V_231 ;
F_211 ( & V_37 -> V_11 -> V_201 ) ;
V_37 -> V_38 . V_191 . V_223 = F_39 ( V_53 -> V_132 ) ;
} else if ( V_37 -> V_38 . V_191 . V_224 == V_225 ) {
for ( V_106 = 0 ; V_106 < 4 ; ++ V_106 ) {
T_11 V_315 = V_37 -> V_38 . V_191 . V_226 [ V_106 ] ;
ASSERT ( ! F_262 ( V_315 ) ) ;
F_210 ( & V_37 -> V_11 -> V_201 ) ;
F_261 ( V_37 ) ;
V_53 = F_184 ( V_37 , V_106 << ( 30 - V_19 ) ,
V_106 << 30 ,
V_212 , 1 , V_284 ,
NULL ) ;
V_315 = F_39 ( V_53 -> V_132 ) ;
++ V_53 -> V_231 ;
F_211 ( & V_37 -> V_11 -> V_201 ) ;
V_37 -> V_38 . V_191 . V_226 [ V_106 ] = V_315 | V_42 ;
}
V_37 -> V_38 . V_191 . V_223 = F_39 ( V_37 -> V_38 . V_191 . V_226 ) ;
} else
F_95 () ;
return 0 ;
}
static int F_266 ( struct V_36 * V_37 )
{
struct V_52 * V_53 ;
T_1 V_319 , V_320 ;
T_2 V_317 ;
int V_106 ;
V_317 = V_37 -> V_38 . V_191 . V_321 ( V_37 ) >> V_19 ;
if ( F_263 ( V_37 , V_317 ) )
return 1 ;
if ( V_37 -> V_38 . V_191 . V_211 == V_198 ) {
T_11 V_315 = V_37 -> V_38 . V_191 . V_223 ;
ASSERT ( ! F_262 ( V_315 ) ) ;
F_210 ( & V_37 -> V_11 -> V_201 ) ;
F_261 ( V_37 ) ;
V_53 = F_184 ( V_37 , V_317 , 0 , V_198 ,
0 , V_284 , NULL ) ;
V_315 = F_39 ( V_53 -> V_132 ) ;
++ V_53 -> V_231 ;
F_211 ( & V_37 -> V_11 -> V_201 ) ;
V_37 -> V_38 . V_191 . V_223 = V_315 ;
return 0 ;
}
V_320 = V_42 ;
if ( V_37 -> V_38 . V_191 . V_224 == V_198 )
V_320 |= V_278 | V_140 | V_322 ;
for ( V_106 = 0 ; V_106 < 4 ; ++ V_106 ) {
T_11 V_315 = V_37 -> V_38 . V_191 . V_226 [ V_106 ] ;
ASSERT ( ! F_262 ( V_315 ) ) ;
if ( V_37 -> V_38 . V_191 . V_211 == V_225 ) {
V_319 = V_37 -> V_38 . V_191 . V_323 ( V_37 , V_106 ) ;
if ( ! F_230 ( V_319 ) ) {
V_37 -> V_38 . V_191 . V_226 [ V_106 ] = 0 ;
continue;
}
V_317 = V_319 >> V_19 ;
if ( F_263 ( V_37 , V_317 ) )
return 1 ;
}
F_210 ( & V_37 -> V_11 -> V_201 ) ;
F_261 ( V_37 ) ;
V_53 = F_184 ( V_37 , V_317 , V_106 << 30 ,
V_212 , 0 ,
V_284 , NULL ) ;
V_315 = F_39 ( V_53 -> V_132 ) ;
++ V_53 -> V_231 ;
F_211 ( & V_37 -> V_11 -> V_201 ) ;
V_37 -> V_38 . V_191 . V_226 [ V_106 ] = V_315 | V_320 ;
}
V_37 -> V_38 . V_191 . V_223 = F_39 ( V_37 -> V_38 . V_191 . V_226 ) ;
if ( V_37 -> V_38 . V_191 . V_224 == V_198 ) {
if ( V_37 -> V_38 . V_191 . V_324 == NULL ) {
T_1 * V_324 ;
V_324 = ( void * ) F_267 ( V_81 ) ;
if ( V_324 == NULL )
return 1 ;
V_324 [ 0 ] = F_39 ( V_37 -> V_38 . V_191 . V_226 ) | V_320 ;
V_37 -> V_38 . V_191 . V_324 = V_324 ;
}
V_37 -> V_38 . V_191 . V_223 = F_39 ( V_37 -> V_38 . V_191 . V_324 ) ;
}
return 0 ;
}
static int F_268 ( struct V_36 * V_37 )
{
if ( V_37 -> V_38 . V_191 . V_210 )
return F_265 ( V_37 ) ;
else
return F_266 ( V_37 ) ;
}
static void F_269 ( struct V_36 * V_37 )
{
int V_106 ;
struct V_52 * V_53 ;
if ( V_37 -> V_38 . V_191 . V_210 )
return;
if ( ! F_262 ( V_37 -> V_38 . V_191 . V_223 ) )
return;
F_270 ( V_37 , ~ 0ul ) ;
F_169 ( V_37 , V_325 ) ;
if ( V_37 -> V_38 . V_191 . V_211 == V_198 ) {
T_11 V_315 = V_37 -> V_38 . V_191 . V_223 ;
V_53 = F_38 ( V_315 ) ;
F_177 ( V_37 , V_53 ) ;
F_169 ( V_37 , V_326 ) ;
return;
}
for ( V_106 = 0 ; V_106 < 4 ; ++ V_106 ) {
T_11 V_315 = V_37 -> V_38 . V_191 . V_226 [ V_106 ] ;
if ( V_315 && F_262 ( V_315 ) ) {
V_315 &= V_47 ;
V_53 = F_38 ( V_315 ) ;
F_177 ( V_37 , V_53 ) ;
}
}
F_169 ( V_37 , V_326 ) ;
}
void F_271 ( struct V_36 * V_37 )
{
F_210 ( & V_37 -> V_11 -> V_201 ) ;
F_269 ( V_37 ) ;
F_211 ( & V_37 -> V_11 -> V_201 ) ;
}
static T_9 F_272 ( struct V_36 * V_37 , T_7 V_327 ,
T_4 V_16 , struct V_328 * V_329 )
{
if ( V_329 )
V_329 -> V_307 = 0 ;
return V_327 ;
}
static T_9 F_273 ( struct V_36 * V_37 , T_7 V_327 ,
T_4 V_16 ,
struct V_328 * V_329 )
{
if ( V_329 )
V_329 -> V_307 = 0 ;
return V_37 -> V_38 . V_330 . V_331 ( V_37 , V_327 , V_16 ) ;
}
static bool F_274 ( struct V_36 * V_37 , T_1 V_221 , bool V_96 )
{
if ( V_96 )
return F_275 ( V_37 , V_221 ) ;
return F_276 ( V_37 , V_221 ) ;
}
static bool F_277 ( T_1 V_10 )
{
return F_36 ( V_10 ) ;
}
static T_1 F_278 ( struct V_36 * V_37 , T_1 V_221 )
{
struct V_219 V_220 ;
T_1 V_10 = 0ull ;
F_55 ( V_37 ) ;
F_256 (vcpu, addr, iterator, spte)
if ( ! F_23 ( V_10 ) )
break;
F_58 ( V_37 ) ;
return V_10 ;
}
int F_279 ( struct V_36 * V_37 , T_1 V_221 , bool V_96 )
{
T_1 V_10 ;
if ( F_274 ( V_37 , V_221 , V_96 ) )
return V_332 ;
V_10 = F_278 ( V_37 , V_221 ) ;
if ( F_10 ( V_10 ) ) {
T_2 V_15 = F_11 ( V_10 ) ;
unsigned V_16 = F_12 ( V_10 ) ;
if ( ! F_16 ( V_37 -> V_11 , V_10 ) )
return V_333 ;
if ( V_96 )
V_221 = 0 ;
F_280 ( V_221 , V_15 , V_16 ) ;
F_251 ( V_37 , V_221 , V_15 , V_16 ) ;
return V_332 ;
}
if ( V_96 && ! F_277 ( V_10 ) )
return V_334 ;
return V_335 ;
}
static int F_281 ( struct V_36 * V_37 , T_1 V_221 ,
T_4 V_307 , bool V_96 )
{
int V_69 ;
V_69 = F_279 ( V_37 , V_221 , V_96 ) ;
F_3 ( V_69 == V_334 ) ;
return V_69 ;
}
static int F_282 ( struct V_36 * V_37 , T_7 V_176 ,
T_4 V_307 , bool V_282 )
{
T_2 V_15 ;
int V_85 ;
F_213 ( L_24 , V_163 , V_176 , V_307 ) ;
if ( F_14 ( V_307 & V_308 ) ) {
V_85 = F_281 ( V_37 , V_176 , V_307 , true ) ;
if ( F_18 ( V_85 != V_333 ) )
return V_85 ;
}
V_85 = F_70 ( V_37 ) ;
if ( V_85 )
return V_85 ;
ASSERT ( V_37 ) ;
ASSERT ( F_262 ( V_37 -> V_38 . V_191 . V_223 ) ) ;
V_15 = V_176 >> V_19 ;
return F_258 ( V_37 , V_176 & V_20 ,
V_307 , V_15 , V_282 ) ;
}
static int F_283 ( struct V_36 * V_37 , T_7 V_176 , T_2 V_15 )
{
struct V_336 V_38 ;
V_38 . V_337 = ( V_37 -> V_38 . V_338 . V_339 ++ << 12 ) | V_37 -> V_340 ;
V_38 . V_15 = V_15 ;
V_38 . V_210 = V_37 -> V_38 . V_191 . V_210 ;
V_38 . V_341 = V_37 -> V_38 . V_191 . V_321 ( V_37 ) ;
return F_284 ( V_37 , V_176 , V_15 , & V_38 ) ;
}
static bool F_285 ( struct V_36 * V_37 )
{
if ( F_14 ( ! F_286 ( V_37 -> V_11 ) ||
F_287 ( V_37 ) ) )
return false ;
return V_119 -> V_342 ( V_37 ) ;
}
static bool F_259 ( struct V_36 * V_37 , bool V_282 , T_2 V_15 ,
T_7 V_176 , T_3 * V_21 , bool V_280 , bool * V_343 )
{
bool V_344 ;
* V_21 = F_288 ( V_37 -> V_11 , V_15 , & V_344 , V_280 , V_343 ) ;
if ( ! V_344 )
return false ;
if ( ! V_282 && F_285 ( V_37 ) ) {
F_289 ( V_176 , V_15 ) ;
if ( F_290 ( V_37 , V_15 ) ) {
F_291 ( V_176 , V_15 ) ;
F_186 ( V_345 , V_37 ) ;
return true ;
} else if ( F_283 ( V_37 , V_176 , V_15 ) )
return true ;
}
* V_21 = F_292 ( V_37 -> V_11 , V_15 , V_280 , V_343 ) ;
return false ;
}
static int F_293 ( struct V_36 * V_37 , T_7 V_346 , T_4 V_307 ,
bool V_282 )
{
T_3 V_21 ;
int V_85 ;
int V_45 ;
int V_311 ;
T_2 V_15 = V_346 >> V_19 ;
unsigned long V_312 ;
int V_280 = V_307 & V_310 ;
bool V_281 ;
ASSERT ( V_37 ) ;
ASSERT ( F_262 ( V_37 -> V_38 . V_191 . V_223 ) ) ;
if ( F_14 ( V_307 & V_308 ) ) {
V_85 = F_281 ( V_37 , V_346 , V_307 , true ) ;
if ( F_18 ( V_85 != V_333 ) )
return V_85 ;
}
V_85 = F_70 ( V_37 ) ;
if ( V_85 )
return V_85 ;
V_311 = F_88 ( V_37 , V_15 ) ;
if ( F_18 ( ! V_311 ) ) {
V_45 = F_89 ( V_37 , V_15 ) ;
V_15 &= ~ ( F_246 ( V_45 ) - 1 ) ;
} else
V_45 = V_46 ;
if ( F_255 ( V_37 , V_346 , V_45 , V_307 ) )
return 0 ;
V_312 = V_37 -> V_11 -> V_313 ;
F_41 () ;
if ( F_259 ( V_37 , V_282 , V_15 , V_346 , & V_21 , V_280 , & V_281 ) )
return 0 ;
if ( F_249 ( V_37 , 0 , V_15 , V_21 , V_284 , & V_85 ) )
return V_85 ;
F_210 ( & V_37 -> V_11 -> V_201 ) ;
if ( F_260 ( V_37 -> V_11 , V_312 ) )
goto V_314;
F_261 ( V_37 ) ;
if ( F_18 ( ! V_311 ) )
F_243 ( V_37 , & V_15 , & V_21 , & V_45 ) ;
V_85 = F_236 ( V_37 , V_346 , V_280 , V_281 ,
V_45 , V_15 , V_21 , V_282 ) ;
F_211 ( & V_37 -> V_11 -> V_201 ) ;
return V_85 ;
V_314:
F_211 ( & V_37 -> V_11 -> V_201 ) ;
F_223 ( V_21 ) ;
return 0 ;
}
static void F_294 ( struct V_36 * V_37 )
{
F_225 ( V_37 ) ;
}
static int F_295 ( struct V_36 * V_37 ,
struct V_273 * V_347 )
{
V_347 -> V_348 = F_224 ;
V_347 -> V_349 = F_282 ;
V_347 -> V_350 = F_272 ;
V_347 -> free = F_294 ;
V_347 -> V_192 = F_152 ;
V_347 -> V_351 = F_153 ;
V_347 -> V_352 = F_154 ;
V_347 -> V_211 = 0 ;
V_347 -> V_224 = V_225 ;
V_347 -> V_223 = V_316 ;
V_347 -> V_210 = true ;
V_347 -> V_353 = false ;
return 0 ;
}
void F_165 ( struct V_36 * V_37 )
{
++ V_37 -> V_136 . V_354 ;
F_186 ( V_355 , V_37 ) ;
}
static void F_296 ( struct V_36 * V_37 )
{
F_213 ( L_25 , V_163 , F_297 ( V_37 ) ) ;
F_225 ( V_37 ) ;
}
static unsigned long V_321 ( struct V_36 * V_37 )
{
return F_297 ( V_37 ) ;
}
static void F_298 ( struct V_36 * V_37 ,
struct V_328 * V_356 )
{
V_37 -> V_38 . V_191 . F_298 ( V_37 , V_356 ) ;
}
static void F_299 ( struct V_36 * V_37 )
{
F_294 ( V_37 ) ;
}
static inline void F_300 ( unsigned * V_16 , unsigned V_48 )
{
unsigned V_4 ;
F_301 ( V_140 != V_17 ) ;
V_4 = ( unsigned ) ~ V_17 ;
V_4 |= ( V_48 >> ( V_357 - V_358 ) ) & V_140 ;
* V_16 &= V_4 ;
}
static bool F_302 ( struct V_11 * V_11 , T_1 * V_14 , T_2 V_15 ,
unsigned V_16 , int * V_359 )
{
if ( F_14 ( F_10 ( * V_14 ) ) ) {
if ( V_15 != F_11 ( * V_14 ) ) {
F_53 ( V_14 ) ;
return true ;
}
( * V_359 ) ++ ;
F_7 ( V_11 , V_14 , V_15 , V_16 ) ;
return true ;
}
return false ;
}
static inline unsigned F_303 ( struct V_36 * V_37 , T_1 V_48 )
{
unsigned V_16 ;
V_16 = ( V_48 & ( V_140 | V_322 ) ) | V_263 ;
V_16 &= ~ ( V_48 >> V_360 ) ;
return V_16 ;
}
static inline bool F_304 ( struct V_273 * V_191 , unsigned V_45 , unsigned V_48 )
{
unsigned V_94 ;
V_94 = V_45 - 1 ;
V_94 |= ( V_48 & V_43 ) >> ( V_361 - 2 ) ;
return V_191 -> V_362 & ( 1 << V_94 ) ;
}
static void F_305 ( struct V_36 * V_37 ,
struct V_273 * V_347 )
{
int V_363 = F_306 ( V_37 ) ;
T_1 V_364 = 0 ;
if ( ! V_347 -> V_353 )
V_364 = F_19 ( 63 , 63 ) ;
switch ( V_347 -> V_211 ) {
case V_212 :
V_347 -> V_275 [ 0 ] [ 1 ] = 0 ;
V_347 -> V_275 [ 0 ] [ 0 ] = 0 ;
V_347 -> V_275 [ 1 ] [ 0 ] = V_347 -> V_275 [ 0 ] [ 0 ] ;
if ( ! F_307 ( V_37 ) ) {
V_347 -> V_275 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_21 () )
V_347 -> V_275 [ 1 ] [ 1 ] = F_19 ( 17 , 21 ) ;
else
V_347 -> V_275 [ 1 ] [ 1 ] = F_19 ( 13 , 21 ) ;
break;
case V_225 :
V_347 -> V_275 [ 0 ] [ 2 ] =
F_19 ( V_363 , 63 ) |
F_19 ( 7 , 8 ) | F_19 ( 1 , 2 ) ;
V_347 -> V_275 [ 0 ] [ 1 ] = V_364 |
F_19 ( V_363 , 62 ) ;
V_347 -> V_275 [ 0 ] [ 0 ] = V_364 |
F_19 ( V_363 , 62 ) ;
V_347 -> V_275 [ 1 ] [ 1 ] = V_364 |
F_19 ( V_363 , 62 ) |
F_19 ( 13 , 20 ) ;
V_347 -> V_275 [ 1 ] [ 0 ] = V_347 -> V_275 [ 0 ] [ 0 ] ;
break;
case V_198 :
V_347 -> V_275 [ 0 ] [ 3 ] = V_364 |
F_19 ( V_363 , 51 ) | F_19 ( 7 , 8 ) ;
V_347 -> V_275 [ 0 ] [ 2 ] = V_364 |
F_19 ( V_363 , 51 ) | F_19 ( 7 , 8 ) ;
V_347 -> V_275 [ 0 ] [ 1 ] = V_364 |
F_19 ( V_363 , 51 ) ;
V_347 -> V_275 [ 0 ] [ 0 ] = V_364 |
F_19 ( V_363 , 51 ) ;
V_347 -> V_275 [ 1 ] [ 3 ] = V_347 -> V_275 [ 0 ] [ 3 ] ;
V_347 -> V_275 [ 1 ] [ 2 ] = V_364 |
F_19 ( V_363 , 51 ) |
F_19 ( 13 , 29 ) ;
V_347 -> V_275 [ 1 ] [ 1 ] = V_364 |
F_19 ( V_363 , 51 ) |
F_19 ( 13 , 20 ) ;
V_347 -> V_275 [ 1 ] [ 0 ] = V_347 -> V_275 [ 0 ] [ 0 ] ;
break;
}
}
static void F_308 ( struct V_36 * V_37 , struct V_273 * V_191 )
{
unsigned V_365 , V_366 , V_367 ;
T_8 V_368 ;
bool V_356 , V_369 , V_370 , V_371 , V_372 , V_373 , V_374 , V_375 ;
V_375 = F_309 ( V_37 , V_376 ) ;
for ( V_366 = 0 ; V_366 < F_61 ( V_191 -> V_377 ) ; ++ V_366 ) {
V_367 = V_366 << 1 ;
V_368 = 0 ;
V_372 = V_367 & V_310 ;
V_373 = V_367 & V_378 ;
V_374 = V_367 & V_379 ;
for ( V_365 = 0 ; V_365 < 8 ; ++ V_365 ) {
V_369 = V_365 & V_263 ;
V_370 = V_365 & V_17 ;
V_371 = V_365 & V_18 ;
V_369 |= ! V_191 -> V_353 ;
V_370 |= ! F_310 ( V_37 ) && ! V_373 ;
V_369 &= ! ( V_375 && V_371 && ! V_373 ) ;
V_356 = ( V_374 && ! V_369 ) || ( V_373 && ! V_371 ) || ( V_372 && ! V_370 ) ;
V_368 |= V_356 << V_365 ;
}
V_191 -> V_377 [ V_366 ] = V_368 ;
}
}
static void F_311 ( struct V_36 * V_37 , struct V_273 * V_191 )
{
T_8 V_368 ;
unsigned V_45 , V_211 = V_191 -> V_211 ;
const unsigned V_380 = 1 << 2 ;
if ( V_211 == V_225 )
-- V_211 ;
V_368 = 1 | ( 1 << V_380 ) ;
for ( V_45 = V_107 ; V_45 <= V_211 ; ++ V_45 ) {
if ( V_45 <= V_381
&& ( V_191 -> V_211 >= V_225 || F_307 ( V_37 ) ) )
V_368 |= 1 << ( V_380 | ( V_45 - 1 ) ) ;
}
V_191 -> V_362 = V_368 ;
}
static int F_312 ( struct V_36 * V_37 ,
struct V_273 * V_347 ,
int V_45 )
{
V_347 -> V_353 = F_22 ( V_37 ) ;
V_347 -> V_211 = V_45 ;
F_305 ( V_37 , V_347 ) ;
F_308 ( V_37 , V_347 ) ;
F_311 ( V_37 , V_347 ) ;
ASSERT ( F_163 ( V_37 ) ) ;
V_347 -> V_348 = F_296 ;
V_347 -> V_349 = V_382 ;
V_347 -> V_350 = V_383 ;
V_347 -> V_192 = V_384 ;
V_347 -> V_351 = V_385 ;
V_347 -> V_352 = V_386 ;
V_347 -> free = F_299 ;
V_347 -> V_224 = V_45 ;
V_347 -> V_223 = V_316 ;
V_347 -> V_210 = false ;
return 0 ;
}
static int F_313 ( struct V_36 * V_37 ,
struct V_273 * V_347 )
{
return F_312 ( V_37 , V_347 , V_198 ) ;
}
static int F_314 ( struct V_36 * V_37 ,
struct V_273 * V_347 )
{
V_347 -> V_353 = false ;
V_347 -> V_211 = V_212 ;
F_305 ( V_37 , V_347 ) ;
F_308 ( V_37 , V_347 ) ;
F_311 ( V_37 , V_347 ) ;
V_347 -> V_348 = F_296 ;
V_347 -> V_349 = V_387 ;
V_347 -> V_350 = V_388 ;
V_347 -> free = F_299 ;
V_347 -> V_192 = V_389 ;
V_347 -> V_351 = V_390 ;
V_347 -> V_352 = V_391 ;
V_347 -> V_224 = V_225 ;
V_347 -> V_223 = V_316 ;
V_347 -> V_210 = false ;
return 0 ;
}
static int F_315 ( struct V_36 * V_37 ,
struct V_273 * V_347 )
{
return F_312 ( V_37 , V_347 , V_225 ) ;
}
static int F_316 ( struct V_36 * V_37 )
{
struct V_273 * V_347 = V_37 -> V_38 . V_392 ;
V_347 -> V_209 . V_215 = 0 ;
V_347 -> V_348 = F_224 ;
V_347 -> V_349 = F_293 ;
V_347 -> free = F_294 ;
V_347 -> V_192 = F_152 ;
V_347 -> V_351 = F_153 ;
V_347 -> V_352 = F_154 ;
V_347 -> V_224 = V_119 -> V_393 () ;
V_347 -> V_223 = V_316 ;
V_347 -> V_210 = true ;
V_347 -> V_394 = V_119 -> V_395 ;
V_347 -> V_321 = V_321 ;
V_347 -> V_323 = V_396 ;
V_347 -> F_298 = V_397 ;
if ( ! F_317 ( V_37 ) ) {
V_347 -> V_353 = false ;
V_347 -> V_350 = F_272 ;
V_347 -> V_211 = 0 ;
} else if ( F_318 ( V_37 ) ) {
V_347 -> V_353 = F_22 ( V_37 ) ;
V_347 -> V_211 = V_198 ;
F_305 ( V_37 , V_347 ) ;
V_347 -> V_350 = V_383 ;
} else if ( F_163 ( V_37 ) ) {
V_347 -> V_353 = F_22 ( V_37 ) ;
V_347 -> V_211 = V_225 ;
F_305 ( V_37 , V_347 ) ;
V_347 -> V_350 = V_383 ;
} else {
V_347 -> V_353 = false ;
V_347 -> V_211 = V_212 ;
F_305 ( V_37 , V_347 ) ;
V_347 -> V_350 = V_388 ;
}
F_308 ( V_37 , V_347 ) ;
F_311 ( V_37 , V_347 ) ;
return 0 ;
}
int F_319 ( struct V_36 * V_37 , struct V_273 * V_347 )
{
int V_85 ;
bool V_375 = F_309 ( V_37 , V_376 ) ;
ASSERT ( V_37 ) ;
ASSERT ( ! F_262 ( V_37 -> V_38 . V_191 . V_223 ) ) ;
if ( ! F_317 ( V_37 ) )
V_85 = F_295 ( V_37 , V_347 ) ;
else if ( F_318 ( V_37 ) )
V_85 = F_313 ( V_37 , V_347 ) ;
else if ( F_163 ( V_37 ) )
V_85 = F_315 ( V_37 , V_347 ) ;
else
V_85 = F_314 ( V_37 , V_347 ) ;
V_37 -> V_38 . V_191 . V_209 . V_398 = F_22 ( V_37 ) ;
V_37 -> V_38 . V_191 . V_209 . V_190 = ! ! F_163 ( V_37 ) ;
V_37 -> V_38 . V_191 . V_209 . V_399 = F_310 ( V_37 ) ;
V_37 -> V_38 . V_191 . V_209 . V_400
= V_375 && ! F_310 ( V_37 ) ;
return V_85 ;
}
static int F_320 ( struct V_36 * V_37 )
{
int V_85 = F_319 ( V_37 , V_37 -> V_38 . V_392 ) ;
V_37 -> V_38 . V_392 -> V_394 = V_119 -> V_394 ;
V_37 -> V_38 . V_392 -> V_321 = V_321 ;
V_37 -> V_38 . V_392 -> V_323 = V_396 ;
V_37 -> V_38 . V_392 -> F_298 = V_397 ;
return V_85 ;
}
static int F_321 ( struct V_36 * V_37 )
{
struct V_273 * V_401 = & V_37 -> V_38 . V_330 ;
V_401 -> V_321 = V_321 ;
V_401 -> V_323 = V_396 ;
V_401 -> F_298 = V_397 ;
if ( ! F_317 ( V_37 ) ) {
V_401 -> V_353 = false ;
V_401 -> V_211 = 0 ;
V_401 -> V_350 = F_273 ;
} else if ( F_318 ( V_37 ) ) {
V_401 -> V_353 = F_22 ( V_37 ) ;
V_401 -> V_211 = V_198 ;
F_305 ( V_37 , V_401 ) ;
V_401 -> V_350 = V_402 ;
} else if ( F_163 ( V_37 ) ) {
V_401 -> V_353 = F_22 ( V_37 ) ;
V_401 -> V_211 = V_225 ;
F_305 ( V_37 , V_401 ) ;
V_401 -> V_350 = V_402 ;
} else {
V_401 -> V_353 = false ;
V_401 -> V_211 = V_212 ;
F_305 ( V_37 , V_401 ) ;
V_401 -> V_350 = V_403 ;
}
F_308 ( V_37 , V_401 ) ;
F_311 ( V_37 , V_401 ) ;
return 0 ;
}
static int F_322 ( struct V_36 * V_37 )
{
if ( F_323 ( V_37 ) )
return F_321 ( V_37 ) ;
else if ( V_264 )
return F_316 ( V_37 ) ;
else
return F_320 ( V_37 ) ;
}
static void F_324 ( struct V_36 * V_37 )
{
ASSERT ( V_37 ) ;
if ( F_262 ( V_37 -> V_38 . V_191 . V_223 ) )
V_37 -> V_38 . V_191 . free ( V_37 ) ;
}
int F_325 ( struct V_36 * V_37 )
{
F_324 ( V_37 ) ;
return F_322 ( V_37 ) ;
}
int F_326 ( struct V_36 * V_37 )
{
int V_85 ;
V_85 = F_70 ( V_37 ) ;
if ( V_85 )
goto V_89;
V_85 = F_268 ( V_37 ) ;
F_271 ( V_37 ) ;
if ( V_85 )
goto V_89;
V_37 -> V_38 . V_191 . V_394 ( V_37 , V_37 -> V_38 . V_191 . V_223 ) ;
V_89:
return V_85 ;
}
void F_327 ( struct V_36 * V_37 )
{
F_225 ( V_37 ) ;
}
static void F_328 ( struct V_36 * V_37 ,
struct V_52 * V_53 , T_1 * V_10 ,
const void * V_404 )
{
if ( V_53 -> V_95 . V_45 != V_46 ) {
++ V_37 -> V_11 -> V_136 . V_405 ;
return;
}
++ V_37 -> V_11 -> V_136 . V_406 ;
V_37 -> V_38 . V_191 . V_352 ( V_37 , V_53 , V_10 , V_404 ) ;
}
static bool F_329 ( T_1 V_407 , T_1 V_404 )
{
if ( ! F_23 ( V_407 ) )
return false ;
if ( ! F_23 ( V_404 ) )
return true ;
if ( ( V_407 ^ V_404 ) & V_47 )
return true ;
V_407 ^= V_408 ;
V_404 ^= V_408 ;
return ( V_407 & ~ V_404 & V_409 ) != 0 ;
}
static void F_330 ( struct V_36 * V_37 , bool V_410 ,
bool V_411 , bool V_412 )
{
if ( V_410 )
return;
if ( V_411 )
F_108 ( V_37 -> V_11 ) ;
else if ( V_412 )
F_165 ( V_37 ) ;
}
static T_1 F_331 ( struct V_36 * V_37 , T_9 * V_346 ,
const T_8 * V_404 , int * V_413 )
{
T_1 V_414 ;
int V_85 ;
if ( F_163 ( V_37 ) && * V_413 == 4 ) {
* V_346 &= ~ ( T_9 ) 7 ;
* V_413 = 8 ;
V_85 = F_332 ( V_37 -> V_11 , * V_346 , & V_414 , 8 ) ;
if ( V_85 )
V_414 = 0 ;
V_404 = ( const T_8 * ) & V_414 ;
}
switch ( * V_413 ) {
case 4 :
V_414 = * ( const T_4 * ) V_404 ;
break;
case 8 :
V_414 = * ( const T_1 * ) V_404 ;
break;
default:
V_414 = 0 ;
break;
}
return V_414 ;
}
static bool F_333 ( struct V_52 * V_53 )
{
if ( V_53 -> V_95 . V_45 == V_46 )
return false ;
return ++ V_53 -> V_203 >= 3 ;
}
static bool F_334 ( struct V_52 * V_53 , T_9 V_346 ,
int V_413 )
{
unsigned V_415 , V_416 , V_417 ;
F_213 ( L_26 ,
V_346 , V_413 , V_53 -> V_95 . V_215 ) ;
V_415 = F_335 ( V_346 ) ;
V_416 = V_53 -> V_95 . V_190 ? 8 : 4 ;
if ( ! ( V_415 & ( V_416 - 1 ) ) && V_413 == 1 )
return false ;
V_417 = ( V_415 ^ ( V_415 + V_413 - 1 ) ) & ~ ( V_416 - 1 ) ;
V_417 |= V_413 < 4 ;
return V_417 ;
}
static T_1 * F_336 ( struct V_52 * V_53 , T_9 V_346 , int * V_418 )
{
unsigned V_419 , V_207 ;
T_1 * V_10 ;
int V_45 ;
V_419 = F_335 ( V_346 ) ;
V_45 = V_53 -> V_95 . V_45 ;
* V_418 = 1 ;
if ( ! V_53 -> V_95 . V_190 ) {
V_419 <<= 1 ;
if ( V_45 == V_212 ) {
V_419 &= ~ 7 ;
V_419 <<= 1 ;
* V_418 = 2 ;
}
V_207 = V_419 >> V_19 ;
V_419 &= ~ V_20 ;
if ( V_207 != V_53 -> V_95 . V_207 )
return NULL ;
}
V_10 = & V_53 -> V_132 [ V_419 / sizeof( * V_10 ) ] ;
return V_10 ;
}
void F_337 ( struct V_36 * V_37 , T_9 V_346 ,
const T_8 * V_404 , int V_413 )
{
T_2 V_15 = V_346 >> V_19 ;
union V_206 V_4 = { . V_215 = 0 } ;
struct V_52 * V_53 ;
F_167 ( V_188 ) ;
T_1 V_420 , V_414 , * V_10 ;
int V_421 ;
bool V_411 , V_412 , V_410 ;
if ( ! F_35 ( V_37 -> V_11 -> V_38 . V_110 ) )
return;
V_410 = V_411 = V_412 = false ;
F_213 ( L_27 , V_163 , V_346 , V_413 ) ;
V_414 = F_331 ( V_37 , & V_346 , V_404 , & V_413 ) ;
F_70 ( V_37 ) ;
F_210 ( & V_37 -> V_11 -> V_201 ) ;
++ V_37 -> V_11 -> V_136 . V_422 ;
F_169 ( V_37 , V_423 ) ;
V_4 . V_399 = V_4 . V_190 = V_4 . V_398 = 1 ;
F_173 (vcpu->kvm, sp, gfn) {
if ( F_334 ( V_53 , V_346 , V_413 ) ||
F_333 ( V_53 ) ) {
V_410 |= ! ! F_164 ( V_37 -> V_11 , V_53 ,
& V_188 ) ;
++ V_37 -> V_11 -> V_136 . V_424 ;
continue;
}
V_10 = F_336 ( V_53 , V_346 , & V_421 ) ;
if ( ! V_10 )
continue;
V_412 = true ;
while ( V_421 -- ) {
V_420 = * V_10 ;
F_197 ( V_37 -> V_11 , V_53 , V_10 ) ;
if ( V_414 &&
! ( ( V_53 -> V_95 . V_215 ^ V_37 -> V_38 . V_191 . V_209 . V_215 )
& V_4 . V_215 ) && F_100 ( V_37 ) )
F_328 ( V_37 , V_53 , V_10 , & V_414 ) ;
if ( F_329 ( V_420 , * V_10 ) )
V_411 = true ;
++ V_10 ;
}
}
F_330 ( V_37 , V_410 , V_411 , V_412 ) ;
F_168 ( V_37 -> V_11 , & V_188 ) ;
F_169 ( V_37 , V_425 ) ;
F_211 ( & V_37 -> V_11 -> V_201 ) ;
}
int F_338 ( struct V_36 * V_37 , T_7 V_176 )
{
T_9 V_346 ;
int V_85 ;
if ( V_37 -> V_38 . V_191 . V_210 )
return 0 ;
V_346 = F_339 ( V_37 , V_176 , NULL ) ;
V_85 = F_212 ( V_37 -> V_11 , V_346 >> V_19 ) ;
return V_85 ;
}
static void F_261 ( struct V_36 * V_37 )
{
F_167 ( V_188 ) ;
if ( F_18 ( F_340 ( V_37 -> V_11 ) >= V_426 ) )
return;
while ( F_340 ( V_37 -> V_11 ) < V_427 ) {
if ( ! F_207 ( V_37 -> V_11 , & V_188 ) )
break;
++ V_37 -> V_11 -> V_136 . V_428 ;
}
F_168 ( V_37 -> V_11 , & V_188 ) ;
}
static bool F_341 ( struct V_36 * V_37 , T_7 V_221 )
{
if ( V_37 -> V_38 . V_191 . V_210 || F_323 ( V_37 ) )
return F_275 ( V_37 , V_221 ) ;
return F_276 ( V_37 , V_221 ) ;
}
int F_342 ( struct V_36 * V_37 , T_7 V_429 , T_4 V_307 ,
void * V_430 , int V_431 )
{
int V_85 , V_432 = V_433 ;
enum V_434 V_435 ;
V_85 = V_37 -> V_38 . V_191 . V_349 ( V_37 , V_429 , V_307 , false ) ;
if ( V_85 < 0 )
goto V_89;
if ( ! V_85 ) {
V_85 = 1 ;
goto V_89;
}
if ( F_341 ( V_37 , V_429 ) )
V_432 = 0 ;
V_435 = F_343 ( V_37 , V_429 , V_432 , V_430 , V_431 ) ;
switch ( V_435 ) {
case V_436 :
return 1 ;
case V_437 :
++ V_37 -> V_136 . V_438 ;
case V_439 :
return 0 ;
default:
F_95 () ;
}
V_89:
return V_85 ;
}
void F_344 ( struct V_36 * V_37 , T_7 V_176 )
{
V_37 -> V_38 . V_191 . V_351 ( V_37 , V_176 ) ;
F_165 ( V_37 ) ;
++ V_37 -> V_136 . V_351 ;
}
void F_345 ( void )
{
V_264 = true ;
}
void F_346 ( void )
{
V_264 = false ;
}
static void F_347 ( struct V_36 * V_37 )
{
F_69 ( ( unsigned long ) V_37 -> V_38 . V_191 . V_226 ) ;
if ( V_37 -> V_38 . V_191 . V_324 != NULL )
F_69 ( ( unsigned long ) V_37 -> V_38 . V_191 . V_324 ) ;
}
static int F_348 ( struct V_36 * V_37 )
{
struct V_84 * V_84 ;
int V_106 ;
ASSERT ( V_37 ) ;
V_84 = F_349 ( V_81 | V_440 ) ;
if ( ! V_84 )
return - V_82 ;
V_37 -> V_38 . V_191 . V_226 = F_350 ( V_84 ) ;
for ( V_106 = 0 ; V_106 < 4 ; ++ V_106 )
V_37 -> V_38 . V_191 . V_226 [ V_106 ] = V_316 ;
return 0 ;
}
int F_351 ( struct V_36 * V_37 )
{
ASSERT ( V_37 ) ;
V_37 -> V_38 . V_392 = & V_37 -> V_38 . V_191 ;
V_37 -> V_38 . V_191 . V_223 = V_316 ;
V_37 -> V_38 . V_191 . V_331 = V_331 ;
V_37 -> V_38 . V_330 . V_331 = V_441 ;
return F_348 ( V_37 ) ;
}
int F_352 ( struct V_36 * V_37 )
{
ASSERT ( V_37 ) ;
ASSERT ( ! F_262 ( V_37 -> V_38 . V_191 . V_223 ) ) ;
return F_322 ( V_37 ) ;
}
void F_353 ( struct V_11 * V_11 , int V_101 )
{
struct V_100 * V_151 ;
T_2 V_442 ;
int V_106 ;
V_151 = F_354 ( V_11 -> V_443 , V_101 ) ;
V_442 = V_151 -> V_103 + V_151 -> V_157 - 1 ;
F_210 ( & V_11 -> V_201 ) ;
for ( V_106 = V_46 ;
V_106 < V_46 + V_108 ; ++ V_106 ) {
unsigned long * V_131 ;
unsigned long V_444 , V_94 ;
V_131 = V_151 -> V_38 . V_130 [ V_106 - V_46 ] ;
V_444 = F_79 ( V_442 , V_151 -> V_103 , V_106 ) ;
for ( V_94 = 0 ; V_94 <= V_444 ; ++ V_94 , ++ V_131 ) {
if ( * V_131 )
F_110 ( V_11 , V_131 , false ) ;
if ( F_355 () || F_356 ( & V_11 -> V_201 ) ) {
F_108 ( V_11 ) ;
F_179 ( & V_11 -> V_201 ) ;
}
}
}
F_108 ( V_11 ) ;
F_211 ( & V_11 -> V_201 ) ;
}
static void F_357 ( struct V_11 * V_11 )
{
struct V_52 * V_53 , * V_445 ;
int V_446 = 0 ;
V_447:
F_358 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_69 ;
if ( ! F_183 ( V_11 , V_53 ) )
break;
if ( V_53 -> V_95 . V_230 )
continue;
if ( V_446 >= V_448 &&
F_179 ( & V_11 -> V_201 ) ) {
V_446 = 0 ;
goto V_447;
}
V_69 = F_164 ( V_11 , V_53 ,
& V_11 -> V_38 . V_449 ) ;
V_446 += V_69 ;
if ( V_69 )
goto V_447;
}
F_168 ( V_11 , & V_11 -> V_38 . V_449 ) ;
}
void F_359 ( struct V_11 * V_11 )
{
F_210 ( & V_11 -> V_201 ) ;
F_360 ( V_11 ) ;
V_11 -> V_38 . V_204 ++ ;
F_204 ( V_11 ) ;
F_357 ( V_11 ) ;
F_211 ( & V_11 -> V_201 ) ;
}
static bool F_361 ( struct V_11 * V_11 )
{
return F_14 ( ! F_362 ( & V_11 -> V_38 . V_449 ) ) ;
}
void F_363 ( struct V_11 * V_11 )
{
if ( F_14 ( F_5 ( V_11 ) >= ( V_5 - 1 ) ) ) {
F_364 ( V_450 L_28 ) ;
F_359 ( V_11 ) ;
}
}
static int F_365 ( struct V_451 * V_452 , struct V_453 * V_454 )
{
struct V_11 * V_11 ;
int V_455 = V_454 -> V_455 ;
if ( V_455 == 0 )
goto V_89;
F_366 ( & V_456 ) ;
F_367 (kvm, &vm_list, vm_list) {
int V_102 ;
F_167 ( V_188 ) ;
if ( ! V_455 -- )
break;
if ( ! V_11 -> V_38 . V_165 &&
! F_361 ( V_11 ) )
continue;
V_102 = F_368 ( & V_11 -> V_457 ) ;
F_210 ( & V_11 -> V_201 ) ;
if ( F_361 ( V_11 ) ) {
F_168 ( V_11 ,
& V_11 -> V_38 . V_449 ) ;
goto V_458;
}
F_207 ( V_11 , & V_188 ) ;
F_168 ( V_11 , & V_188 ) ;
V_458:
F_211 ( & V_11 -> V_201 ) ;
F_369 ( & V_11 -> V_457 , V_102 ) ;
F_370 ( & V_11 -> V_459 , & V_459 ) ;
break;
}
F_371 ( & V_456 ) ;
V_89:
return F_372 ( & V_166 ) ;
}
static void F_373 ( void )
{
if ( V_87 )
F_374 ( V_87 ) ;
if ( V_91 )
F_374 ( V_91 ) ;
}
int F_375 ( void )
{
V_87 = F_376 ( L_29 ,
sizeof( struct V_93 ) ,
0 , 0 , NULL ) ;
if ( ! V_87 )
goto V_460;
V_91 = F_376 ( L_30 ,
sizeof( struct V_52 ) ,
0 , 0 , NULL ) ;
if ( ! V_91 )
goto V_460;
if ( F_377 ( & V_166 , 0 ) )
goto V_460;
F_378 ( & V_461 ) ;
return 0 ;
V_460:
F_373 () ;
return - V_82 ;
}
unsigned int F_379 ( struct V_11 * V_11 )
{
unsigned int V_462 ;
unsigned int V_463 = 0 ;
struct F_6 * V_150 ;
struct V_100 * V_151 ;
V_150 = F_6 ( V_11 ) ;
F_121 (memslot, slots)
V_463 += V_151 -> V_157 ;
V_462 = V_463 * V_464 / 1000 ;
V_462 = F_122 ( V_462 ,
( unsigned int ) V_465 ) ;
return V_462 ;
}
int F_380 ( struct V_36 * V_37 , T_1 V_221 , T_1 V_123 [ 4 ] )
{
struct V_219 V_220 ;
T_1 V_10 ;
int V_466 = 0 ;
F_55 ( V_37 ) ;
F_256 (vcpu, addr, iterator, spte) {
V_123 [ V_220 . V_45 - 1 ] = V_10 ;
V_466 ++ ;
if ( ! F_23 ( V_10 ) )
break;
}
F_58 ( V_37 ) ;
return V_466 ;
}
void F_381 ( struct V_36 * V_37 )
{
ASSERT ( V_37 ) ;
F_324 ( V_37 ) ;
F_347 ( V_37 ) ;
F_71 ( V_37 ) ;
}
void F_382 ( void )
{
F_373 () ;
F_383 ( & V_166 ) ;
F_384 ( & V_461 ) ;
F_170 () ;
}
