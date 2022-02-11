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
F_13 ( V_28 , V_27 ) ;
return V_31 ;
}
V_30 ++ ;
}
V_25 += V_7 -> V_17 ;
}
return 0 ;
}
void F_13 ( struct V_8 * * * V_28 , int * V_27 )
{
if ( * V_28 && * V_27 ) {
while ( -- * V_27 >= 0 )
F_6 ( ( * V_28 ) [ * V_27 ] ) ;
F_14 ( * V_28 ) ;
* V_28 = NULL ;
* V_27 = 0 ;
}
}
static int T_1
F_15 ( struct V_36 * V_37 )
{
struct V_38 * V_2 ;
struct V_1 * V_39 ;
int V_31 = 0 ;
V_2 = (struct V_38 * ) V_37 ;
V_39 = F_16 ( sizeof( * V_39 ) , V_34 ) ;
if ( ! V_39 )
return - V_35 ;
V_39 -> V_40 = V_37 ;
V_39 -> V_41 = V_2 -> V_42 ;
V_39 -> V_10 = V_2 -> V_10 ;
V_39 -> V_3 = V_2 -> V_43 & 0x1 ;
V_31 = F_17 ( V_39 ) ;
if ( V_31 ) {
F_14 ( V_39 ) ;
return V_31 ;
}
F_1 ( V_39 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_39 )
{
if ( V_39 -> V_28 && V_39 -> V_44 )
F_13 ( & V_39 -> V_28 , & V_39 -> V_44 ) ;
if ( V_39 -> V_45 )
F_19 ( V_39 -> V_45 ) ;
F_14 ( V_39 ) ;
}
static int T_1 F_20 ( struct V_1 * V_39 )
{
struct V_38 * V_2 ;
V_2 = (struct V_38 * ) V_39 -> V_40 ;
if ( V_39 -> V_3 )
return 0 ;
return F_11 ( ( void * ) ( V_2 + 1 ) ,
( ( void * ) V_2 ) + V_2 -> V_37 . V_17 ,
& V_39 -> V_44 , & V_39 -> V_28 ,
V_2 -> V_10 ) ;
}
static int T_1
F_21 ( struct V_36 * V_37 )
{
struct V_46 * V_47 ;
struct V_1 * V_2 ;
V_47 = (struct V_46 * ) V_37 ;
F_22 (drhd) {
if ( V_2 -> V_41 == V_47 -> V_48 ) {
int V_49 = F_23 ( V_47 -> V_50 ) ;
if ( ! F_24 ( V_49 ) )
V_49 = - 1 ;
V_2 -> V_45 -> V_49 = V_49 ;
return 0 ;
}
}
F_25 (
1 , V_51 ,
L_5
L_6 ,
V_2 -> V_41 ,
F_26 ( V_52 ) ,
F_26 ( V_53 ) ,
F_26 ( V_54 ) ) ;
return 0 ;
}
static void T_1
F_27 ( struct V_36 * V_37 )
{
struct V_38 * V_2 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_46 * V_47 ;
switch ( V_37 -> type ) {
case V_59 :
V_2 = F_28 ( V_37 , struct V_38 ,
V_37 ) ;
F_29 ( L_7 ,
( unsigned long long ) V_2 -> V_42 , V_2 -> V_43 ) ;
break;
case V_60 :
V_56 = F_28 ( V_37 , struct V_55 ,
V_37 ) ;
F_29 ( L_8 ,
( unsigned long long ) V_56 -> V_48 ,
( unsigned long long ) V_56 -> V_61 ) ;
break;
case V_62 :
V_58 = F_28 ( V_37 , struct V_57 , V_37 ) ;
F_29 ( L_9 , V_58 -> V_43 ) ;
break;
case V_63 :
V_47 = F_28 ( V_37 , struct V_46 , V_37 ) ;
F_29 ( L_10 ,
( unsigned long long ) V_47 -> V_48 ,
V_47 -> V_50 ) ;
break;
}
}
static int T_1 F_30 ( void )
{
T_3 V_64 = V_65 ;
V_64 = F_31 ( V_66 , 0 ,
(struct V_67 * * ) & V_68 ,
& V_69 ) ;
if ( F_32 ( V_64 ) && ! V_68 ) {
F_7 ( L_11 ) ;
V_64 = V_70 ;
}
return ( F_32 ( V_64 ) ? 1 : 0 ) ;
}
static int T_1
F_33 ( void )
{
struct V_71 * V_72 ;
struct V_36 * V_73 ;
int V_31 = 0 ;
int V_74 = 0 ;
F_30 () ;
V_68 = F_34 ( V_68 ) ;
V_72 = (struct V_71 * ) V_68 ;
if ( ! V_72 )
return - V_75 ;
if ( V_72 -> V_76 < V_77 - 1 ) {
F_7 ( L_12 ) ;
return - V_24 ;
}
F_29 ( L_13 , V_72 -> V_76 + 1 ) ;
V_73 = (struct V_36 * ) ( V_72 + 1 ) ;
while ( ( ( unsigned long ) V_73 ) <
( ( ( unsigned long ) V_72 ) + V_68 -> V_17 ) ) {
if ( V_73 -> V_17 == 0 ) {
F_7 ( L_14 ) ;
V_31 = - V_24 ;
break;
}
F_27 ( V_73 ) ;
switch ( V_73 -> type ) {
case V_59 :
V_74 ++ ;
V_31 = F_15 ( V_73 ) ;
break;
case V_60 :
V_31 = F_35 ( V_73 ) ;
break;
case V_62 :
V_31 = F_36 ( V_73 ) ;
break;
case V_63 :
#ifdef F_37
V_31 = F_21 ( V_73 ) ;
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
static int F_38 ( struct V_8 * V_28 [] , int V_27 ,
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
F_39 ( struct V_8 * V_9 )
{
struct V_1 * V_39 = NULL ;
struct V_38 * V_2 ;
V_9 = F_40 ( V_9 ) ;
F_22 (dmaru) {
V_2 = F_28 ( V_39 -> V_40 ,
struct V_38 ,
V_37 ) ;
if ( V_39 -> V_3 &&
V_2 -> V_10 == F_41 ( V_9 -> V_12 ) )
return V_39 ;
if ( F_38 ( V_39 -> V_28 ,
V_39 -> V_44 , V_9 ) )
return V_39 ;
}
return NULL ;
}
int T_1 F_42 ( void )
{
static int V_80 ;
struct V_1 * V_2 ;
int V_31 = - V_75 ;
if ( V_80 )
return V_80 ;
if ( F_43 ( & V_5 ) )
goto V_81;
F_44 (drhd, &dmar_drhd_units, list) {
V_31 = F_20 ( V_2 ) ;
if ( V_31 )
goto V_81;
}
V_31 = F_45 () ;
if ( V_31 )
goto V_81;
V_80 = 1 ;
return 0 ;
V_81:
V_80 = V_31 ;
return V_31 ;
}
int T_1 F_46 ( void )
{
static int V_82 ;
int V_31 ;
if ( V_82 == 0 ) {
V_31 = F_33 () ;
if ( V_31 < 0 ) {
if ( V_31 != - V_75 )
F_29 ( L_17 ) ;
} else if ( F_43 ( & V_5 ) ) {
F_29 ( L_18 ) ;
V_31 = - V_75 ;
}
if ( V_31 < 0 )
V_82 = V_31 ;
else
V_82 = 1 ;
}
return V_82 < 0 ? V_82 : 0 ;
}
static void F_47 ( T_4 V_83 , const char * V_84 )
{
F_48 (
1 , V_51 ,
L_19
L_6 ,
V_83 , V_84 ,
F_26 ( V_52 ) ,
F_26 ( V_53 ) ,
F_26 ( V_54 ) ) ;
}
static int T_1 F_49 ( void )
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
void T_5 * V_83 ;
T_4 V_85 , V_86 ;
V_2 = ( void * ) V_73 ;
if ( ! V_2 -> V_42 ) {
F_47 ( 0 , L_20 ) ;
goto V_87;
}
V_83 = F_50 ( V_2 -> V_42 , V_88 ) ;
if ( ! V_83 ) {
F_51 ( L_21 , V_2 -> V_42 ) ;
goto V_87;
}
V_85 = F_52 ( V_83 + V_89 ) ;
V_86 = F_52 ( V_83 + V_90 ) ;
F_53 ( V_83 , V_88 ) ;
if ( V_85 == ( V_91 ) - 1 && V_86 == ( V_91 ) - 1 ) {
F_47 ( V_2 -> V_42 ,
L_22 ) ;
goto V_87;
}
}
V_73 = ( ( void * ) V_73 + V_73 -> V_17 ) ;
}
return 1 ;
V_87:
return 0 ;
}
int T_1 F_54 ( void )
{
int V_31 ;
V_31 = F_30 () ;
if ( V_31 )
V_31 = F_49 () ;
{
if ( V_31 && ! V_92 && ! V_93 && ! V_94 ) {
V_93 = 1 ;
F_55 () ;
}
#ifdef F_56
if ( V_31 )
V_95 . V_45 . V_96 = V_97 ;
#endif
}
F_57 ( ( void T_5 * ) V_68 , V_69 ) ;
V_68 = NULL ;
return V_31 ? 1 : - V_75 ;
}
static void F_58 ( struct V_98 * V_45 )
{
F_59 ( V_45 -> V_99 ) ;
F_60 ( V_45 -> V_100 , V_45 -> V_101 ) ;
}
static int F_61 ( struct V_98 * V_45 , T_4 V_102 )
{
int V_103 , V_104 = 0 ;
V_45 -> V_100 = V_102 ;
V_45 -> V_101 = V_88 ;
if ( ! F_62 ( V_45 -> V_100 , V_45 -> V_101 , V_45 -> V_105 ) ) {
F_63 ( L_23 ) ;
V_104 = - V_106 ;
goto V_107;
}
V_45 -> V_99 = F_64 ( V_45 -> V_100 , V_45 -> V_101 ) ;
if ( ! V_45 -> V_99 ) {
F_63 ( L_24 ) ;
V_104 = - V_35 ;
goto V_108;
}
V_45 -> V_85 = F_52 ( V_45 -> V_99 + V_89 ) ;
V_45 -> V_86 = F_52 ( V_45 -> V_99 + V_90 ) ;
if ( V_45 -> V_85 == ( V_91 ) - 1 && V_45 -> V_86 == ( V_91 ) - 1 ) {
V_104 = - V_24 ;
F_47 ( V_102 , L_22 ) ;
goto V_109;
}
V_103 = F_65 ( int , F_66 ( V_45 -> V_86 ) ,
F_67 ( V_45 -> V_85 ) ) ;
V_103 = F_68 ( V_103 ) ;
if ( V_103 > V_45 -> V_101 ) {
F_59 ( V_45 -> V_99 ) ;
F_60 ( V_45 -> V_100 , V_45 -> V_101 ) ;
V_45 -> V_101 = V_103 ;
if ( ! F_62 ( V_45 -> V_100 , V_45 -> V_101 ,
V_45 -> V_105 ) ) {
F_63 ( L_23 ) ;
V_104 = - V_106 ;
goto V_107;
}
V_45 -> V_99 = F_64 ( V_45 -> V_100 , V_45 -> V_101 ) ;
if ( ! V_45 -> V_99 ) {
F_63 ( L_24 ) ;
V_104 = - V_35 ;
goto V_108;
}
}
V_104 = 0 ;
goto V_107;
V_109:
F_59 ( V_45 -> V_99 ) ;
V_108:
F_60 ( V_45 -> V_100 , V_45 -> V_101 ) ;
V_107:
return V_104 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_98 * V_45 ;
T_6 V_110 , V_111 ;
static int V_112 = 0 ;
int V_113 = 0 ;
int V_114 = 0 ;
int V_104 ;
if ( ! V_2 -> V_41 ) {
F_47 ( 0 , L_20 ) ;
return - V_24 ;
}
V_45 = F_16 ( sizeof( * V_45 ) , V_34 ) ;
if ( ! V_45 )
return - V_35 ;
V_45 -> V_115 = V_112 ++ ;
sprintf ( V_45 -> V_105 , L_25 , V_45 -> V_115 ) ;
V_104 = F_61 ( V_45 , V_2 -> V_41 ) ;
if ( V_104 ) {
F_63 ( L_26 , V_45 -> V_105 ) ;
goto error;
}
V_104 = - V_24 ;
V_113 = F_69 ( V_45 ) ;
if ( V_113 < 0 ) {
F_63 ( L_27 ,
V_45 -> V_115 ) ;
goto V_116;
}
V_114 = F_70 ( V_45 ) ;
if ( V_114 < 0 ) {
F_63 ( L_28 ,
V_45 -> V_115 ) ;
goto V_116;
}
V_45 -> V_113 = V_113 ;
V_45 -> V_114 = V_114 ;
V_45 -> V_49 = - 1 ;
V_110 = F_71 ( V_45 -> V_99 + V_117 ) ;
F_29 ( L_29 ,
V_45 -> V_115 ,
( unsigned long long ) V_2 -> V_41 ,
F_72 ( V_110 ) , F_73 ( V_110 ) ,
( unsigned long long ) V_45 -> V_85 ,
( unsigned long long ) V_45 -> V_86 ) ;
V_111 = F_71 ( V_45 -> V_99 + V_118 ) ;
if ( V_111 & V_119 )
V_45 -> V_120 |= V_121 ;
if ( V_111 & V_122 )
V_45 -> V_120 |= V_123 ;
if ( V_111 & V_124 )
V_45 -> V_120 |= V_125 ;
F_74 ( & V_45 -> V_126 ) ;
V_2 -> V_45 = V_45 ;
return 0 ;
V_116:
F_58 ( V_45 ) ;
error:
F_14 ( V_45 ) ;
return V_104 ;
}
static void F_19 ( struct V_98 * V_45 )
{
if ( V_45 -> V_127 ) {
F_75 ( V_45 -> V_127 , V_45 ) ;
F_76 ( V_45 -> V_127 , NULL ) ;
F_77 ( V_45 -> V_127 ) ;
}
if ( V_45 -> V_128 ) {
F_78 ( ( unsigned long ) V_45 -> V_128 -> V_129 ) ;
F_14 ( V_45 -> V_128 -> V_130 ) ;
F_14 ( V_45 -> V_128 ) ;
}
if ( V_45 -> V_99 )
F_58 ( V_45 ) ;
F_14 ( V_45 ) ;
}
static inline void F_79 ( struct V_131 * V_128 )
{
while ( V_128 -> V_130 [ V_128 -> V_132 ] == V_133 ||
V_128 -> V_130 [ V_128 -> V_132 ] == V_134 ) {
V_128 -> V_130 [ V_128 -> V_132 ] = V_135 ;
V_128 -> V_132 = ( V_128 -> V_132 + 1 ) % V_136 ;
V_128 -> V_137 ++ ;
}
}
static int F_80 ( struct V_98 * V_45 , int V_30 )
{
T_6 V_138 ;
int V_139 , V_140 ;
struct V_131 * V_128 = V_45 -> V_128 ;
int V_141 = ( V_30 + 1 ) % V_136 ;
if ( V_128 -> V_130 [ V_141 ] == V_134 )
return - V_142 ;
V_138 = F_71 ( V_45 -> V_99 + V_143 ) ;
if ( V_138 & V_144 ) {
V_139 = F_71 ( V_45 -> V_99 + V_145 ) ;
if ( ( V_139 >> V_146 ) == V_30 ) {
F_63 ( L_30
L_31 ,
( unsigned long long ) V_128 -> V_129 [ V_30 ] . V_147 ,
( unsigned long long ) V_128 -> V_129 [ V_30 ] . V_148 ) ;
memcpy ( & V_128 -> V_129 [ V_30 ] , & V_128 -> V_129 [ V_141 ] ,
sizeof( struct V_149 ) ) ;
F_81 ( V_45 , & V_128 -> V_129 [ V_30 ] ,
sizeof( struct V_149 ) ) ;
F_82 ( V_144 , V_45 -> V_99 + V_143 ) ;
return - V_24 ;
}
}
if ( V_138 & V_150 ) {
V_139 = F_71 ( V_45 -> V_99 + V_145 ) ;
V_139 = ( ( V_139 >> V_146 ) - 1 + V_136 ) % V_136 ;
V_139 |= 1 ;
V_140 = F_71 ( V_45 -> V_99 + V_151 ) ;
V_140 = ( ( V_140 >> V_146 ) - 1 + V_136 ) % V_136 ;
F_82 ( V_150 , V_45 -> V_99 + V_143 ) ;
do {
if ( V_128 -> V_130 [ V_139 ] == V_152 )
V_128 -> V_130 [ V_139 ] = V_134 ;
V_139 = ( V_139 - 2 + V_136 ) % V_136 ;
} while ( V_139 != V_140 );
if ( V_128 -> V_130 [ V_141 ] == V_134 )
return - V_142 ;
}
if ( V_138 & V_153 )
F_82 ( V_153 , V_45 -> V_99 + V_143 ) ;
return 0 ;
}
int F_83 ( struct V_149 * V_129 , struct V_98 * V_45 )
{
int V_154 ;
struct V_131 * V_128 = V_45 -> V_128 ;
struct V_149 * V_155 , V_156 ;
int V_141 , V_30 ;
unsigned long V_43 ;
if ( ! V_128 )
return 0 ;
V_155 = V_128 -> V_129 ;
V_157:
V_154 = 0 ;
F_84 ( & V_128 -> V_158 , V_43 ) ;
while ( V_128 -> V_137 < 3 ) {
F_85 ( & V_128 -> V_158 , V_43 ) ;
F_86 () ;
F_84 ( & V_128 -> V_158 , V_43 ) ;
}
V_30 = V_128 -> V_159 ;
V_141 = ( V_30 + 1 ) % V_136 ;
V_128 -> V_130 [ V_30 ] = V_128 -> V_130 [ V_141 ] = V_152 ;
V_155 [ V_30 ] = * V_129 ;
V_156 . V_147 = F_87 ( V_133 ) |
V_160 | V_161 ;
V_156 . V_148 = F_88 ( & V_128 -> V_130 [ V_141 ] ) ;
V_155 [ V_141 ] = V_156 ;
F_81 ( V_45 , & V_155 [ V_30 ] , sizeof( struct V_149 ) ) ;
F_81 ( V_45 , & V_155 [ V_141 ] , sizeof( struct V_149 ) ) ;
V_128 -> V_159 = ( V_128 -> V_159 + 2 ) % V_136 ;
V_128 -> V_137 -= 2 ;
F_82 ( V_128 -> V_159 << V_146 , V_45 -> V_99 + V_151 ) ;
while ( V_128 -> V_130 [ V_141 ] != V_133 ) {
V_154 = F_80 ( V_45 , V_30 ) ;
if ( V_154 )
break;
F_89 ( & V_128 -> V_158 ) ;
F_86 () ;
F_90 ( & V_128 -> V_158 ) ;
}
V_128 -> V_130 [ V_30 ] = V_133 ;
F_79 ( V_128 ) ;
F_85 ( & V_128 -> V_158 , V_43 ) ;
if ( V_154 == - V_142 )
goto V_157;
return V_154 ;
}
void F_91 ( struct V_98 * V_45 )
{
struct V_149 V_129 ;
V_129 . V_147 = V_162 ;
V_129 . V_148 = 0 ;
F_83 ( & V_129 , V_45 ) ;
}
void F_92 ( struct V_98 * V_45 , T_2 V_163 , T_2 V_164 , T_7 V_165 ,
T_4 type )
{
struct V_149 V_129 ;
V_129 . V_147 = F_93 ( V_165 ) | F_94 ( V_164 ) | F_95 ( V_163 )
| F_96 ( type ) | V_166 ;
V_129 . V_148 = 0 ;
F_83 ( & V_129 , V_45 ) ;
}
void F_97 ( struct V_98 * V_45 , T_2 V_163 , T_4 V_83 ,
unsigned int V_167 , T_4 type )
{
T_7 V_168 = 0 , V_169 = 0 ;
struct V_149 V_129 ;
int V_170 = 0 ;
if ( F_98 ( V_45 -> V_85 ) )
V_168 = 1 ;
if ( F_99 ( V_45 -> V_85 ) )
V_169 = 1 ;
V_129 . V_147 = F_100 ( V_163 ) | F_101 ( V_169 ) | F_102 ( V_168 )
| F_103 ( type ) | V_171 ;
V_129 . V_148 = F_104 ( V_83 ) | F_105 ( V_170 )
| F_106 ( V_167 ) ;
F_83 ( & V_129 , V_45 ) ;
}
void F_107 ( struct V_98 * V_45 , T_2 V_164 , T_2 V_172 ,
T_4 V_83 , unsigned V_173 )
{
struct V_149 V_129 ;
if ( V_173 ) {
F_108 ( V_83 & ( ( 1 << ( V_174 + V_173 ) ) - 1 ) ) ;
V_83 |= ( 1 << ( V_174 + V_173 - 1 ) ) - 1 ;
V_129 . V_148 = F_109 ( V_83 ) | V_175 ;
} else
V_129 . V_148 = F_109 ( V_83 ) ;
if ( V_172 >= V_176 )
V_172 = 0 ;
V_129 . V_147 = F_110 ( V_164 ) | F_111 ( V_172 ) |
V_177 ;
F_83 ( & V_129 , V_45 ) ;
}
void F_112 ( struct V_98 * V_45 )
{
unsigned long V_43 ;
T_6 V_111 ;
T_8 V_178 = F_113 () ;
if ( ! F_114 ( V_45 -> V_86 ) )
return;
F_84 ( & V_45 -> V_126 , V_43 ) ;
V_111 = F_52 ( V_45 -> V_99 + V_118 ) ;
if ( ! ( V_111 & V_124 ) )
goto V_26;
while ( ( F_71 ( V_45 -> V_99 + V_151 ) !=
F_71 ( V_45 -> V_99 + V_145 ) ) &&
( V_179 > ( F_113 () - V_178 ) ) )
F_86 () ;
V_45 -> V_120 &= ~ V_125 ;
F_82 ( V_45 -> V_120 , V_45 -> V_99 + V_180 ) ;
F_115 ( V_45 , V_118 , F_71 ,
! ( V_111 & V_124 ) , V_111 ) ;
V_26:
F_85 ( & V_45 -> V_126 , V_43 ) ;
}
static void F_116 ( struct V_98 * V_45 )
{
T_6 V_111 ;
unsigned long V_43 ;
struct V_131 * V_128 = V_45 -> V_128 ;
V_128 -> V_159 = V_128 -> V_132 = 0 ;
V_128 -> V_137 = V_136 ;
F_84 ( & V_45 -> V_126 , V_43 ) ;
F_82 ( 0 , V_45 -> V_99 + V_151 ) ;
F_117 ( V_45 -> V_99 + V_181 , F_88 ( V_128 -> V_129 ) ) ;
V_45 -> V_120 |= V_125 ;
F_82 ( V_45 -> V_120 , V_45 -> V_99 + V_180 ) ;
F_115 ( V_45 , V_118 , F_71 , ( V_111 & V_124 ) , V_111 ) ;
F_85 ( & V_45 -> V_126 , V_43 ) ;
}
int F_118 ( struct V_98 * V_45 )
{
struct V_131 * V_128 ;
struct V_182 * V_183 ;
if ( ! F_114 ( V_45 -> V_86 ) )
return - V_184 ;
if ( V_45 -> V_128 )
return 0 ;
V_45 -> V_128 = F_119 ( sizeof( * V_128 ) , V_185 ) ;
if ( ! V_45 -> V_128 )
return - V_35 ;
V_128 = V_45 -> V_128 ;
V_183 = F_120 ( V_45 -> V_49 , V_185 | V_186 , 0 ) ;
if ( ! V_183 ) {
F_14 ( V_128 ) ;
V_45 -> V_128 = NULL ;
return - V_35 ;
}
V_128 -> V_129 = F_121 ( V_183 ) ;
V_128 -> V_130 = F_16 ( V_136 * sizeof( int ) , V_185 ) ;
if ( ! V_128 -> V_130 ) {
F_78 ( ( unsigned long ) V_128 -> V_129 ) ;
F_14 ( V_128 ) ;
V_45 -> V_128 = NULL ;
return - V_35 ;
}
V_128 -> V_159 = V_128 -> V_132 = 0 ;
V_128 -> V_137 = V_136 ;
F_74 ( & V_128 -> V_158 ) ;
F_116 ( V_45 ) ;
return 0 ;
}
static const char * F_122 ( T_7 V_187 , int * V_188 )
{
if ( V_187 >= 0x20 && ( V_187 - 0x20 <
F_123 ( V_189 ) ) ) {
* V_188 = V_190 ;
return V_189 [ V_187 - 0x20 ] ;
} else if ( V_187 < F_123 ( V_191 ) ) {
* V_188 = V_192 ;
return V_191 [ V_187 ] ;
} else {
* V_188 = V_193 ;
return L_32 ;
}
}
void F_124 ( struct V_194 * V_195 )
{
struct V_98 * V_45 = F_125 ( V_195 ) ;
unsigned long V_196 ;
F_84 ( & V_45 -> V_126 , V_196 ) ;
F_82 ( 0 , V_45 -> V_99 + V_197 ) ;
F_71 ( V_45 -> V_99 + V_197 ) ;
F_85 ( & V_45 -> V_126 , V_196 ) ;
}
void F_126 ( struct V_194 * V_195 )
{
unsigned long V_196 ;
struct V_98 * V_45 = F_125 ( V_195 ) ;
F_84 ( & V_45 -> V_126 , V_196 ) ;
F_82 ( V_198 , V_45 -> V_99 + V_197 ) ;
F_71 ( V_45 -> V_99 + V_197 ) ;
F_85 ( & V_45 -> V_126 , V_196 ) ;
}
void F_127 ( int V_127 , struct V_199 * V_200 )
{
struct V_98 * V_45 = F_128 ( V_127 ) ;
unsigned long V_196 ;
F_84 ( & V_45 -> V_126 , V_196 ) ;
F_82 ( V_200 -> V_195 , V_45 -> V_99 + V_201 ) ;
F_82 ( V_200 -> V_202 , V_45 -> V_99 + V_203 ) ;
F_82 ( V_200 -> V_204 , V_45 -> V_99 + V_205 ) ;
F_85 ( & V_45 -> V_126 , V_196 ) ;
}
void F_129 ( int V_127 , struct V_199 * V_200 )
{
struct V_98 * V_45 = F_128 ( V_127 ) ;
unsigned long V_196 ;
F_84 ( & V_45 -> V_126 , V_196 ) ;
V_200 -> V_195 = F_71 ( V_45 -> V_99 + V_201 ) ;
V_200 -> V_202 = F_71 ( V_45 -> V_99 + V_203 ) ;
V_200 -> V_204 = F_71 ( V_45 -> V_99 + V_205 ) ;
F_85 ( & V_45 -> V_126 , V_196 ) ;
}
static int F_130 ( struct V_98 * V_45 , int type ,
T_7 V_187 , T_2 V_206 , unsigned long long V_83 )
{
const char * V_207 ;
int V_188 ;
V_207 = F_122 ( V_187 , & V_188 ) ;
if ( V_188 == V_190 )
F_63 ( L_33
L_34
L_35 ,
( V_206 >> 8 ) , F_131 ( V_206 & 0xFF ) ,
F_132 ( V_206 & 0xFF ) , V_83 >> 48 ,
V_187 , V_207 ) ;
else
F_63 ( L_36
L_37
L_38 ,
( type ? L_39 : L_40 ) ,
( V_206 >> 8 ) , F_131 ( V_206 & 0xFF ) ,
F_132 ( V_206 & 0xFF ) , V_83 , V_187 , V_207 ) ;
return 0 ;
}
T_9 F_133 ( int V_127 , void * V_208 )
{
struct V_98 * V_45 = V_208 ;
int V_99 , V_209 ;
T_6 V_210 ;
unsigned long V_196 ;
F_84 ( & V_45 -> V_126 , V_196 ) ;
V_210 = F_71 ( V_45 -> V_99 + V_143 ) ;
if ( V_210 )
F_63 ( L_41 , V_210 ) ;
if ( ! ( V_210 & V_211 ) )
goto V_212;
V_209 = F_134 ( V_210 ) ;
V_99 = F_135 ( V_45 -> V_85 ) ;
while ( 1 ) {
T_7 V_187 ;
T_2 V_206 ;
T_4 V_213 ;
int type ;
T_6 V_195 ;
V_195 = F_71 ( V_45 -> V_99 + V_99 +
V_209 * V_214 + 12 ) ;
if ( ! ( V_195 & V_215 ) )
break;
V_187 = F_136 ( V_195 ) ;
type = F_137 ( V_195 ) ;
V_195 = F_71 ( V_45 -> V_99 + V_99 +
V_209 * V_214 + 8 ) ;
V_206 = F_138 ( V_195 ) ;
V_213 = F_52 ( V_45 -> V_99 + V_99 +
V_209 * V_214 ) ;
V_213 = F_139 ( V_213 ) ;
F_82 ( V_215 , V_45 -> V_99 + V_99 +
V_209 * V_214 + 12 ) ;
F_85 ( & V_45 -> V_126 , V_196 ) ;
F_130 ( V_45 , type , V_187 ,
V_206 , V_213 ) ;
V_209 ++ ;
if ( V_209 >= F_140 ( V_45 -> V_85 ) )
V_209 = 0 ;
F_84 ( & V_45 -> V_126 , V_196 ) ;
}
F_82 ( V_216 | V_211 , V_45 -> V_99 + V_143 ) ;
V_212:
F_85 ( & V_45 -> V_126 , V_196 ) ;
return V_217 ;
}
int F_141 ( struct V_98 * V_45 )
{
int V_127 , V_31 ;
if ( V_45 -> V_127 )
return 0 ;
V_127 = F_142 () ;
if ( ! V_127 ) {
F_63 ( L_42 ) ;
return - V_24 ;
}
F_76 ( V_127 , V_45 ) ;
V_45 -> V_127 = V_127 ;
V_31 = F_143 ( V_127 ) ;
if ( V_31 ) {
F_76 ( V_127 , NULL ) ;
V_45 -> V_127 = 0 ;
F_77 ( V_127 ) ;
return V_31 ;
}
V_31 = F_144 ( V_127 , F_133 , V_218 , V_45 -> V_105 , V_45 ) ;
if ( V_31 )
F_63 ( L_43 ) ;
return V_31 ;
}
int T_1 F_145 ( void )
{
struct V_1 * V_2 ;
struct V_98 * V_45 ;
F_146 (iommu, drhd) {
T_6 V_210 ;
int V_31 = F_141 ( V_45 ) ;
if ( V_31 ) {
F_63 ( L_44 ,
( unsigned long long ) V_2 -> V_41 , V_31 ) ;
return - 1 ;
}
F_133 ( V_45 -> V_127 , V_45 ) ;
V_210 = F_71 ( V_45 -> V_99 + V_143 ) ;
F_82 ( V_210 , V_45 -> V_99 + V_143 ) ;
}
return 0 ;
}
int F_147 ( struct V_98 * V_45 )
{
if ( ! F_114 ( V_45 -> V_86 ) )
return - V_184 ;
if ( ! V_45 -> V_128 )
return - V_184 ;
F_112 ( V_45 ) ;
F_116 ( V_45 ) ;
return 0 ;
}
int T_1 F_148 ( void )
{
struct V_71 * V_72 ;
V_72 = (struct V_71 * ) V_68 ;
if ( ! V_72 )
return 0 ;
return V_72 -> V_43 & 0x1 ;
}
static int T_1 F_149 ( void )
{
struct V_1 * V_39 , * V_219 ;
if ( V_220 || V_221 )
return 0 ;
F_150 (dmaru, dmaru_n, &dmar_drhd_units, list) {
F_151 ( & V_39 -> V_4 ) ;
F_18 ( V_39 ) ;
}
return 0 ;
}
