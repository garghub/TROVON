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
fprintf ( V_29 , L_2 , V_26 , ( unsigned long long ) V_24 ) ;
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
if ( V_46 && ! V_47 ) {
if ( V_46 & V_48 )
V_31 += sprintf ( V_31 , L_28 ) ;
if ( V_46 & V_49 )
V_31 += sprintf ( V_31 , L_29 ) ;
if ( V_46 & V_50 )
V_31 += sprintf ( V_31 , L_30 ) ;
if ( V_46 & V_51 )
V_31 += sprintf ( V_31 , L_31 ) ;
if ( V_46 & V_52 )
V_31 += sprintf ( V_31 , L_32 ) ;
if ( V_46 & V_53 )
V_31 += sprintf ( V_31 , L_33 ) ;
} else {
if ( V_46 & V_48 )
V_31 += sprintf ( V_31 , L_34 ) ;
if ( V_46 & V_49 )
V_31 += sprintf ( V_31 , L_35 ) ;
if ( V_46 & V_50 )
V_31 += sprintf ( V_31 , L_36 ) ;
if ( V_46 & V_51 )
V_31 += sprintf ( V_31 , L_31 ) ;
if ( V_46 & V_52 )
V_31 += sprintf ( V_31 , L_32 ) ;
if ( V_46 & V_53 )
V_31 += sprintf ( V_31 , L_33 ) ;
V_31 += sprintf ( V_31 , L_37 ) ;
}
V_31 += sprintf ( V_31 , L_38 ) ;
}
int F_17 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_31 += sprintf ( V_31 , L_39 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
V_31 += sprintf ( V_31 , L_40 ,
V_18 -> V_21 , V_18 -> V_54 ) ;
V_31 += sprintf ( V_31 , L_41 , V_18 -> V_55 ) ;
V_31 += sprintf ( V_31 , L_42 , V_18 -> V_56 ) ;
V_31 += sprintf ( V_31 , L_43 , V_18 -> V_57 ) ;
V_31 += sprintf ( V_31 , L_44 , V_18 -> V_58 ) ;
V_31 += sprintf ( V_31 , L_45 ,
V_37 , V_18 -> V_59 ) ;
V_31 += sprintf ( V_31 , L_46 ,
V_38 , V_18 -> V_60 ) ;
V_31 += sprintf ( V_31 , L_45 ,
V_39 , V_18 -> V_61 ) ;
V_31 += sprintf ( V_31 , L_46 ,
V_40 , V_18 -> V_62 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_47 , V_18 -> V_63 ) ;
}
if ( V_19 ) {
V_31 += sprintf ( V_31 , L_48 , V_19 -> V_64 ) ;
V_31 += sprintf ( V_31 , L_49 , V_19 -> V_65 ) ;
V_31 += sprintf ( V_31 , L_50 , V_19 -> V_66 ) ;
V_31 += sprintf ( V_31 , L_51 , V_19 -> V_67 ) ;
V_31 += sprintf ( V_31 , L_52 , V_19 -> V_68 ) ;
}
if ( V_20 ) {
V_31 += sprintf ( V_31 , L_53 , V_20 -> V_69 ) ;
V_31 += sprintf ( V_31 , L_54 , V_20 -> V_70 ) ;
V_31 += sprintf ( V_31 , L_55 , V_20 -> V_71 ) ;
V_31 += sprintf ( V_31 , L_56 , V_20 -> V_72 ) ;
V_31 += sprintf ( V_31 , L_57 , V_20 -> V_73 ) ;
V_31 += sprintf ( V_31 , L_58 , V_20 -> V_74 ) ;
V_31 += sprintf ( V_31 , L_59 , V_20 -> V_75 ) ;
V_31 += sprintf ( V_31 , L_60 , V_20 -> V_76 ) ;
V_31 += sprintf ( V_31 , L_61 , V_20 -> V_77 ) ;
V_31 += sprintf ( V_31 , L_62 , V_20 -> V_78 ) ;
V_31 += sprintf ( V_31 , L_63 , V_20 -> V_79 ) ;
V_31 += sprintf ( V_31 , L_64 , V_20 -> V_80 ) ;
V_31 += sprintf ( V_31 , L_65 ,
V_20 -> V_81 ) ;
V_31 += sprintf ( V_31 , L_66 ,
V_20 -> V_82 ) ;
V_31 += sprintf ( V_31 , L_67 , V_20 -> V_83 ) ;
}
V_31 += sprintf ( V_31 , L_38 ) ;
return 0 ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_84 ;
char * V_85 , * V_86 ;
if ( V_87 && ! ( V_18 -> V_54 & V_88 ) )
return 0 ;
if ( V_89 && ! ( V_18 -> V_54 & V_90 ) )
return 0 ;
V_84 = V_91 . V_92 + V_91 . V_93 / 1000000.0 ;
if ( V_18 == & V_94 . V_95 ) {
if ( V_30 )
V_31 += sprintf ( V_31 , L_68 ) ;
if ( V_30 && V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 )
V_31 += sprintf ( V_31 , L_69 ) ;
if ( V_33 )
V_31 += sprintf ( V_31 , L_4 L_69 ) ;
} else {
if ( V_30 ) {
if ( V_20 )
V_31 += sprintf ( V_31 , L_70 , V_20 -> V_69 ) ;
else
V_31 += sprintf ( V_31 , L_68 ) ;
}
if ( V_30 && V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 ) {
if ( V_19 )
V_31 += sprintf ( V_31 , L_71 , V_19 -> V_64 ) ;
else
V_31 += sprintf ( V_31 , L_69 ) ;
}
if ( V_33 )
V_31 += sprintf ( V_31 , L_72 , V_18 -> V_21 ) ;
}
if ( V_34 ) {
if ( V_30 || V_32 || V_33 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( ! V_96 )
V_31 += sprintf ( V_31 , L_73 , 100.0 * V_18 -> V_57 / V_18 -> V_55 ) ;
else
V_31 += sprintf ( V_31 , L_74 ) ;
}
if ( V_35 ) {
if ( ! V_97 ) {
V_31 += sprintf ( V_31 , L_75 ,
1.0 * V_18 -> V_55 / V_98 * V_18 -> V_56 /
V_18 -> V_57 / V_84 ) ;
} else {
if ( V_18 -> V_56 > V_18 -> V_55 || V_18 -> V_57 > V_18 -> V_55 ) {
V_31 += sprintf ( V_31 , L_76 ) ;
} else {
V_31 += sprintf ( V_31 , L_77 ,
1.0 * V_18 -> V_55 /
V_98 * V_18 -> V_56 /
V_18 -> V_57 / V_84 ) ;
}
}
}
V_31 += sprintf ( V_31 , L_78 , 1.0 * V_18 -> V_55 / V_98 / V_84 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_79 , V_18 -> V_63 ) ;
if ( V_37 )
V_31 += sprintf ( V_31 , L_80 , V_18 -> V_59 ) ;
if ( V_38 )
V_31 += sprintf ( V_31 , L_80 , V_18 -> V_60 ) ;
if ( V_39 )
V_31 += sprintf ( V_31 , L_81 , V_18 -> V_61 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_82 , V_18 -> V_62 ) ;
if ( V_34 ) {
if ( ! V_99 )
V_31 += sprintf ( V_31 , L_83 , 100.0 * V_18 -> V_58 / V_18 -> V_55 ) ;
else
V_31 += sprintf ( V_31 , L_74 ) ;
}
if ( ! ( V_18 -> V_54 & V_88 ) )
goto V_100;
if ( V_34 && ! V_41 )
V_31 += sprintf ( V_31 , L_83 , 100.0 * V_19 -> V_65 / V_18 -> V_55 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_83 , 100.0 * V_19 -> V_66 / V_18 -> V_55 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_83 , 100.0 * V_19 -> V_67 / V_18 -> V_55 ) ;
if ( V_43 )
V_31 += sprintf ( V_31 , L_84 , V_19 -> V_68 ) ;
if ( ! ( V_18 -> V_54 & V_90 ) )
goto V_100;
if ( V_44 )
V_31 += sprintf ( V_31 , L_84 , V_20 -> V_83 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_83 , 100.0 * V_20 -> V_70 / V_18 -> V_55 ) ;
if ( V_34 && ! V_41 )
V_31 += sprintf ( V_31 , L_83 , 100.0 * V_20 -> V_71 / V_18 -> V_55 ) ;
if ( V_34 && ! V_41 )
V_31 += sprintf ( V_31 , L_83 , 100.0 * V_20 -> V_72 / V_18 -> V_55 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_83 , 100.0 * V_20 -> V_73 / V_18 -> V_55 ) ;
if ( V_45 ) {
V_31 += sprintf ( V_31 , L_83 , 100.0 * V_20 -> V_74 / V_18 -> V_55 ) ;
V_31 += sprintf ( V_31 , L_83 , 100.0 * V_20 -> V_75 / V_18 -> V_55 ) ;
V_31 += sprintf ( V_31 , L_83 , 100.0 * V_20 -> V_76 / V_18 -> V_55 ) ;
}
if ( V_84 < V_101 ) {
V_85 = L_85 ;
V_86 = L_83 ;
} else {
V_85 = L_86 ;
V_86 = L_87 ;
}
if ( V_46 && ! V_47 ) {
if ( V_46 & V_48 )
V_31 += sprintf ( V_31 , V_86 , V_20 -> V_77 * V_102 / V_84 ) ;
if ( V_46 & V_49 )
V_31 += sprintf ( V_31 , V_86 , V_20 -> V_78 * V_102 / V_84 ) ;
if ( V_46 & V_50 )
V_31 += sprintf ( V_31 , V_85 , V_20 -> V_79 * V_102 / V_84 ) ;
if ( V_46 & V_51 )
V_31 += sprintf ( V_31 , V_85 , V_20 -> V_80 * V_102 / V_84 ) ;
if ( V_46 & V_52 )
V_31 += sprintf ( V_31 , V_85 , 100.0 * V_20 -> V_81 * V_103 / V_84 ) ;
if ( V_46 & V_53 )
V_31 += sprintf ( V_31 , V_85 , 100.0 * V_20 -> V_82 * V_103 / V_84 ) ;
} else {
if ( V_46 & V_48 )
V_31 += sprintf ( V_31 , V_86 ,
V_20 -> V_77 * V_102 ) ;
if ( V_46 & V_49 )
V_31 += sprintf ( V_31 , V_86 ,
V_20 -> V_78 * V_102 ) ;
if ( V_46 & V_50 )
V_31 += sprintf ( V_31 , V_85 ,
V_20 -> V_79 * V_102 ) ;
if ( V_46 & V_51 )
V_31 += sprintf ( V_31 , V_85 ,
V_20 -> V_80 * V_102 ) ;
if ( V_46 & V_52 )
V_31 += sprintf ( V_31 , V_85 , 100.0 * V_20 -> V_81 * V_103 / V_84 ) ;
if ( V_46 & V_53 )
V_31 += sprintf ( V_31 , V_85 , 100.0 * V_20 -> V_82 * V_103 / V_84 ) ;
V_31 += sprintf ( V_31 , V_85 , V_84 ) ;
}
V_100:
V_31 += sprintf ( V_31 , L_38 ) ;
return 0 ;
}
void F_19 ()
{
fputs ( V_104 , stdout ) ;
fflush ( stdout ) ;
V_31 = V_104 ;
}
void F_20 ()
{
fputs ( V_104 , V_29 ) ;
V_31 = V_104 ;
}
void F_21 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_105 ;
if ( ! V_105 || ! V_106 )
F_16 () ;
if ( V_14 . V_107 > 1 )
F_18 ( & V_94 . V_95 , & V_94 . V_108 ,
& V_94 . V_109 ) ;
V_105 = 1 ;
if ( V_106 )
return;
F_3 ( F_18 , V_18 , V_19 , V_20 ) ;
}
void
F_22 ( struct V_6 * V_110 , struct V_6 * V_111 )
{
V_111 -> V_70 = V_110 -> V_70 - V_111 -> V_70 ;
V_111 -> V_71 = V_110 -> V_71 - V_111 -> V_71 ;
V_111 -> V_72 = V_110 -> V_72 - V_111 -> V_72 ;
V_111 -> V_73 = V_110 -> V_73 - V_111 -> V_73 ;
V_111 -> V_74 = V_110 -> V_74 - V_111 -> V_74 ;
V_111 -> V_75 = V_110 -> V_75 - V_111 -> V_75 ;
V_111 -> V_76 = V_110 -> V_76 - V_111 -> V_76 ;
V_111 -> V_83 = V_110 -> V_83 ;
F_23 ( V_110 -> V_77 , V_111 -> V_77 ) ;
F_23 ( V_110 -> V_78 , V_111 -> V_78 ) ;
F_23 ( V_110 -> V_79 , V_111 -> V_79 ) ;
F_23 ( V_110 -> V_80 , V_111 -> V_80 ) ;
F_23 ( V_110 -> V_81 , V_111 -> V_81 ) ;
F_23 ( V_110 -> V_82 , V_111 -> V_82 ) ;
}
void
F_24 ( struct V_5 * V_110 , struct V_5 * V_111 )
{
V_111 -> V_65 = V_110 -> V_65 - V_111 -> V_65 ;
V_111 -> V_66 = V_110 -> V_66 - V_111 -> V_66 ;
V_111 -> V_67 = V_110 -> V_67 - V_111 -> V_67 ;
V_111 -> V_68 = V_110 -> V_68 ;
}
void
F_25 ( struct V_4 * V_110 , struct V_4 * V_111 ,
struct V_5 * V_112 )
{
V_111 -> V_55 = V_110 -> V_55 - V_111 -> V_55 ;
if ( V_111 -> V_55 < ( 1000 * 1000 ) )
F_26 ( - 3 , L_88
L_89
L_90 ) ;
V_111 -> V_58 = V_110 -> V_58 - V_111 -> V_58 ;
if ( ( V_110 -> V_56 > V_111 -> V_56 ) && ( V_110 -> V_57 > V_111 -> V_57 ) ) {
V_111 -> V_56 = V_110 -> V_56 - V_111 -> V_56 ;
V_111 -> V_57 = V_110 -> V_57 - V_111 -> V_57 ;
} else {
if ( ! V_97 ) {
fprintf ( V_29 , L_91 , V_113 ) ;
fprintf ( V_29 , L_92 ) ;
fprintf ( V_29 , L_93 ) ;
V_97 = 1 ;
}
V_96 = 1 ;
V_99 = 1 ;
}
if ( V_114 ) {
} else {
if ( ( V_111 -> V_57 + V_112 -> V_65 + V_112 -> V_66 + V_112 -> V_67 ) > V_111 -> V_55 )
V_111 -> V_58 = 0 ;
else {
V_111 -> V_58 = V_111 -> V_55 - V_111 -> V_57 - V_112 -> V_65
- V_112 -> V_66 - V_112 -> V_67 ;
}
}
if ( V_111 -> V_57 == 0 ) {
if ( V_115 > 1 ) fprintf ( V_29 , L_94 , V_111 -> V_21 ) ;
V_111 -> V_57 = 1 ;
}
V_111 -> V_59 = V_110 -> V_59 - V_111 -> V_59 ;
V_111 -> V_59 &= 0xFFFFFFFF ;
V_111 -> V_60 = V_110 -> V_60 - V_111 -> V_60 ;
V_111 -> V_61 = V_110 -> V_61 ;
V_111 -> V_62 = V_110 -> V_62 ;
if ( V_36 )
V_111 -> V_63 = V_110 -> V_63 - V_111 -> V_63 ;
}
int F_27 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_116 ,
struct V_5 * V_117 , struct V_6 * V_118 )
{
if ( V_18 -> V_54 & V_88 )
F_24 ( V_19 , V_117 ) ;
F_25 ( V_18 , V_116 , V_117 ) ;
if ( V_18 -> V_54 & V_90 )
F_22 ( V_20 , V_118 ) ;
return 0 ;
}
void F_28 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
V_18 -> V_55 = 0 ;
V_18 -> V_56 = 0 ;
V_18 -> V_57 = 0 ;
V_18 -> V_58 = 0 ;
V_18 -> V_63 = 0 ;
V_18 -> V_59 = 0 ;
V_18 -> V_60 = 0 ;
V_18 -> V_54 = V_88 | V_90 ;
V_19 -> V_65 = 0 ;
V_19 -> V_66 = 0 ;
V_19 -> V_67 = 0 ;
V_19 -> V_68 = 0 ;
V_20 -> V_70 = 0 ;
V_20 -> V_71 = 0 ;
V_20 -> V_72 = 0 ;
V_20 -> V_73 = 0 ;
V_20 -> V_74 = 0 ;
V_20 -> V_75 = 0 ;
V_20 -> V_76 = 0 ;
V_20 -> V_77 = 0 ;
V_20 -> V_80 = 0 ;
V_20 -> V_78 = 0 ;
V_20 -> V_79 = 0 ;
V_20 -> V_81 = 0 ;
V_20 -> V_82 = 0 ;
V_20 -> V_83 = 0 ;
}
int F_29 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_94 . V_95 . V_55 += V_18 -> V_55 ;
V_94 . V_95 . V_56 += V_18 -> V_56 ;
V_94 . V_95 . V_57 += V_18 -> V_57 ;
V_94 . V_95 . V_58 += V_18 -> V_58 ;
V_94 . V_95 . V_59 += V_18 -> V_59 ;
V_94 . V_95 . V_60 += V_18 -> V_60 ;
if ( ! ( V_18 -> V_54 & V_88 ) )
return 0 ;
V_94 . V_108 . V_65 += V_19 -> V_65 ;
V_94 . V_108 . V_66 += V_19 -> V_66 ;
V_94 . V_108 . V_67 += V_19 -> V_67 ;
V_94 . V_108 . V_68 = F_30 ( V_94 . V_108 . V_68 , V_19 -> V_68 ) ;
if ( ! ( V_18 -> V_54 & V_90 ) )
return 0 ;
V_94 . V_109 . V_70 += V_20 -> V_70 ;
V_94 . V_109 . V_71 += V_20 -> V_71 ;
V_94 . V_109 . V_72 += V_20 -> V_72 ;
V_94 . V_109 . V_73 += V_20 -> V_73 ;
V_94 . V_109 . V_74 += V_20 -> V_74 ;
V_94 . V_109 . V_75 += V_20 -> V_75 ;
V_94 . V_109 . V_76 += V_20 -> V_76 ;
V_94 . V_109 . V_77 += V_20 -> V_77 ;
V_94 . V_109 . V_80 += V_20 -> V_80 ;
V_94 . V_109 . V_78 += V_20 -> V_78 ;
V_94 . V_109 . V_79 += V_20 -> V_79 ;
V_94 . V_109 . V_83 = F_30 ( V_94 . V_109 . V_83 , V_20 -> V_83 ) ;
V_94 . V_109 . V_81 += V_20 -> V_81 ;
V_94 . V_109 . V_82 += V_20 -> V_82 ;
return 0 ;
}
void F_31 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_28 ( & V_94 . V_95 , & V_94 . V_108 , & V_94 . V_109 ) ;
F_3 ( F_29 , V_18 , V_19 , V_20 ) ;
V_94 . V_95 . V_55 /= V_14 . V_107 ;
V_94 . V_95 . V_56 /= V_14 . V_107 ;
V_94 . V_95 . V_57 /= V_14 . V_107 ;
V_94 . V_95 . V_58 /= V_14 . V_107 ;
V_94 . V_95 . V_59 /= V_14 . V_107 ;
V_94 . V_95 . V_59 &= 0xFFFFFFFF ;
V_94 . V_95 . V_60 /= V_14 . V_107 ;
V_94 . V_108 . V_65 /= V_14 . V_119 ;
V_94 . V_108 . V_66 /= V_14 . V_119 ;
V_94 . V_108 . V_67 /= V_14 . V_119 ;
V_94 . V_109 . V_70 /= V_14 . V_15 ;
V_94 . V_109 . V_71 /= V_14 . V_15 ;
V_94 . V_109 . V_72 /= V_14 . V_15 ;
V_94 . V_109 . V_73 /= V_14 . V_15 ;
V_94 . V_109 . V_74 /= V_14 . V_15 ;
V_94 . V_109 . V_75 /= V_14 . V_15 ;
V_94 . V_109 . V_76 /= V_14 . V_15 ;
}
static unsigned long long F_32 ( void )
{
unsigned int V_120 , V_121 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_120 | ( ( unsigned long long ) V_121 ) << 32 ;
}
int F_33 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
unsigned long long V_25 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_95 , V_1 ) ;
return - 1 ;
}
V_18 -> V_55 = F_32 () ;
if ( V_35 ) {
if ( F_12 ( V_1 , V_122 , & V_18 -> V_56 ) )
return - 3 ;
if ( F_12 ( V_1 , V_123 , & V_18 -> V_57 ) )
return - 4 ;
}
if ( V_36 ) {
if ( F_12 ( V_1 , V_124 , & V_25 ) )
return - 5 ;
V_18 -> V_63 = V_25 & 0xFFFFFFFF ;
}
if ( V_37 ) {
if ( F_12 ( V_1 , V_37 , & V_25 ) )
return - 5 ;
V_18 -> V_59 = V_25 & 0xFFFFFFFF ;
}
if ( V_38 )
if ( F_12 ( V_1 , V_38 , & V_18 -> V_60 ) )
return - 5 ;
if ( V_39 ) {
if ( F_12 ( V_1 , V_39 , & V_25 ) )
return - 5 ;
V_18 -> V_61 = V_25 & 0xFFFFFFFF ;
}
if ( V_40 )
if ( F_12 ( V_1 , V_40 , & V_18 -> V_62 ) )
return - 5 ;
if ( V_114 ) {
if ( F_12 ( V_1 , V_125 , & V_18 -> V_58 ) )
return - 6 ;
}
if ( ! ( V_18 -> V_54 & V_88 ) )
return 0 ;
if ( V_34 && ! V_41 ) {
if ( F_12 ( V_1 , V_126 , & V_19 -> V_65 ) )
return - 6 ;
}
if ( V_34 ) {
if ( F_12 ( V_1 , V_127 , & V_19 -> V_66 ) )
return - 7 ;
}
if ( V_42 )
if ( F_12 ( V_1 , V_128 , & V_19 -> V_67 ) )
return - 8 ;
if ( V_43 ) {
if ( F_12 ( V_1 , V_129 , & V_25 ) )
return - 9 ;
V_19 -> V_68 = V_130 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
if ( ! ( V_18 -> V_54 & V_90 ) )
return 0 ;
if ( V_34 && ! V_41 ) {
if ( F_12 ( V_1 , V_131 , & V_20 -> V_71 ) )
return - 9 ;
if ( F_12 ( V_1 , V_132 , & V_20 -> V_72 ) )
return - 10 ;
}
if ( V_42 ) {
if ( F_12 ( V_1 , V_133 , & V_20 -> V_70 ) )
return - 11 ;
if ( F_12 ( V_1 , V_134 , & V_20 -> V_73 ) )
return - 12 ;
}
if ( V_45 ) {
if ( F_12 ( V_1 , V_135 , & V_20 -> V_74 ) )
return - 13 ;
if ( F_12 ( V_1 , V_136 , & V_20 -> V_75 ) )
return - 13 ;
if ( F_12 ( V_1 , V_137 , & V_20 -> V_76 ) )
return - 13 ;
}
if ( V_46 & V_48 ) {
if ( F_12 ( V_1 , V_138 , & V_25 ) )
return - 13 ;
V_20 -> V_77 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_49 ) {
if ( F_12 ( V_1 , V_139 , & V_25 ) )
return - 14 ;
V_20 -> V_78 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_51 ) {
if ( F_12 ( V_1 , V_140 , & V_25 ) )
return - 15 ;
V_20 -> V_80 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_50 ) {
if ( F_12 ( V_1 , V_141 , & V_25 ) )
return - 16 ;
V_20 -> V_79 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_52 ) {
if ( F_12 ( V_1 , V_142 , & V_25 ) )
return - 16 ;
V_20 -> V_81 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_53 ) {
if ( F_12 ( V_1 , V_143 , & V_25 ) )
return - 16 ;
V_20 -> V_82 = V_25 & 0xFFFFFFFF ;
}
if ( V_44 ) {
if ( F_12 ( V_1 , V_144 , & V_25 ) )
return - 17 ;
V_20 -> V_83 = V_130 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
return 0 ;
}
void F_34 ( void )
{
unsigned long long V_25 ;
unsigned int V_145 ;
if ( ! V_146 )
return;
F_12 ( 0 , V_147 , & V_25 ) ;
fprintf ( V_29 , L_96 , V_25 ) ;
V_145 = ( V_25 >> 40 ) & 0xFF ;
fprintf ( V_29 , L_97 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 8 ) & 0xFF ;
fprintf ( V_29 , L_98 ,
V_145 , V_148 , V_145 * V_148 ) ;
F_12 ( 0 , V_149 , & V_25 ) ;
fprintf ( V_29 , L_99 ,
V_25 , V_25 & 0x2 ? L_100 : L_101 ) ;
if ( ! V_150 )
goto V_151;
F_12 ( 0 , V_152 , & V_25 ) ;
fprintf ( V_29 , L_102 , V_25 ) ;
V_145 = ( V_25 >> 56 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_103 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 48 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_104 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 40 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_105 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 32 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_106 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 24 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_107 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 16 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_108 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 8 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_109 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 0 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_110 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_151:
F_12 ( 0 , V_153 , & V_25 ) ;
#define F_35 (1UL << 27)
#define F_36 (1UL << 28)
fprintf ( V_29 , L_111 , V_25 ) ;
fprintf ( V_29 , L_112 ,
( V_25 & F_36 ) ? L_113 : L_114 ,
( V_25 & F_35 ) ? L_115 : L_114 ,
( V_25 & V_154 ) ? L_116 : L_114 ,
( V_25 & V_155 ) ? L_117 : L_114 ,
( V_25 & ( 1 << 15 ) ) ? L_114 : L_118 ,
( unsigned int ) V_25 & 7 ) ;
switch( V_25 & 0x7 ) {
case 0 :
fprintf ( V_29 , V_41 ? L_119 : L_120 ) ;
break;
case 1 :
fprintf ( V_29 , V_41 ? L_119 : V_42 ? L_121 : L_120 ) ;
break;
case 2 :
fprintf ( V_29 , V_41 ? L_122 : V_42 ? L_123 : L_124 ) ;
break;
case 3 :
fprintf ( V_29 , V_41 ? L_122 : L_125 ) ;
break;
case 4 :
fprintf ( V_29 , V_41 ? L_126 : L_127 ) ;
break;
case 5 :
fprintf ( V_29 , V_41 ? L_122 : V_42 ? L_128 : L_122 ) ;
break;
case 6 :
fprintf ( V_29 , V_41 ? L_125 : L_122 ) ;
break;
case 7 :
fprintf ( V_29 , V_41 ? L_127 : L_129 ) ;
break;
default:
fprintf ( V_29 , L_122 ) ;
}
fprintf ( V_29 , L_130 ) ;
if ( ! V_156 )
return;
F_12 ( 0 , V_157 , & V_25 ) ;
fprintf ( V_29 , L_131 , V_25 ) ;
V_145 = ( V_25 >> 56 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_132 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 48 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_133 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 40 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_134 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 32 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_135 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 24 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_136 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 16 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_137 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 8 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_138 ,
V_145 , V_148 , V_145 * V_148 ) ;
V_145 = ( V_25 >> 0 ) & 0xFF ;
if ( V_145 )
fprintf ( V_29 , L_139 ,
V_145 , V_148 , V_145 * V_148 ) ;
}
void F_37 ( void )
{
F_38 ( V_3 ) ;
V_3 = NULL ;
V_3 = 0 ;
F_38 ( V_23 ) ;
V_23 = NULL ;
V_22 = 0 ;
free ( V_158 ) ;
free ( V_159 ) ;
free ( V_160 ) ;
V_158 = NULL ;
V_159 = NULL ;
V_160 = NULL ;
free ( V_161 ) ;
free ( V_162 ) ;
free ( V_163 ) ;
V_161 = NULL ;
V_162 = NULL ;
V_163 = NULL ;
free ( V_104 ) ;
V_104 = NULL ;
V_31 = NULL ;
}
T_3 * F_39 ( const char * V_164 , const char * V_165 )
{
T_3 * V_166 = fopen ( V_164 , L_140 ) ;
if ( ! V_166 )
F_40 ( 1 , L_141 , V_164 ) ;
return V_166 ;
}
int F_41 ( const char * V_167 , ... )
{
T_4 args ;
char V_164 [ V_168 ] ;
T_3 * V_166 ;
int V_169 ;
va_start ( args , V_167 ) ;
vsnprintf ( V_164 , sizeof( V_164 ) , V_167 , args ) ;
va_end ( args ) ;
V_166 = F_39 ( V_164 , L_140 ) ;
if ( fscanf ( V_166 , L_142 , & V_169 ) != 1 )
F_40 ( 1 , L_143 , V_164 ) ;
fclose ( V_166 ) ;
return V_169 ;
}
int F_42 ( int V_1 )
{
return V_1 == F_41 ( L_144 , V_1 ) ;
}
int F_43 ( int V_1 )
{
return V_1 == F_41 ( L_145 , V_1 ) ;
}
int F_44 ( int V_1 )
{
return F_41 ( L_146 , V_1 ) ;
}
int F_45 ( int V_1 )
{
return F_41 ( L_147 , V_1 ) ;
}
int F_46 ( int V_1 )
{
char V_164 [ 80 ] ;
T_3 * V_166 ;
int V_170 , V_171 ;
int V_172 ;
char V_173 ;
sprintf ( V_164 , L_144 , V_1 ) ;
V_166 = F_39 ( V_164 , L_140 ) ;
V_172 = fscanf ( V_166 , L_148 , & V_170 , & V_173 , & V_171 ) ;
fclose ( V_166 ) ;
if ( V_172 == 3 )
return 2 ;
else
return 1 ;
}
int F_47 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_174 , struct V_5 * V_175 ,
struct V_6 * V_176 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_116 ;
struct V_5 * V_19 , * V_117 ;
struct V_6 * V_20 , * V_118 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_116 = F_5 ( V_174 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_117 = F_6 ( V_175 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_118 = F_7 ( V_176 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_116 , V_117 , V_118 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_48 ( int (F_4)( int ) )
{
T_3 * V_177 ;
int V_178 ;
int V_10 ;
V_177 = F_39 ( V_179 , L_140 ) ;
V_10 = fscanf ( V_177 , L_149 ) ;
if ( V_10 != 0 )
F_40 ( 1 , L_150 , V_179 ) ;
while ( 1 ) {
V_10 = fscanf ( V_177 , L_151 , & V_178 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_178 ) ;
if ( V_10 ) {
fclose ( V_177 ) ;
return ( V_10 ) ;
}
}
fclose ( V_177 ) ;
return 0 ;
}
void F_49 ( void )
{
F_37 () ;
F_50 () ;
printf ( L_152 , V_14 . V_107 ) ;
}
int F_51 ( int V_1 )
{
if ( V_14 . V_180 < V_1 )
V_14 . V_180 = V_1 ;
V_14 . V_107 += 1 ;
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
int V_181 = 0 ;
V_182:
V_181 ++ ;
V_10 = F_3 ( F_33 , V_183 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
if ( V_181 > 1 ) {
exit ( V_10 ) ;
}
F_49 () ;
goto V_182;
}
V_181 = 0 ;
F_54 ( & V_184 , (struct V_185 * ) NULL ) ;
while ( 1 ) {
if ( F_48 ( F_1 ) ) {
F_49 () ;
goto V_182;
}
F_55 ( V_186 ) ;
V_10 = F_3 ( F_33 , V_187 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_49 () ;
goto V_182;
}
F_54 ( & V_188 , (struct V_185 * ) NULL ) ;
F_56 ( & V_188 , & V_184 , & V_91 ) ;
F_47 ( F_27 , V_187 , V_183 ) ;
F_31 ( V_183 ) ;
F_21 ( V_183 ) ;
F_19 () ;
F_55 ( V_186 ) ;
V_10 = F_3 ( F_33 , V_183 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_49 () ;
goto V_182;
}
F_54 ( & V_184 , (struct V_185 * ) NULL ) ;
F_56 ( & V_184 , & V_188 , & V_91 ) ;
F_47 ( F_27 , V_183 , V_187 ) ;
F_31 ( V_187 ) ;
F_21 ( V_187 ) ;
F_19 () ;
}
}
void F_57 ()
{
struct V_189 V_190 ;
if ( V_189 ( L_153 , & V_190 ) )
F_40 ( - 5 , L_154
L_155 ) ;
}
void F_58 ()
{
if ( F_59 () != 0 )
F_26 ( - 6 , L_156 ) ;
}
int F_60 ( unsigned int V_191 , unsigned int V_192 )
{
if ( ! V_193 )
return 0 ;
if ( V_191 != 6 )
return 0 ;
switch ( V_192 ) {
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
int F_61 ( unsigned int V_191 , unsigned int V_192 )
{
if ( ! V_193 )
return 0 ;
if ( V_191 != 6 )
return 0 ;
switch ( V_192 ) {
case 0x3E :
return 1 ;
default:
return 0 ;
}
}
int F_62 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
char * V_194 ;
int V_1 ;
if ( ! V_195 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_54 & V_88 ) || ! ( V_18 -> V_54 & V_90 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_95 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_196 , & V_25 ) )
return 0 ;
switch ( V_25 & 0x7 ) {
case V_197 :
V_194 = L_157 ;
break;
case V_198 :
V_194 = L_158 ;
break;
case V_199 :
V_194 = L_159 ;
break;
default:
V_194 = L_160 ;
break;
}
fprintf ( V_29 , L_161 , V_1 , V_25 , V_194 ) ;
return 0 ;
}
double F_63 ( V_192 )
{
unsigned long long V_25 ;
if ( V_46 & V_200 )
if ( ! F_12 ( 0 , V_201 , & V_25 ) )
return ( ( V_25 >> 0 ) & V_202 ) * V_203 ;
switch ( V_192 ) {
case 0x37 :
case 0x4D :
return 30.0 ;
default:
return 135.0 ;
}
}
void F_64 ( unsigned int V_191 , unsigned int V_192 )
{
unsigned long long V_25 ;
unsigned int V_204 ;
double V_205 ;
if ( ! V_193 )
return;
if ( V_191 != 6 )
return;
switch ( V_192 ) {
case 0x2A :
case 0x3A :
case 0x3C :
case 0x45 :
case 0x46 :
V_46 = V_48 | V_49 | V_206 | V_50 | V_200 ;
break;
case 0x3F :
V_46 = V_48 | V_51 | V_53 | V_52 | V_200 ;
break;
case 0x2D :
case 0x3E :
V_46 = V_48 | V_49 | V_206 | V_51 | V_52 | V_53 | V_200 ;
break;
case 0x37 :
case 0x4D :
V_46 = V_48 | V_49 ;
break;
default:
return;
}
if ( F_12 ( 0 , V_207 , & V_25 ) )
return;
V_203 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
if ( V_192 == 0x37 )
V_102 = 1.0 * ( 1 << ( V_25 >> 8 & 0x1F ) ) / 1000000 ;
else
V_102 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_204 = V_25 >> 16 & 0xF ;
if ( V_204 == 0 )
V_204 = 0xA ;
V_103 = 1.0 / ( 1 << ( V_204 ) ) ;
V_205 = F_63 ( V_192 ) ;
V_101 = 0xFFFFFFFF * V_102 / V_205 ;
if ( V_115 )
fprintf ( V_29 , L_162 , V_101 , V_205 ) ;
return;
}
int F_65 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_208 ;
int V_1 ;
if ( ! ( V_43 || V_44 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_54 & V_88 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_95 , V_1 ) ;
return - 1 ;
}
if ( V_44 && ( V_18 -> V_54 & V_90 ) ) {
if ( F_12 ( V_1 , V_144 , & V_25 ) )
return 0 ;
V_208 = ( V_25 >> 16 ) & 0x7F ;
fprintf ( V_29 , L_163 ,
V_1 , V_25 , V_130 - V_208 ) ;
#ifdef F_66
if ( F_12 ( V_1 , V_209 , & V_25 ) )
return 0 ;
V_208 = ( V_25 >> 16 ) & 0x7F ;
V_210 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_164 ,
V_1 , V_25 , V_130 - V_208 , V_130 - V_210 ) ;
#endif
}
if ( V_43 ) {
unsigned int V_211 ;
if ( F_12 ( V_1 , V_129 , & V_25 ) )
return 0 ;
V_208 = ( V_25 >> 16 ) & 0x7F ;
V_211 = ( V_25 >> 27 ) & 0xF ;
fprintf ( V_29 , L_165 ,
V_1 , V_25 , V_130 - V_208 , V_211 ) ;
#ifdef F_66
if ( F_12 ( V_1 , V_212 , & V_25 ) )
return 0 ;
V_208 = ( V_25 >> 16 ) & 0x7F ;
V_210 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_166 ,
V_1 , V_25 , V_130 - V_208 , V_130 - V_210 ) ;
#endif
}
return 0 ;
}
void F_67 ( int V_1 , unsigned long long V_25 , char * V_213 )
{
fprintf ( V_29 , L_167 ,
V_1 , V_213 ,
( ( V_25 >> 15 ) & 1 ) ? L_100 : L_101 ,
( ( V_25 >> 0 ) & 0x7FFF ) * V_203 ,
( 1.0 + ( ( ( V_25 >> 22 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 17 ) & 0x1F ) ) * V_103 ,
( ( ( V_25 >> 16 ) & 1 ) ? L_100 : L_101 ) ) ;
return;
}
int F_68 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
if ( ! V_46 )
return 0 ;
if ( ! ( V_18 -> V_54 & V_88 ) || ! ( V_18 -> V_54 & V_90 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_95 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_207 , & V_25 ) )
return - 1 ;
if ( V_115 ) {
fprintf ( V_29 , L_168
L_169 , V_1 , V_25 ,
V_203 , V_102 , V_103 ) ;
}
if ( V_46 & V_200 ) {
if ( F_12 ( V_1 , V_201 , & V_25 ) )
return - 5 ;
fprintf ( V_29 , L_170 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_202 ) * V_203 ,
( ( V_25 >> 16 ) & V_202 ) * V_203 ,
( ( V_25 >> 32 ) & V_202 ) * V_203 ,
( ( V_25 >> 48 ) & V_214 ) * V_103 ) ;
}
if ( V_46 & V_48 ) {
if ( F_12 ( V_1 , V_215 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_171 ,
V_1 , V_25 , ( V_25 >> 63 ) & 1 ? L_114 : L_118 ) ;
F_67 ( V_1 , V_25 , L_172 ) ;
fprintf ( V_29 , L_173 ,
V_1 ,
( ( V_25 >> 47 ) & 1 ) ? L_100 : L_101 ,
( ( V_25 >> 32 ) & 0x7FFF ) * V_203 ,
( 1.0 + ( ( ( V_25 >> 54 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 49 ) & 0x1F ) ) * V_103 ,
( ( V_25 >> 48 ) & 1 ) ? L_100 : L_101 ) ;
}
if ( V_46 & V_51 ) {
if ( F_12 ( V_1 , V_216 , & V_25 ) )
return - 6 ;
fprintf ( V_29 , L_174 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_202 ) * V_203 ,
( ( V_25 >> 16 ) & V_202 ) * V_203 ,
( ( V_25 >> 32 ) & V_202 ) * V_203 ,
( ( V_25 >> 48 ) & V_214 ) * V_103 ) ;
if ( F_12 ( V_1 , V_217 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_175 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_114 : L_118 ) ;
F_67 ( V_1 , V_25 , L_176 ) ;
}
if ( V_46 & V_206 ) {
if ( V_115 ) {
if ( F_12 ( V_1 , V_218 , & V_25 ) )
return - 7 ;
fprintf ( V_29 , L_177 , V_1 , V_25 & 0xF ) ;
}
}
if ( V_46 & V_49 ) {
if ( V_115 ) {
if ( F_12 ( V_1 , V_219 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_178 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_114 : L_118 ) ;
F_67 ( V_1 , V_25 , L_179 ) ;
}
}
if ( V_46 & V_50 ) {
if ( V_115 ) {
if ( F_12 ( V_1 , V_220 , & V_25 ) )
return - 8 ;
fprintf ( V_29 , L_180 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_221 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_181 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_114 : L_118 ) ;
F_67 ( V_1 , V_25 , L_182 ) ;
}
}
return 0 ;
}
int F_69 ( unsigned int V_191 , unsigned int V_192 )
{
if ( ! V_193 )
return 0 ;
switch ( V_192 ) {
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
int F_70 ( unsigned int V_191 , unsigned int V_192 )
{
if ( ! V_193 )
return 0 ;
switch ( V_192 ) {
case 0x45 :
return 1 ;
}
return 0 ;
}
int F_71 ( unsigned int V_191 , unsigned int V_192 )
{
if ( ! V_193 )
return 0 ;
switch ( V_192 ) {
case 0x37 :
case 0x4D :
return 1 ;
}
return 0 ;
}
double F_72 ( void )
{
unsigned long long V_25 = 3 ;
unsigned int V_222 ;
double V_223 ;
if ( F_12 ( 0 , V_224 , & V_25 ) )
fprintf ( V_29 , L_183 ) ;
V_222 = V_25 & 0xf ;
if ( V_222 >= V_225 ) {
fprintf ( V_29 , L_184 , V_222 ) ;
V_25 = 3 ;
}
V_223 = V_226 [ V_222 ] ;
fprintf ( V_29 , L_185 , V_223 ) ;
return V_223 ;
}
double F_73 ( unsigned int V_191 , unsigned int V_192 )
{
if ( F_69 ( V_191 , V_192 ) )
return 100.00 ;
else if ( F_71 ( V_191 , V_192 ) )
return F_72 () ;
else
return 133.33 ;
}
int F_74 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_227 ;
int V_1 ;
if ( ! ( V_43 || V_44 ) )
return 0 ;
if ( ! ( V_18 -> V_54 & V_88 ) || ! ( V_18 -> V_54 & V_90 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_95 , V_1 ) ;
return - 1 ;
}
if ( V_228 != 0 ) {
V_130 = V_228 ;
fprintf ( V_29 , L_186 ,
V_1 , V_130 ) ;
return 0 ;
}
if ( ! V_146 )
goto V_229;
if ( F_12 ( 0 , V_230 , & V_25 ) )
goto V_229;
V_227 = ( V_25 >> 16 ) & 0x7F ;
if ( V_115 )
fprintf ( V_29 , L_187 ,
V_1 , V_25 , V_227 ) ;
if ( V_227 < 85 || V_227 > 127 )
goto V_229;
V_130 = V_227 ;
return 0 ;
V_229:
V_130 = V_231 ;
fprintf ( V_29 , L_188 ,
V_1 , V_130 ) ;
return 0 ;
}
void F_75 ()
{
unsigned int V_232 , V_233 , V_234 , V_235 , V_236 ;
unsigned int V_237 , V_191 , V_192 , V_238 ;
V_232 = V_233 = V_234 = V_235 = 0 ;
F_76 ( 0 , & V_236 , & V_233 , & V_234 , & V_235 ) ;
if ( V_233 == 0x756e6547 && V_235 == 0x49656e69 && V_234 == 0x6c65746e )
V_193 = 1 ;
if ( V_115 )
fprintf ( V_29 , L_189 ,
( char * ) & V_233 , ( char * ) & V_235 , ( char * ) & V_234 ) ;
F_76 ( 1 , & V_237 , & V_233 , & V_234 , & V_235 ) ;
V_191 = ( V_237 >> 8 ) & 0xf ;
V_192 = ( V_237 >> 4 ) & 0xf ;
V_238 = V_237 & 0xf ;
if ( V_191 == 6 || V_191 == 0xf )
V_192 += ( ( V_237 >> 16 ) & 0xf ) << 4 ;
if ( V_115 )
fprintf ( V_29 , L_190 ,
V_236 , V_191 , V_192 , V_238 , V_191 , V_192 , V_238 ) ;
if ( ! ( V_235 & ( 1 << 5 ) ) )
F_26 ( 1 , L_191 ) ;
V_233 = V_234 = V_235 = 0 ;
F_76 ( 0x80000000 , & V_236 , & V_233 , & V_234 , & V_235 ) ;
if ( V_236 < 0x80000007 )
F_26 ( 1 , L_192 , V_236 ) ;
F_76 ( 0x80000007 , & V_232 , & V_233 , & V_234 , & V_235 ) ;
V_239 = V_235 & ( 1 << 8 ) ;
if ( ! V_239 )
F_26 ( 1 , L_193 ) ;
F_76 ( 0x6 , & V_232 , & V_233 , & V_234 , & V_235 ) ;
V_35 = V_234 & ( 1 << 0 ) ;
V_43 = V_232 & ( 1 << 0 ) ;
V_44 = V_232 & ( 1 << 6 ) ;
V_195 = V_234 & ( 1 << 3 ) ;
if ( V_115 )
fprintf ( V_29 , L_194 ,
V_35 ? L_195 : L_196 ,
V_43 ? L_197 : L_114 ,
V_44 ? L_198 : L_114 ,
V_195 ? L_199 : L_114 ) ;
if ( ! V_35 )
F_26 ( - 1 , L_200 ) ;
V_146 = V_193 && V_239 ;
V_34 = V_193 ;
V_36 = V_34 ;
V_42 = F_69 ( V_191 , V_192 ) ;
V_45 = F_70 ( V_191 , V_192 ) ;
V_41 = F_71 ( V_191 , V_192 ) ;
V_148 = F_73 ( V_191 , V_192 ) ;
V_156 = F_60 ( V_191 , V_192 ) ;
V_150 = F_61 ( V_191 , V_192 ) ;
F_64 ( V_191 , V_192 ) ;
return;
}
void F_77 ()
{
F_26 ( 1 , L_201 ,
V_113 ) ;
}
int F_78 ( const struct V_240 * V_241 )
{
if ( isdigit ( V_241 -> V_242 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_79 ( int V_243 )
{
return 0 ;
}
void F_80 ()
{
int V_222 ;
int V_244 = 0 ;
int V_245 = 0 ;
int V_246 = 0 ;
struct V_247 {
int V_64 ;
int V_248 ;
} * V_249 ;
V_14 . V_107 = 0 ;
V_14 . V_180 = 0 ;
F_48 ( F_51 ) ;
if ( ! V_106 && V_14 . V_107 > 1 )
V_33 = 1 ;
if ( V_115 > 1 )
fprintf ( V_29 , L_202 , V_14 . V_107 , V_14 . V_180 ) ;
V_249 = calloc ( 1 , ( V_14 . V_180 + 1 ) * sizeof( struct V_247 ) ) ;
if ( V_249 == NULL )
F_40 ( 1 , L_203 ) ;
V_3 = F_81 ( ( V_14 . V_180 + 1 ) ) ;
if ( V_3 == NULL )
F_40 ( 3 , L_204 ) ;
V_2 = F_82 ( ( V_14 . V_180 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_48 ( F_52 ) ;
V_23 = F_81 ( ( V_14 . V_180 + 1 ) ) ;
if ( V_23 == NULL )
F_40 ( 3 , L_204 ) ;
V_22 = F_82 ( ( V_14 . V_180 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_222 = 0 ; V_222 <= V_14 . V_180 ; ++ V_222 ) {
int V_250 ;
if ( F_1 ( V_222 ) ) {
if ( V_115 > 1 )
fprintf ( V_29 , L_205 , V_222 ) ;
continue;
}
V_249 [ V_222 ] . V_64 = F_45 ( V_222 ) ;
if ( V_249 [ V_222 ] . V_64 > V_244 )
V_244 = V_249 [ V_222 ] . V_64 ;
V_249 [ V_222 ] . V_248 = F_44 ( V_222 ) ;
if ( V_249 [ V_222 ] . V_248 > V_245 )
V_245 = V_249 [ V_222 ] . V_248 ;
V_250 = F_46 ( V_222 ) ;
if ( V_250 > V_246 )
V_246 = V_250 ;
if ( V_115 > 1 )
fprintf ( V_29 , L_206 ,
V_222 , V_249 [ V_222 ] . V_248 , V_249 [ V_222 ] . V_64 ) ;
}
V_14 . V_16 = V_244 + 1 ;
if ( V_115 > 1 )
fprintf ( V_29 , L_207 ,
V_244 , V_14 . V_16 ) ;
if ( ! V_106 && V_14 . V_16 > 1 )
V_32 = 1 ;
V_14 . V_15 = V_245 + 1 ;
if ( V_115 > 1 )
fprintf ( V_29 , L_208 ,
V_245 , V_14 . V_15 ) ;
if ( ! V_106 && V_14 . V_15 > 1 )
V_30 = 1 ;
V_14 . V_17 = V_246 ;
if ( V_115 > 1 )
fprintf ( V_29 , L_209 , V_246 ) ;
free ( V_249 ) ;
}
void
F_83 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_222 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_222 = 0 ; V_222 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_222 ++ )
( * V_18 ) [ V_222 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_222 = 0 ; V_222 < V_14 . V_16 * V_14 . V_15 ; V_222 ++ )
( * V_19 ) [ V_222 ] . V_64 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_222 = 0 ; V_222 < V_14 . V_15 ; V_222 ++ )
( * V_20 ) [ V_222 ] . V_69 = V_222 ;
return;
error:
F_40 ( 1 , L_210 ) ;
}
void F_84 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_251 , int V_252 ,
int V_253 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_251 , V_252 , V_253 ) ;
V_19 = F_6 ( V_8 , V_252 , V_253 ) ;
V_20 = F_7 ( V_9 , V_253 ) ;
V_18 -> V_21 = V_21 ;
if ( V_251 == 0 ) {
V_18 -> V_54 |= V_88 ;
if ( F_43 ( V_21 ) )
V_18 -> V_54 |= V_90 ;
}
V_19 -> V_64 = V_252 ;
V_20 -> V_69 = V_253 ;
}
int F_85 ( int V_21 )
{
int V_254 , V_255 , V_256 ;
V_256 = F_44 ( V_21 ) ;
V_255 = F_45 ( V_21 ) ;
if ( F_42 ( V_21 ) ) {
V_254 = 0 ;
V_14 . V_119 ++ ;
} else {
V_254 = 1 ;
}
F_84 ( V_183 , V_254 , V_255 , V_256 , V_21 ) ;
F_84 ( V_187 , V_254 , V_255 , V_256 , V_21 ) ;
return 0 ;
}
void F_86 ()
{
V_104 = calloc ( 1 , ( 1 + V_14 . V_107 ) * 1024 ) ;
V_31 = V_104 ;
if ( V_31 == NULL )
F_40 ( - 1 , L_211 ) ;
}
void F_50 ( void )
{
F_80 () ;
F_83 ( & V_158 , & V_159 , & V_160 ) ;
F_83 ( & V_161 , & V_162 , & V_163 ) ;
F_86 () ;
F_48 ( F_85 ) ;
}
void F_87 ()
{
F_75 () ;
F_57 () ;
F_58 () ;
F_50 () ;
if ( V_115 )
F_34 () ;
if ( V_115 )
F_3 ( F_62 , V_187 ) ;
if ( V_115 )
F_3 ( F_68 , V_187 ) ;
F_3 ( F_74 , V_187 ) ;
if ( V_115 )
F_3 ( F_65 , V_187 ) ;
}
int F_88 ( char * * V_257 )
{
T_5 V_258 ;
int V_259 ;
V_259 = F_3 ( F_33 , V_183 ) ;
if ( V_259 )
exit ( V_259 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_54 ( & V_184 , (struct V_185 * ) NULL ) ;
V_258 = F_89 () ;
if ( ! V_258 ) {
F_90 ( V_257 [ 0 ] , V_257 ) ;
} else {
if ( V_258 == - 1 )
F_40 ( 1 , L_212 ) ;
signal ( V_260 , V_261 ) ;
signal ( V_262 , V_261 ) ;
if ( F_91 ( V_258 , & V_259 , 0 ) == - 1 )
F_40 ( V_259 , L_213 ) ;
}
F_3 ( F_33 , V_187 ) ;
F_54 ( & V_188 , (struct V_185 * ) NULL ) ;
F_56 ( & V_188 , & V_184 , & V_91 ) ;
F_47 ( F_27 , V_187 , V_183 ) ;
F_31 ( V_183 ) ;
F_21 ( V_183 ) ;
F_20 () ;
fprintf ( V_29 , L_214 , V_91 . V_92 + V_91 . V_93 / 1000000.0 ) ;
return V_259 ;
}
int F_92 ( void )
{
int V_259 ;
V_259 = F_3 ( F_33 , V_187 ) ;
if ( V_259 )
return V_259 ;
V_259 = F_3 ( F_17 , V_187 ) ;
if ( V_259 )
return V_259 ;
F_19 () ;
return V_259 ;
}
void F_93 ( int V_263 , char * * V_257 )
{
int V_264 ;
V_113 = V_257 [ 0 ] ;
while ( ( V_264 = F_94 ( V_263 , V_257 , L_215 ) ) != - 1 ) {
switch ( V_264 ) {
case 'p' :
V_87 ++ ;
break;
case 'P' :
V_89 ++ ;
break;
case 's' :
V_265 ++ ;
break;
case 'S' :
V_106 ++ ;
break;
case 'v' :
V_115 ++ ;
break;
case 'i' :
V_186 = atoi ( V_266 ) ;
break;
case 'c' :
sscanf ( V_266 , L_216 , & V_37 ) ;
break;
case 'C' :
sscanf ( V_266 , L_216 , & V_38 ) ;
break;
case 'm' :
sscanf ( V_266 , L_216 , & V_39 ) ;
break;
case 'M' :
sscanf ( V_266 , L_216 , & V_40 ) ;
break;
case 'R' :
V_267 ++ ;
break;
case 'T' :
V_228 = atoi ( V_266 ) ;
break;
case 'J' :
V_47 ++ ;
break;
default:
F_77 () ;
}
}
}
int main ( int V_263 , char * * V_257 )
{
F_93 ( V_263 , V_257 ) ;
if ( V_115 )
fprintf ( V_29 , L_217
L_218 ) ;
F_87 () ;
if ( V_265 )
return F_92 () ;
if ( V_263 - V_268 )
return F_88 ( V_257 + V_268 ) ;
else
F_53 () ;
return 0 ;
}
