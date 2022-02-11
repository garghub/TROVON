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
V_3 -> V_26 = V_2 -> V_6 ;
V_3 -> V_27 = F_14 ( V_3 , V_2 -> V_6 ) ;
F_15 ( V_3 ) ;
}
static int
F_16 ( struct V_28 * V_29 , int V_30 )
{
struct V_1 * V_2 = F_17 ( V_29 ,
struct V_1 , V_29 ) ;
int V_31 = 0 ;
int V_32 = 0 ;
while ( ( V_31 < V_30 ) && ! V_32 ) {
struct V_18 * V_5 = & V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] ;
if ( ( V_5 -> V_13 & ( V_14 | V_33 ) ) == V_33 ) {
F_7 ( V_2 ) ;
V_31 ++ ;
} else {
V_32 = 1 ;
}
}
if ( V_32 || ! V_31 ) {
F_18 ( & V_2 -> V_29 ) ;
F_19 ( & V_2 -> V_4 ) ;
}
return V_31 ;
}
static int
F_20 ( struct V_28 * V_29 , int V_30 )
{
struct V_1 * V_2 =
F_17 ( V_29 , struct V_1 , V_29 ) ;
struct V_16 * V_17 = F_8 ( V_2 -> V_6 ) ;
struct V_34 * V_35 =
F_21 ( V_2 -> V_6 , V_2 -> V_36 >> 1 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
while ( ( V_2 -> V_4 . V_9 [ V_2 -> V_37 ] . V_13 &
( V_14 | V_33 ) ) == V_33 ) {
F_22 ( V_2 -> V_3 [ V_2 -> V_37 ] ) ;
V_2 -> V_3 [ V_2 -> V_37 ] = NULL ;
memset ( & V_2 -> V_4 . V_9 [ V_2 -> V_37 ] , 0 ,
sizeof( struct V_18 ) ) ;
V_2 -> V_37 ++ ;
V_2 -> V_37 %= V_25 ;
}
F_12 ( & V_17 -> V_24 , V_23 ) ;
if ( F_23 ( V_35 ) )
F_24 ( V_35 ) ;
F_18 ( & V_2 -> V_29 ) ;
F_19 ( & V_2 -> V_4 ) ;
return 1 ;
}
static T_1
F_25 ( int V_38 , void * V_39 )
{
struct V_16 * V_17 = V_39 ;
int V_2 = V_38 - V_40 ;
F_26 ( & V_17 -> V_2 [ V_2 ] . V_29 ) ;
return V_41 ;
}
static void
F_27 ( struct V_42 * V_26 , struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
F_28 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_4 . V_38 )
F_29 ( V_2 -> V_4 . V_38 , V_17 ) ;
if ( F_30 ( V_2 -> V_36 ) ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ )
F_22 ( V_2 -> V_3 [ V_2 -> V_4 . V_5 ] ) ;
}
}
static void
F_31 ( struct V_42 * V_26 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
int V_43 ;
F_32 ( V_44 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ )
if ( F_33 ( V_43 ) || F_30 ( V_43 ) )
F_27 ( V_26 , & V_17 -> V_2 [ V_43 ] ) ;
}
static int
F_34 ( struct V_42 * V_26 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
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
F_10 ( V_26 , L_2 ,
V_17 -> V_46 -> V_47 ) ;
return - V_54 ;
}
F_37 ( V_55 , V_56 ) ;
F_38 ( V_57 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
int V_38 = V_40 + V_43 ;
struct V_1 * V_2 = & V_17 -> V_2 [ V_43 ] ;
V_2 -> V_36 = V_2 -> V_4 . V_58 = V_43 ;
if ( F_33 ( V_43 ) ) {
F_39 ( & V_2 -> V_4 ) ;
F_40 ( V_38 , F_25 , V_59 ,
L_3 , V_17 ) ;
} else if ( F_30 ( V_43 ) ) {
F_41 ( & V_2 -> V_4 ) ;
for ( V_2 -> V_4 . V_5 = 0 ; V_2 -> V_4 . V_5 < V_25 ;
V_2 -> V_4 . V_5 ++ )
if ( F_1 ( V_2 ) )
return - V_8 ;
V_2 -> V_4 . V_5 = 0 ;
F_40 ( V_38 , F_25 , V_59 ,
L_4 , V_17 ) ;
}
V_2 -> V_4 . V_38 = V_38 ;
}
return 0 ;
}
static void
F_42 ( struct V_42 * V_26 , struct V_60 * V_61 )
{
strcpy ( V_61 -> V_62 , L_5 ) ;
strcpy ( V_61 -> V_63 , L_6 ) ;
strcpy ( V_61 -> V_64 , V_65 ) ;
}
static int
F_43 ( struct V_42 * V_26 , struct V_66 * V_67 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
return F_44 ( V_17 -> V_68 , V_67 ) ;
}
static int
F_45 ( struct V_42 * V_26 , struct V_66 * V_67 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
return F_46 ( V_17 -> V_68 , V_67 ) ;
}
static int
F_47 ( struct V_42 * V_26 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
return F_48 ( V_17 -> V_68 ) ;
}
static int
F_49 ( struct V_69 * V_70 , int V_71 , int V_72 , T_2 V_73 )
{
T_3 V_74 = V_75 |
( ( V_71 & V_76 ) << V_77 ) |
( ( V_72 & V_78 ) << V_79 ) |
V_73 ;
while ( F_50 ( V_80 ) & V_75 )
;
F_37 ( V_74 , V_80 ) ;
return 0 ;
}
static int
F_51 ( struct V_69 * V_70 , int V_71 , int V_72 )
{
T_3 V_74 = V_75 | V_81 |
( ( V_71 & V_76 ) << V_77 ) |
( ( V_72 & V_78 ) << V_79 ) ;
while ( F_50 ( V_80 ) & V_75 )
;
F_37 ( V_74 , V_80 ) ;
while ( F_50 ( V_80 ) & V_75 )
;
V_74 = F_50 ( V_80 ) & V_82 ;
return V_74 ;
}
static void
F_52 ( struct V_42 * V_26 )
{
}
static int
F_53 ( struct V_42 * V_26 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
struct V_83 * V_68 = NULL ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_84 ; V_71 ++ ) {
if ( V_17 -> V_69 -> V_85 [ V_71 ] ) {
V_68 = V_17 -> V_69 -> V_85 [ V_71 ] ;
break;
}
}
if ( ! V_68 ) {
F_10 ( V_26 , L_7 ) ;
return - V_86 ;
}
V_68 = F_54 ( V_26 , F_55 ( & V_68 -> V_26 ) , & F_52 ,
0 , V_17 -> V_46 -> V_47 ) ;
if ( F_56 ( V_68 ) ) {
F_10 ( V_26 , L_8 ) ;
return F_57 ( V_68 ) ;
}
V_68 -> V_87 &= ( V_88
| V_89
| V_90
| V_91
| V_92
| V_93
| V_94 ) ;
V_68 -> V_95 = V_68 -> V_87 ;
V_17 -> V_68 = V_68 ;
F_58 ( L_9 ,
V_26 -> V_96 , V_68 -> V_97 -> V_96 ,
F_55 ( & V_68 -> V_26 ) , V_68 -> V_38 ) ;
return 0 ;
}
static int
F_59 ( struct V_42 * V_26 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
int V_43 ;
int V_98 ;
V_17 -> V_69 = F_60 () ;
if ( ! V_17 -> V_69 ) {
F_10 ( V_26 , L_10 ) ;
V_98 = - V_8 ;
goto V_99;
}
V_17 -> V_69 -> V_17 = V_26 ;
V_17 -> V_69 -> V_100 = F_51 ;
V_17 -> V_69 -> V_101 = F_49 ;
V_17 -> V_69 -> V_96 = L_11 ;
snprintf ( V_17 -> V_69 -> V_102 , V_103 , L_12 ,
V_17 -> V_104 -> V_96 , V_17 -> V_104 -> V_102 ) ;
V_17 -> V_69 -> V_38 = F_61 ( sizeof( int ) * V_84 , V_105 ) ;
if ( ! V_17 -> V_69 -> V_38 ) {
V_98 = - V_8 ;
goto V_106;
}
for ( V_43 = 0 ; V_43 < V_84 ; ++ V_43 )
V_17 -> V_69 -> V_38 [ V_43 ] = V_107 ;
if ( F_62 ( V_17 -> V_69 ) ) {
V_98 = - V_108 ;
goto V_109;
}
if ( F_53 ( V_26 ) ) {
V_98 = - V_108 ;
goto V_110;
}
return 0 ;
V_110:
F_63 ( V_17 -> V_69 ) ;
V_109:
F_64 ( V_17 -> V_69 -> V_38 ) ;
V_106:
F_65 ( V_17 -> V_69 ) ;
V_99:
return V_98 ;
}
static void
F_66 ( struct V_42 * V_26 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
F_67 ( V_17 -> V_68 ) ;
F_63 ( V_17 -> V_69 ) ;
F_64 ( V_17 -> V_69 -> V_38 ) ;
F_65 ( V_17 -> V_69 ) ;
}
static int
F_68 ( struct V_42 * V_26 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_1 * V_2 = & V_17 -> V_2 [ V_43 ] ;
if ( ! F_33 ( V_43 ) && ( ! F_30 ( V_43 ) ) )
continue;
F_69 ( & V_2 -> V_4 ) ;
F_70 ( & V_2 -> V_29 ) ;
}
F_71 ( V_17 -> V_68 ) ;
F_72 ( V_26 ) ;
return 0 ;
}
static int
F_73 ( struct V_42 * V_26 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
int V_43 ;
F_74 ( V_26 ) ;
F_75 ( V_17 -> V_68 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_1 * V_2 = & V_17 -> V_2 [ V_43 ] ;
if ( ! F_30 ( V_43 ) && ! F_33 ( V_43 ) )
continue;
F_76 ( & V_2 -> V_29 ) ;
F_11 ( & V_2 -> V_4 ) ;
}
return 0 ;
}
static int
F_77 ( struct V_19 * V_3 , struct V_42 * V_26 )
{
int V_111 = F_78 ( V_3 ) ;
struct V_34 * V_35 = F_21 ( V_26 , V_111 ) ;
struct V_16 * V_17 = F_8 ( V_26 ) ;
struct V_1 * V_2 = & V_17 -> V_2 [ ( V_111 << 1 ) | 1 ] ;
struct V_18 * V_5 = & V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] ;
int V_20 ;
unsigned long V_23 ;
T_3 V_112 ;
V_20 = V_3 -> V_20 < V_113 ? V_113 : V_3 -> V_20 ;
if ( ( V_5 -> V_13 & ( V_14 | V_33 ) ) || V_2 -> V_3 [ V_2 -> V_4 . V_5 ] ) {
F_22 ( V_3 ) ;
F_10 ( V_26 , L_13 ) ;
F_79 ( V_35 ) ;
return V_114 ;
}
V_112 = F_4 ( V_3 -> V_11 ) % 16 ;
V_2 -> V_3 [ V_2 -> V_4 . V_5 ] = V_3 ;
V_26 -> V_115 = V_116 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
V_5 -> V_10 = ( ( unsigned int ) F_3 ( NULL , V_3 -> V_11 , V_20 ,
V_117 ) ) - V_112 ;
F_80 () ;
V_5 -> V_13 = V_14 | V_118 | V_119 |
F_81 ( V_112 ) | ( V_20 & V_21 ) ;
V_2 -> V_4 . V_5 ++ ;
V_2 -> V_4 . V_5 %= V_25 ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
if ( V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] . V_13 & V_14 )
F_79 ( V_35 ) ;
return V_120 ;
}
static int
F_82 ( struct V_42 * V_26 , int V_121 )
{
int V_122 = F_83 ( V_26 , V_121 ) ;
if ( ! V_122 ) {
struct V_16 * V_17 = F_8 ( V_26 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
F_37 ( ( V_123 << 16 ) | V_121 ,
V_124 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
return V_122 ;
}
static int
F_84 ( struct V_42 * V_26 , struct V_125 * V_126 , int V_67 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
return F_85 ( V_17 -> V_68 , V_126 , V_67 ) ;
}
static int
F_86 ( struct V_42 * V_26 , void * V_127 )
{
int V_122 = F_87 ( V_26 , V_127 ) ;
if ( ! V_122 ) {
struct V_16 * V_17 = F_8 ( V_26 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
F_37 ( * ( ( T_3 * ) V_26 -> V_128 ) , V_129 ) ;
F_37 ( * ( ( T_2 * ) & V_26 -> V_128 [ 4 ] ) << 16 ,
V_130 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
return V_122 ;
}
static void
F_88 ( struct V_42 * V_26 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
if ( ( V_26 -> V_23 & V_131 ) || ( V_26 -> V_23 & V_132 ) )
F_36 ( V_133 , 0 , V_134 ) ;
else
F_36 ( 0 , V_133 , V_134 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
static T_2
F_89 ( struct V_42 * V_26 , struct V_19 * V_3 )
{
return 0 ;
}
static int
F_90 ( struct V_42 * V_26 )
{
struct V_16 * V_17 = F_8 ( V_26 ) ;
struct V_135 V_136 ;
int V_98 ;
bool V_137 = false ;
F_91 ( V_26 ) ;
V_26 -> V_138 = 10 * V_139 ;
V_98 = F_34 ( V_26 ) ;
if ( V_98 )
goto V_140;
F_82 ( V_26 , 1500 ) ;
memcpy ( & V_136 , & V_17 -> V_46 -> V_136 , sizeof( struct V_135 ) ) ;
if ( ! F_92 ( V_136 . V_141 ) ) {
F_93 ( L_14 ) ;
F_94 ( V_136 . V_141 ) ;
V_137 = true ;
}
V_98 = F_86 ( V_26 , & V_136 ) ;
if ( V_98 )
goto V_142;
if ( V_137 )
V_26 -> V_143 |= V_144 ;
F_88 ( V_26 ) ;
V_98 = F_59 ( V_26 ) ;
if ( V_98 )
goto V_142;
return 0 ;
V_142:
F_95 ( V_26 ) ;
F_96 ( V_26 ) ;
V_140:
F_31 ( V_26 ) ;
return V_98 ;
}
static void
F_97 ( struct V_42 * V_26 )
{
int V_98 ;
F_31 ( V_26 ) ;
V_98 = F_34 ( V_26 ) ;
if ( V_98 )
goto V_140;
V_26 -> V_115 = V_116 ;
F_98 ( V_26 ) ;
return;
V_140:
F_31 ( V_26 ) ;
F_10 ( V_26 , L_15 ) ;
}
static int T_4
F_99 ( struct V_145 * V_104 )
{
struct V_42 * V_26 ;
struct V_16 * V_17 ;
struct V_146 * V_147 ;
int V_98 ;
int V_43 ;
V_147 = F_100 ( V_104 , V_148 , 0 ) ;
if ( ! V_147 ) {
F_101 ( & V_104 -> V_26 , L_16 ) ;
V_98 = - V_149 ;
goto V_99;
}
V_147 = F_102 ( & V_104 -> V_26 , V_147 -> V_150 ,
F_103 ( V_147 ) , F_55 ( & V_104 -> V_26 ) ) ;
if ( ! V_147 ) {
F_101 ( & V_104 -> V_26 , L_17 ) ;
V_98 = - V_151 ;
goto V_99;
}
V_152 = F_104 ( & V_104 -> V_26 ,
V_147 -> V_150 , F_103 ( V_147 ) ) ;
if ( ! V_152 ) {
F_101 ( & V_104 -> V_26 , L_18 ,
V_104 -> V_102 ) ;
V_98 = - V_8 ;
goto V_99;
}
V_26 = F_105 ( sizeof( struct V_16 ) , 4 ) ;
if ( ! V_26 ) {
V_98 = - V_8 ;
goto V_99;
}
strcpy ( V_26 -> V_96 , L_19 ) ;
V_26 -> V_153 = & V_154 ;
V_26 -> V_155 = & V_156 ;
V_17 = F_8 ( V_26 ) ;
V_17 -> V_147 = V_147 ;
V_17 -> V_104 = V_104 ;
V_17 -> V_46 = F_106 ( & V_104 -> V_26 ) ;
V_17 -> V_6 = V_26 ;
F_107 ( & V_17 -> V_24 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
if ( F_33 ( V_43 ) )
F_108 ( V_26 , & V_17 -> V_2 [ V_43 ] . V_29 ,
F_20 , 8 ) ;
else if ( F_30 ( V_43 ) )
F_108 ( V_26 , & V_17 -> V_2 [ V_43 ] . V_29 ,
F_16 , 32 ) ;
V_17 -> V_2 [ V_43 ] . V_6 = V_26 ;
}
V_98 = F_109 ( V_26 ) ;
if ( V_98 )
goto V_157;
F_110 ( V_104 , V_26 ) ;
return 0 ;
V_157:
F_64 ( V_26 ) ;
V_99:
return V_98 ;
}
static int T_5
F_111 ( struct V_145 * V_104 )
{
struct V_42 * V_26 = F_112 ( V_104 ) ;
if ( V_26 ) {
F_74 ( V_26 ) ;
F_31 ( V_26 ) ;
F_66 ( V_26 ) ;
F_95 ( V_26 ) ;
}
return 0 ;
}
int T_4
F_113 ( void )
{
int V_122 = F_114 ( & V_158 , F_99 ) ;
if ( V_122 )
F_115 ( L_20 ) ;
return V_122 ;
}
static void T_6
F_116 ( void )
{
F_117 ( & V_158 ) ;
}
