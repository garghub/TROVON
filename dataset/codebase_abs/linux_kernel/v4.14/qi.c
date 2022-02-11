int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
T_1 V_7 ;
int V_8 ;
int V_9 = 0 ;
F_2 ( & V_6 ) ;
F_3 ( & V_6 , F_4 ( & V_4 -> V_10 [ 1 ] ) ) ;
V_7 = F_5 ( V_2 , V_4 -> V_10 , sizeof( V_4 -> V_10 ) ,
V_11 ) ;
if ( F_6 ( V_2 , V_7 ) ) {
F_7 ( V_2 , L_1 ) ;
return - V_12 ;
}
F_8 ( & V_6 , V_7 ) ;
do {
V_8 = F_9 ( V_4 -> V_13 -> V_14 , & V_6 ) ;
if ( F_10 ( ! V_8 ) )
return 0 ;
if ( V_8 != - V_15 )
break;
V_9 ++ ;
} while ( V_9 < V_16 );
F_7 ( V_2 , L_2 , V_8 ) ;
return V_8 ;
}
static void F_11 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const union V_21 * V_22 )
{
const struct V_5 * V_6 ;
struct V_3 * V_23 ;
struct V_1 * V_2 = & ( F_12 ( & V_24 ) -> V_25 . V_26 ) ;
V_6 = & V_22 -> V_27 . V_6 ;
if ( F_13 ( V_6 ) != V_28 ) {
F_7 ( V_2 , L_3 ) ;
return;
}
V_23 = (struct V_3 * ) F_14 ( F_15 ( V_6 ) ) ;
if ( ! V_23 ) {
F_7 ( V_2 ,
L_4 ) ;
return;
}
F_16 ( V_23 -> V_13 -> V_2 , F_17 ( V_6 ) ,
sizeof( V_23 -> V_10 ) , V_11 ) ;
V_23 -> V_29 ( V_23 , - V_12 ) ;
}
static struct V_19 * F_18 ( struct V_1 * V_2 ,
struct V_19 * V_30 ,
T_1 V_31 ,
int V_32 )
{
int V_8 ;
struct V_19 * V_14 ;
struct V_33 V_34 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_35 ) ;
if ( ! V_14 )
return F_20 ( - V_36 ) ;
V_14 -> V_37 . V_27 = F_11 ;
V_14 -> V_37 . V_38 = NULL ;
V_8 = F_21 ( 0 , V_39 |
V_40 , V_14 ) ;
if ( V_8 ) {
F_7 ( V_2 , L_5 ) ;
goto V_41;
}
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_42 = F_22 ( V_43 | V_44 |
V_45 |
V_46 | V_47 ) ;
V_34 . V_48 . V_49 = F_22 ( V_50 | V_51 ) ;
F_23 ( & V_34 . V_48 , V_52 , 2 ) ;
V_34 . V_48 . V_53 = F_24 ( F_25 ( V_30 ) ) ;
F_26 ( & V_34 . V_48 , V_31 ) ;
V_34 . V_48 . V_54 = V_55 . V_56 . V_57 ;
V_8 = F_27 ( V_14 , V_32 , & V_34 ) ;
if ( V_8 ) {
F_7 ( V_2 , L_6 ) ;
goto V_58;
}
F_28 ( V_2 , L_7 , V_14 -> V_59 ,
F_29 () ) ;
return V_14 ;
V_58:
F_30 ( V_14 ) ;
V_41:
F_31 ( V_14 ) ;
return F_20 ( V_8 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_8 ;
V_8 = F_33 ( V_20 , V_60 |
V_61 ,
V_62 |
V_63 ) ;
if ( V_8 ) {
F_7 ( V_2 , L_8 , V_20 -> V_59 ) ;
return V_8 ;
}
do {
struct V_17 * V_64 ;
V_64 = F_34 ( F_29 () ) ;
F_35 ( V_64 , 16 ) ;
} while ( V_20 -> V_65 & V_66 );
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
T_2 V_65 ;
int V_8 ;
V_8 = F_37 ( V_20 , & V_65 ) ;
if ( V_8 < 0 ) {
F_7 ( V_2 , L_9 , V_8 ) ;
return V_8 ;
}
if ( ! V_8 )
goto V_67;
if ( V_8 == 1 ) {
do {
F_38 ( 20 ) ;
} while ( V_20 -> V_68 != V_69 );
F_39 ( V_20 -> V_65 & V_70 ) ;
F_39 ( V_20 -> V_65 & V_71 ) ;
}
V_67:
if ( V_20 -> V_65 & V_66 ) {
V_8 = F_32 ( V_2 , V_20 ) ;
if ( V_8 ) {
F_7 ( V_2 , L_10 ,
V_20 -> V_59 ) ;
return V_8 ;
}
}
V_8 = F_40 ( V_20 ) ;
if ( V_8 )
F_7 ( V_2 , L_11 , V_20 -> V_59 ) ;
F_30 ( V_20 ) ;
F_31 ( V_20 ) ;
return V_8 ;
}
static int F_41 ( struct V_19 * V_20 )
{
int V_8 ;
struct V_72 V_73 ;
do {
V_8 = F_42 ( V_20 , & V_73 ) ;
if ( V_8 )
return V_8 ;
if ( ! F_43 ( & V_73 , V_74 ) )
break;
F_38 ( 20 ) ;
} while ( 1 );
F_38 ( 20 ) ;
return 0 ;
}
int F_44 ( struct V_75 * V_13 , T_2 * V_76 )
{
int V_8 ;
T_2 V_77 ;
struct V_19 * V_78 , * V_79 ;
struct V_1 * V_2 = V_13 -> V_2 ;
V_77 = F_45 ( V_76 ) ;
if ( V_77 > V_80 ) {
F_7 ( V_2 , L_12 , V_77 ) ;
return - V_81 ;
}
V_79 = V_13 -> V_14 ;
V_78 = F_18 ( V_13 -> V_2 , V_13 -> V_30 ,
V_13 -> V_82 , 0 ) ;
if ( F_46 ( F_47 ( V_78 ) ) ) {
F_7 ( V_2 , L_13 ) ;
return F_48 ( V_78 ) ;
}
V_13 -> V_14 = V_78 ;
V_8 = F_41 ( V_79 ) ;
if ( V_8 ) {
F_7 ( V_2 , L_14 , V_8 ) ;
V_13 -> V_14 = V_79 ;
if ( F_36 ( V_2 , V_78 ) )
F_49 ( V_2 , L_15 ) ;
return V_8 ;
}
V_13 -> V_83 [ 0 ] = F_50 ( ( 1 << V_84 ) |
V_77 ) ;
memcpy ( V_13 -> V_76 , V_76 , F_51 ( V_76 ) ) ;
F_52 ( V_2 , V_13 -> V_82 ,
sizeof( V_13 -> V_76 ) +
sizeof( V_13 -> V_83 ) ,
V_11 ) ;
V_8 = F_53 ( V_78 ) ;
if ( V_8 ) {
F_7 ( V_2 , L_16 , V_8 ) ;
V_13 -> V_14 = V_79 ;
if ( F_36 ( V_2 , V_78 ) )
F_49 ( V_2 , L_15 ) ;
} else if ( F_36 ( V_2 , V_79 ) ) {
F_49 ( V_2 , L_17 ) ;
}
return 0 ;
}
struct V_75 * F_54 ( struct V_1 * V_2 ,
int * V_85 ,
T_2 * V_76 )
{
T_3 V_86 ;
T_2 V_77 ;
T_1 V_31 ;
struct V_75 * V_13 ;
const T_4 * V_87 = F_55 () ;
V_77 = F_45 ( V_76 ) ;
if ( V_77 > V_80 ) {
F_7 ( V_2 , L_12 ,
V_77 ) ;
return F_20 ( - V_81 ) ;
}
V_13 = F_19 ( sizeof( * V_13 ) , V_35 ) ;
if ( ! V_13 )
return F_20 ( - V_36 ) ;
V_13 -> V_83 [ 0 ] = F_50 ( ( 1 << V_84 ) |
V_77 ) ;
memcpy ( V_13 -> V_76 , V_76 , F_51 ( V_76 ) ) ;
V_86 = sizeof( V_13 -> V_83 ) + sizeof( V_13 -> V_76 ) ;
V_31 = F_5 ( V_2 , V_13 -> V_83 , V_86 ,
V_11 ) ;
if ( F_6 ( V_2 , V_31 ) ) {
F_7 ( V_2 , L_18 ) ;
F_31 ( V_13 ) ;
return F_20 ( - V_36 ) ;
}
V_13 -> V_82 = V_31 ;
if ( ! F_56 ( * V_85 , V_87 ) ) {
int * V_88 = & F_57 ( V_89 ) ;
* V_88 = F_58 ( * V_88 , V_87 ) ;
if ( * V_88 >= V_90 )
* V_88 = F_59 ( V_87 ) ;
* V_85 = * V_88 ;
F_60 ( V_89 ) ;
}
V_13 -> V_85 = * V_85 ;
V_13 -> V_30 = F_61 ( V_24 . V_30 , V_13 -> V_85 ) ;
V_13 -> V_14 = F_18 ( V_2 , V_13 -> V_30 , V_31 ,
V_91 ) ;
if ( F_46 ( F_47 ( V_13 -> V_14 ) ) ) {
F_7 ( V_2 , L_19 ) ;
F_16 ( V_2 , V_31 , V_86 , V_11 ) ;
F_31 ( V_13 ) ;
return F_20 ( - V_36 ) ;
}
V_13 -> V_2 = V_2 ;
return V_13 ;
}
void * F_62 ( T_5 V_65 )
{
return F_63 ( V_92 , V_65 ) ;
}
void F_64 ( void * V_93 )
{
F_65 ( V_92 , V_93 ) ;
}
static int F_66 ( struct V_94 * V_95 , int V_96 )
{
struct V_97 * V_73 = F_67 ( V_95 , struct V_97 , V_98 ) ;
int V_99 = F_35 ( V_73 -> V_64 , V_96 ) ;
if ( V_99 < V_96 ) {
F_68 ( V_95 ) ;
F_69 ( V_73 -> V_64 , V_100 ) ;
}
return V_99 ;
}
void F_70 ( struct V_75 * V_13 )
{
if ( F_47 ( V_13 ) )
return;
if ( F_36 ( V_13 -> V_2 , V_13 -> V_14 ) )
F_7 ( V_13 -> V_2 , L_20 ) ;
F_16 ( V_13 -> V_2 , V_13 -> V_82 ,
sizeof( V_13 -> V_76 ) + sizeof( V_13 -> V_83 ) ,
V_11 ) ;
F_31 ( V_13 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_101 , V_8 ;
struct V_102 * V_103 = F_72 ( V_2 ) ;
const T_4 * V_87 = F_55 () ;
struct V_104 V_105 = V_106 -> V_107 ;
F_73 (i, cpus) {
struct V_94 * V_98 ;
V_98 = & F_74 ( & V_24 . V_97 , V_101 ) -> V_98 ;
F_75 ( V_98 ) ;
F_76 ( V_98 ) ;
if ( F_36 ( V_2 , F_61 ( V_24 . V_30 , V_101 ) ) )
F_7 ( V_2 , L_21 , V_101 ) ;
}
F_77 ( V_106 , F_78 ( V_108 ) ) ;
V_8 = F_79 ( & V_103 -> V_56 ) ;
if ( V_8 )
F_7 ( V_2 , L_22 , V_8 ) ;
else
F_80 ( V_103 -> V_56 . V_57 ) ;
F_81 ( V_92 ) ;
F_77 ( V_106 , & V_105 ) ;
F_82 ( V_103 -> V_109 ) ;
return V_8 ;
}
static void F_83 ( struct V_17 * V_18 , struct V_110 * V_56 , int V_111 )
{
V_112 = V_111 ;
if ( V_111 ) {
#ifdef F_84
V_113 ++ ;
#endif
F_85 ( L_23 ) ;
} else {
F_85 ( L_24 ) ;
}
}
static int F_86 ( struct V_17 * V_64 , struct V_97 * V_73 )
{
if ( F_46 ( F_87 () || ! F_88 () ) ) {
F_89 ( V_64 , V_100 ) ;
V_73 -> V_64 = V_64 ;
F_90 ( & V_73 -> V_98 ) ;
return 1 ;
}
return 0 ;
}
static enum V_114 F_91 ( struct V_17 * V_64 ,
struct V_19 * V_30 ,
const struct V_115 * V_116 )
{
struct V_97 * V_97 = F_12 ( & V_24 . V_97 ) ;
struct V_3 * V_23 ;
const struct V_5 * V_6 ;
struct V_1 * V_2 = & ( F_12 ( & V_24 ) -> V_25 . V_26 ) ;
T_2 V_117 ;
if ( F_86 ( V_64 , V_97 ) )
return V_118 ;
V_6 = & V_116 -> V_6 ;
V_117 = F_92 ( V_6 -> V_117 ) ;
if ( F_46 ( V_117 ) )
F_7 ( V_2 , L_25 , V_117 ) ;
if ( F_46 ( F_13 ( V_6 ) != V_28 ) ) {
F_7 ( V_2 , L_3 ) ;
return V_119 ;
}
V_23 = (struct V_3 * ) F_14 ( F_15 ( V_6 ) ) ;
if ( F_46 ( ! V_23 ) ) {
F_7 ( V_2 ,
L_26 ) ;
return V_119 ;
}
F_16 ( V_23 -> V_13 -> V_2 , F_17 ( V_6 ) ,
sizeof( V_23 -> V_10 ) , V_11 ) ;
V_23 -> V_29 ( V_23 , V_117 ) ;
return V_119 ;
}
static int F_93 ( struct V_1 * V_2 , unsigned int V_85 )
{
struct V_33 V_34 ;
struct V_19 * V_20 ;
int V_8 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_120 | V_121 ) ;
if ( ! V_20 )
return - V_36 ;
V_20 -> V_37 . V_116 = F_91 ;
V_8 = F_21 ( 0 , V_122 |
V_39 , V_20 ) ;
if ( V_8 ) {
F_7 ( V_2 , L_27 ) ;
F_31 ( V_20 ) ;
return - V_123 ;
}
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_42 = F_22 ( V_43 | V_44 |
V_45 |
V_46 | V_47 ) ;
V_34 . V_48 . V_49 = F_22 ( V_124 |
V_50 | V_51 ) ;
F_23 ( & V_34 . V_48 , F_94 ( V_85 ) , 3 ) ;
V_34 . V_48 . V_54 = V_55 . V_56 . V_57 ;
V_34 . V_48 . V_82 . V_125 . V_126 = V_127 |
V_128 ;
F_95 ( & V_34 . V_48 , 0 , 1 , 1 ) ;
V_8 = F_27 ( V_20 , V_91 , & V_34 ) ;
if ( V_8 ) {
F_7 ( V_2 , L_28 ) ;
F_31 ( V_20 ) ;
return - V_123 ;
}
F_61 ( V_24 . V_30 , V_85 ) = V_20 ;
F_28 ( V_2 , L_29 , V_20 -> V_59 , V_85 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_129 V_34 ;
const T_6 V_87 = * ( T_6 * ) F_55 () ;
const int V_130 = F_97 ( V_87 ) ;
const T_6 V_131 = V_130 * V_132 ;
V_8 = F_98 ( & V_55 . V_56 . V_57 ) ;
if ( V_8 ) {
F_7 ( V_2 , L_30 , V_8 ) ;
return V_8 ;
}
V_55 . V_56 . V_37 = F_83 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_42 = F_22 ( V_133 | V_134 |
V_135 ) ;
V_34 . V_56 . V_136 = V_137 ;
V_34 . V_56 . V_138 = V_139 ;
F_99 ( & V_34 . V_56 . V_140 , V_131 , 1 ) ;
V_8 = F_100 ( & V_55 . V_56 , V_141 , & V_34 ) ;
if ( V_8 ) {
F_7 ( V_2 , L_31 , V_8 ,
V_55 . V_56 . V_57 ) ;
return V_8 ;
}
F_28 ( V_2 , L_32 , V_131 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_8 , V_101 ;
const T_4 * V_87 = F_55 () ;
F_73 (i, cpus) {
V_8 = F_93 ( V_2 , V_101 ) ;
if ( V_8 ) {
F_7 ( V_2 , L_33 , V_101 ) ;
return V_8 ;
}
}
return 0 ;
}
static void F_102 ( void )
{
int V_101 ;
const T_4 * V_87 = F_55 () ;
F_73 (i, cpus)
F_31 ( F_61 ( V_24 . V_30 , V_101 ) ) ;
}
int F_103 ( struct V_142 * V_143 )
{
int V_144 , V_101 ;
struct V_142 * V_109 ;
struct V_1 * V_145 = & V_143 -> V_26 , * V_2 ;
struct V_146 * V_147 ;
const T_4 * V_87 = F_55 () ;
struct V_104 V_105 = V_106 -> V_107 ;
static struct V_148 V_149 = {
. V_150 = L_34 ,
. V_151 = V_152
} ;
V_108 = F_59 ( V_87 ) ;
F_77 ( V_106 , F_78 ( V_108 ) ) ;
V_149 . V_153 = V_145 ;
V_149 . V_154 = F_104 ( V_145 ) ;
V_109 = F_105 ( & V_149 ) ;
if ( F_106 ( V_109 ) )
return F_48 ( V_109 ) ;
F_107 ( & V_109 -> V_26 , F_108 ( V_145 ) ) ;
V_147 = F_72 ( V_145 ) ;
V_2 = & V_109 -> V_26 ;
V_55 . V_109 = V_109 ;
F_109 ( V_2 , & V_55 ) ;
V_144 = F_96 ( V_2 ) ;
if ( V_144 ) {
F_7 ( V_2 , L_35 , V_144 ) ;
F_82 ( V_109 ) ;
return V_144 ;
}
V_144 = F_101 ( V_2 ) ;
if ( V_144 ) {
F_7 ( V_2 , L_36 , V_144 ) ;
F_102 () ;
F_82 ( V_109 ) ;
return V_144 ;
}
F_73 (i, cpus) {
struct V_155 * V_103 = F_74 ( & V_24 , V_101 ) ;
struct V_97 * V_97 = & V_103 -> V_97 ;
struct V_94 * V_98 = & V_97 -> V_98 ;
struct V_156 * V_25 = & V_103 -> V_25 ;
V_25 -> V_26 = * V_2 ;
F_110 ( & V_25 -> V_157 ) ;
F_111 ( V_25 , V_98 , F_66 ,
V_158 ) ;
F_112 ( V_98 ) ;
}
V_147 -> V_2 = V_2 ;
V_92 = F_113 ( L_37 , V_159 , 0 ,
V_160 , NULL ) ;
if ( ! V_92 ) {
F_7 ( V_2 , L_38 ) ;
F_102 () ;
F_82 ( V_109 ) ;
return - V_36 ;
}
F_77 ( V_106 , & V_105 ) ;
#ifdef F_84
F_114 ( L_39 , 0444 , V_147 -> V_161 ,
& V_113 , & V_162 ) ;
#endif
F_115 ( V_2 , L_40 ) ;
return 0 ;
}
