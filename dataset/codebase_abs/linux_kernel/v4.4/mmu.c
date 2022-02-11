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
static int F_24 ( T_1 V_37 )
{
return F_22 ( V_37 ) ;
}
static int F_25 ( T_1 V_37 , int V_40 )
{
if ( V_40 == V_41 )
return 1 ;
if ( F_23 ( V_37 ) )
return 1 ;
return 0 ;
}
static T_3 F_26 ( T_1 V_37 )
{
return ( V_37 & V_42 ) >> V_19 ;
}
static T_2 F_27 ( T_4 V_43 )
{
int V_44 = 32 - V_45 - V_19 ;
return ( V_43 & V_46 ) << V_44 ;
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
static void F_34 ( T_1 * V_14 , T_1 V_10 )
{
struct V_47 * V_48 = F_35 ( F_36 ( V_14 ) ) ;
if ( F_22 ( V_10 ) )
return;
F_37 () ;
V_48 -> V_49 ++ ;
}
static void F_28 ( T_1 * V_14 , T_1 V_10 )
{
union V_50 * V_51 , V_52 ;
V_51 = (union V_50 * ) V_14 ;
V_52 = (union V_50 ) V_10 ;
V_51 -> V_53 = V_52 . V_53 ;
F_37 () ;
V_51 -> V_54 = V_52 . V_54 ;
}
static void F_29 ( T_1 * V_14 , T_1 V_10 )
{
union V_50 * V_51 , V_52 ;
V_51 = (union V_50 * ) V_14 ;
V_52 = (union V_50 ) V_10 ;
V_51 -> V_54 = V_52 . V_54 ;
F_37 () ;
V_51 -> V_53 = V_52 . V_53 ;
F_34 ( V_14 , V_10 ) ;
}
static T_1 F_30 ( T_1 * V_14 , T_1 V_10 )
{
union V_50 * V_51 , V_52 , V_55 ;
V_51 = (union V_50 * ) V_14 ;
V_52 = (union V_50 ) V_10 ;
V_55 . V_54 = F_31 ( & V_51 -> V_54 , V_52 . V_54 ) ;
V_55 . V_53 = V_51 -> V_53 ;
V_51 -> V_53 = V_52 . V_53 ;
F_34 ( V_14 , V_10 ) ;
return V_55 . V_10 ;
}
static T_1 F_32 ( T_1 * V_14 )
{
struct V_47 * V_48 = F_35 ( F_36 ( V_14 ) ) ;
union V_50 V_10 , * V_55 = (union V_50 * ) V_14 ;
int V_56 ;
V_57:
V_56 = V_48 -> V_49 ;
F_38 () ;
V_10 . V_54 = V_55 -> V_54 ;
F_38 () ;
V_10 . V_53 = V_55 -> V_53 ;
F_38 () ;
if ( F_14 ( V_10 . V_54 != V_55 -> V_54 ||
V_56 != V_48 -> V_49 ) )
goto V_57;
return V_10 . V_10 ;
}
static bool F_39 ( T_1 V_10 )
{
return ( V_10 & ( V_58 | V_59 ) ) ==
( V_58 | V_59 ) ;
}
static bool F_40 ( T_1 V_10 )
{
if ( F_39 ( V_10 ) )
return true ;
if ( ! V_30 )
return false ;
if ( ! F_22 ( V_10 ) )
return false ;
if ( ( V_10 & V_30 ) &&
( ! F_41 ( V_10 ) || ( V_10 & V_31 ) ) )
return false ;
return true ;
}
static bool F_42 ( T_1 V_60 , T_1 V_61 , T_1 V_62 )
{
return ( V_60 & V_62 ) && ! ( V_61 & V_62 ) ;
}
static bool F_43 ( T_1 V_60 , T_1 V_61 , T_1 V_62 )
{
return ( V_60 & V_62 ) != ( V_61 & V_62 ) ;
}
static void F_9 ( T_1 * V_14 , T_1 V_61 )
{
F_3 ( F_22 ( * V_14 ) ) ;
F_28 ( V_14 , V_61 ) ;
}
static bool F_44 ( T_1 * V_14 , T_1 V_61 )
{
T_1 V_60 = * V_14 ;
bool V_63 = false ;
F_3 ( ! F_24 ( V_61 ) ) ;
if ( ! F_22 ( V_60 ) ) {
F_9 ( V_14 , V_61 ) ;
return V_63 ;
}
if ( ! F_40 ( V_60 ) )
F_29 ( V_14 , V_61 ) ;
else
V_60 = F_30 ( V_14 , V_61 ) ;
if ( F_39 ( V_60 ) &&
! F_41 ( V_61 ) )
V_63 = true ;
if ( ! V_30 )
return V_63 ;
if ( F_43 ( V_60 , V_61 ,
V_30 | V_31 ) )
V_63 = true ;
if ( F_42 ( V_60 , V_61 , V_30 ) )
F_45 ( F_26 ( V_60 ) ) ;
if ( F_42 ( V_60 , V_61 , V_31 ) )
F_46 ( F_26 ( V_60 ) ) ;
return V_63 ;
}
static int F_47 ( T_1 * V_14 )
{
T_3 V_21 ;
T_1 V_60 = * V_14 ;
if ( ! F_40 ( V_60 ) )
F_29 ( V_14 , 0ull ) ;
else
V_60 = F_30 ( V_14 , 0ull ) ;
if ( ! F_24 ( V_60 ) )
return 0 ;
V_21 = F_26 ( V_60 ) ;
F_3 ( ! F_48 ( V_21 ) && ! F_49 ( F_50 ( V_21 ) ) ) ;
if ( ! V_30 || V_60 & V_30 )
F_45 ( V_21 ) ;
if ( ! V_31 || ( V_60 & V_31 ) )
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
static void F_53 ( struct V_11 * V_12 )
{
F_54 () ;
V_12 -> V_64 = V_65 ;
F_55 () ;
}
static void F_56 ( struct V_11 * V_12 )
{
F_55 () ;
V_12 -> V_64 = V_66 ;
F_57 () ;
}
static int F_58 ( struct V_67 * V_68 ,
struct V_69 * V_70 , int V_71 )
{
void * V_72 ;
if ( V_68 -> V_73 >= V_71 )
return 0 ;
while ( V_68 -> V_73 < F_59 ( V_68 -> V_74 ) ) {
V_72 = F_60 ( V_70 , V_75 ) ;
if ( ! V_72 )
return - V_76 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = V_72 ;
}
return 0 ;
}
static int F_61 ( struct V_67 * V_68 )
{
return V_68 -> V_73 ;
}
static void F_62 ( struct V_67 * V_77 ,
struct V_69 * V_68 )
{
while ( V_77 -> V_73 )
F_63 ( V_68 , V_77 -> V_74 [ -- V_77 -> V_73 ] ) ;
}
static int F_64 ( struct V_67 * V_68 ,
int V_71 )
{
void * V_78 ;
if ( V_68 -> V_73 >= V_71 )
return 0 ;
while ( V_68 -> V_73 < F_59 ( V_68 -> V_74 ) ) {
V_78 = ( void * ) F_65 ( V_75 ) ;
if ( ! V_78 )
return - V_76 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = V_78 ;
}
return 0 ;
}
static void F_66 ( struct V_67 * V_77 )
{
while ( V_77 -> V_73 )
F_67 ( ( unsigned long ) V_77 -> V_74 [ -- V_77 -> V_73 ] ) ;
}
static int F_68 ( struct V_11 * V_12 )
{
int V_79 ;
V_79 = F_58 ( & V_12 -> V_34 . V_80 ,
V_81 , 8 + V_82 ) ;
if ( V_79 )
goto V_83;
V_79 = F_64 ( & V_12 -> V_34 . V_84 , 8 ) ;
if ( V_79 )
goto V_83;
V_79 = F_58 ( & V_12 -> V_34 . V_85 ,
V_85 , 4 ) ;
V_83:
return V_79 ;
}
static void F_69 ( struct V_11 * V_12 )
{
F_62 ( & V_12 -> V_34 . V_80 ,
V_81 ) ;
F_66 ( & V_12 -> V_34 . V_84 ) ;
F_62 ( & V_12 -> V_34 . V_85 ,
V_85 ) ;
}
static void * F_70 ( struct V_67 * V_77 )
{
void * V_86 ;
F_71 ( ! V_77 -> V_73 ) ;
V_86 = V_77 -> V_74 [ -- V_77 -> V_73 ] ;
return V_86 ;
}
static struct V_87 * F_72 ( struct V_11 * V_12 )
{
return F_70 ( & V_12 -> V_34 . V_80 ) ;
}
static void F_73 ( struct V_87 * V_87 )
{
F_63 ( V_81 , V_87 ) ;
}
static T_2 F_74 ( struct V_47 * V_48 , int V_88 )
{
if ( ! V_48 -> V_89 . V_90 )
return V_48 -> V_91 [ V_88 ] ;
return V_48 -> V_15 + ( V_88 << ( ( V_48 -> V_89 . V_40 - 1 ) * V_92 ) ) ;
}
static void F_75 ( struct V_47 * V_48 , int V_88 , T_2 V_15 )
{
if ( V_48 -> V_89 . V_90 )
F_71 ( V_15 != F_74 ( V_48 , V_88 ) ) ;
else
V_48 -> V_91 [ V_88 ] = V_15 ;
}
static struct V_93 * F_76 ( T_2 V_15 ,
struct V_94 * V_95 ,
int V_40 )
{
unsigned long V_96 ;
V_96 = F_77 ( V_15 , V_95 -> V_97 , V_40 ) ;
return & V_95 -> V_34 . V_98 [ V_40 - 2 ] [ V_96 ] ;
}
static void F_78 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
struct V_100 * V_101 ;
struct V_94 * V_95 ;
struct V_93 * V_102 ;
T_2 V_15 ;
int V_103 ;
V_15 = V_48 -> V_15 ;
V_101 = F_79 ( V_99 , V_48 -> V_89 ) ;
V_95 = F_80 ( V_101 , V_15 ) ;
for ( V_103 = V_104 ; V_103 <= V_105 ; ++ V_103 ) {
V_102 = F_76 ( V_15 , V_95 , V_103 ) ;
V_102 -> V_106 += 1 ;
}
V_99 -> V_34 . V_107 ++ ;
}
static void F_81 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
struct V_100 * V_101 ;
struct V_94 * V_95 ;
struct V_93 * V_102 ;
T_2 V_15 ;
int V_103 ;
V_15 = V_48 -> V_15 ;
V_101 = F_79 ( V_99 , V_48 -> V_89 ) ;
V_95 = F_80 ( V_101 , V_15 ) ;
for ( V_103 = V_104 ; V_103 <= V_105 ; ++ V_103 ) {
V_102 = F_76 ( V_15 , V_95 , V_103 ) ;
V_102 -> V_106 -= 1 ;
F_3 ( V_102 -> V_106 < 0 ) ;
}
V_99 -> V_34 . V_107 -- ;
}
static int F_82 ( T_2 V_15 , int V_40 ,
struct V_94 * V_95 )
{
struct V_93 * V_102 ;
if ( V_95 ) {
V_102 = F_76 ( V_15 , V_95 , V_40 ) ;
return V_102 -> V_106 ;
}
return 1 ;
}
static int F_83 ( struct V_11 * V_12 , T_2 V_15 , int V_40 )
{
struct V_94 * V_95 ;
V_95 = F_84 ( V_12 , V_15 ) ;
return F_82 ( V_15 , V_40 , V_95 ) ;
}
static int F_85 ( struct V_99 * V_99 , T_2 V_15 )
{
unsigned long V_108 ;
int V_103 , V_63 = 0 ;
V_108 = F_86 ( V_99 , V_15 ) ;
for ( V_103 = V_41 ; V_103 <= V_105 ; ++ V_103 ) {
if ( V_108 >= F_87 ( V_103 ) )
V_63 = V_103 ;
else
break;
}
return V_63 ;
}
static inline bool F_88 ( struct V_94 * V_95 ,
bool V_109 )
{
if ( ! V_95 || V_95 -> V_110 & V_111 )
return false ;
if ( V_109 && V_95 -> V_112 )
return false ;
return true ;
}
static struct V_94 *
F_89 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_109 )
{
struct V_94 * V_95 ;
V_95 = F_84 ( V_12 , V_15 ) ;
if ( ! F_88 ( V_95 , V_109 ) )
V_95 = NULL ;
return V_95 ;
}
static int F_90 ( struct V_11 * V_12 , T_2 V_113 ,
bool * V_114 )
{
int V_115 , V_40 , V_116 ;
struct V_94 * V_95 ;
if ( F_14 ( * V_114 ) )
return V_41 ;
V_95 = F_84 ( V_12 , V_113 ) ;
* V_114 = ! F_88 ( V_95 , true ) ;
if ( F_14 ( * V_114 ) )
return V_41 ;
V_115 = F_85 ( V_12 -> V_99 , V_113 ) ;
if ( V_115 == V_41 )
return V_115 ;
V_116 = V_71 ( V_117 -> V_118 () , V_115 ) ;
for ( V_40 = V_104 ; V_40 <= V_116 ; ++ V_40 )
if ( F_82 ( V_113 , V_40 , V_95 ) )
break;
return V_40 - 1 ;
}
static int F_91 ( struct V_11 * V_12 , T_1 * V_10 ,
unsigned long * V_119 )
{
struct V_87 * V_120 ;
int V_103 , V_56 = 0 ;
if ( ! * V_119 ) {
F_92 ( L_1 , V_10 , * V_10 ) ;
* V_119 = ( unsigned long ) V_10 ;
} else if ( ! ( * V_119 & 1 ) ) {
F_92 ( L_2 , V_10 , * V_10 ) ;
V_120 = F_72 ( V_12 ) ;
V_120 -> V_121 [ 0 ] = ( T_1 * ) * V_119 ;
V_120 -> V_121 [ 1 ] = V_10 ;
* V_119 = ( unsigned long ) V_120 | 1 ;
++ V_56 ;
} else {
F_92 ( L_3 , V_10 , * V_10 ) ;
V_120 = (struct V_87 * ) ( * V_119 & ~ 1ul ) ;
while ( V_120 -> V_121 [ V_122 - 1 ] && V_120 -> V_123 ) {
V_120 = V_120 -> V_123 ;
V_56 += V_122 ;
}
if ( V_120 -> V_121 [ V_122 - 1 ] ) {
V_120 -> V_123 = F_72 ( V_12 ) ;
V_120 = V_120 -> V_123 ;
}
for ( V_103 = 0 ; V_120 -> V_121 [ V_103 ] ; ++ V_103 )
++ V_56 ;
V_120 -> V_121 [ V_103 ] = V_10 ;
}
return V_56 ;
}
static void
F_93 ( unsigned long * V_119 , struct V_87 * V_120 ,
int V_103 , struct V_87 * V_124 )
{
int V_125 ;
for ( V_125 = V_122 - 1 ; ! V_120 -> V_121 [ V_125 ] && V_125 > V_103 ; -- V_125 )
;
V_120 -> V_121 [ V_103 ] = V_120 -> V_121 [ V_125 ] ;
V_120 -> V_121 [ V_125 ] = NULL ;
if ( V_125 != 0 )
return;
if ( ! V_124 && ! V_120 -> V_123 )
* V_119 = ( unsigned long ) V_120 -> V_121 [ 0 ] ;
else
if ( V_124 )
V_124 -> V_123 = V_120 -> V_123 ;
else
* V_119 = ( unsigned long ) V_120 -> V_123 | 1 ;
F_73 ( V_120 ) ;
}
static void F_94 ( T_1 * V_10 , unsigned long * V_119 )
{
struct V_87 * V_120 ;
struct V_87 * V_124 ;
int V_103 ;
if ( ! * V_119 ) {
F_95 ( V_126 L_4 , V_10 ) ;
F_96 () ;
} else if ( ! ( * V_119 & 1 ) ) {
F_92 ( L_5 , V_10 ) ;
if ( ( T_1 * ) * V_119 != V_10 ) {
F_95 ( V_126 L_6 , V_10 ) ;
F_96 () ;
}
* V_119 = 0 ;
} else {
F_92 ( L_7 , V_10 ) ;
V_120 = (struct V_87 * ) ( * V_119 & ~ 1ul ) ;
V_124 = NULL ;
while ( V_120 ) {
for ( V_103 = 0 ; V_103 < V_122 && V_120 -> V_121 [ V_103 ] ; ++ V_103 )
if ( V_120 -> V_121 [ V_103 ] == V_10 ) {
F_93 ( V_119 ,
V_120 , V_103 ,
V_124 ) ;
return;
}
V_124 = V_120 ;
V_120 = V_120 -> V_123 ;
}
F_97 ( L_8 , V_10 ) ;
F_96 () ;
}
}
static void F_98 ( unsigned long * V_119 , T_5 V_127 )
{
struct V_87 * V_120 ;
int V_103 ;
if ( ! * V_119 )
return;
if ( ! ( * V_119 & 1 ) )
return V_127 ( ( T_1 * ) * V_119 ) ;
V_120 = (struct V_87 * ) ( * V_119 & ~ 1ul ) ;
while ( V_120 ) {
for ( V_103 = 0 ; V_103 < V_122 && V_120 -> V_121 [ V_103 ] ; ++ V_103 )
V_127 ( V_120 -> V_121 [ V_103 ] ) ;
V_120 = V_120 -> V_123 ;
}
}
static unsigned long * F_99 ( T_2 V_15 , int V_40 ,
struct V_94 * V_95 )
{
unsigned long V_96 ;
V_96 = F_77 ( V_15 , V_95 -> V_97 , V_40 ) ;
return & V_95 -> V_34 . V_128 [ V_40 - V_41 ] [ V_96 ] ;
}
static unsigned long * F_100 ( struct V_99 * V_99 , T_2 V_15 , struct V_47 * V_48 )
{
struct V_100 * V_101 ;
struct V_94 * V_95 ;
V_101 = F_79 ( V_99 , V_48 -> V_89 ) ;
V_95 = F_80 ( V_101 , V_15 ) ;
return F_99 ( V_15 , V_48 -> V_89 . V_40 , V_95 ) ;
}
static bool F_101 ( struct V_11 * V_12 )
{
struct V_67 * V_68 ;
V_68 = & V_12 -> V_34 . V_80 ;
return F_61 ( V_68 ) ;
}
static int F_102 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
struct V_47 * V_48 ;
unsigned long * V_129 ;
V_48 = F_35 ( F_36 ( V_10 ) ) ;
F_75 ( V_48 , V_10 - V_48 -> V_130 , V_15 ) ;
V_129 = F_100 ( V_12 -> V_99 , V_15 , V_48 ) ;
return F_91 ( V_12 , V_10 , V_129 ) ;
}
static void F_103 ( struct V_99 * V_99 , T_1 * V_10 )
{
struct V_47 * V_48 ;
T_2 V_15 ;
unsigned long * V_129 ;
V_48 = F_35 ( F_36 ( V_10 ) ) ;
V_15 = F_74 ( V_48 , V_10 - V_48 -> V_130 ) ;
V_129 = F_100 ( V_99 , V_15 , V_48 ) ;
F_94 ( V_10 , V_129 ) ;
}
static T_1 * F_104 ( unsigned long V_128 , struct V_131 * V_132 )
{
if ( ! V_128 )
return NULL ;
if ( ! ( V_128 & 1 ) ) {
V_132 -> V_120 = NULL ;
return ( T_1 * ) V_128 ;
}
V_132 -> V_120 = (struct V_87 * ) ( V_128 & ~ 1ul ) ;
V_132 -> V_133 = 0 ;
return V_132 -> V_120 -> V_121 [ V_132 -> V_133 ] ;
}
static T_1 * F_105 ( struct V_131 * V_132 )
{
if ( V_132 -> V_120 ) {
if ( V_132 -> V_133 < V_122 - 1 ) {
T_1 * V_14 ;
++ V_132 -> V_133 ;
V_14 = V_132 -> V_120 -> V_121 [ V_132 -> V_133 ] ;
if ( V_14 )
return V_14 ;
}
V_132 -> V_120 = V_132 -> V_120 -> V_123 ;
if ( V_132 -> V_120 ) {
V_132 -> V_133 = 0 ;
return V_132 -> V_120 -> V_121 [ V_132 -> V_133 ] ;
}
}
return NULL ;
}
static void F_106 ( struct V_99 * V_99 , T_1 * V_14 )
{
if ( F_47 ( V_14 ) )
F_103 ( V_99 , V_14 ) ;
}
static bool F_107 ( struct V_99 * V_99 , T_1 * V_14 )
{
if ( F_23 ( * V_14 ) ) {
F_3 ( F_35 ( F_36 ( V_14 ) ) -> V_89 . V_40 ==
V_41 ) ;
F_106 ( V_99 , V_14 ) ;
-- V_99 -> V_134 . V_135 ;
return true ;
}
return false ;
}
static void F_108 ( struct V_11 * V_12 , T_1 * V_14 )
{
if ( F_107 ( V_12 -> V_99 , V_14 ) )
F_109 ( V_12 -> V_99 ) ;
}
static bool F_110 ( struct V_99 * V_99 , T_1 * V_14 , bool V_136 )
{
T_1 V_10 = * V_14 ;
if ( ! F_41 ( V_10 ) &&
! ( V_136 && F_39 ( V_10 ) ) )
return false ;
F_92 ( L_9 , V_14 , * V_14 ) ;
if ( V_136 )
V_10 &= ~ V_59 ;
V_10 = V_10 & ~ V_137 ;
return F_44 ( V_14 , V_10 ) ;
}
static bool F_111 ( struct V_99 * V_99 , unsigned long * V_129 ,
bool V_136 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
F_112 (rmapp, &iter, sptep)
V_138 |= F_110 ( V_99 , V_14 , V_136 ) ;
return V_138 ;
}
static bool F_113 ( struct V_99 * V_99 , T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_92 ( L_10 , V_14 , * V_14 ) ;
V_10 &= ~ V_31 ;
return F_44 ( V_14 , V_10 ) ;
}
static bool F_114 ( struct V_99 * V_99 , unsigned long * V_129 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
F_112 (rmapp, &iter, sptep)
V_138 |= F_113 ( V_99 , V_14 ) ;
return V_138 ;
}
static bool F_115 ( struct V_99 * V_99 , T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_92 ( L_11 , V_14 , * V_14 ) ;
V_10 |= V_31 ;
return F_44 ( V_14 , V_10 ) ;
}
static bool F_116 ( struct V_99 * V_99 , unsigned long * V_129 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
F_112 (rmapp, &iter, sptep)
V_138 |= F_115 ( V_99 , V_14 ) ;
return V_138 ;
}
static void F_117 ( struct V_99 * V_99 ,
struct V_94 * V_95 ,
T_2 V_139 , unsigned long V_4 )
{
unsigned long * V_129 ;
while ( V_4 ) {
V_129 = F_99 ( V_95 -> V_97 + V_139 + F_118 ( V_4 ) ,
V_41 , V_95 ) ;
F_111 ( V_99 , V_129 , false ) ;
V_4 &= V_4 - 1 ;
}
}
void F_119 ( struct V_99 * V_99 ,
struct V_94 * V_95 ,
T_2 V_139 , unsigned long V_4 )
{
unsigned long * V_129 ;
while ( V_4 ) {
V_129 = F_99 ( V_95 -> V_97 + V_139 + F_118 ( V_4 ) ,
V_41 , V_95 ) ;
F_114 ( V_99 , V_129 ) ;
V_4 &= V_4 - 1 ;
}
}
void F_120 ( struct V_99 * V_99 ,
struct V_94 * V_95 ,
T_2 V_139 , unsigned long V_4 )
{
if ( V_117 -> V_140 )
V_117 -> V_140 ( V_99 , V_95 , V_139 ,
V_4 ) ;
else
F_117 ( V_99 , V_95 , V_139 , V_4 ) ;
}
static bool F_121 ( struct V_11 * V_12 , T_1 V_15 )
{
struct V_94 * V_95 ;
unsigned long * V_129 ;
int V_103 ;
bool V_141 = false ;
V_95 = F_84 ( V_12 , V_15 ) ;
for ( V_103 = V_41 ; V_103 <= V_105 ; ++ V_103 ) {
V_129 = F_99 ( V_15 , V_103 , V_95 ) ;
V_141 |= F_111 ( V_12 -> V_99 , V_129 , true ) ;
}
return V_141 ;
}
static bool F_122 ( struct V_99 * V_99 , unsigned long * V_129 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
while ( ( V_14 = F_104 ( * V_129 , & V_132 ) ) ) {
F_71 ( ! ( * V_14 & V_38 ) ) ;
F_92 ( L_12 , V_142 , V_14 , * V_14 ) ;
F_106 ( V_99 , V_14 ) ;
V_138 = true ;
}
return V_138 ;
}
static int F_123 ( struct V_99 * V_99 , unsigned long * V_129 ,
struct V_94 * V_95 , T_2 V_15 , int V_40 ,
unsigned long V_143 )
{
return F_122 ( V_99 , V_129 ) ;
}
static int F_124 ( struct V_99 * V_99 , unsigned long * V_129 ,
struct V_94 * V_95 , T_2 V_15 , int V_40 ,
unsigned long V_143 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
int V_144 = 0 ;
T_1 V_61 ;
T_6 * V_145 = ( T_6 * ) V_143 ;
T_3 V_146 ;
F_3 ( F_125 ( * V_145 ) ) ;
V_146 = F_126 ( * V_145 ) ;
V_147:
F_112 (rmapp, &iter, sptep) {
F_92 ( L_13 ,
V_14 , * V_14 , V_15 , V_40 ) ;
V_144 = 1 ;
if ( F_127 ( * V_145 ) ) {
F_106 ( V_99 , V_14 ) ;
goto V_147;
} else {
V_61 = * V_14 & ~ V_42 ;
V_61 |= ( T_1 ) V_146 << V_19 ;
V_61 &= ~ V_137 ;
V_61 &= ~ V_58 ;
V_61 &= ~ V_30 ;
F_47 ( V_14 ) ;
F_9 ( V_14 , V_61 ) ;
}
}
if ( V_144 )
F_109 ( V_99 ) ;
return 0 ;
}
static void
F_128 ( struct V_148 * V_149 , int V_40 )
{
V_149 -> V_40 = V_40 ;
V_149 -> V_15 = V_149 -> V_150 ;
V_149 -> V_128 = F_99 ( V_149 -> V_15 , V_40 , V_149 -> V_95 ) ;
V_149 -> V_151 = F_99 ( V_149 -> V_152 , V_40 ,
V_149 -> V_95 ) ;
}
static void
F_129 ( struct V_148 * V_149 ,
struct V_94 * V_95 , int V_153 ,
int V_154 , T_2 V_150 , T_2 V_152 )
{
V_149 -> V_95 = V_95 ;
V_149 -> V_153 = V_153 ;
V_149 -> V_154 = V_154 ;
V_149 -> V_150 = V_150 ;
V_149 -> V_152 = V_152 ;
F_128 ( V_149 , V_149 -> V_153 ) ;
}
static bool F_130 ( struct V_148 * V_149 )
{
return ! ! V_149 -> V_128 ;
}
static void F_131 ( struct V_148 * V_149 )
{
if ( ++ V_149 -> V_128 <= V_149 -> V_151 ) {
V_149 -> V_15 += ( 1UL << F_132 ( V_149 -> V_40 ) ) ;
return;
}
if ( ++ V_149 -> V_40 > V_149 -> V_154 ) {
V_149 -> V_128 = NULL ;
return;
}
F_128 ( V_149 , V_149 -> V_40 ) ;
}
static int F_133 ( struct V_99 * V_99 ,
unsigned long V_155 ,
unsigned long V_156 ,
unsigned long V_143 ,
int (* F_134)( struct V_99 * V_99 ,
unsigned long * V_129 ,
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
V_101 = F_135 ( V_99 , V_103 ) ;
F_136 (memslot, slots) {
unsigned long V_159 , V_160 ;
T_2 V_161 , V_162 ;
V_159 = F_137 ( V_155 , V_157 -> V_163 ) ;
V_160 = V_71 ( V_156 , V_157 -> V_163 +
( V_157 -> V_164 << V_19 ) ) ;
if ( V_159 >= V_160 )
continue;
V_161 = F_138 ( V_159 , V_157 ) ;
V_162 = F_138 ( V_160 + V_165 - 1 , V_157 ) ;
F_139 (memslot, PT_PAGE_TABLE_LEVEL,
PT_MAX_HUGEPAGE_LEVEL,
gfn_start, gfn_end - 1 ,
&iterator)
V_63 |= F_134 ( V_99 , V_149 . V_128 , V_157 ,
V_149 . V_15 , V_149 . V_40 , V_143 ) ;
}
}
return V_63 ;
}
static int F_140 ( struct V_99 * V_99 , unsigned long V_166 ,
unsigned long V_143 ,
int (* F_134)( struct V_99 * V_99 , unsigned long * V_129 ,
struct V_94 * V_95 ,
T_2 V_15 , int V_40 ,
unsigned long V_143 ) )
{
return F_133 ( V_99 , V_166 , V_166 + 1 , V_143 , F_134 ) ;
}
int F_141 ( struct V_99 * V_99 , unsigned long V_166 )
{
return F_140 ( V_99 , V_166 , 0 , F_123 ) ;
}
int F_142 ( struct V_99 * V_99 , unsigned long V_155 , unsigned long V_156 )
{
return F_133 ( V_99 , V_155 , V_156 , 0 , F_123 ) ;
}
void F_143 ( struct V_99 * V_99 , unsigned long V_166 , T_6 V_37 )
{
F_140 ( V_99 , V_166 , ( unsigned long ) & V_37 , F_124 ) ;
}
static int F_144 ( struct V_99 * V_99 , unsigned long * V_129 ,
struct V_94 * V_95 , T_2 V_15 , int V_40 ,
unsigned long V_143 )
{
T_1 * V_14 ;
struct V_131 V_167 ( V_132 ) ;
int V_168 = 0 ;
F_71 ( ! V_30 ) ;
F_112 (rmapp, &iter, sptep)
if ( * V_14 & V_30 ) {
V_168 = 1 ;
F_145 ( ( F_146 ( V_30 ) - 1 ) ,
( unsigned long * ) V_14 ) ;
}
F_147 ( V_15 , V_40 , V_95 , V_168 ) ;
return V_168 ;
}
static int F_148 ( struct V_99 * V_99 , unsigned long * V_129 ,
struct V_94 * V_95 , T_2 V_15 ,
int V_40 , unsigned long V_143 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
int V_168 = 0 ;
if ( ! V_30 )
goto V_83;
F_112 (rmapp, &iter, sptep)
if ( * V_14 & V_30 ) {
V_168 = 1 ;
break;
}
V_83:
return V_168 ;
}
static void F_149 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
unsigned long * V_129 ;
struct V_47 * V_48 ;
V_48 = F_35 ( F_36 ( V_10 ) ) ;
V_129 = F_100 ( V_12 -> V_99 , V_15 , V_48 ) ;
F_123 ( V_12 -> V_99 , V_129 , NULL , V_15 , V_48 -> V_89 . V_40 , 0 ) ;
F_109 ( V_12 -> V_99 ) ;
}
int F_150 ( struct V_99 * V_99 , unsigned long V_155 , unsigned long V_156 )
{
if ( ! V_30 ) {
V_99 -> V_169 ++ ;
return F_133 ( V_99 , V_155 , V_156 , 0 ,
F_123 ) ;
}
return F_133 ( V_99 , V_155 , V_156 , 0 , F_144 ) ;
}
int F_151 ( struct V_99 * V_99 , unsigned long V_166 )
{
return F_140 ( V_99 , V_166 , 0 , F_148 ) ;
}
static int F_152 ( T_1 * V_130 )
{
T_1 * V_133 ;
T_1 * V_156 ;
for ( V_133 = V_130 , V_156 = V_133 + V_165 / sizeof( T_1 ) ; V_133 != V_156 ; V_133 ++ )
if ( F_22 ( * V_133 ) ) {
F_95 ( V_126 L_14 , V_142 ,
V_133 , * V_133 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_153 ( struct V_99 * V_99 , int V_170 )
{
V_99 -> V_34 . V_171 += V_170 ;
F_154 ( & V_172 , V_170 ) ;
}
static void F_155 ( struct V_47 * V_48 )
{
F_156 ( ! F_152 ( V_48 -> V_130 ) ) ;
F_157 ( & V_48 -> V_173 ) ;
F_158 ( & V_48 -> V_174 ) ;
F_67 ( ( unsigned long ) V_48 -> V_130 ) ;
if ( ! V_48 -> V_89 . V_90 )
F_67 ( ( unsigned long ) V_48 -> V_91 ) ;
F_63 ( V_85 , V_48 ) ;
}
static unsigned F_159 ( T_2 V_15 )
{
return V_15 & ( ( 1 << V_175 ) - 1 ) ;
}
static void F_160 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_176 )
{
if ( ! V_176 )
return;
F_91 ( V_12 , V_176 , & V_48 -> V_177 ) ;
}
static void F_161 ( struct V_47 * V_48 ,
T_1 * V_176 )
{
F_94 ( V_176 , & V_48 -> V_177 ) ;
}
static void F_162 ( struct V_47 * V_48 ,
T_1 * V_176 )
{
F_161 ( V_48 , V_176 ) ;
F_51 ( V_176 ) ;
}
static struct V_47 * F_163 ( struct V_11 * V_12 ,
T_1 * V_176 , int V_90 )
{
struct V_47 * V_48 ;
V_48 = F_70 ( & V_12 -> V_34 . V_85 ) ;
V_48 -> V_130 = F_70 ( & V_12 -> V_34 . V_84 ) ;
if ( ! V_90 )
V_48 -> V_91 = F_70 ( & V_12 -> V_34 . V_84 ) ;
F_164 ( F_165 ( V_48 -> V_130 ) , ( unsigned long ) V_48 ) ;
F_166 ( & V_48 -> V_174 , & V_12 -> V_99 -> V_34 . V_178 ) ;
V_48 -> V_177 = 0 ;
F_160 ( V_12 , V_48 , V_176 ) ;
F_153 ( V_12 -> V_99 , + 1 ) ;
return V_48 ;
}
static void F_167 ( struct V_47 * V_48 )
{
F_98 ( & V_48 -> V_177 , V_179 ) ;
}
static void V_179 ( T_1 * V_10 )
{
struct V_47 * V_48 ;
unsigned int V_88 ;
V_48 = F_35 ( F_36 ( V_10 ) ) ;
V_88 = V_10 - V_48 -> V_130 ;
if ( F_168 ( V_88 , V_48 -> V_180 ) )
return;
if ( V_48 -> V_181 ++ )
return;
F_167 ( V_48 ) ;
}
static int F_169 ( struct V_11 * V_12 ,
struct V_47 * V_48 )
{
return 1 ;
}
static void F_170 ( struct V_11 * V_12 , T_7 V_182 )
{
}
static void F_171 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_10 ,
const void * V_37 )
{
F_3 ( 1 ) ;
}
static int F_172 ( struct V_183 * V_184 , struct V_47 * V_48 ,
int V_96 )
{
int V_103 ;
if ( V_48 -> V_185 )
for ( V_103 = 0 ; V_103 < V_184 -> V_170 ; V_103 ++ )
if ( V_184 -> V_78 [ V_103 ] . V_48 == V_48 )
return 0 ;
V_184 -> V_78 [ V_184 -> V_170 ] . V_48 = V_48 ;
V_184 -> V_78 [ V_184 -> V_170 ] . V_96 = V_96 ;
V_184 -> V_170 ++ ;
return ( V_184 -> V_170 == V_186 ) ;
}
static int F_173 ( struct V_47 * V_48 ,
struct V_183 * V_184 )
{
int V_103 , V_63 , V_187 = 0 ;
F_174 (i, sp->unsync_child_bitmap, 512 ) {
struct V_47 * V_188 ;
T_1 V_189 = V_48 -> V_130 [ V_103 ] ;
if ( ! F_22 ( V_189 ) || F_23 ( V_189 ) )
goto V_190;
V_188 = F_35 ( V_189 & V_42 ) ;
if ( V_188 -> V_181 ) {
if ( F_172 ( V_184 , V_188 , V_103 ) )
return - V_191 ;
V_63 = F_173 ( V_188 , V_184 ) ;
if ( ! V_63 )
goto V_190;
else if ( V_63 > 0 )
V_187 += V_63 ;
else
return V_63 ;
} else if ( V_188 -> V_185 ) {
V_187 ++ ;
if ( F_172 ( V_184 , V_188 , V_103 ) )
return - V_191 ;
} else
goto V_190;
continue;
V_190:
F_175 ( V_103 , V_48 -> V_180 ) ;
V_48 -> V_181 -- ;
F_3 ( ( int ) V_48 -> V_181 < 0 ) ;
}
return V_187 ;
}
static int F_176 ( struct V_47 * V_48 ,
struct V_183 * V_184 )
{
if ( ! V_48 -> V_181 )
return 0 ;
F_172 ( V_184 , V_48 , 0 ) ;
return F_173 ( V_48 , V_184 ) ;
}
static void F_177 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
F_3 ( ! V_48 -> V_185 ) ;
F_178 ( V_48 ) ;
V_48 -> V_185 = 0 ;
-- V_99 -> V_134 . V_192 ;
}
static int F_179 ( struct V_11 * V_12 , struct V_47 * V_48 ,
struct V_193 * V_194 , bool V_195 )
{
if ( V_48 -> V_89 . V_196 != ! ! F_180 ( V_12 ) ) {
F_181 ( V_12 -> V_99 , V_48 , V_194 ) ;
return 1 ;
}
if ( V_195 )
F_177 ( V_12 -> V_99 , V_48 ) ;
if ( V_12 -> V_34 . V_197 . V_198 ( V_12 , V_48 ) ) {
F_181 ( V_12 -> V_99 , V_48 , V_194 ) ;
return 1 ;
}
F_182 ( V_199 , V_12 ) ;
return 0 ;
}
static int F_183 ( struct V_11 * V_12 ,
struct V_47 * V_48 )
{
F_184 ( V_194 ) ;
int V_63 ;
V_63 = F_179 ( V_12 , V_48 , & V_194 , false ) ;
if ( V_63 )
F_185 ( V_12 -> V_99 , & V_194 ) ;
return V_63 ;
}
static void F_186 ( struct V_11 * V_12 , int V_200 ) { }
static void F_187 ( void ) { }
static int F_188 ( struct V_11 * V_12 , struct V_47 * V_48 ,
struct V_193 * V_194 )
{
return F_179 ( V_12 , V_48 , V_194 , true ) ;
}
static void F_189 ( struct V_11 * V_12 , T_2 V_15 )
{
struct V_47 * V_201 ;
F_184 ( V_194 ) ;
bool V_138 = false ;
F_190 (vcpu->kvm, s, gfn) {
if ( ! V_201 -> V_185 )
continue;
F_3 ( V_201 -> V_89 . V_40 != V_41 ) ;
F_177 ( V_12 -> V_99 , V_201 ) ;
if ( ( V_201 -> V_89 . V_196 != ! ! F_180 ( V_12 ) ) ||
( V_12 -> V_34 . V_197 . V_198 ( V_12 , V_201 ) ) ) {
F_181 ( V_12 -> V_99 , V_201 , & V_194 ) ;
continue;
}
V_138 = true ;
}
F_185 ( V_12 -> V_99 , & V_194 ) ;
if ( V_138 )
F_182 ( V_199 , V_12 ) ;
}
static int F_191 ( struct V_183 * V_184 ,
struct V_202 * V_203 ,
int V_103 )
{
int V_204 ;
for ( V_204 = V_103 + 1 ; V_204 < V_184 -> V_170 ; V_204 ++ ) {
struct V_47 * V_48 = V_184 -> V_78 [ V_204 ] . V_48 ;
if ( V_48 -> V_89 . V_40 == V_41 ) {
V_203 -> V_96 [ 0 ] = V_184 -> V_78 [ V_204 ] . V_96 ;
return V_204 ;
}
V_203 -> V_205 [ V_48 -> V_89 . V_40 - 2 ] = V_48 ;
V_203 -> V_96 [ V_48 -> V_89 . V_40 - 1 ] = V_184 -> V_78 [ V_204 ] . V_96 ;
}
return V_204 ;
}
static void F_192 ( struct V_202 * V_203 )
{
struct V_47 * V_48 ;
unsigned int V_40 = 0 ;
do {
unsigned int V_96 = V_203 -> V_96 [ V_40 ] ;
V_48 = V_203 -> V_205 [ V_40 ] ;
if ( ! V_48 )
return;
-- V_48 -> V_181 ;
F_3 ( ( int ) V_48 -> V_181 < 0 ) ;
F_175 ( V_96 , V_48 -> V_180 ) ;
V_40 ++ ;
} while ( V_40 < V_206 - 1 && ! V_48 -> V_181 );
}
static void F_193 ( struct V_47 * V_205 ,
struct V_202 * V_203 ,
struct V_183 * V_184 )
{
V_203 -> V_205 [ V_205 -> V_89 . V_40 - 1 ] = NULL ;
V_184 -> V_170 = 0 ;
}
static void F_194 ( struct V_11 * V_12 ,
struct V_47 * V_205 )
{
int V_103 ;
struct V_47 * V_48 ;
struct V_202 V_203 ;
struct V_183 V_207 ;
F_184 ( V_194 ) ;
F_193 ( V_205 , & V_203 , & V_207 ) ;
while ( F_176 ( V_205 , & V_207 ) ) {
bool V_208 = false ;
F_195 (pages, sp, parents, i)
V_208 |= F_121 ( V_12 , V_48 -> V_15 ) ;
if ( V_208 )
F_109 ( V_12 -> V_99 ) ;
F_195 (pages, sp, parents, i) {
F_188 ( V_12 , V_48 , & V_194 ) ;
F_192 ( & V_203 ) ;
}
F_185 ( V_12 -> V_99 , & V_194 ) ;
F_196 ( & V_12 -> V_99 -> V_209 ) ;
F_193 ( V_205 , & V_203 , & V_207 ) ;
}
}
static void F_197 ( struct V_47 * V_48 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_210 ; ++ V_103 )
V_48 -> V_130 [ V_103 ] = 0ull ;
}
static void F_198 ( struct V_47 * V_48 )
{
V_48 -> V_211 = 0 ;
}
static void F_199 ( T_1 * V_10 )
{
struct V_47 * V_48 = F_35 ( F_36 ( V_10 ) ) ;
F_198 ( V_48 ) ;
}
static bool F_200 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
return F_14 ( V_48 -> V_212 != V_99 -> V_34 . V_212 ) ;
}
static struct V_47 * F_201 ( struct V_11 * V_12 ,
T_2 V_15 ,
T_7 V_213 ,
unsigned V_40 ,
int V_90 ,
unsigned V_16 ,
T_1 * V_176 )
{
union V_214 V_89 ;
unsigned V_215 ;
struct V_47 * V_48 ;
bool V_216 = false ;
V_89 = V_12 -> V_34 . V_197 . V_217 ;
V_89 . V_40 = V_40 ;
V_89 . V_90 = V_90 ;
if ( V_89 . V_90 )
V_89 . V_196 = 0 ;
V_89 . V_16 = V_16 ;
if ( ! V_12 -> V_34 . V_197 . V_218
&& V_12 -> V_34 . V_197 . V_219 <= V_220 ) {
V_215 = V_213 >> ( V_19 + ( V_221 * V_40 ) ) ;
V_215 &= ( 1 << ( ( V_222 - V_221 ) * V_40 ) ) - 1 ;
V_89 . V_215 = V_215 ;
}
F_202 (vcpu->kvm, sp, gfn) {
if ( F_200 ( V_12 -> V_99 , V_48 ) )
continue;
if ( ! V_216 && V_48 -> V_185 )
V_216 = true ;
if ( V_48 -> V_89 . V_223 != V_89 . V_223 )
continue;
if ( V_48 -> V_185 && F_183 ( V_12 , V_48 ) )
break;
F_160 ( V_12 , V_48 , V_176 ) ;
if ( V_48 -> V_181 ) {
F_182 ( V_224 , V_12 ) ;
F_167 ( V_48 ) ;
} else if ( V_48 -> V_185 )
F_167 ( V_48 ) ;
F_198 ( V_48 ) ;
F_203 ( V_48 , false ) ;
return V_48 ;
}
++ V_12 -> V_99 -> V_134 . V_225 ;
V_48 = F_163 ( V_12 , V_176 , V_90 ) ;
if ( ! V_48 )
return V_48 ;
V_48 -> V_15 = V_15 ;
V_48 -> V_89 = V_89 ;
F_204 ( & V_48 -> V_173 ,
& V_12 -> V_99 -> V_34 . V_226 [ F_159 ( V_15 ) ] ) ;
if ( ! V_90 ) {
if ( F_121 ( V_12 , V_15 ) )
F_109 ( V_12 -> V_99 ) ;
if ( V_40 > V_41 && V_216 )
F_189 ( V_12 , V_15 ) ;
F_78 ( V_12 -> V_99 , V_48 ) ;
}
V_48 -> V_212 = V_12 -> V_99 -> V_34 . V_212 ;
F_197 ( V_48 ) ;
F_203 ( V_48 , true ) ;
return V_48 ;
}
static void F_205 ( struct V_227 * V_149 ,
struct V_11 * V_12 , T_1 V_228 )
{
V_149 -> V_228 = V_228 ;
V_149 -> V_229 = V_12 -> V_34 . V_197 . V_230 ;
V_149 -> V_40 = V_12 -> V_34 . V_197 . V_231 ;
if ( V_149 -> V_40 == V_206 &&
V_12 -> V_34 . V_197 . V_219 < V_206 &&
! V_12 -> V_34 . V_197 . V_218 )
-- V_149 -> V_40 ;
if ( V_149 -> V_40 == V_232 ) {
V_149 -> V_229
= V_12 -> V_34 . V_197 . V_233 [ ( V_228 >> 30 ) & 3 ] ;
V_149 -> V_229 &= V_42 ;
-- V_149 -> V_40 ;
if ( ! V_149 -> V_229 )
V_149 -> V_40 = 0 ;
}
}
static bool F_206 ( struct V_227 * V_149 )
{
if ( V_149 -> V_40 < V_41 )
return false ;
V_149 -> V_88 = F_207 ( V_149 -> V_228 , V_149 -> V_40 ) ;
V_149 -> V_14 = ( ( T_1 * ) F_208 ( V_149 -> V_229 ) ) + V_149 -> V_88 ;
return true ;
}
static void F_209 ( struct V_227 * V_149 ,
T_1 V_10 )
{
if ( F_25 ( V_10 , V_149 -> V_40 ) ) {
V_149 -> V_40 = 0 ;
return;
}
V_149 -> V_229 = V_10 & V_42 ;
-- V_149 -> V_40 ;
}
static void F_210 ( struct V_227 * V_149 )
{
return F_209 ( V_149 , * V_149 -> V_14 ) ;
}
static void F_211 ( T_1 * V_14 , struct V_47 * V_48 , bool V_234 )
{
T_1 V_10 ;
F_212 ( V_235 != V_38 ||
V_236 != V_137 ) ;
V_10 = F_36 ( V_48 -> V_130 ) | V_38 | V_137 |
V_29 | V_33 ;
if ( V_234 )
V_10 |= V_30 ;
F_9 ( V_14 , V_10 ) ;
}
static void F_213 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_237 )
{
if ( F_22 ( * V_14 ) && ! F_23 ( * V_14 ) ) {
struct V_47 * V_188 ;
V_188 = F_35 ( * V_14 & V_42 ) ;
if ( V_188 -> V_89 . V_16 == V_237 )
return;
F_162 ( V_188 , V_14 ) ;
F_109 ( V_12 -> V_99 ) ;
}
}
static bool F_214 ( struct V_99 * V_99 , struct V_47 * V_48 ,
T_1 * V_10 )
{
T_1 V_37 ;
struct V_47 * V_188 ;
V_37 = * V_10 ;
if ( F_22 ( V_37 ) ) {
if ( F_25 ( V_37 , V_48 -> V_89 . V_40 ) ) {
F_106 ( V_99 , V_10 ) ;
if ( F_23 ( V_37 ) )
-- V_99 -> V_134 . V_135 ;
} else {
V_188 = F_35 ( V_37 & V_42 ) ;
F_162 ( V_188 , V_10 ) ;
}
return true ;
}
if ( F_10 ( V_37 ) )
F_51 ( V_10 ) ;
return false ;
}
static void F_215 ( struct V_99 * V_99 ,
struct V_47 * V_48 )
{
unsigned V_103 ;
for ( V_103 = 0 ; V_103 < V_210 ; ++ V_103 )
F_214 ( V_99 , V_48 , V_48 -> V_130 + V_103 ) ;
}
static void F_216 ( struct V_47 * V_48 , T_1 * V_176 )
{
F_161 ( V_48 , V_176 ) ;
}
static void F_217 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
while ( ( V_14 = F_104 ( V_48 -> V_177 , & V_132 ) ) )
F_162 ( V_48 , V_14 ) ;
}
static int F_218 ( struct V_99 * V_99 ,
struct V_47 * V_205 ,
struct V_193 * V_194 )
{
int V_103 , V_238 = 0 ;
struct V_202 V_203 ;
struct V_183 V_207 ;
if ( V_205 -> V_89 . V_40 == V_41 )
return 0 ;
F_193 ( V_205 , & V_203 , & V_207 ) ;
while ( F_176 ( V_205 , & V_207 ) ) {
struct V_47 * V_48 ;
F_195 (pages, sp, parents, i) {
F_181 ( V_99 , V_48 , V_194 ) ;
F_192 ( & V_203 ) ;
V_238 ++ ;
}
F_193 ( V_205 , & V_203 , & V_207 ) ;
}
return V_238 ;
}
static int F_181 ( struct V_99 * V_99 , struct V_47 * V_48 ,
struct V_193 * V_194 )
{
int V_63 ;
F_219 ( V_48 ) ;
++ V_99 -> V_134 . V_239 ;
V_63 = F_218 ( V_99 , V_48 , V_194 ) ;
F_215 ( V_99 , V_48 ) ;
F_217 ( V_99 , V_48 ) ;
if ( ! V_48 -> V_89 . V_240 && ! V_48 -> V_89 . V_90 )
F_81 ( V_99 , V_48 ) ;
if ( V_48 -> V_185 )
F_177 ( V_99 , V_48 ) ;
if ( ! V_48 -> V_241 ) {
V_63 ++ ;
F_220 ( & V_48 -> V_174 , V_194 ) ;
F_153 ( V_99 , - 1 ) ;
} else {
F_220 ( & V_48 -> V_174 , & V_99 -> V_34 . V_178 ) ;
if ( ! V_48 -> V_89 . V_240 && ! F_200 ( V_99 , V_48 ) )
F_221 ( V_99 ) ;
}
V_48 -> V_89 . V_240 = 1 ;
return V_63 ;
}
static void F_185 ( struct V_99 * V_99 ,
struct V_193 * V_194 )
{
struct V_47 * V_48 , * V_242 ;
if ( F_222 ( V_194 ) )
return;
F_55 () ;
F_109 ( V_99 ) ;
F_223 (sp, nsp, invalid_list, link) {
F_3 ( ! V_48 -> V_89 . V_240 || V_48 -> V_241 ) ;
F_155 ( V_48 ) ;
}
}
static bool F_224 ( struct V_99 * V_99 ,
struct V_193 * V_194 )
{
struct V_47 * V_48 ;
if ( F_222 ( & V_99 -> V_34 . V_178 ) )
return false ;
V_48 = F_225 ( V_99 -> V_34 . V_178 . V_243 ,
struct V_47 , V_174 ) ;
F_181 ( V_99 , V_48 , V_194 ) ;
return true ;
}
void F_226 ( struct V_99 * V_99 , unsigned int V_244 )
{
F_184 ( V_194 ) ;
F_227 ( & V_99 -> V_209 ) ;
if ( V_99 -> V_34 . V_171 > V_244 ) {
while ( V_99 -> V_34 . V_171 > V_244 )
if ( ! F_224 ( V_99 , & V_194 ) )
break;
F_185 ( V_99 , & V_194 ) ;
V_244 = V_99 -> V_34 . V_171 ;
}
V_99 -> V_34 . V_245 = V_244 ;
F_228 ( & V_99 -> V_209 ) ;
}
int F_229 ( struct V_99 * V_99 , T_2 V_15 )
{
struct V_47 * V_48 ;
F_184 ( V_194 ) ;
int V_79 ;
F_230 ( L_15 , V_142 , V_15 ) ;
V_79 = 0 ;
F_227 ( & V_99 -> V_209 ) ;
F_190 (kvm, sp, gfn) {
F_230 ( L_16 , V_142 , V_15 ,
V_48 -> V_89 . V_223 ) ;
V_79 = 1 ;
F_181 ( V_99 , V_48 , & V_194 ) ;
}
F_185 ( V_99 , & V_194 ) ;
F_228 ( & V_99 -> V_209 ) ;
return V_79 ;
}
static void F_231 ( struct V_11 * V_12 , struct V_47 * V_48 )
{
F_232 ( V_48 ) ;
++ V_12 -> V_99 -> V_134 . V_192 ;
V_48 -> V_185 = 1 ;
F_167 ( V_48 ) ;
}
static void F_233 ( struct V_11 * V_12 , T_2 V_15 )
{
struct V_47 * V_201 ;
F_190 (vcpu->kvm, s, gfn) {
if ( V_201 -> V_185 )
continue;
F_3 ( V_201 -> V_89 . V_40 != V_41 ) ;
F_231 ( V_12 , V_201 ) ;
}
}
static int F_234 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_246 )
{
struct V_47 * V_201 ;
bool V_247 = false ;
F_190 (vcpu->kvm, s, gfn) {
if ( ! V_246 )
return 1 ;
if ( V_201 -> V_89 . V_40 != V_41 )
return 1 ;
if ( ! V_201 -> V_185 )
V_247 = true ;
}
if ( V_247 )
F_233 ( V_12 , V_15 ) ;
return 0 ;
}
static bool F_235 ( T_3 V_21 )
{
if ( F_236 ( V_21 ) )
return ! F_237 ( V_21 ) && F_238 ( F_50 ( V_21 ) ) ;
return true ;
}
static int F_239 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_248 , int V_40 ,
T_2 V_15 , T_3 V_21 , bool V_249 ,
bool V_246 , bool V_250 )
{
T_1 V_10 ;
int V_63 = 0 ;
if ( F_13 ( V_12 , V_14 , V_15 , V_21 , V_248 ) )
return 0 ;
V_10 = V_38 ;
if ( ! V_249 )
V_10 |= V_30 ;
if ( V_248 & V_251 )
V_10 |= V_33 ;
else
V_10 |= V_32 ;
if ( V_248 & V_18 )
V_10 |= V_29 ;
if ( V_40 > V_41 )
V_10 |= V_39 ;
if ( V_252 )
V_10 |= V_117 -> V_253 ( V_12 , V_15 ,
F_235 ( V_21 ) ) ;
if ( V_250 )
V_10 |= V_58 ;
else
V_248 &= ~ V_17 ;
V_10 |= ( T_1 ) V_21 << V_19 ;
if ( V_248 & V_17 ) {
if ( V_40 > V_41 &&
F_83 ( V_12 , V_15 , V_40 ) )
goto V_254;
V_10 |= V_137 | V_59 ;
if ( ! V_246 && F_41 ( * V_14 ) )
goto V_255;
if ( F_234 ( V_12 , V_15 , V_246 ) ) {
F_230 ( L_17 ,
V_142 , V_15 ) ;
V_63 = 1 ;
V_248 &= ~ V_17 ;
V_10 &= ~ ( V_137 | V_59 ) ;
}
}
if ( V_248 & V_17 ) {
F_240 ( V_12 , V_15 ) ;
V_10 |= V_31 ;
}
V_255:
if ( F_44 ( V_14 , V_10 ) )
F_109 ( V_12 -> V_99 ) ;
V_254:
return V_63 ;
}
static void F_241 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_248 , int V_256 , int * V_257 ,
int V_40 , T_2 V_15 , T_3 V_21 , bool V_249 ,
bool V_250 )
{
int V_258 = 0 ;
int V_259 ;
F_230 ( L_18 , V_142 ,
* V_14 , V_256 , V_15 ) ;
if ( F_24 ( * V_14 ) ) {
if ( V_40 > V_41 &&
! F_23 ( * V_14 ) ) {
struct V_47 * V_188 ;
T_1 V_37 = * V_14 ;
V_188 = F_35 ( V_37 & V_42 ) ;
F_162 ( V_188 , V_14 ) ;
F_109 ( V_12 -> V_99 ) ;
} else if ( V_21 != F_26 ( * V_14 ) ) {
F_230 ( L_19 ,
F_26 ( * V_14 ) , V_21 ) ;
F_106 ( V_12 -> V_99 , V_14 ) ;
F_109 ( V_12 -> V_99 ) ;
} else
V_258 = 1 ;
}
if ( F_239 ( V_12 , V_14 , V_248 , V_40 , V_15 , V_21 , V_249 ,
true , V_250 ) ) {
if ( V_256 )
* V_257 = 1 ;
F_182 ( V_199 , V_12 ) ;
}
if ( F_14 ( F_10 ( * V_14 ) && V_257 ) )
* V_257 = 1 ;
F_230 ( L_20 , V_142 , * V_14 ) ;
F_230 ( L_21 ,
F_23 ( * V_14 ) ? L_22 : L_23 ,
* V_14 & V_38 ? L_24 : L_25 , V_15 ,
* V_14 , V_14 ) ;
if ( ! V_258 && F_23 ( * V_14 ) )
++ V_12 -> V_99 -> V_134 . V_135 ;
if ( F_22 ( * V_14 ) ) {
if ( ! V_258 ) {
V_259 = F_102 ( V_12 , V_14 , V_15 ) ;
if ( V_259 > V_260 )
F_149 ( V_12 , V_14 , V_15 ) ;
}
}
F_242 ( V_21 ) ;
}
static T_3 F_243 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_109 )
{
struct V_94 * V_95 ;
V_95 = F_89 ( V_12 , V_15 , V_109 ) ;
if ( ! V_95 )
return V_261 ;
return F_244 ( V_95 , V_15 ) ;
}
static int F_245 ( struct V_11 * V_12 ,
struct V_47 * V_48 ,
T_1 * V_155 , T_1 * V_156 )
{
struct V_78 * V_207 [ V_82 ] ;
struct V_94 * V_95 ;
unsigned V_16 = V_48 -> V_89 . V_16 ;
int V_103 , V_63 ;
T_2 V_15 ;
V_15 = F_74 ( V_48 , V_155 - V_48 -> V_130 ) ;
V_95 = F_89 ( V_12 , V_15 , V_16 & V_17 ) ;
if ( ! V_95 )
return - 1 ;
V_63 = F_246 ( V_95 , V_15 , V_207 , V_156 - V_155 ) ;
if ( V_63 <= 0 )
return - 1 ;
for ( V_103 = 0 ; V_103 < V_63 ; V_103 ++ , V_15 ++ , V_155 ++ )
F_241 ( V_12 , V_155 , V_16 , 0 , NULL ,
V_48 -> V_89 . V_40 , V_15 , F_247 ( V_207 [ V_103 ] ) ,
true , true ) ;
return 0 ;
}
static void F_248 ( struct V_11 * V_12 ,
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
if ( F_245 ( V_12 , V_48 , V_155 , V_10 ) < 0 )
break;
V_155 = NULL ;
} else if ( ! V_155 )
V_155 = V_10 ;
}
}
static void F_249 ( struct V_11 * V_12 , T_1 * V_14 )
{
struct V_47 * V_48 ;
if ( ! V_30 )
return;
V_48 = F_35 ( F_36 ( V_14 ) ) ;
if ( V_48 -> V_89 . V_40 > V_41 )
return;
F_248 ( V_12 , V_48 , V_14 ) ;
}
static int F_250 ( struct V_11 * V_12 , T_8 V_262 , int V_263 ,
int V_264 , int V_40 , T_2 V_15 , T_3 V_21 ,
bool V_265 )
{
struct V_227 V_149 ;
struct V_47 * V_48 ;
int V_257 = 0 ;
T_2 V_266 ;
if ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) )
return 0 ;
F_252 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_149 . V_40 == V_40 ) {
F_241 ( V_12 , V_149 . V_14 , V_267 ,
V_263 , & V_257 , V_40 , V_15 , V_21 ,
V_265 , V_264 ) ;
F_249 ( V_12 , V_149 . V_14 ) ;
++ V_12 -> V_134 . V_268 ;
break;
}
F_108 ( V_12 , V_149 . V_14 ) ;
if ( ! F_22 ( * V_149 . V_14 ) ) {
T_1 V_269 = V_149 . V_228 ;
V_269 &= F_253 ( V_149 . V_40 ) ;
V_266 = V_269 >> V_19 ;
V_48 = F_201 ( V_12 , V_266 , V_149 . V_228 ,
V_149 . V_40 - 1 ,
1 , V_267 , V_149 . V_14 ) ;
F_211 ( V_149 . V_14 , V_48 , true ) ;
}
}
return V_257 ;
}
static void F_254 ( unsigned long V_270 , struct V_271 * V_272 )
{
T_9 V_273 ;
V_273 . V_274 = V_275 ;
V_273 . V_276 = 0 ;
V_273 . V_277 = V_278 ;
V_273 . V_279 = ( void V_280 * ) V_270 ;
V_273 . V_281 = V_19 ;
F_255 ( V_275 , & V_273 , V_272 ) ;
}
static int F_256 ( struct V_11 * V_12 , T_2 V_15 , T_3 V_21 )
{
if ( V_21 == V_282 )
return 1 ;
if ( V_21 == V_283 ) {
F_254 ( F_257 ( V_12 , V_15 ) , V_284 ) ;
return 0 ;
}
return - V_285 ;
}
static void F_258 ( struct V_11 * V_12 ,
T_2 * V_286 , T_3 * V_287 , int * V_288 )
{
T_3 V_21 = * V_287 ;
T_2 V_15 = * V_286 ;
int V_40 = * V_288 ;
if ( ! F_259 ( V_21 ) && ! F_48 ( V_21 ) &&
V_40 == V_41 &&
F_260 ( F_50 ( V_21 ) ) &&
! F_83 ( V_12 , V_15 , V_104 ) ) {
unsigned long V_4 ;
* V_288 = V_40 = V_104 ;
V_4 = F_261 ( V_40 ) - 1 ;
F_262 ( ( V_15 & V_4 ) != ( V_21 & V_4 ) ) ;
if ( V_21 & V_4 ) {
V_15 &= ~ V_4 ;
* V_286 = V_15 ;
F_242 ( V_21 ) ;
V_21 &= ~ V_4 ;
F_263 ( V_21 ) ;
* V_287 = V_21 ;
}
}
}
static bool F_264 ( struct V_11 * V_12 , T_7 V_182 , T_2 V_15 ,
T_3 V_21 , unsigned V_16 , int * V_289 )
{
bool V_63 = true ;
if ( F_14 ( F_265 ( V_21 ) ) ) {
* V_289 = F_256 ( V_12 , V_15 , V_21 ) ;
goto exit;
}
if ( F_14 ( F_15 ( V_21 ) ) )
F_266 ( V_12 , V_182 , V_15 , V_16 ) ;
V_63 = false ;
exit:
return V_63 ;
}
static bool F_267 ( T_4 V_290 )
{
if ( F_14 ( V_290 & V_291 ) )
return false ;
if ( ! ( V_290 & V_292 ) ||
! ( V_290 & V_293 ) )
return false ;
return true ;
}
static bool
F_268 ( struct V_11 * V_12 , struct V_47 * V_48 ,
T_1 * V_14 , T_1 V_10 )
{
T_2 V_15 ;
F_3 ( ! V_48 -> V_89 . V_90 ) ;
V_15 = F_74 ( V_48 , V_14 - V_48 -> V_130 ) ;
if ( F_269 ( V_14 , V_10 , V_10 | V_137 ) == V_10 )
F_240 ( V_12 , V_15 ) ;
return true ;
}
static bool F_270 ( struct V_11 * V_12 , T_7 V_182 , int V_40 ,
T_4 V_290 )
{
struct V_227 V_149 ;
struct V_47 * V_48 ;
bool V_63 = false ;
T_1 V_10 = 0ull ;
if ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) )
return false ;
if ( ! F_267 ( V_290 ) )
return false ;
F_53 ( V_12 ) ;
F_271 (vcpu, gva, iterator, spte)
if ( ! F_22 ( V_10 ) || V_149 . V_40 < V_40 )
break;
if ( ! F_24 ( V_10 ) ) {
V_63 = true ;
goto exit;
}
V_48 = F_35 ( F_36 ( V_149 . V_14 ) ) ;
if ( ! F_25 ( V_10 , V_48 -> V_89 . V_40 ) )
goto exit;
if ( F_41 ( V_10 ) ) {
V_63 = true ;
goto exit;
}
if ( ! F_39 ( V_10 ) )
goto exit;
if ( V_48 -> V_89 . V_40 > V_41 )
goto exit;
V_63 = F_268 ( V_12 , V_48 , V_149 . V_14 , V_10 ) ;
exit:
F_272 ( V_12 , V_182 , V_290 , V_149 . V_14 ,
V_10 , V_63 ) ;
F_56 ( V_12 ) ;
return V_63 ;
}
static int F_273 ( struct V_11 * V_12 , T_7 V_262 , T_4 V_290 ,
T_2 V_15 , bool V_265 )
{
int V_79 ;
int V_40 ;
bool V_114 = false ;
T_3 V_21 ;
unsigned long V_294 ;
bool V_264 , V_263 = V_290 & V_293 ;
V_40 = F_90 ( V_12 , V_15 , & V_114 ) ;
if ( F_18 ( ! V_114 ) ) {
if ( V_40 > V_104 )
V_40 = V_104 ;
V_15 &= ~ ( F_261 ( V_40 ) - 1 ) ;
}
if ( F_270 ( V_12 , V_262 , V_40 , V_290 ) )
return 0 ;
V_294 = V_12 -> V_99 -> V_169 ;
F_38 () ;
if ( F_274 ( V_12 , V_265 , V_15 , V_262 , & V_21 , V_263 , & V_264 ) )
return 0 ;
if ( F_264 ( V_12 , V_262 , V_15 , V_21 , V_267 , & V_79 ) )
return V_79 ;
F_227 ( & V_12 -> V_99 -> V_209 ) ;
if ( F_275 ( V_12 -> V_99 , V_294 ) )
goto V_295;
F_276 ( V_12 ) ;
if ( F_18 ( ! V_114 ) )
F_258 ( V_12 , & V_15 , & V_21 , & V_40 ) ;
V_79 = F_250 ( V_12 , V_262 , V_263 , V_264 , V_40 , V_15 , V_21 ,
V_265 ) ;
F_228 ( & V_12 -> V_99 -> V_209 ) ;
return V_79 ;
V_295:
F_228 ( & V_12 -> V_99 -> V_209 ) ;
F_242 ( V_21 ) ;
return 0 ;
}
static void F_277 ( struct V_11 * V_12 )
{
int V_103 ;
struct V_47 * V_48 ;
F_184 ( V_194 ) ;
if ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) )
return;
if ( V_12 -> V_34 . V_197 . V_231 == V_206 &&
( V_12 -> V_34 . V_197 . V_219 == V_206 ||
V_12 -> V_34 . V_197 . V_218 ) ) {
T_10 V_296 = V_12 -> V_34 . V_197 . V_230 ;
F_227 ( & V_12 -> V_99 -> V_209 ) ;
V_48 = F_35 ( V_296 ) ;
-- V_48 -> V_241 ;
if ( ! V_48 -> V_241 && V_48 -> V_89 . V_240 ) {
F_181 ( V_12 -> V_99 , V_48 , & V_194 ) ;
F_185 ( V_12 -> V_99 , & V_194 ) ;
}
F_228 ( & V_12 -> V_99 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_230 = V_297 ;
return;
}
F_227 ( & V_12 -> V_99 -> V_209 ) ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_10 V_296 = V_12 -> V_34 . V_197 . V_233 [ V_103 ] ;
if ( V_296 ) {
V_296 &= V_42 ;
V_48 = F_35 ( V_296 ) ;
-- V_48 -> V_241 ;
if ( ! V_48 -> V_241 && V_48 -> V_89 . V_240 )
F_181 ( V_12 -> V_99 , V_48 ,
& V_194 ) ;
}
V_12 -> V_34 . V_197 . V_233 [ V_103 ] = V_297 ;
}
F_185 ( V_12 -> V_99 , & V_194 ) ;
F_228 ( & V_12 -> V_99 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_230 = V_297 ;
}
static int F_278 ( struct V_11 * V_12 , T_2 V_298 )
{
int V_63 = 0 ;
if ( ! F_279 ( V_12 -> V_99 , V_298 ) ) {
F_182 ( V_299 , V_12 ) ;
V_63 = 1 ;
}
return V_63 ;
}
static int F_280 ( struct V_11 * V_12 )
{
struct V_47 * V_48 ;
unsigned V_103 ;
if ( V_12 -> V_34 . V_197 . V_231 == V_206 ) {
F_227 ( & V_12 -> V_99 -> V_209 ) ;
F_276 ( V_12 ) ;
V_48 = F_201 ( V_12 , 0 , 0 , V_206 ,
1 , V_267 , NULL ) ;
++ V_48 -> V_241 ;
F_228 ( & V_12 -> V_99 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_230 = F_36 ( V_48 -> V_130 ) ;
} else if ( V_12 -> V_34 . V_197 . V_231 == V_232 ) {
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_10 V_296 = V_12 -> V_34 . V_197 . V_233 [ V_103 ] ;
F_156 ( F_251 ( V_296 ) ) ;
F_227 ( & V_12 -> V_99 -> V_209 ) ;
F_276 ( V_12 ) ;
V_48 = F_201 ( V_12 , V_103 << ( 30 - V_19 ) ,
V_103 << 30 ,
V_220 , 1 , V_267 ,
NULL ) ;
V_296 = F_36 ( V_48 -> V_130 ) ;
++ V_48 -> V_241 ;
F_228 ( & V_12 -> V_99 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_233 [ V_103 ] = V_296 | V_38 ;
}
V_12 -> V_34 . V_197 . V_230 = F_36 ( V_12 -> V_34 . V_197 . V_233 ) ;
} else
F_96 () ;
return 0 ;
}
static int F_281 ( struct V_11 * V_12 )
{
struct V_47 * V_48 ;
T_1 V_300 , V_301 ;
T_2 V_298 ;
int V_103 ;
V_298 = V_12 -> V_34 . V_197 . V_302 ( V_12 ) >> V_19 ;
if ( F_278 ( V_12 , V_298 ) )
return 1 ;
if ( V_12 -> V_34 . V_197 . V_219 == V_206 ) {
T_10 V_296 = V_12 -> V_34 . V_197 . V_230 ;
F_156 ( F_251 ( V_296 ) ) ;
F_227 ( & V_12 -> V_99 -> V_209 ) ;
F_276 ( V_12 ) ;
V_48 = F_201 ( V_12 , V_298 , 0 , V_206 ,
0 , V_267 , NULL ) ;
V_296 = F_36 ( V_48 -> V_130 ) ;
++ V_48 -> V_241 ;
F_228 ( & V_12 -> V_99 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_230 = V_296 ;
return 0 ;
}
V_301 = V_38 ;
if ( V_12 -> V_34 . V_197 . V_231 == V_206 )
V_301 |= V_303 | V_137 | V_304 ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_10 V_296 = V_12 -> V_34 . V_197 . V_233 [ V_103 ] ;
F_156 ( F_251 ( V_296 ) ) ;
if ( V_12 -> V_34 . V_197 . V_219 == V_232 ) {
V_300 = V_12 -> V_34 . V_197 . V_305 ( V_12 , V_103 ) ;
if ( ! F_282 ( V_300 ) ) {
V_12 -> V_34 . V_197 . V_233 [ V_103 ] = 0 ;
continue;
}
V_298 = V_300 >> V_19 ;
if ( F_278 ( V_12 , V_298 ) )
return 1 ;
}
F_227 ( & V_12 -> V_99 -> V_209 ) ;
F_276 ( V_12 ) ;
V_48 = F_201 ( V_12 , V_298 , V_103 << 30 ,
V_220 , 0 ,
V_267 , NULL ) ;
V_296 = F_36 ( V_48 -> V_130 ) ;
++ V_48 -> V_241 ;
F_228 ( & V_12 -> V_99 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_233 [ V_103 ] = V_296 | V_301 ;
}
V_12 -> V_34 . V_197 . V_230 = F_36 ( V_12 -> V_34 . V_197 . V_233 ) ;
if ( V_12 -> V_34 . V_197 . V_231 == V_206 ) {
if ( V_12 -> V_34 . V_197 . V_306 == NULL ) {
T_1 * V_306 ;
V_306 = ( void * ) F_283 ( V_75 ) ;
if ( V_306 == NULL )
return 1 ;
V_306 [ 0 ] = F_36 ( V_12 -> V_34 . V_197 . V_233 ) | V_301 ;
V_12 -> V_34 . V_197 . V_306 = V_306 ;
}
V_12 -> V_34 . V_197 . V_230 = F_36 ( V_12 -> V_34 . V_197 . V_306 ) ;
}
return 0 ;
}
static int F_284 ( struct V_11 * V_12 )
{
if ( V_12 -> V_34 . V_197 . V_218 )
return F_280 ( V_12 ) ;
else
return F_281 ( V_12 ) ;
}
static void F_285 ( struct V_11 * V_12 )
{
int V_103 ;
struct V_47 * V_48 ;
if ( V_12 -> V_34 . V_197 . V_218 )
return;
if ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) )
return;
F_286 ( V_12 , V_307 ) ;
F_186 ( V_12 , V_308 ) ;
if ( V_12 -> V_34 . V_197 . V_219 == V_206 ) {
T_10 V_296 = V_12 -> V_34 . V_197 . V_230 ;
V_48 = F_35 ( V_296 ) ;
F_194 ( V_12 , V_48 ) ;
F_186 ( V_12 , V_309 ) ;
return;
}
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_10 V_296 = V_12 -> V_34 . V_197 . V_233 [ V_103 ] ;
if ( V_296 && F_251 ( V_296 ) ) {
V_296 &= V_42 ;
V_48 = F_35 ( V_296 ) ;
F_194 ( V_12 , V_48 ) ;
}
}
F_186 ( V_12 , V_309 ) ;
}
void F_287 ( struct V_11 * V_12 )
{
F_227 ( & V_12 -> V_99 -> V_209 ) ;
F_285 ( V_12 ) ;
F_228 ( & V_12 -> V_99 -> V_209 ) ;
}
static T_8 F_288 ( struct V_11 * V_12 , T_7 V_310 ,
T_4 V_16 , struct V_311 * V_312 )
{
if ( V_312 )
V_312 -> V_290 = 0 ;
return V_310 ;
}
static T_8 F_289 ( struct V_11 * V_12 , T_7 V_310 ,
T_4 V_16 ,
struct V_311 * V_312 )
{
if ( V_312 )
V_312 -> V_290 = 0 ;
return V_12 -> V_34 . V_313 . V_314 ( V_12 , V_310 , V_16 , V_312 ) ;
}
static bool
F_290 ( struct V_315 * V_316 , T_1 V_37 , int V_40 )
{
int V_317 = ( V_37 >> 7 ) & 1 , V_318 = V_37 & 0x3f ;
return ( V_37 & V_316 -> V_319 [ V_317 ] [ V_40 - 1 ] ) |
( ( V_316 -> V_320 & ( 1ull << V_318 ) ) != 0 ) ;
}
static bool F_291 ( struct V_321 * V_197 , T_1 V_43 , int V_40 )
{
return F_290 ( & V_197 -> V_322 , V_43 , V_40 ) ;
}
static bool F_292 ( struct V_321 * V_197 , T_1 V_10 , int V_40 )
{
return F_290 ( & V_197 -> V_323 , V_10 , V_40 ) ;
}
static bool F_293 ( struct V_11 * V_12 , T_1 V_228 , bool V_90 )
{
if ( V_90 )
return F_294 ( V_12 , V_228 ) ;
return F_295 ( V_12 , V_228 ) ;
}
static bool
F_296 ( struct V_11 * V_12 , T_1 V_228 , T_1 * V_14 )
{
struct V_227 V_149 ;
T_1 V_121 [ V_206 ] , V_10 = 0ull ;
int V_296 , V_324 ;
bool V_325 = false ;
if ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) )
goto exit;
F_53 ( V_12 ) ;
for ( F_205 ( & V_149 , V_12 , V_228 ) ,
V_324 = V_296 = V_149 . V_40 ;
F_206 ( & V_149 ) ;
F_209 ( & V_149 , V_10 ) ) {
V_10 = F_52 ( V_149 . V_14 ) ;
V_121 [ V_324 - 1 ] = V_10 ;
V_324 -- ;
if ( ! F_22 ( V_10 ) )
break;
V_325 |= F_292 ( & V_12 -> V_34 . V_197 , V_10 ,
V_149 . V_40 ) ;
}
F_56 ( V_12 ) ;
if ( V_325 ) {
F_97 ( L_26 ,
V_142 , V_228 ) ;
while ( V_296 > V_324 ) {
F_97 ( L_27 ,
V_121 [ V_296 - 1 ] , V_296 ) ;
V_296 -- ;
}
}
exit:
* V_14 = V_10 ;
return V_325 ;
}
int F_297 ( struct V_11 * V_12 , T_1 V_228 , bool V_90 )
{
T_1 V_10 ;
bool V_325 ;
if ( F_293 ( V_12 , V_228 , V_90 ) )
return V_326 ;
V_325 = F_296 ( V_12 , V_228 , & V_10 ) ;
if ( F_3 ( V_325 ) )
return V_327 ;
if ( F_10 ( V_10 ) ) {
T_2 V_15 = F_11 ( V_10 ) ;
unsigned V_16 = F_12 ( V_10 ) ;
if ( ! F_16 ( V_12 , V_10 ) )
return V_328 ;
if ( V_90 )
V_228 = 0 ;
F_298 ( V_228 , V_15 , V_16 ) ;
F_266 ( V_12 , V_228 , V_15 , V_16 ) ;
return V_326 ;
}
return V_329 ;
}
static int F_299 ( struct V_11 * V_12 , T_7 V_182 ,
T_4 V_290 , bool V_265 )
{
T_2 V_15 ;
int V_79 ;
F_230 ( L_28 , V_142 , V_182 , V_290 ) ;
if ( F_14 ( V_290 & V_291 ) ) {
V_79 = F_297 ( V_12 , V_182 , true ) ;
if ( F_18 ( V_79 != V_328 ) )
return V_79 ;
}
V_79 = F_68 ( V_12 ) ;
if ( V_79 )
return V_79 ;
F_156 ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) ) ;
V_15 = V_182 >> V_19 ;
return F_273 ( V_12 , V_182 & V_20 ,
V_290 , V_15 , V_265 ) ;
}
static int F_300 ( struct V_11 * V_12 , T_7 V_182 , T_2 V_15 )
{
struct V_330 V_34 ;
V_34 . V_331 = ( V_12 -> V_34 . V_332 . V_333 ++ << 12 ) | V_12 -> V_334 ;
V_34 . V_15 = V_15 ;
V_34 . V_218 = V_12 -> V_34 . V_197 . V_218 ;
V_34 . V_335 = V_12 -> V_34 . V_197 . V_302 ( V_12 ) ;
return F_301 ( V_12 , V_182 , F_257 ( V_12 , V_15 ) , & V_34 ) ;
}
static bool F_302 ( struct V_11 * V_12 )
{
if ( F_14 ( ! F_303 ( V_12 ) ||
F_304 ( V_12 ) ) )
return false ;
return V_117 -> V_336 ( V_12 ) ;
}
static bool F_274 ( struct V_11 * V_12 , bool V_265 , T_2 V_15 ,
T_7 V_182 , T_3 * V_21 , bool V_263 , bool * V_337 )
{
struct V_94 * V_95 ;
bool V_338 ;
V_95 = F_84 ( V_12 , V_15 ) ;
V_338 = false ;
* V_21 = F_305 ( V_95 , V_15 , false , & V_338 , V_263 , V_337 ) ;
if ( ! V_338 )
return false ;
if ( ! V_265 && F_302 ( V_12 ) ) {
F_306 ( V_182 , V_15 ) ;
if ( F_307 ( V_12 , V_15 ) ) {
F_308 ( V_182 , V_15 ) ;
F_182 ( V_339 , V_12 ) ;
return true ;
} else if ( F_300 ( V_12 , V_182 , V_15 ) )
return true ;
}
* V_21 = F_305 ( V_95 , V_15 , false , NULL , V_263 , V_337 ) ;
return false ;
}
static bool
F_309 ( struct V_11 * V_12 , T_2 V_15 , int V_40 )
{
int V_340 = F_261 ( V_40 ) ;
V_15 &= ~ ( V_340 - 1 ) ;
return F_310 ( V_12 , V_15 , V_340 ) ;
}
static int F_311 ( struct V_11 * V_12 , T_7 V_341 , T_4 V_290 ,
bool V_265 )
{
T_3 V_21 ;
int V_79 ;
int V_40 ;
bool V_114 ;
T_2 V_15 = V_341 >> V_19 ;
unsigned long V_294 ;
int V_263 = V_290 & V_293 ;
bool V_264 ;
F_156 ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) ) ;
if ( F_14 ( V_290 & V_291 ) ) {
V_79 = F_297 ( V_12 , V_341 , true ) ;
if ( F_18 ( V_79 != V_328 ) )
return V_79 ;
}
V_79 = F_68 ( V_12 ) ;
if ( V_79 )
return V_79 ;
V_114 = ! F_309 ( V_12 , V_15 ,
V_104 ) ;
V_40 = F_90 ( V_12 , V_15 , & V_114 ) ;
if ( F_18 ( ! V_114 ) ) {
if ( V_40 > V_104 &&
! F_309 ( V_12 , V_15 , V_40 ) )
V_40 = V_104 ;
V_15 &= ~ ( F_261 ( V_40 ) - 1 ) ;
}
if ( F_270 ( V_12 , V_341 , V_40 , V_290 ) )
return 0 ;
V_294 = V_12 -> V_99 -> V_169 ;
F_38 () ;
if ( F_274 ( V_12 , V_265 , V_15 , V_341 , & V_21 , V_263 , & V_264 ) )
return 0 ;
if ( F_264 ( V_12 , 0 , V_15 , V_21 , V_267 , & V_79 ) )
return V_79 ;
F_227 ( & V_12 -> V_99 -> V_209 ) ;
if ( F_275 ( V_12 -> V_99 , V_294 ) )
goto V_295;
F_276 ( V_12 ) ;
if ( F_18 ( ! V_114 ) )
F_258 ( V_12 , & V_15 , & V_21 , & V_40 ) ;
V_79 = F_250 ( V_12 , V_341 , V_263 , V_264 ,
V_40 , V_15 , V_21 , V_265 ) ;
F_228 ( & V_12 -> V_99 -> V_209 ) ;
return V_79 ;
V_295:
F_228 ( & V_12 -> V_99 -> V_209 ) ;
F_242 ( V_21 ) ;
return 0 ;
}
static void F_312 ( struct V_11 * V_12 ,
struct V_321 * V_342 )
{
V_342 -> V_343 = F_299 ;
V_342 -> V_344 = F_288 ;
V_342 -> V_198 = F_169 ;
V_342 -> V_345 = F_170 ;
V_342 -> V_346 = F_171 ;
V_342 -> V_219 = 0 ;
V_342 -> V_231 = V_232 ;
V_342 -> V_230 = V_297 ;
V_342 -> V_218 = true ;
V_342 -> V_347 = false ;
}
void F_313 ( struct V_11 * V_12 )
{
F_277 ( V_12 ) ;
}
static unsigned long V_302 ( struct V_11 * V_12 )
{
return F_314 ( V_12 ) ;
}
static void F_315 ( struct V_11 * V_12 ,
struct V_311 * V_348 )
{
V_12 -> V_34 . V_197 . F_315 ( V_12 , V_348 ) ;
}
static bool F_316 ( struct V_11 * V_12 , T_1 * V_14 , T_2 V_15 ,
unsigned V_16 , int * V_349 )
{
if ( F_14 ( F_10 ( * V_14 ) ) ) {
if ( V_15 != F_11 ( * V_14 ) ) {
F_51 ( V_14 ) ;
return true ;
}
( * V_349 ) ++ ;
F_7 ( V_12 , V_14 , V_15 , V_16 ) ;
return true ;
}
return false ;
}
static inline bool F_317 ( struct V_321 * V_197 , unsigned V_40 , unsigned V_43 )
{
unsigned V_88 ;
V_88 = V_40 - 1 ;
V_88 |= ( V_43 & V_39 ) >> ( V_350 - 2 ) ;
return V_197 -> V_351 & ( 1 << V_88 ) ;
}
static void
F_318 ( struct V_11 * V_12 ,
struct V_315 * V_316 ,
int V_352 , int V_40 , bool V_347 , bool V_353 ,
bool V_354 , bool V_355 )
{
T_1 V_356 = 0 ;
T_1 V_357 = 0 ;
T_1 V_358 = 0 ;
V_316 -> V_320 = 0 ;
if ( ! V_347 )
V_356 = F_319 ( 63 , 63 ) ;
if ( ! V_353 )
V_357 = F_319 ( 7 , 7 ) ;
if ( V_355 )
V_358 = F_319 ( 8 , 8 ) ;
switch ( V_40 ) {
case V_220 :
V_316 -> V_319 [ 0 ] [ 1 ] = 0 ;
V_316 -> V_319 [ 0 ] [ 0 ] = 0 ;
V_316 -> V_319 [ 1 ] [ 0 ] =
V_316 -> V_319 [ 0 ] [ 0 ] ;
if ( ! V_354 ) {
V_316 -> V_319 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_20 () )
V_316 -> V_319 [ 1 ] [ 1 ] = F_319 ( 17 , 21 ) ;
else
V_316 -> V_319 [ 1 ] [ 1 ] = F_319 ( 13 , 21 ) ;
break;
case V_232 :
V_316 -> V_319 [ 0 ] [ 2 ] =
F_319 ( V_352 , 63 ) |
F_319 ( 5 , 8 ) | F_319 ( 1 , 2 ) ;
V_316 -> V_319 [ 0 ] [ 1 ] = V_356 |
F_319 ( V_352 , 62 ) ;
V_316 -> V_319 [ 0 ] [ 0 ] = V_356 |
F_319 ( V_352 , 62 ) ;
V_316 -> V_319 [ 1 ] [ 1 ] = V_356 |
F_319 ( V_352 , 62 ) |
F_319 ( 13 , 20 ) ;
V_316 -> V_319 [ 1 ] [ 0 ] =
V_316 -> V_319 [ 0 ] [ 0 ] ;
break;
case V_206 :
V_316 -> V_319 [ 0 ] [ 3 ] = V_356 |
V_358 | F_319 ( 7 , 7 ) |
F_319 ( V_352 , 51 ) ;
V_316 -> V_319 [ 0 ] [ 2 ] = V_356 |
V_358 | V_357 |
F_319 ( V_352 , 51 ) ;
V_316 -> V_319 [ 0 ] [ 1 ] = V_356 |
F_319 ( V_352 , 51 ) ;
V_316 -> V_319 [ 0 ] [ 0 ] = V_356 |
F_319 ( V_352 , 51 ) ;
V_316 -> V_319 [ 1 ] [ 3 ] =
V_316 -> V_319 [ 0 ] [ 3 ] ;
V_316 -> V_319 [ 1 ] [ 2 ] = V_356 |
V_357 | F_319 ( V_352 , 51 ) |
F_319 ( 13 , 29 ) ;
V_316 -> V_319 [ 1 ] [ 1 ] = V_356 |
F_319 ( V_352 , 51 ) |
F_319 ( 13 , 20 ) ;
V_316 -> V_319 [ 1 ] [ 0 ] =
V_316 -> V_319 [ 0 ] [ 0 ] ;
break;
}
}
static void F_320 ( struct V_11 * V_12 ,
struct V_321 * V_342 )
{
F_318 ( V_12 , & V_342 -> V_322 ,
F_321 ( V_12 ) , V_342 -> V_219 ,
V_342 -> V_347 , F_322 ( V_12 ) ,
F_323 ( V_12 ) , F_324 ( V_12 ) ) ;
}
static void
F_325 ( struct V_315 * V_316 ,
int V_352 , bool V_359 )
{
T_1 V_320 ;
V_316 -> V_319 [ 0 ] [ 3 ] =
F_319 ( V_352 , 51 ) | F_319 ( 3 , 7 ) ;
V_316 -> V_319 [ 0 ] [ 2 ] =
F_319 ( V_352 , 51 ) | F_319 ( 3 , 6 ) ;
V_316 -> V_319 [ 0 ] [ 1 ] =
F_319 ( V_352 , 51 ) | F_319 ( 3 , 6 ) ;
V_316 -> V_319 [ 0 ] [ 0 ] = F_319 ( V_352 , 51 ) ;
V_316 -> V_319 [ 1 ] [ 3 ] = V_316 -> V_319 [ 0 ] [ 3 ] ;
V_316 -> V_319 [ 1 ] [ 2 ] =
F_319 ( V_352 , 51 ) | F_319 ( 12 , 29 ) ;
V_316 -> V_319 [ 1 ] [ 1 ] =
F_319 ( V_352 , 51 ) | F_319 ( 12 , 20 ) ;
V_316 -> V_319 [ 1 ] [ 0 ] = V_316 -> V_319 [ 0 ] [ 0 ] ;
V_320 = 0xFFull << ( 2 * 8 ) ;
V_320 |= 0xFFull << ( 3 * 8 ) ;
V_320 |= 0xFFull << ( 7 * 8 ) ;
V_320 |= F_326 ( 1ull << 2 ) ;
V_320 |= F_326 ( 1ull << 6 ) ;
if ( ! V_359 ) {
V_320 |= F_326 ( 1ull << 4 ) ;
}
V_316 -> V_320 = V_320 ;
}
static void F_327 ( struct V_11 * V_12 ,
struct V_321 * V_342 , bool V_359 )
{
F_325 ( & V_342 -> V_322 ,
F_321 ( V_12 ) , V_359 ) ;
}
void
F_328 ( struct V_11 * V_12 , struct V_321 * V_342 )
{
F_318 ( V_12 , & V_342 -> V_323 ,
V_360 . V_361 ,
V_342 -> V_231 , V_342 -> V_347 ,
F_322 ( V_12 ) , F_323 ( V_12 ) ,
true ) ;
}
static inline bool F_329 ( void )
{
F_330 ( ! V_252 ) ;
return V_33 == 0 ;
}
static void
F_331 ( struct V_11 * V_12 ,
struct V_321 * V_342 )
{
if ( F_329 () )
F_318 ( V_12 , & V_342 -> V_323 ,
V_360 . V_361 ,
V_342 -> V_231 , false ,
V_362 , true , true ) ;
else
F_325 ( & V_342 -> V_323 ,
V_360 . V_361 ,
false ) ;
}
static void
F_332 ( struct V_11 * V_12 ,
struct V_321 * V_342 , bool V_359 )
{
F_325 ( & V_342 -> V_323 ,
V_360 . V_361 , V_359 ) ;
}
static void F_333 ( struct V_11 * V_12 ,
struct V_321 * V_197 , bool V_363 )
{
unsigned V_364 , V_365 , V_366 ;
T_11 V_367 ;
bool V_348 , V_368 , V_369 , V_370 , V_371 , V_372 , V_373 , V_374 , V_375 , V_376 , V_377 = 0 ;
V_376 = F_334 ( V_12 , V_378 ) ;
V_375 = F_334 ( V_12 , V_379 ) ;
for ( V_365 = 0 ; V_365 < F_59 ( V_197 -> V_380 ) ; ++ V_365 ) {
V_366 = V_365 << 1 ;
V_367 = 0 ;
V_371 = V_366 & V_293 ;
V_372 = V_366 & V_381 ;
V_373 = V_366 & V_382 ;
V_374 = ! ( V_366 & V_291 ) ;
for ( V_364 = 0 ; V_364 < 8 ; ++ V_364 ) {
V_368 = V_364 & V_251 ;
V_369 = V_364 & V_17 ;
V_370 = V_364 & V_18 ;
if ( ! V_363 ) {
V_368 |= ! V_197 -> V_347 ;
V_369 |= ! F_335 ( V_12 ) && ! V_372 ;
V_368 &= ! ( V_376 && V_370 && ! V_372 ) ;
V_377 = V_375 && V_370 && ! V_372 && ! V_373 ;
} else
V_370 = 1 ;
V_348 = ( V_373 && ! V_368 ) || ( V_372 && ! V_370 ) || ( V_371 && ! V_369 ) ||
( V_374 && V_377 ) ;
V_367 |= V_348 << V_364 ;
}
V_197 -> V_380 [ V_365 ] = V_367 ;
}
}
static void F_336 ( struct V_11 * V_12 , struct V_321 * V_197 )
{
T_11 V_367 ;
unsigned V_40 , V_219 = V_197 -> V_219 ;
const unsigned V_383 = 1 << 2 ;
if ( V_219 == V_232 )
-- V_219 ;
V_367 = 1 | ( 1 << V_383 ) ;
for ( V_40 = V_104 ; V_40 <= V_219 ; ++ V_40 ) {
if ( V_40 <= V_384
&& ( V_197 -> V_219 >= V_232 || F_323 ( V_12 ) ) )
V_367 |= 1 << ( V_383 | ( V_40 - 1 ) ) ;
}
V_197 -> V_351 = V_367 ;
}
static void F_337 ( struct V_11 * V_12 ,
struct V_321 * V_342 ,
int V_40 )
{
V_342 -> V_347 = F_21 ( V_12 ) ;
V_342 -> V_219 = V_40 ;
F_320 ( V_12 , V_342 ) ;
F_333 ( V_12 , V_342 , false ) ;
F_336 ( V_12 , V_342 ) ;
F_156 ( ! F_180 ( V_12 ) ) ;
V_342 -> V_343 = V_385 ;
V_342 -> V_344 = V_386 ;
V_342 -> V_198 = V_387 ;
V_342 -> V_345 = V_388 ;
V_342 -> V_346 = V_389 ;
V_342 -> V_231 = V_40 ;
V_342 -> V_230 = V_297 ;
V_342 -> V_218 = false ;
}
static void F_338 ( struct V_11 * V_12 ,
struct V_321 * V_342 )
{
F_337 ( V_12 , V_342 , V_206 ) ;
}
static void F_339 ( struct V_11 * V_12 ,
struct V_321 * V_342 )
{
V_342 -> V_347 = false ;
V_342 -> V_219 = V_220 ;
F_320 ( V_12 , V_342 ) ;
F_333 ( V_12 , V_342 , false ) ;
F_336 ( V_12 , V_342 ) ;
V_342 -> V_343 = V_390 ;
V_342 -> V_344 = V_391 ;
V_342 -> V_198 = V_392 ;
V_342 -> V_345 = V_393 ;
V_342 -> V_346 = V_394 ;
V_342 -> V_231 = V_232 ;
V_342 -> V_230 = V_297 ;
V_342 -> V_218 = false ;
}
static void F_340 ( struct V_11 * V_12 ,
struct V_321 * V_342 )
{
F_337 ( V_12 , V_342 , V_232 ) ;
}
static void F_341 ( struct V_11 * V_12 )
{
struct V_321 * V_342 = & V_12 -> V_34 . V_197 ;
V_342 -> V_217 . V_223 = 0 ;
V_342 -> V_217 . V_395 = F_342 ( V_12 ) ;
V_342 -> V_343 = F_311 ;
V_342 -> V_198 = F_169 ;
V_342 -> V_345 = F_170 ;
V_342 -> V_346 = F_171 ;
V_342 -> V_231 = V_117 -> V_396 () ;
V_342 -> V_230 = V_297 ;
V_342 -> V_218 = true ;
V_342 -> V_397 = V_117 -> V_398 ;
V_342 -> V_302 = V_302 ;
V_342 -> V_305 = V_399 ;
V_342 -> F_315 = V_400 ;
if ( ! F_343 ( V_12 ) ) {
V_342 -> V_347 = false ;
V_342 -> V_344 = F_288 ;
V_342 -> V_219 = 0 ;
} else if ( F_344 ( V_12 ) ) {
V_342 -> V_347 = F_21 ( V_12 ) ;
V_342 -> V_219 = V_206 ;
F_320 ( V_12 , V_342 ) ;
V_342 -> V_344 = V_386 ;
} else if ( F_180 ( V_12 ) ) {
V_342 -> V_347 = F_21 ( V_12 ) ;
V_342 -> V_219 = V_232 ;
F_320 ( V_12 , V_342 ) ;
V_342 -> V_344 = V_386 ;
} else {
V_342 -> V_347 = false ;
V_342 -> V_219 = V_220 ;
F_320 ( V_12 , V_342 ) ;
V_342 -> V_344 = V_391 ;
}
F_333 ( V_12 , V_342 , false ) ;
F_336 ( V_12 , V_342 ) ;
F_331 ( V_12 , V_342 ) ;
}
void F_345 ( struct V_11 * V_12 )
{
bool V_401 = F_334 ( V_12 , V_378 ) ;
bool V_377 = F_334 ( V_12 , V_379 ) ;
struct V_321 * V_342 = & V_12 -> V_34 . V_197 ;
F_156 ( F_251 ( V_342 -> V_230 ) ) ;
if ( ! F_343 ( V_12 ) )
F_312 ( V_12 , V_342 ) ;
else if ( F_344 ( V_12 ) )
F_338 ( V_12 , V_342 ) ;
else if ( F_180 ( V_12 ) )
F_340 ( V_12 , V_342 ) ;
else
F_339 ( V_12 , V_342 ) ;
V_342 -> V_217 . V_402 = F_21 ( V_12 ) ;
V_342 -> V_217 . V_196 = ! ! F_180 ( V_12 ) ;
V_342 -> V_217 . V_403 = F_335 ( V_12 ) ;
V_342 -> V_217 . V_404
= V_401 && ! F_335 ( V_12 ) ;
V_342 -> V_217 . V_405
= V_377 && ! F_335 ( V_12 ) ;
V_342 -> V_217 . V_395 = F_342 ( V_12 ) ;
F_328 ( V_12 , V_342 ) ;
}
void F_346 ( struct V_11 * V_12 , bool V_359 )
{
struct V_321 * V_342 = & V_12 -> V_34 . V_197 ;
F_156 ( F_251 ( V_342 -> V_230 ) ) ;
V_342 -> V_231 = V_117 -> V_396 () ;
V_342 -> V_347 = true ;
V_342 -> V_343 = V_406 ;
V_342 -> V_344 = V_407 ;
V_342 -> V_198 = V_408 ;
V_342 -> V_345 = V_409 ;
V_342 -> V_346 = V_410 ;
V_342 -> V_219 = V_342 -> V_231 ;
V_342 -> V_230 = V_297 ;
V_342 -> V_218 = false ;
F_333 ( V_12 , V_342 , true ) ;
F_327 ( V_12 , V_342 , V_359 ) ;
F_332 ( V_12 , V_342 , V_359 ) ;
}
static void F_347 ( struct V_11 * V_12 )
{
struct V_321 * V_342 = & V_12 -> V_34 . V_197 ;
F_345 ( V_12 ) ;
V_342 -> V_397 = V_117 -> V_397 ;
V_342 -> V_302 = V_302 ;
V_342 -> V_305 = V_399 ;
V_342 -> F_315 = V_400 ;
}
static void F_348 ( struct V_11 * V_12 )
{
struct V_321 * V_411 = & V_12 -> V_34 . V_313 ;
V_411 -> V_302 = V_302 ;
V_411 -> V_305 = V_399 ;
V_411 -> F_315 = V_400 ;
if ( ! F_343 ( V_12 ) ) {
V_411 -> V_347 = false ;
V_411 -> V_219 = 0 ;
V_411 -> V_344 = F_289 ;
} else if ( F_344 ( V_12 ) ) {
V_411 -> V_347 = F_21 ( V_12 ) ;
V_411 -> V_219 = V_206 ;
F_320 ( V_12 , V_411 ) ;
V_411 -> V_344 = V_412 ;
} else if ( F_180 ( V_12 ) ) {
V_411 -> V_347 = F_21 ( V_12 ) ;
V_411 -> V_219 = V_232 ;
F_320 ( V_12 , V_411 ) ;
V_411 -> V_344 = V_412 ;
} else {
V_411 -> V_347 = false ;
V_411 -> V_219 = V_220 ;
F_320 ( V_12 , V_411 ) ;
V_411 -> V_344 = V_413 ;
}
F_333 ( V_12 , V_411 , false ) ;
F_336 ( V_12 , V_411 ) ;
}
static void F_349 ( struct V_11 * V_12 )
{
if ( F_350 ( V_12 ) )
F_348 ( V_12 ) ;
else if ( V_252 )
F_341 ( V_12 ) ;
else
F_347 ( V_12 ) ;
}
void F_351 ( struct V_11 * V_12 )
{
F_352 ( V_12 ) ;
F_349 ( V_12 ) ;
}
int F_353 ( struct V_11 * V_12 )
{
int V_79 ;
V_79 = F_68 ( V_12 ) ;
if ( V_79 )
goto V_83;
V_79 = F_284 ( V_12 ) ;
F_287 ( V_12 ) ;
if ( V_79 )
goto V_83;
V_12 -> V_34 . V_197 . V_397 ( V_12 , V_12 -> V_34 . V_197 . V_230 ) ;
V_83:
return V_79 ;
}
void F_352 ( struct V_11 * V_12 )
{
F_277 ( V_12 ) ;
F_3 ( F_251 ( V_12 -> V_34 . V_197 . V_230 ) ) ;
}
static void F_354 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_10 ,
const void * V_414 )
{
if ( V_48 -> V_89 . V_40 != V_41 ) {
++ V_12 -> V_99 -> V_134 . V_415 ;
return;
}
++ V_12 -> V_99 -> V_134 . V_416 ;
V_12 -> V_34 . V_197 . V_346 ( V_12 , V_48 , V_10 , V_414 ) ;
}
static bool F_355 ( T_1 V_417 , T_1 V_414 )
{
if ( ! F_22 ( V_417 ) )
return false ;
if ( ! F_22 ( V_414 ) )
return true ;
if ( ( V_417 ^ V_414 ) & V_42 )
return true ;
V_417 ^= V_32 ;
V_414 ^= V_32 ;
return ( V_417 & ~ V_414 & V_418 ) != 0 ;
}
static void F_356 ( struct V_11 * V_12 , bool V_419 ,
bool V_420 , bool V_421 )
{
if ( V_419 )
return;
if ( V_420 )
F_109 ( V_12 -> V_99 ) ;
else if ( V_421 )
F_182 ( V_199 , V_12 ) ;
}
static T_1 F_357 ( struct V_11 * V_12 , T_8 * V_341 ,
const T_11 * V_414 , int * V_422 )
{
T_1 V_423 ;
int V_79 ;
if ( F_180 ( V_12 ) && * V_422 == 4 ) {
* V_341 &= ~ ( T_8 ) 7 ;
* V_422 = 8 ;
V_79 = F_358 ( V_12 , * V_341 , & V_423 , 8 ) ;
if ( V_79 )
V_423 = 0 ;
V_414 = ( const T_11 * ) & V_423 ;
}
switch ( * V_422 ) {
case 4 :
V_423 = * ( const T_4 * ) V_414 ;
break;
case 8 :
V_423 = * ( const T_1 * ) V_414 ;
break;
default:
V_423 = 0 ;
break;
}
return V_423 ;
}
static bool F_359 ( struct V_47 * V_48 )
{
if ( V_48 -> V_89 . V_40 == V_41 )
return false ;
return ++ V_48 -> V_211 >= 3 ;
}
static bool F_360 ( struct V_47 * V_48 , T_8 V_341 ,
int V_422 )
{
unsigned V_424 , V_425 , V_426 ;
F_230 ( L_29 ,
V_341 , V_422 , V_48 -> V_89 . V_223 ) ;
V_424 = F_361 ( V_341 ) ;
V_425 = V_48 -> V_89 . V_196 ? 8 : 4 ;
if ( ! ( V_424 & ( V_425 - 1 ) ) && V_422 == 1 )
return false ;
V_426 = ( V_424 ^ ( V_424 + V_422 - 1 ) ) & ~ ( V_425 - 1 ) ;
V_426 |= V_422 < 4 ;
return V_426 ;
}
static T_1 * F_362 ( struct V_47 * V_48 , T_8 V_341 , int * V_427 )
{
unsigned V_428 , V_215 ;
T_1 * V_10 ;
int V_40 ;
V_428 = F_361 ( V_341 ) ;
V_40 = V_48 -> V_89 . V_40 ;
* V_427 = 1 ;
if ( ! V_48 -> V_89 . V_196 ) {
V_428 <<= 1 ;
if ( V_40 == V_220 ) {
V_428 &= ~ 7 ;
V_428 <<= 1 ;
* V_427 = 2 ;
}
V_215 = V_428 >> V_19 ;
V_428 &= ~ V_20 ;
if ( V_215 != V_48 -> V_89 . V_215 )
return NULL ;
}
V_10 = & V_48 -> V_130 [ V_428 / sizeof( * V_10 ) ] ;
return V_10 ;
}
void F_363 ( struct V_11 * V_12 , T_8 V_341 ,
const T_11 * V_414 , int V_422 )
{
T_2 V_15 = V_341 >> V_19 ;
struct V_47 * V_48 ;
F_184 ( V_194 ) ;
T_1 V_429 , V_423 , * V_10 ;
int V_430 ;
bool V_420 , V_421 , V_419 ;
union V_214 V_4 = { } ;
V_4 . V_403 = 1 ;
V_4 . V_196 = 1 ;
V_4 . V_402 = 1 ;
V_4 . V_404 = 1 ;
V_4 . V_405 = 1 ;
V_4 . V_395 = 1 ;
if ( ! F_33 ( V_12 -> V_99 -> V_34 . V_107 ) )
return;
V_419 = V_420 = V_421 = false ;
F_230 ( L_30 , V_142 , V_341 , V_422 ) ;
V_423 = F_357 ( V_12 , & V_341 , V_414 , & V_422 ) ;
F_68 ( V_12 ) ;
F_227 ( & V_12 -> V_99 -> V_209 ) ;
++ V_12 -> V_99 -> V_134 . V_431 ;
F_186 ( V_12 , V_432 ) ;
F_190 (vcpu->kvm, sp, gfn) {
if ( F_360 ( V_48 , V_341 , V_422 ) ||
F_359 ( V_48 ) ) {
V_419 |= ! ! F_181 ( V_12 -> V_99 , V_48 ,
& V_194 ) ;
++ V_12 -> V_99 -> V_134 . V_433 ;
continue;
}
V_10 = F_362 ( V_48 , V_341 , & V_430 ) ;
if ( ! V_10 )
continue;
V_421 = true ;
while ( V_430 -- ) {
V_429 = * V_10 ;
F_214 ( V_12 -> V_99 , V_48 , V_10 ) ;
if ( V_423 &&
! ( ( V_48 -> V_89 . V_223 ^ V_12 -> V_34 . V_197 . V_217 . V_223 )
& V_4 . V_223 ) && F_101 ( V_12 ) )
F_354 ( V_12 , V_48 , V_10 , & V_423 ) ;
if ( F_355 ( V_429 , * V_10 ) )
V_420 = true ;
++ V_10 ;
}
}
F_356 ( V_12 , V_419 , V_420 , V_421 ) ;
F_185 ( V_12 -> V_99 , & V_194 ) ;
F_186 ( V_12 , V_434 ) ;
F_228 ( & V_12 -> V_99 -> V_209 ) ;
}
int F_364 ( struct V_11 * V_12 , T_7 V_182 )
{
T_8 V_341 ;
int V_79 ;
if ( V_12 -> V_34 . V_197 . V_218 )
return 0 ;
V_341 = F_365 ( V_12 , V_182 , NULL ) ;
V_79 = F_229 ( V_12 -> V_99 , V_341 >> V_19 ) ;
return V_79 ;
}
static void F_276 ( struct V_11 * V_12 )
{
F_184 ( V_194 ) ;
if ( F_18 ( F_366 ( V_12 -> V_99 ) >= V_435 ) )
return;
while ( F_366 ( V_12 -> V_99 ) < V_436 ) {
if ( ! F_224 ( V_12 -> V_99 , & V_194 ) )
break;
++ V_12 -> V_99 -> V_134 . V_437 ;
}
F_185 ( V_12 -> V_99 , & V_194 ) ;
}
static bool F_367 ( struct V_11 * V_12 , T_7 V_228 )
{
if ( V_12 -> V_34 . V_197 . V_218 || F_350 ( V_12 ) )
return F_294 ( V_12 , V_228 ) ;
return F_295 ( V_12 , V_228 ) ;
}
int F_368 ( struct V_11 * V_12 , T_7 V_438 , T_4 V_290 ,
void * V_439 , int V_440 )
{
int V_79 , V_441 = V_442 ;
enum V_443 V_444 ;
V_79 = V_12 -> V_34 . V_197 . V_343 ( V_12 , V_438 , V_290 , false ) ;
if ( V_79 < 0 )
goto V_83;
if ( ! V_79 ) {
V_79 = 1 ;
goto V_83;
}
if ( F_367 ( V_12 , V_438 ) )
V_441 = 0 ;
V_444 = F_369 ( V_12 , V_438 , V_441 , V_439 , V_440 ) ;
switch ( V_444 ) {
case V_445 :
return 1 ;
case V_446 :
++ V_12 -> V_134 . V_447 ;
case V_448 :
return 0 ;
default:
F_96 () ;
}
V_83:
return V_79 ;
}
void F_370 ( struct V_11 * V_12 , T_7 V_182 )
{
V_12 -> V_34 . V_197 . V_345 ( V_12 , V_182 ) ;
F_182 ( V_199 , V_12 ) ;
++ V_12 -> V_134 . V_345 ;
}
void F_371 ( void )
{
V_252 = true ;
}
void F_372 ( void )
{
V_252 = false ;
}
static void F_373 ( struct V_11 * V_12 )
{
F_67 ( ( unsigned long ) V_12 -> V_34 . V_197 . V_233 ) ;
if ( V_12 -> V_34 . V_197 . V_306 != NULL )
F_67 ( ( unsigned long ) V_12 -> V_34 . V_197 . V_306 ) ;
}
static int F_374 ( struct V_11 * V_12 )
{
struct V_78 * V_78 ;
int V_103 ;
V_78 = F_375 ( V_75 | V_449 ) ;
if ( ! V_78 )
return - V_76 ;
V_12 -> V_34 . V_197 . V_233 = F_376 ( V_78 ) ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 )
V_12 -> V_34 . V_197 . V_233 [ V_103 ] = V_297 ;
return 0 ;
}
int F_377 ( struct V_11 * V_12 )
{
V_12 -> V_34 . V_450 = & V_12 -> V_34 . V_197 ;
V_12 -> V_34 . V_197 . V_230 = V_297 ;
V_12 -> V_34 . V_197 . V_314 = V_314 ;
V_12 -> V_34 . V_313 . V_314 = V_451 ;
return F_374 ( V_12 ) ;
}
void F_378 ( struct V_11 * V_12 )
{
F_156 ( F_251 ( V_12 -> V_34 . V_197 . V_230 ) ) ;
F_349 ( V_12 ) ;
}
static bool
F_379 ( struct V_99 * V_99 , struct V_94 * V_157 ,
T_12 V_127 , int V_153 , int V_154 ,
T_2 V_150 , T_2 V_152 , bool V_452 )
{
struct V_148 V_149 ;
bool V_138 = false ;
F_139 (memslot, start_level, end_level, start_gfn,
end_gfn, &iterator) {
if ( V_149 . V_128 )
V_138 |= V_127 ( V_99 , V_149 . V_128 ) ;
if ( F_380 () || F_381 ( & V_99 -> V_209 ) ) {
if ( V_138 && V_452 ) {
F_109 ( V_99 ) ;
V_138 = false ;
}
F_196 ( & V_99 -> V_209 ) ;
}
}
if ( V_138 && V_452 ) {
F_109 ( V_99 ) ;
V_138 = false ;
}
return V_138 ;
}
static bool
F_382 ( struct V_99 * V_99 , struct V_94 * V_157 ,
T_12 V_127 , int V_153 , int V_154 ,
bool V_452 )
{
return F_379 ( V_99 , V_157 , V_127 , V_153 ,
V_154 , V_157 -> V_97 ,
V_157 -> V_97 + V_157 -> V_164 - 1 ,
V_452 ) ;
}
static bool
F_383 ( struct V_99 * V_99 , struct V_94 * V_157 ,
T_12 V_127 , bool V_452 )
{
return F_382 ( V_99 , V_157 , V_127 , V_41 ,
V_105 , V_452 ) ;
}
static bool
F_384 ( struct V_99 * V_99 , struct V_94 * V_157 ,
T_12 V_127 , bool V_452 )
{
return F_382 ( V_99 , V_157 , V_127 , V_41 + 1 ,
V_105 , V_452 ) ;
}
static bool
F_385 ( struct V_99 * V_99 , struct V_94 * V_157 ,
T_12 V_127 , bool V_452 )
{
return F_382 ( V_99 , V_157 , V_127 , V_41 ,
V_41 , V_452 ) ;
}
void F_386 ( struct V_99 * V_99 , T_2 V_161 , T_2 V_162 )
{
struct V_100 * V_101 ;
struct V_94 * V_157 ;
int V_103 ;
F_227 ( & V_99 -> V_209 ) ;
for ( V_103 = 0 ; V_103 < V_158 ; V_103 ++ ) {
V_101 = F_135 ( V_99 , V_103 ) ;
F_136 (memslot, slots) {
T_2 V_155 , V_156 ;
V_155 = F_137 ( V_161 , V_157 -> V_97 ) ;
V_156 = V_71 ( V_162 , V_157 -> V_97 + V_157 -> V_164 ) ;
if ( V_155 >= V_156 )
continue;
F_379 ( V_99 , V_157 , F_122 ,
V_41 , V_105 ,
V_155 , V_156 - 1 , true ) ;
}
}
F_228 ( & V_99 -> V_209 ) ;
}
static bool F_387 ( struct V_99 * V_99 , unsigned long * V_129 )
{
return F_111 ( V_99 , V_129 , false ) ;
}
void F_388 ( struct V_99 * V_99 ,
struct V_94 * V_157 )
{
bool V_138 ;
F_227 ( & V_99 -> V_209 ) ;
V_138 = F_383 ( V_99 , V_157 , F_387 ,
false ) ;
F_228 ( & V_99 -> V_209 ) ;
F_389 ( & V_99 -> V_453 ) ;
if ( V_138 )
F_109 ( V_99 ) ;
}
static bool F_390 ( struct V_99 * V_99 ,
unsigned long * V_129 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
int V_454 = 0 ;
T_3 V_21 ;
struct V_47 * V_48 ;
V_147:
F_112 (rmapp, &iter, sptep) {
V_48 = F_35 ( F_36 ( V_14 ) ) ;
V_21 = F_26 ( * V_14 ) ;
if ( V_48 -> V_89 . V_90 &&
! F_48 ( V_21 ) &&
F_260 ( F_50 ( V_21 ) ) ) {
F_106 ( V_99 , V_14 ) ;
V_454 = 1 ;
goto V_147;
}
}
return V_454 ;
}
void F_391 ( struct V_99 * V_99 ,
const struct V_94 * V_157 )
{
F_227 ( & V_99 -> V_209 ) ;
F_385 ( V_99 , (struct V_94 * ) V_157 ,
F_390 , true ) ;
F_228 ( & V_99 -> V_209 ) ;
}
void F_392 ( struct V_99 * V_99 ,
struct V_94 * V_157 )
{
bool V_138 ;
F_227 ( & V_99 -> V_209 ) ;
V_138 = F_385 ( V_99 , V_157 , F_114 , false ) ;
F_228 ( & V_99 -> V_209 ) ;
F_389 ( & V_99 -> V_453 ) ;
if ( V_138 )
F_109 ( V_99 ) ;
}
void F_393 ( struct V_99 * V_99 ,
struct V_94 * V_157 )
{
bool V_138 ;
F_227 ( & V_99 -> V_209 ) ;
V_138 = F_384 ( V_99 , V_157 , F_387 ,
false ) ;
F_228 ( & V_99 -> V_209 ) ;
F_389 ( & V_99 -> V_453 ) ;
if ( V_138 )
F_109 ( V_99 ) ;
}
void F_394 ( struct V_99 * V_99 ,
struct V_94 * V_157 )
{
bool V_138 ;
F_227 ( & V_99 -> V_209 ) ;
V_138 = F_383 ( V_99 , V_157 , F_116 , false ) ;
F_228 ( & V_99 -> V_209 ) ;
F_389 ( & V_99 -> V_453 ) ;
if ( V_138 )
F_109 ( V_99 ) ;
}
static void F_395 ( struct V_99 * V_99 )
{
struct V_47 * V_48 , * V_455 ;
int V_456 = 0 ;
V_147:
F_396 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_63 ;
if ( ! F_200 ( V_99 , V_48 ) )
break;
if ( V_48 -> V_89 . V_240 )
continue;
if ( V_456 >= V_457 &&
F_196 ( & V_99 -> V_209 ) ) {
V_456 = 0 ;
goto V_147;
}
V_63 = F_181 ( V_99 , V_48 ,
& V_99 -> V_34 . V_458 ) ;
V_456 += V_63 ;
if ( V_63 )
goto V_147;
}
F_185 ( V_99 , & V_99 -> V_34 . V_458 ) ;
}
void F_397 ( struct V_99 * V_99 )
{
F_227 ( & V_99 -> V_209 ) ;
F_398 ( V_99 ) ;
V_99 -> V_34 . V_212 ++ ;
F_221 ( V_99 ) ;
F_395 ( V_99 ) ;
F_228 ( & V_99 -> V_209 ) ;
}
static bool F_399 ( struct V_99 * V_99 )
{
return F_14 ( ! F_400 ( & V_99 -> V_34 . V_458 ) ) ;
}
void F_401 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
if ( F_14 ( ( V_101 -> V_13 & V_5 ) == 0 ) ) {
F_402 ( V_459 L_31 ) ;
F_397 ( V_99 ) ;
}
}
static unsigned long
F_403 ( struct V_460 * V_461 , struct V_462 * V_463 )
{
struct V_99 * V_99 ;
int V_464 = V_463 -> V_464 ;
unsigned long V_465 = 0 ;
F_227 ( & V_466 ) ;
F_404 (kvm, &vm_list, vm_list) {
int V_96 ;
F_184 ( V_194 ) ;
if ( ! V_464 -- )
break;
if ( ! V_99 -> V_34 . V_171 &&
! F_399 ( V_99 ) )
continue;
V_96 = F_405 ( & V_99 -> V_467 ) ;
F_227 ( & V_99 -> V_209 ) ;
if ( F_399 ( V_99 ) ) {
F_185 ( V_99 ,
& V_99 -> V_34 . V_458 ) ;
goto V_468;
}
if ( F_224 ( V_99 , & V_194 ) )
V_465 ++ ;
F_185 ( V_99 , & V_194 ) ;
V_468:
F_228 ( & V_99 -> V_209 ) ;
F_406 ( & V_99 -> V_467 , V_96 ) ;
F_407 ( & V_99 -> V_469 , & V_469 ) ;
break;
}
F_228 ( & V_466 ) ;
return V_465 ;
}
static unsigned long
F_408 ( struct V_460 * V_461 , struct V_462 * V_463 )
{
return F_409 ( & V_172 ) ;
}
static void F_410 ( void )
{
if ( V_81 )
F_411 ( V_81 ) ;
if ( V_85 )
F_411 ( V_85 ) ;
}
int F_412 ( void )
{
V_81 = F_413 ( L_32 ,
sizeof( struct V_87 ) ,
0 , 0 , NULL ) ;
if ( ! V_81 )
goto V_470;
V_85 = F_413 ( L_33 ,
sizeof( struct V_47 ) ,
0 , 0 , NULL ) ;
if ( ! V_85 )
goto V_470;
if ( F_414 ( & V_172 , 0 , V_75 ) )
goto V_470;
F_415 ( & V_471 ) ;
return 0 ;
V_470:
F_410 () ;
return - V_76 ;
}
unsigned int F_416 ( struct V_99 * V_99 )
{
unsigned int V_472 ;
unsigned int V_473 = 0 ;
struct V_100 * V_101 ;
struct V_94 * V_157 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_158 ; V_103 ++ ) {
V_101 = F_135 ( V_99 , V_103 ) ;
F_136 (memslot, slots)
V_473 += V_157 -> V_164 ;
}
V_472 = V_473 * V_474 / 1000 ;
V_472 = F_137 ( V_472 ,
( unsigned int ) V_475 ) ;
return V_472 ;
}
void F_417 ( struct V_11 * V_12 )
{
F_352 ( V_12 ) ;
F_373 ( V_12 ) ;
F_69 ( V_12 ) ;
}
void F_418 ( void )
{
F_410 () ;
F_419 ( & V_172 ) ;
F_420 ( & V_471 ) ;
F_187 () ;
}
