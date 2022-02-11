static int F_1 ( void * V_1 , int V_2 ,
T_1 V_3 , void T_2 * V_4 , int V_5 )
{
int V_6 ;
struct V_7 * V_8 ;
int V_9 ;
char * V_10 ;
const int V_11 = 256 ;
if ( V_2 ) {
F_2 () ;
return 0 ;
}
F_3 ( V_8 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_12 ;
F_3 ( V_10 , V_11 ) ;
if ( ! V_10 ) {
F_4 ( V_8 , sizeof( * V_8 ) ) ;
return - V_12 ;
}
F_5 ( V_8 ) ;
V_9 = snprintf ( V_10 , V_11 ,
L_1 ,
V_8 -> V_13 , V_8 -> V_14 ,
V_8 -> V_15 ,
V_8 -> V_16 , V_8 -> V_17 ,
V_8 -> V_18 , V_8 -> V_19 ,
V_8 -> V_20 , V_8 -> V_21 ,
V_8 -> V_22 , V_8 -> V_23 ) ;
if ( V_3 >= F_6 ( int , V_9 , strlen ( V_10 ) ) )
V_6 = 0 ;
else
V_6 = F_7 ( V_4 , V_5 ,
V_10 + V_3 , L_2 ) ;
F_4 ( V_10 , V_11 ) ;
F_4 ( V_8 , sizeof( * V_8 ) ) ;
return V_6 ;
}
static int F_8 ( struct V_24 * V_25 , int V_2 ,
void T_2 * V_4 , T_3 * V_26 , T_1 * V_27 )
{
return F_9 ( V_25 -> V_1 , V_2 , V_27 , V_4 , V_26 ,
F_1 ) ;
}
static int F_10 ( struct V_24 * V_25 , int V_2 ,
void T_2 * V_4 , T_3 * V_26 , T_1 * V_27 )
{
const int V_11 = 256 ;
char * V_10 ;
char * V_28 ;
int V_6 = 0 ;
int V_9 ;
int V_29 ;
int V_30 ;
F_11 ( sizeof( T_1 ) < 4 ) ;
V_30 = F_12 ( * V_27 ) ;
V_29 = F_13 ( * V_27 ) ;
F_14 ( ! V_2 ) ;
if ( ! * V_26 )
return 0 ;
F_3 ( V_10 , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
V_28 = V_10 ;
if ( ! * V_27 ) {
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 , L_3 ,
V_31 . V_32 ? L_4 : L_5 ) ;
F_14 ( V_10 + V_11 - V_28 > 0 ) ;
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 , L_6 ,
L_7 , L_8 , L_9 , L_10 , L_11 ) ;
F_14 ( V_10 + V_11 - V_28 > 0 ) ;
F_15 ( 0 ) ;
V_29 = ( unsigned int ) V_31 . V_33 ;
F_16 ( 0 ) ;
* V_27 = F_17 ( 0 , V_29 , 0 , V_30 ) ;
} else {
struct V_34 * V_35 ;
struct V_34 * V_36 ;
struct V_37 * V_38 = NULL ;
struct V_39 * V_40 = NULL ;
int V_41 = V_30 - 1 ;
struct V_34 * V_42 ;
int V_43 ;
F_15 ( 0 ) ;
if ( V_29 != F_18 ( V_31 . V_33 ) ) {
F_16 ( 0 ) ;
F_4 ( V_10 , V_11 ) ;
return - V_44 ;
}
for ( V_43 = 0 ; V_43 < V_45 && ! V_38 ; V_43 ++ ) {
V_42 = & V_31 . V_46 [ V_43 ] ;
V_35 = V_42 -> V_47 ;
while ( V_35 != V_42 && ! V_38 ) {
V_40 = F_19 ( V_35 , struct V_39 ,
V_48 ) ;
V_36 = V_40 -> V_49 . V_47 ;
while ( V_36 != & V_40 -> V_49 ) {
struct V_37 * V_50 ;
V_50 = F_19 ( V_36 , struct V_37 ,
V_51 ) ;
if ( ! V_41 ) {
V_38 = V_50 ;
break;
}
V_41 -- ;
V_36 = V_36 -> V_47 ;
}
V_35 = V_35 -> V_47 ;
}
}
if ( V_38 ) {
T_4 V_52 = V_40 -> V_53 ;
T_4 V_54 = V_38 -> V_55 ;
unsigned int V_56 = V_38 -> V_57 ;
T_5 V_58 = V_38 -> V_59 -> V_60 ;
int V_61 = F_20 ( V_38 ) ;
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 ,
L_12 ,
F_21 ( V_52 ) , V_54 ,
V_56 ,
V_61 ? L_13 : L_14 ,
F_22 ( V_58 ) ) ;
F_14 ( V_10 + V_11 - V_28 > 0 ) ;
}
F_16 ( 0 ) ;
}
V_9 = V_28 - V_10 ;
if ( V_9 > * V_26 ) {
V_6 = - V_62 ;
} else if ( V_9 > 0 ) {
if ( F_23 ( V_4 , V_10 , V_9 ) ) {
V_6 = - V_63 ;
} else {
V_30 += 1 ;
* V_27 = F_17 ( 0 , V_29 , 0 , V_30 ) ;
}
}
F_4 ( V_10 , V_11 ) ;
if ( ! V_6 )
* V_26 = V_9 ;
return V_6 ;
}
static int F_24 ( struct V_24 * V_25 , int V_2 ,
void T_2 * V_4 , T_3 * V_26 , T_1 * V_27 )
{
int V_6 = 0 ;
char * V_10 ;
char * V_28 ;
const int V_11 = 256 ;
int V_9 ;
int V_29 ;
int V_30 ;
V_30 = F_12 ( * V_27 ) ;
V_29 = F_13 ( * V_27 ) ;
F_14 ( ! V_2 ) ;
if ( ! * V_26 )
return 0 ;
F_3 ( V_10 , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
V_28 = V_10 ;
if ( ! * V_27 ) {
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 ,
L_15 ,
L_16 , L_17 , L_18 , L_10 ,
L_19 , L_20 , L_21 ,
L_22 , L_11 ) ;
F_14 ( V_10 + V_11 - V_28 > 0 ) ;
F_15 ( 0 ) ;
V_29 = ( unsigned int ) V_31 . V_64 ;
F_16 ( 0 ) ;
* V_27 = F_17 ( 0 , V_29 , 0 , V_30 ) ;
} else {
struct V_34 * V_36 ;
struct V_65 * V_66 = NULL ;
int V_41 = V_30 - 1 ;
F_15 ( 0 ) ;
if ( V_29 != F_18 ( V_31 . V_64 ) ) {
F_16 ( 0 ) ;
F_4 ( V_10 , V_11 ) ;
return - V_44 ;
}
V_36 = V_31 . V_67 . V_47 ;
while ( V_36 != & V_31 . V_67 ) {
struct V_65 * V_68 ;
V_68 = F_19 ( V_36 , struct V_65 , V_69 ) ;
if ( ! V_41 ) {
V_66 = V_68 ;
break;
}
V_41 -- ;
V_36 = V_36 -> V_47 ;
}
if ( V_66 ) {
T_5 V_58 = V_66 -> V_60 ;
unsigned long V_70 = F_25 () ;
unsigned long V_71 = V_66 -> V_72 ;
int V_73 = V_66 -> V_74 ;
int V_75 = V_66 -> V_76 ;
int V_77 = V_66 -> V_78 ;
int V_61 = V_66 -> V_79 ;
int V_80 = ! V_66 -> V_81 ;
int V_82 = F_26 ( F_27 ( V_70 ,
V_66 -> V_83 ) ) ;
int V_84 = 0 ;
struct V_37 * V_85 ;
if ( ( V_66 -> V_86 &
V_87 ) ) {
F_28 (rtr, &peer->lp_routes,
lr_gwlist) {
if ( V_85 -> V_88 ) {
V_84 = V_85 -> V_88 ;
break;
}
}
}
if ( ! V_71 )
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 ,
L_23 ,
V_73 , V_75 , V_77 ,
V_61 ? L_13 : L_14 , V_82 ,
V_80 , L_24 , V_84 ,
F_22 ( V_58 ) ) ;
else
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 ,
L_25 ,
V_73 , V_75 , V_77 ,
V_61 ? L_13 : L_14 , V_82 ,
V_80 ,
F_26 ( F_27 ( V_71 , V_70 ) ) ,
V_84 , F_22 ( V_58 ) ) ;
F_14 ( V_10 + V_11 - V_28 > 0 ) ;
}
F_16 ( 0 ) ;
}
V_9 = V_28 - V_10 ;
if ( V_9 > * V_26 ) {
V_6 = - V_62 ;
} else if ( V_9 > 0 ) {
if ( F_23 ( V_4 , V_10 , V_9 ) ) {
V_6 = - V_63 ;
} else {
V_30 += 1 ;
* V_27 = F_17 ( 0 , V_29 , 0 , V_30 ) ;
}
}
F_4 ( V_10 , V_11 ) ;
if ( ! V_6 )
* V_26 = V_9 ;
return V_6 ;
}
static int F_29 ( struct V_24 * V_25 , int V_2 ,
void T_2 * V_4 , T_3 * V_26 , T_1 * V_27 )
{
const int V_11 = 256 ;
struct V_89 * V_90 ;
char * V_10 ;
char * V_28 ;
int V_91 = F_30 ( * V_27 ) ;
int V_29 = F_13 ( * V_27 ) ;
int V_92 = F_31 ( * V_27 ) ;
int V_93 = F_12 ( * V_27 ) ;
int V_6 = 0 ;
int V_9 ;
F_11 ( V_94 < V_95 ) ;
F_14 ( ! V_2 ) ;
if ( ! * V_26 )
return 0 ;
if ( V_91 >= V_96 ) {
* V_26 = 0 ;
return 0 ;
}
F_3 ( V_10 , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
V_28 = V_10 ;
if ( ! * V_27 ) {
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 ,
L_26 ,
L_27 , L_28 , L_10 , L_29 , L_30 ,
L_31 , L_32 , L_33 , L_32 , L_34 ) ;
F_14 ( V_10 + V_11 - V_28 > 0 ) ;
V_93 ++ ;
} else {
struct V_65 * V_66 ;
struct V_34 * V_97 ;
int V_41 ;
V_98:
V_97 = NULL ;
V_66 = NULL ;
V_41 = V_93 - 1 ;
F_15 ( V_91 ) ;
V_90 = V_31 . V_99 [ V_91 ] ;
if ( V_93 == 1 )
V_29 = F_18 ( V_90 -> V_100 ) ;
if ( V_29 != F_18 ( V_90 -> V_100 ) ) {
F_16 ( V_91 ) ;
F_4 ( V_10 , V_11 ) ;
return - V_44 ;
}
while ( V_92 < V_101 ) {
if ( ! V_97 )
V_97 = V_90 -> V_102 [ V_92 ] . V_47 ;
while ( V_97 != & V_90 -> V_102 [ V_92 ] ) {
struct V_65 * V_68 ;
V_68 = F_19 ( V_97 , struct V_65 ,
V_103 ) ;
if ( ! V_41 ) {
V_66 = V_68 ;
if ( V_68 -> V_103 . V_47 ==
& V_90 -> V_102 [ V_92 ] ) {
V_93 = 1 ;
V_92 ++ ;
} else {
V_93 ++ ;
}
break;
}
V_41 -- ;
V_97 = V_68 -> V_103 . V_47 ;
}
if ( V_66 )
break;
V_97 = NULL ;
V_93 = 1 ;
V_92 ++ ;
}
if ( V_66 ) {
T_5 V_58 = V_66 -> V_60 ;
int V_73 = V_66 -> V_74 ;
int V_104 = - 1 ;
char * V_105 = L_24 ;
int V_106 = V_66 -> V_107 -> V_108 ;
int V_109 = V_66 -> V_110 ;
int V_111 = V_66 -> V_112 ;
int V_113 = V_66 -> V_114 ;
int V_115 = V_66 -> V_116 ;
int V_117 = V_66 -> V_118 ;
if ( F_32 ( V_66 ) ||
F_33 ( V_66 ) )
V_105 = V_66 -> V_79 ? L_13 : L_14 ;
if ( F_33 ( V_66 ) ) {
unsigned long V_70 = F_25 () ;
long V_119 ;
V_119 = F_27 ( V_70 , V_66 -> V_120 ) ;
V_104 = F_26 ( V_119 ) ;
if ( V_104 >= 10000 )
V_104 = 9999 ;
}
F_16 ( V_91 ) ;
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 ,
L_35 ,
F_22 ( V_58 ) , V_73 , V_105 ,
V_104 , V_106 , V_113 , V_115 , V_109 ,
V_111 , V_117 ) ;
F_14 ( V_10 + V_11 - V_28 > 0 ) ;
} else {
F_16 ( V_91 ) ;
}
if ( V_92 == V_101 ) {
V_91 ++ ;
V_92 = 0 ;
V_93 = 1 ;
if ( ! V_66 && V_91 < V_96 )
goto V_98;
}
}
V_9 = V_28 - V_10 ;
if ( V_9 > * V_26 ) {
V_6 = - V_62 ;
} else if ( V_9 > 0 ) {
if ( F_23 ( V_4 , V_10 , V_9 ) )
V_6 = - V_63 ;
else
* V_27 = F_17 ( V_91 , V_29 , V_92 , V_93 ) ;
}
F_4 ( V_10 , V_11 ) ;
if ( ! V_6 )
* V_26 = V_9 ;
return V_6 ;
}
static int F_34 ( void * V_1 , int V_2 ,
T_1 V_3 , void T_2 * V_4 , int V_5 )
{
char * V_28 ;
char * V_10 ;
int V_11 ;
int V_121 ;
int V_9 ;
int V_6 ;
int V_43 ;
F_14 ( ! V_2 ) ;
V_11 = 64 * ( V_122 + 1 ) * V_96 ;
F_3 ( V_10 , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
V_28 = V_10 ;
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 ,
L_36 ,
L_37 , L_38 , L_39 , L_32 ) ;
F_14 ( V_10 + V_11 - V_28 > 0 ) ;
if ( ! V_31 . V_123 )
goto V_124;
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ ) {
struct V_125 * V_126 ;
F_15 ( V_127 ) ;
F_35 (rbp, i, the_lnet.ln_rtrpools) {
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 ,
L_40 ,
V_126 [ V_121 ] . V_128 ,
V_126 [ V_121 ] . V_129 ,
V_126 [ V_121 ] . V_130 ,
V_126 [ V_121 ] . V_131 ) ;
F_14 ( V_10 + V_11 - V_28 > 0 ) ;
}
F_16 ( V_127 ) ;
}
V_124:
V_9 = V_28 - V_10 ;
if ( V_3 >= F_6 ( int , V_9 , strlen ( V_10 ) ) )
V_6 = 0 ;
else
V_6 = F_7 ( V_4 , V_5 ,
V_10 + V_3 , NULL ) ;
F_4 ( V_10 , V_11 ) ;
return V_6 ;
}
static int F_36 ( struct V_24 * V_25 , int V_2 ,
void T_2 * V_4 , T_3 * V_26 , T_1 * V_27 )
{
return F_9 ( V_25 -> V_1 , V_2 , V_27 , V_4 , V_26 ,
F_34 ) ;
}
static int F_37 ( struct V_24 * V_25 , int V_2 ,
void T_2 * V_4 , T_3 * V_26 , T_1 * V_27 )
{
int V_11 = 128 * V_96 ;
int V_6 = 0 ;
char * V_10 ;
char * V_28 ;
int V_9 ;
F_14 ( ! V_2 ) ;
if ( ! * V_26 )
return 0 ;
F_3 ( V_10 , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
V_28 = V_10 ;
if ( ! * V_27 ) {
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 ,
L_41 ,
L_27 , L_42 , L_43 , L_28 , L_44 ,
L_31 , L_30 , L_33 , L_32 ) ;
F_14 ( V_10 + V_11 - V_28 > 0 ) ;
} else {
struct V_34 * V_35 ;
struct V_132 * V_133 = NULL ;
int V_41 = * V_27 - 1 ;
F_15 ( 0 ) ;
V_35 = V_31 . V_134 . V_47 ;
while ( V_35 != & V_31 . V_134 ) {
struct V_132 * V_135 ;
V_135 = F_19 ( V_35 , struct V_132 , V_136 ) ;
if ( ! V_41 ) {
V_133 = V_135 ;
break;
}
V_41 -- ;
V_35 = V_35 -> V_47 ;
}
if ( V_133 ) {
struct V_137 * V_138 ;
char * V_139 ;
T_6 V_70 = F_38 () ;
int V_140 = - 1 ;
int V_43 ;
int V_141 ;
if ( V_31 . V_32 )
V_140 = V_70 - V_133 -> V_142 ;
if ( V_133 -> V_143 -> V_144 == V_145 )
V_140 = 0 ;
F_39 ( V_133 ) ;
F_14 ( V_133 -> V_146 ) ;
V_139 = ( V_133 -> V_146 -> V_147 ==
V_148 ) ? L_13 : L_14 ;
F_40 ( V_133 ) ;
F_35 (tq, i, ni->ni_tx_queues) {
for ( V_141 = 0 ; V_133 -> V_149 &&
V_141 < V_133 -> V_150 ; V_141 ++ ) {
if ( V_43 == V_133 -> V_149 [ V_141 ] )
break;
}
if ( V_141 == V_133 -> V_150 )
continue;
if ( V_43 )
F_15 ( V_43 ) ;
V_28 += snprintf ( V_28 , V_10 + V_11 - V_28 ,
L_45 ,
F_22 ( V_133 -> V_151 ) , V_139 ,
V_140 , * V_133 -> V_152 [ V_43 ] ,
V_133 -> V_108 ,
V_133 -> V_153 ,
V_138 -> V_154 ,
V_138 -> V_155 ,
V_138 -> V_156 ) ;
if ( V_43 )
F_16 ( V_43 ) ;
}
F_14 ( V_10 + V_11 - V_28 > 0 ) ;
}
F_16 ( 0 ) ;
}
V_9 = V_28 - V_10 ;
if ( V_9 > * V_26 ) {
V_6 = - V_62 ;
} else if ( V_9 > 0 ) {
if ( F_23 ( V_4 , V_10 , V_9 ) )
V_6 = - V_63 ;
else
* V_27 += 1 ;
}
F_4 ( V_10 , V_11 ) ;
if ( ! V_6 )
* V_26 = V_9 ;
return V_6 ;
}
static int F_41 ( void * V_1 , int V_2 ,
T_1 V_3 , void T_2 * V_4 , int V_5 )
{
const int V_157 = 128 ;
char * V_158 ;
char * V_159 ;
int V_6 ;
int V_43 ;
F_3 ( V_158 , V_157 ) ;
if ( ! V_158 )
return - V_12 ;
if ( ! V_2 ) {
F_42 ( 0 ) ;
for ( V_43 = 0 ; V_160 [ V_43 ] . V_161 >= 0 ; V_43 ++ ) {
if ( V_160 [ V_43 ] . V_161 == V_162 )
break;
}
F_14 ( V_160 [ V_43 ] . V_161 == V_162 ) ;
F_43 ( 0 ) ;
V_6 = snprintf ( V_158 , V_157 ,
L_46
L_47 ,
V_160 [ V_43 ] . V_163 ,
V_160 [ V_43 ] . V_164 ) ;
if ( V_3 >= F_6 ( int , V_6 , V_157 ) ) {
V_6 = 0 ;
} else {
V_6 = F_7 ( V_4 , V_5 ,
V_158 + V_3 , L_2 ) ;
}
goto V_124;
}
V_6 = F_44 ( V_158 , V_157 , V_4 , V_5 ) ;
if ( V_6 < 0 )
goto V_124;
V_159 = F_45 ( V_158 ) ;
V_6 = - V_62 ;
F_42 ( 0 ) ;
for ( V_43 = 0 ; V_160 [ V_43 ] . V_163 ; V_43 ++ ) {
if ( ! strncasecmp ( V_160 [ V_43 ] . V_163 , V_159 ,
strlen ( V_160 [ V_43 ] . V_163 ) ) ) {
V_162 = V_160 [ V_43 ] . V_161 ;
V_6 = 0 ;
break;
}
}
F_43 ( 0 ) ;
V_124:
F_4 ( V_158 , V_157 ) ;
return V_6 ;
}
static int F_46 ( struct V_24 * V_25 , int V_2 ,
void T_2 * V_4 , T_3 * V_26 ,
T_1 * V_27 )
{
return F_9 ( V_25 -> V_1 , V_2 , V_27 , V_4 , V_26 ,
F_41 ) ;
}
void F_47 ( void )
{
F_48 ( V_165 , NULL ) ;
}
void F_49 ( void )
{
}
