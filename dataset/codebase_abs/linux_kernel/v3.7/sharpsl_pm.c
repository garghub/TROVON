int F_1 ( int V_1 )
{
if ( F_2 () )
return 0 ;
return F_3 ( V_1 >> 1 ) ;
}
static int F_4 ( int V_2 )
{
int V_3 = V_4 . V_5 -> V_6 - 1 ;
int V_7 = V_4 . V_5 -> V_8 ? V_4 . V_5 -> V_8 () : 0 ;
struct V_9 * V_10 ;
if ( V_4 . V_11 == V_12 )
V_10 = V_7 ? V_4 . V_5 -> V_13 : V_4 . V_5 -> V_14 ;
else
V_10 = V_7 ? V_4 . V_5 -> V_15 : V_4 . V_5 -> V_16 ;
while ( V_3 > 0 && ( V_2 > V_10 [ V_3 ] . V_2 ) )
V_3 -- ;
return V_10 [ V_3 ] . V_17 ;
}
static int F_5 ( int V_2 )
{
int V_18 , V_19 ;
if ( V_4 . V_11 == V_12 ) {
V_19 = V_4 . V_5 -> V_20 ;
V_18 = V_4 . V_5 -> V_21 ;
} else {
V_19 = V_4 . V_5 -> V_22 ;
V_18 = V_4 . V_5 -> V_23 ;
}
if ( V_2 >= V_19 )
return V_24 ;
if ( V_2 >= V_18 )
return V_25 ;
return V_26 ;
}
void F_6 ( void )
{
F_7 ( & V_27 , F_8 ( 125 ) ) ;
}
static void F_9 ( struct V_28 * V_29 )
{
int V_2 , V_30 , V_31 , V_3 ;
if ( ! V_4 . V_5 )
return;
V_4 . V_32 . V_33 = ( V_4 . V_5 -> V_34 ( V_35 ) ? V_36 : V_37 ) ;
if ( ! V_4 . V_5 -> V_38 && ( V_4 . V_11 == V_12 )
&& F_10 ( V_39 , V_4 . V_40 + V_41 ) )
F_7 ( & V_42 , 0 ) ;
for ( V_3 = 0 ; V_3 < 5 ; V_3 ++ ) {
V_2 = V_4 . V_5 -> V_34 ( V_43 ) ;
if ( V_2 > 0 )
break;
}
if ( V_2 <= 0 ) {
V_2 = V_4 . V_5 -> V_16 [ 0 ] . V_2 ;
F_11 ( V_4 . V_44 , L_1 ) ;
}
V_2 = F_12 ( V_2 ) ;
V_31 = F_5 ( V_2 ) ;
V_30 = F_4 ( V_2 ) ;
if ( ( V_4 . V_32 . V_33 == V_36 )
|| ( V_31 == V_24 )
|| V_30 <= V_4 . V_32 . V_45 ) {
V_4 . V_32 . V_46 = V_2 ;
V_4 . V_32 . V_47 = V_31 ;
V_4 . V_32 . V_45 = V_30 ;
}
F_13 ( V_4 . V_44 , L_2 , V_2 ,
V_4 . V_32 . V_47 , V_4 . V_32 . V_45 , V_39 ) ;
if ( ( V_4 . V_32 . V_33 != V_36 )
&& ( V_4 . V_32 . V_47 == V_26 )
&& ! ( V_4 . V_48 & V_49 ) ) {
V_4 . V_48 |= V_49 ;
F_14 ( V_4 . V_44 , L_3 ) ;
F_15 ( V_50 ) ;
}
F_7 ( & V_27 , V_51 ) ;
}
void F_16 ( int V_52 )
{
if ( V_52 == V_53 ) {
F_14 ( V_4 . V_44 , L_4 ) ;
} else if ( V_52 == V_54 ) {
F_13 ( V_4 . V_44 , L_5 ) ;
F_17 ( V_55 , V_56 ) ;
} else {
F_13 ( V_4 . V_44 , L_6 ) ;
F_17 ( V_55 , V_57 ) ;
}
}
static void F_18 ( void )
{
F_13 ( V_4 . V_44 , L_7 ) ;
V_4 . V_58 = 0 ;
V_4 . V_11 = V_12 ;
F_7 ( & V_42 , F_8 ( 250 ) ) ;
F_7 ( & V_27 , F_8 ( 500 ) ) ;
}
static void F_19 ( void )
{
F_13 ( V_4 . V_44 , L_8 ) ;
V_4 . V_5 -> V_59 ( 0 ) ;
F_16 ( V_60 ) ;
V_4 . V_11 = V_61 ;
F_7 ( & V_27 , 0 ) ;
}
static void F_20 ( void )
{
F_16 ( V_53 ) ;
V_4 . V_5 -> V_59 ( 0 ) ;
V_4 . V_11 = V_62 ;
}
static void F_21 ( struct V_28 * V_29 )
{
F_13 ( V_4 . V_44 , L_9 , V_39 ) ;
if ( ! V_4 . V_5 -> V_34 ( V_35 ) ) {
F_19 () ;
return;
} else if ( ( F_22 () < 0 ) || ( F_23 () < 0 ) ) {
F_20 () ;
return;
}
F_16 ( V_54 ) ;
V_4 . V_5 -> V_59 ( 0 ) ;
F_24 ( V_63 ) ;
V_4 . V_5 -> V_59 ( 1 ) ;
V_4 . V_40 = V_39 ;
}
static void F_25 ( unsigned long V_64 )
{
int V_65 = V_4 . V_5 -> V_34 ( V_35 ) ;
F_13 ( V_4 . V_44 , L_10 , V_65 ) ;
F_26 () ;
if ( V_65 && ( V_4 . V_11 != V_12 ) )
F_18 () ;
else if ( V_4 . V_11 == V_12 )
F_19 () ;
F_7 ( & V_27 , 0 ) ;
}
static T_1 F_27 ( int V_66 , void * V_67 )
{
F_28 ( & V_4 . V_68 , V_39 + F_8 ( 250 ) ) ;
return V_69 ;
}
static void F_29 ( unsigned long V_64 )
{
F_13 ( V_4 . V_44 , L_11 , V_39 ) ;
V_4 . V_58 ++ ;
if ( ! V_4 . V_5 -> V_34 ( V_35 ) ) {
F_13 ( V_4 . V_44 , L_12 ) ;
if ( V_4 . V_11 == V_12 )
F_19 () ;
} else if ( V_4 . V_58 < 2 ) {
F_13 ( V_4 . V_44 , L_13 ) ;
F_7 ( & V_42 , 0 ) ;
} else if ( F_10 ( V_39 , V_4 . V_40 + V_70 ) ) {
F_13 ( V_4 . V_44 , L_14 ) ;
F_7 ( & V_42 , 0 ) ;
} else {
F_19 () ;
V_4 . V_11 = V_71 ;
F_13 ( V_4 . V_44 , L_15 ) ;
}
}
static T_1 F_30 ( int V_66 , void * V_67 )
{
if ( V_4 . V_48 & V_72 )
return V_69 ;
F_28 ( & V_4 . V_73 , V_39 + F_8 ( 500 ) ) ;
return V_69 ;
}
static T_1 F_31 ( int V_66 , void * V_67 )
{
int V_74 = 0 ;
if ( ! V_4 . V_5 -> V_34 ( V_75 ) ) {
F_14 ( V_4 . V_44 , L_16 ) ;
V_74 = 1 ;
}
if ( ! V_4 . V_5 -> V_34 ( V_76 ) ) {
F_14 ( V_4 . V_44 , L_17 ) ;
V_74 = 1 ;
}
if ( ! ( V_4 . V_48 & V_49 ) && V_74 ) {
V_4 . V_48 |= V_49 ;
F_15 ( V_50 ) ;
}
return V_69 ;
}
static void F_26 ( void )
{
V_77 = 0 ;
}
static int F_12 ( int V_78 )
{
int V_3 , V_79 = 0 ;
static int V_80 [ V_81 + 1 ] ;
if ( V_4 . V_32 . V_47 != V_24 ) {
V_77 = 0 ;
return V_78 ;
}
V_80 [ V_77 ] = V_78 ;
V_77 ++ ;
if ( V_77 >= V_81 ) {
for ( V_3 = 0 ; V_3 < ( V_81 - 1 ) ; V_3 ++ )
V_80 [ V_3 ] = V_80 [ V_3 + 1 ] ;
V_77 = V_81 - 1 ;
}
for ( V_3 = 0 ; V_3 < V_77 ; V_3 ++ )
V_79 += V_80 [ V_3 ] ;
return V_79 / V_77 ;
}
static int F_32 ( int * V_52 )
{
int V_3 , V_82 , V_83 , V_84 , V_85 = 0 ;
V_84 = V_52 [ 0 ] ;
V_82 = 0 ;
for ( V_3 = 1 ; V_3 < 5 ; V_3 ++ ) {
if ( V_84 < V_52 [ V_3 ] ) {
V_84 = V_52 [ V_3 ] ;
V_82 = V_3 ;
}
}
V_84 = V_52 [ 4 ] ;
V_83 = 4 ;
for ( V_3 = 3 ; V_3 >= 0 ; V_3 -- ) {
if ( V_84 > V_52 [ V_3 ] ) {
V_84 = V_52 [ V_3 ] ;
V_83 = V_3 ;
}
}
for ( V_3 = 0 ; V_3 < 5 ; V_3 ++ )
if ( V_3 != V_82 && V_3 != V_83 )
V_85 += V_52 [ V_3 ] ;
F_13 ( V_4 . V_44 , L_18 , V_85 / 3 , V_52 [ 0 ] , V_52 [ 1 ] , V_52 [ 2 ] , V_52 [ 3 ] , V_52 [ 4 ] ) ;
return V_85 / 3 ;
}
static int F_22 ( void )
{
int V_52 , V_3 , V_86 [ 5 ] ;
for ( V_3 = 0 ; V_3 < 5 ; V_3 ++ ) {
F_24 ( V_87 ) ;
V_4 . V_5 -> V_88 ( 1 ) ;
F_24 ( V_87 ) ;
V_86 [ V_3 ] = V_4 . V_5 -> V_34 ( V_89 ) ;
V_4 . V_5 -> V_88 ( 0 ) ;
}
V_52 = F_32 ( V_86 ) ;
F_13 ( V_4 . V_44 , L_19 , V_52 ) ;
if ( V_52 > V_4 . V_5 -> V_90 ) {
F_33 ( V_91 L_20 ) ;
return - 1 ;
}
return 0 ;
}
static int F_34 ( void )
{
int V_52 , V_3 , V_86 [ 5 ] ;
V_4 . V_5 -> V_59 ( 0 ) ;
V_4 . V_5 -> V_92 ( 1 ) ;
F_24 ( V_93 ) ;
if ( V_4 . V_5 -> V_94 )
V_4 . V_5 -> V_94 ( 1 ) ;
for ( V_3 = 0 ; V_3 < 5 ; V_3 ++ ) {
V_86 [ V_3 ] = V_4 . V_5 -> V_34 ( V_43 ) ;
F_24 ( V_95 ) ;
}
if ( V_4 . V_5 -> V_94 )
V_4 . V_5 -> V_94 ( 0 ) ;
V_4 . V_5 -> V_92 ( 0 ) ;
V_52 = F_32 ( V_86 ) ;
F_13 ( V_4 . V_44 , L_21 , V_52 ) ;
if ( V_52 < V_4 . V_5 -> V_96 )
return - 1 ;
return 0 ;
}
static int F_23 ( void )
{
int V_84 , V_3 , V_86 [ 5 ] ;
for ( V_3 = 0 ; V_3 < 5 ; V_3 ++ ) {
V_86 [ V_3 ] = V_4 . V_5 -> V_34 ( V_97 ) ;
F_24 ( V_98 ) ;
}
V_84 = F_32 ( V_86 ) ;
F_13 ( V_4 . V_44 , L_22 , V_84 ) ;
if ( ( V_84 > V_4 . V_5 -> V_99 ) || ( V_84 < V_4 . V_5 -> V_100 ) ) {
F_14 ( V_4 . V_44 , L_23 , V_84 ) ;
return - 1 ;
}
return 0 ;
}
static int F_35 ( struct V_101 * V_102 , T_2 V_103 )
{
V_4 . V_48 |= V_72 ;
F_36 ( & V_42 ) ;
F_36 ( & V_27 ) ;
if ( V_4 . V_11 == V_12 )
V_4 . V_48 |= V_104 ;
else
V_4 . V_48 &= ~ V_104 ;
return 0 ;
}
static int F_37 ( struct V_101 * V_102 )
{
V_105 = 0x0f ;
F_26 () ;
V_4 . V_48 &= ~ V_49 ;
V_4 . V_48 &= ~ V_72 ;
return 0 ;
}
static void F_38 ( unsigned long V_106 , unsigned int V_107 , T_3 V_103 )
{
F_13 ( V_4 . V_44 , L_24 , V_108 ) ;
F_13 ( V_4 . V_44 , L_25 , V_4 . V_48 & V_104 ) ;
if ( ( V_4 . V_48 & V_104 ) && ( V_4 . V_5 -> V_34 ( V_35 ) ) ) {
F_13 ( V_4 . V_44 , L_26 ) ;
V_4 . V_11 = V_61 ;
V_4 . V_48 &= ~ V_104 ;
F_39 () ;
}
V_4 . V_5 -> V_109 () ;
V_110 = 0xffffffff ;
V_4 . V_48 &= ~ V_111 ;
if ( ( V_4 . V_11 == V_12 ) && ( ( V_107 && ( ( V_106 - V_108 ) > ( V_112 + 30 ) ) ) || ! V_107 ) ) {
V_113 &= V_114 ;
V_115 = V_108 + V_112 ;
F_13 ( V_4 . V_44 , L_27 , V_115 ) ;
V_4 . V_48 |= V_111 ;
} else if ( V_107 ) {
V_113 &= V_114 ;
V_115 = V_106 ;
F_13 ( V_4 . V_44 , L_28 , V_115 ) ;
} else {
F_13 ( V_4 . V_44 , L_29 ) ;
}
F_40 ( V_103 ) ;
V_4 . V_5 -> V_116 () ;
F_13 ( V_4 . V_44 , L_30 , V_110 ) ;
}
static int F_41 ( unsigned long V_106 , unsigned int V_107 , T_3 V_103 )
{
if ( ! V_4 . V_5 -> V_117 ( ! ( V_4 . V_48 & V_111 ) && V_107 ) ) {
if ( ! ( V_4 . V_48 & V_111 ) ) {
F_13 ( V_4 . V_44 , L_31 ) ;
F_38 ( V_106 , V_107 , V_103 ) ;
return 1 ;
}
if ( F_39 () ) {
F_13 ( V_4 . V_44 , L_32 ) ;
F_38 ( V_106 , V_107 , V_103 ) ;
return 1 ;
}
F_13 ( V_4 . V_44 , L_33 ) ;
}
if ( ( ! V_4 . V_5 -> V_34 ( V_75 ) ) ||
( ! V_4 . V_5 -> V_34 ( V_76 ) ) ) {
F_14 ( V_4 . V_44 , L_34 ) ;
F_38 ( V_106 , V_107 , V_103 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( T_3 V_103 )
{
unsigned long V_106 = V_115 ;
unsigned int V_118 = ( ( V_113 & V_114 ) != 0 ) ;
F_13 ( V_4 . V_44 , L_35 ) ;
F_38 ( V_106 , V_118 , V_103 ) ;
while ( F_41 ( V_106 , V_118 , V_103 ) )
{}
if ( V_4 . V_5 -> V_119 )
V_4 . V_5 -> V_119 () ;
F_13 ( V_4 . V_44 , L_36 ) ;
return 0 ;
}
static int F_43 ( void )
{
F_14 ( V_4 . V_44 , L_37 ) ;
V_4 . V_5 -> V_59 ( 0 ) ;
F_16 ( V_53 ) ;
V_4 . V_11 = V_62 ;
return 1 ;
}
static int F_39 ( void )
{
int time ;
F_13 ( V_4 . V_44 , L_38 , V_4 . V_11 ) ;
if ( V_4 . V_11 == V_61 ) {
F_13 ( V_4 . V_44 , L_39 ) ;
if ( ( F_23 () < 0 ) || ( F_22 () < 0 ) )
return F_43 () ;
F_16 ( V_54 ) ;
V_4 . V_5 -> V_59 ( 0 ) ;
F_24 ( V_63 ) ;
V_4 . V_5 -> V_59 ( 1 ) ;
V_4 . V_11 = V_12 ;
V_4 . V_58 = 0 ;
return 1 ;
} else if ( V_4 . V_11 != V_12 ) {
return 1 ;
}
if ( V_4 . V_58 == 0 ) {
int time ;
F_13 ( V_4 . V_44 , L_40 ) ;
if ( ( F_22 () < 0 ) || ( F_34 () < 0 ) )
return F_43 () ;
V_4 . V_5 -> V_59 ( 0 ) ;
F_24 ( V_63 ) ;
V_4 . V_5 -> V_59 ( 1 ) ;
V_4 . V_11 = V_12 ;
F_24 ( V_120 ) ;
time = V_108 ;
while ( 1 ) {
if ( V_4 . V_5 -> V_121 () != 0 )
return 0 ;
if ( ( V_108 - time ) > V_122 )
return 1 ;
if ( V_4 . V_5 -> V_34 ( V_123 ) ) {
F_13 ( V_4 . V_44 , L_41 ) ;
V_4 . V_58 ++ ;
V_4 . V_5 -> V_59 ( 0 ) ;
F_24 ( V_63 ) ;
V_4 . V_5 -> V_59 ( 1 ) ;
return 1 ;
}
}
}
F_13 ( V_4 . V_44 , L_42 ) ;
F_24 ( V_120 ) ;
time = V_108 ;
while ( 1 ) {
if ( V_4 . V_5 -> V_121 () )
return 0 ;
if ( ( V_108 - time ) > V_122 ) {
if ( V_4 . V_58 > V_124 ) {
F_13 ( V_4 . V_44 , L_43 ) ;
V_4 . V_58 = 0 ;
}
V_4 . V_58 ++ ;
return 1 ;
}
if ( V_4 . V_5 -> V_34 ( V_123 ) ) {
F_13 ( V_4 . V_44 , L_44 ) ;
F_16 ( V_60 ) ;
V_4 . V_5 -> V_59 ( 0 ) ;
V_4 . V_11 = V_71 ;
return 1 ;
}
}
}
static T_4 F_44 ( struct V_125 * V_44 , struct V_126 * V_127 , char * V_128 )
{
return sprintf ( V_128 , L_45 , V_4 . V_32 . V_45 ) ;
}
static T_4 F_45 ( struct V_125 * V_44 , struct V_126 * V_127 , char * V_128 )
{
return sprintf ( V_128 , L_45 , V_4 . V_32 . V_46 ) ;
}
static void F_46 ( struct V_129 * V_130 )
{
V_130 -> V_131 = V_4 . V_32 . V_33 ;
if ( V_4 . V_11 == V_12 )
V_130 -> V_132 = V_133 ;
else
V_130 -> V_132 = V_4 . V_32 . V_47 ;
V_130 -> V_134 = ( 1 << V_130 -> V_132 ) ;
V_130 -> V_135 = V_4 . V_32 . V_45 ;
}
static int T_5 F_47 ( struct V_101 * V_102 )
{
int V_136 , V_66 ;
if ( ! V_102 -> V_44 . V_137 )
return - V_138 ;
V_4 . V_44 = & V_102 -> V_44 ;
V_4 . V_5 = V_102 -> V_44 . V_137 ;
V_4 . V_11 = V_61 ;
V_4 . V_48 = 0 ;
F_48 ( & V_4 . V_68 ) ;
V_4 . V_68 . V_139 = F_25 ;
F_48 ( & V_4 . V_73 ) ;
V_4 . V_73 . V_139 = F_29 ;
F_49 ( L_46 , & V_55 ) ;
V_4 . V_5 -> V_140 () ;
F_50 ( V_4 . V_5 -> V_141 , L_47 ) ;
F_51 ( V_4 . V_5 -> V_141 ) ;
F_50 ( V_4 . V_5 -> V_142 , L_48 ) ;
F_51 ( V_4 . V_5 -> V_142 ) ;
F_50 ( V_4 . V_5 -> V_143 , L_49 ) ;
F_51 ( V_4 . V_5 -> V_143 ) ;
V_66 = F_52 ( V_4 . V_5 -> V_141 ) ;
if ( F_53 ( V_66 , F_27 , V_144 | V_145 | V_146 , L_50 , F_27 ) ) {
F_14 ( V_4 . V_44 , L_51 , V_66 ) ;
}
V_66 = F_52 ( V_4 . V_5 -> V_143 ) ;
if ( F_53 ( V_66 , F_31 , V_144 | V_146 , L_52 , F_31 ) ) {
F_14 ( V_4 . V_44 , L_51 , V_66 ) ;
}
if ( V_4 . V_5 -> V_147 ) {
V_66 = F_52 ( V_4 . V_5 -> V_147 ) ;
if ( F_53 ( V_66 , F_31 , V_144 | V_146 , L_53 , F_31 ) ) {
F_14 ( V_4 . V_44 , L_51 , V_66 ) ;
}
}
if ( V_4 . V_5 -> V_38 ) {
V_66 = F_52 ( V_4 . V_5 -> V_142 ) ;
if ( F_53 ( V_66 , F_30 , V_144 | V_145 , L_54 , F_30 ) ) {
F_14 ( V_4 . V_44 , L_51 , V_66 ) ;
}
}
V_136 = F_54 ( & V_102 -> V_44 , & V_148 ) ;
V_136 |= F_54 ( & V_102 -> V_44 , & V_149 ) ;
if ( V_136 != 0 )
F_11 ( & V_102 -> V_44 , L_55 , V_136 ) ;
V_150 = F_46 ;
#ifdef F_55
F_56 ( & V_151 ) ;
#endif
F_28 ( & V_4 . V_68 , V_39 + F_8 ( 250 ) ) ;
return 0 ;
}
static int F_57 ( struct V_101 * V_102 )
{
F_56 ( NULL ) ;
F_58 ( & V_102 -> V_44 , & V_148 ) ;
F_58 ( & V_102 -> V_44 , & V_149 ) ;
F_59 ( V_55 ) ;
F_60 ( F_52 ( V_4 . V_5 -> V_141 ) , F_27 ) ;
F_60 ( F_52 ( V_4 . V_5 -> V_143 ) , F_31 ) ;
if ( V_4 . V_5 -> V_147 )
F_60 ( F_52 ( V_4 . V_5 -> V_147 ) , F_31 ) ;
if ( V_4 . V_5 -> V_38 )
F_60 ( F_52 ( V_4 . V_5 -> V_142 ) , F_30 ) ;
F_61 ( V_4 . V_5 -> V_143 ) ;
F_61 ( V_4 . V_5 -> V_142 ) ;
F_61 ( V_4 . V_5 -> V_141 ) ;
if ( V_4 . V_5 -> exit )
V_4 . V_5 -> exit () ;
F_62 ( & V_4 . V_73 ) ;
F_62 ( & V_4 . V_68 ) ;
return 0 ;
}
static int T_5 F_63 ( void )
{
return F_64 ( & V_152 ) ;
}
static void F_65 ( void )
{
F_66 ( & V_152 ) ;
}
