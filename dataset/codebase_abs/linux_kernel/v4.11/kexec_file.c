int __weak F_1 ( struct V_1 * V_2 , void * V_3 ,
unsigned long V_4 )
{
return - V_5 ;
}
void * __weak F_2 ( struct V_1 * V_2 )
{
return F_3 ( - V_5 ) ;
}
int __weak F_4 ( struct V_1 * V_2 )
{
return - V_6 ;
}
int __weak F_5 ( struct V_1 * V_2 , void * V_3 ,
unsigned long V_4 )
{
return - V_7 ;
}
int __weak
F_6 ( const T_1 * V_8 , T_2 * V_9 ,
unsigned int V_10 )
{
F_7 ( L_1 ) ;
return - V_5 ;
}
int __weak
F_8 ( const T_1 * V_8 , T_2 * V_9 ,
unsigned int V_10 )
{
F_7 ( L_2 ) ;
return - V_5 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_11 ;
F_10 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
F_10 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
F_11 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
F_10 ( V_12 -> V_16 ) ;
V_12 -> V_16 = NULL ;
F_10 ( V_12 -> V_9 ) ;
V_12 -> V_9 = NULL ;
F_4 ( V_2 ) ;
F_11 ( V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
}
static int
F_12 ( struct V_1 * V_2 , int V_18 , int V_19 ,
const char T_3 * V_20 ,
unsigned long V_21 , unsigned V_22 )
{
int V_23 = 0 ;
void * V_24 ;
T_4 V_25 ;
V_23 = F_13 ( V_18 , & V_2 -> V_13 ,
& V_25 , V_26 , V_27 ) ;
if ( V_23 )
return V_23 ;
V_2 -> V_28 = V_25 ;
F_14 ( V_2 ) ;
V_23 = F_1 ( V_2 , V_2 -> V_13 ,
V_2 -> V_28 ) ;
if ( V_23 )
goto V_29;
#ifdef F_15
V_23 = F_5 ( V_2 , V_2 -> V_13 ,
V_2 -> V_28 ) ;
if ( V_23 ) {
F_16 ( L_3 ) ;
goto V_29;
}
F_16 ( L_4 ) ;
#endif
if ( ! ( V_22 & V_30 ) ) {
V_23 = F_13 ( V_19 , & V_2 -> V_14 ,
& V_25 , V_26 ,
V_31 ) ;
if ( V_23 )
goto V_29;
V_2 -> V_32 = V_25 ;
}
if ( V_21 ) {
V_2 -> V_15 = F_17 ( V_21 , V_33 ) ;
if ( ! V_2 -> V_15 ) {
V_23 = - V_34 ;
goto V_29;
}
V_23 = F_18 ( V_2 -> V_15 , V_20 ,
V_21 ) ;
if ( V_23 ) {
V_23 = - V_35 ;
goto V_29;
}
V_2 -> V_36 = V_21 ;
if ( V_2 -> V_15 [ V_21 - 1 ] != '\0' ) {
V_23 = - V_6 ;
goto V_29;
}
}
V_24 = F_2 ( V_2 ) ;
if ( F_19 ( V_24 ) ) {
V_23 = F_20 ( V_24 ) ;
goto V_29;
}
V_2 -> V_17 = V_24 ;
V_29:
if ( V_23 )
F_9 ( V_2 ) ;
return V_23 ;
}
static int
F_21 ( struct V_1 * * V_37 , int V_18 ,
int V_19 , const char T_3 * V_20 ,
unsigned long V_21 , unsigned long V_22 )
{
int V_23 ;
struct V_1 * V_2 ;
bool V_38 = V_22 & V_39 ;
V_2 = F_22 () ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_40 = 1 ;
if ( V_38 ) {
V_2 -> V_41 = V_42 . V_43 ;
V_2 -> type = V_44 ;
}
V_23 = F_12 ( V_2 , V_18 , V_19 ,
V_20 , V_21 , V_22 ) ;
if ( V_23 )
goto V_45;
V_23 = F_23 ( V_2 ) ;
if ( V_23 )
goto V_46;
V_23 = - V_34 ;
V_2 -> V_47 = F_24 ( V_2 ,
F_25 ( V_48 ) ) ;
if ( ! V_2 -> V_47 ) {
F_7 ( L_5 ) ;
goto V_46;
}
if ( ! V_38 ) {
V_2 -> V_49 = F_24 ( V_2 , 0 ) ;
if ( ! V_2 -> V_49 ) {
F_7 ( L_6 ) ;
goto V_50;
}
}
* V_37 = V_2 ;
return 0 ;
V_50:
F_26 ( & V_2 -> V_51 ) ;
V_46:
F_9 ( V_2 ) ;
V_45:
F_11 ( V_2 ) ;
return V_23 ;
}
static int F_27 ( unsigned long V_43 , unsigned long V_52 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
unsigned long V_55 , V_56 ;
V_56 = F_28 ( V_52 , V_54 -> V_57 ) ;
V_55 = V_56 - V_54 -> V_58 ;
do {
V_55 = V_55 & ( ~ ( V_54 -> V_59 - 1 ) ) ;
if ( V_55 < V_43 || V_55 < V_54 -> V_60 )
return 0 ;
V_56 = V_55 + V_54 -> V_58 - 1 ;
if ( F_29 ( V_2 , V_55 , V_56 ) ) {
V_55 = V_55 - V_61 ;
continue;
}
break;
} while ( 1 );
V_54 -> V_62 = V_55 ;
return 1 ;
}
static int F_30 ( unsigned long V_43 , unsigned long V_52 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
unsigned long V_55 , V_56 ;
V_55 = F_31 ( V_43 , V_54 -> V_60 ) ;
do {
V_55 = F_32 ( V_55 , V_54 -> V_59 ) ;
V_56 = V_55 + V_54 -> V_58 - 1 ;
if ( V_56 > V_52 || V_56 > V_54 -> V_57 )
return 0 ;
if ( F_29 ( V_2 , V_55 , V_56 ) ) {
V_55 = V_55 + V_61 ;
continue;
}
break;
} while ( 1 );
V_54 -> V_62 = V_55 ;
return 1 ;
}
static int F_33 ( T_5 V_43 , T_5 V_52 , void * V_63 )
{
struct V_53 * V_54 = (struct V_53 * ) V_63 ;
unsigned long V_64 = V_52 - V_43 + 1 ;
if ( V_64 < V_54 -> V_58 )
return 0 ;
if ( V_52 < V_54 -> V_60 || V_43 > V_54 -> V_57 )
return 0 ;
if ( V_54 -> V_65 )
return F_27 ( V_43 , V_52 , V_54 ) ;
return F_30 ( V_43 , V_52 , V_54 ) ;
}
int __weak F_34 ( struct V_53 * V_54 ,
int (* F_35)( T_5 , T_5 , void * ) )
{
if ( V_54 -> V_2 -> type == V_44 )
return F_36 ( V_42 . V_66 ,
V_67 | V_68 ,
V_42 . V_43 , V_42 . V_52 ,
V_54 , F_35 ) ;
else
return F_37 ( 0 , V_69 , V_54 , F_35 ) ;
}
int F_38 ( struct V_53 * V_54 )
{
int V_23 ;
V_23 = F_34 ( V_54 , F_33 ) ;
return V_23 == 1 ? 0 : - V_70 ;
}
int F_39 ( struct V_53 * V_54 )
{
struct V_71 * V_72 ;
int V_23 ;
if ( ! V_54 -> V_2 -> V_40 )
return - V_6 ;
if ( V_54 -> V_2 -> V_73 >= V_74 )
return - V_6 ;
if ( ! F_40 ( & V_54 -> V_2 -> V_51 ) ) {
F_41 ( 1 ) ;
return - V_6 ;
}
V_54 -> V_58 = F_32 ( V_54 -> V_58 , V_61 ) ;
V_54 -> V_59 = F_31 ( V_54 -> V_59 , V_61 ) ;
V_23 = F_38 ( V_54 ) ;
if ( V_23 )
return V_23 ;
V_72 = & V_54 -> V_2 -> V_75 [ V_54 -> V_2 -> V_73 ] ;
V_72 -> V_54 = V_54 -> V_76 ;
V_72 -> V_77 = V_54 -> V_77 ;
V_72 -> V_62 = V_54 -> V_62 ;
V_72 -> V_58 = V_54 -> V_58 ;
V_54 -> V_2 -> V_73 ++ ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_78 * V_79 ;
struct V_80 * V_66 ;
int V_23 = 0 , V_81 , V_82 , V_83 , V_84 ;
T_6 V_85 , V_86 ;
char * V_87 ;
void * V_88 ;
struct V_89 * V_90 ;
struct V_11 * V_12 = & V_2 -> V_11 ;
V_88 = F_43 ( F_44 ( F_45 ( 0 ) ) << V_91 ) ;
V_83 = V_61 ;
V_79 = F_46 ( L_7 , 0 , 0 ) ;
if ( F_19 ( V_79 ) ) {
V_23 = F_20 ( V_79 ) ;
goto V_29;
}
V_85 = F_47 ( V_79 ) + sizeof( * V_66 ) ;
V_66 = F_17 ( V_85 , V_33 ) ;
if ( ! V_66 ) {
V_23 = - V_34 ;
goto V_92;
}
V_84 = V_74 * sizeof( struct V_89 ) ;
V_90 = F_48 ( V_84 ) ;
if ( ! V_90 )
goto V_93;
V_66 -> V_79 = V_79 ;
V_66 -> V_22 = 0 ;
V_23 = F_49 ( V_66 ) ;
if ( V_23 < 0 )
goto V_94;
V_87 = F_17 ( V_95 , V_33 ) ;
if ( ! V_87 ) {
V_23 = - V_34 ;
goto V_94;
}
for ( V_82 = V_81 = 0 ; V_81 < V_2 -> V_73 ; V_81 ++ ) {
struct V_71 * V_72 ;
V_72 = & V_2 -> V_75 [ V_81 ] ;
if ( V_72 -> V_54 == V_12 -> V_16 )
continue;
V_23 = F_50 ( V_66 , V_72 -> V_54 ,
V_72 -> V_77 ) ;
if ( V_23 )
break;
V_86 = V_72 -> V_58 - V_72 -> V_77 ;
while ( V_86 ) {
unsigned long V_96 = V_86 ;
if ( V_96 > V_83 )
V_96 = V_83 ;
V_23 = F_50 ( V_66 , V_88 , V_96 ) ;
if ( V_23 )
break;
V_86 -= V_96 ;
}
if ( V_23 )
break;
V_90 [ V_82 ] . V_43 = V_72 -> V_62 ;
V_90 [ V_82 ] . V_97 = V_72 -> V_58 ;
V_82 ++ ;
}
if ( ! V_23 ) {
V_23 = F_51 ( V_66 , V_87 ) ;
if ( V_23 )
goto V_98;
V_23 = F_52 ( V_2 , L_8 ,
V_90 , V_84 , 0 ) ;
if ( V_23 )
goto V_98;
V_23 = F_52 ( V_2 , L_9 ,
V_87 , V_95 , 0 ) ;
if ( V_23 )
goto V_98;
}
V_98:
F_11 ( V_87 ) ;
V_94:
F_10 ( V_90 ) ;
V_93:
F_11 ( V_66 ) ;
V_92:
F_11 ( V_79 ) ;
V_29:
return V_23 ;
}
static int F_53 ( struct V_1 * V_2 , unsigned long F_28 ,
unsigned long F_31 , int V_65 )
{
struct V_11 * V_12 = & V_2 -> V_11 ;
unsigned long V_99 , V_100 , V_101 , V_102 ;
unsigned long V_103 , V_104 , V_105 , V_106 , V_107 ;
unsigned char * V_108 , * V_109 ;
int V_81 , V_23 = 0 , V_110 = - 1 ;
const T_2 * V_111 ;
T_2 * V_9 = NULL ;
struct V_53 V_54 = { . V_2 = V_2 , . V_77 = 0 , . V_59 = 1 ,
. V_60 = F_28 , . V_57 = F_31 ,
. V_65 = V_65 } ;
V_111 = ( void * ) V_12 -> V_8 + V_12 -> V_8 -> V_112 ;
V_9 = F_48 ( V_12 -> V_8 -> V_113 * sizeof( T_2 ) ) ;
if ( ! V_9 )
return - V_34 ;
memcpy ( V_9 , V_111 , V_12 -> V_8 -> V_113 * sizeof( T_2 ) ) ;
for ( V_81 = 0 ; V_81 < V_12 -> V_8 -> V_113 ; V_81 ++ ) {
if ( V_9 [ V_81 ] . V_114 == V_115 )
continue;
V_9 [ V_81 ] . V_116 = ( unsigned long ) V_12 -> V_8 +
V_9 [ V_81 ] . V_116 ;
}
V_103 = V_12 -> V_8 -> V_117 ;
for ( V_81 = 0 ; V_81 < V_12 -> V_8 -> V_113 ; V_81 ++ ) {
if ( ! ( V_9 [ V_81 ] . V_118 & V_119 ) )
continue;
if ( ! ( V_9 [ V_81 ] . V_118 & V_120 ) )
continue;
if ( V_9 [ V_81 ] . V_121 <= V_12 -> V_8 -> V_117 &&
( ( V_9 [ V_81 ] . V_121 + V_9 [ V_81 ] . V_122 ) >
V_12 -> V_8 -> V_117 ) ) {
V_110 = V_81 ;
V_103 -= V_9 [ V_81 ] . V_121 ;
break;
}
}
V_100 = 1 ;
V_101 = 0 ;
for ( V_81 = 0 ; V_81 < V_12 -> V_8 -> V_113 ; V_81 ++ ) {
if ( ! ( V_9 [ V_81 ] . V_118 & V_119 ) )
continue;
V_99 = V_9 [ V_81 ] . V_123 ;
if ( V_9 [ V_81 ] . V_114 != V_115 ) {
if ( V_54 . V_59 < V_99 )
V_54 . V_59 = V_99 ;
V_54 . V_77 = F_32 ( V_54 . V_77 , V_99 ) ;
V_54 . V_77 += V_9 [ V_81 ] . V_122 ;
} else {
if ( V_100 < V_99 )
V_100 = V_99 ;
V_101 = F_32 ( V_101 , V_99 ) ;
V_101 += V_9 [ V_81 ] . V_122 ;
}
}
V_102 = 0 ;
if ( V_54 . V_77 & ( V_100 - 1 ) )
V_102 = V_100 - ( V_54 . V_77 & ( V_100 - 1 ) ) ;
V_54 . V_58 = V_54 . V_77 + V_102 + V_101 ;
V_54 . V_76 = F_48 ( V_54 . V_77 ) ;
if ( ! V_54 . V_76 ) {
V_23 = - V_34 ;
goto V_29;
}
if ( V_54 . V_59 < V_100 )
V_54 . V_59 = V_100 ;
V_23 = F_39 ( & V_54 ) ;
if ( V_23 )
goto V_29;
V_12 -> V_124 = V_54 . V_62 ;
V_108 = V_54 . V_76 ;
V_104 = V_105 = V_12 -> V_124 ;
V_106 = V_104 + V_54 . V_77 + V_102 ;
for ( V_81 = 0 ; V_81 < V_12 -> V_8 -> V_113 ; V_81 ++ ) {
if ( ! ( V_9 [ V_81 ] . V_118 & V_119 ) )
continue;
V_99 = V_9 [ V_81 ] . V_123 ;
if ( V_9 [ V_81 ] . V_114 != V_115 ) {
V_105 = F_32 ( V_105 , V_99 ) ;
V_107 = V_105 - V_104 ;
V_109 = ( char * ) V_9 [ V_81 ] . V_116 ;
memcpy ( V_108 + V_107 , V_109 , V_9 [ V_81 ] . V_122 ) ;
V_9 [ V_81 ] . V_121 = V_105 ;
V_9 [ V_81 ] . V_116 = ( unsigned long ) ( V_108 + V_107 ) ;
V_105 += V_9 [ V_81 ] . V_122 ;
} else {
V_106 = F_32 ( V_106 , V_99 ) ;
V_9 [ V_81 ] . V_121 = V_106 ;
V_106 += V_9 [ V_81 ] . V_122 ;
}
}
if ( V_110 >= 0 )
V_103 += V_9 [ V_110 ] . V_121 ;
V_2 -> V_43 = V_103 ;
V_12 -> V_9 = V_9 ;
V_12 -> V_16 = V_54 . V_76 ;
return V_23 ;
V_29:
F_10 ( V_9 ) ;
F_10 ( V_54 . V_76 ) ;
return V_23 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_81 , V_23 ;
struct V_11 * V_12 = & V_2 -> V_11 ;
T_2 * V_9 = V_12 -> V_9 ;
for ( V_81 = 0 ; V_81 < V_12 -> V_8 -> V_113 ; V_81 ++ ) {
T_2 * V_125 , * V_126 ;
if ( V_9 [ V_81 ] . V_114 != V_127 &&
V_9 [ V_81 ] . V_114 != V_128 )
continue;
if ( V_9 [ V_81 ] . V_129 >= V_12 -> V_8 -> V_113 ||
V_9 [ V_81 ] . V_130 >= V_12 -> V_8 -> V_113 )
return - V_5 ;
V_125 = & V_9 [ V_9 [ V_81 ] . V_129 ] ;
V_126 = & V_9 [ V_9 [ V_81 ] . V_130 ] ;
if ( ! ( V_125 -> V_118 & V_119 ) )
continue;
if ( V_126 -> V_130 >= V_12 -> V_8 -> V_113 )
continue;
if ( V_9 [ V_81 ] . V_114 == V_127 )
V_23 = F_6 ( V_12 -> V_8 ,
V_9 , V_81 ) ;
else if ( V_9 [ V_81 ] . V_114 == V_128 )
V_23 = F_8 ( V_12 -> V_8 ,
V_9 , V_81 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_2 , unsigned long F_28 ,
unsigned long F_31 , int V_65 ,
unsigned long * V_104 )
{
struct V_11 * V_12 = & V_2 -> V_11 ;
int V_23 ;
if ( V_131 <= 0 )
return - V_6 ;
if ( V_131 < sizeof( T_1 ) )
return - V_5 ;
V_12 -> V_8 = ( T_1 * ) V_132 ;
if ( memcmp ( V_12 -> V_8 -> V_133 , V_134 , V_135 ) != 0
|| V_12 -> V_8 -> V_136 != V_137
|| ! F_56 ( V_12 -> V_8 )
|| V_12 -> V_8 -> V_138 != sizeof( T_2 ) )
return - V_5 ;
if ( V_12 -> V_8 -> V_112 >= V_131
|| ( V_12 -> V_8 -> V_113 * sizeof( T_2 ) >
V_131 - V_12 -> V_8 -> V_112 ) )
return - V_5 ;
V_23 = F_53 ( V_2 , F_28 , F_31 , V_65 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_54 ( V_2 ) ;
if ( V_23 )
goto V_29;
* V_104 = V_12 -> V_124 ;
return 0 ;
V_29:
F_10 ( V_12 -> V_9 ) ;
V_12 -> V_9 = NULL ;
F_10 ( V_12 -> V_16 ) ;
V_12 -> V_16 = NULL ;
return V_23 ;
}
static T_7 * F_57 ( struct V_11 * V_12 ,
const char * V_139 )
{
T_7 * V_140 ;
T_2 * V_9 ;
T_1 * V_8 ;
int V_81 , V_141 ;
const char * V_142 ;
if ( ! V_12 -> V_9 || ! V_12 -> V_8 )
return NULL ;
V_9 = V_12 -> V_9 ;
V_8 = V_12 -> V_8 ;
for ( V_81 = 0 ; V_81 < V_8 -> V_113 ; V_81 ++ ) {
if ( V_9 [ V_81 ] . V_114 != V_143 )
continue;
if ( V_9 [ V_81 ] . V_130 >= V_8 -> V_113 )
continue;
V_142 = ( char * ) V_9 [ V_9 [ V_81 ] . V_130 ] . V_116 ;
V_140 = ( T_7 * ) V_9 [ V_81 ] . V_116 ;
for ( V_141 = 0 ; V_141 < V_9 [ V_81 ] . V_122 / sizeof( T_7 ) ; V_141 ++ ) {
if ( F_58 ( V_140 [ V_141 ] . V_144 ) != V_145 )
continue;
if ( strcmp ( V_142 + V_140 [ V_141 ] . V_146 , V_139 ) != 0 )
continue;
if ( V_140 [ V_141 ] . V_147 == V_148 ||
V_140 [ V_141 ] . V_147 >= V_8 -> V_113 ) {
F_16 ( L_10 ,
V_139 , V_140 [ V_141 ] . V_147 ) ;
return NULL ;
}
return & V_140 [ V_141 ] ;
}
}
return NULL ;
}
void * F_59 ( struct V_1 * V_2 , const char * V_139 )
{
struct V_11 * V_12 = & V_2 -> V_11 ;
T_7 * V_149 ;
T_2 * V_150 ;
V_149 = F_57 ( V_12 , V_139 ) ;
if ( ! V_149 )
return F_3 ( - V_6 ) ;
V_150 = & V_12 -> V_9 [ V_149 -> V_147 ] ;
return ( void * ) ( V_150 -> V_121 + V_149 -> V_151 ) ;
}
int F_52 ( struct V_1 * V_2 , const char * V_139 ,
void * V_3 , unsigned int V_25 , bool V_152 )
{
T_7 * V_149 ;
T_2 * V_9 ;
struct V_11 * V_12 = & V_2 -> V_11 ;
char * V_153 ;
V_149 = F_57 ( V_12 , V_139 ) ;
if ( ! V_149 )
return - V_6 ;
if ( V_149 -> V_154 != V_25 ) {
F_7 ( L_11 ,
V_139 , ( unsigned long ) V_149 -> V_154 , V_25 ) ;
return - V_6 ;
}
V_9 = V_12 -> V_9 ;
if ( V_9 [ V_149 -> V_147 ] . V_114 == V_115 ) {
F_7 ( L_12 , V_139 ,
V_152 ? L_13 : L_14 ) ;
return - V_6 ;
}
V_153 = ( unsigned char * ) V_9 [ V_149 -> V_147 ] . V_116 +
V_149 -> V_151 ;
if ( V_152 )
memcpy ( ( void * ) V_3 , V_153 , V_25 ) ;
else
memcpy ( ( void * ) V_153 , V_3 , V_25 ) ;
return 0 ;
}
