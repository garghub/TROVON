static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = & V_4 ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 == & V_4 ;
}
static void F_3 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_7 * * V_8 = & V_6 -> V_9 . V_7 , * V_10 = NULL ;
while ( * V_8 ) {
struct V_1 * V_11 ;
V_10 = * V_8 ;
V_11 = F_4 ( V_10 , struct V_1 , V_12 ) ;
if ( V_2 -> V_13 >= V_11 -> V_13 )
V_8 = & V_10 -> V_14 ;
else
V_8 = & V_10 -> V_15 ;
}
F_5 ( & V_2 -> V_12 , V_10 , V_8 ) ;
F_6 ( & V_2 -> V_12 , & V_6 -> V_9 ) ;
V_6 -> V_16 ++ ;
V_6 -> V_17 ++ ;
V_2 -> V_3 = & V_18 ;
if ( V_6 -> V_19 > V_2 -> V_13 )
V_6 -> V_19 = V_2 -> V_13 ;
}
static void F_7 ( struct V_20 * V_21 , struct V_1 * V_22 )
{
if ( V_21 -> V_23 )
V_21 -> V_24 -> V_3 = V_22 ;
else
V_21 -> V_23 = V_22 ;
V_21 -> V_24 = V_22 ;
V_22 -> V_3 = NULL ;
}
static bool F_8 ( const struct V_1 * V_2 )
{
return F_2 ( V_2 ) &&
F_9 ( V_25 , V_2 -> V_26 + V_27 ) ;
}
static void F_10 ( struct V_5 * V_6 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 , * V_32 [ V_33 ] ;
struct V_7 * * V_8 , * V_10 ;
int V_34 = 0 ;
V_8 = & V_29 -> V_7 ;
V_10 = NULL ;
while ( * V_8 ) {
V_10 = * V_8 ;
V_2 = F_4 ( V_10 , struct V_1 , V_35 ) ;
if ( V_2 -> V_31 == V_31 )
break;
if ( F_8 ( V_2 ) ) {
V_32 [ V_34 ++ ] = V_2 ;
if ( V_34 == V_33 )
break;
}
if ( V_2 -> V_31 > V_31 )
V_8 = & V_10 -> V_14 ;
else
V_8 = & V_10 -> V_15 ;
}
V_6 -> V_36 -= V_34 ;
V_6 -> V_37 -= V_34 ;
V_6 -> V_38 += V_34 ;
while ( V_34 ) {
struct V_1 * V_2 = V_32 [ -- V_34 ] ;
F_11 ( & V_2 -> V_35 , V_29 ) ;
F_12 ( V_39 , V_2 ) ;
}
}
static struct V_1 * F_13 ( struct V_40 * V_41 , struct V_5 * V_6 )
{
struct V_7 * * V_8 , * V_10 ;
struct V_30 * V_31 = V_41 -> V_31 ;
struct V_28 * V_29 ;
struct V_1 * V_2 ;
int V_42 ;
V_42 = V_43 [ V_41 -> V_44 & V_45 ] ;
if ( F_14 ( V_42 == 0 ) )
return & V_6 -> V_46 ;
if ( F_14 ( ! V_31 ) ) {
V_31 = (struct V_30 * ) ( F_15 ( V_41 ) | 1L ) ;
}
V_29 = & V_6 -> V_47 [ F_16 ( ( V_48 ) ( long ) V_31 , V_6 -> V_49 ) ] ;
if ( V_6 -> V_36 >= ( 2U << V_6 -> V_49 ) &&
V_6 -> V_37 > V_6 -> V_36 / 2 )
F_10 ( V_6 , V_29 , V_31 ) ;
V_8 = & V_29 -> V_7 ;
V_10 = NULL ;
while ( * V_8 ) {
V_10 = * V_8 ;
V_2 = F_4 ( V_10 , struct V_1 , V_35 ) ;
if ( V_2 -> V_31 == V_31 ) {
if ( F_14 ( V_41 -> V_31 &&
V_2 -> V_50 != V_31 -> V_51 ) ) {
V_2 -> V_52 = V_6 -> V_53 ;
V_2 -> V_50 = V_31 -> V_51 ;
}
return V_2 ;
}
if ( V_2 -> V_31 > V_31 )
V_8 = & V_10 -> V_14 ;
else
V_8 = & V_10 -> V_15 ;
}
V_2 = F_17 ( V_39 , V_54 | V_55 ) ;
if ( F_14 ( ! V_2 ) ) {
V_6 -> V_56 ++ ;
return & V_6 -> V_46 ;
}
F_1 ( V_2 ) ;
V_2 -> V_31 = V_31 ;
if ( V_41 -> V_31 )
V_2 -> V_50 = V_31 -> V_51 ;
V_2 -> V_52 = V_6 -> V_53 ;
F_5 ( & V_2 -> V_35 , V_10 , V_8 ) ;
F_6 ( & V_2 -> V_35 , V_29 ) ;
V_6 -> V_36 ++ ;
V_6 -> V_37 ++ ;
return V_2 ;
}
static struct V_40 * F_18 ( struct V_57 * V_58 , struct V_1 * V_22 )
{
struct V_40 * V_41 = V_22 -> V_21 ;
if ( V_41 ) {
V_22 -> V_21 = V_41 -> V_3 ;
V_41 -> V_3 = NULL ;
V_22 -> V_59 -- ;
V_58 -> V_60 . V_61 -= F_19 ( V_41 ) ;
V_58 -> V_6 . V_59 -- ;
}
return V_41 ;
}
static bool F_20 ( struct V_40 * V_41 )
{
return false ;
}
static void F_21 ( struct V_1 * V_22 , struct V_40 * V_41 )
{
struct V_40 * V_62 , * V_21 = V_22 -> V_21 ;
V_41 -> V_3 = NULL ;
if ( ! V_21 ) {
V_22 -> V_21 = V_41 ;
V_22 -> V_63 = V_41 ;
return;
}
if ( F_22 ( ! F_20 ( V_41 ) ) ) {
V_22 -> V_63 -> V_3 = V_41 ;
V_22 -> V_63 = V_41 ;
return;
}
V_62 = NULL ;
while ( F_20 ( V_21 ) ) {
V_62 = V_21 ;
V_21 = V_21 -> V_3 ;
if ( ! V_21 )
break;
}
if ( ! V_62 ) {
V_41 -> V_3 = V_22 -> V_21 ;
V_22 -> V_21 = V_41 ;
} else {
if ( V_62 == V_22 -> V_63 )
V_22 -> V_63 = V_41 ;
else
V_41 -> V_3 = V_62 -> V_3 ;
V_62 -> V_3 = V_41 ;
}
}
static int F_23 ( struct V_40 * V_41 , struct V_57 * V_58 )
{
struct V_5 * V_6 = F_24 ( V_58 ) ;
struct V_1 * V_2 ;
if ( F_14 ( V_58 -> V_6 . V_59 >= V_58 -> V_64 ) )
return F_25 ( V_41 , V_58 ) ;
V_2 = F_13 ( V_41 , V_6 ) ;
if ( F_14 ( V_2 -> V_59 >= V_6 -> V_65 && V_2 != & V_6 -> V_46 ) ) {
V_6 -> V_66 ++ ;
return F_25 ( V_41 , V_58 ) ;
}
V_2 -> V_59 ++ ;
F_21 ( V_2 , V_41 ) ;
if ( F_20 ( V_41 ) )
V_6 -> V_67 ++ ;
V_58 -> V_60 . V_61 += F_19 ( V_41 ) ;
if ( F_2 ( V_2 ) ) {
F_7 ( & V_6 -> V_68 , V_2 ) ;
if ( V_6 -> V_69 > V_2 -> V_52 )
V_2 -> V_52 = V_6 -> V_69 ;
V_6 -> V_37 -- ;
F_26 ( V_58 ) ;
}
if ( F_14 ( V_2 == & V_6 -> V_46 ) ) {
V_6 -> V_70 ++ ;
F_26 ( V_58 ) ;
}
V_58 -> V_6 . V_59 ++ ;
return V_71 ;
}
static void F_27 ( struct V_5 * V_6 , T_1 V_72 )
{
struct V_7 * V_8 ;
if ( V_6 -> V_19 > V_72 )
return;
V_6 -> V_19 = ~ 0ULL ;
while ( ( V_8 = F_28 ( & V_6 -> V_9 ) ) != NULL ) {
struct V_1 * V_2 = F_4 ( V_8 , struct V_1 , V_12 ) ;
if ( V_2 -> V_13 > V_72 ) {
V_6 -> V_19 = V_2 -> V_13 ;
break;
}
F_11 ( V_8 , & V_6 -> V_9 ) ;
V_6 -> V_16 -- ;
F_7 ( & V_6 -> V_73 , V_2 ) ;
}
}
static struct V_40 * F_29 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_24 ( V_58 ) ;
T_1 V_72 = F_30 ( F_31 () ) ;
struct V_20 * V_21 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
V_48 V_74 ;
V_41 = F_18 ( V_58 , & V_6 -> V_46 ) ;
if ( V_41 )
goto V_75;
F_27 ( V_6 , V_72 ) ;
V_76:
V_21 = & V_6 -> V_68 ;
if ( ! V_21 -> V_23 ) {
V_21 = & V_6 -> V_73 ;
if ( ! V_21 -> V_23 ) {
if ( V_6 -> V_19 != ~ 0ULL )
F_32 ( & V_6 -> V_77 ,
V_6 -> V_19 ) ;
return NULL ;
}
}
V_2 = V_21 -> V_23 ;
if ( V_2 -> V_52 <= 0 ) {
V_2 -> V_52 += V_6 -> V_69 ;
V_21 -> V_23 = V_2 -> V_3 ;
F_7 ( & V_6 -> V_73 , V_2 ) ;
goto V_76;
}
if ( F_14 ( V_2 -> V_21 && V_72 < V_2 -> V_13 ) ) {
V_21 -> V_23 = V_2 -> V_3 ;
F_3 ( V_6 , V_2 ) ;
goto V_76;
}
V_41 = F_18 ( V_58 , V_2 ) ;
if ( ! V_41 ) {
V_21 -> V_23 = V_2 -> V_3 ;
if ( ( V_21 == & V_6 -> V_68 ) && V_6 -> V_73 . V_23 ) {
F_7 ( & V_6 -> V_73 , V_2 ) ;
} else {
F_1 ( V_2 ) ;
V_2 -> V_26 = V_25 ;
V_6 -> V_37 ++ ;
}
goto V_76;
}
F_33 ( & V_41 -> V_78 ) ;
V_2 -> V_13 = V_72 ;
V_2 -> V_52 -= F_19 ( V_41 ) ;
if ( V_2 -> V_52 > 0 || ! V_6 -> V_79 )
goto V_75;
V_74 = V_6 -> V_80 ;
if ( V_41 -> V_31 && V_41 -> V_31 -> V_81 != V_82 )
V_74 = F_34 ( V_41 -> V_31 -> V_83 , V_74 ) ;
if ( V_74 != ~ 0U ) {
V_48 V_84 = F_35 ( F_19 ( V_41 ) , V_6 -> V_69 ) ;
T_1 V_85 = ( T_1 ) V_84 * V_86 ;
if ( F_22 ( V_74 ) )
F_36 ( V_85 , V_74 ) ;
if ( F_14 ( V_85 > 125 * V_87 ) ) {
V_85 = 125 * V_87 ;
V_6 -> V_88 ++ ;
}
V_2 -> V_13 = V_72 + V_85 ;
}
V_75:
F_37 ( V_58 , V_41 ) ;
F_26 ( V_58 ) ;
return V_41 ;
}
static void F_38 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_24 ( V_58 ) ;
struct V_28 * V_29 ;
struct V_40 * V_41 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned int V_89 ;
while ( ( V_41 = F_18 ( V_58 , & V_6 -> V_46 ) ) != NULL )
F_39 ( V_41 ) ;
if ( ! V_6 -> V_47 )
return;
for ( V_89 = 0 ; V_89 < ( 1U << V_6 -> V_49 ) ; V_89 ++ ) {
V_29 = & V_6 -> V_47 [ V_89 ] ;
while ( ( V_8 = F_28 ( V_29 ) ) != NULL ) {
V_2 = F_4 ( V_8 , struct V_1 , V_35 ) ;
F_11 ( V_8 , V_29 ) ;
while ( ( V_41 = F_18 ( V_58 , V_2 ) ) != NULL )
F_39 ( V_41 ) ;
F_12 ( V_39 , V_2 ) ;
}
}
V_6 -> V_68 . V_23 = NULL ;
V_6 -> V_73 . V_23 = NULL ;
V_6 -> V_9 = V_90 ;
V_6 -> V_36 = 0 ;
V_6 -> V_37 = 0 ;
V_6 -> V_16 = 0 ;
}
static void F_40 ( struct V_5 * V_6 ,
struct V_28 * V_91 , V_48 V_92 ,
struct V_28 * V_93 , V_48 V_94 )
{
struct V_7 * V_95 , * * V_96 , * V_10 ;
struct V_28 * V_97 , * V_98 ;
struct V_1 * V_99 , * V_100 ;
int V_34 = 0 ;
V_48 V_89 ;
for ( V_89 = 0 ; V_89 < ( 1U << V_92 ) ; V_89 ++ ) {
V_97 = & V_91 [ V_89 ] ;
while ( ( V_95 = F_28 ( V_97 ) ) != NULL ) {
F_11 ( V_95 , V_97 ) ;
V_99 = F_4 ( V_95 , struct V_1 , V_35 ) ;
if ( F_8 ( V_99 ) ) {
V_34 ++ ;
F_12 ( V_39 , V_99 ) ;
continue;
}
V_98 = & V_93 [ F_16 ( ( V_48 ) ( long ) V_99 -> V_31 , V_94 ) ] ;
V_96 = & V_98 -> V_7 ;
V_10 = NULL ;
while ( * V_96 ) {
V_10 = * V_96 ;
V_100 = F_4 ( V_10 , struct V_1 , V_35 ) ;
F_41 ( V_100 -> V_31 == V_99 -> V_31 ) ;
if ( V_100 -> V_31 > V_99 -> V_31 )
V_96 = & V_10 -> V_14 ;
else
V_96 = & V_10 -> V_15 ;
}
F_5 ( & V_99 -> V_35 , V_10 , V_96 ) ;
F_6 ( & V_99 -> V_35 , V_98 ) ;
}
}
V_6 -> V_36 -= V_34 ;
V_6 -> V_37 -= V_34 ;
V_6 -> V_38 += V_34 ;
}
static int F_42 ( struct V_5 * V_6 , V_48 log )
{
struct V_28 * V_101 ;
V_48 V_89 ;
if ( V_6 -> V_47 && log == V_6 -> V_49 )
return 0 ;
V_101 = F_43 ( sizeof( struct V_28 ) << log , V_102 ) ;
if ( ! V_101 )
return - V_103 ;
for ( V_89 = 0 ; V_89 < ( 1U << log ) ; V_89 ++ )
V_101 [ V_89 ] = V_90 ;
if ( V_6 -> V_47 ) {
F_40 ( V_6 , V_6 -> V_47 , V_6 -> V_49 , V_101 , log ) ;
F_44 ( V_6 -> V_47 ) ;
}
V_6 -> V_47 = V_101 ;
V_6 -> V_49 = log ;
return 0 ;
}
static int F_45 ( struct V_57 * V_58 , struct V_104 * V_105 )
{
struct V_5 * V_6 = F_24 ( V_58 ) ;
struct V_104 * V_106 [ V_107 + 1 ] ;
int V_108 , V_109 = 0 ;
V_48 V_110 ;
if ( ! V_105 )
return - V_111 ;
V_108 = F_46 ( V_106 , V_107 , V_105 , V_112 ) ;
if ( V_108 < 0 )
return V_108 ;
F_47 ( V_58 ) ;
V_110 = V_6 -> V_49 ;
if ( V_106 [ V_113 ] ) {
V_48 V_114 = F_48 ( V_106 [ V_113 ] ) ;
if ( V_114 >= 1 && V_114 <= F_49 ( 256 * 1024 ) )
V_110 = V_114 ;
else
V_108 = - V_111 ;
}
if ( V_106 [ V_115 ] )
V_58 -> V_64 = F_48 ( V_106 [ V_115 ] ) ;
if ( V_106 [ V_116 ] )
V_6 -> V_65 = F_48 ( V_106 [ V_116 ] ) ;
if ( V_106 [ V_117 ] )
V_6 -> V_69 = F_48 ( V_106 [ V_117 ] ) ;
if ( V_106 [ V_118 ] )
V_6 -> V_53 = F_48 ( V_106 [ V_118 ] ) ;
if ( V_106 [ V_119 ] )
V_6 -> V_120 = F_48 ( V_106 [ V_119 ] ) ;
if ( V_106 [ V_121 ] )
V_6 -> V_80 = F_48 ( V_106 [ V_121 ] ) ;
if ( V_106 [ V_122 ] ) {
V_48 V_123 = F_48 ( V_106 [ V_122 ] ) ;
if ( V_123 <= 1 )
V_6 -> V_79 = V_123 ;
else
V_108 = - V_111 ;
}
if ( ! V_108 )
V_108 = F_42 ( V_6 , V_110 ) ;
while ( V_58 -> V_6 . V_59 > V_58 -> V_64 ) {
struct V_40 * V_41 = F_29 ( V_58 ) ;
if ( ! V_41 )
break;
F_39 ( V_41 ) ;
V_109 ++ ;
}
F_50 ( V_58 , V_109 ) ;
F_51 ( V_58 ) ;
return V_108 ;
}
static void F_52 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_24 ( V_58 ) ;
F_38 ( V_58 ) ;
F_44 ( V_6 -> V_47 ) ;
F_53 ( & V_6 -> V_77 ) ;
}
static int F_54 ( struct V_57 * V_58 , struct V_104 * V_105 )
{
struct V_5 * V_6 = F_24 ( V_58 ) ;
int V_108 ;
V_58 -> V_64 = 10000 ;
V_6 -> V_65 = 100 ;
V_6 -> V_69 = 2 * F_55 ( F_56 ( V_58 ) ) ;
V_6 -> V_53 = 10 * F_55 ( F_56 ( V_58 ) ) ;
V_6 -> V_120 = 0 ;
V_6 -> V_80 = ~ 0U ;
V_6 -> V_79 = 1 ;
V_6 -> V_68 . V_23 = NULL ;
V_6 -> V_73 . V_23 = NULL ;
V_6 -> V_9 = V_90 ;
V_6 -> V_47 = NULL ;
V_6 -> V_49 = F_49 ( 1024 ) ;
F_57 ( & V_6 -> V_77 , V_58 ) ;
if ( V_105 )
V_108 = F_45 ( V_58 , V_105 ) ;
else
V_108 = F_42 ( V_6 , V_6 -> V_49 ) ;
return V_108 ;
}
static int F_58 ( struct V_57 * V_58 , struct V_40 * V_41 )
{
struct V_5 * V_6 = F_24 ( V_58 ) ;
struct V_104 * V_124 ;
V_124 = F_59 ( V_41 , V_125 ) ;
if ( V_124 == NULL )
goto V_126;
if ( F_60 ( V_41 , V_115 , V_58 -> V_64 ) ||
F_60 ( V_41 , V_116 , V_6 -> V_65 ) ||
F_60 ( V_41 , V_117 , V_6 -> V_69 ) ||
F_60 ( V_41 , V_118 , V_6 -> V_53 ) ||
F_60 ( V_41 , V_122 , V_6 -> V_79 ) ||
F_60 ( V_41 , V_121 , V_6 -> V_80 ) ||
F_60 ( V_41 , V_113 , V_6 -> V_49 ) )
goto V_126;
F_61 ( V_41 , V_124 ) ;
return V_41 -> V_85 ;
V_126:
return - 1 ;
}
static int F_62 ( struct V_57 * V_58 , struct V_127 * V_128 )
{
struct V_5 * V_6 = F_24 ( V_58 ) ;
T_1 V_72 = F_30 ( F_31 () ) ;
struct V_129 V_130 = {
. V_131 = V_6 -> V_38 ,
. V_132 = V_6 -> V_70 ,
. V_133 = V_6 -> V_67 ,
. V_18 = V_6 -> V_17 ,
. V_134 = V_6 -> V_66 ,
. V_135 = V_6 -> V_88 ,
. V_136 = V_6 -> V_56 ,
. V_36 = V_6 -> V_36 ,
. V_37 = V_6 -> V_37 ,
. V_16 = V_6 -> V_16 ,
. V_19 = V_6 -> V_19 - V_72 ,
} ;
return F_63 ( V_128 , & V_130 , sizeof( V_130 ) ) ;
}
static int T_2 F_64 ( void )
{
int V_137 ;
V_39 = F_65 ( L_1 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_39 )
return - V_103 ;
V_137 = F_66 ( & V_138 ) ;
if ( V_137 )
F_67 ( V_39 ) ;
return V_137 ;
}
static void T_3 F_68 ( void )
{
F_69 ( & V_138 ) ;
F_67 ( V_39 ) ;
}
