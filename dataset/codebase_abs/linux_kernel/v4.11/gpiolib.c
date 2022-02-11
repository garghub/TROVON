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
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
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
struct V_35 * V_35 ;
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
if ( V_21 >= V_6 -> V_10 ) {
V_57 = - V_16 ;
goto V_65;
}
if ( V_64 & ~ V_66 ) {
V_57 = - V_16 ;
goto V_65;
}
V_17 = & V_6 -> V_11 [ V_21 ] ;
V_57 = F_45 ( V_17 , V_40 -> V_3 ) ;
if ( V_57 )
goto V_65;
V_40 -> V_11 [ V_32 ] = V_17 ;
if ( V_64 & V_67 )
F_19 ( V_68 , & V_17 -> V_7 ) ;
if ( V_64 & V_69 )
F_19 ( V_70 , & V_17 -> V_7 ) ;
if ( V_64 & V_71 )
F_19 ( V_72 , & V_17 -> V_7 ) ;
if ( V_64 & V_73 ) {
int V_46 = ! ! V_55 . V_74 [ V_32 ] ;
V_57 = F_46 ( V_17 , V_46 ) ;
if ( V_57 )
goto V_65;
} else if ( V_64 & V_75 ) {
V_57 = F_47 ( V_17 ) ;
if ( V_57 )
goto V_65;
}
F_48 ( & V_6 -> V_29 , L_6 ,
V_21 ) ;
}
V_32 -- ;
V_40 -> V_47 = V_55 . V_58 ;
V_56 = F_49 ( V_76 | V_77 ) ;
if ( V_56 < 0 ) {
V_57 = V_56 ;
goto V_65;
}
V_35 = F_50 ( L_7 ,
& V_78 ,
V_40 ,
V_76 | V_77 ) ;
if ( F_51 ( V_35 ) ) {
V_57 = F_52 ( V_35 ) ;
goto V_79;
}
V_55 . V_56 = V_56 ;
if ( F_32 ( V_42 , & V_55 , sizeof( V_55 ) ) ) {
F_53 ( V_35 ) ;
F_54 ( V_56 ) ;
return - V_49 ;
}
F_55 ( V_56 , V_35 ) ;
F_48 ( & V_6 -> V_29 , L_8 ,
V_40 -> V_47 ) ;
return 0 ;
V_79:
F_54 ( V_56 ) ;
V_65:
for (; V_32 >= 0 ; V_32 -- )
F_38 ( V_40 -> V_11 [ V_32 ] ) ;
F_39 ( V_40 -> V_3 ) ;
V_62:
F_39 ( V_40 ) ;
F_40 ( & V_6 -> V_29 ) ;
return V_57 ;
}
static unsigned int F_56 ( struct V_35 * V_36 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 = V_36 -> V_41 ;
unsigned int V_84 = 0 ;
F_57 ( V_36 , & V_83 -> V_81 , V_81 ) ;
if ( ! F_58 ( & V_83 -> V_84 ) )
V_84 = V_85 | V_86 ;
return V_84 ;
}
static T_4 F_59 ( struct V_35 * V_36 ,
char T_2 * V_87 ,
T_5 V_88 ,
T_6 * V_89 )
{
struct V_82 * V_83 = V_36 -> V_41 ;
unsigned int V_90 ;
int V_57 ;
if ( V_88 < sizeof( struct V_91 ) )
return - V_16 ;
do {
if ( F_58 ( & V_83 -> V_84 ) ) {
if ( V_36 -> V_92 & V_93 )
return - V_94 ;
V_57 = F_60 ( V_83 -> V_81 ,
! F_58 ( & V_83 -> V_84 ) ) ;
if ( V_57 )
return V_57 ;
}
if ( F_61 ( & V_83 -> V_95 ) )
return - V_96 ;
V_57 = F_62 ( & V_83 -> V_84 , V_87 , V_88 , & V_90 ) ;
F_63 ( & V_83 -> V_95 ) ;
if ( V_57 )
return V_57 ;
if ( V_90 == 0 && ( V_36 -> V_92 & V_93 ) )
return - V_94 ;
} while ( V_90 == 0 );
return V_90 ;
}
static int F_64 ( struct V_53 * V_53 , struct V_35 * V_36 )
{
struct V_82 * V_83 = V_36 -> V_41 ;
struct V_5 * V_6 = V_83 -> V_6 ;
F_65 ( V_83 -> V_97 , V_83 ) ;
F_38 ( V_83 -> V_17 ) ;
F_39 ( V_83 -> V_3 ) ;
F_39 ( V_83 ) ;
F_40 ( & V_6 -> V_29 ) ;
return 0 ;
}
static long F_66 ( struct V_35 * V_36 , unsigned int V_37 ,
unsigned long V_38 )
{
struct V_82 * V_83 = V_36 -> V_41 ;
void T_2 * V_42 = ( void T_2 * ) V_38 ;
struct V_43 V_44 ;
if ( V_37 == V_45 ) {
int V_46 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_46 = F_31 ( V_83 -> V_17 ) ;
if ( V_46 < 0 )
return V_46 ;
V_44 . V_48 [ 0 ] = V_46 ;
if ( F_32 ( V_42 , & V_44 , sizeof( V_44 ) ) )
return - V_49 ;
return 0 ;
}
return - V_16 ;
}
static long F_67 ( struct V_35 * V_36 , unsigned int V_37 ,
unsigned long V_38 )
{
return F_66 ( V_36 , V_37 , ( unsigned long ) F_36 ( V_38 ) ) ;
}
static T_7 F_68 ( int V_97 , void * V_98 )
{
struct V_82 * V_83 = V_98 ;
struct V_91 V_99 ;
int V_57 ;
V_99 . V_100 = F_69 () ;
if ( V_83 -> V_101 & V_102 ) {
int V_103 = F_31 ( V_83 -> V_17 ) ;
if ( V_103 )
V_99 . V_104 = V_105 ;
else
V_99 . V_104 = V_106 ;
} else if ( V_83 -> V_101 & V_107 ) {
V_99 . V_104 = V_105 ;
} else if ( V_83 -> V_101 & V_108 ) {
V_99 . V_104 = V_106 ;
} else {
return V_109 ;
}
V_57 = F_70 ( & V_83 -> V_84 , V_99 ) ;
if ( V_57 != 0 )
F_71 ( & V_83 -> V_81 , V_85 ) ;
return V_110 ;
}
static int F_72 ( struct V_5 * V_6 , void T_2 * V_42 )
{
struct V_111 V_112 ;
struct V_82 * V_83 ;
struct V_1 * V_17 ;
struct V_35 * V_35 ;
T_3 V_21 ;
T_3 V_64 ;
T_3 V_101 ;
int V_56 ;
int V_57 ;
int V_113 = 0 ;
if ( F_33 ( & V_112 , V_42 , sizeof( V_112 ) ) )
return - V_49 ;
V_83 = F_42 ( sizeof( * V_83 ) , V_59 ) ;
if ( ! V_83 )
return - V_60 ;
V_83 -> V_6 = V_6 ;
F_43 ( & V_6 -> V_29 ) ;
V_112 . V_61 [ sizeof( V_112 . V_61 ) - 1 ] = '\0' ;
if ( strlen ( V_112 . V_61 ) ) {
V_83 -> V_3 = F_44 ( V_112 . V_61 ,
V_59 ) ;
if ( ! V_83 -> V_3 ) {
V_57 = - V_60 ;
goto V_114;
}
}
V_21 = V_112 . V_115 ;
V_64 = V_112 . V_116 ;
V_101 = V_112 . V_117 ;
if ( V_21 >= V_6 -> V_10 ) {
V_57 = - V_16 ;
goto V_118;
}
if ( ( V_64 & ~ V_66 ) ||
( V_101 & ~ V_119 ) ) {
V_57 = - V_16 ;
goto V_118;
}
if ( V_64 & V_73 ) {
V_57 = - V_16 ;
goto V_118;
}
V_17 = & V_6 -> V_11 [ V_21 ] ;
V_57 = F_45 ( V_17 , V_83 -> V_3 ) ;
if ( V_57 )
goto V_120;
V_83 -> V_17 = V_17 ;
V_83 -> V_101 = V_101 ;
if ( V_64 & V_67 )
F_19 ( V_68 , & V_17 -> V_7 ) ;
if ( V_64 & V_69 )
F_19 ( V_70 , & V_17 -> V_7 ) ;
if ( V_64 & V_71 )
F_19 ( V_72 , & V_17 -> V_7 ) ;
V_57 = F_47 ( V_17 ) ;
if ( V_57 )
goto V_120;
V_83 -> V_97 = F_73 ( V_17 ) ;
if ( V_83 -> V_97 <= 0 ) {
V_57 = - V_121 ;
goto V_120;
}
if ( V_101 & V_107 )
V_113 |= V_122 ;
if ( V_101 & V_108 )
V_113 |= V_123 ;
V_113 |= V_124 ;
V_113 |= V_125 ;
F_74 ( V_83 -> V_84 ) ;
F_75 ( & V_83 -> V_81 ) ;
F_76 ( & V_83 -> V_95 ) ;
V_57 = F_77 ( V_83 -> V_97 ,
NULL ,
F_68 ,
V_113 ,
V_83 -> V_3 ,
V_83 ) ;
if ( V_57 )
goto V_120;
V_56 = F_49 ( V_76 | V_77 ) ;
if ( V_56 < 0 ) {
V_57 = V_56 ;
goto V_126;
}
V_35 = F_50 ( L_9 ,
& V_127 ,
V_83 ,
V_76 | V_77 ) ;
if ( F_51 ( V_35 ) ) {
V_57 = F_52 ( V_35 ) ;
goto V_79;
}
V_112 . V_56 = V_56 ;
if ( F_32 ( V_42 , & V_112 , sizeof( V_112 ) ) ) {
F_53 ( V_35 ) ;
F_54 ( V_56 ) ;
return - V_49 ;
}
F_55 ( V_56 , V_35 ) ;
return 0 ;
V_79:
F_54 ( V_56 ) ;
V_126:
F_65 ( V_83 -> V_97 , V_83 ) ;
V_120:
F_38 ( V_83 -> V_17 ) ;
V_118:
F_39 ( V_83 -> V_3 ) ;
V_114:
F_39 ( V_83 ) ;
F_40 ( & V_6 -> V_29 ) ;
return V_57 ;
}
static long F_78 ( struct V_35 * V_128 , unsigned int V_37 , unsigned long V_38 )
{
struct V_5 * V_6 = V_128 -> V_41 ;
struct V_12 * V_13 = V_6 -> V_13 ;
void T_2 * V_42 = ( void T_2 * ) V_38 ;
if ( ! V_13 )
return - V_121 ;
if ( V_37 == V_129 ) {
struct V_130 V_131 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
strncpy ( V_131 . V_31 , F_79 ( & V_6 -> V_29 ) ,
sizeof( V_131 . V_31 ) ) ;
V_131 . V_31 [ sizeof( V_131 . V_31 ) - 1 ] = '\0' ;
strncpy ( V_131 . V_3 , V_6 -> V_3 ,
sizeof( V_131 . V_3 ) ) ;
V_131 . V_3 [ sizeof( V_131 . V_3 ) - 1 ] = '\0' ;
V_131 . V_58 = V_6 -> V_10 ;
if ( F_32 ( V_42 , & V_131 , sizeof( V_131 ) ) )
return - V_49 ;
return 0 ;
} else if ( V_37 == V_132 ) {
struct V_133 V_134 ;
struct V_1 * V_17 ;
if ( F_33 ( & V_134 , V_42 , sizeof( V_134 ) ) )
return - V_49 ;
if ( V_134 . V_135 >= V_6 -> V_10 )
return - V_16 ;
V_17 = & V_6 -> V_11 [ V_134 . V_135 ] ;
if ( V_17 -> V_31 ) {
strncpy ( V_134 . V_31 , V_17 -> V_31 ,
sizeof( V_134 . V_31 ) ) ;
V_134 . V_31 [ sizeof( V_134 . V_31 ) - 1 ] = '\0' ;
} else {
V_134 . V_31 [ 0 ] = '\0' ;
}
if ( V_17 -> V_3 ) {
strncpy ( V_134 . V_136 , V_17 -> V_3 ,
sizeof( V_134 . V_136 ) ) ;
V_134 . V_136 [ sizeof( V_134 . V_136 ) - 1 ] = '\0' ;
} else {
V_134 . V_136 [ 0 ] = '\0' ;
}
V_134 . V_7 = 0 ;
if ( F_80 ( V_137 , & V_17 -> V_7 ) ||
F_80 ( V_138 , & V_17 -> V_7 ) ||
F_80 ( V_139 , & V_17 -> V_7 ) ||
F_80 ( V_140 , & V_17 -> V_7 ) ||
F_80 ( V_141 , & V_17 -> V_7 ) )
V_134 . V_7 |= V_142 ;
if ( F_80 ( V_24 , & V_17 -> V_7 ) )
V_134 . V_7 |= V_143 ;
if ( F_80 ( V_68 , & V_17 -> V_7 ) )
V_134 . V_7 |= V_144 ;
if ( F_80 ( V_70 , & V_17 -> V_7 ) )
V_134 . V_7 |= V_145 ;
if ( F_80 ( V_72 , & V_17 -> V_7 ) )
V_134 . V_7 |= V_146 ;
if ( F_32 ( V_42 , & V_134 , sizeof( V_134 ) ) )
return - V_49 ;
return 0 ;
} else if ( V_37 == V_147 ) {
return F_41 ( V_6 , V_42 ) ;
} else if ( V_37 == V_148 ) {
return F_72 ( V_6 , V_42 ) ;
}
return - V_16 ;
}
static long F_81 ( struct V_35 * V_128 , unsigned int V_37 ,
unsigned long V_38 )
{
return F_78 ( V_128 , V_37 , ( unsigned long ) F_36 ( V_38 ) ) ;
}
static int F_82 ( struct V_53 * V_53 , struct V_35 * V_128 )
{
struct V_5 * V_6 = F_83 ( V_53 -> V_149 ,
struct V_5 , V_150 ) ;
if ( ! V_6 -> V_13 )
return - V_121 ;
F_43 ( & V_6 -> V_29 ) ;
V_128 -> V_41 = V_6 ;
return F_84 ( V_53 , V_128 ) ;
}
static int F_85 ( struct V_53 * V_53 , struct V_35 * V_128 )
{
struct V_5 * V_6 = F_83 ( V_53 -> V_149 ,
struct V_5 , V_150 ) ;
F_40 ( & V_6 -> V_29 ) ;
return 0 ;
}
static void F_86 ( struct V_151 * V_29 )
{
struct V_5 * V_6 = F_87 ( V_29 ) ;
F_88 ( & V_6 -> V_28 ) ;
F_89 ( & V_152 , V_6 -> V_104 ) ;
F_39 ( V_6 -> V_3 ) ;
F_39 ( V_6 -> V_11 ) ;
F_39 ( V_6 ) ;
}
static int F_90 ( struct V_5 * V_6 )
{
int V_22 ;
F_91 ( & V_6 -> V_150 , & V_153 ) ;
V_6 -> V_150 . V_154 = V_155 ;
V_6 -> V_150 . V_156 . V_157 = & V_6 -> V_29 . V_156 ;
V_6 -> V_29 . V_158 = F_92 ( F_93 ( V_159 ) , V_6 -> V_104 ) ;
V_22 = F_94 ( & V_6 -> V_150 , V_6 -> V_29 . V_158 , 1 ) ;
if ( V_22 < 0 )
F_95 ( V_6 -> V_13 , L_10 ,
F_93 ( V_159 ) , V_6 -> V_104 ) ;
else
F_96 ( V_6 -> V_13 , L_11 ,
F_93 ( V_159 ) , V_6 -> V_104 ) ;
V_22 = F_97 ( & V_6 -> V_29 ) ;
if ( V_22 )
goto V_160;
V_22 = F_98 ( V_6 ) ;
if ( V_22 )
goto V_161;
V_6 -> V_29 . V_162 = F_86 ;
F_14 ( L_12 ,
V_19 , V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
F_79 ( & V_6 -> V_29 ) , V_6 -> V_13 -> V_3 ? : L_13 ) ;
return 0 ;
V_161:
F_99 ( & V_6 -> V_29 ) ;
V_160:
F_100 ( & V_6 -> V_150 ) ;
return V_22 ;
}
static void F_101 ( void )
{
struct V_5 * V_6 ;
int V_163 ;
F_4 (gdev, &gpio_devices, list) {
V_163 = F_90 ( V_6 ) ;
if ( V_163 )
F_15 ( L_14 ,
F_79 ( & V_6 -> V_29 ) , V_163 ) ;
}
}
int F_102 ( struct V_12 * V_13 , void * V_164 )
{
unsigned long V_7 ;
int V_22 = 0 ;
unsigned V_32 ;
int V_9 = V_13 -> V_9 ;
struct V_5 * V_6 ;
V_6 = F_42 ( sizeof( * V_6 ) , V_59 ) ;
if ( ! V_6 )
return - V_60 ;
V_6 -> V_29 . V_165 = & V_166 ;
V_6 -> V_13 = V_13 ;
V_13 -> V_15 = V_6 ;
if ( V_13 -> V_157 ) {
V_6 -> V_29 . V_157 = V_13 -> V_157 ;
V_6 -> V_29 . V_167 = V_13 -> V_157 -> V_167 ;
}
#ifdef F_103
if ( V_13 -> V_167 )
V_6 -> V_29 . V_167 = V_13 -> V_167 ;
#endif
V_6 -> V_104 = F_104 ( & V_152 , 0 , 0 , V_59 ) ;
if ( V_6 -> V_104 < 0 ) {
V_22 = V_6 -> V_104 ;
goto V_168;
}
F_105 ( & V_6 -> V_29 , L_15 , V_6 -> V_104 ) ;
F_106 ( & V_6 -> V_29 ) ;
F_107 ( & V_6 -> V_29 , V_6 ) ;
if ( V_13 -> V_157 && V_13 -> V_157 -> V_169 )
V_6 -> V_154 = V_13 -> V_157 -> V_169 -> V_154 ;
else if ( V_13 -> V_154 )
V_6 -> V_154 = V_13 -> V_154 ;
else
V_6 -> V_154 = V_155 ;
V_6 -> V_11 = F_108 ( V_13 -> V_10 , sizeof( V_6 -> V_11 [ 0 ] ) , V_59 ) ;
if ( ! V_6 -> V_11 ) {
V_22 = - V_60 ;
goto V_168;
}
if ( V_13 -> V_10 == 0 ) {
F_109 ( V_13 , L_16 ) ;
V_22 = - V_16 ;
goto V_170;
}
if ( V_13 -> V_3 )
V_6 -> V_3 = F_44 ( V_13 -> V_3 , V_59 ) ;
else
V_6 -> V_3 = F_44 ( L_17 , V_59 ) ;
if ( ! V_6 -> V_3 ) {
V_22 = - V_60 ;
goto V_170;
}
V_6 -> V_10 = V_13 -> V_10 ;
V_6 -> V_164 = V_164 ;
F_3 ( & V_8 , V_7 ) ;
if ( V_9 < 0 ) {
V_9 = F_12 ( V_13 -> V_10 ) ;
if ( V_9 < 0 ) {
V_22 = V_9 ;
F_5 ( & V_8 , V_7 ) ;
goto V_171;
}
V_13 -> V_9 = V_9 ;
}
V_6 -> V_9 = V_9 ;
V_22 = F_20 ( V_6 ) ;
if ( V_22 ) {
F_5 ( & V_8 , V_7 ) ;
goto V_171;
}
F_5 ( & V_8 , V_7 ) ;
for ( V_32 = 0 ; V_32 < V_13 -> V_10 ; V_32 ++ ) {
struct V_1 * V_17 = & V_6 -> V_11 [ V_32 ] ;
V_17 -> V_6 = V_6 ;
if ( V_13 -> V_23 ) {
int V_172 = V_13 -> V_23 ( V_13 , V_32 ) ;
if ( ! V_172 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
} else if ( ! V_13 -> V_173 ) {
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
}
#ifdef F_110
F_111 ( & V_6 -> V_174 ) ;
#endif
V_22 = F_28 ( V_13 ) ;
if ( V_22 )
goto V_175;
V_22 = F_112 ( V_13 ) ;
if ( V_22 )
goto V_175;
V_22 = F_113 ( V_13 ) ;
if ( V_22 )
goto V_176;
F_114 ( V_13 ) ;
if ( V_177 ) {
V_22 = F_90 ( V_6 ) ;
if ( V_22 )
goto V_176;
}
return 0 ;
V_176:
F_115 ( V_13 ) ;
F_116 ( V_13 ) ;
F_117 ( V_13 ) ;
F_118 ( V_13 ) ;
V_175:
F_3 ( & V_8 , V_7 ) ;
F_88 ( & V_6 -> V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
V_171:
F_39 ( V_6 -> V_3 ) ;
V_170:
F_39 ( V_6 -> V_11 ) ;
V_168:
F_89 ( & V_152 , V_6 -> V_104 ) ;
F_15 ( L_18 , V_19 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
V_13 -> V_3 ? : L_13 ) ;
F_39 ( V_6 ) ;
return V_22 ;
}
void * F_119 ( struct V_12 * V_13 )
{
return V_13 -> V_15 -> V_164 ;
}
void F_120 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_15 ;
struct V_1 * V_17 ;
unsigned long V_7 ;
unsigned V_32 ;
bool V_178 = false ;
F_121 ( V_6 ) ;
F_116 ( V_13 ) ;
V_6 -> V_13 = NULL ;
F_122 ( V_13 ) ;
F_115 ( V_13 ) ;
F_123 ( V_13 ) ;
F_117 ( V_13 ) ;
V_6 -> V_164 = NULL ;
F_3 ( & V_8 , V_7 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_10 ; V_32 ++ ) {
V_17 = & V_6 -> V_11 [ V_32 ] ;
if ( F_80 ( V_137 , & V_17 -> V_7 ) )
V_178 = true ;
}
F_5 ( & V_8 , V_7 ) ;
if ( V_178 )
F_124 ( & V_6 -> V_29 ,
L_19 ) ;
F_100 ( & V_6 -> V_150 ) ;
F_99 ( & V_6 -> V_29 ) ;
F_40 ( & V_6 -> V_29 ) ;
}
static void F_125 ( struct V_151 * V_29 , void * V_179 )
{
struct V_12 * V_13 = * (struct V_12 * * ) V_179 ;
F_120 ( V_13 ) ;
}
static int F_126 ( struct V_151 * V_29 , void * V_179 , void * V_164 )
{
struct V_12 * * V_180 = V_179 ;
if ( ! V_180 || ! * V_180 ) {
F_127 ( ! V_180 || ! * V_180 ) ;
return 0 ;
}
return * V_180 == V_164 ;
}
int F_128 ( struct V_151 * V_29 , struct V_12 * V_13 ,
void * V_164 )
{
struct V_12 * * V_181 ;
int V_57 ;
V_181 = F_129 ( F_125 , sizeof( * V_181 ) ,
V_59 ) ;
if ( ! V_181 )
return - V_60 ;
V_57 = F_102 ( V_13 , V_164 ) ;
if ( V_57 < 0 ) {
F_130 ( V_181 ) ;
return V_57 ;
}
* V_181 = V_13 ;
F_131 ( V_29 , V_181 ) ;
return 0 ;
}
void F_132 ( struct V_151 * V_29 , struct V_12 * V_13 )
{
int V_57 ;
V_57 = F_133 ( V_29 , F_125 ,
F_126 , V_13 ) ;
F_127 ( V_57 ) ;
}
struct V_12 * F_134 ( void * V_164 ,
int (* F_135)( struct V_12 * V_13 ,
void * V_164 ) )
{
struct V_5 * V_6 ;
struct V_12 * V_13 = NULL ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list)
if ( V_6 -> V_13 && F_135 ( V_6 -> V_13 , V_164 ) ) {
V_13 = V_6 -> V_13 ;
break;
}
F_5 ( & V_8 , V_7 ) ;
return V_13 ;
}
static int F_136 ( struct V_12 * V_13 , void * V_164 )
{
const char * V_31 = V_164 ;
return ! strcmp ( V_13 -> V_3 , V_31 ) ;
}
static struct V_12 * F_137 ( const char * V_31 )
{
return F_134 ( ( void * ) V_31 , F_136 ) ;
}
static int F_112 ( struct V_12 * V_182 )
{
int V_32 ;
if ( ! V_182 -> V_183 )
return 0 ;
V_182 -> V_184 = F_108 ( F_138 ( V_182 -> V_10 ) ,
sizeof( long ) , V_59 ) ;
if ( ! V_182 -> V_184 )
return - V_60 ;
for ( V_32 = 0 ; V_32 < V_182 -> V_10 ; V_32 ++ )
F_19 ( V_32 , V_182 -> V_184 ) ;
return 0 ;
}
static void F_118 ( struct V_12 * V_182 )
{
F_39 ( V_182 -> V_184 ) ;
V_182 -> V_184 = NULL ;
}
static bool F_139 ( const struct V_12 * V_182 ,
unsigned int V_21 )
{
if ( F_140 ( ! V_182 -> V_184 ) )
return true ;
return F_80 ( V_21 , V_182 -> V_184 ) ;
}
static void F_141 ( struct V_12 * V_182 ,
struct V_185 * V_186 ,
int V_187 ,
T_8 V_188 )
{
unsigned int V_21 ;
if ( ! V_182 -> V_189 ) {
F_109 ( V_182 , L_20 ,
V_19 ) ;
return;
}
if ( V_188 ) {
if ( V_182 -> V_190 ) {
F_109 ( V_182 ,
L_21
L_22 ) ;
return;
}
F_142 ( V_187 , V_188 ,
V_182 ) ;
V_182 -> V_191 = V_187 ;
}
for ( V_21 = 0 ; V_21 < V_182 -> V_10 ; V_21 ++ ) {
if ( ! F_139 ( V_182 , V_21 ) )
continue;
F_143 ( F_144 ( V_182 -> V_189 , V_21 ) ,
V_187 ) ;
}
}
void F_145 ( struct V_12 * V_182 ,
struct V_185 * V_186 ,
int V_187 ,
T_8 V_188 )
{
F_141 ( V_182 , V_186 , V_187 ,
V_188 ) ;
}
void F_146 ( struct V_12 * V_182 ,
struct V_185 * V_186 ,
int V_187 )
{
if ( ! V_182 -> V_192 ) {
F_109 ( V_182 , L_23 ) ;
return;
}
F_141 ( V_182 , V_186 , V_187 ,
NULL ) ;
}
static int F_147 ( struct V_193 * V_2 , unsigned int V_97 ,
T_9 V_194 )
{
struct V_12 * V_13 = V_2 -> V_195 ;
F_148 ( V_97 , V_13 ) ;
F_149 ( V_97 , V_13 -> V_196 ) ;
F_150 ( V_97 , V_13 -> V_186 , V_13 -> V_197 ) ;
if ( V_13 -> V_192 )
F_151 ( V_97 , 1 ) ;
F_152 ( V_97 ) ;
if ( V_13 -> V_198 != V_199 )
F_153 ( V_97 , V_13 -> V_198 ) ;
return 0 ;
}
static void F_154 ( struct V_193 * V_2 , unsigned int V_97 )
{
struct V_12 * V_13 = V_2 -> V_195 ;
if ( V_13 -> V_192 )
F_151 ( V_97 , 0 ) ;
F_150 ( V_97 , NULL , NULL ) ;
F_148 ( V_97 , NULL ) ;
}
static int F_155 ( struct V_200 * V_2 )
{
struct V_12 * V_13 = F_156 ( V_2 ) ;
if ( ! F_157 ( V_13 -> V_15 -> V_154 ) )
return - V_121 ;
if ( F_158 ( V_13 , V_2 -> V_194 ) ) {
F_109 ( V_13 ,
L_24 ,
V_2 -> V_194 ) ;
F_159 ( V_13 -> V_15 -> V_154 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_160 ( struct V_200 * V_2 )
{
struct V_12 * V_13 = F_156 ( V_2 ) ;
F_161 ( V_13 , V_2 -> V_194 ) ;
F_159 ( V_13 -> V_15 -> V_154 ) ;
}
static int F_162 ( struct V_12 * V_13 , unsigned V_21 )
{
return F_144 ( V_13 -> V_189 , V_21 ) ;
}
static void F_122 ( struct V_12 * V_182 )
{
unsigned int V_21 ;
F_163 ( V_182 ) ;
if ( V_182 -> V_191 ) {
F_164 ( V_182 -> V_191 , NULL ) ;
F_165 ( V_182 -> V_191 , NULL ) ;
}
if ( V_182 -> V_189 ) {
for ( V_21 = 0 ; V_21 < V_182 -> V_10 ; V_21 ++ ) {
if ( ! F_139 ( V_182 , V_21 ) )
continue;
F_166 (
F_144 ( V_182 -> V_189 , V_21 ) ) ;
}
F_167 ( V_182 -> V_189 ) ;
}
if ( V_182 -> V_186 ) {
V_182 -> V_186 -> V_201 = NULL ;
V_182 -> V_186 -> V_202 = NULL ;
V_182 -> V_186 = NULL ;
}
F_118 ( V_182 ) ;
}
int F_168 ( struct V_12 * V_182 ,
struct V_185 * V_186 ,
unsigned int V_203 ,
T_8 V_204 ,
unsigned int type ,
bool V_205 ,
struct V_206 * V_196 )
{
struct V_207 * V_167 ;
bool V_208 = false ;
unsigned int V_21 ;
unsigned V_209 = 0 ;
if ( ! V_182 || ! V_186 )
return - V_16 ;
if ( ! V_182 -> V_157 ) {
F_15 ( L_25 ) ;
return - V_16 ;
}
V_182 -> V_192 = V_205 ;
V_167 = V_182 -> V_157 -> V_167 ;
#ifdef F_103
if ( V_182 -> V_167 )
V_167 = V_182 -> V_167 ;
#endif
if ( F_7 ( V_167 && type != V_199 ,
L_26 , V_167 -> V_210 , type ) )
type = V_199 ;
if ( F_169 ( V_182 -> V_157 ) && type != V_199 ) {
F_170 ( F_171 ( V_182 -> V_157 ) ,
L_27 , type ) ;
type = V_199 ;
}
V_182 -> V_186 = V_186 ;
V_182 -> V_197 = V_204 ;
V_182 -> V_198 = type ;
V_182 -> V_211 = F_162 ;
V_182 -> V_196 = V_196 ;
V_182 -> V_189 = F_172 ( V_167 ,
V_182 -> V_10 , V_203 ,
& V_212 , V_182 ) ;
if ( ! V_182 -> V_189 ) {
V_182 -> V_186 = NULL ;
return - V_16 ;
}
if ( ! V_186 -> V_201 &&
! V_186 -> V_202 ) {
V_186 -> V_201 = F_155 ;
V_186 -> V_202 = F_160 ;
}
for ( V_21 = 0 ; V_21 < V_182 -> V_10 ; V_21 ++ ) {
if ( ! F_139 ( V_182 , V_21 ) )
continue;
V_209 = F_173 ( V_182 -> V_189 , V_21 ) ;
if ( ! V_208 ) {
V_182 -> V_209 = V_209 ;
V_208 = true ;
}
}
F_174 ( V_182 ) ;
return 0 ;
}
static void F_122 ( struct V_12 * V_182 ) {}
static inline int F_112 ( struct V_12 * V_182 )
{
return 0 ;
}
static inline void F_118 ( struct V_12 * V_182 )
{ }
int F_175 ( struct V_12 * V_13 , unsigned V_21 )
{
return F_176 ( V_13 -> V_15 -> V_9 + V_21 ) ;
}
void F_177 ( struct V_12 * V_13 , unsigned V_21 )
{
F_178 ( V_13 -> V_15 -> V_9 + V_21 ) ;
}
int F_179 ( struct V_12 * V_13 , unsigned V_21 ,
unsigned long V_213 )
{
return F_180 ( V_13 -> V_15 -> V_9 + V_21 , V_213 ) ;
}
int F_181 ( struct V_12 * V_13 ,
struct V_214 * V_215 ,
unsigned int V_216 , const char * V_217 )
{
struct V_218 * V_219 ;
struct V_5 * V_6 = V_13 -> V_15 ;
int V_57 ;
V_219 = F_42 ( sizeof( * V_219 ) , V_59 ) ;
if ( ! V_219 ) {
F_109 ( V_13 , L_28 ) ;
return - V_60 ;
}
V_219 -> V_220 . V_104 = V_216 ;
V_219 -> V_220 . V_33 = V_13 ;
V_219 -> V_220 . V_31 = V_13 -> V_3 ;
V_219 -> V_220 . V_9 = V_6 -> V_9 + V_216 ;
V_219 -> V_215 = V_215 ;
V_57 = F_182 ( V_215 , V_217 ,
& V_219 -> V_220 . V_221 ,
& V_219 -> V_220 . V_222 ) ;
if ( V_57 < 0 ) {
F_39 ( V_219 ) ;
return V_57 ;
}
F_183 ( V_215 , & V_219 -> V_220 ) ;
F_96 ( V_13 , L_29 ,
V_216 , V_216 + V_219 -> V_220 . V_222 - 1 ,
F_184 ( V_215 ) , V_217 ) ;
F_22 ( & V_219 -> V_223 , & V_6 -> V_174 ) ;
return 0 ;
}
int F_185 ( struct V_12 * V_13 , const char * V_224 ,
unsigned int V_216 , unsigned int V_225 ,
unsigned int V_222 )
{
struct V_218 * V_219 ;
struct V_5 * V_6 = V_13 -> V_15 ;
int V_57 ;
V_219 = F_42 ( sizeof( * V_219 ) , V_59 ) ;
if ( ! V_219 ) {
F_109 ( V_13 , L_28 ) ;
return - V_60 ;
}
V_219 -> V_220 . V_104 = V_216 ;
V_219 -> V_220 . V_33 = V_13 ;
V_219 -> V_220 . V_31 = V_13 -> V_3 ;
V_219 -> V_220 . V_9 = V_6 -> V_9 + V_216 ;
V_219 -> V_220 . V_226 = V_225 ;
V_219 -> V_220 . V_222 = V_222 ;
V_219 -> V_215 = F_186 ( V_224 ,
& V_219 -> V_220 ) ;
if ( F_51 ( V_219 -> V_215 ) ) {
V_57 = F_52 ( V_219 -> V_215 ) ;
F_109 ( V_13 , L_30 ) ;
F_39 ( V_219 ) ;
return V_57 ;
}
F_96 ( V_13 , L_31 ,
V_216 , V_216 + V_222 - 1 ,
V_224 ,
V_225 , V_225 + V_222 - 1 ) ;
F_22 ( & V_219 -> V_223 , & V_6 -> V_174 ) ;
return 0 ;
}
void F_123 ( struct V_12 * V_13 )
{
struct V_218 * V_219 , * V_227 ;
struct V_5 * V_6 = V_13 -> V_15 ;
F_25 (pin_range, tmp, &gdev->pin_ranges, node) {
F_88 ( & V_219 -> V_223 ) ;
F_187 ( V_219 -> V_215 ,
& V_219 -> V_220 ) ;
F_39 ( V_219 ) ;
}
}
static int F_188 ( struct V_1 * V_17 , const char * V_3 )
{
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_22 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
if ( F_189 ( V_137 , & V_17 -> V_7 ) == 0 ) {
F_1 ( V_17 , V_3 ? : L_32 ) ;
V_22 = 0 ;
} else {
V_22 = - V_30 ;
goto V_228;
}
if ( V_13 -> V_229 ) {
F_5 ( & V_8 , V_7 ) ;
V_22 = V_13 -> V_229 ( V_13 , F_17 ( V_17 ) ) ;
F_3 ( & V_8 , V_7 ) ;
if ( V_22 < 0 ) {
F_1 ( V_17 , NULL ) ;
F_18 ( V_137 , & V_17 -> V_7 ) ;
goto V_228;
}
}
if ( V_13 -> V_23 ) {
F_5 ( & V_8 , V_7 ) ;
F_16 ( V_17 ) ;
F_3 ( & V_8 , V_7 ) ;
}
V_228:
F_5 ( & V_8 , V_7 ) ;
return V_22 ;
}
int F_45 ( struct V_1 * V_17 , const char * V_3 )
{
int V_22 = - V_230 ;
struct V_5 * V_6 ;
F_190 ( V_17 ) ;
V_6 = V_17 -> V_6 ;
if ( F_157 ( V_6 -> V_154 ) ) {
V_22 = F_188 ( V_17 , V_3 ) ;
if ( V_22 < 0 )
F_159 ( V_6 -> V_154 ) ;
else
F_43 ( & V_6 -> V_29 ) ;
}
if ( V_22 )
F_191 ( V_17 , L_33 , V_19 , V_22 ) ;
return V_22 ;
}
static bool F_192 ( struct V_1 * V_17 )
{
bool V_57 = false ;
unsigned long V_7 ;
struct V_12 * V_13 ;
F_193 () ;
F_194 ( V_17 ) ;
F_3 ( & V_8 , V_7 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( V_13 && F_80 ( V_137 , & V_17 -> V_7 ) ) {
if ( V_13 -> free ) {
F_5 ( & V_8 , V_7 ) ;
F_195 ( V_13 -> V_190 ) ;
V_13 -> free ( V_13 , F_17 ( V_17 ) ) ;
F_3 ( & V_8 , V_7 ) ;
}
F_1 ( V_17 , NULL ) ;
F_18 ( V_68 , & V_17 -> V_7 ) ;
F_18 ( V_137 , & V_17 -> V_7 ) ;
F_18 ( V_70 , & V_17 -> V_7 ) ;
F_18 ( V_72 , & V_17 -> V_7 ) ;
F_18 ( V_138 , & V_17 -> V_7 ) ;
V_57 = true ;
}
F_5 ( & V_8 , V_7 ) ;
return V_57 ;
}
void F_38 ( struct V_1 * V_17 )
{
if ( V_17 && V_17 -> V_6 && F_192 ( V_17 ) ) {
F_159 ( V_17 -> V_6 -> V_154 ) ;
F_40 ( & V_17 -> V_6 -> V_29 ) ;
} else {
F_127 ( V_231 ) ;
}
}
const char * F_196 ( struct V_12 * V_13 , unsigned V_21 )
{
struct V_1 * V_17 ;
if ( V_21 >= V_13 -> V_10 )
return NULL ;
V_17 = & V_13 -> V_15 -> V_11 [ V_21 ] ;
if ( F_80 ( V_137 , & V_17 -> V_7 ) == 0 )
return NULL ;
return V_17 -> V_3 ;
}
struct V_1 * F_197 ( struct V_12 * V_13 , T_1 V_14 ,
const char * V_3 )
{
struct V_1 * V_17 = F_8 ( V_13 , V_14 ) ;
int V_163 ;
if ( F_51 ( V_17 ) ) {
F_109 ( V_13 , L_34 ) ;
return V_17 ;
}
V_163 = F_188 ( V_17 , V_3 ) ;
if ( V_163 < 0 )
return F_9 ( V_163 ) ;
return V_17 ;
}
void F_198 ( struct V_1 * V_17 )
{
if ( V_17 )
F_192 ( V_17 ) ;
}
int F_47 ( struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_22 = - V_16 ;
F_190 ( V_17 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( ! V_13 -> V_232 || ! V_13 -> V_173 ) {
F_199 ( V_17 ,
L_35 ,
V_19 ) ;
return - V_233 ;
}
V_22 = V_13 -> V_173 ( V_13 , F_17 ( V_17 ) ) ;
if ( V_22 == 0 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
F_200 ( F_10 ( V_17 ) , 1 , V_22 ) ;
return V_22 ;
}
static int F_201 ( struct V_12 * V_33 , unsigned V_21 ,
enum V_234 V_235 )
{
unsigned long V_213 = { F_202 (mode, 0 ) } ;
return V_33 -> V_236 ? V_33 -> V_236 ( V_33 , V_21 , V_213 ) : - V_237 ;
}
static int F_203 ( struct V_1 * V_17 , int V_238 )
{
struct V_12 * V_33 = V_17 -> V_6 -> V_13 ;
int V_46 = ! ! V_238 ;
int V_57 ;
if ( F_80 ( V_139 , & V_17 -> V_7 ) ) {
F_204 ( V_17 ,
L_36 ,
V_19 ) ;
return - V_233 ;
}
if ( F_80 ( V_70 , & V_17 -> V_7 ) ) {
V_57 = F_201 ( V_33 , F_17 ( V_17 ) ,
V_239 ) ;
if ( ! V_57 )
goto V_240;
if ( V_46 )
return F_47 ( V_17 ) ;
}
else if ( F_80 ( V_72 , & V_17 -> V_7 ) ) {
V_57 = F_201 ( V_33 , F_17 ( V_17 ) ,
V_241 ) ;
if ( ! V_57 )
goto V_240;
if ( ! V_46 )
return F_47 ( V_17 ) ;
} else {
F_201 ( V_33 , F_17 ( V_17 ) ,
V_242 ) ;
}
V_240:
if ( ! V_33 -> V_243 || ! V_33 -> V_244 ) {
F_199 ( V_17 ,
L_37 ,
V_19 ) ;
return - V_233 ;
}
V_57 = V_33 -> V_244 ( V_33 , F_17 ( V_17 ) , V_46 ) ;
if ( ! V_57 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
F_205 ( F_10 ( V_17 ) , 0 , V_46 ) ;
F_200 ( F_10 ( V_17 ) , 0 , V_57 ) ;
return V_57 ;
}
int F_206 ( struct V_1 * V_17 , int V_238 )
{
F_190 ( V_17 ) ;
return F_203 ( V_17 , V_238 ) ;
}
int F_46 ( struct V_1 * V_17 , int V_238 )
{
F_190 ( V_17 ) ;
if ( F_80 ( V_68 , & V_17 -> V_7 ) )
V_238 = ! V_238 ;
else
V_238 = ! ! V_238 ;
return F_203 ( V_17 , V_238 ) ;
}
int F_207 ( struct V_1 * V_17 , unsigned V_245 )
{
struct V_12 * V_13 ;
unsigned long V_213 ;
F_190 ( V_17 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( ! V_13 -> V_243 || ! V_13 -> V_236 ) {
F_191 ( V_17 ,
L_38 ,
V_19 ) ;
return - V_237 ;
}
V_213 = F_208 ( V_246 , V_245 ) ;
return V_13 -> V_236 ( V_13 , F_17 ( V_17 ) , V_213 ) ;
}
int F_209 ( const struct V_1 * V_17 )
{
F_190 ( V_17 ) ;
return F_80 ( V_68 , & V_17 -> V_7 ) ;
}
static int F_210 ( const struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_21 ;
int V_238 ;
V_13 = V_17 -> V_6 -> V_13 ;
V_21 = F_17 ( V_17 ) ;
V_238 = V_13 -> V_232 ? V_13 -> V_232 ( V_13 , V_21 ) : - V_233 ;
V_238 = V_238 < 0 ? V_238 : ! ! V_238 ;
F_205 ( F_10 ( V_17 ) , 1 , V_238 ) ;
return V_238 ;
}
int F_211 ( const struct V_1 * V_17 )
{
F_190 ( V_17 ) ;
F_127 ( V_17 -> V_6 -> V_13 -> V_190 ) ;
return F_210 ( V_17 ) ;
}
int F_212 ( const struct V_1 * V_17 )
{
int V_238 ;
F_190 ( V_17 ) ;
F_127 ( V_17 -> V_6 -> V_13 -> V_190 ) ;
V_238 = F_210 ( V_17 ) ;
if ( V_238 < 0 )
return V_238 ;
if ( F_80 ( V_68 , & V_17 -> V_7 ) )
V_238 = ! V_238 ;
return V_238 ;
}
static void F_213 ( struct V_1 * V_17 , bool V_238 )
{
int V_163 = 0 ;
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_21 = F_17 ( V_17 ) ;
if ( V_238 ) {
V_163 = V_13 -> V_173 ( V_13 , V_21 ) ;
if ( ! V_163 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
} else {
V_163 = V_13 -> V_244 ( V_13 , V_21 , 0 ) ;
if ( ! V_163 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
F_200 ( F_10 ( V_17 ) , V_238 , V_163 ) ;
if ( V_163 < 0 )
F_204 ( V_17 ,
L_39 ,
V_19 , V_163 ) ;
}
static void F_214 ( struct V_1 * V_17 , bool V_238 )
{
int V_163 = 0 ;
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_21 = F_17 ( V_17 ) ;
if ( V_238 ) {
V_163 = V_13 -> V_244 ( V_13 , V_21 , 1 ) ;
if ( ! V_163 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
} else {
V_163 = V_13 -> V_173 ( V_13 , V_21 ) ;
if ( ! V_163 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
}
F_200 ( F_10 ( V_17 ) , ! V_238 , V_163 ) ;
if ( V_163 < 0 )
F_204 ( V_17 ,
L_40 ,
V_19 , V_163 ) ;
}
static void F_215 ( struct V_1 * V_17 , bool V_238 )
{
struct V_12 * V_13 ;
V_13 = V_17 -> V_6 -> V_13 ;
F_205 ( F_10 ( V_17 ) , 0 , V_238 ) ;
if ( F_80 ( V_70 , & V_17 -> V_7 ) )
F_213 ( V_17 , V_238 ) ;
else if ( F_80 ( V_72 , & V_17 -> V_7 ) )
F_214 ( V_17 , V_238 ) ;
else
V_13 -> V_243 ( V_13 , F_17 ( V_17 ) , V_238 ) ;
}
static void F_216 ( struct V_12 * V_13 ,
unsigned long * V_247 , unsigned long * V_248 )
{
if ( V_13 -> V_249 ) {
V_13 -> V_249 ( V_13 , V_247 , V_248 ) ;
} else {
unsigned int V_32 ;
F_217 (i, mask, chip->ngpio)
V_13 -> V_243 ( V_13 , V_32 , F_80 ( V_32 , V_248 ) ) ;
}
}
void F_34 ( bool V_250 , bool V_190 ,
unsigned int V_251 ,
struct V_1 * * V_252 ,
int * V_253 )
{
int V_32 = 0 ;
while ( V_32 < V_251 ) {
struct V_12 * V_13 = V_252 [ V_32 ] -> V_6 -> V_13 ;
unsigned long V_247 [ F_138 ( V_13 -> V_10 ) ] ;
unsigned long V_248 [ F_138 ( V_13 -> V_10 ) ] ;
int V_88 = 0 ;
if ( ! V_190 )
F_127 ( V_13 -> V_190 ) ;
memset ( V_247 , 0 , sizeof( V_247 ) ) ;
do {
struct V_1 * V_17 = V_252 [ V_32 ] ;
int V_254 = F_17 ( V_17 ) ;
int V_238 = V_253 [ V_32 ] ;
if ( ! V_250 && F_80 ( V_68 , & V_17 -> V_7 ) )
V_238 = ! V_238 ;
F_205 ( F_10 ( V_17 ) , 0 , V_238 ) ;
if ( F_80 ( V_70 , & V_17 -> V_7 ) ) {
F_213 ( V_17 , V_238 ) ;
} else if ( F_80 ( V_72 , & V_17 -> V_7 ) ) {
F_214 ( V_17 , V_238 ) ;
} else {
F_218 ( V_254 , V_247 ) ;
if ( V_238 )
F_218 ( V_254 , V_248 ) ;
else
F_219 ( V_254 , V_248 ) ;
V_88 ++ ;
}
V_32 ++ ;
} while ( ( V_32 < V_251 ) &&
( V_252 [ V_32 ] -> V_6 -> V_13 == V_13 ) );
if ( V_88 != 0 )
F_216 ( V_13 , V_247 , V_248 ) ;
}
}
void F_220 ( struct V_1 * V_17 , int V_238 )
{
F_221 ( V_17 ) ;
F_127 ( V_17 -> V_6 -> V_13 -> V_190 ) ;
F_215 ( V_17 , V_238 ) ;
}
void F_222 ( struct V_1 * V_17 , int V_238 )
{
F_221 ( V_17 ) ;
F_127 ( V_17 -> V_6 -> V_13 -> V_190 ) ;
if ( F_80 ( V_68 , & V_17 -> V_7 ) )
V_238 = ! V_238 ;
F_215 ( V_17 , V_238 ) ;
}
void F_223 ( unsigned int V_251 ,
struct V_1 * * V_252 , int * V_253 )
{
if ( ! V_252 )
return;
F_34 ( true , false , V_251 , V_252 ,
V_253 ) ;
}
void F_224 ( unsigned int V_251 ,
struct V_1 * * V_252 , int * V_253 )
{
if ( ! V_252 )
return;
F_34 ( false , false , V_251 , V_252 ,
V_253 ) ;
}
int F_225 ( const struct V_1 * V_17 )
{
F_190 ( V_17 ) ;
return V_17 -> V_6 -> V_13 -> V_190 ;
}
int F_73 ( const struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_21 ;
if ( ! V_17 || F_51 ( V_17 ) || ! V_17 -> V_6 || ! V_17 -> V_6 -> V_13 )
return - V_16 ;
V_13 = V_17 -> V_6 -> V_13 ;
V_21 = F_17 ( V_17 ) ;
if ( V_13 -> V_211 ) {
int V_255 = V_13 -> V_211 ( V_13 , V_21 ) ;
if ( ! V_255 )
return - V_256 ;
return V_255 ;
}
return - V_256 ;
}
int F_158 ( struct V_12 * V_13 , unsigned int V_21 )
{
struct V_1 * V_17 ;
V_17 = F_8 ( V_13 , V_21 ) ;
if ( F_51 ( V_17 ) )
return F_52 ( V_17 ) ;
if ( ! V_13 -> V_190 && V_13 -> V_23 ) {
int V_172 = V_13 -> V_23 ( V_13 , V_21 ) ;
if ( V_172 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
else
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
if ( F_80 ( V_24 , & V_17 -> V_7 ) ) {
F_109 ( V_13 ,
L_41 ,
V_19 ) ;
return - V_233 ;
}
F_19 ( V_139 , & V_17 -> V_7 ) ;
if ( ! V_17 -> V_3 )
F_1 ( V_17 , L_42 ) ;
return 0 ;
}
void F_161 ( struct V_12 * V_13 , unsigned int V_21 )
{
struct V_1 * V_17 ;
V_17 = F_8 ( V_13 , V_21 ) ;
if ( F_51 ( V_17 ) )
return;
F_18 ( V_139 , & V_17 -> V_7 ) ;
if ( V_17 -> V_3 && ! strcmp ( V_17 -> V_3 , L_42 ) )
F_1 ( V_17 , NULL ) ;
}
bool F_226 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_80 ( V_139 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
bool F_227 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_80 ( V_70 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
bool F_228 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_80 ( V_72 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
int F_229 ( const struct V_1 * V_17 )
{
F_195 ( V_231 ) ;
F_190 ( V_17 ) ;
return F_210 ( V_17 ) ;
}
int F_31 ( const struct V_1 * V_17 )
{
int V_238 ;
F_195 ( V_231 ) ;
F_190 ( V_17 ) ;
V_238 = F_210 ( V_17 ) ;
if ( V_238 < 0 )
return V_238 ;
if ( F_80 ( V_68 , & V_17 -> V_7 ) )
V_238 = ! V_238 ;
return V_238 ;
}
void F_230 ( struct V_1 * V_17 , int V_238 )
{
F_195 ( V_231 ) ;
F_221 ( V_17 ) ;
F_215 ( V_17 , V_238 ) ;
}
void F_231 ( struct V_1 * V_17 , int V_238 )
{
F_195 ( V_231 ) ;
F_221 ( V_17 ) ;
if ( F_80 ( V_68 , & V_17 -> V_7 ) )
V_238 = ! V_238 ;
F_215 ( V_17 , V_238 ) ;
}
void F_232 ( unsigned int V_251 ,
struct V_1 * * V_252 ,
int * V_253 )
{
F_195 ( V_231 ) ;
if ( ! V_252 )
return;
F_34 ( true , true , V_251 , V_252 ,
V_253 ) ;
}
void F_233 ( unsigned int V_251 ,
struct V_1 * * V_252 ,
int * V_253 )
{
F_195 ( V_231 ) ;
if ( ! V_252 )
return;
F_34 ( false , true , V_251 , V_252 ,
V_253 ) ;
}
void F_234 ( struct V_257 * V_258 )
{
F_235 ( & V_259 ) ;
F_22 ( & V_258 -> V_28 , & V_260 ) ;
F_63 ( & V_259 ) ;
}
void F_236 ( struct V_257 * V_258 )
{
F_235 ( & V_259 ) ;
F_88 ( & V_258 -> V_28 ) ;
F_63 ( & V_259 ) ;
}
static struct V_257 * F_237 ( struct V_151 * V_29 )
{
const char * V_261 = V_29 ? F_79 ( V_29 ) : NULL ;
struct V_257 * V_258 ;
F_235 ( & V_259 ) ;
F_4 (table, &gpio_lookup_list, list) {
if ( V_258 -> V_261 && V_261 ) {
if ( ! strcmp ( V_258 -> V_261 , V_261 ) )
goto V_262;
} else {
if ( V_261 == V_258 -> V_261 )
goto V_262;
}
}
V_258 = NULL ;
V_262:
F_63 ( & V_259 ) ;
return V_258 ;
}
static struct V_1 * F_238 ( struct V_151 * V_29 , const char * V_263 ,
unsigned int V_264 ,
enum V_265 * V_7 )
{
struct V_1 * V_17 = F_9 ( - V_266 ) ;
struct V_257 * V_258 ;
struct V_267 * V_98 ;
V_258 = F_237 ( V_29 ) ;
if ( ! V_258 )
return V_17 ;
for ( V_98 = & V_258 -> V_258 [ 0 ] ; V_98 -> V_268 ; V_98 ++ ) {
struct V_12 * V_13 ;
if ( V_98 -> V_264 != V_264 )
continue;
if ( V_98 -> V_263 && ( ! V_263 || strcmp ( V_98 -> V_263 , V_263 ) ) )
continue;
V_13 = F_137 ( V_98 -> V_268 ) ;
if ( ! V_13 ) {
F_26 ( V_29 , L_43 ,
V_98 -> V_268 ) ;
return F_9 ( - V_121 ) ;
}
if ( V_13 -> V_10 <= V_98 -> V_269 ) {
F_26 ( V_29 ,
L_44 ,
V_264 , V_13 -> V_10 , V_13 -> V_3 ) ;
return F_9 ( - V_16 ) ;
}
V_17 = F_8 ( V_13 , V_98 -> V_269 ) ;
* V_7 = V_98 -> V_7 ;
return V_17 ;
}
return V_17 ;
}
static int F_239 ( struct V_151 * V_29 , const char * V_263 )
{
int V_57 ;
char V_270 [ 32 ] ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_240 ( V_271 ) ; V_32 ++ ) {
if ( V_263 )
snprintf ( V_270 , sizeof( V_270 ) , L_45 ,
V_263 , V_271 [ V_32 ] ) ;
else
snprintf ( V_270 , sizeof( V_270 ) , L_46 ,
V_271 [ V_32 ] ) ;
V_57 = F_241 ( V_29 -> V_167 , V_270 ) ;
if ( V_57 >= 0 )
break;
}
return V_57 ;
}
static int F_242 ( struct V_151 * V_29 , const char * V_263 )
{
struct V_257 * V_258 ;
struct V_267 * V_98 ;
unsigned int V_88 = 0 ;
V_258 = F_237 ( V_29 ) ;
if ( ! V_258 )
return - V_266 ;
for ( V_98 = & V_258 -> V_258 [ 0 ] ; V_98 -> V_268 ; V_98 ++ ) {
if ( ( V_263 && V_98 -> V_263 && ! strcmp ( V_263 , V_98 -> V_263 ) ) ||
( ! V_263 && ! V_98 -> V_263 ) )
V_88 ++ ;
}
if ( ! V_88 )
return - V_266 ;
return V_88 ;
}
int F_243 ( struct V_151 * V_29 , const char * V_263 )
{
int V_88 = - V_266 ;
if ( F_244 ( V_272 ) && V_29 && V_29 -> V_167 )
V_88 = F_239 ( V_29 , V_263 ) ;
else if ( F_244 ( V_273 ) && V_29 && F_171 ( V_29 ) )
V_88 = F_245 ( V_29 , V_263 ) ;
if ( V_88 < 0 )
V_88 = F_242 ( V_29 , V_263 ) ;
return V_88 ;
}
struct V_1 * T_10 F_246 ( struct V_151 * V_29 , const char * V_263 ,
enum V_274 V_7 )
{
return F_247 ( V_29 , V_263 , 0 , V_7 ) ;
}
struct V_1 * T_10 F_248 ( struct V_151 * V_29 ,
const char * V_263 ,
enum V_274 V_7 )
{
return F_249 ( V_29 , V_263 , 0 , V_7 ) ;
}
static int F_250 ( struct V_1 * V_17 , const char * V_263 ,
unsigned long V_64 , enum V_274 V_275 )
{
int V_22 ;
if ( V_64 & V_276 )
F_19 ( V_68 , & V_17 -> V_7 ) ;
if ( V_64 & V_277 )
F_19 ( V_70 , & V_17 -> V_7 ) ;
if ( V_64 & V_278 )
F_19 ( V_72 , & V_17 -> V_7 ) ;
if ( ! ( V_275 & V_279 ) ) {
F_14 ( L_47 , V_263 ) ;
return 0 ;
}
if ( V_275 & V_280 )
V_22 = F_46 ( V_17 ,
! ! ( V_275 & V_281 ) ) ;
else
V_22 = F_47 ( V_17 ) ;
return V_22 ;
}
struct V_1 * T_10 F_247 ( struct V_151 * V_29 ,
const char * V_263 ,
unsigned int V_264 ,
enum V_274 V_7 )
{
struct V_1 * V_17 = NULL ;
int V_22 ;
enum V_265 V_282 = 0 ;
F_48 ( V_29 , L_48 , V_263 ) ;
if ( V_29 ) {
if ( F_244 ( V_272 ) && V_29 -> V_167 ) {
F_48 ( V_29 , L_49 ) ;
V_17 = F_251 ( V_29 , V_263 , V_264 , & V_282 ) ;
} else if ( F_252 ( V_29 ) ) {
F_48 ( V_29 , L_50 ) ;
V_17 = F_253 ( V_29 , V_263 , V_264 , V_7 , & V_282 ) ;
}
}
if ( ! V_17 || V_17 == F_9 ( - V_266 ) ) {
F_48 ( V_29 , L_51 ) ;
V_17 = F_238 ( V_29 , V_263 , V_264 , & V_282 ) ;
}
if ( F_51 ( V_17 ) ) {
F_48 ( V_29 , L_52 , V_263 ) ;
return V_17 ;
}
V_22 = F_45 ( V_17 , V_263 ) ;
if ( V_22 < 0 )
return F_9 ( V_22 ) ;
V_22 = F_250 ( V_17 , V_263 , V_282 , V_7 ) ;
if ( V_22 < 0 ) {
F_48 ( V_29 , L_53 , V_263 ) ;
F_254 ( V_17 ) ;
return F_9 ( V_22 ) ;
}
return V_17 ;
}
struct V_1 * F_255 ( struct V_283 * V_284 ,
const char * V_270 , int V_285 ,
enum V_274 V_275 ,
const char * V_3 )
{
struct V_1 * V_17 = F_9 ( - V_121 ) ;
unsigned long V_64 = 0 ;
bool V_286 = false ;
bool V_287 = false ;
int V_57 ;
if ( ! V_284 )
return F_9 ( - V_16 ) ;
if ( F_256 ( V_284 ) ) {
enum V_288 V_7 ;
V_17 = F_257 ( F_258 ( V_284 ) , V_270 ,
V_285 , & V_7 ) ;
if ( ! F_51 ( V_17 ) ) {
V_286 = V_7 & V_289 ;
V_287 = V_7 & V_290 ;
}
} else if ( F_259 ( V_284 ) ) {
struct V_291 V_292 ;
V_17 = F_260 ( V_284 , V_270 , V_285 , & V_292 ) ;
if ( ! F_51 ( V_17 ) )
V_286 = V_292 . V_293 == V_276 ;
}
if ( F_51 ( V_17 ) )
return V_17 ;
V_57 = F_45 ( V_17 , V_3 ) ;
if ( V_57 )
return F_9 ( V_57 ) ;
if ( V_286 )
V_64 |= V_276 ;
if ( V_287 ) {
if ( V_286 )
V_64 |= V_277 ;
else
V_64 |= V_278 ;
}
V_57 = F_250 ( V_17 , V_270 , V_64 , V_275 ) ;
if ( V_57 < 0 ) {
F_254 ( V_17 ) ;
return F_9 ( V_57 ) ;
}
return V_17 ;
}
struct V_1 * T_10 F_249 ( struct V_151 * V_29 ,
const char * V_263 ,
unsigned int V_285 ,
enum V_274 V_7 )
{
struct V_1 * V_17 ;
V_17 = F_247 ( V_29 , V_263 , V_285 , V_7 ) ;
if ( F_51 ( V_17 ) ) {
if ( F_52 ( V_17 ) == - V_266 )
return NULL ;
}
return V_17 ;
}
int F_261 ( struct V_1 * V_17 , const char * V_31 ,
unsigned long V_64 , enum V_274 V_275 )
{
struct V_12 * V_13 ;
struct V_1 * V_294 ;
int V_14 ;
int V_22 ;
V_13 = F_11 ( V_17 ) ;
V_14 = F_17 ( V_17 ) ;
V_294 = F_197 ( V_13 , V_14 , V_31 ) ;
if ( F_51 ( V_294 ) ) {
V_22 = F_52 ( V_294 ) ;
F_15 ( L_54 ,
V_31 , V_13 -> V_3 , V_14 , V_22 ) ;
return V_22 ;
}
V_22 = F_250 ( V_17 , V_31 , V_64 , V_275 ) ;
if ( V_22 < 0 ) {
F_15 ( L_55 ,
V_31 , V_13 -> V_3 , V_14 , V_22 ) ;
F_198 ( V_17 ) ;
return V_22 ;
}
F_19 ( V_138 , & V_17 -> V_7 ) ;
F_262 ( L_56 ,
F_10 ( V_17 ) , V_31 ,
( V_275 & V_280 ) ? L_57 : L_58 ,
( V_275 & V_280 ) ?
( V_275 & V_281 ) ? L_59 : L_60 : L_61 ) ;
return 0 ;
}
static void F_116 ( struct V_12 * V_13 )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < V_13 -> V_10 ; V_104 ++ ) {
if ( F_80 ( V_138 , & V_13 -> V_15 -> V_11 [ V_104 ] . V_7 ) )
F_198 ( & V_13 -> V_15 -> V_11 [ V_104 ] ) ;
}
}
struct V_295 * T_10 F_263 ( struct V_151 * V_29 ,
const char * V_263 ,
enum V_274 V_7 )
{
struct V_1 * V_17 ;
struct V_295 * V_11 ;
int V_88 ;
V_88 = F_243 ( V_29 , V_263 ) ;
if ( V_88 < 0 )
return F_9 ( V_88 ) ;
V_11 = F_42 ( sizeof( * V_11 ) + sizeof( V_11 -> V_17 [ 0 ] ) * V_88 ,
V_59 ) ;
if ( ! V_11 )
return F_9 ( - V_60 ) ;
for ( V_11 -> V_296 = 0 ; V_11 -> V_296 < V_88 ; ) {
V_17 = F_247 ( V_29 , V_263 , V_11 -> V_296 , V_7 ) ;
if ( F_51 ( V_17 ) ) {
F_264 ( V_11 ) ;
return F_265 ( V_17 ) ;
}
V_11 -> V_17 [ V_11 -> V_296 ] = V_17 ;
V_11 -> V_296 ++ ;
}
return V_11 ;
}
struct V_295 * T_10 F_266 ( struct V_151 * V_29 ,
const char * V_263 ,
enum V_274 V_7 )
{
struct V_295 * V_11 ;
V_11 = F_263 ( V_29 , V_263 , V_7 ) ;
if ( F_51 ( V_11 ) && ( F_52 ( V_11 ) == - V_266 ) )
return NULL ;
return V_11 ;
}
void F_254 ( struct V_1 * V_17 )
{
F_38 ( V_17 ) ;
}
void F_264 ( struct V_295 * V_11 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_11 -> V_296 ; V_32 ++ )
F_254 ( V_11 -> V_17 [ V_32 ] ) ;
F_39 ( V_11 ) ;
}
static int T_11 F_267 ( void )
{
int V_57 ;
V_57 = F_268 ( & V_166 ) ;
if ( V_57 < 0 ) {
F_15 ( L_62 ) ;
return V_57 ;
}
V_57 = F_269 ( & V_159 , 0 , V_297 , L_63 ) ;
if ( V_57 < 0 ) {
F_15 ( L_64 ) ;
F_270 ( & V_166 ) ;
} else {
V_177 = true ;
F_101 () ;
}
return V_57 ;
}
static void F_271 ( struct V_298 * V_299 , struct V_5 * V_6 )
{
unsigned V_32 ;
struct V_12 * V_13 = V_6 -> V_13 ;
unsigned V_4 = V_6 -> V_9 ;
struct V_1 * V_300 = & V_6 -> V_11 [ 0 ] ;
int V_301 ;
int V_302 ;
for ( V_32 = 0 ; V_32 < V_6 -> V_10 ; V_32 ++ , V_4 ++ , V_300 ++ ) {
if ( ! F_80 ( V_137 , & V_300 -> V_7 ) ) {
if ( V_300 -> V_31 ) {
F_272 ( V_299 , L_65 ,
V_4 , V_300 -> V_31 ) ;
}
continue;
}
F_16 ( V_300 ) ;
V_301 = F_80 ( V_24 , & V_300 -> V_7 ) ;
V_302 = F_80 ( V_139 , & V_300 -> V_7 ) ;
F_272 ( V_299 , L_66 ,
V_4 , V_300 -> V_31 ? V_300 -> V_31 : L_61 , V_300 -> V_3 ,
V_301 ? L_67 : L_68 ,
V_13 -> V_232
? ( V_13 -> V_232 ( V_13 , V_32 ) ? L_69 : L_70 )
: L_71 ,
V_302 ? L_72 : L_73 ) ;
F_272 ( V_299 , L_74 ) ;
}
}
static void * F_273 ( struct V_298 * V_299 , T_6 * V_303 )
{
unsigned long V_7 ;
struct V_5 * V_6 = NULL ;
T_6 V_285 = * V_303 ;
V_299 -> V_304 = L_61 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list)
if ( V_285 -- == 0 ) {
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static void * F_274 ( struct V_298 * V_299 , void * V_305 , T_6 * V_303 )
{
unsigned long V_7 ;
struct V_5 * V_6 = V_305 ;
void * V_57 = NULL ;
F_3 ( & V_8 , V_7 ) ;
if ( F_275 ( & V_6 -> V_28 , & V_27 ) )
V_57 = NULL ;
else
V_57 = F_23 ( V_6 -> V_28 . V_26 , struct V_5 , V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
V_299 -> V_304 = L_74 ;
++ * V_303 ;
return V_57 ;
}
static void F_276 ( struct V_298 * V_299 , void * V_305 )
{
}
static int F_277 ( struct V_298 * V_299 , void * V_305 )
{
struct V_5 * V_6 = V_305 ;
struct V_12 * V_13 = V_6 -> V_13 ;
struct V_151 * V_157 ;
if ( ! V_13 ) {
F_272 ( V_299 , L_75 , ( char * ) V_299 -> V_304 ,
F_79 ( & V_6 -> V_29 ) ) ;
return 0 ;
}
F_272 ( V_299 , L_76 , ( char * ) V_299 -> V_304 ,
F_79 ( & V_6 -> V_29 ) ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ) ;
V_157 = V_13 -> V_157 ;
if ( V_157 )
F_272 ( V_299 , L_77 ,
V_157 -> V_165 ? V_157 -> V_165 -> V_31 : L_78 ,
F_79 ( V_157 ) ) ;
if ( V_13 -> V_3 )
F_272 ( V_299 , L_79 , V_13 -> V_3 ) ;
if ( V_13 -> V_190 )
F_272 ( V_299 , L_80 ) ;
F_272 ( V_299 , L_81 ) ;
if ( V_13 -> V_306 )
V_13 -> V_306 ( V_299 , V_13 ) ;
else
F_271 ( V_299 , V_6 ) ;
return 0 ;
}
static int F_278 ( struct V_53 * V_53 , struct V_35 * V_35 )
{
return F_279 ( V_35 , & V_307 ) ;
}
static int T_11 F_280 ( void )
{
( void ) F_281 ( L_82 , V_308 | V_309 ,
NULL , NULL , & V_310 ) ;
return 0 ;
}
