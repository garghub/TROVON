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
static void F_26 ( int V_36 ,
struct V_37 * V_34 )
{
struct V_38 * V_39 = V_34 -> V_34 ;
F_4 ( V_36 ) ;
F_27 ( V_39 ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_40 * V_41 ,
unsigned int V_9 )
{
struct V_42 V_43 [ V_44 ] ;
struct V_3 * V_45 [ V_44 ] ;
struct V_13 * V_13 ;
struct V_14 * V_46 ;
int V_47 = 0 ;
struct V_37 V_48 ;
struct V_38 V_49 ;
F_29 ( & V_49 ) ;
V_48 . V_34 = & V_49 ;
V_48 . V_50 = & F_26 ;
V_48 . V_45 = V_45 ;
V_48 . V_51 = V_43 ;
V_48 . V_52 = NULL ;
F_30 (persistent_gnt, n, root, node) {
F_4 ( V_13 -> V_53 ==
V_54 ) ;
F_31 ( & V_43 [ V_47 ] ,
( unsigned long ) F_32 ( F_33 (
V_13 -> V_3 ) ) ,
V_55 ,
V_13 -> V_53 ) ;
V_45 [ V_47 ] = V_13 -> V_3 ;
if ( ++ V_47 == V_44 ||
! F_34 ( & V_13 -> V_24 ) ) {
V_48 . V_56 = V_47 ;
F_35 ( & V_48 ) ;
F_36 ( & V_49 ) ;
F_9 ( V_2 , V_45 , V_47 ) ;
V_47 = 0 ;
}
F_37 ( & V_13 -> V_24 , V_41 ) ;
F_38 ( V_13 ) ;
V_9 -- ;
}
F_4 ( V_9 != 0 ) ;
}
void F_39 ( struct V_57 * V_58 )
{
struct V_42 V_43 [ V_44 ] ;
struct V_3 * V_45 [ V_44 ] ;
struct V_13 * V_13 ;
int V_59 , V_47 = 0 ;
struct V_1 * V_2 = F_14 ( V_58 , F_40 ( * V_2 ) , V_60 ) ;
while( ! F_3 ( & V_2 -> V_61 ) ) {
V_13 = F_7 ( & V_2 -> V_61 ,
struct V_13 ,
V_62 ) ;
F_8 ( & V_13 -> V_62 ) ;
F_31 ( & V_43 [ V_47 ] ,
F_41 ( V_13 -> V_3 ) ,
V_55 ,
V_13 -> V_53 ) ;
V_45 [ V_47 ] = V_13 -> V_3 ;
if ( ++ V_47 == V_44 ) {
V_59 = F_42 ( V_43 , NULL , V_45 ,
V_47 ) ;
F_4 ( V_59 ) ;
F_9 ( V_2 , V_45 , V_47 ) ;
V_47 = 0 ;
}
F_38 ( V_13 ) ;
}
if ( V_47 > 0 ) {
V_59 = F_42 ( V_43 , NULL , V_45 , V_47 ) ;
F_4 ( V_59 ) ;
F_9 ( V_2 , V_45 , V_47 ) ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_13 * V_13 ;
struct V_14 * V_46 ;
unsigned int V_63 , V_64 ;
bool V_65 = false , V_66 = false ;
struct V_40 * V_41 ;
if ( V_2 -> V_18 < V_19 ||
( V_2 -> V_18 == V_19 &&
! V_2 -> V_20 . V_21 ) ) {
return;
}
if ( F_44 ( & V_2 -> V_60 ) ) {
F_15 ( V_28 L_4 ) ;
return;
}
V_63 = ( V_19 / 100 ) * V_67 ;
V_63 = V_2 -> V_18 - V_19 + V_63 ;
V_63 = F_45 ( V_2 -> V_18 , V_63 ) ;
if ( ( V_63 == 0 ) ||
( V_63 > ( V_2 -> V_18 - F_46 ( & V_2 -> V_32 ) ) ) )
return;
V_64 = V_63 ;
F_47 ( V_28 L_5 , V_63 ) ;
F_4 ( ! F_3 ( & V_2 -> V_61 ) ) ;
V_41 = & V_2 -> V_23 ;
V_68:
F_30 (persistent_gnt, n, root, node) {
F_4 ( V_13 -> V_53 ==
V_54 ) ;
if ( V_66 ) {
F_24 ( V_35 , V_13 -> V_4 ) ;
continue;
}
if ( F_22 ( V_31 , V_13 -> V_4 ) )
continue;
if ( ! V_65 &&
( F_22 ( V_35 , V_13 -> V_4 ) ) )
continue;
F_37 ( & V_13 -> V_24 , V_41 ) ;
F_10 ( & V_13 -> V_62 ,
& V_2 -> V_61 ) ;
if ( -- V_63 == 0 )
goto V_69;
}
if ( ! V_65 && ! V_66 ) {
F_47 ( V_28 L_6 , V_63 ) ;
V_65 = true ;
goto V_68;
}
V_69:
if ( ! V_66 ) {
F_47 ( V_28 L_7 ) ;
V_66 = true ;
goto V_68;
}
V_2 -> V_18 -= ( V_64 - V_63 ) ;
V_2 -> V_20 . V_21 = 0 ;
F_48 ( & V_2 -> V_60 ) ;
F_47 ( V_28 L_8 , ( V_64 - V_63 ) , V_64 ) ;
return;
}
static struct V_70 * F_49 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = NULL ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_72 , V_4 ) ;
if ( ! F_3 ( & V_2 -> V_73 ) ) {
V_71 = F_50 ( V_2 -> V_73 . V_74 , struct V_70 ,
V_75 ) ;
F_8 ( & V_71 -> V_75 ) ;
}
F_5 ( & V_2 -> V_72 , V_4 ) ;
return V_71 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
unsigned long V_4 ;
int V_76 ;
F_2 ( & V_2 -> V_72 , V_4 ) ;
V_76 = F_3 ( & V_2 -> V_73 ) ;
F_10 ( & V_71 -> V_75 , & V_2 -> V_73 ) ;
F_5 ( & V_2 -> V_72 , V_4 ) ;
if ( V_76 )
F_52 ( & V_2 -> V_77 ) ;
}
static int F_53 ( struct V_78 * V_71 , struct V_1 * V_2 ,
int V_79 )
{
struct V_80 * V_20 = & V_2 -> V_20 ;
int V_81 = - V_82 ;
if ( ( V_79 != V_83 ) && V_20 -> V_84 )
goto V_85;
if ( F_54 ( V_71 -> V_86 ) ) {
T_2 V_87 = V_71 -> V_88 + V_71 -> V_86 ;
if ( F_55 ( V_87 < V_71 -> V_88 ) )
goto V_85;
if ( F_55 ( V_87 > F_56 ( V_20 ) ) )
goto V_85;
}
V_71 -> V_89 = V_20 -> V_90 ;
V_71 -> V_91 = V_20 -> V_91 ;
V_81 = 0 ;
V_85:
return V_81 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_80 * V_20 = & V_2 -> V_20 ;
struct V_92 V_93 ;
int V_94 ;
struct V_95 * V_89 = F_58 ( V_2 -> V_96 ) ;
unsigned long long V_97 = F_56 ( V_20 ) ;
F_59 ( V_28 L_9 ,
V_2 -> V_98 , F_60 ( V_20 -> V_90 ) , F_61 ( V_20 -> V_90 ) ) ;
F_59 ( V_28 L_10 , V_97 ) ;
V_20 -> V_99 = V_97 ;
V_100:
V_94 = F_62 ( & V_93 ) ;
if ( V_94 ) {
F_63 ( V_28 L_11 ) ;
return;
}
V_94 = F_64 ( V_93 , V_89 -> V_101 , L_12 , L_13 ,
( unsigned long long ) F_56 ( V_20 ) ) ;
if ( V_94 ) {
F_63 ( V_28 L_14 ) ;
goto abort;
}
V_94 = F_64 ( V_93 , V_89 -> V_101 , L_15 , L_16 , V_89 -> V_102 ) ;
if ( V_94 ) {
F_63 ( V_28 L_17 ) ;
goto abort;
}
V_94 = F_65 ( V_93 , 0 ) ;
if ( V_94 == - V_103 )
goto V_100;
if ( V_94 )
F_63 ( V_28 L_18 ) ;
return;
abort:
F_65 ( V_93 , 1 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
V_2 -> V_104 = 1 ;
F_52 ( & V_2 -> V_105 ) ;
}
T_3 F_67 ( int V_106 , void * V_107 )
{
F_66 ( V_107 ) ;
return V_108 ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_59 ( L_19
L_20 ,
V_109 -> V_110 , V_2 -> V_111 ,
V_2 -> V_112 , V_2 -> V_113 ,
V_2 -> V_114 , V_2 -> V_115 ,
V_2 -> V_18 ,
V_19 ) ;
V_2 -> V_116 = V_117 + F_69 ( 10 * 1000 ) ;
V_2 -> V_112 = 0 ;
V_2 -> V_113 = 0 ;
V_2 -> V_111 = 0 ;
V_2 -> V_115 = 0 ;
}
int F_70 ( void * V_118 )
{
struct V_1 * V_2 = V_118 ;
struct V_80 * V_20 = & V_2 -> V_20 ;
unsigned long V_119 ;
int V_59 ;
F_71 ( V_2 ) ;
while ( ! F_72 () ) {
if ( F_73 () )
continue;
if ( F_55 ( V_20 -> V_99 != F_56 ( V_20 ) ) )
F_57 ( V_2 ) ;
V_119 = F_69 ( V_120 ) ;
V_119 = F_74 (
V_2 -> V_105 ,
V_2 -> V_104 || F_72 () ,
V_119 ) ;
if ( V_119 == 0 )
goto V_121;
V_119 = F_74 (
V_2 -> V_77 ,
! F_3 ( & V_2 -> V_73 ) ||
F_72 () ,
V_119 ) ;
if ( V_119 == 0 )
goto V_121;
V_2 -> V_104 = 0 ;
F_75 () ;
V_59 = F_76 ( V_2 ) ;
if ( V_59 > 0 )
V_2 -> V_104 = 1 ;
if ( V_59 == - V_82 )
F_77 ( V_2 -> V_122 ,
F_72 () ) ;
V_121:
if ( V_2 -> V_20 . V_123 &&
F_78 ( V_117 , V_2 -> V_124 ) ) {
F_43 ( V_2 ) ;
V_2 -> V_124 = V_117 + F_69 ( V_120 ) ;
}
F_11 ( V_2 , V_125 ) ;
if ( V_126 && F_78 ( V_117 , V_2 -> V_116 ) )
F_68 ( V_2 ) ;
}
F_79 ( & V_2 -> V_60 ) ;
if ( V_126 )
F_68 ( V_2 ) ;
V_2 -> V_127 = NULL ;
F_80 ( V_2 ) ;
return 0 ;
}
void F_81 ( struct V_1 * V_2 )
{
if ( ! F_82 ( & V_2 -> V_23 ) )
F_28 ( V_2 , & V_2 -> V_23 ,
V_2 -> V_18 ) ;
F_4 ( ! F_82 ( & V_2 -> V_23 ) ) ;
V_2 -> V_18 = 0 ;
F_11 ( V_2 , 0 ) ;
}
static unsigned int F_83 (
struct V_1 * V_2 ,
struct V_128 * * V_45 ,
unsigned int V_9 ,
struct V_42 * V_51 ,
struct V_3 * * V_129 )
{
unsigned int V_10 , V_130 = 0 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
if ( V_45 [ V_10 ] -> V_13 != NULL ) {
F_23 ( V_2 , V_45 [ V_10 ] -> V_13 ) ;
continue;
}
if ( V_45 [ V_10 ] -> V_53 == V_54 )
continue;
V_129 [ V_130 ] = V_45 [ V_10 ] -> V_3 ;
F_31 ( & V_51 [ V_130 ] , F_41 ( V_45 [ V_10 ] -> V_3 ) ,
V_55 , V_45 [ V_10 ] -> V_53 ) ;
V_45 [ V_10 ] -> V_53 = V_54 ;
V_130 ++ ;
}
return V_130 ;
}
static void F_84 ( int V_36 , struct V_37 * V_34 )
{
struct V_70 * V_70 = (struct V_70 * ) ( V_34 -> V_34 ) ;
struct V_1 * V_2 = V_70 -> V_2 ;
F_4 ( V_36 ) ;
F_9 ( V_2 , V_34 -> V_45 , V_34 -> V_56 ) ;
F_85 ( V_2 , V_70 -> V_131 ,
V_70 -> V_79 , V_70 -> V_132 ) ;
F_51 ( V_2 , V_70 ) ;
if ( F_86 ( & V_2 -> V_133 ) && F_46 ( & V_2 -> V_134 ) ) {
F_27 ( & V_2 -> V_135 ) ;
}
F_80 ( V_2 ) ;
}
static void F_87 ( struct V_70 * V_71 )
{
struct V_37 * V_58 = & V_71 -> V_136 ;
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_128 * * V_45 = V_71 -> V_137 ;
unsigned int V_130 ;
V_130 = F_83 ( V_2 , V_45 , V_71 -> V_138 ,
V_71 -> V_43 , V_71 -> V_129 ) ;
V_58 -> V_34 = V_71 ;
V_58 -> V_50 = F_84 ;
V_58 -> V_51 = V_71 -> V_43 ;
V_58 -> V_52 = NULL ;
V_58 -> V_45 = V_71 -> V_129 ;
V_58 -> V_56 = V_130 ;
F_35 ( & V_71 -> V_136 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_128 * V_45 [] ,
int V_9 )
{
struct V_42 V_43 [ V_44 ] ;
struct V_3 * V_129 [ V_44 ] ;
unsigned int V_130 = 0 ;
int V_59 ;
while ( V_9 ) {
unsigned int V_139 = F_45 ( V_9 , V_44 ) ;
V_130 = F_83 ( V_2 , V_45 , V_139 ,
V_43 , V_129 ) ;
if ( V_130 ) {
V_59 = F_42 ( V_43 , NULL , V_129 , V_130 ) ;
F_4 ( V_59 ) ;
F_9 ( V_2 , V_129 , V_130 ) ;
}
V_45 += V_139 ;
V_9 -= V_139 ;
}
}
static int F_89 ( struct V_1 * V_2 ,
struct V_128 * V_45 [] ,
int V_9 , bool V_140 )
{
struct V_141 V_142 [ V_44 ] ;
struct V_3 * V_143 [ V_44 ] ;
struct V_13 * V_13 = NULL ;
T_4 V_144 = 0 ;
int V_10 , V_145 , V_146 ;
int V_147 = 0 ;
int V_59 = 0 ;
int V_148 = 0 , V_149 = 0 ;
int V_150 ;
V_150 = ( V_2 -> V_20 . V_123 ) ;
V_100:
for ( V_10 = V_149 ; V_10 < V_9 ; V_10 ++ ) {
T_5 V_4 ;
if ( V_150 )
V_13 = F_21 (
V_2 ,
V_45 [ V_10 ] -> V_33 ) ;
if ( V_13 ) {
V_45 [ V_10 ] -> V_3 = V_13 -> V_3 ;
V_45 [ V_10 ] -> V_13 = V_13 ;
} else {
if ( F_1 ( V_2 , & V_45 [ V_10 ] -> V_3 ) )
goto V_151;
V_144 = F_41 ( V_45 [ V_10 ] -> V_3 ) ;
V_143 [ V_147 ] = V_45 [ V_10 ] -> V_3 ;
V_45 [ V_10 ] -> V_13 = NULL ;
V_4 = V_55 ;
if ( ! V_150 && V_140 )
V_4 |= V_152 ;
F_90 ( & V_142 [ V_147 ++ ] , V_144 ,
V_4 , V_45 [ V_10 ] -> V_33 ,
V_2 -> V_98 ) ;
}
V_149 = V_10 + 1 ;
if ( V_147 == V_44 )
break;
}
if ( V_147 ) {
V_59 = F_91 ( V_142 , NULL , V_143 , V_147 ) ;
F_4 ( V_59 ) ;
}
for ( V_145 = V_148 , V_146 = 0 ; V_145 < V_149 ; V_145 ++ ) {
if ( ! V_45 [ V_145 ] -> V_13 ) {
F_4 ( V_146 >= V_147 ) ;
if ( F_55 ( V_142 [ V_146 ] . V_132 != 0 ) ) {
F_47 ( V_28 L_21 ) ;
F_9 ( V_2 , & V_45 [ V_145 ] -> V_3 , 1 ) ;
V_45 [ V_145 ] -> V_53 = V_54 ;
V_59 |= 1 ;
goto V_74;
}
V_45 [ V_145 ] -> V_53 = V_142 [ V_146 ] . V_53 ;
} else {
continue;
}
if ( V_150 &&
V_2 -> V_18 < V_19 ) {
V_13 = F_92 ( sizeof( struct V_13 ) ,
V_153 ) ;
if ( ! V_13 ) {
goto V_74;
}
V_13 -> V_25 = V_142 [ V_146 ] . V_154 ;
V_13 -> V_53 = V_142 [ V_146 ] . V_53 ;
V_13 -> V_3 = V_45 [ V_145 ] -> V_3 ;
if ( F_13 ( V_2 ,
V_13 ) ) {
F_38 ( V_13 ) ;
V_13 = NULL ;
goto V_74;
}
V_45 [ V_145 ] -> V_13 = V_13 ;
F_47 ( V_28 L_22 ,
V_13 -> V_25 , V_2 -> V_18 ,
V_19 ) ;
goto V_74;
}
if ( V_150 && ! V_2 -> V_20 . V_21 ) {
V_2 -> V_20 . V_21 = 1 ;
F_47 ( V_28 L_23 ,
V_2 -> V_98 , V_2 -> V_20 . V_53 ) ;
}
V_74:
V_146 ++ ;
}
V_147 = 0 ;
V_148 = V_149 ;
if ( V_149 != V_9 )
goto V_100;
return V_59 ;
V_151:
F_93 ( V_28 L_24 , V_155 ) ;
F_9 ( V_2 , V_143 , V_147 ) ;
return - V_156 ;
}
static int F_94 ( struct V_70 * V_70 )
{
int V_81 ;
V_81 = F_89 ( V_70 -> V_2 , V_70 -> V_137 ,
V_70 -> V_138 ,
( V_70 -> V_79 != V_157 ) ) ;
return V_81 ;
}
static int F_95 ( struct V_158 * V_71 ,
struct V_70 * V_70 ,
struct V_159 V_160 [] ,
struct V_78 * V_161 )
{
struct V_128 * * V_45 = V_70 -> V_162 ;
struct V_1 * V_2 = V_70 -> V_2 ;
int V_163 , V_81 , V_46 , V_164 , V_10 ;
struct V_165 * V_137 = NULL ;
V_164 = V_70 -> V_138 ;
V_163 = F_96 ( V_164 ) ;
F_4 ( V_163 > V_166 ) ;
for ( V_10 = 0 ; V_10 < V_163 ; V_10 ++ )
V_45 [ V_10 ] -> V_33 = V_71 -> V_167 . V_168 . V_163 [ V_10 ] ;
V_81 = F_89 ( V_2 , V_45 , V_163 , true ) ;
if ( V_81 )
goto V_43;
for ( V_46 = 0 , V_10 = 0 ; V_46 < V_164 ; V_46 ++ ) {
if ( ( V_46 % V_169 ) == 0 ) {
if ( V_137 )
F_97 ( V_137 ) ;
V_137 = F_98 ( V_45 [ V_46 / V_169 ] -> V_3 ) ;
}
V_10 = V_46 % V_169 ;
V_70 -> V_137 [ V_46 ] -> V_33 = V_137 [ V_10 ] . V_33 ;
V_160 [ V_46 ] . V_170 = V_137 [ V_10 ] . V_171 -
V_137 [ V_10 ] . V_172 + 1 ;
V_160 [ V_46 ] . V_173 = ( V_137 [ V_10 ] . V_172 << 9 ) ;
if ( ( V_137 [ V_10 ] . V_171 >= ( V_174 >> 9 ) ) ||
( V_137 [ V_10 ] . V_171 < V_137 [ V_10 ] . V_172 ) ) {
V_81 = - V_29 ;
goto V_43;
}
V_161 -> V_86 += V_160 [ V_46 ] . V_170 ;
}
V_43:
if ( V_137 )
F_97 ( V_137 ) ;
F_88 ( V_2 , V_45 , V_163 ) ;
return V_81 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_158 * V_71 )
{
int V_94 = 0 ;
int V_132 = V_175 ;
struct V_176 * V_91 = V_2 -> V_20 . V_91 ;
unsigned long V_177 ;
struct V_78 V_161 ;
F_71 ( V_2 ) ;
V_161 . V_88 = V_71 -> V_167 . V_178 . V_88 ;
V_161 . V_86 = V_71 -> V_167 . V_178 . V_179 ;
V_94 = F_53 ( & V_161 , V_2 , V_180 ) ;
if ( V_94 ) {
F_63 ( V_28 L_25 ,
V_161 . V_88 ,
V_161 . V_88 + V_161 . V_86 , V_2 -> V_20 . V_90 ) ;
goto V_181;
}
V_2 -> V_115 ++ ;
V_177 = ( V_2 -> V_20 . V_182 &&
( V_71 -> V_167 . V_178 . V_183 & V_184 ) ) ?
V_185 : 0 ;
V_94 = F_100 ( V_91 , V_71 -> V_167 . V_178 . V_88 ,
V_71 -> V_167 . V_178 . V_179 ,
V_153 , V_177 ) ;
V_181:
if ( V_94 == - V_186 ) {
F_47 ( V_28 L_26 ) ;
V_132 = V_187 ;
} else if ( V_94 )
V_132 = V_188 ;
F_85 ( V_2 , V_71 -> V_167 . V_178 . V_131 , V_71 -> V_79 , V_132 ) ;
F_80 ( V_2 ) ;
return V_94 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_158 * V_71 ,
struct V_70 * V_70 )
{
F_51 ( V_2 , V_70 ) ;
F_85 ( V_2 , V_71 -> V_167 . V_189 . V_131 , V_71 -> V_79 ,
V_187 ) ;
return - V_190 ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_103 ( & V_2 -> V_134 , 1 ) ;
do {
if ( F_46 ( & V_2 -> V_133 ) == 0 )
break;
F_104 (
& V_2 -> V_135 , V_191 ) ;
if ( ! F_46 ( & V_2 -> V_134 ) )
break;
} while ( ! F_72 () );
F_103 ( & V_2 -> V_134 , 0 ) ;
}
static void F_105 ( struct V_70 * V_70 , int error )
{
if ( ( V_70 -> V_79 == V_192 ) &&
( error == - V_186 ) ) {
F_47 ( V_28 L_27 ) ;
F_106 ( V_193 , V_70 -> V_2 -> V_96 , 0 ) ;
V_70 -> V_132 = V_187 ;
} else if ( ( V_70 -> V_79 == V_194 ) &&
( error == - V_186 ) ) {
F_47 ( V_28 L_28 ) ;
F_107 ( V_193 , V_70 -> V_2 -> V_96 , 0 ) ;
V_70 -> V_132 = V_187 ;
} else if ( error ) {
F_47 ( V_28 L_29
L_30 , error ) ;
V_70 -> V_132 = V_188 ;
}
if ( F_86 ( & V_70 -> V_195 ) )
F_87 ( V_70 ) ;
}
static void F_108 ( struct V_196 * V_196 , int error )
{
F_105 ( V_196 -> V_197 , error ) ;
F_109 ( V_196 ) ;
}
static int
F_110 ( struct V_1 * V_2 )
{
union V_198 * V_199 = & V_2 -> V_199 ;
struct V_158 V_71 ;
struct V_70 * V_70 ;
T_6 V_81 , V_200 ;
int V_201 = 0 ;
V_81 = V_199 -> V_202 . V_203 ;
V_200 = V_199 -> V_202 . V_204 -> V_205 ;
F_111 () ;
if ( F_112 ( & V_199 -> V_202 , V_200 ) ) {
V_81 = V_199 -> V_202 . V_206 ;
F_63 ( V_28 L_31 ,
V_200 , V_81 , V_200 - V_81 , V_2 -> V_20 . V_90 ) ;
return - V_82 ;
}
while ( V_81 != V_200 ) {
if ( F_113 ( & V_199 -> V_202 , V_81 ) )
break;
if ( F_72 () ) {
V_201 = 1 ;
break;
}
V_70 = F_49 ( V_2 ) ;
if ( NULL == V_70 ) {
V_2 -> V_111 ++ ;
V_201 = 1 ;
break;
}
switch ( V_2 -> V_207 ) {
case V_208 :
memcpy ( & V_71 , F_114 ( & V_199 -> V_209 , V_81 ) , sizeof( V_71 ) ) ;
break;
case V_210 :
F_115 ( & V_71 , F_114 ( & V_199 -> V_211 , V_81 ) ) ;
break;
case V_212 :
F_116 ( & V_71 , F_114 ( & V_199 -> V_213 , V_81 ) ) ;
break;
default:
F_117 () ;
}
V_199 -> V_202 . V_203 = ++ V_81 ;
F_118 () ;
switch ( V_71 . V_79 ) {
case V_157 :
case V_214 :
case V_194 :
case V_192 :
case V_215 :
if ( F_119 ( V_2 , & V_71 , V_70 ) )
goto V_50;
break;
case V_216 :
F_51 ( V_2 , V_70 ) ;
if ( F_99 ( V_2 , & V_71 ) )
goto V_50;
break;
default:
if ( F_101 ( V_2 , & V_71 , V_70 ) )
goto V_50;
break;
}
F_120 () ;
}
V_50:
return V_201 ;
}
static int
F_76 ( struct V_1 * V_2 )
{
union V_198 * V_199 = & V_2 -> V_199 ;
int V_201 ;
do {
V_201 = F_110 ( V_2 ) ;
if ( V_201 )
break;
F_121 ( & V_199 -> V_202 , V_201 ) ;
} while ( V_201 );
return V_201 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_158 * V_71 ,
struct V_70 * V_70 )
{
struct V_78 V_161 ;
struct V_159 * V_160 = V_70 -> V_160 ;
unsigned int V_164 ;
struct V_196 * V_196 = NULL ;
struct V_196 * * V_217 = V_70 -> V_217 ;
int V_10 , V_218 = 0 ;
int V_79 ;
struct V_219 V_220 ;
bool V_134 = false ;
struct V_128 * * V_45 = V_70 -> V_137 ;
unsigned short V_221 ;
V_221 = V_71 -> V_79 == V_215 ?
V_71 -> V_167 . V_168 . V_222 : V_71 -> V_79 ;
if ( ( V_71 -> V_79 == V_215 ) &&
( V_221 != V_157 ) &&
( V_221 != V_214 ) ) {
F_47 ( V_28 L_32 ,
V_221 ) ;
goto V_181;
}
switch ( V_221 ) {
case V_157 :
V_2 -> V_112 ++ ;
V_79 = V_83 ;
break;
case V_214 :
V_2 -> V_113 ++ ;
V_79 = V_223 ;
break;
case V_194 :
V_134 = true ;
case V_192 :
V_2 -> V_114 ++ ;
V_79 = V_224 ;
break;
default:
V_79 = 0 ;
goto V_181;
break;
}
V_164 = V_71 -> V_79 == V_215 ?
V_71 -> V_167 . V_168 . V_225 : V_71 -> V_167 . V_226 . V_225 ;
if ( F_55 ( V_164 == 0 && V_79 != V_224 ) ||
F_55 ( ( V_71 -> V_79 != V_215 ) &&
( V_164 > V_44 ) ) ||
F_55 ( ( V_71 -> V_79 == V_215 ) &&
( V_164 > V_227 ) ) ) {
F_47 ( V_28 L_33 ,
V_164 ) ;
goto V_181;
}
V_161 . V_86 = 0 ;
V_70 -> V_2 = V_2 ;
V_70 -> V_131 = V_71 -> V_167 . V_226 . V_131 ;
V_70 -> V_79 = V_221 ;
V_70 -> V_132 = V_175 ;
V_70 -> V_138 = V_164 ;
if ( V_71 -> V_79 != V_215 ) {
V_161 . V_89 = V_71 -> V_167 . V_226 . V_53 ;
V_161 . V_88 = V_71 -> V_167 . V_226 . V_88 ;
for ( V_10 = 0 ; V_10 < V_164 ; V_10 ++ ) {
V_45 [ V_10 ] -> V_33 = V_71 -> V_167 . V_226 . V_160 [ V_10 ] . V_33 ;
V_160 [ V_10 ] . V_170 = V_71 -> V_167 . V_226 . V_160 [ V_10 ] . V_171 -
V_71 -> V_167 . V_226 . V_160 [ V_10 ] . V_172 + 1 ;
V_160 [ V_10 ] . V_173 = ( V_71 -> V_167 . V_226 . V_160 [ V_10 ] . V_172 << 9 ) ;
if ( ( V_71 -> V_167 . V_226 . V_160 [ V_10 ] . V_171 >= ( V_174 >> 9 ) ) ||
( V_71 -> V_167 . V_226 . V_160 [ V_10 ] . V_171 <
V_71 -> V_167 . V_226 . V_160 [ V_10 ] . V_172 ) )
goto V_181;
V_161 . V_86 += V_160 [ V_10 ] . V_170 ;
}
} else {
V_161 . V_89 = V_71 -> V_167 . V_168 . V_53 ;
V_161 . V_88 = V_71 -> V_167 . V_168 . V_88 ;
if ( F_95 ( V_71 , V_70 , V_160 , & V_161 ) )
goto V_181;
}
if ( F_53 ( & V_161 , V_2 , V_79 ) != 0 ) {
F_47 ( V_28 L_34 ,
V_79 == V_83 ? L_35 : L_36 ,
V_161 . V_88 ,
V_161 . V_88 + V_161 . V_86 ,
V_2 -> V_20 . V_90 ) ;
goto V_181;
}
for ( V_10 = 0 ; V_10 < V_164 ; V_10 ++ ) {
if ( ( ( int ) V_161 . V_88 | ( int ) V_160 [ V_10 ] . V_170 ) &
( ( F_122 ( V_161 . V_91 ) >> 9 ) - 1 ) ) {
F_47 ( V_28 L_37 ,
V_2 -> V_98 ) ;
goto V_181;
}
}
if ( V_134 )
F_102 ( V_70 -> V_2 ) ;
if ( F_94 ( V_70 ) )
goto V_228;
F_71 ( V_2 ) ;
F_20 ( & V_2 -> V_133 ) ;
for ( V_10 = 0 ; V_10 < V_164 ; V_10 ++ ) {
while ( ( V_196 == NULL ) ||
( F_123 ( V_196 ,
V_45 [ V_10 ] -> V_3 ,
V_160 [ V_10 ] . V_170 << 9 ,
V_160 [ V_10 ] . V_173 ) == 0 ) ) {
int V_229 = F_124 ( int , ( V_164 - V_10 ) , V_230 ) ;
V_196 = F_125 ( V_153 , V_229 ) ;
if ( F_55 ( V_196 == NULL ) )
goto V_231;
V_217 [ V_218 ++ ] = V_196 ;
V_196 -> V_232 = V_161 . V_91 ;
V_196 -> V_197 = V_70 ;
V_196 -> V_233 = F_108 ;
V_196 -> V_234 . V_235 = V_161 . V_88 ;
}
V_161 . V_88 += V_160 [ V_10 ] . V_170 ;
}
if ( ! V_196 ) {
F_4 ( V_79 != V_224 ) ;
V_196 = F_125 ( V_153 , 0 ) ;
if ( F_55 ( V_196 == NULL ) )
goto V_231;
V_217 [ V_218 ++ ] = V_196 ;
V_196 -> V_232 = V_161 . V_91 ;
V_196 -> V_197 = V_70 ;
V_196 -> V_233 = F_108 ;
}
F_103 ( & V_70 -> V_195 , V_218 ) ;
F_126 ( & V_220 ) ;
for ( V_10 = 0 ; V_10 < V_218 ; V_10 ++ )
F_127 ( V_79 , V_217 [ V_10 ] ) ;
F_128 ( & V_220 ) ;
if ( V_79 == V_83 )
V_2 -> V_236 += V_161 . V_86 ;
else if ( V_79 & V_180 )
V_2 -> V_237 += V_161 . V_86 ;
return 0 ;
V_228:
F_88 ( V_2 , V_70 -> V_137 ,
V_70 -> V_138 ) ;
V_181:
F_85 ( V_2 , V_71 -> V_167 . V_226 . V_131 , V_221 , V_188 ) ;
F_51 ( V_2 , V_70 ) ;
F_129 ( 1 ) ;
return - V_190 ;
V_231:
for ( V_10 = 0 ; V_10 < V_218 ; V_10 ++ )
F_109 ( V_217 [ V_10 ] ) ;
F_103 ( & V_70 -> V_195 , 1 ) ;
F_105 ( V_70 , - V_29 ) ;
F_129 ( 1 ) ;
return - V_190 ;
}
static void F_85 ( struct V_1 * V_2 , T_7 V_131 ,
unsigned short V_238 , int V_239 )
{
struct V_240 V_241 ;
unsigned long V_4 ;
union V_198 * V_199 = & V_2 -> V_199 ;
int V_242 ;
V_241 . V_131 = V_131 ;
V_241 . V_79 = V_238 ;
V_241 . V_132 = V_239 ;
F_2 ( & V_2 -> V_243 , V_4 ) ;
switch ( V_2 -> V_207 ) {
case V_208 :
memcpy ( F_130 ( & V_199 -> V_209 , V_199 -> V_209 . V_206 ) ,
& V_241 , sizeof( V_241 ) ) ;
break;
case V_210 :
memcpy ( F_130 ( & V_199 -> V_211 , V_199 -> V_211 . V_206 ) ,
& V_241 , sizeof( V_241 ) ) ;
break;
case V_212 :
memcpy ( F_130 ( & V_199 -> V_213 , V_199 -> V_213 . V_206 ) ,
& V_241 , sizeof( V_241 ) ) ;
break;
default:
F_117 () ;
}
V_199 -> V_202 . V_206 ++ ;
F_131 ( & V_199 -> V_202 , V_242 ) ;
F_5 ( & V_2 -> V_243 , V_4 ) ;
if ( V_242 )
F_132 ( V_2 -> V_106 ) ;
}
static int T_8 F_133 ( void )
{
int V_81 = 0 ;
if ( ! F_134 () )
return - V_244 ;
V_81 = F_135 () ;
if ( V_81 )
goto V_245;
V_81 = F_136 () ;
if ( V_81 )
goto V_245;
V_245:
return V_81 ;
}
