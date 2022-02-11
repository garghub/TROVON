static inline int F_1 ( struct V_1 * V_2 , struct V_3 * * V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
if ( F_3 ( & V_2 -> V_6 ) ) {
F_4 ( V_2 -> V_7 != 0 ) ;
F_5 ( & V_2 -> V_5 , V_4 ) ;
return F_6 ( 1 , V_3 , false ) ;
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
F_15 ( V_28 L_1 ) ;
return - V_29 ;
}
}
F_16 ( V_13 -> V_4 , V_30 ) ;
F_17 ( V_31 , V_13 -> V_4 ) ;
F_18 ( & ( V_13 -> V_24 ) , V_16 , V_15 ) ;
F_19 ( & ( V_13 -> V_24 ) , & V_2 -> V_23 ) ;
V_2 -> V_18 ++ ;
F_20 ( & V_2 -> V_32 ) ;
return 0 ;
}
static struct V_13 * F_21 ( struct V_1 * V_2 ,
T_1 V_33 )
{
struct V_13 * V_34 ;
struct V_14 * V_24 = NULL ;
V_24 = V_2 -> V_23 . V_14 ;
while ( V_24 ) {
V_34 = F_14 ( V_24 , struct V_13 , V_24 ) ;
if ( V_33 < V_34 -> V_25 )
V_24 = V_24 -> V_26 ;
else if ( V_33 > V_34 -> V_25 )
V_24 = V_24 -> V_27 ;
else {
if( F_22 ( V_31 , V_34 -> V_4 ) ) {
F_15 ( V_28 L_2 ) ;
return NULL ;
}
F_17 ( V_31 , V_34 -> V_4 ) ;
F_20 ( & V_2 -> V_32 ) ;
return V_34 ;
}
}
return NULL ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
if( ! F_22 ( V_31 , V_13 -> V_4 ) )
F_15 ( V_28 L_3 ) ;
F_17 ( V_35 , V_13 -> V_4 ) ;
F_24 ( V_31 , V_13 -> V_4 ) ;
F_25 ( & V_2 -> V_32 ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_36 * V_37 ,
unsigned int V_9 )
{
struct V_38 V_39 [ V_40 ] ;
struct V_3 * V_41 [ V_40 ] ;
struct V_13 * V_13 ;
struct V_14 * V_42 ;
int V_43 = 0 ;
int V_44 = 0 ;
F_27 (persistent_gnt, n, root, node) {
F_4 ( V_13 -> V_45 ==
V_46 ) ;
F_28 ( & V_39 [ V_44 ] ,
( unsigned long ) F_29 ( F_30 (
V_13 -> V_3 ) ) ,
V_47 ,
V_13 -> V_45 ) ;
V_41 [ V_44 ] = V_13 -> V_3 ;
if ( ++ V_44 == V_40 ||
! F_31 ( & V_13 -> V_24 ) ) {
V_43 = F_32 ( V_39 , NULL , V_41 ,
V_44 ) ;
F_4 ( V_43 ) ;
F_9 ( V_2 , V_41 , V_44 ) ;
V_44 = 0 ;
}
F_33 ( & V_13 -> V_24 , V_37 ) ;
F_34 ( V_13 ) ;
V_9 -- ;
}
F_4 ( V_9 != 0 ) ;
}
void F_35 ( struct V_48 * V_49 )
{
struct V_38 V_39 [ V_40 ] ;
struct V_3 * V_41 [ V_40 ] ;
struct V_13 * V_13 ;
int V_43 , V_44 = 0 ;
struct V_1 * V_2 = F_14 ( V_49 , F_36 ( * V_2 ) , V_50 ) ;
while( ! F_3 ( & V_2 -> V_51 ) ) {
V_13 = F_7 ( & V_2 -> V_51 ,
struct V_13 ,
V_52 ) ;
F_8 ( & V_13 -> V_52 ) ;
F_28 ( & V_39 [ V_44 ] ,
F_37 ( V_13 -> V_3 ) ,
V_47 ,
V_13 -> V_45 ) ;
V_41 [ V_44 ] = V_13 -> V_3 ;
if ( ++ V_44 == V_40 ) {
V_43 = F_32 ( V_39 , NULL , V_41 ,
V_44 ) ;
F_4 ( V_43 ) ;
F_9 ( V_2 , V_41 , V_44 ) ;
V_44 = 0 ;
}
F_34 ( V_13 ) ;
}
if ( V_44 > 0 ) {
V_43 = F_32 ( V_39 , NULL , V_41 , V_44 ) ;
F_4 ( V_43 ) ;
F_9 ( V_2 , V_41 , V_44 ) ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_13 ;
struct V_14 * V_42 ;
unsigned int V_53 , V_54 ;
bool V_55 = false , V_56 = false ;
struct V_36 * V_37 ;
if ( V_2 -> V_18 < V_19 ||
( V_2 -> V_18 == V_19 &&
! V_2 -> V_20 . V_21 ) ) {
return;
}
if ( F_39 ( & V_2 -> V_50 ) ) {
F_15 ( V_28 L_4 ) ;
return;
}
V_53 = ( V_19 / 100 ) * V_57 ;
V_53 = V_2 -> V_18 - V_19 + V_53 ;
V_53 = F_40 ( V_2 -> V_18 , V_53 ) ;
if ( ( V_53 == 0 ) ||
( V_53 > ( V_2 -> V_18 - F_41 ( & V_2 -> V_32 ) ) ) )
return;
V_54 = V_53 ;
F_42 ( V_28 L_5 , V_53 ) ;
F_4 ( ! F_3 ( & V_2 -> V_51 ) ) ;
V_37 = & V_2 -> V_23 ;
V_58:
F_27 (persistent_gnt, n, root, node) {
F_4 ( V_13 -> V_45 ==
V_46 ) ;
if ( V_56 ) {
F_24 ( V_35 , V_13 -> V_4 ) ;
continue;
}
if ( F_22 ( V_31 , V_13 -> V_4 ) )
continue;
if ( ! V_55 &&
( F_22 ( V_35 , V_13 -> V_4 ) ) )
continue;
F_33 ( & V_13 -> V_24 , V_37 ) ;
F_10 ( & V_13 -> V_52 ,
& V_2 -> V_51 ) ;
if ( -- V_53 == 0 )
goto V_59;
}
if ( ! V_55 && ! V_56 ) {
F_42 ( V_28 L_6 , V_53 ) ;
V_55 = true ;
goto V_58;
}
V_59:
if ( ! V_56 ) {
F_42 ( V_28 L_7 ) ;
V_56 = true ;
goto V_58;
}
V_2 -> V_18 -= ( V_54 - V_53 ) ;
V_2 -> V_20 . V_21 = 0 ;
F_43 ( & V_2 -> V_50 ) ;
F_42 ( V_28 L_8 , ( V_54 - V_53 ) , V_54 ) ;
return;
}
static struct V_60 * F_44 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = NULL ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_62 , V_4 ) ;
if ( ! F_3 ( & V_2 -> V_63 ) ) {
V_61 = F_45 ( V_2 -> V_63 . V_64 , struct V_60 ,
V_65 ) ;
F_8 ( & V_61 -> V_65 ) ;
}
F_5 ( & V_2 -> V_62 , V_4 ) ;
return V_61 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
unsigned long V_4 ;
int V_66 ;
F_2 ( & V_2 -> V_62 , V_4 ) ;
V_66 = F_3 ( & V_2 -> V_63 ) ;
F_10 ( & V_61 -> V_65 , & V_2 -> V_63 ) ;
F_5 ( & V_2 -> V_62 , V_4 ) ;
if ( V_66 )
F_47 ( & V_2 -> V_67 ) ;
}
static int F_48 ( struct V_68 * V_61 , struct V_1 * V_2 ,
int V_69 )
{
struct V_70 * V_20 = & V_2 -> V_20 ;
int V_71 = - V_72 ;
if ( ( V_69 != V_73 ) && V_20 -> V_74 )
goto V_75;
if ( F_49 ( V_61 -> V_76 ) ) {
T_2 V_77 = V_61 -> V_78 + V_61 -> V_76 ;
if ( F_50 ( V_77 < V_61 -> V_78 ) )
goto V_75;
if ( F_50 ( V_77 > F_51 ( V_20 ) ) )
goto V_75;
}
V_61 -> V_79 = V_20 -> V_80 ;
V_61 -> V_81 = V_20 -> V_81 ;
V_71 = 0 ;
V_75:
return V_71 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_70 * V_20 = & V_2 -> V_20 ;
struct V_82 V_83 ;
int V_84 ;
struct V_85 * V_79 = F_53 ( V_2 -> V_86 ) ;
unsigned long long V_87 = F_51 ( V_20 ) ;
F_54 ( V_28 L_9 ,
V_2 -> V_88 , F_55 ( V_20 -> V_80 ) , F_56 ( V_20 -> V_80 ) ) ;
F_54 ( V_28 L_10 , V_87 ) ;
V_20 -> V_89 = V_87 ;
V_90:
V_84 = F_57 ( & V_83 ) ;
if ( V_84 ) {
F_58 ( V_28 L_11 ) ;
return;
}
V_84 = F_59 ( V_83 , V_79 -> V_91 , L_12 , L_13 ,
( unsigned long long ) F_51 ( V_20 ) ) ;
if ( V_84 ) {
F_58 ( V_28 L_14 ) ;
goto abort;
}
V_84 = F_59 ( V_83 , V_79 -> V_91 , L_15 , L_16 , V_79 -> V_92 ) ;
if ( V_84 ) {
F_58 ( V_28 L_17 ) ;
goto abort;
}
V_84 = F_60 ( V_83 , 0 ) ;
if ( V_84 == - V_93 )
goto V_90;
if ( V_84 )
F_58 ( V_28 L_18 ) ;
return;
abort:
F_60 ( V_83 , 1 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
V_2 -> V_94 = 1 ;
F_47 ( & V_2 -> V_95 ) ;
}
T_3 F_62 ( int V_96 , void * V_97 )
{
F_61 ( V_97 ) ;
return V_98 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_54 ( L_19
L_20 ,
V_99 -> V_100 , V_2 -> V_101 ,
V_2 -> V_102 , V_2 -> V_103 ,
V_2 -> V_104 , V_2 -> V_105 ,
V_2 -> V_18 ,
V_19 ) ;
V_2 -> V_106 = V_107 + F_64 ( 10 * 1000 ) ;
V_2 -> V_102 = 0 ;
V_2 -> V_103 = 0 ;
V_2 -> V_101 = 0 ;
V_2 -> V_105 = 0 ;
}
int F_65 ( void * V_108 )
{
struct V_1 * V_2 = V_108 ;
struct V_70 * V_20 = & V_2 -> V_20 ;
unsigned long V_109 ;
int V_43 ;
F_66 ( V_2 ) ;
while ( ! F_67 () ) {
if ( F_68 () )
continue;
if ( F_50 ( V_20 -> V_89 != F_51 ( V_20 ) ) )
F_52 ( V_2 ) ;
V_109 = F_64 ( V_110 ) ;
V_109 = F_69 (
V_2 -> V_95 ,
V_2 -> V_94 || F_67 () ,
V_109 ) ;
if ( V_109 == 0 )
goto V_111;
V_109 = F_69 (
V_2 -> V_67 ,
! F_3 ( & V_2 -> V_63 ) ||
F_67 () ,
V_109 ) ;
if ( V_109 == 0 )
goto V_111;
V_2 -> V_94 = 0 ;
F_70 () ;
V_43 = F_71 ( V_2 ) ;
if ( V_43 > 0 )
V_2 -> V_94 = 1 ;
if ( V_43 == - V_72 )
F_72 ( V_2 -> V_112 ,
F_67 () ) ;
V_111:
if ( V_2 -> V_20 . V_113 &&
F_73 ( V_107 , V_2 -> V_114 ) ) {
F_38 ( V_2 ) ;
V_2 -> V_114 = V_107 + F_64 ( V_110 ) ;
}
F_11 ( V_2 , V_115 ) ;
if ( V_116 && F_73 ( V_107 , V_2 -> V_106 ) )
F_63 ( V_2 ) ;
}
F_74 ( & V_2 -> V_50 ) ;
if ( V_116 )
F_63 ( V_2 ) ;
V_2 -> V_117 = NULL ;
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
static void F_78 ( struct V_1 * V_2 ,
struct V_118 * V_41 [] ,
int V_9 )
{
struct V_38 V_39 [ V_40 ] ;
struct V_3 * V_119 [ V_40 ] ;
unsigned int V_10 , V_120 = 0 ;
int V_43 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
if ( V_41 [ V_10 ] -> V_13 != NULL ) {
F_23 ( V_2 , V_41 [ V_10 ] -> V_13 ) ;
continue;
}
if ( V_41 [ V_10 ] -> V_45 == V_46 )
continue;
V_119 [ V_120 ] = V_41 [ V_10 ] -> V_3 ;
F_28 ( & V_39 [ V_120 ] , F_37 ( V_41 [ V_10 ] -> V_3 ) ,
V_47 , V_41 [ V_10 ] -> V_45 ) ;
V_41 [ V_10 ] -> V_45 = V_46 ;
if ( ++ V_120 == V_40 ) {
V_43 = F_32 ( V_39 , NULL , V_119 ,
V_120 ) ;
F_4 ( V_43 ) ;
F_9 ( V_2 , V_119 , V_120 ) ;
V_120 = 0 ;
}
}
if ( V_120 ) {
V_43 = F_32 ( V_39 , NULL , V_119 , V_120 ) ;
F_4 ( V_43 ) ;
F_9 ( V_2 , V_119 , V_120 ) ;
}
}
static int F_79 ( struct V_1 * V_2 ,
struct V_118 * V_41 [] ,
int V_9 , bool V_121 )
{
struct V_122 V_123 [ V_40 ] ;
struct V_3 * V_124 [ V_40 ] ;
struct V_13 * V_13 = NULL ;
T_4 V_125 = 0 ;
int V_10 , V_126 , V_127 ;
int V_128 = 0 ;
int V_43 = 0 ;
int V_129 = 0 , V_130 = 0 ;
int V_131 ;
V_131 = ( V_2 -> V_20 . V_113 ) ;
V_90:
for ( V_10 = V_130 ; V_10 < V_9 ; V_10 ++ ) {
T_5 V_4 ;
if ( V_131 )
V_13 = F_21 (
V_2 ,
V_41 [ V_10 ] -> V_33 ) ;
if ( V_13 ) {
V_41 [ V_10 ] -> V_3 = V_13 -> V_3 ;
V_41 [ V_10 ] -> V_13 = V_13 ;
} else {
if ( F_1 ( V_2 , & V_41 [ V_10 ] -> V_3 ) )
goto V_132;
V_125 = F_37 ( V_41 [ V_10 ] -> V_3 ) ;
V_124 [ V_128 ] = V_41 [ V_10 ] -> V_3 ;
V_41 [ V_10 ] -> V_13 = NULL ;
V_4 = V_47 ;
if ( ! V_131 && V_121 )
V_4 |= V_133 ;
F_80 ( & V_123 [ V_128 ++ ] , V_125 ,
V_4 , V_41 [ V_10 ] -> V_33 ,
V_2 -> V_88 ) ;
}
V_130 = V_10 + 1 ;
if ( V_128 == V_40 )
break;
}
if ( V_128 ) {
V_43 = F_81 ( V_123 , NULL , V_124 , V_128 ) ;
F_4 ( V_43 ) ;
}
for ( V_126 = V_129 , V_127 = 0 ; V_126 < V_130 ; V_126 ++ ) {
if ( ! V_41 [ V_126 ] -> V_13 ) {
F_4 ( V_127 >= V_128 ) ;
if ( F_50 ( V_123 [ V_127 ] . V_134 != 0 ) ) {
F_42 ( V_28 L_21 ) ;
V_41 [ V_126 ] -> V_45 = V_46 ;
V_43 |= 1 ;
goto V_64;
}
V_41 [ V_126 ] -> V_45 = V_123 [ V_127 ] . V_45 ;
} else {
continue;
}
if ( V_131 &&
V_2 -> V_18 < V_19 ) {
V_13 = F_82 ( sizeof( struct V_13 ) ,
V_135 ) ;
if ( ! V_13 ) {
goto V_64;
}
V_13 -> V_25 = V_123 [ V_127 ] . V_136 ;
V_13 -> V_45 = V_123 [ V_127 ] . V_45 ;
V_13 -> V_3 = V_41 [ V_126 ] -> V_3 ;
if ( F_13 ( V_2 ,
V_13 ) ) {
F_34 ( V_13 ) ;
V_13 = NULL ;
goto V_64;
}
V_41 [ V_126 ] -> V_13 = V_13 ;
F_42 ( V_28 L_22 ,
V_13 -> V_25 , V_2 -> V_18 ,
V_19 ) ;
goto V_64;
}
if ( V_131 && ! V_2 -> V_20 . V_21 ) {
V_2 -> V_20 . V_21 = 1 ;
F_42 ( V_28 L_23 ,
V_2 -> V_88 , V_2 -> V_20 . V_45 ) ;
}
V_64:
V_127 ++ ;
}
V_128 = 0 ;
V_129 = V_130 ;
if ( V_130 != V_9 )
goto V_90;
return V_43 ;
V_132:
F_83 ( V_28 L_24 , V_137 ) ;
F_9 ( V_2 , V_124 , V_128 ) ;
return - V_138 ;
}
static int F_84 ( struct V_60 * V_60 )
{
int V_71 ;
V_71 = F_79 ( V_60 -> V_2 , V_60 -> V_139 ,
V_60 -> V_140 ,
( V_60 -> V_69 != V_141 ) ) ;
return V_71 ;
}
static int F_85 ( struct V_142 * V_61 ,
struct V_60 * V_60 ,
struct V_143 V_144 [] ,
struct V_68 * V_145 )
{
struct V_118 * * V_41 = V_60 -> V_146 ;
struct V_1 * V_2 = V_60 -> V_2 ;
int V_147 , V_71 , V_42 , V_148 , V_10 ;
struct V_149 * V_139 = NULL ;
V_148 = V_60 -> V_140 ;
V_147 = F_86 ( V_148 ) ;
F_4 ( V_147 > V_150 ) ;
for ( V_10 = 0 ; V_10 < V_147 ; V_10 ++ )
V_41 [ V_10 ] -> V_33 = V_61 -> V_151 . V_152 . V_147 [ V_10 ] ;
V_71 = F_79 ( V_2 , V_41 , V_147 , true ) ;
if ( V_71 )
goto V_39;
for ( V_42 = 0 , V_10 = 0 ; V_42 < V_148 ; V_42 ++ ) {
if ( ( V_42 % V_153 ) == 0 ) {
if ( V_139 )
F_87 ( V_139 ) ;
V_139 = F_88 ( V_41 [ V_42 / V_153 ] -> V_3 ) ;
}
V_10 = V_42 % V_153 ;
V_60 -> V_139 [ V_42 ] -> V_33 = V_139 [ V_10 ] . V_33 ;
V_144 [ V_42 ] . V_154 = V_139 [ V_10 ] . V_155 -
V_139 [ V_10 ] . V_156 + 1 ;
V_144 [ V_42 ] . V_157 = ( V_139 [ V_10 ] . V_156 << 9 ) ;
if ( ( V_139 [ V_10 ] . V_155 >= ( V_158 >> 9 ) ) ||
( V_139 [ V_10 ] . V_155 < V_139 [ V_10 ] . V_156 ) ) {
V_71 = - V_29 ;
goto V_39;
}
V_145 -> V_76 += V_144 [ V_42 ] . V_154 ;
}
V_39:
if ( V_139 )
F_87 ( V_139 ) ;
F_78 ( V_2 , V_41 , V_147 ) ;
return V_71 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_142 * V_61 )
{
int V_84 = 0 ;
int V_134 = V_159 ;
struct V_160 * V_81 = V_2 -> V_20 . V_81 ;
unsigned long V_161 ;
struct V_68 V_145 ;
F_66 ( V_2 ) ;
V_145 . V_78 = V_61 -> V_151 . V_162 . V_78 ;
V_145 . V_76 = V_61 -> V_151 . V_162 . V_163 ;
V_84 = F_48 ( & V_145 , V_2 , V_164 ) ;
if ( V_84 ) {
F_58 ( V_28 L_25 ,
V_145 . V_78 ,
V_145 . V_78 + V_145 . V_76 , V_2 -> V_20 . V_80 ) ;
goto V_165;
}
V_2 -> V_105 ++ ;
V_161 = ( V_2 -> V_20 . V_166 &&
( V_61 -> V_151 . V_162 . V_167 & V_168 ) ) ?
V_169 : 0 ;
V_84 = F_90 ( V_81 , V_61 -> V_151 . V_162 . V_78 ,
V_61 -> V_151 . V_162 . V_163 ,
V_135 , V_161 ) ;
V_165:
if ( V_84 == - V_170 ) {
F_42 ( V_28 L_26 ) ;
V_134 = V_171 ;
} else if ( V_84 )
V_134 = V_172 ;
F_91 ( V_2 , V_61 -> V_151 . V_162 . V_173 , V_61 -> V_69 , V_134 ) ;
F_75 ( V_2 ) ;
return V_84 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_142 * V_61 ,
struct V_60 * V_60 )
{
F_46 ( V_2 , V_60 ) ;
F_91 ( V_2 , V_61 -> V_151 . V_174 . V_173 , V_61 -> V_69 ,
V_171 ) ;
return - V_175 ;
}
static void F_93 ( struct V_1 * V_2 )
{
F_94 ( & V_2 -> V_176 , 1 ) ;
do {
if ( F_41 ( & V_2 -> V_177 ) == 0 )
break;
F_95 (
& V_2 -> V_178 , V_179 ) ;
if ( ! F_41 ( & V_2 -> V_176 ) )
break;
} while ( ! F_67 () );
F_94 ( & V_2 -> V_176 , 0 ) ;
}
static void F_96 ( struct V_60 * V_60 , int error )
{
if ( ( V_60 -> V_69 == V_180 ) &&
( error == - V_170 ) ) {
F_42 ( V_28 L_27 ) ;
F_97 ( V_181 , V_60 -> V_2 -> V_86 , 0 ) ;
V_60 -> V_134 = V_171 ;
} else if ( ( V_60 -> V_69 == V_182 ) &&
( error == - V_170 ) ) {
F_42 ( V_28 L_28 ) ;
F_98 ( V_181 , V_60 -> V_2 -> V_86 , 0 ) ;
V_60 -> V_134 = V_171 ;
} else if ( error ) {
F_42 ( V_28 L_29
L_30 , error ) ;
V_60 -> V_134 = V_172 ;
}
if ( F_99 ( & V_60 -> V_183 ) ) {
struct V_1 * V_2 = V_60 -> V_2 ;
F_78 ( V_2 ,
V_60 -> V_139 ,
V_60 -> V_140 ) ;
F_91 ( V_2 , V_60 -> V_173 ,
V_60 -> V_69 , V_60 -> V_134 ) ;
F_46 ( V_2 , V_60 ) ;
if ( F_99 ( & V_2 -> V_177 ) && F_41 ( & V_2 -> V_176 ) ) {
F_100 ( & V_2 -> V_178 ) ;
}
F_75 ( V_2 ) ;
}
}
static void F_101 ( struct V_184 * V_184 , int error )
{
F_96 ( V_184 -> V_185 , error ) ;
F_102 ( V_184 ) ;
}
static int
F_103 ( struct V_1 * V_2 )
{
union V_186 * V_187 = & V_2 -> V_187 ;
struct V_142 V_61 ;
struct V_60 * V_60 ;
T_6 V_71 , V_188 ;
int V_189 = 0 ;
V_71 = V_187 -> V_190 . V_191 ;
V_188 = V_187 -> V_190 . V_192 -> V_193 ;
F_104 () ;
if ( F_105 ( & V_187 -> V_190 , V_188 ) ) {
V_71 = V_187 -> V_190 . V_194 ;
F_58 ( V_28 L_31 ,
V_188 , V_71 , V_188 - V_71 , V_2 -> V_20 . V_80 ) ;
return - V_72 ;
}
while ( V_71 != V_188 ) {
if ( F_106 ( & V_187 -> V_190 , V_71 ) )
break;
if ( F_67 () ) {
V_189 = 1 ;
break;
}
V_60 = F_44 ( V_2 ) ;
if ( NULL == V_60 ) {
V_2 -> V_101 ++ ;
V_189 = 1 ;
break;
}
switch ( V_2 -> V_195 ) {
case V_196 :
memcpy ( & V_61 , F_107 ( & V_187 -> V_197 , V_71 ) , sizeof( V_61 ) ) ;
break;
case V_198 :
F_108 ( & V_61 , F_107 ( & V_187 -> V_199 , V_71 ) ) ;
break;
case V_200 :
F_109 ( & V_61 , F_107 ( & V_187 -> V_201 , V_71 ) ) ;
break;
default:
F_110 () ;
}
V_187 -> V_190 . V_191 = ++ V_71 ;
F_111 () ;
switch ( V_61 . V_69 ) {
case V_141 :
case V_202 :
case V_182 :
case V_180 :
case V_203 :
if ( F_112 ( V_2 , & V_61 , V_60 ) )
goto V_204;
break;
case V_205 :
F_46 ( V_2 , V_60 ) ;
if ( F_89 ( V_2 , & V_61 ) )
goto V_204;
break;
default:
if ( F_92 ( V_2 , & V_61 , V_60 ) )
goto V_204;
break;
}
F_113 () ;
}
V_204:
return V_189 ;
}
static int
F_71 ( struct V_1 * V_2 )
{
union V_186 * V_187 = & V_2 -> V_187 ;
int V_189 ;
do {
V_189 = F_103 ( V_2 ) ;
if ( V_189 )
break;
F_114 ( & V_187 -> V_190 , V_189 ) ;
} while ( V_189 );
return V_189 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_142 * V_61 ,
struct V_60 * V_60 )
{
struct V_68 V_145 ;
struct V_143 * V_144 = V_60 -> V_144 ;
unsigned int V_148 ;
struct V_184 * V_184 = NULL ;
struct V_184 * * V_206 = V_60 -> V_206 ;
int V_10 , V_207 = 0 ;
int V_69 ;
struct V_208 V_209 ;
bool V_176 = false ;
struct V_118 * * V_41 = V_60 -> V_139 ;
unsigned short V_210 ;
V_210 = V_61 -> V_69 == V_203 ?
V_61 -> V_151 . V_152 . V_211 : V_61 -> V_69 ;
if ( ( V_61 -> V_69 == V_203 ) &&
( V_210 != V_141 ) &&
( V_210 != V_202 ) ) {
F_42 ( V_28 L_32 ,
V_210 ) ;
goto V_165;
}
switch ( V_210 ) {
case V_141 :
V_2 -> V_102 ++ ;
V_69 = V_73 ;
break;
case V_202 :
V_2 -> V_103 ++ ;
V_69 = V_212 ;
break;
case V_182 :
V_176 = true ;
case V_180 :
V_2 -> V_104 ++ ;
V_69 = V_213 ;
break;
default:
V_69 = 0 ;
goto V_165;
break;
}
V_148 = V_61 -> V_69 == V_203 ?
V_61 -> V_151 . V_152 . V_214 : V_61 -> V_151 . V_215 . V_214 ;
if ( F_50 ( V_148 == 0 && V_69 != V_213 ) ||
F_50 ( ( V_61 -> V_69 != V_203 ) &&
( V_148 > V_40 ) ) ||
F_50 ( ( V_61 -> V_69 == V_203 ) &&
( V_148 > V_216 ) ) ) {
F_42 ( V_28 L_33 ,
V_148 ) ;
goto V_165;
}
V_145 . V_76 = 0 ;
V_60 -> V_2 = V_2 ;
V_60 -> V_173 = V_61 -> V_151 . V_215 . V_173 ;
V_60 -> V_69 = V_210 ;
V_60 -> V_134 = V_159 ;
V_60 -> V_140 = V_148 ;
if ( V_61 -> V_69 != V_203 ) {
V_145 . V_79 = V_61 -> V_151 . V_215 . V_45 ;
V_145 . V_78 = V_61 -> V_151 . V_215 . V_78 ;
for ( V_10 = 0 ; V_10 < V_148 ; V_10 ++ ) {
V_41 [ V_10 ] -> V_33 = V_61 -> V_151 . V_215 . V_144 [ V_10 ] . V_33 ;
V_144 [ V_10 ] . V_154 = V_61 -> V_151 . V_215 . V_144 [ V_10 ] . V_155 -
V_61 -> V_151 . V_215 . V_144 [ V_10 ] . V_156 + 1 ;
V_144 [ V_10 ] . V_157 = ( V_61 -> V_151 . V_215 . V_144 [ V_10 ] . V_156 << 9 ) ;
if ( ( V_61 -> V_151 . V_215 . V_144 [ V_10 ] . V_155 >= ( V_158 >> 9 ) ) ||
( V_61 -> V_151 . V_215 . V_144 [ V_10 ] . V_155 <
V_61 -> V_151 . V_215 . V_144 [ V_10 ] . V_156 ) )
goto V_165;
V_145 . V_76 += V_144 [ V_10 ] . V_154 ;
}
} else {
V_145 . V_79 = V_61 -> V_151 . V_152 . V_45 ;
V_145 . V_78 = V_61 -> V_151 . V_152 . V_78 ;
if ( F_85 ( V_61 , V_60 , V_144 , & V_145 ) )
goto V_165;
}
if ( F_48 ( & V_145 , V_2 , V_69 ) != 0 ) {
F_42 ( V_28 L_34 ,
V_69 == V_73 ? L_35 : L_36 ,
V_145 . V_78 ,
V_145 . V_78 + V_145 . V_76 ,
V_2 -> V_20 . V_80 ) ;
goto V_165;
}
for ( V_10 = 0 ; V_10 < V_148 ; V_10 ++ ) {
if ( ( ( int ) V_145 . V_78 | ( int ) V_144 [ V_10 ] . V_154 ) &
( ( F_115 ( V_145 . V_81 ) >> 9 ) - 1 ) ) {
F_42 ( V_28 L_37 ,
V_2 -> V_88 ) ;
goto V_165;
}
}
if ( V_176 )
F_93 ( V_60 -> V_2 ) ;
if ( F_84 ( V_60 ) )
goto V_217;
F_66 ( V_2 ) ;
F_20 ( & V_2 -> V_177 ) ;
for ( V_10 = 0 ; V_10 < V_148 ; V_10 ++ ) {
while ( ( V_184 == NULL ) ||
( F_116 ( V_184 ,
V_41 [ V_10 ] -> V_3 ,
V_144 [ V_10 ] . V_154 << 9 ,
V_144 [ V_10 ] . V_157 ) == 0 ) ) {
int V_218 = F_117 ( int , ( V_148 - V_10 ) , V_219 ) ;
V_184 = F_118 ( V_135 , V_218 ) ;
if ( F_50 ( V_184 == NULL ) )
goto V_220;
V_206 [ V_207 ++ ] = V_184 ;
V_184 -> V_221 = V_145 . V_81 ;
V_184 -> V_185 = V_60 ;
V_184 -> V_222 = F_101 ;
V_184 -> V_223 . V_224 = V_145 . V_78 ;
}
V_145 . V_78 += V_144 [ V_10 ] . V_154 ;
}
if ( ! V_184 ) {
F_4 ( V_69 != V_213 ) ;
V_184 = F_118 ( V_135 , 0 ) ;
if ( F_50 ( V_184 == NULL ) )
goto V_220;
V_206 [ V_207 ++ ] = V_184 ;
V_184 -> V_221 = V_145 . V_81 ;
V_184 -> V_185 = V_60 ;
V_184 -> V_222 = F_101 ;
}
F_94 ( & V_60 -> V_183 , V_207 ) ;
F_119 ( & V_209 ) ;
for ( V_10 = 0 ; V_10 < V_207 ; V_10 ++ )
F_120 ( V_69 , V_206 [ V_10 ] ) ;
F_121 ( & V_209 ) ;
if ( V_69 == V_73 )
V_2 -> V_225 += V_145 . V_76 ;
else if ( V_69 & V_164 )
V_2 -> V_226 += V_145 . V_76 ;
return 0 ;
V_217:
F_78 ( V_2 , V_60 -> V_139 ,
V_60 -> V_140 ) ;
V_165:
F_91 ( V_2 , V_61 -> V_151 . V_215 . V_173 , V_210 , V_172 ) ;
F_46 ( V_2 , V_60 ) ;
F_122 ( 1 ) ;
return - V_175 ;
V_220:
for ( V_10 = 0 ; V_10 < V_207 ; V_10 ++ )
F_102 ( V_206 [ V_10 ] ) ;
F_94 ( & V_60 -> V_183 , 1 ) ;
F_96 ( V_60 , - V_29 ) ;
F_122 ( 1 ) ;
return - V_175 ;
}
static void F_91 ( struct V_1 * V_2 , T_7 V_173 ,
unsigned short V_227 , int V_228 )
{
struct V_229 V_230 ;
unsigned long V_4 ;
union V_186 * V_187 = & V_2 -> V_187 ;
int V_231 ;
V_230 . V_173 = V_173 ;
V_230 . V_69 = V_227 ;
V_230 . V_134 = V_228 ;
F_2 ( & V_2 -> V_232 , V_4 ) ;
switch ( V_2 -> V_195 ) {
case V_196 :
memcpy ( F_123 ( & V_187 -> V_197 , V_187 -> V_197 . V_194 ) ,
& V_230 , sizeof( V_230 ) ) ;
break;
case V_198 :
memcpy ( F_123 ( & V_187 -> V_199 , V_187 -> V_199 . V_194 ) ,
& V_230 , sizeof( V_230 ) ) ;
break;
case V_200 :
memcpy ( F_123 ( & V_187 -> V_201 , V_187 -> V_201 . V_194 ) ,
& V_230 , sizeof( V_230 ) ) ;
break;
default:
F_110 () ;
}
V_187 -> V_190 . V_194 ++ ;
F_124 ( & V_187 -> V_190 , V_231 ) ;
F_5 ( & V_2 -> V_232 , V_4 ) ;
if ( V_231 )
F_125 ( V_2 -> V_96 ) ;
}
static int T_8 F_126 ( void )
{
int V_71 = 0 ;
if ( ! F_127 () )
return - V_233 ;
V_71 = F_128 () ;
if ( V_71 )
goto V_234;
V_71 = F_129 () ;
if ( V_71 )
goto V_234;
V_234:
return V_71 ;
}
