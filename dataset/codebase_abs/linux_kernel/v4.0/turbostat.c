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
V_30 += sprintf ( V_30 , L_11 ) ;
if ( V_35 )
V_30 += sprintf ( V_30 , L_12 , V_35 ) ;
if ( V_36 )
V_30 += sprintf ( V_30 , L_13 , V_36 ) ;
if ( V_37 )
V_30 += sprintf ( V_30 , L_14 , V_37 ) ;
if ( V_38 )
V_30 += sprintf ( V_30 , L_15 , V_38 ) ;
if ( V_39 )
V_30 += sprintf ( V_30 , L_16 ) ;
if ( V_39 && ! V_40 )
V_30 += sprintf ( V_30 , L_17 ) ;
if ( V_39 )
V_30 += sprintf ( V_30 , L_18 ) ;
if ( V_41 )
V_30 += sprintf ( V_30 , L_19 ) ;
if ( V_42 )
V_30 += sprintf ( V_30 , L_20 ) ;
if ( V_43 )
V_30 += sprintf ( V_30 , L_21 ) ;
if ( V_44 )
V_30 += sprintf ( V_30 , L_22 ) ;
if ( V_45 )
V_30 += sprintf ( V_30 , L_23 ) ;
if ( V_46 )
V_30 += sprintf ( V_30 , L_24 ) ;
if ( V_47 )
V_30 += sprintf ( V_30 , L_25 ) ;
if ( V_48 ) {
V_30 += sprintf ( V_30 , L_26 ) ;
V_30 += sprintf ( V_30 , L_27 ) ;
V_30 += sprintf ( V_30 , L_28 ) ;
}
if ( V_49 && ! V_50 ) {
if ( V_49 & V_51 )
V_30 += sprintf ( V_30 , L_29 ) ;
if ( V_49 & V_52 )
V_30 += sprintf ( V_30 , L_30 ) ;
if ( V_49 & V_53 )
V_30 += sprintf ( V_30 , L_31 ) ;
if ( V_49 & V_54 )
V_30 += sprintf ( V_30 , L_32 ) ;
if ( V_49 & V_55 )
V_30 += sprintf ( V_30 , L_33 ) ;
if ( V_49 & V_56 )
V_30 += sprintf ( V_30 , L_34 ) ;
} else if ( V_49 && V_50 ) {
if ( V_49 & V_51 )
V_30 += sprintf ( V_30 , L_35 ) ;
if ( V_49 & V_52 )
V_30 += sprintf ( V_30 , L_36 ) ;
if ( V_49 & V_53 )
V_30 += sprintf ( V_30 , L_37 ) ;
if ( V_49 & V_54 )
V_30 += sprintf ( V_30 , L_38 ) ;
if ( V_49 & V_55 )
V_30 += sprintf ( V_30 , L_33 ) ;
if ( V_49 & V_56 )
V_30 += sprintf ( V_30 , L_34 ) ;
V_30 += sprintf ( V_30 , L_39 ) ;
}
V_30 += sprintf ( V_30 , L_40 ) ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_30 += sprintf ( V_30 , L_41 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
V_30 += sprintf ( V_30 , L_42 ,
V_18 -> V_21 , V_18 -> V_57 ) ;
V_30 += sprintf ( V_30 , L_43 , V_18 -> V_58 ) ;
V_30 += sprintf ( V_30 , L_44 , V_18 -> V_59 ) ;
V_30 += sprintf ( V_30 , L_45 , V_18 -> V_60 ) ;
V_30 += sprintf ( V_30 , L_46 , V_18 -> V_61 ) ;
V_30 += sprintf ( V_30 , L_47 ,
V_35 , V_18 -> V_62 ) ;
V_30 += sprintf ( V_30 , L_48 ,
V_36 , V_18 -> V_63 ) ;
V_30 += sprintf ( V_30 , L_47 ,
V_37 , V_18 -> V_64 ) ;
V_30 += sprintf ( V_30 , L_48 ,
V_38 , V_18 -> V_65 ) ;
if ( V_34 )
V_30 += sprintf ( V_30 , L_49 , V_18 -> V_66 ) ;
}
if ( V_19 ) {
V_30 += sprintf ( V_30 , L_50 , V_19 -> V_67 ) ;
V_30 += sprintf ( V_30 , L_51 , V_19 -> V_68 ) ;
V_30 += sprintf ( V_30 , L_52 , V_19 -> V_69 ) ;
V_30 += sprintf ( V_30 , L_53 , V_19 -> V_70 ) ;
V_30 += sprintf ( V_30 , L_54 , V_19 -> V_71 ) ;
}
if ( V_20 ) {
V_30 += sprintf ( V_30 , L_55 , V_20 -> V_72 ) ;
V_30 += sprintf ( V_30 , L_56 , V_20 -> V_73 ) ;
if ( V_45 )
V_30 += sprintf ( V_30 , L_57 , V_20 -> V_74 ) ;
if ( V_46 )
V_30 += sprintf ( V_30 , L_58 , V_20 -> V_75 ) ;
if ( V_47 )
V_30 += sprintf ( V_30 , L_59 , V_20 -> V_76 ) ;
V_30 += sprintf ( V_30 , L_60 , V_20 -> V_77 ) ;
V_30 += sprintf ( V_30 , L_61 , V_20 -> V_78 ) ;
V_30 += sprintf ( V_30 , L_62 , V_20 -> V_79 ) ;
V_30 += sprintf ( V_30 , L_63 , V_20 -> V_80 ) ;
V_30 += sprintf ( V_30 , L_64 , V_20 -> V_81 ) ;
V_30 += sprintf ( V_30 , L_65 , V_20 -> V_82 ) ;
V_30 += sprintf ( V_30 , L_66 , V_20 -> V_83 ) ;
V_30 += sprintf ( V_30 , L_67 ,
V_20 -> V_84 ) ;
V_30 += sprintf ( V_30 , L_68 ,
V_20 -> V_85 ) ;
V_30 += sprintf ( V_30 , L_69 , V_20 -> V_86 ) ;
}
V_30 += sprintf ( V_30 , L_40 ) ;
return 0 ;
}
int F_19 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_87 ;
char * V_88 ;
if ( V_89 && ! ( V_18 -> V_57 & V_90 ) )
return 0 ;
if ( V_91 && ! ( V_18 -> V_57 & V_92 ) )
return 0 ;
V_87 = V_93 . V_94 + V_93 . V_95 / 1000000.0 ;
if ( V_18 == & V_96 . V_97 ) {
if ( V_29 )
V_30 += sprintf ( V_30 , L_70 ) ;
if ( V_31 )
V_30 += sprintf ( V_30 , L_70 ) ;
if ( V_32 )
V_30 += sprintf ( V_30 , L_70 ) ;
} else {
if ( V_29 ) {
if ( V_20 )
V_30 += sprintf ( V_30 , L_71 , V_20 -> V_72 ) ;
else
V_30 += sprintf ( V_30 , L_70 ) ;
}
if ( V_31 ) {
if ( V_19 )
V_30 += sprintf ( V_30 , L_71 , V_19 -> V_67 ) ;
else
V_30 += sprintf ( V_30 , L_70 ) ;
}
if ( V_32 )
V_30 += sprintf ( V_30 , L_71 , V_18 -> V_21 ) ;
}
if ( V_33 )
V_30 += sprintf ( V_30 , L_72 ,
1.0 / V_98 * V_18 -> V_59 / V_87 ) ;
if ( V_33 ) {
if ( ! V_99 )
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_18 -> V_60 / V_18 -> V_58 ) ;
else
V_30 += sprintf ( V_30 , L_74 ) ;
}
if ( V_33 )
V_30 += sprintf ( V_30 , L_72 ,
1.0 * V_18 -> V_58 / V_98 * V_18 -> V_59 / V_18 -> V_60 / V_87 ) ;
V_30 += sprintf ( V_30 , L_72 , 1.0 * V_18 -> V_58 / V_98 / V_87 ) ;
if ( V_34 )
V_30 += sprintf ( V_30 , L_71 , V_18 -> V_66 ) ;
if ( V_35 )
V_30 += sprintf ( V_30 , L_75 , V_18 -> V_62 ) ;
if ( V_36 )
V_30 += sprintf ( V_30 , L_75 , V_18 -> V_63 ) ;
if ( V_37 )
V_30 += sprintf ( V_30 , L_76 , V_18 -> V_64 ) ;
if ( V_38 )
V_30 += sprintf ( V_30 , L_77 , V_18 -> V_65 ) ;
if ( V_39 ) {
if ( ! V_100 )
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_18 -> V_61 / V_18 -> V_58 ) ;
else
V_30 += sprintf ( V_30 , L_74 ) ;
}
if ( ! ( V_18 -> V_57 & V_90 ) )
goto V_101;
if ( V_39 && ! V_40 )
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_19 -> V_68 / V_18 -> V_58 ) ;
if ( V_39 )
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_19 -> V_69 / V_18 -> V_58 ) ;
if ( V_41 )
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_19 -> V_70 / V_18 -> V_58 ) ;
if ( V_42 )
V_30 += sprintf ( V_30 , L_71 , V_19 -> V_71 ) ;
if ( ! ( V_18 -> V_57 & V_92 ) )
goto V_101;
if ( V_43 )
V_30 += sprintf ( V_30 , L_71 , V_20 -> V_86 ) ;
if ( V_44 )
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_20 -> V_73 / V_18 -> V_58 ) ;
if ( V_45 )
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_20 -> V_74 / V_18 -> V_58 ) ;
if ( V_46 )
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_20 -> V_75 / V_18 -> V_58 ) ;
if ( V_47 )
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_20 -> V_76 / V_18 -> V_58 ) ;
if ( V_48 ) {
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_20 -> V_77 / V_18 -> V_58 ) ;
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_20 -> V_78 / V_18 -> V_58 ) ;
V_30 += sprintf ( V_30 , L_73 , 100.0 * V_20 -> V_79 / V_18 -> V_58 ) ;
}
if ( V_87 < V_102 )
V_88 = L_73 ;
else
V_88 = L_78 ;
if ( V_49 && ! V_50 ) {
if ( V_49 & V_51 )
V_30 += sprintf ( V_30 , V_88 , V_20 -> V_80 * V_103 / V_87 ) ;
if ( V_49 & V_52 )
V_30 += sprintf ( V_30 , V_88 , V_20 -> V_81 * V_103 / V_87 ) ;
if ( V_49 & V_53 )
V_30 += sprintf ( V_30 , V_88 , V_20 -> V_82 * V_103 / V_87 ) ;
if ( V_49 & V_54 )
V_30 += sprintf ( V_30 , V_88 , V_20 -> V_83 * V_103 / V_87 ) ;
if ( V_49 & V_55 )
V_30 += sprintf ( V_30 , V_88 , 100.0 * V_20 -> V_84 * V_104 / V_87 ) ;
if ( V_49 & V_56 )
V_30 += sprintf ( V_30 , V_88 , 100.0 * V_20 -> V_85 * V_104 / V_87 ) ;
} else if ( V_49 && V_50 ) {
if ( V_49 & V_51 )
V_30 += sprintf ( V_30 , V_88 ,
V_20 -> V_80 * V_103 ) ;
if ( V_49 & V_52 )
V_30 += sprintf ( V_30 , V_88 ,
V_20 -> V_81 * V_103 ) ;
if ( V_49 & V_53 )
V_30 += sprintf ( V_30 , V_88 ,
V_20 -> V_82 * V_103 ) ;
if ( V_49 & V_54 )
V_30 += sprintf ( V_30 , V_88 ,
V_20 -> V_83 * V_103 ) ;
if ( V_49 & V_55 )
V_30 += sprintf ( V_30 , V_88 , 100.0 * V_20 -> V_84 * V_104 / V_87 ) ;
if ( V_49 & V_56 )
V_30 += sprintf ( V_30 , V_88 , 100.0 * V_20 -> V_85 * V_104 / V_87 ) ;
V_30 += sprintf ( V_30 , V_88 , V_87 ) ;
}
V_101:
V_30 += sprintf ( V_30 , L_40 ) ;
return 0 ;
}
void F_20 ()
{
fputs ( V_105 , stdout ) ;
fflush ( stdout ) ;
V_30 = V_105 ;
}
void F_21 ()
{
fputs ( V_105 , V_106 ) ;
V_30 = V_105 ;
}
void F_22 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_107 ;
if ( ! V_107 || ! V_108 )
F_17 () ;
if ( V_14 . V_109 > 1 )
F_19 ( & V_96 . V_97 , & V_96 . V_110 ,
& V_96 . V_111 ) ;
V_107 = 1 ;
if ( V_108 )
return;
F_3 ( F_19 , V_18 , V_19 , V_20 ) ;
}
void
F_23 ( struct V_6 * V_112 , struct V_6 * V_113 )
{
V_113 -> V_73 = V_112 -> V_73 - V_113 -> V_73 ;
if ( V_45 )
V_113 -> V_74 = V_112 -> V_74 - V_113 -> V_74 ;
if ( V_46 )
V_113 -> V_75 = V_112 -> V_75 - V_113 -> V_75 ;
if ( V_47 )
V_113 -> V_76 = V_112 -> V_76 - V_113 -> V_76 ;
V_113 -> V_77 = V_112 -> V_77 - V_113 -> V_77 ;
V_113 -> V_78 = V_112 -> V_78 - V_113 -> V_78 ;
V_113 -> V_79 = V_112 -> V_79 - V_113 -> V_79 ;
V_113 -> V_86 = V_112 -> V_86 ;
F_24 ( V_112 -> V_80 , V_113 -> V_80 ) ;
F_24 ( V_112 -> V_81 , V_113 -> V_81 ) ;
F_24 ( V_112 -> V_82 , V_113 -> V_82 ) ;
F_24 ( V_112 -> V_83 , V_113 -> V_83 ) ;
F_24 ( V_112 -> V_84 , V_113 -> V_84 ) ;
F_24 ( V_112 -> V_85 , V_113 -> V_85 ) ;
}
void
F_25 ( struct V_5 * V_112 , struct V_5 * V_113 )
{
V_113 -> V_68 = V_112 -> V_68 - V_113 -> V_68 ;
V_113 -> V_69 = V_112 -> V_69 - V_113 -> V_69 ;
V_113 -> V_70 = V_112 -> V_70 - V_113 -> V_70 ;
V_113 -> V_71 = V_112 -> V_71 ;
}
void
F_26 ( struct V_4 * V_112 , struct V_4 * V_113 ,
struct V_5 * V_114 )
{
V_113 -> V_58 = V_112 -> V_58 - V_113 -> V_58 ;
if ( V_113 -> V_58 < ( 1000 * 1000 ) )
F_27 ( - 3 , L_79
L_80
L_81 ) ;
V_113 -> V_61 = V_112 -> V_61 - V_113 -> V_61 ;
if ( V_33 ) {
if ( ( V_112 -> V_59 > V_113 -> V_59 ) && ( V_112 -> V_60 > V_113 -> V_60 ) ) {
V_113 -> V_59 = V_112 -> V_59 - V_113 -> V_59 ;
V_113 -> V_60 = V_112 -> V_60 - V_113 -> V_60 ;
} else {
if ( ! V_115 ) {
fprintf ( V_106 , L_82 , V_116 ) ;
fprintf ( V_106 , L_83 ) ;
fprintf ( V_106 , L_84 ) ;
V_115 = 1 ;
}
V_99 = 1 ;
V_100 = 1 ;
}
}
if ( V_117 ) {
} else {
if ( ( V_113 -> V_60 + V_114 -> V_68 + V_114 -> V_69 + V_114 -> V_70 ) > V_113 -> V_58 )
V_113 -> V_61 = 0 ;
else {
V_113 -> V_61 = V_113 -> V_58 - V_113 -> V_60 - V_114 -> V_68
- V_114 -> V_69 - V_114 -> V_70 ;
}
}
if ( V_113 -> V_60 == 0 ) {
if ( V_118 > 1 ) fprintf ( V_106 , L_85 , V_113 -> V_21 ) ;
V_113 -> V_60 = 1 ;
}
V_113 -> V_62 = V_112 -> V_62 - V_113 -> V_62 ;
V_113 -> V_62 &= 0xFFFFFFFF ;
V_113 -> V_63 = V_112 -> V_63 - V_113 -> V_63 ;
V_113 -> V_64 = V_112 -> V_64 ;
V_113 -> V_65 = V_112 -> V_65 ;
if ( V_34 )
V_113 -> V_66 = V_112 -> V_66 - V_113 -> V_66 ;
}
int F_28 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_119 ,
struct V_5 * V_120 , struct V_6 * V_121 )
{
if ( V_18 -> V_57 & V_90 )
F_25 ( V_19 , V_120 ) ;
F_26 ( V_18 , V_119 , V_120 ) ;
if ( V_18 -> V_57 & V_92 )
F_23 ( V_20 , V_121 ) ;
return 0 ;
}
void F_29 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
V_18 -> V_58 = 0 ;
V_18 -> V_59 = 0 ;
V_18 -> V_60 = 0 ;
V_18 -> V_61 = 0 ;
V_18 -> V_66 = 0 ;
V_18 -> V_62 = 0 ;
V_18 -> V_63 = 0 ;
V_18 -> V_57 = V_90 | V_92 ;
V_19 -> V_68 = 0 ;
V_19 -> V_69 = 0 ;
V_19 -> V_70 = 0 ;
V_19 -> V_71 = 0 ;
V_20 -> V_73 = 0 ;
if ( V_45 )
V_20 -> V_74 = 0 ;
if ( V_46 )
V_20 -> V_75 = 0 ;
if ( V_47 )
V_20 -> V_76 = 0 ;
V_20 -> V_77 = 0 ;
V_20 -> V_78 = 0 ;
V_20 -> V_79 = 0 ;
V_20 -> V_80 = 0 ;
V_20 -> V_83 = 0 ;
V_20 -> V_81 = 0 ;
V_20 -> V_82 = 0 ;
V_20 -> V_84 = 0 ;
V_20 -> V_85 = 0 ;
V_20 -> V_86 = 0 ;
}
int F_30 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_96 . V_97 . V_58 += V_18 -> V_58 ;
V_96 . V_97 . V_59 += V_18 -> V_59 ;
V_96 . V_97 . V_60 += V_18 -> V_60 ;
V_96 . V_97 . V_61 += V_18 -> V_61 ;
V_96 . V_97 . V_62 += V_18 -> V_62 ;
V_96 . V_97 . V_63 += V_18 -> V_63 ;
if ( ! ( V_18 -> V_57 & V_90 ) )
return 0 ;
V_96 . V_110 . V_68 += V_19 -> V_68 ;
V_96 . V_110 . V_69 += V_19 -> V_69 ;
V_96 . V_110 . V_70 += V_19 -> V_70 ;
V_96 . V_110 . V_71 = F_31 ( V_96 . V_110 . V_71 , V_19 -> V_71 ) ;
if ( ! ( V_18 -> V_57 & V_92 ) )
return 0 ;
V_96 . V_111 . V_73 += V_20 -> V_73 ;
if ( V_45 )
V_96 . V_111 . V_74 += V_20 -> V_74 ;
if ( V_46 )
V_96 . V_111 . V_75 += V_20 -> V_75 ;
if ( V_47 )
V_96 . V_111 . V_76 += V_20 -> V_76 ;
V_96 . V_111 . V_77 += V_20 -> V_77 ;
V_96 . V_111 . V_78 += V_20 -> V_78 ;
V_96 . V_111 . V_79 += V_20 -> V_79 ;
V_96 . V_111 . V_80 += V_20 -> V_80 ;
V_96 . V_111 . V_83 += V_20 -> V_83 ;
V_96 . V_111 . V_81 += V_20 -> V_81 ;
V_96 . V_111 . V_82 += V_20 -> V_82 ;
V_96 . V_111 . V_86 = F_31 ( V_96 . V_111 . V_86 , V_20 -> V_86 ) ;
V_96 . V_111 . V_84 += V_20 -> V_84 ;
V_96 . V_111 . V_85 += V_20 -> V_85 ;
return 0 ;
}
void F_32 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_29 ( & V_96 . V_97 , & V_96 . V_110 , & V_96 . V_111 ) ;
F_3 ( F_30 , V_18 , V_19 , V_20 ) ;
V_96 . V_97 . V_58 /= V_14 . V_109 ;
V_96 . V_97 . V_59 /= V_14 . V_109 ;
V_96 . V_97 . V_60 /= V_14 . V_109 ;
V_96 . V_97 . V_61 /= V_14 . V_109 ;
V_96 . V_97 . V_62 /= V_14 . V_109 ;
V_96 . V_97 . V_62 &= 0xFFFFFFFF ;
V_96 . V_97 . V_63 /= V_14 . V_109 ;
V_96 . V_110 . V_68 /= V_14 . V_122 ;
V_96 . V_110 . V_69 /= V_14 . V_122 ;
V_96 . V_110 . V_70 /= V_14 . V_122 ;
V_96 . V_111 . V_73 /= V_14 . V_15 ;
if ( V_45 )
V_96 . V_111 . V_74 /= V_14 . V_15 ;
if ( V_46 )
V_96 . V_111 . V_75 /= V_14 . V_15 ;
if ( V_47 )
V_96 . V_111 . V_76 /= V_14 . V_15 ;
V_96 . V_111 . V_77 /= V_14 . V_15 ;
V_96 . V_111 . V_78 /= V_14 . V_15 ;
V_96 . V_111 . V_79 /= V_14 . V_15 ;
}
static unsigned long long F_33 ( void )
{
unsigned int V_123 , V_124 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_123 | ( ( unsigned long long ) V_124 ) << 32 ;
}
int F_34 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
unsigned long long V_25 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_106 , L_86 , V_1 ) ;
return - 1 ;
}
V_18 -> V_58 = F_33 () ;
if ( V_33 ) {
if ( F_12 ( V_1 , V_125 , & V_18 -> V_59 ) )
return - 3 ;
if ( F_12 ( V_1 , V_126 , & V_18 -> V_60 ) )
return - 4 ;
}
if ( V_34 ) {
if ( F_12 ( V_1 , V_127 , & V_25 ) )
return - 5 ;
V_18 -> V_66 = V_25 & 0xFFFFFFFF ;
}
if ( V_35 ) {
if ( F_12 ( V_1 , V_35 , & V_25 ) )
return - 5 ;
V_18 -> V_62 = V_25 & 0xFFFFFFFF ;
}
if ( V_36 )
if ( F_12 ( V_1 , V_36 , & V_18 -> V_63 ) )
return - 5 ;
if ( V_37 ) {
if ( F_12 ( V_1 , V_37 , & V_25 ) )
return - 5 ;
V_18 -> V_64 = V_25 & 0xFFFFFFFF ;
}
if ( V_38 )
if ( F_12 ( V_1 , V_38 , & V_18 -> V_65 ) )
return - 5 ;
if ( V_117 ) {
if ( F_12 ( V_1 , V_128 , & V_18 -> V_61 ) )
return - 6 ;
}
if ( ! ( V_18 -> V_57 & V_90 ) )
return 0 ;
if ( V_39 && ! V_40 ) {
if ( F_12 ( V_1 , V_129 , & V_19 -> V_68 ) )
return - 6 ;
}
if ( V_39 ) {
if ( F_12 ( V_1 , V_130 , & V_19 -> V_69 ) )
return - 7 ;
}
if ( V_41 )
if ( F_12 ( V_1 , V_131 , & V_19 -> V_70 ) )
return - 8 ;
if ( V_42 ) {
if ( F_12 ( V_1 , V_132 , & V_25 ) )
return - 9 ;
V_19 -> V_71 = V_133 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
if ( ! ( V_18 -> V_57 & V_92 ) )
return 0 ;
if ( V_45 )
if ( F_12 ( V_1 , V_134 , & V_20 -> V_74 ) )
return - 9 ;
if ( V_46 )
if ( F_12 ( V_1 , V_135 , & V_20 -> V_75 ) )
return - 10 ;
if ( V_44 )
if ( F_12 ( V_1 , V_136 , & V_20 -> V_73 ) )
return - 11 ;
if ( V_47 )
if ( F_12 ( V_1 , V_137 , & V_20 -> V_76 ) )
return - 12 ;
if ( V_48 ) {
if ( F_12 ( V_1 , V_138 , & V_20 -> V_77 ) )
return - 13 ;
if ( F_12 ( V_1 , V_139 , & V_20 -> V_78 ) )
return - 13 ;
if ( F_12 ( V_1 , V_140 , & V_20 -> V_79 ) )
return - 13 ;
}
if ( V_49 & V_51 ) {
if ( F_12 ( V_1 , V_141 , & V_25 ) )
return - 13 ;
V_20 -> V_80 = V_25 & 0xFFFFFFFF ;
}
if ( V_49 & V_52 ) {
if ( F_12 ( V_1 , V_142 , & V_25 ) )
return - 14 ;
V_20 -> V_81 = V_25 & 0xFFFFFFFF ;
}
if ( V_49 & V_54 ) {
if ( F_12 ( V_1 , V_143 , & V_25 ) )
return - 15 ;
V_20 -> V_83 = V_25 & 0xFFFFFFFF ;
}
if ( V_49 & V_53 ) {
if ( F_12 ( V_1 , V_144 , & V_25 ) )
return - 16 ;
V_20 -> V_82 = V_25 & 0xFFFFFFFF ;
}
if ( V_49 & V_55 ) {
if ( F_12 ( V_1 , V_145 , & V_25 ) )
return - 16 ;
V_20 -> V_84 = V_25 & 0xFFFFFFFF ;
}
if ( V_49 & V_56 ) {
if ( F_12 ( V_1 , V_146 , & V_25 ) )
return - 16 ;
V_20 -> V_85 = V_25 & 0xFFFFFFFF ;
}
if ( V_43 ) {
if ( F_12 ( V_1 , V_147 , & V_25 ) )
return - 17 ;
V_20 -> V_86 = V_133 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
return 0 ;
}
void F_35 ( void )
{
unsigned long long V_25 ;
unsigned int V_148 ;
if ( ! V_149 )
return;
F_12 ( 0 , V_150 , & V_25 ) ;
fprintf ( V_106 , L_87 , V_25 ) ;
V_148 = ( V_25 >> 40 ) & 0xFF ;
fprintf ( V_106 , L_88 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 8 ) & 0xFF ;
fprintf ( V_106 , L_89 ,
V_148 , V_151 , V_148 * V_151 ) ;
F_12 ( 0 , V_152 , & V_25 ) ;
fprintf ( V_106 , L_90 ,
V_25 , V_25 & 0x2 ? L_91 : L_92 ) ;
if ( ! V_153 )
goto V_154;
F_12 ( 0 , V_155 , & V_25 ) ;
fprintf ( V_106 , L_93 , V_25 ) ;
V_148 = ( V_25 >> 56 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_94 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 48 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_95 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 40 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_96 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 32 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_97 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 24 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_98 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 16 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_99 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 8 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_100 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 0 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_101 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_154:
F_12 ( 0 , V_156 , & V_25 ) ;
#define F_36 (1UL << 27)
#define F_37 (1UL << 28)
fprintf ( V_106 , L_102 , V_25 ) ;
fprintf ( V_106 , L_103 ,
( V_25 & F_37 ) ? L_104 : L_105 ,
( V_25 & F_36 ) ? L_106 : L_105 ,
( V_25 & V_157 ) ? L_107 : L_105 ,
( V_25 & V_158 ) ? L_108 : L_105 ,
( V_25 & ( 1 << 15 ) ) ? L_105 : L_109 ,
( unsigned int ) V_25 & 7 ,
V_159 [ V_160 ] ) ;
if ( ! V_161 )
return;
F_12 ( 0 , V_162 , & V_25 ) ;
fprintf ( V_106 , L_110 , V_25 ) ;
V_148 = ( V_25 >> 56 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_111 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 48 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_112 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 40 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_113 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 32 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_114 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 24 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_115 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 16 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_116 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 8 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_117 ,
V_148 , V_151 , V_148 * V_151 ) ;
V_148 = ( V_25 >> 0 ) & 0xFF ;
if ( V_148 )
fprintf ( V_106 , L_118 ,
V_148 , V_151 , V_148 * V_151 ) ;
}
void F_38 ( void )
{
F_39 ( V_3 ) ;
V_3 = NULL ;
V_3 = 0 ;
F_39 ( V_23 ) ;
V_23 = NULL ;
V_22 = 0 ;
free ( V_163 ) ;
free ( V_164 ) ;
free ( V_165 ) ;
V_163 = NULL ;
V_164 = NULL ;
V_165 = NULL ;
free ( V_166 ) ;
free ( V_167 ) ;
free ( V_168 ) ;
V_166 = NULL ;
V_167 = NULL ;
V_168 = NULL ;
free ( V_105 ) ;
V_105 = NULL ;
V_30 = NULL ;
}
T_3 * F_40 ( const char * V_169 , const char * V_170 )
{
T_3 * V_171 = fopen ( V_169 , L_119 ) ;
if ( ! V_171 )
F_14 ( 1 , L_120 , V_169 ) ;
return V_171 ;
}
int F_41 ( const char * V_172 , ... )
{
T_4 args ;
char V_169 [ V_173 ] ;
T_3 * V_171 ;
int V_174 ;
va_start ( args , V_172 ) ;
vsnprintf ( V_169 , sizeof( V_169 ) , V_172 , args ) ;
va_end ( args ) ;
V_171 = F_40 ( V_169 , L_119 ) ;
if ( fscanf ( V_171 , L_121 , & V_174 ) != 1 )
F_14 ( 1 , L_122 , V_169 ) ;
fclose ( V_171 ) ;
return V_174 ;
}
int F_42 ( int V_1 )
{
return V_1 == F_41 ( L_123 , V_1 ) ;
}
int F_43 ( int V_1 )
{
return V_1 == F_41 ( L_124 , V_1 ) ;
}
int F_44 ( int V_1 )
{
return F_41 ( L_125 , V_1 ) ;
}
int F_45 ( int V_1 )
{
return F_41 ( L_126 , V_1 ) ;
}
int F_46 ( int V_1 )
{
char V_169 [ 80 ] ;
T_3 * V_171 ;
int V_175 , V_176 ;
int V_177 ;
char V_178 ;
sprintf ( V_169 , L_123 , V_1 ) ;
V_171 = F_40 ( V_169 , L_119 ) ;
V_177 = fscanf ( V_171 , L_127 , & V_175 , & V_178 , & V_176 ) ;
fclose ( V_171 ) ;
if ( V_177 == 3 )
return 2 ;
else
return 1 ;
}
int F_47 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_179 , struct V_5 * V_180 ,
struct V_6 * V_181 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_119 ;
struct V_5 * V_19 , * V_120 ;
struct V_6 * V_20 , * V_121 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_119 = F_5 ( V_179 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_120 = F_6 ( V_180 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_121 = F_7 ( V_181 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_119 , V_120 , V_121 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_48 ( int (F_4)( int ) )
{
T_3 * V_182 ;
int V_183 ;
int V_10 ;
V_182 = F_40 ( V_184 , L_119 ) ;
V_10 = fscanf ( V_182 , L_128 ) ;
if ( V_10 != 0 )
F_14 ( 1 , L_129 , V_184 ) ;
while ( 1 ) {
V_10 = fscanf ( V_182 , L_130 , & V_183 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_183 ) ;
if ( V_10 ) {
fclose ( V_182 ) ;
return ( V_10 ) ;
}
}
fclose ( V_182 ) ;
return 0 ;
}
void F_49 ( void )
{
F_38 () ;
F_50 () ;
printf ( L_131 , V_14 . V_109 ) ;
}
int F_51 ( int V_1 )
{
if ( V_14 . V_185 < V_1 )
V_14 . V_185 = V_1 ;
V_14 . V_109 += 1 ;
return 0 ;
}
int F_52 ( int V_1 )
{
F_10 ( V_1 , V_2 , V_3 ) ;
return 0 ;
}
void F_53 ()
{
int V_10 ;
int V_186 = 0 ;
V_187:
V_186 ++ ;
V_10 = F_3 ( F_34 , V_188 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
if ( V_186 > 1 ) {
exit ( V_10 ) ;
}
F_49 () ;
goto V_187;
}
V_186 = 0 ;
F_54 ( & V_189 , (struct V_190 * ) NULL ) ;
while ( 1 ) {
if ( F_48 ( F_1 ) ) {
F_49 () ;
goto V_187;
}
F_55 ( V_191 ) ;
V_10 = F_3 ( F_34 , V_192 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_49 () ;
goto V_187;
}
F_54 ( & V_193 , (struct V_190 * ) NULL ) ;
F_56 ( & V_193 , & V_189 , & V_93 ) ;
F_47 ( F_28 , V_192 , V_188 ) ;
F_32 ( V_188 ) ;
F_22 ( V_188 ) ;
F_20 () ;
F_55 ( V_191 ) ;
V_10 = F_3 ( F_34 , V_188 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_49 () ;
goto V_187;
}
F_54 ( & V_189 , (struct V_190 * ) NULL ) ;
F_56 ( & V_189 , & V_193 , & V_93 ) ;
F_47 ( F_28 , V_188 , V_192 ) ;
F_32 ( V_192 ) ;
F_22 ( V_192 ) ;
F_20 () ;
}
}
void F_57 ()
{
struct V_194 V_195 ;
if ( V_194 ( L_132 , & V_195 ) )
F_14 ( - 5 , L_133 ) ;
}
void F_58 ()
{
struct V_196 V_197 ;
T_5 V_198 = & V_197 ;
struct V_199 V_200 ;
T_6 V_201 = & V_200 ;
extern int V_202 ( T_5 V_203 , T_6 V_204 ) ;
int V_205 = 0 ;
V_198 -> V_206 = F_59 () ;
V_198 -> V_207 = V_208 ;
if ( V_202 ( V_198 , V_201 ) < 0 )
F_14 ( - 6 , L_134 ) ;
if ( ( V_201 -> V_209 & ( 1 << V_210 ) ) == 0 ) {
V_205 ++ ;
F_60 ( L_135
L_136 , V_116 ) ;
}
if ( F_61 ( L_132 , V_211 ) ) {
V_205 ++ ;
F_62 ( L_137 ) ;
}
if ( V_205 )
if ( F_63 () != 0 )
F_60 ( L_138 ) ;
if ( V_205 )
exit ( - 6 ) ;
}
int F_64 ( unsigned int V_212 , unsigned int V_213 )
{
unsigned long long V_25 ;
int * V_214 ;
if ( ! V_215 )
return 0 ;
if ( V_212 != 6 )
return 0 ;
switch ( V_213 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x25 :
case 0x2C :
case 0x2E :
case 0x2F :
V_214 = V_216 ;
break;
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
V_214 = V_217 ;
break;
case 0x3C :
case 0x3F :
case 0x45 :
case 0x46 :
case 0x3D :
case 0x47 :
case 0x4F :
case 0x56 :
V_214 = V_218 ;
break;
case 0x37 :
case 0x4D :
V_214 = V_219 ;
break;
case 0x4C :
V_214 = V_220 ;
break;
case 0x57 :
V_214 = V_221 ;
break;
default:
return 0 ;
}
F_12 ( 0 , V_156 , & V_25 ) ;
V_160 = V_214 [ V_25 & 0x7 ] ;
return 1 ;
}
int F_65 ( unsigned int V_212 , unsigned int V_213 )
{
switch ( V_213 ) {
case 0x2E :
case 0x2F :
return 0 ;
default:
return 1 ;
}
}
int F_66 ( unsigned int V_212 , unsigned int V_213 )
{
if ( ! V_215 )
return 0 ;
if ( V_212 != 6 )
return 0 ;
switch ( V_213 ) {
case 0x3E :
return 1 ;
default:
return 0 ;
}
}
int F_67 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
char * V_222 ;
int V_1 ;
if ( ! V_223 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_57 & V_90 ) || ! ( V_18 -> V_57 & V_92 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_106 , L_86 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_224 , & V_25 ) )
return 0 ;
switch ( V_25 & 0x7 ) {
case V_225 :
V_222 = L_139 ;
break;
case V_226 :
V_222 = L_140 ;
break;
case V_227 :
V_222 = L_141 ;
break;
default:
V_222 = L_142 ;
break;
}
fprintf ( V_106 , L_143 , V_1 , V_25 , V_222 ) ;
return 0 ;
}
int F_68 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_57 & V_90 ) || ! ( V_18 -> V_57 & V_92 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_106 , L_86 , V_1 ) ;
return - 1 ;
}
if ( V_228 ) {
F_12 ( V_1 , V_229 , & V_25 ) ;
fprintf ( V_106 , L_144 , V_1 , V_25 ) ;
fprintf ( V_106 , L_145 ,
( V_25 & 1 << 0 ) ? L_146 : L_105 ,
( V_25 & 1 << 1 ) ? L_147 : L_105 ,
( V_25 & 1 << 2 ) ? L_148 : L_105 ,
( V_25 & 1 << 4 ) ? L_149 : L_105 ,
( V_25 & 1 << 5 ) ? L_150 : L_105 ,
( V_25 & 1 << 6 ) ? L_151 : L_105 ,
( V_25 & 1 << 8 ) ? L_152 : L_105 ,
( V_25 & 1 << 9 ) ? L_153 : L_105 ,
( V_25 & 1 << 10 ) ? L_154 : L_105 ,
( V_25 & 1 << 11 ) ? L_155 : L_105 ,
( V_25 & 1 << 12 ) ? L_156 : L_105 ,
( V_25 & 1 << 13 ) ? L_157 : L_105 ,
( V_25 & 1 << 14 ) ? L_158 : L_105 ,
( V_25 & 1 << 15 ) ? L_159 : L_105 ) ;
fprintf ( V_106 , L_160 ,
( V_25 & 1 << 16 ) ? L_146 : L_105 ,
( V_25 & 1 << 17 ) ? L_147 : L_105 ,
( V_25 & 1 << 18 ) ? L_161 : L_105 ,
( V_25 & 1 << 20 ) ? L_149 : L_105 ,
( V_25 & 1 << 21 ) ? L_150 : L_105 ,
( V_25 & 1 << 22 ) ? L_151 : L_105 ,
( V_25 & 1 << 24 ) ? L_152 : L_105 ,
( V_25 & 1 << 25 ) ? L_153 : L_105 ,
( V_25 & 1 << 26 ) ? L_154 : L_105 ,
( V_25 & 1 << 27 ) ? L_155 : L_105 ,
( V_25 & 1 << 28 ) ? L_156 : L_105 ,
( V_25 & 1 << 29 ) ? L_157 : L_105 ,
( V_25 & 1 << 30 ) ? L_162 : L_105 ,
( V_25 & 1 << 31 ) ? L_163 : L_105 ) ;
}
if ( V_230 ) {
F_12 ( V_1 , V_231 , & V_25 ) ;
fprintf ( V_106 , L_164 , V_1 , V_25 ) ;
fprintf ( V_106 , L_165 ,
( V_25 & 1 << 0 ) ? L_146 : L_105 ,
( V_25 & 1 << 1 ) ? L_147 : L_105 ,
( V_25 & 1 << 4 ) ? L_149 : L_105 ,
( V_25 & 1 << 6 ) ? L_151 : L_105 ,
( V_25 & 1 << 8 ) ? L_152 : L_105 ,
( V_25 & 1 << 9 ) ? L_166 : L_105 ,
( V_25 & 1 << 10 ) ? L_154 : L_105 ,
( V_25 & 1 << 11 ) ? L_155 : L_105 ) ;
fprintf ( V_106 , L_167 ,
( V_25 & 1 << 16 ) ? L_146 : L_105 ,
( V_25 & 1 << 17 ) ? L_147 : L_105 ,
( V_25 & 1 << 20 ) ? L_149 : L_105 ,
( V_25 & 1 << 22 ) ? L_151 : L_105 ,
( V_25 & 1 << 24 ) ? L_152 : L_105 ,
( V_25 & 1 << 25 ) ? L_166 : L_105 ,
( V_25 & 1 << 26 ) ? L_154 : L_105 ,
( V_25 & 1 << 27 ) ? L_155 : L_105 ) ;
}
if ( V_232 ) {
F_12 ( V_1 , V_233 , & V_25 ) ;
fprintf ( V_106 , L_168 , V_1 , V_25 ) ;
fprintf ( V_106 , L_169 ,
( V_25 & 1 << 0 ) ? L_146 : L_105 ,
( V_25 & 1 << 1 ) ? L_147 : L_105 ,
( V_25 & 1 << 6 ) ? L_151 : L_105 ,
( V_25 & 1 << 8 ) ? L_152 : L_105 ,
( V_25 & 1 << 10 ) ? L_154 : L_105 ,
( V_25 & 1 << 11 ) ? L_155 : L_105 ) ;
fprintf ( V_106 , L_170 ,
( V_25 & 1 << 16 ) ? L_146 : L_105 ,
( V_25 & 1 << 17 ) ? L_147 : L_105 ,
( V_25 & 1 << 22 ) ? L_151 : L_105 ,
( V_25 & 1 << 24 ) ? L_152 : L_105 ,
( V_25 & 1 << 26 ) ? L_154 : L_105 ,
( V_25 & 1 << 27 ) ? L_155 : L_105 ) ;
}
return 0 ;
}
double F_69 ( V_213 )
{
unsigned long long V_25 ;
if ( V_49 & V_234 )
if ( ! F_12 ( 0 , V_235 , & V_25 ) )
return ( ( V_25 >> 0 ) & V_236 ) * V_237 ;
switch ( V_213 ) {
case 0x37 :
case 0x4D :
return 30.0 ;
default:
return 135.0 ;
}
}
void F_70 ( unsigned int V_212 , unsigned int V_213 )
{
unsigned long long V_25 ;
unsigned int V_238 ;
double V_239 ;
if ( ! V_215 )
return;
if ( V_212 != 6 )
return;
switch ( V_213 ) {
case 0x2A :
case 0x3A :
case 0x3C :
case 0x45 :
case 0x46 :
case 0x3D :
case 0x47 :
V_49 = V_51 | V_52 | V_240 | V_53 | V_234 ;
break;
case 0x3F :
case 0x4F :
case 0x56 :
V_49 = V_51 | V_54 | V_56 | V_55 | V_234 ;
break;
case 0x2D :
case 0x3E :
V_49 = V_51 | V_52 | V_240 | V_54 | V_55 | V_56 | V_234 ;
break;
case 0x37 :
case 0x4D :
V_49 = V_51 | V_52 ;
break;
default:
return;
}
if ( F_12 ( 0 , V_241 , & V_25 ) )
return;
V_237 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
if ( V_213 == 0x37 )
V_103 = 1.0 * ( 1 << ( V_25 >> 8 & 0x1F ) ) / 1000000 ;
else
V_103 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_238 = V_25 >> 16 & 0xF ;
if ( V_238 == 0 )
V_238 = 0xA ;
V_104 = 1.0 / ( 1 << ( V_238 ) ) ;
V_239 = F_69 ( V_213 ) ;
V_102 = 0xFFFFFFFF * V_103 / V_239 ;
if ( V_118 )
fprintf ( V_106 , L_171 , V_102 , V_239 ) ;
return;
}
void F_71 ( V_212 , V_213 )
{
if ( ! V_215 )
return;
if ( V_212 != 6 )
return;
switch ( V_213 ) {
case 0x3C :
case 0x45 :
case 0x46 :
V_230 = 1 ;
case 0x3F :
V_228 = 1 ;
V_232 = 1 ;
default:
return;
}
}
int F_72 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_242 ;
int V_1 ;
if ( ! ( V_42 || V_43 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_57 & V_90 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_106 , L_86 , V_1 ) ;
return - 1 ;
}
if ( V_43 && ( V_18 -> V_57 & V_92 ) ) {
if ( F_12 ( V_1 , V_147 , & V_25 ) )
return 0 ;
V_242 = ( V_25 >> 16 ) & 0x7F ;
fprintf ( V_106 , L_172 ,
V_1 , V_25 , V_133 - V_242 ) ;
#ifdef F_73
if ( F_12 ( V_1 , V_243 , & V_25 ) )
return 0 ;
V_242 = ( V_25 >> 16 ) & 0x7F ;
V_244 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_106 , L_173 ,
V_1 , V_25 , V_133 - V_242 , V_133 - V_244 ) ;
#endif
}
if ( V_42 ) {
unsigned int V_245 ;
if ( F_12 ( V_1 , V_132 , & V_25 ) )
return 0 ;
V_242 = ( V_25 >> 16 ) & 0x7F ;
V_245 = ( V_25 >> 27 ) & 0xF ;
fprintf ( V_106 , L_174 ,
V_1 , V_25 , V_133 - V_242 , V_245 ) ;
#ifdef F_73
if ( F_12 ( V_1 , V_246 , & V_25 ) )
return 0 ;
V_242 = ( V_25 >> 16 ) & 0x7F ;
V_244 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_106 , L_175 ,
V_1 , V_25 , V_133 - V_242 , V_133 - V_244 ) ;
#endif
}
return 0 ;
}
void F_74 ( int V_1 , unsigned long long V_25 , char * V_247 )
{
fprintf ( V_106 , L_176 ,
V_1 , V_247 ,
( ( V_25 >> 15 ) & 1 ) ? L_91 : L_92 ,
( ( V_25 >> 0 ) & 0x7FFF ) * V_237 ,
( 1.0 + ( ( ( V_25 >> 22 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 17 ) & 0x1F ) ) * V_104 ,
( ( ( V_25 >> 16 ) & 1 ) ? L_91 : L_92 ) ) ;
return;
}
int F_75 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
if ( ! V_49 )
return 0 ;
if ( ! ( V_18 -> V_57 & V_90 ) || ! ( V_18 -> V_57 & V_92 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_106 , L_86 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_241 , & V_25 ) )
return - 1 ;
if ( V_118 ) {
fprintf ( V_106 , L_177
L_178 , V_1 , V_25 ,
V_237 , V_103 , V_104 ) ;
}
if ( V_49 & V_234 ) {
if ( F_12 ( V_1 , V_235 , & V_25 ) )
return - 5 ;
fprintf ( V_106 , L_179 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_236 ) * V_237 ,
( ( V_25 >> 16 ) & V_236 ) * V_237 ,
( ( V_25 >> 32 ) & V_236 ) * V_237 ,
( ( V_25 >> 48 ) & V_248 ) * V_104 ) ;
}
if ( V_49 & V_51 ) {
if ( F_12 ( V_1 , V_249 , & V_25 ) )
return - 9 ;
fprintf ( V_106 , L_180 ,
V_1 , V_25 , ( V_25 >> 63 ) & 1 ? L_105 : L_109 ) ;
F_74 ( V_1 , V_25 , L_181 ) ;
fprintf ( V_106 , L_182 ,
V_1 ,
( ( V_25 >> 47 ) & 1 ) ? L_91 : L_92 ,
( ( V_25 >> 32 ) & 0x7FFF ) * V_237 ,
( 1.0 + ( ( ( V_25 >> 54 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 49 ) & 0x1F ) ) * V_104 ,
( ( V_25 >> 48 ) & 1 ) ? L_91 : L_92 ) ;
}
if ( V_49 & V_54 ) {
if ( F_12 ( V_1 , V_250 , & V_25 ) )
return - 6 ;
fprintf ( V_106 , L_183 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_236 ) * V_237 ,
( ( V_25 >> 16 ) & V_236 ) * V_237 ,
( ( V_25 >> 32 ) & V_236 ) * V_237 ,
( ( V_25 >> 48 ) & V_248 ) * V_104 ) ;
if ( F_12 ( V_1 , V_251 , & V_25 ) )
return - 9 ;
fprintf ( V_106 , L_184 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_105 : L_109 ) ;
F_74 ( V_1 , V_25 , L_185 ) ;
}
if ( V_49 & V_240 ) {
if ( V_118 ) {
if ( F_12 ( V_1 , V_252 , & V_25 ) )
return - 7 ;
fprintf ( V_106 , L_186 , V_1 , V_25 & 0xF ) ;
}
}
if ( V_49 & V_52 ) {
if ( V_118 ) {
if ( F_12 ( V_1 , V_253 , & V_25 ) )
return - 9 ;
fprintf ( V_106 , L_187 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_105 : L_109 ) ;
F_74 ( V_1 , V_25 , L_188 ) ;
}
}
if ( V_49 & V_53 ) {
if ( V_118 ) {
if ( F_12 ( V_1 , V_254 , & V_25 ) )
return - 8 ;
fprintf ( V_106 , L_189 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_255 , & V_25 ) )
return - 9 ;
fprintf ( V_106 , L_190 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_105 : L_109 ) ;
F_74 ( V_1 , V_25 , L_191 ) ;
}
}
return 0 ;
}
int F_76 ( unsigned int V_212 , unsigned int V_213 )
{
if ( ! V_215 )
return 0 ;
switch ( V_213 ) {
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
return 1 ;
}
return 0 ;
}
int F_77 ( unsigned int V_212 , unsigned int V_213 )
{
if ( ! V_215 )
return 0 ;
switch ( V_213 ) {
case 0x45 :
case 0x3D :
return 1 ;
}
return 0 ;
}
int F_78 ( unsigned int V_212 , unsigned int V_213 )
{
if ( ! V_215 )
return 0 ;
switch ( V_213 ) {
case 0x37 :
case 0x4D :
return 1 ;
}
return 0 ;
}
double F_79 ( void )
{
unsigned long long V_25 = 3 ;
unsigned int V_256 ;
double V_257 ;
if ( F_12 ( 0 , V_258 , & V_25 ) )
fprintf ( V_106 , L_192 ) ;
V_256 = V_25 & 0xf ;
if ( V_256 >= V_259 ) {
fprintf ( V_106 , L_193 , V_256 ) ;
V_25 = 3 ;
}
V_257 = V_260 [ V_256 ] ;
fprintf ( V_106 , L_194 , V_257 ) ;
return V_257 ;
}
double F_80 ( unsigned int V_212 , unsigned int V_213 )
{
if ( F_76 ( V_212 , V_213 ) )
return 100.00 ;
else if ( F_78 ( V_212 , V_213 ) )
return F_79 () ;
else
return 133.33 ;
}
int F_81 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_261 ;
int V_1 ;
if ( ! ( V_42 || V_43 ) )
return 0 ;
if ( ! ( V_18 -> V_57 & V_90 ) || ! ( V_18 -> V_57 & V_92 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_106 , L_86 , V_1 ) ;
return - 1 ;
}
if ( V_262 != 0 ) {
V_133 = V_262 ;
fprintf ( V_106 , L_195 ,
V_1 , V_133 ) ;
return 0 ;
}
if ( ! V_149 )
goto V_263;
if ( F_12 ( 0 , V_264 , & V_25 ) )
goto V_263;
V_261 = ( V_25 >> 16 ) & 0xFF ;
if ( V_118 )
fprintf ( V_106 , L_196 ,
V_1 , V_25 , V_261 ) ;
if ( ! V_261 )
goto V_263;
V_133 = V_261 ;
return 0 ;
V_263:
V_133 = V_265 ;
fprintf ( V_106 , L_197 ,
V_1 , V_133 ) ;
return 0 ;
}
void F_82 ()
{
unsigned int V_266 , V_267 , V_268 , V_269 , V_270 ;
unsigned int V_271 , V_212 , V_213 , V_272 ;
V_266 = V_267 = V_268 = V_269 = 0 ;
F_83 ( 0 , & V_270 , & V_267 , & V_268 , & V_269 ) ;
if ( V_267 == 0x756e6547 && V_269 == 0x49656e69 && V_268 == 0x6c65746e )
V_215 = 1 ;
if ( V_118 )
fprintf ( V_106 , L_198 ,
( char * ) & V_267 , ( char * ) & V_269 , ( char * ) & V_268 ) ;
F_83 ( 1 , & V_271 , & V_267 , & V_268 , & V_269 ) ;
V_212 = ( V_271 >> 8 ) & 0xf ;
V_213 = ( V_271 >> 4 ) & 0xf ;
V_272 = V_271 & 0xf ;
if ( V_212 == 6 || V_212 == 0xf )
V_213 += ( ( V_271 >> 16 ) & 0xf ) << 4 ;
if ( V_118 )
fprintf ( V_106 , L_199 ,
V_270 , V_212 , V_213 , V_272 , V_212 , V_213 , V_272 ) ;
if ( ! ( V_269 & ( 1 << 5 ) ) )
F_27 ( 1 , L_200 ) ;
V_267 = V_268 = V_269 = 0 ;
F_83 ( 0x80000000 , & V_270 , & V_267 , & V_268 , & V_269 ) ;
if ( V_270 >= 0x80000007 ) {
F_83 ( 0x80000007 , & V_266 , & V_267 , & V_268 , & V_269 ) ;
V_273 = V_269 & ( 1 << 8 ) ;
}
F_83 ( 0x6 , & V_266 , & V_267 , & V_268 , & V_269 ) ;
V_33 = V_268 & ( 1 << 0 ) ;
V_42 = V_266 & ( 1 << 0 ) ;
V_43 = V_266 & ( 1 << 6 ) ;
V_223 = V_268 & ( 1 << 3 ) ;
if ( V_118 )
fprintf ( V_106 , L_201 ,
V_33 ? L_105 : L_202 ,
V_42 ? L_105 : L_202 ,
V_43 ? L_105 : L_202 ,
V_223 ? L_105 : L_202 ) ;
V_149 = V_39 = V_34 = F_64 ( V_212 , V_213 ) ;
V_41 = F_76 ( V_212 , V_213 ) ;
V_44 = V_41 && ( V_160 >= V_274 ) ;
V_45 = ( V_160 >= V_275 ) ;
V_46 = ( V_160 >= V_276 ) ;
V_47 = V_41 && ( V_160 >= V_277 ) ;
V_48 = F_77 ( V_212 , V_213 ) ;
V_40 = F_78 ( V_212 , V_213 ) ;
V_151 = F_80 ( V_212 , V_213 ) ;
V_161 = V_149 && F_65 ( V_212 , V_213 ) ;
V_153 = F_66 ( V_212 , V_213 ) ;
F_70 ( V_212 , V_213 ) ;
F_71 ( V_212 , V_213 ) ;
return;
}
void F_84 ()
{
fprintf ( V_106 ,
L_203
L_40
L_204
L_205
L_206
L_207
L_208
L_209
L_210
L_211
L_212
L_213
L_214
L_215
L_40
L_216 ) ;
}
int F_85 ( const struct V_278 * V_279 )
{
if ( isdigit ( V_279 -> V_280 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_86 ( int V_281 )
{
return 0 ;
}
void F_87 ()
{
int V_256 ;
int V_282 = 0 ;
int V_283 = 0 ;
int V_284 = 0 ;
struct V_285 {
int V_67 ;
int V_286 ;
} * V_287 ;
V_14 . V_109 = 0 ;
V_14 . V_185 = 0 ;
F_48 ( F_51 ) ;
if ( ! V_108 && V_14 . V_109 > 1 )
V_32 = 1 ;
if ( V_118 > 1 )
fprintf ( V_106 , L_217 , V_14 . V_109 , V_14 . V_185 ) ;
V_287 = calloc ( 1 , ( V_14 . V_185 + 1 ) * sizeof( struct V_285 ) ) ;
if ( V_287 == NULL )
F_14 ( 1 , L_218 ) ;
V_3 = F_88 ( ( V_14 . V_185 + 1 ) ) ;
if ( V_3 == NULL )
F_14 ( 3 , L_219 ) ;
V_2 = F_89 ( ( V_14 . V_185 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_48 ( F_52 ) ;
V_23 = F_88 ( ( V_14 . V_185 + 1 ) ) ;
if ( V_23 == NULL )
F_14 ( 3 , L_219 ) ;
V_22 = F_89 ( ( V_14 . V_185 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_256 = 0 ; V_256 <= V_14 . V_185 ; ++ V_256 ) {
int V_288 ;
if ( F_1 ( V_256 ) ) {
if ( V_118 > 1 )
fprintf ( V_106 , L_220 , V_256 ) ;
continue;
}
V_287 [ V_256 ] . V_67 = F_45 ( V_256 ) ;
if ( V_287 [ V_256 ] . V_67 > V_282 )
V_282 = V_287 [ V_256 ] . V_67 ;
V_287 [ V_256 ] . V_286 = F_44 ( V_256 ) ;
if ( V_287 [ V_256 ] . V_286 > V_283 )
V_283 = V_287 [ V_256 ] . V_286 ;
V_288 = F_46 ( V_256 ) ;
if ( V_288 > V_284 )
V_284 = V_288 ;
if ( V_118 > 1 )
fprintf ( V_106 , L_221 ,
V_256 , V_287 [ V_256 ] . V_286 , V_287 [ V_256 ] . V_67 ) ;
}
V_14 . V_16 = V_282 + 1 ;
if ( V_118 > 1 )
fprintf ( V_106 , L_222 ,
V_282 , V_14 . V_16 ) ;
if ( ! V_108 && V_14 . V_16 > 1 )
V_31 = 1 ;
V_14 . V_15 = V_283 + 1 ;
if ( V_118 > 1 )
fprintf ( V_106 , L_223 ,
V_283 , V_14 . V_15 ) ;
if ( ! V_108 && V_14 . V_15 > 1 )
V_29 = 1 ;
V_14 . V_17 = V_284 ;
if ( V_118 > 1 )
fprintf ( V_106 , L_224 , V_284 ) ;
free ( V_287 ) ;
}
void
F_90 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_256 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_256 = 0 ; V_256 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_256 ++ )
( * V_18 ) [ V_256 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_256 = 0 ; V_256 < V_14 . V_16 * V_14 . V_15 ; V_256 ++ )
( * V_19 ) [ V_256 ] . V_67 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_256 = 0 ; V_256 < V_14 . V_15 ; V_256 ++ )
( * V_20 ) [ V_256 ] . V_72 = V_256 ;
return;
error:
F_14 ( 1 , L_225 ) ;
}
void F_91 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_289 , int V_290 ,
int V_291 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_289 , V_290 , V_291 ) ;
V_19 = F_6 ( V_8 , V_290 , V_291 ) ;
V_20 = F_7 ( V_9 , V_291 ) ;
V_18 -> V_21 = V_21 ;
if ( V_289 == 0 ) {
V_18 -> V_57 |= V_90 ;
if ( F_43 ( V_21 ) )
V_18 -> V_57 |= V_92 ;
}
V_19 -> V_67 = V_290 ;
V_20 -> V_72 = V_291 ;
}
int F_92 ( int V_21 )
{
int V_292 , V_293 , V_294 ;
V_294 = F_44 ( V_21 ) ;
V_293 = F_45 ( V_21 ) ;
if ( F_42 ( V_21 ) ) {
V_292 = 0 ;
V_14 . V_122 ++ ;
} else {
V_292 = 1 ;
}
F_91 ( V_188 , V_292 , V_293 , V_294 , V_21 ) ;
F_91 ( V_192 , V_292 , V_293 , V_294 , V_21 ) ;
return 0 ;
}
void F_93 ()
{
V_105 = calloc ( 1 , ( 1 + V_14 . V_109 ) * 1024 ) ;
V_30 = V_105 ;
if ( V_30 == NULL )
F_14 ( - 1 , L_226 ) ;
}
void F_50 ( void )
{
F_87 () ;
F_90 ( & V_163 , & V_164 , & V_165 ) ;
F_90 ( & V_166 , & V_167 , & V_168 ) ;
F_93 () ;
F_48 ( F_92 ) ;
}
void F_94 ()
{
F_57 () ;
F_58 () ;
F_82 () ;
F_50 () ;
if ( V_118 )
F_35 () ;
if ( V_118 )
F_3 ( F_67 , V_192 ) ;
if ( V_118 )
F_3 ( F_68 , V_192 ) ;
if ( V_118 )
F_3 ( F_75 , V_192 ) ;
F_3 ( F_81 , V_192 ) ;
if ( V_118 )
F_3 ( F_72 , V_192 ) ;
}
int F_95 ( char * * V_295 )
{
T_7 V_296 ;
int V_297 ;
V_297 = F_3 ( F_34 , V_188 ) ;
if ( V_297 )
exit ( V_297 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_54 ( & V_189 , (struct V_190 * ) NULL ) ;
V_296 = F_96 () ;
if ( ! V_296 ) {
F_97 ( V_295 [ 0 ] , V_295 ) ;
} else {
if ( V_296 == - 1 )
F_14 ( 1 , L_227 ) ;
signal ( V_298 , V_299 ) ;
signal ( V_300 , V_299 ) ;
if ( F_98 ( V_296 , & V_297 , 0 ) == - 1 )
F_14 ( V_297 , L_228 ) ;
}
F_3 ( F_34 , V_192 ) ;
F_54 ( & V_193 , (struct V_190 * ) NULL ) ;
F_56 ( & V_193 , & V_189 , & V_93 ) ;
F_47 ( F_28 , V_192 , V_188 ) ;
F_32 ( V_188 ) ;
F_22 ( V_188 ) ;
F_21 () ;
fprintf ( V_106 , L_229 , V_93 . V_94 + V_93 . V_95 / 1000000.0 ) ;
return V_297 ;
}
int F_99 ( void )
{
int V_297 ;
V_297 = F_3 ( F_34 , V_192 ) ;
if ( V_297 )
return V_297 ;
V_297 = F_3 ( F_18 , V_192 ) ;
if ( V_297 )
return V_297 ;
F_20 () ;
return V_297 ;
}
void F_100 () {
fprintf ( V_106 , L_230
L_231 ) ;
}
void F_101 ( int V_301 , char * * V_295 )
{
int V_302 ;
int V_303 = 0 ;
static struct V_304 V_305 [] = {
{ L_232 , V_306 , 0 , 'C' } ,
{ L_233 , V_306 , 0 , 'c' } ,
{ L_234 , V_307 , 0 , 'D' } ,
{ L_235 , V_307 , 0 , 'd' } ,
{ L_236 , V_306 , 0 , 'i' } ,
{ L_237 , V_307 , 0 , 'h' } ,
{ L_238 , V_307 , 0 , 'J' } ,
{ L_239 , V_306 , 0 , 'M' } ,
{ L_240 , V_306 , 0 , 'm' } ,
{ L_241 , V_307 , 0 , 'p' } ,
{ L_242 , V_307 , 0 , 'p' } ,
{ L_243 , V_307 , 0 , 'S' } ,
{ L_244 , V_306 , 0 , 'T' } ,
{ L_245 , V_307 , 0 , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
V_116 = V_295 [ 0 ] ;
while ( ( V_302 = F_102 ( V_301 , V_295 , L_246 ,
V_305 , & V_303 ) ) != - 1 ) {
switch ( V_302 ) {
case 'C' :
sscanf ( V_308 , L_247 , & V_36 ) ;
break;
case 'c' :
sscanf ( V_308 , L_247 , & V_35 ) ;
break;
case 'D' :
V_309 ++ ;
break;
case 'd' :
V_118 ++ ;
break;
case 'h' :
default:
F_84 () ;
exit ( 1 ) ;
case 'i' :
V_191 = atoi ( V_308 ) ;
break;
case 'J' :
V_50 ++ ;
break;
case 'M' :
sscanf ( V_308 , L_247 , & V_38 ) ;
break;
case 'm' :
sscanf ( V_308 , L_247 , & V_37 ) ;
break;
case 'P' :
V_91 ++ ;
break;
case 'p' :
V_89 ++ ;
break;
case 'S' :
V_108 ++ ;
break;
case 'T' :
V_262 = atoi ( V_308 ) ;
break;
case 'v' :
F_100 () ;
exit ( 0 ) ;
break;
}
}
}
int main ( int V_301 , char * * V_295 )
{
F_101 ( V_301 , V_295 ) ;
if ( V_118 )
F_100 () ;
F_94 () ;
if ( V_309 )
return F_99 () ;
if ( V_301 - V_310 )
return F_95 ( V_295 + V_310 ) ;
else
F_53 () ;
return 0 ;
}
