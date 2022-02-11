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
static void F_117 ( struct V_95 * V_95 )
{
struct V_83 * V_86 = V_95 -> V_175 ;
struct V_2 * V_3 = V_86 -> V_3 ;
F_53 ( ! V_3 ) ;
F_56 ( 2 , V_3 , L_36 ,
V_95 , ( unsigned long long ) V_86 -> V_1 ,
( unsigned long long ) V_95 -> V_111 . V_112 , V_95 -> V_176 ) ;
if ( V_95 -> V_176 )
F_107 ( & V_86 -> V_177 ) ;
if ( F_55 ( & V_86 -> V_178 ) ) {
F_107 ( & V_86 -> V_179 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
F_52 ( V_3 ) ;
}
static void F_118 ( struct V_95 * V_95 )
{
struct V_83 * V_86 = V_95 -> V_175 ;
struct V_2 * V_3 = V_86 -> V_3 ;
F_53 ( ! V_3 ) ;
F_56 ( 2 , V_3 , L_37 , V_86 -> V_102 , V_95 -> V_176 ) ;
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
V_95 -> V_175 = V_86 ;
V_13 = ( V_169 * V_163 ) / V_166 ;
V_4 = ( V_169 * V_163 ) % V_166 ;
F_56 ( 2 , V_3 , L_39 ,
V_169 , V_86 -> V_91 [ V_13 ] , V_4 ) ;
if ( ! F_123 ( V_95 , V_86 -> V_91 [ V_13 ] , V_163 , V_4 ) )
F_124 () ;
F_107 ( & V_86 -> V_178 ) ;
F_125 ( V_95 , V_189 , 0 ) ;
F_99 ( V_3 , V_95 ) ;
V_180 ++ ;
}
V_186:
F_56 ( 2 , V_3 , L_40 ,
V_180 , ( unsigned long long ) V_86 -> V_1 ) ;
V_3 -> V_22 . V_23 ++ ;
V_3 -> V_22 . V_27 += V_180 * ( V_163 >> 9 ) ;
}
static struct V_83 * F_126 ( struct V_2 * V_3 , int V_190 )
{
struct V_83 * V_86 ;
F_127 (pkt, &pd->cdrw.pkt_free_list, list) {
if ( V_86 -> V_1 == V_190 || V_86 -> V_103 . V_98 == & V_3 -> V_78 . V_100 ) {
F_128 ( & V_86 -> V_103 ) ;
if ( V_86 -> V_1 != V_190 )
V_86 -> V_185 = 0 ;
return V_86 ;
}
}
F_124 () ;
return NULL ;
}
static void F_129 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
if ( V_86 -> V_185 ) {
F_72 ( & V_86 -> V_103 , & V_3 -> V_78 . V_100 ) ;
} else {
F_130 ( & V_86 -> V_103 , & V_3 -> V_78 . V_100 ) ;
}
}
static int F_131 ( struct V_83 * V_86 )
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
static inline void F_132 ( struct V_83 * V_86 , enum V_191 V_192 )
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
static int F_133 ( struct V_2 * V_3 )
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
V_20 = F_134 ( & V_3 -> V_107 ) ;
if ( V_20 )
V_196 = F_75 ( V_20 , struct V_104 , V_106 ) ;
}
V_105 = V_196 ;
while ( V_105 ) {
V_95 = V_105 -> V_95 ;
V_190 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
F_127 (p, &pd->cdrw.pkt_active_list, list) {
if ( V_13 -> V_1 == V_190 ) {
V_95 = NULL ;
goto V_200;
}
}
break;
V_200:
V_105 = F_73 ( V_105 ) ;
if ( ! V_105 ) {
V_20 = F_134 ( & V_3 -> V_107 ) ;
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
V_86 = F_126 ( V_3 , V_190 ) ;
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
F_135 ( & V_3 -> V_202 -> V_203 -> V_204 ,
V_205 ) ;
}
V_86 -> V_206 = F_15 ( V_207 , 1 ) ;
F_132 ( V_86 , V_208 ) ;
F_57 ( & V_86 -> V_179 , 1 ) ;
F_12 ( & V_3 -> V_78 . V_209 ) ;
F_72 ( & V_86 -> V_103 , & V_3 -> V_78 . V_99 ) ;
F_13 ( & V_3 -> V_78 . V_209 ) ;
return 1 ;
}
static void F_136 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
int V_169 ;
struct V_167 * V_168 = V_86 -> V_88 -> V_210 ;
F_122 ( V_86 -> V_88 ) ;
V_86 -> V_88 -> V_111 . V_112 = V_86 -> V_1 ;
V_86 -> V_88 -> V_187 = V_3 -> V_52 ;
V_86 -> V_88 -> V_188 = F_118 ;
V_86 -> V_88 -> V_175 = V_86 ;
for ( V_169 = 0 ; V_169 < V_86 -> V_84 ; V_169 ++ ) {
V_168 [ V_169 ] . V_171 = V_86 -> V_91 [ ( V_169 * V_163 ) / V_166 ] ;
V_168 [ V_169 ] . V_173 = ( V_169 * V_163 ) % V_166 ;
if ( ! F_123 ( V_86 -> V_88 , V_168 [ V_169 ] . V_171 , V_163 , V_168 [ V_169 ] . V_173 ) )
F_124 () ;
}
F_56 ( 2 , V_3 , L_52 , V_86 -> V_88 -> V_211 ) ;
F_12 ( & V_86 -> V_28 ) ;
F_137 ( V_86 -> V_88 , V_86 -> V_94 . V_212 ) ;
F_132 ( V_86 , V_213 ) ;
F_13 ( & V_86 -> V_28 ) ;
F_56 ( 2 , V_3 , L_53 ,
V_86 -> V_201 , ( unsigned long long ) V_86 -> V_1 ) ;
if ( F_138 ( V_164 , & V_3 -> V_165 ) || ( V_86 -> V_201 < V_86 -> V_84 ) ) {
F_113 ( V_86 , V_168 ) ;
V_86 -> V_185 = 1 ;
} else {
V_86 -> V_185 = 0 ;
}
F_57 ( & V_86 -> V_178 , 1 ) ;
F_125 ( V_86 -> V_88 , V_214 , 0 ) ;
F_99 ( V_3 , V_86 -> V_88 ) ;
}
static void F_139 ( struct V_83 * V_86 , int error )
{
struct V_95 * V_95 ;
if ( error )
V_86 -> V_185 = 0 ;
while ( ( V_95 = F_105 ( & V_86 -> V_94 ) ) ) {
V_95 -> V_176 = error ;
F_140 ( V_95 ) ;
}
}
static void F_141 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
F_56 ( 2 , V_3 , L_54 , V_86 -> V_102 ) ;
for (; ; ) {
switch ( V_86 -> V_192 ) {
case V_208 :
if ( ( V_86 -> V_201 < V_86 -> V_84 ) && ( V_86 -> V_206 > 0 ) )
return;
V_86 -> V_206 = 0 ;
F_120 ( V_3 , V_86 ) ;
F_132 ( V_86 , V_215 ) ;
break;
case V_215 :
if ( F_54 ( & V_86 -> V_178 ) > 0 )
return;
if ( F_54 ( & V_86 -> V_177 ) > 0 ) {
F_132 ( V_86 , V_216 ) ;
} else {
F_136 ( V_3 , V_86 ) ;
}
break;
case V_213 :
if ( F_54 ( & V_86 -> V_178 ) > 0 )
return;
if ( ! V_86 -> V_88 -> V_176 ) {
F_132 ( V_86 , V_217 ) ;
} else {
F_132 ( V_86 , V_216 ) ;
}
break;
case V_216 :
if ( F_131 ( V_86 ) ) {
F_136 ( V_3 , V_86 ) ;
} else {
F_56 ( 2 , V_3 , L_55 ) ;
F_132 ( V_86 , V_217 ) ;
}
break;
case V_217 :
F_139 ( V_86 , V_86 -> V_88 -> V_176 ) ;
return;
default:
F_124 () ;
break;
}
}
}
static void F_142 ( struct V_2 * V_3 )
{
struct V_83 * V_86 , * V_98 ;
F_127 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_54 ( & V_86 -> V_179 ) > 0 ) {
F_57 ( & V_86 -> V_179 , 0 ) ;
F_141 ( V_3 , V_86 ) ;
}
}
F_12 ( & V_3 -> V_78 . V_209 ) ;
F_69 (pkt, next, &pd->cdrw.pkt_active_list, list) {
if ( V_86 -> V_192 == V_217 ) {
F_143 ( & V_86 -> V_103 ) ;
F_129 ( V_3 , V_86 ) ;
F_132 ( V_86 , V_218 ) ;
F_57 ( & V_3 -> V_198 , 1 ) ;
}
}
F_13 ( & V_3 -> V_78 . V_209 ) ;
}
static void F_144 ( struct V_2 * V_3 , int * V_219 )
{
struct V_83 * V_86 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_220 ; V_85 ++ )
V_219 [ V_85 ] = 0 ;
F_12 ( & V_3 -> V_78 . V_209 ) ;
F_127 (pkt, &pd->cdrw.pkt_active_list, list) {
V_219 [ V_86 -> V_192 ] ++ ;
}
F_13 ( & V_3 -> V_78 . V_209 ) ;
}
static int F_145 ( void * V_221 )
{
struct V_2 * V_3 = V_221 ;
struct V_83 * V_86 ;
long V_222 , V_223 ;
F_146 ( V_224 , V_225 ) ;
F_147 () ;
for (; ; ) {
F_148 ( V_226 , V_224 ) ;
F_149 ( & V_3 -> V_82 , & V_226 ) ;
for (; ; ) {
F_150 ( V_227 ) ;
if ( F_54 ( & V_3 -> V_198 ) > 0 )
goto V_228;
F_127 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_54 ( & V_86 -> V_179 ) > 0 )
goto V_228;
}
if ( F_54 ( & V_3 -> V_80 . V_81 ) != 0 )
goto V_228;
if ( V_193 > 1 ) {
int V_219 [ V_220 ] ;
F_144 ( V_3 , V_219 ) ;
F_56 ( 2 , V_3 , L_56 ,
V_219 [ 0 ] , V_219 [ 1 ] , V_219 [ 2 ] ,
V_219 [ 3 ] , V_219 [ 4 ] , V_219 [ 5 ] ) ;
}
V_222 = V_229 ;
F_127 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_86 -> V_206 && V_86 -> V_206 < V_222 )
V_222 = V_86 -> V_206 ;
}
F_56 ( 2 , V_3 , L_57 ) ;
V_223 = F_151 ( V_222 ) ;
F_56 ( 2 , V_3 , L_58 ) ;
F_152 () ;
F_127 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( ! V_86 -> V_206 )
continue;
V_86 -> V_206 -= V_222 - V_223 ;
if ( V_86 -> V_206 <= 0 ) {
V_86 -> V_206 = 0 ;
F_107 ( & V_86 -> V_179 ) ;
}
}
if ( F_153 () )
break;
}
V_228:
F_150 ( V_230 ) ;
F_154 ( & V_3 -> V_82 , & V_226 ) ;
if ( F_153 () )
break;
while ( F_133 ( V_3 ) )
;
F_142 ( V_3 ) ;
F_102 ( V_3 ) ;
}
return 0 ;
}
static void F_155 ( struct V_2 * V_3 )
{
F_156 ( V_3 , L_59 ,
V_3 -> V_5 . V_231 ? L_60 : L_61 ,
V_3 -> V_5 . V_6 >> 2 ,
V_3 -> V_5 . V_232 == 8 ? '1' : '2' ) ;
}
static int F_157 ( struct V_2 * V_3 , struct V_115 * V_116 , int V_233 , int V_234 )
{
memset ( V_116 -> V_130 , 0 , sizeof( V_116 -> V_130 ) ) ;
V_116 -> V_130 [ 0 ] = V_235 ;
V_116 -> V_130 [ 2 ] = V_233 | ( V_234 << 6 ) ;
V_116 -> V_130 [ 7 ] = V_116 -> V_126 >> 8 ;
V_116 -> V_130 [ 8 ] = V_116 -> V_126 & 0xff ;
V_116 -> V_121 = V_236 ;
return F_83 ( V_3 , V_116 ) ;
}
static int F_158 ( struct V_2 * V_3 , struct V_115 * V_116 )
{
memset ( V_116 -> V_130 , 0 , sizeof( V_116 -> V_130 ) ) ;
memset ( V_116 -> V_127 , 0 , 2 ) ;
V_116 -> V_130 [ 0 ] = V_237 ;
V_116 -> V_130 [ 1 ] = 0x10 ;
V_116 -> V_130 [ 7 ] = V_116 -> V_126 >> 8 ;
V_116 -> V_130 [ 8 ] = V_116 -> V_126 & 0xff ;
V_116 -> V_121 = V_122 ;
return F_83 ( V_3 , V_116 ) ;
}
static int F_159 ( struct V_2 * V_3 , T_6 * V_238 )
{
struct V_115 V_116 ;
int V_61 ;
F_97 ( & V_116 , V_238 , sizeof( * V_238 ) , V_236 ) ;
V_116 . V_130 [ 0 ] = V_239 ;
V_116 . V_130 [ 8 ] = V_116 . V_126 = 2 ;
V_116 . V_134 = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
return V_61 ;
V_116 . V_126 = F_160 ( V_238 -> V_240 ) +
sizeof( V_238 -> V_240 ) ;
if ( V_116 . V_126 > sizeof( T_6 ) )
V_116 . V_126 = sizeof( T_6 ) ;
V_116 . V_130 [ 8 ] = V_116 . V_126 ;
return F_83 ( V_3 , & V_116 ) ;
}
static int F_161 ( struct V_2 * V_3 , T_7 V_241 , T_4 type , T_8 * V_242 )
{
struct V_115 V_116 ;
int V_61 ;
F_97 ( & V_116 , V_242 , 8 , V_236 ) ;
V_116 . V_130 [ 0 ] = V_243 ;
V_116 . V_130 [ 1 ] = type & 3 ;
V_116 . V_130 [ 4 ] = ( V_241 & 0xff00 ) >> 8 ;
V_116 . V_130 [ 5 ] = V_241 & 0xff ;
V_116 . V_130 [ 8 ] = 8 ;
V_116 . V_134 = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
return V_61 ;
V_116 . V_126 = F_160 ( V_242 -> V_244 ) +
sizeof( V_242 -> V_244 ) ;
if ( V_116 . V_126 > sizeof( T_8 ) )
V_116 . V_126 = sizeof( T_8 ) ;
V_116 . V_130 [ 8 ] = V_116 . V_126 ;
return F_83 ( V_3 , & V_116 ) ;
}
static T_5 int F_162 ( struct V_2 * V_3 ,
long * V_245 )
{
T_6 V_238 ;
T_8 V_242 ;
T_9 V_246 ;
int V_61 = - 1 ;
if ( ( V_61 = F_159 ( V_3 , & V_238 ) ) )
return V_61 ;
V_246 = ( V_238 . V_247 << 8 ) | V_238 . V_248 ;
if ( ( V_61 = F_161 ( V_3 , V_246 , 1 , & V_242 ) ) )
return V_61 ;
if ( V_242 . V_249 ) {
V_246 -- ;
if ( ( V_61 = F_161 ( V_3 , V_246 , 1 , & V_242 ) ) )
return V_61 ;
}
if ( V_242 . V_250 ) {
* V_245 = F_163 ( V_242 . V_251 ) ;
} else {
* V_245 = F_163 ( V_242 . V_252 ) +
F_163 ( V_242 . V_253 ) ;
if ( V_242 . V_254 )
* V_245 -= ( F_163 ( V_242 . V_254 ) + 7 ) ;
}
return 0 ;
}
static T_5 int F_164 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
T_10 * V_255 ;
char V_127 [ 128 ] ;
int V_61 , V_6 ;
if ( ( V_3 -> V_256 == 0x1a ) || ( V_3 -> V_256 == 0x12 ) )
return 0 ;
memset ( V_127 , 0 , sizeof( V_127 ) ) ;
F_97 ( & V_116 , V_127 , sizeof( * V_255 ) , V_236 ) ;
V_116 . V_143 = & V_143 ;
if ( ( V_61 = F_157 ( V_3 , & V_116 , V_257 , 0 ) ) ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
V_6 = 2 + ( ( V_127 [ 0 ] << 8 ) | ( V_127 [ 1 ] & 0xff ) ) ;
V_3 -> V_258 = ( V_127 [ 6 ] << 8 ) | ( V_127 [ 7 ] & 0xff ) ;
if ( V_6 > sizeof( V_127 ) )
V_6 = sizeof( V_127 ) ;
F_97 ( & V_116 , V_127 , V_6 , V_236 ) ;
V_116 . V_143 = & V_143 ;
if ( ( V_61 = F_157 ( V_3 , & V_116 , V_257 , 0 ) ) ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
V_255 = ( T_10 * ) & V_127 [ sizeof( struct V_259 ) + V_3 -> V_258 ] ;
V_255 -> V_231 = V_3 -> V_5 . V_231 ;
V_255 -> V_260 = V_3 -> V_5 . V_260 ;
V_255 -> V_261 = V_3 -> V_5 . V_261 ;
V_255 -> V_262 = V_3 -> V_5 . V_232 ;
V_255 -> V_263 = 0 ;
#ifdef F_165
V_255 -> V_264 = 7 ;
V_255 -> V_265 = 1 ;
#endif
if ( V_255 -> V_262 == V_266 ) {
V_255 -> V_267 = 0 ;
V_255 -> V_268 = 0x20 ;
} else if ( V_255 -> V_262 == V_269 ) {
V_255 -> V_267 = 0x20 ;
V_255 -> V_268 = 8 ;
#if 0
wp->mcn[0] = 0x80;
memcpy(&wp->mcn[1], PACKET_MCN, sizeof(wp->mcn) - 1);
#endif
} else {
F_95 ( V_3 , L_62 , V_255 -> V_262 ) ;
return 1 ;
}
V_255 -> V_270 = F_166 ( V_3 -> V_5 . V_6 >> 2 ) ;
V_116 . V_126 = V_116 . V_130 [ 8 ] = V_6 ;
if ( ( V_61 = F_158 ( V_3 , & V_116 ) ) ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
F_155 ( V_3 ) ;
return 0 ;
}
static int F_167 ( struct V_2 * V_3 , T_8 * V_242 )
{
switch ( V_3 -> V_256 ) {
case 0x1a :
case 0x12 :
return 1 ;
default:
break;
}
if ( ! V_242 -> V_271 || ! V_242 -> V_231 )
return 0 ;
if ( V_242 -> V_272 == 0 && V_242 -> V_249 == 0 )
return 1 ;
if ( V_242 -> V_272 == 0 && V_242 -> V_249 == 1 )
return 1 ;
if ( V_242 -> V_272 == 1 && V_242 -> V_249 == 0 )
return 1 ;
F_95 ( V_3 , L_63 , V_242 -> V_272 , V_242 -> V_249 , V_242 -> V_271 ) ;
return 0 ;
}
static int F_168 ( struct V_2 * V_3 , T_6 * V_238 )
{
switch ( V_3 -> V_256 ) {
case 0x0a :
case 0xffff :
break;
case 0x1a :
case 0x13 :
case 0x12 :
return 1 ;
default:
F_56 ( 2 , V_3 , L_64 ,
V_3 -> V_256 ) ;
return 0 ;
}
if ( V_238 -> V_273 == 0xff ) {
F_169 ( V_3 , L_65 ) ;
return 0 ;
}
if ( V_238 -> V_273 != 0x20 && V_238 -> V_273 != 0 ) {
F_95 ( V_3 , L_66 , V_238 -> V_273 ) ;
return 0 ;
}
if ( V_238 -> V_274 == 0 ) {
F_169 ( V_3 , L_67 ) ;
return 0 ;
}
if ( V_238 -> V_275 == V_276 ) {
F_95 ( V_3 , L_68 ) ;
return 0 ;
}
return 1 ;
}
static T_5 int F_170 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
unsigned char V_54 [ 12 ] ;
T_6 V_238 ;
T_8 V_242 ;
int V_61 , V_241 ;
F_97 ( & V_116 , V_54 , sizeof( V_54 ) , V_236 ) ;
V_116 . V_130 [ 0 ] = V_277 ;
V_116 . V_130 [ 8 ] = 8 ;
V_61 = F_83 ( V_3 , & V_116 ) ;
V_3 -> V_256 = V_61 ? 0xffff : V_54 [ 6 ] << 8 | V_54 [ 7 ] ;
memset ( & V_238 , 0 , sizeof( T_6 ) ) ;
memset ( & V_242 , 0 , sizeof( T_8 ) ) ;
if ( ( V_61 = F_159 ( V_3 , & V_238 ) ) ) {
F_95 ( V_3 , L_69 ) ;
return V_61 ;
}
if ( ! F_168 ( V_3 , & V_238 ) )
return - V_278 ;
V_3 -> type = V_238 . V_274 ? V_279 : V_280 ;
V_241 = 1 ;
if ( ( V_61 = F_161 ( V_3 , V_241 , 1 , & V_242 ) ) ) {
F_95 ( V_3 , L_70 ) ;
return V_61 ;
}
if ( ! F_167 ( V_3 , & V_242 ) ) {
F_95 ( V_3 , L_71 ) ;
return - V_278 ;
}
V_3 -> V_5 . V_6 = F_163 ( V_242 . V_281 ) << 2 ;
if ( V_3 -> V_5 . V_6 == 0 ) {
F_169 ( V_3 , L_72 ) ;
return - V_282 ;
}
if ( V_3 -> V_5 . V_6 > V_283 ) {
F_95 ( V_3 , L_73 ) ;
return - V_278 ;
}
V_3 -> V_5 . V_231 = V_242 . V_231 ;
V_3 -> V_4 = ( F_163 ( V_242 . V_252 ) << 2 ) & ( V_3 -> V_5 . V_6 - 1 ) ;
if ( V_242 . V_284 ) {
V_3 -> V_285 = F_163 ( V_242 . V_286 ) ;
F_112 ( V_287 , & V_3 -> V_165 ) ;
}
if ( V_242 . V_250 ) {
V_3 -> V_288 = F_163 ( V_242 . V_251 ) ;
F_112 ( V_289 , & V_3 -> V_165 ) ;
} else {
V_3 -> V_288 = 0xffffffff ;
F_112 ( V_289 , & V_3 -> V_165 ) ;
}
V_3 -> V_5 . V_290 = 7 ;
V_3 -> V_5 . V_261 = 0 ;
V_3 -> V_5 . V_260 = V_242 . V_260 ;
switch ( V_242 . V_291 ) {
case V_292 :
V_3 -> V_5 . V_232 = V_266 ;
break;
case V_293 :
V_3 -> V_5 . V_232 = V_269 ;
break;
default:
F_95 ( V_3 , L_74 ) ;
return - V_278 ;
}
return 0 ;
}
static T_5 int F_171 ( struct V_2 * V_3 ,
int V_294 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
unsigned char V_54 [ 64 ] ;
int V_61 ;
F_97 ( & V_116 , V_54 , sizeof( V_54 ) , V_236 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_126 = V_3 -> V_258 + 12 ;
V_116 . V_134 = 1 ;
if ( ( V_61 = F_157 ( V_3 , & V_116 , V_295 , 0 ) ) )
return V_61 ;
V_54 [ V_3 -> V_258 + 10 ] |= ( ! ! V_294 << 2 ) ;
V_116 . V_126 = V_116 . V_130 [ 8 ] = 2 + ( ( V_54 [ 0 ] << 8 ) | ( V_54 [ 1 ] & 0xff ) ) ;
V_61 = F_158 ( V_3 , & V_116 ) ;
if ( V_61 ) {
F_95 ( V_3 , L_75 ) ;
F_94 ( V_3 , & V_116 ) ;
} else if ( ! V_61 && V_294 )
F_169 ( V_3 , L_76 ) ;
return V_61 ;
}
static int F_172 ( struct V_2 * V_3 , int V_296 )
{
struct V_115 V_116 ;
F_97 ( & V_116 , NULL , 0 , V_147 ) ;
V_116 . V_130 [ 0 ] = V_297 ;
V_116 . V_130 [ 4 ] = V_296 ? 1 : 0 ;
return F_83 ( V_3 , & V_116 ) ;
}
static T_5 int F_173 ( struct V_2 * V_3 ,
unsigned * V_149 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
unsigned char V_54 [ 256 + 18 ] ;
unsigned char * V_298 ;
int V_61 , V_4 ;
V_298 = & V_54 [ sizeof( struct V_259 ) + V_3 -> V_258 ] ;
F_97 ( & V_116 , V_54 , sizeof( V_54 ) , V_299 ) ;
V_116 . V_143 = & V_143 ;
V_61 = F_157 ( V_3 , & V_116 , V_300 , 0 ) ;
if ( V_61 ) {
V_116 . V_126 = V_3 -> V_258 + V_298 [ 1 ] + 2 +
sizeof( struct V_259 ) ;
V_61 = F_157 ( V_3 , & V_116 , V_300 , 0 ) ;
if ( V_61 ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
}
V_4 = 20 ;
if ( V_298 [ 1 ] >= 28 )
V_4 = 28 ;
if ( V_298 [ 1 ] >= 30 ) {
int V_301 = ( V_298 [ 30 ] << 8 ) + V_298 [ 31 ] ;
if ( V_301 > 0 )
V_4 = 34 ;
}
* V_149 = ( V_298 [ V_4 ] << 8 ) | V_298 [ V_4 + 1 ] ;
return 0 ;
}
static T_5 int F_174 ( struct V_2 * V_3 ,
unsigned * V_302 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
unsigned char V_54 [ 64 ] ;
unsigned int V_6 , V_303 , V_304 ;
int V_61 ;
F_97 ( & V_116 , V_54 , 2 , V_236 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_130 [ 0 ] = V_305 ;
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
F_97 ( & V_116 , V_54 , V_6 , V_236 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_130 [ 0 ] = V_305 ;
V_116 . V_130 [ 1 ] = 2 ;
V_116 . V_130 [ 2 ] = 4 ;
V_116 . V_130 [ 8 ] = V_6 ;
V_61 = F_83 ( V_3 , & V_116 ) ;
if ( V_61 ) {
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
if ( ! ( V_54 [ 6 ] & 0x40 ) ) {
F_169 ( V_3 , L_77 ) ;
return 1 ;
}
if ( ! ( V_54 [ 6 ] & 0x4 ) ) {
F_169 ( V_3 , L_78 ) ;
return 1 ;
}
V_303 = ( V_54 [ 6 ] >> 3 ) & 0x7 ;
V_304 = V_54 [ 16 ] & 0xf ;
switch ( V_303 ) {
case 0 :
* V_302 = V_306 [ V_304 ] ;
break;
case 1 :
* V_302 = V_307 [ V_304 ] ;
break;
case 2 :
* V_302 = V_308 [ V_304 ] ;
break;
default:
F_169 ( V_3 , L_79 , V_303 ) ;
return 1 ;
}
if ( * V_302 ) {
F_156 ( V_3 , L_80 , * V_302 ) ;
return 0 ;
} else {
F_169 ( V_3 , L_81 , V_304 , V_303 ) ;
return 1 ;
}
}
static T_5 int F_175 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
struct V_142 V_143 ;
int V_61 ;
F_56 ( 2 , V_3 , L_82 ) ;
F_97 ( & V_116 , NULL , 0 , V_147 ) ;
V_116 . V_143 = & V_143 ;
V_116 . V_132 = 60 * V_133 ;
V_116 . V_130 [ 0 ] = V_309 ;
V_116 . V_130 [ 1 ] = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
F_94 ( V_3 , & V_116 ) ;
return V_61 ;
}
static int F_176 ( struct V_2 * V_3 )
{
int V_61 ;
unsigned int V_149 , V_310 , V_150 ;
if ( ( V_61 = F_170 ( V_3 ) ) ) {
F_56 ( 2 , V_3 , L_83 ) ;
return V_61 ;
}
if ( ( V_61 = F_164 ( V_3 ) ) ) {
F_56 ( 1 , V_3 , L_84 ) ;
return - V_139 ;
}
F_171 ( V_3 , V_311 ) ;
if ( ( V_61 = F_173 ( V_3 , & V_149 ) ) )
V_149 = 16 * 177 ;
switch ( V_3 -> V_256 ) {
case 0x13 :
case 0x1a :
case 0x12 :
F_56 ( 1 , V_3 , L_85 , V_149 ) ;
break;
default:
if ( ( V_61 = F_174 ( V_3 , & V_310 ) ) )
V_310 = 16 ;
V_149 = F_16 ( V_149 , V_310 * 177 ) ;
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
if ( ( V_61 = F_175 ( V_3 ) ) ) {
F_56 ( 1 , V_3 , L_88 ) ;
}
return 0 ;
}
static int F_177 ( struct V_2 * V_3 , T_11 V_312 )
{
int V_61 ;
long V_313 ;
struct V_117 * V_118 ;
F_178 ( V_3 -> V_52 -> V_53 ) ;
if ( ( V_61 = F_179 ( V_3 -> V_52 , V_314 | V_315 , V_3 ) ) )
goto V_128;
if ( ( V_61 = F_162 ( V_3 , & V_313 ) ) ) {
F_95 ( V_3 , L_89 ) ;
goto V_316;
}
F_180 ( V_3 -> V_202 , V_313 << 2 ) ;
F_180 ( V_3 -> V_52 -> V_137 , V_313 << 2 ) ;
F_181 ( V_3 -> V_52 , ( V_317 ) V_313 << 11 ) ;
V_118 = F_84 ( V_3 -> V_52 ) ;
if ( V_312 ) {
if ( ( V_61 = F_176 ( V_3 ) ) )
goto V_316;
F_182 ( V_118 -> V_318 ) ;
F_183 ( V_118 , V_3 -> V_5 . V_6 ) ;
F_184 ( V_118 -> V_318 ) ;
F_112 ( V_319 , & V_3 -> V_165 ) ;
} else {
F_98 ( V_3 , V_162 , V_162 ) ;
F_111 ( V_319 , & V_3 -> V_165 ) ;
}
if ( ( V_61 = F_109 ( V_3 , V_118 ) ) )
goto V_316;
if ( V_312 ) {
if ( ! F_71 ( V_3 , V_320 ) ) {
F_95 ( V_3 , L_90 ) ;
V_61 = - V_62 ;
goto V_316;
}
F_156 ( V_3 , L_91 , V_313 << 1 ) ;
}
return 0 ;
V_316:
F_185 ( V_3 -> V_52 , V_314 | V_315 ) ;
V_128:
return V_61 ;
}
static void F_186 ( struct V_2 * V_3 , int V_321 )
{
if ( V_321 && F_96 ( V_3 ) )
F_56 ( 1 , V_3 , L_92 ) ;
F_172 ( V_3 , 0 ) ;
F_98 ( V_3 , V_162 , V_162 ) ;
F_185 ( V_3 -> V_52 , V_314 | V_315 ) ;
F_67 ( V_3 ) ;
}
static struct V_2 * F_187 ( unsigned int V_322 )
{
if ( V_322 >= V_49 )
return NULL ;
return V_50 [ V_322 ] ;
}
static int F_188 ( struct V_323 * V_52 , T_11 V_324 )
{
struct V_2 * V_3 = NULL ;
int V_61 ;
F_189 ( & V_325 ) ;
F_189 ( & V_47 ) ;
V_3 = F_187 ( F_28 ( V_52 -> V_53 ) ) ;
if ( ! V_3 ) {
V_61 = - V_59 ;
goto V_128;
}
F_53 ( V_3 -> V_326 < 0 ) ;
V_3 -> V_326 ++ ;
if ( V_3 -> V_326 > 1 ) {
if ( ( V_324 & V_327 ) &&
! F_138 ( V_319 , & V_3 -> V_165 ) ) {
V_61 = - V_328 ;
goto V_329;
}
} else {
V_61 = F_177 ( V_3 , V_324 & V_327 ) ;
if ( V_61 )
goto V_329;
F_190 ( V_52 , V_163 ) ;
}
F_29 ( & V_47 ) ;
F_29 ( & V_325 ) ;
return 0 ;
V_329:
V_3 -> V_326 -- ;
V_128:
F_29 ( & V_47 ) ;
F_29 ( & V_325 ) ;
return V_61 ;
}
static void F_191 ( struct V_330 * V_202 , T_11 V_324 )
{
struct V_2 * V_3 = V_202 -> V_331 ;
F_189 ( & V_325 ) ;
F_189 ( & V_47 ) ;
V_3 -> V_326 -- ;
F_53 ( V_3 -> V_326 < 0 ) ;
if ( V_3 -> V_326 == 0 ) {
int V_321 = F_138 ( V_319 , & V_3 -> V_165 ) ;
F_186 ( V_3 , V_321 ) ;
}
F_29 ( & V_47 ) ;
F_29 ( & V_325 ) ;
}
static void F_192 ( struct V_95 * V_95 )
{
struct V_332 * V_333 = V_95 -> V_175 ;
struct V_2 * V_3 = V_333 -> V_3 ;
V_333 -> V_95 -> V_176 = V_95 -> V_176 ;
F_64 ( V_95 ) ;
F_140 ( V_333 -> V_95 ) ;
F_78 ( V_333 , V_334 ) ;
F_52 ( V_3 ) ;
}
static void F_193 ( struct V_2 * V_3 , struct V_95 * V_95 )
{
struct V_95 * V_335 = F_194 ( V_95 , V_336 ) ;
struct V_332 * V_333 = F_195 ( V_334 , V_336 ) ;
V_333 -> V_3 = V_3 ;
V_333 -> V_95 = V_95 ;
V_335 -> V_187 = V_3 -> V_52 ;
V_335 -> V_175 = V_333 ;
V_335 -> V_188 = F_192 ;
V_3 -> V_22 . V_26 += F_196 ( V_95 ) ;
F_99 ( V_3 , V_335 ) ;
}
static void F_197 ( struct V_117 * V_118 , struct V_95 * V_95 )
{
struct V_2 * V_3 = V_118 -> V_337 ;
T_1 V_190 ;
struct V_83 * V_86 ;
int V_338 , V_339 ;
struct V_104 * V_105 ;
V_190 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
F_12 ( & V_3 -> V_78 . V_209 ) ;
V_339 = 0 ;
F_127 (pkt, &pd->cdrw.pkt_active_list, list) {
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
V_339 = 1 ;
}
F_13 ( & V_86 -> V_28 ) ;
}
}
F_13 ( & V_3 -> V_78 . V_209 ) ;
F_12 ( & V_3 -> V_28 ) ;
if ( V_3 -> V_31 > 0
&& V_3 -> V_29 >= V_3 -> V_31 ) {
F_198 ( & V_118 -> V_204 , V_205 ) ;
do {
F_13 ( & V_3 -> V_28 ) ;
F_199 ( V_205 , V_133 ) ;
F_12 ( & V_3 -> V_28 ) ;
} while( V_3 -> V_29 > V_3 -> V_30 );
}
F_13 ( & V_3 -> V_28 ) ;
V_105 = F_195 ( V_3 -> V_108 , V_336 ) ;
V_105 -> V_95 = V_95 ;
F_12 ( & V_3 -> V_28 ) ;
F_53 ( V_3 -> V_29 < 0 ) ;
V_338 = ( V_3 -> V_29 == 0 ) ;
F_80 ( V_3 , V_105 ) ;
F_13 ( & V_3 -> V_28 ) ;
F_57 ( & V_3 -> V_198 , 1 ) ;
if ( V_338 ) {
F_58 ( & V_3 -> V_82 ) ;
} else if ( ! F_68 ( & V_3 -> V_78 . V_100 ) && ! V_339 ) {
F_58 ( & V_3 -> V_82 ) ;
}
}
static T_12 F_200 ( struct V_117 * V_118 , struct V_95 * V_95 )
{
struct V_2 * V_3 ;
char V_340 [ V_341 ] ;
struct V_95 * V_342 ;
F_201 ( V_118 , & V_95 ) ;
F_202 ( V_118 , & V_95 , V_118 -> V_343 ) ;
V_3 = V_118 -> V_337 ;
if ( ! V_3 ) {
F_38 ( L_93 ,
F_203 ( V_95 -> V_187 , V_340 ) ) ;
goto V_344;
}
F_56 ( 2 , V_3 , L_94 ,
( unsigned long long ) V_95 -> V_111 . V_112 ,
( unsigned long long ) F_106 ( V_95 ) ) ;
if ( F_100 ( V_95 ) == V_124 ) {
F_193 ( V_3 , V_95 ) ;
return V_345 ;
}
if ( ! F_138 ( V_319 , & V_3 -> V_165 ) ) {
F_169 ( V_3 , L_95 ,
( unsigned long long ) V_95 -> V_111 . V_112 ) ;
goto V_344;
}
if ( ! V_95 -> V_111 . V_160 || ( V_95 -> V_111 . V_160 % V_163 ) ) {
F_95 ( V_3 , L_96 ) ;
goto V_344;
}
do {
T_1 V_190 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
T_1 V_346 = F_1 ( F_106 ( V_95 ) - 1 , V_3 ) ;
if ( V_346 != V_190 ) {
F_53 ( V_346 != V_190 + V_3 -> V_5 . V_6 ) ;
V_342 = V_343 ( V_95 , V_346 -
V_95 -> V_111 . V_112 ,
V_336 , V_347 ) ;
F_204 ( V_342 , V_95 ) ;
} else {
V_342 = V_95 ;
}
F_197 ( V_118 , V_342 ) ;
} while ( V_342 != V_95 );
return V_345 ;
V_344:
F_205 ( V_95 ) ;
return V_345 ;
}
static void F_206 ( struct V_2 * V_3 )
{
struct V_117 * V_118 = V_3 -> V_202 -> V_203 ;
F_207 ( V_118 , F_200 ) ;
F_208 ( V_118 , V_163 ) ;
F_183 ( V_118 , V_283 ) ;
V_118 -> V_337 = V_3 ;
}
static int F_42 ( struct V_68 * V_69 , void * V_13 )
{
struct V_2 * V_3 = V_69 -> V_348 ;
char * V_349 ;
char V_350 [ V_341 ] ;
int V_219 [ V_220 ] ;
F_209 ( V_69 , L_97 , V_3 -> V_8 ,
F_203 ( V_3 -> V_52 , V_350 ) ) ;
F_209 ( V_69 , L_98 ) ;
F_209 ( V_69 , L_99 , V_3 -> V_5 . V_6 / 2 ) ;
if ( V_3 -> V_5 . V_261 == 0 )
V_349 = L_100 ;
else
V_349 = L_101 ;
F_209 ( V_69 , L_102 , V_349 ) ;
F_209 ( V_69 , L_103 , V_3 -> V_5 . V_231 ? L_60 : L_61 ) ;
F_209 ( V_69 , L_104 , V_3 -> V_5 . V_290 ) ;
F_209 ( V_69 , L_105 , V_3 -> V_5 . V_260 ) ;
if ( V_3 -> V_5 . V_232 == V_266 )
V_349 = L_106 ;
else if ( V_3 -> V_5 . V_232 == V_269 )
V_349 = L_107 ;
else
V_349 = L_101 ;
F_209 ( V_69 , L_108 , V_349 ) ;
F_209 ( V_69 , L_109 ) ;
F_209 ( V_69 , L_110 , V_3 -> V_22 . V_23 ) ;
F_209 ( V_69 , L_111 , V_3 -> V_22 . V_24 ) ;
F_209 ( V_69 , L_112 , V_3 -> V_22 . V_25 >> 1 ) ;
F_209 ( V_69 , L_113 , V_3 -> V_22 . V_27 >> 1 ) ;
F_209 ( V_69 , L_114 , V_3 -> V_22 . V_26 >> 1 ) ;
F_209 ( V_69 , L_115 ) ;
F_209 ( V_69 , L_116 , V_3 -> V_326 ) ;
F_209 ( V_69 , L_117 , V_3 -> V_165 ) ;
F_209 ( V_69 , L_118 , V_3 -> V_150 ) ;
F_209 ( V_69 , L_119 , V_3 -> V_149 ) ;
F_209 ( V_69 , L_120 , V_3 -> V_4 ) ;
F_209 ( V_69 , L_121 , V_3 -> V_258 ) ;
F_209 ( V_69 , L_122 ) ;
F_209 ( V_69 , L_123 , V_3 -> V_29 ) ;
F_209 ( V_69 , L_124 , F_54 ( & V_3 -> V_78 . V_79 ) ) ;
F_209 ( V_69 , L_125 , ( unsigned long long ) V_3 -> V_199 ) ;
F_144 ( V_3 , V_219 ) ;
F_209 ( V_69 , L_126 ,
V_219 [ 0 ] , V_219 [ 1 ] , V_219 [ 2 ] , V_219 [ 3 ] , V_219 [ 4 ] , V_219 [ 5 ] ) ;
F_209 ( V_69 , L_127 ,
V_3 -> V_30 ,
V_3 -> V_31 ) ;
return 0 ;
}
static int F_210 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
return F_44 ( V_71 , F_42 , F_211 ( V_70 ) ) ;
}
static int F_212 ( struct V_2 * V_3 , T_13 V_37 )
{
int V_85 ;
int V_61 = 0 ;
char V_340 [ V_341 ] ;
struct V_323 * V_52 ;
if ( V_3 -> V_51 == V_37 ) {
F_95 ( V_3 , L_128 ) ;
return - V_328 ;
}
for ( V_85 = 0 ; V_85 < V_49 ; V_85 ++ ) {
struct V_2 * V_351 = V_50 [ V_85 ] ;
if ( ! V_351 )
continue;
if ( V_351 -> V_52 -> V_53 == V_37 ) {
F_95 ( V_3 , L_129 ,
F_203 ( V_351 -> V_52 , V_340 ) ) ;
return - V_328 ;
}
if ( V_351 -> V_51 == V_37 ) {
F_95 ( V_3 , L_130 ) ;
return - V_328 ;
}
}
V_52 = F_178 ( V_37 ) ;
if ( ! V_52 )
return - V_62 ;
V_61 = F_179 ( V_52 , V_314 | V_352 , NULL ) ;
if ( V_61 )
return V_61 ;
F_213 ( V_58 ) ;
V_3 -> V_52 = V_52 ;
F_190 ( V_52 , V_163 ) ;
F_206 ( V_3 ) ;
F_57 ( & V_3 -> V_78 . V_79 , 0 ) ;
V_3 -> V_78 . V_353 = F_214 ( F_145 , V_3 , L_1 , V_3 -> V_8 ) ;
if ( F_21 ( V_3 -> V_78 . V_353 ) ) {
F_95 ( V_3 , L_131 ) ;
V_61 = - V_62 ;
goto V_354;
}
F_215 ( V_3 -> V_8 , 0 , V_355 , & V_356 , V_3 ) ;
F_56 ( 1 , V_3 , L_132 , F_203 ( V_52 , V_340 ) ) ;
return 0 ;
V_354:
F_185 ( V_52 , V_314 | V_352 ) ;
F_33 ( V_58 ) ;
return V_61 ;
}
static int F_216 ( struct V_323 * V_52 , T_11 V_324 , unsigned int V_130 , unsigned long V_357 )
{
struct V_2 * V_3 = V_52 -> V_137 -> V_331 ;
int V_61 ;
F_56 ( 2 , V_3 , L_133 ,
V_130 , F_27 ( V_52 -> V_53 ) , F_28 ( V_52 -> V_53 ) ) ;
F_189 ( & V_325 ) ;
switch ( V_130 ) {
case V_358 :
if ( V_3 -> V_326 == 1 )
F_172 ( V_3 , 0 ) ;
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
V_61 = F_217 ( V_3 -> V_52 , V_324 , V_130 , V_357 ) ;
break;
default:
F_56 ( 2 , V_3 , L_134 , V_130 ) ;
V_61 = - V_364 ;
}
F_29 ( & V_325 ) ;
return V_61 ;
}
static unsigned int F_218 ( struct V_330 * V_202 ,
unsigned int V_365 )
{
struct V_2 * V_3 = V_202 -> V_331 ;
struct V_330 * V_366 ;
if ( ! V_3 )
return 0 ;
if ( ! V_3 -> V_52 )
return 0 ;
V_366 = V_3 -> V_52 -> V_137 ;
if ( ! V_366 || ! V_366 -> V_367 -> V_368 )
return 0 ;
return V_366 -> V_367 -> V_368 ( V_366 , V_365 ) ;
}
static char * F_219 ( struct V_330 * V_369 , T_14 * V_324 )
{
return F_220 ( V_14 , L_135 , V_369 -> V_370 ) ;
}
static int F_32 ( T_13 V_37 , T_13 * V_51 )
{
int V_46 ;
int V_61 = - V_62 ;
struct V_2 * V_3 ;
struct V_330 * V_202 ;
F_26 ( & V_47 , V_48 ) ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ )
if ( ! V_50 [ V_46 ] )
break;
if ( V_46 == V_49 ) {
F_38 ( L_136 , V_49 ) ;
V_61 = - V_328 ;
goto V_371;
}
V_3 = F_3 ( sizeof( struct V_2 ) , V_14 ) ;
if ( ! V_3 )
goto V_371;
V_3 -> V_108 = F_221 ( V_372 ,
sizeof( struct V_104 ) ) ;
if ( ! V_3 -> V_108 )
goto V_354;
F_70 ( & V_3 -> V_78 . V_100 ) ;
F_70 ( & V_3 -> V_78 . V_99 ) ;
F_62 ( & V_3 -> V_78 . V_209 ) ;
F_62 ( & V_3 -> V_28 ) ;
F_62 ( & V_3 -> V_80 . V_28 ) ;
F_63 ( & V_3 -> V_80 . V_152 ) ;
F_63 ( & V_3 -> V_80 . V_153 ) ;
sprintf ( V_3 -> V_8 , V_63 L_13 , V_46 ) ;
F_222 ( & V_3 -> V_82 ) ;
V_3 -> V_107 = V_373 ;
V_3 -> V_31 = V_31 ;
V_3 -> V_30 = V_30 ;
V_202 = F_223 ( 1 ) ;
if ( ! V_202 )
goto V_354;
V_3 -> V_202 = V_202 ;
V_202 -> V_56 = V_374 ;
V_202 -> V_375 = V_46 ;
V_202 -> V_367 = & V_376 ;
V_202 -> V_165 = V_377 ;
strcpy ( V_202 -> V_370 , V_3 -> V_8 ) ;
V_202 -> V_378 = F_219 ;
V_202 -> V_331 = V_3 ;
V_202 -> V_203 = F_224 ( V_14 ) ;
if ( ! V_202 -> V_203 )
goto V_379;
V_3 -> V_51 = F_20 ( V_374 , V_46 ) ;
V_61 = F_212 ( V_3 , V_37 ) ;
if ( V_61 )
goto V_380;
V_202 -> V_381 = V_3 -> V_52 -> V_137 -> V_381 ;
V_202 -> V_382 = V_3 -> V_52 -> V_137 -> V_382 ;
F_225 ( V_202 ) ;
F_18 ( V_3 ) ;
F_45 ( V_3 ) ;
V_50 [ V_46 ] = V_3 ;
if ( V_51 )
* V_51 = V_3 -> V_51 ;
F_29 ( & V_47 ) ;
return 0 ;
V_380:
F_226 ( V_202 -> V_203 ) ;
V_379:
F_227 ( V_202 ) ;
V_354:
F_228 ( V_3 -> V_108 ) ;
F_9 ( V_3 ) ;
V_371:
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
F_229 ( L_138 ) ;
V_61 = - V_282 ;
goto V_128;
}
if ( V_3 -> V_326 > 0 ) {
V_61 = - V_328 ;
goto V_128;
}
if ( ! F_21 ( V_3 -> V_78 . V_353 ) )
F_230 ( V_3 -> V_78 . V_353 ) ;
V_50 [ V_46 ] = NULL ;
F_48 ( V_3 ) ;
F_22 ( V_3 ) ;
F_185 ( V_3 -> V_52 , V_314 | V_352 ) ;
F_231 ( V_3 -> V_8 , V_355 ) ;
F_56 ( 1 , V_3 , L_139 ) ;
F_232 ( V_3 -> V_202 ) ;
F_226 ( V_3 -> V_202 -> V_203 ) ;
F_227 ( V_3 -> V_202 ) ;
F_228 ( V_3 -> V_108 ) ;
F_9 ( V_3 ) ;
F_33 ( V_58 ) ;
V_128:
F_29 ( & V_47 ) ;
return V_61 ;
}
static void F_233 ( struct V_383 * V_384 )
{
struct V_2 * V_3 ;
F_26 ( & V_47 , V_48 ) ;
V_3 = F_187 ( V_384 -> V_385 ) ;
if ( V_3 ) {
V_384 -> V_37 = F_234 ( V_3 -> V_52 -> V_53 ) ;
V_384 -> V_51 = F_234 ( V_3 -> V_51 ) ;
} else {
V_384 -> V_37 = 0 ;
V_384 -> V_51 = 0 ;
}
V_384 -> V_386 = V_49 ;
F_29 ( & V_47 ) ;
}
static long F_235 ( struct V_71 * V_71 , unsigned int V_130 , unsigned long V_357 )
{
void T_15 * V_387 = ( void T_15 * ) V_357 ;
struct V_383 V_384 ;
int V_61 = 0 ;
T_13 V_51 = 0 ;
if ( V_130 != V_388 )
return - V_364 ;
if ( F_236 ( & V_384 , V_387 , sizeof( struct V_383 ) ) )
return - V_389 ;
switch ( V_384 . V_390 ) {
case V_391 :
if ( ! F_237 ( V_392 ) )
return - V_393 ;
V_61 = F_32 ( F_238 ( V_384 . V_37 ) , & V_51 ) ;
V_384 . V_51 = F_234 ( V_51 ) ;
break;
case V_394 :
if ( ! F_237 ( V_392 ) )
return - V_393 ;
V_61 = F_35 ( F_238 ( V_384 . V_51 ) ) ;
break;
case V_395 :
F_233 ( & V_384 ) ;
break;
default:
return - V_364 ;
}
if ( F_239 ( V_387 , & V_384 , sizeof( struct V_383 ) ) )
return - V_389 ;
return V_61 ;
}
static long F_240 ( struct V_71 * V_71 , unsigned int V_130 , unsigned long V_357 )
{
return F_235 ( V_71 , V_130 , ( unsigned long ) F_241 ( V_357 ) ) ;
}
static int T_16 F_242 ( void )
{
int V_61 ;
F_243 ( & V_47 ) ;
V_334 = F_221 ( V_396 ,
sizeof( struct V_332 ) ) ;
if ( ! V_334 )
return - V_62 ;
V_61 = F_244 ( V_374 , V_63 ) ;
if ( V_61 < 0 ) {
F_38 ( L_140 ) ;
goto V_397;
}
if ( ! V_374 )
V_374 = V_61 ;
V_61 = F_36 () ;
if ( V_61 )
goto V_128;
F_50 () ;
V_61 = F_245 ( & V_398 ) ;
if ( V_61 ) {
F_38 ( L_141 ) ;
goto V_399;
}
V_355 = F_246 ( L_142 V_63 , NULL ) ;
return 0 ;
V_399:
F_51 () ;
F_39 () ;
V_128:
F_247 ( V_374 , V_63 ) ;
V_397:
F_228 ( V_334 ) ;
return V_61 ;
}
static void T_17 F_248 ( void )
{
F_231 ( L_142 V_63 , NULL ) ;
F_249 ( & V_398 ) ;
F_51 () ;
F_39 () ;
F_247 ( V_374 , V_63 ) ;
F_228 ( V_334 ) ;
}
