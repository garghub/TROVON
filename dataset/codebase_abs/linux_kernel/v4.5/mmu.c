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
if ( ! V_30 )
return V_63 ;
if ( F_42 ( V_60 , V_61 ,
V_30 | V_31 ) )
V_63 = true ;
if ( F_41 ( V_60 , V_61 , V_30 ) )
F_44 ( F_25 ( V_60 ) ) ;
if ( F_41 ( V_60 , V_61 , V_31 ) )
F_45 ( F_25 ( V_60 ) ) ;
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
F_44 ( V_21 ) ;
if ( ! V_31 || ( V_60 & V_31 ) )
F_45 ( V_21 ) ;
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
V_12 -> V_64 = V_65 ;
F_54 () ;
}
static void F_55 ( struct V_11 * V_12 )
{
F_54 () ;
V_12 -> V_64 = V_66 ;
F_56 () ;
}
static int F_57 ( struct V_67 * V_68 ,
struct V_69 * V_70 , int V_71 )
{
void * V_72 ;
if ( V_68 -> V_73 >= V_71 )
return 0 ;
while ( V_68 -> V_73 < F_58 ( V_68 -> V_74 ) ) {
V_72 = F_59 ( V_70 , V_75 ) ;
if ( ! V_72 )
return - V_76 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = V_72 ;
}
return 0 ;
}
static int F_60 ( struct V_67 * V_68 )
{
return V_68 -> V_73 ;
}
static void F_61 ( struct V_67 * V_77 ,
struct V_69 * V_68 )
{
while ( V_77 -> V_73 )
F_62 ( V_68 , V_77 -> V_74 [ -- V_77 -> V_73 ] ) ;
}
static int F_63 ( struct V_67 * V_68 ,
int V_71 )
{
void * V_78 ;
if ( V_68 -> V_73 >= V_71 )
return 0 ;
while ( V_68 -> V_73 < F_58 ( V_68 -> V_74 ) ) {
V_78 = ( void * ) F_64 ( V_75 ) ;
if ( ! V_78 )
return - V_76 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = V_78 ;
}
return 0 ;
}
static void F_65 ( struct V_67 * V_77 )
{
while ( V_77 -> V_73 )
F_66 ( ( unsigned long ) V_77 -> V_74 [ -- V_77 -> V_73 ] ) ;
}
static int F_67 ( struct V_11 * V_12 )
{
int V_79 ;
V_79 = F_57 ( & V_12 -> V_34 . V_80 ,
V_81 , 8 + V_82 ) ;
if ( V_79 )
goto V_83;
V_79 = F_63 ( & V_12 -> V_34 . V_84 , 8 ) ;
if ( V_79 )
goto V_83;
V_79 = F_57 ( & V_12 -> V_34 . V_85 ,
V_85 , 4 ) ;
V_83:
return V_79 ;
}
static void F_68 ( struct V_11 * V_12 )
{
F_61 ( & V_12 -> V_34 . V_80 ,
V_81 ) ;
F_65 ( & V_12 -> V_34 . V_84 ) ;
F_61 ( & V_12 -> V_34 . V_85 ,
V_85 ) ;
}
static void * F_69 ( struct V_67 * V_77 )
{
void * V_86 ;
F_70 ( ! V_77 -> V_73 ) ;
V_86 = V_77 -> V_74 [ -- V_77 -> V_73 ] ;
return V_86 ;
}
static struct V_87 * F_71 ( struct V_11 * V_12 )
{
return F_69 ( & V_12 -> V_34 . V_80 ) ;
}
static void F_72 ( struct V_87 * V_87 )
{
F_62 ( V_81 , V_87 ) ;
}
static T_2 F_73 ( struct V_47 * V_48 , int V_88 )
{
if ( ! V_48 -> V_89 . V_90 )
return V_48 -> V_91 [ V_88 ] ;
return V_48 -> V_15 + ( V_88 << ( ( V_48 -> V_89 . V_40 - 1 ) * V_92 ) ) ;
}
static void F_74 ( struct V_47 * V_48 , int V_88 , T_2 V_15 )
{
if ( V_48 -> V_89 . V_90 )
F_70 ( V_15 != F_73 ( V_48 , V_88 ) ) ;
else
V_48 -> V_91 [ V_88 ] = V_15 ;
}
static struct V_93 * F_75 ( T_2 V_15 ,
struct V_94 * V_95 ,
int V_40 )
{
unsigned long V_96 ;
V_96 = F_76 ( V_15 , V_95 -> V_97 , V_40 ) ;
return & V_95 -> V_34 . V_98 [ V_40 - 2 ] [ V_96 ] ;
}
static void F_77 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
struct V_100 * V_101 ;
struct V_94 * V_95 ;
struct V_93 * V_102 ;
T_2 V_15 ;
int V_103 ;
V_15 = V_48 -> V_15 ;
V_101 = F_78 ( V_99 , V_48 -> V_89 ) ;
V_95 = F_79 ( V_101 , V_15 ) ;
for ( V_103 = V_104 ; V_103 <= V_105 ; ++ V_103 ) {
V_102 = F_75 ( V_15 , V_95 , V_103 ) ;
V_102 -> V_106 += 1 ;
}
V_99 -> V_34 . V_107 ++ ;
}
static void F_80 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
struct V_100 * V_101 ;
struct V_94 * V_95 ;
struct V_93 * V_102 ;
T_2 V_15 ;
int V_103 ;
V_15 = V_48 -> V_15 ;
V_101 = F_78 ( V_99 , V_48 -> V_89 ) ;
V_95 = F_79 ( V_101 , V_15 ) ;
for ( V_103 = V_104 ; V_103 <= V_105 ; ++ V_103 ) {
V_102 = F_75 ( V_15 , V_95 , V_103 ) ;
V_102 -> V_106 -= 1 ;
F_3 ( V_102 -> V_106 < 0 ) ;
}
V_99 -> V_34 . V_107 -- ;
}
static int F_81 ( T_2 V_15 , int V_40 ,
struct V_94 * V_95 )
{
struct V_93 * V_102 ;
if ( V_95 ) {
V_102 = F_75 ( V_15 , V_95 , V_40 ) ;
return V_102 -> V_106 ;
}
return 1 ;
}
static int F_82 ( struct V_11 * V_12 , T_2 V_15 , int V_40 )
{
struct V_94 * V_95 ;
V_95 = F_83 ( V_12 , V_15 ) ;
return F_81 ( V_15 , V_40 , V_95 ) ;
}
static int F_84 ( struct V_99 * V_99 , T_2 V_15 )
{
unsigned long V_108 ;
int V_103 , V_63 = 0 ;
V_108 = F_85 ( V_99 , V_15 ) ;
for ( V_103 = V_41 ; V_103 <= V_105 ; ++ V_103 ) {
if ( V_108 >= F_86 ( V_103 ) )
V_63 = V_103 ;
else
break;
}
return V_63 ;
}
static inline bool F_87 ( struct V_94 * V_95 ,
bool V_109 )
{
if ( ! V_95 || V_95 -> V_110 & V_111 )
return false ;
if ( V_109 && V_95 -> V_112 )
return false ;
return true ;
}
static struct V_94 *
F_88 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_109 )
{
struct V_94 * V_95 ;
V_95 = F_83 ( V_12 , V_15 ) ;
if ( ! F_87 ( V_95 , V_109 ) )
V_95 = NULL ;
return V_95 ;
}
static int F_89 ( struct V_11 * V_12 , T_2 V_113 ,
bool * V_114 )
{
int V_115 , V_40 , V_116 ;
struct V_94 * V_95 ;
if ( F_14 ( * V_114 ) )
return V_41 ;
V_95 = F_83 ( V_12 , V_113 ) ;
* V_114 = ! F_87 ( V_95 , true ) ;
if ( F_14 ( * V_114 ) )
return V_41 ;
V_115 = F_84 ( V_12 -> V_99 , V_113 ) ;
if ( V_115 == V_41 )
return V_115 ;
V_116 = V_71 ( V_117 -> V_118 () , V_115 ) ;
for ( V_40 = V_104 ; V_40 <= V_116 ; ++ V_40 )
if ( F_81 ( V_113 , V_40 , V_95 ) )
break;
return V_40 - 1 ;
}
static int F_90 ( struct V_11 * V_12 , T_1 * V_10 ,
struct V_119 * V_120 )
{
struct V_87 * V_121 ;
int V_103 , V_56 = 0 ;
if ( ! V_120 -> V_122 ) {
F_91 ( L_1 , V_10 , * V_10 ) ;
V_120 -> V_122 = ( unsigned long ) V_10 ;
} else if ( ! ( V_120 -> V_122 & 1 ) ) {
F_91 ( L_2 , V_10 , * V_10 ) ;
V_121 = F_71 ( V_12 ) ;
V_121 -> V_123 [ 0 ] = ( T_1 * ) V_120 -> V_122 ;
V_121 -> V_123 [ 1 ] = V_10 ;
V_120 -> V_122 = ( unsigned long ) V_121 | 1 ;
++ V_56 ;
} else {
F_91 ( L_3 , V_10 , * V_10 ) ;
V_121 = (struct V_87 * ) ( V_120 -> V_122 & ~ 1ul ) ;
while ( V_121 -> V_123 [ V_124 - 1 ] && V_121 -> V_125 ) {
V_121 = V_121 -> V_125 ;
V_56 += V_124 ;
}
if ( V_121 -> V_123 [ V_124 - 1 ] ) {
V_121 -> V_125 = F_71 ( V_12 ) ;
V_121 = V_121 -> V_125 ;
}
for ( V_103 = 0 ; V_121 -> V_123 [ V_103 ] ; ++ V_103 )
++ V_56 ;
V_121 -> V_123 [ V_103 ] = V_10 ;
}
return V_56 ;
}
static void
F_92 ( struct V_119 * V_120 ,
struct V_87 * V_121 , int V_103 ,
struct V_87 * V_126 )
{
int V_127 ;
for ( V_127 = V_124 - 1 ; ! V_121 -> V_123 [ V_127 ] && V_127 > V_103 ; -- V_127 )
;
V_121 -> V_123 [ V_103 ] = V_121 -> V_123 [ V_127 ] ;
V_121 -> V_123 [ V_127 ] = NULL ;
if ( V_127 != 0 )
return;
if ( ! V_126 && ! V_121 -> V_125 )
V_120 -> V_122 = ( unsigned long ) V_121 -> V_123 [ 0 ] ;
else
if ( V_126 )
V_126 -> V_125 = V_121 -> V_125 ;
else
V_120 -> V_122 = ( unsigned long ) V_121 -> V_125 | 1 ;
F_72 ( V_121 ) ;
}
static void F_93 ( T_1 * V_10 , struct V_119 * V_120 )
{
struct V_87 * V_121 ;
struct V_87 * V_126 ;
int V_103 ;
if ( ! V_120 -> V_122 ) {
F_94 ( V_128 L_4 , V_10 ) ;
F_95 () ;
} else if ( ! ( V_120 -> V_122 & 1 ) ) {
F_91 ( L_5 , V_10 ) ;
if ( ( T_1 * ) V_120 -> V_122 != V_10 ) {
F_94 ( V_128 L_6 , V_10 ) ;
F_95 () ;
}
V_120 -> V_122 = 0 ;
} else {
F_91 ( L_7 , V_10 ) ;
V_121 = (struct V_87 * ) ( V_120 -> V_122 & ~ 1ul ) ;
V_126 = NULL ;
while ( V_121 ) {
for ( V_103 = 0 ; V_103 < V_124 && V_121 -> V_123 [ V_103 ] ; ++ V_103 ) {
if ( V_121 -> V_123 [ V_103 ] == V_10 ) {
F_92 ( V_120 ,
V_121 , V_103 , V_126 ) ;
return;
}
}
V_126 = V_121 ;
V_121 = V_121 -> V_125 ;
}
F_96 ( L_8 , V_10 ) ;
F_95 () ;
}
}
static struct V_119 * F_97 ( T_2 V_15 , int V_40 ,
struct V_94 * V_95 )
{
unsigned long V_96 ;
V_96 = F_76 ( V_15 , V_95 -> V_97 , V_40 ) ;
return & V_95 -> V_34 . V_129 [ V_40 - V_41 ] [ V_96 ] ;
}
static struct V_119 * F_98 ( struct V_99 * V_99 , T_2 V_15 ,
struct V_47 * V_48 )
{
struct V_100 * V_101 ;
struct V_94 * V_95 ;
V_101 = F_78 ( V_99 , V_48 -> V_89 ) ;
V_95 = F_79 ( V_101 , V_15 ) ;
return F_97 ( V_15 , V_48 -> V_89 . V_40 , V_95 ) ;
}
static bool F_99 ( struct V_11 * V_12 )
{
struct V_67 * V_68 ;
V_68 = & V_12 -> V_34 . V_80 ;
return F_60 ( V_68 ) ;
}
static int F_100 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
struct V_47 * V_48 ;
struct V_119 * V_120 ;
V_48 = F_34 ( F_35 ( V_10 ) ) ;
F_74 ( V_48 , V_10 - V_48 -> V_130 , V_15 ) ;
V_120 = F_98 ( V_12 -> V_99 , V_15 , V_48 ) ;
return F_90 ( V_12 , V_10 , V_120 ) ;
}
static void F_101 ( struct V_99 * V_99 , T_1 * V_10 )
{
struct V_47 * V_48 ;
T_2 V_15 ;
struct V_119 * V_120 ;
V_48 = F_34 ( F_35 ( V_10 ) ) ;
V_15 = F_73 ( V_48 , V_10 - V_48 -> V_130 ) ;
V_120 = F_98 ( V_99 , V_15 , V_48 ) ;
F_93 ( V_10 , V_120 ) ;
}
static T_1 * F_102 ( struct V_119 * V_120 ,
struct V_131 * V_132 )
{
T_1 * V_14 ;
if ( ! V_120 -> V_122 )
return NULL ;
if ( ! ( V_120 -> V_122 & 1 ) ) {
V_132 -> V_121 = NULL ;
V_14 = ( T_1 * ) V_120 -> V_122 ;
goto V_83;
}
V_132 -> V_121 = (struct V_87 * ) ( V_120 -> V_122 & ~ 1ul ) ;
V_132 -> V_133 = 0 ;
V_14 = V_132 -> V_121 -> V_123 [ V_132 -> V_133 ] ;
V_83:
F_70 ( ! F_22 ( * V_14 ) ) ;
return V_14 ;
}
static T_1 * F_103 ( struct V_131 * V_132 )
{
T_1 * V_14 ;
if ( V_132 -> V_121 ) {
if ( V_132 -> V_133 < V_124 - 1 ) {
++ V_132 -> V_133 ;
V_14 = V_132 -> V_121 -> V_123 [ V_132 -> V_133 ] ;
if ( V_14 )
goto V_83;
}
V_132 -> V_121 = V_132 -> V_121 -> V_125 ;
if ( V_132 -> V_121 ) {
V_132 -> V_133 = 0 ;
V_14 = V_132 -> V_121 -> V_123 [ V_132 -> V_133 ] ;
goto V_83;
}
}
return NULL ;
V_83:
F_70 ( ! F_22 ( * V_14 ) ) ;
return V_14 ;
}
static void F_104 ( struct V_99 * V_99 , T_1 * V_14 )
{
if ( F_46 ( V_14 ) )
F_101 ( V_99 , V_14 ) ;
}
static bool F_105 ( struct V_99 * V_99 , T_1 * V_14 )
{
if ( F_23 ( * V_14 ) ) {
F_3 ( F_34 ( F_35 ( V_14 ) ) -> V_89 . V_40 ==
V_41 ) ;
F_104 ( V_99 , V_14 ) ;
-- V_99 -> V_134 . V_135 ;
return true ;
}
return false ;
}
static void F_106 ( struct V_11 * V_12 , T_1 * V_14 )
{
if ( F_105 ( V_12 -> V_99 , V_14 ) )
F_107 ( V_12 -> V_99 ) ;
}
static bool F_108 ( struct V_99 * V_99 , T_1 * V_14 , bool V_136 )
{
T_1 V_10 = * V_14 ;
if ( ! F_40 ( V_10 ) &&
! ( V_136 && F_38 ( V_10 ) ) )
return false ;
F_91 ( L_9 , V_14 , * V_14 ) ;
if ( V_136 )
V_10 &= ~ V_59 ;
V_10 = V_10 & ~ V_137 ;
return F_43 ( V_14 , V_10 ) ;
}
static bool F_109 ( struct V_99 * V_99 ,
struct V_119 * V_120 ,
bool V_136 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
F_110 (rmap_head, &iter, sptep)
V_138 |= F_108 ( V_99 , V_14 , V_136 ) ;
return V_138 ;
}
static bool F_111 ( struct V_99 * V_99 , T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_91 ( L_10 , V_14 , * V_14 ) ;
V_10 &= ~ V_31 ;
return F_43 ( V_14 , V_10 ) ;
}
static bool F_112 ( struct V_99 * V_99 , struct V_119 * V_120 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
F_110 (rmap_head, &iter, sptep)
V_138 |= F_111 ( V_99 , V_14 ) ;
return V_138 ;
}
static bool F_113 ( struct V_99 * V_99 , T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_91 ( L_11 , V_14 , * V_14 ) ;
V_10 |= V_31 ;
return F_43 ( V_14 , V_10 ) ;
}
static bool F_114 ( struct V_99 * V_99 , struct V_119 * V_120 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
F_110 (rmap_head, &iter, sptep)
V_138 |= F_113 ( V_99 , V_14 ) ;
return V_138 ;
}
static void F_115 ( struct V_99 * V_99 ,
struct V_94 * V_95 ,
T_2 V_139 , unsigned long V_4 )
{
struct V_119 * V_120 ;
while ( V_4 ) {
V_120 = F_97 ( V_95 -> V_97 + V_139 + F_116 ( V_4 ) ,
V_41 , V_95 ) ;
F_109 ( V_99 , V_120 , false ) ;
V_4 &= V_4 - 1 ;
}
}
void F_117 ( struct V_99 * V_99 ,
struct V_94 * V_95 ,
T_2 V_139 , unsigned long V_4 )
{
struct V_119 * V_120 ;
while ( V_4 ) {
V_120 = F_97 ( V_95 -> V_97 + V_139 + F_116 ( V_4 ) ,
V_41 , V_95 ) ;
F_112 ( V_99 , V_120 ) ;
V_4 &= V_4 - 1 ;
}
}
void F_118 ( struct V_99 * V_99 ,
struct V_94 * V_95 ,
T_2 V_139 , unsigned long V_4 )
{
if ( V_117 -> V_140 )
V_117 -> V_140 ( V_99 , V_95 , V_139 ,
V_4 ) ;
else
F_115 ( V_99 , V_95 , V_139 , V_4 ) ;
}
static bool F_119 ( struct V_11 * V_12 , T_1 V_15 )
{
struct V_94 * V_95 ;
struct V_119 * V_120 ;
int V_103 ;
bool V_141 = false ;
V_95 = F_83 ( V_12 , V_15 ) ;
for ( V_103 = V_41 ; V_103 <= V_105 ; ++ V_103 ) {
V_120 = F_97 ( V_15 , V_103 , V_95 ) ;
V_141 |= F_109 ( V_12 -> V_99 , V_120 , true ) ;
}
return V_141 ;
}
static bool F_120 ( struct V_99 * V_99 , struct V_119 * V_120 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
while ( ( V_14 = F_102 ( V_120 , & V_132 ) ) ) {
F_91 ( L_12 , V_142 , V_14 , * V_14 ) ;
F_104 ( V_99 , V_14 ) ;
V_138 = true ;
}
return V_138 ;
}
static int F_121 ( struct V_99 * V_99 , struct V_119 * V_120 ,
struct V_94 * V_95 , T_2 V_15 , int V_40 ,
unsigned long V_143 )
{
return F_120 ( V_99 , V_120 ) ;
}
static int F_122 ( struct V_99 * V_99 , struct V_119 * V_120 ,
struct V_94 * V_95 , T_2 V_15 , int V_40 ,
unsigned long V_143 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
int V_144 = 0 ;
T_1 V_61 ;
T_5 * V_145 = ( T_5 * ) V_143 ;
T_3 V_146 ;
F_3 ( F_123 ( * V_145 ) ) ;
V_146 = F_124 ( * V_145 ) ;
V_147:
F_110 (rmap_head, &iter, sptep) {
F_91 ( L_13 ,
V_14 , * V_14 , V_15 , V_40 ) ;
V_144 = 1 ;
if ( F_125 ( * V_145 ) ) {
F_104 ( V_99 , V_14 ) ;
goto V_147;
} else {
V_61 = * V_14 & ~ V_42 ;
V_61 |= ( T_1 ) V_146 << V_19 ;
V_61 &= ~ V_137 ;
V_61 &= ~ V_58 ;
V_61 &= ~ V_30 ;
F_46 ( V_14 ) ;
F_9 ( V_14 , V_61 ) ;
}
}
if ( V_144 )
F_107 ( V_99 ) ;
return 0 ;
}
static void
F_126 ( struct V_148 * V_149 , int V_40 )
{
V_149 -> V_40 = V_40 ;
V_149 -> V_15 = V_149 -> V_150 ;
V_149 -> V_129 = F_97 ( V_149 -> V_15 , V_40 , V_149 -> V_95 ) ;
V_149 -> V_151 = F_97 ( V_149 -> V_152 , V_40 ,
V_149 -> V_95 ) ;
}
static void
F_127 ( struct V_148 * V_149 ,
struct V_94 * V_95 , int V_153 ,
int V_154 , T_2 V_150 , T_2 V_152 )
{
V_149 -> V_95 = V_95 ;
V_149 -> V_153 = V_153 ;
V_149 -> V_154 = V_154 ;
V_149 -> V_150 = V_150 ;
V_149 -> V_152 = V_152 ;
F_126 ( V_149 , V_149 -> V_153 ) ;
}
static bool F_128 ( struct V_148 * V_149 )
{
return ! ! V_149 -> V_129 ;
}
static void F_129 ( struct V_148 * V_149 )
{
if ( ++ V_149 -> V_129 <= V_149 -> V_151 ) {
V_149 -> V_15 += ( 1UL << F_130 ( V_149 -> V_40 ) ) ;
return;
}
if ( ++ V_149 -> V_40 > V_149 -> V_154 ) {
V_149 -> V_129 = NULL ;
return;
}
F_126 ( V_149 , V_149 -> V_40 ) ;
}
static int F_131 ( struct V_99 * V_99 ,
unsigned long V_155 ,
unsigned long V_156 ,
unsigned long V_143 ,
int (* F_132)( struct V_99 * V_99 ,
struct V_119 * V_120 ,
struct V_94 * V_95 ,
T_2 V_15 ,
int V_40 ,
unsigned long V_143 ) )
{
struct V_100 * V_101 ;
struct V_94 * V_157 ;
struct V_148 V_149 ;
int V_63 = 0 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_158 ; V_103 ++ ) {
V_101 = F_133 ( V_99 , V_103 ) ;
F_134 (memslot, slots) {
unsigned long V_159 , V_160 ;
T_2 V_161 , V_162 ;
V_159 = F_135 ( V_155 , V_157 -> V_163 ) ;
V_160 = V_71 ( V_156 , V_157 -> V_163 +
( V_157 -> V_164 << V_19 ) ) ;
if ( V_159 >= V_160 )
continue;
V_161 = F_136 ( V_159 , V_157 ) ;
V_162 = F_136 ( V_160 + V_165 - 1 , V_157 ) ;
F_137 (memslot, PT_PAGE_TABLE_LEVEL,
PT_MAX_HUGEPAGE_LEVEL,
gfn_start, gfn_end - 1 ,
&iterator)
V_63 |= F_132 ( V_99 , V_149 . V_129 , V_157 ,
V_149 . V_15 , V_149 . V_40 , V_143 ) ;
}
}
return V_63 ;
}
static int F_138 ( struct V_99 * V_99 , unsigned long V_166 ,
unsigned long V_143 ,
int (* F_132)( struct V_99 * V_99 ,
struct V_119 * V_120 ,
struct V_94 * V_95 ,
T_2 V_15 , int V_40 ,
unsigned long V_143 ) )
{
return F_131 ( V_99 , V_166 , V_166 + 1 , V_143 , F_132 ) ;
}
int F_139 ( struct V_99 * V_99 , unsigned long V_166 )
{
return F_138 ( V_99 , V_166 , 0 , F_121 ) ;
}
int F_140 ( struct V_99 * V_99 , unsigned long V_155 , unsigned long V_156 )
{
return F_131 ( V_99 , V_155 , V_156 , 0 , F_121 ) ;
}
void F_141 ( struct V_99 * V_99 , unsigned long V_166 , T_5 V_37 )
{
F_138 ( V_99 , V_166 , ( unsigned long ) & V_37 , F_122 ) ;
}
static int F_142 ( struct V_99 * V_99 , struct V_119 * V_120 ,
struct V_94 * V_95 , T_2 V_15 , int V_40 ,
unsigned long V_143 )
{
T_1 * V_14 ;
struct V_131 V_167 ( V_132 ) ;
int V_168 = 0 ;
F_70 ( ! V_30 ) ;
F_110 (rmap_head, &iter, sptep) {
if ( * V_14 & V_30 ) {
V_168 = 1 ;
F_143 ( ( F_144 ( V_30 ) - 1 ) ,
( unsigned long * ) V_14 ) ;
}
}
F_145 ( V_15 , V_40 , V_95 , V_168 ) ;
return V_168 ;
}
static int F_146 ( struct V_99 * V_99 , struct V_119 * V_120 ,
struct V_94 * V_95 , T_2 V_15 ,
int V_40 , unsigned long V_143 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
int V_168 = 0 ;
if ( ! V_30 )
goto V_83;
F_110 (rmap_head, &iter, sptep) {
if ( * V_14 & V_30 ) {
V_168 = 1 ;
break;
}
}
V_83:
return V_168 ;
}
static void F_147 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
struct V_119 * V_120 ;
struct V_47 * V_48 ;
V_48 = F_34 ( F_35 ( V_10 ) ) ;
V_120 = F_98 ( V_12 -> V_99 , V_15 , V_48 ) ;
F_121 ( V_12 -> V_99 , V_120 , NULL , V_15 , V_48 -> V_89 . V_40 , 0 ) ;
F_107 ( V_12 -> V_99 ) ;
}
int F_148 ( struct V_99 * V_99 , unsigned long V_155 , unsigned long V_156 )
{
if ( ! V_30 ) {
V_99 -> V_169 ++ ;
return F_131 ( V_99 , V_155 , V_156 , 0 ,
F_121 ) ;
}
return F_131 ( V_99 , V_155 , V_156 , 0 , F_142 ) ;
}
int F_149 ( struct V_99 * V_99 , unsigned long V_166 )
{
return F_138 ( V_99 , V_166 , 0 , F_146 ) ;
}
static int F_150 ( T_1 * V_130 )
{
T_1 * V_133 ;
T_1 * V_156 ;
for ( V_133 = V_130 , V_156 = V_133 + V_165 / sizeof( T_1 ) ; V_133 != V_156 ; V_133 ++ )
if ( F_22 ( * V_133 ) ) {
F_94 ( V_128 L_14 , V_142 ,
V_133 , * V_133 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_151 ( struct V_99 * V_99 , int V_170 )
{
V_99 -> V_34 . V_171 += V_170 ;
F_152 ( & V_172 , V_170 ) ;
}
static void F_153 ( struct V_47 * V_48 )
{
F_154 ( ! F_150 ( V_48 -> V_130 ) ) ;
F_155 ( & V_48 -> V_173 ) ;
F_156 ( & V_48 -> V_174 ) ;
F_66 ( ( unsigned long ) V_48 -> V_130 ) ;
if ( ! V_48 -> V_89 . V_90 )
F_66 ( ( unsigned long ) V_48 -> V_91 ) ;
F_62 ( V_85 , V_48 ) ;
}
static unsigned F_157 ( T_2 V_15 )
{
return V_15 & ( ( 1 << V_175 ) - 1 ) ;
}
static void F_158 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_176 )
{
if ( ! V_176 )
return;
F_90 ( V_12 , V_176 , & V_48 -> V_177 ) ;
}
static void F_159 ( struct V_47 * V_48 ,
T_1 * V_176 )
{
F_93 ( V_176 , & V_48 -> V_177 ) ;
}
static void F_160 ( struct V_47 * V_48 ,
T_1 * V_176 )
{
F_159 ( V_48 , V_176 ) ;
F_50 ( V_176 ) ;
}
static struct V_47 * F_161 ( struct V_11 * V_12 , int V_90 )
{
struct V_47 * V_48 ;
V_48 = F_69 ( & V_12 -> V_34 . V_85 ) ;
V_48 -> V_130 = F_69 ( & V_12 -> V_34 . V_84 ) ;
if ( ! V_90 )
V_48 -> V_91 = F_69 ( & V_12 -> V_34 . V_84 ) ;
F_162 ( F_163 ( V_48 -> V_130 ) , ( unsigned long ) V_48 ) ;
F_164 ( & V_48 -> V_174 , & V_12 -> V_99 -> V_34 . V_178 ) ;
F_151 ( V_12 -> V_99 , + 1 ) ;
return V_48 ;
}
static void F_165 ( struct V_47 * V_48 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
F_110 (&sp->parent_ptes, &iter, sptep) {
F_166 ( V_14 ) ;
}
}
static void F_166 ( T_1 * V_10 )
{
struct V_47 * V_48 ;
unsigned int V_88 ;
V_48 = F_34 ( F_35 ( V_10 ) ) ;
V_88 = V_10 - V_48 -> V_130 ;
if ( F_167 ( V_88 , V_48 -> V_179 ) )
return;
if ( V_48 -> V_180 ++ )
return;
F_165 ( V_48 ) ;
}
static int F_168 ( struct V_11 * V_12 ,
struct V_47 * V_48 )
{
return 1 ;
}
static void F_169 ( struct V_11 * V_12 , T_6 V_181 )
{
}
static void F_170 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_10 ,
const void * V_37 )
{
F_3 ( 1 ) ;
}
static int F_171 ( struct V_182 * V_183 , struct V_47 * V_48 ,
int V_96 )
{
int V_103 ;
if ( V_48 -> V_184 )
for ( V_103 = 0 ; V_103 < V_183 -> V_170 ; V_103 ++ )
if ( V_183 -> V_78 [ V_103 ] . V_48 == V_48 )
return 0 ;
V_183 -> V_78 [ V_183 -> V_170 ] . V_48 = V_48 ;
V_183 -> V_78 [ V_183 -> V_170 ] . V_96 = V_96 ;
V_183 -> V_170 ++ ;
return ( V_183 -> V_170 == V_185 ) ;
}
static inline void F_172 ( struct V_47 * V_48 , int V_96 )
{
-- V_48 -> V_180 ;
F_3 ( ( int ) V_48 -> V_180 < 0 ) ;
F_173 ( V_96 , V_48 -> V_179 ) ;
}
static int F_174 ( struct V_47 * V_48 ,
struct V_182 * V_183 )
{
int V_103 , V_63 , V_186 = 0 ;
F_175 (i, sp->unsync_child_bitmap, 512 ) {
struct V_47 * V_187 ;
T_1 V_188 = V_48 -> V_130 [ V_103 ] ;
if ( ! F_22 ( V_188 ) || F_23 ( V_188 ) ) {
F_172 ( V_48 , V_103 ) ;
continue;
}
V_187 = F_34 ( V_188 & V_42 ) ;
if ( V_187 -> V_180 ) {
if ( F_171 ( V_183 , V_187 , V_103 ) )
return - V_189 ;
V_63 = F_174 ( V_187 , V_183 ) ;
if ( ! V_63 ) {
F_172 ( V_48 , V_103 ) ;
continue;
} else if ( V_63 > 0 ) {
V_186 += V_63 ;
} else
return V_63 ;
} else if ( V_187 -> V_184 ) {
V_186 ++ ;
if ( F_171 ( V_183 , V_187 , V_103 ) )
return - V_189 ;
} else
F_172 ( V_48 , V_103 ) ;
}
return V_186 ;
}
static int F_176 ( struct V_47 * V_48 ,
struct V_182 * V_183 )
{
if ( ! V_48 -> V_180 )
return 0 ;
F_171 ( V_183 , V_48 , 0 ) ;
return F_174 ( V_48 , V_183 ) ;
}
static void F_177 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
F_3 ( ! V_48 -> V_184 ) ;
F_178 ( V_48 ) ;
V_48 -> V_184 = 0 ;
-- V_99 -> V_134 . V_190 ;
}
static int F_179 ( struct V_11 * V_12 , struct V_47 * V_48 ,
struct V_191 * V_192 , bool V_193 )
{
if ( V_48 -> V_89 . V_194 != ! ! F_180 ( V_12 ) ) {
F_181 ( V_12 -> V_99 , V_48 , V_192 ) ;
return 1 ;
}
if ( V_193 )
F_177 ( V_12 -> V_99 , V_48 ) ;
if ( V_12 -> V_34 . V_195 . V_196 ( V_12 , V_48 ) ) {
F_181 ( V_12 -> V_99 , V_48 , V_192 ) ;
return 1 ;
}
F_182 ( V_197 , V_12 ) ;
return 0 ;
}
static int F_183 ( struct V_11 * V_12 ,
struct V_47 * V_48 )
{
F_184 ( V_192 ) ;
int V_63 ;
V_63 = F_179 ( V_12 , V_48 , & V_192 , false ) ;
if ( V_63 )
F_185 ( V_12 -> V_99 , & V_192 ) ;
return V_63 ;
}
static void F_186 ( struct V_11 * V_12 , int V_198 ) { }
static void F_187 ( void ) { }
static int F_188 ( struct V_11 * V_12 , struct V_47 * V_48 ,
struct V_191 * V_192 )
{
return F_179 ( V_12 , V_48 , V_192 , true ) ;
}
static void F_189 ( struct V_11 * V_12 , T_2 V_15 )
{
struct V_47 * V_199 ;
F_184 ( V_192 ) ;
bool V_138 = false ;
F_190 (vcpu->kvm, s, gfn) {
if ( ! V_199 -> V_184 )
continue;
F_3 ( V_199 -> V_89 . V_40 != V_41 ) ;
F_177 ( V_12 -> V_99 , V_199 ) ;
if ( ( V_199 -> V_89 . V_194 != ! ! F_180 ( V_12 ) ) ||
( V_12 -> V_34 . V_195 . V_196 ( V_12 , V_199 ) ) ) {
F_181 ( V_12 -> V_99 , V_199 , & V_192 ) ;
continue;
}
V_138 = true ;
}
F_185 ( V_12 -> V_99 , & V_192 ) ;
if ( V_138 )
F_182 ( V_197 , V_12 ) ;
}
static int F_191 ( struct V_182 * V_183 ,
struct V_200 * V_201 ,
int V_103 )
{
int V_202 ;
for ( V_202 = V_103 + 1 ; V_202 < V_183 -> V_170 ; V_202 ++ ) {
struct V_47 * V_48 = V_183 -> V_78 [ V_202 ] . V_48 ;
if ( V_48 -> V_89 . V_40 == V_41 ) {
V_201 -> V_96 [ 0 ] = V_183 -> V_78 [ V_202 ] . V_96 ;
return V_202 ;
}
V_201 -> V_203 [ V_48 -> V_89 . V_40 - 2 ] = V_48 ;
V_201 -> V_96 [ V_48 -> V_89 . V_40 - 1 ] = V_183 -> V_78 [ V_202 ] . V_96 ;
}
return V_202 ;
}
static void F_192 ( struct V_200 * V_201 )
{
struct V_47 * V_48 ;
unsigned int V_40 = 0 ;
do {
unsigned int V_96 = V_201 -> V_96 [ V_40 ] ;
V_48 = V_201 -> V_203 [ V_40 ] ;
if ( ! V_48 )
return;
F_172 ( V_48 , V_96 ) ;
V_40 ++ ;
} while ( V_40 < V_204 - 1 && ! V_48 -> V_180 );
}
static void F_193 ( struct V_47 * V_203 ,
struct V_200 * V_201 ,
struct V_182 * V_183 )
{
V_201 -> V_203 [ V_203 -> V_89 . V_40 - 1 ] = NULL ;
V_183 -> V_170 = 0 ;
}
static void F_194 ( struct V_11 * V_12 ,
struct V_47 * V_203 )
{
int V_103 ;
struct V_47 * V_48 ;
struct V_200 V_201 ;
struct V_182 V_205 ;
F_184 ( V_192 ) ;
F_193 ( V_203 , & V_201 , & V_205 ) ;
while ( F_176 ( V_203 , & V_205 ) ) {
bool V_206 = false ;
F_195 (pages, sp, parents, i)
V_206 |= F_119 ( V_12 , V_48 -> V_15 ) ;
if ( V_206 )
F_107 ( V_12 -> V_99 ) ;
F_195 (pages, sp, parents, i) {
F_188 ( V_12 , V_48 , & V_192 ) ;
F_192 ( & V_201 ) ;
}
F_185 ( V_12 -> V_99 , & V_192 ) ;
F_196 ( & V_12 -> V_99 -> V_207 ) ;
F_193 ( V_203 , & V_201 , & V_205 ) ;
}
}
static void F_197 ( struct V_47 * V_48 )
{
V_48 -> V_208 = 0 ;
}
static void F_198 ( T_1 * V_10 )
{
struct V_47 * V_48 = F_34 ( F_35 ( V_10 ) ) ;
F_197 ( V_48 ) ;
}
static bool F_199 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
return F_14 ( V_48 -> V_209 != V_99 -> V_34 . V_209 ) ;
}
static struct V_47 * F_200 ( struct V_11 * V_12 ,
T_2 V_15 ,
T_6 V_210 ,
unsigned V_40 ,
int V_90 ,
unsigned V_16 )
{
union V_211 V_89 ;
unsigned V_212 ;
struct V_47 * V_48 ;
bool V_213 = false ;
V_89 = V_12 -> V_34 . V_195 . V_214 ;
V_89 . V_40 = V_40 ;
V_89 . V_90 = V_90 ;
if ( V_89 . V_90 )
V_89 . V_194 = 0 ;
V_89 . V_16 = V_16 ;
if ( ! V_12 -> V_34 . V_195 . V_215
&& V_12 -> V_34 . V_195 . V_216 <= V_217 ) {
V_212 = V_210 >> ( V_19 + ( V_218 * V_40 ) ) ;
V_212 &= ( 1 << ( ( V_219 - V_218 ) * V_40 ) ) - 1 ;
V_89 . V_212 = V_212 ;
}
F_201 (vcpu->kvm, sp, gfn) {
if ( F_199 ( V_12 -> V_99 , V_48 ) )
continue;
if ( ! V_213 && V_48 -> V_184 )
V_213 = true ;
if ( V_48 -> V_89 . V_220 != V_89 . V_220 )
continue;
if ( V_48 -> V_184 && F_183 ( V_12 , V_48 ) )
break;
if ( V_48 -> V_180 )
F_182 ( V_221 , V_12 ) ;
F_197 ( V_48 ) ;
F_202 ( V_48 , false ) ;
return V_48 ;
}
++ V_12 -> V_99 -> V_134 . V_222 ;
V_48 = F_161 ( V_12 , V_90 ) ;
V_48 -> V_15 = V_15 ;
V_48 -> V_89 = V_89 ;
F_203 ( & V_48 -> V_173 ,
& V_12 -> V_99 -> V_34 . V_223 [ F_157 ( V_15 ) ] ) ;
if ( ! V_90 ) {
if ( F_119 ( V_12 , V_15 ) )
F_107 ( V_12 -> V_99 ) ;
if ( V_40 > V_41 && V_213 )
F_189 ( V_12 , V_15 ) ;
F_77 ( V_12 -> V_99 , V_48 ) ;
}
V_48 -> V_209 = V_12 -> V_99 -> V_34 . V_209 ;
F_204 ( V_48 -> V_130 ) ;
F_202 ( V_48 , true ) ;
return V_48 ;
}
static void F_205 ( struct V_224 * V_149 ,
struct V_11 * V_12 , T_1 V_225 )
{
V_149 -> V_225 = V_225 ;
V_149 -> V_226 = V_12 -> V_34 . V_195 . V_227 ;
V_149 -> V_40 = V_12 -> V_34 . V_195 . V_228 ;
if ( V_149 -> V_40 == V_204 &&
V_12 -> V_34 . V_195 . V_216 < V_204 &&
! V_12 -> V_34 . V_195 . V_215 )
-- V_149 -> V_40 ;
if ( V_149 -> V_40 == V_229 ) {
V_149 -> V_226
= V_12 -> V_34 . V_195 . V_230 [ ( V_225 >> 30 ) & 3 ] ;
V_149 -> V_226 &= V_42 ;
-- V_149 -> V_40 ;
if ( ! V_149 -> V_226 )
V_149 -> V_40 = 0 ;
}
}
static bool F_206 ( struct V_224 * V_149 )
{
if ( V_149 -> V_40 < V_41 )
return false ;
V_149 -> V_88 = F_207 ( V_149 -> V_225 , V_149 -> V_40 ) ;
V_149 -> V_14 = ( ( T_1 * ) F_208 ( V_149 -> V_226 ) ) + V_149 -> V_88 ;
return true ;
}
static void F_209 ( struct V_224 * V_149 ,
T_1 V_10 )
{
if ( F_24 ( V_10 , V_149 -> V_40 ) ) {
V_149 -> V_40 = 0 ;
return;
}
V_149 -> V_226 = V_10 & V_42 ;
-- V_149 -> V_40 ;
}
static void F_210 ( struct V_224 * V_149 )
{
return F_209 ( V_149 , * V_149 -> V_14 ) ;
}
static void F_211 ( struct V_11 * V_12 , T_1 * V_14 ,
struct V_47 * V_48 )
{
T_1 V_10 ;
F_212 ( V_231 != V_38 ||
V_232 != V_137 ) ;
V_10 = F_35 ( V_48 -> V_130 ) | V_38 | V_137 |
V_29 | V_33 | V_30 ;
F_9 ( V_14 , V_10 ) ;
F_158 ( V_12 , V_48 , V_14 ) ;
if ( V_48 -> V_180 || V_48 -> V_184 )
F_166 ( V_14 ) ;
}
static void F_213 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_233 )
{
if ( F_22 ( * V_14 ) && ! F_23 ( * V_14 ) ) {
struct V_47 * V_187 ;
V_187 = F_34 ( * V_14 & V_42 ) ;
if ( V_187 -> V_89 . V_16 == V_233 )
return;
F_160 ( V_187 , V_14 ) ;
F_107 ( V_12 -> V_99 ) ;
}
}
static bool F_214 ( struct V_99 * V_99 , struct V_47 * V_48 ,
T_1 * V_10 )
{
T_1 V_37 ;
struct V_47 * V_187 ;
V_37 = * V_10 ;
if ( F_22 ( V_37 ) ) {
if ( F_24 ( V_37 , V_48 -> V_89 . V_40 ) ) {
F_104 ( V_99 , V_10 ) ;
if ( F_23 ( V_37 ) )
-- V_99 -> V_134 . V_135 ;
} else {
V_187 = F_34 ( V_37 & V_42 ) ;
F_160 ( V_187 , V_10 ) ;
}
return true ;
}
if ( F_10 ( V_37 ) )
F_50 ( V_10 ) ;
return false ;
}
static void F_215 ( struct V_99 * V_99 ,
struct V_47 * V_48 )
{
unsigned V_103 ;
for ( V_103 = 0 ; V_103 < V_234 ; ++ V_103 )
F_214 ( V_99 , V_48 , V_48 -> V_130 + V_103 ) ;
}
static void F_216 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
while ( ( V_14 = F_102 ( & V_48 -> V_177 , & V_132 ) ) )
F_160 ( V_48 , V_14 ) ;
}
static int F_217 ( struct V_99 * V_99 ,
struct V_47 * V_203 ,
struct V_191 * V_192 )
{
int V_103 , V_235 = 0 ;
struct V_200 V_201 ;
struct V_182 V_205 ;
if ( V_203 -> V_89 . V_40 == V_41 )
return 0 ;
F_193 ( V_203 , & V_201 , & V_205 ) ;
while ( F_176 ( V_203 , & V_205 ) ) {
struct V_47 * V_48 ;
F_195 (pages, sp, parents, i) {
F_181 ( V_99 , V_48 , V_192 ) ;
F_192 ( & V_201 ) ;
V_235 ++ ;
}
F_193 ( V_203 , & V_201 , & V_205 ) ;
}
return V_235 ;
}
static int F_181 ( struct V_99 * V_99 , struct V_47 * V_48 ,
struct V_191 * V_192 )
{
int V_63 ;
F_218 ( V_48 ) ;
++ V_99 -> V_134 . V_236 ;
V_63 = F_217 ( V_99 , V_48 , V_192 ) ;
F_215 ( V_99 , V_48 ) ;
F_216 ( V_99 , V_48 ) ;
if ( ! V_48 -> V_89 . V_237 && ! V_48 -> V_89 . V_90 )
F_80 ( V_99 , V_48 ) ;
if ( V_48 -> V_184 )
F_177 ( V_99 , V_48 ) ;
if ( ! V_48 -> V_238 ) {
V_63 ++ ;
F_219 ( & V_48 -> V_174 , V_192 ) ;
F_151 ( V_99 , - 1 ) ;
} else {
F_219 ( & V_48 -> V_174 , & V_99 -> V_34 . V_178 ) ;
if ( ! V_48 -> V_89 . V_237 && ! F_199 ( V_99 , V_48 ) )
F_220 ( V_99 ) ;
}
V_48 -> V_89 . V_237 = 1 ;
return V_63 ;
}
static void F_185 ( struct V_99 * V_99 ,
struct V_191 * V_192 )
{
struct V_47 * V_48 , * V_239 ;
if ( F_221 ( V_192 ) )
return;
F_54 () ;
F_107 ( V_99 ) ;
F_222 (sp, nsp, invalid_list, link) {
F_3 ( ! V_48 -> V_89 . V_237 || V_48 -> V_238 ) ;
F_153 ( V_48 ) ;
}
}
static bool F_223 ( struct V_99 * V_99 ,
struct V_191 * V_192 )
{
struct V_47 * V_48 ;
if ( F_221 ( & V_99 -> V_34 . V_178 ) )
return false ;
V_48 = F_224 ( V_99 -> V_34 . V_178 . V_240 ,
struct V_47 , V_174 ) ;
F_181 ( V_99 , V_48 , V_192 ) ;
return true ;
}
void F_225 ( struct V_99 * V_99 , unsigned int V_241 )
{
F_184 ( V_192 ) ;
F_226 ( & V_99 -> V_207 ) ;
if ( V_99 -> V_34 . V_171 > V_241 ) {
while ( V_99 -> V_34 . V_171 > V_241 )
if ( ! F_223 ( V_99 , & V_192 ) )
break;
F_185 ( V_99 , & V_192 ) ;
V_241 = V_99 -> V_34 . V_171 ;
}
V_99 -> V_34 . V_242 = V_241 ;
F_227 ( & V_99 -> V_207 ) ;
}
int F_228 ( struct V_99 * V_99 , T_2 V_15 )
{
struct V_47 * V_48 ;
F_184 ( V_192 ) ;
int V_79 ;
F_229 ( L_15 , V_142 , V_15 ) ;
V_79 = 0 ;
F_226 ( & V_99 -> V_207 ) ;
F_190 (kvm, sp, gfn) {
F_229 ( L_16 , V_142 , V_15 ,
V_48 -> V_89 . V_220 ) ;
V_79 = 1 ;
F_181 ( V_99 , V_48 , & V_192 ) ;
}
F_185 ( V_99 , & V_192 ) ;
F_227 ( & V_99 -> V_207 ) ;
return V_79 ;
}
static void F_230 ( struct V_11 * V_12 , struct V_47 * V_48 )
{
F_231 ( V_48 ) ;
++ V_12 -> V_99 -> V_134 . V_190 ;
V_48 -> V_184 = 1 ;
F_165 ( V_48 ) ;
}
static void F_232 ( struct V_11 * V_12 , T_2 V_15 )
{
struct V_47 * V_199 ;
F_190 (vcpu->kvm, s, gfn) {
if ( V_199 -> V_184 )
continue;
F_3 ( V_199 -> V_89 . V_40 != V_41 ) ;
F_230 ( V_12 , V_199 ) ;
}
}
static int F_233 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_243 )
{
struct V_47 * V_199 ;
bool V_244 = false ;
F_190 (vcpu->kvm, s, gfn) {
if ( ! V_243 )
return 1 ;
if ( V_199 -> V_89 . V_40 != V_41 )
return 1 ;
if ( ! V_199 -> V_184 )
V_244 = true ;
}
if ( V_244 )
F_232 ( V_12 , V_15 ) ;
return 0 ;
}
static bool F_234 ( T_3 V_21 )
{
if ( F_235 ( V_21 ) )
return ! F_236 ( V_21 ) && F_237 ( F_49 ( V_21 ) ) ;
return true ;
}
static int F_238 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_245 , int V_40 ,
T_2 V_15 , T_3 V_21 , bool V_246 ,
bool V_243 , bool V_247 )
{
T_1 V_10 ;
int V_63 = 0 ;
if ( F_13 ( V_12 , V_14 , V_15 , V_21 , V_245 ) )
return 0 ;
V_10 = V_38 ;
if ( ! V_246 )
V_10 |= V_30 ;
if ( V_245 & V_248 )
V_10 |= V_33 ;
else
V_10 |= V_32 ;
if ( V_245 & V_18 )
V_10 |= V_29 ;
if ( V_40 > V_41 )
V_10 |= V_39 ;
if ( V_249 )
V_10 |= V_117 -> V_250 ( V_12 , V_15 ,
F_234 ( V_21 ) ) ;
if ( V_247 )
V_10 |= V_58 ;
else
V_245 &= ~ V_17 ;
V_10 |= ( T_1 ) V_21 << V_19 ;
if ( V_245 & V_17 ) {
if ( V_40 > V_41 &&
F_82 ( V_12 , V_15 , V_40 ) )
goto V_251;
V_10 |= V_137 | V_59 ;
if ( ! V_243 && F_40 ( * V_14 ) )
goto V_252;
if ( F_233 ( V_12 , V_15 , V_243 ) ) {
F_229 ( L_17 ,
V_142 , V_15 ) ;
V_63 = 1 ;
V_245 &= ~ V_17 ;
V_10 &= ~ ( V_137 | V_59 ) ;
}
}
if ( V_245 & V_17 ) {
F_239 ( V_12 , V_15 ) ;
V_10 |= V_31 ;
}
V_252:
if ( F_43 ( V_14 , V_10 ) )
F_107 ( V_12 -> V_99 ) ;
V_251:
return V_63 ;
}
static bool F_240 ( struct V_11 * V_12 , T_1 * V_14 , unsigned V_245 ,
int V_253 , int V_40 , T_2 V_15 , T_3 V_21 ,
bool V_246 , bool V_247 )
{
int V_254 = 0 ;
int V_255 ;
bool V_256 = false ;
F_229 ( L_18 , V_142 ,
* V_14 , V_253 , V_15 ) ;
if ( F_22 ( * V_14 ) ) {
if ( V_40 > V_41 &&
! F_23 ( * V_14 ) ) {
struct V_47 * V_187 ;
T_1 V_37 = * V_14 ;
V_187 = F_34 ( V_37 & V_42 ) ;
F_160 ( V_187 , V_14 ) ;
F_107 ( V_12 -> V_99 ) ;
} else if ( V_21 != F_25 ( * V_14 ) ) {
F_229 ( L_19 ,
F_25 ( * V_14 ) , V_21 ) ;
F_104 ( V_12 -> V_99 , V_14 ) ;
F_107 ( V_12 -> V_99 ) ;
} else
V_254 = 1 ;
}
if ( F_238 ( V_12 , V_14 , V_245 , V_40 , V_15 , V_21 , V_246 ,
true , V_247 ) ) {
if ( V_253 )
V_256 = true ;
F_182 ( V_197 , V_12 ) ;
}
if ( F_14 ( F_10 ( * V_14 ) ) )
V_256 = true ;
F_229 ( L_20 , V_142 , * V_14 ) ;
F_229 ( L_21 ,
F_23 ( * V_14 ) ? L_22 : L_23 ,
* V_14 & V_38 ? L_24 : L_25 , V_15 ,
* V_14 , V_14 ) ;
if ( ! V_254 && F_23 ( * V_14 ) )
++ V_12 -> V_99 -> V_134 . V_135 ;
if ( F_22 ( * V_14 ) ) {
if ( ! V_254 ) {
V_255 = F_100 ( V_12 , V_14 , V_15 ) ;
if ( V_255 > V_257 )
F_147 ( V_12 , V_14 , V_15 ) ;
}
}
F_241 ( V_21 ) ;
return V_256 ;
}
static T_3 F_242 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_109 )
{
struct V_94 * V_95 ;
V_95 = F_88 ( V_12 , V_15 , V_109 ) ;
if ( ! V_95 )
return V_258 ;
return F_243 ( V_95 , V_15 ) ;
}
static int F_244 ( struct V_11 * V_12 ,
struct V_47 * V_48 ,
T_1 * V_155 , T_1 * V_156 )
{
struct V_78 * V_205 [ V_82 ] ;
struct V_94 * V_95 ;
unsigned V_16 = V_48 -> V_89 . V_16 ;
int V_103 , V_63 ;
T_2 V_15 ;
V_15 = F_73 ( V_48 , V_155 - V_48 -> V_130 ) ;
V_95 = F_88 ( V_12 , V_15 , V_16 & V_17 ) ;
if ( ! V_95 )
return - 1 ;
V_63 = F_245 ( V_95 , V_15 , V_205 , V_156 - V_155 ) ;
if ( V_63 <= 0 )
return - 1 ;
for ( V_103 = 0 ; V_103 < V_63 ; V_103 ++ , V_15 ++ , V_155 ++ )
F_240 ( V_12 , V_155 , V_16 , 0 , V_48 -> V_89 . V_40 , V_15 ,
F_246 ( V_205 [ V_103 ] ) , true , true ) ;
return 0 ;
}
static void F_247 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_14 )
{
T_1 * V_10 , * V_155 = NULL ;
int V_103 ;
F_3 ( ! V_48 -> V_89 . V_90 ) ;
V_103 = ( V_14 - V_48 -> V_130 ) & ~ ( V_82 - 1 ) ;
V_10 = V_48 -> V_130 + V_103 ;
for ( V_103 = 0 ; V_103 < V_82 ; V_103 ++ , V_10 ++ ) {
if ( F_22 ( * V_10 ) || V_10 == V_14 ) {
if ( ! V_155 )
continue;
if ( F_244 ( V_12 , V_48 , V_155 , V_10 ) < 0 )
break;
V_155 = NULL ;
} else if ( ! V_155 )
V_155 = V_10 ;
}
}
static void F_248 ( struct V_11 * V_12 , T_1 * V_14 )
{
struct V_47 * V_48 ;
if ( ! V_30 )
return;
V_48 = F_34 ( F_35 ( V_14 ) ) ;
if ( V_48 -> V_89 . V_40 > V_41 )
return;
F_247 ( V_12 , V_48 , V_14 ) ;
}
static int F_249 ( struct V_11 * V_12 , int V_259 , int V_260 ,
int V_40 , T_2 V_15 , T_3 V_21 , bool V_261 )
{
struct V_224 V_149 ;
struct V_47 * V_48 ;
int V_256 = 0 ;
T_2 V_262 ;
if ( ! F_250 ( V_12 -> V_34 . V_195 . V_227 ) )
return 0 ;
F_251 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_149 . V_40 == V_40 ) {
V_256 = F_240 ( V_12 , V_149 . V_14 , V_263 ,
V_259 , V_40 , V_15 , V_21 , V_261 ,
V_260 ) ;
F_248 ( V_12 , V_149 . V_14 ) ;
++ V_12 -> V_134 . V_264 ;
break;
}
F_106 ( V_12 , V_149 . V_14 ) ;
if ( ! F_22 ( * V_149 . V_14 ) ) {
T_1 V_265 = V_149 . V_225 ;
V_265 &= F_252 ( V_149 . V_40 ) ;
V_262 = V_265 >> V_19 ;
V_48 = F_200 ( V_12 , V_262 , V_149 . V_225 ,
V_149 . V_40 - 1 , 1 , V_263 ) ;
F_211 ( V_12 , V_149 . V_14 , V_48 ) ;
}
}
return V_256 ;
}
static void F_253 ( unsigned long V_266 , struct V_267 * V_268 )
{
T_7 V_269 ;
V_269 . V_270 = V_271 ;
V_269 . V_272 = 0 ;
V_269 . V_273 = V_274 ;
V_269 . V_275 = ( void V_276 * ) V_266 ;
V_269 . V_277 = V_19 ;
F_254 ( V_271 , & V_269 , V_268 ) ;
}
static int F_255 ( struct V_11 * V_12 , T_2 V_15 , T_3 V_21 )
{
if ( V_21 == V_278 )
return 1 ;
if ( V_21 == V_279 ) {
F_253 ( F_256 ( V_12 , V_15 ) , V_280 ) ;
return 0 ;
}
return - V_281 ;
}
static void F_257 ( struct V_11 * V_12 ,
T_2 * V_282 , T_3 * V_283 ,
int * V_284 )
{
T_3 V_21 = * V_283 ;
T_2 V_15 = * V_282 ;
int V_40 = * V_284 ;
if ( ! F_258 ( V_21 ) && ! F_47 ( V_21 ) &&
V_40 == V_41 &&
F_259 ( F_49 ( V_21 ) ) &&
! F_82 ( V_12 , V_15 , V_104 ) ) {
unsigned long V_4 ;
* V_284 = V_40 = V_104 ;
V_4 = F_260 ( V_40 ) - 1 ;
F_261 ( ( V_15 & V_4 ) != ( V_21 & V_4 ) ) ;
if ( V_21 & V_4 ) {
V_15 &= ~ V_4 ;
* V_282 = V_15 ;
F_241 ( V_21 ) ;
V_21 &= ~ V_4 ;
F_262 ( V_21 ) ;
* V_283 = V_21 ;
}
}
}
static bool F_263 ( struct V_11 * V_12 , T_6 V_181 , T_2 V_15 ,
T_3 V_21 , unsigned V_16 , int * V_285 )
{
bool V_63 = true ;
if ( F_14 ( F_264 ( V_21 ) ) ) {
* V_285 = F_255 ( V_12 , V_15 , V_21 ) ;
goto exit;
}
if ( F_14 ( F_15 ( V_21 ) ) )
F_265 ( V_12 , V_181 , V_15 , V_16 ) ;
V_63 = false ;
exit:
return V_63 ;
}
static bool F_266 ( T_4 V_286 )
{
if ( F_14 ( V_286 & V_287 ) )
return false ;
if ( ! ( V_286 & V_288 ) ||
! ( V_286 & V_289 ) )
return false ;
return true ;
}
static bool
F_267 ( struct V_11 * V_12 , struct V_47 * V_48 ,
T_1 * V_14 , T_1 V_10 )
{
T_2 V_15 ;
F_3 ( ! V_48 -> V_89 . V_90 ) ;
V_15 = F_73 ( V_48 , V_14 - V_48 -> V_130 ) ;
if ( F_268 ( V_14 , V_10 , V_10 | V_137 ) == V_10 )
F_239 ( V_12 , V_15 ) ;
return true ;
}
static bool F_269 ( struct V_11 * V_12 , T_6 V_181 , int V_40 ,
T_4 V_286 )
{
struct V_224 V_149 ;
struct V_47 * V_48 ;
bool V_63 = false ;
T_1 V_10 = 0ull ;
if ( ! F_250 ( V_12 -> V_34 . V_195 . V_227 ) )
return false ;
if ( ! F_266 ( V_286 ) )
return false ;
F_52 ( V_12 ) ;
F_270 (vcpu, gva, iterator, spte)
if ( ! F_22 ( V_10 ) || V_149 . V_40 < V_40 )
break;
if ( ! F_22 ( V_10 ) ) {
V_63 = true ;
goto exit;
}
V_48 = F_34 ( F_35 ( V_149 . V_14 ) ) ;
if ( ! F_24 ( V_10 , V_48 -> V_89 . V_40 ) )
goto exit;
if ( F_40 ( V_10 ) ) {
V_63 = true ;
goto exit;
}
if ( ! F_38 ( V_10 ) )
goto exit;
if ( V_48 -> V_89 . V_40 > V_41 )
goto exit;
V_63 = F_267 ( V_12 , V_48 , V_149 . V_14 , V_10 ) ;
exit:
F_271 ( V_12 , V_181 , V_286 , V_149 . V_14 ,
V_10 , V_63 ) ;
F_55 ( V_12 ) ;
return V_63 ;
}
static int F_272 ( struct V_11 * V_12 , T_6 V_290 , T_4 V_286 ,
T_2 V_15 , bool V_261 )
{
int V_79 ;
int V_40 ;
bool V_114 = false ;
T_3 V_21 ;
unsigned long V_291 ;
bool V_260 , V_259 = V_286 & V_289 ;
V_40 = F_89 ( V_12 , V_15 , & V_114 ) ;
if ( F_18 ( ! V_114 ) ) {
if ( V_40 > V_104 )
V_40 = V_104 ;
V_15 &= ~ ( F_260 ( V_40 ) - 1 ) ;
}
if ( F_269 ( V_12 , V_290 , V_40 , V_286 ) )
return 0 ;
V_291 = V_12 -> V_99 -> V_169 ;
F_37 () ;
if ( F_273 ( V_12 , V_261 , V_15 , V_290 , & V_21 , V_259 , & V_260 ) )
return 0 ;
if ( F_263 ( V_12 , V_290 , V_15 , V_21 , V_263 , & V_79 ) )
return V_79 ;
F_226 ( & V_12 -> V_99 -> V_207 ) ;
if ( F_274 ( V_12 -> V_99 , V_291 ) )
goto V_292;
F_275 ( V_12 ) ;
if ( F_18 ( ! V_114 ) )
F_257 ( V_12 , & V_15 , & V_21 , & V_40 ) ;
V_79 = F_249 ( V_12 , V_259 , V_260 , V_40 , V_15 , V_21 , V_261 ) ;
F_227 ( & V_12 -> V_99 -> V_207 ) ;
return V_79 ;
V_292:
F_227 ( & V_12 -> V_99 -> V_207 ) ;
F_241 ( V_21 ) ;
return 0 ;
}
static void F_276 ( struct V_11 * V_12 )
{
int V_103 ;
struct V_47 * V_48 ;
F_184 ( V_192 ) ;
if ( ! F_250 ( V_12 -> V_34 . V_195 . V_227 ) )
return;
if ( V_12 -> V_34 . V_195 . V_228 == V_204 &&
( V_12 -> V_34 . V_195 . V_216 == V_204 ||
V_12 -> V_34 . V_195 . V_215 ) ) {
T_8 V_293 = V_12 -> V_34 . V_195 . V_227 ;
F_226 ( & V_12 -> V_99 -> V_207 ) ;
V_48 = F_34 ( V_293 ) ;
-- V_48 -> V_238 ;
if ( ! V_48 -> V_238 && V_48 -> V_89 . V_237 ) {
F_181 ( V_12 -> V_99 , V_48 , & V_192 ) ;
F_185 ( V_12 -> V_99 , & V_192 ) ;
}
F_227 ( & V_12 -> V_99 -> V_207 ) ;
V_12 -> V_34 . V_195 . V_227 = V_294 ;
return;
}
F_226 ( & V_12 -> V_99 -> V_207 ) ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_8 V_293 = V_12 -> V_34 . V_195 . V_230 [ V_103 ] ;
if ( V_293 ) {
V_293 &= V_42 ;
V_48 = F_34 ( V_293 ) ;
-- V_48 -> V_238 ;
if ( ! V_48 -> V_238 && V_48 -> V_89 . V_237 )
F_181 ( V_12 -> V_99 , V_48 ,
& V_192 ) ;
}
V_12 -> V_34 . V_195 . V_230 [ V_103 ] = V_294 ;
}
F_185 ( V_12 -> V_99 , & V_192 ) ;
F_227 ( & V_12 -> V_99 -> V_207 ) ;
V_12 -> V_34 . V_195 . V_227 = V_294 ;
}
static int F_277 ( struct V_11 * V_12 , T_2 V_295 )
{
int V_63 = 0 ;
if ( ! F_278 ( V_12 -> V_99 , V_295 ) ) {
F_182 ( V_296 , V_12 ) ;
V_63 = 1 ;
}
return V_63 ;
}
static int F_279 ( struct V_11 * V_12 )
{
struct V_47 * V_48 ;
unsigned V_103 ;
if ( V_12 -> V_34 . V_195 . V_228 == V_204 ) {
F_226 ( & V_12 -> V_99 -> V_207 ) ;
F_275 ( V_12 ) ;
V_48 = F_200 ( V_12 , 0 , 0 , V_204 , 1 , V_263 ) ;
++ V_48 -> V_238 ;
F_227 ( & V_12 -> V_99 -> V_207 ) ;
V_12 -> V_34 . V_195 . V_227 = F_35 ( V_48 -> V_130 ) ;
} else if ( V_12 -> V_34 . V_195 . V_228 == V_229 ) {
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_8 V_293 = V_12 -> V_34 . V_195 . V_230 [ V_103 ] ;
F_154 ( F_250 ( V_293 ) ) ;
F_226 ( & V_12 -> V_99 -> V_207 ) ;
F_275 ( V_12 ) ;
V_48 = F_200 ( V_12 , V_103 << ( 30 - V_19 ) ,
V_103 << 30 , V_217 , 1 , V_263 ) ;
V_293 = F_35 ( V_48 -> V_130 ) ;
++ V_48 -> V_238 ;
F_227 ( & V_12 -> V_99 -> V_207 ) ;
V_12 -> V_34 . V_195 . V_230 [ V_103 ] = V_293 | V_38 ;
}
V_12 -> V_34 . V_195 . V_227 = F_35 ( V_12 -> V_34 . V_195 . V_230 ) ;
} else
F_95 () ;
return 0 ;
}
static int F_280 ( struct V_11 * V_12 )
{
struct V_47 * V_48 ;
T_1 V_297 , V_298 ;
T_2 V_295 ;
int V_103 ;
V_295 = V_12 -> V_34 . V_195 . V_299 ( V_12 ) >> V_19 ;
if ( F_277 ( V_12 , V_295 ) )
return 1 ;
if ( V_12 -> V_34 . V_195 . V_216 == V_204 ) {
T_8 V_293 = V_12 -> V_34 . V_195 . V_227 ;
F_154 ( F_250 ( V_293 ) ) ;
F_226 ( & V_12 -> V_99 -> V_207 ) ;
F_275 ( V_12 ) ;
V_48 = F_200 ( V_12 , V_295 , 0 , V_204 ,
0 , V_263 ) ;
V_293 = F_35 ( V_48 -> V_130 ) ;
++ V_48 -> V_238 ;
F_227 ( & V_12 -> V_99 -> V_207 ) ;
V_12 -> V_34 . V_195 . V_227 = V_293 ;
return 0 ;
}
V_298 = V_38 ;
if ( V_12 -> V_34 . V_195 . V_228 == V_204 )
V_298 |= V_300 | V_137 | V_301 ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_8 V_293 = V_12 -> V_34 . V_195 . V_230 [ V_103 ] ;
F_154 ( F_250 ( V_293 ) ) ;
if ( V_12 -> V_34 . V_195 . V_216 == V_229 ) {
V_297 = V_12 -> V_34 . V_195 . V_302 ( V_12 , V_103 ) ;
if ( ! F_281 ( V_297 ) ) {
V_12 -> V_34 . V_195 . V_230 [ V_103 ] = 0 ;
continue;
}
V_295 = V_297 >> V_19 ;
if ( F_277 ( V_12 , V_295 ) )
return 1 ;
}
F_226 ( & V_12 -> V_99 -> V_207 ) ;
F_275 ( V_12 ) ;
V_48 = F_200 ( V_12 , V_295 , V_103 << 30 , V_217 ,
0 , V_263 ) ;
V_293 = F_35 ( V_48 -> V_130 ) ;
++ V_48 -> V_238 ;
F_227 ( & V_12 -> V_99 -> V_207 ) ;
V_12 -> V_34 . V_195 . V_230 [ V_103 ] = V_293 | V_298 ;
}
V_12 -> V_34 . V_195 . V_227 = F_35 ( V_12 -> V_34 . V_195 . V_230 ) ;
if ( V_12 -> V_34 . V_195 . V_228 == V_204 ) {
if ( V_12 -> V_34 . V_195 . V_303 == NULL ) {
T_1 * V_303 ;
V_303 = ( void * ) F_282 ( V_75 ) ;
if ( V_303 == NULL )
return 1 ;
V_303 [ 0 ] = F_35 ( V_12 -> V_34 . V_195 . V_230 ) | V_298 ;
V_12 -> V_34 . V_195 . V_303 = V_303 ;
}
V_12 -> V_34 . V_195 . V_227 = F_35 ( V_12 -> V_34 . V_195 . V_303 ) ;
}
return 0 ;
}
static int F_283 ( struct V_11 * V_12 )
{
if ( V_12 -> V_34 . V_195 . V_215 )
return F_279 ( V_12 ) ;
else
return F_280 ( V_12 ) ;
}
static void F_284 ( struct V_11 * V_12 )
{
int V_103 ;
struct V_47 * V_48 ;
if ( V_12 -> V_34 . V_195 . V_215 )
return;
if ( ! F_250 ( V_12 -> V_34 . V_195 . V_227 ) )
return;
F_285 ( V_12 , V_304 ) ;
F_186 ( V_12 , V_305 ) ;
if ( V_12 -> V_34 . V_195 . V_216 == V_204 ) {
T_8 V_293 = V_12 -> V_34 . V_195 . V_227 ;
V_48 = F_34 ( V_293 ) ;
F_194 ( V_12 , V_48 ) ;
F_186 ( V_12 , V_306 ) ;
return;
}
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_8 V_293 = V_12 -> V_34 . V_195 . V_230 [ V_103 ] ;
if ( V_293 && F_250 ( V_293 ) ) {
V_293 &= V_42 ;
V_48 = F_34 ( V_293 ) ;
F_194 ( V_12 , V_48 ) ;
}
}
F_186 ( V_12 , V_306 ) ;
}
void F_286 ( struct V_11 * V_12 )
{
F_226 ( & V_12 -> V_99 -> V_207 ) ;
F_284 ( V_12 ) ;
F_227 ( & V_12 -> V_99 -> V_207 ) ;
}
static T_9 F_287 ( struct V_11 * V_12 , T_6 V_307 ,
T_4 V_16 , struct V_308 * V_309 )
{
if ( V_309 )
V_309 -> V_286 = 0 ;
return V_307 ;
}
static T_9 F_288 ( struct V_11 * V_12 , T_6 V_307 ,
T_4 V_16 ,
struct V_308 * V_309 )
{
if ( V_309 )
V_309 -> V_286 = 0 ;
return V_12 -> V_34 . V_310 . V_311 ( V_12 , V_307 , V_16 , V_309 ) ;
}
static bool
F_289 ( struct V_312 * V_313 , T_1 V_37 , int V_40 )
{
int V_314 = ( V_37 >> 7 ) & 1 , V_315 = V_37 & 0x3f ;
return ( V_37 & V_313 -> V_316 [ V_314 ] [ V_40 - 1 ] ) |
( ( V_313 -> V_317 & ( 1ull << V_315 ) ) != 0 ) ;
}
static bool F_290 ( struct V_318 * V_195 , T_1 V_43 , int V_40 )
{
return F_289 ( & V_195 -> V_319 , V_43 , V_40 ) ;
}
static bool F_291 ( struct V_318 * V_195 , T_1 V_10 , int V_40 )
{
return F_289 ( & V_195 -> V_320 , V_10 , V_40 ) ;
}
static bool F_292 ( struct V_11 * V_12 , T_1 V_225 , bool V_90 )
{
if ( V_90 )
return F_293 ( V_12 , V_225 ) ;
return F_294 ( V_12 , V_225 ) ;
}
static bool
F_295 ( struct V_11 * V_12 , T_1 V_225 , T_1 * V_14 )
{
struct V_224 V_149 ;
T_1 V_123 [ V_204 ] , V_10 = 0ull ;
int V_293 , V_321 ;
bool V_322 = false ;
if ( ! F_250 ( V_12 -> V_34 . V_195 . V_227 ) )
goto exit;
F_52 ( V_12 ) ;
for ( F_205 ( & V_149 , V_12 , V_225 ) ,
V_321 = V_293 = V_149 . V_40 ;
F_206 ( & V_149 ) ;
F_209 ( & V_149 , V_10 ) ) {
V_10 = F_51 ( V_149 . V_14 ) ;
V_123 [ V_321 - 1 ] = V_10 ;
V_321 -- ;
if ( ! F_22 ( V_10 ) )
break;
V_322 |= F_291 ( & V_12 -> V_34 . V_195 , V_10 ,
V_149 . V_40 ) ;
}
F_55 ( V_12 ) ;
if ( V_322 ) {
F_96 ( L_26 ,
V_142 , V_225 ) ;
while ( V_293 > V_321 ) {
F_96 ( L_27 ,
V_123 [ V_293 - 1 ] , V_293 ) ;
V_293 -- ;
}
}
exit:
* V_14 = V_10 ;
return V_322 ;
}
int F_296 ( struct V_11 * V_12 , T_1 V_225 , bool V_90 )
{
T_1 V_10 ;
bool V_322 ;
if ( F_292 ( V_12 , V_225 , V_90 ) )
return V_323 ;
V_322 = F_295 ( V_12 , V_225 , & V_10 ) ;
if ( F_3 ( V_322 ) )
return V_324 ;
if ( F_10 ( V_10 ) ) {
T_2 V_15 = F_11 ( V_10 ) ;
unsigned V_16 = F_12 ( V_10 ) ;
if ( ! F_16 ( V_12 , V_10 ) )
return V_325 ;
if ( V_90 )
V_225 = 0 ;
F_297 ( V_225 , V_15 , V_16 ) ;
F_265 ( V_12 , V_225 , V_15 , V_16 ) ;
return V_323 ;
}
return V_326 ;
}
static int F_298 ( struct V_11 * V_12 , T_6 V_181 ,
T_4 V_286 , bool V_261 )
{
T_2 V_15 ;
int V_79 ;
F_229 ( L_28 , V_142 , V_181 , V_286 ) ;
if ( F_14 ( V_286 & V_287 ) ) {
V_79 = F_296 ( V_12 , V_181 , true ) ;
if ( F_18 ( V_79 != V_325 ) )
return V_79 ;
}
V_79 = F_67 ( V_12 ) ;
if ( V_79 )
return V_79 ;
F_154 ( ! F_250 ( V_12 -> V_34 . V_195 . V_227 ) ) ;
V_15 = V_181 >> V_19 ;
return F_272 ( V_12 , V_181 & V_20 ,
V_286 , V_15 , V_261 ) ;
}
static int F_299 ( struct V_11 * V_12 , T_6 V_181 , T_2 V_15 )
{
struct V_327 V_34 ;
V_34 . V_328 = ( V_12 -> V_34 . V_329 . V_330 ++ << 12 ) | V_12 -> V_331 ;
V_34 . V_15 = V_15 ;
V_34 . V_215 = V_12 -> V_34 . V_195 . V_215 ;
V_34 . V_332 = V_12 -> V_34 . V_195 . V_299 ( V_12 ) ;
return F_300 ( V_12 , V_181 , F_256 ( V_12 , V_15 ) , & V_34 ) ;
}
static bool F_301 ( struct V_11 * V_12 )
{
if ( F_14 ( ! F_302 ( V_12 ) ||
F_303 ( V_12 ) ) )
return false ;
return V_117 -> V_333 ( V_12 ) ;
}
static bool F_273 ( struct V_11 * V_12 , bool V_261 , T_2 V_15 ,
T_6 V_181 , T_3 * V_21 , bool V_259 , bool * V_334 )
{
struct V_94 * V_95 ;
bool V_335 ;
V_95 = F_83 ( V_12 , V_15 ) ;
V_335 = false ;
* V_21 = F_304 ( V_95 , V_15 , false , & V_335 , V_259 , V_334 ) ;
if ( ! V_335 )
return false ;
if ( ! V_261 && F_301 ( V_12 ) ) {
F_305 ( V_181 , V_15 ) ;
if ( F_306 ( V_12 , V_15 ) ) {
F_307 ( V_181 , V_15 ) ;
F_182 ( V_336 , V_12 ) ;
return true ;
} else if ( F_299 ( V_12 , V_181 , V_15 ) )
return true ;
}
* V_21 = F_304 ( V_95 , V_15 , false , NULL , V_259 , V_334 ) ;
return false ;
}
static bool
F_308 ( struct V_11 * V_12 , T_2 V_15 , int V_40 )
{
int V_337 = F_260 ( V_40 ) ;
V_15 &= ~ ( V_337 - 1 ) ;
return F_309 ( V_12 , V_15 , V_337 ) ;
}
static int F_310 ( struct V_11 * V_12 , T_6 V_338 , T_4 V_286 ,
bool V_261 )
{
T_3 V_21 ;
int V_79 ;
int V_40 ;
bool V_114 ;
T_2 V_15 = V_338 >> V_19 ;
unsigned long V_291 ;
int V_259 = V_286 & V_289 ;
bool V_260 ;
F_154 ( ! F_250 ( V_12 -> V_34 . V_195 . V_227 ) ) ;
if ( F_14 ( V_286 & V_287 ) ) {
V_79 = F_296 ( V_12 , V_338 , true ) ;
if ( F_18 ( V_79 != V_325 ) )
return V_79 ;
}
V_79 = F_67 ( V_12 ) ;
if ( V_79 )
return V_79 ;
V_114 = ! F_308 ( V_12 , V_15 ,
V_104 ) ;
V_40 = F_89 ( V_12 , V_15 , & V_114 ) ;
if ( F_18 ( ! V_114 ) ) {
if ( V_40 > V_104 &&
! F_308 ( V_12 , V_15 , V_40 ) )
V_40 = V_104 ;
V_15 &= ~ ( F_260 ( V_40 ) - 1 ) ;
}
if ( F_269 ( V_12 , V_338 , V_40 , V_286 ) )
return 0 ;
V_291 = V_12 -> V_99 -> V_169 ;
F_37 () ;
if ( F_273 ( V_12 , V_261 , V_15 , V_338 , & V_21 , V_259 , & V_260 ) )
return 0 ;
if ( F_263 ( V_12 , 0 , V_15 , V_21 , V_263 , & V_79 ) )
return V_79 ;
F_226 ( & V_12 -> V_99 -> V_207 ) ;
if ( F_274 ( V_12 -> V_99 , V_291 ) )
goto V_292;
F_275 ( V_12 ) ;
if ( F_18 ( ! V_114 ) )
F_257 ( V_12 , & V_15 , & V_21 , & V_40 ) ;
V_79 = F_249 ( V_12 , V_259 , V_260 , V_40 , V_15 , V_21 , V_261 ) ;
F_227 ( & V_12 -> V_99 -> V_207 ) ;
return V_79 ;
V_292:
F_227 ( & V_12 -> V_99 -> V_207 ) ;
F_241 ( V_21 ) ;
return 0 ;
}
static void F_311 ( struct V_11 * V_12 ,
struct V_318 * V_339 )
{
V_339 -> V_340 = F_298 ;
V_339 -> V_341 = F_287 ;
V_339 -> V_196 = F_168 ;
V_339 -> V_342 = F_169 ;
V_339 -> V_343 = F_170 ;
V_339 -> V_216 = 0 ;
V_339 -> V_228 = V_229 ;
V_339 -> V_227 = V_294 ;
V_339 -> V_215 = true ;
V_339 -> V_344 = false ;
}
void F_312 ( struct V_11 * V_12 )
{
F_276 ( V_12 ) ;
}
static unsigned long V_299 ( struct V_11 * V_12 )
{
return F_313 ( V_12 ) ;
}
static void F_314 ( struct V_11 * V_12 ,
struct V_308 * V_345 )
{
V_12 -> V_34 . V_195 . F_314 ( V_12 , V_345 ) ;
}
static bool F_315 ( struct V_11 * V_12 , T_1 * V_14 , T_2 V_15 ,
unsigned V_16 , int * V_346 )
{
if ( F_14 ( F_10 ( * V_14 ) ) ) {
if ( V_15 != F_11 ( * V_14 ) ) {
F_50 ( V_14 ) ;
return true ;
}
( * V_346 ) ++ ;
F_7 ( V_12 , V_14 , V_15 , V_16 ) ;
return true ;
}
return false ;
}
static inline bool F_316 ( struct V_318 * V_195 , unsigned V_40 , unsigned V_43 )
{
unsigned V_88 ;
V_88 = V_40 - 1 ;
V_88 |= ( V_43 & V_39 ) >> ( V_347 - 2 ) ;
return V_195 -> V_348 & ( 1 << V_88 ) ;
}
static void
F_317 ( struct V_11 * V_12 ,
struct V_312 * V_313 ,
int V_349 , int V_40 , bool V_344 , bool V_350 ,
bool V_351 , bool V_352 )
{
T_1 V_353 = 0 ;
T_1 V_354 = 0 ;
T_1 V_355 = 0 ;
V_313 -> V_317 = 0 ;
if ( ! V_344 )
V_353 = F_318 ( 63 , 63 ) ;
if ( ! V_350 )
V_354 = F_318 ( 7 , 7 ) ;
if ( V_352 )
V_355 = F_318 ( 8 , 8 ) ;
switch ( V_40 ) {
case V_217 :
V_313 -> V_316 [ 0 ] [ 1 ] = 0 ;
V_313 -> V_316 [ 0 ] [ 0 ] = 0 ;
V_313 -> V_316 [ 1 ] [ 0 ] =
V_313 -> V_316 [ 0 ] [ 0 ] ;
if ( ! V_351 ) {
V_313 -> V_316 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_20 () )
V_313 -> V_316 [ 1 ] [ 1 ] = F_318 ( 17 , 21 ) ;
else
V_313 -> V_316 [ 1 ] [ 1 ] = F_318 ( 13 , 21 ) ;
break;
case V_229 :
V_313 -> V_316 [ 0 ] [ 2 ] =
F_318 ( V_349 , 63 ) |
F_318 ( 5 , 8 ) | F_318 ( 1 , 2 ) ;
V_313 -> V_316 [ 0 ] [ 1 ] = V_353 |
F_318 ( V_349 , 62 ) ;
V_313 -> V_316 [ 0 ] [ 0 ] = V_353 |
F_318 ( V_349 , 62 ) ;
V_313 -> V_316 [ 1 ] [ 1 ] = V_353 |
F_318 ( V_349 , 62 ) |
F_318 ( 13 , 20 ) ;
V_313 -> V_316 [ 1 ] [ 0 ] =
V_313 -> V_316 [ 0 ] [ 0 ] ;
break;
case V_204 :
V_313 -> V_316 [ 0 ] [ 3 ] = V_353 |
V_355 | F_318 ( 7 , 7 ) |
F_318 ( V_349 , 51 ) ;
V_313 -> V_316 [ 0 ] [ 2 ] = V_353 |
V_355 | V_354 |
F_318 ( V_349 , 51 ) ;
V_313 -> V_316 [ 0 ] [ 1 ] = V_353 |
F_318 ( V_349 , 51 ) ;
V_313 -> V_316 [ 0 ] [ 0 ] = V_353 |
F_318 ( V_349 , 51 ) ;
V_313 -> V_316 [ 1 ] [ 3 ] =
V_313 -> V_316 [ 0 ] [ 3 ] ;
V_313 -> V_316 [ 1 ] [ 2 ] = V_353 |
V_354 | F_318 ( V_349 , 51 ) |
F_318 ( 13 , 29 ) ;
V_313 -> V_316 [ 1 ] [ 1 ] = V_353 |
F_318 ( V_349 , 51 ) |
F_318 ( 13 , 20 ) ;
V_313 -> V_316 [ 1 ] [ 0 ] =
V_313 -> V_316 [ 0 ] [ 0 ] ;
break;
}
}
static void F_319 ( struct V_11 * V_12 ,
struct V_318 * V_339 )
{
F_317 ( V_12 , & V_339 -> V_319 ,
F_320 ( V_12 ) , V_339 -> V_216 ,
V_339 -> V_344 , F_321 ( V_12 ) ,
F_322 ( V_12 ) , F_323 ( V_12 ) ) ;
}
static void
F_324 ( struct V_312 * V_313 ,
int V_349 , bool V_356 )
{
T_1 V_317 ;
V_313 -> V_316 [ 0 ] [ 3 ] =
F_318 ( V_349 , 51 ) | F_318 ( 3 , 7 ) ;
V_313 -> V_316 [ 0 ] [ 2 ] =
F_318 ( V_349 , 51 ) | F_318 ( 3 , 6 ) ;
V_313 -> V_316 [ 0 ] [ 1 ] =
F_318 ( V_349 , 51 ) | F_318 ( 3 , 6 ) ;
V_313 -> V_316 [ 0 ] [ 0 ] = F_318 ( V_349 , 51 ) ;
V_313 -> V_316 [ 1 ] [ 3 ] = V_313 -> V_316 [ 0 ] [ 3 ] ;
V_313 -> V_316 [ 1 ] [ 2 ] =
F_318 ( V_349 , 51 ) | F_318 ( 12 , 29 ) ;
V_313 -> V_316 [ 1 ] [ 1 ] =
F_318 ( V_349 , 51 ) | F_318 ( 12 , 20 ) ;
V_313 -> V_316 [ 1 ] [ 0 ] = V_313 -> V_316 [ 0 ] [ 0 ] ;
V_317 = 0xFFull << ( 2 * 8 ) ;
V_317 |= 0xFFull << ( 3 * 8 ) ;
V_317 |= 0xFFull << ( 7 * 8 ) ;
V_317 |= F_325 ( 1ull << 2 ) ;
V_317 |= F_325 ( 1ull << 6 ) ;
if ( ! V_356 ) {
V_317 |= F_325 ( 1ull << 4 ) ;
}
V_313 -> V_317 = V_317 ;
}
static void F_326 ( struct V_11 * V_12 ,
struct V_318 * V_339 , bool V_356 )
{
F_324 ( & V_339 -> V_319 ,
F_320 ( V_12 ) , V_356 ) ;
}
void
F_327 ( struct V_11 * V_12 , struct V_318 * V_339 )
{
bool V_357 = V_339 -> V_344 || V_339 -> V_214 . V_358 ;
F_317 ( V_12 , & V_339 -> V_320 ,
V_359 . V_360 ,
V_339 -> V_228 , V_357 ,
F_321 ( V_12 ) , F_322 ( V_12 ) ,
true ) ;
}
static inline bool F_328 ( void )
{
F_329 ( ! V_249 ) ;
return V_33 == 0 ;
}
static void
F_330 ( struct V_11 * V_12 ,
struct V_318 * V_339 )
{
if ( F_328 () )
F_317 ( V_12 , & V_339 -> V_320 ,
V_359 . V_360 ,
V_339 -> V_228 , false ,
V_361 , true , true ) ;
else
F_324 ( & V_339 -> V_320 ,
V_359 . V_360 ,
false ) ;
}
static void
F_331 ( struct V_11 * V_12 ,
struct V_318 * V_339 , bool V_356 )
{
F_324 ( & V_339 -> V_320 ,
V_359 . V_360 , V_356 ) ;
}
static void F_332 ( struct V_11 * V_12 ,
struct V_318 * V_195 , bool V_362 )
{
unsigned V_363 , V_364 , V_365 ;
T_10 V_366 ;
bool V_345 , V_367 , V_368 , V_369 , V_370 , V_371 , V_372 , V_373 , V_374 , V_375 , V_376 = 0 ;
V_375 = F_333 ( V_12 , V_377 ) ;
V_374 = F_333 ( V_12 , V_378 ) ;
for ( V_364 = 0 ; V_364 < F_58 ( V_195 -> V_379 ) ; ++ V_364 ) {
V_365 = V_364 << 1 ;
V_366 = 0 ;
V_370 = V_365 & V_289 ;
V_371 = V_365 & V_380 ;
V_372 = V_365 & V_381 ;
V_373 = ! ( V_365 & V_287 ) ;
for ( V_363 = 0 ; V_363 < 8 ; ++ V_363 ) {
V_367 = V_363 & V_248 ;
V_368 = V_363 & V_17 ;
V_369 = V_363 & V_18 ;
if ( ! V_362 ) {
V_367 |= ! V_195 -> V_344 ;
V_368 |= ! F_334 ( V_12 ) && ! V_371 ;
V_367 &= ! ( V_375 && V_369 && ! V_371 ) ;
V_376 = V_374 && V_369 && ! V_371 && ! V_372 ;
} else
V_369 = 1 ;
V_345 = ( V_372 && ! V_367 ) || ( V_371 && ! V_369 ) || ( V_370 && ! V_368 ) ||
( V_373 && V_376 ) ;
V_366 |= V_345 << V_363 ;
}
V_195 -> V_379 [ V_364 ] = V_366 ;
}
}
static void F_335 ( struct V_11 * V_12 , struct V_318 * V_195 )
{
T_10 V_366 ;
unsigned V_40 , V_216 = V_195 -> V_216 ;
const unsigned V_382 = 1 << 2 ;
if ( V_216 == V_229 )
-- V_216 ;
V_366 = 1 | ( 1 << V_382 ) ;
for ( V_40 = V_104 ; V_40 <= V_216 ; ++ V_40 ) {
if ( V_40 <= V_383
&& ( V_195 -> V_216 >= V_229 || F_322 ( V_12 ) ) )
V_366 |= 1 << ( V_382 | ( V_40 - 1 ) ) ;
}
V_195 -> V_348 = V_366 ;
}
static void F_336 ( struct V_11 * V_12 ,
struct V_318 * V_339 ,
int V_40 )
{
V_339 -> V_344 = F_21 ( V_12 ) ;
V_339 -> V_216 = V_40 ;
F_319 ( V_12 , V_339 ) ;
F_332 ( V_12 , V_339 , false ) ;
F_335 ( V_12 , V_339 ) ;
F_154 ( ! F_180 ( V_12 ) ) ;
V_339 -> V_340 = V_384 ;
V_339 -> V_341 = V_385 ;
V_339 -> V_196 = V_386 ;
V_339 -> V_342 = V_387 ;
V_339 -> V_343 = V_388 ;
V_339 -> V_228 = V_40 ;
V_339 -> V_227 = V_294 ;
V_339 -> V_215 = false ;
}
static void F_337 ( struct V_11 * V_12 ,
struct V_318 * V_339 )
{
F_336 ( V_12 , V_339 , V_204 ) ;
}
static void F_338 ( struct V_11 * V_12 ,
struct V_318 * V_339 )
{
V_339 -> V_344 = false ;
V_339 -> V_216 = V_217 ;
F_319 ( V_12 , V_339 ) ;
F_332 ( V_12 , V_339 , false ) ;
F_335 ( V_12 , V_339 ) ;
V_339 -> V_340 = V_389 ;
V_339 -> V_341 = V_390 ;
V_339 -> V_196 = V_391 ;
V_339 -> V_342 = V_392 ;
V_339 -> V_343 = V_393 ;
V_339 -> V_228 = V_229 ;
V_339 -> V_227 = V_294 ;
V_339 -> V_215 = false ;
}
static void F_339 ( struct V_11 * V_12 ,
struct V_318 * V_339 )
{
F_336 ( V_12 , V_339 , V_229 ) ;
}
static void F_340 ( struct V_11 * V_12 )
{
struct V_318 * V_339 = & V_12 -> V_34 . V_195 ;
V_339 -> V_214 . V_220 = 0 ;
V_339 -> V_214 . V_394 = F_341 ( V_12 ) ;
V_339 -> V_340 = F_310 ;
V_339 -> V_196 = F_168 ;
V_339 -> V_342 = F_169 ;
V_339 -> V_343 = F_170 ;
V_339 -> V_228 = V_117 -> V_395 () ;
V_339 -> V_227 = V_294 ;
V_339 -> V_215 = true ;
V_339 -> V_396 = V_117 -> V_397 ;
V_339 -> V_299 = V_299 ;
V_339 -> V_302 = V_398 ;
V_339 -> F_314 = V_399 ;
if ( ! F_342 ( V_12 ) ) {
V_339 -> V_344 = false ;
V_339 -> V_341 = F_287 ;
V_339 -> V_216 = 0 ;
} else if ( F_343 ( V_12 ) ) {
V_339 -> V_344 = F_21 ( V_12 ) ;
V_339 -> V_216 = V_204 ;
F_319 ( V_12 , V_339 ) ;
V_339 -> V_341 = V_385 ;
} else if ( F_180 ( V_12 ) ) {
V_339 -> V_344 = F_21 ( V_12 ) ;
V_339 -> V_216 = V_229 ;
F_319 ( V_12 , V_339 ) ;
V_339 -> V_341 = V_385 ;
} else {
V_339 -> V_344 = false ;
V_339 -> V_216 = V_217 ;
F_319 ( V_12 , V_339 ) ;
V_339 -> V_341 = V_390 ;
}
F_332 ( V_12 , V_339 , false ) ;
F_335 ( V_12 , V_339 ) ;
F_330 ( V_12 , V_339 ) ;
}
void F_344 ( struct V_11 * V_12 )
{
bool V_400 = F_333 ( V_12 , V_377 ) ;
bool V_376 = F_333 ( V_12 , V_378 ) ;
struct V_318 * V_339 = & V_12 -> V_34 . V_195 ;
F_154 ( F_250 ( V_339 -> V_227 ) ) ;
if ( ! F_342 ( V_12 ) )
F_311 ( V_12 , V_339 ) ;
else if ( F_343 ( V_12 ) )
F_337 ( V_12 , V_339 ) ;
else if ( F_180 ( V_12 ) )
F_339 ( V_12 , V_339 ) ;
else
F_338 ( V_12 , V_339 ) ;
V_339 -> V_214 . V_401 = F_21 ( V_12 ) ;
V_339 -> V_214 . V_194 = ! ! F_180 ( V_12 ) ;
V_339 -> V_214 . V_402 = F_334 ( V_12 ) ;
V_339 -> V_214 . V_358
= V_400 && ! F_334 ( V_12 ) ;
V_339 -> V_214 . V_403
= V_376 && ! F_334 ( V_12 ) ;
V_339 -> V_214 . V_394 = F_341 ( V_12 ) ;
F_327 ( V_12 , V_339 ) ;
}
void F_345 ( struct V_11 * V_12 , bool V_356 )
{
struct V_318 * V_339 = & V_12 -> V_34 . V_195 ;
F_154 ( F_250 ( V_339 -> V_227 ) ) ;
V_339 -> V_228 = V_117 -> V_395 () ;
V_339 -> V_344 = true ;
V_339 -> V_340 = V_404 ;
V_339 -> V_341 = V_405 ;
V_339 -> V_196 = V_406 ;
V_339 -> V_342 = V_407 ;
V_339 -> V_343 = V_408 ;
V_339 -> V_216 = V_339 -> V_228 ;
V_339 -> V_227 = V_294 ;
V_339 -> V_215 = false ;
F_332 ( V_12 , V_339 , true ) ;
F_326 ( V_12 , V_339 , V_356 ) ;
F_331 ( V_12 , V_339 , V_356 ) ;
}
static void F_346 ( struct V_11 * V_12 )
{
struct V_318 * V_339 = & V_12 -> V_34 . V_195 ;
F_344 ( V_12 ) ;
V_339 -> V_396 = V_117 -> V_396 ;
V_339 -> V_299 = V_299 ;
V_339 -> V_302 = V_398 ;
V_339 -> F_314 = V_399 ;
}
static void F_347 ( struct V_11 * V_12 )
{
struct V_318 * V_409 = & V_12 -> V_34 . V_310 ;
V_409 -> V_299 = V_299 ;
V_409 -> V_302 = V_398 ;
V_409 -> F_314 = V_399 ;
if ( ! F_342 ( V_12 ) ) {
V_409 -> V_344 = false ;
V_409 -> V_216 = 0 ;
V_409 -> V_341 = F_288 ;
} else if ( F_343 ( V_12 ) ) {
V_409 -> V_344 = F_21 ( V_12 ) ;
V_409 -> V_216 = V_204 ;
F_319 ( V_12 , V_409 ) ;
V_409 -> V_341 = V_410 ;
} else if ( F_180 ( V_12 ) ) {
V_409 -> V_344 = F_21 ( V_12 ) ;
V_409 -> V_216 = V_229 ;
F_319 ( V_12 , V_409 ) ;
V_409 -> V_341 = V_410 ;
} else {
V_409 -> V_344 = false ;
V_409 -> V_216 = V_217 ;
F_319 ( V_12 , V_409 ) ;
V_409 -> V_341 = V_411 ;
}
F_332 ( V_12 , V_409 , false ) ;
F_335 ( V_12 , V_409 ) ;
}
static void F_348 ( struct V_11 * V_12 )
{
if ( F_349 ( V_12 ) )
F_347 ( V_12 ) ;
else if ( V_249 )
F_340 ( V_12 ) ;
else
F_346 ( V_12 ) ;
}
void F_350 ( struct V_11 * V_12 )
{
F_351 ( V_12 ) ;
F_348 ( V_12 ) ;
}
int F_352 ( struct V_11 * V_12 )
{
int V_79 ;
V_79 = F_67 ( V_12 ) ;
if ( V_79 )
goto V_83;
V_79 = F_283 ( V_12 ) ;
F_286 ( V_12 ) ;
if ( V_79 )
goto V_83;
V_12 -> V_34 . V_195 . V_396 ( V_12 , V_12 -> V_34 . V_195 . V_227 ) ;
V_83:
return V_79 ;
}
void F_351 ( struct V_11 * V_12 )
{
F_276 ( V_12 ) ;
F_3 ( F_250 ( V_12 -> V_34 . V_195 . V_227 ) ) ;
}
static void F_353 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_10 ,
const void * V_412 )
{
if ( V_48 -> V_89 . V_40 != V_41 ) {
++ V_12 -> V_99 -> V_134 . V_413 ;
return;
}
++ V_12 -> V_99 -> V_134 . V_414 ;
V_12 -> V_34 . V_195 . V_343 ( V_12 , V_48 , V_10 , V_412 ) ;
}
static bool F_354 ( T_1 V_415 , T_1 V_412 )
{
if ( ! F_22 ( V_415 ) )
return false ;
if ( ! F_22 ( V_412 ) )
return true ;
if ( ( V_415 ^ V_412 ) & V_42 )
return true ;
V_415 ^= V_32 ;
V_412 ^= V_32 ;
return ( V_415 & ~ V_412 & V_416 ) != 0 ;
}
static void F_355 ( struct V_11 * V_12 , bool V_417 ,
bool V_418 , bool V_419 )
{
if ( V_417 )
return;
if ( V_418 )
F_107 ( V_12 -> V_99 ) ;
else if ( V_419 )
F_182 ( V_197 , V_12 ) ;
}
static T_1 F_356 ( struct V_11 * V_12 , T_9 * V_338 ,
const T_10 * V_412 , int * V_420 )
{
T_1 V_421 ;
int V_79 ;
if ( F_180 ( V_12 ) && * V_420 == 4 ) {
* V_338 &= ~ ( T_9 ) 7 ;
* V_420 = 8 ;
V_79 = F_357 ( V_12 , * V_338 , & V_421 , 8 ) ;
if ( V_79 )
V_421 = 0 ;
V_412 = ( const T_10 * ) & V_421 ;
}
switch ( * V_420 ) {
case 4 :
V_421 = * ( const T_4 * ) V_412 ;
break;
case 8 :
V_421 = * ( const T_1 * ) V_412 ;
break;
default:
V_421 = 0 ;
break;
}
return V_421 ;
}
static bool F_358 ( struct V_47 * V_48 )
{
if ( V_48 -> V_89 . V_40 == V_41 )
return false ;
return ++ V_48 -> V_208 >= 3 ;
}
static bool F_359 ( struct V_47 * V_48 , T_9 V_338 ,
int V_420 )
{
unsigned V_422 , V_423 , V_424 ;
F_229 ( L_29 ,
V_338 , V_420 , V_48 -> V_89 . V_220 ) ;
V_422 = F_360 ( V_338 ) ;
V_423 = V_48 -> V_89 . V_194 ? 8 : 4 ;
if ( ! ( V_422 & ( V_423 - 1 ) ) && V_420 == 1 )
return false ;
V_424 = ( V_422 ^ ( V_422 + V_420 - 1 ) ) & ~ ( V_423 - 1 ) ;
V_424 |= V_420 < 4 ;
return V_424 ;
}
static T_1 * F_361 ( struct V_47 * V_48 , T_9 V_338 , int * V_425 )
{
unsigned V_426 , V_212 ;
T_1 * V_10 ;
int V_40 ;
V_426 = F_360 ( V_338 ) ;
V_40 = V_48 -> V_89 . V_40 ;
* V_425 = 1 ;
if ( ! V_48 -> V_89 . V_194 ) {
V_426 <<= 1 ;
if ( V_40 == V_217 ) {
V_426 &= ~ 7 ;
V_426 <<= 1 ;
* V_425 = 2 ;
}
V_212 = V_426 >> V_19 ;
V_426 &= ~ V_20 ;
if ( V_212 != V_48 -> V_89 . V_212 )
return NULL ;
}
V_10 = & V_48 -> V_130 [ V_426 / sizeof( * V_10 ) ] ;
return V_10 ;
}
void F_362 ( struct V_11 * V_12 , T_9 V_338 ,
const T_10 * V_412 , int V_420 )
{
T_2 V_15 = V_338 >> V_19 ;
struct V_47 * V_48 ;
F_184 ( V_192 ) ;
T_1 V_427 , V_421 , * V_10 ;
int V_428 ;
bool V_418 , V_419 , V_417 ;
union V_211 V_4 = { } ;
V_4 . V_402 = 1 ;
V_4 . V_194 = 1 ;
V_4 . V_401 = 1 ;
V_4 . V_358 = 1 ;
V_4 . V_403 = 1 ;
V_4 . V_394 = 1 ;
if ( ! F_32 ( V_12 -> V_99 -> V_34 . V_107 ) )
return;
V_417 = V_418 = V_419 = false ;
F_229 ( L_30 , V_142 , V_338 , V_420 ) ;
V_421 = F_356 ( V_12 , & V_338 , V_412 , & V_420 ) ;
F_67 ( V_12 ) ;
F_226 ( & V_12 -> V_99 -> V_207 ) ;
++ V_12 -> V_99 -> V_134 . V_429 ;
F_186 ( V_12 , V_430 ) ;
F_190 (vcpu->kvm, sp, gfn) {
if ( F_359 ( V_48 , V_338 , V_420 ) ||
F_358 ( V_48 ) ) {
V_417 |= ! ! F_181 ( V_12 -> V_99 , V_48 ,
& V_192 ) ;
++ V_12 -> V_99 -> V_134 . V_431 ;
continue;
}
V_10 = F_361 ( V_48 , V_338 , & V_428 ) ;
if ( ! V_10 )
continue;
V_419 = true ;
while ( V_428 -- ) {
V_427 = * V_10 ;
F_214 ( V_12 -> V_99 , V_48 , V_10 ) ;
if ( V_421 &&
! ( ( V_48 -> V_89 . V_220 ^ V_12 -> V_34 . V_195 . V_214 . V_220 )
& V_4 . V_220 ) && F_99 ( V_12 ) )
F_353 ( V_12 , V_48 , V_10 , & V_421 ) ;
if ( F_354 ( V_427 , * V_10 ) )
V_418 = true ;
++ V_10 ;
}
}
F_355 ( V_12 , V_417 , V_418 , V_419 ) ;
F_185 ( V_12 -> V_99 , & V_192 ) ;
F_186 ( V_12 , V_432 ) ;
F_227 ( & V_12 -> V_99 -> V_207 ) ;
}
int F_363 ( struct V_11 * V_12 , T_6 V_181 )
{
T_9 V_338 ;
int V_79 ;
if ( V_12 -> V_34 . V_195 . V_215 )
return 0 ;
V_338 = F_364 ( V_12 , V_181 , NULL ) ;
V_79 = F_228 ( V_12 -> V_99 , V_338 >> V_19 ) ;
return V_79 ;
}
static void F_275 ( struct V_11 * V_12 )
{
F_184 ( V_192 ) ;
if ( F_18 ( F_365 ( V_12 -> V_99 ) >= V_433 ) )
return;
while ( F_365 ( V_12 -> V_99 ) < V_434 ) {
if ( ! F_223 ( V_12 -> V_99 , & V_192 ) )
break;
++ V_12 -> V_99 -> V_134 . V_435 ;
}
F_185 ( V_12 -> V_99 , & V_192 ) ;
}
static bool F_366 ( struct V_11 * V_12 , T_6 V_225 )
{
if ( V_12 -> V_34 . V_195 . V_215 || F_349 ( V_12 ) )
return F_293 ( V_12 , V_225 ) ;
return F_294 ( V_12 , V_225 ) ;
}
int F_367 ( struct V_11 * V_12 , T_6 V_436 , T_4 V_286 ,
void * V_437 , int V_438 )
{
int V_79 , V_439 = V_440 ;
enum V_441 V_442 ;
V_79 = V_12 -> V_34 . V_195 . V_340 ( V_12 , V_436 , V_286 , false ) ;
if ( V_79 < 0 )
goto V_83;
if ( ! V_79 ) {
V_79 = 1 ;
goto V_83;
}
if ( F_366 ( V_12 , V_436 ) )
V_439 = 0 ;
V_442 = F_368 ( V_12 , V_436 , V_439 , V_437 , V_438 ) ;
switch ( V_442 ) {
case V_443 :
return 1 ;
case V_444 :
++ V_12 -> V_134 . V_445 ;
case V_446 :
return 0 ;
default:
F_95 () ;
}
V_83:
return V_79 ;
}
void F_369 ( struct V_11 * V_12 , T_6 V_181 )
{
V_12 -> V_34 . V_195 . V_342 ( V_12 , V_181 ) ;
F_182 ( V_197 , V_12 ) ;
++ V_12 -> V_134 . V_342 ;
}
void F_370 ( void )
{
V_249 = true ;
}
void F_371 ( void )
{
V_249 = false ;
}
static void F_372 ( struct V_11 * V_12 )
{
F_66 ( ( unsigned long ) V_12 -> V_34 . V_195 . V_230 ) ;
if ( V_12 -> V_34 . V_195 . V_303 != NULL )
F_66 ( ( unsigned long ) V_12 -> V_34 . V_195 . V_303 ) ;
}
static int F_373 ( struct V_11 * V_12 )
{
struct V_78 * V_78 ;
int V_103 ;
V_78 = F_374 ( V_75 | V_447 ) ;
if ( ! V_78 )
return - V_76 ;
V_12 -> V_34 . V_195 . V_230 = F_375 ( V_78 ) ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 )
V_12 -> V_34 . V_195 . V_230 [ V_103 ] = V_294 ;
return 0 ;
}
int F_376 ( struct V_11 * V_12 )
{
V_12 -> V_34 . V_448 = & V_12 -> V_34 . V_195 ;
V_12 -> V_34 . V_195 . V_227 = V_294 ;
V_12 -> V_34 . V_195 . V_311 = V_311 ;
V_12 -> V_34 . V_310 . V_311 = V_449 ;
return F_373 ( V_12 ) ;
}
void F_377 ( struct V_11 * V_12 )
{
F_154 ( F_250 ( V_12 -> V_34 . V_195 . V_227 ) ) ;
F_348 ( V_12 ) ;
}
static bool
F_378 ( struct V_99 * V_99 , struct V_94 * V_157 ,
T_11 V_450 , int V_153 , int V_154 ,
T_2 V_150 , T_2 V_152 , bool V_451 )
{
struct V_148 V_149 ;
bool V_138 = false ;
F_137 (memslot, start_level, end_level, start_gfn,
end_gfn, &iterator) {
if ( V_149 . V_129 )
V_138 |= V_450 ( V_99 , V_149 . V_129 ) ;
if ( F_379 () || F_380 ( & V_99 -> V_207 ) ) {
if ( V_138 && V_451 ) {
F_107 ( V_99 ) ;
V_138 = false ;
}
F_196 ( & V_99 -> V_207 ) ;
}
}
if ( V_138 && V_451 ) {
F_107 ( V_99 ) ;
V_138 = false ;
}
return V_138 ;
}
static bool
F_381 ( struct V_99 * V_99 , struct V_94 * V_157 ,
T_11 V_450 , int V_153 , int V_154 ,
bool V_451 )
{
return F_378 ( V_99 , V_157 , V_450 , V_153 ,
V_154 , V_157 -> V_97 ,
V_157 -> V_97 + V_157 -> V_164 - 1 ,
V_451 ) ;
}
static bool
F_382 ( struct V_99 * V_99 , struct V_94 * V_157 ,
T_11 V_450 , bool V_451 )
{
return F_381 ( V_99 , V_157 , V_450 , V_41 ,
V_105 , V_451 ) ;
}
static bool
F_383 ( struct V_99 * V_99 , struct V_94 * V_157 ,
T_11 V_450 , bool V_451 )
{
return F_381 ( V_99 , V_157 , V_450 , V_41 + 1 ,
V_105 , V_451 ) ;
}
static bool
F_384 ( struct V_99 * V_99 , struct V_94 * V_157 ,
T_11 V_450 , bool V_451 )
{
return F_381 ( V_99 , V_157 , V_450 , V_41 ,
V_41 , V_451 ) ;
}
void F_385 ( struct V_99 * V_99 , T_2 V_161 , T_2 V_162 )
{
struct V_100 * V_101 ;
struct V_94 * V_157 ;
int V_103 ;
F_226 ( & V_99 -> V_207 ) ;
for ( V_103 = 0 ; V_103 < V_158 ; V_103 ++ ) {
V_101 = F_133 ( V_99 , V_103 ) ;
F_134 (memslot, slots) {
T_2 V_155 , V_156 ;
V_155 = F_135 ( V_161 , V_157 -> V_97 ) ;
V_156 = V_71 ( V_162 , V_157 -> V_97 + V_157 -> V_164 ) ;
if ( V_155 >= V_156 )
continue;
F_378 ( V_99 , V_157 , F_120 ,
V_41 , V_105 ,
V_155 , V_156 - 1 , true ) ;
}
}
F_227 ( & V_99 -> V_207 ) ;
}
static bool F_386 ( struct V_99 * V_99 ,
struct V_119 * V_120 )
{
return F_109 ( V_99 , V_120 , false ) ;
}
void F_387 ( struct V_99 * V_99 ,
struct V_94 * V_157 )
{
bool V_138 ;
F_226 ( & V_99 -> V_207 ) ;
V_138 = F_382 ( V_99 , V_157 , F_386 ,
false ) ;
F_227 ( & V_99 -> V_207 ) ;
F_388 ( & V_99 -> V_452 ) ;
if ( V_138 )
F_107 ( V_99 ) ;
}
static bool F_389 ( struct V_99 * V_99 ,
struct V_119 * V_120 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
int V_453 = 0 ;
T_3 V_21 ;
struct V_47 * V_48 ;
V_147:
F_110 (rmap_head, &iter, sptep) {
V_48 = F_34 ( F_35 ( V_14 ) ) ;
V_21 = F_25 ( * V_14 ) ;
if ( V_48 -> V_89 . V_90 &&
! F_47 ( V_21 ) &&
F_259 ( F_49 ( V_21 ) ) ) {
F_104 ( V_99 , V_14 ) ;
V_453 = 1 ;
goto V_147;
}
}
return V_453 ;
}
void F_390 ( struct V_99 * V_99 ,
const struct V_94 * V_157 )
{
F_226 ( & V_99 -> V_207 ) ;
F_384 ( V_99 , (struct V_94 * ) V_157 ,
F_389 , true ) ;
F_227 ( & V_99 -> V_207 ) ;
}
void F_391 ( struct V_99 * V_99 ,
struct V_94 * V_157 )
{
bool V_138 ;
F_226 ( & V_99 -> V_207 ) ;
V_138 = F_384 ( V_99 , V_157 , F_112 , false ) ;
F_227 ( & V_99 -> V_207 ) ;
F_388 ( & V_99 -> V_452 ) ;
if ( V_138 )
F_107 ( V_99 ) ;
}
void F_392 ( struct V_99 * V_99 ,
struct V_94 * V_157 )
{
bool V_138 ;
F_226 ( & V_99 -> V_207 ) ;
V_138 = F_383 ( V_99 , V_157 , F_386 ,
false ) ;
F_227 ( & V_99 -> V_207 ) ;
F_388 ( & V_99 -> V_452 ) ;
if ( V_138 )
F_107 ( V_99 ) ;
}
void F_393 ( struct V_99 * V_99 ,
struct V_94 * V_157 )
{
bool V_138 ;
F_226 ( & V_99 -> V_207 ) ;
V_138 = F_382 ( V_99 , V_157 , F_114 , false ) ;
F_227 ( & V_99 -> V_207 ) ;
F_388 ( & V_99 -> V_452 ) ;
if ( V_138 )
F_107 ( V_99 ) ;
}
static void F_394 ( struct V_99 * V_99 )
{
struct V_47 * V_48 , * V_454 ;
int V_455 = 0 ;
V_147:
F_395 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_63 ;
if ( ! F_199 ( V_99 , V_48 ) )
break;
if ( V_48 -> V_89 . V_237 )
continue;
if ( V_455 >= V_456 &&
F_196 ( & V_99 -> V_207 ) ) {
V_455 = 0 ;
goto V_147;
}
V_63 = F_181 ( V_99 , V_48 ,
& V_99 -> V_34 . V_457 ) ;
V_455 += V_63 ;
if ( V_63 )
goto V_147;
}
F_185 ( V_99 , & V_99 -> V_34 . V_457 ) ;
}
void F_396 ( struct V_99 * V_99 )
{
F_226 ( & V_99 -> V_207 ) ;
F_397 ( V_99 ) ;
V_99 -> V_34 . V_209 ++ ;
F_220 ( V_99 ) ;
F_394 ( V_99 ) ;
F_227 ( & V_99 -> V_207 ) ;
}
static bool F_398 ( struct V_99 * V_99 )
{
return F_14 ( ! F_399 ( & V_99 -> V_34 . V_457 ) ) ;
}
void F_400 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
if ( F_14 ( ( V_101 -> V_13 & V_5 ) == 0 ) ) {
F_401 ( V_458 L_31 ) ;
F_396 ( V_99 ) ;
}
}
static unsigned long
F_402 ( struct V_459 * V_460 , struct V_461 * V_462 )
{
struct V_99 * V_99 ;
int V_463 = V_462 -> V_463 ;
unsigned long V_464 = 0 ;
F_226 ( & V_465 ) ;
F_403 (kvm, &vm_list, vm_list) {
int V_96 ;
F_184 ( V_192 ) ;
if ( ! V_463 -- )
break;
if ( ! V_99 -> V_34 . V_171 &&
! F_398 ( V_99 ) )
continue;
V_96 = F_404 ( & V_99 -> V_466 ) ;
F_226 ( & V_99 -> V_207 ) ;
if ( F_398 ( V_99 ) ) {
F_185 ( V_99 ,
& V_99 -> V_34 . V_457 ) ;
goto V_467;
}
if ( F_223 ( V_99 , & V_192 ) )
V_464 ++ ;
F_185 ( V_99 , & V_192 ) ;
V_467:
F_227 ( & V_99 -> V_207 ) ;
F_405 ( & V_99 -> V_466 , V_96 ) ;
F_406 ( & V_99 -> V_468 , & V_468 ) ;
break;
}
F_227 ( & V_465 ) ;
return V_464 ;
}
static unsigned long
F_407 ( struct V_459 * V_460 , struct V_461 * V_462 )
{
return F_408 ( & V_172 ) ;
}
static void F_409 ( void )
{
if ( V_81 )
F_410 ( V_81 ) ;
if ( V_85 )
F_410 ( V_85 ) ;
}
int F_411 ( void )
{
V_81 = F_412 ( L_32 ,
sizeof( struct V_87 ) ,
0 , 0 , NULL ) ;
if ( ! V_81 )
goto V_469;
V_85 = F_412 ( L_33 ,
sizeof( struct V_47 ) ,
0 , 0 , NULL ) ;
if ( ! V_85 )
goto V_469;
if ( F_413 ( & V_172 , 0 , V_75 ) )
goto V_469;
F_414 ( & V_470 ) ;
return 0 ;
V_469:
F_409 () ;
return - V_76 ;
}
unsigned int F_415 ( struct V_99 * V_99 )
{
unsigned int V_471 ;
unsigned int V_472 = 0 ;
struct V_100 * V_101 ;
struct V_94 * V_157 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_158 ; V_103 ++ ) {
V_101 = F_133 ( V_99 , V_103 ) ;
F_134 (memslot, slots)
V_472 += V_157 -> V_164 ;
}
V_471 = V_472 * V_473 / 1000 ;
V_471 = F_135 ( V_471 ,
( unsigned int ) V_474 ) ;
return V_471 ;
}
void F_416 ( struct V_11 * V_12 )
{
F_351 ( V_12 ) ;
F_372 ( V_12 ) ;
F_68 ( V_12 ) ;
}
void F_417 ( void )
{
F_409 () ;
F_418 ( & V_172 ) ;
F_419 ( & V_470 ) ;
F_187 () ;
}
