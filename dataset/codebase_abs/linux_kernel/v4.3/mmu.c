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
static int F_82 ( struct V_11 * V_12 ,
T_2 V_15 ,
int V_40 )
{
struct V_94 * V_95 ;
struct V_93 * V_102 ;
V_95 = F_83 ( V_12 , V_15 ) ;
if ( V_95 ) {
V_102 = F_76 ( V_15 , V_95 , V_40 ) ;
return V_102 -> V_106 ;
}
return 1 ;
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
static struct V_94 *
F_87 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_109 )
{
struct V_94 * V_95 ;
V_95 = F_83 ( V_12 , V_15 ) ;
if ( ! V_95 || V_95 -> V_110 & V_111 ||
( V_109 && V_95 -> V_112 ) )
V_95 = NULL ;
return V_95 ;
}
static bool F_88 ( struct V_11 * V_12 , T_2 V_113 )
{
return ! F_87 ( V_12 , V_113 , true ) ;
}
static int F_89 ( struct V_11 * V_12 , T_2 V_113 )
{
int V_114 , V_40 , V_115 ;
V_114 = F_84 ( V_12 -> V_99 , V_113 ) ;
if ( V_114 == V_41 )
return V_114 ;
V_115 = V_71 ( V_116 -> V_117 () , V_114 ) ;
for ( V_40 = V_104 ; V_40 <= V_115 ; ++ V_40 )
if ( F_82 ( V_12 , V_113 , V_40 ) )
break;
return V_40 - 1 ;
}
static int F_90 ( struct V_11 * V_12 , T_1 * V_10 ,
unsigned long * V_118 )
{
struct V_87 * V_119 ;
int V_103 , V_56 = 0 ;
if ( ! * V_118 ) {
F_91 ( L_1 , V_10 , * V_10 ) ;
* V_118 = ( unsigned long ) V_10 ;
} else if ( ! ( * V_118 & 1 ) ) {
F_91 ( L_2 , V_10 , * V_10 ) ;
V_119 = F_72 ( V_12 ) ;
V_119 -> V_120 [ 0 ] = ( T_1 * ) * V_118 ;
V_119 -> V_120 [ 1 ] = V_10 ;
* V_118 = ( unsigned long ) V_119 | 1 ;
++ V_56 ;
} else {
F_91 ( L_3 , V_10 , * V_10 ) ;
V_119 = (struct V_87 * ) ( * V_118 & ~ 1ul ) ;
while ( V_119 -> V_120 [ V_121 - 1 ] && V_119 -> V_122 ) {
V_119 = V_119 -> V_122 ;
V_56 += V_121 ;
}
if ( V_119 -> V_120 [ V_121 - 1 ] ) {
V_119 -> V_122 = F_72 ( V_12 ) ;
V_119 = V_119 -> V_122 ;
}
for ( V_103 = 0 ; V_119 -> V_120 [ V_103 ] ; ++ V_103 )
++ V_56 ;
V_119 -> V_120 [ V_103 ] = V_10 ;
}
return V_56 ;
}
static void
F_92 ( unsigned long * V_118 , struct V_87 * V_119 ,
int V_103 , struct V_87 * V_123 )
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
static void F_93 ( T_1 * V_10 , unsigned long * V_118 )
{
struct V_87 * V_119 ;
struct V_87 * V_123 ;
int V_103 ;
if ( ! * V_118 ) {
F_94 ( V_125 L_4 , V_10 ) ;
F_95 () ;
} else if ( ! ( * V_118 & 1 ) ) {
F_91 ( L_5 , V_10 ) ;
if ( ( T_1 * ) * V_118 != V_10 ) {
F_94 ( V_125 L_6 , V_10 ) ;
F_95 () ;
}
* V_118 = 0 ;
} else {
F_91 ( L_7 , V_10 ) ;
V_119 = (struct V_87 * ) ( * V_118 & ~ 1ul ) ;
V_123 = NULL ;
while ( V_119 ) {
for ( V_103 = 0 ; V_103 < V_121 && V_119 -> V_120 [ V_103 ] ; ++ V_103 )
if ( V_119 -> V_120 [ V_103 ] == V_10 ) {
F_92 ( V_118 ,
V_119 , V_103 ,
V_123 ) ;
return;
}
V_123 = V_119 ;
V_119 = V_119 -> V_122 ;
}
F_96 ( L_8 , V_10 ) ;
F_95 () ;
}
}
static void F_97 ( unsigned long * V_118 , T_5 V_126 )
{
struct V_87 * V_119 ;
int V_103 ;
if ( ! * V_118 )
return;
if ( ! ( * V_118 & 1 ) )
return V_126 ( ( T_1 * ) * V_118 ) ;
V_119 = (struct V_87 * ) ( * V_118 & ~ 1ul ) ;
while ( V_119 ) {
for ( V_103 = 0 ; V_103 < V_121 && V_119 -> V_120 [ V_103 ] ; ++ V_103 )
V_126 ( V_119 -> V_120 [ V_103 ] ) ;
V_119 = V_119 -> V_122 ;
}
}
static unsigned long * F_98 ( T_2 V_15 , int V_40 ,
struct V_94 * V_95 )
{
unsigned long V_96 ;
V_96 = F_77 ( V_15 , V_95 -> V_97 , V_40 ) ;
return & V_95 -> V_34 . V_127 [ V_40 - V_41 ] [ V_96 ] ;
}
static unsigned long * F_99 ( struct V_99 * V_99 , T_2 V_15 , struct V_47 * V_48 )
{
struct V_100 * V_101 ;
struct V_94 * V_95 ;
V_101 = F_79 ( V_99 , V_48 -> V_89 ) ;
V_95 = F_80 ( V_101 , V_15 ) ;
return F_98 ( V_15 , V_48 -> V_89 . V_40 , V_95 ) ;
}
static bool F_100 ( struct V_11 * V_12 )
{
struct V_67 * V_68 ;
V_68 = & V_12 -> V_34 . V_80 ;
return F_61 ( V_68 ) ;
}
static int F_101 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
struct V_47 * V_48 ;
unsigned long * V_128 ;
V_48 = F_35 ( F_36 ( V_10 ) ) ;
F_75 ( V_48 , V_10 - V_48 -> V_129 , V_15 ) ;
V_128 = F_99 ( V_12 -> V_99 , V_15 , V_48 ) ;
return F_90 ( V_12 , V_10 , V_128 ) ;
}
static void F_102 ( struct V_99 * V_99 , T_1 * V_10 )
{
struct V_47 * V_48 ;
T_2 V_15 ;
unsigned long * V_128 ;
V_48 = F_35 ( F_36 ( V_10 ) ) ;
V_15 = F_74 ( V_48 , V_10 - V_48 -> V_129 ) ;
V_128 = F_99 ( V_99 , V_15 , V_48 ) ;
F_93 ( V_10 , V_128 ) ;
}
static T_1 * F_103 ( unsigned long V_127 , struct V_130 * V_131 )
{
if ( ! V_127 )
return NULL ;
if ( ! ( V_127 & 1 ) ) {
V_131 -> V_119 = NULL ;
return ( T_1 * ) V_127 ;
}
V_131 -> V_119 = (struct V_87 * ) ( V_127 & ~ 1ul ) ;
V_131 -> V_132 = 0 ;
return V_131 -> V_119 -> V_120 [ V_131 -> V_132 ] ;
}
static T_1 * F_104 ( struct V_130 * V_131 )
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
static void F_105 ( struct V_99 * V_99 , T_1 * V_14 )
{
if ( F_47 ( V_14 ) )
F_102 ( V_99 , V_14 ) ;
}
static bool F_106 ( struct V_99 * V_99 , T_1 * V_14 )
{
if ( F_23 ( * V_14 ) ) {
F_3 ( F_35 ( F_36 ( V_14 ) ) -> V_89 . V_40 ==
V_41 ) ;
F_105 ( V_99 , V_14 ) ;
-- V_99 -> V_133 . V_134 ;
return true ;
}
return false ;
}
static void F_107 ( struct V_11 * V_12 , T_1 * V_14 )
{
if ( F_106 ( V_12 -> V_99 , V_14 ) )
F_108 ( V_12 -> V_99 ) ;
}
static bool F_109 ( struct V_99 * V_99 , T_1 * V_14 , bool V_135 )
{
T_1 V_10 = * V_14 ;
if ( ! F_41 ( V_10 ) &&
! ( V_135 && F_39 ( V_10 ) ) )
return false ;
F_91 ( L_9 , V_14 , * V_14 ) ;
if ( V_135 )
V_10 &= ~ V_59 ;
V_10 = V_10 & ~ V_136 ;
return F_44 ( V_14 , V_10 ) ;
}
static bool F_110 ( struct V_99 * V_99 , unsigned long * V_128 ,
bool V_135 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
bool V_137 = false ;
F_111 (rmapp, &iter, sptep)
V_137 |= F_109 ( V_99 , V_14 , V_135 ) ;
return V_137 ;
}
static bool F_112 ( struct V_99 * V_99 , T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_91 ( L_10 , V_14 , * V_14 ) ;
V_10 &= ~ V_31 ;
return F_44 ( V_14 , V_10 ) ;
}
static bool F_113 ( struct V_99 * V_99 , unsigned long * V_128 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
bool V_137 = false ;
F_111 (rmapp, &iter, sptep)
V_137 |= F_112 ( V_99 , V_14 ) ;
return V_137 ;
}
static bool F_114 ( struct V_99 * V_99 , T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_91 ( L_11 , V_14 , * V_14 ) ;
V_10 |= V_31 ;
return F_44 ( V_14 , V_10 ) ;
}
static bool F_115 ( struct V_99 * V_99 , unsigned long * V_128 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
bool V_137 = false ;
F_111 (rmapp, &iter, sptep)
V_137 |= F_114 ( V_99 , V_14 ) ;
return V_137 ;
}
static void F_116 ( struct V_99 * V_99 ,
struct V_94 * V_95 ,
T_2 V_138 , unsigned long V_4 )
{
unsigned long * V_128 ;
while ( V_4 ) {
V_128 = F_98 ( V_95 -> V_97 + V_138 + F_117 ( V_4 ) ,
V_41 , V_95 ) ;
F_110 ( V_99 , V_128 , false ) ;
V_4 &= V_4 - 1 ;
}
}
void F_118 ( struct V_99 * V_99 ,
struct V_94 * V_95 ,
T_2 V_138 , unsigned long V_4 )
{
unsigned long * V_128 ;
while ( V_4 ) {
V_128 = F_98 ( V_95 -> V_97 + V_138 + F_117 ( V_4 ) ,
V_41 , V_95 ) ;
F_113 ( V_99 , V_128 ) ;
V_4 &= V_4 - 1 ;
}
}
void F_119 ( struct V_99 * V_99 ,
struct V_94 * V_95 ,
T_2 V_138 , unsigned long V_4 )
{
if ( V_116 -> V_139 )
V_116 -> V_139 ( V_99 , V_95 , V_138 ,
V_4 ) ;
else
F_116 ( V_99 , V_95 , V_138 , V_4 ) ;
}
static bool F_120 ( struct V_11 * V_12 , T_1 V_15 )
{
struct V_94 * V_95 ;
unsigned long * V_128 ;
int V_103 ;
bool V_140 = false ;
V_95 = F_83 ( V_12 , V_15 ) ;
for ( V_103 = V_41 ; V_103 <= V_105 ; ++ V_103 ) {
V_128 = F_98 ( V_15 , V_103 , V_95 ) ;
V_140 |= F_110 ( V_12 -> V_99 , V_128 , true ) ;
}
return V_140 ;
}
static bool F_121 ( struct V_99 * V_99 , unsigned long * V_128 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
bool V_137 = false ;
while ( ( V_14 = F_103 ( * V_128 , & V_131 ) ) ) {
F_71 ( ! ( * V_14 & V_38 ) ) ;
F_91 ( L_12 , V_141 , V_14 , * V_14 ) ;
F_105 ( V_99 , V_14 ) ;
V_137 = true ;
}
return V_137 ;
}
static int F_122 ( struct V_99 * V_99 , unsigned long * V_128 ,
struct V_94 * V_95 , T_2 V_15 , int V_40 ,
unsigned long V_142 )
{
return F_121 ( V_99 , V_128 ) ;
}
static int F_123 ( struct V_99 * V_99 , unsigned long * V_128 ,
struct V_94 * V_95 , T_2 V_15 , int V_40 ,
unsigned long V_142 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
int V_143 = 0 ;
T_1 V_61 ;
T_6 * V_144 = ( T_6 * ) V_142 ;
T_3 V_145 ;
F_3 ( F_124 ( * V_144 ) ) ;
V_145 = F_125 ( * V_144 ) ;
V_146:
F_111 (rmapp, &iter, sptep) {
F_91 ( L_13 ,
V_14 , * V_14 , V_15 , V_40 ) ;
V_143 = 1 ;
if ( F_126 ( * V_144 ) ) {
F_105 ( V_99 , V_14 ) ;
goto V_146;
} else {
V_61 = * V_14 & ~ V_42 ;
V_61 |= ( T_1 ) V_145 << V_19 ;
V_61 &= ~ V_136 ;
V_61 &= ~ V_58 ;
V_61 &= ~ V_30 ;
F_47 ( V_14 ) ;
F_9 ( V_14 , V_61 ) ;
}
}
if ( V_143 )
F_108 ( V_99 ) ;
return 0 ;
}
static void
F_127 ( struct V_147 * V_148 , int V_40 )
{
V_148 -> V_40 = V_40 ;
V_148 -> V_15 = V_148 -> V_149 ;
V_148 -> V_127 = F_98 ( V_148 -> V_15 , V_40 , V_148 -> V_95 ) ;
V_148 -> V_150 = F_98 ( V_148 -> V_151 , V_40 ,
V_148 -> V_95 ) ;
}
static void
F_128 ( struct V_147 * V_148 ,
struct V_94 * V_95 , int V_152 ,
int V_153 , T_2 V_149 , T_2 V_151 )
{
V_148 -> V_95 = V_95 ;
V_148 -> V_152 = V_152 ;
V_148 -> V_153 = V_153 ;
V_148 -> V_149 = V_149 ;
V_148 -> V_151 = V_151 ;
F_127 ( V_148 , V_148 -> V_152 ) ;
}
static bool F_129 ( struct V_147 * V_148 )
{
return ! ! V_148 -> V_127 ;
}
static void F_130 ( struct V_147 * V_148 )
{
if ( ++ V_148 -> V_127 <= V_148 -> V_150 ) {
V_148 -> V_15 += ( 1UL << F_131 ( V_148 -> V_40 ) ) ;
return;
}
if ( ++ V_148 -> V_40 > V_148 -> V_153 ) {
V_148 -> V_127 = NULL ;
return;
}
F_127 ( V_148 , V_148 -> V_40 ) ;
}
static int F_132 ( struct V_99 * V_99 ,
unsigned long V_154 ,
unsigned long V_155 ,
unsigned long V_142 ,
int (* F_133)( struct V_99 * V_99 ,
unsigned long * V_128 ,
struct V_94 * V_95 ,
T_2 V_15 ,
int V_40 ,
unsigned long V_142 ) )
{
struct V_100 * V_101 ;
struct V_94 * V_156 ;
struct V_147 V_148 ;
int V_63 = 0 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_157 ; V_103 ++ ) {
V_101 = F_134 ( V_99 , V_103 ) ;
F_135 (memslot, slots) {
unsigned long V_158 , V_159 ;
T_2 V_160 , V_161 ;
V_158 = F_136 ( V_154 , V_156 -> V_162 ) ;
V_159 = V_71 ( V_155 , V_156 -> V_162 +
( V_156 -> V_163 << V_19 ) ) ;
if ( V_158 >= V_159 )
continue;
V_160 = F_137 ( V_158 , V_156 ) ;
V_161 = F_137 ( V_159 + V_164 - 1 , V_156 ) ;
F_138 (memslot, PT_PAGE_TABLE_LEVEL,
PT_MAX_HUGEPAGE_LEVEL,
gfn_start, gfn_end - 1 ,
&iterator)
V_63 |= F_133 ( V_99 , V_148 . V_127 , V_156 ,
V_148 . V_15 , V_148 . V_40 , V_142 ) ;
}
}
return V_63 ;
}
static int F_139 ( struct V_99 * V_99 , unsigned long V_165 ,
unsigned long V_142 ,
int (* F_133)( struct V_99 * V_99 , unsigned long * V_128 ,
struct V_94 * V_95 ,
T_2 V_15 , int V_40 ,
unsigned long V_142 ) )
{
return F_132 ( V_99 , V_165 , V_165 + 1 , V_142 , F_133 ) ;
}
int F_140 ( struct V_99 * V_99 , unsigned long V_165 )
{
return F_139 ( V_99 , V_165 , 0 , F_122 ) ;
}
int F_141 ( struct V_99 * V_99 , unsigned long V_154 , unsigned long V_155 )
{
return F_132 ( V_99 , V_154 , V_155 , 0 , F_122 ) ;
}
void F_142 ( struct V_99 * V_99 , unsigned long V_165 , T_6 V_37 )
{
F_139 ( V_99 , V_165 , ( unsigned long ) & V_37 , F_123 ) ;
}
static int F_143 ( struct V_99 * V_99 , unsigned long * V_128 ,
struct V_94 * V_95 , T_2 V_15 , int V_40 ,
unsigned long V_142 )
{
T_1 * V_14 ;
struct V_130 V_166 ( V_131 ) ;
int V_167 = 0 ;
F_71 ( ! V_30 ) ;
F_111 (rmapp, &iter, sptep)
if ( * V_14 & V_30 ) {
V_167 = 1 ;
F_144 ( ( F_145 ( V_30 ) - 1 ) ,
( unsigned long * ) V_14 ) ;
}
F_146 ( V_15 , V_40 , V_95 , V_167 ) ;
return V_167 ;
}
static int F_147 ( struct V_99 * V_99 , unsigned long * V_128 ,
struct V_94 * V_95 , T_2 V_15 ,
int V_40 , unsigned long V_142 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
int V_167 = 0 ;
if ( ! V_30 )
goto V_83;
F_111 (rmapp, &iter, sptep)
if ( * V_14 & V_30 ) {
V_167 = 1 ;
break;
}
V_83:
return V_167 ;
}
static void F_148 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
unsigned long * V_128 ;
struct V_47 * V_48 ;
V_48 = F_35 ( F_36 ( V_10 ) ) ;
V_128 = F_99 ( V_12 -> V_99 , V_15 , V_48 ) ;
F_122 ( V_12 -> V_99 , V_128 , NULL , V_15 , V_48 -> V_89 . V_40 , 0 ) ;
F_108 ( V_12 -> V_99 ) ;
}
int F_149 ( struct V_99 * V_99 , unsigned long V_154 , unsigned long V_155 )
{
if ( ! V_30 ) {
V_99 -> V_168 ++ ;
return F_132 ( V_99 , V_154 , V_155 , 0 ,
F_122 ) ;
}
return F_132 ( V_99 , V_154 , V_155 , 0 , F_143 ) ;
}
int F_150 ( struct V_99 * V_99 , unsigned long V_165 )
{
return F_139 ( V_99 , V_165 , 0 , F_147 ) ;
}
static int F_151 ( T_1 * V_129 )
{
T_1 * V_132 ;
T_1 * V_155 ;
for ( V_132 = V_129 , V_155 = V_132 + V_164 / sizeof( T_1 ) ; V_132 != V_155 ; V_132 ++ )
if ( F_22 ( * V_132 ) ) {
F_94 ( V_125 L_14 , V_141 ,
V_132 , * V_132 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_152 ( struct V_99 * V_99 , int V_169 )
{
V_99 -> V_34 . V_170 += V_169 ;
F_153 ( & V_171 , V_169 ) ;
}
static void F_154 ( struct V_47 * V_48 )
{
F_155 ( ! F_151 ( V_48 -> V_129 ) ) ;
F_156 ( & V_48 -> V_172 ) ;
F_157 ( & V_48 -> V_173 ) ;
F_67 ( ( unsigned long ) V_48 -> V_129 ) ;
if ( ! V_48 -> V_89 . V_90 )
F_67 ( ( unsigned long ) V_48 -> V_91 ) ;
F_63 ( V_85 , V_48 ) ;
}
static unsigned F_158 ( T_2 V_15 )
{
return V_15 & ( ( 1 << V_174 ) - 1 ) ;
}
static void F_159 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_175 )
{
if ( ! V_175 )
return;
F_90 ( V_12 , V_175 , & V_48 -> V_176 ) ;
}
static void F_160 ( struct V_47 * V_48 ,
T_1 * V_175 )
{
F_93 ( V_175 , & V_48 -> V_176 ) ;
}
static void F_161 ( struct V_47 * V_48 ,
T_1 * V_175 )
{
F_160 ( V_48 , V_175 ) ;
F_51 ( V_175 ) ;
}
static struct V_47 * F_162 ( struct V_11 * V_12 ,
T_1 * V_175 , int V_90 )
{
struct V_47 * V_48 ;
V_48 = F_70 ( & V_12 -> V_34 . V_85 ) ;
V_48 -> V_129 = F_70 ( & V_12 -> V_34 . V_84 ) ;
if ( ! V_90 )
V_48 -> V_91 = F_70 ( & V_12 -> V_34 . V_84 ) ;
F_163 ( F_164 ( V_48 -> V_129 ) , ( unsigned long ) V_48 ) ;
F_165 ( & V_48 -> V_173 , & V_12 -> V_99 -> V_34 . V_177 ) ;
V_48 -> V_176 = 0 ;
F_159 ( V_12 , V_48 , V_175 ) ;
F_152 ( V_12 -> V_99 , + 1 ) ;
return V_48 ;
}
static void F_166 ( struct V_47 * V_48 )
{
F_97 ( & V_48 -> V_176 , V_178 ) ;
}
static void V_178 ( T_1 * V_10 )
{
struct V_47 * V_48 ;
unsigned int V_88 ;
V_48 = F_35 ( F_36 ( V_10 ) ) ;
V_88 = V_10 - V_48 -> V_129 ;
if ( F_167 ( V_88 , V_48 -> V_179 ) )
return;
if ( V_48 -> V_180 ++ )
return;
F_166 ( V_48 ) ;
}
static int F_168 ( struct V_11 * V_12 ,
struct V_47 * V_48 )
{
return 1 ;
}
static void F_169 ( struct V_11 * V_12 , T_7 V_181 )
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
for ( V_103 = 0 ; V_103 < V_183 -> V_169 ; V_103 ++ )
if ( V_183 -> V_78 [ V_103 ] . V_48 == V_48 )
return 0 ;
V_183 -> V_78 [ V_183 -> V_169 ] . V_48 = V_48 ;
V_183 -> V_78 [ V_183 -> V_169 ] . V_96 = V_96 ;
V_183 -> V_169 ++ ;
return ( V_183 -> V_169 == V_185 ) ;
}
static int F_172 ( struct V_47 * V_48 ,
struct V_182 * V_183 )
{
int V_103 , V_63 , V_186 = 0 ;
F_173 (i, sp->unsync_child_bitmap, 512 ) {
struct V_47 * V_187 ;
T_1 V_188 = V_48 -> V_129 [ V_103 ] ;
if ( ! F_22 ( V_188 ) || F_23 ( V_188 ) )
goto V_189;
V_187 = F_35 ( V_188 & V_42 ) ;
if ( V_187 -> V_180 ) {
if ( F_171 ( V_183 , V_187 , V_103 ) )
return - V_190 ;
V_63 = F_172 ( V_187 , V_183 ) ;
if ( ! V_63 )
goto V_189;
else if ( V_63 > 0 )
V_186 += V_63 ;
else
return V_63 ;
} else if ( V_187 -> V_184 ) {
V_186 ++ ;
if ( F_171 ( V_183 , V_187 , V_103 ) )
return - V_190 ;
} else
goto V_189;
continue;
V_189:
F_174 ( V_103 , V_48 -> V_179 ) ;
V_48 -> V_180 -- ;
F_3 ( ( int ) V_48 -> V_180 < 0 ) ;
}
return V_186 ;
}
static int F_175 ( struct V_47 * V_48 ,
struct V_182 * V_183 )
{
if ( ! V_48 -> V_180 )
return 0 ;
F_171 ( V_183 , V_48 , 0 ) ;
return F_172 ( V_48 , V_183 ) ;
}
static void F_176 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
F_3 ( ! V_48 -> V_184 ) ;
F_177 ( V_48 ) ;
V_48 -> V_184 = 0 ;
-- V_99 -> V_133 . V_191 ;
}
static int F_178 ( struct V_11 * V_12 , struct V_47 * V_48 ,
struct V_192 * V_193 , bool V_194 )
{
if ( V_48 -> V_89 . V_195 != ! ! F_179 ( V_12 ) ) {
F_180 ( V_12 -> V_99 , V_48 , V_193 ) ;
return 1 ;
}
if ( V_194 )
F_176 ( V_12 -> V_99 , V_48 ) ;
if ( V_12 -> V_34 . V_196 . V_197 ( V_12 , V_48 ) ) {
F_180 ( V_12 -> V_99 , V_48 , V_193 ) ;
return 1 ;
}
F_181 ( V_198 , V_12 ) ;
return 0 ;
}
static int F_182 ( struct V_11 * V_12 ,
struct V_47 * V_48 )
{
F_183 ( V_193 ) ;
int V_63 ;
V_63 = F_178 ( V_12 , V_48 , & V_193 , false ) ;
if ( V_63 )
F_184 ( V_12 -> V_99 , & V_193 ) ;
return V_63 ;
}
static void F_185 ( struct V_11 * V_12 , int V_199 ) { }
static void F_186 ( void ) { }
static int F_187 ( struct V_11 * V_12 , struct V_47 * V_48 ,
struct V_192 * V_193 )
{
return F_178 ( V_12 , V_48 , V_193 , true ) ;
}
static void F_188 ( struct V_11 * V_12 , T_2 V_15 )
{
struct V_47 * V_200 ;
F_183 ( V_193 ) ;
bool V_137 = false ;
F_189 (vcpu->kvm, s, gfn) {
if ( ! V_200 -> V_184 )
continue;
F_3 ( V_200 -> V_89 . V_40 != V_41 ) ;
F_176 ( V_12 -> V_99 , V_200 ) ;
if ( ( V_200 -> V_89 . V_195 != ! ! F_179 ( V_12 ) ) ||
( V_12 -> V_34 . V_196 . V_197 ( V_12 , V_200 ) ) ) {
F_180 ( V_12 -> V_99 , V_200 , & V_193 ) ;
continue;
}
V_137 = true ;
}
F_184 ( V_12 -> V_99 , & V_193 ) ;
if ( V_137 )
F_181 ( V_198 , V_12 ) ;
}
static int F_190 ( struct V_182 * V_183 ,
struct V_201 * V_202 ,
int V_103 )
{
int V_203 ;
for ( V_203 = V_103 + 1 ; V_203 < V_183 -> V_169 ; V_203 ++ ) {
struct V_47 * V_48 = V_183 -> V_78 [ V_203 ] . V_48 ;
if ( V_48 -> V_89 . V_40 == V_41 ) {
V_202 -> V_96 [ 0 ] = V_183 -> V_78 [ V_203 ] . V_96 ;
return V_203 ;
}
V_202 -> V_204 [ V_48 -> V_89 . V_40 - 2 ] = V_48 ;
V_202 -> V_96 [ V_48 -> V_89 . V_40 - 1 ] = V_183 -> V_78 [ V_203 ] . V_96 ;
}
return V_203 ;
}
static void F_191 ( struct V_201 * V_202 )
{
struct V_47 * V_48 ;
unsigned int V_40 = 0 ;
do {
unsigned int V_96 = V_202 -> V_96 [ V_40 ] ;
V_48 = V_202 -> V_204 [ V_40 ] ;
if ( ! V_48 )
return;
-- V_48 -> V_180 ;
F_3 ( ( int ) V_48 -> V_180 < 0 ) ;
F_174 ( V_96 , V_48 -> V_179 ) ;
V_40 ++ ;
} while ( V_40 < V_205 - 1 && ! V_48 -> V_180 );
}
static void F_192 ( struct V_47 * V_204 ,
struct V_201 * V_202 ,
struct V_182 * V_183 )
{
V_202 -> V_204 [ V_204 -> V_89 . V_40 - 1 ] = NULL ;
V_183 -> V_169 = 0 ;
}
static void F_193 ( struct V_11 * V_12 ,
struct V_47 * V_204 )
{
int V_103 ;
struct V_47 * V_48 ;
struct V_201 V_202 ;
struct V_182 V_206 ;
F_183 ( V_193 ) ;
F_192 ( V_204 , & V_202 , & V_206 ) ;
while ( F_175 ( V_204 , & V_206 ) ) {
bool V_207 = false ;
F_194 (pages, sp, parents, i)
V_207 |= F_120 ( V_12 , V_48 -> V_15 ) ;
if ( V_207 )
F_108 ( V_12 -> V_99 ) ;
F_194 (pages, sp, parents, i) {
F_187 ( V_12 , V_48 , & V_193 ) ;
F_191 ( & V_202 ) ;
}
F_184 ( V_12 -> V_99 , & V_193 ) ;
F_195 ( & V_12 -> V_99 -> V_208 ) ;
F_192 ( V_204 , & V_202 , & V_206 ) ;
}
}
static void F_196 ( struct V_47 * V_48 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_209 ; ++ V_103 )
V_48 -> V_129 [ V_103 ] = 0ull ;
}
static void F_197 ( struct V_47 * V_48 )
{
V_48 -> V_210 = 0 ;
}
static void F_198 ( T_1 * V_10 )
{
struct V_47 * V_48 = F_35 ( F_36 ( V_10 ) ) ;
F_197 ( V_48 ) ;
}
static bool F_199 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
return F_14 ( V_48 -> V_211 != V_99 -> V_34 . V_211 ) ;
}
static struct V_47 * F_200 ( struct V_11 * V_12 ,
T_2 V_15 ,
T_7 V_212 ,
unsigned V_40 ,
int V_90 ,
unsigned V_16 ,
T_1 * V_175 )
{
union V_213 V_89 ;
unsigned V_214 ;
struct V_47 * V_48 ;
bool V_215 = false ;
V_89 = V_12 -> V_34 . V_196 . V_216 ;
V_89 . V_40 = V_40 ;
V_89 . V_90 = V_90 ;
if ( V_89 . V_90 )
V_89 . V_195 = 0 ;
V_89 . V_16 = V_16 ;
if ( ! V_12 -> V_34 . V_196 . V_217
&& V_12 -> V_34 . V_196 . V_218 <= V_219 ) {
V_214 = V_212 >> ( V_19 + ( V_220 * V_40 ) ) ;
V_214 &= ( 1 << ( ( V_221 - V_220 ) * V_40 ) ) - 1 ;
V_89 . V_214 = V_214 ;
}
F_201 (vcpu->kvm, sp, gfn) {
if ( F_199 ( V_12 -> V_99 , V_48 ) )
continue;
if ( ! V_215 && V_48 -> V_184 )
V_215 = true ;
if ( V_48 -> V_89 . V_222 != V_89 . V_222 )
continue;
if ( V_48 -> V_184 && F_182 ( V_12 , V_48 ) )
break;
F_159 ( V_12 , V_48 , V_175 ) ;
if ( V_48 -> V_180 ) {
F_181 ( V_223 , V_12 ) ;
F_166 ( V_48 ) ;
} else if ( V_48 -> V_184 )
F_166 ( V_48 ) ;
F_197 ( V_48 ) ;
F_202 ( V_48 , false ) ;
return V_48 ;
}
++ V_12 -> V_99 -> V_133 . V_224 ;
V_48 = F_162 ( V_12 , V_175 , V_90 ) ;
if ( ! V_48 )
return V_48 ;
V_48 -> V_15 = V_15 ;
V_48 -> V_89 = V_89 ;
F_203 ( & V_48 -> V_172 ,
& V_12 -> V_99 -> V_34 . V_225 [ F_158 ( V_15 ) ] ) ;
if ( ! V_90 ) {
if ( F_120 ( V_12 , V_15 ) )
F_108 ( V_12 -> V_99 ) ;
if ( V_40 > V_41 && V_215 )
F_188 ( V_12 , V_15 ) ;
F_78 ( V_12 -> V_99 , V_48 ) ;
}
V_48 -> V_211 = V_12 -> V_99 -> V_34 . V_211 ;
F_196 ( V_48 ) ;
F_202 ( V_48 , true ) ;
return V_48 ;
}
static void F_204 ( struct V_226 * V_148 ,
struct V_11 * V_12 , T_1 V_227 )
{
V_148 -> V_227 = V_227 ;
V_148 -> V_228 = V_12 -> V_34 . V_196 . V_229 ;
V_148 -> V_40 = V_12 -> V_34 . V_196 . V_230 ;
if ( V_148 -> V_40 == V_205 &&
V_12 -> V_34 . V_196 . V_218 < V_205 &&
! V_12 -> V_34 . V_196 . V_217 )
-- V_148 -> V_40 ;
if ( V_148 -> V_40 == V_231 ) {
V_148 -> V_228
= V_12 -> V_34 . V_196 . V_232 [ ( V_227 >> 30 ) & 3 ] ;
V_148 -> V_228 &= V_42 ;
-- V_148 -> V_40 ;
if ( ! V_148 -> V_228 )
V_148 -> V_40 = 0 ;
}
}
static bool F_205 ( struct V_226 * V_148 )
{
if ( V_148 -> V_40 < V_41 )
return false ;
V_148 -> V_88 = F_206 ( V_148 -> V_227 , V_148 -> V_40 ) ;
V_148 -> V_14 = ( ( T_1 * ) F_207 ( V_148 -> V_228 ) ) + V_148 -> V_88 ;
return true ;
}
static void F_208 ( struct V_226 * V_148 ,
T_1 V_10 )
{
if ( F_25 ( V_10 , V_148 -> V_40 ) ) {
V_148 -> V_40 = 0 ;
return;
}
V_148 -> V_228 = V_10 & V_42 ;
-- V_148 -> V_40 ;
}
static void F_209 ( struct V_226 * V_148 )
{
return F_208 ( V_148 , * V_148 -> V_14 ) ;
}
static void F_210 ( T_1 * V_14 , struct V_47 * V_48 , bool V_233 )
{
T_1 V_10 ;
F_211 ( V_234 != V_38 ||
V_235 != V_136 ) ;
V_10 = F_36 ( V_48 -> V_129 ) | V_38 | V_136 |
V_29 | V_33 ;
if ( V_233 )
V_10 |= V_30 ;
F_9 ( V_14 , V_10 ) ;
}
static void F_212 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_236 )
{
if ( F_22 ( * V_14 ) && ! F_23 ( * V_14 ) ) {
struct V_47 * V_187 ;
V_187 = F_35 ( * V_14 & V_42 ) ;
if ( V_187 -> V_89 . V_16 == V_236 )
return;
F_161 ( V_187 , V_14 ) ;
F_108 ( V_12 -> V_99 ) ;
}
}
static bool F_213 ( struct V_99 * V_99 , struct V_47 * V_48 ,
T_1 * V_10 )
{
T_1 V_37 ;
struct V_47 * V_187 ;
V_37 = * V_10 ;
if ( F_22 ( V_37 ) ) {
if ( F_25 ( V_37 , V_48 -> V_89 . V_40 ) ) {
F_105 ( V_99 , V_10 ) ;
if ( F_23 ( V_37 ) )
-- V_99 -> V_133 . V_134 ;
} else {
V_187 = F_35 ( V_37 & V_42 ) ;
F_161 ( V_187 , V_10 ) ;
}
return true ;
}
if ( F_10 ( V_37 ) )
F_51 ( V_10 ) ;
return false ;
}
static void F_214 ( struct V_99 * V_99 ,
struct V_47 * V_48 )
{
unsigned V_103 ;
for ( V_103 = 0 ; V_103 < V_209 ; ++ V_103 )
F_213 ( V_99 , V_48 , V_48 -> V_129 + V_103 ) ;
}
static void F_215 ( struct V_47 * V_48 , T_1 * V_175 )
{
F_160 ( V_48 , V_175 ) ;
}
static void F_216 ( struct V_99 * V_99 , struct V_47 * V_48 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
while ( ( V_14 = F_103 ( V_48 -> V_176 , & V_131 ) ) )
F_161 ( V_48 , V_14 ) ;
}
static int F_217 ( struct V_99 * V_99 ,
struct V_47 * V_204 ,
struct V_192 * V_193 )
{
int V_103 , V_237 = 0 ;
struct V_201 V_202 ;
struct V_182 V_206 ;
if ( V_204 -> V_89 . V_40 == V_41 )
return 0 ;
F_192 ( V_204 , & V_202 , & V_206 ) ;
while ( F_175 ( V_204 , & V_206 ) ) {
struct V_47 * V_48 ;
F_194 (pages, sp, parents, i) {
F_180 ( V_99 , V_48 , V_193 ) ;
F_191 ( & V_202 ) ;
V_237 ++ ;
}
F_192 ( V_204 , & V_202 , & V_206 ) ;
}
return V_237 ;
}
static int F_180 ( struct V_99 * V_99 , struct V_47 * V_48 ,
struct V_192 * V_193 )
{
int V_63 ;
F_218 ( V_48 ) ;
++ V_99 -> V_133 . V_238 ;
V_63 = F_217 ( V_99 , V_48 , V_193 ) ;
F_214 ( V_99 , V_48 ) ;
F_216 ( V_99 , V_48 ) ;
if ( ! V_48 -> V_89 . V_239 && ! V_48 -> V_89 . V_90 )
F_81 ( V_99 , V_48 ) ;
if ( V_48 -> V_184 )
F_176 ( V_99 , V_48 ) ;
if ( ! V_48 -> V_240 ) {
V_63 ++ ;
F_219 ( & V_48 -> V_173 , V_193 ) ;
F_152 ( V_99 , - 1 ) ;
} else {
F_219 ( & V_48 -> V_173 , & V_99 -> V_34 . V_177 ) ;
if ( ! V_48 -> V_89 . V_239 && ! F_199 ( V_99 , V_48 ) )
F_220 ( V_99 ) ;
}
V_48 -> V_89 . V_239 = 1 ;
return V_63 ;
}
static void F_184 ( struct V_99 * V_99 ,
struct V_192 * V_193 )
{
struct V_47 * V_48 , * V_241 ;
if ( F_221 ( V_193 ) )
return;
F_55 () ;
F_108 ( V_99 ) ;
F_222 (sp, nsp, invalid_list, link) {
F_3 ( ! V_48 -> V_89 . V_239 || V_48 -> V_240 ) ;
F_154 ( V_48 ) ;
}
}
static bool F_223 ( struct V_99 * V_99 ,
struct V_192 * V_193 )
{
struct V_47 * V_48 ;
if ( F_221 ( & V_99 -> V_34 . V_177 ) )
return false ;
V_48 = F_224 ( V_99 -> V_34 . V_177 . V_242 ,
struct V_47 , V_173 ) ;
F_180 ( V_99 , V_48 , V_193 ) ;
return true ;
}
void F_225 ( struct V_99 * V_99 , unsigned int V_243 )
{
F_183 ( V_193 ) ;
F_226 ( & V_99 -> V_208 ) ;
if ( V_99 -> V_34 . V_170 > V_243 ) {
while ( V_99 -> V_34 . V_170 > V_243 )
if ( ! F_223 ( V_99 , & V_193 ) )
break;
F_184 ( V_99 , & V_193 ) ;
V_243 = V_99 -> V_34 . V_170 ;
}
V_99 -> V_34 . V_244 = V_243 ;
F_227 ( & V_99 -> V_208 ) ;
}
int F_228 ( struct V_99 * V_99 , T_2 V_15 )
{
struct V_47 * V_48 ;
F_183 ( V_193 ) ;
int V_79 ;
F_229 ( L_15 , V_141 , V_15 ) ;
V_79 = 0 ;
F_226 ( & V_99 -> V_208 ) ;
F_189 (kvm, sp, gfn) {
F_229 ( L_16 , V_141 , V_15 ,
V_48 -> V_89 . V_222 ) ;
V_79 = 1 ;
F_180 ( V_99 , V_48 , & V_193 ) ;
}
F_184 ( V_99 , & V_193 ) ;
F_227 ( & V_99 -> V_208 ) ;
return V_79 ;
}
static void F_230 ( struct V_11 * V_12 , struct V_47 * V_48 )
{
F_231 ( V_48 ) ;
++ V_12 -> V_99 -> V_133 . V_191 ;
V_48 -> V_184 = 1 ;
F_166 ( V_48 ) ;
}
static void F_232 ( struct V_11 * V_12 , T_2 V_15 )
{
struct V_47 * V_200 ;
F_189 (vcpu->kvm, s, gfn) {
if ( V_200 -> V_184 )
continue;
F_3 ( V_200 -> V_89 . V_40 != V_41 ) ;
F_230 ( V_12 , V_200 ) ;
}
}
static int F_233 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_245 )
{
struct V_47 * V_200 ;
bool V_246 = false ;
F_189 (vcpu->kvm, s, gfn) {
if ( ! V_245 )
return 1 ;
if ( V_200 -> V_89 . V_40 != V_41 )
return 1 ;
if ( ! V_200 -> V_184 )
V_246 = true ;
}
if ( V_246 )
F_232 ( V_12 , V_15 ) ;
return 0 ;
}
static bool F_234 ( T_3 V_21 )
{
if ( F_235 ( V_21 ) )
return ! F_236 ( V_21 ) && F_237 ( F_50 ( V_21 ) ) ;
return true ;
}
static int F_238 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_247 , int V_40 ,
T_2 V_15 , T_3 V_21 , bool V_248 ,
bool V_245 , bool V_249 )
{
T_1 V_10 ;
int V_63 = 0 ;
if ( F_13 ( V_12 , V_14 , V_15 , V_21 , V_247 ) )
return 0 ;
V_10 = V_38 ;
if ( ! V_248 )
V_10 |= V_30 ;
if ( V_247 & V_250 )
V_10 |= V_33 ;
else
V_10 |= V_32 ;
if ( V_247 & V_18 )
V_10 |= V_29 ;
if ( V_40 > V_41 )
V_10 |= V_39 ;
if ( V_251 )
V_10 |= V_116 -> V_252 ( V_12 , V_15 ,
F_234 ( V_21 ) ) ;
if ( V_249 )
V_10 |= V_58 ;
else
V_247 &= ~ V_17 ;
V_10 |= ( T_1 ) V_21 << V_19 ;
if ( V_247 & V_17 ) {
if ( V_40 > V_41 &&
F_82 ( V_12 , V_15 , V_40 ) )
goto V_253;
V_10 |= V_136 | V_59 ;
if ( ! V_245 && F_41 ( * V_14 ) )
goto V_254;
if ( F_233 ( V_12 , V_15 , V_245 ) ) {
F_229 ( L_17 ,
V_141 , V_15 ) ;
V_63 = 1 ;
V_247 &= ~ V_17 ;
V_10 &= ~ ( V_136 | V_59 ) ;
}
}
if ( V_247 & V_17 ) {
F_239 ( V_12 , V_15 ) ;
V_10 |= V_31 ;
}
V_254:
if ( F_44 ( V_14 , V_10 ) )
F_108 ( V_12 -> V_99 ) ;
V_253:
return V_63 ;
}
static void F_240 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_247 , int V_255 , int * V_256 ,
int V_40 , T_2 V_15 , T_3 V_21 , bool V_248 ,
bool V_249 )
{
int V_257 = 0 ;
int V_258 ;
F_229 ( L_18 , V_141 ,
* V_14 , V_255 , V_15 ) ;
if ( F_24 ( * V_14 ) ) {
if ( V_40 > V_41 &&
! F_23 ( * V_14 ) ) {
struct V_47 * V_187 ;
T_1 V_37 = * V_14 ;
V_187 = F_35 ( V_37 & V_42 ) ;
F_161 ( V_187 , V_14 ) ;
F_108 ( V_12 -> V_99 ) ;
} else if ( V_21 != F_26 ( * V_14 ) ) {
F_229 ( L_19 ,
F_26 ( * V_14 ) , V_21 ) ;
F_105 ( V_12 -> V_99 , V_14 ) ;
F_108 ( V_12 -> V_99 ) ;
} else
V_257 = 1 ;
}
if ( F_238 ( V_12 , V_14 , V_247 , V_40 , V_15 , V_21 , V_248 ,
true , V_249 ) ) {
if ( V_255 )
* V_256 = 1 ;
F_181 ( V_198 , V_12 ) ;
}
if ( F_14 ( F_10 ( * V_14 ) && V_256 ) )
* V_256 = 1 ;
F_229 ( L_20 , V_141 , * V_14 ) ;
F_229 ( L_21 ,
F_23 ( * V_14 ) ? L_22 : L_23 ,
* V_14 & V_38 ? L_24 : L_25 , V_15 ,
* V_14 , V_14 ) ;
if ( ! V_257 && F_23 ( * V_14 ) )
++ V_12 -> V_99 -> V_133 . V_134 ;
if ( F_22 ( * V_14 ) ) {
if ( ! V_257 ) {
V_258 = F_101 ( V_12 , V_14 , V_15 ) ;
if ( V_258 > V_259 )
F_148 ( V_12 , V_14 , V_15 ) ;
}
}
F_241 ( V_21 ) ;
}
static T_3 F_242 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_109 )
{
struct V_94 * V_95 ;
V_95 = F_87 ( V_12 , V_15 , V_109 ) ;
if ( ! V_95 )
return V_260 ;
return F_243 ( V_95 , V_15 ) ;
}
static int F_244 ( struct V_11 * V_12 ,
struct V_47 * V_48 ,
T_1 * V_154 , T_1 * V_155 )
{
struct V_78 * V_206 [ V_82 ] ;
struct V_94 * V_95 ;
unsigned V_16 = V_48 -> V_89 . V_16 ;
int V_103 , V_63 ;
T_2 V_15 ;
V_15 = F_74 ( V_48 , V_154 - V_48 -> V_129 ) ;
V_95 = F_87 ( V_12 , V_15 , V_16 & V_17 ) ;
if ( ! V_95 )
return - 1 ;
V_63 = F_245 ( V_95 , V_15 , V_206 , V_155 - V_154 ) ;
if ( V_63 <= 0 )
return - 1 ;
for ( V_103 = 0 ; V_103 < V_63 ; V_103 ++ , V_15 ++ , V_154 ++ )
F_240 ( V_12 , V_154 , V_16 , 0 , NULL ,
V_48 -> V_89 . V_40 , V_15 , F_246 ( V_206 [ V_103 ] ) ,
true , true ) ;
return 0 ;
}
static void F_247 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_14 )
{
T_1 * V_10 , * V_154 = NULL ;
int V_103 ;
F_3 ( ! V_48 -> V_89 . V_90 ) ;
V_103 = ( V_14 - V_48 -> V_129 ) & ~ ( V_82 - 1 ) ;
V_10 = V_48 -> V_129 + V_103 ;
for ( V_103 = 0 ; V_103 < V_82 ; V_103 ++ , V_10 ++ ) {
if ( F_22 ( * V_10 ) || V_10 == V_14 ) {
if ( ! V_154 )
continue;
if ( F_244 ( V_12 , V_48 , V_154 , V_10 ) < 0 )
break;
V_154 = NULL ;
} else if ( ! V_154 )
V_154 = V_10 ;
}
}
static void F_248 ( struct V_11 * V_12 , T_1 * V_14 )
{
struct V_47 * V_48 ;
if ( ! V_30 )
return;
V_48 = F_35 ( F_36 ( V_14 ) ) ;
if ( V_48 -> V_89 . V_40 > V_41 )
return;
F_247 ( V_12 , V_48 , V_14 ) ;
}
static int F_249 ( struct V_11 * V_12 , T_8 V_261 , int V_262 ,
int V_263 , int V_40 , T_2 V_15 , T_3 V_21 ,
bool V_264 )
{
struct V_226 V_148 ;
struct V_47 * V_48 ;
int V_256 = 0 ;
T_2 V_265 ;
if ( ! F_250 ( V_12 -> V_34 . V_196 . V_229 ) )
return 0 ;
F_251 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_148 . V_40 == V_40 ) {
F_240 ( V_12 , V_148 . V_14 , V_266 ,
V_262 , & V_256 , V_40 , V_15 , V_21 ,
V_264 , V_263 ) ;
F_248 ( V_12 , V_148 . V_14 ) ;
++ V_12 -> V_133 . V_267 ;
break;
}
F_107 ( V_12 , V_148 . V_14 ) ;
if ( ! F_22 ( * V_148 . V_14 ) ) {
T_1 V_268 = V_148 . V_227 ;
V_268 &= F_252 ( V_148 . V_40 ) ;
V_265 = V_268 >> V_19 ;
V_48 = F_200 ( V_12 , V_265 , V_148 . V_227 ,
V_148 . V_40 - 1 ,
1 , V_266 , V_148 . V_14 ) ;
F_210 ( V_148 . V_14 , V_48 , true ) ;
}
}
return V_256 ;
}
static void F_253 ( unsigned long V_269 , struct V_270 * V_271 )
{
T_9 V_272 ;
V_272 . V_273 = V_274 ;
V_272 . V_275 = 0 ;
V_272 . V_276 = V_277 ;
V_272 . V_278 = ( void V_279 * ) V_269 ;
V_272 . V_280 = V_19 ;
F_254 ( V_274 , & V_272 , V_271 ) ;
}
static int F_255 ( struct V_11 * V_12 , T_2 V_15 , T_3 V_21 )
{
if ( V_21 == V_281 )
return 1 ;
if ( V_21 == V_282 ) {
F_253 ( F_256 ( V_12 , V_15 ) , V_283 ) ;
return 0 ;
}
return - V_284 ;
}
static void F_257 ( struct V_11 * V_12 ,
T_2 * V_285 , T_3 * V_286 , int * V_287 )
{
T_3 V_21 = * V_286 ;
T_2 V_15 = * V_285 ;
int V_40 = * V_287 ;
if ( ! F_258 ( V_21 ) && ! F_48 ( V_21 ) &&
V_40 == V_41 &&
F_259 ( F_50 ( V_21 ) ) &&
! F_82 ( V_12 , V_15 , V_104 ) ) {
unsigned long V_4 ;
* V_287 = V_40 = V_104 ;
V_4 = F_260 ( V_40 ) - 1 ;
F_261 ( ( V_15 & V_4 ) != ( V_21 & V_4 ) ) ;
if ( V_21 & V_4 ) {
V_15 &= ~ V_4 ;
* V_285 = V_15 ;
F_241 ( V_21 ) ;
V_21 &= ~ V_4 ;
F_262 ( V_21 ) ;
* V_286 = V_21 ;
}
}
}
static bool F_263 ( struct V_11 * V_12 , T_7 V_181 , T_2 V_15 ,
T_3 V_21 , unsigned V_16 , int * V_288 )
{
bool V_63 = true ;
if ( F_14 ( F_264 ( V_21 ) ) ) {
* V_288 = F_255 ( V_12 , V_15 , V_21 ) ;
goto exit;
}
if ( F_14 ( F_15 ( V_21 ) ) )
F_265 ( V_12 , V_181 , V_15 , V_16 ) ;
V_63 = false ;
exit:
return V_63 ;
}
static bool F_266 ( T_4 V_289 )
{
if ( F_14 ( V_289 & V_290 ) )
return false ;
if ( ! ( V_289 & V_291 ) ||
! ( V_289 & V_292 ) )
return false ;
return true ;
}
static bool
F_267 ( struct V_11 * V_12 , struct V_47 * V_48 ,
T_1 * V_14 , T_1 V_10 )
{
T_2 V_15 ;
F_3 ( ! V_48 -> V_89 . V_90 ) ;
V_15 = F_74 ( V_48 , V_14 - V_48 -> V_129 ) ;
if ( F_268 ( V_14 , V_10 , V_10 | V_136 ) == V_10 )
F_239 ( V_12 , V_15 ) ;
return true ;
}
static bool F_269 ( struct V_11 * V_12 , T_7 V_181 , int V_40 ,
T_4 V_289 )
{
struct V_226 V_148 ;
struct V_47 * V_48 ;
bool V_63 = false ;
T_1 V_10 = 0ull ;
if ( ! F_250 ( V_12 -> V_34 . V_196 . V_229 ) )
return false ;
if ( ! F_266 ( V_289 ) )
return false ;
F_53 ( V_12 ) ;
F_270 (vcpu, gva, iterator, spte)
if ( ! F_22 ( V_10 ) || V_148 . V_40 < V_40 )
break;
if ( ! F_24 ( V_10 ) ) {
V_63 = true ;
goto exit;
}
V_48 = F_35 ( F_36 ( V_148 . V_14 ) ) ;
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
V_63 = F_267 ( V_12 , V_48 , V_148 . V_14 , V_10 ) ;
exit:
F_271 ( V_12 , V_181 , V_289 , V_148 . V_14 ,
V_10 , V_63 ) ;
F_56 ( V_12 ) ;
return V_63 ;
}
static int F_272 ( struct V_11 * V_12 , T_7 V_261 , T_4 V_289 ,
T_2 V_15 , bool V_264 )
{
int V_79 ;
int V_40 ;
int V_293 ;
T_3 V_21 ;
unsigned long V_294 ;
bool V_263 , V_262 = V_289 & V_292 ;
V_293 = F_88 ( V_12 , V_15 ) ;
if ( F_18 ( ! V_293 ) ) {
V_40 = F_89 ( V_12 , V_15 ) ;
if ( V_40 > V_104 )
V_40 = V_104 ;
V_15 &= ~ ( F_260 ( V_40 ) - 1 ) ;
} else
V_40 = V_41 ;
if ( F_269 ( V_12 , V_261 , V_40 , V_289 ) )
return 0 ;
V_294 = V_12 -> V_99 -> V_168 ;
F_38 () ;
if ( F_273 ( V_12 , V_264 , V_15 , V_261 , & V_21 , V_262 , & V_263 ) )
return 0 ;
if ( F_263 ( V_12 , V_261 , V_15 , V_21 , V_266 , & V_79 ) )
return V_79 ;
F_226 ( & V_12 -> V_99 -> V_208 ) ;
if ( F_274 ( V_12 -> V_99 , V_294 ) )
goto V_295;
F_275 ( V_12 ) ;
if ( F_18 ( ! V_293 ) )
F_257 ( V_12 , & V_15 , & V_21 , & V_40 ) ;
V_79 = F_249 ( V_12 , V_261 , V_262 , V_263 , V_40 , V_15 , V_21 ,
V_264 ) ;
F_227 ( & V_12 -> V_99 -> V_208 ) ;
return V_79 ;
V_295:
F_227 ( & V_12 -> V_99 -> V_208 ) ;
F_241 ( V_21 ) ;
return 0 ;
}
static void F_276 ( struct V_11 * V_12 )
{
int V_103 ;
struct V_47 * V_48 ;
F_183 ( V_193 ) ;
if ( ! F_250 ( V_12 -> V_34 . V_196 . V_229 ) )
return;
if ( V_12 -> V_34 . V_196 . V_230 == V_205 &&
( V_12 -> V_34 . V_196 . V_218 == V_205 ||
V_12 -> V_34 . V_196 . V_217 ) ) {
T_10 V_296 = V_12 -> V_34 . V_196 . V_229 ;
F_226 ( & V_12 -> V_99 -> V_208 ) ;
V_48 = F_35 ( V_296 ) ;
-- V_48 -> V_240 ;
if ( ! V_48 -> V_240 && V_48 -> V_89 . V_239 ) {
F_180 ( V_12 -> V_99 , V_48 , & V_193 ) ;
F_184 ( V_12 -> V_99 , & V_193 ) ;
}
F_227 ( & V_12 -> V_99 -> V_208 ) ;
V_12 -> V_34 . V_196 . V_229 = V_297 ;
return;
}
F_226 ( & V_12 -> V_99 -> V_208 ) ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_10 V_296 = V_12 -> V_34 . V_196 . V_232 [ V_103 ] ;
if ( V_296 ) {
V_296 &= V_42 ;
V_48 = F_35 ( V_296 ) ;
-- V_48 -> V_240 ;
if ( ! V_48 -> V_240 && V_48 -> V_89 . V_239 )
F_180 ( V_12 -> V_99 , V_48 ,
& V_193 ) ;
}
V_12 -> V_34 . V_196 . V_232 [ V_103 ] = V_297 ;
}
F_184 ( V_12 -> V_99 , & V_193 ) ;
F_227 ( & V_12 -> V_99 -> V_208 ) ;
V_12 -> V_34 . V_196 . V_229 = V_297 ;
}
static int F_277 ( struct V_11 * V_12 , T_2 V_298 )
{
int V_63 = 0 ;
if ( ! F_278 ( V_12 -> V_99 , V_298 ) ) {
F_181 ( V_299 , V_12 ) ;
V_63 = 1 ;
}
return V_63 ;
}
static int F_279 ( struct V_11 * V_12 )
{
struct V_47 * V_48 ;
unsigned V_103 ;
if ( V_12 -> V_34 . V_196 . V_230 == V_205 ) {
F_226 ( & V_12 -> V_99 -> V_208 ) ;
F_275 ( V_12 ) ;
V_48 = F_200 ( V_12 , 0 , 0 , V_205 ,
1 , V_266 , NULL ) ;
++ V_48 -> V_240 ;
F_227 ( & V_12 -> V_99 -> V_208 ) ;
V_12 -> V_34 . V_196 . V_229 = F_36 ( V_48 -> V_129 ) ;
} else if ( V_12 -> V_34 . V_196 . V_230 == V_231 ) {
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_10 V_296 = V_12 -> V_34 . V_196 . V_232 [ V_103 ] ;
F_155 ( F_250 ( V_296 ) ) ;
F_226 ( & V_12 -> V_99 -> V_208 ) ;
F_275 ( V_12 ) ;
V_48 = F_200 ( V_12 , V_103 << ( 30 - V_19 ) ,
V_103 << 30 ,
V_219 , 1 , V_266 ,
NULL ) ;
V_296 = F_36 ( V_48 -> V_129 ) ;
++ V_48 -> V_240 ;
F_227 ( & V_12 -> V_99 -> V_208 ) ;
V_12 -> V_34 . V_196 . V_232 [ V_103 ] = V_296 | V_38 ;
}
V_12 -> V_34 . V_196 . V_229 = F_36 ( V_12 -> V_34 . V_196 . V_232 ) ;
} else
F_95 () ;
return 0 ;
}
static int F_280 ( struct V_11 * V_12 )
{
struct V_47 * V_48 ;
T_1 V_300 , V_301 ;
T_2 V_298 ;
int V_103 ;
V_298 = V_12 -> V_34 . V_196 . V_302 ( V_12 ) >> V_19 ;
if ( F_277 ( V_12 , V_298 ) )
return 1 ;
if ( V_12 -> V_34 . V_196 . V_218 == V_205 ) {
T_10 V_296 = V_12 -> V_34 . V_196 . V_229 ;
F_155 ( F_250 ( V_296 ) ) ;
F_226 ( & V_12 -> V_99 -> V_208 ) ;
F_275 ( V_12 ) ;
V_48 = F_200 ( V_12 , V_298 , 0 , V_205 ,
0 , V_266 , NULL ) ;
V_296 = F_36 ( V_48 -> V_129 ) ;
++ V_48 -> V_240 ;
F_227 ( & V_12 -> V_99 -> V_208 ) ;
V_12 -> V_34 . V_196 . V_229 = V_296 ;
return 0 ;
}
V_301 = V_38 ;
if ( V_12 -> V_34 . V_196 . V_230 == V_205 )
V_301 |= V_303 | V_136 | V_304 ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_10 V_296 = V_12 -> V_34 . V_196 . V_232 [ V_103 ] ;
F_155 ( F_250 ( V_296 ) ) ;
if ( V_12 -> V_34 . V_196 . V_218 == V_231 ) {
V_300 = V_12 -> V_34 . V_196 . V_305 ( V_12 , V_103 ) ;
if ( ! F_281 ( V_300 ) ) {
V_12 -> V_34 . V_196 . V_232 [ V_103 ] = 0 ;
continue;
}
V_298 = V_300 >> V_19 ;
if ( F_277 ( V_12 , V_298 ) )
return 1 ;
}
F_226 ( & V_12 -> V_99 -> V_208 ) ;
F_275 ( V_12 ) ;
V_48 = F_200 ( V_12 , V_298 , V_103 << 30 ,
V_219 , 0 ,
V_266 , NULL ) ;
V_296 = F_36 ( V_48 -> V_129 ) ;
++ V_48 -> V_240 ;
F_227 ( & V_12 -> V_99 -> V_208 ) ;
V_12 -> V_34 . V_196 . V_232 [ V_103 ] = V_296 | V_301 ;
}
V_12 -> V_34 . V_196 . V_229 = F_36 ( V_12 -> V_34 . V_196 . V_232 ) ;
if ( V_12 -> V_34 . V_196 . V_230 == V_205 ) {
if ( V_12 -> V_34 . V_196 . V_306 == NULL ) {
T_1 * V_306 ;
V_306 = ( void * ) F_282 ( V_75 ) ;
if ( V_306 == NULL )
return 1 ;
V_306 [ 0 ] = F_36 ( V_12 -> V_34 . V_196 . V_232 ) | V_301 ;
V_12 -> V_34 . V_196 . V_306 = V_306 ;
}
V_12 -> V_34 . V_196 . V_229 = F_36 ( V_12 -> V_34 . V_196 . V_306 ) ;
}
return 0 ;
}
static int F_283 ( struct V_11 * V_12 )
{
if ( V_12 -> V_34 . V_196 . V_217 )
return F_279 ( V_12 ) ;
else
return F_280 ( V_12 ) ;
}
static void F_284 ( struct V_11 * V_12 )
{
int V_103 ;
struct V_47 * V_48 ;
if ( V_12 -> V_34 . V_196 . V_217 )
return;
if ( ! F_250 ( V_12 -> V_34 . V_196 . V_229 ) )
return;
F_285 ( V_12 , V_307 ) ;
F_185 ( V_12 , V_308 ) ;
if ( V_12 -> V_34 . V_196 . V_218 == V_205 ) {
T_10 V_296 = V_12 -> V_34 . V_196 . V_229 ;
V_48 = F_35 ( V_296 ) ;
F_193 ( V_12 , V_48 ) ;
F_185 ( V_12 , V_309 ) ;
return;
}
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
T_10 V_296 = V_12 -> V_34 . V_196 . V_232 [ V_103 ] ;
if ( V_296 && F_250 ( V_296 ) ) {
V_296 &= V_42 ;
V_48 = F_35 ( V_296 ) ;
F_193 ( V_12 , V_48 ) ;
}
}
F_185 ( V_12 , V_309 ) ;
}
void F_286 ( struct V_11 * V_12 )
{
F_226 ( & V_12 -> V_99 -> V_208 ) ;
F_284 ( V_12 ) ;
F_227 ( & V_12 -> V_99 -> V_208 ) ;
}
static T_8 F_287 ( struct V_11 * V_12 , T_7 V_310 ,
T_4 V_16 , struct V_311 * V_312 )
{
if ( V_312 )
V_312 -> V_289 = 0 ;
return V_310 ;
}
static T_8 F_288 ( struct V_11 * V_12 , T_7 V_310 ,
T_4 V_16 ,
struct V_311 * V_312 )
{
if ( V_312 )
V_312 -> V_289 = 0 ;
return V_12 -> V_34 . V_313 . V_314 ( V_12 , V_310 , V_16 , V_312 ) ;
}
static bool
F_289 ( struct V_315 * V_316 , T_1 V_37 , int V_40 )
{
int V_317 = ( V_37 >> 7 ) & 1 , V_318 = V_37 & 0x3f ;
return ( V_37 & V_316 -> V_319 [ V_317 ] [ V_40 - 1 ] ) |
( ( V_316 -> V_320 & ( 1ull << V_318 ) ) != 0 ) ;
}
static bool F_290 ( struct V_321 * V_196 , T_1 V_43 , int V_40 )
{
return F_289 ( & V_196 -> V_322 , V_43 , V_40 ) ;
}
static bool F_291 ( struct V_321 * V_196 , T_1 V_10 , int V_40 )
{
return F_289 ( & V_196 -> V_323 , V_10 , V_40 ) ;
}
static bool F_292 ( struct V_11 * V_12 , T_1 V_227 , bool V_90 )
{
if ( V_90 )
return F_293 ( V_12 , V_227 ) ;
return F_294 ( V_12 , V_227 ) ;
}
static bool
F_295 ( struct V_11 * V_12 , T_1 V_227 , T_1 * V_14 )
{
struct V_226 V_148 ;
T_1 V_120 [ V_205 ] , V_10 = 0ull ;
int V_296 , V_324 ;
bool V_325 = false ;
if ( ! F_250 ( V_12 -> V_34 . V_196 . V_229 ) )
goto exit;
F_53 ( V_12 ) ;
for ( F_204 ( & V_148 , V_12 , V_227 ) ,
V_324 = V_296 = V_148 . V_40 ;
F_205 ( & V_148 ) ;
F_208 ( & V_148 , V_10 ) ) {
V_10 = F_52 ( V_148 . V_14 ) ;
V_120 [ V_324 - 1 ] = V_10 ;
V_324 -- ;
if ( ! F_22 ( V_10 ) )
break;
V_325 |= F_291 ( & V_12 -> V_34 . V_196 , V_10 ,
V_148 . V_40 ) ;
}
F_56 ( V_12 ) ;
if ( V_325 ) {
F_96 ( L_26 ,
V_141 , V_227 ) ;
while ( V_296 > V_324 ) {
F_96 ( L_27 ,
V_120 [ V_296 - 1 ] , V_296 ) ;
V_296 -- ;
}
}
exit:
* V_14 = V_10 ;
return V_325 ;
}
int F_296 ( struct V_11 * V_12 , T_1 V_227 , bool V_90 )
{
T_1 V_10 ;
bool V_325 ;
if ( F_292 ( V_12 , V_227 , V_90 ) )
return V_326 ;
V_325 = F_295 ( V_12 , V_227 , & V_10 ) ;
if ( F_14 ( V_325 ) )
return V_327 ;
if ( F_10 ( V_10 ) ) {
T_2 V_15 = F_11 ( V_10 ) ;
unsigned V_16 = F_12 ( V_10 ) ;
if ( ! F_16 ( V_12 , V_10 ) )
return V_328 ;
if ( V_90 )
V_227 = 0 ;
F_297 ( V_227 , V_15 , V_16 ) ;
F_265 ( V_12 , V_227 , V_15 , V_16 ) ;
return V_326 ;
}
return V_329 ;
}
static int F_298 ( struct V_11 * V_12 , T_1 V_227 ,
T_4 V_289 , bool V_90 )
{
int V_63 ;
V_63 = F_296 ( V_12 , V_227 , V_90 ) ;
F_3 ( V_63 == V_327 ) ;
return V_63 ;
}
static int F_299 ( struct V_11 * V_12 , T_7 V_181 ,
T_4 V_289 , bool V_264 )
{
T_2 V_15 ;
int V_79 ;
F_229 ( L_28 , V_141 , V_181 , V_289 ) ;
if ( F_14 ( V_289 & V_290 ) ) {
V_79 = F_298 ( V_12 , V_181 , V_289 , true ) ;
if ( F_18 ( V_79 != V_328 ) )
return V_79 ;
}
V_79 = F_68 ( V_12 ) ;
if ( V_79 )
return V_79 ;
F_155 ( ! F_250 ( V_12 -> V_34 . V_196 . V_229 ) ) ;
V_15 = V_181 >> V_19 ;
return F_272 ( V_12 , V_181 & V_20 ,
V_289 , V_15 , V_264 ) ;
}
static int F_300 ( struct V_11 * V_12 , T_7 V_181 , T_2 V_15 )
{
struct V_330 V_34 ;
V_34 . V_331 = ( V_12 -> V_34 . V_332 . V_333 ++ << 12 ) | V_12 -> V_334 ;
V_34 . V_15 = V_15 ;
V_34 . V_217 = V_12 -> V_34 . V_196 . V_217 ;
V_34 . V_335 = V_12 -> V_34 . V_196 . V_302 ( V_12 ) ;
return F_301 ( V_12 , V_181 , F_256 ( V_12 , V_15 ) , & V_34 ) ;
}
static bool F_302 ( struct V_11 * V_12 )
{
if ( F_14 ( ! F_303 ( V_12 -> V_99 ) ||
F_304 ( V_12 ) ) )
return false ;
return V_116 -> V_336 ( V_12 ) ;
}
static bool F_273 ( struct V_11 * V_12 , bool V_264 , T_2 V_15 ,
T_7 V_181 , T_3 * V_21 , bool V_262 , bool * V_337 )
{
struct V_94 * V_95 ;
bool V_338 ;
V_95 = F_83 ( V_12 , V_15 ) ;
V_338 = false ;
* V_21 = F_305 ( V_95 , V_15 , false , & V_338 , V_262 , V_337 ) ;
if ( ! V_338 )
return false ;
if ( ! V_264 && F_302 ( V_12 ) ) {
F_306 ( V_181 , V_15 ) ;
if ( F_307 ( V_12 , V_15 ) ) {
F_308 ( V_181 , V_15 ) ;
F_181 ( V_339 , V_12 ) ;
return true ;
} else if ( F_300 ( V_12 , V_181 , V_15 ) )
return true ;
}
* V_21 = F_305 ( V_95 , V_15 , false , NULL , V_262 , V_337 ) ;
return false ;
}
static bool
F_309 ( struct V_11 * V_12 , T_2 V_15 , int V_40 )
{
int V_340 = F_260 ( V_40 ) ;
V_15 &= ~ ( V_340 - 1 ) ;
return F_310 ( V_12 , V_15 , V_340 ) ;
}
static int F_311 ( struct V_11 * V_12 , T_7 V_341 , T_4 V_289 ,
bool V_264 )
{
T_3 V_21 ;
int V_79 ;
int V_40 ;
int V_293 ;
T_2 V_15 = V_341 >> V_19 ;
unsigned long V_294 ;
int V_262 = V_289 & V_292 ;
bool V_263 ;
F_155 ( ! F_250 ( V_12 -> V_34 . V_196 . V_229 ) ) ;
if ( F_14 ( V_289 & V_290 ) ) {
V_79 = F_298 ( V_12 , V_341 , V_289 , true ) ;
if ( F_18 ( V_79 != V_328 ) )
return V_79 ;
}
V_79 = F_68 ( V_12 ) ;
if ( V_79 )
return V_79 ;
if ( F_88 ( V_12 , V_15 ) ||
! F_309 ( V_12 , V_15 , V_104 ) )
V_293 = 1 ;
else
V_293 = 0 ;
if ( F_18 ( ! V_293 ) ) {
V_40 = F_89 ( V_12 , V_15 ) ;
if ( V_40 > V_104 &&
! F_309 ( V_12 , V_15 , V_40 ) )
V_40 = V_104 ;
V_15 &= ~ ( F_260 ( V_40 ) - 1 ) ;
} else
V_40 = V_41 ;
if ( F_269 ( V_12 , V_341 , V_40 , V_289 ) )
return 0 ;
V_294 = V_12 -> V_99 -> V_168 ;
F_38 () ;
if ( F_273 ( V_12 , V_264 , V_15 , V_341 , & V_21 , V_262 , & V_263 ) )
return 0 ;
if ( F_263 ( V_12 , 0 , V_15 , V_21 , V_266 , & V_79 ) )
return V_79 ;
F_226 ( & V_12 -> V_99 -> V_208 ) ;
if ( F_274 ( V_12 -> V_99 , V_294 ) )
goto V_295;
F_275 ( V_12 ) ;
if ( F_18 ( ! V_293 ) )
F_257 ( V_12 , & V_15 , & V_21 , & V_40 ) ;
V_79 = F_249 ( V_12 , V_341 , V_262 , V_263 ,
V_40 , V_15 , V_21 , V_264 ) ;
F_227 ( & V_12 -> V_99 -> V_208 ) ;
return V_79 ;
V_295:
F_227 ( & V_12 -> V_99 -> V_208 ) ;
F_241 ( V_21 ) ;
return 0 ;
}
static void F_312 ( struct V_11 * V_12 ,
struct V_321 * V_342 )
{
V_342 -> V_343 = F_299 ;
V_342 -> V_344 = F_287 ;
V_342 -> V_197 = F_168 ;
V_342 -> V_345 = F_169 ;
V_342 -> V_346 = F_170 ;
V_342 -> V_218 = 0 ;
V_342 -> V_230 = V_231 ;
V_342 -> V_229 = V_297 ;
V_342 -> V_217 = true ;
V_342 -> V_347 = false ;
}
void F_313 ( struct V_11 * V_12 )
{
F_276 ( V_12 ) ;
}
static unsigned long V_302 ( struct V_11 * V_12 )
{
return F_314 ( V_12 ) ;
}
static void F_315 ( struct V_11 * V_12 ,
struct V_311 * V_348 )
{
V_12 -> V_34 . V_196 . F_315 ( V_12 , V_348 ) ;
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
static inline bool F_317 ( struct V_321 * V_196 , unsigned V_40 , unsigned V_43 )
{
unsigned V_88 ;
V_88 = V_40 - 1 ;
V_88 |= ( V_43 & V_39 ) >> ( V_350 - 2 ) ;
return V_196 -> V_351 & ( 1 << V_88 ) ;
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
case V_219 :
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
case V_231 :
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
case V_205 :
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
F_321 ( V_12 ) , V_342 -> V_218 ,
V_342 -> V_347 , F_322 ( V_12 ) ,
F_323 ( V_12 ) , F_324 ( V_12 ) ) ;
}
static void
F_325 ( struct V_315 * V_316 ,
int V_352 , bool V_359 )
{
int V_37 ;
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
for ( V_37 = 0 ; V_37 < 64 ; V_37 ++ ) {
int V_360 = V_37 & 7 ;
int V_361 = V_37 >> 3 ;
if ( V_361 == 0x2 || V_361 == 0x3 || V_361 == 0x7 ||
V_360 == 0x2 || V_360 == 0x6 ||
( V_360 == 0x4 && ! V_359 ) )
V_316 -> V_320 |= ( 1ull << V_37 ) ;
}
}
static void F_326 ( struct V_11 * V_12 ,
struct V_321 * V_342 , bool V_359 )
{
F_325 ( & V_342 -> V_322 ,
F_321 ( V_12 ) , V_359 ) ;
}
void
F_327 ( struct V_11 * V_12 , struct V_321 * V_342 )
{
F_318 ( V_12 , & V_342 -> V_323 ,
V_362 . V_363 ,
V_342 -> V_230 , V_342 -> V_347 ,
F_322 ( V_12 ) , F_323 ( V_12 ) ,
true ) ;
}
static inline bool F_328 ( void )
{
F_329 ( ! V_251 ) ;
return V_33 == 0 ;
}
static void
F_330 ( struct V_11 * V_12 ,
struct V_321 * V_342 )
{
if ( F_328 () )
F_318 ( V_12 , & V_342 -> V_323 ,
V_362 . V_363 ,
V_342 -> V_230 , false ,
V_364 , true , true ) ;
else
F_325 ( & V_342 -> V_323 ,
V_362 . V_363 ,
false ) ;
}
static void
F_331 ( struct V_11 * V_12 ,
struct V_321 * V_342 , bool V_359 )
{
F_325 ( & V_342 -> V_323 ,
V_362 . V_363 , V_359 ) ;
}
static void F_332 ( struct V_11 * V_12 ,
struct V_321 * V_196 , bool V_365 )
{
unsigned V_366 , V_367 , V_368 ;
T_11 V_369 ;
bool V_348 , V_370 , V_371 , V_372 , V_373 , V_374 , V_375 , V_376 , V_377 , V_378 , V_379 = 0 ;
V_378 = F_333 ( V_12 , V_380 ) ;
V_377 = F_333 ( V_12 , V_381 ) ;
for ( V_367 = 0 ; V_367 < F_59 ( V_196 -> V_382 ) ; ++ V_367 ) {
V_368 = V_367 << 1 ;
V_369 = 0 ;
V_373 = V_368 & V_292 ;
V_374 = V_368 & V_383 ;
V_375 = V_368 & V_384 ;
V_376 = ! ( V_368 & V_290 ) ;
for ( V_366 = 0 ; V_366 < 8 ; ++ V_366 ) {
V_370 = V_366 & V_250 ;
V_371 = V_366 & V_17 ;
V_372 = V_366 & V_18 ;
if ( ! V_365 ) {
V_370 |= ! V_196 -> V_347 ;
V_371 |= ! F_334 ( V_12 ) && ! V_374 ;
V_370 &= ! ( V_378 && V_372 && ! V_374 ) ;
V_379 = V_377 && V_372 && ! V_374 && ! V_375 ;
} else
V_372 = 1 ;
V_348 = ( V_375 && ! V_370 ) || ( V_374 && ! V_372 ) || ( V_373 && ! V_371 ) ||
( V_376 && V_379 ) ;
V_369 |= V_348 << V_366 ;
}
V_196 -> V_382 [ V_367 ] = V_369 ;
}
}
static void F_335 ( struct V_11 * V_12 , struct V_321 * V_196 )
{
T_11 V_369 ;
unsigned V_40 , V_218 = V_196 -> V_218 ;
const unsigned V_385 = 1 << 2 ;
if ( V_218 == V_231 )
-- V_218 ;
V_369 = 1 | ( 1 << V_385 ) ;
for ( V_40 = V_104 ; V_40 <= V_218 ; ++ V_40 ) {
if ( V_40 <= V_386
&& ( V_196 -> V_218 >= V_231 || F_323 ( V_12 ) ) )
V_369 |= 1 << ( V_385 | ( V_40 - 1 ) ) ;
}
V_196 -> V_351 = V_369 ;
}
static void F_336 ( struct V_11 * V_12 ,
struct V_321 * V_342 ,
int V_40 )
{
V_342 -> V_347 = F_21 ( V_12 ) ;
V_342 -> V_218 = V_40 ;
F_320 ( V_12 , V_342 ) ;
F_332 ( V_12 , V_342 , false ) ;
F_335 ( V_12 , V_342 ) ;
F_155 ( ! F_179 ( V_12 ) ) ;
V_342 -> V_343 = V_387 ;
V_342 -> V_344 = V_388 ;
V_342 -> V_197 = V_389 ;
V_342 -> V_345 = V_390 ;
V_342 -> V_346 = V_391 ;
V_342 -> V_230 = V_40 ;
V_342 -> V_229 = V_297 ;
V_342 -> V_217 = false ;
}
static void F_337 ( struct V_11 * V_12 ,
struct V_321 * V_342 )
{
F_336 ( V_12 , V_342 , V_205 ) ;
}
static void F_338 ( struct V_11 * V_12 ,
struct V_321 * V_342 )
{
V_342 -> V_347 = false ;
V_342 -> V_218 = V_219 ;
F_320 ( V_12 , V_342 ) ;
F_332 ( V_12 , V_342 , false ) ;
F_335 ( V_12 , V_342 ) ;
V_342 -> V_343 = V_392 ;
V_342 -> V_344 = V_393 ;
V_342 -> V_197 = V_394 ;
V_342 -> V_345 = V_395 ;
V_342 -> V_346 = V_396 ;
V_342 -> V_230 = V_231 ;
V_342 -> V_229 = V_297 ;
V_342 -> V_217 = false ;
}
static void F_339 ( struct V_11 * V_12 ,
struct V_321 * V_342 )
{
F_336 ( V_12 , V_342 , V_231 ) ;
}
static void F_340 ( struct V_11 * V_12 )
{
struct V_321 * V_342 = & V_12 -> V_34 . V_196 ;
V_342 -> V_216 . V_222 = 0 ;
V_342 -> V_216 . V_397 = F_341 ( V_12 ) ;
V_342 -> V_343 = F_311 ;
V_342 -> V_197 = F_168 ;
V_342 -> V_345 = F_169 ;
V_342 -> V_346 = F_170 ;
V_342 -> V_230 = V_116 -> V_398 () ;
V_342 -> V_229 = V_297 ;
V_342 -> V_217 = true ;
V_342 -> V_399 = V_116 -> V_400 ;
V_342 -> V_302 = V_302 ;
V_342 -> V_305 = V_401 ;
V_342 -> F_315 = V_402 ;
if ( ! F_342 ( V_12 ) ) {
V_342 -> V_347 = false ;
V_342 -> V_344 = F_287 ;
V_342 -> V_218 = 0 ;
} else if ( F_343 ( V_12 ) ) {
V_342 -> V_347 = F_21 ( V_12 ) ;
V_342 -> V_218 = V_205 ;
F_320 ( V_12 , V_342 ) ;
V_342 -> V_344 = V_388 ;
} else if ( F_179 ( V_12 ) ) {
V_342 -> V_347 = F_21 ( V_12 ) ;
V_342 -> V_218 = V_231 ;
F_320 ( V_12 , V_342 ) ;
V_342 -> V_344 = V_388 ;
} else {
V_342 -> V_347 = false ;
V_342 -> V_218 = V_219 ;
F_320 ( V_12 , V_342 ) ;
V_342 -> V_344 = V_393 ;
}
F_332 ( V_12 , V_342 , false ) ;
F_335 ( V_12 , V_342 ) ;
F_330 ( V_12 , V_342 ) ;
}
void F_344 ( struct V_11 * V_12 )
{
bool V_403 = F_333 ( V_12 , V_380 ) ;
bool V_379 = F_333 ( V_12 , V_381 ) ;
struct V_321 * V_342 = & V_12 -> V_34 . V_196 ;
F_155 ( F_250 ( V_342 -> V_229 ) ) ;
if ( ! F_342 ( V_12 ) )
F_312 ( V_12 , V_342 ) ;
else if ( F_343 ( V_12 ) )
F_337 ( V_12 , V_342 ) ;
else if ( F_179 ( V_12 ) )
F_339 ( V_12 , V_342 ) ;
else
F_338 ( V_12 , V_342 ) ;
V_342 -> V_216 . V_404 = F_21 ( V_12 ) ;
V_342 -> V_216 . V_195 = ! ! F_179 ( V_12 ) ;
V_342 -> V_216 . V_405 = F_334 ( V_12 ) ;
V_342 -> V_216 . V_406
= V_403 && ! F_334 ( V_12 ) ;
V_342 -> V_216 . V_407
= V_379 && ! F_334 ( V_12 ) ;
V_342 -> V_216 . V_397 = F_341 ( V_12 ) ;
F_327 ( V_12 , V_342 ) ;
}
void F_345 ( struct V_11 * V_12 , bool V_359 )
{
struct V_321 * V_342 = & V_12 -> V_34 . V_196 ;
F_155 ( F_250 ( V_342 -> V_229 ) ) ;
V_342 -> V_230 = V_116 -> V_398 () ;
V_342 -> V_347 = true ;
V_342 -> V_343 = V_408 ;
V_342 -> V_344 = V_409 ;
V_342 -> V_197 = V_410 ;
V_342 -> V_345 = V_411 ;
V_342 -> V_346 = V_412 ;
V_342 -> V_218 = V_342 -> V_230 ;
V_342 -> V_229 = V_297 ;
V_342 -> V_217 = false ;
F_332 ( V_12 , V_342 , true ) ;
F_326 ( V_12 , V_342 , V_359 ) ;
F_331 ( V_12 , V_342 , V_359 ) ;
}
static void F_346 ( struct V_11 * V_12 )
{
struct V_321 * V_342 = & V_12 -> V_34 . V_196 ;
F_344 ( V_12 ) ;
V_342 -> V_399 = V_116 -> V_399 ;
V_342 -> V_302 = V_302 ;
V_342 -> V_305 = V_401 ;
V_342 -> F_315 = V_402 ;
}
static void F_347 ( struct V_11 * V_12 )
{
struct V_321 * V_413 = & V_12 -> V_34 . V_313 ;
V_413 -> V_302 = V_302 ;
V_413 -> V_305 = V_401 ;
V_413 -> F_315 = V_402 ;
if ( ! F_342 ( V_12 ) ) {
V_413 -> V_347 = false ;
V_413 -> V_218 = 0 ;
V_413 -> V_344 = F_288 ;
} else if ( F_343 ( V_12 ) ) {
V_413 -> V_347 = F_21 ( V_12 ) ;
V_413 -> V_218 = V_205 ;
F_320 ( V_12 , V_413 ) ;
V_413 -> V_344 = V_414 ;
} else if ( F_179 ( V_12 ) ) {
V_413 -> V_347 = F_21 ( V_12 ) ;
V_413 -> V_218 = V_231 ;
F_320 ( V_12 , V_413 ) ;
V_413 -> V_344 = V_414 ;
} else {
V_413 -> V_347 = false ;
V_413 -> V_218 = V_219 ;
F_320 ( V_12 , V_413 ) ;
V_413 -> V_344 = V_415 ;
}
F_332 ( V_12 , V_413 , false ) ;
F_335 ( V_12 , V_413 ) ;
}
static void F_348 ( struct V_11 * V_12 )
{
if ( F_349 ( V_12 ) )
F_347 ( V_12 ) ;
else if ( V_251 )
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
V_79 = F_68 ( V_12 ) ;
if ( V_79 )
goto V_83;
V_79 = F_283 ( V_12 ) ;
F_286 ( V_12 ) ;
if ( V_79 )
goto V_83;
V_12 -> V_34 . V_196 . V_399 ( V_12 , V_12 -> V_34 . V_196 . V_229 ) ;
V_83:
return V_79 ;
}
void F_351 ( struct V_11 * V_12 )
{
F_276 ( V_12 ) ;
F_3 ( F_250 ( V_12 -> V_34 . V_196 . V_229 ) ) ;
}
static void F_353 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_10 ,
const void * V_416 )
{
if ( V_48 -> V_89 . V_40 != V_41 ) {
++ V_12 -> V_99 -> V_133 . V_417 ;
return;
}
++ V_12 -> V_99 -> V_133 . V_418 ;
V_12 -> V_34 . V_196 . V_346 ( V_12 , V_48 , V_10 , V_416 ) ;
}
static bool F_354 ( T_1 V_419 , T_1 V_416 )
{
if ( ! F_22 ( V_419 ) )
return false ;
if ( ! F_22 ( V_416 ) )
return true ;
if ( ( V_419 ^ V_416 ) & V_42 )
return true ;
V_419 ^= V_32 ;
V_416 ^= V_32 ;
return ( V_419 & ~ V_416 & V_420 ) != 0 ;
}
static void F_355 ( struct V_11 * V_12 , bool V_421 ,
bool V_422 , bool V_423 )
{
if ( V_421 )
return;
if ( V_422 )
F_108 ( V_12 -> V_99 ) ;
else if ( V_423 )
F_181 ( V_198 , V_12 ) ;
}
static T_1 F_356 ( struct V_11 * V_12 , T_8 * V_341 ,
const T_11 * V_416 , int * V_424 )
{
T_1 V_425 ;
int V_79 ;
if ( F_179 ( V_12 ) && * V_424 == 4 ) {
* V_341 &= ~ ( T_8 ) 7 ;
* V_424 = 8 ;
V_79 = F_357 ( V_12 , * V_341 , & V_425 , 8 ) ;
if ( V_79 )
V_425 = 0 ;
V_416 = ( const T_11 * ) & V_425 ;
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
static bool F_358 ( struct V_47 * V_48 )
{
if ( V_48 -> V_89 . V_40 == V_41 )
return false ;
return ++ V_48 -> V_210 >= 3 ;
}
static bool F_359 ( struct V_47 * V_48 , T_8 V_341 ,
int V_424 )
{
unsigned V_426 , V_427 , V_428 ;
F_229 ( L_29 ,
V_341 , V_424 , V_48 -> V_89 . V_222 ) ;
V_426 = F_360 ( V_341 ) ;
V_427 = V_48 -> V_89 . V_195 ? 8 : 4 ;
if ( ! ( V_426 & ( V_427 - 1 ) ) && V_424 == 1 )
return false ;
V_428 = ( V_426 ^ ( V_426 + V_424 - 1 ) ) & ~ ( V_427 - 1 ) ;
V_428 |= V_424 < 4 ;
return V_428 ;
}
static T_1 * F_361 ( struct V_47 * V_48 , T_8 V_341 , int * V_429 )
{
unsigned V_430 , V_214 ;
T_1 * V_10 ;
int V_40 ;
V_430 = F_360 ( V_341 ) ;
V_40 = V_48 -> V_89 . V_40 ;
* V_429 = 1 ;
if ( ! V_48 -> V_89 . V_195 ) {
V_430 <<= 1 ;
if ( V_40 == V_219 ) {
V_430 &= ~ 7 ;
V_430 <<= 1 ;
* V_429 = 2 ;
}
V_214 = V_430 >> V_19 ;
V_430 &= ~ V_20 ;
if ( V_214 != V_48 -> V_89 . V_214 )
return NULL ;
}
V_10 = & V_48 -> V_129 [ V_430 / sizeof( * V_10 ) ] ;
return V_10 ;
}
void F_362 ( struct V_11 * V_12 , T_8 V_341 ,
const T_11 * V_416 , int V_424 )
{
T_2 V_15 = V_341 >> V_19 ;
struct V_47 * V_48 ;
F_183 ( V_193 ) ;
T_1 V_431 , V_425 , * V_10 ;
int V_432 ;
bool V_422 , V_423 , V_421 ;
union V_213 V_4 = { } ;
V_4 . V_405 = 1 ;
V_4 . V_195 = 1 ;
V_4 . V_404 = 1 ;
V_4 . V_406 = 1 ;
V_4 . V_407 = 1 ;
V_4 . V_397 = 1 ;
if ( ! F_33 ( V_12 -> V_99 -> V_34 . V_107 ) )
return;
V_421 = V_422 = V_423 = false ;
F_229 ( L_30 , V_141 , V_341 , V_424 ) ;
V_425 = F_356 ( V_12 , & V_341 , V_416 , & V_424 ) ;
F_68 ( V_12 ) ;
F_226 ( & V_12 -> V_99 -> V_208 ) ;
++ V_12 -> V_99 -> V_133 . V_433 ;
F_185 ( V_12 , V_434 ) ;
F_189 (vcpu->kvm, sp, gfn) {
if ( F_359 ( V_48 , V_341 , V_424 ) ||
F_358 ( V_48 ) ) {
V_421 |= ! ! F_180 ( V_12 -> V_99 , V_48 ,
& V_193 ) ;
++ V_12 -> V_99 -> V_133 . V_435 ;
continue;
}
V_10 = F_361 ( V_48 , V_341 , & V_432 ) ;
if ( ! V_10 )
continue;
V_423 = true ;
while ( V_432 -- ) {
V_431 = * V_10 ;
F_213 ( V_12 -> V_99 , V_48 , V_10 ) ;
if ( V_425 &&
! ( ( V_48 -> V_89 . V_222 ^ V_12 -> V_34 . V_196 . V_216 . V_222 )
& V_4 . V_222 ) && F_100 ( V_12 ) )
F_353 ( V_12 , V_48 , V_10 , & V_425 ) ;
if ( F_354 ( V_431 , * V_10 ) )
V_422 = true ;
++ V_10 ;
}
}
F_355 ( V_12 , V_421 , V_422 , V_423 ) ;
F_184 ( V_12 -> V_99 , & V_193 ) ;
F_185 ( V_12 , V_436 ) ;
F_227 ( & V_12 -> V_99 -> V_208 ) ;
}
int F_363 ( struct V_11 * V_12 , T_7 V_181 )
{
T_8 V_341 ;
int V_79 ;
if ( V_12 -> V_34 . V_196 . V_217 )
return 0 ;
V_341 = F_364 ( V_12 , V_181 , NULL ) ;
V_79 = F_228 ( V_12 -> V_99 , V_341 >> V_19 ) ;
return V_79 ;
}
static void F_275 ( struct V_11 * V_12 )
{
F_183 ( V_193 ) ;
if ( F_18 ( F_365 ( V_12 -> V_99 ) >= V_437 ) )
return;
while ( F_365 ( V_12 -> V_99 ) < V_438 ) {
if ( ! F_223 ( V_12 -> V_99 , & V_193 ) )
break;
++ V_12 -> V_99 -> V_133 . V_439 ;
}
F_184 ( V_12 -> V_99 , & V_193 ) ;
}
static bool F_366 ( struct V_11 * V_12 , T_7 V_227 )
{
if ( V_12 -> V_34 . V_196 . V_217 || F_349 ( V_12 ) )
return F_293 ( V_12 , V_227 ) ;
return F_294 ( V_12 , V_227 ) ;
}
int F_367 ( struct V_11 * V_12 , T_7 V_440 , T_4 V_289 ,
void * V_441 , int V_442 )
{
int V_79 , V_443 = V_444 ;
enum V_445 V_446 ;
V_79 = V_12 -> V_34 . V_196 . V_343 ( V_12 , V_440 , V_289 , false ) ;
if ( V_79 < 0 )
goto V_83;
if ( ! V_79 ) {
V_79 = 1 ;
goto V_83;
}
if ( F_366 ( V_12 , V_440 ) )
V_443 = 0 ;
V_446 = F_368 ( V_12 , V_440 , V_443 , V_441 , V_442 ) ;
switch ( V_446 ) {
case V_447 :
return 1 ;
case V_448 :
++ V_12 -> V_133 . V_449 ;
case V_450 :
return 0 ;
default:
F_95 () ;
}
V_83:
return V_79 ;
}
void F_369 ( struct V_11 * V_12 , T_7 V_181 )
{
V_12 -> V_34 . V_196 . V_345 ( V_12 , V_181 ) ;
F_181 ( V_198 , V_12 ) ;
++ V_12 -> V_133 . V_345 ;
}
void F_370 ( void )
{
V_251 = true ;
}
void F_371 ( void )
{
V_251 = false ;
}
static void F_372 ( struct V_11 * V_12 )
{
F_67 ( ( unsigned long ) V_12 -> V_34 . V_196 . V_232 ) ;
if ( V_12 -> V_34 . V_196 . V_306 != NULL )
F_67 ( ( unsigned long ) V_12 -> V_34 . V_196 . V_306 ) ;
}
static int F_373 ( struct V_11 * V_12 )
{
struct V_78 * V_78 ;
int V_103 ;
V_78 = F_374 ( V_75 | V_451 ) ;
if ( ! V_78 )
return - V_76 ;
V_12 -> V_34 . V_196 . V_232 = F_375 ( V_78 ) ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 )
V_12 -> V_34 . V_196 . V_232 [ V_103 ] = V_297 ;
return 0 ;
}
int F_376 ( struct V_11 * V_12 )
{
V_12 -> V_34 . V_452 = & V_12 -> V_34 . V_196 ;
V_12 -> V_34 . V_196 . V_229 = V_297 ;
V_12 -> V_34 . V_196 . V_314 = V_314 ;
V_12 -> V_34 . V_313 . V_314 = V_453 ;
return F_373 ( V_12 ) ;
}
void F_377 ( struct V_11 * V_12 )
{
F_155 ( F_250 ( V_12 -> V_34 . V_196 . V_229 ) ) ;
F_348 ( V_12 ) ;
}
static bool
F_378 ( struct V_99 * V_99 , struct V_94 * V_156 ,
T_12 V_126 , int V_152 , int V_153 ,
T_2 V_149 , T_2 V_151 , bool V_454 )
{
struct V_147 V_148 ;
bool V_137 = false ;
F_138 (memslot, start_level, end_level, start_gfn,
end_gfn, &iterator) {
if ( V_148 . V_127 )
V_137 |= V_126 ( V_99 , V_148 . V_127 ) ;
if ( F_379 () || F_380 ( & V_99 -> V_208 ) ) {
if ( V_137 && V_454 ) {
F_108 ( V_99 ) ;
V_137 = false ;
}
F_195 ( & V_99 -> V_208 ) ;
}
}
if ( V_137 && V_454 ) {
F_108 ( V_99 ) ;
V_137 = false ;
}
return V_137 ;
}
static bool
F_381 ( struct V_99 * V_99 , struct V_94 * V_156 ,
T_12 V_126 , int V_152 , int V_153 ,
bool V_454 )
{
return F_378 ( V_99 , V_156 , V_126 , V_152 ,
V_153 , V_156 -> V_97 ,
V_156 -> V_97 + V_156 -> V_163 - 1 ,
V_454 ) ;
}
static bool
F_382 ( struct V_99 * V_99 , struct V_94 * V_156 ,
T_12 V_126 , bool V_454 )
{
return F_381 ( V_99 , V_156 , V_126 , V_41 ,
V_105 , V_454 ) ;
}
static bool
F_383 ( struct V_99 * V_99 , struct V_94 * V_156 ,
T_12 V_126 , bool V_454 )
{
return F_381 ( V_99 , V_156 , V_126 , V_41 + 1 ,
V_105 , V_454 ) ;
}
static bool
F_384 ( struct V_99 * V_99 , struct V_94 * V_156 ,
T_12 V_126 , bool V_454 )
{
return F_381 ( V_99 , V_156 , V_126 , V_41 ,
V_41 , V_454 ) ;
}
void F_385 ( struct V_99 * V_99 , T_2 V_160 , T_2 V_161 )
{
struct V_100 * V_101 ;
struct V_94 * V_156 ;
int V_103 ;
F_226 ( & V_99 -> V_208 ) ;
for ( V_103 = 0 ; V_103 < V_157 ; V_103 ++ ) {
V_101 = F_134 ( V_99 , V_103 ) ;
F_135 (memslot, slots) {
T_2 V_154 , V_155 ;
V_154 = F_136 ( V_160 , V_156 -> V_97 ) ;
V_155 = V_71 ( V_161 , V_156 -> V_97 + V_156 -> V_163 ) ;
if ( V_154 >= V_155 )
continue;
F_378 ( V_99 , V_156 , F_121 ,
V_41 , V_105 ,
V_154 , V_155 - 1 , true ) ;
}
}
F_227 ( & V_99 -> V_208 ) ;
}
static bool F_386 ( struct V_99 * V_99 , unsigned long * V_128 )
{
return F_110 ( V_99 , V_128 , false ) ;
}
void F_387 ( struct V_99 * V_99 ,
struct V_94 * V_156 )
{
bool V_137 ;
F_226 ( & V_99 -> V_208 ) ;
V_137 = F_382 ( V_99 , V_156 , F_386 ,
false ) ;
F_227 ( & V_99 -> V_208 ) ;
F_388 ( & V_99 -> V_455 ) ;
if ( V_137 )
F_108 ( V_99 ) ;
}
static bool F_389 ( struct V_99 * V_99 ,
unsigned long * V_128 )
{
T_1 * V_14 ;
struct V_130 V_131 ;
int V_456 = 0 ;
T_3 V_21 ;
struct V_47 * V_48 ;
V_146:
F_111 (rmapp, &iter, sptep) {
V_48 = F_35 ( F_36 ( V_14 ) ) ;
V_21 = F_26 ( * V_14 ) ;
if ( V_48 -> V_89 . V_90 &&
! F_48 ( V_21 ) &&
F_259 ( F_50 ( V_21 ) ) ) {
F_105 ( V_99 , V_14 ) ;
V_456 = 1 ;
goto V_146;
}
}
return V_456 ;
}
void F_390 ( struct V_99 * V_99 ,
const struct V_94 * V_156 )
{
F_226 ( & V_99 -> V_208 ) ;
F_384 ( V_99 , (struct V_94 * ) V_156 ,
F_389 , true ) ;
F_227 ( & V_99 -> V_208 ) ;
}
void F_391 ( struct V_99 * V_99 ,
struct V_94 * V_156 )
{
bool V_137 ;
F_226 ( & V_99 -> V_208 ) ;
V_137 = F_384 ( V_99 , V_156 , F_113 , false ) ;
F_227 ( & V_99 -> V_208 ) ;
F_388 ( & V_99 -> V_455 ) ;
if ( V_137 )
F_108 ( V_99 ) ;
}
void F_392 ( struct V_99 * V_99 ,
struct V_94 * V_156 )
{
bool V_137 ;
F_226 ( & V_99 -> V_208 ) ;
V_137 = F_383 ( V_99 , V_156 , F_386 ,
false ) ;
F_227 ( & V_99 -> V_208 ) ;
F_388 ( & V_99 -> V_455 ) ;
if ( V_137 )
F_108 ( V_99 ) ;
}
void F_393 ( struct V_99 * V_99 ,
struct V_94 * V_156 )
{
bool V_137 ;
F_226 ( & V_99 -> V_208 ) ;
V_137 = F_382 ( V_99 , V_156 , F_115 , false ) ;
F_227 ( & V_99 -> V_208 ) ;
F_388 ( & V_99 -> V_455 ) ;
if ( V_137 )
F_108 ( V_99 ) ;
}
static void F_394 ( struct V_99 * V_99 )
{
struct V_47 * V_48 , * V_457 ;
int V_458 = 0 ;
V_146:
F_395 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_63 ;
if ( ! F_199 ( V_99 , V_48 ) )
break;
if ( V_48 -> V_89 . V_239 )
continue;
if ( V_458 >= V_459 &&
F_195 ( & V_99 -> V_208 ) ) {
V_458 = 0 ;
goto V_146;
}
V_63 = F_180 ( V_99 , V_48 ,
& V_99 -> V_34 . V_460 ) ;
V_458 += V_63 ;
if ( V_63 )
goto V_146;
}
F_184 ( V_99 , & V_99 -> V_34 . V_460 ) ;
}
void F_396 ( struct V_99 * V_99 )
{
F_226 ( & V_99 -> V_208 ) ;
F_397 ( V_99 ) ;
V_99 -> V_34 . V_211 ++ ;
F_220 ( V_99 ) ;
F_394 ( V_99 ) ;
F_227 ( & V_99 -> V_208 ) ;
}
static bool F_398 ( struct V_99 * V_99 )
{
return F_14 ( ! F_399 ( & V_99 -> V_34 . V_460 ) ) ;
}
void F_400 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
if ( F_14 ( ( V_101 -> V_13 & V_5 ) == 0 ) ) {
F_401 ( V_461 L_31 ) ;
F_396 ( V_99 ) ;
}
}
static unsigned long
F_402 ( struct V_462 * V_463 , struct V_464 * V_465 )
{
struct V_99 * V_99 ;
int V_466 = V_465 -> V_466 ;
unsigned long V_467 = 0 ;
F_226 ( & V_468 ) ;
F_403 (kvm, &vm_list, vm_list) {
int V_96 ;
F_183 ( V_193 ) ;
if ( ! V_466 -- )
break;
if ( ! V_99 -> V_34 . V_170 &&
! F_398 ( V_99 ) )
continue;
V_96 = F_404 ( & V_99 -> V_469 ) ;
F_226 ( & V_99 -> V_208 ) ;
if ( F_398 ( V_99 ) ) {
F_184 ( V_99 ,
& V_99 -> V_34 . V_460 ) ;
goto V_470;
}
if ( F_223 ( V_99 , & V_193 ) )
V_467 ++ ;
F_184 ( V_99 , & V_193 ) ;
V_470:
F_227 ( & V_99 -> V_208 ) ;
F_405 ( & V_99 -> V_469 , V_96 ) ;
F_406 ( & V_99 -> V_471 , & V_471 ) ;
break;
}
F_227 ( & V_468 ) ;
return V_467 ;
}
static unsigned long
F_407 ( struct V_462 * V_463 , struct V_464 * V_465 )
{
return F_408 ( & V_171 ) ;
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
goto V_472;
V_85 = F_412 ( L_33 ,
sizeof( struct V_47 ) ,
0 , 0 , NULL ) ;
if ( ! V_85 )
goto V_472;
if ( F_413 ( & V_171 , 0 , V_75 ) )
goto V_472;
F_414 ( & V_473 ) ;
return 0 ;
V_472:
F_409 () ;
return - V_76 ;
}
unsigned int F_415 ( struct V_99 * V_99 )
{
unsigned int V_474 ;
unsigned int V_475 = 0 ;
struct V_100 * V_101 ;
struct V_94 * V_156 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_157 ; V_103 ++ ) {
V_101 = F_134 ( V_99 , V_103 ) ;
F_135 (memslot, slots)
V_475 += V_156 -> V_163 ;
}
V_474 = V_475 * V_476 / 1000 ;
V_474 = F_136 ( V_474 ,
( unsigned int ) V_477 ) ;
return V_474 ;
}
void F_416 ( struct V_11 * V_12 )
{
F_351 ( V_12 ) ;
F_372 ( V_12 ) ;
F_69 ( V_12 ) ;
}
void F_417 ( void )
{
F_409 () ;
F_418 ( & V_171 ) ;
F_419 ( & V_473 ) ;
F_186 () ;
}
