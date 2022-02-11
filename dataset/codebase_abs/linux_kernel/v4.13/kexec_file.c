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
V_2 -> V_15 = F_17 ( V_20 , V_21 ) ;
if ( F_18 ( V_2 -> V_15 ) ) {
V_23 = F_19 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
goto V_29;
}
V_2 -> V_33 = V_21 ;
if ( V_2 -> V_15 [ V_21 - 1 ] != '\0' ) {
V_23 = - V_6 ;
goto V_29;
}
}
V_24 = F_2 ( V_2 ) ;
if ( F_18 ( V_24 ) ) {
V_23 = F_19 ( V_24 ) ;
goto V_29;
}
V_2 -> V_17 = V_24 ;
V_29:
if ( V_23 )
F_9 ( V_2 ) ;
return V_23 ;
}
static int
F_20 ( struct V_1 * * V_34 , int V_18 ,
int V_19 , const char T_3 * V_20 ,
unsigned long V_21 , unsigned long V_22 )
{
int V_23 ;
struct V_1 * V_2 ;
bool V_35 = V_22 & V_36 ;
V_2 = F_21 () ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_38 = 1 ;
if ( V_35 ) {
V_2 -> V_39 = V_40 . V_41 ;
V_2 -> type = V_42 ;
}
V_23 = F_12 ( V_2 , V_18 , V_19 ,
V_20 , V_21 , V_22 ) ;
if ( V_23 )
goto V_43;
V_23 = F_22 ( V_2 ) ;
if ( V_23 )
goto V_44;
V_23 = - V_37 ;
V_2 -> V_45 = F_23 ( V_2 ,
F_24 ( V_46 ) ) ;
if ( ! V_2 -> V_45 ) {
F_7 ( L_5 ) ;
goto V_44;
}
if ( ! V_35 ) {
V_2 -> V_47 = F_23 ( V_2 , 0 ) ;
if ( ! V_2 -> V_47 ) {
F_7 ( L_6 ) ;
goto V_48;
}
}
* V_34 = V_2 ;
return 0 ;
V_48:
F_25 ( & V_2 -> V_49 ) ;
V_44:
F_9 ( V_2 ) ;
V_43:
F_11 ( V_2 ) ;
return V_23 ;
}
static int F_26 ( unsigned long V_41 , unsigned long V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned long V_53 , V_54 ;
V_54 = F_27 ( V_50 , V_52 -> V_55 ) ;
V_53 = V_54 - V_52 -> V_56 ;
do {
V_53 = V_53 & ( ~ ( V_52 -> V_57 - 1 ) ) ;
if ( V_53 < V_41 || V_53 < V_52 -> V_58 )
return 0 ;
V_54 = V_53 + V_52 -> V_56 - 1 ;
if ( F_28 ( V_2 , V_53 , V_54 ) ) {
V_53 = V_53 - V_59 ;
continue;
}
break;
} while ( 1 );
V_52 -> V_60 = V_53 ;
return 1 ;
}
static int F_29 ( unsigned long V_41 , unsigned long V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned long V_53 , V_54 ;
V_53 = F_30 ( V_41 , V_52 -> V_58 ) ;
do {
V_53 = F_31 ( V_53 , V_52 -> V_57 ) ;
V_54 = V_53 + V_52 -> V_56 - 1 ;
if ( V_54 > V_50 || V_54 > V_52 -> V_55 )
return 0 ;
if ( F_28 ( V_2 , V_53 , V_54 ) ) {
V_53 = V_53 + V_59 ;
continue;
}
break;
} while ( 1 );
V_52 -> V_60 = V_53 ;
return 1 ;
}
static int F_32 ( T_5 V_41 , T_5 V_50 , void * V_61 )
{
struct V_51 * V_52 = (struct V_51 * ) V_61 ;
unsigned long V_62 = V_50 - V_41 + 1 ;
if ( V_62 < V_52 -> V_56 )
return 0 ;
if ( V_50 < V_52 -> V_58 || V_41 > V_52 -> V_55 )
return 0 ;
if ( V_52 -> V_63 )
return F_26 ( V_41 , V_50 , V_52 ) ;
return F_29 ( V_41 , V_50 , V_52 ) ;
}
int __weak F_33 ( struct V_51 * V_52 ,
int (* F_34)( T_5 , T_5 , void * ) )
{
if ( V_52 -> V_2 -> type == V_42 )
return F_35 ( V_40 . V_64 ,
V_65 | V_66 ,
V_40 . V_41 , V_40 . V_50 ,
V_52 , F_34 ) ;
else
return F_36 ( 0 , V_67 , V_52 , F_34 ) ;
}
int F_37 ( struct V_51 * V_52 )
{
int V_23 ;
V_23 = F_33 ( V_52 , F_32 ) ;
return V_23 == 1 ? 0 : - V_68 ;
}
int F_38 ( struct V_51 * V_52 )
{
struct V_69 * V_70 ;
int V_23 ;
if ( ! V_52 -> V_2 -> V_38 )
return - V_6 ;
if ( V_52 -> V_2 -> V_71 >= V_72 )
return - V_6 ;
if ( ! F_39 ( & V_52 -> V_2 -> V_49 ) ) {
F_40 ( 1 ) ;
return - V_6 ;
}
V_52 -> V_56 = F_31 ( V_52 -> V_56 , V_59 ) ;
V_52 -> V_57 = F_30 ( V_52 -> V_57 , V_59 ) ;
V_23 = F_37 ( V_52 ) ;
if ( V_23 )
return V_23 ;
V_70 = & V_52 -> V_2 -> V_73 [ V_52 -> V_2 -> V_71 ] ;
V_70 -> V_52 = V_52 -> V_74 ;
V_70 -> V_75 = V_52 -> V_75 ;
V_70 -> V_60 = V_52 -> V_60 ;
V_70 -> V_56 = V_52 -> V_56 ;
V_52 -> V_2 -> V_71 ++ ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
struct V_78 * V_64 ;
int V_23 = 0 , V_79 , V_80 , V_81 , V_82 ;
T_6 V_83 , V_84 ;
char * V_85 ;
void * V_86 ;
struct V_87 * V_88 ;
struct V_11 * V_12 = & V_2 -> V_11 ;
V_86 = F_42 ( F_43 ( F_44 ( 0 ) ) << V_89 ) ;
V_81 = V_59 ;
V_77 = F_45 ( L_7 , 0 , 0 ) ;
if ( F_18 ( V_77 ) ) {
V_23 = F_19 ( V_77 ) ;
goto V_29;
}
V_83 = F_46 ( V_77 ) + sizeof( * V_64 ) ;
V_64 = F_47 ( V_83 , V_90 ) ;
if ( ! V_64 ) {
V_23 = - V_37 ;
goto V_91;
}
V_82 = V_72 * sizeof( struct V_87 ) ;
V_88 = F_48 ( V_82 ) ;
if ( ! V_88 )
goto V_92;
V_64 -> V_77 = V_77 ;
V_64 -> V_22 = 0 ;
V_23 = F_49 ( V_64 ) ;
if ( V_23 < 0 )
goto V_93;
V_85 = F_47 ( V_94 , V_90 ) ;
if ( ! V_85 ) {
V_23 = - V_37 ;
goto V_93;
}
for ( V_80 = V_79 = 0 ; V_79 < V_2 -> V_71 ; V_79 ++ ) {
struct V_69 * V_70 ;
V_70 = & V_2 -> V_73 [ V_79 ] ;
if ( V_70 -> V_52 == V_12 -> V_16 )
continue;
V_23 = F_50 ( V_64 , V_70 -> V_52 ,
V_70 -> V_75 ) ;
if ( V_23 )
break;
V_84 = V_70 -> V_56 - V_70 -> V_75 ;
while ( V_84 ) {
unsigned long V_95 = V_84 ;
if ( V_95 > V_81 )
V_95 = V_81 ;
V_23 = F_50 ( V_64 , V_86 , V_95 ) ;
if ( V_23 )
break;
V_84 -= V_95 ;
}
if ( V_23 )
break;
V_88 [ V_80 ] . V_41 = V_70 -> V_60 ;
V_88 [ V_80 ] . V_96 = V_70 -> V_56 ;
V_80 ++ ;
}
if ( ! V_23 ) {
V_23 = F_51 ( V_64 , V_85 ) ;
if ( V_23 )
goto V_97;
V_23 = F_52 ( V_2 , L_8 ,
V_88 , V_82 , 0 ) ;
if ( V_23 )
goto V_97;
V_23 = F_52 ( V_2 , L_9 ,
V_85 , V_94 , 0 ) ;
if ( V_23 )
goto V_97;
}
V_97:
F_11 ( V_85 ) ;
V_93:
F_10 ( V_88 ) ;
V_92:
F_11 ( V_64 ) ;
V_91:
F_11 ( V_77 ) ;
V_29:
return V_23 ;
}
static int F_53 ( struct V_1 * V_2 , unsigned long F_27 ,
unsigned long F_30 , int V_63 )
{
struct V_11 * V_12 = & V_2 -> V_11 ;
unsigned long V_98 , V_99 , V_100 , V_101 ;
unsigned long V_102 , V_103 , V_104 , V_105 , V_106 ;
unsigned char * V_107 , * V_108 ;
int V_79 , V_23 = 0 , V_109 = - 1 ;
const T_2 * V_110 ;
T_2 * V_9 = NULL ;
struct V_51 V_52 = { . V_2 = V_2 , . V_75 = 0 , . V_57 = 1 ,
. V_58 = F_27 , . V_55 = F_30 ,
. V_63 = V_63 } ;
V_110 = ( void * ) V_12 -> V_8 + V_12 -> V_8 -> V_111 ;
V_9 = F_48 ( V_12 -> V_8 -> V_112 * sizeof( T_2 ) ) ;
if ( ! V_9 )
return - V_37 ;
memcpy ( V_9 , V_110 , V_12 -> V_8 -> V_112 * sizeof( T_2 ) ) ;
for ( V_79 = 0 ; V_79 < V_12 -> V_8 -> V_112 ; V_79 ++ ) {
if ( V_9 [ V_79 ] . V_113 == V_114 )
continue;
V_9 [ V_79 ] . V_115 = ( unsigned long ) V_12 -> V_8 +
V_9 [ V_79 ] . V_115 ;
}
V_102 = V_12 -> V_8 -> V_116 ;
for ( V_79 = 0 ; V_79 < V_12 -> V_8 -> V_112 ; V_79 ++ ) {
if ( ! ( V_9 [ V_79 ] . V_117 & V_118 ) )
continue;
if ( ! ( V_9 [ V_79 ] . V_117 & V_119 ) )
continue;
if ( V_9 [ V_79 ] . V_120 <= V_12 -> V_8 -> V_116 &&
( ( V_9 [ V_79 ] . V_120 + V_9 [ V_79 ] . V_121 ) >
V_12 -> V_8 -> V_116 ) ) {
V_109 = V_79 ;
V_102 -= V_9 [ V_79 ] . V_120 ;
break;
}
}
V_99 = 1 ;
V_100 = 0 ;
for ( V_79 = 0 ; V_79 < V_12 -> V_8 -> V_112 ; V_79 ++ ) {
if ( ! ( V_9 [ V_79 ] . V_117 & V_118 ) )
continue;
V_98 = V_9 [ V_79 ] . V_122 ;
if ( V_9 [ V_79 ] . V_113 != V_114 ) {
if ( V_52 . V_57 < V_98 )
V_52 . V_57 = V_98 ;
V_52 . V_75 = F_31 ( V_52 . V_75 , V_98 ) ;
V_52 . V_75 += V_9 [ V_79 ] . V_121 ;
} else {
if ( V_99 < V_98 )
V_99 = V_98 ;
V_100 = F_31 ( V_100 , V_98 ) ;
V_100 += V_9 [ V_79 ] . V_121 ;
}
}
V_101 = 0 ;
if ( V_52 . V_75 & ( V_99 - 1 ) )
V_101 = V_99 - ( V_52 . V_75 & ( V_99 - 1 ) ) ;
V_52 . V_56 = V_52 . V_75 + V_101 + V_100 ;
V_52 . V_74 = F_48 ( V_52 . V_75 ) ;
if ( ! V_52 . V_74 ) {
V_23 = - V_37 ;
goto V_29;
}
if ( V_52 . V_57 < V_99 )
V_52 . V_57 = V_99 ;
V_23 = F_38 ( & V_52 ) ;
if ( V_23 )
goto V_29;
V_12 -> V_123 = V_52 . V_60 ;
V_107 = V_52 . V_74 ;
V_103 = V_104 = V_12 -> V_123 ;
V_105 = V_103 + V_52 . V_75 + V_101 ;
for ( V_79 = 0 ; V_79 < V_12 -> V_8 -> V_112 ; V_79 ++ ) {
if ( ! ( V_9 [ V_79 ] . V_117 & V_118 ) )
continue;
V_98 = V_9 [ V_79 ] . V_122 ;
if ( V_9 [ V_79 ] . V_113 != V_114 ) {
V_104 = F_31 ( V_104 , V_98 ) ;
V_106 = V_104 - V_103 ;
V_108 = ( char * ) V_9 [ V_79 ] . V_115 ;
memcpy ( V_107 + V_106 , V_108 , V_9 [ V_79 ] . V_121 ) ;
V_9 [ V_79 ] . V_120 = V_104 ;
V_9 [ V_79 ] . V_115 = ( unsigned long ) ( V_107 + V_106 ) ;
V_104 += V_9 [ V_79 ] . V_121 ;
} else {
V_105 = F_31 ( V_105 , V_98 ) ;
V_9 [ V_79 ] . V_120 = V_105 ;
V_105 += V_9 [ V_79 ] . V_121 ;
}
}
if ( V_109 >= 0 )
V_102 += V_9 [ V_109 ] . V_120 ;
V_2 -> V_41 = V_102 ;
V_12 -> V_9 = V_9 ;
V_12 -> V_16 = V_52 . V_74 ;
return V_23 ;
V_29:
F_10 ( V_9 ) ;
F_10 ( V_52 . V_74 ) ;
return V_23 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_79 , V_23 ;
struct V_11 * V_12 = & V_2 -> V_11 ;
T_2 * V_9 = V_12 -> V_9 ;
for ( V_79 = 0 ; V_79 < V_12 -> V_8 -> V_112 ; V_79 ++ ) {
T_2 * V_124 , * V_125 ;
if ( V_9 [ V_79 ] . V_113 != V_126 &&
V_9 [ V_79 ] . V_113 != V_127 )
continue;
if ( V_9 [ V_79 ] . V_128 >= V_12 -> V_8 -> V_112 ||
V_9 [ V_79 ] . V_129 >= V_12 -> V_8 -> V_112 )
return - V_5 ;
V_124 = & V_9 [ V_9 [ V_79 ] . V_128 ] ;
V_125 = & V_9 [ V_9 [ V_79 ] . V_129 ] ;
if ( ! ( V_124 -> V_117 & V_118 ) )
continue;
if ( V_125 -> V_129 >= V_12 -> V_8 -> V_112 )
continue;
if ( V_9 [ V_79 ] . V_113 == V_126 )
V_23 = F_6 ( V_12 -> V_8 ,
V_9 , V_79 ) ;
else if ( V_9 [ V_79 ] . V_113 == V_127 )
V_23 = F_8 ( V_12 -> V_8 ,
V_9 , V_79 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_2 , unsigned long F_27 ,
unsigned long F_30 , int V_63 ,
unsigned long * V_103 )
{
struct V_11 * V_12 = & V_2 -> V_11 ;
int V_23 ;
if ( V_130 <= 0 )
return - V_6 ;
if ( V_130 < sizeof( T_1 ) )
return - V_5 ;
V_12 -> V_8 = ( T_1 * ) V_131 ;
if ( memcmp ( V_12 -> V_8 -> V_132 , V_133 , V_134 ) != 0
|| V_12 -> V_8 -> V_135 != V_136
|| ! F_56 ( V_12 -> V_8 )
|| V_12 -> V_8 -> V_137 != sizeof( T_2 ) )
return - V_5 ;
if ( V_12 -> V_8 -> V_111 >= V_130
|| ( V_12 -> V_8 -> V_112 * sizeof( T_2 ) >
V_130 - V_12 -> V_8 -> V_111 ) )
return - V_5 ;
V_23 = F_53 ( V_2 , F_27 , F_30 , V_63 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_54 ( V_2 ) ;
if ( V_23 )
goto V_29;
* V_103 = V_12 -> V_123 ;
return 0 ;
V_29:
F_10 ( V_12 -> V_9 ) ;
V_12 -> V_9 = NULL ;
F_10 ( V_12 -> V_16 ) ;
V_12 -> V_16 = NULL ;
return V_23 ;
}
static T_7 * F_57 ( struct V_11 * V_12 ,
const char * V_138 )
{
T_7 * V_139 ;
T_2 * V_9 ;
T_1 * V_8 ;
int V_79 , V_140 ;
const char * V_141 ;
if ( ! V_12 -> V_9 || ! V_12 -> V_8 )
return NULL ;
V_9 = V_12 -> V_9 ;
V_8 = V_12 -> V_8 ;
for ( V_79 = 0 ; V_79 < V_8 -> V_112 ; V_79 ++ ) {
if ( V_9 [ V_79 ] . V_113 != V_142 )
continue;
if ( V_9 [ V_79 ] . V_129 >= V_8 -> V_112 )
continue;
V_141 = ( char * ) V_9 [ V_9 [ V_79 ] . V_129 ] . V_115 ;
V_139 = ( T_7 * ) V_9 [ V_79 ] . V_115 ;
for ( V_140 = 0 ; V_140 < V_9 [ V_79 ] . V_121 / sizeof( T_7 ) ; V_140 ++ ) {
if ( F_58 ( V_139 [ V_140 ] . V_143 ) != V_144 )
continue;
if ( strcmp ( V_141 + V_139 [ V_140 ] . V_145 , V_138 ) != 0 )
continue;
if ( V_139 [ V_140 ] . V_146 == V_147 ||
V_139 [ V_140 ] . V_146 >= V_8 -> V_112 ) {
F_16 ( L_10 ,
V_138 , V_139 [ V_140 ] . V_146 ) ;
return NULL ;
}
return & V_139 [ V_140 ] ;
}
}
return NULL ;
}
void * F_59 ( struct V_1 * V_2 , const char * V_138 )
{
struct V_11 * V_12 = & V_2 -> V_11 ;
T_7 * V_148 ;
T_2 * V_149 ;
V_148 = F_57 ( V_12 , V_138 ) ;
if ( ! V_148 )
return F_3 ( - V_6 ) ;
V_149 = & V_12 -> V_9 [ V_148 -> V_146 ] ;
return ( void * ) ( V_149 -> V_120 + V_148 -> V_150 ) ;
}
int F_52 ( struct V_1 * V_2 , const char * V_138 ,
void * V_3 , unsigned int V_25 , bool V_151 )
{
T_7 * V_148 ;
T_2 * V_9 ;
struct V_11 * V_12 = & V_2 -> V_11 ;
char * V_152 ;
V_148 = F_57 ( V_12 , V_138 ) ;
if ( ! V_148 )
return - V_6 ;
if ( V_148 -> V_153 != V_25 ) {
F_7 ( L_11 ,
V_138 , ( unsigned long ) V_148 -> V_153 , V_25 ) ;
return - V_6 ;
}
V_9 = V_12 -> V_9 ;
if ( V_9 [ V_148 -> V_146 ] . V_113 == V_114 ) {
F_7 ( L_12 , V_138 ,
V_151 ? L_13 : L_14 ) ;
return - V_6 ;
}
V_152 = ( unsigned char * ) V_9 [ V_148 -> V_146 ] . V_115 +
V_148 -> V_150 ;
if ( V_151 )
memcpy ( ( void * ) V_3 , V_152 , V_25 ) ;
else
memcpy ( ( void * ) V_152 , V_3 , V_25 ) ;
return 0 ;
}
