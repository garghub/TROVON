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
if ( V_116 -> V_126 ) {
V_61 = F_86 ( V_118 , V_120 , V_116 -> V_127 , V_116 -> V_126 ,
V_125 ) ;
if ( V_61 )
goto V_128;
}
V_120 -> V_129 = F_87 ( V_116 -> V_130 [ 0 ] ) ;
memcpy ( V_120 -> V_130 , V_116 -> V_130 , V_131 ) ;
V_120 -> V_132 = 60 * V_133 ;
V_120 -> V_134 = V_135 ;
if ( V_116 -> V_136 )
V_120 -> V_137 |= V_138 ;
F_88 ( V_120 -> V_118 , V_3 -> V_52 -> V_139 , V_120 , 0 ) ;
if ( V_120 -> V_140 )
V_61 = - V_141 ;
V_128:
F_89 ( V_120 ) ;
return V_61 ;
}
static const char * F_90 ( T_4 V_142 )
{
static const char * const V_143 [] = {
L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 ,
L_27 , L_28 , L_29 ,
} ;
return V_142 < F_91 ( V_143 ) ? V_143 [ V_142 ] : L_30 ;
}
static void F_92 ( struct V_2 * V_3 ,
struct V_115 * V_116 )
{
struct V_144 * V_145 = V_116 -> V_145 ;
if ( V_145 )
F_93 ( V_3 , L_31 ,
V_131 , V_116 -> V_130 ,
V_145 -> V_146 , V_145 -> V_147 , V_145 -> V_148 ,
F_90 ( V_145 -> V_146 ) ) ;
else
F_93 ( V_3 , L_32 , V_131 , V_116 -> V_130 ) ;
}
static int F_94 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
F_95 ( & V_116 , NULL , 0 , V_149 ) ;
V_116 . V_130 [ 0 ] = V_150 ;
V_116 . V_136 = 1 ;
#if 0
cgc.cmd[1] = 1 << 1;
#endif
return F_83 ( V_3 , & V_116 ) ;
}
static T_5 int F_96 ( struct V_2 * V_3 ,
unsigned V_151 , unsigned V_152 )
{
struct V_115 V_116 ;
struct V_144 V_145 ;
int V_61 ;
F_95 ( & V_116 , NULL , 0 , V_149 ) ;
V_116 . V_145 = & V_145 ;
V_116 . V_130 [ 0 ] = V_153 ;
V_116 . V_130 [ 2 ] = ( V_152 >> 8 ) & 0xff ;
V_116 . V_130 [ 3 ] = V_152 & 0xff ;
V_116 . V_130 [ 4 ] = ( V_151 >> 8 ) & 0xff ;
V_116 . V_130 [ 5 ] = V_151 & 0xff ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
F_92 ( V_3 , & V_116 ) ;
return V_61 ;
}
static void F_97 ( struct V_2 * V_3 , struct V_95 * V_95 )
{
F_12 ( & V_3 -> V_80 . V_28 ) ;
if ( F_98 ( V_95 ) == V_124 )
F_99 ( & V_3 -> V_80 . V_154 , V_95 ) ;
else
F_99 ( & V_3 -> V_80 . V_155 , V_95 ) ;
F_13 ( & V_3 -> V_80 . V_28 ) ;
F_57 ( & V_3 -> V_80 . V_81 , 1 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
static void F_100 ( struct V_2 * V_3 )
{
if ( F_54 ( & V_3 -> V_80 . V_81 ) == 0 )
return;
F_57 ( & V_3 -> V_80 . V_81 , 0 ) ;
for (; ; ) {
struct V_95 * V_95 ;
int V_156 , V_157 ;
F_12 ( & V_3 -> V_80 . V_28 ) ;
V_156 = ! F_101 ( & V_3 -> V_80 . V_154 ) ;
V_157 = ! F_101 ( & V_3 -> V_80 . V_155 ) ;
F_13 ( & V_3 -> V_80 . V_28 ) ;
if ( ! V_156 && ! V_157 )
break;
if ( V_3 -> V_80 . V_158 ) {
int V_159 = 1 ;
F_12 ( & V_3 -> V_80 . V_28 ) ;
V_95 = F_102 ( & V_3 -> V_80 . V_155 ) ;
F_13 ( & V_3 -> V_80 . V_28 ) ;
if ( V_95 && ( V_95 -> V_111 . V_112 ==
V_3 -> V_80 . V_160 ) )
V_159 = 0 ;
if ( V_159 && V_156 ) {
if ( F_54 ( & V_3 -> V_78 . V_79 ) > 0 ) {
F_56 ( 2 , V_3 , L_33 ) ;
break;
}
F_94 ( V_3 ) ;
V_3 -> V_80 . V_158 = 0 ;
}
} else {
if ( ! V_156 && V_157 ) {
if ( F_54 ( & V_3 -> V_78 . V_79 ) > 0 ) {
F_56 ( 2 , V_3 , L_34 ) ;
break;
}
V_3 -> V_80 . V_158 = 1 ;
}
}
F_12 ( & V_3 -> V_80 . V_28 ) ;
if ( V_3 -> V_80 . V_158 )
V_95 = F_103 ( & V_3 -> V_80 . V_155 ) ;
else
V_95 = F_103 ( & V_3 -> V_80 . V_154 ) ;
F_13 ( & V_3 -> V_80 . V_28 ) ;
if ( ! V_95 )
continue;
if ( F_98 ( V_95 ) == V_124 )
V_3 -> V_80 . V_161 +=
V_95 -> V_111 . V_162 >> 10 ;
else {
V_3 -> V_80 . V_161 = 0 ;
V_3 -> V_80 . V_160 = F_104 ( V_95 ) ;
}
if ( V_3 -> V_80 . V_161 >= V_163 ) {
if ( V_3 -> V_152 == V_3 -> V_151 ) {
V_3 -> V_152 = V_164 ;
F_96 ( V_3 , V_3 -> V_151 , V_3 -> V_152 ) ;
}
} else {
if ( V_3 -> V_152 != V_3 -> V_151 ) {
V_3 -> V_152 = V_3 -> V_151 ;
F_96 ( V_3 , V_3 -> V_151 , V_3 -> V_152 ) ;
}
}
F_105 ( & V_3 -> V_78 . V_79 ) ;
F_106 ( V_95 ) ;
}
}
static int F_107 ( struct V_2 * V_3 , struct V_117 * V_118 )
{
if ( ( V_3 -> V_5 . V_6 << 9 ) / V_165
<= F_108 ( V_118 ) ) {
F_109 ( V_166 , & V_3 -> V_167 ) ;
return 0 ;
} else if ( ( V_3 -> V_5 . V_6 << 9 ) / V_168
<= F_108 ( V_118 ) ) {
F_110 ( V_166 , & V_3 -> V_167 ) ;
return 0 ;
} else {
F_93 ( V_3 , L_35 ) ;
return - V_141 ;
}
}
static void F_111 ( struct V_83 * V_86 , struct V_169 * V_170 )
{
int V_171 , V_13 , V_172 ;
V_13 = 0 ;
V_172 = 0 ;
for ( V_171 = 0 ; V_171 < V_86 -> V_84 ; V_171 ++ ) {
if ( V_170 [ V_171 ] . V_173 != V_86 -> V_91 [ V_13 ] ) {
void * V_174 = F_112 ( V_170 [ V_171 ] . V_173 ) + V_170 [ V_171 ] . V_175 ;
void * V_176 = F_113 ( V_86 -> V_91 [ V_13 ] ) + V_172 ;
memcpy ( V_176 , V_174 , V_165 ) ;
F_114 ( V_174 ) ;
V_170 [ V_171 ] . V_173 = V_86 -> V_91 [ V_13 ] ;
V_170 [ V_171 ] . V_175 = V_172 ;
} else {
F_53 ( V_170 [ V_171 ] . V_175 != V_172 ) ;
}
V_172 += V_165 ;
if ( V_172 >= V_168 ) {
V_172 = 0 ;
V_13 ++ ;
}
}
}
static void F_115 ( struct V_95 * V_95 , int V_177 )
{
struct V_83 * V_86 = V_95 -> V_178 ;
struct V_2 * V_3 = V_86 -> V_3 ;
F_53 ( ! V_3 ) ;
F_56 ( 2 , V_3 , L_36 ,
V_95 , ( unsigned long long ) V_86 -> V_1 ,
( unsigned long long ) V_95 -> V_111 . V_112 , V_177 ) ;
if ( V_177 )
F_105 ( & V_86 -> V_179 ) ;
if ( F_55 ( & V_86 -> V_180 ) ) {
F_105 ( & V_86 -> V_181 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
F_52 ( V_3 ) ;
}
static void F_116 ( struct V_95 * V_95 , int V_177 )
{
struct V_83 * V_86 = V_95 -> V_178 ;
struct V_2 * V_3 = V_86 -> V_3 ;
F_53 ( ! V_3 ) ;
F_56 ( 2 , V_3 , L_37 , V_86 -> V_102 , V_177 ) ;
V_3 -> V_22 . V_24 ++ ;
F_52 ( V_3 ) ;
F_117 ( & V_86 -> V_180 ) ;
F_105 ( & V_86 -> V_181 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
static void F_118 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
int V_182 = 0 ;
struct V_95 * V_95 ;
int V_171 ;
char V_183 [ V_184 ] ;
F_53 ( F_101 ( & V_86 -> V_94 ) ) ;
F_57 ( & V_86 -> V_180 , 0 ) ;
F_57 ( & V_86 -> V_179 , 0 ) ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
F_12 ( & V_86 -> V_28 ) ;
F_119 (bio, &pkt->orig_bios) {
int V_185 = ( V_95 -> V_111 . V_112 - V_86 -> V_1 ) /
( V_165 >> 9 ) ;
int V_186 = V_95 -> V_111 . V_162 / V_165 ;
V_3 -> V_22 . V_25 += V_186 * ( V_165 >> 9 ) ;
F_53 ( V_185 < 0 ) ;
F_53 ( V_185 + V_186 > V_86 -> V_84 ) ;
for ( V_171 = V_185 ; V_171 < V_185 + V_186 ; V_171 ++ )
V_183 [ V_171 ] = 1 ;
}
F_13 ( & V_86 -> V_28 ) ;
if ( V_86 -> V_187 ) {
F_56 ( 2 , V_3 , L_38 ,
( unsigned long long ) V_86 -> V_1 ) ;
goto V_188;
}
for ( V_171 = 0 ; V_171 < V_86 -> V_84 ; V_171 ++ ) {
int V_13 , V_4 ;
if ( V_183 [ V_171 ] )
continue;
V_95 = V_86 -> V_97 [ V_171 ] ;
F_120 ( V_95 ) ;
V_95 -> V_111 . V_112 = V_86 -> V_1 + V_171 * ( V_165 >> 9 ) ;
V_95 -> V_189 = V_3 -> V_52 ;
V_95 -> V_190 = F_115 ;
V_95 -> V_178 = V_86 ;
V_13 = ( V_171 * V_165 ) / V_168 ;
V_4 = ( V_171 * V_165 ) % V_168 ;
F_56 ( 2 , V_3 , L_39 ,
V_171 , V_86 -> V_91 [ V_13 ] , V_4 ) ;
if ( ! F_121 ( V_95 , V_86 -> V_91 [ V_13 ] , V_165 , V_4 ) )
F_122 () ;
F_105 ( & V_86 -> V_180 ) ;
V_95 -> V_191 = V_124 ;
F_97 ( V_3 , V_95 ) ;
V_182 ++ ;
}
V_188:
F_56 ( 2 , V_3 , L_40 ,
V_182 , ( unsigned long long ) V_86 -> V_1 ) ;
V_3 -> V_22 . V_23 ++ ;
V_3 -> V_22 . V_27 += V_182 * ( V_165 >> 9 ) ;
}
static struct V_83 * F_123 ( struct V_2 * V_3 , int V_192 )
{
struct V_83 * V_86 ;
F_124 (pkt, &pd->cdrw.pkt_free_list, list) {
if ( V_86 -> V_1 == V_192 || V_86 -> V_103 . V_98 == & V_3 -> V_78 . V_100 ) {
F_125 ( & V_86 -> V_103 ) ;
if ( V_86 -> V_1 != V_192 )
V_86 -> V_187 = 0 ;
return V_86 ;
}
}
F_122 () ;
return NULL ;
}
static void F_126 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
if ( V_86 -> V_187 ) {
F_72 ( & V_86 -> V_103 , & V_3 -> V_78 . V_100 ) ;
} else {
F_127 ( & V_86 -> V_103 , & V_3 -> V_78 . V_100 ) ;
}
}
static int F_128 ( struct V_83 * V_86 )
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
static inline void F_129 ( struct V_83 * V_86 , enum V_193 V_194 )
{
#if V_195 > 1
static const char * V_196 [] = {
L_41 , L_42 , L_43 , L_44 , L_45 , L_46
} ;
enum V_193 V_197 = V_86 -> V_194 ;
F_56 ( 2 , V_3 , L_47 ,
V_86 -> V_102 , ( unsigned long long ) V_86 -> V_1 ,
V_196 [ V_197 ] , V_196 [ V_194 ] ) ;
#endif
V_86 -> V_194 = V_194 ;
}
static int F_130 ( struct V_2 * V_3 )
{
struct V_83 * V_86 , * V_13 ;
struct V_95 * V_95 = NULL ;
T_1 V_192 = 0 ;
struct V_104 * V_105 , * V_198 ;
struct V_106 * V_20 ;
int V_199 ;
F_57 ( & V_3 -> V_200 , 0 ) ;
if ( F_68 ( & V_3 -> V_78 . V_100 ) ) {
F_56 ( 2 , V_3 , L_48 ) ;
return 0 ;
}
F_12 ( & V_3 -> V_28 ) ;
V_198 = F_79 ( V_3 , V_3 -> V_201 ) ;
if ( ! V_198 ) {
V_20 = F_131 ( & V_3 -> V_107 ) ;
if ( V_20 )
V_198 = F_75 ( V_20 , struct V_104 , V_106 ) ;
}
V_105 = V_198 ;
while ( V_105 ) {
V_95 = V_105 -> V_95 ;
V_192 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
F_124 (p, &pd->cdrw.pkt_active_list, list) {
if ( V_13 -> V_1 == V_192 ) {
V_95 = NULL ;
goto V_202;
}
}
break;
V_202:
V_105 = F_73 ( V_105 ) ;
if ( ! V_105 ) {
V_20 = F_131 ( & V_3 -> V_107 ) ;
if ( V_20 )
V_105 = F_75 ( V_20 , struct V_104 , V_106 ) ;
}
if ( V_105 == V_198 )
V_105 = NULL ;
}
F_13 ( & V_3 -> V_28 ) ;
if ( ! V_95 ) {
F_56 ( 2 , V_3 , L_49 ) ;
return 0 ;
}
V_86 = F_123 ( V_3 , V_192 ) ;
V_3 -> V_201 = V_192 + V_3 -> V_5 . V_6 ;
V_86 -> V_1 = V_192 ;
F_53 ( V_86 -> V_84 != V_3 -> V_5 . V_6 >> 2 ) ;
V_86 -> V_203 = 0 ;
F_12 ( & V_3 -> V_28 ) ;
F_56 ( 2 , V_3 , L_50 , ( unsigned long long ) V_192 ) ;
while ( ( V_105 = F_79 ( V_3 , V_192 ) ) != NULL ) {
V_95 = V_105 -> V_95 ;
F_56 ( 2 , V_3 , L_51 , ( unsigned long long )
F_1 ( V_95 -> V_111 . V_112 , V_3 ) ) ;
if ( F_1 ( V_95 -> V_111 . V_112 , V_3 ) != V_192 )
break;
F_76 ( V_3 , V_105 ) ;
F_12 ( & V_86 -> V_28 ) ;
F_99 ( & V_86 -> V_94 , V_95 ) ;
V_86 -> V_203 += V_95 -> V_111 . V_162 / V_165 ;
F_13 ( & V_86 -> V_28 ) ;
}
V_199 = ( V_3 -> V_31 > 0
&& V_3 -> V_29 <= V_3 -> V_30 ) ;
F_13 ( & V_3 -> V_28 ) ;
if ( V_199 ) {
F_132 ( & V_3 -> V_204 -> V_205 -> V_206 ,
V_207 ) ;
}
V_86 -> V_208 = F_15 ( V_209 , 1 ) ;
F_129 ( V_86 , V_210 ) ;
F_57 ( & V_86 -> V_181 , 1 ) ;
F_12 ( & V_3 -> V_78 . V_211 ) ;
F_72 ( & V_86 -> V_103 , & V_3 -> V_78 . V_99 ) ;
F_13 ( & V_3 -> V_78 . V_211 ) ;
return 1 ;
}
static void F_133 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
int V_171 ;
struct V_169 * V_170 = V_86 -> V_88 -> V_212 ;
F_120 ( V_86 -> V_88 ) ;
V_86 -> V_88 -> V_111 . V_112 = V_86 -> V_1 ;
V_86 -> V_88 -> V_189 = V_3 -> V_52 ;
V_86 -> V_88 -> V_190 = F_116 ;
V_86 -> V_88 -> V_178 = V_86 ;
for ( V_171 = 0 ; V_171 < V_86 -> V_84 ; V_171 ++ ) {
V_170 [ V_171 ] . V_173 = V_86 -> V_91 [ ( V_171 * V_165 ) / V_168 ] ;
V_170 [ V_171 ] . V_175 = ( V_171 * V_165 ) % V_168 ;
if ( ! F_121 ( V_86 -> V_88 , V_170 [ V_171 ] . V_173 , V_165 , V_170 [ V_171 ] . V_175 ) )
F_122 () ;
}
F_56 ( 2 , V_3 , L_52 , V_86 -> V_88 -> V_213 ) ;
F_12 ( & V_86 -> V_28 ) ;
F_134 ( V_86 -> V_88 , V_86 -> V_94 . V_214 ) ;
F_129 ( V_86 , V_215 ) ;
F_13 ( & V_86 -> V_28 ) ;
F_56 ( 2 , V_3 , L_53 ,
V_86 -> V_203 , ( unsigned long long ) V_86 -> V_1 ) ;
if ( F_135 ( V_166 , & V_3 -> V_167 ) || ( V_86 -> V_203 < V_86 -> V_84 ) ) {
F_111 ( V_86 , V_170 ) ;
V_86 -> V_187 = 1 ;
} else {
V_86 -> V_187 = 0 ;
}
F_57 ( & V_86 -> V_180 , 1 ) ;
V_86 -> V_88 -> V_191 = V_123 ;
F_97 ( V_3 , V_86 -> V_88 ) ;
}
static void F_136 ( struct V_83 * V_86 , int V_216 )
{
struct V_95 * V_95 ;
if ( ! V_216 )
V_86 -> V_187 = 0 ;
while ( ( V_95 = F_103 ( & V_86 -> V_94 ) ) )
F_137 ( V_95 , V_216 ? 0 : - V_141 ) ;
}
static void F_138 ( struct V_2 * V_3 , struct V_83 * V_86 )
{
int V_216 ;
F_56 ( 2 , V_3 , L_54 , V_86 -> V_102 ) ;
for (; ; ) {
switch ( V_86 -> V_194 ) {
case V_210 :
if ( ( V_86 -> V_203 < V_86 -> V_84 ) && ( V_86 -> V_208 > 0 ) )
return;
V_86 -> V_208 = 0 ;
F_118 ( V_3 , V_86 ) ;
F_129 ( V_86 , V_217 ) ;
break;
case V_217 :
if ( F_54 ( & V_86 -> V_180 ) > 0 )
return;
if ( F_54 ( & V_86 -> V_179 ) > 0 ) {
F_129 ( V_86 , V_218 ) ;
} else {
F_133 ( V_3 , V_86 ) ;
}
break;
case V_215 :
if ( F_54 ( & V_86 -> V_180 ) > 0 )
return;
if ( F_135 ( V_219 , & V_86 -> V_88 -> V_220 ) ) {
F_129 ( V_86 , V_221 ) ;
} else {
F_129 ( V_86 , V_218 ) ;
}
break;
case V_218 :
if ( F_128 ( V_86 ) ) {
F_133 ( V_3 , V_86 ) ;
} else {
F_56 ( 2 , V_3 , L_55 ) ;
F_129 ( V_86 , V_221 ) ;
}
break;
case V_221 :
V_216 = F_135 ( V_219 , & V_86 -> V_88 -> V_220 ) ;
F_136 ( V_86 , V_216 ) ;
return;
default:
F_122 () ;
break;
}
}
}
static void F_139 ( struct V_2 * V_3 )
{
struct V_83 * V_86 , * V_98 ;
F_124 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_54 ( & V_86 -> V_181 ) > 0 ) {
F_57 ( & V_86 -> V_181 , 0 ) ;
F_138 ( V_3 , V_86 ) ;
}
}
F_12 ( & V_3 -> V_78 . V_211 ) ;
F_69 (pkt, next, &pd->cdrw.pkt_active_list, list) {
if ( V_86 -> V_194 == V_221 ) {
F_140 ( & V_86 -> V_103 ) ;
F_126 ( V_3 , V_86 ) ;
F_129 ( V_86 , V_222 ) ;
F_57 ( & V_3 -> V_200 , 1 ) ;
}
}
F_13 ( & V_3 -> V_78 . V_211 ) ;
}
static void F_141 ( struct V_2 * V_3 , int * V_223 )
{
struct V_83 * V_86 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_224 ; V_85 ++ )
V_223 [ V_85 ] = 0 ;
F_12 ( & V_3 -> V_78 . V_211 ) ;
F_124 (pkt, &pd->cdrw.pkt_active_list, list) {
V_223 [ V_86 -> V_194 ] ++ ;
}
F_13 ( & V_3 -> V_78 . V_211 ) ;
}
static int F_142 ( void * V_225 )
{
struct V_2 * V_3 = V_225 ;
struct V_83 * V_86 ;
long V_226 , V_227 ;
F_143 ( V_228 , - 20 ) ;
F_144 () ;
for (; ; ) {
F_145 ( V_229 , V_228 ) ;
F_146 ( & V_3 -> V_82 , & V_229 ) ;
for (; ; ) {
F_147 ( V_230 ) ;
if ( F_54 ( & V_3 -> V_200 ) > 0 )
goto V_231;
F_124 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( F_54 ( & V_86 -> V_181 ) > 0 )
goto V_231;
}
if ( F_54 ( & V_3 -> V_80 . V_81 ) != 0 )
goto V_231;
if ( V_195 > 1 ) {
int V_223 [ V_224 ] ;
F_141 ( V_3 , V_223 ) ;
F_56 ( 2 , V_3 , L_56 ,
V_223 [ 0 ] , V_223 [ 1 ] , V_223 [ 2 ] ,
V_223 [ 3 ] , V_223 [ 4 ] , V_223 [ 5 ] ) ;
}
V_226 = V_232 ;
F_124 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_86 -> V_208 && V_86 -> V_208 < V_226 )
V_226 = V_86 -> V_208 ;
}
F_56 ( 2 , V_3 , L_57 ) ;
V_227 = F_148 ( V_226 ) ;
F_56 ( 2 , V_3 , L_58 ) ;
F_149 () ;
F_124 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( ! V_86 -> V_208 )
continue;
V_86 -> V_208 -= V_226 - V_227 ;
if ( V_86 -> V_208 <= 0 ) {
V_86 -> V_208 = 0 ;
F_105 ( & V_86 -> V_181 ) ;
}
}
if ( F_150 () )
break;
}
V_231:
F_147 ( V_233 ) ;
F_151 ( & V_3 -> V_82 , & V_229 ) ;
if ( F_150 () )
break;
while ( F_130 ( V_3 ) )
;
F_139 ( V_3 ) ;
F_100 ( V_3 ) ;
}
return 0 ;
}
static void F_152 ( struct V_2 * V_3 )
{
F_153 ( V_3 , L_59 ,
V_3 -> V_5 . V_234 ? L_60 : L_61 ,
V_3 -> V_5 . V_6 >> 2 ,
V_3 -> V_5 . V_235 == 8 ? '1' : '2' ) ;
}
static int F_154 ( struct V_2 * V_3 , struct V_115 * V_116 , int V_236 , int V_237 )
{
memset ( V_116 -> V_130 , 0 , sizeof( V_116 -> V_130 ) ) ;
V_116 -> V_130 [ 0 ] = V_238 ;
V_116 -> V_130 [ 2 ] = V_236 | ( V_237 << 6 ) ;
V_116 -> V_130 [ 7 ] = V_116 -> V_126 >> 8 ;
V_116 -> V_130 [ 8 ] = V_116 -> V_126 & 0xff ;
V_116 -> V_121 = V_239 ;
return F_83 ( V_3 , V_116 ) ;
}
static int F_155 ( struct V_2 * V_3 , struct V_115 * V_116 )
{
memset ( V_116 -> V_130 , 0 , sizeof( V_116 -> V_130 ) ) ;
memset ( V_116 -> V_127 , 0 , 2 ) ;
V_116 -> V_130 [ 0 ] = V_240 ;
V_116 -> V_130 [ 1 ] = 0x10 ;
V_116 -> V_130 [ 7 ] = V_116 -> V_126 >> 8 ;
V_116 -> V_130 [ 8 ] = V_116 -> V_126 & 0xff ;
V_116 -> V_121 = V_122 ;
return F_83 ( V_3 , V_116 ) ;
}
static int F_156 ( struct V_2 * V_3 , T_6 * V_241 )
{
struct V_115 V_116 ;
int V_61 ;
F_95 ( & V_116 , V_241 , sizeof( * V_241 ) , V_239 ) ;
V_116 . V_130 [ 0 ] = V_242 ;
V_116 . V_130 [ 8 ] = V_116 . V_126 = 2 ;
V_116 . V_136 = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
return V_61 ;
V_116 . V_126 = F_157 ( V_241 -> V_243 ) +
sizeof( V_241 -> V_243 ) ;
if ( V_116 . V_126 > sizeof( T_6 ) )
V_116 . V_126 = sizeof( T_6 ) ;
V_116 . V_130 [ 8 ] = V_116 . V_126 ;
return F_83 ( V_3 , & V_116 ) ;
}
static int F_158 ( struct V_2 * V_3 , T_7 V_244 , T_4 type , T_8 * V_245 )
{
struct V_115 V_116 ;
int V_61 ;
F_95 ( & V_116 , V_245 , 8 , V_239 ) ;
V_116 . V_130 [ 0 ] = V_246 ;
V_116 . V_130 [ 1 ] = type & 3 ;
V_116 . V_130 [ 4 ] = ( V_244 & 0xff00 ) >> 8 ;
V_116 . V_130 [ 5 ] = V_244 & 0xff ;
V_116 . V_130 [ 8 ] = 8 ;
V_116 . V_136 = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
return V_61 ;
V_116 . V_126 = F_157 ( V_245 -> V_247 ) +
sizeof( V_245 -> V_247 ) ;
if ( V_116 . V_126 > sizeof( T_8 ) )
V_116 . V_126 = sizeof( T_8 ) ;
V_116 . V_130 [ 8 ] = V_116 . V_126 ;
return F_83 ( V_3 , & V_116 ) ;
}
static T_5 int F_159 ( struct V_2 * V_3 ,
long * V_248 )
{
T_6 V_241 ;
T_8 V_245 ;
T_9 V_249 ;
int V_61 = - 1 ;
if ( ( V_61 = F_156 ( V_3 , & V_241 ) ) )
return V_61 ;
V_249 = ( V_241 . V_250 << 8 ) | V_241 . V_251 ;
if ( ( V_61 = F_158 ( V_3 , V_249 , 1 , & V_245 ) ) )
return V_61 ;
if ( V_245 . V_252 ) {
V_249 -- ;
if ( ( V_61 = F_158 ( V_3 , V_249 , 1 , & V_245 ) ) )
return V_61 ;
}
if ( V_245 . V_253 ) {
* V_248 = F_160 ( V_245 . V_254 ) ;
} else {
* V_248 = F_160 ( V_245 . V_255 ) +
F_160 ( V_245 . V_256 ) ;
if ( V_245 . V_257 )
* V_248 -= ( F_160 ( V_245 . V_257 ) + 7 ) ;
}
return 0 ;
}
static T_5 int F_161 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
struct V_144 V_145 ;
T_10 * V_258 ;
char V_127 [ 128 ] ;
int V_61 , V_6 ;
if ( ( V_3 -> V_259 == 0x1a ) || ( V_3 -> V_259 == 0x12 ) )
return 0 ;
memset ( V_127 , 0 , sizeof( V_127 ) ) ;
F_95 ( & V_116 , V_127 , sizeof( * V_258 ) , V_239 ) ;
V_116 . V_145 = & V_145 ;
if ( ( V_61 = F_154 ( V_3 , & V_116 , V_260 , 0 ) ) ) {
F_92 ( V_3 , & V_116 ) ;
return V_61 ;
}
V_6 = 2 + ( ( V_127 [ 0 ] << 8 ) | ( V_127 [ 1 ] & 0xff ) ) ;
V_3 -> V_261 = ( V_127 [ 6 ] << 8 ) | ( V_127 [ 7 ] & 0xff ) ;
if ( V_6 > sizeof( V_127 ) )
V_6 = sizeof( V_127 ) ;
F_95 ( & V_116 , V_127 , V_6 , V_239 ) ;
V_116 . V_145 = & V_145 ;
if ( ( V_61 = F_154 ( V_3 , & V_116 , V_260 , 0 ) ) ) {
F_92 ( V_3 , & V_116 ) ;
return V_61 ;
}
V_258 = ( T_10 * ) & V_127 [ sizeof( struct V_262 ) + V_3 -> V_261 ] ;
V_258 -> V_234 = V_3 -> V_5 . V_234 ;
V_258 -> V_263 = V_3 -> V_5 . V_263 ;
V_258 -> V_264 = V_3 -> V_5 . V_264 ;
V_258 -> V_265 = V_3 -> V_5 . V_235 ;
V_258 -> V_266 = 0 ;
#ifdef F_162
V_258 -> V_267 = 7 ;
V_258 -> V_268 = 1 ;
#endif
if ( V_258 -> V_265 == V_269 ) {
V_258 -> V_270 = 0 ;
V_258 -> V_271 = 0x20 ;
} else if ( V_258 -> V_265 == V_272 ) {
V_258 -> V_270 = 0x20 ;
V_258 -> V_271 = 8 ;
#if 0
wp->mcn[0] = 0x80;
memcpy(&wp->mcn[1], PACKET_MCN, sizeof(wp->mcn) - 1);
#endif
} else {
F_93 ( V_3 , L_62 , V_258 -> V_265 ) ;
return 1 ;
}
V_258 -> V_273 = F_163 ( V_3 -> V_5 . V_6 >> 2 ) ;
V_116 . V_126 = V_116 . V_130 [ 8 ] = V_6 ;
if ( ( V_61 = F_155 ( V_3 , & V_116 ) ) ) {
F_92 ( V_3 , & V_116 ) ;
return V_61 ;
}
F_152 ( V_3 ) ;
return 0 ;
}
static int F_164 ( struct V_2 * V_3 , T_8 * V_245 )
{
switch ( V_3 -> V_259 ) {
case 0x1a :
case 0x12 :
return 1 ;
default:
break;
}
if ( ! V_245 -> V_274 || ! V_245 -> V_234 )
return 0 ;
if ( V_245 -> V_275 == 0 && V_245 -> V_252 == 0 )
return 1 ;
if ( V_245 -> V_275 == 0 && V_245 -> V_252 == 1 )
return 1 ;
if ( V_245 -> V_275 == 1 && V_245 -> V_252 == 0 )
return 1 ;
F_93 ( V_3 , L_63 , V_245 -> V_275 , V_245 -> V_252 , V_245 -> V_274 ) ;
return 0 ;
}
static int F_165 ( struct V_2 * V_3 , T_6 * V_241 )
{
switch ( V_3 -> V_259 ) {
case 0x0a :
case 0xffff :
break;
case 0x1a :
case 0x13 :
case 0x12 :
return 1 ;
default:
F_56 ( 2 , V_3 , L_64 ,
V_3 -> V_259 ) ;
return 0 ;
}
if ( V_241 -> V_276 == 0xff ) {
F_166 ( V_3 , L_65 ) ;
return 0 ;
}
if ( V_241 -> V_276 != 0x20 && V_241 -> V_276 != 0 ) {
F_93 ( V_3 , L_66 , V_241 -> V_276 ) ;
return 0 ;
}
if ( V_241 -> V_277 == 0 ) {
F_166 ( V_3 , L_67 ) ;
return 0 ;
}
if ( V_241 -> V_278 == V_279 ) {
F_93 ( V_3 , L_68 ) ;
return 0 ;
}
return 1 ;
}
static T_5 int F_167 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
unsigned char V_54 [ 12 ] ;
T_6 V_241 ;
T_8 V_245 ;
int V_61 , V_244 ;
F_95 ( & V_116 , V_54 , sizeof( V_54 ) , V_239 ) ;
V_116 . V_130 [ 0 ] = V_280 ;
V_116 . V_130 [ 8 ] = 8 ;
V_61 = F_83 ( V_3 , & V_116 ) ;
V_3 -> V_259 = V_61 ? 0xffff : V_54 [ 6 ] << 8 | V_54 [ 7 ] ;
memset ( & V_241 , 0 , sizeof( T_6 ) ) ;
memset ( & V_245 , 0 , sizeof( T_8 ) ) ;
if ( ( V_61 = F_156 ( V_3 , & V_241 ) ) ) {
F_93 ( V_3 , L_69 ) ;
return V_61 ;
}
if ( ! F_165 ( V_3 , & V_241 ) )
return - V_281 ;
V_3 -> type = V_241 . V_277 ? V_282 : V_283 ;
V_244 = 1 ;
if ( ( V_61 = F_158 ( V_3 , V_244 , 1 , & V_245 ) ) ) {
F_93 ( V_3 , L_70 ) ;
return V_61 ;
}
if ( ! F_164 ( V_3 , & V_245 ) ) {
F_93 ( V_3 , L_71 ) ;
return - V_281 ;
}
V_3 -> V_5 . V_6 = F_160 ( V_245 . V_284 ) << 2 ;
if ( V_3 -> V_5 . V_6 == 0 ) {
F_166 ( V_3 , L_72 ) ;
return - V_285 ;
}
if ( V_3 -> V_5 . V_6 > V_286 ) {
F_93 ( V_3 , L_73 ) ;
return - V_281 ;
}
V_3 -> V_5 . V_234 = V_245 . V_234 ;
V_3 -> V_4 = ( F_160 ( V_245 . V_255 ) << 2 ) & ( V_3 -> V_5 . V_6 - 1 ) ;
if ( V_245 . V_287 ) {
V_3 -> V_288 = F_160 ( V_245 . V_289 ) ;
F_110 ( V_290 , & V_3 -> V_167 ) ;
}
if ( V_245 . V_253 ) {
V_3 -> V_291 = F_160 ( V_245 . V_254 ) ;
F_110 ( V_292 , & V_3 -> V_167 ) ;
} else {
V_3 -> V_291 = 0xffffffff ;
F_110 ( V_292 , & V_3 -> V_167 ) ;
}
V_3 -> V_5 . V_293 = 7 ;
V_3 -> V_5 . V_264 = 0 ;
V_3 -> V_5 . V_263 = V_245 . V_263 ;
switch ( V_245 . V_294 ) {
case V_295 :
V_3 -> V_5 . V_235 = V_269 ;
break;
case V_296 :
V_3 -> V_5 . V_235 = V_272 ;
break;
default:
F_93 ( V_3 , L_74 ) ;
return - V_281 ;
}
return 0 ;
}
static T_5 int F_168 ( struct V_2 * V_3 ,
int V_297 )
{
struct V_115 V_116 ;
struct V_144 V_145 ;
unsigned char V_54 [ 64 ] ;
int V_61 ;
F_95 ( & V_116 , V_54 , sizeof( V_54 ) , V_239 ) ;
V_116 . V_145 = & V_145 ;
V_116 . V_126 = V_3 -> V_261 + 12 ;
V_116 . V_136 = 1 ;
if ( ( V_61 = F_154 ( V_3 , & V_116 , V_298 , 0 ) ) )
return V_61 ;
V_54 [ V_3 -> V_261 + 10 ] |= ( ! ! V_297 << 2 ) ;
V_116 . V_126 = V_116 . V_130 [ 8 ] = 2 + ( ( V_54 [ 0 ] << 8 ) | ( V_54 [ 1 ] & 0xff ) ) ;
V_61 = F_155 ( V_3 , & V_116 ) ;
if ( V_61 ) {
F_93 ( V_3 , L_75 ) ;
F_92 ( V_3 , & V_116 ) ;
} else if ( ! V_61 && V_297 )
F_166 ( V_3 , L_76 ) ;
return V_61 ;
}
static int F_169 ( struct V_2 * V_3 , int V_299 )
{
struct V_115 V_116 ;
F_95 ( & V_116 , NULL , 0 , V_149 ) ;
V_116 . V_130 [ 0 ] = V_300 ;
V_116 . V_130 [ 4 ] = V_299 ? 1 : 0 ;
return F_83 ( V_3 , & V_116 ) ;
}
static T_5 int F_170 ( struct V_2 * V_3 ,
unsigned * V_151 )
{
struct V_115 V_116 ;
struct V_144 V_145 ;
unsigned char V_54 [ 256 + 18 ] ;
unsigned char * V_301 ;
int V_61 , V_4 ;
V_301 = & V_54 [ sizeof( struct V_262 ) + V_3 -> V_261 ] ;
F_95 ( & V_116 , V_54 , sizeof( V_54 ) , V_302 ) ;
V_116 . V_145 = & V_145 ;
V_61 = F_154 ( V_3 , & V_116 , V_303 , 0 ) ;
if ( V_61 ) {
V_116 . V_126 = V_3 -> V_261 + V_301 [ 1 ] + 2 +
sizeof( struct V_262 ) ;
V_61 = F_154 ( V_3 , & V_116 , V_303 , 0 ) ;
if ( V_61 ) {
F_92 ( V_3 , & V_116 ) ;
return V_61 ;
}
}
V_4 = 20 ;
if ( V_301 [ 1 ] >= 28 )
V_4 = 28 ;
if ( V_301 [ 1 ] >= 30 ) {
int V_304 = ( V_301 [ 30 ] << 8 ) + V_301 [ 31 ] ;
if ( V_304 > 0 )
V_4 = 34 ;
}
* V_151 = ( V_301 [ V_4 ] << 8 ) | V_301 [ V_4 + 1 ] ;
return 0 ;
}
static T_5 int F_171 ( struct V_2 * V_3 ,
unsigned * V_305 )
{
struct V_115 V_116 ;
struct V_144 V_145 ;
unsigned char V_54 [ 64 ] ;
unsigned int V_6 , V_306 , V_307 ;
int V_61 ;
F_95 ( & V_116 , V_54 , 2 , V_239 ) ;
V_116 . V_145 = & V_145 ;
V_116 . V_130 [ 0 ] = V_308 ;
V_116 . V_130 [ 1 ] = 2 ;
V_116 . V_130 [ 2 ] = 4 ;
V_116 . V_130 [ 8 ] = 2 ;
V_61 = F_83 ( V_3 , & V_116 ) ;
if ( V_61 ) {
F_92 ( V_3 , & V_116 ) ;
return V_61 ;
}
V_6 = ( ( unsigned int ) V_54 [ 0 ] << 8 ) + V_54 [ 1 ] + 2 ;
if ( V_6 > sizeof( V_54 ) )
V_6 = sizeof( V_54 ) ;
F_95 ( & V_116 , V_54 , V_6 , V_239 ) ;
V_116 . V_145 = & V_145 ;
V_116 . V_130 [ 0 ] = V_308 ;
V_116 . V_130 [ 1 ] = 2 ;
V_116 . V_130 [ 2 ] = 4 ;
V_116 . V_130 [ 8 ] = V_6 ;
V_61 = F_83 ( V_3 , & V_116 ) ;
if ( V_61 ) {
F_92 ( V_3 , & V_116 ) ;
return V_61 ;
}
if ( ! ( V_54 [ 6 ] & 0x40 ) ) {
F_166 ( V_3 , L_77 ) ;
return 1 ;
}
if ( ! ( V_54 [ 6 ] & 0x4 ) ) {
F_166 ( V_3 , L_78 ) ;
return 1 ;
}
V_306 = ( V_54 [ 6 ] >> 3 ) & 0x7 ;
V_307 = V_54 [ 16 ] & 0xf ;
switch ( V_306 ) {
case 0 :
* V_305 = V_309 [ V_307 ] ;
break;
case 1 :
* V_305 = V_310 [ V_307 ] ;
break;
case 2 :
* V_305 = V_311 [ V_307 ] ;
break;
default:
F_166 ( V_3 , L_79 , V_306 ) ;
return 1 ;
}
if ( * V_305 ) {
F_153 ( V_3 , L_80 , * V_305 ) ;
return 0 ;
} else {
F_166 ( V_3 , L_81 , V_307 , V_306 ) ;
return 1 ;
}
}
static T_5 int F_172 ( struct V_2 * V_3 )
{
struct V_115 V_116 ;
struct V_144 V_145 ;
int V_61 ;
F_56 ( 2 , V_3 , L_82 ) ;
F_95 ( & V_116 , NULL , 0 , V_149 ) ;
V_116 . V_145 = & V_145 ;
V_116 . V_132 = 60 * V_133 ;
V_116 . V_130 [ 0 ] = V_312 ;
V_116 . V_130 [ 1 ] = 1 ;
if ( ( V_61 = F_83 ( V_3 , & V_116 ) ) )
F_92 ( V_3 , & V_116 ) ;
return V_61 ;
}
static int F_173 ( struct V_2 * V_3 )
{
int V_61 ;
unsigned int V_151 , V_313 , V_152 ;
if ( ( V_61 = F_167 ( V_3 ) ) ) {
F_56 ( 2 , V_3 , L_83 ) ;
return V_61 ;
}
if ( ( V_61 = F_161 ( V_3 ) ) ) {
F_56 ( 1 , V_3 , L_84 ) ;
return - V_141 ;
}
F_168 ( V_3 , V_314 ) ;
if ( ( V_61 = F_170 ( V_3 , & V_151 ) ) )
V_151 = 16 * 177 ;
switch ( V_3 -> V_259 ) {
case 0x13 :
case 0x1a :
case 0x12 :
F_56 ( 1 , V_3 , L_85 , V_151 ) ;
break;
default:
if ( ( V_61 = F_171 ( V_3 , & V_313 ) ) )
V_313 = 16 ;
V_151 = F_16 ( V_151 , V_313 * 177 ) ;
F_56 ( 1 , V_3 , L_86 , V_151 / 176 ) ;
break;
}
V_152 = V_151 ;
if ( ( V_61 = F_96 ( V_3 , V_151 , V_152 ) ) ) {
F_56 ( 1 , V_3 , L_87 ) ;
return - V_141 ;
}
V_3 -> V_151 = V_151 ;
V_3 -> V_152 = V_152 ;
if ( ( V_61 = F_172 ( V_3 ) ) ) {
F_56 ( 1 , V_3 , L_88 ) ;
}
return 0 ;
}
static int F_174 ( struct V_2 * V_3 , T_11 V_315 )
{
int V_61 ;
long V_316 ;
struct V_117 * V_118 ;
F_175 ( V_3 -> V_52 -> V_53 ) ;
if ( ( V_61 = F_176 ( V_3 -> V_52 , V_317 | V_318 , V_3 ) ) )
goto V_128;
if ( ( V_61 = F_159 ( V_3 , & V_316 ) ) ) {
F_93 ( V_3 , L_89 ) ;
goto V_319;
}
F_177 ( V_3 -> V_204 , V_316 << 2 ) ;
F_177 ( V_3 -> V_52 -> V_139 , V_316 << 2 ) ;
F_178 ( V_3 -> V_52 , ( V_320 ) V_316 << 11 ) ;
V_118 = F_84 ( V_3 -> V_52 ) ;
if ( V_315 ) {
if ( ( V_61 = F_173 ( V_3 ) ) )
goto V_319;
F_179 ( V_118 -> V_321 ) ;
F_180 ( V_118 , V_3 -> V_5 . V_6 ) ;
F_181 ( V_118 -> V_321 ) ;
F_110 ( V_322 , & V_3 -> V_167 ) ;
} else {
F_96 ( V_3 , V_164 , V_164 ) ;
F_109 ( V_322 , & V_3 -> V_167 ) ;
}
if ( ( V_61 = F_107 ( V_3 , V_118 ) ) )
goto V_319;
if ( V_315 ) {
if ( ! F_71 ( V_3 , V_323 ) ) {
F_93 ( V_3 , L_90 ) ;
V_61 = - V_62 ;
goto V_319;
}
F_153 ( V_3 , L_91 , V_316 << 1 ) ;
}
return 0 ;
V_319:
F_182 ( V_3 -> V_52 , V_317 | V_318 ) ;
V_128:
return V_61 ;
}
static void F_183 ( struct V_2 * V_3 , int V_324 )
{
if ( V_324 && F_94 ( V_3 ) )
F_56 ( 1 , V_3 , L_92 ) ;
F_169 ( V_3 , 0 ) ;
F_96 ( V_3 , V_164 , V_164 ) ;
F_182 ( V_3 -> V_52 , V_317 | V_318 ) ;
F_67 ( V_3 ) ;
}
static struct V_2 * F_184 ( unsigned int V_325 )
{
if ( V_325 >= V_49 )
return NULL ;
return V_50 [ V_325 ] ;
}
static int F_185 ( struct V_326 * V_52 , T_11 V_327 )
{
struct V_2 * V_3 = NULL ;
int V_61 ;
F_186 ( & V_328 ) ;
F_186 ( & V_47 ) ;
V_3 = F_184 ( F_28 ( V_52 -> V_53 ) ) ;
if ( ! V_3 ) {
V_61 = - V_59 ;
goto V_128;
}
F_53 ( V_3 -> V_329 < 0 ) ;
V_3 -> V_329 ++ ;
if ( V_3 -> V_329 > 1 ) {
if ( ( V_327 & V_330 ) &&
! F_135 ( V_322 , & V_3 -> V_167 ) ) {
V_61 = - V_331 ;
goto V_332;
}
} else {
V_61 = F_174 ( V_3 , V_327 & V_330 ) ;
if ( V_61 )
goto V_332;
F_187 ( V_52 , V_165 ) ;
}
F_29 ( & V_47 ) ;
F_29 ( & V_328 ) ;
return 0 ;
V_332:
V_3 -> V_329 -- ;
V_128:
F_29 ( & V_47 ) ;
F_29 ( & V_328 ) ;
return V_61 ;
}
static void F_188 ( struct V_333 * V_204 , T_11 V_327 )
{
struct V_2 * V_3 = V_204 -> V_334 ;
F_186 ( & V_328 ) ;
F_186 ( & V_47 ) ;
V_3 -> V_329 -- ;
F_53 ( V_3 -> V_329 < 0 ) ;
if ( V_3 -> V_329 == 0 ) {
int V_324 = F_135 ( V_322 , & V_3 -> V_167 ) ;
F_183 ( V_3 , V_324 ) ;
}
F_29 ( & V_47 ) ;
F_29 ( & V_328 ) ;
}
static void F_189 ( struct V_95 * V_95 , int V_177 )
{
struct V_335 * V_336 = V_95 -> V_178 ;
struct V_2 * V_3 = V_336 -> V_3 ;
F_64 ( V_95 ) ;
F_137 ( V_336 -> V_95 , V_177 ) ;
F_78 ( V_336 , V_337 ) ;
F_52 ( V_3 ) ;
}
static void F_190 ( struct V_2 * V_3 , struct V_95 * V_95 )
{
struct V_95 * V_338 = F_191 ( V_95 , V_339 ) ;
struct V_335 * V_336 = F_192 ( V_337 , V_339 ) ;
V_336 -> V_3 = V_3 ;
V_336 -> V_95 = V_95 ;
V_338 -> V_189 = V_3 -> V_52 ;
V_338 -> V_178 = V_336 ;
V_338 -> V_190 = F_189 ;
V_3 -> V_22 . V_26 += F_193 ( V_95 ) ;
F_97 ( V_3 , V_338 ) ;
}
static void F_194 ( struct V_117 * V_118 , struct V_95 * V_95 )
{
struct V_2 * V_3 = V_118 -> V_340 ;
T_1 V_192 ;
struct V_83 * V_86 ;
int V_341 , V_342 ;
struct V_104 * V_105 ;
V_192 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
F_12 ( & V_3 -> V_78 . V_211 ) ;
V_342 = 0 ;
F_124 (pkt, &pd->cdrw.pkt_active_list, list) {
if ( V_86 -> V_1 == V_192 ) {
F_12 ( & V_86 -> V_28 ) ;
if ( ( V_86 -> V_194 == V_210 ) ||
( V_86 -> V_194 == V_217 ) ) {
F_99 ( & V_86 -> V_94 , V_95 ) ;
V_86 -> V_203 +=
V_95 -> V_111 . V_162 / V_165 ;
if ( ( V_86 -> V_203 >= V_86 -> V_84 ) &&
( V_86 -> V_194 == V_210 ) ) {
F_105 ( & V_86 -> V_181 ) ;
F_58 ( & V_3 -> V_82 ) ;
}
F_13 ( & V_86 -> V_28 ) ;
F_13 ( & V_3 -> V_78 . V_211 ) ;
return;
} else {
V_342 = 1 ;
}
F_13 ( & V_86 -> V_28 ) ;
}
}
F_13 ( & V_3 -> V_78 . V_211 ) ;
F_12 ( & V_3 -> V_28 ) ;
if ( V_3 -> V_31 > 0
&& V_3 -> V_29 >= V_3 -> V_31 ) {
F_195 ( & V_118 -> V_206 , V_207 ) ;
do {
F_13 ( & V_3 -> V_28 ) ;
F_196 ( V_207 , V_133 ) ;
F_12 ( & V_3 -> V_28 ) ;
} while( V_3 -> V_29 > V_3 -> V_30 );
}
F_13 ( & V_3 -> V_28 ) ;
V_105 = F_192 ( V_3 -> V_108 , V_339 ) ;
V_105 -> V_95 = V_95 ;
F_12 ( & V_3 -> V_28 ) ;
F_53 ( V_3 -> V_29 < 0 ) ;
V_341 = ( V_3 -> V_29 == 0 ) ;
F_80 ( V_3 , V_105 ) ;
F_13 ( & V_3 -> V_28 ) ;
F_57 ( & V_3 -> V_200 , 1 ) ;
if ( V_341 ) {
F_58 ( & V_3 -> V_82 ) ;
} else if ( ! F_68 ( & V_3 -> V_78 . V_100 ) && ! V_342 ) {
F_58 ( & V_3 -> V_82 ) ;
}
}
static void F_197 ( struct V_117 * V_118 , struct V_95 * V_95 )
{
struct V_2 * V_3 ;
char V_343 [ V_344 ] ;
struct V_95 * V_345 ;
V_3 = V_118 -> V_340 ;
if ( ! V_3 ) {
F_38 ( L_93 ,
F_198 ( V_95 -> V_189 , V_343 ) ) ;
goto V_346;
}
F_56 ( 2 , V_3 , L_94 ,
( unsigned long long ) V_95 -> V_111 . V_112 ,
( unsigned long long ) F_104 ( V_95 ) ) ;
if ( F_98 ( V_95 ) == V_124 ) {
F_190 ( V_3 , V_95 ) ;
return;
}
if ( ! F_135 ( V_322 , & V_3 -> V_167 ) ) {
F_166 ( V_3 , L_95 ,
( unsigned long long ) V_95 -> V_111 . V_112 ) ;
goto V_346;
}
if ( ! V_95 -> V_111 . V_162 || ( V_95 -> V_111 . V_162 % V_165 ) ) {
F_93 ( V_3 , L_96 ) ;
goto V_346;
}
F_199 ( V_118 , & V_95 ) ;
do {
T_1 V_192 = F_1 ( V_95 -> V_111 . V_112 , V_3 ) ;
T_1 V_347 = F_1 ( F_104 ( V_95 ) - 1 , V_3 ) ;
if ( V_347 != V_192 ) {
F_53 ( V_347 != V_192 + V_3 -> V_5 . V_6 ) ;
V_345 = F_200 ( V_95 , V_347 -
V_95 -> V_111 . V_112 ,
V_339 , V_348 ) ;
F_201 ( V_345 , V_95 ) ;
} else {
V_345 = V_95 ;
}
F_194 ( V_118 , V_345 ) ;
} while ( V_345 != V_95 );
return;
V_346:
F_202 ( V_95 ) ;
}
static int F_203 ( struct V_117 * V_118 , struct V_349 * V_350 ,
struct V_169 * V_170 )
{
struct V_2 * V_3 = V_118 -> V_340 ;
T_1 V_192 = F_1 ( V_350 -> V_112 , V_3 ) ;
int V_351 = ( ( V_350 -> V_112 - V_192 ) << 9 ) + V_350 -> V_162 ;
int V_352 = ( V_3 -> V_5 . V_6 << 9 ) - V_351 ;
int V_353 ;
V_353 = V_168 - V_350 -> V_162 ;
V_352 = F_15 ( V_352 , V_353 ) ;
F_53 ( V_352 < 0 ) ;
return V_352 ;
}
static void F_204 ( struct V_2 * V_3 )
{
struct V_117 * V_118 = V_3 -> V_204 -> V_205 ;
F_205 ( V_118 , F_197 ) ;
F_206 ( V_118 , V_165 ) ;
F_180 ( V_118 , V_286 ) ;
F_207 ( V_118 , F_203 ) ;
V_118 -> V_340 = V_3 ;
}
static int F_42 ( struct V_68 * V_69 , void * V_13 )
{
struct V_2 * V_3 = V_69 -> V_354 ;
char * V_355 ;
char V_356 [ V_344 ] ;
int V_223 [ V_224 ] ;
F_208 ( V_69 , L_97 , V_3 -> V_8 ,
F_198 ( V_3 -> V_52 , V_356 ) ) ;
F_208 ( V_69 , L_98 ) ;
F_208 ( V_69 , L_99 , V_3 -> V_5 . V_6 / 2 ) ;
if ( V_3 -> V_5 . V_264 == 0 )
V_355 = L_100 ;
else
V_355 = L_101 ;
F_208 ( V_69 , L_102 , V_355 ) ;
F_208 ( V_69 , L_103 , V_3 -> V_5 . V_234 ? L_60 : L_61 ) ;
F_208 ( V_69 , L_104 , V_3 -> V_5 . V_293 ) ;
F_208 ( V_69 , L_105 , V_3 -> V_5 . V_263 ) ;
if ( V_3 -> V_5 . V_235 == V_269 )
V_355 = L_106 ;
else if ( V_3 -> V_5 . V_235 == V_272 )
V_355 = L_107 ;
else
V_355 = L_101 ;
F_208 ( V_69 , L_108 , V_355 ) ;
F_208 ( V_69 , L_109 ) ;
F_208 ( V_69 , L_110 , V_3 -> V_22 . V_23 ) ;
F_208 ( V_69 , L_111 , V_3 -> V_22 . V_24 ) ;
F_208 ( V_69 , L_112 , V_3 -> V_22 . V_25 >> 1 ) ;
F_208 ( V_69 , L_113 , V_3 -> V_22 . V_27 >> 1 ) ;
F_208 ( V_69 , L_114 , V_3 -> V_22 . V_26 >> 1 ) ;
F_208 ( V_69 , L_115 ) ;
F_208 ( V_69 , L_116 , V_3 -> V_329 ) ;
F_208 ( V_69 , L_117 , V_3 -> V_167 ) ;
F_208 ( V_69 , L_118 , V_3 -> V_152 ) ;
F_208 ( V_69 , L_119 , V_3 -> V_151 ) ;
F_208 ( V_69 , L_120 , V_3 -> V_4 ) ;
F_208 ( V_69 , L_121 , V_3 -> V_261 ) ;
F_208 ( V_69 , L_122 ) ;
F_208 ( V_69 , L_123 , V_3 -> V_29 ) ;
F_208 ( V_69 , L_124 , F_54 ( & V_3 -> V_78 . V_79 ) ) ;
F_208 ( V_69 , L_125 , ( unsigned long long ) V_3 -> V_201 ) ;
F_141 ( V_3 , V_223 ) ;
F_208 ( V_69 , L_126 ,
V_223 [ 0 ] , V_223 [ 1 ] , V_223 [ 2 ] , V_223 [ 3 ] , V_223 [ 4 ] , V_223 [ 5 ] ) ;
F_208 ( V_69 , L_127 ,
V_3 -> V_30 ,
V_3 -> V_31 ) ;
return 0 ;
}
static int F_209 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
return F_44 ( V_71 , F_42 , F_210 ( V_70 ) ) ;
}
static int F_211 ( struct V_2 * V_3 , T_12 V_37 )
{
int V_85 ;
int V_61 = 0 ;
char V_343 [ V_344 ] ;
struct V_326 * V_52 ;
if ( V_3 -> V_51 == V_37 ) {
F_93 ( V_3 , L_128 ) ;
return - V_331 ;
}
for ( V_85 = 0 ; V_85 < V_49 ; V_85 ++ ) {
struct V_2 * V_357 = V_50 [ V_85 ] ;
if ( ! V_357 )
continue;
if ( V_357 -> V_52 -> V_53 == V_37 ) {
F_93 ( V_3 , L_129 ,
F_198 ( V_357 -> V_52 , V_343 ) ) ;
return - V_331 ;
}
if ( V_357 -> V_51 == V_37 ) {
F_93 ( V_3 , L_130 ) ;
return - V_331 ;
}
}
V_52 = F_175 ( V_37 ) ;
if ( ! V_52 )
return - V_62 ;
V_61 = F_176 ( V_52 , V_317 | V_358 , NULL ) ;
if ( V_61 )
return V_61 ;
F_212 ( V_58 ) ;
V_3 -> V_52 = V_52 ;
F_187 ( V_52 , V_165 ) ;
F_204 ( V_3 ) ;
F_57 ( & V_3 -> V_78 . V_79 , 0 ) ;
V_3 -> V_78 . V_359 = F_213 ( F_142 , V_3 , L_1 , V_3 -> V_8 ) ;
if ( F_21 ( V_3 -> V_78 . V_359 ) ) {
F_93 ( V_3 , L_131 ) ;
V_61 = - V_62 ;
goto V_360;
}
F_214 ( V_3 -> V_8 , 0 , V_361 , & V_362 , V_3 ) ;
F_56 ( 1 , V_3 , L_132 , F_198 ( V_52 , V_343 ) ) ;
return 0 ;
V_360:
F_182 ( V_52 , V_317 | V_358 ) ;
F_33 ( V_58 ) ;
return V_61 ;
}
static int F_215 ( struct V_326 * V_52 , T_11 V_327 , unsigned int V_130 , unsigned long V_363 )
{
struct V_2 * V_3 = V_52 -> V_139 -> V_334 ;
int V_61 ;
F_56 ( 2 , V_3 , L_133 ,
V_130 , F_27 ( V_52 -> V_53 ) , F_28 ( V_52 -> V_53 ) ) ;
F_186 ( & V_328 ) ;
switch ( V_130 ) {
case V_364 :
if ( V_3 -> V_329 == 1 )
F_169 ( V_3 , 0 ) ;
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
V_61 = F_216 ( V_3 -> V_52 , V_327 , V_130 , V_363 ) ;
break;
default:
F_56 ( 2 , V_3 , L_134 , V_130 ) ;
V_61 = - V_370 ;
}
F_29 ( & V_328 ) ;
return V_61 ;
}
static unsigned int F_217 ( struct V_333 * V_204 ,
unsigned int V_371 )
{
struct V_2 * V_3 = V_204 -> V_334 ;
struct V_333 * V_372 ;
if ( ! V_3 )
return 0 ;
if ( ! V_3 -> V_52 )
return 0 ;
V_372 = V_3 -> V_52 -> V_139 ;
if ( ! V_372 || ! V_372 -> V_373 -> V_374 )
return 0 ;
return V_372 -> V_373 -> V_374 ( V_372 , V_371 ) ;
}
static char * F_218 ( struct V_333 * V_375 , T_13 * V_327 )
{
return F_219 ( V_14 , L_135 , V_375 -> V_376 ) ;
}
static int F_32 ( T_12 V_37 , T_12 * V_51 )
{
int V_46 ;
int V_61 = - V_62 ;
struct V_2 * V_3 ;
struct V_333 * V_204 ;
F_26 ( & V_47 , V_48 ) ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ )
if ( ! V_50 [ V_46 ] )
break;
if ( V_46 == V_49 ) {
F_38 ( L_136 , V_49 ) ;
V_61 = - V_331 ;
goto V_377;
}
V_3 = F_3 ( sizeof( struct V_2 ) , V_14 ) ;
if ( ! V_3 )
goto V_377;
V_3 -> V_108 = F_220 ( V_378 ,
sizeof( struct V_104 ) ) ;
if ( ! V_3 -> V_108 )
goto V_360;
F_70 ( & V_3 -> V_78 . V_100 ) ;
F_70 ( & V_3 -> V_78 . V_99 ) ;
F_62 ( & V_3 -> V_78 . V_211 ) ;
F_62 ( & V_3 -> V_28 ) ;
F_62 ( & V_3 -> V_80 . V_28 ) ;
F_63 ( & V_3 -> V_80 . V_154 ) ;
F_63 ( & V_3 -> V_80 . V_155 ) ;
sprintf ( V_3 -> V_8 , V_63 L_13 , V_46 ) ;
F_221 ( & V_3 -> V_82 ) ;
V_3 -> V_107 = V_379 ;
V_3 -> V_31 = V_31 ;
V_3 -> V_30 = V_30 ;
V_204 = F_222 ( 1 ) ;
if ( ! V_204 )
goto V_360;
V_3 -> V_204 = V_204 ;
V_204 -> V_56 = V_380 ;
V_204 -> V_381 = V_46 ;
V_204 -> V_373 = & V_382 ;
V_204 -> V_167 = V_383 ;
strcpy ( V_204 -> V_376 , V_3 -> V_8 ) ;
V_204 -> V_384 = F_218 ;
V_204 -> V_334 = V_3 ;
V_204 -> V_205 = F_223 ( V_14 ) ;
if ( ! V_204 -> V_205 )
goto V_385;
V_3 -> V_51 = F_20 ( V_380 , V_46 ) ;
V_61 = F_211 ( V_3 , V_37 ) ;
if ( V_61 )
goto V_386;
V_204 -> V_387 = V_3 -> V_52 -> V_139 -> V_387 ;
V_204 -> V_388 = V_3 -> V_52 -> V_139 -> V_388 ;
F_224 ( V_204 ) ;
F_18 ( V_3 ) ;
F_45 ( V_3 ) ;
V_50 [ V_46 ] = V_3 ;
if ( V_51 )
* V_51 = V_3 -> V_51 ;
F_29 ( & V_47 ) ;
return 0 ;
V_386:
F_225 ( V_204 -> V_205 ) ;
V_385:
F_226 ( V_204 ) ;
V_360:
if ( V_3 -> V_108 )
F_227 ( V_3 -> V_108 ) ;
F_9 ( V_3 ) ;
V_377:
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
F_228 ( L_138 ) ;
V_61 = - V_285 ;
goto V_128;
}
if ( V_3 -> V_329 > 0 ) {
V_61 = - V_331 ;
goto V_128;
}
if ( ! F_21 ( V_3 -> V_78 . V_359 ) )
F_229 ( V_3 -> V_78 . V_359 ) ;
V_50 [ V_46 ] = NULL ;
F_48 ( V_3 ) ;
F_22 ( V_3 ) ;
F_182 ( V_3 -> V_52 , V_317 | V_358 ) ;
F_230 ( V_3 -> V_8 , V_361 ) ;
F_56 ( 1 , V_3 , L_139 ) ;
F_231 ( V_3 -> V_204 ) ;
F_225 ( V_3 -> V_204 -> V_205 ) ;
F_226 ( V_3 -> V_204 ) ;
F_227 ( V_3 -> V_108 ) ;
F_9 ( V_3 ) ;
F_33 ( V_58 ) ;
V_128:
F_29 ( & V_47 ) ;
return V_61 ;
}
static void F_232 ( struct V_389 * V_390 )
{
struct V_2 * V_3 ;
F_26 ( & V_47 , V_48 ) ;
V_3 = F_184 ( V_390 -> V_391 ) ;
if ( V_3 ) {
V_390 -> V_37 = F_233 ( V_3 -> V_52 -> V_53 ) ;
V_390 -> V_51 = F_233 ( V_3 -> V_51 ) ;
} else {
V_390 -> V_37 = 0 ;
V_390 -> V_51 = 0 ;
}
V_390 -> V_392 = V_49 ;
F_29 ( & V_47 ) ;
}
static long F_234 ( struct V_71 * V_71 , unsigned int V_130 , unsigned long V_363 )
{
void T_14 * V_393 = ( void T_14 * ) V_363 ;
struct V_389 V_390 ;
int V_61 = 0 ;
T_12 V_51 = 0 ;
if ( V_130 != V_394 )
return - V_370 ;
if ( F_235 ( & V_390 , V_393 , sizeof( struct V_389 ) ) )
return - V_395 ;
switch ( V_390 . V_396 ) {
case V_397 :
if ( ! F_236 ( V_398 ) )
return - V_399 ;
V_61 = F_32 ( F_237 ( V_390 . V_37 ) , & V_51 ) ;
V_390 . V_51 = F_233 ( V_51 ) ;
break;
case V_400 :
if ( ! F_236 ( V_398 ) )
return - V_399 ;
V_61 = F_35 ( F_237 ( V_390 . V_51 ) ) ;
break;
case V_401 :
F_232 ( & V_390 ) ;
break;
default:
return - V_370 ;
}
if ( F_238 ( V_393 , & V_390 , sizeof( struct V_389 ) ) )
return - V_395 ;
return V_61 ;
}
static long F_239 ( struct V_71 * V_71 , unsigned int V_130 , unsigned long V_363 )
{
return F_234 ( V_71 , V_130 , ( unsigned long ) F_240 ( V_363 ) ) ;
}
static int T_15 F_241 ( void )
{
int V_61 ;
F_242 ( & V_47 ) ;
V_337 = F_220 ( V_402 ,
sizeof( struct V_335 ) ) ;
if ( ! V_337 )
return - V_62 ;
V_61 = F_243 ( V_380 , V_63 ) ;
if ( V_61 < 0 ) {
F_38 ( L_140 ) ;
goto V_403;
}
if ( ! V_380 )
V_380 = V_61 ;
V_61 = F_36 () ;
if ( V_61 )
goto V_128;
F_50 () ;
V_61 = F_244 ( & V_404 ) ;
if ( V_61 ) {
F_38 ( L_141 ) ;
goto V_405;
}
V_361 = F_245 ( L_142 V_63 , NULL ) ;
return 0 ;
V_405:
F_51 () ;
F_39 () ;
V_128:
F_246 ( V_380 , V_63 ) ;
V_403:
F_227 ( V_337 ) ;
return V_61 ;
}
static void T_16 F_247 ( void )
{
F_230 ( L_142 V_63 , NULL ) ;
F_248 ( & V_404 ) ;
F_51 () ;
F_39 () ;
F_246 ( V_380 , V_63 ) ;
F_227 ( V_337 ) ;
}
