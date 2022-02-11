void F_1 ( T_1 V_1 )
{
V_2 = V_1 ;
}
static void F_2 ( T_1 * V_3 , T_1 V_4 , unsigned V_5 )
{
struct V_6 * V_7 = F_3 ( F_4 ( V_3 ) ) ;
V_5 &= V_8 | V_9 ;
V_7 -> V_10 = true ;
F_5 ( V_3 , V_4 , V_5 ) ;
F_6 ( V_3 , V_2 | V_5 | V_4 << V_11 ) ;
}
static bool F_7 ( T_1 V_12 )
{
return ( V_12 & V_2 ) == V_2 ;
}
static T_2 F_8 ( T_1 V_12 )
{
return ( V_12 & ~ V_2 ) >> V_11 ;
}
static unsigned F_9 ( T_1 V_12 )
{
return ( V_12 & ~ V_2 ) & ~ V_13 ;
}
static bool F_10 ( T_1 * V_3 , T_2 V_4 , T_3 V_14 , unsigned V_5 )
{
if ( F_11 ( F_12 ( V_14 ) ) ) {
F_2 ( V_3 , V_4 , V_5 ) ;
return true ;
}
return false ;
}
static inline T_1 F_13 ( int V_15 , int V_16 )
{
return ( ( 1ULL << ( V_16 - V_15 + 1 ) ) - 1 ) << V_15 ;
}
void F_14 ( T_1 V_17 , T_1 V_18 ,
T_1 V_19 , T_1 V_20 , T_1 V_21 )
{
V_22 = V_17 ;
V_23 = V_18 ;
V_24 = V_19 ;
V_25 = V_20 ;
V_26 = V_21 ;
}
static int F_15 ( void )
{
return 1 ;
}
static int F_16 ( struct V_27 * V_28 )
{
return V_28 -> V_29 . V_30 & V_31 ;
}
static int F_17 ( T_1 V_32 )
{
return V_32 & V_33 && ! F_7 ( V_32 ) ;
}
static int F_18 ( T_1 V_32 )
{
return V_32 & V_34 ;
}
static int F_19 ( unsigned long V_32 )
{
return V_32 & V_35 ;
}
static int F_20 ( T_1 V_32 )
{
return F_17 ( V_32 ) ;
}
static int F_21 ( T_1 V_32 , int V_36 )
{
if ( V_36 == V_37 )
return 1 ;
if ( F_18 ( V_32 ) )
return 1 ;
return 0 ;
}
static T_3 F_22 ( T_1 V_32 )
{
return ( V_32 & V_38 ) >> V_11 ;
}
static T_2 F_23 ( T_4 V_39 )
{
int V_40 = 32 - V_41 - V_11 ;
return ( V_39 & V_42 ) << V_40 ;
}
static void F_24 ( T_1 * V_3 , T_1 V_12 )
{
* V_3 = V_12 ;
}
static void F_25 ( T_1 * V_3 , T_1 V_12 )
{
* V_3 = V_12 ;
}
static T_1 F_26 ( T_1 * V_3 , T_1 V_12 )
{
return F_27 ( V_3 , V_12 ) ;
}
static T_1 F_28 ( T_1 * V_3 )
{
return F_29 ( * V_3 ) ;
}
static bool F_30 ( T_1 V_12 )
{
return V_12 == 0ull ;
}
static void F_31 ( T_1 * V_3 , T_1 V_12 )
{
struct V_6 * V_7 = F_3 ( F_4 ( V_3 ) ) ;
if ( F_17 ( V_12 ) )
return;
F_32 () ;
V_7 -> V_43 ++ ;
}
static void F_24 ( T_1 * V_3 , T_1 V_12 )
{
union V_44 * V_45 , V_46 ;
V_45 = (union V_44 * ) V_3 ;
V_46 = (union V_44 ) V_12 ;
V_45 -> V_47 = V_46 . V_47 ;
F_32 () ;
V_45 -> V_48 = V_46 . V_48 ;
}
static void F_25 ( T_1 * V_3 , T_1 V_12 )
{
union V_44 * V_45 , V_46 ;
V_45 = (union V_44 * ) V_3 ;
V_46 = (union V_44 ) V_12 ;
V_45 -> V_48 = V_46 . V_48 ;
F_32 () ;
V_45 -> V_47 = V_46 . V_47 ;
F_31 ( V_3 , V_12 ) ;
}
static T_1 F_26 ( T_1 * V_3 , T_1 V_12 )
{
union V_44 * V_45 , V_46 , V_49 ;
V_45 = (union V_44 * ) V_3 ;
V_46 = (union V_44 ) V_12 ;
V_49 . V_48 = F_27 ( & V_45 -> V_48 , V_46 . V_48 ) ;
V_49 . V_47 = V_45 -> V_47 ;
V_45 -> V_47 = V_46 . V_47 ;
F_31 ( V_3 , V_12 ) ;
return V_49 . V_12 ;
}
static T_1 F_28 ( T_1 * V_3 )
{
struct V_6 * V_7 = F_3 ( F_4 ( V_3 ) ) ;
union V_44 V_12 , * V_49 = (union V_44 * ) V_3 ;
int V_50 ;
V_51:
V_50 = V_7 -> V_43 ;
F_33 () ;
V_12 . V_48 = V_49 -> V_48 ;
F_33 () ;
V_12 . V_47 = V_49 -> V_47 ;
F_33 () ;
if ( F_11 ( V_12 . V_48 != V_49 -> V_48 ||
V_50 != V_7 -> V_43 ) )
goto V_51;
return V_12 . V_12 ;
}
static bool F_30 ( T_1 V_12 )
{
union V_44 V_46 = (union V_44 ) V_12 ;
T_4 V_52 = V_2 >> 32 ;
if ( V_12 == 0ull )
return true ;
if ( V_46 . V_48 == 0ull &&
( V_46 . V_47 & V_52 ) == V_52 )
return true ;
return false ;
}
static bool F_34 ( T_1 V_12 )
{
return ( V_12 & ( V_53 | V_54 ) ) ==
( V_53 | V_54 ) ;
}
static bool F_35 ( T_1 V_12 )
{
if ( F_34 ( V_12 ) )
return true ;
if ( ! V_23 )
return false ;
if ( ! F_17 ( V_12 ) )
return false ;
if ( ( V_12 & V_23 ) &&
( ! F_36 ( V_12 ) || ( V_12 & V_24 ) ) )
return false ;
return true ;
}
static bool F_37 ( T_1 V_55 , T_1 V_56 , T_1 V_57 )
{
return ( V_55 & V_57 ) && ! ( V_56 & V_57 ) ;
}
static void F_6 ( T_1 * V_3 , T_1 V_56 )
{
F_38 ( F_17 ( * V_3 ) ) ;
F_24 ( V_3 , V_56 ) ;
}
static bool F_39 ( T_1 * V_3 , T_1 V_56 )
{
T_1 V_55 = * V_3 ;
bool V_58 = false ;
F_38 ( ! F_20 ( V_56 ) ) ;
if ( ! F_17 ( V_55 ) ) {
F_6 ( V_3 , V_56 ) ;
return V_58 ;
}
if ( ! F_35 ( V_55 ) )
F_25 ( V_3 , V_56 ) ;
else
V_55 = F_26 ( V_3 , V_56 ) ;
if ( F_36 ( V_55 ) && ! F_36 ( V_56 ) )
V_58 = true ;
if ( ! V_23 )
return V_58 ;
if ( F_37 ( V_55 , V_56 , V_23 ) )
F_40 ( F_22 ( V_55 ) ) ;
if ( F_37 ( V_55 , V_56 , V_24 ) )
F_41 ( F_22 ( V_55 ) ) ;
return V_58 ;
}
static int F_42 ( T_1 * V_3 )
{
T_3 V_14 ;
T_1 V_55 = * V_3 ;
if ( ! F_35 ( V_55 ) )
F_25 ( V_3 , 0ull ) ;
else
V_55 = F_26 ( V_3 , 0ull ) ;
if ( ! F_20 ( V_55 ) )
return 0 ;
V_14 = F_22 ( V_55 ) ;
F_38 ( ! F_43 ( V_14 ) && ! F_44 ( F_45 ( V_14 ) ) ) ;
if ( ! V_23 || V_55 & V_23 )
F_40 ( V_14 ) ;
if ( ! V_24 || ( V_55 & V_24 ) )
F_41 ( V_14 ) ;
return 1 ;
}
static void F_46 ( T_1 * V_3 )
{
F_25 ( V_3 , 0ull ) ;
}
static T_1 F_47 ( T_1 * V_3 )
{
return F_28 ( V_3 ) ;
}
static void F_48 ( struct V_27 * V_28 )
{
F_49 () ;
V_28 -> V_59 = V_60 ;
F_50 () ;
}
static void F_51 ( struct V_27 * V_28 )
{
F_50 () ;
V_28 -> V_59 = V_61 ;
F_52 () ;
}
static int F_53 ( struct V_62 * V_63 ,
struct V_64 * V_65 , int V_66 )
{
void * V_67 ;
if ( V_63 -> V_68 >= V_66 )
return 0 ;
while ( V_63 -> V_68 < F_54 ( V_63 -> V_69 ) ) {
V_67 = F_55 ( V_65 , V_70 ) ;
if ( ! V_67 )
return - V_71 ;
V_63 -> V_69 [ V_63 -> V_68 ++ ] = V_67 ;
}
return 0 ;
}
static int F_56 ( struct V_62 * V_63 )
{
return V_63 -> V_68 ;
}
static void F_57 ( struct V_62 * V_72 ,
struct V_64 * V_63 )
{
while ( V_72 -> V_68 )
F_58 ( V_63 , V_72 -> V_69 [ -- V_72 -> V_68 ] ) ;
}
static int F_59 ( struct V_62 * V_63 ,
int V_66 )
{
void * V_73 ;
if ( V_63 -> V_68 >= V_66 )
return 0 ;
while ( V_63 -> V_68 < F_54 ( V_63 -> V_69 ) ) {
V_73 = ( void * ) F_60 ( V_70 ) ;
if ( ! V_73 )
return - V_71 ;
V_63 -> V_69 [ V_63 -> V_68 ++ ] = V_73 ;
}
return 0 ;
}
static void F_61 ( struct V_62 * V_72 )
{
while ( V_72 -> V_68 )
F_62 ( ( unsigned long ) V_72 -> V_69 [ -- V_72 -> V_68 ] ) ;
}
static int F_63 ( struct V_27 * V_28 )
{
int V_74 ;
V_74 = F_53 ( & V_28 -> V_29 . V_75 ,
V_76 , 8 + V_77 ) ;
if ( V_74 )
goto V_78;
V_74 = F_59 ( & V_28 -> V_29 . V_79 , 8 ) ;
if ( V_74 )
goto V_78;
V_74 = F_53 ( & V_28 -> V_29 . V_80 ,
V_80 , 4 ) ;
V_78:
return V_74 ;
}
static void F_64 ( struct V_27 * V_28 )
{
F_57 ( & V_28 -> V_29 . V_75 ,
V_76 ) ;
F_61 ( & V_28 -> V_29 . V_79 ) ;
F_57 ( & V_28 -> V_29 . V_80 ,
V_80 ) ;
}
static void * F_65 ( struct V_62 * V_72 )
{
void * V_81 ;
F_66 ( ! V_72 -> V_68 ) ;
V_81 = V_72 -> V_69 [ -- V_72 -> V_68 ] ;
return V_81 ;
}
static struct V_82 * F_67 ( struct V_27 * V_28 )
{
return F_65 ( & V_28 -> V_29 . V_75 ) ;
}
static void F_68 ( struct V_82 * V_82 )
{
F_58 ( V_76 , V_82 ) ;
}
static T_2 F_69 ( struct V_6 * V_7 , int V_83 )
{
if ( ! V_7 -> V_84 . V_85 )
return V_7 -> V_86 [ V_83 ] ;
return V_7 -> V_4 + ( V_83 << ( ( V_7 -> V_84 . V_36 - 1 ) * V_87 ) ) ;
}
static void F_70 ( struct V_6 * V_7 , int V_83 , T_2 V_4 )
{
if ( V_7 -> V_84 . V_85 )
F_66 ( V_4 != F_69 ( V_7 , V_83 ) ) ;
else
V_7 -> V_86 [ V_83 ] = V_4 ;
}
static struct V_88 * F_71 ( T_2 V_4 ,
struct V_89 * V_90 ,
int V_36 )
{
unsigned long V_91 ;
V_91 = F_72 ( V_4 , V_90 -> V_92 , V_36 ) ;
return & V_90 -> V_29 . V_93 [ V_36 - 2 ] [ V_91 ] ;
}
static void F_73 ( struct V_94 * V_94 , T_2 V_4 )
{
struct V_89 * V_90 ;
struct V_88 * V_95 ;
int V_96 ;
V_90 = F_74 ( V_94 , V_4 ) ;
for ( V_96 = V_97 ;
V_96 < V_37 + V_98 ; ++ V_96 ) {
V_95 = F_71 ( V_4 , V_90 , V_96 ) ;
V_95 -> V_99 += 1 ;
}
V_94 -> V_29 . V_100 ++ ;
}
static void F_75 ( struct V_94 * V_94 , T_2 V_4 )
{
struct V_89 * V_90 ;
struct V_88 * V_95 ;
int V_96 ;
V_90 = F_74 ( V_94 , V_4 ) ;
for ( V_96 = V_97 ;
V_96 < V_37 + V_98 ; ++ V_96 ) {
V_95 = F_71 ( V_4 , V_90 , V_96 ) ;
V_95 -> V_99 -= 1 ;
F_38 ( V_95 -> V_99 < 0 ) ;
}
V_94 -> V_29 . V_100 -- ;
}
static int F_76 ( struct V_94 * V_94 ,
T_2 V_4 ,
int V_36 )
{
struct V_89 * V_90 ;
struct V_88 * V_95 ;
V_90 = F_74 ( V_94 , V_4 ) ;
if ( V_90 ) {
V_95 = F_71 ( V_4 , V_90 , V_36 ) ;
return V_95 -> V_99 ;
}
return 1 ;
}
static int F_77 ( struct V_94 * V_94 , T_2 V_4 )
{
unsigned long V_101 ;
int V_96 , V_58 = 0 ;
V_101 = F_78 ( V_94 , V_4 ) ;
for ( V_96 = V_37 ;
V_96 < ( V_37 + V_98 ) ; ++ V_96 ) {
if ( V_101 >= F_79 ( V_96 ) )
V_58 = V_96 ;
else
break;
}
return V_58 ;
}
static struct V_89 *
F_80 ( struct V_27 * V_28 , T_2 V_4 ,
bool V_102 )
{
struct V_89 * V_90 ;
V_90 = F_74 ( V_28 -> V_94 , V_4 ) ;
if ( ! V_90 || V_90 -> V_103 & V_104 ||
( V_102 && V_90 -> V_105 ) )
V_90 = NULL ;
return V_90 ;
}
static bool F_81 ( struct V_27 * V_28 , T_2 V_106 )
{
return ! F_80 ( V_28 , V_106 , true ) ;
}
static int F_82 ( struct V_27 * V_28 , T_2 V_106 )
{
int V_107 , V_36 , V_108 ;
V_107 = F_77 ( V_28 -> V_94 , V_106 ) ;
if ( V_107 == V_37 )
return V_107 ;
V_108 = V_66 ( V_109 -> V_110 () , V_107 ) ;
for ( V_36 = V_97 ; V_36 <= V_108 ; ++ V_36 )
if ( F_76 ( V_28 -> V_94 , V_106 , V_36 ) )
break;
return V_36 - 1 ;
}
static int F_83 ( struct V_27 * V_28 , T_1 * V_12 ,
unsigned long * V_111 )
{
struct V_82 * V_112 ;
int V_96 , V_50 = 0 ;
if ( ! * V_111 ) {
F_84 ( L_1 , V_12 , * V_12 ) ;
* V_111 = ( unsigned long ) V_12 ;
} else if ( ! ( * V_111 & 1 ) ) {
F_84 ( L_2 , V_12 , * V_12 ) ;
V_112 = F_67 ( V_28 ) ;
V_112 -> V_113 [ 0 ] = ( T_1 * ) * V_111 ;
V_112 -> V_113 [ 1 ] = V_12 ;
* V_111 = ( unsigned long ) V_112 | 1 ;
++ V_50 ;
} else {
F_84 ( L_3 , V_12 , * V_12 ) ;
V_112 = (struct V_82 * ) ( * V_111 & ~ 1ul ) ;
while ( V_112 -> V_113 [ V_114 - 1 ] && V_112 -> V_115 ) {
V_112 = V_112 -> V_115 ;
V_50 += V_114 ;
}
if ( V_112 -> V_113 [ V_114 - 1 ] ) {
V_112 -> V_115 = F_67 ( V_28 ) ;
V_112 = V_112 -> V_115 ;
}
for ( V_96 = 0 ; V_112 -> V_113 [ V_96 ] ; ++ V_96 )
++ V_50 ;
V_112 -> V_113 [ V_96 ] = V_12 ;
}
return V_50 ;
}
static void
F_85 ( unsigned long * V_111 , struct V_82 * V_112 ,
int V_96 , struct V_82 * V_116 )
{
int V_117 ;
for ( V_117 = V_114 - 1 ; ! V_112 -> V_113 [ V_117 ] && V_117 > V_96 ; -- V_117 )
;
V_112 -> V_113 [ V_96 ] = V_112 -> V_113 [ V_117 ] ;
V_112 -> V_113 [ V_117 ] = NULL ;
if ( V_117 != 0 )
return;
if ( ! V_116 && ! V_112 -> V_115 )
* V_111 = ( unsigned long ) V_112 -> V_113 [ 0 ] ;
else
if ( V_116 )
V_116 -> V_115 = V_112 -> V_115 ;
else
* V_111 = ( unsigned long ) V_112 -> V_115 | 1 ;
F_68 ( V_112 ) ;
}
static void F_86 ( T_1 * V_12 , unsigned long * V_111 )
{
struct V_82 * V_112 ;
struct V_82 * V_116 ;
int V_96 ;
if ( ! * V_111 ) {
F_87 ( V_118 L_4 , V_12 ) ;
F_88 () ;
} else if ( ! ( * V_111 & 1 ) ) {
F_84 ( L_5 , V_12 ) ;
if ( ( T_1 * ) * V_111 != V_12 ) {
F_87 ( V_118 L_6 , V_12 ) ;
F_88 () ;
}
* V_111 = 0 ;
} else {
F_84 ( L_7 , V_12 ) ;
V_112 = (struct V_82 * ) ( * V_111 & ~ 1ul ) ;
V_116 = NULL ;
while ( V_112 ) {
for ( V_96 = 0 ; V_96 < V_114 && V_112 -> V_113 [ V_96 ] ; ++ V_96 )
if ( V_112 -> V_113 [ V_96 ] == V_12 ) {
F_85 ( V_111 ,
V_112 , V_96 ,
V_116 ) ;
return;
}
V_116 = V_112 ;
V_112 = V_112 -> V_115 ;
}
F_89 ( L_8 , V_12 ) ;
F_88 () ;
}
}
static void F_90 ( unsigned long * V_111 , T_5 V_119 )
{
struct V_82 * V_112 ;
int V_96 ;
if ( ! * V_111 )
return;
if ( ! ( * V_111 & 1 ) )
return V_119 ( ( T_1 * ) * V_111 ) ;
V_112 = (struct V_82 * ) ( * V_111 & ~ 1ul ) ;
while ( V_112 ) {
for ( V_96 = 0 ; V_96 < V_114 && V_112 -> V_113 [ V_96 ] ; ++ V_96 )
V_119 ( V_112 -> V_113 [ V_96 ] ) ;
V_112 = V_112 -> V_115 ;
}
}
static unsigned long * F_91 ( T_2 V_4 , int V_36 ,
struct V_89 * V_90 )
{
unsigned long V_91 ;
V_91 = F_72 ( V_4 , V_90 -> V_92 , V_36 ) ;
return & V_90 -> V_29 . V_120 [ V_36 - V_37 ] [ V_91 ] ;
}
static unsigned long * F_92 ( struct V_94 * V_94 , T_2 V_4 , int V_36 )
{
struct V_89 * V_90 ;
V_90 = F_74 ( V_94 , V_4 ) ;
return F_91 ( V_4 , V_36 , V_90 ) ;
}
static bool F_93 ( struct V_27 * V_28 )
{
struct V_62 * V_63 ;
V_63 = & V_28 -> V_29 . V_75 ;
return F_56 ( V_63 ) ;
}
static int F_94 ( struct V_27 * V_28 , T_1 * V_12 , T_2 V_4 )
{
struct V_6 * V_7 ;
unsigned long * V_121 ;
V_7 = F_3 ( F_4 ( V_12 ) ) ;
F_70 ( V_7 , V_12 - V_7 -> V_122 , V_4 ) ;
V_121 = F_92 ( V_28 -> V_94 , V_4 , V_7 -> V_84 . V_36 ) ;
return F_83 ( V_28 , V_12 , V_121 ) ;
}
static void F_95 ( struct V_94 * V_94 , T_1 * V_12 )
{
struct V_6 * V_7 ;
T_2 V_4 ;
unsigned long * V_121 ;
V_7 = F_3 ( F_4 ( V_12 ) ) ;
V_4 = F_69 ( V_7 , V_12 - V_7 -> V_122 ) ;
V_121 = F_92 ( V_94 , V_4 , V_7 -> V_84 . V_36 ) ;
F_86 ( V_12 , V_121 ) ;
}
static T_1 * F_96 ( unsigned long V_120 , struct V_123 * V_124 )
{
if ( ! V_120 )
return NULL ;
if ( ! ( V_120 & 1 ) ) {
V_124 -> V_112 = NULL ;
return ( T_1 * ) V_120 ;
}
V_124 -> V_112 = (struct V_82 * ) ( V_120 & ~ 1ul ) ;
V_124 -> V_125 = 0 ;
return V_124 -> V_112 -> V_113 [ V_124 -> V_125 ] ;
}
static T_1 * F_97 ( struct V_123 * V_124 )
{
if ( V_124 -> V_112 ) {
if ( V_124 -> V_125 < V_114 - 1 ) {
T_1 * V_3 ;
++ V_124 -> V_125 ;
V_3 = V_124 -> V_112 -> V_113 [ V_124 -> V_125 ] ;
if ( V_3 )
return V_3 ;
}
V_124 -> V_112 = V_124 -> V_112 -> V_115 ;
if ( V_124 -> V_112 ) {
V_124 -> V_125 = 0 ;
return V_124 -> V_112 -> V_113 [ V_124 -> V_125 ] ;
}
}
return NULL ;
}
static void F_98 ( struct V_94 * V_94 , T_1 * V_3 )
{
if ( F_42 ( V_3 ) )
F_95 ( V_94 , V_3 ) ;
}
static bool F_99 ( struct V_94 * V_94 , T_1 * V_3 )
{
if ( F_18 ( * V_3 ) ) {
F_38 ( F_3 ( F_4 ( V_3 ) ) -> V_84 . V_36 ==
V_37 ) ;
F_98 ( V_94 , V_3 ) ;
-- V_94 -> V_126 . V_127 ;
return true ;
}
return false ;
}
static void F_100 ( struct V_27 * V_28 , T_1 * V_3 )
{
if ( F_99 ( V_28 -> V_94 , V_3 ) )
F_101 ( V_28 -> V_94 ) ;
}
static bool
F_102 ( struct V_94 * V_94 , T_1 * V_3 , bool * V_128 , bool V_129 )
{
T_1 V_12 = * V_3 ;
if ( ! F_36 ( V_12 ) &&
! ( V_129 && F_34 ( V_12 ) ) )
return false ;
F_84 ( L_9 , V_3 , * V_3 ) ;
if ( F_99 ( V_94 , V_3 ) ) {
* V_128 |= true ;
return true ;
}
if ( V_129 )
V_12 &= ~ V_54 ;
V_12 = V_12 & ~ V_130 ;
* V_128 |= F_39 ( V_3 , V_12 ) ;
return false ;
}
static bool F_103 ( struct V_94 * V_94 , unsigned long * V_121 ,
bool V_129 )
{
T_1 * V_3 ;
struct V_123 V_124 ;
bool V_128 = false ;
for ( V_3 = F_96 ( * V_121 , & V_124 ) ; V_3 ; ) {
F_66 ( ! ( * V_3 & V_33 ) ) ;
if ( F_102 ( V_94 , V_3 , & V_128 , V_129 ) ) {
V_3 = F_96 ( * V_121 , & V_124 ) ;
continue;
}
V_3 = F_97 ( & V_124 ) ;
}
return V_128 ;
}
void F_104 ( struct V_94 * V_94 ,
struct V_89 * V_90 ,
T_2 V_131 , unsigned long V_132 )
{
unsigned long * V_121 ;
while ( V_132 ) {
V_121 = F_91 ( V_90 -> V_92 + V_131 + F_105 ( V_132 ) ,
V_37 , V_90 ) ;
F_103 ( V_94 , V_121 , false ) ;
V_132 &= V_132 - 1 ;
}
}
static bool F_106 ( struct V_94 * V_94 , T_1 V_4 )
{
struct V_89 * V_90 ;
unsigned long * V_121 ;
int V_96 ;
bool V_133 = false ;
V_90 = F_74 ( V_94 , V_4 ) ;
for ( V_96 = V_37 ;
V_96 < V_37 + V_98 ; ++ V_96 ) {
V_121 = F_91 ( V_4 , V_96 , V_90 ) ;
V_133 |= F_103 ( V_94 , V_121 , true ) ;
}
return V_133 ;
}
static int F_107 ( struct V_94 * V_94 , unsigned long * V_121 ,
struct V_89 * V_90 , unsigned long V_134 )
{
T_1 * V_3 ;
struct V_123 V_124 ;
int V_135 = 0 ;
while ( ( V_3 = F_96 ( * V_121 , & V_124 ) ) ) {
F_66 ( ! ( * V_3 & V_33 ) ) ;
F_84 ( L_10 , V_3 , * V_3 ) ;
F_98 ( V_94 , V_3 ) ;
V_135 = 1 ;
}
return V_135 ;
}
static int F_108 ( struct V_94 * V_94 , unsigned long * V_121 ,
struct V_89 * V_90 , unsigned long V_134 )
{
T_1 * V_3 ;
struct V_123 V_124 ;
int V_136 = 0 ;
T_1 V_56 ;
T_6 * V_137 = ( T_6 * ) V_134 ;
T_3 V_138 ;
F_38 ( F_109 ( * V_137 ) ) ;
V_138 = F_110 ( * V_137 ) ;
for ( V_3 = F_96 ( * V_121 , & V_124 ) ; V_3 ; ) {
F_66 ( ! F_17 ( * V_3 ) ) ;
F_84 ( L_11 , V_3 , * V_3 ) ;
V_136 = 1 ;
if ( F_111 ( * V_137 ) ) {
F_98 ( V_94 , V_3 ) ;
V_3 = F_96 ( * V_121 , & V_124 ) ;
} else {
V_56 = * V_3 & ~ V_38 ;
V_56 |= ( T_1 ) V_138 << V_11 ;
V_56 &= ~ V_130 ;
V_56 &= ~ V_53 ;
V_56 &= ~ V_23 ;
F_42 ( V_3 ) ;
F_6 ( V_3 , V_56 ) ;
V_3 = F_97 ( & V_124 ) ;
}
}
if ( V_136 )
F_101 ( V_94 ) ;
return 0 ;
}
static int F_112 ( struct V_94 * V_94 ,
unsigned long V_139 ,
unsigned long V_140 ,
unsigned long V_134 ,
int (* F_113)( struct V_94 * V_94 ,
unsigned long * V_121 ,
struct V_89 * V_90 ,
unsigned long V_134 ) )
{
int V_117 ;
int V_58 = 0 ;
struct V_141 * V_142 ;
struct V_89 * V_143 ;
V_142 = V_141 ( V_94 ) ;
F_114 (memslot, slots) {
unsigned long V_144 , V_145 ;
T_2 V_146 , V_147 ;
V_144 = F_115 ( V_139 , V_143 -> V_148 ) ;
V_145 = V_66 ( V_140 , V_143 -> V_148 +
( V_143 -> V_149 << V_11 ) ) ;
if ( V_144 >= V_145 )
continue;
V_146 = F_116 ( V_144 , V_143 ) ;
V_147 = F_116 ( V_145 + V_150 - 1 , V_143 ) ;
for ( V_117 = V_37 ;
V_117 < V_37 + V_98 ; ++ V_117 ) {
unsigned long V_91 , V_151 ;
unsigned long * V_121 ;
V_91 = F_72 ( V_146 , V_143 -> V_92 , V_117 ) ;
V_151 = F_72 ( V_147 - 1 , V_143 -> V_92 , V_117 ) ;
V_121 = F_91 ( V_146 , V_117 , V_143 ) ;
for (; V_91 <= V_151 ; ++ V_91 )
V_58 |= F_113 ( V_94 , V_121 ++ , V_143 , V_134 ) ;
}
}
return V_58 ;
}
static int F_117 ( struct V_94 * V_94 , unsigned long V_152 ,
unsigned long V_134 ,
int (* F_113)( struct V_94 * V_94 , unsigned long * V_121 ,
struct V_89 * V_90 ,
unsigned long V_134 ) )
{
return F_112 ( V_94 , V_152 , V_152 + 1 , V_134 , F_113 ) ;
}
int F_118 ( struct V_94 * V_94 , unsigned long V_152 )
{
return F_117 ( V_94 , V_152 , 0 , F_107 ) ;
}
int F_119 ( struct V_94 * V_94 , unsigned long V_139 , unsigned long V_140 )
{
return F_112 ( V_94 , V_139 , V_140 , 0 , F_107 ) ;
}
void F_120 ( struct V_94 * V_94 , unsigned long V_152 , T_6 V_32 )
{
F_117 ( V_94 , V_152 , ( unsigned long ) & V_32 , F_108 ) ;
}
static int F_121 ( struct V_94 * V_94 , unsigned long * V_121 ,
struct V_89 * V_90 , unsigned long V_134 )
{
T_1 * V_3 ;
struct V_123 V_153 ( V_124 ) ;
int V_154 = 0 ;
if ( ! V_23 ) {
V_154 = F_107 ( V_94 , V_121 , V_90 , V_134 ) ;
goto V_78;
}
for ( V_3 = F_96 ( * V_121 , & V_124 ) ; V_3 ;
V_3 = F_97 ( & V_124 ) ) {
F_66 ( ! F_17 ( * V_3 ) ) ;
if ( * V_3 & V_23 ) {
V_154 = 1 ;
F_122 ( ( F_123 ( V_23 ) - 1 ) ,
( unsigned long * ) V_3 ) ;
}
}
V_78:
F_124 ( V_134 , V_90 , V_154 ) ;
return V_154 ;
}
static int F_125 ( struct V_94 * V_94 , unsigned long * V_121 ,
struct V_89 * V_90 , unsigned long V_134 )
{
T_1 * V_3 ;
struct V_123 V_124 ;
int V_154 = 0 ;
if ( ! V_23 )
goto V_78;
for ( V_3 = F_96 ( * V_121 , & V_124 ) ; V_3 ;
V_3 = F_97 ( & V_124 ) ) {
F_66 ( ! F_17 ( * V_3 ) ) ;
if ( * V_3 & V_23 ) {
V_154 = 1 ;
break;
}
}
V_78:
return V_154 ;
}
static void F_126 ( struct V_27 * V_28 , T_1 * V_12 , T_2 V_4 )
{
unsigned long * V_121 ;
struct V_6 * V_7 ;
V_7 = F_3 ( F_4 ( V_12 ) ) ;
V_121 = F_92 ( V_28 -> V_94 , V_4 , V_7 -> V_84 . V_36 ) ;
F_107 ( V_28 -> V_94 , V_121 , NULL , 0 ) ;
F_101 ( V_28 -> V_94 ) ;
}
int F_127 ( struct V_94 * V_94 , unsigned long V_152 )
{
return F_117 ( V_94 , V_152 , V_152 , F_121 ) ;
}
int F_128 ( struct V_94 * V_94 , unsigned long V_152 )
{
return F_117 ( V_94 , V_152 , 0 , F_125 ) ;
}
static int F_129 ( T_1 * V_122 )
{
T_1 * V_125 ;
T_1 * V_140 ;
for ( V_125 = V_122 , V_140 = V_125 + V_150 / sizeof( T_1 ) ; V_125 != V_140 ; V_125 ++ )
if ( F_17 ( * V_125 ) ) {
F_87 ( V_118 L_12 , V_155 ,
V_125 , * V_125 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_130 ( struct V_94 * V_94 , int V_156 )
{
V_94 -> V_29 . V_157 += V_156 ;
F_131 ( & V_158 , V_156 ) ;
}
static void F_132 ( struct V_6 * V_7 )
{
ASSERT ( F_129 ( V_7 -> V_122 ) ) ;
F_133 ( & V_7 -> V_159 ) ;
F_134 ( & V_7 -> V_160 ) ;
F_62 ( ( unsigned long ) V_7 -> V_122 ) ;
if ( ! V_7 -> V_84 . V_85 )
F_62 ( ( unsigned long ) V_7 -> V_86 ) ;
F_58 ( V_80 , V_7 ) ;
}
static unsigned F_135 ( T_2 V_4 )
{
return V_4 & ( ( 1 << V_161 ) - 1 ) ;
}
static void F_136 ( struct V_27 * V_28 ,
struct V_6 * V_7 , T_1 * V_162 )
{
if ( ! V_162 )
return;
F_83 ( V_28 , V_162 , & V_7 -> V_163 ) ;
}
static void F_137 ( struct V_6 * V_7 ,
T_1 * V_162 )
{
F_86 ( V_162 , & V_7 -> V_163 ) ;
}
static void F_138 ( struct V_6 * V_7 ,
T_1 * V_162 )
{
F_137 ( V_7 , V_162 ) ;
F_46 ( V_162 ) ;
}
static struct V_6 * F_139 ( struct V_27 * V_28 ,
T_1 * V_162 , int V_85 )
{
struct V_6 * V_7 ;
V_7 = F_65 ( & V_28 -> V_29 . V_80 ) ;
V_7 -> V_122 = F_65 ( & V_28 -> V_29 . V_79 ) ;
if ( ! V_85 )
V_7 -> V_86 = F_65 ( & V_28 -> V_29 . V_79 ) ;
F_140 ( F_141 ( V_7 -> V_122 ) , ( unsigned long ) V_7 ) ;
F_142 ( & V_7 -> V_160 , & V_28 -> V_94 -> V_29 . V_164 ) ;
V_7 -> V_163 = 0 ;
F_136 ( V_28 , V_7 , V_162 ) ;
F_130 ( V_28 -> V_94 , + 1 ) ;
return V_7 ;
}
static void F_143 ( struct V_6 * V_7 )
{
F_90 ( & V_7 -> V_163 , V_165 ) ;
}
static void V_165 ( T_1 * V_12 )
{
struct V_6 * V_7 ;
unsigned int V_83 ;
V_7 = F_3 ( F_4 ( V_12 ) ) ;
V_83 = V_12 - V_7 -> V_122 ;
if ( F_144 ( V_83 , V_7 -> V_166 ) )
return;
if ( V_7 -> V_167 ++ )
return;
F_143 ( V_7 ) ;
}
static int F_145 ( struct V_27 * V_28 ,
struct V_6 * V_7 )
{
return 1 ;
}
static void F_146 ( struct V_27 * V_28 , T_7 V_168 )
{
}
static void F_147 ( struct V_27 * V_28 ,
struct V_6 * V_7 , T_1 * V_12 ,
const void * V_32 )
{
F_38 ( 1 ) ;
}
static int F_148 ( struct V_169 * V_170 , struct V_6 * V_7 ,
int V_91 )
{
int V_96 ;
if ( V_7 -> V_171 )
for ( V_96 = 0 ; V_96 < V_170 -> V_156 ; V_96 ++ )
if ( V_170 -> V_73 [ V_96 ] . V_7 == V_7 )
return 0 ;
V_170 -> V_73 [ V_170 -> V_156 ] . V_7 = V_7 ;
V_170 -> V_73 [ V_170 -> V_156 ] . V_91 = V_91 ;
V_170 -> V_156 ++ ;
return ( V_170 -> V_156 == V_172 ) ;
}
static int F_149 ( struct V_6 * V_7 ,
struct V_169 * V_170 )
{
int V_96 , V_58 , V_173 = 0 ;
F_150 (i, sp->unsync_child_bitmap, 512 ) {
struct V_6 * V_174 ;
T_1 V_175 = V_7 -> V_122 [ V_96 ] ;
if ( ! F_17 ( V_175 ) || F_18 ( V_175 ) )
goto V_176;
V_174 = F_3 ( V_175 & V_38 ) ;
if ( V_174 -> V_167 ) {
if ( F_148 ( V_170 , V_174 , V_96 ) )
return - V_177 ;
V_58 = F_149 ( V_174 , V_170 ) ;
if ( ! V_58 )
goto V_176;
else if ( V_58 > 0 )
V_173 += V_58 ;
else
return V_58 ;
} else if ( V_174 -> V_171 ) {
V_173 ++ ;
if ( F_148 ( V_170 , V_174 , V_96 ) )
return - V_177 ;
} else
goto V_176;
continue;
V_176:
F_151 ( V_96 , V_7 -> V_166 ) ;
V_7 -> V_167 -- ;
F_38 ( ( int ) V_7 -> V_167 < 0 ) ;
}
return V_173 ;
}
static int F_152 ( struct V_6 * V_7 ,
struct V_169 * V_170 )
{
if ( ! V_7 -> V_167 )
return 0 ;
F_148 ( V_170 , V_7 , 0 ) ;
return F_149 ( V_7 , V_170 ) ;
}
static void F_153 ( struct V_94 * V_94 , struct V_6 * V_7 )
{
F_38 ( ! V_7 -> V_171 ) ;
F_154 ( V_7 ) ;
V_7 -> V_171 = 0 ;
-- V_94 -> V_126 . V_178 ;
}
static int F_155 ( struct V_27 * V_28 , struct V_6 * V_7 ,
struct V_179 * V_180 , bool V_181 )
{
if ( V_7 -> V_84 . V_182 != ! ! F_156 ( V_28 ) ) {
F_157 ( V_28 -> V_94 , V_7 , V_180 ) ;
return 1 ;
}
if ( V_181 )
F_153 ( V_28 -> V_94 , V_7 ) ;
if ( V_28 -> V_29 . V_183 . V_184 ( V_28 , V_7 ) ) {
F_157 ( V_28 -> V_94 , V_7 , V_180 ) ;
return 1 ;
}
F_158 ( V_28 ) ;
return 0 ;
}
static int F_159 ( struct V_27 * V_28 ,
struct V_6 * V_7 )
{
F_160 ( V_180 ) ;
int V_58 ;
V_58 = F_155 ( V_28 , V_7 , & V_180 , false ) ;
if ( V_58 )
F_161 ( V_28 -> V_94 , & V_180 ) ;
return V_58 ;
}
static void F_162 ( struct V_27 * V_28 , int V_185 ) { }
static void F_163 ( void ) { }
static int F_164 ( struct V_27 * V_28 , struct V_6 * V_7 ,
struct V_179 * V_180 )
{
return F_155 ( V_28 , V_7 , V_180 , true ) ;
}
static void F_165 ( struct V_27 * V_28 , T_2 V_4 )
{
struct V_6 * V_15 ;
F_160 ( V_180 ) ;
bool V_128 = false ;
F_166 (vcpu->kvm, s, gfn) {
if ( ! V_15 -> V_171 )
continue;
F_38 ( V_15 -> V_84 . V_36 != V_37 ) ;
F_153 ( V_28 -> V_94 , V_15 ) ;
if ( ( V_15 -> V_84 . V_182 != ! ! F_156 ( V_28 ) ) ||
( V_28 -> V_29 . V_183 . V_184 ( V_28 , V_15 ) ) ) {
F_157 ( V_28 -> V_94 , V_15 , & V_180 ) ;
continue;
}
V_128 = true ;
}
F_161 ( V_28 -> V_94 , & V_180 ) ;
if ( V_128 )
F_158 ( V_28 ) ;
}
static int F_167 ( struct V_169 * V_170 ,
struct V_186 * V_187 ,
int V_96 )
{
int V_188 ;
for ( V_188 = V_96 + 1 ; V_188 < V_170 -> V_156 ; V_188 ++ ) {
struct V_6 * V_7 = V_170 -> V_73 [ V_188 ] . V_7 ;
if ( V_7 -> V_84 . V_36 == V_37 ) {
V_187 -> V_91 [ 0 ] = V_170 -> V_73 [ V_188 ] . V_91 ;
return V_188 ;
}
V_187 -> V_189 [ V_7 -> V_84 . V_36 - 2 ] = V_7 ;
V_187 -> V_91 [ V_7 -> V_84 . V_36 - 1 ] = V_170 -> V_73 [ V_188 ] . V_91 ;
}
return V_188 ;
}
static void F_168 ( struct V_186 * V_187 )
{
struct V_6 * V_7 ;
unsigned int V_36 = 0 ;
do {
unsigned int V_91 = V_187 -> V_91 [ V_36 ] ;
V_7 = V_187 -> V_189 [ V_36 ] ;
if ( ! V_7 )
return;
-- V_7 -> V_167 ;
F_38 ( ( int ) V_7 -> V_167 < 0 ) ;
F_151 ( V_91 , V_7 -> V_166 ) ;
V_36 ++ ;
} while ( V_36 < V_190 - 1 && ! V_7 -> V_167 );
}
static void F_169 ( struct V_6 * V_189 ,
struct V_186 * V_187 ,
struct V_169 * V_170 )
{
V_187 -> V_189 [ V_189 -> V_84 . V_36 - 1 ] = NULL ;
V_170 -> V_156 = 0 ;
}
static void F_170 ( struct V_27 * V_28 ,
struct V_6 * V_189 )
{
int V_96 ;
struct V_6 * V_7 ;
struct V_186 V_187 ;
struct V_169 V_191 ;
F_160 ( V_180 ) ;
F_169 ( V_189 , & V_187 , & V_191 ) ;
while ( F_152 ( V_189 , & V_191 ) ) {
bool V_192 = false ;
F_171 (pages, sp, parents, i)
V_192 |= F_106 ( V_28 -> V_94 , V_7 -> V_4 ) ;
if ( V_192 )
F_101 ( V_28 -> V_94 ) ;
F_171 (pages, sp, parents, i) {
F_164 ( V_28 , V_7 , & V_180 ) ;
F_168 ( & V_187 ) ;
}
F_161 ( V_28 -> V_94 , & V_180 ) ;
F_172 ( & V_28 -> V_94 -> V_193 ) ;
F_169 ( V_189 , & V_187 , & V_191 ) ;
}
}
static void F_173 ( struct V_6 * V_7 )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_194 ; ++ V_96 )
V_7 -> V_122 [ V_96 ] = 0ull ;
}
static void F_174 ( struct V_6 * V_7 )
{
V_7 -> V_195 = 0 ;
}
static void F_175 ( T_1 * V_12 )
{
struct V_6 * V_7 = F_3 ( F_4 ( V_12 ) ) ;
F_174 ( V_7 ) ;
}
static struct V_6 * F_176 ( struct V_27 * V_28 ,
T_2 V_4 ,
T_7 V_196 ,
unsigned V_36 ,
int V_85 ,
unsigned V_5 ,
T_1 * V_162 )
{
union V_197 V_84 ;
unsigned V_198 ;
struct V_6 * V_7 ;
bool V_199 = false ;
V_84 = V_28 -> V_29 . V_183 . V_200 ;
V_84 . V_36 = V_36 ;
V_84 . V_85 = V_85 ;
if ( V_84 . V_85 )
V_84 . V_182 = 0 ;
V_84 . V_5 = V_5 ;
if ( ! V_28 -> V_29 . V_183 . V_201
&& V_28 -> V_29 . V_183 . V_202 <= V_203 ) {
V_198 = V_196 >> ( V_11 + ( V_204 * V_36 ) ) ;
V_198 &= ( 1 << ( ( V_205 - V_204 ) * V_36 ) ) - 1 ;
V_84 . V_198 = V_198 ;
}
F_177 (vcpu->kvm, sp, gfn) {
if ( ! V_199 && V_7 -> V_171 )
V_199 = true ;
if ( V_7 -> V_84 . V_206 != V_84 . V_206 )
continue;
if ( V_7 -> V_171 && F_159 ( V_28 , V_7 ) )
break;
F_136 ( V_28 , V_7 , V_162 ) ;
if ( V_7 -> V_167 ) {
F_178 ( V_207 , V_28 ) ;
F_143 ( V_7 ) ;
} else if ( V_7 -> V_171 )
F_143 ( V_7 ) ;
F_174 ( V_7 ) ;
F_179 ( V_7 , false ) ;
return V_7 ;
}
++ V_28 -> V_94 -> V_126 . V_208 ;
V_7 = F_139 ( V_28 , V_162 , V_85 ) ;
if ( ! V_7 )
return V_7 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_84 = V_84 ;
F_180 ( & V_7 -> V_159 ,
& V_28 -> V_94 -> V_29 . V_209 [ F_135 ( V_4 ) ] ) ;
if ( ! V_85 ) {
if ( F_106 ( V_28 -> V_94 , V_4 ) )
F_101 ( V_28 -> V_94 ) ;
if ( V_36 > V_37 && V_199 )
F_165 ( V_28 , V_4 ) ;
F_73 ( V_28 -> V_94 , V_4 ) ;
}
F_173 ( V_7 ) ;
F_179 ( V_7 , true ) ;
return V_7 ;
}
static void F_181 ( struct V_210 * V_211 ,
struct V_27 * V_28 , T_1 V_212 )
{
V_211 -> V_212 = V_212 ;
V_211 -> V_213 = V_28 -> V_29 . V_183 . V_214 ;
V_211 -> V_36 = V_28 -> V_29 . V_183 . V_215 ;
if ( V_211 -> V_36 == V_190 &&
V_28 -> V_29 . V_183 . V_202 < V_190 &&
! V_28 -> V_29 . V_183 . V_201 )
-- V_211 -> V_36 ;
if ( V_211 -> V_36 == V_216 ) {
V_211 -> V_213
= V_28 -> V_29 . V_183 . V_217 [ ( V_212 >> 30 ) & 3 ] ;
V_211 -> V_213 &= V_38 ;
-- V_211 -> V_36 ;
if ( ! V_211 -> V_213 )
V_211 -> V_36 = 0 ;
}
}
static bool F_182 ( struct V_210 * V_211 )
{
if ( V_211 -> V_36 < V_37 )
return false ;
V_211 -> V_83 = F_183 ( V_211 -> V_212 , V_211 -> V_36 ) ;
V_211 -> V_3 = ( ( T_1 * ) F_184 ( V_211 -> V_213 ) ) + V_211 -> V_83 ;
return true ;
}
static void F_185 ( struct V_210 * V_211 ,
T_1 V_12 )
{
if ( F_21 ( V_12 , V_211 -> V_36 ) ) {
V_211 -> V_36 = 0 ;
return;
}
V_211 -> V_213 = V_12 & V_38 ;
-- V_211 -> V_36 ;
}
static void F_186 ( struct V_210 * V_211 )
{
return F_185 ( V_211 , * V_211 -> V_3 ) ;
}
static void F_187 ( T_1 * V_3 , struct V_6 * V_7 )
{
T_1 V_12 ;
V_12 = F_4 ( V_7 -> V_122 ) | V_33 | V_130 |
V_22 | V_26 | V_23 ;
F_6 ( V_3 , V_12 ) ;
}
static void F_188 ( struct V_27 * V_28 , T_1 * V_3 ,
unsigned V_218 )
{
if ( F_17 ( * V_3 ) && ! F_18 ( * V_3 ) ) {
struct V_6 * V_174 ;
V_174 = F_3 ( * V_3 & V_38 ) ;
if ( V_174 -> V_84 . V_5 == V_218 )
return;
F_138 ( V_174 , V_3 ) ;
F_101 ( V_28 -> V_94 ) ;
}
}
static bool F_189 ( struct V_94 * V_94 , struct V_6 * V_7 ,
T_1 * V_12 )
{
T_1 V_32 ;
struct V_6 * V_174 ;
V_32 = * V_12 ;
if ( F_17 ( V_32 ) ) {
if ( F_21 ( V_32 , V_7 -> V_84 . V_36 ) ) {
F_98 ( V_94 , V_12 ) ;
if ( F_18 ( V_32 ) )
-- V_94 -> V_126 . V_127 ;
} else {
V_174 = F_3 ( V_32 & V_38 ) ;
F_138 ( V_174 , V_12 ) ;
}
return true ;
}
if ( F_7 ( V_32 ) )
F_46 ( V_12 ) ;
return false ;
}
static void F_190 ( struct V_94 * V_94 ,
struct V_6 * V_7 )
{
unsigned V_96 ;
for ( V_96 = 0 ; V_96 < V_194 ; ++ V_96 )
F_189 ( V_94 , V_7 , V_7 -> V_122 + V_96 ) ;
}
static void F_191 ( struct V_6 * V_7 , T_1 * V_162 )
{
F_137 ( V_7 , V_162 ) ;
}
static void F_192 ( struct V_94 * V_94 , struct V_6 * V_7 )
{
T_1 * V_3 ;
struct V_123 V_124 ;
while ( ( V_3 = F_96 ( V_7 -> V_163 , & V_124 ) ) )
F_138 ( V_7 , V_3 ) ;
}
static int F_193 ( struct V_94 * V_94 ,
struct V_6 * V_189 ,
struct V_179 * V_180 )
{
int V_96 , V_219 = 0 ;
struct V_186 V_187 ;
struct V_169 V_191 ;
if ( V_189 -> V_84 . V_36 == V_37 )
return 0 ;
F_169 ( V_189 , & V_187 , & V_191 ) ;
while ( F_152 ( V_189 , & V_191 ) ) {
struct V_6 * V_7 ;
F_171 (pages, sp, parents, i) {
F_157 ( V_94 , V_7 , V_180 ) ;
F_168 ( & V_187 ) ;
V_219 ++ ;
}
F_169 ( V_189 , & V_187 , & V_191 ) ;
}
return V_219 ;
}
static int F_157 ( struct V_94 * V_94 , struct V_6 * V_7 ,
struct V_179 * V_180 )
{
int V_58 ;
F_194 ( V_7 ) ;
++ V_94 -> V_126 . V_220 ;
V_58 = F_193 ( V_94 , V_7 , V_180 ) ;
F_190 ( V_94 , V_7 ) ;
F_192 ( V_94 , V_7 ) ;
if ( ! V_7 -> V_84 . V_221 && ! V_7 -> V_84 . V_85 )
F_75 ( V_94 , V_7 -> V_4 ) ;
if ( V_7 -> V_171 )
F_153 ( V_94 , V_7 ) ;
if ( ! V_7 -> V_222 ) {
V_58 ++ ;
F_195 ( & V_7 -> V_160 , V_180 ) ;
F_130 ( V_94 , - 1 ) ;
} else {
F_195 ( & V_7 -> V_160 , & V_94 -> V_29 . V_164 ) ;
F_196 ( V_94 ) ;
}
V_7 -> V_84 . V_221 = 1 ;
return V_58 ;
}
static void F_161 ( struct V_94 * V_94 ,
struct V_179 * V_180 )
{
struct V_6 * V_7 , * V_223 ;
if ( F_197 ( V_180 ) )
return;
F_50 () ;
F_101 ( V_94 ) ;
F_198 (sp, nsp, invalid_list, link) {
F_38 ( ! V_7 -> V_84 . V_221 || V_7 -> V_222 ) ;
F_132 ( V_7 ) ;
}
}
static bool F_199 ( struct V_94 * V_94 ,
struct V_179 * V_180 )
{
struct V_6 * V_7 ;
if ( F_197 ( & V_94 -> V_29 . V_164 ) )
return false ;
V_7 = F_200 ( V_94 -> V_29 . V_164 . V_224 ,
struct V_6 , V_160 ) ;
F_157 ( V_94 , V_7 , V_180 ) ;
return true ;
}
void F_201 ( struct V_94 * V_94 , unsigned int V_225 )
{
F_160 ( V_180 ) ;
F_202 ( & V_94 -> V_193 ) ;
if ( V_94 -> V_29 . V_157 > V_225 ) {
while ( V_94 -> V_29 . V_157 > V_225 )
if ( ! F_199 ( V_94 , & V_180 ) )
break;
F_161 ( V_94 , & V_180 ) ;
V_225 = V_94 -> V_29 . V_157 ;
}
V_94 -> V_29 . V_226 = V_225 ;
F_203 ( & V_94 -> V_193 ) ;
}
int F_204 ( struct V_94 * V_94 , T_2 V_4 )
{
struct V_6 * V_7 ;
F_160 ( V_180 ) ;
int V_74 ;
F_205 ( L_13 , V_155 , V_4 ) ;
V_74 = 0 ;
F_202 ( & V_94 -> V_193 ) ;
F_166 (kvm, sp, gfn) {
F_205 ( L_14 , V_155 , V_4 ,
V_7 -> V_84 . V_206 ) ;
V_74 = 1 ;
F_157 ( V_94 , V_7 , & V_180 ) ;
}
F_161 ( V_94 , & V_180 ) ;
F_203 ( & V_94 -> V_193 ) ;
return V_74 ;
}
static int F_206 ( struct V_227 * V_228 ,
T_1 V_139 , T_1 V_140 )
{
int V_96 ;
T_1 V_229 , V_132 ;
T_8 V_230 , V_231 ;
int V_232 = V_233 ;
if ( ! V_228 -> V_234 )
return 0xFF ;
V_140 -- ;
if ( V_228 -> V_235 && ( V_139 < 0x100000 ) ) {
int V_91 ;
if ( V_139 < 0x80000 ) {
V_91 = 0 ;
V_91 += ( V_139 >> 16 ) ;
return V_228 -> V_236 [ V_91 ] ;
} else if ( V_139 < 0xC0000 ) {
V_91 = 1 * 8 ;
V_91 += ( ( V_139 - 0x80000 ) >> 14 ) ;
return V_228 -> V_236 [ V_91 ] ;
} else if ( V_139 < 0x1000000 ) {
V_91 = 3 * 8 ;
V_91 += ( ( V_139 - 0xC0000 ) >> 12 ) ;
return V_228 -> V_236 [ V_91 ] ;
}
}
if ( ! ( V_228 -> V_234 & 2 ) )
return V_228 -> V_237 ;
V_230 = 0xFF ;
for ( V_96 = 0 ; V_96 < V_232 ; ++ V_96 ) {
unsigned short V_238 , V_239 ;
if ( ! ( V_228 -> V_240 [ V_96 ] . V_241 & ( 1 << 11 ) ) )
continue;
V_229 = ( ( ( T_1 ) V_228 -> V_240 [ V_96 ] . V_242 ) << 32 ) +
( V_228 -> V_240 [ V_96 ] . V_243 & V_13 ) ;
V_132 = ( ( ( T_1 ) V_228 -> V_240 [ V_96 ] . V_244 ) << 32 ) +
( V_228 -> V_240 [ V_96 ] . V_241 & V_13 ) ;
V_238 = ( ( V_139 & V_132 ) == ( V_229 & V_132 ) ) ;
V_239 = ( ( V_140 & V_132 ) == ( V_229 & V_132 ) ) ;
if ( V_238 != V_239 )
return 0xFE ;
if ( ( V_139 & V_132 ) != ( V_229 & V_132 ) )
continue;
V_231 = V_228 -> V_240 [ V_96 ] . V_243 & 0xff ;
if ( V_230 == 0xFF ) {
V_230 = V_231 ;
continue;
}
if ( V_230 == V_245 ||
V_231 == V_245 )
return V_245 ;
if ( ( V_230 == V_246 &&
V_231 == V_247 ) ||
( V_230 == V_247 &&
V_231 == V_246 ) ) {
V_230 = V_247 ;
V_231 = V_247 ;
}
if ( V_230 != V_231 )
return V_245 ;
}
if ( V_230 != 0xFF )
return V_230 ;
return V_228 -> V_237 ;
}
T_8 F_207 ( struct V_27 * V_28 , T_2 V_4 )
{
T_8 V_248 ;
V_248 = F_206 ( & V_28 -> V_29 . V_228 , V_4 << V_11 ,
( V_4 << V_11 ) + V_150 ) ;
if ( V_248 == 0xfe || V_248 == 0xff )
V_248 = V_246 ;
return V_248 ;
}
static void F_208 ( struct V_27 * V_28 , struct V_6 * V_7 )
{
F_209 ( V_7 ) ;
++ V_28 -> V_94 -> V_126 . V_178 ;
V_7 -> V_171 = 1 ;
F_143 ( V_7 ) ;
}
static void F_210 ( struct V_27 * V_28 , T_2 V_4 )
{
struct V_6 * V_15 ;
F_166 (vcpu->kvm, s, gfn) {
if ( V_15 -> V_171 )
continue;
F_38 ( V_15 -> V_84 . V_36 != V_37 ) ;
F_208 ( V_28 , V_15 ) ;
}
}
static int F_211 ( struct V_27 * V_28 , T_2 V_4 ,
bool V_249 )
{
struct V_6 * V_15 ;
bool V_250 = false ;
F_166 (vcpu->kvm, s, gfn) {
if ( ! V_249 )
return 1 ;
if ( V_15 -> V_84 . V_36 != V_37 )
return 1 ;
if ( ! V_15 -> V_171 )
V_250 = true ;
}
if ( V_250 )
F_210 ( V_28 , V_4 ) ;
return 0 ;
}
static int F_212 ( struct V_27 * V_28 , T_1 * V_3 ,
unsigned V_251 , int V_36 ,
T_2 V_4 , T_3 V_14 , bool V_252 ,
bool V_249 , bool V_253 )
{
T_1 V_12 ;
int V_58 = 0 ;
if ( F_10 ( V_3 , V_4 , V_14 , V_251 ) )
return 0 ;
V_12 = V_33 ;
if ( ! V_252 )
V_12 |= V_23 ;
if ( V_251 & V_254 )
V_12 |= V_26 ;
else
V_12 |= V_25 ;
if ( V_251 & V_9 )
V_12 |= V_22 ;
if ( V_36 > V_37 )
V_12 |= V_34 ;
if ( V_255 )
V_12 |= V_109 -> V_256 ( V_28 , V_4 ,
F_43 ( V_14 ) ) ;
if ( V_253 )
V_12 |= V_53 ;
else
V_251 &= ~ V_8 ;
V_12 |= ( T_1 ) V_14 << V_11 ;
if ( V_251 & V_8 ) {
if ( V_36 > V_37 &&
F_76 ( V_28 -> V_94 , V_4 , V_36 ) )
goto V_257;
V_12 |= V_130 | V_54 ;
if ( ! V_249 && F_36 ( * V_3 ) )
goto V_258;
if ( F_211 ( V_28 , V_4 , V_249 ) ) {
F_205 ( L_15 ,
V_155 , V_4 ) ;
V_58 = 1 ;
V_251 &= ~ V_8 ;
V_12 &= ~ ( V_130 | V_54 ) ;
}
}
if ( V_251 & V_8 )
F_213 ( V_28 -> V_94 , V_4 ) ;
V_258:
if ( F_39 ( V_3 , V_12 ) )
F_101 ( V_28 -> V_94 ) ;
V_257:
return V_58 ;
}
static void F_214 ( struct V_27 * V_28 , T_1 * V_3 ,
unsigned V_251 , int V_259 , int * V_260 ,
int V_36 , T_2 V_4 , T_3 V_14 , bool V_252 ,
bool V_253 )
{
int V_261 = 0 ;
int V_262 ;
F_205 ( L_16 , V_155 ,
* V_3 , V_259 , V_4 ) ;
if ( F_20 ( * V_3 ) ) {
if ( V_36 > V_37 &&
! F_18 ( * V_3 ) ) {
struct V_6 * V_174 ;
T_1 V_32 = * V_3 ;
V_174 = F_3 ( V_32 & V_38 ) ;
F_138 ( V_174 , V_3 ) ;
F_101 ( V_28 -> V_94 ) ;
} else if ( V_14 != F_22 ( * V_3 ) ) {
F_205 ( L_17 ,
F_22 ( * V_3 ) , V_14 ) ;
F_98 ( V_28 -> V_94 , V_3 ) ;
F_101 ( V_28 -> V_94 ) ;
} else
V_261 = 1 ;
}
if ( F_212 ( V_28 , V_3 , V_251 , V_36 , V_4 , V_14 , V_252 ,
true , V_253 ) ) {
if ( V_259 )
* V_260 = 1 ;
F_158 ( V_28 ) ;
}
if ( F_11 ( F_7 ( * V_3 ) && V_260 ) )
* V_260 = 1 ;
F_205 ( L_18 , V_155 , * V_3 ) ;
F_205 ( L_19 ,
F_18 ( * V_3 ) ? L_20 : L_21 ,
* V_3 & V_33 ? L_22 : L_23 , V_4 ,
* V_3 , V_3 ) ;
if ( ! V_261 && F_18 ( * V_3 ) )
++ V_28 -> V_94 -> V_126 . V_127 ;
if ( F_17 ( * V_3 ) ) {
if ( ! V_261 ) {
V_262 = F_94 ( V_28 , V_3 , V_4 ) ;
if ( V_262 > V_263 )
F_126 ( V_28 , V_3 , V_4 ) ;
}
}
F_215 ( V_14 ) ;
}
static void F_216 ( struct V_27 * V_28 )
{
F_217 ( V_28 ) ;
}
static bool F_218 ( struct V_264 * V_183 , T_1 V_39 , int V_36 )
{
int V_265 ;
V_265 = ( V_39 >> 7 ) & 1 ;
return ( V_39 & V_183 -> V_266 [ V_265 ] [ V_36 - 1 ] ) != 0 ;
}
static T_3 F_219 ( struct V_27 * V_28 , T_2 V_4 ,
bool V_102 )
{
struct V_89 * V_90 ;
V_90 = F_80 ( V_28 , V_4 , V_102 ) ;
if ( ! V_90 )
return V_267 ;
return F_220 ( V_90 , V_4 ) ;
}
static bool F_221 ( struct V_27 * V_28 ,
struct V_6 * V_7 , T_1 * V_12 ,
T_1 V_39 )
{
if ( F_218 ( & V_28 -> V_29 . V_183 , V_39 , V_37 ) )
goto V_268;
if ( ! F_222 ( V_39 ) )
goto V_268;
if ( ! ( V_39 & V_269 ) )
goto V_268;
return false ;
V_268:
F_98 ( V_28 -> V_94 , V_12 ) ;
return true ;
}
static int F_223 ( struct V_27 * V_28 ,
struct V_6 * V_7 ,
T_1 * V_139 , T_1 * V_140 )
{
struct V_73 * V_191 [ V_77 ] ;
unsigned V_5 = V_7 -> V_84 . V_5 ;
int V_96 , V_58 ;
T_2 V_4 ;
V_4 = F_69 ( V_7 , V_139 - V_7 -> V_122 ) ;
if ( ! F_80 ( V_28 , V_4 , V_5 & V_8 ) )
return - 1 ;
V_58 = F_224 ( V_28 -> V_94 , V_4 , V_191 , V_140 - V_139 ) ;
if ( V_58 <= 0 )
return - 1 ;
for ( V_96 = 0 ; V_96 < V_58 ; V_96 ++ , V_4 ++ , V_139 ++ )
F_214 ( V_28 , V_139 , V_5 , 0 , NULL ,
V_7 -> V_84 . V_36 , V_4 , F_225 ( V_191 [ V_96 ] ) ,
true , true ) ;
return 0 ;
}
static void F_226 ( struct V_27 * V_28 ,
struct V_6 * V_7 , T_1 * V_3 )
{
T_1 * V_12 , * V_139 = NULL ;
int V_96 ;
F_38 ( ! V_7 -> V_84 . V_85 ) ;
V_96 = ( V_3 - V_7 -> V_122 ) & ~ ( V_77 - 1 ) ;
V_12 = V_7 -> V_122 + V_96 ;
for ( V_96 = 0 ; V_96 < V_77 ; V_96 ++ , V_12 ++ ) {
if ( F_17 ( * V_12 ) || V_12 == V_3 ) {
if ( ! V_139 )
continue;
if ( F_223 ( V_28 , V_7 , V_139 , V_12 ) < 0 )
break;
V_139 = NULL ;
} else if ( ! V_139 )
V_139 = V_12 ;
}
}
static void F_227 ( struct V_27 * V_28 , T_1 * V_3 )
{
struct V_6 * V_7 ;
if ( ! V_23 )
return;
V_7 = F_3 ( F_4 ( V_3 ) ) ;
if ( V_7 -> V_84 . V_36 > V_37 )
return;
F_226 ( V_28 , V_7 , V_3 ) ;
}
static int F_228 ( struct V_27 * V_28 , T_9 V_270 , int V_271 ,
int V_272 , int V_36 , T_2 V_4 , T_3 V_14 ,
bool V_273 )
{
struct V_210 V_211 ;
struct V_6 * V_7 ;
int V_260 = 0 ;
T_2 V_274 ;
F_229 (vcpu, (u64)gfn << PAGE_SHIFT, iterator) {
if ( V_211 . V_36 == V_36 ) {
F_214 ( V_28 , V_211 . V_3 , V_275 ,
V_271 , & V_260 , V_36 , V_4 , V_14 ,
V_273 , V_272 ) ;
F_227 ( V_28 , V_211 . V_3 ) ;
++ V_28 -> V_126 . V_276 ;
break;
}
if ( ! F_17 ( * V_211 . V_3 ) ) {
T_1 V_277 = V_211 . V_212 ;
V_277 &= F_230 ( V_211 . V_36 ) ;
V_274 = V_277 >> V_11 ;
V_7 = F_176 ( V_28 , V_274 , V_211 . V_212 ,
V_211 . V_36 - 1 ,
1 , V_275 , V_211 . V_3 ) ;
F_187 ( V_211 . V_3 , V_7 ) ;
}
}
return V_260 ;
}
static void F_231 ( unsigned long V_278 , struct V_279 * V_280 )
{
T_10 V_281 ;
V_281 . V_282 = V_283 ;
V_281 . V_284 = 0 ;
V_281 . V_285 = V_286 ;
V_281 . V_287 = ( void V_288 * ) V_278 ;
V_281 . V_289 = V_11 ;
F_232 ( V_283 , & V_281 , V_280 ) ;
}
static int F_233 ( struct V_27 * V_28 , T_2 V_4 , T_3 V_14 )
{
if ( V_14 == V_290 )
return 1 ;
if ( V_14 == V_291 ) {
F_231 ( F_234 ( V_28 -> V_94 , V_4 ) , V_292 ) ;
return 0 ;
}
return - V_293 ;
}
static void F_235 ( struct V_27 * V_28 ,
T_2 * V_294 , T_3 * V_295 , int * V_296 )
{
T_3 V_14 = * V_295 ;
T_2 V_4 = * V_294 ;
int V_36 = * V_296 ;
if ( ! F_236 ( V_14 ) && ! F_43 ( V_14 ) &&
V_36 == V_37 &&
F_237 ( F_45 ( V_14 ) ) &&
! F_76 ( V_28 -> V_94 , V_4 , V_97 ) ) {
unsigned long V_132 ;
* V_296 = V_36 = V_97 ;
V_132 = F_238 ( V_36 ) - 1 ;
F_239 ( ( V_4 & V_132 ) != ( V_14 & V_132 ) ) ;
if ( V_14 & V_132 ) {
V_4 &= ~ V_132 ;
* V_294 = V_4 ;
F_215 ( V_14 ) ;
V_14 &= ~ V_132 ;
F_240 ( V_14 ) ;
* V_295 = V_14 ;
}
}
}
static bool F_241 ( struct V_27 * V_28 , T_7 V_168 , T_2 V_4 ,
T_3 V_14 , unsigned V_5 , int * V_297 )
{
bool V_58 = true ;
if ( F_11 ( F_242 ( V_14 ) ) ) {
* V_297 = F_233 ( V_28 , V_4 , V_14 ) ;
goto exit;
}
if ( F_11 ( F_12 ( V_14 ) ) )
F_243 ( V_28 , V_168 , V_4 , V_5 ) ;
V_58 = false ;
exit:
return V_58 ;
}
static bool F_244 ( struct V_27 * V_28 , T_4 V_298 )
{
if ( ! ( V_298 & V_299 ) ||
! ( V_298 & V_300 ) )
return false ;
return true ;
}
static bool
F_245 ( struct V_27 * V_28 , T_1 * V_3 , T_1 V_12 )
{
struct V_6 * V_7 = F_3 ( F_4 ( V_3 ) ) ;
T_2 V_4 ;
F_38 ( ! V_7 -> V_84 . V_85 ) ;
V_4 = F_69 ( V_7 , V_3 - V_7 -> V_122 ) ;
if ( F_246 ( V_3 , V_12 , V_12 | V_130 ) == V_12 )
F_213 ( V_28 -> V_94 , V_4 ) ;
return true ;
}
static bool F_247 ( struct V_27 * V_28 , T_7 V_168 , int V_36 ,
T_4 V_298 )
{
struct V_210 V_211 ;
bool V_58 = false ;
T_1 V_12 = 0ull ;
if ( ! F_244 ( V_28 , V_298 ) )
return false ;
F_48 ( V_28 ) ;
F_248 (vcpu, gva, iterator, spte)
if ( ! F_17 ( V_12 ) || V_211 . V_36 < V_36 )
break;
if ( ! F_20 ( V_12 ) ) {
V_58 = true ;
goto exit;
}
if ( ! F_21 ( V_12 , V_36 ) )
goto exit;
if ( F_36 ( V_12 ) ) {
V_58 = true ;
goto exit;
}
if ( ! F_34 ( V_12 ) )
goto exit;
V_58 = F_245 ( V_28 , V_211 . V_3 , V_12 ) ;
exit:
F_249 ( V_28 , V_168 , V_298 , V_211 . V_3 ,
V_12 , V_58 ) ;
F_51 ( V_28 ) ;
return V_58 ;
}
static int F_250 ( struct V_27 * V_28 , T_7 V_270 , T_4 V_298 ,
T_2 V_4 , bool V_273 )
{
int V_74 ;
int V_36 ;
int V_301 ;
T_3 V_14 ;
unsigned long V_302 ;
bool V_272 , V_271 = V_298 & V_300 ;
V_301 = F_81 ( V_28 , V_4 ) ;
if ( F_251 ( ! V_301 ) ) {
V_36 = F_82 ( V_28 , V_4 ) ;
if ( V_36 > V_97 )
V_36 = V_97 ;
V_4 &= ~ ( F_238 ( V_36 ) - 1 ) ;
} else
V_36 = V_37 ;
if ( F_247 ( V_28 , V_270 , V_36 , V_298 ) )
return 0 ;
V_302 = V_28 -> V_94 -> V_303 ;
F_33 () ;
if ( F_252 ( V_28 , V_273 , V_4 , V_270 , & V_14 , V_271 , & V_272 ) )
return 0 ;
if ( F_241 ( V_28 , V_270 , V_4 , V_14 , V_275 , & V_74 ) )
return V_74 ;
F_202 ( & V_28 -> V_94 -> V_193 ) ;
if ( F_253 ( V_28 -> V_94 , V_302 ) )
goto V_304;
F_254 ( V_28 ) ;
if ( F_251 ( ! V_301 ) )
F_235 ( V_28 , & V_4 , & V_14 , & V_36 ) ;
V_74 = F_228 ( V_28 , V_270 , V_271 , V_272 , V_36 , V_4 , V_14 ,
V_273 ) ;
F_203 ( & V_28 -> V_94 -> V_193 ) ;
return V_74 ;
V_304:
F_203 ( & V_28 -> V_94 -> V_193 ) ;
F_215 ( V_14 ) ;
return 0 ;
}
static void F_217 ( struct V_27 * V_28 )
{
int V_96 ;
struct V_6 * V_7 ;
F_160 ( V_180 ) ;
if ( ! F_255 ( V_28 -> V_29 . V_183 . V_214 ) )
return;
F_202 ( & V_28 -> V_94 -> V_193 ) ;
if ( V_28 -> V_29 . V_183 . V_215 == V_190 &&
( V_28 -> V_29 . V_183 . V_202 == V_190 ||
V_28 -> V_29 . V_183 . V_201 ) ) {
T_11 V_305 = V_28 -> V_29 . V_183 . V_214 ;
V_7 = F_3 ( V_305 ) ;
-- V_7 -> V_222 ;
if ( ! V_7 -> V_222 && V_7 -> V_84 . V_221 ) {
F_157 ( V_28 -> V_94 , V_7 , & V_180 ) ;
F_161 ( V_28 -> V_94 , & V_180 ) ;
}
V_28 -> V_29 . V_183 . V_214 = V_306 ;
F_203 ( & V_28 -> V_94 -> V_193 ) ;
return;
}
for ( V_96 = 0 ; V_96 < 4 ; ++ V_96 ) {
T_11 V_305 = V_28 -> V_29 . V_183 . V_217 [ V_96 ] ;
if ( V_305 ) {
V_305 &= V_38 ;
V_7 = F_3 ( V_305 ) ;
-- V_7 -> V_222 ;
if ( ! V_7 -> V_222 && V_7 -> V_84 . V_221 )
F_157 ( V_28 -> V_94 , V_7 ,
& V_180 ) ;
}
V_28 -> V_29 . V_183 . V_217 [ V_96 ] = V_306 ;
}
F_161 ( V_28 -> V_94 , & V_180 ) ;
F_203 ( & V_28 -> V_94 -> V_193 ) ;
V_28 -> V_29 . V_183 . V_214 = V_306 ;
}
static int F_256 ( struct V_27 * V_28 , T_2 V_307 )
{
int V_58 = 0 ;
if ( ! F_257 ( V_28 -> V_94 , V_307 ) ) {
F_178 ( V_308 , V_28 ) ;
V_58 = 1 ;
}
return V_58 ;
}
static int F_258 ( struct V_27 * V_28 )
{
struct V_6 * V_7 ;
unsigned V_96 ;
if ( V_28 -> V_29 . V_183 . V_215 == V_190 ) {
F_202 ( & V_28 -> V_94 -> V_193 ) ;
F_254 ( V_28 ) ;
V_7 = F_176 ( V_28 , 0 , 0 , V_190 ,
1 , V_275 , NULL ) ;
++ V_7 -> V_222 ;
F_203 ( & V_28 -> V_94 -> V_193 ) ;
V_28 -> V_29 . V_183 . V_214 = F_4 ( V_7 -> V_122 ) ;
} else if ( V_28 -> V_29 . V_183 . V_215 == V_216 ) {
for ( V_96 = 0 ; V_96 < 4 ; ++ V_96 ) {
T_11 V_305 = V_28 -> V_29 . V_183 . V_217 [ V_96 ] ;
ASSERT ( ! F_255 ( V_305 ) ) ;
F_202 ( & V_28 -> V_94 -> V_193 ) ;
F_254 ( V_28 ) ;
V_7 = F_176 ( V_28 , V_96 << ( 30 - V_11 ) ,
V_96 << 30 ,
V_203 , 1 , V_275 ,
NULL ) ;
V_305 = F_4 ( V_7 -> V_122 ) ;
++ V_7 -> V_222 ;
F_203 ( & V_28 -> V_94 -> V_193 ) ;
V_28 -> V_29 . V_183 . V_217 [ V_96 ] = V_305 | V_33 ;
}
V_28 -> V_29 . V_183 . V_214 = F_4 ( V_28 -> V_29 . V_183 . V_217 ) ;
} else
F_88 () ;
return 0 ;
}
static int F_259 ( struct V_27 * V_28 )
{
struct V_6 * V_7 ;
T_1 V_309 , V_310 ;
T_2 V_307 ;
int V_96 ;
V_307 = V_28 -> V_29 . V_183 . V_311 ( V_28 ) >> V_11 ;
if ( F_256 ( V_28 , V_307 ) )
return 1 ;
if ( V_28 -> V_29 . V_183 . V_202 == V_190 ) {
T_11 V_305 = V_28 -> V_29 . V_183 . V_214 ;
ASSERT ( ! F_255 ( V_305 ) ) ;
F_202 ( & V_28 -> V_94 -> V_193 ) ;
F_254 ( V_28 ) ;
V_7 = F_176 ( V_28 , V_307 , 0 , V_190 ,
0 , V_275 , NULL ) ;
V_305 = F_4 ( V_7 -> V_122 ) ;
++ V_7 -> V_222 ;
F_203 ( & V_28 -> V_94 -> V_193 ) ;
V_28 -> V_29 . V_183 . V_214 = V_305 ;
return 0 ;
}
V_310 = V_33 ;
if ( V_28 -> V_29 . V_183 . V_215 == V_190 )
V_310 |= V_269 | V_130 | V_312 ;
for ( V_96 = 0 ; V_96 < 4 ; ++ V_96 ) {
T_11 V_305 = V_28 -> V_29 . V_183 . V_217 [ V_96 ] ;
ASSERT ( ! F_255 ( V_305 ) ) ;
if ( V_28 -> V_29 . V_183 . V_202 == V_216 ) {
V_309 = V_28 -> V_29 . V_183 . V_313 ( V_28 , V_96 ) ;
if ( ! F_222 ( V_309 ) ) {
V_28 -> V_29 . V_183 . V_217 [ V_96 ] = 0 ;
continue;
}
V_307 = V_309 >> V_11 ;
if ( F_256 ( V_28 , V_307 ) )
return 1 ;
}
F_202 ( & V_28 -> V_94 -> V_193 ) ;
F_254 ( V_28 ) ;
V_7 = F_176 ( V_28 , V_307 , V_96 << 30 ,
V_203 , 0 ,
V_275 , NULL ) ;
V_305 = F_4 ( V_7 -> V_122 ) ;
++ V_7 -> V_222 ;
F_203 ( & V_28 -> V_94 -> V_193 ) ;
V_28 -> V_29 . V_183 . V_217 [ V_96 ] = V_305 | V_310 ;
}
V_28 -> V_29 . V_183 . V_214 = F_4 ( V_28 -> V_29 . V_183 . V_217 ) ;
if ( V_28 -> V_29 . V_183 . V_215 == V_190 ) {
if ( V_28 -> V_29 . V_183 . V_314 == NULL ) {
T_1 * V_314 ;
V_314 = ( void * ) F_260 ( V_70 ) ;
if ( V_314 == NULL )
return 1 ;
V_314 [ 0 ] = F_4 ( V_28 -> V_29 . V_183 . V_217 ) | V_310 ;
V_28 -> V_29 . V_183 . V_314 = V_314 ;
}
V_28 -> V_29 . V_183 . V_214 = F_4 ( V_28 -> V_29 . V_183 . V_314 ) ;
}
return 0 ;
}
static int F_261 ( struct V_27 * V_28 )
{
if ( V_28 -> V_29 . V_183 . V_201 )
return F_258 ( V_28 ) ;
else
return F_259 ( V_28 ) ;
}
static void F_262 ( struct V_27 * V_28 )
{
int V_96 ;
struct V_6 * V_7 ;
if ( V_28 -> V_29 . V_183 . V_201 )
return;
if ( ! F_255 ( V_28 -> V_29 . V_183 . V_214 ) )
return;
F_263 ( V_28 , ~ 0ul ) ;
F_162 ( V_28 , V_315 ) ;
if ( V_28 -> V_29 . V_183 . V_202 == V_190 ) {
T_11 V_305 = V_28 -> V_29 . V_183 . V_214 ;
V_7 = F_3 ( V_305 ) ;
F_170 ( V_28 , V_7 ) ;
F_162 ( V_28 , V_316 ) ;
return;
}
for ( V_96 = 0 ; V_96 < 4 ; ++ V_96 ) {
T_11 V_305 = V_28 -> V_29 . V_183 . V_217 [ V_96 ] ;
if ( V_305 && F_255 ( V_305 ) ) {
V_305 &= V_38 ;
V_7 = F_3 ( V_305 ) ;
F_170 ( V_28 , V_7 ) ;
}
}
F_162 ( V_28 , V_316 ) ;
}
void F_264 ( struct V_27 * V_28 )
{
F_202 ( & V_28 -> V_94 -> V_193 ) ;
F_262 ( V_28 ) ;
F_203 ( & V_28 -> V_94 -> V_193 ) ;
}
static T_9 F_265 ( struct V_27 * V_28 , T_7 V_317 ,
T_4 V_5 , struct V_318 * V_319 )
{
if ( V_319 )
V_319 -> V_298 = 0 ;
return V_317 ;
}
static T_9 F_266 ( struct V_27 * V_28 , T_7 V_317 ,
T_4 V_5 ,
struct V_318 * V_319 )
{
if ( V_319 )
V_319 -> V_298 = 0 ;
return V_28 -> V_29 . V_320 . V_321 ( V_28 , V_317 , V_5 ) ;
}
static bool F_267 ( struct V_27 * V_28 , T_1 V_212 , bool V_85 )
{
if ( V_85 )
return F_268 ( V_28 , V_212 ) ;
return F_269 ( V_28 , V_212 ) ;
}
static bool F_270 ( T_1 V_12 )
{
return F_30 ( V_12 ) ;
}
static T_1 F_271 ( struct V_27 * V_28 , T_1 V_212 )
{
struct V_210 V_211 ;
T_1 V_12 = 0ull ;
F_48 ( V_28 ) ;
F_248 (vcpu, addr, iterator, spte)
if ( ! F_17 ( V_12 ) )
break;
F_51 ( V_28 ) ;
return V_12 ;
}
int F_272 ( struct V_27 * V_28 , T_1 V_212 , bool V_85 )
{
T_1 V_12 ;
if ( F_267 ( V_28 , V_212 , V_85 ) )
return 1 ;
V_12 = F_271 ( V_28 , V_212 ) ;
if ( F_7 ( V_12 ) ) {
T_2 V_4 = F_8 ( V_12 ) ;
unsigned V_5 = F_9 ( V_12 ) ;
if ( V_85 )
V_212 = 0 ;
F_273 ( V_212 , V_4 , V_5 ) ;
F_243 ( V_28 , V_212 , V_4 , V_5 ) ;
return 1 ;
}
if ( V_85 && ! F_270 ( V_12 ) )
return - 1 ;
return 0 ;
}
static int F_274 ( struct V_27 * V_28 , T_1 V_212 ,
T_4 V_298 , bool V_85 )
{
int V_58 ;
V_58 = F_272 ( V_28 , V_212 , V_85 ) ;
F_38 ( V_58 < 0 ) ;
return V_58 ;
}
static int F_275 ( struct V_27 * V_28 , T_7 V_168 ,
T_4 V_298 , bool V_273 )
{
T_2 V_4 ;
int V_74 ;
F_205 ( L_24 , V_155 , V_168 , V_298 ) ;
if ( F_11 ( V_298 & V_322 ) )
return F_274 ( V_28 , V_168 , V_298 , true ) ;
V_74 = F_63 ( V_28 ) ;
if ( V_74 )
return V_74 ;
ASSERT ( V_28 ) ;
ASSERT ( F_255 ( V_28 -> V_29 . V_183 . V_214 ) ) ;
V_4 = V_168 >> V_11 ;
return F_250 ( V_28 , V_168 & V_13 ,
V_298 , V_4 , V_273 ) ;
}
static int F_276 ( struct V_27 * V_28 , T_7 V_168 , T_2 V_4 )
{
struct V_323 V_29 ;
V_29 . V_324 = ( V_28 -> V_29 . V_325 . V_326 ++ << 12 ) | V_28 -> V_327 ;
V_29 . V_4 = V_4 ;
V_29 . V_201 = V_28 -> V_29 . V_183 . V_201 ;
V_29 . V_328 = V_28 -> V_29 . V_183 . V_311 ( V_28 ) ;
return F_277 ( V_28 , V_168 , V_4 , & V_29 ) ;
}
static bool F_278 ( struct V_27 * V_28 )
{
if ( F_11 ( ! F_279 ( V_28 -> V_94 ) ||
F_280 ( V_28 ) ) )
return false ;
return V_109 -> V_329 ( V_28 ) ;
}
static bool F_252 ( struct V_27 * V_28 , bool V_273 , T_2 V_4 ,
T_7 V_168 , T_3 * V_14 , bool V_271 , bool * V_330 )
{
bool V_331 ;
* V_14 = F_281 ( V_28 -> V_94 , V_4 , & V_331 , V_271 , V_330 ) ;
if ( ! V_331 )
return false ;
if ( ! V_273 && F_278 ( V_28 ) ) {
F_282 ( V_168 , V_4 ) ;
if ( F_283 ( V_28 , V_4 ) ) {
F_284 ( V_168 , V_4 ) ;
F_178 ( V_332 , V_28 ) ;
return true ;
} else if ( F_276 ( V_28 , V_168 , V_4 ) )
return true ;
}
* V_14 = F_285 ( V_28 -> V_94 , V_4 , V_271 , V_330 ) ;
return false ;
}
static int F_286 ( struct V_27 * V_28 , T_7 V_333 , T_4 V_298 ,
bool V_273 )
{
T_3 V_14 ;
int V_74 ;
int V_36 ;
int V_301 ;
T_2 V_4 = V_333 >> V_11 ;
unsigned long V_302 ;
int V_271 = V_298 & V_300 ;
bool V_272 ;
ASSERT ( V_28 ) ;
ASSERT ( F_255 ( V_28 -> V_29 . V_183 . V_214 ) ) ;
if ( F_11 ( V_298 & V_322 ) )
return F_274 ( V_28 , V_333 , V_298 , true ) ;
V_74 = F_63 ( V_28 ) ;
if ( V_74 )
return V_74 ;
V_301 = F_81 ( V_28 , V_4 ) ;
if ( F_251 ( ! V_301 ) ) {
V_36 = F_82 ( V_28 , V_4 ) ;
V_4 &= ~ ( F_238 ( V_36 ) - 1 ) ;
} else
V_36 = V_37 ;
if ( F_247 ( V_28 , V_333 , V_36 , V_298 ) )
return 0 ;
V_302 = V_28 -> V_94 -> V_303 ;
F_33 () ;
if ( F_252 ( V_28 , V_273 , V_4 , V_333 , & V_14 , V_271 , & V_272 ) )
return 0 ;
if ( F_241 ( V_28 , 0 , V_4 , V_14 , V_275 , & V_74 ) )
return V_74 ;
F_202 ( & V_28 -> V_94 -> V_193 ) ;
if ( F_253 ( V_28 -> V_94 , V_302 ) )
goto V_304;
F_254 ( V_28 ) ;
if ( F_251 ( ! V_301 ) )
F_235 ( V_28 , & V_4 , & V_14 , & V_36 ) ;
V_74 = F_228 ( V_28 , V_333 , V_271 , V_272 ,
V_36 , V_4 , V_14 , V_273 ) ;
F_203 ( & V_28 -> V_94 -> V_193 ) ;
return V_74 ;
V_304:
F_203 ( & V_28 -> V_94 -> V_193 ) ;
F_215 ( V_14 ) ;
return 0 ;
}
static void F_287 ( struct V_27 * V_28 )
{
F_217 ( V_28 ) ;
}
static int F_288 ( struct V_27 * V_28 ,
struct V_264 * V_334 )
{
V_334 -> V_335 = F_216 ;
V_334 -> V_336 = F_275 ;
V_334 -> V_337 = F_265 ;
V_334 -> free = F_287 ;
V_334 -> V_184 = F_145 ;
V_334 -> V_338 = F_146 ;
V_334 -> V_339 = F_147 ;
V_334 -> V_202 = 0 ;
V_334 -> V_215 = V_216 ;
V_334 -> V_214 = V_306 ;
V_334 -> V_201 = true ;
V_334 -> V_340 = false ;
return 0 ;
}
void F_158 ( struct V_27 * V_28 )
{
++ V_28 -> V_126 . V_341 ;
F_178 ( V_342 , V_28 ) ;
}
static void F_289 ( struct V_27 * V_28 )
{
F_205 ( L_25 , V_155 , F_290 ( V_28 ) ) ;
F_217 ( V_28 ) ;
}
static unsigned long V_311 ( struct V_27 * V_28 )
{
return F_290 ( V_28 ) ;
}
static void F_291 ( struct V_27 * V_28 ,
struct V_318 * V_343 )
{
V_28 -> V_29 . V_183 . F_291 ( V_28 , V_343 ) ;
}
static void F_292 ( struct V_27 * V_28 )
{
F_287 ( V_28 ) ;
}
static inline void F_293 ( unsigned * V_5 , unsigned V_39 )
{
unsigned V_132 ;
F_294 ( V_130 != V_8 ) ;
V_132 = ( unsigned ) ~ V_8 ;
V_132 |= ( V_39 >> ( V_344 - V_345 ) ) & V_130 ;
* V_5 &= V_132 ;
}
static bool F_295 ( T_1 * V_3 , T_2 V_4 , unsigned V_5 ,
int * V_346 )
{
if ( F_11 ( F_7 ( * V_3 ) ) ) {
if ( V_4 != F_8 ( * V_3 ) ) {
F_46 ( V_3 ) ;
return true ;
}
( * V_346 ) ++ ;
F_2 ( V_3 , V_4 , V_5 ) ;
return true ;
}
return false ;
}
static inline unsigned F_296 ( struct V_27 * V_28 , T_1 V_39 )
{
unsigned V_5 ;
V_5 = ( V_39 & ( V_130 | V_312 ) ) | V_254 ;
V_5 &= ~ ( V_39 >> V_347 ) ;
return V_5 ;
}
static inline bool F_297 ( struct V_264 * V_183 , unsigned V_36 , unsigned V_39 )
{
unsigned V_83 ;
V_83 = V_36 - 1 ;
V_83 |= ( V_39 & V_34 ) >> ( V_348 - 2 ) ;
return V_183 -> V_349 & ( 1 << V_83 ) ;
}
static void F_298 ( struct V_27 * V_28 ,
struct V_264 * V_334 )
{
int V_350 = F_299 ( V_28 ) ;
T_1 V_351 = 0 ;
if ( ! V_334 -> V_340 )
V_351 = F_13 ( 63 , 63 ) ;
switch ( V_334 -> V_202 ) {
case V_203 :
V_334 -> V_266 [ 0 ] [ 1 ] = 0 ;
V_334 -> V_266 [ 0 ] [ 0 ] = 0 ;
V_334 -> V_266 [ 1 ] [ 0 ] = V_334 -> V_266 [ 0 ] [ 0 ] ;
if ( ! F_300 ( V_28 ) ) {
V_334 -> V_266 [ 1 ] [ 1 ] = 0 ;
break;
}
if ( F_15 () )
V_334 -> V_266 [ 1 ] [ 1 ] = F_13 ( 17 , 21 ) ;
else
V_334 -> V_266 [ 1 ] [ 1 ] = F_13 ( 13 , 21 ) ;
break;
case V_216 :
V_334 -> V_266 [ 0 ] [ 2 ] =
F_13 ( V_350 , 63 ) |
F_13 ( 7 , 8 ) | F_13 ( 1 , 2 ) ;
V_334 -> V_266 [ 0 ] [ 1 ] = V_351 |
F_13 ( V_350 , 62 ) ;
V_334 -> V_266 [ 0 ] [ 0 ] = V_351 |
F_13 ( V_350 , 62 ) ;
V_334 -> V_266 [ 1 ] [ 1 ] = V_351 |
F_13 ( V_350 , 62 ) |
F_13 ( 13 , 20 ) ;
V_334 -> V_266 [ 1 ] [ 0 ] = V_334 -> V_266 [ 0 ] [ 0 ] ;
break;
case V_190 :
V_334 -> V_266 [ 0 ] [ 3 ] = V_351 |
F_13 ( V_350 , 51 ) | F_13 ( 7 , 8 ) ;
V_334 -> V_266 [ 0 ] [ 2 ] = V_351 |
F_13 ( V_350 , 51 ) | F_13 ( 7 , 8 ) ;
V_334 -> V_266 [ 0 ] [ 1 ] = V_351 |
F_13 ( V_350 , 51 ) ;
V_334 -> V_266 [ 0 ] [ 0 ] = V_351 |
F_13 ( V_350 , 51 ) ;
V_334 -> V_266 [ 1 ] [ 3 ] = V_334 -> V_266 [ 0 ] [ 3 ] ;
V_334 -> V_266 [ 1 ] [ 2 ] = V_351 |
F_13 ( V_350 , 51 ) |
F_13 ( 13 , 29 ) ;
V_334 -> V_266 [ 1 ] [ 1 ] = V_351 |
F_13 ( V_350 , 51 ) |
F_13 ( 13 , 20 ) ;
V_334 -> V_266 [ 1 ] [ 0 ] = V_334 -> V_266 [ 0 ] [ 0 ] ;
break;
}
}
static void F_301 ( struct V_27 * V_28 , struct V_264 * V_183 )
{
unsigned V_352 , V_353 , V_354 ;
T_8 V_355 ;
bool V_343 , V_356 , V_357 , V_358 , V_359 , V_360 , V_361 , V_362 ;
V_362 = F_302 ( V_28 , V_363 ) ;
for ( V_353 = 0 ; V_353 < F_54 ( V_183 -> V_364 ) ; ++ V_353 ) {
V_354 = V_353 << 1 ;
V_355 = 0 ;
V_359 = V_354 & V_300 ;
V_360 = V_354 & V_365 ;
V_361 = V_354 & V_366 ;
for ( V_352 = 0 ; V_352 < 8 ; ++ V_352 ) {
V_356 = V_352 & V_254 ;
V_357 = V_352 & V_8 ;
V_358 = V_352 & V_9 ;
V_356 |= ! V_183 -> V_340 ;
V_357 |= ! F_303 ( V_28 ) && ! V_360 ;
V_356 &= ! ( V_362 && V_358 && ! V_360 ) ;
V_343 = ( V_361 && ! V_356 ) || ( V_360 && ! V_358 ) || ( V_359 && ! V_357 ) ;
V_355 |= V_343 << V_352 ;
}
V_183 -> V_364 [ V_353 ] = V_355 ;
}
}
static void F_304 ( struct V_27 * V_28 , struct V_264 * V_183 )
{
T_8 V_355 ;
unsigned V_36 , V_202 = V_183 -> V_202 ;
const unsigned V_367 = 1 << 2 ;
if ( V_202 == V_216 )
-- V_202 ;
V_355 = 1 | ( 1 << V_367 ) ;
for ( V_36 = V_97 ; V_36 <= V_202 ; ++ V_36 ) {
if ( V_36 <= V_368
&& ( V_183 -> V_202 >= V_216 || F_300 ( V_28 ) ) )
V_355 |= 1 << ( V_367 | ( V_36 - 1 ) ) ;
}
V_183 -> V_349 = V_355 ;
}
static int F_305 ( struct V_27 * V_28 ,
struct V_264 * V_334 ,
int V_36 )
{
V_334 -> V_340 = F_16 ( V_28 ) ;
V_334 -> V_202 = V_36 ;
F_298 ( V_28 , V_334 ) ;
F_301 ( V_28 , V_334 ) ;
F_304 ( V_28 , V_334 ) ;
ASSERT ( F_156 ( V_28 ) ) ;
V_334 -> V_335 = F_289 ;
V_334 -> V_336 = V_369 ;
V_334 -> V_337 = V_370 ;
V_334 -> V_184 = V_371 ;
V_334 -> V_338 = V_372 ;
V_334 -> V_339 = V_373 ;
V_334 -> free = F_292 ;
V_334 -> V_215 = V_36 ;
V_334 -> V_214 = V_306 ;
V_334 -> V_201 = false ;
return 0 ;
}
static int F_306 ( struct V_27 * V_28 ,
struct V_264 * V_334 )
{
return F_305 ( V_28 , V_334 , V_190 ) ;
}
static int F_307 ( struct V_27 * V_28 ,
struct V_264 * V_334 )
{
V_334 -> V_340 = false ;
V_334 -> V_202 = V_203 ;
F_298 ( V_28 , V_334 ) ;
F_301 ( V_28 , V_334 ) ;
F_304 ( V_28 , V_334 ) ;
V_334 -> V_335 = F_289 ;
V_334 -> V_336 = V_374 ;
V_334 -> V_337 = V_375 ;
V_334 -> free = F_292 ;
V_334 -> V_184 = V_376 ;
V_334 -> V_338 = V_377 ;
V_334 -> V_339 = V_378 ;
V_334 -> V_215 = V_216 ;
V_334 -> V_214 = V_306 ;
V_334 -> V_201 = false ;
return 0 ;
}
static int F_308 ( struct V_27 * V_28 ,
struct V_264 * V_334 )
{
return F_305 ( V_28 , V_334 , V_216 ) ;
}
static int F_309 ( struct V_27 * V_28 )
{
struct V_264 * V_334 = V_28 -> V_29 . V_379 ;
V_334 -> V_200 . V_206 = 0 ;
V_334 -> V_335 = F_216 ;
V_334 -> V_336 = F_286 ;
V_334 -> free = F_287 ;
V_334 -> V_184 = F_145 ;
V_334 -> V_338 = F_146 ;
V_334 -> V_339 = F_147 ;
V_334 -> V_215 = V_109 -> V_380 () ;
V_334 -> V_214 = V_306 ;
V_334 -> V_201 = true ;
V_334 -> V_381 = V_109 -> V_382 ;
V_334 -> V_311 = V_311 ;
V_334 -> V_313 = V_383 ;
V_334 -> F_291 = V_384 ;
if ( ! F_310 ( V_28 ) ) {
V_334 -> V_340 = false ;
V_334 -> V_337 = F_265 ;
V_334 -> V_202 = 0 ;
} else if ( F_311 ( V_28 ) ) {
V_334 -> V_340 = F_16 ( V_28 ) ;
V_334 -> V_202 = V_190 ;
F_298 ( V_28 , V_334 ) ;
V_334 -> V_337 = V_370 ;
} else if ( F_156 ( V_28 ) ) {
V_334 -> V_340 = F_16 ( V_28 ) ;
V_334 -> V_202 = V_216 ;
F_298 ( V_28 , V_334 ) ;
V_334 -> V_337 = V_370 ;
} else {
V_334 -> V_340 = false ;
V_334 -> V_202 = V_203 ;
F_298 ( V_28 , V_334 ) ;
V_334 -> V_337 = V_375 ;
}
F_301 ( V_28 , V_334 ) ;
F_304 ( V_28 , V_334 ) ;
return 0 ;
}
int F_312 ( struct V_27 * V_28 , struct V_264 * V_334 )
{
int V_74 ;
bool V_362 = F_302 ( V_28 , V_363 ) ;
ASSERT ( V_28 ) ;
ASSERT ( ! F_255 ( V_28 -> V_29 . V_183 . V_214 ) ) ;
if ( ! F_310 ( V_28 ) )
V_74 = F_288 ( V_28 , V_334 ) ;
else if ( F_311 ( V_28 ) )
V_74 = F_306 ( V_28 , V_334 ) ;
else if ( F_156 ( V_28 ) )
V_74 = F_308 ( V_28 , V_334 ) ;
else
V_74 = F_307 ( V_28 , V_334 ) ;
V_28 -> V_29 . V_183 . V_200 . V_385 = F_16 ( V_28 ) ;
V_28 -> V_29 . V_183 . V_200 . V_182 = ! ! F_156 ( V_28 ) ;
V_28 -> V_29 . V_183 . V_200 . V_386 = F_303 ( V_28 ) ;
V_28 -> V_29 . V_183 . V_200 . V_387
= V_362 && ! F_303 ( V_28 ) ;
return V_74 ;
}
static int F_313 ( struct V_27 * V_28 )
{
int V_74 = F_312 ( V_28 , V_28 -> V_29 . V_379 ) ;
V_28 -> V_29 . V_379 -> V_381 = V_109 -> V_381 ;
V_28 -> V_29 . V_379 -> V_311 = V_311 ;
V_28 -> V_29 . V_379 -> V_313 = V_383 ;
V_28 -> V_29 . V_379 -> F_291 = V_384 ;
return V_74 ;
}
static int F_314 ( struct V_27 * V_28 )
{
struct V_264 * V_388 = & V_28 -> V_29 . V_320 ;
V_388 -> V_311 = V_311 ;
V_388 -> V_313 = V_383 ;
V_388 -> F_291 = V_384 ;
if ( ! F_310 ( V_28 ) ) {
V_388 -> V_340 = false ;
V_388 -> V_202 = 0 ;
V_388 -> V_337 = F_266 ;
} else if ( F_311 ( V_28 ) ) {
V_388 -> V_340 = F_16 ( V_28 ) ;
V_388 -> V_202 = V_190 ;
F_298 ( V_28 , V_388 ) ;
V_388 -> V_337 = V_389 ;
} else if ( F_156 ( V_28 ) ) {
V_388 -> V_340 = F_16 ( V_28 ) ;
V_388 -> V_202 = V_216 ;
F_298 ( V_28 , V_388 ) ;
V_388 -> V_337 = V_389 ;
} else {
V_388 -> V_340 = false ;
V_388 -> V_202 = V_203 ;
F_298 ( V_28 , V_388 ) ;
V_388 -> V_337 = V_390 ;
}
F_301 ( V_28 , V_388 ) ;
F_304 ( V_28 , V_388 ) ;
return 0 ;
}
static int F_315 ( struct V_27 * V_28 )
{
if ( F_316 ( V_28 ) )
return F_314 ( V_28 ) ;
else if ( V_255 )
return F_309 ( V_28 ) ;
else
return F_313 ( V_28 ) ;
}
static void F_317 ( struct V_27 * V_28 )
{
ASSERT ( V_28 ) ;
if ( F_255 ( V_28 -> V_29 . V_183 . V_214 ) )
V_28 -> V_29 . V_183 . free ( V_28 ) ;
}
int F_318 ( struct V_27 * V_28 )
{
F_317 ( V_28 ) ;
return F_315 ( V_28 ) ;
}
int F_319 ( struct V_27 * V_28 )
{
int V_74 ;
V_74 = F_63 ( V_28 ) ;
if ( V_74 )
goto V_78;
V_74 = F_261 ( V_28 ) ;
F_202 ( & V_28 -> V_94 -> V_193 ) ;
F_262 ( V_28 ) ;
F_203 ( & V_28 -> V_94 -> V_193 ) ;
if ( V_74 )
goto V_78;
V_28 -> V_29 . V_183 . V_381 ( V_28 , V_28 -> V_29 . V_183 . V_214 ) ;
V_78:
return V_74 ;
}
void F_320 ( struct V_27 * V_28 )
{
F_217 ( V_28 ) ;
}
static void F_321 ( struct V_27 * V_28 ,
struct V_6 * V_7 , T_1 * V_12 ,
const void * V_391 )
{
if ( V_7 -> V_84 . V_36 != V_37 ) {
++ V_28 -> V_94 -> V_126 . V_392 ;
return;
}
++ V_28 -> V_94 -> V_126 . V_393 ;
V_28 -> V_29 . V_183 . V_339 ( V_28 , V_7 , V_12 , V_391 ) ;
}
static bool F_322 ( T_1 V_394 , T_1 V_391 )
{
if ( ! F_17 ( V_394 ) )
return false ;
if ( ! F_17 ( V_391 ) )
return true ;
if ( ( V_394 ^ V_391 ) & V_38 )
return true ;
V_394 ^= V_395 ;
V_391 ^= V_395 ;
return ( V_394 & ~ V_391 & V_396 ) != 0 ;
}
static void F_323 ( struct V_27 * V_28 , bool V_397 ,
bool V_398 , bool V_399 )
{
if ( V_397 )
return;
if ( V_398 )
F_101 ( V_28 -> V_94 ) ;
else if ( V_399 )
F_158 ( V_28 ) ;
}
static T_1 F_324 ( struct V_27 * V_28 , T_9 * V_333 ,
const T_8 * V_391 , int * V_400 )
{
T_1 V_401 ;
int V_74 ;
if ( F_156 ( V_28 ) && * V_400 == 4 ) {
* V_333 &= ~ ( T_9 ) 7 ;
* V_400 = 8 ;
V_74 = F_325 ( V_28 -> V_94 , * V_333 , & V_401 , 8 ) ;
if ( V_74 )
V_401 = 0 ;
V_391 = ( const T_8 * ) & V_401 ;
}
switch ( * V_400 ) {
case 4 :
V_401 = * ( const T_4 * ) V_391 ;
break;
case 8 :
V_401 = * ( const T_1 * ) V_391 ;
break;
default:
V_401 = 0 ;
break;
}
return V_401 ;
}
static bool F_326 ( struct V_6 * V_7 )
{
if ( V_7 -> V_84 . V_36 == V_37 )
return false ;
return ++ V_7 -> V_195 >= 3 ;
}
static bool F_327 ( struct V_6 * V_7 , T_9 V_333 ,
int V_400 )
{
unsigned V_402 , V_403 , V_404 ;
F_205 ( L_26 ,
V_333 , V_400 , V_7 -> V_84 . V_206 ) ;
V_402 = F_328 ( V_333 ) ;
V_403 = V_7 -> V_84 . V_182 ? 8 : 4 ;
if ( ! ( V_402 & ( V_403 - 1 ) ) && V_400 == 1 )
return false ;
V_404 = ( V_402 ^ ( V_402 + V_400 - 1 ) ) & ~ ( V_403 - 1 ) ;
V_404 |= V_400 < 4 ;
return V_404 ;
}
static T_1 * F_329 ( struct V_6 * V_7 , T_9 V_333 , int * V_405 )
{
unsigned V_406 , V_198 ;
T_1 * V_12 ;
int V_36 ;
V_406 = F_328 ( V_333 ) ;
V_36 = V_7 -> V_84 . V_36 ;
* V_405 = 1 ;
if ( ! V_7 -> V_84 . V_182 ) {
V_406 <<= 1 ;
if ( V_36 == V_203 ) {
V_406 &= ~ 7 ;
V_406 <<= 1 ;
* V_405 = 2 ;
}
V_198 = V_406 >> V_11 ;
V_406 &= ~ V_13 ;
if ( V_198 != V_7 -> V_84 . V_198 )
return NULL ;
}
V_12 = & V_7 -> V_122 [ V_406 / sizeof( * V_12 ) ] ;
return V_12 ;
}
void F_330 ( struct V_27 * V_28 , T_9 V_333 ,
const T_8 * V_391 , int V_400 )
{
T_2 V_4 = V_333 >> V_11 ;
union V_197 V_132 = { . V_206 = 0 } ;
struct V_6 * V_7 ;
F_160 ( V_180 ) ;
T_1 V_407 , V_401 , * V_12 ;
int V_408 ;
bool V_398 , V_399 , V_397 ;
if ( ! F_29 ( V_28 -> V_94 -> V_29 . V_100 ) )
return;
V_397 = V_398 = V_399 = false ;
F_205 ( L_27 , V_155 , V_333 , V_400 ) ;
V_401 = F_324 ( V_28 , & V_333 , V_391 , & V_400 ) ;
F_63 ( V_28 ) ;
F_202 ( & V_28 -> V_94 -> V_193 ) ;
++ V_28 -> V_94 -> V_126 . V_409 ;
F_162 ( V_28 , V_410 ) ;
V_132 . V_386 = V_132 . V_182 = V_132 . V_385 = 1 ;
F_166 (vcpu->kvm, sp, gfn) {
if ( F_327 ( V_7 , V_333 , V_400 ) ||
F_326 ( V_7 ) ) {
V_397 |= ! ! F_157 ( V_28 -> V_94 , V_7 ,
& V_180 ) ;
++ V_28 -> V_94 -> V_126 . V_411 ;
continue;
}
V_12 = F_329 ( V_7 , V_333 , & V_408 ) ;
if ( ! V_12 )
continue;
V_399 = true ;
while ( V_408 -- ) {
V_407 = * V_12 ;
F_189 ( V_28 -> V_94 , V_7 , V_12 ) ;
if ( V_401 &&
! ( ( V_7 -> V_84 . V_206 ^ V_28 -> V_29 . V_183 . V_200 . V_206 )
& V_132 . V_206 ) && F_93 ( V_28 ) )
F_321 ( V_28 , V_7 , V_12 , & V_401 ) ;
if ( F_322 ( V_407 , * V_12 ) )
V_398 = true ;
++ V_12 ;
}
}
F_323 ( V_28 , V_397 , V_398 , V_399 ) ;
F_161 ( V_28 -> V_94 , & V_180 ) ;
F_162 ( V_28 , V_412 ) ;
F_203 ( & V_28 -> V_94 -> V_193 ) ;
}
int F_331 ( struct V_27 * V_28 , T_7 V_168 )
{
T_9 V_333 ;
int V_74 ;
if ( V_28 -> V_29 . V_183 . V_201 )
return 0 ;
V_333 = F_332 ( V_28 , V_168 , NULL ) ;
V_74 = F_204 ( V_28 -> V_94 , V_333 >> V_11 ) ;
return V_74 ;
}
static void F_254 ( struct V_27 * V_28 )
{
F_160 ( V_180 ) ;
if ( F_251 ( F_333 ( V_28 -> V_94 ) >= V_413 ) )
return;
while ( F_333 ( V_28 -> V_94 ) < V_414 ) {
if ( ! F_199 ( V_28 -> V_94 , & V_180 ) )
break;
++ V_28 -> V_94 -> V_126 . V_415 ;
}
F_161 ( V_28 -> V_94 , & V_180 ) ;
}
static bool F_334 ( struct V_27 * V_28 , T_7 V_212 )
{
if ( V_28 -> V_29 . V_183 . V_201 || F_316 ( V_28 ) )
return F_268 ( V_28 , V_212 ) ;
return F_269 ( V_28 , V_212 ) ;
}
int F_335 ( struct V_27 * V_28 , T_7 V_416 , T_4 V_298 ,
void * V_417 , int V_418 )
{
int V_74 , V_419 = V_420 ;
enum V_421 V_422 ;
V_74 = V_28 -> V_29 . V_183 . V_336 ( V_28 , V_416 , V_298 , false ) ;
if ( V_74 < 0 )
goto V_78;
if ( ! V_74 ) {
V_74 = 1 ;
goto V_78;
}
if ( F_334 ( V_28 , V_416 ) )
V_419 = 0 ;
V_422 = F_336 ( V_28 , V_416 , V_419 , V_417 , V_418 ) ;
switch ( V_422 ) {
case V_423 :
return 1 ;
case V_424 :
++ V_28 -> V_126 . V_425 ;
case V_426 :
return 0 ;
default:
F_88 () ;
}
V_78:
return V_74 ;
}
void F_337 ( struct V_27 * V_28 , T_7 V_168 )
{
V_28 -> V_29 . V_183 . V_338 ( V_28 , V_168 ) ;
F_158 ( V_28 ) ;
++ V_28 -> V_126 . V_338 ;
}
void F_338 ( void )
{
V_255 = true ;
}
void F_339 ( void )
{
V_255 = false ;
}
static void F_340 ( struct V_27 * V_28 )
{
F_62 ( ( unsigned long ) V_28 -> V_29 . V_183 . V_217 ) ;
if ( V_28 -> V_29 . V_183 . V_314 != NULL )
F_62 ( ( unsigned long ) V_28 -> V_29 . V_183 . V_314 ) ;
}
static int F_341 ( struct V_27 * V_28 )
{
struct V_73 * V_73 ;
int V_96 ;
ASSERT ( V_28 ) ;
V_73 = F_342 ( V_70 | V_427 ) ;
if ( ! V_73 )
return - V_71 ;
V_28 -> V_29 . V_183 . V_217 = F_343 ( V_73 ) ;
for ( V_96 = 0 ; V_96 < 4 ; ++ V_96 )
V_28 -> V_29 . V_183 . V_217 [ V_96 ] = V_306 ;
return 0 ;
}
int F_344 ( struct V_27 * V_28 )
{
ASSERT ( V_28 ) ;
V_28 -> V_29 . V_379 = & V_28 -> V_29 . V_183 ;
V_28 -> V_29 . V_183 . V_214 = V_306 ;
V_28 -> V_29 . V_183 . V_321 = V_321 ;
V_28 -> V_29 . V_320 . V_321 = V_428 ;
return F_341 ( V_28 ) ;
}
int F_345 ( struct V_27 * V_28 )
{
ASSERT ( V_28 ) ;
ASSERT ( ! F_255 ( V_28 -> V_29 . V_183 . V_214 ) ) ;
return F_315 ( V_28 ) ;
}
void F_346 ( struct V_94 * V_94 , int V_90 )
{
struct V_89 * V_143 ;
T_2 V_429 ;
int V_96 ;
V_143 = F_347 ( V_94 -> V_430 , V_90 ) ;
V_429 = V_143 -> V_92 + V_143 -> V_149 - 1 ;
F_202 ( & V_94 -> V_193 ) ;
for ( V_96 = V_37 ;
V_96 < V_37 + V_98 ; ++ V_96 ) {
unsigned long * V_121 ;
unsigned long V_431 , V_83 ;
V_121 = V_143 -> V_29 . V_120 [ V_96 - V_37 ] ;
V_431 = F_72 ( V_429 , V_143 -> V_92 , V_96 ) ;
for ( V_83 = 0 ; V_83 <= V_431 ; ++ V_83 , ++ V_121 ) {
if ( * V_121 )
F_103 ( V_94 , V_121 , false ) ;
if ( F_348 () || F_349 ( & V_94 -> V_193 ) ) {
F_101 ( V_94 ) ;
F_172 ( & V_94 -> V_193 ) ;
}
}
}
F_101 ( V_94 ) ;
F_203 ( & V_94 -> V_193 ) ;
}
void F_350 ( struct V_94 * V_94 )
{
struct V_6 * V_7 , * V_432 ;
F_160 ( V_180 ) ;
F_202 ( & V_94 -> V_193 ) ;
V_433:
F_198 (sp, node, &kvm->arch.active_mmu_pages, link)
if ( F_157 ( V_94 , V_7 , & V_180 ) )
goto V_433;
F_161 ( V_94 , & V_180 ) ;
F_203 ( & V_94 -> V_193 ) ;
}
void F_351 ( struct V_94 * V_94 )
{
struct V_6 * V_7 , * V_432 ;
F_160 ( V_180 ) ;
F_202 ( & V_94 -> V_193 ) ;
V_433:
F_198 (sp, node, &kvm->arch.active_mmu_pages, link) {
if ( ! V_7 -> V_10 )
continue;
if ( F_157 ( V_94 , V_7 , & V_180 ) )
goto V_433;
}
F_161 ( V_94 , & V_180 ) ;
F_203 ( & V_94 -> V_193 ) ;
}
static int F_352 ( struct V_434 * V_435 , struct V_436 * V_437 )
{
struct V_94 * V_94 ;
int V_438 = V_437 -> V_438 ;
if ( V_438 == 0 )
goto V_78;
F_353 ( & V_439 ) ;
F_354 (kvm, &vm_list, vm_list) {
int V_91 ;
F_160 ( V_180 ) ;
if ( ! V_438 -- )
break;
if ( ! V_94 -> V_29 . V_157 )
continue;
V_91 = F_355 ( & V_94 -> V_440 ) ;
F_202 ( & V_94 -> V_193 ) ;
F_199 ( V_94 , & V_180 ) ;
F_161 ( V_94 , & V_180 ) ;
F_203 ( & V_94 -> V_193 ) ;
F_356 ( & V_94 -> V_440 , V_91 ) ;
F_357 ( & V_94 -> V_441 , & V_441 ) ;
break;
}
F_358 ( & V_439 ) ;
V_78:
return F_359 ( & V_158 ) ;
}
static void F_360 ( void )
{
if ( V_76 )
F_361 ( V_76 ) ;
if ( V_80 )
F_361 ( V_80 ) ;
}
int F_362 ( void )
{
V_76 = F_363 ( L_28 ,
sizeof( struct V_82 ) ,
0 , 0 , NULL ) ;
if ( ! V_76 )
goto V_442;
V_80 = F_363 ( L_29 ,
sizeof( struct V_6 ) ,
0 , 0 , NULL ) ;
if ( ! V_80 )
goto V_442;
if ( F_364 ( & V_158 , 0 ) )
goto V_442;
F_365 ( & V_443 ) ;
return 0 ;
V_442:
F_360 () ;
return - V_71 ;
}
unsigned int F_366 ( struct V_94 * V_94 )
{
unsigned int V_444 ;
unsigned int V_445 = 0 ;
struct V_141 * V_142 ;
struct V_89 * V_143 ;
V_142 = V_141 ( V_94 ) ;
F_114 (memslot, slots)
V_445 += V_143 -> V_149 ;
V_444 = V_445 * V_446 / 1000 ;
V_444 = F_115 ( V_444 ,
( unsigned int ) V_447 ) ;
return V_444 ;
}
int F_367 ( struct V_27 * V_28 , T_1 V_212 , T_1 V_113 [ 4 ] )
{
struct V_210 V_211 ;
T_1 V_12 ;
int V_448 = 0 ;
F_48 ( V_28 ) ;
F_248 (vcpu, addr, iterator, spte) {
V_113 [ V_211 . V_36 - 1 ] = V_12 ;
V_448 ++ ;
if ( ! F_17 ( V_12 ) )
break;
}
F_51 ( V_28 ) ;
return V_448 ;
}
void F_368 ( struct V_27 * V_28 )
{
ASSERT ( V_28 ) ;
F_317 ( V_28 ) ;
F_340 ( V_28 ) ;
F_64 ( V_28 ) ;
}
void F_369 ( void )
{
F_360 () ;
F_370 ( & V_158 ) ;
F_371 ( & V_443 ) ;
F_163 () ;
}
