static void T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( & V_2 -> V_4 , & V_5 ) ;
else
F_3 ( & V_2 -> V_4 , & V_5 ) ;
}
static int T_1 F_4 ( struct V_6 * V_7 ,
struct V_8 * * V_9 , T_2 V_10 )
{
struct V_11 * V_12 ;
struct V_8 * V_13 = NULL ;
struct V_14 * V_15 ;
int V_16 ;
V_12 = F_5 ( V_10 , V_7 -> V_12 ) ;
V_15 = (struct V_14 * ) ( V_7 + 1 ) ;
V_16 = ( V_7 -> V_17 - sizeof( struct V_6 ) )
/ sizeof( struct V_14 ) ;
while ( V_16 ) {
if ( V_13 )
F_6 ( V_13 ) ;
if ( ! V_12 ) {
F_7 ( L_1 , V_7 -> V_12 ) ;
break;
}
V_13 = F_8 ( V_12 , F_9 ( V_15 -> V_9 , V_15 -> V_18 ) ) ;
if ( ! V_13 ) {
break;
}
V_15 ++ ;
V_16 -- ;
V_12 = V_13 -> V_19 ;
}
if ( ! V_13 ) {
F_7 ( L_2 ,
V_10 , V_7 -> V_12 , V_15 -> V_9 , V_15 -> V_18 ) ;
* V_9 = NULL ;
return 0 ;
}
if ( ( V_7 -> V_20 == V_21 && \
V_13 -> V_19 ) || ( V_7 -> V_20 == \
V_22 && ! V_13 -> V_19 ) ) {
F_6 ( V_13 ) ;
F_7 ( L_3 ,
F_10 ( V_13 ) ) ;
return - V_23 ;
}
* V_9 = V_13 ;
return 0 ;
}
int T_1 F_11 ( void * V_24 , void * V_25 , int * V_26 ,
struct V_8 * * * V_27 , T_2 V_10 )
{
struct V_6 * V_7 ;
void * V_28 = V_24 ;
int V_29 ;
int V_30 ;
* V_26 = 0 ;
while ( V_24 < V_25 ) {
V_7 = V_24 ;
if ( V_7 -> V_20 == V_21 ||
V_7 -> V_20 == V_22 )
( * V_26 ) ++ ;
else if ( V_7 -> V_20 != V_31 &&
V_7 -> V_20 != V_32 ) {
F_7 ( L_4 ) ;
}
V_24 += V_7 -> V_17 ;
}
if ( * V_26 == 0 )
return 0 ;
* V_27 = F_12 ( * V_26 , sizeof( struct V_8 * ) , V_33 ) ;
if ( ! * V_27 )
return - V_34 ;
V_24 = V_28 ;
V_29 = 0 ;
while ( V_24 < V_25 ) {
V_7 = V_24 ;
if ( V_7 -> V_20 == V_21 ||
V_7 -> V_20 == V_22 ) {
V_30 = F_4 ( V_7 ,
& ( * V_27 ) [ V_29 ] , V_10 ) ;
if ( V_30 ) {
F_13 ( * V_27 ) ;
return V_30 ;
}
V_29 ++ ;
}
V_24 += V_7 -> V_17 ;
}
return 0 ;
}
static int T_1
F_14 ( struct V_35 * V_36 )
{
struct V_37 * V_2 ;
struct V_1 * V_38 ;
int V_30 = 0 ;
V_2 = (struct V_37 * ) V_36 ;
V_38 = F_15 ( sizeof( * V_38 ) , V_33 ) ;
if ( ! V_38 )
return - V_34 ;
V_38 -> V_39 = V_36 ;
V_38 -> V_40 = V_2 -> V_41 ;
V_38 -> V_10 = V_2 -> V_10 ;
V_38 -> V_3 = V_2 -> V_42 & 0x1 ;
V_30 = F_16 ( V_38 ) ;
if ( V_30 ) {
F_13 ( V_38 ) ;
return V_30 ;
}
F_1 ( V_38 ) ;
return 0 ;
}
static int T_1 F_17 ( struct V_1 * V_38 )
{
struct V_37 * V_2 ;
int V_30 = 0 ;
V_2 = (struct V_37 * ) V_38 -> V_39 ;
if ( V_38 -> V_3 )
return 0 ;
V_30 = F_11 ( ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_36 . V_17 ,
& V_38 -> V_43 , & V_38 -> V_27 ,
V_2 -> V_10 ) ;
if ( V_30 ) {
F_18 ( & V_38 -> V_4 ) ;
F_13 ( V_38 ) ;
}
return V_30 ;
}
static int T_1
F_19 ( struct V_35 * V_36 )
{
struct V_44 * V_45 ;
struct V_1 * V_2 ;
V_45 = (struct V_44 * ) V_36 ;
F_20 (drhd) {
if ( V_2 -> V_40 == V_45 -> V_46 ) {
int V_47 = F_21 ( V_45 -> V_48 ) ;
if ( ! F_22 ( V_47 ) )
V_47 = - 1 ;
V_2 -> V_49 -> V_47 = V_47 ;
return 0 ;
}
}
F_23 (
1 , V_50 ,
L_5
L_6 ,
V_2 -> V_40 ,
F_24 ( V_51 ) ,
F_24 ( V_52 ) ,
F_24 ( V_53 ) ) ;
return 0 ;
}
static void T_1
F_25 ( struct V_35 * V_36 )
{
struct V_37 * V_2 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_44 * V_45 ;
switch ( V_36 -> type ) {
case V_58 :
V_2 = F_26 ( V_36 , struct V_37 ,
V_36 ) ;
F_27 ( L_7 ,
( unsigned long long ) V_2 -> V_41 , V_2 -> V_42 ) ;
break;
case V_59 :
V_55 = F_26 ( V_36 , struct V_54 ,
V_36 ) ;
F_27 ( L_8 ,
( unsigned long long ) V_55 -> V_46 ,
( unsigned long long ) V_55 -> V_60 ) ;
break;
case V_61 :
V_57 = F_26 ( V_36 , struct V_56 , V_36 ) ;
F_27 ( L_9 , V_57 -> V_42 ) ;
break;
case V_62 :
V_45 = F_26 ( V_36 , struct V_44 , V_36 ) ;
F_27 ( L_10 ,
( unsigned long long ) V_45 -> V_46 ,
V_45 -> V_48 ) ;
break;
}
}
static int T_1 F_28 ( void )
{
T_3 V_63 = V_64 ;
V_63 = F_29 ( V_65 , 0 ,
(struct V_66 * * ) & V_67 ,
& V_68 ) ;
if ( F_30 ( V_63 ) && ! V_67 ) {
F_7 ( L_11 ) ;
V_63 = V_69 ;
}
return ( F_30 ( V_63 ) ? 1 : 0 ) ;
}
static int T_1
F_31 ( void )
{
struct V_70 * V_71 ;
struct V_35 * V_72 ;
int V_30 = 0 ;
int V_73 = 0 ;
F_28 () ;
V_67 = F_32 ( V_67 ) ;
V_71 = (struct V_70 * ) V_67 ;
if ( ! V_71 )
return - V_74 ;
if ( V_71 -> V_75 < V_76 - 1 ) {
F_7 ( L_12 ) ;
return - V_23 ;
}
F_27 ( L_13 , V_71 -> V_75 + 1 ) ;
V_72 = (struct V_35 * ) ( V_71 + 1 ) ;
while ( ( ( unsigned long ) V_72 ) <
( ( ( unsigned long ) V_71 ) + V_67 -> V_17 ) ) {
if ( V_72 -> V_17 == 0 ) {
F_7 ( L_14 ) ;
V_30 = - V_23 ;
break;
}
F_25 ( V_72 ) ;
switch ( V_72 -> type ) {
case V_58 :
V_73 ++ ;
V_30 = F_14 ( V_72 ) ;
break;
case V_59 :
V_30 = F_33 ( V_72 ) ;
break;
case V_61 :
V_30 = F_34 ( V_72 ) ;
break;
case V_62 :
#ifdef F_35
V_30 = F_19 ( V_72 ) ;
#endif
break;
default:
F_7 ( L_15 ,
V_72 -> type ) ;
V_30 = 0 ;
break;
}
if ( V_30 )
break;
V_72 = ( ( void * ) V_72 + V_72 -> V_17 ) ;
}
if ( V_73 == 0 )
F_7 ( V_77 L_16 ) ;
return V_30 ;
}
static int F_36 ( struct V_8 * V_27 [] , int V_26 ,
struct V_8 * V_9 )
{
int V_29 ;
while ( V_9 ) {
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ )
if ( V_9 == V_27 [ V_29 ] )
return 1 ;
V_9 = V_9 -> V_12 -> V_78 ;
}
return 0 ;
}
struct V_1 *
F_37 ( struct V_8 * V_9 )
{
struct V_1 * V_38 = NULL ;
struct V_37 * V_2 ;
V_9 = F_38 ( V_9 ) ;
F_39 (dmaru, &dmar_drhd_units, list) {
V_2 = F_26 ( V_38 -> V_39 ,
struct V_37 ,
V_36 ) ;
if ( V_38 -> V_3 &&
V_2 -> V_10 == F_40 ( V_9 -> V_12 ) )
return V_38 ;
if ( F_36 ( V_38 -> V_27 ,
V_38 -> V_43 , V_9 ) )
return V_38 ;
}
return NULL ;
}
int T_1 F_41 ( void )
{
static int V_79 ;
struct V_1 * V_2 , * V_80 ;
int V_30 = - V_74 ;
if ( V_79 )
return V_79 ;
if ( F_42 ( & V_5 ) )
goto V_81;
F_43 (drhd, drhd_n, &dmar_drhd_units, list) {
V_30 = F_17 ( V_2 ) ;
if ( V_30 )
goto V_81;
}
V_30 = F_44 () ;
if ( V_30 )
goto V_81;
V_79 = 1 ;
return 0 ;
V_81:
V_79 = V_30 ;
return V_30 ;
}
int T_1 F_45 ( void )
{
static int V_82 ;
int V_30 ;
if ( V_82 )
return 0 ;
V_82 = 1 ;
V_30 = F_31 () ;
if ( V_30 ) {
if ( V_30 != - V_74 )
F_27 ( L_17 ) ;
return V_30 ;
}
if ( F_42 ( & V_5 ) ) {
F_27 ( L_18 ) ;
return - V_74 ;
}
return 0 ;
}
static void F_46 ( T_4 V_83 , const char * V_84 )
{
F_47 (
1 , V_50 ,
L_19
L_6 ,
V_83 , V_84 ,
F_24 ( V_51 ) ,
F_24 ( V_52 ) ,
F_24 ( V_53 ) ) ;
}
int T_1 F_48 ( void )
{
struct V_70 * V_71 ;
struct V_35 * V_72 ;
struct V_37 * V_2 ;
V_71 = (struct V_70 * ) V_67 ;
V_72 = (struct V_35 * ) ( V_71 + 1 ) ;
while ( ( ( unsigned long ) V_72 ) <
( ( ( unsigned long ) V_71 ) + V_67 -> V_17 ) ) {
if ( V_72 -> V_17 == 0 ) {
F_7 ( L_14 ) ;
return 0 ;
}
if ( V_72 -> type == V_58 ) {
void T_5 * V_83 ;
T_4 V_85 , V_86 ;
V_2 = ( void * ) V_72 ;
if ( ! V_2 -> V_41 ) {
F_46 ( 0 , L_20 ) ;
goto V_87;
}
V_83 = F_49 ( V_2 -> V_41 , V_88 ) ;
if ( ! V_83 ) {
F_50 ( L_21 , V_2 -> V_41 ) ;
goto V_87;
}
V_85 = F_51 ( V_83 + V_89 ) ;
V_86 = F_51 ( V_83 + V_90 ) ;
F_52 ( V_83 , V_88 ) ;
if ( V_85 == ( V_91 ) - 1 && V_86 == ( V_91 ) - 1 ) {
F_46 ( V_2 -> V_41 ,
L_22 ) ;
goto V_87;
}
}
V_72 = ( ( void * ) V_72 + V_72 -> V_17 ) ;
}
return 1 ;
V_87:
return 0 ;
}
int T_1 F_53 ( void )
{
int V_30 ;
V_30 = F_28 () ;
if ( V_30 )
V_30 = F_48 () ;
{
struct V_70 * V_71 ;
V_71 = (struct V_70 * ) V_67 ;
if ( V_30 && V_92 && V_93 &&
V_71 -> V_42 & 0x1 )
F_27 ( L_23 ) ;
if ( V_30 && ! V_94 && ! V_95 && ! V_96 ) {
V_95 = 1 ;
F_54 () ;
}
#ifdef F_55
if ( V_30 )
V_97 . V_49 . V_98 = V_99 ;
#endif
}
F_56 ( V_67 , V_68 ) ;
V_67 = NULL ;
return V_30 ? 1 : - V_74 ;
}
static void F_57 ( struct V_100 * V_49 )
{
F_58 ( V_49 -> V_101 ) ;
F_59 ( V_49 -> V_102 , V_49 -> V_103 ) ;
}
static int F_60 ( struct V_100 * V_49 , T_4 V_104 )
{
int V_105 , V_106 = 0 ;
V_49 -> V_102 = V_104 ;
V_49 -> V_103 = V_88 ;
if ( ! F_61 ( V_49 -> V_102 , V_49 -> V_103 , V_49 -> V_107 ) ) {
F_62 ( L_24 ) ;
V_106 = - V_108 ;
goto V_109;
}
V_49 -> V_101 = F_63 ( V_49 -> V_102 , V_49 -> V_103 ) ;
if ( ! V_49 -> V_101 ) {
F_62 ( L_25 ) ;
V_106 = - V_34 ;
goto V_110;
}
V_49 -> V_85 = F_51 ( V_49 -> V_101 + V_89 ) ;
V_49 -> V_86 = F_51 ( V_49 -> V_101 + V_90 ) ;
if ( V_49 -> V_85 == ( V_91 ) - 1 && V_49 -> V_86 == ( V_91 ) - 1 ) {
V_106 = - V_23 ;
F_46 ( V_104 , L_22 ) ;
goto V_111;
}
V_105 = F_64 ( int , F_65 ( V_49 -> V_86 ) ,
F_66 ( V_49 -> V_85 ) ) ;
V_105 = F_67 ( V_105 ) ;
if ( V_105 > V_49 -> V_103 ) {
F_58 ( V_49 -> V_101 ) ;
F_59 ( V_49 -> V_102 , V_49 -> V_103 ) ;
V_49 -> V_103 = V_105 ;
if ( ! F_61 ( V_49 -> V_102 , V_49 -> V_103 ,
V_49 -> V_107 ) ) {
F_62 ( L_24 ) ;
V_106 = - V_108 ;
goto V_109;
}
V_49 -> V_101 = F_63 ( V_49 -> V_102 , V_49 -> V_103 ) ;
if ( ! V_49 -> V_101 ) {
F_62 ( L_25 ) ;
V_106 = - V_34 ;
goto V_110;
}
}
V_106 = 0 ;
goto V_109;
V_111:
F_58 ( V_49 -> V_101 ) ;
V_110:
F_59 ( V_49 -> V_102 , V_49 -> V_103 ) ;
V_109:
return V_106 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_100 * V_49 ;
T_6 V_112 , V_113 ;
static int V_114 = 0 ;
int V_115 = 0 ;
int V_116 = 0 ;
int V_106 ;
if ( ! V_2 -> V_40 ) {
F_46 ( 0 , L_20 ) ;
return - V_23 ;
}
V_49 = F_15 ( sizeof( * V_49 ) , V_33 ) ;
if ( ! V_49 )
return - V_34 ;
V_49 -> V_117 = V_114 ++ ;
sprintf ( V_49 -> V_107 , L_26 , V_49 -> V_117 ) ;
V_106 = F_60 ( V_49 , V_2 -> V_40 ) ;
if ( V_106 ) {
F_62 ( L_27 , V_49 -> V_107 ) ;
goto error;
}
V_106 = - V_23 ;
V_115 = F_68 ( V_49 ) ;
if ( V_115 < 0 ) {
F_62 ( L_28 ,
V_49 -> V_117 ) ;
goto V_118;
}
V_116 = F_69 ( V_49 ) ;
if ( V_116 < 0 ) {
F_62 ( L_29 ,
V_49 -> V_117 ) ;
goto V_118;
}
V_49 -> V_115 = V_115 ;
V_49 -> V_116 = V_116 ;
V_49 -> V_47 = - 1 ;
V_112 = F_70 ( V_49 -> V_101 + V_119 ) ;
F_27 ( L_30 ,
V_49 -> V_117 ,
( unsigned long long ) V_2 -> V_40 ,
F_71 ( V_112 ) , F_72 ( V_112 ) ,
( unsigned long long ) V_49 -> V_85 ,
( unsigned long long ) V_49 -> V_86 ) ;
V_113 = F_70 ( V_49 -> V_101 + V_120 ) ;
if ( V_113 & V_121 )
V_49 -> V_122 |= V_123 ;
if ( V_113 & V_124 )
V_49 -> V_122 |= V_125 ;
if ( V_113 & V_126 )
V_49 -> V_122 |= V_127 ;
F_73 ( & V_49 -> V_128 ) ;
V_2 -> V_49 = V_49 ;
return 0 ;
V_118:
F_57 ( V_49 ) ;
error:
F_13 ( V_49 ) ;
return V_106 ;
}
void F_74 ( struct V_100 * V_49 )
{
if ( ! V_49 )
return;
F_75 ( V_49 ) ;
if ( V_49 -> V_101 )
F_57 ( V_49 ) ;
F_13 ( V_49 ) ;
}
static inline void F_76 ( struct V_129 * V_130 )
{
while ( V_130 -> V_131 [ V_130 -> V_132 ] == V_133 ||
V_130 -> V_131 [ V_130 -> V_132 ] == V_134 ) {
V_130 -> V_131 [ V_130 -> V_132 ] = V_135 ;
V_130 -> V_132 = ( V_130 -> V_132 + 1 ) % V_136 ;
V_130 -> V_137 ++ ;
}
}
static int F_77 ( struct V_100 * V_49 , int V_29 )
{
T_6 V_138 ;
int V_139 , V_140 ;
struct V_129 * V_130 = V_49 -> V_130 ;
int V_141 = ( V_29 + 1 ) % V_136 ;
if ( V_130 -> V_131 [ V_141 ] == V_134 )
return - V_142 ;
V_138 = F_70 ( V_49 -> V_101 + V_143 ) ;
if ( V_138 & V_144 ) {
V_139 = F_70 ( V_49 -> V_101 + V_145 ) ;
if ( ( V_139 >> V_146 ) == V_29 ) {
F_62 ( L_31
L_32 ,
( unsigned long long ) V_130 -> V_147 [ V_29 ] . V_148 ,
( unsigned long long ) V_130 -> V_147 [ V_29 ] . V_149 ) ;
memcpy ( & V_130 -> V_147 [ V_29 ] , & V_130 -> V_147 [ V_141 ] ,
sizeof( struct V_150 ) ) ;
F_78 ( V_49 , & V_130 -> V_147 [ V_29 ] ,
sizeof( struct V_150 ) ) ;
F_79 ( V_144 , V_49 -> V_101 + V_143 ) ;
return - V_23 ;
}
}
if ( V_138 & V_151 ) {
V_139 = F_70 ( V_49 -> V_101 + V_145 ) ;
V_139 = ( ( V_139 >> V_146 ) - 1 + V_136 ) % V_136 ;
V_139 |= 1 ;
V_140 = F_70 ( V_49 -> V_101 + V_152 ) ;
V_140 = ( ( V_140 >> V_146 ) - 1 + V_136 ) % V_136 ;
F_79 ( V_151 , V_49 -> V_101 + V_143 ) ;
do {
if ( V_130 -> V_131 [ V_139 ] == V_153 )
V_130 -> V_131 [ V_139 ] = V_134 ;
V_139 = ( V_139 - 2 + V_136 ) % V_136 ;
} while ( V_139 != V_140 );
if ( V_130 -> V_131 [ V_141 ] == V_134 )
return - V_142 ;
}
if ( V_138 & V_154 )
F_79 ( V_154 , V_49 -> V_101 + V_143 ) ;
return 0 ;
}
int F_80 ( struct V_150 * V_147 , struct V_100 * V_49 )
{
int V_155 ;
struct V_129 * V_130 = V_49 -> V_130 ;
struct V_150 * V_156 , V_157 ;
int V_141 , V_29 ;
unsigned long V_42 ;
if ( ! V_130 )
return 0 ;
V_156 = V_130 -> V_147 ;
V_158:
V_155 = 0 ;
F_81 ( & V_130 -> V_159 , V_42 ) ;
while ( V_130 -> V_137 < 3 ) {
F_82 ( & V_130 -> V_159 , V_42 ) ;
F_83 () ;
F_81 ( & V_130 -> V_159 , V_42 ) ;
}
V_29 = V_130 -> V_160 ;
V_141 = ( V_29 + 1 ) % V_136 ;
V_130 -> V_131 [ V_29 ] = V_130 -> V_131 [ V_141 ] = V_153 ;
V_156 [ V_29 ] = * V_147 ;
V_157 . V_148 = F_84 ( V_133 ) |
V_161 | V_162 ;
V_157 . V_149 = F_85 ( & V_130 -> V_131 [ V_141 ] ) ;
V_156 [ V_141 ] = V_157 ;
F_78 ( V_49 , & V_156 [ V_29 ] , sizeof( struct V_150 ) ) ;
F_78 ( V_49 , & V_156 [ V_141 ] , sizeof( struct V_150 ) ) ;
V_130 -> V_160 = ( V_130 -> V_160 + 2 ) % V_136 ;
V_130 -> V_137 -= 2 ;
F_79 ( V_130 -> V_160 << V_146 , V_49 -> V_101 + V_152 ) ;
while ( V_130 -> V_131 [ V_141 ] != V_133 ) {
V_155 = F_77 ( V_49 , V_29 ) ;
if ( V_155 )
break;
F_86 ( & V_130 -> V_159 ) ;
F_83 () ;
F_87 ( & V_130 -> V_159 ) ;
}
V_130 -> V_131 [ V_29 ] = V_133 ;
F_76 ( V_130 ) ;
F_82 ( & V_130 -> V_159 , V_42 ) ;
if ( V_155 == - V_142 )
goto V_158;
return V_155 ;
}
void F_88 ( struct V_100 * V_49 )
{
struct V_150 V_147 ;
V_147 . V_148 = V_163 ;
V_147 . V_149 = 0 ;
F_80 ( & V_147 , V_49 ) ;
}
void F_89 ( struct V_100 * V_49 , T_2 V_164 , T_2 V_165 , T_7 V_166 ,
T_4 type )
{
struct V_150 V_147 ;
V_147 . V_148 = F_90 ( V_166 ) | F_91 ( V_165 ) | F_92 ( V_164 )
| F_93 ( type ) | V_167 ;
V_147 . V_149 = 0 ;
F_80 ( & V_147 , V_49 ) ;
}
void F_94 ( struct V_100 * V_49 , T_2 V_164 , T_4 V_83 ,
unsigned int V_168 , T_4 type )
{
T_7 V_169 = 0 , V_170 = 0 ;
struct V_150 V_147 ;
int V_171 = 0 ;
if ( F_95 ( V_49 -> V_85 ) )
V_169 = 1 ;
if ( F_96 ( V_49 -> V_85 ) )
V_170 = 1 ;
V_147 . V_148 = F_97 ( V_164 ) | F_98 ( V_170 ) | F_99 ( V_169 )
| F_100 ( type ) | V_172 ;
V_147 . V_149 = F_101 ( V_83 ) | F_102 ( V_171 )
| F_103 ( V_168 ) ;
F_80 ( & V_147 , V_49 ) ;
}
void F_104 ( struct V_100 * V_49 , T_2 V_165 , T_2 V_173 ,
T_4 V_83 , unsigned V_174 )
{
struct V_150 V_147 ;
if ( V_174 ) {
F_105 ( V_83 & ( ( 1 << ( V_175 + V_174 ) ) - 1 ) ) ;
V_83 |= ( 1 << ( V_175 + V_174 - 1 ) ) - 1 ;
V_147 . V_149 = F_106 ( V_83 ) | V_176 ;
} else
V_147 . V_149 = F_106 ( V_83 ) ;
if ( V_173 >= V_177 )
V_173 = 0 ;
V_147 . V_148 = F_107 ( V_165 ) | F_108 ( V_173 ) |
V_178 ;
F_80 ( & V_147 , V_49 ) ;
}
void F_109 ( struct V_100 * V_49 )
{
unsigned long V_42 ;
T_6 V_113 ;
T_8 V_179 = F_110 () ;
if ( ! F_111 ( V_49 -> V_86 ) )
return;
F_81 ( & V_49 -> V_128 , V_42 ) ;
V_113 = F_51 ( V_49 -> V_101 + V_120 ) ;
if ( ! ( V_113 & V_126 ) )
goto V_25;
while ( ( F_70 ( V_49 -> V_101 + V_152 ) !=
F_70 ( V_49 -> V_101 + V_145 ) ) &&
( V_180 > ( F_110 () - V_179 ) ) )
F_83 () ;
V_49 -> V_122 &= ~ V_127 ;
F_79 ( V_49 -> V_122 , V_49 -> V_101 + V_181 ) ;
F_112 ( V_49 , V_120 , F_70 ,
! ( V_113 & V_126 ) , V_113 ) ;
V_25:
F_82 ( & V_49 -> V_128 , V_42 ) ;
}
static void F_113 ( struct V_100 * V_49 )
{
T_6 V_113 ;
unsigned long V_42 ;
struct V_129 * V_130 = V_49 -> V_130 ;
V_130 -> V_160 = V_130 -> V_132 = 0 ;
V_130 -> V_137 = V_136 ;
F_81 ( & V_49 -> V_128 , V_42 ) ;
F_79 ( 0 , V_49 -> V_101 + V_152 ) ;
F_114 ( V_49 -> V_101 + V_182 , F_85 ( V_130 -> V_147 ) ) ;
V_49 -> V_122 |= V_127 ;
F_79 ( V_49 -> V_122 , V_49 -> V_101 + V_181 ) ;
F_112 ( V_49 , V_120 , F_70 , ( V_113 & V_126 ) , V_113 ) ;
F_82 ( & V_49 -> V_128 , V_42 ) ;
}
int F_115 ( struct V_100 * V_49 )
{
struct V_129 * V_130 ;
struct V_183 * V_184 ;
if ( ! F_111 ( V_49 -> V_86 ) )
return - V_185 ;
if ( V_49 -> V_130 )
return 0 ;
V_49 -> V_130 = F_116 ( sizeof( * V_130 ) , V_186 ) ;
if ( ! V_49 -> V_130 )
return - V_34 ;
V_130 = V_49 -> V_130 ;
V_184 = F_117 ( V_49 -> V_47 , V_186 | V_187 , 0 ) ;
if ( ! V_184 ) {
F_13 ( V_130 ) ;
V_49 -> V_130 = 0 ;
return - V_34 ;
}
V_130 -> V_147 = F_118 ( V_184 ) ;
V_130 -> V_131 = F_15 ( V_136 * sizeof( int ) , V_186 ) ;
if ( ! V_130 -> V_131 ) {
F_119 ( ( unsigned long ) V_130 -> V_147 ) ;
F_13 ( V_130 ) ;
V_49 -> V_130 = 0 ;
return - V_34 ;
}
V_130 -> V_160 = V_130 -> V_132 = 0 ;
V_130 -> V_137 = V_136 ;
F_73 ( & V_130 -> V_159 ) ;
F_113 ( V_49 ) ;
return 0 ;
}
const char * F_120 ( T_7 V_188 , int * V_189 )
{
if ( V_188 >= 0x20 && ( V_188 - 0x20 <
F_121 ( V_190 ) ) ) {
* V_189 = V_191 ;
return V_190 [ V_188 - 0x20 ] ;
} else if ( V_188 < F_121 ( V_192 ) ) {
* V_189 = V_193 ;
return V_192 [ V_188 ] ;
} else {
* V_189 = V_194 ;
return L_33 ;
}
}
void F_122 ( struct V_195 * V_196 )
{
struct V_100 * V_49 = F_123 ( V_196 ) ;
unsigned long V_197 ;
F_81 ( & V_49 -> V_128 , V_197 ) ;
F_79 ( 0 , V_49 -> V_101 + V_198 ) ;
F_70 ( V_49 -> V_101 + V_198 ) ;
F_82 ( & V_49 -> V_128 , V_197 ) ;
}
void F_124 ( struct V_195 * V_196 )
{
unsigned long V_197 ;
struct V_100 * V_49 = F_123 ( V_196 ) ;
F_81 ( & V_49 -> V_128 , V_197 ) ;
F_79 ( V_199 , V_49 -> V_101 + V_198 ) ;
F_70 ( V_49 -> V_101 + V_198 ) ;
F_82 ( & V_49 -> V_128 , V_197 ) ;
}
void F_125 ( int V_200 , struct V_201 * V_202 )
{
struct V_100 * V_49 = F_126 ( V_200 ) ;
unsigned long V_197 ;
F_81 ( & V_49 -> V_128 , V_197 ) ;
F_79 ( V_202 -> V_196 , V_49 -> V_101 + V_203 ) ;
F_79 ( V_202 -> V_204 , V_49 -> V_101 + V_205 ) ;
F_79 ( V_202 -> V_206 , V_49 -> V_101 + V_207 ) ;
F_82 ( & V_49 -> V_128 , V_197 ) ;
}
void F_127 ( int V_200 , struct V_201 * V_202 )
{
struct V_100 * V_49 = F_126 ( V_200 ) ;
unsigned long V_197 ;
F_81 ( & V_49 -> V_128 , V_197 ) ;
V_202 -> V_196 = F_70 ( V_49 -> V_101 + V_203 ) ;
V_202 -> V_204 = F_70 ( V_49 -> V_101 + V_205 ) ;
V_202 -> V_206 = F_70 ( V_49 -> V_101 + V_207 ) ;
F_82 ( & V_49 -> V_128 , V_197 ) ;
}
static int F_128 ( struct V_100 * V_49 , int type ,
T_7 V_188 , T_2 V_208 , unsigned long long V_83 )
{
const char * V_209 ;
int V_189 ;
V_209 = F_120 ( V_188 , & V_189 ) ;
if ( V_189 == V_191 )
F_62 ( L_34
L_35
L_36 ,
( V_208 >> 8 ) , F_129 ( V_208 & 0xFF ) ,
F_130 ( V_208 & 0xFF ) , V_83 >> 48 ,
V_188 , V_209 ) ;
else
F_62 ( L_37
L_38
L_39 ,
( type ? L_40 : L_41 ) ,
( V_208 >> 8 ) , F_129 ( V_208 & 0xFF ) ,
F_130 ( V_208 & 0xFF ) , V_83 , V_188 , V_209 ) ;
return 0 ;
}
T_9 F_131 ( int V_200 , void * V_210 )
{
struct V_100 * V_49 = V_210 ;
int V_101 , V_211 ;
T_6 V_212 ;
unsigned long V_197 ;
F_81 ( & V_49 -> V_128 , V_197 ) ;
V_212 = F_70 ( V_49 -> V_101 + V_143 ) ;
if ( V_212 )
F_62 ( L_42 , V_212 ) ;
if ( ! ( V_212 & V_213 ) )
goto V_214;
V_211 = F_132 ( V_212 ) ;
V_101 = F_133 ( V_49 -> V_85 ) ;
while ( 1 ) {
T_7 V_188 ;
T_2 V_208 ;
T_4 V_215 ;
int type ;
T_6 V_196 ;
V_196 = F_70 ( V_49 -> V_101 + V_101 +
V_211 * V_216 + 12 ) ;
if ( ! ( V_196 & V_217 ) )
break;
V_188 = F_134 ( V_196 ) ;
type = F_135 ( V_196 ) ;
V_196 = F_70 ( V_49 -> V_101 + V_101 +
V_211 * V_216 + 8 ) ;
V_208 = F_136 ( V_196 ) ;
V_215 = F_51 ( V_49 -> V_101 + V_101 +
V_211 * V_216 ) ;
V_215 = F_137 ( V_215 ) ;
F_79 ( V_217 , V_49 -> V_101 + V_101 +
V_211 * V_216 + 12 ) ;
F_82 ( & V_49 -> V_128 , V_197 ) ;
F_128 ( V_49 , type , V_188 ,
V_208 , V_215 ) ;
V_211 ++ ;
if ( V_211 >= F_138 ( V_49 -> V_85 ) )
V_211 = 0 ;
F_81 ( & V_49 -> V_128 , V_197 ) ;
}
F_79 ( V_218 | V_213 , V_49 -> V_101 + V_143 ) ;
V_214:
F_82 ( & V_49 -> V_128 , V_197 ) ;
return V_219 ;
}
int F_139 ( struct V_100 * V_49 )
{
int V_200 , V_30 ;
if ( V_49 -> V_200 )
return 0 ;
V_200 = F_140 () ;
if ( ! V_200 ) {
F_62 ( L_43 ) ;
return - V_23 ;
}
F_141 ( V_200 , V_49 ) ;
V_49 -> V_200 = V_200 ;
V_30 = F_142 ( V_200 ) ;
if ( V_30 ) {
F_141 ( V_200 , NULL ) ;
V_49 -> V_200 = 0 ;
F_143 ( V_200 ) ;
return V_30 ;
}
V_30 = F_144 ( V_200 , F_131 , V_220 , V_49 -> V_107 , V_49 ) ;
if ( V_30 )
F_62 ( L_44 ) ;
return V_30 ;
}
int T_1 F_145 ( void )
{
struct V_1 * V_2 ;
F_20 (drhd) {
int V_30 ;
struct V_100 * V_49 = V_2 -> V_49 ;
T_6 V_212 ;
V_30 = F_139 ( V_49 ) ;
if ( V_30 ) {
F_62 ( L_45 ,
( unsigned long long ) V_2 -> V_40 , V_30 ) ;
return - 1 ;
}
F_131 ( V_49 -> V_200 , V_49 ) ;
V_212 = F_70 ( V_49 -> V_101 + V_143 ) ;
F_79 ( V_212 , V_49 -> V_101 + V_143 ) ;
}
return 0 ;
}
int F_146 ( struct V_100 * V_49 )
{
if ( ! F_111 ( V_49 -> V_86 ) )
return - V_185 ;
if ( ! V_49 -> V_130 )
return - V_185 ;
F_109 ( V_49 ) ;
F_113 ( V_49 ) ;
return 0 ;
}
int T_1 F_147 ( void )
{
struct V_70 * V_71 ;
V_71 = (struct V_70 * ) V_67 ;
if ( ! V_71 )
return 0 ;
return V_71 -> V_42 & 0x1 ;
}
