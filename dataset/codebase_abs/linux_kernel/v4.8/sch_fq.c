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
static int F_25 ( struct V_40 * V_41 , struct V_58 * V_59 ,
struct V_40 * * V_63 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
struct V_1 * V_2 ;
if ( F_14 ( V_59 -> V_8 . V_60 >= V_59 -> V_64 ) )
return F_27 ( V_41 , V_59 , V_63 ) ;
V_2 = F_13 ( V_41 , V_8 ) ;
if ( F_14 ( V_2 -> V_60 >= V_8 -> V_65 && V_2 != & V_8 -> V_45 ) ) {
V_8 -> V_66 ++ ;
return F_27 ( V_41 , V_59 , V_63 ) ;
}
V_2 -> V_60 ++ ;
if ( F_22 ( V_41 ) )
V_8 -> V_67 ++ ;
F_28 ( V_59 , V_41 ) ;
if ( F_2 ( V_2 ) ) {
F_7 ( & V_8 -> V_68 , V_2 ) ;
if ( F_9 ( V_6 , V_2 -> V_5 + V_8 -> V_69 ) )
V_2 -> V_53 = F_29 ( V_49 , V_2 -> V_53 , V_8 -> V_70 ) ;
V_8 -> V_37 -- ;
}
F_23 ( V_2 , V_41 ) ;
if ( F_14 ( V_2 == & V_8 -> V_45 ) ) {
V_8 -> V_71 ++ ;
}
V_59 -> V_8 . V_60 ++ ;
return V_72 ;
}
static void F_30 ( struct V_7 * V_8 , T_1 V_73 )
{
struct V_9 * V_10 ;
if ( V_8 -> V_21 > V_73 )
return;
V_8 -> V_21 = ~ 0ULL ;
while ( ( V_10 = F_31 ( & V_8 -> V_11 ) ) != NULL ) {
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_14 ) ;
if ( V_2 -> V_15 > V_73 ) {
V_8 -> V_21 = V_2 -> V_15 ;
break;
}
F_11 ( V_10 , & V_8 -> V_11 ) ;
V_8 -> V_18 -- ;
F_7 ( & V_8 -> V_74 , V_2 ) ;
}
}
static struct V_40 * F_32 ( struct V_58 * V_59 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
T_1 V_73 = F_33 () ;
struct V_22 * V_23 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
V_49 V_75 ;
V_41 = F_20 ( V_59 , & V_8 -> V_45 ) ;
if ( V_41 )
goto V_76;
F_30 ( V_8 , V_73 ) ;
V_77:
V_23 = & V_8 -> V_68 ;
if ( ! V_23 -> V_25 ) {
V_23 = & V_8 -> V_74 ;
if ( ! V_23 -> V_25 ) {
if ( V_8 -> V_21 != ~ 0ULL )
F_34 ( & V_8 -> V_78 ,
V_8 -> V_21 ) ;
return NULL ;
}
}
V_2 = V_23 -> V_25 ;
if ( V_2 -> V_53 <= 0 ) {
V_2 -> V_53 += V_8 -> V_70 ;
V_23 -> V_25 = V_2 -> V_3 ;
F_7 ( & V_8 -> V_74 , V_2 ) ;
goto V_77;
}
V_41 = V_2 -> V_23 ;
if ( F_14 ( V_41 && V_73 < V_2 -> V_15 &&
! F_35 ( V_41 ) ) ) {
V_23 -> V_25 = V_2 -> V_3 ;
F_3 ( V_8 , V_2 ) ;
goto V_77;
}
V_41 = F_20 ( V_59 , V_2 ) ;
if ( ! V_41 ) {
V_23 -> V_25 = V_2 -> V_3 ;
if ( ( V_23 == & V_8 -> V_68 ) && V_8 -> V_74 . V_25 ) {
F_7 ( & V_8 -> V_74 , V_2 ) ;
} else {
F_1 ( V_2 ) ;
V_8 -> V_37 ++ ;
}
goto V_77;
}
F_36 ( & V_41 -> V_79 ) ;
V_2 -> V_53 -= F_37 ( V_41 ) ;
if ( V_2 -> V_53 > 0 || ! V_8 -> V_80 )
goto V_76;
if ( F_35 ( V_41 ) )
goto V_76;
V_75 = V_8 -> V_81 ;
if ( V_41 -> V_31 )
V_75 = F_38 ( V_41 -> V_31 -> V_82 , V_75 ) ;
if ( V_75 != ~ 0U ) {
V_49 V_83 = F_39 ( F_37 ( V_41 ) , V_8 -> V_70 ) ;
T_1 V_84 = ( T_1 ) V_83 * V_85 ;
if ( F_24 ( V_75 ) )
F_40 ( V_84 , V_75 ) ;
if ( F_14 ( V_84 > V_85 ) ) {
V_84 = V_85 ;
V_8 -> V_86 ++ ;
}
V_2 -> V_15 = V_73 + V_84 ;
}
V_76:
F_41 ( V_59 , V_41 ) ;
return V_41 ;
}
static void F_42 ( struct V_1 * V_24 )
{
F_43 ( V_24 -> V_23 , V_24 -> V_62 ) ;
V_24 -> V_23 = NULL ;
V_24 -> V_60 = 0 ;
}
static void F_44 ( struct V_58 * V_59 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned int V_87 ;
V_59 -> V_8 . V_60 = 0 ;
V_59 -> V_88 . V_89 = 0 ;
F_42 ( & V_8 -> V_45 ) ;
if ( ! V_8 -> V_48 )
return;
for ( V_87 = 0 ; V_87 < ( 1U << V_8 -> V_50 ) ; V_87 ++ ) {
V_29 = & V_8 -> V_48 [ V_87 ] ;
while ( ( V_10 = F_31 ( V_29 ) ) != NULL ) {
V_2 = F_4 ( V_10 , struct V_1 , V_35 ) ;
F_11 ( V_10 , V_29 ) ;
F_42 ( V_2 ) ;
F_12 ( V_39 , V_2 ) ;
}
}
V_8 -> V_68 . V_25 = NULL ;
V_8 -> V_74 . V_25 = NULL ;
V_8 -> V_11 = V_90 ;
V_8 -> V_36 = 0 ;
V_8 -> V_37 = 0 ;
V_8 -> V_18 = 0 ;
}
static void F_45 ( struct V_7 * V_8 ,
struct V_28 * V_91 , V_49 V_92 ,
struct V_28 * V_93 , V_49 V_94 )
{
struct V_9 * V_95 , * * V_96 , * V_12 ;
struct V_28 * V_97 , * V_98 ;
struct V_1 * V_99 , * V_100 ;
int V_34 = 0 ;
V_49 V_87 ;
for ( V_87 = 0 ; V_87 < ( 1U << V_92 ) ; V_87 ++ ) {
V_97 = & V_91 [ V_87 ] ;
while ( ( V_95 = F_31 ( V_97 ) ) != NULL ) {
F_11 ( V_95 , V_97 ) ;
V_99 = F_4 ( V_95 , struct V_1 , V_35 ) ;
if ( F_8 ( V_99 ) ) {
V_34 ++ ;
F_12 ( V_39 , V_99 ) ;
continue;
}
V_98 = & V_93 [ F_18 ( ( V_49 ) ( long ) V_99 -> V_31 , V_94 ) ] ;
V_96 = & V_98 -> V_9 ;
V_12 = NULL ;
while ( * V_96 ) {
V_12 = * V_96 ;
V_100 = F_4 ( V_12 , struct V_1 , V_35 ) ;
F_46 ( V_100 -> V_31 == V_99 -> V_31 ) ;
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
static void * F_47 ( T_2 V_101 , int V_102 )
{
void * V_103 ;
V_103 = F_48 ( V_101 , V_104 | V_105 | V_56 , V_102 ) ;
if ( ! V_103 )
V_103 = F_49 ( V_101 , V_102 ) ;
return V_103 ;
}
static void F_50 ( void * V_106 )
{
F_51 ( V_106 ) ;
}
static int F_52 ( struct V_58 * V_59 , V_49 log )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
struct V_28 * V_107 ;
void * V_108 ;
V_49 V_87 ;
if ( V_8 -> V_48 && log == V_8 -> V_50 )
return 0 ;
V_107 = F_47 ( sizeof( struct V_28 ) << log ,
F_53 ( V_59 -> V_109 ) ) ;
if ( ! V_107 )
return - V_110 ;
for ( V_87 = 0 ; V_87 < ( 1U << log ) ; V_87 ++ )
V_107 [ V_87 ] = V_90 ;
F_54 ( V_59 ) ;
V_108 = V_8 -> V_48 ;
if ( V_108 )
F_45 ( V_8 , V_108 , V_8 -> V_50 , V_107 , log ) ;
V_8 -> V_48 = V_107 ;
V_8 -> V_50 = log ;
F_55 ( V_59 ) ;
F_50 ( V_108 ) ;
return 0 ;
}
static int F_56 ( struct V_58 * V_59 , struct V_111 * V_112 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
struct V_111 * V_113 [ V_114 + 1 ] ;
int V_115 , V_116 = 0 ;
unsigned V_117 = 0 ;
V_49 V_118 ;
if ( ! V_112 )
return - V_119 ;
V_115 = F_57 ( V_113 , V_114 , V_112 , V_120 ) ;
if ( V_115 < 0 )
return V_115 ;
F_54 ( V_59 ) ;
V_118 = V_8 -> V_50 ;
if ( V_113 [ V_121 ] ) {
V_49 V_122 = F_58 ( V_113 [ V_121 ] ) ;
if ( V_122 >= 1 && V_122 <= F_59 ( 256 * 1024 ) )
V_118 = V_122 ;
else
V_115 = - V_119 ;
}
if ( V_113 [ V_123 ] )
V_59 -> V_64 = F_58 ( V_113 [ V_123 ] ) ;
if ( V_113 [ V_124 ] )
V_8 -> V_65 = F_58 ( V_113 [ V_124 ] ) ;
if ( V_113 [ V_125 ] ) {
V_49 V_70 = F_58 ( V_113 [ V_125 ] ) ;
if ( V_70 > 0 )
V_8 -> V_70 = V_70 ;
else
V_115 = - V_119 ;
}
if ( V_113 [ V_126 ] )
V_8 -> V_54 = F_58 ( V_113 [ V_126 ] ) ;
if ( V_113 [ V_127 ] )
F_60 ( L_1 ,
F_58 ( V_113 [ V_127 ] ) ) ;
if ( V_113 [ V_128 ] )
V_8 -> V_81 = F_58 ( V_113 [ V_128 ] ) ;
if ( V_113 [ V_129 ] ) {
V_49 V_130 = F_58 ( V_113 [ V_129 ] ) ;
if ( V_130 <= 1 )
V_8 -> V_80 = V_130 ;
else
V_115 = - V_119 ;
}
if ( V_113 [ V_131 ] ) {
V_49 V_132 = F_58 ( V_113 [ V_131 ] ) ;
V_8 -> V_69 = F_61 ( V_132 ) ;
}
if ( V_113 [ V_133 ] )
V_8 -> V_47 = F_58 ( V_113 [ V_133 ] ) ;
if ( ! V_115 ) {
F_55 ( V_59 ) ;
V_115 = F_52 ( V_59 , V_118 ) ;
F_54 ( V_59 ) ;
}
while ( V_59 -> V_8 . V_60 > V_59 -> V_64 ) {
struct V_40 * V_41 = F_32 ( V_59 ) ;
if ( ! V_41 )
break;
V_117 += F_37 ( V_41 ) ;
F_43 ( V_41 , V_41 ) ;
V_116 ++ ;
}
F_62 ( V_59 , V_116 , V_117 ) ;
F_55 ( V_59 ) ;
return V_115 ;
}
static void F_63 ( struct V_58 * V_59 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
F_44 ( V_59 ) ;
F_50 ( V_8 -> V_48 ) ;
F_64 ( & V_8 -> V_78 ) ;
}
static int F_65 ( struct V_58 * V_59 , struct V_111 * V_112 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
int V_115 ;
V_59 -> V_64 = 10000 ;
V_8 -> V_65 = 100 ;
V_8 -> V_70 = 2 * F_66 ( F_67 ( V_59 ) ) ;
V_8 -> V_54 = 10 * F_66 ( F_67 ( V_59 ) ) ;
V_8 -> V_69 = F_68 ( 40 ) ;
V_8 -> V_81 = ~ 0U ;
V_8 -> V_80 = 1 ;
V_8 -> V_68 . V_25 = NULL ;
V_8 -> V_74 . V_25 = NULL ;
V_8 -> V_11 = V_90 ;
V_8 -> V_48 = NULL ;
V_8 -> V_50 = F_59 ( 1024 ) ;
V_8 -> V_47 = 1024 - 1 ;
F_69 ( & V_8 -> V_78 , V_59 ) ;
if ( V_112 )
V_115 = F_56 ( V_59 , V_112 ) ;
else
V_115 = F_52 ( V_59 , V_8 -> V_50 ) ;
return V_115 ;
}
static int F_70 ( struct V_58 * V_59 , struct V_40 * V_41 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
struct V_111 * V_134 ;
V_134 = F_71 ( V_41 , V_135 ) ;
if ( V_134 == NULL )
goto V_136;
if ( F_72 ( V_41 , V_123 , V_59 -> V_64 ) ||
F_72 ( V_41 , V_124 , V_8 -> V_65 ) ||
F_72 ( V_41 , V_125 , V_8 -> V_70 ) ||
F_72 ( V_41 , V_126 , V_8 -> V_54 ) ||
F_72 ( V_41 , V_129 , V_8 -> V_80 ) ||
F_72 ( V_41 , V_128 , V_8 -> V_81 ) ||
F_72 ( V_41 , V_131 ,
F_73 ( V_8 -> V_69 ) ) ||
F_72 ( V_41 , V_133 , V_8 -> V_47 ) ||
F_72 ( V_41 , V_121 , V_8 -> V_50 ) )
goto V_136;
return F_74 ( V_41 , V_134 ) ;
V_136:
return - 1 ;
}
static int F_75 ( struct V_58 * V_59 , struct V_137 * V_138 )
{
struct V_7 * V_8 = F_26 ( V_59 ) ;
T_1 V_73 = F_33 () ;
struct V_139 V_140 = {
. V_141 = V_8 -> V_38 ,
. V_142 = V_8 -> V_71 ,
. V_143 = V_8 -> V_67 ,
. V_20 = V_8 -> V_19 ,
. V_144 = V_8 -> V_66 ,
. V_145 = V_8 -> V_86 ,
. V_146 = V_8 -> V_57 ,
. V_36 = V_8 -> V_36 ,
. V_37 = V_8 -> V_37 ,
. V_18 = V_8 -> V_18 ,
. V_21 = V_8 -> V_21 - V_73 ,
} ;
return F_76 ( V_138 , & V_140 , sizeof( V_140 ) ) ;
}
static int T_3 F_77 ( void )
{
int V_147 ;
V_39 = F_78 ( L_2 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_39 )
return - V_110 ;
V_147 = F_79 ( & V_148 ) ;
if ( V_147 )
F_80 ( V_39 ) ;
return V_147 ;
}
static void T_4 F_81 ( void )
{
F_82 ( & V_148 ) ;
F_80 ( V_39 ) ;
}
