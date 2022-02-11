static int F_1 ( void * V_1 , int V_2 ,
T_1 V_3 , void * V_4 , int V_5 )
{
int V_6 ;
T_2 * V_7 ;
int V_8 ;
char * V_9 ;
const int V_10 = 256 ;
if ( V_2 ) {
F_2 () ;
return 0 ;
}
F_3 ( V_7 , sizeof( * V_7 ) ) ;
if ( V_7 == NULL )
return - V_11 ;
F_3 ( V_9 , V_10 ) ;
if ( V_9 == NULL ) {
F_4 ( V_7 , sizeof( * V_7 ) ) ;
return - V_11 ;
}
F_5 ( V_7 ) ;
V_8 = snprintf ( V_9 , V_10 ,
L_1 V_12 L_2 V_12 L_2
V_12 L_2 V_12 ,
V_7 -> V_13 , V_7 -> V_14 ,
V_7 -> V_15 ,
V_7 -> V_16 , V_7 -> V_17 ,
V_7 -> V_18 , V_7 -> V_19 ,
V_7 -> V_20 , V_7 -> V_21 ,
V_7 -> V_22 , V_7 -> V_23 ) ;
if ( V_3 >= F_6 ( int , V_8 , strlen ( V_9 ) ) )
V_6 = 0 ;
else
V_6 = F_7 ( V_4 , V_5 ,
V_9 + V_3 , L_3 ) ;
F_4 ( V_9 , V_10 ) ;
F_4 ( V_7 , sizeof( * V_7 ) ) ;
return V_6 ;
}
int F_8 ( T_3 )
{
const int V_10 = 256 ;
char * V_9 ;
char * V_24 ;
int V_6 = 0 ;
int V_8 ;
int V_25 ;
int V_26 ;
V_27 ;
F_9 ( sizeof( T_1 ) >= 4 ) ;
V_26 = F_10 ( * V_28 ) ;
V_25 = F_11 ( * V_28 ) ;
F_12 ( ! V_2 ) ;
if ( * V_29 == 0 )
return 0 ;
F_3 ( V_9 , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
V_24 = V_9 ;
if ( * V_28 == 0 ) {
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 , L_4 ,
V_30 . V_31 ? L_5 : L_6 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 , L_7 ,
L_8 , L_9 , L_10 , L_11 , L_12 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
F_13 ( 0 ) ;
V_25 = ( unsigned int ) V_30 . V_32 ;
F_14 ( 0 ) ;
* V_28 = F_15 ( 0 , V_25 , 0 , V_26 ) ;
} else {
struct V_33 * V_34 ;
struct V_33 * V_35 ;
T_4 * V_36 = NULL ;
T_5 * V_37 = NULL ;
int V_38 = V_26 - 1 ;
struct V_33 * V_39 ;
int V_40 ;
F_13 ( 0 ) ;
if ( V_25 != F_16 ( V_30 . V_32 ) ) {
F_14 ( 0 ) ;
F_4 ( V_9 , V_10 ) ;
return - V_41 ;
}
for ( V_40 = 0 ; V_40 < V_42 && V_36 == NULL ;
V_40 ++ ) {
V_39 = & V_30 . V_43 [ V_40 ] ;
V_34 = V_39 -> V_44 ;
while ( V_34 != V_39 && V_36 == NULL ) {
V_37 = F_17 ( V_34 , T_5 ,
V_45 ) ;
V_35 = V_37 -> V_46 . V_44 ;
while ( V_35 != & V_37 -> V_46 ) {
T_4 * V_47 =
F_17 ( V_35 , T_4 ,
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
T_6 V_49 = V_37 -> V_50 ;
unsigned int V_51 = V_36 -> V_52 ;
unsigned int V_53 = V_36 -> V_54 ;
T_7 V_55 = V_36 -> V_56 -> V_57 ;
int V_58 = V_36 -> V_56 -> V_59 ;
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_13 ,
F_18 ( V_49 ) , V_51 ,
V_53 ,
V_58 ? L_14 : L_15 ,
F_19 ( V_55 ) ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
}
F_14 ( 0 ) ;
}
V_8 = V_24 - V_9 ;
if ( V_8 > * V_29 ) {
V_6 = - V_60 ;
} else if ( V_8 > 0 ) {
if ( F_20 ( V_4 , V_9 , V_8 ) )
V_6 = - V_61 ;
else {
V_26 += 1 ;
* V_28 = F_15 ( 0 , V_25 , 0 , V_26 ) ;
}
}
F_4 ( V_9 , V_10 ) ;
if ( V_6 == 0 )
* V_29 = V_8 ;
return V_6 ;
}
int F_8 ( T_8 )
{
int V_6 = 0 ;
char * V_9 ;
char * V_24 ;
const int V_10 = 256 ;
int V_8 ;
int V_25 ;
int V_26 ;
V_27 ;
V_26 = F_10 ( * V_28 ) ;
V_25 = F_11 ( * V_28 ) ;
F_12 ( ! V_2 ) ;
if ( * V_29 == 0 )
return 0 ;
F_3 ( V_9 , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
V_24 = V_9 ;
if ( * V_28 == 0 ) {
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_16 ,
L_17 , L_18 , L_19 , L_11 ,
L_20 , L_21 , L_22 ,
L_23 , L_12 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
F_13 ( 0 ) ;
V_25 = ( unsigned int ) V_30 . V_62 ;
F_14 ( 0 ) ;
* V_28 = F_15 ( 0 , V_25 , 0 , V_26 ) ;
} else {
struct V_33 * V_35 ;
struct V_63 * V_64 = NULL ;
int V_38 = V_26 - 1 ;
F_13 ( 0 ) ;
if ( V_25 != F_16 ( V_30 . V_62 ) ) {
F_14 ( 0 ) ;
F_4 ( V_9 , V_10 ) ;
return - V_41 ;
}
V_35 = V_30 . V_65 . V_44 ;
while ( V_35 != & V_30 . V_65 ) {
T_9 * V_66 = F_17 ( V_35 , T_9 ,
V_67 ) ;
if ( V_38 == 0 ) {
V_64 = V_66 ;
break;
}
V_38 -- ;
V_35 = V_35 -> V_44 ;
}
if ( V_64 != NULL ) {
T_7 V_55 = V_64 -> V_57 ;
T_10 V_68 = F_21 () ;
T_10 V_69 = V_64 -> V_70 ;
int V_71 = V_64 -> V_72 ;
int V_73 = V_64 -> V_74 ;
int V_75 = V_64 -> V_76 ;
int V_58 = V_64 -> V_59 ;
int V_77 = ! V_64 -> V_78 ;
int V_79 = F_22 ( F_23 ( V_68 ,
V_64 -> V_80 ) ) ;
int V_81 = 0 ;
T_4 * V_82 ;
if ( ( V_64 -> V_83 &
V_84 ) != 0 ) {
F_24 (rtr, &peer->lp_routes,
lr_gwlist) {
if ( V_82 -> V_85 != 0 ) {
V_81 = V_82 -> V_85 ;
break;
}
}
}
if ( V_69 == 0 )
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_24 ,
V_71 , V_73 , V_75 ,
V_58 ? L_14 : L_15 , V_79 ,
V_77 , L_25 , V_81 ,
F_19 ( V_55 ) ) ;
else
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_26 ,
V_71 , V_73 , V_75 ,
V_58 ? L_14 : L_15 , V_79 ,
V_77 ,
F_22 ( F_23 ( V_69 , V_68 ) ) ,
V_81 , F_19 ( V_55 ) ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
}
F_14 ( 0 ) ;
}
V_8 = V_24 - V_9 ;
if ( V_8 > * V_29 ) {
V_6 = - V_60 ;
} else if ( V_8 > 0 ) {
if ( F_20 ( V_4 , V_9 , V_8 ) )
V_6 = - V_61 ;
else {
V_26 += 1 ;
* V_28 = F_15 ( 0 , V_25 , 0 , V_26 ) ;
}
}
F_4 ( V_9 , V_10 ) ;
if ( V_6 == 0 )
* V_29 = V_8 ;
return V_6 ;
}
int F_8 ( T_11 )
{
const int V_10 = 256 ;
struct V_86 * V_87 ;
char * V_9 ;
char * V_24 ;
int V_88 = F_25 ( * V_28 ) ;
int V_25 = F_11 ( * V_28 ) ;
int V_89 = F_26 ( * V_28 ) ;
int V_90 = F_10 ( * V_28 ) ;
int V_6 = 0 ;
int V_8 ;
F_9 ( V_91 >= V_92 ) ;
F_12 ( ! V_2 ) ;
if ( * V_29 == 0 )
return 0 ;
if ( V_88 >= V_93 ) {
* V_29 = 0 ;
return 0 ;
}
F_3 ( V_9 , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
V_24 = V_9 ;
if ( * V_28 == 0 ) {
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_27 ,
L_28 , L_29 , L_11 , L_30 , L_31 ,
L_32 , L_33 , L_34 , L_33 , L_35 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
V_90 ++ ;
} else {
struct V_63 * V_64 ;
struct V_33 * V_94 ;
int V_38 ;
V_95:
V_94 = NULL ;
V_64 = NULL ;
V_38 = V_90 - 1 ;
F_13 ( V_88 ) ;
V_87 = V_30 . V_96 [ V_88 ] ;
if ( V_90 == 1 )
V_25 = F_16 ( V_87 -> V_97 ) ;
if ( V_25 != F_16 ( V_87 -> V_97 ) ) {
F_14 ( V_88 ) ;
F_4 ( V_9 , V_10 ) ;
return - V_41 ;
}
while ( V_89 < V_98 ) {
if ( V_94 == NULL )
V_94 = V_87 -> V_99 [ V_89 ] . V_44 ;
while ( V_94 != & V_87 -> V_99 [ V_89 ] ) {
T_9 * V_66 = F_17 ( V_94 , T_9 ,
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
T_7 V_55 = V_64 -> V_57 ;
int V_71 = V_64 -> V_72 ;
int V_101 = - 1 ;
char * V_102 = L_25 ;
int V_103 = V_64 -> V_104 -> V_105 ;
int V_106 = V_64 -> V_107 ;
int V_108 = V_64 -> V_109 ;
int V_110 = V_64 -> V_111 ;
int V_112 = V_64 -> V_113 ;
int V_114 = V_64 -> V_115 ;
if ( F_27 ( V_64 ) ||
F_28 ( V_64 ) )
V_102 = V_64 -> V_59 ? L_14 : L_15 ;
if ( F_28 ( V_64 ) ) {
T_10 V_68 = F_21 () ;
T_12 V_116 ;
V_116 = F_23 ( V_68 , V_64 -> V_117 ) ;
V_101 = F_22 ( V_116 ) ;
if ( V_101 >= 10000 )
V_101 = 9999 ;
}
F_14 ( V_88 ) ;
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_36 ,
F_19 ( V_55 ) , V_71 , V_102 ,
V_101 , V_103 , V_110 , V_112 , V_106 ,
V_108 , V_114 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
} else {
F_14 ( V_88 ) ;
}
if ( V_89 == V_98 ) {
V_88 ++ ;
V_89 = 0 ;
V_90 = 1 ;
if ( V_64 == NULL && V_88 < V_93 )
goto V_95;
}
}
V_8 = V_24 - V_9 ;
if ( V_8 > * V_29 ) {
V_6 = - V_60 ;
} else if ( V_8 > 0 ) {
if ( F_20 ( V_4 , V_9 , V_8 ) )
V_6 = - V_61 ;
else
* V_28 = F_15 ( V_88 , V_25 , V_89 , V_90 ) ;
}
F_4 ( V_9 , V_10 ) ;
if ( V_6 == 0 )
* V_29 = V_8 ;
return V_6 ;
}
static int F_29 ( void * V_1 , int V_2 ,
T_1 V_3 , void * V_4 , int V_5 )
{
char * V_24 ;
char * V_9 ;
int V_10 ;
int V_118 ;
int V_8 ;
int V_6 ;
int V_40 ;
F_12 ( ! V_2 ) ;
V_10 = 64 * ( V_119 + 1 ) * V_93 ;
F_3 ( V_9 , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
V_24 = V_9 ;
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_37 ,
L_38 , L_39 , L_40 , L_33 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
if ( V_30 . V_120 == NULL )
goto V_121;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
T_13 * V_122 ;
F_13 ( V_123 ) ;
F_30 (rbp, i, the_lnet.ln_rtrpools) {
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_41 ,
V_122 [ V_118 ] . V_124 ,
V_122 [ V_118 ] . V_125 ,
V_122 [ V_118 ] . V_126 ,
V_122 [ V_118 ] . V_127 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
}
F_14 ( V_123 ) ;
}
V_121:
V_8 = V_24 - V_9 ;
if ( V_3 >= F_6 ( int , V_8 , strlen ( V_9 ) ) )
V_6 = 0 ;
else
V_6 = F_7 ( V_4 , V_5 ,
V_9 + V_3 , NULL ) ;
F_4 ( V_9 , V_10 ) ;
return V_6 ;
}
int F_8 ( T_14 )
{
int V_10 = 128 * V_93 ;
int V_6 = 0 ;
char * V_9 ;
char * V_24 ;
int V_8 ;
V_27 ;
F_12 ( ! V_2 ) ;
if ( * V_29 == 0 )
return 0 ;
F_3 ( V_9 , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
V_24 = V_9 ;
if ( * V_28 == 0 ) {
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_42 ,
L_28 , L_43 , L_44 , L_29 , L_45 ,
L_32 , L_31 , L_34 , L_33 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
} else {
struct V_33 * V_34 ;
T_15 * V_128 = NULL ;
int V_38 = * V_28 - 1 ;
F_13 ( 0 ) ;
V_34 = V_30 . V_129 . V_44 ;
while ( V_34 != & V_30 . V_129 ) {
T_15 * V_130 = F_17 ( V_34 , T_15 , V_131 ) ;
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
long V_68 = F_31 () ;
int V_135 = - 1 ;
int V_40 ;
int V_136 ;
if ( V_30 . V_31 )
V_135 = V_68 - V_128 -> V_137 ;
if ( V_128 -> V_138 -> V_139 == V_140 )
V_135 = 0 ;
F_32 ( V_128 ) ;
F_12 ( V_128 -> V_141 != NULL ) ;
V_134 = ( V_128 -> V_141 -> V_142 ==
V_143 ) ? L_14 : L_15 ;
F_33 ( V_128 ) ;
F_30 (tq, i, ni->ni_tx_queues) {
for ( V_136 = 0 ; V_128 -> V_144 != NULL &&
V_136 < V_128 -> V_145 ; V_136 ++ ) {
if ( V_40 == V_128 -> V_144 [ V_136 ] )
break;
}
if ( V_136 == V_128 -> V_145 )
continue;
if ( V_40 != 0 )
F_13 ( V_40 ) ;
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_46 ,
F_19 ( V_128 -> V_146 ) , V_134 ,
V_135 , * V_128 -> V_147 [ V_40 ] ,
V_128 -> V_105 ,
V_128 -> V_148 ,
V_133 -> V_149 ,
V_133 -> V_150 , V_133 -> V_151 ) ;
if ( V_40 != 0 )
F_14 ( V_40 ) ;
}
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
}
F_14 ( 0 ) ;
}
V_8 = V_24 - V_9 ;
if ( V_8 > * V_29 ) {
V_6 = - V_60 ;
} else if ( V_8 > 0 ) {
if ( F_20 ( V_4 , V_9 , V_8 ) )
V_6 = - V_61 ;
else
* V_28 += 1 ;
}
F_4 ( V_9 , V_10 ) ;
if ( V_6 == 0 )
* V_29 = V_8 ;
return V_6 ;
}
static int F_34 ( void * V_1 , int V_2 ,
T_1 V_3 , void * V_4 , int V_5 )
{
const int V_152 = 128 ;
char * V_153 ;
char * V_154 ;
int V_6 ;
int V_40 ;
F_3 ( V_153 , V_152 ) ;
if ( V_153 == NULL )
return - V_11 ;
if ( ! V_2 ) {
F_35 ( 0 ) ;
for ( V_40 = 0 ; V_155 [ V_40 ] . V_156 >= 0 ; V_40 ++ ) {
if ( V_155 [ V_40 ] . V_156 == V_157 )
break;
}
F_12 ( V_155 [ V_40 ] . V_156 == V_157 ) ;
F_36 ( 0 ) ;
V_6 = snprintf ( V_153 , V_152 ,
L_47
L_48 ,
V_155 [ V_40 ] . V_158 ,
V_155 [ V_40 ] . V_159 ) ;
if ( V_3 >= F_6 ( int , V_6 , V_152 ) ) {
V_6 = 0 ;
} else {
V_6 = F_7 ( V_4 , V_5 ,
V_153 + V_3 , L_3 ) ;
}
goto V_121;
}
V_6 = F_37 ( V_153 , V_152 , V_4 , V_5 ) ;
if ( V_6 < 0 )
goto V_121;
V_154 = F_38 ( V_153 ) ;
V_6 = - V_60 ;
F_35 ( 0 ) ;
for ( V_40 = 0 ; V_155 [ V_40 ] . V_158 != NULL ; V_40 ++ ) {
if ( F_39 ( V_155 [ V_40 ] . V_158 , V_154 ,
strlen ( V_155 [ V_40 ] . V_158 ) ) == 0 ) {
V_157 = V_155 [ V_40 ] . V_156 ;
V_6 = 0 ;
break;
}
}
F_36 ( 0 ) ;
V_121:
F_4 ( V_153 , V_152 ) ;
return V_6 ;
}
void
F_40 ( void )
{
if ( V_160 == NULL )
V_160 = F_41 ( V_161 ) ;
}
void
F_42 ( void )
{
if ( V_160 != NULL )
F_43 ( V_160 ) ;
V_160 = NULL ;
}
void
F_40 ( void )
{
}
void
F_42 ( void )
{
}
