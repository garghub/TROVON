static inline void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
V_2 -> V_3 = V_3 ;
}
struct V_1 * F_2 ( unsigned V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list) {
if ( V_6 -> V_9 <= V_4 &&
V_6 -> V_9 + V_6 -> V_10 > V_4 ) {
F_5 ( & V_8 , V_7 ) ;
return & V_6 -> V_11 [ V_4 - V_6 -> V_9 ] ;
}
}
F_5 ( & V_8 , V_7 ) ;
if ( ! F_6 ( V_4 ) )
F_7 ( 1 , L_1 , V_4 ) ;
return NULL ;
}
struct V_1 * F_8 ( struct V_12 * V_13 ,
T_1 V_14 )
{
struct V_5 * V_6 = V_13 -> V_15 ;
if ( V_14 >= V_6 -> V_10 )
return F_9 ( - V_16 ) ;
return & V_6 -> V_11 [ V_14 ] ;
}
int F_10 ( const struct V_1 * V_17 )
{
return V_17 -> V_6 -> V_9 + ( V_17 - & V_17 -> V_6 -> V_11 [ 0 ] ) ;
}
struct V_12 * F_11 ( const struct V_1 * V_17 )
{
if ( ! V_17 || ! V_17 -> V_6 || ! V_17 -> V_6 -> V_13 )
return NULL ;
return V_17 -> V_6 -> V_13 ;
}
static int F_12 ( int V_10 )
{
struct V_5 * V_6 ;
int V_9 = V_18 - V_10 ;
F_13 (gdev, &gpio_devices, list) {
if ( V_6 -> V_9 + V_6 -> V_10 <= V_9 )
break;
else
V_9 = V_6 -> V_9 - V_10 ;
}
if ( F_6 ( V_9 ) ) {
F_14 ( L_2 , V_19 , V_9 ) ;
return V_9 ;
} else {
F_15 ( L_3 , V_19 ) ;
return - V_20 ;
}
}
int F_16 ( struct V_1 * V_17 )
{
struct V_12 * V_13 ;
unsigned V_21 ;
int V_22 = - V_16 ;
V_13 = F_11 ( V_17 ) ;
V_21 = F_17 ( V_17 ) ;
if ( ! V_13 -> V_23 )
return V_22 ;
V_22 = V_13 -> V_23 ( V_13 , V_21 ) ;
if ( V_22 > 0 ) {
V_22 = 1 ;
F_18 ( V_24 , & V_17 -> V_7 ) ;
}
if ( V_22 == 0 ) {
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
return V_22 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_5 * V_25 , * V_26 ;
if ( F_21 ( & V_27 ) ) {
F_22 ( & V_6 -> V_28 , & V_27 ) ;
return 0 ;
}
V_26 = F_23 ( V_27 . V_26 , struct V_5 , V_28 ) ;
if ( V_6 -> V_9 + V_6 -> V_10 <= V_26 -> V_9 ) {
F_24 ( & V_6 -> V_28 , & V_27 ) ;
return 0 ;
}
V_25 = F_23 ( V_27 . V_25 , struct V_5 , V_28 ) ;
if ( V_25 -> V_9 + V_25 -> V_10 <= V_6 -> V_9 ) {
F_22 ( & V_6 -> V_28 , & V_27 ) ;
return 0 ;
}
F_25 (prev, next, &gpio_devices, list) {
if ( & V_26 -> V_28 == & V_27 )
break;
if ( V_25 -> V_9 + V_25 -> V_10 <= V_6 -> V_9
&& V_6 -> V_9 + V_6 -> V_10 <= V_26 -> V_9 ) {
F_24 ( & V_6 -> V_28 , & V_25 -> V_28 ) ;
return 0 ;
}
}
F_26 ( & V_6 -> V_29 , L_4 ) ;
return - V_30 ;
}
static struct V_1 * F_27 ( const char * const V_31 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list) {
int V_32 ;
for ( V_32 = 0 ; V_32 != V_6 -> V_10 ; ++ V_32 ) {
struct V_1 * V_17 = & V_6 -> V_11 [ V_32 ] ;
if ( ! V_17 -> V_31 || ! V_31 )
continue;
if ( ! strcmp ( V_17 -> V_31 , V_31 ) ) {
F_5 ( & V_8 , V_7 ) ;
return V_17 ;
}
}
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static int F_28 ( struct V_12 * V_33 )
{
struct V_5 * V_6 = V_33 -> V_15 ;
int V_32 ;
if ( ! V_33 -> V_34 )
return 0 ;
for ( V_32 = 0 ; V_32 != V_33 -> V_10 ; ++ V_32 ) {
struct V_1 * V_4 ;
V_4 = F_27 ( V_33 -> V_34 [ V_32 ] ) ;
if ( V_4 )
F_29 ( & V_6 -> V_29 ,
L_5 ,
V_33 -> V_34 [ V_32 ] ) ;
}
for ( V_32 = 0 ; V_32 != V_33 -> V_10 ; ++ V_32 )
V_6 -> V_11 [ V_32 ] . V_31 = V_33 -> V_34 [ V_32 ] ;
return 0 ;
}
static long F_30 ( struct V_35 * V_36 , unsigned int V_37 ,
unsigned long V_38 )
{
struct V_39 * V_40 = V_36 -> V_41 ;
void T_2 * V_42 = ( void T_2 * ) V_38 ;
struct V_43 V_44 ;
int V_32 ;
if ( V_37 == V_45 ) {
int V_46 ;
for ( V_32 = 0 ; V_32 < V_40 -> V_47 ; V_32 ++ ) {
V_46 = F_31 ( V_40 -> V_11 [ V_32 ] ) ;
if ( V_46 < 0 )
return V_46 ;
V_44 . V_48 [ V_32 ] = V_46 ;
}
if ( F_32 ( V_42 , & V_44 , sizeof( V_44 ) ) )
return - V_49 ;
return 0 ;
} else if ( V_37 == V_50 ) {
int V_51 [ V_52 ] ;
if ( F_33 ( & V_44 , V_42 , sizeof( V_44 ) ) )
return - V_49 ;
for ( V_32 = 0 ; V_32 < V_40 -> V_47 ; V_32 ++ )
V_51 [ V_32 ] = ! ! V_44 . V_48 [ V_32 ] ;
F_34 ( false ,
true ,
V_40 -> V_47 ,
V_40 -> V_11 ,
V_51 ) ;
return 0 ;
}
return - V_16 ;
}
static long F_35 ( struct V_35 * V_36 , unsigned int V_37 ,
unsigned long V_38 )
{
return F_30 ( V_36 , V_37 , ( unsigned long ) F_36 ( V_38 ) ) ;
}
static int F_37 ( struct V_53 * V_53 , struct V_35 * V_36 )
{
struct V_39 * V_40 = V_36 -> V_41 ;
struct V_5 * V_6 = V_40 -> V_6 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_40 -> V_47 ; V_32 ++ )
F_38 ( V_40 -> V_11 [ V_32 ] ) ;
F_39 ( V_40 -> V_3 ) ;
F_39 ( V_40 ) ;
F_40 ( & V_6 -> V_29 ) ;
return 0 ;
}
static int F_41 ( struct V_5 * V_6 , void T_2 * V_42 )
{
struct V_54 V_55 ;
struct V_39 * V_40 ;
int V_56 , V_32 , V_57 ;
if ( F_33 ( & V_55 , V_42 , sizeof( V_55 ) ) )
return - V_49 ;
if ( ( V_55 . V_58 == 0 ) || ( V_55 . V_58 > V_52 ) )
return - V_16 ;
V_40 = F_42 ( sizeof( * V_40 ) , V_59 ) ;
if ( ! V_40 )
return - V_60 ;
V_40 -> V_6 = V_6 ;
F_43 ( & V_6 -> V_29 ) ;
V_55 . V_61 [ sizeof( V_55 . V_61 ) - 1 ] = '\0' ;
if ( strlen ( V_55 . V_61 ) ) {
V_40 -> V_3 = F_44 ( V_55 . V_61 ,
V_59 ) ;
if ( ! V_40 -> V_3 ) {
V_57 = - V_60 ;
goto V_62;
}
}
for ( V_32 = 0 ; V_32 < V_55 . V_58 ; V_32 ++ ) {
T_3 V_21 = V_55 . V_63 [ V_32 ] ;
T_3 V_64 = V_55 . V_7 ;
struct V_1 * V_17 ;
V_17 = & V_6 -> V_11 [ V_21 ] ;
V_57 = F_45 ( V_17 , V_40 -> V_3 ) ;
if ( V_57 )
goto V_65;
V_40 -> V_11 [ V_32 ] = V_17 ;
if ( V_64 & V_66 )
F_19 ( V_67 , & V_17 -> V_7 ) ;
if ( V_64 & V_68 )
F_19 ( V_69 , & V_17 -> V_7 ) ;
if ( V_64 & V_70 )
F_19 ( V_71 , & V_17 -> V_7 ) ;
if ( V_64 & V_72 ) {
int V_46 = ! ! V_55 . V_73 [ V_32 ] ;
V_57 = F_46 ( V_17 , V_46 ) ;
if ( V_57 )
goto V_65;
} else if ( V_64 & V_74 ) {
V_57 = F_47 ( V_17 ) ;
if ( V_57 )
goto V_65;
}
F_48 ( & V_6 -> V_29 , L_6 ,
V_21 ) ;
}
V_32 -- ;
V_40 -> V_47 = V_55 . V_58 ;
V_56 = F_49 ( L_7 ,
& V_75 ,
V_40 ,
V_76 | V_77 ) ;
if ( V_56 < 0 ) {
V_57 = V_56 ;
goto V_65;
}
V_55 . V_56 = V_56 ;
if ( F_32 ( V_42 , & V_55 , sizeof( V_55 ) ) ) {
V_57 = - V_49 ;
goto V_65;
}
F_48 ( & V_6 -> V_29 , L_8 ,
V_40 -> V_47 ) ;
return 0 ;
V_65:
for (; V_32 >= 0 ; V_32 -- )
F_38 ( V_40 -> V_11 [ V_32 ] ) ;
F_39 ( V_40 -> V_3 ) ;
V_62:
F_39 ( V_40 ) ;
F_40 ( & V_6 -> V_29 ) ;
return V_57 ;
}
static unsigned int F_50 ( struct V_35 * V_36 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = V_36 -> V_41 ;
unsigned int V_82 = 0 ;
F_51 ( V_36 , & V_81 -> V_79 , V_79 ) ;
if ( ! F_52 ( & V_81 -> V_82 ) )
V_82 = V_83 | V_84 ;
return V_82 ;
}
static T_4 F_53 ( struct V_35 * V_36 ,
char T_2 * V_85 ,
T_5 V_86 ,
T_6 * V_87 )
{
struct V_80 * V_81 = V_36 -> V_41 ;
unsigned int V_88 ;
int V_57 ;
if ( V_86 < sizeof( struct V_89 ) )
return - V_16 ;
do {
if ( F_52 ( & V_81 -> V_82 ) ) {
if ( V_36 -> V_90 & V_91 )
return - V_92 ;
V_57 = F_54 ( V_81 -> V_79 ,
! F_52 ( & V_81 -> V_82 ) ) ;
if ( V_57 )
return V_57 ;
}
if ( F_55 ( & V_81 -> V_93 ) )
return - V_94 ;
V_57 = F_56 ( & V_81 -> V_82 , V_85 , V_86 , & V_88 ) ;
F_57 ( & V_81 -> V_93 ) ;
if ( V_57 )
return V_57 ;
if ( V_88 == 0 && ( V_36 -> V_90 & V_91 ) )
return - V_92 ;
} while ( V_88 == 0 );
return V_88 ;
}
static int F_58 ( struct V_53 * V_53 , struct V_35 * V_36 )
{
struct V_80 * V_81 = V_36 -> V_41 ;
struct V_5 * V_6 = V_81 -> V_6 ;
F_59 ( V_81 -> V_95 , V_81 ) ;
F_38 ( V_81 -> V_17 ) ;
F_39 ( V_81 -> V_3 ) ;
F_39 ( V_81 ) ;
F_40 ( & V_6 -> V_29 ) ;
return 0 ;
}
static long F_60 ( struct V_35 * V_36 , unsigned int V_37 ,
unsigned long V_38 )
{
struct V_80 * V_81 = V_36 -> V_41 ;
void T_2 * V_42 = ( void T_2 * ) V_38 ;
struct V_43 V_44 ;
if ( V_37 == V_45 ) {
int V_46 ;
V_46 = F_31 ( V_81 -> V_17 ) ;
if ( V_46 < 0 )
return V_46 ;
V_44 . V_48 [ 0 ] = V_46 ;
if ( F_32 ( V_42 , & V_44 , sizeof( V_44 ) ) )
return - V_49 ;
return 0 ;
}
return - V_16 ;
}
static long F_61 ( struct V_35 * V_36 , unsigned int V_37 ,
unsigned long V_38 )
{
return F_60 ( V_36 , V_37 , ( unsigned long ) F_36 ( V_38 ) ) ;
}
static T_7 F_62 ( int V_95 , void * V_96 )
{
struct V_80 * V_81 = V_96 ;
struct V_89 V_97 ;
int V_57 ;
V_97 . V_98 = F_63 () ;
if ( V_81 -> V_99 & V_100 ) {
int V_101 = F_31 ( V_81 -> V_17 ) ;
if ( V_101 )
V_97 . V_102 = V_103 ;
else
V_97 . V_102 = V_104 ;
} else if ( V_81 -> V_99 & V_105 ) {
V_97 . V_102 = V_103 ;
} else if ( V_81 -> V_99 & V_106 ) {
V_97 . V_102 = V_104 ;
} else {
return V_107 ;
}
V_57 = F_64 ( & V_81 -> V_82 , V_97 ) ;
if ( V_57 != 0 )
F_65 ( & V_81 -> V_79 , V_83 ) ;
return V_108 ;
}
static int F_66 ( struct V_5 * V_6 , void T_2 * V_42 )
{
struct V_109 V_110 ;
struct V_80 * V_81 ;
struct V_1 * V_17 ;
T_3 V_21 ;
T_3 V_64 ;
T_3 V_99 ;
int V_56 ;
int V_57 ;
int V_111 = 0 ;
if ( F_33 ( & V_110 , V_42 , sizeof( V_110 ) ) )
return - V_49 ;
V_81 = F_42 ( sizeof( * V_81 ) , V_59 ) ;
if ( ! V_81 )
return - V_60 ;
V_81 -> V_6 = V_6 ;
F_43 ( & V_6 -> V_29 ) ;
V_110 . V_61 [ sizeof( V_110 . V_61 ) - 1 ] = '\0' ;
if ( strlen ( V_110 . V_61 ) ) {
V_81 -> V_3 = F_44 ( V_110 . V_61 ,
V_59 ) ;
if ( ! V_81 -> V_3 ) {
V_57 = - V_60 ;
goto V_112;
}
}
V_21 = V_110 . V_113 ;
V_64 = V_110 . V_114 ;
V_99 = V_110 . V_115 ;
if ( V_64 & V_72 ) {
V_57 = - V_16 ;
goto V_116;
}
V_17 = & V_6 -> V_11 [ V_21 ] ;
V_57 = F_45 ( V_17 , V_81 -> V_3 ) ;
if ( V_57 )
goto V_117;
V_81 -> V_17 = V_17 ;
V_81 -> V_99 = V_99 ;
if ( V_64 & V_66 )
F_19 ( V_67 , & V_17 -> V_7 ) ;
if ( V_64 & V_68 )
F_19 ( V_69 , & V_17 -> V_7 ) ;
if ( V_64 & V_70 )
F_19 ( V_71 , & V_17 -> V_7 ) ;
V_57 = F_47 ( V_17 ) ;
if ( V_57 )
goto V_117;
V_81 -> V_95 = F_67 ( V_17 ) ;
if ( V_81 -> V_95 <= 0 ) {
V_57 = - V_118 ;
goto V_117;
}
if ( V_99 & V_105 )
V_111 |= V_119 ;
if ( V_99 & V_106 )
V_111 |= V_120 ;
V_111 |= V_121 ;
V_111 |= V_122 ;
F_68 ( V_81 -> V_82 ) ;
F_69 ( & V_81 -> V_79 ) ;
F_70 ( & V_81 -> V_93 ) ;
V_57 = F_71 ( V_81 -> V_95 ,
NULL ,
F_62 ,
V_111 ,
V_81 -> V_3 ,
V_81 ) ;
if ( V_57 )
goto V_117;
V_56 = F_49 ( L_9 ,
& V_123 ,
V_81 ,
V_76 | V_77 ) ;
if ( V_56 < 0 ) {
V_57 = V_56 ;
goto V_124;
}
V_110 . V_56 = V_56 ;
if ( F_32 ( V_42 , & V_110 , sizeof( V_110 ) ) ) {
V_57 = - V_49 ;
goto V_124;
}
return 0 ;
V_124:
F_59 ( V_81 -> V_95 , V_81 ) ;
V_117:
F_38 ( V_81 -> V_17 ) ;
V_116:
F_39 ( V_81 -> V_3 ) ;
V_112:
F_39 ( V_81 ) ;
F_40 ( & V_6 -> V_29 ) ;
return V_57 ;
}
static long F_72 ( struct V_35 * V_125 , unsigned int V_37 , unsigned long V_38 )
{
struct V_5 * V_6 = V_125 -> V_41 ;
struct V_12 * V_13 = V_6 -> V_13 ;
void T_2 * V_42 = ( void T_2 * ) V_38 ;
if ( ! V_13 )
return - V_118 ;
if ( V_37 == V_126 ) {
struct V_127 V_128 ;
strncpy ( V_128 . V_31 , F_73 ( & V_6 -> V_29 ) ,
sizeof( V_128 . V_31 ) ) ;
V_128 . V_31 [ sizeof( V_128 . V_31 ) - 1 ] = '\0' ;
strncpy ( V_128 . V_3 , V_6 -> V_3 ,
sizeof( V_128 . V_3 ) ) ;
V_128 . V_3 [ sizeof( V_128 . V_3 ) - 1 ] = '\0' ;
V_128 . V_58 = V_6 -> V_10 ;
if ( F_32 ( V_42 , & V_128 , sizeof( V_128 ) ) )
return - V_49 ;
return 0 ;
} else if ( V_37 == V_129 ) {
struct V_130 V_131 ;
struct V_1 * V_17 ;
if ( F_33 ( & V_131 , V_42 , sizeof( V_131 ) ) )
return - V_49 ;
if ( V_131 . V_132 > V_6 -> V_10 )
return - V_16 ;
V_17 = & V_6 -> V_11 [ V_131 . V_132 ] ;
if ( V_17 -> V_31 ) {
strncpy ( V_131 . V_31 , V_17 -> V_31 ,
sizeof( V_131 . V_31 ) ) ;
V_131 . V_31 [ sizeof( V_131 . V_31 ) - 1 ] = '\0' ;
} else {
V_131 . V_31 [ 0 ] = '\0' ;
}
if ( V_17 -> V_3 ) {
strncpy ( V_131 . V_133 , V_17 -> V_3 ,
sizeof( V_131 . V_133 ) ) ;
V_131 . V_133 [ sizeof( V_131 . V_133 ) - 1 ] = '\0' ;
} else {
V_131 . V_133 [ 0 ] = '\0' ;
}
V_131 . V_7 = 0 ;
if ( F_74 ( V_134 , & V_17 -> V_7 ) ||
F_74 ( V_135 , & V_17 -> V_7 ) ||
F_74 ( V_136 , & V_17 -> V_7 ) ||
F_74 ( V_137 , & V_17 -> V_7 ) ||
F_74 ( V_138 , & V_17 -> V_7 ) )
V_131 . V_7 |= V_139 ;
if ( F_74 ( V_24 , & V_17 -> V_7 ) )
V_131 . V_7 |= V_140 ;
if ( F_74 ( V_67 , & V_17 -> V_7 ) )
V_131 . V_7 |= V_141 ;
if ( F_74 ( V_69 , & V_17 -> V_7 ) )
V_131 . V_7 |= V_142 ;
if ( F_74 ( V_71 , & V_17 -> V_7 ) )
V_131 . V_7 |= V_143 ;
if ( F_32 ( V_42 , & V_131 , sizeof( V_131 ) ) )
return - V_49 ;
return 0 ;
} else if ( V_37 == V_144 ) {
return F_41 ( V_6 , V_42 ) ;
} else if ( V_37 == V_145 ) {
return F_66 ( V_6 , V_42 ) ;
}
return - V_16 ;
}
static long F_75 ( struct V_35 * V_125 , unsigned int V_37 ,
unsigned long V_38 )
{
return F_72 ( V_125 , V_37 , ( unsigned long ) F_36 ( V_38 ) ) ;
}
static int F_76 ( struct V_53 * V_53 , struct V_35 * V_125 )
{
struct V_5 * V_6 = F_77 ( V_53 -> V_146 ,
struct V_5 , V_147 ) ;
if ( ! V_6 || ! V_6 -> V_13 )
return - V_118 ;
F_43 ( & V_6 -> V_29 ) ;
V_125 -> V_41 = V_6 ;
return 0 ;
}
static int F_78 ( struct V_53 * V_53 , struct V_35 * V_125 )
{
struct V_5 * V_6 = F_77 ( V_53 -> V_146 ,
struct V_5 , V_147 ) ;
if ( ! V_6 )
return - V_118 ;
F_40 ( & V_6 -> V_29 ) ;
return 0 ;
}
static void F_79 ( struct V_148 * V_29 )
{
struct V_5 * V_6 = F_80 ( V_29 ) ;
F_81 ( & V_6 -> V_28 ) ;
F_82 ( & V_149 , V_6 -> V_102 ) ;
F_39 ( V_6 -> V_3 ) ;
F_39 ( V_6 -> V_11 ) ;
F_39 ( V_6 ) ;
}
static int F_83 ( struct V_5 * V_6 )
{
int V_22 ;
F_84 ( & V_6 -> V_147 , & V_150 ) ;
V_6 -> V_147 . V_151 = V_152 ;
V_6 -> V_147 . V_153 . V_154 = & V_6 -> V_29 . V_153 ;
V_6 -> V_29 . V_155 = F_85 ( F_86 ( V_156 ) , V_6 -> V_102 ) ;
V_22 = F_87 ( & V_6 -> V_147 , V_6 -> V_29 . V_155 , 1 ) ;
if ( V_22 < 0 )
F_88 ( V_6 -> V_13 , L_10 ,
F_86 ( V_156 ) , V_6 -> V_102 ) ;
else
F_89 ( V_6 -> V_13 , L_11 ,
F_86 ( V_156 ) , V_6 -> V_102 ) ;
V_22 = F_90 ( & V_6 -> V_29 ) ;
if ( V_22 )
goto V_157;
V_22 = F_91 ( V_6 ) ;
if ( V_22 )
goto V_158;
V_6 -> V_29 . V_159 = F_79 ;
F_14 ( L_12 ,
V_19 , V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
F_73 ( & V_6 -> V_29 ) , V_6 -> V_13 -> V_3 ? : L_13 ) ;
return 0 ;
V_158:
F_92 ( & V_6 -> V_29 ) ;
V_157:
F_93 ( & V_6 -> V_147 ) ;
return V_22 ;
}
static void F_94 ( void )
{
struct V_5 * V_6 ;
int V_160 ;
F_4 (gdev, &gpio_devices, list) {
V_160 = F_83 ( V_6 ) ;
if ( V_160 )
F_15 ( L_14 ,
F_73 ( & V_6 -> V_29 ) , V_160 ) ;
}
}
int F_95 ( struct V_12 * V_13 , void * V_161 )
{
unsigned long V_7 ;
int V_22 = 0 ;
unsigned V_32 ;
int V_9 = V_13 -> V_9 ;
struct V_5 * V_6 ;
V_6 = F_42 ( sizeof( * V_6 ) , V_59 ) ;
if ( ! V_6 )
return - V_60 ;
V_6 -> V_29 . V_162 = & V_163 ;
V_6 -> V_13 = V_13 ;
V_13 -> V_15 = V_6 ;
if ( V_13 -> V_154 ) {
V_6 -> V_29 . V_154 = V_13 -> V_154 ;
V_6 -> V_29 . V_164 = V_13 -> V_154 -> V_164 ;
}
#ifdef F_96
if ( V_13 -> V_164 )
V_6 -> V_29 . V_164 = V_13 -> V_164 ;
#endif
V_6 -> V_102 = F_97 ( & V_149 , 0 , 0 , V_59 ) ;
if ( V_6 -> V_102 < 0 ) {
V_22 = V_6 -> V_102 ;
goto V_165;
}
F_98 ( & V_6 -> V_29 , L_15 , V_6 -> V_102 ) ;
F_99 ( & V_6 -> V_29 ) ;
F_100 ( & V_6 -> V_29 , V_6 ) ;
if ( V_13 -> V_154 && V_13 -> V_154 -> V_166 )
V_6 -> V_151 = V_13 -> V_154 -> V_166 -> V_151 ;
else if ( V_13 -> V_151 )
V_6 -> V_151 = V_13 -> V_151 ;
else
V_6 -> V_151 = V_152 ;
V_6 -> V_11 = F_101 ( V_13 -> V_10 , sizeof( V_6 -> V_11 [ 0 ] ) , V_59 ) ;
if ( ! V_6 -> V_11 ) {
V_22 = - V_60 ;
goto V_165;
}
if ( V_13 -> V_10 == 0 ) {
F_102 ( V_13 , L_16 ) ;
V_22 = - V_16 ;
goto V_167;
}
if ( V_13 -> V_3 )
V_6 -> V_3 = F_44 ( V_13 -> V_3 , V_59 ) ;
else
V_6 -> V_3 = F_44 ( L_17 , V_59 ) ;
if ( ! V_6 -> V_3 ) {
V_22 = - V_60 ;
goto V_167;
}
V_6 -> V_10 = V_13 -> V_10 ;
V_6 -> V_161 = V_161 ;
F_3 ( & V_8 , V_7 ) ;
if ( V_9 < 0 ) {
V_9 = F_12 ( V_13 -> V_10 ) ;
if ( V_9 < 0 ) {
V_22 = V_9 ;
F_5 ( & V_8 , V_7 ) ;
goto V_168;
}
V_13 -> V_9 = V_9 ;
}
V_6 -> V_9 = V_9 ;
V_22 = F_20 ( V_6 ) ;
if ( V_22 ) {
F_5 ( & V_8 , V_7 ) ;
goto V_168;
}
F_5 ( & V_8 , V_7 ) ;
for ( V_32 = 0 ; V_32 < V_13 -> V_10 ; V_32 ++ ) {
struct V_1 * V_17 = & V_6 -> V_11 [ V_32 ] ;
V_17 -> V_6 = V_6 ;
if ( V_13 -> V_23 ) {
int V_169 = V_13 -> V_23 ( V_13 , V_32 ) ;
if ( ! V_169 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
} else if ( ! V_13 -> V_170 ) {
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
}
#ifdef F_103
F_104 ( & V_6 -> V_171 ) ;
#endif
V_22 = F_28 ( V_13 ) ;
if ( V_22 )
goto V_172;
V_22 = F_105 ( V_13 ) ;
if ( V_22 )
goto V_173;
F_106 ( V_13 ) ;
if ( V_174 ) {
V_22 = F_83 ( V_6 ) ;
if ( V_22 )
goto V_173;
}
return 0 ;
V_173:
F_107 ( V_13 ) ;
F_108 ( V_13 ) ;
F_109 ( V_13 ) ;
V_172:
F_3 ( & V_8 , V_7 ) ;
F_81 ( & V_6 -> V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
V_168:
F_39 ( V_6 -> V_3 ) ;
V_167:
F_39 ( V_6 -> V_11 ) ;
V_165:
F_82 ( & V_149 , V_6 -> V_102 ) ;
F_15 ( L_18 , V_19 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
V_13 -> V_3 ? : L_13 ) ;
F_39 ( V_6 ) ;
return V_22 ;
}
void * F_110 ( struct V_12 * V_13 )
{
return V_13 -> V_15 -> V_161 ;
}
void F_111 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_15 ;
struct V_1 * V_17 ;
unsigned long V_7 ;
unsigned V_32 ;
bool V_175 = false ;
F_112 ( V_6 ) ;
V_6 -> V_13 = NULL ;
F_113 ( V_13 ) ;
F_107 ( V_13 ) ;
F_114 ( V_13 ) ;
F_108 ( V_13 ) ;
F_109 ( V_13 ) ;
V_6 -> V_161 = NULL ;
F_3 ( & V_8 , V_7 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_10 ; V_32 ++ ) {
V_17 = & V_6 -> V_11 [ V_32 ] ;
if ( F_74 ( V_134 , & V_17 -> V_7 ) )
V_175 = true ;
}
F_5 ( & V_8 , V_7 ) ;
if ( V_175 )
F_115 ( & V_6 -> V_29 ,
L_19 ) ;
F_93 ( & V_6 -> V_147 ) ;
F_92 ( & V_6 -> V_29 ) ;
F_40 ( & V_6 -> V_29 ) ;
}
static void F_116 ( struct V_148 * V_29 , void * V_176 )
{
struct V_12 * V_13 = * (struct V_12 * * ) V_176 ;
F_111 ( V_13 ) ;
}
static int F_117 ( struct V_148 * V_29 , void * V_176 , void * V_161 )
{
struct V_12 * * V_177 = V_176 ;
if ( ! V_177 || ! * V_177 ) {
F_118 ( ! V_177 || ! * V_177 ) ;
return 0 ;
}
return * V_177 == V_161 ;
}
int F_119 ( struct V_148 * V_29 , struct V_12 * V_13 ,
void * V_161 )
{
struct V_12 * * V_178 ;
int V_57 ;
V_178 = F_120 ( F_116 , sizeof( * V_178 ) ,
V_59 ) ;
if ( ! V_178 )
return - V_60 ;
V_57 = F_95 ( V_13 , V_161 ) ;
if ( V_57 < 0 ) {
F_121 ( V_178 ) ;
return V_57 ;
}
* V_178 = V_13 ;
F_122 ( V_29 , V_178 ) ;
return 0 ;
}
void F_123 ( struct V_148 * V_29 , struct V_12 * V_13 )
{
int V_57 ;
V_57 = F_124 ( V_29 , F_116 ,
F_117 , V_13 ) ;
if ( ! V_57 )
F_118 ( V_57 ) ;
}
struct V_12 * F_125 ( void * V_161 ,
int (* F_126)( struct V_12 * V_13 ,
void * V_161 ) )
{
struct V_5 * V_6 ;
struct V_12 * V_13 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list)
if ( V_6 -> V_13 && F_126 ( V_6 -> V_13 , V_161 ) )
break;
if ( & V_6 -> V_28 == & V_27 )
V_13 = NULL ;
else
V_13 = V_6 -> V_13 ;
F_5 ( & V_8 , V_7 ) ;
return V_13 ;
}
static int F_127 ( struct V_12 * V_13 , void * V_161 )
{
const char * V_31 = V_161 ;
return ! strcmp ( V_13 -> V_3 , V_31 ) ;
}
static struct V_12 * F_128 ( const char * V_31 )
{
return F_125 ( ( void * ) V_31 , F_127 ) ;
}
void F_129 ( struct V_12 * V_179 ,
struct V_180 * V_181 ,
int V_182 ,
T_8 V_183 )
{
unsigned int V_21 ;
if ( ! V_179 -> V_184 ) {
F_102 ( V_179 , L_20 ,
V_19 ) ;
return;
}
if ( V_183 ) {
if ( V_179 -> V_185 ) {
F_102 ( V_179 ,
L_21
L_22 ) ;
return;
}
F_130 ( V_182 , V_183 ,
V_179 ) ;
V_179 -> V_186 = V_182 ;
}
for ( V_21 = 0 ; V_21 < V_179 -> V_10 ; V_21 ++ )
F_131 ( F_132 ( V_179 -> V_184 , V_21 ) ,
V_182 ) ;
}
static int F_133 ( struct V_187 * V_2 , unsigned int V_95 ,
T_9 V_188 )
{
struct V_12 * V_13 = V_2 -> V_189 ;
F_134 ( V_95 , V_13 ) ;
F_135 ( V_95 , V_13 -> V_190 ) ;
F_136 ( V_95 , V_13 -> V_181 , V_13 -> V_191 ) ;
if ( V_13 -> V_185 && ! V_13 -> V_192 )
F_137 ( V_95 , 1 ) ;
F_138 ( V_95 ) ;
if ( V_13 -> V_193 != V_194 )
F_139 ( V_95 , V_13 -> V_193 ) ;
return 0 ;
}
static void F_140 ( struct V_187 * V_2 , unsigned int V_95 )
{
struct V_12 * V_13 = V_2 -> V_189 ;
if ( V_13 -> V_185 )
F_137 ( V_95 , 0 ) ;
F_136 ( V_95 , NULL , NULL ) ;
F_134 ( V_95 , NULL ) ;
}
static int F_141 ( struct V_195 * V_2 )
{
struct V_12 * V_13 = F_142 ( V_2 ) ;
if ( ! F_143 ( V_13 -> V_15 -> V_151 ) )
return - V_118 ;
if ( F_144 ( V_13 , V_2 -> V_188 ) ) {
F_102 ( V_13 ,
L_23 ,
V_2 -> V_188 ) ;
F_145 ( V_13 -> V_15 -> V_151 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_146 ( struct V_195 * V_2 )
{
struct V_12 * V_13 = F_142 ( V_2 ) ;
F_147 ( V_13 , V_2 -> V_188 ) ;
F_145 ( V_13 -> V_15 -> V_151 ) ;
}
static int F_148 ( struct V_12 * V_13 , unsigned V_21 )
{
return F_132 ( V_13 -> V_184 , V_21 ) ;
}
static void F_113 ( struct V_12 * V_179 )
{
unsigned int V_21 ;
F_149 ( V_179 ) ;
if ( V_179 -> V_186 ) {
F_150 ( V_179 -> V_186 , NULL ) ;
F_151 ( V_179 -> V_186 , NULL ) ;
}
if ( V_179 -> V_184 ) {
for ( V_21 = 0 ; V_21 < V_179 -> V_10 ; V_21 ++ )
F_152 (
F_132 ( V_179 -> V_184 , V_21 ) ) ;
F_153 ( V_179 -> V_184 ) ;
}
if ( V_179 -> V_181 ) {
V_179 -> V_181 -> V_196 = NULL ;
V_179 -> V_181 -> V_197 = NULL ;
V_179 -> V_181 = NULL ;
}
}
int F_154 ( struct V_12 * V_179 ,
struct V_180 * V_181 ,
unsigned int V_198 ,
T_8 V_199 ,
unsigned int type ,
struct V_200 * V_190 )
{
struct V_201 * V_164 ;
unsigned int V_21 ;
unsigned V_202 = 0 ;
if ( ! V_179 || ! V_181 )
return - V_16 ;
if ( ! V_179 -> V_154 ) {
F_15 ( L_24 ) ;
return - V_16 ;
}
V_164 = V_179 -> V_154 -> V_164 ;
#ifdef F_96
if ( V_179 -> V_164 )
V_164 = V_179 -> V_164 ;
#endif
V_179 -> V_181 = V_181 ;
V_179 -> V_191 = V_199 ;
V_179 -> V_193 = type ;
V_179 -> V_203 = F_148 ;
V_179 -> V_190 = V_190 ;
V_179 -> V_184 = F_155 ( V_164 ,
V_179 -> V_10 , V_198 ,
& V_204 , V_179 ) ;
if ( ! V_179 -> V_184 ) {
V_179 -> V_181 = NULL ;
return - V_16 ;
}
if ( ! V_181 -> V_196 &&
! V_181 -> V_197 ) {
V_181 -> V_196 = F_141 ;
V_181 -> V_197 = F_146 ;
}
for ( V_21 = 0 ; V_21 < V_179 -> V_10 ; V_21 ++ ) {
V_202 = F_156 ( V_179 -> V_184 , V_21 ) ;
if ( V_21 == 0 )
V_179 -> V_202 = V_202 ;
}
F_157 ( V_179 ) ;
return 0 ;
}
static void F_113 ( struct V_12 * V_179 ) {}
int F_158 ( struct V_12 * V_13 , unsigned V_21 )
{
return F_159 ( V_13 -> V_15 -> V_9 + V_21 ) ;
}
void F_160 ( struct V_12 * V_13 , unsigned V_21 )
{
F_161 ( V_13 -> V_15 -> V_9 + V_21 ) ;
}
int F_162 ( struct V_12 * V_13 ,
struct V_205 * V_206 ,
unsigned int V_207 , const char * V_208 )
{
struct V_209 * V_210 ;
struct V_5 * V_6 = V_13 -> V_15 ;
int V_57 ;
V_210 = F_42 ( sizeof( * V_210 ) , V_59 ) ;
if ( ! V_210 ) {
F_102 ( V_13 , L_25 ) ;
return - V_60 ;
}
V_210 -> V_211 . V_102 = V_207 ;
V_210 -> V_211 . V_33 = V_13 ;
V_210 -> V_211 . V_31 = V_13 -> V_3 ;
V_210 -> V_211 . V_9 = V_6 -> V_9 + V_207 ;
V_210 -> V_206 = V_206 ;
V_57 = F_163 ( V_206 , V_208 ,
& V_210 -> V_211 . V_212 ,
& V_210 -> V_211 . V_213 ) ;
if ( V_57 < 0 ) {
F_39 ( V_210 ) ;
return V_57 ;
}
F_164 ( V_206 , & V_210 -> V_211 ) ;
F_89 ( V_13 , L_26 ,
V_207 , V_207 + V_210 -> V_211 . V_213 - 1 ,
F_165 ( V_206 ) , V_208 ) ;
F_22 ( & V_210 -> V_214 , & V_6 -> V_171 ) ;
return 0 ;
}
int F_166 ( struct V_12 * V_13 , const char * V_215 ,
unsigned int V_207 , unsigned int V_216 ,
unsigned int V_213 )
{
struct V_209 * V_210 ;
struct V_5 * V_6 = V_13 -> V_15 ;
int V_57 ;
V_210 = F_42 ( sizeof( * V_210 ) , V_59 ) ;
if ( ! V_210 ) {
F_102 ( V_13 , L_25 ) ;
return - V_60 ;
}
V_210 -> V_211 . V_102 = V_207 ;
V_210 -> V_211 . V_33 = V_13 ;
V_210 -> V_211 . V_31 = V_13 -> V_3 ;
V_210 -> V_211 . V_9 = V_6 -> V_9 + V_207 ;
V_210 -> V_211 . V_217 = V_216 ;
V_210 -> V_211 . V_213 = V_213 ;
V_210 -> V_206 = F_167 ( V_215 ,
& V_210 -> V_211 ) ;
if ( F_168 ( V_210 -> V_206 ) ) {
V_57 = F_169 ( V_210 -> V_206 ) ;
F_102 ( V_13 , L_27 ) ;
F_39 ( V_210 ) ;
return V_57 ;
}
F_89 ( V_13 , L_28 ,
V_207 , V_207 + V_213 - 1 ,
V_215 ,
V_216 , V_216 + V_213 - 1 ) ;
F_22 ( & V_210 -> V_214 , & V_6 -> V_171 ) ;
return 0 ;
}
void F_114 ( struct V_12 * V_13 )
{
struct V_209 * V_210 , * V_218 ;
struct V_5 * V_6 = V_13 -> V_15 ;
F_25 (pin_range, tmp, &gdev->pin_ranges, node) {
F_81 ( & V_210 -> V_214 ) ;
F_170 ( V_210 -> V_206 ,
& V_210 -> V_211 ) ;
F_39 ( V_210 ) ;
}
}
static int F_171 ( struct V_1 * V_17 , const char * V_3 )
{
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_22 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
if ( F_172 ( V_134 , & V_17 -> V_7 ) == 0 ) {
F_1 ( V_17 , V_3 ? : L_29 ) ;
V_22 = 0 ;
} else {
V_22 = - V_30 ;
goto V_219;
}
if ( V_13 -> V_220 ) {
F_5 ( & V_8 , V_7 ) ;
V_22 = V_13 -> V_220 ( V_13 , F_17 ( V_17 ) ) ;
F_3 ( & V_8 , V_7 ) ;
if ( V_22 < 0 ) {
F_1 ( V_17 , NULL ) ;
F_18 ( V_134 , & V_17 -> V_7 ) ;
goto V_219;
}
}
if ( V_13 -> V_23 ) {
F_5 ( & V_8 , V_7 ) ;
F_16 ( V_17 ) ;
F_3 ( & V_8 , V_7 ) ;
}
V_219:
F_5 ( & V_8 , V_7 ) ;
return V_22 ;
}
int F_45 ( struct V_1 * V_17 , const char * V_3 )
{
int V_22 = - V_221 ;
struct V_5 * V_6 ;
F_173 ( V_17 ) ;
V_6 = V_17 -> V_6 ;
if ( F_143 ( V_6 -> V_151 ) ) {
V_22 = F_171 ( V_17 , V_3 ) ;
if ( V_22 < 0 )
F_145 ( V_6 -> V_151 ) ;
else
F_43 ( & V_6 -> V_29 ) ;
}
if ( V_22 )
F_174 ( V_17 , L_30 , V_19 , V_22 ) ;
return V_22 ;
}
static bool F_175 ( struct V_1 * V_17 )
{
bool V_57 = false ;
unsigned long V_7 ;
struct V_12 * V_13 ;
F_176 () ;
F_177 ( V_17 ) ;
F_3 ( & V_8 , V_7 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( V_13 && F_74 ( V_134 , & V_17 -> V_7 ) ) {
if ( V_13 -> free ) {
F_5 ( & V_8 , V_7 ) ;
F_178 ( V_13 -> V_185 ) ;
V_13 -> free ( V_13 , F_17 ( V_17 ) ) ;
F_3 ( & V_8 , V_7 ) ;
}
F_1 ( V_17 , NULL ) ;
F_18 ( V_67 , & V_17 -> V_7 ) ;
F_18 ( V_134 , & V_17 -> V_7 ) ;
F_18 ( V_69 , & V_17 -> V_7 ) ;
F_18 ( V_71 , & V_17 -> V_7 ) ;
F_18 ( V_135 , & V_17 -> V_7 ) ;
V_57 = true ;
}
F_5 ( & V_8 , V_7 ) ;
return V_57 ;
}
void F_38 ( struct V_1 * V_17 )
{
if ( V_17 && V_17 -> V_6 && F_175 ( V_17 ) ) {
F_145 ( V_17 -> V_6 -> V_151 ) ;
F_40 ( & V_17 -> V_6 -> V_29 ) ;
} else {
F_118 ( V_222 ) ;
}
}
const char * F_179 ( struct V_12 * V_13 , unsigned V_21 )
{
struct V_1 * V_17 ;
if ( V_21 >= V_13 -> V_10 )
return NULL ;
V_17 = & V_13 -> V_15 -> V_11 [ V_21 ] ;
if ( F_74 ( V_134 , & V_17 -> V_7 ) == 0 )
return NULL ;
return V_17 -> V_3 ;
}
struct V_1 * F_180 ( struct V_12 * V_13 , T_1 V_14 ,
const char * V_3 )
{
struct V_1 * V_17 = F_8 ( V_13 , V_14 ) ;
int V_160 ;
if ( F_168 ( V_17 ) ) {
F_102 ( V_13 , L_31 ) ;
return V_17 ;
}
V_160 = F_171 ( V_17 , V_3 ) ;
if ( V_160 < 0 )
return F_9 ( V_160 ) ;
return V_17 ;
}
void F_181 ( struct V_1 * V_17 )
{
if ( V_17 )
F_175 ( V_17 ) ;
}
int F_47 ( struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_22 = - V_16 ;
F_173 ( V_17 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( ! V_13 -> V_223 || ! V_13 -> V_170 ) {
F_182 ( V_17 ,
L_32 ,
V_19 ) ;
return - V_224 ;
}
V_22 = V_13 -> V_170 ( V_13 , F_17 ( V_17 ) ) ;
if ( V_22 == 0 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
F_183 ( F_10 ( V_17 ) , 1 , V_22 ) ;
return V_22 ;
}
static int F_184 ( struct V_1 * V_17 , int V_225 )
{
struct V_12 * V_33 = V_17 -> V_6 -> V_13 ;
int V_57 ;
if ( F_74 ( V_136 , & V_17 -> V_7 ) ) {
F_185 ( V_17 ,
L_33 ,
V_19 ) ;
return - V_224 ;
}
if ( F_74 ( V_69 , & V_17 -> V_7 ) ) {
if ( V_33 -> V_226 ) {
V_57 = V_33 -> V_226 ( V_33 , F_17 ( V_17 ) ,
V_227 ) ;
if ( ! V_57 )
goto V_228;
}
if ( V_225 )
return F_47 ( V_17 ) ;
}
else if ( F_74 ( V_71 , & V_17 -> V_7 ) ) {
if ( V_33 -> V_226 ) {
V_57 = V_33 -> V_226 ( V_33 , F_17 ( V_17 ) ,
V_229 ) ;
if ( ! V_57 )
goto V_228;
}
if ( ! V_225 )
return F_47 ( V_17 ) ;
} else {
if ( V_33 -> V_226 )
V_33 -> V_226 ( V_33 ,
F_17 ( V_17 ) ,
V_230 ) ;
}
V_228:
if ( ! V_33 -> V_231 || ! V_33 -> V_232 ) {
F_182 ( V_17 ,
L_34 ,
V_19 ) ;
return - V_224 ;
}
V_57 = V_33 -> V_232 ( V_33 , F_17 ( V_17 ) , V_225 ) ;
if ( ! V_57 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
F_186 ( F_10 ( V_17 ) , 0 , V_225 ) ;
F_183 ( F_10 ( V_17 ) , 0 , V_57 ) ;
return V_57 ;
}
int F_187 ( struct V_1 * V_17 , int V_225 )
{
F_173 ( V_17 ) ;
return F_184 ( V_17 , V_225 ) ;
}
int F_46 ( struct V_1 * V_17 , int V_225 )
{
F_173 ( V_17 ) ;
if ( F_74 ( V_67 , & V_17 -> V_7 ) )
V_225 = ! V_225 ;
return F_184 ( V_17 , V_225 ) ;
}
int F_188 ( struct V_1 * V_17 , unsigned V_233 )
{
struct V_12 * V_13 ;
F_173 ( V_17 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( ! V_13 -> V_231 || ! V_13 -> V_234 ) {
F_174 ( V_17 ,
L_35 ,
V_19 ) ;
return - V_235 ;
}
return V_13 -> V_234 ( V_13 , F_17 ( V_17 ) , V_233 ) ;
}
int F_189 ( const struct V_1 * V_17 )
{
F_173 ( V_17 ) ;
return F_74 ( V_67 , & V_17 -> V_7 ) ;
}
static int F_190 ( const struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_21 ;
int V_225 ;
V_13 = V_17 -> V_6 -> V_13 ;
V_21 = F_17 ( V_17 ) ;
V_225 = V_13 -> V_223 ? V_13 -> V_223 ( V_13 , V_21 ) : - V_224 ;
V_225 = V_225 < 0 ? V_225 : ! ! V_225 ;
F_186 ( F_10 ( V_17 ) , 1 , V_225 ) ;
return V_225 ;
}
int F_191 ( const struct V_1 * V_17 )
{
F_173 ( V_17 ) ;
F_118 ( V_17 -> V_6 -> V_13 -> V_185 ) ;
return F_190 ( V_17 ) ;
}
int F_192 ( const struct V_1 * V_17 )
{
int V_225 ;
F_173 ( V_17 ) ;
F_118 ( V_17 -> V_6 -> V_13 -> V_185 ) ;
V_225 = F_190 ( V_17 ) ;
if ( V_225 < 0 )
return V_225 ;
if ( F_74 ( V_67 , & V_17 -> V_7 ) )
V_225 = ! V_225 ;
return V_225 ;
}
static void F_193 ( struct V_1 * V_17 , bool V_225 )
{
int V_160 = 0 ;
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_21 = F_17 ( V_17 ) ;
if ( V_225 ) {
V_160 = V_13 -> V_170 ( V_13 , V_21 ) ;
if ( ! V_160 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
} else {
V_160 = V_13 -> V_232 ( V_13 , V_21 , 0 ) ;
if ( ! V_160 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
F_183 ( F_10 ( V_17 ) , V_225 , V_160 ) ;
if ( V_160 < 0 )
F_185 ( V_17 ,
L_36 ,
V_19 , V_160 ) ;
}
static void F_194 ( struct V_1 * V_17 , bool V_225 )
{
int V_160 = 0 ;
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_21 = F_17 ( V_17 ) ;
if ( V_225 ) {
V_160 = V_13 -> V_232 ( V_13 , V_21 , 1 ) ;
if ( ! V_160 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
} else {
V_160 = V_13 -> V_170 ( V_13 , V_21 ) ;
if ( ! V_160 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
}
F_183 ( F_10 ( V_17 ) , ! V_225 , V_160 ) ;
if ( V_160 < 0 )
F_185 ( V_17 ,
L_37 ,
V_19 , V_160 ) ;
}
static void F_195 ( struct V_1 * V_17 , bool V_225 )
{
struct V_12 * V_13 ;
V_13 = V_17 -> V_6 -> V_13 ;
F_186 ( F_10 ( V_17 ) , 0 , V_225 ) ;
if ( F_74 ( V_69 , & V_17 -> V_7 ) )
F_193 ( V_17 , V_225 ) ;
else if ( F_74 ( V_71 , & V_17 -> V_7 ) )
F_194 ( V_17 , V_225 ) ;
else
V_13 -> V_231 ( V_13 , F_17 ( V_17 ) , V_225 ) ;
}
static void F_196 ( struct V_12 * V_13 ,
unsigned long * V_236 , unsigned long * V_237 )
{
if ( V_13 -> V_238 ) {
V_13 -> V_238 ( V_13 , V_236 , V_237 ) ;
} else {
int V_32 ;
for ( V_32 = 0 ; V_32 < V_13 -> V_10 ; V_32 ++ ) {
if ( V_236 [ F_197 ( V_32 ) ] == 0 ) {
V_32 = ( F_197 ( V_32 ) + 1 ) * V_239 - 1 ;
continue;
}
if ( F_198 ( V_32 , V_236 ) )
V_13 -> V_231 ( V_13 , V_32 , F_74 ( V_32 , V_237 ) ) ;
}
}
}
void F_34 ( bool V_240 , bool V_185 ,
unsigned int V_241 ,
struct V_1 * * V_242 ,
int * V_243 )
{
int V_32 = 0 ;
while ( V_32 < V_241 ) {
struct V_12 * V_13 = V_242 [ V_32 ] -> V_6 -> V_13 ;
unsigned long V_236 [ F_199 ( V_13 -> V_10 ) ] ;
unsigned long V_237 [ F_199 ( V_13 -> V_10 ) ] ;
int V_86 = 0 ;
if ( ! V_185 )
F_118 ( V_13 -> V_185 ) ;
memset ( V_236 , 0 , sizeof( V_236 ) ) ;
do {
struct V_1 * V_17 = V_242 [ V_32 ] ;
int V_244 = F_17 ( V_17 ) ;
int V_225 = V_243 [ V_32 ] ;
if ( ! V_240 && F_74 ( V_67 , & V_17 -> V_7 ) )
V_225 = ! V_225 ;
F_186 ( F_10 ( V_17 ) , 0 , V_225 ) ;
if ( F_74 ( V_69 , & V_17 -> V_7 ) ) {
F_193 ( V_17 , V_225 ) ;
} else if ( F_74 ( V_71 , & V_17 -> V_7 ) ) {
F_194 ( V_17 , V_225 ) ;
} else {
F_200 ( V_244 , V_236 ) ;
if ( V_225 )
F_200 ( V_244 , V_237 ) ;
else
F_201 ( V_244 , V_237 ) ;
V_86 ++ ;
}
V_32 ++ ;
} while ( ( V_32 < V_241 ) &&
( V_242 [ V_32 ] -> V_6 -> V_13 == V_13 ) );
if ( V_86 != 0 )
F_196 ( V_13 , V_236 , V_237 ) ;
}
}
void F_202 ( struct V_1 * V_17 , int V_225 )
{
F_203 ( V_17 ) ;
F_118 ( V_17 -> V_6 -> V_13 -> V_185 ) ;
F_195 ( V_17 , V_225 ) ;
}
void F_204 ( struct V_1 * V_17 , int V_225 )
{
F_203 ( V_17 ) ;
F_118 ( V_17 -> V_6 -> V_13 -> V_185 ) ;
if ( F_74 ( V_67 , & V_17 -> V_7 ) )
V_225 = ! V_225 ;
F_195 ( V_17 , V_225 ) ;
}
void F_205 ( unsigned int V_241 ,
struct V_1 * * V_242 , int * V_243 )
{
if ( ! V_242 )
return;
F_34 ( true , false , V_241 , V_242 ,
V_243 ) ;
}
void F_206 ( unsigned int V_241 ,
struct V_1 * * V_242 , int * V_243 )
{
if ( ! V_242 )
return;
F_34 ( false , false , V_241 , V_242 ,
V_243 ) ;
}
int F_207 ( const struct V_1 * V_17 )
{
F_173 ( V_17 ) ;
return V_17 -> V_6 -> V_13 -> V_185 ;
}
int F_67 ( const struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_21 ;
if ( ! V_17 || F_168 ( V_17 ) || ! V_17 -> V_6 || ! V_17 -> V_6 -> V_13 )
return - V_16 ;
V_13 = V_17 -> V_6 -> V_13 ;
V_21 = F_17 ( V_17 ) ;
if ( V_13 -> V_203 ) {
int V_245 = V_13 -> V_203 ( V_13 , V_21 ) ;
if ( ! V_245 )
return - V_246 ;
return V_245 ;
}
return - V_246 ;
}
int F_144 ( struct V_12 * V_13 , unsigned int V_21 )
{
struct V_1 * V_17 ;
V_17 = F_8 ( V_13 , V_21 ) ;
if ( F_168 ( V_17 ) )
return F_169 ( V_17 ) ;
if ( V_13 -> V_23 ) {
int V_169 = V_13 -> V_23 ( V_13 , V_21 ) ;
if ( V_169 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
else
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
if ( F_74 ( V_24 , & V_17 -> V_7 ) ) {
F_102 ( V_13 ,
L_38 ,
V_19 ) ;
return - V_224 ;
}
F_19 ( V_136 , & V_17 -> V_7 ) ;
return 0 ;
}
void F_147 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return;
F_18 ( V_136 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
bool F_208 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_74 ( V_136 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
bool F_209 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_74 ( V_69 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
bool F_210 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_74 ( V_71 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
int F_211 ( const struct V_1 * V_17 )
{
F_178 ( V_222 ) ;
F_173 ( V_17 ) ;
return F_190 ( V_17 ) ;
}
int F_31 ( const struct V_1 * V_17 )
{
int V_225 ;
F_178 ( V_222 ) ;
F_173 ( V_17 ) ;
V_225 = F_190 ( V_17 ) ;
if ( V_225 < 0 )
return V_225 ;
if ( F_74 ( V_67 , & V_17 -> V_7 ) )
V_225 = ! V_225 ;
return V_225 ;
}
void F_212 ( struct V_1 * V_17 , int V_225 )
{
F_178 ( V_222 ) ;
F_203 ( V_17 ) ;
F_195 ( V_17 , V_225 ) ;
}
void F_213 ( struct V_1 * V_17 , int V_225 )
{
F_178 ( V_222 ) ;
F_203 ( V_17 ) ;
if ( F_74 ( V_67 , & V_17 -> V_7 ) )
V_225 = ! V_225 ;
F_195 ( V_17 , V_225 ) ;
}
void F_214 ( unsigned int V_241 ,
struct V_1 * * V_242 ,
int * V_243 )
{
F_178 ( V_222 ) ;
if ( ! V_242 )
return;
F_34 ( true , true , V_241 , V_242 ,
V_243 ) ;
}
void F_215 ( unsigned int V_241 ,
struct V_1 * * V_242 ,
int * V_243 )
{
F_178 ( V_222 ) ;
if ( ! V_242 )
return;
F_34 ( false , true , V_241 , V_242 ,
V_243 ) ;
}
void F_216 ( struct V_247 * V_248 )
{
F_217 ( & V_249 ) ;
F_22 ( & V_248 -> V_28 , & V_250 ) ;
F_57 ( & V_249 ) ;
}
void F_218 ( struct V_247 * V_248 )
{
F_217 ( & V_249 ) ;
F_81 ( & V_248 -> V_28 ) ;
F_57 ( & V_249 ) ;
}
static struct V_1 * F_219 ( struct V_148 * V_29 , const char * V_251 ,
unsigned int V_252 ,
enum V_253 * V_7 )
{
char V_254 [ 32 ] ;
enum V_255 V_256 ;
struct V_1 * V_17 ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_220 ( V_257 ) ; V_32 ++ ) {
if ( V_251 )
snprintf ( V_254 , sizeof( V_254 ) , L_39 , V_251 ,
V_257 [ V_32 ] ) ;
else
snprintf ( V_254 , sizeof( V_254 ) , L_40 ,
V_257 [ V_32 ] ) ;
V_17 = F_221 ( V_29 -> V_164 , V_254 , V_252 ,
& V_256 ) ;
if ( ! F_168 ( V_17 ) || ( F_169 ( V_17 ) != - V_258 ) )
break;
}
if ( F_168 ( V_17 ) )
return V_17 ;
if ( V_256 & V_259 )
* V_7 |= V_260 ;
if ( V_256 & V_261 ) {
if ( V_256 & V_259 )
* V_7 |= V_262 ;
else
* V_7 |= V_263 ;
}
return V_17 ;
}
static struct V_1 * F_222 ( struct V_148 * V_29 ,
const char * V_251 ,
unsigned int V_252 ,
enum V_264 V_7 ,
enum V_253 * V_265 )
{
struct V_266 * V_267 = F_223 ( V_29 ) ;
struct V_268 V_269 ;
struct V_1 * V_17 ;
char V_270 [ 32 ] ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_220 ( V_257 ) ; V_32 ++ ) {
if ( V_251 && strcmp ( V_251 , L_41 ) ) {
snprintf ( V_270 , sizeof( V_270 ) , L_39 ,
V_251 , V_257 [ V_32 ] ) ;
} else {
snprintf ( V_270 , sizeof( V_270 ) , L_40 ,
V_257 [ V_32 ] ) ;
}
V_17 = F_224 ( V_267 , V_270 , V_252 , & V_269 ) ;
if ( ! F_168 ( V_17 ) || ( F_169 ( V_17 ) == - V_221 ) )
break;
}
if ( F_168 ( V_17 ) ) {
if ( ! F_225 ( V_267 , V_251 ) )
return F_9 ( - V_258 ) ;
V_17 = F_224 ( V_267 , NULL , V_252 , & V_269 ) ;
if ( F_168 ( V_17 ) )
return V_17 ;
if ( ( V_7 == V_271 || V_7 == V_272 ) &&
V_269 . V_273 ) {
F_48 ( V_29 , L_42 ) ;
return F_9 ( - V_258 ) ;
}
}
if ( V_269 . V_274 == V_260 )
* V_265 |= V_260 ;
return V_17 ;
}
static struct V_247 * F_226 ( struct V_148 * V_29 )
{
const char * V_275 = V_29 ? F_73 ( V_29 ) : NULL ;
struct V_247 * V_248 ;
F_217 ( & V_249 ) ;
F_4 (table, &gpio_lookup_list, list) {
if ( V_248 -> V_275 && V_275 ) {
if ( ! strcmp ( V_248 -> V_275 , V_275 ) )
goto V_276;
} else {
if ( V_275 == V_248 -> V_275 )
goto V_276;
}
}
V_248 = NULL ;
V_276:
F_57 ( & V_249 ) ;
return V_248 ;
}
static struct V_1 * F_227 ( struct V_148 * V_29 , const char * V_251 ,
unsigned int V_252 ,
enum V_253 * V_7 )
{
struct V_1 * V_17 = F_9 ( - V_258 ) ;
struct V_247 * V_248 ;
struct V_277 * V_96 ;
V_248 = F_226 ( V_29 ) ;
if ( ! V_248 )
return V_17 ;
for ( V_96 = & V_248 -> V_248 [ 0 ] ; V_96 -> V_278 ; V_96 ++ ) {
struct V_12 * V_13 ;
if ( V_96 -> V_252 != V_252 )
continue;
if ( V_96 -> V_251 && ( ! V_251 || strcmp ( V_96 -> V_251 , V_251 ) ) )
continue;
V_13 = F_128 ( V_96 -> V_278 ) ;
if ( ! V_13 ) {
F_26 ( V_29 , L_43 ,
V_96 -> V_278 ) ;
return F_9 ( - V_118 ) ;
}
if ( V_13 -> V_10 <= V_96 -> V_279 ) {
F_26 ( V_29 ,
L_44 ,
V_252 , V_13 -> V_10 , V_13 -> V_3 ) ;
return F_9 ( - V_16 ) ;
}
V_17 = F_8 ( V_13 , V_96 -> V_279 ) ;
* V_7 = V_96 -> V_7 ;
return V_17 ;
}
return V_17 ;
}
static int F_228 ( struct V_148 * V_29 , const char * V_251 )
{
int V_57 ;
char V_270 [ 32 ] ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_220 ( V_257 ) ; V_32 ++ ) {
if ( V_251 )
snprintf ( V_270 , sizeof( V_270 ) , L_39 ,
V_251 , V_257 [ V_32 ] ) ;
else
snprintf ( V_270 , sizeof( V_270 ) , L_40 ,
V_257 [ V_32 ] ) ;
V_57 = F_229 ( V_29 -> V_164 , V_270 ) ;
if ( V_57 >= 0 )
break;
}
return V_57 ;
}
static int F_230 ( struct V_148 * V_29 , const char * V_251 )
{
struct V_247 * V_248 ;
struct V_277 * V_96 ;
unsigned int V_86 = 0 ;
V_248 = F_226 ( V_29 ) ;
if ( ! V_248 )
return - V_258 ;
for ( V_96 = & V_248 -> V_248 [ 0 ] ; V_96 -> V_278 ; V_96 ++ ) {
if ( ( V_251 && V_96 -> V_251 && ! strcmp ( V_251 , V_96 -> V_251 ) ) ||
( ! V_251 && ! V_96 -> V_251 ) )
V_86 ++ ;
}
if ( ! V_86 )
return - V_258 ;
return V_86 ;
}
int F_231 ( struct V_148 * V_29 , const char * V_251 )
{
int V_86 = - V_258 ;
if ( F_232 ( V_280 ) && V_29 && V_29 -> V_164 )
V_86 = F_228 ( V_29 , V_251 ) ;
else if ( F_232 ( V_281 ) && V_29 && F_233 ( V_29 ) )
V_86 = F_234 ( V_29 , V_251 ) ;
if ( V_86 < 0 )
V_86 = F_230 ( V_29 , V_251 ) ;
return V_86 ;
}
struct V_1 * T_10 F_235 ( struct V_148 * V_29 , const char * V_251 ,
enum V_264 V_7 )
{
return F_236 ( V_29 , V_251 , 0 , V_7 ) ;
}
struct V_1 * T_10 F_237 ( struct V_148 * V_29 ,
const char * V_251 ,
enum V_264 V_7 )
{
return F_238 ( V_29 , V_251 , 0 , V_7 ) ;
}
static int F_239 ( struct V_1 * V_17 , const char * V_251 ,
unsigned long V_64 , enum V_264 V_282 )
{
int V_22 ;
if ( V_64 & V_260 )
F_19 ( V_67 , & V_17 -> V_7 ) ;
if ( V_64 & V_262 )
F_19 ( V_69 , & V_17 -> V_7 ) ;
if ( V_64 & V_263 )
F_19 ( V_71 , & V_17 -> V_7 ) ;
if ( ! ( V_282 & V_283 ) ) {
F_14 ( L_45 , V_251 ) ;
return 0 ;
}
if ( V_282 & V_284 )
V_22 = F_46 ( V_17 ,
V_282 & V_285 ) ;
else
V_22 = F_47 ( V_17 ) ;
return V_22 ;
}
struct V_1 * T_10 F_236 ( struct V_148 * V_29 ,
const char * V_251 ,
unsigned int V_252 ,
enum V_264 V_7 )
{
struct V_1 * V_17 = NULL ;
int V_22 ;
enum V_253 V_265 = 0 ;
F_48 ( V_29 , L_46 , V_251 ) ;
if ( V_29 ) {
if ( F_232 ( V_280 ) && V_29 -> V_164 ) {
F_48 ( V_29 , L_47 ) ;
V_17 = F_219 ( V_29 , V_251 , V_252 , & V_265 ) ;
} else if ( F_223 ( V_29 ) ) {
F_48 ( V_29 , L_48 ) ;
V_17 = F_222 ( V_29 , V_251 , V_252 , V_7 , & V_265 ) ;
}
}
if ( ! V_17 || V_17 == F_9 ( - V_258 ) ) {
F_48 ( V_29 , L_49 ) ;
V_17 = F_227 ( V_29 , V_251 , V_252 , & V_265 ) ;
}
if ( F_168 ( V_17 ) ) {
F_48 ( V_29 , L_50 , V_251 ) ;
return V_17 ;
}
V_22 = F_45 ( V_17 , V_251 ) ;
if ( V_22 < 0 )
return F_9 ( V_22 ) ;
V_22 = F_239 ( V_17 , V_251 , V_265 , V_7 ) ;
if ( V_22 < 0 ) {
F_48 ( V_29 , L_51 , V_251 ) ;
F_240 ( V_17 ) ;
return F_9 ( V_22 ) ;
}
return V_17 ;
}
struct V_1 * F_241 ( struct V_286 * V_287 ,
const char * V_270 )
{
struct V_1 * V_17 = F_9 ( - V_118 ) ;
bool V_288 = false ;
bool V_289 = false ;
int V_57 ;
if ( ! V_287 )
return F_9 ( - V_16 ) ;
if ( F_242 ( V_287 ) ) {
enum V_255 V_7 ;
V_17 = F_221 ( F_243 ( V_287 ) , V_270 , 0 ,
& V_7 ) ;
if ( ! F_168 ( V_17 ) ) {
V_288 = V_7 & V_259 ;
V_289 = V_7 & V_261 ;
}
} else if ( F_244 ( V_287 ) ) {
struct V_268 V_269 ;
V_17 = F_245 ( V_287 , V_270 , 0 , & V_269 ) ;
if ( ! F_168 ( V_17 ) )
V_288 = V_269 . V_274 == V_260 ;
}
if ( F_168 ( V_17 ) )
return V_17 ;
V_57 = F_45 ( V_17 , NULL ) ;
if ( V_57 )
return F_9 ( V_57 ) ;
if ( V_288 )
F_19 ( V_67 , & V_17 -> V_7 ) ;
if ( V_289 ) {
if ( V_288 )
F_19 ( V_69 , & V_17 -> V_7 ) ;
else
F_19 ( V_71 , & V_17 -> V_7 ) ;
}
return V_17 ;
}
struct V_1 * T_10 F_238 ( struct V_148 * V_29 ,
const char * V_251 ,
unsigned int V_290 ,
enum V_264 V_7 )
{
struct V_1 * V_17 ;
V_17 = F_236 ( V_29 , V_251 , V_290 , V_7 ) ;
if ( F_168 ( V_17 ) ) {
if ( F_169 ( V_17 ) == - V_258 )
return NULL ;
}
return V_17 ;
}
int F_246 ( struct V_1 * V_17 , const char * V_31 ,
unsigned long V_64 , enum V_264 V_282 )
{
struct V_12 * V_13 ;
struct V_1 * V_291 ;
int V_14 ;
int V_22 ;
V_13 = F_11 ( V_17 ) ;
V_14 = F_17 ( V_17 ) ;
V_291 = F_180 ( V_13 , V_14 , V_31 ) ;
if ( F_168 ( V_291 ) ) {
V_22 = F_169 ( V_291 ) ;
F_15 ( L_52 ,
V_31 , V_13 -> V_3 , V_14 , V_22 ) ;
return V_22 ;
}
V_22 = F_239 ( V_17 , V_31 , V_64 , V_282 ) ;
if ( V_22 < 0 ) {
F_15 ( L_53 ,
V_31 , V_13 -> V_3 , V_14 , V_22 ) ;
F_181 ( V_17 ) ;
return V_22 ;
}
F_19 ( V_135 , & V_17 -> V_7 ) ;
F_247 ( L_54 ,
F_10 ( V_17 ) , V_31 ,
( V_282 & V_284 ) ? L_55 : L_56 ,
( V_282 & V_284 ) ?
( V_282 & V_285 ) ? L_57 : L_58 : L_59 ) ;
return 0 ;
}
static void F_108 ( struct V_12 * V_13 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_13 -> V_10 ; V_102 ++ ) {
if ( F_74 ( V_135 , & V_13 -> V_15 -> V_11 [ V_102 ] . V_7 ) )
F_181 ( & V_13 -> V_15 -> V_11 [ V_102 ] ) ;
}
}
struct V_292 * T_10 F_248 ( struct V_148 * V_29 ,
const char * V_251 ,
enum V_264 V_7 )
{
struct V_1 * V_17 ;
struct V_292 * V_11 ;
int V_86 ;
V_86 = F_231 ( V_29 , V_251 ) ;
if ( V_86 < 0 )
return F_9 ( V_86 ) ;
V_11 = F_42 ( sizeof( * V_11 ) + sizeof( V_11 -> V_17 [ 0 ] ) * V_86 ,
V_59 ) ;
if ( ! V_11 )
return F_9 ( - V_60 ) ;
for ( V_11 -> V_293 = 0 ; V_11 -> V_293 < V_86 ; ) {
V_17 = F_236 ( V_29 , V_251 , V_11 -> V_293 , V_7 ) ;
if ( F_168 ( V_17 ) ) {
F_249 ( V_11 ) ;
return F_250 ( V_17 ) ;
}
V_11 -> V_17 [ V_11 -> V_293 ] = V_17 ;
V_11 -> V_293 ++ ;
}
return V_11 ;
}
struct V_292 * T_10 F_251 ( struct V_148 * V_29 ,
const char * V_251 ,
enum V_264 V_7 )
{
struct V_292 * V_11 ;
V_11 = F_248 ( V_29 , V_251 , V_7 ) ;
if ( F_168 ( V_11 ) && ( F_169 ( V_11 ) == - V_258 ) )
return NULL ;
return V_11 ;
}
void F_240 ( struct V_1 * V_17 )
{
F_38 ( V_17 ) ;
}
void F_249 ( struct V_292 * V_11 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_11 -> V_293 ; V_32 ++ )
F_240 ( V_11 -> V_17 [ V_32 ] ) ;
F_39 ( V_11 ) ;
}
static int T_11 F_252 ( void )
{
int V_57 ;
V_57 = F_253 ( & V_163 ) ;
if ( V_57 < 0 ) {
F_15 ( L_60 ) ;
return V_57 ;
}
V_57 = F_254 ( & V_156 , 0 , V_294 , L_61 ) ;
if ( V_57 < 0 ) {
F_15 ( L_62 ) ;
F_255 ( & V_163 ) ;
} else {
V_174 = true ;
F_94 () ;
}
return V_57 ;
}
static void F_256 ( struct V_295 * V_296 , struct V_5 * V_6 )
{
unsigned V_32 ;
struct V_12 * V_13 = V_6 -> V_13 ;
unsigned V_4 = V_6 -> V_9 ;
struct V_1 * V_297 = & V_6 -> V_11 [ 0 ] ;
int V_298 ;
int V_299 ;
for ( V_32 = 0 ; V_32 < V_6 -> V_10 ; V_32 ++ , V_4 ++ , V_297 ++ ) {
if ( ! F_74 ( V_134 , & V_297 -> V_7 ) ) {
if ( V_297 -> V_31 ) {
F_257 ( V_296 , L_63 ,
V_4 , V_297 -> V_31 ) ;
}
continue;
}
F_16 ( V_297 ) ;
V_298 = F_74 ( V_24 , & V_297 -> V_7 ) ;
V_299 = F_74 ( V_136 , & V_297 -> V_7 ) ;
F_257 ( V_296 , L_64 ,
V_4 , V_297 -> V_31 ? V_297 -> V_31 : L_59 , V_297 -> V_3 ,
V_298 ? L_65 : L_66 ,
V_13 -> V_223
? ( V_13 -> V_223 ( V_13 , V_32 ) ? L_67 : L_68 )
: L_69 ,
V_299 ? L_70 : L_71 ) ;
F_257 ( V_296 , L_72 ) ;
}
}
static void * F_258 ( struct V_295 * V_296 , T_6 * V_300 )
{
unsigned long V_7 ;
struct V_5 * V_6 = NULL ;
T_6 V_290 = * V_300 ;
V_296 -> V_301 = L_59 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list)
if ( V_290 -- == 0 ) {
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static void * F_259 ( struct V_295 * V_296 , void * V_302 , T_6 * V_300 )
{
unsigned long V_7 ;
struct V_5 * V_6 = V_302 ;
void * V_57 = NULL ;
F_3 ( & V_8 , V_7 ) ;
if ( F_260 ( & V_6 -> V_28 , & V_27 ) )
V_57 = NULL ;
else
V_57 = F_23 ( V_6 -> V_28 . V_26 , struct V_5 , V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
V_296 -> V_301 = L_72 ;
++ * V_300 ;
return V_57 ;
}
static void F_261 ( struct V_295 * V_296 , void * V_302 )
{
}
static int F_262 ( struct V_295 * V_296 , void * V_302 )
{
struct V_5 * V_6 = V_302 ;
struct V_12 * V_13 = V_6 -> V_13 ;
struct V_148 * V_154 ;
if ( ! V_13 ) {
F_257 ( V_296 , L_73 , ( char * ) V_296 -> V_301 ,
F_73 ( & V_6 -> V_29 ) ) ;
return 0 ;
}
F_257 ( V_296 , L_74 , ( char * ) V_296 -> V_301 ,
F_73 ( & V_6 -> V_29 ) ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ) ;
V_154 = V_13 -> V_154 ;
if ( V_154 )
F_257 ( V_296 , L_75 ,
V_154 -> V_162 ? V_154 -> V_162 -> V_31 : L_76 ,
F_73 ( V_154 ) ) ;
if ( V_13 -> V_3 )
F_257 ( V_296 , L_77 , V_13 -> V_3 ) ;
if ( V_13 -> V_185 )
F_257 ( V_296 , L_78 ) ;
F_257 ( V_296 , L_79 ) ;
if ( V_13 -> V_303 )
V_13 -> V_303 ( V_296 , V_13 ) ;
else
F_256 ( V_296 , V_6 ) ;
return 0 ;
}
static int F_263 ( struct V_53 * V_53 , struct V_35 * V_35 )
{
return F_264 ( V_35 , & V_304 ) ;
}
static int T_11 F_265 ( void )
{
( void ) F_266 ( L_80 , V_305 | V_306 ,
NULL , NULL , & V_307 ) ;
return 0 ;
}
