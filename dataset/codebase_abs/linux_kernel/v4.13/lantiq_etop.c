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
while ( V_30 < V_29 ) {
struct V_18 * V_5 = & V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] ;
if ( ( V_5 -> V_13 & ( V_14 | V_31 ) ) != V_31 )
break;
F_7 ( V_2 ) ;
V_30 ++ ;
}
if ( V_30 < V_29 ) {
F_18 ( & V_2 -> V_28 , V_30 ) ;
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
struct V_32 * V_33 =
F_21 ( V_2 -> V_6 , V_2 -> V_34 >> 1 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
while ( ( V_2 -> V_4 . V_9 [ V_2 -> V_35 ] . V_13 &
( V_14 | V_31 ) ) == V_31 ) {
F_22 ( V_2 -> V_3 [ V_2 -> V_35 ] ) ;
V_2 -> V_3 [ V_2 -> V_35 ] = NULL ;
memset ( & V_2 -> V_4 . V_9 [ V_2 -> V_35 ] , 0 ,
sizeof( struct V_18 ) ) ;
V_2 -> V_35 ++ ;
V_2 -> V_35 %= V_25 ;
}
F_12 ( & V_17 -> V_24 , V_23 ) ;
if ( F_23 ( V_33 ) )
F_24 ( V_33 ) ;
F_25 ( & V_2 -> V_28 ) ;
F_19 ( & V_2 -> V_4 ) ;
return 1 ;
}
static T_1
F_26 ( int V_36 , void * V_37 )
{
struct V_16 * V_17 = V_37 ;
int V_2 = V_36 - V_38 ;
F_27 ( & V_17 -> V_2 [ V_2 ] . V_28 ) ;
return V_39 ;
}
static void
F_28 ( struct V_40 * V_41 , struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_41 ) ;
F_29 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_4 . V_36 )
F_30 ( V_2 -> V_4 . V_36 , V_17 ) ;
if ( F_31 ( V_2 -> V_34 ) ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ )
F_22 ( V_2 -> V_3 [ V_2 -> V_4 . V_5 ] ) ;
}
}
static void
F_32 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = F_8 ( V_41 ) ;
int V_42 ;
F_33 ( V_43 ) ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ )
if ( F_34 ( V_42 ) || F_31 ( V_42 ) )
F_28 ( V_41 , & V_17 -> V_2 [ V_42 ] ) ;
}
static int
F_35 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = F_8 ( V_41 ) ;
int V_42 ;
F_36 ( V_43 ) ;
switch ( V_17 -> V_45 -> V_46 ) {
case V_47 :
F_37 ( V_48 ,
V_49 , V_50 ) ;
break;
case V_51 :
F_37 ( V_48 ,
V_52 , V_50 ) ;
break;
default:
F_10 ( V_41 , L_2 ,
V_17 -> V_45 -> V_46 ) ;
return - V_53 ;
}
F_38 ( V_54 , V_55 ) ;
F_39 ( V_56 ) ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
int V_36 = V_38 + V_42 ;
struct V_1 * V_2 = & V_17 -> V_2 [ V_42 ] ;
V_2 -> V_34 = V_2 -> V_4 . V_57 = V_42 ;
if ( F_34 ( V_42 ) ) {
F_40 ( & V_2 -> V_4 ) ;
F_41 ( V_36 , F_26 , 0 , L_3 , V_17 ) ;
} else if ( F_31 ( V_42 ) ) {
F_42 ( & V_2 -> V_4 ) ;
for ( V_2 -> V_4 . V_5 = 0 ; V_2 -> V_4 . V_5 < V_25 ;
V_2 -> V_4 . V_5 ++ )
if ( F_1 ( V_2 ) )
return - V_8 ;
V_2 -> V_4 . V_5 = 0 ;
F_41 ( V_36 , F_26 , 0 , L_4 , V_17 ) ;
}
V_2 -> V_4 . V_36 = V_36 ;
}
return 0 ;
}
static void
F_43 ( struct V_40 * V_41 , struct V_58 * V_59 )
{
F_44 ( V_59 -> V_60 , L_5 , sizeof( V_59 -> V_60 ) ) ;
F_44 ( V_59 -> V_61 , L_6 , sizeof( V_59 -> V_61 ) ) ;
F_44 ( V_59 -> V_62 , V_63 , sizeof( V_59 -> V_62 ) ) ;
}
static int
F_45 ( struct V_64 * V_65 , int V_66 , int V_67 , T_2 V_68 )
{
T_3 V_69 = V_70 |
( ( V_66 & V_71 ) << V_72 ) |
( ( V_67 & V_73 ) << V_74 ) |
V_68 ;
while ( F_46 ( V_75 ) & V_70 )
;
F_38 ( V_69 , V_75 ) ;
return 0 ;
}
static int
F_47 ( struct V_64 * V_65 , int V_66 , int V_67 )
{
T_3 V_69 = V_70 | V_76 |
( ( V_66 & V_71 ) << V_72 ) |
( ( V_67 & V_73 ) << V_74 ) ;
while ( F_46 ( V_75 ) & V_70 )
;
F_38 ( V_69 , V_75 ) ;
while ( F_46 ( V_75 ) & V_70 )
;
V_69 = F_46 ( V_75 ) & V_77 ;
return V_69 ;
}
static void
F_48 ( struct V_40 * V_41 )
{
}
static int
F_49 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = F_8 ( V_41 ) ;
struct V_78 * V_79 ;
V_79 = F_50 ( V_17 -> V_64 ) ;
if ( ! V_79 ) {
F_10 ( V_41 , L_7 ) ;
return - V_80 ;
}
V_79 = F_51 ( V_41 , F_52 ( V_79 ) ,
& F_48 , V_17 -> V_45 -> V_46 ) ;
if ( F_53 ( V_79 ) ) {
F_10 ( V_41 , L_8 ) ;
return F_54 ( V_79 ) ;
}
V_79 -> V_81 &= ( V_82
| V_83
| V_84
| V_85
| V_86
| V_87
| V_88 ) ;
V_79 -> V_89 = V_79 -> V_81 ;
F_55 ( V_79 ) ;
return 0 ;
}
static int
F_56 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = F_8 ( V_41 ) ;
int V_90 ;
V_17 -> V_64 = F_57 () ;
if ( ! V_17 -> V_64 ) {
F_10 ( V_41 , L_9 ) ;
V_90 = - V_8 ;
goto V_91;
}
V_17 -> V_64 -> V_17 = V_41 ;
V_17 -> V_64 -> V_92 = F_47 ;
V_17 -> V_64 -> V_93 = F_45 ;
V_17 -> V_64 -> V_94 = L_10 ;
snprintf ( V_17 -> V_64 -> V_95 , V_96 , L_11 ,
V_17 -> V_97 -> V_94 , V_17 -> V_97 -> V_95 ) ;
if ( F_58 ( V_17 -> V_64 ) ) {
V_90 = - V_98 ;
goto V_99;
}
if ( F_49 ( V_41 ) ) {
V_90 = - V_98 ;
goto V_100;
}
return 0 ;
V_100:
F_59 ( V_17 -> V_64 ) ;
V_99:
F_60 ( V_17 -> V_64 ) ;
V_91:
return V_90 ;
}
static void
F_61 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = F_8 ( V_41 ) ;
F_62 ( V_41 -> V_79 ) ;
F_59 ( V_17 -> V_64 ) ;
F_60 ( V_17 -> V_64 ) ;
}
static int
F_63 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = F_8 ( V_41 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
struct V_1 * V_2 = & V_17 -> V_2 [ V_42 ] ;
if ( ! F_34 ( V_42 ) && ( ! F_31 ( V_42 ) ) )
continue;
F_64 ( & V_2 -> V_4 ) ;
F_65 ( & V_2 -> V_28 ) ;
}
F_66 ( V_41 -> V_79 ) ;
F_67 ( V_41 ) ;
return 0 ;
}
static int
F_68 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = F_8 ( V_41 ) ;
int V_42 ;
F_69 ( V_41 ) ;
F_70 ( V_41 -> V_79 ) ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
struct V_1 * V_2 = & V_17 -> V_2 [ V_42 ] ;
if ( ! F_31 ( V_42 ) && ! F_34 ( V_42 ) )
continue;
F_71 ( & V_2 -> V_28 ) ;
F_11 ( & V_2 -> V_4 ) ;
}
return 0 ;
}
static int
F_72 ( struct V_19 * V_3 , struct V_40 * V_41 )
{
int V_101 = F_73 ( V_3 ) ;
struct V_32 * V_33 = F_21 ( V_41 , V_101 ) ;
struct V_16 * V_17 = F_8 ( V_41 ) ;
struct V_1 * V_2 = & V_17 -> V_2 [ ( V_101 << 1 ) | 1 ] ;
struct V_18 * V_5 = & V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] ;
int V_20 ;
unsigned long V_23 ;
T_3 V_102 ;
V_20 = V_3 -> V_20 < V_103 ? V_103 : V_3 -> V_20 ;
if ( ( V_5 -> V_13 & ( V_14 | V_31 ) ) || V_2 -> V_3 [ V_2 -> V_4 . V_5 ] ) {
F_22 ( V_3 ) ;
F_10 ( V_41 , L_12 ) ;
F_74 ( V_33 ) ;
return V_104 ;
}
V_102 = F_4 ( V_3 -> V_11 ) % 16 ;
V_2 -> V_3 [ V_2 -> V_4 . V_5 ] = V_3 ;
F_75 ( V_41 ) ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
V_5 -> V_10 = ( ( unsigned int ) F_3 ( NULL , V_3 -> V_11 , V_20 ,
V_105 ) ) - V_102 ;
F_76 () ;
V_5 -> V_13 = V_14 | V_106 | V_107 |
F_77 ( V_102 ) | ( V_20 & V_21 ) ;
V_2 -> V_4 . V_5 ++ ;
V_2 -> V_4 . V_5 %= V_25 ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
if ( V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] . V_13 & V_14 )
F_74 ( V_33 ) ;
return V_108 ;
}
static int
F_78 ( struct V_40 * V_41 , int V_109 )
{
struct V_16 * V_17 = F_8 ( V_41 ) ;
unsigned long V_23 ;
V_41 -> V_110 = V_109 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
F_38 ( ( V_111 << 16 ) | V_109 , V_112 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
return 0 ;
}
static int
F_79 ( struct V_40 * V_41 , struct V_113 * V_114 , int V_115 )
{
return F_80 ( V_41 -> V_79 , V_114 , V_115 ) ;
}
static int
F_81 ( struct V_40 * V_41 , void * V_116 )
{
int V_117 = F_82 ( V_41 , V_116 ) ;
if ( ! V_117 ) {
struct V_16 * V_17 = F_8 ( V_41 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
F_38 ( * ( ( T_3 * ) V_41 -> V_118 ) , V_119 ) ;
F_38 ( * ( ( T_2 * ) & V_41 -> V_118 [ 4 ] ) << 16 ,
V_120 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
return V_117 ;
}
static void
F_83 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = F_8 ( V_41 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
if ( ( V_41 -> V_23 & V_121 ) || ( V_41 -> V_23 & V_122 ) )
F_37 ( V_123 , 0 , V_124 ) ;
else
F_37 ( 0 , V_123 , V_124 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
static T_2
F_84 ( struct V_40 * V_41 , struct V_19 * V_3 ,
void * V_125 , T_4 V_126 )
{
return 0 ;
}
static int
F_85 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = F_8 ( V_41 ) ;
struct V_127 V_128 ;
int V_90 ;
bool V_129 = false ;
V_41 -> V_130 = 10 * V_131 ;
V_90 = F_35 ( V_41 ) ;
if ( V_90 )
goto V_132;
F_78 ( V_41 , 1500 ) ;
memcpy ( & V_128 , & V_17 -> V_45 -> V_128 , sizeof( struct V_127 ) ) ;
if ( ! F_86 ( V_128 . V_133 ) ) {
F_87 ( L_13 ) ;
F_88 ( V_128 . V_133 ) ;
V_129 = true ;
}
V_90 = F_81 ( V_41 , & V_128 ) ;
if ( V_90 )
goto V_134;
if ( V_129 )
V_41 -> V_135 = V_136 ;
F_83 ( V_41 ) ;
V_90 = F_56 ( V_41 ) ;
if ( V_90 )
goto V_134;
return 0 ;
V_134:
F_89 ( V_41 ) ;
F_90 ( V_41 ) ;
V_132:
F_32 ( V_41 ) ;
return V_90 ;
}
static void
F_91 ( struct V_40 * V_41 )
{
int V_90 ;
F_32 ( V_41 ) ;
V_90 = F_35 ( V_41 ) ;
if ( V_90 )
goto V_132;
F_75 ( V_41 ) ;
F_92 ( V_41 ) ;
return;
V_132:
F_32 ( V_41 ) ;
F_10 ( V_41 , L_14 ) ;
}
static int T_5
F_93 ( struct V_137 * V_97 )
{
struct V_40 * V_41 ;
struct V_16 * V_17 ;
struct V_138 * V_139 ;
int V_90 ;
int V_42 ;
V_139 = F_94 ( V_97 , V_140 , 0 ) ;
if ( ! V_139 ) {
F_95 ( & V_97 -> V_41 , L_15 ) ;
V_90 = - V_141 ;
goto V_91;
}
V_139 = F_96 ( & V_97 -> V_41 , V_139 -> V_142 ,
F_97 ( V_139 ) , F_98 ( & V_97 -> V_41 ) ) ;
if ( ! V_139 ) {
F_95 ( & V_97 -> V_41 , L_16 ) ;
V_90 = - V_143 ;
goto V_91;
}
V_144 = F_99 ( & V_97 -> V_41 ,
V_139 -> V_142 , F_97 ( V_139 ) ) ;
if ( ! V_144 ) {
F_95 ( & V_97 -> V_41 , L_17 ,
V_97 -> V_95 ) ;
V_90 = - V_8 ;
goto V_91;
}
V_41 = F_100 ( sizeof( struct V_16 ) , 4 ) ;
if ( ! V_41 ) {
V_90 = - V_8 ;
goto V_91;
}
strcpy ( V_41 -> V_94 , L_18 ) ;
V_41 -> V_145 = & V_146 ;
V_41 -> V_147 = & V_148 ;
V_17 = F_8 ( V_41 ) ;
V_17 -> V_139 = V_139 ;
V_17 -> V_97 = V_97 ;
V_17 -> V_45 = F_101 ( & V_97 -> V_41 ) ;
V_17 -> V_6 = V_41 ;
F_102 ( & V_17 -> V_24 ) ;
F_103 ( V_41 , & V_97 -> V_41 ) ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
if ( F_34 ( V_42 ) )
F_104 ( V_41 , & V_17 -> V_2 [ V_42 ] . V_28 ,
F_20 , 8 ) ;
else if ( F_31 ( V_42 ) )
F_104 ( V_41 , & V_17 -> V_2 [ V_42 ] . V_28 ,
F_16 , 32 ) ;
V_17 -> V_2 [ V_42 ] . V_6 = V_41 ;
}
V_90 = F_105 ( V_41 ) ;
if ( V_90 )
goto V_149;
F_106 ( V_97 , V_41 ) ;
return 0 ;
V_149:
F_90 ( V_41 ) ;
V_91:
return V_90 ;
}
static int
F_107 ( struct V_137 * V_97 )
{
struct V_40 * V_41 = F_108 ( V_97 ) ;
if ( V_41 ) {
F_69 ( V_41 ) ;
F_32 ( V_41 ) ;
F_61 ( V_41 ) ;
F_89 ( V_41 ) ;
}
return 0 ;
}
int T_5
F_109 ( void )
{
int V_117 = F_110 ( & V_150 , F_93 ) ;
if ( V_117 )
F_111 ( L_19 ) ;
return V_117 ;
}
static void T_6
F_112 ( void )
{
F_113 ( & V_150 ) ;
}
