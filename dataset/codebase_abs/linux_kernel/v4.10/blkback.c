static inline int F_1 ( struct V_1 * V_2 , struct V_3 * * V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
if ( F_3 ( & V_2 -> V_6 ) ) {
F_4 ( V_2 -> V_7 != 0 ) ;
F_5 ( & V_2 -> V_5 , V_4 ) ;
return F_6 ( 1 , V_3 ) ;
}
F_4 ( V_2 -> V_7 == 0 ) ;
V_3 [ 0 ] = F_7 ( & V_2 -> V_6 , struct V_3 , V_8 ) ;
F_8 ( & V_3 [ 0 ] -> V_8 ) ;
V_2 -> V_7 -- ;
F_5 ( & V_2 -> V_5 , V_4 ) ;
return 0 ;
}
static inline void F_9 ( struct V_1 * V_2 , struct V_3 * * V_3 ,
int V_9 )
{
unsigned long V_4 ;
int V_10 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
F_10 ( & V_3 [ V_10 ] -> V_8 , & V_2 -> V_6 ) ;
V_2 -> V_7 += V_9 ;
F_5 ( & V_2 -> V_5 , V_4 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , int V_9 )
{
struct V_3 * V_3 [ V_11 ] ;
unsigned int V_12 = 0 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
while ( V_2 -> V_7 > V_9 ) {
F_4 ( F_3 ( & V_2 -> V_6 ) ) ;
V_3 [ V_12 ] = F_7 ( & V_2 -> V_6 ,
struct V_3 , V_8 ) ;
F_8 ( & V_3 [ V_12 ] -> V_8 ) ;
V_2 -> V_7 -- ;
if ( ++ V_12 == V_11 ) {
F_5 ( & V_2 -> V_5 , V_4 ) ;
F_12 ( V_12 , V_3 ) ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_12 = 0 ;
}
}
F_5 ( & V_2 -> V_5 , V_4 ) ;
if ( V_12 != 0 )
F_12 ( V_12 , V_3 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
struct V_14 * * V_15 = NULL , * V_16 = NULL ;
struct V_13 * V_17 ;
struct V_18 * V_19 = V_2 -> V_19 ;
if ( V_2 -> V_20 >= V_21 ) {
if ( ! V_19 -> V_22 . V_23 )
V_19 -> V_22 . V_23 = 1 ;
return - V_24 ;
}
V_15 = & V_2 -> V_25 . V_14 ;
while ( * V_15 ) {
V_17 = F_14 ( * V_15 , struct V_13 , V_26 ) ;
V_16 = * V_15 ;
if ( V_13 -> V_27 < V_17 -> V_27 )
V_15 = & ( ( * V_15 ) -> V_28 ) ;
else if ( V_13 -> V_27 > V_17 -> V_27 )
V_15 = & ( ( * V_15 ) -> V_29 ) ;
else {
F_15 ( L_1 ) ;
return - V_30 ;
}
}
F_16 ( V_13 -> V_4 , V_31 ) ;
F_17 ( V_32 , V_13 -> V_4 ) ;
F_18 ( & ( V_13 -> V_26 ) , V_16 , V_15 ) ;
F_19 ( & ( V_13 -> V_26 ) , & V_2 -> V_25 ) ;
V_2 -> V_20 ++ ;
F_20 ( & V_2 -> V_33 ) ;
return 0 ;
}
static struct V_13 * F_21 ( struct V_1 * V_2 ,
T_1 V_34 )
{
struct V_13 * V_35 ;
struct V_14 * V_26 = NULL ;
V_26 = V_2 -> V_25 . V_14 ;
while ( V_26 ) {
V_35 = F_14 ( V_26 , struct V_13 , V_26 ) ;
if ( V_34 < V_35 -> V_27 )
V_26 = V_26 -> V_28 ;
else if ( V_34 > V_35 -> V_27 )
V_26 = V_26 -> V_29 ;
else {
if( F_22 ( V_32 , V_35 -> V_4 ) ) {
F_15 ( L_2 ) ;
return NULL ;
}
F_17 ( V_32 , V_35 -> V_4 ) ;
F_20 ( & V_2 -> V_33 ) ;
return V_35 ;
}
}
return NULL ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
if( ! F_22 ( V_32 , V_13 -> V_4 ) )
F_15 ( L_3 ) ;
F_17 ( V_36 , V_13 -> V_4 ) ;
F_24 ( V_32 , V_13 -> V_4 ) ;
F_25 ( & V_2 -> V_33 ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_37 * V_38 ,
unsigned int V_9 )
{
struct V_39 V_40 [ V_41 ] ;
struct V_3 * V_42 [ V_41 ] ;
struct V_13 * V_13 ;
struct V_14 * V_43 ;
int V_44 = 0 ;
struct V_45 V_46 ;
V_46 . V_42 = V_42 ;
V_46 . V_47 = V_40 ;
V_46 . V_48 = NULL ;
F_27 (persistent_gnt, n, root, node) {
F_4 ( V_13 -> V_49 ==
V_50 ) ;
F_28 ( & V_40 [ V_44 ] ,
( unsigned long ) F_29 ( F_30 (
V_13 -> V_3 ) ) ,
V_51 ,
V_13 -> V_49 ) ;
V_42 [ V_44 ] = V_13 -> V_3 ;
if ( ++ V_44 == V_41 ||
! F_31 ( & V_13 -> V_26 ) ) {
V_46 . V_52 = V_44 ;
F_4 ( F_32 ( & V_46 ) ) ;
F_9 ( V_2 , V_42 , V_44 ) ;
V_44 = 0 ;
}
F_33 ( & V_13 -> V_26 , V_38 ) ;
F_34 ( V_13 ) ;
V_9 -- ;
}
F_4 ( V_9 != 0 ) ;
}
void F_35 ( struct V_53 * V_54 )
{
struct V_39 V_40 [ V_41 ] ;
struct V_3 * V_42 [ V_41 ] ;
struct V_13 * V_13 ;
int V_44 = 0 ;
struct V_1 * V_2 = F_14 ( V_54 , F_36 ( * V_2 ) , V_55 ) ;
struct V_45 V_46 ;
V_46 . V_42 = V_42 ;
V_46 . V_47 = V_40 ;
V_46 . V_48 = NULL ;
while( ! F_3 ( & V_2 -> V_56 ) ) {
V_13 = F_7 ( & V_2 -> V_56 ,
struct V_13 ,
V_57 ) ;
F_8 ( & V_13 -> V_57 ) ;
F_28 ( & V_40 [ V_44 ] ,
F_37 ( V_13 -> V_3 ) ,
V_51 ,
V_13 -> V_49 ) ;
V_42 [ V_44 ] = V_13 -> V_3 ;
if ( ++ V_44 == V_41 ) {
V_46 . V_52 = V_44 ;
F_4 ( F_32 ( & V_46 ) ) ;
F_9 ( V_2 , V_42 , V_44 ) ;
V_44 = 0 ;
}
F_34 ( V_13 ) ;
}
if ( V_44 > 0 ) {
V_46 . V_52 = V_44 ;
F_4 ( F_32 ( & V_46 ) ) ;
F_9 ( V_2 , V_42 , V_44 ) ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_13 ;
struct V_14 * V_43 ;
unsigned int V_58 , V_59 ;
bool V_60 = false , V_61 = false ;
struct V_37 * V_38 ;
if ( V_2 -> V_20 < V_21 ||
( V_2 -> V_20 == V_21 &&
! V_2 -> V_19 -> V_22 . V_23 ) ) {
goto V_62;
}
if ( F_39 ( & V_2 -> V_55 ) ) {
F_15 ( L_4 ) ;
goto V_62;
}
V_58 = ( V_21 / 100 ) * V_63 ;
V_58 = V_2 -> V_20 - V_21 + V_58 ;
V_58 = F_40 ( V_2 -> V_20 , V_58 ) ;
if ( ( V_58 == 0 ) ||
( V_58 > ( V_2 -> V_20 - F_41 ( & V_2 -> V_33 ) ) ) )
goto V_62;
V_59 = V_58 ;
F_42 ( L_5 , V_58 ) ;
F_4 ( ! F_3 ( & V_2 -> V_56 ) ) ;
V_38 = & V_2 -> V_25 ;
V_64:
F_27 (persistent_gnt, n, root, node) {
F_4 ( V_13 -> V_49 ==
V_50 ) ;
if ( V_61 ) {
F_24 ( V_36 , V_13 -> V_4 ) ;
continue;
}
if ( F_22 ( V_32 , V_13 -> V_4 ) )
continue;
if ( ! V_60 &&
( F_22 ( V_36 , V_13 -> V_4 ) ) )
continue;
F_33 ( & V_13 -> V_26 , V_38 ) ;
F_10 ( & V_13 -> V_57 ,
& V_2 -> V_56 ) ;
if ( -- V_58 == 0 )
goto V_65;
}
if ( ! V_60 && ! V_61 ) {
F_42 ( L_6 , V_58 ) ;
V_60 = true ;
goto V_64;
}
V_65:
if ( ! V_61 ) {
F_42 ( L_7 ) ;
V_61 = true ;
goto V_64;
}
V_2 -> V_20 -= ( V_59 - V_58 ) ;
V_2 -> V_19 -> V_22 . V_23 = 0 ;
F_43 ( & V_2 -> V_55 ) ;
F_42 ( L_8 , ( V_59 - V_58 ) , V_59 ) ;
V_62:
return;
}
static struct V_66 * F_44 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = NULL ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_68 , V_4 ) ;
if ( ! F_3 ( & V_2 -> V_69 ) ) {
V_67 = F_45 ( V_2 -> V_69 . V_70 , struct V_66 ,
V_71 ) ;
F_8 ( & V_67 -> V_71 ) ;
}
F_5 ( & V_2 -> V_68 , V_4 ) ;
return V_67 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
unsigned long V_4 ;
int V_72 ;
F_2 ( & V_2 -> V_68 , V_4 ) ;
V_72 = F_3 ( & V_2 -> V_69 ) ;
F_10 ( & V_67 -> V_71 , & V_2 -> V_69 ) ;
F_5 ( & V_2 -> V_68 , V_4 ) ;
if ( V_72 )
F_47 ( & V_2 -> V_73 ) ;
}
static int F_48 ( struct V_74 * V_67 , struct V_18 * V_19 ,
int V_75 )
{
struct V_76 * V_22 = & V_19 -> V_22 ;
int V_77 = - V_78 ;
if ( ( V_75 != V_79 ) && V_22 -> V_80 )
goto V_62;
if ( F_49 ( V_67 -> V_81 ) ) {
T_2 V_82 = V_67 -> V_83 + V_67 -> V_81 ;
if ( F_50 ( V_82 < V_67 -> V_83 ) )
goto V_62;
if ( F_50 ( V_82 > F_51 ( V_22 ) ) )
goto V_62;
}
V_67 -> V_84 = V_22 -> V_85 ;
V_67 -> V_86 = V_22 -> V_86 ;
V_77 = 0 ;
V_62:
return V_77 ;
}
static void F_52 ( struct V_18 * V_19 )
{
struct V_76 * V_22 = & V_19 -> V_22 ;
struct V_87 V_88 ;
int V_89 ;
struct V_90 * V_84 = F_53 ( V_19 -> V_91 ) ;
unsigned long long V_92 = F_51 ( V_22 ) ;
F_54 ( L_9 ,
V_19 -> V_93 , F_55 ( V_22 -> V_85 ) , F_56 ( V_22 -> V_85 ) ) ;
F_54 ( L_10 , V_92 ) ;
V_22 -> V_94 = V_92 ;
V_95:
V_89 = F_57 ( & V_88 ) ;
if ( V_89 ) {
F_58 ( L_11 ) ;
return;
}
V_89 = F_59 ( V_88 , V_84 -> V_96 , L_12 , L_13 ,
( unsigned long long ) F_51 ( V_22 ) ) ;
if ( V_89 ) {
F_58 ( L_14 ) ;
goto abort;
}
V_89 = F_59 ( V_88 , V_84 -> V_96 , L_15 , L_16 , V_84 -> V_97 ) ;
if ( V_89 ) {
F_58 ( L_17 ) ;
goto abort;
}
V_89 = F_60 ( V_88 , 0 ) ;
if ( V_89 == - V_98 )
goto V_95;
if ( V_89 )
F_58 ( L_18 ) ;
return;
abort:
F_60 ( V_88 , 1 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
V_2 -> V_99 = 1 ;
F_47 ( & V_2 -> V_100 ) ;
}
T_3 F_62 ( int V_101 , void * V_102 )
{
F_61 ( V_102 ) ;
return V_103 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_54 ( L_19
L_20 ,
V_104 -> V_105 , V_2 -> V_106 ,
V_2 -> V_107 , V_2 -> V_108 ,
V_2 -> V_109 , V_2 -> V_110 ,
V_2 -> V_20 ,
V_21 ) ;
V_2 -> V_111 = V_112 + F_64 ( 10 * 1000 ) ;
V_2 -> V_107 = 0 ;
V_2 -> V_108 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_110 = 0 ;
}
int F_65 ( void * V_113 )
{
struct V_1 * V_2 = V_113 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_76 * V_22 = & V_19 -> V_22 ;
unsigned long V_114 ;
int V_115 ;
F_66 ( V_19 ) ;
F_67 () ;
while ( ! F_68 () ) {
if ( F_69 () )
continue;
if ( F_50 ( V_22 -> V_94 != F_51 ( V_22 ) ) )
F_52 ( V_19 ) ;
V_114 = F_64 ( V_116 ) ;
V_114 = F_70 (
V_2 -> V_100 ,
V_2 -> V_99 || F_68 () ,
V_114 ) ;
if ( V_114 == 0 )
goto V_117;
V_114 = F_70 (
V_2 -> V_73 ,
! F_3 ( & V_2 -> V_69 ) ||
F_68 () ,
V_114 ) ;
if ( V_114 == 0 )
goto V_117;
V_2 -> V_99 = 0 ;
F_71 () ;
V_115 = F_72 ( V_2 ) ;
if ( V_115 > 0 )
V_2 -> V_99 = 1 ;
if ( V_115 == - V_78 )
F_73 ( V_2 -> V_118 ,
F_68 () ) ;
V_117:
if ( V_19 -> V_22 . V_119 &&
F_74 ( V_112 , V_2 -> V_120 ) ) {
F_38 ( V_2 ) ;
V_2 -> V_120 = V_112 + F_64 ( V_116 ) ;
}
F_11 ( V_2 , V_121 ) ;
if ( V_122 && F_74 ( V_112 , V_2 -> V_111 ) )
F_63 ( V_2 ) ;
}
F_75 ( & V_2 -> V_55 ) ;
if ( V_122 )
F_63 ( V_2 ) ;
V_2 -> V_123 = NULL ;
F_76 ( V_19 ) ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 )
{
if ( ! F_78 ( & V_2 -> V_25 ) )
F_26 ( V_2 , & V_2 -> V_25 ,
V_2 -> V_20 ) ;
F_4 ( ! F_78 ( & V_2 -> V_25 ) ) ;
V_2 -> V_20 = 0 ;
F_11 ( V_2 , 0 ) ;
}
static unsigned int F_79 (
struct V_1 * V_2 ,
struct V_124 * * V_42 ,
unsigned int V_9 ,
struct V_39 * V_47 ,
struct V_3 * * V_125 )
{
unsigned int V_10 , V_126 = 0 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
if ( V_42 [ V_10 ] -> V_13 != NULL ) {
F_23 ( V_2 , V_42 [ V_10 ] -> V_13 ) ;
continue;
}
if ( V_42 [ V_10 ] -> V_49 == V_50 )
continue;
V_125 [ V_126 ] = V_42 [ V_10 ] -> V_3 ;
F_28 ( & V_47 [ V_126 ] , F_37 ( V_42 [ V_10 ] -> V_3 ) ,
V_51 , V_42 [ V_10 ] -> V_49 ) ;
V_42 [ V_10 ] -> V_49 = V_50 ;
V_126 ++ ;
}
return V_126 ;
}
static void F_80 ( int V_127 , struct V_45 * V_35 )
{
struct V_66 * V_66 = (struct V_66 * ) ( V_35 -> V_35 ) ;
struct V_1 * V_2 = V_66 -> V_2 ;
struct V_18 * V_19 = V_2 -> V_19 ;
F_4 ( V_127 ) ;
F_9 ( V_2 , V_35 -> V_42 , V_35 -> V_52 ) ;
F_81 ( V_2 , V_66 -> V_128 ,
V_66 -> V_75 , V_66 -> V_129 ) ;
F_46 ( V_2 , V_66 ) ;
if ( F_82 ( & V_2 -> V_130 ) && F_41 ( & V_19 -> V_131 ) ) {
F_83 ( & V_19 -> V_132 ) ;
}
F_76 ( V_19 ) ;
}
static void F_84 ( struct V_66 * V_67 )
{
struct V_45 * V_54 = & V_67 -> V_133 ;
struct V_1 * V_2 = V_67 -> V_2 ;
struct V_124 * * V_42 = V_67 -> V_134 ;
unsigned int V_126 ;
V_126 = F_79 ( V_2 , V_42 , V_67 -> V_135 ,
V_67 -> V_40 , V_67 -> V_125 ) ;
V_54 -> V_35 = V_67 ;
V_54 -> V_136 = F_80 ;
V_54 -> V_47 = V_67 -> V_40 ;
V_54 -> V_48 = NULL ;
V_54 -> V_42 = V_67 -> V_125 ;
V_54 -> V_52 = V_126 ;
F_85 ( & V_67 -> V_133 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_124 * V_42 [] ,
int V_9 )
{
struct V_39 V_40 [ V_41 ] ;
struct V_3 * V_125 [ V_41 ] ;
unsigned int V_126 = 0 ;
int V_115 ;
while ( V_9 ) {
unsigned int V_137 = F_40 ( V_9 , V_41 ) ;
V_126 = F_79 ( V_2 , V_42 , V_137 ,
V_40 , V_125 ) ;
if ( V_126 ) {
V_115 = F_87 ( V_40 , NULL , V_125 , V_126 ) ;
F_4 ( V_115 ) ;
F_9 ( V_2 , V_125 , V_126 ) ;
}
V_42 += V_137 ;
V_9 -= V_137 ;
}
}
static int F_88 ( struct V_1 * V_2 ,
struct V_124 * V_42 [] ,
int V_9 , bool V_138 )
{
struct V_139 V_140 [ V_41 ] ;
struct V_3 * V_141 [ V_41 ] ;
struct V_13 * V_13 = NULL ;
T_4 V_142 = 0 ;
int V_10 , V_143 , V_144 ;
int V_145 = 0 ;
int V_115 = 0 ;
int V_146 = 0 , V_147 = 0 ;
int V_148 ;
struct V_18 * V_19 = V_2 -> V_19 ;
V_148 = ( V_19 -> V_22 . V_119 ) ;
V_95:
for ( V_10 = V_147 ; V_10 < V_9 ; V_10 ++ ) {
T_5 V_4 ;
if ( V_148 ) {
V_13 = F_21 (
V_2 ,
V_42 [ V_10 ] -> V_34 ) ;
}
if ( V_13 ) {
V_42 [ V_10 ] -> V_3 = V_13 -> V_3 ;
V_42 [ V_10 ] -> V_13 = V_13 ;
} else {
if ( F_1 ( V_2 , & V_42 [ V_10 ] -> V_3 ) )
goto V_149;
V_142 = F_37 ( V_42 [ V_10 ] -> V_3 ) ;
V_141 [ V_145 ] = V_42 [ V_10 ] -> V_3 ;
V_42 [ V_10 ] -> V_13 = NULL ;
V_4 = V_51 ;
if ( ! V_148 && V_138 )
V_4 |= V_150 ;
F_89 ( & V_140 [ V_145 ++ ] , V_142 ,
V_4 , V_42 [ V_10 ] -> V_34 ,
V_19 -> V_93 ) ;
}
V_147 = V_10 + 1 ;
if ( V_145 == V_41 )
break;
}
if ( V_145 ) {
V_115 = F_90 ( V_140 , NULL , V_141 , V_145 ) ;
F_4 ( V_115 ) ;
}
for ( V_143 = V_146 , V_144 = 0 ; V_143 < V_147 ; V_143 ++ ) {
if ( ! V_42 [ V_143 ] -> V_13 ) {
F_4 ( V_144 >= V_145 ) ;
if ( F_50 ( V_140 [ V_144 ] . V_129 != 0 ) ) {
F_42 ( L_21 ) ;
F_9 ( V_2 , & V_42 [ V_143 ] -> V_3 , 1 ) ;
V_42 [ V_143 ] -> V_49 = V_50 ;
V_115 |= 1 ;
goto V_70;
}
V_42 [ V_143 ] -> V_49 = V_140 [ V_144 ] . V_49 ;
} else {
continue;
}
if ( V_148 &&
V_2 -> V_20 < V_21 ) {
V_13 = F_91 ( sizeof( struct V_13 ) ,
V_151 ) ;
if ( ! V_13 ) {
goto V_70;
}
V_13 -> V_27 = V_140 [ V_144 ] . V_152 ;
V_13 -> V_49 = V_140 [ V_144 ] . V_49 ;
V_13 -> V_3 = V_42 [ V_143 ] -> V_3 ;
if ( F_13 ( V_2 ,
V_13 ) ) {
F_34 ( V_13 ) ;
V_13 = NULL ;
goto V_70;
}
V_42 [ V_143 ] -> V_13 = V_13 ;
F_42 ( L_22 ,
V_13 -> V_27 , V_2 -> V_20 ,
V_21 ) ;
goto V_70;
}
if ( V_148 && ! V_19 -> V_22 . V_23 ) {
V_19 -> V_22 . V_23 = 1 ;
F_42 ( L_23 ,
V_19 -> V_93 , V_19 -> V_22 . V_49 ) ;
}
V_70:
V_144 ++ ;
}
V_145 = 0 ;
V_146 = V_147 ;
if ( V_147 != V_9 )
goto V_95;
return V_115 ;
V_149:
F_92 ( L_24 , V_153 ) ;
F_9 ( V_2 , V_141 , V_145 ) ;
return - V_154 ;
}
static int F_93 ( struct V_66 * V_66 )
{
int V_77 ;
V_77 = F_88 ( V_66 -> V_2 , V_66 -> V_134 ,
V_66 -> V_135 ,
( V_66 -> V_75 != V_155 ) ) ;
return V_77 ;
}
static int F_94 ( struct V_156 * V_67 ,
struct V_66 * V_66 ,
struct V_157 V_158 [] ,
struct V_74 * V_159 )
{
struct V_124 * * V_42 = V_66 -> V_160 ;
struct V_1 * V_2 = V_66 -> V_2 ;
int V_161 , V_77 , V_43 , V_162 , V_10 ;
struct V_163 * V_134 = NULL ;
V_162 = V_66 -> V_135 ;
V_161 = F_95 ( V_162 ) ;
F_4 ( V_161 > V_164 ) ;
for ( V_10 = 0 ; V_10 < V_161 ; V_10 ++ )
V_42 [ V_10 ] -> V_34 = V_67 -> V_165 . V_166 . V_161 [ V_10 ] ;
V_77 = F_88 ( V_2 , V_42 , V_161 , true ) ;
if ( V_77 )
goto V_40;
for ( V_43 = 0 , V_10 = 0 ; V_43 < V_162 ; V_43 ++ ) {
T_6 V_167 , V_168 ;
if ( ( V_43 % V_169 ) == 0 ) {
if ( V_134 )
F_96 ( V_134 ) ;
V_134 = F_97 ( V_42 [ V_43 / V_169 ] -> V_3 ) ;
}
V_10 = V_43 % V_169 ;
V_66 -> V_134 [ V_43 ] -> V_34 = V_134 [ V_10 ] . V_34 ;
V_167 = F_98 ( V_134 [ V_10 ] . V_167 ) ;
V_168 = F_98 ( V_134 [ V_10 ] . V_168 ) ;
if ( V_168 >= ( V_170 >> 9 ) || V_168 < V_167 ) {
V_77 = - V_30 ;
goto V_40;
}
V_158 [ V_43 ] . V_171 = V_168 - V_167 + 1 ;
V_158 [ V_43 ] . V_172 = V_167 << 9 ;
V_159 -> V_81 += V_158 [ V_43 ] . V_171 ;
}
V_40:
if ( V_134 )
F_96 ( V_134 ) ;
F_86 ( V_2 , V_42 , V_161 ) ;
return V_77 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_156 * V_67 )
{
int V_89 = 0 ;
int V_129 = V_173 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_174 * V_86 = V_19 -> V_22 . V_86 ;
unsigned long V_175 ;
struct V_74 V_159 ;
F_66 ( V_19 ) ;
V_159 . V_83 = V_67 -> V_165 . V_176 . V_83 ;
V_159 . V_81 = V_67 -> V_165 . V_176 . V_177 ;
V_89 = F_48 ( & V_159 , V_19 , V_178 ) ;
if ( V_89 ) {
F_58 ( L_25 ,
V_159 . V_83 ,
V_159 . V_83 + V_159 . V_81 , V_19 -> V_22 . V_85 ) ;
goto V_179;
}
V_2 -> V_110 ++ ;
V_175 = ( V_19 -> V_22 . V_180 &&
( V_67 -> V_165 . V_176 . V_181 & V_182 ) ) ?
V_183 : 0 ;
V_89 = F_100 ( V_86 , V_67 -> V_165 . V_176 . V_83 ,
V_67 -> V_165 . V_176 . V_177 ,
V_151 , V_175 ) ;
V_179:
if ( V_89 == - V_184 ) {
F_42 ( L_26 ) ;
V_129 = V_185 ;
} else if ( V_89 )
V_129 = V_186 ;
F_81 ( V_2 , V_67 -> V_165 . V_176 . V_128 , V_67 -> V_75 , V_129 ) ;
F_76 ( V_19 ) ;
return V_89 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_156 * V_67 ,
struct V_66 * V_66 )
{
F_46 ( V_2 , V_66 ) ;
F_81 ( V_2 , V_67 -> V_165 . V_187 . V_128 , V_67 -> V_75 ,
V_185 ) ;
return - V_188 ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
F_103 ( & V_19 -> V_131 , 1 ) ;
do {
if ( F_41 ( & V_2 -> V_130 ) == 0 )
break;
F_104 (
& V_19 -> V_132 , V_189 ) ;
if ( ! F_41 ( & V_19 -> V_131 ) )
break;
} while ( ! F_68 () );
F_103 ( & V_19 -> V_131 , 0 ) ;
}
static void F_105 ( struct V_66 * V_66 , int error )
{
if ( ( V_66 -> V_75 == V_190 ) &&
( error == - V_184 ) ) {
F_42 ( L_27 ) ;
F_106 ( V_191 , V_66 -> V_2 -> V_19 -> V_91 , 0 ) ;
V_66 -> V_129 = V_185 ;
} else if ( ( V_66 -> V_75 == V_192 ) &&
( error == - V_184 ) ) {
F_42 ( L_28 ) ;
F_107 ( V_191 , V_66 -> V_2 -> V_19 -> V_91 , 0 ) ;
V_66 -> V_129 = V_185 ;
} else if ( error ) {
F_42 ( L_29
L_30 , error ) ;
V_66 -> V_129 = V_186 ;
}
if ( F_82 ( & V_66 -> V_193 ) )
F_84 ( V_66 ) ;
}
static void F_108 ( struct V_194 * V_194 )
{
F_105 ( V_194 -> V_195 , V_194 -> V_196 ) ;
F_109 ( V_194 ) ;
}
static int
F_110 ( struct V_1 * V_2 )
{
union V_197 * V_198 = & V_2 -> V_198 ;
struct V_156 V_67 ;
struct V_66 * V_66 ;
T_7 V_77 , V_199 ;
int V_200 = 0 ;
V_77 = V_198 -> V_201 . V_202 ;
V_199 = V_198 -> V_201 . V_203 -> V_204 ;
F_111 () ;
if ( F_112 ( & V_198 -> V_201 , V_199 ) ) {
V_77 = V_198 -> V_201 . V_205 ;
F_58 ( L_31 ,
V_199 , V_77 , V_199 - V_77 , V_2 -> V_19 -> V_22 . V_85 ) ;
return - V_78 ;
}
while ( V_77 != V_199 ) {
if ( F_113 ( & V_198 -> V_201 , V_77 ) )
break;
if ( F_68 () ) {
V_200 = 1 ;
break;
}
V_66 = F_44 ( V_2 ) ;
if ( NULL == V_66 ) {
V_2 -> V_106 ++ ;
V_200 = 1 ;
break;
}
switch ( V_2 -> V_19 -> V_206 ) {
case V_207 :
memcpy ( & V_67 , F_114 ( & V_198 -> V_208 , V_77 ) , sizeof( V_67 ) ) ;
break;
case V_209 :
F_115 ( & V_67 , F_114 ( & V_198 -> V_210 , V_77 ) ) ;
break;
case V_211 :
F_116 ( & V_67 , F_114 ( & V_198 -> V_212 , V_77 ) ) ;
break;
default:
F_117 () ;
}
V_198 -> V_201 . V_202 = ++ V_77 ;
F_118 () ;
switch ( V_67 . V_75 ) {
case V_155 :
case V_213 :
case V_192 :
case V_190 :
case V_214 :
if ( F_119 ( V_2 , & V_67 , V_66 ) )
goto V_136;
break;
case V_215 :
F_46 ( V_2 , V_66 ) ;
if ( F_99 ( V_2 , & V_67 ) )
goto V_136;
break;
default:
if ( F_101 ( V_2 , & V_67 , V_66 ) )
goto V_136;
break;
}
F_120 () ;
}
V_136:
return V_200 ;
}
static int
F_72 ( struct V_1 * V_2 )
{
union V_197 * V_198 = & V_2 -> V_198 ;
int V_200 ;
do {
V_200 = F_110 ( V_2 ) ;
if ( V_200 )
break;
F_121 ( & V_198 -> V_201 , V_200 ) ;
} while ( V_200 );
return V_200 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_156 * V_67 ,
struct V_66 * V_66 )
{
struct V_74 V_159 ;
struct V_157 * V_158 = V_66 -> V_158 ;
unsigned int V_162 ;
struct V_194 * V_194 = NULL ;
struct V_194 * * V_216 = V_66 -> V_216 ;
int V_10 , V_217 = 0 ;
int V_75 ;
int V_218 = 0 ;
struct V_219 V_220 ;
bool V_131 = false ;
struct V_124 * * V_42 = V_66 -> V_134 ;
unsigned short V_221 ;
V_221 = V_67 -> V_75 == V_214 ?
V_67 -> V_165 . V_166 . V_222 : V_67 -> V_75 ;
if ( ( V_67 -> V_75 == V_214 ) &&
( V_221 != V_155 ) &&
( V_221 != V_213 ) ) {
F_42 ( L_32 , V_221 ) ;
goto V_179;
}
switch ( V_221 ) {
case V_155 :
V_2 -> V_107 ++ ;
V_75 = V_79 ;
break;
case V_213 :
V_2 -> V_108 ++ ;
V_75 = V_178 ;
V_218 = V_223 | V_224 ;
break;
case V_192 :
V_131 = true ;
case V_190 :
V_2 -> V_109 ++ ;
V_75 = V_178 ;
V_218 = V_225 ;
break;
default:
V_75 = 0 ;
goto V_179;
break;
}
V_162 = V_67 -> V_75 == V_214 ?
V_67 -> V_165 . V_166 . V_226 : V_67 -> V_165 . V_227 . V_226 ;
if ( F_50 ( V_162 == 0 && V_218 != V_225 ) ||
F_50 ( ( V_67 -> V_75 != V_214 ) &&
( V_162 > V_41 ) ) ||
F_50 ( ( V_67 -> V_75 == V_214 ) &&
( V_162 > V_228 ) ) ) {
F_42 ( L_33 , V_162 ) ;
goto V_179;
}
V_159 . V_81 = 0 ;
V_66 -> V_2 = V_2 ;
V_66 -> V_128 = V_67 -> V_165 . V_227 . V_128 ;
V_66 -> V_75 = V_221 ;
V_66 -> V_129 = V_173 ;
V_66 -> V_135 = V_162 ;
if ( V_67 -> V_75 != V_214 ) {
V_159 . V_84 = V_67 -> V_165 . V_227 . V_49 ;
V_159 . V_83 = V_67 -> V_165 . V_227 . V_83 ;
for ( V_10 = 0 ; V_10 < V_162 ; V_10 ++ ) {
V_42 [ V_10 ] -> V_34 = V_67 -> V_165 . V_227 . V_158 [ V_10 ] . V_34 ;
V_158 [ V_10 ] . V_171 = V_67 -> V_165 . V_227 . V_158 [ V_10 ] . V_168 -
V_67 -> V_165 . V_227 . V_158 [ V_10 ] . V_167 + 1 ;
V_158 [ V_10 ] . V_172 = ( V_67 -> V_165 . V_227 . V_158 [ V_10 ] . V_167 << 9 ) ;
if ( ( V_67 -> V_165 . V_227 . V_158 [ V_10 ] . V_168 >= ( V_170 >> 9 ) ) ||
( V_67 -> V_165 . V_227 . V_158 [ V_10 ] . V_168 <
V_67 -> V_165 . V_227 . V_158 [ V_10 ] . V_167 ) )
goto V_179;
V_159 . V_81 += V_158 [ V_10 ] . V_171 ;
}
} else {
V_159 . V_84 = V_67 -> V_165 . V_166 . V_49 ;
V_159 . V_83 = V_67 -> V_165 . V_166 . V_83 ;
if ( F_94 ( V_67 , V_66 , V_158 , & V_159 ) )
goto V_179;
}
if ( F_48 ( & V_159 , V_2 -> V_19 , V_75 ) != 0 ) {
F_42 ( L_34 ,
V_75 == V_79 ? L_35 : L_36 ,
V_159 . V_83 ,
V_159 . V_83 + V_159 . V_81 ,
V_2 -> V_19 -> V_22 . V_85 ) ;
goto V_179;
}
for ( V_10 = 0 ; V_10 < V_162 ; V_10 ++ ) {
if ( ( ( int ) V_159 . V_83 | ( int ) V_158 [ V_10 ] . V_171 ) &
( ( F_122 ( V_159 . V_86 ) >> 9 ) - 1 ) ) {
F_42 ( L_37 ,
V_2 -> V_19 -> V_93 ) ;
goto V_179;
}
}
if ( V_131 )
F_102 ( V_66 -> V_2 ) ;
if ( F_93 ( V_66 ) )
goto V_229;
F_66 ( V_2 -> V_19 ) ;
F_20 ( & V_2 -> V_130 ) ;
for ( V_10 = 0 ; V_10 < V_162 ; V_10 ++ ) {
while ( ( V_194 == NULL ) ||
( F_123 ( V_194 ,
V_42 [ V_10 ] -> V_3 ,
V_158 [ V_10 ] . V_171 << 9 ,
V_158 [ V_10 ] . V_172 ) == 0 ) ) {
int V_230 = F_124 ( int , ( V_162 - V_10 ) , V_231 ) ;
V_194 = F_125 ( V_151 , V_230 ) ;
if ( F_50 ( V_194 == NULL ) )
goto V_232;
V_216 [ V_217 ++ ] = V_194 ;
V_194 -> V_233 = V_159 . V_86 ;
V_194 -> V_195 = V_66 ;
V_194 -> V_234 = F_108 ;
V_194 -> V_235 . V_236 = V_159 . V_83 ;
F_126 ( V_194 , V_75 , V_218 ) ;
}
V_159 . V_83 += V_158 [ V_10 ] . V_171 ;
}
if ( ! V_194 ) {
F_4 ( V_218 != V_225 ) ;
V_194 = F_125 ( V_151 , 0 ) ;
if ( F_50 ( V_194 == NULL ) )
goto V_232;
V_216 [ V_217 ++ ] = V_194 ;
V_194 -> V_233 = V_159 . V_86 ;
V_194 -> V_195 = V_66 ;
V_194 -> V_234 = F_108 ;
F_126 ( V_194 , V_75 , V_218 ) ;
}
F_103 ( & V_66 -> V_193 , V_217 ) ;
F_127 ( & V_220 ) ;
for ( V_10 = 0 ; V_10 < V_217 ; V_10 ++ )
F_128 ( V_216 [ V_10 ] ) ;
F_129 ( & V_220 ) ;
if ( V_75 == V_79 )
V_2 -> V_237 += V_159 . V_81 ;
else if ( V_75 == V_178 )
V_2 -> V_238 += V_159 . V_81 ;
return 0 ;
V_229:
F_86 ( V_2 , V_66 -> V_134 ,
V_66 -> V_135 ) ;
V_179:
F_81 ( V_2 , V_67 -> V_165 . V_227 . V_128 , V_221 , V_186 ) ;
F_46 ( V_2 , V_66 ) ;
F_130 ( 1 ) ;
return - V_188 ;
V_232:
for ( V_10 = 0 ; V_10 < V_217 ; V_10 ++ )
F_109 ( V_216 [ V_10 ] ) ;
F_103 ( & V_66 -> V_193 , 1 ) ;
F_105 ( V_66 , - V_30 ) ;
F_130 ( 1 ) ;
return - V_188 ;
}
static void F_81 ( struct V_1 * V_2 , T_8 V_128 ,
unsigned short V_239 , int V_240 )
{
struct V_241 V_242 ;
unsigned long V_4 ;
union V_197 * V_198 ;
int V_243 ;
V_242 . V_128 = V_128 ;
V_242 . V_75 = V_239 ;
V_242 . V_129 = V_240 ;
F_2 ( & V_2 -> V_244 , V_4 ) ;
V_198 = & V_2 -> V_198 ;
switch ( V_2 -> V_19 -> V_206 ) {
case V_207 :
memcpy ( F_131 ( & V_198 -> V_208 , V_198 -> V_208 . V_205 ) ,
& V_242 , sizeof( V_242 ) ) ;
break;
case V_209 :
memcpy ( F_131 ( & V_198 -> V_210 , V_198 -> V_210 . V_205 ) ,
& V_242 , sizeof( V_242 ) ) ;
break;
case V_211 :
memcpy ( F_131 ( & V_198 -> V_212 , V_198 -> V_212 . V_205 ) ,
& V_242 , sizeof( V_242 ) ) ;
break;
default:
F_117 () ;
}
V_198 -> V_201 . V_205 ++ ;
F_132 ( & V_198 -> V_201 , V_243 ) ;
F_5 ( & V_2 -> V_244 , V_4 ) ;
if ( V_243 )
F_133 ( V_2 -> V_101 ) ;
}
static int T_9 F_134 ( void )
{
int V_77 = 0 ;
if ( ! F_135 () )
return - V_245 ;
if ( V_246 > V_247 ) {
F_54 ( L_38 ,
V_246 , V_247 ) ;
V_246 = V_247 ;
}
if ( V_248 == 0 )
V_248 = F_136 () ;
V_77 = F_137 () ;
if ( V_77 )
goto V_249;
V_77 = F_138 () ;
if ( V_77 )
goto V_249;
V_249:
return V_77 ;
}
