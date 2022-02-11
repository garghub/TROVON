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
V_30 += sprintf ( V_30 , L_81 , 100.0 * V_18 -> V_64 / V_18 -> V_62 ) ;
else
V_30 += sprintf ( V_30 , L_82 ) ;
}
if ( V_33 )
V_30 += sprintf ( V_30 , L_80 ,
1.0 * V_18 -> V_62 / V_106 * V_18 -> V_63 / V_18 -> V_64 / V_95 ) ;
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
if ( ! V_108 )
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
if ( V_95 < V_109 )
V_96 = L_81 ;
else
V_96 = L_86 ;
if ( V_53 && ! V_54 ) {
if ( V_53 & V_55 )
V_30 += sprintf ( V_30 , V_96 , V_20 -> V_88 * V_110 / V_95 ) ;
if ( V_53 & V_56 )
V_30 += sprintf ( V_30 , V_96 , V_20 -> V_89 * V_110 / V_95 ) ;
if ( V_53 & V_57 )
V_30 += sprintf ( V_30 , V_96 , V_20 -> V_90 * V_110 / V_95 ) ;
if ( V_53 & V_58 )
V_30 += sprintf ( V_30 , V_96 , V_20 -> V_91 * V_111 / V_95 ) ;
if ( V_53 & V_59 )
V_30 += sprintf ( V_30 , V_96 , 100.0 * V_20 -> V_92 * V_112 / V_95 ) ;
if ( V_53 & V_60 )
V_30 += sprintf ( V_30 , V_96 , 100.0 * V_20 -> V_93 * V_112 / V_95 ) ;
} else if ( V_53 && V_54 ) {
if ( V_53 & V_55 )
V_30 += sprintf ( V_30 , V_96 ,
V_20 -> V_88 * V_110 ) ;
if ( V_53 & V_56 )
V_30 += sprintf ( V_30 , V_96 ,
V_20 -> V_89 * V_110 ) ;
if ( V_53 & V_57 )
V_30 += sprintf ( V_30 , V_96 ,
V_20 -> V_90 * V_110 ) ;
if ( V_53 & V_58 )
V_30 += sprintf ( V_30 , V_96 ,
V_20 -> V_91 * V_111 ) ;
if ( V_53 & V_59 )
V_30 += sprintf ( V_30 , V_96 , 100.0 * V_20 -> V_92 * V_112 / V_95 ) ;
if ( V_53 & V_60 )
V_30 += sprintf ( V_30 , V_96 , 100.0 * V_20 -> V_93 * V_112 / V_95 ) ;
V_30 += sprintf ( V_30 , V_96 , V_95 ) ;
}
V_39:
V_30 += sprintf ( V_30 , L_44 ) ;
return 0 ;
}
void F_20 ()
{
fputs ( V_113 , stdout ) ;
fflush ( stdout ) ;
V_30 = V_113 ;
}
void F_21 ()
{
fputs ( V_113 , V_114 ) ;
V_30 = V_113 ;
}
void F_22 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_115 ;
if ( ! V_115 || ! V_116 )
F_17 () ;
if ( V_14 . V_117 > 1 )
F_19 ( & V_104 . V_105 , & V_104 . V_118 ,
& V_104 . V_119 ) ;
V_115 = 1 ;
if ( V_116 )
return;
F_3 ( F_19 , V_18 , V_19 , V_20 ) ;
}
void
F_23 ( struct V_6 * V_120 , struct V_6 * V_121 )
{
if ( V_47 ) {
V_121 -> V_77 = V_120 -> V_77 - V_121 -> V_77 ;
V_121 -> V_78 = V_120 -> V_78 - V_121 -> V_78 ;
V_121 -> V_79 = V_120 -> V_79 - V_121 -> V_79 ;
V_121 -> V_80 = V_120 -> V_80 - V_121 -> V_80 ;
}
V_121 -> V_81 = V_120 -> V_81 - V_121 -> V_81 ;
if ( V_49 )
V_121 -> V_82 = V_120 -> V_82 - V_121 -> V_82 ;
if ( V_50 )
V_121 -> V_83 = V_120 -> V_83 - V_121 -> V_83 ;
if ( V_51 )
V_121 -> V_84 = V_120 -> V_84 - V_121 -> V_84 ;
V_121 -> V_85 = V_120 -> V_85 - V_121 -> V_85 ;
V_121 -> V_86 = V_120 -> V_86 - V_121 -> V_86 ;
V_121 -> V_87 = V_120 -> V_87 - V_121 -> V_87 ;
V_121 -> V_94 = V_120 -> V_94 ;
F_24 ( V_120 -> V_88 , V_121 -> V_88 ) ;
F_24 ( V_120 -> V_89 , V_121 -> V_89 ) ;
F_24 ( V_120 -> V_90 , V_121 -> V_90 ) ;
F_24 ( V_120 -> V_91 , V_121 -> V_91 ) ;
F_24 ( V_120 -> V_92 , V_121 -> V_92 ) ;
F_24 ( V_120 -> V_93 , V_121 -> V_93 ) ;
}
void
F_25 ( struct V_5 * V_120 , struct V_5 * V_121 )
{
V_121 -> V_72 = V_120 -> V_72 - V_121 -> V_72 ;
V_121 -> V_73 = V_120 -> V_73 - V_121 -> V_73 ;
V_121 -> V_74 = V_120 -> V_74 - V_121 -> V_74 ;
V_121 -> V_75 = V_120 -> V_75 ;
}
void
F_26 ( struct V_4 * V_120 , struct V_4 * V_121 ,
struct V_5 * V_122 )
{
V_121 -> V_62 = V_120 -> V_62 - V_121 -> V_62 ;
if ( V_121 -> V_62 < ( 1000 * 1000 ) )
F_27 ( - 3 , L_87
L_88
L_89 ) ;
V_121 -> V_65 = V_120 -> V_65 - V_121 -> V_65 ;
if ( V_33 ) {
if ( ( V_120 -> V_63 > V_121 -> V_63 ) && ( V_120 -> V_64 > V_121 -> V_64 ) ) {
V_121 -> V_63 = V_120 -> V_63 - V_121 -> V_63 ;
V_121 -> V_64 = V_120 -> V_64 - V_121 -> V_64 ;
} else {
if ( ! V_123 ) {
fprintf ( V_114 , L_90 , V_124 ) ;
fprintf ( V_114 , L_91 ) ;
fprintf ( V_114 , L_92 ) ;
V_123 = 1 ;
}
V_107 = 1 ;
V_108 = 1 ;
}
}
if ( V_125 ) {
} else {
if ( ( V_121 -> V_64 + V_122 -> V_72 + V_122 -> V_73 + V_122 -> V_74 ) > V_121 -> V_62 )
V_121 -> V_65 = 0 ;
else {
V_121 -> V_65 = V_121 -> V_62 - V_121 -> V_64 - V_122 -> V_72
- V_122 -> V_73 - V_122 -> V_74 ;
}
}
if ( V_121 -> V_64 == 0 ) {
if ( V_38 > 1 ) fprintf ( V_114 , L_93 , V_121 -> V_21 ) ;
V_121 -> V_64 = 1 ;
}
V_121 -> V_66 = V_120 -> V_66 - V_121 -> V_66 ;
V_121 -> V_66 &= 0xFFFFFFFF ;
V_121 -> V_67 = V_120 -> V_67 - V_121 -> V_67 ;
V_121 -> V_68 = V_120 -> V_68 ;
V_121 -> V_69 = V_120 -> V_69 ;
if ( V_40 )
V_121 -> V_70 = V_120 -> V_70 - V_121 -> V_70 ;
}
int F_28 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_126 ,
struct V_5 * V_127 , struct V_6 * V_128 )
{
if ( V_18 -> V_61 & V_98 )
F_25 ( V_19 , V_127 ) ;
F_26 ( V_18 , V_126 , V_127 ) ;
if ( V_18 -> V_61 & V_100 )
F_23 ( V_20 , V_128 ) ;
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
V_104 . V_118 . V_72 += V_19 -> V_72 ;
V_104 . V_118 . V_73 += V_19 -> V_73 ;
V_104 . V_118 . V_74 += V_19 -> V_74 ;
V_104 . V_118 . V_75 = F_31 ( V_104 . V_118 . V_75 , V_19 -> V_75 ) ;
if ( ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
if ( V_47 ) {
V_104 . V_119 . V_77 += V_20 -> V_77 ;
V_104 . V_119 . V_78 += V_20 -> V_78 ;
V_104 . V_119 . V_79 += V_20 -> V_79 ;
V_104 . V_119 . V_80 += V_20 -> V_80 ;
}
V_104 . V_119 . V_81 += V_20 -> V_81 ;
if ( V_49 )
V_104 . V_119 . V_82 += V_20 -> V_82 ;
if ( V_50 )
V_104 . V_119 . V_83 += V_20 -> V_83 ;
if ( V_51 )
V_104 . V_119 . V_84 += V_20 -> V_84 ;
V_104 . V_119 . V_85 += V_20 -> V_85 ;
V_104 . V_119 . V_86 += V_20 -> V_86 ;
V_104 . V_119 . V_87 += V_20 -> V_87 ;
V_104 . V_119 . V_88 += V_20 -> V_88 ;
V_104 . V_119 . V_91 += V_20 -> V_91 ;
V_104 . V_119 . V_89 += V_20 -> V_89 ;
V_104 . V_119 . V_90 += V_20 -> V_90 ;
V_104 . V_119 . V_94 = F_31 ( V_104 . V_119 . V_94 , V_20 -> V_94 ) ;
V_104 . V_119 . V_92 += V_20 -> V_92 ;
V_104 . V_119 . V_93 += V_20 -> V_93 ;
return 0 ;
}
void F_32 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_29 ( & V_104 . V_105 , & V_104 . V_118 , & V_104 . V_119 ) ;
F_3 ( F_30 , V_18 , V_19 , V_20 ) ;
V_104 . V_105 . V_62 /= V_14 . V_117 ;
V_104 . V_105 . V_63 /= V_14 . V_117 ;
V_104 . V_105 . V_64 /= V_14 . V_117 ;
V_104 . V_105 . V_65 /= V_14 . V_117 ;
V_104 . V_105 . V_66 /= V_14 . V_117 ;
V_104 . V_105 . V_66 &= 0xFFFFFFFF ;
V_104 . V_105 . V_67 /= V_14 . V_117 ;
V_104 . V_118 . V_72 /= V_14 . V_129 ;
V_104 . V_118 . V_73 /= V_14 . V_129 ;
V_104 . V_118 . V_74 /= V_14 . V_129 ;
if ( V_47 ) {
V_104 . V_119 . V_77 /= V_14 . V_15 ;
V_104 . V_119 . V_78 /= V_14 . V_15 ;
V_104 . V_119 . V_79 /= V_14 . V_15 ;
V_104 . V_119 . V_80 /= V_14 . V_15 ;
}
V_104 . V_119 . V_81 /= V_14 . V_15 ;
if ( V_49 )
V_104 . V_119 . V_82 /= V_14 . V_15 ;
if ( V_50 )
V_104 . V_119 . V_83 /= V_14 . V_15 ;
if ( V_51 )
V_104 . V_119 . V_84 /= V_14 . V_15 ;
V_104 . V_119 . V_85 /= V_14 . V_15 ;
V_104 . V_119 . V_86 /= V_14 . V_15 ;
V_104 . V_119 . V_87 /= V_14 . V_15 ;
}
static unsigned long long F_33 ( void )
{
unsigned int V_130 , V_131 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_130 | ( ( unsigned long long ) V_131 ) << 32 ;
}
int F_34 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
unsigned long long V_25 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_114 , L_94 , V_1 ) ;
return - 1 ;
}
V_18 -> V_62 = F_33 () ;
if ( V_33 ) {
if ( F_12 ( V_1 , V_132 , & V_18 -> V_63 ) )
return - 3 ;
if ( F_12 ( V_1 , V_133 , & V_18 -> V_64 ) )
return - 4 ;
}
if ( V_40 ) {
if ( F_12 ( V_1 , V_134 , & V_25 ) )
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
if ( V_125 ) {
if ( F_12 ( V_1 , V_135 , & V_18 -> V_65 ) )
return - 6 ;
}
if ( ! ( V_18 -> V_61 & V_98 ) )
return 0 ;
if ( V_41 && ! V_42 && ! V_43 ) {
if ( F_12 ( V_1 , V_136 , & V_19 -> V_72 ) )
return - 6 ;
}
if ( V_41 && ! V_43 ) {
if ( F_12 ( V_1 , V_137 , & V_19 -> V_73 ) )
return - 7 ;
} else if ( V_43 ) {
if ( F_12 ( V_1 , V_138 , & V_19 -> V_73 ) )
return - 7 ;
}
if ( V_44 )
if ( F_12 ( V_1 , V_139 , & V_19 -> V_74 ) )
return - 8 ;
if ( V_45 ) {
if ( F_12 ( V_1 , V_140 , & V_25 ) )
return - 9 ;
V_19 -> V_75 = V_141 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
if ( ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
if ( V_47 ) {
if ( F_12 ( V_1 , V_142 , & V_20 -> V_77 ) )
return - 10 ;
if ( F_12 ( V_1 , V_143 , & V_20 -> V_78 ) )
return - 11 ;
if ( F_12 ( V_1 , V_144 , & V_20 -> V_79 ) )
return - 12 ;
if ( F_12 ( V_1 , V_145 , & V_20 -> V_80 ) )
return - 13 ;
}
if ( V_49 )
if ( F_12 ( V_1 , V_146 , & V_20 -> V_82 ) )
return - 9 ;
if ( V_50 )
if ( F_12 ( V_1 , V_147 , & V_20 -> V_83 ) )
return - 10 ;
if ( V_48 )
if ( F_12 ( V_1 , V_148 , & V_20 -> V_81 ) )
return - 11 ;
if ( V_51 )
if ( F_12 ( V_1 , V_149 , & V_20 -> V_84 ) )
return - 12 ;
if ( V_52 ) {
if ( F_12 ( V_1 , V_150 , & V_20 -> V_85 ) )
return - 13 ;
if ( F_12 ( V_1 , V_151 , & V_20 -> V_86 ) )
return - 13 ;
if ( F_12 ( V_1 , V_152 , & V_20 -> V_87 ) )
return - 13 ;
}
if ( V_53 & V_55 ) {
if ( F_12 ( V_1 , V_153 , & V_25 ) )
return - 13 ;
V_20 -> V_88 = V_25 & 0xFFFFFFFF ;
}
if ( V_53 & V_56 ) {
if ( F_12 ( V_1 , V_154 , & V_25 ) )
return - 14 ;
V_20 -> V_89 = V_25 & 0xFFFFFFFF ;
}
if ( V_53 & V_58 ) {
if ( F_12 ( V_1 , V_155 , & V_25 ) )
return - 15 ;
V_20 -> V_91 = V_25 & 0xFFFFFFFF ;
}
if ( V_53 & V_57 ) {
if ( F_12 ( V_1 , V_156 , & V_25 ) )
return - 16 ;
V_20 -> V_90 = V_25 & 0xFFFFFFFF ;
}
if ( V_53 & V_59 ) {
if ( F_12 ( V_1 , V_157 , & V_25 ) )
return - 16 ;
V_20 -> V_92 = V_25 & 0xFFFFFFFF ;
}
if ( V_53 & V_60 ) {
if ( F_12 ( V_1 , V_158 , & V_25 ) )
return - 16 ;
V_20 -> V_93 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 ) {
if ( F_12 ( V_1 , V_159 , & V_25 ) )
return - 17 ;
V_20 -> V_94 = V_141 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
return 0 ;
}
static void
F_35 ( void )
{
unsigned long long V_25 ;
unsigned int V_160 ;
F_12 ( V_161 , V_162 , & V_25 ) ;
fprintf ( V_114 , L_95 , V_25 ) ;
V_160 = ( V_25 >> 40 ) & 0xFF ;
fprintf ( V_114 , L_96 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 8 ) & 0xFF ;
fprintf ( V_114 , L_97 ,
V_160 , V_163 , V_160 * V_163 ) ;
F_12 ( V_161 , V_164 , & V_25 ) ;
fprintf ( V_114 , L_98 ,
V_25 , V_25 & 0x2 ? L_99 : L_100 ) ;
return;
}
static void
F_36 ( void )
{
unsigned long long V_25 ;
unsigned int V_160 ;
F_12 ( V_161 , V_165 , & V_25 ) ;
fprintf ( V_114 , L_101 , V_25 ) ;
V_160 = ( V_25 >> 8 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_102 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 0 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_103 ,
V_160 , V_163 , V_160 * V_163 ) ;
return;
}
static void
F_37 ( void )
{
unsigned long long V_25 ;
unsigned int V_160 ;
F_12 ( V_161 , V_166 , & V_25 ) ;
fprintf ( V_114 , L_104 , V_25 ) ;
V_160 = ( V_25 >> 56 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_105 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 48 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_106 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 40 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_107 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 32 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_108 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 24 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_109 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 16 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_110 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 8 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_111 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 0 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_112 ,
V_160 , V_163 , V_160 * V_163 ) ;
return;
}
static void
F_38 ( void )
{
unsigned long long V_25 ;
unsigned int V_160 ;
F_12 ( V_161 , V_167 , & V_25 ) ;
fprintf ( V_114 , L_113 , V_25 ) ;
V_160 = ( V_25 >> 56 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_114 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 48 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_115 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 40 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_116 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 32 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_117 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 24 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_118 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 16 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_119 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 8 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_120 ,
V_160 , V_163 , V_160 * V_163 ) ;
V_160 = ( V_25 >> 0 ) & 0xFF ;
if ( V_160 )
fprintf ( V_114 , L_121 ,
V_160 , V_163 , V_160 * V_163 ) ;
return;
}
static void
F_39 ( void )
{
int V_118 ;
unsigned int V_160 ;
unsigned long long V_25 ;
int V_168 ;
int V_169 ;
int V_170 ;
F_12 ( V_161 , V_171 , & V_25 ) ;
fprintf ( V_114 , L_122 ,
V_25 ) ;
V_118 = V_25 & 0xFF ;
V_160 = ( V_25 >> 8 ) && 0xFF ;
if ( V_160 > 0 )
fprintf ( V_114 ,
L_123 ,
V_160 , V_163 , V_160 * V_163 , V_118 ) ;
for ( V_170 = 16 ; V_170 < 64 ; V_170 = V_170 + 8 ) {
V_168 = ( V_25 >> V_170 ) & 0x1F ;
V_169 = ( V_25 >> ( V_170 + 5 ) ) && 0x7 ;
if ( ! V_168 || ! V_169 )
return;
V_118 = V_118 + V_168 ;
V_160 = V_160 - V_169 ;
if ( V_160 > 0 )
fprintf ( V_114 ,
L_123 ,
V_160 , V_163 , V_160 * V_163 , V_118 ) ;
}
}
static void
F_40 ( void )
{
unsigned long long V_25 ;
F_12 ( V_161 , V_172 , & V_25 ) ;
#define F_41 (1UL << 27)
#define F_42 (1UL << 28)
fprintf ( V_114 , L_124 , V_25 ) ;
fprintf ( V_114 , L_125 ,
( V_25 & F_42 ) ? L_126 : L_127 ,
( V_25 & F_41 ) ? L_128 : L_127 ,
( V_25 & V_173 ) ? L_129 : L_127 ,
( V_25 & V_174 ) ? L_130 : L_127 ,
( V_25 & ( 1 << 15 ) ) ? L_127 : L_131 ,
( unsigned int ) V_25 & 7 ,
V_175 [ V_176 ] ) ;
return;
}
void F_43 ( void )
{
F_44 ( V_3 ) ;
V_3 = NULL ;
V_3 = 0 ;
F_44 ( V_23 ) ;
V_23 = NULL ;
V_22 = 0 ;
free ( V_177 ) ;
free ( V_178 ) ;
free ( V_179 ) ;
V_177 = NULL ;
V_178 = NULL ;
V_179 = NULL ;
free ( V_180 ) ;
free ( V_181 ) ;
free ( V_182 ) ;
V_180 = NULL ;
V_181 = NULL ;
V_182 = NULL ;
free ( V_113 ) ;
V_113 = NULL ;
V_30 = NULL ;
}
T_3 * F_45 ( const char * V_183 , const char * V_184 )
{
T_3 * V_185 = fopen ( V_183 , L_132 ) ;
if ( ! V_185 )
F_14 ( 1 , L_133 , V_183 ) ;
return V_185 ;
}
int F_46 ( const char * V_186 , ... )
{
T_4 args ;
char V_183 [ V_187 ] ;
T_3 * V_185 ;
int V_188 ;
va_start ( args , V_186 ) ;
vsnprintf ( V_183 , sizeof( V_183 ) , V_186 , args ) ;
va_end ( args ) ;
V_185 = F_45 ( V_183 , L_132 ) ;
if ( fscanf ( V_185 , L_134 , & V_188 ) != 1 )
F_14 ( 1 , L_135 , V_183 ) ;
fclose ( V_185 ) ;
return V_188 ;
}
int F_47 ( int V_1 )
{
char V_183 [ 64 ] ;
T_3 * V_185 ;
int V_189 ;
char V_190 ;
int V_170 ;
sprintf ( V_183 ,
L_136 ,
V_1 ) ;
V_185 = fopen ( V_183 , L_132 ) ;
if ( V_185 == NULL ) {
perror ( V_183 ) ;
exit ( 1 ) ;
}
for ( V_170 = 0 ; V_170 < V_14 . V_17 ; V_170 ++ ) {
fscanf ( V_185 , L_134 , & V_189 ) ;
if ( V_189 == V_1 ) {
fclose ( V_185 ) ;
return V_170 ;
}
if ( V_170 != ( V_14 . V_17 - 1 ) )
fscanf ( V_185 , L_137 , & V_190 ) ;
}
fclose ( V_185 ) ;
return - 1 ;
}
int F_48 ( int V_1 )
{
return V_1 == F_46 ( L_138 , V_1 ) ;
}
int F_49 ( int V_1 )
{
return F_46 ( L_139 , V_1 ) ;
}
int F_50 ( int V_1 )
{
return F_46 ( L_140 , V_1 ) ;
}
int F_51 ( int V_1 )
{
char V_183 [ 80 ] ;
T_3 * V_185 ;
int V_191 ;
int V_192 = 0 ;
char V_190 ;
char V_193 [ 100 ] ;
char * V_194 ;
sprintf ( V_183 , L_136 , V_1 ) ;
V_185 = F_45 ( V_183 , L_132 ) ;
fscanf ( V_185 , L_141 , & V_191 , & V_190 ) ;
fseek ( V_185 , 0 , V_195 ) ;
fgets ( V_193 , 100 , V_185 ) ;
V_194 = strchr ( V_193 , V_190 ) ;
while ( V_194 != NULL ) {
V_192 ++ ;
V_194 = strchr ( V_194 + 1 , V_190 ) ;
}
fclose ( V_185 ) ;
return V_192 + 1 ;
}
int F_52 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_196 , struct V_5 * V_197 ,
struct V_6 * V_198 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_126 ;
struct V_5 * V_19 , * V_127 ;
struct V_6 * V_20 , * V_128 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_126 = F_5 ( V_196 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_127 = F_6 ( V_197 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_128 = F_7 ( V_198 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_126 , V_127 , V_128 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_53 ( int (F_4)( int ) )
{
T_3 * V_199 ;
int V_200 ;
int V_10 ;
V_199 = F_45 ( V_201 , L_132 ) ;
V_10 = fscanf ( V_199 , L_142 ) ;
if ( V_10 != 0 )
F_14 ( 1 , L_143 , V_201 ) ;
while ( 1 ) {
V_10 = fscanf ( V_199 , L_144 , & V_200 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_200 ) ;
if ( V_10 ) {
fclose ( V_199 ) ;
return ( V_10 ) ;
}
}
fclose ( V_199 ) ;
return 0 ;
}
void F_54 ( void )
{
F_43 () ;
F_55 () ;
printf ( L_145 , V_14 . V_117 ) ;
}
int F_56 ( int V_1 )
{
if ( V_14 . V_202 < V_1 )
V_14 . V_202 = V_1 ;
V_14 . V_117 += 1 ;
return 0 ;
}
int F_57 ( int V_1 )
{
F_10 ( V_1 , V_2 , V_3 ) ;
return 0 ;
}
void F_58 ()
{
int V_10 ;
int V_203 = 0 ;
V_204:
V_203 ++ ;
V_10 = F_3 ( F_34 , V_205 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
if ( V_203 > 1 ) {
exit ( V_10 ) ;
}
F_54 () ;
goto V_204;
}
V_203 = 0 ;
F_59 ( & V_206 , (struct V_207 * ) NULL ) ;
while ( 1 ) {
if ( F_53 ( F_1 ) ) {
F_54 () ;
goto V_204;
}
F_60 ( V_208 ) ;
V_10 = F_3 ( F_34 , V_209 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_54 () ;
goto V_204;
}
F_59 ( & V_210 , (struct V_207 * ) NULL ) ;
F_61 ( & V_210 , & V_206 , & V_101 ) ;
F_52 ( F_28 , V_209 , V_205 ) ;
F_32 ( V_205 ) ;
F_22 ( V_205 ) ;
F_20 () ;
F_60 ( V_208 ) ;
V_10 = F_3 ( F_34 , V_205 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_54 () ;
goto V_204;
}
F_59 ( & V_206 , (struct V_207 * ) NULL ) ;
F_61 ( & V_206 , & V_210 , & V_101 ) ;
F_52 ( F_28 , V_205 , V_209 ) ;
F_32 ( V_209 ) ;
F_22 ( V_209 ) ;
F_20 () ;
}
}
void F_62 ()
{
struct V_211 V_212 ;
char V_26 [ 32 ] ;
sprintf ( V_26 , L_1 , V_161 ) ;
if ( V_211 ( V_26 , & V_212 ) )
if ( system ( L_146 ) )
F_14 ( - 5 , L_147 ) ;
}
void F_63 ()
{
struct V_213 V_214 ;
T_5 V_215 = & V_214 ;
struct V_216 V_217 ;
T_6 V_218 = & V_217 ;
extern int V_219 ( T_5 V_220 , T_6 V_221 ) ;
int V_222 = 0 ;
char V_26 [ 32 ] ;
V_215 -> V_223 = F_64 () ;
V_215 -> V_224 = V_225 ;
if ( V_219 ( V_215 , V_218 ) < 0 )
F_14 ( - 6 , L_148 ) ;
if ( ( V_218 -> V_226 & ( 1 << V_227 ) ) == 0 ) {
V_222 ++ ;
F_65 ( L_149
L_150 , V_124 ) ;
}
sprintf ( V_26 , L_1 , V_161 ) ;
if ( F_66 ( V_26 , V_228 ) ) {
V_222 ++ ;
F_67 ( L_151 ) ;
}
if ( V_222 )
if ( F_68 () != 0 )
F_65 ( L_152 ) ;
if ( V_222 )
exit ( - 6 ) ;
}
int F_69 ( unsigned int V_229 , unsigned int V_230 )
{
unsigned long long V_25 ;
int * V_231 ;
if ( ! V_232 )
return 0 ;
if ( V_229 != 6 )
return 0 ;
switch ( V_230 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x25 :
case 0x2C :
case 0x2E :
case 0x2F :
V_231 = V_233 ;
break;
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
V_231 = V_234 ;
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
V_231 = V_235 ;
break;
case 0x37 :
case 0x4D :
V_231 = V_236 ;
break;
case 0x4C :
V_231 = V_237 ;
break;
case 0x57 :
V_231 = V_238 ;
break;
default:
return 0 ;
}
F_12 ( V_161 , V_172 , & V_25 ) ;
V_176 = V_231 [ V_25 & 0xF ] ;
return 1 ;
}
int F_70 ( unsigned int V_229 , unsigned int V_230 )
{
switch ( V_230 ) {
case 0x2E :
case 0x2F :
return 0 ;
default:
return 1 ;
}
}
int F_71 ( unsigned int V_229 , unsigned int V_230 )
{
if ( ! V_232 )
return 0 ;
if ( V_229 != 6 )
return 0 ;
switch ( V_230 ) {
case 0x3E :
case 0x3F :
return 1 ;
default:
return 0 ;
}
}
int F_72 ( unsigned int V_229 , unsigned int V_230 )
{
if ( ! V_232 )
return 0 ;
if ( V_229 != 6 )
return 0 ;
switch ( V_230 ) {
case 0x3F :
return 1 ;
default:
return 0 ;
}
}
int F_73 ( unsigned int V_229 , unsigned int V_230 )
{
if ( ! V_232 )
return 0 ;
if ( V_229 != 6 )
return 0 ;
switch ( V_230 ) {
case 0x57 :
return 1 ;
default:
return 0 ;
}
}
static void
F_74 ( V_229 , V_230 )
{
if ( ! V_239 )
return;
F_35 () ;
if ( F_72 ( V_229 , V_230 ) )
F_36 () ;
if ( F_71 ( V_229 , V_230 ) )
F_37 () ;
if ( F_70 ( V_229 , V_230 ) )
F_38 () ;
if ( F_73 ( V_229 , V_230 ) )
F_39 () ;
F_40 () ;
}
int F_75 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
char * V_240 ;
int V_1 ;
if ( ! V_241 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_61 & V_98 ) || ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_114 , L_94 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_242 , & V_25 ) )
return 0 ;
switch ( V_25 & 0xF ) {
case V_243 :
V_240 = L_153 ;
break;
case V_244 :
V_240 = L_154 ;
break;
case V_245 :
V_240 = L_155 ;
break;
default:
V_240 = L_156 ;
break;
}
fprintf ( V_114 , L_157 , V_1 , V_25 , V_240 ) ;
return 0 ;
}
int F_76 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_61 & V_98 ) || ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_114 , L_94 , V_1 ) ;
return - 1 ;
}
if ( V_246 ) {
F_12 ( V_1 , V_247 , & V_25 ) ;
fprintf ( V_114 , L_158 , V_1 , V_25 ) ;
fprintf ( V_114 , L_159 ,
( V_25 & 1 << 15 ) ? L_160 : L_127 ,
( V_25 & 1 << 14 ) ? L_161 : L_127 ,
( V_25 & 1 << 13 ) ? L_162 : L_127 ,
( V_25 & 1 << 12 ) ? L_163 : L_127 ,
( V_25 & 1 << 11 ) ? L_164 : L_127 ,
( V_25 & 1 << 10 ) ? L_165 : L_127 ,
( V_25 & 1 << 9 ) ? L_166 : L_127 ,
( V_25 & 1 << 8 ) ? L_167 : L_127 ,
( V_25 & 1 << 6 ) ? L_168 : L_127 ,
( V_25 & 1 << 5 ) ? L_169 : L_127 ,
( V_25 & 1 << 4 ) ? L_170 : L_127 ,
( V_25 & 1 << 2 ) ? L_171 : L_127 ,
( V_25 & 1 << 1 ) ? L_172 : L_127 ,
( V_25 & 1 << 0 ) ? L_173 : L_127 ) ;
fprintf ( V_114 , L_174 ,
( V_25 & 1 << 31 ) ? L_175 : L_127 ,
( V_25 & 1 << 30 ) ? L_176 : L_127 ,
( V_25 & 1 << 29 ) ? L_162 : L_127 ,
( V_25 & 1 << 28 ) ? L_163 : L_127 ,
( V_25 & 1 << 27 ) ? L_164 : L_127 ,
( V_25 & 1 << 26 ) ? L_165 : L_127 ,
( V_25 & 1 << 25 ) ? L_166 : L_127 ,
( V_25 & 1 << 24 ) ? L_167 : L_127 ,
( V_25 & 1 << 22 ) ? L_168 : L_127 ,
( V_25 & 1 << 21 ) ? L_169 : L_127 ,
( V_25 & 1 << 20 ) ? L_170 : L_127 ,
( V_25 & 1 << 18 ) ? L_177 : L_127 ,
( V_25 & 1 << 17 ) ? L_172 : L_127 ,
( V_25 & 1 << 16 ) ? L_173 : L_127 ) ;
}
if ( V_248 ) {
F_12 ( V_1 , V_249 , & V_25 ) ;
fprintf ( V_114 , L_178 , V_1 , V_25 ) ;
fprintf ( V_114 , L_179 ,
( V_25 & 1 << 0 ) ? L_173 : L_127 ,
( V_25 & 1 << 1 ) ? L_172 : L_127 ,
( V_25 & 1 << 4 ) ? L_170 : L_127 ,
( V_25 & 1 << 6 ) ? L_168 : L_127 ,
( V_25 & 1 << 8 ) ? L_167 : L_127 ,
( V_25 & 1 << 9 ) ? L_180 : L_127 ,
( V_25 & 1 << 10 ) ? L_165 : L_127 ,
( V_25 & 1 << 11 ) ? L_164 : L_127 ) ;
fprintf ( V_114 , L_181 ,
( V_25 & 1 << 16 ) ? L_173 : L_127 ,
( V_25 & 1 << 17 ) ? L_172 : L_127 ,
( V_25 & 1 << 20 ) ? L_170 : L_127 ,
( V_25 & 1 << 22 ) ? L_168 : L_127 ,
( V_25 & 1 << 24 ) ? L_167 : L_127 ,
( V_25 & 1 << 25 ) ? L_180 : L_127 ,
( V_25 & 1 << 26 ) ? L_165 : L_127 ,
( V_25 & 1 << 27 ) ? L_164 : L_127 ) ;
}
if ( V_250 ) {
F_12 ( V_1 , V_251 , & V_25 ) ;
fprintf ( V_114 , L_182 , V_1 , V_25 ) ;
fprintf ( V_114 , L_183 ,
( V_25 & 1 << 0 ) ? L_173 : L_127 ,
( V_25 & 1 << 1 ) ? L_172 : L_127 ,
( V_25 & 1 << 6 ) ? L_168 : L_127 ,
( V_25 & 1 << 8 ) ? L_167 : L_127 ,
( V_25 & 1 << 10 ) ? L_165 : L_127 ,
( V_25 & 1 << 11 ) ? L_164 : L_127 ) ;
fprintf ( V_114 , L_184 ,
( V_25 & 1 << 16 ) ? L_173 : L_127 ,
( V_25 & 1 << 17 ) ? L_172 : L_127 ,
( V_25 & 1 << 22 ) ? L_168 : L_127 ,
( V_25 & 1 << 24 ) ? L_167 : L_127 ,
( V_25 & 1 << 26 ) ? L_165 : L_127 ,
( V_25 & 1 << 27 ) ? L_164 : L_127 ) ;
}
return 0 ;
}
double F_77 ( V_230 )
{
unsigned long long V_25 ;
if ( V_53 & V_252 )
if ( ! F_12 ( V_161 , V_253 , & V_25 ) )
return ( ( V_25 >> 0 ) & V_254 ) * V_255 ;
switch ( V_230 ) {
case 0x37 :
case 0x4D :
return 30.0 ;
default:
return 135.0 ;
}
}
static double
F_78 ( int V_230 , double V_110 )
{
switch ( V_230 ) {
case 0x3F :
case 0x4F :
case 0x56 :
case 0x57 :
return ( V_111 = 15.3 / 1000000 ) ;
default:
return ( V_110 ) ;
}
}
void F_79 ( unsigned int V_229 , unsigned int V_230 )
{
unsigned long long V_25 ;
unsigned int V_256 ;
double V_257 ;
if ( ! V_232 )
return;
if ( V_229 != 6 )
return;
switch ( V_230 ) {
case 0x2A :
case 0x3A :
case 0x3C :
case 0x45 :
case 0x46 :
case 0x3D :
case 0x47 :
V_53 = V_55 | V_56 | V_258 | V_57 | V_252 ;
break;
case 0x4E :
case 0x5E :
V_53 = V_55 | V_58 | V_60 | V_59 | V_252 ;
break;
case 0x3F :
case 0x4F :
case 0x56 :
case 0x57 :
V_53 = V_55 | V_58 | V_259 | V_60 | V_59 | V_252 ;
break;
case 0x2D :
case 0x3E :
V_53 = V_55 | V_56 | V_258 | V_58 | V_259 | V_59 | V_60 | V_252 ;
break;
case 0x37 :
case 0x4D :
V_53 = V_55 | V_56 ;
break;
default:
return;
}
if ( F_12 ( V_161 , V_260 , & V_25 ) )
return;
V_255 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
if ( V_230 == 0x37 )
V_110 = 1.0 * ( 1 << ( V_25 >> 8 & 0x1F ) ) / 1000000 ;
else
V_110 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_111 = F_78 ( V_230 , V_110 ) ;
V_256 = V_25 >> 16 & 0xF ;
if ( V_256 == 0 )
V_256 = 0xA ;
V_112 = 1.0 / ( 1 << ( V_256 ) ) ;
V_257 = F_77 ( V_230 ) ;
V_109 = 0xFFFFFFFF * V_110 / V_257 ;
if ( V_38 )
fprintf ( V_114 , L_185 , V_109 , V_257 ) ;
return;
}
void F_80 ( V_229 , V_230 )
{
if ( ! V_232 )
return;
if ( V_229 != 6 )
return;
switch ( V_230 ) {
case 0x3C :
case 0x45 :
case 0x46 :
V_248 = 1 ;
case 0x3F :
V_246 = 1 ;
V_250 = 1 ;
default:
return;
}
}
int F_81 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_261 ;
int V_1 ;
if ( ! ( V_45 || V_46 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_61 & V_98 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_114 , L_94 , V_1 ) ;
return - 1 ;
}
if ( V_46 && ( V_18 -> V_61 & V_100 ) ) {
if ( F_12 ( V_1 , V_159 , & V_25 ) )
return 0 ;
V_261 = ( V_25 >> 16 ) & 0x7F ;
fprintf ( V_114 , L_186 ,
V_1 , V_25 , V_141 - V_261 ) ;
#ifdef F_82
if ( F_12 ( V_1 , V_262 , & V_25 ) )
return 0 ;
V_261 = ( V_25 >> 16 ) & 0x7F ;
V_263 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_114 , L_187 ,
V_1 , V_25 , V_141 - V_261 , V_141 - V_263 ) ;
#endif
}
if ( V_45 ) {
unsigned int V_264 ;
if ( F_12 ( V_1 , V_140 , & V_25 ) )
return 0 ;
V_261 = ( V_25 >> 16 ) & 0x7F ;
V_264 = ( V_25 >> 27 ) & 0xF ;
fprintf ( V_114 , L_188 ,
V_1 , V_25 , V_141 - V_261 , V_264 ) ;
#ifdef F_82
if ( F_12 ( V_1 , V_265 , & V_25 ) )
return 0 ;
V_261 = ( V_25 >> 16 ) & 0x7F ;
V_263 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_114 , L_189 ,
V_1 , V_25 , V_141 - V_261 , V_141 - V_263 ) ;
#endif
}
return 0 ;
}
void F_83 ( int V_1 , unsigned long long V_25 , char * V_266 )
{
fprintf ( V_114 , L_190 ,
V_1 , V_266 ,
( ( V_25 >> 15 ) & 1 ) ? L_99 : L_100 ,
( ( V_25 >> 0 ) & 0x7FFF ) * V_255 ,
( 1.0 + ( ( ( V_25 >> 22 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 17 ) & 0x1F ) ) * V_112 ,
( ( ( V_25 >> 16 ) & 1 ) ? L_99 : L_100 ) ) ;
return;
}
int F_84 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
if ( ! V_53 )
return 0 ;
if ( ! ( V_18 -> V_61 & V_98 ) || ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_114 , L_94 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_260 , & V_25 ) )
return - 1 ;
if ( V_38 ) {
fprintf ( V_114 , L_191
L_192 , V_1 , V_25 ,
V_255 , V_110 , V_112 ) ;
}
if ( V_53 & V_252 ) {
if ( F_12 ( V_1 , V_253 , & V_25 ) )
return - 5 ;
fprintf ( V_114 , L_193 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_254 ) * V_255 ,
( ( V_25 >> 16 ) & V_254 ) * V_255 ,
( ( V_25 >> 32 ) & V_254 ) * V_255 ,
( ( V_25 >> 48 ) & V_267 ) * V_112 ) ;
}
if ( V_53 & V_55 ) {
if ( F_12 ( V_1 , V_268 , & V_25 ) )
return - 9 ;
fprintf ( V_114 , L_194 ,
V_1 , V_25 , ( V_25 >> 63 ) & 1 ? L_127 : L_131 ) ;
F_83 ( V_1 , V_25 , L_195 ) ;
fprintf ( V_114 , L_196 ,
V_1 ,
( ( V_25 >> 47 ) & 1 ) ? L_99 : L_100 ,
( ( V_25 >> 32 ) & 0x7FFF ) * V_255 ,
( 1.0 + ( ( ( V_25 >> 54 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 49 ) & 0x1F ) ) * V_112 ,
( ( V_25 >> 48 ) & 1 ) ? L_99 : L_100 ) ;
}
if ( V_53 & V_259 ) {
if ( F_12 ( V_1 , V_269 , & V_25 ) )
return - 6 ;
fprintf ( V_114 , L_197 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_254 ) * V_255 ,
( ( V_25 >> 16 ) & V_254 ) * V_255 ,
( ( V_25 >> 32 ) & V_254 ) * V_255 ,
( ( V_25 >> 48 ) & V_267 ) * V_112 ) ;
}
if ( V_53 & V_58 ) {
if ( F_12 ( V_1 , V_270 , & V_25 ) )
return - 9 ;
fprintf ( V_114 , L_198 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_127 : L_131 ) ;
F_83 ( V_1 , V_25 , L_199 ) ;
}
if ( V_53 & V_258 ) {
if ( V_38 ) {
if ( F_12 ( V_1 , V_271 , & V_25 ) )
return - 7 ;
fprintf ( V_114 , L_200 , V_1 , V_25 & 0xF ) ;
}
}
if ( V_53 & V_56 ) {
if ( V_38 ) {
if ( F_12 ( V_1 , V_272 , & V_25 ) )
return - 9 ;
fprintf ( V_114 , L_201 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_127 : L_131 ) ;
F_83 ( V_1 , V_25 , L_202 ) ;
}
}
if ( V_53 & V_57 ) {
if ( V_38 ) {
if ( F_12 ( V_1 , V_273 , & V_25 ) )
return - 8 ;
fprintf ( V_114 , L_203 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_274 , & V_25 ) )
return - 9 ;
fprintf ( V_114 , L_204 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_127 : L_131 ) ;
F_83 ( V_1 , V_25 , L_205 ) ;
}
}
return 0 ;
}
int F_85 ( unsigned int V_229 , unsigned int V_230 )
{
if ( ! V_232 )
return 0 ;
switch ( V_230 ) {
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
int F_86 ( unsigned int V_229 , unsigned int V_230 )
{
if ( ! V_232 )
return 0 ;
switch ( V_230 ) {
case 0x45 :
case 0x3D :
case 0x4E :
case 0x5E :
return 1 ;
}
return 0 ;
}
int F_87 ( unsigned int V_229 , unsigned int V_230 )
{
if ( ! V_232 )
return 0 ;
switch ( V_230 ) {
case 0x4E :
case 0x5E :
return 1 ;
}
return 0 ;
}
int F_88 ( unsigned int V_229 , unsigned int V_230 )
{
if ( ! V_232 )
return 0 ;
switch ( V_230 ) {
case 0x37 :
case 0x4D :
return 1 ;
}
return 0 ;
}
int F_89 ( unsigned int V_229 , unsigned int V_230 )
{
if ( ! V_232 )
return 0 ;
switch ( V_230 ) {
case 0x57 :
return 1 ;
}
return 0 ;
}
double F_90 ( void )
{
unsigned long long V_25 = 3 ;
unsigned int V_170 ;
double V_275 ;
if ( F_12 ( V_161 , V_276 , & V_25 ) )
fprintf ( V_114 , L_206 ) ;
V_170 = V_25 & 0xf ;
if ( V_170 >= V_277 ) {
fprintf ( V_114 , L_207 , V_170 ) ;
V_25 = 3 ;
}
V_275 = V_278 [ V_170 ] ;
fprintf ( V_114 , L_208 , V_275 ) ;
return V_275 ;
}
double F_91 ( unsigned int V_229 , unsigned int V_230 )
{
if ( F_85 ( V_229 , V_230 ) )
return 100.00 ;
else if ( F_88 ( V_229 , V_230 ) )
return F_90 () ;
else
return 133.33 ;
}
int F_92 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_279 ;
int V_1 ;
if ( ! ( V_45 || V_46 ) )
return 0 ;
if ( ! ( V_18 -> V_61 & V_98 ) || ! ( V_18 -> V_61 & V_100 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_114 , L_94 , V_1 ) ;
return - 1 ;
}
if ( V_280 != 0 ) {
V_141 = V_280 ;
fprintf ( V_114 , L_209 ,
V_1 , V_141 ) ;
return 0 ;
}
if ( ! V_239 )
goto V_281;
if ( F_12 ( V_161 , V_282 , & V_25 ) )
goto V_281;
V_279 = ( V_25 >> 16 ) & 0xFF ;
if ( V_38 )
fprintf ( V_114 , L_210 ,
V_1 , V_25 , V_279 ) ;
if ( ! V_279 )
goto V_281;
V_141 = V_279 ;
return 0 ;
V_281:
V_141 = V_283 ;
fprintf ( V_114 , L_211 ,
V_1 , V_141 ) ;
return 0 ;
}
void F_93 ()
{
unsigned int V_284 , V_285 , V_286 , V_287 , V_288 ;
unsigned int V_289 , V_229 , V_230 , V_290 ;
V_284 = V_285 = V_286 = V_287 = 0 ;
F_94 ( 0 , & V_288 , & V_285 , & V_286 , & V_287 ) ;
if ( V_285 == 0x756e6547 && V_287 == 0x49656e69 && V_286 == 0x6c65746e )
V_232 = 1 ;
if ( V_38 )
fprintf ( V_114 , L_212 ,
( char * ) & V_285 , ( char * ) & V_287 , ( char * ) & V_286 ) ;
F_94 ( 1 , & V_289 , & V_285 , & V_286 , & V_287 ) ;
V_229 = ( V_289 >> 8 ) & 0xf ;
V_230 = ( V_289 >> 4 ) & 0xf ;
V_290 = V_289 & 0xf ;
if ( V_229 == 6 || V_229 == 0xf )
V_230 += ( ( V_289 >> 16 ) & 0xf ) << 4 ;
if ( V_38 )
fprintf ( V_114 , L_213 ,
V_288 , V_229 , V_230 , V_290 , V_229 , V_230 , V_290 ) ;
if ( ! ( V_287 & ( 1 << 5 ) ) )
F_27 ( 1 , L_214 ) ;
V_285 = V_286 = V_287 = 0 ;
F_94 ( 0x80000000 , & V_288 , & V_285 , & V_286 , & V_287 ) ;
if ( V_288 >= 0x80000007 ) {
F_94 ( 0x80000007 , & V_284 , & V_285 , & V_286 , & V_287 ) ;
V_291 = V_287 & ( 1 << 8 ) ;
}
F_94 ( 0x6 , & V_284 , & V_285 , & V_286 , & V_287 ) ;
V_33 = V_286 & ( 1 << 0 ) ;
V_45 = V_284 & ( 1 << 0 ) ;
V_46 = V_284 & ( 1 << 6 ) ;
V_241 = V_286 & ( 1 << 3 ) ;
if ( V_38 )
fprintf ( V_114 , L_215 ,
V_33 ? L_127 : L_216 ,
V_45 ? L_127 : L_216 ,
V_46 ? L_127 : L_216 ,
V_241 ? L_127 : L_216 ) ;
if ( V_288 > 0x15 ) {
unsigned int V_292 ;
unsigned int V_293 ;
V_292 = V_293 = V_294 = V_287 = 0 ;
F_94 ( 0x15 , & V_292 , & V_293 , & V_294 , & V_287 ) ;
if ( V_293 != 0 ) {
if ( V_38 && ( V_285 != 0 ) )
fprintf ( V_114 , L_217 ,
V_292 , V_293 , V_294 ) ;
if ( V_294 == 0 )
switch( V_230 ) {
case 0x4E :
case 0x5E :
V_294 = 24000000 ;
break;
default:
V_294 = 0 ;
}
if ( V_294 ) {
V_295 = ( unsigned long long ) V_294 * V_293 / V_292 ;
if ( V_38 )
fprintf ( V_114 , L_218 ,
V_295 / 1000000 , V_294 , V_293 , V_292 ) ;
}
}
}
V_239 = V_41 = V_40 = F_69 ( V_229 , V_230 ) ;
V_44 = F_85 ( V_229 , V_230 ) ;
V_48 = V_44 && ( V_176 >= V_296 ) ;
V_49 = ( V_176 >= V_297 ) ;
V_50 = ( V_176 >= V_298 ) ;
V_51 = V_44 && ( V_176 >= V_299 ) ;
V_52 = F_86 ( V_229 , V_230 ) ;
V_47 = F_87 ( V_229 , V_230 ) ;
V_42 = F_88 ( V_229 , V_230 ) ;
V_43 = F_89 ( V_229 , V_230 ) ;
V_163 = F_91 ( V_229 , V_230 ) ;
F_79 ( V_229 , V_230 ) ;
F_80 ( V_229 , V_230 ) ;
if ( V_38 )
F_74 () ;
return;
}
void F_95 ()
{
fprintf ( V_114 ,
L_219
L_44
L_220
L_221
L_222
L_223
L_224
L_225
L_226
L_227
L_228
L_229
L_230
L_231
L_44
L_232 ) ;
}
int F_96 ( const struct V_300 * V_301 )
{
if ( isdigit ( V_301 -> V_302 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_97 ( int V_303 )
{
return 0 ;
}
void F_98 ()
{
int V_170 ;
int V_304 = 0 ;
int V_305 = 0 ;
int V_306 = 0 ;
struct V_307 {
int V_71 ;
int V_308 ;
} * V_309 ;
V_14 . V_117 = 0 ;
V_14 . V_202 = 0 ;
F_53 ( F_56 ) ;
if ( ! V_116 && V_14 . V_117 > 1 )
V_32 = 1 ;
if ( V_38 > 1 )
fprintf ( V_114 , L_233 , V_14 . V_117 , V_14 . V_202 ) ;
V_309 = calloc ( 1 , ( V_14 . V_202 + 1 ) * sizeof( struct V_307 ) ) ;
if ( V_309 == NULL )
F_14 ( 1 , L_234 ) ;
V_3 = F_99 ( ( V_14 . V_202 + 1 ) ) ;
if ( V_3 == NULL )
F_14 ( 3 , L_235 ) ;
V_2 = F_100 ( ( V_14 . V_202 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_53 ( F_57 ) ;
V_23 = F_99 ( ( V_14 . V_202 + 1 ) ) ;
if ( V_23 == NULL )
F_14 ( 3 , L_235 ) ;
V_22 = F_100 ( ( V_14 . V_202 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_170 = 0 ; V_170 <= V_14 . V_202 ; ++ V_170 ) {
int V_310 ;
if ( F_1 ( V_170 ) ) {
if ( V_38 > 1 )
fprintf ( V_114 , L_236 , V_170 ) ;
continue;
}
V_309 [ V_170 ] . V_71 = F_50 ( V_170 ) ;
if ( V_309 [ V_170 ] . V_71 > V_304 )
V_304 = V_309 [ V_170 ] . V_71 ;
V_309 [ V_170 ] . V_308 = F_49 ( V_170 ) ;
if ( V_309 [ V_170 ] . V_308 > V_305 )
V_305 = V_309 [ V_170 ] . V_308 ;
V_310 = F_51 ( V_170 ) ;
if ( V_310 > V_306 )
V_306 = V_310 ;
if ( V_38 > 1 )
fprintf ( V_114 , L_237 ,
V_170 , V_309 [ V_170 ] . V_308 , V_309 [ V_170 ] . V_71 ) ;
}
V_14 . V_16 = V_304 + 1 ;
if ( V_38 > 1 )
fprintf ( V_114 , L_238 ,
V_304 , V_14 . V_16 ) ;
if ( V_38 && ! V_116 && V_14 . V_16 > 1 )
V_31 = 1 ;
V_14 . V_15 = V_305 + 1 ;
if ( V_38 > 1 )
fprintf ( V_114 , L_239 ,
V_305 , V_14 . V_15 ) ;
if ( V_38 && ! V_116 && V_14 . V_15 > 1 )
V_29 = 1 ;
V_14 . V_17 = V_306 ;
if ( V_38 > 1 )
fprintf ( V_114 , L_240 , V_306 ) ;
free ( V_309 ) ;
}
void
F_101 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_170 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_170 = 0 ; V_170 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_170 ++ )
( * V_18 ) [ V_170 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_170 = 0 ; V_170 < V_14 . V_16 * V_14 . V_15 ; V_170 ++ )
( * V_19 ) [ V_170 ] . V_71 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_170 = 0 ; V_170 < V_14 . V_15 ; V_170 ++ )
( * V_20 ) [ V_170 ] . V_76 = V_170 ;
return;
error:
F_14 ( 1 , L_241 ) ;
}
void F_102 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_311 , int V_312 ,
int V_313 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_311 , V_312 , V_313 ) ;
V_19 = F_6 ( V_8 , V_312 , V_313 ) ;
V_20 = F_7 ( V_9 , V_313 ) ;
V_18 -> V_21 = V_21 ;
if ( V_311 == 0 ) {
V_18 -> V_61 |= V_98 ;
if ( F_48 ( V_21 ) )
V_18 -> V_61 |= V_100 ;
}
V_19 -> V_71 = V_312 ;
V_20 -> V_76 = V_313 ;
}
int F_103 ( int V_21 )
{
int V_314 , V_315 , V_316 ;
V_316 = F_49 ( V_21 ) ;
V_315 = F_50 ( V_21 ) ;
V_314 = F_47 ( V_21 ) ;
if ( ! V_314 )
V_14 . V_129 ++ ;
F_102 ( V_205 , V_314 , V_315 , V_316 , V_21 ) ;
F_102 ( V_209 , V_314 , V_315 , V_316 , V_21 ) ;
return 0 ;
}
void F_104 ()
{
V_113 = calloc ( 1 , ( 1 + V_14 . V_117 ) * 1024 ) ;
V_30 = V_113 ;
if ( V_30 == NULL )
F_14 ( - 1 , L_242 ) ;
}
void F_55 ( void )
{
F_98 () ;
F_101 ( & V_177 , & V_178 , & V_179 ) ;
F_101 ( & V_180 , & V_181 , & V_182 ) ;
F_104 () ;
F_53 ( F_103 ) ;
}
void F_105 ( void )
{
V_161 = F_106 () ;
if ( V_161 < 0 )
F_14 ( - V_317 , L_243 ) ;
if ( V_38 > 1 )
fprintf ( V_114 , L_244 , V_161 ) ;
}
void F_107 ()
{
F_55 () ;
F_105 () ;
F_62 () ;
F_63 () ;
F_93 () ;
if ( V_38 )
F_3 ( F_75 , V_209 ) ;
if ( V_38 )
F_3 ( F_76 , V_209 ) ;
if ( V_38 )
F_3 ( F_84 , V_209 ) ;
F_3 ( F_92 , V_209 ) ;
if ( V_38 )
F_3 ( F_81 , V_209 ) ;
}
int F_108 ( char * * V_318 )
{
T_7 V_319 ;
int V_320 ;
V_320 = F_3 ( F_34 , V_205 ) ;
if ( V_320 )
exit ( V_320 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_59 ( & V_206 , (struct V_207 * ) NULL ) ;
V_319 = F_109 () ;
if ( ! V_319 ) {
F_110 ( V_318 [ 0 ] , V_318 ) ;
} else {
if ( V_319 == - 1 )
F_14 ( 1 , L_245 ) ;
signal ( V_321 , V_322 ) ;
signal ( V_323 , V_322 ) ;
if ( F_111 ( V_319 , & V_320 , 0 ) == - 1 )
F_14 ( V_320 , L_246 ) ;
}
F_3 ( F_34 , V_209 ) ;
F_59 ( & V_210 , (struct V_207 * ) NULL ) ;
F_61 ( & V_210 , & V_206 , & V_101 ) ;
F_52 ( F_28 , V_209 , V_205 ) ;
F_32 ( V_205 ) ;
F_22 ( V_205 ) ;
F_21 () ;
fprintf ( V_114 , L_247 , V_101 . V_102 + V_101 . V_103 / 1000000.0 ) ;
return V_320 ;
}
int F_112 ( void )
{
int V_320 ;
V_320 = F_3 ( F_34 , V_209 ) ;
if ( V_320 )
return V_320 ;
V_320 = F_3 ( F_18 , V_209 ) ;
if ( V_320 )
return V_320 ;
F_20 () ;
return V_320 ;
}
void F_113 () {
fprintf ( V_114 , L_248
L_249 ) ;
}
void F_114 ( int V_324 , char * * V_318 )
{
int V_325 ;
int V_326 = 0 ;
static struct V_327 V_328 [] = {
{ L_250 , V_329 , 0 , 'C' } ,
{ L_251 , V_329 , 0 , 'c' } ,
{ L_252 , V_330 , 0 , 'D' } ,
{ L_253 , V_330 , 0 , 'd' } ,
{ L_254 , V_329 , 0 , 'i' } ,
{ L_255 , V_330 , 0 , 'h' } ,
{ L_256 , V_330 , 0 , 'J' } ,
{ L_257 , V_329 , 0 , 'M' } ,
{ L_258 , V_329 , 0 , 'm' } ,
{ L_259 , V_330 , 0 , 'p' } ,
{ L_260 , V_330 , 0 , 'p' } ,
{ L_261 , V_330 , 0 , 'S' } ,
{ L_262 , V_329 , 0 , 'T' } ,
{ L_263 , V_330 , 0 , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
V_124 = V_318 [ 0 ] ;
while ( ( V_325 = F_115 ( V_324 , V_318 , L_264 ,
V_328 , & V_326 ) ) != - 1 ) {
switch ( V_325 ) {
case 'C' :
sscanf ( V_331 , L_265 , & V_35 ) ;
break;
case 'c' :
sscanf ( V_331 , L_265 , & V_34 ) ;
break;
case 'D' :
V_332 ++ ;
break;
case 'd' :
V_38 ++ ;
break;
case 'h' :
default:
F_95 () ;
exit ( 1 ) ;
case 'i' :
V_208 = atoi ( V_331 ) ;
break;
case 'J' :
V_54 ++ ;
break;
case 'M' :
sscanf ( V_331 , L_265 , & V_37 ) ;
break;
case 'm' :
sscanf ( V_331 , L_265 , & V_36 ) ;
break;
case 'P' :
V_99 ++ ;
break;
case 'p' :
V_97 ++ ;
break;
case 'S' :
V_116 ++ ;
break;
case 'T' :
V_280 = atoi ( V_331 ) ;
break;
case 'v' :
F_113 () ;
exit ( 0 ) ;
break;
}
}
}
int main ( int V_324 , char * * V_318 )
{
F_114 ( V_324 , V_318 ) ;
if ( V_38 )
F_113 () ;
F_107 () ;
if ( V_332 )
return F_112 () ;
if ( V_324 - V_333 )
return F_108 ( V_318 + V_333 ) ;
else
F_58 () ;
return 0 ;
}
