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
if ( ! V_31 || V_31 -> V_46 == V_47 ) {
unsigned long V_48 = F_15 ( V_41 ) & V_8 -> V_49 ;
V_31 = (struct V_30 * ) ( ( V_48 << 1 ) | 1UL ) ;
F_16 ( V_41 ) ;
}
V_29 = & V_8 -> V_50 [ F_17 ( ( V_51 ) ( long ) V_31 , V_8 -> V_52 ) ] ;
if ( V_8 -> V_36 >= ( 2U << V_8 -> V_52 ) &&
V_8 -> V_37 > V_8 -> V_36 / 2 )
F_10 ( V_8 , V_29 , V_31 ) ;
V_10 = & V_29 -> V_9 ;
V_12 = NULL ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_2 = F_4 ( V_12 , struct V_1 , V_35 ) ;
if ( V_2 -> V_31 == V_31 ) {
if ( F_14 ( V_41 -> V_31 &&
V_2 -> V_53 != V_31 -> V_54 ) ) {
V_2 -> V_55 = V_8 -> V_56 ;
V_2 -> V_53 = V_31 -> V_54 ;
V_2 -> V_15 = 0ULL ;
}
return V_2 ;
}
if ( V_2 -> V_31 > V_31 )
V_10 = & V_12 -> V_16 ;
else
V_10 = & V_12 -> V_17 ;
}
V_2 = F_18 ( V_39 , V_57 | V_58 ) ;
if ( F_14 ( ! V_2 ) ) {
V_8 -> V_59 ++ ;
return & V_8 -> V_45 ;
}
F_1 ( V_2 ) ;
V_2 -> V_31 = V_31 ;
if ( V_41 -> V_31 )
V_2 -> V_53 = V_31 -> V_54 ;
V_2 -> V_55 = V_8 -> V_56 ;
F_5 ( & V_2 -> V_35 , V_12 , V_10 ) ;
F_6 ( & V_2 -> V_35 , V_29 ) ;
V_8 -> V_36 ++ ;
V_8 -> V_37 ++ ;
return V_2 ;
}
static struct V_40 * F_19 ( struct V_60 * V_61 , struct V_1 * V_24 )
{
struct V_40 * V_41 = V_24 -> V_23 ;
if ( V_41 ) {
V_24 -> V_23 = V_41 -> V_3 ;
V_41 -> V_3 = NULL ;
V_24 -> V_62 -- ;
F_20 ( V_61 , V_41 ) ;
V_61 -> V_8 . V_62 -- ;
}
return V_41 ;
}
static bool F_21 ( struct V_40 * V_41 )
{
return false ;
}
static void F_22 ( struct V_1 * V_24 , struct V_40 * V_41 )
{
struct V_40 * V_63 , * V_23 = V_24 -> V_23 ;
V_41 -> V_3 = NULL ;
if ( ! V_23 ) {
V_24 -> V_23 = V_41 ;
V_24 -> V_64 = V_41 ;
return;
}
if ( F_23 ( ! F_21 ( V_41 ) ) ) {
V_24 -> V_64 -> V_3 = V_41 ;
V_24 -> V_64 = V_41 ;
return;
}
V_63 = NULL ;
while ( F_21 ( V_23 ) ) {
V_63 = V_23 ;
V_23 = V_23 -> V_3 ;
if ( ! V_23 )
break;
}
if ( ! V_63 ) {
V_41 -> V_3 = V_24 -> V_23 ;
V_24 -> V_23 = V_41 ;
} else {
if ( V_63 == V_24 -> V_64 )
V_24 -> V_64 = V_41 ;
else
V_41 -> V_3 = V_63 -> V_3 ;
V_63 -> V_3 = V_41 ;
}
}
static int F_24 ( struct V_40 * V_41 , struct V_60 * V_61 )
{
struct V_7 * V_8 = F_25 ( V_61 ) ;
struct V_1 * V_2 ;
if ( F_14 ( V_61 -> V_8 . V_62 >= V_61 -> V_65 ) )
return F_26 ( V_41 , V_61 ) ;
V_2 = F_13 ( V_41 , V_8 ) ;
if ( F_14 ( V_2 -> V_62 >= V_8 -> V_66 && V_2 != & V_8 -> V_45 ) ) {
V_8 -> V_67 ++ ;
return F_26 ( V_41 , V_61 ) ;
}
V_2 -> V_62 ++ ;
if ( F_21 ( V_41 ) )
V_8 -> V_68 ++ ;
F_27 ( V_61 , V_41 ) ;
if ( F_2 ( V_2 ) ) {
F_7 ( & V_8 -> V_69 , V_2 ) ;
if ( F_9 ( V_6 , V_2 -> V_5 + V_8 -> V_70 ) )
V_2 -> V_55 = F_28 ( V_51 , V_2 -> V_55 , V_8 -> V_71 ) ;
V_8 -> V_37 -- ;
}
F_22 ( V_2 , V_41 ) ;
if ( F_14 ( V_2 == & V_8 -> V_45 ) ) {
V_8 -> V_72 ++ ;
}
V_61 -> V_8 . V_62 ++ ;
return V_73 ;
}
static void F_29 ( struct V_7 * V_8 , T_1 V_74 )
{
struct V_9 * V_10 ;
if ( V_8 -> V_21 > V_74 )
return;
V_8 -> V_21 = ~ 0ULL ;
while ( ( V_10 = F_30 ( & V_8 -> V_11 ) ) != NULL ) {
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_14 ) ;
if ( V_2 -> V_15 > V_74 ) {
V_8 -> V_21 = V_2 -> V_15 ;
break;
}
F_11 ( V_10 , & V_8 -> V_11 ) ;
V_8 -> V_18 -- ;
F_7 ( & V_8 -> V_75 , V_2 ) ;
}
}
static struct V_40 * F_31 ( struct V_60 * V_61 )
{
struct V_7 * V_8 = F_25 ( V_61 ) ;
T_1 V_74 = F_32 () ;
struct V_22 * V_23 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
V_51 V_76 ;
V_41 = F_19 ( V_61 , & V_8 -> V_45 ) ;
if ( V_41 )
goto V_77;
F_29 ( V_8 , V_74 ) ;
V_78:
V_23 = & V_8 -> V_69 ;
if ( ! V_23 -> V_25 ) {
V_23 = & V_8 -> V_75 ;
if ( ! V_23 -> V_25 ) {
if ( V_8 -> V_21 != ~ 0ULL )
F_33 ( & V_8 -> V_79 ,
V_8 -> V_21 ,
false ) ;
return NULL ;
}
}
V_2 = V_23 -> V_25 ;
if ( V_2 -> V_55 <= 0 ) {
V_2 -> V_55 += V_8 -> V_71 ;
V_23 -> V_25 = V_2 -> V_3 ;
F_7 ( & V_8 -> V_75 , V_2 ) ;
goto V_78;
}
V_41 = V_2 -> V_23 ;
if ( F_14 ( V_41 && V_74 < V_2 -> V_15 &&
! F_34 ( V_41 ) ) ) {
V_23 -> V_25 = V_2 -> V_3 ;
F_3 ( V_8 , V_2 ) ;
goto V_78;
}
V_41 = F_19 ( V_61 , V_2 ) ;
if ( ! V_41 ) {
V_23 -> V_25 = V_2 -> V_3 ;
if ( ( V_23 == & V_8 -> V_69 ) && V_8 -> V_75 . V_25 ) {
F_7 ( & V_8 -> V_75 , V_2 ) ;
} else {
F_1 ( V_2 ) ;
V_8 -> V_37 ++ ;
}
goto V_78;
}
F_35 ( & V_41 -> V_80 ) ;
V_2 -> V_55 -= F_36 ( V_41 ) ;
if ( V_2 -> V_55 > 0 || ! V_8 -> V_81 )
goto V_77;
if ( F_34 ( V_41 ) )
goto V_77;
V_76 = V_8 -> V_82 ;
if ( V_41 -> V_31 )
V_76 = F_37 ( V_41 -> V_31 -> V_83 , V_76 ) ;
if ( V_76 != ~ 0U ) {
V_51 V_84 = F_38 ( F_36 ( V_41 ) , V_8 -> V_71 ) ;
T_1 V_85 = ( T_1 ) V_84 * V_86 ;
if ( F_23 ( V_76 ) )
F_39 ( V_85 , V_76 ) ;
if ( F_14 ( V_85 > V_86 ) ) {
V_85 = V_86 ;
V_8 -> V_87 ++ ;
}
V_2 -> V_15 = V_74 + V_85 ;
}
V_77:
F_40 ( V_61 , V_41 ) ;
return V_41 ;
}
static void F_41 ( struct V_60 * V_61 )
{
struct V_7 * V_8 = F_25 ( V_61 ) ;
struct V_28 * V_29 ;
struct V_40 * V_41 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned int V_88 ;
while ( ( V_41 = F_19 ( V_61 , & V_8 -> V_45 ) ) != NULL )
F_42 ( V_41 ) ;
if ( ! V_8 -> V_50 )
return;
for ( V_88 = 0 ; V_88 < ( 1U << V_8 -> V_52 ) ; V_88 ++ ) {
V_29 = & V_8 -> V_50 [ V_88 ] ;
while ( ( V_10 = F_30 ( V_29 ) ) != NULL ) {
V_2 = F_4 ( V_10 , struct V_1 , V_35 ) ;
F_11 ( V_10 , V_29 ) ;
while ( ( V_41 = F_19 ( V_61 , V_2 ) ) != NULL )
F_42 ( V_41 ) ;
F_12 ( V_39 , V_2 ) ;
}
}
V_8 -> V_69 . V_25 = NULL ;
V_8 -> V_75 . V_25 = NULL ;
V_8 -> V_11 = V_89 ;
V_8 -> V_36 = 0 ;
V_8 -> V_37 = 0 ;
V_8 -> V_18 = 0 ;
}
static void F_43 ( struct V_7 * V_8 ,
struct V_28 * V_90 , V_51 V_91 ,
struct V_28 * V_92 , V_51 V_93 )
{
struct V_9 * V_94 , * * V_95 , * V_12 ;
struct V_28 * V_96 , * V_97 ;
struct V_1 * V_98 , * V_99 ;
int V_34 = 0 ;
V_51 V_88 ;
for ( V_88 = 0 ; V_88 < ( 1U << V_91 ) ; V_88 ++ ) {
V_96 = & V_90 [ V_88 ] ;
while ( ( V_94 = F_30 ( V_96 ) ) != NULL ) {
F_11 ( V_94 , V_96 ) ;
V_98 = F_4 ( V_94 , struct V_1 , V_35 ) ;
if ( F_8 ( V_98 ) ) {
V_34 ++ ;
F_12 ( V_39 , V_98 ) ;
continue;
}
V_97 = & V_92 [ F_17 ( ( V_51 ) ( long ) V_98 -> V_31 , V_93 ) ] ;
V_95 = & V_97 -> V_9 ;
V_12 = NULL ;
while ( * V_95 ) {
V_12 = * V_95 ;
V_99 = F_4 ( V_12 , struct V_1 , V_35 ) ;
F_44 ( V_99 -> V_31 == V_98 -> V_31 ) ;
if ( V_99 -> V_31 > V_98 -> V_31 )
V_95 = & V_12 -> V_16 ;
else
V_95 = & V_12 -> V_17 ;
}
F_5 ( & V_98 -> V_35 , V_12 , V_95 ) ;
F_6 ( & V_98 -> V_35 , V_97 ) ;
}
}
V_8 -> V_36 -= V_34 ;
V_8 -> V_37 -= V_34 ;
V_8 -> V_38 += V_34 ;
}
static void * F_45 ( T_2 V_100 , int V_101 )
{
void * V_102 ;
V_102 = F_46 ( V_100 , V_103 | V_104 | V_58 , V_101 ) ;
if ( ! V_102 )
V_102 = F_47 ( V_100 , V_101 ) ;
return V_102 ;
}
static void F_48 ( void * V_105 )
{
F_49 ( V_105 ) ;
}
static int F_50 ( struct V_60 * V_61 , V_51 log )
{
struct V_7 * V_8 = F_25 ( V_61 ) ;
struct V_28 * V_106 ;
void * V_107 ;
V_51 V_88 ;
if ( V_8 -> V_50 && log == V_8 -> V_52 )
return 0 ;
V_106 = F_45 ( sizeof( struct V_28 ) << log ,
F_51 ( V_61 -> V_108 ) ) ;
if ( ! V_106 )
return - V_109 ;
for ( V_88 = 0 ; V_88 < ( 1U << log ) ; V_88 ++ )
V_106 [ V_88 ] = V_89 ;
F_52 ( V_61 ) ;
V_107 = V_8 -> V_50 ;
if ( V_107 )
F_43 ( V_8 , V_107 , V_8 -> V_52 , V_106 , log ) ;
V_8 -> V_50 = V_106 ;
V_8 -> V_52 = log ;
F_53 ( V_61 ) ;
F_48 ( V_107 ) ;
return 0 ;
}
static int F_54 ( struct V_60 * V_61 , struct V_110 * V_111 )
{
struct V_7 * V_8 = F_25 ( V_61 ) ;
struct V_110 * V_112 [ V_113 + 1 ] ;
int V_114 , V_115 = 0 ;
V_51 V_116 ;
if ( ! V_111 )
return - V_117 ;
V_114 = F_55 ( V_112 , V_113 , V_111 , V_118 ) ;
if ( V_114 < 0 )
return V_114 ;
F_52 ( V_61 ) ;
V_116 = V_8 -> V_52 ;
if ( V_112 [ V_119 ] ) {
V_51 V_120 = F_56 ( V_112 [ V_119 ] ) ;
if ( V_120 >= 1 && V_120 <= F_57 ( 256 * 1024 ) )
V_116 = V_120 ;
else
V_114 = - V_117 ;
}
if ( V_112 [ V_121 ] )
V_61 -> V_65 = F_56 ( V_112 [ V_121 ] ) ;
if ( V_112 [ V_122 ] )
V_8 -> V_66 = F_56 ( V_112 [ V_122 ] ) ;
if ( V_112 [ V_123 ] ) {
V_51 V_71 = F_56 ( V_112 [ V_123 ] ) ;
if ( V_71 > 0 )
V_8 -> V_71 = V_71 ;
else
V_114 = - V_117 ;
}
if ( V_112 [ V_124 ] )
V_8 -> V_56 = F_56 ( V_112 [ V_124 ] ) ;
if ( V_112 [ V_125 ] )
F_58 ( L_1 ,
F_56 ( V_112 [ V_125 ] ) ) ;
if ( V_112 [ V_126 ] )
V_8 -> V_82 = F_56 ( V_112 [ V_126 ] ) ;
if ( V_112 [ V_127 ] ) {
V_51 V_128 = F_56 ( V_112 [ V_127 ] ) ;
if ( V_128 <= 1 )
V_8 -> V_81 = V_128 ;
else
V_114 = - V_117 ;
}
if ( V_112 [ V_129 ] ) {
V_51 V_130 = F_56 ( V_112 [ V_129 ] ) ;
V_8 -> V_70 = F_59 ( V_130 ) ;
}
if ( V_112 [ V_131 ] )
V_8 -> V_49 = F_56 ( V_112 [ V_131 ] ) ;
if ( ! V_114 ) {
F_53 ( V_61 ) ;
V_114 = F_50 ( V_61 , V_116 ) ;
F_52 ( V_61 ) ;
}
while ( V_61 -> V_8 . V_62 > V_61 -> V_65 ) {
struct V_40 * V_41 = F_31 ( V_61 ) ;
if ( ! V_41 )
break;
F_42 ( V_41 ) ;
V_115 ++ ;
}
F_60 ( V_61 , V_115 ) ;
F_53 ( V_61 ) ;
return V_114 ;
}
static void F_61 ( struct V_60 * V_61 )
{
struct V_7 * V_8 = F_25 ( V_61 ) ;
F_41 ( V_61 ) ;
F_48 ( V_8 -> V_50 ) ;
F_62 ( & V_8 -> V_79 ) ;
}
static int F_63 ( struct V_60 * V_61 , struct V_110 * V_111 )
{
struct V_7 * V_8 = F_25 ( V_61 ) ;
int V_114 ;
V_61 -> V_65 = 10000 ;
V_8 -> V_66 = 100 ;
V_8 -> V_71 = 2 * F_64 ( F_65 ( V_61 ) ) ;
V_8 -> V_56 = 10 * F_64 ( F_65 ( V_61 ) ) ;
V_8 -> V_70 = F_66 ( 40 ) ;
V_8 -> V_82 = ~ 0U ;
V_8 -> V_81 = 1 ;
V_8 -> V_69 . V_25 = NULL ;
V_8 -> V_75 . V_25 = NULL ;
V_8 -> V_11 = V_89 ;
V_8 -> V_50 = NULL ;
V_8 -> V_52 = F_57 ( 1024 ) ;
V_8 -> V_49 = 1024 - 1 ;
F_67 ( & V_8 -> V_79 , V_61 ) ;
if ( V_111 )
V_114 = F_54 ( V_61 , V_111 ) ;
else
V_114 = F_50 ( V_61 , V_8 -> V_52 ) ;
return V_114 ;
}
static int F_68 ( struct V_60 * V_61 , struct V_40 * V_41 )
{
struct V_7 * V_8 = F_25 ( V_61 ) ;
struct V_110 * V_132 ;
V_132 = F_69 ( V_41 , V_133 ) ;
if ( V_132 == NULL )
goto V_134;
if ( F_70 ( V_41 , V_121 , V_61 -> V_65 ) ||
F_70 ( V_41 , V_122 , V_8 -> V_66 ) ||
F_70 ( V_41 , V_123 , V_8 -> V_71 ) ||
F_70 ( V_41 , V_124 , V_8 -> V_56 ) ||
F_70 ( V_41 , V_127 , V_8 -> V_81 ) ||
F_70 ( V_41 , V_126 , V_8 -> V_82 ) ||
F_70 ( V_41 , V_129 ,
F_71 ( V_8 -> V_70 ) ) ||
F_70 ( V_41 , V_131 , V_8 -> V_49 ) ||
F_70 ( V_41 , V_119 , V_8 -> V_52 ) )
goto V_134;
return F_72 ( V_41 , V_132 ) ;
V_134:
return - 1 ;
}
static int F_73 ( struct V_60 * V_61 , struct V_135 * V_136 )
{
struct V_7 * V_8 = F_25 ( V_61 ) ;
T_1 V_74 = F_32 () ;
struct V_137 V_138 = {
. V_139 = V_8 -> V_38 ,
. V_140 = V_8 -> V_72 ,
. V_141 = V_8 -> V_68 ,
. V_20 = V_8 -> V_19 ,
. V_142 = V_8 -> V_67 ,
. V_143 = V_8 -> V_87 ,
. V_144 = V_8 -> V_59 ,
. V_36 = V_8 -> V_36 ,
. V_37 = V_8 -> V_37 ,
. V_18 = V_8 -> V_18 ,
. V_21 = V_8 -> V_21 - V_74 ,
} ;
return F_74 ( V_136 , & V_138 , sizeof( V_138 ) ) ;
}
static int T_3 F_75 ( void )
{
int V_145 ;
V_39 = F_76 ( L_2 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_39 )
return - V_109 ;
V_145 = F_77 ( & V_146 ) ;
if ( V_145 )
F_78 ( V_39 ) ;
return V_145 ;
}
static void T_4 F_79 ( void )
{
F_80 ( & V_146 ) ;
F_78 ( V_39 ) ;
}
