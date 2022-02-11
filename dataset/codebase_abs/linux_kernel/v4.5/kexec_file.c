static int F_1 ( int V_1 , void * * V_2 , unsigned long * V_3 )
{
struct V_1 V_4 = F_2 ( V_1 ) ;
int V_5 ;
struct V_6 V_7 ;
T_1 V_8 ;
T_2 V_9 = 0 ;
if ( ! V_4 . V_10 )
return - V_11 ;
V_5 = F_3 ( & V_4 . V_10 -> V_12 , & V_7 ) ;
if ( V_5 )
goto V_13;
if ( V_7 . V_14 > V_15 ) {
V_5 = - V_16 ;
goto V_13;
}
if ( V_7 . V_14 == 0 ) {
V_5 = - V_17 ;
goto V_13;
}
* V_2 = F_4 ( V_7 . V_14 ) ;
if ( ! * V_2 ) {
V_5 = - V_18 ;
goto V_13;
}
V_8 = 0 ;
while ( V_8 < V_7 . V_14 ) {
V_9 = F_5 ( V_4 . V_10 , V_8 , ( char * ) ( * V_2 ) + V_8 ,
V_7 . V_14 - V_8 ) ;
if ( V_9 < 0 ) {
F_6 ( * V_2 ) ;
V_5 = V_9 ;
goto V_13;
}
if ( V_9 == 0 )
break;
V_8 += V_9 ;
}
if ( V_8 != V_7 . V_14 ) {
V_5 = - V_11 ;
F_6 ( * V_2 ) ;
goto V_13;
}
* V_3 = V_8 ;
V_13:
F_7 ( V_4 ) ;
return V_5 ;
}
int __weak F_8 ( struct V_19 * V_20 , void * V_2 ,
unsigned long V_3 )
{
return - V_21 ;
}
void * __weak F_9 ( struct V_19 * V_20 )
{
return F_10 ( - V_21 ) ;
}
int __weak F_11 ( struct V_19 * V_20 )
{
return - V_17 ;
}
int __weak F_12 ( struct V_19 * V_20 , void * V_2 ,
unsigned long V_3 )
{
return - V_22 ;
}
int __weak
F_13 ( const T_3 * V_23 , T_4 * V_24 ,
unsigned int V_25 )
{
F_14 ( L_1 ) ;
return - V_21 ;
}
int __weak
F_15 ( const T_3 * V_23 , T_4 * V_24 ,
unsigned int V_25 )
{
F_14 ( L_2 ) ;
return - V_21 ;
}
void F_16 ( struct V_19 * V_20 )
{
struct V_26 * V_27 = & V_20 -> V_26 ;
F_6 ( V_20 -> V_28 ) ;
V_20 -> V_28 = NULL ;
F_6 ( V_20 -> V_29 ) ;
V_20 -> V_29 = NULL ;
F_17 ( V_20 -> V_30 ) ;
V_20 -> V_30 = NULL ;
F_6 ( V_27 -> V_31 ) ;
V_27 -> V_31 = NULL ;
F_6 ( V_27 -> V_24 ) ;
V_27 -> V_24 = NULL ;
F_11 ( V_20 ) ;
F_17 ( V_20 -> V_32 ) ;
V_20 -> V_32 = NULL ;
}
static int
F_18 ( struct V_19 * V_20 , int V_33 , int V_34 ,
const char T_5 * V_35 ,
unsigned long V_36 , unsigned V_37 )
{
int V_5 = 0 ;
void * V_38 ;
V_5 = F_1 ( V_33 , & V_20 -> V_28 ,
& V_20 -> V_39 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_8 ( V_20 , V_20 -> V_28 ,
V_20 -> V_39 ) ;
if ( V_5 )
goto V_13;
#ifdef F_19
V_5 = F_12 ( V_20 , V_20 -> V_28 ,
V_20 -> V_39 ) ;
if ( V_5 ) {
F_20 ( L_3 ) ;
goto V_13;
}
F_20 ( L_4 ) ;
#endif
if ( ! ( V_37 & V_40 ) ) {
V_5 = F_1 ( V_34 , & V_20 -> V_29 ,
& V_20 -> V_41 ) ;
if ( V_5 )
goto V_13;
}
if ( V_36 ) {
V_20 -> V_30 = F_21 ( V_36 , V_42 ) ;
if ( ! V_20 -> V_30 ) {
V_5 = - V_18 ;
goto V_13;
}
V_5 = F_22 ( V_20 -> V_30 , V_35 ,
V_36 ) ;
if ( V_5 ) {
V_5 = - V_43 ;
goto V_13;
}
V_20 -> V_44 = V_36 ;
if ( V_20 -> V_30 [ V_36 - 1 ] != '\0' ) {
V_5 = - V_17 ;
goto V_13;
}
}
V_38 = F_9 ( V_20 ) ;
if ( F_23 ( V_38 ) ) {
V_5 = F_24 ( V_38 ) ;
goto V_13;
}
V_20 -> V_32 = V_38 ;
V_13:
if ( V_5 )
F_16 ( V_20 ) ;
return V_5 ;
}
static int
F_25 ( struct V_19 * * V_45 , int V_33 ,
int V_34 , const char T_5 * V_35 ,
unsigned long V_36 , unsigned long V_37 )
{
int V_5 ;
struct V_19 * V_20 ;
bool V_46 = V_37 & V_47 ;
V_20 = F_26 () ;
if ( ! V_20 )
return - V_18 ;
V_20 -> V_48 = 1 ;
if ( V_46 ) {
V_20 -> V_49 = V_50 . V_51 ;
V_20 -> type = V_52 ;
}
V_5 = F_18 ( V_20 , V_33 , V_34 ,
V_35 , V_36 , V_37 ) ;
if ( V_5 )
goto V_53;
V_5 = F_27 ( V_20 ) ;
if ( V_5 )
goto V_54;
V_5 = - V_18 ;
V_20 -> V_55 = F_28 ( V_20 ,
F_29 ( V_56 ) ) ;
if ( ! V_20 -> V_55 ) {
F_14 ( L_5 ) ;
goto V_54;
}
if ( ! V_46 ) {
V_20 -> V_57 = F_28 ( V_20 , 0 ) ;
if ( ! V_20 -> V_57 ) {
F_14 ( L_6 ) ;
goto V_58;
}
}
* V_45 = V_20 ;
return 0 ;
V_58:
F_30 ( & V_20 -> V_59 ) ;
V_54:
F_16 ( V_20 ) ;
V_53:
F_17 ( V_20 ) ;
return V_5 ;
}
static int F_31 ( unsigned long V_51 , unsigned long V_60 ,
struct V_61 * V_62 )
{
struct V_19 * V_20 = V_62 -> V_20 ;
unsigned long V_63 , V_64 ;
V_64 = F_32 ( V_60 , V_62 -> V_65 ) ;
V_63 = V_64 - V_62 -> V_66 ;
do {
V_63 = V_63 & ( ~ ( V_62 -> V_67 - 1 ) ) ;
if ( V_63 < V_51 || V_63 < V_62 -> V_68 )
return 0 ;
V_64 = V_63 + V_62 -> V_66 - 1 ;
if ( F_33 ( V_20 , V_63 , V_64 ) ) {
V_63 = V_63 - V_69 ;
continue;
}
break;
} while ( 1 );
V_62 -> V_70 = V_63 ;
return 1 ;
}
static int F_34 ( unsigned long V_51 , unsigned long V_60 ,
struct V_61 * V_62 )
{
struct V_19 * V_20 = V_62 -> V_20 ;
unsigned long V_63 , V_64 ;
V_63 = F_35 ( V_51 , V_62 -> V_68 ) ;
do {
V_63 = F_36 ( V_63 , V_62 -> V_67 ) ;
V_64 = V_63 + V_62 -> V_66 - 1 ;
if ( V_64 > V_60 || V_64 > V_62 -> V_65 )
return 0 ;
if ( F_33 ( V_20 , V_63 , V_64 ) ) {
V_63 = V_63 + V_69 ;
continue;
}
break;
} while ( 1 );
V_62 -> V_70 = V_63 ;
return 1 ;
}
static int F_37 ( T_6 V_51 , T_6 V_60 , void * V_71 )
{
struct V_61 * V_62 = (struct V_61 * ) V_71 ;
unsigned long V_72 = V_60 - V_51 + 1 ;
if ( V_72 < V_62 -> V_66 )
return 0 ;
if ( V_60 < V_62 -> V_68 || V_51 > V_62 -> V_65 )
return 0 ;
if ( V_62 -> V_73 )
return F_31 ( V_51 , V_60 , V_62 ) ;
return F_34 ( V_51 , V_60 , V_62 ) ;
}
int F_38 ( struct V_19 * V_20 , char * V_74 , unsigned long V_75 ,
unsigned long V_66 , unsigned long V_67 ,
unsigned long V_68 , unsigned long V_65 ,
bool V_73 , unsigned long * V_76 )
{
struct V_77 * V_78 ;
struct V_61 V_2 , * V_62 ;
int V_5 ;
if ( ! V_20 -> V_48 )
return - V_17 ;
if ( V_20 -> V_79 >= V_80 )
return - V_17 ;
if ( ! F_39 ( & V_20 -> V_59 ) ) {
F_40 ( 1 ) ;
return - V_17 ;
}
memset ( & V_2 , 0 , sizeof( struct V_61 ) ) ;
V_62 = & V_2 ;
V_62 -> V_20 = V_20 ;
V_62 -> V_74 = V_74 ;
V_62 -> V_75 = V_75 ;
V_62 -> V_66 = F_36 ( V_66 , V_69 ) ;
V_62 -> V_67 = F_35 ( V_67 , V_69 ) ;
V_62 -> V_68 = V_68 ;
V_62 -> V_65 = V_65 ;
V_62 -> V_73 = V_73 ;
if ( V_20 -> type == V_52 )
V_5 = F_41 ( L_7 ,
V_81 | V_82 ,
V_50 . V_51 , V_50 . V_60 , V_62 ,
F_37 ) ;
else
V_5 = F_42 ( 0 , - 1 , V_62 ,
F_37 ) ;
if ( V_5 != 1 ) {
return - V_83 ;
}
V_78 = & V_20 -> V_84 [ V_20 -> V_79 ] ;
V_78 -> V_62 = V_62 -> V_74 ;
V_78 -> V_75 = V_62 -> V_75 ;
V_78 -> V_70 = V_62 -> V_70 ;
V_78 -> V_66 = V_62 -> V_66 ;
V_20 -> V_79 ++ ;
* V_76 = V_78 -> V_70 ;
return 0 ;
}
static int F_43 ( struct V_19 * V_20 )
{
struct V_85 * V_86 ;
struct V_87 * V_88 ;
int V_5 = 0 , V_89 , V_90 , V_91 , V_92 ;
T_7 V_93 , V_94 ;
char * V_95 ;
void * V_96 ;
struct V_97 * V_98 ;
struct V_26 * V_27 = & V_20 -> V_26 ;
V_96 = F_44 ( F_45 ( F_46 ( 0 ) ) << V_99 ) ;
V_91 = V_69 ;
V_86 = F_47 ( L_8 , 0 , 0 ) ;
if ( F_23 ( V_86 ) ) {
V_5 = F_24 ( V_86 ) ;
goto V_13;
}
V_93 = F_48 ( V_86 ) + sizeof( * V_88 ) ;
V_88 = F_21 ( V_93 , V_42 ) ;
if ( ! V_88 ) {
V_5 = - V_18 ;
goto V_100;
}
V_92 = V_80 * sizeof( struct V_97 ) ;
V_98 = F_49 ( V_92 ) ;
if ( ! V_98 )
goto V_101;
V_88 -> V_86 = V_86 ;
V_88 -> V_37 = 0 ;
V_5 = F_50 ( V_88 ) ;
if ( V_5 < 0 )
goto V_102;
V_95 = F_21 ( V_103 , V_42 ) ;
if ( ! V_95 ) {
V_5 = - V_18 ;
goto V_102;
}
for ( V_90 = V_89 = 0 ; V_89 < V_20 -> V_79 ; V_89 ++ ) {
struct V_77 * V_78 ;
V_78 = & V_20 -> V_84 [ V_89 ] ;
if ( V_78 -> V_62 == V_27 -> V_31 )
continue;
V_5 = F_51 ( V_88 , V_78 -> V_62 ,
V_78 -> V_75 ) ;
if ( V_5 )
break;
V_94 = V_78 -> V_66 - V_78 -> V_75 ;
while ( V_94 ) {
unsigned long V_9 = V_94 ;
if ( V_9 > V_91 )
V_9 = V_91 ;
V_5 = F_51 ( V_88 , V_96 , V_9 ) ;
if ( V_5 )
break;
V_94 -= V_9 ;
}
if ( V_5 )
break;
V_98 [ V_90 ] . V_51 = V_78 -> V_70 ;
V_98 [ V_90 ] . V_104 = V_78 -> V_66 ;
V_90 ++ ;
}
if ( ! V_5 ) {
V_5 = F_52 ( V_88 , V_95 ) ;
if ( V_5 )
goto V_105;
V_5 = F_53 ( V_20 , L_9 ,
V_98 , V_92 , 0 ) ;
if ( V_5 )
goto V_105;
V_5 = F_53 ( V_20 , L_10 ,
V_95 , V_103 , 0 ) ;
if ( V_5 )
goto V_105;
}
V_105:
F_17 ( V_95 ) ;
V_102:
F_6 ( V_98 ) ;
V_101:
F_17 ( V_88 ) ;
V_100:
F_17 ( V_86 ) ;
V_13:
return V_5 ;
}
static int F_54 ( struct V_19 * V_20 , unsigned long F_32 ,
unsigned long F_35 , int V_73 )
{
struct V_26 * V_27 = & V_20 -> V_26 ;
unsigned long V_106 , V_67 , V_107 , V_108 , V_109 , V_110 ;
unsigned long V_66 , V_111 , V_76 , V_112 , V_113 , V_114 ;
unsigned char * V_115 , * V_116 ;
int V_89 , V_5 = 0 , V_117 = - 1 ;
const T_4 * V_118 ;
T_4 * V_24 = NULL ;
void * V_31 = NULL ;
V_118 = ( void * ) V_27 -> V_23 + V_27 -> V_23 -> V_119 ;
V_24 = F_49 ( V_27 -> V_23 -> V_120 * sizeof( T_4 ) ) ;
if ( ! V_24 )
return - V_18 ;
memcpy ( V_24 , V_118 , V_27 -> V_23 -> V_120 * sizeof( T_4 ) ) ;
for ( V_89 = 0 ; V_89 < V_27 -> V_23 -> V_120 ; V_89 ++ ) {
if ( V_24 [ V_89 ] . V_121 == V_122 )
continue;
V_24 [ V_89 ] . V_123 = ( unsigned long ) V_27 -> V_23 +
V_24 [ V_89 ] . V_123 ;
}
V_111 = V_27 -> V_23 -> V_124 ;
for ( V_89 = 0 ; V_89 < V_27 -> V_23 -> V_120 ; V_89 ++ ) {
if ( ! ( V_24 [ V_89 ] . V_125 & V_126 ) )
continue;
if ( ! ( V_24 [ V_89 ] . V_125 & V_127 ) )
continue;
if ( V_24 [ V_89 ] . V_128 <= V_27 -> V_23 -> V_124 &&
( ( V_24 [ V_89 ] . V_128 + V_24 [ V_89 ] . V_129 ) >
V_27 -> V_23 -> V_124 ) ) {
V_117 = V_89 ;
V_111 -= V_24 [ V_89 ] . V_128 ;
break;
}
}
V_67 = 1 ;
V_107 = 1 ;
V_108 = 0 ;
V_109 = 0 ;
for ( V_89 = 0 ; V_89 < V_27 -> V_23 -> V_120 ; V_89 ++ ) {
if ( ! ( V_24 [ V_89 ] . V_125 & V_126 ) )
continue;
V_106 = V_24 [ V_89 ] . V_130 ;
if ( V_24 [ V_89 ] . V_121 != V_122 ) {
if ( V_67 < V_106 )
V_67 = V_106 ;
V_108 = F_36 ( V_108 , V_106 ) ;
V_108 += V_24 [ V_89 ] . V_129 ;
} else {
if ( V_107 < V_106 )
V_107 = V_106 ;
V_109 = F_36 ( V_109 , V_106 ) ;
V_109 += V_24 [ V_89 ] . V_129 ;
}
}
V_110 = 0 ;
if ( V_108 & ( V_107 - 1 ) )
V_110 = V_107 - ( V_108 & ( V_107 - 1 ) ) ;
V_66 = V_108 + V_110 + V_109 ;
V_31 = F_49 ( V_108 ) ;
if ( ! V_31 ) {
V_5 = - V_18 ;
goto V_13;
}
if ( V_67 < V_107 )
V_67 = V_107 ;
V_5 = F_38 ( V_20 , V_31 , V_108 , V_66 ,
V_67 , F_32 , F_35 , V_73 ,
& V_27 -> V_131 ) ;
if ( V_5 )
goto V_13;
V_115 = V_31 ;
V_76 = V_112 = V_27 -> V_131 ;
V_113 = V_76 + V_108 + V_110 ;
for ( V_89 = 0 ; V_89 < V_27 -> V_23 -> V_120 ; V_89 ++ ) {
if ( ! ( V_24 [ V_89 ] . V_125 & V_126 ) )
continue;
V_106 = V_24 [ V_89 ] . V_130 ;
if ( V_24 [ V_89 ] . V_121 != V_122 ) {
V_112 = F_36 ( V_112 , V_106 ) ;
V_114 = V_112 - V_76 ;
V_116 = ( char * ) V_24 [ V_89 ] . V_123 ;
memcpy ( V_115 + V_114 , V_116 , V_24 [ V_89 ] . V_129 ) ;
V_24 [ V_89 ] . V_128 = V_112 ;
V_24 [ V_89 ] . V_123 = ( unsigned long ) ( V_115 + V_114 ) ;
V_112 += V_24 [ V_89 ] . V_129 ;
} else {
V_113 = F_36 ( V_113 , V_106 ) ;
V_24 [ V_89 ] . V_128 = V_113 ;
V_113 += V_24 [ V_89 ] . V_129 ;
}
}
if ( V_117 >= 0 )
V_111 += V_24 [ V_117 ] . V_128 ;
V_20 -> V_51 = V_111 ;
V_27 -> V_24 = V_24 ;
V_27 -> V_31 = V_31 ;
return V_5 ;
V_13:
F_6 ( V_24 ) ;
F_6 ( V_31 ) ;
return V_5 ;
}
static int F_55 ( struct V_19 * V_20 )
{
int V_89 , V_5 ;
struct V_26 * V_27 = & V_20 -> V_26 ;
T_4 * V_24 = V_27 -> V_24 ;
for ( V_89 = 0 ; V_89 < V_27 -> V_23 -> V_120 ; V_89 ++ ) {
T_4 * V_132 , * V_133 ;
if ( V_24 [ V_89 ] . V_121 != V_134 &&
V_24 [ V_89 ] . V_121 != V_135 )
continue;
if ( V_24 [ V_89 ] . V_136 >= V_27 -> V_23 -> V_120 ||
V_24 [ V_89 ] . V_137 >= V_27 -> V_23 -> V_120 )
return - V_21 ;
V_132 = & V_24 [ V_24 [ V_89 ] . V_136 ] ;
V_133 = & V_24 [ V_24 [ V_89 ] . V_137 ] ;
if ( ! ( V_132 -> V_125 & V_126 ) )
continue;
if ( V_133 -> V_137 >= V_27 -> V_23 -> V_120 )
continue;
if ( V_24 [ V_89 ] . V_121 == V_134 )
V_5 = F_13 ( V_27 -> V_23 ,
V_24 , V_89 ) ;
else if ( V_24 [ V_89 ] . V_121 == V_135 )
V_5 = F_15 ( V_27 -> V_23 ,
V_24 , V_89 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
int F_56 ( struct V_19 * V_20 , unsigned long F_32 ,
unsigned long F_35 , int V_73 ,
unsigned long * V_76 )
{
struct V_26 * V_27 = & V_20 -> V_26 ;
int V_5 ;
if ( V_138 <= 0 )
return - V_17 ;
if ( V_138 < sizeof( T_3 ) )
return - V_21 ;
V_27 -> V_23 = ( T_3 * ) V_139 ;
if ( memcmp ( V_27 -> V_23 -> V_140 , V_141 , V_142 ) != 0
|| V_27 -> V_23 -> V_143 != V_144
|| ! F_57 ( V_27 -> V_23 )
|| V_27 -> V_23 -> V_145 != sizeof( T_4 ) )
return - V_21 ;
if ( V_27 -> V_23 -> V_119 >= V_138
|| ( V_27 -> V_23 -> V_120 * sizeof( T_4 ) >
V_138 - V_27 -> V_23 -> V_119 ) )
return - V_21 ;
V_5 = F_54 ( V_20 , F_32 , F_35 , V_73 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_55 ( V_20 ) ;
if ( V_5 )
goto V_13;
* V_76 = V_27 -> V_131 ;
return 0 ;
V_13:
F_6 ( V_27 -> V_24 ) ;
F_6 ( V_27 -> V_31 ) ;
return V_5 ;
}
static T_8 * F_58 ( struct V_26 * V_27 ,
const char * V_146 )
{
T_8 * V_147 ;
T_4 * V_24 ;
T_3 * V_23 ;
int V_89 , V_148 ;
const char * V_149 ;
if ( ! V_27 -> V_24 || ! V_27 -> V_23 )
return NULL ;
V_24 = V_27 -> V_24 ;
V_23 = V_27 -> V_23 ;
for ( V_89 = 0 ; V_89 < V_23 -> V_120 ; V_89 ++ ) {
if ( V_24 [ V_89 ] . V_121 != V_150 )
continue;
if ( V_24 [ V_89 ] . V_137 >= V_23 -> V_120 )
continue;
V_149 = ( char * ) V_24 [ V_24 [ V_89 ] . V_137 ] . V_123 ;
V_147 = ( T_8 * ) V_24 [ V_89 ] . V_123 ;
for ( V_148 = 0 ; V_148 < V_24 [ V_89 ] . V_129 / sizeof( T_8 ) ; V_148 ++ ) {
if ( F_59 ( V_147 [ V_148 ] . V_151 ) != V_152 )
continue;
if ( strcmp ( V_149 + V_147 [ V_148 ] . V_153 , V_146 ) != 0 )
continue;
if ( V_147 [ V_148 ] . V_154 == V_155 ||
V_147 [ V_148 ] . V_154 >= V_23 -> V_120 ) {
F_20 ( L_11 ,
V_146 , V_147 [ V_148 ] . V_154 ) ;
return NULL ;
}
return & V_147 [ V_148 ] ;
}
}
return NULL ;
}
void * F_60 ( struct V_19 * V_20 , const char * V_146 )
{
struct V_26 * V_27 = & V_20 -> V_26 ;
T_8 * V_156 ;
T_4 * V_157 ;
V_156 = F_58 ( V_27 , V_146 ) ;
if ( ! V_156 )
return F_10 ( - V_17 ) ;
V_157 = & V_27 -> V_24 [ V_156 -> V_154 ] ;
return ( void * ) ( V_157 -> V_128 + V_156 -> V_158 ) ;
}
int F_53 ( struct V_19 * V_20 , const char * V_146 ,
void * V_2 , unsigned int V_14 , bool V_159 )
{
T_8 * V_156 ;
T_4 * V_24 ;
struct V_26 * V_27 = & V_20 -> V_26 ;
char * V_160 ;
V_156 = F_58 ( V_27 , V_146 ) ;
if ( ! V_156 )
return - V_17 ;
if ( V_156 -> V_161 != V_14 ) {
F_14 ( L_12 ,
V_146 , ( unsigned long ) V_156 -> V_161 , V_14 ) ;
return - V_17 ;
}
V_24 = V_27 -> V_24 ;
if ( V_24 [ V_156 -> V_154 ] . V_121 == V_122 ) {
F_14 ( L_13 , V_146 ,
V_159 ? L_14 : L_15 ) ;
return - V_17 ;
}
V_160 = ( unsigned char * ) V_24 [ V_156 -> V_154 ] . V_123 +
V_156 -> V_158 ;
if ( V_159 )
memcpy ( ( void * ) V_2 , V_160 , V_14 ) ;
else
memcpy ( ( void * ) V_160 , V_2 , V_14 ) ;
return 0 ;
}
