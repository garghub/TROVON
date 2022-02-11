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
return - 1 ;
V_10 = F_14 ( V_27 , V_25 , sizeof *V_25 , V_24 ) ;
F_15 ( V_27 ) ;
if ( V_10 != sizeof *V_25 ) {
fprintf ( V_29 , L_2 , V_26 , V_24 ) ;
return - 1 ;
}
return 0 ;
}
void F_16 ( void )
{
if ( V_30 )
V_31 += sprintf ( V_31 , L_3 ) ;
if ( V_30 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 )
V_31 += sprintf ( V_31 , L_5 ) ;
if ( V_33 )
V_31 += sprintf ( V_31 , L_6 ) ;
if ( V_30 || V_32 || V_33 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_7 ) ;
if ( V_35 )
V_31 += sprintf ( V_31 , L_8 ) ;
V_31 += sprintf ( V_31 , L_9 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_10 ) ;
if ( V_37 )
V_31 += sprintf ( V_31 , L_11 , V_37 ) ;
if ( V_38 )
V_31 += sprintf ( V_31 , L_12 , V_38 ) ;
if ( V_39 )
V_31 += sprintf ( V_31 , L_13 , V_39 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_14 , V_40 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_15 ) ;
if ( V_34 && ! V_41 )
V_31 += sprintf ( V_31 , L_16 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_17 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_18 ) ;
if ( V_43 )
V_31 += sprintf ( V_31 , L_19 ) ;
if ( V_44 )
V_31 += sprintf ( V_31 , L_20 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_21 ) ;
if ( V_34 && ! V_41 )
V_31 += sprintf ( V_31 , L_22 ) ;
if ( V_34 && ! V_41 )
V_31 += sprintf ( V_31 , L_23 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_24 ) ;
if ( V_45 ) {
V_31 += sprintf ( V_31 , L_25 ) ;
V_31 += sprintf ( V_31 , L_26 ) ;
V_31 += sprintf ( V_31 , L_27 ) ;
}
if ( V_46 & V_47 )
V_31 += sprintf ( V_31 , L_28 ) ;
if ( V_46 & V_48 )
V_31 += sprintf ( V_31 , L_29 ) ;
if ( V_46 & V_49 )
V_31 += sprintf ( V_31 , L_30 ) ;
if ( V_46 & V_50 )
V_31 += sprintf ( V_31 , L_31 ) ;
if ( V_46 & V_51 )
V_31 += sprintf ( V_31 , L_32 ) ;
if ( V_46 & V_52 )
V_31 += sprintf ( V_31 , L_33 ) ;
V_31 += sprintf ( V_31 , L_34 ) ;
}
int F_17 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
fprintf ( V_29 , L_35 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
fprintf ( V_29 , L_36 , V_18 -> V_21 , V_18 -> V_53 ) ;
fprintf ( V_29 , L_37 , V_18 -> V_54 ) ;
fprintf ( V_29 , L_38 , V_18 -> V_55 ) ;
fprintf ( V_29 , L_39 , V_18 -> V_56 ) ;
fprintf ( V_29 , L_40 , V_18 -> V_57 ) ;
fprintf ( V_29 , L_41 ,
V_37 , V_18 -> V_58 ) ;
fprintf ( V_29 , L_42 ,
V_38 , V_18 -> V_59 ) ;
fprintf ( V_29 , L_41 ,
V_39 , V_18 -> V_60 ) ;
fprintf ( V_29 , L_42 ,
V_40 , V_18 -> V_61 ) ;
if ( V_36 )
fprintf ( V_29 , L_43 , V_18 -> V_62 ) ;
}
if ( V_19 ) {
fprintf ( V_29 , L_44 , V_19 -> V_63 ) ;
fprintf ( V_29 , L_45 , V_19 -> V_64 ) ;
fprintf ( V_29 , L_46 , V_19 -> V_65 ) ;
fprintf ( V_29 , L_47 , V_19 -> V_66 ) ;
fprintf ( V_29 , L_48 , V_19 -> V_67 ) ;
}
if ( V_20 ) {
fprintf ( V_29 , L_49 , V_20 -> V_68 ) ;
fprintf ( V_29 , L_50 , V_20 -> V_69 ) ;
fprintf ( V_29 , L_51 , V_20 -> V_70 ) ;
fprintf ( V_29 , L_52 , V_20 -> V_71 ) ;
fprintf ( V_29 , L_53 , V_20 -> V_72 ) ;
fprintf ( V_29 , L_54 , V_20 -> V_73 ) ;
fprintf ( V_29 , L_55 , V_20 -> V_74 ) ;
fprintf ( V_29 , L_56 , V_20 -> V_75 ) ;
fprintf ( V_29 , L_57 , V_20 -> V_76 ) ;
fprintf ( V_29 , L_58 , V_20 -> V_77 ) ;
fprintf ( V_29 , L_59 , V_20 -> V_78 ) ;
fprintf ( V_29 , L_60 , V_20 -> V_79 ) ;
fprintf ( V_29 , L_61 , V_20 -> V_80 ) ;
fprintf ( V_29 , L_62 , V_20 -> V_81 ) ;
fprintf ( V_29 , L_63 , V_20 -> V_82 ) ;
}
return 0 ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_83 ;
char * V_84 , * V_85 ;
if ( V_86 && ! ( V_18 -> V_53 & V_87 ) )
return 0 ;
if ( V_88 && ! ( V_18 -> V_53 & V_89 ) )
return 0 ;
V_83 = V_90 . V_91 + V_90 . V_92 / 1000000.0 ;
if ( V_18 == & V_93 . V_94 ) {
if ( V_30 )
V_31 += sprintf ( V_31 , L_64 ) ;
if ( V_30 && V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 )
V_31 += sprintf ( V_31 , L_65 ) ;
if ( V_33 )
V_31 += sprintf ( V_31 , L_4 L_65 ) ;
} else {
if ( V_30 ) {
if ( V_20 )
V_31 += sprintf ( V_31 , L_66 , V_20 -> V_68 ) ;
else
V_31 += sprintf ( V_31 , L_64 ) ;
}
if ( V_30 && V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 ) {
if ( V_19 )
V_31 += sprintf ( V_31 , L_67 , V_19 -> V_63 ) ;
else
V_31 += sprintf ( V_31 , L_65 ) ;
}
if ( V_33 )
V_31 += sprintf ( V_31 , L_68 , V_18 -> V_21 ) ;
}
if ( V_34 ) {
if ( V_30 || V_32 || V_33 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( ! V_95 )
V_31 += sprintf ( V_31 , L_69 , 100.0 * V_18 -> V_56 / V_18 -> V_54 ) ;
else
V_31 += sprintf ( V_31 , L_70 ) ;
}
if ( V_35 ) {
if ( ! V_96 ) {
V_31 += sprintf ( V_31 , L_71 ,
1.0 * V_18 -> V_54 / V_97 * V_18 -> V_55 /
V_18 -> V_56 / V_83 ) ;
} else {
if ( V_18 -> V_55 > V_18 -> V_54 || V_18 -> V_56 > V_18 -> V_54 ) {
V_31 += sprintf ( V_31 , L_72 ) ;
} else {
V_31 += sprintf ( V_31 , L_73 ,
1.0 * V_18 -> V_54 /
V_97 * V_18 -> V_55 /
V_18 -> V_56 / V_83 ) ;
}
}
}
V_31 += sprintf ( V_31 , L_74 , 1.0 * V_18 -> V_54 / V_97 / V_83 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_75 , V_18 -> V_62 ) ;
if ( V_37 )
V_31 += sprintf ( V_31 , L_76 , V_18 -> V_58 ) ;
if ( V_38 )
V_31 += sprintf ( V_31 , L_76 , V_18 -> V_59 ) ;
if ( V_39 )
V_31 += sprintf ( V_31 , L_77 , V_18 -> V_60 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_78 , V_18 -> V_61 ) ;
if ( V_34 ) {
if ( ! V_98 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_18 -> V_57 / V_18 -> V_54 ) ;
else
V_31 += sprintf ( V_31 , L_70 ) ;
}
if ( ! ( V_18 -> V_53 & V_87 ) )
goto V_99;
if ( V_34 && ! V_41 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_19 -> V_64 / V_18 -> V_54 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_19 -> V_65 / V_18 -> V_54 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_19 -> V_66 / V_18 -> V_54 ) ;
if ( V_43 )
V_31 += sprintf ( V_31 , L_80 , V_19 -> V_67 ) ;
if ( ! ( V_18 -> V_53 & V_89 ) )
goto V_99;
if ( V_44 )
V_31 += sprintf ( V_31 , L_80 , V_20 -> V_82 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_69 / V_18 -> V_54 ) ;
if ( V_34 && ! V_41 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_70 / V_18 -> V_54 ) ;
if ( V_34 && ! V_41 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_71 / V_18 -> V_54 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_72 / V_18 -> V_54 ) ;
if ( V_45 ) {
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_73 / V_18 -> V_54 ) ;
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_74 / V_18 -> V_54 ) ;
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_75 / V_18 -> V_54 ) ;
}
if ( V_83 < V_100 ) {
V_84 = L_81 ;
V_85 = L_79 ;
} else {
V_84 = L_82 ;
V_85 = L_83 ;
}
if ( V_46 & V_47 )
V_31 += sprintf ( V_31 , V_85 , V_20 -> V_76 * V_101 / V_83 ) ;
if ( V_46 & V_48 )
V_31 += sprintf ( V_31 , V_85 , V_20 -> V_77 * V_101 / V_83 ) ;
if ( V_46 & V_49 )
V_31 += sprintf ( V_31 , V_84 , V_20 -> V_78 * V_101 / V_83 ) ;
if ( V_46 & V_50 )
V_31 += sprintf ( V_31 , V_84 , V_20 -> V_79 * V_101 / V_83 ) ;
if ( V_46 & V_51 )
V_31 += sprintf ( V_31 , V_84 , 100.0 * V_20 -> V_80 * V_102 / V_83 ) ;
if ( V_46 & V_52 )
V_31 += sprintf ( V_31 , V_84 , 100.0 * V_20 -> V_81 * V_102 / V_83 ) ;
V_99:
V_31 += sprintf ( V_31 , L_34 ) ;
return 0 ;
}
void F_19 ()
{
fputs ( V_103 , stdout ) ;
fflush ( stdout ) ;
V_31 = V_103 ;
}
void F_20 ()
{
fputs ( V_103 , V_29 ) ;
V_31 = V_103 ;
}
void F_21 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_104 ;
if ( ! V_104 || ! V_105 )
F_16 () ;
if ( V_14 . V_106 > 1 )
F_18 ( & V_93 . V_94 , & V_93 . V_107 ,
& V_93 . V_108 ) ;
V_104 = 1 ;
if ( V_105 )
return;
F_3 ( F_18 , V_18 , V_19 , V_20 ) ;
}
void
F_22 ( struct V_6 * V_109 , struct V_6 * V_110 )
{
V_110 -> V_69 = V_109 -> V_69 - V_110 -> V_69 ;
V_110 -> V_70 = V_109 -> V_70 - V_110 -> V_70 ;
V_110 -> V_71 = V_109 -> V_71 - V_110 -> V_71 ;
V_110 -> V_72 = V_109 -> V_72 - V_110 -> V_72 ;
V_110 -> V_73 = V_109 -> V_73 - V_110 -> V_73 ;
V_110 -> V_74 = V_109 -> V_74 - V_110 -> V_74 ;
V_110 -> V_75 = V_109 -> V_75 - V_110 -> V_75 ;
V_110 -> V_82 = V_109 -> V_82 ;
F_23 ( V_109 -> V_76 , V_110 -> V_76 ) ;
F_23 ( V_109 -> V_77 , V_110 -> V_77 ) ;
F_23 ( V_109 -> V_78 , V_110 -> V_78 ) ;
F_23 ( V_109 -> V_79 , V_110 -> V_79 ) ;
F_23 ( V_109 -> V_80 , V_110 -> V_80 ) ;
F_23 ( V_109 -> V_81 , V_110 -> V_81 ) ;
}
void
F_24 ( struct V_5 * V_109 , struct V_5 * V_110 )
{
V_110 -> V_64 = V_109 -> V_64 - V_110 -> V_64 ;
V_110 -> V_65 = V_109 -> V_65 - V_110 -> V_65 ;
V_110 -> V_66 = V_109 -> V_66 - V_110 -> V_66 ;
V_110 -> V_67 = V_109 -> V_67 ;
}
void
F_25 ( struct V_4 * V_109 , struct V_4 * V_110 ,
struct V_5 * V_111 )
{
V_110 -> V_54 = V_109 -> V_54 - V_110 -> V_54 ;
if ( V_110 -> V_54 < ( 1000 * 1000 ) ) {
fprintf ( V_29 , L_84 ) ;
fprintf ( V_29 , L_85 ) ;
fprintf ( V_29 , L_86 ) ;
exit ( - 3 ) ;
}
V_110 -> V_57 = V_109 -> V_57 - V_110 -> V_57 ;
if ( ( V_109 -> V_55 > V_110 -> V_55 ) && ( V_109 -> V_56 > V_110 -> V_56 ) ) {
V_110 -> V_55 = V_109 -> V_55 - V_110 -> V_55 ;
V_110 -> V_56 = V_109 -> V_56 - V_110 -> V_56 ;
} else {
if ( ! V_96 ) {
fprintf ( V_29 , L_87 , V_112 ) ;
fprintf ( V_29 , L_88 ) ;
fprintf ( V_29 , L_89 ) ;
V_96 = 1 ;
}
V_95 = 1 ;
V_98 = 1 ;
}
if ( V_113 ) {
} else {
if ( ( V_110 -> V_56 + V_111 -> V_64 + V_111 -> V_65 + V_111 -> V_66 ) > V_110 -> V_54 )
V_110 -> V_57 = 0 ;
else {
V_110 -> V_57 = V_110 -> V_54 - V_110 -> V_56 - V_111 -> V_64
- V_111 -> V_65 - V_111 -> V_66 ;
}
}
if ( V_110 -> V_56 == 0 ) {
if ( V_114 > 1 ) fprintf ( V_29 , L_90 , V_110 -> V_21 ) ;
V_110 -> V_56 = 1 ;
}
V_110 -> V_58 = V_109 -> V_58 - V_110 -> V_58 ;
V_110 -> V_58 &= 0xFFFFFFFF ;
V_110 -> V_59 = V_109 -> V_59 - V_110 -> V_59 ;
V_110 -> V_60 = V_109 -> V_60 ;
V_110 -> V_61 = V_109 -> V_61 ;
if ( V_36 )
V_110 -> V_62 = V_109 -> V_62 - V_110 -> V_62 ;
}
int F_26 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_115 ,
struct V_5 * V_116 , struct V_6 * V_117 )
{
if ( V_18 -> V_53 & V_87 )
F_24 ( V_19 , V_116 ) ;
F_25 ( V_18 , V_115 , V_116 ) ;
if ( V_18 -> V_53 & V_89 )
F_22 ( V_20 , V_117 ) ;
return 0 ;
}
void F_27 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
V_18 -> V_54 = 0 ;
V_18 -> V_55 = 0 ;
V_18 -> V_56 = 0 ;
V_18 -> V_57 = 0 ;
V_18 -> V_62 = 0 ;
V_18 -> V_58 = 0 ;
V_18 -> V_59 = 0 ;
V_18 -> V_53 = V_87 | V_89 ;
V_19 -> V_64 = 0 ;
V_19 -> V_65 = 0 ;
V_19 -> V_66 = 0 ;
V_19 -> V_67 = 0 ;
V_20 -> V_69 = 0 ;
V_20 -> V_70 = 0 ;
V_20 -> V_71 = 0 ;
V_20 -> V_72 = 0 ;
V_20 -> V_73 = 0 ;
V_20 -> V_74 = 0 ;
V_20 -> V_75 = 0 ;
V_20 -> V_76 = 0 ;
V_20 -> V_79 = 0 ;
V_20 -> V_77 = 0 ;
V_20 -> V_78 = 0 ;
V_20 -> V_80 = 0 ;
V_20 -> V_81 = 0 ;
V_20 -> V_82 = 0 ;
}
int F_28 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_93 . V_94 . V_54 += V_18 -> V_54 ;
V_93 . V_94 . V_55 += V_18 -> V_55 ;
V_93 . V_94 . V_56 += V_18 -> V_56 ;
V_93 . V_94 . V_57 += V_18 -> V_57 ;
V_93 . V_94 . V_58 += V_18 -> V_58 ;
V_93 . V_94 . V_59 += V_18 -> V_59 ;
if ( ! ( V_18 -> V_53 & V_87 ) )
return 0 ;
V_93 . V_107 . V_64 += V_19 -> V_64 ;
V_93 . V_107 . V_65 += V_19 -> V_65 ;
V_93 . V_107 . V_66 += V_19 -> V_66 ;
V_93 . V_107 . V_67 = F_29 ( V_93 . V_107 . V_67 , V_19 -> V_67 ) ;
if ( ! ( V_18 -> V_53 & V_89 ) )
return 0 ;
V_93 . V_108 . V_69 += V_20 -> V_69 ;
V_93 . V_108 . V_70 += V_20 -> V_70 ;
V_93 . V_108 . V_71 += V_20 -> V_71 ;
V_93 . V_108 . V_72 += V_20 -> V_72 ;
V_93 . V_108 . V_73 += V_20 -> V_73 ;
V_93 . V_108 . V_74 += V_20 -> V_74 ;
V_93 . V_108 . V_75 += V_20 -> V_75 ;
V_93 . V_108 . V_76 += V_20 -> V_76 ;
V_93 . V_108 . V_79 += V_20 -> V_79 ;
V_93 . V_108 . V_77 += V_20 -> V_77 ;
V_93 . V_108 . V_78 += V_20 -> V_78 ;
V_93 . V_108 . V_82 = F_29 ( V_93 . V_108 . V_82 , V_20 -> V_82 ) ;
V_93 . V_108 . V_80 += V_20 -> V_80 ;
V_93 . V_108 . V_81 += V_20 -> V_81 ;
return 0 ;
}
void F_30 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_27 ( & V_93 . V_94 , & V_93 . V_107 , & V_93 . V_108 ) ;
F_3 ( F_28 , V_18 , V_19 , V_20 ) ;
V_93 . V_94 . V_54 /= V_14 . V_106 ;
V_93 . V_94 . V_55 /= V_14 . V_106 ;
V_93 . V_94 . V_56 /= V_14 . V_106 ;
V_93 . V_94 . V_57 /= V_14 . V_106 ;
V_93 . V_94 . V_58 /= V_14 . V_106 ;
V_93 . V_94 . V_58 &= 0xFFFFFFFF ;
V_93 . V_94 . V_59 /= V_14 . V_106 ;
V_93 . V_107 . V_64 /= V_14 . V_118 ;
V_93 . V_107 . V_65 /= V_14 . V_118 ;
V_93 . V_107 . V_66 /= V_14 . V_118 ;
V_93 . V_108 . V_69 /= V_14 . V_15 ;
V_93 . V_108 . V_70 /= V_14 . V_15 ;
V_93 . V_108 . V_71 /= V_14 . V_15 ;
V_93 . V_108 . V_72 /= V_14 . V_15 ;
V_93 . V_108 . V_73 /= V_14 . V_15 ;
V_93 . V_108 . V_74 /= V_14 . V_15 ;
V_93 . V_108 . V_75 /= V_14 . V_15 ;
}
static unsigned long long F_31 ( void )
{
unsigned int V_119 , V_120 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_119 | ( ( unsigned long long ) V_120 ) << 32 ;
}
int F_32 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
unsigned long long V_25 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_91 , V_1 ) ;
return - 1 ;
}
V_18 -> V_54 = F_31 () ;
if ( V_35 ) {
if ( F_12 ( V_1 , V_121 , & V_18 -> V_55 ) )
return - 3 ;
if ( F_12 ( V_1 , V_122 , & V_18 -> V_56 ) )
return - 4 ;
}
if ( V_36 ) {
if ( F_12 ( V_1 , V_123 , & V_25 ) )
return - 5 ;
V_18 -> V_62 = V_25 & 0xFFFFFFFF ;
}
if ( V_37 ) {
if ( F_12 ( V_1 , V_37 , & V_25 ) )
return - 5 ;
V_18 -> V_58 = V_25 & 0xFFFFFFFF ;
}
if ( V_38 )
if ( F_12 ( V_1 , V_38 , & V_18 -> V_59 ) )
return - 5 ;
if ( V_39 ) {
if ( F_12 ( V_1 , V_39 , & V_25 ) )
return - 5 ;
V_18 -> V_60 = V_25 & 0xFFFFFFFF ;
}
if ( V_40 )
if ( F_12 ( V_1 , V_40 , & V_18 -> V_61 ) )
return - 5 ;
if ( V_113 ) {
if ( F_12 ( V_1 , V_124 , & V_18 -> V_57 ) )
return - 6 ;
}
if ( ! ( V_18 -> V_53 & V_87 ) )
return 0 ;
if ( V_34 && ! V_41 ) {
if ( F_12 ( V_1 , V_125 , & V_19 -> V_64 ) )
return - 6 ;
}
if ( V_34 ) {
if ( F_12 ( V_1 , V_126 , & V_19 -> V_65 ) )
return - 7 ;
}
if ( V_42 )
if ( F_12 ( V_1 , V_127 , & V_19 -> V_66 ) )
return - 8 ;
if ( V_43 ) {
if ( F_12 ( V_1 , V_128 , & V_25 ) )
return - 9 ;
V_19 -> V_67 = V_129 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
if ( ! ( V_18 -> V_53 & V_89 ) )
return 0 ;
if ( V_34 && ! V_41 ) {
if ( F_12 ( V_1 , V_130 , & V_20 -> V_70 ) )
return - 9 ;
if ( F_12 ( V_1 , V_131 , & V_20 -> V_71 ) )
return - 10 ;
}
if ( V_42 ) {
if ( F_12 ( V_1 , V_132 , & V_20 -> V_69 ) )
return - 11 ;
if ( F_12 ( V_1 , V_133 , & V_20 -> V_72 ) )
return - 12 ;
}
if ( V_45 ) {
if ( F_12 ( V_1 , V_134 , & V_20 -> V_73 ) )
return - 13 ;
if ( F_12 ( V_1 , V_135 , & V_20 -> V_74 ) )
return - 13 ;
if ( F_12 ( V_1 , V_136 , & V_20 -> V_75 ) )
return - 13 ;
}
if ( V_46 & V_47 ) {
if ( F_12 ( V_1 , V_137 , & V_25 ) )
return - 13 ;
V_20 -> V_76 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_48 ) {
if ( F_12 ( V_1 , V_138 , & V_25 ) )
return - 14 ;
V_20 -> V_77 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_50 ) {
if ( F_12 ( V_1 , V_139 , & V_25 ) )
return - 15 ;
V_20 -> V_79 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_49 ) {
if ( F_12 ( V_1 , V_140 , & V_25 ) )
return - 16 ;
V_20 -> V_78 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_51 ) {
if ( F_12 ( V_1 , V_141 , & V_25 ) )
return - 16 ;
V_20 -> V_80 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_52 ) {
if ( F_12 ( V_1 , V_142 , & V_25 ) )
return - 16 ;
V_20 -> V_81 = V_25 & 0xFFFFFFFF ;
}
if ( V_44 ) {
if ( F_12 ( V_1 , V_143 , & V_25 ) )
return - 17 ;
V_20 -> V_82 = V_129 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
return 0 ;
}
void F_33 ( void )
{
unsigned long long V_25 ;
unsigned int V_144 ;
if ( ! V_145 )
return;
F_12 ( 0 , V_146 , & V_25 ) ;
fprintf ( V_29 , L_92 , V_25 ) ;
V_144 = ( V_25 >> 40 ) & 0xFF ;
fprintf ( V_29 , L_93 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 8 ) & 0xFF ;
fprintf ( V_29 , L_94 ,
V_144 , V_147 , V_144 * V_147 ) ;
F_12 ( 0 , V_148 , & V_25 ) ;
fprintf ( V_29 , L_95 ,
V_25 , V_25 & 0x2 ? L_96 : L_97 ) ;
if ( ! V_149 )
goto V_150;
F_12 ( 0 , V_151 , & V_25 ) ;
fprintf ( V_29 , L_98 , V_25 ) ;
V_144 = ( V_25 >> 56 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_99 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 48 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_100 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 40 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_101 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 32 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_102 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 24 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_103 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 16 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_104 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 8 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_105 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 0 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_106 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_150:
F_12 ( 0 , V_152 , & V_25 ) ;
#define F_34 (1UL << 27)
#define F_35 (1UL << 28)
fprintf ( V_29 , L_107 , V_25 ) ;
fprintf ( V_29 , L_108 ,
( V_25 & F_35 ) ? L_109 : L_110 ,
( V_25 & F_34 ) ? L_111 : L_110 ,
( V_25 & V_153 ) ? L_112 : L_110 ,
( V_25 & V_154 ) ? L_113 : L_110 ,
( V_25 & ( 1 << 15 ) ) ? L_110 : L_114 ,
( unsigned int ) V_25 & 7 ) ;
switch( V_25 & 0x7 ) {
case 0 :
fprintf ( V_29 , V_41 ? L_115 : L_116 ) ;
break;
case 1 :
fprintf ( V_29 , V_41 ? L_115 : V_42 ? L_117 : L_116 ) ;
break;
case 2 :
fprintf ( V_29 , V_41 ? L_118 : V_42 ? L_119 : L_120 ) ;
break;
case 3 :
fprintf ( V_29 , V_41 ? L_118 : L_121 ) ;
break;
case 4 :
fprintf ( V_29 , V_41 ? L_122 : L_123 ) ;
break;
case 5 :
fprintf ( V_29 , V_41 ? L_118 : V_42 ? L_124 : L_118 ) ;
break;
case 6 :
fprintf ( V_29 , V_41 ? L_121 : L_118 ) ;
break;
case 7 :
fprintf ( V_29 , V_41 ? L_123 : L_125 ) ;
break;
default:
fprintf ( V_29 , L_118 ) ;
}
fprintf ( V_29 , L_126 ) ;
if ( ! V_155 )
return;
F_12 ( 0 , V_156 , & V_25 ) ;
fprintf ( V_29 , L_127 , V_25 ) ;
V_144 = ( V_25 >> 56 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_128 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 48 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_129 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 40 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_130 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 32 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_131 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 24 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_132 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 16 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_133 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 8 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_134 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 0 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_135 ,
V_144 , V_147 , V_144 * V_147 ) ;
}
void F_36 ( void )
{
F_37 ( V_3 ) ;
V_3 = NULL ;
V_3 = 0 ;
F_37 ( V_23 ) ;
V_23 = NULL ;
V_22 = 0 ;
free ( V_157 ) ;
free ( V_158 ) ;
free ( V_159 ) ;
V_157 = NULL ;
V_158 = NULL ;
V_159 = NULL ;
free ( V_160 ) ;
free ( V_161 ) ;
free ( V_162 ) ;
V_160 = NULL ;
V_161 = NULL ;
V_162 = NULL ;
free ( V_103 ) ;
V_103 = NULL ;
V_31 = NULL ;
}
int F_38 ( int V_1 )
{
char V_163 [ 64 ] ;
T_3 * V_164 ;
int V_165 ;
sprintf ( V_163 , L_136 , V_1 ) ;
V_164 = fopen ( V_163 , L_137 ) ;
if ( V_164 == NULL ) {
perror ( V_163 ) ;
exit ( 1 ) ;
}
fscanf ( V_164 , L_138 , & V_165 ) ;
fclose ( V_164 ) ;
return ( V_1 == V_165 ) ;
}
int F_39 ( int V_1 )
{
char V_163 [ 64 ] ;
T_3 * V_164 ;
int V_165 ;
sprintf ( V_163 , L_139 , V_1 ) ;
V_164 = fopen ( V_163 , L_137 ) ;
if ( V_164 == NULL ) {
perror ( V_163 ) ;
exit ( 1 ) ;
}
fscanf ( V_164 , L_138 , & V_165 ) ;
fclose ( V_164 ) ;
return ( V_1 == V_165 ) ;
}
int F_40 ( int V_1 )
{
char V_163 [ 80 ] ;
T_3 * V_164 ;
int V_166 ;
sprintf ( V_163 , L_140 , V_1 ) ;
V_164 = fopen ( V_163 , L_137 ) ;
if ( V_164 == NULL ) {
perror ( V_163 ) ;
exit ( 1 ) ;
}
fscanf ( V_164 , L_138 , & V_166 ) ;
fclose ( V_164 ) ;
return V_166 ;
}
int F_41 ( int V_1 )
{
char V_163 [ 80 ] ;
T_3 * V_164 ;
int V_167 ;
sprintf ( V_163 , L_141 , V_1 ) ;
V_164 = fopen ( V_163 , L_137 ) ;
if ( V_164 == NULL ) {
perror ( V_163 ) ;
exit ( 1 ) ;
}
fscanf ( V_164 , L_138 , & V_167 ) ;
fclose ( V_164 ) ;
return V_167 ;
}
int F_42 ( int V_1 )
{
char V_163 [ 80 ] ;
T_3 * V_164 ;
int V_168 , V_169 ;
int V_170 ;
char V_171 ;
sprintf ( V_163 , L_136 , V_1 ) ;
V_164 = fopen ( V_163 , L_137 ) ;
if ( V_164 == NULL ) {
perror ( V_163 ) ;
exit ( 1 ) ;
}
V_170 = fscanf ( V_164 , L_142 , & V_168 , & V_171 , & V_169 ) ;
fclose ( V_164 ) ;
if ( V_170 == 3 )
return 2 ;
else
return 1 ;
}
int F_43 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_172 , struct V_5 * V_173 ,
struct V_6 * V_174 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_115 ;
struct V_5 * V_19 , * V_116 ;
struct V_6 * V_20 , * V_117 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_115 = F_5 ( V_172 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_116 = F_6 ( V_173 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_117 = F_7 ( V_174 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_115 , V_116 , V_117 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_44 ( int (F_4)( int ) )
{
T_3 * V_175 ;
int V_176 ;
int V_10 ;
V_175 = fopen ( V_177 , L_137 ) ;
if ( V_175 == NULL ) {
perror ( V_177 ) ;
exit ( 1 ) ;
}
V_10 = fscanf ( V_175 , L_143 ) ;
if ( V_10 != 0 ) {
perror ( L_144 ) ;
exit ( 1 ) ;
}
while ( 1 ) {
V_10 = fscanf ( V_175 , L_145 , & V_176 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_176 ) ;
if ( V_10 ) {
fclose ( V_175 ) ;
return ( V_10 ) ;
}
}
fclose ( V_175 ) ;
return 0 ;
}
void F_45 ( void )
{
F_36 () ;
F_46 () ;
printf ( L_146 , V_14 . V_106 ) ;
}
int F_47 ( int V_1 )
{
if ( V_14 . V_178 < V_1 )
V_14 . V_178 = V_1 ;
V_14 . V_106 += 1 ;
return 0 ;
}
int F_48 ( int V_1 )
{
F_10 ( V_1 , V_2 , V_3 ) ;
return 0 ;
}
void F_49 ()
{
int V_10 ;
int V_179 = 0 ;
V_180:
V_179 ++ ;
V_10 = F_3 ( F_32 , V_181 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
if ( V_179 > 1 ) {
exit ( V_10 ) ;
}
F_45 () ;
goto V_180;
}
V_179 = 0 ;
F_50 ( & V_182 , (struct V_183 * ) NULL ) ;
while ( 1 ) {
if ( F_44 ( F_1 ) ) {
F_45 () ;
goto V_180;
}
F_51 ( V_184 ) ;
V_10 = F_3 ( F_32 , V_185 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_45 () ;
goto V_180;
}
F_50 ( & V_186 , (struct V_183 * ) NULL ) ;
F_52 ( & V_186 , & V_182 , & V_90 ) ;
F_43 ( F_26 , V_185 , V_181 ) ;
F_30 ( V_181 ) ;
F_21 ( V_181 ) ;
F_19 () ;
F_51 ( V_184 ) ;
V_10 = F_3 ( F_32 , V_181 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_45 () ;
goto V_180;
}
F_50 ( & V_182 , (struct V_183 * ) NULL ) ;
F_52 ( & V_182 , & V_186 , & V_90 ) ;
F_43 ( F_26 , V_181 , V_185 ) ;
F_30 ( V_185 ) ;
F_21 ( V_185 ) ;
F_19 () ;
}
}
void F_53 ()
{
struct V_187 V_188 ;
if ( V_187 ( L_147 , & V_188 ) ) {
fprintf ( V_29 , L_148 ) ;
fprintf ( V_29 , L_149 ) ;
exit ( - 5 ) ;
}
}
void F_54 ()
{
if ( F_55 () != 0 ) {
fprintf ( V_29 , L_150 ) ;
exit ( - 6 ) ;
}
}
int F_56 ( unsigned int V_189 , unsigned int V_190 )
{
if ( ! V_191 )
return 0 ;
if ( V_189 != 6 )
return 0 ;
switch ( V_190 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x25 :
case 0x2C :
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
case 0x3C :
case 0x3F :
case 0x45 :
case 0x46 :
case 0x37 :
case 0x4D :
return 1 ;
case 0x2E :
case 0x2F :
default:
return 0 ;
}
}
int F_57 ( unsigned int V_189 , unsigned int V_190 )
{
if ( ! V_191 )
return 0 ;
if ( V_189 != 6 )
return 0 ;
switch ( V_190 ) {
case 0x3E :
return 1 ;
default:
return 0 ;
}
}
int F_58 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
char * V_192 ;
int V_1 ;
if ( ! V_193 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_53 & V_87 ) || ! ( V_18 -> V_53 & V_89 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_91 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_194 , & V_25 ) )
return 0 ;
switch ( V_25 & 0x7 ) {
case V_195 :
V_192 = L_151 ;
break;
case V_196 :
V_192 = L_152 ;
break;
case V_197 :
V_192 = L_153 ;
break;
default:
V_192 = L_154 ;
break;
}
fprintf ( V_29 , L_155 , V_1 , V_25 , V_192 ) ;
return 0 ;
}
double F_59 ( V_190 )
{
unsigned long long V_25 ;
if ( V_46 & V_198 )
if ( ! F_12 ( 0 , V_199 , & V_25 ) )
return ( ( V_25 >> 0 ) & V_200 ) * V_201 ;
switch ( V_190 ) {
case 0x37 :
case 0x4D :
return 30.0 ;
default:
return 135.0 ;
}
}
void F_60 ( unsigned int V_189 , unsigned int V_190 )
{
unsigned long long V_25 ;
unsigned int V_202 ;
double V_203 ;
if ( ! V_191 )
return;
if ( V_189 != 6 )
return;
switch ( V_190 ) {
case 0x2A :
case 0x3A :
case 0x3C :
case 0x3F :
case 0x45 :
case 0x46 :
V_46 = V_47 | V_48 | V_204 | V_49 | V_198 ;
break;
case 0x2D :
case 0x3E :
V_46 = V_47 | V_48 | V_204 | V_50 | V_51 | V_52 | V_198 ;
break;
case 0x37 :
case 0x4D :
V_46 = V_47 | V_48 ;
break;
default:
return;
}
if ( F_12 ( 0 , V_205 , & V_25 ) )
return;
V_201 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
if ( V_190 == 0x37 )
V_101 = 1.0 * ( 1 << ( V_25 >> 8 & 0x1F ) ) / 1000000 ;
else
V_101 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_202 = V_25 >> 16 & 0xF ;
if ( V_202 == 0 )
V_202 = 0xA ;
V_102 = 1.0 / ( 1 << ( V_202 ) ) ;
V_203 = F_59 ( V_190 ) ;
V_100 = 0xFFFFFFFF * V_101 / V_203 ;
if ( V_114 )
fprintf ( V_29 , L_156 , V_100 , V_203 ) ;
return;
}
int F_61 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_206 ;
int V_1 ;
if ( ! ( V_43 || V_44 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_53 & V_87 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_91 , V_1 ) ;
return - 1 ;
}
if ( V_44 && ( V_18 -> V_53 & V_89 ) ) {
if ( F_12 ( V_1 , V_143 , & V_25 ) )
return 0 ;
V_206 = ( V_25 >> 16 ) & 0x7F ;
fprintf ( V_29 , L_157 ,
V_1 , V_25 , V_129 - V_206 ) ;
#ifdef F_62
if ( F_12 ( V_1 , V_207 , & V_25 ) )
return 0 ;
V_206 = ( V_25 >> 16 ) & 0x7F ;
V_208 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_158 ,
V_1 , V_25 , V_129 - V_206 , V_129 - V_208 ) ;
#endif
}
if ( V_43 ) {
unsigned int V_209 ;
if ( F_12 ( V_1 , V_128 , & V_25 ) )
return 0 ;
V_206 = ( V_25 >> 16 ) & 0x7F ;
V_209 = ( V_25 >> 27 ) & 0xF ;
fprintf ( V_29 , L_159 ,
V_1 , V_25 , V_129 - V_206 , V_209 ) ;
#ifdef F_62
if ( F_12 ( V_1 , V_210 , & V_25 ) )
return 0 ;
V_206 = ( V_25 >> 16 ) & 0x7F ;
V_208 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_160 ,
V_1 , V_25 , V_129 - V_206 , V_129 - V_208 ) ;
#endif
}
return 0 ;
}
void F_63 ( int V_1 , unsigned long long V_25 , char * V_211 )
{
fprintf ( V_29 , L_161 ,
V_1 , V_211 ,
( ( V_25 >> 15 ) & 1 ) ? L_96 : L_97 ,
( ( V_25 >> 0 ) & 0x7FFF ) * V_201 ,
( 1.0 + ( ( ( V_25 >> 22 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 17 ) & 0x1F ) ) * V_102 ,
( ( ( V_25 >> 16 ) & 1 ) ? L_96 : L_97 ) ) ;
return;
}
int F_64 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
if ( ! V_46 )
return 0 ;
if ( ! ( V_18 -> V_53 & V_87 ) || ! ( V_18 -> V_53 & V_89 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_91 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_205 , & V_25 ) )
return - 1 ;
if ( V_114 ) {
fprintf ( V_29 , L_162
L_163 , V_1 , V_25 ,
V_201 , V_101 , V_102 ) ;
}
if ( V_46 & V_198 ) {
if ( F_12 ( V_1 , V_199 , & V_25 ) )
return - 5 ;
fprintf ( V_29 , L_164 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_200 ) * V_201 ,
( ( V_25 >> 16 ) & V_200 ) * V_201 ,
( ( V_25 >> 32 ) & V_200 ) * V_201 ,
( ( V_25 >> 48 ) & V_212 ) * V_102 ) ;
}
if ( V_46 & V_47 ) {
if ( F_12 ( V_1 , V_213 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_165 ,
V_1 , V_25 , ( V_25 >> 63 ) & 1 ? L_110 : L_114 ) ;
F_63 ( V_1 , V_25 , L_166 ) ;
fprintf ( V_29 , L_167 ,
V_1 ,
( ( V_25 >> 47 ) & 1 ) ? L_96 : L_97 ,
( ( V_25 >> 32 ) & 0x7FFF ) * V_201 ,
( 1.0 + ( ( ( V_25 >> 54 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 49 ) & 0x1F ) ) * V_102 ,
( ( V_25 >> 48 ) & 1 ) ? L_96 : L_97 ) ;
}
if ( V_46 & V_50 ) {
if ( F_12 ( V_1 , V_214 , & V_25 ) )
return - 6 ;
fprintf ( V_29 , L_168 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_200 ) * V_201 ,
( ( V_25 >> 16 ) & V_200 ) * V_201 ,
( ( V_25 >> 32 ) & V_200 ) * V_201 ,
( ( V_25 >> 48 ) & V_212 ) * V_102 ) ;
if ( F_12 ( V_1 , V_215 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_169 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_110 : L_114 ) ;
F_63 ( V_1 , V_25 , L_170 ) ;
}
if ( V_46 & V_204 ) {
if ( V_114 ) {
if ( F_12 ( V_1 , V_216 , & V_25 ) )
return - 7 ;
fprintf ( V_29 , L_171 , V_1 , V_25 & 0xF ) ;
}
}
if ( V_46 & V_48 ) {
if ( V_114 ) {
if ( F_12 ( V_1 , V_217 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_172 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_110 : L_114 ) ;
F_63 ( V_1 , V_25 , L_173 ) ;
}
}
if ( V_46 & V_49 ) {
if ( V_114 ) {
if ( F_12 ( V_1 , V_218 , & V_25 ) )
return - 8 ;
fprintf ( V_29 , L_174 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_219 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_175 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_110 : L_114 ) ;
F_63 ( V_1 , V_25 , L_176 ) ;
}
}
return 0 ;
}
int F_65 ( unsigned int V_189 , unsigned int V_190 )
{
if ( ! V_191 )
return 0 ;
switch ( V_190 ) {
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
case 0x3C :
case 0x3F :
case 0x45 :
case 0x46 :
return 1 ;
}
return 0 ;
}
int F_66 ( unsigned int V_189 , unsigned int V_190 )
{
if ( ! V_191 )
return 0 ;
switch ( V_190 ) {
case 0x45 :
return 1 ;
}
return 0 ;
}
int F_67 ( unsigned int V_189 , unsigned int V_190 )
{
if ( ! V_191 )
return 0 ;
switch ( V_190 ) {
case 0x37 :
case 0x4D :
return 1 ;
}
return 0 ;
}
double F_68 ( void )
{
unsigned long long V_25 = 3 ;
unsigned int V_220 ;
double V_221 ;
if ( F_12 ( 0 , V_222 , & V_25 ) )
fprintf ( V_29 , L_177 ) ;
V_220 = V_25 & 0xf ;
if ( V_220 >= V_223 ) {
fprintf ( V_29 , L_178 , V_220 ) ;
V_25 = 3 ;
}
V_221 = V_224 [ V_220 ] ;
fprintf ( V_29 , L_179 , V_221 ) ;
return V_221 ;
}
double F_69 ( unsigned int V_189 , unsigned int V_190 )
{
if ( F_65 ( V_189 , V_190 ) )
return 100.00 ;
else if ( F_67 ( V_189 , V_190 ) )
return F_68 () ;
else
return 133.33 ;
}
int F_70 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_225 ;
int V_1 ;
if ( ! ( V_43 || V_44 ) )
return 0 ;
if ( ! ( V_18 -> V_53 & V_87 ) || ! ( V_18 -> V_53 & V_89 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_91 , V_1 ) ;
return - 1 ;
}
if ( V_226 != 0 ) {
V_129 = V_226 ;
fprintf ( V_29 , L_180 ,
V_1 , V_129 ) ;
return 0 ;
}
if ( ! V_145 )
goto V_227;
if ( F_12 ( 0 , V_228 , & V_25 ) )
goto V_227;
V_225 = ( V_25 >> 16 ) & 0x7F ;
if ( V_114 )
fprintf ( V_29 , L_181 ,
V_1 , V_25 , V_225 ) ;
if ( V_225 < 85 || V_225 > 127 )
goto V_227;
V_129 = V_225 ;
return 0 ;
V_227:
V_129 = V_229 ;
fprintf ( V_29 , L_182 ,
V_1 , V_129 ) ;
return 0 ;
}
void F_71 ()
{
unsigned int V_230 , V_231 , V_232 , V_233 , V_234 ;
unsigned int V_235 , V_189 , V_190 , V_236 ;
V_230 = V_231 = V_232 = V_233 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0));
if ( V_231 == 0x756e6547 && V_233 == 0x49656e69 && V_232 == 0x6c65746e )
V_191 = 1 ;
if ( V_114 )
fprintf ( V_29 , L_183 ,
( char * ) & V_231 , ( char * ) & V_233 , ( char * ) & V_232 ) ;
asm("cpuid" : "=a" (fms), "=c" (ecx), "=d" (edx) : "a" (1) : "ebx");
V_189 = ( V_235 >> 8 ) & 0xf ;
V_190 = ( V_235 >> 4 ) & 0xf ;
V_236 = V_235 & 0xf ;
if ( V_189 == 6 || V_189 == 0xf )
V_190 += ( ( V_235 >> 16 ) & 0xf ) << 4 ;
if ( V_114 )
fprintf ( V_29 , L_184 ,
V_234 , V_189 , V_190 , V_236 , V_189 , V_190 , V_236 ) ;
if ( ! ( V_233 & ( 1 << 5 ) ) ) {
fprintf ( V_29 , L_185 ) ;
exit ( 1 ) ;
}
V_231 = V_232 = V_233 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000000));
if ( V_234 < 0x80000007 ) {
fprintf ( V_29 , L_186 , V_234 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000007));
V_237 = V_233 & ( 1 << 8 ) ;
if ( ! V_237 ) {
fprintf ( V_29 , L_187 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x6));
V_35 = V_232 & ( 1 << 0 ) ;
V_43 = V_230 & ( 1 << 0 ) ;
V_44 = V_230 & ( 1 << 6 ) ;
V_193 = V_232 & ( 1 << 3 ) ;
if ( V_114 )
fprintf ( V_29 , L_188 ,
V_35 ? L_189 : L_190 ,
V_43 ? L_191 : L_110 ,
V_44 ? L_192 : L_110 ,
V_193 ? L_193 : L_110 ) ;
if ( ! V_35 )
exit ( - 1 ) ;
V_145 = V_191 && V_237 ;
V_34 = V_191 ;
V_36 = V_34 ;
V_42 = F_65 ( V_189 , V_190 ) ;
V_45 = F_66 ( V_189 , V_190 ) ;
V_41 = F_67 ( V_189 , V_190 ) ;
V_147 = F_69 ( V_189 , V_190 ) ;
V_155 = F_56 ( V_189 , V_190 ) ;
V_149 = F_57 ( V_189 , V_190 ) ;
F_60 ( V_189 , V_190 ) ;
return;
}
void F_72 ()
{
fprintf ( V_29 , L_194 ,
V_112 ) ;
exit ( 1 ) ;
}
int F_73 ( const struct V_238 * V_239 )
{
if ( isdigit ( V_239 -> V_240 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_74 ( int V_241 )
{
return 0 ;
}
void F_75 ()
{
int V_220 ;
int V_242 = 0 ;
int V_243 = 0 ;
int V_244 = 0 ;
struct V_245 {
int V_63 ;
int V_246 ;
} * V_247 ;
V_14 . V_106 = 0 ;
V_14 . V_178 = 0 ;
F_44 ( F_47 ) ;
if ( ! V_105 && V_14 . V_106 > 1 )
V_33 = 1 ;
if ( V_114 > 1 )
fprintf ( V_29 , L_195 , V_14 . V_106 , V_14 . V_178 ) ;
V_247 = calloc ( 1 , ( V_14 . V_178 + 1 ) * sizeof( struct V_245 ) ) ;
if ( V_247 == NULL ) {
perror ( L_196 ) ;
exit ( 1 ) ;
}
V_3 = F_76 ( ( V_14 . V_178 + 1 ) ) ;
if ( V_3 == NULL ) {
perror ( L_197 ) ;
exit ( 3 ) ;
}
V_2 = F_77 ( ( V_14 . V_178 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_44 ( F_48 ) ;
V_23 = F_76 ( ( V_14 . V_178 + 1 ) ) ;
if ( V_23 == NULL ) {
perror ( L_197 ) ;
exit ( 3 ) ;
}
V_22 = F_77 ( ( V_14 . V_178 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_220 = 0 ; V_220 <= V_14 . V_178 ; ++ V_220 ) {
int V_248 ;
if ( F_1 ( V_220 ) ) {
if ( V_114 > 1 )
fprintf ( V_29 , L_198 , V_220 ) ;
continue;
}
V_247 [ V_220 ] . V_63 = F_41 ( V_220 ) ;
if ( V_247 [ V_220 ] . V_63 > V_242 )
V_242 = V_247 [ V_220 ] . V_63 ;
V_247 [ V_220 ] . V_246 = F_40 ( V_220 ) ;
if ( V_247 [ V_220 ] . V_246 > V_243 )
V_243 = V_247 [ V_220 ] . V_246 ;
V_248 = F_42 ( V_220 ) ;
if ( V_248 > V_244 )
V_244 = V_248 ;
if ( V_114 > 1 )
fprintf ( V_29 , L_199 ,
V_220 , V_247 [ V_220 ] . V_246 , V_247 [ V_220 ] . V_63 ) ;
}
V_14 . V_16 = V_242 + 1 ;
if ( V_114 > 1 )
fprintf ( V_29 , L_200 ,
V_242 , V_14 . V_16 ) ;
if ( ! V_105 && V_14 . V_16 > 1 )
V_32 = 1 ;
V_14 . V_15 = V_243 + 1 ;
if ( V_114 > 1 )
fprintf ( V_29 , L_201 ,
V_243 , V_14 . V_15 ) ;
if ( ! V_105 && V_14 . V_15 > 1 )
V_30 = 1 ;
V_14 . V_17 = V_244 ;
if ( V_114 > 1 )
fprintf ( V_29 , L_202 , V_244 ) ;
free ( V_247 ) ;
}
void
F_78 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_220 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_220 = 0 ; V_220 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_220 ++ )
( * V_18 ) [ V_220 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_220 = 0 ; V_220 < V_14 . V_16 * V_14 . V_15 ; V_220 ++ )
( * V_19 ) [ V_220 ] . V_63 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_220 = 0 ; V_220 < V_14 . V_15 ; V_220 ++ )
( * V_20 ) [ V_220 ] . V_68 = V_220 ;
return;
error:
perror ( L_203 ) ;
exit ( 1 ) ;
}
void F_79 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_249 , int V_250 ,
int V_251 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_249 , V_250 , V_251 ) ;
V_19 = F_6 ( V_8 , V_250 , V_251 ) ;
V_20 = F_7 ( V_9 , V_251 ) ;
V_18 -> V_21 = V_21 ;
if ( V_249 == 0 ) {
V_18 -> V_53 |= V_87 ;
if ( F_39 ( V_21 ) )
V_18 -> V_53 |= V_89 ;
}
V_19 -> V_63 = V_250 ;
V_20 -> V_68 = V_251 ;
}
int F_80 ( int V_21 )
{
int V_252 , V_253 , V_254 ;
V_254 = F_40 ( V_21 ) ;
V_253 = F_41 ( V_21 ) ;
if ( F_38 ( V_21 ) ) {
V_252 = 0 ;
V_14 . V_118 ++ ;
} else {
V_252 = 1 ;
}
F_79 ( V_181 , V_252 , V_253 , V_254 , V_21 ) ;
F_79 ( V_185 , V_252 , V_253 , V_254 , V_21 ) ;
return 0 ;
}
void F_81 ()
{
V_103 = calloc ( 1 , ( 1 + V_14 . V_106 ) * 256 ) ;
V_31 = V_103 ;
if ( V_31 == NULL ) {
perror ( L_204 ) ;
exit ( - 1 ) ;
}
}
void F_46 ( void )
{
F_75 () ;
F_78 ( & V_157 , & V_158 , & V_159 ) ;
F_78 ( & V_160 , & V_161 , & V_162 ) ;
F_81 () ;
F_44 ( F_80 ) ;
}
void F_82 ()
{
F_71 () ;
F_53 () ;
F_54 () ;
F_46 () ;
if ( V_114 )
F_33 () ;
if ( V_114 )
F_3 ( F_58 , V_185 ) ;
if ( V_114 )
F_3 ( F_64 , V_185 ) ;
F_3 ( F_70 , V_185 ) ;
if ( V_114 )
F_3 ( F_61 , V_185 ) ;
}
int F_83 ( char * * V_255 )
{
T_4 V_256 ;
int V_257 ;
V_257 = F_3 ( F_32 , V_181 ) ;
if ( V_257 )
exit ( V_257 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_50 ( & V_182 , (struct V_183 * ) NULL ) ;
V_256 = F_84 () ;
if ( ! V_256 ) {
F_85 ( V_255 [ 0 ] , V_255 ) ;
} else {
if ( V_256 == - 1 ) {
perror ( L_205 ) ;
exit ( 1 ) ;
}
signal ( V_258 , V_259 ) ;
signal ( V_260 , V_259 ) ;
if ( F_86 ( V_256 , & V_257 , 0 ) == - 1 ) {
perror ( L_206 ) ;
exit ( V_257 ) ;
}
}
F_3 ( F_32 , V_185 ) ;
F_50 ( & V_186 , (struct V_183 * ) NULL ) ;
F_52 ( & V_186 , & V_182 , & V_90 ) ;
F_43 ( F_26 , V_185 , V_181 ) ;
F_30 ( V_181 ) ;
F_21 ( V_181 ) ;
F_20 () ;
fprintf ( V_29 , L_207 , V_90 . V_91 + V_90 . V_92 / 1000000.0 ) ;
return V_257 ;
}
void F_87 ( int V_261 , char * * V_255 )
{
int V_262 ;
V_112 = V_255 [ 0 ] ;
while ( ( V_262 = F_88 ( V_261 , V_255 , L_208 ) ) != - 1 ) {
switch ( V_262 ) {
case 'p' :
V_86 ++ ;
break;
case 'P' :
V_88 ++ ;
break;
case 'S' :
V_105 ++ ;
break;
case 'v' :
V_114 ++ ;
break;
case 'i' :
V_184 = atoi ( V_263 ) ;
break;
case 'c' :
sscanf ( V_263 , L_209 , & V_37 ) ;
break;
case 'C' :
sscanf ( V_263 , L_209 , & V_38 ) ;
break;
case 'm' :
sscanf ( V_263 , L_209 , & V_39 ) ;
break;
case 'M' :
sscanf ( V_263 , L_209 , & V_40 ) ;
break;
case 'R' :
V_264 ++ ;
break;
case 'T' :
V_226 = atoi ( V_263 ) ;
break;
default:
F_72 () ;
}
}
}
int main ( int V_261 , char * * V_255 )
{
F_87 ( V_261 , V_255 ) ;
if ( V_114 )
fprintf ( V_29 , L_210
L_211 ) ;
F_82 () ;
if ( V_261 - V_265 )
return F_83 ( V_255 + V_265 ) ;
else
F_49 () ;
return 0 ;
}
