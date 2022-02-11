static int
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 [ V_2 -> V_4 . V_5 ] = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( ! V_2 -> V_3 [ V_2 -> V_4 . V_5 ] )
return - V_8 ;
V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] . V_10 = F_3 ( NULL ,
V_2 -> V_3 [ V_2 -> V_4 . V_5 ] -> V_11 , V_7 ,
V_12 ) ;
V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] . V_10 =
F_4 ( V_2 -> V_3 [ V_2 -> V_4 . V_5 ] -> V_11 ) ;
V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] . V_13 =
V_14 | F_5 ( V_15 ) |
V_7 ;
F_6 ( V_2 -> V_3 [ V_2 -> V_4 . V_5 ] , V_15 ) ;
return 0 ;
}
static void
F_7 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_2 -> V_6 ) ;
struct V_18 * V_5 = & V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] ;
struct V_19 * V_3 = V_2 -> V_3 [ V_2 -> V_4 . V_5 ] ;
int V_20 = ( V_5 -> V_13 & V_21 ) - V_22 ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
if ( F_1 ( V_2 ) ) {
F_10 ( V_2 -> V_6 ,
L_1 ) ;
F_11 ( & V_2 -> V_4 ) ;
}
V_2 -> V_4 . V_5 ++ ;
V_2 -> V_4 . V_5 %= V_25 ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
F_13 ( V_3 , V_20 ) ;
V_3 -> V_26 = F_14 ( V_3 , V_2 -> V_6 ) ;
F_15 ( V_3 ) ;
}
static int
F_16 ( struct V_27 * V_28 , int V_29 )
{
struct V_1 * V_2 = F_17 ( V_28 ,
struct V_1 , V_28 ) ;
int V_30 = 0 ;
int V_31 = 0 ;
while ( ( V_30 < V_29 ) && ! V_31 ) {
struct V_18 * V_5 = & V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] ;
if ( ( V_5 -> V_13 & ( V_14 | V_32 ) ) == V_32 ) {
F_7 ( V_2 ) ;
V_30 ++ ;
} else {
V_31 = 1 ;
}
}
if ( V_31 || ! V_30 ) {
F_18 ( & V_2 -> V_28 ) ;
F_19 ( & V_2 -> V_4 ) ;
}
return V_30 ;
}
static int
F_20 ( struct V_27 * V_28 , int V_29 )
{
struct V_1 * V_2 =
F_17 ( V_28 , struct V_1 , V_28 ) ;
struct V_16 * V_17 = F_8 ( V_2 -> V_6 ) ;
struct V_33 * V_34 =
F_21 ( V_2 -> V_6 , V_2 -> V_35 >> 1 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
while ( ( V_2 -> V_4 . V_9 [ V_2 -> V_36 ] . V_13 &
( V_14 | V_32 ) ) == V_32 ) {
F_22 ( V_2 -> V_3 [ V_2 -> V_36 ] ) ;
V_2 -> V_3 [ V_2 -> V_36 ] = NULL ;
memset ( & V_2 -> V_4 . V_9 [ V_2 -> V_36 ] , 0 ,
sizeof( struct V_18 ) ) ;
V_2 -> V_36 ++ ;
V_2 -> V_36 %= V_25 ;
}
F_12 ( & V_17 -> V_24 , V_23 ) ;
if ( F_23 ( V_34 ) )
F_24 ( V_34 ) ;
F_18 ( & V_2 -> V_28 ) ;
F_19 ( & V_2 -> V_4 ) ;
return 1 ;
}
static T_1
F_25 ( int V_37 , void * V_38 )
{
struct V_16 * V_17 = V_38 ;
int V_2 = V_37 - V_39 ;
F_26 ( & V_17 -> V_2 [ V_2 ] . V_28 ) ;
return V_40 ;
}
static void
F_27 ( struct V_41 * V_42 , struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
F_28 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_4 . V_37 )
F_29 ( V_2 -> V_4 . V_37 , V_17 ) ;
if ( F_30 ( V_2 -> V_35 ) ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ )
F_22 ( V_2 -> V_3 [ V_2 -> V_4 . V_5 ] ) ;
}
}
static void
F_31 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
int V_43 ;
F_32 ( V_44 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ )
if ( F_33 ( V_43 ) || F_30 ( V_43 ) )
F_27 ( V_42 , & V_17 -> V_2 [ V_43 ] ) ;
}
static int
F_34 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
int V_43 ;
F_35 ( V_44 ) ;
switch ( V_17 -> V_46 -> V_47 ) {
case V_48 :
F_36 ( V_49 ,
V_50 , V_51 ) ;
break;
case V_52 :
F_36 ( V_49 ,
V_53 , V_51 ) ;
break;
default:
F_10 ( V_42 , L_2 ,
V_17 -> V_46 -> V_47 ) ;
return - V_54 ;
}
F_37 ( V_55 , V_56 ) ;
F_38 ( V_57 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
int V_37 = V_39 + V_43 ;
struct V_1 * V_2 = & V_17 -> V_2 [ V_43 ] ;
V_2 -> V_35 = V_2 -> V_4 . V_58 = V_43 ;
if ( F_33 ( V_43 ) ) {
F_39 ( & V_2 -> V_4 ) ;
F_40 ( V_37 , F_25 , 0 , L_3 , V_17 ) ;
} else if ( F_30 ( V_43 ) ) {
F_41 ( & V_2 -> V_4 ) ;
for ( V_2 -> V_4 . V_5 = 0 ; V_2 -> V_4 . V_5 < V_25 ;
V_2 -> V_4 . V_5 ++ )
if ( F_1 ( V_2 ) )
return - V_8 ;
V_2 -> V_4 . V_5 = 0 ;
F_40 ( V_37 , F_25 , 0 , L_4 , V_17 ) ;
}
V_2 -> V_4 . V_37 = V_37 ;
}
return 0 ;
}
static void
F_42 ( struct V_41 * V_42 , struct V_59 * V_60 )
{
F_43 ( V_60 -> V_61 , L_5 , sizeof( V_60 -> V_61 ) ) ;
F_43 ( V_60 -> V_62 , L_6 , sizeof( V_60 -> V_62 ) ) ;
F_43 ( V_60 -> V_63 , V_64 , sizeof( V_60 -> V_63 ) ) ;
}
static int
F_44 ( struct V_41 * V_42 , struct V_65 * V_66 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
return F_45 ( V_17 -> V_67 , V_66 ) ;
}
static int
F_46 ( struct V_41 * V_42 , struct V_65 * V_66 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
return F_47 ( V_17 -> V_67 , V_66 ) ;
}
static int
F_48 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
return F_49 ( V_17 -> V_67 ) ;
}
static int
F_50 ( struct V_68 * V_69 , int V_70 , int V_71 , T_2 V_72 )
{
T_3 V_73 = V_74 |
( ( V_70 & V_75 ) << V_76 ) |
( ( V_71 & V_77 ) << V_78 ) |
V_72 ;
while ( F_51 ( V_79 ) & V_74 )
;
F_37 ( V_73 , V_79 ) ;
return 0 ;
}
static int
F_52 ( struct V_68 * V_69 , int V_70 , int V_71 )
{
T_3 V_73 = V_74 | V_80 |
( ( V_70 & V_75 ) << V_76 ) |
( ( V_71 & V_77 ) << V_78 ) ;
while ( F_51 ( V_79 ) & V_74 )
;
F_37 ( V_73 , V_79 ) ;
while ( F_51 ( V_79 ) & V_74 )
;
V_73 = F_51 ( V_79 ) & V_81 ;
return V_73 ;
}
static void
F_53 ( struct V_41 * V_42 )
{
}
static int
F_54 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
struct V_82 * V_67 = NULL ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_83 ; V_70 ++ ) {
if ( V_17 -> V_68 -> V_84 [ V_70 ] ) {
V_67 = V_17 -> V_68 -> V_84 [ V_70 ] ;
break;
}
}
if ( ! V_67 ) {
F_10 ( V_42 , L_7 ) ;
return - V_85 ;
}
V_67 = F_55 ( V_42 , F_56 ( & V_67 -> V_42 ) ,
& F_53 , V_17 -> V_46 -> V_47 ) ;
if ( F_57 ( V_67 ) ) {
F_10 ( V_42 , L_8 ) ;
return F_58 ( V_67 ) ;
}
V_67 -> V_86 &= ( V_87
| V_88
| V_89
| V_90
| V_91
| V_92
| V_93 ) ;
V_67 -> V_94 = V_67 -> V_86 ;
V_17 -> V_67 = V_67 ;
F_59 ( L_9 ,
V_42 -> V_95 , V_67 -> V_96 -> V_95 ,
F_56 ( & V_67 -> V_42 ) , V_67 -> V_37 ) ;
return 0 ;
}
static int
F_60 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
int V_43 ;
int V_97 ;
V_17 -> V_68 = F_61 () ;
if ( ! V_17 -> V_68 ) {
F_10 ( V_42 , L_10 ) ;
V_97 = - V_8 ;
goto V_98;
}
V_17 -> V_68 -> V_17 = V_42 ;
V_17 -> V_68 -> V_99 = F_52 ;
V_17 -> V_68 -> V_100 = F_50 ;
V_17 -> V_68 -> V_95 = L_11 ;
snprintf ( V_17 -> V_68 -> V_101 , V_102 , L_12 ,
V_17 -> V_103 -> V_95 , V_17 -> V_103 -> V_101 ) ;
V_17 -> V_68 -> V_37 = F_62 ( sizeof( int ) * V_83 , V_104 ) ;
if ( ! V_17 -> V_68 -> V_37 ) {
V_97 = - V_8 ;
goto V_105;
}
for ( V_43 = 0 ; V_43 < V_83 ; ++ V_43 )
V_17 -> V_68 -> V_37 [ V_43 ] = V_106 ;
if ( F_63 ( V_17 -> V_68 ) ) {
V_97 = - V_107 ;
goto V_108;
}
if ( F_54 ( V_42 ) ) {
V_97 = - V_107 ;
goto V_109;
}
return 0 ;
V_109:
F_64 ( V_17 -> V_68 ) ;
V_108:
F_65 ( V_17 -> V_68 -> V_37 ) ;
V_105:
F_66 ( V_17 -> V_68 ) ;
V_98:
return V_97 ;
}
static void
F_67 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
F_68 ( V_17 -> V_67 ) ;
F_64 ( V_17 -> V_68 ) ;
F_65 ( V_17 -> V_68 -> V_37 ) ;
F_66 ( V_17 -> V_68 ) ;
}
static int
F_69 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_1 * V_2 = & V_17 -> V_2 [ V_43 ] ;
if ( ! F_33 ( V_43 ) && ( ! F_30 ( V_43 ) ) )
continue;
F_70 ( & V_2 -> V_4 ) ;
F_71 ( & V_2 -> V_28 ) ;
}
F_72 ( V_17 -> V_67 ) ;
F_73 ( V_42 ) ;
return 0 ;
}
static int
F_74 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
int V_43 ;
F_75 ( V_42 ) ;
F_76 ( V_17 -> V_67 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_1 * V_2 = & V_17 -> V_2 [ V_43 ] ;
if ( ! F_30 ( V_43 ) && ! F_33 ( V_43 ) )
continue;
F_77 ( & V_2 -> V_28 ) ;
F_11 ( & V_2 -> V_4 ) ;
}
return 0 ;
}
static int
F_78 ( struct V_19 * V_3 , struct V_41 * V_42 )
{
int V_110 = F_79 ( V_3 ) ;
struct V_33 * V_34 = F_21 ( V_42 , V_110 ) ;
struct V_16 * V_17 = F_8 ( V_42 ) ;
struct V_1 * V_2 = & V_17 -> V_2 [ ( V_110 << 1 ) | 1 ] ;
struct V_18 * V_5 = & V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] ;
int V_20 ;
unsigned long V_23 ;
T_3 V_111 ;
V_20 = V_3 -> V_20 < V_112 ? V_112 : V_3 -> V_20 ;
if ( ( V_5 -> V_13 & ( V_14 | V_32 ) ) || V_2 -> V_3 [ V_2 -> V_4 . V_5 ] ) {
F_22 ( V_3 ) ;
F_10 ( V_42 , L_13 ) ;
F_80 ( V_34 ) ;
return V_113 ;
}
V_111 = F_4 ( V_3 -> V_11 ) % 16 ;
V_2 -> V_3 [ V_2 -> V_4 . V_5 ] = V_3 ;
V_42 -> V_114 = V_115 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
V_5 -> V_10 = ( ( unsigned int ) F_3 ( NULL , V_3 -> V_11 , V_20 ,
V_116 ) ) - V_111 ;
F_81 () ;
V_5 -> V_13 = V_14 | V_117 | V_118 |
F_82 ( V_111 ) | ( V_20 & V_21 ) ;
V_2 -> V_4 . V_5 ++ ;
V_2 -> V_4 . V_5 %= V_25 ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
if ( V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] . V_13 & V_14 )
F_80 ( V_34 ) ;
return V_119 ;
}
static int
F_83 ( struct V_41 * V_42 , int V_120 )
{
int V_121 = F_84 ( V_42 , V_120 ) ;
if ( ! V_121 ) {
struct V_16 * V_17 = F_8 ( V_42 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
F_37 ( ( V_122 << 16 ) | V_120 ,
V_123 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
return V_121 ;
}
static int
F_85 ( struct V_41 * V_42 , struct V_124 * V_125 , int V_66 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
return F_86 ( V_17 -> V_67 , V_125 , V_66 ) ;
}
static int
F_87 ( struct V_41 * V_42 , void * V_126 )
{
int V_121 = F_88 ( V_42 , V_126 ) ;
if ( ! V_121 ) {
struct V_16 * V_17 = F_8 ( V_42 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
F_37 ( * ( ( T_3 * ) V_42 -> V_127 ) , V_128 ) ;
F_37 ( * ( ( T_2 * ) & V_42 -> V_127 [ 4 ] ) << 16 ,
V_129 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
return V_121 ;
}
static void
F_89 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
if ( ( V_42 -> V_23 & V_130 ) || ( V_42 -> V_23 & V_131 ) )
F_36 ( V_132 , 0 , V_133 ) ;
else
F_36 ( 0 , V_132 , V_133 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
static T_2
F_90 ( struct V_41 * V_42 , struct V_19 * V_3 ,
void * V_134 , T_4 V_135 )
{
return 0 ;
}
static int
F_91 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
struct V_136 V_137 ;
int V_97 ;
bool V_138 = false ;
F_92 ( V_42 ) ;
V_42 -> V_139 = 10 * V_140 ;
V_97 = F_34 ( V_42 ) ;
if ( V_97 )
goto V_141;
F_83 ( V_42 , 1500 ) ;
memcpy ( & V_137 , & V_17 -> V_46 -> V_137 , sizeof( struct V_136 ) ) ;
if ( ! F_93 ( V_137 . V_142 ) ) {
F_94 ( L_14 ) ;
F_95 ( V_137 . V_142 ) ;
V_138 = true ;
}
V_97 = F_87 ( V_42 , & V_137 ) ;
if ( V_97 )
goto V_143;
if ( V_138 )
V_42 -> V_144 = V_145 ;
F_89 ( V_42 ) ;
V_97 = F_60 ( V_42 ) ;
if ( V_97 )
goto V_143;
return 0 ;
V_143:
F_96 ( V_42 ) ;
F_97 ( V_42 ) ;
V_141:
F_31 ( V_42 ) ;
return V_97 ;
}
static void
F_98 ( struct V_41 * V_42 )
{
int V_97 ;
F_31 ( V_42 ) ;
V_97 = F_34 ( V_42 ) ;
if ( V_97 )
goto V_141;
V_42 -> V_114 = V_115 ;
F_99 ( V_42 ) ;
return;
V_141:
F_31 ( V_42 ) ;
F_10 ( V_42 , L_15 ) ;
}
static int T_5
F_100 ( struct V_146 * V_103 )
{
struct V_41 * V_42 ;
struct V_16 * V_17 ;
struct V_147 * V_148 ;
int V_97 ;
int V_43 ;
V_148 = F_101 ( V_103 , V_149 , 0 ) ;
if ( ! V_148 ) {
F_102 ( & V_103 -> V_42 , L_16 ) ;
V_97 = - V_150 ;
goto V_98;
}
V_148 = F_103 ( & V_103 -> V_42 , V_148 -> V_151 ,
F_104 ( V_148 ) , F_56 ( & V_103 -> V_42 ) ) ;
if ( ! V_148 ) {
F_102 ( & V_103 -> V_42 , L_17 ) ;
V_97 = - V_152 ;
goto V_98;
}
V_153 = F_105 ( & V_103 -> V_42 ,
V_148 -> V_151 , F_104 ( V_148 ) ) ;
if ( ! V_153 ) {
F_102 ( & V_103 -> V_42 , L_18 ,
V_103 -> V_101 ) ;
V_97 = - V_8 ;
goto V_98;
}
V_42 = F_106 ( sizeof( struct V_16 ) , 4 ) ;
if ( ! V_42 ) {
V_97 = - V_8 ;
goto V_98;
}
strcpy ( V_42 -> V_95 , L_19 ) ;
V_42 -> V_154 = & V_155 ;
V_42 -> V_156 = & V_157 ;
V_17 = F_8 ( V_42 ) ;
V_17 -> V_148 = V_148 ;
V_17 -> V_103 = V_103 ;
V_17 -> V_46 = F_107 ( & V_103 -> V_42 ) ;
V_17 -> V_6 = V_42 ;
F_108 ( & V_17 -> V_24 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
if ( F_33 ( V_43 ) )
F_109 ( V_42 , & V_17 -> V_2 [ V_43 ] . V_28 ,
F_20 , 8 ) ;
else if ( F_30 ( V_43 ) )
F_109 ( V_42 , & V_17 -> V_2 [ V_43 ] . V_28 ,
F_16 , 32 ) ;
V_17 -> V_2 [ V_43 ] . V_6 = V_42 ;
}
V_97 = F_110 ( V_42 ) ;
if ( V_97 )
goto V_158;
F_111 ( V_103 , V_42 ) ;
return 0 ;
V_158:
F_97 ( V_42 ) ;
V_98:
return V_97 ;
}
static int
F_112 ( struct V_146 * V_103 )
{
struct V_41 * V_42 = F_113 ( V_103 ) ;
if ( V_42 ) {
F_75 ( V_42 ) ;
F_31 ( V_42 ) ;
F_67 ( V_42 ) ;
F_96 ( V_42 ) ;
}
return 0 ;
}
int T_5
F_114 ( void )
{
int V_121 = F_115 ( & V_159 , F_100 ) ;
if ( V_121 )
F_116 ( L_20 ) ;
return V_121 ;
}
static void T_6
F_117 ( void )
{
F_118 ( & V_159 ) ;
}
