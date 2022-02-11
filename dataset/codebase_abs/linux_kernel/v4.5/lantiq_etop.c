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
struct V_82 * V_67 ;
V_67 = F_55 ( V_17 -> V_68 ) ;
if ( ! V_67 ) {
F_10 ( V_42 , L_7 ) ;
return - V_83 ;
}
V_67 = F_56 ( V_42 , F_57 ( V_67 ) ,
& F_53 , V_17 -> V_46 -> V_47 ) ;
if ( F_58 ( V_67 ) ) {
F_10 ( V_42 , L_8 ) ;
return F_59 ( V_67 ) ;
}
V_67 -> V_84 &= ( V_85
| V_86
| V_87
| V_88
| V_89
| V_90
| V_91 ) ;
V_67 -> V_92 = V_67 -> V_84 ;
V_17 -> V_67 = V_67 ;
F_60 ( V_67 ) ;
return 0 ;
}
static int
F_61 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
int V_43 ;
int V_93 ;
V_17 -> V_68 = F_62 () ;
if ( ! V_17 -> V_68 ) {
F_10 ( V_42 , L_9 ) ;
V_93 = - V_8 ;
goto V_94;
}
V_17 -> V_68 -> V_17 = V_42 ;
V_17 -> V_68 -> V_95 = F_52 ;
V_17 -> V_68 -> V_96 = F_50 ;
V_17 -> V_68 -> V_97 = L_10 ;
snprintf ( V_17 -> V_68 -> V_98 , V_99 , L_11 ,
V_17 -> V_100 -> V_97 , V_17 -> V_100 -> V_98 ) ;
if ( F_63 ( V_17 -> V_68 ) ) {
V_93 = - V_101 ;
goto V_102;
}
if ( F_54 ( V_42 ) ) {
V_93 = - V_101 ;
goto V_103;
}
return 0 ;
V_103:
F_64 ( V_17 -> V_68 ) ;
V_102:
F_65 ( V_17 -> V_68 ) ;
V_94:
return V_93 ;
}
static void
F_66 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
F_67 ( V_17 -> V_67 ) ;
F_64 ( V_17 -> V_68 ) ;
F_65 ( V_17 -> V_68 ) ;
}
static int
F_68 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_1 * V_2 = & V_17 -> V_2 [ V_43 ] ;
if ( ! F_33 ( V_43 ) && ( ! F_30 ( V_43 ) ) )
continue;
F_69 ( & V_2 -> V_4 ) ;
F_70 ( & V_2 -> V_28 ) ;
}
F_71 ( V_17 -> V_67 ) ;
F_72 ( V_42 ) ;
return 0 ;
}
static int
F_73 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
int V_43 ;
F_74 ( V_42 ) ;
F_75 ( V_17 -> V_67 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_1 * V_2 = & V_17 -> V_2 [ V_43 ] ;
if ( ! F_30 ( V_43 ) && ! F_33 ( V_43 ) )
continue;
F_76 ( & V_2 -> V_28 ) ;
F_11 ( & V_2 -> V_4 ) ;
}
return 0 ;
}
static int
F_77 ( struct V_19 * V_3 , struct V_41 * V_42 )
{
int V_104 = F_78 ( V_3 ) ;
struct V_33 * V_34 = F_21 ( V_42 , V_104 ) ;
struct V_16 * V_17 = F_8 ( V_42 ) ;
struct V_1 * V_2 = & V_17 -> V_2 [ ( V_104 << 1 ) | 1 ] ;
struct V_18 * V_5 = & V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] ;
int V_20 ;
unsigned long V_23 ;
T_3 V_105 ;
V_20 = V_3 -> V_20 < V_106 ? V_106 : V_3 -> V_20 ;
if ( ( V_5 -> V_13 & ( V_14 | V_32 ) ) || V_2 -> V_3 [ V_2 -> V_4 . V_5 ] ) {
F_22 ( V_3 ) ;
F_10 ( V_42 , L_12 ) ;
F_79 ( V_34 ) ;
return V_107 ;
}
V_105 = F_4 ( V_3 -> V_11 ) % 16 ;
V_2 -> V_3 [ V_2 -> V_4 . V_5 ] = V_3 ;
V_42 -> V_108 = V_109 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
V_5 -> V_10 = ( ( unsigned int ) F_3 ( NULL , V_3 -> V_11 , V_20 ,
V_110 ) ) - V_105 ;
F_80 () ;
V_5 -> V_13 = V_14 | V_111 | V_112 |
F_81 ( V_105 ) | ( V_20 & V_21 ) ;
V_2 -> V_4 . V_5 ++ ;
V_2 -> V_4 . V_5 %= V_25 ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
if ( V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] . V_13 & V_14 )
F_79 ( V_34 ) ;
return V_113 ;
}
static int
F_82 ( struct V_41 * V_42 , int V_114 )
{
int V_115 = F_83 ( V_42 , V_114 ) ;
if ( ! V_115 ) {
struct V_16 * V_17 = F_8 ( V_42 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
F_37 ( ( V_116 << 16 ) | V_114 ,
V_117 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
return V_115 ;
}
static int
F_84 ( struct V_41 * V_42 , struct V_118 * V_119 , int V_66 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
return F_85 ( V_17 -> V_67 , V_119 , V_66 ) ;
}
static int
F_86 ( struct V_41 * V_42 , void * V_120 )
{
int V_115 = F_87 ( V_42 , V_120 ) ;
if ( ! V_115 ) {
struct V_16 * V_17 = F_8 ( V_42 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
F_37 ( * ( ( T_3 * ) V_42 -> V_121 ) , V_122 ) ;
F_37 ( * ( ( T_2 * ) & V_42 -> V_121 [ 4 ] ) << 16 ,
V_123 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
return V_115 ;
}
static void
F_88 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
if ( ( V_42 -> V_23 & V_124 ) || ( V_42 -> V_23 & V_125 ) )
F_36 ( V_126 , 0 , V_127 ) ;
else
F_36 ( 0 , V_126 , V_127 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
static T_2
F_89 ( struct V_41 * V_42 , struct V_19 * V_3 ,
void * V_128 , T_4 V_129 )
{
return 0 ;
}
static int
F_90 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
struct V_130 V_131 ;
int V_93 ;
bool V_132 = false ;
V_42 -> V_133 = 10 * V_134 ;
V_93 = F_34 ( V_42 ) ;
if ( V_93 )
goto V_135;
F_82 ( V_42 , 1500 ) ;
memcpy ( & V_131 , & V_17 -> V_46 -> V_131 , sizeof( struct V_130 ) ) ;
if ( ! F_91 ( V_131 . V_136 ) ) {
F_92 ( L_13 ) ;
F_93 ( V_131 . V_136 ) ;
V_132 = true ;
}
V_93 = F_86 ( V_42 , & V_131 ) ;
if ( V_93 )
goto V_137;
if ( V_132 )
V_42 -> V_138 = V_139 ;
F_88 ( V_42 ) ;
V_93 = F_61 ( V_42 ) ;
if ( V_93 )
goto V_137;
return 0 ;
V_137:
F_94 ( V_42 ) ;
F_95 ( V_42 ) ;
V_135:
F_31 ( V_42 ) ;
return V_93 ;
}
static void
F_96 ( struct V_41 * V_42 )
{
int V_93 ;
F_31 ( V_42 ) ;
V_93 = F_34 ( V_42 ) ;
if ( V_93 )
goto V_135;
V_42 -> V_108 = V_109 ;
F_97 ( V_42 ) ;
return;
V_135:
F_31 ( V_42 ) ;
F_10 ( V_42 , L_14 ) ;
}
static int T_5
F_98 ( struct V_140 * V_100 )
{
struct V_41 * V_42 ;
struct V_16 * V_17 ;
struct V_141 * V_142 ;
int V_93 ;
int V_43 ;
V_142 = F_99 ( V_100 , V_143 , 0 ) ;
if ( ! V_142 ) {
F_100 ( & V_100 -> V_42 , L_15 ) ;
V_93 = - V_144 ;
goto V_94;
}
V_142 = F_101 ( & V_100 -> V_42 , V_142 -> V_145 ,
F_102 ( V_142 ) , F_103 ( & V_100 -> V_42 ) ) ;
if ( ! V_142 ) {
F_100 ( & V_100 -> V_42 , L_16 ) ;
V_93 = - V_146 ;
goto V_94;
}
V_147 = F_104 ( & V_100 -> V_42 ,
V_142 -> V_145 , F_102 ( V_142 ) ) ;
if ( ! V_147 ) {
F_100 ( & V_100 -> V_42 , L_17 ,
V_100 -> V_98 ) ;
V_93 = - V_8 ;
goto V_94;
}
V_42 = F_105 ( sizeof( struct V_16 ) , 4 ) ;
if ( ! V_42 ) {
V_93 = - V_8 ;
goto V_94;
}
strcpy ( V_42 -> V_97 , L_18 ) ;
V_42 -> V_148 = & V_149 ;
V_42 -> V_150 = & V_151 ;
V_17 = F_8 ( V_42 ) ;
V_17 -> V_142 = V_142 ;
V_17 -> V_100 = V_100 ;
V_17 -> V_46 = F_106 ( & V_100 -> V_42 ) ;
V_17 -> V_6 = V_42 ;
F_107 ( & V_17 -> V_24 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
if ( F_33 ( V_43 ) )
F_108 ( V_42 , & V_17 -> V_2 [ V_43 ] . V_28 ,
F_20 , 8 ) ;
else if ( F_30 ( V_43 ) )
F_108 ( V_42 , & V_17 -> V_2 [ V_43 ] . V_28 ,
F_16 , 32 ) ;
V_17 -> V_2 [ V_43 ] . V_6 = V_42 ;
}
V_93 = F_109 ( V_42 ) ;
if ( V_93 )
goto V_152;
F_110 ( V_100 , V_42 ) ;
return 0 ;
V_152:
F_95 ( V_42 ) ;
V_94:
return V_93 ;
}
static int
F_111 ( struct V_140 * V_100 )
{
struct V_41 * V_42 = F_112 ( V_100 ) ;
if ( V_42 ) {
F_74 ( V_42 ) ;
F_31 ( V_42 ) ;
F_66 ( V_42 ) ;
F_94 ( V_42 ) ;
}
return 0 ;
}
int T_5
F_113 ( void )
{
int V_115 = F_114 ( & V_153 , F_98 ) ;
if ( V_115 )
F_115 ( L_19 ) ;
return V_115 ;
}
static void T_6
F_116 ( void )
{
F_117 ( & V_153 ) ;
}
