static struct V_1 * F_1 ( struct V_2 * V_3 ,
const char * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_9 ;
int error ;
V_9 = F_2 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_3 = V_3 ;
error = F_3 ( & V_9 -> V_11 , V_8 , V_6 , L_1 , V_4 ) ;
if ( error ) {
F_4 ( & V_9 -> V_11 ) ;
return NULL ;
}
F_5 ( & V_9 -> V_11 , V_12 ) ;
return V_9 ;
}
static void F_6 ( struct V_1 * V_9 )
{
if ( V_9 )
F_4 ( & V_9 -> V_11 ) ;
}
static void F_7 ( struct V_5 * V_11 )
{
F_8 ( F_9 ( V_11 ) ) ;
}
static T_1 F_10 ( struct V_5 * V_11 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_2 * V_3 = F_9 ( V_11 ) -> V_3 ;
int V_16 = 0 ;
int V_17 ;
if ( strcmp ( V_14 -> V_4 , L_2 ) == 0 ) {
V_16 = sprintf ( V_15 , L_3 , V_3 -> V_18 . V_19 ) ;
} else if ( strcmp ( V_14 -> V_4 , L_4 ) == 0 ) {
V_16 = sprintf ( V_15 , L_3 , V_3 -> V_18 . V_20 ) ;
} else if ( strcmp ( V_14 -> V_4 , L_5 ) == 0 ) {
V_16 = sprintf ( V_15 , L_3 , V_3 -> V_18 . V_21 >> 1 ) ;
} else if ( strcmp ( V_14 -> V_4 , L_6 ) == 0 ) {
V_16 = sprintf ( V_15 , L_3 , V_3 -> V_18 . V_22 >> 1 ) ;
} else if ( strcmp ( V_14 -> V_4 , L_7 ) == 0 ) {
V_16 = sprintf ( V_15 , L_3 , V_3 -> V_18 . V_23 >> 1 ) ;
} else if ( strcmp ( V_14 -> V_4 , L_8 ) == 0 ) {
F_11 ( & V_3 -> V_24 ) ;
V_17 = V_3 -> V_25 ;
F_12 ( & V_3 -> V_24 ) ;
V_16 = sprintf ( V_15 , L_9 , V_17 ) ;
} else if ( strcmp ( V_14 -> V_4 , L_10 ) == 0 ) {
F_11 ( & V_3 -> V_24 ) ;
V_17 = V_3 -> V_26 ;
F_12 ( & V_3 -> V_24 ) ;
V_16 = sprintf ( V_15 , L_9 , V_17 ) ;
} else if ( strcmp ( V_14 -> V_4 , L_11 ) == 0 ) {
F_11 ( & V_3 -> V_24 ) ;
V_17 = V_3 -> V_27 ;
F_12 ( & V_3 -> V_24 ) ;
V_16 = sprintf ( V_15 , L_9 , V_17 ) ;
}
return V_16 ;
}
static void F_13 ( int * V_28 , int * V_29 )
{
if ( * V_29 > 0 ) {
* V_29 = F_14 ( * V_29 , 500 ) ;
* V_29 = F_15 ( * V_29 , 1000000 ) ;
if ( * V_28 <= 0 )
* V_28 = * V_29 - 100 ;
else {
* V_28 = F_15 ( * V_28 , * V_29 - 100 ) ;
* V_28 = F_14 ( * V_28 , 100 ) ;
}
} else {
* V_29 = - 1 ;
* V_28 = - 1 ;
}
}
static T_1 F_16 ( struct V_5 * V_11 ,
struct V_13 * V_14 ,
const char * V_15 , T_2 V_30 )
{
struct V_2 * V_3 = F_9 ( V_11 ) -> V_3 ;
int V_31 ;
if ( strcmp ( V_14 -> V_4 , L_12 ) == 0 && V_30 > 0 ) {
V_3 -> V_18 . V_19 = 0 ;
V_3 -> V_18 . V_20 = 0 ;
V_3 -> V_18 . V_21 = 0 ;
V_3 -> V_18 . V_23 = 0 ;
V_3 -> V_18 . V_22 = 0 ;
} else if ( strcmp ( V_14 -> V_4 , L_10 ) == 0
&& sscanf ( V_15 , L_13 , & V_31 ) == 1 ) {
F_11 ( & V_3 -> V_24 ) ;
V_3 -> V_26 = V_31 ;
F_13 ( & V_3 -> V_26 ,
& V_3 -> V_27 ) ;
F_12 ( & V_3 -> V_24 ) ;
} else if ( strcmp ( V_14 -> V_4 , L_11 ) == 0
&& sscanf ( V_15 , L_13 , & V_31 ) == 1 ) {
F_11 ( & V_3 -> V_24 ) ;
V_3 -> V_27 = V_31 ;
F_13 ( & V_3 -> V_26 ,
& V_3 -> V_27 ) ;
F_12 ( & V_3 -> V_24 ) ;
}
return V_30 ;
}
static void F_17 ( struct V_2 * V_3 )
{
if ( V_32 ) {
V_3 -> V_33 = F_18 ( V_32 , NULL , F_19 ( 0 , 0 ) , NULL ,
L_1 , V_3 -> V_4 ) ;
if ( F_20 ( V_3 -> V_33 ) )
V_3 -> V_33 = NULL ;
}
if ( V_3 -> V_33 ) {
V_3 -> V_34 = F_1 ( V_3 , L_14 ,
& V_3 -> V_33 -> V_11 ,
& V_35 ) ;
V_3 -> V_36 = F_1 ( V_3 , L_15 ,
& V_3 -> V_33 -> V_11 ,
& V_37 ) ;
}
}
static void F_21 ( struct V_2 * V_3 )
{
F_6 ( V_3 -> V_34 ) ;
F_6 ( V_3 -> V_36 ) ;
if ( V_32 )
F_22 ( V_3 -> V_33 ) ;
}
static void F_23 ( struct V_38 * V_39 )
{
F_8 ( V_39 ) ;
}
static T_1 F_24 ( struct V_38 * V_40 ,
struct V_41 * V_14 ,
char * V_15 )
{
int V_16 = 0 ;
int V_42 ;
F_25 ( & V_43 , V_44 ) ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ ) {
struct V_2 * V_3 = V_46 [ V_42 ] ;
if ( ! V_3 )
continue;
V_16 += sprintf ( V_15 + V_16 , L_16 ,
V_3 -> V_4 ,
F_26 ( V_3 -> V_47 ) , F_27 ( V_3 -> V_47 ) ,
F_26 ( V_3 -> V_48 -> V_49 ) ,
F_27 ( V_3 -> V_48 -> V_49 ) ) ;
}
F_28 ( & V_43 ) ;
return V_16 ;
}
static T_1 F_29 ( struct V_38 * V_40 ,
struct V_41 * V_14 ,
const char * V_50 ,
T_2 V_51 )
{
unsigned int V_52 , V_53 ;
if ( sscanf ( V_50 , L_17 , & V_52 , & V_53 ) == 2 ) {
if ( ! F_30 ( V_54 ) )
return - V_55 ;
F_31 ( F_19 ( V_52 , V_53 ) , NULL ) ;
F_32 ( V_54 ) ;
return V_51 ;
}
return - V_56 ;
}
static T_1 F_33 ( struct V_38 * V_40 ,
struct V_41 * V_14 ,
const char * V_50 ,
T_2 V_51 )
{
unsigned int V_52 , V_53 ;
if ( sscanf ( V_50 , L_17 , & V_52 , & V_53 ) == 2 ) {
F_34 ( F_19 ( V_52 , V_53 ) ) ;
return V_51 ;
}
return - V_56 ;
}
static int F_35 ( void )
{
int V_57 = 0 ;
V_32 = F_2 ( sizeof( * V_32 ) , V_10 ) ;
if ( ! V_32 )
return - V_58 ;
V_32 -> V_4 = V_59 ;
V_32 -> V_60 = V_54 ;
V_32 -> V_61 = F_23 ;
V_32 -> V_62 = V_63 ;
V_57 = F_36 ( V_32 ) ;
if ( V_57 ) {
F_8 ( V_32 ) ;
V_32 = NULL ;
F_37 ( V_59 L_18 ) ;
return V_57 ;
}
return 0 ;
}
static void F_38 ( void )
{
if ( V_32 )
F_39 ( V_32 ) ;
V_32 = NULL ;
}
static int F_40 ( struct V_64 * V_65 , void * V_9 )
{
return F_41 ( V_65 , V_9 ) ;
}
static int F_42 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
return F_43 ( V_67 , F_40 , V_66 -> V_68 ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
if ( ! V_69 )
return;
V_3 -> V_70 = NULL ;
V_3 -> V_71 = F_45 ( V_3 -> V_4 , V_69 ) ;
if ( F_20 ( V_3 -> V_71 ) ) {
V_3 -> V_71 = NULL ;
return;
}
V_3 -> V_70 = F_46 ( L_19 , V_72 ,
V_3 -> V_71 , V_3 , & V_73 ) ;
if ( F_20 ( V_3 -> V_70 ) ) {
V_3 -> V_70 = NULL ;
return;
}
}
static void F_47 ( struct V_2 * V_3 )
{
if ( ! V_69 )
return;
if ( V_3 -> V_70 )
F_48 ( V_3 -> V_70 ) ;
V_3 -> V_70 = NULL ;
if ( V_3 -> V_71 )
F_48 ( V_3 -> V_71 ) ;
V_3 -> V_71 = NULL ;
}
static void F_49 ( void )
{
V_69 = F_45 ( V_59 , NULL ) ;
if ( F_20 ( V_69 ) ) {
V_69 = NULL ;
return;
}
}
static void F_50 ( void )
{
if ( ! V_69 )
return;
F_48 ( V_69 ) ;
V_69 = NULL ;
}
static void F_51 ( struct V_2 * V_3 )
{
F_52 ( F_53 ( & V_3 -> V_74 . V_75 ) <= 0 ) ;
if ( F_54 ( & V_3 -> V_74 . V_75 ) ) {
F_55 ( V_59 L_20 ) ;
F_56 ( & V_3 -> V_76 . V_77 , 1 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
}
static void F_58 ( struct V_79 * V_79 )
{
F_8 ( V_79 -> V_80 ) ;
F_8 ( V_79 ) ;
}
static struct V_79 * F_59 ( int V_81 )
{
struct V_82 * V_83 = NULL ;
struct V_79 * V_79 ;
V_79 = F_60 ( sizeof( struct V_79 ) , V_10 ) ;
if ( ! V_79 )
goto V_84;
F_61 ( V_79 ) ;
V_83 = F_62 ( V_81 , sizeof( struct V_82 ) , V_10 ) ;
if ( ! V_83 )
goto V_85;
V_79 -> V_86 = V_81 ;
V_79 -> V_80 = V_83 ;
V_79 -> V_87 = F_58 ;
return V_79 ;
V_85:
F_8 ( V_79 ) ;
V_84:
return NULL ;
}
static struct V_88 * F_63 ( int V_89 )
{
int V_90 ;
struct V_88 * V_91 ;
V_91 = F_2 ( sizeof( struct V_88 ) , V_10 ) ;
if ( ! V_91 )
goto V_92;
V_91 -> V_89 = V_89 ;
V_91 -> V_93 = F_59 ( V_89 ) ;
if ( ! V_91 -> V_93 )
goto V_84;
for ( V_90 = 0 ; V_90 < V_89 / V_94 ; V_90 ++ ) {
V_91 -> V_95 [ V_90 ] = F_64 ( V_10 | V_96 ) ;
if ( ! V_91 -> V_95 [ V_90 ] )
goto V_97;
}
F_65 ( & V_91 -> V_24 ) ;
F_66 ( & V_91 -> V_98 ) ;
for ( V_90 = 0 ; V_90 < V_89 ; V_90 ++ ) {
struct V_79 * V_79 = F_59 ( 1 ) ;
if ( ! V_79 )
goto V_99;
V_91 -> V_100 [ V_90 ] = V_79 ;
}
return V_91 ;
V_99:
for ( V_90 = 0 ; V_90 < V_89 ; V_90 ++ ) {
struct V_79 * V_79 = V_91 -> V_100 [ V_90 ] ;
if ( V_79 )
F_67 ( V_79 ) ;
}
V_97:
for ( V_90 = 0 ; V_90 < V_89 / V_94 ; V_90 ++ )
if ( V_91 -> V_95 [ V_90 ] )
F_68 ( V_91 -> V_95 [ V_90 ] ) ;
F_67 ( V_91 -> V_93 ) ;
V_84:
F_8 ( V_91 ) ;
V_92:
return NULL ;
}
static void F_69 ( struct V_88 * V_91 )
{
int V_90 ;
for ( V_90 = 0 ; V_90 < V_91 -> V_89 ; V_90 ++ ) {
struct V_79 * V_79 = V_91 -> V_100 [ V_90 ] ;
if ( V_79 )
F_67 ( V_79 ) ;
}
for ( V_90 = 0 ; V_90 < V_91 -> V_89 / V_94 ; V_90 ++ )
F_68 ( V_91 -> V_95 [ V_90 ] ) ;
F_67 ( V_91 -> V_93 ) ;
F_8 ( V_91 ) ;
}
static void F_70 ( struct V_2 * V_3 )
{
struct V_88 * V_91 , * V_101 ;
F_52 ( ! F_71 ( & V_3 -> V_74 . V_102 ) ) ;
F_72 (pkt, next, &pd->cdrw.pkt_free_list, list) {
F_69 ( V_91 ) ;
}
F_73 ( & V_3 -> V_74 . V_103 ) ;
}
static int F_74 ( struct V_2 * V_3 , int V_104 )
{
struct V_88 * V_91 ;
F_52 ( ! F_71 ( & V_3 -> V_74 . V_103 ) ) ;
while ( V_104 > 0 ) {
V_91 = F_63 ( V_3 -> V_105 . V_106 >> 2 ) ;
if ( ! V_91 ) {
F_70 ( V_3 ) ;
return 0 ;
}
V_91 -> V_107 = V_104 ;
V_91 -> V_3 = V_3 ;
F_75 ( & V_91 -> V_108 , & V_3 -> V_74 . V_103 ) ;
V_104 -- ;
}
return 1 ;
}
static inline struct V_109 * F_76 ( struct V_109 * V_110 )
{
struct V_111 * V_16 = F_77 ( & V_110 -> V_111 ) ;
if ( ! V_16 )
return NULL ;
return F_78 ( V_16 , struct V_109 , V_111 ) ;
}
static void F_79 ( struct V_2 * V_3 , struct V_109 * V_110 )
{
F_80 ( & V_110 -> V_111 , & V_3 -> V_112 ) ;
F_81 ( V_110 , V_3 -> V_113 ) ;
V_3 -> V_25 -- ;
F_52 ( V_3 -> V_25 < 0 ) ;
}
static struct V_109 * F_82 ( struct V_2 * V_3 , T_3 V_114 )
{
struct V_111 * V_16 = V_3 -> V_112 . V_111 ;
struct V_111 * V_101 ;
struct V_109 * V_115 ;
if ( ! V_16 ) {
F_52 ( V_3 -> V_25 > 0 ) ;
return NULL ;
}
for (; ; ) {
V_115 = F_78 ( V_16 , struct V_109 , V_111 ) ;
if ( V_114 <= V_115 -> V_79 -> V_116 )
V_101 = V_16 -> V_117 ;
else
V_101 = V_16 -> V_118 ;
if ( ! V_101 )
break;
V_16 = V_101 ;
}
if ( V_114 > V_115 -> V_79 -> V_116 ) {
V_115 = F_76 ( V_115 ) ;
if ( ! V_115 )
return NULL ;
}
F_52 ( V_114 > V_115 -> V_79 -> V_116 ) ;
return V_115 ;
}
static void F_83 ( struct V_2 * V_3 , struct V_109 * V_110 )
{
struct V_111 * * V_9 = & V_3 -> V_112 . V_111 ;
struct V_111 * V_6 = NULL ;
T_3 V_114 = V_110 -> V_79 -> V_116 ;
struct V_109 * V_115 ;
while ( * V_9 ) {
V_6 = * V_9 ;
V_115 = F_78 ( V_6 , struct V_109 , V_111 ) ;
if ( V_114 < V_115 -> V_79 -> V_116 )
V_9 = & ( * V_9 ) -> V_117 ;
else
V_9 = & ( * V_9 ) -> V_118 ;
}
F_84 ( & V_110 -> V_111 , V_6 , V_9 ) ;
F_85 ( & V_110 -> V_111 , & V_3 -> V_112 ) ;
V_3 -> V_25 ++ ;
}
static int F_86 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
struct V_121 * V_122 = F_87 ( V_3 -> V_48 ) ;
struct V_123 * V_124 ;
int V_57 = 0 ;
V_124 = F_88 ( V_122 , ( V_120 -> V_125 == V_126 ) ?
V_127 : V_128 , V_129 ) ;
if ( V_120 -> V_130 ) {
if ( F_89 ( V_122 , V_124 , V_120 -> V_131 , V_120 -> V_130 , V_129 ) )
goto V_132;
}
V_124 -> V_133 = F_90 ( V_120 -> V_134 [ 0 ] ) ;
memcpy ( V_124 -> V_134 , V_120 -> V_134 , V_135 ) ;
V_124 -> V_136 = 60 * V_137 ;
V_124 -> V_138 = V_139 ;
if ( V_120 -> V_140 )
V_124 -> V_141 |= V_142 ;
F_91 ( V_124 -> V_122 , V_3 -> V_48 -> V_143 , V_124 , 0 ) ;
if ( V_124 -> V_144 )
V_57 = - V_145 ;
V_132:
F_92 ( V_124 ) ;
return V_57 ;
}
static void F_93 ( struct V_119 * V_120 )
{
static char * V_146 [ 9 ] = { L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 ,
L_27 , L_28 , L_29 } ;
int V_90 ;
struct V_147 * V_148 = V_120 -> V_148 ;
F_37 ( V_59 L_30 ) ;
for ( V_90 = 0 ; V_90 < V_135 ; V_90 ++ )
F_37 ( L_31 , V_120 -> V_134 [ V_90 ] ) ;
F_37 ( L_32 ) ;
if ( V_148 == NULL ) {
F_37 ( L_33 ) ;
return;
}
F_37 ( L_34 , V_148 -> V_149 , V_148 -> V_150 , V_148 -> V_151 ) ;
if ( V_148 -> V_149 > 8 ) {
F_37 ( L_35 ) ;
return;
}
F_37 ( L_36 , V_146 [ V_148 -> V_149 ] ) ;
}
static int F_94 ( struct V_2 * V_3 )
{
struct V_119 V_120 ;
F_95 ( & V_120 , NULL , 0 , V_152 ) ;
V_120 . V_134 [ 0 ] = V_153 ;
V_120 . V_140 = 1 ;
#if 0
cgc.cmd[1] = 1 << 1;
#endif
return F_86 ( V_3 , & V_120 ) ;
}
static T_4 int F_96 ( struct V_2 * V_3 ,
unsigned V_154 , unsigned V_155 )
{
struct V_119 V_120 ;
struct V_147 V_148 ;
int V_57 ;
F_95 ( & V_120 , NULL , 0 , V_152 ) ;
V_120 . V_148 = & V_148 ;
V_120 . V_134 [ 0 ] = V_156 ;
V_120 . V_134 [ 2 ] = ( V_155 >> 8 ) & 0xff ;
V_120 . V_134 [ 3 ] = V_155 & 0xff ;
V_120 . V_134 [ 4 ] = ( V_154 >> 8 ) & 0xff ;
V_120 . V_134 [ 5 ] = V_154 & 0xff ;
if ( ( V_57 = F_86 ( V_3 , & V_120 ) ) )
F_93 ( & V_120 ) ;
return V_57 ;
}
static void F_97 ( struct V_2 * V_3 , struct V_79 * V_79 )
{
F_11 ( & V_3 -> V_76 . V_24 ) ;
if ( F_98 ( V_79 ) == V_128 )
F_99 ( & V_3 -> V_76 . V_157 , V_79 ) ;
else
F_99 ( & V_3 -> V_76 . V_158 , V_79 ) ;
F_12 ( & V_3 -> V_76 . V_24 ) ;
F_56 ( & V_3 -> V_76 . V_77 , 1 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
static void F_100 ( struct V_2 * V_3 )
{
if ( F_53 ( & V_3 -> V_76 . V_77 ) == 0 )
return;
F_56 ( & V_3 -> V_76 . V_77 , 0 ) ;
for (; ; ) {
struct V_79 * V_79 ;
int V_159 , V_160 ;
F_11 ( & V_3 -> V_76 . V_24 ) ;
V_159 = ! F_101 ( & V_3 -> V_76 . V_157 ) ;
V_160 = ! F_101 ( & V_3 -> V_76 . V_158 ) ;
F_12 ( & V_3 -> V_76 . V_24 ) ;
if ( ! V_159 && ! V_160 )
break;
if ( V_3 -> V_76 . V_161 ) {
int V_162 = 1 ;
F_11 ( & V_3 -> V_76 . V_24 ) ;
V_79 = F_102 ( & V_3 -> V_76 . V_158 ) ;
F_12 ( & V_3 -> V_76 . V_24 ) ;
if ( V_79 && ( V_79 -> V_116 == V_3 -> V_76 . V_163 ) )
V_162 = 0 ;
if ( V_162 && V_159 ) {
if ( F_53 ( & V_3 -> V_74 . V_75 ) > 0 ) {
F_55 ( V_59 L_37 ) ;
break;
}
F_94 ( V_3 ) ;
V_3 -> V_76 . V_161 = 0 ;
}
} else {
if ( ! V_159 && V_160 ) {
if ( F_53 ( & V_3 -> V_74 . V_75 ) > 0 ) {
F_55 ( V_59 L_38 ) ;
break;
}
V_3 -> V_76 . V_161 = 1 ;
}
}
F_11 ( & V_3 -> V_76 . V_24 ) ;
if ( V_3 -> V_76 . V_161 )
V_79 = F_103 ( & V_3 -> V_76 . V_158 ) ;
else
V_79 = F_103 ( & V_3 -> V_76 . V_157 ) ;
F_12 ( & V_3 -> V_76 . V_24 ) ;
if ( ! V_79 )
continue;
if ( F_98 ( V_79 ) == V_128 )
V_3 -> V_76 . V_164 += V_79 -> V_165 >> 10 ;
else {
V_3 -> V_76 . V_164 = 0 ;
V_3 -> V_76 . V_163 = V_79 -> V_116 + F_104 ( V_79 ) ;
}
if ( V_3 -> V_76 . V_164 >= V_166 ) {
if ( V_3 -> V_155 == V_3 -> V_154 ) {
V_3 -> V_155 = V_167 ;
F_96 ( V_3 , V_3 -> V_154 , V_3 -> V_155 ) ;
}
} else {
if ( V_3 -> V_155 != V_3 -> V_154 ) {
V_3 -> V_155 = V_3 -> V_154 ;
F_96 ( V_3 , V_3 -> V_154 , V_3 -> V_155 ) ;
}
}
F_105 ( & V_3 -> V_74 . V_75 ) ;
F_106 ( V_79 ) ;
}
}
static int F_107 ( struct V_2 * V_3 , struct V_121 * V_122 )
{
if ( ( V_3 -> V_105 . V_106 << 9 ) / V_168
<= F_108 ( V_122 ) ) {
F_109 ( V_169 , & V_3 -> V_170 ) ;
return 0 ;
} else if ( ( V_3 -> V_105 . V_106 << 9 ) / V_171
<= F_108 ( V_122 ) ) {
F_110 ( V_169 , & V_3 -> V_170 ) ;
return 0 ;
} else {
F_37 ( V_59 L_39 ) ;
return - V_145 ;
}
}
static void F_111 ( struct V_79 * V_172 , int V_173 , int V_174 , struct V_175 * V_176 , int V_177 )
{
unsigned int V_178 = V_168 ;
while ( V_178 > 0 ) {
struct V_82 * V_179 = F_112 ( V_172 , V_173 ) ;
void * V_180 = F_113 ( V_179 -> V_181 , V_182 ) +
V_179 -> V_183 + V_174 ;
void * V_184 = F_114 ( V_176 ) + V_177 ;
int V_30 = F_115 ( int , V_178 , V_179 -> V_185 - V_174 ) ;
F_52 ( V_30 < 0 ) ;
memcpy ( V_184 , V_180 , V_30 ) ;
F_116 ( V_180 , V_182 ) ;
V_173 ++ ;
V_174 = 0 ;
V_177 += V_30 ;
V_178 -= V_30 ;
}
}
static void F_117 ( struct V_88 * V_91 , struct V_82 * V_186 )
{
int V_187 , V_9 , V_174 ;
V_9 = 0 ;
V_174 = 0 ;
for ( V_187 = 0 ; V_187 < V_91 -> V_89 ; V_187 ++ ) {
if ( V_186 [ V_187 ] . V_181 != V_91 -> V_95 [ V_9 ] ) {
void * V_180 = F_113 ( V_186 [ V_187 ] . V_181 , V_182 ) + V_186 [ V_187 ] . V_183 ;
void * V_184 = F_114 ( V_91 -> V_95 [ V_9 ] ) + V_174 ;
memcpy ( V_184 , V_180 , V_168 ) ;
F_116 ( V_180 , V_182 ) ;
V_186 [ V_187 ] . V_181 = V_91 -> V_95 [ V_9 ] ;
V_186 [ V_187 ] . V_183 = V_174 ;
} else {
F_52 ( V_186 [ V_187 ] . V_183 != V_174 ) ;
}
V_174 += V_168 ;
if ( V_174 >= V_171 ) {
V_174 = 0 ;
V_9 ++ ;
}
}
}
static void F_118 ( struct V_79 * V_79 , int V_188 )
{
struct V_88 * V_91 = V_79 -> V_189 ;
struct V_2 * V_3 = V_91 -> V_3 ;
F_52 ( ! V_3 ) ;
F_55 ( L_40 , V_79 ,
( unsigned long long ) V_91 -> V_190 , ( unsigned long long ) V_79 -> V_116 , V_188 ) ;
if ( V_188 )
F_105 ( & V_91 -> V_191 ) ;
if ( F_54 ( & V_91 -> V_192 ) ) {
F_105 ( & V_91 -> V_193 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
F_51 ( V_3 ) ;
}
static void F_119 ( struct V_79 * V_79 , int V_188 )
{
struct V_88 * V_91 = V_79 -> V_189 ;
struct V_2 * V_3 = V_91 -> V_3 ;
F_52 ( ! V_3 ) ;
F_55 ( L_41 , V_91 -> V_107 , V_188 ) ;
V_3 -> V_18 . V_20 ++ ;
F_51 ( V_3 ) ;
F_120 ( & V_91 -> V_192 ) ;
F_105 ( & V_91 -> V_193 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
static void F_121 ( struct V_2 * V_3 , struct V_88 * V_91 )
{
int V_194 = 0 ;
struct V_79 * V_79 ;
int V_187 ;
char V_195 [ V_196 ] ;
F_52 ( F_101 ( & V_91 -> V_98 ) ) ;
F_56 ( & V_91 -> V_192 , 0 ) ;
F_56 ( & V_91 -> V_191 , 0 ) ;
memset ( V_195 , 0 , sizeof( V_195 ) ) ;
F_11 ( & V_91 -> V_24 ) ;
F_122 (bio, &pkt->orig_bios) {
int V_197 = ( V_79 -> V_116 - V_91 -> V_190 ) / ( V_168 >> 9 ) ;
int V_198 = V_79 -> V_165 / V_168 ;
V_3 -> V_18 . V_21 += V_198 * ( V_168 >> 9 ) ;
F_52 ( V_197 < 0 ) ;
F_52 ( V_197 + V_198 > V_91 -> V_89 ) ;
for ( V_187 = V_197 ; V_187 < V_197 + V_198 ; V_187 ++ )
V_195 [ V_187 ] = 1 ;
}
F_12 ( & V_91 -> V_24 ) ;
if ( V_91 -> V_199 ) {
F_55 ( L_42 ,
( unsigned long long ) V_91 -> V_190 ) ;
goto V_200;
}
for ( V_187 = 0 ; V_187 < V_91 -> V_89 ; V_187 ++ ) {
struct V_82 * V_201 ;
int V_9 , V_202 ;
if ( V_195 [ V_187 ] )
continue;
V_79 = V_91 -> V_100 [ V_187 ] ;
V_201 = V_79 -> V_80 ;
F_61 ( V_79 ) ;
V_79 -> V_86 = 1 ;
V_79 -> V_116 = V_91 -> V_190 + V_187 * ( V_168 >> 9 ) ;
V_79 -> V_203 = V_3 -> V_48 ;
V_79 -> V_204 = F_118 ;
V_79 -> V_189 = V_91 ;
V_79 -> V_80 = V_201 ;
V_79 -> V_87 = F_58 ;
V_9 = ( V_187 * V_168 ) / V_171 ;
V_202 = ( V_187 * V_168 ) % V_171 ;
F_55 ( L_43 ,
V_187 , V_91 -> V_95 [ V_9 ] , V_202 ) ;
if ( ! F_123 ( V_79 , V_91 -> V_95 [ V_9 ] , V_168 , V_202 ) )
F_124 () ;
F_105 ( & V_91 -> V_192 ) ;
V_79 -> V_205 = V_128 ;
F_97 ( V_3 , V_79 ) ;
V_194 ++ ;
}
V_200:
F_55 ( L_44 ,
V_194 , ( unsigned long long ) V_91 -> V_190 ) ;
V_3 -> V_18 . V_19 ++ ;
V_3 -> V_18 . V_23 += V_194 * ( V_168 >> 9 ) ;
}
static struct V_88 * F_125 ( struct V_2 * V_3 , int V_206 )
{
struct V_88 * V_91 ;
F_126 (pkt, &pd->cdrw.pkt_free_list, list) {
if ( V_91 -> V_190 == V_206 || V_91 -> V_108 . V_101 == & V_3 -> V_74 . V_103 ) {
F_127 ( & V_91 -> V_108 ) ;
if ( V_91 -> V_190 != V_206 )
V_91 -> V_199 = 0 ;
return V_91 ;
}
}
F_124 () ;
return NULL ;
}
static void F_128 ( struct V_2 * V_3 , struct V_88 * V_91 )
{
if ( V_91 -> V_199 ) {
F_75 ( & V_91 -> V_108 , & V_3 -> V_74 . V_103 ) ;
} else {
F_129 ( & V_91 -> V_108 , & V_3 -> V_74 . V_103 ) ;
}
}
static int F_130 ( struct V_88 * V_91 )
{
return 0 ;
#if 0
struct request *rq = pkt->rq;
struct pktcdvd_device *pd = rq->rq_disk->private_data;
struct block_device *pkt_bdev;
struct super_block *sb = NULL;
unsigned long old_block, new_block;
sector_t new_sector;
pkt_bdev = bdget(kdev_t_to_nr(pd->pkt_dev));
if (pkt_bdev) {
sb = get_super(pkt_bdev);
bdput(pkt_bdev);
}
if (!sb)
return 0;
if (!sb->s_op->relocate_blocks)
goto out;
old_block = pkt->sector / (CD_FRAMESIZE >> 9);
if (sb->s_op->relocate_blocks(sb, old_block, &new_block))
goto out;
new_sector = new_block * (CD_FRAMESIZE >> 9);
pkt->sector = new_sector;
pkt->bio->bi_sector = new_sector;
pkt->bio->bi_next = NULL;
pkt->bio->bi_flags = 1 << BIO_UPTODATE;
pkt->bio->bi_idx = 0;
BUG_ON(pkt->bio->bi_rw != REQ_WRITE);
BUG_ON(pkt->bio->bi_vcnt != pkt->frames);
BUG_ON(pkt->bio->bi_size != pkt->frames * CD_FRAMESIZE);
BUG_ON(pkt->bio->bi_end_io != pkt_end_io_packet_write);
BUG_ON(pkt->bio->bi_private != pkt);
drop_super(sb);
return 1;
out:
drop_super(sb);
return 0;
#endif
}
static inline void F_131 ( struct V_88 * V_91 , enum V_207 V_208 )
{
#if V_209 > 1
static const char * V_210 [] = {
L_45 , L_46 , L_47 , L_48 , L_49 , L_50
} ;
enum V_207 V_211 = V_91 -> V_208 ;
F_55 ( L_51 , V_91 -> V_107 , ( unsigned long long ) V_91 -> V_190 ,
V_210 [ V_211 ] , V_210 [ V_208 ] ) ;
#endif
V_91 -> V_208 = V_208 ;
}
static int F_132 ( struct V_2 * V_3 )
{
struct V_88 * V_91 , * V_9 ;
struct V_79 * V_79 = NULL ;
T_3 V_206 = 0 ;
struct V_109 * V_110 , * V_212 ;
struct V_111 * V_16 ;
int V_213 ;
F_55 ( L_52 ) ;
F_56 ( & V_3 -> V_214 , 0 ) ;
if ( F_71 ( & V_3 -> V_74 . V_103 ) ) {
F_55 ( L_53 ) ;
return 0 ;
}
F_11 ( & V_3 -> V_24 ) ;
V_212 = F_82 ( V_3 , V_3 -> V_215 ) ;
if ( ! V_212 ) {
V_16 = F_133 ( & V_3 -> V_112 ) ;
if ( V_16 )
V_212 = F_78 ( V_16 , struct V_109 , V_111 ) ;
}
V_110 = V_212 ;
while ( V_110 ) {
V_79 = V_110 -> V_79 ;
V_206 = F_134 ( V_79 -> V_116 , V_3 ) ;
F_126 (p, &pd->cdrw.pkt_active_list, list) {
if ( V_9 -> V_190 == V_206 ) {
V_79 = NULL ;
goto V_216;
}
}
break;
V_216:
V_110 = F_76 ( V_110 ) ;
if ( ! V_110 ) {
V_16 = F_133 ( & V_3 -> V_112 ) ;
if ( V_16 )
V_110 = F_78 ( V_16 , struct V_109 , V_111 ) ;
}
if ( V_110 == V_212 )
V_110 = NULL ;
}
F_12 ( & V_3 -> V_24 ) ;
if ( ! V_79 ) {
F_55 ( L_54 ) ;
return 0 ;
}
V_91 = F_125 ( V_3 , V_206 ) ;
V_3 -> V_215 = V_206 + V_3 -> V_105 . V_106 ;
V_91 -> V_190 = V_206 ;
F_52 ( V_91 -> V_89 != V_3 -> V_105 . V_106 >> 2 ) ;
V_91 -> V_217 = 0 ;
F_11 ( & V_3 -> V_24 ) ;
F_55 ( L_55 , ( unsigned long long ) V_206 ) ;
while ( ( V_110 = F_82 ( V_3 , V_206 ) ) != NULL ) {
V_79 = V_110 -> V_79 ;
F_55 ( L_56 ,
( unsigned long long ) F_134 ( V_79 -> V_116 , V_3 ) ) ;
if ( F_134 ( V_79 -> V_116 , V_3 ) != V_206 )
break;
F_79 ( V_3 , V_110 ) ;
F_11 ( & V_91 -> V_24 ) ;
F_99 ( & V_91 -> V_98 , V_79 ) ;
V_91 -> V_217 += V_79 -> V_165 / V_168 ;
F_12 ( & V_91 -> V_24 ) ;
}
V_213 = ( V_3 -> V_27 > 0
&& V_3 -> V_25 <= V_3 -> V_26 ) ;
F_12 ( & V_3 -> V_24 ) ;
if ( V_213 ) {
F_135 ( & V_3 -> V_218 -> V_219 -> V_220 ,
V_221 ) ;
}
V_91 -> V_222 = F_14 ( V_223 , 1 ) ;
F_131 ( V_91 , V_224 ) ;
F_56 ( & V_91 -> V_193 , 1 ) ;
F_11 ( & V_3 -> V_74 . V_225 ) ;
F_75 ( & V_91 -> V_108 , & V_3 -> V_74 . V_102 ) ;
F_12 ( & V_3 -> V_74 . V_225 ) ;
return 1 ;
}
static void F_136 ( struct V_2 * V_3 , struct V_88 * V_91 )
{
struct V_79 * V_79 ;
int V_187 ;
int V_226 ;
struct V_82 * V_186 = V_91 -> V_93 -> V_80 ;
for ( V_187 = 0 ; V_187 < V_91 -> V_89 ; V_187 ++ ) {
V_186 [ V_187 ] . V_181 = V_91 -> V_95 [ ( V_187 * V_168 ) / V_171 ] ;
V_186 [ V_187 ] . V_183 = ( V_187 * V_168 ) % V_171 ;
}
V_226 = 0 ;
F_11 ( & V_91 -> V_24 ) ;
F_122 (bio, &pkt->orig_bios) {
int V_227 = V_79 -> V_228 ;
int V_229 = 0 ;
int V_197 = ( V_79 -> V_116 - V_91 -> V_190 ) / ( V_168 >> 9 ) ;
int V_198 = V_79 -> V_165 / V_168 ;
F_52 ( V_197 < 0 ) ;
F_52 ( V_197 + V_198 > V_91 -> V_89 ) ;
for ( V_187 = V_197 ; V_187 < V_197 + V_198 ; V_187 ++ ) {
struct V_82 * V_179 = F_112 ( V_79 , V_227 ) ;
while ( V_229 >= V_179 -> V_185 ) {
V_229 -= V_179 -> V_185 ;
V_227 ++ ;
F_52 ( V_227 >= V_79 -> V_230 ) ;
V_179 = F_112 ( V_79 , V_227 ) ;
}
if ( V_179 -> V_185 - V_229 >= V_168 ) {
V_186 [ V_187 ] . V_181 = V_179 -> V_181 ;
V_186 [ V_187 ] . V_183 = V_179 -> V_183 + V_229 ;
} else {
F_111 ( V_79 , V_227 , V_229 ,
V_186 [ V_187 ] . V_181 , V_186 [ V_187 ] . V_183 ) ;
}
V_229 += V_168 ;
V_226 ++ ;
}
}
F_131 ( V_91 , V_231 ) ;
F_12 ( & V_91 -> V_24 ) ;
F_55 ( L_57 ,
V_226 , ( unsigned long long ) V_91 -> V_190 ) ;
F_52 ( V_226 != V_91 -> V_217 ) ;
if ( F_137 ( V_169 , & V_3 -> V_170 ) || ( V_91 -> V_217 < V_91 -> V_89 ) ) {
F_117 ( V_91 , V_186 ) ;
V_91 -> V_199 = 1 ;
} else {
V_91 -> V_199 = 0 ;
}
F_61 ( V_91 -> V_93 ) ;
V_91 -> V_93 -> V_86 = V_196 ;
V_91 -> V_93 -> V_116 = V_91 -> V_190 ;
V_91 -> V_93 -> V_203 = V_3 -> V_48 ;
V_91 -> V_93 -> V_204 = F_119 ;
V_91 -> V_93 -> V_189 = V_91 ;
V_91 -> V_93 -> V_80 = V_186 ;
V_91 -> V_93 -> V_87 = F_58 ;
for ( V_187 = 0 ; V_187 < V_91 -> V_89 ; V_187 ++ )
if ( ! F_123 ( V_91 -> V_93 , V_186 [ V_187 ] . V_181 , V_168 , V_186 [ V_187 ] . V_183 ) )
F_124 () ;
F_55 ( V_59 L_58 , V_91 -> V_93 -> V_230 ) ;
F_56 ( & V_91 -> V_192 , 1 ) ;
V_91 -> V_93 -> V_205 = V_127 ;
F_97 ( V_3 , V_91 -> V_93 ) ;
}
static void F_138 ( struct V_88 * V_91 , int V_232 )
{
struct V_79 * V_79 ;
if ( ! V_232 )
V_91 -> V_199 = 0 ;
while ( ( V_79 = F_103 ( & V_91 -> V_98 ) ) )
F_139 ( V_79 , V_232 ? 0 : - V_145 ) ;
}
static void F_140 ( struct V_2 * V_3 , struct V_88 * V_91 )
{
int V_232 ;
F_55 ( L_59 , V_91 -> V_107 ) ;
for (; ; ) {
switch ( V_91 -> V_208 ) {
case V_224 :
if ( ( V_91 -> V_217 < V_91 -> V_89 ) && ( V_91 -> V_222 > 0 ) )
return;
V_91 -> V_222 = 0 ;
F_121 ( V_3 , V_91 ) ;
F_131 ( V_91 , V_233 ) ;
break;
case V_233 :
if ( F_53 ( & V_91 -> V_192 ) > 0 )
return;
if ( F_53 ( & V_91 -> V_191 ) > 0 ) {
F_131 ( V_91 , V_234 ) ;
} else {
F_136 ( V_3 , V_91 ) ;
}
break;
case V_231 :
if ( F_53 ( & V_91 -> V_192 ) > 0 )
return;
if ( F_137 ( V_235 , & V_91 -> V_93 -> V_236 ) ) {
F_131 ( V_91 , V_237 ) ;
} else {
F_131 ( V_91 , V_234 ) ;
}
break;
case V_234 :
if ( F_130 ( V_91 ) ) {
F_136 ( V_3 , V_91 ) ;
} else {
F_55 ( L_60 ) ;
F_131 ( V_91 , V_237 ) ;
}
break;
case V_237 :
V_232 = F_137 ( V_235 , & V_91 -> V_93 -> V_236 ) ;
F_138 ( V_91 , V_232 ) ;
return;
default:
F_124 () ;
break;
}
}
}
static void F_141 ( struct V_2 * V_3 )
{
struct V_88 * V_91 , * V_101 ;
F_55 ( L_61 ) ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_53 ( & V_91 -> V_193 ) > 0 ) {
F_56 ( & V_91 -> V_193 , 0 ) ;
F_140 ( V_3 , V_91 ) ;
}
}
F_11 ( & V_3 -> V_74 . V_225 ) ;
F_72 (pkt, next, &pd->cdrw.pkt_active_list, list) {
if ( V_91 -> V_208 == V_237 ) {
F_142 ( & V_91 -> V_108 ) ;
F_128 ( V_3 , V_91 ) ;
F_131 ( V_91 , V_238 ) ;
F_56 ( & V_3 -> V_214 , 1 ) ;
}
}
F_12 ( & V_3 -> V_74 . V_225 ) ;
}
static void F_143 ( struct V_2 * V_3 , int * V_239 )
{
struct V_88 * V_91 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_240 ; V_90 ++ )
V_239 [ V_90 ] = 0 ;
F_11 ( & V_3 -> V_74 . V_225 ) ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
V_239 [ V_91 -> V_208 ] ++ ;
}
F_12 ( & V_3 -> V_74 . V_225 ) ;
}
static int F_144 ( void * V_241 )
{
struct V_2 * V_3 = V_241 ;
struct V_88 * V_91 ;
long V_242 , V_243 ;
F_145 ( V_244 , - 20 ) ;
F_146 () ;
for (; ; ) {
F_147 ( V_245 , V_244 ) ;
F_148 ( & V_3 -> V_78 , & V_245 ) ;
for (; ; ) {
F_149 ( V_246 ) ;
if ( F_53 ( & V_3 -> V_214 ) > 0 )
goto V_247;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_53 ( & V_91 -> V_193 ) > 0 )
goto V_247;
}
if ( F_53 ( & V_3 -> V_76 . V_77 ) != 0 )
goto V_247;
if ( V_209 > 1 ) {
int V_239 [ V_240 ] ;
F_143 ( V_3 , V_239 ) ;
F_55 ( L_62 ,
V_239 [ 0 ] , V_239 [ 1 ] , V_239 [ 2 ] , V_239 [ 3 ] ,
V_239 [ 4 ] , V_239 [ 5 ] ) ;
}
V_242 = V_248 ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_91 -> V_222 && V_91 -> V_222 < V_242 )
V_242 = V_91 -> V_222 ;
}
F_55 ( L_63 ) ;
V_243 = F_150 ( V_242 ) ;
F_55 ( L_64 ) ;
F_151 () ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( ! V_91 -> V_222 )
continue;
V_91 -> V_222 -= V_242 - V_243 ;
if ( V_91 -> V_222 <= 0 ) {
V_91 -> V_222 = 0 ;
F_105 ( & V_91 -> V_193 ) ;
}
}
if ( F_152 () )
break;
}
V_247:
F_149 ( V_249 ) ;
F_153 ( & V_3 -> V_78 , & V_245 ) ;
if ( F_152 () )
break;
while ( F_132 ( V_3 ) )
;
F_141 ( V_3 ) ;
F_100 ( V_3 ) ;
}
return 0 ;
}
static void F_154 ( struct V_2 * V_3 )
{
F_37 ( V_59 L_65 , V_3 -> V_105 . V_250 ? L_66 : L_67 ) ;
F_37 ( L_68 , V_3 -> V_105 . V_106 >> 2 ) ;
F_37 ( L_69 , V_3 -> V_105 . V_251 == 8 ? '1' : '2' ) ;
}
static int F_155 ( struct V_2 * V_3 , struct V_119 * V_120 , int V_252 , int V_253 )
{
memset ( V_120 -> V_134 , 0 , sizeof( V_120 -> V_134 ) ) ;
V_120 -> V_134 [ 0 ] = V_254 ;
V_120 -> V_134 [ 2 ] = V_252 | ( V_253 << 6 ) ;
V_120 -> V_134 [ 7 ] = V_120 -> V_130 >> 8 ;
V_120 -> V_134 [ 8 ] = V_120 -> V_130 & 0xff ;
V_120 -> V_125 = V_255 ;
return F_86 ( V_3 , V_120 ) ;
}
static int F_156 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
memset ( V_120 -> V_134 , 0 , sizeof( V_120 -> V_134 ) ) ;
memset ( V_120 -> V_131 , 0 , 2 ) ;
V_120 -> V_134 [ 0 ] = V_256 ;
V_120 -> V_134 [ 1 ] = 0x10 ;
V_120 -> V_134 [ 7 ] = V_120 -> V_130 >> 8 ;
V_120 -> V_134 [ 8 ] = V_120 -> V_130 & 0xff ;
V_120 -> V_125 = V_126 ;
return F_86 ( V_3 , V_120 ) ;
}
static int F_157 ( struct V_2 * V_3 , T_5 * V_257 )
{
struct V_119 V_120 ;
int V_57 ;
F_95 ( & V_120 , V_257 , sizeof( * V_257 ) , V_255 ) ;
V_120 . V_134 [ 0 ] = V_258 ;
V_120 . V_134 [ 8 ] = V_120 . V_130 = 2 ;
V_120 . V_140 = 1 ;
if ( ( V_57 = F_86 ( V_3 , & V_120 ) ) )
return V_57 ;
V_120 . V_130 = F_158 ( V_257 -> V_259 ) +
sizeof( V_257 -> V_259 ) ;
if ( V_120 . V_130 > sizeof( T_5 ) )
V_120 . V_130 = sizeof( T_5 ) ;
V_120 . V_134 [ 8 ] = V_120 . V_130 ;
return F_86 ( V_3 , & V_120 ) ;
}
static int F_159 ( struct V_2 * V_3 , T_6 V_260 , T_7 type , T_8 * V_261 )
{
struct V_119 V_120 ;
int V_57 ;
F_95 ( & V_120 , V_261 , 8 , V_255 ) ;
V_120 . V_134 [ 0 ] = V_262 ;
V_120 . V_134 [ 1 ] = type & 3 ;
V_120 . V_134 [ 4 ] = ( V_260 & 0xff00 ) >> 8 ;
V_120 . V_134 [ 5 ] = V_260 & 0xff ;
V_120 . V_134 [ 8 ] = 8 ;
V_120 . V_140 = 1 ;
if ( ( V_57 = F_86 ( V_3 , & V_120 ) ) )
return V_57 ;
V_120 . V_130 = F_158 ( V_261 -> V_263 ) +
sizeof( V_261 -> V_263 ) ;
if ( V_120 . V_130 > sizeof( T_8 ) )
V_120 . V_130 = sizeof( T_8 ) ;
V_120 . V_134 [ 8 ] = V_120 . V_130 ;
return F_86 ( V_3 , & V_120 ) ;
}
static T_4 int F_160 ( struct V_2 * V_3 ,
long * V_264 )
{
T_5 V_257 ;
T_8 V_261 ;
T_9 V_265 ;
int V_57 = - 1 ;
if ( ( V_57 = F_157 ( V_3 , & V_257 ) ) )
return V_57 ;
V_265 = ( V_257 . V_266 << 8 ) | V_257 . V_267 ;
if ( ( V_57 = F_159 ( V_3 , V_265 , 1 , & V_261 ) ) )
return V_57 ;
if ( V_261 . V_268 ) {
V_265 -- ;
if ( ( V_57 = F_159 ( V_3 , V_265 , 1 , & V_261 ) ) )
return V_57 ;
}
if ( V_261 . V_269 ) {
* V_264 = F_161 ( V_261 . V_270 ) ;
} else {
* V_264 = F_161 ( V_261 . V_271 ) +
F_161 ( V_261 . V_272 ) ;
if ( V_261 . V_273 )
* V_264 -= ( F_161 ( V_261 . V_273 ) + 7 ) ;
}
return 0 ;
}
static T_4 int F_162 ( struct V_2 * V_3 )
{
struct V_119 V_120 ;
struct V_147 V_148 ;
T_10 * V_274 ;
char V_131 [ 128 ] ;
int V_57 , V_106 ;
if ( ( V_3 -> V_275 == 0x1a ) || ( V_3 -> V_275 == 0x12 ) )
return 0 ;
memset ( V_131 , 0 , sizeof( V_131 ) ) ;
F_95 ( & V_120 , V_131 , sizeof( * V_274 ) , V_255 ) ;
V_120 . V_148 = & V_148 ;
if ( ( V_57 = F_155 ( V_3 , & V_120 , V_276 , 0 ) ) ) {
F_93 ( & V_120 ) ;
return V_57 ;
}
V_106 = 2 + ( ( V_131 [ 0 ] << 8 ) | ( V_131 [ 1 ] & 0xff ) ) ;
V_3 -> V_277 = ( V_131 [ 6 ] << 8 ) | ( V_131 [ 7 ] & 0xff ) ;
if ( V_106 > sizeof( V_131 ) )
V_106 = sizeof( V_131 ) ;
F_95 ( & V_120 , V_131 , V_106 , V_255 ) ;
V_120 . V_148 = & V_148 ;
if ( ( V_57 = F_155 ( V_3 , & V_120 , V_276 , 0 ) ) ) {
F_93 ( & V_120 ) ;
return V_57 ;
}
V_274 = ( T_10 * ) & V_131 [ sizeof( struct V_278 ) + V_3 -> V_277 ] ;
V_274 -> V_250 = V_3 -> V_105 . V_250 ;
V_274 -> V_279 = V_3 -> V_105 . V_279 ;
V_274 -> V_280 = V_3 -> V_105 . V_280 ;
V_274 -> V_281 = V_3 -> V_105 . V_251 ;
V_274 -> V_282 = 0 ;
#ifdef F_163
V_274 -> V_283 = 7 ;
V_274 -> V_284 = 1 ;
#endif
if ( V_274 -> V_281 == V_285 ) {
V_274 -> V_286 = 0 ;
V_274 -> V_287 = 0x20 ;
} else if ( V_274 -> V_281 == V_288 ) {
V_274 -> V_286 = 0x20 ;
V_274 -> V_287 = 8 ;
#if 0
wp->mcn[0] = 0x80;
memcpy(&wp->mcn[1], PACKET_MCN, sizeof(wp->mcn) - 1);
#endif
} else {
F_37 ( V_59 L_70 , V_274 -> V_281 ) ;
return 1 ;
}
V_274 -> V_289 = F_164 ( V_3 -> V_105 . V_106 >> 2 ) ;
V_120 . V_130 = V_120 . V_134 [ 8 ] = V_106 ;
if ( ( V_57 = F_156 ( V_3 , & V_120 ) ) ) {
F_93 ( & V_120 ) ;
return V_57 ;
}
F_154 ( V_3 ) ;
return 0 ;
}
static int F_165 ( struct V_2 * V_3 , T_8 * V_261 )
{
switch ( V_3 -> V_275 ) {
case 0x1a :
case 0x12 :
return 1 ;
default:
break;
}
if ( ! V_261 -> V_290 || ! V_261 -> V_250 )
return 0 ;
if ( V_261 -> V_291 == 0 && V_261 -> V_268 == 0 )
return 1 ;
if ( V_261 -> V_291 == 0 && V_261 -> V_268 == 1 )
return 1 ;
if ( V_261 -> V_291 == 1 && V_261 -> V_268 == 0 )
return 1 ;
F_37 ( V_59 L_71 , V_261 -> V_291 , V_261 -> V_268 , V_261 -> V_290 ) ;
return 0 ;
}
static int F_166 ( struct V_2 * V_3 , T_5 * V_257 )
{
switch ( V_3 -> V_275 ) {
case 0x0a :
case 0xffff :
break;
case 0x1a :
case 0x13 :
case 0x12 :
return 1 ;
default:
F_55 ( V_59 L_72 , V_3 -> V_275 ) ;
return 0 ;
}
if ( V_257 -> V_292 == 0xff ) {
F_37 ( V_59 L_73 ) ;
return 0 ;
}
if ( V_257 -> V_292 != 0x20 && V_257 -> V_292 != 0 ) {
F_37 ( V_59 L_74 , V_257 -> V_292 ) ;
return 0 ;
}
if ( V_257 -> V_293 == 0 ) {
F_37 ( V_59 L_75 ) ;
return 0 ;
}
if ( V_257 -> V_294 == V_295 ) {
F_37 ( V_59 L_76 ) ;
return 0 ;
}
return 1 ;
}
static T_4 int F_167 ( struct V_2 * V_3 )
{
struct V_119 V_120 ;
unsigned char V_50 [ 12 ] ;
T_5 V_257 ;
T_8 V_261 ;
int V_57 , V_260 ;
F_95 ( & V_120 , V_50 , sizeof( V_50 ) , V_255 ) ;
V_120 . V_134 [ 0 ] = V_296 ;
V_120 . V_134 [ 8 ] = 8 ;
V_57 = F_86 ( V_3 , & V_120 ) ;
V_3 -> V_275 = V_57 ? 0xffff : V_50 [ 6 ] << 8 | V_50 [ 7 ] ;
memset ( & V_257 , 0 , sizeof( T_5 ) ) ;
memset ( & V_261 , 0 , sizeof( T_8 ) ) ;
if ( ( V_57 = F_157 ( V_3 , & V_257 ) ) ) {
F_37 ( L_77 ) ;
return V_57 ;
}
if ( ! F_166 ( V_3 , & V_257 ) )
return - V_297 ;
V_3 -> type = V_257 . V_293 ? V_298 : V_299 ;
V_260 = 1 ;
if ( ( V_57 = F_159 ( V_3 , V_260 , 1 , & V_261 ) ) ) {
F_37 ( V_59 L_78 ) ;
return V_57 ;
}
if ( ! F_165 ( V_3 , & V_261 ) ) {
F_37 ( V_59 L_79 ) ;
return - V_297 ;
}
V_3 -> V_105 . V_106 = F_161 ( V_261 . V_300 ) << 2 ;
if ( V_3 -> V_105 . V_106 == 0 ) {
F_37 ( V_59 L_80 ) ;
return - V_301 ;
}
if ( V_3 -> V_105 . V_106 > V_302 ) {
F_37 ( V_59 L_81 ) ;
return - V_297 ;
}
V_3 -> V_105 . V_250 = V_261 . V_250 ;
V_3 -> V_202 = ( F_161 ( V_261 . V_271 ) << 2 ) & ( V_3 -> V_105 . V_106 - 1 ) ;
if ( V_261 . V_303 ) {
V_3 -> V_304 = F_161 ( V_261 . V_305 ) ;
F_110 ( V_306 , & V_3 -> V_170 ) ;
}
if ( V_261 . V_269 ) {
V_3 -> V_307 = F_161 ( V_261 . V_270 ) ;
F_110 ( V_308 , & V_3 -> V_170 ) ;
} else {
V_3 -> V_307 = 0xffffffff ;
F_110 ( V_308 , & V_3 -> V_170 ) ;
}
V_3 -> V_105 . V_309 = 7 ;
V_3 -> V_105 . V_280 = 0 ;
V_3 -> V_105 . V_279 = V_261 . V_279 ;
switch ( V_261 . V_310 ) {
case V_311 :
V_3 -> V_105 . V_251 = V_285 ;
break;
case V_312 :
V_3 -> V_105 . V_251 = V_288 ;
break;
default:
F_37 ( V_59 L_82 ) ;
return - V_297 ;
}
return 0 ;
}
static T_4 int F_168 ( struct V_2 * V_3 ,
int V_313 )
{
struct V_119 V_120 ;
struct V_147 V_148 ;
unsigned char V_50 [ 64 ] ;
int V_57 ;
F_95 ( & V_120 , V_50 , sizeof( V_50 ) , V_255 ) ;
V_120 . V_148 = & V_148 ;
V_120 . V_130 = V_3 -> V_277 + 12 ;
V_120 . V_140 = 1 ;
if ( ( V_57 = F_155 ( V_3 , & V_120 , V_314 , 0 ) ) )
return V_57 ;
V_50 [ V_3 -> V_277 + 10 ] |= ( ! ! V_313 << 2 ) ;
V_120 . V_130 = V_120 . V_134 [ 8 ] = 2 + ( ( V_50 [ 0 ] << 8 ) | ( V_50 [ 1 ] & 0xff ) ) ;
V_57 = F_156 ( V_3 , & V_120 ) ;
if ( V_57 ) {
F_37 ( V_59 L_83 ) ;
F_93 ( & V_120 ) ;
} else if ( ! V_57 && V_313 )
F_37 ( V_59 L_84 , V_3 -> V_4 ) ;
return V_57 ;
}
static int F_169 ( struct V_2 * V_3 , int V_315 )
{
struct V_119 V_120 ;
F_95 ( & V_120 , NULL , 0 , V_152 ) ;
V_120 . V_134 [ 0 ] = V_316 ;
V_120 . V_134 [ 4 ] = V_315 ? 1 : 0 ;
return F_86 ( V_3 , & V_120 ) ;
}
static T_4 int F_170 ( struct V_2 * V_3 ,
unsigned * V_154 )
{
struct V_119 V_120 ;
struct V_147 V_148 ;
unsigned char V_50 [ 256 + 18 ] ;
unsigned char * V_317 ;
int V_57 , V_202 ;
V_317 = & V_50 [ sizeof( struct V_278 ) + V_3 -> V_277 ] ;
F_95 ( & V_120 , V_50 , sizeof( V_50 ) , V_318 ) ;
V_120 . V_148 = & V_148 ;
V_57 = F_155 ( V_3 , & V_120 , V_319 , 0 ) ;
if ( V_57 ) {
V_120 . V_130 = V_3 -> V_277 + V_317 [ 1 ] + 2 +
sizeof( struct V_278 ) ;
V_57 = F_155 ( V_3 , & V_120 , V_319 , 0 ) ;
if ( V_57 ) {
F_93 ( & V_120 ) ;
return V_57 ;
}
}
V_202 = 20 ;
if ( V_317 [ 1 ] >= 28 )
V_202 = 28 ;
if ( V_317 [ 1 ] >= 30 ) {
int V_320 = ( V_317 [ 30 ] << 8 ) + V_317 [ 31 ] ;
if ( V_320 > 0 )
V_202 = 34 ;
}
* V_154 = ( V_317 [ V_202 ] << 8 ) | V_317 [ V_202 + 1 ] ;
return 0 ;
}
static T_4 int F_171 ( struct V_2 * V_3 ,
unsigned * V_321 )
{
struct V_119 V_120 ;
struct V_147 V_148 ;
unsigned char V_50 [ 64 ] ;
unsigned int V_106 , V_322 , V_323 ;
int V_57 ;
F_95 ( & V_120 , V_50 , 2 , V_255 ) ;
V_120 . V_148 = & V_148 ;
V_120 . V_134 [ 0 ] = V_324 ;
V_120 . V_134 [ 1 ] = 2 ;
V_120 . V_134 [ 2 ] = 4 ;
V_120 . V_134 [ 8 ] = 2 ;
V_57 = F_86 ( V_3 , & V_120 ) ;
if ( V_57 ) {
F_93 ( & V_120 ) ;
return V_57 ;
}
V_106 = ( ( unsigned int ) V_50 [ 0 ] << 8 ) + V_50 [ 1 ] + 2 ;
if ( V_106 > sizeof( V_50 ) )
V_106 = sizeof( V_50 ) ;
F_95 ( & V_120 , V_50 , V_106 , V_255 ) ;
V_120 . V_148 = & V_148 ;
V_120 . V_134 [ 0 ] = V_324 ;
V_120 . V_134 [ 1 ] = 2 ;
V_120 . V_134 [ 2 ] = 4 ;
V_120 . V_134 [ 8 ] = V_106 ;
V_57 = F_86 ( V_3 , & V_120 ) ;
if ( V_57 ) {
F_93 ( & V_120 ) ;
return V_57 ;
}
if ( ! ( V_50 [ 6 ] & 0x40 ) ) {
F_37 ( V_59 L_85 ) ;
return 1 ;
}
if ( ! ( V_50 [ 6 ] & 0x4 ) ) {
F_37 ( V_59 L_86 ) ;
return 1 ;
}
V_322 = ( V_50 [ 6 ] >> 3 ) & 0x7 ;
V_323 = V_50 [ 16 ] & 0xf ;
switch ( V_322 ) {
case 0 :
* V_321 = V_325 [ V_323 ] ;
break;
case 1 :
* V_321 = V_326 [ V_323 ] ;
break;
case 2 :
* V_321 = V_327 [ V_323 ] ;
break;
default:
F_37 ( V_59 L_87 , V_322 ) ;
return 1 ;
}
if ( * V_321 ) {
F_37 ( V_59 L_88 , * V_321 ) ;
return 0 ;
} else {
F_37 ( V_59 L_89 , V_323 , V_322 ) ;
return 1 ;
}
}
static T_4 int F_172 ( struct V_2 * V_3 )
{
struct V_119 V_120 ;
struct V_147 V_148 ;
int V_57 ;
F_55 ( V_59 L_90 ) ;
F_95 ( & V_120 , NULL , 0 , V_152 ) ;
V_120 . V_148 = & V_148 ;
V_120 . V_136 = 60 * V_137 ;
V_120 . V_134 [ 0 ] = V_328 ;
V_120 . V_134 [ 1 ] = 1 ;
if ( ( V_57 = F_86 ( V_3 , & V_120 ) ) )
F_93 ( & V_120 ) ;
return V_57 ;
}
static int F_173 ( struct V_2 * V_3 )
{
int V_57 ;
unsigned int V_154 , V_329 , V_155 ;
if ( ( V_57 = F_167 ( V_3 ) ) ) {
F_55 ( V_59 L_91 , V_3 -> V_4 ) ;
return V_57 ;
}
if ( ( V_57 = F_162 ( V_3 ) ) ) {
F_174 ( V_59 L_92 , V_3 -> V_4 ) ;
return - V_145 ;
}
F_168 ( V_3 , V_330 ) ;
if ( ( V_57 = F_170 ( V_3 , & V_154 ) ) )
V_154 = 16 * 177 ;
switch ( V_3 -> V_275 ) {
case 0x13 :
case 0x1a :
case 0x12 :
F_174 ( V_59 L_93 , V_154 ) ;
break;
default:
if ( ( V_57 = F_171 ( V_3 , & V_329 ) ) )
V_329 = 16 ;
V_154 = F_15 ( V_154 , V_329 * 177 ) ;
F_174 ( V_59 L_94 , V_154 / 176 ) ;
break;
}
V_155 = V_154 ;
if ( ( V_57 = F_96 ( V_3 , V_154 , V_155 ) ) ) {
F_174 ( V_59 L_95 , V_3 -> V_4 ) ;
return - V_145 ;
}
V_3 -> V_154 = V_154 ;
V_3 -> V_155 = V_155 ;
if ( ( V_57 = F_172 ( V_3 ) ) ) {
F_174 ( V_59 L_96 , V_3 -> V_4 ) ;
}
return 0 ;
}
static int F_175 ( struct V_2 * V_3 , T_11 V_331 )
{
int V_57 ;
long V_332 ;
struct V_121 * V_122 ;
F_176 ( V_3 -> V_48 -> V_49 ) ;
if ( ( V_57 = F_177 ( V_3 -> V_48 , V_333 | V_334 , V_3 ) ) )
goto V_132;
if ( ( V_57 = F_160 ( V_3 , & V_332 ) ) ) {
F_37 ( V_59 L_97 ) ;
goto V_335;
}
F_178 ( V_3 -> V_218 , V_332 << 2 ) ;
F_178 ( V_3 -> V_48 -> V_143 , V_332 << 2 ) ;
F_179 ( V_3 -> V_48 , ( V_336 ) V_332 << 11 ) ;
V_122 = F_87 ( V_3 -> V_48 ) ;
if ( V_331 ) {
if ( ( V_57 = F_173 ( V_3 ) ) )
goto V_335;
F_180 ( V_122 -> V_337 ) ;
F_181 ( V_122 , V_3 -> V_105 . V_106 ) ;
F_182 ( V_122 -> V_337 ) ;
F_110 ( V_338 , & V_3 -> V_170 ) ;
} else {
F_96 ( V_3 , V_167 , V_167 ) ;
F_109 ( V_338 , & V_3 -> V_170 ) ;
}
if ( ( V_57 = F_107 ( V_3 , V_122 ) ) )
goto V_335;
if ( V_331 ) {
if ( ! F_74 ( V_3 , V_339 ) ) {
F_37 ( V_59 L_98 ) ;
V_57 = - V_58 ;
goto V_335;
}
F_37 ( V_59 L_99 , V_332 << 1 ) ;
}
return 0 ;
V_335:
F_183 ( V_3 -> V_48 , V_333 | V_334 ) ;
V_132:
return V_57 ;
}
static void F_184 ( struct V_2 * V_3 , int V_340 )
{
if ( V_340 && F_94 ( V_3 ) )
F_174 ( V_59 L_100 , V_3 -> V_4 ) ;
F_169 ( V_3 , 0 ) ;
F_96 ( V_3 , V_167 , V_167 ) ;
F_183 ( V_3 -> V_48 , V_333 | V_334 ) ;
F_70 ( V_3 ) ;
}
static struct V_2 * F_185 ( unsigned int V_341 )
{
if ( V_341 >= V_45 )
return NULL ;
return V_46 [ V_341 ] ;
}
static int F_186 ( struct V_342 * V_48 , T_11 V_343 )
{
struct V_2 * V_3 = NULL ;
int V_57 ;
F_55 ( V_59 L_101 ) ;
F_187 ( & V_344 ) ;
F_187 ( & V_43 ) ;
V_3 = F_185 ( F_27 ( V_48 -> V_49 ) ) ;
if ( ! V_3 ) {
V_57 = - V_55 ;
goto V_132;
}
F_52 ( V_3 -> V_345 < 0 ) ;
V_3 -> V_345 ++ ;
if ( V_3 -> V_345 > 1 ) {
if ( ( V_343 & V_346 ) &&
! F_137 ( V_338 , & V_3 -> V_170 ) ) {
V_57 = - V_347 ;
goto V_348;
}
} else {
V_57 = F_175 ( V_3 , V_343 & V_346 ) ;
if ( V_57 )
goto V_348;
F_188 ( V_48 , V_168 ) ;
}
F_28 ( & V_43 ) ;
F_28 ( & V_344 ) ;
return 0 ;
V_348:
V_3 -> V_345 -- ;
V_132:
F_55 ( V_59 L_102 , V_57 ) ;
F_28 ( & V_43 ) ;
F_28 ( & V_344 ) ;
return V_57 ;
}
static int F_189 ( struct V_349 * V_218 , T_11 V_343 )
{
struct V_2 * V_3 = V_218 -> V_350 ;
int V_57 = 0 ;
F_187 ( & V_344 ) ;
F_187 ( & V_43 ) ;
V_3 -> V_345 -- ;
F_52 ( V_3 -> V_345 < 0 ) ;
if ( V_3 -> V_345 == 0 ) {
int V_340 = F_137 ( V_338 , & V_3 -> V_170 ) ;
F_184 ( V_3 , V_340 ) ;
}
F_28 ( & V_43 ) ;
F_28 ( & V_344 ) ;
return V_57 ;
}
static void F_190 ( struct V_79 * V_79 , int V_188 )
{
struct V_351 * V_352 = V_79 -> V_189 ;
struct V_2 * V_3 = V_352 -> V_3 ;
F_67 ( V_79 ) ;
F_139 ( V_352 -> V_79 , V_188 ) ;
F_81 ( V_352 , V_353 ) ;
F_51 ( V_3 ) ;
}
static int F_191 ( struct V_121 * V_122 , struct V_79 * V_79 )
{
struct V_2 * V_3 ;
char V_354 [ V_355 ] ;
T_3 V_206 ;
struct V_88 * V_91 ;
int V_356 , V_357 ;
struct V_109 * V_110 ;
V_3 = V_122 -> V_358 ;
if ( ! V_3 ) {
F_37 ( V_59 L_103 , F_192 ( V_79 -> V_203 , V_354 ) ) ;
goto V_359;
}
if ( F_98 ( V_79 ) == V_128 ) {
struct V_79 * V_360 = F_193 ( V_79 , V_361 ) ;
struct V_351 * V_352 = F_194 ( V_353 , V_361 ) ;
V_352 -> V_3 = V_3 ;
V_352 -> V_79 = V_79 ;
V_360 -> V_203 = V_3 -> V_48 ;
V_360 -> V_189 = V_352 ;
V_360 -> V_204 = F_190 ;
V_3 -> V_18 . V_22 += V_79 -> V_165 >> 9 ;
F_97 ( V_3 , V_360 ) ;
return 0 ;
}
if ( ! F_137 ( V_338 , & V_3 -> V_170 ) ) {
F_37 ( V_59 L_104 ,
V_3 -> V_4 , ( unsigned long long ) V_79 -> V_116 ) ;
goto V_359;
}
if ( ! V_79 -> V_165 || ( V_79 -> V_165 % V_168 ) ) {
F_37 ( V_59 L_105 ) ;
goto V_359;
}
F_195 ( V_122 , & V_79 ) ;
V_206 = F_134 ( V_79 -> V_116 , V_3 ) ;
F_55 ( L_106 ,
( unsigned long long ) V_79 -> V_116 ,
( unsigned long long ) ( V_79 -> V_116 + F_104 ( V_79 ) ) ) ;
{
struct V_362 * V_363 ;
T_3 V_364 ;
int V_365 ;
V_364 = F_134 ( V_79 -> V_116 + F_104 ( V_79 ) - 1 , V_3 ) ;
if ( V_364 != V_206 ) {
F_52 ( V_364 != V_206 + V_3 -> V_105 . V_106 ) ;
V_365 = V_364 - V_79 -> V_116 ;
V_363 = F_196 ( V_79 , V_365 ) ;
F_52 ( ! V_363 ) ;
F_191 ( V_122 , & V_363 -> V_366 ) ;
F_191 ( V_122 , & V_363 -> V_367 ) ;
F_197 ( V_363 ) ;
return 0 ;
}
}
F_11 ( & V_3 -> V_74 . V_225 ) ;
V_357 = 0 ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_91 -> V_190 == V_206 ) {
F_11 ( & V_91 -> V_24 ) ;
if ( ( V_91 -> V_208 == V_224 ) ||
( V_91 -> V_208 == V_233 ) ) {
F_99 ( & V_91 -> V_98 , V_79 ) ;
V_91 -> V_217 += V_79 -> V_165 / V_168 ;
if ( ( V_91 -> V_217 >= V_91 -> V_89 ) &&
( V_91 -> V_208 == V_224 ) ) {
F_105 ( & V_91 -> V_193 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
F_12 ( & V_91 -> V_24 ) ;
F_12 ( & V_3 -> V_74 . V_225 ) ;
return 0 ;
} else {
V_357 = 1 ;
}
F_12 ( & V_91 -> V_24 ) ;
}
}
F_12 ( & V_3 -> V_74 . V_225 ) ;
F_11 ( & V_3 -> V_24 ) ;
if ( V_3 -> V_27 > 0
&& V_3 -> V_25 >= V_3 -> V_27 ) {
F_198 ( & V_122 -> V_220 , V_221 ) ;
do {
F_12 ( & V_3 -> V_24 ) ;
F_199 ( V_221 , V_137 ) ;
F_11 ( & V_3 -> V_24 ) ;
} while( V_3 -> V_25 > V_3 -> V_26 );
}
F_12 ( & V_3 -> V_24 ) ;
V_110 = F_194 ( V_3 -> V_113 , V_361 ) ;
V_110 -> V_79 = V_79 ;
F_11 ( & V_3 -> V_24 ) ;
F_52 ( V_3 -> V_25 < 0 ) ;
V_356 = ( V_3 -> V_25 == 0 ) ;
F_83 ( V_3 , V_110 ) ;
F_12 ( & V_3 -> V_24 ) ;
F_56 ( & V_3 -> V_214 , 1 ) ;
if ( V_356 ) {
F_57 ( & V_3 -> V_78 ) ;
} else if ( ! F_71 ( & V_3 -> V_74 . V_103 ) && ! V_357 ) {
F_57 ( & V_3 -> V_78 ) ;
}
return 0 ;
V_359:
F_200 ( V_79 ) ;
return 0 ;
}
static int F_201 ( struct V_121 * V_122 , struct V_368 * V_369 ,
struct V_82 * V_186 )
{
struct V_2 * V_3 = V_122 -> V_358 ;
T_3 V_206 = F_134 ( V_369 -> V_116 , V_3 ) ;
int V_370 = ( ( V_369 -> V_116 - V_206 ) << 9 ) + V_369 -> V_165 ;
int V_371 = ( V_3 -> V_105 . V_106 << 9 ) - V_370 ;
int V_372 ;
V_372 = V_171 - V_369 -> V_165 ;
V_371 = F_14 ( V_371 , V_372 ) ;
F_52 ( V_371 < 0 ) ;
return V_371 ;
}
static void F_202 ( struct V_2 * V_3 )
{
struct V_121 * V_122 = V_3 -> V_218 -> V_219 ;
F_203 ( V_122 , F_191 ) ;
F_204 ( V_122 , V_168 ) ;
F_181 ( V_122 , V_302 ) ;
F_205 ( V_122 , F_201 ) ;
V_122 -> V_358 = V_3 ;
}
static int F_41 ( struct V_64 * V_65 , void * V_9 )
{
struct V_2 * V_3 = V_65 -> V_373 ;
char * V_374 ;
char V_375 [ V_355 ] ;
int V_239 [ V_240 ] ;
F_206 ( V_65 , L_107 , V_3 -> V_4 ,
F_192 ( V_3 -> V_48 , V_375 ) ) ;
F_206 ( V_65 , L_108 ) ;
F_206 ( V_65 , L_109 , V_3 -> V_105 . V_106 / 2 ) ;
if ( V_3 -> V_105 . V_280 == 0 )
V_374 = L_110 ;
else
V_374 = L_111 ;
F_206 ( V_65 , L_112 , V_374 ) ;
F_206 ( V_65 , L_113 , V_3 -> V_105 . V_250 ? L_66 : L_67 ) ;
F_206 ( V_65 , L_114 , V_3 -> V_105 . V_309 ) ;
F_206 ( V_65 , L_115 , V_3 -> V_105 . V_279 ) ;
if ( V_3 -> V_105 . V_251 == V_285 )
V_374 = L_116 ;
else if ( V_3 -> V_105 . V_251 == V_288 )
V_374 = L_117 ;
else
V_374 = L_111 ;
F_206 ( V_65 , L_118 , V_374 ) ;
F_206 ( V_65 , L_119 ) ;
F_206 ( V_65 , L_120 , V_3 -> V_18 . V_19 ) ;
F_206 ( V_65 , L_121 , V_3 -> V_18 . V_20 ) ;
F_206 ( V_65 , L_122 , V_3 -> V_18 . V_21 >> 1 ) ;
F_206 ( V_65 , L_123 , V_3 -> V_18 . V_23 >> 1 ) ;
F_206 ( V_65 , L_124 , V_3 -> V_18 . V_22 >> 1 ) ;
F_206 ( V_65 , L_125 ) ;
F_206 ( V_65 , L_126 , V_3 -> V_345 ) ;
F_206 ( V_65 , L_127 , V_3 -> V_170 ) ;
F_206 ( V_65 , L_128 , V_3 -> V_155 ) ;
F_206 ( V_65 , L_129 , V_3 -> V_154 ) ;
F_206 ( V_65 , L_130 , V_3 -> V_202 ) ;
F_206 ( V_65 , L_131 , V_3 -> V_277 ) ;
F_206 ( V_65 , L_132 ) ;
F_206 ( V_65 , L_133 , V_3 -> V_25 ) ;
F_206 ( V_65 , L_134 , F_53 ( & V_3 -> V_74 . V_75 ) ) ;
F_206 ( V_65 , L_135 , ( unsigned long long ) V_3 -> V_215 ) ;
F_143 ( V_3 , V_239 ) ;
F_206 ( V_65 , L_136 ,
V_239 [ 0 ] , V_239 [ 1 ] , V_239 [ 2 ] , V_239 [ 3 ] , V_239 [ 4 ] , V_239 [ 5 ] ) ;
F_206 ( V_65 , L_137 ,
V_3 -> V_26 ,
V_3 -> V_27 ) ;
return 0 ;
}
static int F_207 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
return F_43 ( V_67 , F_41 , F_208 ( V_66 ) -> V_15 ) ;
}
static int F_209 ( struct V_2 * V_3 , T_12 V_33 )
{
int V_90 ;
int V_57 = 0 ;
char V_354 [ V_355 ] ;
struct V_342 * V_48 ;
if ( V_3 -> V_47 == V_33 ) {
F_37 ( V_59 L_138 ) ;
return - V_347 ;
}
for ( V_90 = 0 ; V_90 < V_45 ; V_90 ++ ) {
struct V_2 * V_376 = V_46 [ V_90 ] ;
if ( ! V_376 )
continue;
if ( V_376 -> V_48 -> V_49 == V_33 ) {
F_37 ( V_59 L_139 , F_192 ( V_376 -> V_48 , V_354 ) ) ;
return - V_347 ;
}
if ( V_376 -> V_47 == V_33 ) {
F_37 ( V_59 L_140 ) ;
return - V_347 ;
}
}
V_48 = F_176 ( V_33 ) ;
if ( ! V_48 )
return - V_58 ;
V_57 = F_177 ( V_48 , V_333 | V_377 , NULL ) ;
if ( V_57 )
return V_57 ;
F_210 ( V_54 ) ;
V_3 -> V_48 = V_48 ;
F_188 ( V_48 , V_168 ) ;
F_202 ( V_3 ) ;
F_56 ( & V_3 -> V_74 . V_75 , 0 ) ;
V_3 -> V_74 . V_378 = F_211 ( F_144 , V_3 , L_1 , V_3 -> V_4 ) ;
if ( F_20 ( V_3 -> V_74 . V_378 ) ) {
F_37 ( V_59 L_141 ) ;
V_57 = - V_58 ;
goto V_379;
}
F_212 ( V_3 -> V_4 , 0 , V_380 , & V_381 , V_3 ) ;
F_174 ( V_59 L_142 , V_3 -> V_4 , F_192 ( V_48 , V_354 ) ) ;
return 0 ;
V_379:
F_183 ( V_48 , V_333 | V_377 ) ;
F_32 ( V_54 ) ;
return V_57 ;
}
static int F_213 ( struct V_342 * V_48 , T_11 V_343 , unsigned int V_134 , unsigned long V_382 )
{
struct V_2 * V_3 = V_48 -> V_143 -> V_350 ;
int V_57 ;
F_55 ( L_143 , V_134 ,
F_26 ( V_48 -> V_49 ) , F_27 ( V_48 -> V_49 ) ) ;
F_187 ( & V_344 ) ;
switch ( V_134 ) {
case V_383 :
if ( V_3 -> V_345 == 1 )
F_169 ( V_3 , 0 ) ;
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
V_57 = F_214 ( V_3 -> V_48 , V_343 , V_134 , V_382 ) ;
break;
default:
F_55 ( V_59 L_144 , V_3 -> V_4 , V_134 ) ;
V_57 = - V_389 ;
}
F_28 ( & V_344 ) ;
return V_57 ;
}
static unsigned int F_215 ( struct V_349 * V_218 ,
unsigned int V_390 )
{
struct V_2 * V_3 = V_218 -> V_350 ;
struct V_349 * V_391 ;
if ( ! V_3 )
return 0 ;
if ( ! V_3 -> V_48 )
return 0 ;
V_391 = V_3 -> V_48 -> V_143 ;
if ( ! V_391 || ! V_391 -> V_392 -> V_393 )
return 0 ;
return V_391 -> V_392 -> V_393 ( V_391 , V_390 ) ;
}
static char * F_216 ( struct V_349 * V_394 , T_13 * V_343 )
{
return F_217 ( V_10 , L_145 , V_394 -> V_395 ) ;
}
static int F_31 ( T_12 V_33 , T_12 * V_47 )
{
int V_42 ;
int V_57 = - V_58 ;
struct V_2 * V_3 ;
struct V_349 * V_218 ;
F_25 ( & V_43 , V_44 ) ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ )
if ( ! V_46 [ V_42 ] )
break;
if ( V_42 == V_45 ) {
F_37 ( V_59 L_146 , V_45 ) ;
V_57 = - V_347 ;
goto V_396;
}
V_3 = F_2 ( sizeof( struct V_2 ) , V_10 ) ;
if ( ! V_3 )
goto V_396;
V_3 -> V_113 = F_218 ( V_397 ,
sizeof( struct V_109 ) ) ;
if ( ! V_3 -> V_113 )
goto V_379;
F_73 ( & V_3 -> V_74 . V_103 ) ;
F_73 ( & V_3 -> V_74 . V_102 ) ;
F_65 ( & V_3 -> V_74 . V_225 ) ;
F_65 ( & V_3 -> V_24 ) ;
F_65 ( & V_3 -> V_76 . V_24 ) ;
F_66 ( & V_3 -> V_76 . V_157 ) ;
F_66 ( & V_3 -> V_76 . V_158 ) ;
sprintf ( V_3 -> V_4 , V_59 L_13 , V_42 ) ;
F_219 ( & V_3 -> V_78 ) ;
V_3 -> V_112 = V_398 ;
V_3 -> V_27 = V_27 ;
V_3 -> V_26 = V_26 ;
V_218 = F_220 ( 1 ) ;
if ( ! V_218 )
goto V_379;
V_3 -> V_218 = V_218 ;
V_218 -> V_52 = V_399 ;
V_218 -> V_400 = V_42 ;
V_218 -> V_392 = & V_401 ;
V_218 -> V_170 = V_402 ;
strcpy ( V_218 -> V_395 , V_3 -> V_4 ) ;
V_218 -> V_403 = F_216 ;
V_218 -> V_350 = V_3 ;
V_218 -> V_219 = F_221 ( V_10 ) ;
if ( ! V_218 -> V_219 )
goto V_404;
V_3 -> V_47 = F_19 ( V_399 , V_42 ) ;
V_57 = F_209 ( V_3 , V_33 ) ;
if ( V_57 )
goto V_405;
V_218 -> V_406 = V_3 -> V_48 -> V_143 -> V_406 ;
V_218 -> V_407 = V_3 -> V_48 -> V_143 -> V_407 ;
F_222 ( V_218 ) ;
F_17 ( V_3 ) ;
F_44 ( V_3 ) ;
V_46 [ V_42 ] = V_3 ;
if ( V_47 )
* V_47 = V_3 -> V_47 ;
F_28 ( & V_43 ) ;
return 0 ;
V_405:
F_223 ( V_218 -> V_219 ) ;
V_404:
F_224 ( V_218 ) ;
V_379:
if ( V_3 -> V_113 )
F_225 ( V_3 -> V_113 ) ;
F_8 ( V_3 ) ;
V_396:
F_28 ( & V_43 ) ;
F_37 ( V_59 L_147 ) ;
return V_57 ;
}
static int F_34 ( T_12 V_47 )
{
struct V_2 * V_3 ;
int V_42 ;
int V_57 = 0 ;
F_25 ( & V_43 , V_44 ) ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ ) {
V_3 = V_46 [ V_42 ] ;
if ( V_3 && ( V_3 -> V_47 == V_47 ) )
break;
}
if ( V_42 == V_45 ) {
F_174 ( V_59 L_148 ) ;
V_57 = - V_301 ;
goto V_132;
}
if ( V_3 -> V_345 > 0 ) {
V_57 = - V_347 ;
goto V_132;
}
if ( ! F_20 ( V_3 -> V_74 . V_378 ) )
F_226 ( V_3 -> V_74 . V_378 ) ;
V_46 [ V_42 ] = NULL ;
F_47 ( V_3 ) ;
F_21 ( V_3 ) ;
F_183 ( V_3 -> V_48 , V_333 | V_377 ) ;
F_227 ( V_3 -> V_4 , V_380 ) ;
F_174 ( V_59 L_149 , V_3 -> V_4 ) ;
F_228 ( V_3 -> V_218 ) ;
F_223 ( V_3 -> V_218 -> V_219 ) ;
F_224 ( V_3 -> V_218 ) ;
F_225 ( V_3 -> V_113 ) ;
F_8 ( V_3 ) ;
F_32 ( V_54 ) ;
V_132:
F_28 ( & V_43 ) ;
return V_57 ;
}
static void F_229 ( struct V_408 * V_409 )
{
struct V_2 * V_3 ;
F_25 ( & V_43 , V_44 ) ;
V_3 = F_185 ( V_409 -> V_410 ) ;
if ( V_3 ) {
V_409 -> V_33 = F_230 ( V_3 -> V_48 -> V_49 ) ;
V_409 -> V_47 = F_230 ( V_3 -> V_47 ) ;
} else {
V_409 -> V_33 = 0 ;
V_409 -> V_47 = 0 ;
}
V_409 -> V_411 = V_45 ;
F_28 ( & V_43 ) ;
}
static long F_231 ( struct V_67 * V_67 , unsigned int V_134 , unsigned long V_382 )
{
void T_14 * V_412 = ( void T_14 * ) V_382 ;
struct V_408 V_409 ;
int V_57 = 0 ;
T_12 V_47 = 0 ;
if ( V_134 != V_413 )
return - V_389 ;
if ( F_232 ( & V_409 , V_412 , sizeof( struct V_408 ) ) )
return - V_414 ;
switch ( V_409 . V_415 ) {
case V_416 :
if ( ! F_233 ( V_417 ) )
return - V_418 ;
V_57 = F_31 ( F_234 ( V_409 . V_33 ) , & V_47 ) ;
V_409 . V_47 = F_230 ( V_47 ) ;
break;
case V_419 :
if ( ! F_233 ( V_417 ) )
return - V_418 ;
V_57 = F_34 ( F_234 ( V_409 . V_47 ) ) ;
break;
case V_420 :
F_229 ( & V_409 ) ;
break;
default:
return - V_389 ;
}
if ( F_235 ( V_412 , & V_409 , sizeof( struct V_408 ) ) )
return - V_414 ;
return V_57 ;
}
static long F_236 ( struct V_67 * V_67 , unsigned int V_134 , unsigned long V_382 )
{
return F_231 ( V_67 , V_134 , ( unsigned long ) F_237 ( V_382 ) ) ;
}
static int T_15 F_238 ( void )
{
int V_57 ;
F_239 ( & V_43 ) ;
V_353 = F_218 ( V_421 ,
sizeof( struct V_351 ) ) ;
if ( ! V_353 )
return - V_58 ;
V_57 = F_240 ( V_399 , V_59 ) ;
if ( V_57 < 0 ) {
F_37 ( V_59 L_150 ) ;
goto V_422;
}
if ( ! V_399 )
V_399 = V_57 ;
V_57 = F_35 () ;
if ( V_57 )
goto V_132;
F_49 () ;
V_57 = F_241 ( & V_423 ) ;
if ( V_57 ) {
F_37 ( V_59 L_151 ) ;
goto V_424;
}
V_380 = F_242 ( L_152 V_59 , NULL ) ;
return 0 ;
V_424:
F_50 () ;
F_38 () ;
V_132:
F_243 ( V_399 , V_59 ) ;
V_422:
F_225 ( V_353 ) ;
return V_57 ;
}
static void T_16 F_244 ( void )
{
F_227 ( L_152 V_59 , NULL ) ;
F_245 ( & V_423 ) ;
F_50 () ;
F_38 () ;
F_243 ( V_399 , V_59 ) ;
F_225 ( V_353 ) ;
}
