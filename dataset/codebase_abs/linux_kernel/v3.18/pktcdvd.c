static T_1 F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
return ( V_1 + V_3 -> V_4 ) & ~ ( T_1 ) ( V_3 -> V_5 . V_6 - 1 ) ;
}
static struct V_7 * F_2 ( struct V_2 * V_3 ,
const char * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_7 * V_13 ;
int error ;
V_13 = F_3 ( sizeof( * V_13 ) , V_14 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_3 = V_3 ;
error = F_4 ( & V_13 -> V_15 , V_12 , V_10 , L_1 , V_8 ) ;
if ( error ) {
F_5 ( & V_13 -> V_15 ) ;
return NULL ;
}
F_6 ( & V_13 -> V_15 , V_16 ) ;
return V_13 ;
}
static void F_7 ( struct V_7 * V_13 )
{
if ( V_13 )
F_5 ( & V_13 -> V_15 ) ;
}
static void F_8 ( struct V_9 * V_15 )
{
F_9 ( F_10 ( V_15 ) ) ;
}
static T_2 F_11 ( struct V_9 * V_15 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_2 * V_3 = F_10 ( V_15 ) -> V_3 ;
int V_20 = 0 ;
int V_21 ;
if ( strcmp ( V_18 -> V_8 , L_2 ) == 0 ) {
V_20 = sprintf ( V_19 , L_3 , V_3 -> V_22 . V_23 ) ;
} else if ( strcmp ( V_18 -> V_8 , L_4 ) == 0 ) {
V_20 = sprintf ( V_19 , L_3 , V_3 -> V_22 . V_24 ) ;
} else if ( strcmp ( V_18 -> V_8 , L_5 ) == 0 ) {
V_20 = sprintf ( V_19 , L_3 , V_3 -> V_22 . V_25 >> 1 ) ;
} else if ( strcmp ( V_18 -> V_8 , L_6 ) == 0 ) {
V_20 = sprintf ( V_19 , L_3 , V_3 -> V_22 . V_26 >> 1 ) ;
} else if ( strcmp ( V_18 -> V_8 , L_7 ) == 0 ) {
V_20 = sprintf ( V_19 , L_3 , V_3 -> V_22 . V_27 >> 1 ) ;
} else if ( strcmp ( V_18 -> V_8 , L_8 ) == 0 ) {
F_12 ( & V_3 -> V_28 ) ;
V_21 = V_3 -> V_29 ;
F_13 ( & V_3 -> V_28 ) ;
V_20 = sprintf ( V_19 , L_9 , V_21 ) ;
} else if ( strcmp ( V_18 -> V_8 , L_10 ) == 0 ) {
F_12 ( & V_3 -> V_28 ) ;
V_21 = V_3 -> V_30 ;
F_13 ( & V_3 -> V_28 ) ;
V_20 = sprintf ( V_19 , L_9 , V_21 ) ;
} else if ( strcmp ( V_18 -> V_8 , L_11 ) == 0 ) {
F_12 ( & V_3 -> V_28 ) ;
V_21 = V_3 -> V_31 ;
F_13 ( & V_3 -> V_28 ) ;
V_20 = sprintf ( V_19 , L_9 , V_21 ) ;
}
return V_20 ;
}
static void F_14 ( int * V_32 , int * V_33 )
{
if ( * V_33 > 0 ) {
* V_33 = F_15 ( * V_33 , 500 ) ;
* V_33 = F_16 ( * V_33 , 1000000 ) ;
if ( * V_32 <= 0 )
* V_32 = * V_33 - 100 ;
else {
* V_32 = F_16 ( * V_32 , * V_33 - 100 ) ;
* V_32 = F_15 ( * V_32 , 100 ) ;
}
} else {
* V_33 = - 1 ;
* V_32 = - 1 ;
}
}
static T_2 F_17 ( struct V_9 * V_15 ,
struct V_17 * V_18 ,
const char * V_19 , T_3 V_34 )
{
struct V_2 * V_3 = F_10 ( V_15 ) -> V_3 ;
int V_35 ;
if ( strcmp ( V_18 -> V_8 , L_12 ) == 0 && V_34 > 0 ) {
V_3 -> V_22 . V_23 = 0 ;
V_3 -> V_22 . V_24 = 0 ;
V_3 -> V_22 . V_25 = 0 ;
V_3 -> V_22 . V_27 = 0 ;
V_3 -> V_22 . V_26 = 0 ;
} else if ( strcmp ( V_18 -> V_8 , L_10 ) == 0
&& sscanf ( V_19 , L_13 , & V_35 ) == 1 ) {
F_12 ( & V_3 -> V_28 ) ;
V_3 -> V_30 = V_35 ;
F_14 ( & V_3 -> V_30 ,
& V_3 -> V_31 ) ;
F_13 ( & V_3 -> V_28 ) ;
} else if ( strcmp ( V_18 -> V_8 , L_11 ) == 0
&& sscanf ( V_19 , L_13 , & V_35 ) == 1 ) {
F_12 ( & V_3 -> V_28 ) ;
V_3 -> V_31 = V_35 ;
F_14 ( & V_3 -> V_30 ,
& V_3 -> V_31 ) ;
F_13 ( & V_3 -> V_28 ) ;
}
return V_34 ;
}
static void F_18 ( struct V_2 * V_3 )
{
if ( V_36 ) {
V_3 -> V_37 = F_19 ( V_36 , NULL , F_20 ( 0 , 0 ) , NULL ,
L_1 , V_3 -> V_8 ) ;
if ( F_21 ( V_3 -> V_37 ) )
V_3 -> V_37 = NULL ;
}
if ( V_3 -> V_37 ) {
V_3 -> V_38 = F_2 ( V_3 , L_14 ,
& V_3 -> V_37 -> V_15 ,
& V_39 ) ;
V_3 -> V_40 = F_2 ( V_3 , L_15 ,
& V_3 -> V_37 -> V_15 ,
& V_41 ) ;
}
}
static void F_22 ( struct V_2 * V_3 )
{
F_7 ( V_3 -> V_38 ) ;
F_7 ( V_3 -> V_40 ) ;
if ( V_36 )
F_23 ( V_3 -> V_37 ) ;
}
static void F_24 ( struct V_42 * V_43 )
{
F_9 ( V_43 ) ;
}
static T_2 F_25 ( struct V_42 * V_44 ,
struct V_45 * V_18 ,
char * V_19 )
{
int V_20 = 0 ;
int V_46 ;
F_26 ( & V_47 , V_48 ) ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ ) {
struct V_2 * V_3 = V_50 [ V_46 ] ;
if ( ! V_3 )
continue;
V_20 += sprintf ( V_19 + V_20 , L_16 ,
V_3 -> V_8 ,
F_27 ( V_3 -> V_51 ) , F_28 ( V_3 -> V_51 ) ,
F_27 ( V_3 -> V_52 -> V_53 ) ,
F_28 ( V_3 -> V_52 -> V_53 ) ) ;
}
F_29 ( & V_47 ) ;
return V_20 ;
}
static T_2 F_30 ( struct V_42 * V_44 ,
struct V_45 * V_18 ,
const char * V_54 ,
T_3 V_55 )
{
unsigned int V_56 , V_57 ;
if ( sscanf ( V_54 , L_17 , & V_56 , & V_57 ) == 2 ) {
if ( ! F_31 ( V_58 ) )
return - V_59 ;
F_32 ( F_20 ( V_56 , V_57 ) , NULL ) ;
F_33 ( V_58 ) ;
return V_55 ;
}
return - V_60 ;
}
static T_2 F_34 ( struct V_42 * V_44 ,
struct V_45 * V_18 ,
const char * V_54 ,
T_3 V_55 )
{
unsigned int V_56 , V_57 ;
if ( sscanf ( V_54 , L_17 , & V_56 , & V_57 ) == 2 ) {
F_35 ( F_20 ( V_56 , V_57 ) ) ;
return V_55 ;
}
return - V_60 ;
}
static int F_36 ( void )
{
int V_61 = 0 ;
V_36 = F_3 ( sizeof( * V_36 ) , V_14 ) ;
if ( ! V_36 )
return - V_62 ;
V_36 -> V_8 = V_63 ;
V_36 -> V_64 = V_58 ;
V_36 -> V_65 = F_24 ;
V_36 -> V_66 = V_67 ;
V_61 = F_37 ( V_36 ) ;
if ( V_61 ) {
F_9 ( V_36 ) ;
V_36 = NULL ;
F_38 ( L_18 ) ;
return V_61 ;
}
return 0 ;
}
static void F_39 ( void )
{
if ( V_36 )
F_40 ( V_36 ) ;
V_36 = NULL ;
}
static int F_41 ( struct V_68 * V_69 , void * V_13 )
{
return F_42 ( V_69 , V_13 ) ;
}
static int F_43 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
return F_44 ( V_71 , F_41 , V_70 -> V_72 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
if ( ! V_73 )
return;
V_3 -> V_74 = F_46 ( V_3 -> V_8 , V_73 ) ;
if ( ! V_3 -> V_74 )
return;
V_3 -> V_75 = F_47 ( L_19 , V_76 ,
V_3 -> V_74 , V_3 , & V_77 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
if ( ! V_73 )
return;
F_49 ( V_3 -> V_75 ) ;
F_49 ( V_3 -> V_74 ) ;
V_3 -> V_75 = NULL ;
V_3 -> V_74 = NULL ;
}
static void F_50 ( void )
{
V_73 = F_46 ( V_63 , NULL ) ;
}
static void F_51 ( void )
{
F_49 ( V_73 ) ;
V_73 = NULL ;
}
static void F_52 ( struct V_2 * V_3 )
{
F_53 ( F_54 ( & V_3 -> V_78 . V_79 ) <= 0 ) ;
if ( F_55 ( & V_3 -> V_78 . V_79 ) ) {
F_56 ( 2 , V_3 , L_20 ) ;
F_57 ( & V_3 -> V_80 . V_81 , 1 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
}
static struct V_83 * F_59 ( int V_84 )
{
int V_85 ;
struct V_83 * V_86 ;
V_86 = F_3 ( sizeof( struct V_83 ) , V_14 ) ;
if ( ! V_86 )
goto V_87;
V_86 -> V_84 = V_84 ;
V_86 -> V_88 = F_60 ( V_14 , V_84 ) ;
if ( ! V_86 -> V_88 )
goto V_89;
for ( V_85 = 0 ; V_85 < V_84 / V_90 ; V_85 ++ ) {
V_86 -> V_91 [ V_85 ] = F_61 ( V_14 | V_92 ) ;
if ( ! V_86 -> V_91 [ V_85 ] )
goto V_93;
}
F_62 ( & V_86 -> V_28 ) ;
F_63 ( & V_86 -> V_94 ) ;
for ( V_85 = 0 ; V_85 < V_84 ; V_85 ++ ) {
struct V_95 * V_95 = F_60 ( V_14 , 1 ) ;
if ( ! V_95 )
goto V_96;
V_86 -> V_97 [ V_85 ] = V_95 ;
}
return V_86 ;
V_96:
for ( V_85 = 0 ; V_85 < V_84 ; V_85 ++ ) {
struct V_95 * V_95 = V_86 -> V_97 [ V_85 ] ;
if ( V_95 )
F_64 ( V_95 ) ;
}
V_93:
for ( V_85 = 0 ; V_85 < V_84 / V_90 ; V_85 ++ )
if ( V_86 -> V_91 [ V_85 ] )
F_65 ( V_86 -> V_91 [ V_85 ] ) ;
F_64 ( V_86 -> V_88 ) ;
V_89:
F_9 ( V_86 ) ;
V_87:
return NULL ;
}
static void F_66 ( struct V_83 * V_86 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_86 -> V_84 ; V_85 ++ ) {
struct V_95 * V_95 = V_86 -> V_97 [ V_85 ] ;
if ( V_95 )
F_64 ( V_95 ) ;
}
for ( V_85 = 0 ; V_85 < V_86 -> V_84 / V_90 ; V_85 ++ )
F_65 ( V_86 -> V_91 [ V_85 ] ) ;
F_64 ( V_86 -> V_88 ) ;
F_9 ( V_86 ) ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_83 * V_86 , * V_98 ;
F_53 ( ! F_68 ( & V_3 -> V_78 . V_99 ) ) ;
F_69 (pkt, next, &pd->cdrw.pkt_free_list, list) {
F_66 ( V_86 ) ;
}
F_70 ( & V_3 -> V_78 . V_100 ) ;
}
static int F_71 ( struct V_2 * V_3 , int V_101 )
{
struct V_83 * V_86 ;
F_53 ( ! F_68 ( & V_3 -> V_78 . V_100 ) ) ;
while ( V_101 > 0 ) {
V_86 = F_59 ( V_3 -> V_5 . V_6 >> 2 ) ;
if ( ! V_86 ) {
F_67 ( V_3 ) ;
return 0 ;
}
V_86 -> V_102 = V_101 ;
V_86 -> V_3 = V_3 ;
F_72 ( & V_86 -> V_103 , & V_3 -> V_78 . V_100 ) ;
V_101 -- ;
}
return 1 ;
}
static inline struct V_104 * F_73 ( struct V_104 * V_105 )
{
struct V_106 * V_20 = F_74 ( & V_105 -> V_106 ) ;
if ( ! V_20 )
return NULL ;
return F_75 ( V_20 , struct V_104 , V_106 ) ;
}
static void F_76 ( struct V_2 * V_3 , struct V_104 * V_105 )
{
F_77 ( & V_105 -> V_106 , & V_3 -> V_107 ) ;
F_78 ( V_105 , V_3 -> V_108 ) ;
V_3 -> V_29 -- ;
F_53 ( V_3 -> V_29 < 0 ) ;
}
static struct V_104 * F_79 ( struct V_2 * V_3 , T_1 V_109 )
{
struct V_106 * V_20 = V_3 -> V_107 . V_106 ;
struct V_106 * V_98 ;
struct V_104 * V_110 ;
if ( ! V_20 ) {
F_53 ( V_3 -> V_29 > 0 ) ;
return NULL ;
}
for (; ; ) {
V_110 = F_75 ( V_20 , struct V_104 , V_106 ) ;
if ( V_109 <= V_110 -> V_95 -> V_111 . V_112 )
V_98 = V_20 -> V_113 ;
else
V_98 = V_20 -> V_114 ;
if ( ! V_98 )
break;
V_20 = V_98 ;
}
if ( V_109 > V_110 -> V_95 -> V_111 . V_112 ) {
V_110 = F_73 ( V_110 ) ;
if ( ! V_110 )
return NULL ;
}
F_53 ( V_109 > V_110 -> V_95 -> V_111 . V_112 ) ;
return V_110 ;
}
static void F_80 ( struct V_2 * V_3 , struct V_104 * V_105 )
{
struct V_106 * * V_13 = & V_3 -> V_107 . V_106 ;
struct V_106 * V_10 = NULL ;
T_1 V_109 = V_105 -> V_95 -> V_111 . V_112 ;
struct V_104 * V_110 ;
while ( * V_13 ) {
V_10 = * V_13 ;
V_110 = F_75 ( V_10 , struct V_104 , V_106 ) ;
if ( V_109 < V_110 -> V_95 -> V_111 . V_112 )
V_13 = & ( * V_13 ) -> V_113 ;
else
V_13 = & ( * V_13 ) -> V_114 ;
}
F_81 ( & V_105 -> V_106 , V_10 , V_13 ) ;
F_82 ( & V_105 -> V_106 , & V_3 -> V_107 ) ;
V_3 -> V_29 ++ ;
}
static int F_83 ( struct V_2 * V_3 , struct V_115 * V_116 )
{
struct V_117 * V_118 = F_84 ( V_3 -> V_52 ) ;
struct V_119 * V_120 ;
int V_61 = 0 ;
V_120 = F_85 ( V_118 , ( V_116 -> V_121 == V_122 ) ?
V_123 : V_124 , V_125 ) ;
if ( F_21 ( V_120 ) )
return F_86 ( V_120 ) ;
F_87 ( V_120 ) ;
if ( V_116 -> V_126 ) {
V_61 = F_88 ( V_118 , V_120 , V_116 -> V_127 , V_116 -> V_126 ,
V_125 ) ;
if ( V_61 )
goto V_128;
}
V_120 -> V_129 = F_89 ( V_116 -> V_130 [ 0 ] ) ;
memcpy ( V_120 -> V_130 , V_116 -> V_130 , V_131 ) ;
V_120 -> V_132 = 60 * V_133 ;
if ( V_116 -> V_134 )
V_120 -> V_135 |= V_136 ;
F_90 ( V_120 -> V_118 , V_3 -> V_52 -> V_137 , V_120 , 0 ) ;
if ( V_120 -> V_138 )
V_61 = - V_139 ;
V_128:
F_91 ( V_120 ) ;
return V_61 ;
}
static const char * F_92 ( T_4 V_140 )
{
static const char * const V_141 [] = {
L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 ,
L_27 , L_28 , L_29 ,
} ;
return V_140 < F_93 ( V_141 ) ? V_141 [ V_140 ] : L_30 ;
}
static void F_94 ( struct V_2 * V_3 ,
struct V_115 * V_116 )
{
struct V_142 * V_143 = V_116 -> V_143 ;
if ( V_143 )
F_95 ( V_3 , L_31 ,
V_131 , V_116 -> V_130 ,
V_143 -> V_144 , V_143 -> V_145 , V_143 -> V_146 ,
F_92 ( V_143 -> V_144 ) ) ;
else
F_95 ( V_3 , L_32 , V_131 , V_116 -> V_130 ) ;
}
static int F_96 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
F_97 ( & V_116 , NULL , 0 , V_147 ) ;
V_116 . V_130 [ 0 ] = V_148 ;
V_116 . V_134 = 1 ;
#if 0
cgc.cmd[1] = 1 << 1;
#endif
return F_83 ( V_3 , & V_116 ) ;
}
static T_5 int F_98 ( struct V_2 * V_3 ,
unsigned V_149 , unsigned V_150 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
int V_61 ;
F_97 ( & V_116 , NULL , 0 , V_147 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_130 [ 0 ] = V_151 ;
V_116 . V_130 [ 2 ] = ( V_150 >> 8 ) & 0xff ;
V_116 . V_130 [ 3 ] = V_150 & 0xff ;
V_116 . V_130 [ 4 ] = ( V_149 >> 8 ) & 0xff ;
V_116 . V_130 [ 5 ] = V_149 & 0xff ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
static void F_99 ( struct V_2 * V_3 , struct V_95 * V_95 )
{
F_12 ( & V_3 -> V_80 . V_28 ) ;
if ( F_100 ( V_95 ) == V_124 )
F_101 ( & V_3 -> V_80 . V_152 , V_95 ) ;
else
F_101 ( & V_3 -> V_80 . V_153 , V_95 ) ;
F_13 ( & V_3 -> V_80 . V_28 ) ;
F_57 ( & V_3 -> V_80 . V_81 , 1 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
static void F_102 ( struct V_2 * V_3 )
{
if ( F_54 ( & V_3 -> V_80 . V_81 ) == 0 )
return;
F_57 ( & V_3 -> V_80 . V_81 , 0 ) ;
for (; ; ) {
struct V_95 * V_95 ;
int V_154 , V_155 ;
F_12 ( & V_3 -> V_80 . V_28 ) ;
V_154 = ! F_103 ( & V_3 -> V_80 . V_152 ) ;
V_155 = ! F_103 ( & V_3 -> V_80 . V_153 ) ;
F_13 ( & V_3 -> V_80 . V_28 ) ;
if ( ! V_154 && ! V_155 )
break;
if ( V_3 -> V_80 . V_156 ) {
int V_157 = 1 ;
F_12 ( & V_3 -> V_80 . V_28 ) ;
V_95 = F_104 ( & V_3 -> V_80 . V_153 ) ;
F_13 ( & V_3 -> V_80 . V_28 ) ;
if ( V_95 && ( V_95 -> V_111 . V_112 ==
V_3 -> V_80 . V_158 ) )
V_157 = 0 ;
if ( V_157 && V_154 ) {
if ( F_54 ( & V_3 -> V_78 . V_79 ) > 0 ) {
F_56 ( 2 , V_3 , L_33 ) ;
break;
}
F_96 ( V_3 ) ;
V_3 -> V_80 . V_156 = 0 ;
}
} else {
if ( ! V_154 && V_155 ) {
if ( F_54 ( & V_3 -> V_78 . V_79 ) > 0 ) {
F_56 ( 2 , V_3 , L_34 ) ;
break;
}
V_3 -> V_80 . V_156 = 1 ;
}
}
F_12 ( & V_3 -> V_80 . V_28 ) ;
if ( V_3 -> V_80 . V_156 )
V_95 = F_105 ( & V_3 -> V_80 . V_153 ) ;
else
V_95 = F_105 ( & V_3 -> V_80 . V_152 ) ;
F_13 ( & V_3 -> V_80 . V_28 ) ;
if ( ! V_95 )
continue;
if ( F_100 ( V_95 ) == V_124 )
V_3 -> V_80 . V_159 +=
V_95 -> V_111 . V_160 >> 10 ;
else {
V_3 -> V_80 . V_159 = 0 ;
V_3 -> V_80 . V_158 = F_106 ( V_95 ) ;
}
if ( V_3 -> V_80 . V_159 >= V_161 ) {
if ( V_3 -> V_150 == V_3 -> V_149 ) {
V_3 -> V_150 = V_162 ;
F_98 ( V_3 , V_3 -> V_149 , V_3 -> V_150 ) ;
}
} else {
if ( V_3 -> V_150 != V_3 -> V_149 ) {
V_3 -> V_150 = V_3 -> V_149 ;
F_98 ( V_3 , V_3 -> V_149 , V_3 -> V_150 ) ;
}
}
F_107 ( & V_3 -> V_78 . V_79 ) ;
F_108 ( V_95 ) ;
}
}
static int F_109 ( struct V_2 * V_3 , struct V_117 * V_118 )
{
if ( ( V_3 -> V_5 . V_6 << 9 ) / V_163
<= F_110 ( V_118 ) ) {
F_111 ( V_164 , & V_3 -> V_165 ) ;
return 0 ;
} else if ( ( V_3 -> V_5 . V_6 << 9 ) / V_166
<= F_110 ( V_118 ) ) {
F_112 ( V_164 , & V_3 -> V_165 ) ;
return 0 ;
} else {
F_95 ( V_3 , L_35 ) ;
return - V_139 ;
}
}
static void F_113 ( struct V_83 * V_86 , struct V_167 * V_168 )
{
int V_169 , V_13 , V_170 ;
V_13 = 0 ;
V_170 = 0 ;
for ( V_169 = 0 ; V_169 < V_86 -> V_84 ; V_169 ++ ) {
if ( V_168 [ V_169 ] . V_171 != V_86 -> V_91 [ V_13 ] ) {
void * V_172 = F_114 ( V_168 [ V_169 ] . V_171 ) + V_168 [ V_169 ] . V_173 ;
void * V_174 = F_115 ( V_86 -> V_91 [ V_13 ] ) + V_170 ;
memcpy ( V_174 , V_172 , V_163 ) ;
F_116 ( V_172 ) ;
V_168 [ V_169 ] . V_171 = V_86 -> V_91 [ V_13 ] ;
V_168 [ V_169 ] . V_173 = V_170 ;
} else {
F_53 ( V_168 [ V_169 ] . V_173 != V_170 ) ;
}
V_170 += V_163 ;
if ( V_170 >= V_166 ) {
V_170 = 0 ;
V_13 ++ ;
}
}
}
static void F_117 ( struct V_95 * V_95 , int V_175 )
{
struct V_83 * V_86 = V_95 -> V_176 ;
struct V_2 * V_3 = V_86 -> V_3 ;
F_53 ( ! V_3 ) ;
F_56 ( 2 , V_3 , L_36 ,
V_95 , ( unsigned long long ) V_86 -> V_1 ,
( unsigned long long ) V_95 -> V_111 . V_112 , V_175 ) ;
if ( V_175 )
F_107 ( & V_86 -> V_177 ) ;
if ( F_55 ( & V_86 -> V_178 ) ) {
F_107 ( & V_86 -> V_179 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
F_52 ( V_3 ) ;
}
static void F_118 ( struct V_95 * V_95 , int V_175 )
{
struct V_83 * V_86 = V_95 -> V_176 ;
struct V_2 * V_3 = V_86 -> V_3 ;
F_53 ( ! V_3 ) ;
F_56 ( 2 , V_3 , L_37 , V_86 -> V_102 , V_175 ) ;
V_3 -> V_22 . V_24 ++ ;
F_52 ( V_3 ) ;
F_119 ( & V_86 -> V_178 ) ;
F_107 ( & V_86 -> V_179 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
static void F_120 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
int V_180 = 0 ;
struct V_95 * V_95 ;
int V_169 ;
char V_181 [ V_182 ] ;
F_53 ( F_103 ( & V_86 -> V_94 ) ) ;
F_57 ( & V_86 -> V_178 , 0 ) ;
F_57 ( & V_86 -> V_177 , 0 ) ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
F_12 ( & V_86 -> V_28 ) ;
F_121 (bio, &pkt->orig_bios) {
int V_183 = ( V_95 -> V_111 . V_112 - V_86 -> V_1 ) /
( V_163 >> 9 ) ;
int V_184 = V_95 -> V_111 . V_160 / V_163 ;
V_3 -> V_22 . V_25 += V_184 * ( V_163 >> 9 ) ;
F_53 ( V_183 < 0 ) ;
F_53 ( V_183 + V_184 > V_86 -> V_84 ) ;
for ( V_169 = V_183 ; V_169 < V_183 + V_184 ; V_169 ++ )
V_181 [ V_169 ] = 1 ;
}
F_13 ( & V_86 -> V_28 ) ;
if ( V_86 -> V_185 ) {
F_56 ( 2 , V_3 , L_38 ,
( unsigned long long ) V_86 -> V_1 ) ;
goto V_186;
}
for ( V_169 = 0 ; V_169 < V_86 -> V_84 ; V_169 ++ ) {
int V_13 , V_4 ;
if ( V_181 [ V_169 ] )
continue;
V_95 = V_86 -> V_97 [ V_169 ] ;
F_122 ( V_95 ) ;
V_95 -> V_111 . V_112 = V_86 -> V_1 + V_169 * ( V_163 >> 9 ) ;
V_95 -> V_187 = V_3 -> V_52 ;
V_95 -> V_188 = F_117 ;
V_95 -> V_176 = V_86 ;
V_13 = ( V_169 * V_163 ) / V_166 ;
V_4 = ( V_169 * V_163 ) % V_166 ;
F_56 ( 2 , V_3 , L_39 ,
V_169 , V_86 -> V_91 [ V_13 ] , V_4 ) ;
if ( ! F_123 ( V_95 , V_86 -> V_91 [ V_13 ] , V_163 , V_4 ) )
F_124 () ;
F_107 ( & V_86 -> V_178 ) ;
V_95 -> V_189 = V_124 ;
F_99 ( V_3 , V_95 ) ;
V_180 ++ ;
}
V_186:
F_56 ( 2 , V_3 , L_40 ,
V_180 , ( unsigned long long ) V_86 -> V_1 ) ;
V_3 -> V_22 . V_23 ++ ;
V_3 -> V_22 . V_27 += V_180 * ( V_163 >> 9 ) ;
}
static struct V_83 * F_125 ( struct V_2 * V_3 , int V_190 )
{
struct V_83 * V_86 ;
F_126 (pkt, &pd->cdrw.pkt_free_list, list) {
if ( V_86 -> V_1 == V_190 || V_86 -> V_103 . V_98 == & V_3 -> V_78 . V_100 ) {
F_127 ( & V_86 -> V_103 ) ;
if ( V_86 -> V_1 != V_190 )
V_86 -> V_185 = 0 ;
return V_86 ;
}
}
F_124 () ;
return NULL ;
}
static void F_128 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
if ( V_86 -> V_185 ) {
F_72 ( & V_86 -> V_103 , & V_3 -> V_78 . V_100 ) ;
} else {
F_129 ( & V_86 -> V_103 , & V_3 -> V_78 . V_100 ) ;
}
}
static int F_130 ( struct V_83 * V_86 )
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
pkt->bio->bi_iter.bi_sector = new_sector;
pkt->bio->bi_iter.bi_size = pkt->frames * CD_FRAMESIZE;
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
static inline void F_131 ( struct V_83 * V_86 , enum V_191 V_192 )
{
#if V_193 > 1
static const char * V_194 [] = {
L_41 , L_42 , L_43 , L_44 , L_45 , L_46
} ;
enum V_191 V_195 = V_86 -> V_192 ;
F_56 ( 2 , V_3 , L_47 ,
V_86 -> V_102 , ( unsigned long long ) V_86 -> V_1 ,
V_194 [ V_195 ] , V_194 [ V_192 ] ) ;
#endif
V_86 -> V_192 = V_192 ;
}
static int F_132 ( struct V_2 * V_3 )
{
struct V_83 * V_86 , * V_13 ;
struct V_95 * V_95 = NULL ;
T_1 V_190 = 0 ;
struct V_104 * V_105 , * V_196 ;
struct V_106 * V_20 ;
int V_197 ;
F_57 ( & V_3 -> V_198 , 0 ) ;
if ( F_68 ( & V_3 -> V_78 . V_100 ) ) {
F_56 ( 2 , V_3 , L_48 ) ;
return 0 ;
}
F_12 ( & V_3 -> V_28 ) ;
V_196 = F_79 ( V_3 , V_3 -> V_199 ) ;
if ( ! V_196 ) {
V_20 = F_133 ( & V_3 -> V_107 ) ;
if ( V_20 )
V_196 = F_75 ( V_20 , struct V_104 , V_106 ) ;
}
V_105 = V_196 ;
while ( V_105 ) {
V_95 = V_105 -> V_95 ;
V_190 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
F_126 (p, &pd->cdrw.pkt_active_list, list) {
if ( V_13 -> V_1 == V_190 ) {
V_95 = NULL ;
goto V_200;
}
}
break;
V_200:
V_105 = F_73 ( V_105 ) ;
if ( ! V_105 ) {
V_20 = F_133 ( & V_3 -> V_107 ) ;
if ( V_20 )
V_105 = F_75 ( V_20 , struct V_104 , V_106 ) ;
}
if ( V_105 == V_196 )
V_105 = NULL ;
}
F_13 ( & V_3 -> V_28 ) ;
if ( ! V_95 ) {
F_56 ( 2 , V_3 , L_49 ) ;
return 0 ;
}
V_86 = F_125 ( V_3 , V_190 ) ;
V_3 -> V_199 = V_190 + V_3 -> V_5 . V_6 ;
V_86 -> V_1 = V_190 ;
F_53 ( V_86 -> V_84 != V_3 -> V_5 . V_6 >> 2 ) ;
V_86 -> V_201 = 0 ;
F_12 ( & V_3 -> V_28 ) ;
F_56 ( 2 , V_3 , L_50 , ( unsigned long long ) V_190 ) ;
while ( ( V_105 = F_79 ( V_3 , V_190 ) ) != NULL ) {
V_95 = V_105 -> V_95 ;
F_56 ( 2 , V_3 , L_51 , ( unsigned long long )
F_1 ( V_95 -> V_111 . V_112 , V_3 ) ) ;
if ( F_1 ( V_95 -> V_111 . V_112 , V_3 ) != V_190 )
break;
F_76 ( V_3 , V_105 ) ;
F_12 ( & V_86 -> V_28 ) ;
F_101 ( & V_86 -> V_94 , V_95 ) ;
V_86 -> V_201 += V_95 -> V_111 . V_160 / V_163 ;
F_13 ( & V_86 -> V_28 ) ;
}
V_197 = ( V_3 -> V_31 > 0
&& V_3 -> V_29 <= V_3 -> V_30 ) ;
F_13 ( & V_3 -> V_28 ) ;
if ( V_197 ) {
F_134 ( & V_3 -> V_202 -> V_203 -> V_204 ,
V_205 ) ;
}
V_86 -> V_206 = F_15 ( V_207 , 1 ) ;
F_131 ( V_86 , V_208 ) ;
F_57 ( & V_86 -> V_179 , 1 ) ;
F_12 ( & V_3 -> V_78 . V_209 ) ;
F_72 ( & V_86 -> V_103 , & V_3 -> V_78 . V_99 ) ;
F_13 ( & V_3 -> V_78 . V_209 ) ;
return 1 ;
}
static void F_135 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
int V_169 ;
struct V_167 * V_168 = V_86 -> V_88 -> V_210 ;
F_122 ( V_86 -> V_88 ) ;
V_86 -> V_88 -> V_111 . V_112 = V_86 -> V_1 ;
V_86 -> V_88 -> V_187 = V_3 -> V_52 ;
V_86 -> V_88 -> V_188 = F_118 ;
V_86 -> V_88 -> V_176 = V_86 ;
for ( V_169 = 0 ; V_169 < V_86 -> V_84 ; V_169 ++ ) {
V_168 [ V_169 ] . V_171 = V_86 -> V_91 [ ( V_169 * V_163 ) / V_166 ] ;
V_168 [ V_169 ] . V_173 = ( V_169 * V_163 ) % V_166 ;
if ( ! F_123 ( V_86 -> V_88 , V_168 [ V_169 ] . V_171 , V_163 , V_168 [ V_169 ] . V_173 ) )
F_124 () ;
}
F_56 ( 2 , V_3 , L_52 , V_86 -> V_88 -> V_211 ) ;
F_12 ( & V_86 -> V_28 ) ;
F_136 ( V_86 -> V_88 , V_86 -> V_94 . V_212 ) ;
F_131 ( V_86 , V_213 ) ;
F_13 ( & V_86 -> V_28 ) ;
F_56 ( 2 , V_3 , L_53 ,
V_86 -> V_201 , ( unsigned long long ) V_86 -> V_1 ) ;
if ( F_137 ( V_164 , & V_3 -> V_165 ) || ( V_86 -> V_201 < V_86 -> V_84 ) ) {
F_113 ( V_86 , V_168 ) ;
V_86 -> V_185 = 1 ;
} else {
V_86 -> V_185 = 0 ;
}
F_57 ( & V_86 -> V_178 , 1 ) ;
V_86 -> V_88 -> V_189 = V_123 ;
F_99 ( V_3 , V_86 -> V_88 ) ;
}
static void F_138 ( struct V_83 * V_86 , int V_214 )
{
struct V_95 * V_95 ;
if ( ! V_214 )
V_86 -> V_185 = 0 ;
while ( ( V_95 = F_105 ( & V_86 -> V_94 ) ) )
F_139 ( V_95 , V_214 ? 0 : - V_139 ) ;
}
static void F_140 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
int V_214 ;
F_56 ( 2 , V_3 , L_54 , V_86 -> V_102 ) ;
for (; ; ) {
switch ( V_86 -> V_192 ) {
case V_208 :
if ( ( V_86 -> V_201 < V_86 -> V_84 ) && ( V_86 -> V_206 > 0 ) )
return;
V_86 -> V_206 = 0 ;
F_120 ( V_3 , V_86 ) ;
F_131 ( V_86 , V_215 ) ;
break;
case V_215 :
if ( F_54 ( & V_86 -> V_178 ) > 0 )
return;
if ( F_54 ( & V_86 -> V_177 ) > 0 ) {
F_131 ( V_86 , V_216 ) ;
} else {
F_135 ( V_3 , V_86 ) ;
}
break;
case V_213 :
if ( F_54 ( & V_86 -> V_178 ) > 0 )
return;
if ( F_137 ( V_217 , & V_86 -> V_88 -> V_218 ) ) {
F_131 ( V_86 , V_219 ) ;
} else {
F_131 ( V_86 , V_216 ) ;
}
break;
case V_216 :
if ( F_130 ( V_86 ) ) {
F_135 ( V_3 , V_86 ) ;
} else {
F_56 ( 2 , V_3 , L_55 ) ;
F_131 ( V_86 , V_219 ) ;
}
break;
case V_219 :
V_214 = F_137 ( V_217 , & V_86 -> V_88 -> V_218 ) ;
F_138 ( V_86 , V_214 ) ;
return;
default:
F_124 () ;
break;
}
}
}
static void F_141 ( struct V_2 * V_3 )
{
struct V_83 * V_86 , * V_98 ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_54 ( & V_86 -> V_179 ) > 0 ) {
F_57 ( & V_86 -> V_179 , 0 ) ;
F_140 ( V_3 , V_86 ) ;
}
}
F_12 ( & V_3 -> V_78 . V_209 ) ;
F_69 (pkt, next, &pd->cdrw.pkt_active_list, list) {
if ( V_86 -> V_192 == V_219 ) {
F_142 ( & V_86 -> V_103 ) ;
F_128 ( V_3 , V_86 ) ;
F_131 ( V_86 , V_220 ) ;
F_57 ( & V_3 -> V_198 , 1 ) ;
}
}
F_13 ( & V_3 -> V_78 . V_209 ) ;
}
static void F_143 ( struct V_2 * V_3 , int * V_221 )
{
struct V_83 * V_86 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_222 ; V_85 ++ )
V_221 [ V_85 ] = 0 ;
F_12 ( & V_3 -> V_78 . V_209 ) ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
V_221 [ V_86 -> V_192 ] ++ ;
}
F_13 ( & V_3 -> V_78 . V_209 ) ;
}
static int F_144 ( void * V_223 )
{
struct V_2 * V_3 = V_223 ;
struct V_83 * V_86 ;
long V_224 , V_225 ;
F_145 ( V_226 , V_227 ) ;
F_146 () ;
for (; ; ) {
F_147 ( V_228 , V_226 ) ;
F_148 ( & V_3 -> V_82 , & V_228 ) ;
for (; ; ) {
F_149 ( V_229 ) ;
if ( F_54 ( & V_3 -> V_198 ) > 0 )
goto V_230;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_54 ( & V_86 -> V_179 ) > 0 )
goto V_230;
}
if ( F_54 ( & V_3 -> V_80 . V_81 ) != 0 )
goto V_230;
if ( V_193 > 1 ) {
int V_221 [ V_222 ] ;
F_143 ( V_3 , V_221 ) ;
F_56 ( 2 , V_3 , L_56 ,
V_221 [ 0 ] , V_221 [ 1 ] , V_221 [ 2 ] ,
V_221 [ 3 ] , V_221 [ 4 ] , V_221 [ 5 ] ) ;
}
V_224 = V_231 ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_86 -> V_206 && V_86 -> V_206 < V_224 )
V_224 = V_86 -> V_206 ;
}
F_56 ( 2 , V_3 , L_57 ) ;
V_225 = F_150 ( V_224 ) ;
F_56 ( 2 , V_3 , L_58 ) ;
F_151 () ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( ! V_86 -> V_206 )
continue;
V_86 -> V_206 -= V_224 - V_225 ;
if ( V_86 -> V_206 <= 0 ) {
V_86 -> V_206 = 0 ;
F_107 ( & V_86 -> V_179 ) ;
}
}
if ( F_152 () )
break;
}
V_230:
F_149 ( V_232 ) ;
F_153 ( & V_3 -> V_82 , & V_228 ) ;
if ( F_152 () )
break;
while ( F_132 ( V_3 ) )
;
F_141 ( V_3 ) ;
F_102 ( V_3 ) ;
}
return 0 ;
}
static void F_154 ( struct V_2 * V_3 )
{
F_155 ( V_3 , L_59 ,
V_3 -> V_5 . V_233 ? L_60 : L_61 ,
V_3 -> V_5 . V_6 >> 2 ,
V_3 -> V_5 . V_234 == 8 ? '1' : '2' ) ;
}
static int F_156 ( struct V_2 * V_3 , struct V_115 * V_116 , int V_235 , int V_236 )
{
memset ( V_116 -> V_130 , 0 , sizeof( V_116 -> V_130 ) ) ;
V_116 -> V_130 [ 0 ] = V_237 ;
V_116 -> V_130 [ 2 ] = V_235 | ( V_236 << 6 ) ;
V_116 -> V_130 [ 7 ] = V_116 -> V_126 >> 8 ;
V_116 -> V_130 [ 8 ] = V_116 -> V_126 & 0xff ;
V_116 -> V_121 = V_238 ;
return F_83 ( V_3 , V_116 ) ;
}
static int F_157 ( struct V_2 * V_3 , struct V_115 * V_116 )
{
memset ( V_116 -> V_130 , 0 , sizeof( V_116 -> V_130 ) ) ;
memset ( V_116 -> V_127 , 0 , 2 ) ;
V_116 -> V_130 [ 0 ] = V_239 ;
V_116 -> V_130 [ 1 ] = 0x10 ;
V_116 -> V_130 [ 7 ] = V_116 -> V_126 >> 8 ;
V_116 -> V_130 [ 8 ] = V_116 -> V_126 & 0xff ;
V_116 -> V_121 = V_122 ;
return F_83 ( V_3 , V_116 ) ;
}
static int F_158 ( struct V_2 * V_3 , T_6 * V_240 )
{
struct V_115 V_116 ;
int V_61 ;
F_97 ( & V_116 , V_240 , sizeof( * V_240 ) , V_238 ) ;
V_116 . V_130 [ 0 ] = V_241 ;
V_116 . V_130 [ 8 ] = V_116 . V_126 = 2 ;
V_116 . V_134 = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
return V_61 ;
V_116 . V_126 = F_159 ( V_240 -> V_242 ) +
sizeof( V_240 -> V_242 ) ;
if ( V_116 . V_126 > sizeof( T_6 ) )
V_116 . V_126 = sizeof( T_6 ) ;
V_116 . V_130 [ 8 ] = V_116 . V_126 ;
return F_83 ( V_3 , & V_116 ) ;
}
static int F_160 ( struct V_2 * V_3 , T_7 V_243 , T_4 type , T_8 * V_244 )
{
struct V_115 V_116 ;
int V_61 ;
F_97 ( & V_116 , V_244 , 8 , V_238 ) ;
V_116 . V_130 [ 0 ] = V_245 ;
V_116 . V_130 [ 1 ] = type & 3 ;
V_116 . V_130 [ 4 ] = ( V_243 & 0xff00 ) >> 8 ;
V_116 . V_130 [ 5 ] = V_243 & 0xff ;
V_116 . V_130 [ 8 ] = 8 ;
V_116 . V_134 = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
return V_61 ;
V_116 . V_126 = F_159 ( V_244 -> V_246 ) +
sizeof( V_244 -> V_246 ) ;
if ( V_116 . V_126 > sizeof( T_8 ) )
V_116 . V_126 = sizeof( T_8 ) ;
V_116 . V_130 [ 8 ] = V_116 . V_126 ;
return F_83 ( V_3 , & V_116 ) ;
}
static T_5 int F_161 ( struct V_2 * V_3 ,
long * V_247 )
{
T_6 V_240 ;
T_8 V_244 ;
T_9 V_248 ;
int V_61 = - 1 ;
if ( ( V_61 = F_158 ( V_3 , & V_240 ) ) )
return V_61 ;
V_248 = ( V_240 . V_249 << 8 ) | V_240 . V_250 ;
if ( ( V_61 = F_160 ( V_3 , V_248 , 1 , & V_244 ) ) )
return V_61 ;
if ( V_244 . V_251 ) {
V_248 -- ;
if ( ( V_61 = F_160 ( V_3 , V_248 , 1 , & V_244 ) ) )
return V_61 ;
}
if ( V_244 . V_252 ) {
* V_247 = F_162 ( V_244 . V_253 ) ;
} else {
* V_247 = F_162 ( V_244 . V_254 ) +
F_162 ( V_244 . V_255 ) ;
if ( V_244 . V_256 )
* V_247 -= ( F_162 ( V_244 . V_256 ) + 7 ) ;
}
return 0 ;
}
static T_5 int F_163 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
T_10 * V_257 ;
char V_127 [ 128 ] ;
int V_61 , V_6 ;
if ( ( V_3 -> V_258 == 0x1a ) || ( V_3 -> V_258 == 0x12 ) )
return 0 ;
memset ( V_127 , 0 , sizeof( V_127 ) ) ;
F_97 ( & V_116 , V_127 , sizeof( * V_257 ) , V_238 ) ;
V_116 . V_143 = & V_143 ;
if ( ( V_61 = F_156 ( V_3 , & V_116 , V_259 , 0 ) ) ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
V_6 = 2 + ( ( V_127 [ 0 ] << 8 ) | ( V_127 [ 1 ] & 0xff ) ) ;
V_3 -> V_260 = ( V_127 [ 6 ] << 8 ) | ( V_127 [ 7 ] & 0xff ) ;
if ( V_6 > sizeof( V_127 ) )
V_6 = sizeof( V_127 ) ;
F_97 ( & V_116 , V_127 , V_6 , V_238 ) ;
V_116 . V_143 = & V_143 ;
if ( ( V_61 = F_156 ( V_3 , & V_116 , V_259 , 0 ) ) ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
V_257 = ( T_10 * ) & V_127 [ sizeof( struct V_261 ) + V_3 -> V_260 ] ;
V_257 -> V_233 = V_3 -> V_5 . V_233 ;
V_257 -> V_262 = V_3 -> V_5 . V_262 ;
V_257 -> V_263 = V_3 -> V_5 . V_263 ;
V_257 -> V_264 = V_3 -> V_5 . V_234 ;
V_257 -> V_265 = 0 ;
#ifdef F_164
V_257 -> V_266 = 7 ;
V_257 -> V_267 = 1 ;
#endif
if ( V_257 -> V_264 == V_268 ) {
V_257 -> V_269 = 0 ;
V_257 -> V_270 = 0x20 ;
} else if ( V_257 -> V_264 == V_271 ) {
V_257 -> V_269 = 0x20 ;
V_257 -> V_270 = 8 ;
#if 0
wp->mcn[0] = 0x80;
memcpy(&wp->mcn[1], PACKET_MCN, sizeof(wp->mcn) - 1);
#endif
} else {
F_95 ( V_3 , L_62 , V_257 -> V_264 ) ;
return 1 ;
}
V_257 -> V_272 = F_165 ( V_3 -> V_5 . V_6 >> 2 ) ;
V_116 . V_126 = V_116 . V_130 [ 8 ] = V_6 ;
if ( ( V_61 = F_157 ( V_3 , & V_116 ) ) ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
F_154 ( V_3 ) ;
return 0 ;
}
static int F_166 ( struct V_2 * V_3 , T_8 * V_244 )
{
switch ( V_3 -> V_258 ) {
case 0x1a :
case 0x12 :
return 1 ;
default:
break;
}
if ( ! V_244 -> V_273 || ! V_244 -> V_233 )
return 0 ;
if ( V_244 -> V_274 == 0 && V_244 -> V_251 == 0 )
return 1 ;
if ( V_244 -> V_274 == 0 && V_244 -> V_251 == 1 )
return 1 ;
if ( V_244 -> V_274 == 1 && V_244 -> V_251 == 0 )
return 1 ;
F_95 ( V_3 , L_63 , V_244 -> V_274 , V_244 -> V_251 , V_244 -> V_273 ) ;
return 0 ;
}
static int F_167 ( struct V_2 * V_3 , T_6 * V_240 )
{
switch ( V_3 -> V_258 ) {
case 0x0a :
case 0xffff :
break;
case 0x1a :
case 0x13 :
case 0x12 :
return 1 ;
default:
F_56 ( 2 , V_3 , L_64 ,
V_3 -> V_258 ) ;
return 0 ;
}
if ( V_240 -> V_275 == 0xff ) {
F_168 ( V_3 , L_65 ) ;
return 0 ;
}
if ( V_240 -> V_275 != 0x20 && V_240 -> V_275 != 0 ) {
F_95 ( V_3 , L_66 , V_240 -> V_275 ) ;
return 0 ;
}
if ( V_240 -> V_276 == 0 ) {
F_168 ( V_3 , L_67 ) ;
return 0 ;
}
if ( V_240 -> V_277 == V_278 ) {
F_95 ( V_3 , L_68 ) ;
return 0 ;
}
return 1 ;
}
static T_5 int F_169 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
unsigned char V_54 [ 12 ] ;
T_6 V_240 ;
T_8 V_244 ;
int V_61 , V_243 ;
F_97 ( & V_116 , V_54 , sizeof( V_54 ) , V_238 ) ;
V_116 . V_130 [ 0 ] = V_279 ;
V_116 . V_130 [ 8 ] = 8 ;
V_61 = F_83 ( V_3 , & V_116 ) ;
V_3 -> V_258 = V_61 ? 0xffff : V_54 [ 6 ] << 8 | V_54 [ 7 ] ;
memset ( & V_240 , 0 , sizeof( T_6 ) ) ;
memset ( & V_244 , 0 , sizeof( T_8 ) ) ;
if ( ( V_61 = F_158 ( V_3 , & V_240 ) ) ) {
F_95 ( V_3 , L_69 ) ;
return V_61 ;
}
if ( ! F_167 ( V_3 , & V_240 ) )
return - V_280 ;
V_3 -> type = V_240 . V_276 ? V_281 : V_282 ;
V_243 = 1 ;
if ( ( V_61 = F_160 ( V_3 , V_243 , 1 , & V_244 ) ) ) {
F_95 ( V_3 , L_70 ) ;
return V_61 ;
}
if ( ! F_166 ( V_3 , & V_244 ) ) {
F_95 ( V_3 , L_71 ) ;
return - V_280 ;
}
V_3 -> V_5 . V_6 = F_162 ( V_244 . V_283 ) << 2 ;
if ( V_3 -> V_5 . V_6 == 0 ) {
F_168 ( V_3 , L_72 ) ;
return - V_284 ;
}
if ( V_3 -> V_5 . V_6 > V_285 ) {
F_95 ( V_3 , L_73 ) ;
return - V_280 ;
}
V_3 -> V_5 . V_233 = V_244 . V_233 ;
V_3 -> V_4 = ( F_162 ( V_244 . V_254 ) << 2 ) & ( V_3 -> V_5 . V_6 - 1 ) ;
if ( V_244 . V_286 ) {
V_3 -> V_287 = F_162 ( V_244 . V_288 ) ;
F_112 ( V_289 , & V_3 -> V_165 ) ;
}
if ( V_244 . V_252 ) {
V_3 -> V_290 = F_162 ( V_244 . V_253 ) ;
F_112 ( V_291 , & V_3 -> V_165 ) ;
} else {
V_3 -> V_290 = 0xffffffff ;
F_112 ( V_291 , & V_3 -> V_165 ) ;
}
V_3 -> V_5 . V_292 = 7 ;
V_3 -> V_5 . V_263 = 0 ;
V_3 -> V_5 . V_262 = V_244 . V_262 ;
switch ( V_244 . V_293 ) {
case V_294 :
V_3 -> V_5 . V_234 = V_268 ;
break;
case V_295 :
V_3 -> V_5 . V_234 = V_271 ;
break;
default:
F_95 ( V_3 , L_74 ) ;
return - V_280 ;
}
return 0 ;
}
static T_5 int F_170 ( struct V_2 * V_3 ,
int V_296 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
unsigned char V_54 [ 64 ] ;
int V_61 ;
F_97 ( & V_116 , V_54 , sizeof( V_54 ) , V_238 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_126 = V_3 -> V_260 + 12 ;
V_116 . V_134 = 1 ;
if ( ( V_61 = F_156 ( V_3 , & V_116 , V_297 , 0 ) ) )
return V_61 ;
V_54 [ V_3 -> V_260 + 10 ] |= ( ! ! V_296 << 2 ) ;
V_116 . V_126 = V_116 . V_130 [ 8 ] = 2 + ( ( V_54 [ 0 ] << 8 ) | ( V_54 [ 1 ] & 0xff ) ) ;
V_61 = F_157 ( V_3 , & V_116 ) ;
if ( V_61 ) {
F_95 ( V_3 , L_75 ) ;
F_94 ( V_3 , & V_116 ) ;
} else if ( ! V_61 && V_296 )
F_168 ( V_3 , L_76 ) ;
return V_61 ;
}
static int F_171 ( struct V_2 * V_3 , int V_298 )
{
struct V_115 V_116 ;
F_97 ( & V_116 , NULL , 0 , V_147 ) ;
V_116 . V_130 [ 0 ] = V_299 ;
V_116 . V_130 [ 4 ] = V_298 ? 1 : 0 ;
return F_83 ( V_3 , & V_116 ) ;
}
static T_5 int F_172 ( struct V_2 * V_3 ,
unsigned * V_149 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
unsigned char V_54 [ 256 + 18 ] ;
unsigned char * V_300 ;
int V_61 , V_4 ;
V_300 = & V_54 [ sizeof( struct V_261 ) + V_3 -> V_260 ] ;
F_97 ( & V_116 , V_54 , sizeof( V_54 ) , V_301 ) ;
V_116 . V_143 = & V_143 ;
V_61 = F_156 ( V_3 , & V_116 , V_302 , 0 ) ;
if ( V_61 ) {
V_116 . V_126 = V_3 -> V_260 + V_300 [ 1 ] + 2 +
sizeof( struct V_261 ) ;
V_61 = F_156 ( V_3 , & V_116 , V_302 , 0 ) ;
if ( V_61 ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
}
V_4 = 20 ;
if ( V_300 [ 1 ] >= 28 )
V_4 = 28 ;
if ( V_300 [ 1 ] >= 30 ) {
int V_303 = ( V_300 [ 30 ] << 8 ) + V_300 [ 31 ] ;
if ( V_303 > 0 )
V_4 = 34 ;
}
* V_149 = ( V_300 [ V_4 ] << 8 ) | V_300 [ V_4 + 1 ] ;
return 0 ;
}
static T_5 int F_173 ( struct V_2 * V_3 ,
unsigned * V_304 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
unsigned char V_54 [ 64 ] ;
unsigned int V_6 , V_305 , V_306 ;
int V_61 ;
F_97 ( & V_116 , V_54 , 2 , V_238 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_130 [ 0 ] = V_307 ;
V_116 . V_130 [ 1 ] = 2 ;
V_116 . V_130 [ 2 ] = 4 ;
V_116 . V_130 [ 8 ] = 2 ;
V_61 = F_83 ( V_3 , & V_116 ) ;
if ( V_61 ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
V_6 = ( ( unsigned int ) V_54 [ 0 ] << 8 ) + V_54 [ 1 ] + 2 ;
if ( V_6 > sizeof( V_54 ) )
V_6 = sizeof( V_54 ) ;
F_97 ( & V_116 , V_54 , V_6 , V_238 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_130 [ 0 ] = V_307 ;
V_116 . V_130 [ 1 ] = 2 ;
V_116 . V_130 [ 2 ] = 4 ;
V_116 . V_130 [ 8 ] = V_6 ;
V_61 = F_83 ( V_3 , & V_116 ) ;
if ( V_61 ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
if ( ! ( V_54 [ 6 ] & 0x40 ) ) {
F_168 ( V_3 , L_77 ) ;
return 1 ;
}
if ( ! ( V_54 [ 6 ] & 0x4 ) ) {
F_168 ( V_3 , L_78 ) ;
return 1 ;
}
V_305 = ( V_54 [ 6 ] >> 3 ) & 0x7 ;
V_306 = V_54 [ 16 ] & 0xf ;
switch ( V_305 ) {
case 0 :
* V_304 = V_308 [ V_306 ] ;
break;
case 1 :
* V_304 = V_309 [ V_306 ] ;
break;
case 2 :
* V_304 = V_310 [ V_306 ] ;
break;
default:
F_168 ( V_3 , L_79 , V_305 ) ;
return 1 ;
}
if ( * V_304 ) {
F_155 ( V_3 , L_80 , * V_304 ) ;
return 0 ;
} else {
F_168 ( V_3 , L_81 , V_306 , V_305 ) ;
return 1 ;
}
}
static T_5 int F_174 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
int V_61 ;
F_56 ( 2 , V_3 , L_82 ) ;
F_97 ( & V_116 , NULL , 0 , V_147 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_132 = 60 * V_133 ;
V_116 . V_130 [ 0 ] = V_311 ;
V_116 . V_130 [ 1 ] = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
static int F_175 ( struct V_2 * V_3 )
{
int V_61 ;
unsigned int V_149 , V_312 , V_150 ;
if ( ( V_61 = F_169 ( V_3 ) ) ) {
F_56 ( 2 , V_3 , L_83 ) ;
return V_61 ;
}
if ( ( V_61 = F_163 ( V_3 ) ) ) {
F_56 ( 1 , V_3 , L_84 ) ;
return - V_139 ;
}
F_170 ( V_3 , V_313 ) ;
if ( ( V_61 = F_172 ( V_3 , & V_149 ) ) )
V_149 = 16 * 177 ;
switch ( V_3 -> V_258 ) {
case 0x13 :
case 0x1a :
case 0x12 :
F_56 ( 1 , V_3 , L_85 , V_149 ) ;
break;
default:
if ( ( V_61 = F_173 ( V_3 , & V_312 ) ) )
V_312 = 16 ;
V_149 = F_16 ( V_149 , V_312 * 177 ) ;
F_56 ( 1 , V_3 , L_86 , V_149 / 176 ) ;
break;
}
V_150 = V_149 ;
if ( ( V_61 = F_98 ( V_3 , V_149 , V_150 ) ) ) {
F_56 ( 1 , V_3 , L_87 ) ;
return - V_139 ;
}
V_3 -> V_149 = V_149 ;
V_3 -> V_150 = V_150 ;
if ( ( V_61 = F_174 ( V_3 ) ) ) {
F_56 ( 1 , V_3 , L_88 ) ;
}
return 0 ;
}
static int F_176 ( struct V_2 * V_3 , T_11 V_314 )
{
int V_61 ;
long V_315 ;
struct V_117 * V_118 ;
F_177 ( V_3 -> V_52 -> V_53 ) ;
if ( ( V_61 = F_178 ( V_3 -> V_52 , V_316 | V_317 , V_3 ) ) )
goto V_128;
if ( ( V_61 = F_161 ( V_3 , & V_315 ) ) ) {
F_95 ( V_3 , L_89 ) ;
goto V_318;
}
F_179 ( V_3 -> V_202 , V_315 << 2 ) ;
F_179 ( V_3 -> V_52 -> V_137 , V_315 << 2 ) ;
F_180 ( V_3 -> V_52 , ( V_319 ) V_315 << 11 ) ;
V_118 = F_84 ( V_3 -> V_52 ) ;
if ( V_314 ) {
if ( ( V_61 = F_175 ( V_3 ) ) )
goto V_318;
F_181 ( V_118 -> V_320 ) ;
F_182 ( V_118 , V_3 -> V_5 . V_6 ) ;
F_183 ( V_118 -> V_320 ) ;
F_112 ( V_321 , & V_3 -> V_165 ) ;
} else {
F_98 ( V_3 , V_162 , V_162 ) ;
F_111 ( V_321 , & V_3 -> V_165 ) ;
}
if ( ( V_61 = F_109 ( V_3 , V_118 ) ) )
goto V_318;
if ( V_314 ) {
if ( ! F_71 ( V_3 , V_322 ) ) {
F_95 ( V_3 , L_90 ) ;
V_61 = - V_62 ;
goto V_318;
}
F_155 ( V_3 , L_91 , V_315 << 1 ) ;
}
return 0 ;
V_318:
F_184 ( V_3 -> V_52 , V_316 | V_317 ) ;
V_128:
return V_61 ;
}
static void F_185 ( struct V_2 * V_3 , int V_323 )
{
if ( V_323 && F_96 ( V_3 ) )
F_56 ( 1 , V_3 , L_92 ) ;
F_171 ( V_3 , 0 ) ;
F_98 ( V_3 , V_162 , V_162 ) ;
F_184 ( V_3 -> V_52 , V_316 | V_317 ) ;
F_67 ( V_3 ) ;
}
static struct V_2 * F_186 ( unsigned int V_324 )
{
if ( V_324 >= V_49 )
return NULL ;
return V_50 [ V_324 ] ;
}
static int F_187 ( struct V_325 * V_52 , T_11 V_326 )
{
struct V_2 * V_3 = NULL ;
int V_61 ;
F_188 ( & V_327 ) ;
F_188 ( & V_47 ) ;
V_3 = F_186 ( F_28 ( V_52 -> V_53 ) ) ;
if ( ! V_3 ) {
V_61 = - V_59 ;
goto V_128;
}
F_53 ( V_3 -> V_328 < 0 ) ;
V_3 -> V_328 ++ ;
if ( V_3 -> V_328 > 1 ) {
if ( ( V_326 & V_329 ) &&
! F_137 ( V_321 , & V_3 -> V_165 ) ) {
V_61 = - V_330 ;
goto V_331;
}
} else {
V_61 = F_176 ( V_3 , V_326 & V_329 ) ;
if ( V_61 )
goto V_331;
F_189 ( V_52 , V_163 ) ;
}
F_29 ( & V_47 ) ;
F_29 ( & V_327 ) ;
return 0 ;
V_331:
V_3 -> V_328 -- ;
V_128:
F_29 ( & V_47 ) ;
F_29 ( & V_327 ) ;
return V_61 ;
}
static void F_190 ( struct V_332 * V_202 , T_11 V_326 )
{
struct V_2 * V_3 = V_202 -> V_333 ;
F_188 ( & V_327 ) ;
F_188 ( & V_47 ) ;
V_3 -> V_328 -- ;
F_53 ( V_3 -> V_328 < 0 ) ;
if ( V_3 -> V_328 == 0 ) {
int V_323 = F_137 ( V_321 , & V_3 -> V_165 ) ;
F_185 ( V_3 , V_323 ) ;
}
F_29 ( & V_47 ) ;
F_29 ( & V_327 ) ;
}
static void F_191 ( struct V_95 * V_95 , int V_175 )
{
struct V_334 * V_335 = V_95 -> V_176 ;
struct V_2 * V_3 = V_335 -> V_3 ;
F_64 ( V_95 ) ;
F_139 ( V_335 -> V_95 , V_175 ) ;
F_78 ( V_335 , V_336 ) ;
F_52 ( V_3 ) ;
}
static void F_192 ( struct V_2 * V_3 , struct V_95 * V_95 )
{
struct V_95 * V_337 = F_193 ( V_95 , V_338 ) ;
struct V_334 * V_335 = F_194 ( V_336 , V_338 ) ;
V_335 -> V_3 = V_3 ;
V_335 -> V_95 = V_95 ;
V_337 -> V_187 = V_3 -> V_52 ;
V_337 -> V_176 = V_335 ;
V_337 -> V_188 = F_191 ;
V_3 -> V_22 . V_26 += F_195 ( V_95 ) ;
F_99 ( V_3 , V_337 ) ;
}
static void F_196 ( struct V_117 * V_118 , struct V_95 * V_95 )
{
struct V_2 * V_3 = V_118 -> V_339 ;
T_1 V_190 ;
struct V_83 * V_86 ;
int V_340 , V_341 ;
struct V_104 * V_105 ;
V_190 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
F_12 ( & V_3 -> V_78 . V_209 ) ;
V_341 = 0 ;
F_126 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_86 -> V_1 == V_190 ) {
F_12 ( & V_86 -> V_28 ) ;
if ( ( V_86 -> V_192 == V_208 ) ||
( V_86 -> V_192 == V_215 ) ) {
F_101 ( & V_86 -> V_94 , V_95 ) ;
V_86 -> V_201 +=
V_95 -> V_111 . V_160 / V_163 ;
if ( ( V_86 -> V_201 >= V_86 -> V_84 ) &&
( V_86 -> V_192 == V_208 ) ) {
F_107 ( & V_86 -> V_179 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
F_13 ( & V_86 -> V_28 ) ;
F_13 ( & V_3 -> V_78 . V_209 ) ;
return;
} else {
V_341 = 1 ;
}
F_13 ( & V_86 -> V_28 ) ;
}
}
F_13 ( & V_3 -> V_78 . V_209 ) ;
F_12 ( & V_3 -> V_28 ) ;
if ( V_3 -> V_31 > 0
&& V_3 -> V_29 >= V_3 -> V_31 ) {
F_197 ( & V_118 -> V_204 , V_205 ) ;
do {
F_13 ( & V_3 -> V_28 ) ;
F_198 ( V_205 , V_133 ) ;
F_12 ( & V_3 -> V_28 ) ;
} while( V_3 -> V_29 > V_3 -> V_30 );
}
F_13 ( & V_3 -> V_28 ) ;
V_105 = F_194 ( V_3 -> V_108 , V_338 ) ;
V_105 -> V_95 = V_95 ;
F_12 ( & V_3 -> V_28 ) ;
F_53 ( V_3 -> V_29 < 0 ) ;
V_340 = ( V_3 -> V_29 == 0 ) ;
F_80 ( V_3 , V_105 ) ;
F_13 ( & V_3 -> V_28 ) ;
F_57 ( & V_3 -> V_198 , 1 ) ;
if ( V_340 ) {
F_58 ( & V_3 -> V_82 ) ;
} else if ( ! F_68 ( & V_3 -> V_78 . V_100 ) && ! V_341 ) {
F_58 ( & V_3 -> V_82 ) ;
}
}
static void F_199 ( struct V_117 * V_118 , struct V_95 * V_95 )
{
struct V_2 * V_3 ;
char V_342 [ V_343 ] ;
struct V_95 * V_344 ;
V_3 = V_118 -> V_339 ;
if ( ! V_3 ) {
F_38 ( L_93 ,
F_200 ( V_95 -> V_187 , V_342 ) ) ;
goto V_345;
}
F_56 ( 2 , V_3 , L_94 ,
( unsigned long long ) V_95 -> V_111 . V_112 ,
( unsigned long long ) F_106 ( V_95 ) ) ;
if ( F_100 ( V_95 ) == V_124 ) {
F_192 ( V_3 , V_95 ) ;
return;
}
if ( ! F_137 ( V_321 , & V_3 -> V_165 ) ) {
F_168 ( V_3 , L_95 ,
( unsigned long long ) V_95 -> V_111 . V_112 ) ;
goto V_345;
}
if ( ! V_95 -> V_111 . V_160 || ( V_95 -> V_111 . V_160 % V_163 ) ) {
F_95 ( V_3 , L_96 ) ;
goto V_345;
}
F_201 ( V_118 , & V_95 ) ;
do {
T_1 V_190 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
T_1 V_346 = F_1 ( F_106 ( V_95 ) - 1 , V_3 ) ;
if ( V_346 != V_190 ) {
F_53 ( V_346 != V_190 + V_3 -> V_5 . V_6 ) ;
V_344 = F_202 ( V_95 , V_346 -
V_95 -> V_111 . V_112 ,
V_338 , V_347 ) ;
F_203 ( V_344 , V_95 ) ;
} else {
V_344 = V_95 ;
}
F_196 ( V_118 , V_344 ) ;
} while ( V_344 != V_95 );
return;
V_345:
F_204 ( V_95 ) ;
}
static int F_205 ( struct V_117 * V_118 , struct V_348 * V_349 ,
struct V_167 * V_168 )
{
struct V_2 * V_3 = V_118 -> V_339 ;
T_1 V_190 = F_1 ( V_349 -> V_112 , V_3 ) ;
int V_350 = ( ( V_349 -> V_112 - V_190 ) << 9 ) + V_349 -> V_160 ;
int V_351 = ( V_3 -> V_5 . V_6 << 9 ) - V_350 ;
int V_352 ;
V_352 = V_166 - V_349 -> V_160 ;
V_351 = F_15 ( V_351 , V_352 ) ;
F_53 ( V_351 < 0 ) ;
return V_351 ;
}
static void F_206 ( struct V_2 * V_3 )
{
struct V_117 * V_118 = V_3 -> V_202 -> V_203 ;
F_207 ( V_118 , F_199 ) ;
F_208 ( V_118 , V_163 ) ;
F_182 ( V_118 , V_285 ) ;
F_209 ( V_118 , F_205 ) ;
V_118 -> V_339 = V_3 ;
}
static int F_42 ( struct V_68 * V_69 , void * V_13 )
{
struct V_2 * V_3 = V_69 -> V_353 ;
char * V_354 ;
char V_355 [ V_343 ] ;
int V_221 [ V_222 ] ;
F_210 ( V_69 , L_97 , V_3 -> V_8 ,
F_200 ( V_3 -> V_52 , V_355 ) ) ;
F_210 ( V_69 , L_98 ) ;
F_210 ( V_69 , L_99 , V_3 -> V_5 . V_6 / 2 ) ;
if ( V_3 -> V_5 . V_263 == 0 )
V_354 = L_100 ;
else
V_354 = L_101 ;
F_210 ( V_69 , L_102 , V_354 ) ;
F_210 ( V_69 , L_103 , V_3 -> V_5 . V_233 ? L_60 : L_61 ) ;
F_210 ( V_69 , L_104 , V_3 -> V_5 . V_292 ) ;
F_210 ( V_69 , L_105 , V_3 -> V_5 . V_262 ) ;
if ( V_3 -> V_5 . V_234 == V_268 )
V_354 = L_106 ;
else if ( V_3 -> V_5 . V_234 == V_271 )
V_354 = L_107 ;
else
V_354 = L_101 ;
F_210 ( V_69 , L_108 , V_354 ) ;
F_210 ( V_69 , L_109 ) ;
F_210 ( V_69 , L_110 , V_3 -> V_22 . V_23 ) ;
F_210 ( V_69 , L_111 , V_3 -> V_22 . V_24 ) ;
F_210 ( V_69 , L_112 , V_3 -> V_22 . V_25 >> 1 ) ;
F_210 ( V_69 , L_113 , V_3 -> V_22 . V_27 >> 1 ) ;
F_210 ( V_69 , L_114 , V_3 -> V_22 . V_26 >> 1 ) ;
F_210 ( V_69 , L_115 ) ;
F_210 ( V_69 , L_116 , V_3 -> V_328 ) ;
F_210 ( V_69 , L_117 , V_3 -> V_165 ) ;
F_210 ( V_69 , L_118 , V_3 -> V_150 ) ;
F_210 ( V_69 , L_119 , V_3 -> V_149 ) ;
F_210 ( V_69 , L_120 , V_3 -> V_4 ) ;
F_210 ( V_69 , L_121 , V_3 -> V_260 ) ;
F_210 ( V_69 , L_122 ) ;
F_210 ( V_69 , L_123 , V_3 -> V_29 ) ;
F_210 ( V_69 , L_124 , F_54 ( & V_3 -> V_78 . V_79 ) ) ;
F_210 ( V_69 , L_125 , ( unsigned long long ) V_3 -> V_199 ) ;
F_143 ( V_3 , V_221 ) ;
F_210 ( V_69 , L_126 ,
V_221 [ 0 ] , V_221 [ 1 ] , V_221 [ 2 ] , V_221 [ 3 ] , V_221 [ 4 ] , V_221 [ 5 ] ) ;
F_210 ( V_69 , L_127 ,
V_3 -> V_30 ,
V_3 -> V_31 ) ;
return 0 ;
}
static int F_211 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
return F_44 ( V_71 , F_42 , F_212 ( V_70 ) ) ;
}
static int F_213 ( struct V_2 * V_3 , T_12 V_37 )
{
int V_85 ;
int V_61 = 0 ;
char V_342 [ V_343 ] ;
struct V_325 * V_52 ;
if ( V_3 -> V_51 == V_37 ) {
F_95 ( V_3 , L_128 ) ;
return - V_330 ;
}
for ( V_85 = 0 ; V_85 < V_49 ; V_85 ++ ) {
struct V_2 * V_356 = V_50 [ V_85 ] ;
if ( ! V_356 )
continue;
if ( V_356 -> V_52 -> V_53 == V_37 ) {
F_95 ( V_3 , L_129 ,
F_200 ( V_356 -> V_52 , V_342 ) ) ;
return - V_330 ;
}
if ( V_356 -> V_51 == V_37 ) {
F_95 ( V_3 , L_130 ) ;
return - V_330 ;
}
}
V_52 = F_177 ( V_37 ) ;
if ( ! V_52 )
return - V_62 ;
V_61 = F_178 ( V_52 , V_316 | V_357 , NULL ) ;
if ( V_61 )
return V_61 ;
F_214 ( V_58 ) ;
V_3 -> V_52 = V_52 ;
F_189 ( V_52 , V_163 ) ;
F_206 ( V_3 ) ;
F_57 ( & V_3 -> V_78 . V_79 , 0 ) ;
V_3 -> V_78 . V_358 = F_215 ( F_144 , V_3 , L_1 , V_3 -> V_8 ) ;
if ( F_21 ( V_3 -> V_78 . V_358 ) ) {
F_95 ( V_3 , L_131 ) ;
V_61 = - V_62 ;
goto V_359;
}
F_216 ( V_3 -> V_8 , 0 , V_360 , & V_361 , V_3 ) ;
F_56 ( 1 , V_3 , L_132 , F_200 ( V_52 , V_342 ) ) ;
return 0 ;
V_359:
F_184 ( V_52 , V_316 | V_357 ) ;
F_33 ( V_58 ) ;
return V_61 ;
}
static int F_217 ( struct V_325 * V_52 , T_11 V_326 , unsigned int V_130 , unsigned long V_362 )
{
struct V_2 * V_3 = V_52 -> V_137 -> V_333 ;
int V_61 ;
F_56 ( 2 , V_3 , L_133 ,
V_130 , F_27 ( V_52 -> V_53 ) , F_28 ( V_52 -> V_53 ) ) ;
F_188 ( & V_327 ) ;
switch ( V_130 ) {
case V_363 :
if ( V_3 -> V_328 == 1 )
F_171 ( V_3 , 0 ) ;
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
V_61 = F_218 ( V_3 -> V_52 , V_326 , V_130 , V_362 ) ;
break;
default:
F_56 ( 2 , V_3 , L_134 , V_130 ) ;
V_61 = - V_369 ;
}
F_29 ( & V_327 ) ;
return V_61 ;
}
static unsigned int F_219 ( struct V_332 * V_202 ,
unsigned int V_370 )
{
struct V_2 * V_3 = V_202 -> V_333 ;
struct V_332 * V_371 ;
if ( ! V_3 )
return 0 ;
if ( ! V_3 -> V_52 )
return 0 ;
V_371 = V_3 -> V_52 -> V_137 ;
if ( ! V_371 || ! V_371 -> V_372 -> V_373 )
return 0 ;
return V_371 -> V_372 -> V_373 ( V_371 , V_370 ) ;
}
static char * F_220 ( struct V_332 * V_374 , T_13 * V_326 )
{
return F_221 ( V_14 , L_135 , V_374 -> V_375 ) ;
}
static int F_32 ( T_12 V_37 , T_12 * V_51 )
{
int V_46 ;
int V_61 = - V_62 ;
struct V_2 * V_3 ;
struct V_332 * V_202 ;
F_26 ( & V_47 , V_48 ) ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ )
if ( ! V_50 [ V_46 ] )
break;
if ( V_46 == V_49 ) {
F_38 ( L_136 , V_49 ) ;
V_61 = - V_330 ;
goto V_376;
}
V_3 = F_3 ( sizeof( struct V_2 ) , V_14 ) ;
if ( ! V_3 )
goto V_376;
V_3 -> V_108 = F_222 ( V_377 ,
sizeof( struct V_104 ) ) ;
if ( ! V_3 -> V_108 )
goto V_359;
F_70 ( & V_3 -> V_78 . V_100 ) ;
F_70 ( & V_3 -> V_78 . V_99 ) ;
F_62 ( & V_3 -> V_78 . V_209 ) ;
F_62 ( & V_3 -> V_28 ) ;
F_62 ( & V_3 -> V_80 . V_28 ) ;
F_63 ( & V_3 -> V_80 . V_152 ) ;
F_63 ( & V_3 -> V_80 . V_153 ) ;
sprintf ( V_3 -> V_8 , V_63 L_13 , V_46 ) ;
F_223 ( & V_3 -> V_82 ) ;
V_3 -> V_107 = V_378 ;
V_3 -> V_31 = V_31 ;
V_3 -> V_30 = V_30 ;
V_202 = F_224 ( 1 ) ;
if ( ! V_202 )
goto V_359;
V_3 -> V_202 = V_202 ;
V_202 -> V_56 = V_379 ;
V_202 -> V_380 = V_46 ;
V_202 -> V_372 = & V_381 ;
V_202 -> V_165 = V_382 ;
strcpy ( V_202 -> V_375 , V_3 -> V_8 ) ;
V_202 -> V_383 = F_220 ;
V_202 -> V_333 = V_3 ;
V_202 -> V_203 = F_225 ( V_14 ) ;
if ( ! V_202 -> V_203 )
goto V_384;
V_3 -> V_51 = F_20 ( V_379 , V_46 ) ;
V_61 = F_213 ( V_3 , V_37 ) ;
if ( V_61 )
goto V_385;
V_202 -> V_386 = V_3 -> V_52 -> V_137 -> V_386 ;
V_202 -> V_387 = V_3 -> V_52 -> V_137 -> V_387 ;
F_226 ( V_202 ) ;
F_18 ( V_3 ) ;
F_45 ( V_3 ) ;
V_50 [ V_46 ] = V_3 ;
if ( V_51 )
* V_51 = V_3 -> V_51 ;
F_29 ( & V_47 ) ;
return 0 ;
V_385:
F_227 ( V_202 -> V_203 ) ;
V_384:
F_228 ( V_202 ) ;
V_359:
if ( V_3 -> V_108 )
F_229 ( V_3 -> V_108 ) ;
F_9 ( V_3 ) ;
V_376:
F_29 ( & V_47 ) ;
F_38 ( L_137 ) ;
return V_61 ;
}
static int F_35 ( T_12 V_51 )
{
struct V_2 * V_3 ;
int V_46 ;
int V_61 = 0 ;
F_26 ( & V_47 , V_48 ) ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ ) {
V_3 = V_50 [ V_46 ] ;
if ( V_3 && ( V_3 -> V_51 == V_51 ) )
break;
}
if ( V_46 == V_49 ) {
F_230 ( L_138 ) ;
V_61 = - V_284 ;
goto V_128;
}
if ( V_3 -> V_328 > 0 ) {
V_61 = - V_330 ;
goto V_128;
}
if ( ! F_21 ( V_3 -> V_78 . V_358 ) )
F_231 ( V_3 -> V_78 . V_358 ) ;
V_50 [ V_46 ] = NULL ;
F_48 ( V_3 ) ;
F_22 ( V_3 ) ;
F_184 ( V_3 -> V_52 , V_316 | V_357 ) ;
F_232 ( V_3 -> V_8 , V_360 ) ;
F_56 ( 1 , V_3 , L_139 ) ;
F_233 ( V_3 -> V_202 ) ;
F_227 ( V_3 -> V_202 -> V_203 ) ;
F_228 ( V_3 -> V_202 ) ;
F_229 ( V_3 -> V_108 ) ;
F_9 ( V_3 ) ;
F_33 ( V_58 ) ;
V_128:
F_29 ( & V_47 ) ;
return V_61 ;
}
static void F_234 ( struct V_388 * V_389 )
{
struct V_2 * V_3 ;
F_26 ( & V_47 , V_48 ) ;
V_3 = F_186 ( V_389 -> V_390 ) ;
if ( V_3 ) {
V_389 -> V_37 = F_235 ( V_3 -> V_52 -> V_53 ) ;
V_389 -> V_51 = F_235 ( V_3 -> V_51 ) ;
} else {
V_389 -> V_37 = 0 ;
V_389 -> V_51 = 0 ;
}
V_389 -> V_391 = V_49 ;
F_29 ( & V_47 ) ;
}
static long F_236 ( struct V_71 * V_71 , unsigned int V_130 , unsigned long V_362 )
{
void T_14 * V_392 = ( void T_14 * ) V_362 ;
struct V_388 V_389 ;
int V_61 = 0 ;
T_12 V_51 = 0 ;
if ( V_130 != V_393 )
return - V_369 ;
if ( F_237 ( & V_389 , V_392 , sizeof( struct V_388 ) ) )
return - V_394 ;
switch ( V_389 . V_395 ) {
case V_396 :
if ( ! F_238 ( V_397 ) )
return - V_398 ;
V_61 = F_32 ( F_239 ( V_389 . V_37 ) , & V_51 ) ;
V_389 . V_51 = F_235 ( V_51 ) ;
break;
case V_399 :
if ( ! F_238 ( V_397 ) )
return - V_398 ;
V_61 = F_35 ( F_239 ( V_389 . V_51 ) ) ;
break;
case V_400 :
F_234 ( & V_389 ) ;
break;
default:
return - V_369 ;
}
if ( F_240 ( V_392 , & V_389 , sizeof( struct V_388 ) ) )
return - V_394 ;
return V_61 ;
}
static long F_241 ( struct V_71 * V_71 , unsigned int V_130 , unsigned long V_362 )
{
return F_236 ( V_71 , V_130 , ( unsigned long ) F_242 ( V_362 ) ) ;
}
static int T_15 F_243 ( void )
{
int V_61 ;
F_244 ( & V_47 ) ;
V_336 = F_222 ( V_401 ,
sizeof( struct V_334 ) ) ;
if ( ! V_336 )
return - V_62 ;
V_61 = F_245 ( V_379 , V_63 ) ;
if ( V_61 < 0 ) {
F_38 ( L_140 ) ;
goto V_402;
}
if ( ! V_379 )
V_379 = V_61 ;
V_61 = F_36 () ;
if ( V_61 )
goto V_128;
F_50 () ;
V_61 = F_246 ( & V_403 ) ;
if ( V_61 ) {
F_38 ( L_141 ) ;
goto V_404;
}
V_360 = F_247 ( L_142 V_63 , NULL ) ;
return 0 ;
V_404:
F_51 () ;
F_39 () ;
V_128:
F_248 ( V_379 , V_63 ) ;
V_402:
F_229 ( V_336 ) ;
return V_61 ;
}
static void T_16 F_249 ( void )
{
F_232 ( L_142 V_63 , NULL ) ;
F_250 ( & V_403 ) ;
F_51 () ;
F_39 () ;
F_248 ( V_379 , V_63 ) ;
F_229 ( V_336 ) ;
}
