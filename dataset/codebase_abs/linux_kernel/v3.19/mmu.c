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
static unsigned int F_5 ( struct V_11 * V_11 )
{
return F_6 ( V_11 ) -> V_12 & V_5 ;
}
static void F_7 ( struct V_11 * V_11 , T_1 * V_13 , T_1 V_14 ,
unsigned V_15 )
{
unsigned int V_3 = F_5 ( V_11 ) ;
T_1 V_4 = F_2 ( V_3 ) ;
V_15 &= V_16 | V_17 ;
V_4 |= V_2 | V_15 | V_14 << V_18 ;
F_8 ( V_13 , V_14 , V_15 , V_3 ) ;
F_9 ( V_13 , V_4 ) ;
}
static bool F_10 ( T_1 V_10 )
{
return ( V_10 & V_2 ) == V_2 ;
}
static T_2 F_11 ( T_1 V_10 )
{
T_1 V_4 = F_2 ( V_5 ) | V_2 ;
return ( V_10 & ~ V_4 ) >> V_18 ;
}
static unsigned F_12 ( T_1 V_10 )
{
T_1 V_4 = F_2 ( V_5 ) | V_2 ;
return ( V_10 & ~ V_4 ) & ~ V_19 ;
}
static bool F_13 ( struct V_11 * V_11 , T_1 * V_13 , T_2 V_14 ,
T_3 V_20 , unsigned V_15 )
{
if ( F_14 ( F_15 ( V_20 ) ) ) {
F_7 ( V_11 , V_13 , V_14 , V_15 ) ;
return true ;
}
return false ;
}
static bool F_16 ( struct V_11 * V_11 , T_1 V_10 )
{
unsigned int V_21 , V_22 ;
V_21 = F_5 ( V_11 ) ;
V_22 = F_4 ( V_10 ) ;
F_17 ( V_10 , V_21 , V_22 ) ;
return F_18 ( V_21 == V_22 ) ;
}
void F_19 ( T_1 V_23 , T_1 V_24 ,
T_1 V_25 , T_1 V_26 , T_1 V_27 )
{
V_28 = V_23 ;
V_29 = V_24 ;
V_30 = V_25 ;
V_31 = V_26 ;
V_32 = V_27 ;
}
static int F_20 ( void )
{
return 1 ;
}
static int F_21 ( struct V_33 * V_34 )
{
return V_34 -> V_35 . V_36 & V_37 ;
}
static int F_22 ( T_1 V_38 )
{
return V_38 & V_39 && ! F_10 ( V_38 ) ;
}
static int F_23 ( T_1 V_38 )
{
return V_38 & V_40 ;
}
static int F_24 ( T_1 V_38 )
{
return F_22 ( V_38 ) ;
}
static int F_25 ( T_1 V_38 , int V_41 )
{
if ( V_41 == V_42 )
return 1 ;
if ( F_23 ( V_38 ) )
return 1 ;
return 0 ;
}
static T_3 F_26 ( T_1 V_38 )
{
return ( V_38 & V_43 ) >> V_18 ;
}
static T_2 F_27 ( T_4 V_44 )
{
int V_45 = 32 - V_46 - V_18 ;
return ( V_44 & V_47 ) << V_45 ;
}
static void F_28 ( T_1 * V_13 , T_1 V_10 )
{
* V_13 = V_10 ;
}
static void F_29 ( T_1 * V_13 , T_1 V_10 )
{
* V_13 = V_10 ;
}
static T_1 F_30 ( T_1 * V_13 , T_1 V_10 )
{
return F_31 ( V_13 , V_10 ) ;
}
static T_1 F_32 ( T_1 * V_13 )
{
return F_33 ( * V_13 ) ;
}
static bool F_34 ( T_1 V_10 )
{
return V_10 == 0ull ;
}
static void F_35 ( T_1 * V_13 , T_1 V_10 )
{
struct V_48 * V_49 = F_36 ( F_37 ( V_13 ) ) ;
if ( F_22 ( V_10 ) )
return;
F_38 () ;
V_49 -> V_50 ++ ;
}
static void F_28 ( T_1 * V_13 , T_1 V_10 )
{
union V_51 * V_52 , V_53 ;
V_52 = (union V_51 * ) V_13 ;
V_53 = (union V_51 ) V_10 ;
V_52 -> V_54 = V_53 . V_54 ;
F_38 () ;
V_52 -> V_55 = V_53 . V_55 ;
}
static void F_29 ( T_1 * V_13 , T_1 V_10 )
{
union V_51 * V_52 , V_53 ;
V_52 = (union V_51 * ) V_13 ;
V_53 = (union V_51 ) V_10 ;
V_52 -> V_55 = V_53 . V_55 ;
F_38 () ;
V_52 -> V_54 = V_53 . V_54 ;
F_35 ( V_13 , V_10 ) ;
}
static T_1 F_30 ( T_1 * V_13 , T_1 V_10 )
{
union V_51 * V_52 , V_53 , V_56 ;
V_52 = (union V_51 * ) V_13 ;
V_53 = (union V_51 ) V_10 ;
V_56 . V_55 = F_31 ( & V_52 -> V_55 , V_53 . V_55 ) ;
V_56 . V_54 = V_52 -> V_54 ;
V_52 -> V_54 = V_53 . V_54 ;
F_35 ( V_13 , V_10 ) ;
return V_56 . V_10 ;
}
static T_1 F_32 ( T_1 * V_13 )
{
struct V_48 * V_49 = F_36 ( F_37 ( V_13 ) ) ;
union V_51 V_10 , * V_56 = (union V_51 * ) V_13 ;
int V_57 ;
V_58:
V_57 = V_49 -> V_50 ;
F_39 () ;
V_10 . V_55 = V_56 -> V_55 ;
F_39 () ;
V_10 . V_54 = V_56 -> V_54 ;
F_39 () ;
if ( F_14 ( V_10 . V_55 != V_56 -> V_55 ||
V_57 != V_49 -> V_50 ) )
goto V_58;
return V_10 . V_10 ;
}
static bool F_34 ( T_1 V_10 )
{
union V_51 V_53 = (union V_51 ) V_10 ;
T_4 V_59 = V_2 >> 32 ;
if ( V_10 == 0ull )
return true ;
if ( V_53 . V_55 == 0ull &&
( V_53 . V_54 & V_59 ) == V_59 )
return true ;
return false ;
}
static bool F_40 ( T_1 V_10 )
{
return ( V_10 & ( V_60 | V_61 ) ) ==
( V_60 | V_61 ) ;
}
static bool F_41 ( T_1 V_10 )
{
if ( F_40 ( V_10 ) )
return true ;
if ( ! V_29 )
return false ;
if ( ! F_22 ( V_10 ) )
return false ;
if ( ( V_10 & V_29 ) &&
( ! F_42 ( V_10 ) || ( V_10 & V_30 ) ) )
return false ;
return true ;
}
static bool F_43 ( T_1 V_62 , T_1 V_63 , T_1 V_64 )
{
return ( V_62 & V_64 ) && ! ( V_63 & V_64 ) ;
}
static void F_9 ( T_1 * V_13 , T_1 V_63 )
{
F_3 ( F_22 ( * V_13 ) ) ;
F_28 ( V_13 , V_63 ) ;
}
static bool F_44 ( T_1 * V_13 , T_1 V_63 )
{
T_1 V_62 = * V_13 ;
bool V_65 = false ;
F_3 ( ! F_24 ( V_63 ) ) ;
if ( ! F_22 ( V_62 ) ) {
F_9 ( V_13 , V_63 ) ;
return V_65 ;
}
if ( ! F_41 ( V_62 ) )
F_29 ( V_13 , V_63 ) ;
else
V_62 = F_30 ( V_13 , V_63 ) ;
if ( F_40 ( V_62 ) &&
! F_42 ( V_63 ) )
V_65 = true ;
if ( ! V_29 )
return V_65 ;
if ( F_43 ( V_62 , V_63 , V_29 ) )
F_45 ( F_26 ( V_62 ) ) ;
if ( F_43 ( V_62 , V_63 , V_30 ) )
F_46 ( F_26 ( V_62 ) ) ;
return V_65 ;
}
static int F_47 ( T_1 * V_13 )
{
T_3 V_20 ;
T_1 V_62 = * V_13 ;
if ( ! F_41 ( V_62 ) )
F_29 ( V_13 , 0ull ) ;
else
V_62 = F_30 ( V_13 , 0ull ) ;
if ( ! F_24 ( V_62 ) )
return 0 ;
V_20 = F_26 ( V_62 ) ;
F_3 ( ! F_48 ( V_20 ) && ! F_49 ( F_50 ( V_20 ) ) ) ;
if ( ! V_29 || V_62 & V_29 )
F_45 ( V_20 ) ;
if ( ! V_30 || ( V_62 & V_30 ) )
F_46 ( V_20 ) ;
return 1 ;
}
static void F_51 ( T_1 * V_13 )
{
F_29 ( V_13 , 0ull ) ;
}
static T_1 F_52 ( T_1 * V_13 )
{
return F_32 ( V_13 ) ;
}
static void F_53 ( struct V_33 * V_34 )
{
F_54 () ;
V_34 -> V_66 = V_67 ;
F_55 () ;
}
static void F_56 ( struct V_33 * V_34 )
{
F_55 () ;
V_34 -> V_66 = V_68 ;
F_57 () ;
}
static int F_58 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
void * V_74 ;
if ( V_70 -> V_75 >= V_73 )
return 0 ;
while ( V_70 -> V_75 < F_59 ( V_70 -> V_76 ) ) {
V_74 = F_60 ( V_72 , V_77 ) ;
if ( ! V_74 )
return - V_78 ;
V_70 -> V_76 [ V_70 -> V_75 ++ ] = V_74 ;
}
return 0 ;
}
static int F_61 ( struct V_69 * V_70 )
{
return V_70 -> V_75 ;
}
static void F_62 ( struct V_69 * V_79 ,
struct V_71 * V_70 )
{
while ( V_79 -> V_75 )
F_63 ( V_70 , V_79 -> V_76 [ -- V_79 -> V_75 ] ) ;
}
static int F_64 ( struct V_69 * V_70 ,
int V_73 )
{
void * V_80 ;
if ( V_70 -> V_75 >= V_73 )
return 0 ;
while ( V_70 -> V_75 < F_59 ( V_70 -> V_76 ) ) {
V_80 = ( void * ) F_65 ( V_77 ) ;
if ( ! V_80 )
return - V_78 ;
V_70 -> V_76 [ V_70 -> V_75 ++ ] = V_80 ;
}
return 0 ;
}
static void F_66 ( struct V_69 * V_79 )
{
while ( V_79 -> V_75 )
F_67 ( ( unsigned long ) V_79 -> V_76 [ -- V_79 -> V_75 ] ) ;
}
static int F_68 ( struct V_33 * V_34 )
{
int V_81 ;
V_81 = F_58 ( & V_34 -> V_35 . V_82 ,
V_83 , 8 + V_84 ) ;
if ( V_81 )
goto V_85;
V_81 = F_64 ( & V_34 -> V_35 . V_86 , 8 ) ;
if ( V_81 )
goto V_85;
V_81 = F_58 ( & V_34 -> V_35 . V_87 ,
V_87 , 4 ) ;
V_85:
return V_81 ;
}
static void F_69 ( struct V_33 * V_34 )
{
F_62 ( & V_34 -> V_35 . V_82 ,
V_83 ) ;
F_66 ( & V_34 -> V_35 . V_86 ) ;
F_62 ( & V_34 -> V_35 . V_87 ,
V_87 ) ;
}
static void * F_70 ( struct V_69 * V_79 )
{
void * V_88 ;
F_71 ( ! V_79 -> V_75 ) ;
V_88 = V_79 -> V_76 [ -- V_79 -> V_75 ] ;
return V_88 ;
}
static struct V_89 * F_72 ( struct V_33 * V_34 )
{
return F_70 ( & V_34 -> V_35 . V_82 ) ;
}
static void F_73 ( struct V_89 * V_89 )
{
F_63 ( V_83 , V_89 ) ;
}
static T_2 F_74 ( struct V_48 * V_49 , int V_90 )
{
if ( ! V_49 -> V_91 . V_92 )
return V_49 -> V_93 [ V_90 ] ;
return V_49 -> V_14 + ( V_90 << ( ( V_49 -> V_91 . V_41 - 1 ) * V_94 ) ) ;
}
static void F_75 ( struct V_48 * V_49 , int V_90 , T_2 V_14 )
{
if ( V_49 -> V_91 . V_92 )
F_71 ( V_14 != F_74 ( V_49 , V_90 ) ) ;
else
V_49 -> V_93 [ V_90 ] = V_14 ;
}
static struct V_95 * F_76 ( T_2 V_14 ,
struct V_96 * V_97 ,
int V_41 )
{
unsigned long V_98 ;
V_98 = F_77 ( V_14 , V_97 -> V_99 , V_41 ) ;
return & V_97 -> V_35 . V_100 [ V_41 - 2 ] [ V_98 ] ;
}
static void F_78 ( struct V_11 * V_11 , T_2 V_14 )
{
struct V_96 * V_97 ;
struct V_95 * V_101 ;
int V_102 ;
V_97 = F_79 ( V_11 , V_14 ) ;
for ( V_102 = V_103 ;
V_102 < V_42 + V_104 ; ++ V_102 ) {
V_101 = F_76 ( V_14 , V_97 , V_102 ) ;
V_101 -> V_105 += 1 ;
}
V_11 -> V_35 . V_106 ++ ;
}
static void F_80 ( struct V_11 * V_11 , T_2 V_14 )
{
struct V_96 * V_97 ;
struct V_95 * V_101 ;
int V_102 ;
V_97 = F_79 ( V_11 , V_14 ) ;
for ( V_102 = V_103 ;
V_102 < V_42 + V_104 ; ++ V_102 ) {
V_101 = F_76 ( V_14 , V_97 , V_102 ) ;
V_101 -> V_105 -= 1 ;
F_3 ( V_101 -> V_105 < 0 ) ;
}
V_11 -> V_35 . V_106 -- ;
}
static int F_81 ( struct V_11 * V_11 ,
T_2 V_14 ,
int V_41 )
{
struct V_96 * V_97 ;
struct V_95 * V_101 ;
V_97 = F_79 ( V_11 , V_14 ) ;
if ( V_97 ) {
V_101 = F_76 ( V_14 , V_97 , V_41 ) ;
return V_101 -> V_105 ;
}
return 1 ;
}
static int F_82 ( struct V_11 * V_11 , T_2 V_14 )
{
unsigned long V_107 ;
int V_102 , V_65 = 0 ;
V_107 = F_83 ( V_11 , V_14 ) ;
for ( V_102 = V_42 ;
V_102 < ( V_42 + V_104 ) ; ++ V_102 ) {
if ( V_107 >= F_84 ( V_102 ) )
V_65 = V_102 ;
else
break;
}
return V_65 ;
}
static struct V_96 *
F_85 ( struct V_33 * V_34 , T_2 V_14 ,
bool V_108 )
{
struct V_96 * V_97 ;
V_97 = F_79 ( V_34 -> V_11 , V_14 ) ;
if ( ! V_97 || V_97 -> V_109 & V_110 ||
( V_108 && V_97 -> V_111 ) )
V_97 = NULL ;
return V_97 ;
}
static bool F_86 ( struct V_33 * V_34 , T_2 V_112 )
{
return ! F_85 ( V_34 , V_112 , true ) ;
}
static int F_87 ( struct V_33 * V_34 , T_2 V_112 )
{
int V_113 , V_41 , V_114 ;
V_113 = F_82 ( V_34 -> V_11 , V_112 ) ;
if ( V_113 == V_42 )
return V_113 ;
V_114 = V_73 ( V_115 -> V_116 () , V_113 ) ;
for ( V_41 = V_103 ; V_41 <= V_114 ; ++ V_41 )
if ( F_81 ( V_34 -> V_11 , V_112 , V_41 ) )
break;
return V_41 - 1 ;
}
static int F_88 ( struct V_33 * V_34 , T_1 * V_10 ,
unsigned long * V_117 )
{
struct V_89 * V_118 ;
int V_102 , V_57 = 0 ;
if ( ! * V_117 ) {
F_89 ( L_1 , V_10 , * V_10 ) ;
* V_117 = ( unsigned long ) V_10 ;
} else if ( ! ( * V_117 & 1 ) ) {
F_89 ( L_2 , V_10 , * V_10 ) ;
V_118 = F_72 ( V_34 ) ;
V_118 -> V_119 [ 0 ] = ( T_1 * ) * V_117 ;
V_118 -> V_119 [ 1 ] = V_10 ;
* V_117 = ( unsigned long ) V_118 | 1 ;
++ V_57 ;
} else {
F_89 ( L_3 , V_10 , * V_10 ) ;
V_118 = (struct V_89 * ) ( * V_117 & ~ 1ul ) ;
while ( V_118 -> V_119 [ V_120 - 1 ] && V_118 -> V_121 ) {
V_118 = V_118 -> V_121 ;
V_57 += V_120 ;
}
if ( V_118 -> V_119 [ V_120 - 1 ] ) {
V_118 -> V_121 = F_72 ( V_34 ) ;
V_118 = V_118 -> V_121 ;
}
for ( V_102 = 0 ; V_118 -> V_119 [ V_102 ] ; ++ V_102 )
++ V_57 ;
V_118 -> V_119 [ V_102 ] = V_10 ;
}
return V_57 ;
}
static void
F_90 ( unsigned long * V_117 , struct V_89 * V_118 ,
int V_102 , struct V_89 * V_122 )
{
int V_123 ;
for ( V_123 = V_120 - 1 ; ! V_118 -> V_119 [ V_123 ] && V_123 > V_102 ; -- V_123 )
;
V_118 -> V_119 [ V_102 ] = V_118 -> V_119 [ V_123 ] ;
V_118 -> V_119 [ V_123 ] = NULL ;
if ( V_123 != 0 )
return;
if ( ! V_122 && ! V_118 -> V_121 )
* V_117 = ( unsigned long ) V_118 -> V_119 [ 0 ] ;
else
if ( V_122 )
V_122 -> V_121 = V_118 -> V_121 ;
else
* V_117 = ( unsigned long ) V_118 -> V_121 | 1 ;
F_73 ( V_118 ) ;
}
static void F_91 ( T_1 * V_10 , unsigned long * V_117 )
{
struct V_89 * V_118 ;
struct V_89 * V_122 ;
int V_102 ;
if ( ! * V_117 ) {
F_92 ( V_124 L_4 , V_10 ) ;
F_93 () ;
} else if ( ! ( * V_117 & 1 ) ) {
F_89 ( L_5 , V_10 ) ;
if ( ( T_1 * ) * V_117 != V_10 ) {
F_92 ( V_124 L_6 , V_10 ) ;
F_93 () ;
}
* V_117 = 0 ;
} else {
F_89 ( L_7 , V_10 ) ;
V_118 = (struct V_89 * ) ( * V_117 & ~ 1ul ) ;
V_122 = NULL ;
while ( V_118 ) {
for ( V_102 = 0 ; V_102 < V_120 && V_118 -> V_119 [ V_102 ] ; ++ V_102 )
if ( V_118 -> V_119 [ V_102 ] == V_10 ) {
F_90 ( V_117 ,
V_118 , V_102 ,
V_122 ) ;
return;
}
V_122 = V_118 ;
V_118 = V_118 -> V_121 ;
}
F_94 ( L_8 , V_10 ) ;
F_93 () ;
}
}
static void F_95 ( unsigned long * V_117 , T_5 V_125 )
{
struct V_89 * V_118 ;
int V_102 ;
if ( ! * V_117 )
return;
if ( ! ( * V_117 & 1 ) )
return V_125 ( ( T_1 * ) * V_117 ) ;
V_118 = (struct V_89 * ) ( * V_117 & ~ 1ul ) ;
while ( V_118 ) {
for ( V_102 = 0 ; V_102 < V_120 && V_118 -> V_119 [ V_102 ] ; ++ V_102 )
V_125 ( V_118 -> V_119 [ V_102 ] ) ;
V_118 = V_118 -> V_121 ;
}
}
static unsigned long * F_96 ( T_2 V_14 , int V_41 ,
struct V_96 * V_97 )
{
unsigned long V_98 ;
V_98 = F_77 ( V_14 , V_97 -> V_99 , V_41 ) ;
return & V_97 -> V_35 . V_126 [ V_41 - V_42 ] [ V_98 ] ;
}
static unsigned long * F_97 ( struct V_11 * V_11 , T_2 V_14 , int V_41 )
{
struct V_96 * V_97 ;
V_97 = F_79 ( V_11 , V_14 ) ;
return F_96 ( V_14 , V_41 , V_97 ) ;
}
static bool F_98 ( struct V_33 * V_34 )
{
struct V_69 * V_70 ;
V_70 = & V_34 -> V_35 . V_82 ;
return F_61 ( V_70 ) ;
}
static int F_99 ( struct V_33 * V_34 , T_1 * V_10 , T_2 V_14 )
{
struct V_48 * V_49 ;
unsigned long * V_127 ;
V_49 = F_36 ( F_37 ( V_10 ) ) ;
F_75 ( V_49 , V_10 - V_49 -> V_128 , V_14 ) ;
V_127 = F_97 ( V_34 -> V_11 , V_14 , V_49 -> V_91 . V_41 ) ;
return F_88 ( V_34 , V_10 , V_127 ) ;
}
static void F_100 ( struct V_11 * V_11 , T_1 * V_10 )
{
struct V_48 * V_49 ;
T_2 V_14 ;
unsigned long * V_127 ;
V_49 = F_36 ( F_37 ( V_10 ) ) ;
V_14 = F_74 ( V_49 , V_10 - V_49 -> V_128 ) ;
V_127 = F_97 ( V_11 , V_14 , V_49 -> V_91 . V_41 ) ;
F_91 ( V_10 , V_127 ) ;
}
static T_1 * F_101 ( unsigned long V_126 , struct V_129 * V_130 )
{
if ( ! V_126 )
return NULL ;
if ( ! ( V_126 & 1 ) ) {
V_130 -> V_118 = NULL ;
return ( T_1 * ) V_126 ;
}
V_130 -> V_118 = (struct V_89 * ) ( V_126 & ~ 1ul ) ;
V_130 -> V_131 = 0 ;
return V_130 -> V_118 -> V_119 [ V_130 -> V_131 ] ;
}
static T_1 * F_102 ( struct V_129 * V_130 )
{
if ( V_130 -> V_118 ) {
if ( V_130 -> V_131 < V_120 - 1 ) {
T_1 * V_13 ;
++ V_130 -> V_131 ;
V_13 = V_130 -> V_118 -> V_119 [ V_130 -> V_131 ] ;
if ( V_13 )
return V_13 ;
}
V_130 -> V_118 = V_130 -> V_118 -> V_121 ;
if ( V_130 -> V_118 ) {
V_130 -> V_131 = 0 ;
return V_130 -> V_118 -> V_119 [ V_130 -> V_131 ] ;
}
}
return NULL ;
}
static void F_103 ( struct V_11 * V_11 , T_1 * V_13 )
{
if ( F_47 ( V_13 ) )
F_100 ( V_11 , V_13 ) ;
}
static bool F_104 ( struct V_11 * V_11 , T_1 * V_13 )
{
if ( F_23 ( * V_13 ) ) {
F_3 ( F_36 ( F_37 ( V_13 ) ) -> V_91 . V_41 ==
V_42 ) ;
F_103 ( V_11 , V_13 ) ;
-- V_11 -> V_132 . V_133 ;
return true ;
}
return false ;
}
static void F_105 ( struct V_33 * V_34 , T_1 * V_13 )
{
if ( F_104 ( V_34 -> V_11 , V_13 ) )
F_106 ( V_34 -> V_11 ) ;
}
static bool F_107 ( struct V_11 * V_11 , T_1 * V_13 , bool V_134 )
{
T_1 V_10 = * V_13 ;
if ( ! F_42 ( V_10 ) &&
! ( V_134 && F_40 ( V_10 ) ) )
return false ;
F_89 ( L_9 , V_13 , * V_13 ) ;
if ( V_134 )
V_10 &= ~ V_61 ;
V_10 = V_10 & ~ V_135 ;
return F_44 ( V_13 , V_10 ) ;
}
static bool F_108 ( struct V_11 * V_11 , unsigned long * V_127 ,
bool V_134 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
bool V_136 = false ;
for ( V_13 = F_101 ( * V_127 , & V_130 ) ; V_13 ; ) {
F_71 ( ! ( * V_13 & V_39 ) ) ;
V_136 |= F_107 ( V_11 , V_13 , V_134 ) ;
V_13 = F_102 ( & V_130 ) ;
}
return V_136 ;
}
void F_109 ( struct V_11 * V_11 ,
struct V_96 * V_97 ,
T_2 V_137 , unsigned long V_4 )
{
unsigned long * V_127 ;
while ( V_4 ) {
V_127 = F_96 ( V_97 -> V_99 + V_137 + F_110 ( V_4 ) ,
V_42 , V_97 ) ;
F_108 ( V_11 , V_127 , false ) ;
V_4 &= V_4 - 1 ;
}
}
static bool F_111 ( struct V_11 * V_11 , T_1 V_14 )
{
struct V_96 * V_97 ;
unsigned long * V_127 ;
int V_102 ;
bool V_138 = false ;
V_97 = F_79 ( V_11 , V_14 ) ;
for ( V_102 = V_42 ;
V_102 < V_42 + V_104 ; ++ V_102 ) {
V_127 = F_96 ( V_14 , V_102 , V_97 ) ;
V_138 |= F_108 ( V_11 , V_127 , true ) ;
}
return V_138 ;
}
static int F_112 ( struct V_11 * V_11 , unsigned long * V_127 ,
struct V_96 * V_97 , T_2 V_14 , int V_41 ,
unsigned long V_139 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
int V_140 = 0 ;
while ( ( V_13 = F_101 ( * V_127 , & V_130 ) ) ) {
F_71 ( ! ( * V_13 & V_39 ) ) ;
F_89 ( L_10 ,
V_13 , * V_13 , V_14 , V_41 ) ;
F_103 ( V_11 , V_13 ) ;
V_140 = 1 ;
}
return V_140 ;
}
static int F_113 ( struct V_11 * V_11 , unsigned long * V_127 ,
struct V_96 * V_97 , T_2 V_14 , int V_41 ,
unsigned long V_139 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
int V_141 = 0 ;
T_1 V_63 ;
T_6 * V_142 = ( T_6 * ) V_139 ;
T_3 V_143 ;
F_3 ( F_114 ( * V_142 ) ) ;
V_143 = F_115 ( * V_142 ) ;
for ( V_13 = F_101 ( * V_127 , & V_130 ) ; V_13 ; ) {
F_71 ( ! F_22 ( * V_13 ) ) ;
F_89 ( L_11 ,
V_13 , * V_13 , V_14 , V_41 ) ;
V_141 = 1 ;
if ( F_116 ( * V_142 ) ) {
F_103 ( V_11 , V_13 ) ;
V_13 = F_101 ( * V_127 , & V_130 ) ;
} else {
V_63 = * V_13 & ~ V_43 ;
V_63 |= ( T_1 ) V_143 << V_18 ;
V_63 &= ~ V_135 ;
V_63 &= ~ V_60 ;
V_63 &= ~ V_29 ;
F_47 ( V_13 ) ;
F_9 ( V_13 , V_63 ) ;
V_13 = F_102 ( & V_130 ) ;
}
}
if ( V_141 )
F_106 ( V_11 ) ;
return 0 ;
}
static int F_117 ( struct V_11 * V_11 ,
unsigned long V_144 ,
unsigned long V_145 ,
unsigned long V_139 ,
int (* F_118)( struct V_11 * V_11 ,
unsigned long * V_127 ,
struct V_96 * V_97 ,
T_2 V_14 ,
int V_41 ,
unsigned long V_139 ) )
{
int V_123 ;
int V_65 = 0 ;
struct F_6 * V_146 ;
struct V_96 * V_147 ;
V_146 = F_6 ( V_11 ) ;
F_119 (memslot, slots) {
unsigned long V_148 , V_149 ;
T_2 V_150 , V_151 ;
V_148 = F_120 ( V_144 , V_147 -> V_152 ) ;
V_149 = V_73 ( V_145 , V_147 -> V_152 +
( V_147 -> V_153 << V_18 ) ) ;
if ( V_148 >= V_149 )
continue;
V_150 = F_121 ( V_148 , V_147 ) ;
V_151 = F_121 ( V_149 + V_154 - 1 , V_147 ) ;
for ( V_123 = V_42 ;
V_123 < V_42 + V_104 ; ++ V_123 ) {
unsigned long V_98 , V_155 ;
unsigned long * V_127 ;
T_2 V_14 = V_150 ;
V_98 = F_77 ( V_150 , V_147 -> V_99 , V_123 ) ;
V_155 = F_77 ( V_151 - 1 , V_147 -> V_99 , V_123 ) ;
V_127 = F_96 ( V_150 , V_123 , V_147 ) ;
for (; V_98 <= V_155 ;
++ V_98 , V_14 += ( 1UL << F_122 ( V_123 ) ) )
V_65 |= F_118 ( V_11 , V_127 ++ , V_147 ,
V_14 , V_123 , V_139 ) ;
}
}
return V_65 ;
}
static int F_123 ( struct V_11 * V_11 , unsigned long V_156 ,
unsigned long V_139 ,
int (* F_118)( struct V_11 * V_11 , unsigned long * V_127 ,
struct V_96 * V_97 ,
T_2 V_14 , int V_41 ,
unsigned long V_139 ) )
{
return F_117 ( V_11 , V_156 , V_156 + 1 , V_139 , F_118 ) ;
}
int F_124 ( struct V_11 * V_11 , unsigned long V_156 )
{
return F_123 ( V_11 , V_156 , 0 , F_112 ) ;
}
int F_125 ( struct V_11 * V_11 , unsigned long V_144 , unsigned long V_145 )
{
return F_117 ( V_11 , V_144 , V_145 , 0 , F_112 ) ;
}
void F_126 ( struct V_11 * V_11 , unsigned long V_156 , T_6 V_38 )
{
F_123 ( V_11 , V_156 , ( unsigned long ) & V_38 , F_113 ) ;
}
static int F_127 ( struct V_11 * V_11 , unsigned long * V_127 ,
struct V_96 * V_97 , T_2 V_14 , int V_41 ,
unsigned long V_139 )
{
T_1 * V_13 ;
struct V_129 V_157 ( V_130 ) ;
int V_158 = 0 ;
F_71 ( ! V_29 ) ;
for ( V_13 = F_101 ( * V_127 , & V_130 ) ; V_13 ;
V_13 = F_102 ( & V_130 ) ) {
F_71 ( ! F_22 ( * V_13 ) ) ;
if ( * V_13 & V_29 ) {
V_158 = 1 ;
F_128 ( ( F_129 ( V_29 ) - 1 ) ,
( unsigned long * ) V_13 ) ;
}
}
F_130 ( V_14 , V_41 , V_97 , V_158 ) ;
return V_158 ;
}
static int F_131 ( struct V_11 * V_11 , unsigned long * V_127 ,
struct V_96 * V_97 , T_2 V_14 ,
int V_41 , unsigned long V_139 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
int V_158 = 0 ;
if ( ! V_29 )
goto V_85;
for ( V_13 = F_101 ( * V_127 , & V_130 ) ; V_13 ;
V_13 = F_102 ( & V_130 ) ) {
F_71 ( ! F_22 ( * V_13 ) ) ;
if ( * V_13 & V_29 ) {
V_158 = 1 ;
break;
}
}
V_85:
return V_158 ;
}
static void F_132 ( struct V_33 * V_34 , T_1 * V_10 , T_2 V_14 )
{
unsigned long * V_127 ;
struct V_48 * V_49 ;
V_49 = F_36 ( F_37 ( V_10 ) ) ;
V_127 = F_97 ( V_34 -> V_11 , V_14 , V_49 -> V_91 . V_41 ) ;
F_112 ( V_34 -> V_11 , V_127 , NULL , V_14 , V_49 -> V_91 . V_41 , 0 ) ;
F_106 ( V_34 -> V_11 ) ;
}
int F_133 ( struct V_11 * V_11 , unsigned long V_144 , unsigned long V_145 )
{
if ( ! V_29 ) {
V_11 -> V_159 ++ ;
return F_117 ( V_11 , V_144 , V_145 , 0 ,
F_112 ) ;
}
return F_117 ( V_11 , V_144 , V_145 , 0 , F_127 ) ;
}
int F_134 ( struct V_11 * V_11 , unsigned long V_156 )
{
return F_123 ( V_11 , V_156 , 0 , F_131 ) ;
}
static int F_135 ( T_1 * V_128 )
{
T_1 * V_131 ;
T_1 * V_145 ;
for ( V_131 = V_128 , V_145 = V_131 + V_154 / sizeof( T_1 ) ; V_131 != V_145 ; V_131 ++ )
if ( F_22 ( * V_131 ) ) {
F_92 ( V_124 L_12 , V_160 ,
V_131 , * V_131 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_136 ( struct V_11 * V_11 , int V_161 )
{
V_11 -> V_35 . V_162 += V_161 ;
F_137 ( & V_163 , V_161 ) ;
}
static void F_138 ( struct V_48 * V_49 )
{
ASSERT ( F_135 ( V_49 -> V_128 ) ) ;
F_139 ( & V_49 -> V_164 ) ;
F_140 ( & V_49 -> V_165 ) ;
F_67 ( ( unsigned long ) V_49 -> V_128 ) ;
if ( ! V_49 -> V_91 . V_92 )
F_67 ( ( unsigned long ) V_49 -> V_93 ) ;
F_63 ( V_87 , V_49 ) ;
}
static unsigned F_141 ( T_2 V_14 )
{
return V_14 & ( ( 1 << V_166 ) - 1 ) ;
}
static void F_142 ( struct V_33 * V_34 ,
struct V_48 * V_49 , T_1 * V_167 )
{
if ( ! V_167 )
return;
F_88 ( V_34 , V_167 , & V_49 -> V_168 ) ;
}
static void F_143 ( struct V_48 * V_49 ,
T_1 * V_167 )
{
F_91 ( V_167 , & V_49 -> V_168 ) ;
}
static void F_144 ( struct V_48 * V_49 ,
T_1 * V_167 )
{
F_143 ( V_49 , V_167 ) ;
F_51 ( V_167 ) ;
}
static struct V_48 * F_145 ( struct V_33 * V_34 ,
T_1 * V_167 , int V_92 )
{
struct V_48 * V_49 ;
V_49 = F_70 ( & V_34 -> V_35 . V_87 ) ;
V_49 -> V_128 = F_70 ( & V_34 -> V_35 . V_86 ) ;
if ( ! V_92 )
V_49 -> V_93 = F_70 ( & V_34 -> V_35 . V_86 ) ;
F_146 ( F_147 ( V_49 -> V_128 ) , ( unsigned long ) V_49 ) ;
F_148 ( & V_49 -> V_165 , & V_34 -> V_11 -> V_35 . V_169 ) ;
V_49 -> V_168 = 0 ;
F_142 ( V_34 , V_49 , V_167 ) ;
F_136 ( V_34 -> V_11 , + 1 ) ;
return V_49 ;
}
static void F_149 ( struct V_48 * V_49 )
{
F_95 ( & V_49 -> V_168 , V_170 ) ;
}
static void V_170 ( T_1 * V_10 )
{
struct V_48 * V_49 ;
unsigned int V_90 ;
V_49 = F_36 ( F_37 ( V_10 ) ) ;
V_90 = V_10 - V_49 -> V_128 ;
if ( F_150 ( V_90 , V_49 -> V_171 ) )
return;
if ( V_49 -> V_172 ++ )
return;
F_149 ( V_49 ) ;
}
static int F_151 ( struct V_33 * V_34 ,
struct V_48 * V_49 )
{
return 1 ;
}
static void F_152 ( struct V_33 * V_34 , T_7 V_173 )
{
}
static void F_153 ( struct V_33 * V_34 ,
struct V_48 * V_49 , T_1 * V_10 ,
const void * V_38 )
{
F_3 ( 1 ) ;
}
static int F_154 ( struct V_174 * V_175 , struct V_48 * V_49 ,
int V_98 )
{
int V_102 ;
if ( V_49 -> V_176 )
for ( V_102 = 0 ; V_102 < V_175 -> V_161 ; V_102 ++ )
if ( V_175 -> V_80 [ V_102 ] . V_49 == V_49 )
return 0 ;
V_175 -> V_80 [ V_175 -> V_161 ] . V_49 = V_49 ;
V_175 -> V_80 [ V_175 -> V_161 ] . V_98 = V_98 ;
V_175 -> V_161 ++ ;
return ( V_175 -> V_161 == V_177 ) ;
}
static int F_155 ( struct V_48 * V_49 ,
struct V_174 * V_175 )
{
int V_102 , V_65 , V_178 = 0 ;
F_156 (i, sp->unsync_child_bitmap, 512 ) {
struct V_48 * V_179 ;
T_1 V_180 = V_49 -> V_128 [ V_102 ] ;
if ( ! F_22 ( V_180 ) || F_23 ( V_180 ) )
goto V_181;
V_179 = F_36 ( V_180 & V_43 ) ;
if ( V_179 -> V_172 ) {
if ( F_154 ( V_175 , V_179 , V_102 ) )
return - V_182 ;
V_65 = F_155 ( V_179 , V_175 ) ;
if ( ! V_65 )
goto V_181;
else if ( V_65 > 0 )
V_178 += V_65 ;
else
return V_65 ;
} else if ( V_179 -> V_176 ) {
V_178 ++ ;
if ( F_154 ( V_175 , V_179 , V_102 ) )
return - V_182 ;
} else
goto V_181;
continue;
V_181:
F_157 ( V_102 , V_49 -> V_171 ) ;
V_49 -> V_172 -- ;
F_3 ( ( int ) V_49 -> V_172 < 0 ) ;
}
return V_178 ;
}
static int F_158 ( struct V_48 * V_49 ,
struct V_174 * V_175 )
{
if ( ! V_49 -> V_172 )
return 0 ;
F_154 ( V_175 , V_49 , 0 ) ;
return F_155 ( V_49 , V_175 ) ;
}
static void F_159 ( struct V_11 * V_11 , struct V_48 * V_49 )
{
F_3 ( ! V_49 -> V_176 ) ;
F_160 ( V_49 ) ;
V_49 -> V_176 = 0 ;
-- V_11 -> V_132 . V_183 ;
}
static int F_161 ( struct V_33 * V_34 , struct V_48 * V_49 ,
struct V_184 * V_185 , bool V_186 )
{
if ( V_49 -> V_91 . V_187 != ! ! F_162 ( V_34 ) ) {
F_163 ( V_34 -> V_11 , V_49 , V_185 ) ;
return 1 ;
}
if ( V_186 )
F_159 ( V_34 -> V_11 , V_49 ) ;
if ( V_34 -> V_35 . V_188 . V_189 ( V_34 , V_49 ) ) {
F_163 ( V_34 -> V_11 , V_49 , V_185 ) ;
return 1 ;
}
F_164 ( V_190 , V_34 ) ;
return 0 ;
}
static int F_165 ( struct V_33 * V_34 ,
struct V_48 * V_49 )
{
F_166 ( V_185 ) ;
int V_65 ;
V_65 = F_161 ( V_34 , V_49 , & V_185 , false ) ;
if ( V_65 )
F_167 ( V_34 -> V_11 , & V_185 ) ;
return V_65 ;
}
static void F_168 ( struct V_33 * V_34 , int V_191 ) { }
static void F_169 ( void ) { }
static int F_170 ( struct V_33 * V_34 , struct V_48 * V_49 ,
struct V_184 * V_185 )
{
return F_161 ( V_34 , V_49 , V_185 , true ) ;
}
static void F_171 ( struct V_33 * V_34 , T_2 V_14 )
{
struct V_48 * V_192 ;
F_166 ( V_185 ) ;
bool V_136 = false ;
F_172 (vcpu->kvm, s, gfn) {
if ( ! V_192 -> V_176 )
continue;
F_3 ( V_192 -> V_91 . V_41 != V_42 ) ;
F_159 ( V_34 -> V_11 , V_192 ) ;
if ( ( V_192 -> V_91 . V_187 != ! ! F_162 ( V_34 ) ) ||
( V_34 -> V_35 . V_188 . V_189 ( V_34 , V_192 ) ) ) {
F_163 ( V_34 -> V_11 , V_192 , & V_185 ) ;
continue;
}
V_136 = true ;
}
F_167 ( V_34 -> V_11 , & V_185 ) ;
if ( V_136 )
F_164 ( V_190 , V_34 ) ;
}
static int F_173 ( struct V_174 * V_175 ,
struct V_193 * V_194 ,
int V_102 )
{
int V_195 ;
for ( V_195 = V_102 + 1 ; V_195 < V_175 -> V_161 ; V_195 ++ ) {
struct V_48 * V_49 = V_175 -> V_80 [ V_195 ] . V_49 ;
if ( V_49 -> V_91 . V_41 == V_42 ) {
V_194 -> V_98 [ 0 ] = V_175 -> V_80 [ V_195 ] . V_98 ;
return V_195 ;
}
V_194 -> V_196 [ V_49 -> V_91 . V_41 - 2 ] = V_49 ;
V_194 -> V_98 [ V_49 -> V_91 . V_41 - 1 ] = V_175 -> V_80 [ V_195 ] . V_98 ;
}
return V_195 ;
}
static void F_174 ( struct V_193 * V_194 )
{
struct V_48 * V_49 ;
unsigned int V_41 = 0 ;
do {
unsigned int V_98 = V_194 -> V_98 [ V_41 ] ;
V_49 = V_194 -> V_196 [ V_41 ] ;
if ( ! V_49 )
return;
-- V_49 -> V_172 ;
F_3 ( ( int ) V_49 -> V_172 < 0 ) ;
F_157 ( V_98 , V_49 -> V_171 ) ;
V_41 ++ ;
} while ( V_41 < V_197 - 1 && ! V_49 -> V_172 );
}
static void F_175 ( struct V_48 * V_196 ,
struct V_193 * V_194 ,
struct V_174 * V_175 )
{
V_194 -> V_196 [ V_196 -> V_91 . V_41 - 1 ] = NULL ;
V_175 -> V_161 = 0 ;
}
static void F_176 ( struct V_33 * V_34 ,
struct V_48 * V_196 )
{
int V_102 ;
struct V_48 * V_49 ;
struct V_193 V_194 ;
struct V_174 V_198 ;
F_166 ( V_185 ) ;
F_175 ( V_196 , & V_194 , & V_198 ) ;
while ( F_158 ( V_196 , & V_198 ) ) {
bool V_199 = false ;
F_177 (pages, sp, parents, i)
V_199 |= F_111 ( V_34 -> V_11 , V_49 -> V_14 ) ;
if ( V_199 )
F_106 ( V_34 -> V_11 ) ;
F_177 (pages, sp, parents, i) {
F_170 ( V_34 , V_49 , & V_185 ) ;
F_174 ( & V_194 ) ;
}
F_167 ( V_34 -> V_11 , & V_185 ) ;
F_178 ( & V_34 -> V_11 -> V_200 ) ;
F_175 ( V_196 , & V_194 , & V_198 ) ;
}
}
static void F_179 ( struct V_48 * V_49 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_201 ; ++ V_102 )
V_49 -> V_128 [ V_102 ] = 0ull ;
}
static void F_180 ( struct V_48 * V_49 )
{
V_49 -> V_202 = 0 ;
}
static void F_181 ( T_1 * V_10 )
{
struct V_48 * V_49 = F_36 ( F_37 ( V_10 ) ) ;
F_180 ( V_49 ) ;
}
static bool F_182 ( struct V_11 * V_11 , struct V_48 * V_49 )
{
return F_14 ( V_49 -> V_203 != V_11 -> V_35 . V_203 ) ;
}
static struct V_48 * F_183 ( struct V_33 * V_34 ,
T_2 V_14 ,
T_7 V_204 ,
unsigned V_41 ,
int V_92 ,
unsigned V_15 ,
T_1 * V_167 )
{
union V_205 V_91 ;
unsigned V_206 ;
struct V_48 * V_49 ;
bool V_207 = false ;
V_91 = V_34 -> V_35 . V_188 . V_208 ;
V_91 . V_41 = V_41 ;
V_91 . V_92 = V_92 ;
if ( V_91 . V_92 )
V_91 . V_187 = 0 ;
V_91 . V_15 = V_15 ;
if ( ! V_34 -> V_35 . V_188 . V_209
&& V_34 -> V_35 . V_188 . V_210 <= V_211 ) {
V_206 = V_204 >> ( V_18 + ( V_212 * V_41 ) ) ;
V_206 &= ( 1 << ( ( V_213 - V_212 ) * V_41 ) ) - 1 ;
V_91 . V_206 = V_206 ;
}
F_184 (vcpu->kvm, sp, gfn) {
if ( F_182 ( V_34 -> V_11 , V_49 ) )
continue;
if ( ! V_207 && V_49 -> V_176 )
V_207 = true ;
if ( V_49 -> V_91 . V_214 != V_91 . V_214 )
continue;
if ( V_49 -> V_176 && F_165 ( V_34 , V_49 ) )
break;
F_142 ( V_34 , V_49 , V_167 ) ;
if ( V_49 -> V_172 ) {
F_164 ( V_215 , V_34 ) ;
F_149 ( V_49 ) ;
} else if ( V_49 -> V_176 )
F_149 ( V_49 ) ;
F_180 ( V_49 ) ;
F_185 ( V_49 , false ) ;
return V_49 ;
}
++ V_34 -> V_11 -> V_132 . V_216 ;
V_49 = F_145 ( V_34 , V_167 , V_92 ) ;
if ( ! V_49 )
return V_49 ;
V_49 -> V_14 = V_14 ;
V_49 -> V_91 = V_91 ;
F_186 ( & V_49 -> V_164 ,
& V_34 -> V_11 -> V_35 . V_217 [ F_141 ( V_14 ) ] ) ;
if ( ! V_92 ) {
if ( F_111 ( V_34 -> V_11 , V_14 ) )
F_106 ( V_34 -> V_11 ) ;
if ( V_41 > V_42 && V_207 )
F_171 ( V_34 , V_14 ) ;
F_78 ( V_34 -> V_11 , V_14 ) ;
}
V_49 -> V_203 = V_34 -> V_11 -> V_35 . V_203 ;
F_179 ( V_49 ) ;
F_185 ( V_49 , true ) ;
return V_49 ;
}
static void F_187 ( struct V_218 * V_219 ,
struct V_33 * V_34 , T_1 V_220 )
{
V_219 -> V_220 = V_220 ;
V_219 -> V_221 = V_34 -> V_35 . V_188 . V_222 ;
V_219 -> V_41 = V_34 -> V_35 . V_188 . V_223 ;
if ( V_219 -> V_41 == V_197 &&
V_34 -> V_35 . V_188 . V_210 < V_197 &&
! V_34 -> V_35 . V_188 . V_209 )
-- V_219 -> V_41 ;
if ( V_219 -> V_41 == V_224 ) {
V_219 -> V_221
= V_34 -> V_35 . V_188 . V_225 [ ( V_220 >> 30 ) & 3 ] ;
V_219 -> V_221 &= V_43 ;
-- V_219 -> V_41 ;
if ( ! V_219 -> V_221 )
V_219 -> V_41 = 0 ;
}
}
static bool F_188 ( struct V_218 * V_219 )
{
if ( V_219 -> V_41 < V_42 )
return false ;
V_219 -> V_90 = F_189 ( V_219 -> V_220 , V_219 -> V_41 ) ;
V_219 -> V_13 = ( ( T_1 * ) F_190 ( V_219 -> V_221 ) ) + V_219 -> V_90 ;
return true ;
}
static void F_191 ( struct V_218 * V_219 ,
T_1 V_10 )
{
if ( F_25 ( V_10 , V_219 -> V_41 ) ) {
V_219 -> V_41 = 0 ;
return;
}
V_219 -> V_221 = V_10 & V_43 ;
-- V_219 -> V_41 ;
}
static void F_192 ( struct V_218 * V_219 )
{
return F_191 ( V_219 , * V_219 -> V_13 ) ;
}
static void F_193 ( T_1 * V_13 , struct V_48 * V_49 , bool V_226 )
{
T_1 V_10 ;
F_194 ( V_227 != V_39 ||
V_228 != V_135 ) ;
V_10 = F_37 ( V_49 -> V_128 ) | V_39 | V_135 |
V_28 | V_32 ;
if ( V_226 )
V_10 |= V_29 ;
F_9 ( V_13 , V_10 ) ;
}
static void F_195 ( struct V_33 * V_34 , T_1 * V_13 ,
unsigned V_229 )
{
if ( F_22 ( * V_13 ) && ! F_23 ( * V_13 ) ) {
struct V_48 * V_179 ;
V_179 = F_36 ( * V_13 & V_43 ) ;
if ( V_179 -> V_91 . V_15 == V_229 )
return;
F_144 ( V_179 , V_13 ) ;
F_106 ( V_34 -> V_11 ) ;
}
}
static bool F_196 ( struct V_11 * V_11 , struct V_48 * V_49 ,
T_1 * V_10 )
{
T_1 V_38 ;
struct V_48 * V_179 ;
V_38 = * V_10 ;
if ( F_22 ( V_38 ) ) {
if ( F_25 ( V_38 , V_49 -> V_91 . V_41 ) ) {
F_103 ( V_11 , V_10 ) ;
if ( F_23 ( V_38 ) )
-- V_11 -> V_132 . V_133 ;
} else {
V_179 = F_36 ( V_38 & V_43 ) ;
F_144 ( V_179 , V_10 ) ;
}
return true ;
}
if ( F_10 ( V_38 ) )
F_51 ( V_10 ) ;
return false ;
}
static void F_197 ( struct V_11 * V_11 ,
struct V_48 * V_49 )
{
unsigned V_102 ;
for ( V_102 = 0 ; V_102 < V_201 ; ++ V_102 )
F_196 ( V_11 , V_49 , V_49 -> V_128 + V_102 ) ;
}
static void F_198 ( struct V_48 * V_49 , T_1 * V_167 )
{
F_143 ( V_49 , V_167 ) ;
}
static void F_199 ( struct V_11 * V_11 , struct V_48 * V_49 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
while ( ( V_13 = F_101 ( V_49 -> V_168 , & V_130 ) ) )
F_144 ( V_49 , V_13 ) ;
}
static int F_200 ( struct V_11 * V_11 ,
struct V_48 * V_196 ,
struct V_184 * V_185 )
{
int V_102 , V_230 = 0 ;
struct V_193 V_194 ;
struct V_174 V_198 ;
if ( V_196 -> V_91 . V_41 == V_42 )
return 0 ;
F_175 ( V_196 , & V_194 , & V_198 ) ;
while ( F_158 ( V_196 , & V_198 ) ) {
struct V_48 * V_49 ;
F_177 (pages, sp, parents, i) {
F_163 ( V_11 , V_49 , V_185 ) ;
F_174 ( & V_194 ) ;
V_230 ++ ;
}
F_175 ( V_196 , & V_194 , & V_198 ) ;
}
return V_230 ;
}
static int F_163 ( struct V_11 * V_11 , struct V_48 * V_49 ,
struct V_184 * V_185 )
{
int V_65 ;
F_201 ( V_49 ) ;
++ V_11 -> V_132 . V_231 ;
V_65 = F_200 ( V_11 , V_49 , V_185 ) ;
F_197 ( V_11 , V_49 ) ;
F_199 ( V_11 , V_49 ) ;
if ( ! V_49 -> V_91 . V_232 && ! V_49 -> V_91 . V_92 )
F_80 ( V_11 , V_49 -> V_14 ) ;
if ( V_49 -> V_176 )
F_159 ( V_11 , V_49 ) ;
if ( ! V_49 -> V_233 ) {
V_65 ++ ;
F_202 ( & V_49 -> V_165 , V_185 ) ;
F_136 ( V_11 , - 1 ) ;
} else {
F_202 ( & V_49 -> V_165 , & V_11 -> V_35 . V_169 ) ;
if ( ! V_49 -> V_91 . V_232 && ! F_182 ( V_11 , V_49 ) )
F_203 ( V_11 ) ;
}
V_49 -> V_91 . V_232 = 1 ;
return V_65 ;
}
static void F_167 ( struct V_11 * V_11 ,
struct V_184 * V_185 )
{
struct V_48 * V_49 , * V_234 ;
if ( F_204 ( V_185 ) )
return;
F_55 () ;
F_106 ( V_11 ) ;
F_205 (sp, nsp, invalid_list, link) {
F_3 ( ! V_49 -> V_91 . V_232 || V_49 -> V_233 ) ;
F_138 ( V_49 ) ;
}
}
static bool F_206 ( struct V_11 * V_11 ,
struct V_184 * V_185 )
{
struct V_48 * V_49 ;
if ( F_204 ( & V_11 -> V_35 . V_169 ) )
return false ;
V_49 = F_207 ( V_11 -> V_35 . V_169 . V_235 ,
struct V_48 , V_165 ) ;
F_163 ( V_11 , V_49 , V_185 ) ;
return true ;
}
void F_208 ( struct V_11 * V_11 , unsigned int V_236 )
{
F_166 ( V_185 ) ;
F_209 ( & V_11 -> V_200 ) ;
if ( V_11 -> V_35 . V_162 > V_236 ) {
while ( V_11 -> V_35 . V_162 > V_236 )
if ( ! F_206 ( V_11 , & V_185 ) )
break;
F_167 ( V_11 , & V_185 ) ;
V_236 = V_11 -> V_35 . V_162 ;
}
V_11 -> V_35 . V_237 = V_236 ;
F_210 ( & V_11 -> V_200 ) ;
}
int F_211 ( struct V_11 * V_11 , T_2 V_14 )
{
struct V_48 * V_49 ;
F_166 ( V_185 ) ;
int V_81 ;
F_212 ( L_13 , V_160 , V_14 ) ;
V_81 = 0 ;
F_209 ( & V_11 -> V_200 ) ;
F_172 (kvm, sp, gfn) {
F_212 ( L_14 , V_160 , V_14 ,
V_49 -> V_91 . V_214 ) ;
V_81 = 1 ;
F_163 ( V_11 , V_49 , & V_185 ) ;
}
F_167 ( V_11 , & V_185 ) ;
F_210 ( & V_11 -> V_200 ) ;
return V_81 ;
}
static int F_213 ( struct V_238 * V_239 ,
T_1 V_144 , T_1 V_145 )
{
int V_102 ;
T_1 V_240 , V_4 ;
T_8 V_241 , V_242 ;
int V_243 = V_244 ;
if ( ! V_239 -> V_245 )
return 0xFF ;
V_145 -- ;
if ( V_239 -> V_246 && ( V_144 < 0x100000 ) ) {
int V_98 ;
if ( V_144 < 0x80000 ) {
V_98 = 0 ;
V_98 += ( V_144 >> 16 ) ;
return V_239 -> V_247 [ V_98 ] ;
} else if ( V_144 < 0xC0000 ) {
V_98 = 1 * 8 ;
V_98 += ( ( V_144 - 0x80000 ) >> 14 ) ;
return V_239 -> V_247 [ V_98 ] ;
} else if ( V_144 < 0x1000000 ) {
V_98 = 3 * 8 ;
V_98 += ( ( V_144 - 0xC0000 ) >> 12 ) ;
return V_239 -> V_247 [ V_98 ] ;
}
}
if ( ! ( V_239 -> V_245 & 2 ) )
return V_239 -> V_248 ;
V_241 = 0xFF ;
for ( V_102 = 0 ; V_102 < V_243 ; ++ V_102 ) {
unsigned short V_249 , V_250 ;
if ( ! ( V_239 -> V_251 [ V_102 ] . V_252 & ( 1 << 11 ) ) )
continue;
V_240 = ( ( ( T_1 ) V_239 -> V_251 [ V_102 ] . V_253 ) << 32 ) +
( V_239 -> V_251 [ V_102 ] . V_254 & V_19 ) ;
V_4 = ( ( ( T_1 ) V_239 -> V_251 [ V_102 ] . V_255 ) << 32 ) +
( V_239 -> V_251 [ V_102 ] . V_252 & V_19 ) ;
V_249 = ( ( V_144 & V_4 ) == ( V_240 & V_4 ) ) ;
V_250 = ( ( V_145 & V_4 ) == ( V_240 & V_4 ) ) ;
if ( V_249 != V_250 )
return 0xFE ;
if ( ( V_144 & V_4 ) != ( V_240 & V_4 ) )
continue;
V_242 = V_239 -> V_251 [ V_102 ] . V_254 & 0xff ;
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
T_8 F_214 ( struct V_33 * V_34 , T_2 V_14 )
{
T_8 V_259 ;
V_259 = F_213 ( & V_34 -> V_35 . V_239 , V_14 << V_18 ,
( V_14 << V_18 ) + V_154 ) ;
if ( V_259 == 0xfe || V_259 == 0xff )
V_259 = V_257 ;
return V_259 ;
}
static void F_215 ( struct V_33 * V_34 , struct V_48 * V_49 )
{
F_216 ( V_49 ) ;
++ V_34 -> V_11 -> V_132 . V_183 ;
V_49 -> V_176 = 1 ;
F_149 ( V_49 ) ;
}
static void F_217 ( struct V_33 * V_34 , T_2 V_14 )
{
struct V_48 * V_192 ;
F_172 (vcpu->kvm, s, gfn) {
if ( V_192 -> V_176 )
continue;
F_3 ( V_192 -> V_91 . V_41 != V_42 ) ;
F_215 ( V_34 , V_192 ) ;
}
}
static int F_218 ( struct V_33 * V_34 , T_2 V_14 ,
bool V_260 )
{
struct V_48 * V_192 ;
bool V_261 = false ;
F_172 (vcpu->kvm, s, gfn) {
if ( ! V_260 )
return 1 ;
if ( V_192 -> V_91 . V_41 != V_42 )
return 1 ;
if ( ! V_192 -> V_176 )
V_261 = true ;
}
if ( V_261 )
F_217 ( V_34 , V_14 ) ;
return 0 ;
}
static int F_219 ( struct V_33 * V_34 , T_1 * V_13 ,
unsigned V_262 , int V_41 ,
T_2 V_14 , T_3 V_20 , bool V_263 ,
bool V_260 , bool V_264 )
{
T_1 V_10 ;
int V_65 = 0 ;
if ( F_13 ( V_34 -> V_11 , V_13 , V_14 , V_20 , V_262 ) )
return 0 ;
V_10 = V_39 ;
if ( ! V_263 )
V_10 |= V_29 ;
if ( V_262 & V_265 )
V_10 |= V_32 ;
else
V_10 |= V_31 ;
if ( V_262 & V_17 )
V_10 |= V_28 ;
if ( V_41 > V_42 )
V_10 |= V_40 ;
if ( V_266 )
V_10 |= V_115 -> V_267 ( V_34 , V_14 ,
F_48 ( V_20 ) ) ;
if ( V_264 )
V_10 |= V_60 ;
else
V_262 &= ~ V_16 ;
V_10 |= ( T_1 ) V_20 << V_18 ;
if ( V_262 & V_16 ) {
if ( V_41 > V_42 &&
F_81 ( V_34 -> V_11 , V_14 , V_41 ) )
goto V_268;
V_10 |= V_135 | V_61 ;
if ( ! V_260 && F_42 ( * V_13 ) )
goto V_269;
if ( F_218 ( V_34 , V_14 , V_260 ) ) {
F_212 ( L_15 ,
V_160 , V_14 ) ;
V_65 = 1 ;
V_262 &= ~ V_16 ;
V_10 &= ~ ( V_135 | V_61 ) ;
}
}
if ( V_262 & V_16 )
F_220 ( V_34 -> V_11 , V_14 ) ;
V_269:
if ( F_44 ( V_13 , V_10 ) )
F_106 ( V_34 -> V_11 ) ;
V_268:
return V_65 ;
}
static void F_221 ( struct V_33 * V_34 , T_1 * V_13 ,
unsigned V_262 , int V_270 , int * V_271 ,
int V_41 , T_2 V_14 , T_3 V_20 , bool V_263 ,
bool V_264 )
{
int V_272 = 0 ;
int V_273 ;
F_212 ( L_16 , V_160 ,
* V_13 , V_270 , V_14 ) ;
if ( F_24 ( * V_13 ) ) {
if ( V_41 > V_42 &&
! F_23 ( * V_13 ) ) {
struct V_48 * V_179 ;
T_1 V_38 = * V_13 ;
V_179 = F_36 ( V_38 & V_43 ) ;
F_144 ( V_179 , V_13 ) ;
F_106 ( V_34 -> V_11 ) ;
} else if ( V_20 != F_26 ( * V_13 ) ) {
F_212 ( L_17 ,
F_26 ( * V_13 ) , V_20 ) ;
F_103 ( V_34 -> V_11 , V_13 ) ;
F_106 ( V_34 -> V_11 ) ;
} else
V_272 = 1 ;
}
if ( F_219 ( V_34 , V_13 , V_262 , V_41 , V_14 , V_20 , V_263 ,
true , V_264 ) ) {
if ( V_270 )
* V_271 = 1 ;
F_164 ( V_190 , V_34 ) ;
}
if ( F_14 ( F_10 ( * V_13 ) && V_271 ) )
* V_271 = 1 ;
F_212 ( L_18 , V_160 , * V_13 ) ;
F_212 ( L_19 ,
F_23 ( * V_13 ) ? L_20 : L_21 ,
* V_13 & V_39 ? L_22 : L_23 , V_14 ,
* V_13 , V_13 ) ;
if ( ! V_272 && F_23 ( * V_13 ) )
++ V_34 -> V_11 -> V_132 . V_133 ;
if ( F_22 ( * V_13 ) ) {
if ( ! V_272 ) {
V_273 = F_99 ( V_34 , V_13 , V_14 ) ;
if ( V_273 > V_274 )
F_132 ( V_34 , V_13 , V_14 ) ;
}
}
F_222 ( V_20 ) ;
}
static T_3 F_223 ( struct V_33 * V_34 , T_2 V_14 ,
bool V_108 )
{
struct V_96 * V_97 ;
V_97 = F_85 ( V_34 , V_14 , V_108 ) ;
if ( ! V_97 )
return V_275 ;
return F_224 ( V_97 , V_14 ) ;
}
static int F_225 ( struct V_33 * V_34 ,
struct V_48 * V_49 ,
T_1 * V_144 , T_1 * V_145 )
{
struct V_80 * V_198 [ V_84 ] ;
unsigned V_15 = V_49 -> V_91 . V_15 ;
int V_102 , V_65 ;
T_2 V_14 ;
V_14 = F_74 ( V_49 , V_144 - V_49 -> V_128 ) ;
if ( ! F_85 ( V_34 , V_14 , V_15 & V_16 ) )
return - 1 ;
V_65 = F_226 ( V_34 -> V_11 , V_14 , V_198 , V_145 - V_144 ) ;
if ( V_65 <= 0 )
return - 1 ;
for ( V_102 = 0 ; V_102 < V_65 ; V_102 ++ , V_14 ++ , V_144 ++ )
F_221 ( V_34 , V_144 , V_15 , 0 , NULL ,
V_49 -> V_91 . V_41 , V_14 , F_227 ( V_198 [ V_102 ] ) ,
true , true ) ;
return 0 ;
}
static void F_228 ( struct V_33 * V_34 ,
struct V_48 * V_49 , T_1 * V_13 )
{
T_1 * V_10 , * V_144 = NULL ;
int V_102 ;
F_3 ( ! V_49 -> V_91 . V_92 ) ;
V_102 = ( V_13 - V_49 -> V_128 ) & ~ ( V_84 - 1 ) ;
V_10 = V_49 -> V_128 + V_102 ;
for ( V_102 = 0 ; V_102 < V_84 ; V_102 ++ , V_10 ++ ) {
if ( F_22 ( * V_10 ) || V_10 == V_13 ) {
if ( ! V_144 )
continue;
if ( F_225 ( V_34 , V_49 , V_144 , V_10 ) < 0 )
break;
V_144 = NULL ;
} else if ( ! V_144 )
V_144 = V_10 ;
}
}
static void F_229 ( struct V_33 * V_34 , T_1 * V_13 )
{
struct V_48 * V_49 ;
if ( ! V_29 )
return;
V_49 = F_36 ( F_37 ( V_13 ) ) ;
if ( V_49 -> V_91 . V_41 > V_42 )
return;
F_228 ( V_34 , V_49 , V_13 ) ;
}
static int F_230 ( struct V_33 * V_34 , T_9 V_276 , int V_277 ,
int V_278 , int V_41 , T_2 V_14 , T_3 V_20 ,
bool V_279 )
{
struct V_218 V_219 ;
struct V_48 * V_49 ;
int V_271 = 0 ;
T_2 V_280 ;
if ( ! F_231 ( V_34 -> V_35 . V_188 . V_222 ) )
return 0 ;
F_232 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_219 . V_41 == V_41 ) {
F_221 ( V_34 , V_219 . V_13 , V_281 ,
V_277 , & V_271 , V_41 , V_14 , V_20 ,
V_279 , V_278 ) ;
F_229 ( V_34 , V_219 . V_13 ) ;
++ V_34 -> V_132 . V_282 ;
break;
}
F_105 ( V_34 , V_219 . V_13 ) ;
if ( ! F_22 ( * V_219 . V_13 ) ) {
T_1 V_283 = V_219 . V_220 ;
V_283 &= F_233 ( V_219 . V_41 ) ;
V_280 = V_283 >> V_18 ;
V_49 = F_183 ( V_34 , V_280 , V_219 . V_220 ,
V_219 . V_41 - 1 ,
1 , V_281 , V_219 . V_13 ) ;
F_193 ( V_219 . V_13 , V_49 , true ) ;
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
V_287 . V_295 = V_18 ;
F_235 ( V_289 , & V_287 , V_286 ) ;
}
static int F_236 ( struct V_33 * V_34 , T_2 V_14 , T_3 V_20 )
{
if ( V_20 == V_296 )
return 1 ;
if ( V_20 == V_297 ) {
F_234 ( F_237 ( V_34 -> V_11 , V_14 ) , V_298 ) ;
return 0 ;
}
return - V_299 ;
}
static void F_238 ( struct V_33 * V_34 ,
T_2 * V_300 , T_3 * V_301 , int * V_302 )
{
T_3 V_20 = * V_301 ;
T_2 V_14 = * V_300 ;
int V_41 = * V_302 ;
if ( ! F_239 ( V_20 ) && ! F_48 ( V_20 ) &&
V_41 == V_42 &&
F_240 ( F_50 ( V_20 ) ) &&
! F_81 ( V_34 -> V_11 , V_14 , V_103 ) ) {
unsigned long V_4 ;
* V_302 = V_41 = V_103 ;
V_4 = F_241 ( V_41 ) - 1 ;
F_242 ( ( V_14 & V_4 ) != ( V_20 & V_4 ) ) ;
if ( V_20 & V_4 ) {
V_14 &= ~ V_4 ;
* V_300 = V_14 ;
F_222 ( V_20 ) ;
V_20 &= ~ V_4 ;
F_243 ( V_20 ) ;
* V_301 = V_20 ;
}
}
}
static bool F_244 ( struct V_33 * V_34 , T_7 V_173 , T_2 V_14 ,
T_3 V_20 , unsigned V_15 , int * V_303 )
{
bool V_65 = true ;
if ( F_14 ( F_245 ( V_20 ) ) ) {
* V_303 = F_236 ( V_34 , V_14 , V_20 ) ;
goto exit;
}
if ( F_14 ( F_15 ( V_20 ) ) )
F_246 ( V_34 , V_173 , V_14 , V_15 ) ;
V_65 = false ;
exit:
return V_65 ;
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
F_248 ( struct V_33 * V_34 , struct V_48 * V_49 ,
T_1 * V_13 , T_1 V_10 )
{
T_2 V_14 ;
F_3 ( ! V_49 -> V_91 . V_92 ) ;
V_14 = F_74 ( V_49 , V_13 - V_49 -> V_128 ) ;
if ( F_249 ( V_13 , V_10 , V_10 | V_135 ) == V_10 )
F_220 ( V_34 -> V_11 , V_14 ) ;
return true ;
}
static bool F_250 ( struct V_33 * V_34 , T_7 V_173 , int V_41 ,
T_4 V_304 )
{
struct V_218 V_219 ;
struct V_48 * V_49 ;
bool V_65 = false ;
T_1 V_10 = 0ull ;
if ( ! F_231 ( V_34 -> V_35 . V_188 . V_222 ) )
return false ;
if ( ! F_247 ( V_304 ) )
return false ;
F_53 ( V_34 ) ;
F_251 (vcpu, gva, iterator, spte)
if ( ! F_22 ( V_10 ) || V_219 . V_41 < V_41 )
break;
if ( ! F_24 ( V_10 ) ) {
V_65 = true ;
goto exit;
}
V_49 = F_36 ( F_37 ( V_219 . V_13 ) ) ;
if ( ! F_25 ( V_10 , V_49 -> V_91 . V_41 ) )
goto exit;
if ( F_42 ( V_10 ) ) {
V_65 = true ;
goto exit;
}
if ( ! F_40 ( V_10 ) )
goto exit;
if ( V_49 -> V_91 . V_41 > V_42 )
goto exit;
V_65 = F_248 ( V_34 , V_49 , V_219 . V_13 , V_10 ) ;
exit:
F_252 ( V_34 , V_173 , V_304 , V_219 . V_13 ,
V_10 , V_65 ) ;
F_56 ( V_34 ) ;
return V_65 ;
}
static int F_253 ( struct V_33 * V_34 , T_7 V_276 , T_4 V_304 ,
T_2 V_14 , bool V_279 )
{
int V_81 ;
int V_41 ;
int V_308 ;
T_3 V_20 ;
unsigned long V_309 ;
bool V_278 , V_277 = V_304 & V_307 ;
V_308 = F_86 ( V_34 , V_14 ) ;
if ( F_18 ( ! V_308 ) ) {
V_41 = F_87 ( V_34 , V_14 ) ;
if ( V_41 > V_103 )
V_41 = V_103 ;
V_14 &= ~ ( F_241 ( V_41 ) - 1 ) ;
} else
V_41 = V_42 ;
if ( F_250 ( V_34 , V_276 , V_41 , V_304 ) )
return 0 ;
V_309 = V_34 -> V_11 -> V_159 ;
F_39 () ;
if ( F_254 ( V_34 , V_279 , V_14 , V_276 , & V_20 , V_277 , & V_278 ) )
return 0 ;
if ( F_244 ( V_34 , V_276 , V_14 , V_20 , V_281 , & V_81 ) )
return V_81 ;
F_209 ( & V_34 -> V_11 -> V_200 ) ;
if ( F_255 ( V_34 -> V_11 , V_309 ) )
goto V_310;
F_256 ( V_34 ) ;
if ( F_18 ( ! V_308 ) )
F_238 ( V_34 , & V_14 , & V_20 , & V_41 ) ;
V_81 = F_230 ( V_34 , V_276 , V_277 , V_278 , V_41 , V_14 , V_20 ,
V_279 ) ;
F_210 ( & V_34 -> V_11 -> V_200 ) ;
return V_81 ;
V_310:
F_210 ( & V_34 -> V_11 -> V_200 ) ;
F_222 ( V_20 ) ;
return 0 ;
}
static void F_257 ( struct V_33 * V_34 )
{
int V_102 ;
struct V_48 * V_49 ;
F_166 ( V_185 ) ;
if ( ! F_231 ( V_34 -> V_35 . V_188 . V_222 ) )
return;
if ( V_34 -> V_35 . V_188 . V_223 == V_197 &&
( V_34 -> V_35 . V_188 . V_210 == V_197 ||
V_34 -> V_35 . V_188 . V_209 ) ) {
T_11 V_311 = V_34 -> V_35 . V_188 . V_222 ;
F_209 ( & V_34 -> V_11 -> V_200 ) ;
V_49 = F_36 ( V_311 ) ;
-- V_49 -> V_233 ;
if ( ! V_49 -> V_233 && V_49 -> V_91 . V_232 ) {
F_163 ( V_34 -> V_11 , V_49 , & V_185 ) ;
F_167 ( V_34 -> V_11 , & V_185 ) ;
}
F_210 ( & V_34 -> V_11 -> V_200 ) ;
V_34 -> V_35 . V_188 . V_222 = V_312 ;
return;
}
F_209 ( & V_34 -> V_11 -> V_200 ) ;
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_11 V_311 = V_34 -> V_35 . V_188 . V_225 [ V_102 ] ;
if ( V_311 ) {
V_311 &= V_43 ;
V_49 = F_36 ( V_311 ) ;
-- V_49 -> V_233 ;
if ( ! V_49 -> V_233 && V_49 -> V_91 . V_232 )
F_163 ( V_34 -> V_11 , V_49 ,
& V_185 ) ;
}
V_34 -> V_35 . V_188 . V_225 [ V_102 ] = V_312 ;
}
F_167 ( V_34 -> V_11 , & V_185 ) ;
F_210 ( & V_34 -> V_11 -> V_200 ) ;
V_34 -> V_35 . V_188 . V_222 = V_312 ;
}
static int F_258 ( struct V_33 * V_34 , T_2 V_313 )
{
int V_65 = 0 ;
if ( ! F_259 ( V_34 -> V_11 , V_313 ) ) {
F_164 ( V_314 , V_34 ) ;
V_65 = 1 ;
}
return V_65 ;
}
static int F_260 ( struct V_33 * V_34 )
{
struct V_48 * V_49 ;
unsigned V_102 ;
if ( V_34 -> V_35 . V_188 . V_223 == V_197 ) {
F_209 ( & V_34 -> V_11 -> V_200 ) ;
F_256 ( V_34 ) ;
V_49 = F_183 ( V_34 , 0 , 0 , V_197 ,
1 , V_281 , NULL ) ;
++ V_49 -> V_233 ;
F_210 ( & V_34 -> V_11 -> V_200 ) ;
V_34 -> V_35 . V_188 . V_222 = F_37 ( V_49 -> V_128 ) ;
} else if ( V_34 -> V_35 . V_188 . V_223 == V_224 ) {
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_11 V_311 = V_34 -> V_35 . V_188 . V_225 [ V_102 ] ;
ASSERT ( ! F_231 ( V_311 ) ) ;
F_209 ( & V_34 -> V_11 -> V_200 ) ;
F_256 ( V_34 ) ;
V_49 = F_183 ( V_34 , V_102 << ( 30 - V_18 ) ,
V_102 << 30 ,
V_211 , 1 , V_281 ,
NULL ) ;
V_311 = F_37 ( V_49 -> V_128 ) ;
++ V_49 -> V_233 ;
F_210 ( & V_34 -> V_11 -> V_200 ) ;
V_34 -> V_35 . V_188 . V_225 [ V_102 ] = V_311 | V_39 ;
}
V_34 -> V_35 . V_188 . V_222 = F_37 ( V_34 -> V_35 . V_188 . V_225 ) ;
} else
F_93 () ;
return 0 ;
}
static int F_261 ( struct V_33 * V_34 )
{
struct V_48 * V_49 ;
T_1 V_315 , V_316 ;
T_2 V_313 ;
int V_102 ;
V_313 = V_34 -> V_35 . V_188 . V_317 ( V_34 ) >> V_18 ;
if ( F_258 ( V_34 , V_313 ) )
return 1 ;
if ( V_34 -> V_35 . V_188 . V_210 == V_197 ) {
T_11 V_311 = V_34 -> V_35 . V_188 . V_222 ;
ASSERT ( ! F_231 ( V_311 ) ) ;
F_209 ( & V_34 -> V_11 -> V_200 ) ;
F_256 ( V_34 ) ;
V_49 = F_183 ( V_34 , V_313 , 0 , V_197 ,
0 , V_281 , NULL ) ;
V_311 = F_37 ( V_49 -> V_128 ) ;
++ V_49 -> V_233 ;
F_210 ( & V_34 -> V_11 -> V_200 ) ;
V_34 -> V_35 . V_188 . V_222 = V_311 ;
return 0 ;
}
V_316 = V_39 ;
if ( V_34 -> V_35 . V_188 . V_223 == V_197 )
V_316 |= V_318 | V_135 | V_319 ;
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_11 V_311 = V_34 -> V_35 . V_188 . V_225 [ V_102 ] ;
ASSERT ( ! F_231 ( V_311 ) ) ;
if ( V_34 -> V_35 . V_188 . V_210 == V_224 ) {
V_315 = V_34 -> V_35 . V_188 . V_320 ( V_34 , V_102 ) ;
if ( ! F_262 ( V_315 ) ) {
V_34 -> V_35 . V_188 . V_225 [ V_102 ] = 0 ;
continue;
}
V_313 = V_315 >> V_18 ;
if ( F_258 ( V_34 , V_313 ) )
return 1 ;
}
F_209 ( & V_34 -> V_11 -> V_200 ) ;
F_256 ( V_34 ) ;
V_49 = F_183 ( V_34 , V_313 , V_102 << 30 ,
V_211 , 0 ,
V_281 , NULL ) ;
V_311 = F_37 ( V_49 -> V_128 ) ;
++ V_49 -> V_233 ;
F_210 ( & V_34 -> V_11 -> V_200 ) ;
V_34 -> V_35 . V_188 . V_225 [ V_102 ] = V_311 | V_316 ;
}
V_34 -> V_35 . V_188 . V_222 = F_37 ( V_34 -> V_35 . V_188 . V_225 ) ;
if ( V_34 -> V_35 . V_188 . V_223 == V_197 ) {
if ( V_34 -> V_35 . V_188 . V_321 == NULL ) {
T_1 * V_321 ;
V_321 = ( void * ) F_263 ( V_77 ) ;
if ( V_321 == NULL )
return 1 ;
V_321 [ 0 ] = F_37 ( V_34 -> V_35 . V_188 . V_225 ) | V_316 ;
V_34 -> V_35 . V_188 . V_321 = V_321 ;
}
V_34 -> V_35 . V_188 . V_222 = F_37 ( V_34 -> V_35 . V_188 . V_321 ) ;
}
return 0 ;
}
static int F_264 ( struct V_33 * V_34 )
{
if ( V_34 -> V_35 . V_188 . V_209 )
return F_260 ( V_34 ) ;
else
return F_261 ( V_34 ) ;
}
static void F_265 ( struct V_33 * V_34 )
{
int V_102 ;
struct V_48 * V_49 ;
if ( V_34 -> V_35 . V_188 . V_209 )
return;
if ( ! F_231 ( V_34 -> V_35 . V_188 . V_222 ) )
return;
F_266 ( V_34 , V_322 ) ;
F_168 ( V_34 , V_323 ) ;
if ( V_34 -> V_35 . V_188 . V_210 == V_197 ) {
T_11 V_311 = V_34 -> V_35 . V_188 . V_222 ;
V_49 = F_36 ( V_311 ) ;
F_176 ( V_34 , V_49 ) ;
F_168 ( V_34 , V_324 ) ;
return;
}
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_11 V_311 = V_34 -> V_35 . V_188 . V_225 [ V_102 ] ;
if ( V_311 && F_231 ( V_311 ) ) {
V_311 &= V_43 ;
V_49 = F_36 ( V_311 ) ;
F_176 ( V_34 , V_49 ) ;
}
}
F_168 ( V_34 , V_324 ) ;
}
void F_267 ( struct V_33 * V_34 )
{
F_209 ( & V_34 -> V_11 -> V_200 ) ;
F_265 ( V_34 ) ;
F_210 ( & V_34 -> V_11 -> V_200 ) ;
}
static T_9 F_268 ( struct V_33 * V_34 , T_7 V_325 ,
T_4 V_15 , struct V_326 * V_327 )
{
if ( V_327 )
V_327 -> V_304 = 0 ;
return V_325 ;
}
static T_9 F_269 ( struct V_33 * V_34 , T_7 V_325 ,
T_4 V_15 ,
struct V_326 * V_327 )
{
if ( V_327 )
V_327 -> V_304 = 0 ;
return V_34 -> V_35 . V_328 . V_329 ( V_34 , V_325 , V_15 , V_327 ) ;
}
static bool F_270 ( struct V_33 * V_34 , T_1 V_220 , bool V_92 )
{
if ( V_92 )
return F_271 ( V_34 , V_220 ) ;
return F_272 ( V_34 , V_220 ) ;
}
static bool F_273 ( T_1 V_10 )
{
return F_34 ( V_10 ) ;
}
static T_1 F_274 ( struct V_33 * V_34 , T_1 V_220 )
{
struct V_218 V_219 ;
T_1 V_10 = 0ull ;
if ( ! F_231 ( V_34 -> V_35 . V_188 . V_222 ) )
return V_10 ;
F_53 ( V_34 ) ;
F_251 (vcpu, addr, iterator, spte)
if ( ! F_22 ( V_10 ) )
break;
F_56 ( V_34 ) ;
return V_10 ;
}
int F_275 ( struct V_33 * V_34 , T_1 V_220 , bool V_92 )
{
T_1 V_10 ;
if ( F_270 ( V_34 , V_220 , V_92 ) )
return V_330 ;
V_10 = F_274 ( V_34 , V_220 ) ;
if ( F_10 ( V_10 ) ) {
T_2 V_14 = F_11 ( V_10 ) ;
unsigned V_15 = F_12 ( V_10 ) ;
if ( ! F_16 ( V_34 -> V_11 , V_10 ) )
return V_331 ;
if ( V_92 )
V_220 = 0 ;
F_276 ( V_220 , V_14 , V_15 ) ;
F_246 ( V_34 , V_220 , V_14 , V_15 ) ;
return V_330 ;
}
if ( V_92 && ! F_273 ( V_10 ) )
return V_332 ;
return V_333 ;
}
static int F_277 ( struct V_33 * V_34 , T_1 V_220 ,
T_4 V_304 , bool V_92 )
{
int V_65 ;
V_65 = F_275 ( V_34 , V_220 , V_92 ) ;
F_3 ( V_65 == V_332 ) ;
return V_65 ;
}
static int F_278 ( struct V_33 * V_34 , T_7 V_173 ,
T_4 V_304 , bool V_279 )
{
T_2 V_14 ;
int V_81 ;
F_212 ( L_24 , V_160 , V_173 , V_304 ) ;
if ( F_14 ( V_304 & V_305 ) ) {
V_81 = F_277 ( V_34 , V_173 , V_304 , true ) ;
if ( F_18 ( V_81 != V_331 ) )
return V_81 ;
}
V_81 = F_68 ( V_34 ) ;
if ( V_81 )
return V_81 ;
ASSERT ( V_34 ) ;
ASSERT ( F_231 ( V_34 -> V_35 . V_188 . V_222 ) ) ;
V_14 = V_173 >> V_18 ;
return F_253 ( V_34 , V_173 & V_19 ,
V_304 , V_14 , V_279 ) ;
}
static int F_279 ( struct V_33 * V_34 , T_7 V_173 , T_2 V_14 )
{
struct V_334 V_35 ;
V_35 . V_335 = ( V_34 -> V_35 . V_336 . V_337 ++ << 12 ) | V_34 -> V_338 ;
V_35 . V_14 = V_14 ;
V_35 . V_209 = V_34 -> V_35 . V_188 . V_209 ;
V_35 . V_339 = V_34 -> V_35 . V_188 . V_317 ( V_34 ) ;
return F_280 ( V_34 , V_173 , F_237 ( V_34 -> V_11 , V_14 ) , & V_35 ) ;
}
static bool F_281 ( struct V_33 * V_34 )
{
if ( F_14 ( ! F_282 ( V_34 -> V_11 ) ||
F_283 ( V_34 ) ) )
return false ;
return V_115 -> V_340 ( V_34 ) ;
}
static bool F_254 ( struct V_33 * V_34 , bool V_279 , T_2 V_14 ,
T_7 V_173 , T_3 * V_20 , bool V_277 , bool * V_341 )
{
bool V_342 ;
* V_20 = F_284 ( V_34 -> V_11 , V_14 , & V_342 , V_277 , V_341 ) ;
if ( ! V_342 )
return false ;
if ( ! V_279 && F_281 ( V_34 ) ) {
F_285 ( V_173 , V_14 ) ;
if ( F_286 ( V_34 , V_14 ) ) {
F_287 ( V_173 , V_14 ) ;
F_164 ( V_343 , V_34 ) ;
return true ;
} else if ( F_279 ( V_34 , V_173 , V_14 ) )
return true ;
}
* V_20 = F_288 ( V_34 -> V_11 , V_14 , V_277 , V_341 ) ;
return false ;
}
static int F_289 ( struct V_33 * V_34 , T_7 V_344 , T_4 V_304 ,
bool V_279 )
{
T_3 V_20 ;
int V_81 ;
int V_41 ;
int V_308 ;
T_2 V_14 = V_344 >> V_18 ;
unsigned long V_309 ;
int V_277 = V_304 & V_307 ;
bool V_278 ;
ASSERT ( V_34 ) ;
ASSERT ( F_231 ( V_34 -> V_35 . V_188 . V_222 ) ) ;
if ( F_14 ( V_304 & V_305 ) ) {
V_81 = F_277 ( V_34 , V_344 , V_304 , true ) ;
if ( F_18 ( V_81 != V_331 ) )
return V_81 ;
}
V_81 = F_68 ( V_34 ) ;
if ( V_81 )
return V_81 ;
V_308 = F_86 ( V_34 , V_14 ) ;
if ( F_18 ( ! V_308 ) ) {
V_41 = F_87 ( V_34 , V_14 ) ;
V_14 &= ~ ( F_241 ( V_41 ) - 1 ) ;
} else
V_41 = V_42 ;
if ( F_250 ( V_34 , V_344 , V_41 , V_304 ) )
return 0 ;
V_309 = V_34 -> V_11 -> V_159 ;
F_39 () ;
if ( F_254 ( V_34 , V_279 , V_14 , V_344 , & V_20 , V_277 , & V_278 ) )
return 0 ;
if ( F_244 ( V_34 , 0 , V_14 , V_20 , V_281 , & V_81 ) )
return V_81 ;
F_209 ( & V_34 -> V_11 -> V_200 ) ;
if ( F_255 ( V_34 -> V_11 , V_309 ) )
goto V_310;
F_256 ( V_34 ) ;
if ( F_18 ( ! V_308 ) )
F_238 ( V_34 , & V_14 , & V_20 , & V_41 ) ;
V_81 = F_230 ( V_34 , V_344 , V_277 , V_278 ,
V_41 , V_14 , V_20 , V_279 ) ;
F_210 ( & V_34 -> V_11 -> V_200 ) ;
return V_81 ;
V_310:
F_210 ( & V_34 -> V_11 -> V_200 ) ;
F_222 ( V_20 ) ;
return 0 ;
}
static void F_290 ( struct V_33 * V_34 ,
struct V_345 * V_346 )
{
V_346 -> V_347 = F_278 ;
V_346 -> V_348 = F_268 ;
V_346 -> V_189 = F_151 ;
V_346 -> V_349 = F_152 ;
V_346 -> V_350 = F_153 ;
V_346 -> V_210 = 0 ;
V_346 -> V_223 = V_224 ;
V_346 -> V_222 = V_312 ;
V_346 -> V_209 = true ;
V_346 -> V_351 = false ;
}
void F_291 ( struct V_33 * V_34 )
{
F_257 ( V_34 ) ;
}
static unsigned long V_317 ( struct V_33 * V_34 )
{
return F_292 ( V_34 ) ;
}
static void F_293 ( struct V_33 * V_34 ,
struct V_326 * V_352 )
{
V_34 -> V_35 . V_188 . F_293 ( V_34 , V_352 ) ;
}
static bool F_294 ( struct V_11 * V_11 , T_1 * V_13 , T_2 V_14 ,
unsigned V_15 , int * V_353 )
{
if ( F_14 ( F_10 ( * V_13 ) ) ) {
if ( V_14 != F_11 ( * V_13 ) ) {
F_51 ( V_13 ) ;
return true ;
}
( * V_353 ) ++ ;
F_7 ( V_11 , V_13 , V_14 , V_15 ) ;
return true ;
}
return false ;
}
static inline bool F_295 ( struct V_345 * V_188 , unsigned V_41 , unsigned V_44 )
{
unsigned V_90 ;
V_90 = V_41 - 1 ;
V_90 |= ( V_44 & V_40 ) >> ( V_354 - 2 ) ;
return V_188 -> V_355 & ( 1 << V_90 ) ;
}
static void F_296 ( struct V_33 * V_34 ,
struct V_345 * V_346 )
{
int V_356 = F_297 ( V_34 ) ;
T_1 V_357 = 0 ;
T_1 V_358 = 0 ;
T_1 V_359 = 0 ;
V_346 -> V_360 = 0 ;
if ( ! V_346 -> V_351 )
V_357 = F_298 ( 63 , 63 ) ;
if ( ! F_299 ( V_34 ) )
V_358 = F_298 ( 7 , 7 ) ;
if ( F_300 ( V_34 ) )
V_359 = F_298 ( 8 , 8 ) ;
switch ( V_346 -> V_210 ) {
case V_211 :
V_346 -> V_361 [ 0 ] [ 1 ] = 0 ;
V_346 -> V_361 [ 0 ] [ 0 ] = 0 ;
V_346 -> V_361 [ 1 ] [ 0 ] = V_346 -> V_361 [ 0 ] [ 0 ] ;
if ( ! F_301 ( V_34 ) ) {
V_346 -> V_361 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_20 () )
V_346 -> V_361 [ 1 ] [ 1 ] = F_298 ( 17 , 21 ) ;
else
V_346 -> V_361 [ 1 ] [ 1 ] = F_298 ( 13 , 21 ) ;
break;
case V_224 :
V_346 -> V_361 [ 0 ] [ 2 ] =
F_298 ( V_356 , 63 ) |
F_298 ( 5 , 8 ) | F_298 ( 1 , 2 ) ;
V_346 -> V_361 [ 0 ] [ 1 ] = V_357 |
F_298 ( V_356 , 62 ) ;
V_346 -> V_361 [ 0 ] [ 0 ] = V_357 |
F_298 ( V_356 , 62 ) ;
V_346 -> V_361 [ 1 ] [ 1 ] = V_357 |
F_298 ( V_356 , 62 ) |
F_298 ( 13 , 20 ) ;
V_346 -> V_361 [ 1 ] [ 0 ] = V_346 -> V_361 [ 0 ] [ 0 ] ;
break;
case V_197 :
V_346 -> V_361 [ 0 ] [ 3 ] = V_357 |
V_359 | F_298 ( 7 , 7 ) | F_298 ( V_356 , 51 ) ;
V_346 -> V_361 [ 0 ] [ 2 ] = V_357 |
V_359 | V_358 | F_298 ( V_356 , 51 ) ;
V_346 -> V_361 [ 0 ] [ 1 ] = V_357 |
F_298 ( V_356 , 51 ) ;
V_346 -> V_361 [ 0 ] [ 0 ] = V_357 |
F_298 ( V_356 , 51 ) ;
V_346 -> V_361 [ 1 ] [ 3 ] = V_346 -> V_361 [ 0 ] [ 3 ] ;
V_346 -> V_361 [ 1 ] [ 2 ] = V_357 |
V_358 | F_298 ( V_356 , 51 ) |
F_298 ( 13 , 29 ) ;
V_346 -> V_361 [ 1 ] [ 1 ] = V_357 |
F_298 ( V_356 , 51 ) |
F_298 ( 13 , 20 ) ;
V_346 -> V_361 [ 1 ] [ 0 ] = V_346 -> V_361 [ 0 ] [ 0 ] ;
break;
}
}
static void F_302 ( struct V_33 * V_34 ,
struct V_345 * V_346 , bool V_362 )
{
int V_356 = F_297 ( V_34 ) ;
int V_38 ;
V_346 -> V_361 [ 0 ] [ 3 ] =
F_298 ( V_356 , 51 ) | F_298 ( 3 , 7 ) ;
V_346 -> V_361 [ 0 ] [ 2 ] =
F_298 ( V_356 , 51 ) | F_298 ( 3 , 6 ) ;
V_346 -> V_361 [ 0 ] [ 1 ] =
F_298 ( V_356 , 51 ) | F_298 ( 3 , 6 ) ;
V_346 -> V_361 [ 0 ] [ 0 ] = F_298 ( V_356 , 51 ) ;
V_346 -> V_361 [ 1 ] [ 3 ] = V_346 -> V_361 [ 0 ] [ 3 ] ;
V_346 -> V_361 [ 1 ] [ 2 ] =
F_298 ( V_356 , 51 ) | F_298 ( 12 , 29 ) ;
V_346 -> V_361 [ 1 ] [ 1 ] =
F_298 ( V_356 , 51 ) | F_298 ( 12 , 20 ) ;
V_346 -> V_361 [ 1 ] [ 0 ] = V_346 -> V_361 [ 0 ] [ 0 ] ;
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ ) {
int V_363 = V_38 & 7 ;
int V_364 = V_38 >> 3 ;
if ( V_364 == 0x2 || V_364 == 0x3 || V_364 == 0x7 ||
V_363 == 0x2 || V_363 == 0x6 ||
( V_363 == 0x4 && ! V_362 ) )
V_346 -> V_360 |= ( 1ull << V_38 ) ;
}
}
void F_303 ( struct V_33 * V_34 ,
struct V_345 * V_188 , bool V_365 )
{
unsigned V_366 , V_367 , V_368 ;
T_8 V_369 ;
bool V_352 , V_370 , V_371 , V_372 , V_373 , V_374 , V_375 , V_376 , V_377 , V_378 , V_379 = 0 ;
V_378 = F_304 ( V_34 , V_380 ) ;
V_377 = F_304 ( V_34 , V_381 ) ;
for ( V_367 = 0 ; V_367 < F_59 ( V_188 -> V_382 ) ; ++ V_367 ) {
V_368 = V_367 << 1 ;
V_369 = 0 ;
V_373 = V_368 & V_307 ;
V_374 = V_368 & V_383 ;
V_375 = V_368 & V_384 ;
V_376 = ! ( V_368 & V_305 ) ;
for ( V_366 = 0 ; V_366 < 8 ; ++ V_366 ) {
V_370 = V_366 & V_265 ;
V_371 = V_366 & V_16 ;
V_372 = V_366 & V_17 ;
if ( ! V_365 ) {
V_370 |= ! V_188 -> V_351 ;
V_371 |= ! F_305 ( V_34 ) && ! V_374 ;
V_370 &= ! ( V_378 && V_372 && ! V_374 ) ;
V_379 = V_377 && V_372 && ! V_374 && ! V_375 ;
} else
V_372 = 1 ;
V_352 = ( V_375 && ! V_370 ) || ( V_374 && ! V_372 ) || ( V_373 && ! V_371 ) ||
( V_376 && V_379 ) ;
V_369 |= V_352 << V_366 ;
}
V_188 -> V_382 [ V_367 ] = V_369 ;
}
}
static void F_306 ( struct V_33 * V_34 , struct V_345 * V_188 )
{
T_8 V_369 ;
unsigned V_41 , V_210 = V_188 -> V_210 ;
const unsigned V_385 = 1 << 2 ;
if ( V_210 == V_224 )
-- V_210 ;
V_369 = 1 | ( 1 << V_385 ) ;
for ( V_41 = V_103 ; V_41 <= V_210 ; ++ V_41 ) {
if ( V_41 <= V_386
&& ( V_188 -> V_210 >= V_224 || F_301 ( V_34 ) ) )
V_369 |= 1 << ( V_385 | ( V_41 - 1 ) ) ;
}
V_188 -> V_355 = V_369 ;
}
static void F_307 ( struct V_33 * V_34 ,
struct V_345 * V_346 ,
int V_41 )
{
V_346 -> V_351 = F_21 ( V_34 ) ;
V_346 -> V_210 = V_41 ;
F_296 ( V_34 , V_346 ) ;
F_303 ( V_34 , V_346 , false ) ;
F_306 ( V_34 , V_346 ) ;
ASSERT ( F_162 ( V_34 ) ) ;
V_346 -> V_347 = V_387 ;
V_346 -> V_348 = V_388 ;
V_346 -> V_189 = V_389 ;
V_346 -> V_349 = V_390 ;
V_346 -> V_350 = V_391 ;
V_346 -> V_223 = V_41 ;
V_346 -> V_222 = V_312 ;
V_346 -> V_209 = false ;
}
static void F_308 ( struct V_33 * V_34 ,
struct V_345 * V_346 )
{
F_307 ( V_34 , V_346 , V_197 ) ;
}
static void F_309 ( struct V_33 * V_34 ,
struct V_345 * V_346 )
{
V_346 -> V_351 = false ;
V_346 -> V_210 = V_211 ;
F_296 ( V_34 , V_346 ) ;
F_303 ( V_34 , V_346 , false ) ;
F_306 ( V_34 , V_346 ) ;
V_346 -> V_347 = V_392 ;
V_346 -> V_348 = V_393 ;
V_346 -> V_189 = V_394 ;
V_346 -> V_349 = V_395 ;
V_346 -> V_350 = V_396 ;
V_346 -> V_223 = V_224 ;
V_346 -> V_222 = V_312 ;
V_346 -> V_209 = false ;
}
static void F_310 ( struct V_33 * V_34 ,
struct V_345 * V_346 )
{
F_307 ( V_34 , V_346 , V_224 ) ;
}
static void F_311 ( struct V_33 * V_34 )
{
struct V_345 * V_346 = V_34 -> V_35 . V_397 ;
V_346 -> V_208 . V_214 = 0 ;
V_346 -> V_347 = F_289 ;
V_346 -> V_189 = F_151 ;
V_346 -> V_349 = F_152 ;
V_346 -> V_350 = F_153 ;
V_346 -> V_223 = V_115 -> V_398 () ;
V_346 -> V_222 = V_312 ;
V_346 -> V_209 = true ;
V_346 -> V_399 = V_115 -> V_400 ;
V_346 -> V_317 = V_317 ;
V_346 -> V_320 = V_401 ;
V_346 -> F_293 = V_402 ;
if ( ! F_312 ( V_34 ) ) {
V_346 -> V_351 = false ;
V_346 -> V_348 = F_268 ;
V_346 -> V_210 = 0 ;
} else if ( F_313 ( V_34 ) ) {
V_346 -> V_351 = F_21 ( V_34 ) ;
V_346 -> V_210 = V_197 ;
F_296 ( V_34 , V_346 ) ;
V_346 -> V_348 = V_388 ;
} else if ( F_162 ( V_34 ) ) {
V_346 -> V_351 = F_21 ( V_34 ) ;
V_346 -> V_210 = V_224 ;
F_296 ( V_34 , V_346 ) ;
V_346 -> V_348 = V_388 ;
} else {
V_346 -> V_351 = false ;
V_346 -> V_210 = V_211 ;
F_296 ( V_34 , V_346 ) ;
V_346 -> V_348 = V_393 ;
}
F_303 ( V_34 , V_346 , false ) ;
F_306 ( V_34 , V_346 ) ;
}
void F_314 ( struct V_33 * V_34 , struct V_345 * V_346 )
{
bool V_403 = F_304 ( V_34 , V_380 ) ;
ASSERT ( V_34 ) ;
ASSERT ( ! F_231 ( V_34 -> V_35 . V_188 . V_222 ) ) ;
if ( ! F_312 ( V_34 ) )
F_290 ( V_34 , V_346 ) ;
else if ( F_313 ( V_34 ) )
F_308 ( V_34 , V_346 ) ;
else if ( F_162 ( V_34 ) )
F_310 ( V_34 , V_346 ) ;
else
F_309 ( V_34 , V_346 ) ;
V_34 -> V_35 . V_188 . V_208 . V_404 = F_21 ( V_34 ) ;
V_34 -> V_35 . V_188 . V_208 . V_187 = ! ! F_162 ( V_34 ) ;
V_34 -> V_35 . V_188 . V_208 . V_405 = F_305 ( V_34 ) ;
V_34 -> V_35 . V_188 . V_208 . V_406
= V_403 && ! F_305 ( V_34 ) ;
}
void F_315 ( struct V_33 * V_34 , struct V_345 * V_346 ,
bool V_362 )
{
ASSERT ( V_34 ) ;
ASSERT ( ! F_231 ( V_34 -> V_35 . V_188 . V_222 ) ) ;
V_346 -> V_223 = V_115 -> V_398 () ;
V_346 -> V_351 = true ;
V_346 -> V_347 = V_407 ;
V_346 -> V_348 = V_408 ;
V_346 -> V_189 = V_409 ;
V_346 -> V_349 = V_410 ;
V_346 -> V_350 = V_411 ;
V_346 -> V_210 = V_346 -> V_223 ;
V_346 -> V_222 = V_312 ;
V_346 -> V_209 = false ;
F_303 ( V_34 , V_346 , true ) ;
F_302 ( V_34 , V_346 , V_362 ) ;
}
static void F_316 ( struct V_33 * V_34 )
{
F_314 ( V_34 , V_34 -> V_35 . V_397 ) ;
V_34 -> V_35 . V_397 -> V_399 = V_115 -> V_399 ;
V_34 -> V_35 . V_397 -> V_317 = V_317 ;
V_34 -> V_35 . V_397 -> V_320 = V_401 ;
V_34 -> V_35 . V_397 -> F_293 = V_402 ;
}
static void F_317 ( struct V_33 * V_34 )
{
struct V_345 * V_412 = & V_34 -> V_35 . V_328 ;
V_412 -> V_317 = V_317 ;
V_412 -> V_320 = V_401 ;
V_412 -> F_293 = V_402 ;
if ( ! F_312 ( V_34 ) ) {
V_412 -> V_351 = false ;
V_412 -> V_210 = 0 ;
V_412 -> V_348 = F_269 ;
} else if ( F_313 ( V_34 ) ) {
V_412 -> V_351 = F_21 ( V_34 ) ;
V_412 -> V_210 = V_197 ;
F_296 ( V_34 , V_412 ) ;
V_412 -> V_348 = V_413 ;
} else if ( F_162 ( V_34 ) ) {
V_412 -> V_351 = F_21 ( V_34 ) ;
V_412 -> V_210 = V_224 ;
F_296 ( V_34 , V_412 ) ;
V_412 -> V_348 = V_413 ;
} else {
V_412 -> V_351 = false ;
V_412 -> V_210 = V_211 ;
F_296 ( V_34 , V_412 ) ;
V_412 -> V_348 = V_414 ;
}
F_303 ( V_34 , V_412 , false ) ;
F_306 ( V_34 , V_412 ) ;
}
static void F_318 ( struct V_33 * V_34 )
{
if ( F_319 ( V_34 ) )
return F_317 ( V_34 ) ;
else if ( V_266 )
return F_311 ( V_34 ) ;
else
return F_316 ( V_34 ) ;
}
void F_320 ( struct V_33 * V_34 )
{
ASSERT ( V_34 ) ;
F_321 ( V_34 ) ;
F_318 ( V_34 ) ;
}
int F_322 ( struct V_33 * V_34 )
{
int V_81 ;
V_81 = F_68 ( V_34 ) ;
if ( V_81 )
goto V_85;
V_81 = F_264 ( V_34 ) ;
F_267 ( V_34 ) ;
if ( V_81 )
goto V_85;
V_34 -> V_35 . V_188 . V_399 ( V_34 , V_34 -> V_35 . V_188 . V_222 ) ;
V_85:
return V_81 ;
}
void F_321 ( struct V_33 * V_34 )
{
F_257 ( V_34 ) ;
F_3 ( F_231 ( V_34 -> V_35 . V_188 . V_222 ) ) ;
}
static void F_323 ( struct V_33 * V_34 ,
struct V_48 * V_49 , T_1 * V_10 ,
const void * V_415 )
{
if ( V_49 -> V_91 . V_41 != V_42 ) {
++ V_34 -> V_11 -> V_132 . V_416 ;
return;
}
++ V_34 -> V_11 -> V_132 . V_417 ;
V_34 -> V_35 . V_188 . V_350 ( V_34 , V_49 , V_10 , V_415 ) ;
}
static bool F_324 ( T_1 V_418 , T_1 V_415 )
{
if ( ! F_22 ( V_418 ) )
return false ;
if ( ! F_22 ( V_415 ) )
return true ;
if ( ( V_418 ^ V_415 ) & V_43 )
return true ;
V_418 ^= V_31 ;
V_415 ^= V_31 ;
return ( V_418 & ~ V_415 & V_419 ) != 0 ;
}
static void F_325 ( struct V_33 * V_34 , bool V_420 ,
bool V_421 , bool V_422 )
{
if ( V_420 )
return;
if ( V_421 )
F_106 ( V_34 -> V_11 ) ;
else if ( V_422 )
F_164 ( V_190 , V_34 ) ;
}
static T_1 F_326 ( struct V_33 * V_34 , T_9 * V_344 ,
const T_8 * V_415 , int * V_423 )
{
T_1 V_424 ;
int V_81 ;
if ( F_162 ( V_34 ) && * V_423 == 4 ) {
* V_344 &= ~ ( T_9 ) 7 ;
* V_423 = 8 ;
V_81 = F_327 ( V_34 -> V_11 , * V_344 , & V_424 , 8 ) ;
if ( V_81 )
V_424 = 0 ;
V_415 = ( const T_8 * ) & V_424 ;
}
switch ( * V_423 ) {
case 4 :
V_424 = * ( const T_4 * ) V_415 ;
break;
case 8 :
V_424 = * ( const T_1 * ) V_415 ;
break;
default:
V_424 = 0 ;
break;
}
return V_424 ;
}
static bool F_328 ( struct V_48 * V_49 )
{
if ( V_49 -> V_91 . V_41 == V_42 )
return false ;
return ++ V_49 -> V_202 >= 3 ;
}
static bool F_329 ( struct V_48 * V_49 , T_9 V_344 ,
int V_423 )
{
unsigned V_425 , V_426 , V_427 ;
F_212 ( L_25 ,
V_344 , V_423 , V_49 -> V_91 . V_214 ) ;
V_425 = F_330 ( V_344 ) ;
V_426 = V_49 -> V_91 . V_187 ? 8 : 4 ;
if ( ! ( V_425 & ( V_426 - 1 ) ) && V_423 == 1 )
return false ;
V_427 = ( V_425 ^ ( V_425 + V_423 - 1 ) ) & ~ ( V_426 - 1 ) ;
V_427 |= V_423 < 4 ;
return V_427 ;
}
static T_1 * F_331 ( struct V_48 * V_49 , T_9 V_344 , int * V_428 )
{
unsigned V_429 , V_206 ;
T_1 * V_10 ;
int V_41 ;
V_429 = F_330 ( V_344 ) ;
V_41 = V_49 -> V_91 . V_41 ;
* V_428 = 1 ;
if ( ! V_49 -> V_91 . V_187 ) {
V_429 <<= 1 ;
if ( V_41 == V_211 ) {
V_429 &= ~ 7 ;
V_429 <<= 1 ;
* V_428 = 2 ;
}
V_206 = V_429 >> V_18 ;
V_429 &= ~ V_19 ;
if ( V_206 != V_49 -> V_91 . V_206 )
return NULL ;
}
V_10 = & V_49 -> V_128 [ V_429 / sizeof( * V_10 ) ] ;
return V_10 ;
}
void F_332 ( struct V_33 * V_34 , T_9 V_344 ,
const T_8 * V_415 , int V_423 )
{
T_2 V_14 = V_344 >> V_18 ;
union V_205 V_4 = { . V_214 = 0 } ;
struct V_48 * V_49 ;
F_166 ( V_185 ) ;
T_1 V_430 , V_424 , * V_10 ;
int V_431 ;
bool V_421 , V_422 , V_420 ;
if ( ! F_33 ( V_34 -> V_11 -> V_35 . V_106 ) )
return;
V_420 = V_421 = V_422 = false ;
F_212 ( L_26 , V_160 , V_344 , V_423 ) ;
V_424 = F_326 ( V_34 , & V_344 , V_415 , & V_423 ) ;
F_68 ( V_34 ) ;
F_209 ( & V_34 -> V_11 -> V_200 ) ;
++ V_34 -> V_11 -> V_132 . V_432 ;
F_168 ( V_34 , V_433 ) ;
V_4 . V_405 = V_4 . V_187 = V_4 . V_404 = 1 ;
F_172 (vcpu->kvm, sp, gfn) {
if ( F_329 ( V_49 , V_344 , V_423 ) ||
F_328 ( V_49 ) ) {
V_420 |= ! ! F_163 ( V_34 -> V_11 , V_49 ,
& V_185 ) ;
++ V_34 -> V_11 -> V_132 . V_434 ;
continue;
}
V_10 = F_331 ( V_49 , V_344 , & V_431 ) ;
if ( ! V_10 )
continue;
V_422 = true ;
while ( V_431 -- ) {
V_430 = * V_10 ;
F_196 ( V_34 -> V_11 , V_49 , V_10 ) ;
if ( V_424 &&
! ( ( V_49 -> V_91 . V_214 ^ V_34 -> V_35 . V_188 . V_208 . V_214 )
& V_4 . V_214 ) && F_98 ( V_34 ) )
F_323 ( V_34 , V_49 , V_10 , & V_424 ) ;
if ( F_324 ( V_430 , * V_10 ) )
V_421 = true ;
++ V_10 ;
}
}
F_325 ( V_34 , V_420 , V_421 , V_422 ) ;
F_167 ( V_34 -> V_11 , & V_185 ) ;
F_168 ( V_34 , V_435 ) ;
F_210 ( & V_34 -> V_11 -> V_200 ) ;
}
int F_333 ( struct V_33 * V_34 , T_7 V_173 )
{
T_9 V_344 ;
int V_81 ;
if ( V_34 -> V_35 . V_188 . V_209 )
return 0 ;
V_344 = F_334 ( V_34 , V_173 , NULL ) ;
V_81 = F_211 ( V_34 -> V_11 , V_344 >> V_18 ) ;
return V_81 ;
}
static void F_256 ( struct V_33 * V_34 )
{
F_166 ( V_185 ) ;
if ( F_18 ( F_335 ( V_34 -> V_11 ) >= V_436 ) )
return;
while ( F_335 ( V_34 -> V_11 ) < V_437 ) {
if ( ! F_206 ( V_34 -> V_11 , & V_185 ) )
break;
++ V_34 -> V_11 -> V_132 . V_438 ;
}
F_167 ( V_34 -> V_11 , & V_185 ) ;
}
static bool F_336 ( struct V_33 * V_34 , T_7 V_220 )
{
if ( V_34 -> V_35 . V_188 . V_209 || F_319 ( V_34 ) )
return F_271 ( V_34 , V_220 ) ;
return F_272 ( V_34 , V_220 ) ;
}
int F_337 ( struct V_33 * V_34 , T_7 V_439 , T_4 V_304 ,
void * V_440 , int V_441 )
{
int V_81 , V_442 = V_443 ;
enum V_444 V_445 ;
V_81 = V_34 -> V_35 . V_188 . V_347 ( V_34 , V_439 , V_304 , false ) ;
if ( V_81 < 0 )
goto V_85;
if ( ! V_81 ) {
V_81 = 1 ;
goto V_85;
}
if ( F_336 ( V_34 , V_439 ) )
V_442 = 0 ;
V_445 = F_338 ( V_34 , V_439 , V_442 , V_440 , V_441 ) ;
switch ( V_445 ) {
case V_446 :
return 1 ;
case V_447 :
++ V_34 -> V_132 . V_448 ;
case V_449 :
return 0 ;
default:
F_93 () ;
}
V_85:
return V_81 ;
}
void F_339 ( struct V_33 * V_34 , T_7 V_173 )
{
V_34 -> V_35 . V_188 . V_349 ( V_34 , V_173 ) ;
F_164 ( V_190 , V_34 ) ;
++ V_34 -> V_132 . V_349 ;
}
void F_340 ( void )
{
V_266 = true ;
}
void F_341 ( void )
{
V_266 = false ;
}
static void F_342 ( struct V_33 * V_34 )
{
F_67 ( ( unsigned long ) V_34 -> V_35 . V_188 . V_225 ) ;
if ( V_34 -> V_35 . V_188 . V_321 != NULL )
F_67 ( ( unsigned long ) V_34 -> V_35 . V_188 . V_321 ) ;
}
static int F_343 ( struct V_33 * V_34 )
{
struct V_80 * V_80 ;
int V_102 ;
ASSERT ( V_34 ) ;
V_80 = F_344 ( V_77 | V_450 ) ;
if ( ! V_80 )
return - V_78 ;
V_34 -> V_35 . V_188 . V_225 = F_345 ( V_80 ) ;
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 )
V_34 -> V_35 . V_188 . V_225 [ V_102 ] = V_312 ;
return 0 ;
}
int F_346 ( struct V_33 * V_34 )
{
ASSERT ( V_34 ) ;
V_34 -> V_35 . V_397 = & V_34 -> V_35 . V_188 ;
V_34 -> V_35 . V_188 . V_222 = V_312 ;
V_34 -> V_35 . V_188 . V_329 = V_329 ;
V_34 -> V_35 . V_328 . V_329 = V_451 ;
return F_343 ( V_34 ) ;
}
void F_347 ( struct V_33 * V_34 )
{
ASSERT ( V_34 ) ;
ASSERT ( ! F_231 ( V_34 -> V_35 . V_188 . V_222 ) ) ;
F_318 ( V_34 ) ;
}
void F_348 ( struct V_11 * V_11 , int V_97 )
{
struct V_96 * V_147 ;
T_2 V_452 ;
int V_102 ;
V_147 = F_349 ( V_11 -> V_453 , V_97 ) ;
V_452 = V_147 -> V_99 + V_147 -> V_153 - 1 ;
F_209 ( & V_11 -> V_200 ) ;
for ( V_102 = V_42 ;
V_102 < V_42 + V_104 ; ++ V_102 ) {
unsigned long * V_127 ;
unsigned long V_454 , V_90 ;
V_127 = V_147 -> V_35 . V_126 [ V_102 - V_42 ] ;
V_454 = F_77 ( V_452 , V_147 -> V_99 , V_102 ) ;
for ( V_90 = 0 ; V_90 <= V_454 ; ++ V_90 , ++ V_127 ) {
if ( * V_127 )
F_108 ( V_11 , V_127 , false ) ;
if ( F_350 () || F_351 ( & V_11 -> V_200 ) )
F_178 ( & V_11 -> V_200 ) ;
}
}
F_210 ( & V_11 -> V_200 ) ;
F_352 ( & V_11 -> V_455 ) ;
F_106 ( V_11 ) ;
}
static void F_353 ( struct V_11 * V_11 )
{
struct V_48 * V_49 , * V_456 ;
int V_457 = 0 ;
V_458:
F_354 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_65 ;
if ( ! F_182 ( V_11 , V_49 ) )
break;
if ( V_49 -> V_91 . V_232 )
continue;
if ( V_457 >= V_459 &&
F_178 ( & V_11 -> V_200 ) ) {
V_457 = 0 ;
goto V_458;
}
V_65 = F_163 ( V_11 , V_49 ,
& V_11 -> V_35 . V_460 ) ;
V_457 += V_65 ;
if ( V_65 )
goto V_458;
}
F_167 ( V_11 , & V_11 -> V_35 . V_460 ) ;
}
void F_355 ( struct V_11 * V_11 )
{
F_209 ( & V_11 -> V_200 ) ;
F_356 ( V_11 ) ;
V_11 -> V_35 . V_203 ++ ;
F_203 ( V_11 ) ;
F_353 ( V_11 ) ;
F_210 ( & V_11 -> V_200 ) ;
}
static bool F_357 ( struct V_11 * V_11 )
{
return F_14 ( ! F_358 ( & V_11 -> V_35 . V_460 ) ) ;
}
void F_359 ( struct V_11 * V_11 )
{
if ( F_14 ( F_5 ( V_11 ) == 0 ) ) {
F_360 ( V_461 L_27 ) ;
F_355 ( V_11 ) ;
}
}
static unsigned long
F_361 ( struct V_462 * V_463 , struct V_464 * V_465 )
{
struct V_11 * V_11 ;
int V_466 = V_465 -> V_466 ;
unsigned long V_467 = 0 ;
F_209 ( & V_468 ) ;
F_362 (kvm, &vm_list, vm_list) {
int V_98 ;
F_166 ( V_185 ) ;
if ( ! V_466 -- )
break;
if ( ! V_11 -> V_35 . V_162 &&
! F_357 ( V_11 ) )
continue;
V_98 = F_363 ( & V_11 -> V_469 ) ;
F_209 ( & V_11 -> V_200 ) ;
if ( F_357 ( V_11 ) ) {
F_167 ( V_11 ,
& V_11 -> V_35 . V_460 ) ;
goto V_470;
}
if ( F_206 ( V_11 , & V_185 ) )
V_467 ++ ;
F_167 ( V_11 , & V_185 ) ;
V_470:
F_210 ( & V_11 -> V_200 ) ;
F_364 ( & V_11 -> V_469 , V_98 ) ;
F_365 ( & V_11 -> V_471 , & V_471 ) ;
break;
}
F_210 ( & V_468 ) ;
return V_467 ;
}
static unsigned long
F_366 ( struct V_462 * V_463 , struct V_464 * V_465 )
{
return F_367 ( & V_163 ) ;
}
static void F_368 ( void )
{
if ( V_83 )
F_369 ( V_83 ) ;
if ( V_87 )
F_369 ( V_87 ) ;
}
int F_370 ( void )
{
V_83 = F_371 ( L_28 ,
sizeof( struct V_89 ) ,
0 , 0 , NULL ) ;
if ( ! V_83 )
goto V_472;
V_87 = F_371 ( L_29 ,
sizeof( struct V_48 ) ,
0 , 0 , NULL ) ;
if ( ! V_87 )
goto V_472;
if ( F_372 ( & V_163 , 0 , V_77 ) )
goto V_472;
F_373 ( & V_473 ) ;
return 0 ;
V_472:
F_368 () ;
return - V_78 ;
}
unsigned int F_374 ( struct V_11 * V_11 )
{
unsigned int V_474 ;
unsigned int V_475 = 0 ;
struct F_6 * V_146 ;
struct V_96 * V_147 ;
V_146 = F_6 ( V_11 ) ;
F_119 (memslot, slots)
V_475 += V_147 -> V_153 ;
V_474 = V_475 * V_476 / 1000 ;
V_474 = F_120 ( V_474 ,
( unsigned int ) V_477 ) ;
return V_474 ;
}
int F_375 ( struct V_33 * V_34 , T_1 V_220 , T_1 V_119 [ 4 ] )
{
struct V_218 V_219 ;
T_1 V_10 ;
int V_478 = 0 ;
if ( ! F_231 ( V_34 -> V_35 . V_188 . V_222 ) )
return V_478 ;
F_53 ( V_34 ) ;
F_251 (vcpu, addr, iterator, spte) {
V_119 [ V_219 . V_41 - 1 ] = V_10 ;
V_478 ++ ;
if ( ! F_22 ( V_10 ) )
break;
}
F_56 ( V_34 ) ;
return V_478 ;
}
void F_376 ( struct V_33 * V_34 )
{
ASSERT ( V_34 ) ;
F_321 ( V_34 ) ;
F_342 ( V_34 ) ;
F_69 ( V_34 ) ;
}
void F_377 ( void )
{
F_368 () ;
F_378 ( & V_163 ) ;
F_379 ( & V_473 ) ;
F_169 () ;
}
