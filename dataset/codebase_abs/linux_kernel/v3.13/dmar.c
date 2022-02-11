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
V_13 = F_8 ( V_12 , F_9 ( V_15 -> V_18 , V_15 -> V_19 ) ) ;
if ( ! V_13 ) {
break;
}
V_15 ++ ;
V_16 -- ;
V_12 = V_13 -> V_20 ;
}
if ( ! V_13 ) {
F_7 ( L_2 ,
V_10 , V_7 -> V_12 , V_15 -> V_18 , V_15 -> V_19 ) ;
* V_9 = NULL ;
return 0 ;
}
if ( ( V_7 -> V_21 == V_22 && \
V_13 -> V_20 ) || ( V_7 -> V_21 == \
V_23 && ! V_13 -> V_20 ) ) {
F_6 ( V_13 ) ;
F_7 ( L_3 ,
F_10 ( V_13 ) ) ;
return - V_24 ;
}
* V_9 = V_13 ;
return 0 ;
}
int T_1 F_11 ( void * V_25 , void * V_26 , int * V_27 ,
struct V_8 * * * V_28 , T_2 V_10 )
{
struct V_6 * V_7 ;
void * V_29 = V_25 ;
int V_30 ;
int V_31 ;
* V_27 = 0 ;
while ( V_25 < V_26 ) {
V_7 = V_25 ;
if ( V_7 -> V_21 == V_22 ||
V_7 -> V_21 == V_23 )
( * V_27 ) ++ ;
else if ( V_7 -> V_21 != V_32 &&
V_7 -> V_21 != V_33 ) {
F_7 ( L_4 ) ;
}
V_25 += V_7 -> V_17 ;
}
if ( * V_27 == 0 )
return 0 ;
* V_28 = F_12 ( * V_27 , sizeof( struct V_8 * ) , V_34 ) ;
if ( ! * V_28 )
return - V_35 ;
V_25 = V_29 ;
V_30 = 0 ;
while ( V_25 < V_26 ) {
V_7 = V_25 ;
if ( V_7 -> V_21 == V_22 ||
V_7 -> V_21 == V_23 ) {
V_31 = F_4 ( V_7 ,
& ( * V_28 ) [ V_30 ] , V_10 ) ;
if ( V_31 ) {
F_13 ( * V_28 ) ;
return V_31 ;
}
V_30 ++ ;
}
V_25 += V_7 -> V_17 ;
}
return 0 ;
}
static int T_1
F_14 ( struct V_36 * V_37 )
{
struct V_38 * V_2 ;
struct V_1 * V_39 ;
int V_31 = 0 ;
V_2 = (struct V_38 * ) V_37 ;
V_39 = F_15 ( sizeof( * V_39 ) , V_34 ) ;
if ( ! V_39 )
return - V_35 ;
V_39 -> V_40 = V_37 ;
V_39 -> V_41 = V_2 -> V_42 ;
V_39 -> V_10 = V_2 -> V_10 ;
V_39 -> V_3 = V_2 -> V_43 & 0x1 ;
V_31 = F_16 ( V_39 ) ;
if ( V_31 ) {
F_13 ( V_39 ) ;
return V_31 ;
}
F_1 ( V_39 ) ;
return 0 ;
}
static int T_1 F_17 ( struct V_1 * V_39 )
{
struct V_38 * V_2 ;
int V_31 = 0 ;
V_2 = (struct V_38 * ) V_39 -> V_40 ;
if ( V_39 -> V_3 )
return 0 ;
V_31 = F_11 ( ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_37 . V_17 ,
& V_39 -> V_44 , & V_39 -> V_28 ,
V_2 -> V_10 ) ;
if ( V_31 ) {
F_18 ( & V_39 -> V_4 ) ;
F_13 ( V_39 ) ;
}
return V_31 ;
}
static int T_1
F_19 ( struct V_36 * V_37 )
{
struct V_45 * V_46 ;
struct V_1 * V_2 ;
V_46 = (struct V_45 * ) V_37 ;
F_20 (drhd) {
if ( V_2 -> V_41 == V_46 -> V_47 ) {
int V_48 = F_21 ( V_46 -> V_49 ) ;
if ( ! F_22 ( V_48 ) )
V_48 = - 1 ;
V_2 -> V_50 -> V_48 = V_48 ;
return 0 ;
}
}
F_23 (
1 , V_51 ,
L_5
L_6 ,
V_2 -> V_41 ,
F_24 ( V_52 ) ,
F_24 ( V_53 ) ,
F_24 ( V_54 ) ) ;
return 0 ;
}
static void T_1
F_25 ( struct V_36 * V_37 )
{
struct V_38 * V_2 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_45 * V_46 ;
switch ( V_37 -> type ) {
case V_59 :
V_2 = F_26 ( V_37 , struct V_38 ,
V_37 ) ;
F_27 ( L_7 ,
( unsigned long long ) V_2 -> V_42 , V_2 -> V_43 ) ;
break;
case V_60 :
V_56 = F_26 ( V_37 , struct V_55 ,
V_37 ) ;
F_27 ( L_8 ,
( unsigned long long ) V_56 -> V_47 ,
( unsigned long long ) V_56 -> V_61 ) ;
break;
case V_62 :
V_58 = F_26 ( V_37 , struct V_57 , V_37 ) ;
F_27 ( L_9 , V_58 -> V_43 ) ;
break;
case V_63 :
V_46 = F_26 ( V_37 , struct V_45 , V_37 ) ;
F_27 ( L_10 ,
( unsigned long long ) V_46 -> V_47 ,
V_46 -> V_49 ) ;
break;
}
}
static int T_1 F_28 ( void )
{
T_3 V_64 = V_65 ;
V_64 = F_29 ( V_66 , 0 ,
(struct V_67 * * ) & V_68 ,
& V_69 ) ;
if ( F_30 ( V_64 ) && ! V_68 ) {
F_7 ( L_11 ) ;
V_64 = V_70 ;
}
return ( F_30 ( V_64 ) ? 1 : 0 ) ;
}
static int T_1
F_31 ( void )
{
struct V_71 * V_72 ;
struct V_36 * V_73 ;
int V_31 = 0 ;
int V_74 = 0 ;
F_28 () ;
V_68 = F_32 ( V_68 ) ;
V_72 = (struct V_71 * ) V_68 ;
if ( ! V_72 )
return - V_75 ;
if ( V_72 -> V_76 < V_77 - 1 ) {
F_7 ( L_12 ) ;
return - V_24 ;
}
F_27 ( L_13 , V_72 -> V_76 + 1 ) ;
V_73 = (struct V_36 * ) ( V_72 + 1 ) ;
while ( ( ( unsigned long ) V_73 ) <
( ( ( unsigned long ) V_72 ) + V_68 -> V_17 ) ) {
if ( V_73 -> V_17 == 0 ) {
F_7 ( L_14 ) ;
V_31 = - V_24 ;
break;
}
F_25 ( V_73 ) ;
switch ( V_73 -> type ) {
case V_59 :
V_74 ++ ;
V_31 = F_14 ( V_73 ) ;
break;
case V_60 :
V_31 = F_33 ( V_73 ) ;
break;
case V_62 :
V_31 = F_34 ( V_73 ) ;
break;
case V_63 :
#ifdef F_35
V_31 = F_19 ( V_73 ) ;
#endif
break;
default:
F_7 ( L_15 ,
V_73 -> type ) ;
V_31 = 0 ;
break;
}
if ( V_31 )
break;
V_73 = ( ( void * ) V_73 + V_73 -> V_17 ) ;
}
if ( V_74 == 0 )
F_7 ( V_78 L_16 ) ;
return V_31 ;
}
static int F_36 ( struct V_8 * V_28 [] , int V_27 ,
struct V_8 * V_9 )
{
int V_30 ;
while ( V_9 ) {
for ( V_30 = 0 ; V_30 < V_27 ; V_30 ++ )
if ( V_9 == V_28 [ V_30 ] )
return 1 ;
V_9 = V_9 -> V_12 -> V_79 ;
}
return 0 ;
}
struct V_1 *
F_37 ( struct V_8 * V_9 )
{
struct V_1 * V_39 = NULL ;
struct V_38 * V_2 ;
V_9 = F_38 ( V_9 ) ;
F_20 (dmaru) {
V_2 = F_26 ( V_39 -> V_40 ,
struct V_38 ,
V_37 ) ;
if ( V_39 -> V_3 &&
V_2 -> V_10 == F_39 ( V_9 -> V_12 ) )
return V_39 ;
if ( F_36 ( V_39 -> V_28 ,
V_39 -> V_44 , V_9 ) )
return V_39 ;
}
return NULL ;
}
int T_1 F_40 ( void )
{
static int V_80 ;
struct V_1 * V_2 , * V_81 ;
int V_31 = - V_75 ;
if ( V_80 )
return V_80 ;
if ( F_41 ( & V_5 ) )
goto V_82;
F_42 (drhd, drhd_n, &dmar_drhd_units, list) {
V_31 = F_17 ( V_2 ) ;
if ( V_31 )
goto V_82;
}
V_31 = F_43 () ;
if ( V_31 )
goto V_82;
V_80 = 1 ;
return 0 ;
V_82:
V_80 = V_31 ;
return V_31 ;
}
int T_1 F_44 ( void )
{
static int V_83 ;
int V_31 ;
if ( V_83 )
return 0 ;
V_83 = 1 ;
V_31 = F_31 () ;
if ( V_31 ) {
if ( V_31 != - V_75 )
F_27 ( L_17 ) ;
return V_31 ;
}
if ( F_41 ( & V_5 ) ) {
F_27 ( L_18 ) ;
return - V_75 ;
}
return 0 ;
}
static void F_45 ( T_4 V_84 , const char * V_85 )
{
F_46 (
1 , V_51 ,
L_19
L_6 ,
V_84 , V_85 ,
F_24 ( V_52 ) ,
F_24 ( V_53 ) ,
F_24 ( V_54 ) ) ;
}
int T_1 F_47 ( void )
{
struct V_71 * V_72 ;
struct V_36 * V_73 ;
struct V_38 * V_2 ;
V_72 = (struct V_71 * ) V_68 ;
V_73 = (struct V_36 * ) ( V_72 + 1 ) ;
while ( ( ( unsigned long ) V_73 ) <
( ( ( unsigned long ) V_72 ) + V_68 -> V_17 ) ) {
if ( V_73 -> V_17 == 0 ) {
F_7 ( L_14 ) ;
return 0 ;
}
if ( V_73 -> type == V_59 ) {
void T_5 * V_84 ;
T_4 V_86 , V_87 ;
V_2 = ( void * ) V_73 ;
if ( ! V_2 -> V_42 ) {
F_45 ( 0 , L_20 ) ;
goto V_88;
}
V_84 = F_48 ( V_2 -> V_42 , V_89 ) ;
if ( ! V_84 ) {
F_49 ( L_21 , V_2 -> V_42 ) ;
goto V_88;
}
V_86 = F_50 ( V_84 + V_90 ) ;
V_87 = F_50 ( V_84 + V_91 ) ;
F_51 ( V_84 , V_89 ) ;
if ( V_86 == ( V_92 ) - 1 && V_87 == ( V_92 ) - 1 ) {
F_45 ( V_2 -> V_42 ,
L_22 ) ;
goto V_88;
}
}
V_73 = ( ( void * ) V_73 + V_73 -> V_17 ) ;
}
return 1 ;
V_88:
return 0 ;
}
int T_1 F_52 ( void )
{
int V_31 ;
V_31 = F_28 () ;
if ( V_31 )
V_31 = F_47 () ;
{
struct V_71 * V_72 ;
V_72 = (struct V_71 * ) V_68 ;
if ( V_31 && V_93 && V_94 &&
V_72 -> V_43 & 0x1 )
F_27 ( L_23 ) ;
if ( V_31 && ! V_95 && ! V_96 && ! V_97 ) {
V_96 = 1 ;
F_53 () ;
}
#ifdef F_54
if ( V_31 )
V_98 . V_50 . V_99 = V_100 ;
#endif
}
F_55 ( V_68 , V_69 ) ;
V_68 = NULL ;
return V_31 ? 1 : - V_75 ;
}
static void F_56 ( struct V_101 * V_50 )
{
F_57 ( V_50 -> V_102 ) ;
F_58 ( V_50 -> V_103 , V_50 -> V_104 ) ;
}
static int F_59 ( struct V_101 * V_50 , T_4 V_105 )
{
int V_106 , V_107 = 0 ;
V_50 -> V_103 = V_105 ;
V_50 -> V_104 = V_89 ;
if ( ! F_60 ( V_50 -> V_103 , V_50 -> V_104 , V_50 -> V_108 ) ) {
F_61 ( L_24 ) ;
V_107 = - V_109 ;
goto V_110;
}
V_50 -> V_102 = F_62 ( V_50 -> V_103 , V_50 -> V_104 ) ;
if ( ! V_50 -> V_102 ) {
F_61 ( L_25 ) ;
V_107 = - V_35 ;
goto V_111;
}
V_50 -> V_86 = F_50 ( V_50 -> V_102 + V_90 ) ;
V_50 -> V_87 = F_50 ( V_50 -> V_102 + V_91 ) ;
if ( V_50 -> V_86 == ( V_92 ) - 1 && V_50 -> V_87 == ( V_92 ) - 1 ) {
V_107 = - V_24 ;
F_45 ( V_105 , L_22 ) ;
goto V_112;
}
V_106 = F_63 ( int , F_64 ( V_50 -> V_87 ) ,
F_65 ( V_50 -> V_86 ) ) ;
V_106 = F_66 ( V_106 ) ;
if ( V_106 > V_50 -> V_104 ) {
F_57 ( V_50 -> V_102 ) ;
F_58 ( V_50 -> V_103 , V_50 -> V_104 ) ;
V_50 -> V_104 = V_106 ;
if ( ! F_60 ( V_50 -> V_103 , V_50 -> V_104 ,
V_50 -> V_108 ) ) {
F_61 ( L_24 ) ;
V_107 = - V_109 ;
goto V_110;
}
V_50 -> V_102 = F_62 ( V_50 -> V_103 , V_50 -> V_104 ) ;
if ( ! V_50 -> V_102 ) {
F_61 ( L_25 ) ;
V_107 = - V_35 ;
goto V_111;
}
}
V_107 = 0 ;
goto V_110;
V_112:
F_57 ( V_50 -> V_102 ) ;
V_111:
F_58 ( V_50 -> V_103 , V_50 -> V_104 ) ;
V_110:
return V_107 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_101 * V_50 ;
T_6 V_113 , V_114 ;
static int V_115 = 0 ;
int V_116 = 0 ;
int V_117 = 0 ;
int V_107 ;
if ( ! V_2 -> V_41 ) {
F_45 ( 0 , L_20 ) ;
return - V_24 ;
}
V_50 = F_15 ( sizeof( * V_50 ) , V_34 ) ;
if ( ! V_50 )
return - V_35 ;
V_50 -> V_118 = V_115 ++ ;
sprintf ( V_50 -> V_108 , L_26 , V_50 -> V_118 ) ;
V_107 = F_59 ( V_50 , V_2 -> V_41 ) ;
if ( V_107 ) {
F_61 ( L_27 , V_50 -> V_108 ) ;
goto error;
}
V_107 = - V_24 ;
V_116 = F_67 ( V_50 ) ;
if ( V_116 < 0 ) {
F_61 ( L_28 ,
V_50 -> V_118 ) ;
goto V_119;
}
V_117 = F_68 ( V_50 ) ;
if ( V_117 < 0 ) {
F_61 ( L_29 ,
V_50 -> V_118 ) ;
goto V_119;
}
V_50 -> V_116 = V_116 ;
V_50 -> V_117 = V_117 ;
V_50 -> V_48 = - 1 ;
V_113 = F_69 ( V_50 -> V_102 + V_120 ) ;
F_27 ( L_30 ,
V_50 -> V_118 ,
( unsigned long long ) V_2 -> V_41 ,
F_70 ( V_113 ) , F_71 ( V_113 ) ,
( unsigned long long ) V_50 -> V_86 ,
( unsigned long long ) V_50 -> V_87 ) ;
V_114 = F_69 ( V_50 -> V_102 + V_121 ) ;
if ( V_114 & V_122 )
V_50 -> V_123 |= V_124 ;
if ( V_114 & V_125 )
V_50 -> V_123 |= V_126 ;
if ( V_114 & V_127 )
V_50 -> V_123 |= V_128 ;
F_72 ( & V_50 -> V_129 ) ;
V_2 -> V_50 = V_50 ;
return 0 ;
V_119:
F_56 ( V_50 ) ;
error:
F_13 ( V_50 ) ;
return V_107 ;
}
void F_73 ( struct V_101 * V_50 )
{
if ( ! V_50 )
return;
F_74 ( V_50 ) ;
if ( V_50 -> V_102 )
F_56 ( V_50 ) ;
F_13 ( V_50 ) ;
}
static inline void F_75 ( struct V_130 * V_131 )
{
while ( V_131 -> V_132 [ V_131 -> V_133 ] == V_134 ||
V_131 -> V_132 [ V_131 -> V_133 ] == V_135 ) {
V_131 -> V_132 [ V_131 -> V_133 ] = V_136 ;
V_131 -> V_133 = ( V_131 -> V_133 + 1 ) % V_137 ;
V_131 -> V_138 ++ ;
}
}
static int F_76 ( struct V_101 * V_50 , int V_30 )
{
T_6 V_139 ;
int V_140 , V_141 ;
struct V_130 * V_131 = V_50 -> V_131 ;
int V_142 = ( V_30 + 1 ) % V_137 ;
if ( V_131 -> V_132 [ V_142 ] == V_135 )
return - V_143 ;
V_139 = F_69 ( V_50 -> V_102 + V_144 ) ;
if ( V_139 & V_145 ) {
V_140 = F_69 ( V_50 -> V_102 + V_146 ) ;
if ( ( V_140 >> V_147 ) == V_30 ) {
F_61 ( L_31
L_32 ,
( unsigned long long ) V_131 -> V_148 [ V_30 ] . V_149 ,
( unsigned long long ) V_131 -> V_148 [ V_30 ] . V_150 ) ;
memcpy ( & V_131 -> V_148 [ V_30 ] , & V_131 -> V_148 [ V_142 ] ,
sizeof( struct V_151 ) ) ;
F_77 ( V_50 , & V_131 -> V_148 [ V_30 ] ,
sizeof( struct V_151 ) ) ;
F_78 ( V_145 , V_50 -> V_102 + V_144 ) ;
return - V_24 ;
}
}
if ( V_139 & V_152 ) {
V_140 = F_69 ( V_50 -> V_102 + V_146 ) ;
V_140 = ( ( V_140 >> V_147 ) - 1 + V_137 ) % V_137 ;
V_140 |= 1 ;
V_141 = F_69 ( V_50 -> V_102 + V_153 ) ;
V_141 = ( ( V_141 >> V_147 ) - 1 + V_137 ) % V_137 ;
F_78 ( V_152 , V_50 -> V_102 + V_144 ) ;
do {
if ( V_131 -> V_132 [ V_140 ] == V_154 )
V_131 -> V_132 [ V_140 ] = V_135 ;
V_140 = ( V_140 - 2 + V_137 ) % V_137 ;
} while ( V_140 != V_141 );
if ( V_131 -> V_132 [ V_142 ] == V_135 )
return - V_143 ;
}
if ( V_139 & V_155 )
F_78 ( V_155 , V_50 -> V_102 + V_144 ) ;
return 0 ;
}
int F_79 ( struct V_151 * V_148 , struct V_101 * V_50 )
{
int V_156 ;
struct V_130 * V_131 = V_50 -> V_131 ;
struct V_151 * V_157 , V_158 ;
int V_142 , V_30 ;
unsigned long V_43 ;
if ( ! V_131 )
return 0 ;
V_157 = V_131 -> V_148 ;
V_159:
V_156 = 0 ;
F_80 ( & V_131 -> V_160 , V_43 ) ;
while ( V_131 -> V_138 < 3 ) {
F_81 ( & V_131 -> V_160 , V_43 ) ;
F_82 () ;
F_80 ( & V_131 -> V_160 , V_43 ) ;
}
V_30 = V_131 -> V_161 ;
V_142 = ( V_30 + 1 ) % V_137 ;
V_131 -> V_132 [ V_30 ] = V_131 -> V_132 [ V_142 ] = V_154 ;
V_157 [ V_30 ] = * V_148 ;
V_158 . V_149 = F_83 ( V_134 ) |
V_162 | V_163 ;
V_158 . V_150 = F_84 ( & V_131 -> V_132 [ V_142 ] ) ;
V_157 [ V_142 ] = V_158 ;
F_77 ( V_50 , & V_157 [ V_30 ] , sizeof( struct V_151 ) ) ;
F_77 ( V_50 , & V_157 [ V_142 ] , sizeof( struct V_151 ) ) ;
V_131 -> V_161 = ( V_131 -> V_161 + 2 ) % V_137 ;
V_131 -> V_138 -= 2 ;
F_78 ( V_131 -> V_161 << V_147 , V_50 -> V_102 + V_153 ) ;
while ( V_131 -> V_132 [ V_142 ] != V_134 ) {
V_156 = F_76 ( V_50 , V_30 ) ;
if ( V_156 )
break;
F_85 ( & V_131 -> V_160 ) ;
F_82 () ;
F_86 ( & V_131 -> V_160 ) ;
}
V_131 -> V_132 [ V_30 ] = V_134 ;
F_75 ( V_131 ) ;
F_81 ( & V_131 -> V_160 , V_43 ) ;
if ( V_156 == - V_143 )
goto V_159;
return V_156 ;
}
void F_87 ( struct V_101 * V_50 )
{
struct V_151 V_148 ;
V_148 . V_149 = V_164 ;
V_148 . V_150 = 0 ;
F_79 ( & V_148 , V_50 ) ;
}
void F_88 ( struct V_101 * V_50 , T_2 V_165 , T_2 V_166 , T_7 V_167 ,
T_4 type )
{
struct V_151 V_148 ;
V_148 . V_149 = F_89 ( V_167 ) | F_90 ( V_166 ) | F_91 ( V_165 )
| F_92 ( type ) | V_168 ;
V_148 . V_150 = 0 ;
F_79 ( & V_148 , V_50 ) ;
}
void F_93 ( struct V_101 * V_50 , T_2 V_165 , T_4 V_84 ,
unsigned int V_169 , T_4 type )
{
T_7 V_170 = 0 , V_171 = 0 ;
struct V_151 V_148 ;
int V_172 = 0 ;
if ( F_94 ( V_50 -> V_86 ) )
V_170 = 1 ;
if ( F_95 ( V_50 -> V_86 ) )
V_171 = 1 ;
V_148 . V_149 = F_96 ( V_165 ) | F_97 ( V_171 ) | F_98 ( V_170 )
| F_99 ( type ) | V_173 ;
V_148 . V_150 = F_100 ( V_84 ) | F_101 ( V_172 )
| F_102 ( V_169 ) ;
F_79 ( & V_148 , V_50 ) ;
}
void F_103 ( struct V_101 * V_50 , T_2 V_166 , T_2 V_174 ,
T_4 V_84 , unsigned V_175 )
{
struct V_151 V_148 ;
if ( V_175 ) {
F_104 ( V_84 & ( ( 1 << ( V_176 + V_175 ) ) - 1 ) ) ;
V_84 |= ( 1 << ( V_176 + V_175 - 1 ) ) - 1 ;
V_148 . V_150 = F_105 ( V_84 ) | V_177 ;
} else
V_148 . V_150 = F_105 ( V_84 ) ;
if ( V_174 >= V_178 )
V_174 = 0 ;
V_148 . V_149 = F_106 ( V_166 ) | F_107 ( V_174 ) |
V_179 ;
F_79 ( & V_148 , V_50 ) ;
}
void F_108 ( struct V_101 * V_50 )
{
unsigned long V_43 ;
T_6 V_114 ;
T_8 V_180 = F_109 () ;
if ( ! F_110 ( V_50 -> V_87 ) )
return;
F_80 ( & V_50 -> V_129 , V_43 ) ;
V_114 = F_50 ( V_50 -> V_102 + V_121 ) ;
if ( ! ( V_114 & V_127 ) )
goto V_26;
while ( ( F_69 ( V_50 -> V_102 + V_153 ) !=
F_69 ( V_50 -> V_102 + V_146 ) ) &&
( V_181 > ( F_109 () - V_180 ) ) )
F_82 () ;
V_50 -> V_123 &= ~ V_128 ;
F_78 ( V_50 -> V_123 , V_50 -> V_102 + V_182 ) ;
F_111 ( V_50 , V_121 , F_69 ,
! ( V_114 & V_127 ) , V_114 ) ;
V_26:
F_81 ( & V_50 -> V_129 , V_43 ) ;
}
static void F_112 ( struct V_101 * V_50 )
{
T_6 V_114 ;
unsigned long V_43 ;
struct V_130 * V_131 = V_50 -> V_131 ;
V_131 -> V_161 = V_131 -> V_133 = 0 ;
V_131 -> V_138 = V_137 ;
F_80 ( & V_50 -> V_129 , V_43 ) ;
F_78 ( 0 , V_50 -> V_102 + V_153 ) ;
F_113 ( V_50 -> V_102 + V_183 , F_84 ( V_131 -> V_148 ) ) ;
V_50 -> V_123 |= V_128 ;
F_78 ( V_50 -> V_123 , V_50 -> V_102 + V_182 ) ;
F_111 ( V_50 , V_121 , F_69 , ( V_114 & V_127 ) , V_114 ) ;
F_81 ( & V_50 -> V_129 , V_43 ) ;
}
int F_114 ( struct V_101 * V_50 )
{
struct V_130 * V_131 ;
struct V_184 * V_185 ;
if ( ! F_110 ( V_50 -> V_87 ) )
return - V_186 ;
if ( V_50 -> V_131 )
return 0 ;
V_50 -> V_131 = F_115 ( sizeof( * V_131 ) , V_187 ) ;
if ( ! V_50 -> V_131 )
return - V_35 ;
V_131 = V_50 -> V_131 ;
V_185 = F_116 ( V_50 -> V_48 , V_187 | V_188 , 0 ) ;
if ( ! V_185 ) {
F_13 ( V_131 ) ;
V_50 -> V_131 = 0 ;
return - V_35 ;
}
V_131 -> V_148 = F_117 ( V_185 ) ;
V_131 -> V_132 = F_15 ( V_137 * sizeof( int ) , V_187 ) ;
if ( ! V_131 -> V_132 ) {
F_118 ( ( unsigned long ) V_131 -> V_148 ) ;
F_13 ( V_131 ) ;
V_50 -> V_131 = 0 ;
return - V_35 ;
}
V_131 -> V_161 = V_131 -> V_133 = 0 ;
V_131 -> V_138 = V_137 ;
F_72 ( & V_131 -> V_160 ) ;
F_112 ( V_50 ) ;
return 0 ;
}
const char * F_119 ( T_7 V_189 , int * V_190 )
{
if ( V_189 >= 0x20 && ( V_189 - 0x20 <
F_120 ( V_191 ) ) ) {
* V_190 = V_192 ;
return V_191 [ V_189 - 0x20 ] ;
} else if ( V_189 < F_120 ( V_193 ) ) {
* V_190 = V_194 ;
return V_193 [ V_189 ] ;
} else {
* V_190 = V_195 ;
return L_33 ;
}
}
void F_121 ( struct V_196 * V_197 )
{
struct V_101 * V_50 = F_122 ( V_197 ) ;
unsigned long V_198 ;
F_80 ( & V_50 -> V_129 , V_198 ) ;
F_78 ( 0 , V_50 -> V_102 + V_199 ) ;
F_69 ( V_50 -> V_102 + V_199 ) ;
F_81 ( & V_50 -> V_129 , V_198 ) ;
}
void F_123 ( struct V_196 * V_197 )
{
unsigned long V_198 ;
struct V_101 * V_50 = F_122 ( V_197 ) ;
F_80 ( & V_50 -> V_129 , V_198 ) ;
F_78 ( V_200 , V_50 -> V_102 + V_199 ) ;
F_69 ( V_50 -> V_102 + V_199 ) ;
F_81 ( & V_50 -> V_129 , V_198 ) ;
}
void F_124 ( int V_201 , struct V_202 * V_203 )
{
struct V_101 * V_50 = F_125 ( V_201 ) ;
unsigned long V_198 ;
F_80 ( & V_50 -> V_129 , V_198 ) ;
F_78 ( V_203 -> V_197 , V_50 -> V_102 + V_204 ) ;
F_78 ( V_203 -> V_205 , V_50 -> V_102 + V_206 ) ;
F_78 ( V_203 -> V_207 , V_50 -> V_102 + V_208 ) ;
F_81 ( & V_50 -> V_129 , V_198 ) ;
}
void F_126 ( int V_201 , struct V_202 * V_203 )
{
struct V_101 * V_50 = F_125 ( V_201 ) ;
unsigned long V_198 ;
F_80 ( & V_50 -> V_129 , V_198 ) ;
V_203 -> V_197 = F_69 ( V_50 -> V_102 + V_204 ) ;
V_203 -> V_205 = F_69 ( V_50 -> V_102 + V_206 ) ;
V_203 -> V_207 = F_69 ( V_50 -> V_102 + V_208 ) ;
F_81 ( & V_50 -> V_129 , V_198 ) ;
}
static int F_127 ( struct V_101 * V_50 , int type ,
T_7 V_189 , T_2 V_209 , unsigned long long V_84 )
{
const char * V_210 ;
int V_190 ;
V_210 = F_119 ( V_189 , & V_190 ) ;
if ( V_190 == V_192 )
F_61 ( L_34
L_35
L_36 ,
( V_209 >> 8 ) , F_128 ( V_209 & 0xFF ) ,
F_129 ( V_209 & 0xFF ) , V_84 >> 48 ,
V_189 , V_210 ) ;
else
F_61 ( L_37
L_38
L_39 ,
( type ? L_40 : L_41 ) ,
( V_209 >> 8 ) , F_128 ( V_209 & 0xFF ) ,
F_129 ( V_209 & 0xFF ) , V_84 , V_189 , V_210 ) ;
return 0 ;
}
T_9 F_130 ( int V_201 , void * V_211 )
{
struct V_101 * V_50 = V_211 ;
int V_102 , V_212 ;
T_6 V_213 ;
unsigned long V_198 ;
F_80 ( & V_50 -> V_129 , V_198 ) ;
V_213 = F_69 ( V_50 -> V_102 + V_144 ) ;
if ( V_213 )
F_61 ( L_42 , V_213 ) ;
if ( ! ( V_213 & V_214 ) )
goto V_215;
V_212 = F_131 ( V_213 ) ;
V_102 = F_132 ( V_50 -> V_86 ) ;
while ( 1 ) {
T_7 V_189 ;
T_2 V_209 ;
T_4 V_216 ;
int type ;
T_6 V_197 ;
V_197 = F_69 ( V_50 -> V_102 + V_102 +
V_212 * V_217 + 12 ) ;
if ( ! ( V_197 & V_218 ) )
break;
V_189 = F_133 ( V_197 ) ;
type = F_134 ( V_197 ) ;
V_197 = F_69 ( V_50 -> V_102 + V_102 +
V_212 * V_217 + 8 ) ;
V_209 = F_135 ( V_197 ) ;
V_216 = F_50 ( V_50 -> V_102 + V_102 +
V_212 * V_217 ) ;
V_216 = F_136 ( V_216 ) ;
F_78 ( V_218 , V_50 -> V_102 + V_102 +
V_212 * V_217 + 12 ) ;
F_81 ( & V_50 -> V_129 , V_198 ) ;
F_127 ( V_50 , type , V_189 ,
V_209 , V_216 ) ;
V_212 ++ ;
if ( V_212 >= F_137 ( V_50 -> V_86 ) )
V_212 = 0 ;
F_80 ( & V_50 -> V_129 , V_198 ) ;
}
F_78 ( V_219 | V_214 , V_50 -> V_102 + V_144 ) ;
V_215:
F_81 ( & V_50 -> V_129 , V_198 ) ;
return V_220 ;
}
int F_138 ( struct V_101 * V_50 )
{
int V_201 , V_31 ;
if ( V_50 -> V_201 )
return 0 ;
V_201 = F_139 () ;
if ( ! V_201 ) {
F_61 ( L_43 ) ;
return - V_24 ;
}
F_140 ( V_201 , V_50 ) ;
V_50 -> V_201 = V_201 ;
V_31 = F_141 ( V_201 ) ;
if ( V_31 ) {
F_140 ( V_201 , NULL ) ;
V_50 -> V_201 = 0 ;
F_142 ( V_201 ) ;
return V_31 ;
}
V_31 = F_143 ( V_201 , F_130 , V_221 , V_50 -> V_108 , V_50 ) ;
if ( V_31 )
F_61 ( L_44 ) ;
return V_31 ;
}
int T_1 F_144 ( void )
{
struct V_1 * V_2 ;
F_20 (drhd) {
int V_31 ;
struct V_101 * V_50 = V_2 -> V_50 ;
T_6 V_213 ;
V_31 = F_138 ( V_50 ) ;
if ( V_31 ) {
F_61 ( L_45 ,
( unsigned long long ) V_2 -> V_41 , V_31 ) ;
return - 1 ;
}
F_130 ( V_50 -> V_201 , V_50 ) ;
V_213 = F_69 ( V_50 -> V_102 + V_144 ) ;
F_78 ( V_213 , V_50 -> V_102 + V_144 ) ;
}
return 0 ;
}
int F_145 ( struct V_101 * V_50 )
{
if ( ! F_110 ( V_50 -> V_87 ) )
return - V_186 ;
if ( ! V_50 -> V_131 )
return - V_186 ;
F_108 ( V_50 ) ;
F_112 ( V_50 ) ;
return 0 ;
}
int T_1 F_146 ( void )
{
struct V_71 * V_72 ;
V_72 = (struct V_71 * ) V_68 ;
if ( ! V_72 )
return 0 ;
return V_72 -> V_43 & 0x1 ;
}
