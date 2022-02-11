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
V_29 = & V_8 -> V_48 [ F_18 ( V_31 , V_8 -> V_49 ) ] ;
if ( V_8 -> V_36 >= ( 2U << V_8 -> V_49 ) &&
V_8 -> V_37 > V_8 -> V_36 / 2 )
F_10 ( V_8 , V_29 , V_31 ) ;
V_10 = & V_29 -> V_9 ;
V_12 = NULL ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_2 = F_4 ( V_12 , struct V_1 , V_35 ) ;
if ( V_2 -> V_31 == V_31 ) {
if ( F_14 ( V_41 -> V_31 &&
V_2 -> V_50 != V_31 -> V_51 ) ) {
V_2 -> V_52 = V_8 -> V_53 ;
V_2 -> V_50 = V_31 -> V_51 ;
V_2 -> V_15 = 0ULL ;
}
return V_2 ;
}
if ( V_2 -> V_31 > V_31 )
V_10 = & V_12 -> V_16 ;
else
V_10 = & V_12 -> V_17 ;
}
V_2 = F_19 ( V_39 , V_54 | V_55 ) ;
if ( F_14 ( ! V_2 ) ) {
V_8 -> V_56 ++ ;
return & V_8 -> V_45 ;
}
F_1 ( V_2 ) ;
V_2 -> V_31 = V_31 ;
if ( V_41 -> V_31 )
V_2 -> V_50 = V_31 -> V_51 ;
V_2 -> V_52 = V_8 -> V_53 ;
F_5 ( & V_2 -> V_35 , V_12 , V_10 ) ;
F_6 ( & V_2 -> V_35 , V_29 ) ;
V_8 -> V_36 ++ ;
V_8 -> V_37 ++ ;
return V_2 ;
}
static struct V_40 * F_20 ( struct V_57 * V_58 , struct V_1 * V_24 )
{
struct V_40 * V_41 = V_24 -> V_23 ;
if ( V_41 ) {
V_24 -> V_23 = V_41 -> V_3 ;
V_41 -> V_3 = NULL ;
V_24 -> V_59 -- ;
F_21 ( V_58 , V_41 ) ;
V_58 -> V_8 . V_59 -- ;
}
return V_41 ;
}
static bool F_22 ( struct V_40 * V_41 )
{
return false ;
}
static void F_23 ( struct V_1 * V_24 , struct V_40 * V_41 )
{
struct V_40 * V_60 , * V_23 = V_24 -> V_23 ;
V_41 -> V_3 = NULL ;
if ( ! V_23 ) {
V_24 -> V_23 = V_41 ;
V_24 -> V_61 = V_41 ;
return;
}
if ( F_24 ( ! F_22 ( V_41 ) ) ) {
V_24 -> V_61 -> V_3 = V_41 ;
V_24 -> V_61 = V_41 ;
return;
}
V_60 = NULL ;
while ( F_22 ( V_23 ) ) {
V_60 = V_23 ;
V_23 = V_23 -> V_3 ;
if ( ! V_23 )
break;
}
if ( ! V_60 ) {
V_41 -> V_3 = V_24 -> V_23 ;
V_24 -> V_23 = V_41 ;
} else {
if ( V_60 == V_24 -> V_61 )
V_24 -> V_61 = V_41 ;
else
V_41 -> V_3 = V_60 -> V_3 ;
V_60 -> V_3 = V_41 ;
}
}
static int F_25 ( struct V_40 * V_41 , struct V_57 * V_58 ,
struct V_40 * * V_62 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
struct V_1 * V_2 ;
if ( F_14 ( V_58 -> V_8 . V_59 >= V_58 -> V_63 ) )
return F_27 ( V_41 , V_58 , V_62 ) ;
V_2 = F_13 ( V_41 , V_8 ) ;
if ( F_14 ( V_2 -> V_59 >= V_8 -> V_64 && V_2 != & V_8 -> V_45 ) ) {
V_8 -> V_65 ++ ;
return F_27 ( V_41 , V_58 , V_62 ) ;
}
V_2 -> V_59 ++ ;
if ( F_22 ( V_41 ) )
V_8 -> V_66 ++ ;
F_28 ( V_58 , V_41 ) ;
if ( F_2 ( V_2 ) ) {
struct V_30 * V_31 = V_41 -> V_31 ;
F_7 ( & V_8 -> V_67 , V_2 ) ;
if ( F_9 ( V_6 , V_2 -> V_5 + V_8 -> V_68 ) )
V_2 -> V_52 = F_29 ( V_69 , V_2 -> V_52 , V_8 -> V_70 ) ;
if ( V_31 && V_8 -> V_71 ) {
if ( F_14 ( F_30 ( & V_31 -> V_72 ) !=
V_73 ) )
F_31 ( & V_31 -> V_72 ,
V_73 ) ;
}
V_8 -> V_37 -- ;
}
F_23 ( V_2 , V_41 ) ;
if ( F_14 ( V_2 == & V_8 -> V_45 ) ) {
V_8 -> V_74 ++ ;
}
V_58 -> V_8 . V_59 ++ ;
return V_75 ;
}
static void F_32 ( struct V_7 * V_8 , T_1 V_76 )
{
unsigned long V_77 ;
struct V_9 * V_10 ;
if ( V_8 -> V_21 > V_76 )
return;
V_77 = ( unsigned long ) ( V_76 - V_8 -> V_21 ) ;
V_8 -> V_78 -= V_8 -> V_78 >> 3 ;
V_8 -> V_78 += V_77 >> 3 ;
V_8 -> V_21 = ~ 0ULL ;
while ( ( V_10 = F_33 ( & V_8 -> V_11 ) ) != NULL ) {
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_14 ) ;
if ( V_2 -> V_15 > V_76 ) {
V_8 -> V_21 = V_2 -> V_15 ;
break;
}
F_11 ( V_10 , & V_8 -> V_11 ) ;
V_8 -> V_18 -- ;
F_7 ( & V_8 -> V_79 , V_2 ) ;
}
}
static struct V_40 * F_34 ( struct V_57 * V_58 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
T_1 V_76 = F_35 () ;
struct V_22 * V_23 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
V_69 V_80 , V_81 ;
V_41 = F_20 ( V_58 , & V_8 -> V_45 ) ;
if ( V_41 )
goto V_82;
F_32 ( V_8 , V_76 ) ;
V_83:
V_23 = & V_8 -> V_67 ;
if ( ! V_23 -> V_25 ) {
V_23 = & V_8 -> V_79 ;
if ( ! V_23 -> V_25 ) {
if ( V_8 -> V_21 != ~ 0ULL )
F_36 ( & V_8 -> V_84 ,
V_8 -> V_21 ) ;
return NULL ;
}
}
V_2 = V_23 -> V_25 ;
if ( V_2 -> V_52 <= 0 ) {
V_2 -> V_52 += V_8 -> V_70 ;
V_23 -> V_25 = V_2 -> V_3 ;
F_7 ( & V_8 -> V_79 , V_2 ) ;
goto V_83;
}
V_41 = V_2 -> V_23 ;
if ( F_14 ( V_41 && V_76 < V_2 -> V_15 &&
! F_37 ( V_41 ) ) ) {
V_23 -> V_25 = V_2 -> V_3 ;
F_3 ( V_8 , V_2 ) ;
goto V_83;
}
V_41 = F_20 ( V_58 , V_2 ) ;
if ( ! V_41 ) {
V_23 -> V_25 = V_2 -> V_3 ;
if ( ( V_23 == & V_8 -> V_67 ) && V_8 -> V_79 . V_25 ) {
F_7 ( & V_8 -> V_79 , V_2 ) ;
} else {
F_1 ( V_2 ) ;
V_8 -> V_37 ++ ;
}
goto V_83;
}
F_38 ( & V_41 -> V_85 ) ;
V_2 -> V_52 -= F_39 ( V_41 ) ;
if ( ! V_8 -> V_71 )
goto V_82;
if ( F_37 ( V_41 ) )
goto V_82;
V_80 = V_8 -> V_86 ;
if ( V_41 -> V_31 )
V_80 = F_40 ( V_41 -> V_31 -> V_87 , V_80 ) ;
if ( V_80 <= V_8 -> V_88 ) {
V_2 -> V_52 = 0 ;
V_81 = F_39 ( V_41 ) ;
} else {
V_81 = F_41 ( F_39 ( V_41 ) , V_8 -> V_70 ) ;
if ( V_2 -> V_52 > 0 )
goto V_82;
}
if ( V_80 != ~ 0U ) {
T_1 V_89 = ( T_1 ) V_81 * V_90 ;
if ( F_24 ( V_80 ) )
F_42 ( V_89 , V_80 ) ;
if ( F_14 ( V_89 > V_90 ) ) {
V_89 = V_90 ;
V_8 -> V_91 ++ ;
}
if ( V_2 -> V_15 )
V_89 -= F_40 ( V_89 / 2 , V_76 - V_2 -> V_15 ) ;
V_2 -> V_15 = V_76 + V_89 ;
}
V_82:
F_43 ( V_58 , V_41 ) ;
return V_41 ;
}
static void F_44 ( struct V_1 * V_24 )
{
F_45 ( V_24 -> V_23 , V_24 -> V_61 ) ;
V_24 -> V_23 = NULL ;
V_24 -> V_59 = 0 ;
}
static void F_46 ( struct V_57 * V_58 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned int V_92 ;
V_58 -> V_8 . V_59 = 0 ;
V_58 -> V_93 . V_94 = 0 ;
F_44 ( & V_8 -> V_45 ) ;
if ( ! V_8 -> V_48 )
return;
for ( V_92 = 0 ; V_92 < ( 1U << V_8 -> V_49 ) ; V_92 ++ ) {
V_29 = & V_8 -> V_48 [ V_92 ] ;
while ( ( V_10 = F_33 ( V_29 ) ) != NULL ) {
V_2 = F_4 ( V_10 , struct V_1 , V_35 ) ;
F_11 ( V_10 , V_29 ) ;
F_44 ( V_2 ) ;
F_12 ( V_39 , V_2 ) ;
}
}
V_8 -> V_67 . V_25 = NULL ;
V_8 -> V_79 . V_25 = NULL ;
V_8 -> V_11 = V_95 ;
V_8 -> V_36 = 0 ;
V_8 -> V_37 = 0 ;
V_8 -> V_18 = 0 ;
}
static void F_47 ( struct V_7 * V_8 ,
struct V_28 * V_96 , V_69 V_97 ,
struct V_28 * V_98 , V_69 V_99 )
{
struct V_9 * V_100 , * * V_101 , * V_12 ;
struct V_28 * V_102 , * V_103 ;
struct V_1 * V_104 , * V_105 ;
int V_34 = 0 ;
V_69 V_92 ;
for ( V_92 = 0 ; V_92 < ( 1U << V_97 ) ; V_92 ++ ) {
V_102 = & V_96 [ V_92 ] ;
while ( ( V_100 = F_33 ( V_102 ) ) != NULL ) {
F_11 ( V_100 , V_102 ) ;
V_104 = F_4 ( V_100 , struct V_1 , V_35 ) ;
if ( F_8 ( V_104 ) ) {
V_34 ++ ;
F_12 ( V_39 , V_104 ) ;
continue;
}
V_103 = & V_98 [ F_18 ( V_104 -> V_31 , V_99 ) ] ;
V_101 = & V_103 -> V_9 ;
V_12 = NULL ;
while ( * V_101 ) {
V_12 = * V_101 ;
V_105 = F_4 ( V_12 , struct V_1 , V_35 ) ;
F_48 ( V_105 -> V_31 == V_104 -> V_31 ) ;
if ( V_105 -> V_31 > V_104 -> V_31 )
V_101 = & V_12 -> V_16 ;
else
V_101 = & V_12 -> V_17 ;
}
F_5 ( & V_104 -> V_35 , V_12 , V_101 ) ;
F_6 ( & V_104 -> V_35 , V_103 ) ;
}
}
V_8 -> V_36 -= V_34 ;
V_8 -> V_37 -= V_34 ;
V_8 -> V_38 += V_34 ;
}
static void F_49 ( void * V_106 )
{
F_50 ( V_106 ) ;
}
static int F_51 ( struct V_57 * V_58 , V_69 log )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
struct V_28 * V_107 ;
void * V_108 ;
V_69 V_92 ;
if ( V_8 -> V_48 && log == V_8 -> V_49 )
return 0 ;
V_107 = F_52 ( sizeof( struct V_28 ) << log , V_109 | V_110 ,
F_53 ( V_58 -> V_111 ) ) ;
if ( ! V_107 )
return - V_112 ;
for ( V_92 = 0 ; V_92 < ( 1U << log ) ; V_92 ++ )
V_107 [ V_92 ] = V_95 ;
F_54 ( V_58 ) ;
V_108 = V_8 -> V_48 ;
if ( V_108 )
F_47 ( V_8 , V_108 , V_8 -> V_49 , V_107 , log ) ;
V_8 -> V_48 = V_107 ;
V_8 -> V_49 = log ;
F_55 ( V_58 ) ;
F_49 ( V_108 ) ;
return 0 ;
}
static int F_56 ( struct V_57 * V_58 , struct V_113 * V_114 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
struct V_113 * V_115 [ V_116 + 1 ] ;
int V_117 , V_118 = 0 ;
unsigned V_119 = 0 ;
V_69 V_120 ;
if ( ! V_114 )
return - V_121 ;
V_117 = F_57 ( V_115 , V_116 , V_114 , V_122 , NULL ) ;
if ( V_117 < 0 )
return V_117 ;
F_54 ( V_58 ) ;
V_120 = V_8 -> V_49 ;
if ( V_115 [ V_123 ] ) {
V_69 V_124 = F_58 ( V_115 [ V_123 ] ) ;
if ( V_124 >= 1 && V_124 <= F_59 ( 256 * 1024 ) )
V_120 = V_124 ;
else
V_117 = - V_121 ;
}
if ( V_115 [ V_125 ] )
V_58 -> V_63 = F_58 ( V_115 [ V_125 ] ) ;
if ( V_115 [ V_126 ] )
V_8 -> V_64 = F_58 ( V_115 [ V_126 ] ) ;
if ( V_115 [ V_127 ] ) {
V_69 V_70 = F_58 ( V_115 [ V_127 ] ) ;
if ( V_70 > 0 )
V_8 -> V_70 = V_70 ;
else
V_117 = - V_121 ;
}
if ( V_115 [ V_128 ] )
V_8 -> V_53 = F_58 ( V_115 [ V_128 ] ) ;
if ( V_115 [ V_129 ] )
F_60 ( L_1 ,
F_58 ( V_115 [ V_129 ] ) ) ;
if ( V_115 [ V_130 ] )
V_8 -> V_86 = F_58 ( V_115 [ V_130 ] ) ;
if ( V_115 [ V_131 ] )
V_8 -> V_88 =
F_58 ( V_115 [ V_131 ] ) ;
if ( V_115 [ V_132 ] ) {
V_69 V_133 = F_58 ( V_115 [ V_132 ] ) ;
if ( V_133 <= 1 )
V_8 -> V_71 = V_133 ;
else
V_117 = - V_121 ;
}
if ( V_115 [ V_134 ] ) {
V_69 V_135 = F_58 ( V_115 [ V_134 ] ) ;
V_8 -> V_68 = F_61 ( V_135 ) ;
}
if ( V_115 [ V_136 ] )
V_8 -> V_47 = F_58 ( V_115 [ V_136 ] ) ;
if ( ! V_117 ) {
F_55 ( V_58 ) ;
V_117 = F_51 ( V_58 , V_120 ) ;
F_54 ( V_58 ) ;
}
while ( V_58 -> V_8 . V_59 > V_58 -> V_63 ) {
struct V_40 * V_41 = F_34 ( V_58 ) ;
if ( ! V_41 )
break;
V_119 += F_39 ( V_41 ) ;
F_45 ( V_41 , V_41 ) ;
V_118 ++ ;
}
F_62 ( V_58 , V_118 , V_119 ) ;
F_55 ( V_58 ) ;
return V_117 ;
}
static void F_63 ( struct V_57 * V_58 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
F_46 ( V_58 ) ;
F_49 ( V_8 -> V_48 ) ;
F_64 ( & V_8 -> V_84 ) ;
}
static int F_65 ( struct V_57 * V_58 , struct V_113 * V_114 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
int V_117 ;
V_58 -> V_63 = 10000 ;
V_8 -> V_64 = 100 ;
V_8 -> V_70 = 2 * F_66 ( F_67 ( V_58 ) ) ;
V_8 -> V_53 = 10 * F_66 ( F_67 ( V_58 ) ) ;
V_8 -> V_68 = F_68 ( 40 ) ;
V_8 -> V_86 = ~ 0U ;
V_8 -> V_21 = ~ 0ULL ;
V_8 -> V_71 = 1 ;
V_8 -> V_67 . V_25 = NULL ;
V_8 -> V_79 . V_25 = NULL ;
V_8 -> V_11 = V_95 ;
V_8 -> V_48 = NULL ;
V_8 -> V_49 = F_59 ( 1024 ) ;
V_8 -> V_47 = 1024 - 1 ;
V_8 -> V_88 = 550000 / 8 ;
F_69 ( & V_8 -> V_84 , V_58 ) ;
if ( V_114 )
V_117 = F_56 ( V_58 , V_114 ) ;
else
V_117 = F_51 ( V_58 , V_8 -> V_49 ) ;
return V_117 ;
}
static int F_70 ( struct V_57 * V_58 , struct V_40 * V_41 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
struct V_113 * V_137 ;
V_137 = F_71 ( V_41 , V_138 ) ;
if ( V_137 == NULL )
goto V_139;
if ( F_72 ( V_41 , V_125 , V_58 -> V_63 ) ||
F_72 ( V_41 , V_126 , V_8 -> V_64 ) ||
F_72 ( V_41 , V_127 , V_8 -> V_70 ) ||
F_72 ( V_41 , V_128 , V_8 -> V_53 ) ||
F_72 ( V_41 , V_132 , V_8 -> V_71 ) ||
F_72 ( V_41 , V_130 , V_8 -> V_86 ) ||
F_72 ( V_41 , V_134 ,
F_73 ( V_8 -> V_68 ) ) ||
F_72 ( V_41 , V_136 , V_8 -> V_47 ) ||
F_72 ( V_41 , V_131 ,
V_8 -> V_88 ) ||
F_72 ( V_41 , V_123 , V_8 -> V_49 ) )
goto V_139;
return F_74 ( V_41 , V_137 ) ;
V_139:
return - 1 ;
}
static int F_75 ( struct V_57 * V_58 , struct V_140 * V_141 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
struct V_142 V_143 ;
F_54 ( V_58 ) ;
V_143 . V_144 = V_8 -> V_38 ;
V_143 . V_145 = V_8 -> V_74 ;
V_143 . V_146 = V_8 -> V_66 ;
V_143 . V_20 = V_8 -> V_19 ;
V_143 . V_147 = V_8 -> V_65 ;
V_143 . V_148 = V_8 -> V_91 ;
V_143 . V_149 = V_8 -> V_56 ;
V_143 . V_21 = V_8 -> V_21 - F_35 () ;
V_143 . V_36 = V_8 -> V_36 ;
V_143 . V_37 = V_8 -> V_37 ;
V_143 . V_18 = V_8 -> V_18 ;
V_143 . V_78 = F_76 (unsigned long,
q->unthrottle_latency_ns, ~0U ) ;
F_55 ( V_58 ) ;
return F_77 ( V_141 , & V_143 , sizeof( V_143 ) ) ;
}
static int T_2 F_78 ( void )
{
int V_150 ;
V_39 = F_79 ( L_2 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_39 )
return - V_112 ;
V_150 = F_80 ( & V_151 ) ;
if ( V_150 )
F_81 ( V_39 ) ;
return V_150 ;
}
static void T_3 F_82 ( void )
{
F_83 ( & V_151 ) ;
F_81 ( V_39 ) ;
}
