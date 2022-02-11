static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( V_6 , V_7 ) ;
if ( ! V_5 ) {
F_3 ( V_8 L_1 ) ;
F_4 () ;
}
V_5 -> V_9 = V_4 ;
V_5 -> V_10 = 0 ;
V_5 -> V_11 = 0 ;
F_5 ( & V_5 -> V_12 , & V_3 -> V_13 ) ;
return V_5 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_5 , * V_14 ;
F_7 (reg, n, &frame->reg_list, link) {
F_8 ( & V_5 -> V_12 ) ;
F_9 ( V_5 , V_6 ) ;
}
}
static struct V_1 * F_10 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
struct V_1 * V_5 ;
F_11 (reg, &frame->reg_list, link) {
if ( V_5 -> V_9 == V_4 )
return V_5 ;
}
return NULL ;
}
static inline int F_12 ( unsigned long * V_15 , unsigned long * V_16 )
{
T_1 V_17 = F_13 ( V_15 ) ;
F_14 ( V_17 , V_16 ) ;
return sizeof( unsigned long * ) ;
}
static inline unsigned long F_15 ( char * V_10 , unsigned int * V_18 )
{
unsigned int V_19 ;
unsigned char V_20 ;
int V_21 , V_22 ;
V_19 = 0 ;
V_21 = 0 ;
V_22 = 0 ;
while ( 1 ) {
V_20 = F_16 ( V_10 ) ;
V_10 ++ ;
V_22 ++ ;
V_19 |= ( V_20 & 0x7f ) << V_21 ;
V_21 += 7 ;
if ( ! ( V_20 & 0x80 ) )
break;
}
* V_18 = V_19 ;
return V_22 ;
}
static inline unsigned long F_17 ( char * V_10 , int * V_18 )
{
unsigned char V_20 ;
int V_19 , V_21 ;
int V_23 ;
int V_22 ;
V_19 = 0 ;
V_21 = 0 ;
V_22 = 0 ;
while ( 1 ) {
V_20 = F_16 ( V_10 ) ;
V_10 ++ ;
V_19 |= ( V_20 & 0x7f ) << V_21 ;
V_21 += 7 ;
V_22 ++ ;
if ( ! ( V_20 & 0x80 ) )
break;
}
V_23 = 8 * sizeof( V_19 ) ;
if ( ( V_21 < V_23 ) && ( V_20 & 0x40 ) )
V_19 |= ( - 1 << V_21 ) ;
* V_18 = V_19 ;
return V_22 ;
}
static int F_18 ( char * V_10 , unsigned long * V_17 ,
char V_24 )
{
unsigned long V_25 = 0 ;
int V_22 = 0 ;
switch ( V_24 & 0x70 ) {
case V_26 :
break;
case V_27 :
V_25 = ( unsigned long ) V_10 ;
break;
default:
F_19 ( L_2 , ( V_24 & 0x70 ) ) ;
F_4 () ;
}
if ( ( V_24 & 0x07 ) == 0x00 )
V_24 |= V_28 ;
switch ( V_24 & 0x0f ) {
case V_29 :
case V_28 :
V_22 += 4 ;
V_25 += F_13 ( ( T_1 * ) V_10 ) ;
F_20 ( V_25 , V_17 ) ;
break;
default:
F_19 ( L_2 , V_24 ) ;
F_4 () ;
}
return V_22 ;
}
static inline int F_21 ( char * V_10 , unsigned long * V_30 )
{
T_1 V_31 ;
int V_22 ;
V_31 = F_13 ( ( T_1 * ) V_10 ) ;
V_22 = 4 ;
if ( V_31 >= V_32 && V_31 <= V_33 ) {
if ( V_31 == V_34 ) {
* V_30 = F_13 ( ( V_35 * ) V_10 + 4 ) ;
V_22 = 12 ;
} else {
F_3 ( V_8 L_3 ) ;
V_22 = 0 ;
}
} else
* V_30 = V_31 ;
return V_22 ;
}
static struct V_36 * F_22 ( unsigned long V_37 )
{
struct V_38 * * V_38 = & V_39 . V_38 ;
struct V_36 * V_40 = NULL ;
unsigned long V_11 ;
F_23 ( & V_41 , V_11 ) ;
if ( V_42 && V_42 -> V_43 == V_37 ) {
V_40 = V_42 ;
goto V_44;
}
while ( * V_38 ) {
struct V_36 * V_45 ;
V_45 = F_24 ( * V_38 , struct V_36 , V_46 ) ;
F_25 ( ! V_45 ) ;
if ( V_37 == V_45 -> V_43 ) {
V_40 = V_45 ;
V_42 = V_45 ;
goto V_44;
} else {
if ( V_37 < V_45 -> V_43 )
V_38 = & ( * V_38 ) -> V_47 ;
else
V_38 = & ( * V_38 ) -> V_48 ;
}
}
V_44:
F_26 ( & V_41 , V_11 ) ;
return V_40 ;
}
struct V_49 * F_27 ( unsigned long V_50 )
{
struct V_38 * * V_38 = & V_51 . V_38 ;
struct V_49 * V_52 = NULL ;
unsigned long V_11 ;
F_23 ( & V_53 , V_11 ) ;
while ( * V_38 ) {
struct V_49 * V_54 ;
unsigned long V_55 , V_56 ;
V_54 = F_24 ( * V_38 , struct V_49 , V_46 ) ;
F_25 ( ! V_54 ) ;
V_55 = V_54 -> V_57 ;
V_56 = V_54 -> V_57 + V_54 -> V_58 ;
if ( V_50 < V_55 ) {
V_38 = & ( * V_38 ) -> V_47 ;
} else {
if ( V_50 < V_56 ) {
V_52 = V_54 ;
goto V_44;
} else
V_38 = & ( * V_38 ) -> V_48 ;
}
}
V_44:
F_26 ( & V_53 , V_11 ) ;
return V_52 ;
}
static int F_28 ( unsigned char * V_59 ,
unsigned char * V_60 ,
struct V_36 * V_40 ,
struct V_49 * V_52 ,
struct V_2 * V_3 ,
unsigned long V_50 )
{
unsigned char V_61 ;
unsigned char * V_62 ;
unsigned int V_22 , V_63 , V_5 , V_64 , V_65 ;
struct V_1 * V_66 ;
V_62 = V_59 ;
while ( V_62 < V_60 && V_3 -> V_50 <= V_50 ) {
V_61 = F_16 ( V_62 ++ ) ;
switch ( F_29 ( V_61 ) ) {
case V_67 :
V_63 = F_30 ( V_61 ) ;
V_63 *= V_40 -> V_68 ;
V_3 -> V_50 += V_63 ;
continue;
case V_69 :
V_5 = F_30 ( V_61 ) ;
V_22 = F_15 ( V_62 , & V_65 ) ;
V_62 += V_22 ;
V_65 *= V_40 -> V_70 ;
V_66 = F_1 ( V_3 , V_5 ) ;
V_66 -> V_10 = V_65 ;
V_66 -> V_11 |= V_71 ;
continue;
case V_72 :
V_5 = F_30 ( V_61 ) ;
continue;
}
switch ( V_61 ) {
case V_73 :
continue;
case V_74 :
V_63 = * V_62 ++ ;
V_3 -> V_50 += V_63 * V_40 -> V_68 ;
break;
case V_75 :
V_63 = F_13 ( ( V_76 * ) V_62 ) ;
V_62 += 2 ;
V_3 -> V_50 += V_63 * V_40 -> V_68 ;
break;
case V_77 :
V_63 = F_13 ( ( T_1 * ) V_62 ) ;
V_62 += 4 ;
V_3 -> V_50 += V_63 * V_40 -> V_68 ;
break;
case V_78 :
V_22 = F_15 ( V_62 , & V_5 ) ;
V_62 += V_22 ;
V_22 = F_15 ( V_62 , & V_65 ) ;
V_62 += V_22 ;
V_65 *= V_40 -> V_70 ;
break;
case V_79 :
V_22 = F_15 ( V_62 , & V_5 ) ;
V_62 += V_22 ;
break;
case V_80 :
V_22 = F_15 ( V_62 , & V_5 ) ;
V_62 += V_22 ;
V_66 = F_1 ( V_3 , V_5 ) ;
V_66 -> V_11 |= V_81 ;
break;
case V_82 :
V_22 = F_15 ( V_62 ,
& V_3 -> V_83 ) ;
V_62 += V_22 ;
V_22 = F_15 ( V_62 ,
& V_3 -> V_84 ) ;
V_62 += V_22 ;
V_3 -> V_11 |= V_85 ;
break;
case V_86 :
V_22 = F_15 ( V_62 ,
& V_3 -> V_83 ) ;
V_62 += V_22 ;
V_3 -> V_11 |= V_85 ;
break;
case V_87 :
V_22 = F_15 ( V_62 , & V_65 ) ;
V_62 += V_22 ;
V_3 -> V_84 = V_65 ;
break;
case V_88 :
V_22 = F_15 ( V_62 , & V_64 ) ;
V_62 += V_22 ;
V_3 -> V_89 = V_62 ;
V_3 -> V_90 = V_64 ;
V_62 += V_64 ;
V_3 -> V_11 |= V_91 ;
break;
case V_92 :
V_22 = F_15 ( V_62 , & V_5 ) ;
V_62 += V_22 ;
V_22 = F_17 ( V_62 , & V_65 ) ;
V_62 += V_22 ;
V_65 *= V_40 -> V_70 ;
V_66 = F_1 ( V_3 , V_5 ) ;
V_66 -> V_11 |= V_71 ;
V_66 -> V_10 = V_65 ;
break;
case V_93 :
V_22 = F_15 ( V_62 , & V_5 ) ;
V_62 += V_22 ;
V_22 = F_17 ( V_62 , & V_65 ) ;
V_65 *= V_40 -> V_70 ;
V_66 = F_1 ( V_3 , V_5 ) ;
V_66 -> V_11 |= V_94 ;
V_66 -> V_10 = V_65 ;
break;
case V_95 :
V_22 = F_15 ( V_62 , & V_65 ) ;
V_62 += V_22 ;
break;
case V_96 :
V_22 = F_15 ( V_62 , & V_5 ) ;
V_62 += V_22 ;
V_22 = F_15 ( V_62 , & V_65 ) ;
V_65 *= V_40 -> V_70 ;
V_66 = F_1 ( V_3 , V_5 ) ;
V_66 -> V_11 |= V_71 ;
V_66 -> V_10 = - V_65 ;
break;
default:
F_19 ( L_4 , V_61 ) ;
F_4 () ;
break;
}
}
return 0 ;
}
void F_31 ( struct V_2 * V_3 )
{
F_6 ( V_3 ) ;
F_9 ( V_3 , V_97 ) ;
}
struct V_2 * F_32 ( unsigned long V_50 ,
struct V_2 * V_98 )
{
struct V_2 * V_3 ;
struct V_36 * V_40 ;
struct V_49 * V_52 ;
struct V_1 * V_5 ;
unsigned long V_10 ;
if ( ! V_99 )
return NULL ;
if ( ! V_50 || ! V_98 )
V_50 = ( unsigned long ) F_33 () ;
#ifdef F_34
if ( V_50 == ( unsigned long ) & V_100 ) {
int V_101 = V_102 -> V_103 ;
F_35 ( V_101 > 0 ) ;
V_50 = V_102 -> V_104 [ V_101 ] . V_18 ;
}
#endif
V_3 = F_2 ( V_97 , V_7 ) ;
if ( ! V_3 ) {
F_3 ( V_105 L_5 ) ;
F_4 () ;
}
F_36 ( & V_3 -> V_13 ) ;
V_3 -> V_11 = 0 ;
V_3 -> V_98 = V_98 ;
V_3 -> V_106 = 0 ;
V_52 = F_27 ( V_50 ) ;
if ( ! V_52 ) {
goto V_107;
}
V_40 = F_22 ( V_52 -> V_43 ) ;
V_3 -> V_50 = V_52 -> V_57 ;
F_28 ( V_40 -> V_108 ,
V_40 -> V_109 , V_40 , V_52 ,
V_3 , V_50 ) ;
F_28 ( V_52 -> V_110 , V_52 -> V_111 , V_40 ,
V_52 , V_3 , V_50 ) ;
switch ( V_3 -> V_11 ) {
case V_85 :
if ( V_98 ) {
V_5 = F_10 ( V_98 , V_3 -> V_83 ) ;
F_37 ( ! V_5 ) ;
F_37 ( V_5 -> V_11 != V_71 ) ;
V_10 = V_98 -> V_112 + V_5 -> V_10 ;
V_3 -> V_112 = F_38 ( V_10 ) ;
} else {
V_3 -> V_112 = F_39 ( V_3 -> V_83 ) ;
}
V_3 -> V_112 += V_3 -> V_84 ;
break;
default:
F_4 () ;
}
V_5 = F_10 ( V_3 , V_113 ) ;
if ( ! V_5 || V_5 -> V_11 == V_81 )
goto V_107;
F_37 ( V_5 -> V_11 != V_71 ) ;
V_10 = V_3 -> V_112 + V_5 -> V_10 ;
V_3 -> V_106 = F_38 ( V_10 ) ;
if ( V_98 && V_98 -> V_50 == ( unsigned long ) V_114 )
V_3 -> V_106 = 0 ;
return V_3 ;
V_107:
F_31 ( V_3 ) ;
return NULL ;
}
static int F_40 ( void * V_115 , void * V_116 , unsigned long V_30 ,
unsigned char * V_111 , struct V_117 * V_118 )
{
struct V_38 * * V_38 = & V_39 . V_38 ;
struct V_38 * V_119 = * V_38 ;
struct V_36 * V_40 ;
unsigned long V_11 ;
int V_22 ;
V_40 = F_41 ( sizeof( * V_40 ) , V_120 ) ;
if ( ! V_40 )
return - V_121 ;
V_40 -> V_122 = V_30 ;
V_40 -> V_43 = ( unsigned long ) V_115 ;
V_40 -> V_123 = * ( char * ) V_116 ++ ;
F_37 ( V_40 -> V_123 != 1 ) ;
V_40 -> V_124 = V_116 ;
V_116 += strlen ( V_40 -> V_124 ) + 1 ;
V_22 = F_15 ( V_116 , & V_40 -> V_68 ) ;
V_116 += V_22 ;
V_22 = F_17 ( V_116 , & V_40 -> V_70 ) ;
V_116 += V_22 ;
if ( V_40 -> V_123 == 1 ) {
V_40 -> V_125 = F_16 ( V_116 ) ;
V_116 ++ ;
} else {
V_22 = F_15 ( V_116 , & V_40 -> V_125 ) ;
V_116 += V_22 ;
}
if ( V_40 -> V_124 [ 0 ] == 'z' ) {
unsigned int V_122 , V_22 ;
V_40 -> V_11 |= V_126 ;
V_22 = F_15 ( V_116 , & V_122 ) ;
V_116 += V_22 ;
F_37 ( ( unsigned char * ) V_116 > V_111 ) ;
V_40 -> V_108 = V_116 + V_122 ;
V_40 -> V_124 ++ ;
}
while ( * V_40 -> V_124 ) {
if ( * V_40 -> V_124 == 'L' ) {
V_116 ++ ;
V_40 -> V_124 ++ ;
} else if ( * V_40 -> V_124 == 'R' ) {
V_40 -> V_24 = * ( char * ) V_116 ++ ;
V_40 -> V_124 ++ ;
} else if ( * V_40 -> V_124 == 'P' ) {
F_4 () ;
} else if ( * V_40 -> V_124 == 'S' ) {
F_4 () ;
} else {
V_116 = V_40 -> V_108 ;
F_37 ( ! V_116 ) ;
break;
}
}
V_40 -> V_108 = V_116 ;
V_40 -> V_109 = V_111 ;
F_23 ( & V_41 , V_11 ) ;
while ( * V_38 ) {
struct V_36 * V_45 ;
V_45 = F_24 ( * V_38 , struct V_36 , V_46 ) ;
V_119 = * V_38 ;
if ( V_40 -> V_43 < V_45 -> V_43 )
V_38 = & V_119 -> V_47 ;
else if ( V_40 -> V_43 >= V_45 -> V_43 )
V_38 = & V_119 -> V_48 ;
else
F_35 ( 1 ) ;
}
F_42 ( & V_40 -> V_46 , V_119 , V_38 ) ;
F_43 ( & V_40 -> V_46 , & V_39 ) ;
#ifdef F_44
if ( V_118 != NULL )
F_45 ( & V_40 -> V_12 , & V_118 -> V_127 . V_128 ) ;
#endif
F_26 ( & V_41 , V_11 ) ;
return 0 ;
}
static int F_46 ( void * V_115 , T_1 V_129 ,
void * V_130 , unsigned long V_30 ,
unsigned char * V_111 , struct V_117 * V_118 )
{
struct V_38 * * V_38 = & V_51 . V_38 ;
struct V_38 * V_119 = * V_38 ;
struct V_49 * V_52 ;
struct V_36 * V_40 ;
unsigned long V_11 ;
int V_22 ;
void * V_116 = V_130 ;
V_52 = F_41 ( sizeof( * V_52 ) , V_120 ) ;
if ( ! V_52 )
return - V_121 ;
V_52 -> V_122 = V_30 ;
V_52 -> V_43 = ( unsigned long ) ( V_116 - V_129 - 4 ) ;
V_40 = F_22 ( V_52 -> V_43 ) ;
V_52 -> V_40 = V_40 ;
if ( V_40 -> V_24 )
V_22 = F_18 ( V_116 , & V_52 -> V_57 ,
V_40 -> V_24 ) ;
else
V_22 = F_12 ( V_116 , & V_52 -> V_57 ) ;
V_116 += V_22 ;
if ( V_40 -> V_24 )
V_22 = F_18 ( V_116 , & V_52 -> V_58 ,
V_40 -> V_24 & 0x0f ) ;
else
V_22 = F_12 ( V_116 , & V_52 -> V_58 ) ;
V_116 += V_22 ;
if ( V_52 -> V_40 -> V_11 & V_126 ) {
unsigned int V_122 ;
V_22 = F_15 ( V_116 , & V_122 ) ;
V_116 += V_22 + V_122 ;
}
V_52 -> V_110 = V_116 ;
V_52 -> V_111 = V_111 ;
F_23 ( & V_53 , V_11 ) ;
while ( * V_38 ) {
struct V_49 * V_54 ;
unsigned long V_55 , V_56 ;
unsigned long V_130 , V_111 ;
V_54 = F_24 ( * V_38 , struct V_49 , V_46 ) ;
V_130 = V_52 -> V_57 ;
V_111 = V_52 -> V_57 + V_52 -> V_58 ;
V_55 = V_54 -> V_57 ;
V_56 = V_54 -> V_57 + V_54 -> V_58 ;
V_119 = * V_38 ;
if ( V_130 < V_55 )
V_38 = & V_119 -> V_47 ;
else if ( V_130 >= V_56 )
V_38 = & V_119 -> V_48 ;
else
F_35 ( 1 ) ;
}
F_42 ( & V_52 -> V_46 , V_119 , V_38 ) ;
F_43 ( & V_52 -> V_46 , & V_51 ) ;
#ifdef F_44
if ( V_118 != NULL )
F_45 ( & V_52 -> V_12 , & V_118 -> V_127 . V_131 ) ;
#endif
F_26 ( & V_53 , V_11 ) ;
return 0 ;
}
static void F_47 ( struct V_132 * V_133 ,
struct V_134 * V_135 ,
unsigned long * V_136 ,
const struct V_137 * V_138 ,
void * V_139 )
{
struct V_2 * V_3 , * V_140 ;
unsigned long V_106 ;
V_140 = NULL ;
V_106 = 0 ;
while ( 1 ) {
V_3 = F_32 ( V_106 , V_140 ) ;
if ( V_140 )
F_31 ( V_140 ) ;
V_140 = V_3 ;
if ( ! V_3 || ! V_3 -> V_106 )
break;
V_106 = V_3 -> V_106 ;
V_138 -> V_141 ( V_139 , V_106 , 1 ) ;
}
if ( V_3 )
F_31 ( V_3 ) ;
}
static void F_48 ( void )
{
struct V_38 * * V_142 = & V_51 . V_38 ;
struct V_38 * * V_143 = & V_39 . V_38 ;
while ( * V_142 ) {
struct V_49 * V_52 ;
V_52 = F_24 ( * V_142 , struct V_49 , V_46 ) ;
F_49 ( * V_142 , & V_51 ) ;
F_50 ( V_52 ) ;
}
while ( * V_143 ) {
struct V_36 * V_40 ;
V_40 = F_24 ( * V_143 , struct V_36 , V_46 ) ;
F_49 ( * V_143 , & V_39 ) ;
F_50 ( V_40 ) ;
}
F_51 ( V_144 ) ;
F_51 ( V_145 ) ;
}
static int F_52 ( char * V_146 , char * V_147 ,
struct V_117 * V_118 )
{
T_1 V_129 ;
void * V_116 , * V_115 ;
int V_22 , V_148 = 0 ;
unsigned long V_30 = 0 ;
unsigned int V_149 , V_150 ;
unsigned char * V_111 ;
V_149 = 0 ;
V_150 = 0 ;
V_115 = V_146 ;
while ( ( char * ) V_115 < V_147 ) {
V_116 = V_115 ;
V_22 = F_21 ( V_116 , & V_30 ) ;
if ( V_22 == 0 ) {
V_148 = - V_151 ;
goto V_44;
} else
V_116 += V_22 ;
V_111 = V_116 + V_30 ;
V_129 = F_13 ( ( T_1 * ) V_116 ) ;
V_116 += 4 ;
if ( V_129 == V_152 ) {
V_148 = F_40 ( V_115 , V_116 , V_30 , V_111 , V_118 ) ;
if ( V_148 < 0 )
goto V_44;
else
V_149 ++ ;
} else {
V_148 = F_46 ( V_115 , V_129 , V_116 , V_30 ,
V_111 , V_118 ) ;
if ( V_148 < 0 )
goto V_44;
else
V_150 ++ ;
}
V_115 = ( char * ) V_115 + V_30 + 4 ;
}
F_3 ( V_153 L_6 ,
V_149 , V_150 ) ;
return 0 ;
V_44:
return V_148 ;
}
int F_53 ( const T_2 * V_154 , const T_3 * V_155 ,
struct V_117 * V_156 )
{
unsigned int V_157 , V_148 ;
unsigned long V_130 , V_111 ;
char * V_158 = ( void * ) V_154 + V_155 [ V_154 -> V_159 ] . V_160 ;
V_130 = V_111 = 0 ;
for ( V_157 = 1 ; V_157 < V_154 -> V_161 ; V_157 ++ ) {
if ( ( V_155 [ V_157 ] . V_162 & V_163 )
&& ! strcmp ( V_158 + V_155 [ V_157 ] . V_164 , L_7 ) ) {
V_130 = V_155 [ V_157 ] . V_165 ;
V_111 = V_130 + V_155 [ V_157 ] . V_166 ;
break;
}
}
if ( V_157 != V_154 -> V_161 ) {
F_36 ( & V_156 -> V_127 . V_128 ) ;
F_36 ( & V_156 -> V_127 . V_131 ) ;
V_148 = F_52 ( ( char * ) V_130 , ( char * ) V_111 , V_156 ) ;
if ( V_148 ) {
F_3 ( V_8 L_8 ,
V_156 -> V_167 ) ;
return V_148 ;
}
}
return 0 ;
}
void F_54 ( struct V_117 * V_118 )
{
struct V_49 * V_52 , * V_168 ;
struct V_36 * V_40 , * V_169 ;
unsigned long V_11 ;
F_23 ( & V_41 , V_11 ) ;
F_7 (cie, ctmp, &mod->arch.cie_list, link) {
F_8 ( & V_40 -> V_12 ) ;
F_49 ( & V_40 -> V_46 , & V_39 ) ;
F_50 ( V_40 ) ;
}
F_26 ( & V_41 , V_11 ) ;
F_23 ( & V_53 , V_11 ) ;
F_7 (fde, ftmp, &mod->arch.fde_list, link) {
F_8 ( & V_52 -> V_12 ) ;
F_49 ( & V_52 -> V_46 , & V_51 ) ;
F_50 ( V_52 ) ;
}
F_26 ( & V_53 , V_11 ) ;
}
static int T_4 F_55 ( void )
{
int V_148 = - V_121 ;
V_145 = F_56 ( L_9 ,
sizeof( struct V_2 ) , 0 ,
V_170 | V_171 | V_172 , NULL ) ;
V_144 = F_56 ( L_10 ,
sizeof( struct V_1 ) , 0 ,
V_170 | V_171 | V_172 , NULL ) ;
V_97 = F_57 ( V_173 ,
V_174 ,
V_175 ,
V_145 ) ;
if ( ! V_97 )
goto V_44;
V_6 = F_57 ( V_176 ,
V_174 ,
V_175 ,
V_144 ) ;
if ( ! V_6 )
goto V_44;
V_148 = F_52 ( V_177 , V_178 , NULL ) ;
if ( V_148 )
goto V_44;
V_148 = F_58 ( & V_179 ) ;
if ( V_148 )
goto V_44;
V_99 = 1 ;
return 0 ;
V_44:
F_3 ( V_105 L_11 , V_148 ) ;
F_48 () ;
return V_148 ;
}
