static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 . V_6 ;
}
static inline int F_2 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return - V_7 ;
if ( ! V_3 -> V_8 || ! V_3 -> V_8 -> type ) {
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , - V_7 ) ;
return - V_7 ;
}
if ( V_3 -> V_8 -> type == - 1 ) {
F_4 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , - V_10 ) ;
return - V_10 ;
}
return 0 ;
}
static void F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_12 , struct V_13 , V_12 ) ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_15 * V_4 = V_3 -> V_4 ;
T_1 V_16 = V_3 -> V_17 -> V_18 ;
if ( V_16 != - 1 )
V_4 -> V_19 -> V_20 ( V_4 , V_16 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_21 * V_22 = F_8 ( V_3 -> V_8 ) ;
struct V_15 * V_4 = V_3 -> V_4 ;
int V_23 , V_24 ;
for ( V_23 = 0 ; V_23 < V_3 -> V_8 -> V_25 ; V_23 ++ ) {
V_24 = F_9 ( sizeof( V_26 ) * 3 +
sizeof( struct V_27 ) *
F_10 ( V_22 -> V_28 ) ) ;
if ( ! F_11 ( V_22 [ V_23 ] . V_29 ) ) {
F_12 ( F_1 ( V_3 ) , L_2 ) ;
continue;
}
V_3 -> V_30 [ V_23 ] . V_12 . V_31 . V_32 =
( void V_33 * ) V_4 -> V_19 -> V_34 (
V_4 ,
F_11 ( V_22 [ V_23 ] . V_29 ) ,
V_24 ) ;
}
V_3 -> V_17 -> V_35 = 0 ;
F_13 ( F_1 ( V_3 ) , L_3 ,
V_9 , V_3 -> V_36 ) ;
}
static inline void F_14 ( struct V_2 * V_3 )
{
int V_23 ;
F_4 ( F_1 ( V_3 ) , L_4 ,
V_9 , V_3 -> V_8 -> V_37 , V_3 -> V_36 ) ;
for ( V_23 = 0 ; V_23 < V_3 -> V_8 -> V_25 ; V_23 ++ )
F_15 ( & V_3 -> V_30 [ V_23 ] . V_38 , V_23 + 1 ) ;
V_3 -> V_8 -> V_37 = 0 ;
V_3 -> V_17 -> V_39 = 0 ;
V_3 -> V_17 -> V_40 = 1 ;
for ( V_23 = 0 ; V_23 < V_3 -> V_8 -> V_25 ; V_23 ++ ) {
struct V_11 * V_12 = & V_3 -> V_30 [ V_23 ] . V_12 ;
V_3 -> V_30 [ V_23 ] . V_31 . V_41 -> V_42 = 0 ;
V_12 -> V_43 = 0 ;
V_12 -> V_44 = 0 ;
V_12 -> V_45 = 0 ;
}
for ( V_23 = 0 ; V_23 < V_3 -> V_8 -> V_25 ; V_23 ++ )
F_16 ( & V_3 -> V_30 [ V_23 ] . V_38 ) ;
}
static void F_17 ( struct V_46 * V_47 )
{
struct V_48 * V_49 , * V_50 ;
struct V_2 * V_3 ;
F_18 (pos, tmp, &vi->vdev_list) {
V_3 = F_19 ( V_49 , struct V_2 , V_51 ) ;
F_14 ( V_3 ) ;
V_3 -> V_52 = 1 ;
F_20 ( & V_3 -> V_53 ) ;
}
}
static void F_21 ( struct V_54 * V_55 )
{
struct V_2 * V_3 = F_6 ( V_55 , struct V_2 ,
V_56 ) ;
if ( V_3 -> V_17 -> V_35 )
F_7 ( V_3 ) ;
if ( V_3 -> V_17 -> V_39 )
F_14 ( V_3 ) ;
V_3 -> V_52 = 1 ;
F_20 ( & V_3 -> V_53 ) ;
}
static T_2 F_22 ( int V_57 , void * V_58 )
{
struct V_2 * V_3 = V_58 ;
struct V_15 * V_4 = V_3 -> V_4 ;
V_4 -> V_19 -> V_59 ( V_4 , V_3 -> V_60 ) ;
F_23 ( & V_3 -> V_56 ) ;
return V_61 ;
}
static int F_24 ( struct V_2 * V_3 , void * V_62 )
{
F_25 ( V_63 ) ;
int V_64 = 0 , V_65 , V_23 ;
struct V_15 * V_4 = V_3 -> V_4 ;
struct V_46 * V_47 = F_26 ( & V_4 -> V_5 ) ;
struct V_66 * V_67 = V_4 -> V_19 -> V_68 ( V_4 ) ;
T_1 V_16 = V_67 -> V_69 ;
F_27 ( & V_47 -> V_70 ) ;
for ( V_23 = 0 ; V_23 < V_3 -> V_8 -> V_25 ; V_23 ++ )
F_15 ( & V_3 -> V_30 [ V_23 ] . V_38 , V_23 + 1 ) ;
if ( V_16 == - 1 || V_3 -> V_8 -> type == - 1 ) {
V_64 = - V_71 ;
goto exit;
}
memcpy ( F_28 ( V_3 -> V_8 ) , V_62 , V_3 -> V_8 -> V_72 ) ;
V_3 -> V_17 -> V_73 = V_74 ;
V_4 -> V_19 -> V_20 ( V_4 , V_16 ) ;
for ( V_65 = 100 ; V_65 -- ; ) {
V_64 = F_29 ( V_63 , V_3 -> V_17 -> V_75 ,
F_30 ( 100 ) ) ;
if ( V_64 )
break;
}
F_4 ( F_1 ( V_3 ) ,
L_5 , V_9 , __LINE__ , V_65 ) ;
V_3 -> V_17 -> V_73 = 0 ;
V_3 -> V_17 -> V_75 = 0 ;
exit:
for ( V_23 = 0 ; V_23 < V_3 -> V_8 -> V_25 ; V_23 ++ )
F_16 ( & V_3 -> V_30 [ V_23 ] . V_38 ) ;
F_16 ( & V_47 -> V_70 ) ;
return V_64 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_76 * V_62 , T_3 * type ,
struct V_76 * * V_77 )
{
struct V_15 * V_4 = V_3 -> V_4 ;
struct V_76 * V_78 ;
struct V_21 * V_22 ;
int V_64 = 0 , V_23 ;
bool V_79 = false ;
V_22 = F_8 ( V_62 ) ;
for ( V_23 = 0 ; V_23 < V_62 -> V_25 ; V_23 ++ ) {
if ( F_10 ( V_22 [ V_23 ] . V_28 ) > V_80 ) {
V_64 = - V_7 ;
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_64 ) ;
goto exit;
}
}
for ( V_23 = sizeof( struct V_66 ) ;
V_23 < V_81 - F_32 ( V_62 ) ;
V_23 += F_32 ( V_78 ) ) {
V_78 = V_4 -> V_19 -> V_68 ( V_4 ) + V_23 ;
if ( V_78 -> type == 0 || V_78 -> type == - 1 ) {
V_79 = true ;
break;
}
}
if ( ! V_79 ) {
V_64 = - V_7 ;
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_64 ) ;
goto exit;
}
* type = V_62 -> type ;
V_62 -> type = 0 ;
memcpy ( V_78 , V_62 , F_33 ( V_62 ) ) ;
* V_77 = V_78 ;
exit:
return V_64 ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_76 * V_77 )
{
struct V_82 * V_17 ;
V_17 = ( void * ) V_77 + F_35 ( V_77 ) ;
V_17 -> V_73 = 0 ;
V_17 -> V_75 = 0 ;
V_17 -> V_39 = 0 ;
V_17 -> V_40 = 0 ;
V_17 -> V_35 = 0 ;
V_17 -> V_83 = - 1 ;
V_17 -> V_18 = - 1 ;
V_3 -> V_17 = V_17 ;
}
static int F_36 ( struct V_2 * V_3 ,
struct V_76 * V_62 )
{
struct V_46 * V_47 = V_3 -> V_47 ;
struct V_15 * V_4 = V_47 -> V_4 ;
struct V_76 * V_8 = NULL ;
struct V_21 * V_22 ;
int V_84 , V_23 , V_85 , V_64 ;
T_4 type = 0 ;
T_1 V_16 = - 1 ;
char V_86 [ 16 ] ;
struct V_66 * V_67 ;
V_26 V_28 ;
T_5 V_87 ;
V_67 = V_4 -> V_19 -> V_68 ( V_4 ) ;
F_37 ( & V_3 -> V_53 ) ;
F_38 ( & V_3 -> V_51 ) ;
V_3 -> V_4 = V_4 ;
V_64 = F_31 ( V_3 , V_62 , & type , & V_8 ) ;
if ( V_64 ) {
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_64 ) ;
return V_64 ;
}
F_34 ( V_3 , V_8 ) ;
V_3 -> V_8 = V_8 ;
V_3 -> V_36 = type ;
V_22 = F_8 ( V_8 ) ;
F_39 ( & V_3 -> V_56 , F_21 ) ;
for ( V_23 = 0 ; V_23 < V_8 -> V_25 ; V_23 ++ ) {
struct V_13 * V_30 = & V_3 -> V_30 [ V_23 ] ;
struct V_88 * V_89 = & V_3 -> V_30 [ V_23 ] . V_31 ;
V_28 = F_10 ( V_22 [ V_23 ] . V_28 ) ;
F_40 ( & V_30 -> V_38 ) ;
V_84 = F_9 ( F_41 ( V_28 , V_90 ) +
sizeof( struct V_91 ) ) ;
V_89 -> V_92 = ( void * )
F_42 ( V_93 | V_94 ,
F_43 ( V_84 ) ) ;
if ( ! V_89 -> V_92 ) {
V_64 = - V_95 ;
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_64 ) ;
goto V_96;
}
V_89 -> V_97 = V_84 ;
V_89 -> V_41 = V_89 -> V_92 + F_41 ( V_28 , V_90 ) ;
V_89 -> V_41 -> V_98 = F_44 ( V_99 + V_3 -> V_36 + V_23 ) ;
V_87 = F_45 ( & V_4 -> V_5 , V_89 -> V_92 , V_84 ,
V_100 ) ;
if ( F_46 ( & V_4 -> V_5 , V_87 ) ) {
F_47 ( ( unsigned long ) V_89 -> V_92 , F_43 ( V_84 ) ) ;
V_64 = - V_95 ;
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_64 ) ;
goto V_96;
}
V_22 [ V_23 ] . V_101 = F_48 ( V_87 ) ;
F_49 ( & V_89 -> V_89 , V_28 , V_89 -> V_92 , V_90 ) ;
V_64 = F_50 ( & V_30 -> V_12 ,
* ( V_102 * ) F_51 ( V_3 -> V_8 ) ,
V_28 , false , V_89 -> V_89 . V_103 , V_89 -> V_89 . V_104 ,
V_89 -> V_89 . V_32 ) ;
if ( V_64 ) {
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_64 ) ;
goto V_96;
}
F_52 ( & V_30 -> V_105 , NULL , 0 ) ;
F_52 ( & V_30 -> V_106 , NULL , 0 ) ;
V_30 -> V_107 = V_108 ;
V_30 -> V_3 = V_3 ;
V_30 -> V_12 . V_109 = F_5 ;
F_4 ( & V_4 -> V_5 ,
L_6 ,
V_9 , __LINE__ , V_23 , V_89 -> V_92 , V_89 -> V_41 , V_84 ) ;
V_30 -> V_110 = ( void * ) F_42 ( V_93 ,
F_43 ( V_111 ) ) ;
V_30 -> V_112 = F_45 ( & V_4 -> V_5 ,
V_30 -> V_110 , V_111 ,
V_100 ) ;
}
snprintf ( V_86 , sizeof( V_86 ) , L_7 , V_4 -> V_113 ,
V_3 -> V_36 ) ;
V_3 -> V_60 = V_4 -> V_19 -> V_114 ( V_4 ) ;
V_3 -> V_115 = V_4 -> V_19 -> V_116 ( V_4 ,
F_22 , V_86 , V_3 ,
V_3 -> V_60 ) ;
if ( F_53 ( V_3 -> V_115 ) ) {
V_64 = F_54 ( V_3 -> V_115 ) ;
F_4 ( & V_4 -> V_5 , L_8 ) ;
goto V_96;
}
V_3 -> V_17 -> V_83 = V_3 -> V_60 ;
F_55 () ;
V_8 -> type = type ;
V_62 -> type = type ;
if ( V_67 ) {
V_16 = V_67 -> V_69 ;
if ( V_16 != - 1 )
V_4 -> V_19 -> V_20 ( V_4 , V_16 ) ;
}
F_4 ( & V_4 -> V_5 , L_9 , V_8 -> type , V_16 ) ;
return 0 ;
V_96:
V_22 = F_8 ( V_8 ) ;
for ( V_85 = 0 ; V_85 < V_23 ; V_85 ++ ) {
struct V_13 * V_30 = & V_3 -> V_30 [ V_85 ] ;
F_56 ( & V_4 -> V_5 , F_11 ( V_22 [ V_85 ] . V_101 ) ,
V_30 -> V_31 . V_97 , V_100 ) ;
F_47 ( ( unsigned long ) V_30 -> V_31 . V_92 ,
F_43 ( V_30 -> V_31 . V_97 ) ) ;
}
return V_64 ;
}
static void F_57 ( struct V_46 * V_117 , struct V_82 * V_78 ,
struct V_15 * V_4 )
{
struct V_66 * V_67 = V_4 -> V_19 -> V_68 ( V_4 ) ;
T_1 V_16 ;
int V_64 , V_65 ;
F_25 ( V_63 ) ;
V_78 -> V_73 = V_118 ;
V_16 = V_67 -> V_69 ;
if ( V_16 != - 1 )
V_4 -> V_19 -> V_20 ( V_4 , V_16 ) ;
else
goto V_119;
for ( V_65 = 15 ; V_65 -- ; ) {
V_64 = F_29 ( V_63 , V_78 -> V_75 ,
F_30 ( 1000 ) ) ;
if ( V_64 )
break;
}
V_119:
V_78 -> V_73 = 0 ;
V_78 -> V_75 = 0 ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_46 * V_47 = V_3 -> V_47 ;
struct V_15 * V_4 = V_3 -> V_4 ;
int V_23 ;
struct V_21 * V_22 ;
struct V_66 * V_67 = V_4 -> V_19 -> V_68 ( V_4 ) ;
if ( ! V_67 )
goto V_120;
F_57 ( V_47 , V_3 -> V_17 , V_4 ) ;
V_120:
V_4 -> V_19 -> V_121 ( V_4 , V_3 -> V_115 , V_3 ) ;
F_59 ( & V_3 -> V_56 ) ;
V_22 = F_8 ( V_3 -> V_8 ) ;
for ( V_23 = 0 ; V_23 < V_3 -> V_8 -> V_25 ; V_23 ++ ) {
struct V_13 * V_30 = & V_3 -> V_30 [ V_23 ] ;
F_56 ( & V_4 -> V_5 ,
V_30 -> V_112 , V_111 ,
V_100 ) ;
F_47 ( ( unsigned long ) V_30 -> V_110 ,
F_43 ( V_111 ) ) ;
F_60 ( & V_30 -> V_105 ) ;
F_60 ( & V_30 -> V_106 ) ;
F_56 ( & V_4 -> V_5 , F_11 ( V_22 [ V_23 ] . V_101 ) ,
V_30 -> V_31 . V_97 , V_100 ) ;
F_47 ( ( unsigned long ) V_30 -> V_31 . V_92 ,
F_43 ( V_30 -> V_31 . V_97 ) ) ;
}
F_55 () ;
V_3 -> V_8 -> type = - 1 ;
}
static int F_61 ( struct V_2 * V_3 , T_5 V_122 , T_5 V_123 ,
T_6 V_97 )
{
int V_96 = 0 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
struct V_46 * V_47 = F_26 ( & V_3 -> V_4 -> V_5 ) ;
struct V_128 * V_129 = V_47 -> V_130 ;
if ( ! V_129 ) {
V_96 = - V_131 ;
goto error;
}
V_125 = V_129 -> V_1 ;
V_127 = V_125 -> V_132 ( V_129 , V_122 , V_123 , V_97 ,
V_133 ) ;
if ( ! V_127 ) {
V_96 = - V_95 ;
goto error;
} else {
T_7 V_134 ;
V_134 = V_127 -> V_135 ( V_127 ) ;
if ( F_62 ( V_134 ) ) {
V_96 = - V_95 ;
goto error;
}
F_63 ( V_129 ) ;
V_96 = F_64 ( V_129 , V_134 ) ;
}
error:
if ( V_96 )
F_3 ( & V_47 -> V_4 -> V_5 , L_1 ,
V_9 , __LINE__ , V_96 ) ;
return V_96 ;
}
static int F_65 ( struct V_2 * V_3 , void T_8 * V_136 ,
T_6 V_97 , T_9 V_137 , T_6 V_138 ,
int V_139 )
{
struct V_15 * V_4 = V_3 -> V_4 ;
void T_10 * V_140 = V_4 -> V_19 -> V_34 ( V_4 , V_137 , V_97 ) ;
struct V_13 * V_30 = & V_3 -> V_30 [ V_139 ] ;
struct V_46 * V_47 = F_26 ( & V_4 -> V_5 ) ;
T_6 V_141 = 1 << V_47 -> V_130 -> V_1 -> V_142 ;
bool V_143 = F_66 ( V_47 -> V_130 -> V_1 , 1 , 1 , 1 ) ;
T_6 V_144 , V_145 ;
int V_96 ;
if ( ! V_146 ) {
if ( F_67 ( V_136 , ( void V_33 * ) V_140 , V_97 ) ) {
V_96 = - V_147 ;
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_96 ) ;
goto V_96;
}
V_3 -> V_148 += V_97 ;
V_96 = 0 ;
goto V_96;
}
V_144 = V_137 - F_68 ( V_137 , V_141 ) ;
V_137 -= V_144 ;
V_97 += V_144 ;
if ( V_143 )
V_137 += V_4 -> V_149 -> V_150 ;
while ( V_97 ) {
V_145 = F_69 ( T_6 , V_97 , V_111 ) ;
V_96 = F_61 ( V_3 , V_30 -> V_112 , V_137 ,
F_70 ( V_145 , V_141 ) ) ;
if ( V_96 ) {
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_96 ) ;
goto V_96;
}
if ( F_67 ( V_136 , V_30 -> V_110 + V_144 ,
V_145 - V_144 ) ) {
V_96 = - V_147 ;
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_96 ) ;
goto V_96;
}
V_137 += V_145 ;
V_136 += V_145 ;
V_140 += V_145 ;
V_3 -> V_151 += V_145 ;
V_3 -> V_148 += V_145 ;
V_97 -= V_145 ;
V_144 = 0 ;
}
V_96 = 0 ;
V_96:
V_4 -> V_19 -> V_152 ( V_4 , V_140 ) ;
F_4 ( F_1 ( V_3 ) ,
L_10 ,
V_9 , V_136 , V_140 , V_97 , V_139 ) ;
return V_96 ;
}
static int F_71 ( struct V_2 * V_3 , void T_8 * V_136 ,
T_6 V_97 , T_9 V_137 , T_6 V_138 ,
int V_139 )
{
struct V_15 * V_4 = V_3 -> V_4 ;
void T_10 * V_140 = V_4 -> V_19 -> V_34 ( V_4 , V_137 , V_97 ) ;
struct V_13 * V_30 = & V_3 -> V_30 [ V_139 ] ;
struct V_46 * V_47 = F_26 ( & V_3 -> V_4 -> V_5 ) ;
T_6 V_141 = 1 << V_47 -> V_130 -> V_1 -> V_142 ;
bool V_143 = F_66 ( V_47 -> V_130 -> V_1 , 1 , 1 , 1 ) ;
T_6 V_145 ;
bool V_153 = V_146 ;
int V_96 = 0 ;
if ( V_137 & ( V_141 - 1 ) ) {
V_3 -> V_154 += V_97 ;
V_153 = false ;
} else if ( F_70 ( V_97 , V_141 ) > V_138 ) {
V_3 -> V_155 += V_97 ;
V_153 = false ;
}
if ( ! V_153 )
goto memcpy;
if ( V_143 )
V_137 += V_4 -> V_149 -> V_150 ;
while ( V_97 ) {
V_145 = F_69 ( T_6 , V_97 , V_111 ) ;
if ( F_72 ( V_30 -> V_110 , V_136 , V_145 ) ) {
V_96 = - V_147 ;
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_96 ) ;
goto V_96;
}
V_96 = F_61 ( V_3 , V_137 , V_30 -> V_112 ,
F_70 ( V_145 , V_141 ) ) ;
if ( V_96 ) {
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_96 ) ;
goto V_96;
}
V_137 += V_145 ;
V_136 += V_145 ;
V_140 += V_145 ;
V_3 -> V_156 += V_145 ;
V_3 -> V_157 += V_145 ;
V_97 -= V_145 ;
}
memcpy:
if ( F_72 ( ( void V_33 * ) V_140 , V_136 , V_97 ) ) {
V_96 = - V_147 ;
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_96 ) ;
goto V_96;
}
V_3 -> V_157 += V_97 ;
V_96 = 0 ;
V_96:
V_4 -> V_19 -> V_152 ( V_4 , V_140 ) ;
F_4 ( F_1 ( V_3 ) ,
L_10 ,
V_9 , V_136 , V_140 , V_97 , V_139 ) ;
return V_96 ;
}
static inline V_102 F_73 ( struct V_158 * V_159 )
{
int V_23 ;
V_102 V_160 = V_159 -> V_161 ;
for ( V_23 = 0 ; V_23 < V_159 -> V_23 ; V_23 ++ )
V_160 += V_159 -> V_159 [ V_23 ] . V_162 ;
return V_160 ;
}
static int F_74 ( struct V_2 * V_3 , struct V_158 * V_159 ,
void T_8 * V_136 , T_6 V_97 , bool V_163 , int V_139 ,
T_6 * V_164 )
{
int V_64 = 0 ;
T_6 V_145 , V_165 = 0 ;
while ( V_97 && V_159 -> V_23 < V_159 -> V_32 ) {
struct V_166 * V_167 = & V_159 -> V_159 [ V_159 -> V_23 ] ;
V_145 = F_75 ( V_167 -> V_162 , V_97 ) ;
if ( V_163 )
V_64 = F_65 ( V_3 , V_136 , V_145 ,
( T_9 ) V_167 -> V_168 ,
V_167 -> V_162 ,
V_139 ) ;
else
V_64 = F_71 ( V_3 , V_136 , V_145 ,
( T_9 ) V_167 -> V_168 ,
V_167 -> V_162 ,
V_139 ) ;
if ( V_64 ) {
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_64 ) ;
break;
}
V_97 -= V_145 ;
V_136 += V_145 ;
V_165 += V_145 ;
V_159 -> V_161 += V_145 ;
V_167 -> V_162 -= V_145 ;
V_167 -> V_168 += V_145 ;
if ( ! V_167 -> V_162 ) {
V_167 -> V_162 = V_159 -> V_161 ;
V_167 -> V_168 -= V_159 -> V_161 ;
V_159 -> V_161 = 0 ;
V_159 -> V_23 ++ ;
}
}
* V_164 = V_165 ;
return V_64 ;
}
static int F_76 ( struct V_2 * V_3 , struct V_169 * V_170 )
{
int V_64 = 0 ;
V_102 V_171 = V_170 -> V_171 ;
struct V_172 V_159 ;
struct V_172 T_8 * V_173 = V_170 -> V_159 ;
void T_8 * V_136 = NULL ;
struct V_13 * V_30 = & V_3 -> V_30 [ V_170 -> V_139 ] ;
struct V_158 * V_105 = & V_30 -> V_105 ;
struct V_158 * V_106 = & V_30 -> V_106 ;
struct V_11 * V_12 = & V_30 -> V_12 ;
V_26 * V_107 = & V_30 -> V_107 ;
struct V_88 * V_89 = & V_30 -> V_31 ;
T_6 V_97 = 0 , V_164 ;
V_170 -> V_164 = 0 ;
if ( V_105 -> V_23 == V_105 -> V_32 && V_106 -> V_23 == V_106 -> V_32 ) {
V_64 = F_77 ( V_12 , V_105 , V_106 ,
V_107 , V_93 ) ;
if ( V_64 <= 0 )
return V_64 ;
}
while ( V_171 ) {
if ( ! V_97 ) {
V_64 = F_72 ( & V_159 , V_173 , sizeof( * V_173 ) ) ;
if ( V_64 ) {
V_64 = - V_7 ;
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_64 ) ;
break;
}
V_97 = V_159 . V_162 ;
V_136 = V_159 . V_168 ;
}
V_64 = F_74 ( V_3 , V_105 , V_136 , V_97 ,
V_174 , V_170 -> V_139 , & V_164 ) ;
if ( V_64 ) {
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_64 ) ;
break;
}
V_97 -= V_164 ;
V_136 += V_164 ;
V_170 -> V_164 += V_164 ;
V_64 = F_74 ( V_3 , V_106 , V_136 , V_97 ,
! V_174 , V_170 -> V_139 , & V_164 ) ;
if ( V_64 ) {
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_64 ) ;
break;
}
V_97 -= V_164 ;
V_136 += V_164 ;
V_170 -> V_164 += V_164 ;
if ( ! V_97 ) {
V_171 -- ;
V_173 ++ ;
}
if ( V_105 -> V_23 == V_105 -> V_32 && V_106 -> V_23 == V_106 -> V_32 )
break;
}
if ( * V_107 != V_108 && V_170 -> V_164 && V_170 -> V_175 ) {
V_102 V_160 = 0 ;
V_160 += F_73 ( V_105 ) ;
V_160 += F_73 ( V_106 ) ;
F_78 ( V_12 , * V_107 , V_160 ) ;
* V_107 = V_108 ;
if ( F_79 ( V_12 ) > 0 )
F_80 ( V_12 ) ;
F_60 ( V_105 ) ;
F_60 ( V_106 ) ;
V_89 -> V_41 -> V_42 = V_12 -> V_44 ;
}
return V_64 ;
}
static inline int F_81 ( struct V_2 * V_3 ,
struct V_169 * V_170 )
{
if ( ! V_3 || V_170 -> V_139 >= V_3 -> V_8 -> V_25 )
return - V_7 ;
return 0 ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_169 * V_170 )
{
int V_96 ;
struct V_13 * V_30 ;
V_96 = F_81 ( V_3 , V_170 ) ;
if ( V_96 )
return V_96 ;
V_30 = & V_3 -> V_30 [ V_170 -> V_139 ] ;
F_27 ( & V_30 -> V_38 ) ;
if ( ! F_83 ( V_3 ) ) {
V_96 = - V_10 ;
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_96 ) ;
goto V_96;
}
V_96 = F_76 ( V_3 , V_170 ) ;
if ( V_96 ) {
F_3 ( F_1 ( V_3 ) , L_1 ,
V_9 , __LINE__ , V_96 ) ;
}
V_96:
F_16 ( & V_30 -> V_38 ) ;
return V_96 ;
}
static int F_84 ( struct V_176 * V_176 , struct V_177 * V_178 )
{
struct V_2 * V_3 ;
struct V_46 * V_47 = F_6 ( V_178 -> V_179 ,
struct V_46 , V_180 ) ;
V_3 = F_85 ( sizeof( * V_3 ) , V_93 ) ;
if ( ! V_3 )
return - V_95 ;
V_3 -> V_47 = V_47 ;
F_40 ( & V_3 -> V_181 ) ;
V_178 -> V_179 = V_3 ;
F_86 ( & V_3 -> V_182 ) ;
F_87 ( & V_3 -> V_182 ) ;
return 0 ;
}
static int F_88 ( struct V_176 * V_176 , struct V_177 * V_178 )
{
struct V_2 * V_3 = V_178 -> V_179 , * V_183 ;
struct V_46 * V_47 = V_3 -> V_47 ;
struct V_48 * V_49 , * V_50 ;
bool V_184 = false ;
F_27 ( & V_3 -> V_181 ) ;
if ( V_3 -> V_185 )
goto V_186;
F_27 ( & V_47 -> V_70 ) ;
F_18 (pos, tmp, &vi->vdev_list) {
V_183 = F_19 ( V_49 , struct V_2 , V_51 ) ;
if ( V_3 == V_183 ) {
F_58 ( V_3 ) ;
F_89 ( V_49 ) ;
V_184 = true ;
break;
}
}
F_16 ( & V_47 -> V_70 ) ;
V_186:
F_16 ( & V_3 -> V_181 ) ;
if ( ! V_184 )
F_90 ( & V_3 -> V_182 ) ;
V_178 -> V_179 = NULL ;
F_91 ( V_3 ) ;
return 0 ;
}
static long F_92 ( struct V_177 * V_178 , unsigned int V_187 , unsigned long V_188 )
{
struct V_2 * V_3 = V_178 -> V_179 ;
struct V_46 * V_47 = V_3 -> V_47 ;
void T_8 * V_62 = ( void T_8 * ) V_188 ;
int V_64 ;
switch ( V_187 ) {
case V_189 :
{
struct V_76 V_8 , * V_190 ;
if ( F_72 ( & V_8 , V_62 , sizeof( V_8 ) ) )
return - V_147 ;
if ( F_35 ( & V_8 ) > V_191 ||
V_8 . V_25 > V_192 )
return - V_7 ;
V_190 = F_85 ( F_33 ( & V_8 ) , V_93 ) ;
if ( ! V_190 )
return - V_95 ;
if ( F_72 ( V_190 , V_62 , F_33 ( & V_8 ) ) ) {
V_64 = - V_147 ;
goto V_193;
}
if ( memcmp ( & V_8 , V_190 , sizeof( V_8 ) ) ) {
V_64 = - V_7 ;
goto V_193;
}
F_27 ( & V_3 -> V_181 ) ;
F_27 ( & V_47 -> V_70 ) ;
V_64 = F_36 ( V_3 , V_190 ) ;
if ( V_64 )
goto V_194;
F_93 ( & V_3 -> V_51 , & V_47 -> V_195 ) ;
V_194:
F_16 ( & V_47 -> V_70 ) ;
F_16 ( & V_3 -> V_181 ) ;
V_193:
F_91 ( V_190 ) ;
return V_64 ;
}
case V_196 :
{
struct V_169 V_170 ;
F_27 ( & V_3 -> V_181 ) ;
V_64 = F_2 ( V_3 ) ;
if ( V_64 )
goto V_197;
if ( F_72 ( & V_170 , V_62 , sizeof( V_170 ) ) ) {
V_64 = - V_147 ;
goto V_197;
}
V_64 = F_82 ( V_3 , & V_170 ) ;
if ( V_64 < 0 )
goto V_197;
if ( F_67 (
& ( (struct V_169 T_8 * ) V_62 ) -> V_164 ,
& V_170 . V_164 , sizeof( V_170 . V_164 ) ) )
V_64 = - V_147 ;
V_197:
F_16 ( & V_3 -> V_181 ) ;
return V_64 ;
}
case V_198 :
{
void * V_110 ;
F_27 ( & V_3 -> V_181 ) ;
V_64 = F_2 ( V_3 ) ;
if ( V_64 )
goto V_199;
V_110 = F_85 ( V_3 -> V_8 -> V_72 , V_93 ) ;
if ( ! V_110 ) {
V_64 = - V_95 ;
goto V_199;
}
if ( F_72 ( V_110 , V_62 , V_3 -> V_8 -> V_72 ) ) {
V_64 = - V_147 ;
goto V_119;
}
V_64 = F_24 ( V_3 , V_110 ) ;
V_119:
F_91 ( V_110 ) ;
V_199:
F_16 ( & V_3 -> V_181 ) ;
return V_64 ;
}
default:
return - V_200 ;
} ;
return 0 ;
}
static unsigned int F_94 ( struct V_177 * V_178 , T_11 * V_201 )
{
struct V_2 * V_3 = V_178 -> V_179 ;
int V_202 = 0 ;
F_27 ( & V_3 -> V_181 ) ;
if ( F_2 ( V_3 ) ) {
V_202 = V_203 ;
goto V_119;
}
F_95 ( V_178 , & V_3 -> V_53 , V_201 ) ;
if ( F_2 ( V_3 ) ) {
V_202 = V_203 ;
} else if ( V_3 -> V_52 ) {
V_3 -> V_52 = 0 ;
V_202 = V_204 | V_205 ;
}
V_119:
F_16 ( & V_3 -> V_181 ) ;
return V_202 ;
}
static inline int
F_96 ( struct V_2 * V_3 , unsigned long V_206 ,
unsigned long * V_207 , unsigned long * V_150 )
{
struct V_15 * V_4 = V_3 -> V_4 ;
unsigned long V_208 = V_81 ;
int V_23 ;
if ( ! V_206 ) {
* V_150 = F_97 ( V_4 -> V_19 -> V_68 ( V_4 ) ) ;
* V_207 = V_81 ;
return 0 ;
}
for ( V_23 = 0 ; V_23 < V_3 -> V_8 -> V_25 ; V_23 ++ ) {
struct V_13 * V_30 = & V_3 -> V_30 [ V_23 ] ;
if ( V_206 == V_208 ) {
* V_150 = F_97 ( V_30 -> V_31 . V_92 ) ;
* V_207 = V_30 -> V_31 . V_97 ;
return 0 ;
}
V_208 += V_30 -> V_31 . V_97 ;
}
return - 1 ;
}
static int F_98 ( struct V_177 * V_178 , struct V_209 * V_210 )
{
struct V_2 * V_3 = V_178 -> V_179 ;
unsigned long V_206 = V_210 -> V_211 << V_212 ;
unsigned long V_150 , V_207 = V_210 -> V_213 - V_210 -> V_214 , V_215 = V_207 ;
int V_23 , V_96 ;
V_96 = F_2 ( V_3 ) ;
if ( V_96 )
goto V_64;
if ( V_210 -> V_216 & V_217 ) {
V_96 = - V_218 ;
goto V_64;
}
while ( V_215 ) {
V_23 = F_96 ( V_3 , V_206 , & V_207 , & V_150 ) ;
if ( V_23 < 0 ) {
V_96 = - V_7 ;
goto V_64;
}
V_96 = F_99 ( V_210 , V_210 -> V_214 + V_206 ,
V_150 >> V_212 , V_207 ,
V_210 -> V_219 ) ;
if ( V_96 )
goto V_64;
V_215 -= V_207 ;
V_206 += V_207 ;
}
V_64:
return V_96 ;
}
int F_100 ( struct V_46 * V_47 )
{
int V_220 ;
struct V_221 * V_222 ;
struct V_15 * V_4 = V_47 -> V_4 ;
F_38 ( & V_47 -> V_195 ) ;
V_47 -> V_130 = V_4 -> V_130 ;
V_222 = & V_47 -> V_180 ;
V_222 -> V_223 = V_224 ;
snprintf ( V_47 -> V_225 , sizeof( V_47 -> V_225 ) , L_11 , V_4 -> V_113 ) ;
V_222 -> V_225 = V_47 -> V_225 ;
V_222 -> V_226 = & V_227 ;
V_222 -> V_6 = & V_4 -> V_5 ;
V_220 = F_101 ( V_222 ) ;
if ( V_220 )
F_3 ( & V_4 -> V_5 , L_12 , V_9 , V_220 ) ;
return V_220 ;
}
void F_102 ( struct V_46 * V_47 )
{
struct V_48 * V_49 , * V_50 ;
struct V_2 * V_3 ;
F_27 ( & V_47 -> V_70 ) ;
F_17 ( V_47 ) ;
F_18 (pos, tmp, &vi->vdev_list) {
V_3 = F_19 ( V_49 , struct V_2 , V_51 ) ;
F_89 ( V_49 ) ;
F_103 ( & V_3 -> V_182 ) ;
F_16 ( & V_47 -> V_70 ) ;
F_27 ( & V_3 -> V_181 ) ;
F_58 ( V_3 ) ;
V_3 -> V_185 = true ;
F_16 ( & V_3 -> V_181 ) ;
F_87 ( & V_3 -> V_182 ) ;
F_27 ( & V_47 -> V_70 ) ;
}
F_16 ( & V_47 -> V_70 ) ;
F_104 ( & V_47 -> V_180 ) ;
}
