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
static void V_14 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_51 * V_52 , * V_98 ;
struct V_74 * V_75 , * V_99 ;
struct V_18 * V_23 = F_12 ( V_21 , struct V_18 , V_22 ) ;
struct V_72 V_100 ;
F_56 ( & V_23 -> V_22 . V_101 ) ;
F_41 (un, tu, &sma->list_id, list_id) {
F_46 ( & V_52 -> V_45 ) ;
F_57 ( & V_52 -> V_102 -> V_101 ) ;
V_52 -> V_103 = - 1 ;
F_58 ( & V_52 -> V_104 ) ;
F_59 ( & V_52 -> V_102 -> V_101 ) ;
F_60 ( V_52 , V_105 ) ;
}
F_29 ( & V_100 ) ;
F_41 (q, tq, &sma->sem_pending, list) {
F_45 ( V_23 , V_75 ) ;
F_36 ( & V_100 , V_75 , - V_106 ) ;
}
F_22 ( V_2 , V_23 ) ;
F_31 ( V_23 ) ;
F_40 ( & V_100 ) ;
V_2 -> V_11 -= V_23 -> V_46 ;
F_28 ( V_23 ) ;
F_17 ( V_23 ) ;
}
static unsigned long F_61 ( void T_4 * V_107 , struct V_108 * V_109 , int V_110 )
{
switch( V_110 ) {
case V_111 :
return F_62 ( V_107 , V_109 , sizeof( * V_109 ) ) ;
case V_112 :
{
struct V_113 V_114 ;
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
F_63 ( & V_109 -> V_22 , & V_114 . V_22 ) ;
V_114 . V_95 = V_109 -> V_95 ;
V_114 . V_47 = V_109 -> V_47 ;
V_114 . V_46 = V_109 -> V_46 ;
return F_62 ( V_107 , & V_114 , sizeof( V_114 ) ) ;
}
default:
return - V_35 ;
}
}
static int F_64 ( struct V_1 * V_2 , int V_103 ,
int V_115 , int V_110 , union V_116 V_117 )
{
int V_118 ;
struct V_18 * V_23 ;
switch( V_115 ) {
case V_119 :
case V_120 :
{
struct V_121 V_121 ;
int V_122 ;
V_118 = F_65 ( NULL , V_115 ) ;
if ( V_118 )
return V_118 ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_123 = V_2 -> V_9 ;
V_121 . V_124 = V_2 -> V_5 ;
V_121 . V_125 = V_2 -> V_3 ;
V_121 . V_126 = V_2 -> V_7 ;
V_121 . V_127 = V_61 ;
V_121 . V_128 = V_129 ;
V_121 . V_130 = V_131 ;
V_121 . V_132 = V_133 ;
F_66 ( & F_5 ( V_2 ) . V_134 ) ;
if ( V_115 == V_120 ) {
V_121 . V_135 = F_5 ( V_2 ) . V_136 ;
V_121 . V_137 = V_2 -> V_11 ;
} else {
V_121 . V_135 = V_138 ;
V_121 . V_137 = V_67 ;
}
V_122 = F_67 ( & F_5 ( V_2 ) ) ;
F_68 ( & F_5 ( V_2 ) . V_134 ) ;
if ( F_62 ( V_117 . V_139 , & V_121 , sizeof( struct V_121 ) ) )
return - V_140 ;
return ( V_122 < 0 ) ? 0 : V_122 ;
}
case V_141 :
case V_142 :
{
struct V_108 V_143 ;
int V_19 ;
if ( V_115 == V_142 ) {
V_23 = F_9 ( V_2 , V_103 ) ;
if ( F_11 ( V_23 ) )
return F_69 ( V_23 ) ;
V_19 = V_23 -> V_22 . V_19 ;
} else {
V_23 = F_13 ( V_2 , V_103 ) ;
if ( F_11 ( V_23 ) )
return F_69 ( V_23 ) ;
V_19 = 0 ;
}
V_118 = - V_144 ;
if ( F_70 ( V_2 , & V_23 -> V_22 , V_145 ) )
goto V_146;
V_118 = F_65 ( V_23 , V_115 ) ;
if ( V_118 )
goto V_146;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
F_71 ( & V_23 -> V_22 , & V_143 . V_22 ) ;
V_143 . V_95 = V_23 -> V_95 ;
V_143 . V_47 = V_23 -> V_47 ;
V_143 . V_46 = V_23 -> V_46 ;
F_31 ( V_23 ) ;
if ( F_61 ( V_117 . V_107 , & V_143 , V_110 ) )
return - V_140 ;
return V_19 ;
}
default:
return - V_35 ;
}
V_146:
F_31 ( V_23 ) ;
return V_118 ;
}
static int F_72 ( struct V_1 * V_2 , int V_103 , int V_85 ,
int V_115 , int V_110 , union V_116 V_117 )
{
struct V_18 * V_23 ;
struct V_37 * V_57 ;
int V_118 ;
T_3 V_147 [ V_148 ] ;
T_3 * V_149 = V_147 ;
int V_30 ;
struct V_72 V_100 ;
V_23 = F_13 ( V_2 , V_103 ) ;
if ( F_11 ( V_23 ) )
return F_69 ( V_23 ) ;
F_29 ( & V_100 ) ;
V_30 = V_23 -> V_46 ;
V_118 = - V_144 ;
if ( F_70 ( V_2 , & V_23 -> V_22 ,
( V_115 == V_150 || V_115 == V_151 ) ? V_152 : V_145 ) )
goto V_146;
V_118 = F_65 ( V_23 , V_115 ) ;
if ( V_118 )
goto V_146;
V_118 = - V_144 ;
switch ( V_115 ) {
case V_153 :
{
T_3 T_4 * V_154 = V_117 . V_154 ;
int V_34 ;
if( V_30 > V_148 ) {
F_18 ( V_23 ) ;
V_149 = F_73 ( sizeof( T_3 ) * V_30 ) ;
if( V_149 == NULL ) {
F_21 ( V_23 ) ;
return - V_38 ;
}
F_15 ( V_23 ) ;
if ( V_23 -> V_22 . V_155 ) {
F_31 ( V_23 ) ;
V_118 = - V_106 ;
goto V_156;
}
}
for ( V_34 = 0 ; V_34 < V_23 -> V_46 ; V_34 ++ )
V_149 [ V_34 ] = V_23 -> V_42 [ V_34 ] . V_59 ;
F_31 ( V_23 ) ;
V_118 = 0 ;
if( F_62 ( V_154 , V_149 , V_30 * sizeof( T_3 ) ) )
V_118 = - V_140 ;
goto V_156;
}
case V_151 :
{
int V_34 ;
struct V_51 * V_52 ;
F_18 ( V_23 ) ;
if( V_30 > V_148 ) {
V_149 = F_73 ( sizeof( T_3 ) * V_30 ) ;
if( V_149 == NULL ) {
F_21 ( V_23 ) ;
return - V_38 ;
}
}
if ( F_74 ( V_149 , V_117 . V_154 , V_30 * sizeof( T_3 ) ) ) {
F_21 ( V_23 ) ;
V_118 = - V_140 ;
goto V_156;
}
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ ) {
if ( V_149 [ V_34 ] > V_61 ) {
F_21 ( V_23 ) ;
V_118 = - V_69 ;
goto V_156;
}
}
F_15 ( V_23 ) ;
if ( V_23 -> V_22 . V_155 ) {
F_31 ( V_23 ) ;
V_118 = - V_106 ;
goto V_156;
}
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ )
V_23 -> V_42 [ V_34 ] . V_59 = V_149 [ V_34 ] ;
F_56 ( & V_23 -> V_22 . V_101 ) ;
F_54 (un, &sma->list_id, list_id) {
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ )
V_52 -> V_66 [ V_34 ] = 0 ;
}
V_23 -> V_47 = F_30 () ;
F_52 ( V_23 , NULL , 0 , 0 , & V_100 ) ;
V_118 = 0 ;
goto V_146;
}
}
V_118 = - V_35 ;
if( V_85 < 0 || V_85 >= V_30 )
goto V_146;
V_57 = & V_23 -> V_42 [ V_85 ] ;
switch ( V_115 ) {
case V_157 :
V_118 = V_57 -> V_59 ;
goto V_146;
case V_158 :
V_118 = V_57 -> V_68 ;
goto V_146;
case V_159 :
V_118 = F_53 ( V_23 , V_85 ) ;
goto V_146;
case V_160 :
V_118 = F_55 ( V_23 , V_85 ) ;
goto V_146;
case V_150 :
{
int V_161 = V_117 . V_161 ;
struct V_51 * V_52 ;
V_118 = - V_69 ;
if ( V_161 > V_61 || V_161 < 0 )
goto V_146;
F_56 ( & V_23 -> V_22 . V_101 ) ;
F_54 (un, &sma->list_id, list_id)
V_52 -> V_66 [ V_85 ] = 0 ;
V_57 -> V_59 = V_161 ;
V_57 -> V_68 = F_75 ( V_162 ) ;
V_23 -> V_47 = F_30 () ;
F_52 ( V_23 , NULL , 0 , 0 , & V_100 ) ;
V_118 = 0 ;
goto V_146;
}
}
V_146:
F_31 ( V_23 ) ;
F_40 ( & V_100 ) ;
V_156:
if( V_149 != V_147 )
F_76 ( V_149 , sizeof( T_3 ) * V_30 ) ;
return V_118 ;
}
static inline unsigned long
F_77 ( struct V_108 * V_114 , void T_4 * V_107 , int V_110 )
{
switch( V_110 ) {
case V_111 :
if ( F_74 ( V_114 , V_107 , sizeof( * V_114 ) ) )
return - V_140 ;
return 0 ;
case V_112 :
{
struct V_113 V_163 ;
if( F_74 ( & V_163 , V_107 , sizeof( V_163 ) ) )
return - V_140 ;
V_114 -> V_22 . V_164 = V_163 . V_22 . V_164 ;
V_114 -> V_22 . V_165 = V_163 . V_22 . V_165 ;
V_114 -> V_22 . V_39 = V_163 . V_22 . V_39 ;
return 0 ;
}
default:
return - V_35 ;
}
}
static int F_78 ( struct V_1 * V_2 , int V_103 ,
int V_115 , int V_110 , union V_116 V_117 )
{
struct V_18 * V_23 ;
int V_118 ;
struct V_108 V_166 ;
struct V_20 * V_21 ;
if( V_115 == V_167 ) {
if ( F_77 ( & V_166 , V_117 . V_107 , V_110 ) )
return - V_140 ;
}
V_21 = F_79 ( V_2 , & F_5 ( V_2 ) , V_103 , V_115 ,
& V_166 . V_22 , 0 ) ;
if ( F_11 ( V_21 ) )
return F_69 ( V_21 ) ;
V_23 = F_12 ( V_21 , struct V_18 , V_22 ) ;
V_118 = F_65 ( V_23 , V_115 ) ;
if ( V_118 )
goto V_146;
switch( V_115 ) {
case V_168 :
V_14 ( V_2 , V_21 ) ;
goto V_169;
case V_167 :
V_118 = F_80 ( & V_166 . V_22 , V_21 ) ;
if ( V_118 )
goto V_146;
V_23 -> V_47 = F_30 () ;
break;
default:
V_118 = - V_35 ;
}
V_146:
F_31 ( V_23 ) ;
V_169:
F_81 ( & F_5 ( V_2 ) . V_134 ) ;
return V_118 ;
}
T_5 (F_82)( int V_103 , int V_85 , int V_115 , union V_116 V_117 )
{
int V_118 = - V_35 ;
int V_110 ;
struct V_1 * V_2 ;
if ( V_103 < 0 )
return - V_35 ;
V_110 = F_83 ( & V_115 ) ;
V_2 = V_162 -> V_170 -> V_171 ;
switch( V_115 ) {
case V_119 :
case V_120 :
case V_141 :
case V_142 :
V_118 = F_64 ( V_2 , V_103 , V_115 , V_110 , V_117 ) ;
return V_118 ;
case V_153 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_150 :
case V_151 :
V_118 = F_72 ( V_2 , V_103 , V_85 , V_115 , V_110 , V_117 ) ;
return V_118 ;
case V_168 :
case V_167 :
V_118 = F_78 ( V_2 , V_103 , V_115 , V_110 , V_117 ) ;
return V_118 ;
default:
return - V_35 ;
}
}
T_6 long F_84 ( int V_103 , int V_85 , int V_115 , union V_116 V_117 )
{
return F_85 ( ( int ) V_103 , ( int ) V_85 , ( int ) V_115 , V_117 ) ;
}
static inline int F_86 ( struct V_172 * * V_173 )
{
struct V_172 * V_174 ;
V_174 = V_162 -> V_175 . V_174 ;
if ( ! V_174 ) {
V_174 = F_87 ( sizeof( * V_174 ) , V_176 ) ;
if ( V_174 == NULL )
return - V_38 ;
F_88 ( & V_174 -> V_101 ) ;
F_89 ( & V_174 -> V_177 , 1 ) ;
F_29 ( & V_174 -> V_104 ) ;
V_162 -> V_175 . V_174 = V_174 ;
}
* V_173 = V_174 ;
return 0 ;
}
static struct V_51 * F_90 ( struct V_172 * V_102 , int V_103 )
{
struct V_51 * V_52 ;
F_91 (un, &ulp->list_proc, list_proc) {
if ( V_52 -> V_103 == V_103 )
return V_52 ;
}
return NULL ;
}
static struct V_51 * F_92 ( struct V_172 * V_102 , int V_103 )
{
struct V_51 * V_52 ;
F_56 ( & V_102 -> V_101 ) ;
V_52 = F_90 ( V_102 , V_103 ) ;
if ( V_52 ) {
F_58 ( & V_52 -> V_104 ) ;
F_93 ( & V_52 -> V_104 , & V_102 -> V_104 ) ;
}
return V_52 ;
}
static struct V_51 * F_94 ( struct V_1 * V_2 , int V_103 )
{
struct V_18 * V_23 ;
struct V_172 * V_102 ;
struct V_51 * V_52 , * V_178 ;
int V_30 ;
int error ;
error = F_86 ( & V_102 ) ;
if ( error )
return F_95 ( error ) ;
F_96 () ;
F_57 ( & V_102 -> V_101 ) ;
V_52 = F_92 ( V_102 , V_103 ) ;
F_59 ( & V_102 -> V_101 ) ;
if ( F_97 ( V_52 != NULL ) )
goto V_114;
F_98 () ;
V_23 = F_13 ( V_2 , V_103 ) ;
if ( F_11 ( V_23 ) )
return F_99 ( V_23 ) ;
V_30 = V_23 -> V_46 ;
F_18 ( V_23 ) ;
V_178 = F_87 ( sizeof( struct V_51 ) + sizeof( short ) * V_30 , V_176 ) ;
if ( ! V_178 ) {
F_21 ( V_23 ) ;
return F_95 ( - V_38 ) ;
}
F_15 ( V_23 ) ;
if ( V_23 -> V_22 . V_155 ) {
F_31 ( V_23 ) ;
F_100 ( V_178 ) ;
V_52 = F_95 ( - V_106 ) ;
goto V_114;
}
F_57 ( & V_102 -> V_101 ) ;
V_52 = F_92 ( V_102 , V_103 ) ;
if ( V_52 ) {
F_100 ( V_178 ) ;
goto V_179;
}
V_178 -> V_66 = ( short * ) & V_178 [ 1 ] ;
V_178 -> V_102 = V_102 ;
V_178 -> V_103 = V_103 ;
F_56 ( & V_102 -> V_101 ) ;
F_93 ( & V_178 -> V_104 , & V_102 -> V_104 ) ;
F_56 ( & V_23 -> V_22 . V_101 ) ;
F_101 ( & V_178 -> V_45 , & V_23 -> V_45 ) ;
V_52 = V_178 ;
V_179:
F_59 ( & V_102 -> V_101 ) ;
F_96 () ;
F_31 ( V_23 ) ;
V_114:
return V_52 ;
}
static int F_102 ( struct V_74 * V_75 )
{
int error ;
error = V_75 -> V_76 ;
while ( F_103 ( error == V_77 ) ) {
F_104 () ;
error = V_75 -> V_76 ;
}
return error ;
}
int F_105 ( unsigned long V_180 , struct V_181 * V_182 )
{
struct V_172 * V_174 ;
int error ;
if ( V_180 & V_183 ) {
error = F_86 ( & V_174 ) ;
if ( error )
return error ;
F_106 ( & V_174 -> V_177 ) ;
V_182 -> V_175 . V_174 = V_174 ;
} else
V_182 -> V_175 . V_174 = NULL ;
return 0 ;
}
void F_107 ( struct V_181 * V_182 )
{
struct V_172 * V_102 ;
V_102 = V_182 -> V_175 . V_174 ;
if ( ! V_102 )
return;
V_182 -> V_175 . V_174 = NULL ;
if ( ! F_108 ( & V_102 -> V_177 ) )
return;
for (; ; ) {
struct V_18 * V_23 ;
struct V_51 * V_52 ;
struct V_72 V_100 ;
int V_103 ;
int V_34 ;
F_96 () ;
V_52 = F_109 ( V_102 -> V_104 . V_91 ,
struct V_51 , V_104 ) ;
if ( & V_52 -> V_104 == & V_102 -> V_104 )
V_103 = - 1 ;
else
V_103 = V_52 -> V_103 ;
F_98 () ;
if ( V_103 == - 1 )
break;
V_23 = F_13 ( V_182 -> V_170 -> V_171 , V_52 -> V_103 ) ;
if ( F_11 ( V_23 ) )
continue;
V_52 = F_90 ( V_102 , V_103 ) ;
if ( V_52 == NULL ) {
F_31 ( V_23 ) ;
continue;
}
F_56 ( & V_23 -> V_22 . V_101 ) ;
F_46 ( & V_52 -> V_45 ) ;
F_57 ( & V_102 -> V_101 ) ;
F_58 ( & V_52 -> V_104 ) ;
F_59 ( & V_102 -> V_101 ) ;
for ( V_34 = 0 ; V_34 < V_23 -> V_46 ; V_34 ++ ) {
struct V_37 * V_184 = & V_23 -> V_42 [ V_34 ] ;
if ( V_52 -> V_66 [ V_34 ] ) {
V_184 -> V_59 += V_52 -> V_66 [ V_34 ] ;
if ( V_184 -> V_59 < 0 )
V_184 -> V_59 = 0 ;
if ( V_184 -> V_59 > V_61 )
V_184 -> V_59 = V_61 ;
V_184 -> V_68 = F_75 ( V_162 ) ;
}
}
F_29 ( & V_100 ) ;
F_52 ( V_23 , NULL , 0 , 1 , & V_100 ) ;
F_31 ( V_23 ) ;
F_40 ( & V_100 ) ;
F_60 ( V_52 , V_105 ) ;
}
F_100 ( V_102 ) ;
}
static int V_17 ( struct V_185 * V_24 , void * V_186 )
{
struct V_187 * V_188 = F_110 ( V_24 ) ;
struct V_18 * V_23 = V_186 ;
return F_111 ( V_24 ,
L_3 ,
V_23 -> V_22 . V_29 ,
V_23 -> V_22 . V_19 ,
V_23 -> V_22 . V_39 ,
V_23 -> V_46 ,
F_112 ( V_188 , V_23 -> V_22 . V_164 ) ,
F_113 ( V_188 , V_23 -> V_22 . V_165 ) ,
F_112 ( V_188 , V_23 -> V_22 . V_189 ) ,
F_113 ( V_188 , V_23 -> V_22 . V_190 ) ,
V_23 -> V_95 ,
V_23 -> V_47 ) ;
}
