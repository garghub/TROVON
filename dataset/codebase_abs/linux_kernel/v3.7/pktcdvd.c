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
V_3 -> V_76 . V_156 = V_91 -> V_109 + F_100 ( V_91 ) ;
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
static void F_107 ( struct V_91 * V_165 , int V_166 , int V_167 , struct V_168 * V_169 , int V_170 )
{
unsigned int V_171 = V_161 ;
while ( V_171 > 0 ) {
struct V_172 * V_173 = F_108 ( V_165 , V_166 ) ;
void * V_174 = F_109 ( V_173 -> V_175 ) +
V_173 -> V_176 + V_167 ;
void * V_177 = F_110 ( V_169 ) + V_170 ;
int V_30 = F_111 ( int , V_171 , V_173 -> V_178 - V_167 ) ;
F_52 ( V_30 < 0 ) ;
memcpy ( V_177 , V_174 , V_30 ) ;
F_112 ( V_174 ) ;
V_166 ++ ;
V_167 = 0 ;
V_170 += V_30 ;
V_171 -= V_30 ;
}
}
static void F_113 ( struct V_79 * V_82 , struct V_172 * V_179 )
{
int V_180 , V_9 , V_167 ;
V_9 = 0 ;
V_167 = 0 ;
for ( V_180 = 0 ; V_180 < V_82 -> V_80 ; V_180 ++ ) {
if ( V_179 [ V_180 ] . V_175 != V_82 -> V_87 [ V_9 ] ) {
void * V_174 = F_109 ( V_179 [ V_180 ] . V_175 ) + V_179 [ V_180 ] . V_176 ;
void * V_177 = F_110 ( V_82 -> V_87 [ V_9 ] ) + V_167 ;
memcpy ( V_177 , V_174 , V_161 ) ;
F_112 ( V_174 ) ;
V_179 [ V_180 ] . V_175 = V_82 -> V_87 [ V_9 ] ;
V_179 [ V_180 ] . V_176 = V_167 ;
} else {
F_52 ( V_179 [ V_180 ] . V_176 != V_167 ) ;
}
V_167 += V_161 ;
if ( V_167 >= V_164 ) {
V_167 = 0 ;
V_9 ++ ;
}
}
}
static void F_114 ( struct V_91 * V_91 , int V_181 )
{
struct V_79 * V_82 = V_91 -> V_182 ;
struct V_2 * V_3 = V_82 -> V_3 ;
F_52 ( ! V_3 ) ;
F_55 ( L_40 , V_91 ,
( unsigned long long ) V_82 -> V_183 , ( unsigned long long ) V_91 -> V_109 , V_181 ) ;
if ( V_181 )
F_101 ( & V_82 -> V_184 ) ;
if ( F_54 ( & V_82 -> V_185 ) ) {
F_101 ( & V_82 -> V_186 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
F_51 ( V_3 ) ;
}
static void F_115 ( struct V_91 * V_91 , int V_181 )
{
struct V_79 * V_82 = V_91 -> V_182 ;
struct V_2 * V_3 = V_82 -> V_3 ;
F_52 ( ! V_3 ) ;
F_55 ( L_41 , V_82 -> V_100 , V_181 ) ;
V_3 -> V_18 . V_20 ++ ;
F_51 ( V_3 ) ;
F_116 ( & V_82 -> V_185 ) ;
F_101 ( & V_82 -> V_186 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
static void F_117 ( struct V_2 * V_3 , struct V_79 * V_82 )
{
int V_187 = 0 ;
struct V_91 * V_91 ;
int V_180 ;
char V_188 [ V_189 ] ;
F_52 ( F_97 ( & V_82 -> V_90 ) ) ;
F_56 ( & V_82 -> V_185 , 0 ) ;
F_56 ( & V_82 -> V_184 , 0 ) ;
memset ( V_188 , 0 , sizeof( V_188 ) ) ;
F_11 ( & V_82 -> V_24 ) ;
F_118 (bio, &pkt->orig_bios) {
int V_190 = ( V_91 -> V_109 - V_82 -> V_183 ) / ( V_161 >> 9 ) ;
int V_191 = V_91 -> V_158 / V_161 ;
V_3 -> V_18 . V_21 += V_191 * ( V_161 >> 9 ) ;
F_52 ( V_190 < 0 ) ;
F_52 ( V_190 + V_191 > V_82 -> V_80 ) ;
for ( V_180 = V_190 ; V_180 < V_190 + V_191 ; V_180 ++ )
V_188 [ V_180 ] = 1 ;
}
F_12 ( & V_82 -> V_24 ) ;
if ( V_82 -> V_192 ) {
F_55 ( L_42 ,
( unsigned long long ) V_82 -> V_183 ) ;
goto V_193;
}
for ( V_180 = 0 ; V_180 < V_82 -> V_80 ; V_180 ++ ) {
int V_9 , V_194 ;
if ( V_188 [ V_180 ] )
continue;
V_91 = V_82 -> V_93 [ V_180 ] ;
F_119 ( V_91 ) ;
V_91 -> V_109 = V_82 -> V_183 + V_180 * ( V_161 >> 9 ) ;
V_91 -> V_195 = V_3 -> V_48 ;
V_91 -> V_196 = F_114 ;
V_91 -> V_182 = V_82 ;
V_9 = ( V_180 * V_161 ) / V_164 ;
V_194 = ( V_180 * V_161 ) % V_164 ;
F_55 ( L_43 ,
V_180 , V_82 -> V_87 [ V_9 ] , V_194 ) ;
if ( ! F_120 ( V_91 , V_82 -> V_87 [ V_9 ] , V_161 , V_194 ) )
F_121 () ;
F_101 ( & V_82 -> V_185 ) ;
V_91 -> V_197 = V_121 ;
F_93 ( V_3 , V_91 ) ;
V_187 ++ ;
}
V_193:
F_55 ( L_44 ,
V_187 , ( unsigned long long ) V_82 -> V_183 ) ;
V_3 -> V_18 . V_19 ++ ;
V_3 -> V_18 . V_23 += V_187 * ( V_161 >> 9 ) ;
}
static struct V_79 * F_122 ( struct V_2 * V_3 , int V_198 )
{
struct V_79 * V_82 ;
F_123 (pkt, &pd->cdrw.pkt_free_list, list) {
if ( V_82 -> V_183 == V_198 || V_82 -> V_101 . V_94 == & V_3 -> V_74 . V_96 ) {
F_124 ( & V_82 -> V_101 ) ;
if ( V_82 -> V_183 != V_198 )
V_82 -> V_192 = 0 ;
return V_82 ;
}
}
F_121 () ;
return NULL ;
}
static void F_125 ( struct V_2 * V_3 , struct V_79 * V_82 )
{
if ( V_82 -> V_192 ) {
F_71 ( & V_82 -> V_101 , & V_3 -> V_74 . V_96 ) ;
} else {
F_126 ( & V_82 -> V_101 , & V_3 -> V_74 . V_96 ) ;
}
}
static int F_127 ( struct V_79 * V_82 )
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
static inline void F_128 ( struct V_79 * V_82 , enum V_199 V_200 )
{
#if V_201 > 1
static const char * V_202 [] = {
L_45 , L_46 , L_47 , L_48 , L_49 , L_50
} ;
enum V_199 V_203 = V_82 -> V_200 ;
F_55 ( L_51 , V_82 -> V_100 , ( unsigned long long ) V_82 -> V_183 ,
V_202 [ V_203 ] , V_202 [ V_200 ] ) ;
#endif
V_82 -> V_200 = V_200 ;
}
static int F_129 ( struct V_2 * V_3 )
{
struct V_79 * V_82 , * V_9 ;
struct V_91 * V_91 = NULL ;
T_3 V_198 = 0 ;
struct V_102 * V_103 , * V_204 ;
struct V_104 * V_16 ;
int V_205 ;
F_55 ( L_52 ) ;
F_56 ( & V_3 -> V_206 , 0 ) ;
if ( F_67 ( & V_3 -> V_74 . V_96 ) ) {
F_55 ( L_53 ) ;
return 0 ;
}
F_11 ( & V_3 -> V_24 ) ;
V_204 = F_78 ( V_3 , V_3 -> V_207 ) ;
if ( ! V_204 ) {
V_16 = F_130 ( & V_3 -> V_105 ) ;
if ( V_16 )
V_204 = F_74 ( V_16 , struct V_102 , V_104 ) ;
}
V_103 = V_204 ;
while ( V_103 ) {
V_91 = V_103 -> V_91 ;
V_198 = F_131 ( V_91 -> V_109 , V_3 ) ;
F_123 (p, &pd->cdrw.pkt_active_list, list) {
if ( V_9 -> V_183 == V_198 ) {
V_91 = NULL ;
goto V_208;
}
}
break;
V_208:
V_103 = F_72 ( V_103 ) ;
if ( ! V_103 ) {
V_16 = F_130 ( & V_3 -> V_105 ) ;
if ( V_16 )
V_103 = F_74 ( V_16 , struct V_102 , V_104 ) ;
}
if ( V_103 == V_204 )
V_103 = NULL ;
}
F_12 ( & V_3 -> V_24 ) ;
if ( ! V_91 ) {
F_55 ( L_54 ) ;
return 0 ;
}
V_82 = F_122 ( V_3 , V_198 ) ;
V_3 -> V_207 = V_198 + V_3 -> V_98 . V_99 ;
V_82 -> V_183 = V_198 ;
F_52 ( V_82 -> V_80 != V_3 -> V_98 . V_99 >> 2 ) ;
V_82 -> V_209 = 0 ;
F_11 ( & V_3 -> V_24 ) ;
F_55 ( L_55 , ( unsigned long long ) V_198 ) ;
while ( ( V_103 = F_78 ( V_3 , V_198 ) ) != NULL ) {
V_91 = V_103 -> V_91 ;
F_55 ( L_56 ,
( unsigned long long ) F_131 ( V_91 -> V_109 , V_3 ) ) ;
if ( F_131 ( V_91 -> V_109 , V_3 ) != V_198 )
break;
F_75 ( V_3 , V_103 ) ;
F_11 ( & V_82 -> V_24 ) ;
F_95 ( & V_82 -> V_90 , V_91 ) ;
V_82 -> V_209 += V_91 -> V_158 / V_161 ;
F_12 ( & V_82 -> V_24 ) ;
}
V_205 = ( V_3 -> V_27 > 0
&& V_3 -> V_25 <= V_3 -> V_26 ) ;
F_12 ( & V_3 -> V_24 ) ;
if ( V_205 ) {
F_132 ( & V_3 -> V_210 -> V_211 -> V_212 ,
V_213 ) ;
}
V_82 -> V_214 = F_14 ( V_215 , 1 ) ;
F_128 ( V_82 , V_216 ) ;
F_56 ( & V_82 -> V_186 , 1 ) ;
F_11 ( & V_3 -> V_74 . V_217 ) ;
F_71 ( & V_82 -> V_101 , & V_3 -> V_74 . V_95 ) ;
F_12 ( & V_3 -> V_74 . V_217 ) ;
return 1 ;
}
static void F_133 ( struct V_2 * V_3 , struct V_79 * V_82 )
{
struct V_91 * V_91 ;
int V_180 ;
int V_218 ;
struct V_172 * V_179 = V_82 -> V_84 -> V_219 ;
for ( V_180 = 0 ; V_180 < V_82 -> V_80 ; V_180 ++ ) {
V_179 [ V_180 ] . V_175 = V_82 -> V_87 [ ( V_180 * V_161 ) / V_164 ] ;
V_179 [ V_180 ] . V_176 = ( V_180 * V_161 ) % V_164 ;
}
V_218 = 0 ;
F_11 ( & V_82 -> V_24 ) ;
F_118 (bio, &pkt->orig_bios) {
int V_220 = V_91 -> V_221 ;
int V_222 = 0 ;
int V_190 = ( V_91 -> V_109 - V_82 -> V_183 ) / ( V_161 >> 9 ) ;
int V_191 = V_91 -> V_158 / V_161 ;
F_52 ( V_190 < 0 ) ;
F_52 ( V_190 + V_191 > V_82 -> V_80 ) ;
for ( V_180 = V_190 ; V_180 < V_190 + V_191 ; V_180 ++ ) {
struct V_172 * V_173 = F_108 ( V_91 , V_220 ) ;
while ( V_222 >= V_173 -> V_178 ) {
V_222 -= V_173 -> V_178 ;
V_220 ++ ;
F_52 ( V_220 >= V_91 -> V_223 ) ;
V_173 = F_108 ( V_91 , V_220 ) ;
}
if ( V_173 -> V_178 - V_222 >= V_161 ) {
V_179 [ V_180 ] . V_175 = V_173 -> V_175 ;
V_179 [ V_180 ] . V_176 = V_173 -> V_176 + V_222 ;
} else {
F_107 ( V_91 , V_220 , V_222 ,
V_179 [ V_180 ] . V_175 , V_179 [ V_180 ] . V_176 ) ;
}
V_222 += V_161 ;
V_218 ++ ;
}
}
F_128 ( V_82 , V_224 ) ;
F_12 ( & V_82 -> V_24 ) ;
F_55 ( L_57 ,
V_218 , ( unsigned long long ) V_82 -> V_183 ) ;
F_52 ( V_218 != V_82 -> V_209 ) ;
if ( F_134 ( V_162 , & V_3 -> V_163 ) || ( V_82 -> V_209 < V_82 -> V_80 ) ) {
F_113 ( V_82 , V_179 ) ;
V_82 -> V_192 = 1 ;
} else {
V_82 -> V_192 = 0 ;
}
F_119 ( V_82 -> V_84 ) ;
V_82 -> V_84 -> V_109 = V_82 -> V_183 ;
V_82 -> V_84 -> V_195 = V_3 -> V_48 ;
V_82 -> V_84 -> V_196 = F_115 ;
V_82 -> V_84 -> V_182 = V_82 ;
for ( V_180 = 0 ; V_180 < V_82 -> V_80 ; V_180 ++ )
if ( ! F_120 ( V_82 -> V_84 , V_179 [ V_180 ] . V_175 , V_161 , V_179 [ V_180 ] . V_176 ) )
F_121 () ;
F_55 ( V_59 L_58 , V_82 -> V_84 -> V_223 ) ;
F_56 ( & V_82 -> V_185 , 1 ) ;
V_82 -> V_84 -> V_197 = V_120 ;
F_93 ( V_3 , V_82 -> V_84 ) ;
}
static void F_135 ( struct V_79 * V_82 , int V_225 )
{
struct V_91 * V_91 ;
if ( ! V_225 )
V_82 -> V_192 = 0 ;
while ( ( V_91 = F_99 ( & V_82 -> V_90 ) ) )
F_136 ( V_91 , V_225 ? 0 : - V_138 ) ;
}
static void F_137 ( struct V_2 * V_3 , struct V_79 * V_82 )
{
int V_225 ;
F_55 ( L_59 , V_82 -> V_100 ) ;
for (; ; ) {
switch ( V_82 -> V_200 ) {
case V_216 :
if ( ( V_82 -> V_209 < V_82 -> V_80 ) && ( V_82 -> V_214 > 0 ) )
return;
V_82 -> V_214 = 0 ;
F_117 ( V_3 , V_82 ) ;
F_128 ( V_82 , V_226 ) ;
break;
case V_226 :
if ( F_53 ( & V_82 -> V_185 ) > 0 )
return;
if ( F_53 ( & V_82 -> V_184 ) > 0 ) {
F_128 ( V_82 , V_227 ) ;
} else {
F_133 ( V_3 , V_82 ) ;
}
break;
case V_224 :
if ( F_53 ( & V_82 -> V_185 ) > 0 )
return;
if ( F_134 ( V_228 , & V_82 -> V_84 -> V_229 ) ) {
F_128 ( V_82 , V_230 ) ;
} else {
F_128 ( V_82 , V_227 ) ;
}
break;
case V_227 :
if ( F_127 ( V_82 ) ) {
F_133 ( V_3 , V_82 ) ;
} else {
F_55 ( L_60 ) ;
F_128 ( V_82 , V_230 ) ;
}
break;
case V_230 :
V_225 = F_134 ( V_228 , & V_82 -> V_84 -> V_229 ) ;
F_135 ( V_82 , V_225 ) ;
return;
default:
F_121 () ;
break;
}
}
}
static void F_138 ( struct V_2 * V_3 )
{
struct V_79 * V_82 , * V_94 ;
F_55 ( L_61 ) ;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_53 ( & V_82 -> V_186 ) > 0 ) {
F_56 ( & V_82 -> V_186 , 0 ) ;
F_137 ( V_3 , V_82 ) ;
}
}
F_11 ( & V_3 -> V_74 . V_217 ) ;
F_68 (pkt, next, &pd->cdrw.pkt_active_list, list) {
if ( V_82 -> V_200 == V_230 ) {
F_139 ( & V_82 -> V_101 ) ;
F_125 ( V_3 , V_82 ) ;
F_128 ( V_82 , V_231 ) ;
F_56 ( & V_3 -> V_206 , 1 ) ;
}
}
F_12 ( & V_3 -> V_74 . V_217 ) ;
}
static void F_140 ( struct V_2 * V_3 , int * V_232 )
{
struct V_79 * V_82 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < V_233 ; V_81 ++ )
V_232 [ V_81 ] = 0 ;
F_11 ( & V_3 -> V_74 . V_217 ) ;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
V_232 [ V_82 -> V_200 ] ++ ;
}
F_12 ( & V_3 -> V_74 . V_217 ) ;
}
static int F_141 ( void * V_234 )
{
struct V_2 * V_3 = V_234 ;
struct V_79 * V_82 ;
long V_235 , V_236 ;
F_142 ( V_237 , - 20 ) ;
F_143 () ;
for (; ; ) {
F_144 ( V_238 , V_237 ) ;
F_145 ( & V_3 -> V_78 , & V_238 ) ;
for (; ; ) {
F_146 ( V_239 ) ;
if ( F_53 ( & V_3 -> V_206 ) > 0 )
goto V_240;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_53 ( & V_82 -> V_186 ) > 0 )
goto V_240;
}
if ( F_53 ( & V_3 -> V_76 . V_77 ) != 0 )
goto V_240;
if ( V_201 > 1 ) {
int V_232 [ V_233 ] ;
F_140 ( V_3 , V_232 ) ;
F_55 ( L_62 ,
V_232 [ 0 ] , V_232 [ 1 ] , V_232 [ 2 ] , V_232 [ 3 ] ,
V_232 [ 4 ] , V_232 [ 5 ] ) ;
}
V_235 = V_241 ;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_82 -> V_214 && V_82 -> V_214 < V_235 )
V_235 = V_82 -> V_214 ;
}
F_55 ( L_63 ) ;
V_236 = F_147 ( V_235 ) ;
F_55 ( L_64 ) ;
F_148 () ;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( ! V_82 -> V_214 )
continue;
V_82 -> V_214 -= V_235 - V_236 ;
if ( V_82 -> V_214 <= 0 ) {
V_82 -> V_214 = 0 ;
F_101 ( & V_82 -> V_186 ) ;
}
}
if ( F_149 () )
break;
}
V_240:
F_146 ( V_242 ) ;
F_150 ( & V_3 -> V_78 , & V_238 ) ;
if ( F_149 () )
break;
while ( F_129 ( V_3 ) )
;
F_138 ( V_3 ) ;
F_96 ( V_3 ) ;
}
return 0 ;
}
static void F_151 ( struct V_2 * V_3 )
{
F_37 ( V_59 L_65 , V_3 -> V_98 . V_243 ? L_66 : L_67 ) ;
F_37 ( L_68 , V_3 -> V_98 . V_99 >> 2 ) ;
F_37 ( L_69 , V_3 -> V_98 . V_244 == 8 ? '1' : '2' ) ;
}
static int F_152 ( struct V_2 * V_3 , struct V_112 * V_113 , int V_245 , int V_246 )
{
memset ( V_113 -> V_127 , 0 , sizeof( V_113 -> V_127 ) ) ;
V_113 -> V_127 [ 0 ] = V_247 ;
V_113 -> V_127 [ 2 ] = V_245 | ( V_246 << 6 ) ;
V_113 -> V_127 [ 7 ] = V_113 -> V_123 >> 8 ;
V_113 -> V_127 [ 8 ] = V_113 -> V_123 & 0xff ;
V_113 -> V_118 = V_248 ;
return F_82 ( V_3 , V_113 ) ;
}
static int F_153 ( struct V_2 * V_3 , struct V_112 * V_113 )
{
memset ( V_113 -> V_127 , 0 , sizeof( V_113 -> V_127 ) ) ;
memset ( V_113 -> V_124 , 0 , 2 ) ;
V_113 -> V_127 [ 0 ] = V_249 ;
V_113 -> V_127 [ 1 ] = 0x10 ;
V_113 -> V_127 [ 7 ] = V_113 -> V_123 >> 8 ;
V_113 -> V_127 [ 8 ] = V_113 -> V_123 & 0xff ;
V_113 -> V_118 = V_119 ;
return F_82 ( V_3 , V_113 ) ;
}
static int F_154 ( struct V_2 * V_3 , T_5 * V_250 )
{
struct V_112 V_113 ;
int V_57 ;
F_91 ( & V_113 , V_250 , sizeof( * V_250 ) , V_248 ) ;
V_113 . V_127 [ 0 ] = V_251 ;
V_113 . V_127 [ 8 ] = V_113 . V_123 = 2 ;
V_113 . V_133 = 1 ;
if ( ( V_57 = F_82 ( V_3 , & V_113 ) ) )
return V_57 ;
V_113 . V_123 = F_155 ( V_250 -> V_252 ) +
sizeof( V_250 -> V_252 ) ;
if ( V_113 . V_123 > sizeof( T_5 ) )
V_113 . V_123 = sizeof( T_5 ) ;
V_113 . V_127 [ 8 ] = V_113 . V_123 ;
return F_82 ( V_3 , & V_113 ) ;
}
static int F_156 ( struct V_2 * V_3 , T_6 V_253 , T_7 type , T_8 * V_254 )
{
struct V_112 V_113 ;
int V_57 ;
F_91 ( & V_113 , V_254 , 8 , V_248 ) ;
V_113 . V_127 [ 0 ] = V_255 ;
V_113 . V_127 [ 1 ] = type & 3 ;
V_113 . V_127 [ 4 ] = ( V_253 & 0xff00 ) >> 8 ;
V_113 . V_127 [ 5 ] = V_253 & 0xff ;
V_113 . V_127 [ 8 ] = 8 ;
V_113 . V_133 = 1 ;
if ( ( V_57 = F_82 ( V_3 , & V_113 ) ) )
return V_57 ;
V_113 . V_123 = F_155 ( V_254 -> V_256 ) +
sizeof( V_254 -> V_256 ) ;
if ( V_113 . V_123 > sizeof( T_8 ) )
V_113 . V_123 = sizeof( T_8 ) ;
V_113 . V_127 [ 8 ] = V_113 . V_123 ;
return F_82 ( V_3 , & V_113 ) ;
}
static T_4 int F_157 ( struct V_2 * V_3 ,
long * V_257 )
{
T_5 V_250 ;
T_8 V_254 ;
T_9 V_258 ;
int V_57 = - 1 ;
if ( ( V_57 = F_154 ( V_3 , & V_250 ) ) )
return V_57 ;
V_258 = ( V_250 . V_259 << 8 ) | V_250 . V_260 ;
if ( ( V_57 = F_156 ( V_3 , V_258 , 1 , & V_254 ) ) )
return V_57 ;
if ( V_254 . V_261 ) {
V_258 -- ;
if ( ( V_57 = F_156 ( V_3 , V_258 , 1 , & V_254 ) ) )
return V_57 ;
}
if ( V_254 . V_262 ) {
* V_257 = F_158 ( V_254 . V_263 ) ;
} else {
* V_257 = F_158 ( V_254 . V_264 ) +
F_158 ( V_254 . V_265 ) ;
if ( V_254 . V_266 )
* V_257 -= ( F_158 ( V_254 . V_266 ) + 7 ) ;
}
return 0 ;
}
static T_4 int F_159 ( struct V_2 * V_3 )
{
struct V_112 V_113 ;
struct V_140 V_141 ;
T_10 * V_267 ;
char V_124 [ 128 ] ;
int V_57 , V_99 ;
if ( ( V_3 -> V_268 == 0x1a ) || ( V_3 -> V_268 == 0x12 ) )
return 0 ;
memset ( V_124 , 0 , sizeof( V_124 ) ) ;
F_91 ( & V_113 , V_124 , sizeof( * V_267 ) , V_248 ) ;
V_113 . V_141 = & V_141 ;
if ( ( V_57 = F_152 ( V_3 , & V_113 , V_269 , 0 ) ) ) {
F_89 ( & V_113 ) ;
return V_57 ;
}
V_99 = 2 + ( ( V_124 [ 0 ] << 8 ) | ( V_124 [ 1 ] & 0xff ) ) ;
V_3 -> V_270 = ( V_124 [ 6 ] << 8 ) | ( V_124 [ 7 ] & 0xff ) ;
if ( V_99 > sizeof( V_124 ) )
V_99 = sizeof( V_124 ) ;
F_91 ( & V_113 , V_124 , V_99 , V_248 ) ;
V_113 . V_141 = & V_141 ;
if ( ( V_57 = F_152 ( V_3 , & V_113 , V_269 , 0 ) ) ) {
F_89 ( & V_113 ) ;
return V_57 ;
}
V_267 = ( T_10 * ) & V_124 [ sizeof( struct V_271 ) + V_3 -> V_270 ] ;
V_267 -> V_243 = V_3 -> V_98 . V_243 ;
V_267 -> V_272 = V_3 -> V_98 . V_272 ;
V_267 -> V_273 = V_3 -> V_98 . V_273 ;
V_267 -> V_274 = V_3 -> V_98 . V_244 ;
V_267 -> V_275 = 0 ;
#ifdef F_160
V_267 -> V_276 = 7 ;
V_267 -> V_277 = 1 ;
#endif
if ( V_267 -> V_274 == V_278 ) {
V_267 -> V_279 = 0 ;
V_267 -> V_280 = 0x20 ;
} else if ( V_267 -> V_274 == V_281 ) {
V_267 -> V_279 = 0x20 ;
V_267 -> V_280 = 8 ;
#if 0
wp->mcn[0] = 0x80;
memcpy(&wp->mcn[1], PACKET_MCN, sizeof(wp->mcn) - 1);
#endif
} else {
F_37 ( V_59 L_70 , V_267 -> V_274 ) ;
return 1 ;
}
V_267 -> V_282 = F_161 ( V_3 -> V_98 . V_99 >> 2 ) ;
V_113 . V_123 = V_113 . V_127 [ 8 ] = V_99 ;
if ( ( V_57 = F_153 ( V_3 , & V_113 ) ) ) {
F_89 ( & V_113 ) ;
return V_57 ;
}
F_151 ( V_3 ) ;
return 0 ;
}
static int F_162 ( struct V_2 * V_3 , T_8 * V_254 )
{
switch ( V_3 -> V_268 ) {
case 0x1a :
case 0x12 :
return 1 ;
default:
break;
}
if ( ! V_254 -> V_283 || ! V_254 -> V_243 )
return 0 ;
if ( V_254 -> V_284 == 0 && V_254 -> V_261 == 0 )
return 1 ;
if ( V_254 -> V_284 == 0 && V_254 -> V_261 == 1 )
return 1 ;
if ( V_254 -> V_284 == 1 && V_254 -> V_261 == 0 )
return 1 ;
F_37 ( V_59 L_71 , V_254 -> V_284 , V_254 -> V_261 , V_254 -> V_283 ) ;
return 0 ;
}
static int F_163 ( struct V_2 * V_3 , T_5 * V_250 )
{
switch ( V_3 -> V_268 ) {
case 0x0a :
case 0xffff :
break;
case 0x1a :
case 0x13 :
case 0x12 :
return 1 ;
default:
F_55 ( V_59 L_72 , V_3 -> V_268 ) ;
return 0 ;
}
if ( V_250 -> V_285 == 0xff ) {
F_37 ( V_59 L_73 ) ;
return 0 ;
}
if ( V_250 -> V_285 != 0x20 && V_250 -> V_285 != 0 ) {
F_37 ( V_59 L_74 , V_250 -> V_285 ) ;
return 0 ;
}
if ( V_250 -> V_286 == 0 ) {
F_37 ( V_59 L_75 ) ;
return 0 ;
}
if ( V_250 -> V_287 == V_288 ) {
F_37 ( V_59 L_76 ) ;
return 0 ;
}
return 1 ;
}
static T_4 int F_164 ( struct V_2 * V_3 )
{
struct V_112 V_113 ;
unsigned char V_50 [ 12 ] ;
T_5 V_250 ;
T_8 V_254 ;
int V_57 , V_253 ;
F_91 ( & V_113 , V_50 , sizeof( V_50 ) , V_248 ) ;
V_113 . V_127 [ 0 ] = V_289 ;
V_113 . V_127 [ 8 ] = 8 ;
V_57 = F_82 ( V_3 , & V_113 ) ;
V_3 -> V_268 = V_57 ? 0xffff : V_50 [ 6 ] << 8 | V_50 [ 7 ] ;
memset ( & V_250 , 0 , sizeof( T_5 ) ) ;
memset ( & V_254 , 0 , sizeof( T_8 ) ) ;
if ( ( V_57 = F_154 ( V_3 , & V_250 ) ) ) {
F_37 ( L_77 ) ;
return V_57 ;
}
if ( ! F_163 ( V_3 , & V_250 ) )
return - V_290 ;
V_3 -> type = V_250 . V_286 ? V_291 : V_292 ;
V_253 = 1 ;
if ( ( V_57 = F_156 ( V_3 , V_253 , 1 , & V_254 ) ) ) {
F_37 ( V_59 L_78 ) ;
return V_57 ;
}
if ( ! F_162 ( V_3 , & V_254 ) ) {
F_37 ( V_59 L_79 ) ;
return - V_290 ;
}
V_3 -> V_98 . V_99 = F_158 ( V_254 . V_293 ) << 2 ;
if ( V_3 -> V_98 . V_99 == 0 ) {
F_37 ( V_59 L_80 ) ;
return - V_294 ;
}
if ( V_3 -> V_98 . V_99 > V_295 ) {
F_37 ( V_59 L_81 ) ;
return - V_290 ;
}
V_3 -> V_98 . V_243 = V_254 . V_243 ;
V_3 -> V_194 = ( F_158 ( V_254 . V_264 ) << 2 ) & ( V_3 -> V_98 . V_99 - 1 ) ;
if ( V_254 . V_296 ) {
V_3 -> V_297 = F_158 ( V_254 . V_298 ) ;
F_106 ( V_299 , & V_3 -> V_163 ) ;
}
if ( V_254 . V_262 ) {
V_3 -> V_300 = F_158 ( V_254 . V_263 ) ;
F_106 ( V_301 , & V_3 -> V_163 ) ;
} else {
V_3 -> V_300 = 0xffffffff ;
F_106 ( V_301 , & V_3 -> V_163 ) ;
}
V_3 -> V_98 . V_302 = 7 ;
V_3 -> V_98 . V_273 = 0 ;
V_3 -> V_98 . V_272 = V_254 . V_272 ;
switch ( V_254 . V_303 ) {
case V_304 :
V_3 -> V_98 . V_244 = V_278 ;
break;
case V_305 :
V_3 -> V_98 . V_244 = V_281 ;
break;
default:
F_37 ( V_59 L_82 ) ;
return - V_290 ;
}
return 0 ;
}
static T_4 int F_165 ( struct V_2 * V_3 ,
int V_306 )
{
struct V_112 V_113 ;
struct V_140 V_141 ;
unsigned char V_50 [ 64 ] ;
int V_57 ;
F_91 ( & V_113 , V_50 , sizeof( V_50 ) , V_248 ) ;
V_113 . V_141 = & V_141 ;
V_113 . V_123 = V_3 -> V_270 + 12 ;
V_113 . V_133 = 1 ;
if ( ( V_57 = F_152 ( V_3 , & V_113 , V_307 , 0 ) ) )
return V_57 ;
V_50 [ V_3 -> V_270 + 10 ] |= ( ! ! V_306 << 2 ) ;
V_113 . V_123 = V_113 . V_127 [ 8 ] = 2 + ( ( V_50 [ 0 ] << 8 ) | ( V_50 [ 1 ] & 0xff ) ) ;
V_57 = F_153 ( V_3 , & V_113 ) ;
if ( V_57 ) {
F_37 ( V_59 L_83 ) ;
F_89 ( & V_113 ) ;
} else if ( ! V_57 && V_306 )
F_37 ( V_59 L_84 , V_3 -> V_4 ) ;
return V_57 ;
}
static int F_166 ( struct V_2 * V_3 , int V_308 )
{
struct V_112 V_113 ;
F_91 ( & V_113 , NULL , 0 , V_145 ) ;
V_113 . V_127 [ 0 ] = V_309 ;
V_113 . V_127 [ 4 ] = V_308 ? 1 : 0 ;
return F_82 ( V_3 , & V_113 ) ;
}
static T_4 int F_167 ( struct V_2 * V_3 ,
unsigned * V_147 )
{
struct V_112 V_113 ;
struct V_140 V_141 ;
unsigned char V_50 [ 256 + 18 ] ;
unsigned char * V_310 ;
int V_57 , V_194 ;
V_310 = & V_50 [ sizeof( struct V_271 ) + V_3 -> V_270 ] ;
F_91 ( & V_113 , V_50 , sizeof( V_50 ) , V_311 ) ;
V_113 . V_141 = & V_141 ;
V_57 = F_152 ( V_3 , & V_113 , V_312 , 0 ) ;
if ( V_57 ) {
V_113 . V_123 = V_3 -> V_270 + V_310 [ 1 ] + 2 +
sizeof( struct V_271 ) ;
V_57 = F_152 ( V_3 , & V_113 , V_312 , 0 ) ;
if ( V_57 ) {
F_89 ( & V_113 ) ;
return V_57 ;
}
}
V_194 = 20 ;
if ( V_310 [ 1 ] >= 28 )
V_194 = 28 ;
if ( V_310 [ 1 ] >= 30 ) {
int V_313 = ( V_310 [ 30 ] << 8 ) + V_310 [ 31 ] ;
if ( V_313 > 0 )
V_194 = 34 ;
}
* V_147 = ( V_310 [ V_194 ] << 8 ) | V_310 [ V_194 + 1 ] ;
return 0 ;
}
static T_4 int F_168 ( struct V_2 * V_3 ,
unsigned * V_314 )
{
struct V_112 V_113 ;
struct V_140 V_141 ;
unsigned char V_50 [ 64 ] ;
unsigned int V_99 , V_315 , V_316 ;
int V_57 ;
F_91 ( & V_113 , V_50 , 2 , V_248 ) ;
V_113 . V_141 = & V_141 ;
V_113 . V_127 [ 0 ] = V_317 ;
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
F_91 ( & V_113 , V_50 , V_99 , V_248 ) ;
V_113 . V_141 = & V_141 ;
V_113 . V_127 [ 0 ] = V_317 ;
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
V_315 = ( V_50 [ 6 ] >> 3 ) & 0x7 ;
V_316 = V_50 [ 16 ] & 0xf ;
switch ( V_315 ) {
case 0 :
* V_314 = V_318 [ V_316 ] ;
break;
case 1 :
* V_314 = V_319 [ V_316 ] ;
break;
case 2 :
* V_314 = V_320 [ V_316 ] ;
break;
default:
F_37 ( V_59 L_87 , V_315 ) ;
return 1 ;
}
if ( * V_314 ) {
F_37 ( V_59 L_88 , * V_314 ) ;
return 0 ;
} else {
F_37 ( V_59 L_89 , V_316 , V_315 ) ;
return 1 ;
}
}
static T_4 int F_169 ( struct V_2 * V_3 )
{
struct V_112 V_113 ;
struct V_140 V_141 ;
int V_57 ;
F_55 ( V_59 L_90 ) ;
F_91 ( & V_113 , NULL , 0 , V_145 ) ;
V_113 . V_141 = & V_141 ;
V_113 . V_129 = 60 * V_130 ;
V_113 . V_127 [ 0 ] = V_321 ;
V_113 . V_127 [ 1 ] = 1 ;
if ( ( V_57 = F_82 ( V_3 , & V_113 ) ) )
F_89 ( & V_113 ) ;
return V_57 ;
}
static int F_170 ( struct V_2 * V_3 )
{
int V_57 ;
unsigned int V_147 , V_322 , V_148 ;
if ( ( V_57 = F_164 ( V_3 ) ) ) {
F_55 ( V_59 L_91 , V_3 -> V_4 ) ;
return V_57 ;
}
if ( ( V_57 = F_159 ( V_3 ) ) ) {
F_171 ( V_59 L_92 , V_3 -> V_4 ) ;
return - V_138 ;
}
F_165 ( V_3 , V_323 ) ;
if ( ( V_57 = F_167 ( V_3 , & V_147 ) ) )
V_147 = 16 * 177 ;
switch ( V_3 -> V_268 ) {
case 0x13 :
case 0x1a :
case 0x12 :
F_171 ( V_59 L_93 , V_147 ) ;
break;
default:
if ( ( V_57 = F_168 ( V_3 , & V_322 ) ) )
V_322 = 16 ;
V_147 = F_15 ( V_147 , V_322 * 177 ) ;
F_171 ( V_59 L_94 , V_147 / 176 ) ;
break;
}
V_148 = V_147 ;
if ( ( V_57 = F_92 ( V_3 , V_147 , V_148 ) ) ) {
F_171 ( V_59 L_95 , V_3 -> V_4 ) ;
return - V_138 ;
}
V_3 -> V_147 = V_147 ;
V_3 -> V_148 = V_148 ;
if ( ( V_57 = F_169 ( V_3 ) ) ) {
F_171 ( V_59 L_96 , V_3 -> V_4 ) ;
}
return 0 ;
}
static int F_172 ( struct V_2 * V_3 , T_11 V_324 )
{
int V_57 ;
long V_325 ;
struct V_114 * V_115 ;
F_173 ( V_3 -> V_48 -> V_49 ) ;
if ( ( V_57 = F_174 ( V_3 -> V_48 , V_326 | V_327 , V_3 ) ) )
goto V_125;
if ( ( V_57 = F_157 ( V_3 , & V_325 ) ) ) {
F_37 ( V_59 L_97 ) ;
goto V_328;
}
F_175 ( V_3 -> V_210 , V_325 << 2 ) ;
F_175 ( V_3 -> V_48 -> V_136 , V_325 << 2 ) ;
F_176 ( V_3 -> V_48 , ( V_329 ) V_325 << 11 ) ;
V_115 = F_83 ( V_3 -> V_48 ) ;
if ( V_324 ) {
if ( ( V_57 = F_170 ( V_3 ) ) )
goto V_328;
F_177 ( V_115 -> V_330 ) ;
F_178 ( V_115 , V_3 -> V_98 . V_99 ) ;
F_179 ( V_115 -> V_330 ) ;
F_106 ( V_331 , & V_3 -> V_163 ) ;
} else {
F_92 ( V_3 , V_160 , V_160 ) ;
F_105 ( V_331 , & V_3 -> V_163 ) ;
}
if ( ( V_57 = F_103 ( V_3 , V_115 ) ) )
goto V_328;
if ( V_324 ) {
if ( ! F_70 ( V_3 , V_332 ) ) {
F_37 ( V_59 L_98 ) ;
V_57 = - V_58 ;
goto V_328;
}
F_37 ( V_59 L_99 , V_325 << 1 ) ;
}
return 0 ;
V_328:
F_180 ( V_3 -> V_48 , V_326 | V_327 ) ;
V_125:
return V_57 ;
}
static void F_181 ( struct V_2 * V_3 , int V_333 )
{
if ( V_333 && F_90 ( V_3 ) )
F_171 ( V_59 L_100 , V_3 -> V_4 ) ;
F_166 ( V_3 , 0 ) ;
F_92 ( V_3 , V_160 , V_160 ) ;
F_180 ( V_3 -> V_48 , V_326 | V_327 ) ;
F_66 ( V_3 ) ;
}
static struct V_2 * F_182 ( unsigned int V_334 )
{
if ( V_334 >= V_45 )
return NULL ;
return V_46 [ V_334 ] ;
}
static int F_183 ( struct V_335 * V_48 , T_11 V_336 )
{
struct V_2 * V_3 = NULL ;
int V_57 ;
F_55 ( V_59 L_101 ) ;
F_184 ( & V_337 ) ;
F_184 ( & V_43 ) ;
V_3 = F_182 ( F_27 ( V_48 -> V_49 ) ) ;
if ( ! V_3 ) {
V_57 = - V_55 ;
goto V_125;
}
F_52 ( V_3 -> V_338 < 0 ) ;
V_3 -> V_338 ++ ;
if ( V_3 -> V_338 > 1 ) {
if ( ( V_336 & V_339 ) &&
! F_134 ( V_331 , & V_3 -> V_163 ) ) {
V_57 = - V_340 ;
goto V_341;
}
} else {
V_57 = F_172 ( V_3 , V_336 & V_339 ) ;
if ( V_57 )
goto V_341;
F_185 ( V_48 , V_161 ) ;
}
F_28 ( & V_43 ) ;
F_28 ( & V_337 ) ;
return 0 ;
V_341:
V_3 -> V_338 -- ;
V_125:
F_55 ( V_59 L_102 , V_57 ) ;
F_28 ( & V_43 ) ;
F_28 ( & V_337 ) ;
return V_57 ;
}
static int F_186 ( struct V_342 * V_210 , T_11 V_336 )
{
struct V_2 * V_3 = V_210 -> V_343 ;
int V_57 = 0 ;
F_184 ( & V_337 ) ;
F_184 ( & V_43 ) ;
V_3 -> V_338 -- ;
F_52 ( V_3 -> V_338 < 0 ) ;
if ( V_3 -> V_338 == 0 ) {
int V_333 = F_134 ( V_331 , & V_3 -> V_163 ) ;
F_181 ( V_3 , V_333 ) ;
}
F_28 ( & V_43 ) ;
F_28 ( & V_337 ) ;
return V_57 ;
}
static void F_187 ( struct V_91 * V_91 , int V_181 )
{
struct V_344 * V_345 = V_91 -> V_182 ;
struct V_2 * V_3 = V_345 -> V_3 ;
F_63 ( V_91 ) ;
F_136 ( V_345 -> V_91 , V_181 ) ;
F_77 ( V_345 , V_346 ) ;
F_51 ( V_3 ) ;
}
static void F_188 ( struct V_114 * V_115 , struct V_91 * V_91 )
{
struct V_2 * V_3 ;
char V_347 [ V_348 ] ;
T_3 V_198 ;
struct V_79 * V_82 ;
int V_349 , V_350 ;
struct V_102 * V_103 ;
V_3 = V_115 -> V_351 ;
if ( ! V_3 ) {
F_37 ( V_59 L_103 , F_189 ( V_91 -> V_195 , V_347 ) ) ;
goto V_352;
}
if ( F_94 ( V_91 ) == V_121 ) {
struct V_91 * V_353 = F_190 ( V_91 , V_354 ) ;
struct V_344 * V_345 = F_191 ( V_346 , V_354 ) ;
V_345 -> V_3 = V_3 ;
V_345 -> V_91 = V_91 ;
V_353 -> V_195 = V_3 -> V_48 ;
V_353 -> V_182 = V_345 ;
V_353 -> V_196 = F_187 ;
V_3 -> V_18 . V_22 += V_91 -> V_158 >> 9 ;
F_93 ( V_3 , V_353 ) ;
return;
}
if ( ! F_134 ( V_331 , & V_3 -> V_163 ) ) {
F_37 ( V_59 L_104 ,
V_3 -> V_4 , ( unsigned long long ) V_91 -> V_109 ) ;
goto V_352;
}
if ( ! V_91 -> V_158 || ( V_91 -> V_158 % V_161 ) ) {
F_37 ( V_59 L_105 ) ;
goto V_352;
}
F_192 ( V_115 , & V_91 ) ;
V_198 = F_131 ( V_91 -> V_109 , V_3 ) ;
F_55 ( L_106 ,
( unsigned long long ) V_91 -> V_109 ,
( unsigned long long ) ( V_91 -> V_109 + F_100 ( V_91 ) ) ) ;
{
struct V_355 * V_356 ;
T_3 V_357 ;
int V_358 ;
V_357 = F_131 ( V_91 -> V_109 + F_100 ( V_91 ) - 1 , V_3 ) ;
if ( V_357 != V_198 ) {
F_52 ( V_357 != V_198 + V_3 -> V_98 . V_99 ) ;
V_358 = V_357 - V_91 -> V_109 ;
V_356 = F_193 ( V_91 , V_358 ) ;
F_52 ( ! V_356 ) ;
F_188 ( V_115 , & V_356 -> V_359 ) ;
F_188 ( V_115 , & V_356 -> V_360 ) ;
F_194 ( V_356 ) ;
return;
}
}
F_11 ( & V_3 -> V_74 . V_217 ) ;
V_350 = 0 ;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_82 -> V_183 == V_198 ) {
F_11 ( & V_82 -> V_24 ) ;
if ( ( V_82 -> V_200 == V_216 ) ||
( V_82 -> V_200 == V_226 ) ) {
F_95 ( & V_82 -> V_90 , V_91 ) ;
V_82 -> V_209 += V_91 -> V_158 / V_161 ;
if ( ( V_82 -> V_209 >= V_82 -> V_80 ) &&
( V_82 -> V_200 == V_216 ) ) {
F_101 ( & V_82 -> V_186 ) ;
F_57 ( & V_3 -> V_78 ) ;
}
F_12 ( & V_82 -> V_24 ) ;
F_12 ( & V_3 -> V_74 . V_217 ) ;
return;
} else {
V_350 = 1 ;
}
F_12 ( & V_82 -> V_24 ) ;
}
}
F_12 ( & V_3 -> V_74 . V_217 ) ;
F_11 ( & V_3 -> V_24 ) ;
if ( V_3 -> V_27 > 0
&& V_3 -> V_25 >= V_3 -> V_27 ) {
F_195 ( & V_115 -> V_212 , V_213 ) ;
do {
F_12 ( & V_3 -> V_24 ) ;
F_196 ( V_213 , V_130 ) ;
F_11 ( & V_3 -> V_24 ) ;
} while( V_3 -> V_25 > V_3 -> V_26 );
}
F_12 ( & V_3 -> V_24 ) ;
V_103 = F_191 ( V_3 -> V_106 , V_354 ) ;
V_103 -> V_91 = V_91 ;
F_11 ( & V_3 -> V_24 ) ;
F_52 ( V_3 -> V_25 < 0 ) ;
V_349 = ( V_3 -> V_25 == 0 ) ;
F_79 ( V_3 , V_103 ) ;
F_12 ( & V_3 -> V_24 ) ;
F_56 ( & V_3 -> V_206 , 1 ) ;
if ( V_349 ) {
F_57 ( & V_3 -> V_78 ) ;
} else if ( ! F_67 ( & V_3 -> V_74 . V_96 ) && ! V_350 ) {
F_57 ( & V_3 -> V_78 ) ;
}
return;
V_352:
F_197 ( V_91 ) ;
}
static int F_198 ( struct V_114 * V_115 , struct V_361 * V_362 ,
struct V_172 * V_179 )
{
struct V_2 * V_3 = V_115 -> V_351 ;
T_3 V_198 = F_131 ( V_362 -> V_109 , V_3 ) ;
int V_363 = ( ( V_362 -> V_109 - V_198 ) << 9 ) + V_362 -> V_158 ;
int V_364 = ( V_3 -> V_98 . V_99 << 9 ) - V_363 ;
int V_365 ;
V_365 = V_164 - V_362 -> V_158 ;
V_364 = F_14 ( V_364 , V_365 ) ;
F_52 ( V_364 < 0 ) ;
return V_364 ;
}
static void F_199 ( struct V_2 * V_3 )
{
struct V_114 * V_115 = V_3 -> V_210 -> V_211 ;
F_200 ( V_115 , F_188 ) ;
F_201 ( V_115 , V_161 ) ;
F_178 ( V_115 , V_295 ) ;
F_202 ( V_115 , F_198 ) ;
V_115 -> V_351 = V_3 ;
}
static int F_41 ( struct V_64 * V_65 , void * V_9 )
{
struct V_2 * V_3 = V_65 -> V_366 ;
char * V_367 ;
char V_368 [ V_348 ] ;
int V_232 [ V_233 ] ;
F_203 ( V_65 , L_107 , V_3 -> V_4 ,
F_189 ( V_3 -> V_48 , V_368 ) ) ;
F_203 ( V_65 , L_108 ) ;
F_203 ( V_65 , L_109 , V_3 -> V_98 . V_99 / 2 ) ;
if ( V_3 -> V_98 . V_273 == 0 )
V_367 = L_110 ;
else
V_367 = L_111 ;
F_203 ( V_65 , L_112 , V_367 ) ;
F_203 ( V_65 , L_113 , V_3 -> V_98 . V_243 ? L_66 : L_67 ) ;
F_203 ( V_65 , L_114 , V_3 -> V_98 . V_302 ) ;
F_203 ( V_65 , L_115 , V_3 -> V_98 . V_272 ) ;
if ( V_3 -> V_98 . V_244 == V_278 )
V_367 = L_116 ;
else if ( V_3 -> V_98 . V_244 == V_281 )
V_367 = L_117 ;
else
V_367 = L_111 ;
F_203 ( V_65 , L_118 , V_367 ) ;
F_203 ( V_65 , L_119 ) ;
F_203 ( V_65 , L_120 , V_3 -> V_18 . V_19 ) ;
F_203 ( V_65 , L_121 , V_3 -> V_18 . V_20 ) ;
F_203 ( V_65 , L_122 , V_3 -> V_18 . V_21 >> 1 ) ;
F_203 ( V_65 , L_123 , V_3 -> V_18 . V_23 >> 1 ) ;
F_203 ( V_65 , L_124 , V_3 -> V_18 . V_22 >> 1 ) ;
F_203 ( V_65 , L_125 ) ;
F_203 ( V_65 , L_126 , V_3 -> V_338 ) ;
F_203 ( V_65 , L_127 , V_3 -> V_163 ) ;
F_203 ( V_65 , L_128 , V_3 -> V_148 ) ;
F_203 ( V_65 , L_129 , V_3 -> V_147 ) ;
F_203 ( V_65 , L_130 , V_3 -> V_194 ) ;
F_203 ( V_65 , L_131 , V_3 -> V_270 ) ;
F_203 ( V_65 , L_132 ) ;
F_203 ( V_65 , L_133 , V_3 -> V_25 ) ;
F_203 ( V_65 , L_134 , F_53 ( & V_3 -> V_74 . V_75 ) ) ;
F_203 ( V_65 , L_135 , ( unsigned long long ) V_3 -> V_207 ) ;
F_140 ( V_3 , V_232 ) ;
F_203 ( V_65 , L_136 ,
V_232 [ 0 ] , V_232 [ 1 ] , V_232 [ 2 ] , V_232 [ 3 ] , V_232 [ 4 ] , V_232 [ 5 ] ) ;
F_203 ( V_65 , L_137 ,
V_3 -> V_26 ,
V_3 -> V_27 ) ;
return 0 ;
}
static int F_204 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
return F_43 ( V_67 , F_41 , F_205 ( V_66 ) -> V_15 ) ;
}
static int F_206 ( struct V_2 * V_3 , T_12 V_33 )
{
int V_81 ;
int V_57 = 0 ;
char V_347 [ V_348 ] ;
struct V_335 * V_48 ;
if ( V_3 -> V_47 == V_33 ) {
F_37 ( V_59 L_138 ) ;
return - V_340 ;
}
for ( V_81 = 0 ; V_81 < V_45 ; V_81 ++ ) {
struct V_2 * V_369 = V_46 [ V_81 ] ;
if ( ! V_369 )
continue;
if ( V_369 -> V_48 -> V_49 == V_33 ) {
F_37 ( V_59 L_139 , F_189 ( V_369 -> V_48 , V_347 ) ) ;
return - V_340 ;
}
if ( V_369 -> V_47 == V_33 ) {
F_37 ( V_59 L_140 ) ;
return - V_340 ;
}
}
V_48 = F_173 ( V_33 ) ;
if ( ! V_48 )
return - V_58 ;
V_57 = F_174 ( V_48 , V_326 | V_370 , NULL ) ;
if ( V_57 )
return V_57 ;
F_207 ( V_54 ) ;
V_3 -> V_48 = V_48 ;
F_185 ( V_48 , V_161 ) ;
F_199 ( V_3 ) ;
F_56 ( & V_3 -> V_74 . V_75 , 0 ) ;
V_3 -> V_74 . V_371 = F_208 ( F_141 , V_3 , L_1 , V_3 -> V_4 ) ;
if ( F_20 ( V_3 -> V_74 . V_371 ) ) {
F_37 ( V_59 L_141 ) ;
V_57 = - V_58 ;
goto V_372;
}
F_209 ( V_3 -> V_4 , 0 , V_373 , & V_374 , V_3 ) ;
F_171 ( V_59 L_142 , V_3 -> V_4 , F_189 ( V_48 , V_347 ) ) ;
return 0 ;
V_372:
F_180 ( V_48 , V_326 | V_370 ) ;
F_32 ( V_54 ) ;
return V_57 ;
}
static int F_210 ( struct V_335 * V_48 , T_11 V_336 , unsigned int V_127 , unsigned long V_375 )
{
struct V_2 * V_3 = V_48 -> V_136 -> V_343 ;
int V_57 ;
F_55 ( L_143 , V_127 ,
F_26 ( V_48 -> V_49 ) , F_27 ( V_48 -> V_49 ) ) ;
F_184 ( & V_337 ) ;
switch ( V_127 ) {
case V_376 :
if ( V_3 -> V_338 == 1 )
F_166 ( V_3 , 0 ) ;
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
V_57 = F_211 ( V_3 -> V_48 , V_336 , V_127 , V_375 ) ;
break;
default:
F_55 ( V_59 L_144 , V_3 -> V_4 , V_127 ) ;
V_57 = - V_382 ;
}
F_28 ( & V_337 ) ;
return V_57 ;
}
static unsigned int F_212 ( struct V_342 * V_210 ,
unsigned int V_383 )
{
struct V_2 * V_3 = V_210 -> V_343 ;
struct V_342 * V_384 ;
if ( ! V_3 )
return 0 ;
if ( ! V_3 -> V_48 )
return 0 ;
V_384 = V_3 -> V_48 -> V_136 ;
if ( ! V_384 || ! V_384 -> V_385 -> V_386 )
return 0 ;
return V_384 -> V_385 -> V_386 ( V_384 , V_383 ) ;
}
static char * F_213 ( struct V_342 * V_387 , T_13 * V_336 )
{
return F_214 ( V_10 , L_145 , V_387 -> V_388 ) ;
}
static int F_31 ( T_12 V_33 , T_12 * V_47 )
{
int V_42 ;
int V_57 = - V_58 ;
struct V_2 * V_3 ;
struct V_342 * V_210 ;
F_25 ( & V_43 , V_44 ) ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ )
if ( ! V_46 [ V_42 ] )
break;
if ( V_42 == V_45 ) {
F_37 ( V_59 L_146 , V_45 ) ;
V_57 = - V_340 ;
goto V_389;
}
V_3 = F_2 ( sizeof( struct V_2 ) , V_10 ) ;
if ( ! V_3 )
goto V_389;
V_3 -> V_106 = F_215 ( V_390 ,
sizeof( struct V_102 ) ) ;
if ( ! V_3 -> V_106 )
goto V_372;
F_69 ( & V_3 -> V_74 . V_96 ) ;
F_69 ( & V_3 -> V_74 . V_95 ) ;
F_61 ( & V_3 -> V_74 . V_217 ) ;
F_61 ( & V_3 -> V_24 ) ;
F_61 ( & V_3 -> V_76 . V_24 ) ;
F_62 ( & V_3 -> V_76 . V_150 ) ;
F_62 ( & V_3 -> V_76 . V_151 ) ;
sprintf ( V_3 -> V_4 , V_59 L_13 , V_42 ) ;
F_216 ( & V_3 -> V_78 ) ;
V_3 -> V_105 = V_391 ;
V_3 -> V_27 = V_27 ;
V_3 -> V_26 = V_26 ;
V_210 = F_217 ( 1 ) ;
if ( ! V_210 )
goto V_372;
V_3 -> V_210 = V_210 ;
V_210 -> V_52 = V_392 ;
V_210 -> V_393 = V_42 ;
V_210 -> V_385 = & V_394 ;
V_210 -> V_163 = V_395 ;
strcpy ( V_210 -> V_388 , V_3 -> V_4 ) ;
V_210 -> V_396 = F_213 ;
V_210 -> V_343 = V_3 ;
V_210 -> V_211 = F_218 ( V_10 ) ;
if ( ! V_210 -> V_211 )
goto V_397;
V_3 -> V_47 = F_19 ( V_392 , V_42 ) ;
V_57 = F_206 ( V_3 , V_33 ) ;
if ( V_57 )
goto V_398;
V_210 -> V_399 = V_3 -> V_48 -> V_136 -> V_399 ;
V_210 -> V_400 = V_3 -> V_48 -> V_136 -> V_400 ;
F_219 ( V_210 ) ;
F_17 ( V_3 ) ;
F_44 ( V_3 ) ;
V_46 [ V_42 ] = V_3 ;
if ( V_47 )
* V_47 = V_3 -> V_47 ;
F_28 ( & V_43 ) ;
return 0 ;
V_398:
F_220 ( V_210 -> V_211 ) ;
V_397:
F_221 ( V_210 ) ;
V_372:
if ( V_3 -> V_106 )
F_222 ( V_3 -> V_106 ) ;
F_8 ( V_3 ) ;
V_389:
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
F_171 ( V_59 L_148 ) ;
V_57 = - V_294 ;
goto V_125;
}
if ( V_3 -> V_338 > 0 ) {
V_57 = - V_340 ;
goto V_125;
}
if ( ! F_20 ( V_3 -> V_74 . V_371 ) )
F_223 ( V_3 -> V_74 . V_371 ) ;
V_46 [ V_42 ] = NULL ;
F_47 ( V_3 ) ;
F_21 ( V_3 ) ;
F_180 ( V_3 -> V_48 , V_326 | V_370 ) ;
F_224 ( V_3 -> V_4 , V_373 ) ;
F_171 ( V_59 L_149 , V_3 -> V_4 ) ;
F_225 ( V_3 -> V_210 ) ;
F_220 ( V_3 -> V_210 -> V_211 ) ;
F_221 ( V_3 -> V_210 ) ;
F_222 ( V_3 -> V_106 ) ;
F_8 ( V_3 ) ;
F_32 ( V_54 ) ;
V_125:
F_28 ( & V_43 ) ;
return V_57 ;
}
static void F_226 ( struct V_401 * V_402 )
{
struct V_2 * V_3 ;
F_25 ( & V_43 , V_44 ) ;
V_3 = F_182 ( V_402 -> V_403 ) ;
if ( V_3 ) {
V_402 -> V_33 = F_227 ( V_3 -> V_48 -> V_49 ) ;
V_402 -> V_47 = F_227 ( V_3 -> V_47 ) ;
} else {
V_402 -> V_33 = 0 ;
V_402 -> V_47 = 0 ;
}
V_402 -> V_404 = V_45 ;
F_28 ( & V_43 ) ;
}
static long F_228 ( struct V_67 * V_67 , unsigned int V_127 , unsigned long V_375 )
{
void T_14 * V_405 = ( void T_14 * ) V_375 ;
struct V_401 V_402 ;
int V_57 = 0 ;
T_12 V_47 = 0 ;
if ( V_127 != V_406 )
return - V_382 ;
if ( F_229 ( & V_402 , V_405 , sizeof( struct V_401 ) ) )
return - V_407 ;
switch ( V_402 . V_408 ) {
case V_409 :
if ( ! F_230 ( V_410 ) )
return - V_411 ;
V_57 = F_31 ( F_231 ( V_402 . V_33 ) , & V_47 ) ;
V_402 . V_47 = F_227 ( V_47 ) ;
break;
case V_412 :
if ( ! F_230 ( V_410 ) )
return - V_411 ;
V_57 = F_34 ( F_231 ( V_402 . V_47 ) ) ;
break;
case V_413 :
F_226 ( & V_402 ) ;
break;
default:
return - V_382 ;
}
if ( F_232 ( V_405 , & V_402 , sizeof( struct V_401 ) ) )
return - V_407 ;
return V_57 ;
}
static long F_233 ( struct V_67 * V_67 , unsigned int V_127 , unsigned long V_375 )
{
return F_228 ( V_67 , V_127 , ( unsigned long ) F_234 ( V_375 ) ) ;
}
static int T_15 F_235 ( void )
{
int V_57 ;
F_236 ( & V_43 ) ;
V_346 = F_215 ( V_414 ,
sizeof( struct V_344 ) ) ;
if ( ! V_346 )
return - V_58 ;
V_57 = F_237 ( V_392 , V_59 ) ;
if ( V_57 < 0 ) {
F_37 ( V_59 L_150 ) ;
goto V_415;
}
if ( ! V_392 )
V_392 = V_57 ;
V_57 = F_35 () ;
if ( V_57 )
goto V_125;
F_49 () ;
V_57 = F_238 ( & V_416 ) ;
if ( V_57 ) {
F_37 ( V_59 L_151 ) ;
goto V_417;
}
V_373 = F_239 ( L_152 V_59 , NULL ) ;
return 0 ;
V_417:
F_50 () ;
F_38 () ;
V_125:
F_240 ( V_392 , V_59 ) ;
V_415:
F_222 ( V_346 ) ;
return V_57 ;
}
static void T_16 F_241 ( void )
{
F_224 ( L_152 V_59 , NULL ) ;
F_242 ( & V_416 ) ;
F_50 () ;
F_38 () ;
F_240 ( V_392 , V_59 ) ;
F_222 ( V_346 ) ;
}
