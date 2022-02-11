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
else if ( V_7 -> V_20 != V_31 ) {
F_7 ( L_4 ) ;
}
V_24 += V_7 -> V_17 ;
}
if ( * V_26 == 0 )
return 0 ;
* V_27 = F_12 ( * V_26 , sizeof( struct V_8 * ) , V_32 ) ;
if ( ! * V_27 )
return - V_33 ;
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
F_14 ( struct V_34 * V_35 )
{
struct V_36 * V_2 ;
struct V_1 * V_37 ;
int V_30 = 0 ;
V_2 = (struct V_36 * ) V_35 ;
V_37 = F_15 ( sizeof( * V_37 ) , V_32 ) ;
if ( ! V_37 )
return - V_33 ;
V_37 -> V_38 = V_35 ;
V_37 -> V_39 = V_2 -> V_40 ;
V_37 -> V_10 = V_2 -> V_10 ;
V_37 -> V_3 = V_2 -> V_41 & 0x1 ;
V_30 = F_16 ( V_37 ) ;
if ( V_30 ) {
F_13 ( V_37 ) ;
return V_30 ;
}
F_1 ( V_37 ) ;
return 0 ;
}
static int T_1 F_17 ( struct V_1 * V_37 )
{
struct V_36 * V_2 ;
int V_30 = 0 ;
V_2 = (struct V_36 * ) V_37 -> V_38 ;
if ( V_37 -> V_3 )
return 0 ;
V_30 = F_11 ( ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_35 . V_17 ,
& V_37 -> V_42 , & V_37 -> V_27 ,
V_2 -> V_10 ) ;
if ( V_30 ) {
F_18 ( & V_37 -> V_4 ) ;
F_13 ( V_37 ) ;
}
return V_30 ;
}
static int T_1
F_19 ( struct V_34 * V_35 )
{
struct V_43 * V_44 ;
struct V_1 * V_2 ;
V_44 = (struct V_43 * ) V_35 ;
F_20 (drhd) {
if ( V_2 -> V_39 == V_44 -> V_45 ) {
int V_46 = F_21 ( V_44 -> V_47 ) ;
if ( ! F_22 ( V_46 ) )
V_46 = - 1 ;
V_2 -> V_48 -> V_46 = V_46 ;
return 0 ;
}
}
F_23 (
1 , V_49 ,
L_5
L_6 ,
V_2 -> V_39 ,
F_24 ( V_50 ) ,
F_24 ( V_51 ) ,
F_24 ( V_52 ) ) ;
return 0 ;
}
static void T_1
F_25 ( struct V_34 * V_35 )
{
struct V_36 * V_2 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_43 * V_44 ;
switch ( V_35 -> type ) {
case V_57 :
V_2 = F_26 ( V_35 , struct V_36 ,
V_35 ) ;
F_27 ( L_7 ,
( unsigned long long ) V_2 -> V_40 , V_2 -> V_41 ) ;
break;
case V_58 :
V_54 = F_26 ( V_35 , struct V_53 ,
V_35 ) ;
F_27 ( L_8 ,
( unsigned long long ) V_54 -> V_45 ,
( unsigned long long ) V_54 -> V_59 ) ;
break;
case V_60 :
V_56 = F_26 ( V_35 , struct V_55 , V_35 ) ;
F_27 ( L_9 , V_56 -> V_41 ) ;
break;
case V_61 :
V_44 = F_26 ( V_35 , struct V_43 , V_35 ) ;
F_27 ( L_10 ,
( unsigned long long ) V_44 -> V_45 ,
V_44 -> V_47 ) ;
break;
}
}
static int T_1 F_28 ( void )
{
T_3 V_62 = V_63 ;
V_62 = F_29 ( V_64 , 0 ,
(struct V_65 * * ) & V_66 ,
& V_67 ) ;
if ( F_30 ( V_62 ) && ! V_66 ) {
F_7 ( L_11 ) ;
V_62 = V_68 ;
}
return ( F_30 ( V_62 ) ? 1 : 0 ) ;
}
static int T_1
F_31 ( void )
{
struct V_69 * V_70 ;
struct V_34 * V_71 ;
int V_30 = 0 ;
F_28 () ;
V_66 = F_32 ( V_66 ) ;
V_70 = (struct V_69 * ) V_66 ;
if ( ! V_70 )
return - V_72 ;
if ( V_70 -> V_73 < V_74 - 1 ) {
F_7 ( L_12 ) ;
return - V_23 ;
}
F_27 ( L_13 , V_70 -> V_73 + 1 ) ;
V_71 = (struct V_34 * ) ( V_70 + 1 ) ;
while ( ( ( unsigned long ) V_71 ) <
( ( ( unsigned long ) V_70 ) + V_66 -> V_17 ) ) {
if ( V_71 -> V_17 == 0 ) {
F_7 ( L_14 ) ;
V_30 = - V_23 ;
break;
}
F_25 ( V_71 ) ;
switch ( V_71 -> type ) {
case V_57 :
V_30 = F_14 ( V_71 ) ;
break;
case V_58 :
V_30 = F_33 ( V_71 ) ;
break;
case V_60 :
V_30 = F_34 ( V_71 ) ;
break;
case V_61 :
#ifdef F_35
V_30 = F_19 ( V_71 ) ;
#endif
break;
default:
F_7 ( L_15 ,
V_71 -> type ) ;
V_30 = 0 ;
break;
}
if ( V_30 )
break;
V_71 = ( ( void * ) V_71 + V_71 -> V_17 ) ;
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
V_9 = V_9 -> V_12 -> V_75 ;
}
return 0 ;
}
struct V_1 *
F_37 ( struct V_8 * V_9 )
{
struct V_1 * V_37 = NULL ;
struct V_36 * V_2 ;
V_9 = F_38 ( V_9 ) ;
F_39 (dmaru, &dmar_drhd_units, list) {
V_2 = F_26 ( V_37 -> V_38 ,
struct V_36 ,
V_35 ) ;
if ( V_37 -> V_3 &&
V_2 -> V_10 == F_40 ( V_9 -> V_12 ) )
return V_37 ;
if ( F_36 ( V_37 -> V_27 ,
V_37 -> V_42 , V_9 ) )
return V_37 ;
}
return NULL ;
}
int T_1 F_41 ( void )
{
static int V_76 ;
struct V_1 * V_2 , * V_77 ;
int V_30 = - V_72 ;
if ( V_76 )
return V_76 ;
if ( F_42 ( & V_5 ) )
goto V_78;
F_43 (drhd, drhd_n, &dmar_drhd_units, list) {
V_30 = F_17 ( V_2 ) ;
if ( V_30 )
goto V_78;
}
V_30 = F_44 () ;
if ( V_30 )
goto V_78;
V_76 = 1 ;
return 0 ;
V_78:
V_76 = V_30 ;
return V_30 ;
}
int T_1 F_45 ( void )
{
static int V_79 ;
int V_30 ;
if ( V_79 )
return 0 ;
V_79 = 1 ;
V_30 = F_31 () ;
if ( V_30 ) {
if ( V_30 != - V_72 )
F_27 ( L_16 ) ;
return V_30 ;
}
if ( F_42 ( & V_5 ) ) {
F_27 ( L_17 ) ;
return - V_72 ;
}
return 0 ;
}
static void F_46 ( T_4 V_80 , const char * V_81 )
{
F_47 (
1 , V_49 ,
L_18
L_6 ,
V_80 , V_81 ,
F_24 ( V_50 ) ,
F_24 ( V_51 ) ,
F_24 ( V_52 ) ) ;
}
int T_1 F_48 ( void )
{
struct V_69 * V_70 ;
struct V_34 * V_71 ;
struct V_36 * V_2 ;
V_70 = (struct V_69 * ) V_66 ;
V_71 = (struct V_34 * ) ( V_70 + 1 ) ;
while ( ( ( unsigned long ) V_71 ) <
( ( ( unsigned long ) V_70 ) + V_66 -> V_17 ) ) {
if ( V_71 -> V_17 == 0 ) {
F_7 ( L_14 ) ;
return 0 ;
}
if ( V_71 -> type == V_57 ) {
void T_5 * V_80 ;
T_4 V_82 , V_83 ;
V_2 = ( void * ) V_71 ;
if ( ! V_2 -> V_40 ) {
F_46 ( 0 , L_19 ) ;
goto V_84;
}
V_80 = F_49 ( V_2 -> V_40 , V_85 ) ;
if ( ! V_80 ) {
F_50 ( L_20 , V_2 -> V_40 ) ;
goto V_84;
}
V_82 = F_51 ( V_80 + V_86 ) ;
V_83 = F_51 ( V_80 + V_87 ) ;
F_52 ( V_80 , V_85 ) ;
if ( V_82 == ( V_88 ) - 1 && V_83 == ( V_88 ) - 1 ) {
F_46 ( V_2 -> V_40 ,
L_21 ) ;
goto V_84;
}
}
V_71 = ( ( void * ) V_71 + V_71 -> V_17 ) ;
}
return 1 ;
V_84:
return 0 ;
}
int T_1 F_53 ( void )
{
int V_30 ;
V_30 = F_28 () ;
if ( V_30 )
V_30 = F_48 () ;
{
struct V_69 * V_70 ;
V_70 = (struct V_69 * ) V_66 ;
if ( V_30 && V_89 && V_90 &&
V_70 -> V_41 & 0x1 )
F_27 ( L_22 ) ;
if ( V_30 && ! V_91 && ! V_92 && ! V_93 ) {
V_92 = 1 ;
F_54 () ;
}
#ifdef F_55
if ( V_30 )
V_94 . V_48 . V_95 = V_96 ;
#endif
}
F_56 ( V_66 , V_67 ) ;
V_66 = NULL ;
return V_30 ? 1 : - V_72 ;
}
static void F_57 ( struct V_97 * V_48 )
{
F_58 ( V_48 -> V_98 ) ;
F_59 ( V_48 -> V_99 , V_48 -> V_100 ) ;
}
static int F_60 ( struct V_97 * V_48 , T_4 V_101 )
{
int V_102 , V_103 = 0 ;
V_48 -> V_99 = V_101 ;
V_48 -> V_100 = V_85 ;
if ( ! F_61 ( V_48 -> V_99 , V_48 -> V_100 , V_48 -> V_104 ) ) {
F_62 ( L_23 ) ;
V_103 = - V_105 ;
goto V_106;
}
V_48 -> V_98 = F_63 ( V_48 -> V_99 , V_48 -> V_100 ) ;
if ( ! V_48 -> V_98 ) {
F_62 ( L_24 ) ;
V_103 = - V_33 ;
goto V_107;
}
V_48 -> V_82 = F_51 ( V_48 -> V_98 + V_86 ) ;
V_48 -> V_83 = F_51 ( V_48 -> V_98 + V_87 ) ;
if ( V_48 -> V_82 == ( V_88 ) - 1 && V_48 -> V_83 == ( V_88 ) - 1 ) {
V_103 = - V_23 ;
F_46 ( V_101 , L_21 ) ;
goto V_108;
}
V_102 = F_64 ( int , F_65 ( V_48 -> V_83 ) ,
F_66 ( V_48 -> V_82 ) ) ;
V_102 = F_67 ( V_102 ) ;
if ( V_102 > V_48 -> V_100 ) {
F_58 ( V_48 -> V_98 ) ;
F_59 ( V_48 -> V_99 , V_48 -> V_100 ) ;
V_48 -> V_100 = V_102 ;
if ( ! F_61 ( V_48 -> V_99 , V_48 -> V_100 ,
V_48 -> V_104 ) ) {
F_62 ( L_23 ) ;
V_103 = - V_105 ;
goto V_106;
}
V_48 -> V_98 = F_63 ( V_48 -> V_99 , V_48 -> V_100 ) ;
if ( ! V_48 -> V_98 ) {
F_62 ( L_24 ) ;
V_103 = - V_33 ;
goto V_107;
}
}
V_103 = 0 ;
goto V_106;
V_108:
F_58 ( V_48 -> V_98 ) ;
V_107:
F_59 ( V_48 -> V_99 , V_48 -> V_100 ) ;
V_106:
return V_103 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_97 * V_48 ;
T_6 V_109 ;
static int V_110 = 0 ;
int V_111 = 0 ;
int V_112 = 0 ;
int V_103 ;
if ( ! V_2 -> V_39 ) {
F_46 ( 0 , L_19 ) ;
return - V_23 ;
}
V_48 = F_15 ( sizeof( * V_48 ) , V_32 ) ;
if ( ! V_48 )
return - V_33 ;
V_48 -> V_113 = V_110 ++ ;
sprintf ( V_48 -> V_104 , L_25 , V_48 -> V_113 ) ;
V_103 = F_60 ( V_48 , V_2 -> V_39 ) ;
if ( V_103 ) {
F_62 ( L_26 , V_48 -> V_104 ) ;
goto error;
}
V_103 = - V_23 ;
V_111 = F_68 ( V_48 ) ;
if ( V_111 < 0 ) {
F_62 ( L_27 ,
V_48 -> V_113 ) ;
goto V_114;
}
V_112 = F_69 ( V_48 ) ;
if ( V_112 < 0 ) {
F_62 ( L_28 ,
V_48 -> V_113 ) ;
goto V_114;
}
V_48 -> V_111 = V_111 ;
V_48 -> V_112 = V_112 ;
V_48 -> V_46 = - 1 ;
V_109 = F_70 ( V_48 -> V_98 + V_115 ) ;
F_27 ( L_29 ,
V_48 -> V_113 ,
( unsigned long long ) V_2 -> V_39 ,
F_71 ( V_109 ) , F_72 ( V_109 ) ,
( unsigned long long ) V_48 -> V_82 ,
( unsigned long long ) V_48 -> V_83 ) ;
F_73 ( & V_48 -> V_116 ) ;
V_2 -> V_48 = V_48 ;
return 0 ;
V_114:
F_57 ( V_48 ) ;
error:
F_13 ( V_48 ) ;
return V_103 ;
}
void F_74 ( struct V_97 * V_48 )
{
if ( ! V_48 )
return;
F_75 ( V_48 ) ;
if ( V_48 -> V_98 )
F_57 ( V_48 ) ;
F_13 ( V_48 ) ;
}
static inline void F_76 ( struct V_117 * V_118 )
{
while ( V_118 -> V_119 [ V_118 -> V_120 ] == V_121 ||
V_118 -> V_119 [ V_118 -> V_120 ] == V_122 ) {
V_118 -> V_119 [ V_118 -> V_120 ] = V_123 ;
V_118 -> V_120 = ( V_118 -> V_120 + 1 ) % V_124 ;
V_118 -> V_125 ++ ;
}
}
static int F_77 ( struct V_97 * V_48 , int V_29 )
{
T_6 V_126 ;
int V_127 , V_128 ;
struct V_117 * V_118 = V_48 -> V_118 ;
int V_129 = ( V_29 + 1 ) % V_124 ;
if ( V_118 -> V_119 [ V_129 ] == V_122 )
return - V_130 ;
V_126 = F_70 ( V_48 -> V_98 + V_131 ) ;
if ( V_126 & V_132 ) {
V_127 = F_70 ( V_48 -> V_98 + V_133 ) ;
if ( ( V_127 >> V_134 ) == V_29 ) {
F_62 ( L_30
L_31 ,
( unsigned long long ) V_118 -> V_135 [ V_29 ] . V_136 ,
( unsigned long long ) V_118 -> V_135 [ V_29 ] . V_137 ) ;
memcpy ( & V_118 -> V_135 [ V_29 ] , & V_118 -> V_135 [ V_129 ] ,
sizeof( struct V_138 ) ) ;
F_78 ( V_48 , & V_118 -> V_135 [ V_29 ] ,
sizeof( struct V_138 ) ) ;
F_79 ( V_132 , V_48 -> V_98 + V_131 ) ;
return - V_23 ;
}
}
if ( V_126 & V_139 ) {
V_127 = F_70 ( V_48 -> V_98 + V_133 ) ;
V_127 = ( ( V_127 >> V_134 ) - 1 + V_124 ) % V_124 ;
V_127 |= 1 ;
V_128 = F_70 ( V_48 -> V_98 + V_140 ) ;
V_128 = ( ( V_128 >> V_134 ) - 1 + V_124 ) % V_124 ;
F_79 ( V_139 , V_48 -> V_98 + V_131 ) ;
do {
if ( V_118 -> V_119 [ V_127 ] == V_141 )
V_118 -> V_119 [ V_127 ] = V_122 ;
V_127 = ( V_127 - 2 + V_124 ) % V_124 ;
} while ( V_127 != V_128 );
if ( V_118 -> V_119 [ V_129 ] == V_122 )
return - V_130 ;
}
if ( V_126 & V_142 )
F_79 ( V_142 , V_48 -> V_98 + V_131 ) ;
return 0 ;
}
int F_80 ( struct V_138 * V_135 , struct V_97 * V_48 )
{
int V_143 ;
struct V_117 * V_118 = V_48 -> V_118 ;
struct V_138 * V_144 , V_145 ;
int V_129 , V_29 ;
unsigned long V_41 ;
if ( ! V_118 )
return 0 ;
V_144 = V_118 -> V_135 ;
V_146:
V_143 = 0 ;
F_81 ( & V_118 -> V_147 , V_41 ) ;
while ( V_118 -> V_125 < 3 ) {
F_82 ( & V_118 -> V_147 , V_41 ) ;
F_83 () ;
F_81 ( & V_118 -> V_147 , V_41 ) ;
}
V_29 = V_118 -> V_148 ;
V_129 = ( V_29 + 1 ) % V_124 ;
V_118 -> V_119 [ V_29 ] = V_118 -> V_119 [ V_129 ] = V_141 ;
V_144 [ V_29 ] = * V_135 ;
V_145 . V_136 = F_84 ( V_121 ) |
V_149 | V_150 ;
V_145 . V_137 = F_85 ( & V_118 -> V_119 [ V_129 ] ) ;
V_144 [ V_129 ] = V_145 ;
F_78 ( V_48 , & V_144 [ V_29 ] , sizeof( struct V_138 ) ) ;
F_78 ( V_48 , & V_144 [ V_129 ] , sizeof( struct V_138 ) ) ;
V_118 -> V_148 = ( V_118 -> V_148 + 2 ) % V_124 ;
V_118 -> V_125 -= 2 ;
F_79 ( V_118 -> V_148 << V_134 , V_48 -> V_98 + V_140 ) ;
while ( V_118 -> V_119 [ V_129 ] != V_121 ) {
V_143 = F_77 ( V_48 , V_29 ) ;
if ( V_143 )
break;
F_86 ( & V_118 -> V_147 ) ;
F_83 () ;
F_87 ( & V_118 -> V_147 ) ;
}
V_118 -> V_119 [ V_29 ] = V_121 ;
F_76 ( V_118 ) ;
F_82 ( & V_118 -> V_147 , V_41 ) ;
if ( V_143 == - V_130 )
goto V_146;
return V_143 ;
}
void F_88 ( struct V_97 * V_48 )
{
struct V_138 V_135 ;
V_135 . V_136 = V_151 ;
V_135 . V_137 = 0 ;
F_80 ( & V_135 , V_48 ) ;
}
void F_89 ( struct V_97 * V_48 , T_2 V_152 , T_2 V_153 , T_7 V_154 ,
T_4 type )
{
struct V_138 V_135 ;
V_135 . V_136 = F_90 ( V_154 ) | F_91 ( V_153 ) | F_92 ( V_152 )
| F_93 ( type ) | V_155 ;
V_135 . V_137 = 0 ;
F_80 ( & V_135 , V_48 ) ;
}
void F_94 ( struct V_97 * V_48 , T_2 V_152 , T_4 V_80 ,
unsigned int V_156 , T_4 type )
{
T_7 V_157 = 0 , V_158 = 0 ;
struct V_138 V_135 ;
int V_159 = 0 ;
if ( F_95 ( V_48 -> V_82 ) )
V_157 = 1 ;
if ( F_96 ( V_48 -> V_82 ) )
V_158 = 1 ;
V_135 . V_136 = F_97 ( V_152 ) | F_98 ( V_158 ) | F_99 ( V_157 )
| F_100 ( type ) | V_160 ;
V_135 . V_137 = F_101 ( V_80 ) | F_102 ( V_159 )
| F_103 ( V_156 ) ;
F_80 ( & V_135 , V_48 ) ;
}
void F_104 ( struct V_97 * V_48 , T_2 V_153 , T_2 V_161 ,
T_4 V_80 , unsigned V_162 )
{
struct V_138 V_135 ;
if ( V_162 ) {
F_105 ( V_80 & ( ( 1 << ( V_163 + V_162 ) ) - 1 ) ) ;
V_80 |= ( 1 << ( V_163 + V_162 - 1 ) ) - 1 ;
V_135 . V_137 = F_106 ( V_80 ) | V_164 ;
} else
V_135 . V_137 = F_106 ( V_80 ) ;
if ( V_161 >= V_165 )
V_161 = 0 ;
V_135 . V_136 = F_107 ( V_153 ) | F_108 ( V_161 ) |
V_166 ;
F_80 ( & V_135 , V_48 ) ;
}
void F_109 ( struct V_97 * V_48 )
{
unsigned long V_41 ;
T_6 V_167 ;
T_8 V_168 = F_110 () ;
if ( ! F_111 ( V_48 -> V_83 ) )
return;
F_81 ( & V_48 -> V_116 , V_41 ) ;
V_167 = F_51 ( V_48 -> V_98 + V_169 ) ;
if ( ! ( V_167 & V_170 ) )
goto V_25;
while ( ( F_70 ( V_48 -> V_98 + V_140 ) !=
F_70 ( V_48 -> V_98 + V_133 ) ) &&
( V_171 > ( F_110 () - V_168 ) ) )
F_83 () ;
V_48 -> V_172 &= ~ V_173 ;
F_79 ( V_48 -> V_172 , V_48 -> V_98 + V_174 ) ;
F_112 ( V_48 , V_169 , F_70 ,
! ( V_167 & V_170 ) , V_167 ) ;
V_25:
F_82 ( & V_48 -> V_116 , V_41 ) ;
}
static void F_113 ( struct V_97 * V_48 )
{
T_6 V_167 ;
unsigned long V_41 ;
struct V_117 * V_118 = V_48 -> V_118 ;
V_118 -> V_148 = V_118 -> V_120 = 0 ;
V_118 -> V_125 = V_124 ;
F_81 ( & V_48 -> V_116 , V_41 ) ;
F_79 ( 0 , V_48 -> V_98 + V_140 ) ;
F_114 ( V_48 -> V_98 + V_175 , F_85 ( V_118 -> V_135 ) ) ;
V_48 -> V_172 |= V_173 ;
F_79 ( V_48 -> V_172 , V_48 -> V_98 + V_174 ) ;
F_112 ( V_48 , V_169 , F_70 , ( V_167 & V_170 ) , V_167 ) ;
F_82 ( & V_48 -> V_116 , V_41 ) ;
}
int F_115 ( struct V_97 * V_48 )
{
struct V_117 * V_118 ;
struct V_176 * V_177 ;
if ( ! F_111 ( V_48 -> V_83 ) )
return - V_178 ;
if ( V_48 -> V_118 )
return 0 ;
V_48 -> V_118 = F_116 ( sizeof( * V_118 ) , V_179 ) ;
if ( ! V_48 -> V_118 )
return - V_33 ;
V_118 = V_48 -> V_118 ;
V_177 = F_117 ( V_48 -> V_46 , V_179 | V_180 , 0 ) ;
if ( ! V_177 ) {
F_13 ( V_118 ) ;
V_48 -> V_118 = 0 ;
return - V_33 ;
}
V_118 -> V_135 = F_118 ( V_177 ) ;
V_118 -> V_119 = F_116 ( V_124 * sizeof( int ) , V_179 ) ;
if ( ! V_118 -> V_119 ) {
F_119 ( ( unsigned long ) V_118 -> V_135 ) ;
F_13 ( V_118 ) ;
V_48 -> V_118 = 0 ;
return - V_33 ;
}
V_118 -> V_148 = V_118 -> V_120 = 0 ;
V_118 -> V_125 = V_124 ;
F_73 ( & V_118 -> V_147 ) ;
F_113 ( V_48 ) ;
return 0 ;
}
const char * F_120 ( T_7 V_181 , int * V_182 )
{
if ( V_181 >= 0x20 && ( V_181 - 0x20 <
F_121 ( V_183 ) ) ) {
* V_182 = V_184 ;
return V_183 [ V_181 - 0x20 ] ;
} else if ( V_181 < F_121 ( V_185 ) ) {
* V_182 = V_186 ;
return V_185 [ V_181 ] ;
} else {
* V_182 = V_187 ;
return L_32 ;
}
}
void F_122 ( struct V_188 * V_189 )
{
struct V_97 * V_48 = F_123 ( V_189 ) ;
unsigned long V_190 ;
F_81 ( & V_48 -> V_116 , V_190 ) ;
F_79 ( 0 , V_48 -> V_98 + V_191 ) ;
F_70 ( V_48 -> V_98 + V_191 ) ;
F_82 ( & V_48 -> V_116 , V_190 ) ;
}
void F_124 ( struct V_188 * V_189 )
{
unsigned long V_190 ;
struct V_97 * V_48 = F_123 ( V_189 ) ;
F_81 ( & V_48 -> V_116 , V_190 ) ;
F_79 ( V_192 , V_48 -> V_98 + V_191 ) ;
F_70 ( V_48 -> V_98 + V_191 ) ;
F_82 ( & V_48 -> V_116 , V_190 ) ;
}
void F_125 ( int V_193 , struct V_194 * V_195 )
{
struct V_97 * V_48 = F_126 ( V_193 ) ;
unsigned long V_190 ;
F_81 ( & V_48 -> V_116 , V_190 ) ;
F_79 ( V_195 -> V_189 , V_48 -> V_98 + V_196 ) ;
F_79 ( V_195 -> V_197 , V_48 -> V_98 + V_198 ) ;
F_79 ( V_195 -> V_199 , V_48 -> V_98 + V_200 ) ;
F_82 ( & V_48 -> V_116 , V_190 ) ;
}
void F_127 ( int V_193 , struct V_194 * V_195 )
{
struct V_97 * V_48 = F_126 ( V_193 ) ;
unsigned long V_190 ;
F_81 ( & V_48 -> V_116 , V_190 ) ;
V_195 -> V_189 = F_70 ( V_48 -> V_98 + V_196 ) ;
V_195 -> V_197 = F_70 ( V_48 -> V_98 + V_198 ) ;
V_195 -> V_199 = F_70 ( V_48 -> V_98 + V_200 ) ;
F_82 ( & V_48 -> V_116 , V_190 ) ;
}
static int F_128 ( struct V_97 * V_48 , int type ,
T_7 V_181 , T_2 V_201 , unsigned long long V_80 )
{
const char * V_202 ;
int V_182 ;
V_202 = F_120 ( V_181 , & V_182 ) ;
if ( V_182 == V_184 )
F_62 ( L_33
L_34
L_35 ,
( V_201 >> 8 ) , F_129 ( V_201 & 0xFF ) ,
F_130 ( V_201 & 0xFF ) , V_80 >> 48 ,
V_181 , V_202 ) ;
else
F_62 ( L_36
L_37
L_38 ,
( type ? L_39 : L_40 ) ,
( V_201 >> 8 ) , F_129 ( V_201 & 0xFF ) ,
F_130 ( V_201 & 0xFF ) , V_80 , V_181 , V_202 ) ;
return 0 ;
}
T_9 F_131 ( int V_193 , void * V_203 )
{
struct V_97 * V_48 = V_203 ;
int V_98 , V_204 ;
T_6 V_205 ;
unsigned long V_190 ;
F_81 ( & V_48 -> V_116 , V_190 ) ;
V_205 = F_70 ( V_48 -> V_98 + V_131 ) ;
if ( V_205 )
F_62 ( L_41 , V_205 ) ;
if ( ! ( V_205 & V_206 ) )
goto V_207;
V_204 = F_132 ( V_205 ) ;
V_98 = F_133 ( V_48 -> V_82 ) ;
while ( 1 ) {
T_7 V_181 ;
T_2 V_201 ;
T_4 V_208 ;
int type ;
T_6 V_189 ;
V_189 = F_70 ( V_48 -> V_98 + V_98 +
V_204 * V_209 + 12 ) ;
if ( ! ( V_189 & V_210 ) )
break;
V_181 = F_134 ( V_189 ) ;
type = F_135 ( V_189 ) ;
V_189 = F_70 ( V_48 -> V_98 + V_98 +
V_204 * V_209 + 8 ) ;
V_201 = F_136 ( V_189 ) ;
V_208 = F_51 ( V_48 -> V_98 + V_98 +
V_204 * V_209 ) ;
V_208 = F_137 ( V_208 ) ;
F_79 ( V_210 , V_48 -> V_98 + V_98 +
V_204 * V_209 + 12 ) ;
F_82 ( & V_48 -> V_116 , V_190 ) ;
F_128 ( V_48 , type , V_181 ,
V_201 , V_208 ) ;
V_204 ++ ;
if ( V_204 >= F_138 ( V_48 -> V_82 ) )
V_204 = 0 ;
F_81 ( & V_48 -> V_116 , V_190 ) ;
}
V_207:
V_205 = F_70 ( V_48 -> V_98 + V_131 ) ;
F_79 ( V_205 , V_48 -> V_98 + V_131 ) ;
F_82 ( & V_48 -> V_116 , V_190 ) ;
return V_211 ;
}
int F_139 ( struct V_97 * V_48 )
{
int V_193 , V_30 ;
if ( V_48 -> V_193 )
return 0 ;
V_193 = F_140 () ;
if ( ! V_193 ) {
F_62 ( L_42 ) ;
return - V_23 ;
}
F_141 ( V_193 , V_48 ) ;
V_48 -> V_193 = V_193 ;
V_30 = F_142 ( V_193 ) ;
if ( V_30 ) {
F_141 ( V_193 , NULL ) ;
V_48 -> V_193 = 0 ;
F_143 ( V_193 ) ;
return V_30 ;
}
V_30 = F_144 ( V_193 , F_131 , V_212 , V_48 -> V_104 , V_48 ) ;
if ( V_30 )
F_62 ( L_43 ) ;
return V_30 ;
}
int T_1 F_145 ( void )
{
struct V_1 * V_2 ;
F_20 (drhd) {
int V_30 ;
struct V_97 * V_48 = V_2 -> V_48 ;
V_30 = F_139 ( V_48 ) ;
if ( V_30 ) {
F_62 ( L_44 ,
( unsigned long long ) V_2 -> V_39 , V_30 ) ;
return - 1 ;
}
F_131 ( V_48 -> V_193 , V_48 ) ;
}
return 0 ;
}
int F_146 ( struct V_97 * V_48 )
{
if ( ! F_111 ( V_48 -> V_83 ) )
return - V_178 ;
if ( ! V_48 -> V_118 )
return - V_178 ;
F_109 ( V_48 ) ;
F_113 ( V_48 ) ;
return 0 ;
}
int T_1 F_147 ( void )
{
struct V_69 * V_70 ;
V_70 = (struct V_69 * ) V_66 ;
if ( ! V_70 )
return 0 ;
return V_70 -> V_41 & 0x1 ;
}
