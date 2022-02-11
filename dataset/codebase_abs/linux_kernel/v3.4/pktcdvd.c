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
void * V_180 = F_113 ( V_179 -> V_181 ) +
V_179 -> V_182 + V_174 ;
void * V_183 = F_114 ( V_176 ) + V_177 ;
int V_30 = F_115 ( int , V_178 , V_179 -> V_184 - V_174 ) ;
F_52 ( V_30 < 0 ) ;
memcpy ( V_183 , V_180 , V_30 ) ;
F_116 ( V_180 ) ;
V_173 ++ ;
V_174 = 0 ;
V_177 += V_30 ;
V_178 -= V_30 ;
}
}
static void F_117 ( struct V_88 * V_91 , struct V_82 * V_185 )
{
int V_186 , V_9 , V_174 ;
V_9 = 0 ;
V_174 = 0 ;
for ( V_186 = 0 ; V_186 < V_91 -> V_89 ; V_186 ++ ) {
if ( V_185 [ V_186 ] . V_181 != V_91 -> V_95 [ V_9 ] ) {
void * V_180 = F_113 ( V_185 [ V_186 ] . V_181 ) + V_185 [ V_186 ] . V_182 ;
void * V_183 = F_114 ( V_91 -> V_95 [ V_9 ] ) + V_174 ;
memcpy ( V_183 , V_180 , V_168 ) ;
F_116 ( V_180 ) ;
V_185 [ V_186 ] . V_181 = V_91 -> V_95 [ V_9 ] ;
V_185 [ V_186 ] . V_182 = V_174 ;
} else {
F_52 ( V_185 [ V_186 ] . V_182 != V_174 ) ;
}
V_174 += V_168 ;
if ( V_174 >= V_171 ) {
V_174 = 0 ;
V_9 ++ ;
}
}
}
static void F_118 ( struct V_79 * V_79 , int V_187 )
{
struct V_88 * V_91 = V_79 -> V_188 ;
struct V_2 * V_3 = V_91 -> V_3 ;
F_52 ( ! V_3 ) ;
F_55 ( L_40 , V_79 ,
( unsigned long long ) V_91 -> V_189 , ( unsigned long long ) V_79 -> V_116 , V_187 ) ;
if ( V_187 )
F_105 ( & V_91 -> V_190 ) ;
if ( F_54 ( & V_91 -> V_191 ) ) {
F_105 ( & V_91 -> V_192 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
F_51 ( V_3 ) ;
}
static void F_119 ( struct V_79 * V_79 , int V_187 )
{
struct V_88 * V_91 = V_79 -> V_188 ;
struct V_2 * V_3 = V_91 -> V_3 ;
F_52 ( ! V_3 ) ;
F_55 ( L_41 , V_91 -> V_107 , V_187 ) ;
V_3 -> V_18 . V_20 ++ ;
F_51 ( V_3 ) ;
F_120 ( & V_91 -> V_191 ) ;
F_105 ( & V_91 -> V_192 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
static void F_121 ( struct V_2 * V_3 , struct V_88 * V_91 )
{
int V_193 = 0 ;
struct V_79 * V_79 ;
int V_186 ;
char V_194 [ V_195 ] ;
F_52 ( F_101 ( & V_91 -> V_98 ) ) ;
F_56 ( & V_91 -> V_191 , 0 ) ;
F_56 ( & V_91 -> V_190 , 0 ) ;
memset ( V_194 , 0 , sizeof( V_194 ) ) ;
F_11 ( & V_91 -> V_24 ) ;
F_122 (bio, &pkt->orig_bios) {
int V_196 = ( V_79 -> V_116 - V_91 -> V_189 ) / ( V_168 >> 9 ) ;
int V_197 = V_79 -> V_165 / V_168 ;
V_3 -> V_18 . V_21 += V_197 * ( V_168 >> 9 ) ;
F_52 ( V_196 < 0 ) ;
F_52 ( V_196 + V_197 > V_91 -> V_89 ) ;
for ( V_186 = V_196 ; V_186 < V_196 + V_197 ; V_186 ++ )
V_194 [ V_186 ] = 1 ;
}
F_12 ( & V_91 -> V_24 ) ;
if ( V_91 -> V_198 ) {
F_55 ( L_42 ,
( unsigned long long ) V_91 -> V_189 ) ;
goto V_199;
}
for ( V_186 = 0 ; V_186 < V_91 -> V_89 ; V_186 ++ ) {
struct V_82 * V_200 ;
int V_9 , V_201 ;
if ( V_194 [ V_186 ] )
continue;
V_79 = V_91 -> V_100 [ V_186 ] ;
V_200 = V_79 -> V_80 ;
F_61 ( V_79 ) ;
V_79 -> V_86 = 1 ;
V_79 -> V_116 = V_91 -> V_189 + V_186 * ( V_168 >> 9 ) ;
V_79 -> V_202 = V_3 -> V_48 ;
V_79 -> V_203 = F_118 ;
V_79 -> V_188 = V_91 ;
V_79 -> V_80 = V_200 ;
V_79 -> V_87 = F_58 ;
V_9 = ( V_186 * V_168 ) / V_171 ;
V_201 = ( V_186 * V_168 ) % V_171 ;
F_55 ( L_43 ,
V_186 , V_91 -> V_95 [ V_9 ] , V_201 ) ;
if ( ! F_123 ( V_79 , V_91 -> V_95 [ V_9 ] , V_168 , V_201 ) )
F_124 () ;
F_105 ( & V_91 -> V_191 ) ;
V_79 -> V_204 = V_128 ;
F_97 ( V_3 , V_79 ) ;
V_193 ++ ;
}
V_199:
F_55 ( L_44 ,
V_193 , ( unsigned long long ) V_91 -> V_189 ) ;
V_3 -> V_18 . V_19 ++ ;
V_3 -> V_18 . V_23 += V_193 * ( V_168 >> 9 ) ;
}
static struct V_88 * F_125 ( struct V_2 * V_3 , int V_205 )
{
struct V_88 * V_91 ;
F_126 (pkt, &pd->cdrw.pkt_free_list, list) {
if ( V_91 -> V_189 == V_205 || V_91 -> V_108 . V_101 == & V_3 -> V_74 . V_103 ) {
F_127 ( & V_91 -> V_108 ) ;
if ( V_91 -> V_189 != V_205 )
V_91 -> V_198 = 0 ;
return V_91 ;
}
}
F_124 () ;
return NULL ;
}
static void F_128 ( struct V_2 * V_3 , struct V_88 * V_91 )
{
if ( V_91 -> V_198 ) {
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
static inline void F_131 ( struct V_88 * V_91 , enum V_206 V_207 )
{
#if V_208 > 1
static const char * V_209 [] = {
L_45 , L_46 , L_47 , L_48 , L_49 , L_50
} ;
enum V_206 V_210 = V_91 -> V_207 ;
F_55 ( L_51 , V_91 -> V_107 , ( unsigned long long ) V_91 -> V_189 ,
V_209 [ V_210 ] , V_209 [ V_207 ] ) ;
#endif
V_91 -> V_207 = V_207 ;
}
static int F_132 ( struct V_2 * V_3 )
{
struct V_88 * V_91 , * V_9 ;
struct V_79 * V_79 = NULL ;
T_3 V_205 = 0 ;
struct V_109 * V_110 , * V_211 ;
struct V_111 * V_16 ;
int V_212 ;
F_55 ( L_52 ) ;
F_56 ( & V_3 -> V_213 , 0 ) ;
if ( F_71 ( & V_3 -> V_74 . V_103 ) ) {
F_55 ( L_53 ) ;
return 0 ;
}
F_11 ( & V_3 -> V_24 ) ;
V_211 = F_82 ( V_3 , V_3 -> V_214 ) ;
if ( ! V_211 ) {
V_16 = F_133 ( & V_3 -> V_112 ) ;
if ( V_16 )
V_211 = F_78 ( V_16 , struct V_109 , V_111 ) ;
}
V_110 = V_211 ;
while ( V_110 ) {
V_79 = V_110 -> V_79 ;
V_205 = F_134 ( V_79 -> V_116 , V_3 ) ;
F_126 (p, &pd->cdrw.pkt_active_list, list) {
if ( V_9 -> V_189 == V_205 ) {
V_79 = NULL ;
goto V_215;
}
}
break;
V_215:
V_110 = F_76 ( V_110 ) ;
if ( ! V_110 ) {
V_16 = F_133 ( & V_3 -> V_112 ) ;
if ( V_16 )
V_110 = F_78 ( V_16 , struct V_109 , V_111 ) ;
}
if ( V_110 == V_211 )
V_110 = NULL ;
}
F_12 ( & V_3 -> V_24 ) ;
if ( ! V_79 ) {
F_55 ( L_54 ) ;
return 0 ;
}
V_91 = F_125 ( V_3 , V_205 ) ;
V_3 -> V_214 = V_205 + V_3 -> V_105 . V_106 ;
V_91 -> V_189 = V_205 ;
F_52 ( V_91 -> V_89 != V_3 -> V_105 . V_106 >> 2 ) ;
V_91 -> V_216 = 0 ;
F_11 ( & V_3 -> V_24 ) ;
F_55 ( L_55 , ( unsigned long long ) V_205 ) ;
while ( ( V_110 = F_82 ( V_3 , V_205 ) ) != NULL ) {
V_79 = V_110 -> V_79 ;
F_55 ( L_56 ,
( unsigned long long ) F_134 ( V_79 -> V_116 , V_3 ) ) ;
if ( F_134 ( V_79 -> V_116 , V_3 ) != V_205 )
break;
F_79 ( V_3 , V_110 ) ;
F_11 ( & V_91 -> V_24 ) ;
F_99 ( & V_91 -> V_98 , V_79 ) ;
V_91 -> V_216 += V_79 -> V_165 / V_168 ;
F_12 ( & V_91 -> V_24 ) ;
}
V_212 = ( V_3 -> V_27 > 0
&& V_3 -> V_25 <= V_3 -> V_26 ) ;
F_12 ( & V_3 -> V_24 ) ;
if ( V_212 ) {
F_135 ( & V_3 -> V_217 -> V_218 -> V_219 ,
V_220 ) ;
}
V_91 -> V_221 = F_14 ( V_222 , 1 ) ;
F_131 ( V_91 , V_223 ) ;
F_56 ( & V_91 -> V_192 , 1 ) ;
F_11 ( & V_3 -> V_74 . V_224 ) ;
F_75 ( & V_91 -> V_108 , & V_3 -> V_74 . V_102 ) ;
F_12 ( & V_3 -> V_74 . V_224 ) ;
return 1 ;
}
static void F_136 ( struct V_2 * V_3 , struct V_88 * V_91 )
{
struct V_79 * V_79 ;
int V_186 ;
int V_225 ;
struct V_82 * V_185 = V_91 -> V_93 -> V_80 ;
for ( V_186 = 0 ; V_186 < V_91 -> V_89 ; V_186 ++ ) {
V_185 [ V_186 ] . V_181 = V_91 -> V_95 [ ( V_186 * V_168 ) / V_171 ] ;
V_185 [ V_186 ] . V_182 = ( V_186 * V_168 ) % V_171 ;
}
V_225 = 0 ;
F_11 ( & V_91 -> V_24 ) ;
F_122 (bio, &pkt->orig_bios) {
int V_226 = V_79 -> V_227 ;
int V_228 = 0 ;
int V_196 = ( V_79 -> V_116 - V_91 -> V_189 ) / ( V_168 >> 9 ) ;
int V_197 = V_79 -> V_165 / V_168 ;
F_52 ( V_196 < 0 ) ;
F_52 ( V_196 + V_197 > V_91 -> V_89 ) ;
for ( V_186 = V_196 ; V_186 < V_196 + V_197 ; V_186 ++ ) {
struct V_82 * V_179 = F_112 ( V_79 , V_226 ) ;
while ( V_228 >= V_179 -> V_184 ) {
V_228 -= V_179 -> V_184 ;
V_226 ++ ;
F_52 ( V_226 >= V_79 -> V_229 ) ;
V_179 = F_112 ( V_79 , V_226 ) ;
}
if ( V_179 -> V_184 - V_228 >= V_168 ) {
V_185 [ V_186 ] . V_181 = V_179 -> V_181 ;
V_185 [ V_186 ] . V_182 = V_179 -> V_182 + V_228 ;
} else {
F_111 ( V_79 , V_226 , V_228 ,
V_185 [ V_186 ] . V_181 , V_185 [ V_186 ] . V_182 ) ;
}
V_228 += V_168 ;
V_225 ++ ;
}
}
F_131 ( V_91 , V_230 ) ;
F_12 ( & V_91 -> V_24 ) ;
F_55 ( L_57 ,
V_225 , ( unsigned long long ) V_91 -> V_189 ) ;
F_52 ( V_225 != V_91 -> V_216 ) ;
if ( F_137 ( V_169 , & V_3 -> V_170 ) || ( V_91 -> V_216 < V_91 -> V_89 ) ) {
F_117 ( V_91 , V_185 ) ;
V_91 -> V_198 = 1 ;
} else {
V_91 -> V_198 = 0 ;
}
F_61 ( V_91 -> V_93 ) ;
V_91 -> V_93 -> V_86 = V_195 ;
V_91 -> V_93 -> V_116 = V_91 -> V_189 ;
V_91 -> V_93 -> V_202 = V_3 -> V_48 ;
V_91 -> V_93 -> V_203 = F_119 ;
V_91 -> V_93 -> V_188 = V_91 ;
V_91 -> V_93 -> V_80 = V_185 ;
V_91 -> V_93 -> V_87 = F_58 ;
for ( V_186 = 0 ; V_186 < V_91 -> V_89 ; V_186 ++ )
if ( ! F_123 ( V_91 -> V_93 , V_185 [ V_186 ] . V_181 , V_168 , V_185 [ V_186 ] . V_182 ) )
F_124 () ;
F_55 ( V_59 L_58 , V_91 -> V_93 -> V_229 ) ;
F_56 ( & V_91 -> V_191 , 1 ) ;
V_91 -> V_93 -> V_204 = V_127 ;
F_97 ( V_3 , V_91 -> V_93 ) ;
}
static void F_138 ( struct V_88 * V_91 , int V_231 )
{
struct V_79 * V_79 ;
if ( ! V_231 )
V_91 -> V_198 = 0 ;
while ( ( V_79 = F_103 ( & V_91 -> V_98 ) ) )
F_139 ( V_79 , V_231 ? 0 : - V_145 ) ;
}
static void F_140 ( struct V_2 * V_3 , struct V_88 * V_91 )
{
int V_231 ;
F_55 ( L_59 , V_91 -> V_107 ) ;
for (; ; ) {
switch ( V_91 -> V_207 ) {
case V_223 :
if ( ( V_91 -> V_216 < V_91 -> V_89 ) && ( V_91 -> V_221 > 0 ) )
return;
V_91 -> V_221 = 0 ;
F_121 ( V_3 , V_91 ) ;
F_131 ( V_91 , V_232 ) ;
break;
case V_232 :
if ( F_53 ( & V_91 -> V_191 ) > 0 )
return;
if ( F_53 ( & V_91 -> V_190 ) > 0 ) {
F_131 ( V_91 , V_233 ) ;
} else {
F_136 ( V_3 , V_91 ) ;
}
break;
case V_230 :
if ( F_53 ( & V_91 -> V_191 ) > 0 )
return;
if ( F_137 ( V_234 , & V_91 -> V_93 -> V_235 ) ) {
F_131 ( V_91 , V_236 ) ;
} else {
F_131 ( V_91 , V_233 ) ;
}
break;
case V_233 :
if ( F_130 ( V_91 ) ) {
F_136 ( V_3 , V_91 ) ;
} else {
F_55 ( L_60 ) ;
F_131 ( V_91 , V_236 ) ;
}
break;
case V_236 :
V_231 = F_137 ( V_234 , & V_91 -> V_93 -> V_235 ) ;
F_138 ( V_91 , V_231 ) ;
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
if ( F_53 ( & V_91 -> V_192 ) > 0 ) {
F_56 ( & V_91 -> V_192 , 0 ) ;
F_140 ( V_3 , V_91 ) ;
}
}
F_11 ( & V_3 -> V_74 . V_224 ) ;
F_72 (pkt, next, &pd->cdrw.pkt_active_list, list) {
if ( V_91 -> V_207 == V_236 ) {
F_142 ( & V_91 -> V_108 ) ;
F_128 ( V_3 , V_91 ) ;
F_131 ( V_91 , V_237 ) ;
F_56 ( & V_3 -> V_213 , 1 ) ;
}
}
F_12 ( & V_3 -> V_74 . V_224 ) ;
}
static void F_143 ( struct V_2 * V_3 , int * V_238 )
{
struct V_88 * V_91 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_239 ; V_90 ++ )
V_238 [ V_90 ] = 0 ;
F_11 ( & V_3 -> V_74 . V_224 ) ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
V_238 [ V_91 -> V_207 ] ++ ;
}
F_12 ( & V_3 -> V_74 . V_224 ) ;
}
static int F_144 ( void * V_240 )
{
struct V_2 * V_3 = V_240 ;
struct V_88 * V_91 ;
long V_241 , V_242 ;
F_145 ( V_243 , - 20 ) ;
F_146 () ;
for (; ; ) {
F_147 ( V_244 , V_243 ) ;
F_148 ( & V_3 -> V_78 , & V_244 ) ;
for (; ; ) {
F_149 ( V_245 ) ;
if ( F_53 ( & V_3 -> V_213 ) > 0 )
goto V_246;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_53 ( & V_91 -> V_192 ) > 0 )
goto V_246;
}
if ( F_53 ( & V_3 -> V_76 . V_77 ) != 0 )
goto V_246;
if ( V_208 > 1 ) {
int V_238 [ V_239 ] ;
F_143 ( V_3 , V_238 ) ;
F_55 ( L_62 ,
V_238 [ 0 ] , V_238 [ 1 ] , V_238 [ 2 ] , V_238 [ 3 ] ,
V_238 [ 4 ] , V_238 [ 5 ] ) ;
}
V_241 = V_247 ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_91 -> V_221 && V_91 -> V_221 < V_241 )
V_241 = V_91 -> V_221 ;
}
F_55 ( L_63 ) ;
V_242 = F_150 ( V_241 ) ;
F_55 ( L_64 ) ;
F_151 () ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( ! V_91 -> V_221 )
continue;
V_91 -> V_221 -= V_241 - V_242 ;
if ( V_91 -> V_221 <= 0 ) {
V_91 -> V_221 = 0 ;
F_105 ( & V_91 -> V_192 ) ;
}
}
if ( F_152 () )
break;
}
V_246:
F_149 ( V_248 ) ;
F_153 ( & V_3 -> V_78 , & V_244 ) ;
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
F_37 ( V_59 L_65 , V_3 -> V_105 . V_249 ? L_66 : L_67 ) ;
F_37 ( L_68 , V_3 -> V_105 . V_106 >> 2 ) ;
F_37 ( L_69 , V_3 -> V_105 . V_250 == 8 ? '1' : '2' ) ;
}
static int F_155 ( struct V_2 * V_3 , struct V_119 * V_120 , int V_251 , int V_252 )
{
memset ( V_120 -> V_134 , 0 , sizeof( V_120 -> V_134 ) ) ;
V_120 -> V_134 [ 0 ] = V_253 ;
V_120 -> V_134 [ 2 ] = V_251 | ( V_252 << 6 ) ;
V_120 -> V_134 [ 7 ] = V_120 -> V_130 >> 8 ;
V_120 -> V_134 [ 8 ] = V_120 -> V_130 & 0xff ;
V_120 -> V_125 = V_254 ;
return F_86 ( V_3 , V_120 ) ;
}
static int F_156 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
memset ( V_120 -> V_134 , 0 , sizeof( V_120 -> V_134 ) ) ;
memset ( V_120 -> V_131 , 0 , 2 ) ;
V_120 -> V_134 [ 0 ] = V_255 ;
V_120 -> V_134 [ 1 ] = 0x10 ;
V_120 -> V_134 [ 7 ] = V_120 -> V_130 >> 8 ;
V_120 -> V_134 [ 8 ] = V_120 -> V_130 & 0xff ;
V_120 -> V_125 = V_126 ;
return F_86 ( V_3 , V_120 ) ;
}
static int F_157 ( struct V_2 * V_3 , T_5 * V_256 )
{
struct V_119 V_120 ;
int V_57 ;
F_95 ( & V_120 , V_256 , sizeof( * V_256 ) , V_254 ) ;
V_120 . V_134 [ 0 ] = V_257 ;
V_120 . V_134 [ 8 ] = V_120 . V_130 = 2 ;
V_120 . V_140 = 1 ;
if ( ( V_57 = F_86 ( V_3 , & V_120 ) ) )
return V_57 ;
V_120 . V_130 = F_158 ( V_256 -> V_258 ) +
sizeof( V_256 -> V_258 ) ;
if ( V_120 . V_130 > sizeof( T_5 ) )
V_120 . V_130 = sizeof( T_5 ) ;
V_120 . V_134 [ 8 ] = V_120 . V_130 ;
return F_86 ( V_3 , & V_120 ) ;
}
static int F_159 ( struct V_2 * V_3 , T_6 V_259 , T_7 type , T_8 * V_260 )
{
struct V_119 V_120 ;
int V_57 ;
F_95 ( & V_120 , V_260 , 8 , V_254 ) ;
V_120 . V_134 [ 0 ] = V_261 ;
V_120 . V_134 [ 1 ] = type & 3 ;
V_120 . V_134 [ 4 ] = ( V_259 & 0xff00 ) >> 8 ;
V_120 . V_134 [ 5 ] = V_259 & 0xff ;
V_120 . V_134 [ 8 ] = 8 ;
V_120 . V_140 = 1 ;
if ( ( V_57 = F_86 ( V_3 , & V_120 ) ) )
return V_57 ;
V_120 . V_130 = F_158 ( V_260 -> V_262 ) +
sizeof( V_260 -> V_262 ) ;
if ( V_120 . V_130 > sizeof( T_8 ) )
V_120 . V_130 = sizeof( T_8 ) ;
V_120 . V_134 [ 8 ] = V_120 . V_130 ;
return F_86 ( V_3 , & V_120 ) ;
}
static T_4 int F_160 ( struct V_2 * V_3 ,
long * V_263 )
{
T_5 V_256 ;
T_8 V_260 ;
T_9 V_264 ;
int V_57 = - 1 ;
if ( ( V_57 = F_157 ( V_3 , & V_256 ) ) )
return V_57 ;
V_264 = ( V_256 . V_265 << 8 ) | V_256 . V_266 ;
if ( ( V_57 = F_159 ( V_3 , V_264 , 1 , & V_260 ) ) )
return V_57 ;
if ( V_260 . V_267 ) {
V_264 -- ;
if ( ( V_57 = F_159 ( V_3 , V_264 , 1 , & V_260 ) ) )
return V_57 ;
}
if ( V_260 . V_268 ) {
* V_263 = F_161 ( V_260 . V_269 ) ;
} else {
* V_263 = F_161 ( V_260 . V_270 ) +
F_161 ( V_260 . V_271 ) ;
if ( V_260 . V_272 )
* V_263 -= ( F_161 ( V_260 . V_272 ) + 7 ) ;
}
return 0 ;
}
static T_4 int F_162 ( struct V_2 * V_3 )
{
struct V_119 V_120 ;
struct V_147 V_148 ;
T_10 * V_273 ;
char V_131 [ 128 ] ;
int V_57 , V_106 ;
if ( ( V_3 -> V_274 == 0x1a ) || ( V_3 -> V_274 == 0x12 ) )
return 0 ;
memset ( V_131 , 0 , sizeof( V_131 ) ) ;
F_95 ( & V_120 , V_131 , sizeof( * V_273 ) , V_254 ) ;
V_120 . V_148 = & V_148 ;
if ( ( V_57 = F_155 ( V_3 , & V_120 , V_275 , 0 ) ) ) {
F_93 ( & V_120 ) ;
return V_57 ;
}
V_106 = 2 + ( ( V_131 [ 0 ] << 8 ) | ( V_131 [ 1 ] & 0xff ) ) ;
V_3 -> V_276 = ( V_131 [ 6 ] << 8 ) | ( V_131 [ 7 ] & 0xff ) ;
if ( V_106 > sizeof( V_131 ) )
V_106 = sizeof( V_131 ) ;
F_95 ( & V_120 , V_131 , V_106 , V_254 ) ;
V_120 . V_148 = & V_148 ;
if ( ( V_57 = F_155 ( V_3 , & V_120 , V_275 , 0 ) ) ) {
F_93 ( & V_120 ) ;
return V_57 ;
}
V_273 = ( T_10 * ) & V_131 [ sizeof( struct V_277 ) + V_3 -> V_276 ] ;
V_273 -> V_249 = V_3 -> V_105 . V_249 ;
V_273 -> V_278 = V_3 -> V_105 . V_278 ;
V_273 -> V_279 = V_3 -> V_105 . V_279 ;
V_273 -> V_280 = V_3 -> V_105 . V_250 ;
V_273 -> V_281 = 0 ;
#ifdef F_163
V_273 -> V_282 = 7 ;
V_273 -> V_283 = 1 ;
#endif
if ( V_273 -> V_280 == V_284 ) {
V_273 -> V_285 = 0 ;
V_273 -> V_286 = 0x20 ;
} else if ( V_273 -> V_280 == V_287 ) {
V_273 -> V_285 = 0x20 ;
V_273 -> V_286 = 8 ;
#if 0
wp->mcn[0] = 0x80;
memcpy(&wp->mcn[1], PACKET_MCN, sizeof(wp->mcn) - 1);
#endif
} else {
F_37 ( V_59 L_70 , V_273 -> V_280 ) ;
return 1 ;
}
V_273 -> V_288 = F_164 ( V_3 -> V_105 . V_106 >> 2 ) ;
V_120 . V_130 = V_120 . V_134 [ 8 ] = V_106 ;
if ( ( V_57 = F_156 ( V_3 , & V_120 ) ) ) {
F_93 ( & V_120 ) ;
return V_57 ;
}
F_154 ( V_3 ) ;
return 0 ;
}
static int F_165 ( struct V_2 * V_3 , T_8 * V_260 )
{
switch ( V_3 -> V_274 ) {
case 0x1a :
case 0x12 :
return 1 ;
default:
break;
}
if ( ! V_260 -> V_289 || ! V_260 -> V_249 )
return 0 ;
if ( V_260 -> V_290 == 0 && V_260 -> V_267 == 0 )
return 1 ;
if ( V_260 -> V_290 == 0 && V_260 -> V_267 == 1 )
return 1 ;
if ( V_260 -> V_290 == 1 && V_260 -> V_267 == 0 )
return 1 ;
F_37 ( V_59 L_71 , V_260 -> V_290 , V_260 -> V_267 , V_260 -> V_289 ) ;
return 0 ;
}
static int F_166 ( struct V_2 * V_3 , T_5 * V_256 )
{
switch ( V_3 -> V_274 ) {
case 0x0a :
case 0xffff :
break;
case 0x1a :
case 0x13 :
case 0x12 :
return 1 ;
default:
F_55 ( V_59 L_72 , V_3 -> V_274 ) ;
return 0 ;
}
if ( V_256 -> V_291 == 0xff ) {
F_37 ( V_59 L_73 ) ;
return 0 ;
}
if ( V_256 -> V_291 != 0x20 && V_256 -> V_291 != 0 ) {
F_37 ( V_59 L_74 , V_256 -> V_291 ) ;
return 0 ;
}
if ( V_256 -> V_292 == 0 ) {
F_37 ( V_59 L_75 ) ;
return 0 ;
}
if ( V_256 -> V_293 == V_294 ) {
F_37 ( V_59 L_76 ) ;
return 0 ;
}
return 1 ;
}
static T_4 int F_167 ( struct V_2 * V_3 )
{
struct V_119 V_120 ;
unsigned char V_50 [ 12 ] ;
T_5 V_256 ;
T_8 V_260 ;
int V_57 , V_259 ;
F_95 ( & V_120 , V_50 , sizeof( V_50 ) , V_254 ) ;
V_120 . V_134 [ 0 ] = V_295 ;
V_120 . V_134 [ 8 ] = 8 ;
V_57 = F_86 ( V_3 , & V_120 ) ;
V_3 -> V_274 = V_57 ? 0xffff : V_50 [ 6 ] << 8 | V_50 [ 7 ] ;
memset ( & V_256 , 0 , sizeof( T_5 ) ) ;
memset ( & V_260 , 0 , sizeof( T_8 ) ) ;
if ( ( V_57 = F_157 ( V_3 , & V_256 ) ) ) {
F_37 ( L_77 ) ;
return V_57 ;
}
if ( ! F_166 ( V_3 , & V_256 ) )
return - V_296 ;
V_3 -> type = V_256 . V_292 ? V_297 : V_298 ;
V_259 = 1 ;
if ( ( V_57 = F_159 ( V_3 , V_259 , 1 , & V_260 ) ) ) {
F_37 ( V_59 L_78 ) ;
return V_57 ;
}
if ( ! F_165 ( V_3 , & V_260 ) ) {
F_37 ( V_59 L_79 ) ;
return - V_296 ;
}
V_3 -> V_105 . V_106 = F_161 ( V_260 . V_299 ) << 2 ;
if ( V_3 -> V_105 . V_106 == 0 ) {
F_37 ( V_59 L_80 ) ;
return - V_300 ;
}
if ( V_3 -> V_105 . V_106 > V_301 ) {
F_37 ( V_59 L_81 ) ;
return - V_296 ;
}
V_3 -> V_105 . V_249 = V_260 . V_249 ;
V_3 -> V_201 = ( F_161 ( V_260 . V_270 ) << 2 ) & ( V_3 -> V_105 . V_106 - 1 ) ;
if ( V_260 . V_302 ) {
V_3 -> V_303 = F_161 ( V_260 . V_304 ) ;
F_110 ( V_305 , & V_3 -> V_170 ) ;
}
if ( V_260 . V_268 ) {
V_3 -> V_306 = F_161 ( V_260 . V_269 ) ;
F_110 ( V_307 , & V_3 -> V_170 ) ;
} else {
V_3 -> V_306 = 0xffffffff ;
F_110 ( V_307 , & V_3 -> V_170 ) ;
}
V_3 -> V_105 . V_308 = 7 ;
V_3 -> V_105 . V_279 = 0 ;
V_3 -> V_105 . V_278 = V_260 . V_278 ;
switch ( V_260 . V_309 ) {
case V_310 :
V_3 -> V_105 . V_250 = V_284 ;
break;
case V_311 :
V_3 -> V_105 . V_250 = V_287 ;
break;
default:
F_37 ( V_59 L_82 ) ;
return - V_296 ;
}
return 0 ;
}
static T_4 int F_168 ( struct V_2 * V_3 ,
int V_312 )
{
struct V_119 V_120 ;
struct V_147 V_148 ;
unsigned char V_50 [ 64 ] ;
int V_57 ;
F_95 ( & V_120 , V_50 , sizeof( V_50 ) , V_254 ) ;
V_120 . V_148 = & V_148 ;
V_120 . V_130 = V_3 -> V_276 + 12 ;
V_120 . V_140 = 1 ;
if ( ( V_57 = F_155 ( V_3 , & V_120 , V_313 , 0 ) ) )
return V_57 ;
V_50 [ V_3 -> V_276 + 10 ] |= ( ! ! V_312 << 2 ) ;
V_120 . V_130 = V_120 . V_134 [ 8 ] = 2 + ( ( V_50 [ 0 ] << 8 ) | ( V_50 [ 1 ] & 0xff ) ) ;
V_57 = F_156 ( V_3 , & V_120 ) ;
if ( V_57 ) {
F_37 ( V_59 L_83 ) ;
F_93 ( & V_120 ) ;
} else if ( ! V_57 && V_312 )
F_37 ( V_59 L_84 , V_3 -> V_4 ) ;
return V_57 ;
}
static int F_169 ( struct V_2 * V_3 , int V_314 )
{
struct V_119 V_120 ;
F_95 ( & V_120 , NULL , 0 , V_152 ) ;
V_120 . V_134 [ 0 ] = V_315 ;
V_120 . V_134 [ 4 ] = V_314 ? 1 : 0 ;
return F_86 ( V_3 , & V_120 ) ;
}
static T_4 int F_170 ( struct V_2 * V_3 ,
unsigned * V_154 )
{
struct V_119 V_120 ;
struct V_147 V_148 ;
unsigned char V_50 [ 256 + 18 ] ;
unsigned char * V_316 ;
int V_57 , V_201 ;
V_316 = & V_50 [ sizeof( struct V_277 ) + V_3 -> V_276 ] ;
F_95 ( & V_120 , V_50 , sizeof( V_50 ) , V_317 ) ;
V_120 . V_148 = & V_148 ;
V_57 = F_155 ( V_3 , & V_120 , V_318 , 0 ) ;
if ( V_57 ) {
V_120 . V_130 = V_3 -> V_276 + V_316 [ 1 ] + 2 +
sizeof( struct V_277 ) ;
V_57 = F_155 ( V_3 , & V_120 , V_318 , 0 ) ;
if ( V_57 ) {
F_93 ( & V_120 ) ;
return V_57 ;
}
}
V_201 = 20 ;
if ( V_316 [ 1 ] >= 28 )
V_201 = 28 ;
if ( V_316 [ 1 ] >= 30 ) {
int V_319 = ( V_316 [ 30 ] << 8 ) + V_316 [ 31 ] ;
if ( V_319 > 0 )
V_201 = 34 ;
}
* V_154 = ( V_316 [ V_201 ] << 8 ) | V_316 [ V_201 + 1 ] ;
return 0 ;
}
static T_4 int F_171 ( struct V_2 * V_3 ,
unsigned * V_320 )
{
struct V_119 V_120 ;
struct V_147 V_148 ;
unsigned char V_50 [ 64 ] ;
unsigned int V_106 , V_321 , V_322 ;
int V_57 ;
F_95 ( & V_120 , V_50 , 2 , V_254 ) ;
V_120 . V_148 = & V_148 ;
V_120 . V_134 [ 0 ] = V_323 ;
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
F_95 ( & V_120 , V_50 , V_106 , V_254 ) ;
V_120 . V_148 = & V_148 ;
V_120 . V_134 [ 0 ] = V_323 ;
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
V_321 = ( V_50 [ 6 ] >> 3 ) & 0x7 ;
V_322 = V_50 [ 16 ] & 0xf ;
switch ( V_321 ) {
case 0 :
* V_320 = V_324 [ V_322 ] ;
break;
case 1 :
* V_320 = V_325 [ V_322 ] ;
break;
case 2 :
* V_320 = V_326 [ V_322 ] ;
break;
default:
F_37 ( V_59 L_87 , V_321 ) ;
return 1 ;
}
if ( * V_320 ) {
F_37 ( V_59 L_88 , * V_320 ) ;
return 0 ;
} else {
F_37 ( V_59 L_89 , V_322 , V_321 ) ;
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
V_120 . V_134 [ 0 ] = V_327 ;
V_120 . V_134 [ 1 ] = 1 ;
if ( ( V_57 = F_86 ( V_3 , & V_120 ) ) )
F_93 ( & V_120 ) ;
return V_57 ;
}
static int F_173 ( struct V_2 * V_3 )
{
int V_57 ;
unsigned int V_154 , V_328 , V_155 ;
if ( ( V_57 = F_167 ( V_3 ) ) ) {
F_55 ( V_59 L_91 , V_3 -> V_4 ) ;
return V_57 ;
}
if ( ( V_57 = F_162 ( V_3 ) ) ) {
F_174 ( V_59 L_92 , V_3 -> V_4 ) ;
return - V_145 ;
}
F_168 ( V_3 , V_329 ) ;
if ( ( V_57 = F_170 ( V_3 , & V_154 ) ) )
V_154 = 16 * 177 ;
switch ( V_3 -> V_274 ) {
case 0x13 :
case 0x1a :
case 0x12 :
F_174 ( V_59 L_93 , V_154 ) ;
break;
default:
if ( ( V_57 = F_171 ( V_3 , & V_328 ) ) )
V_328 = 16 ;
V_154 = F_15 ( V_154 , V_328 * 177 ) ;
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
static int F_175 ( struct V_2 * V_3 , T_11 V_330 )
{
int V_57 ;
long V_331 ;
struct V_121 * V_122 ;
F_176 ( V_3 -> V_48 -> V_49 ) ;
if ( ( V_57 = F_177 ( V_3 -> V_48 , V_332 | V_333 , V_3 ) ) )
goto V_132;
if ( ( V_57 = F_160 ( V_3 , & V_331 ) ) ) {
F_37 ( V_59 L_97 ) ;
goto V_334;
}
F_178 ( V_3 -> V_217 , V_331 << 2 ) ;
F_178 ( V_3 -> V_48 -> V_143 , V_331 << 2 ) ;
F_179 ( V_3 -> V_48 , ( V_335 ) V_331 << 11 ) ;
V_122 = F_87 ( V_3 -> V_48 ) ;
if ( V_330 ) {
if ( ( V_57 = F_173 ( V_3 ) ) )
goto V_334;
F_180 ( V_122 -> V_336 ) ;
F_181 ( V_122 , V_3 -> V_105 . V_106 ) ;
F_182 ( V_122 -> V_336 ) ;
F_110 ( V_337 , & V_3 -> V_170 ) ;
} else {
F_96 ( V_3 , V_167 , V_167 ) ;
F_109 ( V_337 , & V_3 -> V_170 ) ;
}
if ( ( V_57 = F_107 ( V_3 , V_122 ) ) )
goto V_334;
if ( V_330 ) {
if ( ! F_74 ( V_3 , V_338 ) ) {
F_37 ( V_59 L_98 ) ;
V_57 = - V_58 ;
goto V_334;
}
F_37 ( V_59 L_99 , V_331 << 1 ) ;
}
return 0 ;
V_334:
F_183 ( V_3 -> V_48 , V_332 | V_333 ) ;
V_132:
return V_57 ;
}
static void F_184 ( struct V_2 * V_3 , int V_339 )
{
if ( V_339 && F_94 ( V_3 ) )
F_174 ( V_59 L_100 , V_3 -> V_4 ) ;
F_169 ( V_3 , 0 ) ;
F_96 ( V_3 , V_167 , V_167 ) ;
F_183 ( V_3 -> V_48 , V_332 | V_333 ) ;
F_70 ( V_3 ) ;
}
static struct V_2 * F_185 ( unsigned int V_340 )
{
if ( V_340 >= V_45 )
return NULL ;
return V_46 [ V_340 ] ;
}
static int F_186 ( struct V_341 * V_48 , T_11 V_342 )
{
struct V_2 * V_3 = NULL ;
int V_57 ;
F_55 ( V_59 L_101 ) ;
F_187 ( & V_343 ) ;
F_187 ( & V_43 ) ;
V_3 = F_185 ( F_27 ( V_48 -> V_49 ) ) ;
if ( ! V_3 ) {
V_57 = - V_55 ;
goto V_132;
}
F_52 ( V_3 -> V_344 < 0 ) ;
V_3 -> V_344 ++ ;
if ( V_3 -> V_344 > 1 ) {
if ( ( V_342 & V_345 ) &&
! F_137 ( V_337 , & V_3 -> V_170 ) ) {
V_57 = - V_346 ;
goto V_347;
}
} else {
V_57 = F_175 ( V_3 , V_342 & V_345 ) ;
if ( V_57 )
goto V_347;
F_188 ( V_48 , V_168 ) ;
}
F_28 ( & V_43 ) ;
F_28 ( & V_343 ) ;
return 0 ;
V_347:
V_3 -> V_344 -- ;
V_132:
F_55 ( V_59 L_102 , V_57 ) ;
F_28 ( & V_43 ) ;
F_28 ( & V_343 ) ;
return V_57 ;
}
static int F_189 ( struct V_348 * V_217 , T_11 V_342 )
{
struct V_2 * V_3 = V_217 -> V_349 ;
int V_57 = 0 ;
F_187 ( & V_343 ) ;
F_187 ( & V_43 ) ;
V_3 -> V_344 -- ;
F_52 ( V_3 -> V_344 < 0 ) ;
if ( V_3 -> V_344 == 0 ) {
int V_339 = F_137 ( V_337 , & V_3 -> V_170 ) ;
F_184 ( V_3 , V_339 ) ;
}
F_28 ( & V_43 ) ;
F_28 ( & V_343 ) ;
return V_57 ;
}
static void F_190 ( struct V_79 * V_79 , int V_187 )
{
struct V_350 * V_351 = V_79 -> V_188 ;
struct V_2 * V_3 = V_351 -> V_3 ;
F_67 ( V_79 ) ;
F_139 ( V_351 -> V_79 , V_187 ) ;
F_81 ( V_351 , V_352 ) ;
F_51 ( V_3 ) ;
}
static void F_191 ( struct V_121 * V_122 , struct V_79 * V_79 )
{
struct V_2 * V_3 ;
char V_353 [ V_354 ] ;
T_3 V_205 ;
struct V_88 * V_91 ;
int V_355 , V_356 ;
struct V_109 * V_110 ;
V_3 = V_122 -> V_357 ;
if ( ! V_3 ) {
F_37 ( V_59 L_103 , F_192 ( V_79 -> V_202 , V_353 ) ) ;
goto V_358;
}
if ( F_98 ( V_79 ) == V_128 ) {
struct V_79 * V_359 = F_193 ( V_79 , V_360 ) ;
struct V_350 * V_351 = F_194 ( V_352 , V_360 ) ;
V_351 -> V_3 = V_3 ;
V_351 -> V_79 = V_79 ;
V_359 -> V_202 = V_3 -> V_48 ;
V_359 -> V_188 = V_351 ;
V_359 -> V_203 = F_190 ;
V_3 -> V_18 . V_22 += V_79 -> V_165 >> 9 ;
F_97 ( V_3 , V_359 ) ;
return;
}
if ( ! F_137 ( V_337 , & V_3 -> V_170 ) ) {
F_37 ( V_59 L_104 ,
V_3 -> V_4 , ( unsigned long long ) V_79 -> V_116 ) ;
goto V_358;
}
if ( ! V_79 -> V_165 || ( V_79 -> V_165 % V_168 ) ) {
F_37 ( V_59 L_105 ) ;
goto V_358;
}
F_195 ( V_122 , & V_79 ) ;
V_205 = F_134 ( V_79 -> V_116 , V_3 ) ;
F_55 ( L_106 ,
( unsigned long long ) V_79 -> V_116 ,
( unsigned long long ) ( V_79 -> V_116 + F_104 ( V_79 ) ) ) ;
{
struct V_361 * V_362 ;
T_3 V_363 ;
int V_364 ;
V_363 = F_134 ( V_79 -> V_116 + F_104 ( V_79 ) - 1 , V_3 ) ;
if ( V_363 != V_205 ) {
F_52 ( V_363 != V_205 + V_3 -> V_105 . V_106 ) ;
V_364 = V_363 - V_79 -> V_116 ;
V_362 = F_196 ( V_79 , V_364 ) ;
F_52 ( ! V_362 ) ;
F_191 ( V_122 , & V_362 -> V_365 ) ;
F_191 ( V_122 , & V_362 -> V_366 ) ;
F_197 ( V_362 ) ;
return;
}
}
F_11 ( & V_3 -> V_74 . V_224 ) ;
V_356 = 0 ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_91 -> V_189 == V_205 ) {
F_11 ( & V_91 -> V_24 ) ;
if ( ( V_91 -> V_207 == V_223 ) ||
( V_91 -> V_207 == V_232 ) ) {
F_99 ( & V_91 -> V_98 , V_79 ) ;
V_91 -> V_216 += V_79 -> V_165 / V_168 ;
if ( ( V_91 -> V_216 >= V_91 -> V_89 ) &&
( V_91 -> V_207 == V_223 ) ) {
F_105 ( & V_91 -> V_192 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
F_12 ( & V_91 -> V_24 ) ;
F_12 ( & V_3 -> V_74 . V_224 ) ;
return;
} else {
V_356 = 1 ;
}
F_12 ( & V_91 -> V_24 ) ;
}
}
F_12 ( & V_3 -> V_74 . V_224 ) ;
F_11 ( & V_3 -> V_24 ) ;
if ( V_3 -> V_27 > 0
&& V_3 -> V_25 >= V_3 -> V_27 ) {
F_198 ( & V_122 -> V_219 , V_220 ) ;
do {
F_12 ( & V_3 -> V_24 ) ;
F_199 ( V_220 , V_137 ) ;
F_11 ( & V_3 -> V_24 ) ;
} while( V_3 -> V_25 > V_3 -> V_26 );
}
F_12 ( & V_3 -> V_24 ) ;
V_110 = F_194 ( V_3 -> V_113 , V_360 ) ;
V_110 -> V_79 = V_79 ;
F_11 ( & V_3 -> V_24 ) ;
F_52 ( V_3 -> V_25 < 0 ) ;
V_355 = ( V_3 -> V_25 == 0 ) ;
F_83 ( V_3 , V_110 ) ;
F_12 ( & V_3 -> V_24 ) ;
F_56 ( & V_3 -> V_213 , 1 ) ;
if ( V_355 ) {
F_57 ( & V_3 -> V_78 ) ;
} else if ( ! F_71 ( & V_3 -> V_74 . V_103 ) && ! V_356 ) {
F_57 ( & V_3 -> V_78 ) ;
}
return;
V_358:
F_200 ( V_79 ) ;
}
static int F_201 ( struct V_121 * V_122 , struct V_367 * V_368 ,
struct V_82 * V_185 )
{
struct V_2 * V_3 = V_122 -> V_357 ;
T_3 V_205 = F_134 ( V_368 -> V_116 , V_3 ) ;
int V_369 = ( ( V_368 -> V_116 - V_205 ) << 9 ) + V_368 -> V_165 ;
int V_370 = ( V_3 -> V_105 . V_106 << 9 ) - V_369 ;
int V_371 ;
V_371 = V_171 - V_368 -> V_165 ;
V_370 = F_14 ( V_370 , V_371 ) ;
F_52 ( V_370 < 0 ) ;
return V_370 ;
}
static void F_202 ( struct V_2 * V_3 )
{
struct V_121 * V_122 = V_3 -> V_217 -> V_218 ;
F_203 ( V_122 , F_191 ) ;
F_204 ( V_122 , V_168 ) ;
F_181 ( V_122 , V_301 ) ;
F_205 ( V_122 , F_201 ) ;
V_122 -> V_357 = V_3 ;
}
static int F_41 ( struct V_64 * V_65 , void * V_9 )
{
struct V_2 * V_3 = V_65 -> V_372 ;
char * V_373 ;
char V_374 [ V_354 ] ;
int V_238 [ V_239 ] ;
F_206 ( V_65 , L_107 , V_3 -> V_4 ,
F_192 ( V_3 -> V_48 , V_374 ) ) ;
F_206 ( V_65 , L_108 ) ;
F_206 ( V_65 , L_109 , V_3 -> V_105 . V_106 / 2 ) ;
if ( V_3 -> V_105 . V_279 == 0 )
V_373 = L_110 ;
else
V_373 = L_111 ;
F_206 ( V_65 , L_112 , V_373 ) ;
F_206 ( V_65 , L_113 , V_3 -> V_105 . V_249 ? L_66 : L_67 ) ;
F_206 ( V_65 , L_114 , V_3 -> V_105 . V_308 ) ;
F_206 ( V_65 , L_115 , V_3 -> V_105 . V_278 ) ;
if ( V_3 -> V_105 . V_250 == V_284 )
V_373 = L_116 ;
else if ( V_3 -> V_105 . V_250 == V_287 )
V_373 = L_117 ;
else
V_373 = L_111 ;
F_206 ( V_65 , L_118 , V_373 ) ;
F_206 ( V_65 , L_119 ) ;
F_206 ( V_65 , L_120 , V_3 -> V_18 . V_19 ) ;
F_206 ( V_65 , L_121 , V_3 -> V_18 . V_20 ) ;
F_206 ( V_65 , L_122 , V_3 -> V_18 . V_21 >> 1 ) ;
F_206 ( V_65 , L_123 , V_3 -> V_18 . V_23 >> 1 ) ;
F_206 ( V_65 , L_124 , V_3 -> V_18 . V_22 >> 1 ) ;
F_206 ( V_65 , L_125 ) ;
F_206 ( V_65 , L_126 , V_3 -> V_344 ) ;
F_206 ( V_65 , L_127 , V_3 -> V_170 ) ;
F_206 ( V_65 , L_128 , V_3 -> V_155 ) ;
F_206 ( V_65 , L_129 , V_3 -> V_154 ) ;
F_206 ( V_65 , L_130 , V_3 -> V_201 ) ;
F_206 ( V_65 , L_131 , V_3 -> V_276 ) ;
F_206 ( V_65 , L_132 ) ;
F_206 ( V_65 , L_133 , V_3 -> V_25 ) ;
F_206 ( V_65 , L_134 , F_53 ( & V_3 -> V_74 . V_75 ) ) ;
F_206 ( V_65 , L_135 , ( unsigned long long ) V_3 -> V_214 ) ;
F_143 ( V_3 , V_238 ) ;
F_206 ( V_65 , L_136 ,
V_238 [ 0 ] , V_238 [ 1 ] , V_238 [ 2 ] , V_238 [ 3 ] , V_238 [ 4 ] , V_238 [ 5 ] ) ;
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
char V_353 [ V_354 ] ;
struct V_341 * V_48 ;
if ( V_3 -> V_47 == V_33 ) {
F_37 ( V_59 L_138 ) ;
return - V_346 ;
}
for ( V_90 = 0 ; V_90 < V_45 ; V_90 ++ ) {
struct V_2 * V_375 = V_46 [ V_90 ] ;
if ( ! V_375 )
continue;
if ( V_375 -> V_48 -> V_49 == V_33 ) {
F_37 ( V_59 L_139 , F_192 ( V_375 -> V_48 , V_353 ) ) ;
return - V_346 ;
}
if ( V_375 -> V_47 == V_33 ) {
F_37 ( V_59 L_140 ) ;
return - V_346 ;
}
}
V_48 = F_176 ( V_33 ) ;
if ( ! V_48 )
return - V_58 ;
V_57 = F_177 ( V_48 , V_332 | V_376 , NULL ) ;
if ( V_57 )
return V_57 ;
F_210 ( V_54 ) ;
V_3 -> V_48 = V_48 ;
F_188 ( V_48 , V_168 ) ;
F_202 ( V_3 ) ;
F_56 ( & V_3 -> V_74 . V_75 , 0 ) ;
V_3 -> V_74 . V_377 = F_211 ( F_144 , V_3 , L_1 , V_3 -> V_4 ) ;
if ( F_20 ( V_3 -> V_74 . V_377 ) ) {
F_37 ( V_59 L_141 ) ;
V_57 = - V_58 ;
goto V_378;
}
F_212 ( V_3 -> V_4 , 0 , V_379 , & V_380 , V_3 ) ;
F_174 ( V_59 L_142 , V_3 -> V_4 , F_192 ( V_48 , V_353 ) ) ;
return 0 ;
V_378:
F_183 ( V_48 , V_332 | V_376 ) ;
F_32 ( V_54 ) ;
return V_57 ;
}
static int F_213 ( struct V_341 * V_48 , T_11 V_342 , unsigned int V_134 , unsigned long V_381 )
{
struct V_2 * V_3 = V_48 -> V_143 -> V_349 ;
int V_57 ;
F_55 ( L_143 , V_134 ,
F_26 ( V_48 -> V_49 ) , F_27 ( V_48 -> V_49 ) ) ;
F_187 ( & V_343 ) ;
switch ( V_134 ) {
case V_382 :
if ( V_3 -> V_344 == 1 )
F_169 ( V_3 , 0 ) ;
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
V_57 = F_214 ( V_3 -> V_48 , V_342 , V_134 , V_381 ) ;
break;
default:
F_55 ( V_59 L_144 , V_3 -> V_4 , V_134 ) ;
V_57 = - V_388 ;
}
F_28 ( & V_343 ) ;
return V_57 ;
}
static unsigned int F_215 ( struct V_348 * V_217 ,
unsigned int V_389 )
{
struct V_2 * V_3 = V_217 -> V_349 ;
struct V_348 * V_390 ;
if ( ! V_3 )
return 0 ;
if ( ! V_3 -> V_48 )
return 0 ;
V_390 = V_3 -> V_48 -> V_143 ;
if ( ! V_390 || ! V_390 -> V_391 -> V_392 )
return 0 ;
return V_390 -> V_391 -> V_392 ( V_390 , V_389 ) ;
}
static char * F_216 ( struct V_348 * V_393 , T_13 * V_342 )
{
return F_217 ( V_10 , L_145 , V_393 -> V_394 ) ;
}
static int F_31 ( T_12 V_33 , T_12 * V_47 )
{
int V_42 ;
int V_57 = - V_58 ;
struct V_2 * V_3 ;
struct V_348 * V_217 ;
F_25 ( & V_43 , V_44 ) ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ )
if ( ! V_46 [ V_42 ] )
break;
if ( V_42 == V_45 ) {
F_37 ( V_59 L_146 , V_45 ) ;
V_57 = - V_346 ;
goto V_395;
}
V_3 = F_2 ( sizeof( struct V_2 ) , V_10 ) ;
if ( ! V_3 )
goto V_395;
V_3 -> V_113 = F_218 ( V_396 ,
sizeof( struct V_109 ) ) ;
if ( ! V_3 -> V_113 )
goto V_378;
F_73 ( & V_3 -> V_74 . V_103 ) ;
F_73 ( & V_3 -> V_74 . V_102 ) ;
F_65 ( & V_3 -> V_74 . V_224 ) ;
F_65 ( & V_3 -> V_24 ) ;
F_65 ( & V_3 -> V_76 . V_24 ) ;
F_66 ( & V_3 -> V_76 . V_157 ) ;
F_66 ( & V_3 -> V_76 . V_158 ) ;
sprintf ( V_3 -> V_4 , V_59 L_13 , V_42 ) ;
F_219 ( & V_3 -> V_78 ) ;
V_3 -> V_112 = V_397 ;
V_3 -> V_27 = V_27 ;
V_3 -> V_26 = V_26 ;
V_217 = F_220 ( 1 ) ;
if ( ! V_217 )
goto V_378;
V_3 -> V_217 = V_217 ;
V_217 -> V_52 = V_398 ;
V_217 -> V_399 = V_42 ;
V_217 -> V_391 = & V_400 ;
V_217 -> V_170 = V_401 ;
strcpy ( V_217 -> V_394 , V_3 -> V_4 ) ;
V_217 -> V_402 = F_216 ;
V_217 -> V_349 = V_3 ;
V_217 -> V_218 = F_221 ( V_10 ) ;
if ( ! V_217 -> V_218 )
goto V_403;
V_3 -> V_47 = F_19 ( V_398 , V_42 ) ;
V_57 = F_209 ( V_3 , V_33 ) ;
if ( V_57 )
goto V_404;
V_217 -> V_405 = V_3 -> V_48 -> V_143 -> V_405 ;
V_217 -> V_406 = V_3 -> V_48 -> V_143 -> V_406 ;
F_222 ( V_217 ) ;
F_17 ( V_3 ) ;
F_44 ( V_3 ) ;
V_46 [ V_42 ] = V_3 ;
if ( V_47 )
* V_47 = V_3 -> V_47 ;
F_28 ( & V_43 ) ;
return 0 ;
V_404:
F_223 ( V_217 -> V_218 ) ;
V_403:
F_224 ( V_217 ) ;
V_378:
if ( V_3 -> V_113 )
F_225 ( V_3 -> V_113 ) ;
F_8 ( V_3 ) ;
V_395:
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
V_57 = - V_300 ;
goto V_132;
}
if ( V_3 -> V_344 > 0 ) {
V_57 = - V_346 ;
goto V_132;
}
if ( ! F_20 ( V_3 -> V_74 . V_377 ) )
F_226 ( V_3 -> V_74 . V_377 ) ;
V_46 [ V_42 ] = NULL ;
F_47 ( V_3 ) ;
F_21 ( V_3 ) ;
F_183 ( V_3 -> V_48 , V_332 | V_376 ) ;
F_227 ( V_3 -> V_4 , V_379 ) ;
F_174 ( V_59 L_149 , V_3 -> V_4 ) ;
F_228 ( V_3 -> V_217 ) ;
F_223 ( V_3 -> V_217 -> V_218 ) ;
F_224 ( V_3 -> V_217 ) ;
F_225 ( V_3 -> V_113 ) ;
F_8 ( V_3 ) ;
F_32 ( V_54 ) ;
V_132:
F_28 ( & V_43 ) ;
return V_57 ;
}
static void F_229 ( struct V_407 * V_408 )
{
struct V_2 * V_3 ;
F_25 ( & V_43 , V_44 ) ;
V_3 = F_185 ( V_408 -> V_409 ) ;
if ( V_3 ) {
V_408 -> V_33 = F_230 ( V_3 -> V_48 -> V_49 ) ;
V_408 -> V_47 = F_230 ( V_3 -> V_47 ) ;
} else {
V_408 -> V_33 = 0 ;
V_408 -> V_47 = 0 ;
}
V_408 -> V_410 = V_45 ;
F_28 ( & V_43 ) ;
}
static long F_231 ( struct V_67 * V_67 , unsigned int V_134 , unsigned long V_381 )
{
void T_14 * V_411 = ( void T_14 * ) V_381 ;
struct V_407 V_408 ;
int V_57 = 0 ;
T_12 V_47 = 0 ;
if ( V_134 != V_412 )
return - V_388 ;
if ( F_232 ( & V_408 , V_411 , sizeof( struct V_407 ) ) )
return - V_413 ;
switch ( V_408 . V_414 ) {
case V_415 :
if ( ! F_233 ( V_416 ) )
return - V_417 ;
V_57 = F_31 ( F_234 ( V_408 . V_33 ) , & V_47 ) ;
V_408 . V_47 = F_230 ( V_47 ) ;
break;
case V_418 :
if ( ! F_233 ( V_416 ) )
return - V_417 ;
V_57 = F_34 ( F_234 ( V_408 . V_47 ) ) ;
break;
case V_419 :
F_229 ( & V_408 ) ;
break;
default:
return - V_388 ;
}
if ( F_235 ( V_411 , & V_408 , sizeof( struct V_407 ) ) )
return - V_413 ;
return V_57 ;
}
static long F_236 ( struct V_67 * V_67 , unsigned int V_134 , unsigned long V_381 )
{
return F_231 ( V_67 , V_134 , ( unsigned long ) F_237 ( V_381 ) ) ;
}
static int T_15 F_238 ( void )
{
int V_57 ;
F_239 ( & V_43 ) ;
V_352 = F_218 ( V_420 ,
sizeof( struct V_350 ) ) ;
if ( ! V_352 )
return - V_58 ;
V_57 = F_240 ( V_398 , V_59 ) ;
if ( V_57 < 0 ) {
F_37 ( V_59 L_150 ) ;
goto V_421;
}
if ( ! V_398 )
V_398 = V_57 ;
V_57 = F_35 () ;
if ( V_57 )
goto V_132;
F_49 () ;
V_57 = F_241 ( & V_422 ) ;
if ( V_57 ) {
F_37 ( V_59 L_151 ) ;
goto V_423;
}
V_379 = F_242 ( L_152 V_59 , NULL ) ;
return 0 ;
V_423:
F_50 () ;
F_38 () ;
V_132:
F_243 ( V_398 , V_59 ) ;
V_421:
F_225 ( V_352 ) ;
return V_57 ;
}
static void T_16 F_244 ( void )
{
F_227 ( L_152 V_59 , NULL ) ;
F_245 ( & V_422 ) ;
F_50 () ;
F_38 () ;
F_243 ( V_398 , V_59 ) ;
F_225 ( V_352 ) ;
}
