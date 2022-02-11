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
F_44 ( struct V_41 * V_42 )
{
return F_45 ( V_42 -> V_65 ) ;
}
static int
F_46 ( struct V_66 * V_67 , int V_68 , int V_69 , T_2 V_70 )
{
T_3 V_71 = V_72 |
( ( V_68 & V_73 ) << V_74 ) |
( ( V_69 & V_75 ) << V_76 ) |
V_70 ;
while ( F_47 ( V_77 ) & V_72 )
;
F_37 ( V_71 , V_77 ) ;
return 0 ;
}
static int
F_48 ( struct V_66 * V_67 , int V_68 , int V_69 )
{
T_3 V_71 = V_72 | V_78 |
( ( V_68 & V_73 ) << V_74 ) |
( ( V_69 & V_75 ) << V_76 ) ;
while ( F_47 ( V_77 ) & V_72 )
;
F_37 ( V_71 , V_77 ) ;
while ( F_47 ( V_77 ) & V_72 )
;
V_71 = F_47 ( V_77 ) & V_79 ;
return V_71 ;
}
static void
F_49 ( struct V_41 * V_42 )
{
}
static int
F_50 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
struct V_80 * V_65 ;
V_65 = F_51 ( V_17 -> V_66 ) ;
if ( ! V_65 ) {
F_10 ( V_42 , L_7 ) ;
return - V_81 ;
}
V_65 = F_52 ( V_42 , F_53 ( V_65 ) ,
& F_49 , V_17 -> V_46 -> V_47 ) ;
if ( F_54 ( V_65 ) ) {
F_10 ( V_42 , L_8 ) ;
return F_55 ( V_65 ) ;
}
V_65 -> V_82 &= ( V_83
| V_84
| V_85
| V_86
| V_87
| V_88
| V_89 ) ;
V_65 -> V_90 = V_65 -> V_82 ;
F_56 ( V_65 ) ;
return 0 ;
}
static int
F_57 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
int V_91 ;
V_17 -> V_66 = F_58 () ;
if ( ! V_17 -> V_66 ) {
F_10 ( V_42 , L_9 ) ;
V_91 = - V_8 ;
goto V_92;
}
V_17 -> V_66 -> V_17 = V_42 ;
V_17 -> V_66 -> V_93 = F_48 ;
V_17 -> V_66 -> V_94 = F_46 ;
V_17 -> V_66 -> V_95 = L_10 ;
snprintf ( V_17 -> V_66 -> V_96 , V_97 , L_11 ,
V_17 -> V_98 -> V_95 , V_17 -> V_98 -> V_96 ) ;
if ( F_59 ( V_17 -> V_66 ) ) {
V_91 = - V_99 ;
goto V_100;
}
if ( F_50 ( V_42 ) ) {
V_91 = - V_99 ;
goto V_101;
}
return 0 ;
V_101:
F_60 ( V_17 -> V_66 ) ;
V_100:
F_61 ( V_17 -> V_66 ) ;
V_92:
return V_91 ;
}
static void
F_62 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
F_63 ( V_42 -> V_65 ) ;
F_60 ( V_17 -> V_66 ) ;
F_61 ( V_17 -> V_66 ) ;
}
static int
F_64 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_1 * V_2 = & V_17 -> V_2 [ V_43 ] ;
if ( ! F_33 ( V_43 ) && ( ! F_30 ( V_43 ) ) )
continue;
F_65 ( & V_2 -> V_4 ) ;
F_66 ( & V_2 -> V_28 ) ;
}
F_67 ( V_42 -> V_65 ) ;
F_68 ( V_42 ) ;
return 0 ;
}
static int
F_69 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
int V_43 ;
F_70 ( V_42 ) ;
F_71 ( V_42 -> V_65 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_1 * V_2 = & V_17 -> V_2 [ V_43 ] ;
if ( ! F_30 ( V_43 ) && ! F_33 ( V_43 ) )
continue;
F_72 ( & V_2 -> V_28 ) ;
F_11 ( & V_2 -> V_4 ) ;
}
return 0 ;
}
static int
F_73 ( struct V_19 * V_3 , struct V_41 * V_42 )
{
int V_102 = F_74 ( V_3 ) ;
struct V_33 * V_34 = F_21 ( V_42 , V_102 ) ;
struct V_16 * V_17 = F_8 ( V_42 ) ;
struct V_1 * V_2 = & V_17 -> V_2 [ ( V_102 << 1 ) | 1 ] ;
struct V_18 * V_5 = & V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] ;
int V_20 ;
unsigned long V_23 ;
T_3 V_103 ;
V_20 = V_3 -> V_20 < V_104 ? V_104 : V_3 -> V_20 ;
if ( ( V_5 -> V_13 & ( V_14 | V_32 ) ) || V_2 -> V_3 [ V_2 -> V_4 . V_5 ] ) {
F_22 ( V_3 ) ;
F_10 ( V_42 , L_12 ) ;
F_75 ( V_34 ) ;
return V_105 ;
}
V_103 = F_4 ( V_3 -> V_11 ) % 16 ;
V_2 -> V_3 [ V_2 -> V_4 . V_5 ] = V_3 ;
F_76 ( V_42 ) ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
V_5 -> V_10 = ( ( unsigned int ) F_3 ( NULL , V_3 -> V_11 , V_20 ,
V_106 ) ) - V_103 ;
F_77 () ;
V_5 -> V_13 = V_14 | V_107 | V_108 |
F_78 ( V_103 ) | ( V_20 & V_21 ) ;
V_2 -> V_4 . V_5 ++ ;
V_2 -> V_4 . V_5 %= V_25 ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
if ( V_2 -> V_4 . V_9 [ V_2 -> V_4 . V_5 ] . V_13 & V_14 )
F_75 ( V_34 ) ;
return V_109 ;
}
static int
F_79 ( struct V_41 * V_42 , int V_110 )
{
int V_111 = F_80 ( V_42 , V_110 ) ;
if ( ! V_111 ) {
struct V_16 * V_17 = F_8 ( V_42 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
F_37 ( ( V_112 << 16 ) | V_110 ,
V_113 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
return V_111 ;
}
static int
F_81 ( struct V_41 * V_42 , struct V_114 * V_115 , int V_116 )
{
return F_82 ( V_42 -> V_65 , V_115 , V_116 ) ;
}
static int
F_83 ( struct V_41 * V_42 , void * V_117 )
{
int V_111 = F_84 ( V_42 , V_117 ) ;
if ( ! V_111 ) {
struct V_16 * V_17 = F_8 ( V_42 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
F_37 ( * ( ( T_3 * ) V_42 -> V_118 ) , V_119 ) ;
F_37 ( * ( ( T_2 * ) & V_42 -> V_118 [ 4 ] ) << 16 ,
V_120 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
return V_111 ;
}
static void
F_85 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_24 , V_23 ) ;
if ( ( V_42 -> V_23 & V_121 ) || ( V_42 -> V_23 & V_122 ) )
F_36 ( V_123 , 0 , V_124 ) ;
else
F_36 ( 0 , V_123 , V_124 ) ;
F_12 ( & V_17 -> V_24 , V_23 ) ;
}
static T_2
F_86 ( struct V_41 * V_42 , struct V_19 * V_3 ,
void * V_125 , T_4 V_126 )
{
return 0 ;
}
static int
F_87 ( struct V_41 * V_42 )
{
struct V_16 * V_17 = F_8 ( V_42 ) ;
struct V_127 V_128 ;
int V_91 ;
bool V_129 = false ;
V_42 -> V_130 = 10 * V_131 ;
V_91 = F_34 ( V_42 ) ;
if ( V_91 )
goto V_132;
F_79 ( V_42 , 1500 ) ;
memcpy ( & V_128 , & V_17 -> V_46 -> V_128 , sizeof( struct V_127 ) ) ;
if ( ! F_88 ( V_128 . V_133 ) ) {
F_89 ( L_13 ) ;
F_90 ( V_128 . V_133 ) ;
V_129 = true ;
}
V_91 = F_83 ( V_42 , & V_128 ) ;
if ( V_91 )
goto V_134;
if ( V_129 )
V_42 -> V_135 = V_136 ;
F_85 ( V_42 ) ;
V_91 = F_57 ( V_42 ) ;
if ( V_91 )
goto V_134;
return 0 ;
V_134:
F_91 ( V_42 ) ;
F_92 ( V_42 ) ;
V_132:
F_31 ( V_42 ) ;
return V_91 ;
}
static void
F_93 ( struct V_41 * V_42 )
{
int V_91 ;
F_31 ( V_42 ) ;
V_91 = F_34 ( V_42 ) ;
if ( V_91 )
goto V_132;
F_76 ( V_42 ) ;
F_94 ( V_42 ) ;
return;
V_132:
F_31 ( V_42 ) ;
F_10 ( V_42 , L_14 ) ;
}
static int T_5
F_95 ( struct V_137 * V_98 )
{
struct V_41 * V_42 ;
struct V_16 * V_17 ;
struct V_138 * V_139 ;
int V_91 ;
int V_43 ;
V_139 = F_96 ( V_98 , V_140 , 0 ) ;
if ( ! V_139 ) {
F_97 ( & V_98 -> V_42 , L_15 ) ;
V_91 = - V_141 ;
goto V_92;
}
V_139 = F_98 ( & V_98 -> V_42 , V_139 -> V_142 ,
F_99 ( V_139 ) , F_100 ( & V_98 -> V_42 ) ) ;
if ( ! V_139 ) {
F_97 ( & V_98 -> V_42 , L_16 ) ;
V_91 = - V_143 ;
goto V_92;
}
V_144 = F_101 ( & V_98 -> V_42 ,
V_139 -> V_142 , F_99 ( V_139 ) ) ;
if ( ! V_144 ) {
F_97 ( & V_98 -> V_42 , L_17 ,
V_98 -> V_96 ) ;
V_91 = - V_8 ;
goto V_92;
}
V_42 = F_102 ( sizeof( struct V_16 ) , 4 ) ;
if ( ! V_42 ) {
V_91 = - V_8 ;
goto V_92;
}
strcpy ( V_42 -> V_95 , L_18 ) ;
V_42 -> V_145 = & V_146 ;
V_42 -> V_147 = & V_148 ;
V_17 = F_8 ( V_42 ) ;
V_17 -> V_139 = V_139 ;
V_17 -> V_98 = V_98 ;
V_17 -> V_46 = F_103 ( & V_98 -> V_42 ) ;
V_17 -> V_6 = V_42 ;
F_104 ( & V_17 -> V_24 ) ;
F_105 ( V_42 , & V_98 -> V_42 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
if ( F_33 ( V_43 ) )
F_106 ( V_42 , & V_17 -> V_2 [ V_43 ] . V_28 ,
F_20 , 8 ) ;
else if ( F_30 ( V_43 ) )
F_106 ( V_42 , & V_17 -> V_2 [ V_43 ] . V_28 ,
F_16 , 32 ) ;
V_17 -> V_2 [ V_43 ] . V_6 = V_42 ;
}
V_91 = F_107 ( V_42 ) ;
if ( V_91 )
goto V_149;
F_108 ( V_98 , V_42 ) ;
return 0 ;
V_149:
F_92 ( V_42 ) ;
V_92:
return V_91 ;
}
static int
F_109 ( struct V_137 * V_98 )
{
struct V_41 * V_42 = F_110 ( V_98 ) ;
if ( V_42 ) {
F_70 ( V_42 ) ;
F_31 ( V_42 ) ;
F_62 ( V_42 ) ;
F_91 ( V_42 ) ;
}
return 0 ;
}
int T_5
F_111 ( void )
{
int V_111 = F_112 ( & V_150 , F_95 ) ;
if ( V_111 )
F_113 ( L_19 ) ;
return V_111 ;
}
static void T_6
F_114 ( void )
{
F_115 ( & V_150 ) ;
}
