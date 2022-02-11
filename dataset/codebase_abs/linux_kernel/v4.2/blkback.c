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
if ( V_2 -> V_18 >= V_19 ) {
if ( ! V_2 -> V_20 . V_21 )
V_2 -> V_20 . V_21 = 1 ;
return - V_22 ;
}
V_15 = & V_2 -> V_23 . V_14 ;
while ( * V_15 ) {
V_17 = F_14 ( * V_15 , struct V_13 , V_24 ) ;
V_16 = * V_15 ;
if ( V_13 -> V_25 < V_17 -> V_25 )
V_15 = & ( ( * V_15 ) -> V_26 ) ;
else if ( V_13 -> V_25 > V_17 -> V_25 )
V_15 = & ( ( * V_15 ) -> V_27 ) ;
else {
F_15 ( L_1 ) ;
return - V_28 ;
}
}
F_16 ( V_13 -> V_4 , V_29 ) ;
F_17 ( V_30 , V_13 -> V_4 ) ;
F_18 ( & ( V_13 -> V_24 ) , V_16 , V_15 ) ;
F_19 ( & ( V_13 -> V_24 ) , & V_2 -> V_23 ) ;
V_2 -> V_18 ++ ;
F_20 ( & V_2 -> V_31 ) ;
return 0 ;
}
static struct V_13 * F_21 ( struct V_1 * V_2 ,
T_1 V_32 )
{
struct V_13 * V_33 ;
struct V_14 * V_24 = NULL ;
V_24 = V_2 -> V_23 . V_14 ;
while ( V_24 ) {
V_33 = F_14 ( V_24 , struct V_13 , V_24 ) ;
if ( V_32 < V_33 -> V_25 )
V_24 = V_24 -> V_26 ;
else if ( V_32 > V_33 -> V_25 )
V_24 = V_24 -> V_27 ;
else {
if( F_22 ( V_30 , V_33 -> V_4 ) ) {
F_15 ( L_2 ) ;
return NULL ;
}
F_17 ( V_30 , V_33 -> V_4 ) ;
F_20 ( & V_2 -> V_31 ) ;
return V_33 ;
}
}
return NULL ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
if( ! F_22 ( V_30 , V_13 -> V_4 ) )
F_15 ( L_3 ) ;
F_17 ( V_34 , V_13 -> V_4 ) ;
F_24 ( V_30 , V_13 -> V_4 ) ;
F_25 ( & V_2 -> V_31 ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_35 * V_36 ,
unsigned int V_9 )
{
struct V_37 V_38 [ V_39 ] ;
struct V_3 * V_40 [ V_39 ] ;
struct V_13 * V_13 ;
struct V_14 * V_41 ;
int V_42 = 0 ;
struct V_43 V_44 ;
V_44 . V_40 = V_40 ;
V_44 . V_45 = V_38 ;
V_44 . V_46 = NULL ;
F_27 (persistent_gnt, n, root, node) {
F_4 ( V_13 -> V_47 ==
V_48 ) ;
F_28 ( & V_38 [ V_42 ] ,
( unsigned long ) F_29 ( F_30 (
V_13 -> V_3 ) ) ,
V_49 ,
V_13 -> V_47 ) ;
V_40 [ V_42 ] = V_13 -> V_3 ;
if ( ++ V_42 == V_39 ||
! F_31 ( & V_13 -> V_24 ) ) {
V_44 . V_50 = V_42 ;
F_4 ( F_32 ( & V_44 ) ) ;
F_9 ( V_2 , V_40 , V_42 ) ;
V_42 = 0 ;
}
F_33 ( & V_13 -> V_24 , V_36 ) ;
F_34 ( V_13 ) ;
V_9 -- ;
}
F_4 ( V_9 != 0 ) ;
}
void F_35 ( struct V_51 * V_52 )
{
struct V_37 V_38 [ V_39 ] ;
struct V_3 * V_40 [ V_39 ] ;
struct V_13 * V_13 ;
int V_42 = 0 ;
struct V_1 * V_2 = F_14 ( V_52 , F_36 ( * V_2 ) , V_53 ) ;
struct V_43 V_44 ;
V_44 . V_40 = V_40 ;
V_44 . V_45 = V_38 ;
V_44 . V_46 = NULL ;
while( ! F_3 ( & V_2 -> V_54 ) ) {
V_13 = F_7 ( & V_2 -> V_54 ,
struct V_13 ,
V_55 ) ;
F_8 ( & V_13 -> V_55 ) ;
F_28 ( & V_38 [ V_42 ] ,
F_37 ( V_13 -> V_3 ) ,
V_49 ,
V_13 -> V_47 ) ;
V_40 [ V_42 ] = V_13 -> V_3 ;
if ( ++ V_42 == V_39 ) {
V_44 . V_50 = V_42 ;
F_4 ( F_32 ( & V_44 ) ) ;
F_9 ( V_2 , V_40 , V_42 ) ;
V_42 = 0 ;
}
F_34 ( V_13 ) ;
}
if ( V_42 > 0 ) {
V_44 . V_50 = V_42 ;
F_4 ( F_32 ( & V_44 ) ) ;
F_9 ( V_2 , V_40 , V_42 ) ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_13 ;
struct V_14 * V_41 ;
unsigned int V_56 , V_57 ;
bool V_58 = false , V_59 = false ;
struct V_35 * V_36 ;
if ( V_2 -> V_18 < V_19 ||
( V_2 -> V_18 == V_19 &&
! V_2 -> V_20 . V_21 ) ) {
return;
}
if ( F_39 ( & V_2 -> V_53 ) ) {
F_15 ( L_4 ) ;
return;
}
V_56 = ( V_19 / 100 ) * V_60 ;
V_56 = V_2 -> V_18 - V_19 + V_56 ;
V_56 = F_40 ( V_2 -> V_18 , V_56 ) ;
if ( ( V_56 == 0 ) ||
( V_56 > ( V_2 -> V_18 - F_41 ( & V_2 -> V_31 ) ) ) )
return;
V_57 = V_56 ;
F_42 ( L_5 , V_56 ) ;
F_4 ( ! F_3 ( & V_2 -> V_54 ) ) ;
V_36 = & V_2 -> V_23 ;
V_61:
F_27 (persistent_gnt, n, root, node) {
F_4 ( V_13 -> V_47 ==
V_48 ) ;
if ( V_59 ) {
F_24 ( V_34 , V_13 -> V_4 ) ;
continue;
}
if ( F_22 ( V_30 , V_13 -> V_4 ) )
continue;
if ( ! V_58 &&
( F_22 ( V_34 , V_13 -> V_4 ) ) )
continue;
F_33 ( & V_13 -> V_24 , V_36 ) ;
F_10 ( & V_13 -> V_55 ,
& V_2 -> V_54 ) ;
if ( -- V_56 == 0 )
goto V_62;
}
if ( ! V_58 && ! V_59 ) {
F_42 ( L_6 , V_56 ) ;
V_58 = true ;
goto V_61;
}
V_62:
if ( ! V_59 ) {
F_42 ( L_7 ) ;
V_59 = true ;
goto V_61;
}
V_2 -> V_18 -= ( V_57 - V_56 ) ;
V_2 -> V_20 . V_21 = 0 ;
F_43 ( & V_2 -> V_53 ) ;
F_42 ( L_8 , ( V_57 - V_56 ) , V_57 ) ;
return;
}
static struct V_63 * F_44 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = NULL ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_65 , V_4 ) ;
if ( ! F_3 ( & V_2 -> V_66 ) ) {
V_64 = F_45 ( V_2 -> V_66 . V_67 , struct V_63 ,
V_68 ) ;
F_8 ( & V_64 -> V_68 ) ;
}
F_5 ( & V_2 -> V_65 , V_4 ) ;
return V_64 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
unsigned long V_4 ;
int V_69 ;
F_2 ( & V_2 -> V_65 , V_4 ) ;
V_69 = F_3 ( & V_2 -> V_66 ) ;
F_10 ( & V_64 -> V_68 , & V_2 -> V_66 ) ;
F_5 ( & V_2 -> V_65 , V_4 ) ;
if ( V_69 )
F_47 ( & V_2 -> V_70 ) ;
}
static int F_48 ( struct V_71 * V_64 , struct V_1 * V_2 ,
int V_72 )
{
struct V_73 * V_20 = & V_2 -> V_20 ;
int V_74 = - V_75 ;
if ( ( V_72 != V_76 ) && V_20 -> V_77 )
goto V_78;
if ( F_49 ( V_64 -> V_79 ) ) {
T_2 V_80 = V_64 -> V_81 + V_64 -> V_79 ;
if ( F_50 ( V_80 < V_64 -> V_81 ) )
goto V_78;
if ( F_50 ( V_80 > F_51 ( V_20 ) ) )
goto V_78;
}
V_64 -> V_82 = V_20 -> V_83 ;
V_64 -> V_84 = V_20 -> V_84 ;
V_74 = 0 ;
V_78:
return V_74 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_73 * V_20 = & V_2 -> V_20 ;
struct V_85 V_86 ;
int V_87 ;
struct V_88 * V_82 = F_53 ( V_2 -> V_89 ) ;
unsigned long long V_90 = F_51 ( V_20 ) ;
F_54 ( L_9 ,
V_2 -> V_91 , F_55 ( V_20 -> V_83 ) , F_56 ( V_20 -> V_83 ) ) ;
F_54 ( L_10 , V_90 ) ;
V_20 -> V_92 = V_90 ;
V_93:
V_87 = F_57 ( & V_86 ) ;
if ( V_87 ) {
F_58 ( L_11 ) ;
return;
}
V_87 = F_59 ( V_86 , V_82 -> V_94 , L_12 , L_13 ,
( unsigned long long ) F_51 ( V_20 ) ) ;
if ( V_87 ) {
F_58 ( L_14 ) ;
goto abort;
}
V_87 = F_59 ( V_86 , V_82 -> V_94 , L_15 , L_16 , V_82 -> V_95 ) ;
if ( V_87 ) {
F_58 ( L_17 ) ;
goto abort;
}
V_87 = F_60 ( V_86 , 0 ) ;
if ( V_87 == - V_96 )
goto V_93;
if ( V_87 )
F_58 ( L_18 ) ;
return;
abort:
F_60 ( V_86 , 1 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
V_2 -> V_97 = 1 ;
F_47 ( & V_2 -> V_98 ) ;
}
T_3 F_62 ( int V_99 , void * V_100 )
{
F_61 ( V_100 ) ;
return V_101 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_54 ( L_19
L_20 ,
V_102 -> V_103 , V_2 -> V_104 ,
V_2 -> V_105 , V_2 -> V_106 ,
V_2 -> V_107 , V_2 -> V_108 ,
V_2 -> V_18 ,
V_19 ) ;
V_2 -> V_109 = V_110 + F_64 ( 10 * 1000 ) ;
V_2 -> V_105 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_104 = 0 ;
V_2 -> V_108 = 0 ;
}
int F_65 ( void * V_111 )
{
struct V_1 * V_2 = V_111 ;
struct V_73 * V_20 = & V_2 -> V_20 ;
unsigned long V_112 ;
int V_113 ;
F_66 ( V_2 ) ;
while ( ! F_67 () ) {
if ( F_68 () )
continue;
if ( F_50 ( V_20 -> V_92 != F_51 ( V_20 ) ) )
F_52 ( V_2 ) ;
V_112 = F_64 ( V_114 ) ;
V_112 = F_69 (
V_2 -> V_98 ,
V_2 -> V_97 || F_67 () ,
V_112 ) ;
if ( V_112 == 0 )
goto V_115;
V_112 = F_69 (
V_2 -> V_70 ,
! F_3 ( & V_2 -> V_66 ) ||
F_67 () ,
V_112 ) ;
if ( V_112 == 0 )
goto V_115;
V_2 -> V_97 = 0 ;
F_70 () ;
V_113 = F_71 ( V_2 ) ;
if ( V_113 > 0 )
V_2 -> V_97 = 1 ;
if ( V_113 == - V_75 )
F_72 ( V_2 -> V_116 ,
F_67 () ) ;
V_115:
if ( V_2 -> V_20 . V_117 &&
F_73 ( V_110 , V_2 -> V_118 ) ) {
F_38 ( V_2 ) ;
V_2 -> V_118 = V_110 + F_64 ( V_114 ) ;
}
F_11 ( V_2 , V_119 ) ;
if ( V_120 && F_73 ( V_110 , V_2 -> V_109 ) )
F_63 ( V_2 ) ;
}
F_74 ( & V_2 -> V_53 ) ;
if ( V_120 )
F_63 ( V_2 ) ;
V_2 -> V_121 = NULL ;
F_75 ( V_2 ) ;
return 0 ;
}
void F_76 ( struct V_1 * V_2 )
{
if ( ! F_77 ( & V_2 -> V_23 ) )
F_26 ( V_2 , & V_2 -> V_23 ,
V_2 -> V_18 ) ;
F_4 ( ! F_77 ( & V_2 -> V_23 ) ) ;
V_2 -> V_18 = 0 ;
F_11 ( V_2 , 0 ) ;
}
static unsigned int F_78 (
struct V_1 * V_2 ,
struct V_122 * * V_40 ,
unsigned int V_9 ,
struct V_37 * V_45 ,
struct V_3 * * V_123 )
{
unsigned int V_10 , V_124 = 0 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
if ( V_40 [ V_10 ] -> V_13 != NULL ) {
F_23 ( V_2 , V_40 [ V_10 ] -> V_13 ) ;
continue;
}
if ( V_40 [ V_10 ] -> V_47 == V_48 )
continue;
V_123 [ V_124 ] = V_40 [ V_10 ] -> V_3 ;
F_28 ( & V_45 [ V_124 ] , F_37 ( V_40 [ V_10 ] -> V_3 ) ,
V_49 , V_40 [ V_10 ] -> V_47 ) ;
V_40 [ V_10 ] -> V_47 = V_48 ;
V_124 ++ ;
}
return V_124 ;
}
static void F_79 ( int V_125 , struct V_43 * V_33 )
{
struct V_63 * V_63 = (struct V_63 * ) ( V_33 -> V_33 ) ;
struct V_1 * V_2 = V_63 -> V_2 ;
F_4 ( V_125 ) ;
F_9 ( V_2 , V_33 -> V_40 , V_33 -> V_50 ) ;
F_80 ( V_2 , V_63 -> V_126 ,
V_63 -> V_72 , V_63 -> V_127 ) ;
F_46 ( V_2 , V_63 ) ;
if ( F_81 ( & V_2 -> V_128 ) && F_41 ( & V_2 -> V_129 ) ) {
F_82 ( & V_2 -> V_130 ) ;
}
F_75 ( V_2 ) ;
}
static void F_83 ( struct V_63 * V_64 )
{
struct V_43 * V_52 = & V_64 -> V_131 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_122 * * V_40 = V_64 -> V_132 ;
unsigned int V_124 ;
V_124 = F_78 ( V_2 , V_40 , V_64 -> V_133 ,
V_64 -> V_38 , V_64 -> V_123 ) ;
V_52 -> V_33 = V_64 ;
V_52 -> V_134 = F_79 ;
V_52 -> V_45 = V_64 -> V_38 ;
V_52 -> V_46 = NULL ;
V_52 -> V_40 = V_64 -> V_123 ;
V_52 -> V_50 = V_124 ;
F_84 ( & V_64 -> V_131 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_122 * V_40 [] ,
int V_9 )
{
struct V_37 V_38 [ V_39 ] ;
struct V_3 * V_123 [ V_39 ] ;
unsigned int V_124 = 0 ;
int V_113 ;
while ( V_9 ) {
unsigned int V_135 = F_40 ( V_9 , V_39 ) ;
V_124 = F_78 ( V_2 , V_40 , V_135 ,
V_38 , V_123 ) ;
if ( V_124 ) {
V_113 = F_86 ( V_38 , NULL , V_123 , V_124 ) ;
F_4 ( V_113 ) ;
F_9 ( V_2 , V_123 , V_124 ) ;
}
V_40 += V_135 ;
V_9 -= V_135 ;
}
}
static int F_87 ( struct V_1 * V_2 ,
struct V_122 * V_40 [] ,
int V_9 , bool V_136 )
{
struct V_137 V_138 [ V_39 ] ;
struct V_3 * V_139 [ V_39 ] ;
struct V_13 * V_13 = NULL ;
T_4 V_140 = 0 ;
int V_10 , V_141 , V_142 ;
int V_143 = 0 ;
int V_113 = 0 ;
int V_144 = 0 , V_145 = 0 ;
int V_146 ;
V_146 = ( V_2 -> V_20 . V_117 ) ;
V_93:
for ( V_10 = V_145 ; V_10 < V_9 ; V_10 ++ ) {
T_5 V_4 ;
if ( V_146 )
V_13 = F_21 (
V_2 ,
V_40 [ V_10 ] -> V_32 ) ;
if ( V_13 ) {
V_40 [ V_10 ] -> V_3 = V_13 -> V_3 ;
V_40 [ V_10 ] -> V_13 = V_13 ;
} else {
if ( F_1 ( V_2 , & V_40 [ V_10 ] -> V_3 ) )
goto V_147;
V_140 = F_37 ( V_40 [ V_10 ] -> V_3 ) ;
V_139 [ V_143 ] = V_40 [ V_10 ] -> V_3 ;
V_40 [ V_10 ] -> V_13 = NULL ;
V_4 = V_49 ;
if ( ! V_146 && V_136 )
V_4 |= V_148 ;
F_88 ( & V_138 [ V_143 ++ ] , V_140 ,
V_4 , V_40 [ V_10 ] -> V_32 ,
V_2 -> V_91 ) ;
}
V_145 = V_10 + 1 ;
if ( V_143 == V_39 )
break;
}
if ( V_143 ) {
V_113 = F_89 ( V_138 , NULL , V_139 , V_143 ) ;
F_4 ( V_113 ) ;
}
for ( V_141 = V_144 , V_142 = 0 ; V_141 < V_145 ; V_141 ++ ) {
if ( ! V_40 [ V_141 ] -> V_13 ) {
F_4 ( V_142 >= V_143 ) ;
if ( F_50 ( V_138 [ V_142 ] . V_127 != 0 ) ) {
F_42 ( L_21 ) ;
F_9 ( V_2 , & V_40 [ V_141 ] -> V_3 , 1 ) ;
V_40 [ V_141 ] -> V_47 = V_48 ;
V_113 |= 1 ;
goto V_67;
}
V_40 [ V_141 ] -> V_47 = V_138 [ V_142 ] . V_47 ;
} else {
continue;
}
if ( V_146 &&
V_2 -> V_18 < V_19 ) {
V_13 = F_90 ( sizeof( struct V_13 ) ,
V_149 ) ;
if ( ! V_13 ) {
goto V_67;
}
V_13 -> V_25 = V_138 [ V_142 ] . V_150 ;
V_13 -> V_47 = V_138 [ V_142 ] . V_47 ;
V_13 -> V_3 = V_40 [ V_141 ] -> V_3 ;
if ( F_13 ( V_2 ,
V_13 ) ) {
F_34 ( V_13 ) ;
V_13 = NULL ;
goto V_67;
}
V_40 [ V_141 ] -> V_13 = V_13 ;
F_42 ( L_22 ,
V_13 -> V_25 , V_2 -> V_18 ,
V_19 ) ;
goto V_67;
}
if ( V_146 && ! V_2 -> V_20 . V_21 ) {
V_2 -> V_20 . V_21 = 1 ;
F_42 ( L_23 ,
V_2 -> V_91 , V_2 -> V_20 . V_47 ) ;
}
V_67:
V_142 ++ ;
}
V_143 = 0 ;
V_144 = V_145 ;
if ( V_145 != V_9 )
goto V_93;
return V_113 ;
V_147:
F_91 ( L_24 , V_151 ) ;
F_9 ( V_2 , V_139 , V_143 ) ;
return - V_152 ;
}
static int F_92 ( struct V_63 * V_63 )
{
int V_74 ;
V_74 = F_87 ( V_63 -> V_2 , V_63 -> V_132 ,
V_63 -> V_133 ,
( V_63 -> V_72 != V_153 ) ) ;
return V_74 ;
}
static int F_93 ( struct V_154 * V_64 ,
struct V_63 * V_63 ,
struct V_155 V_156 [] ,
struct V_71 * V_157 )
{
struct V_122 * * V_40 = V_63 -> V_158 ;
struct V_1 * V_2 = V_63 -> V_2 ;
int V_159 , V_74 , V_41 , V_160 , V_10 ;
struct V_161 * V_132 = NULL ;
V_160 = V_63 -> V_133 ;
V_159 = F_94 ( V_160 ) ;
F_4 ( V_159 > V_162 ) ;
for ( V_10 = 0 ; V_10 < V_159 ; V_10 ++ )
V_40 [ V_10 ] -> V_32 = V_64 -> V_163 . V_164 . V_159 [ V_10 ] ;
V_74 = F_87 ( V_2 , V_40 , V_159 , true ) ;
if ( V_74 )
goto V_38;
for ( V_41 = 0 , V_10 = 0 ; V_41 < V_160 ; V_41 ++ ) {
if ( ( V_41 % V_165 ) == 0 ) {
if ( V_132 )
F_95 ( V_132 ) ;
V_132 = F_96 ( V_40 [ V_41 / V_165 ] -> V_3 ) ;
}
V_10 = V_41 % V_165 ;
V_63 -> V_132 [ V_41 ] -> V_32 = V_132 [ V_10 ] . V_32 ;
V_156 [ V_41 ] . V_166 = V_132 [ V_10 ] . V_167 -
V_132 [ V_10 ] . V_168 + 1 ;
V_156 [ V_41 ] . V_169 = ( V_132 [ V_10 ] . V_168 << 9 ) ;
if ( ( V_132 [ V_10 ] . V_167 >= ( V_170 >> 9 ) ) ||
( V_132 [ V_10 ] . V_167 < V_132 [ V_10 ] . V_168 ) ) {
V_74 = - V_28 ;
goto V_38;
}
V_157 -> V_79 += V_156 [ V_41 ] . V_166 ;
}
V_38:
if ( V_132 )
F_95 ( V_132 ) ;
F_85 ( V_2 , V_40 , V_159 ) ;
return V_74 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_154 * V_64 )
{
int V_87 = 0 ;
int V_127 = V_171 ;
struct V_172 * V_84 = V_2 -> V_20 . V_84 ;
unsigned long V_173 ;
struct V_71 V_157 ;
F_66 ( V_2 ) ;
V_157 . V_81 = V_64 -> V_163 . V_174 . V_81 ;
V_157 . V_79 = V_64 -> V_163 . V_174 . V_175 ;
V_87 = F_48 ( & V_157 , V_2 , V_176 ) ;
if ( V_87 ) {
F_58 ( L_25 ,
V_157 . V_81 ,
V_157 . V_81 + V_157 . V_79 , V_2 -> V_20 . V_83 ) ;
goto V_177;
}
V_2 -> V_108 ++ ;
V_173 = ( V_2 -> V_20 . V_178 &&
( V_64 -> V_163 . V_174 . V_179 & V_180 ) ) ?
V_181 : 0 ;
V_87 = F_98 ( V_84 , V_64 -> V_163 . V_174 . V_81 ,
V_64 -> V_163 . V_174 . V_175 ,
V_149 , V_173 ) ;
V_177:
if ( V_87 == - V_182 ) {
F_42 ( L_26 ) ;
V_127 = V_183 ;
} else if ( V_87 )
V_127 = V_184 ;
F_80 ( V_2 , V_64 -> V_163 . V_174 . V_126 , V_64 -> V_72 , V_127 ) ;
F_75 ( V_2 ) ;
return V_87 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_154 * V_64 ,
struct V_63 * V_63 )
{
F_46 ( V_2 , V_63 ) ;
F_80 ( V_2 , V_64 -> V_163 . V_185 . V_126 , V_64 -> V_72 ,
V_183 ) ;
return - V_186 ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_101 ( & V_2 -> V_129 , 1 ) ;
do {
if ( F_41 ( & V_2 -> V_128 ) == 0 )
break;
F_102 (
& V_2 -> V_130 , V_187 ) ;
if ( ! F_41 ( & V_2 -> V_129 ) )
break;
} while ( ! F_67 () );
F_101 ( & V_2 -> V_129 , 0 ) ;
}
static void F_103 ( struct V_63 * V_63 , int error )
{
if ( ( V_63 -> V_72 == V_188 ) &&
( error == - V_182 ) ) {
F_42 ( L_27 ) ;
F_104 ( V_189 , V_63 -> V_2 -> V_89 , 0 ) ;
V_63 -> V_127 = V_183 ;
} else if ( ( V_63 -> V_72 == V_190 ) &&
( error == - V_182 ) ) {
F_42 ( L_28 ) ;
F_105 ( V_189 , V_63 -> V_2 -> V_89 , 0 ) ;
V_63 -> V_127 = V_183 ;
} else if ( error ) {
F_42 ( L_29
L_30 , error ) ;
V_63 -> V_127 = V_184 ;
}
if ( F_81 ( & V_63 -> V_191 ) )
F_83 ( V_63 ) ;
}
static void F_106 ( struct V_192 * V_192 , int error )
{
F_103 ( V_192 -> V_193 , error ) ;
F_107 ( V_192 ) ;
}
static int
F_108 ( struct V_1 * V_2 )
{
union V_194 * V_195 = & V_2 -> V_195 ;
struct V_154 V_64 ;
struct V_63 * V_63 ;
T_6 V_74 , V_196 ;
int V_197 = 0 ;
V_74 = V_195 -> V_198 . V_199 ;
V_196 = V_195 -> V_198 . V_200 -> V_201 ;
F_109 () ;
if ( F_110 ( & V_195 -> V_198 , V_196 ) ) {
V_74 = V_195 -> V_198 . V_202 ;
F_58 ( L_31 ,
V_196 , V_74 , V_196 - V_74 , V_2 -> V_20 . V_83 ) ;
return - V_75 ;
}
while ( V_74 != V_196 ) {
if ( F_111 ( & V_195 -> V_198 , V_74 ) )
break;
if ( F_67 () ) {
V_197 = 1 ;
break;
}
V_63 = F_44 ( V_2 ) ;
if ( NULL == V_63 ) {
V_2 -> V_104 ++ ;
V_197 = 1 ;
break;
}
switch ( V_2 -> V_203 ) {
case V_204 :
memcpy ( & V_64 , F_112 ( & V_195 -> V_205 , V_74 ) , sizeof( V_64 ) ) ;
break;
case V_206 :
F_113 ( & V_64 , F_112 ( & V_195 -> V_207 , V_74 ) ) ;
break;
case V_208 :
F_114 ( & V_64 , F_112 ( & V_195 -> V_209 , V_74 ) ) ;
break;
default:
F_115 () ;
}
V_195 -> V_198 . V_199 = ++ V_74 ;
F_116 () ;
switch ( V_64 . V_72 ) {
case V_153 :
case V_210 :
case V_190 :
case V_188 :
case V_211 :
if ( F_117 ( V_2 , & V_64 , V_63 ) )
goto V_134;
break;
case V_212 :
F_46 ( V_2 , V_63 ) ;
if ( F_97 ( V_2 , & V_64 ) )
goto V_134;
break;
default:
if ( F_99 ( V_2 , & V_64 , V_63 ) )
goto V_134;
break;
}
F_118 () ;
}
V_134:
return V_197 ;
}
static int
F_71 ( struct V_1 * V_2 )
{
union V_194 * V_195 = & V_2 -> V_195 ;
int V_197 ;
do {
V_197 = F_108 ( V_2 ) ;
if ( V_197 )
break;
F_119 ( & V_195 -> V_198 , V_197 ) ;
} while ( V_197 );
return V_197 ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_154 * V_64 ,
struct V_63 * V_63 )
{
struct V_71 V_157 ;
struct V_155 * V_156 = V_63 -> V_156 ;
unsigned int V_160 ;
struct V_192 * V_192 = NULL ;
struct V_192 * * V_213 = V_63 -> V_213 ;
int V_10 , V_214 = 0 ;
int V_72 ;
struct V_215 V_216 ;
bool V_129 = false ;
struct V_122 * * V_40 = V_63 -> V_132 ;
unsigned short V_217 ;
V_217 = V_64 -> V_72 == V_211 ?
V_64 -> V_163 . V_164 . V_218 : V_64 -> V_72 ;
if ( ( V_64 -> V_72 == V_211 ) &&
( V_217 != V_153 ) &&
( V_217 != V_210 ) ) {
F_42 ( L_32 , V_217 ) ;
goto V_177;
}
switch ( V_217 ) {
case V_153 :
V_2 -> V_105 ++ ;
V_72 = V_76 ;
break;
case V_210 :
V_2 -> V_106 ++ ;
V_72 = V_219 ;
break;
case V_190 :
V_129 = true ;
case V_188 :
V_2 -> V_107 ++ ;
V_72 = V_220 ;
break;
default:
V_72 = 0 ;
goto V_177;
break;
}
V_160 = V_64 -> V_72 == V_211 ?
V_64 -> V_163 . V_164 . V_221 : V_64 -> V_163 . V_222 . V_221 ;
if ( F_50 ( V_160 == 0 && V_72 != V_220 ) ||
F_50 ( ( V_64 -> V_72 != V_211 ) &&
( V_160 > V_39 ) ) ||
F_50 ( ( V_64 -> V_72 == V_211 ) &&
( V_160 > V_223 ) ) ) {
F_42 ( L_33 , V_160 ) ;
goto V_177;
}
V_157 . V_79 = 0 ;
V_63 -> V_2 = V_2 ;
V_63 -> V_126 = V_64 -> V_163 . V_222 . V_126 ;
V_63 -> V_72 = V_217 ;
V_63 -> V_127 = V_171 ;
V_63 -> V_133 = V_160 ;
if ( V_64 -> V_72 != V_211 ) {
V_157 . V_82 = V_64 -> V_163 . V_222 . V_47 ;
V_157 . V_81 = V_64 -> V_163 . V_222 . V_81 ;
for ( V_10 = 0 ; V_10 < V_160 ; V_10 ++ ) {
V_40 [ V_10 ] -> V_32 = V_64 -> V_163 . V_222 . V_156 [ V_10 ] . V_32 ;
V_156 [ V_10 ] . V_166 = V_64 -> V_163 . V_222 . V_156 [ V_10 ] . V_167 -
V_64 -> V_163 . V_222 . V_156 [ V_10 ] . V_168 + 1 ;
V_156 [ V_10 ] . V_169 = ( V_64 -> V_163 . V_222 . V_156 [ V_10 ] . V_168 << 9 ) ;
if ( ( V_64 -> V_163 . V_222 . V_156 [ V_10 ] . V_167 >= ( V_170 >> 9 ) ) ||
( V_64 -> V_163 . V_222 . V_156 [ V_10 ] . V_167 <
V_64 -> V_163 . V_222 . V_156 [ V_10 ] . V_168 ) )
goto V_177;
V_157 . V_79 += V_156 [ V_10 ] . V_166 ;
}
} else {
V_157 . V_82 = V_64 -> V_163 . V_164 . V_47 ;
V_157 . V_81 = V_64 -> V_163 . V_164 . V_81 ;
if ( F_93 ( V_64 , V_63 , V_156 , & V_157 ) )
goto V_177;
}
if ( F_48 ( & V_157 , V_2 , V_72 ) != 0 ) {
F_42 ( L_34 ,
V_72 == V_76 ? L_35 : L_36 ,
V_157 . V_81 ,
V_157 . V_81 + V_157 . V_79 ,
V_2 -> V_20 . V_83 ) ;
goto V_177;
}
for ( V_10 = 0 ; V_10 < V_160 ; V_10 ++ ) {
if ( ( ( int ) V_157 . V_81 | ( int ) V_156 [ V_10 ] . V_166 ) &
( ( F_120 ( V_157 . V_84 ) >> 9 ) - 1 ) ) {
F_42 ( L_37 ,
V_2 -> V_91 ) ;
goto V_177;
}
}
if ( V_129 )
F_100 ( V_63 -> V_2 ) ;
if ( F_92 ( V_63 ) )
goto V_224;
F_66 ( V_2 ) ;
F_20 ( & V_2 -> V_128 ) ;
for ( V_10 = 0 ; V_10 < V_160 ; V_10 ++ ) {
while ( ( V_192 == NULL ) ||
( F_121 ( V_192 ,
V_40 [ V_10 ] -> V_3 ,
V_156 [ V_10 ] . V_166 << 9 ,
V_156 [ V_10 ] . V_169 ) == 0 ) ) {
int V_225 = F_122 ( int , ( V_160 - V_10 ) , V_226 ) ;
V_192 = F_123 ( V_149 , V_225 ) ;
if ( F_50 ( V_192 == NULL ) )
goto V_227;
V_213 [ V_214 ++ ] = V_192 ;
V_192 -> V_228 = V_157 . V_84 ;
V_192 -> V_193 = V_63 ;
V_192 -> V_229 = F_106 ;
V_192 -> V_230 . V_231 = V_157 . V_81 ;
}
V_157 . V_81 += V_156 [ V_10 ] . V_166 ;
}
if ( ! V_192 ) {
F_4 ( V_72 != V_220 ) ;
V_192 = F_123 ( V_149 , 0 ) ;
if ( F_50 ( V_192 == NULL ) )
goto V_227;
V_213 [ V_214 ++ ] = V_192 ;
V_192 -> V_228 = V_157 . V_84 ;
V_192 -> V_193 = V_63 ;
V_192 -> V_229 = F_106 ;
}
F_101 ( & V_63 -> V_191 , V_214 ) ;
F_124 ( & V_216 ) ;
for ( V_10 = 0 ; V_10 < V_214 ; V_10 ++ )
F_125 ( V_72 , V_213 [ V_10 ] ) ;
F_126 ( & V_216 ) ;
if ( V_72 == V_76 )
V_2 -> V_232 += V_157 . V_79 ;
else if ( V_72 & V_176 )
V_2 -> V_233 += V_157 . V_79 ;
return 0 ;
V_224:
F_85 ( V_2 , V_63 -> V_132 ,
V_63 -> V_133 ) ;
V_177:
F_80 ( V_2 , V_64 -> V_163 . V_222 . V_126 , V_217 , V_184 ) ;
F_46 ( V_2 , V_63 ) ;
F_127 ( 1 ) ;
return - V_186 ;
V_227:
for ( V_10 = 0 ; V_10 < V_214 ; V_10 ++ )
F_107 ( V_213 [ V_10 ] ) ;
F_101 ( & V_63 -> V_191 , 1 ) ;
F_103 ( V_63 , - V_28 ) ;
F_127 ( 1 ) ;
return - V_186 ;
}
static void F_80 ( struct V_1 * V_2 , T_7 V_126 ,
unsigned short V_234 , int V_235 )
{
struct V_236 V_237 ;
unsigned long V_4 ;
union V_194 * V_195 = & V_2 -> V_195 ;
int V_238 ;
V_237 . V_126 = V_126 ;
V_237 . V_72 = V_234 ;
V_237 . V_127 = V_235 ;
F_2 ( & V_2 -> V_239 , V_4 ) ;
switch ( V_2 -> V_203 ) {
case V_204 :
memcpy ( F_128 ( & V_195 -> V_205 , V_195 -> V_205 . V_202 ) ,
& V_237 , sizeof( V_237 ) ) ;
break;
case V_206 :
memcpy ( F_128 ( & V_195 -> V_207 , V_195 -> V_207 . V_202 ) ,
& V_237 , sizeof( V_237 ) ) ;
break;
case V_208 :
memcpy ( F_128 ( & V_195 -> V_209 , V_195 -> V_209 . V_202 ) ,
& V_237 , sizeof( V_237 ) ) ;
break;
default:
F_115 () ;
}
V_195 -> V_198 . V_202 ++ ;
F_129 ( & V_195 -> V_198 , V_238 ) ;
F_5 ( & V_2 -> V_239 , V_4 ) ;
if ( V_238 )
F_130 ( V_2 -> V_99 ) ;
}
static int T_8 F_131 ( void )
{
int V_74 = 0 ;
if ( ! F_132 () )
return - V_240 ;
if ( V_241 > V_242 ) {
F_54 ( L_38 ,
V_241 , V_242 ) ;
V_241 = V_242 ;
}
V_74 = F_133 () ;
if ( V_74 )
goto V_243;
V_74 = F_134 () ;
if ( V_74 )
goto V_243;
V_243:
return V_74 ;
}
