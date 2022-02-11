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
if ( ! V_31 || F_15 ( V_31 ) ) {
unsigned long V_46 = F_16 ( V_41 ) & V_8 -> V_47 ;
V_31 = (struct V_30 * ) ( ( V_46 << 1 ) | 1UL ) ;
F_17 ( V_41 ) ;
}
V_29 = & V_8 -> V_48 [ F_18 ( ( V_49 ) ( long ) V_31 , V_8 -> V_50 ) ] ;
if ( V_8 -> V_36 >= ( 2U << V_8 -> V_50 ) &&
V_8 -> V_37 > V_8 -> V_36 / 2 )
F_10 ( V_8 , V_29 , V_31 ) ;
V_10 = & V_29 -> V_9 ;
V_12 = NULL ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_2 = F_4 ( V_12 , struct V_1 , V_35 ) ;
if ( V_2 -> V_31 == V_31 ) {
if ( F_14 ( V_41 -> V_31 &&
V_2 -> V_51 != V_31 -> V_52 ) ) {
V_2 -> V_53 = V_8 -> V_54 ;
V_2 -> V_51 = V_31 -> V_52 ;
V_2 -> V_15 = 0ULL ;
}
return V_2 ;
}
if ( V_2 -> V_31 > V_31 )
V_10 = & V_12 -> V_16 ;
else
V_10 = & V_12 -> V_17 ;
}
V_2 = F_19 ( V_39 , V_55 | V_56 ) ;
if ( F_14 ( ! V_2 ) ) {
V_8 -> V_57 ++ ;
return & V_8 -> V_45 ;
}
F_1 ( V_2 ) ;
V_2 -> V_31 = V_31 ;
if ( V_41 -> V_31 )
V_2 -> V_51 = V_31 -> V_52 ;
V_2 -> V_53 = V_8 -> V_54 ;
F_5 ( & V_2 -> V_35 , V_12 , V_10 ) ;
F_6 ( & V_2 -> V_35 , V_29 ) ;
V_8 -> V_36 ++ ;
V_8 -> V_37 ++ ;
return V_2 ;
}
static struct V_40 * F_20 ( struct V_58 * V_59 , struct V_1 * V_24 )
{
struct V_40 * V_41 = V_24 -> V_23 ;
if ( V_41 ) {
V_24 -> V_23 = V_41 -> V_3 ;
V_41 -> V_3 = NULL ;
V_24 -> V_60 -- ;
F_21 ( V_59 , V_41 ) ;
V_59 -> V_8 . V_60 -- ;
}
return V_41 ;
}
static bool F_22 ( struct V_40 * V_41 )
{
return false ;
}
static void F_23 ( struct V_1 * V_24 , struct V_40 * V_41 )
{
struct V_40 * V_61 , * V_23 = V_24 -> V_23 ;
V_41 -> V_3 = NULL ;
if ( ! V_23 ) {
V_24 -> V_23 = V_41 ;
V_24 -> V_62 = V_41 ;
return;
}
if ( F_24 ( ! F_22 ( V_41 ) ) ) {
V_24 -> V_62 -> V_3 = V_41 ;
V_24 -> V_62 = V_41 ;
return;
}
V_61 = NULL ;
while ( F_22 ( V_23 ) ) {
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
static int F_25 ( struct V_40 * V_41 , struct V_58 * V_59 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
struct V_1 * V_2 ;
if ( F_14 ( V_59 -> V_8 . V_60 >= V_59 -> V_63 ) )
return F_27 ( V_41 , V_59 ) ;
V_2 = F_13 ( V_41 , V_8 ) ;
if ( F_14 ( V_2 -> V_60 >= V_8 -> V_64 && V_2 != & V_8 -> V_45 ) ) {
V_8 -> V_65 ++ ;
return F_27 ( V_41 , V_59 ) ;
}
V_2 -> V_60 ++ ;
if ( F_22 ( V_41 ) )
V_8 -> V_66 ++ ;
F_28 ( V_59 , V_41 ) ;
if ( F_2 ( V_2 ) ) {
F_7 ( & V_8 -> V_67 , V_2 ) ;
if ( F_9 ( V_6 , V_2 -> V_5 + V_8 -> V_68 ) )
V_2 -> V_53 = F_29 ( V_49 , V_2 -> V_53 , V_8 -> V_69 ) ;
V_8 -> V_37 -- ;
}
F_23 ( V_2 , V_41 ) ;
if ( F_14 ( V_2 == & V_8 -> V_45 ) ) {
V_8 -> V_70 ++ ;
}
V_59 -> V_8 . V_60 ++ ;
return V_71 ;
}
static void F_30 ( struct V_7 * V_8 , T_1 V_72 )
{
struct V_9 * V_10 ;
if ( V_8 -> V_21 > V_72 )
return;
V_8 -> V_21 = ~ 0ULL ;
while ( ( V_10 = F_31 ( & V_8 -> V_11 ) ) != NULL ) {
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
static struct V_40 * F_32 ( struct V_58 * V_59 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
T_1 V_72 = F_33 () ;
struct V_22 * V_23 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
V_49 V_74 ;
V_41 = F_20 ( V_59 , & V_8 -> V_45 ) ;
if ( V_41 )
goto V_75;
F_30 ( V_8 , V_72 ) ;
V_76:
V_23 = & V_8 -> V_67 ;
if ( ! V_23 -> V_25 ) {
V_23 = & V_8 -> V_73 ;
if ( ! V_23 -> V_25 ) {
if ( V_8 -> V_21 != ~ 0ULL )
F_34 ( & V_8 -> V_77 ,
V_8 -> V_21 ,
false ) ;
return NULL ;
}
}
V_2 = V_23 -> V_25 ;
if ( V_2 -> V_53 <= 0 ) {
V_2 -> V_53 += V_8 -> V_69 ;
V_23 -> V_25 = V_2 -> V_3 ;
F_7 ( & V_8 -> V_73 , V_2 ) ;
goto V_76;
}
V_41 = V_2 -> V_23 ;
if ( F_14 ( V_41 && V_72 < V_2 -> V_15 &&
! F_35 ( V_41 ) ) ) {
V_23 -> V_25 = V_2 -> V_3 ;
F_3 ( V_8 , V_2 ) ;
goto V_76;
}
V_41 = F_20 ( V_59 , V_2 ) ;
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
F_36 ( & V_41 -> V_78 ) ;
V_2 -> V_53 -= F_37 ( V_41 ) ;
if ( V_2 -> V_53 > 0 || ! V_8 -> V_79 )
goto V_75;
if ( F_35 ( V_41 ) )
goto V_75;
V_74 = V_8 -> V_80 ;
if ( V_41 -> V_31 )
V_74 = F_38 ( V_41 -> V_31 -> V_81 , V_74 ) ;
if ( V_74 != ~ 0U ) {
V_49 V_82 = F_39 ( F_37 ( V_41 ) , V_8 -> V_69 ) ;
T_1 V_83 = ( T_1 ) V_82 * V_84 ;
if ( F_24 ( V_74 ) )
F_40 ( V_83 , V_74 ) ;
if ( F_14 ( V_83 > V_84 ) ) {
V_83 = V_84 ;
V_8 -> V_85 ++ ;
}
V_2 -> V_15 = V_72 + V_83 ;
}
V_75:
F_41 ( V_59 , V_41 ) ;
return V_41 ;
}
static void F_42 ( struct V_58 * V_59 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
struct V_28 * V_29 ;
struct V_40 * V_41 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned int V_86 ;
while ( ( V_41 = F_20 ( V_59 , & V_8 -> V_45 ) ) != NULL )
F_43 ( V_41 ) ;
if ( ! V_8 -> V_48 )
return;
for ( V_86 = 0 ; V_86 < ( 1U << V_8 -> V_50 ) ; V_86 ++ ) {
V_29 = & V_8 -> V_48 [ V_86 ] ;
while ( ( V_10 = F_31 ( V_29 ) ) != NULL ) {
V_2 = F_4 ( V_10 , struct V_1 , V_35 ) ;
F_11 ( V_10 , V_29 ) ;
while ( ( V_41 = F_20 ( V_59 , V_2 ) ) != NULL )
F_43 ( V_41 ) ;
F_12 ( V_39 , V_2 ) ;
}
}
V_8 -> V_67 . V_25 = NULL ;
V_8 -> V_73 . V_25 = NULL ;
V_8 -> V_11 = V_87 ;
V_8 -> V_36 = 0 ;
V_8 -> V_37 = 0 ;
V_8 -> V_18 = 0 ;
}
static void F_44 ( struct V_7 * V_8 ,
struct V_28 * V_88 , V_49 V_89 ,
struct V_28 * V_90 , V_49 V_91 )
{
struct V_9 * V_92 , * * V_93 , * V_12 ;
struct V_28 * V_94 , * V_95 ;
struct V_1 * V_96 , * V_97 ;
int V_34 = 0 ;
V_49 V_86 ;
for ( V_86 = 0 ; V_86 < ( 1U << V_89 ) ; V_86 ++ ) {
V_94 = & V_88 [ V_86 ] ;
while ( ( V_92 = F_31 ( V_94 ) ) != NULL ) {
F_11 ( V_92 , V_94 ) ;
V_96 = F_4 ( V_92 , struct V_1 , V_35 ) ;
if ( F_8 ( V_96 ) ) {
V_34 ++ ;
F_12 ( V_39 , V_96 ) ;
continue;
}
V_95 = & V_90 [ F_18 ( ( V_49 ) ( long ) V_96 -> V_31 , V_91 ) ] ;
V_93 = & V_95 -> V_9 ;
V_12 = NULL ;
while ( * V_93 ) {
V_12 = * V_93 ;
V_97 = F_4 ( V_12 , struct V_1 , V_35 ) ;
F_45 ( V_97 -> V_31 == V_96 -> V_31 ) ;
if ( V_97 -> V_31 > V_96 -> V_31 )
V_93 = & V_12 -> V_16 ;
else
V_93 = & V_12 -> V_17 ;
}
F_5 ( & V_96 -> V_35 , V_12 , V_93 ) ;
F_6 ( & V_96 -> V_35 , V_95 ) ;
}
}
V_8 -> V_36 -= V_34 ;
V_8 -> V_37 -= V_34 ;
V_8 -> V_38 += V_34 ;
}
static void * F_46 ( T_2 V_98 , int V_99 )
{
void * V_100 ;
V_100 = F_47 ( V_98 , V_101 | V_102 | V_56 , V_99 ) ;
if ( ! V_100 )
V_100 = F_48 ( V_98 , V_99 ) ;
return V_100 ;
}
static void F_49 ( void * V_103 )
{
F_50 ( V_103 ) ;
}
static int F_51 ( struct V_58 * V_59 , V_49 log )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
struct V_28 * V_104 ;
void * V_105 ;
V_49 V_86 ;
if ( V_8 -> V_48 && log == V_8 -> V_50 )
return 0 ;
V_104 = F_46 ( sizeof( struct V_28 ) << log ,
F_52 ( V_59 -> V_106 ) ) ;
if ( ! V_104 )
return - V_107 ;
for ( V_86 = 0 ; V_86 < ( 1U << log ) ; V_86 ++ )
V_104 [ V_86 ] = V_87 ;
F_53 ( V_59 ) ;
V_105 = V_8 -> V_48 ;
if ( V_105 )
F_44 ( V_8 , V_105 , V_8 -> V_50 , V_104 , log ) ;
V_8 -> V_48 = V_104 ;
V_8 -> V_50 = log ;
F_54 ( V_59 ) ;
F_49 ( V_105 ) ;
return 0 ;
}
static int F_55 ( struct V_58 * V_59 , struct V_108 * V_109 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
struct V_108 * V_110 [ V_111 + 1 ] ;
int V_112 , V_113 = 0 ;
unsigned V_114 = 0 ;
V_49 V_115 ;
if ( ! V_109 )
return - V_116 ;
V_112 = F_56 ( V_110 , V_111 , V_109 , V_117 ) ;
if ( V_112 < 0 )
return V_112 ;
F_53 ( V_59 ) ;
V_115 = V_8 -> V_50 ;
if ( V_110 [ V_118 ] ) {
V_49 V_119 = F_57 ( V_110 [ V_118 ] ) ;
if ( V_119 >= 1 && V_119 <= F_58 ( 256 * 1024 ) )
V_115 = V_119 ;
else
V_112 = - V_116 ;
}
if ( V_110 [ V_120 ] )
V_59 -> V_63 = F_57 ( V_110 [ V_120 ] ) ;
if ( V_110 [ V_121 ] )
V_8 -> V_64 = F_57 ( V_110 [ V_121 ] ) ;
if ( V_110 [ V_122 ] ) {
V_49 V_69 = F_57 ( V_110 [ V_122 ] ) ;
if ( V_69 > 0 )
V_8 -> V_69 = V_69 ;
else
V_112 = - V_116 ;
}
if ( V_110 [ V_123 ] )
V_8 -> V_54 = F_57 ( V_110 [ V_123 ] ) ;
if ( V_110 [ V_124 ] )
F_59 ( L_1 ,
F_57 ( V_110 [ V_124 ] ) ) ;
if ( V_110 [ V_125 ] )
V_8 -> V_80 = F_57 ( V_110 [ V_125 ] ) ;
if ( V_110 [ V_126 ] ) {
V_49 V_127 = F_57 ( V_110 [ V_126 ] ) ;
if ( V_127 <= 1 )
V_8 -> V_79 = V_127 ;
else
V_112 = - V_116 ;
}
if ( V_110 [ V_128 ] ) {
V_49 V_129 = F_57 ( V_110 [ V_128 ] ) ;
V_8 -> V_68 = F_60 ( V_129 ) ;
}
if ( V_110 [ V_130 ] )
V_8 -> V_47 = F_57 ( V_110 [ V_130 ] ) ;
if ( ! V_112 ) {
F_54 ( V_59 ) ;
V_112 = F_51 ( V_59 , V_115 ) ;
F_53 ( V_59 ) ;
}
while ( V_59 -> V_8 . V_60 > V_59 -> V_63 ) {
struct V_40 * V_41 = F_32 ( V_59 ) ;
if ( ! V_41 )
break;
V_114 += F_37 ( V_41 ) ;
F_43 ( V_41 ) ;
V_113 ++ ;
}
F_61 ( V_59 , V_113 , V_114 ) ;
F_54 ( V_59 ) ;
return V_112 ;
}
static void F_62 ( struct V_58 * V_59 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
F_42 ( V_59 ) ;
F_49 ( V_8 -> V_48 ) ;
F_63 ( & V_8 -> V_77 ) ;
}
static int F_64 ( struct V_58 * V_59 , struct V_108 * V_109 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
int V_112 ;
V_59 -> V_63 = 10000 ;
V_8 -> V_64 = 100 ;
V_8 -> V_69 = 2 * F_65 ( F_66 ( V_59 ) ) ;
V_8 -> V_54 = 10 * F_65 ( F_66 ( V_59 ) ) ;
V_8 -> V_68 = F_67 ( 40 ) ;
V_8 -> V_80 = ~ 0U ;
V_8 -> V_79 = 1 ;
V_8 -> V_67 . V_25 = NULL ;
V_8 -> V_73 . V_25 = NULL ;
V_8 -> V_11 = V_87 ;
V_8 -> V_48 = NULL ;
V_8 -> V_50 = F_58 ( 1024 ) ;
V_8 -> V_47 = 1024 - 1 ;
F_68 ( & V_8 -> V_77 , V_59 ) ;
if ( V_109 )
V_112 = F_55 ( V_59 , V_109 ) ;
else
V_112 = F_51 ( V_59 , V_8 -> V_50 ) ;
return V_112 ;
}
static int F_69 ( struct V_58 * V_59 , struct V_40 * V_41 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
struct V_108 * V_131 ;
V_131 = F_70 ( V_41 , V_132 ) ;
if ( V_131 == NULL )
goto V_133;
if ( F_71 ( V_41 , V_120 , V_59 -> V_63 ) ||
F_71 ( V_41 , V_121 , V_8 -> V_64 ) ||
F_71 ( V_41 , V_122 , V_8 -> V_69 ) ||
F_71 ( V_41 , V_123 , V_8 -> V_54 ) ||
F_71 ( V_41 , V_126 , V_8 -> V_79 ) ||
F_71 ( V_41 , V_125 , V_8 -> V_80 ) ||
F_71 ( V_41 , V_128 ,
F_72 ( V_8 -> V_68 ) ) ||
F_71 ( V_41 , V_130 , V_8 -> V_47 ) ||
F_71 ( V_41 , V_118 , V_8 -> V_50 ) )
goto V_133;
return F_73 ( V_41 , V_131 ) ;
V_133:
return - 1 ;
}
static int F_74 ( struct V_58 * V_59 , struct V_134 * V_135 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
T_1 V_72 = F_33 () ;
struct V_136 V_137 = {
. V_138 = V_8 -> V_38 ,
. V_139 = V_8 -> V_70 ,
. V_140 = V_8 -> V_66 ,
. V_20 = V_8 -> V_19 ,
. V_141 = V_8 -> V_65 ,
. V_142 = V_8 -> V_85 ,
. V_143 = V_8 -> V_57 ,
. V_36 = V_8 -> V_36 ,
. V_37 = V_8 -> V_37 ,
. V_18 = V_8 -> V_18 ,
. V_21 = V_8 -> V_21 - V_72 ,
} ;
return F_75 ( V_135 , & V_137 , sizeof( V_137 ) ) ;
}
static int T_3 F_76 ( void )
{
int V_144 ;
V_39 = F_77 ( L_2 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_39 )
return - V_107 ;
V_144 = F_78 ( & V_145 ) ;
if ( V_144 )
F_79 ( V_39 ) ;
return V_144 ;
}
static void T_4 F_80 ( void )
{
F_81 ( & V_145 ) ;
F_79 ( V_39 ) ;
}
