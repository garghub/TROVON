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
L_8 , L_9 , L_10 , L_11 ) ;
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
T_7 V_53 = V_36 -> V_54 -> V_55 ;
int V_56 = V_36 -> V_54 -> V_57 ;
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_12 ,
F_18 ( V_49 ) , V_51 ,
V_56 ? L_13 : L_14 ,
F_19 ( V_53 ) ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
}
F_14 ( 0 ) ;
}
V_8 = V_24 - V_9 ;
if ( V_8 > * V_29 ) {
V_6 = - V_58 ;
} else if ( V_8 > 0 ) {
if ( F_20 ( V_4 , V_9 , V_8 ) )
V_6 = - V_59 ;
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
L_15 ,
L_16 , L_17 , L_18 , L_10 ,
L_19 , L_20 , L_21 ,
L_22 , L_11 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
F_13 ( 0 ) ;
V_25 = ( unsigned int ) V_30 . V_60 ;
F_14 ( 0 ) ;
* V_28 = F_15 ( 0 , V_25 , 0 , V_26 ) ;
} else {
struct V_33 * V_35 ;
struct V_61 * V_62 = NULL ;
int V_38 = V_26 - 1 ;
F_13 ( 0 ) ;
if ( V_25 != F_16 ( V_30 . V_60 ) ) {
F_14 ( 0 ) ;
F_4 ( V_9 , V_10 ) ;
return - V_41 ;
}
V_35 = V_30 . V_63 . V_44 ;
while ( V_35 != & V_30 . V_63 ) {
T_9 * V_64 = F_17 ( V_35 , T_9 ,
V_65 ) ;
if ( V_38 == 0 ) {
V_62 = V_64 ;
break;
}
V_38 -- ;
V_35 = V_35 -> V_44 ;
}
if ( V_62 != NULL ) {
T_7 V_53 = V_62 -> V_55 ;
T_10 V_66 = F_21 () ;
T_10 V_67 = V_62 -> V_68 ;
int V_69 = V_62 -> V_70 ;
int V_71 = V_62 -> V_72 ;
int V_73 = V_62 -> V_74 ;
int V_56 = V_62 -> V_57 ;
int V_75 = ! V_62 -> V_76 ;
int V_77 = F_22 ( F_23 ( V_66 ,
V_62 -> V_78 ) ) ;
int V_79 = 0 ;
T_4 * V_80 ;
if ( ( V_62 -> V_81 &
V_82 ) != 0 ) {
F_24 (rtr, &peer->lp_routes,
lr_gwlist) {
if ( V_80 -> V_83 != 0 ) {
V_79 = V_80 -> V_83 ;
break;
}
}
}
if ( V_67 == 0 )
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_23 ,
V_69 , V_71 , V_73 ,
V_56 ? L_13 : L_14 , V_77 ,
V_75 , L_24 , V_79 ,
F_19 ( V_53 ) ) ;
else
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_25 ,
V_69 , V_71 , V_73 ,
V_56 ? L_13 : L_14 , V_77 ,
V_75 ,
F_22 ( F_23 ( V_67 , V_66 ) ) ,
V_79 , F_19 ( V_53 ) ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
}
F_14 ( 0 ) ;
}
V_8 = V_24 - V_9 ;
if ( V_8 > * V_29 ) {
V_6 = - V_58 ;
} else if ( V_8 > 0 ) {
if ( F_20 ( V_4 , V_9 , V_8 ) )
V_6 = - V_59 ;
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
struct V_84 * V_85 ;
char * V_9 ;
char * V_24 ;
int V_86 = F_25 ( * V_28 ) ;
int V_25 = F_11 ( * V_28 ) ;
int V_87 = F_26 ( * V_28 ) ;
int V_88 = F_10 ( * V_28 ) ;
int V_6 = 0 ;
int V_8 ;
F_9 ( V_89 >= V_90 ) ;
F_12 ( ! V_2 ) ;
if ( * V_29 == 0 )
return 0 ;
if ( V_86 >= V_91 ) {
* V_29 = 0 ;
return 0 ;
}
F_3 ( V_9 , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
V_24 = V_9 ;
if ( * V_28 == 0 ) {
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_26 ,
L_27 , L_28 , L_10 , L_29 , L_30 ,
L_31 , L_32 , L_33 , L_32 , L_34 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
V_88 ++ ;
} else {
struct V_61 * V_62 ;
struct V_33 * V_92 ;
int V_38 ;
V_93:
V_92 = NULL ;
V_62 = NULL ;
V_38 = V_88 - 1 ;
F_13 ( V_86 ) ;
V_85 = V_30 . V_94 [ V_86 ] ;
if ( V_88 == 1 )
V_25 = F_16 ( V_85 -> V_95 ) ;
if ( V_25 != F_16 ( V_85 -> V_95 ) ) {
F_14 ( V_86 ) ;
F_4 ( V_9 , V_10 ) ;
return - V_41 ;
}
while ( V_87 < V_96 ) {
if ( V_92 == NULL )
V_92 = V_85 -> V_97 [ V_87 ] . V_44 ;
while ( V_92 != & V_85 -> V_97 [ V_87 ] ) {
T_9 * V_64 = F_17 ( V_92 , T_9 ,
V_98 ) ;
if ( V_38 == 0 ) {
V_62 = V_64 ;
if ( V_64 -> V_98 . V_44 ==
& V_85 -> V_97 [ V_87 ] ) {
V_88 = 1 ;
V_87 ++ ;
} else {
V_88 ++ ;
}
break;
}
V_38 -- ;
V_92 = V_64 -> V_98 . V_44 ;
}
if ( V_62 != NULL )
break;
V_92 = NULL ;
V_88 = 1 ;
V_87 ++ ;
}
if ( V_62 != NULL ) {
T_7 V_53 = V_62 -> V_55 ;
int V_69 = V_62 -> V_70 ;
int V_99 = - 1 ;
char * V_100 = L_24 ;
int V_101 = V_62 -> V_102 -> V_103 ;
int V_104 = V_62 -> V_105 ;
int V_106 = V_62 -> V_107 ;
int V_108 = V_62 -> V_109 ;
int V_110 = V_62 -> V_111 ;
int V_112 = V_62 -> V_113 ;
if ( F_27 ( V_62 ) ||
F_28 ( V_62 ) )
V_100 = V_62 -> V_57 ? L_13 : L_14 ;
if ( F_28 ( V_62 ) ) {
T_10 V_66 = F_21 () ;
T_12 V_114 ;
V_114 = F_23 ( V_66 , V_62 -> V_115 ) ;
V_99 = F_22 ( V_114 ) ;
if ( V_99 >= 10000 )
V_99 = 9999 ;
}
F_14 ( V_86 ) ;
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_35 ,
F_19 ( V_53 ) , V_69 , V_100 ,
V_99 , V_101 , V_108 , V_110 , V_104 ,
V_106 , V_112 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
} else {
F_14 ( V_86 ) ;
}
if ( V_87 == V_96 ) {
V_86 ++ ;
V_87 = 0 ;
V_88 = 1 ;
if ( V_62 == NULL && V_86 < V_91 )
goto V_93;
}
}
V_8 = V_24 - V_9 ;
if ( V_8 > * V_29 ) {
V_6 = - V_58 ;
} else if ( V_8 > 0 ) {
if ( F_20 ( V_4 , V_9 , V_8 ) )
V_6 = - V_59 ;
else
* V_28 = F_15 ( V_86 , V_25 , V_87 , V_88 ) ;
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
int V_116 ;
int V_8 ;
int V_6 ;
int V_40 ;
F_12 ( ! V_2 ) ;
V_10 = 64 * ( V_117 + 1 ) * V_91 ;
F_3 ( V_9 , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
V_24 = V_9 ;
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_36 ,
L_37 , L_38 , L_39 , L_32 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
if ( V_30 . V_118 == NULL )
goto V_119;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
T_13 * V_120 ;
F_13 ( V_121 ) ;
F_30 (rbp, i, the_lnet.ln_rtrpools) {
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_40 ,
V_120 [ V_116 ] . V_122 ,
V_120 [ V_116 ] . V_123 ,
V_120 [ V_116 ] . V_124 ,
V_120 [ V_116 ] . V_125 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
}
F_14 ( V_121 ) ;
}
V_119:
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
int V_10 = 128 * V_91 ;
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
L_41 ,
L_27 , L_42 , L_43 , L_28 , L_44 ,
L_31 , L_30 , L_33 , L_32 ) ;
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
} else {
struct V_33 * V_34 ;
T_15 * V_126 = NULL ;
int V_38 = * V_28 - 1 ;
F_13 ( 0 ) ;
V_34 = V_30 . V_127 . V_44 ;
while ( V_34 != & V_30 . V_127 ) {
T_15 * V_128 = F_17 ( V_34 , T_15 , V_129 ) ;
if ( V_38 == 0 ) {
V_126 = V_128 ;
break;
}
V_38 -- ;
V_34 = V_34 -> V_44 ;
}
if ( V_126 != NULL ) {
struct V_130 * V_131 ;
char * V_132 ;
long V_66 = F_31 () ;
int V_133 = - 1 ;
int V_40 ;
int V_134 ;
if ( V_30 . V_31 )
V_133 = V_66 - V_126 -> V_135 ;
if ( V_126 -> V_136 -> V_137 == V_138 )
V_133 = 0 ;
F_32 ( V_126 ) ;
F_12 ( V_126 -> V_139 != NULL ) ;
V_132 = ( V_126 -> V_139 -> V_140 ==
V_141 ) ? L_13 : L_14 ;
F_33 ( V_126 ) ;
F_30 (tq, i, ni->ni_tx_queues) {
for ( V_134 = 0 ; V_126 -> V_142 != NULL &&
V_134 < V_126 -> V_143 ; V_134 ++ ) {
if ( V_40 == V_126 -> V_142 [ V_134 ] )
break;
}
if ( V_134 == V_126 -> V_143 )
continue;
if ( V_40 != 0 )
F_13 ( V_40 ) ;
V_24 += snprintf ( V_24 , V_9 + V_10 - V_24 ,
L_45 ,
F_19 ( V_126 -> V_144 ) , V_132 ,
V_133 , * V_126 -> V_145 [ V_40 ] ,
V_126 -> V_103 ,
V_126 -> V_146 ,
V_131 -> V_147 ,
V_131 -> V_148 , V_131 -> V_149 ) ;
if ( V_40 != 0 )
F_14 ( V_40 ) ;
}
F_12 ( V_9 + V_10 - V_24 > 0 ) ;
}
F_14 ( 0 ) ;
}
V_8 = V_24 - V_9 ;
if ( V_8 > * V_29 ) {
V_6 = - V_58 ;
} else if ( V_8 > 0 ) {
if ( F_20 ( V_4 , V_9 , V_8 ) )
V_6 = - V_59 ;
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
const int V_150 = 128 ;
char * V_151 ;
char * V_152 ;
int V_6 ;
int V_40 ;
F_3 ( V_151 , V_150 ) ;
if ( V_151 == NULL )
return - V_11 ;
if ( ! V_2 ) {
F_35 ( 0 ) ;
for ( V_40 = 0 ; V_153 [ V_40 ] . V_154 >= 0 ; V_40 ++ ) {
if ( V_153 [ V_40 ] . V_154 == V_155 )
break;
}
F_12 ( V_153 [ V_40 ] . V_154 == V_155 ) ;
F_36 ( 0 ) ;
V_6 = snprintf ( V_151 , V_150 ,
L_46
L_47 ,
V_153 [ V_40 ] . V_156 ,
V_153 [ V_40 ] . V_157 ) ;
if ( V_3 >= F_6 ( int , V_6 , V_150 ) ) {
V_6 = 0 ;
} else {
V_6 = F_7 ( V_4 , V_5 ,
V_151 + V_3 , L_3 ) ;
}
goto V_119;
}
V_6 = F_37 ( V_151 , V_150 , V_4 , V_5 ) ;
if ( V_6 < 0 )
goto V_119;
V_152 = F_38 ( V_151 ) ;
V_6 = - V_58 ;
F_35 ( 0 ) ;
for ( V_40 = 0 ; V_153 [ V_40 ] . V_156 != NULL ; V_40 ++ ) {
if ( F_39 ( V_153 [ V_40 ] . V_156 , V_152 ,
strlen ( V_153 [ V_40 ] . V_156 ) ) == 0 ) {
V_155 = V_153 [ V_40 ] . V_154 ;
V_6 = 0 ;
break;
}
}
F_36 ( 0 ) ;
V_119:
F_4 ( V_151 , V_150 ) ;
return V_6 ;
}
void
F_40 ( void )
{
#ifdef F_41
if ( V_158 == NULL )
V_158 = F_42 ( V_159 , 0 ) ;
#endif
}
void
F_43 ( void )
{
#ifdef F_41
if ( V_158 != NULL )
F_44 ( V_158 ) ;
V_158 = NULL ;
#endif
}
void
F_40 ( void )
{
}
void
F_43 ( void )
{
}
