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
F_38 ( & V_2 -> V_41 ) ;
if ( F_39 ( ! V_2 -> V_72 ) )
goto V_73;
if ( V_70 & ~ ( V_74 | V_75 | V_76 ) ) {
if ( V_70 & V_77 )
F_40 ( F_16 ( V_2 ) ,
L_11 ) ;
if ( V_70 & V_78 )
F_40 ( F_16 ( V_2 ) ,
L_12 ) ;
if ( V_70 & V_55 ) {
if ( V_2 -> V_12 >= V_61 ) {
F_40 ( F_16 ( V_2 ) ,
L_13 ) ;
if ( V_79 > 1 && V_80 ) {
F_41 ( V_2 , V_80 ,
V_81 - V_82 ) ;
F_42 ( V_80 ) ;
}
F_8 ( V_2 ) ;
F_43 ( V_69 ) ;
F_35 ( & V_69 -> V_66 , V_67 ) ;
}
}
}
if ( V_70 & V_76 ) {
F_44 ( & V_2 -> V_41 ) ;
F_45 ( V_69 ) ;
} else {
F_31 ( V_2 ) ;
V_73:
F_44 ( & V_2 -> V_41 ) ;
}
return V_83 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_14 ) {
unsigned V_84 ;
V_84 = ( F_14 ( V_2 , V_37 ) - V_2 -> V_20 ) &
( V_5 - 1 ) ;
V_2 -> V_20 += V_84 ;
}
}
static void F_46 ( struct V_1 * V_2 )
{
int V_85 ;
if ( V_86 ) {
F_29 ( & V_2 -> V_41 ) ;
V_2 -> V_72 = 0 ;
F_27 ( & V_2 -> V_41 ) ;
F_47 ( V_2 -> V_87 ) ;
}
for ( V_85 = 0 ; V_85 < V_88 ; V_85 ++ )
F_48 ( V_2 , V_2 -> V_6 [ V_85 ] ) ;
F_49 ( V_2 , V_2 -> V_89 ) ;
F_50 ( V_2 -> V_90 ) ;
F_50 ( V_2 -> V_91 ) ;
F_51 ( V_2 -> V_92 ) ;
F_52 ( F_16 ( V_2 ) ,
V_5 * sizeof( * V_2 -> V_3 ) ,
V_2 -> V_3 , V_2 -> V_34 ) ;
}
static int F_53 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
int V_93 = - V_94 ;
int V_85 ;
struct V_87 T_3 * V_87 ;
V_69 -> V_95 = 1 ;
if ( ! ( V_69 -> V_96 -> V_17 & V_97 ) )
V_69 -> V_48 . V_98 = ~ 0 ;
F_54 ( & V_2 -> V_41 ) ;
F_55 ( & V_2 -> V_99 , V_100 ,
( unsigned long ) V_2 ) ;
F_56 ( & V_2 -> V_101 ) ;
F_57 ( & V_2 -> V_102 ) ;
#ifdef F_58
V_87 = F_59 ( V_69 -> V_48 . V_103 ,
V_104 | V_105 | V_106 , V_107 ,
V_2 , & V_108 ) ;
if ( ! V_87 ) {
F_40 ( F_16 ( V_2 ) , L_14 ) ;
return - V_109 ;
}
V_2 -> V_87 = V_87 ;
#endif
V_2 -> V_3 = F_60 ( F_16 ( V_2 ) ,
V_5 * sizeof( * V_2 -> V_3 ) ,
& V_2 -> V_34 , 0 ) ;
if ( ! V_2 -> V_3 ) {
F_40 ( F_16 ( V_2 ) ,
L_15 ) ;
goto V_110;
}
memset ( V_2 -> V_3 , 0 , V_5 * sizeof( * V_2 -> V_3 ) ) ;
V_2 -> V_92 = F_61 ( V_5 , sizeof( * V_2 -> V_92 ) ,
V_111 ) ;
if ( ! V_2 -> V_92 ) {
F_40 ( F_16 ( V_2 ) ,
L_16 ) ;
goto V_112;
}
V_2 -> V_91 = F_62 ( L_17 , F_16 ( V_2 ) ,
sizeof( struct V_113 ) , 16 , 0 ) ;
if ( ! V_2 -> V_91 ) {
F_40 ( F_16 ( V_2 ) , L_18 ) ;
goto V_114;
}
V_2 -> V_90 = F_62 ( L_19 , F_16 ( V_2 ) ,
sizeof( struct V_115 ) , 16 , 0 ) ;
if ( ! V_2 -> V_90 ) {
F_40 ( F_16 ( V_2 ) , L_20 ) ;
goto V_116;
}
V_2 -> V_89 = F_63 ( V_2 ) ;
if ( ! V_2 -> V_89 ) {
F_40 ( F_16 ( V_2 ) , L_21 ) ;
goto V_117;
}
for ( V_85 = 0 ; V_85 < V_88 ; V_85 ++ ) {
V_2 -> V_6 [ V_85 ] = F_64 ( V_2 , NULL , NULL ) ;
if ( ! V_2 -> V_6 [ V_85 ] ) {
F_40 ( F_16 ( V_2 ) , L_22 ) ;
goto V_118;
}
}
for ( V_85 = V_119 + 1 ; V_85 < V_120 ; ++ V_85 )
V_2 -> V_6 [ V_85 ] -> V_121 = F_3 ( V_2 , V_2 -> V_122 ) ;
V_2 -> V_122 -> V_121 = F_65 ( V_2 ) ;
V_2 -> V_123 -> V_121 = F_3 ( V_2 , V_2 -> V_123 ) ;
F_66 ( V_2 , V_2 -> V_89 , 0 , F_67 ( 0 ) |
( 0x7f << V_124 ) | V_125 , 0 ) ;
V_2 -> V_89 -> V_121 = F_65 ( V_2 ) ;
V_2 -> V_122 -> V_126 = V_2 -> V_123 -> V_126 =
F_68 ( V_2 , V_2 -> V_89 ) ;
for ( V_85 = 0 ; V_85 < V_5 ; V_85 ++ ) {
V_2 -> V_3 [ V_85 ] = F_1 ( V_2 , V_85 ) ;
}
F_12 () ;
F_29 ( & V_2 -> V_41 ) ;
F_19 ( V_2 ) ;
V_2 -> V_72 = 1 ;
F_33 ( V_2 ) ;
F_27 ( & V_2 -> V_41 ) ;
return 0 ;
V_118:
for ( V_85 = 0 ; V_85 < V_88 ; V_85 ++ ) {
if ( V_2 -> V_6 [ V_85 ] )
F_48 ( V_2 , V_2 -> V_6 [ V_85 ] ) ;
}
F_49 ( V_2 , V_2 -> V_89 ) ;
V_117:
F_50 ( V_2 -> V_90 ) ;
V_116:
F_50 ( V_2 -> V_91 ) ;
V_114:
F_51 ( V_2 -> V_92 ) ;
V_112:
F_52 ( F_16 ( V_2 ) ,
V_5 * sizeof( * V_2 -> V_3 ) ,
V_2 -> V_3 , V_2 -> V_34 ) ;
V_110:
F_47 ( V_2 -> V_87 ) ;
return V_93 ;
}
static void F_69 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
F_29 ( & V_2 -> V_41 ) ;
if ( F_70 ( V_69 ) && ! V_2 -> V_19 )
F_8 ( V_2 ) ;
F_31 ( V_2 ) ;
F_27 ( & V_2 -> V_41 ) ;
F_71 ( V_69 -> V_127 ) ;
F_72 ( & V_2 -> V_99 ) ;
F_46 ( V_2 ) ;
}
static int F_73 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
int V_128 = 0 ;
F_29 ( & V_2 -> V_41 ) ;
if ( ! F_70 ( V_69 ) )
V_128 = - V_129 ;
else if ( V_2 -> V_19 )
;
else if ( V_69 -> V_48 . V_49 -> V_52 &&
V_2 -> V_11 ) {
F_18 ( F_16 ( V_2 ) ,
L_23 ) ;
V_128 = - V_94 ;
} else
F_24 ( V_2 , V_62 ) ;
F_27 ( & V_2 -> V_41 ) ;
return V_128 ;
}
static int F_74 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
int V_128 = 0 ;
F_29 ( & V_2 -> V_41 ) ;
if ( ! F_70 ( V_69 ) )
V_128 = - V_129 ;
else if ( ! V_2 -> V_19 )
F_34 ( V_2 ) ;
F_27 ( & V_2 -> V_41 ) ;
return V_128 ;
}
static void F_75 ( struct V_68 * V_69 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
struct V_115 * V_132 ;
F_29 ( & V_2 -> V_41 ) ;
V_132 = (struct V_115 * ) V_131 -> V_133 ;
if ( V_132 == NULL )
goto V_73;
while ( V_132 -> V_134 != V_135 ) {
++ V_2 -> V_136 ;
F_27 ( & V_2 -> V_41 ) ;
F_76 ( V_2 -> V_102 ,
V_132 -> V_134 == V_135 ) ;
F_29 ( & V_2 -> V_41 ) ;
-- V_2 -> V_136 ;
}
F_48 ( V_2 , V_132 ) ;
V_73:
F_27 ( & V_2 -> V_41 ) ;
}
static int F_77 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
unsigned V_20 ;
unsigned V_84 ;
V_20 = V_2 -> V_20 ;
F_78 () ;
V_84 = ( F_14 ( V_2 , V_37 ) - V_20 ) &
( V_5 - 1 ) ;
return V_20 + V_84 ;
}
static int F_79 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 ) ;
unsigned V_137 = ( unsigned ) V_69 -> V_138 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < ( V_137 - V_9 ) / 2 ; V_7 ++ ) {
unsigned int V_139 ;
V_139 = F_14 ( V_2 , V_9 + ( V_7 * 2 ) ) ;
if ( ! ( V_139 & 0x0080 ) || V_139 == 0xffff )
break;
}
if ( V_79 )
F_80 ( F_16 ( V_2 ) , L_24 , V_7 ) ;
if ( V_7 > V_140 ) {
F_80 ( F_16 ( V_2 ) ,
L_25 ) ;
V_7 = 2 ;
}
return V_7 ;
}
static int T_4 F_81 ( void )
{
int V_93 = - V_109 ;
if ( F_82 () )
return - V_141 ;
F_83 ( V_142 L_26 V_143 L_27 ,
V_38 ? L_28 : L_7 ) ;
F_30 ( V_144 , & V_145 ) ;
if ( V_86 ) {
V_80 = F_84 ( V_81 , V_111 ) ;
if ( ! V_80 )
goto V_146;
V_107 = F_85 ( L_29 , V_147 ) ;
if ( ! V_107 )
goto V_148;
}
V_149 = F_86 ( L_30 ,
sizeof( struct V_150 ) , 0 , 0 , NULL ) ;
if ( ! V_149 )
goto V_151;
#ifdef F_87
V_93 = F_88 ( & F_87 ) ;
if ( V_93 < 0 )
goto V_152;
#endif
#ifdef F_89
V_93 = F_90 ( & F_89 ) ;
if ( V_93 < 0 )
goto V_153;
#endif
return 0 ;
#ifdef F_89
V_153:
#endif
#ifdef F_87
F_91 ( & F_87 ) ;
V_152:
#endif
F_92 ( V_149 ) ;
V_151:
F_47 ( V_107 ) ;
V_148:
F_51 ( V_80 ) ;
V_146:
F_6 ( V_144 , & V_145 ) ;
return V_93 ;
}
static void T_5 F_93 ( void )
{
#ifdef F_87
F_91 ( & F_87 ) ;
#endif
#ifdef F_89
F_94 ( & F_89 ) ;
#endif
F_92 ( V_149 ) ;
F_47 ( V_107 ) ;
F_51 ( V_80 ) ;
F_6 ( V_144 , & V_145 ) ;
}
