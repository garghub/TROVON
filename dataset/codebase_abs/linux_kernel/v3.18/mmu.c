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
return F_6 ( V_11 ) -> V_12 & V_13 ;
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
static int F_21 ( struct V_34 * V_35 )
{
return V_35 -> V_36 . V_37 & V_38 ;
}
static int F_22 ( T_1 V_39 )
{
return V_39 & V_40 && ! F_10 ( V_39 ) ;
}
static int F_23 ( T_1 V_39 )
{
return V_39 & V_41 ;
}
static int F_24 ( T_1 V_39 )
{
return F_22 ( V_39 ) ;
}
static int F_25 ( T_1 V_39 , int V_42 )
{
if ( V_42 == V_43 )
return 1 ;
if ( F_23 ( V_39 ) )
return 1 ;
return 0 ;
}
static T_3 F_26 ( T_1 V_39 )
{
return ( V_39 & V_44 ) >> V_19 ;
}
static T_2 F_27 ( T_4 V_45 )
{
int V_46 = 32 - V_47 - V_19 ;
return ( V_45 & V_48 ) << V_46 ;
}
static void F_28 ( T_1 * V_14 , T_1 V_10 )
{
* V_14 = V_10 ;
}
static void F_29 ( T_1 * V_14 , T_1 V_10 )
{
* V_14 = V_10 ;
}
static T_1 F_30 ( T_1 * V_14 , T_1 V_10 )
{
return F_31 ( V_14 , V_10 ) ;
}
static T_1 F_32 ( T_1 * V_14 )
{
return F_33 ( * V_14 ) ;
}
static bool F_34 ( T_1 V_10 )
{
return V_10 == 0ull ;
}
static void F_35 ( T_1 * V_14 , T_1 V_10 )
{
struct V_49 * V_50 = F_36 ( F_37 ( V_14 ) ) ;
if ( F_22 ( V_10 ) )
return;
F_38 () ;
V_50 -> V_51 ++ ;
}
static void F_28 ( T_1 * V_14 , T_1 V_10 )
{
union V_52 * V_53 , V_54 ;
V_53 = (union V_52 * ) V_14 ;
V_54 = (union V_52 ) V_10 ;
V_53 -> V_55 = V_54 . V_55 ;
F_38 () ;
V_53 -> V_56 = V_54 . V_56 ;
}
static void F_29 ( T_1 * V_14 , T_1 V_10 )
{
union V_52 * V_53 , V_54 ;
V_53 = (union V_52 * ) V_14 ;
V_54 = (union V_52 ) V_10 ;
V_53 -> V_56 = V_54 . V_56 ;
F_38 () ;
V_53 -> V_55 = V_54 . V_55 ;
F_35 ( V_14 , V_10 ) ;
}
static T_1 F_30 ( T_1 * V_14 , T_1 V_10 )
{
union V_52 * V_53 , V_54 , V_57 ;
V_53 = (union V_52 * ) V_14 ;
V_54 = (union V_52 ) V_10 ;
V_57 . V_56 = F_31 ( & V_53 -> V_56 , V_54 . V_56 ) ;
V_57 . V_55 = V_53 -> V_55 ;
V_53 -> V_55 = V_54 . V_55 ;
F_35 ( V_14 , V_10 ) ;
return V_57 . V_10 ;
}
static T_1 F_32 ( T_1 * V_14 )
{
struct V_49 * V_50 = F_36 ( F_37 ( V_14 ) ) ;
union V_52 V_10 , * V_57 = (union V_52 * ) V_14 ;
int V_58 ;
V_59:
V_58 = V_50 -> V_51 ;
F_39 () ;
V_10 . V_56 = V_57 -> V_56 ;
F_39 () ;
V_10 . V_55 = V_57 -> V_55 ;
F_39 () ;
if ( F_14 ( V_10 . V_56 != V_57 -> V_56 ||
V_58 != V_50 -> V_51 ) )
goto V_59;
return V_10 . V_10 ;
}
static bool F_34 ( T_1 V_10 )
{
union V_52 V_54 = (union V_52 ) V_10 ;
T_4 V_60 = V_2 >> 32 ;
if ( V_10 == 0ull )
return true ;
if ( V_54 . V_56 == 0ull &&
( V_54 . V_55 & V_60 ) == V_60 )
return true ;
return false ;
}
static bool F_40 ( T_1 V_10 )
{
return ( V_10 & ( V_61 | V_62 ) ) ==
( V_61 | V_62 ) ;
}
static bool F_41 ( T_1 V_10 )
{
if ( F_40 ( V_10 ) )
return true ;
if ( ! V_30 )
return false ;
if ( ! F_22 ( V_10 ) )
return false ;
if ( ( V_10 & V_30 ) &&
( ! F_42 ( V_10 ) || ( V_10 & V_31 ) ) )
return false ;
return true ;
}
static bool F_43 ( T_1 V_63 , T_1 V_64 , T_1 V_65 )
{
return ( V_63 & V_65 ) && ! ( V_64 & V_65 ) ;
}
static void F_9 ( T_1 * V_14 , T_1 V_64 )
{
F_3 ( F_22 ( * V_14 ) ) ;
F_28 ( V_14 , V_64 ) ;
}
static bool F_44 ( T_1 * V_14 , T_1 V_64 )
{
T_1 V_63 = * V_14 ;
bool V_66 = false ;
F_3 ( ! F_24 ( V_64 ) ) ;
if ( ! F_22 ( V_63 ) ) {
F_9 ( V_14 , V_64 ) ;
return V_66 ;
}
if ( ! F_41 ( V_63 ) )
F_29 ( V_14 , V_64 ) ;
else
V_63 = F_30 ( V_14 , V_64 ) ;
if ( F_40 ( V_63 ) &&
! F_42 ( V_64 ) )
V_66 = true ;
if ( ! V_30 )
return V_66 ;
if ( F_43 ( V_63 , V_64 , V_30 ) )
F_45 ( F_26 ( V_63 ) ) ;
if ( F_43 ( V_63 , V_64 , V_31 ) )
F_46 ( F_26 ( V_63 ) ) ;
return V_66 ;
}
static int F_47 ( T_1 * V_14 )
{
T_3 V_21 ;
T_1 V_63 = * V_14 ;
if ( ! F_41 ( V_63 ) )
F_29 ( V_14 , 0ull ) ;
else
V_63 = F_30 ( V_14 , 0ull ) ;
if ( ! F_24 ( V_63 ) )
return 0 ;
V_21 = F_26 ( V_63 ) ;
F_3 ( ! F_48 ( V_21 ) && ! F_49 ( F_50 ( V_21 ) ) ) ;
if ( ! V_30 || V_63 & V_30 )
F_45 ( V_21 ) ;
if ( ! V_31 || ( V_63 & V_31 ) )
F_46 ( V_21 ) ;
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
static void F_53 ( struct V_34 * V_35 )
{
F_54 () ;
V_35 -> V_67 = V_68 ;
F_55 () ;
}
static void F_56 ( struct V_34 * V_35 )
{
F_55 () ;
V_35 -> V_67 = V_69 ;
F_57 () ;
}
static int F_58 ( struct V_70 * V_71 ,
struct V_72 * V_73 , int V_74 )
{
void * V_75 ;
if ( V_71 -> V_76 >= V_74 )
return 0 ;
while ( V_71 -> V_76 < F_59 ( V_71 -> V_77 ) ) {
V_75 = F_60 ( V_73 , V_78 ) ;
if ( ! V_75 )
return - V_79 ;
V_71 -> V_77 [ V_71 -> V_76 ++ ] = V_75 ;
}
return 0 ;
}
static int F_61 ( struct V_70 * V_71 )
{
return V_71 -> V_76 ;
}
static void F_62 ( struct V_70 * V_80 ,
struct V_72 * V_71 )
{
while ( V_80 -> V_76 )
F_63 ( V_71 , V_80 -> V_77 [ -- V_80 -> V_76 ] ) ;
}
static int F_64 ( struct V_70 * V_71 ,
int V_74 )
{
void * V_81 ;
if ( V_71 -> V_76 >= V_74 )
return 0 ;
while ( V_71 -> V_76 < F_59 ( V_71 -> V_77 ) ) {
V_81 = ( void * ) F_65 ( V_78 ) ;
if ( ! V_81 )
return - V_79 ;
V_71 -> V_77 [ V_71 -> V_76 ++ ] = V_81 ;
}
return 0 ;
}
static void F_66 ( struct V_70 * V_80 )
{
while ( V_80 -> V_76 )
F_67 ( ( unsigned long ) V_80 -> V_77 [ -- V_80 -> V_76 ] ) ;
}
static int F_68 ( struct V_34 * V_35 )
{
int V_82 ;
V_82 = F_58 ( & V_35 -> V_36 . V_83 ,
V_84 , 8 + V_85 ) ;
if ( V_82 )
goto V_86;
V_82 = F_64 ( & V_35 -> V_36 . V_87 , 8 ) ;
if ( V_82 )
goto V_86;
V_82 = F_58 ( & V_35 -> V_36 . V_88 ,
V_88 , 4 ) ;
V_86:
return V_82 ;
}
static void F_69 ( struct V_34 * V_35 )
{
F_62 ( & V_35 -> V_36 . V_83 ,
V_84 ) ;
F_66 ( & V_35 -> V_36 . V_87 ) ;
F_62 ( & V_35 -> V_36 . V_88 ,
V_88 ) ;
}
static void * F_70 ( struct V_70 * V_80 )
{
void * V_89 ;
F_71 ( ! V_80 -> V_76 ) ;
V_89 = V_80 -> V_77 [ -- V_80 -> V_76 ] ;
return V_89 ;
}
static struct V_90 * F_72 ( struct V_34 * V_35 )
{
return F_70 ( & V_35 -> V_36 . V_83 ) ;
}
static void F_73 ( struct V_90 * V_90 )
{
F_63 ( V_84 , V_90 ) ;
}
static T_2 F_74 ( struct V_49 * V_50 , int V_91 )
{
if ( ! V_50 -> V_92 . V_93 )
return V_50 -> V_94 [ V_91 ] ;
return V_50 -> V_15 + ( V_91 << ( ( V_50 -> V_92 . V_42 - 1 ) * V_95 ) ) ;
}
static void F_75 ( struct V_49 * V_50 , int V_91 , T_2 V_15 )
{
if ( V_50 -> V_92 . V_93 )
F_71 ( V_15 != F_74 ( V_50 , V_91 ) ) ;
else
V_50 -> V_94 [ V_91 ] = V_15 ;
}
static struct V_96 * F_76 ( T_2 V_15 ,
struct V_97 * V_98 ,
int V_42 )
{
unsigned long V_99 ;
V_99 = F_77 ( V_15 , V_98 -> V_100 , V_42 ) ;
return & V_98 -> V_36 . V_101 [ V_42 - 2 ] [ V_99 ] ;
}
static void F_78 ( struct V_11 * V_11 , T_2 V_15 )
{
struct V_97 * V_98 ;
struct V_96 * V_102 ;
int V_103 ;
V_98 = F_79 ( V_11 , V_15 ) ;
for ( V_103 = V_104 ;
V_103 < V_43 + V_105 ; ++ V_103 ) {
V_102 = F_76 ( V_15 , V_98 , V_103 ) ;
V_102 -> V_106 += 1 ;
}
V_11 -> V_36 . V_107 ++ ;
}
static void F_80 ( struct V_11 * V_11 , T_2 V_15 )
{
struct V_97 * V_98 ;
struct V_96 * V_102 ;
int V_103 ;
V_98 = F_79 ( V_11 , V_15 ) ;
for ( V_103 = V_104 ;
V_103 < V_43 + V_105 ; ++ V_103 ) {
V_102 = F_76 ( V_15 , V_98 , V_103 ) ;
V_102 -> V_106 -= 1 ;
F_3 ( V_102 -> V_106 < 0 ) ;
}
V_11 -> V_36 . V_107 -- ;
}
static int F_81 ( struct V_11 * V_11 ,
T_2 V_15 ,
int V_42 )
{
struct V_97 * V_98 ;
struct V_96 * V_102 ;
V_98 = F_79 ( V_11 , V_15 ) ;
if ( V_98 ) {
V_102 = F_76 ( V_15 , V_98 , V_42 ) ;
return V_102 -> V_106 ;
}
return 1 ;
}
static int F_82 ( struct V_11 * V_11 , T_2 V_15 )
{
unsigned long V_108 ;
int V_103 , V_66 = 0 ;
V_108 = F_83 ( V_11 , V_15 ) ;
for ( V_103 = V_43 ;
V_103 < ( V_43 + V_105 ) ; ++ V_103 ) {
if ( V_108 >= F_84 ( V_103 ) )
V_66 = V_103 ;
else
break;
}
return V_66 ;
}
static struct V_97 *
F_85 ( struct V_34 * V_35 , T_2 V_15 ,
bool V_109 )
{
struct V_97 * V_98 ;
V_98 = F_79 ( V_35 -> V_11 , V_15 ) ;
if ( ! V_98 || V_98 -> V_110 & V_111 ||
( V_109 && V_98 -> V_112 ) )
V_98 = NULL ;
return V_98 ;
}
static bool F_86 ( struct V_34 * V_35 , T_2 V_113 )
{
return ! F_85 ( V_35 , V_113 , true ) ;
}
static int F_87 ( struct V_34 * V_35 , T_2 V_113 )
{
int V_114 , V_42 , V_115 ;
V_114 = F_82 ( V_35 -> V_11 , V_113 ) ;
if ( V_114 == V_43 )
return V_114 ;
V_115 = V_74 ( V_116 -> V_117 () , V_114 ) ;
for ( V_42 = V_104 ; V_42 <= V_115 ; ++ V_42 )
if ( F_81 ( V_35 -> V_11 , V_113 , V_42 ) )
break;
return V_42 - 1 ;
}
static int F_88 ( struct V_34 * V_35 , T_1 * V_10 ,
unsigned long * V_118 )
{
struct V_90 * V_119 ;
int V_103 , V_58 = 0 ;
if ( ! * V_118 ) {
F_89 ( L_1 , V_10 , * V_10 ) ;
* V_118 = ( unsigned long ) V_10 ;
} else if ( ! ( * V_118 & 1 ) ) {
F_89 ( L_2 , V_10 , * V_10 ) ;
V_119 = F_72 ( V_35 ) ;
V_119 -> V_120 [ 0 ] = ( T_1 * ) * V_118 ;
V_119 -> V_120 [ 1 ] = V_10 ;
* V_118 = ( unsigned long ) V_119 | 1 ;
++ V_58 ;
} else {
F_89 ( L_3 , V_10 , * V_10 ) ;
V_119 = (struct V_90 * ) ( * V_118 & ~ 1ul ) ;
while ( V_119 -> V_120 [ V_121 - 1 ] && V_119 -> V_122 ) {
V_119 = V_119 -> V_122 ;
V_58 += V_121 ;
}
if ( V_119 -> V_120 [ V_121 - 1 ] ) {
V_119 -> V_122 = F_72 ( V_35 ) ;
V_119 = V_119 -> V_122 ;
}
for ( V_103 = 0 ; V_119 -> V_120 [ V_103 ] ; ++ V_103 )
++ V_58 ;
V_119 -> V_120 [ V_103 ] = V_10 ;
}
return V_58 ;
}
static void
F_90 ( unsigned long * V_118 , struct V_90 * V_119 ,
int V_103 , struct V_90 * V_123 )
{
int V_124 ;
for ( V_124 = V_121 - 1 ; ! V_119 -> V_120 [ V_124 ] && V_124 > V_103 ; -- V_124 )
;
V_119 -> V_120 [ V_103 ] = V_119 -> V_120 [ V_124 ] ;
V_119 -> V_120 [ V_124 ] = NULL ;
if ( V_124 != 0 )
return;
if ( ! V_123 && ! V_119 -> V_122 )
* V_118 = ( unsigned long ) V_119 -> V_120 [ 0 ] ;
else
if ( V_123 )
V_123 -> V_122 = V_119 -> V_122 ;
else
* V_118 = ( unsigned long ) V_119 -> V_122 | 1 ;
F_73 ( V_119 ) ;
}
static void F_91 ( T_1 * V_10 , unsigned long * V_118 )
{
struct V_90 * V_119 ;
struct V_90 * V_123 ;
int V_103 ;
if ( ! * V_118 ) {
F_92 ( V_125 L_4 , V_10 ) ;
F_93 () ;
} else if ( ! ( * V_118 & 1 ) ) {
F_89 ( L_5 , V_10 ) ;
if ( ( T_1 * ) * V_118 != V_10 ) {
F_92 ( V_125 L_6 , V_10 ) ;
F_93 () ;
}
* V_118 = 0 ;
} else {
F_89 ( L_7 , V_10 ) ;
V_119 = (struct V_90 * ) ( * V_118 & ~ 1ul ) ;
V_123 = NULL ;
while ( V_119 ) {
for ( V_103 = 0 ; V_103 < V_121 && V_119 -> V_120 [ V_103 ] ; ++ V_103 )
if ( V_119 -> V_120 [ V_103 ] == V_10 ) {
F_90 ( V_118 ,
V_119 , V_103 ,
V_123 ) ;
return;
}
V_123 = V_119 ;
V_119 = V_119 -> V_122 ;
}
F_94 ( L_8 , V_10 ) ;
F_93 () ;
}
}
static void F_95 ( unsigned long * V_118 , T_5 V_126 )
{
struct V_90 * V_119 ;
int V_103 ;
if ( ! * V_118 )
return;
if ( ! ( * V_118 & 1 ) )
return V_126 ( ( T_1 * ) * V_118 ) ;
V_119 = (struct V_90 * ) ( * V_118 & ~ 1ul ) ;
while ( V_119 ) {
for ( V_103 = 0 ; V_103 < V_121 && V_119 -> V_120 [ V_103 ] ; ++ V_103 )
V_126 ( V_119 -> V_120 [ V_103 ] ) ;
V_119 = V_119 -> V_122 ;
}
}
static unsigned long * F_96 ( T_2 V_15 , int V_42 ,
struct V_97 * V_98 )
{
unsigned long V_99 ;
V_99 = F_77 ( V_15 , V_98 -> V_100 , V_42 ) ;
return & V_98 -> V_36 . V_127 [ V_42 - V_43 ] [ V_99 ] ;
}
static unsigned long * F_97 ( struct V_11 * V_11 , T_2 V_15 , int V_42 )
{
struct V_97 * V_98 ;
V_98 = F_79 ( V_11 , V_15 ) ;
return F_96 ( V_15 , V_42 , V_98 ) ;
}
static bool F_98 ( struct V_34 * V_35 )
{
struct V_70 * V_71 ;
V_71 = & V_35 -> V_36 . V_83 ;
return F_61 ( V_71 ) ;
}
static int F_99 ( struct V_34 * V_35 , T_1 * V_10 , T_2 V_15 )
{
struct V_49 * V_50 ;
unsigned long * V_128 ;
V_50 = F_36 ( F_37 ( V_10 ) ) ;
F_75 ( V_50 , V_10 - V_50 -> V_129 , V_15 ) ;
V_128 = F_97 ( V_35 -> V_11 , V_15 , V_50 -> V_92 . V_42 ) ;
return F_88 ( V_35 , V_10 , V_128 ) ;
}
static void F_100 ( struct V_11 * V_11 , T_1 * V_10 )
{
struct V_49 * V_50 ;
T_2 V_15 ;
unsigned long * V_128 ;
V_50 = F_36 ( F_37 ( V_10 ) ) ;
V_15 = F_74 ( V_50 , V_10 - V_50 -> V_129 ) ;
V_128 = F_97 ( V_11 , V_15 , V_50 -> V_92 . V_42 ) ;
F_91 ( V_10 , V_128 ) ;
}
static T_1 * F_101 ( unsigned long V_127 , struct V_130 * V_131 )
{
if ( ! V_127 )
return NULL ;
if ( ! ( V_127 & 1 ) ) {
V_131 -> V_119 = NULL ;
return ( T_1 * ) V_127 ;
}
V_131 -> V_119 = (struct V_90 * ) ( V_127 & ~ 1ul ) ;
V_131 -> V_132 = 0 ;
return V_131 -> V_119 -> V_120 [ V_131 -> V_132 ] ;
}
static T_1 * F_102 ( struct V_130 * V_131 )
{
if ( V_131 -> V_119 ) {
if ( V_131 -> V_132 < V_121 - 1 ) {
T_1 * V_14 ;
++ V_131 -> V_132 ;
V_14 = V_131 -> V_119 -> V_120 [ V_131 -> V_132 ] ;
if ( V_14 )
return V_14 ;
}
V_131 -> V_119 = V_131 -> V_119 -> V_122 ;
if ( V_131 -> V_119 ) {
V_131 -> V_132 = 0 ;
return V_131 -> V_119 -> V_120 [ V_131 -> V_132 ] ;
}
}
return NULL ;
}
static void F_103 ( struct V_11 * V_11 , T_1 * V_14 )
{
if ( F_47 ( V_14 ) )
F_100 ( V_11 , V_14 ) ;
}
static bool F_104 ( struct V_11 * V_11 , T_1 * V_14 )
{
if ( F_23 ( * V_14 ) ) {
F_3 ( F_36 ( F_37 ( V_14 ) ) -> V_92 . V_42 ==
V_43 ) ;
F_103 ( V_11 , V_14 ) ;
-- V_11 -> V_133 . V_134 ;
return true ;
}
return false ;
}
static void F_105 ( struct V_34 * V_35 , T_1 * V_14 )
{
if ( F_104 ( V_35 -> V_11 , V_14 ) )
F_106 ( V_35 -> V_11 ) ;
}
static bool F_107 ( struct V_11 * V_11 , T_1 * V_14 , bool V_135 )
{
T_1 V_10 = * V_14 ;
if ( ! F_42 ( V_10 ) &&
! ( V_135 && F_40 ( V_10 ) ) )
return false ;
F_89 ( L_9 , V_14 , * V_14 ) ;
if ( V_135 )
V_10 &= ~ V_62 ;
V_10 = V_10 & ~ V_136 ;
return F_44 ( V_14 , V_10 ) ;
}
static bool F_108 ( struct V_11 * V_11 , unsigned long * V_128 ,
bool V_135 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
bool V_137 = false ;
for ( V_14 = F_101 ( * V_128 , & V_131 ) ; V_14 ; ) {
F_71 ( ! ( * V_14 & V_40 ) ) ;
V_137 |= F_107 ( V_11 , V_14 , V_135 ) ;
V_14 = F_102 ( & V_131 ) ;
}
return V_137 ;
}
void F_109 ( struct V_11 * V_11 ,
struct V_97 * V_98 ,
T_2 V_138 , unsigned long V_4 )
{
unsigned long * V_128 ;
while ( V_4 ) {
V_128 = F_96 ( V_98 -> V_100 + V_138 + F_110 ( V_4 ) ,
V_43 , V_98 ) ;
F_108 ( V_11 , V_128 , false ) ;
V_4 &= V_4 - 1 ;
}
}
static bool F_111 ( struct V_11 * V_11 , T_1 V_15 )
{
struct V_97 * V_98 ;
unsigned long * V_128 ;
int V_103 ;
bool V_139 = false ;
V_98 = F_79 ( V_11 , V_15 ) ;
for ( V_103 = V_43 ;
V_103 < V_43 + V_105 ; ++ V_103 ) {
V_128 = F_96 ( V_15 , V_103 , V_98 ) ;
V_139 |= F_108 ( V_11 , V_128 , true ) ;
}
return V_139 ;
}
static int F_112 ( struct V_11 * V_11 , unsigned long * V_128 ,
struct V_97 * V_98 , T_2 V_15 , int V_42 ,
unsigned long V_140 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
int V_141 = 0 ;
while ( ( V_14 = F_101 ( * V_128 , & V_131 ) ) ) {
F_71 ( ! ( * V_14 & V_40 ) ) ;
F_89 ( L_10 ,
V_14 , * V_14 , V_15 , V_42 ) ;
F_103 ( V_11 , V_14 ) ;
V_141 = 1 ;
}
return V_141 ;
}
static int F_113 ( struct V_11 * V_11 , unsigned long * V_128 ,
struct V_97 * V_98 , T_2 V_15 , int V_42 ,
unsigned long V_140 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
int V_142 = 0 ;
T_1 V_64 ;
T_6 * V_143 = ( T_6 * ) V_140 ;
T_3 V_144 ;
F_3 ( F_114 ( * V_143 ) ) ;
V_144 = F_115 ( * V_143 ) ;
for ( V_14 = F_101 ( * V_128 , & V_131 ) ; V_14 ; ) {
F_71 ( ! F_22 ( * V_14 ) ) ;
F_89 ( L_11 ,
V_14 , * V_14 , V_15 , V_42 ) ;
V_142 = 1 ;
if ( F_116 ( * V_143 ) ) {
F_103 ( V_11 , V_14 ) ;
V_14 = F_101 ( * V_128 , & V_131 ) ;
} else {
V_64 = * V_14 & ~ V_44 ;
V_64 |= ( T_1 ) V_144 << V_19 ;
V_64 &= ~ V_136 ;
V_64 &= ~ V_61 ;
V_64 &= ~ V_30 ;
F_47 ( V_14 ) ;
F_9 ( V_14 , V_64 ) ;
V_14 = F_102 ( & V_131 ) ;
}
}
if ( V_142 )
F_106 ( V_11 ) ;
return 0 ;
}
static int F_117 ( struct V_11 * V_11 ,
unsigned long V_145 ,
unsigned long V_146 ,
unsigned long V_140 ,
int (* F_118)( struct V_11 * V_11 ,
unsigned long * V_128 ,
struct V_97 * V_98 ,
T_2 V_15 ,
int V_42 ,
unsigned long V_140 ) )
{
int V_124 ;
int V_66 = 0 ;
struct F_6 * V_147 ;
struct V_97 * V_148 ;
V_147 = F_6 ( V_11 ) ;
F_119 (memslot, slots) {
unsigned long V_149 , V_150 ;
T_2 V_151 , V_152 ;
V_149 = F_120 ( V_145 , V_148 -> V_153 ) ;
V_150 = V_74 ( V_146 , V_148 -> V_153 +
( V_148 -> V_154 << V_19 ) ) ;
if ( V_149 >= V_150 )
continue;
V_151 = F_121 ( V_149 , V_148 ) ;
V_152 = F_121 ( V_150 + V_155 - 1 , V_148 ) ;
for ( V_124 = V_43 ;
V_124 < V_43 + V_105 ; ++ V_124 ) {
unsigned long V_99 , V_156 ;
unsigned long * V_128 ;
T_2 V_15 = V_151 ;
V_99 = F_77 ( V_151 , V_148 -> V_100 , V_124 ) ;
V_156 = F_77 ( V_152 - 1 , V_148 -> V_100 , V_124 ) ;
V_128 = F_96 ( V_151 , V_124 , V_148 ) ;
for (; V_99 <= V_156 ;
++ V_99 , V_15 += ( 1UL << F_122 ( V_124 ) ) )
V_66 |= F_118 ( V_11 , V_128 ++ , V_148 ,
V_15 , V_124 , V_140 ) ;
}
}
return V_66 ;
}
static int F_123 ( struct V_11 * V_11 , unsigned long V_157 ,
unsigned long V_140 ,
int (* F_118)( struct V_11 * V_11 , unsigned long * V_128 ,
struct V_97 * V_98 ,
T_2 V_15 , int V_42 ,
unsigned long V_140 ) )
{
return F_117 ( V_11 , V_157 , V_157 + 1 , V_140 , F_118 ) ;
}
int F_124 ( struct V_11 * V_11 , unsigned long V_157 )
{
return F_123 ( V_11 , V_157 , 0 , F_112 ) ;
}
int F_125 ( struct V_11 * V_11 , unsigned long V_145 , unsigned long V_146 )
{
return F_117 ( V_11 , V_145 , V_146 , 0 , F_112 ) ;
}
void F_126 ( struct V_11 * V_11 , unsigned long V_157 , T_6 V_39 )
{
F_123 ( V_11 , V_157 , ( unsigned long ) & V_39 , F_113 ) ;
}
static int F_127 ( struct V_11 * V_11 , unsigned long * V_128 ,
struct V_97 * V_98 , T_2 V_15 , int V_42 ,
unsigned long V_140 )
{
T_1 * V_14 ;
struct V_130 V_158 ( V_131 ) ;
int V_159 = 0 ;
F_71 ( ! V_30 ) ;
for ( V_14 = F_101 ( * V_128 , & V_131 ) ; V_14 ;
V_14 = F_102 ( & V_131 ) ) {
F_71 ( ! F_22 ( * V_14 ) ) ;
if ( * V_14 & V_30 ) {
V_159 = 1 ;
F_128 ( ( F_129 ( V_30 ) - 1 ) ,
( unsigned long * ) V_14 ) ;
}
}
F_130 ( V_15 , V_42 , V_98 , V_159 ) ;
return V_159 ;
}
static int F_131 ( struct V_11 * V_11 , unsigned long * V_128 ,
struct V_97 * V_98 , T_2 V_15 ,
int V_42 , unsigned long V_140 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
int V_159 = 0 ;
if ( ! V_30 )
goto V_86;
for ( V_14 = F_101 ( * V_128 , & V_131 ) ; V_14 ;
V_14 = F_102 ( & V_131 ) ) {
F_71 ( ! F_22 ( * V_14 ) ) ;
if ( * V_14 & V_30 ) {
V_159 = 1 ;
break;
}
}
V_86:
return V_159 ;
}
static void F_132 ( struct V_34 * V_35 , T_1 * V_10 , T_2 V_15 )
{
unsigned long * V_128 ;
struct V_49 * V_50 ;
V_50 = F_36 ( F_37 ( V_10 ) ) ;
V_128 = F_97 ( V_35 -> V_11 , V_15 , V_50 -> V_92 . V_42 ) ;
F_112 ( V_35 -> V_11 , V_128 , NULL , V_15 , V_50 -> V_92 . V_42 , 0 ) ;
F_106 ( V_35 -> V_11 ) ;
}
int F_133 ( struct V_11 * V_11 , unsigned long V_145 , unsigned long V_146 )
{
if ( ! V_30 ) {
V_11 -> V_160 ++ ;
return F_117 ( V_11 , V_145 , V_146 , 0 ,
F_112 ) ;
}
return F_117 ( V_11 , V_145 , V_146 , 0 , F_127 ) ;
}
int F_134 ( struct V_11 * V_11 , unsigned long V_157 )
{
return F_123 ( V_11 , V_157 , 0 , F_131 ) ;
}
static int F_135 ( T_1 * V_129 )
{
T_1 * V_132 ;
T_1 * V_146 ;
for ( V_132 = V_129 , V_146 = V_132 + V_155 / sizeof( T_1 ) ; V_132 != V_146 ; V_132 ++ )
if ( F_22 ( * V_132 ) ) {
F_92 ( V_125 L_12 , V_161 ,
V_132 , * V_132 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_136 ( struct V_11 * V_11 , int V_162 )
{
V_11 -> V_36 . V_163 += V_162 ;
F_137 ( & V_164 , V_162 ) ;
}
static void F_138 ( struct V_49 * V_50 )
{
ASSERT ( F_135 ( V_50 -> V_129 ) ) ;
F_139 ( & V_50 -> V_165 ) ;
F_140 ( & V_50 -> V_166 ) ;
F_67 ( ( unsigned long ) V_50 -> V_129 ) ;
if ( ! V_50 -> V_92 . V_93 )
F_67 ( ( unsigned long ) V_50 -> V_94 ) ;
F_63 ( V_88 , V_50 ) ;
}
static unsigned F_141 ( T_2 V_15 )
{
return V_15 & ( ( 1 << V_167 ) - 1 ) ;
}
static void F_142 ( struct V_34 * V_35 ,
struct V_49 * V_50 , T_1 * V_168 )
{
if ( ! V_168 )
return;
F_88 ( V_35 , V_168 , & V_50 -> V_169 ) ;
}
static void F_143 ( struct V_49 * V_50 ,
T_1 * V_168 )
{
F_91 ( V_168 , & V_50 -> V_169 ) ;
}
static void F_144 ( struct V_49 * V_50 ,
T_1 * V_168 )
{
F_143 ( V_50 , V_168 ) ;
F_51 ( V_168 ) ;
}
static struct V_49 * F_145 ( struct V_34 * V_35 ,
T_1 * V_168 , int V_93 )
{
struct V_49 * V_50 ;
V_50 = F_70 ( & V_35 -> V_36 . V_88 ) ;
V_50 -> V_129 = F_70 ( & V_35 -> V_36 . V_87 ) ;
if ( ! V_93 )
V_50 -> V_94 = F_70 ( & V_35 -> V_36 . V_87 ) ;
F_146 ( F_147 ( V_50 -> V_129 ) , ( unsigned long ) V_50 ) ;
F_148 ( & V_50 -> V_166 , & V_35 -> V_11 -> V_36 . V_170 ) ;
V_50 -> V_169 = 0 ;
F_142 ( V_35 , V_50 , V_168 ) ;
F_136 ( V_35 -> V_11 , + 1 ) ;
return V_50 ;
}
static void F_149 ( struct V_49 * V_50 )
{
F_95 ( & V_50 -> V_169 , V_171 ) ;
}
static void V_171 ( T_1 * V_10 )
{
struct V_49 * V_50 ;
unsigned int V_91 ;
V_50 = F_36 ( F_37 ( V_10 ) ) ;
V_91 = V_10 - V_50 -> V_129 ;
if ( F_150 ( V_91 , V_50 -> V_172 ) )
return;
if ( V_50 -> V_173 ++ )
return;
F_149 ( V_50 ) ;
}
static int F_151 ( struct V_34 * V_35 ,
struct V_49 * V_50 )
{
return 1 ;
}
static void F_152 ( struct V_34 * V_35 , T_7 V_174 )
{
}
static void F_153 ( struct V_34 * V_35 ,
struct V_49 * V_50 , T_1 * V_10 ,
const void * V_39 )
{
F_3 ( 1 ) ;
}
static int F_154 ( struct V_175 * V_176 , struct V_49 * V_50 ,
int V_99 )
{
int V_103 ;
if ( V_50 -> V_177 )
for ( V_103 = 0 ; V_103 < V_176 -> V_162 ; V_103 ++ )
if ( V_176 -> V_81 [ V_103 ] . V_50 == V_50 )
return 0 ;
V_176 -> V_81 [ V_176 -> V_162 ] . V_50 = V_50 ;
V_176 -> V_81 [ V_176 -> V_162 ] . V_99 = V_99 ;
V_176 -> V_162 ++ ;
return ( V_176 -> V_162 == V_178 ) ;
}
static int F_155 ( struct V_49 * V_50 ,
struct V_175 * V_176 )
{
int V_103 , V_66 , V_179 = 0 ;
F_156 (i, sp->unsync_child_bitmap, 512 ) {
struct V_49 * V_180 ;
T_1 V_181 = V_50 -> V_129 [ V_103 ] ;
if ( ! F_22 ( V_181 ) || F_23 ( V_181 ) )
goto V_182;
V_180 = F_36 ( V_181 & V_44 ) ;
if ( V_180 -> V_173 ) {
if ( F_154 ( V_176 , V_180 , V_103 ) )
return - V_183 ;
V_66 = F_155 ( V_180 , V_176 ) ;
if ( ! V_66 )
goto V_182;
else if ( V_66 > 0 )
V_179 += V_66 ;
else
return V_66 ;
} else if ( V_180 -> V_177 ) {
V_179 ++ ;
if ( F_154 ( V_176 , V_180 , V_103 ) )
return - V_183 ;
} else
goto V_182;
continue;
V_182:
F_157 ( V_103 , V_50 -> V_172 ) ;
V_50 -> V_173 -- ;
F_3 ( ( int ) V_50 -> V_173 < 0 ) ;
}
return V_179 ;
}
static int F_158 ( struct V_49 * V_50 ,
struct V_175 * V_176 )
{
if ( ! V_50 -> V_173 )
return 0 ;
F_154 ( V_176 , V_50 , 0 ) ;
return F_155 ( V_50 , V_176 ) ;
}
static void F_159 ( struct V_11 * V_11 , struct V_49 * V_50 )
{
F_3 ( ! V_50 -> V_177 ) ;
F_160 ( V_50 ) ;
V_50 -> V_177 = 0 ;
-- V_11 -> V_133 . V_184 ;
}
static int F_161 ( struct V_34 * V_35 , struct V_49 * V_50 ,
struct V_185 * V_186 , bool V_187 )
{
if ( V_50 -> V_92 . V_188 != ! ! F_162 ( V_35 ) ) {
F_163 ( V_35 -> V_11 , V_50 , V_186 ) ;
return 1 ;
}
if ( V_187 )
F_159 ( V_35 -> V_11 , V_50 ) ;
if ( V_35 -> V_36 . V_189 . V_190 ( V_35 , V_50 ) ) {
F_163 ( V_35 -> V_11 , V_50 , V_186 ) ;
return 1 ;
}
F_164 ( V_191 , V_35 ) ;
return 0 ;
}
static int F_165 ( struct V_34 * V_35 ,
struct V_49 * V_50 )
{
F_166 ( V_186 ) ;
int V_66 ;
V_66 = F_161 ( V_35 , V_50 , & V_186 , false ) ;
if ( V_66 )
F_167 ( V_35 -> V_11 , & V_186 ) ;
return V_66 ;
}
static void F_168 ( struct V_34 * V_35 , int V_192 ) { }
static void F_169 ( void ) { }
static int F_170 ( struct V_34 * V_35 , struct V_49 * V_50 ,
struct V_185 * V_186 )
{
return F_161 ( V_35 , V_50 , V_186 , true ) ;
}
static void F_171 ( struct V_34 * V_35 , T_2 V_15 )
{
struct V_49 * V_193 ;
F_166 ( V_186 ) ;
bool V_137 = false ;
F_172 (vcpu->kvm, s, gfn) {
if ( ! V_193 -> V_177 )
continue;
F_3 ( V_193 -> V_92 . V_42 != V_43 ) ;
F_159 ( V_35 -> V_11 , V_193 ) ;
if ( ( V_193 -> V_92 . V_188 != ! ! F_162 ( V_35 ) ) ||
( V_35 -> V_36 . V_189 . V_190 ( V_35 , V_193 ) ) ) {
F_163 ( V_35 -> V_11 , V_193 , & V_186 ) ;
continue;
}
V_137 = true ;
}
F_167 ( V_35 -> V_11 , & V_186 ) ;
if ( V_137 )
F_164 ( V_191 , V_35 ) ;
}
static int F_173 ( struct V_175 * V_176 ,
struct V_194 * V_195 ,
int V_103 )
{
int V_196 ;
for ( V_196 = V_103 + 1 ; V_196 < V_176 -> V_162 ; V_196 ++ ) {
struct V_49 * V_50 = V_176 -> V_81 [ V_196 ] . V_50 ;
if ( V_50 -> V_92 . V_42 == V_43 ) {
V_195 -> V_99 [ 0 ] = V_176 -> V_81 [ V_196 ] . V_99 ;
return V_196 ;
}
V_195 -> V_197 [ V_50 -> V_92 . V_42 - 2 ] = V_50 ;
V_195 -> V_99 [ V_50 -> V_92 . V_42 - 1 ] = V_176 -> V_81 [ V_196 ] . V_99 ;
}
return V_196 ;
}
static void F_174 ( struct V_194 * V_195 )
{
struct V_49 * V_50 ;
unsigned int V_42 = 0 ;
do {
unsigned int V_99 = V_195 -> V_99 [ V_42 ] ;
V_50 = V_195 -> V_197 [ V_42 ] ;
if ( ! V_50 )
return;
-- V_50 -> V_173 ;
F_3 ( ( int ) V_50 -> V_173 < 0 ) ;
F_157 ( V_99 , V_50 -> V_172 ) ;
V_42 ++ ;
} while ( V_42 < V_198 - 1 && ! V_50 -> V_173 );
}
static void F_175 ( struct V_49 * V_197 ,
struct V_194 * V_195 ,
struct V_175 * V_176 )
{
V_195 -> V_197 [ V_197 -> V_92 . V_42 - 1 ] = NULL ;
V_176 -> V_162 = 0 ;
}
static void F_176 ( struct V_34 * V_35 ,
struct V_49 * V_197 )
{
int V_103 ;
struct V_49 * V_50 ;
struct V_194 V_195 ;
struct V_175 V_199 ;
F_166 ( V_186 ) ;
F_175 ( V_197 , & V_195 , & V_199 ) ;
while ( F_158 ( V_197 , & V_199 ) ) {
bool V_200 = false ;
F_177 (pages, sp, parents, i)
V_200 |= F_111 ( V_35 -> V_11 , V_50 -> V_15 ) ;
if ( V_200 )
F_106 ( V_35 -> V_11 ) ;
F_177 (pages, sp, parents, i) {
F_170 ( V_35 , V_50 , & V_186 ) ;
F_174 ( & V_195 ) ;
}
F_167 ( V_35 -> V_11 , & V_186 ) ;
F_178 ( & V_35 -> V_11 -> V_201 ) ;
F_175 ( V_197 , & V_195 , & V_199 ) ;
}
}
static void F_179 ( struct V_49 * V_50 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_202 ; ++ V_103 )
V_50 -> V_129 [ V_103 ] = 0ull ;
}
static void F_180 ( struct V_49 * V_50 )
{
V_50 -> V_203 = 0 ;
}
static void F_181 ( T_1 * V_10 )
{
struct V_49 * V_50 = F_36 ( F_37 ( V_10 ) ) ;
F_180 ( V_50 ) ;
}
static bool F_182 ( struct V_11 * V_11 , struct V_49 * V_50 )
{
return F_14 ( V_50 -> V_204 != V_11 -> V_36 . V_204 ) ;
}
static struct V_49 * F_183 ( struct V_34 * V_35 ,
T_2 V_15 ,
T_7 V_205 ,
unsigned V_42 ,
int V_93 ,
unsigned V_16 ,
T_1 * V_168 )
{
union V_206 V_92 ;
unsigned V_207 ;
struct V_49 * V_50 ;
bool V_208 = false ;
V_92 = V_35 -> V_36 . V_189 . V_209 ;
V_92 . V_42 = V_42 ;
V_92 . V_93 = V_93 ;
if ( V_92 . V_93 )
V_92 . V_188 = 0 ;
V_92 . V_16 = V_16 ;
if ( ! V_35 -> V_36 . V_189 . V_210
&& V_35 -> V_36 . V_189 . V_211 <= V_212 ) {
V_207 = V_205 >> ( V_19 + ( V_213 * V_42 ) ) ;
V_207 &= ( 1 << ( ( V_214 - V_213 ) * V_42 ) ) - 1 ;
V_92 . V_207 = V_207 ;
}
F_184 (vcpu->kvm, sp, gfn) {
if ( F_182 ( V_35 -> V_11 , V_50 ) )
continue;
if ( ! V_208 && V_50 -> V_177 )
V_208 = true ;
if ( V_50 -> V_92 . V_215 != V_92 . V_215 )
continue;
if ( V_50 -> V_177 && F_165 ( V_35 , V_50 ) )
break;
F_142 ( V_35 , V_50 , V_168 ) ;
if ( V_50 -> V_173 ) {
F_164 ( V_216 , V_35 ) ;
F_149 ( V_50 ) ;
} else if ( V_50 -> V_177 )
F_149 ( V_50 ) ;
F_180 ( V_50 ) ;
F_185 ( V_50 , false ) ;
return V_50 ;
}
++ V_35 -> V_11 -> V_133 . V_217 ;
V_50 = F_145 ( V_35 , V_168 , V_93 ) ;
if ( ! V_50 )
return V_50 ;
V_50 -> V_15 = V_15 ;
V_50 -> V_92 = V_92 ;
F_186 ( & V_50 -> V_165 ,
& V_35 -> V_11 -> V_36 . V_218 [ F_141 ( V_15 ) ] ) ;
if ( ! V_93 ) {
if ( F_111 ( V_35 -> V_11 , V_15 ) )
F_106 ( V_35 -> V_11 ) ;
if ( V_42 > V_43 && V_208 )
F_171 ( V_35 , V_15 ) ;
F_78 ( V_35 -> V_11 , V_15 ) ;
}
V_50 -> V_204 = V_35 -> V_11 -> V_36 . V_204 ;
F_179 ( V_50 ) ;
F_185 ( V_50 , true ) ;
return V_50 ;
}
static void F_187 ( struct V_219 * V_220 ,
struct V_34 * V_35 , T_1 V_221 )
{
V_220 -> V_221 = V_221 ;
V_220 -> V_222 = V_35 -> V_36 . V_189 . V_223 ;
V_220 -> V_42 = V_35 -> V_36 . V_189 . V_224 ;
if ( V_220 -> V_42 == V_198 &&
V_35 -> V_36 . V_189 . V_211 < V_198 &&
! V_35 -> V_36 . V_189 . V_210 )
-- V_220 -> V_42 ;
if ( V_220 -> V_42 == V_225 ) {
V_220 -> V_222
= V_35 -> V_36 . V_189 . V_226 [ ( V_221 >> 30 ) & 3 ] ;
V_220 -> V_222 &= V_44 ;
-- V_220 -> V_42 ;
if ( ! V_220 -> V_222 )
V_220 -> V_42 = 0 ;
}
}
static bool F_188 ( struct V_219 * V_220 )
{
if ( V_220 -> V_42 < V_43 )
return false ;
V_220 -> V_91 = F_189 ( V_220 -> V_221 , V_220 -> V_42 ) ;
V_220 -> V_14 = ( ( T_1 * ) F_190 ( V_220 -> V_222 ) ) + V_220 -> V_91 ;
return true ;
}
static void F_191 ( struct V_219 * V_220 ,
T_1 V_10 )
{
if ( F_25 ( V_10 , V_220 -> V_42 ) ) {
V_220 -> V_42 = 0 ;
return;
}
V_220 -> V_222 = V_10 & V_44 ;
-- V_220 -> V_42 ;
}
static void F_192 ( struct V_219 * V_220 )
{
return F_191 ( V_220 , * V_220 -> V_14 ) ;
}
static void F_193 ( T_1 * V_14 , struct V_49 * V_50 , bool V_227 )
{
T_1 V_10 ;
F_194 ( V_228 != V_40 ||
V_229 != V_136 ) ;
V_10 = F_37 ( V_50 -> V_129 ) | V_40 | V_136 |
V_29 | V_33 ;
if ( V_227 )
V_10 |= V_30 ;
F_9 ( V_14 , V_10 ) ;
}
static void F_195 ( struct V_34 * V_35 , T_1 * V_14 ,
unsigned V_230 )
{
if ( F_22 ( * V_14 ) && ! F_23 ( * V_14 ) ) {
struct V_49 * V_180 ;
V_180 = F_36 ( * V_14 & V_44 ) ;
if ( V_180 -> V_92 . V_16 == V_230 )
return;
F_144 ( V_180 , V_14 ) ;
F_106 ( V_35 -> V_11 ) ;
}
}
static bool F_196 ( struct V_11 * V_11 , struct V_49 * V_50 ,
T_1 * V_10 )
{
T_1 V_39 ;
struct V_49 * V_180 ;
V_39 = * V_10 ;
if ( F_22 ( V_39 ) ) {
if ( F_25 ( V_39 , V_50 -> V_92 . V_42 ) ) {
F_103 ( V_11 , V_10 ) ;
if ( F_23 ( V_39 ) )
-- V_11 -> V_133 . V_134 ;
} else {
V_180 = F_36 ( V_39 & V_44 ) ;
F_144 ( V_180 , V_10 ) ;
}
return true ;
}
if ( F_10 ( V_39 ) )
F_51 ( V_10 ) ;
return false ;
}
static void F_197 ( struct V_11 * V_11 ,
struct V_49 * V_50 )
{
unsigned V_103 ;
for ( V_103 = 0 ; V_103 < V_202 ; ++ V_103 )
F_196 ( V_11 , V_50 , V_50 -> V_129 + V_103 ) ;
}
static void F_198 ( struct V_49 * V_50 , T_1 * V_168 )
{
F_143 ( V_50 , V_168 ) ;
}
static void F_199 ( struct V_11 * V_11 , struct V_49 * V_50 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
while ( ( V_14 = F_101 ( V_50 -> V_169 , & V_131 ) ) )
F_144 ( V_50 , V_14 ) ;
}
static int F_200 ( struct V_11 * V_11 ,
struct V_49 * V_197 ,
struct V_185 * V_186 )
{
int V_103 , V_231 = 0 ;
struct V_194 V_195 ;
struct V_175 V_199 ;
if ( V_197 -> V_92 . V_42 == V_43 )
return 0 ;
F_175 ( V_197 , & V_195 , & V_199 ) ;
while ( F_158 ( V_197 , & V_199 ) ) {
struct V_49 * V_50 ;
F_177 (pages, sp, parents, i) {
F_163 ( V_11 , V_50 , V_186 ) ;
F_174 ( & V_195 ) ;
V_231 ++ ;
}
F_175 ( V_197 , & V_195 , & V_199 ) ;
}
return V_231 ;
}
static int F_163 ( struct V_11 * V_11 , struct V_49 * V_50 ,
struct V_185 * V_186 )
{
int V_66 ;
F_201 ( V_50 ) ;
++ V_11 -> V_133 . V_232 ;
V_66 = F_200 ( V_11 , V_50 , V_186 ) ;
F_197 ( V_11 , V_50 ) ;
F_199 ( V_11 , V_50 ) ;
if ( ! V_50 -> V_92 . V_233 && ! V_50 -> V_92 . V_93 )
F_80 ( V_11 , V_50 -> V_15 ) ;
if ( V_50 -> V_177 )
F_159 ( V_11 , V_50 ) ;
if ( ! V_50 -> V_234 ) {
V_66 ++ ;
F_202 ( & V_50 -> V_166 , V_186 ) ;
F_136 ( V_11 , - 1 ) ;
} else {
F_202 ( & V_50 -> V_166 , & V_11 -> V_36 . V_170 ) ;
if ( ! V_50 -> V_92 . V_233 && ! F_182 ( V_11 , V_50 ) )
F_203 ( V_11 ) ;
}
V_50 -> V_92 . V_233 = 1 ;
return V_66 ;
}
static void F_167 ( struct V_11 * V_11 ,
struct V_185 * V_186 )
{
struct V_49 * V_50 , * V_235 ;
if ( F_204 ( V_186 ) )
return;
F_55 () ;
F_106 ( V_11 ) ;
F_205 (sp, nsp, invalid_list, link) {
F_3 ( ! V_50 -> V_92 . V_233 || V_50 -> V_234 ) ;
F_138 ( V_50 ) ;
}
}
static bool F_206 ( struct V_11 * V_11 ,
struct V_185 * V_186 )
{
struct V_49 * V_50 ;
if ( F_204 ( & V_11 -> V_36 . V_170 ) )
return false ;
V_50 = F_207 ( V_11 -> V_36 . V_170 . V_236 ,
struct V_49 , V_166 ) ;
F_163 ( V_11 , V_50 , V_186 ) ;
return true ;
}
void F_208 ( struct V_11 * V_11 , unsigned int V_237 )
{
F_166 ( V_186 ) ;
F_209 ( & V_11 -> V_201 ) ;
if ( V_11 -> V_36 . V_163 > V_237 ) {
while ( V_11 -> V_36 . V_163 > V_237 )
if ( ! F_206 ( V_11 , & V_186 ) )
break;
F_167 ( V_11 , & V_186 ) ;
V_237 = V_11 -> V_36 . V_163 ;
}
V_11 -> V_36 . V_238 = V_237 ;
F_210 ( & V_11 -> V_201 ) ;
}
int F_211 ( struct V_11 * V_11 , T_2 V_15 )
{
struct V_49 * V_50 ;
F_166 ( V_186 ) ;
int V_82 ;
F_212 ( L_13 , V_161 , V_15 ) ;
V_82 = 0 ;
F_209 ( & V_11 -> V_201 ) ;
F_172 (kvm, sp, gfn) {
F_212 ( L_14 , V_161 , V_15 ,
V_50 -> V_92 . V_215 ) ;
V_82 = 1 ;
F_163 ( V_11 , V_50 , & V_186 ) ;
}
F_167 ( V_11 , & V_186 ) ;
F_210 ( & V_11 -> V_201 ) ;
return V_82 ;
}
static int F_213 ( struct V_239 * V_240 ,
T_1 V_145 , T_1 V_146 )
{
int V_103 ;
T_1 V_241 , V_4 ;
T_8 V_242 , V_243 ;
int V_244 = V_245 ;
if ( ! V_240 -> V_246 )
return 0xFF ;
V_146 -- ;
if ( V_240 -> V_247 && ( V_145 < 0x100000 ) ) {
int V_99 ;
if ( V_145 < 0x80000 ) {
V_99 = 0 ;
V_99 += ( V_145 >> 16 ) ;
return V_240 -> V_248 [ V_99 ] ;
} else if ( V_145 < 0xC0000 ) {
V_99 = 1 * 8 ;
V_99 += ( ( V_145 - 0x80000 ) >> 14 ) ;
return V_240 -> V_248 [ V_99 ] ;
} else if ( V_145 < 0x1000000 ) {
V_99 = 3 * 8 ;
V_99 += ( ( V_145 - 0xC0000 ) >> 12 ) ;
return V_240 -> V_248 [ V_99 ] ;
}
}
if ( ! ( V_240 -> V_246 & 2 ) )
return V_240 -> V_249 ;
V_242 = 0xFF ;
for ( V_103 = 0 ; V_103 < V_244 ; ++ V_103 ) {
unsigned short V_250 , V_251 ;
if ( ! ( V_240 -> V_252 [ V_103 ] . V_253 & ( 1 << 11 ) ) )
continue;
V_241 = ( ( ( T_1 ) V_240 -> V_252 [ V_103 ] . V_254 ) << 32 ) +
( V_240 -> V_252 [ V_103 ] . V_255 & V_20 ) ;
V_4 = ( ( ( T_1 ) V_240 -> V_252 [ V_103 ] . V_256 ) << 32 ) +
( V_240 -> V_252 [ V_103 ] . V_253 & V_20 ) ;
V_250 = ( ( V_145 & V_4 ) == ( V_241 & V_4 ) ) ;
V_251 = ( ( V_146 & V_4 ) == ( V_241 & V_4 ) ) ;
if ( V_250 != V_251 )
return 0xFE ;
if ( ( V_145 & V_4 ) != ( V_241 & V_4 ) )
continue;
V_243 = V_240 -> V_252 [ V_103 ] . V_255 & 0xff ;
if ( V_242 == 0xFF ) {
V_242 = V_243 ;
continue;
}
if ( V_242 == V_257 ||
V_243 == V_257 )
return V_257 ;
if ( ( V_242 == V_258 &&
V_243 == V_259 ) ||
( V_242 == V_259 &&
V_243 == V_258 ) ) {
V_242 = V_259 ;
V_243 = V_259 ;
}
if ( V_242 != V_243 )
return V_257 ;
}
if ( V_242 != 0xFF )
return V_242 ;
return V_240 -> V_249 ;
}
T_8 F_214 ( struct V_34 * V_35 , T_2 V_15 )
{
T_8 V_260 ;
V_260 = F_213 ( & V_35 -> V_36 . V_240 , V_15 << V_19 ,
( V_15 << V_19 ) + V_155 ) ;
if ( V_260 == 0xfe || V_260 == 0xff )
V_260 = V_258 ;
return V_260 ;
}
static void F_215 ( struct V_34 * V_35 , struct V_49 * V_50 )
{
F_216 ( V_50 ) ;
++ V_35 -> V_11 -> V_133 . V_184 ;
V_50 -> V_177 = 1 ;
F_149 ( V_50 ) ;
}
static void F_217 ( struct V_34 * V_35 , T_2 V_15 )
{
struct V_49 * V_193 ;
F_172 (vcpu->kvm, s, gfn) {
if ( V_193 -> V_177 )
continue;
F_3 ( V_193 -> V_92 . V_42 != V_43 ) ;
F_215 ( V_35 , V_193 ) ;
}
}
static int F_218 ( struct V_34 * V_35 , T_2 V_15 ,
bool V_261 )
{
struct V_49 * V_193 ;
bool V_262 = false ;
F_172 (vcpu->kvm, s, gfn) {
if ( ! V_261 )
return 1 ;
if ( V_193 -> V_92 . V_42 != V_43 )
return 1 ;
if ( ! V_193 -> V_177 )
V_262 = true ;
}
if ( V_262 )
F_217 ( V_35 , V_15 ) ;
return 0 ;
}
static int F_219 ( struct V_34 * V_35 , T_1 * V_14 ,
unsigned V_263 , int V_42 ,
T_2 V_15 , T_3 V_21 , bool V_264 ,
bool V_261 , bool V_265 )
{
T_1 V_10 ;
int V_66 = 0 ;
if ( F_13 ( V_35 -> V_11 , V_14 , V_15 , V_21 , V_263 ) )
return 0 ;
V_10 = V_40 ;
if ( ! V_264 )
V_10 |= V_30 ;
if ( V_263 & V_266 )
V_10 |= V_33 ;
else
V_10 |= V_32 ;
if ( V_263 & V_18 )
V_10 |= V_29 ;
if ( V_42 > V_43 )
V_10 |= V_41 ;
if ( V_267 )
V_10 |= V_116 -> V_268 ( V_35 , V_15 ,
F_48 ( V_21 ) ) ;
if ( V_265 )
V_10 |= V_61 ;
else
V_263 &= ~ V_17 ;
V_10 |= ( T_1 ) V_21 << V_19 ;
if ( V_263 & V_17 ) {
if ( V_42 > V_43 &&
F_81 ( V_35 -> V_11 , V_15 , V_42 ) )
goto V_269;
V_10 |= V_136 | V_62 ;
if ( ! V_261 && F_42 ( * V_14 ) )
goto V_270;
if ( F_218 ( V_35 , V_15 , V_261 ) ) {
F_212 ( L_15 ,
V_161 , V_15 ) ;
V_66 = 1 ;
V_263 &= ~ V_17 ;
V_10 &= ~ ( V_136 | V_62 ) ;
}
}
if ( V_263 & V_17 )
F_220 ( V_35 -> V_11 , V_15 ) ;
V_270:
if ( F_44 ( V_14 , V_10 ) )
F_106 ( V_35 -> V_11 ) ;
V_269:
return V_66 ;
}
static void F_221 ( struct V_34 * V_35 , T_1 * V_14 ,
unsigned V_263 , int V_271 , int * V_272 ,
int V_42 , T_2 V_15 , T_3 V_21 , bool V_264 ,
bool V_265 )
{
int V_273 = 0 ;
int V_274 ;
F_212 ( L_16 , V_161 ,
* V_14 , V_271 , V_15 ) ;
if ( F_24 ( * V_14 ) ) {
if ( V_42 > V_43 &&
! F_23 ( * V_14 ) ) {
struct V_49 * V_180 ;
T_1 V_39 = * V_14 ;
V_180 = F_36 ( V_39 & V_44 ) ;
F_144 ( V_180 , V_14 ) ;
F_106 ( V_35 -> V_11 ) ;
} else if ( V_21 != F_26 ( * V_14 ) ) {
F_212 ( L_17 ,
F_26 ( * V_14 ) , V_21 ) ;
F_103 ( V_35 -> V_11 , V_14 ) ;
F_106 ( V_35 -> V_11 ) ;
} else
V_273 = 1 ;
}
if ( F_219 ( V_35 , V_14 , V_263 , V_42 , V_15 , V_21 , V_264 ,
true , V_265 ) ) {
if ( V_271 )
* V_272 = 1 ;
F_164 ( V_191 , V_35 ) ;
}
if ( F_14 ( F_10 ( * V_14 ) && V_272 ) )
* V_272 = 1 ;
F_212 ( L_18 , V_161 , * V_14 ) ;
F_212 ( L_19 ,
F_23 ( * V_14 ) ? L_20 : L_21 ,
* V_14 & V_40 ? L_22 : L_23 , V_15 ,
* V_14 , V_14 ) ;
if ( ! V_273 && F_23 ( * V_14 ) )
++ V_35 -> V_11 -> V_133 . V_134 ;
if ( F_22 ( * V_14 ) ) {
if ( ! V_273 ) {
V_274 = F_99 ( V_35 , V_14 , V_15 ) ;
if ( V_274 > V_275 )
F_132 ( V_35 , V_14 , V_15 ) ;
}
}
F_222 ( V_21 ) ;
}
static T_3 F_223 ( struct V_34 * V_35 , T_2 V_15 ,
bool V_109 )
{
struct V_97 * V_98 ;
V_98 = F_85 ( V_35 , V_15 , V_109 ) ;
if ( ! V_98 )
return V_276 ;
return F_224 ( V_98 , V_15 ) ;
}
static int F_225 ( struct V_34 * V_35 ,
struct V_49 * V_50 ,
T_1 * V_145 , T_1 * V_146 )
{
struct V_81 * V_199 [ V_85 ] ;
unsigned V_16 = V_50 -> V_92 . V_16 ;
int V_103 , V_66 ;
T_2 V_15 ;
V_15 = F_74 ( V_50 , V_145 - V_50 -> V_129 ) ;
if ( ! F_85 ( V_35 , V_15 , V_16 & V_17 ) )
return - 1 ;
V_66 = F_226 ( V_35 -> V_11 , V_15 , V_199 , V_146 - V_145 ) ;
if ( V_66 <= 0 )
return - 1 ;
for ( V_103 = 0 ; V_103 < V_66 ; V_103 ++ , V_15 ++ , V_145 ++ )
F_221 ( V_35 , V_145 , V_16 , 0 , NULL ,
V_50 -> V_92 . V_42 , V_15 , F_227 ( V_199 [ V_103 ] ) ,
true , true ) ;
return 0 ;
}
static void F_228 ( struct V_34 * V_35 ,
struct V_49 * V_50 , T_1 * V_14 )
{
T_1 * V_10 , * V_145 = NULL ;
int V_103 ;
F_3 ( ! V_50 -> V_92 . V_93 ) ;
V_103 = ( V_14 - V_50 -> V_129 ) & ~ ( V_85 - 1 ) ;
V_10 = V_50 -> V_129 + V_103 ;
for ( V_103 = 0 ; V_103 < V_85 ; V_103 ++ , V_10 ++ ) {
if ( F_22 ( * V_10 ) || V_10 == V_14 ) {
if ( ! V_145 )
continue;
if ( F_225 ( V_35 , V_50 , V_145 , V_10 ) < 0 )
break;
V_145 = NULL ;
} else if ( ! V_145 )
V_145 = V_10 ;
}
}
static void F_229 ( struct V_34 * V_35 , T_1 * V_14 )
{
struct V_49 * V_50 ;
if ( ! V_30 )
return;
V_50 = F_36 ( F_37 ( V_14 ) ) ;
if ( V_50 -> V_92 . V_42 > V_43 )
return;
F_228 ( V_35 , V_50 , V_14 ) ;
}
static int F_230 ( struct V_34 * V_35 , T_9 V_277 , int V_278 ,
int V_279 , int V_42 , T_2 V_15 , T_3 V_21 ,
bool V_280 )
{
struct V_219 V_220 ;
struct V_49 * V_50 ;
int V_272 = 0 ;
T_2 V_281 ;
if ( ! F_231 ( V_35 -> V_36 . V_189 . V_223 ) )
return 0 ;
F_232 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_220 . V_42 == V_42 ) {
F_221 ( V_35 , V_220 . V_14 , V_282 ,
V_278 , & V_272 , V_42 , V_15 , V_21 ,
V_280 , V_279 ) ;
F_229 ( V_35 , V_220 . V_14 ) ;
++ V_35 -> V_133 . V_283 ;
break;
}
F_105 ( V_35 , V_220 . V_14 ) ;
if ( ! F_22 ( * V_220 . V_14 ) ) {
T_1 V_284 = V_220 . V_221 ;
V_284 &= F_233 ( V_220 . V_42 ) ;
V_281 = V_284 >> V_19 ;
V_50 = F_183 ( V_35 , V_281 , V_220 . V_221 ,
V_220 . V_42 - 1 ,
1 , V_282 , V_220 . V_14 ) ;
F_193 ( V_220 . V_14 , V_50 , true ) ;
}
}
return V_272 ;
}
static void F_234 ( unsigned long V_285 , struct V_286 * V_287 )
{
T_10 V_288 ;
V_288 . V_289 = V_290 ;
V_288 . V_291 = 0 ;
V_288 . V_292 = V_293 ;
V_288 . V_294 = ( void V_295 * ) V_285 ;
V_288 . V_296 = V_19 ;
F_235 ( V_290 , & V_288 , V_287 ) ;
}
static int F_236 ( struct V_34 * V_35 , T_2 V_15 , T_3 V_21 )
{
if ( V_21 == V_297 )
return 1 ;
if ( V_21 == V_298 ) {
F_234 ( F_237 ( V_35 -> V_11 , V_15 ) , V_299 ) ;
return 0 ;
}
return - V_300 ;
}
static void F_238 ( struct V_34 * V_35 ,
T_2 * V_301 , T_3 * V_302 , int * V_303 )
{
T_3 V_21 = * V_302 ;
T_2 V_15 = * V_301 ;
int V_42 = * V_303 ;
if ( ! F_239 ( V_21 ) && ! F_48 ( V_21 ) &&
V_42 == V_43 &&
F_240 ( F_50 ( V_21 ) ) &&
! F_81 ( V_35 -> V_11 , V_15 , V_104 ) ) {
unsigned long V_4 ;
* V_303 = V_42 = V_104 ;
V_4 = F_241 ( V_42 ) - 1 ;
F_242 ( ( V_15 & V_4 ) != ( V_21 & V_4 ) ) ;
if ( V_21 & V_4 ) {
V_15 &= ~ V_4 ;
* V_301 = V_15 ;
F_222 ( V_21 ) ;
V_21 &= ~ V_4 ;
F_243 ( V_21 ) ;
* V_302 = V_21 ;
}
}
}
static bool F_244 ( struct V_34 * V_35 , T_7 V_174 , T_2 V_15 ,
T_3 V_21 , unsigned V_16 , int * V_304 )
{
bool V_66 = true ;
if ( F_14 ( F_245 ( V_21 ) ) ) {
* V_304 = F_236 ( V_35 , V_15 , V_21 ) ;
goto exit;
}
if ( F_14 ( F_15 ( V_21 ) ) )
F_246 ( V_35 , V_174 , V_15 , V_16 ) ;
V_66 = false ;
exit:
return V_66 ;
}
static bool F_247 ( T_4 V_305 )
{
if ( F_14 ( V_305 & V_306 ) )
return false ;
if ( ! ( V_305 & V_307 ) ||
! ( V_305 & V_308 ) )
return false ;
return true ;
}
static bool
F_248 ( struct V_34 * V_35 , struct V_49 * V_50 ,
T_1 * V_14 , T_1 V_10 )
{
T_2 V_15 ;
F_3 ( ! V_50 -> V_92 . V_93 ) ;
V_15 = F_74 ( V_50 , V_14 - V_50 -> V_129 ) ;
if ( F_249 ( V_14 , V_10 , V_10 | V_136 ) == V_10 )
F_220 ( V_35 -> V_11 , V_15 ) ;
return true ;
}
static bool F_250 ( struct V_34 * V_35 , T_7 V_174 , int V_42 ,
T_4 V_305 )
{
struct V_219 V_220 ;
struct V_49 * V_50 ;
bool V_66 = false ;
T_1 V_10 = 0ull ;
if ( ! F_231 ( V_35 -> V_36 . V_189 . V_223 ) )
return false ;
if ( ! F_247 ( V_305 ) )
return false ;
F_53 ( V_35 ) ;
F_251 (vcpu, gva, iterator, spte)
if ( ! F_22 ( V_10 ) || V_220 . V_42 < V_42 )
break;
if ( ! F_24 ( V_10 ) ) {
V_66 = true ;
goto exit;
}
V_50 = F_36 ( F_37 ( V_220 . V_14 ) ) ;
if ( ! F_25 ( V_10 , V_50 -> V_92 . V_42 ) )
goto exit;
if ( F_42 ( V_10 ) ) {
V_66 = true ;
goto exit;
}
if ( ! F_40 ( V_10 ) )
goto exit;
if ( V_50 -> V_92 . V_42 > V_43 )
goto exit;
V_66 = F_248 ( V_35 , V_50 , V_220 . V_14 , V_10 ) ;
exit:
F_252 ( V_35 , V_174 , V_305 , V_220 . V_14 ,
V_10 , V_66 ) ;
F_56 ( V_35 ) ;
return V_66 ;
}
static int F_253 ( struct V_34 * V_35 , T_7 V_277 , T_4 V_305 ,
T_2 V_15 , bool V_280 )
{
int V_82 ;
int V_42 ;
int V_309 ;
T_3 V_21 ;
unsigned long V_310 ;
bool V_279 , V_278 = V_305 & V_308 ;
V_309 = F_86 ( V_35 , V_15 ) ;
if ( F_18 ( ! V_309 ) ) {
V_42 = F_87 ( V_35 , V_15 ) ;
if ( V_42 > V_104 )
V_42 = V_104 ;
V_15 &= ~ ( F_241 ( V_42 ) - 1 ) ;
} else
V_42 = V_43 ;
if ( F_250 ( V_35 , V_277 , V_42 , V_305 ) )
return 0 ;
V_310 = V_35 -> V_11 -> V_160 ;
F_39 () ;
if ( F_254 ( V_35 , V_280 , V_15 , V_277 , & V_21 , V_278 , & V_279 ) )
return 0 ;
if ( F_244 ( V_35 , V_277 , V_15 , V_21 , V_282 , & V_82 ) )
return V_82 ;
F_209 ( & V_35 -> V_11 -> V_201 ) ;
if ( F_255 ( V_35 -> V_11 , V_310 ) )
goto V_311;
F_256 ( V_35 ) ;
if ( F_18 ( ! V_309 ) )
F_238 ( V_35 , & V_15 , & V_21 , & V_42 ) ;
V_82 = F_230 ( V_35 , V_277 , V_278 , V_279 , V_42 , V_15 , V_21 ,
V_280 ) ;
F_210 ( & V_35 -> V_11 -> V_201 ) ;
return V_82 ;
V_311:
F_210 ( & V_35 -> V_11 -> V_201 ) ;
F_222 ( V_21 ) ;
return 0 ;
}
static void F_257 ( struct V_34 * V_35 )
{
int V_103 ;
struct V_49 * V_50 ;
F_166 ( V_186 ) ;
if ( ! F_231 ( V_35 -> V_36 . V_189 . V_223 ) )
return;
if ( V_35 -> V_36 . V_189 . V_224 == V_198 &&
( V_35 -> V_36 . V_189 . V_211 == V_198 ||
V_35 -> V_36 . V_189 . V_210 ) ) {
T_11 V_312 = V_35 -> V_36 . V_189 . V_223 ;
F_209 ( & V_35 -> V_11 -> V_201 ) ;
V_50 = F_36 ( V_312 ) ;
-- V_50 -> V_234 ;
if ( ! V_50 -> V_234 && V_50 -> V_92 . V_233 ) {
F_163 ( V_35 -> V_11 , V_50 , & V_186 ) ;
F_167 ( V_35 -> V_11 , & V_186 ) ;
}
F_210 ( & V_35 -> V_11 -> V_201 ) ;
V_35 -> V_36 . V_189 . V_223 = V_313 ;
return;
}
F_209 ( & V_35 -> V_11 -> V_201 ) ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_11 V_312 = V_35 -> V_36 . V_189 . V_226 [ V_103 ] ;
if ( V_312 ) {
V_312 &= V_44 ;
V_50 = F_36 ( V_312 ) ;
-- V_50 -> V_234 ;
if ( ! V_50 -> V_234 && V_50 -> V_92 . V_233 )
F_163 ( V_35 -> V_11 , V_50 ,
& V_186 ) ;
}
V_35 -> V_36 . V_189 . V_226 [ V_103 ] = V_313 ;
}
F_167 ( V_35 -> V_11 , & V_186 ) ;
F_210 ( & V_35 -> V_11 -> V_201 ) ;
V_35 -> V_36 . V_189 . V_223 = V_313 ;
}
static int F_258 ( struct V_34 * V_35 , T_2 V_314 )
{
int V_66 = 0 ;
if ( ! F_259 ( V_35 -> V_11 , V_314 ) ) {
F_164 ( V_315 , V_35 ) ;
V_66 = 1 ;
}
return V_66 ;
}
static int F_260 ( struct V_34 * V_35 )
{
struct V_49 * V_50 ;
unsigned V_103 ;
if ( V_35 -> V_36 . V_189 . V_224 == V_198 ) {
F_209 ( & V_35 -> V_11 -> V_201 ) ;
F_256 ( V_35 ) ;
V_50 = F_183 ( V_35 , 0 , 0 , V_198 ,
1 , V_282 , NULL ) ;
++ V_50 -> V_234 ;
F_210 ( & V_35 -> V_11 -> V_201 ) ;
V_35 -> V_36 . V_189 . V_223 = F_37 ( V_50 -> V_129 ) ;
} else if ( V_35 -> V_36 . V_189 . V_224 == V_225 ) {
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_11 V_312 = V_35 -> V_36 . V_189 . V_226 [ V_103 ] ;
ASSERT ( ! F_231 ( V_312 ) ) ;
F_209 ( & V_35 -> V_11 -> V_201 ) ;
F_256 ( V_35 ) ;
V_50 = F_183 ( V_35 , V_103 << ( 30 - V_19 ) ,
V_103 << 30 ,
V_212 , 1 , V_282 ,
NULL ) ;
V_312 = F_37 ( V_50 -> V_129 ) ;
++ V_50 -> V_234 ;
F_210 ( & V_35 -> V_11 -> V_201 ) ;
V_35 -> V_36 . V_189 . V_226 [ V_103 ] = V_312 | V_40 ;
}
V_35 -> V_36 . V_189 . V_223 = F_37 ( V_35 -> V_36 . V_189 . V_226 ) ;
} else
F_93 () ;
return 0 ;
}
static int F_261 ( struct V_34 * V_35 )
{
struct V_49 * V_50 ;
T_1 V_316 , V_317 ;
T_2 V_314 ;
int V_103 ;
V_314 = V_35 -> V_36 . V_189 . V_318 ( V_35 ) >> V_19 ;
if ( F_258 ( V_35 , V_314 ) )
return 1 ;
if ( V_35 -> V_36 . V_189 . V_211 == V_198 ) {
T_11 V_312 = V_35 -> V_36 . V_189 . V_223 ;
ASSERT ( ! F_231 ( V_312 ) ) ;
F_209 ( & V_35 -> V_11 -> V_201 ) ;
F_256 ( V_35 ) ;
V_50 = F_183 ( V_35 , V_314 , 0 , V_198 ,
0 , V_282 , NULL ) ;
V_312 = F_37 ( V_50 -> V_129 ) ;
++ V_50 -> V_234 ;
F_210 ( & V_35 -> V_11 -> V_201 ) ;
V_35 -> V_36 . V_189 . V_223 = V_312 ;
return 0 ;
}
V_317 = V_40 ;
if ( V_35 -> V_36 . V_189 . V_224 == V_198 )
V_317 |= V_319 | V_136 | V_320 ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_11 V_312 = V_35 -> V_36 . V_189 . V_226 [ V_103 ] ;
ASSERT ( ! F_231 ( V_312 ) ) ;
if ( V_35 -> V_36 . V_189 . V_211 == V_225 ) {
V_316 = V_35 -> V_36 . V_189 . V_321 ( V_35 , V_103 ) ;
if ( ! F_262 ( V_316 ) ) {
V_35 -> V_36 . V_189 . V_226 [ V_103 ] = 0 ;
continue;
}
V_314 = V_316 >> V_19 ;
if ( F_258 ( V_35 , V_314 ) )
return 1 ;
}
F_209 ( & V_35 -> V_11 -> V_201 ) ;
F_256 ( V_35 ) ;
V_50 = F_183 ( V_35 , V_314 , V_103 << 30 ,
V_212 , 0 ,
V_282 , NULL ) ;
V_312 = F_37 ( V_50 -> V_129 ) ;
++ V_50 -> V_234 ;
F_210 ( & V_35 -> V_11 -> V_201 ) ;
V_35 -> V_36 . V_189 . V_226 [ V_103 ] = V_312 | V_317 ;
}
V_35 -> V_36 . V_189 . V_223 = F_37 ( V_35 -> V_36 . V_189 . V_226 ) ;
if ( V_35 -> V_36 . V_189 . V_224 == V_198 ) {
if ( V_35 -> V_36 . V_189 . V_322 == NULL ) {
T_1 * V_322 ;
V_322 = ( void * ) F_263 ( V_78 ) ;
if ( V_322 == NULL )
return 1 ;
V_322 [ 0 ] = F_37 ( V_35 -> V_36 . V_189 . V_226 ) | V_317 ;
V_35 -> V_36 . V_189 . V_322 = V_322 ;
}
V_35 -> V_36 . V_189 . V_223 = F_37 ( V_35 -> V_36 . V_189 . V_322 ) ;
}
return 0 ;
}
static int F_264 ( struct V_34 * V_35 )
{
if ( V_35 -> V_36 . V_189 . V_210 )
return F_260 ( V_35 ) ;
else
return F_261 ( V_35 ) ;
}
static void F_265 ( struct V_34 * V_35 )
{
int V_103 ;
struct V_49 * V_50 ;
if ( V_35 -> V_36 . V_189 . V_210 )
return;
if ( ! F_231 ( V_35 -> V_36 . V_189 . V_223 ) )
return;
F_266 ( V_35 , V_323 ) ;
F_168 ( V_35 , V_324 ) ;
if ( V_35 -> V_36 . V_189 . V_211 == V_198 ) {
T_11 V_312 = V_35 -> V_36 . V_189 . V_223 ;
V_50 = F_36 ( V_312 ) ;
F_176 ( V_35 , V_50 ) ;
F_168 ( V_35 , V_325 ) ;
return;
}
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_11 V_312 = V_35 -> V_36 . V_189 . V_226 [ V_103 ] ;
if ( V_312 && F_231 ( V_312 ) ) {
V_312 &= V_44 ;
V_50 = F_36 ( V_312 ) ;
F_176 ( V_35 , V_50 ) ;
}
}
F_168 ( V_35 , V_325 ) ;
}
void F_267 ( struct V_34 * V_35 )
{
F_209 ( & V_35 -> V_11 -> V_201 ) ;
F_265 ( V_35 ) ;
F_210 ( & V_35 -> V_11 -> V_201 ) ;
}
static T_9 F_268 ( struct V_34 * V_35 , T_7 V_326 ,
T_4 V_16 , struct V_327 * V_328 )
{
if ( V_328 )
V_328 -> V_305 = 0 ;
return V_326 ;
}
static T_9 F_269 ( struct V_34 * V_35 , T_7 V_326 ,
T_4 V_16 ,
struct V_327 * V_328 )
{
if ( V_328 )
V_328 -> V_305 = 0 ;
return V_35 -> V_36 . V_329 . V_330 ( V_35 , V_326 , V_16 , V_328 ) ;
}
static bool F_270 ( struct V_34 * V_35 , T_1 V_221 , bool V_93 )
{
if ( V_93 )
return F_271 ( V_35 , V_221 ) ;
return F_272 ( V_35 , V_221 ) ;
}
static bool F_273 ( T_1 V_10 )
{
return F_34 ( V_10 ) ;
}
static T_1 F_274 ( struct V_34 * V_35 , T_1 V_221 )
{
struct V_219 V_220 ;
T_1 V_10 = 0ull ;
if ( ! F_231 ( V_35 -> V_36 . V_189 . V_223 ) )
return V_10 ;
F_53 ( V_35 ) ;
F_251 (vcpu, addr, iterator, spte)
if ( ! F_22 ( V_10 ) )
break;
F_56 ( V_35 ) ;
return V_10 ;
}
int F_275 ( struct V_34 * V_35 , T_1 V_221 , bool V_93 )
{
T_1 V_10 ;
if ( F_270 ( V_35 , V_221 , V_93 ) )
return V_331 ;
V_10 = F_274 ( V_35 , V_221 ) ;
if ( F_10 ( V_10 ) ) {
T_2 V_15 = F_11 ( V_10 ) ;
unsigned V_16 = F_12 ( V_10 ) ;
if ( ! F_16 ( V_35 -> V_11 , V_10 ) )
return V_332 ;
if ( V_93 )
V_221 = 0 ;
F_276 ( V_221 , V_15 , V_16 ) ;
F_246 ( V_35 , V_221 , V_15 , V_16 ) ;
return V_331 ;
}
if ( V_93 && ! F_273 ( V_10 ) )
return V_333 ;
return V_334 ;
}
static int F_277 ( struct V_34 * V_35 , T_1 V_221 ,
T_4 V_305 , bool V_93 )
{
int V_66 ;
V_66 = F_275 ( V_35 , V_221 , V_93 ) ;
F_3 ( V_66 == V_333 ) ;
return V_66 ;
}
static int F_278 ( struct V_34 * V_35 , T_7 V_174 ,
T_4 V_305 , bool V_280 )
{
T_2 V_15 ;
int V_82 ;
F_212 ( L_24 , V_161 , V_174 , V_305 ) ;
if ( F_14 ( V_305 & V_306 ) ) {
V_82 = F_277 ( V_35 , V_174 , V_305 , true ) ;
if ( F_18 ( V_82 != V_332 ) )
return V_82 ;
}
V_82 = F_68 ( V_35 ) ;
if ( V_82 )
return V_82 ;
ASSERT ( V_35 ) ;
ASSERT ( F_231 ( V_35 -> V_36 . V_189 . V_223 ) ) ;
V_15 = V_174 >> V_19 ;
return F_253 ( V_35 , V_174 & V_20 ,
V_305 , V_15 , V_280 ) ;
}
static int F_279 ( struct V_34 * V_35 , T_7 V_174 , T_2 V_15 )
{
struct V_335 V_36 ;
V_36 . V_336 = ( V_35 -> V_36 . V_337 . V_338 ++ << 12 ) | V_35 -> V_339 ;
V_36 . V_15 = V_15 ;
V_36 . V_210 = V_35 -> V_36 . V_189 . V_210 ;
V_36 . V_340 = V_35 -> V_36 . V_189 . V_318 ( V_35 ) ;
return F_280 ( V_35 , V_174 , F_237 ( V_35 -> V_11 , V_15 ) , & V_36 ) ;
}
static bool F_281 ( struct V_34 * V_35 )
{
if ( F_14 ( ! F_282 ( V_35 -> V_11 ) ||
F_283 ( V_35 ) ) )
return false ;
return V_116 -> V_341 ( V_35 ) ;
}
static bool F_254 ( struct V_34 * V_35 , bool V_280 , T_2 V_15 ,
T_7 V_174 , T_3 * V_21 , bool V_278 , bool * V_342 )
{
bool V_343 ;
* V_21 = F_284 ( V_35 -> V_11 , V_15 , & V_343 , V_278 , V_342 ) ;
if ( ! V_343 )
return false ;
if ( ! V_280 && F_281 ( V_35 ) ) {
F_285 ( V_174 , V_15 ) ;
if ( F_286 ( V_35 , V_15 ) ) {
F_287 ( V_174 , V_15 ) ;
F_164 ( V_344 , V_35 ) ;
return true ;
} else if ( F_279 ( V_35 , V_174 , V_15 ) )
return true ;
}
* V_21 = F_288 ( V_35 -> V_11 , V_15 , V_278 , V_342 ) ;
return false ;
}
static int F_289 ( struct V_34 * V_35 , T_7 V_345 , T_4 V_305 ,
bool V_280 )
{
T_3 V_21 ;
int V_82 ;
int V_42 ;
int V_309 ;
T_2 V_15 = V_345 >> V_19 ;
unsigned long V_310 ;
int V_278 = V_305 & V_308 ;
bool V_279 ;
ASSERT ( V_35 ) ;
ASSERT ( F_231 ( V_35 -> V_36 . V_189 . V_223 ) ) ;
if ( F_14 ( V_305 & V_306 ) ) {
V_82 = F_277 ( V_35 , V_345 , V_305 , true ) ;
if ( F_18 ( V_82 != V_332 ) )
return V_82 ;
}
V_82 = F_68 ( V_35 ) ;
if ( V_82 )
return V_82 ;
V_309 = F_86 ( V_35 , V_15 ) ;
if ( F_18 ( ! V_309 ) ) {
V_42 = F_87 ( V_35 , V_15 ) ;
V_15 &= ~ ( F_241 ( V_42 ) - 1 ) ;
} else
V_42 = V_43 ;
if ( F_250 ( V_35 , V_345 , V_42 , V_305 ) )
return 0 ;
V_310 = V_35 -> V_11 -> V_160 ;
F_39 () ;
if ( F_254 ( V_35 , V_280 , V_15 , V_345 , & V_21 , V_278 , & V_279 ) )
return 0 ;
if ( F_244 ( V_35 , 0 , V_15 , V_21 , V_282 , & V_82 ) )
return V_82 ;
F_209 ( & V_35 -> V_11 -> V_201 ) ;
if ( F_255 ( V_35 -> V_11 , V_310 ) )
goto V_311;
F_256 ( V_35 ) ;
if ( F_18 ( ! V_309 ) )
F_238 ( V_35 , & V_15 , & V_21 , & V_42 ) ;
V_82 = F_230 ( V_35 , V_345 , V_278 , V_279 ,
V_42 , V_15 , V_21 , V_280 ) ;
F_210 ( & V_35 -> V_11 -> V_201 ) ;
return V_82 ;
V_311:
F_210 ( & V_35 -> V_11 -> V_201 ) ;
F_222 ( V_21 ) ;
return 0 ;
}
static void F_290 ( struct V_34 * V_35 ,
struct V_346 * V_347 )
{
V_347 -> V_348 = F_278 ;
V_347 -> V_349 = F_268 ;
V_347 -> V_190 = F_151 ;
V_347 -> V_350 = F_152 ;
V_347 -> V_351 = F_153 ;
V_347 -> V_211 = 0 ;
V_347 -> V_224 = V_225 ;
V_347 -> V_223 = V_313 ;
V_347 -> V_210 = true ;
V_347 -> V_352 = false ;
}
void F_291 ( struct V_34 * V_35 )
{
F_257 ( V_35 ) ;
}
static unsigned long V_318 ( struct V_34 * V_35 )
{
return F_292 ( V_35 ) ;
}
static void F_293 ( struct V_34 * V_35 ,
struct V_327 * V_353 )
{
V_35 -> V_36 . V_189 . F_293 ( V_35 , V_353 ) ;
}
static bool F_294 ( struct V_11 * V_11 , T_1 * V_14 , T_2 V_15 ,
unsigned V_16 , int * V_354 )
{
if ( F_14 ( F_10 ( * V_14 ) ) ) {
if ( V_15 != F_11 ( * V_14 ) ) {
F_51 ( V_14 ) ;
return true ;
}
( * V_354 ) ++ ;
F_7 ( V_11 , V_14 , V_15 , V_16 ) ;
return true ;
}
return false ;
}
static inline bool F_295 ( struct V_346 * V_189 , unsigned V_42 , unsigned V_45 )
{
unsigned V_91 ;
V_91 = V_42 - 1 ;
V_91 |= ( V_45 & V_41 ) >> ( V_355 - 2 ) ;
return V_189 -> V_356 & ( 1 << V_91 ) ;
}
static void F_296 ( struct V_34 * V_35 ,
struct V_346 * V_347 )
{
int V_357 = F_297 ( V_35 ) ;
T_1 V_358 = 0 ;
T_1 V_359 = 0 ;
T_1 V_360 = 0 ;
V_347 -> V_361 = 0 ;
if ( ! V_347 -> V_352 )
V_358 = F_298 ( 63 , 63 ) ;
if ( ! F_299 ( V_35 ) )
V_359 = F_298 ( 7 , 7 ) ;
if ( F_300 ( V_35 ) )
V_360 = F_298 ( 8 , 8 ) ;
switch ( V_347 -> V_211 ) {
case V_212 :
V_347 -> V_362 [ 0 ] [ 1 ] = 0 ;
V_347 -> V_362 [ 0 ] [ 0 ] = 0 ;
V_347 -> V_362 [ 1 ] [ 0 ] = V_347 -> V_362 [ 0 ] [ 0 ] ;
if ( ! F_301 ( V_35 ) ) {
V_347 -> V_362 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_20 () )
V_347 -> V_362 [ 1 ] [ 1 ] = F_298 ( 17 , 21 ) ;
else
V_347 -> V_362 [ 1 ] [ 1 ] = F_298 ( 13 , 21 ) ;
break;
case V_225 :
V_347 -> V_362 [ 0 ] [ 2 ] =
F_298 ( V_357 , 63 ) |
F_298 ( 5 , 8 ) | F_298 ( 1 , 2 ) ;
V_347 -> V_362 [ 0 ] [ 1 ] = V_358 |
F_298 ( V_357 , 62 ) ;
V_347 -> V_362 [ 0 ] [ 0 ] = V_358 |
F_298 ( V_357 , 62 ) ;
V_347 -> V_362 [ 1 ] [ 1 ] = V_358 |
F_298 ( V_357 , 62 ) |
F_298 ( 13 , 20 ) ;
V_347 -> V_362 [ 1 ] [ 0 ] = V_347 -> V_362 [ 0 ] [ 0 ] ;
break;
case V_198 :
V_347 -> V_362 [ 0 ] [ 3 ] = V_358 |
V_360 | F_298 ( 7 , 7 ) | F_298 ( V_357 , 51 ) ;
V_347 -> V_362 [ 0 ] [ 2 ] = V_358 |
V_360 | V_359 | F_298 ( V_357 , 51 ) ;
V_347 -> V_362 [ 0 ] [ 1 ] = V_358 |
F_298 ( V_357 , 51 ) ;
V_347 -> V_362 [ 0 ] [ 0 ] = V_358 |
F_298 ( V_357 , 51 ) ;
V_347 -> V_362 [ 1 ] [ 3 ] = V_347 -> V_362 [ 0 ] [ 3 ] ;
V_347 -> V_362 [ 1 ] [ 2 ] = V_358 |
V_359 | F_298 ( V_357 , 51 ) |
F_298 ( 13 , 29 ) ;
V_347 -> V_362 [ 1 ] [ 1 ] = V_358 |
F_298 ( V_357 , 51 ) |
F_298 ( 13 , 20 ) ;
V_347 -> V_362 [ 1 ] [ 0 ] = V_347 -> V_362 [ 0 ] [ 0 ] ;
break;
}
}
static void F_302 ( struct V_34 * V_35 ,
struct V_346 * V_347 , bool V_363 )
{
int V_357 = F_297 ( V_35 ) ;
int V_39 ;
V_347 -> V_362 [ 0 ] [ 3 ] =
F_298 ( V_357 , 51 ) | F_298 ( 3 , 7 ) ;
V_347 -> V_362 [ 0 ] [ 2 ] =
F_298 ( V_357 , 51 ) | F_298 ( 3 , 6 ) ;
V_347 -> V_362 [ 0 ] [ 1 ] =
F_298 ( V_357 , 51 ) | F_298 ( 3 , 6 ) ;
V_347 -> V_362 [ 0 ] [ 0 ] = F_298 ( V_357 , 51 ) ;
V_347 -> V_362 [ 1 ] [ 3 ] = V_347 -> V_362 [ 0 ] [ 3 ] ;
V_347 -> V_362 [ 1 ] [ 2 ] =
F_298 ( V_357 , 51 ) | F_298 ( 12 , 29 ) ;
V_347 -> V_362 [ 1 ] [ 1 ] =
F_298 ( V_357 , 51 ) | F_298 ( 12 , 20 ) ;
V_347 -> V_362 [ 1 ] [ 0 ] = V_347 -> V_362 [ 0 ] [ 0 ] ;
for ( V_39 = 0 ; V_39 < 64 ; V_39 ++ ) {
int V_364 = V_39 & 7 ;
int V_365 = V_39 >> 3 ;
if ( V_365 == 0x2 || V_365 == 0x3 || V_365 == 0x7 ||
V_364 == 0x2 || V_364 == 0x6 ||
( V_364 == 0x4 && ! V_363 ) )
V_347 -> V_361 |= ( 1ull << V_39 ) ;
}
}
void F_303 ( struct V_34 * V_35 ,
struct V_346 * V_189 , bool V_366 )
{
unsigned V_367 , V_368 , V_369 ;
T_8 V_370 ;
bool V_353 , V_371 , V_372 , V_373 , V_374 , V_375 , V_376 , V_377 , V_378 , V_379 , V_380 = 0 ;
V_379 = F_304 ( V_35 , V_381 ) ;
V_378 = F_304 ( V_35 , V_382 ) ;
for ( V_368 = 0 ; V_368 < F_59 ( V_189 -> V_383 ) ; ++ V_368 ) {
V_369 = V_368 << 1 ;
V_370 = 0 ;
V_374 = V_369 & V_308 ;
V_375 = V_369 & V_384 ;
V_376 = V_369 & V_385 ;
V_377 = ! ( V_369 & V_306 ) ;
for ( V_367 = 0 ; V_367 < 8 ; ++ V_367 ) {
V_371 = V_367 & V_266 ;
V_372 = V_367 & V_17 ;
V_373 = V_367 & V_18 ;
if ( ! V_366 ) {
V_371 |= ! V_189 -> V_352 ;
V_372 |= ! F_305 ( V_35 ) && ! V_375 ;
V_371 &= ! ( V_379 && V_373 && ! V_375 ) ;
V_380 = V_378 && V_373 && ! V_375 && ! V_376 ;
} else
V_373 = 1 ;
V_353 = ( V_376 && ! V_371 ) || ( V_375 && ! V_373 ) || ( V_374 && ! V_372 ) ||
( V_377 && V_380 ) ;
V_370 |= V_353 << V_367 ;
}
V_189 -> V_383 [ V_368 ] = V_370 ;
}
}
static void F_306 ( struct V_34 * V_35 , struct V_346 * V_189 )
{
T_8 V_370 ;
unsigned V_42 , V_211 = V_189 -> V_211 ;
const unsigned V_386 = 1 << 2 ;
if ( V_211 == V_225 )
-- V_211 ;
V_370 = 1 | ( 1 << V_386 ) ;
for ( V_42 = V_104 ; V_42 <= V_211 ; ++ V_42 ) {
if ( V_42 <= V_387
&& ( V_189 -> V_211 >= V_225 || F_301 ( V_35 ) ) )
V_370 |= 1 << ( V_386 | ( V_42 - 1 ) ) ;
}
V_189 -> V_356 = V_370 ;
}
static void F_307 ( struct V_34 * V_35 ,
struct V_346 * V_347 ,
int V_42 )
{
V_347 -> V_352 = F_21 ( V_35 ) ;
V_347 -> V_211 = V_42 ;
F_296 ( V_35 , V_347 ) ;
F_303 ( V_35 , V_347 , false ) ;
F_306 ( V_35 , V_347 ) ;
ASSERT ( F_162 ( V_35 ) ) ;
V_347 -> V_348 = V_388 ;
V_347 -> V_349 = V_389 ;
V_347 -> V_190 = V_390 ;
V_347 -> V_350 = V_391 ;
V_347 -> V_351 = V_392 ;
V_347 -> V_224 = V_42 ;
V_347 -> V_223 = V_313 ;
V_347 -> V_210 = false ;
}
static void F_308 ( struct V_34 * V_35 ,
struct V_346 * V_347 )
{
F_307 ( V_35 , V_347 , V_198 ) ;
}
static void F_309 ( struct V_34 * V_35 ,
struct V_346 * V_347 )
{
V_347 -> V_352 = false ;
V_347 -> V_211 = V_212 ;
F_296 ( V_35 , V_347 ) ;
F_303 ( V_35 , V_347 , false ) ;
F_306 ( V_35 , V_347 ) ;
V_347 -> V_348 = V_393 ;
V_347 -> V_349 = V_394 ;
V_347 -> V_190 = V_395 ;
V_347 -> V_350 = V_396 ;
V_347 -> V_351 = V_397 ;
V_347 -> V_224 = V_225 ;
V_347 -> V_223 = V_313 ;
V_347 -> V_210 = false ;
}
static void F_310 ( struct V_34 * V_35 ,
struct V_346 * V_347 )
{
F_307 ( V_35 , V_347 , V_225 ) ;
}
static void F_311 ( struct V_34 * V_35 )
{
struct V_346 * V_347 = V_35 -> V_36 . V_398 ;
V_347 -> V_209 . V_215 = 0 ;
V_347 -> V_348 = F_289 ;
V_347 -> V_190 = F_151 ;
V_347 -> V_350 = F_152 ;
V_347 -> V_351 = F_153 ;
V_347 -> V_224 = V_116 -> V_399 () ;
V_347 -> V_223 = V_313 ;
V_347 -> V_210 = true ;
V_347 -> V_400 = V_116 -> V_401 ;
V_347 -> V_318 = V_318 ;
V_347 -> V_321 = V_402 ;
V_347 -> F_293 = V_403 ;
if ( ! F_312 ( V_35 ) ) {
V_347 -> V_352 = false ;
V_347 -> V_349 = F_268 ;
V_347 -> V_211 = 0 ;
} else if ( F_313 ( V_35 ) ) {
V_347 -> V_352 = F_21 ( V_35 ) ;
V_347 -> V_211 = V_198 ;
F_296 ( V_35 , V_347 ) ;
V_347 -> V_349 = V_389 ;
} else if ( F_162 ( V_35 ) ) {
V_347 -> V_352 = F_21 ( V_35 ) ;
V_347 -> V_211 = V_225 ;
F_296 ( V_35 , V_347 ) ;
V_347 -> V_349 = V_389 ;
} else {
V_347 -> V_352 = false ;
V_347 -> V_211 = V_212 ;
F_296 ( V_35 , V_347 ) ;
V_347 -> V_349 = V_394 ;
}
F_303 ( V_35 , V_347 , false ) ;
F_306 ( V_35 , V_347 ) ;
}
void F_314 ( struct V_34 * V_35 , struct V_346 * V_347 )
{
bool V_404 = F_304 ( V_35 , V_381 ) ;
ASSERT ( V_35 ) ;
ASSERT ( ! F_231 ( V_35 -> V_36 . V_189 . V_223 ) ) ;
if ( ! F_312 ( V_35 ) )
F_290 ( V_35 , V_347 ) ;
else if ( F_313 ( V_35 ) )
F_308 ( V_35 , V_347 ) ;
else if ( F_162 ( V_35 ) )
F_310 ( V_35 , V_347 ) ;
else
F_309 ( V_35 , V_347 ) ;
V_35 -> V_36 . V_189 . V_209 . V_405 = F_21 ( V_35 ) ;
V_35 -> V_36 . V_189 . V_209 . V_188 = ! ! F_162 ( V_35 ) ;
V_35 -> V_36 . V_189 . V_209 . V_406 = F_305 ( V_35 ) ;
V_35 -> V_36 . V_189 . V_209 . V_407
= V_404 && ! F_305 ( V_35 ) ;
}
void F_315 ( struct V_34 * V_35 , struct V_346 * V_347 ,
bool V_363 )
{
ASSERT ( V_35 ) ;
ASSERT ( ! F_231 ( V_35 -> V_36 . V_189 . V_223 ) ) ;
V_347 -> V_224 = V_116 -> V_399 () ;
V_347 -> V_352 = true ;
V_347 -> V_348 = V_408 ;
V_347 -> V_349 = V_409 ;
V_347 -> V_190 = V_410 ;
V_347 -> V_350 = V_411 ;
V_347 -> V_351 = V_412 ;
V_347 -> V_211 = V_347 -> V_224 ;
V_347 -> V_223 = V_313 ;
V_347 -> V_210 = false ;
F_303 ( V_35 , V_347 , true ) ;
F_302 ( V_35 , V_347 , V_363 ) ;
}
static void F_316 ( struct V_34 * V_35 )
{
F_314 ( V_35 , V_35 -> V_36 . V_398 ) ;
V_35 -> V_36 . V_398 -> V_400 = V_116 -> V_400 ;
V_35 -> V_36 . V_398 -> V_318 = V_318 ;
V_35 -> V_36 . V_398 -> V_321 = V_402 ;
V_35 -> V_36 . V_398 -> F_293 = V_403 ;
}
static void F_317 ( struct V_34 * V_35 )
{
struct V_346 * V_413 = & V_35 -> V_36 . V_329 ;
V_413 -> V_318 = V_318 ;
V_413 -> V_321 = V_402 ;
V_413 -> F_293 = V_403 ;
if ( ! F_312 ( V_35 ) ) {
V_413 -> V_352 = false ;
V_413 -> V_211 = 0 ;
V_413 -> V_349 = F_269 ;
} else if ( F_313 ( V_35 ) ) {
V_413 -> V_352 = F_21 ( V_35 ) ;
V_413 -> V_211 = V_198 ;
F_296 ( V_35 , V_413 ) ;
V_413 -> V_349 = V_414 ;
} else if ( F_162 ( V_35 ) ) {
V_413 -> V_352 = F_21 ( V_35 ) ;
V_413 -> V_211 = V_225 ;
F_296 ( V_35 , V_413 ) ;
V_413 -> V_349 = V_414 ;
} else {
V_413 -> V_352 = false ;
V_413 -> V_211 = V_212 ;
F_296 ( V_35 , V_413 ) ;
V_413 -> V_349 = V_415 ;
}
F_303 ( V_35 , V_413 , false ) ;
F_306 ( V_35 , V_413 ) ;
}
static void F_318 ( struct V_34 * V_35 )
{
if ( F_319 ( V_35 ) )
return F_317 ( V_35 ) ;
else if ( V_267 )
return F_311 ( V_35 ) ;
else
return F_316 ( V_35 ) ;
}
void F_320 ( struct V_34 * V_35 )
{
ASSERT ( V_35 ) ;
F_321 ( V_35 ) ;
F_318 ( V_35 ) ;
}
int F_322 ( struct V_34 * V_35 )
{
int V_82 ;
V_82 = F_68 ( V_35 ) ;
if ( V_82 )
goto V_86;
V_82 = F_264 ( V_35 ) ;
F_267 ( V_35 ) ;
if ( V_82 )
goto V_86;
V_35 -> V_36 . V_189 . V_400 ( V_35 , V_35 -> V_36 . V_189 . V_223 ) ;
V_86:
return V_82 ;
}
void F_321 ( struct V_34 * V_35 )
{
F_257 ( V_35 ) ;
F_3 ( F_231 ( V_35 -> V_36 . V_189 . V_223 ) ) ;
}
static void F_323 ( struct V_34 * V_35 ,
struct V_49 * V_50 , T_1 * V_10 ,
const void * V_416 )
{
if ( V_50 -> V_92 . V_42 != V_43 ) {
++ V_35 -> V_11 -> V_133 . V_417 ;
return;
}
++ V_35 -> V_11 -> V_133 . V_418 ;
V_35 -> V_36 . V_189 . V_351 ( V_35 , V_50 , V_10 , V_416 ) ;
}
static bool F_324 ( T_1 V_419 , T_1 V_416 )
{
if ( ! F_22 ( V_419 ) )
return false ;
if ( ! F_22 ( V_416 ) )
return true ;
if ( ( V_419 ^ V_416 ) & V_44 )
return true ;
V_419 ^= V_32 ;
V_416 ^= V_32 ;
return ( V_419 & ~ V_416 & V_420 ) != 0 ;
}
static void F_325 ( struct V_34 * V_35 , bool V_421 ,
bool V_422 , bool V_423 )
{
if ( V_421 )
return;
if ( V_422 )
F_106 ( V_35 -> V_11 ) ;
else if ( V_423 )
F_164 ( V_191 , V_35 ) ;
}
static T_1 F_326 ( struct V_34 * V_35 , T_9 * V_345 ,
const T_8 * V_416 , int * V_424 )
{
T_1 V_425 ;
int V_82 ;
if ( F_162 ( V_35 ) && * V_424 == 4 ) {
* V_345 &= ~ ( T_9 ) 7 ;
* V_424 = 8 ;
V_82 = F_327 ( V_35 -> V_11 , * V_345 , & V_425 , 8 ) ;
if ( V_82 )
V_425 = 0 ;
V_416 = ( const T_8 * ) & V_425 ;
}
switch ( * V_424 ) {
case 4 :
V_425 = * ( const T_4 * ) V_416 ;
break;
case 8 :
V_425 = * ( const T_1 * ) V_416 ;
break;
default:
V_425 = 0 ;
break;
}
return V_425 ;
}
static bool F_328 ( struct V_49 * V_50 )
{
if ( V_50 -> V_92 . V_42 == V_43 )
return false ;
return ++ V_50 -> V_203 >= 3 ;
}
static bool F_329 ( struct V_49 * V_50 , T_9 V_345 ,
int V_424 )
{
unsigned V_426 , V_427 , V_428 ;
F_212 ( L_25 ,
V_345 , V_424 , V_50 -> V_92 . V_215 ) ;
V_426 = F_330 ( V_345 ) ;
V_427 = V_50 -> V_92 . V_188 ? 8 : 4 ;
if ( ! ( V_426 & ( V_427 - 1 ) ) && V_424 == 1 )
return false ;
V_428 = ( V_426 ^ ( V_426 + V_424 - 1 ) ) & ~ ( V_427 - 1 ) ;
V_428 |= V_424 < 4 ;
return V_428 ;
}
static T_1 * F_331 ( struct V_49 * V_50 , T_9 V_345 , int * V_429 )
{
unsigned V_430 , V_207 ;
T_1 * V_10 ;
int V_42 ;
V_430 = F_330 ( V_345 ) ;
V_42 = V_50 -> V_92 . V_42 ;
* V_429 = 1 ;
if ( ! V_50 -> V_92 . V_188 ) {
V_430 <<= 1 ;
if ( V_42 == V_212 ) {
V_430 &= ~ 7 ;
V_430 <<= 1 ;
* V_429 = 2 ;
}
V_207 = V_430 >> V_19 ;
V_430 &= ~ V_20 ;
if ( V_207 != V_50 -> V_92 . V_207 )
return NULL ;
}
V_10 = & V_50 -> V_129 [ V_430 / sizeof( * V_10 ) ] ;
return V_10 ;
}
void F_332 ( struct V_34 * V_35 , T_9 V_345 ,
const T_8 * V_416 , int V_424 )
{
T_2 V_15 = V_345 >> V_19 ;
union V_206 V_4 = { . V_215 = 0 } ;
struct V_49 * V_50 ;
F_166 ( V_186 ) ;
T_1 V_431 , V_425 , * V_10 ;
int V_432 ;
bool V_422 , V_423 , V_421 ;
if ( ! F_33 ( V_35 -> V_11 -> V_36 . V_107 ) )
return;
V_421 = V_422 = V_423 = false ;
F_212 ( L_26 , V_161 , V_345 , V_424 ) ;
V_425 = F_326 ( V_35 , & V_345 , V_416 , & V_424 ) ;
F_68 ( V_35 ) ;
F_209 ( & V_35 -> V_11 -> V_201 ) ;
++ V_35 -> V_11 -> V_133 . V_433 ;
F_168 ( V_35 , V_434 ) ;
V_4 . V_406 = V_4 . V_188 = V_4 . V_405 = 1 ;
F_172 (vcpu->kvm, sp, gfn) {
if ( F_329 ( V_50 , V_345 , V_424 ) ||
F_328 ( V_50 ) ) {
V_421 |= ! ! F_163 ( V_35 -> V_11 , V_50 ,
& V_186 ) ;
++ V_35 -> V_11 -> V_133 . V_435 ;
continue;
}
V_10 = F_331 ( V_50 , V_345 , & V_432 ) ;
if ( ! V_10 )
continue;
V_423 = true ;
while ( V_432 -- ) {
V_431 = * V_10 ;
F_196 ( V_35 -> V_11 , V_50 , V_10 ) ;
if ( V_425 &&
! ( ( V_50 -> V_92 . V_215 ^ V_35 -> V_36 . V_189 . V_209 . V_215 )
& V_4 . V_215 ) && F_98 ( V_35 ) )
F_323 ( V_35 , V_50 , V_10 , & V_425 ) ;
if ( F_324 ( V_431 , * V_10 ) )
V_422 = true ;
++ V_10 ;
}
}
F_325 ( V_35 , V_421 , V_422 , V_423 ) ;
F_167 ( V_35 -> V_11 , & V_186 ) ;
F_168 ( V_35 , V_436 ) ;
F_210 ( & V_35 -> V_11 -> V_201 ) ;
}
int F_333 ( struct V_34 * V_35 , T_7 V_174 )
{
T_9 V_345 ;
int V_82 ;
if ( V_35 -> V_36 . V_189 . V_210 )
return 0 ;
V_345 = F_334 ( V_35 , V_174 , NULL ) ;
V_82 = F_211 ( V_35 -> V_11 , V_345 >> V_19 ) ;
return V_82 ;
}
static void F_256 ( struct V_34 * V_35 )
{
F_166 ( V_186 ) ;
if ( F_18 ( F_335 ( V_35 -> V_11 ) >= V_437 ) )
return;
while ( F_335 ( V_35 -> V_11 ) < V_438 ) {
if ( ! F_206 ( V_35 -> V_11 , & V_186 ) )
break;
++ V_35 -> V_11 -> V_133 . V_439 ;
}
F_167 ( V_35 -> V_11 , & V_186 ) ;
}
static bool F_336 ( struct V_34 * V_35 , T_7 V_221 )
{
if ( V_35 -> V_36 . V_189 . V_210 || F_319 ( V_35 ) )
return F_271 ( V_35 , V_221 ) ;
return F_272 ( V_35 , V_221 ) ;
}
int F_337 ( struct V_34 * V_35 , T_7 V_440 , T_4 V_305 ,
void * V_441 , int V_442 )
{
int V_82 , V_443 = V_444 ;
enum V_445 V_446 ;
V_82 = V_35 -> V_36 . V_189 . V_348 ( V_35 , V_440 , V_305 , false ) ;
if ( V_82 < 0 )
goto V_86;
if ( ! V_82 ) {
V_82 = 1 ;
goto V_86;
}
if ( F_336 ( V_35 , V_440 ) )
V_443 = 0 ;
V_446 = F_338 ( V_35 , V_440 , V_443 , V_441 , V_442 ) ;
switch ( V_446 ) {
case V_447 :
return 1 ;
case V_448 :
++ V_35 -> V_133 . V_449 ;
case V_450 :
return 0 ;
default:
F_93 () ;
}
V_86:
return V_82 ;
}
void F_339 ( struct V_34 * V_35 , T_7 V_174 )
{
V_35 -> V_36 . V_189 . V_350 ( V_35 , V_174 ) ;
F_164 ( V_191 , V_35 ) ;
++ V_35 -> V_133 . V_350 ;
}
void F_340 ( void )
{
V_267 = true ;
}
void F_341 ( void )
{
V_267 = false ;
}
static void F_342 ( struct V_34 * V_35 )
{
F_67 ( ( unsigned long ) V_35 -> V_36 . V_189 . V_226 ) ;
if ( V_35 -> V_36 . V_189 . V_322 != NULL )
F_67 ( ( unsigned long ) V_35 -> V_36 . V_189 . V_322 ) ;
}
static int F_343 ( struct V_34 * V_35 )
{
struct V_81 * V_81 ;
int V_103 ;
ASSERT ( V_35 ) ;
V_81 = F_344 ( V_78 | V_451 ) ;
if ( ! V_81 )
return - V_79 ;
V_35 -> V_36 . V_189 . V_226 = F_345 ( V_81 ) ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 )
V_35 -> V_36 . V_189 . V_226 [ V_103 ] = V_313 ;
return 0 ;
}
int F_346 ( struct V_34 * V_35 )
{
ASSERT ( V_35 ) ;
V_35 -> V_36 . V_398 = & V_35 -> V_36 . V_189 ;
V_35 -> V_36 . V_189 . V_223 = V_313 ;
V_35 -> V_36 . V_189 . V_330 = V_330 ;
V_35 -> V_36 . V_329 . V_330 = V_452 ;
return F_343 ( V_35 ) ;
}
void F_347 ( struct V_34 * V_35 )
{
ASSERT ( V_35 ) ;
ASSERT ( ! F_231 ( V_35 -> V_36 . V_189 . V_223 ) ) ;
F_318 ( V_35 ) ;
}
void F_348 ( struct V_11 * V_11 , int V_98 )
{
struct V_97 * V_148 ;
T_2 V_453 ;
int V_103 ;
V_148 = F_349 ( V_11 -> V_454 , V_98 ) ;
V_453 = V_148 -> V_100 + V_148 -> V_154 - 1 ;
F_209 ( & V_11 -> V_201 ) ;
for ( V_103 = V_43 ;
V_103 < V_43 + V_105 ; ++ V_103 ) {
unsigned long * V_128 ;
unsigned long V_455 , V_91 ;
V_128 = V_148 -> V_36 . V_127 [ V_103 - V_43 ] ;
V_455 = F_77 ( V_453 , V_148 -> V_100 , V_103 ) ;
for ( V_91 = 0 ; V_91 <= V_455 ; ++ V_91 , ++ V_128 ) {
if ( * V_128 )
F_108 ( V_11 , V_128 , false ) ;
if ( F_350 () || F_351 ( & V_11 -> V_201 ) )
F_178 ( & V_11 -> V_201 ) ;
}
}
F_210 ( & V_11 -> V_201 ) ;
F_352 ( & V_11 -> V_456 ) ;
F_106 ( V_11 ) ;
}
static void F_353 ( struct V_11 * V_11 )
{
struct V_49 * V_50 , * V_457 ;
int V_458 = 0 ;
V_459:
F_354 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_66 ;
if ( ! F_182 ( V_11 , V_50 ) )
break;
if ( V_50 -> V_92 . V_233 )
continue;
if ( V_458 >= V_460 &&
F_178 ( & V_11 -> V_201 ) ) {
V_458 = 0 ;
goto V_459;
}
V_66 = F_163 ( V_11 , V_50 ,
& V_11 -> V_36 . V_461 ) ;
V_458 += V_66 ;
if ( V_66 )
goto V_459;
}
F_167 ( V_11 , & V_11 -> V_36 . V_461 ) ;
}
void F_355 ( struct V_11 * V_11 )
{
F_209 ( & V_11 -> V_201 ) ;
F_356 ( V_11 ) ;
V_11 -> V_36 . V_204 ++ ;
F_203 ( V_11 ) ;
F_353 ( V_11 ) ;
F_210 ( & V_11 -> V_201 ) ;
}
static bool F_357 ( struct V_11 * V_11 )
{
return F_14 ( ! F_358 ( & V_11 -> V_36 . V_461 ) ) ;
}
void F_359 ( struct V_11 * V_11 )
{
if ( F_14 ( F_5 ( V_11 ) == 0 ) ) {
F_360 ( V_462 L_27 ) ;
F_355 ( V_11 ) ;
}
}
static unsigned long
F_361 ( struct V_463 * V_464 , struct V_465 * V_466 )
{
struct V_11 * V_11 ;
int V_467 = V_466 -> V_467 ;
unsigned long V_468 = 0 ;
F_209 ( & V_469 ) ;
F_362 (kvm, &vm_list, vm_list) {
int V_99 ;
F_166 ( V_186 ) ;
if ( ! V_467 -- )
break;
if ( ! V_11 -> V_36 . V_163 &&
! F_357 ( V_11 ) )
continue;
V_99 = F_363 ( & V_11 -> V_470 ) ;
F_209 ( & V_11 -> V_201 ) ;
if ( F_357 ( V_11 ) ) {
F_167 ( V_11 ,
& V_11 -> V_36 . V_461 ) ;
goto V_471;
}
if ( F_206 ( V_11 , & V_186 ) )
V_468 ++ ;
F_167 ( V_11 , & V_186 ) ;
V_471:
F_210 ( & V_11 -> V_201 ) ;
F_364 ( & V_11 -> V_470 , V_99 ) ;
F_365 ( & V_11 -> V_472 , & V_472 ) ;
break;
}
F_210 ( & V_469 ) ;
return V_468 ;
}
static unsigned long
F_366 ( struct V_463 * V_464 , struct V_465 * V_466 )
{
return F_367 ( & V_164 ) ;
}
static void F_368 ( void )
{
if ( V_84 )
F_369 ( V_84 ) ;
if ( V_88 )
F_369 ( V_88 ) ;
}
int F_370 ( void )
{
V_84 = F_371 ( L_28 ,
sizeof( struct V_90 ) ,
0 , 0 , NULL ) ;
if ( ! V_84 )
goto V_473;
V_88 = F_371 ( L_29 ,
sizeof( struct V_49 ) ,
0 , 0 , NULL ) ;
if ( ! V_88 )
goto V_473;
if ( F_372 ( & V_164 , 0 , V_78 ) )
goto V_473;
F_373 ( & V_474 ) ;
return 0 ;
V_473:
F_368 () ;
return - V_79 ;
}
unsigned int F_374 ( struct V_11 * V_11 )
{
unsigned int V_475 ;
unsigned int V_476 = 0 ;
struct F_6 * V_147 ;
struct V_97 * V_148 ;
V_147 = F_6 ( V_11 ) ;
F_119 (memslot, slots)
V_476 += V_148 -> V_154 ;
V_475 = V_476 * V_477 / 1000 ;
V_475 = F_120 ( V_475 ,
( unsigned int ) V_478 ) ;
return V_475 ;
}
int F_375 ( struct V_34 * V_35 , T_1 V_221 , T_1 V_120 [ 4 ] )
{
struct V_219 V_220 ;
T_1 V_10 ;
int V_479 = 0 ;
if ( ! F_231 ( V_35 -> V_36 . V_189 . V_223 ) )
return V_479 ;
F_53 ( V_35 ) ;
F_251 (vcpu, addr, iterator, spte) {
V_120 [ V_220 . V_42 - 1 ] = V_10 ;
V_479 ++ ;
if ( ! F_22 ( V_10 ) )
break;
}
F_56 ( V_35 ) ;
return V_479 ;
}
void F_376 ( struct V_34 * V_35 )
{
ASSERT ( V_35 ) ;
F_321 ( V_35 ) ;
F_342 ( V_35 ) ;
F_69 ( V_35 ) ;
}
void F_377 ( void )
{
F_368 () ;
F_378 ( & V_164 ) ;
F_379 ( & V_474 ) ;
F_169 () ;
}
