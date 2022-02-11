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
F_28 () ;
V_67 = F_32 ( V_67 ) ;
V_71 = (struct V_70 * ) V_67 ;
if ( ! V_71 )
return - V_73 ;
if ( V_71 -> V_74 < V_75 - 1 ) {
F_7 ( L_12 ) ;
return - V_23 ;
}
F_27 ( L_13 , V_71 -> V_74 + 1 ) ;
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
V_9 = V_9 -> V_12 -> V_76 ;
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
static int V_77 ;
struct V_1 * V_2 , * V_78 ;
int V_30 = - V_73 ;
if ( V_77 )
return V_77 ;
if ( F_42 ( & V_5 ) )
goto V_79;
F_43 (drhd, drhd_n, &dmar_drhd_units, list) {
V_30 = F_17 ( V_2 ) ;
if ( V_30 )
goto V_79;
}
V_30 = F_44 () ;
if ( V_30 )
goto V_79;
V_77 = 1 ;
return 0 ;
V_79:
V_77 = V_30 ;
return V_30 ;
}
int T_1 F_45 ( void )
{
static int V_80 ;
int V_30 ;
if ( V_80 )
return 0 ;
V_80 = 1 ;
V_30 = F_31 () ;
if ( V_30 ) {
if ( V_30 != - V_73 )
F_27 ( L_16 ) ;
return V_30 ;
}
if ( F_42 ( & V_5 ) ) {
F_27 ( L_17 ) ;
return - V_73 ;
}
return 0 ;
}
static void F_46 ( T_4 V_81 , const char * V_82 )
{
F_47 (
1 , V_50 ,
L_18
L_6 ,
V_81 , V_82 ,
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
void T_5 * V_81 ;
T_4 V_83 , V_84 ;
V_2 = ( void * ) V_72 ;
if ( ! V_2 -> V_41 ) {
F_46 ( 0 , L_19 ) ;
goto V_85;
}
V_81 = F_49 ( V_2 -> V_41 , V_86 ) ;
if ( ! V_81 ) {
F_50 ( L_20 , V_2 -> V_41 ) ;
goto V_85;
}
V_83 = F_51 ( V_81 + V_87 ) ;
V_84 = F_51 ( V_81 + V_88 ) ;
F_52 ( V_81 , V_86 ) ;
if ( V_83 == ( V_89 ) - 1 && V_84 == ( V_89 ) - 1 ) {
F_46 ( V_2 -> V_41 ,
L_21 ) ;
goto V_85;
}
}
V_72 = ( ( void * ) V_72 + V_72 -> V_17 ) ;
}
return 1 ;
V_85:
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
if ( V_30 && V_90 && V_91 &&
V_71 -> V_42 & 0x1 )
F_27 ( L_22 ) ;
if ( V_30 && ! V_92 && ! V_93 && ! V_94 ) {
V_93 = 1 ;
F_54 () ;
}
#ifdef F_55
if ( V_30 )
V_95 . V_49 . V_96 = V_97 ;
#endif
}
F_56 ( V_67 , V_68 ) ;
V_67 = NULL ;
return V_30 ? 1 : - V_73 ;
}
static void F_57 ( struct V_98 * V_49 )
{
F_58 ( V_49 -> V_99 ) ;
F_59 ( V_49 -> V_100 , V_49 -> V_101 ) ;
}
static int F_60 ( struct V_98 * V_49 , T_4 V_102 )
{
int V_103 , V_104 = 0 ;
V_49 -> V_100 = V_102 ;
V_49 -> V_101 = V_86 ;
if ( ! F_61 ( V_49 -> V_100 , V_49 -> V_101 , V_49 -> V_105 ) ) {
F_62 ( L_23 ) ;
V_104 = - V_106 ;
goto V_107;
}
V_49 -> V_99 = F_63 ( V_49 -> V_100 , V_49 -> V_101 ) ;
if ( ! V_49 -> V_99 ) {
F_62 ( L_24 ) ;
V_104 = - V_34 ;
goto V_108;
}
V_49 -> V_83 = F_51 ( V_49 -> V_99 + V_87 ) ;
V_49 -> V_84 = F_51 ( V_49 -> V_99 + V_88 ) ;
if ( V_49 -> V_83 == ( V_89 ) - 1 && V_49 -> V_84 == ( V_89 ) - 1 ) {
V_104 = - V_23 ;
F_46 ( V_102 , L_21 ) ;
goto V_109;
}
V_103 = F_64 ( int , F_65 ( V_49 -> V_84 ) ,
F_66 ( V_49 -> V_83 ) ) ;
V_103 = F_67 ( V_103 ) ;
if ( V_103 > V_49 -> V_101 ) {
F_58 ( V_49 -> V_99 ) ;
F_59 ( V_49 -> V_100 , V_49 -> V_101 ) ;
V_49 -> V_101 = V_103 ;
if ( ! F_61 ( V_49 -> V_100 , V_49 -> V_101 ,
V_49 -> V_105 ) ) {
F_62 ( L_23 ) ;
V_104 = - V_106 ;
goto V_107;
}
V_49 -> V_99 = F_63 ( V_49 -> V_100 , V_49 -> V_101 ) ;
if ( ! V_49 -> V_99 ) {
F_62 ( L_24 ) ;
V_104 = - V_34 ;
goto V_108;
}
}
V_104 = 0 ;
goto V_107;
V_109:
F_58 ( V_49 -> V_99 ) ;
V_108:
F_59 ( V_49 -> V_100 , V_49 -> V_101 ) ;
V_107:
return V_104 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_98 * V_49 ;
T_6 V_110 , V_111 ;
static int V_112 = 0 ;
int V_113 = 0 ;
int V_114 = 0 ;
int V_104 ;
if ( ! V_2 -> V_40 ) {
F_46 ( 0 , L_19 ) ;
return - V_23 ;
}
V_49 = F_15 ( sizeof( * V_49 ) , V_33 ) ;
if ( ! V_49 )
return - V_34 ;
V_49 -> V_115 = V_112 ++ ;
sprintf ( V_49 -> V_105 , L_25 , V_49 -> V_115 ) ;
V_104 = F_60 ( V_49 , V_2 -> V_40 ) ;
if ( V_104 ) {
F_62 ( L_26 , V_49 -> V_105 ) ;
goto error;
}
V_104 = - V_23 ;
V_113 = F_68 ( V_49 ) ;
if ( V_113 < 0 ) {
F_62 ( L_27 ,
V_49 -> V_115 ) ;
goto V_116;
}
V_114 = F_69 ( V_49 ) ;
if ( V_114 < 0 ) {
F_62 ( L_28 ,
V_49 -> V_115 ) ;
goto V_116;
}
V_49 -> V_113 = V_113 ;
V_49 -> V_114 = V_114 ;
V_49 -> V_47 = - 1 ;
V_110 = F_70 ( V_49 -> V_99 + V_117 ) ;
F_27 ( L_29 ,
V_49 -> V_115 ,
( unsigned long long ) V_2 -> V_40 ,
F_71 ( V_110 ) , F_72 ( V_110 ) ,
( unsigned long long ) V_49 -> V_83 ,
( unsigned long long ) V_49 -> V_84 ) ;
V_111 = F_70 ( V_49 -> V_99 + V_118 ) ;
if ( V_111 & V_119 )
V_49 -> V_120 |= V_121 ;
if ( V_111 & V_122 )
V_49 -> V_120 |= V_123 ;
if ( V_111 & V_124 )
V_49 -> V_120 |= V_125 ;
F_73 ( & V_49 -> V_126 ) ;
V_2 -> V_49 = V_49 ;
return 0 ;
V_116:
F_57 ( V_49 ) ;
error:
F_13 ( V_49 ) ;
return V_104 ;
}
void F_74 ( struct V_98 * V_49 )
{
if ( ! V_49 )
return;
F_75 ( V_49 ) ;
if ( V_49 -> V_99 )
F_57 ( V_49 ) ;
F_13 ( V_49 ) ;
}
static inline void F_76 ( struct V_127 * V_128 )
{
while ( V_128 -> V_129 [ V_128 -> V_130 ] == V_131 ||
V_128 -> V_129 [ V_128 -> V_130 ] == V_132 ) {
V_128 -> V_129 [ V_128 -> V_130 ] = V_133 ;
V_128 -> V_130 = ( V_128 -> V_130 + 1 ) % V_134 ;
V_128 -> V_135 ++ ;
}
}
static int F_77 ( struct V_98 * V_49 , int V_29 )
{
T_6 V_136 ;
int V_137 , V_138 ;
struct V_127 * V_128 = V_49 -> V_128 ;
int V_139 = ( V_29 + 1 ) % V_134 ;
if ( V_128 -> V_129 [ V_139 ] == V_132 )
return - V_140 ;
V_136 = F_70 ( V_49 -> V_99 + V_141 ) ;
if ( V_136 & V_142 ) {
V_137 = F_70 ( V_49 -> V_99 + V_143 ) ;
if ( ( V_137 >> V_144 ) == V_29 ) {
F_62 ( L_30
L_31 ,
( unsigned long long ) V_128 -> V_145 [ V_29 ] . V_146 ,
( unsigned long long ) V_128 -> V_145 [ V_29 ] . V_147 ) ;
memcpy ( & V_128 -> V_145 [ V_29 ] , & V_128 -> V_145 [ V_139 ] ,
sizeof( struct V_148 ) ) ;
F_78 ( V_49 , & V_128 -> V_145 [ V_29 ] ,
sizeof( struct V_148 ) ) ;
F_79 ( V_142 , V_49 -> V_99 + V_141 ) ;
return - V_23 ;
}
}
if ( V_136 & V_149 ) {
V_137 = F_70 ( V_49 -> V_99 + V_143 ) ;
V_137 = ( ( V_137 >> V_144 ) - 1 + V_134 ) % V_134 ;
V_137 |= 1 ;
V_138 = F_70 ( V_49 -> V_99 + V_150 ) ;
V_138 = ( ( V_138 >> V_144 ) - 1 + V_134 ) % V_134 ;
F_79 ( V_149 , V_49 -> V_99 + V_141 ) ;
do {
if ( V_128 -> V_129 [ V_137 ] == V_151 )
V_128 -> V_129 [ V_137 ] = V_132 ;
V_137 = ( V_137 - 2 + V_134 ) % V_134 ;
} while ( V_137 != V_138 );
if ( V_128 -> V_129 [ V_139 ] == V_132 )
return - V_140 ;
}
if ( V_136 & V_152 )
F_79 ( V_152 , V_49 -> V_99 + V_141 ) ;
return 0 ;
}
int F_80 ( struct V_148 * V_145 , struct V_98 * V_49 )
{
int V_153 ;
struct V_127 * V_128 = V_49 -> V_128 ;
struct V_148 * V_154 , V_155 ;
int V_139 , V_29 ;
unsigned long V_42 ;
if ( ! V_128 )
return 0 ;
V_154 = V_128 -> V_145 ;
V_156:
V_153 = 0 ;
F_81 ( & V_128 -> V_157 , V_42 ) ;
while ( V_128 -> V_135 < 3 ) {
F_82 ( & V_128 -> V_157 , V_42 ) ;
F_83 () ;
F_81 ( & V_128 -> V_157 , V_42 ) ;
}
V_29 = V_128 -> V_158 ;
V_139 = ( V_29 + 1 ) % V_134 ;
V_128 -> V_129 [ V_29 ] = V_128 -> V_129 [ V_139 ] = V_151 ;
V_154 [ V_29 ] = * V_145 ;
V_155 . V_146 = F_84 ( V_131 ) |
V_159 | V_160 ;
V_155 . V_147 = F_85 ( & V_128 -> V_129 [ V_139 ] ) ;
V_154 [ V_139 ] = V_155 ;
F_78 ( V_49 , & V_154 [ V_29 ] , sizeof( struct V_148 ) ) ;
F_78 ( V_49 , & V_154 [ V_139 ] , sizeof( struct V_148 ) ) ;
V_128 -> V_158 = ( V_128 -> V_158 + 2 ) % V_134 ;
V_128 -> V_135 -= 2 ;
F_79 ( V_128 -> V_158 << V_144 , V_49 -> V_99 + V_150 ) ;
while ( V_128 -> V_129 [ V_139 ] != V_131 ) {
V_153 = F_77 ( V_49 , V_29 ) ;
if ( V_153 )
break;
F_86 ( & V_128 -> V_157 ) ;
F_83 () ;
F_87 ( & V_128 -> V_157 ) ;
}
V_128 -> V_129 [ V_29 ] = V_131 ;
F_76 ( V_128 ) ;
F_82 ( & V_128 -> V_157 , V_42 ) ;
if ( V_153 == - V_140 )
goto V_156;
return V_153 ;
}
void F_88 ( struct V_98 * V_49 )
{
struct V_148 V_145 ;
V_145 . V_146 = V_161 ;
V_145 . V_147 = 0 ;
F_80 ( & V_145 , V_49 ) ;
}
void F_89 ( struct V_98 * V_49 , T_2 V_162 , T_2 V_163 , T_7 V_164 ,
T_4 type )
{
struct V_148 V_145 ;
V_145 . V_146 = F_90 ( V_164 ) | F_91 ( V_163 ) | F_92 ( V_162 )
| F_93 ( type ) | V_165 ;
V_145 . V_147 = 0 ;
F_80 ( & V_145 , V_49 ) ;
}
void F_94 ( struct V_98 * V_49 , T_2 V_162 , T_4 V_81 ,
unsigned int V_166 , T_4 type )
{
T_7 V_167 = 0 , V_168 = 0 ;
struct V_148 V_145 ;
int V_169 = 0 ;
if ( F_95 ( V_49 -> V_83 ) )
V_167 = 1 ;
if ( F_96 ( V_49 -> V_83 ) )
V_168 = 1 ;
V_145 . V_146 = F_97 ( V_162 ) | F_98 ( V_168 ) | F_99 ( V_167 )
| F_100 ( type ) | V_170 ;
V_145 . V_147 = F_101 ( V_81 ) | F_102 ( V_169 )
| F_103 ( V_166 ) ;
F_80 ( & V_145 , V_49 ) ;
}
void F_104 ( struct V_98 * V_49 , T_2 V_163 , T_2 V_171 ,
T_4 V_81 , unsigned V_172 )
{
struct V_148 V_145 ;
if ( V_172 ) {
F_105 ( V_81 & ( ( 1 << ( V_173 + V_172 ) ) - 1 ) ) ;
V_81 |= ( 1 << ( V_173 + V_172 - 1 ) ) - 1 ;
V_145 . V_147 = F_106 ( V_81 ) | V_174 ;
} else
V_145 . V_147 = F_106 ( V_81 ) ;
if ( V_171 >= V_175 )
V_171 = 0 ;
V_145 . V_146 = F_107 ( V_163 ) | F_108 ( V_171 ) |
V_176 ;
F_80 ( & V_145 , V_49 ) ;
}
void F_109 ( struct V_98 * V_49 )
{
unsigned long V_42 ;
T_6 V_111 ;
T_8 V_177 = F_110 () ;
if ( ! F_111 ( V_49 -> V_84 ) )
return;
F_81 ( & V_49 -> V_126 , V_42 ) ;
V_111 = F_51 ( V_49 -> V_99 + V_118 ) ;
if ( ! ( V_111 & V_124 ) )
goto V_25;
while ( ( F_70 ( V_49 -> V_99 + V_150 ) !=
F_70 ( V_49 -> V_99 + V_143 ) ) &&
( V_178 > ( F_110 () - V_177 ) ) )
F_83 () ;
V_49 -> V_120 &= ~ V_125 ;
F_79 ( V_49 -> V_120 , V_49 -> V_99 + V_179 ) ;
F_112 ( V_49 , V_118 , F_70 ,
! ( V_111 & V_124 ) , V_111 ) ;
V_25:
F_82 ( & V_49 -> V_126 , V_42 ) ;
}
static void F_113 ( struct V_98 * V_49 )
{
T_6 V_111 ;
unsigned long V_42 ;
struct V_127 * V_128 = V_49 -> V_128 ;
V_128 -> V_158 = V_128 -> V_130 = 0 ;
V_128 -> V_135 = V_134 ;
F_81 ( & V_49 -> V_126 , V_42 ) ;
F_79 ( 0 , V_49 -> V_99 + V_150 ) ;
F_114 ( V_49 -> V_99 + V_180 , F_85 ( V_128 -> V_145 ) ) ;
V_49 -> V_120 |= V_125 ;
F_79 ( V_49 -> V_120 , V_49 -> V_99 + V_179 ) ;
F_112 ( V_49 , V_118 , F_70 , ( V_111 & V_124 ) , V_111 ) ;
F_82 ( & V_49 -> V_126 , V_42 ) ;
}
int F_115 ( struct V_98 * V_49 )
{
struct V_127 * V_128 ;
struct V_181 * V_182 ;
if ( ! F_111 ( V_49 -> V_84 ) )
return - V_183 ;
if ( V_49 -> V_128 )
return 0 ;
V_49 -> V_128 = F_116 ( sizeof( * V_128 ) , V_184 ) ;
if ( ! V_49 -> V_128 )
return - V_34 ;
V_128 = V_49 -> V_128 ;
V_182 = F_117 ( V_49 -> V_47 , V_184 | V_185 , 0 ) ;
if ( ! V_182 ) {
F_13 ( V_128 ) ;
V_49 -> V_128 = 0 ;
return - V_34 ;
}
V_128 -> V_145 = F_118 ( V_182 ) ;
V_128 -> V_129 = F_15 ( V_134 * sizeof( int ) , V_184 ) ;
if ( ! V_128 -> V_129 ) {
F_119 ( ( unsigned long ) V_128 -> V_145 ) ;
F_13 ( V_128 ) ;
V_49 -> V_128 = 0 ;
return - V_34 ;
}
V_128 -> V_158 = V_128 -> V_130 = 0 ;
V_128 -> V_135 = V_134 ;
F_73 ( & V_128 -> V_157 ) ;
F_113 ( V_49 ) ;
return 0 ;
}
const char * F_120 ( T_7 V_186 , int * V_187 )
{
if ( V_186 >= 0x20 && ( V_186 - 0x20 <
F_121 ( V_188 ) ) ) {
* V_187 = V_189 ;
return V_188 [ V_186 - 0x20 ] ;
} else if ( V_186 < F_121 ( V_190 ) ) {
* V_187 = V_191 ;
return V_190 [ V_186 ] ;
} else {
* V_187 = V_192 ;
return L_32 ;
}
}
void F_122 ( struct V_193 * V_194 )
{
struct V_98 * V_49 = F_123 ( V_194 ) ;
unsigned long V_195 ;
F_81 ( & V_49 -> V_126 , V_195 ) ;
F_79 ( 0 , V_49 -> V_99 + V_196 ) ;
F_70 ( V_49 -> V_99 + V_196 ) ;
F_82 ( & V_49 -> V_126 , V_195 ) ;
}
void F_124 ( struct V_193 * V_194 )
{
unsigned long V_195 ;
struct V_98 * V_49 = F_123 ( V_194 ) ;
F_81 ( & V_49 -> V_126 , V_195 ) ;
F_79 ( V_197 , V_49 -> V_99 + V_196 ) ;
F_70 ( V_49 -> V_99 + V_196 ) ;
F_82 ( & V_49 -> V_126 , V_195 ) ;
}
void F_125 ( int V_198 , struct V_199 * V_200 )
{
struct V_98 * V_49 = F_126 ( V_198 ) ;
unsigned long V_195 ;
F_81 ( & V_49 -> V_126 , V_195 ) ;
F_79 ( V_200 -> V_194 , V_49 -> V_99 + V_201 ) ;
F_79 ( V_200 -> V_202 , V_49 -> V_99 + V_203 ) ;
F_79 ( V_200 -> V_204 , V_49 -> V_99 + V_205 ) ;
F_82 ( & V_49 -> V_126 , V_195 ) ;
}
void F_127 ( int V_198 , struct V_199 * V_200 )
{
struct V_98 * V_49 = F_126 ( V_198 ) ;
unsigned long V_195 ;
F_81 ( & V_49 -> V_126 , V_195 ) ;
V_200 -> V_194 = F_70 ( V_49 -> V_99 + V_201 ) ;
V_200 -> V_202 = F_70 ( V_49 -> V_99 + V_203 ) ;
V_200 -> V_204 = F_70 ( V_49 -> V_99 + V_205 ) ;
F_82 ( & V_49 -> V_126 , V_195 ) ;
}
static int F_128 ( struct V_98 * V_49 , int type ,
T_7 V_186 , T_2 V_206 , unsigned long long V_81 )
{
const char * V_207 ;
int V_187 ;
V_207 = F_120 ( V_186 , & V_187 ) ;
if ( V_187 == V_189 )
F_62 ( L_33
L_34
L_35 ,
( V_206 >> 8 ) , F_129 ( V_206 & 0xFF ) ,
F_130 ( V_206 & 0xFF ) , V_81 >> 48 ,
V_186 , V_207 ) ;
else
F_62 ( L_36
L_37
L_38 ,
( type ? L_39 : L_40 ) ,
( V_206 >> 8 ) , F_129 ( V_206 & 0xFF ) ,
F_130 ( V_206 & 0xFF ) , V_81 , V_186 , V_207 ) ;
return 0 ;
}
T_9 F_131 ( int V_198 , void * V_208 )
{
struct V_98 * V_49 = V_208 ;
int V_99 , V_209 ;
T_6 V_210 ;
unsigned long V_195 ;
F_81 ( & V_49 -> V_126 , V_195 ) ;
V_210 = F_70 ( V_49 -> V_99 + V_141 ) ;
if ( V_210 )
F_62 ( L_41 , V_210 ) ;
if ( ! ( V_210 & V_211 ) )
goto V_212;
V_209 = F_132 ( V_210 ) ;
V_99 = F_133 ( V_49 -> V_83 ) ;
while ( 1 ) {
T_7 V_186 ;
T_2 V_206 ;
T_4 V_213 ;
int type ;
T_6 V_194 ;
V_194 = F_70 ( V_49 -> V_99 + V_99 +
V_209 * V_214 + 12 ) ;
if ( ! ( V_194 & V_215 ) )
break;
V_186 = F_134 ( V_194 ) ;
type = F_135 ( V_194 ) ;
V_194 = F_70 ( V_49 -> V_99 + V_99 +
V_209 * V_214 + 8 ) ;
V_206 = F_136 ( V_194 ) ;
V_213 = F_51 ( V_49 -> V_99 + V_99 +
V_209 * V_214 ) ;
V_213 = F_137 ( V_213 ) ;
F_79 ( V_215 , V_49 -> V_99 + V_99 +
V_209 * V_214 + 12 ) ;
F_82 ( & V_49 -> V_126 , V_195 ) ;
F_128 ( V_49 , type , V_186 ,
V_206 , V_213 ) ;
V_209 ++ ;
if ( V_209 >= F_138 ( V_49 -> V_83 ) )
V_209 = 0 ;
F_81 ( & V_49 -> V_126 , V_195 ) ;
}
F_79 ( V_216 | V_211 , V_49 -> V_99 + V_141 ) ;
V_212:
F_82 ( & V_49 -> V_126 , V_195 ) ;
return V_217 ;
}
int F_139 ( struct V_98 * V_49 )
{
int V_198 , V_30 ;
if ( V_49 -> V_198 )
return 0 ;
V_198 = F_140 () ;
if ( ! V_198 ) {
F_62 ( L_42 ) ;
return - V_23 ;
}
F_141 ( V_198 , V_49 ) ;
V_49 -> V_198 = V_198 ;
V_30 = F_142 ( V_198 ) ;
if ( V_30 ) {
F_141 ( V_198 , NULL ) ;
V_49 -> V_198 = 0 ;
F_143 ( V_198 ) ;
return V_30 ;
}
V_30 = F_144 ( V_198 , F_131 , V_218 , V_49 -> V_105 , V_49 ) ;
if ( V_30 )
F_62 ( L_43 ) ;
return V_30 ;
}
int T_1 F_145 ( void )
{
struct V_1 * V_2 ;
F_20 (drhd) {
int V_30 ;
struct V_98 * V_49 = V_2 -> V_49 ;
T_6 V_210 ;
V_30 = F_139 ( V_49 ) ;
if ( V_30 ) {
F_62 ( L_44 ,
( unsigned long long ) V_2 -> V_40 , V_30 ) ;
return - 1 ;
}
F_131 ( V_49 -> V_198 , V_49 ) ;
V_210 = F_70 ( V_49 -> V_99 + V_141 ) ;
F_79 ( V_210 , V_49 -> V_99 + V_141 ) ;
}
return 0 ;
}
int F_146 ( struct V_98 * V_49 )
{
if ( ! F_111 ( V_49 -> V_84 ) )
return - V_183 ;
if ( ! V_49 -> V_128 )
return - V_183 ;
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
