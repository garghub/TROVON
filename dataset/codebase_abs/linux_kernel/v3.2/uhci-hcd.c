static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_4 = 8 - ( int ) F_2 ( V_3 | V_5 ) ;
if ( V_4 <= 1 )
V_4 = 9 ;
return F_3 ( V_2 , V_2 -> V_6 [ V_4 ] ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 )
F_5 ( V_2 , 0 , V_9 + ( V_7 * 2 ) ) ;
V_2 -> V_10 = V_2 -> V_11 = 0 ;
V_2 -> V_12 = V_13 ;
V_2 -> V_14 = V_15 ;
F_6 ( V_16 , & F_7 ( V_2 ) -> V_17 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
V_2 -> V_18 ( V_2 ) ;
F_4 ( V_2 ) ;
V_2 -> V_19 = 1 ;
++ V_2 -> V_20 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> F_10 ( V_2 ) )
F_4 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_21 , V_22 ) ;
F_12 () ;
F_13 ( 5 ) ;
if ( F_14 ( V_2 , V_22 ) & V_21 )
F_15 ( F_16 ( V_2 ) , L_1 ) ;
F_5 ( V_2 , 0 , V_23 ) ;
F_5 ( V_2 , 0 , V_22 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned int V_24 , V_25 ;
V_24 = F_14 ( V_2 , V_22 ) ;
if ( ( V_24 & V_26 ) || ! ( V_24 & V_27 ) || ! ( V_24 & V_28 ) ) {
F_18 ( F_16 ( V_2 ) , L_2 ,
V_29 , V_24 ) ;
goto V_30;
}
V_25 = F_14 ( V_2 , V_23 ) ;
if ( V_25 & ( ~ V_31 ) ) {
F_18 ( F_16 ( V_2 ) , L_3 ,
V_29 , V_25 ) ;
goto V_30;
}
return 0 ;
V_30:
F_18 ( F_16 ( V_2 ) , L_4 ) ;
F_11 ( V_2 ) ;
return 1 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_32 , V_33 ) ;
F_21 ( V_2 , V_2 -> V_34 , V_35 ) ;
F_5 ( V_2 , V_2 -> V_20 & V_36 ,
V_37 ) ;
if ( V_2 -> F_19 )
V_2 -> F_19 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
if ( V_38 )
return 1 ;
return V_2 -> F_22 ?
V_2 -> F_22 ( V_2 ) : 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return V_2 -> F_23 ?
V_2 -> F_23 ( V_2 ) : 0 ;
}
static void F_24 ( struct V_1 * V_2 , enum V_39 V_40 )
__releases( V_2 -> V_41 )
__acquires( V_2 -> V_41 )
{
int V_42 ;
int V_43 , V_44 , V_45 ;
struct V_46 * V_47 = F_7 ( V_2 ) -> V_48 . V_49 ;
V_42 = ( V_40 == V_50 ) ;
F_18 ( & V_47 -> V_51 , L_5 , V_29 ,
( V_42 ? L_6 : L_7 ) ) ;
V_44 = V_28 ;
V_43 = V_31 ;
V_45 = 1 ;
if ( V_42 ) {
if ( ! F_25 ( & V_47 -> V_51 ) )
V_44 = V_43 = 0 ;
}
#ifdef F_26
else {
if ( ! V_47 -> V_52 )
V_45 = 0 ;
}
#endif
if ( ! V_45 || F_23 ( V_2 ) ||
F_22 ( V_2 ) )
V_44 = V_43 = 0 ;
V_2 -> V_53 = ! ! V_43 ;
F_5 ( V_2 , V_43 , V_23 ) ;
F_5 ( V_2 , V_44 | V_27 , V_22 ) ;
F_12 () ;
F_13 ( 5 ) ;
if ( ! V_42 && ! ( F_14 ( V_2 , V_54 ) & V_55 ) ) {
V_2 -> V_12 = V_56 ;
F_27 ( & V_2 -> V_41 ) ;
F_28 ( 1 ) ;
F_29 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_19 )
return;
}
if ( ! ( F_14 ( V_2 , V_54 ) & V_55 ) )
F_15 ( F_16 ( V_2 ) , L_8 ) ;
F_9 ( V_2 ) ;
V_2 -> V_12 = V_40 ;
V_2 -> V_14 = V_15 ;
if ( V_45 && ( ! V_43 || ! V_44 ) )
F_30 ( V_16 , & F_7 ( V_2 ) -> V_17 ) ;
else
F_6 ( V_16 , & F_7 ( V_2 ) -> V_17 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
V_2 -> V_14 = 0 ;
F_5 ( V_2 , V_26 | V_27 | V_57 , V_22 ) ;
F_5 ( V_2 , V_58 | V_31 |
V_59 | V_60 , V_23 ) ;
F_12 () ;
V_2 -> V_12 = V_61 ;
F_30 ( V_16 , & F_7 ( V_2 ) -> V_17 ) ;
}
static void F_34 ( struct V_1 * V_2 )
__releases( V_2 -> V_41 )
__acquires( V_2 -> V_41 )
{
F_18 ( & F_7 ( V_2 ) -> V_48 . V_49 -> V_51 ,
L_5 , V_29 ,
V_2 -> V_12 == V_50 ?
L_9 : L_7 ) ;
if ( V_2 -> V_12 == V_62 ) {
unsigned V_63 ;
V_63 = F_14 ( V_2 , V_22 ) & V_28 ;
V_2 -> V_12 = V_64 ;
F_5 ( V_2 , V_65 | V_27 | V_63 , V_22 ) ;
F_27 ( & V_2 -> V_41 ) ;
F_28 ( 20 ) ;
F_29 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_19 )
return;
F_5 ( V_2 , V_27 , V_22 ) ;
F_12 () ;
F_13 ( 4 ) ;
if ( F_14 ( V_2 , V_22 ) & V_65 )
F_15 ( F_16 ( V_2 ) , L_10 ) ;
}
F_33 ( V_2 ) ;
F_35 ( & F_7 ( V_2 ) -> V_66 , V_67 ) ;
}
static T_2 F_36 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
unsigned short V_70 ;
V_70 = F_14 ( V_2 , V_54 ) ;
if ( ! ( V_70 & ~ V_55 ) )
return V_71 ;
F_5 ( V_2 , V_70 , V_54 ) ;
if ( V_70 & ~ ( V_72 | V_73 | V_74 ) ) {
if ( V_70 & V_75 )
F_38 ( F_16 ( V_2 ) , L_11
L_12 ) ;
if ( V_70 & V_76 )
F_38 ( F_16 ( V_2 ) , L_13
L_14 ) ;
if ( V_70 & V_55 ) {
F_39 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_12 >= V_61 ) {
F_38 ( F_16 ( V_2 ) ,
L_15
L_16 ) ;
if ( V_77 > 1 && V_78 ) {
F_40 ( V_2 ,
V_78 , V_79 ) ;
F_41 ( V_78 ) ;
}
F_8 ( V_2 ) ;
F_42 ( V_69 ) ;
F_35 ( & V_69 -> V_66 , V_67 ) ;
}
F_43 ( & V_2 -> V_41 ) ;
}
}
if ( V_70 & V_74 )
F_44 ( V_69 ) ;
else {
F_39 ( & V_2 -> V_41 ) ;
F_31 ( V_2 ) ;
F_43 ( & V_2 -> V_41 ) ;
}
return V_80 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_14 ) {
unsigned V_81 ;
V_81 = ( F_14 ( V_2 , V_37 ) - V_2 -> V_20 ) &
( V_5 - 1 ) ;
V_2 -> V_20 += V_81 ;
}
}
static void F_45 ( struct V_1 * V_2 )
{
int V_82 ;
if ( V_83 ) {
F_29 ( & V_2 -> V_41 ) ;
V_2 -> V_84 = 0 ;
F_27 ( & V_2 -> V_41 ) ;
F_46 ( V_2 -> V_85 ) ;
}
for ( V_82 = 0 ; V_82 < V_86 ; V_82 ++ )
F_47 ( V_2 , V_2 -> V_6 [ V_82 ] ) ;
F_48 ( V_2 , V_2 -> V_87 ) ;
F_49 ( V_2 -> V_88 ) ;
F_49 ( V_2 -> V_89 ) ;
F_50 ( V_2 -> V_90 ) ;
F_51 ( F_16 ( V_2 ) ,
V_5 * sizeof( * V_2 -> V_3 ) ,
V_2 -> V_3 , V_2 -> V_34 ) ;
}
static int F_52 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
int V_91 = - V_92 ;
int V_82 ;
struct V_85 T_3 * V_85 ;
V_69 -> V_93 = 1 ;
F_53 ( & V_2 -> V_41 ) ;
F_54 ( & V_2 -> V_94 , V_95 ,
( unsigned long ) V_2 ) ;
F_55 ( & V_2 -> V_96 ) ;
F_56 ( & V_2 -> V_97 ) ;
#ifdef F_57
V_85 = F_58 ( V_69 -> V_48 . V_98 ,
V_99 | V_100 | V_101 , V_102 ,
V_2 , & V_103 ) ;
if ( ! V_85 ) {
F_38 ( F_16 ( V_2 ) , L_17 ) ;
return - V_104 ;
}
V_2 -> V_85 = V_85 ;
#endif
V_2 -> V_3 = F_59 ( F_16 ( V_2 ) ,
V_5 * sizeof( * V_2 -> V_3 ) ,
& V_2 -> V_34 , 0 ) ;
if ( ! V_2 -> V_3 ) {
F_38 ( F_16 ( V_2 ) , L_18
L_19 ) ;
goto V_105;
}
memset ( V_2 -> V_3 , 0 , V_5 * sizeof( * V_2 -> V_3 ) ) ;
V_2 -> V_90 = F_60 ( V_5 , sizeof( * V_2 -> V_90 ) ,
V_106 ) ;
if ( ! V_2 -> V_90 ) {
F_38 ( F_16 ( V_2 ) , L_18
L_20 ) ;
goto V_107;
}
V_2 -> V_89 = F_61 ( L_21 , F_16 ( V_2 ) ,
sizeof( struct V_108 ) , 16 , 0 ) ;
if ( ! V_2 -> V_89 ) {
F_38 ( F_16 ( V_2 ) , L_22 ) ;
goto V_109;
}
V_2 -> V_88 = F_61 ( L_23 , F_16 ( V_2 ) ,
sizeof( struct V_110 ) , 16 , 0 ) ;
if ( ! V_2 -> V_88 ) {
F_38 ( F_16 ( V_2 ) , L_24 ) ;
goto V_111;
}
V_2 -> V_87 = F_62 ( V_2 ) ;
if ( ! V_2 -> V_87 ) {
F_38 ( F_16 ( V_2 ) , L_25 ) ;
goto V_112;
}
for ( V_82 = 0 ; V_82 < V_86 ; V_82 ++ ) {
V_2 -> V_6 [ V_82 ] = F_63 ( V_2 , NULL , NULL ) ;
if ( ! V_2 -> V_6 [ V_82 ] ) {
F_38 ( F_16 ( V_2 ) , L_26 ) ;
goto V_113;
}
}
for ( V_82 = V_114 + 1 ; V_82 < V_115 ; ++ V_82 )
V_2 -> V_6 [ V_82 ] -> V_116 = F_3 ( V_2 , V_2 -> V_117 ) ;
V_2 -> V_117 -> V_116 = F_64 ( V_2 ) ;
V_2 -> V_118 -> V_116 = F_3 ( V_2 , V_2 -> V_118 ) ;
F_65 ( V_2 , V_2 -> V_87 , 0 , F_66 ( 0 ) |
( 0x7f << V_119 ) | V_120 , 0 ) ;
V_2 -> V_87 -> V_116 = F_64 ( V_2 ) ;
V_2 -> V_117 -> V_121 = V_2 -> V_118 -> V_121 =
F_67 ( V_2 , V_2 -> V_87 ) ;
for ( V_82 = 0 ; V_82 < V_5 ; V_82 ++ ) {
V_2 -> V_3 [ V_82 ] = F_1 ( V_2 , V_82 ) ;
}
F_12 () ;
F_19 ( V_2 ) ;
V_2 -> V_84 = 1 ;
F_29 ( & V_2 -> V_41 ) ;
F_33 ( V_2 ) ;
F_27 ( & V_2 -> V_41 ) ;
return 0 ;
V_113:
for ( V_82 = 0 ; V_82 < V_86 ; V_82 ++ ) {
if ( V_2 -> V_6 [ V_82 ] )
F_47 ( V_2 , V_2 -> V_6 [ V_82 ] ) ;
}
F_48 ( V_2 , V_2 -> V_87 ) ;
V_112:
F_49 ( V_2 -> V_88 ) ;
V_111:
F_49 ( V_2 -> V_89 ) ;
V_109:
F_50 ( V_2 -> V_90 ) ;
V_107:
F_51 ( F_16 ( V_2 ) ,
V_5 * sizeof( * V_2 -> V_3 ) ,
V_2 -> V_3 , V_2 -> V_34 ) ;
V_105:
F_46 ( V_2 -> V_85 ) ;
return V_91 ;
}
static void F_68 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
F_29 ( & V_2 -> V_41 ) ;
if ( F_69 ( V_69 ) && ! V_2 -> V_19 )
F_8 ( V_2 ) ;
F_31 ( V_2 ) ;
F_27 ( & V_2 -> V_41 ) ;
F_70 ( V_69 -> V_122 ) ;
F_71 ( & V_2 -> V_94 ) ;
F_45 ( V_2 ) ;
}
static int F_72 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
int V_123 = 0 ;
F_29 ( & V_2 -> V_41 ) ;
if ( ! F_69 ( V_69 ) )
V_123 = - V_124 ;
else if ( V_2 -> V_19 )
;
else if ( V_69 -> V_48 . V_49 -> V_52 &&
V_2 -> V_11 ) {
F_18 ( F_16 ( V_2 ) , L_27
L_28 ) ;
V_123 = - V_92 ;
} else
F_24 ( V_2 , V_62 ) ;
F_27 ( & V_2 -> V_41 ) ;
return V_123 ;
}
static int F_73 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
int V_123 = 0 ;
F_29 ( & V_2 -> V_41 ) ;
if ( ! F_69 ( V_69 ) )
V_123 = - V_124 ;
else if ( ! V_2 -> V_19 )
F_34 ( V_2 ) ;
F_27 ( & V_2 -> V_41 ) ;
return V_123 ;
}
static void F_74 ( struct V_68 * V_69 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
struct V_110 * V_127 ;
F_29 ( & V_2 -> V_41 ) ;
V_127 = (struct V_110 * ) V_126 -> V_128 ;
if ( V_127 == NULL )
goto V_129;
while ( V_127 -> V_130 != V_131 ) {
++ V_2 -> V_132 ;
F_27 ( & V_2 -> V_41 ) ;
F_75 ( V_2 -> V_97 ,
V_127 -> V_130 == V_131 ) ;
F_29 ( & V_2 -> V_41 ) ;
-- V_2 -> V_132 ;
}
F_47 ( V_2 , V_127 ) ;
V_129:
F_27 ( & V_2 -> V_41 ) ;
}
static int F_76 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
unsigned V_20 ;
unsigned V_81 ;
V_20 = V_2 -> V_20 ;
F_77 () ;
V_81 = ( F_14 ( V_2 , V_37 ) - V_20 ) &
( V_5 - 1 ) ;
return V_20 + V_81 ;
}
static int F_78 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
unsigned V_133 = ( unsigned ) V_69 -> V_134 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < ( V_133 - V_9 ) / 2 ; V_7 ++ ) {
unsigned int V_135 ;
V_135 = F_14 ( V_2 , V_9 + ( V_7 * 2 ) ) ;
if ( ! ( V_135 & 0x0080 ) || V_135 == 0xffff )
break;
}
if ( V_77 )
F_79 ( F_16 ( V_2 ) , L_29 , V_7 ) ;
if ( V_7 > V_136 ) {
F_79 ( F_16 ( V_2 ) , L_30
L_31 ) ;
V_7 = 2 ;
}
return V_7 ;
}
static int T_4 F_80 ( void )
{
int V_91 = - V_104 ;
if ( F_81 () )
return - V_137 ;
F_82 ( V_138 L_32 V_139 L_33 ,
V_38 ? L_34 : L_7 ) ;
F_30 ( V_140 , & V_141 ) ;
if ( V_83 ) {
V_78 = F_83 ( V_79 , V_106 ) ;
if ( ! V_78 )
goto V_142;
V_102 = F_84 ( L_35 , V_143 ) ;
if ( ! V_102 )
goto V_144;
}
V_145 = F_85 ( L_36 ,
sizeof( struct V_146 ) , 0 , 0 , NULL ) ;
if ( ! V_145 )
goto V_147;
#ifdef F_86
V_91 = F_87 ( & F_86 ) ;
if ( V_91 < 0 )
goto V_148;
#endif
#ifdef F_88
V_91 = F_89 ( & F_88 ) ;
if ( V_91 < 0 )
goto V_149;
#endif
return 0 ;
#ifdef F_88
V_149:
#endif
#ifdef F_86
F_90 ( & F_86 ) ;
V_148:
#endif
F_91 ( V_145 ) ;
V_147:
F_46 ( V_102 ) ;
V_144:
F_50 ( V_78 ) ;
V_142:
F_6 ( V_140 , & V_141 ) ;
return V_91 ;
}
static void T_5 F_92 ( void )
{
#ifdef F_86
F_90 ( & F_86 ) ;
#endif
#ifdef F_88
F_93 ( & F_88 ) ;
#endif
F_91 ( V_145 ) ;
F_46 ( V_102 ) ;
F_50 ( V_78 ) ;
F_6 ( V_140 , & V_141 ) ;
}
