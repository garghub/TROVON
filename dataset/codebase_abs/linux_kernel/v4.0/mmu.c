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
static bool F_44 ( T_1 V_62 , T_1 V_63 , T_1 V_64 )
{
return ( V_62 & V_64 ) != ( V_63 & V_64 ) ;
}
static void F_9 ( T_1 * V_13 , T_1 V_63 )
{
F_3 ( F_22 ( * V_13 ) ) ;
F_28 ( V_13 , V_63 ) ;
}
static bool F_45 ( T_1 * V_13 , T_1 V_63 )
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
if ( F_44 ( V_62 , V_63 ,
V_29 | V_30 ) )
V_65 = true ;
if ( F_43 ( V_62 , V_63 , V_29 ) )
F_46 ( F_26 ( V_62 ) ) ;
if ( F_43 ( V_62 , V_63 , V_30 ) )
F_47 ( F_26 ( V_62 ) ) ;
return V_65 ;
}
static int F_48 ( T_1 * V_13 )
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
F_3 ( ! F_49 ( V_20 ) && ! F_50 ( F_51 ( V_20 ) ) ) ;
if ( ! V_29 || V_62 & V_29 )
F_46 ( V_20 ) ;
if ( ! V_30 || ( V_62 & V_30 ) )
F_47 ( V_20 ) ;
return 1 ;
}
static void F_52 ( T_1 * V_13 )
{
F_29 ( V_13 , 0ull ) ;
}
static T_1 F_53 ( T_1 * V_13 )
{
return F_32 ( V_13 ) ;
}
static void F_54 ( struct V_33 * V_34 )
{
F_55 () ;
V_34 -> V_66 = V_67 ;
F_56 () ;
}
static void F_57 ( struct V_33 * V_34 )
{
F_56 () ;
V_34 -> V_66 = V_68 ;
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
static int F_69 ( struct V_33 * V_34 )
{
int V_81 ;
V_81 = F_59 ( & V_34 -> V_35 . V_82 ,
V_83 , 8 + V_84 ) ;
if ( V_81 )
goto V_85;
V_81 = F_65 ( & V_34 -> V_35 . V_86 , 8 ) ;
if ( V_81 )
goto V_85;
V_81 = F_59 ( & V_34 -> V_35 . V_87 ,
V_87 , 4 ) ;
V_85:
return V_81 ;
}
static void F_70 ( struct V_33 * V_34 )
{
F_63 ( & V_34 -> V_35 . V_82 ,
V_83 ) ;
F_67 ( & V_34 -> V_35 . V_86 ) ;
F_63 ( & V_34 -> V_35 . V_87 ,
V_87 ) ;
}
static void * F_71 ( struct V_69 * V_79 )
{
void * V_88 ;
F_72 ( ! V_79 -> V_75 ) ;
V_88 = V_79 -> V_76 [ -- V_79 -> V_75 ] ;
return V_88 ;
}
static struct V_89 * F_73 ( struct V_33 * V_34 )
{
return F_71 ( & V_34 -> V_35 . V_82 ) ;
}
static void F_74 ( struct V_89 * V_89 )
{
F_64 ( V_83 , V_89 ) ;
}
static T_2 F_75 ( struct V_48 * V_49 , int V_90 )
{
if ( ! V_49 -> V_91 . V_92 )
return V_49 -> V_93 [ V_90 ] ;
return V_49 -> V_14 + ( V_90 << ( ( V_49 -> V_91 . V_41 - 1 ) * V_94 ) ) ;
}
static void F_76 ( struct V_48 * V_49 , int V_90 , T_2 V_14 )
{
if ( V_49 -> V_91 . V_92 )
F_72 ( V_14 != F_75 ( V_49 , V_90 ) ) ;
else
V_49 -> V_93 [ V_90 ] = V_14 ;
}
static struct V_95 * F_77 ( T_2 V_14 ,
struct V_96 * V_97 ,
int V_41 )
{
unsigned long V_98 ;
V_98 = F_78 ( V_14 , V_97 -> V_99 , V_41 ) ;
return & V_97 -> V_35 . V_100 [ V_41 - 2 ] [ V_98 ] ;
}
static void F_79 ( struct V_11 * V_11 , T_2 V_14 )
{
struct V_96 * V_97 ;
struct V_95 * V_101 ;
int V_102 ;
V_97 = F_80 ( V_11 , V_14 ) ;
for ( V_102 = V_103 ;
V_102 < V_42 + V_104 ; ++ V_102 ) {
V_101 = F_77 ( V_14 , V_97 , V_102 ) ;
V_101 -> V_105 += 1 ;
}
V_11 -> V_35 . V_106 ++ ;
}
static void F_81 ( struct V_11 * V_11 , T_2 V_14 )
{
struct V_96 * V_97 ;
struct V_95 * V_101 ;
int V_102 ;
V_97 = F_80 ( V_11 , V_14 ) ;
for ( V_102 = V_103 ;
V_102 < V_42 + V_104 ; ++ V_102 ) {
V_101 = F_77 ( V_14 , V_97 , V_102 ) ;
V_101 -> V_105 -= 1 ;
F_3 ( V_101 -> V_105 < 0 ) ;
}
V_11 -> V_35 . V_106 -- ;
}
static int F_82 ( struct V_11 * V_11 ,
T_2 V_14 ,
int V_41 )
{
struct V_96 * V_97 ;
struct V_95 * V_101 ;
V_97 = F_80 ( V_11 , V_14 ) ;
if ( V_97 ) {
V_101 = F_77 ( V_14 , V_97 , V_41 ) ;
return V_101 -> V_105 ;
}
return 1 ;
}
static int F_83 ( struct V_11 * V_11 , T_2 V_14 )
{
unsigned long V_107 ;
int V_102 , V_65 = 0 ;
V_107 = F_84 ( V_11 , V_14 ) ;
for ( V_102 = V_42 ;
V_102 < ( V_42 + V_104 ) ; ++ V_102 ) {
if ( V_107 >= F_85 ( V_102 ) )
V_65 = V_102 ;
else
break;
}
return V_65 ;
}
static struct V_96 *
F_86 ( struct V_33 * V_34 , T_2 V_14 ,
bool V_108 )
{
struct V_96 * V_97 ;
V_97 = F_80 ( V_34 -> V_11 , V_14 ) ;
if ( ! V_97 || V_97 -> V_109 & V_110 ||
( V_108 && V_97 -> V_111 ) )
V_97 = NULL ;
return V_97 ;
}
static bool F_87 ( struct V_33 * V_34 , T_2 V_112 )
{
return ! F_86 ( V_34 , V_112 , true ) ;
}
static int F_88 ( struct V_33 * V_34 , T_2 V_112 )
{
int V_113 , V_41 , V_114 ;
V_113 = F_83 ( V_34 -> V_11 , V_112 ) ;
if ( V_113 == V_42 )
return V_113 ;
V_114 = V_73 ( V_115 -> V_116 () , V_113 ) ;
for ( V_41 = V_103 ; V_41 <= V_114 ; ++ V_41 )
if ( F_82 ( V_34 -> V_11 , V_112 , V_41 ) )
break;
return V_41 - 1 ;
}
static int F_89 ( struct V_33 * V_34 , T_1 * V_10 ,
unsigned long * V_117 )
{
struct V_89 * V_118 ;
int V_102 , V_57 = 0 ;
if ( ! * V_117 ) {
F_90 ( L_1 , V_10 , * V_10 ) ;
* V_117 = ( unsigned long ) V_10 ;
} else if ( ! ( * V_117 & 1 ) ) {
F_90 ( L_2 , V_10 , * V_10 ) ;
V_118 = F_73 ( V_34 ) ;
V_118 -> V_119 [ 0 ] = ( T_1 * ) * V_117 ;
V_118 -> V_119 [ 1 ] = V_10 ;
* V_117 = ( unsigned long ) V_118 | 1 ;
++ V_57 ;
} else {
F_90 ( L_3 , V_10 , * V_10 ) ;
V_118 = (struct V_89 * ) ( * V_117 & ~ 1ul ) ;
while ( V_118 -> V_119 [ V_120 - 1 ] && V_118 -> V_121 ) {
V_118 = V_118 -> V_121 ;
V_57 += V_120 ;
}
if ( V_118 -> V_119 [ V_120 - 1 ] ) {
V_118 -> V_121 = F_73 ( V_34 ) ;
V_118 = V_118 -> V_121 ;
}
for ( V_102 = 0 ; V_118 -> V_119 [ V_102 ] ; ++ V_102 )
++ V_57 ;
V_118 -> V_119 [ V_102 ] = V_10 ;
}
return V_57 ;
}
static void
F_91 ( unsigned long * V_117 , struct V_89 * V_118 ,
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
F_74 ( V_118 ) ;
}
static void F_92 ( T_1 * V_10 , unsigned long * V_117 )
{
struct V_89 * V_118 ;
struct V_89 * V_122 ;
int V_102 ;
if ( ! * V_117 ) {
F_93 ( V_124 L_4 , V_10 ) ;
F_94 () ;
} else if ( ! ( * V_117 & 1 ) ) {
F_90 ( L_5 , V_10 ) ;
if ( ( T_1 * ) * V_117 != V_10 ) {
F_93 ( V_124 L_6 , V_10 ) ;
F_94 () ;
}
* V_117 = 0 ;
} else {
F_90 ( L_7 , V_10 ) ;
V_118 = (struct V_89 * ) ( * V_117 & ~ 1ul ) ;
V_122 = NULL ;
while ( V_118 ) {
for ( V_102 = 0 ; V_102 < V_120 && V_118 -> V_119 [ V_102 ] ; ++ V_102 )
if ( V_118 -> V_119 [ V_102 ] == V_10 ) {
F_91 ( V_117 ,
V_118 , V_102 ,
V_122 ) ;
return;
}
V_122 = V_118 ;
V_118 = V_118 -> V_121 ;
}
F_95 ( L_8 , V_10 ) ;
F_94 () ;
}
}
static void F_96 ( unsigned long * V_117 , T_5 V_125 )
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
static unsigned long * F_97 ( T_2 V_14 , int V_41 ,
struct V_96 * V_97 )
{
unsigned long V_98 ;
V_98 = F_78 ( V_14 , V_97 -> V_99 , V_41 ) ;
return & V_97 -> V_35 . V_126 [ V_41 - V_42 ] [ V_98 ] ;
}
static unsigned long * F_98 ( struct V_11 * V_11 , T_2 V_14 , int V_41 )
{
struct V_96 * V_97 ;
V_97 = F_80 ( V_11 , V_14 ) ;
return F_97 ( V_14 , V_41 , V_97 ) ;
}
static bool F_99 ( struct V_33 * V_34 )
{
struct V_69 * V_70 ;
V_70 = & V_34 -> V_35 . V_82 ;
return F_62 ( V_70 ) ;
}
static int F_100 ( struct V_33 * V_34 , T_1 * V_10 , T_2 V_14 )
{
struct V_48 * V_49 ;
unsigned long * V_127 ;
V_49 = F_36 ( F_37 ( V_10 ) ) ;
F_76 ( V_49 , V_10 - V_49 -> V_128 , V_14 ) ;
V_127 = F_98 ( V_34 -> V_11 , V_14 , V_49 -> V_91 . V_41 ) ;
return F_89 ( V_34 , V_10 , V_127 ) ;
}
static void F_101 ( struct V_11 * V_11 , T_1 * V_10 )
{
struct V_48 * V_49 ;
T_2 V_14 ;
unsigned long * V_127 ;
V_49 = F_36 ( F_37 ( V_10 ) ) ;
V_14 = F_75 ( V_49 , V_10 - V_49 -> V_128 ) ;
V_127 = F_98 ( V_11 , V_14 , V_49 -> V_91 . V_41 ) ;
F_92 ( V_10 , V_127 ) ;
}
static T_1 * F_102 ( unsigned long V_126 , struct V_129 * V_130 )
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
static T_1 * F_103 ( struct V_129 * V_130 )
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
static void F_104 ( struct V_11 * V_11 , T_1 * V_13 )
{
if ( F_48 ( V_13 ) )
F_101 ( V_11 , V_13 ) ;
}
static bool F_105 ( struct V_11 * V_11 , T_1 * V_13 )
{
if ( F_23 ( * V_13 ) ) {
F_3 ( F_36 ( F_37 ( V_13 ) ) -> V_91 . V_41 ==
V_42 ) ;
F_104 ( V_11 , V_13 ) ;
-- V_11 -> V_132 . V_133 ;
return true ;
}
return false ;
}
static void F_106 ( struct V_33 * V_34 , T_1 * V_13 )
{
if ( F_105 ( V_34 -> V_11 , V_13 ) )
F_107 ( V_34 -> V_11 ) ;
}
static bool F_108 ( struct V_11 * V_11 , T_1 * V_13 , bool V_134 )
{
T_1 V_10 = * V_13 ;
if ( ! F_42 ( V_10 ) &&
! ( V_134 && F_40 ( V_10 ) ) )
return false ;
F_90 ( L_9 , V_13 , * V_13 ) ;
if ( V_134 )
V_10 &= ~ V_61 ;
V_10 = V_10 & ~ V_135 ;
return F_45 ( V_13 , V_10 ) ;
}
static bool F_109 ( struct V_11 * V_11 , unsigned long * V_127 ,
bool V_134 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
bool V_136 = false ;
for ( V_13 = F_102 ( * V_127 , & V_130 ) ; V_13 ; ) {
F_72 ( ! ( * V_13 & V_39 ) ) ;
V_136 |= F_108 ( V_11 , V_13 , V_134 ) ;
V_13 = F_103 ( & V_130 ) ;
}
return V_136 ;
}
static bool F_110 ( struct V_11 * V_11 , T_1 * V_13 )
{
T_1 V_10 = * V_13 ;
F_90 ( L_10 , V_13 , * V_13 ) ;
V_10 &= ~ V_30 ;
return F_45 ( V_13 , V_10 ) ;
}
static bool F_111 ( struct V_11 * V_11 , unsigned long * V_127 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
bool V_136 = false ;
for ( V_13 = F_102 ( * V_127 , & V_130 ) ; V_13 ; ) {
F_72 ( ! ( * V_13 & V_39 ) ) ;
V_136 |= F_110 ( V_11 , V_13 ) ;
V_13 = F_103 ( & V_130 ) ;
}
return V_136 ;
}
static bool F_112 ( struct V_11 * V_11 , T_1 * V_13 )
{
T_1 V_10 = * V_13 ;
F_90 ( L_11 , V_13 , * V_13 ) ;
V_10 |= V_30 ;
return F_45 ( V_13 , V_10 ) ;
}
static bool F_113 ( struct V_11 * V_11 , unsigned long * V_127 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
bool V_136 = false ;
for ( V_13 = F_102 ( * V_127 , & V_130 ) ; V_13 ; ) {
F_72 ( ! ( * V_13 & V_39 ) ) ;
V_136 |= F_112 ( V_11 , V_13 ) ;
V_13 = F_103 ( & V_130 ) ;
}
return V_136 ;
}
static void F_114 ( struct V_11 * V_11 ,
struct V_96 * V_97 ,
T_2 V_137 , unsigned long V_4 )
{
unsigned long * V_127 ;
while ( V_4 ) {
V_127 = F_97 ( V_97 -> V_99 + V_137 + F_115 ( V_4 ) ,
V_42 , V_97 ) ;
F_109 ( V_11 , V_127 , false ) ;
V_4 &= V_4 - 1 ;
}
}
void F_116 ( struct V_11 * V_11 ,
struct V_96 * V_97 ,
T_2 V_137 , unsigned long V_4 )
{
unsigned long * V_127 ;
while ( V_4 ) {
V_127 = F_97 ( V_97 -> V_99 + V_137 + F_115 ( V_4 ) ,
V_42 , V_97 ) ;
F_111 ( V_11 , V_127 ) ;
V_4 &= V_4 - 1 ;
}
}
void F_117 ( struct V_11 * V_11 ,
struct V_96 * V_97 ,
T_2 V_137 , unsigned long V_4 )
{
if ( V_115 -> V_138 )
V_115 -> V_138 ( V_11 , V_97 , V_137 ,
V_4 ) ;
else
F_114 ( V_11 , V_97 , V_137 , V_4 ) ;
}
static bool F_118 ( struct V_11 * V_11 , T_1 V_14 )
{
struct V_96 * V_97 ;
unsigned long * V_127 ;
int V_102 ;
bool V_139 = false ;
V_97 = F_80 ( V_11 , V_14 ) ;
for ( V_102 = V_42 ;
V_102 < V_42 + V_104 ; ++ V_102 ) {
V_127 = F_97 ( V_14 , V_102 , V_97 ) ;
V_139 |= F_109 ( V_11 , V_127 , true ) ;
}
return V_139 ;
}
static int F_119 ( struct V_11 * V_11 , unsigned long * V_127 ,
struct V_96 * V_97 , T_2 V_14 , int V_41 ,
unsigned long V_140 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
int V_141 = 0 ;
while ( ( V_13 = F_102 ( * V_127 , & V_130 ) ) ) {
F_72 ( ! ( * V_13 & V_39 ) ) ;
F_90 ( L_12 ,
V_13 , * V_13 , V_14 , V_41 ) ;
F_104 ( V_11 , V_13 ) ;
V_141 = 1 ;
}
return V_141 ;
}
static int F_120 ( struct V_11 * V_11 , unsigned long * V_127 ,
struct V_96 * V_97 , T_2 V_14 , int V_41 ,
unsigned long V_140 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
int V_142 = 0 ;
T_1 V_63 ;
T_6 * V_143 = ( T_6 * ) V_140 ;
T_3 V_144 ;
F_3 ( F_121 ( * V_143 ) ) ;
V_144 = F_122 ( * V_143 ) ;
for ( V_13 = F_102 ( * V_127 , & V_130 ) ; V_13 ; ) {
F_72 ( ! F_22 ( * V_13 ) ) ;
F_90 ( L_13 ,
V_13 , * V_13 , V_14 , V_41 ) ;
V_142 = 1 ;
if ( F_123 ( * V_143 ) ) {
F_104 ( V_11 , V_13 ) ;
V_13 = F_102 ( * V_127 , & V_130 ) ;
} else {
V_63 = * V_13 & ~ V_43 ;
V_63 |= ( T_1 ) V_144 << V_18 ;
V_63 &= ~ V_135 ;
V_63 &= ~ V_60 ;
V_63 &= ~ V_29 ;
F_48 ( V_13 ) ;
F_9 ( V_13 , V_63 ) ;
V_13 = F_103 ( & V_130 ) ;
}
}
if ( V_142 )
F_107 ( V_11 ) ;
return 0 ;
}
static int F_124 ( struct V_11 * V_11 ,
unsigned long V_145 ,
unsigned long V_146 ,
unsigned long V_140 ,
int (* F_125)( struct V_11 * V_11 ,
unsigned long * V_127 ,
struct V_96 * V_97 ,
T_2 V_14 ,
int V_41 ,
unsigned long V_140 ) )
{
int V_123 ;
int V_65 = 0 ;
struct F_6 * V_147 ;
struct V_96 * V_148 ;
V_147 = F_6 ( V_11 ) ;
F_126 (memslot, slots) {
unsigned long V_149 , V_150 ;
T_2 V_151 , V_152 ;
V_149 = F_127 ( V_145 , V_148 -> V_153 ) ;
V_150 = V_73 ( V_146 , V_148 -> V_153 +
( V_148 -> V_154 << V_18 ) ) ;
if ( V_149 >= V_150 )
continue;
V_151 = F_128 ( V_149 , V_148 ) ;
V_152 = F_128 ( V_150 + V_155 - 1 , V_148 ) ;
for ( V_123 = V_42 ;
V_123 < V_42 + V_104 ; ++ V_123 ) {
unsigned long V_98 , V_156 ;
unsigned long * V_127 ;
T_2 V_14 = V_151 ;
V_98 = F_78 ( V_151 , V_148 -> V_99 , V_123 ) ;
V_156 = F_78 ( V_152 - 1 , V_148 -> V_99 , V_123 ) ;
V_127 = F_97 ( V_151 , V_123 , V_148 ) ;
for (; V_98 <= V_156 ;
++ V_98 , V_14 += ( 1UL << F_129 ( V_123 ) ) )
V_65 |= F_125 ( V_11 , V_127 ++ , V_148 ,
V_14 , V_123 , V_140 ) ;
}
}
return V_65 ;
}
static int F_130 ( struct V_11 * V_11 , unsigned long V_157 ,
unsigned long V_140 ,
int (* F_125)( struct V_11 * V_11 , unsigned long * V_127 ,
struct V_96 * V_97 ,
T_2 V_14 , int V_41 ,
unsigned long V_140 ) )
{
return F_124 ( V_11 , V_157 , V_157 + 1 , V_140 , F_125 ) ;
}
int F_131 ( struct V_11 * V_11 , unsigned long V_157 )
{
return F_130 ( V_11 , V_157 , 0 , F_119 ) ;
}
int F_132 ( struct V_11 * V_11 , unsigned long V_145 , unsigned long V_146 )
{
return F_124 ( V_11 , V_145 , V_146 , 0 , F_119 ) ;
}
void F_133 ( struct V_11 * V_11 , unsigned long V_157 , T_6 V_38 )
{
F_130 ( V_11 , V_157 , ( unsigned long ) & V_38 , F_120 ) ;
}
static int F_134 ( struct V_11 * V_11 , unsigned long * V_127 ,
struct V_96 * V_97 , T_2 V_14 , int V_41 ,
unsigned long V_140 )
{
T_1 * V_13 ;
struct V_129 V_158 ( V_130 ) ;
int V_159 = 0 ;
F_72 ( ! V_29 ) ;
for ( V_13 = F_102 ( * V_127 , & V_130 ) ; V_13 ;
V_13 = F_103 ( & V_130 ) ) {
F_72 ( ! F_22 ( * V_13 ) ) ;
if ( * V_13 & V_29 ) {
V_159 = 1 ;
F_135 ( ( F_136 ( V_29 ) - 1 ) ,
( unsigned long * ) V_13 ) ;
}
}
F_137 ( V_14 , V_41 , V_97 , V_159 ) ;
return V_159 ;
}
static int F_138 ( struct V_11 * V_11 , unsigned long * V_127 ,
struct V_96 * V_97 , T_2 V_14 ,
int V_41 , unsigned long V_140 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
int V_159 = 0 ;
if ( ! V_29 )
goto V_85;
for ( V_13 = F_102 ( * V_127 , & V_130 ) ; V_13 ;
V_13 = F_103 ( & V_130 ) ) {
F_72 ( ! F_22 ( * V_13 ) ) ;
if ( * V_13 & V_29 ) {
V_159 = 1 ;
break;
}
}
V_85:
return V_159 ;
}
static void F_139 ( struct V_33 * V_34 , T_1 * V_10 , T_2 V_14 )
{
unsigned long * V_127 ;
struct V_48 * V_49 ;
V_49 = F_36 ( F_37 ( V_10 ) ) ;
V_127 = F_98 ( V_34 -> V_11 , V_14 , V_49 -> V_91 . V_41 ) ;
F_119 ( V_34 -> V_11 , V_127 , NULL , V_14 , V_49 -> V_91 . V_41 , 0 ) ;
F_107 ( V_34 -> V_11 ) ;
}
int F_140 ( struct V_11 * V_11 , unsigned long V_145 , unsigned long V_146 )
{
if ( ! V_29 ) {
V_11 -> V_160 ++ ;
return F_124 ( V_11 , V_145 , V_146 , 0 ,
F_119 ) ;
}
return F_124 ( V_11 , V_145 , V_146 , 0 , F_134 ) ;
}
int F_141 ( struct V_11 * V_11 , unsigned long V_157 )
{
return F_130 ( V_11 , V_157 , 0 , F_138 ) ;
}
static int F_142 ( T_1 * V_128 )
{
T_1 * V_131 ;
T_1 * V_146 ;
for ( V_131 = V_128 , V_146 = V_131 + V_155 / sizeof( T_1 ) ; V_131 != V_146 ; V_131 ++ )
if ( F_22 ( * V_131 ) ) {
F_93 ( V_124 L_14 , V_161 ,
V_131 , * V_131 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_143 ( struct V_11 * V_11 , int V_162 )
{
V_11 -> V_35 . V_163 += V_162 ;
F_144 ( & V_164 , V_162 ) ;
}
static void F_145 ( struct V_48 * V_49 )
{
F_146 ( ! F_142 ( V_49 -> V_128 ) ) ;
F_147 ( & V_49 -> V_165 ) ;
F_148 ( & V_49 -> V_166 ) ;
F_68 ( ( unsigned long ) V_49 -> V_128 ) ;
if ( ! V_49 -> V_91 . V_92 )
F_68 ( ( unsigned long ) V_49 -> V_93 ) ;
F_64 ( V_87 , V_49 ) ;
}
static unsigned F_149 ( T_2 V_14 )
{
return V_14 & ( ( 1 << V_167 ) - 1 ) ;
}
static void F_150 ( struct V_33 * V_34 ,
struct V_48 * V_49 , T_1 * V_168 )
{
if ( ! V_168 )
return;
F_89 ( V_34 , V_168 , & V_49 -> V_169 ) ;
}
static void F_151 ( struct V_48 * V_49 ,
T_1 * V_168 )
{
F_92 ( V_168 , & V_49 -> V_169 ) ;
}
static void F_152 ( struct V_48 * V_49 ,
T_1 * V_168 )
{
F_151 ( V_49 , V_168 ) ;
F_52 ( V_168 ) ;
}
static struct V_48 * F_153 ( struct V_33 * V_34 ,
T_1 * V_168 , int V_92 )
{
struct V_48 * V_49 ;
V_49 = F_71 ( & V_34 -> V_35 . V_87 ) ;
V_49 -> V_128 = F_71 ( & V_34 -> V_35 . V_86 ) ;
if ( ! V_92 )
V_49 -> V_93 = F_71 ( & V_34 -> V_35 . V_86 ) ;
F_154 ( F_155 ( V_49 -> V_128 ) , ( unsigned long ) V_49 ) ;
F_156 ( & V_49 -> V_166 , & V_34 -> V_11 -> V_35 . V_170 ) ;
V_49 -> V_169 = 0 ;
F_150 ( V_34 , V_49 , V_168 ) ;
F_143 ( V_34 -> V_11 , + 1 ) ;
return V_49 ;
}
static void F_157 ( struct V_48 * V_49 )
{
F_96 ( & V_49 -> V_169 , V_171 ) ;
}
static void V_171 ( T_1 * V_10 )
{
struct V_48 * V_49 ;
unsigned int V_90 ;
V_49 = F_36 ( F_37 ( V_10 ) ) ;
V_90 = V_10 - V_49 -> V_128 ;
if ( F_158 ( V_90 , V_49 -> V_172 ) )
return;
if ( V_49 -> V_173 ++ )
return;
F_157 ( V_49 ) ;
}
static int F_159 ( struct V_33 * V_34 ,
struct V_48 * V_49 )
{
return 1 ;
}
static void F_160 ( struct V_33 * V_34 , T_7 V_174 )
{
}
static void F_161 ( struct V_33 * V_34 ,
struct V_48 * V_49 , T_1 * V_10 ,
const void * V_38 )
{
F_3 ( 1 ) ;
}
static int F_162 ( struct V_175 * V_176 , struct V_48 * V_49 ,
int V_98 )
{
int V_102 ;
if ( V_49 -> V_177 )
for ( V_102 = 0 ; V_102 < V_176 -> V_162 ; V_102 ++ )
if ( V_176 -> V_80 [ V_102 ] . V_49 == V_49 )
return 0 ;
V_176 -> V_80 [ V_176 -> V_162 ] . V_49 = V_49 ;
V_176 -> V_80 [ V_176 -> V_162 ] . V_98 = V_98 ;
V_176 -> V_162 ++ ;
return ( V_176 -> V_162 == V_178 ) ;
}
static int F_163 ( struct V_48 * V_49 ,
struct V_175 * V_176 )
{
int V_102 , V_65 , V_179 = 0 ;
F_164 (i, sp->unsync_child_bitmap, 512 ) {
struct V_48 * V_180 ;
T_1 V_181 = V_49 -> V_128 [ V_102 ] ;
if ( ! F_22 ( V_181 ) || F_23 ( V_181 ) )
goto V_182;
V_180 = F_36 ( V_181 & V_43 ) ;
if ( V_180 -> V_173 ) {
if ( F_162 ( V_176 , V_180 , V_102 ) )
return - V_183 ;
V_65 = F_163 ( V_180 , V_176 ) ;
if ( ! V_65 )
goto V_182;
else if ( V_65 > 0 )
V_179 += V_65 ;
else
return V_65 ;
} else if ( V_180 -> V_177 ) {
V_179 ++ ;
if ( F_162 ( V_176 , V_180 , V_102 ) )
return - V_183 ;
} else
goto V_182;
continue;
V_182:
F_165 ( V_102 , V_49 -> V_172 ) ;
V_49 -> V_173 -- ;
F_3 ( ( int ) V_49 -> V_173 < 0 ) ;
}
return V_179 ;
}
static int F_166 ( struct V_48 * V_49 ,
struct V_175 * V_176 )
{
if ( ! V_49 -> V_173 )
return 0 ;
F_162 ( V_176 , V_49 , 0 ) ;
return F_163 ( V_49 , V_176 ) ;
}
static void F_167 ( struct V_11 * V_11 , struct V_48 * V_49 )
{
F_3 ( ! V_49 -> V_177 ) ;
F_168 ( V_49 ) ;
V_49 -> V_177 = 0 ;
-- V_11 -> V_132 . V_184 ;
}
static int F_169 ( struct V_33 * V_34 , struct V_48 * V_49 ,
struct V_185 * V_186 , bool V_187 )
{
if ( V_49 -> V_91 . V_188 != ! ! F_170 ( V_34 ) ) {
F_171 ( V_34 -> V_11 , V_49 , V_186 ) ;
return 1 ;
}
if ( V_187 )
F_167 ( V_34 -> V_11 , V_49 ) ;
if ( V_34 -> V_35 . V_189 . V_190 ( V_34 , V_49 ) ) {
F_171 ( V_34 -> V_11 , V_49 , V_186 ) ;
return 1 ;
}
F_172 ( V_191 , V_34 ) ;
return 0 ;
}
static int F_173 ( struct V_33 * V_34 ,
struct V_48 * V_49 )
{
F_174 ( V_186 ) ;
int V_65 ;
V_65 = F_169 ( V_34 , V_49 , & V_186 , false ) ;
if ( V_65 )
F_175 ( V_34 -> V_11 , & V_186 ) ;
return V_65 ;
}
static void F_176 ( struct V_33 * V_34 , int V_192 ) { }
static void F_177 ( void ) { }
static int F_178 ( struct V_33 * V_34 , struct V_48 * V_49 ,
struct V_185 * V_186 )
{
return F_169 ( V_34 , V_49 , V_186 , true ) ;
}
static void F_179 ( struct V_33 * V_34 , T_2 V_14 )
{
struct V_48 * V_193 ;
F_174 ( V_186 ) ;
bool V_136 = false ;
F_180 (vcpu->kvm, s, gfn) {
if ( ! V_193 -> V_177 )
continue;
F_3 ( V_193 -> V_91 . V_41 != V_42 ) ;
F_167 ( V_34 -> V_11 , V_193 ) ;
if ( ( V_193 -> V_91 . V_188 != ! ! F_170 ( V_34 ) ) ||
( V_34 -> V_35 . V_189 . V_190 ( V_34 , V_193 ) ) ) {
F_171 ( V_34 -> V_11 , V_193 , & V_186 ) ;
continue;
}
V_136 = true ;
}
F_175 ( V_34 -> V_11 , & V_186 ) ;
if ( V_136 )
F_172 ( V_191 , V_34 ) ;
}
static int F_181 ( struct V_175 * V_176 ,
struct V_194 * V_195 ,
int V_102 )
{
int V_196 ;
for ( V_196 = V_102 + 1 ; V_196 < V_176 -> V_162 ; V_196 ++ ) {
struct V_48 * V_49 = V_176 -> V_80 [ V_196 ] . V_49 ;
if ( V_49 -> V_91 . V_41 == V_42 ) {
V_195 -> V_98 [ 0 ] = V_176 -> V_80 [ V_196 ] . V_98 ;
return V_196 ;
}
V_195 -> V_197 [ V_49 -> V_91 . V_41 - 2 ] = V_49 ;
V_195 -> V_98 [ V_49 -> V_91 . V_41 - 1 ] = V_176 -> V_80 [ V_196 ] . V_98 ;
}
return V_196 ;
}
static void F_182 ( struct V_194 * V_195 )
{
struct V_48 * V_49 ;
unsigned int V_41 = 0 ;
do {
unsigned int V_98 = V_195 -> V_98 [ V_41 ] ;
V_49 = V_195 -> V_197 [ V_41 ] ;
if ( ! V_49 )
return;
-- V_49 -> V_173 ;
F_3 ( ( int ) V_49 -> V_173 < 0 ) ;
F_165 ( V_98 , V_49 -> V_172 ) ;
V_41 ++ ;
} while ( V_41 < V_198 - 1 && ! V_49 -> V_173 );
}
static void F_183 ( struct V_48 * V_197 ,
struct V_194 * V_195 ,
struct V_175 * V_176 )
{
V_195 -> V_197 [ V_197 -> V_91 . V_41 - 1 ] = NULL ;
V_176 -> V_162 = 0 ;
}
static void F_184 ( struct V_33 * V_34 ,
struct V_48 * V_197 )
{
int V_102 ;
struct V_48 * V_49 ;
struct V_194 V_195 ;
struct V_175 V_199 ;
F_174 ( V_186 ) ;
F_183 ( V_197 , & V_195 , & V_199 ) ;
while ( F_166 ( V_197 , & V_199 ) ) {
bool V_200 = false ;
F_185 (pages, sp, parents, i)
V_200 |= F_118 ( V_34 -> V_11 , V_49 -> V_14 ) ;
if ( V_200 )
F_107 ( V_34 -> V_11 ) ;
F_185 (pages, sp, parents, i) {
F_178 ( V_34 , V_49 , & V_186 ) ;
F_182 ( & V_195 ) ;
}
F_175 ( V_34 -> V_11 , & V_186 ) ;
F_186 ( & V_34 -> V_11 -> V_201 ) ;
F_183 ( V_197 , & V_195 , & V_199 ) ;
}
}
static void F_187 ( struct V_48 * V_49 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_202 ; ++ V_102 )
V_49 -> V_128 [ V_102 ] = 0ull ;
}
static void F_188 ( struct V_48 * V_49 )
{
V_49 -> V_203 = 0 ;
}
static void F_189 ( T_1 * V_10 )
{
struct V_48 * V_49 = F_36 ( F_37 ( V_10 ) ) ;
F_188 ( V_49 ) ;
}
static bool F_190 ( struct V_11 * V_11 , struct V_48 * V_49 )
{
return F_14 ( V_49 -> V_204 != V_11 -> V_35 . V_204 ) ;
}
static struct V_48 * F_191 ( struct V_33 * V_34 ,
T_2 V_14 ,
T_7 V_205 ,
unsigned V_41 ,
int V_92 ,
unsigned V_15 ,
T_1 * V_168 )
{
union V_206 V_91 ;
unsigned V_207 ;
struct V_48 * V_49 ;
bool V_208 = false ;
V_91 = V_34 -> V_35 . V_189 . V_209 ;
V_91 . V_41 = V_41 ;
V_91 . V_92 = V_92 ;
if ( V_91 . V_92 )
V_91 . V_188 = 0 ;
V_91 . V_15 = V_15 ;
if ( ! V_34 -> V_35 . V_189 . V_210
&& V_34 -> V_35 . V_189 . V_211 <= V_212 ) {
V_207 = V_205 >> ( V_18 + ( V_213 * V_41 ) ) ;
V_207 &= ( 1 << ( ( V_214 - V_213 ) * V_41 ) ) - 1 ;
V_91 . V_207 = V_207 ;
}
F_192 (vcpu->kvm, sp, gfn) {
if ( F_190 ( V_34 -> V_11 , V_49 ) )
continue;
if ( ! V_208 && V_49 -> V_177 )
V_208 = true ;
if ( V_49 -> V_91 . V_215 != V_91 . V_215 )
continue;
if ( V_49 -> V_177 && F_173 ( V_34 , V_49 ) )
break;
F_150 ( V_34 , V_49 , V_168 ) ;
if ( V_49 -> V_173 ) {
F_172 ( V_216 , V_34 ) ;
F_157 ( V_49 ) ;
} else if ( V_49 -> V_177 )
F_157 ( V_49 ) ;
F_188 ( V_49 ) ;
F_193 ( V_49 , false ) ;
return V_49 ;
}
++ V_34 -> V_11 -> V_132 . V_217 ;
V_49 = F_153 ( V_34 , V_168 , V_92 ) ;
if ( ! V_49 )
return V_49 ;
V_49 -> V_14 = V_14 ;
V_49 -> V_91 = V_91 ;
F_194 ( & V_49 -> V_165 ,
& V_34 -> V_11 -> V_35 . V_218 [ F_149 ( V_14 ) ] ) ;
if ( ! V_92 ) {
if ( F_118 ( V_34 -> V_11 , V_14 ) )
F_107 ( V_34 -> V_11 ) ;
if ( V_41 > V_42 && V_208 )
F_179 ( V_34 , V_14 ) ;
F_79 ( V_34 -> V_11 , V_14 ) ;
}
V_49 -> V_204 = V_34 -> V_11 -> V_35 . V_204 ;
F_187 ( V_49 ) ;
F_193 ( V_49 , true ) ;
return V_49 ;
}
static void F_195 ( struct V_219 * V_220 ,
struct V_33 * V_34 , T_1 V_221 )
{
V_220 -> V_221 = V_221 ;
V_220 -> V_222 = V_34 -> V_35 . V_189 . V_223 ;
V_220 -> V_41 = V_34 -> V_35 . V_189 . V_224 ;
if ( V_220 -> V_41 == V_198 &&
V_34 -> V_35 . V_189 . V_211 < V_198 &&
! V_34 -> V_35 . V_189 . V_210 )
-- V_220 -> V_41 ;
if ( V_220 -> V_41 == V_225 ) {
V_220 -> V_222
= V_34 -> V_35 . V_189 . V_226 [ ( V_221 >> 30 ) & 3 ] ;
V_220 -> V_222 &= V_43 ;
-- V_220 -> V_41 ;
if ( ! V_220 -> V_222 )
V_220 -> V_41 = 0 ;
}
}
static bool F_196 ( struct V_219 * V_220 )
{
if ( V_220 -> V_41 < V_42 )
return false ;
V_220 -> V_90 = F_197 ( V_220 -> V_221 , V_220 -> V_41 ) ;
V_220 -> V_13 = ( ( T_1 * ) F_198 ( V_220 -> V_222 ) ) + V_220 -> V_90 ;
return true ;
}
static void F_199 ( struct V_219 * V_220 ,
T_1 V_10 )
{
if ( F_25 ( V_10 , V_220 -> V_41 ) ) {
V_220 -> V_41 = 0 ;
return;
}
V_220 -> V_222 = V_10 & V_43 ;
-- V_220 -> V_41 ;
}
static void F_200 ( struct V_219 * V_220 )
{
return F_199 ( V_220 , * V_220 -> V_13 ) ;
}
static void F_201 ( T_1 * V_13 , struct V_48 * V_49 , bool V_227 )
{
T_1 V_10 ;
F_202 ( V_228 != V_39 ||
V_229 != V_135 ) ;
V_10 = F_37 ( V_49 -> V_128 ) | V_39 | V_135 |
V_28 | V_32 ;
if ( V_227 )
V_10 |= V_29 ;
F_9 ( V_13 , V_10 ) ;
}
static void F_203 ( struct V_33 * V_34 , T_1 * V_13 ,
unsigned V_230 )
{
if ( F_22 ( * V_13 ) && ! F_23 ( * V_13 ) ) {
struct V_48 * V_180 ;
V_180 = F_36 ( * V_13 & V_43 ) ;
if ( V_180 -> V_91 . V_15 == V_230 )
return;
F_152 ( V_180 , V_13 ) ;
F_107 ( V_34 -> V_11 ) ;
}
}
static bool F_204 ( struct V_11 * V_11 , struct V_48 * V_49 ,
T_1 * V_10 )
{
T_1 V_38 ;
struct V_48 * V_180 ;
V_38 = * V_10 ;
if ( F_22 ( V_38 ) ) {
if ( F_25 ( V_38 , V_49 -> V_91 . V_41 ) ) {
F_104 ( V_11 , V_10 ) ;
if ( F_23 ( V_38 ) )
-- V_11 -> V_132 . V_133 ;
} else {
V_180 = F_36 ( V_38 & V_43 ) ;
F_152 ( V_180 , V_10 ) ;
}
return true ;
}
if ( F_10 ( V_38 ) )
F_52 ( V_10 ) ;
return false ;
}
static void F_205 ( struct V_11 * V_11 ,
struct V_48 * V_49 )
{
unsigned V_102 ;
for ( V_102 = 0 ; V_102 < V_202 ; ++ V_102 )
F_204 ( V_11 , V_49 , V_49 -> V_128 + V_102 ) ;
}
static void F_206 ( struct V_48 * V_49 , T_1 * V_168 )
{
F_151 ( V_49 , V_168 ) ;
}
static void F_207 ( struct V_11 * V_11 , struct V_48 * V_49 )
{
T_1 * V_13 ;
struct V_129 V_130 ;
while ( ( V_13 = F_102 ( V_49 -> V_169 , & V_130 ) ) )
F_152 ( V_49 , V_13 ) ;
}
static int F_208 ( struct V_11 * V_11 ,
struct V_48 * V_197 ,
struct V_185 * V_186 )
{
int V_102 , V_231 = 0 ;
struct V_194 V_195 ;
struct V_175 V_199 ;
if ( V_197 -> V_91 . V_41 == V_42 )
return 0 ;
F_183 ( V_197 , & V_195 , & V_199 ) ;
while ( F_166 ( V_197 , & V_199 ) ) {
struct V_48 * V_49 ;
F_185 (pages, sp, parents, i) {
F_171 ( V_11 , V_49 , V_186 ) ;
F_182 ( & V_195 ) ;
V_231 ++ ;
}
F_183 ( V_197 , & V_195 , & V_199 ) ;
}
return V_231 ;
}
static int F_171 ( struct V_11 * V_11 , struct V_48 * V_49 ,
struct V_185 * V_186 )
{
int V_65 ;
F_209 ( V_49 ) ;
++ V_11 -> V_132 . V_232 ;
V_65 = F_208 ( V_11 , V_49 , V_186 ) ;
F_205 ( V_11 , V_49 ) ;
F_207 ( V_11 , V_49 ) ;
if ( ! V_49 -> V_91 . V_233 && ! V_49 -> V_91 . V_92 )
F_81 ( V_11 , V_49 -> V_14 ) ;
if ( V_49 -> V_177 )
F_167 ( V_11 , V_49 ) ;
if ( ! V_49 -> V_234 ) {
V_65 ++ ;
F_210 ( & V_49 -> V_166 , V_186 ) ;
F_143 ( V_11 , - 1 ) ;
} else {
F_210 ( & V_49 -> V_166 , & V_11 -> V_35 . V_170 ) ;
if ( ! V_49 -> V_91 . V_233 && ! F_190 ( V_11 , V_49 ) )
F_211 ( V_11 ) ;
}
V_49 -> V_91 . V_233 = 1 ;
return V_65 ;
}
static void F_175 ( struct V_11 * V_11 ,
struct V_185 * V_186 )
{
struct V_48 * V_49 , * V_235 ;
if ( F_212 ( V_186 ) )
return;
F_56 () ;
F_107 ( V_11 ) ;
F_213 (sp, nsp, invalid_list, link) {
F_3 ( ! V_49 -> V_91 . V_233 || V_49 -> V_234 ) ;
F_145 ( V_49 ) ;
}
}
static bool F_214 ( struct V_11 * V_11 ,
struct V_185 * V_186 )
{
struct V_48 * V_49 ;
if ( F_212 ( & V_11 -> V_35 . V_170 ) )
return false ;
V_49 = F_215 ( V_11 -> V_35 . V_170 . V_236 ,
struct V_48 , V_166 ) ;
F_171 ( V_11 , V_49 , V_186 ) ;
return true ;
}
void F_216 ( struct V_11 * V_11 , unsigned int V_237 )
{
F_174 ( V_186 ) ;
F_217 ( & V_11 -> V_201 ) ;
if ( V_11 -> V_35 . V_163 > V_237 ) {
while ( V_11 -> V_35 . V_163 > V_237 )
if ( ! F_214 ( V_11 , & V_186 ) )
break;
F_175 ( V_11 , & V_186 ) ;
V_237 = V_11 -> V_35 . V_163 ;
}
V_11 -> V_35 . V_238 = V_237 ;
F_218 ( & V_11 -> V_201 ) ;
}
int F_219 ( struct V_11 * V_11 , T_2 V_14 )
{
struct V_48 * V_49 ;
F_174 ( V_186 ) ;
int V_81 ;
F_220 ( L_15 , V_161 , V_14 ) ;
V_81 = 0 ;
F_217 ( & V_11 -> V_201 ) ;
F_180 (kvm, sp, gfn) {
F_220 ( L_16 , V_161 , V_14 ,
V_49 -> V_91 . V_215 ) ;
V_81 = 1 ;
F_171 ( V_11 , V_49 , & V_186 ) ;
}
F_175 ( V_11 , & V_186 ) ;
F_218 ( & V_11 -> V_201 ) ;
return V_81 ;
}
static int F_221 ( struct V_239 * V_240 ,
T_1 V_145 , T_1 V_146 )
{
int V_102 ;
T_1 V_241 , V_4 ;
T_8 V_242 , V_243 ;
int V_244 = V_245 ;
if ( ! V_240 -> V_246 )
return 0xFF ;
V_146 -- ;
if ( V_240 -> V_247 && ( V_145 < 0x100000 ) ) {
int V_98 ;
if ( V_145 < 0x80000 ) {
V_98 = 0 ;
V_98 += ( V_145 >> 16 ) ;
return V_240 -> V_248 [ V_98 ] ;
} else if ( V_145 < 0xC0000 ) {
V_98 = 1 * 8 ;
V_98 += ( ( V_145 - 0x80000 ) >> 14 ) ;
return V_240 -> V_248 [ V_98 ] ;
} else if ( V_145 < 0x1000000 ) {
V_98 = 3 * 8 ;
V_98 += ( ( V_145 - 0xC0000 ) >> 12 ) ;
return V_240 -> V_248 [ V_98 ] ;
}
}
if ( ! ( V_240 -> V_246 & 2 ) )
return V_240 -> V_249 ;
V_242 = 0xFF ;
for ( V_102 = 0 ; V_102 < V_244 ; ++ V_102 ) {
unsigned short V_250 , V_251 ;
if ( ! ( V_240 -> V_252 [ V_102 ] . V_253 & ( 1 << 11 ) ) )
continue;
V_241 = ( ( ( T_1 ) V_240 -> V_252 [ V_102 ] . V_254 ) << 32 ) +
( V_240 -> V_252 [ V_102 ] . V_255 & V_19 ) ;
V_4 = ( ( ( T_1 ) V_240 -> V_252 [ V_102 ] . V_256 ) << 32 ) +
( V_240 -> V_252 [ V_102 ] . V_253 & V_19 ) ;
V_250 = ( ( V_145 & V_4 ) == ( V_241 & V_4 ) ) ;
V_251 = ( ( V_146 & V_4 ) == ( V_241 & V_4 ) ) ;
if ( V_250 != V_251 )
return 0xFE ;
if ( ( V_145 & V_4 ) != ( V_241 & V_4 ) )
continue;
V_243 = V_240 -> V_252 [ V_102 ] . V_255 & 0xff ;
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
T_8 F_222 ( struct V_33 * V_34 , T_2 V_14 )
{
T_8 V_260 ;
V_260 = F_221 ( & V_34 -> V_35 . V_240 , V_14 << V_18 ,
( V_14 << V_18 ) + V_155 ) ;
if ( V_260 == 0xfe || V_260 == 0xff )
V_260 = V_258 ;
return V_260 ;
}
static void F_223 ( struct V_33 * V_34 , struct V_48 * V_49 )
{
F_224 ( V_49 ) ;
++ V_34 -> V_11 -> V_132 . V_184 ;
V_49 -> V_177 = 1 ;
F_157 ( V_49 ) ;
}
static void F_225 ( struct V_33 * V_34 , T_2 V_14 )
{
struct V_48 * V_193 ;
F_180 (vcpu->kvm, s, gfn) {
if ( V_193 -> V_177 )
continue;
F_3 ( V_193 -> V_91 . V_41 != V_42 ) ;
F_223 ( V_34 , V_193 ) ;
}
}
static int F_226 ( struct V_33 * V_34 , T_2 V_14 ,
bool V_261 )
{
struct V_48 * V_193 ;
bool V_262 = false ;
F_180 (vcpu->kvm, s, gfn) {
if ( ! V_261 )
return 1 ;
if ( V_193 -> V_91 . V_41 != V_42 )
return 1 ;
if ( ! V_193 -> V_177 )
V_262 = true ;
}
if ( V_262 )
F_225 ( V_34 , V_14 ) ;
return 0 ;
}
static int F_227 ( struct V_33 * V_34 , T_1 * V_13 ,
unsigned V_263 , int V_41 ,
T_2 V_14 , T_3 V_20 , bool V_264 ,
bool V_261 , bool V_265 )
{
T_1 V_10 ;
int V_65 = 0 ;
if ( F_13 ( V_34 -> V_11 , V_13 , V_14 , V_20 , V_263 ) )
return 0 ;
V_10 = V_39 ;
if ( ! V_264 )
V_10 |= V_29 ;
if ( V_263 & V_266 )
V_10 |= V_32 ;
else
V_10 |= V_31 ;
if ( V_263 & V_17 )
V_10 |= V_28 ;
if ( V_41 > V_42 )
V_10 |= V_40 ;
if ( V_267 )
V_10 |= V_115 -> V_268 ( V_34 , V_14 ,
F_49 ( V_20 ) ) ;
if ( V_265 )
V_10 |= V_60 ;
else
V_263 &= ~ V_16 ;
V_10 |= ( T_1 ) V_20 << V_18 ;
if ( V_263 & V_16 ) {
if ( V_41 > V_42 &&
F_82 ( V_34 -> V_11 , V_14 , V_41 ) )
goto V_269;
V_10 |= V_135 | V_61 ;
if ( ! V_261 && F_42 ( * V_13 ) )
goto V_270;
if ( F_226 ( V_34 , V_14 , V_261 ) ) {
F_220 ( L_17 ,
V_161 , V_14 ) ;
V_65 = 1 ;
V_263 &= ~ V_16 ;
V_10 &= ~ ( V_135 | V_61 ) ;
}
}
if ( V_263 & V_16 ) {
F_228 ( V_34 -> V_11 , V_14 ) ;
V_10 |= V_30 ;
}
V_270:
if ( F_45 ( V_13 , V_10 ) )
F_107 ( V_34 -> V_11 ) ;
V_269:
return V_65 ;
}
static void F_229 ( struct V_33 * V_34 , T_1 * V_13 ,
unsigned V_263 , int V_271 , int * V_272 ,
int V_41 , T_2 V_14 , T_3 V_20 , bool V_264 ,
bool V_265 )
{
int V_273 = 0 ;
int V_274 ;
F_220 ( L_18 , V_161 ,
* V_13 , V_271 , V_14 ) ;
if ( F_24 ( * V_13 ) ) {
if ( V_41 > V_42 &&
! F_23 ( * V_13 ) ) {
struct V_48 * V_180 ;
T_1 V_38 = * V_13 ;
V_180 = F_36 ( V_38 & V_43 ) ;
F_152 ( V_180 , V_13 ) ;
F_107 ( V_34 -> V_11 ) ;
} else if ( V_20 != F_26 ( * V_13 ) ) {
F_220 ( L_19 ,
F_26 ( * V_13 ) , V_20 ) ;
F_104 ( V_34 -> V_11 , V_13 ) ;
F_107 ( V_34 -> V_11 ) ;
} else
V_273 = 1 ;
}
if ( F_227 ( V_34 , V_13 , V_263 , V_41 , V_14 , V_20 , V_264 ,
true , V_265 ) ) {
if ( V_271 )
* V_272 = 1 ;
F_172 ( V_191 , V_34 ) ;
}
if ( F_14 ( F_10 ( * V_13 ) && V_272 ) )
* V_272 = 1 ;
F_220 ( L_20 , V_161 , * V_13 ) ;
F_220 ( L_21 ,
F_23 ( * V_13 ) ? L_22 : L_23 ,
* V_13 & V_39 ? L_24 : L_25 , V_14 ,
* V_13 , V_13 ) ;
if ( ! V_273 && F_23 ( * V_13 ) )
++ V_34 -> V_11 -> V_132 . V_133 ;
if ( F_22 ( * V_13 ) ) {
if ( ! V_273 ) {
V_274 = F_100 ( V_34 , V_13 , V_14 ) ;
if ( V_274 > V_275 )
F_139 ( V_34 , V_13 , V_14 ) ;
}
}
F_230 ( V_20 ) ;
}
static T_3 F_231 ( struct V_33 * V_34 , T_2 V_14 ,
bool V_108 )
{
struct V_96 * V_97 ;
V_97 = F_86 ( V_34 , V_14 , V_108 ) ;
if ( ! V_97 )
return V_276 ;
return F_232 ( V_97 , V_14 ) ;
}
static int F_233 ( struct V_33 * V_34 ,
struct V_48 * V_49 ,
T_1 * V_145 , T_1 * V_146 )
{
struct V_80 * V_199 [ V_84 ] ;
unsigned V_15 = V_49 -> V_91 . V_15 ;
int V_102 , V_65 ;
T_2 V_14 ;
V_14 = F_75 ( V_49 , V_145 - V_49 -> V_128 ) ;
if ( ! F_86 ( V_34 , V_14 , V_15 & V_16 ) )
return - 1 ;
V_65 = F_234 ( V_34 -> V_11 , V_14 , V_199 , V_146 - V_145 ) ;
if ( V_65 <= 0 )
return - 1 ;
for ( V_102 = 0 ; V_102 < V_65 ; V_102 ++ , V_14 ++ , V_145 ++ )
F_229 ( V_34 , V_145 , V_15 , 0 , NULL ,
V_49 -> V_91 . V_41 , V_14 , F_235 ( V_199 [ V_102 ] ) ,
true , true ) ;
return 0 ;
}
static void F_236 ( struct V_33 * V_34 ,
struct V_48 * V_49 , T_1 * V_13 )
{
T_1 * V_10 , * V_145 = NULL ;
int V_102 ;
F_3 ( ! V_49 -> V_91 . V_92 ) ;
V_102 = ( V_13 - V_49 -> V_128 ) & ~ ( V_84 - 1 ) ;
V_10 = V_49 -> V_128 + V_102 ;
for ( V_102 = 0 ; V_102 < V_84 ; V_102 ++ , V_10 ++ ) {
if ( F_22 ( * V_10 ) || V_10 == V_13 ) {
if ( ! V_145 )
continue;
if ( F_233 ( V_34 , V_49 , V_145 , V_10 ) < 0 )
break;
V_145 = NULL ;
} else if ( ! V_145 )
V_145 = V_10 ;
}
}
static void F_237 ( struct V_33 * V_34 , T_1 * V_13 )
{
struct V_48 * V_49 ;
if ( ! V_29 )
return;
V_49 = F_36 ( F_37 ( V_13 ) ) ;
if ( V_49 -> V_91 . V_41 > V_42 )
return;
F_236 ( V_34 , V_49 , V_13 ) ;
}
static int F_238 ( struct V_33 * V_34 , T_9 V_277 , int V_278 ,
int V_279 , int V_41 , T_2 V_14 , T_3 V_20 ,
bool V_280 )
{
struct V_219 V_220 ;
struct V_48 * V_49 ;
int V_272 = 0 ;
T_2 V_281 ;
if ( ! F_239 ( V_34 -> V_35 . V_189 . V_223 ) )
return 0 ;
F_240 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_220 . V_41 == V_41 ) {
F_229 ( V_34 , V_220 . V_13 , V_282 ,
V_278 , & V_272 , V_41 , V_14 , V_20 ,
V_280 , V_279 ) ;
F_237 ( V_34 , V_220 . V_13 ) ;
++ V_34 -> V_132 . V_283 ;
break;
}
F_106 ( V_34 , V_220 . V_13 ) ;
if ( ! F_22 ( * V_220 . V_13 ) ) {
T_1 V_284 = V_220 . V_221 ;
V_284 &= F_241 ( V_220 . V_41 ) ;
V_281 = V_284 >> V_18 ;
V_49 = F_191 ( V_34 , V_281 , V_220 . V_221 ,
V_220 . V_41 - 1 ,
1 , V_282 , V_220 . V_13 ) ;
F_201 ( V_220 . V_13 , V_49 , true ) ;
}
}
return V_272 ;
}
static void F_242 ( unsigned long V_285 , struct V_286 * V_287 )
{
T_10 V_288 ;
V_288 . V_289 = V_290 ;
V_288 . V_291 = 0 ;
V_288 . V_292 = V_293 ;
V_288 . V_294 = ( void V_295 * ) V_285 ;
V_288 . V_296 = V_18 ;
F_243 ( V_290 , & V_288 , V_287 ) ;
}
static int F_244 ( struct V_33 * V_34 , T_2 V_14 , T_3 V_20 )
{
if ( V_20 == V_297 )
return 1 ;
if ( V_20 == V_298 ) {
F_242 ( F_245 ( V_34 -> V_11 , V_14 ) , V_299 ) ;
return 0 ;
}
return - V_300 ;
}
static void F_246 ( struct V_33 * V_34 ,
T_2 * V_301 , T_3 * V_302 , int * V_303 )
{
T_3 V_20 = * V_302 ;
T_2 V_14 = * V_301 ;
int V_41 = * V_303 ;
if ( ! F_247 ( V_20 ) && ! F_49 ( V_20 ) &&
V_41 == V_42 &&
F_248 ( F_51 ( V_20 ) ) &&
! F_82 ( V_34 -> V_11 , V_14 , V_103 ) ) {
unsigned long V_4 ;
* V_303 = V_41 = V_103 ;
V_4 = F_249 ( V_41 ) - 1 ;
F_250 ( ( V_14 & V_4 ) != ( V_20 & V_4 ) ) ;
if ( V_20 & V_4 ) {
V_14 &= ~ V_4 ;
* V_301 = V_14 ;
F_230 ( V_20 ) ;
V_20 &= ~ V_4 ;
F_251 ( V_20 ) ;
* V_302 = V_20 ;
}
}
}
static bool F_252 ( struct V_33 * V_34 , T_7 V_174 , T_2 V_14 ,
T_3 V_20 , unsigned V_15 , int * V_304 )
{
bool V_65 = true ;
if ( F_14 ( F_253 ( V_20 ) ) ) {
* V_304 = F_244 ( V_34 , V_14 , V_20 ) ;
goto exit;
}
if ( F_14 ( F_15 ( V_20 ) ) )
F_254 ( V_34 , V_174 , V_14 , V_15 ) ;
V_65 = false ;
exit:
return V_65 ;
}
static bool F_255 ( T_4 V_305 )
{
if ( F_14 ( V_305 & V_306 ) )
return false ;
if ( ! ( V_305 & V_307 ) ||
! ( V_305 & V_308 ) )
return false ;
return true ;
}
static bool
F_256 ( struct V_33 * V_34 , struct V_48 * V_49 ,
T_1 * V_13 , T_1 V_10 )
{
T_2 V_14 ;
F_3 ( ! V_49 -> V_91 . V_92 ) ;
V_14 = F_75 ( V_49 , V_13 - V_49 -> V_128 ) ;
if ( F_257 ( V_13 , V_10 , V_10 | V_135 ) == V_10 )
F_228 ( V_34 -> V_11 , V_14 ) ;
return true ;
}
static bool F_258 ( struct V_33 * V_34 , T_7 V_174 , int V_41 ,
T_4 V_305 )
{
struct V_219 V_220 ;
struct V_48 * V_49 ;
bool V_65 = false ;
T_1 V_10 = 0ull ;
if ( ! F_239 ( V_34 -> V_35 . V_189 . V_223 ) )
return false ;
if ( ! F_255 ( V_305 ) )
return false ;
F_54 ( V_34 ) ;
F_259 (vcpu, gva, iterator, spte)
if ( ! F_22 ( V_10 ) || V_220 . V_41 < V_41 )
break;
if ( ! F_24 ( V_10 ) ) {
V_65 = true ;
goto exit;
}
V_49 = F_36 ( F_37 ( V_220 . V_13 ) ) ;
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
V_65 = F_256 ( V_34 , V_49 , V_220 . V_13 , V_10 ) ;
exit:
F_260 ( V_34 , V_174 , V_305 , V_220 . V_13 ,
V_10 , V_65 ) ;
F_57 ( V_34 ) ;
return V_65 ;
}
static int F_261 ( struct V_33 * V_34 , T_7 V_277 , T_4 V_305 ,
T_2 V_14 , bool V_280 )
{
int V_81 ;
int V_41 ;
int V_309 ;
T_3 V_20 ;
unsigned long V_310 ;
bool V_279 , V_278 = V_305 & V_308 ;
V_309 = F_87 ( V_34 , V_14 ) ;
if ( F_18 ( ! V_309 ) ) {
V_41 = F_88 ( V_34 , V_14 ) ;
if ( V_41 > V_103 )
V_41 = V_103 ;
V_14 &= ~ ( F_249 ( V_41 ) - 1 ) ;
} else
V_41 = V_42 ;
if ( F_258 ( V_34 , V_277 , V_41 , V_305 ) )
return 0 ;
V_310 = V_34 -> V_11 -> V_160 ;
F_39 () ;
if ( F_262 ( V_34 , V_280 , V_14 , V_277 , & V_20 , V_278 , & V_279 ) )
return 0 ;
if ( F_252 ( V_34 , V_277 , V_14 , V_20 , V_282 , & V_81 ) )
return V_81 ;
F_217 ( & V_34 -> V_11 -> V_201 ) ;
if ( F_263 ( V_34 -> V_11 , V_310 ) )
goto V_311;
F_264 ( V_34 ) ;
if ( F_18 ( ! V_309 ) )
F_246 ( V_34 , & V_14 , & V_20 , & V_41 ) ;
V_81 = F_238 ( V_34 , V_277 , V_278 , V_279 , V_41 , V_14 , V_20 ,
V_280 ) ;
F_218 ( & V_34 -> V_11 -> V_201 ) ;
return V_81 ;
V_311:
F_218 ( & V_34 -> V_11 -> V_201 ) ;
F_230 ( V_20 ) ;
return 0 ;
}
static void F_265 ( struct V_33 * V_34 )
{
int V_102 ;
struct V_48 * V_49 ;
F_174 ( V_186 ) ;
if ( ! F_239 ( V_34 -> V_35 . V_189 . V_223 ) )
return;
if ( V_34 -> V_35 . V_189 . V_224 == V_198 &&
( V_34 -> V_35 . V_189 . V_211 == V_198 ||
V_34 -> V_35 . V_189 . V_210 ) ) {
T_11 V_312 = V_34 -> V_35 . V_189 . V_223 ;
F_217 ( & V_34 -> V_11 -> V_201 ) ;
V_49 = F_36 ( V_312 ) ;
-- V_49 -> V_234 ;
if ( ! V_49 -> V_234 && V_49 -> V_91 . V_233 ) {
F_171 ( V_34 -> V_11 , V_49 , & V_186 ) ;
F_175 ( V_34 -> V_11 , & V_186 ) ;
}
F_218 ( & V_34 -> V_11 -> V_201 ) ;
V_34 -> V_35 . V_189 . V_223 = V_313 ;
return;
}
F_217 ( & V_34 -> V_11 -> V_201 ) ;
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_11 V_312 = V_34 -> V_35 . V_189 . V_226 [ V_102 ] ;
if ( V_312 ) {
V_312 &= V_43 ;
V_49 = F_36 ( V_312 ) ;
-- V_49 -> V_234 ;
if ( ! V_49 -> V_234 && V_49 -> V_91 . V_233 )
F_171 ( V_34 -> V_11 , V_49 ,
& V_186 ) ;
}
V_34 -> V_35 . V_189 . V_226 [ V_102 ] = V_313 ;
}
F_175 ( V_34 -> V_11 , & V_186 ) ;
F_218 ( & V_34 -> V_11 -> V_201 ) ;
V_34 -> V_35 . V_189 . V_223 = V_313 ;
}
static int F_266 ( struct V_33 * V_34 , T_2 V_314 )
{
int V_65 = 0 ;
if ( ! F_267 ( V_34 -> V_11 , V_314 ) ) {
F_172 ( V_315 , V_34 ) ;
V_65 = 1 ;
}
return V_65 ;
}
static int F_268 ( struct V_33 * V_34 )
{
struct V_48 * V_49 ;
unsigned V_102 ;
if ( V_34 -> V_35 . V_189 . V_224 == V_198 ) {
F_217 ( & V_34 -> V_11 -> V_201 ) ;
F_264 ( V_34 ) ;
V_49 = F_191 ( V_34 , 0 , 0 , V_198 ,
1 , V_282 , NULL ) ;
++ V_49 -> V_234 ;
F_218 ( & V_34 -> V_11 -> V_201 ) ;
V_34 -> V_35 . V_189 . V_223 = F_37 ( V_49 -> V_128 ) ;
} else if ( V_34 -> V_35 . V_189 . V_224 == V_225 ) {
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_11 V_312 = V_34 -> V_35 . V_189 . V_226 [ V_102 ] ;
F_146 ( F_239 ( V_312 ) ) ;
F_217 ( & V_34 -> V_11 -> V_201 ) ;
F_264 ( V_34 ) ;
V_49 = F_191 ( V_34 , V_102 << ( 30 - V_18 ) ,
V_102 << 30 ,
V_212 , 1 , V_282 ,
NULL ) ;
V_312 = F_37 ( V_49 -> V_128 ) ;
++ V_49 -> V_234 ;
F_218 ( & V_34 -> V_11 -> V_201 ) ;
V_34 -> V_35 . V_189 . V_226 [ V_102 ] = V_312 | V_39 ;
}
V_34 -> V_35 . V_189 . V_223 = F_37 ( V_34 -> V_35 . V_189 . V_226 ) ;
} else
F_94 () ;
return 0 ;
}
static int F_269 ( struct V_33 * V_34 )
{
struct V_48 * V_49 ;
T_1 V_316 , V_317 ;
T_2 V_314 ;
int V_102 ;
V_314 = V_34 -> V_35 . V_189 . V_318 ( V_34 ) >> V_18 ;
if ( F_266 ( V_34 , V_314 ) )
return 1 ;
if ( V_34 -> V_35 . V_189 . V_211 == V_198 ) {
T_11 V_312 = V_34 -> V_35 . V_189 . V_223 ;
F_146 ( F_239 ( V_312 ) ) ;
F_217 ( & V_34 -> V_11 -> V_201 ) ;
F_264 ( V_34 ) ;
V_49 = F_191 ( V_34 , V_314 , 0 , V_198 ,
0 , V_282 , NULL ) ;
V_312 = F_37 ( V_49 -> V_128 ) ;
++ V_49 -> V_234 ;
F_218 ( & V_34 -> V_11 -> V_201 ) ;
V_34 -> V_35 . V_189 . V_223 = V_312 ;
return 0 ;
}
V_317 = V_39 ;
if ( V_34 -> V_35 . V_189 . V_224 == V_198 )
V_317 |= V_319 | V_135 | V_320 ;
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_11 V_312 = V_34 -> V_35 . V_189 . V_226 [ V_102 ] ;
F_146 ( F_239 ( V_312 ) ) ;
if ( V_34 -> V_35 . V_189 . V_211 == V_225 ) {
V_316 = V_34 -> V_35 . V_189 . V_321 ( V_34 , V_102 ) ;
if ( ! F_270 ( V_316 ) ) {
V_34 -> V_35 . V_189 . V_226 [ V_102 ] = 0 ;
continue;
}
V_314 = V_316 >> V_18 ;
if ( F_266 ( V_34 , V_314 ) )
return 1 ;
}
F_217 ( & V_34 -> V_11 -> V_201 ) ;
F_264 ( V_34 ) ;
V_49 = F_191 ( V_34 , V_314 , V_102 << 30 ,
V_212 , 0 ,
V_282 , NULL ) ;
V_312 = F_37 ( V_49 -> V_128 ) ;
++ V_49 -> V_234 ;
F_218 ( & V_34 -> V_11 -> V_201 ) ;
V_34 -> V_35 . V_189 . V_226 [ V_102 ] = V_312 | V_317 ;
}
V_34 -> V_35 . V_189 . V_223 = F_37 ( V_34 -> V_35 . V_189 . V_226 ) ;
if ( V_34 -> V_35 . V_189 . V_224 == V_198 ) {
if ( V_34 -> V_35 . V_189 . V_322 == NULL ) {
T_1 * V_322 ;
V_322 = ( void * ) F_271 ( V_77 ) ;
if ( V_322 == NULL )
return 1 ;
V_322 [ 0 ] = F_37 ( V_34 -> V_35 . V_189 . V_226 ) | V_317 ;
V_34 -> V_35 . V_189 . V_322 = V_322 ;
}
V_34 -> V_35 . V_189 . V_223 = F_37 ( V_34 -> V_35 . V_189 . V_322 ) ;
}
return 0 ;
}
static int F_272 ( struct V_33 * V_34 )
{
if ( V_34 -> V_35 . V_189 . V_210 )
return F_268 ( V_34 ) ;
else
return F_269 ( V_34 ) ;
}
static void F_273 ( struct V_33 * V_34 )
{
int V_102 ;
struct V_48 * V_49 ;
if ( V_34 -> V_35 . V_189 . V_210 )
return;
if ( ! F_239 ( V_34 -> V_35 . V_189 . V_223 ) )
return;
F_274 ( V_34 , V_323 ) ;
F_176 ( V_34 , V_324 ) ;
if ( V_34 -> V_35 . V_189 . V_211 == V_198 ) {
T_11 V_312 = V_34 -> V_35 . V_189 . V_223 ;
V_49 = F_36 ( V_312 ) ;
F_184 ( V_34 , V_49 ) ;
F_176 ( V_34 , V_325 ) ;
return;
}
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 ) {
T_11 V_312 = V_34 -> V_35 . V_189 . V_226 [ V_102 ] ;
if ( V_312 && F_239 ( V_312 ) ) {
V_312 &= V_43 ;
V_49 = F_36 ( V_312 ) ;
F_184 ( V_34 , V_49 ) ;
}
}
F_176 ( V_34 , V_325 ) ;
}
void F_275 ( struct V_33 * V_34 )
{
F_217 ( & V_34 -> V_11 -> V_201 ) ;
F_273 ( V_34 ) ;
F_218 ( & V_34 -> V_11 -> V_201 ) ;
}
static T_9 F_276 ( struct V_33 * V_34 , T_7 V_326 ,
T_4 V_15 , struct V_327 * V_328 )
{
if ( V_328 )
V_328 -> V_305 = 0 ;
return V_326 ;
}
static T_9 F_277 ( struct V_33 * V_34 , T_7 V_326 ,
T_4 V_15 ,
struct V_327 * V_328 )
{
if ( V_328 )
V_328 -> V_305 = 0 ;
return V_34 -> V_35 . V_329 . V_330 ( V_34 , V_326 , V_15 , V_328 ) ;
}
static bool F_278 ( struct V_33 * V_34 , T_1 V_221 , bool V_92 )
{
if ( V_92 )
return F_279 ( V_34 , V_221 ) ;
return F_280 ( V_34 , V_221 ) ;
}
static bool F_281 ( T_1 V_10 )
{
return F_34 ( V_10 ) ;
}
static T_1 F_282 ( struct V_33 * V_34 , T_1 V_221 )
{
struct V_219 V_220 ;
T_1 V_10 = 0ull ;
if ( ! F_239 ( V_34 -> V_35 . V_189 . V_223 ) )
return V_10 ;
F_54 ( V_34 ) ;
F_259 (vcpu, addr, iterator, spte)
if ( ! F_22 ( V_10 ) )
break;
F_57 ( V_34 ) ;
return V_10 ;
}
int F_283 ( struct V_33 * V_34 , T_1 V_221 , bool V_92 )
{
T_1 V_10 ;
if ( F_278 ( V_34 , V_221 , V_92 ) )
return V_331 ;
V_10 = F_282 ( V_34 , V_221 ) ;
if ( F_10 ( V_10 ) ) {
T_2 V_14 = F_11 ( V_10 ) ;
unsigned V_15 = F_12 ( V_10 ) ;
if ( ! F_16 ( V_34 -> V_11 , V_10 ) )
return V_332 ;
if ( V_92 )
V_221 = 0 ;
F_284 ( V_221 , V_14 , V_15 ) ;
F_254 ( V_34 , V_221 , V_14 , V_15 ) ;
return V_331 ;
}
if ( V_92 && ! F_281 ( V_10 ) )
return V_333 ;
return V_334 ;
}
static int F_285 ( struct V_33 * V_34 , T_1 V_221 ,
T_4 V_305 , bool V_92 )
{
int V_65 ;
V_65 = F_283 ( V_34 , V_221 , V_92 ) ;
F_3 ( V_65 == V_333 ) ;
return V_65 ;
}
static int F_286 ( struct V_33 * V_34 , T_7 V_174 ,
T_4 V_305 , bool V_280 )
{
T_2 V_14 ;
int V_81 ;
F_220 ( L_26 , V_161 , V_174 , V_305 ) ;
if ( F_14 ( V_305 & V_306 ) ) {
V_81 = F_285 ( V_34 , V_174 , V_305 , true ) ;
if ( F_18 ( V_81 != V_332 ) )
return V_81 ;
}
V_81 = F_69 ( V_34 ) ;
if ( V_81 )
return V_81 ;
F_146 ( ! F_239 ( V_34 -> V_35 . V_189 . V_223 ) ) ;
V_14 = V_174 >> V_18 ;
return F_261 ( V_34 , V_174 & V_19 ,
V_305 , V_14 , V_280 ) ;
}
static int F_287 ( struct V_33 * V_34 , T_7 V_174 , T_2 V_14 )
{
struct V_335 V_35 ;
V_35 . V_336 = ( V_34 -> V_35 . V_337 . V_338 ++ << 12 ) | V_34 -> V_339 ;
V_35 . V_14 = V_14 ;
V_35 . V_210 = V_34 -> V_35 . V_189 . V_210 ;
V_35 . V_340 = V_34 -> V_35 . V_189 . V_318 ( V_34 ) ;
return F_288 ( V_34 , V_174 , F_245 ( V_34 -> V_11 , V_14 ) , & V_35 ) ;
}
static bool F_289 ( struct V_33 * V_34 )
{
if ( F_14 ( ! F_290 ( V_34 -> V_11 ) ||
F_291 ( V_34 ) ) )
return false ;
return V_115 -> V_341 ( V_34 ) ;
}
static bool F_262 ( struct V_33 * V_34 , bool V_280 , T_2 V_14 ,
T_7 V_174 , T_3 * V_20 , bool V_278 , bool * V_342 )
{
bool V_343 ;
* V_20 = F_292 ( V_34 -> V_11 , V_14 , & V_343 , V_278 , V_342 ) ;
if ( ! V_343 )
return false ;
if ( ! V_280 && F_289 ( V_34 ) ) {
F_293 ( V_174 , V_14 ) ;
if ( F_294 ( V_34 , V_14 ) ) {
F_295 ( V_174 , V_14 ) ;
F_172 ( V_344 , V_34 ) ;
return true ;
} else if ( F_287 ( V_34 , V_174 , V_14 ) )
return true ;
}
* V_20 = F_296 ( V_34 -> V_11 , V_14 , V_278 , V_342 ) ;
return false ;
}
static int F_297 ( struct V_33 * V_34 , T_7 V_345 , T_4 V_305 ,
bool V_280 )
{
T_3 V_20 ;
int V_81 ;
int V_41 ;
int V_309 ;
T_2 V_14 = V_345 >> V_18 ;
unsigned long V_310 ;
int V_278 = V_305 & V_308 ;
bool V_279 ;
F_146 ( ! F_239 ( V_34 -> V_35 . V_189 . V_223 ) ) ;
if ( F_14 ( V_305 & V_306 ) ) {
V_81 = F_285 ( V_34 , V_345 , V_305 , true ) ;
if ( F_18 ( V_81 != V_332 ) )
return V_81 ;
}
V_81 = F_69 ( V_34 ) ;
if ( V_81 )
return V_81 ;
V_309 = F_87 ( V_34 , V_14 ) ;
if ( F_18 ( ! V_309 ) ) {
V_41 = F_88 ( V_34 , V_14 ) ;
V_14 &= ~ ( F_249 ( V_41 ) - 1 ) ;
} else
V_41 = V_42 ;
if ( F_258 ( V_34 , V_345 , V_41 , V_305 ) )
return 0 ;
V_310 = V_34 -> V_11 -> V_160 ;
F_39 () ;
if ( F_262 ( V_34 , V_280 , V_14 , V_345 , & V_20 , V_278 , & V_279 ) )
return 0 ;
if ( F_252 ( V_34 , 0 , V_14 , V_20 , V_282 , & V_81 ) )
return V_81 ;
F_217 ( & V_34 -> V_11 -> V_201 ) ;
if ( F_263 ( V_34 -> V_11 , V_310 ) )
goto V_311;
F_264 ( V_34 ) ;
if ( F_18 ( ! V_309 ) )
F_246 ( V_34 , & V_14 , & V_20 , & V_41 ) ;
V_81 = F_238 ( V_34 , V_345 , V_278 , V_279 ,
V_41 , V_14 , V_20 , V_280 ) ;
F_218 ( & V_34 -> V_11 -> V_201 ) ;
return V_81 ;
V_311:
F_218 ( & V_34 -> V_11 -> V_201 ) ;
F_230 ( V_20 ) ;
return 0 ;
}
static void F_298 ( struct V_33 * V_34 ,
struct V_346 * V_347 )
{
V_347 -> V_348 = F_286 ;
V_347 -> V_349 = F_276 ;
V_347 -> V_190 = F_159 ;
V_347 -> V_350 = F_160 ;
V_347 -> V_351 = F_161 ;
V_347 -> V_211 = 0 ;
V_347 -> V_224 = V_225 ;
V_347 -> V_223 = V_313 ;
V_347 -> V_210 = true ;
V_347 -> V_352 = false ;
}
void F_299 ( struct V_33 * V_34 )
{
F_265 ( V_34 ) ;
}
static unsigned long V_318 ( struct V_33 * V_34 )
{
return F_300 ( V_34 ) ;
}
static void F_301 ( struct V_33 * V_34 ,
struct V_327 * V_353 )
{
V_34 -> V_35 . V_189 . F_301 ( V_34 , V_353 ) ;
}
static bool F_302 ( struct V_11 * V_11 , T_1 * V_13 , T_2 V_14 ,
unsigned V_15 , int * V_354 )
{
if ( F_14 ( F_10 ( * V_13 ) ) ) {
if ( V_14 != F_11 ( * V_13 ) ) {
F_52 ( V_13 ) ;
return true ;
}
( * V_354 ) ++ ;
F_7 ( V_11 , V_13 , V_14 , V_15 ) ;
return true ;
}
return false ;
}
static inline bool F_303 ( struct V_346 * V_189 , unsigned V_41 , unsigned V_44 )
{
unsigned V_90 ;
V_90 = V_41 - 1 ;
V_90 |= ( V_44 & V_40 ) >> ( V_355 - 2 ) ;
return V_189 -> V_356 & ( 1 << V_90 ) ;
}
static void F_304 ( struct V_33 * V_34 ,
struct V_346 * V_347 )
{
int V_357 = F_305 ( V_34 ) ;
T_1 V_358 = 0 ;
T_1 V_359 = 0 ;
T_1 V_360 = 0 ;
V_347 -> V_361 = 0 ;
if ( ! V_347 -> V_352 )
V_358 = F_306 ( 63 , 63 ) ;
if ( ! F_307 ( V_34 ) )
V_359 = F_306 ( 7 , 7 ) ;
if ( F_308 ( V_34 ) )
V_360 = F_306 ( 8 , 8 ) ;
switch ( V_347 -> V_211 ) {
case V_212 :
V_347 -> V_362 [ 0 ] [ 1 ] = 0 ;
V_347 -> V_362 [ 0 ] [ 0 ] = 0 ;
V_347 -> V_362 [ 1 ] [ 0 ] = V_347 -> V_362 [ 0 ] [ 0 ] ;
if ( ! F_309 ( V_34 ) ) {
V_347 -> V_362 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_20 () )
V_347 -> V_362 [ 1 ] [ 1 ] = F_306 ( 17 , 21 ) ;
else
V_347 -> V_362 [ 1 ] [ 1 ] = F_306 ( 13 , 21 ) ;
break;
case V_225 :
V_347 -> V_362 [ 0 ] [ 2 ] =
F_306 ( V_357 , 63 ) |
F_306 ( 5 , 8 ) | F_306 ( 1 , 2 ) ;
V_347 -> V_362 [ 0 ] [ 1 ] = V_358 |
F_306 ( V_357 , 62 ) ;
V_347 -> V_362 [ 0 ] [ 0 ] = V_358 |
F_306 ( V_357 , 62 ) ;
V_347 -> V_362 [ 1 ] [ 1 ] = V_358 |
F_306 ( V_357 , 62 ) |
F_306 ( 13 , 20 ) ;
V_347 -> V_362 [ 1 ] [ 0 ] = V_347 -> V_362 [ 0 ] [ 0 ] ;
break;
case V_198 :
V_347 -> V_362 [ 0 ] [ 3 ] = V_358 |
V_360 | F_306 ( 7 , 7 ) | F_306 ( V_357 , 51 ) ;
V_347 -> V_362 [ 0 ] [ 2 ] = V_358 |
V_360 | V_359 | F_306 ( V_357 , 51 ) ;
V_347 -> V_362 [ 0 ] [ 1 ] = V_358 |
F_306 ( V_357 , 51 ) ;
V_347 -> V_362 [ 0 ] [ 0 ] = V_358 |
F_306 ( V_357 , 51 ) ;
V_347 -> V_362 [ 1 ] [ 3 ] = V_347 -> V_362 [ 0 ] [ 3 ] ;
V_347 -> V_362 [ 1 ] [ 2 ] = V_358 |
V_359 | F_306 ( V_357 , 51 ) |
F_306 ( 13 , 29 ) ;
V_347 -> V_362 [ 1 ] [ 1 ] = V_358 |
F_306 ( V_357 , 51 ) |
F_306 ( 13 , 20 ) ;
V_347 -> V_362 [ 1 ] [ 0 ] = V_347 -> V_362 [ 0 ] [ 0 ] ;
break;
}
}
static void F_310 ( struct V_33 * V_34 ,
struct V_346 * V_347 , bool V_363 )
{
int V_357 = F_305 ( V_34 ) ;
int V_38 ;
V_347 -> V_362 [ 0 ] [ 3 ] =
F_306 ( V_357 , 51 ) | F_306 ( 3 , 7 ) ;
V_347 -> V_362 [ 0 ] [ 2 ] =
F_306 ( V_357 , 51 ) | F_306 ( 3 , 6 ) ;
V_347 -> V_362 [ 0 ] [ 1 ] =
F_306 ( V_357 , 51 ) | F_306 ( 3 , 6 ) ;
V_347 -> V_362 [ 0 ] [ 0 ] = F_306 ( V_357 , 51 ) ;
V_347 -> V_362 [ 1 ] [ 3 ] = V_347 -> V_362 [ 0 ] [ 3 ] ;
V_347 -> V_362 [ 1 ] [ 2 ] =
F_306 ( V_357 , 51 ) | F_306 ( 12 , 29 ) ;
V_347 -> V_362 [ 1 ] [ 1 ] =
F_306 ( V_357 , 51 ) | F_306 ( 12 , 20 ) ;
V_347 -> V_362 [ 1 ] [ 0 ] = V_347 -> V_362 [ 0 ] [ 0 ] ;
for ( V_38 = 0 ; V_38 < 64 ; V_38 ++ ) {
int V_364 = V_38 & 7 ;
int V_365 = V_38 >> 3 ;
if ( V_365 == 0x2 || V_365 == 0x3 || V_365 == 0x7 ||
V_364 == 0x2 || V_364 == 0x6 ||
( V_364 == 0x4 && ! V_363 ) )
V_347 -> V_361 |= ( 1ull << V_38 ) ;
}
}
void F_311 ( struct V_33 * V_34 ,
struct V_346 * V_189 , bool V_366 )
{
unsigned V_367 , V_368 , V_369 ;
T_8 V_370 ;
bool V_353 , V_371 , V_372 , V_373 , V_374 , V_375 , V_376 , V_377 , V_378 , V_379 , V_380 = 0 ;
V_379 = F_312 ( V_34 , V_381 ) ;
V_378 = F_312 ( V_34 , V_382 ) ;
for ( V_368 = 0 ; V_368 < F_60 ( V_189 -> V_383 ) ; ++ V_368 ) {
V_369 = V_368 << 1 ;
V_370 = 0 ;
V_374 = V_369 & V_308 ;
V_375 = V_369 & V_384 ;
V_376 = V_369 & V_385 ;
V_377 = ! ( V_369 & V_306 ) ;
for ( V_367 = 0 ; V_367 < 8 ; ++ V_367 ) {
V_371 = V_367 & V_266 ;
V_372 = V_367 & V_16 ;
V_373 = V_367 & V_17 ;
if ( ! V_366 ) {
V_371 |= ! V_189 -> V_352 ;
V_372 |= ! F_313 ( V_34 ) && ! V_375 ;
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
static void F_314 ( struct V_33 * V_34 , struct V_346 * V_189 )
{
T_8 V_370 ;
unsigned V_41 , V_211 = V_189 -> V_211 ;
const unsigned V_386 = 1 << 2 ;
if ( V_211 == V_225 )
-- V_211 ;
V_370 = 1 | ( 1 << V_386 ) ;
for ( V_41 = V_103 ; V_41 <= V_211 ; ++ V_41 ) {
if ( V_41 <= V_387
&& ( V_189 -> V_211 >= V_225 || F_309 ( V_34 ) ) )
V_370 |= 1 << ( V_386 | ( V_41 - 1 ) ) ;
}
V_189 -> V_356 = V_370 ;
}
static void F_315 ( struct V_33 * V_34 ,
struct V_346 * V_347 ,
int V_41 )
{
V_347 -> V_352 = F_21 ( V_34 ) ;
V_347 -> V_211 = V_41 ;
F_304 ( V_34 , V_347 ) ;
F_311 ( V_34 , V_347 , false ) ;
F_314 ( V_34 , V_347 ) ;
F_146 ( ! F_170 ( V_34 ) ) ;
V_347 -> V_348 = V_388 ;
V_347 -> V_349 = V_389 ;
V_347 -> V_190 = V_390 ;
V_347 -> V_350 = V_391 ;
V_347 -> V_351 = V_392 ;
V_347 -> V_224 = V_41 ;
V_347 -> V_223 = V_313 ;
V_347 -> V_210 = false ;
}
static void F_316 ( struct V_33 * V_34 ,
struct V_346 * V_347 )
{
F_315 ( V_34 , V_347 , V_198 ) ;
}
static void F_317 ( struct V_33 * V_34 ,
struct V_346 * V_347 )
{
V_347 -> V_352 = false ;
V_347 -> V_211 = V_212 ;
F_304 ( V_34 , V_347 ) ;
F_311 ( V_34 , V_347 , false ) ;
F_314 ( V_34 , V_347 ) ;
V_347 -> V_348 = V_393 ;
V_347 -> V_349 = V_394 ;
V_347 -> V_190 = V_395 ;
V_347 -> V_350 = V_396 ;
V_347 -> V_351 = V_397 ;
V_347 -> V_224 = V_225 ;
V_347 -> V_223 = V_313 ;
V_347 -> V_210 = false ;
}
static void F_318 ( struct V_33 * V_34 ,
struct V_346 * V_347 )
{
F_315 ( V_34 , V_347 , V_225 ) ;
}
static void F_319 ( struct V_33 * V_34 )
{
struct V_346 * V_347 = & V_34 -> V_35 . V_189 ;
V_347 -> V_209 . V_215 = 0 ;
V_347 -> V_348 = F_297 ;
V_347 -> V_190 = F_159 ;
V_347 -> V_350 = F_160 ;
V_347 -> V_351 = F_161 ;
V_347 -> V_224 = V_115 -> V_398 () ;
V_347 -> V_223 = V_313 ;
V_347 -> V_210 = true ;
V_347 -> V_399 = V_115 -> V_400 ;
V_347 -> V_318 = V_318 ;
V_347 -> V_321 = V_401 ;
V_347 -> F_301 = V_402 ;
if ( ! F_320 ( V_34 ) ) {
V_347 -> V_352 = false ;
V_347 -> V_349 = F_276 ;
V_347 -> V_211 = 0 ;
} else if ( F_321 ( V_34 ) ) {
V_347 -> V_352 = F_21 ( V_34 ) ;
V_347 -> V_211 = V_198 ;
F_304 ( V_34 , V_347 ) ;
V_347 -> V_349 = V_389 ;
} else if ( F_170 ( V_34 ) ) {
V_347 -> V_352 = F_21 ( V_34 ) ;
V_347 -> V_211 = V_225 ;
F_304 ( V_34 , V_347 ) ;
V_347 -> V_349 = V_389 ;
} else {
V_347 -> V_352 = false ;
V_347 -> V_211 = V_212 ;
F_304 ( V_34 , V_347 ) ;
V_347 -> V_349 = V_394 ;
}
F_311 ( V_34 , V_347 , false ) ;
F_314 ( V_34 , V_347 ) ;
}
void F_322 ( struct V_33 * V_34 )
{
bool V_403 = F_312 ( V_34 , V_381 ) ;
struct V_346 * V_347 = & V_34 -> V_35 . V_189 ;
F_146 ( F_239 ( V_347 -> V_223 ) ) ;
if ( ! F_320 ( V_34 ) )
F_298 ( V_34 , V_347 ) ;
else if ( F_321 ( V_34 ) )
F_316 ( V_34 , V_347 ) ;
else if ( F_170 ( V_34 ) )
F_318 ( V_34 , V_347 ) ;
else
F_317 ( V_34 , V_347 ) ;
V_347 -> V_209 . V_404 = F_21 ( V_34 ) ;
V_347 -> V_209 . V_188 = ! ! F_170 ( V_34 ) ;
V_347 -> V_209 . V_405 = F_313 ( V_34 ) ;
V_347 -> V_209 . V_406
= V_403 && ! F_313 ( V_34 ) ;
}
void F_323 ( struct V_33 * V_34 , bool V_363 )
{
struct V_346 * V_347 = & V_34 -> V_35 . V_189 ;
F_146 ( F_239 ( V_347 -> V_223 ) ) ;
V_347 -> V_224 = V_115 -> V_398 () ;
V_347 -> V_352 = true ;
V_347 -> V_348 = V_407 ;
V_347 -> V_349 = V_408 ;
V_347 -> V_190 = V_409 ;
V_347 -> V_350 = V_410 ;
V_347 -> V_351 = V_411 ;
V_347 -> V_211 = V_347 -> V_224 ;
V_347 -> V_223 = V_313 ;
V_347 -> V_210 = false ;
F_311 ( V_34 , V_347 , true ) ;
F_310 ( V_34 , V_347 , V_363 ) ;
}
static void F_324 ( struct V_33 * V_34 )
{
struct V_346 * V_347 = & V_34 -> V_35 . V_189 ;
F_322 ( V_34 ) ;
V_347 -> V_399 = V_115 -> V_399 ;
V_347 -> V_318 = V_318 ;
V_347 -> V_321 = V_401 ;
V_347 -> F_301 = V_402 ;
}
static void F_325 ( struct V_33 * V_34 )
{
struct V_346 * V_412 = & V_34 -> V_35 . V_329 ;
V_412 -> V_318 = V_318 ;
V_412 -> V_321 = V_401 ;
V_412 -> F_301 = V_402 ;
if ( ! F_320 ( V_34 ) ) {
V_412 -> V_352 = false ;
V_412 -> V_211 = 0 ;
V_412 -> V_349 = F_277 ;
} else if ( F_321 ( V_34 ) ) {
V_412 -> V_352 = F_21 ( V_34 ) ;
V_412 -> V_211 = V_198 ;
F_304 ( V_34 , V_412 ) ;
V_412 -> V_349 = V_413 ;
} else if ( F_170 ( V_34 ) ) {
V_412 -> V_352 = F_21 ( V_34 ) ;
V_412 -> V_211 = V_225 ;
F_304 ( V_34 , V_412 ) ;
V_412 -> V_349 = V_413 ;
} else {
V_412 -> V_352 = false ;
V_412 -> V_211 = V_212 ;
F_304 ( V_34 , V_412 ) ;
V_412 -> V_349 = V_414 ;
}
F_311 ( V_34 , V_412 , false ) ;
F_314 ( V_34 , V_412 ) ;
}
static void F_326 ( struct V_33 * V_34 )
{
if ( F_327 ( V_34 ) )
F_325 ( V_34 ) ;
else if ( V_267 )
F_319 ( V_34 ) ;
else
F_324 ( V_34 ) ;
}
void F_328 ( struct V_33 * V_34 )
{
F_329 ( V_34 ) ;
F_326 ( V_34 ) ;
}
int F_330 ( struct V_33 * V_34 )
{
int V_81 ;
V_81 = F_69 ( V_34 ) ;
if ( V_81 )
goto V_85;
V_81 = F_272 ( V_34 ) ;
F_275 ( V_34 ) ;
if ( V_81 )
goto V_85;
V_34 -> V_35 . V_189 . V_399 ( V_34 , V_34 -> V_35 . V_189 . V_223 ) ;
V_85:
return V_81 ;
}
void F_329 ( struct V_33 * V_34 )
{
F_265 ( V_34 ) ;
F_3 ( F_239 ( V_34 -> V_35 . V_189 . V_223 ) ) ;
}
static void F_331 ( struct V_33 * V_34 ,
struct V_48 * V_49 , T_1 * V_10 ,
const void * V_415 )
{
if ( V_49 -> V_91 . V_41 != V_42 ) {
++ V_34 -> V_11 -> V_132 . V_416 ;
return;
}
++ V_34 -> V_11 -> V_132 . V_417 ;
V_34 -> V_35 . V_189 . V_351 ( V_34 , V_49 , V_10 , V_415 ) ;
}
static bool F_332 ( T_1 V_418 , T_1 V_415 )
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
static void F_333 ( struct V_33 * V_34 , bool V_420 ,
bool V_421 , bool V_422 )
{
if ( V_420 )
return;
if ( V_421 )
F_107 ( V_34 -> V_11 ) ;
else if ( V_422 )
F_172 ( V_191 , V_34 ) ;
}
static T_1 F_334 ( struct V_33 * V_34 , T_9 * V_345 ,
const T_8 * V_415 , int * V_423 )
{
T_1 V_424 ;
int V_81 ;
if ( F_170 ( V_34 ) && * V_423 == 4 ) {
* V_345 &= ~ ( T_9 ) 7 ;
* V_423 = 8 ;
V_81 = F_335 ( V_34 -> V_11 , * V_345 , & V_424 , 8 ) ;
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
static bool F_336 ( struct V_48 * V_49 )
{
if ( V_49 -> V_91 . V_41 == V_42 )
return false ;
return ++ V_49 -> V_203 >= 3 ;
}
static bool F_337 ( struct V_48 * V_49 , T_9 V_345 ,
int V_423 )
{
unsigned V_425 , V_426 , V_427 ;
F_220 ( L_27 ,
V_345 , V_423 , V_49 -> V_91 . V_215 ) ;
V_425 = F_338 ( V_345 ) ;
V_426 = V_49 -> V_91 . V_188 ? 8 : 4 ;
if ( ! ( V_425 & ( V_426 - 1 ) ) && V_423 == 1 )
return false ;
V_427 = ( V_425 ^ ( V_425 + V_423 - 1 ) ) & ~ ( V_426 - 1 ) ;
V_427 |= V_423 < 4 ;
return V_427 ;
}
static T_1 * F_339 ( struct V_48 * V_49 , T_9 V_345 , int * V_428 )
{
unsigned V_429 , V_207 ;
T_1 * V_10 ;
int V_41 ;
V_429 = F_338 ( V_345 ) ;
V_41 = V_49 -> V_91 . V_41 ;
* V_428 = 1 ;
if ( ! V_49 -> V_91 . V_188 ) {
V_429 <<= 1 ;
if ( V_41 == V_212 ) {
V_429 &= ~ 7 ;
V_429 <<= 1 ;
* V_428 = 2 ;
}
V_207 = V_429 >> V_18 ;
V_429 &= ~ V_19 ;
if ( V_207 != V_49 -> V_91 . V_207 )
return NULL ;
}
V_10 = & V_49 -> V_128 [ V_429 / sizeof( * V_10 ) ] ;
return V_10 ;
}
void F_340 ( struct V_33 * V_34 , T_9 V_345 ,
const T_8 * V_415 , int V_423 )
{
T_2 V_14 = V_345 >> V_18 ;
union V_206 V_4 = { . V_215 = 0 } ;
struct V_48 * V_49 ;
F_174 ( V_186 ) ;
T_1 V_430 , V_424 , * V_10 ;
int V_431 ;
bool V_421 , V_422 , V_420 ;
if ( ! F_33 ( V_34 -> V_11 -> V_35 . V_106 ) )
return;
V_420 = V_421 = V_422 = false ;
F_220 ( L_28 , V_161 , V_345 , V_423 ) ;
V_424 = F_334 ( V_34 , & V_345 , V_415 , & V_423 ) ;
F_69 ( V_34 ) ;
F_217 ( & V_34 -> V_11 -> V_201 ) ;
++ V_34 -> V_11 -> V_132 . V_432 ;
F_176 ( V_34 , V_433 ) ;
V_4 . V_405 = V_4 . V_188 = V_4 . V_404 = 1 ;
F_180 (vcpu->kvm, sp, gfn) {
if ( F_337 ( V_49 , V_345 , V_423 ) ||
F_336 ( V_49 ) ) {
V_420 |= ! ! F_171 ( V_34 -> V_11 , V_49 ,
& V_186 ) ;
++ V_34 -> V_11 -> V_132 . V_434 ;
continue;
}
V_10 = F_339 ( V_49 , V_345 , & V_431 ) ;
if ( ! V_10 )
continue;
V_422 = true ;
while ( V_431 -- ) {
V_430 = * V_10 ;
F_204 ( V_34 -> V_11 , V_49 , V_10 ) ;
if ( V_424 &&
! ( ( V_49 -> V_91 . V_215 ^ V_34 -> V_35 . V_189 . V_209 . V_215 )
& V_4 . V_215 ) && F_99 ( V_34 ) )
F_331 ( V_34 , V_49 , V_10 , & V_424 ) ;
if ( F_332 ( V_430 , * V_10 ) )
V_421 = true ;
++ V_10 ;
}
}
F_333 ( V_34 , V_420 , V_421 , V_422 ) ;
F_175 ( V_34 -> V_11 , & V_186 ) ;
F_176 ( V_34 , V_435 ) ;
F_218 ( & V_34 -> V_11 -> V_201 ) ;
}
int F_341 ( struct V_33 * V_34 , T_7 V_174 )
{
T_9 V_345 ;
int V_81 ;
if ( V_34 -> V_35 . V_189 . V_210 )
return 0 ;
V_345 = F_342 ( V_34 , V_174 , NULL ) ;
V_81 = F_219 ( V_34 -> V_11 , V_345 >> V_18 ) ;
return V_81 ;
}
static void F_264 ( struct V_33 * V_34 )
{
F_174 ( V_186 ) ;
if ( F_18 ( F_343 ( V_34 -> V_11 ) >= V_436 ) )
return;
while ( F_343 ( V_34 -> V_11 ) < V_437 ) {
if ( ! F_214 ( V_34 -> V_11 , & V_186 ) )
break;
++ V_34 -> V_11 -> V_132 . V_438 ;
}
F_175 ( V_34 -> V_11 , & V_186 ) ;
}
static bool F_344 ( struct V_33 * V_34 , T_7 V_221 )
{
if ( V_34 -> V_35 . V_189 . V_210 || F_327 ( V_34 ) )
return F_279 ( V_34 , V_221 ) ;
return F_280 ( V_34 , V_221 ) ;
}
int F_345 ( struct V_33 * V_34 , T_7 V_439 , T_4 V_305 ,
void * V_440 , int V_441 )
{
int V_81 , V_442 = V_443 ;
enum V_444 V_445 ;
V_81 = V_34 -> V_35 . V_189 . V_348 ( V_34 , V_439 , V_305 , false ) ;
if ( V_81 < 0 )
goto V_85;
if ( ! V_81 ) {
V_81 = 1 ;
goto V_85;
}
if ( F_344 ( V_34 , V_439 ) )
V_442 = 0 ;
V_445 = F_346 ( V_34 , V_439 , V_442 , V_440 , V_441 ) ;
switch ( V_445 ) {
case V_446 :
return 1 ;
case V_447 :
++ V_34 -> V_132 . V_448 ;
case V_449 :
return 0 ;
default:
F_94 () ;
}
V_85:
return V_81 ;
}
void F_347 ( struct V_33 * V_34 , T_7 V_174 )
{
V_34 -> V_35 . V_189 . V_350 ( V_34 , V_174 ) ;
F_172 ( V_191 , V_34 ) ;
++ V_34 -> V_132 . V_350 ;
}
void F_348 ( void )
{
V_267 = true ;
}
void F_349 ( void )
{
V_267 = false ;
}
static void F_350 ( struct V_33 * V_34 )
{
F_68 ( ( unsigned long ) V_34 -> V_35 . V_189 . V_226 ) ;
if ( V_34 -> V_35 . V_189 . V_322 != NULL )
F_68 ( ( unsigned long ) V_34 -> V_35 . V_189 . V_322 ) ;
}
static int F_351 ( struct V_33 * V_34 )
{
struct V_80 * V_80 ;
int V_102 ;
V_80 = F_352 ( V_77 | V_450 ) ;
if ( ! V_80 )
return - V_78 ;
V_34 -> V_35 . V_189 . V_226 = F_353 ( V_80 ) ;
for ( V_102 = 0 ; V_102 < 4 ; ++ V_102 )
V_34 -> V_35 . V_189 . V_226 [ V_102 ] = V_313 ;
return 0 ;
}
int F_354 ( struct V_33 * V_34 )
{
V_34 -> V_35 . V_451 = & V_34 -> V_35 . V_189 ;
V_34 -> V_35 . V_189 . V_223 = V_313 ;
V_34 -> V_35 . V_189 . V_330 = V_330 ;
V_34 -> V_35 . V_329 . V_330 = V_452 ;
return F_351 ( V_34 ) ;
}
void F_355 ( struct V_33 * V_34 )
{
F_146 ( F_239 ( V_34 -> V_35 . V_189 . V_223 ) ) ;
F_326 ( V_34 ) ;
}
void F_356 ( struct V_11 * V_11 ,
struct V_96 * V_148 )
{
T_2 V_453 ;
int V_102 ;
bool V_136 = false ;
V_453 = V_148 -> V_99 + V_148 -> V_154 - 1 ;
F_217 ( & V_11 -> V_201 ) ;
for ( V_102 = V_42 ;
V_102 < V_42 + V_104 ; ++ V_102 ) {
unsigned long * V_127 ;
unsigned long V_454 , V_90 ;
V_127 = V_148 -> V_35 . V_126 [ V_102 - V_42 ] ;
V_454 = F_78 ( V_453 , V_148 -> V_99 , V_102 ) ;
for ( V_90 = 0 ; V_90 <= V_454 ; ++ V_90 , ++ V_127 ) {
if ( * V_127 )
V_136 |= F_109 ( V_11 , V_127 ,
false ) ;
if ( F_357 () || F_358 ( & V_11 -> V_201 ) )
F_186 ( & V_11 -> V_201 ) ;
}
}
F_218 ( & V_11 -> V_201 ) ;
F_359 ( & V_11 -> V_455 ) ;
if ( V_136 )
F_107 ( V_11 ) ;
}
void F_360 ( struct V_11 * V_11 ,
struct V_96 * V_148 )
{
T_2 V_453 ;
unsigned long * V_127 ;
unsigned long V_454 , V_90 ;
bool V_136 = false ;
V_453 = V_148 -> V_99 + V_148 -> V_154 - 1 ;
F_217 ( & V_11 -> V_201 ) ;
V_127 = V_148 -> V_35 . V_126 [ V_42 - 1 ] ;
V_454 = F_78 ( V_453 , V_148 -> V_99 ,
V_42 ) ;
for ( V_90 = 0 ; V_90 <= V_454 ; ++ V_90 , ++ V_127 ) {
if ( * V_127 )
V_136 |= F_111 ( V_11 , V_127 ) ;
if ( F_357 () || F_358 ( & V_11 -> V_201 ) )
F_186 ( & V_11 -> V_201 ) ;
}
F_218 ( & V_11 -> V_201 ) ;
F_359 ( & V_11 -> V_455 ) ;
if ( V_136 )
F_107 ( V_11 ) ;
}
void F_361 ( struct V_11 * V_11 ,
struct V_96 * V_148 )
{
T_2 V_453 ;
int V_102 ;
bool V_136 = false ;
V_453 = V_148 -> V_99 + V_148 -> V_154 - 1 ;
F_217 ( & V_11 -> V_201 ) ;
for ( V_102 = V_42 + 1 ;
V_102 < V_42 + V_104 ; ++ V_102 ) {
unsigned long * V_127 ;
unsigned long V_454 , V_90 ;
V_127 = V_148 -> V_35 . V_126 [ V_102 - V_42 ] ;
V_454 = F_78 ( V_453 , V_148 -> V_99 , V_102 ) ;
for ( V_90 = 0 ; V_90 <= V_454 ; ++ V_90 , ++ V_127 ) {
if ( * V_127 )
V_136 |= F_109 ( V_11 , V_127 ,
false ) ;
if ( F_357 () || F_358 ( & V_11 -> V_201 ) )
F_186 ( & V_11 -> V_201 ) ;
}
}
F_218 ( & V_11 -> V_201 ) ;
F_359 ( & V_11 -> V_455 ) ;
if ( V_136 )
F_107 ( V_11 ) ;
}
void F_362 ( struct V_11 * V_11 ,
struct V_96 * V_148 )
{
T_2 V_453 ;
int V_102 ;
bool V_136 = false ;
V_453 = V_148 -> V_99 + V_148 -> V_154 - 1 ;
F_217 ( & V_11 -> V_201 ) ;
for ( V_102 = V_42 ;
V_102 < V_42 + V_104 ; ++ V_102 ) {
unsigned long * V_127 ;
unsigned long V_454 , V_90 ;
V_127 = V_148 -> V_35 . V_126 [ V_102 - V_42 ] ;
V_454 = F_78 ( V_453 , V_148 -> V_99 , V_102 ) ;
for ( V_90 = 0 ; V_90 <= V_454 ; ++ V_90 , ++ V_127 ) {
if ( * V_127 )
V_136 |= F_113 ( V_11 , V_127 ) ;
if ( F_357 () || F_358 ( & V_11 -> V_201 ) )
F_186 ( & V_11 -> V_201 ) ;
}
}
F_218 ( & V_11 -> V_201 ) ;
F_359 ( & V_11 -> V_455 ) ;
if ( V_136 )
F_107 ( V_11 ) ;
}
static void F_363 ( struct V_11 * V_11 )
{
struct V_48 * V_49 , * V_456 ;
int V_457 = 0 ;
V_458:
F_364 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_65 ;
if ( ! F_190 ( V_11 , V_49 ) )
break;
if ( V_49 -> V_91 . V_233 )
continue;
if ( V_457 >= V_459 &&
F_186 ( & V_11 -> V_201 ) ) {
V_457 = 0 ;
goto V_458;
}
V_65 = F_171 ( V_11 , V_49 ,
& V_11 -> V_35 . V_460 ) ;
V_457 += V_65 ;
if ( V_65 )
goto V_458;
}
F_175 ( V_11 , & V_11 -> V_35 . V_460 ) ;
}
void F_365 ( struct V_11 * V_11 )
{
F_217 ( & V_11 -> V_201 ) ;
F_366 ( V_11 ) ;
V_11 -> V_35 . V_204 ++ ;
F_211 ( V_11 ) ;
F_363 ( V_11 ) ;
F_218 ( & V_11 -> V_201 ) ;
}
static bool F_367 ( struct V_11 * V_11 )
{
return F_14 ( ! F_368 ( & V_11 -> V_35 . V_460 ) ) ;
}
void F_369 ( struct V_11 * V_11 )
{
if ( F_14 ( F_5 ( V_11 ) == 0 ) ) {
F_370 ( V_461 L_29 ) ;
F_365 ( V_11 ) ;
}
}
static unsigned long
F_371 ( struct V_462 * V_463 , struct V_464 * V_465 )
{
struct V_11 * V_11 ;
int V_466 = V_465 -> V_466 ;
unsigned long V_467 = 0 ;
F_217 ( & V_468 ) ;
F_372 (kvm, &vm_list, vm_list) {
int V_98 ;
F_174 ( V_186 ) ;
if ( ! V_466 -- )
break;
if ( ! V_11 -> V_35 . V_163 &&
! F_367 ( V_11 ) )
continue;
V_98 = F_373 ( & V_11 -> V_469 ) ;
F_217 ( & V_11 -> V_201 ) ;
if ( F_367 ( V_11 ) ) {
F_175 ( V_11 ,
& V_11 -> V_35 . V_460 ) ;
goto V_470;
}
if ( F_214 ( V_11 , & V_186 ) )
V_467 ++ ;
F_175 ( V_11 , & V_186 ) ;
V_470:
F_218 ( & V_11 -> V_201 ) ;
F_374 ( & V_11 -> V_469 , V_98 ) ;
F_375 ( & V_11 -> V_471 , & V_471 ) ;
break;
}
F_218 ( & V_468 ) ;
return V_467 ;
}
static unsigned long
F_376 ( struct V_462 * V_463 , struct V_464 * V_465 )
{
return F_377 ( & V_164 ) ;
}
static void F_378 ( void )
{
if ( V_83 )
F_379 ( V_83 ) ;
if ( V_87 )
F_379 ( V_87 ) ;
}
int F_380 ( void )
{
V_83 = F_381 ( L_30 ,
sizeof( struct V_89 ) ,
0 , 0 , NULL ) ;
if ( ! V_83 )
goto V_472;
V_87 = F_381 ( L_31 ,
sizeof( struct V_48 ) ,
0 , 0 , NULL ) ;
if ( ! V_87 )
goto V_472;
if ( F_382 ( & V_164 , 0 , V_77 ) )
goto V_472;
F_383 ( & V_473 ) ;
return 0 ;
V_472:
F_378 () ;
return - V_78 ;
}
unsigned int F_384 ( struct V_11 * V_11 )
{
unsigned int V_474 ;
unsigned int V_475 = 0 ;
struct F_6 * V_147 ;
struct V_96 * V_148 ;
V_147 = F_6 ( V_11 ) ;
F_126 (memslot, slots)
V_475 += V_148 -> V_154 ;
V_474 = V_475 * V_476 / 1000 ;
V_474 = F_127 ( V_474 ,
( unsigned int ) V_477 ) ;
return V_474 ;
}
int F_385 ( struct V_33 * V_34 , T_1 V_221 , T_1 V_119 [ 4 ] )
{
struct V_219 V_220 ;
T_1 V_10 ;
int V_478 = 0 ;
if ( ! F_239 ( V_34 -> V_35 . V_189 . V_223 ) )
return V_478 ;
F_54 ( V_34 ) ;
F_259 (vcpu, addr, iterator, spte) {
V_119 [ V_220 . V_41 - 1 ] = V_10 ;
V_478 ++ ;
if ( ! F_22 ( V_10 ) )
break;
}
F_57 ( V_34 ) ;
return V_478 ;
}
void F_386 ( struct V_33 * V_34 )
{
F_329 ( V_34 ) ;
F_350 ( V_34 ) ;
F_70 ( V_34 ) ;
}
void F_387 ( void )
{
F_378 () ;
F_388 ( & V_164 ) ;
F_389 ( & V_473 ) ;
F_177 () ;
}
