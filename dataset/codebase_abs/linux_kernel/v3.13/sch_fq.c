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
V_57 -> V_59 . V_60 -= F_19 ( V_41 ) ;
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
struct V_40 * V_61 , * V_23 = V_24 -> V_23 ;
V_41 -> V_3 = NULL ;
if ( ! V_23 ) {
V_24 -> V_23 = V_41 ;
V_24 -> V_62 = V_41 ;
return;
}
if ( F_22 ( ! F_20 ( V_41 ) ) ) {
V_24 -> V_62 -> V_3 = V_41 ;
V_24 -> V_62 = V_41 ;
return;
}
V_61 = NULL ;
while ( F_20 ( V_23 ) ) {
V_61 = V_23 ;
V_23 = V_23 -> V_3 ;
if ( ! V_23 )
break;
}
if ( ! V_61 ) {
V_41 -> V_3 = V_24 -> V_23 ;
V_24 -> V_23 = V_41 ;
} else {
if ( V_61 == V_24 -> V_62 )
V_24 -> V_62 = V_41 ;
else
V_41 -> V_3 = V_61 -> V_3 ;
V_61 -> V_3 = V_41 ;
}
}
static int F_23 ( struct V_40 * V_41 , struct V_56 * V_57 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
struct V_1 * V_2 ;
if ( F_14 ( V_57 -> V_8 . V_58 >= V_57 -> V_63 ) )
return F_25 ( V_41 , V_57 ) ;
V_2 = F_13 ( V_41 , V_8 ) ;
if ( F_14 ( V_2 -> V_58 >= V_8 -> V_64 && V_2 != & V_8 -> V_45 ) ) {
V_8 -> V_65 ++ ;
return F_25 ( V_41 , V_57 ) ;
}
V_2 -> V_58 ++ ;
if ( F_20 ( V_41 ) )
V_8 -> V_66 ++ ;
V_57 -> V_59 . V_60 += F_19 ( V_41 ) ;
if ( F_2 ( V_2 ) ) {
F_7 ( & V_8 -> V_67 , V_2 ) ;
if ( F_9 ( V_6 , V_2 -> V_5 + V_8 -> V_68 ) )
V_2 -> V_51 = F_26 ( V_47 , V_2 -> V_51 , V_8 -> V_69 ) ;
V_8 -> V_37 -- ;
F_27 ( V_57 ) ;
}
F_21 ( V_2 , V_41 ) ;
if ( F_14 ( V_2 == & V_8 -> V_45 ) ) {
V_8 -> V_70 ++ ;
F_27 ( V_57 ) ;
}
V_57 -> V_8 . V_58 ++ ;
return V_71 ;
}
static void F_28 ( struct V_7 * V_8 , T_1 V_72 )
{
struct V_9 * V_10 ;
if ( V_8 -> V_21 > V_72 )
return;
V_8 -> V_21 = ~ 0ULL ;
while ( ( V_10 = F_29 ( & V_8 -> V_11 ) ) != NULL ) {
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_14 ) ;
if ( V_2 -> V_15 > V_72 ) {
V_8 -> V_21 = V_2 -> V_15 ;
break;
}
F_11 ( V_10 , & V_8 -> V_11 ) ;
V_8 -> V_18 -- ;
F_7 ( & V_8 -> V_73 , V_2 ) ;
}
}
static struct V_40 * F_30 ( struct V_56 * V_57 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
T_1 V_72 = F_31 ( F_32 () ) ;
struct V_22 * V_23 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
V_47 V_74 ;
V_41 = F_18 ( V_57 , & V_8 -> V_45 ) ;
if ( V_41 )
goto V_75;
F_28 ( V_8 , V_72 ) ;
V_76:
V_23 = & V_8 -> V_67 ;
if ( ! V_23 -> V_25 ) {
V_23 = & V_8 -> V_73 ;
if ( ! V_23 -> V_25 ) {
if ( V_8 -> V_21 != ~ 0ULL )
F_33 ( & V_8 -> V_77 ,
V_8 -> V_21 ) ;
return NULL ;
}
}
V_2 = V_23 -> V_25 ;
if ( V_2 -> V_51 <= 0 ) {
V_2 -> V_51 += V_8 -> V_69 ;
V_23 -> V_25 = V_2 -> V_3 ;
F_7 ( & V_8 -> V_73 , V_2 ) ;
goto V_76;
}
if ( F_14 ( V_2 -> V_23 && V_72 < V_2 -> V_15 ) ) {
V_23 -> V_25 = V_2 -> V_3 ;
F_3 ( V_8 , V_2 ) ;
goto V_76;
}
V_41 = F_18 ( V_57 , V_2 ) ;
if ( ! V_41 ) {
V_23 -> V_25 = V_2 -> V_3 ;
if ( ( V_23 == & V_8 -> V_67 ) && V_8 -> V_73 . V_25 ) {
F_7 ( & V_8 -> V_73 , V_2 ) ;
} else {
F_1 ( V_2 ) ;
V_8 -> V_37 ++ ;
}
goto V_76;
}
F_34 ( & V_41 -> V_78 ) ;
V_2 -> V_15 = V_72 ;
V_2 -> V_51 -= F_19 ( V_41 ) ;
if ( V_2 -> V_51 > 0 || ! V_8 -> V_79 )
goto V_75;
V_74 = V_8 -> V_80 ;
if ( V_41 -> V_31 && V_41 -> V_31 -> V_81 != V_82 )
V_74 = F_35 ( V_41 -> V_31 -> V_83 , V_74 ) ;
if ( V_74 != ~ 0U ) {
V_47 V_84 = F_36 ( F_19 ( V_41 ) , V_8 -> V_69 ) ;
T_1 V_85 = ( T_1 ) V_84 * V_86 ;
if ( F_22 ( V_74 ) )
F_37 ( V_85 , V_74 ) ;
if ( F_14 ( V_85 > 125 * V_87 ) ) {
V_85 = 125 * V_87 ;
V_8 -> V_88 ++ ;
}
V_2 -> V_15 = V_72 + V_85 ;
}
V_75:
F_38 ( V_57 , V_41 ) ;
F_27 ( V_57 ) ;
return V_41 ;
}
static void F_39 ( struct V_56 * V_57 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
struct V_28 * V_29 ;
struct V_40 * V_41 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned int V_89 ;
while ( ( V_41 = F_18 ( V_57 , & V_8 -> V_45 ) ) != NULL )
F_40 ( V_41 ) ;
if ( ! V_8 -> V_46 )
return;
for ( V_89 = 0 ; V_89 < ( 1U << V_8 -> V_48 ) ; V_89 ++ ) {
V_29 = & V_8 -> V_46 [ V_89 ] ;
while ( ( V_10 = F_29 ( V_29 ) ) != NULL ) {
V_2 = F_4 ( V_10 , struct V_1 , V_35 ) ;
F_11 ( V_10 , V_29 ) ;
while ( ( V_41 = F_18 ( V_57 , V_2 ) ) != NULL )
F_40 ( V_41 ) ;
F_12 ( V_39 , V_2 ) ;
}
}
V_8 -> V_67 . V_25 = NULL ;
V_8 -> V_73 . V_25 = NULL ;
V_8 -> V_11 = V_90 ;
V_8 -> V_36 = 0 ;
V_8 -> V_37 = 0 ;
V_8 -> V_18 = 0 ;
}
static void F_41 ( struct V_7 * V_8 ,
struct V_28 * V_91 , V_47 V_92 ,
struct V_28 * V_93 , V_47 V_94 )
{
struct V_9 * V_95 , * * V_96 , * V_12 ;
struct V_28 * V_97 , * V_98 ;
struct V_1 * V_99 , * V_100 ;
int V_34 = 0 ;
V_47 V_89 ;
for ( V_89 = 0 ; V_89 < ( 1U << V_92 ) ; V_89 ++ ) {
V_97 = & V_91 [ V_89 ] ;
while ( ( V_95 = F_29 ( V_97 ) ) != NULL ) {
F_11 ( V_95 , V_97 ) ;
V_99 = F_4 ( V_95 , struct V_1 , V_35 ) ;
if ( F_8 ( V_99 ) ) {
V_34 ++ ;
F_12 ( V_39 , V_99 ) ;
continue;
}
V_98 = & V_93 [ F_16 ( ( V_47 ) ( long ) V_99 -> V_31 , V_94 ) ] ;
V_96 = & V_98 -> V_9 ;
V_12 = NULL ;
while ( * V_96 ) {
V_12 = * V_96 ;
V_100 = F_4 ( V_12 , struct V_1 , V_35 ) ;
F_42 ( V_100 -> V_31 == V_99 -> V_31 ) ;
if ( V_100 -> V_31 > V_99 -> V_31 )
V_96 = & V_12 -> V_16 ;
else
V_96 = & V_12 -> V_17 ;
}
F_5 ( & V_99 -> V_35 , V_12 , V_96 ) ;
F_6 ( & V_99 -> V_35 , V_98 ) ;
}
}
V_8 -> V_36 -= V_34 ;
V_8 -> V_37 -= V_34 ;
V_8 -> V_38 += V_34 ;
}
static int F_43 ( struct V_7 * V_8 , V_47 log )
{
struct V_28 * V_101 ;
V_47 V_89 ;
if ( V_8 -> V_46 && log == V_8 -> V_48 )
return 0 ;
V_101 = F_44 ( sizeof( struct V_28 ) << log , V_102 ) ;
if ( ! V_101 )
return - V_103 ;
for ( V_89 = 0 ; V_89 < ( 1U << log ) ; V_89 ++ )
V_101 [ V_89 ] = V_90 ;
if ( V_8 -> V_46 ) {
F_41 ( V_8 , V_8 -> V_46 , V_8 -> V_48 , V_101 , log ) ;
F_45 ( V_8 -> V_46 ) ;
}
V_8 -> V_46 = V_101 ;
V_8 -> V_48 = log ;
return 0 ;
}
static int F_46 ( struct V_56 * V_57 , struct V_104 * V_105 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
struct V_104 * V_106 [ V_107 + 1 ] ;
int V_108 , V_109 = 0 ;
V_47 V_110 ;
if ( ! V_105 )
return - V_111 ;
V_108 = F_47 ( V_106 , V_107 , V_105 , V_112 ) ;
if ( V_108 < 0 )
return V_108 ;
F_48 ( V_57 ) ;
V_110 = V_8 -> V_48 ;
if ( V_106 [ V_113 ] ) {
V_47 V_114 = F_49 ( V_106 [ V_113 ] ) ;
if ( V_114 >= 1 && V_114 <= F_50 ( 256 * 1024 ) )
V_110 = V_114 ;
else
V_108 = - V_111 ;
}
if ( V_106 [ V_115 ] )
V_57 -> V_63 = F_49 ( V_106 [ V_115 ] ) ;
if ( V_106 [ V_116 ] )
V_8 -> V_64 = F_49 ( V_106 [ V_116 ] ) ;
if ( V_106 [ V_117 ] )
V_8 -> V_69 = F_49 ( V_106 [ V_117 ] ) ;
if ( V_106 [ V_118 ] )
V_8 -> V_52 = F_49 ( V_106 [ V_118 ] ) ;
if ( V_106 [ V_119 ] )
F_51 ( L_1 ,
F_49 ( V_106 [ V_119 ] ) ) ;
if ( V_106 [ V_120 ] )
V_8 -> V_80 = F_49 ( V_106 [ V_120 ] ) ;
if ( V_106 [ V_121 ] ) {
V_47 V_122 = F_49 ( V_106 [ V_121 ] ) ;
if ( V_122 <= 1 )
V_8 -> V_79 = V_122 ;
else
V_108 = - V_111 ;
}
if ( V_106 [ V_123 ] ) {
V_47 V_124 = F_49 ( V_106 [ V_123 ] ) ;
V_8 -> V_68 = F_52 ( V_124 ) ;
}
if ( ! V_108 )
V_108 = F_43 ( V_8 , V_110 ) ;
while ( V_57 -> V_8 . V_58 > V_57 -> V_63 ) {
struct V_40 * V_41 = F_30 ( V_57 ) ;
if ( ! V_41 )
break;
F_40 ( V_41 ) ;
V_109 ++ ;
}
F_53 ( V_57 , V_109 ) ;
F_54 ( V_57 ) ;
return V_108 ;
}
static void F_55 ( struct V_56 * V_57 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
F_39 ( V_57 ) ;
F_45 ( V_8 -> V_46 ) ;
F_56 ( & V_8 -> V_77 ) ;
}
static int F_57 ( struct V_56 * V_57 , struct V_104 * V_105 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
int V_108 ;
V_57 -> V_63 = 10000 ;
V_8 -> V_64 = 100 ;
V_8 -> V_69 = 2 * F_58 ( F_59 ( V_57 ) ) ;
V_8 -> V_52 = 10 * F_58 ( F_59 ( V_57 ) ) ;
V_8 -> V_68 = F_60 ( 40 ) ;
V_8 -> V_80 = ~ 0U ;
V_8 -> V_79 = 1 ;
V_8 -> V_67 . V_25 = NULL ;
V_8 -> V_73 . V_25 = NULL ;
V_8 -> V_11 = V_90 ;
V_8 -> V_46 = NULL ;
V_8 -> V_48 = F_50 ( 1024 ) ;
F_61 ( & V_8 -> V_77 , V_57 ) ;
if ( V_105 )
V_108 = F_46 ( V_57 , V_105 ) ;
else
V_108 = F_43 ( V_8 , V_8 -> V_48 ) ;
return V_108 ;
}
static int F_62 ( struct V_56 * V_57 , struct V_40 * V_41 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
struct V_104 * V_125 ;
V_125 = F_63 ( V_41 , V_126 ) ;
if ( V_125 == NULL )
goto V_127;
if ( F_64 ( V_41 , V_115 , V_57 -> V_63 ) ||
F_64 ( V_41 , V_116 , V_8 -> V_64 ) ||
F_64 ( V_41 , V_117 , V_8 -> V_69 ) ||
F_64 ( V_41 , V_118 , V_8 -> V_52 ) ||
F_64 ( V_41 , V_121 , V_8 -> V_79 ) ||
F_64 ( V_41 , V_120 , V_8 -> V_80 ) ||
F_64 ( V_41 , V_123 ,
F_65 ( V_8 -> V_68 ) ) ||
F_64 ( V_41 , V_113 , V_8 -> V_48 ) )
goto V_127;
F_66 ( V_41 , V_125 ) ;
return V_41 -> V_85 ;
V_127:
return - 1 ;
}
static int F_67 ( struct V_56 * V_57 , struct V_128 * V_129 )
{
struct V_7 * V_8 = F_24 ( V_57 ) ;
T_1 V_72 = F_31 ( F_32 () ) ;
struct V_130 V_131 = {
. V_132 = V_8 -> V_38 ,
. V_133 = V_8 -> V_70 ,
. V_134 = V_8 -> V_66 ,
. V_20 = V_8 -> V_19 ,
. V_135 = V_8 -> V_65 ,
. V_136 = V_8 -> V_88 ,
. V_137 = V_8 -> V_55 ,
. V_36 = V_8 -> V_36 ,
. V_37 = V_8 -> V_37 ,
. V_18 = V_8 -> V_18 ,
. V_21 = V_8 -> V_21 - V_72 ,
} ;
return F_68 ( V_129 , & V_131 , sizeof( V_131 ) ) ;
}
static int T_2 F_69 ( void )
{
int V_138 ;
V_39 = F_70 ( L_2 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_39 )
return - V_103 ;
V_138 = F_71 ( & V_139 ) ;
if ( V_138 )
F_72 ( V_39 ) ;
return V_138 ;
}
static void T_3 F_73 ( void )
{
F_74 ( & V_139 ) ;
F_72 ( V_39 ) ;
}
