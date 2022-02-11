static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = & V_4 ;
V_2 -> V_5 = V_6 ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 == & V_4 ;
}
static void F_3 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_9 * * V_10 = & V_8 -> V_11 . V_9 , * V_12 = NULL ;
while ( * V_10 ) {
struct V_1 * V_13 ;
V_12 = * V_10 ;
V_13 = F_4 ( V_12 , struct V_1 , V_14 ) ;
if ( V_2 -> V_15 >= V_13 -> V_15 )
V_10 = & V_12 -> V_16 ;
else
V_10 = & V_12 -> V_17 ;
}
F_5 ( & V_2 -> V_14 , V_12 , V_10 ) ;
F_6 ( & V_2 -> V_14 , & V_8 -> V_11 ) ;
V_8 -> V_18 ++ ;
V_8 -> V_19 ++ ;
V_2 -> V_3 = & V_20 ;
if ( V_8 -> V_21 > V_2 -> V_15 )
V_8 -> V_21 = V_2 -> V_15 ;
}
static void F_7 ( struct V_22 * V_23 , struct V_1 * V_24 )
{
if ( V_23 -> V_25 )
V_23 -> V_26 -> V_3 = V_24 ;
else
V_23 -> V_25 = V_24 ;
V_23 -> V_26 = V_24 ;
V_24 -> V_3 = NULL ;
}
static bool F_8 ( const struct V_1 * V_2 )
{
return F_2 ( V_2 ) &&
F_9 ( V_6 , V_2 -> V_5 + V_27 ) ;
}
static void F_10 ( struct V_7 * V_8 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 , * V_32 [ V_33 ] ;
struct V_9 * * V_10 , * V_12 ;
int V_34 = 0 ;
V_10 = & V_29 -> V_9 ;
V_12 = NULL ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_2 = F_4 ( V_12 , struct V_1 , V_35 ) ;
if ( V_2 -> V_31 == V_31 )
break;
if ( F_8 ( V_2 ) ) {
V_32 [ V_34 ++ ] = V_2 ;
if ( V_34 == V_33 )
break;
}
if ( V_2 -> V_31 > V_31 )
V_10 = & V_12 -> V_16 ;
else
V_10 = & V_12 -> V_17 ;
}
V_8 -> V_36 -= V_34 ;
V_8 -> V_37 -= V_34 ;
V_8 -> V_38 += V_34 ;
while ( V_34 ) {
struct V_1 * V_2 = V_32 [ -- V_34 ] ;
F_11 ( & V_2 -> V_35 , V_29 ) ;
F_12 ( V_39 , V_2 ) ;
}
}
static struct V_1 * F_13 ( struct V_40 * V_41 , struct V_7 * V_8 )
{
struct V_9 * * V_10 , * V_12 ;
struct V_30 * V_31 = V_41 -> V_31 ;
struct V_28 * V_29 ;
struct V_1 * V_2 ;
if ( F_14 ( ( V_41 -> V_42 & V_43 ) == V_44 ) )
return & V_8 -> V_45 ;
if ( F_14 ( ! V_31 ) ) {
V_31 = (struct V_30 * ) ( F_15 ( V_41 ) | 1L ) ;
}
V_29 = & V_8 -> V_46 [ F_16 ( ( V_47 ) ( long ) V_31 , V_8 -> V_48 ) ] ;
if ( V_8 -> V_36 >= ( 2U << V_8 -> V_48 ) &&
V_8 -> V_37 > V_8 -> V_36 / 2 )
F_10 ( V_8 , V_29 , V_31 ) ;
V_10 = & V_29 -> V_9 ;
V_12 = NULL ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_2 = F_4 ( V_12 , struct V_1 , V_35 ) ;
if ( V_2 -> V_31 == V_31 ) {
if ( F_14 ( V_41 -> V_31 &&
V_2 -> V_49 != V_31 -> V_50 ) ) {
V_2 -> V_51 = V_8 -> V_52 ;
V_2 -> V_49 = V_31 -> V_50 ;
V_2 -> V_15 = 0ULL ;
}
return V_2 ;
}
if ( V_2 -> V_31 > V_31 )
V_10 = & V_12 -> V_16 ;
else
V_10 = & V_12 -> V_17 ;
}
V_2 = F_17 ( V_39 , V_53 | V_54 ) ;
if ( F_14 ( ! V_2 ) ) {
V_8 -> V_55 ++ ;
return & V_8 -> V_45 ;
}
F_1 ( V_2 ) ;
V_2 -> V_31 = V_31 ;
if ( V_41 -> V_31 )
V_2 -> V_49 = V_31 -> V_50 ;
V_2 -> V_51 = V_8 -> V_52 ;
F_5 ( & V_2 -> V_35 , V_12 , V_10 ) ;
F_6 ( & V_2 -> V_35 , V_29 ) ;
V_8 -> V_36 ++ ;
V_8 -> V_37 ++ ;
return V_2 ;
}
static struct V_40 * F_18 ( struct V_56 * V_57 , struct V_1 * V_24 )
{
struct V_40 * V_41 = V_24 -> V_23 ;
if ( V_41 ) {
V_24 -> V_23 = V_41 -> V_3 ;
V_41 -> V_3 = NULL ;
V_24 -> V_58 -- ;
F_19 ( V_57 , V_41 ) ;
V_57 -> V_8 . V_58 -- ;
}
return V_41 ;
}
static bool F_20 ( struct V_40 * V_41 )
{
return false ;
}
static void F_21 ( struct V_1 * V_24 , struct V_40 * V_41 )
{
struct V_40 * V_59 , * V_23 = V_24 -> V_23 ;
V_41 -> V_3 = NULL ;
if ( ! V_23 ) {
V_24 -> V_23 = V_41 ;
V_24 -> V_60 = V_41 ;
return;
}
if ( F_22 ( ! F_20 ( V_41 ) ) ) {
V_24 -> V_60 -> V_3 = V_41 ;
V_24 -> V_60 = V_41 ;
return;
}
V_59 = NULL ;
while ( F_20 ( V_23 ) ) {
V_59 = V_23 ;
V_23 = V_23 -> V_3 ;
if ( ! V_23 )
break;
}
if ( ! V_59 ) {
V_41 -> V_3 = V_24 -> V_23 ;
V_24 -> V_23 = V_41 ;
} else {
if ( V_59 == V_24 -> V_60 )
V_24 -> V_60 = V_41 ;
else
V_41 -> V_3 = V_59 -> V_3 ;
V_59 -> V_3 = V_41 ;
}
}
static int F_23 ( struct V_40 * V_41 , struct V_56 * V_57 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
struct V_1 * V_2 ;
if ( F_14 ( V_57 -> V_8 . V_58 >= V_57 -> V_61 ) )
return F_25 ( V_41 , V_57 ) ;
V_2 = F_13 ( V_41 , V_8 ) ;
if ( F_14 ( V_2 -> V_58 >= V_8 -> V_62 && V_2 != & V_8 -> V_45 ) ) {
V_8 -> V_63 ++ ;
return F_25 ( V_41 , V_57 ) ;
}
V_2 -> V_58 ++ ;
if ( F_20 ( V_41 ) )
V_8 -> V_64 ++ ;
F_26 ( V_57 , V_41 ) ;
if ( F_2 ( V_2 ) ) {
F_7 ( & V_8 -> V_65 , V_2 ) ;
if ( F_9 ( V_6 , V_2 -> V_5 + V_8 -> V_66 ) )
V_2 -> V_51 = F_27 ( V_47 , V_2 -> V_51 , V_8 -> V_67 ) ;
V_8 -> V_37 -- ;
}
F_21 ( V_2 , V_41 ) ;
if ( F_14 ( V_2 == & V_8 -> V_45 ) ) {
V_8 -> V_68 ++ ;
}
V_57 -> V_8 . V_58 ++ ;
return V_69 ;
}
static void F_28 ( struct V_7 * V_8 , T_1 V_70 )
{
struct V_9 * V_10 ;
if ( V_8 -> V_21 > V_70 )
return;
V_8 -> V_21 = ~ 0ULL ;
while ( ( V_10 = F_29 ( & V_8 -> V_11 ) ) != NULL ) {
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_14 ) ;
if ( V_2 -> V_15 > V_70 ) {
V_8 -> V_21 = V_2 -> V_15 ;
break;
}
F_11 ( V_10 , & V_8 -> V_11 ) ;
V_8 -> V_18 -- ;
F_7 ( & V_8 -> V_71 , V_2 ) ;
}
}
static struct V_40 * F_30 ( struct V_56 * V_57 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
T_1 V_70 = F_31 () ;
struct V_22 * V_23 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
V_47 V_72 ;
V_41 = F_18 ( V_57 , & V_8 -> V_45 ) ;
if ( V_41 )
goto V_73;
F_28 ( V_8 , V_70 ) ;
V_74:
V_23 = & V_8 -> V_65 ;
if ( ! V_23 -> V_25 ) {
V_23 = & V_8 -> V_71 ;
if ( ! V_23 -> V_25 ) {
if ( V_8 -> V_21 != ~ 0ULL )
F_32 ( & V_8 -> V_75 ,
V_8 -> V_21 ,
false ) ;
return NULL ;
}
}
V_2 = V_23 -> V_25 ;
if ( V_2 -> V_51 <= 0 ) {
V_2 -> V_51 += V_8 -> V_67 ;
V_23 -> V_25 = V_2 -> V_3 ;
F_7 ( & V_8 -> V_71 , V_2 ) ;
goto V_74;
}
if ( F_14 ( V_2 -> V_23 && V_70 < V_2 -> V_15 ) ) {
V_23 -> V_25 = V_2 -> V_3 ;
F_3 ( V_8 , V_2 ) ;
goto V_74;
}
V_41 = F_18 ( V_57 , V_2 ) ;
if ( ! V_41 ) {
V_23 -> V_25 = V_2 -> V_3 ;
if ( ( V_23 == & V_8 -> V_65 ) && V_8 -> V_71 . V_25 ) {
F_7 ( & V_8 -> V_71 , V_2 ) ;
} else {
F_1 ( V_2 ) ;
V_8 -> V_37 ++ ;
}
goto V_74;
}
F_33 ( & V_41 -> V_76 ) ;
V_2 -> V_15 = V_70 ;
V_2 -> V_51 -= F_34 ( V_41 ) ;
if ( V_2 -> V_51 > 0 || ! V_8 -> V_77 )
goto V_73;
V_72 = V_8 -> V_78 ;
if ( V_41 -> V_31 && V_41 -> V_31 -> V_79 != V_80 )
V_72 = F_35 ( V_41 -> V_31 -> V_81 , V_72 ) ;
if ( V_72 != ~ 0U ) {
V_47 V_82 = F_36 ( F_34 ( V_41 ) , V_8 -> V_67 ) ;
T_1 V_83 = ( T_1 ) V_82 * V_84 ;
if ( F_22 ( V_72 ) )
F_37 ( V_83 , V_72 ) ;
if ( F_14 ( V_83 > 125 * V_85 ) ) {
V_83 = 125 * V_85 ;
V_8 -> V_86 ++ ;
}
V_2 -> V_15 = V_70 + V_83 ;
}
V_73:
F_38 ( V_57 , V_41 ) ;
return V_41 ;
}
static void F_39 ( struct V_56 * V_57 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
struct V_28 * V_29 ;
struct V_40 * V_41 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned int V_87 ;
while ( ( V_41 = F_18 ( V_57 , & V_8 -> V_45 ) ) != NULL )
F_40 ( V_41 ) ;
if ( ! V_8 -> V_46 )
return;
for ( V_87 = 0 ; V_87 < ( 1U << V_8 -> V_48 ) ; V_87 ++ ) {
V_29 = & V_8 -> V_46 [ V_87 ] ;
while ( ( V_10 = F_29 ( V_29 ) ) != NULL ) {
V_2 = F_4 ( V_10 , struct V_1 , V_35 ) ;
F_11 ( V_10 , V_29 ) ;
while ( ( V_41 = F_18 ( V_57 , V_2 ) ) != NULL )
F_40 ( V_41 ) ;
F_12 ( V_39 , V_2 ) ;
}
}
V_8 -> V_65 . V_25 = NULL ;
V_8 -> V_71 . V_25 = NULL ;
V_8 -> V_11 = V_88 ;
V_8 -> V_36 = 0 ;
V_8 -> V_37 = 0 ;
V_8 -> V_18 = 0 ;
}
static void F_41 ( struct V_7 * V_8 ,
struct V_28 * V_89 , V_47 V_90 ,
struct V_28 * V_91 , V_47 V_92 )
{
struct V_9 * V_93 , * * V_94 , * V_12 ;
struct V_28 * V_95 , * V_96 ;
struct V_1 * V_97 , * V_98 ;
int V_34 = 0 ;
V_47 V_87 ;
for ( V_87 = 0 ; V_87 < ( 1U << V_90 ) ; V_87 ++ ) {
V_95 = & V_89 [ V_87 ] ;
while ( ( V_93 = F_29 ( V_95 ) ) != NULL ) {
F_11 ( V_93 , V_95 ) ;
V_97 = F_4 ( V_93 , struct V_1 , V_35 ) ;
if ( F_8 ( V_97 ) ) {
V_34 ++ ;
F_12 ( V_39 , V_97 ) ;
continue;
}
V_96 = & V_91 [ F_16 ( ( V_47 ) ( long ) V_97 -> V_31 , V_92 ) ] ;
V_94 = & V_96 -> V_9 ;
V_12 = NULL ;
while ( * V_94 ) {
V_12 = * V_94 ;
V_98 = F_4 ( V_12 , struct V_1 , V_35 ) ;
F_42 ( V_98 -> V_31 == V_97 -> V_31 ) ;
if ( V_98 -> V_31 > V_97 -> V_31 )
V_94 = & V_12 -> V_16 ;
else
V_94 = & V_12 -> V_17 ;
}
F_5 ( & V_97 -> V_35 , V_12 , V_94 ) ;
F_6 ( & V_97 -> V_35 , V_96 ) ;
}
}
V_8 -> V_36 -= V_34 ;
V_8 -> V_37 -= V_34 ;
V_8 -> V_38 += V_34 ;
}
static void * F_43 ( T_2 V_99 , int V_100 )
{
void * V_101 ;
V_101 = F_44 ( V_99 , V_102 | V_103 | V_54 , V_100 ) ;
if ( ! V_101 )
V_101 = F_45 ( V_99 , V_100 ) ;
return V_101 ;
}
static void F_46 ( void * V_104 )
{
F_47 ( V_104 ) ;
}
static int F_48 ( struct V_56 * V_57 , V_47 log )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
struct V_28 * V_105 ;
void * V_106 ;
V_47 V_87 ;
if ( V_8 -> V_46 && log == V_8 -> V_48 )
return 0 ;
V_105 = F_43 ( sizeof( struct V_28 ) << log ,
F_49 ( V_57 -> V_107 ) ) ;
if ( ! V_105 )
return - V_108 ;
for ( V_87 = 0 ; V_87 < ( 1U << log ) ; V_87 ++ )
V_105 [ V_87 ] = V_88 ;
F_50 ( V_57 ) ;
V_106 = V_8 -> V_46 ;
if ( V_106 )
F_41 ( V_8 , V_106 , V_8 -> V_48 , V_105 , log ) ;
V_8 -> V_46 = V_105 ;
V_8 -> V_48 = log ;
F_51 ( V_57 ) ;
F_46 ( V_106 ) ;
return 0 ;
}
static int F_52 ( struct V_56 * V_57 , struct V_109 * V_110 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
struct V_109 * V_111 [ V_112 + 1 ] ;
int V_113 , V_114 = 0 ;
V_47 V_115 ;
if ( ! V_110 )
return - V_116 ;
V_113 = F_53 ( V_111 , V_112 , V_110 , V_117 ) ;
if ( V_113 < 0 )
return V_113 ;
F_50 ( V_57 ) ;
V_115 = V_8 -> V_48 ;
if ( V_111 [ V_118 ] ) {
V_47 V_119 = F_54 ( V_111 [ V_118 ] ) ;
if ( V_119 >= 1 && V_119 <= F_55 ( 256 * 1024 ) )
V_115 = V_119 ;
else
V_113 = - V_116 ;
}
if ( V_111 [ V_120 ] )
V_57 -> V_61 = F_54 ( V_111 [ V_120 ] ) ;
if ( V_111 [ V_121 ] )
V_8 -> V_62 = F_54 ( V_111 [ V_121 ] ) ;
if ( V_111 [ V_122 ] )
V_8 -> V_67 = F_54 ( V_111 [ V_122 ] ) ;
if ( V_111 [ V_123 ] )
V_8 -> V_52 = F_54 ( V_111 [ V_123 ] ) ;
if ( V_111 [ V_124 ] )
F_56 ( L_1 ,
F_54 ( V_111 [ V_124 ] ) ) ;
if ( V_111 [ V_125 ] )
V_8 -> V_78 = F_54 ( V_111 [ V_125 ] ) ;
if ( V_111 [ V_126 ] ) {
V_47 V_127 = F_54 ( V_111 [ V_126 ] ) ;
if ( V_127 <= 1 )
V_8 -> V_77 = V_127 ;
else
V_113 = - V_116 ;
}
if ( V_111 [ V_128 ] ) {
V_47 V_129 = F_54 ( V_111 [ V_128 ] ) ;
V_8 -> V_66 = F_57 ( V_129 ) ;
}
if ( ! V_113 ) {
F_51 ( V_57 ) ;
V_113 = F_48 ( V_57 , V_115 ) ;
F_50 ( V_57 ) ;
}
while ( V_57 -> V_8 . V_58 > V_57 -> V_61 ) {
struct V_40 * V_41 = F_30 ( V_57 ) ;
if ( ! V_41 )
break;
F_40 ( V_41 ) ;
V_114 ++ ;
}
F_58 ( V_57 , V_114 ) ;
F_51 ( V_57 ) ;
return V_113 ;
}
static void F_59 ( struct V_56 * V_57 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
F_39 ( V_57 ) ;
F_46 ( V_8 -> V_46 ) ;
F_60 ( & V_8 -> V_75 ) ;
}
static int F_61 ( struct V_56 * V_57 , struct V_109 * V_110 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
int V_113 ;
V_57 -> V_61 = 10000 ;
V_8 -> V_62 = 100 ;
V_8 -> V_67 = 2 * F_62 ( F_63 ( V_57 ) ) ;
V_8 -> V_52 = 10 * F_62 ( F_63 ( V_57 ) ) ;
V_8 -> V_66 = F_64 ( 40 ) ;
V_8 -> V_78 = ~ 0U ;
V_8 -> V_77 = 1 ;
V_8 -> V_65 . V_25 = NULL ;
V_8 -> V_71 . V_25 = NULL ;
V_8 -> V_11 = V_88 ;
V_8 -> V_46 = NULL ;
V_8 -> V_48 = F_55 ( 1024 ) ;
F_65 ( & V_8 -> V_75 , V_57 ) ;
if ( V_110 )
V_113 = F_52 ( V_57 , V_110 ) ;
else
V_113 = F_48 ( V_57 , V_8 -> V_48 ) ;
return V_113 ;
}
static int F_66 ( struct V_56 * V_57 , struct V_40 * V_41 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
struct V_109 * V_130 ;
V_130 = F_67 ( V_41 , V_131 ) ;
if ( V_130 == NULL )
goto V_132;
if ( F_68 ( V_41 , V_120 , V_57 -> V_61 ) ||
F_68 ( V_41 , V_121 , V_8 -> V_62 ) ||
F_68 ( V_41 , V_122 , V_8 -> V_67 ) ||
F_68 ( V_41 , V_123 , V_8 -> V_52 ) ||
F_68 ( V_41 , V_126 , V_8 -> V_77 ) ||
F_68 ( V_41 , V_125 , V_8 -> V_78 ) ||
F_68 ( V_41 , V_128 ,
F_69 ( V_8 -> V_66 ) ) ||
F_68 ( V_41 , V_118 , V_8 -> V_48 ) )
goto V_132;
return F_70 ( V_41 , V_130 ) ;
V_132:
return - 1 ;
}
static int F_71 ( struct V_56 * V_57 , struct V_133 * V_134 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
T_1 V_70 = F_31 () ;
struct V_135 V_136 = {
. V_137 = V_8 -> V_38 ,
. V_138 = V_8 -> V_68 ,
. V_139 = V_8 -> V_64 ,
. V_20 = V_8 -> V_19 ,
. V_140 = V_8 -> V_63 ,
. V_141 = V_8 -> V_86 ,
. V_142 = V_8 -> V_55 ,
. V_36 = V_8 -> V_36 ,
. V_37 = V_8 -> V_37 ,
. V_18 = V_8 -> V_18 ,
. V_21 = V_8 -> V_21 - V_70 ,
} ;
return F_72 ( V_134 , & V_136 , sizeof( V_136 ) ) ;
}
static int T_3 F_73 ( void )
{
int V_143 ;
V_39 = F_74 ( L_2 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_39 )
return - V_108 ;
V_143 = F_75 ( & V_144 ) ;
if ( V_143 )
F_76 ( V_39 ) ;
return V_143 ;
}
static void T_4 F_77 ( void )
{
F_78 ( & V_144 ) ;
F_76 ( V_39 ) ;
}
