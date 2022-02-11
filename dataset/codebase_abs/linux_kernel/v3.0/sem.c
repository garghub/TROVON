void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = 0 ;
F_2 ( & V_2 -> V_12 [ V_13 ] ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 , & F_5 ( V_2 ) , V_14 ) ;
F_6 ( & V_2 -> V_12 [ V_13 ] . V_15 ) ;
}
void T_1 F_7 ( void )
{
F_1 ( & V_16 ) ;
F_8 ( L_1 ,
L_2 ,
V_13 , V_17 ) ;
}
static inline struct V_18 * F_9 ( struct V_1 * V_2 , int V_19 )
{
struct V_20 * V_21 = F_10 ( & F_5 ( V_2 ) , V_19 ) ;
if ( F_11 ( V_21 ) )
return (struct V_18 * ) V_21 ;
return F_12 ( V_21 , struct V_18 , V_22 ) ;
}
static inline struct V_18 * F_13 ( struct V_1 * V_2 ,
int V_19 )
{
struct V_20 * V_21 = F_14 ( & F_5 ( V_2 ) , V_19 ) ;
if ( F_11 ( V_21 ) )
return (struct V_18 * ) V_21 ;
return F_12 ( V_21 , struct V_18 , V_22 ) ;
}
static inline void F_15 ( struct V_18 * V_23 )
{
F_16 ( & V_23 -> V_22 ) ;
F_17 ( V_23 ) ;
}
static inline void F_18 ( struct V_18 * V_23 )
{
F_19 ( V_23 ) ;
F_20 ( & ( V_23 ) -> V_22 ) ;
}
static inline void F_21 ( struct V_18 * V_23 )
{
F_16 ( & V_23 -> V_22 ) ;
F_17 ( V_23 ) ;
F_20 ( & ( V_23 ) -> V_22 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , struct V_18 * V_24 )
{
F_23 ( & F_5 ( V_2 ) , & V_24 -> V_22 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
int V_19 ;
int V_27 ;
struct V_18 * V_23 ;
int V_28 ;
T_2 V_29 = V_26 -> V_29 ;
int V_30 = V_26 -> V_31 . V_30 ;
int V_32 = V_26 -> V_33 ;
int V_34 ;
if ( ! V_30 )
return - V_35 ;
if ( V_2 -> V_11 + V_30 > V_2 -> V_5 )
return - V_36 ;
V_28 = sizeof ( * V_23 ) + V_30 * sizeof ( struct V_37 ) ;
V_23 = F_25 ( V_28 ) ;
if ( ! V_23 ) {
return - V_38 ;
}
memset ( V_23 , 0 , V_28 ) ;
V_23 -> V_22 . V_39 = ( V_32 & V_40 ) ;
V_23 -> V_22 . V_29 = V_29 ;
V_23 -> V_22 . V_41 = NULL ;
V_27 = F_26 ( V_23 ) ;
if ( V_27 ) {
F_17 ( V_23 ) ;
return V_27 ;
}
V_19 = F_27 ( & F_5 ( V_2 ) , & V_23 -> V_22 , V_2 -> V_9 ) ;
if ( V_19 < 0 ) {
F_28 ( V_23 ) ;
F_17 ( V_23 ) ;
return V_19 ;
}
V_2 -> V_11 += V_30 ;
V_23 -> V_42 = (struct V_37 * ) & V_23 [ 1 ] ;
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ )
F_29 ( & V_23 -> V_42 [ V_34 ] . V_43 ) ;
V_23 -> V_44 = 0 ;
F_29 ( & V_23 -> V_43 ) ;
F_29 ( & V_23 -> V_45 ) ;
V_23 -> V_46 = V_30 ;
V_23 -> V_47 = F_30 () ;
F_31 ( V_23 ) ;
return V_23 -> V_22 . V_19 ;
}
static inline int F_32 ( struct V_20 * V_21 , int V_32 )
{
struct V_18 * V_23 ;
V_23 = F_12 ( V_21 , struct V_18 , V_22 ) ;
return F_33 ( V_23 , V_32 ) ;
}
static inline int F_34 ( struct V_20 * V_21 ,
struct V_25 * V_26 )
{
struct V_18 * V_23 ;
V_23 = F_12 ( V_21 , struct V_18 , V_22 ) ;
if ( V_26 -> V_31 . V_30 > V_23 -> V_46 )
return - V_35 ;
return 0 ;
}
static int F_35 ( struct V_18 * V_23 , struct V_48 * V_49 ,
int V_50 , struct V_51 * V_52 , int V_53 )
{
int V_54 , V_55 ;
struct V_48 * V_56 ;
struct V_37 * V_57 ;
for ( V_56 = V_49 ; V_56 < V_49 + V_50 ; V_56 ++ ) {
V_57 = V_23 -> V_42 + V_56 -> V_58 ;
V_55 = V_56 -> V_55 ;
V_54 = V_57 -> V_59 ;
if ( ! V_55 && V_54 )
goto V_60;
V_54 += V_55 ;
if ( V_54 < 0 )
goto V_60;
if ( V_54 > V_61 )
goto V_62;
if ( V_56 -> V_63 & V_64 ) {
int V_65 = V_52 -> V_66 [ V_56 -> V_58 ] - V_55 ;
if ( V_65 < ( - V_67 - 1 ) || V_65 > V_67 )
goto V_62;
}
V_57 -> V_59 = V_54 ;
}
V_56 -- ;
while ( V_56 >= V_49 ) {
V_23 -> V_42 [ V_56 -> V_58 ] . V_68 = V_53 ;
if ( V_56 -> V_63 & V_64 )
V_52 -> V_66 [ V_56 -> V_58 ] -= V_56 -> V_55 ;
V_56 -- ;
}
return 0 ;
V_62:
V_54 = - V_69 ;
goto V_65;
V_60:
if ( V_56 -> V_63 & V_70 )
V_54 = - V_71 ;
else
V_54 = 1 ;
V_65:
V_56 -- ;
while ( V_56 >= V_49 ) {
V_23 -> V_42 [ V_56 -> V_58 ] . V_59 -= V_56 -> V_55 ;
V_56 -- ;
}
return V_54 ;
}
static void F_36 ( struct V_72 * V_73 ,
struct V_74 * V_75 , int error )
{
if ( F_37 ( V_73 ) ) {
F_38 () ;
}
V_75 -> V_76 = V_77 ;
V_75 -> V_53 = error ;
F_39 ( & V_75 -> V_78 , V_73 ) ;
}
static void F_40 ( struct V_72 * V_73 )
{
struct V_74 * V_75 , * V_79 ;
int V_80 ;
V_80 = ! F_37 ( V_73 ) ;
F_41 (q, t, pt, simple_list) {
F_42 ( V_75 -> V_81 ) ;
F_43 () ;
V_75 -> V_76 = V_75 -> V_53 ;
}
if ( V_80 )
F_44 () ;
}
static void F_45 ( struct V_18 * V_23 , struct V_74 * V_75 )
{
F_46 ( & V_75 -> V_82 ) ;
if ( V_75 -> V_50 == 1 )
F_46 ( & V_75 -> V_78 ) ;
else
V_23 -> V_44 -- ;
}
static int F_47 ( struct V_18 * V_23 , struct V_74 * V_75 )
{
struct V_37 * V_57 ;
struct V_74 * V_83 ;
if ( V_75 -> V_84 == 0 )
return 0 ;
if ( V_23 -> V_44 )
return 1 ;
if ( V_75 -> V_50 > 1 )
return 1 ;
V_57 = V_23 -> V_42 + V_75 -> V_49 [ 0 ] . V_58 ;
if ( F_37 ( & V_57 -> V_43 ) )
return 0 ;
if ( V_57 -> V_59 ) {
F_48 ( V_75 -> V_49 [ 0 ] . V_55 >= 0 ) ;
return 0 ;
}
V_83 = F_49 ( & V_57 -> V_43 , struct V_74 , V_78 ) ;
F_48 ( V_83 -> V_50 != 1 ) ;
F_48 ( V_83 -> V_49 [ 0 ] . V_58 != V_75 -> V_49 [ 0 ] . V_58 ) ;
if ( V_83 -> V_49 [ 0 ] . V_55 == 0 )
return 1 ;
return 0 ;
}
static int F_50 ( struct V_18 * V_23 , int V_85 , struct V_72 * V_73 )
{
struct V_74 * V_75 ;
struct V_72 * V_86 ;
struct V_72 * V_87 ;
int V_88 ;
int V_89 = 0 ;
if ( V_23 -> V_44 )
V_85 = - 1 ;
if ( V_85 == - 1 ) {
V_87 = & V_23 -> V_43 ;
V_88 = F_51 ( struct V_74 , V_82 ) ;
} else {
V_87 = & V_23 -> V_42 [ V_85 ] . V_43 ;
V_88 = F_51 ( struct V_74 , V_78 ) ;
}
V_90:
V_86 = V_87 -> V_91 ;
while ( V_86 != V_87 ) {
int error , V_92 ;
V_75 = (struct V_74 * ) ( ( char * ) V_86 - V_88 ) ;
V_86 = V_86 -> V_91 ;
if ( V_85 != - 1 && V_23 -> V_42 [ V_85 ] . V_59 == 0 &&
V_75 -> V_84 )
break;
error = F_35 ( V_23 , V_75 -> V_49 , V_75 -> V_50 ,
V_75 -> V_65 , V_75 -> V_53 ) ;
if ( error > 0 )
continue;
F_45 ( V_23 , V_75 ) ;
if ( error ) {
V_92 = 0 ;
} else {
V_89 = 1 ;
V_92 = F_47 ( V_23 , V_75 ) ;
}
F_36 ( V_73 , V_75 , error ) ;
if ( V_92 )
goto V_90;
}
return V_89 ;
}
static void F_52 ( struct V_18 * V_23 , struct V_48 * V_49 , int V_50 ,
int V_93 , struct V_72 * V_73 )
{
int V_34 ;
if ( V_23 -> V_44 || V_49 == NULL ) {
if ( F_50 ( V_23 , - 1 , V_73 ) )
V_93 = 1 ;
goto V_94;
}
for ( V_34 = 0 ; V_34 < V_50 ; V_34 ++ ) {
if ( V_49 [ V_34 ] . V_55 > 0 ||
( V_49 [ V_34 ] . V_55 < 0 &&
V_23 -> V_42 [ V_49 [ V_34 ] . V_58 ] . V_59 == 0 ) )
if ( F_50 ( V_23 , V_49 [ V_34 ] . V_58 , V_73 ) )
V_93 = 1 ;
}
V_94:
if ( V_93 )
V_23 -> V_95 = F_30 () ;
}
static int F_53 ( struct V_18 * V_23 , T_3 V_85 )
{
int V_96 ;
struct V_74 * V_75 ;
V_96 = 0 ;
F_54 (q, &sma->sem_pending, list) {
struct V_48 * V_49 = V_75 -> V_49 ;
int V_50 = V_75 -> V_50 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_50 ; V_34 ++ )
if ( V_49 [ V_34 ] . V_58 == V_85
&& ( V_49 [ V_34 ] . V_55 < 0 )
&& ! ( V_49 [ V_34 ] . V_63 & V_70 ) )
V_96 ++ ;
}
return V_96 ;
}
static int F_55 ( struct V_18 * V_23 , T_3 V_85 )
{
int V_97 ;
struct V_74 * V_75 ;
V_97 = 0 ;
F_54 (q, &sma->sem_pending, list) {
struct V_48 * V_49 = V_75 -> V_49 ;
int V_50 = V_75 -> V_50 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_50 ; V_34 ++ )
if ( V_49 [ V_34 ] . V_58 == V_85
&& ( V_49 [ V_34 ] . V_55 == 0 )
&& ! ( V_49 [ V_34 ] . V_63 & V_70 ) )
V_97 ++ ;
}
return V_97 ;
}
static void F_56 ( struct V_98 * V_99 )
{
struct V_51 * V_52 = F_12 ( V_99 , struct V_51 , V_100 ) ;
F_57 ( V_52 ) ;
}
static void V_14 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_51 * V_52 , * V_101 ;
struct V_74 * V_75 , * V_102 ;
struct V_18 * V_23 = F_12 ( V_21 , struct V_18 , V_22 ) ;
struct V_72 V_103 ;
F_58 ( & V_23 -> V_22 . V_104 ) ;
F_41 (un, tu, &sma->list_id, list_id) {
F_46 ( & V_52 -> V_45 ) ;
F_59 ( & V_52 -> V_105 -> V_104 ) ;
V_52 -> V_106 = - 1 ;
F_60 ( & V_52 -> V_107 ) ;
F_61 ( & V_52 -> V_105 -> V_104 ) ;
F_62 ( & V_52 -> V_100 , F_56 ) ;
}
F_29 ( & V_103 ) ;
F_41 (q, tq, &sma->sem_pending, list) {
F_45 ( V_23 , V_75 ) ;
F_36 ( & V_103 , V_75 , - V_108 ) ;
}
F_22 ( V_2 , V_23 ) ;
F_31 ( V_23 ) ;
F_40 ( & V_103 ) ;
V_2 -> V_11 -= V_23 -> V_46 ;
F_28 ( V_23 ) ;
F_17 ( V_23 ) ;
}
static unsigned long F_63 ( void T_4 * V_109 , struct V_110 * V_111 , int V_112 )
{
switch( V_112 ) {
case V_113 :
return F_64 ( V_109 , V_111 , sizeof( * V_111 ) ) ;
case V_114 :
{
struct V_115 V_116 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
F_65 ( & V_111 -> V_22 , & V_116 . V_22 ) ;
V_116 . V_95 = V_111 -> V_95 ;
V_116 . V_47 = V_111 -> V_47 ;
V_116 . V_46 = V_111 -> V_46 ;
return F_64 ( V_109 , & V_116 , sizeof( V_116 ) ) ;
}
default:
return - V_35 ;
}
}
static int F_66 ( struct V_1 * V_2 , int V_106 ,
int V_117 , int V_112 , union V_118 V_119 )
{
int V_120 ;
struct V_18 * V_23 ;
switch( V_117 ) {
case V_121 :
case V_122 :
{
struct V_123 V_123 ;
int V_124 ;
V_120 = F_67 ( NULL , V_117 ) ;
if ( V_120 )
return V_120 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_125 = V_2 -> V_9 ;
V_123 . V_126 = V_2 -> V_5 ;
V_123 . V_127 = V_2 -> V_3 ;
V_123 . V_128 = V_2 -> V_7 ;
V_123 . V_129 = V_61 ;
V_123 . V_130 = V_131 ;
V_123 . V_132 = V_133 ;
V_123 . V_134 = V_135 ;
F_68 ( & F_5 ( V_2 ) . V_136 ) ;
if ( V_117 == V_122 ) {
V_123 . V_137 = F_5 ( V_2 ) . V_138 ;
V_123 . V_139 = V_2 -> V_11 ;
} else {
V_123 . V_137 = V_140 ;
V_123 . V_139 = V_67 ;
}
V_124 = F_69 ( & F_5 ( V_2 ) ) ;
F_70 ( & F_5 ( V_2 ) . V_136 ) ;
if ( F_64 ( V_119 . V_141 , & V_123 , sizeof( struct V_123 ) ) )
return - V_142 ;
return ( V_124 < 0 ) ? 0 : V_124 ;
}
case V_143 :
case V_144 :
{
struct V_110 V_145 ;
int V_19 ;
if ( V_117 == V_144 ) {
V_23 = F_9 ( V_2 , V_106 ) ;
if ( F_11 ( V_23 ) )
return F_71 ( V_23 ) ;
V_19 = V_23 -> V_22 . V_19 ;
} else {
V_23 = F_13 ( V_2 , V_106 ) ;
if ( F_11 ( V_23 ) )
return F_71 ( V_23 ) ;
V_19 = 0 ;
}
V_120 = - V_146 ;
if ( F_72 ( V_2 , & V_23 -> V_22 , V_147 ) )
goto V_148;
V_120 = F_67 ( V_23 , V_117 ) ;
if ( V_120 )
goto V_148;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
F_73 ( & V_23 -> V_22 , & V_145 . V_22 ) ;
V_145 . V_95 = V_23 -> V_95 ;
V_145 . V_47 = V_23 -> V_47 ;
V_145 . V_46 = V_23 -> V_46 ;
F_31 ( V_23 ) ;
if ( F_63 ( V_119 . V_109 , & V_145 , V_112 ) )
return - V_142 ;
return V_19 ;
}
default:
return - V_35 ;
}
V_148:
F_31 ( V_23 ) ;
return V_120 ;
}
static int F_74 ( struct V_1 * V_2 , int V_106 , int V_85 ,
int V_117 , int V_112 , union V_118 V_119 )
{
struct V_18 * V_23 ;
struct V_37 * V_57 ;
int V_120 ;
T_3 V_149 [ V_150 ] ;
T_3 * V_151 = V_149 ;
int V_30 ;
struct V_72 V_103 ;
V_23 = F_13 ( V_2 , V_106 ) ;
if ( F_11 ( V_23 ) )
return F_71 ( V_23 ) ;
F_29 ( & V_103 ) ;
V_30 = V_23 -> V_46 ;
V_120 = - V_146 ;
if ( F_72 ( V_2 , & V_23 -> V_22 ,
( V_117 == V_152 || V_117 == V_153 ) ? V_154 : V_147 ) )
goto V_148;
V_120 = F_67 ( V_23 , V_117 ) ;
if ( V_120 )
goto V_148;
V_120 = - V_146 ;
switch ( V_117 ) {
case V_155 :
{
T_3 T_4 * V_156 = V_119 . V_156 ;
int V_34 ;
if( V_30 > V_150 ) {
F_18 ( V_23 ) ;
V_151 = F_75 ( sizeof( T_3 ) * V_30 ) ;
if( V_151 == NULL ) {
F_21 ( V_23 ) ;
return - V_38 ;
}
F_15 ( V_23 ) ;
if ( V_23 -> V_22 . V_157 ) {
F_31 ( V_23 ) ;
V_120 = - V_108 ;
goto V_158;
}
}
for ( V_34 = 0 ; V_34 < V_23 -> V_46 ; V_34 ++ )
V_151 [ V_34 ] = V_23 -> V_42 [ V_34 ] . V_59 ;
F_31 ( V_23 ) ;
V_120 = 0 ;
if( F_64 ( V_156 , V_151 , V_30 * sizeof( T_3 ) ) )
V_120 = - V_142 ;
goto V_158;
}
case V_153 :
{
int V_34 ;
struct V_51 * V_52 ;
F_18 ( V_23 ) ;
if( V_30 > V_150 ) {
V_151 = F_75 ( sizeof( T_3 ) * V_30 ) ;
if( V_151 == NULL ) {
F_21 ( V_23 ) ;
return - V_38 ;
}
}
if ( F_76 ( V_151 , V_119 . V_156 , V_30 * sizeof( T_3 ) ) ) {
F_21 ( V_23 ) ;
V_120 = - V_142 ;
goto V_158;
}
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ ) {
if ( V_151 [ V_34 ] > V_61 ) {
F_21 ( V_23 ) ;
V_120 = - V_69 ;
goto V_158;
}
}
F_15 ( V_23 ) ;
if ( V_23 -> V_22 . V_157 ) {
F_31 ( V_23 ) ;
V_120 = - V_108 ;
goto V_158;
}
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ )
V_23 -> V_42 [ V_34 ] . V_59 = V_151 [ V_34 ] ;
F_58 ( & V_23 -> V_22 . V_104 ) ;
F_54 (un, &sma->list_id, list_id) {
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ )
V_52 -> V_66 [ V_34 ] = 0 ;
}
V_23 -> V_47 = F_30 () ;
F_52 ( V_23 , NULL , 0 , 0 , & V_103 ) ;
V_120 = 0 ;
goto V_148;
}
}
V_120 = - V_35 ;
if( V_85 < 0 || V_85 >= V_30 )
goto V_148;
V_57 = & V_23 -> V_42 [ V_85 ] ;
switch ( V_117 ) {
case V_159 :
V_120 = V_57 -> V_59 ;
goto V_148;
case V_160 :
V_120 = V_57 -> V_68 ;
goto V_148;
case V_161 :
V_120 = F_53 ( V_23 , V_85 ) ;
goto V_148;
case V_162 :
V_120 = F_55 ( V_23 , V_85 ) ;
goto V_148;
case V_152 :
{
int V_163 = V_119 . V_163 ;
struct V_51 * V_52 ;
V_120 = - V_69 ;
if ( V_163 > V_61 || V_163 < 0 )
goto V_148;
F_58 ( & V_23 -> V_22 . V_104 ) ;
F_54 (un, &sma->list_id, list_id)
V_52 -> V_66 [ V_85 ] = 0 ;
V_57 -> V_59 = V_163 ;
V_57 -> V_68 = F_77 ( V_164 ) ;
V_23 -> V_47 = F_30 () ;
F_52 ( V_23 , NULL , 0 , 0 , & V_103 ) ;
V_120 = 0 ;
goto V_148;
}
}
V_148:
F_31 ( V_23 ) ;
F_40 ( & V_103 ) ;
V_158:
if( V_151 != V_149 )
F_78 ( V_151 , sizeof( T_3 ) * V_30 ) ;
return V_120 ;
}
static inline unsigned long
F_79 ( struct V_110 * V_116 , void T_4 * V_109 , int V_112 )
{
switch( V_112 ) {
case V_113 :
if ( F_76 ( V_116 , V_109 , sizeof( * V_116 ) ) )
return - V_142 ;
return 0 ;
case V_114 :
{
struct V_115 V_165 ;
if( F_76 ( & V_165 , V_109 , sizeof( V_165 ) ) )
return - V_142 ;
V_116 -> V_22 . V_166 = V_165 . V_22 . V_166 ;
V_116 -> V_22 . V_167 = V_165 . V_22 . V_167 ;
V_116 -> V_22 . V_39 = V_165 . V_22 . V_39 ;
return 0 ;
}
default:
return - V_35 ;
}
}
static int F_80 ( struct V_1 * V_2 , int V_106 ,
int V_117 , int V_112 , union V_118 V_119 )
{
struct V_18 * V_23 ;
int V_120 ;
struct V_110 V_168 ;
struct V_20 * V_21 ;
if( V_117 == V_169 ) {
if ( F_79 ( & V_168 , V_119 . V_109 , V_112 ) )
return - V_142 ;
}
V_21 = F_81 ( V_2 , & F_5 ( V_2 ) , V_106 , V_117 ,
& V_168 . V_22 , 0 ) ;
if ( F_11 ( V_21 ) )
return F_71 ( V_21 ) ;
V_23 = F_12 ( V_21 , struct V_18 , V_22 ) ;
V_120 = F_67 ( V_23 , V_117 ) ;
if ( V_120 )
goto V_148;
switch( V_117 ) {
case V_170 :
V_14 ( V_2 , V_21 ) ;
goto V_171;
case V_169 :
F_82 ( & V_168 . V_22 , V_21 ) ;
V_23 -> V_47 = F_30 () ;
break;
default:
V_120 = - V_35 ;
}
V_148:
F_31 ( V_23 ) ;
V_171:
F_83 ( & F_5 ( V_2 ) . V_136 ) ;
return V_120 ;
}
T_5 (F_84)( int V_106 , int V_85 , int V_117 , union V_118 V_119 )
{
int V_120 = - V_35 ;
int V_112 ;
struct V_1 * V_2 ;
if ( V_106 < 0 )
return - V_35 ;
V_112 = F_85 ( & V_117 ) ;
V_2 = V_164 -> V_172 -> V_173 ;
switch( V_117 ) {
case V_121 :
case V_122 :
case V_143 :
case V_144 :
V_120 = F_66 ( V_2 , V_106 , V_117 , V_112 , V_119 ) ;
return V_120 ;
case V_155 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_152 :
case V_153 :
V_120 = F_74 ( V_2 , V_106 , V_85 , V_117 , V_112 , V_119 ) ;
return V_120 ;
case V_170 :
case V_169 :
V_120 = F_80 ( V_2 , V_106 , V_117 , V_112 , V_119 ) ;
return V_120 ;
default:
return - V_35 ;
}
}
T_6 long F_86 ( int V_106 , int V_85 , int V_117 , union V_118 V_119 )
{
return F_87 ( ( int ) V_106 , ( int ) V_85 , ( int ) V_117 , V_119 ) ;
}
static inline int F_88 ( struct V_174 * * V_175 )
{
struct V_174 * V_176 ;
V_176 = V_164 -> V_177 . V_176 ;
if ( ! V_176 ) {
V_176 = F_89 ( sizeof( * V_176 ) , V_178 ) ;
if ( V_176 == NULL )
return - V_38 ;
F_90 ( & V_176 -> V_104 ) ;
F_91 ( & V_176 -> V_179 , 1 ) ;
F_29 ( & V_176 -> V_107 ) ;
V_164 -> V_177 . V_176 = V_176 ;
}
* V_175 = V_176 ;
return 0 ;
}
static struct V_51 * F_92 ( struct V_174 * V_105 , int V_106 )
{
struct V_51 * V_52 ;
F_93 (un, &ulp->list_proc, list_proc) {
if ( V_52 -> V_106 == V_106 )
return V_52 ;
}
return NULL ;
}
static struct V_51 * F_94 ( struct V_174 * V_105 , int V_106 )
{
struct V_51 * V_52 ;
F_58 ( & V_105 -> V_104 ) ;
V_52 = F_92 ( V_105 , V_106 ) ;
if ( V_52 ) {
F_60 ( & V_52 -> V_107 ) ;
F_95 ( & V_52 -> V_107 , & V_105 -> V_107 ) ;
}
return V_52 ;
}
static struct V_51 * F_96 ( struct V_1 * V_2 , int V_106 )
{
struct V_18 * V_23 ;
struct V_174 * V_105 ;
struct V_51 * V_52 , * V_180 ;
int V_30 ;
int error ;
error = F_88 ( & V_105 ) ;
if ( error )
return F_97 ( error ) ;
F_98 () ;
F_59 ( & V_105 -> V_104 ) ;
V_52 = F_94 ( V_105 , V_106 ) ;
F_61 ( & V_105 -> V_104 ) ;
if ( F_99 ( V_52 != NULL ) )
goto V_116;
F_100 () ;
V_23 = F_13 ( V_2 , V_106 ) ;
if ( F_11 ( V_23 ) )
return F_101 ( V_23 ) ;
V_30 = V_23 -> V_46 ;
F_18 ( V_23 ) ;
V_180 = F_89 ( sizeof( struct V_51 ) + sizeof( short ) * V_30 , V_178 ) ;
if ( ! V_180 ) {
F_21 ( V_23 ) ;
return F_97 ( - V_38 ) ;
}
F_15 ( V_23 ) ;
if ( V_23 -> V_22 . V_157 ) {
F_31 ( V_23 ) ;
F_57 ( V_180 ) ;
V_52 = F_97 ( - V_108 ) ;
goto V_116;
}
F_59 ( & V_105 -> V_104 ) ;
V_52 = F_94 ( V_105 , V_106 ) ;
if ( V_52 ) {
F_57 ( V_180 ) ;
goto V_181;
}
V_180 -> V_66 = ( short * ) & V_180 [ 1 ] ;
V_180 -> V_105 = V_105 ;
V_180 -> V_106 = V_106 ;
F_58 ( & V_105 -> V_104 ) ;
F_95 ( & V_180 -> V_107 , & V_105 -> V_107 ) ;
F_58 ( & V_23 -> V_22 . V_104 ) ;
F_102 ( & V_180 -> V_45 , & V_23 -> V_45 ) ;
V_52 = V_180 ;
V_181:
F_61 ( & V_105 -> V_104 ) ;
F_98 () ;
F_31 ( V_23 ) ;
V_116:
return V_52 ;
}
static int F_103 ( struct V_74 * V_75 )
{
int error ;
error = V_75 -> V_76 ;
while ( F_104 ( error == V_77 ) ) {
F_105 () ;
error = V_75 -> V_76 ;
}
return error ;
}
int F_106 ( unsigned long V_182 , struct V_183 * V_184 )
{
struct V_174 * V_176 ;
int error ;
if ( V_182 & V_185 ) {
error = F_88 ( & V_176 ) ;
if ( error )
return error ;
F_107 ( & V_176 -> V_179 ) ;
V_184 -> V_177 . V_176 = V_176 ;
} else
V_184 -> V_177 . V_176 = NULL ;
return 0 ;
}
void F_108 ( struct V_183 * V_184 )
{
struct V_174 * V_105 ;
V_105 = V_184 -> V_177 . V_176 ;
if ( ! V_105 )
return;
V_184 -> V_177 . V_176 = NULL ;
if ( ! F_109 ( & V_105 -> V_179 ) )
return;
for (; ; ) {
struct V_18 * V_23 ;
struct V_51 * V_52 ;
struct V_72 V_103 ;
int V_106 ;
int V_34 ;
F_98 () ;
V_52 = F_110 ( V_105 -> V_107 . V_91 ,
struct V_51 , V_107 ) ;
if ( & V_52 -> V_107 == & V_105 -> V_107 )
V_106 = - 1 ;
else
V_106 = V_52 -> V_106 ;
F_100 () ;
if ( V_106 == - 1 )
break;
V_23 = F_13 ( V_184 -> V_172 -> V_173 , V_52 -> V_106 ) ;
if ( F_11 ( V_23 ) )
continue;
V_52 = F_92 ( V_105 , V_106 ) ;
if ( V_52 == NULL ) {
F_31 ( V_23 ) ;
continue;
}
F_58 ( & V_23 -> V_22 . V_104 ) ;
F_46 ( & V_52 -> V_45 ) ;
F_59 ( & V_105 -> V_104 ) ;
F_60 ( & V_52 -> V_107 ) ;
F_61 ( & V_105 -> V_104 ) ;
for ( V_34 = 0 ; V_34 < V_23 -> V_46 ; V_34 ++ ) {
struct V_37 * V_186 = & V_23 -> V_42 [ V_34 ] ;
if ( V_52 -> V_66 [ V_34 ] ) {
V_186 -> V_59 += V_52 -> V_66 [ V_34 ] ;
if ( V_186 -> V_59 < 0 )
V_186 -> V_59 = 0 ;
if ( V_186 -> V_59 > V_61 )
V_186 -> V_59 = V_61 ;
V_186 -> V_68 = F_77 ( V_164 ) ;
}
}
F_29 ( & V_103 ) ;
F_52 ( V_23 , NULL , 0 , 1 , & V_103 ) ;
F_31 ( V_23 ) ;
F_40 ( & V_103 ) ;
F_62 ( & V_52 -> V_100 , F_56 ) ;
}
F_57 ( V_105 ) ;
}
static int V_17 ( struct V_187 * V_24 , void * V_188 )
{
struct V_18 * V_23 = V_188 ;
return F_111 ( V_24 ,
L_3 ,
V_23 -> V_22 . V_29 ,
V_23 -> V_22 . V_19 ,
V_23 -> V_22 . V_39 ,
V_23 -> V_46 ,
V_23 -> V_22 . V_166 ,
V_23 -> V_22 . V_167 ,
V_23 -> V_22 . V_189 ,
V_23 -> V_22 . V_190 ,
V_23 -> V_95 ,
V_23 -> V_47 ) ;
}
