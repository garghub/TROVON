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
int F_12 ( int V_1 , T_1 V_24 , unsigned long long * V_25 )
{
T_2 V_10 ;
char V_26 [ 32 ] ;
int V_27 ;
sprintf ( V_26 , L_1 , V_1 ) ;
V_27 = F_13 ( V_26 , V_28 ) ;
if ( V_27 < 0 )
F_14 ( - 1 , L_2 , V_26 ) ;
V_10 = F_15 ( V_27 , V_25 , sizeof *V_25 , V_24 ) ;
F_16 ( V_27 ) ;
if ( V_10 != sizeof *V_25 )
F_14 ( - 1 , L_3 , V_26 , ( unsigned long long ) V_24 ) ;
return 0 ;
}
void F_17 ( void )
{
if ( V_29 )
V_30 += sprintf ( V_30 , L_4 ) ;
if ( V_31 )
V_30 += sprintf ( V_30 , L_5 ) ;
if ( V_32 )
V_30 += sprintf ( V_30 , L_6 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_7 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_8 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_9 ) ;
V_30 += sprintf ( V_30 , L_10 ) ;
if ( V_34 )
V_30 += sprintf ( V_30 , L_11 , V_34 ) ;
if ( V_35 )
V_30 += sprintf ( V_30 , L_12 , V_35 ) ;
if ( V_36 )
V_30 += sprintf ( V_30 , L_13 , V_36 ) ;
if ( V_37 )
V_30 += sprintf ( V_30 , L_14 , V_37 ) ;
if ( ! V_38 )
goto V_39;
if ( V_40 )
V_30 += sprintf ( V_30 , L_15 ) ;
if ( V_41 )
V_30 += sprintf ( V_30 , L_16 ) ;
if ( V_41 && ! V_42 && ! V_43 )
V_30 += sprintf ( V_30 , L_17 ) ;
if ( V_41 )
V_30 += sprintf ( V_30 , L_18 ) ;
if ( V_44 )
V_30 += sprintf ( V_30 , L_19 ) ;
if ( V_45 )
V_30 += sprintf ( V_30 , L_20 ) ;
if ( V_46 )
V_30 += sprintf ( V_30 , L_21 ) ;
if ( V_47 ) {
V_30 += sprintf ( V_30 , L_22 ) ;
V_30 += sprintf ( V_30 , L_23 ) ;
V_30 += sprintf ( V_30 , L_24 ) ;
V_30 += sprintf ( V_30 , L_25 ) ;
}
if ( V_48 )
V_30 += sprintf ( V_30 , L_26 ) ;
if ( V_49 )
V_30 += sprintf ( V_30 , L_27 ) ;
if ( V_50 )
V_30 += sprintf ( V_30 , L_28 ) ;
if ( V_51 )
V_30 += sprintf ( V_30 , L_29 ) ;
if ( V_52 ) {
V_30 += sprintf ( V_30 , L_30 ) ;
V_30 += sprintf ( V_30 , L_31 ) ;
V_30 += sprintf ( V_30 , L_32 ) ;
}
if ( V_53 && ! V_54 ) {
if ( V_53 & V_55 )
V_30 += sprintf ( V_30 , L_33 ) ;
if ( V_53 & V_56 )
V_30 += sprintf ( V_30 , L_34 ) ;
if ( V_53 & V_57 )
V_30 += sprintf ( V_30 , L_35 ) ;
if ( V_53 & V_58 )
V_30 += sprintf ( V_30 , L_36 ) ;
if ( V_53 & V_59 )
V_30 += sprintf ( V_30 , L_37 ) ;
if ( V_53 & V_60 )
V_30 += sprintf ( V_30 , L_38 ) ;
} else if ( V_53 && V_54 ) {
if ( V_53 & V_55 )
V_30 += sprintf ( V_30 , L_39 ) ;
if ( V_53 & V_56 )
V_30 += sprintf ( V_30 , L_40 ) ;
if ( V_53 & V_57 )
V_30 += sprintf ( V_30 , L_41 ) ;
if ( V_53 & V_58 )
V_30 += sprintf ( V_30 , L_42 ) ;
if ( V_53 & V_59 )
V_30 += sprintf ( V_30 , L_37 ) ;
if ( V_53 & V_60 )
V_30 += sprintf ( V_30 , L_38 ) ;
V_30 += sprintf ( V_30 , L_43 ) ;
}
V_39:
V_30 += sprintf ( V_30 , L_44 ) ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_30 += sprintf ( V_30 , L_45 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
V_30 += sprintf ( V_30 , L_46 ,
V_18 -> V_21 , V_18 -> V_61 ) ;
V_30 += sprintf ( V_30 , L_47 , V_18 -> V_62 ) ;
V_30 += sprintf ( V_30 , L_48 , V_18 -> V_63 ) ;
V_30 += sprintf ( V_30 , L_49 , V_18 -> V_64 ) ;
V_30 += sprintf ( V_30 , L_50 , V_18 -> V_65 ) ;
V_30 += sprintf ( V_30 , L_51 ,
V_34 , V_18 -> V_66 ) ;
V_30 += sprintf ( V_30 , L_52 ,
V_35 , V_18 -> V_67 ) ;
V_30 += sprintf ( V_30 , L_51 ,
V_36 , V_18 -> V_68 ) ;
V_30 += sprintf ( V_30 , L_52 ,
V_37 , V_18 -> V_69 ) ;
if ( V_40 )
V_30 += sprintf ( V_30 , L_53 , V_18 -> V_70 ) ;
}
if ( V_19 ) {
V_30 += sprintf ( V_30 , L_54 , V_19 -> V_71 ) ;
V_30 += sprintf ( V_30 , L_55 , V_19 -> V_72 ) ;
V_30 += sprintf ( V_30 , L_56 , V_19 -> V_73 ) ;
V_30 += sprintf ( V_30 , L_57 , V_19 -> V_74 ) ;
V_30 += sprintf ( V_30 , L_58 , V_19 -> V_75 ) ;
}
if ( V_20 ) {
V_30 += sprintf ( V_30 , L_59 , V_20 -> V_76 ) ;
V_30 += sprintf ( V_30 , L_60 , V_20 -> V_77 ) ;
V_30 += sprintf ( V_30 , L_61 , V_20 -> V_78 ) ;
V_30 += sprintf ( V_30 , L_62 , V_20 -> V_79 ) ;
V_30 += sprintf ( V_30 , L_63 , V_20 -> V_80 ) ;
V_30 += sprintf ( V_30 , L_64 , V_20 -> V_81 ) ;
if ( V_49 )
V_30 += sprintf ( V_30 , L_65 , V_20 -> V_82 ) ;
if ( V_50 )
V_30 += sprintf ( V_30 , L_66 , V_20 -> V_83 ) ;
if ( V_51 )
V_30 += sprintf ( V_30 , L_67 , V_20 -> V_84 ) ;
V_30 += sprintf ( V_30 , L_68 , V_20 -> V_85 ) ;
V_30 += sprintf ( V_30 , L_69 , V_20 -> V_86 ) ;
V_30 += sprintf ( V_30 , L_70 , V_20 -> V_87 ) ;
V_30 += sprintf ( V_30 , L_71 , V_20 -> V_88 ) ;
V_30 += sprintf ( V_30 , L_72 , V_20 -> V_89 ) ;
V_30 += sprintf ( V_30 , L_73 , V_20 -> V_90 ) ;
V_30 += sprintf ( V_30 , L_74 , V_20 -> V_91 ) ;
V_30 += sprintf ( V_30 , L_75 ,
V_20 -> V_92 ) ;
V_30 += sprintf ( V_30 , L_76 ,
V_20 -> V_93 ) ;
V_30 += sprintf ( V_30 , L_77 , V_20 -> V_94 ) ;
}
V_30 += sprintf ( V_30 , L_44 ) ;
return 0 ;
}
int F_19 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_95 ;
char * V_96 ;
if ( V_97 && ! ( V_18 -> V_61 & V_98 ) )
return 0 ;
if ( V_99 && ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
V_95 = V_101 . V_102 + V_101 . V_103 / 1000000.0 ;
if ( V_18 == & V_104 . V_105 ) {
if ( V_29 )
V_30 += sprintf ( V_30 , L_78 ) ;
if ( V_31 )
V_30 += sprintf ( V_30 , L_78 ) ;
if ( V_32 )
V_30 += sprintf ( V_30 , L_78 ) ;
} else {
if ( V_29 ) {
if ( V_20 )
V_30 += sprintf ( V_30 , L_79 , V_20 -> V_76 ) ;
else
V_30 += sprintf ( V_30 , L_78 ) ;
}
if ( V_31 ) {
if ( V_19 )
V_30 += sprintf ( V_30 , L_79 , V_19 -> V_71 ) ;
else
V_30 += sprintf ( V_30 , L_78 ) ;
}
if ( V_32 )
V_30 += sprintf ( V_30 , L_79 , V_18 -> V_21 ) ;
}
if ( V_33 )
V_30 += sprintf ( V_30 , L_80 ,
1.0 / V_106 * V_18 -> V_63 / V_95 ) ;
if ( V_33 ) {
if ( ! V_107 )
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_18 -> V_64 / V_18 -> V_62 / V_108 ) ;
else
V_30 += sprintf ( V_30 , L_82 ) ;
}
if ( V_33 )
V_30 += sprintf ( V_30 , L_80 ,
1.0 * V_18 -> V_62 * V_108 / V_106 * V_18 -> V_63 / V_18 -> V_64 / V_95 ) ;
V_30 += sprintf ( V_30 , L_80 , 1.0 * V_18 -> V_62 / V_106 / V_95 ) ;
if ( V_34 )
V_30 += sprintf ( V_30 , L_83 , V_18 -> V_66 ) ;
if ( V_35 )
V_30 += sprintf ( V_30 , L_83 , V_18 -> V_67 ) ;
if ( V_36 )
V_30 += sprintf ( V_30 , L_84 , V_18 -> V_68 ) ;
if ( V_37 )
V_30 += sprintf ( V_30 , L_85 , V_18 -> V_69 ) ;
if ( ! V_38 )
goto V_39;
if ( V_40 )
V_30 += sprintf ( V_30 , L_79 , V_18 -> V_70 ) ;
if ( V_41 ) {
if ( ! V_109 )
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_18 -> V_65 / V_18 -> V_62 ) ;
else
V_30 += sprintf ( V_30 , L_82 ) ;
}
if ( ! ( V_18 -> V_61 & V_98 ) )
goto V_39;
if ( V_41 && ! V_42 && ! V_43 )
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_19 -> V_72 / V_18 -> V_62 ) ;
if ( V_41 )
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_19 -> V_73 / V_18 -> V_62 ) ;
if ( V_44 )
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_19 -> V_74 / V_18 -> V_62 ) ;
if ( V_45 )
V_30 += sprintf ( V_30 , L_79 , V_19 -> V_75 ) ;
if ( ! ( V_18 -> V_61 & V_100 ) )
goto V_39;
if ( V_46 )
V_30 += sprintf ( V_30 , L_79 , V_20 -> V_94 ) ;
if ( V_47 ) {
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_20 -> V_77 / V_18 -> V_62 ) ;
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_20 -> V_78 / V_18 -> V_62 ) ;
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_20 -> V_79 / V_18 -> V_62 ) ;
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_20 -> V_80 / V_18 -> V_62 ) ;
}
if ( V_48 )
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_20 -> V_81 / V_18 -> V_62 ) ;
if ( V_49 )
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_20 -> V_82 / V_18 -> V_62 ) ;
if ( V_50 )
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_20 -> V_83 / V_18 -> V_62 ) ;
if ( V_51 )
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_20 -> V_84 / V_18 -> V_62 ) ;
if ( V_52 ) {
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_20 -> V_85 / V_18 -> V_62 ) ;
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_20 -> V_86 / V_18 -> V_62 ) ;
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_20 -> V_87 / V_18 -> V_62 ) ;
}
if ( V_95 < V_110 )
V_96 = L_81 ;
else
V_96 = L_86 ;
if ( V_53 && ! V_54 ) {
if ( V_53 & V_55 )
V_30 += sprintf ( V_30 , V_96 , V_20 -> V_88 * V_111 / V_95 ) ;
if ( V_53 & V_56 )
V_30 += sprintf ( V_30 , V_96 , V_20 -> V_89 * V_111 / V_95 ) ;
if ( V_53 & V_57 )
V_30 += sprintf ( V_30 , V_96 , V_20 -> V_90 * V_111 / V_95 ) ;
if ( V_53 & V_58 )
V_30 += sprintf ( V_30 , V_96 , V_20 -> V_91 * V_112 / V_95 ) ;
if ( V_53 & V_59 )
V_30 += sprintf ( V_30 , V_96 , 100.0 * V_20 -> V_92 * V_113 / V_95 ) ;
if ( V_53 & V_60 )
V_30 += sprintf ( V_30 , V_96 , 100.0 * V_20 -> V_93 * V_113 / V_95 ) ;
} else if ( V_53 && V_54 ) {
if ( V_53 & V_55 )
V_30 += sprintf ( V_30 , V_96 ,
V_20 -> V_88 * V_111 ) ;
if ( V_53 & V_56 )
V_30 += sprintf ( V_30 , V_96 ,
V_20 -> V_89 * V_111 ) ;
if ( V_53 & V_57 )
V_30 += sprintf ( V_30 , V_96 ,
V_20 -> V_90 * V_111 ) ;
if ( V_53 & V_58 )
V_30 += sprintf ( V_30 , V_96 ,
V_20 -> V_91 * V_112 ) ;
if ( V_53 & V_59 )
V_30 += sprintf ( V_30 , V_96 , 100.0 * V_20 -> V_92 * V_113 / V_95 ) ;
if ( V_53 & V_60 )
V_30 += sprintf ( V_30 , V_96 , 100.0 * V_20 -> V_93 * V_113 / V_95 ) ;
V_30 += sprintf ( V_30 , V_96 , V_95 ) ;
}
V_39:
V_30 += sprintf ( V_30 , L_44 ) ;
return 0 ;
}
void F_20 ()
{
fputs ( V_114 , stdout ) ;
fflush ( stdout ) ;
V_30 = V_114 ;
}
void F_21 ()
{
fputs ( V_114 , V_115 ) ;
V_30 = V_114 ;
}
void F_22 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_116 ;
if ( ! V_116 || ! V_117 )
F_17 () ;
if ( V_14 . V_118 > 1 )
F_19 ( & V_104 . V_105 , & V_104 . V_119 ,
& V_104 . V_120 ) ;
V_116 = 1 ;
if ( V_117 )
return;
F_3 ( F_19 , V_18 , V_19 , V_20 ) ;
}
void
F_23 ( struct V_6 * V_121 , struct V_6 * V_122 )
{
if ( V_47 ) {
V_122 -> V_77 = V_121 -> V_77 - V_122 -> V_77 ;
V_122 -> V_78 = V_121 -> V_78 - V_122 -> V_78 ;
V_122 -> V_79 = V_121 -> V_79 - V_122 -> V_79 ;
V_122 -> V_80 = V_121 -> V_80 - V_122 -> V_80 ;
}
V_122 -> V_81 = V_121 -> V_81 - V_122 -> V_81 ;
if ( V_49 )
V_122 -> V_82 = V_121 -> V_82 - V_122 -> V_82 ;
if ( V_50 )
V_122 -> V_83 = V_121 -> V_83 - V_122 -> V_83 ;
if ( V_51 )
V_122 -> V_84 = V_121 -> V_84 - V_122 -> V_84 ;
V_122 -> V_85 = V_121 -> V_85 - V_122 -> V_85 ;
V_122 -> V_86 = V_121 -> V_86 - V_122 -> V_86 ;
V_122 -> V_87 = V_121 -> V_87 - V_122 -> V_87 ;
V_122 -> V_94 = V_121 -> V_94 ;
F_24 ( V_121 -> V_88 , V_122 -> V_88 ) ;
F_24 ( V_121 -> V_89 , V_122 -> V_89 ) ;
F_24 ( V_121 -> V_90 , V_122 -> V_90 ) ;
F_24 ( V_121 -> V_91 , V_122 -> V_91 ) ;
F_24 ( V_121 -> V_92 , V_122 -> V_92 ) ;
F_24 ( V_121 -> V_93 , V_122 -> V_93 ) ;
}
void
F_25 ( struct V_5 * V_121 , struct V_5 * V_122 )
{
V_122 -> V_72 = V_121 -> V_72 - V_122 -> V_72 ;
V_122 -> V_73 = V_121 -> V_73 - V_122 -> V_73 ;
V_122 -> V_74 = V_121 -> V_74 - V_122 -> V_74 ;
V_122 -> V_75 = V_121 -> V_75 ;
}
void
F_26 ( struct V_4 * V_121 , struct V_4 * V_122 ,
struct V_5 * V_123 )
{
V_122 -> V_62 = V_121 -> V_62 - V_122 -> V_62 ;
if ( V_122 -> V_62 < ( 1000 * 1000 ) )
F_27 ( - 3 , L_87
L_88
L_89 ) ;
V_122 -> V_65 = V_121 -> V_65 - V_122 -> V_65 ;
if ( V_33 ) {
if ( ( V_121 -> V_63 > V_122 -> V_63 ) && ( V_121 -> V_64 > V_122 -> V_64 ) ) {
V_122 -> V_63 = V_121 -> V_63 - V_122 -> V_63 ;
V_122 -> V_64 = V_121 -> V_64 - V_122 -> V_64 ;
} else {
if ( ! V_124 ) {
fprintf ( V_115 , L_90 , V_125 ) ;
fprintf ( V_115 , L_91 ) ;
fprintf ( V_115 , L_92 ) ;
V_124 = 1 ;
}
V_107 = 1 ;
V_109 = 1 ;
}
}
if ( V_126 ) {
} else {
if ( ( V_122 -> V_64 + V_123 -> V_72 + V_123 -> V_73 + V_123 -> V_74 ) > V_122 -> V_62 )
V_122 -> V_65 = 0 ;
else {
V_122 -> V_65 = V_122 -> V_62 - V_122 -> V_64 - V_123 -> V_72
- V_123 -> V_73 - V_123 -> V_74 ;
}
}
if ( V_122 -> V_64 == 0 ) {
if ( V_38 > 1 ) fprintf ( V_115 , L_93 , V_122 -> V_21 ) ;
V_122 -> V_64 = 1 ;
}
V_122 -> V_66 = V_121 -> V_66 - V_122 -> V_66 ;
V_122 -> V_66 &= 0xFFFFFFFF ;
V_122 -> V_67 = V_121 -> V_67 - V_122 -> V_67 ;
V_122 -> V_68 = V_121 -> V_68 ;
V_122 -> V_69 = V_121 -> V_69 ;
if ( V_40 )
V_122 -> V_70 = V_121 -> V_70 - V_122 -> V_70 ;
}
int F_28 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_127 ,
struct V_5 * V_128 , struct V_6 * V_129 )
{
if ( V_18 -> V_61 & V_98 )
F_25 ( V_19 , V_128 ) ;
F_26 ( V_18 , V_127 , V_128 ) ;
if ( V_18 -> V_61 & V_100 )
F_23 ( V_20 , V_129 ) ;
return 0 ;
}
void F_29 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
V_18 -> V_62 = 0 ;
V_18 -> V_63 = 0 ;
V_18 -> V_64 = 0 ;
V_18 -> V_65 = 0 ;
V_18 -> V_70 = 0 ;
V_18 -> V_66 = 0 ;
V_18 -> V_67 = 0 ;
V_18 -> V_61 = V_98 | V_100 ;
V_19 -> V_72 = 0 ;
V_19 -> V_73 = 0 ;
V_19 -> V_74 = 0 ;
V_19 -> V_75 = 0 ;
V_20 -> V_77 = 0 ;
V_20 -> V_78 = 0 ;
V_20 -> V_79 = 0 ;
V_20 -> V_80 = 0 ;
V_20 -> V_81 = 0 ;
if ( V_49 )
V_20 -> V_82 = 0 ;
if ( V_50 )
V_20 -> V_83 = 0 ;
if ( V_51 )
V_20 -> V_84 = 0 ;
V_20 -> V_85 = 0 ;
V_20 -> V_86 = 0 ;
V_20 -> V_87 = 0 ;
V_20 -> V_88 = 0 ;
V_20 -> V_91 = 0 ;
V_20 -> V_89 = 0 ;
V_20 -> V_90 = 0 ;
V_20 -> V_92 = 0 ;
V_20 -> V_93 = 0 ;
V_20 -> V_94 = 0 ;
}
int F_30 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_104 . V_105 . V_62 += V_18 -> V_62 ;
V_104 . V_105 . V_63 += V_18 -> V_63 ;
V_104 . V_105 . V_64 += V_18 -> V_64 ;
V_104 . V_105 . V_65 += V_18 -> V_65 ;
V_104 . V_105 . V_66 += V_18 -> V_66 ;
V_104 . V_105 . V_67 += V_18 -> V_67 ;
if ( ! ( V_18 -> V_61 & V_98 ) )
return 0 ;
V_104 . V_119 . V_72 += V_19 -> V_72 ;
V_104 . V_119 . V_73 += V_19 -> V_73 ;
V_104 . V_119 . V_74 += V_19 -> V_74 ;
V_104 . V_119 . V_75 = F_31 ( V_104 . V_119 . V_75 , V_19 -> V_75 ) ;
if ( ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
if ( V_47 ) {
V_104 . V_120 . V_77 += V_20 -> V_77 ;
V_104 . V_120 . V_78 += V_20 -> V_78 ;
V_104 . V_120 . V_79 += V_20 -> V_79 ;
V_104 . V_120 . V_80 += V_20 -> V_80 ;
}
V_104 . V_120 . V_81 += V_20 -> V_81 ;
if ( V_49 )
V_104 . V_120 . V_82 += V_20 -> V_82 ;
if ( V_50 )
V_104 . V_120 . V_83 += V_20 -> V_83 ;
if ( V_51 )
V_104 . V_120 . V_84 += V_20 -> V_84 ;
V_104 . V_120 . V_85 += V_20 -> V_85 ;
V_104 . V_120 . V_86 += V_20 -> V_86 ;
V_104 . V_120 . V_87 += V_20 -> V_87 ;
V_104 . V_120 . V_88 += V_20 -> V_88 ;
V_104 . V_120 . V_91 += V_20 -> V_91 ;
V_104 . V_120 . V_89 += V_20 -> V_89 ;
V_104 . V_120 . V_90 += V_20 -> V_90 ;
V_104 . V_120 . V_94 = F_31 ( V_104 . V_120 . V_94 , V_20 -> V_94 ) ;
V_104 . V_120 . V_92 += V_20 -> V_92 ;
V_104 . V_120 . V_93 += V_20 -> V_93 ;
return 0 ;
}
void F_32 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_29 ( & V_104 . V_105 , & V_104 . V_119 , & V_104 . V_120 ) ;
F_3 ( F_30 , V_18 , V_19 , V_20 ) ;
V_104 . V_105 . V_62 /= V_14 . V_118 ;
V_104 . V_105 . V_63 /= V_14 . V_118 ;
V_104 . V_105 . V_64 /= V_14 . V_118 ;
V_104 . V_105 . V_65 /= V_14 . V_118 ;
V_104 . V_105 . V_66 /= V_14 . V_118 ;
V_104 . V_105 . V_66 &= 0xFFFFFFFF ;
V_104 . V_105 . V_67 /= V_14 . V_118 ;
V_104 . V_119 . V_72 /= V_14 . V_130 ;
V_104 . V_119 . V_73 /= V_14 . V_130 ;
V_104 . V_119 . V_74 /= V_14 . V_130 ;
if ( V_47 ) {
V_104 . V_120 . V_77 /= V_14 . V_15 ;
V_104 . V_120 . V_78 /= V_14 . V_15 ;
V_104 . V_120 . V_79 /= V_14 . V_15 ;
V_104 . V_120 . V_80 /= V_14 . V_15 ;
}
V_104 . V_120 . V_81 /= V_14 . V_15 ;
if ( V_49 )
V_104 . V_120 . V_82 /= V_14 . V_15 ;
if ( V_50 )
V_104 . V_120 . V_83 /= V_14 . V_15 ;
if ( V_51 )
V_104 . V_120 . V_84 /= V_14 . V_15 ;
V_104 . V_120 . V_85 /= V_14 . V_15 ;
V_104 . V_120 . V_86 /= V_14 . V_15 ;
V_104 . V_120 . V_87 /= V_14 . V_15 ;
}
static unsigned long long F_33 ( void )
{
unsigned int V_131 , V_132 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_131 | ( ( unsigned long long ) V_132 ) << 32 ;
}
int F_34 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
unsigned long long V_25 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_115 , L_94 , V_1 ) ;
return - 1 ;
}
V_18 -> V_62 = F_33 () ;
if ( V_33 ) {
if ( F_12 ( V_1 , V_133 , & V_18 -> V_63 ) )
return - 3 ;
if ( F_12 ( V_1 , V_134 , & V_18 -> V_64 ) )
return - 4 ;
V_18 -> V_63 = V_18 -> V_63 * V_135 ;
V_18 -> V_64 = V_18 -> V_64 * V_135 ;
}
if ( V_40 ) {
if ( F_12 ( V_1 , V_136 , & V_25 ) )
return - 5 ;
V_18 -> V_70 = V_25 & 0xFFFFFFFF ;
}
if ( V_34 ) {
if ( F_12 ( V_1 , V_34 , & V_25 ) )
return - 5 ;
V_18 -> V_66 = V_25 & 0xFFFFFFFF ;
}
if ( V_35 )
if ( F_12 ( V_1 , V_35 , & V_18 -> V_67 ) )
return - 5 ;
if ( V_36 ) {
if ( F_12 ( V_1 , V_36 , & V_25 ) )
return - 5 ;
V_18 -> V_68 = V_25 & 0xFFFFFFFF ;
}
if ( V_37 )
if ( F_12 ( V_1 , V_37 , & V_18 -> V_69 ) )
return - 5 ;
if ( V_126 ) {
if ( F_12 ( V_1 , V_137 , & V_18 -> V_65 ) )
return - 6 ;
}
if ( ! ( V_18 -> V_61 & V_98 ) )
return 0 ;
if ( V_41 && ! V_42 && ! V_43 ) {
if ( F_12 ( V_1 , V_138 , & V_19 -> V_72 ) )
return - 6 ;
}
if ( V_41 && ! V_43 ) {
if ( F_12 ( V_1 , V_139 , & V_19 -> V_73 ) )
return - 7 ;
} else if ( V_43 ) {
if ( F_12 ( V_1 , V_140 , & V_19 -> V_73 ) )
return - 7 ;
}
if ( V_44 )
if ( F_12 ( V_1 , V_141 , & V_19 -> V_74 ) )
return - 8 ;
if ( V_45 ) {
if ( F_12 ( V_1 , V_142 , & V_25 ) )
return - 9 ;
V_19 -> V_75 = V_143 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
if ( ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
if ( V_47 ) {
if ( F_12 ( V_1 , V_144 , & V_20 -> V_77 ) )
return - 10 ;
if ( F_12 ( V_1 , V_145 , & V_20 -> V_78 ) )
return - 11 ;
if ( F_12 ( V_1 , V_146 , & V_20 -> V_79 ) )
return - 12 ;
if ( F_12 ( V_1 , V_147 , & V_20 -> V_80 ) )
return - 13 ;
}
if ( V_49 )
if ( F_12 ( V_1 , V_148 , & V_20 -> V_82 ) )
return - 9 ;
if ( V_50 )
if ( F_12 ( V_1 , V_149 , & V_20 -> V_83 ) )
return - 10 ;
if ( V_48 )
if ( F_12 ( V_1 , V_150 , & V_20 -> V_81 ) )
return - 11 ;
if ( V_51 )
if ( F_12 ( V_1 , V_151 , & V_20 -> V_84 ) )
return - 12 ;
if ( V_52 ) {
if ( F_12 ( V_1 , V_152 , & V_20 -> V_85 ) )
return - 13 ;
if ( F_12 ( V_1 , V_153 , & V_20 -> V_86 ) )
return - 13 ;
if ( F_12 ( V_1 , V_154 , & V_20 -> V_87 ) )
return - 13 ;
}
if ( V_53 & V_55 ) {
if ( F_12 ( V_1 , V_155 , & V_25 ) )
return - 13 ;
V_20 -> V_88 = V_25 & 0xFFFFFFFF ;
}
if ( V_53 & V_56 ) {
if ( F_12 ( V_1 , V_156 , & V_25 ) )
return - 14 ;
V_20 -> V_89 = V_25 & 0xFFFFFFFF ;
}
if ( V_53 & V_58 ) {
if ( F_12 ( V_1 , V_157 , & V_25 ) )
return - 15 ;
V_20 -> V_91 = V_25 & 0xFFFFFFFF ;
}
if ( V_53 & V_57 ) {
if ( F_12 ( V_1 , V_158 , & V_25 ) )
return - 16 ;
V_20 -> V_90 = V_25 & 0xFFFFFFFF ;
}
if ( V_53 & V_59 ) {
if ( F_12 ( V_1 , V_159 , & V_25 ) )
return - 16 ;
V_20 -> V_92 = V_25 & 0xFFFFFFFF ;
}
if ( V_53 & V_60 ) {
if ( F_12 ( V_1 , V_160 , & V_25 ) )
return - 16 ;
V_20 -> V_93 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 ) {
if ( F_12 ( V_1 , V_161 , & V_25 ) )
return - 17 ;
V_20 -> V_94 = V_143 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
return 0 ;
}
static void
F_35 ()
{
unsigned long long V_25 ;
unsigned int V_162 ;
F_12 ( V_163 , V_164 , & V_25 ) ;
V_162 = ( V_25 >> 8 ) & 0xFF ;
V_165 = V_162 * V_166 * 1000000 ;
V_108 = V_165 / V_167 ;
}
static void
F_36 ( void )
{
unsigned long long V_25 ;
unsigned int V_168 ;
F_12 ( V_163 , V_164 , & V_25 ) ;
fprintf ( V_115 , L_95 , V_163 , V_25 ) ;
V_168 = ( V_25 >> 40 ) & 0xFF ;
fprintf ( V_115 , L_96 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 8 ) & 0xFF ;
fprintf ( V_115 , L_97 ,
V_168 , V_166 , V_168 * V_166 ) ;
F_12 ( V_163 , V_169 , & V_25 ) ;
fprintf ( V_115 , L_98 ,
V_163 , V_25 , V_25 & 0x2 ? L_99 : L_100 ) ;
return;
}
static void
F_37 ( void )
{
unsigned long long V_25 ;
unsigned int V_168 ;
F_12 ( V_163 , V_170 , & V_25 ) ;
fprintf ( V_115 , L_101 , V_163 , V_25 ) ;
V_168 = ( V_25 >> 8 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_102 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 0 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_103 ,
V_168 , V_166 , V_168 * V_166 ) ;
return;
}
static void
F_38 ( void )
{
unsigned long long V_25 ;
unsigned int V_168 ;
F_12 ( V_163 , V_171 , & V_25 ) ;
fprintf ( V_115 , L_104 , V_163 , V_25 ) ;
V_168 = ( V_25 >> 56 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_105 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 48 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_106 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 40 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_107 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 32 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_108 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 24 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_109 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 16 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_110 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 8 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_111 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 0 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_112 ,
V_168 , V_166 , V_168 * V_166 ) ;
return;
}
static void
F_39 ( void )
{
unsigned long long V_25 ;
unsigned int V_168 ;
F_12 ( V_163 , V_172 , & V_25 ) ;
fprintf ( V_115 , L_113 , V_163 , V_25 ) ;
V_168 = ( V_25 >> 56 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_114 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 48 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_115 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 40 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_116 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 32 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_117 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 24 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_118 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 16 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_119 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 8 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_120 ,
V_168 , V_166 , V_168 * V_166 ) ;
V_168 = ( V_25 >> 0 ) & 0xFF ;
if ( V_168 )
fprintf ( V_115 , L_121 ,
V_168 , V_166 , V_168 * V_166 ) ;
return;
}
static void
F_40 ( void )
{
int V_119 ;
unsigned int V_168 ;
unsigned long long V_25 ;
int V_173 ;
int V_174 ;
int V_175 ;
F_12 ( V_163 , V_176 , & V_25 ) ;
fprintf ( V_115 , L_122 ,
V_163 , V_25 ) ;
V_119 = V_25 & 0xFF ;
V_168 = ( V_25 >> 8 ) && 0xFF ;
if ( V_168 > 0 )
fprintf ( V_115 ,
L_123 ,
V_168 , V_166 , V_168 * V_166 , V_119 ) ;
for ( V_175 = 16 ; V_175 < 64 ; V_175 = V_175 + 8 ) {
V_173 = ( V_25 >> V_175 ) & 0x1F ;
V_174 = ( V_25 >> ( V_175 + 5 ) ) && 0x7 ;
if ( ! V_173 || ! V_174 )
return;
V_119 = V_119 + V_173 ;
V_168 = V_168 - V_174 ;
if ( V_168 > 0 )
fprintf ( V_115 ,
L_123 ,
V_168 , V_166 , V_168 * V_166 , V_119 ) ;
}
}
static void
F_41 ( void )
{
unsigned long long V_25 ;
F_12 ( V_163 , V_177 , & V_25 ) ;
#define F_42 (1UL << 27)
#define F_43 (1UL << 28)
fprintf ( V_115 , L_124 , V_163 , V_25 ) ;
fprintf ( V_115 , L_125 ,
( V_25 & F_43 ) ? L_126 : L_127 ,
( V_25 & F_42 ) ? L_128 : L_127 ,
( V_25 & V_178 ) ? L_129 : L_127 ,
( V_25 & V_179 ) ? L_130 : L_127 ,
( V_25 & ( 1 << 15 ) ) ? L_127 : L_131 ,
( unsigned int ) V_25 & 7 ,
V_180 [ V_181 ] ) ;
return;
}
static void
F_44 ( void )
{
unsigned long long V_25 ;
F_12 ( V_163 , V_182 , & V_25 ) ;
fprintf ( V_115 , L_132 , V_163 , V_25 ) ;
fprintf ( V_115 , L_133 , ( unsigned int ) V_25 & 0xEF ) ;
F_12 ( V_163 , V_183 , & V_25 ) ;
fprintf ( V_115 , L_134 , V_163 , V_25 ) ;
if ( V_25 ) {
fprintf ( V_115 , L_135 , ( unsigned int ) ( V_25 >> 48 ) & 0xEFFF ) ;
fprintf ( V_115 , L_136 , ( unsigned int ) ( V_25 >> 32 ) & 0xEFFF ) ;
fprintf ( V_115 , L_137 , ( unsigned int ) ( V_25 >> 16 ) & 0xEF ) ;
fprintf ( V_115 , L_138 , ( unsigned int ) ( V_25 ) & 0xEFFF ) ;
}
fprintf ( V_115 , L_139 ) ;
F_12 ( V_163 , V_184 , & V_25 ) ;
fprintf ( V_115 , L_140 , V_163 , V_25 ) ;
if ( V_25 ) {
fprintf ( V_115 , L_141 , ( unsigned int ) ( V_25 >> 48 ) & 0xEFFF ) ;
fprintf ( V_115 , L_142 , ( unsigned int ) ( V_25 >> 32 ) & 0xEFFF ) ;
fprintf ( V_115 , L_143 , ( unsigned int ) ( V_25 >> 16 ) & 0xEF ) ;
fprintf ( V_115 , L_144 , ( unsigned int ) ( V_25 ) & 0xEFFF ) ;
}
fprintf ( V_115 , L_139 ) ;
F_12 ( V_163 , V_185 , & V_25 ) ;
fprintf ( V_115 , L_145 , V_163 , V_25 ) ;
if ( ( V_25 ) & 0x3 )
fprintf ( V_115 , L_146 , ( unsigned int ) ( V_25 ) & 0x3 ) ;
fprintf ( V_115 , L_147 , ( unsigned int ) ( V_25 >> 31 ) & 1 ) ;
fprintf ( V_115 , L_139 ) ;
F_12 ( V_163 , V_186 , & V_25 ) ;
fprintf ( V_115 , L_148 , V_163 , V_25 ) ;
fprintf ( V_115 , L_149 , ( unsigned int ) ( V_25 ) & 0xEF ) ;
fprintf ( V_115 , L_147 , ( unsigned int ) ( V_25 >> 31 ) & 1 ) ;
fprintf ( V_115 , L_139 ) ;
}
void F_45 ( void )
{
F_46 ( V_3 ) ;
V_3 = NULL ;
V_3 = 0 ;
F_46 ( V_23 ) ;
V_23 = NULL ;
V_22 = 0 ;
free ( V_187 ) ;
free ( V_188 ) ;
free ( V_189 ) ;
V_187 = NULL ;
V_188 = NULL ;
V_189 = NULL ;
free ( V_190 ) ;
free ( V_191 ) ;
free ( V_192 ) ;
V_190 = NULL ;
V_191 = NULL ;
V_192 = NULL ;
free ( V_114 ) ;
V_114 = NULL ;
V_30 = NULL ;
}
T_3 * F_47 ( const char * V_193 , const char * V_194 )
{
T_3 * V_195 = fopen ( V_193 , L_150 ) ;
if ( ! V_195 )
F_14 ( 1 , L_151 , V_193 ) ;
return V_195 ;
}
int F_48 ( const char * V_196 , ... )
{
T_4 args ;
char V_193 [ V_197 ] ;
T_3 * V_195 ;
int V_198 ;
va_start ( args , V_196 ) ;
vsnprintf ( V_193 , sizeof( V_193 ) , V_196 , args ) ;
va_end ( args ) ;
V_195 = F_47 ( V_193 , L_150 ) ;
if ( fscanf ( V_195 , L_152 , & V_198 ) != 1 )
F_14 ( 1 , L_153 , V_193 ) ;
fclose ( V_195 ) ;
return V_198 ;
}
int F_49 ( int V_1 )
{
char V_193 [ 64 ] ;
T_3 * V_195 ;
int V_199 ;
char V_200 ;
int V_175 ;
sprintf ( V_193 ,
L_154 ,
V_1 ) ;
V_195 = fopen ( V_193 , L_150 ) ;
if ( V_195 == NULL ) {
perror ( V_193 ) ;
exit ( 1 ) ;
}
for ( V_175 = 0 ; V_175 < V_14 . V_17 ; V_175 ++ ) {
fscanf ( V_195 , L_152 , & V_199 ) ;
if ( V_199 == V_1 ) {
fclose ( V_195 ) ;
return V_175 ;
}
if ( V_175 != ( V_14 . V_17 - 1 ) )
fscanf ( V_195 , L_155 , & V_200 ) ;
}
fclose ( V_195 ) ;
return - 1 ;
}
int F_50 ( int V_1 )
{
return V_1 == F_48 ( L_156 , V_1 ) ;
}
int F_51 ( int V_1 )
{
return F_48 ( L_157 , V_1 ) ;
}
int F_52 ( int V_1 )
{
return F_48 ( L_158 , V_1 ) ;
}
int F_53 ( int V_1 )
{
char V_193 [ 80 ] ;
T_3 * V_195 ;
int V_201 ;
int V_202 = 0 ;
char V_200 ;
char V_203 [ 100 ] ;
char * V_204 ;
sprintf ( V_193 , L_154 , V_1 ) ;
V_195 = F_47 ( V_193 , L_150 ) ;
fscanf ( V_195 , L_159 , & V_201 , & V_200 ) ;
fseek ( V_195 , 0 , V_205 ) ;
fgets ( V_203 , 100 , V_195 ) ;
V_204 = strchr ( V_203 , V_200 ) ;
while ( V_204 != NULL ) {
V_202 ++ ;
V_204 = strchr ( V_204 + 1 , V_200 ) ;
}
fclose ( V_195 ) ;
return V_202 + 1 ;
}
int F_54 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_206 , struct V_5 * V_207 ,
struct V_6 * V_208 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_127 ;
struct V_5 * V_19 , * V_128 ;
struct V_6 * V_20 , * V_129 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_127 = F_5 ( V_206 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_128 = F_6 ( V_207 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_129 = F_7 ( V_208 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_127 , V_128 , V_129 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_55 ( int (F_4)( int ) )
{
T_3 * V_209 ;
int V_210 ;
int V_10 ;
V_209 = F_47 ( V_211 , L_150 ) ;
V_10 = fscanf ( V_209 , L_160 ) ;
if ( V_10 != 0 )
F_14 ( 1 , L_161 , V_211 ) ;
while ( 1 ) {
V_10 = fscanf ( V_209 , L_162 , & V_210 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_210 ) ;
if ( V_10 ) {
fclose ( V_209 ) ;
return ( V_10 ) ;
}
}
fclose ( V_209 ) ;
return 0 ;
}
void F_56 ( void )
{
F_45 () ;
F_57 () ;
printf ( L_163 , V_14 . V_118 ) ;
}
int F_58 ( int V_1 )
{
if ( V_14 . V_212 < V_1 )
V_14 . V_212 = V_1 ;
V_14 . V_118 += 1 ;
return 0 ;
}
int F_59 ( int V_1 )
{
F_10 ( V_1 , V_2 , V_3 ) ;
return 0 ;
}
void F_60 ()
{
int V_10 ;
int V_213 = 0 ;
V_214:
V_213 ++ ;
V_10 = F_3 ( F_34 , V_215 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
if ( V_213 > 1 ) {
exit ( V_10 ) ;
}
F_56 () ;
goto V_214;
}
V_213 = 0 ;
F_61 ( & V_216 , (struct V_217 * ) NULL ) ;
while ( 1 ) {
if ( F_55 ( F_1 ) ) {
F_56 () ;
goto V_214;
}
F_62 ( V_218 ) ;
V_10 = F_3 ( F_34 , V_219 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_56 () ;
goto V_214;
}
F_61 ( & V_220 , (struct V_217 * ) NULL ) ;
F_63 ( & V_220 , & V_216 , & V_101 ) ;
F_54 ( F_28 , V_219 , V_215 ) ;
F_32 ( V_215 ) ;
F_22 ( V_215 ) ;
F_20 () ;
F_62 ( V_218 ) ;
V_10 = F_3 ( F_34 , V_215 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_56 () ;
goto V_214;
}
F_61 ( & V_216 , (struct V_217 * ) NULL ) ;
F_63 ( & V_216 , & V_220 , & V_101 ) ;
F_54 ( F_28 , V_215 , V_219 ) ;
F_32 ( V_219 ) ;
F_22 ( V_219 ) ;
F_20 () ;
}
}
void F_64 ()
{
struct V_221 V_222 ;
char V_26 [ 32 ] ;
sprintf ( V_26 , L_1 , V_163 ) ;
if ( V_221 ( V_26 , & V_222 ) )
if ( system ( L_164 ) )
F_14 ( - 5 , L_165 ) ;
}
void F_65 ()
{
struct V_223 V_224 ;
T_5 V_225 = & V_224 ;
struct V_226 V_227 ;
T_6 V_228 = & V_227 ;
extern int V_229 ( T_5 V_230 , T_6 V_231 ) ;
int V_232 = 0 ;
char V_26 [ 32 ] ;
V_225 -> V_233 = F_66 () ;
V_225 -> V_234 = V_235 ;
if ( V_229 ( V_225 , V_228 ) < 0 )
F_14 ( - 6 , L_166 ) ;
if ( ( V_228 -> V_236 & ( 1 << V_237 ) ) == 0 ) {
V_232 ++ ;
F_67 ( L_167
L_168 , V_125 ) ;
}
sprintf ( V_26 , L_1 , V_163 ) ;
if ( F_68 ( V_26 , V_238 ) ) {
V_232 ++ ;
F_69 ( L_169 ) ;
}
if ( V_232 )
if ( F_70 () != 0 )
F_67 ( L_170 ) ;
if ( V_232 )
exit ( - 6 ) ;
}
int F_71 ( unsigned int V_239 , unsigned int V_240 )
{
unsigned long long V_25 ;
int * V_241 ;
if ( ! V_242 )
return 0 ;
if ( V_239 != 6 )
return 0 ;
switch ( V_240 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x25 :
case 0x2C :
case 0x2E :
case 0x2F :
V_241 = V_243 ;
break;
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
V_241 = V_244 ;
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
V_241 = V_245 ;
break;
case 0x37 :
case 0x4D :
V_241 = V_246 ;
break;
case 0x4C :
V_241 = V_247 ;
break;
case 0x57 :
V_241 = V_248 ;
break;
default:
return 0 ;
}
F_12 ( V_163 , V_177 , & V_25 ) ;
V_181 = V_241 [ V_25 & 0xF ] ;
return 1 ;
}
int F_72 ( unsigned int V_239 , unsigned int V_240 )
{
switch ( V_240 ) {
case 0x2E :
case 0x2F :
return 0 ;
default:
return 1 ;
}
}
int F_73 ( unsigned int V_239 , unsigned int V_240 )
{
if ( ! V_242 )
return 0 ;
if ( V_239 != 6 )
return 0 ;
switch ( V_240 ) {
case 0x3E :
case 0x3F :
return 1 ;
default:
return 0 ;
}
}
int F_74 ( unsigned int V_239 , unsigned int V_240 )
{
if ( ! V_242 )
return 0 ;
if ( V_239 != 6 )
return 0 ;
switch ( V_240 ) {
case 0x3F :
return 1 ;
default:
return 0 ;
}
}
int F_75 ( unsigned int V_239 , unsigned int V_240 )
{
if ( ! V_242 )
return 0 ;
if ( V_239 != 6 )
return 0 ;
switch ( V_240 ) {
case 0x57 :
return 1 ;
default:
return 0 ;
}
}
int F_76 ( unsigned int V_239 , unsigned int V_240 )
{
if ( ! V_242 )
return 0 ;
if ( V_239 != 6 )
return 0 ;
switch ( V_240 ) {
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
case 0x57 :
return 1 ;
default:
return 0 ;
}
}
static void
F_77 ( V_239 , V_240 )
{
if ( ! V_249 )
return;
F_36 () ;
if ( F_74 ( V_239 , V_240 ) )
F_37 () ;
if ( F_73 ( V_239 , V_240 ) )
F_38 () ;
if ( F_72 ( V_239 , V_240 ) )
F_39 () ;
if ( F_75 ( V_239 , V_240 ) )
F_40 () ;
if ( F_76 ( V_239 , V_240 ) )
F_44 () ;
F_41 () ;
}
int F_78 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
char * V_250 ;
int V_1 ;
if ( ! V_251 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_61 & V_98 ) || ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_115 , L_94 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_252 , & V_25 ) )
return 0 ;
switch ( V_25 & 0xF ) {
case V_253 :
V_250 = L_171 ;
break;
case V_254 :
V_250 = L_172 ;
break;
case V_255 :
V_250 = L_173 ;
break;
default:
V_250 = L_174 ;
break;
}
fprintf ( V_115 , L_175 , V_1 , V_25 , V_250 ) ;
return 0 ;
}
int F_79 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_61 & V_98 ) || ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_115 , L_94 , V_1 ) ;
return - 1 ;
}
if ( V_256 ) {
F_12 ( V_1 , V_257 , & V_25 ) ;
fprintf ( V_115 , L_176 , V_1 , V_25 ) ;
fprintf ( V_115 , L_177 ,
( V_25 & 1 << 15 ) ? L_178 : L_127 ,
( V_25 & 1 << 14 ) ? L_179 : L_127 ,
( V_25 & 1 << 13 ) ? L_180 : L_127 ,
( V_25 & 1 << 12 ) ? L_181 : L_127 ,
( V_25 & 1 << 11 ) ? L_182 : L_127 ,
( V_25 & 1 << 10 ) ? L_183 : L_127 ,
( V_25 & 1 << 9 ) ? L_184 : L_127 ,
( V_25 & 1 << 8 ) ? L_185 : L_127 ,
( V_25 & 1 << 6 ) ? L_186 : L_127 ,
( V_25 & 1 << 5 ) ? L_187 : L_127 ,
( V_25 & 1 << 4 ) ? L_188 : L_127 ,
( V_25 & 1 << 2 ) ? L_189 : L_127 ,
( V_25 & 1 << 1 ) ? L_190 : L_127 ,
( V_25 & 1 << 0 ) ? L_191 : L_127 ) ;
fprintf ( V_115 , L_192 ,
( V_25 & 1 << 31 ) ? L_193 : L_127 ,
( V_25 & 1 << 30 ) ? L_194 : L_127 ,
( V_25 & 1 << 29 ) ? L_180 : L_127 ,
( V_25 & 1 << 28 ) ? L_181 : L_127 ,
( V_25 & 1 << 27 ) ? L_182 : L_127 ,
( V_25 & 1 << 26 ) ? L_183 : L_127 ,
( V_25 & 1 << 25 ) ? L_184 : L_127 ,
( V_25 & 1 << 24 ) ? L_185 : L_127 ,
( V_25 & 1 << 22 ) ? L_186 : L_127 ,
( V_25 & 1 << 21 ) ? L_187 : L_127 ,
( V_25 & 1 << 20 ) ? L_188 : L_127 ,
( V_25 & 1 << 18 ) ? L_195 : L_127 ,
( V_25 & 1 << 17 ) ? L_190 : L_127 ,
( V_25 & 1 << 16 ) ? L_191 : L_127 ) ;
}
if ( V_258 ) {
F_12 ( V_1 , V_259 , & V_25 ) ;
fprintf ( V_115 , L_196 , V_1 , V_25 ) ;
fprintf ( V_115 , L_197 ,
( V_25 & 1 << 0 ) ? L_191 : L_127 ,
( V_25 & 1 << 1 ) ? L_190 : L_127 ,
( V_25 & 1 << 4 ) ? L_188 : L_127 ,
( V_25 & 1 << 6 ) ? L_186 : L_127 ,
( V_25 & 1 << 8 ) ? L_185 : L_127 ,
( V_25 & 1 << 9 ) ? L_198 : L_127 ,
( V_25 & 1 << 10 ) ? L_183 : L_127 ,
( V_25 & 1 << 11 ) ? L_182 : L_127 ) ;
fprintf ( V_115 , L_199 ,
( V_25 & 1 << 16 ) ? L_191 : L_127 ,
( V_25 & 1 << 17 ) ? L_190 : L_127 ,
( V_25 & 1 << 20 ) ? L_188 : L_127 ,
( V_25 & 1 << 22 ) ? L_186 : L_127 ,
( V_25 & 1 << 24 ) ? L_185 : L_127 ,
( V_25 & 1 << 25 ) ? L_198 : L_127 ,
( V_25 & 1 << 26 ) ? L_183 : L_127 ,
( V_25 & 1 << 27 ) ? L_182 : L_127 ) ;
}
if ( V_260 ) {
F_12 ( V_1 , V_261 , & V_25 ) ;
fprintf ( V_115 , L_200 , V_1 , V_25 ) ;
fprintf ( V_115 , L_201 ,
( V_25 & 1 << 0 ) ? L_191 : L_127 ,
( V_25 & 1 << 1 ) ? L_190 : L_127 ,
( V_25 & 1 << 6 ) ? L_186 : L_127 ,
( V_25 & 1 << 8 ) ? L_185 : L_127 ,
( V_25 & 1 << 10 ) ? L_183 : L_127 ,
( V_25 & 1 << 11 ) ? L_182 : L_127 ) ;
fprintf ( V_115 , L_202 ,
( V_25 & 1 << 16 ) ? L_191 : L_127 ,
( V_25 & 1 << 17 ) ? L_190 : L_127 ,
( V_25 & 1 << 22 ) ? L_186 : L_127 ,
( V_25 & 1 << 24 ) ? L_185 : L_127 ,
( V_25 & 1 << 26 ) ? L_183 : L_127 ,
( V_25 & 1 << 27 ) ? L_182 : L_127 ) ;
}
return 0 ;
}
double F_80 ( V_240 )
{
unsigned long long V_25 ;
if ( V_53 & V_262 )
if ( ! F_12 ( V_163 , V_263 , & V_25 ) )
return ( ( V_25 >> 0 ) & V_264 ) * V_265 ;
switch ( V_240 ) {
case 0x37 :
case 0x4D :
return 30.0 ;
default:
return 135.0 ;
}
}
static double
F_81 ( int V_240 , double V_111 )
{
switch ( V_240 ) {
case 0x3F :
case 0x4F :
case 0x56 :
case 0x57 :
return ( V_112 = 15.3 / 1000000 ) ;
default:
return ( V_111 ) ;
}
}
void F_82 ( unsigned int V_239 , unsigned int V_240 )
{
unsigned long long V_25 ;
unsigned int V_266 ;
double V_267 ;
if ( ! V_242 )
return;
if ( V_239 != 6 )
return;
switch ( V_240 ) {
case 0x2A :
case 0x3A :
case 0x3C :
case 0x45 :
case 0x46 :
case 0x3D :
case 0x47 :
V_53 = V_55 | V_56 | V_268 | V_57 | V_262 ;
break;
case 0x4E :
case 0x5E :
V_53 = V_55 | V_58 | V_60 | V_59 | V_262 ;
break;
case 0x3F :
case 0x4F :
case 0x56 :
case 0x57 :
V_53 = V_55 | V_58 | V_269 | V_60 | V_59 | V_262 ;
break;
case 0x2D :
case 0x3E :
V_53 = V_55 | V_56 | V_268 | V_58 | V_269 | V_59 | V_60 | V_262 ;
break;
case 0x37 :
case 0x4D :
V_53 = V_55 | V_56 ;
break;
default:
return;
}
if ( F_12 ( V_163 , V_270 , & V_25 ) )
return;
V_265 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
if ( V_240 == 0x37 )
V_111 = 1.0 * ( 1 << ( V_25 >> 8 & 0x1F ) ) / 1000000 ;
else
V_111 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_112 = F_81 ( V_240 , V_111 ) ;
V_266 = V_25 >> 16 & 0xF ;
if ( V_266 == 0 )
V_266 = 0xA ;
V_113 = 1.0 / ( 1 << ( V_266 ) ) ;
V_267 = F_80 ( V_240 ) ;
V_110 = 0xFFFFFFFF * V_111 / V_267 ;
if ( V_38 )
fprintf ( V_115 , L_203 , V_110 , V_267 ) ;
return;
}
void F_83 ( V_239 , V_240 )
{
if ( ! V_242 )
return;
if ( V_239 != 6 )
return;
switch ( V_240 ) {
case 0x3C :
case 0x45 :
case 0x46 :
V_258 = 1 ;
case 0x3F :
V_256 = 1 ;
V_260 = 1 ;
default:
return;
}
}
int F_84 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_271 ;
int V_1 ;
if ( ! ( V_45 || V_46 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_61 & V_98 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_115 , L_94 , V_1 ) ;
return - 1 ;
}
if ( V_46 && ( V_18 -> V_61 & V_100 ) ) {
if ( F_12 ( V_1 , V_161 , & V_25 ) )
return 0 ;
V_271 = ( V_25 >> 16 ) & 0x7F ;
fprintf ( V_115 , L_204 ,
V_1 , V_25 , V_143 - V_271 ) ;
#ifdef F_85
if ( F_12 ( V_1 , V_272 , & V_25 ) )
return 0 ;
V_271 = ( V_25 >> 16 ) & 0x7F ;
V_273 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_115 , L_205 ,
V_1 , V_25 , V_143 - V_271 , V_143 - V_273 ) ;
#endif
}
if ( V_45 ) {
unsigned int V_274 ;
if ( F_12 ( V_1 , V_142 , & V_25 ) )
return 0 ;
V_271 = ( V_25 >> 16 ) & 0x7F ;
V_274 = ( V_25 >> 27 ) & 0xF ;
fprintf ( V_115 , L_206 ,
V_1 , V_25 , V_143 - V_271 , V_274 ) ;
#ifdef F_85
if ( F_12 ( V_1 , V_275 , & V_25 ) )
return 0 ;
V_271 = ( V_25 >> 16 ) & 0x7F ;
V_273 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_115 , L_207 ,
V_1 , V_25 , V_143 - V_271 , V_143 - V_273 ) ;
#endif
}
return 0 ;
}
void F_86 ( int V_1 , unsigned long long V_25 , char * V_276 )
{
fprintf ( V_115 , L_208 ,
V_1 , V_276 ,
( ( V_25 >> 15 ) & 1 ) ? L_99 : L_100 ,
( ( V_25 >> 0 ) & 0x7FFF ) * V_265 ,
( 1.0 + ( ( ( V_25 >> 22 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 17 ) & 0x1F ) ) * V_113 ,
( ( ( V_25 >> 16 ) & 1 ) ? L_99 : L_100 ) ) ;
return;
}
int F_87 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
if ( ! V_53 )
return 0 ;
if ( ! ( V_18 -> V_61 & V_98 ) || ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_115 , L_94 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_270 , & V_25 ) )
return - 1 ;
if ( V_38 ) {
fprintf ( V_115 , L_209
L_210 , V_1 , V_25 ,
V_265 , V_111 , V_113 ) ;
}
if ( V_53 & V_262 ) {
if ( F_12 ( V_1 , V_263 , & V_25 ) )
return - 5 ;
fprintf ( V_115 , L_211 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_264 ) * V_265 ,
( ( V_25 >> 16 ) & V_264 ) * V_265 ,
( ( V_25 >> 32 ) & V_264 ) * V_265 ,
( ( V_25 >> 48 ) & V_277 ) * V_113 ) ;
}
if ( V_53 & V_55 ) {
if ( F_12 ( V_1 , V_278 , & V_25 ) )
return - 9 ;
fprintf ( V_115 , L_212 ,
V_1 , V_25 , ( V_25 >> 63 ) & 1 ? L_127 : L_131 ) ;
F_86 ( V_1 , V_25 , L_213 ) ;
fprintf ( V_115 , L_214 ,
V_1 ,
( ( V_25 >> 47 ) & 1 ) ? L_99 : L_100 ,
( ( V_25 >> 32 ) & 0x7FFF ) * V_265 ,
( 1.0 + ( ( ( V_25 >> 54 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 49 ) & 0x1F ) ) * V_113 ,
( ( V_25 >> 48 ) & 1 ) ? L_99 : L_100 ) ;
}
if ( V_53 & V_269 ) {
if ( F_12 ( V_1 , V_279 , & V_25 ) )
return - 6 ;
fprintf ( V_115 , L_215 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_264 ) * V_265 ,
( ( V_25 >> 16 ) & V_264 ) * V_265 ,
( ( V_25 >> 32 ) & V_264 ) * V_265 ,
( ( V_25 >> 48 ) & V_277 ) * V_113 ) ;
}
if ( V_53 & V_58 ) {
if ( F_12 ( V_1 , V_280 , & V_25 ) )
return - 9 ;
fprintf ( V_115 , L_216 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_127 : L_131 ) ;
F_86 ( V_1 , V_25 , L_217 ) ;
}
if ( V_53 & V_268 ) {
if ( V_38 ) {
if ( F_12 ( V_1 , V_281 , & V_25 ) )
return - 7 ;
fprintf ( V_115 , L_218 , V_1 , V_25 & 0xF ) ;
}
}
if ( V_53 & V_56 ) {
if ( V_38 ) {
if ( F_12 ( V_1 , V_282 , & V_25 ) )
return - 9 ;
fprintf ( V_115 , L_219 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_127 : L_131 ) ;
F_86 ( V_1 , V_25 , L_220 ) ;
}
}
if ( V_53 & V_57 ) {
if ( V_38 ) {
if ( F_12 ( V_1 , V_283 , & V_25 ) )
return - 8 ;
fprintf ( V_115 , L_221 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_284 , & V_25 ) )
return - 9 ;
fprintf ( V_115 , L_222 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_127 : L_131 ) ;
F_86 ( V_1 , V_25 , L_223 ) ;
}
}
return 0 ;
}
int F_88 ( unsigned int V_239 , unsigned int V_240 )
{
if ( ! V_242 )
return 0 ;
switch ( V_240 ) {
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
return 1 ;
}
return 0 ;
}
int F_89 ( unsigned int V_239 , unsigned int V_240 )
{
if ( ! V_242 )
return 0 ;
switch ( V_240 ) {
case 0x45 :
case 0x3D :
case 0x4E :
case 0x5E :
return 1 ;
}
return 0 ;
}
int F_90 ( unsigned int V_239 , unsigned int V_240 )
{
if ( ! V_242 )
return 0 ;
switch ( V_240 ) {
case 0x4E :
case 0x5E :
return 1 ;
}
return 0 ;
}
int F_91 ( unsigned int V_239 , unsigned int V_240 )
{
if ( ! V_242 )
return 0 ;
switch ( V_240 ) {
case 0x37 :
case 0x4D :
return 1 ;
}
return 0 ;
}
int F_92 ( unsigned int V_239 , unsigned int V_240 )
{
if ( ! V_242 )
return 0 ;
switch ( V_240 ) {
case 0x57 :
return 1 ;
}
return 0 ;
}
unsigned int F_93 ( unsigned int V_239 , unsigned int V_240 )
{
if ( F_92 ( V_239 , V_240 ) )
return 1024 ;
return 1 ;
}
double F_94 ( void )
{
unsigned long long V_25 = 3 ;
unsigned int V_175 ;
double V_285 ;
if ( F_12 ( V_163 , V_286 , & V_25 ) )
fprintf ( V_115 , L_224 ) ;
V_175 = V_25 & 0xf ;
if ( V_175 >= V_287 ) {
fprintf ( V_115 , L_225 , V_175 ) ;
V_25 = 3 ;
}
V_285 = V_288 [ V_175 ] ;
fprintf ( V_115 , L_226 , V_285 ) ;
return V_285 ;
}
double F_95 ( unsigned int V_239 , unsigned int V_240 )
{
if ( F_88 ( V_239 , V_240 ) )
return 100.00 ;
else if ( F_91 ( V_239 , V_240 ) )
return F_94 () ;
else
return 133.33 ;
}
int F_96 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_289 ;
int V_1 ;
if ( ! ( V_45 || V_46 ) )
return 0 ;
if ( ! ( V_18 -> V_61 & V_98 ) || ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_115 , L_94 , V_1 ) ;
return - 1 ;
}
if ( V_290 != 0 ) {
V_143 = V_290 ;
fprintf ( V_115 , L_227 ,
V_1 , V_143 ) ;
return 0 ;
}
if ( ! V_249 )
goto V_291;
if ( F_12 ( V_163 , V_292 , & V_25 ) )
goto V_291;
V_289 = ( V_25 >> 16 ) & 0xFF ;
if ( V_38 )
fprintf ( V_115 , L_228 ,
V_1 , V_25 , V_289 ) ;
if ( ! V_289 )
goto V_291;
V_143 = V_289 ;
return 0 ;
V_291:
V_143 = V_293 ;
fprintf ( V_115 , L_229 ,
V_1 , V_143 ) ;
return 0 ;
}
void F_97 ()
{
unsigned int V_294 , V_295 , V_296 , V_297 , V_298 ;
unsigned int V_299 , V_239 , V_240 , V_300 ;
V_294 = V_295 = V_296 = V_297 = 0 ;
F_98 ( 0 , & V_298 , & V_295 , & V_296 , & V_297 ) ;
if ( V_295 == 0x756e6547 && V_297 == 0x49656e69 && V_296 == 0x6c65746e )
V_242 = 1 ;
if ( V_38 )
fprintf ( V_115 , L_230 ,
( char * ) & V_295 , ( char * ) & V_297 , ( char * ) & V_296 ) ;
F_98 ( 1 , & V_299 , & V_295 , & V_296 , & V_297 ) ;
V_239 = ( V_299 >> 8 ) & 0xf ;
V_240 = ( V_299 >> 4 ) & 0xf ;
V_300 = V_299 & 0xf ;
if ( V_239 == 6 || V_239 == 0xf )
V_240 += ( ( V_299 >> 16 ) & 0xf ) << 4 ;
if ( V_38 )
fprintf ( V_115 , L_231 ,
V_298 , V_239 , V_240 , V_300 , V_239 , V_240 , V_300 ) ;
if ( ! ( V_297 & ( 1 << 5 ) ) )
F_27 ( 1 , L_232 ) ;
V_295 = V_296 = V_297 = 0 ;
F_98 ( 0x80000000 , & V_298 , & V_295 , & V_296 , & V_297 ) ;
if ( V_298 >= 0x80000007 ) {
F_98 ( 0x80000007 , & V_294 , & V_295 , & V_296 , & V_297 ) ;
V_301 = V_297 & ( 1 << 8 ) ;
}
F_98 ( 0x6 , & V_294 , & V_295 , & V_296 , & V_297 ) ;
V_33 = V_296 & ( 1 << 0 ) ;
V_45 = V_294 & ( 1 << 0 ) ;
V_46 = V_294 & ( 1 << 6 ) ;
V_251 = V_296 & ( 1 << 3 ) ;
if ( V_38 )
fprintf ( V_115 , L_233 ,
V_33 ? L_127 : L_234 ,
V_45 ? L_127 : L_234 ,
V_46 ? L_127 : L_234 ,
V_251 ? L_127 : L_234 ) ;
if ( V_298 > 0x15 ) {
unsigned int V_302 ;
unsigned int V_303 ;
V_302 = V_303 = V_304 = V_297 = 0 ;
F_98 ( 0x15 , & V_302 , & V_303 , & V_304 , & V_297 ) ;
if ( V_303 != 0 ) {
if ( V_38 && ( V_295 != 0 ) )
fprintf ( V_115 , L_235 ,
V_302 , V_303 , V_304 ) ;
if ( V_304 == 0 )
switch( V_240 ) {
case 0x4E :
case 0x5E :
V_304 = 24000000 ;
break;
default:
V_304 = 0 ;
}
if ( V_304 ) {
V_167 = ( unsigned long long ) V_304 * V_303 / V_302 ;
if ( V_38 )
fprintf ( V_115 , L_236 ,
V_167 / 1000000 , V_304 , V_303 , V_302 ) ;
}
}
}
if ( V_33 )
V_135 = F_93 ( V_239 , V_240 ) ;
V_249 = V_41 = V_40 = F_71 ( V_239 , V_240 ) ;
V_44 = F_88 ( V_239 , V_240 ) ;
V_48 = V_44 && ( V_181 >= V_305 ) ;
V_49 = ( V_181 >= V_306 ) ;
V_50 = ( V_181 >= V_307 ) ;
V_51 = V_44 && ( V_181 >= V_308 ) ;
V_52 = F_89 ( V_239 , V_240 ) ;
V_47 = F_90 ( V_239 , V_240 ) ;
V_42 = F_91 ( V_239 , V_240 ) ;
V_43 = F_92 ( V_239 , V_240 ) ;
V_166 = F_95 ( V_239 , V_240 ) ;
F_82 ( V_239 , V_240 ) ;
F_83 ( V_239 , V_240 ) ;
if ( V_38 )
F_77 () ;
if ( F_90 ( V_239 , V_240 ) )
F_35 () ;
return;
}
void F_99 ()
{
fprintf ( V_115 ,
L_237
L_44
L_238
L_239
L_240
L_241
L_242
L_243
L_244
L_245
L_246
L_247
L_248
L_249
L_44
L_250 ) ;
}
int F_100 ( const struct V_309 * V_310 )
{
if ( isdigit ( V_310 -> V_311 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_101 ( int V_312 )
{
return 0 ;
}
void F_102 ()
{
int V_175 ;
int V_313 = 0 ;
int V_314 = 0 ;
int V_315 = 0 ;
struct V_316 {
int V_71 ;
int V_317 ;
} * V_318 ;
V_14 . V_118 = 0 ;
V_14 . V_212 = 0 ;
F_55 ( F_58 ) ;
if ( ! V_117 && V_14 . V_118 > 1 )
V_32 = 1 ;
if ( V_38 > 1 )
fprintf ( V_115 , L_251 , V_14 . V_118 , V_14 . V_212 ) ;
V_318 = calloc ( 1 , ( V_14 . V_212 + 1 ) * sizeof( struct V_316 ) ) ;
if ( V_318 == NULL )
F_14 ( 1 , L_252 ) ;
V_3 = F_103 ( ( V_14 . V_212 + 1 ) ) ;
if ( V_3 == NULL )
F_14 ( 3 , L_253 ) ;
V_2 = F_104 ( ( V_14 . V_212 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_55 ( F_59 ) ;
V_23 = F_103 ( ( V_14 . V_212 + 1 ) ) ;
if ( V_23 == NULL )
F_14 ( 3 , L_253 ) ;
V_22 = F_104 ( ( V_14 . V_212 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_175 = 0 ; V_175 <= V_14 . V_212 ; ++ V_175 ) {
int V_319 ;
if ( F_1 ( V_175 ) ) {
if ( V_38 > 1 )
fprintf ( V_115 , L_254 , V_175 ) ;
continue;
}
V_318 [ V_175 ] . V_71 = F_52 ( V_175 ) ;
if ( V_318 [ V_175 ] . V_71 > V_313 )
V_313 = V_318 [ V_175 ] . V_71 ;
V_318 [ V_175 ] . V_317 = F_51 ( V_175 ) ;
if ( V_318 [ V_175 ] . V_317 > V_314 )
V_314 = V_318 [ V_175 ] . V_317 ;
V_319 = F_53 ( V_175 ) ;
if ( V_319 > V_315 )
V_315 = V_319 ;
if ( V_38 > 1 )
fprintf ( V_115 , L_255 ,
V_175 , V_318 [ V_175 ] . V_317 , V_318 [ V_175 ] . V_71 ) ;
}
V_14 . V_16 = V_313 + 1 ;
if ( V_38 > 1 )
fprintf ( V_115 , L_256 ,
V_313 , V_14 . V_16 ) ;
if ( V_38 && ! V_117 && V_14 . V_16 > 1 )
V_31 = 1 ;
V_14 . V_15 = V_314 + 1 ;
if ( V_38 > 1 )
fprintf ( V_115 , L_257 ,
V_314 , V_14 . V_15 ) ;
if ( V_38 && ! V_117 && V_14 . V_15 > 1 )
V_29 = 1 ;
V_14 . V_17 = V_315 ;
if ( V_38 > 1 )
fprintf ( V_115 , L_258 , V_315 ) ;
free ( V_318 ) ;
}
void
F_105 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_175 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_175 = 0 ; V_175 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_175 ++ )
( * V_18 ) [ V_175 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_175 = 0 ; V_175 < V_14 . V_16 * V_14 . V_15 ; V_175 ++ )
( * V_19 ) [ V_175 ] . V_71 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_175 = 0 ; V_175 < V_14 . V_15 ; V_175 ++ )
( * V_20 ) [ V_175 ] . V_76 = V_175 ;
return;
error:
F_14 ( 1 , L_259 ) ;
}
void F_106 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_320 , int V_321 ,
int V_322 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_320 , V_321 , V_322 ) ;
V_19 = F_6 ( V_8 , V_321 , V_322 ) ;
V_20 = F_7 ( V_9 , V_322 ) ;
V_18 -> V_21 = V_21 ;
if ( V_320 == 0 ) {
V_18 -> V_61 |= V_98 ;
if ( F_50 ( V_21 ) )
V_18 -> V_61 |= V_100 ;
}
V_19 -> V_71 = V_321 ;
V_20 -> V_76 = V_322 ;
}
int F_107 ( int V_21 )
{
int V_323 , V_324 , V_325 ;
V_325 = F_51 ( V_21 ) ;
V_324 = F_52 ( V_21 ) ;
V_323 = F_49 ( V_21 ) ;
if ( ! V_323 )
V_14 . V_130 ++ ;
F_106 ( V_215 , V_323 , V_324 , V_325 , V_21 ) ;
F_106 ( V_219 , V_323 , V_324 , V_325 , V_21 ) ;
return 0 ;
}
void F_108 ()
{
V_114 = calloc ( 1 , ( 1 + V_14 . V_118 ) * 1024 ) ;
V_30 = V_114 ;
if ( V_30 == NULL )
F_14 ( - 1 , L_260 ) ;
}
void F_57 ( void )
{
F_102 () ;
F_105 ( & V_187 , & V_188 , & V_189 ) ;
F_105 ( & V_190 , & V_191 , & V_192 ) ;
F_108 () ;
F_55 ( F_107 ) ;
}
void F_109 ( void )
{
V_163 = F_110 () ;
if ( V_163 < 0 )
F_14 ( - V_326 , L_261 ) ;
if ( V_38 > 1 )
fprintf ( V_115 , L_262 , V_163 ) ;
}
void F_111 ()
{
F_57 () ;
F_109 () ;
F_64 () ;
F_65 () ;
F_97 () ;
if ( V_38 )
F_3 ( F_78 , V_219 ) ;
if ( V_38 )
F_3 ( F_79 , V_219 ) ;
if ( V_38 )
F_3 ( F_87 , V_219 ) ;
F_3 ( F_96 , V_219 ) ;
if ( V_38 )
F_3 ( F_84 , V_219 ) ;
}
int F_112 ( char * * V_327 )
{
T_7 V_328 ;
int V_329 ;
V_329 = F_3 ( F_34 , V_215 ) ;
if ( V_329 )
exit ( V_329 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_61 ( & V_216 , (struct V_217 * ) NULL ) ;
V_328 = F_113 () ;
if ( ! V_328 ) {
F_114 ( V_327 [ 0 ] , V_327 ) ;
} else {
if ( V_328 == - 1 )
F_14 ( 1 , L_263 ) ;
signal ( V_330 , V_331 ) ;
signal ( V_332 , V_331 ) ;
if ( F_115 ( V_328 , & V_329 , 0 ) == - 1 )
F_14 ( V_329 , L_264 ) ;
}
F_3 ( F_34 , V_219 ) ;
F_61 ( & V_220 , (struct V_217 * ) NULL ) ;
F_63 ( & V_220 , & V_216 , & V_101 ) ;
F_54 ( F_28 , V_219 , V_215 ) ;
F_32 ( V_215 ) ;
F_22 ( V_215 ) ;
F_21 () ;
fprintf ( V_115 , L_265 , V_101 . V_102 + V_101 . V_103 / 1000000.0 ) ;
return V_329 ;
}
int F_116 ( void )
{
int V_329 ;
V_329 = F_3 ( F_34 , V_219 ) ;
if ( V_329 )
return V_329 ;
V_329 = F_3 ( F_18 , V_219 ) ;
if ( V_329 )
return V_329 ;
F_20 () ;
return V_329 ;
}
void F_117 () {
fprintf ( V_115 , L_266
L_267 ) ;
}
void F_118 ( int V_333 , char * * V_327 )
{
int V_334 ;
int V_335 = 0 ;
static struct V_336 V_337 [] = {
{ L_268 , V_338 , 0 , 'C' } ,
{ L_269 , V_338 , 0 , 'c' } ,
{ L_270 , V_339 , 0 , 'D' } ,
{ L_271 , V_339 , 0 , 'd' } ,
{ L_272 , V_338 , 0 , 'i' } ,
{ L_273 , V_339 , 0 , 'h' } ,
{ L_274 , V_339 , 0 , 'J' } ,
{ L_275 , V_338 , 0 , 'M' } ,
{ L_276 , V_338 , 0 , 'm' } ,
{ L_277 , V_339 , 0 , 'p' } ,
{ L_278 , V_339 , 0 , 'p' } ,
{ L_279 , V_339 , 0 , 'S' } ,
{ L_280 , V_338 , 0 , 'T' } ,
{ L_281 , V_339 , 0 , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
V_125 = V_327 [ 0 ] ;
while ( ( V_334 = F_119 ( V_333 , V_327 , L_282 ,
V_337 , & V_335 ) ) != - 1 ) {
switch ( V_334 ) {
case 'C' :
sscanf ( V_340 , L_283 , & V_35 ) ;
break;
case 'c' :
sscanf ( V_340 , L_283 , & V_34 ) ;
break;
case 'D' :
V_341 ++ ;
break;
case 'd' :
V_38 ++ ;
break;
case 'h' :
default:
F_99 () ;
exit ( 1 ) ;
case 'i' :
V_218 = atoi ( V_340 ) ;
break;
case 'J' :
V_54 ++ ;
break;
case 'M' :
sscanf ( V_340 , L_283 , & V_37 ) ;
break;
case 'm' :
sscanf ( V_340 , L_283 , & V_36 ) ;
break;
case 'P' :
V_99 ++ ;
break;
case 'p' :
V_97 ++ ;
break;
case 'S' :
V_117 ++ ;
break;
case 'T' :
V_290 = atoi ( V_340 ) ;
break;
case 'v' :
F_117 () ;
exit ( 0 ) ;
break;
}
}
}
int main ( int V_333 , char * * V_327 )
{
F_118 ( V_333 , V_327 ) ;
if ( V_38 )
F_117 () ;
F_111 () ;
if ( V_341 )
return F_116 () ;
if ( V_333 - V_342 )
return F_112 ( V_327 + V_342 ) ;
else
F_60 () ;
return 0 ;
}
