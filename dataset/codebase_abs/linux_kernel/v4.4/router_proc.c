static int F_1 ( void * V_1 , int V_2 , T_1 * V_3 ,
void T_2 * V_4 , T_3 * V_5 ,
int (* F_2)( void * V_1 , int V_2 ,
T_1 V_6 , void T_2 * V_4 , int V_7 ) )
{
int V_8 = F_2 ( V_1 , V_2 , * V_3 , V_4 , * V_5 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 ) {
* V_3 += * V_5 ;
} else {
* V_5 = V_8 ;
* V_3 += V_8 ;
}
return 0 ;
}
static int F_3 ( void * V_1 , int V_2 ,
T_1 V_6 , void T_2 * V_4 , int V_9 )
{
int V_8 ;
T_4 * V_10 ;
int V_7 ;
char * V_11 ;
const int V_12 = 256 ;
if ( V_2 ) {
F_4 () ;
return 0 ;
}
F_5 ( V_10 , sizeof( * V_10 ) ) ;
if ( V_10 == NULL )
return - V_13 ;
F_5 ( V_11 , V_12 ) ;
if ( V_11 == NULL ) {
F_6 ( V_10 , sizeof( * V_10 ) ) ;
return - V_13 ;
}
F_7 ( V_10 ) ;
V_7 = snprintf ( V_11 , V_12 ,
L_1 ,
V_10 -> V_14 , V_10 -> V_15 ,
V_10 -> V_16 ,
V_10 -> V_17 , V_10 -> V_18 ,
V_10 -> V_19 , V_10 -> V_20 ,
V_10 -> V_21 , V_10 -> V_22 ,
V_10 -> V_23 , V_10 -> V_24 ) ;
if ( V_6 >= F_8 ( int , V_7 , strlen ( V_11 ) ) )
V_8 = 0 ;
else
V_8 = F_9 ( V_4 , V_9 ,
V_11 + V_6 , L_2 ) ;
F_6 ( V_11 , V_12 ) ;
F_6 ( V_10 , sizeof( * V_10 ) ) ;
return V_8 ;
}
static int F_10 ( struct V_25 * V_26 , int V_2 ,
void T_2 * V_4 , T_3 * V_5 , T_1 * V_3 )
{
return F_1 ( V_26 -> V_1 , V_2 , V_3 , V_4 , V_5 ,
F_3 ) ;
}
static int F_11 ( struct V_25 * V_26 , int V_2 ,
void T_2 * V_4 , T_3 * V_5 , T_1 * V_3 )
{
const int V_12 = 256 ;
char * V_11 ;
char * V_27 ;
int V_8 = 0 ;
int V_7 ;
int V_28 ;
int V_29 ;
F_12 ( sizeof( T_1 ) >= 4 ) ;
V_29 = F_13 ( * V_3 ) ;
V_28 = F_14 ( * V_3 ) ;
F_15 ( ! V_2 ) ;
if ( * V_5 == 0 )
return 0 ;
F_5 ( V_11 , V_12 ) ;
if ( V_11 == NULL )
return - V_13 ;
V_27 = V_11 ;
if ( * V_3 == 0 ) {
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 , L_3 ,
V_30 . V_31 ? L_4 : L_5 ) ;
F_15 ( V_11 + V_12 - V_27 > 0 ) ;
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 , L_6 ,
L_7 , L_8 , L_9 , L_10 , L_11 ) ;
F_15 ( V_11 + V_12 - V_27 > 0 ) ;
F_16 ( 0 ) ;
V_28 = ( unsigned int ) V_30 . V_32 ;
F_17 ( 0 ) ;
* V_3 = F_18 ( 0 , V_28 , 0 , V_29 ) ;
} else {
struct V_33 * V_34 ;
struct V_33 * V_35 ;
T_5 * V_36 = NULL ;
T_6 * V_37 = NULL ;
int V_38 = V_29 - 1 ;
struct V_33 * V_39 ;
int V_40 ;
F_16 ( 0 ) ;
if ( V_28 != F_19 ( V_30 . V_32 ) ) {
F_17 ( 0 ) ;
F_6 ( V_11 , V_12 ) ;
return - V_41 ;
}
for ( V_40 = 0 ; V_40 < V_42 && V_36 == NULL ;
V_40 ++ ) {
V_39 = & V_30 . V_43 [ V_40 ] ;
V_34 = V_39 -> V_44 ;
while ( V_34 != V_39 && V_36 == NULL ) {
V_37 = F_20 ( V_34 , T_6 ,
V_45 ) ;
V_35 = V_37 -> V_46 . V_44 ;
while ( V_35 != & V_37 -> V_46 ) {
T_5 * V_47 =
F_20 ( V_35 , T_5 ,
V_48 ) ;
if ( V_38 == 0 ) {
V_36 = V_47 ;
break;
}
V_38 -- ;
V_35 = V_35 -> V_44 ;
}
V_34 = V_34 -> V_44 ;
}
}
if ( V_36 != NULL ) {
T_7 V_49 = V_37 -> V_50 ;
unsigned int V_51 = V_36 -> V_52 ;
unsigned int V_53 = V_36 -> V_54 ;
T_8 V_55 = V_36 -> V_56 -> V_57 ;
int V_58 = V_36 -> V_56 -> V_59 ;
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 ,
L_12 ,
F_21 ( V_49 ) , V_51 ,
V_53 ,
V_58 ? L_13 : L_14 ,
F_22 ( V_55 ) ) ;
F_15 ( V_11 + V_12 - V_27 > 0 ) ;
}
F_17 ( 0 ) ;
}
V_7 = V_27 - V_11 ;
if ( V_7 > * V_5 ) {
V_8 = - V_60 ;
} else if ( V_7 > 0 ) {
if ( F_23 ( V_4 , V_11 , V_7 ) )
V_8 = - V_61 ;
else {
V_29 += 1 ;
* V_3 = F_18 ( 0 , V_28 , 0 , V_29 ) ;
}
}
F_6 ( V_11 , V_12 ) ;
if ( V_8 == 0 )
* V_5 = V_7 ;
return V_8 ;
}
static int F_24 ( struct V_25 * V_26 , int V_2 ,
void T_2 * V_4 , T_3 * V_5 , T_1 * V_3 )
{
int V_8 = 0 ;
char * V_11 ;
char * V_27 ;
const int V_12 = 256 ;
int V_7 ;
int V_28 ;
int V_29 ;
V_29 = F_13 ( * V_3 ) ;
V_28 = F_14 ( * V_3 ) ;
F_15 ( ! V_2 ) ;
if ( * V_5 == 0 )
return 0 ;
F_5 ( V_11 , V_12 ) ;
if ( V_11 == NULL )
return - V_13 ;
V_27 = V_11 ;
if ( * V_3 == 0 ) {
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 ,
L_15 ,
L_16 , L_17 , L_18 , L_10 ,
L_19 , L_20 , L_21 ,
L_22 , L_11 ) ;
F_15 ( V_11 + V_12 - V_27 > 0 ) ;
F_16 ( 0 ) ;
V_28 = ( unsigned int ) V_30 . V_62 ;
F_17 ( 0 ) ;
* V_3 = F_18 ( 0 , V_28 , 0 , V_29 ) ;
} else {
struct V_33 * V_35 ;
struct V_63 * V_64 = NULL ;
int V_38 = V_29 - 1 ;
F_16 ( 0 ) ;
if ( V_28 != F_19 ( V_30 . V_62 ) ) {
F_17 ( 0 ) ;
F_6 ( V_11 , V_12 ) ;
return - V_41 ;
}
V_35 = V_30 . V_65 . V_44 ;
while ( V_35 != & V_30 . V_65 ) {
T_9 * V_66 = F_20 ( V_35 , T_9 ,
V_67 ) ;
if ( V_38 == 0 ) {
V_64 = V_66 ;
break;
}
V_38 -- ;
V_35 = V_35 -> V_44 ;
}
if ( V_64 != NULL ) {
T_8 V_55 = V_64 -> V_57 ;
unsigned long V_68 = F_25 () ;
unsigned long V_69 = V_64 -> V_70 ;
int V_71 = V_64 -> V_72 ;
int V_73 = V_64 -> V_74 ;
int V_75 = V_64 -> V_76 ;
int V_58 = V_64 -> V_59 ;
int V_77 = ! V_64 -> V_78 ;
int V_79 = F_26 ( F_27 ( V_68 ,
V_64 -> V_80 ) ) ;
int V_81 = 0 ;
T_5 * V_82 ;
if ( ( V_64 -> V_83 &
V_84 ) != 0 ) {
F_28 (rtr, &peer->lp_routes,
lr_gwlist) {
if ( V_82 -> V_85 != 0 ) {
V_81 = V_82 -> V_85 ;
break;
}
}
}
if ( V_69 == 0 )
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 ,
L_23 ,
V_71 , V_73 , V_75 ,
V_58 ? L_13 : L_14 , V_79 ,
V_77 , L_24 , V_81 ,
F_22 ( V_55 ) ) ;
else
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 ,
L_25 ,
V_71 , V_73 , V_75 ,
V_58 ? L_13 : L_14 , V_79 ,
V_77 ,
F_26 ( F_27 ( V_69 , V_68 ) ) ,
V_81 , F_22 ( V_55 ) ) ;
F_15 ( V_11 + V_12 - V_27 > 0 ) ;
}
F_17 ( 0 ) ;
}
V_7 = V_27 - V_11 ;
if ( V_7 > * V_5 ) {
V_8 = - V_60 ;
} else if ( V_7 > 0 ) {
if ( F_23 ( V_4 , V_11 , V_7 ) )
V_8 = - V_61 ;
else {
V_29 += 1 ;
* V_3 = F_18 ( 0 , V_28 , 0 , V_29 ) ;
}
}
F_6 ( V_11 , V_12 ) ;
if ( V_8 == 0 )
* V_5 = V_7 ;
return V_8 ;
}
static int F_29 ( struct V_25 * V_26 , int V_2 ,
void T_2 * V_4 , T_3 * V_5 , T_1 * V_3 )
{
const int V_12 = 256 ;
struct V_86 * V_87 ;
char * V_11 ;
char * V_27 ;
int V_88 = F_30 ( * V_3 ) ;
int V_28 = F_14 ( * V_3 ) ;
int V_89 = F_31 ( * V_3 ) ;
int V_90 = F_13 ( * V_3 ) ;
int V_8 = 0 ;
int V_7 ;
F_12 ( V_91 >= V_92 ) ;
F_15 ( ! V_2 ) ;
if ( * V_5 == 0 )
return 0 ;
if ( V_88 >= V_93 ) {
* V_5 = 0 ;
return 0 ;
}
F_5 ( V_11 , V_12 ) ;
if ( V_11 == NULL )
return - V_13 ;
V_27 = V_11 ;
if ( * V_3 == 0 ) {
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 ,
L_26 ,
L_27 , L_28 , L_10 , L_29 , L_30 ,
L_31 , L_32 , L_33 , L_32 , L_34 ) ;
F_15 ( V_11 + V_12 - V_27 > 0 ) ;
V_90 ++ ;
} else {
struct V_63 * V_64 ;
struct V_33 * V_94 ;
int V_38 ;
V_95:
V_94 = NULL ;
V_64 = NULL ;
V_38 = V_90 - 1 ;
F_16 ( V_88 ) ;
V_87 = V_30 . V_96 [ V_88 ] ;
if ( V_90 == 1 )
V_28 = F_19 ( V_87 -> V_97 ) ;
if ( V_28 != F_19 ( V_87 -> V_97 ) ) {
F_17 ( V_88 ) ;
F_6 ( V_11 , V_12 ) ;
return - V_41 ;
}
while ( V_89 < V_98 ) {
if ( V_94 == NULL )
V_94 = V_87 -> V_99 [ V_89 ] . V_44 ;
while ( V_94 != & V_87 -> V_99 [ V_89 ] ) {
T_9 * V_66 = F_20 ( V_94 , T_9 ,
V_100 ) ;
if ( V_38 == 0 ) {
V_64 = V_66 ;
if ( V_66 -> V_100 . V_44 ==
& V_87 -> V_99 [ V_89 ] ) {
V_90 = 1 ;
V_89 ++ ;
} else {
V_90 ++ ;
}
break;
}
V_38 -- ;
V_94 = V_66 -> V_100 . V_44 ;
}
if ( V_64 != NULL )
break;
V_94 = NULL ;
V_90 = 1 ;
V_89 ++ ;
}
if ( V_64 != NULL ) {
T_8 V_55 = V_64 -> V_57 ;
int V_71 = V_64 -> V_72 ;
int V_101 = - 1 ;
char * V_102 = L_24 ;
int V_103 = V_64 -> V_104 -> V_105 ;
int V_106 = V_64 -> V_107 ;
int V_108 = V_64 -> V_109 ;
int V_110 = V_64 -> V_111 ;
int V_112 = V_64 -> V_113 ;
int V_114 = V_64 -> V_115 ;
if ( F_32 ( V_64 ) ||
F_33 ( V_64 ) )
V_102 = V_64 -> V_59 ? L_13 : L_14 ;
if ( F_33 ( V_64 ) ) {
unsigned long V_68 = F_25 () ;
long V_116 ;
V_116 = F_27 ( V_68 , V_64 -> V_117 ) ;
V_101 = F_26 ( V_116 ) ;
if ( V_101 >= 10000 )
V_101 = 9999 ;
}
F_17 ( V_88 ) ;
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 ,
L_35 ,
F_22 ( V_55 ) , V_71 , V_102 ,
V_101 , V_103 , V_110 , V_112 , V_106 ,
V_108 , V_114 ) ;
F_15 ( V_11 + V_12 - V_27 > 0 ) ;
} else {
F_17 ( V_88 ) ;
}
if ( V_89 == V_98 ) {
V_88 ++ ;
V_89 = 0 ;
V_90 = 1 ;
if ( V_64 == NULL && V_88 < V_93 )
goto V_95;
}
}
V_7 = V_27 - V_11 ;
if ( V_7 > * V_5 ) {
V_8 = - V_60 ;
} else if ( V_7 > 0 ) {
if ( F_23 ( V_4 , V_11 , V_7 ) )
V_8 = - V_61 ;
else
* V_3 = F_18 ( V_88 , V_28 , V_89 , V_90 ) ;
}
F_6 ( V_11 , V_12 ) ;
if ( V_8 == 0 )
* V_5 = V_7 ;
return V_8 ;
}
static int F_34 ( void * V_1 , int V_2 ,
T_1 V_6 , void T_2 * V_4 , int V_9 )
{
char * V_27 ;
char * V_11 ;
int V_12 ;
int V_118 ;
int V_7 ;
int V_8 ;
int V_40 ;
F_15 ( ! V_2 ) ;
V_12 = 64 * ( V_119 + 1 ) * V_93 ;
F_5 ( V_11 , V_12 ) ;
if ( V_11 == NULL )
return - V_13 ;
V_27 = V_11 ;
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 ,
L_36 ,
L_37 , L_38 , L_39 , L_32 ) ;
F_15 ( V_11 + V_12 - V_27 > 0 ) ;
if ( V_30 . V_120 == NULL )
goto V_121;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
T_10 * V_122 ;
F_16 ( V_123 ) ;
F_35 (rbp, i, the_lnet.ln_rtrpools) {
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 ,
L_40 ,
V_122 [ V_118 ] . V_124 ,
V_122 [ V_118 ] . V_125 ,
V_122 [ V_118 ] . V_126 ,
V_122 [ V_118 ] . V_127 ) ;
F_15 ( V_11 + V_12 - V_27 > 0 ) ;
}
F_17 ( V_123 ) ;
}
V_121:
V_7 = V_27 - V_11 ;
if ( V_6 >= F_8 ( int , V_7 , strlen ( V_11 ) ) )
V_8 = 0 ;
else
V_8 = F_9 ( V_4 , V_9 ,
V_11 + V_6 , NULL ) ;
F_6 ( V_11 , V_12 ) ;
return V_8 ;
}
static int F_36 ( struct V_25 * V_26 , int V_2 ,
void T_2 * V_4 , T_3 * V_5 , T_1 * V_3 )
{
return F_1 ( V_26 -> V_1 , V_2 , V_3 , V_4 , V_5 ,
F_34 ) ;
}
static int F_37 ( struct V_25 * V_26 , int V_2 ,
void T_2 * V_4 , T_3 * V_5 , T_1 * V_3 )
{
int V_12 = 128 * V_93 ;
int V_8 = 0 ;
char * V_11 ;
char * V_27 ;
int V_7 ;
F_15 ( ! V_2 ) ;
if ( * V_5 == 0 )
return 0 ;
F_5 ( V_11 , V_12 ) ;
if ( V_11 == NULL )
return - V_13 ;
V_27 = V_11 ;
if ( * V_3 == 0 ) {
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 ,
L_41 ,
L_27 , L_42 , L_43 , L_28 , L_44 ,
L_31 , L_30 , L_33 , L_32 ) ;
F_15 ( V_11 + V_12 - V_27 > 0 ) ;
} else {
struct V_33 * V_34 ;
T_11 * V_128 = NULL ;
int V_38 = * V_3 - 1 ;
F_16 ( 0 ) ;
V_34 = V_30 . V_129 . V_44 ;
while ( V_34 != & V_30 . V_129 ) {
T_11 * V_130 = F_20 ( V_34 , T_11 , V_131 ) ;
if ( V_38 == 0 ) {
V_128 = V_130 ;
break;
}
V_38 -- ;
V_34 = V_34 -> V_44 ;
}
if ( V_128 != NULL ) {
struct V_132 * V_133 ;
char * V_134 ;
T_12 V_68 = F_38 () ;
int V_135 = - 1 ;
int V_40 ;
int V_136 ;
if ( V_30 . V_31 )
V_135 = V_68 - V_128 -> V_137 ;
if ( V_128 -> V_138 -> V_139 == V_140 )
V_135 = 0 ;
F_39 ( V_128 ) ;
F_15 ( V_128 -> V_141 != NULL ) ;
V_134 = ( V_128 -> V_141 -> V_142 ==
V_143 ) ? L_13 : L_14 ;
F_40 ( V_128 ) ;
F_35 (tq, i, ni->ni_tx_queues) {
for ( V_136 = 0 ; V_128 -> V_144 != NULL &&
V_136 < V_128 -> V_145 ; V_136 ++ ) {
if ( V_40 == V_128 -> V_144 [ V_136 ] )
break;
}
if ( V_136 == V_128 -> V_145 )
continue;
if ( V_40 != 0 )
F_16 ( V_40 ) ;
V_27 += snprintf ( V_27 , V_11 + V_12 - V_27 ,
L_45 ,
F_22 ( V_128 -> V_146 ) , V_134 ,
V_135 , * V_128 -> V_147 [ V_40 ] ,
V_128 -> V_105 ,
V_128 -> V_148 ,
V_133 -> V_149 ,
V_133 -> V_150 , V_133 -> V_151 ) ;
if ( V_40 != 0 )
F_17 ( V_40 ) ;
}
F_15 ( V_11 + V_12 - V_27 > 0 ) ;
}
F_17 ( 0 ) ;
}
V_7 = V_27 - V_11 ;
if ( V_7 > * V_5 ) {
V_8 = - V_60 ;
} else if ( V_7 > 0 ) {
if ( F_23 ( V_4 , V_11 , V_7 ) )
V_8 = - V_61 ;
else
* V_3 += 1 ;
}
F_6 ( V_11 , V_12 ) ;
if ( V_8 == 0 )
* V_5 = V_7 ;
return V_8 ;
}
static int F_41 ( void * V_1 , int V_2 ,
T_1 V_6 , void T_2 * V_4 , int V_9 )
{
const int V_152 = 128 ;
char * V_153 ;
char * V_154 ;
int V_8 ;
int V_40 ;
F_5 ( V_153 , V_152 ) ;
if ( V_153 == NULL )
return - V_13 ;
if ( ! V_2 ) {
F_42 ( 0 ) ;
for ( V_40 = 0 ; V_155 [ V_40 ] . V_156 >= 0 ; V_40 ++ ) {
if ( V_155 [ V_40 ] . V_156 == V_157 )
break;
}
F_15 ( V_155 [ V_40 ] . V_156 == V_157 ) ;
F_43 ( 0 ) ;
V_8 = snprintf ( V_153 , V_152 ,
L_46
L_47 ,
V_155 [ V_40 ] . V_158 ,
V_155 [ V_40 ] . V_159 ) ;
if ( V_6 >= F_8 ( int , V_8 , V_152 ) ) {
V_8 = 0 ;
} else {
V_8 = F_9 ( V_4 , V_9 ,
V_153 + V_6 , L_2 ) ;
}
goto V_121;
}
V_8 = F_44 ( V_153 , V_152 , V_4 , V_9 ) ;
if ( V_8 < 0 )
goto V_121;
V_154 = F_45 ( V_153 ) ;
V_8 = - V_60 ;
F_42 ( 0 ) ;
for ( V_40 = 0 ; V_155 [ V_40 ] . V_158 != NULL ; V_40 ++ ) {
if ( strncasecmp ( V_155 [ V_40 ] . V_158 , V_154 ,
strlen ( V_155 [ V_40 ] . V_158 ) ) == 0 ) {
V_157 = V_155 [ V_40 ] . V_156 ;
V_8 = 0 ;
break;
}
}
F_43 ( 0 ) ;
V_121:
F_6 ( V_153 , V_152 ) ;
return V_8 ;
}
static int F_46 ( struct V_25 * V_26 , int V_2 ,
void T_2 * V_4 , T_3 * V_5 ,
T_1 * V_3 )
{
return F_1 ( V_26 -> V_1 , V_2 , V_3 , V_4 , V_5 ,
F_41 ) ;
}
void F_47 ( void )
{
F_48 ( V_160 , NULL ) ;
}
void F_49 ( void )
{
}
