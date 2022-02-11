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
static void F_113 ( struct V_95 * V_95 )
{
struct V_83 * V_86 = V_95 -> V_167 ;
struct V_2 * V_3 = V_86 -> V_3 ;
F_53 ( ! V_3 ) ;
F_56 ( 2 , V_3 , L_36 ,
V_95 , ( unsigned long long ) V_86 -> V_1 ,
( unsigned long long ) V_95 -> V_111 . V_112 , V_95 -> V_168 ) ;
if ( V_95 -> V_168 )
F_107 ( & V_86 -> V_169 ) ;
if ( F_55 ( & V_86 -> V_170 ) ) {
F_107 ( & V_86 -> V_171 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
F_52 ( V_3 ) ;
}
static void F_114 ( struct V_95 * V_95 )
{
struct V_83 * V_86 = V_95 -> V_167 ;
struct V_2 * V_3 = V_86 -> V_3 ;
F_53 ( ! V_3 ) ;
F_56 ( 2 , V_3 , L_37 , V_86 -> V_102 , V_95 -> V_168 ) ;
V_3 -> V_22 . V_24 ++ ;
F_52 ( V_3 ) ;
F_115 ( & V_86 -> V_170 ) ;
F_107 ( & V_86 -> V_171 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
static void F_116 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
int V_172 = 0 ;
struct V_95 * V_95 ;
int V_173 ;
char V_174 [ V_175 ] ;
F_53 ( F_103 ( & V_86 -> V_94 ) ) ;
F_57 ( & V_86 -> V_170 , 0 ) ;
F_57 ( & V_86 -> V_169 , 0 ) ;
memset ( V_174 , 0 , sizeof( V_174 ) ) ;
F_12 ( & V_86 -> V_28 ) ;
F_117 (bio, &pkt->orig_bios) {
int V_176 = ( V_95 -> V_111 . V_112 - V_86 -> V_1 ) /
( V_163 >> 9 ) ;
int V_177 = V_95 -> V_111 . V_160 / V_163 ;
V_3 -> V_22 . V_25 += V_177 * ( V_163 >> 9 ) ;
F_53 ( V_176 < 0 ) ;
F_53 ( V_176 + V_177 > V_86 -> V_84 ) ;
for ( V_173 = V_176 ; V_173 < V_176 + V_177 ; V_173 ++ )
V_174 [ V_173 ] = 1 ;
}
F_13 ( & V_86 -> V_28 ) ;
if ( V_86 -> V_178 ) {
F_56 ( 2 , V_3 , L_38 ,
( unsigned long long ) V_86 -> V_1 ) ;
goto V_179;
}
for ( V_173 = 0 ; V_173 < V_86 -> V_84 ; V_173 ++ ) {
int V_13 , V_4 ;
if ( V_174 [ V_173 ] )
continue;
V_95 = V_86 -> V_97 [ V_173 ] ;
F_118 ( V_95 ) ;
V_95 -> V_111 . V_112 = V_86 -> V_1 + V_173 * ( V_163 >> 9 ) ;
V_95 -> V_180 = V_3 -> V_52 ;
V_95 -> V_181 = F_113 ;
V_95 -> V_167 = V_86 ;
V_13 = ( V_173 * V_163 ) / V_166 ;
V_4 = ( V_173 * V_163 ) % V_166 ;
F_56 ( 2 , V_3 , L_39 ,
V_173 , V_86 -> V_91 [ V_13 ] , V_4 ) ;
if ( ! F_119 ( V_95 , V_86 -> V_91 [ V_13 ] , V_163 , V_4 ) )
F_120 () ;
F_107 ( & V_86 -> V_170 ) ;
F_121 ( V_95 , V_182 , 0 ) ;
F_99 ( V_3 , V_95 ) ;
V_172 ++ ;
}
V_179:
F_56 ( 2 , V_3 , L_40 ,
V_172 , ( unsigned long long ) V_86 -> V_1 ) ;
V_3 -> V_22 . V_23 ++ ;
V_3 -> V_22 . V_27 += V_172 * ( V_163 >> 9 ) ;
}
static struct V_83 * F_122 ( struct V_2 * V_3 , int V_183 )
{
struct V_83 * V_86 ;
F_123 (pkt, &pd->cdrw.pkt_free_list, list) {
if ( V_86 -> V_1 == V_183 || V_86 -> V_103 . V_98 == & V_3 -> V_78 . V_100 ) {
F_124 ( & V_86 -> V_103 ) ;
if ( V_86 -> V_1 != V_183 )
V_86 -> V_178 = 0 ;
return V_86 ;
}
}
F_120 () ;
return NULL ;
}
static void F_125 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
if ( V_86 -> V_178 ) {
F_72 ( & V_86 -> V_103 , & V_3 -> V_78 . V_100 ) ;
} else {
F_126 ( & V_86 -> V_103 , & V_3 -> V_78 . V_100 ) ;
}
}
static int F_127 ( struct V_83 * V_86 )
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
bio_set_op_attrs(pkt->bio, REQ_OP_WRITE, 0);
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
static inline void F_128 ( struct V_83 * V_86 , enum V_184 V_185 )
{
#if V_186 > 1
static const char * V_187 [] = {
L_41 , L_42 , L_43 , L_44 , L_45 , L_46
} ;
enum V_184 V_188 = V_86 -> V_185 ;
F_56 ( 2 , V_3 , L_47 ,
V_86 -> V_102 , ( unsigned long long ) V_86 -> V_1 ,
V_187 [ V_188 ] , V_187 [ V_185 ] ) ;
#endif
V_86 -> V_185 = V_185 ;
}
static int F_129 ( struct V_2 * V_3 )
{
struct V_83 * V_86 , * V_13 ;
struct V_95 * V_95 = NULL ;
T_1 V_183 = 0 ;
struct V_104 * V_105 , * V_189 ;
struct V_106 * V_20 ;
int V_190 ;
F_57 ( & V_3 -> V_191 , 0 ) ;
if ( F_68 ( & V_3 -> V_78 . V_100 ) ) {
F_56 ( 2 , V_3 , L_48 ) ;
return 0 ;
}
F_12 ( & V_3 -> V_28 ) ;
V_189 = F_79 ( V_3 , V_3 -> V_192 ) ;
if ( ! V_189 ) {
V_20 = F_130 ( & V_3 -> V_107 ) ;
if ( V_20 )
V_189 = F_75 ( V_20 , struct V_104 , V_106 ) ;
}
V_105 = V_189 ;
while ( V_105 ) {
V_95 = V_105 -> V_95 ;
V_183 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
F_123 (p, &pd->cdrw.pkt_active_list, list) {
if ( V_13 -> V_1 == V_183 ) {
V_95 = NULL ;
goto V_193;
}
}
break;
V_193:
V_105 = F_73 ( V_105 ) ;
if ( ! V_105 ) {
V_20 = F_130 ( & V_3 -> V_107 ) ;
if ( V_20 )
V_105 = F_75 ( V_20 , struct V_104 , V_106 ) ;
}
if ( V_105 == V_189 )
V_105 = NULL ;
}
F_13 ( & V_3 -> V_28 ) ;
if ( ! V_95 ) {
F_56 ( 2 , V_3 , L_49 ) ;
return 0 ;
}
V_86 = F_122 ( V_3 , V_183 ) ;
V_3 -> V_192 = V_183 + V_3 -> V_5 . V_6 ;
V_86 -> V_1 = V_183 ;
F_53 ( V_86 -> V_84 != V_3 -> V_5 . V_6 >> 2 ) ;
V_86 -> V_194 = 0 ;
F_12 ( & V_3 -> V_28 ) ;
F_56 ( 2 , V_3 , L_50 , ( unsigned long long ) V_183 ) ;
while ( ( V_105 = F_79 ( V_3 , V_183 ) ) != NULL ) {
V_95 = V_105 -> V_95 ;
F_56 ( 2 , V_3 , L_51 , ( unsigned long long )
F_1 ( V_95 -> V_111 . V_112 , V_3 ) ) ;
if ( F_1 ( V_95 -> V_111 . V_112 , V_3 ) != V_183 )
break;
F_76 ( V_3 , V_105 ) ;
F_12 ( & V_86 -> V_28 ) ;
F_101 ( & V_86 -> V_94 , V_95 ) ;
V_86 -> V_194 += V_95 -> V_111 . V_160 / V_163 ;
F_13 ( & V_86 -> V_28 ) ;
}
V_190 = ( V_3 -> V_31 > 0
&& V_3 -> V_29 <= V_3 -> V_30 ) ;
F_13 ( & V_3 -> V_28 ) ;
if ( V_190 ) {
F_131 ( & V_3 -> V_195 -> V_196 -> V_197 ,
V_198 ) ;
}
V_86 -> V_199 = F_15 ( V_200 , 1 ) ;
F_128 ( V_86 , V_201 ) ;
F_57 ( & V_86 -> V_171 , 1 ) ;
F_12 ( & V_3 -> V_78 . V_202 ) ;
F_72 ( & V_86 -> V_103 , & V_3 -> V_78 . V_99 ) ;
F_13 ( & V_3 -> V_78 . V_202 ) ;
return 1 ;
}
static void F_132 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
int V_173 ;
F_118 ( V_86 -> V_88 ) ;
V_86 -> V_88 -> V_111 . V_112 = V_86 -> V_1 ;
V_86 -> V_88 -> V_180 = V_3 -> V_52 ;
V_86 -> V_88 -> V_181 = F_114 ;
V_86 -> V_88 -> V_167 = V_86 ;
for ( V_173 = 0 ; V_173 < V_86 -> V_84 ; V_173 ++ ) {
struct V_203 * V_203 = V_86 -> V_91 [ ( V_173 * V_163 ) / V_166 ] ;
unsigned V_4 = ( V_173 * V_163 ) % V_166 ;
if ( ! F_119 ( V_86 -> V_88 , V_203 , V_163 , V_4 ) )
F_120 () ;
}
F_56 ( 2 , V_3 , L_52 , V_86 -> V_88 -> V_204 ) ;
F_12 ( & V_86 -> V_28 ) ;
F_133 ( V_86 -> V_88 , V_86 -> V_94 . V_205 ) ;
F_128 ( V_86 , V_206 ) ;
F_13 ( & V_86 -> V_28 ) ;
F_56 ( 2 , V_3 , L_53 ,
V_86 -> V_194 , ( unsigned long long ) V_86 -> V_1 ) ;
if ( F_134 ( V_164 , & V_3 -> V_165 ) || ( V_86 -> V_194 < V_86 -> V_84 ) )
V_86 -> V_178 = 1 ;
else
V_86 -> V_178 = 0 ;
F_57 ( & V_86 -> V_170 , 1 ) ;
F_121 ( V_86 -> V_88 , V_207 , 0 ) ;
F_99 ( V_3 , V_86 -> V_88 ) ;
}
static void F_135 ( struct V_83 * V_86 , int error )
{
struct V_95 * V_95 ;
if ( error )
V_86 -> V_178 = 0 ;
while ( ( V_95 = F_105 ( & V_86 -> V_94 ) ) ) {
V_95 -> V_168 = error ;
F_136 ( V_95 ) ;
}
}
static void F_137 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
F_56 ( 2 , V_3 , L_54 , V_86 -> V_102 ) ;
for (; ; ) {
switch ( V_86 -> V_185 ) {
case V_201 :
if ( ( V_86 -> V_194 < V_86 -> V_84 ) && ( V_86 -> V_199 > 0 ) )
return;
V_86 -> V_199 = 0 ;
F_116 ( V_3 , V_86 ) ;
F_128 ( V_86 , V_208 ) ;
break;
case V_208 :
if ( F_54 ( & V_86 -> V_170 ) > 0 )
return;
if ( F_54 ( & V_86 -> V_169 ) > 0 ) {
F_128 ( V_86 , V_209 ) ;
} else {
F_132 ( V_3 , V_86 ) ;
}
break;
case V_206 :
if ( F_54 ( & V_86 -> V_170 ) > 0 )
return;
if ( ! V_86 -> V_88 -> V_168 ) {
F_128 ( V_86 , V_210 ) ;
} else {
F_128 ( V_86 , V_209 ) ;
}
break;
case V_209 :
if ( F_127 ( V_86 ) ) {
F_132 ( V_3 , V_86 ) ;
} else {
F_56 ( 2 , V_3 , L_55 ) ;
F_128 ( V_86 , V_210 ) ;
}
break;
case V_210 :
F_135 ( V_86 , V_86 -> V_88 -> V_168 ) ;
return;
default:
F_120 () ;
break;
}
}
}
static void F_138 ( struct V_2 * V_3 )
{
struct V_83 * V_86 , * V_98 ;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_54 ( & V_86 -> V_171 ) > 0 ) {
F_57 ( & V_86 -> V_171 , 0 ) ;
F_137 ( V_3 , V_86 ) ;
}
}
F_12 ( & V_3 -> V_78 . V_202 ) ;
F_69 (pkt, next, &pd->cdrw.pkt_active_list, list) {
if ( V_86 -> V_185 == V_210 ) {
F_139 ( & V_86 -> V_103 ) ;
F_125 ( V_3 , V_86 ) ;
F_128 ( V_86 , V_211 ) ;
F_57 ( & V_3 -> V_191 , 1 ) ;
}
}
F_13 ( & V_3 -> V_78 . V_202 ) ;
}
static void F_140 ( struct V_2 * V_3 , int * V_212 )
{
struct V_83 * V_86 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_213 ; V_85 ++ )
V_212 [ V_85 ] = 0 ;
F_12 ( & V_3 -> V_78 . V_202 ) ;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
V_212 [ V_86 -> V_185 ] ++ ;
}
F_13 ( & V_3 -> V_78 . V_202 ) ;
}
static int F_141 ( void * V_214 )
{
struct V_2 * V_3 = V_214 ;
struct V_83 * V_86 ;
long V_215 , V_216 ;
F_142 ( V_217 , V_218 ) ;
F_143 () ;
for (; ; ) {
F_144 ( V_219 , V_217 ) ;
F_145 ( & V_3 -> V_82 , & V_219 ) ;
for (; ; ) {
F_146 ( V_220 ) ;
if ( F_54 ( & V_3 -> V_191 ) > 0 )
goto V_221;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_54 ( & V_86 -> V_171 ) > 0 )
goto V_221;
}
if ( F_54 ( & V_3 -> V_80 . V_81 ) != 0 )
goto V_221;
if ( V_186 > 1 ) {
int V_212 [ V_213 ] ;
F_140 ( V_3 , V_212 ) ;
F_56 ( 2 , V_3 , L_56 ,
V_212 [ 0 ] , V_212 [ 1 ] , V_212 [ 2 ] ,
V_212 [ 3 ] , V_212 [ 4 ] , V_212 [ 5 ] ) ;
}
V_215 = V_222 ;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_86 -> V_199 && V_86 -> V_199 < V_215 )
V_215 = V_86 -> V_199 ;
}
F_56 ( 2 , V_3 , L_57 ) ;
V_216 = F_147 ( V_215 ) ;
F_56 ( 2 , V_3 , L_58 ) ;
F_148 () ;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( ! V_86 -> V_199 )
continue;
V_86 -> V_199 -= V_215 - V_216 ;
if ( V_86 -> V_199 <= 0 ) {
V_86 -> V_199 = 0 ;
F_107 ( & V_86 -> V_171 ) ;
}
}
if ( F_149 () )
break;
}
V_221:
F_146 ( V_223 ) ;
F_150 ( & V_3 -> V_82 , & V_219 ) ;
if ( F_149 () )
break;
while ( F_129 ( V_3 ) )
;
F_138 ( V_3 ) ;
F_102 ( V_3 ) ;
}
return 0 ;
}
static void F_151 ( struct V_2 * V_3 )
{
F_152 ( V_3 , L_59 ,
V_3 -> V_5 . V_224 ? L_60 : L_61 ,
V_3 -> V_5 . V_6 >> 2 ,
V_3 -> V_5 . V_225 == 8 ? '1' : '2' ) ;
}
static int F_153 ( struct V_2 * V_3 , struct V_115 * V_116 , int V_226 , int V_227 )
{
memset ( V_116 -> V_130 , 0 , sizeof( V_116 -> V_130 ) ) ;
V_116 -> V_130 [ 0 ] = V_228 ;
V_116 -> V_130 [ 2 ] = V_226 | ( V_227 << 6 ) ;
V_116 -> V_130 [ 7 ] = V_116 -> V_126 >> 8 ;
V_116 -> V_130 [ 8 ] = V_116 -> V_126 & 0xff ;
V_116 -> V_121 = V_229 ;
return F_83 ( V_3 , V_116 ) ;
}
static int F_154 ( struct V_2 * V_3 , struct V_115 * V_116 )
{
memset ( V_116 -> V_130 , 0 , sizeof( V_116 -> V_130 ) ) ;
memset ( V_116 -> V_127 , 0 , 2 ) ;
V_116 -> V_130 [ 0 ] = V_230 ;
V_116 -> V_130 [ 1 ] = 0x10 ;
V_116 -> V_130 [ 7 ] = V_116 -> V_126 >> 8 ;
V_116 -> V_130 [ 8 ] = V_116 -> V_126 & 0xff ;
V_116 -> V_121 = V_122 ;
return F_83 ( V_3 , V_116 ) ;
}
static int F_155 ( struct V_2 * V_3 , T_6 * V_231 )
{
struct V_115 V_116 ;
int V_61 ;
F_97 ( & V_116 , V_231 , sizeof( * V_231 ) , V_229 ) ;
V_116 . V_130 [ 0 ] = V_232 ;
V_116 . V_130 [ 8 ] = V_116 . V_126 = 2 ;
V_116 . V_134 = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
return V_61 ;
V_116 . V_126 = F_156 ( V_231 -> V_233 ) +
sizeof( V_231 -> V_233 ) ;
if ( V_116 . V_126 > sizeof( T_6 ) )
V_116 . V_126 = sizeof( T_6 ) ;
V_116 . V_130 [ 8 ] = V_116 . V_126 ;
return F_83 ( V_3 , & V_116 ) ;
}
static int F_157 ( struct V_2 * V_3 , T_7 V_234 , T_4 type , T_8 * V_235 )
{
struct V_115 V_116 ;
int V_61 ;
F_97 ( & V_116 , V_235 , 8 , V_229 ) ;
V_116 . V_130 [ 0 ] = V_236 ;
V_116 . V_130 [ 1 ] = type & 3 ;
V_116 . V_130 [ 4 ] = ( V_234 & 0xff00 ) >> 8 ;
V_116 . V_130 [ 5 ] = V_234 & 0xff ;
V_116 . V_130 [ 8 ] = 8 ;
V_116 . V_134 = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
return V_61 ;
V_116 . V_126 = F_156 ( V_235 -> V_237 ) +
sizeof( V_235 -> V_237 ) ;
if ( V_116 . V_126 > sizeof( T_8 ) )
V_116 . V_126 = sizeof( T_8 ) ;
V_116 . V_130 [ 8 ] = V_116 . V_126 ;
return F_83 ( V_3 , & V_116 ) ;
}
static T_5 int F_158 ( struct V_2 * V_3 ,
long * V_238 )
{
T_6 V_231 ;
T_8 V_235 ;
T_9 V_239 ;
int V_61 = - 1 ;
if ( ( V_61 = F_155 ( V_3 , & V_231 ) ) )
return V_61 ;
V_239 = ( V_231 . V_240 << 8 ) | V_231 . V_241 ;
if ( ( V_61 = F_157 ( V_3 , V_239 , 1 , & V_235 ) ) )
return V_61 ;
if ( V_235 . V_242 ) {
V_239 -- ;
if ( ( V_61 = F_157 ( V_3 , V_239 , 1 , & V_235 ) ) )
return V_61 ;
}
if ( V_235 . V_243 ) {
* V_238 = F_159 ( V_235 . V_244 ) ;
} else {
* V_238 = F_159 ( V_235 . V_245 ) +
F_159 ( V_235 . V_246 ) ;
if ( V_235 . V_247 )
* V_238 -= ( F_159 ( V_235 . V_247 ) + 7 ) ;
}
return 0 ;
}
static T_5 int F_160 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
T_10 * V_248 ;
char V_127 [ 128 ] ;
int V_61 , V_6 ;
if ( ( V_3 -> V_249 == 0x1a ) || ( V_3 -> V_249 == 0x12 ) )
return 0 ;
memset ( V_127 , 0 , sizeof( V_127 ) ) ;
F_97 ( & V_116 , V_127 , sizeof( * V_248 ) , V_229 ) ;
V_116 . V_143 = & V_143 ;
if ( ( V_61 = F_153 ( V_3 , & V_116 , V_250 , 0 ) ) ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
V_6 = 2 + ( ( V_127 [ 0 ] << 8 ) | ( V_127 [ 1 ] & 0xff ) ) ;
V_3 -> V_251 = ( V_127 [ 6 ] << 8 ) | ( V_127 [ 7 ] & 0xff ) ;
if ( V_6 > sizeof( V_127 ) )
V_6 = sizeof( V_127 ) ;
F_97 ( & V_116 , V_127 , V_6 , V_229 ) ;
V_116 . V_143 = & V_143 ;
if ( ( V_61 = F_153 ( V_3 , & V_116 , V_250 , 0 ) ) ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
V_248 = ( T_10 * ) & V_127 [ sizeof( struct V_252 ) + V_3 -> V_251 ] ;
V_248 -> V_224 = V_3 -> V_5 . V_224 ;
V_248 -> V_253 = V_3 -> V_5 . V_253 ;
V_248 -> V_254 = V_3 -> V_5 . V_254 ;
V_248 -> V_255 = V_3 -> V_5 . V_225 ;
V_248 -> V_256 = 0 ;
#ifdef F_161
V_248 -> V_257 = 7 ;
V_248 -> V_258 = 1 ;
#endif
if ( V_248 -> V_255 == V_259 ) {
V_248 -> V_260 = 0 ;
V_248 -> V_261 = 0x20 ;
} else if ( V_248 -> V_255 == V_262 ) {
V_248 -> V_260 = 0x20 ;
V_248 -> V_261 = 8 ;
#if 0
wp->mcn[0] = 0x80;
memcpy(&wp->mcn[1], PACKET_MCN, sizeof(wp->mcn) - 1);
#endif
} else {
F_95 ( V_3 , L_62 , V_248 -> V_255 ) ;
return 1 ;
}
V_248 -> V_263 = F_162 ( V_3 -> V_5 . V_6 >> 2 ) ;
V_116 . V_126 = V_116 . V_130 [ 8 ] = V_6 ;
if ( ( V_61 = F_154 ( V_3 , & V_116 ) ) ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
F_151 ( V_3 ) ;
return 0 ;
}
static int F_163 ( struct V_2 * V_3 , T_8 * V_235 )
{
switch ( V_3 -> V_249 ) {
case 0x1a :
case 0x12 :
return 1 ;
default:
break;
}
if ( ! V_235 -> V_264 || ! V_235 -> V_224 )
return 0 ;
if ( V_235 -> V_265 == 0 && V_235 -> V_242 == 0 )
return 1 ;
if ( V_235 -> V_265 == 0 && V_235 -> V_242 == 1 )
return 1 ;
if ( V_235 -> V_265 == 1 && V_235 -> V_242 == 0 )
return 1 ;
F_95 ( V_3 , L_63 , V_235 -> V_265 , V_235 -> V_242 , V_235 -> V_264 ) ;
return 0 ;
}
static int F_164 ( struct V_2 * V_3 , T_6 * V_231 )
{
switch ( V_3 -> V_249 ) {
case 0x0a :
case 0xffff :
break;
case 0x1a :
case 0x13 :
case 0x12 :
return 1 ;
default:
F_56 ( 2 , V_3 , L_64 ,
V_3 -> V_249 ) ;
return 0 ;
}
if ( V_231 -> V_266 == 0xff ) {
F_165 ( V_3 , L_65 ) ;
return 0 ;
}
if ( V_231 -> V_266 != 0x20 && V_231 -> V_266 != 0 ) {
F_95 ( V_3 , L_66 , V_231 -> V_266 ) ;
return 0 ;
}
if ( V_231 -> V_267 == 0 ) {
F_165 ( V_3 , L_67 ) ;
return 0 ;
}
if ( V_231 -> V_268 == V_269 ) {
F_95 ( V_3 , L_68 ) ;
return 0 ;
}
return 1 ;
}
static T_5 int F_166 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
unsigned char V_54 [ 12 ] ;
T_6 V_231 ;
T_8 V_235 ;
int V_61 , V_234 ;
F_97 ( & V_116 , V_54 , sizeof( V_54 ) , V_229 ) ;
V_116 . V_130 [ 0 ] = V_270 ;
V_116 . V_130 [ 8 ] = 8 ;
V_61 = F_83 ( V_3 , & V_116 ) ;
V_3 -> V_249 = V_61 ? 0xffff : V_54 [ 6 ] << 8 | V_54 [ 7 ] ;
memset ( & V_231 , 0 , sizeof( T_6 ) ) ;
memset ( & V_235 , 0 , sizeof( T_8 ) ) ;
if ( ( V_61 = F_155 ( V_3 , & V_231 ) ) ) {
F_95 ( V_3 , L_69 ) ;
return V_61 ;
}
if ( ! F_164 ( V_3 , & V_231 ) )
return - V_271 ;
V_3 -> type = V_231 . V_267 ? V_272 : V_273 ;
V_234 = 1 ;
if ( ( V_61 = F_157 ( V_3 , V_234 , 1 , & V_235 ) ) ) {
F_95 ( V_3 , L_70 ) ;
return V_61 ;
}
if ( ! F_163 ( V_3 , & V_235 ) ) {
F_95 ( V_3 , L_71 ) ;
return - V_271 ;
}
V_3 -> V_5 . V_6 = F_159 ( V_235 . V_274 ) << 2 ;
if ( V_3 -> V_5 . V_6 == 0 ) {
F_165 ( V_3 , L_72 ) ;
return - V_275 ;
}
if ( V_3 -> V_5 . V_6 > V_276 ) {
F_95 ( V_3 , L_73 ) ;
return - V_271 ;
}
V_3 -> V_5 . V_224 = V_235 . V_224 ;
V_3 -> V_4 = ( F_159 ( V_235 . V_245 ) << 2 ) & ( V_3 -> V_5 . V_6 - 1 ) ;
if ( V_235 . V_277 ) {
V_3 -> V_278 = F_159 ( V_235 . V_279 ) ;
F_112 ( V_280 , & V_3 -> V_165 ) ;
}
if ( V_235 . V_243 ) {
V_3 -> V_281 = F_159 ( V_235 . V_244 ) ;
F_112 ( V_282 , & V_3 -> V_165 ) ;
} else {
V_3 -> V_281 = 0xffffffff ;
F_112 ( V_282 , & V_3 -> V_165 ) ;
}
V_3 -> V_5 . V_283 = 7 ;
V_3 -> V_5 . V_254 = 0 ;
V_3 -> V_5 . V_253 = V_235 . V_253 ;
switch ( V_235 . V_284 ) {
case V_285 :
V_3 -> V_5 . V_225 = V_259 ;
break;
case V_286 :
V_3 -> V_5 . V_225 = V_262 ;
break;
default:
F_95 ( V_3 , L_74 ) ;
return - V_271 ;
}
return 0 ;
}
static T_5 int F_167 ( struct V_2 * V_3 ,
int V_287 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
unsigned char V_54 [ 64 ] ;
int V_61 ;
F_97 ( & V_116 , V_54 , sizeof( V_54 ) , V_229 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_126 = V_3 -> V_251 + 12 ;
V_116 . V_134 = 1 ;
if ( ( V_61 = F_153 ( V_3 , & V_116 , V_288 , 0 ) ) )
return V_61 ;
V_54 [ V_3 -> V_251 + 10 ] |= ( ! ! V_287 << 2 ) ;
V_116 . V_126 = V_116 . V_130 [ 8 ] = 2 + ( ( V_54 [ 0 ] << 8 ) | ( V_54 [ 1 ] & 0xff ) ) ;
V_61 = F_154 ( V_3 , & V_116 ) ;
if ( V_61 ) {
F_95 ( V_3 , L_75 ) ;
F_94 ( V_3 , & V_116 ) ;
} else if ( ! V_61 && V_287 )
F_165 ( V_3 , L_76 ) ;
return V_61 ;
}
static int F_168 ( struct V_2 * V_3 , int V_289 )
{
struct V_115 V_116 ;
F_97 ( & V_116 , NULL , 0 , V_147 ) ;
V_116 . V_130 [ 0 ] = V_290 ;
V_116 . V_130 [ 4 ] = V_289 ? 1 : 0 ;
return F_83 ( V_3 , & V_116 ) ;
}
static T_5 int F_169 ( struct V_2 * V_3 ,
unsigned * V_149 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
unsigned char V_54 [ 256 + 18 ] ;
unsigned char * V_291 ;
int V_61 , V_4 ;
V_291 = & V_54 [ sizeof( struct V_252 ) + V_3 -> V_251 ] ;
F_97 ( & V_116 , V_54 , sizeof( V_54 ) , V_292 ) ;
V_116 . V_143 = & V_143 ;
V_61 = F_153 ( V_3 , & V_116 , V_293 , 0 ) ;
if ( V_61 ) {
V_116 . V_126 = V_3 -> V_251 + V_291 [ 1 ] + 2 +
sizeof( struct V_252 ) ;
V_61 = F_153 ( V_3 , & V_116 , V_293 , 0 ) ;
if ( V_61 ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
}
V_4 = 20 ;
if ( V_291 [ 1 ] >= 28 )
V_4 = 28 ;
if ( V_291 [ 1 ] >= 30 ) {
int V_294 = ( V_291 [ 30 ] << 8 ) + V_291 [ 31 ] ;
if ( V_294 > 0 )
V_4 = 34 ;
}
* V_149 = ( V_291 [ V_4 ] << 8 ) | V_291 [ V_4 + 1 ] ;
return 0 ;
}
static T_5 int F_170 ( struct V_2 * V_3 ,
unsigned * V_295 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
unsigned char V_54 [ 64 ] ;
unsigned int V_6 , V_296 , V_297 ;
int V_61 ;
F_97 ( & V_116 , V_54 , 2 , V_229 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_130 [ 0 ] = V_298 ;
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
F_97 ( & V_116 , V_54 , V_6 , V_229 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_130 [ 0 ] = V_298 ;
V_116 . V_130 [ 1 ] = 2 ;
V_116 . V_130 [ 2 ] = 4 ;
V_116 . V_130 [ 8 ] = V_6 ;
V_61 = F_83 ( V_3 , & V_116 ) ;
if ( V_61 ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
if ( ! ( V_54 [ 6 ] & 0x40 ) ) {
F_165 ( V_3 , L_77 ) ;
return 1 ;
}
if ( ! ( V_54 [ 6 ] & 0x4 ) ) {
F_165 ( V_3 , L_78 ) ;
return 1 ;
}
V_296 = ( V_54 [ 6 ] >> 3 ) & 0x7 ;
V_297 = V_54 [ 16 ] & 0xf ;
switch ( V_296 ) {
case 0 :
* V_295 = V_299 [ V_297 ] ;
break;
case 1 :
* V_295 = V_300 [ V_297 ] ;
break;
case 2 :
* V_295 = V_301 [ V_297 ] ;
break;
default:
F_165 ( V_3 , L_79 , V_296 ) ;
return 1 ;
}
if ( * V_295 ) {
F_152 ( V_3 , L_80 , * V_295 ) ;
return 0 ;
} else {
F_165 ( V_3 , L_81 , V_297 , V_296 ) ;
return 1 ;
}
}
static T_5 int F_171 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
int V_61 ;
F_56 ( 2 , V_3 , L_82 ) ;
F_97 ( & V_116 , NULL , 0 , V_147 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_132 = 60 * V_133 ;
V_116 . V_130 [ 0 ] = V_302 ;
V_116 . V_130 [ 1 ] = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
static int F_172 ( struct V_2 * V_3 )
{
int V_61 ;
unsigned int V_149 , V_303 , V_150 ;
if ( ( V_61 = F_166 ( V_3 ) ) ) {
F_56 ( 2 , V_3 , L_83 ) ;
return V_61 ;
}
if ( ( V_61 = F_160 ( V_3 ) ) ) {
F_56 ( 1 , V_3 , L_84 ) ;
return - V_139 ;
}
F_167 ( V_3 , V_304 ) ;
if ( ( V_61 = F_169 ( V_3 , & V_149 ) ) )
V_149 = 16 * 177 ;
switch ( V_3 -> V_249 ) {
case 0x13 :
case 0x1a :
case 0x12 :
F_56 ( 1 , V_3 , L_85 , V_149 ) ;
break;
default:
if ( ( V_61 = F_170 ( V_3 , & V_303 ) ) )
V_303 = 16 ;
V_149 = F_16 ( V_149 , V_303 * 177 ) ;
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
if ( ( V_61 = F_171 ( V_3 ) ) ) {
F_56 ( 1 , V_3 , L_88 ) ;
}
return 0 ;
}
static int F_173 ( struct V_2 * V_3 , T_11 V_305 )
{
int V_61 ;
long V_306 ;
struct V_117 * V_118 ;
F_174 ( V_3 -> V_52 -> V_53 ) ;
if ( ( V_61 = F_175 ( V_3 -> V_52 , V_307 | V_308 , V_3 ) ) )
goto V_128;
if ( ( V_61 = F_158 ( V_3 , & V_306 ) ) ) {
F_95 ( V_3 , L_89 ) ;
goto V_309;
}
F_176 ( V_3 -> V_195 , V_306 << 2 ) ;
F_176 ( V_3 -> V_52 -> V_137 , V_306 << 2 ) ;
F_177 ( V_3 -> V_52 , ( V_310 ) V_306 << 11 ) ;
V_118 = F_84 ( V_3 -> V_52 ) ;
if ( V_305 ) {
if ( ( V_61 = F_172 ( V_3 ) ) )
goto V_309;
F_178 ( V_118 -> V_311 ) ;
F_179 ( V_118 , V_3 -> V_5 . V_6 ) ;
F_180 ( V_118 -> V_311 ) ;
F_112 ( V_312 , & V_3 -> V_165 ) ;
} else {
F_98 ( V_3 , V_162 , V_162 ) ;
F_111 ( V_312 , & V_3 -> V_165 ) ;
}
if ( ( V_61 = F_109 ( V_3 , V_118 ) ) )
goto V_309;
if ( V_305 ) {
if ( ! F_71 ( V_3 , V_313 ) ) {
F_95 ( V_3 , L_90 ) ;
V_61 = - V_62 ;
goto V_309;
}
F_152 ( V_3 , L_91 , V_306 << 1 ) ;
}
return 0 ;
V_309:
F_181 ( V_3 -> V_52 , V_307 | V_308 ) ;
V_128:
return V_61 ;
}
static void F_182 ( struct V_2 * V_3 , int V_314 )
{
if ( V_314 && F_96 ( V_3 ) )
F_56 ( 1 , V_3 , L_92 ) ;
F_168 ( V_3 , 0 ) ;
F_98 ( V_3 , V_162 , V_162 ) ;
F_181 ( V_3 -> V_52 , V_307 | V_308 ) ;
F_67 ( V_3 ) ;
}
static struct V_2 * F_183 ( unsigned int V_315 )
{
if ( V_315 >= V_49 )
return NULL ;
return V_50 [ V_315 ] ;
}
static int F_184 ( struct V_316 * V_52 , T_11 V_317 )
{
struct V_2 * V_3 = NULL ;
int V_61 ;
F_185 ( & V_318 ) ;
F_185 ( & V_47 ) ;
V_3 = F_183 ( F_28 ( V_52 -> V_53 ) ) ;
if ( ! V_3 ) {
V_61 = - V_59 ;
goto V_128;
}
F_53 ( V_3 -> V_319 < 0 ) ;
V_3 -> V_319 ++ ;
if ( V_3 -> V_319 > 1 ) {
if ( ( V_317 & V_320 ) &&
! F_134 ( V_312 , & V_3 -> V_165 ) ) {
V_61 = - V_321 ;
goto V_322;
}
} else {
V_61 = F_173 ( V_3 , V_317 & V_320 ) ;
if ( V_61 )
goto V_322;
F_186 ( V_52 , V_163 ) ;
}
F_29 ( & V_47 ) ;
F_29 ( & V_318 ) ;
return 0 ;
V_322:
V_3 -> V_319 -- ;
V_128:
F_29 ( & V_47 ) ;
F_29 ( & V_318 ) ;
return V_61 ;
}
static void F_187 ( struct V_323 * V_195 , T_11 V_317 )
{
struct V_2 * V_3 = V_195 -> V_324 ;
F_185 ( & V_318 ) ;
F_185 ( & V_47 ) ;
V_3 -> V_319 -- ;
F_53 ( V_3 -> V_319 < 0 ) ;
if ( V_3 -> V_319 == 0 ) {
int V_314 = F_134 ( V_312 , & V_3 -> V_165 ) ;
F_182 ( V_3 , V_314 ) ;
}
F_29 ( & V_47 ) ;
F_29 ( & V_318 ) ;
}
static void F_188 ( struct V_95 * V_95 )
{
struct V_325 * V_326 = V_95 -> V_167 ;
struct V_2 * V_3 = V_326 -> V_3 ;
V_326 -> V_95 -> V_168 = V_95 -> V_168 ;
F_64 ( V_95 ) ;
F_136 ( V_326 -> V_95 ) ;
F_78 ( V_326 , V_327 ) ;
F_52 ( V_3 ) ;
}
static void F_189 ( struct V_2 * V_3 , struct V_95 * V_95 )
{
struct V_95 * V_328 = F_190 ( V_95 , V_329 ) ;
struct V_325 * V_326 = F_191 ( V_327 , V_329 ) ;
V_326 -> V_3 = V_3 ;
V_326 -> V_95 = V_95 ;
V_328 -> V_180 = V_3 -> V_52 ;
V_328 -> V_167 = V_326 ;
V_328 -> V_181 = F_188 ;
V_3 -> V_22 . V_26 += F_192 ( V_95 ) ;
F_99 ( V_3 , V_328 ) ;
}
static void F_193 ( struct V_117 * V_118 , struct V_95 * V_95 )
{
struct V_2 * V_3 = V_118 -> V_330 ;
T_1 V_183 ;
struct V_83 * V_86 ;
int V_331 , V_332 ;
struct V_104 * V_105 ;
V_183 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
F_12 ( & V_3 -> V_78 . V_202 ) ;
V_332 = 0 ;
F_123 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_86 -> V_1 == V_183 ) {
F_12 ( & V_86 -> V_28 ) ;
if ( ( V_86 -> V_185 == V_201 ) ||
( V_86 -> V_185 == V_208 ) ) {
F_101 ( & V_86 -> V_94 , V_95 ) ;
V_86 -> V_194 +=
V_95 -> V_111 . V_160 / V_163 ;
if ( ( V_86 -> V_194 >= V_86 -> V_84 ) &&
( V_86 -> V_185 == V_201 ) ) {
F_107 ( & V_86 -> V_171 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
F_13 ( & V_86 -> V_28 ) ;
F_13 ( & V_3 -> V_78 . V_202 ) ;
return;
} else {
V_332 = 1 ;
}
F_13 ( & V_86 -> V_28 ) ;
}
}
F_13 ( & V_3 -> V_78 . V_202 ) ;
F_12 ( & V_3 -> V_28 ) ;
if ( V_3 -> V_31 > 0
&& V_3 -> V_29 >= V_3 -> V_31 ) {
F_194 ( & V_118 -> V_197 , V_198 ) ;
do {
F_13 ( & V_3 -> V_28 ) ;
F_195 ( V_198 , V_133 ) ;
F_12 ( & V_3 -> V_28 ) ;
} while( V_3 -> V_29 > V_3 -> V_30 );
}
F_13 ( & V_3 -> V_28 ) ;
V_105 = F_191 ( V_3 -> V_108 , V_329 ) ;
V_105 -> V_95 = V_95 ;
F_12 ( & V_3 -> V_28 ) ;
F_53 ( V_3 -> V_29 < 0 ) ;
V_331 = ( V_3 -> V_29 == 0 ) ;
F_80 ( V_3 , V_105 ) ;
F_13 ( & V_3 -> V_28 ) ;
F_57 ( & V_3 -> V_191 , 1 ) ;
if ( V_331 ) {
F_58 ( & V_3 -> V_82 ) ;
} else if ( ! F_68 ( & V_3 -> V_78 . V_100 ) && ! V_332 ) {
F_58 ( & V_3 -> V_82 ) ;
}
}
static T_12 F_196 ( struct V_117 * V_118 , struct V_95 * V_95 )
{
struct V_2 * V_3 ;
char V_333 [ V_334 ] ;
struct V_95 * V_335 ;
F_197 ( V_118 , & V_95 ) ;
F_198 ( V_118 , & V_95 , V_118 -> V_336 ) ;
V_3 = V_118 -> V_330 ;
if ( ! V_3 ) {
F_38 ( L_93 ,
F_199 ( V_95 -> V_180 , V_333 ) ) ;
goto V_337;
}
F_56 ( 2 , V_3 , L_94 ,
( unsigned long long ) V_95 -> V_111 . V_112 ,
( unsigned long long ) F_106 ( V_95 ) ) ;
if ( F_100 ( V_95 ) == V_124 ) {
F_189 ( V_3 , V_95 ) ;
return V_338 ;
}
if ( ! F_134 ( V_312 , & V_3 -> V_165 ) ) {
F_165 ( V_3 , L_95 ,
( unsigned long long ) V_95 -> V_111 . V_112 ) ;
goto V_337;
}
if ( ! V_95 -> V_111 . V_160 || ( V_95 -> V_111 . V_160 % V_163 ) ) {
F_95 ( V_3 , L_96 ) ;
goto V_337;
}
do {
T_1 V_183 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
T_1 V_339 = F_1 ( F_106 ( V_95 ) - 1 , V_3 ) ;
if ( V_339 != V_183 ) {
F_53 ( V_339 != V_183 + V_3 -> V_5 . V_6 ) ;
V_335 = V_336 ( V_95 , V_339 -
V_95 -> V_111 . V_112 ,
V_329 , V_340 ) ;
F_200 ( V_335 , V_95 ) ;
} else {
V_335 = V_95 ;
}
F_193 ( V_118 , V_335 ) ;
} while ( V_335 != V_95 );
return V_338 ;
V_337:
F_201 ( V_95 ) ;
return V_338 ;
}
static void F_202 ( struct V_2 * V_3 )
{
struct V_117 * V_118 = V_3 -> V_195 -> V_196 ;
F_203 ( V_118 , F_196 ) ;
F_204 ( V_118 , V_163 ) ;
F_179 ( V_118 , V_276 ) ;
V_118 -> V_330 = V_3 ;
}
static int F_42 ( struct V_68 * V_69 , void * V_13 )
{
struct V_2 * V_3 = V_69 -> V_341 ;
char * V_342 ;
char V_343 [ V_334 ] ;
int V_212 [ V_213 ] ;
F_205 ( V_69 , L_97 , V_3 -> V_8 ,
F_199 ( V_3 -> V_52 , V_343 ) ) ;
F_205 ( V_69 , L_98 ) ;
F_205 ( V_69 , L_99 , V_3 -> V_5 . V_6 / 2 ) ;
if ( V_3 -> V_5 . V_254 == 0 )
V_342 = L_100 ;
else
V_342 = L_101 ;
F_205 ( V_69 , L_102 , V_342 ) ;
F_205 ( V_69 , L_103 , V_3 -> V_5 . V_224 ? L_60 : L_61 ) ;
F_205 ( V_69 , L_104 , V_3 -> V_5 . V_283 ) ;
F_205 ( V_69 , L_105 , V_3 -> V_5 . V_253 ) ;
if ( V_3 -> V_5 . V_225 == V_259 )
V_342 = L_106 ;
else if ( V_3 -> V_5 . V_225 == V_262 )
V_342 = L_107 ;
else
V_342 = L_101 ;
F_205 ( V_69 , L_108 , V_342 ) ;
F_205 ( V_69 , L_109 ) ;
F_205 ( V_69 , L_110 , V_3 -> V_22 . V_23 ) ;
F_205 ( V_69 , L_111 , V_3 -> V_22 . V_24 ) ;
F_205 ( V_69 , L_112 , V_3 -> V_22 . V_25 >> 1 ) ;
F_205 ( V_69 , L_113 , V_3 -> V_22 . V_27 >> 1 ) ;
F_205 ( V_69 , L_114 , V_3 -> V_22 . V_26 >> 1 ) ;
F_205 ( V_69 , L_115 ) ;
F_205 ( V_69 , L_116 , V_3 -> V_319 ) ;
F_205 ( V_69 , L_117 , V_3 -> V_165 ) ;
F_205 ( V_69 , L_118 , V_3 -> V_150 ) ;
F_205 ( V_69 , L_119 , V_3 -> V_149 ) ;
F_205 ( V_69 , L_120 , V_3 -> V_4 ) ;
F_205 ( V_69 , L_121 , V_3 -> V_251 ) ;
F_205 ( V_69 , L_122 ) ;
F_205 ( V_69 , L_123 , V_3 -> V_29 ) ;
F_205 ( V_69 , L_124 , F_54 ( & V_3 -> V_78 . V_79 ) ) ;
F_205 ( V_69 , L_125 , ( unsigned long long ) V_3 -> V_192 ) ;
F_140 ( V_3 , V_212 ) ;
F_205 ( V_69 , L_126 ,
V_212 [ 0 ] , V_212 [ 1 ] , V_212 [ 2 ] , V_212 [ 3 ] , V_212 [ 4 ] , V_212 [ 5 ] ) ;
F_205 ( V_69 , L_127 ,
V_3 -> V_30 ,
V_3 -> V_31 ) ;
return 0 ;
}
static int F_206 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
return F_44 ( V_71 , F_42 , F_207 ( V_70 ) ) ;
}
static int F_208 ( struct V_2 * V_3 , T_13 V_37 )
{
int V_85 ;
int V_61 = 0 ;
char V_333 [ V_334 ] ;
struct V_316 * V_52 ;
if ( V_3 -> V_51 == V_37 ) {
F_95 ( V_3 , L_128 ) ;
return - V_321 ;
}
for ( V_85 = 0 ; V_85 < V_49 ; V_85 ++ ) {
struct V_2 * V_344 = V_50 [ V_85 ] ;
if ( ! V_344 )
continue;
if ( V_344 -> V_52 -> V_53 == V_37 ) {
F_95 ( V_3 , L_129 ,
F_199 ( V_344 -> V_52 , V_333 ) ) ;
return - V_321 ;
}
if ( V_344 -> V_51 == V_37 ) {
F_95 ( V_3 , L_130 ) ;
return - V_321 ;
}
}
V_52 = F_174 ( V_37 ) ;
if ( ! V_52 )
return - V_62 ;
V_61 = F_175 ( V_52 , V_307 | V_345 , NULL ) ;
if ( V_61 )
return V_61 ;
F_209 ( V_58 ) ;
V_3 -> V_52 = V_52 ;
F_186 ( V_52 , V_163 ) ;
F_202 ( V_3 ) ;
F_57 ( & V_3 -> V_78 . V_79 , 0 ) ;
V_3 -> V_78 . V_346 = F_210 ( F_141 , V_3 , L_1 , V_3 -> V_8 ) ;
if ( F_21 ( V_3 -> V_78 . V_346 ) ) {
F_95 ( V_3 , L_131 ) ;
V_61 = - V_62 ;
goto V_347;
}
F_211 ( V_3 -> V_8 , 0 , V_348 , & V_349 , V_3 ) ;
F_56 ( 1 , V_3 , L_132 , F_199 ( V_52 , V_333 ) ) ;
return 0 ;
V_347:
F_181 ( V_52 , V_307 | V_345 ) ;
F_33 ( V_58 ) ;
return V_61 ;
}
static int F_212 ( struct V_316 * V_52 , T_11 V_317 , unsigned int V_130 , unsigned long V_350 )
{
struct V_2 * V_3 = V_52 -> V_137 -> V_324 ;
int V_61 ;
F_56 ( 2 , V_3 , L_133 ,
V_130 , F_27 ( V_52 -> V_53 ) , F_28 ( V_52 -> V_53 ) ) ;
F_185 ( & V_318 ) ;
switch ( V_130 ) {
case V_351 :
if ( V_3 -> V_319 == 1 )
F_168 ( V_3 , 0 ) ;
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
V_61 = F_213 ( V_3 -> V_52 , V_317 , V_130 , V_350 ) ;
break;
default:
F_56 ( 2 , V_3 , L_134 , V_130 ) ;
V_61 = - V_357 ;
}
F_29 ( & V_318 ) ;
return V_61 ;
}
static unsigned int F_214 ( struct V_323 * V_195 ,
unsigned int V_358 )
{
struct V_2 * V_3 = V_195 -> V_324 ;
struct V_323 * V_359 ;
if ( ! V_3 )
return 0 ;
if ( ! V_3 -> V_52 )
return 0 ;
V_359 = V_3 -> V_52 -> V_137 ;
if ( ! V_359 || ! V_359 -> V_360 -> V_361 )
return 0 ;
return V_359 -> V_360 -> V_361 ( V_359 , V_358 ) ;
}
static char * F_215 ( struct V_323 * V_362 , T_14 * V_317 )
{
return F_216 ( V_14 , L_135 , V_362 -> V_363 ) ;
}
static int F_32 ( T_13 V_37 , T_13 * V_51 )
{
int V_46 ;
int V_61 = - V_62 ;
struct V_2 * V_3 ;
struct V_323 * V_195 ;
F_26 ( & V_47 , V_48 ) ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ )
if ( ! V_50 [ V_46 ] )
break;
if ( V_46 == V_49 ) {
F_38 ( L_136 , V_49 ) ;
V_61 = - V_321 ;
goto V_364;
}
V_3 = F_3 ( sizeof( struct V_2 ) , V_14 ) ;
if ( ! V_3 )
goto V_364;
V_3 -> V_108 = F_217 ( V_365 ,
sizeof( struct V_104 ) ) ;
if ( ! V_3 -> V_108 )
goto V_347;
F_70 ( & V_3 -> V_78 . V_100 ) ;
F_70 ( & V_3 -> V_78 . V_99 ) ;
F_62 ( & V_3 -> V_78 . V_202 ) ;
F_62 ( & V_3 -> V_28 ) ;
F_62 ( & V_3 -> V_80 . V_28 ) ;
F_63 ( & V_3 -> V_80 . V_152 ) ;
F_63 ( & V_3 -> V_80 . V_153 ) ;
sprintf ( V_3 -> V_8 , V_63 L_13 , V_46 ) ;
F_218 ( & V_3 -> V_82 ) ;
V_3 -> V_107 = V_366 ;
V_3 -> V_31 = V_31 ;
V_3 -> V_30 = V_30 ;
V_195 = F_219 ( 1 ) ;
if ( ! V_195 )
goto V_347;
V_3 -> V_195 = V_195 ;
V_195 -> V_56 = V_367 ;
V_195 -> V_368 = V_46 ;
V_195 -> V_360 = & V_369 ;
V_195 -> V_165 = V_370 ;
strcpy ( V_195 -> V_363 , V_3 -> V_8 ) ;
V_195 -> V_371 = F_215 ;
V_195 -> V_324 = V_3 ;
V_195 -> V_196 = F_220 ( V_14 ) ;
if ( ! V_195 -> V_196 )
goto V_372;
V_3 -> V_51 = F_20 ( V_367 , V_46 ) ;
V_61 = F_208 ( V_3 , V_37 ) ;
if ( V_61 )
goto V_373;
V_195 -> V_374 = V_3 -> V_52 -> V_137 -> V_374 ;
V_195 -> V_375 = V_3 -> V_52 -> V_137 -> V_375 ;
F_221 ( V_195 ) ;
F_18 ( V_3 ) ;
F_45 ( V_3 ) ;
V_50 [ V_46 ] = V_3 ;
if ( V_51 )
* V_51 = V_3 -> V_51 ;
F_29 ( & V_47 ) ;
return 0 ;
V_373:
F_222 ( V_195 -> V_196 ) ;
V_372:
F_223 ( V_195 ) ;
V_347:
F_224 ( V_3 -> V_108 ) ;
F_9 ( V_3 ) ;
V_364:
F_29 ( & V_47 ) ;
F_38 ( L_137 ) ;
return V_61 ;
}
static int F_35 ( T_13 V_51 )
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
F_225 ( L_138 ) ;
V_61 = - V_275 ;
goto V_128;
}
if ( V_3 -> V_319 > 0 ) {
V_61 = - V_321 ;
goto V_128;
}
if ( ! F_21 ( V_3 -> V_78 . V_346 ) )
F_226 ( V_3 -> V_78 . V_346 ) ;
V_50 [ V_46 ] = NULL ;
F_48 ( V_3 ) ;
F_22 ( V_3 ) ;
F_181 ( V_3 -> V_52 , V_307 | V_345 ) ;
F_227 ( V_3 -> V_8 , V_348 ) ;
F_56 ( 1 , V_3 , L_139 ) ;
F_228 ( V_3 -> V_195 ) ;
F_222 ( V_3 -> V_195 -> V_196 ) ;
F_223 ( V_3 -> V_195 ) ;
F_224 ( V_3 -> V_108 ) ;
F_9 ( V_3 ) ;
F_33 ( V_58 ) ;
V_128:
F_29 ( & V_47 ) ;
return V_61 ;
}
static void F_229 ( struct V_376 * V_377 )
{
struct V_2 * V_3 ;
F_26 ( & V_47 , V_48 ) ;
V_3 = F_183 ( V_377 -> V_378 ) ;
if ( V_3 ) {
V_377 -> V_37 = F_230 ( V_3 -> V_52 -> V_53 ) ;
V_377 -> V_51 = F_230 ( V_3 -> V_51 ) ;
} else {
V_377 -> V_37 = 0 ;
V_377 -> V_51 = 0 ;
}
V_377 -> V_379 = V_49 ;
F_29 ( & V_47 ) ;
}
static long F_231 ( struct V_71 * V_71 , unsigned int V_130 , unsigned long V_350 )
{
void T_15 * V_380 = ( void T_15 * ) V_350 ;
struct V_376 V_377 ;
int V_61 = 0 ;
T_13 V_51 = 0 ;
if ( V_130 != V_381 )
return - V_357 ;
if ( F_232 ( & V_377 , V_380 , sizeof( struct V_376 ) ) )
return - V_382 ;
switch ( V_377 . V_383 ) {
case V_384 :
if ( ! F_233 ( V_385 ) )
return - V_386 ;
V_61 = F_32 ( F_234 ( V_377 . V_37 ) , & V_51 ) ;
V_377 . V_51 = F_230 ( V_51 ) ;
break;
case V_387 :
if ( ! F_233 ( V_385 ) )
return - V_386 ;
V_61 = F_35 ( F_234 ( V_377 . V_51 ) ) ;
break;
case V_388 :
F_229 ( & V_377 ) ;
break;
default:
return - V_357 ;
}
if ( F_235 ( V_380 , & V_377 , sizeof( struct V_376 ) ) )
return - V_382 ;
return V_61 ;
}
static long F_236 ( struct V_71 * V_71 , unsigned int V_130 , unsigned long V_350 )
{
return F_231 ( V_71 , V_130 , ( unsigned long ) F_237 ( V_350 ) ) ;
}
static int T_16 F_238 ( void )
{
int V_61 ;
F_239 ( & V_47 ) ;
V_327 = F_217 ( V_389 ,
sizeof( struct V_325 ) ) ;
if ( ! V_327 )
return - V_62 ;
V_61 = F_240 ( V_367 , V_63 ) ;
if ( V_61 < 0 ) {
F_38 ( L_140 ) ;
goto V_390;
}
if ( ! V_367 )
V_367 = V_61 ;
V_61 = F_36 () ;
if ( V_61 )
goto V_128;
F_50 () ;
V_61 = F_241 ( & V_391 ) ;
if ( V_61 ) {
F_38 ( L_141 ) ;
goto V_392;
}
V_348 = F_242 ( L_142 V_63 , NULL ) ;
return 0 ;
V_392:
F_51 () ;
F_39 () ;
V_128:
F_243 ( V_367 , V_63 ) ;
V_390:
F_224 ( V_327 ) ;
return V_61 ;
}
static void T_17 F_244 ( void )
{
F_227 ( L_142 V_63 , NULL ) ;
F_245 ( & V_391 ) ;
F_51 () ;
F_39 () ;
F_243 ( V_367 , V_63 ) ;
F_224 ( V_327 ) ;
}
