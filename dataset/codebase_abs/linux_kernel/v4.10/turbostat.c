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
struct V_30 * V_31 ;
if ( V_32 )
V_33 += sprintf ( V_33 , L_4 ) ;
if ( V_34 )
V_33 += sprintf ( V_33 , L_5 ) ;
if ( V_35 )
V_33 += sprintf ( V_33 , L_6 ) ;
if ( V_36 )
V_33 += sprintf ( V_33 , L_7 ) ;
if ( V_36 )
V_33 += sprintf ( V_33 , L_8 ) ;
if ( V_36 )
V_33 += sprintf ( V_33 , L_9 ) ;
V_33 += sprintf ( V_33 , L_10 ) ;
if ( ! V_37 )
goto V_38;
if ( V_39 )
V_33 += sprintf ( V_33 , L_11 ) ;
if ( V_40 )
V_33 += sprintf ( V_33 , L_12 ) ;
if ( V_41 )
V_33 += sprintf ( V_33 , L_13 ) ;
if ( V_41 && ! V_42 && ! V_43 )
V_33 += sprintf ( V_33 , L_14 ) ;
if ( V_41 )
V_33 += sprintf ( V_33 , L_15 ) ;
if ( V_44 )
V_33 += sprintf ( V_33 , L_16 ) ;
for ( V_31 = V_45 . V_46 ; V_31 ; V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 ) {
if ( V_31 -> V_50 == 64 )
V_33 += sprintf ( V_33 , L_17 , V_31 -> V_51 ) ;
else
V_33 += sprintf ( V_33 , L_18 , V_31 -> V_51 ) ;
} else {
V_33 += sprintf ( V_33 , L_19 , V_31 -> V_51 ) ;
}
}
if ( V_52 )
V_33 += sprintf ( V_33 , L_20 ) ;
for ( V_31 = V_45 . V_53 ; V_31 ; V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 ) {
if ( V_31 -> V_50 == 64 )
V_33 += sprintf ( V_33 , L_17 , V_31 -> V_51 ) ;
else
V_33 += sprintf ( V_33 , L_18 , V_31 -> V_51 ) ;
} else {
V_33 += sprintf ( V_33 , L_19 , V_31 -> V_51 ) ;
}
}
if ( V_54 )
V_33 += sprintf ( V_33 , L_21 ) ;
if ( V_55 )
V_33 += sprintf ( V_33 , L_22 ) ;
if ( V_56 )
V_33 += sprintf ( V_33 , L_23 ) ;
if ( V_57 ) {
V_33 += sprintf ( V_33 , L_24 ) ;
V_33 += sprintf ( V_33 , L_25 ) ;
V_33 += sprintf ( V_33 , L_26 ) ;
V_33 += sprintf ( V_33 , L_27 ) ;
}
if ( V_58 )
V_33 += sprintf ( V_33 , L_28 ) ;
if ( V_59 )
V_33 += sprintf ( V_33 , L_29 ) ;
if ( V_60 )
V_33 += sprintf ( V_33 , L_30 ) ;
if ( V_61 )
V_33 += sprintf ( V_33 , L_31 ) ;
if ( V_62 ) {
V_33 += sprintf ( V_33 , L_32 ) ;
V_33 += sprintf ( V_33 , L_33 ) ;
V_33 += sprintf ( V_33 , L_34 ) ;
}
if ( V_63 && ! V_64 ) {
if ( V_63 & V_65 )
V_33 += sprintf ( V_33 , L_35 ) ;
if ( V_63 & V_66 )
V_33 += sprintf ( V_33 , L_36 ) ;
if ( V_63 & V_67 )
V_33 += sprintf ( V_33 , L_37 ) ;
if ( V_63 & V_68 )
V_33 += sprintf ( V_33 , L_38 ) ;
if ( V_63 & V_69 )
V_33 += sprintf ( V_33 , L_39 ) ;
if ( V_63 & V_70 )
V_33 += sprintf ( V_33 , L_40 ) ;
} else if ( V_63 && V_64 ) {
if ( V_63 & V_65 )
V_33 += sprintf ( V_33 , L_41 ) ;
if ( V_63 & V_66 )
V_33 += sprintf ( V_33 , L_42 ) ;
if ( V_63 & V_67 )
V_33 += sprintf ( V_33 , L_43 ) ;
if ( V_63 & V_68 )
V_33 += sprintf ( V_33 , L_44 ) ;
if ( V_63 & V_69 )
V_33 += sprintf ( V_33 , L_39 ) ;
if ( V_63 & V_70 )
V_33 += sprintf ( V_33 , L_40 ) ;
}
for ( V_31 = V_45 . V_71 ; V_31 ; V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 ) {
if ( V_31 -> V_50 == 64 )
V_33 += sprintf ( V_33 , L_17 , V_31 -> V_51 ) ;
else
V_33 += sprintf ( V_33 , L_18 , V_31 -> V_51 ) ;
} else {
V_33 += sprintf ( V_33 , L_19 , V_31 -> V_51 ) ;
}
}
V_38:
V_33 += sprintf ( V_33 , L_45 ) ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
int V_72 ;
struct V_30 * V_31 ;
V_33 += sprintf ( V_33 , L_46 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
V_33 += sprintf ( V_33 , L_47 ,
V_18 -> V_21 , V_18 -> V_73 ) ;
V_33 += sprintf ( V_33 , L_48 , V_18 -> V_74 ) ;
V_33 += sprintf ( V_33 , L_49 , V_18 -> V_75 ) ;
V_33 += sprintf ( V_33 , L_50 , V_18 -> V_76 ) ;
V_33 += sprintf ( V_33 , L_51 , V_18 -> V_77 ) ;
if ( V_39 )
V_33 += sprintf ( V_33 , L_52 , V_18 -> V_78 ) ;
if ( V_40 )
V_33 += sprintf ( V_33 , L_53 , V_18 -> V_79 ) ;
for ( V_72 = 0 , V_31 = V_45 . V_46 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
V_33 += sprintf ( V_33 , L_54 ,
V_72 , V_31 -> V_80 , V_18 -> V_81 [ V_72 ] ) ;
}
}
if ( V_19 ) {
V_33 += sprintf ( V_33 , L_55 , V_19 -> V_82 ) ;
V_33 += sprintf ( V_33 , L_56 , V_19 -> V_83 ) ;
V_33 += sprintf ( V_33 , L_57 , V_19 -> V_84 ) ;
V_33 += sprintf ( V_33 , L_58 , V_19 -> V_85 ) ;
V_33 += sprintf ( V_33 , L_59 , V_19 -> V_86 ) ;
for ( V_72 = 0 , V_31 = V_45 . V_53 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
V_33 += sprintf ( V_33 , L_60 ,
V_72 , V_31 -> V_80 , V_19 -> V_81 [ V_72 ] ) ;
}
}
if ( V_20 ) {
V_33 += sprintf ( V_33 , L_61 , V_20 -> V_87 ) ;
V_33 += sprintf ( V_33 , L_62 , V_20 -> V_88 ) ;
V_33 += sprintf ( V_33 , L_63 , V_20 -> V_89 ) ;
V_33 += sprintf ( V_33 , L_64 , V_20 -> V_90 ) ;
V_33 += sprintf ( V_33 , L_65 , V_20 -> V_91 ) ;
V_33 += sprintf ( V_33 , L_66 , V_20 -> V_92 ) ;
if ( V_59 )
V_33 += sprintf ( V_33 , L_67 , V_20 -> V_93 ) ;
if ( V_60 )
V_33 += sprintf ( V_33 , L_68 , V_20 -> V_94 ) ;
if ( V_61 )
V_33 += sprintf ( V_33 , L_69 , V_20 -> V_95 ) ;
V_33 += sprintf ( V_33 , L_70 , V_20 -> V_96 ) ;
V_33 += sprintf ( V_33 , L_71 , V_20 -> V_97 ) ;
V_33 += sprintf ( V_33 , L_72 , V_20 -> V_98 ) ;
V_33 += sprintf ( V_33 , L_73 , V_20 -> V_99 ) ;
V_33 += sprintf ( V_33 , L_74 , V_20 -> V_100 ) ;
V_33 += sprintf ( V_33 , L_75 , V_20 -> V_101 ) ;
V_33 += sprintf ( V_33 , L_76 , V_20 -> V_102 ) ;
V_33 += sprintf ( V_33 , L_77 ,
V_20 -> V_103 ) ;
V_33 += sprintf ( V_33 , L_78 ,
V_20 -> V_104 ) ;
V_33 += sprintf ( V_33 , L_79 , V_20 -> V_105 ) ;
for ( V_72 = 0 , V_31 = V_45 . V_71 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
V_33 += sprintf ( V_33 , L_80 ,
V_72 , V_31 -> V_80 , V_20 -> V_81 [ V_72 ] ) ;
}
}
V_33 += sprintf ( V_33 , L_45 ) ;
return 0 ;
}
int F_19 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_106 ;
char * V_107 ;
int V_72 ;
struct V_30 * V_31 ;
if ( V_108 && ! ( V_18 -> V_73 & V_109 ) )
return 0 ;
if ( V_110 && ! ( V_18 -> V_73 & V_111 ) )
return 0 ;
V_106 = V_112 . V_113 + V_112 . V_114 / 1000000.0 ;
if ( V_18 == & V_115 . V_116 ) {
if ( V_32 )
V_33 += sprintf ( V_33 , L_81 ) ;
if ( V_34 )
V_33 += sprintf ( V_33 , L_81 ) ;
if ( V_35 )
V_33 += sprintf ( V_33 , L_81 ) ;
} else {
if ( V_32 ) {
if ( V_20 )
V_33 += sprintf ( V_33 , L_82 , V_20 -> V_87 ) ;
else
V_33 += sprintf ( V_33 , L_81 ) ;
}
if ( V_34 ) {
if ( V_19 )
V_33 += sprintf ( V_33 , L_82 , V_19 -> V_82 ) ;
else
V_33 += sprintf ( V_33 , L_81 ) ;
}
if ( V_35 )
V_33 += sprintf ( V_33 , L_82 , V_18 -> V_21 ) ;
}
if ( V_36 )
V_33 += sprintf ( V_33 , L_83 ,
1.0 / V_117 * V_18 -> V_75 / V_106 ) ;
if ( V_36 )
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_18 -> V_76 / V_18 -> V_74 / V_118 ) ;
if ( V_36 ) {
if ( V_119 )
V_33 += sprintf ( V_33 , L_83 , V_120 / V_117 * V_18 -> V_75 / V_18 -> V_76 ) ;
else
V_33 += sprintf ( V_33 , L_83 ,
1.0 * V_18 -> V_74 / V_117 * V_18 -> V_75 / V_18 -> V_76 / V_106 ) ;
}
V_33 += sprintf ( V_33 , L_83 , 1.0 * V_18 -> V_74 / V_117 / V_106 ) ;
if ( ! V_37 )
goto V_38;
if ( V_39 )
V_33 += sprintf ( V_33 , L_82 , V_18 -> V_78 ) ;
if ( V_40 )
V_33 += sprintf ( V_33 , L_82 , V_18 -> V_79 ) ;
if ( V_41 )
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_18 -> V_77 / V_18 -> V_74 ) ;
if ( ! ( V_18 -> V_73 & V_109 ) )
goto V_38;
if ( V_41 && ! V_42 && ! V_43 )
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_19 -> V_83 / V_18 -> V_74 ) ;
if ( V_41 )
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_19 -> V_84 / V_18 -> V_74 ) ;
if ( V_44 )
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_19 -> V_85 / V_18 -> V_74 ) ;
for ( V_72 = 0 , V_31 = V_45 . V_46 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 ) {
if ( V_31 -> V_50 == 32 )
V_33 += sprintf ( V_33 , L_85 , ( unsigned long ) V_18 -> V_81 [ V_72 ] ) ;
else
V_33 += sprintf ( V_33 , L_86 , V_18 -> V_81 [ V_72 ] ) ;
} else if ( V_31 -> V_48 == V_121 ) {
V_33 += sprintf ( V_33 , L_87 , V_18 -> V_81 [ V_72 ] ) ;
} else if ( V_31 -> V_48 == V_122 ) {
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_18 -> V_81 [ V_72 ] / V_18 -> V_74 ) ;
}
}
if ( V_52 )
V_33 += sprintf ( V_33 , L_82 , V_19 -> V_86 ) ;
for ( V_72 = 0 , V_31 = V_45 . V_53 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 ) {
if ( V_31 -> V_50 == 32 )
V_33 += sprintf ( V_33 , L_85 , ( unsigned long ) V_19 -> V_81 [ V_72 ] ) ;
else
V_33 += sprintf ( V_33 , L_86 , V_19 -> V_81 [ V_72 ] ) ;
} else if ( V_31 -> V_48 == V_121 ) {
V_33 += sprintf ( V_33 , L_87 , V_19 -> V_81 [ V_72 ] ) ;
} else if ( V_31 -> V_48 == V_122 ) {
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_19 -> V_81 [ V_72 ] / V_18 -> V_74 ) ;
}
}
if ( ! ( V_18 -> V_73 & V_111 ) )
goto V_38;
if ( V_54 )
V_33 += sprintf ( V_33 , L_82 , V_20 -> V_105 ) ;
if ( V_55 ) {
if ( V_20 -> V_123 == - 1 ) {
V_33 += sprintf ( V_33 , L_88 ) ;
} else {
V_33 += sprintf ( V_33 , L_84 ,
V_20 -> V_123 / 10.0 / V_106 ) ;
}
}
if ( V_56 )
V_33 += sprintf ( V_33 , L_82 , V_20 -> V_124 ) ;
if ( V_57 ) {
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_88 / V_18 -> V_74 ) ;
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_89 / V_18 -> V_74 ) ;
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_90 / V_18 -> V_74 ) ;
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_91 / V_18 -> V_74 ) ;
}
if ( V_58 )
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_92 / V_18 -> V_74 ) ;
if ( V_59 )
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_93 / V_18 -> V_74 ) ;
if ( V_60 )
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_94 / V_18 -> V_74 ) ;
if ( V_61 )
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_95 / V_18 -> V_74 ) ;
if ( V_62 ) {
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_96 / V_18 -> V_74 ) ;
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_97 / V_18 -> V_74 ) ;
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_98 / V_18 -> V_74 ) ;
}
if ( V_106 < V_125 )
V_107 = L_84 ;
else
V_107 = L_89 ;
if ( V_63 && ! V_64 ) {
if ( V_63 & V_65 )
V_33 += sprintf ( V_33 , V_107 , V_20 -> V_99 * V_126 / V_106 ) ;
if ( V_63 & V_66 )
V_33 += sprintf ( V_33 , V_107 , V_20 -> V_100 * V_126 / V_106 ) ;
if ( V_63 & V_67 )
V_33 += sprintf ( V_33 , V_107 , V_20 -> V_101 * V_126 / V_106 ) ;
if ( V_63 & V_68 )
V_33 += sprintf ( V_33 , V_107 , V_20 -> V_102 * V_127 / V_106 ) ;
if ( V_63 & V_69 )
V_33 += sprintf ( V_33 , V_107 , 100.0 * V_20 -> V_103 * V_128 / V_106 ) ;
if ( V_63 & V_70 )
V_33 += sprintf ( V_33 , V_107 , 100.0 * V_20 -> V_104 * V_128 / V_106 ) ;
} else if ( V_63 && V_64 ) {
if ( V_63 & V_65 )
V_33 += sprintf ( V_33 , V_107 ,
V_20 -> V_99 * V_126 ) ;
if ( V_63 & V_129 )
V_33 += sprintf ( V_33 , V_107 ,
V_20 -> V_100 * V_126 ) ;
if ( V_63 & V_67 )
V_33 += sprintf ( V_33 , V_107 ,
V_20 -> V_101 * V_126 ) ;
if ( V_63 & V_68 )
V_33 += sprintf ( V_33 , V_107 ,
V_20 -> V_102 * V_127 ) ;
if ( V_63 & V_69 )
V_33 += sprintf ( V_33 , V_107 , 100.0 * V_20 -> V_103 * V_128 / V_106 ) ;
if ( V_63 & V_70 )
V_33 += sprintf ( V_33 , V_107 , 100.0 * V_20 -> V_104 * V_128 / V_106 ) ;
}
for ( V_72 = 0 , V_31 = V_45 . V_71 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 ) {
if ( V_31 -> V_50 == 32 )
V_33 += sprintf ( V_33 , L_85 , ( unsigned long ) V_20 -> V_81 [ V_72 ] ) ;
else
V_33 += sprintf ( V_33 , L_86 , V_20 -> V_81 [ V_72 ] ) ;
} else if ( V_31 -> V_48 == V_121 ) {
V_33 += sprintf ( V_33 , L_87 , V_20 -> V_81 [ V_72 ] ) ;
} else if ( V_31 -> V_48 == V_122 ) {
V_33 += sprintf ( V_33 , L_84 , 100.0 * V_20 -> V_81 [ V_72 ] / V_18 -> V_74 ) ;
}
}
V_38:
V_33 += sprintf ( V_33 , L_45 ) ;
return 0 ;
}
void F_20 ( void )
{
T_3 * V_130 ;
if ( V_131 == V_132 )
V_130 = stdout ;
else
V_130 = V_131 ;
fputs ( V_133 , V_130 ) ;
fflush ( V_130 ) ;
V_33 = V_133 ;
}
void F_21 ( void )
{
fputs ( V_133 , V_131 ) ;
fflush ( V_131 ) ;
V_33 = V_133 ;
}
void F_22 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_134 ;
if ( ! V_134 || ! V_135 )
F_17 () ;
if ( V_14 . V_136 > 1 )
F_19 ( & V_115 . V_116 , & V_115 . V_137 ,
& V_115 . V_138 ) ;
V_134 = 1 ;
if ( V_135 )
return;
F_3 ( F_19 , V_18 , V_19 , V_20 ) ;
}
int
F_23 ( struct V_6 * V_139 , struct V_6 * V_140 )
{
int V_72 ;
struct V_30 * V_31 ;
if ( V_57 ) {
V_140 -> V_88 = V_139 -> V_88 - V_140 -> V_88 ;
V_140 -> V_89 = V_139 -> V_89 - V_140 -> V_89 ;
V_140 -> V_90 = V_139 -> V_90 - V_140 -> V_90 ;
V_140 -> V_91 = V_139 -> V_91 - V_140 -> V_91 ;
}
V_140 -> V_92 = V_139 -> V_92 - V_140 -> V_92 ;
if ( V_59 )
V_140 -> V_93 = V_139 -> V_93 - V_140 -> V_93 ;
if ( V_60 )
V_140 -> V_94 = V_139 -> V_94 - V_140 -> V_94 ;
if ( V_61 )
V_140 -> V_95 = V_139 -> V_95 - V_140 -> V_95 ;
V_140 -> V_96 = V_139 -> V_96 - V_140 -> V_96 ;
V_140 -> V_97 = V_139 -> V_97 - V_140 -> V_97 ;
V_140 -> V_98 = V_139 -> V_98 - V_140 -> V_98 ;
V_140 -> V_105 = V_139 -> V_105 ;
if ( V_140 -> V_123 > V_139 -> V_123 )
V_140 -> V_123 = - 1 ;
else
V_140 -> V_123 = V_139 -> V_123 - V_140 -> V_123 ;
V_140 -> V_124 = V_139 -> V_124 ;
F_24 ( V_139 -> V_99 , V_140 -> V_99 ) ;
F_24 ( V_139 -> V_100 , V_140 -> V_100 ) ;
F_24 ( V_139 -> V_101 , V_140 -> V_101 ) ;
F_24 ( V_139 -> V_102 , V_140 -> V_102 ) ;
F_24 ( V_139 -> V_103 , V_140 -> V_103 ) ;
F_24 ( V_139 -> V_104 , V_140 -> V_104 ) ;
for ( V_72 = 0 , V_31 = V_45 . V_71 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 )
V_140 -> V_81 [ V_72 ] = V_139 -> V_81 [ V_72 ] ;
else
V_140 -> V_81 [ V_72 ] = V_139 -> V_81 [ V_72 ] - V_140 -> V_81 [ V_72 ] ;
}
return 0 ;
}
void
F_25 ( struct V_5 * V_139 , struct V_5 * V_140 )
{
int V_72 ;
struct V_30 * V_31 ;
V_140 -> V_83 = V_139 -> V_83 - V_140 -> V_83 ;
V_140 -> V_84 = V_139 -> V_84 - V_140 -> V_84 ;
V_140 -> V_85 = V_139 -> V_85 - V_140 -> V_85 ;
V_140 -> V_86 = V_139 -> V_86 ;
for ( V_72 = 0 , V_31 = V_45 . V_53 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 )
V_140 -> V_81 [ V_72 ] = V_139 -> V_81 [ V_72 ] ;
else
V_140 -> V_81 [ V_72 ] = V_139 -> V_81 [ V_72 ] - V_140 -> V_81 [ V_72 ] ;
}
}
int
F_26 ( struct V_4 * V_139 , struct V_4 * V_140 ,
struct V_5 * V_141 )
{
int V_72 ;
struct V_30 * V_31 ;
V_140 -> V_74 = V_139 -> V_74 - V_140 -> V_74 ;
if ( V_140 -> V_74 < ( 1000 * 1000 ) )
F_27 ( - 3 , L_90
L_91
L_92 ) ;
V_140 -> V_77 = V_139 -> V_77 - V_140 -> V_77 ;
if ( V_36 ) {
if ( ( V_139 -> V_75 > V_140 -> V_75 ) && ( V_139 -> V_76 > V_140 -> V_76 ) ) {
V_140 -> V_75 = V_139 -> V_75 - V_140 -> V_75 ;
V_140 -> V_76 = V_139 -> V_76 - V_140 -> V_76 ;
} else {
return - 1 ;
}
}
if ( V_142 ) {
} else {
if ( ( V_140 -> V_76 + V_141 -> V_83 + V_141 -> V_84 + V_141 -> V_85 ) > V_140 -> V_74 )
V_140 -> V_77 = 0 ;
else {
V_140 -> V_77 = V_140 -> V_74 - V_140 -> V_76 - V_141 -> V_83
- V_141 -> V_84 - V_141 -> V_85 ;
}
}
if ( V_140 -> V_76 == 0 ) {
if ( V_37 > 1 )
fprintf ( V_131 , L_93 , V_140 -> V_21 ) ;
V_140 -> V_76 = 1 ;
}
if ( V_39 )
V_140 -> V_78 = V_139 -> V_78 - V_140 -> V_78 ;
if ( V_40 )
V_140 -> V_79 = V_139 -> V_79 - V_140 -> V_79 ;
for ( V_72 = 0 , V_31 = V_45 . V_46 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 )
V_140 -> V_81 [ V_72 ] = V_139 -> V_81 [ V_72 ] ;
else
V_140 -> V_81 [ V_72 ] = V_139 -> V_81 [ V_72 ] - V_140 -> V_81 [ V_72 ] ;
}
return 0 ;
}
int F_28 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_143 ,
struct V_5 * V_144 , struct V_6 * V_145 )
{
int V_10 = 0 ;
if ( V_18 -> V_73 & V_109 )
F_25 ( V_19 , V_144 ) ;
V_10 = F_26 ( V_18 , V_143 , V_144 ) ;
if ( V_10 )
return V_10 ;
if ( V_18 -> V_73 & V_111 )
V_10 = F_23 ( V_20 , V_145 ) ;
return V_10 ;
}
void F_29 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_72 ;
struct V_30 * V_31 ;
V_18 -> V_74 = 0 ;
V_18 -> V_75 = 0 ;
V_18 -> V_76 = 0 ;
V_18 -> V_77 = 0 ;
V_18 -> V_78 = 0 ;
V_18 -> V_79 = 0 ;
V_18 -> V_73 = V_109 | V_111 ;
V_19 -> V_83 = 0 ;
V_19 -> V_84 = 0 ;
V_19 -> V_85 = 0 ;
V_19 -> V_86 = 0 ;
V_20 -> V_88 = 0 ;
V_20 -> V_89 = 0 ;
V_20 -> V_90 = 0 ;
V_20 -> V_91 = 0 ;
V_20 -> V_92 = 0 ;
if ( V_59 )
V_20 -> V_93 = 0 ;
if ( V_60 )
V_20 -> V_94 = 0 ;
if ( V_61 )
V_20 -> V_95 = 0 ;
V_20 -> V_96 = 0 ;
V_20 -> V_97 = 0 ;
V_20 -> V_98 = 0 ;
V_20 -> V_99 = 0 ;
V_20 -> V_102 = 0 ;
V_20 -> V_100 = 0 ;
V_20 -> V_101 = 0 ;
V_20 -> V_103 = 0 ;
V_20 -> V_104 = 0 ;
V_20 -> V_105 = 0 ;
V_20 -> V_123 = 0 ;
V_20 -> V_124 = 0 ;
for ( V_72 = 0 , V_31 = V_45 . V_46 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 )
V_18 -> V_81 [ V_72 ] = 0 ;
for ( V_72 = 0 , V_31 = V_45 . V_53 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 )
V_19 -> V_81 [ V_72 ] = 0 ;
for ( V_72 = 0 , V_31 = V_45 . V_71 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 )
V_20 -> V_81 [ V_72 ] = 0 ;
}
int F_30 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
int V_72 ;
struct V_30 * V_31 ;
V_115 . V_116 . V_74 += V_18 -> V_74 ;
V_115 . V_116 . V_75 += V_18 -> V_75 ;
V_115 . V_116 . V_76 += V_18 -> V_76 ;
V_115 . V_116 . V_77 += V_18 -> V_77 ;
V_115 . V_116 . V_78 += V_18 -> V_78 ;
V_115 . V_116 . V_79 += V_18 -> V_79 ;
for ( V_72 = 0 , V_31 = V_45 . V_46 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 )
continue;
V_115 . V_116 . V_81 [ V_72 ] += V_18 -> V_81 [ V_72 ] ;
}
if ( ! ( V_18 -> V_73 & V_109 ) )
return 0 ;
V_115 . V_137 . V_83 += V_19 -> V_83 ;
V_115 . V_137 . V_84 += V_19 -> V_84 ;
V_115 . V_137 . V_85 += V_19 -> V_85 ;
V_115 . V_137 . V_86 = F_31 ( V_115 . V_137 . V_86 , V_19 -> V_86 ) ;
for ( V_72 = 0 , V_31 = V_45 . V_53 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 )
continue;
V_115 . V_137 . V_81 [ V_72 ] += V_19 -> V_81 [ V_72 ] ;
}
if ( ! ( V_18 -> V_73 & V_111 ) )
return 0 ;
if ( V_57 ) {
V_115 . V_138 . V_88 += V_20 -> V_88 ;
V_115 . V_138 . V_89 += V_20 -> V_89 ;
V_115 . V_138 . V_90 += V_20 -> V_90 ;
V_115 . V_138 . V_91 += V_20 -> V_91 ;
}
V_115 . V_138 . V_92 += V_20 -> V_92 ;
if ( V_59 )
V_115 . V_138 . V_93 += V_20 -> V_93 ;
if ( V_60 )
V_115 . V_138 . V_94 += V_20 -> V_94 ;
if ( V_61 )
V_115 . V_138 . V_95 += V_20 -> V_95 ;
V_115 . V_138 . V_96 += V_20 -> V_96 ;
V_115 . V_138 . V_97 += V_20 -> V_97 ;
V_115 . V_138 . V_98 += V_20 -> V_98 ;
V_115 . V_138 . V_99 += V_20 -> V_99 ;
V_115 . V_138 . V_102 += V_20 -> V_102 ;
V_115 . V_138 . V_100 += V_20 -> V_100 ;
V_115 . V_138 . V_101 += V_20 -> V_101 ;
V_115 . V_138 . V_123 = V_20 -> V_123 ;
V_115 . V_138 . V_124 = V_20 -> V_124 ;
V_115 . V_138 . V_105 = F_31 ( V_115 . V_138 . V_105 , V_20 -> V_105 ) ;
V_115 . V_138 . V_103 += V_20 -> V_103 ;
V_115 . V_138 . V_104 += V_20 -> V_104 ;
for ( V_72 = 0 , V_31 = V_45 . V_71 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 )
continue;
V_115 . V_138 . V_81 [ V_72 ] += V_20 -> V_81 [ V_72 ] ;
}
return 0 ;
}
void F_32 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
int V_72 ;
struct V_30 * V_31 ;
F_29 ( & V_115 . V_116 , & V_115 . V_137 , & V_115 . V_138 ) ;
F_3 ( F_30 , V_18 , V_19 , V_20 ) ;
V_115 . V_116 . V_74 /= V_14 . V_136 ;
V_115 . V_116 . V_75 /= V_14 . V_136 ;
V_115 . V_116 . V_76 /= V_14 . V_136 ;
V_115 . V_116 . V_77 /= V_14 . V_136 ;
V_115 . V_137 . V_83 /= V_14 . V_146 ;
V_115 . V_137 . V_84 /= V_14 . V_146 ;
V_115 . V_137 . V_85 /= V_14 . V_146 ;
if ( V_57 ) {
V_115 . V_138 . V_88 /= V_14 . V_15 ;
V_115 . V_138 . V_89 /= V_14 . V_15 ;
V_115 . V_138 . V_90 /= V_14 . V_15 ;
V_115 . V_138 . V_91 /= V_14 . V_15 ;
}
V_115 . V_138 . V_92 /= V_14 . V_15 ;
if ( V_59 )
V_115 . V_138 . V_93 /= V_14 . V_15 ;
if ( V_60 )
V_115 . V_138 . V_94 /= V_14 . V_15 ;
if ( V_61 )
V_115 . V_138 . V_95 /= V_14 . V_15 ;
V_115 . V_138 . V_96 /= V_14 . V_15 ;
V_115 . V_138 . V_97 /= V_14 . V_15 ;
V_115 . V_138 . V_98 /= V_14 . V_15 ;
for ( V_72 = 0 , V_31 = V_45 . V_46 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 )
continue;
V_115 . V_116 . V_81 [ V_72 ] /= V_14 . V_136 ;
}
for ( V_72 = 0 , V_31 = V_45 . V_53 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 )
continue;
V_115 . V_137 . V_81 [ V_72 ] /= V_14 . V_146 ;
}
for ( V_72 = 0 , V_31 = V_45 . V_71 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( V_31 -> V_48 == V_49 )
continue;
V_115 . V_138 . V_81 [ V_72 ] /= V_14 . V_15 ;
}
}
static unsigned long long F_33 ( void )
{
unsigned int V_147 , V_148 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_147 | ( ( unsigned long long ) V_148 ) << 32 ;
}
int F_34 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
unsigned long long V_29 ;
int V_149 = 0 ;
struct V_30 * V_31 ;
int V_72 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_131 , L_94 , V_1 ) ;
return - 1 ;
}
V_150:
V_18 -> V_74 = F_33 () ;
if ( V_36 ) {
unsigned long long V_151 , V_152 , V_153 , V_154 , V_155 ;
if ( F_15 ( V_1 , V_156 , & V_18 -> V_75 ) )
return - 3 ;
V_18 -> V_74 = F_33 () ;
V_151 = V_18 -> V_74 ;
if ( F_15 ( V_1 , V_156 , & V_18 -> V_75 ) )
return - 3 ;
V_152 = F_33 () ;
if ( F_15 ( V_1 , V_157 , & V_18 -> V_76 ) )
return - 4 ;
V_153 = F_33 () ;
V_154 = V_152 - V_151 ;
V_155 = V_153 - V_152 ;
if ( ( V_154 > ( 2 * V_155 ) ) || ( V_155 > ( 2 * V_154 ) ) ) {
V_149 ++ ;
if ( V_149 < 5 )
goto V_150;
else
F_35 ( L_95 ,
V_1 , V_154 , V_155 ) ;
}
V_149 = 0 ;
V_18 -> V_75 = V_18 -> V_75 * V_158 ;
V_18 -> V_76 = V_18 -> V_76 * V_158 ;
}
if ( V_39 )
V_18 -> V_78 = V_159 [ V_1 ] ;
if ( V_40 ) {
if ( F_15 ( V_1 , V_160 , & V_29 ) )
return - 5 ;
V_18 -> V_79 = V_29 & 0xFFFFFFFF ;
}
if ( V_142 ) {
if ( F_15 ( V_1 , V_161 , & V_18 -> V_77 ) )
return - 6 ;
}
for ( V_72 = 0 , V_31 = V_45 . V_46 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( F_15 ( V_1 , V_31 -> V_80 , & V_18 -> V_81 [ V_72 ] ) )
return - 10 ;
}
if ( ! ( V_18 -> V_73 & V_109 ) )
return 0 ;
if ( V_41 && ! V_42 && ! V_43 ) {
if ( F_15 ( V_1 , V_162 , & V_19 -> V_83 ) )
return - 6 ;
}
if ( V_41 && ! V_43 ) {
if ( F_15 ( V_1 , V_163 , & V_19 -> V_84 ) )
return - 7 ;
} else if ( V_43 ) {
if ( F_15 ( V_1 , V_164 , & V_19 -> V_84 ) )
return - 7 ;
}
if ( V_44 )
if ( F_15 ( V_1 , V_165 , & V_19 -> V_85 ) )
return - 8 ;
if ( V_52 ) {
if ( F_15 ( V_1 , V_166 , & V_29 ) )
return - 9 ;
V_19 -> V_86 = V_167 - ( ( V_29 >> 16 ) & 0x7F ) ;
}
for ( V_72 = 0 , V_31 = V_45 . V_53 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( F_15 ( V_1 , V_31 -> V_80 , & V_19 -> V_81 [ V_72 ] ) )
return - 10 ;
}
if ( ! ( V_18 -> V_73 & V_111 ) )
return 0 ;
if ( V_57 ) {
if ( F_15 ( V_1 , V_168 , & V_20 -> V_88 ) )
return - 10 ;
if ( F_15 ( V_1 , V_169 , & V_20 -> V_89 ) )
return - 11 ;
if ( F_15 ( V_1 , V_170 , & V_20 -> V_90 ) )
return - 12 ;
if ( F_15 ( V_1 , V_171 , & V_20 -> V_91 ) )
return - 13 ;
}
if ( V_59 )
if ( F_15 ( V_1 , V_172 , & V_20 -> V_93 ) )
return - 9 ;
if ( V_60 )
if ( F_15 ( V_1 , V_173 , & V_20 -> V_94 ) )
return - 10 ;
if ( V_58 )
if ( F_15 ( V_1 , V_174 , & V_20 -> V_92 ) )
return - 11 ;
if ( V_61 )
if ( F_15 ( V_1 , V_175 , & V_20 -> V_95 ) )
return - 12 ;
if ( V_62 ) {
if ( F_15 ( V_1 , V_176 , & V_20 -> V_96 ) )
return - 13 ;
if ( F_15 ( V_1 , V_177 , & V_20 -> V_97 ) )
return - 13 ;
if ( F_15 ( V_1 , V_178 , & V_20 -> V_98 ) )
return - 13 ;
}
if ( V_63 & V_65 ) {
if ( F_15 ( V_1 , V_179 , & V_29 ) )
return - 13 ;
V_20 -> V_99 = V_29 & 0xFFFFFFFF ;
}
if ( V_63 & V_66 ) {
if ( F_15 ( V_1 , V_180 , & V_29 ) )
return - 14 ;
V_20 -> V_100 = V_29 & 0xFFFFFFFF ;
}
if ( V_63 & V_68 ) {
if ( F_15 ( V_1 , V_181 , & V_29 ) )
return - 15 ;
V_20 -> V_102 = V_29 & 0xFFFFFFFF ;
}
if ( V_63 & V_67 ) {
if ( F_15 ( V_1 , V_182 , & V_29 ) )
return - 16 ;
V_20 -> V_101 = V_29 & 0xFFFFFFFF ;
}
if ( V_63 & V_69 ) {
if ( F_15 ( V_1 , V_183 , & V_29 ) )
return - 16 ;
V_20 -> V_103 = V_29 & 0xFFFFFFFF ;
}
if ( V_63 & V_70 ) {
if ( F_15 ( V_1 , V_184 , & V_29 ) )
return - 16 ;
V_20 -> V_104 = V_29 & 0xFFFFFFFF ;
}
if ( V_54 ) {
if ( F_15 ( V_1 , V_185 , & V_29 ) )
return - 17 ;
V_20 -> V_105 = V_167 - ( ( V_29 >> 16 ) & 0x7F ) ;
}
if ( V_55 )
V_20 -> V_123 = V_186 ;
if ( V_56 )
V_20 -> V_124 = V_187 ;
for ( V_72 = 0 , V_31 = V_45 . V_71 ; V_31 ; V_72 ++ , V_31 = V_31 -> V_47 ) {
if ( F_15 ( V_1 , V_31 -> V_80 , & V_20 -> V_81 [ V_72 ] ) )
return - 10 ;
}
return 0 ;
}
static void
F_36 ()
{
V_118 = V_120 / V_188 ;
}
static void
F_37 ( void )
{
unsigned long long V_29 ;
unsigned int V_189 ;
F_15 ( V_190 , V_191 , & V_29 ) ;
fprintf ( V_131 , L_96 , V_190 , V_29 ) ;
V_189 = ( V_29 >> 40 ) & 0xFF ;
fprintf ( V_131 , L_97 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 8 ) & 0xFF ;
fprintf ( V_131 , L_98 ,
V_189 , V_192 , V_189 * V_192 ) ;
F_15 ( V_190 , V_193 , & V_29 ) ;
fprintf ( V_131 , L_99 ,
V_190 , V_29 , V_29 & 0x2 ? L_100 : L_101 ) ;
return;
}
static void
F_38 ( void )
{
unsigned long long V_29 ;
unsigned int V_189 ;
F_15 ( V_190 , V_194 , & V_29 ) ;
fprintf ( V_131 , L_102 , V_190 , V_29 ) ;
V_189 = ( V_29 >> 8 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_103 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 0 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_104 ,
V_189 , V_192 , V_189 * V_192 ) ;
return;
}
static void
F_39 ( void )
{
unsigned long long V_29 ;
unsigned int V_189 ;
F_15 ( V_190 , V_195 , & V_29 ) ;
fprintf ( V_131 , L_105 , V_190 , V_29 ) ;
V_189 = ( V_29 >> 56 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_106 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 48 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_107 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 40 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_108 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 32 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_109 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 24 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_110 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 16 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_111 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 8 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_112 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 0 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_113 ,
V_189 , V_192 , V_189 * V_192 ) ;
return;
}
static void
F_40 ( void )
{
unsigned long long V_29 ;
unsigned int V_189 ;
F_15 ( V_190 , V_196 , & V_29 ) ;
fprintf ( V_131 , L_114 , V_190 , V_29 ) ;
V_189 = ( V_29 >> 56 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_115 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 48 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_116 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 40 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_117 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 32 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_118 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 24 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_119 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 16 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_120 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 8 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_121 ,
V_189 , V_192 , V_189 * V_192 ) ;
V_189 = ( V_29 >> 0 ) & 0xFF ;
if ( V_189 )
fprintf ( V_131 , L_122 ,
V_189 , V_192 , V_189 * V_192 ) ;
return;
}
static void
F_41 ( void )
{
const unsigned int V_197 = 7 ;
unsigned long long V_29 ;
int V_198 , V_199 ;
int V_72 , V_200 ;
unsigned int V_137 [ V_197 ] ;
unsigned int V_189 [ V_197 ] ;
F_15 ( V_190 , V_196 , & V_29 ) ;
fprintf ( V_131 , L_114 ,
V_190 , V_29 ) ;
V_200 = 0 ;
V_137 [ V_200 ] = ( V_29 & 0xFF ) >> 1 ;
V_189 [ V_200 ] = ( V_29 >> 8 ) & 0xFF ;
for ( V_72 = 16 ; V_72 < 64 ; V_72 += 8 ) {
V_198 = ( V_29 >> V_72 ) & 0x1F ;
V_199 = ( V_29 >> ( V_72 + 5 ) ) & 0x7 ;
V_137 [ V_200 + 1 ] = V_137 [ V_200 ] + V_198 ;
V_189 [ V_200 + 1 ] = V_189 [ V_200 ] - V_199 ;
V_200 ++ ;
}
for ( V_72 = V_197 - 1 ; V_72 >= 0 ; V_72 -- )
if ( V_72 > 0 ? V_189 [ V_72 ] != V_189 [ V_72 - 1 ] : 1 )
fprintf ( V_131 ,
L_123 ,
V_189 [ V_72 ] , V_192 , V_189 [ V_72 ] * V_192 , V_137 [ V_72 ] ) ;
}
static void
F_42 ( void )
{
unsigned long long V_29 ;
F_15 ( V_190 , V_201 , & V_29 ) ;
#define F_43 (1UL << 27)
#define F_44 (1UL << 28)
fprintf ( V_131 , L_124 , V_190 , V_29 ) ;
fprintf ( V_131 , L_125 ,
( V_29 & F_44 ) ? L_126 : L_127 ,
( V_29 & F_43 ) ? L_128 : L_127 ,
( V_29 & V_202 ) ? L_129 : L_127 ,
( V_29 & V_203 ) ? L_130 : L_127 ,
( V_29 & ( 1 << 15 ) ) ? L_127 : L_131 ,
( unsigned int ) V_29 & 0xF ,
V_204 [ V_205 ] ) ;
return;
}
static void
F_45 ( void )
{
unsigned long long V_29 ;
F_15 ( V_190 , V_206 , & V_29 ) ;
fprintf ( V_131 , L_132 , V_190 , V_29 ) ;
fprintf ( V_131 , L_133 , ( unsigned int ) V_29 & 0xFF ) ;
F_15 ( V_190 , V_207 , & V_29 ) ;
fprintf ( V_131 , L_134 , V_190 , V_29 ) ;
if ( V_29 ) {
fprintf ( V_131 , L_135 , ( unsigned int ) ( V_29 >> 48 ) & 0x7FFF ) ;
fprintf ( V_131 , L_136 , ( unsigned int ) ( V_29 >> 32 ) & 0x7FFF ) ;
fprintf ( V_131 , L_137 , ( unsigned int ) ( V_29 >> 16 ) & 0xFF ) ;
fprintf ( V_131 , L_138 , ( unsigned int ) ( V_29 ) & 0x7FFF ) ;
}
fprintf ( V_131 , L_139 ) ;
F_15 ( V_190 , V_208 , & V_29 ) ;
fprintf ( V_131 , L_140 , V_190 , V_29 ) ;
if ( V_29 ) {
fprintf ( V_131 , L_141 , ( unsigned int ) ( V_29 >> 48 ) & 0x7FFF ) ;
fprintf ( V_131 , L_142 , ( unsigned int ) ( V_29 >> 32 ) & 0x7FFF ) ;
fprintf ( V_131 , L_143 , ( unsigned int ) ( V_29 >> 16 ) & 0xFF ) ;
fprintf ( V_131 , L_144 , ( unsigned int ) ( V_29 ) & 0x7FFF ) ;
}
fprintf ( V_131 , L_139 ) ;
F_15 ( V_190 , V_209 , & V_29 ) ;
fprintf ( V_131 , L_145 , V_190 , V_29 ) ;
if ( ( V_29 ) & 0x3 )
fprintf ( V_131 , L_146 , ( unsigned int ) ( V_29 ) & 0x3 ) ;
fprintf ( V_131 , L_147 , ( unsigned int ) ( V_29 >> 31 ) & 1 ) ;
fprintf ( V_131 , L_139 ) ;
F_15 ( V_190 , V_210 , & V_29 ) ;
fprintf ( V_131 , L_148 , V_190 , V_29 ) ;
fprintf ( V_131 , L_149 , ( unsigned int ) ( V_29 ) & 0xFF ) ;
fprintf ( V_131 , L_147 , ( unsigned int ) ( V_29 >> 31 ) & 1 ) ;
fprintf ( V_131 , L_139 ) ;
}
void F_46 ( void )
{
unsigned long long V_29 ;
F_15 ( V_190 , V_211 , & V_29 ) ;
fprintf ( V_131 , L_150 , V_190 , V_29 ) ;
fprintf ( V_131 , L_151 , V_29 & ( 1 << 15 ) ? L_127 : L_152 ,
( V_29 & 0x3FF ) * V_212 [ ( V_29 >> 10 ) & 0x3 ] ) ;
F_15 ( V_190 , V_213 , & V_29 ) ;
fprintf ( V_131 , L_153 , V_190 , V_29 ) ;
fprintf ( V_131 , L_151 , V_29 & ( 1 << 15 ) ? L_127 : L_152 ,
( V_29 & 0x3FF ) * V_212 [ ( V_29 >> 10 ) & 0x3 ] ) ;
F_15 ( V_190 , V_214 , & V_29 ) ;
fprintf ( V_131 , L_154 , V_190 , V_29 ) ;
fprintf ( V_131 , L_151 , V_29 & ( 1 << 15 ) ? L_127 : L_152 ,
( V_29 & 0x3FF ) * V_212 [ ( V_29 >> 10 ) & 0x3 ] ) ;
if ( ! V_215 )
return;
F_15 ( V_190 , V_216 , & V_29 ) ;
fprintf ( V_131 , L_155 , V_190 , V_29 ) ;
fprintf ( V_131 , L_151 , V_29 & ( 1 << 15 ) ? L_127 : L_152 ,
( V_29 & 0x3FF ) * V_212 [ ( V_29 >> 10 ) & 0x3 ] ) ;
F_15 ( V_190 , V_217 , & V_29 ) ;
fprintf ( V_131 , L_156 , V_190 , V_29 ) ;
fprintf ( V_131 , L_151 , V_29 & ( 1 << 15 ) ? L_127 : L_152 ,
( V_29 & 0x3FF ) * V_212 [ ( V_29 >> 10 ) & 0x3 ] ) ;
F_15 ( V_190 , V_218 , & V_29 ) ;
fprintf ( V_131 , L_157 , V_190 , V_29 ) ;
fprintf ( V_131 , L_151 , V_29 & ( 1 << 15 ) ? L_127 : L_152 ,
( V_29 & 0x3FF ) * V_212 [ ( V_29 >> 10 ) & 0x3 ] ) ;
}
void F_47 ( void )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_14 . V_219 + 1 ; ++ V_72 ) {
if ( V_26 [ V_72 ] != 0 )
F_48 ( V_26 [ V_72 ] ) ;
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
free ( V_220 ) ;
free ( V_221 ) ;
free ( V_222 ) ;
V_220 = NULL ;
V_221 = NULL ;
V_222 = NULL ;
free ( V_223 ) ;
free ( V_224 ) ;
free ( V_225 ) ;
V_223 = NULL ;
V_224 = NULL ;
V_225 = NULL ;
free ( V_133 ) ;
V_133 = NULL ;
V_33 = NULL ;
F_47 () ;
free ( V_226 ) ;
free ( V_159 ) ;
}
T_3 * F_51 ( const char * V_227 , const char * V_228 )
{
T_3 * V_130 = fopen ( V_227 , V_228 ) ;
if ( ! V_130 )
F_14 ( 1 , L_158 , V_227 ) ;
return V_130 ;
}
int F_52 ( const char * V_229 , ... )
{
T_4 args ;
char V_227 [ V_230 ] ;
T_3 * V_130 ;
int V_231 ;
va_start ( args , V_229 ) ;
vsnprintf ( V_227 , sizeof( V_227 ) , V_229 , args ) ;
va_end ( args ) ;
V_130 = F_51 ( V_227 , L_159 ) ;
if ( fscanf ( V_130 , L_160 , & V_231 ) != 1 )
F_14 ( 1 , L_161 , V_227 ) ;
fclose ( V_130 ) ;
return V_231 ;
}
int F_53 ( int V_1 )
{
char V_227 [ 64 ] ;
T_3 * V_130 ;
int V_232 ;
char V_233 ;
int V_72 ;
sprintf ( V_227 ,
L_162 ,
V_1 ) ;
V_130 = fopen ( V_227 , L_159 ) ;
if ( V_130 == NULL ) {
perror ( V_227 ) ;
exit ( 1 ) ;
}
for ( V_72 = 0 ; V_72 < V_14 . V_17 ; V_72 ++ ) {
fscanf ( V_130 , L_160 , & V_232 ) ;
if ( V_232 == V_1 ) {
fclose ( V_130 ) ;
return V_72 ;
}
if ( V_72 != ( V_14 . V_17 - 1 ) )
fscanf ( V_130 , L_163 , & V_233 ) ;
}
fclose ( V_130 ) ;
return - 1 ;
}
int F_54 ( int V_1 )
{
return V_1 == F_52 ( L_164 , V_1 ) ;
}
int F_55 ( int V_1 )
{
return F_52 ( L_165 , V_1 ) ;
}
int F_56 ( int V_1 )
{
return F_52 ( L_166 , V_1 ) ;
}
int F_57 ( int V_1 )
{
char V_227 [ 80 ] ;
T_3 * V_130 ;
int V_234 ;
int V_235 = 0 ;
char V_233 ;
char V_236 [ 100 ] ;
char * V_237 ;
sprintf ( V_227 , L_162 , V_1 ) ;
V_130 = F_51 ( V_227 , L_159 ) ;
fscanf ( V_130 , L_167 , & V_234 , & V_233 ) ;
fseek ( V_130 , 0 , V_238 ) ;
fgets ( V_236 , 100 , V_130 ) ;
V_237 = strchr ( V_236 , V_233 ) ;
while ( V_237 != NULL ) {
V_235 ++ ;
V_237 = strchr ( V_237 + 1 , V_233 ) ;
}
fclose ( V_130 ) ;
return V_235 + 1 ;
}
int F_58 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_239 , struct V_5 * V_240 ,
struct V_6 * V_241 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_143 ;
struct V_5 * V_19 , * V_144 ;
struct V_6 * V_20 , * V_145 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_143 = F_5 ( V_239 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_144 = F_6 ( V_240 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_145 = F_7 ( V_241 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_143 , V_144 , V_145 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_59 ( int (F_4)( int ) )
{
T_3 * V_242 ;
int V_243 ;
int V_10 ;
V_242 = F_51 ( V_244 , L_159 ) ;
V_10 = fscanf ( V_242 , L_168 ) ;
if ( V_10 != 0 )
F_14 ( 1 , L_169 , V_244 ) ;
while ( 1 ) {
V_10 = fscanf ( V_242 , L_170 , & V_243 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_243 ) ;
if ( V_10 ) {
fclose ( V_242 ) ;
return ( V_10 ) ;
}
}
fclose ( V_242 ) ;
return 0 ;
}
void F_60 ( void )
{
F_49 () ;
F_61 () ;
printf ( L_171 , V_14 . V_136 ) ;
}
int F_62 ( int V_1 )
{
if ( V_14 . V_219 < V_1 )
V_14 . V_219 = V_1 ;
V_14 . V_136 += 1 ;
return 0 ;
}
int F_63 ( int V_1 )
{
F_10 ( V_1 , V_2 , V_3 ) ;
return 0 ;
}
int F_64 ( void )
{
static T_3 * V_242 ;
int V_245 , V_10 ;
if ( V_242 == NULL )
V_242 = F_51 ( L_172 , L_159 ) ;
else
rewind ( V_242 ) ;
for ( V_245 = 0 ; V_245 < V_14 . V_136 ; ++ V_245 ) {
int V_246 ;
V_10 = fscanf ( V_242 , L_173 , & V_246 ) ;
if ( V_10 != 1 )
break;
if ( V_246 > V_14 . V_219 ) {
F_65 ( L_174 , V_246 , V_14 . V_219 ) ;
return 1 ;
}
V_226 [ V_245 ] = V_246 ;
V_159 [ V_246 ] = 0 ;
}
while ( 1 ) {
int V_245 ;
char V_247 [ 64 ] ;
V_10 = fscanf ( V_242 , L_175 , V_247 ) ;
if ( V_10 != 1 )
break;
for ( V_245 = 0 ; V_245 < V_14 . V_136 ; ++ V_245 ) {
int V_246 , V_78 ;
V_10 = fscanf ( V_242 , L_176 , & V_78 ) ;
if ( V_10 != 1 )
break;
V_246 = V_226 [ V_245 ] ;
V_159 [ V_246 ] += V_78 ;
}
while ( getc ( V_242 ) != '\n' )
;
}
return 0 ;
}
int F_66 ( void )
{
T_3 * V_242 ;
int V_10 ;
V_242 = F_51 ( L_177 , L_159 ) ;
V_10 = fscanf ( V_242 , L_178 , & V_186 ) ;
if ( V_10 != 1 )
F_14 ( 1 , L_179 ) ;
fclose ( V_242 ) ;
return 0 ;
}
int F_67 ( void )
{
static T_3 * V_242 ;
int V_10 ;
if ( V_242 == NULL )
V_242 = F_51 ( L_180 , L_159 ) ;
else
rewind ( V_242 ) ;
V_10 = fscanf ( V_242 , L_160 , & V_187 ) ;
if ( V_10 != 1 )
F_14 ( 1 , L_181 ) ;
return 0 ;
}
int F_68 ( void )
{
if ( F_64 () )
return 1 ;
if ( V_55 )
F_66 () ;
if ( V_56 )
F_67 () ;
return 0 ;
}
void F_69 ()
{
int V_10 ;
int V_248 = 0 ;
V_249:
V_248 ++ ;
F_68 () ;
V_10 = F_3 ( F_34 , V_250 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
if ( V_248 > 1 ) {
exit ( V_10 ) ;
}
F_60 () ;
goto V_249;
}
V_248 = 0 ;
F_70 ( & V_251 , (struct V_252 * ) NULL ) ;
while ( 1 ) {
if ( F_59 ( F_1 ) ) {
F_60 () ;
goto V_249;
}
F_71 ( & V_253 , NULL ) ;
if ( F_68 () )
goto V_249;
V_10 = F_3 ( F_34 , V_254 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_60 () ;
goto V_249;
}
F_70 ( & V_255 , (struct V_252 * ) NULL ) ;
F_72 ( & V_255 , & V_251 , & V_112 ) ;
if ( F_58 ( F_28 , V_254 , V_250 ) ) {
F_60 () ;
goto V_249;
}
F_32 ( V_250 ) ;
F_22 ( V_250 ) ;
F_20 () ;
F_71 ( & V_253 , NULL ) ;
if ( F_68 () )
goto V_249;
V_10 = F_3 ( F_34 , V_250 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_60 () ;
goto V_249;
}
F_70 ( & V_251 , (struct V_252 * ) NULL ) ;
F_72 ( & V_251 , & V_255 , & V_112 ) ;
if ( F_58 ( F_28 , V_250 , V_254 ) ) {
F_60 () ;
goto V_249;
}
F_32 ( V_254 ) ;
F_22 ( V_254 ) ;
F_20 () ;
}
}
void F_73 ()
{
struct V_256 V_257 ;
char V_24 [ 32 ] ;
sprintf ( V_24 , L_1 , V_190 ) ;
if ( V_256 ( V_24 , & V_257 ) )
if ( system ( L_182 ) )
F_14 ( - 5 , L_183 ) ;
}
void F_74 ()
{
struct V_258 V_259 ;
T_5 V_260 = & V_259 ;
struct V_261 V_262 ;
T_6 V_263 = & V_262 ;
extern int V_264 ( T_5 V_265 , T_6 V_266 ) ;
int V_267 = 0 ;
char V_24 [ 32 ] ;
V_260 -> V_268 = F_75 () ;
V_260 -> V_269 = V_270 ;
if ( V_264 ( V_260 , V_263 ) < 0 )
F_14 ( - 6 , L_184 ) ;
if ( ( V_263 -> V_271 & ( 1 << V_272 ) ) == 0 ) {
V_267 ++ ;
F_35 ( L_185
L_186 , V_273 ) ;
}
sprintf ( V_24 , L_1 , V_190 ) ;
if ( F_76 ( V_24 , V_274 ) ) {
V_267 ++ ;
F_65 ( L_187 ) ;
}
if ( V_267 )
if ( F_77 () != 0 )
F_35 ( L_188 ) ;
if ( V_267 )
exit ( - 6 ) ;
}
int F_78 ( unsigned int V_275 , unsigned int V_276 )
{
unsigned long long V_29 ;
unsigned int V_277 ;
int * V_278 ;
if ( ! V_279 )
return 0 ;
if ( V_275 != 6 )
return 0 ;
V_192 = F_79 ( V_275 , V_276 ) ;
switch ( V_276 ) {
case V_280 :
case V_281 :
case 0x1F :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
V_278 = V_286 ;
break;
case V_287 :
case V_288 :
case V_289 :
case V_290 :
V_278 = V_291 ;
break;
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
V_278 = V_304 ;
break;
case V_305 :
V_278 = V_306 ;
break;
case V_307 :
case V_308 :
V_278 = V_309 ;
break;
case V_310 :
V_278 = V_311 ;
break;
case V_312 :
case V_313 :
V_278 = V_314 ;
break;
case V_315 :
case V_316 :
V_278 = V_317 ;
break;
default:
return 0 ;
}
F_15 ( V_190 , V_201 , & V_29 ) ;
V_205 = V_278 [ V_29 & 0xF ] ;
F_15 ( V_190 , V_191 , & V_29 ) ;
V_277 = ( V_29 >> 8 ) & 0xFF ;
V_120 = V_277 * V_192 * 1000000 ;
V_119 = 1 ;
return 1 ;
}
int F_80 ( unsigned int V_275 , unsigned int V_276 )
{
switch ( V_276 ) {
case V_284 :
case V_285 :
case V_312 :
case V_313 :
return 0 ;
default:
return 1 ;
}
}
int F_81 ( unsigned int V_275 , unsigned int V_276 )
{
if ( ! V_279 )
return 0 ;
if ( V_275 != 6 )
return 0 ;
switch ( V_276 ) {
case V_290 :
case V_293 :
return 1 ;
default:
return 0 ;
}
}
int F_82 ( unsigned int V_275 , unsigned int V_276 )
{
if ( ! V_279 )
return 0 ;
if ( V_275 != 6 )
return 0 ;
switch ( V_276 ) {
case V_293 :
return 1 ;
default:
return 0 ;
}
}
int F_83 ( unsigned int V_275 , unsigned int V_276 )
{
if ( ! V_279 )
return 0 ;
if ( V_275 != 6 )
return 0 ;
switch ( V_276 ) {
case V_312 :
case V_313 :
return 1 ;
default:
return 0 ;
}
}
int F_84 ( unsigned int V_275 , unsigned int V_276 )
{
if ( ! V_279 )
return 0 ;
if ( V_275 != 6 )
return 0 ;
switch ( V_276 ) {
case V_289 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
case V_305 :
case V_312 :
case V_313 :
return 1 ;
default:
return 0 ;
}
}
static void
F_85 ( unsigned int V_275 , unsigned int V_276 )
{
if ( ! V_318 )
return;
F_37 () ;
if ( F_82 ( V_275 , V_276 ) )
F_38 () ;
if ( F_81 ( V_275 , V_276 ) )
F_39 () ;
if ( F_80 ( V_275 , V_276 ) )
F_40 () ;
if ( F_83 ( V_275 , V_276 ) )
F_41 () ;
if ( F_84 ( V_275 , V_276 ) )
F_45 () ;
F_42 () ;
}
int F_86 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
char * V_319 ;
int V_1 ;
if ( ! V_320 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_73 & V_109 ) || ! ( V_18 -> V_73 & V_111 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_131 , L_94 , V_1 ) ;
return - 1 ;
}
if ( F_15 ( V_1 , V_321 , & V_29 ) )
return 0 ;
switch ( V_29 & 0xF ) {
case V_322 :
V_319 = L_189 ;
break;
case V_323 :
V_319 = L_190 ;
break;
case V_324 :
V_319 = L_191 ;
break;
default:
V_319 = L_192 ;
break;
}
fprintf ( V_131 , L_193 , V_1 , V_29 , V_319 ) ;
return 0 ;
}
int F_87 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
int V_1 ;
if ( ! V_325 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_73 & V_109 ) || ! ( V_18 -> V_73 & V_111 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_131 , L_94 , V_1 ) ;
return - 1 ;
}
if ( F_15 ( V_1 , V_326 , & V_29 ) )
return 0 ;
fprintf ( V_131 , L_194 ,
V_1 , V_29 , ( V_29 & ( 1 << 0 ) ) ? L_127 : L_195 ) ;
if ( ( V_29 & ( 1 << 0 ) ) == 0 )
return 0 ;
if ( F_15 ( V_1 , V_327 , & V_29 ) )
return 0 ;
fprintf ( V_131 , L_196
L_197 ,
V_1 , V_29 ,
( unsigned int ) F_88 ( V_29 ) ,
( unsigned int ) F_89 ( V_29 ) ,
( unsigned int ) F_90 ( V_29 ) ,
( unsigned int ) F_91 ( V_29 ) ) ;
if ( F_15 ( V_1 , V_328 , & V_29 ) )
return 0 ;
fprintf ( V_131 , L_198
L_199 ,
V_1 , V_29 ,
( unsigned int ) ( ( ( V_29 ) >> 0 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 8 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 16 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 24 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 32 ) & 0xff3 ) ,
( unsigned int ) ( ( ( V_29 ) >> 42 ) & 0x1 ) ) ;
if ( V_329 ) {
if ( F_15 ( V_1 , V_330 , & V_29 ) )
return 0 ;
fprintf ( V_131 , L_200
L_201 ,
V_1 , V_29 ,
( unsigned int ) ( ( ( V_29 ) >> 0 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 8 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 16 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 24 ) & 0xff ) ,
( unsigned int ) ( ( ( V_29 ) >> 32 ) & 0xff3 ) ) ;
}
if ( V_331 ) {
if ( F_15 ( V_1 , V_332 , & V_29 ) )
return 0 ;
fprintf ( V_131 , L_202
L_203 ,
V_1 , V_29 ,
( ( V_29 ) & 0x1 ) ? L_100 : L_204 ,
( ( V_29 ) & 0x2 ) ? L_100 : L_204 ) ;
}
if ( F_15 ( V_1 , V_333 , & V_29 ) )
return 0 ;
fprintf ( V_131 , L_205
L_206 ,
V_1 , V_29 ,
( ( V_29 ) & 0x1 ) ? L_127 : L_195 ,
( ( V_29 ) & 0x2 ) ? L_127 : L_195 ) ;
return 0 ;
}
int F_92 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
int V_1 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_73 & V_109 ) || ! ( V_18 -> V_73 & V_111 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_131 , L_94 , V_1 ) ;
return - 1 ;
}
if ( V_334 ) {
F_15 ( V_1 , V_335 , & V_29 ) ;
fprintf ( V_131 , L_207 , V_1 , V_29 ) ;
fprintf ( V_131 , L_208 ,
( V_29 & 1 << 15 ) ? L_209 : L_127 ,
( V_29 & 1 << 14 ) ? L_210 : L_127 ,
( V_29 & 1 << 13 ) ? L_211 : L_127 ,
( V_29 & 1 << 12 ) ? L_212 : L_127 ,
( V_29 & 1 << 11 ) ? L_213 : L_127 ,
( V_29 & 1 << 10 ) ? L_214 : L_127 ,
( V_29 & 1 << 9 ) ? L_215 : L_127 ,
( V_29 & 1 << 8 ) ? L_216 : L_127 ,
( V_29 & 1 << 6 ) ? L_217 : L_127 ,
( V_29 & 1 << 5 ) ? L_218 : L_127 ,
( V_29 & 1 << 4 ) ? L_219 : L_127 ,
( V_29 & 1 << 2 ) ? L_220 : L_127 ,
( V_29 & 1 << 1 ) ? L_221 : L_127 ,
( V_29 & 1 << 0 ) ? L_222 : L_127 ) ;
fprintf ( V_131 , L_223 ,
( V_29 & 1 << 31 ) ? L_224 : L_127 ,
( V_29 & 1 << 30 ) ? L_225 : L_127 ,
( V_29 & 1 << 29 ) ? L_211 : L_127 ,
( V_29 & 1 << 28 ) ? L_212 : L_127 ,
( V_29 & 1 << 27 ) ? L_213 : L_127 ,
( V_29 & 1 << 26 ) ? L_214 : L_127 ,
( V_29 & 1 << 25 ) ? L_215 : L_127 ,
( V_29 & 1 << 24 ) ? L_216 : L_127 ,
( V_29 & 1 << 22 ) ? L_217 : L_127 ,
( V_29 & 1 << 21 ) ? L_218 : L_127 ,
( V_29 & 1 << 20 ) ? L_219 : L_127 ,
( V_29 & 1 << 18 ) ? L_226 : L_127 ,
( V_29 & 1 << 17 ) ? L_221 : L_127 ,
( V_29 & 1 << 16 ) ? L_222 : L_127 ) ;
}
if ( V_336 ) {
F_15 ( V_1 , V_337 , & V_29 ) ;
fprintf ( V_131 , L_227 , V_1 , V_29 ) ;
fprintf ( V_131 , L_228 ,
( V_29 & 1 << 0 ) ? L_222 : L_127 ,
( V_29 & 1 << 1 ) ? L_221 : L_127 ,
( V_29 & 1 << 4 ) ? L_219 : L_127 ,
( V_29 & 1 << 6 ) ? L_217 : L_127 ,
( V_29 & 1 << 8 ) ? L_216 : L_127 ,
( V_29 & 1 << 9 ) ? L_229 : L_127 ,
( V_29 & 1 << 10 ) ? L_214 : L_127 ,
( V_29 & 1 << 11 ) ? L_213 : L_127 ) ;
fprintf ( V_131 , L_230 ,
( V_29 & 1 << 16 ) ? L_222 : L_127 ,
( V_29 & 1 << 17 ) ? L_221 : L_127 ,
( V_29 & 1 << 20 ) ? L_219 : L_127 ,
( V_29 & 1 << 22 ) ? L_217 : L_127 ,
( V_29 & 1 << 24 ) ? L_216 : L_127 ,
( V_29 & 1 << 25 ) ? L_229 : L_127 ,
( V_29 & 1 << 26 ) ? L_214 : L_127 ,
( V_29 & 1 << 27 ) ? L_213 : L_127 ) ;
}
if ( V_338 ) {
F_15 ( V_1 , V_339 , & V_29 ) ;
fprintf ( V_131 , L_231 , V_1 , V_29 ) ;
fprintf ( V_131 , L_232 ,
( V_29 & 1 << 0 ) ? L_222 : L_127 ,
( V_29 & 1 << 1 ) ? L_221 : L_127 ,
( V_29 & 1 << 6 ) ? L_217 : L_127 ,
( V_29 & 1 << 8 ) ? L_216 : L_127 ,
( V_29 & 1 << 10 ) ? L_214 : L_127 ,
( V_29 & 1 << 11 ) ? L_213 : L_127 ) ;
fprintf ( V_131 , L_233 ,
( V_29 & 1 << 16 ) ? L_222 : L_127 ,
( V_29 & 1 << 17 ) ? L_221 : L_127 ,
( V_29 & 1 << 22 ) ? L_217 : L_127 ,
( V_29 & 1 << 24 ) ? L_216 : L_127 ,
( V_29 & 1 << 26 ) ? L_214 : L_127 ,
( V_29 & 1 << 27 ) ? L_213 : L_127 ) ;
}
return 0 ;
}
double F_93 ( unsigned int V_276 )
{
unsigned long long V_29 ;
if ( V_63 & V_340 )
if ( ! F_15 ( V_190 , V_341 , & V_29 ) )
return ( ( V_29 >> 0 ) & V_342 ) * V_343 ;
switch ( V_276 ) {
case V_307 :
case V_308 :
return 30.0 ;
default:
return 135.0 ;
}
}
static double
F_94 ( int V_276 , double V_126 )
{
switch ( V_276 ) {
case V_293 :
case V_298 :
case V_299 :
case V_312 :
case V_313 :
return ( V_127 = 15.3 / 1000000 ) ;
default:
return ( V_126 ) ;
}
}
void F_95 ( unsigned int V_275 , unsigned int V_276 )
{
unsigned long long V_29 ;
unsigned int V_344 ;
double V_345 ;
if ( ! V_279 )
return;
if ( V_275 != 6 )
return;
switch ( V_276 ) {
case V_287 :
case V_289 :
case V_292 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
V_63 = V_65 | V_129 | V_346 | V_67 | V_340 ;
break;
case V_315 :
V_63 = V_65 | V_340 ;
break;
case V_300 :
case V_301 :
case V_302 :
case V_303 :
V_63 = V_65 | V_68 | V_70 | V_69 | V_340 ;
break;
case V_293 :
case V_298 :
case V_299 :
case V_305 :
case V_312 :
case V_313 :
V_63 = V_65 | V_68 | V_347 | V_70 | V_69 | V_340 ;
break;
case V_288 :
case V_290 :
V_63 = V_65 | V_129 | V_346 | V_68 | V_347 | V_69 | V_70 | V_340 ;
break;
case V_307 :
case V_308 :
V_63 = V_65 | V_129 ;
break;
case V_316 :
V_63 = V_65 | V_68 | V_347 | V_70 | V_69 | V_340 | V_66 ;
break;
default:
return;
}
if ( F_15 ( V_190 , V_348 , & V_29 ) )
return;
V_343 = 1.0 / ( 1 << ( V_29 & 0xF ) ) ;
if ( V_276 == V_307 )
V_126 = 1.0 * ( 1 << ( V_29 >> 8 & 0x1F ) ) / 1000000 ;
else
V_126 = 1.0 / ( 1 << ( V_29 >> 8 & 0x1F ) ) ;
V_127 = F_94 ( V_276 , V_126 ) ;
V_344 = V_29 >> 16 & 0xF ;
if ( V_344 == 0 )
V_344 = 0xA ;
V_128 = 1.0 / ( 1 << ( V_344 ) ) ;
V_345 = F_93 ( V_276 ) ;
V_125 = 0xFFFFFFFF * V_126 / V_345 ;
if ( V_37 )
fprintf ( V_131 , L_234 , V_125 , V_345 ) ;
return;
}
void F_96 ( unsigned int V_275 , unsigned int V_276 )
{
if ( ! V_279 )
return;
if ( V_275 != 6 )
return;
switch ( V_276 ) {
case V_292 :
case V_294 :
case V_295 :
V_336 = 1 ;
case V_293 :
V_334 = 1 ;
V_338 = 1 ;
default:
return;
}
}
int F_97 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
unsigned int V_349 ;
int V_1 ;
if ( ! ( V_52 || V_54 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_73 & V_109 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_131 , L_94 , V_1 ) ;
return - 1 ;
}
if ( V_54 && ( V_18 -> V_73 & V_111 ) ) {
if ( F_15 ( V_1 , V_185 , & V_29 ) )
return 0 ;
V_349 = ( V_29 >> 16 ) & 0x7F ;
fprintf ( V_131 , L_235 ,
V_1 , V_29 , V_167 - V_349 ) ;
#ifdef F_98
if ( F_15 ( V_1 , V_350 , & V_29 ) )
return 0 ;
V_349 = ( V_29 >> 16 ) & 0x7F ;
V_351 = ( V_29 >> 8 ) & 0x7F ;
fprintf ( V_131 , L_236 ,
V_1 , V_29 , V_167 - V_349 , V_167 - V_351 ) ;
#endif
}
if ( V_52 ) {
unsigned int V_352 ;
if ( F_15 ( V_1 , V_166 , & V_29 ) )
return 0 ;
V_349 = ( V_29 >> 16 ) & 0x7F ;
V_352 = ( V_29 >> 27 ) & 0xF ;
fprintf ( V_131 , L_237 ,
V_1 , V_29 , V_167 - V_349 , V_352 ) ;
#ifdef F_98
if ( F_15 ( V_1 , V_353 , & V_29 ) )
return 0 ;
V_349 = ( V_29 >> 16 ) & 0x7F ;
V_351 = ( V_29 >> 8 ) & 0x7F ;
fprintf ( V_131 , L_238 ,
V_1 , V_29 , V_167 - V_349 , V_167 - V_351 ) ;
#endif
}
return 0 ;
}
void F_99 ( int V_1 , unsigned long long V_29 , char * V_354 )
{
fprintf ( V_131 , L_239 ,
V_1 , V_354 ,
( ( V_29 >> 15 ) & 1 ) ? L_100 : L_101 ,
( ( V_29 >> 0 ) & 0x7FFF ) * V_343 ,
( 1.0 + ( ( ( V_29 >> 22 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_29 >> 17 ) & 0x1F ) ) * V_128 ,
( ( ( V_29 >> 16 ) & 1 ) ? L_100 : L_101 ) ) ;
return;
}
int F_100 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
int V_1 ;
if ( ! V_63 )
return 0 ;
if ( ! ( V_18 -> V_73 & V_109 ) || ! ( V_18 -> V_73 & V_111 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_131 , L_94 , V_1 ) ;
return - 1 ;
}
if ( F_15 ( V_1 , V_348 , & V_29 ) )
return - 1 ;
if ( V_37 ) {
fprintf ( V_131 , L_240
L_241 , V_1 , V_29 ,
V_343 , V_126 , V_128 ) ;
}
if ( V_63 & V_340 ) {
if ( F_15 ( V_1 , V_341 , & V_29 ) )
return - 5 ;
fprintf ( V_131 , L_242 ,
V_1 , V_29 ,
( ( V_29 >> 0 ) & V_342 ) * V_343 ,
( ( V_29 >> 16 ) & V_342 ) * V_343 ,
( ( V_29 >> 32 ) & V_342 ) * V_343 ,
( ( V_29 >> 48 ) & V_355 ) * V_128 ) ;
}
if ( V_63 & V_65 ) {
if ( F_15 ( V_1 , V_356 , & V_29 ) )
return - 9 ;
fprintf ( V_131 , L_243 ,
V_1 , V_29 , ( V_29 >> 63 ) & 1 ? L_127 : L_131 ) ;
F_99 ( V_1 , V_29 , L_244 ) ;
fprintf ( V_131 , L_245 ,
V_1 ,
( ( V_29 >> 47 ) & 1 ) ? L_100 : L_101 ,
( ( V_29 >> 32 ) & 0x7FFF ) * V_343 ,
( 1.0 + ( ( ( V_29 >> 54 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_29 >> 49 ) & 0x1F ) ) * V_128 ,
( ( V_29 >> 48 ) & 1 ) ? L_100 : L_101 ) ;
}
if ( V_63 & V_347 ) {
if ( F_15 ( V_1 , V_357 , & V_29 ) )
return - 6 ;
fprintf ( V_131 , L_246 ,
V_1 , V_29 ,
( ( V_29 >> 0 ) & V_342 ) * V_343 ,
( ( V_29 >> 16 ) & V_342 ) * V_343 ,
( ( V_29 >> 32 ) & V_342 ) * V_343 ,
( ( V_29 >> 48 ) & V_355 ) * V_128 ) ;
}
if ( V_63 & V_68 ) {
if ( F_15 ( V_1 , V_358 , & V_29 ) )
return - 9 ;
fprintf ( V_131 , L_247 ,
V_1 , V_29 , ( V_29 >> 31 ) & 1 ? L_127 : L_131 ) ;
F_99 ( V_1 , V_29 , L_248 ) ;
}
if ( V_63 & V_346 ) {
if ( V_37 ) {
if ( F_15 ( V_1 , V_359 , & V_29 ) )
return - 7 ;
fprintf ( V_131 , L_249 , V_1 , V_29 & 0xF ) ;
}
}
if ( V_63 & V_360 ) {
if ( V_37 ) {
if ( F_15 ( V_1 , V_361 , & V_29 ) )
return - 9 ;
fprintf ( V_131 , L_250 ,
V_1 , V_29 , ( V_29 >> 31 ) & 1 ? L_127 : L_131 ) ;
F_99 ( V_1 , V_29 , L_251 ) ;
}
}
if ( V_63 & V_67 ) {
if ( V_37 ) {
if ( F_15 ( V_1 , V_362 , & V_29 ) )
return - 8 ;
fprintf ( V_131 , L_252 , V_1 , V_29 & 0xF ) ;
if ( F_15 ( V_1 , V_363 , & V_29 ) )
return - 9 ;
fprintf ( V_131 , L_253 ,
V_1 , V_29 , ( V_29 >> 31 ) & 1 ? L_127 : L_131 ) ;
F_99 ( V_1 , V_29 , L_254 ) ;
}
}
return 0 ;
}
int F_101 ( unsigned int V_275 , unsigned int V_276 )
{
if ( ! V_279 )
return 0 ;
switch ( V_276 ) {
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
case V_305 :
case V_315 :
case V_316 :
return 1 ;
}
return 0 ;
}
int F_102 ( unsigned int V_275 , unsigned int V_276 )
{
if ( ! V_279 )
return 0 ;
switch ( V_276 ) {
case V_294 :
case V_296 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
case V_315 :
return 1 ;
}
return 0 ;
}
int F_103 ( unsigned int V_275 , unsigned int V_276 )
{
if ( ! V_279 )
return 0 ;
switch ( V_276 ) {
case V_300 :
case V_301 :
case V_302 :
case V_303 :
return 1 ;
}
return 0 ;
}
int F_104 ( unsigned int V_275 , unsigned int V_276 )
{
if ( ! V_279 )
return 0 ;
switch ( V_276 ) {
case V_307 :
case V_308 :
return 1 ;
}
return 0 ;
}
int F_105 ( unsigned int V_275 , unsigned int V_276 )
{
if ( ! V_279 )
return 0 ;
switch ( V_276 ) {
case V_312 :
case V_313 :
return 1 ;
}
return 0 ;
}
unsigned int F_106 ( unsigned int V_275 , unsigned int V_276 )
{
if ( F_105 ( V_275 , V_276 ) )
return 1024 ;
return 1 ;
}
double F_107 ( void )
{
unsigned long long V_29 = 3 ;
unsigned int V_72 ;
double V_364 ;
if ( F_15 ( V_190 , V_365 , & V_29 ) )
fprintf ( V_131 , L_255 ) ;
V_72 = V_29 & 0xf ;
if ( V_72 >= V_366 ) {
fprintf ( V_131 , L_256 , V_72 ) ;
V_72 = 3 ;
}
V_364 = V_367 [ V_72 ] ;
fprintf ( V_131 , L_257 , V_364 ) ;
return V_364 ;
}
double F_79 ( unsigned int V_275 , unsigned int V_276 )
{
if ( F_101 ( V_275 , V_276 ) || F_105 ( V_275 , V_276 ) )
return 100.00 ;
else if ( F_104 ( V_275 , V_276 ) )
return F_107 () ;
else
return 133.33 ;
}
int F_108 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_29 ;
unsigned int V_368 ;
int V_1 ;
if ( ! ( V_52 || V_54 ) )
return 0 ;
if ( ! ( V_18 -> V_73 & V_109 ) || ! ( V_18 -> V_73 & V_111 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_131 , L_94 , V_1 ) ;
return - 1 ;
}
if ( V_369 != 0 ) {
V_167 = V_369 ;
fprintf ( V_131 , L_258 ,
V_1 , V_167 ) ;
return 0 ;
}
if ( ! V_318 )
goto V_370;
if ( F_15 ( V_190 , V_371 , & V_29 ) )
goto V_370;
V_368 = ( V_29 >> 16 ) & 0xFF ;
if ( V_37 )
fprintf ( V_131 , L_259 ,
V_1 , V_29 , V_368 ) ;
if ( ! V_368 )
goto V_370;
V_167 = V_368 ;
return 0 ;
V_370:
V_167 = V_372 ;
fprintf ( V_131 , L_260 ,
V_1 , V_167 ) ;
return 0 ;
}
void F_109 ( void )
{
unsigned long long V_29 ;
if ( ! F_15 ( V_190 , V_373 , & V_29 ) )
fprintf ( V_131 , L_261 ,
V_190 , V_29 ,
V_29 & V_374 ? L_127 : L_262 ,
V_29 & ( 1 << 18 ) ? L_263 : L_127 ) ;
}
void F_110 ( void )
{
unsigned long long V_29 ;
if ( ! F_15 ( V_190 , V_375 , & V_29 ) )
fprintf ( V_131 , L_264 ,
V_190 , V_29 ,
V_29 & ( 1 << 3 ) ? L_265 : L_127 ,
V_29 & ( 1 << 16 ) ? L_266 : L_127 ,
V_29 & ( 1 << 18 ) ? L_267 : L_127 ) ;
}
void F_111 ( void )
{
unsigned long long V_29 ;
if ( ! V_318 )
return;
if ( ! F_15 ( V_190 , V_376 , & V_29 ) )
fprintf ( V_131 , L_268 ,
V_190 , V_29 ,
V_29 & ( 1 << 0 ) ? L_101 : L_100 ,
V_29 & ( 1 << 1 ) ? L_100 : L_101 ,
V_29 & ( 1 << 8 ) ? L_100 : L_101 ) ;
}
void F_112 ()
{
unsigned int V_377 , V_378 , V_379 , V_380 , V_381 , V_382 ;
unsigned int V_383 , V_275 , V_276 , V_384 ;
V_377 = V_378 = V_379 = V_380 = 0 ;
F_113 ( 0 , V_381 , V_378 , V_379 , V_380 ) ;
if ( V_378 == 0x756e6547 && V_380 == 0x49656e69 && V_379 == 0x6c65746e )
V_279 = 1 ;
if ( V_37 )
fprintf ( V_131 , L_269 ,
( char * ) & V_378 , ( char * ) & V_380 , ( char * ) & V_379 ) ;
F_113 ( 1 , V_383 , V_378 , V_379 , V_380 ) ;
V_275 = ( V_383 >> 8 ) & 0xf ;
V_276 = ( V_383 >> 4 ) & 0xf ;
V_384 = V_383 & 0xf ;
if ( V_275 == 6 || V_275 == 0xf )
V_276 += ( ( V_383 >> 16 ) & 0xf ) << 4 ;
if ( V_37 ) {
fprintf ( V_131 , L_270 ,
V_381 , V_275 , V_276 , V_384 , V_275 , V_276 , V_384 ) ;
fprintf ( V_131 , L_271 ,
V_379 & ( 1 << 0 ) ? L_272 : L_273 ,
V_379 & ( 1 << 3 ) ? L_267 : L_273 ,
V_379 & ( 1 << 6 ) ? L_274 : L_273 ,
V_379 & ( 1 << 7 ) ? L_266 : L_273 ,
V_379 & ( 1 << 8 ) ? L_275 : L_273 ,
V_380 & ( 1 << 4 ) ? L_276 : L_273 ,
V_380 & ( 1 << 5 ) ? L_277 : L_273 ,
V_380 & ( 1 << 22 ) ? L_278 : L_273 ,
V_380 & ( 1 << 29 ) ? L_279 : L_273 ) ;
}
if ( ! ( V_380 & ( 1 << 5 ) ) )
F_27 ( 1 , L_280 ) ;
V_378 = V_379 = V_380 = 0 ;
F_113 ( 0x80000000 , V_382 , V_378 , V_379 , V_380 ) ;
if ( V_382 >= 0x80000007 ) {
F_113 ( 0x80000007 , V_377 , V_378 , V_379 , V_380 ) ;
V_385 = V_380 & ( 1 << 8 ) ;
}
F_113 ( 0x6 , V_377 , V_378 , V_379 , V_380 ) ;
V_36 = V_379 & ( 1 << 0 ) ;
V_52 = V_377 & ( 1 << 0 ) ;
V_54 = V_377 & ( 1 << 6 ) ;
V_325 = V_377 & ( 1 << 7 ) ;
V_331 = V_377 & ( 1 << 8 ) ;
V_386 = V_377 & ( 1 << 9 ) ;
V_387 = V_377 & ( 1 << 10 ) ;
V_329 = V_377 & ( 1 << 11 ) ;
V_320 = V_379 & ( 1 << 3 ) ;
if ( V_37 )
fprintf ( V_131 , L_281
L_282 ,
V_36 ? L_127 : L_195 ,
V_52 ? L_127 : L_195 ,
V_54 ? L_127 : L_195 ,
V_325 ? L_127 : L_195 ,
V_331 ? L_127 : L_195 ,
V_386 ? L_127 : L_195 ,
V_387 ? L_127 : L_195 ,
V_329 ? L_127 : L_195 ,
V_320 ? L_127 : L_195 ) ;
if ( V_37 )
F_110 () ;
if ( V_381 >= 0x7 && V_37 ) {
int V_388 ;
V_379 = 0 ;
F_114 ( 0x7 , 0 , V_377 , V_378 , V_379 , V_380 ) ;
V_388 = V_378 & ( 1 << 2 ) ;
fprintf ( V_131 , L_283 , V_388 ? L_127 : L_195 ) ;
if ( V_388 )
F_109 () ;
}
if ( V_381 >= 0x15 ) {
unsigned int V_389 ;
unsigned int V_390 ;
V_389 = V_390 = V_391 = V_380 = 0 ;
F_113 ( 0x15 , V_389 , V_390 , V_391 , V_380 ) ;
if ( V_390 != 0 ) {
if ( V_37 && ( V_378 != 0 ) )
fprintf ( V_131 , L_284 ,
V_389 , V_390 , V_391 ) ;
if ( V_391 == 0 )
switch( V_276 ) {
case V_300 :
case V_301 :
case V_302 :
case V_303 :
V_391 = 24000000 ;
break;
case V_305 :
case V_316 :
V_391 = 25000000 ;
break;
case V_315 :
V_391 = 19200000 ;
break;
default:
V_391 = 0 ;
}
if ( V_391 ) {
V_188 = ( unsigned long long ) V_391 * V_390 / V_389 ;
if ( V_37 )
fprintf ( V_131 , L_285 ,
V_188 / 1000000 , V_391 , V_390 , V_389 ) ;
}
}
}
if ( V_381 >= 0x16 ) {
unsigned int V_392 , V_393 , V_394 , V_380 ;
V_392 = V_393 = V_394 = V_380 = 0 ;
F_113 ( 0x16 , V_392 , V_393 , V_394 , V_380 ) ;
if ( V_37 )
fprintf ( V_131 , L_286 ,
V_392 , V_393 , V_394 ) ;
}
if ( V_36 )
V_158 = F_106 ( V_275 , V_276 ) ;
V_318 = V_41 = V_40 = F_78 ( V_275 , V_276 ) ;
V_44 = F_101 ( V_275 , V_276 ) ;
V_395 = F_101 ( V_275 , V_276 ) ;
V_58 = V_44 && ( V_205 >= V_396 ) ;
V_59 = ( V_205 >= V_397 ) ;
V_60 = ( V_205 >= V_398 ) ;
V_61 = V_44 && ( V_205 >= V_399 ) ;
V_62 = F_102 ( V_275 , V_276 ) ;
V_215 = F_102 ( V_275 , V_276 ) ;
V_57 = F_103 ( V_275 , V_276 ) ;
V_42 = F_104 ( V_275 , V_276 ) ;
V_43 = F_105 ( V_275 , V_276 ) ;
if ( V_37 )
F_111 () ;
F_95 ( V_275 , V_276 ) ;
F_96 ( V_275 , V_276 ) ;
if ( V_37 )
F_85 ( V_275 , V_276 ) ;
if ( F_103 ( V_275 , V_276 ) )
F_36 () ;
V_55 = ! F_115 ( L_177 , V_274 ) ;
V_56 = ! F_115 ( L_180 , V_274 ) ;
return;
}
void F_116 ()
{
fprintf ( V_131 ,
L_287
L_45
L_288
L_289
L_290
L_291
L_292
L_293
L_294
L_295
L_296
L_297
L_298
L_45
L_299 ) ;
}
int F_117 ( const struct V_400 * V_401 )
{
if ( isdigit ( V_401 -> V_402 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_118 ( int V_403 )
{
return 0 ;
}
void F_119 ()
{
int V_72 ;
int V_404 = 0 ;
int V_405 = 0 ;
int V_406 = 0 ;
struct V_407 {
int V_82 ;
int V_408 ;
} * V_409 ;
V_14 . V_136 = 0 ;
V_14 . V_219 = 0 ;
F_59 ( F_62 ) ;
if ( ! V_135 && V_14 . V_136 > 1 )
V_35 = 1 ;
if ( V_37 > 1 )
fprintf ( V_131 , L_300 , V_14 . V_136 , V_14 . V_219 ) ;
V_409 = calloc ( 1 , ( V_14 . V_219 + 1 ) * sizeof( struct V_407 ) ) ;
if ( V_409 == NULL )
F_14 ( 1 , L_301 ) ;
V_3 = F_120 ( ( V_14 . V_219 + 1 ) ) ;
if ( V_3 == NULL )
F_14 ( 3 , L_302 ) ;
V_2 = F_121 ( ( V_14 . V_219 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_59 ( F_63 ) ;
V_23 = F_120 ( ( V_14 . V_219 + 1 ) ) ;
if ( V_23 == NULL )
F_14 ( 3 , L_302 ) ;
V_22 = F_121 ( ( V_14 . V_219 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_72 = 0 ; V_72 <= V_14 . V_219 ; ++ V_72 ) {
int V_410 ;
if ( F_1 ( V_72 ) ) {
if ( V_37 > 1 )
fprintf ( V_131 , L_303 , V_72 ) ;
continue;
}
V_409 [ V_72 ] . V_82 = F_56 ( V_72 ) ;
if ( V_409 [ V_72 ] . V_82 > V_404 )
V_404 = V_409 [ V_72 ] . V_82 ;
V_409 [ V_72 ] . V_408 = F_55 ( V_72 ) ;
if ( V_409 [ V_72 ] . V_408 > V_405 )
V_405 = V_409 [ V_72 ] . V_408 ;
V_410 = F_57 ( V_72 ) ;
if ( V_410 > V_406 )
V_406 = V_410 ;
if ( V_37 > 1 )
fprintf ( V_131 , L_304 ,
V_72 , V_409 [ V_72 ] . V_408 , V_409 [ V_72 ] . V_82 ) ;
}
V_14 . V_16 = V_404 + 1 ;
if ( V_37 > 1 )
fprintf ( V_131 , L_305 ,
V_404 , V_14 . V_16 ) ;
if ( V_37 && ! V_135 && V_14 . V_16 > 1 )
V_34 = 1 ;
V_14 . V_15 = V_405 + 1 ;
if ( V_37 > 1 )
fprintf ( V_131 , L_306 ,
V_405 , V_14 . V_15 ) ;
if ( V_37 && ! V_135 && V_14 . V_15 > 1 )
V_32 = 1 ;
V_14 . V_17 = V_406 ;
if ( V_37 > 1 )
fprintf ( V_131 , L_307 , V_406 ) ;
free ( V_409 ) ;
}
void
F_122 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_72 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) + V_45 . V_411 ) ;
if ( * V_18 == NULL )
goto error;
for ( V_72 = 0 ; V_72 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_72 ++ )
( * V_18 ) [ V_72 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) + V_45 . V_412 ) ;
if ( * V_19 == NULL )
goto error;
for ( V_72 = 0 ; V_72 < V_14 . V_16 * V_14 . V_15 ; V_72 ++ )
( * V_19 ) [ V_72 ] . V_82 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) + V_45 . V_413 ) ;
if ( * V_20 == NULL )
goto error;
for ( V_72 = 0 ; V_72 < V_14 . V_15 ; V_72 ++ )
( * V_20 ) [ V_72 ] . V_87 = V_72 ;
return;
error:
F_14 ( 1 , L_308 ) ;
}
void F_123 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_414 , int V_415 ,
int V_416 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_414 , V_415 , V_416 ) ;
V_19 = F_6 ( V_8 , V_415 , V_416 ) ;
V_20 = F_7 ( V_9 , V_416 ) ;
V_18 -> V_21 = V_21 ;
if ( V_414 == 0 ) {
V_18 -> V_73 |= V_109 ;
if ( F_54 ( V_21 ) )
V_18 -> V_73 |= V_111 ;
}
V_19 -> V_82 = V_415 ;
V_20 -> V_87 = V_416 ;
}
int F_124 ( int V_21 )
{
int V_417 , V_418 , V_419 ;
V_419 = F_55 ( V_21 ) ;
V_418 = F_56 ( V_21 ) ;
V_417 = F_53 ( V_21 ) ;
if ( ! V_417 )
V_14 . V_146 ++ ;
F_123 ( V_250 , V_417 , V_418 , V_419 , V_21 ) ;
F_123 ( V_254 , V_417 , V_418 , V_419 , V_21 ) ;
return 0 ;
}
void F_125 ()
{
V_133 = calloc ( 1 , ( 1 + V_14 . V_136 ) * 1024 ) ;
V_33 = V_133 ;
if ( V_33 == NULL )
F_14 ( - 1 , L_309 ) ;
}
void F_126 ( void )
{
V_26 = calloc ( V_14 . V_219 + 1 , sizeof( int ) ) ;
if ( V_26 == NULL )
F_14 ( - 1 , L_310 ) ;
}
void F_127 ( void )
{
V_226 = calloc ( V_14 . V_136 , sizeof( int ) ) ;
if ( V_226 == NULL )
F_14 ( - 1 , L_311 , V_14 . V_136 ) ;
V_159 = calloc ( V_14 . V_219 + 1 , sizeof( int ) ) ;
if ( V_159 == NULL )
F_14 ( - 1 , L_311 , V_14 . V_219 + 1 ) ;
}
void F_61 ( void )
{
F_119 () ;
F_127 () ;
F_126 () ;
F_122 ( & V_220 , & V_221 , & V_222 ) ;
F_122 ( & V_223 , & V_224 , & V_225 ) ;
F_125 () ;
F_59 ( F_124 ) ;
}
void F_128 ( void )
{
V_190 = F_129 () ;
if ( V_190 < 0 )
F_14 ( - V_420 , L_312 ) ;
if ( V_37 > 1 )
fprintf ( V_131 , L_313 , V_190 ) ;
}
void F_130 ()
{
F_61 () ;
F_128 () ;
F_73 () ;
F_74 () ;
F_112 () ;
if ( V_37 )
F_3 ( F_87 , V_254 ) ;
if ( V_37 )
F_3 ( F_86 , V_254 ) ;
if ( V_37 )
F_3 ( F_92 , V_254 ) ;
if ( V_37 )
F_3 ( F_100 , V_254 ) ;
F_3 ( F_108 , V_254 ) ;
if ( V_37 )
F_3 ( F_97 , V_254 ) ;
if ( V_37 && V_395 )
F_46 () ;
}
int F_131 ( char * * V_421 )
{
T_7 V_422 ;
int V_423 ;
V_423 = F_3 ( F_34 , V_250 ) ;
if ( V_423 )
exit ( V_423 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_70 ( & V_251 , (struct V_252 * ) NULL ) ;
V_422 = F_132 () ;
if ( ! V_422 ) {
F_133 ( V_421 [ 0 ] , V_421 ) ;
} else {
if ( V_422 == - 1 )
F_14 ( 1 , L_314 ) ;
signal ( V_424 , V_425 ) ;
signal ( V_426 , V_425 ) ;
if ( F_134 ( V_422 , & V_423 , 0 ) == - 1 )
F_14 ( V_423 , L_315 ) ;
}
F_3 ( F_34 , V_254 ) ;
F_70 ( & V_255 , (struct V_252 * ) NULL ) ;
F_72 ( & V_255 , & V_251 , & V_112 ) ;
if ( F_58 ( F_28 , V_254 , V_250 ) )
fprintf ( V_131 , L_316 , V_273 ) ;
else {
F_32 ( V_250 ) ;
F_22 ( V_250 ) ;
}
fprintf ( V_131 , L_317 , V_112 . V_113 + V_112 . V_114 / 1000000.0 ) ;
F_21 () ;
return V_423 ;
}
int F_135 ( void )
{
int V_423 ;
V_423 = F_3 ( F_34 , V_254 ) ;
if ( V_423 )
return V_423 ;
V_423 = F_3 ( F_18 , V_254 ) ;
if ( V_423 )
return V_423 ;
F_20 () ;
return V_423 ;
}
void F_136 () {
fprintf ( V_131 , L_318
L_319 ) ;
}
int F_137 ( unsigned int V_80 , char * V_51 , unsigned int V_50 ,
enum V_427 V_428 , enum V_429 type ,
enum V_430 V_48 )
{
struct V_30 * V_431 ;
V_431 = calloc ( 1 , sizeof( struct V_30 ) ) ;
if ( V_431 == NULL ) {
perror ( L_320 ) ;
exit ( 1 ) ;
}
V_431 -> V_80 = V_80 ;
strncpy ( V_431 -> V_51 , V_51 , V_432 ) ;
V_431 -> V_50 = V_50 ;
V_431 -> type = type ;
V_431 -> V_48 = V_48 ;
switch ( V_428 ) {
case V_433 :
V_45 . V_411 += 64 ;
V_431 -> V_47 = V_45 . V_46 ;
V_45 . V_46 = V_431 ;
V_45 . V_411 += sizeof( unsigned long long ) ;
break;
case V_434 :
V_45 . V_412 += 64 ;
V_431 -> V_47 = V_45 . V_53 ;
V_45 . V_53 = V_431 ;
V_45 . V_412 += sizeof( unsigned long long ) ;
break;
case V_435 :
V_45 . V_413 += 64 ;
V_431 -> V_47 = V_45 . V_71 ;
V_45 . V_71 = V_431 ;
V_45 . V_413 += sizeof( unsigned long long ) ;
break;
}
return 0 ;
}
void F_138 ( char * V_436 )
{
int V_80 = 0 ;
char V_437 [ V_432 ] ;
int V_50 = 64 ;
int V_438 = 0 ;
enum V_427 V_428 = V_433 ;
enum V_429 type = V_439 ;
enum V_430 V_48 = V_121 ;
while ( V_436 ) {
if ( sscanf ( V_436 , L_321 , & V_80 ) == 1 )
goto V_47;
if ( sscanf ( V_436 , L_322 , & V_80 ) == 1 )
goto V_47;
if ( sscanf ( V_436 , L_323 , & V_50 ) == 1 ) {
if ( ( V_50 == 32 ) || ( V_50 == 64 ) )
goto V_47;
V_50 = 64 ;
}
if ( ! strncmp ( V_436 , L_324 , strlen ( L_324 ) ) ) {
V_428 = V_433 ;
goto V_47;
}
if ( ! strncmp ( V_436 , L_325 , strlen ( L_325 ) ) ) {
V_428 = V_434 ;
goto V_47;
}
if ( ! strncmp ( V_436 , L_326 , strlen ( L_326 ) ) ) {
V_428 = V_435 ;
goto V_47;
}
if ( ! strncmp ( V_436 , L_327 , strlen ( L_327 ) ) ) {
type = V_439 ;
goto V_47;
}
if ( ! strncmp ( V_436 , L_328 , strlen ( L_328 ) ) ) {
type = V_440 ;
goto V_47;
}
if ( ! strncmp ( V_436 , L_329 , strlen ( L_329 ) ) ) {
V_48 = V_49 ;
goto V_47;
}
if ( ! strncmp ( V_436 , L_330 , strlen ( L_330 ) ) ) {
V_48 = V_121 ;
goto V_47;
}
if ( ! strncmp ( V_436 , L_331 , strlen ( L_331 ) ) ) {
V_48 = V_122 ;
goto V_47;
}
if ( sscanf ( V_436 , L_332 , V_437 ) == 1 ) {
char * V_441 ;
V_441 = strchr ( V_437 , ',' ) ;
if ( V_441 )
* V_441 = '\0' ;
goto V_47;
}
V_47:
V_436 = strchr ( V_436 , ',' ) ;
if ( V_436 )
V_436 ++ ;
}
if ( V_80 == 0 ) {
fprintf ( V_132 , L_333 ) ;
V_438 ++ ;
}
if ( * V_437 == '\0' ) {
if ( V_48 == V_49 ) {
if ( V_50 == 32 )
sprintf ( V_437 , L_322 , V_80 ) ;
else
sprintf ( V_437 , L_334 , V_80 ) ;
} else if ( V_48 == V_121 ) {
if ( V_50 == 32 )
sprintf ( V_437 , L_335 , V_80 ) ;
else
sprintf ( V_437 , L_336 , V_80 ) ;
} else if ( V_48 == V_122 ) {
if ( V_50 == 32 )
sprintf ( V_437 , L_337 , V_80 ) ;
else
sprintf ( V_437 , L_338 , V_80 ) ;
}
}
if ( F_137 ( V_80 , V_437 , V_50 , V_428 , type , V_48 ) )
V_438 ++ ;
if ( V_438 ) {
F_116 () ;
exit ( 1 ) ;
}
}
void F_139 ( int V_442 , char * * V_421 )
{
int V_443 ;
int V_444 = 0 ;
static struct V_445 V_446 [] = {
{ L_339 , V_447 , 0 , 'a' } ,
{ L_340 , V_448 , 0 , 'D' } ,
{ L_341 , V_448 , 0 , 'd' } ,
{ L_342 , V_447 , 0 , 'i' } ,
{ L_343 , V_448 , 0 , 'h' } ,
{ L_344 , V_448 , 0 , 'J' } ,
{ L_345 , V_447 , 0 , 'o' } ,
{ L_346 , V_448 , 0 , 'p' } ,
{ L_347 , V_448 , 0 , 'p' } ,
{ L_348 , V_448 , 0 , 'S' } ,
{ L_265 , V_447 , 0 , 'T' } ,
{ L_349 , V_448 , 0 , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
V_273 = V_421 [ 0 ] ;
while ( ( V_443 = F_140 ( V_442 , V_421 , L_350 ,
V_446 , & V_444 ) ) != - 1 ) {
switch ( V_443 ) {
case 'a' :
F_138 ( V_449 ) ;
break;
case 'D' :
V_450 ++ ;
break;
case 'd' :
V_37 ++ ;
break;
case 'h' :
default:
F_116 () ;
exit ( 1 ) ;
case 'i' :
{
double V_451 = strtod ( V_449 , NULL ) ;
if ( V_451 < 0.001 ) {
fprintf ( V_131 , L_351 ,
V_451 ) ;
exit ( 2 ) ;
}
V_253 . V_113 = V_451 ;
V_253 . V_452 = ( V_451 - V_253 . V_113 ) * 1000000000 ;
}
break;
case 'J' :
V_64 ++ ;
break;
case 'o' :
V_131 = F_51 ( V_449 , L_352 ) ;
break;
case 'P' :
V_110 ++ ;
break;
case 'p' :
V_108 ++ ;
break;
case 'S' :
V_135 ++ ;
break;
case 'T' :
V_369 = atoi ( V_449 ) ;
break;
case 'v' :
F_136 () ;
exit ( 0 ) ;
break;
}
}
}
int main ( int V_442 , char * * V_421 )
{
V_131 = V_132 ;
F_139 ( V_442 , V_421 ) ;
if ( V_37 )
F_136 () ;
F_130 () ;
if ( V_450 )
return F_135 () ;
if ( V_442 - V_453 )
return F_131 ( V_421 + V_453 ) ;
else
F_69 () ;
return 0 ;
}
