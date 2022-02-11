int F_1 ( int V_1 )
{
return ! F_2 ( V_1 , V_2 , V_3 ) ;
}
int F_3 ( int (F_4)( struct V_4 * , struct V_5 * , struct V_6 * ) ,
struct V_4 * V_7 , struct V_5 * V_8 , struct V_6 * V_9 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_8 ( int V_1 )
{
F_9 ( V_22 , V_23 ) ;
F_10 ( V_1 , V_22 , V_23 ) ;
if ( F_11 ( 0 , V_22 , V_23 ) == - 1 )
return - 1 ;
else
return 0 ;
}
int F_12 ( int V_1 )
{
char V_24 [ 32 ] ;
int V_25 ;
V_25 = V_26 [ V_1 ] ;
if ( V_25 )
return V_25 ;
sprintf ( V_24 , L_1 , V_1 ) ;
V_25 = F_13 ( V_24 , V_27 ) ;
if ( V_25 < 0 )
F_14 ( - 1 , L_2 , V_24 ) ;
V_26 [ V_1 ] = V_25 ;
return V_25 ;
}
int F_15 ( int V_1 , T_1 V_28 , unsigned long long * V_29 )
{
T_2 V_10 ;
V_10 = F_16 ( F_12 ( V_1 ) , V_29 , sizeof( * V_29 ) , V_28 ) ;
if ( V_10 != sizeof *V_29 )
F_14 ( - 1 , L_3 , V_1 , ( unsigned long long ) V_28 ) ;
return 0 ;
}
void F_17 ( void )
{
if ( V_30 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 )
V_31 += sprintf ( V_31 , L_5 ) ;
if ( V_33 )
V_31 += sprintf ( V_31 , L_6 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_7 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_8 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_9 ) ;
V_31 += sprintf ( V_31 , L_10 ) ;
if ( V_35 )
V_31 += sprintf ( V_31 , L_11 , V_35 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_12 , V_36 ) ;
if ( V_37 )
V_31 += sprintf ( V_31 , L_13 , V_37 ) ;
if ( V_38 )
V_31 += sprintf ( V_31 , L_14 , V_38 ) ;
if ( ! V_39 )
goto V_40;
if ( V_41 )
V_31 += sprintf ( V_31 , L_15 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_16 ) ;
if ( V_43 )
V_31 += sprintf ( V_31 , L_17 ) ;
if ( V_43 && ! V_44 && ! V_45 )
V_31 += sprintf ( V_31 , L_18 ) ;
if ( V_43 )
V_31 += sprintf ( V_31 , L_19 ) ;
if ( V_46 )
V_31 += sprintf ( V_31 , L_20 ) ;
if ( V_47 )
V_31 += sprintf ( V_31 , L_21 ) ;
if ( V_48 )
V_31 += sprintf ( V_31 , L_22 ) ;
if ( V_49 )
V_31 += sprintf ( V_31 , L_23 ) ;
if ( V_50 )
V_31 += sprintf ( V_31 , L_24 ) ;
if ( V_51 ) {
V_31 += sprintf ( V_31 , L_25 ) ;
V_31 += sprintf ( V_31 , L_26 ) ;
V_31 += sprintf ( V_31 , L_27 ) ;
V_31 += sprintf ( V_31 , L_28 ) ;
}
if ( V_52 )
V_31 += sprintf ( V_31 , L_29 ) ;
if ( V_53 )
V_31 += sprintf ( V_31 , L_30 ) ;
if ( V_54 )
V_31 += sprintf ( V_31 , L_31 ) ;
if ( V_55 )
V_31 += sprintf ( V_31 , L_32 ) ;
if ( V_56 ) {
V_31 += sprintf ( V_31 , L_33 ) ;
V_31 += sprintf ( V_31 , L_34 ) ;
V_31 += sprintf ( V_31 , L_35 ) ;
}
if ( V_57 && ! V_58 ) {
if ( V_57 & V_59 )
V_31 += sprintf ( V_31 , L_36 ) ;
if ( V_57 & V_60 )
V_31 += sprintf ( V_31 , L_37 ) ;
if ( V_57 & V_61 )
V_31 += sprintf ( V_31 , L_38 ) ;
if ( V_57 & V_62 )
V_31 += sprintf ( V_31 , L_39 ) ;
if ( V_57 & V_63 )
V_31 += sprintf ( V_31 , L_40 ) ;
if ( V_57 & V_64 )
V_31 += sprintf ( V_31 , L_41 ) ;
} else if ( V_57 && V_58 ) {
if ( V_57 & V_59 )
V_31 += sprintf ( V_31 , L_42 ) ;
if ( V_57 & V_60 )
V_31 += sprintf ( V_31 , L_43 ) ;
if ( V_57 & V_61 )
V_31 += sprintf ( V_31 , L_44 ) ;
if ( V_57 & V_62 )
V_31 += sprintf ( V_31 , L_45 ) ;
if ( V_57 & V_63 )
V_31 += sprintf ( V_31 , L_40 ) ;
if ( V_57 & V_64 )
V_31 += sprintf ( V_31 , L_41 ) ;
V_31 += sprintf ( V_31 , L_46 ) ;
}
V_40:
V_31 += sprintf ( V_31 , L_47 ) ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_31 += sprintf ( V_31 , L_48 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
V_31 += sprintf ( V_31 , L_49 ,
V_18 -> V_21 , V_18 -> V_65 ) ;
V_31 += sprintf ( V_31 , L_50 , V_18 -> V_66 ) ;
V_31 += sprintf ( V_31 , L_51 , V_18 -> V_67 ) ;
V_31 += sprintf ( V_31 , L_52 , V_18 -> V_68 ) ;
V_31 += sprintf ( V_31 , L_53 , V_18 -> V_69 ) ;
V_31 += sprintf ( V_31 , L_54 ,
V_35 , V_18 -> V_70 ) ;
V_31 += sprintf ( V_31 , L_55 ,
V_36 , V_18 -> V_71 ) ;
V_31 += sprintf ( V_31 , L_54 ,
V_37 , V_18 -> V_72 ) ;
V_31 += sprintf ( V_31 , L_55 ,
V_38 , V_18 -> V_73 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_56 , V_18 -> V_74 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_57 , V_18 -> V_75 ) ;
}
if ( V_19 ) {
V_31 += sprintf ( V_31 , L_58 , V_19 -> V_76 ) ;
V_31 += sprintf ( V_31 , L_59 , V_19 -> V_77 ) ;
V_31 += sprintf ( V_31 , L_60 , V_19 -> V_78 ) ;
V_31 += sprintf ( V_31 , L_61 , V_19 -> V_79 ) ;
V_31 += sprintf ( V_31 , L_62 , V_19 -> V_80 ) ;
}
if ( V_20 ) {
V_31 += sprintf ( V_31 , L_63 , V_20 -> V_81 ) ;
V_31 += sprintf ( V_31 , L_64 , V_20 -> V_82 ) ;
V_31 += sprintf ( V_31 , L_65 , V_20 -> V_83 ) ;
V_31 += sprintf ( V_31 , L_66 , V_20 -> V_84 ) ;
V_31 += sprintf ( V_31 , L_67 , V_20 -> V_85 ) ;
V_31 += sprintf ( V_31 , L_68 , V_20 -> V_86 ) ;
if ( V_53 )
V_31 += sprintf ( V_31 , L_69 , V_20 -> V_87 ) ;
if ( V_54 )
V_31 += sprintf ( V_31 , L_70 , V_20 -> V_88 ) ;
if ( V_55 )
V_31 += sprintf ( V_31 , L_71 , V_20 -> V_89 ) ;
V_31 += sprintf ( V_31 , L_72 , V_20 -> V_90 ) ;
V_31 += sprintf ( V_31 , L_73 , V_20 -> V_91 ) ;
V_31 += sprintf ( V_31 , L_74 , V_20 -> V_92 ) ;
V_31 += sprintf ( V_31 , L_75 , V_20 -> V_93 ) ;
V_31 += sprintf ( V_31 , L_76 , V_20 -> V_94 ) ;
V_31 += sprintf ( V_31 , L_77 , V_20 -> V_95 ) ;
V_31 += sprintf ( V_31 , L_78 , V_20 -> V_96 ) ;
V_31 += sprintf ( V_31 , L_79 ,
V_20 -> V_97 ) ;
V_31 += sprintf ( V_31 , L_80 ,
V_20 -> V_98 ) ;
V_31 += sprintf ( V_31 , L_81 , V_20 -> V_99 ) ;
}
V_31 += sprintf ( V_31 , L_47 ) ;
return 0 ;
}
int F_19 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_100 ;
char * V_101 ;
if ( V_102 && ! ( V_18 -> V_65 & V_103 ) )
return 0 ;
if ( V_104 && ! ( V_18 -> V_65 & V_105 ) )
return 0 ;
V_100 = V_106 . V_107 + V_106 . V_108 / 1000000.0 ;
if ( V_18 == & V_109 . V_110 ) {
if ( V_30 )
V_31 += sprintf ( V_31 , L_82 ) ;
if ( V_32 )
V_31 += sprintf ( V_31 , L_82 ) ;
if ( V_33 )
V_31 += sprintf ( V_31 , L_82 ) ;
} else {
if ( V_30 ) {
if ( V_20 )
V_31 += sprintf ( V_31 , L_83 , V_20 -> V_81 ) ;
else
V_31 += sprintf ( V_31 , L_82 ) ;
}
if ( V_32 ) {
if ( V_19 )
V_31 += sprintf ( V_31 , L_83 , V_19 -> V_76 ) ;
else
V_31 += sprintf ( V_31 , L_82 ) ;
}
if ( V_33 )
V_31 += sprintf ( V_31 , L_83 , V_18 -> V_21 ) ;
}
if ( V_34 )
V_31 += sprintf ( V_31 , L_84 ,
1.0 / V_111 * V_18 -> V_67 / V_100 ) ;
if ( V_34 ) {
if ( ! V_112 )
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_18 -> V_68 / V_18 -> V_66 / V_113 ) ;
else
V_31 += sprintf ( V_31 , L_86 ) ;
}
if ( V_34 ) {
if ( V_114 )
V_31 += sprintf ( V_31 , L_84 , V_115 / V_111 * V_18 -> V_67 / V_18 -> V_68 ) ;
else
V_31 += sprintf ( V_31 , L_84 ,
1.0 * V_18 -> V_66 / V_111 * V_18 -> V_67 / V_18 -> V_68 / V_100 ) ;
}
V_31 += sprintf ( V_31 , L_84 , 1.0 * V_18 -> V_66 / V_111 / V_100 ) ;
if ( V_35 )
V_31 += sprintf ( V_31 , L_87 , V_18 -> V_70 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_87 , V_18 -> V_71 ) ;
if ( V_37 )
V_31 += sprintf ( V_31 , L_88 , V_18 -> V_72 ) ;
if ( V_38 )
V_31 += sprintf ( V_31 , L_89 , V_18 -> V_73 ) ;
if ( ! V_39 )
goto V_40;
if ( V_41 )
V_31 += sprintf ( V_31 , L_83 , V_18 -> V_74 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_83 , V_18 -> V_75 ) ;
if ( V_43 ) {
if ( ! V_116 )
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_18 -> V_69 / V_18 -> V_66 ) ;
else
V_31 += sprintf ( V_31 , L_86 ) ;
}
if ( ! ( V_18 -> V_65 & V_103 ) )
goto V_40;
if ( V_43 && ! V_44 && ! V_45 )
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_19 -> V_77 / V_18 -> V_66 ) ;
if ( V_43 )
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_19 -> V_78 / V_18 -> V_66 ) ;
if ( V_46 )
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_19 -> V_79 / V_18 -> V_66 ) ;
if ( V_47 )
V_31 += sprintf ( V_31 , L_83 , V_19 -> V_80 ) ;
if ( ! ( V_18 -> V_65 & V_105 ) )
goto V_40;
if ( V_48 )
V_31 += sprintf ( V_31 , L_83 , V_20 -> V_99 ) ;
if ( V_49 ) {
if ( V_20 -> V_117 == - 1 ) {
V_31 += sprintf ( V_31 , L_90 ) ;
} else {
V_31 += sprintf ( V_31 , L_85 ,
V_20 -> V_117 / 10.0 / V_100 ) ;
}
}
if ( V_50 )
V_31 += sprintf ( V_31 , L_83 , V_20 -> V_118 ) ;
if ( V_51 ) {
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_20 -> V_82 / V_18 -> V_66 ) ;
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_20 -> V_83 / V_18 -> V_66 ) ;
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_20 -> V_84 / V_18 -> V_66 ) ;
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_20 -> V_85 / V_18 -> V_66 ) ;
}
if ( V_52 )
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_20 -> V_86 / V_18 -> V_66 ) ;
if ( V_53 )
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_20 -> V_87 / V_18 -> V_66 ) ;
if ( V_54 )
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_20 -> V_88 / V_18 -> V_66 ) ;
if ( V_55 )
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_20 -> V_89 / V_18 -> V_66 ) ;
if ( V_56 ) {
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_20 -> V_90 / V_18 -> V_66 ) ;
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_20 -> V_91 / V_18 -> V_66 ) ;
V_31 += sprintf ( V_31 , L_85 , 100.0 * V_20 -> V_92 / V_18 -> V_66 ) ;
}
if ( V_100 < V_119 )
V_101 = L_85 ;
else
V_101 = L_91 ;
if ( V_57 && ! V_58 ) {
if ( V_57 & V_59 )
V_31 += sprintf ( V_31 , V_101 , V_20 -> V_93 * V_120 / V_100 ) ;
if ( V_57 & V_60 )
V_31 += sprintf ( V_31 , V_101 , V_20 -> V_94 * V_120 / V_100 ) ;
if ( V_57 & V_61 )
V_31 += sprintf ( V_31 , V_101 , V_20 -> V_95 * V_120 / V_100 ) ;
if ( V_57 & V_62 )
V_31 += sprintf ( V_31 , V_101 , V_20 -> V_96 * V_121 / V_100 ) ;
if ( V_57 & V_63 )
V_31 += sprintf ( V_31 , V_101 , 100.0 * V_20 -> V_97 * V_122 / V_100 ) ;
if ( V_57 & V_64 )
V_31 += sprintf ( V_31 , V_101 , 100.0 * V_20 -> V_98 * V_122 / V_100 ) ;
} else if ( V_57 && V_58 ) {
if ( V_57 & V_59 )
V_31 += sprintf ( V_31 , V_101 ,
V_20 -> V_93 * V_120 ) ;
if ( V_57 & V_60 )
V_31 += sprintf ( V_31 , V_101 ,
V_20 -> V_94 * V_120 ) ;
if ( V_57 & V_61 )
V_31 += sprintf ( V_31 , V_101 ,
V_20 -> V_95 * V_120 ) ;
if ( V_57 & V_62 )
V_31 += sprintf ( V_31 , V_101 ,
V_20 -> V_96 * V_121 ) ;
if ( V_57 & V_63 )
V_31 += sprintf ( V_31 , V_101 , 100.0 * V_20 -> V_97 * V_122 / V_100 ) ;
if ( V_57 & V_64 )
V_31 += sprintf ( V_31 , V_101 , 100.0 * V_20 -> V_98 * V_122 / V_100 ) ;
V_31 += sprintf ( V_31 , V_101 , V_100 ) ;
}
V_40:
V_31 += sprintf ( V_31 , L_47 ) ;
return 0 ;
}
void F_20 ( void )
{
T_3 * V_123 ;
if ( V_124 == V_125 )
V_123 = stdout ;
else
V_123 = V_124 ;
fputs ( V_126 , V_123 ) ;
fflush ( V_123 ) ;
V_31 = V_126 ;
}
void F_21 ( void )
{
fputs ( V_126 , V_124 ) ;
fflush ( V_124 ) ;
V_31 = V_126 ;
}
void F_22 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_127 ;
if ( ! V_127 || ! V_128 )
F_17 () ;
if ( V_14 . V_129 > 1 )
F_19 ( & V_109 . V_110 , & V_109 . V_130 ,
& V_109 . V_131 ) ;
V_127 = 1 ;
if ( V_128 )
return;
F_3 ( F_19 , V_18 , V_19 , V_20 ) ;
}
void
F_23 ( struct V_6 * V_132 , struct V_6 * V_133 )
{
if ( V_51 ) {
V_133 -> V_82 = V_132 -> V_82 - V_133 -> V_82 ;
V_133 -> V_83 = V_132 -> V_83 - V_133 -> V_83 ;
V_133 -> V_84 = V_132 -> V_84 - V_133 -> V_84 ;
V_133 -> V_85 = V_132 -> V_85 - V_133 -> V_85 ;
}
V_133 -> V_86 = V_132 -> V_86 - V_133 -> V_86 ;
if ( V_53 )
V_133 -> V_87 = V_132 -> V_87 - V_133 -> V_87 ;
if ( V_54 )
V_133 -> V_88 = V_132 -> V_88 - V_133 -> V_88 ;
if ( V_55 )
V_133 -> V_89 = V_132 -> V_89 - V_133 -> V_89 ;
V_133 -> V_90 = V_132 -> V_90 - V_133 -> V_90 ;
V_133 -> V_91 = V_132 -> V_91 - V_133 -> V_91 ;
V_133 -> V_92 = V_132 -> V_92 - V_133 -> V_92 ;
V_133 -> V_99 = V_132 -> V_99 ;
if ( V_133 -> V_117 > V_132 -> V_117 )
V_133 -> V_117 = - 1 ;
else
V_133 -> V_117 = V_132 -> V_117 - V_133 -> V_117 ;
V_133 -> V_118 = V_132 -> V_118 ;
F_24 ( V_132 -> V_93 , V_133 -> V_93 ) ;
F_24 ( V_132 -> V_94 , V_133 -> V_94 ) ;
F_24 ( V_132 -> V_95 , V_133 -> V_95 ) ;
F_24 ( V_132 -> V_96 , V_133 -> V_96 ) ;
F_24 ( V_132 -> V_97 , V_133 -> V_97 ) ;
F_24 ( V_132 -> V_98 , V_133 -> V_98 ) ;
}
void
F_25 ( struct V_5 * V_132 , struct V_5 * V_133 )
{
V_133 -> V_77 = V_132 -> V_77 - V_133 -> V_77 ;
V_133 -> V_78 = V_132 -> V_78 - V_133 -> V_78 ;
V_133 -> V_79 = V_132 -> V_79 - V_133 -> V_79 ;
V_133 -> V_80 = V_132 -> V_80 ;
}
void
F_26 ( struct V_4 * V_132 , struct V_4 * V_133 ,
struct V_5 * V_134 )
{
V_133 -> V_66 = V_132 -> V_66 - V_133 -> V_66 ;
if ( V_133 -> V_66 < ( 1000 * 1000 ) )
F_27 ( - 3 , L_92
L_93
L_94 ) ;
V_133 -> V_69 = V_132 -> V_69 - V_133 -> V_69 ;
if ( V_34 ) {
if ( ( V_132 -> V_67 > V_133 -> V_67 ) && ( V_132 -> V_68 > V_133 -> V_68 ) ) {
V_133 -> V_67 = V_132 -> V_67 - V_133 -> V_67 ;
V_133 -> V_68 = V_132 -> V_68 - V_133 -> V_68 ;
} else {
if ( ! V_135 ) {
fprintf ( V_124 , L_95 , V_136 ) ;
fprintf ( V_124 , L_96 ) ;
fprintf ( V_124 , L_97 ) ;
V_135 = 1 ;
}
V_112 = 1 ;
V_116 = 1 ;
}
}
if ( V_137 ) {
} else {
if ( ( V_133 -> V_68 + V_134 -> V_77 + V_134 -> V_78 + V_134 -> V_79 ) > V_133 -> V_66 )
V_133 -> V_69 = 0 ;
else {
V_133 -> V_69 = V_133 -> V_66 - V_133 -> V_68 - V_134 -> V_77
- V_134 -> V_78 - V_134 -> V_79 ;
}
}
if ( V_133 -> V_68 == 0 ) {
if ( V_39 > 1 )
fprintf ( V_124 , L_98 , V_133 -> V_21 ) ;
V_133 -> V_68 = 1 ;
}
V_133 -> V_70 = V_132 -> V_70 - V_133 -> V_70 ;
V_133 -> V_70 &= 0xFFFFFFFF ;
V_133 -> V_71 = V_132 -> V_71 - V_133 -> V_71 ;
V_133 -> V_72 = V_132 -> V_72 ;
V_133 -> V_73 = V_132 -> V_73 ;
if ( V_41 )
V_133 -> V_74 = V_132 -> V_74 - V_133 -> V_74 ;
if ( V_42 )
V_133 -> V_75 = V_132 -> V_75 - V_133 -> V_75 ;
}
int F_28 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_138 ,
struct V_5 * V_139 , struct V_6 * V_140 )
{
if ( V_18 -> V_65 & V_103 )
F_25 ( V_19 , V_139 ) ;
F_26 ( V_18 , V_138 , V_139 ) ;
if ( V_18 -> V_65 & V_105 )
F_23 ( V_20 , V_140 ) ;
return 0 ;
}
void F_29 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
V_18 -> V_66 = 0 ;
V_18 -> V_67 = 0 ;
V_18 -> V_68 = 0 ;
V_18 -> V_69 = 0 ;
V_18 -> V_70 = 0 ;
V_18 -> V_71 = 0 ;
V_18 -> V_74 = 0 ;
V_18 -> V_75 = 0 ;
V_18 -> V_65 = V_103 | V_105 ;
V_19 -> V_77 = 0 ;
V_19 -> V_78 = 0 ;
V_19 -> V_79 = 0 ;
V_19 -> V_80 = 0 ;
V_20 -> V_82 = 0 ;
V_20 -> V_83 = 0 ;
V_20 -> V_84 = 0 ;
V_20 -> V_85 = 0 ;
V_20 -> V_86 = 0 ;
if ( V_53 )
V_20 -> V_87 = 0 ;
if ( V_54 )
V_20 -> V_88 = 0 ;
if ( V_55 )
V_20 -> V_89 = 0 ;
V_20 -> V_90 = 0 ;
V_20 -> V_91 = 0 ;
V_20 -> V_92 = 0 ;
V_20 -> V_93 = 0 ;
V_20 -> V_96 = 0 ;
V_20 -> V_94 = 0 ;
V_20 -> V_95 = 0 ;
V_20 -> V_97 = 0 ;
V_20 -> V_98 = 0 ;
V_20 -> V_99 = 0 ;
V_20 -> V_117 = 0 ;
V_20 -> V_118 = 0 ;
}
int F_30 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_109 . V_110 . V_66 += V_18 -> V_66 ;
V_109 . V_110 . V_67 += V_18 -> V_67 ;
V_109 . V_110 . V_68 += V_18 -> V_68 ;
V_109 . V_110 . V_69 += V_18 -> V_69 ;
V_109 . V_110 . V_70 += V_18 -> V_70 ;
V_109 . V_110 . V_71 += V_18 -> V_71 ;
V_109 . V_110 . V_74 += V_18 -> V_74 ;
V_109 . V_110 . V_75 += V_18 -> V_75 ;
if ( ! ( V_18 -> V_65 & V_103 ) )
return 0 ;
V_109 . V_130 . V_77 += V_19 -> V_77 ;
V_109 . V_130 . V_78 += V_19 -> V_78 ;
V_109 . V_130 . V_79 += V_19 -> V_79 ;
V_109 . V_130 . V_80 = F_31 ( V_109 . V_130 . V_80 , V_19 -> V_80 ) ;
if ( ! ( V_18 -> V_65 & V_105 ) )
return 0 ;
if ( V_51 ) {
V_109 . V_131 . V_82 += V_20 -> V_82 ;
V_109 . V_131 . V_83 += V_20 -> V_83 ;
V_109 . V_131 . V_84 += V_20 -> V_84 ;
V_109 . V_131 . V_85 += V_20 -> V_85 ;
}
V_109 . V_131 . V_86 += V_20 -> V_86 ;
if ( V_53 )
V_109 . V_131 . V_87 += V_20 -> V_87 ;
if ( V_54 )
V_109 . V_131 . V_88 += V_20 -> V_88 ;
if ( V_55 )
V_109 . V_131 . V_89 += V_20 -> V_89 ;
V_109 . V_131 . V_90 += V_20 -> V_90 ;
V_109 . V_131 . V_91 += V_20 -> V_91 ;
V_109 . V_131 . V_92 += V_20 -> V_92 ;
V_109 . V_131 . V_93 += V_20 -> V_93 ;
V_109 . V_131 . V_96 += V_20 -> V_96 ;
V_109 . V_131 . V_94 += V_20 -> V_94 ;
V_109 . V_131 . V_95 += V_20 -> V_95 ;
V_109 . V_131 . V_117 = V_20 -> V_117 ;
V_109 . V_131 . V_118 = V_20 -> V_118 ;
V_109 . V_131 . V_99 = F_31 ( V_109 . V_131 . V_99 , V_20 -> V_99 ) ;
V_109 . V_131 . V_97 += V_20 -> V_97 ;
V_109 . V_131 . V_98 += V_20 -> V_98 ;
return 0 ;
}
void F_32 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_29 ( & V_109 . V_110 , & V_109 . V_130 , & V_109 . V_131 ) ;
F_3 ( F_30 , V_18 , V_19 , V_20 ) ;
V_109 . V_110 . V_66 /= V_14 . V_129 ;
V_109 . V_110 . V_67 /= V_14 . V_129 ;
V_109 . V_110 . V_68 /= V_14 . V_129 ;
V_109 . V_110 . V_69 /= V_14 . V_129 ;
V_109 . V_110 . V_70 /= V_14 . V_129 ;
V_109 . V_110 . V_70 &= 0xFFFFFFFF ;
V_109 . V_110 . V_71 /= V_14 . V_129 ;
V_109 . V_130 . V_77 /= V_14 . V_141 ;
V_109 . V_130 . V_78 /= V_14 . V_141 ;
V_109 . V_130 . V_79 /= V_14 . V_141 ;
if ( V_51 ) {
V_109 . V_131 . V_82 /= V_14 . V_15 ;
V_109 . V_131 . V_83 /= V_14 . V_15 ;
V_109 . V_131 . V_84 /= V_14 . V_15 ;
V_109 . V_131 . V_85 /= V_14 . V_15 ;
}
V_109 . V_131 . V_86 /= V_14 . V_15 ;
if ( V_53 )
V_109 . V_131 . V_87 /= V_14 . V_15 ;
if ( V_54 )
V_109 . V_131 . V_88 /= V_14 . V_15 ;
if ( V_55 )
V_109 . V_131 . V_89 /= V_14 . V_15 ;
V_109 . V_131 . V_90 /= V_14 . V_15 ;
V_109 . V_131 . V_91 /= V_14 . V_15 ;
V_109 . V_131 . V_92 /= V_14 . V_15 ;
}
static unsigned long long F_33 ( void )
{
unsigned int V_142 , V_143 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_142 | ( ( unsigned long long ) V_143 ) << 32 ;
}
int F_34 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
unsigned long long V_29 ;
int V_144 = 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_124 , L_99 , V_1 ) ;
return - 1 ;
}
V_145:
V_18 -> V_66 = F_33 () ;
if ( V_34 ) {
unsigned long long V_146 , V_147 , V_148 , V_149 , V_150 ;
if ( F_15 ( V_1 , V_151 , & V_18 -> V_67 ) )
return - 3 ;
V_18 -> V_66 = F_33 () ;
V_146 = V_18 -> V_66 ;
if ( F_15 ( V_1 , V_151 , & V_18 -> V_67 ) )
return - 3 ;
V_147 = F_33 () ;
if ( F_15 ( V_1 , V_152 , & V_18 -> V_68 ) )
return - 4 ;
V_148 = F_33 () ;
V_149 = V_147 - V_146 ;
V_150 = V_148 - V_147 ;
if ( ( V_149 > ( 2 * V_150 ) ) || ( V_150 > ( 2 * V_149 ) ) ) {
V_144 ++ ;
if ( V_144 < 5 )
goto V_145;
else
F_35 ( L_100 ,
V_1 , V_149 , V_150 ) ;
}
V_144 = 0 ;
V_18 -> V_67 = V_18 -> V_67 * V_153 ;
V_18 -> V_68 = V_18 -> V_68 * V_153 ;
}
if ( V_41 )
V_18 -> V_74 = V_154 [ V_1 ] ;
if ( V_42 ) {
if ( F_15 ( V_1 , V_155 , & V_29 ) )
return - 5 ;
V_18 -> V_75 = V_29 & 0xFFFFFFFF ;
}
if ( V_35 ) {
if ( F_15 ( V_1 , V_35 , & V_29 ) )
return - 5 ;
V_18 -> V_70 = V_29 & 0xFFFFFFFF ;
}
if ( V_36 )
if ( F_15 ( V_1 , V_36 , & V_18 -> V_71 ) )
return - 5 ;
if ( V_37 ) {
if ( F_15 ( V_1 , V_37 , & V_29 ) )
return - 5 ;
V_18 -> V_72 = V_29 & 0xFFFFFFFF ;
}
if ( V_38 )
if ( F_15 ( V_1 , V_38 , & V_18 -> V_73 ) )
return - 5 ;
if ( V_137 ) {
if ( F_15 ( V_1 , V_156 , & V_18 -> V_69 ) )
return - 6 ;
}
if ( ! ( V_18 -> V_65 & V_103 ) )
return 0 ;
if ( V_43 && ! V_44 && ! V_45 ) {
if ( F_15 ( V_1 , V_157 , & V_19 -> V_77 ) )
return - 6 ;
}
if ( V_43 && ! V_45 ) {
if ( F_15 ( V_1 , V_158 , & V_19 -> V_78 ) )
return - 7 ;
} else if ( V_45 ) {
if ( F_15 ( V_1 , V_159 , & V_19 -> V_78 ) )
return - 7 ;
}
if ( V_46 )
if ( F_15 ( V_1 , V_160 , & V_19 -> V_79 ) )
return - 8 ;
if ( V_47 ) {
if ( F_15 ( V_1 , V_161 , & V_29 ) )
return - 9 ;
V_19 -> V_80 = V_162 - ( ( V_29 >> 16 ) & 0x7F ) ;
}
if ( ! ( V_18 -> V_65 & V_105 ) )
return 0 ;
if ( V_51 ) {
if ( F_15 ( V_1 , V_163 , & V_20 -> V_82 ) )
return - 10 ;
if ( F_15 ( V_1 , V_164 , & V_20 -> V_83 ) )
return - 11 ;
if ( F_15 ( V_1 , V_165 , & V_20 -> V_84 ) )
return - 12 ;
if ( F_15 ( V_1 , V_166 , & V_20 -> V_85 ) )
return - 13 ;
}
if ( V_53 )
if ( F_15 ( V_1 , V_167 , & V_20 -> V_87 ) )
return - 9 ;
if ( V_54 )
if ( F_15 ( V_1 , V_168 , & V_20 -> V_88 ) )
return - 10 ;
if ( V_52 )
if ( F_15 ( V_1 , V_169 , & V_20 -> V_86 ) )
return - 11 ;
if ( V_55 )
if ( F_15 ( V_1 , V_170 , & V_20 -> V_89 ) )
return - 12 ;
if ( V_56 ) {
if ( F_15 ( V_1 , V_171 , & V_20 -> V_90 ) )
return - 13 ;
if ( F_15 ( V_1 , V_172 , & V_20 -> V_91 ) )
return - 13 ;
if ( F_15 ( V_1 , V_173 , & V_20 -> V_92 ) )
return - 13 ;
}
if ( V_57 & V_59 ) {
if ( F_15 ( V_1 , V_174 , & V_29 ) )
return - 13 ;
V_20 -> V_93 = V_29 & 0xFFFFFFFF ;
}
if ( V_57 & V_60 ) {
if ( F_15 ( V_1 , V_175 , & V_29 ) )
return - 14 ;
V_20 -> V_94 = V_29 & 0xFFFFFFFF ;
}
if ( V_57 & V_62 ) {
if ( F_15 ( V_1 , V_176 , & V_29 ) )
return - 15 ;
V_20 -> V_96 = V_29 & 0xFFFFFFFF ;
}
if ( V_57 & V_61 ) {
if ( F_15 ( V_1 , V_177 , & V_29 ) )
return - 16 ;
V_20 -> V_95 = V_29 & 0xFFFFFFFF ;
}
if ( V_57 & V_63 ) {
if ( F_15 ( V_1 , V_178 , & V_29 ) )
return - 16 ;
V_20 -> V_97 = V_29 & 0xFFFFFFFF ;
}
if ( V_57 & V_64 ) {
if ( F_15 ( V_1 , V_179 , & V_29 ) )
return - 16 ;
V_20 -> V_98 = V_29 & 0xFFFFFFFF ;
}
if ( V_48 ) {
if ( F_15 ( V_1 , V_180 , & V_29 ) )
return - 17 ;
V_20 -> V_99 = V_162 - ( ( V_29 >> 16 ) & 0x7F ) ;
}
if ( V_49 )
V_20 -> V_117 = V_181 ;
if ( V_50 )
V_20 -> V_118 = V_182 ;
return 0 ;
}
static void
F_36 ()
{
V_113 = V_115 / V_183 ;
}
static void
F_37 ( void )
{
unsigned long long V_29 ;
unsigned int V_184 ;
F_15 ( V_185 , V_186 , & V_29 ) ;
fprintf ( V_124 , L_101 , V_185 , V_29 ) ;
V_184 = ( V_29 >> 40 ) & 0xFF ;
fprintf ( V_124 , L_102 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 8 ) & 0xFF ;
fprintf ( V_124 , L_103 ,
V_184 , V_187 , V_184 * V_187 ) ;
F_15 ( V_185 , V_188 , & V_29 ) ;
fprintf ( V_124 , L_104 ,
V_185 , V_29 , V_29 & 0x2 ? L_105 : L_106 ) ;
return;
}
static void
F_38 ( void )
{
unsigned long long V_29 ;
unsigned int V_184 ;
F_15 ( V_185 , V_189 , & V_29 ) ;
fprintf ( V_124 , L_107 , V_185 , V_29 ) ;
V_184 = ( V_29 >> 8 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_108 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 0 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_109 ,
V_184 , V_187 , V_184 * V_187 ) ;
return;
}
static void
F_39 ( void )
{
unsigned long long V_29 ;
unsigned int V_184 ;
F_15 ( V_185 , V_190 , & V_29 ) ;
fprintf ( V_124 , L_110 , V_185 , V_29 ) ;
V_184 = ( V_29 >> 56 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_111 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 48 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_112 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 40 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_113 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 32 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_114 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 24 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_115 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 16 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_116 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 8 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_117 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 0 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_118 ,
V_184 , V_187 , V_184 * V_187 ) ;
return;
}
static void
F_40 ( void )
{
unsigned long long V_29 ;
unsigned int V_184 ;
F_15 ( V_185 , V_191 , & V_29 ) ;
fprintf ( V_124 , L_119 , V_185 , V_29 ) ;
V_184 = ( V_29 >> 56 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_120 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 48 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_121 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 40 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_122 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 32 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_123 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 24 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_124 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 16 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_125 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 8 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_126 ,
V_184 , V_187 , V_184 * V_187 ) ;
V_184 = ( V_29 >> 0 ) & 0xFF ;
if ( V_184 )
fprintf ( V_124 , L_127 ,
V_184 , V_187 , V_184 * V_187 ) ;
return;
}
static void
F_41 ( void )
{
const unsigned int V_192 = 7 ;
unsigned long long V_29 ;
int V_193 , V_194 ;
int V_195 , V_196 ;
unsigned int V_130 [ V_192 ] ;
unsigned int V_184 [ V_192 ] ;
F_15 ( V_185 , V_197 , & V_29 ) ;
fprintf ( V_124 , L_119 ,
V_185 , V_29 ) ;
V_196 = 0 ;
V_130 [ V_196 ] = ( V_29 & 0xFF ) >> 1 ;
V_184 [ V_196 ] = ( V_29 >> 8 ) & 0xFF ;
for ( V_195 = 16 ; V_195 < 64 ; V_195 += 8 ) {
V_193 = ( V_29 >> V_195 ) & 0x1F ;
V_194 = ( V_29 >> ( V_195 + 5 ) ) & 0x7 ;
V_130 [ V_196 + 1 ] = V_130 [ V_196 ] + V_193 ;
V_184 [ V_196 + 1 ] = V_184 [ V_196 ] - V_194 ;
V_196 ++ ;
}
for ( V_195 = V_192 - 1 ; V_195 >= 0 ; V_195 -- )
if ( V_195 > 0 ? V_184 [ V_195 ] != V_184 [ V_195 - 1 ] : 1 )
fprintf ( V_124 ,
L_128 ,
V_184 [ V_195 ] , V_187 , V_184 [ V_195 ] * V_187 , V_130 [ V_195 ] ) ;
}
static void
F_42 ( void )
{
unsigned long long V_29 ;
F_15 ( V_185 , V_198 , & V_29 ) ;
#define F_43 (1UL << 27)
#define F_44 (1UL << 28)
fprintf ( V_124 , L_129 , V_185 , V_29 ) ;
fprintf ( V_124 , L_130 ,
( V_29 & F_44 ) ? L_131 : L_132 ,
( V_29 & F_43 ) ? L_133 : L_132 ,
( V_29 & V_199 ) ? L_134 : L_132 ,
( V_29 & V_200 ) ? L_135 : L_132 ,
( V_29 & ( 1 << 15 ) ) ? L_132 : L_136 ,
( unsigned int ) V_29 & 0xF ,
V_201 [ V_202 ] ) ;
return;
}
static void
F_45 ( void )
{
unsigned long long V_29 ;
F_15 ( V_185 , V_203 , & V_29 ) ;
fprintf ( V_124 , L_137 , V_185 , V_29 ) ;
fprintf ( V_124 , L_138 , ( unsigned int ) V_29 & 0xFF ) ;
F_15 ( V_185 , V_204 , & V_29 ) ;
fprintf ( V_124 , L_139 , V_185 , V_29 ) ;
if ( V_29 ) {
fprintf ( V_124 , L_140 , ( unsigned int ) ( V_29 >> 48 ) & 0x7FFF ) ;
fprintf ( V_124 , L_141 , ( unsigned int ) ( V_29 >> 32 ) & 0x7FFF ) ;
fprintf ( V_124 , L_142 , ( unsigned int ) ( V_29 >> 16 ) & 0xFF ) ;
fprintf ( V_124 , L_143 , ( unsigned int ) ( V_29 ) & 0x7FFF ) ;
}
fprintf ( V_124 , L_144 ) ;
F_15 ( V_185 , V_205 , & V_29 ) ;
fprintf ( V_124 , L_145 , V_185 , V_29 ) ;
if ( V_29 ) {
fprintf ( V_124 , L_146 , ( unsigned int ) ( V_29 >> 48 ) & 0x7FFF ) ;
fprintf ( V_124 , L_147 , ( unsigned int ) ( V_29 >> 32 ) & 0x7FFF ) ;
fprintf ( V_124 , L_148 , ( unsigned int ) ( V_29 >> 16 ) & 0xFF ) ;
fprintf ( V_124 , L_149 , ( unsigned int ) ( V_29 ) & 0x7FFF ) ;
}
fprintf ( V_124 , L_144 ) ;
F_15 ( V_185 , V_206 , & V_29 ) ;
fprintf ( V_124 , L_150 , V_185 , V_29 ) ;
if ( ( V_29 ) & 0x3 )
fprintf ( V_124 , L_151 , ( unsigned int ) ( V_29 ) & 0x3 ) ;
fprintf ( V_124 , L_152 , ( unsigned int ) ( V_29 >> 31 ) & 1 ) ;
fprintf ( V_124 , L_144 ) ;
F_15 ( V_185 , V_207 , & V_29 ) ;
fprintf ( V_124 , L_153 , V_185 , V_29 ) ;
fprintf ( V_124 , L_154 , ( unsigned int ) ( V_29 ) & 0xFF ) ;
fprintf ( V_124 , L_152 , ( unsigned int ) ( V_29 >> 31 ) & 1 ) ;
fprintf ( V_124 , L_144 ) ;
}
void F_46 ( void )
{
unsigned long long V_29 ;
F_15 ( V_185 , V_208 , & V_29 ) ;
fprintf ( V_124 , L_155 , V_185 , V_29 ) ;
fprintf ( V_124 , L_156 , V_29 & ( 1 << 15 ) ? L_132 : L_157 ,
( V_29 & 0x3FF ) * V_209 [ ( V_29 >> 10 ) & 0x3 ] ) ;
F_15 ( V_185 , V_210 , & V_29 ) ;
fprintf ( V_124 , L_158 , V_185 , V_29 ) ;
fprintf ( V_124 , L_156 , V_29 & ( 1 << 15 ) ? L_132 : L_157 ,
( V_29 & 0x3FF ) * V_209 [ ( V_29 >> 10 ) & 0x3 ] ) ;
F_15 ( V_185 , V_211 , & V_29 ) ;
fprintf ( V_124 , L_159 , V_185 , V_29 ) ;
fprintf ( V_124 , L_156 , V_29 & ( 1 << 15 ) ? L_132 : L_157 ,
( V_29 & 0x3FF ) * V_209 [ ( V_29 >> 10 ) & 0x3 ] ) ;
if ( ! V_212 )
return;
F_15 ( V_185 , V_213 , & V_29 ) ;
fprintf ( V_124 , L_160 , V_185 , V_29 ) ;
fprintf ( V_124 , L_156 , V_29 & ( 1 << 15 ) ? L_132 : L_157 ,
( V_29 & 0x3FF ) * V_209 [ ( V_29 >> 10 ) & 0x3 ] ) ;
F_15 ( V_185 , V_214 , & V_29 ) ;
fprintf ( V_124 , L_161 , V_185 , V_29 ) ;
fprintf ( V_124 , L_156 , V_29 & ( 1 << 15 ) ? L_132 : L_157 ,
( V_29 & 0x3FF ) * V_209 [ ( V_29 >> 10 ) & 0x3 ] ) ;
F_15 ( V_185 , V_215 , & V_29 ) ;
fprintf ( V_124 , L_162 , V_185 , V_29 ) ;
fprintf ( V_124 , L_156 , V_29 & ( 1 << 15 ) ? L_132 : L_157 ,
( V_29 & 0x3FF ) * V_209 [ ( V_29 >> 10 ) & 0x3 ] ) ;
}
void F_47 ( void )
{
int V_195 ;
for ( V_195 = 0 ; V_195 < V_14 . V_216 ; ++ V_195 ) {
if ( V_26 [ V_195 ] != 0 )
F_48 ( V_26 [ V_195 ] ) ;
}
free ( V_26 ) ;
}
void F_49 ( void )
{
F_50 ( V_3 ) ;
V_3 = NULL ;
V_2 = 0 ;
F_50 ( V_23 ) ;
V_23 = NULL ;
V_22 = 0 ;
free ( V_217 ) ;
free ( V_218 ) ;
free ( V_219 ) ;
V_217 = NULL ;
V_218 = NULL ;
V_219 = NULL ;
free ( V_220 ) ;
free ( V_221 ) ;
free ( V_222 ) ;
V_220 = NULL ;
V_221 = NULL ;
V_222 = NULL ;
free ( V_126 ) ;
V_126 = NULL ;
V_31 = NULL ;
F_47 () ;
free ( V_223 ) ;
free ( V_154 ) ;
}
T_3 * F_51 ( const char * V_224 , const char * V_225 )
{
T_3 * V_123 = fopen ( V_224 , V_225 ) ;
if ( ! V_123 )
F_14 ( 1 , L_163 , V_224 ) ;
return V_123 ;
}
int F_52 ( const char * V_226 , ... )
{
T_4 args ;
char V_224 [ V_227 ] ;
T_3 * V_123 ;
int V_228 ;
va_start ( args , V_226 ) ;
vsnprintf ( V_224 , sizeof( V_224 ) , V_226 , args ) ;
va_end ( args ) ;
V_123 = F_51 ( V_224 , L_164 ) ;
if ( fscanf ( V_123 , L_165 , & V_228 ) != 1 )
F_14 ( 1 , L_166 , V_224 ) ;
fclose ( V_123 ) ;
return V_228 ;
}
int F_53 ( int V_1 )
{
char V_224 [ 64 ] ;
T_3 * V_123 ;
int V_229 ;
char V_230 ;
int V_195 ;
sprintf ( V_224 ,
L_167 ,
V_1 ) ;
V_123 = fopen ( V_224 , L_164 ) ;
if ( V_123 == NULL ) {
perror ( V_224 ) ;
exit ( 1 ) ;
}
for ( V_195 = 0 ; V_195 < V_14 . V_17 ; V_195 ++ ) {
fscanf ( V_123 , L_165 , & V_229 ) ;
if ( V_229 == V_1 ) {
fclose ( V_123 ) ;
return V_195 ;
}
if ( V_195 != ( V_14 . V_17 - 1 ) )
fscanf ( V_123 , L_168 , & V_230 ) ;
}
fclose ( V_123 ) ;
return - 1 ;
}
int F_54 ( int V_1 )
{
return V_1 == F_52 ( L_169 , V_1 ) ;
}
int F_55 ( int V_1 )
{
return F_52 ( L_170 , V_1 ) ;
}
int F_56 ( int V_1 )
{
return F_52 ( L_171 , V_1 ) ;
}
int F_57 ( int V_1 )
{
char V_224 [ 80 ] ;
T_3 * V_123 ;
int V_231 ;
int V_232 = 0 ;
char V_230 ;
char V_233 [ 100 ] ;
char * V_234 ;
sprintf ( V_224 , L_167 , V_1 ) ;
V_123 = F_51 ( V_224 , L_164 ) ;
fscanf ( V_123 , L_172 , & V_231 , & V_230 ) ;
fseek ( V_123 , 0 , V_235 ) ;
fgets ( V_233 , 100 , V_123 ) ;
V_234 = strchr ( V_233 , V_230 ) ;
while ( V_234 != NULL ) {
V_232 ++ ;
V_234 = strchr ( V_234 + 1 , V_230 ) ;
}
fclose ( V_123 ) ;
return V_232 + 1 ;
}
int F_58 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_236 , struct V_5 * V_237 ,
struct V_6 * V_238 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_138 ;
struct V_5 * V_19 , * V_139 ;
struct V_6 * V_20 , * V_140 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_138 = F_5 ( V_236 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_139 = F_6 ( V_237 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_140 = F_7 ( V_238 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_138 , V_139 , V_140 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_59 ( int (F_4)( int ) )
{
T_3 * V_239 ;
int V_240 ;
int V_10 ;
V_239 = F_51 ( V_241 , L_164 ) ;
V_10 = fscanf ( V_239 , L_173 ) ;
if ( V_10 != 0 )
F_14 ( 1 , L_174 , V_241 ) ;
while ( 1 ) {
V_10 = fscanf ( V_239 , L_175 , & V_240 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_240 ) ;
if ( V_10 ) {
fclose ( V_239 ) ;
return ( V_10 ) ;
}
}
fclose ( V_239 ) ;
return 0 ;
}
void F_60 ( void )
{
F_49 () ;
F_61 () ;
printf ( L_176 , V_14 . V_129 ) ;
}
int F_62 ( int V_1 )
{
if ( V_14 . V_216 < V_1 )
V_14 . V_216 = V_1 ;
V_14 . V_129 += 1 ;
return 0 ;
}
int F_63 ( int V_1 )
{
F_10 ( V_1 , V_2 , V_3 ) ;
return 0 ;
}
int F_64 ( void )
{
static T_3 * V_239 ;
int V_242 , V_10 ;
if ( V_239 == NULL )
V_239 = F_51 ( L_177 , L_164 ) ;
else
rewind ( V_239 ) ;
for ( V_242 = 0 ; V_242 < V_14 . V_129 ; ++ V_242 ) {
int V_243 ;
V_10 = fscanf ( V_239 , L_178 , & V_243 ) ;
if ( V_10 != 1 )
break;
if ( V_243 > V_14 . V_216 ) {
F_65 ( L_179 , V_243 , V_14 . V_216 ) ;
return 1 ;
}
V_223 [ V_242 ] = V_243 ;
V_154 [ V_243 ] = 0 ;
}
while ( 1 ) {
int V_242 ;
char V_244 [ 64 ] ;
V_10 = fscanf ( V_239 , L_180 , V_244 ) ;
if ( V_10 != 1 )
break;
for ( V_242 = 0 ; V_242 < V_14 . V_129 ; ++ V_242 ) {
int V_243 , V_74 ;
V_10 = fscanf ( V_239 , L_181 , & V_74 ) ;
if ( V_10 != 1 )
break;
V_243 = V_223 [ V_242 ] ;
V_154 [ V_243 ] += V_74 ;
}
while ( getc ( V_239 ) != '\n' )
;
}
return 0 ;
}
int F_66 ( void )
{
T_3 * V_239 ;
int V_10 ;
V_239 = F_51 ( L_182 , L_164 ) ;
V_10 = fscanf ( V_239 , L_183 , & V_181 ) ;
if ( V_10 != 1 )
F_14 ( 1 , L_184 ) ;
fclose ( V_239 ) ;
return 0 ;
}
int F_67 ( void )
{
static T_3 * V_239 ;
int V_10 ;
if ( V_239 == NULL )
V_239 = F_51 ( L_185 , L_164 ) ;
else
rewind ( V_239 ) ;
V_10 = fscanf ( V_239 , L_165 , & V_182 ) ;
if ( V_10 != 1 )
F_14 ( 1 , L_186 ) ;
return 0 ;
}
int F_68 ( void )
{
if ( F_64 () )
return 1 ;
if ( V_49 )
F_66 () ;
if ( V_50 )
F_67 () ;
return 0 ;
}
void F_69 ()
{
int V_10 ;
int V_245 = 0 ;
V_246:
V_245 ++ ;
F_68 () ;
V_10 = F_3 ( F_34 , V_247 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
if ( V_245 > 1 ) {
exit ( V_10 ) ;
}
F_60 () ;
goto V_246;
}
V_245 = 0 ;
F_70 ( & V_248 , (struct V_249 * ) NULL ) ;
while ( 1 ) {
if ( F_59 ( F_1 ) ) {
F_60 () ;
goto V_246;
}
F_71 ( & V_250 , NULL ) ;
if ( F_68 () )
goto V_246;
V_10 = F_3 ( F_34 , V_251 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_60 () ;
goto V_246;
}
F_70 ( & V_252 , (struct V_249 * ) NULL ) ;
F_72 ( & V_252 , & V_248 , & V_106 ) ;
F_58 ( F_28 , V_251 , V_247 ) ;
F_32 ( V_247 ) ;
F_22 ( V_247 ) ;
F_20 () ;
F_71 ( & V_250 , NULL ) ;
if ( F_68 () )
goto V_246;
V_10 = F_3 ( F_34 , V_247 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_60 () ;
goto V_246;
}
F_70 ( & V_248 , (struct V_249 * ) NULL ) ;
F_72 ( & V_248 , & V_252 , & V_106 ) ;
F_58 ( F_28 , V_247 , V_251 ) ;
F_32 ( V_251 ) ;
F_22 ( V_251 ) ;
F_20 () ;
}
}
void F_73 ()
{
struct V_253 V_254 ;
char V_24 [ 32 ] ;
sprintf ( V_24 , L_1 , V_185 ) ;
if ( V_253 ( V_24 , & V_254 ) )
if ( system ( L_187 ) )
F_14 ( - 5 , L_188 ) ;
}
void F_74 ()
{
struct V_255 V_256 ;
T_5 V_257 = & V_256 ;
struct V_258 V_259 ;
T_6 V_260 = & V_259 ;
extern int V_261 ( T_5 V_262 , T_6 V_263 ) ;
int V_264 = 0 ;
char V_24 [ 32 ] ;
V_257 -> V_265 = F_75 () ;
V_257 -> V_266 = V_267 ;
if ( V_261 ( V_257 , V_260 ) < 0 )
F_14 ( - 6 , L_189 ) ;
if ( ( V_260 -> V_268 & ( 1 << V_269 ) ) == 0 ) {
V_264 ++ ;
F_35 ( L_190
L_191 , V_136 ) ;
}
sprintf ( V_24 , L_1 , V_185 ) ;
if ( F_76 ( V_24 , V_270 ) ) {
V_264 ++ ;
F_65 ( L_192 ) ;
}
if ( V_264 )
if ( F_77 () != 0 )
F_35 ( L_193 ) ;
if ( V_264 )
exit ( - 6 ) ;
}
int F_78 ( unsigned int V_271 , unsigned int V_272 )
{
unsigned long long V_29 ;
unsigned int V_273 ;
int * V_274 ;
if ( ! V_275 )
return 0 ;
if ( V_271 != 6 )
return 0 ;
V_187 = F_79 ( V_271 , V_272 ) ;
switch ( V_272 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x25 :
case 0x2C :
case 0x2E :
case 0x2F :
V_274 = V_276 ;
break;
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
V_274 = V_277 ;
break;
case 0x3C :
case 0x3F :
case 0x45 :
case 0x46 :
case 0x3D :
case 0x47 :
case 0x4F :
case 0x56 :
case 0x4E :
case 0x5E :
case 0x8E :
case 0x9E :
case 0x55 :
V_274 = V_278 ;
break;
case 0x37 :
case 0x4D :
V_274 = V_279 ;
break;
case 0x4C :
V_274 = V_280 ;
break;
case 0x57 :
V_274 = V_281 ;
break;
case 0x5C :
V_274 = V_282 ;
break;
default:
return 0 ;
}
F_15 ( V_185 , V_198 , & V_29 ) ;
V_202 = V_274 [ V_29 & 0xF ] ;
F_15 ( V_185 , V_186 , & V_29 ) ;
V_273 = ( V_29 >> 8 ) & 0xFF ;
V_115 = V_273 * V_187 * 1000000 ;
V_114 = 1 ;
return 1 ;
}
int F_80 ( unsigned int V_271 , unsigned int V_272 )
{
switch ( V_272 ) {
case 0x2E :
case 0x2F :
case 0x57 :
return 0 ;
default:
return 1 ;
}
}
int F_81 ( unsigned int V_271 , unsigned int V_272 )
{
if ( ! V_275 )
return 0 ;
if ( V_271 != 6 )
return 0 ;
switch ( V_272 ) {
case 0x3E :
case 0x3F :
return 1 ;
default:
return 0 ;
}
}
int F_82 ( unsigned int V_271 , unsigned int V_272 )
{
if ( ! V_275 )
return 0 ;
if ( V_271 != 6 )
return 0 ;
switch ( V_272 ) {
case 0x3F :
return 1 ;
default:
return 0 ;
}
}
int F_83 ( unsigned int V_271 , unsigned int V_272 )
{
if ( ! V_275 )
return 0 ;
if ( V_271 != 6 )
return 0 ;
switch ( V_272 ) {
case 0x57 :
return 1 ;
default:
return 0 ;
}
}
int F_84 ( unsigned int V_271 , unsigned int V_272 )
{
if ( ! V_275 )
return 0 ;
if ( V_271 != 6 )
return 0 ;
switch ( V_272 ) {
case 0x3A :
case 0x3C :
case 0x3F :
case 0x45 :
case 0x46 :
case 0x3D :
case 0x47 :
case 0x4F :
case 0x56 :
case 0x4E :
case 0x5E :
case 0x8E :
case 0x9E :
case 0x55 :
case 0x57 :
return 1 ;
default:
return 0 ;
}
}
static void
F_85 ( unsigned int V_271 , unsigned int V_272 )
{
if ( ! V_283 )
return;
F_37 () ;
if ( F_82 ( V_271 , V_272 ) )
F_38 () ;
if ( F_81 ( V_271 , V_272 ) )
F_39 () ;
if ( F_80 ( V_271 , V_272 ) )
F_40 () ;
if ( F_83 ( V_271 , V_272 ) )
F_41 () ;
if ( F_84 ( V_271 , V_272 ) )
F_45 () ;
F_42 () ;
}
int F_86 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
char * V_284 ;
int V_1 ;
if ( ! V_285 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_65 & V_103 ) || ! ( V_18 -> V_65 & V_105 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_124 , L_99 , V_1 ) ;
return - 1 ;
}
if ( F_15 ( V_1 , V_286 , & V_29 ) )
return 0 ;
switch ( V_29 & 0xF ) {
case V_287 :
V_284 = L_194 ;
break;
case V_288 :
V_284 = L_195 ;
break;
case V_289 :
V_284 = L_196 ;
break;
default:
V_284 = L_197 ;
break;
}
fprintf ( V_124 , L_198 , V_1 , V_29 , V_284 ) ;
return 0 ;
}
int F_87 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
int V_1 ;
if ( ! V_290 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_65 & V_103 ) || ! ( V_18 -> V_65 & V_105 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_124 , L_99 , V_1 ) ;
return - 1 ;
}
if ( F_15 ( V_1 , V_291 , & V_29 ) )
return 0 ;
fprintf ( V_124 , L_199 ,
V_1 , V_29 , ( V_29 & ( 1 << 0 ) ) ? L_132 : L_200 ) ;
if ( ( V_29 & ( 1 << 0 ) ) == 0 )
return 0 ;
if ( F_15 ( V_1 , V_292 , & V_29 ) )
return 0 ;
fprintf ( V_124 , L_201
L_202 ,
V_1 , V_29 ,
( unsigned int ) F_88 ( V_29 ) ,
( unsigned int ) F_89 ( V_29 ) ,
( unsigned int ) F_90 ( V_29 ) ,
( unsigned int ) F_91 ( V_29 ) ) ;
if ( F_15 ( V_1 , V_293 , & V_29 ) )
return 0 ;
fprintf ( V_124 , L_203
L_204 ,
V_1 , V_29 ,
( unsigned int ) ( ( ( V_29 ) >> 0 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 8 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 16 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 24 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 32 ) & 0xff3 ) ,
( unsigned int ) ( ( ( V_29 ) >> 42 ) & 0x1 ) ) ;
if ( V_294 ) {
if ( F_15 ( V_1 , V_295 , & V_29 ) )
return 0 ;
fprintf ( V_124 , L_205
L_206 ,
V_1 , V_29 ,
( unsigned int ) ( ( ( V_29 ) >> 0 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 8 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 16 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 24 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 32 ) & 0xff3 ) ) ;
}
if ( V_296 ) {
if ( F_15 ( V_1 , V_297 , & V_29 ) )
return 0 ;
fprintf ( V_124 , L_207
L_208 ,
V_1 , V_29 ,
( ( V_29 ) & 0x1 ) ? L_105 : L_209 ,
( ( V_29 ) & 0x2 ) ? L_105 : L_209 ) ;
}
if ( F_15 ( V_1 , V_298 , & V_29 ) )
return 0 ;
fprintf ( V_124 , L_210
L_211 ,
V_1 , V_29 ,
( ( V_29 ) & 0x1 ) ? L_132 : L_200 ,
( ( V_29 ) & 0x2 ) ? L_132 : L_200 ) ;
return 0 ;
}
int F_92 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
int V_1 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_65 & V_103 ) || ! ( V_18 -> V_65 & V_105 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_124 , L_99 , V_1 ) ;
return - 1 ;
}
if ( V_299 ) {
F_15 ( V_1 , V_300 , & V_29 ) ;
fprintf ( V_124 , L_212 , V_1 , V_29 ) ;
fprintf ( V_124 , L_213 ,
( V_29 & 1 << 15 ) ? L_214 : L_132 ,
( V_29 & 1 << 14 ) ? L_215 : L_132 ,
( V_29 & 1 << 13 ) ? L_216 : L_132 ,
( V_29 & 1 << 12 ) ? L_217 : L_132 ,
( V_29 & 1 << 11 ) ? L_218 : L_132 ,
( V_29 & 1 << 10 ) ? L_219 : L_132 ,
( V_29 & 1 << 9 ) ? L_220 : L_132 ,
( V_29 & 1 << 8 ) ? L_221 : L_132 ,
( V_29 & 1 << 6 ) ? L_222 : L_132 ,
( V_29 & 1 << 5 ) ? L_223 : L_132 ,
( V_29 & 1 << 4 ) ? L_224 : L_132 ,
( V_29 & 1 << 2 ) ? L_225 : L_132 ,
( V_29 & 1 << 1 ) ? L_226 : L_132 ,
( V_29 & 1 << 0 ) ? L_227 : L_132 ) ;
fprintf ( V_124 , L_228 ,
( V_29 & 1 << 31 ) ? L_229 : L_132 ,
( V_29 & 1 << 30 ) ? L_230 : L_132 ,
( V_29 & 1 << 29 ) ? L_216 : L_132 ,
( V_29 & 1 << 28 ) ? L_217 : L_132 ,
( V_29 & 1 << 27 ) ? L_218 : L_132 ,
( V_29 & 1 << 26 ) ? L_219 : L_132 ,
( V_29 & 1 << 25 ) ? L_220 : L_132 ,
( V_29 & 1 << 24 ) ? L_221 : L_132 ,
( V_29 & 1 << 22 ) ? L_222 : L_132 ,
( V_29 & 1 << 21 ) ? L_223 : L_132 ,
( V_29 & 1 << 20 ) ? L_224 : L_132 ,
( V_29 & 1 << 18 ) ? L_231 : L_132 ,
( V_29 & 1 << 17 ) ? L_226 : L_132 ,
( V_29 & 1 << 16 ) ? L_227 : L_132 ) ;
}
if ( V_301 ) {
F_15 ( V_1 , V_302 , & V_29 ) ;
fprintf ( V_124 , L_232 , V_1 , V_29 ) ;
fprintf ( V_124 , L_233 ,
( V_29 & 1 << 0 ) ? L_227 : L_132 ,
( V_29 & 1 << 1 ) ? L_226 : L_132 ,
( V_29 & 1 << 4 ) ? L_224 : L_132 ,
( V_29 & 1 << 6 ) ? L_222 : L_132 ,
( V_29 & 1 << 8 ) ? L_221 : L_132 ,
( V_29 & 1 << 9 ) ? L_234 : L_132 ,
( V_29 & 1 << 10 ) ? L_219 : L_132 ,
( V_29 & 1 << 11 ) ? L_218 : L_132 ) ;
fprintf ( V_124 , L_235 ,
( V_29 & 1 << 16 ) ? L_227 : L_132 ,
( V_29 & 1 << 17 ) ? L_226 : L_132 ,
( V_29 & 1 << 20 ) ? L_224 : L_132 ,
( V_29 & 1 << 22 ) ? L_222 : L_132 ,
( V_29 & 1 << 24 ) ? L_221 : L_132 ,
( V_29 & 1 << 25 ) ? L_234 : L_132 ,
( V_29 & 1 << 26 ) ? L_219 : L_132 ,
( V_29 & 1 << 27 ) ? L_218 : L_132 ) ;
}
if ( V_303 ) {
F_15 ( V_1 , V_304 , & V_29 ) ;
fprintf ( V_124 , L_236 , V_1 , V_29 ) ;
fprintf ( V_124 , L_237 ,
( V_29 & 1 << 0 ) ? L_227 : L_132 ,
( V_29 & 1 << 1 ) ? L_226 : L_132 ,
( V_29 & 1 << 6 ) ? L_222 : L_132 ,
( V_29 & 1 << 8 ) ? L_221 : L_132 ,
( V_29 & 1 << 10 ) ? L_219 : L_132 ,
( V_29 & 1 << 11 ) ? L_218 : L_132 ) ;
fprintf ( V_124 , L_238 ,
( V_29 & 1 << 16 ) ? L_227 : L_132 ,
( V_29 & 1 << 17 ) ? L_226 : L_132 ,
( V_29 & 1 << 22 ) ? L_222 : L_132 ,
( V_29 & 1 << 24 ) ? L_221 : L_132 ,
( V_29 & 1 << 26 ) ? L_219 : L_132 ,
( V_29 & 1 << 27 ) ? L_218 : L_132 ) ;
}
return 0 ;
}
double F_93 ( unsigned int V_272 )
{
unsigned long long V_29 ;
if ( V_57 & V_305 )
if ( ! F_15 ( V_185 , V_306 , & V_29 ) )
return ( ( V_29 >> 0 ) & V_307 ) * V_308 ;
switch ( V_272 ) {
case 0x37 :
case 0x4D :
return 30.0 ;
default:
return 135.0 ;
}
}
static double
F_94 ( int V_272 , double V_120 )
{
switch ( V_272 ) {
case 0x3F :
case 0x4F :
case 0x56 :
case 0x57 :
return ( V_121 = 15.3 / 1000000 ) ;
default:
return ( V_120 ) ;
}
}
void F_95 ( unsigned int V_271 , unsigned int V_272 )
{
unsigned long long V_29 ;
unsigned int V_309 ;
double V_310 ;
if ( ! V_275 )
return;
if ( V_271 != 6 )
return;
switch ( V_272 ) {
case 0x2A :
case 0x3A :
case 0x3C :
case 0x45 :
case 0x46 :
case 0x3D :
case 0x47 :
V_57 = V_59 | V_60 | V_311 | V_61 | V_305 ;
break;
case 0x5C :
V_57 = V_59 | V_305 ;
break;
case 0x4E :
case 0x5E :
case 0x8E :
case 0x9E :
V_57 = V_59 | V_62 | V_64 | V_63 | V_305 ;
break;
case 0x3F :
case 0x4F :
case 0x56 :
case 0x55 :
case 0x57 :
V_57 = V_59 | V_62 | V_312 | V_64 | V_63 | V_305 ;
break;
case 0x2D :
case 0x3E :
V_57 = V_59 | V_60 | V_311 | V_62 | V_312 | V_63 | V_64 | V_305 ;
break;
case 0x37 :
case 0x4D :
V_57 = V_59 | V_60 ;
break;
default:
return;
}
if ( F_15 ( V_185 , V_313 , & V_29 ) )
return;
V_308 = 1.0 / ( 1 << ( V_29 & 0xF ) ) ;
if ( V_272 == 0x37 )
V_120 = 1.0 * ( 1 << ( V_29 >> 8 & 0x1F ) ) / 1000000 ;
else
V_120 = 1.0 / ( 1 << ( V_29 >> 8 & 0x1F ) ) ;
V_121 = F_94 ( V_272 , V_120 ) ;
V_309 = V_29 >> 16 & 0xF ;
if ( V_309 == 0 )
V_309 = 0xA ;
V_122 = 1.0 / ( 1 << ( V_309 ) ) ;
V_310 = F_93 ( V_272 ) ;
V_119 = 0xFFFFFFFF * V_120 / V_310 ;
if ( V_39 )
fprintf ( V_124 , L_239 , V_119 , V_310 ) ;
return;
}
void F_96 ( unsigned int V_271 , unsigned int V_272 )
{
if ( ! V_275 )
return;
if ( V_271 != 6 )
return;
switch ( V_272 ) {
case 0x3C :
case 0x45 :
case 0x46 :
V_301 = 1 ;
case 0x3F :
V_299 = 1 ;
V_303 = 1 ;
default:
return;
}
}
int F_97 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
unsigned int V_314 ;
int V_1 ;
if ( ! ( V_47 || V_48 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_65 & V_103 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_124 , L_99 , V_1 ) ;
return - 1 ;
}
if ( V_48 && ( V_18 -> V_65 & V_105 ) ) {
if ( F_15 ( V_1 , V_180 , & V_29 ) )
return 0 ;
V_314 = ( V_29 >> 16 ) & 0x7F ;
fprintf ( V_124 , L_240 ,
V_1 , V_29 , V_162 - V_314 ) ;
#ifdef F_98
if ( F_15 ( V_1 , V_315 , & V_29 ) )
return 0 ;
V_314 = ( V_29 >> 16 ) & 0x7F ;
V_316 = ( V_29 >> 8 ) & 0x7F ;
fprintf ( V_124 , L_241 ,
V_1 , V_29 , V_162 - V_314 , V_162 - V_316 ) ;
#endif
}
if ( V_47 ) {
unsigned int V_317 ;
if ( F_15 ( V_1 , V_161 , & V_29 ) )
return 0 ;
V_314 = ( V_29 >> 16 ) & 0x7F ;
V_317 = ( V_29 >> 27 ) & 0xF ;
fprintf ( V_124 , L_242 ,
V_1 , V_29 , V_162 - V_314 , V_317 ) ;
#ifdef F_98
if ( F_15 ( V_1 , V_318 , & V_29 ) )
return 0 ;
V_314 = ( V_29 >> 16 ) & 0x7F ;
V_316 = ( V_29 >> 8 ) & 0x7F ;
fprintf ( V_124 , L_243 ,
V_1 , V_29 , V_162 - V_314 , V_162 - V_316 ) ;
#endif
}
return 0 ;
}
void F_99 ( int V_1 , unsigned long long V_29 , char * V_319 )
{
fprintf ( V_124 , L_244 ,
V_1 , V_319 ,
( ( V_29 >> 15 ) & 1 ) ? L_105 : L_106 ,
( ( V_29 >> 0 ) & 0x7FFF ) * V_308 ,
( 1.0 + ( ( ( V_29 >> 22 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_29 >> 17 ) & 0x1F ) ) * V_122 ,
( ( ( V_29 >> 16 ) & 1 ) ? L_105 : L_106 ) ) ;
return;
}
int F_100 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
int V_1 ;
if ( ! V_57 )
return 0 ;
if ( ! ( V_18 -> V_65 & V_103 ) || ! ( V_18 -> V_65 & V_105 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_124 , L_99 , V_1 ) ;
return - 1 ;
}
if ( F_15 ( V_1 , V_313 , & V_29 ) )
return - 1 ;
if ( V_39 ) {
fprintf ( V_124 , L_245
L_246 , V_1 , V_29 ,
V_308 , V_120 , V_122 ) ;
}
if ( V_57 & V_305 ) {
if ( F_15 ( V_1 , V_306 , & V_29 ) )
return - 5 ;
fprintf ( V_124 , L_247 ,
V_1 , V_29 ,
( ( V_29 >> 0 ) & V_307 ) * V_308 ,
( ( V_29 >> 16 ) & V_307 ) * V_308 ,
( ( V_29 >> 32 ) & V_307 ) * V_308 ,
( ( V_29 >> 48 ) & V_320 ) * V_122 ) ;
}
if ( V_57 & V_59 ) {
if ( F_15 ( V_1 , V_321 , & V_29 ) )
return - 9 ;
fprintf ( V_124 , L_248 ,
V_1 , V_29 , ( V_29 >> 63 ) & 1 ? L_132 : L_136 ) ;
F_99 ( V_1 , V_29 , L_249 ) ;
fprintf ( V_124 , L_250 ,
V_1 ,
( ( V_29 >> 47 ) & 1 ) ? L_105 : L_106 ,
( ( V_29 >> 32 ) & 0x7FFF ) * V_308 ,
( 1.0 + ( ( ( V_29 >> 54 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_29 >> 49 ) & 0x1F ) ) * V_122 ,
( ( V_29 >> 48 ) & 1 ) ? L_105 : L_106 ) ;
}
if ( V_57 & V_312 ) {
if ( F_15 ( V_1 , V_322 , & V_29 ) )
return - 6 ;
fprintf ( V_124 , L_251 ,
V_1 , V_29 ,
( ( V_29 >> 0 ) & V_307 ) * V_308 ,
( ( V_29 >> 16 ) & V_307 ) * V_308 ,
( ( V_29 >> 32 ) & V_307 ) * V_308 ,
( ( V_29 >> 48 ) & V_320 ) * V_122 ) ;
}
if ( V_57 & V_62 ) {
if ( F_15 ( V_1 , V_323 , & V_29 ) )
return - 9 ;
fprintf ( V_124 , L_252 ,
V_1 , V_29 , ( V_29 >> 31 ) & 1 ? L_132 : L_136 ) ;
F_99 ( V_1 , V_29 , L_253 ) ;
}
if ( V_57 & V_311 ) {
if ( V_39 ) {
if ( F_15 ( V_1 , V_324 , & V_29 ) )
return - 7 ;
fprintf ( V_124 , L_254 , V_1 , V_29 & 0xF ) ;
}
}
if ( V_57 & V_60 ) {
if ( V_39 ) {
if ( F_15 ( V_1 , V_325 , & V_29 ) )
return - 9 ;
fprintf ( V_124 , L_255 ,
V_1 , V_29 , ( V_29 >> 31 ) & 1 ? L_132 : L_136 ) ;
F_99 ( V_1 , V_29 , L_256 ) ;
}
}
if ( V_57 & V_61 ) {
if ( V_39 ) {
if ( F_15 ( V_1 , V_326 , & V_29 ) )
return - 8 ;
fprintf ( V_124 , L_257 , V_1 , V_29 & 0xF ) ;
if ( F_15 ( V_1 , V_327 , & V_29 ) )
return - 9 ;
fprintf ( V_124 , L_258 ,
V_1 , V_29 , ( V_29 >> 31 ) & 1 ? L_132 : L_136 ) ;
F_99 ( V_1 , V_29 , L_259 ) ;
}
}
return 0 ;
}
int F_101 ( unsigned int V_271 , unsigned int V_272 )
{
if ( ! V_275 )
return 0 ;
switch ( V_272 ) {
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
case 0x3C :
case 0x3F :
case 0x45 :
case 0x46 :
case 0x3D :
case 0x47 :
case 0x4F :
case 0x56 :
case 0x4E :
case 0x5E :
case 0x8E :
case 0x9E :
case 0x55 :
case 0x5C :
return 1 ;
}
return 0 ;
}
int F_102 ( unsigned int V_271 , unsigned int V_272 )
{
if ( ! V_275 )
return 0 ;
switch ( V_272 ) {
case 0x45 :
case 0x3D :
case 0x4E :
case 0x5E :
case 0x8E :
case 0x9E :
case 0x5C :
return 1 ;
}
return 0 ;
}
int F_103 ( unsigned int V_271 , unsigned int V_272 )
{
if ( ! V_275 )
return 0 ;
switch ( V_272 ) {
case 0x4E :
case 0x5E :
case 0x8E :
case 0x9E :
return 1 ;
}
return 0 ;
}
int F_104 ( unsigned int V_271 , unsigned int V_272 )
{
if ( ! V_275 )
return 0 ;
switch ( V_272 ) {
case 0x37 :
case 0x4D :
return 1 ;
}
return 0 ;
}
int F_105 ( unsigned int V_271 , unsigned int V_272 )
{
if ( ! V_275 )
return 0 ;
switch ( V_272 ) {
case 0x57 :
return 1 ;
}
return 0 ;
}
unsigned int F_106 ( unsigned int V_271 , unsigned int V_272 )
{
if ( F_105 ( V_271 , V_272 ) )
return 1024 ;
return 1 ;
}
double F_107 ( void )
{
unsigned long long V_29 = 3 ;
unsigned int V_195 ;
double V_328 ;
if ( F_15 ( V_185 , V_329 , & V_29 ) )
fprintf ( V_124 , L_260 ) ;
V_195 = V_29 & 0xf ;
if ( V_195 >= V_330 ) {
fprintf ( V_124 , L_261 , V_195 ) ;
V_29 = 3 ;
}
V_328 = V_331 [ V_195 ] ;
fprintf ( V_124 , L_262 , V_328 ) ;
return V_328 ;
}
double F_79 ( unsigned int V_271 , unsigned int V_272 )
{
if ( F_101 ( V_271 , V_272 ) || F_105 ( V_271 , V_272 ) )
return 100.00 ;
else if ( F_104 ( V_271 , V_272 ) )
return F_107 () ;
else
return 133.33 ;
}
int F_108 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
unsigned int V_332 ;
int V_1 ;
if ( ! ( V_47 || V_48 ) )
return 0 ;
if ( ! ( V_18 -> V_65 & V_103 ) || ! ( V_18 -> V_65 & V_105 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_124 , L_99 , V_1 ) ;
return - 1 ;
}
if ( V_333 != 0 ) {
V_162 = V_333 ;
fprintf ( V_124 , L_263 ,
V_1 , V_162 ) ;
return 0 ;
}
if ( ! V_283 )
goto V_334;
if ( F_15 ( V_185 , V_335 , & V_29 ) )
goto V_334;
V_332 = ( V_29 >> 16 ) & 0xFF ;
if ( V_39 )
fprintf ( V_124 , L_264 ,
V_1 , V_29 , V_332 ) ;
if ( ! V_332 )
goto V_334;
V_162 = V_332 ;
return 0 ;
V_334:
V_162 = V_336 ;
fprintf ( V_124 , L_265 ,
V_1 , V_162 ) ;
return 0 ;
}
void F_109 ( void )
{
unsigned long long V_29 ;
if ( ! F_15 ( V_185 , V_337 , & V_29 ) )
fprintf ( V_124 , L_266 ,
V_185 , V_29 ,
V_29 & V_338 ? L_132 : L_267 ,
V_29 & ( 1 << 18 ) ? L_268 : L_132 ) ;
}
void F_110 ( void )
{
unsigned long long V_29 ;
if ( ! F_15 ( V_185 , V_339 , & V_29 ) )
fprintf ( V_124 , L_269 ,
V_185 , V_29 ,
V_29 & ( 1 << 3 ) ? L_270 : L_132 ,
V_29 & ( 1 << 16 ) ? L_271 : L_132 ,
V_29 & ( 1 << 18 ) ? L_272 : L_132 ) ;
}
void F_111 ( void )
{
unsigned long long V_29 ;
if ( ! V_283 )
return;
if ( ! F_15 ( V_185 , V_340 , & V_29 ) )
fprintf ( V_124 , L_273 ,
V_185 , V_29 ,
V_29 & ( 1 << 0 ) ? L_106 : L_105 ,
V_29 & ( 1 << 1 ) ? L_105 : L_106 ) ;
}
void F_112 ()
{
unsigned int V_341 , V_342 , V_343 , V_344 , V_345 , V_346 ;
unsigned int V_347 , V_271 , V_272 , V_348 ;
V_341 = V_342 = V_343 = V_344 = 0 ;
F_113 ( 0 , V_345 , V_342 , V_343 , V_344 ) ;
if ( V_342 == 0x756e6547 && V_344 == 0x49656e69 && V_343 == 0x6c65746e )
V_275 = 1 ;
if ( V_39 )
fprintf ( V_124 , L_274 ,
( char * ) & V_342 , ( char * ) & V_344 , ( char * ) & V_343 ) ;
F_113 ( 1 , V_347 , V_342 , V_343 , V_344 ) ;
V_271 = ( V_347 >> 8 ) & 0xf ;
V_272 = ( V_347 >> 4 ) & 0xf ;
V_348 = V_347 & 0xf ;
if ( V_271 == 6 || V_271 == 0xf )
V_272 += ( ( V_347 >> 16 ) & 0xf ) << 4 ;
if ( V_39 ) {
fprintf ( V_124 , L_275 ,
V_345 , V_271 , V_272 , V_348 , V_271 , V_272 , V_348 ) ;
fprintf ( V_124 , L_276 ,
V_343 & ( 1 << 0 ) ? L_277 : L_278 ,
V_343 & ( 1 << 3 ) ? L_272 : L_278 ,
V_343 & ( 1 << 6 ) ? L_279 : L_278 ,
V_343 & ( 1 << 7 ) ? L_271 : L_278 ,
V_343 & ( 1 << 8 ) ? L_280 : L_278 ,
V_344 & ( 1 << 4 ) ? L_281 : L_278 ,
V_344 & ( 1 << 5 ) ? L_282 : L_278 ,
V_344 & ( 1 << 22 ) ? L_283 : L_278 ,
V_344 & ( 1 << 29 ) ? L_284 : L_278 ) ;
}
if ( ! ( V_344 & ( 1 << 5 ) ) )
F_27 ( 1 , L_285 ) ;
V_342 = V_343 = V_344 = 0 ;
F_113 ( 0x80000000 , V_346 , V_342 , V_343 , V_344 ) ;
if ( V_346 >= 0x80000007 ) {
F_113 ( 0x80000007 , V_341 , V_342 , V_343 , V_344 ) ;
V_349 = V_344 & ( 1 << 8 ) ;
}
F_113 ( 0x6 , V_341 , V_342 , V_343 , V_344 ) ;
V_34 = V_343 & ( 1 << 0 ) ;
V_47 = V_341 & ( 1 << 0 ) ;
V_48 = V_341 & ( 1 << 6 ) ;
V_290 = V_341 & ( 1 << 7 ) ;
V_296 = V_341 & ( 1 << 8 ) ;
V_350 = V_341 & ( 1 << 9 ) ;
V_351 = V_341 & ( 1 << 10 ) ;
V_294 = V_341 & ( 1 << 11 ) ;
V_285 = V_343 & ( 1 << 3 ) ;
if ( V_39 )
fprintf ( V_124 , L_286
L_287 ,
V_34 ? L_132 : L_200 ,
V_47 ? L_132 : L_200 ,
V_48 ? L_132 : L_200 ,
V_290 ? L_132 : L_200 ,
V_296 ? L_132 : L_200 ,
V_350 ? L_132 : L_200 ,
V_351 ? L_132 : L_200 ,
V_294 ? L_132 : L_200 ,
V_285 ? L_132 : L_200 ) ;
if ( V_39 )
F_110 () ;
if ( V_345 >= 0x7 && V_39 ) {
int V_352 ;
V_343 = 0 ;
F_114 ( 0x7 , 0 , V_341 , V_342 , V_343 , V_344 ) ;
V_352 = V_342 & ( 1 << 2 ) ;
fprintf ( V_124 , L_288 , V_352 ? L_132 : L_200 ) ;
if ( V_352 )
F_109 () ;
}
if ( V_345 >= 0x15 ) {
unsigned int V_353 ;
unsigned int V_354 ;
V_353 = V_354 = V_355 = V_344 = 0 ;
F_113 ( 0x15 , V_353 , V_354 , V_355 , V_344 ) ;
if ( V_354 != 0 ) {
if ( V_39 && ( V_342 != 0 ) )
fprintf ( V_124 , L_289 ,
V_353 , V_354 , V_355 ) ;
if ( V_355 == 0 )
switch( V_272 ) {
case 0x4E :
case 0x5E :
case 0x8E :
case 0x9E :
V_355 = 24000000 ;
break;
case 0x55 :
V_355 = 25000000 ;
break;
case 0x5C :
V_355 = 19200000 ;
break;
default:
V_355 = 0 ;
}
if ( V_355 ) {
V_183 = ( unsigned long long ) V_355 * V_354 / V_353 ;
if ( V_39 )
fprintf ( V_124 , L_290 ,
V_183 / 1000000 , V_355 , V_354 , V_353 ) ;
}
}
}
if ( V_345 >= 0x16 ) {
unsigned int V_356 , V_357 , V_358 , V_344 ;
V_356 = V_357 = V_358 = V_344 = 0 ;
F_113 ( 0x16 , V_356 , V_357 , V_358 , V_344 ) ;
if ( V_39 )
fprintf ( V_124 , L_291 ,
V_356 , V_357 , V_358 ) ;
}
if ( V_34 )
V_153 = F_106 ( V_271 , V_272 ) ;
V_283 = V_43 = V_42 = F_78 ( V_271 , V_272 ) ;
V_46 = F_101 ( V_271 , V_272 ) ;
V_359 = F_101 ( V_271 , V_272 ) ;
V_52 = V_46 && ( V_202 >= V_360 ) ;
V_53 = ( V_202 >= V_361 ) ;
V_54 = ( V_202 >= V_362 ) ;
V_55 = V_46 && ( V_202 >= V_363 ) ;
V_56 = F_102 ( V_271 , V_272 ) ;
V_212 = F_102 ( V_271 , V_272 ) ;
V_51 = F_103 ( V_271 , V_272 ) ;
V_44 = F_104 ( V_271 , V_272 ) ;
V_45 = F_105 ( V_271 , V_272 ) ;
if ( V_39 )
F_111 () ;
F_95 ( V_271 , V_272 ) ;
F_96 ( V_271 , V_272 ) ;
if ( V_39 )
F_85 ( V_271 , V_272 ) ;
if ( F_103 ( V_271 , V_272 ) )
F_36 () ;
V_49 = ! F_115 ( L_182 , V_270 ) ;
V_50 = ! F_115 ( L_185 , V_270 ) ;
return;
}
void F_116 ()
{
fprintf ( V_124 ,
L_292
L_47
L_293
L_294
L_295
L_296
L_297
L_298
L_299
L_300
L_301
L_302
L_303
L_304
L_305
L_47
L_306 ) ;
}
int F_117 ( const struct V_364 * V_365 )
{
if ( isdigit ( V_365 -> V_366 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_118 ( int V_367 )
{
return 0 ;
}
void F_119 ()
{
int V_195 ;
int V_368 = 0 ;
int V_369 = 0 ;
int V_370 = 0 ;
struct V_371 {
int V_76 ;
int V_372 ;
} * V_373 ;
V_14 . V_129 = 0 ;
V_14 . V_216 = 0 ;
F_59 ( F_62 ) ;
if ( ! V_128 && V_14 . V_129 > 1 )
V_33 = 1 ;
if ( V_39 > 1 )
fprintf ( V_124 , L_307 , V_14 . V_129 , V_14 . V_216 ) ;
V_373 = calloc ( 1 , ( V_14 . V_216 + 1 ) * sizeof( struct V_371 ) ) ;
if ( V_373 == NULL )
F_14 ( 1 , L_308 ) ;
V_3 = F_120 ( ( V_14 . V_216 + 1 ) ) ;
if ( V_3 == NULL )
F_14 ( 3 , L_309 ) ;
V_2 = F_121 ( ( V_14 . V_216 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_59 ( F_63 ) ;
V_23 = F_120 ( ( V_14 . V_216 + 1 ) ) ;
if ( V_23 == NULL )
F_14 ( 3 , L_309 ) ;
V_22 = F_121 ( ( V_14 . V_216 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_195 = 0 ; V_195 <= V_14 . V_216 ; ++ V_195 ) {
int V_374 ;
if ( F_1 ( V_195 ) ) {
if ( V_39 > 1 )
fprintf ( V_124 , L_310 , V_195 ) ;
continue;
}
V_373 [ V_195 ] . V_76 = F_56 ( V_195 ) ;
if ( V_373 [ V_195 ] . V_76 > V_368 )
V_368 = V_373 [ V_195 ] . V_76 ;
V_373 [ V_195 ] . V_372 = F_55 ( V_195 ) ;
if ( V_373 [ V_195 ] . V_372 > V_369 )
V_369 = V_373 [ V_195 ] . V_372 ;
V_374 = F_57 ( V_195 ) ;
if ( V_374 > V_370 )
V_370 = V_374 ;
if ( V_39 > 1 )
fprintf ( V_124 , L_311 ,
V_195 , V_373 [ V_195 ] . V_372 , V_373 [ V_195 ] . V_76 ) ;
}
V_14 . V_16 = V_368 + 1 ;
if ( V_39 > 1 )
fprintf ( V_124 , L_312 ,
V_368 , V_14 . V_16 ) ;
if ( V_39 && ! V_128 && V_14 . V_16 > 1 )
V_32 = 1 ;
V_14 . V_15 = V_369 + 1 ;
if ( V_39 > 1 )
fprintf ( V_124 , L_313 ,
V_369 , V_14 . V_15 ) ;
if ( V_39 && ! V_128 && V_14 . V_15 > 1 )
V_30 = 1 ;
V_14 . V_17 = V_370 ;
if ( V_39 > 1 )
fprintf ( V_124 , L_314 , V_370 ) ;
free ( V_373 ) ;
}
void
F_122 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_195 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_195 = 0 ; V_195 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_195 ++ )
( * V_18 ) [ V_195 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_195 = 0 ; V_195 < V_14 . V_16 * V_14 . V_15 ; V_195 ++ )
( * V_19 ) [ V_195 ] . V_76 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_195 = 0 ; V_195 < V_14 . V_15 ; V_195 ++ )
( * V_20 ) [ V_195 ] . V_81 = V_195 ;
return;
error:
F_14 ( 1 , L_315 ) ;
}
void F_123 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_375 , int V_376 ,
int V_377 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_375 , V_376 , V_377 ) ;
V_19 = F_6 ( V_8 , V_376 , V_377 ) ;
V_20 = F_7 ( V_9 , V_377 ) ;
V_18 -> V_21 = V_21 ;
if ( V_375 == 0 ) {
V_18 -> V_65 |= V_103 ;
if ( F_54 ( V_21 ) )
V_18 -> V_65 |= V_105 ;
}
V_19 -> V_76 = V_376 ;
V_20 -> V_81 = V_377 ;
}
int F_124 ( int V_21 )
{
int V_378 , V_379 , V_380 ;
V_380 = F_55 ( V_21 ) ;
V_379 = F_56 ( V_21 ) ;
V_378 = F_53 ( V_21 ) ;
if ( ! V_378 )
V_14 . V_141 ++ ;
F_123 ( V_247 , V_378 , V_379 , V_380 , V_21 ) ;
F_123 ( V_251 , V_378 , V_379 , V_380 , V_21 ) ;
return 0 ;
}
void F_125 ()
{
V_126 = calloc ( 1 , ( 1 + V_14 . V_129 ) * 1024 ) ;
V_31 = V_126 ;
if ( V_31 == NULL )
F_14 ( - 1 , L_316 ) ;
}
void F_126 ( void )
{
V_26 = calloc ( V_14 . V_216 , sizeof( int ) ) ;
if ( V_26 == NULL )
F_14 ( - 1 , L_317 ) ;
}
void F_127 ( void )
{
V_223 = calloc ( V_14 . V_129 , sizeof( int ) ) ;
if ( V_223 == NULL )
F_14 ( - 1 , L_318 , V_14 . V_129 ) ;
V_154 = calloc ( V_14 . V_216 , sizeof( int ) ) ;
if ( V_154 == NULL )
F_14 ( - 1 , L_318 , V_14 . V_216 ) ;
}
void F_61 ( void )
{
F_119 () ;
F_127 () ;
F_126 () ;
F_122 ( & V_217 , & V_218 , & V_219 ) ;
F_122 ( & V_220 , & V_221 , & V_222 ) ;
F_125 () ;
F_59 ( F_124 ) ;
}
void F_128 ( void )
{
V_185 = F_129 () ;
if ( V_185 < 0 )
F_14 ( - V_381 , L_319 ) ;
if ( V_39 > 1 )
fprintf ( V_124 , L_320 , V_185 ) ;
}
void F_130 ()
{
F_61 () ;
F_128 () ;
F_73 () ;
F_74 () ;
F_112 () ;
if ( V_39 )
F_3 ( F_87 , V_251 ) ;
if ( V_39 )
F_3 ( F_86 , V_251 ) ;
if ( V_39 )
F_3 ( F_92 , V_251 ) ;
if ( V_39 )
F_3 ( F_100 , V_251 ) ;
F_3 ( F_108 , V_251 ) ;
if ( V_39 )
F_3 ( F_97 , V_251 ) ;
if ( V_39 && V_359 )
F_46 () ;
}
int F_131 ( char * * V_382 )
{
T_7 V_383 ;
int V_384 ;
V_384 = F_3 ( F_34 , V_247 ) ;
if ( V_384 )
exit ( V_384 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_70 ( & V_248 , (struct V_249 * ) NULL ) ;
V_383 = F_132 () ;
if ( ! V_383 ) {
F_133 ( V_382 [ 0 ] , V_382 ) ;
} else {
if ( V_383 == - 1 )
F_14 ( 1 , L_321 ) ;
signal ( V_385 , V_386 ) ;
signal ( V_387 , V_386 ) ;
if ( F_134 ( V_383 , & V_384 , 0 ) == - 1 )
F_14 ( V_384 , L_322 ) ;
}
F_3 ( F_34 , V_251 ) ;
F_70 ( & V_252 , (struct V_249 * ) NULL ) ;
F_72 ( & V_252 , & V_248 , & V_106 ) ;
F_58 ( F_28 , V_251 , V_247 ) ;
F_32 ( V_247 ) ;
F_22 ( V_247 ) ;
fprintf ( V_124 , L_323 , V_106 . V_107 + V_106 . V_108 / 1000000.0 ) ;
F_21 () ;
return V_384 ;
}
int F_135 ( void )
{
int V_384 ;
V_384 = F_3 ( F_34 , V_251 ) ;
if ( V_384 )
return V_384 ;
V_384 = F_3 ( F_18 , V_251 ) ;
if ( V_384 )
return V_384 ;
F_20 () ;
return V_384 ;
}
void F_136 () {
fprintf ( V_124 , L_324
L_325 ) ;
}
void F_137 ( int V_388 , char * * V_382 )
{
int V_389 ;
int V_390 = 0 ;
static struct V_391 V_392 [] = {
{ L_326 , V_393 , 0 , 'C' } ,
{ L_327 , V_393 , 0 , 'c' } ,
{ L_328 , V_394 , 0 , 'D' } ,
{ L_329 , V_394 , 0 , 'd' } ,
{ L_330 , V_393 , 0 , 'i' } ,
{ L_331 , V_394 , 0 , 'h' } ,
{ L_332 , V_394 , 0 , 'J' } ,
{ L_282 , V_393 , 0 , 'M' } ,
{ L_333 , V_393 , 0 , 'm' } ,
{ L_334 , V_393 , 0 , 'o' } ,
{ L_335 , V_394 , 0 , 'p' } ,
{ L_336 , V_394 , 0 , 'p' } ,
{ L_337 , V_394 , 0 , 'S' } ,
{ L_270 , V_393 , 0 , 'T' } ,
{ L_338 , V_394 , 0 , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
V_136 = V_382 [ 0 ] ;
while ( ( V_389 = F_138 ( V_388 , V_382 , L_339 ,
V_392 , & V_390 ) ) != - 1 ) {
switch ( V_389 ) {
case 'C' :
sscanf ( V_395 , L_340 , & V_36 ) ;
break;
case 'c' :
sscanf ( V_395 , L_340 , & V_35 ) ;
break;
case 'D' :
V_396 ++ ;
break;
case 'd' :
V_39 ++ ;
break;
case 'h' :
default:
F_116 () ;
exit ( 1 ) ;
case 'i' :
{
double V_397 = strtod ( V_395 , NULL ) ;
if ( V_397 < 0.001 ) {
fprintf ( V_124 , L_341 ,
V_397 ) ;
exit ( 2 ) ;
}
V_250 . V_107 = V_397 ;
V_250 . V_398 = ( V_397 - V_250 . V_107 ) * 1000000000 ;
}
break;
case 'J' :
V_58 ++ ;
break;
case 'M' :
sscanf ( V_395 , L_340 , & V_38 ) ;
break;
case 'm' :
sscanf ( V_395 , L_340 , & V_37 ) ;
break;
case 'o' :
V_124 = F_51 ( V_395 , L_342 ) ;
break;
case 'P' :
V_104 ++ ;
break;
case 'p' :
V_102 ++ ;
break;
case 'S' :
V_128 ++ ;
break;
case 'T' :
V_333 = atoi ( V_395 ) ;
break;
case 'v' :
F_136 () ;
exit ( 0 ) ;
break;
}
}
}
int main ( int V_388 , char * * V_382 )
{
V_124 = V_125 ;
F_137 ( V_388 , V_382 ) ;
if ( V_39 )
F_136 () ;
F_130 () ;
if ( V_396 )
return F_135 () ;
if ( V_388 - V_399 )
return F_131 ( V_382 + V_399 ) ;
else
F_69 () ;
return 0 ;
}
