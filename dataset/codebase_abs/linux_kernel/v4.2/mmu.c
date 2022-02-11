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
static bool F_34 ( T_1 V_10 )
{
return V_10 == 0ull ;
}
static void F_35 ( T_1 * V_14 , T_1 V_10 )
{
struct V_47 * V_48 = F_36 ( F_37 ( V_14 ) ) ;
if ( F_22 ( V_10 ) )
return;
F_38 () ;
V_48 -> V_49 ++ ;
}
static void F_28 ( T_1 * V_14 , T_1 V_10 )
{
union V_50 * V_51 , V_52 ;
V_51 = (union V_50 * ) V_14 ;
V_52 = (union V_50 ) V_10 ;
V_51 -> V_53 = V_52 . V_53 ;
F_38 () ;
V_51 -> V_54 = V_52 . V_54 ;
}
static void F_29 ( T_1 * V_14 , T_1 V_10 )
{
union V_50 * V_51 , V_52 ;
V_51 = (union V_50 * ) V_14 ;
V_52 = (union V_50 ) V_10 ;
V_51 -> V_54 = V_52 . V_54 ;
F_38 () ;
V_51 -> V_53 = V_52 . V_53 ;
F_35 ( V_14 , V_10 ) ;
}
static T_1 F_30 ( T_1 * V_14 , T_1 V_10 )
{
union V_50 * V_51 , V_52 , V_55 ;
V_51 = (union V_50 * ) V_14 ;
V_52 = (union V_50 ) V_10 ;
V_55 . V_54 = F_31 ( & V_51 -> V_54 , V_52 . V_54 ) ;
V_55 . V_53 = V_51 -> V_53 ;
V_51 -> V_53 = V_52 . V_53 ;
F_35 ( V_14 , V_10 ) ;
return V_55 . V_10 ;
}
static T_1 F_32 ( T_1 * V_14 )
{
struct V_47 * V_48 = F_36 ( F_37 ( V_14 ) ) ;
union V_50 V_10 , * V_55 = (union V_50 * ) V_14 ;
int V_56 ;
V_57:
V_56 = V_48 -> V_49 ;
F_39 () ;
V_10 . V_54 = V_55 -> V_54 ;
F_39 () ;
V_10 . V_53 = V_55 -> V_53 ;
F_39 () ;
if ( F_14 ( V_10 . V_54 != V_55 -> V_54 ||
V_56 != V_48 -> V_49 ) )
goto V_57;
return V_10 . V_10 ;
}
static bool F_34 ( T_1 V_10 )
{
union V_50 V_52 = (union V_50 ) V_10 ;
T_4 V_58 = V_2 >> 32 ;
if ( V_10 == 0ull )
return true ;
if ( V_52 . V_54 == 0ull &&
( V_52 . V_53 & V_58 ) == V_58 )
return true ;
return false ;
}
static bool F_40 ( T_1 V_10 )
{
return ( V_10 & ( V_59 | V_60 ) ) ==
( V_59 | V_60 ) ;
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
static bool F_43 ( T_1 V_61 , T_1 V_62 , T_1 V_63 )
{
return ( V_61 & V_63 ) && ! ( V_62 & V_63 ) ;
}
static bool F_44 ( T_1 V_61 , T_1 V_62 , T_1 V_63 )
{
return ( V_61 & V_63 ) != ( V_62 & V_63 ) ;
}
static void F_9 ( T_1 * V_14 , T_1 V_62 )
{
F_3 ( F_22 ( * V_14 ) ) ;
F_28 ( V_14 , V_62 ) ;
}
static bool F_45 ( T_1 * V_14 , T_1 V_62 )
{
T_1 V_61 = * V_14 ;
bool V_64 = false ;
F_3 ( ! F_24 ( V_62 ) ) ;
if ( ! F_22 ( V_61 ) ) {
F_9 ( V_14 , V_62 ) ;
return V_64 ;
}
if ( ! F_41 ( V_61 ) )
F_29 ( V_14 , V_62 ) ;
else
V_61 = F_30 ( V_14 , V_62 ) ;
if ( F_40 ( V_61 ) &&
! F_42 ( V_62 ) )
V_64 = true ;
if ( ! V_30 )
return V_64 ;
if ( F_44 ( V_61 , V_62 ,
V_30 | V_31 ) )
V_64 = true ;
if ( F_43 ( V_61 , V_62 , V_30 ) )
F_46 ( F_26 ( V_61 ) ) ;
if ( F_43 ( V_61 , V_62 , V_31 ) )
F_47 ( F_26 ( V_61 ) ) ;
return V_64 ;
}
static int F_48 ( T_1 * V_14 )
{
T_3 V_21 ;
T_1 V_61 = * V_14 ;
if ( ! F_41 ( V_61 ) )
F_29 ( V_14 , 0ull ) ;
else
V_61 = F_30 ( V_14 , 0ull ) ;
if ( ! F_24 ( V_61 ) )
return 0 ;
V_21 = F_26 ( V_61 ) ;
F_3 ( ! F_49 ( V_21 ) && ! F_50 ( F_51 ( V_21 ) ) ) ;
if ( ! V_30 || V_61 & V_30 )
F_46 ( V_21 ) ;
if ( ! V_31 || ( V_61 & V_31 ) )
F_47 ( V_21 ) ;
return 1 ;
}
static void F_52 ( T_1 * V_14 )
{
F_29 ( V_14 , 0ull ) ;
}
static T_1 F_53 ( T_1 * V_14 )
{
return F_32 ( V_14 ) ;
}
static void F_54 ( struct V_11 * V_12 )
{
F_55 () ;
V_12 -> V_65 = V_66 ;
F_56 () ;
}
static void F_57 ( struct V_11 * V_12 )
{
F_56 () ;
V_12 -> V_65 = V_67 ;
F_58 () ;
}
static int F_59 ( struct V_68 * V_69 ,
struct V_70 * V_71 , int V_72 )
{
void * V_73 ;
if ( V_69 -> V_74 >= V_72 )
return 0 ;
while ( V_69 -> V_74 < F_60 ( V_69 -> V_75 ) ) {
V_73 = F_61 ( V_71 , V_76 ) ;
if ( ! V_73 )
return - V_77 ;
V_69 -> V_75 [ V_69 -> V_74 ++ ] = V_73 ;
}
return 0 ;
}
static int F_62 ( struct V_68 * V_69 )
{
return V_69 -> V_74 ;
}
static void F_63 ( struct V_68 * V_78 ,
struct V_70 * V_69 )
{
while ( V_78 -> V_74 )
F_64 ( V_69 , V_78 -> V_75 [ -- V_78 -> V_74 ] ) ;
}
static int F_65 ( struct V_68 * V_69 ,
int V_72 )
{
void * V_79 ;
if ( V_69 -> V_74 >= V_72 )
return 0 ;
while ( V_69 -> V_74 < F_60 ( V_69 -> V_75 ) ) {
V_79 = ( void * ) F_66 ( V_76 ) ;
if ( ! V_79 )
return - V_77 ;
V_69 -> V_75 [ V_69 -> V_74 ++ ] = V_79 ;
}
return 0 ;
}
static void F_67 ( struct V_68 * V_78 )
{
while ( V_78 -> V_74 )
F_68 ( ( unsigned long ) V_78 -> V_75 [ -- V_78 -> V_74 ] ) ;
}
static int F_69 ( struct V_11 * V_12 )
{
int V_80 ;
V_80 = F_59 ( & V_12 -> V_34 . V_81 ,
V_82 , 8 + V_83 ) ;
if ( V_80 )
goto V_84;
V_80 = F_65 ( & V_12 -> V_34 . V_85 , 8 ) ;
if ( V_80 )
goto V_84;
V_80 = F_59 ( & V_12 -> V_34 . V_86 ,
V_86 , 4 ) ;
V_84:
return V_80 ;
}
static void F_70 ( struct V_11 * V_12 )
{
F_63 ( & V_12 -> V_34 . V_81 ,
V_82 ) ;
F_67 ( & V_12 -> V_34 . V_85 ) ;
F_63 ( & V_12 -> V_34 . V_86 ,
V_86 ) ;
}
static void * F_71 ( struct V_68 * V_78 )
{
void * V_87 ;
F_72 ( ! V_78 -> V_74 ) ;
V_87 = V_78 -> V_75 [ -- V_78 -> V_74 ] ;
return V_87 ;
}
static struct V_88 * F_73 ( struct V_11 * V_12 )
{
return F_71 ( & V_12 -> V_34 . V_81 ) ;
}
static void F_74 ( struct V_88 * V_88 )
{
F_64 ( V_82 , V_88 ) ;
}
static T_2 F_75 ( struct V_47 * V_48 , int V_89 )
{
if ( ! V_48 -> V_90 . V_91 )
return V_48 -> V_92 [ V_89 ] ;
return V_48 -> V_15 + ( V_89 << ( ( V_48 -> V_90 . V_40 - 1 ) * V_93 ) ) ;
}
static void F_76 ( struct V_47 * V_48 , int V_89 , T_2 V_15 )
{
if ( V_48 -> V_90 . V_91 )
F_72 ( V_15 != F_75 ( V_48 , V_89 ) ) ;
else
V_48 -> V_92 [ V_89 ] = V_15 ;
}
static struct V_94 * F_77 ( T_2 V_15 ,
struct V_95 * V_96 ,
int V_40 )
{
unsigned long V_97 ;
V_97 = F_78 ( V_15 , V_96 -> V_98 , V_40 ) ;
return & V_96 -> V_34 . V_99 [ V_40 - 2 ] [ V_97 ] ;
}
static void F_79 ( struct V_100 * V_100 , struct V_47 * V_48 )
{
struct V_101 * V_102 ;
struct V_95 * V_96 ;
struct V_94 * V_103 ;
T_2 V_15 ;
int V_104 ;
V_15 = V_48 -> V_15 ;
V_102 = F_80 ( V_100 , V_48 -> V_90 ) ;
V_96 = F_81 ( V_102 , V_15 ) ;
for ( V_104 = V_105 ; V_104 <= V_106 ; ++ V_104 ) {
V_103 = F_77 ( V_15 , V_96 , V_104 ) ;
V_103 -> V_107 += 1 ;
}
V_100 -> V_34 . V_108 ++ ;
}
static void F_82 ( struct V_100 * V_100 , struct V_47 * V_48 )
{
struct V_101 * V_102 ;
struct V_95 * V_96 ;
struct V_94 * V_103 ;
T_2 V_15 ;
int V_104 ;
V_15 = V_48 -> V_15 ;
V_102 = F_80 ( V_100 , V_48 -> V_90 ) ;
V_96 = F_81 ( V_102 , V_15 ) ;
for ( V_104 = V_105 ; V_104 <= V_106 ; ++ V_104 ) {
V_103 = F_77 ( V_15 , V_96 , V_104 ) ;
V_103 -> V_107 -= 1 ;
F_3 ( V_103 -> V_107 < 0 ) ;
}
V_100 -> V_34 . V_108 -- ;
}
static int F_83 ( struct V_11 * V_12 ,
T_2 V_15 ,
int V_40 )
{
struct V_95 * V_96 ;
struct V_94 * V_103 ;
V_96 = F_84 ( V_12 , V_15 ) ;
if ( V_96 ) {
V_103 = F_77 ( V_15 , V_96 , V_40 ) ;
return V_103 -> V_107 ;
}
return 1 ;
}
static int F_85 ( struct V_100 * V_100 , T_2 V_15 )
{
unsigned long V_109 ;
int V_104 , V_64 = 0 ;
V_109 = F_86 ( V_100 , V_15 ) ;
for ( V_104 = V_41 ; V_104 <= V_106 ; ++ V_104 ) {
if ( V_109 >= F_87 ( V_104 ) )
V_64 = V_104 ;
else
break;
}
return V_64 ;
}
static struct V_95 *
F_88 ( struct V_11 * V_12 , T_2 V_15 ,
bool V_110 )
{
struct V_95 * V_96 ;
V_96 = F_84 ( V_12 , V_15 ) ;
if ( ! V_96 || V_96 -> V_111 & V_112 ||
( V_110 && V_96 -> V_113 ) )
V_96 = NULL ;
return V_96 ;
}
static bool F_89 ( struct V_11 * V_12 , T_2 V_114 )
{
return ! F_88 ( V_12 , V_114 , true ) ;
}
static int F_90 ( struct V_11 * V_12 , T_2 V_114 )
{
int V_115 , V_40 , V_116 ;
V_115 = F_85 ( V_12 -> V_100 , V_114 ) ;
if ( V_115 == V_41 )
return V_115 ;
V_116 = V_72 ( V_117 -> V_118 () , V_115 ) ;
for ( V_40 = V_105 ; V_40 <= V_116 ; ++ V_40 )
if ( F_83 ( V_12 , V_114 , V_40 ) )
break;
return V_40 - 1 ;
}
static int F_91 ( struct V_11 * V_12 , T_1 * V_10 ,
unsigned long * V_119 )
{
struct V_88 * V_120 ;
int V_104 , V_56 = 0 ;
if ( ! * V_119 ) {
F_92 ( L_1 , V_10 , * V_10 ) ;
* V_119 = ( unsigned long ) V_10 ;
} else if ( ! ( * V_119 & 1 ) ) {
F_92 ( L_2 , V_10 , * V_10 ) ;
V_120 = F_73 ( V_12 ) ;
V_120 -> V_121 [ 0 ] = ( T_1 * ) * V_119 ;
V_120 -> V_121 [ 1 ] = V_10 ;
* V_119 = ( unsigned long ) V_120 | 1 ;
++ V_56 ;
} else {
F_92 ( L_3 , V_10 , * V_10 ) ;
V_120 = (struct V_88 * ) ( * V_119 & ~ 1ul ) ;
while ( V_120 -> V_121 [ V_122 - 1 ] && V_120 -> V_123 ) {
V_120 = V_120 -> V_123 ;
V_56 += V_122 ;
}
if ( V_120 -> V_121 [ V_122 - 1 ] ) {
V_120 -> V_123 = F_73 ( V_12 ) ;
V_120 = V_120 -> V_123 ;
}
for ( V_104 = 0 ; V_120 -> V_121 [ V_104 ] ; ++ V_104 )
++ V_56 ;
V_120 -> V_121 [ V_104 ] = V_10 ;
}
return V_56 ;
}
static void
F_93 ( unsigned long * V_119 , struct V_88 * V_120 ,
int V_104 , struct V_88 * V_124 )
{
int V_125 ;
for ( V_125 = V_122 - 1 ; ! V_120 -> V_121 [ V_125 ] && V_125 > V_104 ; -- V_125 )
;
V_120 -> V_121 [ V_104 ] = V_120 -> V_121 [ V_125 ] ;
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
F_74 ( V_120 ) ;
}
static void F_94 ( T_1 * V_10 , unsigned long * V_119 )
{
struct V_88 * V_120 ;
struct V_88 * V_124 ;
int V_104 ;
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
V_120 = (struct V_88 * ) ( * V_119 & ~ 1ul ) ;
V_124 = NULL ;
while ( V_120 ) {
for ( V_104 = 0 ; V_104 < V_122 && V_120 -> V_121 [ V_104 ] ; ++ V_104 )
if ( V_120 -> V_121 [ V_104 ] == V_10 ) {
F_93 ( V_119 ,
V_120 , V_104 ,
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
struct V_88 * V_120 ;
int V_104 ;
if ( ! * V_119 )
return;
if ( ! ( * V_119 & 1 ) )
return V_127 ( ( T_1 * ) * V_119 ) ;
V_120 = (struct V_88 * ) ( * V_119 & ~ 1ul ) ;
while ( V_120 ) {
for ( V_104 = 0 ; V_104 < V_122 && V_120 -> V_121 [ V_104 ] ; ++ V_104 )
V_127 ( V_120 -> V_121 [ V_104 ] ) ;
V_120 = V_120 -> V_123 ;
}
}
static unsigned long * F_99 ( T_2 V_15 , int V_40 ,
struct V_95 * V_96 )
{
unsigned long V_97 ;
V_97 = F_78 ( V_15 , V_96 -> V_98 , V_40 ) ;
return & V_96 -> V_34 . V_128 [ V_40 - V_41 ] [ V_97 ] ;
}
static unsigned long * F_100 ( struct V_100 * V_100 , T_2 V_15 , struct V_47 * V_48 )
{
struct V_101 * V_102 ;
struct V_95 * V_96 ;
V_102 = F_80 ( V_100 , V_48 -> V_90 ) ;
V_96 = F_81 ( V_102 , V_15 ) ;
return F_99 ( V_15 , V_48 -> V_90 . V_40 , V_96 ) ;
}
static bool F_101 ( struct V_11 * V_12 )
{
struct V_68 * V_69 ;
V_69 = & V_12 -> V_34 . V_81 ;
return F_62 ( V_69 ) ;
}
static int F_102 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
struct V_47 * V_48 ;
unsigned long * V_129 ;
V_48 = F_36 ( F_37 ( V_10 ) ) ;
F_76 ( V_48 , V_10 - V_48 -> V_130 , V_15 ) ;
V_129 = F_100 ( V_12 -> V_100 , V_15 , V_48 ) ;
return F_91 ( V_12 , V_10 , V_129 ) ;
}
static void F_103 ( struct V_100 * V_100 , T_1 * V_10 )
{
struct V_47 * V_48 ;
T_2 V_15 ;
unsigned long * V_129 ;
V_48 = F_36 ( F_37 ( V_10 ) ) ;
V_15 = F_75 ( V_48 , V_10 - V_48 -> V_130 ) ;
V_129 = F_100 ( V_100 , V_15 , V_48 ) ;
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
V_132 -> V_120 = (struct V_88 * ) ( V_128 & ~ 1ul ) ;
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
static void F_106 ( struct V_100 * V_100 , T_1 * V_14 )
{
if ( F_48 ( V_14 ) )
F_103 ( V_100 , V_14 ) ;
}
static bool F_107 ( struct V_100 * V_100 , T_1 * V_14 )
{
if ( F_23 ( * V_14 ) ) {
F_3 ( F_36 ( F_37 ( V_14 ) ) -> V_90 . V_40 ==
V_41 ) ;
F_106 ( V_100 , V_14 ) ;
-- V_100 -> V_134 . V_135 ;
return true ;
}
return false ;
}
static void F_108 ( struct V_11 * V_12 , T_1 * V_14 )
{
if ( F_107 ( V_12 -> V_100 , V_14 ) )
F_109 ( V_12 -> V_100 ) ;
}
static bool F_110 ( struct V_100 * V_100 , T_1 * V_14 , bool V_136 )
{
T_1 V_10 = * V_14 ;
if ( ! F_42 ( V_10 ) &&
! ( V_136 && F_40 ( V_10 ) ) )
return false ;
F_92 ( L_9 , V_14 , * V_14 ) ;
if ( V_136 )
V_10 &= ~ V_60 ;
V_10 = V_10 & ~ V_137 ;
return F_45 ( V_14 , V_10 ) ;
}
static bool F_111 ( struct V_100 * V_100 , unsigned long * V_129 ,
bool V_136 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
F_112 (rmapp, &iter, sptep)
V_138 |= F_110 ( V_100 , V_14 , V_136 ) ;
return V_138 ;
}
static bool F_113 ( struct V_100 * V_100 , T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_92 ( L_10 , V_14 , * V_14 ) ;
V_10 &= ~ V_31 ;
return F_45 ( V_14 , V_10 ) ;
}
static bool F_114 ( struct V_100 * V_100 , unsigned long * V_129 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
F_112 (rmapp, &iter, sptep)
V_138 |= F_113 ( V_100 , V_14 ) ;
return V_138 ;
}
static bool F_115 ( struct V_100 * V_100 , T_1 * V_14 )
{
T_1 V_10 = * V_14 ;
F_92 ( L_11 , V_14 , * V_14 ) ;
V_10 |= V_31 ;
return F_45 ( V_14 , V_10 ) ;
}
static bool F_116 ( struct V_100 * V_100 , unsigned long * V_129 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
F_112 (rmapp, &iter, sptep)
V_138 |= F_115 ( V_100 , V_14 ) ;
return V_138 ;
}
static void F_117 ( struct V_100 * V_100 ,
struct V_95 * V_96 ,
T_2 V_139 , unsigned long V_4 )
{
unsigned long * V_129 ;
while ( V_4 ) {
V_129 = F_99 ( V_96 -> V_98 + V_139 + F_118 ( V_4 ) ,
V_41 , V_96 ) ;
F_111 ( V_100 , V_129 , false ) ;
V_4 &= V_4 - 1 ;
}
}
void F_119 ( struct V_100 * V_100 ,
struct V_95 * V_96 ,
T_2 V_139 , unsigned long V_4 )
{
unsigned long * V_129 ;
while ( V_4 ) {
V_129 = F_99 ( V_96 -> V_98 + V_139 + F_118 ( V_4 ) ,
V_41 , V_96 ) ;
F_114 ( V_100 , V_129 ) ;
V_4 &= V_4 - 1 ;
}
}
void F_120 ( struct V_100 * V_100 ,
struct V_95 * V_96 ,
T_2 V_139 , unsigned long V_4 )
{
if ( V_117 -> V_140 )
V_117 -> V_140 ( V_100 , V_96 , V_139 ,
V_4 ) ;
else
F_117 ( V_100 , V_96 , V_139 , V_4 ) ;
}
static bool F_121 ( struct V_11 * V_12 , T_1 V_15 )
{
struct V_95 * V_96 ;
unsigned long * V_129 ;
int V_104 ;
bool V_141 = false ;
V_96 = F_84 ( V_12 , V_15 ) ;
for ( V_104 = V_41 ; V_104 <= V_106 ; ++ V_104 ) {
V_129 = F_99 ( V_15 , V_104 , V_96 ) ;
V_141 |= F_111 ( V_12 -> V_100 , V_129 , true ) ;
}
return V_141 ;
}
static bool F_122 ( struct V_100 * V_100 , unsigned long * V_129 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
bool V_138 = false ;
while ( ( V_14 = F_104 ( * V_129 , & V_132 ) ) ) {
F_72 ( ! ( * V_14 & V_38 ) ) ;
F_92 ( L_12 , V_142 , V_14 , * V_14 ) ;
F_106 ( V_100 , V_14 ) ;
V_138 = true ;
}
return V_138 ;
}
static int F_123 ( struct V_100 * V_100 , unsigned long * V_129 ,
struct V_95 * V_96 , T_2 V_15 , int V_40 ,
unsigned long V_143 )
{
return F_122 ( V_100 , V_129 ) ;
}
static int F_124 ( struct V_100 * V_100 , unsigned long * V_129 ,
struct V_95 * V_96 , T_2 V_15 , int V_40 ,
unsigned long V_143 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
int V_144 = 0 ;
T_1 V_62 ;
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
F_106 ( V_100 , V_14 ) ;
goto V_147;
} else {
V_62 = * V_14 & ~ V_42 ;
V_62 |= ( T_1 ) V_146 << V_19 ;
V_62 &= ~ V_137 ;
V_62 &= ~ V_59 ;
V_62 &= ~ V_30 ;
F_48 ( V_14 ) ;
F_9 ( V_14 , V_62 ) ;
}
}
if ( V_144 )
F_109 ( V_100 ) ;
return 0 ;
}
static void
F_128 ( struct V_148 * V_149 , int V_40 )
{
V_149 -> V_40 = V_40 ;
V_149 -> V_15 = V_149 -> V_150 ;
V_149 -> V_128 = F_99 ( V_149 -> V_15 , V_40 , V_149 -> V_96 ) ;
V_149 -> V_151 = F_99 ( V_149 -> V_152 , V_40 ,
V_149 -> V_96 ) ;
}
static void
F_129 ( struct V_148 * V_149 ,
struct V_95 * V_96 , int V_153 ,
int V_154 , T_2 V_150 , T_2 V_152 )
{
V_149 -> V_96 = V_96 ;
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
static int F_133 ( struct V_100 * V_100 ,
unsigned long V_155 ,
unsigned long V_156 ,
unsigned long V_143 ,
int (* F_134)( struct V_100 * V_100 ,
unsigned long * V_129 ,
struct V_95 * V_96 ,
T_2 V_15 ,
int V_40 ,
unsigned long V_143 ) )
{
struct V_101 * V_102 ;
struct V_95 * V_157 ;
struct V_148 V_149 ;
int V_64 = 0 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_158 ; V_104 ++ ) {
V_102 = F_135 ( V_100 , V_104 ) ;
F_136 (memslot, slots) {
unsigned long V_159 , V_160 ;
T_2 V_161 , V_162 ;
V_159 = F_137 ( V_155 , V_157 -> V_163 ) ;
V_160 = V_72 ( V_156 , V_157 -> V_163 +
( V_157 -> V_164 << V_19 ) ) ;
if ( V_159 >= V_160 )
continue;
V_161 = F_138 ( V_159 , V_157 ) ;
V_162 = F_138 ( V_160 + V_165 - 1 , V_157 ) ;
F_139 (memslot, PT_PAGE_TABLE_LEVEL,
PT_MAX_HUGEPAGE_LEVEL,
gfn_start, gfn_end - 1 ,
&iterator)
V_64 |= F_134 ( V_100 , V_149 . V_128 , V_157 ,
V_149 . V_15 , V_149 . V_40 , V_143 ) ;
}
}
return V_64 ;
}
static int F_140 ( struct V_100 * V_100 , unsigned long V_166 ,
unsigned long V_143 ,
int (* F_134)( struct V_100 * V_100 , unsigned long * V_129 ,
struct V_95 * V_96 ,
T_2 V_15 , int V_40 ,
unsigned long V_143 ) )
{
return F_133 ( V_100 , V_166 , V_166 + 1 , V_143 , F_134 ) ;
}
int F_141 ( struct V_100 * V_100 , unsigned long V_166 )
{
return F_140 ( V_100 , V_166 , 0 , F_123 ) ;
}
int F_142 ( struct V_100 * V_100 , unsigned long V_155 , unsigned long V_156 )
{
return F_133 ( V_100 , V_155 , V_156 , 0 , F_123 ) ;
}
void F_143 ( struct V_100 * V_100 , unsigned long V_166 , T_6 V_37 )
{
F_140 ( V_100 , V_166 , ( unsigned long ) & V_37 , F_124 ) ;
}
static int F_144 ( struct V_100 * V_100 , unsigned long * V_129 ,
struct V_95 * V_96 , T_2 V_15 , int V_40 ,
unsigned long V_143 )
{
T_1 * V_14 ;
struct V_131 V_167 ( V_132 ) ;
int V_168 = 0 ;
F_72 ( ! V_30 ) ;
F_112 (rmapp, &iter, sptep)
if ( * V_14 & V_30 ) {
V_168 = 1 ;
F_145 ( ( F_146 ( V_30 ) - 1 ) ,
( unsigned long * ) V_14 ) ;
}
F_147 ( V_15 , V_40 , V_96 , V_168 ) ;
return V_168 ;
}
static int F_148 ( struct V_100 * V_100 , unsigned long * V_129 ,
struct V_95 * V_96 , T_2 V_15 ,
int V_40 , unsigned long V_143 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
int V_168 = 0 ;
if ( ! V_30 )
goto V_84;
F_112 (rmapp, &iter, sptep)
if ( * V_14 & V_30 ) {
V_168 = 1 ;
break;
}
V_84:
return V_168 ;
}
static void F_149 ( struct V_11 * V_12 , T_1 * V_10 , T_2 V_15 )
{
unsigned long * V_129 ;
struct V_47 * V_48 ;
V_48 = F_36 ( F_37 ( V_10 ) ) ;
V_129 = F_100 ( V_12 -> V_100 , V_15 , V_48 ) ;
F_123 ( V_12 -> V_100 , V_129 , NULL , V_15 , V_48 -> V_90 . V_40 , 0 ) ;
F_109 ( V_12 -> V_100 ) ;
}
int F_150 ( struct V_100 * V_100 , unsigned long V_155 , unsigned long V_156 )
{
if ( ! V_30 ) {
V_100 -> V_169 ++ ;
return F_133 ( V_100 , V_155 , V_156 , 0 ,
F_123 ) ;
}
return F_133 ( V_100 , V_155 , V_156 , 0 , F_144 ) ;
}
int F_151 ( struct V_100 * V_100 , unsigned long V_166 )
{
return F_140 ( V_100 , V_166 , 0 , F_148 ) ;
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
static inline void F_153 ( struct V_100 * V_100 , int V_170 )
{
V_100 -> V_34 . V_171 += V_170 ;
F_154 ( & V_172 , V_170 ) ;
}
static void F_155 ( struct V_47 * V_48 )
{
F_156 ( ! F_152 ( V_48 -> V_130 ) ) ;
F_157 ( & V_48 -> V_173 ) ;
F_158 ( & V_48 -> V_174 ) ;
F_68 ( ( unsigned long ) V_48 -> V_130 ) ;
if ( ! V_48 -> V_90 . V_91 )
F_68 ( ( unsigned long ) V_48 -> V_92 ) ;
F_64 ( V_86 , V_48 ) ;
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
F_52 ( V_176 ) ;
}
static struct V_47 * F_163 ( struct V_11 * V_12 ,
T_1 * V_176 , int V_91 )
{
struct V_47 * V_48 ;
V_48 = F_71 ( & V_12 -> V_34 . V_86 ) ;
V_48 -> V_130 = F_71 ( & V_12 -> V_34 . V_85 ) ;
if ( ! V_91 )
V_48 -> V_92 = F_71 ( & V_12 -> V_34 . V_85 ) ;
F_164 ( F_165 ( V_48 -> V_130 ) , ( unsigned long ) V_48 ) ;
F_166 ( & V_48 -> V_174 , & V_12 -> V_100 -> V_34 . V_178 ) ;
V_48 -> V_177 = 0 ;
F_160 ( V_12 , V_48 , V_176 ) ;
F_153 ( V_12 -> V_100 , + 1 ) ;
return V_48 ;
}
static void F_167 ( struct V_47 * V_48 )
{
F_98 ( & V_48 -> V_177 , V_179 ) ;
}
static void V_179 ( T_1 * V_10 )
{
struct V_47 * V_48 ;
unsigned int V_89 ;
V_48 = F_36 ( F_37 ( V_10 ) ) ;
V_89 = V_10 - V_48 -> V_130 ;
if ( F_168 ( V_89 , V_48 -> V_180 ) )
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
int V_97 )
{
int V_104 ;
if ( V_48 -> V_185 )
for ( V_104 = 0 ; V_104 < V_184 -> V_170 ; V_104 ++ )
if ( V_184 -> V_79 [ V_104 ] . V_48 == V_48 )
return 0 ;
V_184 -> V_79 [ V_184 -> V_170 ] . V_48 = V_48 ;
V_184 -> V_79 [ V_184 -> V_170 ] . V_97 = V_97 ;
V_184 -> V_170 ++ ;
return ( V_184 -> V_170 == V_186 ) ;
}
static int F_173 ( struct V_47 * V_48 ,
struct V_183 * V_184 )
{
int V_104 , V_64 , V_187 = 0 ;
F_174 (i, sp->unsync_child_bitmap, 512 ) {
struct V_47 * V_188 ;
T_1 V_189 = V_48 -> V_130 [ V_104 ] ;
if ( ! F_22 ( V_189 ) || F_23 ( V_189 ) )
goto V_190;
V_188 = F_36 ( V_189 & V_42 ) ;
if ( V_188 -> V_181 ) {
if ( F_172 ( V_184 , V_188 , V_104 ) )
return - V_191 ;
V_64 = F_173 ( V_188 , V_184 ) ;
if ( ! V_64 )
goto V_190;
else if ( V_64 > 0 )
V_187 += V_64 ;
else
return V_64 ;
} else if ( V_188 -> V_185 ) {
V_187 ++ ;
if ( F_172 ( V_184 , V_188 , V_104 ) )
return - V_191 ;
} else
goto V_190;
continue;
V_190:
F_175 ( V_104 , V_48 -> V_180 ) ;
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
static void F_177 ( struct V_100 * V_100 , struct V_47 * V_48 )
{
F_3 ( ! V_48 -> V_185 ) ;
F_178 ( V_48 ) ;
V_48 -> V_185 = 0 ;
-- V_100 -> V_134 . V_192 ;
}
static int F_179 ( struct V_11 * V_12 , struct V_47 * V_48 ,
struct V_193 * V_194 , bool V_195 )
{
if ( V_48 -> V_90 . V_196 != ! ! F_180 ( V_12 ) ) {
F_181 ( V_12 -> V_100 , V_48 , V_194 ) ;
return 1 ;
}
if ( V_195 )
F_177 ( V_12 -> V_100 , V_48 ) ;
if ( V_12 -> V_34 . V_197 . V_198 ( V_12 , V_48 ) ) {
F_181 ( V_12 -> V_100 , V_48 , V_194 ) ;
return 1 ;
}
F_182 ( V_199 , V_12 ) ;
return 0 ;
}
static int F_183 ( struct V_11 * V_12 ,
struct V_47 * V_48 )
{
F_184 ( V_194 ) ;
int V_64 ;
V_64 = F_179 ( V_12 , V_48 , & V_194 , false ) ;
if ( V_64 )
F_185 ( V_12 -> V_100 , & V_194 ) ;
return V_64 ;
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
F_3 ( V_201 -> V_90 . V_40 != V_41 ) ;
F_177 ( V_12 -> V_100 , V_201 ) ;
if ( ( V_201 -> V_90 . V_196 != ! ! F_180 ( V_12 ) ) ||
( V_12 -> V_34 . V_197 . V_198 ( V_12 , V_201 ) ) ) {
F_181 ( V_12 -> V_100 , V_201 , & V_194 ) ;
continue;
}
V_138 = true ;
}
F_185 ( V_12 -> V_100 , & V_194 ) ;
if ( V_138 )
F_182 ( V_199 , V_12 ) ;
}
static int F_191 ( struct V_183 * V_184 ,
struct V_202 * V_203 ,
int V_104 )
{
int V_204 ;
for ( V_204 = V_104 + 1 ; V_204 < V_184 -> V_170 ; V_204 ++ ) {
struct V_47 * V_48 = V_184 -> V_79 [ V_204 ] . V_48 ;
if ( V_48 -> V_90 . V_40 == V_41 ) {
V_203 -> V_97 [ 0 ] = V_184 -> V_79 [ V_204 ] . V_97 ;
return V_204 ;
}
V_203 -> V_205 [ V_48 -> V_90 . V_40 - 2 ] = V_48 ;
V_203 -> V_97 [ V_48 -> V_90 . V_40 - 1 ] = V_184 -> V_79 [ V_204 ] . V_97 ;
}
return V_204 ;
}
static void F_192 ( struct V_202 * V_203 )
{
struct V_47 * V_48 ;
unsigned int V_40 = 0 ;
do {
unsigned int V_97 = V_203 -> V_97 [ V_40 ] ;
V_48 = V_203 -> V_205 [ V_40 ] ;
if ( ! V_48 )
return;
-- V_48 -> V_181 ;
F_3 ( ( int ) V_48 -> V_181 < 0 ) ;
F_175 ( V_97 , V_48 -> V_180 ) ;
V_40 ++ ;
} while ( V_40 < V_206 - 1 && ! V_48 -> V_181 );
}
static void F_193 ( struct V_47 * V_205 ,
struct V_202 * V_203 ,
struct V_183 * V_184 )
{
V_203 -> V_205 [ V_205 -> V_90 . V_40 - 1 ] = NULL ;
V_184 -> V_170 = 0 ;
}
static void F_194 ( struct V_11 * V_12 ,
struct V_47 * V_205 )
{
int V_104 ;
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
F_109 ( V_12 -> V_100 ) ;
F_195 (pages, sp, parents, i) {
F_188 ( V_12 , V_48 , & V_194 ) ;
F_192 ( & V_203 ) ;
}
F_185 ( V_12 -> V_100 , & V_194 ) ;
F_196 ( & V_12 -> V_100 -> V_209 ) ;
F_193 ( V_205 , & V_203 , & V_207 ) ;
}
}
static void F_197 ( struct V_47 * V_48 )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < V_210 ; ++ V_104 )
V_48 -> V_130 [ V_104 ] = 0ull ;
}
static void F_198 ( struct V_47 * V_48 )
{
V_48 -> V_211 = 0 ;
}
static void F_199 ( T_1 * V_10 )
{
struct V_47 * V_48 = F_36 ( F_37 ( V_10 ) ) ;
F_198 ( V_48 ) ;
}
static bool F_200 ( struct V_100 * V_100 , struct V_47 * V_48 )
{
return F_14 ( V_48 -> V_212 != V_100 -> V_34 . V_212 ) ;
}
static struct V_47 * F_201 ( struct V_11 * V_12 ,
T_2 V_15 ,
T_7 V_213 ,
unsigned V_40 ,
int V_91 ,
unsigned V_16 ,
T_1 * V_176 )
{
union V_214 V_90 ;
unsigned V_215 ;
struct V_47 * V_48 ;
bool V_216 = false ;
V_90 = V_12 -> V_34 . V_197 . V_217 ;
V_90 . V_40 = V_40 ;
V_90 . V_91 = V_91 ;
if ( V_90 . V_91 )
V_90 . V_196 = 0 ;
V_90 . V_16 = V_16 ;
if ( ! V_12 -> V_34 . V_197 . V_218
&& V_12 -> V_34 . V_197 . V_219 <= V_220 ) {
V_215 = V_213 >> ( V_19 + ( V_221 * V_40 ) ) ;
V_215 &= ( 1 << ( ( V_222 - V_221 ) * V_40 ) ) - 1 ;
V_90 . V_215 = V_215 ;
}
F_202 (vcpu->kvm, sp, gfn) {
if ( F_200 ( V_12 -> V_100 , V_48 ) )
continue;
if ( ! V_216 && V_48 -> V_185 )
V_216 = true ;
if ( V_48 -> V_90 . V_223 != V_90 . V_223 )
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
++ V_12 -> V_100 -> V_134 . V_225 ;
V_48 = F_163 ( V_12 , V_176 , V_91 ) ;
if ( ! V_48 )
return V_48 ;
V_48 -> V_15 = V_15 ;
V_48 -> V_90 = V_90 ;
F_204 ( & V_48 -> V_173 ,
& V_12 -> V_100 -> V_34 . V_226 [ F_159 ( V_15 ) ] ) ;
if ( ! V_91 ) {
if ( F_121 ( V_12 , V_15 ) )
F_109 ( V_12 -> V_100 ) ;
if ( V_40 > V_41 && V_216 )
F_189 ( V_12 , V_15 ) ;
F_79 ( V_12 -> V_100 , V_48 ) ;
}
V_48 -> V_212 = V_12 -> V_100 -> V_34 . V_212 ;
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
V_149 -> V_89 = F_207 ( V_149 -> V_228 , V_149 -> V_40 ) ;
V_149 -> V_14 = ( ( T_1 * ) F_208 ( V_149 -> V_229 ) ) + V_149 -> V_89 ;
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
V_10 = F_37 ( V_48 -> V_130 ) | V_38 | V_137 |
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
V_188 = F_36 ( * V_14 & V_42 ) ;
if ( V_188 -> V_90 . V_16 == V_237 )
return;
F_162 ( V_188 , V_14 ) ;
F_109 ( V_12 -> V_100 ) ;
}
}
static bool F_214 ( struct V_100 * V_100 , struct V_47 * V_48 ,
T_1 * V_10 )
{
T_1 V_37 ;
struct V_47 * V_188 ;
V_37 = * V_10 ;
if ( F_22 ( V_37 ) ) {
if ( F_25 ( V_37 , V_48 -> V_90 . V_40 ) ) {
F_106 ( V_100 , V_10 ) ;
if ( F_23 ( V_37 ) )
-- V_100 -> V_134 . V_135 ;
} else {
V_188 = F_36 ( V_37 & V_42 ) ;
F_162 ( V_188 , V_10 ) ;
}
return true ;
}
if ( F_10 ( V_37 ) )
F_52 ( V_10 ) ;
return false ;
}
static void F_215 ( struct V_100 * V_100 ,
struct V_47 * V_48 )
{
unsigned V_104 ;
for ( V_104 = 0 ; V_104 < V_210 ; ++ V_104 )
F_214 ( V_100 , V_48 , V_48 -> V_130 + V_104 ) ;
}
static void F_216 ( struct V_47 * V_48 , T_1 * V_176 )
{
F_161 ( V_48 , V_176 ) ;
}
static void F_217 ( struct V_100 * V_100 , struct V_47 * V_48 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
while ( ( V_14 = F_104 ( V_48 -> V_177 , & V_132 ) ) )
F_162 ( V_48 , V_14 ) ;
}
static int F_218 ( struct V_100 * V_100 ,
struct V_47 * V_205 ,
struct V_193 * V_194 )
{
int V_104 , V_238 = 0 ;
struct V_202 V_203 ;
struct V_183 V_207 ;
if ( V_205 -> V_90 . V_40 == V_41 )
return 0 ;
F_193 ( V_205 , & V_203 , & V_207 ) ;
while ( F_176 ( V_205 , & V_207 ) ) {
struct V_47 * V_48 ;
F_195 (pages, sp, parents, i) {
F_181 ( V_100 , V_48 , V_194 ) ;
F_192 ( & V_203 ) ;
V_238 ++ ;
}
F_193 ( V_205 , & V_203 , & V_207 ) ;
}
return V_238 ;
}
static int F_181 ( struct V_100 * V_100 , struct V_47 * V_48 ,
struct V_193 * V_194 )
{
int V_64 ;
F_219 ( V_48 ) ;
++ V_100 -> V_134 . V_239 ;
V_64 = F_218 ( V_100 , V_48 , V_194 ) ;
F_215 ( V_100 , V_48 ) ;
F_217 ( V_100 , V_48 ) ;
if ( ! V_48 -> V_90 . V_240 && ! V_48 -> V_90 . V_91 )
F_82 ( V_100 , V_48 ) ;
if ( V_48 -> V_185 )
F_177 ( V_100 , V_48 ) ;
if ( ! V_48 -> V_241 ) {
V_64 ++ ;
F_220 ( & V_48 -> V_174 , V_194 ) ;
F_153 ( V_100 , - 1 ) ;
} else {
F_220 ( & V_48 -> V_174 , & V_100 -> V_34 . V_178 ) ;
if ( ! V_48 -> V_90 . V_240 && ! F_200 ( V_100 , V_48 ) )
F_221 ( V_100 ) ;
}
V_48 -> V_90 . V_240 = 1 ;
return V_64 ;
}
static void F_185 ( struct V_100 * V_100 ,
struct V_193 * V_194 )
{
struct V_47 * V_48 , * V_242 ;
if ( F_222 ( V_194 ) )
return;
F_56 () ;
F_109 ( V_100 ) ;
F_223 (sp, nsp, invalid_list, link) {
F_3 ( ! V_48 -> V_90 . V_240 || V_48 -> V_241 ) ;
F_155 ( V_48 ) ;
}
}
static bool F_224 ( struct V_100 * V_100 ,
struct V_193 * V_194 )
{
struct V_47 * V_48 ;
if ( F_222 ( & V_100 -> V_34 . V_178 ) )
return false ;
V_48 = F_225 ( V_100 -> V_34 . V_178 . V_243 ,
struct V_47 , V_174 ) ;
F_181 ( V_100 , V_48 , V_194 ) ;
return true ;
}
void F_226 ( struct V_100 * V_100 , unsigned int V_244 )
{
F_184 ( V_194 ) ;
F_227 ( & V_100 -> V_209 ) ;
if ( V_100 -> V_34 . V_171 > V_244 ) {
while ( V_100 -> V_34 . V_171 > V_244 )
if ( ! F_224 ( V_100 , & V_194 ) )
break;
F_185 ( V_100 , & V_194 ) ;
V_244 = V_100 -> V_34 . V_171 ;
}
V_100 -> V_34 . V_245 = V_244 ;
F_228 ( & V_100 -> V_209 ) ;
}
int F_229 ( struct V_100 * V_100 , T_2 V_15 )
{
struct V_47 * V_48 ;
F_184 ( V_194 ) ;
int V_80 ;
F_230 ( L_15 , V_142 , V_15 ) ;
V_80 = 0 ;
F_227 ( & V_100 -> V_209 ) ;
F_190 (kvm, sp, gfn) {
F_230 ( L_16 , V_142 , V_15 ,
V_48 -> V_90 . V_223 ) ;
V_80 = 1 ;
F_181 ( V_100 , V_48 , & V_194 ) ;
}
F_185 ( V_100 , & V_194 ) ;
F_228 ( & V_100 -> V_209 ) ;
return V_80 ;
}
static void F_231 ( struct V_11 * V_12 , struct V_47 * V_48 )
{
F_232 ( V_48 ) ;
++ V_12 -> V_100 -> V_134 . V_192 ;
V_48 -> V_185 = 1 ;
F_167 ( V_48 ) ;
}
static void F_233 ( struct V_11 * V_12 , T_2 V_15 )
{
struct V_47 * V_201 ;
F_190 (vcpu->kvm, s, gfn) {
if ( V_201 -> V_185 )
continue;
F_3 ( V_201 -> V_90 . V_40 != V_41 ) ;
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
if ( V_201 -> V_90 . V_40 != V_41 )
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
return ! F_237 ( V_21 ) && F_238 ( F_51 ( V_21 ) ) ;
return true ;
}
static int F_239 ( struct V_11 * V_12 , T_1 * V_14 ,
unsigned V_248 , int V_40 ,
T_2 V_15 , T_3 V_21 , bool V_249 ,
bool V_246 , bool V_250 )
{
T_1 V_10 ;
int V_64 = 0 ;
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
V_10 |= V_59 ;
else
V_248 &= ~ V_17 ;
V_10 |= ( T_1 ) V_21 << V_19 ;
if ( V_248 & V_17 ) {
if ( V_40 > V_41 &&
F_83 ( V_12 , V_15 , V_40 ) )
goto V_254;
V_10 |= V_137 | V_60 ;
if ( ! V_246 && F_42 ( * V_14 ) )
goto V_255;
if ( F_234 ( V_12 , V_15 , V_246 ) ) {
F_230 ( L_17 ,
V_142 , V_15 ) ;
V_64 = 1 ;
V_248 &= ~ V_17 ;
V_10 &= ~ ( V_137 | V_60 ) ;
}
}
if ( V_248 & V_17 ) {
F_240 ( V_12 , V_15 ) ;
V_10 |= V_31 ;
}
V_255:
if ( F_45 ( V_14 , V_10 ) )
F_109 ( V_12 -> V_100 ) ;
V_254:
return V_64 ;
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
V_188 = F_36 ( V_37 & V_42 ) ;
F_162 ( V_188 , V_14 ) ;
F_109 ( V_12 -> V_100 ) ;
} else if ( V_21 != F_26 ( * V_14 ) ) {
F_230 ( L_19 ,
F_26 ( * V_14 ) , V_21 ) ;
F_106 ( V_12 -> V_100 , V_14 ) ;
F_109 ( V_12 -> V_100 ) ;
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
++ V_12 -> V_100 -> V_134 . V_135 ;
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
bool V_110 )
{
struct V_95 * V_96 ;
V_96 = F_88 ( V_12 , V_15 , V_110 ) ;
if ( ! V_96 )
return V_261 ;
return F_244 ( V_96 , V_15 ) ;
}
static int F_245 ( struct V_11 * V_12 ,
struct V_47 * V_48 ,
T_1 * V_155 , T_1 * V_156 )
{
struct V_79 * V_207 [ V_83 ] ;
struct V_95 * V_96 ;
unsigned V_16 = V_48 -> V_90 . V_16 ;
int V_104 , V_64 ;
T_2 V_15 ;
V_15 = F_75 ( V_48 , V_155 - V_48 -> V_130 ) ;
V_96 = F_88 ( V_12 , V_15 , V_16 & V_17 ) ;
if ( ! V_96 )
return - 1 ;
V_64 = F_246 ( V_96 , V_15 , V_207 , V_156 - V_155 ) ;
if ( V_64 <= 0 )
return - 1 ;
for ( V_104 = 0 ; V_104 < V_64 ; V_104 ++ , V_15 ++ , V_155 ++ )
F_241 ( V_12 , V_155 , V_16 , 0 , NULL ,
V_48 -> V_90 . V_40 , V_15 , F_247 ( V_207 [ V_104 ] ) ,
true , true ) ;
return 0 ;
}
static void F_248 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_14 )
{
T_1 * V_10 , * V_155 = NULL ;
int V_104 ;
F_3 ( ! V_48 -> V_90 . V_91 ) ;
V_104 = ( V_14 - V_48 -> V_130 ) & ~ ( V_83 - 1 ) ;
V_10 = V_48 -> V_130 + V_104 ;
for ( V_104 = 0 ; V_104 < V_83 ; V_104 ++ , V_10 ++ ) {
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
V_48 = F_36 ( F_37 ( V_14 ) ) ;
if ( V_48 -> V_90 . V_40 > V_41 )
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
if ( ! F_259 ( V_21 ) && ! F_49 ( V_21 ) &&
V_40 == V_41 &&
F_260 ( F_51 ( V_21 ) ) &&
! F_83 ( V_12 , V_15 , V_105 ) ) {
unsigned long V_4 ;
* V_288 = V_40 = V_105 ;
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
bool V_64 = true ;
if ( F_14 ( F_265 ( V_21 ) ) ) {
* V_289 = F_256 ( V_12 , V_15 , V_21 ) ;
goto exit;
}
if ( F_14 ( F_15 ( V_21 ) ) )
F_266 ( V_12 , V_182 , V_15 , V_16 ) ;
V_64 = false ;
exit:
return V_64 ;
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
F_3 ( ! V_48 -> V_90 . V_91 ) ;
V_15 = F_75 ( V_48 , V_14 - V_48 -> V_130 ) ;
if ( F_269 ( V_14 , V_10 , V_10 | V_137 ) == V_10 )
F_240 ( V_12 , V_15 ) ;
return true ;
}
static bool F_270 ( struct V_11 * V_12 , T_7 V_182 , int V_40 ,
T_4 V_290 )
{
struct V_227 V_149 ;
struct V_47 * V_48 ;
bool V_64 = false ;
T_1 V_10 = 0ull ;
if ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) )
return false ;
if ( ! F_267 ( V_290 ) )
return false ;
F_54 ( V_12 ) ;
F_271 (vcpu, gva, iterator, spte)
if ( ! F_22 ( V_10 ) || V_149 . V_40 < V_40 )
break;
if ( ! F_24 ( V_10 ) ) {
V_64 = true ;
goto exit;
}
V_48 = F_36 ( F_37 ( V_149 . V_14 ) ) ;
if ( ! F_25 ( V_10 , V_48 -> V_90 . V_40 ) )
goto exit;
if ( F_42 ( V_10 ) ) {
V_64 = true ;
goto exit;
}
if ( ! F_40 ( V_10 ) )
goto exit;
if ( V_48 -> V_90 . V_40 > V_41 )
goto exit;
V_64 = F_268 ( V_12 , V_48 , V_149 . V_14 , V_10 ) ;
exit:
F_272 ( V_12 , V_182 , V_290 , V_149 . V_14 ,
V_10 , V_64 ) ;
F_57 ( V_12 ) ;
return V_64 ;
}
static int F_273 ( struct V_11 * V_12 , T_7 V_262 , T_4 V_290 ,
T_2 V_15 , bool V_265 )
{
int V_80 ;
int V_40 ;
int V_294 ;
T_3 V_21 ;
unsigned long V_295 ;
bool V_264 , V_263 = V_290 & V_293 ;
V_294 = F_89 ( V_12 , V_15 ) ;
if ( F_18 ( ! V_294 ) ) {
V_40 = F_90 ( V_12 , V_15 ) ;
if ( V_40 > V_105 )
V_40 = V_105 ;
V_15 &= ~ ( F_261 ( V_40 ) - 1 ) ;
} else
V_40 = V_41 ;
if ( F_270 ( V_12 , V_262 , V_40 , V_290 ) )
return 0 ;
V_295 = V_12 -> V_100 -> V_169 ;
F_39 () ;
if ( F_274 ( V_12 , V_265 , V_15 , V_262 , & V_21 , V_263 , & V_264 ) )
return 0 ;
if ( F_264 ( V_12 , V_262 , V_15 , V_21 , V_267 , & V_80 ) )
return V_80 ;
F_227 ( & V_12 -> V_100 -> V_209 ) ;
if ( F_275 ( V_12 -> V_100 , V_295 ) )
goto V_296;
F_276 ( V_12 ) ;
if ( F_18 ( ! V_294 ) )
F_258 ( V_12 , & V_15 , & V_21 , & V_40 ) ;
V_80 = F_250 ( V_12 , V_262 , V_263 , V_264 , V_40 , V_15 , V_21 ,
V_265 ) ;
F_228 ( & V_12 -> V_100 -> V_209 ) ;
return V_80 ;
V_296:
F_228 ( & V_12 -> V_100 -> V_209 ) ;
F_242 ( V_21 ) ;
return 0 ;
}
static void F_277 ( struct V_11 * V_12 )
{
int V_104 ;
struct V_47 * V_48 ;
F_184 ( V_194 ) ;
if ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) )
return;
if ( V_12 -> V_34 . V_197 . V_231 == V_206 &&
( V_12 -> V_34 . V_197 . V_219 == V_206 ||
V_12 -> V_34 . V_197 . V_218 ) ) {
T_10 V_297 = V_12 -> V_34 . V_197 . V_230 ;
F_227 ( & V_12 -> V_100 -> V_209 ) ;
V_48 = F_36 ( V_297 ) ;
-- V_48 -> V_241 ;
if ( ! V_48 -> V_241 && V_48 -> V_90 . V_240 ) {
F_181 ( V_12 -> V_100 , V_48 , & V_194 ) ;
F_185 ( V_12 -> V_100 , & V_194 ) ;
}
F_228 ( & V_12 -> V_100 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_230 = V_298 ;
return;
}
F_227 ( & V_12 -> V_100 -> V_209 ) ;
for ( V_104 = 0 ; V_104 < 4 ; ++ V_104 ) {
T_10 V_297 = V_12 -> V_34 . V_197 . V_233 [ V_104 ] ;
if ( V_297 ) {
V_297 &= V_42 ;
V_48 = F_36 ( V_297 ) ;
-- V_48 -> V_241 ;
if ( ! V_48 -> V_241 && V_48 -> V_90 . V_240 )
F_181 ( V_12 -> V_100 , V_48 ,
& V_194 ) ;
}
V_12 -> V_34 . V_197 . V_233 [ V_104 ] = V_298 ;
}
F_185 ( V_12 -> V_100 , & V_194 ) ;
F_228 ( & V_12 -> V_100 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_230 = V_298 ;
}
static int F_278 ( struct V_11 * V_12 , T_2 V_299 )
{
int V_64 = 0 ;
if ( ! F_279 ( V_12 -> V_100 , V_299 ) ) {
F_182 ( V_300 , V_12 ) ;
V_64 = 1 ;
}
return V_64 ;
}
static int F_280 ( struct V_11 * V_12 )
{
struct V_47 * V_48 ;
unsigned V_104 ;
if ( V_12 -> V_34 . V_197 . V_231 == V_206 ) {
F_227 ( & V_12 -> V_100 -> V_209 ) ;
F_276 ( V_12 ) ;
V_48 = F_201 ( V_12 , 0 , 0 , V_206 ,
1 , V_267 , NULL ) ;
++ V_48 -> V_241 ;
F_228 ( & V_12 -> V_100 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_230 = F_37 ( V_48 -> V_130 ) ;
} else if ( V_12 -> V_34 . V_197 . V_231 == V_232 ) {
for ( V_104 = 0 ; V_104 < 4 ; ++ V_104 ) {
T_10 V_297 = V_12 -> V_34 . V_197 . V_233 [ V_104 ] ;
F_156 ( F_251 ( V_297 ) ) ;
F_227 ( & V_12 -> V_100 -> V_209 ) ;
F_276 ( V_12 ) ;
V_48 = F_201 ( V_12 , V_104 << ( 30 - V_19 ) ,
V_104 << 30 ,
V_220 , 1 , V_267 ,
NULL ) ;
V_297 = F_37 ( V_48 -> V_130 ) ;
++ V_48 -> V_241 ;
F_228 ( & V_12 -> V_100 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_233 [ V_104 ] = V_297 | V_38 ;
}
V_12 -> V_34 . V_197 . V_230 = F_37 ( V_12 -> V_34 . V_197 . V_233 ) ;
} else
F_96 () ;
return 0 ;
}
static int F_281 ( struct V_11 * V_12 )
{
struct V_47 * V_48 ;
T_1 V_301 , V_302 ;
T_2 V_299 ;
int V_104 ;
V_299 = V_12 -> V_34 . V_197 . V_303 ( V_12 ) >> V_19 ;
if ( F_278 ( V_12 , V_299 ) )
return 1 ;
if ( V_12 -> V_34 . V_197 . V_219 == V_206 ) {
T_10 V_297 = V_12 -> V_34 . V_197 . V_230 ;
F_156 ( F_251 ( V_297 ) ) ;
F_227 ( & V_12 -> V_100 -> V_209 ) ;
F_276 ( V_12 ) ;
V_48 = F_201 ( V_12 , V_299 , 0 , V_206 ,
0 , V_267 , NULL ) ;
V_297 = F_37 ( V_48 -> V_130 ) ;
++ V_48 -> V_241 ;
F_228 ( & V_12 -> V_100 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_230 = V_297 ;
return 0 ;
}
V_302 = V_38 ;
if ( V_12 -> V_34 . V_197 . V_231 == V_206 )
V_302 |= V_304 | V_137 | V_305 ;
for ( V_104 = 0 ; V_104 < 4 ; ++ V_104 ) {
T_10 V_297 = V_12 -> V_34 . V_197 . V_233 [ V_104 ] ;
F_156 ( F_251 ( V_297 ) ) ;
if ( V_12 -> V_34 . V_197 . V_219 == V_232 ) {
V_301 = V_12 -> V_34 . V_197 . V_306 ( V_12 , V_104 ) ;
if ( ! F_282 ( V_301 ) ) {
V_12 -> V_34 . V_197 . V_233 [ V_104 ] = 0 ;
continue;
}
V_299 = V_301 >> V_19 ;
if ( F_278 ( V_12 , V_299 ) )
return 1 ;
}
F_227 ( & V_12 -> V_100 -> V_209 ) ;
F_276 ( V_12 ) ;
V_48 = F_201 ( V_12 , V_299 , V_104 << 30 ,
V_220 , 0 ,
V_267 , NULL ) ;
V_297 = F_37 ( V_48 -> V_130 ) ;
++ V_48 -> V_241 ;
F_228 ( & V_12 -> V_100 -> V_209 ) ;
V_12 -> V_34 . V_197 . V_233 [ V_104 ] = V_297 | V_302 ;
}
V_12 -> V_34 . V_197 . V_230 = F_37 ( V_12 -> V_34 . V_197 . V_233 ) ;
if ( V_12 -> V_34 . V_197 . V_231 == V_206 ) {
if ( V_12 -> V_34 . V_197 . V_307 == NULL ) {
T_1 * V_307 ;
V_307 = ( void * ) F_283 ( V_76 ) ;
if ( V_307 == NULL )
return 1 ;
V_307 [ 0 ] = F_37 ( V_12 -> V_34 . V_197 . V_233 ) | V_302 ;
V_12 -> V_34 . V_197 . V_307 = V_307 ;
}
V_12 -> V_34 . V_197 . V_230 = F_37 ( V_12 -> V_34 . V_197 . V_307 ) ;
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
int V_104 ;
struct V_47 * V_48 ;
if ( V_12 -> V_34 . V_197 . V_218 )
return;
if ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) )
return;
F_286 ( V_12 , V_308 ) ;
F_186 ( V_12 , V_309 ) ;
if ( V_12 -> V_34 . V_197 . V_219 == V_206 ) {
T_10 V_297 = V_12 -> V_34 . V_197 . V_230 ;
V_48 = F_36 ( V_297 ) ;
F_194 ( V_12 , V_48 ) ;
F_186 ( V_12 , V_310 ) ;
return;
}
for ( V_104 = 0 ; V_104 < 4 ; ++ V_104 ) {
T_10 V_297 = V_12 -> V_34 . V_197 . V_233 [ V_104 ] ;
if ( V_297 && F_251 ( V_297 ) ) {
V_297 &= V_42 ;
V_48 = F_36 ( V_297 ) ;
F_194 ( V_12 , V_48 ) ;
}
}
F_186 ( V_12 , V_310 ) ;
}
void F_287 ( struct V_11 * V_12 )
{
F_227 ( & V_12 -> V_100 -> V_209 ) ;
F_285 ( V_12 ) ;
F_228 ( & V_12 -> V_100 -> V_209 ) ;
}
static T_8 F_288 ( struct V_11 * V_12 , T_7 V_311 ,
T_4 V_16 , struct V_312 * V_313 )
{
if ( V_313 )
V_313 -> V_290 = 0 ;
return V_311 ;
}
static T_8 F_289 ( struct V_11 * V_12 , T_7 V_311 ,
T_4 V_16 ,
struct V_312 * V_313 )
{
if ( V_313 )
V_313 -> V_290 = 0 ;
return V_12 -> V_34 . V_314 . V_315 ( V_12 , V_311 , V_16 , V_313 ) ;
}
static bool F_290 ( struct V_11 * V_12 , T_1 V_228 , bool V_91 )
{
if ( V_91 )
return F_291 ( V_12 , V_228 ) ;
return F_292 ( V_12 , V_228 ) ;
}
static bool F_293 ( T_1 V_10 )
{
return F_34 ( V_10 ) ;
}
static T_1 F_294 ( struct V_11 * V_12 , T_1 V_228 )
{
struct V_227 V_149 ;
T_1 V_10 = 0ull ;
if ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) )
return V_10 ;
F_54 ( V_12 ) ;
F_271 (vcpu, addr, iterator, spte)
if ( ! F_22 ( V_10 ) )
break;
F_57 ( V_12 ) ;
return V_10 ;
}
int F_295 ( struct V_11 * V_12 , T_1 V_228 , bool V_91 )
{
T_1 V_10 ;
if ( F_290 ( V_12 , V_228 , V_91 ) )
return V_316 ;
V_10 = F_294 ( V_12 , V_228 ) ;
if ( F_10 ( V_10 ) ) {
T_2 V_15 = F_11 ( V_10 ) ;
unsigned V_16 = F_12 ( V_10 ) ;
if ( ! F_16 ( V_12 , V_10 ) )
return V_317 ;
if ( V_91 )
V_228 = 0 ;
F_296 ( V_228 , V_15 , V_16 ) ;
F_266 ( V_12 , V_228 , V_15 , V_16 ) ;
return V_316 ;
}
if ( V_91 && ! F_293 ( V_10 ) )
return V_318 ;
return V_319 ;
}
static int F_297 ( struct V_11 * V_12 , T_1 V_228 ,
T_4 V_290 , bool V_91 )
{
int V_64 ;
V_64 = F_295 ( V_12 , V_228 , V_91 ) ;
F_3 ( V_64 == V_318 ) ;
return V_64 ;
}
static int F_298 ( struct V_11 * V_12 , T_7 V_182 ,
T_4 V_290 , bool V_265 )
{
T_2 V_15 ;
int V_80 ;
F_230 ( L_26 , V_142 , V_182 , V_290 ) ;
if ( F_14 ( V_290 & V_291 ) ) {
V_80 = F_297 ( V_12 , V_182 , V_290 , true ) ;
if ( F_18 ( V_80 != V_317 ) )
return V_80 ;
}
V_80 = F_69 ( V_12 ) ;
if ( V_80 )
return V_80 ;
F_156 ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) ) ;
V_15 = V_182 >> V_19 ;
return F_273 ( V_12 , V_182 & V_20 ,
V_290 , V_15 , V_265 ) ;
}
static int F_299 ( struct V_11 * V_12 , T_7 V_182 , T_2 V_15 )
{
struct V_320 V_34 ;
V_34 . V_321 = ( V_12 -> V_34 . V_322 . V_323 ++ << 12 ) | V_12 -> V_324 ;
V_34 . V_15 = V_15 ;
V_34 . V_218 = V_12 -> V_34 . V_197 . V_218 ;
V_34 . V_325 = V_12 -> V_34 . V_197 . V_303 ( V_12 ) ;
return F_300 ( V_12 , V_182 , F_257 ( V_12 , V_15 ) , & V_34 ) ;
}
static bool F_301 ( struct V_11 * V_12 )
{
if ( F_14 ( ! F_302 ( V_12 -> V_100 ) ||
F_303 ( V_12 ) ) )
return false ;
return V_117 -> V_326 ( V_12 ) ;
}
static bool F_274 ( struct V_11 * V_12 , bool V_265 , T_2 V_15 ,
T_7 V_182 , T_3 * V_21 , bool V_263 , bool * V_327 )
{
struct V_95 * V_96 ;
bool V_328 ;
V_96 = F_84 ( V_12 , V_15 ) ;
V_328 = false ;
* V_21 = F_304 ( V_96 , V_15 , false , & V_328 , V_263 , V_327 ) ;
if ( ! V_328 )
return false ;
if ( ! V_265 && F_301 ( V_12 ) ) {
F_305 ( V_182 , V_15 ) ;
if ( F_306 ( V_12 , V_15 ) ) {
F_307 ( V_182 , V_15 ) ;
F_182 ( V_329 , V_12 ) ;
return true ;
} else if ( F_299 ( V_12 , V_182 , V_15 ) )
return true ;
}
* V_21 = F_304 ( V_96 , V_15 , false , NULL , V_263 , V_327 ) ;
return false ;
}
static bool
F_308 ( struct V_11 * V_12 , T_2 V_15 , int V_40 )
{
int V_330 = F_261 ( V_40 ) ;
V_15 &= ~ ( V_330 - 1 ) ;
return F_309 ( V_12 , V_15 , V_330 ) ;
}
static int F_310 ( struct V_11 * V_12 , T_7 V_331 , T_4 V_290 ,
bool V_265 )
{
T_3 V_21 ;
int V_80 ;
int V_40 ;
int V_294 ;
T_2 V_15 = V_331 >> V_19 ;
unsigned long V_295 ;
int V_263 = V_290 & V_293 ;
bool V_264 ;
F_156 ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) ) ;
if ( F_14 ( V_290 & V_291 ) ) {
V_80 = F_297 ( V_12 , V_331 , V_290 , true ) ;
if ( F_18 ( V_80 != V_317 ) )
return V_80 ;
}
V_80 = F_69 ( V_12 ) ;
if ( V_80 )
return V_80 ;
if ( F_89 ( V_12 , V_15 ) ||
! F_308 ( V_12 , V_15 , V_105 ) )
V_294 = 1 ;
else
V_294 = 0 ;
if ( F_18 ( ! V_294 ) ) {
V_40 = F_90 ( V_12 , V_15 ) ;
if ( V_40 > V_105 &&
! F_308 ( V_12 , V_15 , V_40 ) )
V_40 = V_105 ;
V_15 &= ~ ( F_261 ( V_40 ) - 1 ) ;
} else
V_40 = V_41 ;
if ( F_270 ( V_12 , V_331 , V_40 , V_290 ) )
return 0 ;
V_295 = V_12 -> V_100 -> V_169 ;
F_39 () ;
if ( F_274 ( V_12 , V_265 , V_15 , V_331 , & V_21 , V_263 , & V_264 ) )
return 0 ;
if ( F_264 ( V_12 , 0 , V_15 , V_21 , V_267 , & V_80 ) )
return V_80 ;
F_227 ( & V_12 -> V_100 -> V_209 ) ;
if ( F_275 ( V_12 -> V_100 , V_295 ) )
goto V_296;
F_276 ( V_12 ) ;
if ( F_18 ( ! V_294 ) )
F_258 ( V_12 , & V_15 , & V_21 , & V_40 ) ;
V_80 = F_250 ( V_12 , V_331 , V_263 , V_264 ,
V_40 , V_15 , V_21 , V_265 ) ;
F_228 ( & V_12 -> V_100 -> V_209 ) ;
return V_80 ;
V_296:
F_228 ( & V_12 -> V_100 -> V_209 ) ;
F_242 ( V_21 ) ;
return 0 ;
}
static void F_311 ( struct V_11 * V_12 ,
struct V_332 * V_333 )
{
V_333 -> V_334 = F_298 ;
V_333 -> V_335 = F_288 ;
V_333 -> V_198 = F_169 ;
V_333 -> V_336 = F_170 ;
V_333 -> V_337 = F_171 ;
V_333 -> V_219 = 0 ;
V_333 -> V_231 = V_232 ;
V_333 -> V_230 = V_298 ;
V_333 -> V_218 = true ;
V_333 -> V_338 = false ;
}
void F_312 ( struct V_11 * V_12 )
{
F_277 ( V_12 ) ;
}
static unsigned long V_303 ( struct V_11 * V_12 )
{
return F_313 ( V_12 ) ;
}
static void F_314 ( struct V_11 * V_12 ,
struct V_312 * V_339 )
{
V_12 -> V_34 . V_197 . F_314 ( V_12 , V_339 ) ;
}
static bool F_315 ( struct V_11 * V_12 , T_1 * V_14 , T_2 V_15 ,
unsigned V_16 , int * V_340 )
{
if ( F_14 ( F_10 ( * V_14 ) ) ) {
if ( V_15 != F_11 ( * V_14 ) ) {
F_52 ( V_14 ) ;
return true ;
}
( * V_340 ) ++ ;
F_7 ( V_12 , V_14 , V_15 , V_16 ) ;
return true ;
}
return false ;
}
static inline bool F_316 ( struct V_332 * V_197 , unsigned V_40 , unsigned V_43 )
{
unsigned V_89 ;
V_89 = V_40 - 1 ;
V_89 |= ( V_43 & V_39 ) >> ( V_341 - 2 ) ;
return V_197 -> V_342 & ( 1 << V_89 ) ;
}
static void F_317 ( struct V_11 * V_12 ,
struct V_332 * V_333 )
{
int V_343 = F_318 ( V_12 ) ;
T_1 V_344 = 0 ;
T_1 V_345 = 0 ;
T_1 V_346 = 0 ;
V_333 -> V_347 = 0 ;
if ( ! V_333 -> V_338 )
V_344 = F_319 ( 63 , 63 ) ;
if ( ! F_320 ( V_12 ) )
V_345 = F_319 ( 7 , 7 ) ;
if ( F_321 ( V_12 ) )
V_346 = F_319 ( 8 , 8 ) ;
switch ( V_333 -> V_219 ) {
case V_220 :
V_333 -> V_348 [ 0 ] [ 1 ] = 0 ;
V_333 -> V_348 [ 0 ] [ 0 ] = 0 ;
V_333 -> V_348 [ 1 ] [ 0 ] = V_333 -> V_348 [ 0 ] [ 0 ] ;
if ( ! F_322 ( V_12 ) ) {
V_333 -> V_348 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_20 () )
V_333 -> V_348 [ 1 ] [ 1 ] = F_319 ( 17 , 21 ) ;
else
V_333 -> V_348 [ 1 ] [ 1 ] = F_319 ( 13 , 21 ) ;
break;
case V_232 :
V_333 -> V_348 [ 0 ] [ 2 ] =
F_319 ( V_343 , 63 ) |
F_319 ( 5 , 8 ) | F_319 ( 1 , 2 ) ;
V_333 -> V_348 [ 0 ] [ 1 ] = V_344 |
F_319 ( V_343 , 62 ) ;
V_333 -> V_348 [ 0 ] [ 0 ] = V_344 |
F_319 ( V_343 , 62 ) ;
V_333 -> V_348 [ 1 ] [ 1 ] = V_344 |
F_319 ( V_343 , 62 ) |
F_319 ( 13 , 20 ) ;
V_333 -> V_348 [ 1 ] [ 0 ] = V_333 -> V_348 [ 0 ] [ 0 ] ;
break;
case V_206 :
V_333 -> V_348 [ 0 ] [ 3 ] = V_344 |
V_346 | F_319 ( 7 , 7 ) | F_319 ( V_343 , 51 ) ;
V_333 -> V_348 [ 0 ] [ 2 ] = V_344 |
V_346 | V_345 | F_319 ( V_343 , 51 ) ;
V_333 -> V_348 [ 0 ] [ 1 ] = V_344 |
F_319 ( V_343 , 51 ) ;
V_333 -> V_348 [ 0 ] [ 0 ] = V_344 |
F_319 ( V_343 , 51 ) ;
V_333 -> V_348 [ 1 ] [ 3 ] = V_333 -> V_348 [ 0 ] [ 3 ] ;
V_333 -> V_348 [ 1 ] [ 2 ] = V_344 |
V_345 | F_319 ( V_343 , 51 ) |
F_319 ( 13 , 29 ) ;
V_333 -> V_348 [ 1 ] [ 1 ] = V_344 |
F_319 ( V_343 , 51 ) |
F_319 ( 13 , 20 ) ;
V_333 -> V_348 [ 1 ] [ 0 ] = V_333 -> V_348 [ 0 ] [ 0 ] ;
break;
}
}
static void F_323 ( struct V_11 * V_12 ,
struct V_332 * V_333 , bool V_349 )
{
int V_343 = F_318 ( V_12 ) ;
int V_37 ;
V_333 -> V_348 [ 0 ] [ 3 ] =
F_319 ( V_343 , 51 ) | F_319 ( 3 , 7 ) ;
V_333 -> V_348 [ 0 ] [ 2 ] =
F_319 ( V_343 , 51 ) | F_319 ( 3 , 6 ) ;
V_333 -> V_348 [ 0 ] [ 1 ] =
F_319 ( V_343 , 51 ) | F_319 ( 3 , 6 ) ;
V_333 -> V_348 [ 0 ] [ 0 ] = F_319 ( V_343 , 51 ) ;
V_333 -> V_348 [ 1 ] [ 3 ] = V_333 -> V_348 [ 0 ] [ 3 ] ;
V_333 -> V_348 [ 1 ] [ 2 ] =
F_319 ( V_343 , 51 ) | F_319 ( 12 , 29 ) ;
V_333 -> V_348 [ 1 ] [ 1 ] =
F_319 ( V_343 , 51 ) | F_319 ( 12 , 20 ) ;
V_333 -> V_348 [ 1 ] [ 0 ] = V_333 -> V_348 [ 0 ] [ 0 ] ;
for ( V_37 = 0 ; V_37 < 64 ; V_37 ++ ) {
int V_350 = V_37 & 7 ;
int V_351 = V_37 >> 3 ;
if ( V_351 == 0x2 || V_351 == 0x3 || V_351 == 0x7 ||
V_350 == 0x2 || V_350 == 0x6 ||
( V_350 == 0x4 && ! V_349 ) )
V_333 -> V_347 |= ( 1ull << V_37 ) ;
}
}
static void F_324 ( struct V_11 * V_12 ,
struct V_332 * V_197 , bool V_352 )
{
unsigned V_353 , V_354 , V_355 ;
T_11 V_356 ;
bool V_339 , V_357 , V_358 , V_359 , V_360 , V_361 , V_362 , V_363 , V_364 , V_365 , V_366 = 0 ;
V_365 = F_325 ( V_12 , V_367 ) ;
V_364 = F_325 ( V_12 , V_368 ) ;
for ( V_354 = 0 ; V_354 < F_60 ( V_197 -> V_369 ) ; ++ V_354 ) {
V_355 = V_354 << 1 ;
V_356 = 0 ;
V_360 = V_355 & V_293 ;
V_361 = V_355 & V_370 ;
V_362 = V_355 & V_371 ;
V_363 = ! ( V_355 & V_291 ) ;
for ( V_353 = 0 ; V_353 < 8 ; ++ V_353 ) {
V_357 = V_353 & V_251 ;
V_358 = V_353 & V_17 ;
V_359 = V_353 & V_18 ;
if ( ! V_352 ) {
V_357 |= ! V_197 -> V_338 ;
V_358 |= ! F_326 ( V_12 ) && ! V_361 ;
V_357 &= ! ( V_365 && V_359 && ! V_361 ) ;
V_366 = V_364 && V_359 && ! V_361 && ! V_362 ;
} else
V_359 = 1 ;
V_339 = ( V_362 && ! V_357 ) || ( V_361 && ! V_359 ) || ( V_360 && ! V_358 ) ||
( V_363 && V_366 ) ;
V_356 |= V_339 << V_353 ;
}
V_197 -> V_369 [ V_354 ] = V_356 ;
}
}
static void F_327 ( struct V_11 * V_12 , struct V_332 * V_197 )
{
T_11 V_356 ;
unsigned V_40 , V_219 = V_197 -> V_219 ;
const unsigned V_372 = 1 << 2 ;
if ( V_219 == V_232 )
-- V_219 ;
V_356 = 1 | ( 1 << V_372 ) ;
for ( V_40 = V_105 ; V_40 <= V_219 ; ++ V_40 ) {
if ( V_40 <= V_373
&& ( V_197 -> V_219 >= V_232 || F_322 ( V_12 ) ) )
V_356 |= 1 << ( V_372 | ( V_40 - 1 ) ) ;
}
V_197 -> V_342 = V_356 ;
}
static void F_328 ( struct V_11 * V_12 ,
struct V_332 * V_333 ,
int V_40 )
{
V_333 -> V_338 = F_21 ( V_12 ) ;
V_333 -> V_219 = V_40 ;
F_317 ( V_12 , V_333 ) ;
F_324 ( V_12 , V_333 , false ) ;
F_327 ( V_12 , V_333 ) ;
F_156 ( ! F_180 ( V_12 ) ) ;
V_333 -> V_334 = V_374 ;
V_333 -> V_335 = V_375 ;
V_333 -> V_198 = V_376 ;
V_333 -> V_336 = V_377 ;
V_333 -> V_337 = V_378 ;
V_333 -> V_231 = V_40 ;
V_333 -> V_230 = V_298 ;
V_333 -> V_218 = false ;
}
static void F_329 ( struct V_11 * V_12 ,
struct V_332 * V_333 )
{
F_328 ( V_12 , V_333 , V_206 ) ;
}
static void F_330 ( struct V_11 * V_12 ,
struct V_332 * V_333 )
{
V_333 -> V_338 = false ;
V_333 -> V_219 = V_220 ;
F_317 ( V_12 , V_333 ) ;
F_324 ( V_12 , V_333 , false ) ;
F_327 ( V_12 , V_333 ) ;
V_333 -> V_334 = V_379 ;
V_333 -> V_335 = V_380 ;
V_333 -> V_198 = V_381 ;
V_333 -> V_336 = V_382 ;
V_333 -> V_337 = V_383 ;
V_333 -> V_231 = V_232 ;
V_333 -> V_230 = V_298 ;
V_333 -> V_218 = false ;
}
static void F_331 ( struct V_11 * V_12 ,
struct V_332 * V_333 )
{
F_328 ( V_12 , V_333 , V_232 ) ;
}
static void F_332 ( struct V_11 * V_12 )
{
struct V_332 * V_333 = & V_12 -> V_34 . V_197 ;
V_333 -> V_217 . V_223 = 0 ;
V_333 -> V_217 . V_384 = F_333 ( V_12 ) ;
V_333 -> V_334 = F_310 ;
V_333 -> V_198 = F_169 ;
V_333 -> V_336 = F_170 ;
V_333 -> V_337 = F_171 ;
V_333 -> V_231 = V_117 -> V_385 () ;
V_333 -> V_230 = V_298 ;
V_333 -> V_218 = true ;
V_333 -> V_386 = V_117 -> V_387 ;
V_333 -> V_303 = V_303 ;
V_333 -> V_306 = V_388 ;
V_333 -> F_314 = V_389 ;
if ( ! F_334 ( V_12 ) ) {
V_333 -> V_338 = false ;
V_333 -> V_335 = F_288 ;
V_333 -> V_219 = 0 ;
} else if ( F_335 ( V_12 ) ) {
V_333 -> V_338 = F_21 ( V_12 ) ;
V_333 -> V_219 = V_206 ;
F_317 ( V_12 , V_333 ) ;
V_333 -> V_335 = V_375 ;
} else if ( F_180 ( V_12 ) ) {
V_333 -> V_338 = F_21 ( V_12 ) ;
V_333 -> V_219 = V_232 ;
F_317 ( V_12 , V_333 ) ;
V_333 -> V_335 = V_375 ;
} else {
V_333 -> V_338 = false ;
V_333 -> V_219 = V_220 ;
F_317 ( V_12 , V_333 ) ;
V_333 -> V_335 = V_380 ;
}
F_324 ( V_12 , V_333 , false ) ;
F_327 ( V_12 , V_333 ) ;
}
void F_336 ( struct V_11 * V_12 )
{
bool V_390 = F_325 ( V_12 , V_367 ) ;
bool V_366 = F_325 ( V_12 , V_368 ) ;
struct V_332 * V_333 = & V_12 -> V_34 . V_197 ;
F_156 ( F_251 ( V_333 -> V_230 ) ) ;
if ( ! F_334 ( V_12 ) )
F_311 ( V_12 , V_333 ) ;
else if ( F_335 ( V_12 ) )
F_329 ( V_12 , V_333 ) ;
else if ( F_180 ( V_12 ) )
F_331 ( V_12 , V_333 ) ;
else
F_330 ( V_12 , V_333 ) ;
V_333 -> V_217 . V_391 = F_21 ( V_12 ) ;
V_333 -> V_217 . V_196 = ! ! F_180 ( V_12 ) ;
V_333 -> V_217 . V_392 = F_326 ( V_12 ) ;
V_333 -> V_217 . V_393
= V_390 && ! F_326 ( V_12 ) ;
V_333 -> V_217 . V_394
= V_366 && ! F_326 ( V_12 ) ;
V_333 -> V_217 . V_384 = F_333 ( V_12 ) ;
}
void F_337 ( struct V_11 * V_12 , bool V_349 )
{
struct V_332 * V_333 = & V_12 -> V_34 . V_197 ;
F_156 ( F_251 ( V_333 -> V_230 ) ) ;
V_333 -> V_231 = V_117 -> V_385 () ;
V_333 -> V_338 = true ;
V_333 -> V_334 = V_395 ;
V_333 -> V_335 = V_396 ;
V_333 -> V_198 = V_397 ;
V_333 -> V_336 = V_398 ;
V_333 -> V_337 = V_399 ;
V_333 -> V_219 = V_333 -> V_231 ;
V_333 -> V_230 = V_298 ;
V_333 -> V_218 = false ;
F_324 ( V_12 , V_333 , true ) ;
F_323 ( V_12 , V_333 , V_349 ) ;
}
static void F_338 ( struct V_11 * V_12 )
{
struct V_332 * V_333 = & V_12 -> V_34 . V_197 ;
F_336 ( V_12 ) ;
V_333 -> V_386 = V_117 -> V_386 ;
V_333 -> V_303 = V_303 ;
V_333 -> V_306 = V_388 ;
V_333 -> F_314 = V_389 ;
}
static void F_339 ( struct V_11 * V_12 )
{
struct V_332 * V_400 = & V_12 -> V_34 . V_314 ;
V_400 -> V_303 = V_303 ;
V_400 -> V_306 = V_388 ;
V_400 -> F_314 = V_389 ;
if ( ! F_334 ( V_12 ) ) {
V_400 -> V_338 = false ;
V_400 -> V_219 = 0 ;
V_400 -> V_335 = F_289 ;
} else if ( F_335 ( V_12 ) ) {
V_400 -> V_338 = F_21 ( V_12 ) ;
V_400 -> V_219 = V_206 ;
F_317 ( V_12 , V_400 ) ;
V_400 -> V_335 = V_401 ;
} else if ( F_180 ( V_12 ) ) {
V_400 -> V_338 = F_21 ( V_12 ) ;
V_400 -> V_219 = V_232 ;
F_317 ( V_12 , V_400 ) ;
V_400 -> V_335 = V_401 ;
} else {
V_400 -> V_338 = false ;
V_400 -> V_219 = V_220 ;
F_317 ( V_12 , V_400 ) ;
V_400 -> V_335 = V_402 ;
}
F_324 ( V_12 , V_400 , false ) ;
F_327 ( V_12 , V_400 ) ;
}
static void F_340 ( struct V_11 * V_12 )
{
if ( F_341 ( V_12 ) )
F_339 ( V_12 ) ;
else if ( V_252 )
F_332 ( V_12 ) ;
else
F_338 ( V_12 ) ;
}
void F_342 ( struct V_11 * V_12 )
{
F_343 ( V_12 ) ;
F_340 ( V_12 ) ;
}
int F_344 ( struct V_11 * V_12 )
{
int V_80 ;
V_80 = F_69 ( V_12 ) ;
if ( V_80 )
goto V_84;
V_80 = F_284 ( V_12 ) ;
F_287 ( V_12 ) ;
if ( V_80 )
goto V_84;
V_12 -> V_34 . V_197 . V_386 ( V_12 , V_12 -> V_34 . V_197 . V_230 ) ;
V_84:
return V_80 ;
}
void F_343 ( struct V_11 * V_12 )
{
F_277 ( V_12 ) ;
F_3 ( F_251 ( V_12 -> V_34 . V_197 . V_230 ) ) ;
}
static void F_345 ( struct V_11 * V_12 ,
struct V_47 * V_48 , T_1 * V_10 ,
const void * V_403 )
{
if ( V_48 -> V_90 . V_40 != V_41 ) {
++ V_12 -> V_100 -> V_134 . V_404 ;
return;
}
++ V_12 -> V_100 -> V_134 . V_405 ;
V_12 -> V_34 . V_197 . V_337 ( V_12 , V_48 , V_10 , V_403 ) ;
}
static bool F_346 ( T_1 V_406 , T_1 V_403 )
{
if ( ! F_22 ( V_406 ) )
return false ;
if ( ! F_22 ( V_403 ) )
return true ;
if ( ( V_406 ^ V_403 ) & V_42 )
return true ;
V_406 ^= V_32 ;
V_403 ^= V_32 ;
return ( V_406 & ~ V_403 & V_407 ) != 0 ;
}
static void F_347 ( struct V_11 * V_12 , bool V_408 ,
bool V_409 , bool V_410 )
{
if ( V_408 )
return;
if ( V_409 )
F_109 ( V_12 -> V_100 ) ;
else if ( V_410 )
F_182 ( V_199 , V_12 ) ;
}
static T_1 F_348 ( struct V_11 * V_12 , T_8 * V_331 ,
const T_11 * V_403 , int * V_411 )
{
T_1 V_412 ;
int V_80 ;
if ( F_180 ( V_12 ) && * V_411 == 4 ) {
* V_331 &= ~ ( T_8 ) 7 ;
* V_411 = 8 ;
V_80 = F_349 ( V_12 , * V_331 , & V_412 , 8 ) ;
if ( V_80 )
V_412 = 0 ;
V_403 = ( const T_11 * ) & V_412 ;
}
switch ( * V_411 ) {
case 4 :
V_412 = * ( const T_4 * ) V_403 ;
break;
case 8 :
V_412 = * ( const T_1 * ) V_403 ;
break;
default:
V_412 = 0 ;
break;
}
return V_412 ;
}
static bool F_350 ( struct V_47 * V_48 )
{
if ( V_48 -> V_90 . V_40 == V_41 )
return false ;
return ++ V_48 -> V_211 >= 3 ;
}
static bool F_351 ( struct V_47 * V_48 , T_8 V_331 ,
int V_411 )
{
unsigned V_413 , V_414 , V_415 ;
F_230 ( L_27 ,
V_331 , V_411 , V_48 -> V_90 . V_223 ) ;
V_413 = F_352 ( V_331 ) ;
V_414 = V_48 -> V_90 . V_196 ? 8 : 4 ;
if ( ! ( V_413 & ( V_414 - 1 ) ) && V_411 == 1 )
return false ;
V_415 = ( V_413 ^ ( V_413 + V_411 - 1 ) ) & ~ ( V_414 - 1 ) ;
V_415 |= V_411 < 4 ;
return V_415 ;
}
static T_1 * F_353 ( struct V_47 * V_48 , T_8 V_331 , int * V_416 )
{
unsigned V_417 , V_215 ;
T_1 * V_10 ;
int V_40 ;
V_417 = F_352 ( V_331 ) ;
V_40 = V_48 -> V_90 . V_40 ;
* V_416 = 1 ;
if ( ! V_48 -> V_90 . V_196 ) {
V_417 <<= 1 ;
if ( V_40 == V_220 ) {
V_417 &= ~ 7 ;
V_417 <<= 1 ;
* V_416 = 2 ;
}
V_215 = V_417 >> V_19 ;
V_417 &= ~ V_20 ;
if ( V_215 != V_48 -> V_90 . V_215 )
return NULL ;
}
V_10 = & V_48 -> V_130 [ V_417 / sizeof( * V_10 ) ] ;
return V_10 ;
}
void F_354 ( struct V_11 * V_12 , T_8 V_331 ,
const T_11 * V_403 , int V_411 )
{
T_2 V_15 = V_331 >> V_19 ;
struct V_47 * V_48 ;
F_184 ( V_194 ) ;
T_1 V_418 , V_412 , * V_10 ;
int V_419 ;
bool V_409 , V_410 , V_408 ;
union V_214 V_4 = { } ;
V_4 . V_392 = 1 ;
V_4 . V_196 = 1 ;
V_4 . V_391 = 1 ;
V_4 . V_393 = 1 ;
V_4 . V_394 = 1 ;
V_4 . V_384 = 1 ;
if ( ! F_33 ( V_12 -> V_100 -> V_34 . V_108 ) )
return;
V_408 = V_409 = V_410 = false ;
F_230 ( L_28 , V_142 , V_331 , V_411 ) ;
V_412 = F_348 ( V_12 , & V_331 , V_403 , & V_411 ) ;
F_69 ( V_12 ) ;
F_227 ( & V_12 -> V_100 -> V_209 ) ;
++ V_12 -> V_100 -> V_134 . V_420 ;
F_186 ( V_12 , V_421 ) ;
F_190 (vcpu->kvm, sp, gfn) {
if ( F_351 ( V_48 , V_331 , V_411 ) ||
F_350 ( V_48 ) ) {
V_408 |= ! ! F_181 ( V_12 -> V_100 , V_48 ,
& V_194 ) ;
++ V_12 -> V_100 -> V_134 . V_422 ;
continue;
}
V_10 = F_353 ( V_48 , V_331 , & V_419 ) ;
if ( ! V_10 )
continue;
V_410 = true ;
while ( V_419 -- ) {
V_418 = * V_10 ;
F_214 ( V_12 -> V_100 , V_48 , V_10 ) ;
if ( V_412 &&
! ( ( V_48 -> V_90 . V_223 ^ V_12 -> V_34 . V_197 . V_217 . V_223 )
& V_4 . V_223 ) && F_101 ( V_12 ) )
F_345 ( V_12 , V_48 , V_10 , & V_412 ) ;
if ( F_346 ( V_418 , * V_10 ) )
V_409 = true ;
++ V_10 ;
}
}
F_347 ( V_12 , V_408 , V_409 , V_410 ) ;
F_185 ( V_12 -> V_100 , & V_194 ) ;
F_186 ( V_12 , V_423 ) ;
F_228 ( & V_12 -> V_100 -> V_209 ) ;
}
int F_355 ( struct V_11 * V_12 , T_7 V_182 )
{
T_8 V_331 ;
int V_80 ;
if ( V_12 -> V_34 . V_197 . V_218 )
return 0 ;
V_331 = F_356 ( V_12 , V_182 , NULL ) ;
V_80 = F_229 ( V_12 -> V_100 , V_331 >> V_19 ) ;
return V_80 ;
}
static void F_276 ( struct V_11 * V_12 )
{
F_184 ( V_194 ) ;
if ( F_18 ( F_357 ( V_12 -> V_100 ) >= V_424 ) )
return;
while ( F_357 ( V_12 -> V_100 ) < V_425 ) {
if ( ! F_224 ( V_12 -> V_100 , & V_194 ) )
break;
++ V_12 -> V_100 -> V_134 . V_426 ;
}
F_185 ( V_12 -> V_100 , & V_194 ) ;
}
static bool F_358 ( struct V_11 * V_12 , T_7 V_228 )
{
if ( V_12 -> V_34 . V_197 . V_218 || F_341 ( V_12 ) )
return F_291 ( V_12 , V_228 ) ;
return F_292 ( V_12 , V_228 ) ;
}
int F_359 ( struct V_11 * V_12 , T_7 V_427 , T_4 V_290 ,
void * V_428 , int V_429 )
{
int V_80 , V_430 = V_431 ;
enum V_432 V_433 ;
V_80 = V_12 -> V_34 . V_197 . V_334 ( V_12 , V_427 , V_290 , false ) ;
if ( V_80 < 0 )
goto V_84;
if ( ! V_80 ) {
V_80 = 1 ;
goto V_84;
}
if ( F_358 ( V_12 , V_427 ) )
V_430 = 0 ;
V_433 = F_360 ( V_12 , V_427 , V_430 , V_428 , V_429 ) ;
switch ( V_433 ) {
case V_434 :
return 1 ;
case V_435 :
++ V_12 -> V_134 . V_436 ;
case V_437 :
return 0 ;
default:
F_96 () ;
}
V_84:
return V_80 ;
}
void F_361 ( struct V_11 * V_12 , T_7 V_182 )
{
V_12 -> V_34 . V_197 . V_336 ( V_12 , V_182 ) ;
F_182 ( V_199 , V_12 ) ;
++ V_12 -> V_134 . V_336 ;
}
void F_362 ( void )
{
V_252 = true ;
}
void F_363 ( void )
{
V_252 = false ;
}
static void F_364 ( struct V_11 * V_12 )
{
F_68 ( ( unsigned long ) V_12 -> V_34 . V_197 . V_233 ) ;
if ( V_12 -> V_34 . V_197 . V_307 != NULL )
F_68 ( ( unsigned long ) V_12 -> V_34 . V_197 . V_307 ) ;
}
static int F_365 ( struct V_11 * V_12 )
{
struct V_79 * V_79 ;
int V_104 ;
V_79 = F_366 ( V_76 | V_438 ) ;
if ( ! V_79 )
return - V_77 ;
V_12 -> V_34 . V_197 . V_233 = F_367 ( V_79 ) ;
for ( V_104 = 0 ; V_104 < 4 ; ++ V_104 )
V_12 -> V_34 . V_197 . V_233 [ V_104 ] = V_298 ;
return 0 ;
}
int F_368 ( struct V_11 * V_12 )
{
V_12 -> V_34 . V_439 = & V_12 -> V_34 . V_197 ;
V_12 -> V_34 . V_197 . V_230 = V_298 ;
V_12 -> V_34 . V_197 . V_315 = V_315 ;
V_12 -> V_34 . V_314 . V_315 = V_440 ;
return F_365 ( V_12 ) ;
}
void F_369 ( struct V_11 * V_12 )
{
F_156 ( F_251 ( V_12 -> V_34 . V_197 . V_230 ) ) ;
F_340 ( V_12 ) ;
}
static bool
F_370 ( struct V_100 * V_100 , struct V_95 * V_157 ,
T_12 V_127 , int V_153 , int V_154 ,
T_2 V_150 , T_2 V_152 , bool V_441 )
{
struct V_148 V_149 ;
bool V_138 = false ;
F_139 (memslot, start_level, end_level, start_gfn,
end_gfn, &iterator) {
if ( V_149 . V_128 )
V_138 |= V_127 ( V_100 , V_149 . V_128 ) ;
if ( F_371 () || F_372 ( & V_100 -> V_209 ) ) {
if ( V_138 && V_441 ) {
F_109 ( V_100 ) ;
V_138 = false ;
}
F_196 ( & V_100 -> V_209 ) ;
}
}
if ( V_138 && V_441 ) {
F_109 ( V_100 ) ;
V_138 = false ;
}
return V_138 ;
}
static bool
F_373 ( struct V_100 * V_100 , struct V_95 * V_157 ,
T_12 V_127 , int V_153 , int V_154 ,
bool V_441 )
{
return F_370 ( V_100 , V_157 , V_127 , V_153 ,
V_154 , V_157 -> V_98 ,
V_157 -> V_98 + V_157 -> V_164 - 1 ,
V_441 ) ;
}
static bool
F_374 ( struct V_100 * V_100 , struct V_95 * V_157 ,
T_12 V_127 , bool V_441 )
{
return F_373 ( V_100 , V_157 , V_127 , V_41 ,
V_106 , V_441 ) ;
}
static bool
F_375 ( struct V_100 * V_100 , struct V_95 * V_157 ,
T_12 V_127 , bool V_441 )
{
return F_373 ( V_100 , V_157 , V_127 , V_41 + 1 ,
V_106 , V_441 ) ;
}
static bool
F_376 ( struct V_100 * V_100 , struct V_95 * V_157 ,
T_12 V_127 , bool V_441 )
{
return F_373 ( V_100 , V_157 , V_127 , V_41 ,
V_41 , V_441 ) ;
}
void F_377 ( struct V_100 * V_100 , T_2 V_161 , T_2 V_162 )
{
struct V_101 * V_102 ;
struct V_95 * V_157 ;
int V_104 ;
F_227 ( & V_100 -> V_209 ) ;
for ( V_104 = 0 ; V_104 < V_158 ; V_104 ++ ) {
V_102 = F_135 ( V_100 , V_104 ) ;
F_136 (memslot, slots) {
T_2 V_155 , V_156 ;
V_155 = F_137 ( V_161 , V_157 -> V_98 ) ;
V_156 = V_72 ( V_162 , V_157 -> V_98 + V_157 -> V_164 ) ;
if ( V_155 >= V_156 )
continue;
F_370 ( V_100 , V_157 , F_122 ,
V_41 , V_106 ,
V_155 , V_156 - 1 , true ) ;
}
}
F_228 ( & V_100 -> V_209 ) ;
}
static bool F_378 ( struct V_100 * V_100 , unsigned long * V_129 )
{
return F_111 ( V_100 , V_129 , false ) ;
}
void F_379 ( struct V_100 * V_100 ,
struct V_95 * V_157 )
{
bool V_138 ;
F_227 ( & V_100 -> V_209 ) ;
V_138 = F_374 ( V_100 , V_157 , F_378 ,
false ) ;
F_228 ( & V_100 -> V_209 ) ;
F_380 ( & V_100 -> V_442 ) ;
if ( V_138 )
F_109 ( V_100 ) ;
}
static bool F_381 ( struct V_100 * V_100 ,
unsigned long * V_129 )
{
T_1 * V_14 ;
struct V_131 V_132 ;
int V_443 = 0 ;
T_3 V_21 ;
struct V_47 * V_48 ;
V_147:
F_112 (rmapp, &iter, sptep) {
V_48 = F_36 ( F_37 ( V_14 ) ) ;
V_21 = F_26 ( * V_14 ) ;
if ( V_48 -> V_90 . V_91 &&
! F_49 ( V_21 ) &&
F_260 ( F_51 ( V_21 ) ) ) {
F_106 ( V_100 , V_14 ) ;
V_443 = 1 ;
goto V_147;
}
}
return V_443 ;
}
void F_382 ( struct V_100 * V_100 ,
const struct V_95 * V_157 )
{
F_227 ( & V_100 -> V_209 ) ;
F_376 ( V_100 , (struct V_95 * ) V_157 ,
F_381 , true ) ;
F_228 ( & V_100 -> V_209 ) ;
}
void F_383 ( struct V_100 * V_100 ,
struct V_95 * V_157 )
{
bool V_138 ;
F_227 ( & V_100 -> V_209 ) ;
V_138 = F_376 ( V_100 , V_157 , F_114 , false ) ;
F_228 ( & V_100 -> V_209 ) ;
F_380 ( & V_100 -> V_442 ) ;
if ( V_138 )
F_109 ( V_100 ) ;
}
void F_384 ( struct V_100 * V_100 ,
struct V_95 * V_157 )
{
bool V_138 ;
F_227 ( & V_100 -> V_209 ) ;
V_138 = F_375 ( V_100 , V_157 , F_378 ,
false ) ;
F_228 ( & V_100 -> V_209 ) ;
F_380 ( & V_100 -> V_442 ) ;
if ( V_138 )
F_109 ( V_100 ) ;
}
void F_385 ( struct V_100 * V_100 ,
struct V_95 * V_157 )
{
bool V_138 ;
F_227 ( & V_100 -> V_209 ) ;
V_138 = F_374 ( V_100 , V_157 , F_116 , false ) ;
F_228 ( & V_100 -> V_209 ) ;
F_380 ( & V_100 -> V_442 ) ;
if ( V_138 )
F_109 ( V_100 ) ;
}
static void F_386 ( struct V_100 * V_100 )
{
struct V_47 * V_48 , * V_444 ;
int V_445 = 0 ;
V_147:
F_387 (sp, node,
&kvm->arch.active_mmu_pages, link) {
int V_64 ;
if ( ! F_200 ( V_100 , V_48 ) )
break;
if ( V_48 -> V_90 . V_240 )
continue;
if ( V_445 >= V_446 &&
F_196 ( & V_100 -> V_209 ) ) {
V_445 = 0 ;
goto V_147;
}
V_64 = F_181 ( V_100 , V_48 ,
& V_100 -> V_34 . V_447 ) ;
V_445 += V_64 ;
if ( V_64 )
goto V_147;
}
F_185 ( V_100 , & V_100 -> V_34 . V_447 ) ;
}
void F_388 ( struct V_100 * V_100 )
{
F_227 ( & V_100 -> V_209 ) ;
F_389 ( V_100 ) ;
V_100 -> V_34 . V_212 ++ ;
F_221 ( V_100 ) ;
F_386 ( V_100 ) ;
F_228 ( & V_100 -> V_209 ) ;
}
static bool F_390 ( struct V_100 * V_100 )
{
return F_14 ( ! F_391 ( & V_100 -> V_34 . V_447 ) ) ;
}
void F_392 ( struct V_100 * V_100 , struct V_101 * V_102 )
{
if ( F_14 ( ( V_102 -> V_13 & V_5 ) == 0 ) ) {
F_393 ( V_448 L_29 ) ;
F_388 ( V_100 ) ;
}
}
static unsigned long
F_394 ( struct V_449 * V_450 , struct V_451 * V_452 )
{
struct V_100 * V_100 ;
int V_453 = V_452 -> V_453 ;
unsigned long V_454 = 0 ;
F_227 ( & V_455 ) ;
F_395 (kvm, &vm_list, vm_list) {
int V_97 ;
F_184 ( V_194 ) ;
if ( ! V_453 -- )
break;
if ( ! V_100 -> V_34 . V_171 &&
! F_390 ( V_100 ) )
continue;
V_97 = F_396 ( & V_100 -> V_456 ) ;
F_227 ( & V_100 -> V_209 ) ;
if ( F_390 ( V_100 ) ) {
F_185 ( V_100 ,
& V_100 -> V_34 . V_447 ) ;
goto V_457;
}
if ( F_224 ( V_100 , & V_194 ) )
V_454 ++ ;
F_185 ( V_100 , & V_194 ) ;
V_457:
F_228 ( & V_100 -> V_209 ) ;
F_397 ( & V_100 -> V_456 , V_97 ) ;
F_398 ( & V_100 -> V_458 , & V_458 ) ;
break;
}
F_228 ( & V_455 ) ;
return V_454 ;
}
static unsigned long
F_399 ( struct V_449 * V_450 , struct V_451 * V_452 )
{
return F_400 ( & V_172 ) ;
}
static void F_401 ( void )
{
if ( V_82 )
F_402 ( V_82 ) ;
if ( V_86 )
F_402 ( V_86 ) ;
}
int F_403 ( void )
{
V_82 = F_404 ( L_30 ,
sizeof( struct V_88 ) ,
0 , 0 , NULL ) ;
if ( ! V_82 )
goto V_459;
V_86 = F_404 ( L_31 ,
sizeof( struct V_47 ) ,
0 , 0 , NULL ) ;
if ( ! V_86 )
goto V_459;
if ( F_405 ( & V_172 , 0 , V_76 ) )
goto V_459;
F_406 ( & V_460 ) ;
return 0 ;
V_459:
F_401 () ;
return - V_77 ;
}
unsigned int F_407 ( struct V_100 * V_100 )
{
unsigned int V_461 ;
unsigned int V_462 = 0 ;
struct V_101 * V_102 ;
struct V_95 * V_157 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_158 ; V_104 ++ ) {
V_102 = F_135 ( V_100 , V_104 ) ;
F_136 (memslot, slots)
V_462 += V_157 -> V_164 ;
}
V_461 = V_462 * V_463 / 1000 ;
V_461 = F_137 ( V_461 ,
( unsigned int ) V_464 ) ;
return V_461 ;
}
int F_408 ( struct V_11 * V_12 , T_1 V_228 , T_1 V_121 [ 4 ] )
{
struct V_227 V_149 ;
T_1 V_10 ;
int V_465 = 0 ;
if ( ! F_251 ( V_12 -> V_34 . V_197 . V_230 ) )
return V_465 ;
F_54 ( V_12 ) ;
F_271 (vcpu, addr, iterator, spte) {
V_121 [ V_149 . V_40 - 1 ] = V_10 ;
V_465 ++ ;
if ( ! F_22 ( V_10 ) )
break;
}
F_57 ( V_12 ) ;
return V_465 ;
}
void F_409 ( struct V_11 * V_12 )
{
F_343 ( V_12 ) ;
F_364 ( V_12 ) ;
F_70 ( V_12 ) ;
}
void F_410 ( void )
{
F_401 () ;
F_411 ( & V_172 ) ;
F_412 ( & V_460 ) ;
F_187 () ;
}
