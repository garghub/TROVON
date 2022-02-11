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
static struct V_79 * F_58 ( int V_80 )
{
int V_81 ;
struct V_79 * V_82 ;
V_82 = F_2 ( sizeof( struct V_79 ) , V_10 ) ;
if ( ! V_82 )
goto V_83;
V_82 -> V_80 = V_80 ;
V_82 -> V_84 = F_59 ( V_10 , V_80 ) ;
if ( ! V_82 -> V_84 )
goto V_85;
for ( V_81 = 0 ; V_81 < V_80 / V_86 ; V_81 ++ ) {
V_82 -> V_87 [ V_81 ] = F_60 ( V_10 | V_88 ) ;
if ( ! V_82 -> V_87 [ V_81 ] )
goto V_89;
}
F_61 ( & V_82 -> V_24 ) ;
F_62 ( & V_82 -> V_90 ) ;
for ( V_81 = 0 ; V_81 < V_80 ; V_81 ++ ) {
struct V_91 * V_91 = F_59 ( V_10 , 1 ) ;
if ( ! V_91 )
goto V_92;
V_82 -> V_93 [ V_81 ] = V_91 ;
}
return V_82 ;
V_92:
for ( V_81 = 0 ; V_81 < V_80 ; V_81 ++ ) {
struct V_91 * V_91 = V_82 -> V_93 [ V_81 ] ;
if ( V_91 )
F_63 ( V_91 ) ;
}
V_89:
for ( V_81 = 0 ; V_81 < V_80 / V_86 ; V_81 ++ )
if ( V_82 -> V_87 [ V_81 ] )
F_64 ( V_82 -> V_87 [ V_81 ] ) ;
F_63 ( V_82 -> V_84 ) ;
V_85:
F_8 ( V_82 ) ;
V_83:
return NULL ;
}
static void F_65 ( struct V_79 * V_82 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_82 -> V_80 ; V_81 ++ ) {
struct V_91 * V_91 = V_82 -> V_93 [ V_81 ] ;
if ( V_91 )
F_63 ( V_91 ) ;
}
for ( V_81 = 0 ; V_81 < V_82 -> V_80 / V_86 ; V_81 ++ )
F_64 ( V_82 -> V_87 [ V_81 ] ) ;
F_63 ( V_82 -> V_84 ) ;
F_8 ( V_82 ) ;
}
static void F_66 ( struct V_2 * V_3 )
{
struct V_79 * V_82 , * V_94 ;
F_52 ( ! F_67 ( & V_3 -> V_74 . V_95 ) ) ;
F_68 (pkt, next, &pd->cdrw.pkt_free_list, list) {
F_65 ( V_82 ) ;
}
F_69 ( & V_3 -> V_74 . V_96 ) ;
}
static int F_70 ( struct V_2 * V_3 , int V_97 )
{
struct V_79 * V_82 ;
F_52 ( ! F_67 ( & V_3 -> V_74 . V_96 ) ) ;
while ( V_97 > 0 ) {
V_82 = F_58 ( V_3 -> V_98 . V_99 >> 2 ) ;
if ( ! V_82 ) {
F_66 ( V_3 ) ;
return 0 ;
}
V_82 -> V_100 = V_97 ;
V_82 -> V_3 = V_3 ;
F_71 ( & V_82 -> V_101 , & V_3 -> V_74 . V_96 ) ;
V_97 -- ;
}
return 1 ;
}
static inline struct V_102 * F_72 ( struct V_102 * V_103 )
{
struct V_104 * V_16 = F_73 ( & V_103 -> V_104 ) ;
if ( ! V_16 )
return NULL ;
return F_74 ( V_16 , struct V_102 , V_104 ) ;
}
static void F_75 ( struct V_2 * V_3 , struct V_102 * V_103 )
{
F_76 ( & V_103 -> V_104 , & V_3 -> V_105 ) ;
F_77 ( V_103 , V_3 -> V_106 ) ;
V_3 -> V_25 -- ;
F_52 ( V_3 -> V_25 < 0 ) ;
}
static struct V_102 * F_78 ( struct V_2 * V_3 , T_3 V_107 )
{
struct V_104 * V_16 = V_3 -> V_105 . V_104 ;
struct V_104 * V_94 ;
struct V_102 * V_108 ;
if ( ! V_16 ) {
F_52 ( V_3 -> V_25 > 0 ) ;
return NULL ;
}
for (; ; ) {
V_108 = F_74 ( V_16 , struct V_102 , V_104 ) ;
if ( V_107 <= V_108 -> V_91 -> V_109 )
V_94 = V_16 -> V_110 ;
else
V_94 = V_16 -> V_111 ;
if ( ! V_94 )
break;
V_16 = V_94 ;
}
if ( V_107 > V_108 -> V_91 -> V_109 ) {
V_108 = F_72 ( V_108 ) ;
if ( ! V_108 )
return NULL ;
}
F_52 ( V_107 > V_108 -> V_91 -> V_109 ) ;
return V_108 ;
}
static void F_79 ( struct V_2 * V_3 , struct V_102 * V_103 )
{
struct V_104 * * V_9 = & V_3 -> V_105 . V_104 ;
struct V_104 * V_6 = NULL ;
T_3 V_107 = V_103 -> V_91 -> V_109 ;
struct V_102 * V_108 ;
while ( * V_9 ) {
V_6 = * V_9 ;
V_108 = F_74 ( V_6 , struct V_102 , V_104 ) ;
if ( V_107 < V_108 -> V_91 -> V_109 )
V_9 = & ( * V_9 ) -> V_110 ;
else
V_9 = & ( * V_9 ) -> V_111 ;
}
F_80 ( & V_103 -> V_104 , V_6 , V_9 ) ;
F_81 ( & V_103 -> V_104 , & V_3 -> V_105 ) ;
V_3 -> V_25 ++ ;
}
static int F_82 ( struct V_2 * V_3 , struct V_112 * V_113 )
{
struct V_114 * V_115 = F_83 ( V_3 -> V_48 ) ;
struct V_116 * V_117 ;
int V_57 = 0 ;
V_117 = F_84 ( V_115 , ( V_113 -> V_118 == V_119 ) ?
V_120 : V_121 , V_122 ) ;
if ( V_113 -> V_123 ) {
if ( F_85 ( V_115 , V_117 , V_113 -> V_124 , V_113 -> V_123 , V_122 ) )
goto V_125;
}
V_117 -> V_126 = F_86 ( V_113 -> V_127 [ 0 ] ) ;
memcpy ( V_117 -> V_127 , V_113 -> V_127 , V_128 ) ;
V_117 -> V_129 = 60 * V_130 ;
V_117 -> V_131 = V_132 ;
if ( V_113 -> V_133 )
V_117 -> V_134 |= V_135 ;
F_87 ( V_117 -> V_115 , V_3 -> V_48 -> V_136 , V_117 , 0 ) ;
if ( V_117 -> V_137 )
V_57 = - V_138 ;
V_125:
F_88 ( V_117 ) ;
return V_57 ;
}
static void F_89 ( struct V_112 * V_113 )
{
static char * V_139 [ 9 ] = { L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 ,
L_27 , L_28 , L_29 } ;
int V_81 ;
struct V_140 * V_141 = V_113 -> V_141 ;
F_37 ( V_59 L_30 ) ;
for ( V_81 = 0 ; V_81 < V_128 ; V_81 ++ )
F_37 ( L_31 , V_113 -> V_127 [ V_81 ] ) ;
F_37 ( L_32 ) ;
if ( V_141 == NULL ) {
F_37 ( L_33 ) ;
return;
}
F_37 ( L_34 , V_141 -> V_142 , V_141 -> V_143 , V_141 -> V_144 ) ;
if ( V_141 -> V_142 > 8 ) {
F_37 ( L_35 ) ;
return;
}
F_37 ( L_36 , V_139 [ V_141 -> V_142 ] ) ;
}
static int F_90 ( struct V_2 * V_3 )
{
struct V_112 V_113 ;
F_91 ( & V_113 , NULL , 0 , V_145 ) ;
V_113 . V_127 [ 0 ] = V_146 ;
V_113 . V_133 = 1 ;
#if 0
cgc.cmd[1] = 1 << 1;
#endif
return F_82 ( V_3 , & V_113 ) ;
}
static T_4 int F_92 ( struct V_2 * V_3 ,
unsigned V_147 , unsigned V_148 )
{
struct V_112 V_113 ;
struct V_140 V_141 ;
int V_57 ;
F_91 ( & V_113 , NULL , 0 , V_145 ) ;
V_113 . V_141 = & V_141 ;
V_113 . V_127 [ 0 ] = V_149 ;
V_113 . V_127 [ 2 ] = ( V_148 >> 8 ) & 0xff ;
V_113 . V_127 [ 3 ] = V_148 & 0xff ;
V_113 . V_127 [ 4 ] = ( V_147 >> 8 ) & 0xff ;
V_113 . V_127 [ 5 ] = V_147 & 0xff ;
if ( ( V_57 = F_82 ( V_3 , & V_113 ) ) )
F_89 ( & V_113 ) ;
return V_57 ;
}
static void F_93 ( struct V_2 * V_3 , struct V_91 * V_91 )
{
F_11 ( & V_3 -> V_76 . V_24 ) ;
if ( F_94 ( V_91 ) == V_121 )
F_95 ( & V_3 -> V_76 . V_150 , V_91 ) ;
else
F_95 ( & V_3 -> V_76 . V_151 , V_91 ) ;
F_12 ( & V_3 -> V_76 . V_24 ) ;
F_56 ( & V_3 -> V_76 . V_77 , 1 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
if ( F_53 ( & V_3 -> V_76 . V_77 ) == 0 )
return;
F_56 ( & V_3 -> V_76 . V_77 , 0 ) ;
for (; ; ) {
struct V_91 * V_91 ;
int V_152 , V_153 ;
F_11 ( & V_3 -> V_76 . V_24 ) ;
V_152 = ! F_97 ( & V_3 -> V_76 . V_150 ) ;
V_153 = ! F_97 ( & V_3 -> V_76 . V_151 ) ;
F_12 ( & V_3 -> V_76 . V_24 ) ;
if ( ! V_152 && ! V_153 )
break;
if ( V_3 -> V_76 . V_154 ) {
int V_155 = 1 ;
F_11 ( & V_3 -> V_76 . V_24 ) ;
V_91 = F_98 ( & V_3 -> V_76 . V_151 ) ;
F_12 ( & V_3 -> V_76 . V_24 ) ;
if ( V_91 && ( V_91 -> V_109 == V_3 -> V_76 . V_156 ) )
V_155 = 0 ;
if ( V_155 && V_152 ) {
if ( F_53 ( & V_3 -> V_74 . V_75 ) > 0 ) {
F_55 ( V_59 L_37 ) ;
break;
}
F_90 ( V_3 ) ;
V_3 -> V_76 . V_154 = 0 ;
}
} else {
if ( ! V_152 && V_153 ) {
if ( F_53 ( & V_3 -> V_74 . V_75 ) > 0 ) {
F_55 ( V_59 L_38 ) ;
break;
}
V_3 -> V_76 . V_154 = 1 ;
}
}
F_11 ( & V_3 -> V_76 . V_24 ) ;
if ( V_3 -> V_76 . V_154 )
V_91 = F_99 ( & V_3 -> V_76 . V_151 ) ;
else
V_91 = F_99 ( & V_3 -> V_76 . V_150 ) ;
F_12 ( & V_3 -> V_76 . V_24 ) ;
if ( ! V_91 )
continue;
if ( F_94 ( V_91 ) == V_121 )
V_3 -> V_76 . V_157 += V_91 -> V_158 >> 10 ;
else {
V_3 -> V_76 . V_157 = 0 ;
V_3 -> V_76 . V_156 = F_100 ( V_91 ) ;
}
if ( V_3 -> V_76 . V_157 >= V_159 ) {
if ( V_3 -> V_148 == V_3 -> V_147 ) {
V_3 -> V_148 = V_160 ;
F_92 ( V_3 , V_3 -> V_147 , V_3 -> V_148 ) ;
}
} else {
if ( V_3 -> V_148 != V_3 -> V_147 ) {
V_3 -> V_148 = V_3 -> V_147 ;
F_92 ( V_3 , V_3 -> V_147 , V_3 -> V_148 ) ;
}
}
F_101 ( & V_3 -> V_74 . V_75 ) ;
F_102 ( V_91 ) ;
}
}
static int F_103 ( struct V_2 * V_3 , struct V_114 * V_115 )
{
if ( ( V_3 -> V_98 . V_99 << 9 ) / V_161
<= F_104 ( V_115 ) ) {
F_105 ( V_162 , & V_3 -> V_163 ) ;
return 0 ;
} else if ( ( V_3 -> V_98 . V_99 << 9 ) / V_164
<= F_104 ( V_115 ) ) {
F_106 ( V_162 , & V_3 -> V_163 ) ;
return 0 ;
} else {
F_37 ( V_59 L_39 ) ;
return - V_138 ;
}
}
static void F_107 ( struct V_79 * V_82 , struct V_165 * V_166 )
{
int V_167 , V_9 , V_168 ;
V_9 = 0 ;
V_168 = 0 ;
for ( V_167 = 0 ; V_167 < V_82 -> V_80 ; V_167 ++ ) {
if ( V_166 [ V_167 ] . V_169 != V_82 -> V_87 [ V_9 ] ) {
void * V_170 = F_108 ( V_166 [ V_167 ] . V_169 ) + V_166 [ V_167 ] . V_171 ;
void * V_172 = F_109 ( V_82 -> V_87 [ V_9 ] ) + V_168 ;
memcpy ( V_172 , V_170 , V_161 ) ;
F_110 ( V_170 ) ;
V_166 [ V_167 ] . V_169 = V_82 -> V_87 [ V_9 ] ;
V_166 [ V_167 ] . V_171 = V_168 ;
} else {
F_52 ( V_166 [ V_167 ] . V_171 != V_168 ) ;
}
V_168 += V_161 ;
if ( V_168 >= V_164 ) {
V_168 = 0 ;
V_9 ++ ;
}
}
}
static void F_111 ( struct V_91 * V_91 , int V_173 )
{
struct V_79 * V_82 = V_91 -> V_174 ;
struct V_2 * V_3 = V_82 -> V_3 ;
F_52 ( ! V_3 ) ;
F_55 ( L_40 , V_91 ,
( unsigned long long ) V_82 -> V_175 , ( unsigned long long ) V_91 -> V_109 , V_173 ) ;
if ( V_173 )
F_101 ( & V_82 -> V_176 ) ;
if ( F_54 ( & V_82 -> V_177 ) ) {
F_101 ( & V_82 -> V_178 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
F_51 ( V_3 ) ;
}
static void F_112 ( struct V_91 * V_91 , int V_173 )
{
struct V_79 * V_82 = V_91 -> V_174 ;
struct V_2 * V_3 = V_82 -> V_3 ;
F_52 ( ! V_3 ) ;
F_55 ( L_41 , V_82 -> V_100 , V_173 ) ;
V_3 -> V_18 . V_20 ++ ;
F_51 ( V_3 ) ;
F_113 ( & V_82 -> V_177 ) ;
F_101 ( & V_82 -> V_178 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
static void F_114 ( struct V_2 * V_3 , struct V_79 * V_82 )
{
int V_179 = 0 ;
struct V_91 * V_91 ;
int V_167 ;
char V_180 [ V_181 ] ;
F_52 ( F_97 ( & V_82 -> V_90 ) ) ;
F_56 ( & V_82 -> V_177 , 0 ) ;
F_56 ( & V_82 -> V_176 , 0 ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
F_11 ( & V_82 -> V_24 ) ;
F_115 (bio, &pkt->orig_bios) {
int V_182 = ( V_91 -> V_109 - V_82 -> V_175 ) / ( V_161 >> 9 ) ;
int V_183 = V_91 -> V_158 / V_161 ;
V_3 -> V_18 . V_21 += V_183 * ( V_161 >> 9 ) ;
F_52 ( V_182 < 0 ) ;
F_52 ( V_182 + V_183 > V_82 -> V_80 ) ;
for ( V_167 = V_182 ; V_167 < V_182 + V_183 ; V_167 ++ )
V_180 [ V_167 ] = 1 ;
}
F_12 ( & V_82 -> V_24 ) ;
if ( V_82 -> V_184 ) {
F_55 ( L_42 ,
( unsigned long long ) V_82 -> V_175 ) ;
goto V_185;
}
for ( V_167 = 0 ; V_167 < V_82 -> V_80 ; V_167 ++ ) {
int V_9 , V_186 ;
if ( V_180 [ V_167 ] )
continue;
V_91 = V_82 -> V_93 [ V_167 ] ;
F_116 ( V_91 ) ;
V_91 -> V_109 = V_82 -> V_175 + V_167 * ( V_161 >> 9 ) ;
V_91 -> V_187 = V_3 -> V_48 ;
V_91 -> V_188 = F_111 ;
V_91 -> V_174 = V_82 ;
V_9 = ( V_167 * V_161 ) / V_164 ;
V_186 = ( V_167 * V_161 ) % V_164 ;
F_55 ( L_43 ,
V_167 , V_82 -> V_87 [ V_9 ] , V_186 ) ;
if ( ! F_117 ( V_91 , V_82 -> V_87 [ V_9 ] , V_161 , V_186 ) )
F_118 () ;
F_101 ( & V_82 -> V_177 ) ;
V_91 -> V_189 = V_121 ;
F_93 ( V_3 , V_91 ) ;
V_179 ++ ;
}
V_185:
F_55 ( L_44 ,
V_179 , ( unsigned long long ) V_82 -> V_175 ) ;
V_3 -> V_18 . V_19 ++ ;
V_3 -> V_18 . V_23 += V_179 * ( V_161 >> 9 ) ;
}
static struct V_79 * F_119 ( struct V_2 * V_3 , int V_190 )
{
struct V_79 * V_82 ;
F_120 (pkt, &pd->cdrw.pkt_free_list, list) {
if ( V_82 -> V_175 == V_190 || V_82 -> V_101 . V_94 == & V_3 -> V_74 . V_96 ) {
F_121 ( & V_82 -> V_101 ) ;
if ( V_82 -> V_175 != V_190 )
V_82 -> V_184 = 0 ;
return V_82 ;
}
}
F_118 () ;
return NULL ;
}
static void F_122 ( struct V_2 * V_3 , struct V_79 * V_82 )
{
if ( V_82 -> V_184 ) {
F_71 ( & V_82 -> V_101 , & V_3 -> V_74 . V_96 ) ;
} else {
F_123 ( & V_82 -> V_101 , & V_3 -> V_74 . V_96 ) ;
}
}
static int F_124 ( struct V_79 * V_82 )
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
bio_reset(pkt->bio);
pkt->bio->bi_bdev = pd->bdev;
pkt->bio->bi_rw = REQ_WRITE;
pkt->bio->bi_sector = new_sector;
pkt->bio->bi_size = pkt->frames * CD_FRAMESIZE;
pkt->bio->bi_vcnt = pkt->frames;
pkt->bio->bi_end_io = pkt_end_io_packet_write;
pkt->bio->bi_private = pkt;
drop_super(sb);
return 1;
out:
drop_super(sb);
return 0;
#endif
}
static inline void F_125 ( struct V_79 * V_82 , enum V_191 V_192 )
{
#if V_193 > 1
static const char * V_194 [] = {
L_45 , L_46 , L_47 , L_48 , L_49 , L_50
} ;
enum V_191 V_195 = V_82 -> V_192 ;
F_55 ( L_51 , V_82 -> V_100 , ( unsigned long long ) V_82 -> V_175 ,
V_194 [ V_195 ] , V_194 [ V_192 ] ) ;
#endif
V_82 -> V_192 = V_192 ;
}
static int F_126 ( struct V_2 * V_3 )
{
struct V_79 * V_82 , * V_9 ;
struct V_91 * V_91 = NULL ;
T_3 V_190 = 0 ;
struct V_102 * V_103 , * V_196 ;
struct V_104 * V_16 ;
int V_197 ;
F_55 ( L_52 ) ;
F_56 ( & V_3 -> V_198 , 0 ) ;
if ( F_67 ( & V_3 -> V_74 . V_96 ) ) {
F_55 ( L_53 ) ;
return 0 ;
}
F_11 ( & V_3 -> V_24 ) ;
V_196 = F_78 ( V_3 , V_3 -> V_199 ) ;
if ( ! V_196 ) {
V_16 = F_127 ( & V_3 -> V_105 ) ;
if ( V_16 )
V_196 = F_74 ( V_16 , struct V_102 , V_104 ) ;
}
V_103 = V_196 ;
while ( V_103 ) {
V_91 = V_103 -> V_91 ;
V_190 = F_128 ( V_91 -> V_109 , V_3 ) ;
F_120 (p, &pd->cdrw.pkt_active_list, list) {
if ( V_9 -> V_175 == V_190 ) {
V_91 = NULL ;
goto V_200;
}
}
break;
V_200:
V_103 = F_72 ( V_103 ) ;
if ( ! V_103 ) {
V_16 = F_127 ( & V_3 -> V_105 ) ;
if ( V_16 )
V_103 = F_74 ( V_16 , struct V_102 , V_104 ) ;
}
if ( V_103 == V_196 )
V_103 = NULL ;
}
F_12 ( & V_3 -> V_24 ) ;
if ( ! V_91 ) {
F_55 ( L_54 ) ;
return 0 ;
}
V_82 = F_119 ( V_3 , V_190 ) ;
V_3 -> V_199 = V_190 + V_3 -> V_98 . V_99 ;
V_82 -> V_175 = V_190 ;
F_52 ( V_82 -> V_80 != V_3 -> V_98 . V_99 >> 2 ) ;
V_82 -> V_201 = 0 ;
F_11 ( & V_3 -> V_24 ) ;
F_55 ( L_55 , ( unsigned long long ) V_190 ) ;
while ( ( V_103 = F_78 ( V_3 , V_190 ) ) != NULL ) {
V_91 = V_103 -> V_91 ;
F_55 ( L_56 ,
( unsigned long long ) F_128 ( V_91 -> V_109 , V_3 ) ) ;
if ( F_128 ( V_91 -> V_109 , V_3 ) != V_190 )
break;
F_75 ( V_3 , V_103 ) ;
F_11 ( & V_82 -> V_24 ) ;
F_95 ( & V_82 -> V_90 , V_91 ) ;
V_82 -> V_201 += V_91 -> V_158 / V_161 ;
F_12 ( & V_82 -> V_24 ) ;
}
V_197 = ( V_3 -> V_27 > 0
&& V_3 -> V_25 <= V_3 -> V_26 ) ;
F_12 ( & V_3 -> V_24 ) ;
if ( V_197 ) {
F_129 ( & V_3 -> V_202 -> V_203 -> V_204 ,
V_205 ) ;
}
V_82 -> V_206 = F_14 ( V_207 , 1 ) ;
F_125 ( V_82 , V_208 ) ;
F_56 ( & V_82 -> V_178 , 1 ) ;
F_11 ( & V_3 -> V_74 . V_209 ) ;
F_71 ( & V_82 -> V_101 , & V_3 -> V_74 . V_95 ) ;
F_12 ( & V_3 -> V_74 . V_209 ) ;
return 1 ;
}
static void F_130 ( struct V_2 * V_3 , struct V_79 * V_82 )
{
int V_167 ;
struct V_165 * V_166 = V_82 -> V_84 -> V_210 ;
F_116 ( V_82 -> V_84 ) ;
V_82 -> V_84 -> V_109 = V_82 -> V_175 ;
V_82 -> V_84 -> V_187 = V_3 -> V_48 ;
V_82 -> V_84 -> V_188 = F_112 ;
V_82 -> V_84 -> V_174 = V_82 ;
for ( V_167 = 0 ; V_167 < V_82 -> V_80 ; V_167 ++ ) {
V_166 [ V_167 ] . V_169 = V_82 -> V_87 [ ( V_167 * V_161 ) / V_164 ] ;
V_166 [ V_167 ] . V_171 = ( V_167 * V_161 ) % V_164 ;
if ( ! F_117 ( V_82 -> V_84 , V_166 [ V_167 ] . V_169 , V_161 , V_166 [ V_167 ] . V_171 ) )
F_118 () ;
}
F_55 ( V_59 L_57 , V_82 -> V_84 -> V_211 ) ;
F_11 ( & V_82 -> V_24 ) ;
F_131 ( V_82 -> V_84 , V_82 -> V_90 . V_212 ) ;
F_125 ( V_82 , V_213 ) ;
F_12 ( & V_82 -> V_24 ) ;
F_55 ( L_58 ,
V_82 -> V_201 , ( unsigned long long ) V_82 -> V_175 ) ;
if ( F_132 ( V_162 , & V_3 -> V_163 ) || ( V_82 -> V_201 < V_82 -> V_80 ) ) {
F_107 ( V_82 , V_166 ) ;
V_82 -> V_184 = 1 ;
} else {
V_82 -> V_184 = 0 ;
}
F_56 ( & V_82 -> V_177 , 1 ) ;
V_82 -> V_84 -> V_189 = V_120 ;
F_93 ( V_3 , V_82 -> V_84 ) ;
}
static void F_133 ( struct V_79 * V_82 , int V_214 )
{
struct V_91 * V_91 ;
if ( ! V_214 )
V_82 -> V_184 = 0 ;
while ( ( V_91 = F_99 ( & V_82 -> V_90 ) ) )
F_134 ( V_91 , V_214 ? 0 : - V_138 ) ;
}
static void F_135 ( struct V_2 * V_3 , struct V_79 * V_82 )
{
int V_214 ;
F_55 ( L_59 , V_82 -> V_100 ) ;
for (; ; ) {
switch ( V_82 -> V_192 ) {
case V_208 :
if ( ( V_82 -> V_201 < V_82 -> V_80 ) && ( V_82 -> V_206 > 0 ) )
return;
V_82 -> V_206 = 0 ;
F_114 ( V_3 , V_82 ) ;
F_125 ( V_82 , V_215 ) ;
break;
case V_215 :
if ( F_53 ( & V_82 -> V_177 ) > 0 )
return;
if ( F_53 ( & V_82 -> V_176 ) > 0 ) {
F_125 ( V_82 , V_216 ) ;
} else {
F_130 ( V_3 , V_82 ) ;
}
break;
case V_213 :
if ( F_53 ( & V_82 -> V_177 ) > 0 )
return;
if ( F_132 ( V_217 , & V_82 -> V_84 -> V_218 ) ) {
F_125 ( V_82 , V_219 ) ;
} else {
F_125 ( V_82 , V_216 ) ;
}
break;
case V_216 :
if ( F_124 ( V_82 ) ) {
F_130 ( V_3 , V_82 ) ;
} else {
F_55 ( L_60 ) ;
F_125 ( V_82 , V_219 ) ;
}
break;
case V_219 :
V_214 = F_132 ( V_217 , & V_82 -> V_84 -> V_218 ) ;
F_133 ( V_82 , V_214 ) ;
return;
default:
F_118 () ;
break;
}
}
}
static void F_136 ( struct V_2 * V_3 )
{
struct V_79 * V_82 , * V_94 ;
F_55 ( L_61 ) ;
F_120 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_53 ( & V_82 -> V_178 ) > 0 ) {
F_56 ( & V_82 -> V_178 , 0 ) ;
F_135 ( V_3 , V_82 ) ;
}
}
F_11 ( & V_3 -> V_74 . V_209 ) ;
F_68 (pkt, next, &pd->cdrw.pkt_active_list, list) {
if ( V_82 -> V_192 == V_219 ) {
F_137 ( & V_82 -> V_101 ) ;
F_122 ( V_3 , V_82 ) ;
F_125 ( V_82 , V_220 ) ;
F_56 ( & V_3 -> V_198 , 1 ) ;
}
}
F_12 ( & V_3 -> V_74 . V_209 ) ;
}
static void F_138 ( struct V_2 * V_3 , int * V_221 )
{
struct V_79 * V_82 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < V_222 ; V_81 ++ )
V_221 [ V_81 ] = 0 ;
F_11 ( & V_3 -> V_74 . V_209 ) ;
F_120 (pkt, &pd->cdrw.pkt_active_list, list) {
V_221 [ V_82 -> V_192 ] ++ ;
}
F_12 ( & V_3 -> V_74 . V_209 ) ;
}
static int F_139 ( void * V_223 )
{
struct V_2 * V_3 = V_223 ;
struct V_79 * V_82 ;
long V_224 , V_225 ;
F_140 ( V_226 , - 20 ) ;
F_141 () ;
for (; ; ) {
F_142 ( V_227 , V_226 ) ;
F_143 ( & V_3 -> V_78 , & V_227 ) ;
for (; ; ) {
F_144 ( V_228 ) ;
if ( F_53 ( & V_3 -> V_198 ) > 0 )
goto V_229;
F_120 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_53 ( & V_82 -> V_178 ) > 0 )
goto V_229;
}
if ( F_53 ( & V_3 -> V_76 . V_77 ) != 0 )
goto V_229;
if ( V_193 > 1 ) {
int V_221 [ V_222 ] ;
F_138 ( V_3 , V_221 ) ;
F_55 ( L_62 ,
V_221 [ 0 ] , V_221 [ 1 ] , V_221 [ 2 ] , V_221 [ 3 ] ,
V_221 [ 4 ] , V_221 [ 5 ] ) ;
}
V_224 = V_230 ;
F_120 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_82 -> V_206 && V_82 -> V_206 < V_224 )
V_224 = V_82 -> V_206 ;
}
F_55 ( L_63 ) ;
V_225 = F_145 ( V_224 ) ;
F_55 ( L_64 ) ;
F_146 () ;
F_120 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( ! V_82 -> V_206 )
continue;
V_82 -> V_206 -= V_224 - V_225 ;
if ( V_82 -> V_206 <= 0 ) {
V_82 -> V_206 = 0 ;
F_101 ( & V_82 -> V_178 ) ;
}
}
if ( F_147 () )
break;
}
V_229:
F_144 ( V_231 ) ;
F_148 ( & V_3 -> V_78 , & V_227 ) ;
if ( F_147 () )
break;
while ( F_126 ( V_3 ) )
;
F_136 ( V_3 ) ;
F_96 ( V_3 ) ;
}
return 0 ;
}
static void F_149 ( struct V_2 * V_3 )
{
F_37 ( V_59 L_65 , V_3 -> V_98 . V_232 ? L_66 : L_67 ) ;
F_37 ( L_68 , V_3 -> V_98 . V_99 >> 2 ) ;
F_37 ( L_69 , V_3 -> V_98 . V_233 == 8 ? '1' : '2' ) ;
}
static int F_150 ( struct V_2 * V_3 , struct V_112 * V_113 , int V_234 , int V_235 )
{
memset ( V_113 -> V_127 , 0 , sizeof( V_113 -> V_127 ) ) ;
V_113 -> V_127 [ 0 ] = V_236 ;
V_113 -> V_127 [ 2 ] = V_234 | ( V_235 << 6 ) ;
V_113 -> V_127 [ 7 ] = V_113 -> V_123 >> 8 ;
V_113 -> V_127 [ 8 ] = V_113 -> V_123 & 0xff ;
V_113 -> V_118 = V_237 ;
return F_82 ( V_3 , V_113 ) ;
}
static int F_151 ( struct V_2 * V_3 , struct V_112 * V_113 )
{
memset ( V_113 -> V_127 , 0 , sizeof( V_113 -> V_127 ) ) ;
memset ( V_113 -> V_124 , 0 , 2 ) ;
V_113 -> V_127 [ 0 ] = V_238 ;
V_113 -> V_127 [ 1 ] = 0x10 ;
V_113 -> V_127 [ 7 ] = V_113 -> V_123 >> 8 ;
V_113 -> V_127 [ 8 ] = V_113 -> V_123 & 0xff ;
V_113 -> V_118 = V_119 ;
return F_82 ( V_3 , V_113 ) ;
}
static int F_152 ( struct V_2 * V_3 , T_5 * V_239 )
{
struct V_112 V_113 ;
int V_57 ;
F_91 ( & V_113 , V_239 , sizeof( * V_239 ) , V_237 ) ;
V_113 . V_127 [ 0 ] = V_240 ;
V_113 . V_127 [ 8 ] = V_113 . V_123 = 2 ;
V_113 . V_133 = 1 ;
if ( ( V_57 = F_82 ( V_3 , & V_113 ) ) )
return V_57 ;
V_113 . V_123 = F_153 ( V_239 -> V_241 ) +
sizeof( V_239 -> V_241 ) ;
if ( V_113 . V_123 > sizeof( T_5 ) )
V_113 . V_123 = sizeof( T_5 ) ;
V_113 . V_127 [ 8 ] = V_113 . V_123 ;
return F_82 ( V_3 , & V_113 ) ;
}
static int F_154 ( struct V_2 * V_3 , T_6 V_242 , T_7 type , T_8 * V_243 )
{
struct V_112 V_113 ;
int V_57 ;
F_91 ( & V_113 , V_243 , 8 , V_237 ) ;
V_113 . V_127 [ 0 ] = V_244 ;
V_113 . V_127 [ 1 ] = type & 3 ;
V_113 . V_127 [ 4 ] = ( V_242 & 0xff00 ) >> 8 ;
V_113 . V_127 [ 5 ] = V_242 & 0xff ;
V_113 . V_127 [ 8 ] = 8 ;
V_113 . V_133 = 1 ;
if ( ( V_57 = F_82 ( V_3 , & V_113 ) ) )
return V_57 ;
V_113 . V_123 = F_153 ( V_243 -> V_245 ) +
sizeof( V_243 -> V_245 ) ;
if ( V_113 . V_123 > sizeof( T_8 ) )
V_113 . V_123 = sizeof( T_8 ) ;
V_113 . V_127 [ 8 ] = V_113 . V_123 ;
return F_82 ( V_3 , & V_113 ) ;
}
static T_4 int F_155 ( struct V_2 * V_3 ,
long * V_246 )
{
T_5 V_239 ;
T_8 V_243 ;
T_9 V_247 ;
int V_57 = - 1 ;
if ( ( V_57 = F_152 ( V_3 , & V_239 ) ) )
return V_57 ;
V_247 = ( V_239 . V_248 << 8 ) | V_239 . V_249 ;
if ( ( V_57 = F_154 ( V_3 , V_247 , 1 , & V_243 ) ) )
return V_57 ;
if ( V_243 . V_250 ) {
V_247 -- ;
if ( ( V_57 = F_154 ( V_3 , V_247 , 1 , & V_243 ) ) )
return V_57 ;
}
if ( V_243 . V_251 ) {
* V_246 = F_156 ( V_243 . V_252 ) ;
} else {
* V_246 = F_156 ( V_243 . V_253 ) +
F_156 ( V_243 . V_254 ) ;
if ( V_243 . V_255 )
* V_246 -= ( F_156 ( V_243 . V_255 ) + 7 ) ;
}
return 0 ;
}
static T_4 int F_157 ( struct V_2 * V_3 )
{
struct V_112 V_113 ;
struct V_140 V_141 ;
T_10 * V_256 ;
char V_124 [ 128 ] ;
int V_57 , V_99 ;
if ( ( V_3 -> V_257 == 0x1a ) || ( V_3 -> V_257 == 0x12 ) )
return 0 ;
memset ( V_124 , 0 , sizeof( V_124 ) ) ;
F_91 ( & V_113 , V_124 , sizeof( * V_256 ) , V_237 ) ;
V_113 . V_141 = & V_141 ;
if ( ( V_57 = F_150 ( V_3 , & V_113 , V_258 , 0 ) ) ) {
F_89 ( & V_113 ) ;
return V_57 ;
}
V_99 = 2 + ( ( V_124 [ 0 ] << 8 ) | ( V_124 [ 1 ] & 0xff ) ) ;
V_3 -> V_259 = ( V_124 [ 6 ] << 8 ) | ( V_124 [ 7 ] & 0xff ) ;
if ( V_99 > sizeof( V_124 ) )
V_99 = sizeof( V_124 ) ;
F_91 ( & V_113 , V_124 , V_99 , V_237 ) ;
V_113 . V_141 = & V_141 ;
if ( ( V_57 = F_150 ( V_3 , & V_113 , V_258 , 0 ) ) ) {
F_89 ( & V_113 ) ;
return V_57 ;
}
V_256 = ( T_10 * ) & V_124 [ sizeof( struct V_260 ) + V_3 -> V_259 ] ;
V_256 -> V_232 = V_3 -> V_98 . V_232 ;
V_256 -> V_261 = V_3 -> V_98 . V_261 ;
V_256 -> V_262 = V_3 -> V_98 . V_262 ;
V_256 -> V_263 = V_3 -> V_98 . V_233 ;
V_256 -> V_264 = 0 ;
#ifdef F_158
V_256 -> V_265 = 7 ;
V_256 -> V_266 = 1 ;
#endif
if ( V_256 -> V_263 == V_267 ) {
V_256 -> V_268 = 0 ;
V_256 -> V_269 = 0x20 ;
} else if ( V_256 -> V_263 == V_270 ) {
V_256 -> V_268 = 0x20 ;
V_256 -> V_269 = 8 ;
#if 0
wp->mcn[0] = 0x80;
memcpy(&wp->mcn[1], PACKET_MCN, sizeof(wp->mcn) - 1);
#endif
} else {
F_37 ( V_59 L_70 , V_256 -> V_263 ) ;
return 1 ;
}
V_256 -> V_271 = F_159 ( V_3 -> V_98 . V_99 >> 2 ) ;
V_113 . V_123 = V_113 . V_127 [ 8 ] = V_99 ;
if ( ( V_57 = F_151 ( V_3 , & V_113 ) ) ) {
F_89 ( & V_113 ) ;
return V_57 ;
}
F_149 ( V_3 ) ;
return 0 ;
}
static int F_160 ( struct V_2 * V_3 , T_8 * V_243 )
{
switch ( V_3 -> V_257 ) {
case 0x1a :
case 0x12 :
return 1 ;
default:
break;
}
if ( ! V_243 -> V_272 || ! V_243 -> V_232 )
return 0 ;
if ( V_243 -> V_273 == 0 && V_243 -> V_250 == 0 )
return 1 ;
if ( V_243 -> V_273 == 0 && V_243 -> V_250 == 1 )
return 1 ;
if ( V_243 -> V_273 == 1 && V_243 -> V_250 == 0 )
return 1 ;
F_37 ( V_59 L_71 , V_243 -> V_273 , V_243 -> V_250 , V_243 -> V_272 ) ;
return 0 ;
}
static int F_161 ( struct V_2 * V_3 , T_5 * V_239 )
{
switch ( V_3 -> V_257 ) {
case 0x0a :
case 0xffff :
break;
case 0x1a :
case 0x13 :
case 0x12 :
return 1 ;
default:
F_55 ( V_59 L_72 , V_3 -> V_257 ) ;
return 0 ;
}
if ( V_239 -> V_274 == 0xff ) {
F_37 ( V_59 L_73 ) ;
return 0 ;
}
if ( V_239 -> V_274 != 0x20 && V_239 -> V_274 != 0 ) {
F_37 ( V_59 L_74 , V_239 -> V_274 ) ;
return 0 ;
}
if ( V_239 -> V_275 == 0 ) {
F_37 ( V_59 L_75 ) ;
return 0 ;
}
if ( V_239 -> V_276 == V_277 ) {
F_37 ( V_59 L_76 ) ;
return 0 ;
}
return 1 ;
}
static T_4 int F_162 ( struct V_2 * V_3 )
{
struct V_112 V_113 ;
unsigned char V_50 [ 12 ] ;
T_5 V_239 ;
T_8 V_243 ;
int V_57 , V_242 ;
F_91 ( & V_113 , V_50 , sizeof( V_50 ) , V_237 ) ;
V_113 . V_127 [ 0 ] = V_278 ;
V_113 . V_127 [ 8 ] = 8 ;
V_57 = F_82 ( V_3 , & V_113 ) ;
V_3 -> V_257 = V_57 ? 0xffff : V_50 [ 6 ] << 8 | V_50 [ 7 ] ;
memset ( & V_239 , 0 , sizeof( T_5 ) ) ;
memset ( & V_243 , 0 , sizeof( T_8 ) ) ;
if ( ( V_57 = F_152 ( V_3 , & V_239 ) ) ) {
F_37 ( L_77 ) ;
return V_57 ;
}
if ( ! F_161 ( V_3 , & V_239 ) )
return - V_279 ;
V_3 -> type = V_239 . V_275 ? V_280 : V_281 ;
V_242 = 1 ;
if ( ( V_57 = F_154 ( V_3 , V_242 , 1 , & V_243 ) ) ) {
F_37 ( V_59 L_78 ) ;
return V_57 ;
}
if ( ! F_160 ( V_3 , & V_243 ) ) {
F_37 ( V_59 L_79 ) ;
return - V_279 ;
}
V_3 -> V_98 . V_99 = F_156 ( V_243 . V_282 ) << 2 ;
if ( V_3 -> V_98 . V_99 == 0 ) {
F_37 ( V_59 L_80 ) ;
return - V_283 ;
}
if ( V_3 -> V_98 . V_99 > V_284 ) {
F_37 ( V_59 L_81 ) ;
return - V_279 ;
}
V_3 -> V_98 . V_232 = V_243 . V_232 ;
V_3 -> V_186 = ( F_156 ( V_243 . V_253 ) << 2 ) & ( V_3 -> V_98 . V_99 - 1 ) ;
if ( V_243 . V_285 ) {
V_3 -> V_286 = F_156 ( V_243 . V_287 ) ;
F_106 ( V_288 , & V_3 -> V_163 ) ;
}
if ( V_243 . V_251 ) {
V_3 -> V_289 = F_156 ( V_243 . V_252 ) ;
F_106 ( V_290 , & V_3 -> V_163 ) ;
} else {
V_3 -> V_289 = 0xffffffff ;
F_106 ( V_290 , & V_3 -> V_163 ) ;
}
V_3 -> V_98 . V_291 = 7 ;
V_3 -> V_98 . V_262 = 0 ;
V_3 -> V_98 . V_261 = V_243 . V_261 ;
switch ( V_243 . V_292 ) {
case V_293 :
V_3 -> V_98 . V_233 = V_267 ;
break;
case V_294 :
V_3 -> V_98 . V_233 = V_270 ;
break;
default:
F_37 ( V_59 L_82 ) ;
return - V_279 ;
}
return 0 ;
}
static T_4 int F_163 ( struct V_2 * V_3 ,
int V_295 )
{
struct V_112 V_113 ;
struct V_140 V_141 ;
unsigned char V_50 [ 64 ] ;
int V_57 ;
F_91 ( & V_113 , V_50 , sizeof( V_50 ) , V_237 ) ;
V_113 . V_141 = & V_141 ;
V_113 . V_123 = V_3 -> V_259 + 12 ;
V_113 . V_133 = 1 ;
if ( ( V_57 = F_150 ( V_3 , & V_113 , V_296 , 0 ) ) )
return V_57 ;
V_50 [ V_3 -> V_259 + 10 ] |= ( ! ! V_295 << 2 ) ;
V_113 . V_123 = V_113 . V_127 [ 8 ] = 2 + ( ( V_50 [ 0 ] << 8 ) | ( V_50 [ 1 ] & 0xff ) ) ;
V_57 = F_151 ( V_3 , & V_113 ) ;
if ( V_57 ) {
F_37 ( V_59 L_83 ) ;
F_89 ( & V_113 ) ;
} else if ( ! V_57 && V_295 )
F_37 ( V_59 L_84 , V_3 -> V_4 ) ;
return V_57 ;
}
static int F_164 ( struct V_2 * V_3 , int V_297 )
{
struct V_112 V_113 ;
F_91 ( & V_113 , NULL , 0 , V_145 ) ;
V_113 . V_127 [ 0 ] = V_298 ;
V_113 . V_127 [ 4 ] = V_297 ? 1 : 0 ;
return F_82 ( V_3 , & V_113 ) ;
}
static T_4 int F_165 ( struct V_2 * V_3 ,
unsigned * V_147 )
{
struct V_112 V_113 ;
struct V_140 V_141 ;
unsigned char V_50 [ 256 + 18 ] ;
unsigned char * V_299 ;
int V_57 , V_186 ;
V_299 = & V_50 [ sizeof( struct V_260 ) + V_3 -> V_259 ] ;
F_91 ( & V_113 , V_50 , sizeof( V_50 ) , V_300 ) ;
V_113 . V_141 = & V_141 ;
V_57 = F_150 ( V_3 , & V_113 , V_301 , 0 ) ;
if ( V_57 ) {
V_113 . V_123 = V_3 -> V_259 + V_299 [ 1 ] + 2 +
sizeof( struct V_260 ) ;
V_57 = F_150 ( V_3 , & V_113 , V_301 , 0 ) ;
if ( V_57 ) {
F_89 ( & V_113 ) ;
return V_57 ;
}
}
V_186 = 20 ;
if ( V_299 [ 1 ] >= 28 )
V_186 = 28 ;
if ( V_299 [ 1 ] >= 30 ) {
int V_302 = ( V_299 [ 30 ] << 8 ) + V_299 [ 31 ] ;
if ( V_302 > 0 )
V_186 = 34 ;
}
* V_147 = ( V_299 [ V_186 ] << 8 ) | V_299 [ V_186 + 1 ] ;
return 0 ;
}
static T_4 int F_166 ( struct V_2 * V_3 ,
unsigned * V_303 )
{
struct V_112 V_113 ;
struct V_140 V_141 ;
unsigned char V_50 [ 64 ] ;
unsigned int V_99 , V_304 , V_305 ;
int V_57 ;
F_91 ( & V_113 , V_50 , 2 , V_237 ) ;
V_113 . V_141 = & V_141 ;
V_113 . V_127 [ 0 ] = V_306 ;
V_113 . V_127 [ 1 ] = 2 ;
V_113 . V_127 [ 2 ] = 4 ;
V_113 . V_127 [ 8 ] = 2 ;
V_57 = F_82 ( V_3 , & V_113 ) ;
if ( V_57 ) {
F_89 ( & V_113 ) ;
return V_57 ;
}
V_99 = ( ( unsigned int ) V_50 [ 0 ] << 8 ) + V_50 [ 1 ] + 2 ;
if ( V_99 > sizeof( V_50 ) )
V_99 = sizeof( V_50 ) ;
F_91 ( & V_113 , V_50 , V_99 , V_237 ) ;
V_113 . V_141 = & V_141 ;
V_113 . V_127 [ 0 ] = V_306 ;
V_113 . V_127 [ 1 ] = 2 ;
V_113 . V_127 [ 2 ] = 4 ;
V_113 . V_127 [ 8 ] = V_99 ;
V_57 = F_82 ( V_3 , & V_113 ) ;
if ( V_57 ) {
F_89 ( & V_113 ) ;
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
V_304 = ( V_50 [ 6 ] >> 3 ) & 0x7 ;
V_305 = V_50 [ 16 ] & 0xf ;
switch ( V_304 ) {
case 0 :
* V_303 = V_307 [ V_305 ] ;
break;
case 1 :
* V_303 = V_308 [ V_305 ] ;
break;
case 2 :
* V_303 = V_309 [ V_305 ] ;
break;
default:
F_37 ( V_59 L_87 , V_304 ) ;
return 1 ;
}
if ( * V_303 ) {
F_37 ( V_59 L_88 , * V_303 ) ;
return 0 ;
} else {
F_37 ( V_59 L_89 , V_305 , V_304 ) ;
return 1 ;
}
}
static T_4 int F_167 ( struct V_2 * V_3 )
{
struct V_112 V_113 ;
struct V_140 V_141 ;
int V_57 ;
F_55 ( V_59 L_90 ) ;
F_91 ( & V_113 , NULL , 0 , V_145 ) ;
V_113 . V_141 = & V_141 ;
V_113 . V_129 = 60 * V_130 ;
V_113 . V_127 [ 0 ] = V_310 ;
V_113 . V_127 [ 1 ] = 1 ;
if ( ( V_57 = F_82 ( V_3 , & V_113 ) ) )
F_89 ( & V_113 ) ;
return V_57 ;
}
static int F_168 ( struct V_2 * V_3 )
{
int V_57 ;
unsigned int V_147 , V_311 , V_148 ;
if ( ( V_57 = F_162 ( V_3 ) ) ) {
F_55 ( V_59 L_91 , V_3 -> V_4 ) ;
return V_57 ;
}
if ( ( V_57 = F_157 ( V_3 ) ) ) {
F_169 ( V_59 L_92 , V_3 -> V_4 ) ;
return - V_138 ;
}
F_163 ( V_3 , V_312 ) ;
if ( ( V_57 = F_165 ( V_3 , & V_147 ) ) )
V_147 = 16 * 177 ;
switch ( V_3 -> V_257 ) {
case 0x13 :
case 0x1a :
case 0x12 :
F_169 ( V_59 L_93 , V_147 ) ;
break;
default:
if ( ( V_57 = F_166 ( V_3 , & V_311 ) ) )
V_311 = 16 ;
V_147 = F_15 ( V_147 , V_311 * 177 ) ;
F_169 ( V_59 L_94 , V_147 / 176 ) ;
break;
}
V_148 = V_147 ;
if ( ( V_57 = F_92 ( V_3 , V_147 , V_148 ) ) ) {
F_169 ( V_59 L_95 , V_3 -> V_4 ) ;
return - V_138 ;
}
V_3 -> V_147 = V_147 ;
V_3 -> V_148 = V_148 ;
if ( ( V_57 = F_167 ( V_3 ) ) ) {
F_169 ( V_59 L_96 , V_3 -> V_4 ) ;
}
return 0 ;
}
static int F_170 ( struct V_2 * V_3 , T_11 V_313 )
{
int V_57 ;
long V_314 ;
struct V_114 * V_115 ;
F_171 ( V_3 -> V_48 -> V_49 ) ;
if ( ( V_57 = F_172 ( V_3 -> V_48 , V_315 | V_316 , V_3 ) ) )
goto V_125;
if ( ( V_57 = F_155 ( V_3 , & V_314 ) ) ) {
F_37 ( V_59 L_97 ) ;
goto V_317;
}
F_173 ( V_3 -> V_202 , V_314 << 2 ) ;
F_173 ( V_3 -> V_48 -> V_136 , V_314 << 2 ) ;
F_174 ( V_3 -> V_48 , ( V_318 ) V_314 << 11 ) ;
V_115 = F_83 ( V_3 -> V_48 ) ;
if ( V_313 ) {
if ( ( V_57 = F_168 ( V_3 ) ) )
goto V_317;
F_175 ( V_115 -> V_319 ) ;
F_176 ( V_115 , V_3 -> V_98 . V_99 ) ;
F_177 ( V_115 -> V_319 ) ;
F_106 ( V_320 , & V_3 -> V_163 ) ;
} else {
F_92 ( V_3 , V_160 , V_160 ) ;
F_105 ( V_320 , & V_3 -> V_163 ) ;
}
if ( ( V_57 = F_103 ( V_3 , V_115 ) ) )
goto V_317;
if ( V_313 ) {
if ( ! F_70 ( V_3 , V_321 ) ) {
F_37 ( V_59 L_98 ) ;
V_57 = - V_58 ;
goto V_317;
}
F_37 ( V_59 L_99 , V_314 << 1 ) ;
}
return 0 ;
V_317:
F_178 ( V_3 -> V_48 , V_315 | V_316 ) ;
V_125:
return V_57 ;
}
static void F_179 ( struct V_2 * V_3 , int V_322 )
{
if ( V_322 && F_90 ( V_3 ) )
F_169 ( V_59 L_100 , V_3 -> V_4 ) ;
F_164 ( V_3 , 0 ) ;
F_92 ( V_3 , V_160 , V_160 ) ;
F_178 ( V_3 -> V_48 , V_315 | V_316 ) ;
F_66 ( V_3 ) ;
}
static struct V_2 * F_180 ( unsigned int V_323 )
{
if ( V_323 >= V_45 )
return NULL ;
return V_46 [ V_323 ] ;
}
static int F_181 ( struct V_324 * V_48 , T_11 V_325 )
{
struct V_2 * V_3 = NULL ;
int V_57 ;
F_55 ( V_59 L_101 ) ;
F_182 ( & V_326 ) ;
F_182 ( & V_43 ) ;
V_3 = F_180 ( F_27 ( V_48 -> V_49 ) ) ;
if ( ! V_3 ) {
V_57 = - V_55 ;
goto V_125;
}
F_52 ( V_3 -> V_327 < 0 ) ;
V_3 -> V_327 ++ ;
if ( V_3 -> V_327 > 1 ) {
if ( ( V_325 & V_328 ) &&
! F_132 ( V_320 , & V_3 -> V_163 ) ) {
V_57 = - V_329 ;
goto V_330;
}
} else {
V_57 = F_170 ( V_3 , V_325 & V_328 ) ;
if ( V_57 )
goto V_330;
F_183 ( V_48 , V_161 ) ;
}
F_28 ( & V_43 ) ;
F_28 ( & V_326 ) ;
return 0 ;
V_330:
V_3 -> V_327 -- ;
V_125:
F_55 ( V_59 L_102 , V_57 ) ;
F_28 ( & V_43 ) ;
F_28 ( & V_326 ) ;
return V_57 ;
}
static void F_184 ( struct V_331 * V_202 , T_11 V_325 )
{
struct V_2 * V_3 = V_202 -> V_332 ;
F_182 ( & V_326 ) ;
F_182 ( & V_43 ) ;
V_3 -> V_327 -- ;
F_52 ( V_3 -> V_327 < 0 ) ;
if ( V_3 -> V_327 == 0 ) {
int V_322 = F_132 ( V_320 , & V_3 -> V_163 ) ;
F_179 ( V_3 , V_322 ) ;
}
F_28 ( & V_43 ) ;
F_28 ( & V_326 ) ;
}
static void F_185 ( struct V_91 * V_91 , int V_173 )
{
struct V_333 * V_334 = V_91 -> V_174 ;
struct V_2 * V_3 = V_334 -> V_3 ;
F_63 ( V_91 ) ;
F_134 ( V_334 -> V_91 , V_173 ) ;
F_77 ( V_334 , V_335 ) ;
F_51 ( V_3 ) ;
}
static void F_186 ( struct V_114 * V_115 , struct V_91 * V_91 )
{
struct V_2 * V_3 ;
char V_336 [ V_337 ] ;
T_3 V_190 ;
struct V_79 * V_82 ;
int V_338 , V_339 ;
struct V_102 * V_103 ;
V_3 = V_115 -> V_340 ;
if ( ! V_3 ) {
F_37 ( V_59 L_103 , F_187 ( V_91 -> V_187 , V_336 ) ) ;
goto V_341;
}
if ( F_94 ( V_91 ) == V_121 ) {
struct V_91 * V_342 = F_188 ( V_91 , V_343 ) ;
struct V_333 * V_334 = F_189 ( V_335 , V_343 ) ;
V_334 -> V_3 = V_3 ;
V_334 -> V_91 = V_91 ;
V_342 -> V_187 = V_3 -> V_48 ;
V_342 -> V_174 = V_334 ;
V_342 -> V_188 = F_185 ;
V_3 -> V_18 . V_22 += F_190 ( V_91 ) ;
F_93 ( V_3 , V_342 ) ;
return;
}
if ( ! F_132 ( V_320 , & V_3 -> V_163 ) ) {
F_37 ( V_59 L_104 ,
V_3 -> V_4 , ( unsigned long long ) V_91 -> V_109 ) ;
goto V_341;
}
if ( ! V_91 -> V_158 || ( V_91 -> V_158 % V_161 ) ) {
F_37 ( V_59 L_105 ) ;
goto V_341;
}
F_191 ( V_115 , & V_91 ) ;
V_190 = F_128 ( V_91 -> V_109 , V_3 ) ;
F_55 ( L_106 ,
( unsigned long long ) V_91 -> V_109 ,
( unsigned long long ) F_100 ( V_91 ) ) ;
{
struct V_344 * V_345 ;
T_3 V_346 ;
int V_347 ;
V_346 = F_128 ( F_100 ( V_91 ) - 1 , V_3 ) ;
if ( V_346 != V_190 ) {
F_52 ( V_346 != V_190 + V_3 -> V_98 . V_99 ) ;
V_347 = V_346 - V_91 -> V_109 ;
V_345 = F_192 ( V_91 , V_347 ) ;
F_52 ( ! V_345 ) ;
F_186 ( V_115 , & V_345 -> V_348 ) ;
F_186 ( V_115 , & V_345 -> V_349 ) ;
F_193 ( V_345 ) ;
return;
}
}
F_11 ( & V_3 -> V_74 . V_209 ) ;
V_339 = 0 ;
F_120 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_82 -> V_175 == V_190 ) {
F_11 ( & V_82 -> V_24 ) ;
if ( ( V_82 -> V_192 == V_208 ) ||
( V_82 -> V_192 == V_215 ) ) {
F_95 ( & V_82 -> V_90 , V_91 ) ;
V_82 -> V_201 += V_91 -> V_158 / V_161 ;
if ( ( V_82 -> V_201 >= V_82 -> V_80 ) &&
( V_82 -> V_192 == V_208 ) ) {
F_101 ( & V_82 -> V_178 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
F_12 ( & V_82 -> V_24 ) ;
F_12 ( & V_3 -> V_74 . V_209 ) ;
return;
} else {
V_339 = 1 ;
}
F_12 ( & V_82 -> V_24 ) ;
}
}
F_12 ( & V_3 -> V_74 . V_209 ) ;
F_11 ( & V_3 -> V_24 ) ;
if ( V_3 -> V_27 > 0
&& V_3 -> V_25 >= V_3 -> V_27 ) {
F_194 ( & V_115 -> V_204 , V_205 ) ;
do {
F_12 ( & V_3 -> V_24 ) ;
F_195 ( V_205 , V_130 ) ;
F_11 ( & V_3 -> V_24 ) ;
} while( V_3 -> V_25 > V_3 -> V_26 );
}
F_12 ( & V_3 -> V_24 ) ;
V_103 = F_189 ( V_3 -> V_106 , V_343 ) ;
V_103 -> V_91 = V_91 ;
F_11 ( & V_3 -> V_24 ) ;
F_52 ( V_3 -> V_25 < 0 ) ;
V_338 = ( V_3 -> V_25 == 0 ) ;
F_79 ( V_3 , V_103 ) ;
F_12 ( & V_3 -> V_24 ) ;
F_56 ( & V_3 -> V_198 , 1 ) ;
if ( V_338 ) {
F_57 ( & V_3 -> V_78 ) ;
} else if ( ! F_67 ( & V_3 -> V_74 . V_96 ) && ! V_339 ) {
F_57 ( & V_3 -> V_78 ) ;
}
return;
V_341:
F_196 ( V_91 ) ;
}
static int F_197 ( struct V_114 * V_115 , struct V_350 * V_351 ,
struct V_165 * V_166 )
{
struct V_2 * V_3 = V_115 -> V_340 ;
T_3 V_190 = F_128 ( V_351 -> V_109 , V_3 ) ;
int V_352 = ( ( V_351 -> V_109 - V_190 ) << 9 ) + V_351 -> V_158 ;
int V_353 = ( V_3 -> V_98 . V_99 << 9 ) - V_352 ;
int V_354 ;
V_354 = V_164 - V_351 -> V_158 ;
V_353 = F_14 ( V_353 , V_354 ) ;
F_52 ( V_353 < 0 ) ;
return V_353 ;
}
static void F_198 ( struct V_2 * V_3 )
{
struct V_114 * V_115 = V_3 -> V_202 -> V_203 ;
F_199 ( V_115 , F_186 ) ;
F_200 ( V_115 , V_161 ) ;
F_176 ( V_115 , V_284 ) ;
F_201 ( V_115 , F_197 ) ;
V_115 -> V_340 = V_3 ;
}
static int F_41 ( struct V_64 * V_65 , void * V_9 )
{
struct V_2 * V_3 = V_65 -> V_355 ;
char * V_356 ;
char V_357 [ V_337 ] ;
int V_221 [ V_222 ] ;
F_202 ( V_65 , L_107 , V_3 -> V_4 ,
F_187 ( V_3 -> V_48 , V_357 ) ) ;
F_202 ( V_65 , L_108 ) ;
F_202 ( V_65 , L_109 , V_3 -> V_98 . V_99 / 2 ) ;
if ( V_3 -> V_98 . V_262 == 0 )
V_356 = L_110 ;
else
V_356 = L_111 ;
F_202 ( V_65 , L_112 , V_356 ) ;
F_202 ( V_65 , L_113 , V_3 -> V_98 . V_232 ? L_66 : L_67 ) ;
F_202 ( V_65 , L_114 , V_3 -> V_98 . V_291 ) ;
F_202 ( V_65 , L_115 , V_3 -> V_98 . V_261 ) ;
if ( V_3 -> V_98 . V_233 == V_267 )
V_356 = L_116 ;
else if ( V_3 -> V_98 . V_233 == V_270 )
V_356 = L_117 ;
else
V_356 = L_111 ;
F_202 ( V_65 , L_118 , V_356 ) ;
F_202 ( V_65 , L_119 ) ;
F_202 ( V_65 , L_120 , V_3 -> V_18 . V_19 ) ;
F_202 ( V_65 , L_121 , V_3 -> V_18 . V_20 ) ;
F_202 ( V_65 , L_122 , V_3 -> V_18 . V_21 >> 1 ) ;
F_202 ( V_65 , L_123 , V_3 -> V_18 . V_23 >> 1 ) ;
F_202 ( V_65 , L_124 , V_3 -> V_18 . V_22 >> 1 ) ;
F_202 ( V_65 , L_125 ) ;
F_202 ( V_65 , L_126 , V_3 -> V_327 ) ;
F_202 ( V_65 , L_127 , V_3 -> V_163 ) ;
F_202 ( V_65 , L_128 , V_3 -> V_148 ) ;
F_202 ( V_65 , L_129 , V_3 -> V_147 ) ;
F_202 ( V_65 , L_130 , V_3 -> V_186 ) ;
F_202 ( V_65 , L_131 , V_3 -> V_259 ) ;
F_202 ( V_65 , L_132 ) ;
F_202 ( V_65 , L_133 , V_3 -> V_25 ) ;
F_202 ( V_65 , L_134 , F_53 ( & V_3 -> V_74 . V_75 ) ) ;
F_202 ( V_65 , L_135 , ( unsigned long long ) V_3 -> V_199 ) ;
F_138 ( V_3 , V_221 ) ;
F_202 ( V_65 , L_136 ,
V_221 [ 0 ] , V_221 [ 1 ] , V_221 [ 2 ] , V_221 [ 3 ] , V_221 [ 4 ] , V_221 [ 5 ] ) ;
F_202 ( V_65 , L_137 ,
V_3 -> V_26 ,
V_3 -> V_27 ) ;
return 0 ;
}
static int F_203 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
return F_43 ( V_67 , F_41 , F_204 ( V_66 ) ) ;
}
static int F_205 ( struct V_2 * V_3 , T_12 V_33 )
{
int V_81 ;
int V_57 = 0 ;
char V_336 [ V_337 ] ;
struct V_324 * V_48 ;
if ( V_3 -> V_47 == V_33 ) {
F_37 ( V_59 L_138 ) ;
return - V_329 ;
}
for ( V_81 = 0 ; V_81 < V_45 ; V_81 ++ ) {
struct V_2 * V_358 = V_46 [ V_81 ] ;
if ( ! V_358 )
continue;
if ( V_358 -> V_48 -> V_49 == V_33 ) {
F_37 ( V_59 L_139 , F_187 ( V_358 -> V_48 , V_336 ) ) ;
return - V_329 ;
}
if ( V_358 -> V_47 == V_33 ) {
F_37 ( V_59 L_140 ) ;
return - V_329 ;
}
}
V_48 = F_171 ( V_33 ) ;
if ( ! V_48 )
return - V_58 ;
V_57 = F_172 ( V_48 , V_315 | V_359 , NULL ) ;
if ( V_57 )
return V_57 ;
F_206 ( V_54 ) ;
V_3 -> V_48 = V_48 ;
F_183 ( V_48 , V_161 ) ;
F_198 ( V_3 ) ;
F_56 ( & V_3 -> V_74 . V_75 , 0 ) ;
V_3 -> V_74 . V_360 = F_207 ( F_139 , V_3 , L_1 , V_3 -> V_4 ) ;
if ( F_20 ( V_3 -> V_74 . V_360 ) ) {
F_37 ( V_59 L_141 ) ;
V_57 = - V_58 ;
goto V_361;
}
F_208 ( V_3 -> V_4 , 0 , V_362 , & V_363 , V_3 ) ;
F_169 ( V_59 L_142 , V_3 -> V_4 , F_187 ( V_48 , V_336 ) ) ;
return 0 ;
V_361:
F_178 ( V_48 , V_315 | V_359 ) ;
F_32 ( V_54 ) ;
return V_57 ;
}
static int F_209 ( struct V_324 * V_48 , T_11 V_325 , unsigned int V_127 , unsigned long V_364 )
{
struct V_2 * V_3 = V_48 -> V_136 -> V_332 ;
int V_57 ;
F_55 ( L_143 , V_127 ,
F_26 ( V_48 -> V_49 ) , F_27 ( V_48 -> V_49 ) ) ;
F_182 ( & V_326 ) ;
switch ( V_127 ) {
case V_365 :
if ( V_3 -> V_327 == 1 )
F_164 ( V_3 , 0 ) ;
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
V_57 = F_210 ( V_3 -> V_48 , V_325 , V_127 , V_364 ) ;
break;
default:
F_55 ( V_59 L_144 , V_3 -> V_4 , V_127 ) ;
V_57 = - V_371 ;
}
F_28 ( & V_326 ) ;
return V_57 ;
}
static unsigned int F_211 ( struct V_331 * V_202 ,
unsigned int V_372 )
{
struct V_2 * V_3 = V_202 -> V_332 ;
struct V_331 * V_373 ;
if ( ! V_3 )
return 0 ;
if ( ! V_3 -> V_48 )
return 0 ;
V_373 = V_3 -> V_48 -> V_136 ;
if ( ! V_373 || ! V_373 -> V_374 -> V_375 )
return 0 ;
return V_373 -> V_374 -> V_375 ( V_373 , V_372 ) ;
}
static char * F_212 ( struct V_331 * V_376 , T_13 * V_325 )
{
return F_213 ( V_10 , L_145 , V_376 -> V_377 ) ;
}
static int F_31 ( T_12 V_33 , T_12 * V_47 )
{
int V_42 ;
int V_57 = - V_58 ;
struct V_2 * V_3 ;
struct V_331 * V_202 ;
F_25 ( & V_43 , V_44 ) ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ )
if ( ! V_46 [ V_42 ] )
break;
if ( V_42 == V_45 ) {
F_37 ( V_59 L_146 , V_45 ) ;
V_57 = - V_329 ;
goto V_378;
}
V_3 = F_2 ( sizeof( struct V_2 ) , V_10 ) ;
if ( ! V_3 )
goto V_378;
V_3 -> V_106 = F_214 ( V_379 ,
sizeof( struct V_102 ) ) ;
if ( ! V_3 -> V_106 )
goto V_361;
F_69 ( & V_3 -> V_74 . V_96 ) ;
F_69 ( & V_3 -> V_74 . V_95 ) ;
F_61 ( & V_3 -> V_74 . V_209 ) ;
F_61 ( & V_3 -> V_24 ) ;
F_61 ( & V_3 -> V_76 . V_24 ) ;
F_62 ( & V_3 -> V_76 . V_150 ) ;
F_62 ( & V_3 -> V_76 . V_151 ) ;
sprintf ( V_3 -> V_4 , V_59 L_13 , V_42 ) ;
F_215 ( & V_3 -> V_78 ) ;
V_3 -> V_105 = V_380 ;
V_3 -> V_27 = V_27 ;
V_3 -> V_26 = V_26 ;
V_202 = F_216 ( 1 ) ;
if ( ! V_202 )
goto V_361;
V_3 -> V_202 = V_202 ;
V_202 -> V_52 = V_381 ;
V_202 -> V_382 = V_42 ;
V_202 -> V_374 = & V_383 ;
V_202 -> V_163 = V_384 ;
strcpy ( V_202 -> V_377 , V_3 -> V_4 ) ;
V_202 -> V_385 = F_212 ;
V_202 -> V_332 = V_3 ;
V_202 -> V_203 = F_217 ( V_10 ) ;
if ( ! V_202 -> V_203 )
goto V_386;
V_3 -> V_47 = F_19 ( V_381 , V_42 ) ;
V_57 = F_205 ( V_3 , V_33 ) ;
if ( V_57 )
goto V_387;
V_202 -> V_388 = V_3 -> V_48 -> V_136 -> V_388 ;
V_202 -> V_389 = V_3 -> V_48 -> V_136 -> V_389 ;
F_218 ( V_202 ) ;
F_17 ( V_3 ) ;
F_44 ( V_3 ) ;
V_46 [ V_42 ] = V_3 ;
if ( V_47 )
* V_47 = V_3 -> V_47 ;
F_28 ( & V_43 ) ;
return 0 ;
V_387:
F_219 ( V_202 -> V_203 ) ;
V_386:
F_220 ( V_202 ) ;
V_361:
if ( V_3 -> V_106 )
F_221 ( V_3 -> V_106 ) ;
F_8 ( V_3 ) ;
V_378:
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
F_169 ( V_59 L_148 ) ;
V_57 = - V_283 ;
goto V_125;
}
if ( V_3 -> V_327 > 0 ) {
V_57 = - V_329 ;
goto V_125;
}
if ( ! F_20 ( V_3 -> V_74 . V_360 ) )
F_222 ( V_3 -> V_74 . V_360 ) ;
V_46 [ V_42 ] = NULL ;
F_47 ( V_3 ) ;
F_21 ( V_3 ) ;
F_178 ( V_3 -> V_48 , V_315 | V_359 ) ;
F_223 ( V_3 -> V_4 , V_362 ) ;
F_169 ( V_59 L_149 , V_3 -> V_4 ) ;
F_224 ( V_3 -> V_202 ) ;
F_219 ( V_3 -> V_202 -> V_203 ) ;
F_220 ( V_3 -> V_202 ) ;
F_221 ( V_3 -> V_106 ) ;
F_8 ( V_3 ) ;
F_32 ( V_54 ) ;
V_125:
F_28 ( & V_43 ) ;
return V_57 ;
}
static void F_225 ( struct V_390 * V_391 )
{
struct V_2 * V_3 ;
F_25 ( & V_43 , V_44 ) ;
V_3 = F_180 ( V_391 -> V_392 ) ;
if ( V_3 ) {
V_391 -> V_33 = F_226 ( V_3 -> V_48 -> V_49 ) ;
V_391 -> V_47 = F_226 ( V_3 -> V_47 ) ;
} else {
V_391 -> V_33 = 0 ;
V_391 -> V_47 = 0 ;
}
V_391 -> V_393 = V_45 ;
F_28 ( & V_43 ) ;
}
static long F_227 ( struct V_67 * V_67 , unsigned int V_127 , unsigned long V_364 )
{
void T_14 * V_394 = ( void T_14 * ) V_364 ;
struct V_390 V_391 ;
int V_57 = 0 ;
T_12 V_47 = 0 ;
if ( V_127 != V_395 )
return - V_371 ;
if ( F_228 ( & V_391 , V_394 , sizeof( struct V_390 ) ) )
return - V_396 ;
switch ( V_391 . V_397 ) {
case V_398 :
if ( ! F_229 ( V_399 ) )
return - V_400 ;
V_57 = F_31 ( F_230 ( V_391 . V_33 ) , & V_47 ) ;
V_391 . V_47 = F_226 ( V_47 ) ;
break;
case V_401 :
if ( ! F_229 ( V_399 ) )
return - V_400 ;
V_57 = F_34 ( F_230 ( V_391 . V_47 ) ) ;
break;
case V_402 :
F_225 ( & V_391 ) ;
break;
default:
return - V_371 ;
}
if ( F_231 ( V_394 , & V_391 , sizeof( struct V_390 ) ) )
return - V_396 ;
return V_57 ;
}
static long F_232 ( struct V_67 * V_67 , unsigned int V_127 , unsigned long V_364 )
{
return F_227 ( V_67 , V_127 , ( unsigned long ) F_233 ( V_364 ) ) ;
}
static int T_15 F_234 ( void )
{
int V_57 ;
F_235 ( & V_43 ) ;
V_335 = F_214 ( V_403 ,
sizeof( struct V_333 ) ) ;
if ( ! V_335 )
return - V_58 ;
V_57 = F_236 ( V_381 , V_59 ) ;
if ( V_57 < 0 ) {
F_37 ( V_59 L_150 ) ;
goto V_404;
}
if ( ! V_381 )
V_381 = V_57 ;
V_57 = F_35 () ;
if ( V_57 )
goto V_125;
F_49 () ;
V_57 = F_237 ( & V_405 ) ;
if ( V_57 ) {
F_37 ( V_59 L_151 ) ;
goto V_406;
}
V_362 = F_238 ( L_152 V_59 , NULL ) ;
return 0 ;
V_406:
F_50 () ;
F_38 () ;
V_125:
F_239 ( V_381 , V_59 ) ;
V_404:
F_221 ( V_335 ) ;
return V_57 ;
}
static void T_16 F_240 ( void )
{
F_223 ( L_152 V_59 , NULL ) ;
F_241 ( & V_405 ) ;
F_50 () ;
F_38 () ;
F_239 ( V_381 , V_59 ) ;
F_221 ( V_335 ) ;
}
