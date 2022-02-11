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
F_7 ( & V_8 -> V_67 , V_2 ) ;
if ( F_9 ( V_6 , V_2 -> V_5 + V_8 -> V_68 ) )
V_2 -> V_52 = F_29 ( V_69 , V_2 -> V_52 , V_8 -> V_70 ) ;
V_8 -> V_37 -- ;
}
F_23 ( V_2 , V_41 ) ;
if ( F_14 ( V_2 == & V_8 -> V_45 ) ) {
V_8 -> V_71 ++ ;
}
V_58 -> V_8 . V_59 ++ ;
return V_72 ;
}
static void F_30 ( struct V_7 * V_8 , T_1 V_73 )
{
unsigned long V_74 ;
struct V_9 * V_10 ;
if ( V_8 -> V_21 > V_73 )
return;
V_74 = ( unsigned long ) ( V_73 - V_8 -> V_21 ) ;
V_8 -> V_75 -= V_8 -> V_75 >> 3 ;
V_8 -> V_75 += V_74 >> 3 ;
V_8 -> V_21 = ~ 0ULL ;
while ( ( V_10 = F_31 ( & V_8 -> V_11 ) ) != NULL ) {
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_14 ) ;
if ( V_2 -> V_15 > V_73 ) {
V_8 -> V_21 = V_2 -> V_15 ;
break;
}
F_11 ( V_10 , & V_8 -> V_11 ) ;
V_8 -> V_18 -- ;
F_7 ( & V_8 -> V_76 , V_2 ) ;
}
}
static struct V_40 * F_32 ( struct V_57 * V_58 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
T_1 V_73 = F_33 () ;
struct V_22 * V_23 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
V_69 V_77 , V_78 ;
V_41 = F_20 ( V_58 , & V_8 -> V_45 ) ;
if ( V_41 )
goto V_79;
F_30 ( V_8 , V_73 ) ;
V_80:
V_23 = & V_8 -> V_67 ;
if ( ! V_23 -> V_25 ) {
V_23 = & V_8 -> V_76 ;
if ( ! V_23 -> V_25 ) {
if ( V_8 -> V_21 != ~ 0ULL )
F_34 ( & V_8 -> V_81 ,
V_8 -> V_21 ) ;
return NULL ;
}
}
V_2 = V_23 -> V_25 ;
if ( V_2 -> V_52 <= 0 ) {
V_2 -> V_52 += V_8 -> V_70 ;
V_23 -> V_25 = V_2 -> V_3 ;
F_7 ( & V_8 -> V_76 , V_2 ) ;
goto V_80;
}
V_41 = V_2 -> V_23 ;
if ( F_14 ( V_41 && V_73 < V_2 -> V_15 &&
! F_35 ( V_41 ) ) ) {
V_23 -> V_25 = V_2 -> V_3 ;
F_3 ( V_8 , V_2 ) ;
goto V_80;
}
V_41 = F_20 ( V_58 , V_2 ) ;
if ( ! V_41 ) {
V_23 -> V_25 = V_2 -> V_3 ;
if ( ( V_23 == & V_8 -> V_67 ) && V_8 -> V_76 . V_25 ) {
F_7 ( & V_8 -> V_76 , V_2 ) ;
} else {
F_1 ( V_2 ) ;
V_8 -> V_37 ++ ;
}
goto V_80;
}
F_36 ( & V_41 -> V_82 ) ;
V_2 -> V_52 -= F_37 ( V_41 ) ;
if ( ! V_8 -> V_83 )
goto V_79;
if ( F_35 ( V_41 ) )
goto V_79;
V_77 = V_8 -> V_84 ;
if ( V_41 -> V_31 )
V_77 = F_38 ( V_41 -> V_31 -> V_85 , V_77 ) ;
if ( V_77 <= V_8 -> V_86 ) {
V_2 -> V_52 = 0 ;
V_78 = F_37 ( V_41 ) ;
} else {
V_78 = F_39 ( F_37 ( V_41 ) , V_8 -> V_70 ) ;
if ( V_2 -> V_52 > 0 )
goto V_79;
}
if ( V_77 != ~ 0U ) {
T_1 V_87 = ( T_1 ) V_78 * V_88 ;
if ( F_24 ( V_77 ) )
F_40 ( V_87 , V_77 ) ;
if ( F_14 ( V_87 > V_88 ) ) {
V_87 = V_88 ;
V_8 -> V_89 ++ ;
}
if ( V_2 -> V_15 )
V_87 -= F_38 ( V_87 / 2 , V_73 - V_2 -> V_15 ) ;
V_2 -> V_15 = V_73 + V_87 ;
}
V_79:
F_41 ( V_58 , V_41 ) ;
return V_41 ;
}
static void F_42 ( struct V_1 * V_24 )
{
F_43 ( V_24 -> V_23 , V_24 -> V_61 ) ;
V_24 -> V_23 = NULL ;
V_24 -> V_59 = 0 ;
}
static void F_44 ( struct V_57 * V_58 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned int V_90 ;
V_58 -> V_8 . V_59 = 0 ;
V_58 -> V_91 . V_92 = 0 ;
F_42 ( & V_8 -> V_45 ) ;
if ( ! V_8 -> V_48 )
return;
for ( V_90 = 0 ; V_90 < ( 1U << V_8 -> V_49 ) ; V_90 ++ ) {
V_29 = & V_8 -> V_48 [ V_90 ] ;
while ( ( V_10 = F_31 ( V_29 ) ) != NULL ) {
V_2 = F_4 ( V_10 , struct V_1 , V_35 ) ;
F_11 ( V_10 , V_29 ) ;
F_42 ( V_2 ) ;
F_12 ( V_39 , V_2 ) ;
}
}
V_8 -> V_67 . V_25 = NULL ;
V_8 -> V_76 . V_25 = NULL ;
V_8 -> V_11 = V_93 ;
V_8 -> V_36 = 0 ;
V_8 -> V_37 = 0 ;
V_8 -> V_18 = 0 ;
}
static void F_45 ( struct V_7 * V_8 ,
struct V_28 * V_94 , V_69 V_95 ,
struct V_28 * V_96 , V_69 V_97 )
{
struct V_9 * V_98 , * * V_99 , * V_12 ;
struct V_28 * V_100 , * V_101 ;
struct V_1 * V_102 , * V_103 ;
int V_34 = 0 ;
V_69 V_90 ;
for ( V_90 = 0 ; V_90 < ( 1U << V_95 ) ; V_90 ++ ) {
V_100 = & V_94 [ V_90 ] ;
while ( ( V_98 = F_31 ( V_100 ) ) != NULL ) {
F_11 ( V_98 , V_100 ) ;
V_102 = F_4 ( V_98 , struct V_1 , V_35 ) ;
if ( F_8 ( V_102 ) ) {
V_34 ++ ;
F_12 ( V_39 , V_102 ) ;
continue;
}
V_101 = & V_96 [ F_18 ( V_102 -> V_31 , V_97 ) ] ;
V_99 = & V_101 -> V_9 ;
V_12 = NULL ;
while ( * V_99 ) {
V_12 = * V_99 ;
V_103 = F_4 ( V_12 , struct V_1 , V_35 ) ;
F_46 ( V_103 -> V_31 == V_102 -> V_31 ) ;
if ( V_103 -> V_31 > V_102 -> V_31 )
V_99 = & V_12 -> V_16 ;
else
V_99 = & V_12 -> V_17 ;
}
F_5 ( & V_102 -> V_35 , V_12 , V_99 ) ;
F_6 ( & V_102 -> V_35 , V_101 ) ;
}
}
V_8 -> V_36 -= V_34 ;
V_8 -> V_37 -= V_34 ;
V_8 -> V_38 += V_34 ;
}
static void F_47 ( void * V_104 )
{
F_48 ( V_104 ) ;
}
static int F_49 ( struct V_57 * V_58 , V_69 log )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
struct V_28 * V_105 ;
void * V_106 ;
V_69 V_90 ;
if ( V_8 -> V_48 && log == V_8 -> V_49 )
return 0 ;
V_105 = F_50 ( sizeof( struct V_28 ) << log , V_107 | V_108 ,
F_51 ( V_58 -> V_109 ) ) ;
if ( ! V_105 )
return - V_110 ;
for ( V_90 = 0 ; V_90 < ( 1U << log ) ; V_90 ++ )
V_105 [ V_90 ] = V_93 ;
F_52 ( V_58 ) ;
V_106 = V_8 -> V_48 ;
if ( V_106 )
F_45 ( V_8 , V_106 , V_8 -> V_49 , V_105 , log ) ;
V_8 -> V_48 = V_105 ;
V_8 -> V_49 = log ;
F_53 ( V_58 ) ;
F_47 ( V_106 ) ;
return 0 ;
}
static int F_54 ( struct V_57 * V_58 , struct V_111 * V_112 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
struct V_111 * V_113 [ V_114 + 1 ] ;
int V_115 , V_116 = 0 ;
unsigned V_117 = 0 ;
V_69 V_118 ;
if ( ! V_112 )
return - V_119 ;
V_115 = F_55 ( V_113 , V_114 , V_112 , V_120 , NULL ) ;
if ( V_115 < 0 )
return V_115 ;
F_52 ( V_58 ) ;
V_118 = V_8 -> V_49 ;
if ( V_113 [ V_121 ] ) {
V_69 V_122 = F_56 ( V_113 [ V_121 ] ) ;
if ( V_122 >= 1 && V_122 <= F_57 ( 256 * 1024 ) )
V_118 = V_122 ;
else
V_115 = - V_119 ;
}
if ( V_113 [ V_123 ] )
V_58 -> V_63 = F_56 ( V_113 [ V_123 ] ) ;
if ( V_113 [ V_124 ] )
V_8 -> V_64 = F_56 ( V_113 [ V_124 ] ) ;
if ( V_113 [ V_125 ] ) {
V_69 V_70 = F_56 ( V_113 [ V_125 ] ) ;
if ( V_70 > 0 )
V_8 -> V_70 = V_70 ;
else
V_115 = - V_119 ;
}
if ( V_113 [ V_126 ] )
V_8 -> V_53 = F_56 ( V_113 [ V_126 ] ) ;
if ( V_113 [ V_127 ] )
F_58 ( L_1 ,
F_56 ( V_113 [ V_127 ] ) ) ;
if ( V_113 [ V_128 ] )
V_8 -> V_84 = F_56 ( V_113 [ V_128 ] ) ;
if ( V_113 [ V_129 ] )
V_8 -> V_86 =
F_56 ( V_113 [ V_129 ] ) ;
if ( V_113 [ V_130 ] ) {
V_69 V_131 = F_56 ( V_113 [ V_130 ] ) ;
if ( V_131 <= 1 )
V_8 -> V_83 = V_131 ;
else
V_115 = - V_119 ;
}
if ( V_113 [ V_132 ] ) {
V_69 V_133 = F_56 ( V_113 [ V_132 ] ) ;
V_8 -> V_68 = F_59 ( V_133 ) ;
}
if ( V_113 [ V_134 ] )
V_8 -> V_47 = F_56 ( V_113 [ V_134 ] ) ;
if ( ! V_115 ) {
F_53 ( V_58 ) ;
V_115 = F_49 ( V_58 , V_118 ) ;
F_52 ( V_58 ) ;
}
while ( V_58 -> V_8 . V_59 > V_58 -> V_63 ) {
struct V_40 * V_41 = F_32 ( V_58 ) ;
if ( ! V_41 )
break;
V_117 += F_37 ( V_41 ) ;
F_43 ( V_41 , V_41 ) ;
V_116 ++ ;
}
F_60 ( V_58 , V_116 , V_117 ) ;
F_53 ( V_58 ) ;
return V_115 ;
}
static void F_61 ( struct V_57 * V_58 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
F_44 ( V_58 ) ;
F_47 ( V_8 -> V_48 ) ;
F_62 ( & V_8 -> V_81 ) ;
}
static int F_63 ( struct V_57 * V_58 , struct V_111 * V_112 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
int V_115 ;
V_58 -> V_63 = 10000 ;
V_8 -> V_64 = 100 ;
V_8 -> V_70 = 2 * F_64 ( F_65 ( V_58 ) ) ;
V_8 -> V_53 = 10 * F_64 ( F_65 ( V_58 ) ) ;
V_8 -> V_68 = F_66 ( 40 ) ;
V_8 -> V_84 = ~ 0U ;
V_8 -> V_21 = ~ 0ULL ;
V_8 -> V_83 = 1 ;
V_8 -> V_67 . V_25 = NULL ;
V_8 -> V_76 . V_25 = NULL ;
V_8 -> V_11 = V_93 ;
V_8 -> V_48 = NULL ;
V_8 -> V_49 = F_57 ( 1024 ) ;
V_8 -> V_47 = 1024 - 1 ;
V_8 -> V_86 = 550000 / 8 ;
F_67 ( & V_8 -> V_81 , V_58 ) ;
if ( V_112 )
V_115 = F_54 ( V_58 , V_112 ) ;
else
V_115 = F_49 ( V_58 , V_8 -> V_49 ) ;
return V_115 ;
}
static int F_68 ( struct V_57 * V_58 , struct V_40 * V_41 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
struct V_111 * V_135 ;
V_135 = F_69 ( V_41 , V_136 ) ;
if ( V_135 == NULL )
goto V_137;
if ( F_70 ( V_41 , V_123 , V_58 -> V_63 ) ||
F_70 ( V_41 , V_124 , V_8 -> V_64 ) ||
F_70 ( V_41 , V_125 , V_8 -> V_70 ) ||
F_70 ( V_41 , V_126 , V_8 -> V_53 ) ||
F_70 ( V_41 , V_130 , V_8 -> V_83 ) ||
F_70 ( V_41 , V_128 , V_8 -> V_84 ) ||
F_70 ( V_41 , V_132 ,
F_71 ( V_8 -> V_68 ) ) ||
F_70 ( V_41 , V_134 , V_8 -> V_47 ) ||
F_70 ( V_41 , V_129 ,
V_8 -> V_86 ) ||
F_70 ( V_41 , V_121 , V_8 -> V_49 ) )
goto V_137;
return F_72 ( V_41 , V_135 ) ;
V_137:
return - 1 ;
}
static int F_73 ( struct V_57 * V_58 , struct V_138 * V_139 )
{
struct V_7 * V_8 = F_26 ( V_58 ) ;
struct V_140 V_141 ;
F_52 ( V_58 ) ;
V_141 . V_142 = V_8 -> V_38 ;
V_141 . V_143 = V_8 -> V_71 ;
V_141 . V_144 = V_8 -> V_66 ;
V_141 . V_20 = V_8 -> V_19 ;
V_141 . V_145 = V_8 -> V_65 ;
V_141 . V_146 = V_8 -> V_89 ;
V_141 . V_147 = V_8 -> V_56 ;
V_141 . V_21 = V_8 -> V_21 - F_33 () ;
V_141 . V_36 = V_8 -> V_36 ;
V_141 . V_37 = V_8 -> V_37 ;
V_141 . V_18 = V_8 -> V_18 ;
V_141 . V_75 = F_74 (unsigned long,
q->unthrottle_latency_ns, ~0U ) ;
F_53 ( V_58 ) ;
return F_75 ( V_139 , & V_141 , sizeof( V_141 ) ) ;
}
static int T_2 F_76 ( void )
{
int V_148 ;
V_39 = F_77 ( L_2 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_39 )
return - V_110 ;
V_148 = F_78 ( & V_149 ) ;
if ( V_148 )
F_79 ( V_39 ) ;
return V_148 ;
}
static void T_3 F_80 ( void )
{
F_81 ( & V_149 ) ;
F_79 ( V_39 ) ;
}
