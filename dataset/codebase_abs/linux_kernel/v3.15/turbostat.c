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
if ( V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_33 )
V_31 += sprintf ( V_31 , L_5 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_6 ) ;
if ( V_35 )
V_31 += sprintf ( V_31 , L_7 ) ;
if ( V_34 )
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
if ( V_35 )
V_31 += sprintf ( V_31 , L_15 ) ;
if ( V_35 && ! V_41 )
V_31 += sprintf ( V_31 , L_16 ) ;
if ( V_35 )
V_31 += sprintf ( V_31 , L_17 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_18 ) ;
if ( V_43 )
V_31 += sprintf ( V_31 , L_19 ) ;
if ( V_44 )
V_31 += sprintf ( V_31 , L_20 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_21 ) ;
if ( V_35 && ! V_41 )
V_31 += sprintf ( V_31 , L_22 ) ;
if ( V_35 && ! V_41 )
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
V_31 += sprintf ( V_31 , L_37 ) ;
if ( V_46 & V_52 )
V_31 += sprintf ( V_31 , L_32 ) ;
if ( V_46 & V_53 )
V_31 += sprintf ( V_31 , L_33 ) ;
V_31 += sprintf ( V_31 , L_38 ) ;
}
V_31 += sprintf ( V_31 , L_39 ) ;
}
int F_17 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_31 += sprintf ( V_31 , L_40 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
V_31 += sprintf ( V_31 , L_41 ,
V_18 -> V_21 , V_18 -> V_54 ) ;
V_31 += sprintf ( V_31 , L_42 , V_18 -> V_55 ) ;
V_31 += sprintf ( V_31 , L_43 , V_18 -> V_56 ) ;
V_31 += sprintf ( V_31 , L_44 , V_18 -> V_57 ) ;
V_31 += sprintf ( V_31 , L_45 , V_18 -> V_58 ) ;
V_31 += sprintf ( V_31 , L_46 ,
V_37 , V_18 -> V_59 ) ;
V_31 += sprintf ( V_31 , L_47 ,
V_38 , V_18 -> V_60 ) ;
V_31 += sprintf ( V_31 , L_46 ,
V_39 , V_18 -> V_61 ) ;
V_31 += sprintf ( V_31 , L_47 ,
V_40 , V_18 -> V_62 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_48 , V_18 -> V_63 ) ;
}
if ( V_19 ) {
V_31 += sprintf ( V_31 , L_49 , V_19 -> V_64 ) ;
V_31 += sprintf ( V_31 , L_50 , V_19 -> V_65 ) ;
V_31 += sprintf ( V_31 , L_51 , V_19 -> V_66 ) ;
V_31 += sprintf ( V_31 , L_52 , V_19 -> V_67 ) ;
V_31 += sprintf ( V_31 , L_53 , V_19 -> V_68 ) ;
}
if ( V_20 ) {
V_31 += sprintf ( V_31 , L_54 , V_20 -> V_69 ) ;
V_31 += sprintf ( V_31 , L_55 , V_20 -> V_70 ) ;
V_31 += sprintf ( V_31 , L_56 , V_20 -> V_71 ) ;
V_31 += sprintf ( V_31 , L_57 , V_20 -> V_72 ) ;
V_31 += sprintf ( V_31 , L_58 , V_20 -> V_73 ) ;
V_31 += sprintf ( V_31 , L_59 , V_20 -> V_74 ) ;
V_31 += sprintf ( V_31 , L_60 , V_20 -> V_75 ) ;
V_31 += sprintf ( V_31 , L_61 , V_20 -> V_76 ) ;
V_31 += sprintf ( V_31 , L_62 , V_20 -> V_77 ) ;
V_31 += sprintf ( V_31 , L_63 , V_20 -> V_78 ) ;
V_31 += sprintf ( V_31 , L_64 , V_20 -> V_79 ) ;
V_31 += sprintf ( V_31 , L_65 , V_20 -> V_80 ) ;
V_31 += sprintf ( V_31 , L_66 ,
V_20 -> V_81 ) ;
V_31 += sprintf ( V_31 , L_67 ,
V_20 -> V_82 ) ;
V_31 += sprintf ( V_31 , L_68 , V_20 -> V_83 ) ;
}
V_31 += sprintf ( V_31 , L_39 ) ;
return 0 ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_84 ;
char * V_85 ;
if ( V_86 && ! ( V_18 -> V_54 & V_87 ) )
return 0 ;
if ( V_88 && ! ( V_18 -> V_54 & V_89 ) )
return 0 ;
V_84 = V_90 . V_91 + V_90 . V_92 / 1000000.0 ;
if ( V_18 == & V_93 . V_94 ) {
if ( V_30 )
V_31 += sprintf ( V_31 , L_69 ) ;
if ( V_32 )
V_31 += sprintf ( V_31 , L_69 ) ;
if ( V_33 )
V_31 += sprintf ( V_31 , L_69 ) ;
} else {
if ( V_30 ) {
if ( V_20 )
V_31 += sprintf ( V_31 , L_70 , V_20 -> V_69 ) ;
else
V_31 += sprintf ( V_31 , L_69 ) ;
}
if ( V_32 ) {
if ( V_19 )
V_31 += sprintf ( V_31 , L_70 , V_19 -> V_64 ) ;
else
V_31 += sprintf ( V_31 , L_69 ) ;
}
if ( V_33 )
V_31 += sprintf ( V_31 , L_70 , V_18 -> V_21 ) ;
}
if ( V_34 )
V_31 += sprintf ( V_31 , L_71 ,
1.0 / V_95 * V_18 -> V_56 / V_84 ) ;
if ( V_35 ) {
if ( ! V_96 )
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_18 -> V_57 / V_18 -> V_55 ) ;
else
V_31 += sprintf ( V_31 , L_73 ) ;
}
if ( V_34 )
V_31 += sprintf ( V_31 , L_71 ,
1.0 * V_18 -> V_55 / V_95 * V_18 -> V_56 / V_18 -> V_57 / V_84 ) ;
V_31 += sprintf ( V_31 , L_71 , 1.0 * V_18 -> V_55 / V_95 / V_84 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_70 , V_18 -> V_63 ) ;
if ( V_37 )
V_31 += sprintf ( V_31 , L_74 , V_18 -> V_59 ) ;
if ( V_38 )
V_31 += sprintf ( V_31 , L_74 , V_18 -> V_60 ) ;
if ( V_39 )
V_31 += sprintf ( V_31 , L_75 , V_18 -> V_61 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_76 , V_18 -> V_62 ) ;
if ( V_35 ) {
if ( ! V_97 )
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_18 -> V_58 / V_18 -> V_55 ) ;
else
V_31 += sprintf ( V_31 , L_73 ) ;
}
if ( ! ( V_18 -> V_54 & V_87 ) )
goto V_98;
if ( V_35 && ! V_41 )
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_19 -> V_65 / V_18 -> V_55 ) ;
if ( V_35 )
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_19 -> V_66 / V_18 -> V_55 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_19 -> V_67 / V_18 -> V_55 ) ;
if ( V_43 )
V_31 += sprintf ( V_31 , L_70 , V_19 -> V_68 ) ;
if ( ! ( V_18 -> V_54 & V_89 ) )
goto V_98;
if ( V_44 )
V_31 += sprintf ( V_31 , L_70 , V_20 -> V_83 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_20 -> V_70 / V_18 -> V_55 ) ;
if ( V_35 && ! V_41 )
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_20 -> V_71 / V_18 -> V_55 ) ;
if ( V_35 && ! V_41 )
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_20 -> V_72 / V_18 -> V_55 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_20 -> V_73 / V_18 -> V_55 ) ;
if ( V_45 ) {
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_20 -> V_74 / V_18 -> V_55 ) ;
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_20 -> V_75 / V_18 -> V_55 ) ;
V_31 += sprintf ( V_31 , L_72 , 100.0 * V_20 -> V_76 / V_18 -> V_55 ) ;
}
if ( V_84 < V_99 )
V_85 = L_72 ;
else
V_85 = L_77 ;
if ( V_46 && ! V_47 ) {
if ( V_46 & V_48 )
V_31 += sprintf ( V_31 , V_85 , V_20 -> V_77 * V_100 / V_84 ) ;
if ( V_46 & V_49 )
V_31 += sprintf ( V_31 , V_85 , V_20 -> V_78 * V_100 / V_84 ) ;
if ( V_46 & V_50 )
V_31 += sprintf ( V_31 , V_85 , V_20 -> V_79 * V_100 / V_84 ) ;
if ( V_46 & V_51 )
V_31 += sprintf ( V_31 , V_85 , V_20 -> V_80 * V_100 / V_84 ) ;
if ( V_46 & V_52 )
V_31 += sprintf ( V_31 , V_85 , 100.0 * V_20 -> V_81 * V_101 / V_84 ) ;
if ( V_46 & V_53 )
V_31 += sprintf ( V_31 , V_85 , 100.0 * V_20 -> V_82 * V_101 / V_84 ) ;
} else {
if ( V_46 & V_48 )
V_31 += sprintf ( V_31 , V_85 ,
V_20 -> V_77 * V_100 ) ;
if ( V_46 & V_49 )
V_31 += sprintf ( V_31 , V_85 ,
V_20 -> V_78 * V_100 ) ;
if ( V_46 & V_50 )
V_31 += sprintf ( V_31 , V_85 ,
V_20 -> V_79 * V_100 ) ;
if ( V_46 & V_51 )
V_31 += sprintf ( V_31 , V_85 ,
V_20 -> V_80 * V_100 ) ;
if ( V_46 & V_52 )
V_31 += sprintf ( V_31 , V_85 , 100.0 * V_20 -> V_81 * V_101 / V_84 ) ;
if ( V_46 & V_53 )
V_31 += sprintf ( V_31 , V_85 , 100.0 * V_20 -> V_82 * V_101 / V_84 ) ;
V_31 += sprintf ( V_31 , V_85 , V_84 ) ;
}
V_98:
V_31 += sprintf ( V_31 , L_39 ) ;
return 0 ;
}
void F_19 ()
{
fputs ( V_102 , stdout ) ;
fflush ( stdout ) ;
V_31 = V_102 ;
}
void F_20 ()
{
fputs ( V_102 , V_29 ) ;
V_31 = V_102 ;
}
void F_21 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_103 ;
if ( ! V_103 || ! V_104 )
F_16 () ;
if ( V_14 . V_105 > 1 )
F_18 ( & V_93 . V_94 , & V_93 . V_106 ,
& V_93 . V_107 ) ;
V_103 = 1 ;
if ( V_104 )
return;
F_3 ( F_18 , V_18 , V_19 , V_20 ) ;
}
void
F_22 ( struct V_6 * V_108 , struct V_6 * V_109 )
{
V_109 -> V_70 = V_108 -> V_70 - V_109 -> V_70 ;
V_109 -> V_71 = V_108 -> V_71 - V_109 -> V_71 ;
V_109 -> V_72 = V_108 -> V_72 - V_109 -> V_72 ;
V_109 -> V_73 = V_108 -> V_73 - V_109 -> V_73 ;
V_109 -> V_74 = V_108 -> V_74 - V_109 -> V_74 ;
V_109 -> V_75 = V_108 -> V_75 - V_109 -> V_75 ;
V_109 -> V_76 = V_108 -> V_76 - V_109 -> V_76 ;
V_109 -> V_83 = V_108 -> V_83 ;
F_23 ( V_108 -> V_77 , V_109 -> V_77 ) ;
F_23 ( V_108 -> V_78 , V_109 -> V_78 ) ;
F_23 ( V_108 -> V_79 , V_109 -> V_79 ) ;
F_23 ( V_108 -> V_80 , V_109 -> V_80 ) ;
F_23 ( V_108 -> V_81 , V_109 -> V_81 ) ;
F_23 ( V_108 -> V_82 , V_109 -> V_82 ) ;
}
void
F_24 ( struct V_5 * V_108 , struct V_5 * V_109 )
{
V_109 -> V_65 = V_108 -> V_65 - V_109 -> V_65 ;
V_109 -> V_66 = V_108 -> V_66 - V_109 -> V_66 ;
V_109 -> V_67 = V_108 -> V_67 - V_109 -> V_67 ;
V_109 -> V_68 = V_108 -> V_68 ;
}
void
F_25 ( struct V_4 * V_108 , struct V_4 * V_109 ,
struct V_5 * V_110 )
{
V_109 -> V_55 = V_108 -> V_55 - V_109 -> V_55 ;
if ( V_109 -> V_55 < ( 1000 * 1000 ) )
F_26 ( - 3 , L_78
L_79
L_80 ) ;
V_109 -> V_58 = V_108 -> V_58 - V_109 -> V_58 ;
if ( ( V_108 -> V_56 > V_109 -> V_56 ) && ( V_108 -> V_57 > V_109 -> V_57 ) ) {
V_109 -> V_56 = V_108 -> V_56 - V_109 -> V_56 ;
V_109 -> V_57 = V_108 -> V_57 - V_109 -> V_57 ;
} else {
if ( ! V_111 ) {
fprintf ( V_29 , L_81 , V_112 ) ;
fprintf ( V_29 , L_82 ) ;
fprintf ( V_29 , L_83 ) ;
V_111 = 1 ;
}
V_96 = 1 ;
V_97 = 1 ;
}
if ( V_113 ) {
} else {
if ( ( V_109 -> V_57 + V_110 -> V_65 + V_110 -> V_66 + V_110 -> V_67 ) > V_109 -> V_55 )
V_109 -> V_58 = 0 ;
else {
V_109 -> V_58 = V_109 -> V_55 - V_109 -> V_57 - V_110 -> V_65
- V_110 -> V_66 - V_110 -> V_67 ;
}
}
if ( V_109 -> V_57 == 0 ) {
if ( V_114 > 1 ) fprintf ( V_29 , L_84 , V_109 -> V_21 ) ;
V_109 -> V_57 = 1 ;
}
V_109 -> V_59 = V_108 -> V_59 - V_109 -> V_59 ;
V_109 -> V_59 &= 0xFFFFFFFF ;
V_109 -> V_60 = V_108 -> V_60 - V_109 -> V_60 ;
V_109 -> V_61 = V_108 -> V_61 ;
V_109 -> V_62 = V_108 -> V_62 ;
if ( V_36 )
V_109 -> V_63 = V_108 -> V_63 - V_109 -> V_63 ;
}
int F_27 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_115 ,
struct V_5 * V_116 , struct V_6 * V_117 )
{
if ( V_18 -> V_54 & V_87 )
F_24 ( V_19 , V_116 ) ;
F_25 ( V_18 , V_115 , V_116 ) ;
if ( V_18 -> V_54 & V_89 )
F_22 ( V_20 , V_117 ) ;
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
V_18 -> V_54 = V_87 | V_89 ;
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
V_93 . V_94 . V_55 += V_18 -> V_55 ;
V_93 . V_94 . V_56 += V_18 -> V_56 ;
V_93 . V_94 . V_57 += V_18 -> V_57 ;
V_93 . V_94 . V_58 += V_18 -> V_58 ;
V_93 . V_94 . V_59 += V_18 -> V_59 ;
V_93 . V_94 . V_60 += V_18 -> V_60 ;
if ( ! ( V_18 -> V_54 & V_87 ) )
return 0 ;
V_93 . V_106 . V_65 += V_19 -> V_65 ;
V_93 . V_106 . V_66 += V_19 -> V_66 ;
V_93 . V_106 . V_67 += V_19 -> V_67 ;
V_93 . V_106 . V_68 = F_30 ( V_93 . V_106 . V_68 , V_19 -> V_68 ) ;
if ( ! ( V_18 -> V_54 & V_89 ) )
return 0 ;
V_93 . V_107 . V_70 += V_20 -> V_70 ;
V_93 . V_107 . V_71 += V_20 -> V_71 ;
V_93 . V_107 . V_72 += V_20 -> V_72 ;
V_93 . V_107 . V_73 += V_20 -> V_73 ;
V_93 . V_107 . V_74 += V_20 -> V_74 ;
V_93 . V_107 . V_75 += V_20 -> V_75 ;
V_93 . V_107 . V_76 += V_20 -> V_76 ;
V_93 . V_107 . V_77 += V_20 -> V_77 ;
V_93 . V_107 . V_80 += V_20 -> V_80 ;
V_93 . V_107 . V_78 += V_20 -> V_78 ;
V_93 . V_107 . V_79 += V_20 -> V_79 ;
V_93 . V_107 . V_83 = F_30 ( V_93 . V_107 . V_83 , V_20 -> V_83 ) ;
V_93 . V_107 . V_81 += V_20 -> V_81 ;
V_93 . V_107 . V_82 += V_20 -> V_82 ;
return 0 ;
}
void F_31 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_28 ( & V_93 . V_94 , & V_93 . V_106 , & V_93 . V_107 ) ;
F_3 ( F_29 , V_18 , V_19 , V_20 ) ;
V_93 . V_94 . V_55 /= V_14 . V_105 ;
V_93 . V_94 . V_56 /= V_14 . V_105 ;
V_93 . V_94 . V_57 /= V_14 . V_105 ;
V_93 . V_94 . V_58 /= V_14 . V_105 ;
V_93 . V_94 . V_59 /= V_14 . V_105 ;
V_93 . V_94 . V_59 &= 0xFFFFFFFF ;
V_93 . V_94 . V_60 /= V_14 . V_105 ;
V_93 . V_106 . V_65 /= V_14 . V_118 ;
V_93 . V_106 . V_66 /= V_14 . V_118 ;
V_93 . V_106 . V_67 /= V_14 . V_118 ;
V_93 . V_107 . V_70 /= V_14 . V_15 ;
V_93 . V_107 . V_71 /= V_14 . V_15 ;
V_93 . V_107 . V_72 /= V_14 . V_15 ;
V_93 . V_107 . V_73 /= V_14 . V_15 ;
V_93 . V_107 . V_74 /= V_14 . V_15 ;
V_93 . V_107 . V_75 /= V_14 . V_15 ;
V_93 . V_107 . V_76 /= V_14 . V_15 ;
}
static unsigned long long F_32 ( void )
{
unsigned int V_119 , V_120 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_119 | ( ( unsigned long long ) V_120 ) << 32 ;
}
int F_33 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
unsigned long long V_25 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_85 , V_1 ) ;
return - 1 ;
}
V_18 -> V_55 = F_32 () ;
if ( V_34 ) {
if ( F_12 ( V_1 , V_121 , & V_18 -> V_56 ) )
return - 3 ;
if ( F_12 ( V_1 , V_122 , & V_18 -> V_57 ) )
return - 4 ;
}
if ( V_36 ) {
if ( F_12 ( V_1 , V_123 , & V_25 ) )
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
if ( V_113 ) {
if ( F_12 ( V_1 , V_124 , & V_18 -> V_58 ) )
return - 6 ;
}
if ( ! ( V_18 -> V_54 & V_87 ) )
return 0 ;
if ( V_35 && ! V_41 ) {
if ( F_12 ( V_1 , V_125 , & V_19 -> V_65 ) )
return - 6 ;
}
if ( V_35 ) {
if ( F_12 ( V_1 , V_126 , & V_19 -> V_66 ) )
return - 7 ;
}
if ( V_42 )
if ( F_12 ( V_1 , V_127 , & V_19 -> V_67 ) )
return - 8 ;
if ( V_43 ) {
if ( F_12 ( V_1 , V_128 , & V_25 ) )
return - 9 ;
V_19 -> V_68 = V_129 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
if ( ! ( V_18 -> V_54 & V_89 ) )
return 0 ;
if ( V_35 && ! V_41 ) {
if ( F_12 ( V_1 , V_130 , & V_20 -> V_71 ) )
return - 9 ;
if ( F_12 ( V_1 , V_131 , & V_20 -> V_72 ) )
return - 10 ;
}
if ( V_42 ) {
if ( F_12 ( V_1 , V_132 , & V_20 -> V_70 ) )
return - 11 ;
if ( F_12 ( V_1 , V_133 , & V_20 -> V_73 ) )
return - 12 ;
}
if ( V_45 ) {
if ( F_12 ( V_1 , V_134 , & V_20 -> V_74 ) )
return - 13 ;
if ( F_12 ( V_1 , V_135 , & V_20 -> V_75 ) )
return - 13 ;
if ( F_12 ( V_1 , V_136 , & V_20 -> V_76 ) )
return - 13 ;
}
if ( V_46 & V_48 ) {
if ( F_12 ( V_1 , V_137 , & V_25 ) )
return - 13 ;
V_20 -> V_77 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_49 ) {
if ( F_12 ( V_1 , V_138 , & V_25 ) )
return - 14 ;
V_20 -> V_78 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_51 ) {
if ( F_12 ( V_1 , V_139 , & V_25 ) )
return - 15 ;
V_20 -> V_80 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_50 ) {
if ( F_12 ( V_1 , V_140 , & V_25 ) )
return - 16 ;
V_20 -> V_79 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_52 ) {
if ( F_12 ( V_1 , V_141 , & V_25 ) )
return - 16 ;
V_20 -> V_81 = V_25 & 0xFFFFFFFF ;
}
if ( V_46 & V_53 ) {
if ( F_12 ( V_1 , V_142 , & V_25 ) )
return - 16 ;
V_20 -> V_82 = V_25 & 0xFFFFFFFF ;
}
if ( V_44 ) {
if ( F_12 ( V_1 , V_143 , & V_25 ) )
return - 17 ;
V_20 -> V_83 = V_129 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
return 0 ;
}
void F_34 ( void )
{
unsigned long long V_25 ;
unsigned int V_144 ;
if ( ! V_145 )
return;
F_12 ( 0 , V_146 , & V_25 ) ;
fprintf ( V_29 , L_86 , V_25 ) ;
V_144 = ( V_25 >> 40 ) & 0xFF ;
fprintf ( V_29 , L_87 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 8 ) & 0xFF ;
fprintf ( V_29 , L_88 ,
V_144 , V_147 , V_144 * V_147 ) ;
F_12 ( 0 , V_148 , & V_25 ) ;
fprintf ( V_29 , L_89 ,
V_25 , V_25 & 0x2 ? L_90 : L_91 ) ;
if ( ! V_149 )
goto V_150;
F_12 ( 0 , V_151 , & V_25 ) ;
fprintf ( V_29 , L_92 , V_25 ) ;
V_144 = ( V_25 >> 56 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_93 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 48 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_94 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 40 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_95 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 32 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_96 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 24 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_97 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 16 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_98 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 8 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_99 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 0 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_100 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_150:
F_12 ( 0 , V_152 , & V_25 ) ;
#define F_35 (1UL << 27)
#define F_36 (1UL << 28)
fprintf ( V_29 , L_101 , V_25 ) ;
fprintf ( V_29 , L_102 ,
( V_25 & F_36 ) ? L_103 : L_104 ,
( V_25 & F_35 ) ? L_105 : L_104 ,
( V_25 & V_153 ) ? L_106 : L_104 ,
( V_25 & V_154 ) ? L_107 : L_104 ,
( V_25 & ( 1 << 15 ) ) ? L_104 : L_108 ,
( unsigned int ) V_25 & 7 ) ;
switch( V_25 & 0x7 ) {
case 0 :
fprintf ( V_29 , V_41 ? L_109 : L_110 ) ;
break;
case 1 :
fprintf ( V_29 , V_41 ? L_109 : V_42 ? L_111 : L_110 ) ;
break;
case 2 :
fprintf ( V_29 , V_41 ? L_112 : V_42 ? L_113 : L_114 ) ;
break;
case 3 :
fprintf ( V_29 , V_41 ? L_112 : L_115 ) ;
break;
case 4 :
fprintf ( V_29 , V_41 ? L_116 : L_117 ) ;
break;
case 5 :
fprintf ( V_29 , V_41 ? L_112 : V_42 ? L_118 : L_112 ) ;
break;
case 6 :
fprintf ( V_29 , V_41 ? L_115 : L_112 ) ;
break;
case 7 :
fprintf ( V_29 , V_41 ? L_117 : L_119 ) ;
break;
default:
fprintf ( V_29 , L_112 ) ;
}
fprintf ( V_29 , L_120 ) ;
if ( ! V_155 )
return;
F_12 ( 0 , V_156 , & V_25 ) ;
fprintf ( V_29 , L_121 , V_25 ) ;
V_144 = ( V_25 >> 56 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_122 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 48 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_123 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 40 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_124 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 32 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_125 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 24 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_126 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 16 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_127 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 8 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_128 ,
V_144 , V_147 , V_144 * V_147 ) ;
V_144 = ( V_25 >> 0 ) & 0xFF ;
if ( V_144 )
fprintf ( V_29 , L_129 ,
V_144 , V_147 , V_144 * V_147 ) ;
}
void F_37 ( void )
{
F_38 ( V_3 ) ;
V_3 = NULL ;
V_3 = 0 ;
F_38 ( V_23 ) ;
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
free ( V_102 ) ;
V_102 = NULL ;
V_31 = NULL ;
}
T_3 * F_39 ( const char * V_163 , const char * V_164 )
{
T_3 * V_165 = fopen ( V_163 , L_130 ) ;
if ( ! V_165 )
F_40 ( 1 , L_131 , V_163 ) ;
return V_165 ;
}
int F_41 ( const char * V_166 , ... )
{
T_4 args ;
char V_163 [ V_167 ] ;
T_3 * V_165 ;
int V_168 ;
va_start ( args , V_166 ) ;
vsnprintf ( V_163 , sizeof( V_163 ) , V_166 , args ) ;
va_end ( args ) ;
V_165 = F_39 ( V_163 , L_130 ) ;
if ( fscanf ( V_165 , L_132 , & V_168 ) != 1 )
F_40 ( 1 , L_133 , V_163 ) ;
fclose ( V_165 ) ;
return V_168 ;
}
int F_42 ( int V_1 )
{
return V_1 == F_41 ( L_134 , V_1 ) ;
}
int F_43 ( int V_1 )
{
return V_1 == F_41 ( L_135 , V_1 ) ;
}
int F_44 ( int V_1 )
{
return F_41 ( L_136 , V_1 ) ;
}
int F_45 ( int V_1 )
{
return F_41 ( L_137 , V_1 ) ;
}
int F_46 ( int V_1 )
{
char V_163 [ 80 ] ;
T_3 * V_165 ;
int V_169 , V_170 ;
int V_171 ;
char V_172 ;
sprintf ( V_163 , L_134 , V_1 ) ;
V_165 = F_39 ( V_163 , L_130 ) ;
V_171 = fscanf ( V_165 , L_138 , & V_169 , & V_172 , & V_170 ) ;
fclose ( V_165 ) ;
if ( V_171 == 3 )
return 2 ;
else
return 1 ;
}
int F_47 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_173 , struct V_5 * V_174 ,
struct V_6 * V_175 )
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
V_115 = F_5 ( V_173 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_116 = F_6 ( V_174 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_117 = F_7 ( V_175 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_115 , V_116 , V_117 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_48 ( int (F_4)( int ) )
{
T_3 * V_176 ;
int V_177 ;
int V_10 ;
V_176 = F_39 ( V_178 , L_130 ) ;
V_10 = fscanf ( V_176 , L_139 ) ;
if ( V_10 != 0 )
F_40 ( 1 , L_140 , V_178 ) ;
while ( 1 ) {
V_10 = fscanf ( V_176 , L_141 , & V_177 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_177 ) ;
if ( V_10 ) {
fclose ( V_176 ) ;
return ( V_10 ) ;
}
}
fclose ( V_176 ) ;
return 0 ;
}
void F_49 ( void )
{
F_37 () ;
F_50 () ;
printf ( L_142 , V_14 . V_105 ) ;
}
int F_51 ( int V_1 )
{
if ( V_14 . V_179 < V_1 )
V_14 . V_179 = V_1 ;
V_14 . V_105 += 1 ;
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
int V_180 = 0 ;
V_181:
V_180 ++ ;
V_10 = F_3 ( F_33 , V_182 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
if ( V_180 > 1 ) {
exit ( V_10 ) ;
}
F_49 () ;
goto V_181;
}
V_180 = 0 ;
F_54 ( & V_183 , (struct V_184 * ) NULL ) ;
while ( 1 ) {
if ( F_48 ( F_1 ) ) {
F_49 () ;
goto V_181;
}
F_55 ( V_185 ) ;
V_10 = F_3 ( F_33 , V_186 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_49 () ;
goto V_181;
}
F_54 ( & V_187 , (struct V_184 * ) NULL ) ;
F_56 ( & V_187 , & V_183 , & V_90 ) ;
F_47 ( F_27 , V_186 , V_182 ) ;
F_31 ( V_182 ) ;
F_21 ( V_182 ) ;
F_19 () ;
F_55 ( V_185 ) ;
V_10 = F_3 ( F_33 , V_182 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_49 () ;
goto V_181;
}
F_54 ( & V_183 , (struct V_184 * ) NULL ) ;
F_56 ( & V_183 , & V_187 , & V_90 ) ;
F_47 ( F_27 , V_182 , V_186 ) ;
F_31 ( V_186 ) ;
F_21 ( V_186 ) ;
F_19 () ;
}
}
void F_57 ()
{
struct V_188 V_189 ;
if ( V_188 ( L_143 , & V_189 ) )
F_40 ( - 5 , L_144
L_145 ) ;
}
void F_58 ()
{
if ( F_59 () != 0 )
F_26 ( - 6 , L_146 ) ;
}
int F_60 ( unsigned int V_190 , unsigned int V_191 )
{
if ( ! V_192 )
return 0 ;
if ( V_190 != 6 )
return 0 ;
switch ( V_191 ) {
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
case 0x3D :
case 0x4F :
case 0x56 :
return 1 ;
case 0x2E :
case 0x2F :
default:
return 0 ;
}
}
int F_61 ( unsigned int V_190 , unsigned int V_191 )
{
if ( ! V_192 )
return 0 ;
if ( V_190 != 6 )
return 0 ;
switch ( V_191 ) {
case 0x3E :
return 1 ;
default:
return 0 ;
}
}
int F_62 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
char * V_193 ;
int V_1 ;
if ( ! V_194 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_54 & V_87 ) || ! ( V_18 -> V_54 & V_89 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_85 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_195 , & V_25 ) )
return 0 ;
switch ( V_25 & 0x7 ) {
case V_196 :
V_193 = L_147 ;
break;
case V_197 :
V_193 = L_148 ;
break;
case V_198 :
V_193 = L_149 ;
break;
default:
V_193 = L_150 ;
break;
}
fprintf ( V_29 , L_151 , V_1 , V_25 , V_193 ) ;
return 0 ;
}
double F_63 ( V_191 )
{
unsigned long long V_25 ;
if ( V_46 & V_199 )
if ( ! F_12 ( 0 , V_200 , & V_25 ) )
return ( ( V_25 >> 0 ) & V_201 ) * V_202 ;
switch ( V_191 ) {
case 0x37 :
case 0x4D :
return 30.0 ;
default:
return 135.0 ;
}
}
void F_64 ( unsigned int V_190 , unsigned int V_191 )
{
unsigned long long V_25 ;
unsigned int V_203 ;
double V_204 ;
if ( ! V_192 )
return;
if ( V_190 != 6 )
return;
switch ( V_191 ) {
case 0x2A :
case 0x3A :
case 0x3C :
case 0x45 :
case 0x46 :
case 0x3D :
V_46 = V_48 | V_49 | V_205 | V_50 | V_199 ;
break;
case 0x3F :
case 0x4F :
case 0x56 :
V_46 = V_48 | V_51 | V_53 | V_52 | V_199 ;
break;
case 0x2D :
case 0x3E :
V_46 = V_48 | V_49 | V_205 | V_51 | V_52 | V_53 | V_199 ;
break;
case 0x37 :
case 0x4D :
V_46 = V_48 | V_49 ;
break;
default:
return;
}
if ( F_12 ( 0 , V_206 , & V_25 ) )
return;
V_202 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
if ( V_191 == 0x37 )
V_100 = 1.0 * ( 1 << ( V_25 >> 8 & 0x1F ) ) / 1000000 ;
else
V_100 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_203 = V_25 >> 16 & 0xF ;
if ( V_203 == 0 )
V_203 = 0xA ;
V_101 = 1.0 / ( 1 << ( V_203 ) ) ;
V_204 = F_63 ( V_191 ) ;
V_99 = 0xFFFFFFFF * V_100 / V_204 ;
if ( V_114 )
fprintf ( V_29 , L_152 , V_99 , V_204 ) ;
return;
}
int F_65 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_207 ;
int V_1 ;
if ( ! ( V_43 || V_44 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_54 & V_87 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_85 , V_1 ) ;
return - 1 ;
}
if ( V_44 && ( V_18 -> V_54 & V_89 ) ) {
if ( F_12 ( V_1 , V_143 , & V_25 ) )
return 0 ;
V_207 = ( V_25 >> 16 ) & 0x7F ;
fprintf ( V_29 , L_153 ,
V_1 , V_25 , V_129 - V_207 ) ;
#ifdef F_66
if ( F_12 ( V_1 , V_208 , & V_25 ) )
return 0 ;
V_207 = ( V_25 >> 16 ) & 0x7F ;
V_209 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_154 ,
V_1 , V_25 , V_129 - V_207 , V_129 - V_209 ) ;
#endif
}
if ( V_43 ) {
unsigned int V_210 ;
if ( F_12 ( V_1 , V_128 , & V_25 ) )
return 0 ;
V_207 = ( V_25 >> 16 ) & 0x7F ;
V_210 = ( V_25 >> 27 ) & 0xF ;
fprintf ( V_29 , L_155 ,
V_1 , V_25 , V_129 - V_207 , V_210 ) ;
#ifdef F_66
if ( F_12 ( V_1 , V_211 , & V_25 ) )
return 0 ;
V_207 = ( V_25 >> 16 ) & 0x7F ;
V_209 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_156 ,
V_1 , V_25 , V_129 - V_207 , V_129 - V_209 ) ;
#endif
}
return 0 ;
}
void F_67 ( int V_1 , unsigned long long V_25 , char * V_212 )
{
fprintf ( V_29 , L_157 ,
V_1 , V_212 ,
( ( V_25 >> 15 ) & 1 ) ? L_90 : L_91 ,
( ( V_25 >> 0 ) & 0x7FFF ) * V_202 ,
( 1.0 + ( ( ( V_25 >> 22 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 17 ) & 0x1F ) ) * V_101 ,
( ( ( V_25 >> 16 ) & 1 ) ? L_90 : L_91 ) ) ;
return;
}
int F_68 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
if ( ! V_46 )
return 0 ;
if ( ! ( V_18 -> V_54 & V_87 ) || ! ( V_18 -> V_54 & V_89 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_85 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_206 , & V_25 ) )
return - 1 ;
if ( V_114 ) {
fprintf ( V_29 , L_158
L_159 , V_1 , V_25 ,
V_202 , V_100 , V_101 ) ;
}
if ( V_46 & V_199 ) {
if ( F_12 ( V_1 , V_200 , & V_25 ) )
return - 5 ;
fprintf ( V_29 , L_160 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_201 ) * V_202 ,
( ( V_25 >> 16 ) & V_201 ) * V_202 ,
( ( V_25 >> 32 ) & V_201 ) * V_202 ,
( ( V_25 >> 48 ) & V_213 ) * V_101 ) ;
}
if ( V_46 & V_48 ) {
if ( F_12 ( V_1 , V_214 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_161 ,
V_1 , V_25 , ( V_25 >> 63 ) & 1 ? L_104 : L_108 ) ;
F_67 ( V_1 , V_25 , L_162 ) ;
fprintf ( V_29 , L_163 ,
V_1 ,
( ( V_25 >> 47 ) & 1 ) ? L_90 : L_91 ,
( ( V_25 >> 32 ) & 0x7FFF ) * V_202 ,
( 1.0 + ( ( ( V_25 >> 54 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 49 ) & 0x1F ) ) * V_101 ,
( ( V_25 >> 48 ) & 1 ) ? L_90 : L_91 ) ;
}
if ( V_46 & V_51 ) {
if ( F_12 ( V_1 , V_215 , & V_25 ) )
return - 6 ;
fprintf ( V_29 , L_164 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_201 ) * V_202 ,
( ( V_25 >> 16 ) & V_201 ) * V_202 ,
( ( V_25 >> 32 ) & V_201 ) * V_202 ,
( ( V_25 >> 48 ) & V_213 ) * V_101 ) ;
if ( F_12 ( V_1 , V_216 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_165 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_104 : L_108 ) ;
F_67 ( V_1 , V_25 , L_166 ) ;
}
if ( V_46 & V_205 ) {
if ( V_114 ) {
if ( F_12 ( V_1 , V_217 , & V_25 ) )
return - 7 ;
fprintf ( V_29 , L_167 , V_1 , V_25 & 0xF ) ;
}
}
if ( V_46 & V_49 ) {
if ( V_114 ) {
if ( F_12 ( V_1 , V_218 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_168 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_104 : L_108 ) ;
F_67 ( V_1 , V_25 , L_169 ) ;
}
}
if ( V_46 & V_50 ) {
if ( V_114 ) {
if ( F_12 ( V_1 , V_219 , & V_25 ) )
return - 8 ;
fprintf ( V_29 , L_170 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_220 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_171 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_104 : L_108 ) ;
F_67 ( V_1 , V_25 , L_172 ) ;
}
}
return 0 ;
}
int F_69 ( unsigned int V_190 , unsigned int V_191 )
{
if ( ! V_192 )
return 0 ;
switch ( V_191 ) {
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
case 0x3C :
case 0x3F :
case 0x45 :
case 0x46 :
case 0x3D :
case 0x4F :
case 0x56 :
return 1 ;
}
return 0 ;
}
int F_70 ( unsigned int V_190 , unsigned int V_191 )
{
if ( ! V_192 )
return 0 ;
switch ( V_191 ) {
case 0x45 :
case 0x3D :
return 1 ;
}
return 0 ;
}
int F_71 ( unsigned int V_190 , unsigned int V_191 )
{
if ( ! V_192 )
return 0 ;
switch ( V_191 ) {
case 0x37 :
case 0x4D :
return 1 ;
}
return 0 ;
}
double F_72 ( void )
{
unsigned long long V_25 = 3 ;
unsigned int V_221 ;
double V_222 ;
if ( F_12 ( 0 , V_223 , & V_25 ) )
fprintf ( V_29 , L_173 ) ;
V_221 = V_25 & 0xf ;
if ( V_221 >= V_224 ) {
fprintf ( V_29 , L_174 , V_221 ) ;
V_25 = 3 ;
}
V_222 = V_225 [ V_221 ] ;
fprintf ( V_29 , L_175 , V_222 ) ;
return V_222 ;
}
double F_73 ( unsigned int V_190 , unsigned int V_191 )
{
if ( F_69 ( V_190 , V_191 ) )
return 100.00 ;
else if ( F_71 ( V_190 , V_191 ) )
return F_72 () ;
else
return 133.33 ;
}
int F_74 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_226 ;
int V_1 ;
if ( ! ( V_43 || V_44 ) )
return 0 ;
if ( ! ( V_18 -> V_54 & V_87 ) || ! ( V_18 -> V_54 & V_89 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_85 , V_1 ) ;
return - 1 ;
}
if ( V_227 != 0 ) {
V_129 = V_227 ;
fprintf ( V_29 , L_176 ,
V_1 , V_129 ) ;
return 0 ;
}
if ( ! V_145 )
goto V_228;
if ( F_12 ( 0 , V_229 , & V_25 ) )
goto V_228;
V_226 = ( V_25 >> 16 ) & 0x7F ;
if ( V_114 )
fprintf ( V_29 , L_177 ,
V_1 , V_25 , V_226 ) ;
if ( V_226 < 85 || V_226 > 127 )
goto V_228;
V_129 = V_226 ;
return 0 ;
V_228:
V_129 = V_230 ;
fprintf ( V_29 , L_178 ,
V_1 , V_129 ) ;
return 0 ;
}
void F_75 ()
{
unsigned int V_231 , V_232 , V_233 , V_234 , V_235 ;
unsigned int V_236 , V_190 , V_191 , V_237 ;
V_231 = V_232 = V_233 = V_234 = 0 ;
F_76 ( 0 , & V_235 , & V_232 , & V_233 , & V_234 ) ;
if ( V_232 == 0x756e6547 && V_234 == 0x49656e69 && V_233 == 0x6c65746e )
V_192 = 1 ;
if ( V_114 )
fprintf ( V_29 , L_179 ,
( char * ) & V_232 , ( char * ) & V_234 , ( char * ) & V_233 ) ;
F_76 ( 1 , & V_236 , & V_232 , & V_233 , & V_234 ) ;
V_190 = ( V_236 >> 8 ) & 0xf ;
V_191 = ( V_236 >> 4 ) & 0xf ;
V_237 = V_236 & 0xf ;
if ( V_190 == 6 || V_190 == 0xf )
V_191 += ( ( V_236 >> 16 ) & 0xf ) << 4 ;
if ( V_114 )
fprintf ( V_29 , L_180 ,
V_235 , V_190 , V_191 , V_237 , V_190 , V_191 , V_237 ) ;
if ( ! ( V_234 & ( 1 << 5 ) ) )
F_26 ( 1 , L_181 ) ;
V_232 = V_233 = V_234 = 0 ;
F_76 ( 0x80000000 , & V_235 , & V_232 , & V_233 , & V_234 ) ;
if ( V_235 < 0x80000007 )
F_26 ( 1 , L_182 , V_235 ) ;
F_76 ( 0x80000007 , & V_231 , & V_232 , & V_233 , & V_234 ) ;
V_238 = V_234 & ( 1 << 8 ) ;
if ( ! V_238 )
F_26 ( 1 , L_183 ) ;
F_76 ( 0x6 , & V_231 , & V_232 , & V_233 , & V_234 ) ;
V_34 = V_233 & ( 1 << 0 ) ;
V_43 = V_231 & ( 1 << 0 ) ;
V_44 = V_231 & ( 1 << 6 ) ;
V_194 = V_233 & ( 1 << 3 ) ;
if ( V_114 )
fprintf ( V_29 , L_184 ,
V_34 ? L_185 : L_186 ,
V_43 ? L_187 : L_104 ,
V_44 ? L_188 : L_104 ,
V_194 ? L_189 : L_104 ) ;
if ( ! V_34 )
F_26 ( - 1 , L_190 ) ;
V_145 = V_192 && V_238 ;
V_35 = V_192 ;
V_36 = V_35 ;
V_42 = F_69 ( V_190 , V_191 ) ;
V_45 = F_70 ( V_190 , V_191 ) ;
V_41 = F_71 ( V_190 , V_191 ) ;
V_147 = F_73 ( V_190 , V_191 ) ;
V_155 = F_60 ( V_190 , V_191 ) ;
V_149 = F_61 ( V_190 , V_191 ) ;
F_64 ( V_190 , V_191 ) ;
return;
}
void F_77 ()
{
F_26 ( 1 , L_191 ,
V_112 ) ;
}
int F_78 ( const struct V_239 * V_240 )
{
if ( isdigit ( V_240 -> V_241 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_79 ( int V_242 )
{
return 0 ;
}
void F_80 ()
{
int V_221 ;
int V_243 = 0 ;
int V_244 = 0 ;
int V_245 = 0 ;
struct V_246 {
int V_64 ;
int V_247 ;
} * V_248 ;
V_14 . V_105 = 0 ;
V_14 . V_179 = 0 ;
F_48 ( F_51 ) ;
if ( ! V_104 && V_14 . V_105 > 1 )
V_33 = 1 ;
if ( V_114 > 1 )
fprintf ( V_29 , L_192 , V_14 . V_105 , V_14 . V_179 ) ;
V_248 = calloc ( 1 , ( V_14 . V_179 + 1 ) * sizeof( struct V_246 ) ) ;
if ( V_248 == NULL )
F_40 ( 1 , L_193 ) ;
V_3 = F_81 ( ( V_14 . V_179 + 1 ) ) ;
if ( V_3 == NULL )
F_40 ( 3 , L_194 ) ;
V_2 = F_82 ( ( V_14 . V_179 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_48 ( F_52 ) ;
V_23 = F_81 ( ( V_14 . V_179 + 1 ) ) ;
if ( V_23 == NULL )
F_40 ( 3 , L_194 ) ;
V_22 = F_82 ( ( V_14 . V_179 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_221 = 0 ; V_221 <= V_14 . V_179 ; ++ V_221 ) {
int V_249 ;
if ( F_1 ( V_221 ) ) {
if ( V_114 > 1 )
fprintf ( V_29 , L_195 , V_221 ) ;
continue;
}
V_248 [ V_221 ] . V_64 = F_45 ( V_221 ) ;
if ( V_248 [ V_221 ] . V_64 > V_243 )
V_243 = V_248 [ V_221 ] . V_64 ;
V_248 [ V_221 ] . V_247 = F_44 ( V_221 ) ;
if ( V_248 [ V_221 ] . V_247 > V_244 )
V_244 = V_248 [ V_221 ] . V_247 ;
V_249 = F_46 ( V_221 ) ;
if ( V_249 > V_245 )
V_245 = V_249 ;
if ( V_114 > 1 )
fprintf ( V_29 , L_196 ,
V_221 , V_248 [ V_221 ] . V_247 , V_248 [ V_221 ] . V_64 ) ;
}
V_14 . V_16 = V_243 + 1 ;
if ( V_114 > 1 )
fprintf ( V_29 , L_197 ,
V_243 , V_14 . V_16 ) ;
if ( ! V_104 && V_14 . V_16 > 1 )
V_32 = 1 ;
V_14 . V_15 = V_244 + 1 ;
if ( V_114 > 1 )
fprintf ( V_29 , L_198 ,
V_244 , V_14 . V_15 ) ;
if ( ! V_104 && V_14 . V_15 > 1 )
V_30 = 1 ;
V_14 . V_17 = V_245 ;
if ( V_114 > 1 )
fprintf ( V_29 , L_199 , V_245 ) ;
free ( V_248 ) ;
}
void
F_83 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_221 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_221 = 0 ; V_221 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_221 ++ )
( * V_18 ) [ V_221 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_221 = 0 ; V_221 < V_14 . V_16 * V_14 . V_15 ; V_221 ++ )
( * V_19 ) [ V_221 ] . V_64 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_221 = 0 ; V_221 < V_14 . V_15 ; V_221 ++ )
( * V_20 ) [ V_221 ] . V_69 = V_221 ;
return;
error:
F_40 ( 1 , L_200 ) ;
}
void F_84 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_250 , int V_251 ,
int V_252 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_250 , V_251 , V_252 ) ;
V_19 = F_6 ( V_8 , V_251 , V_252 ) ;
V_20 = F_7 ( V_9 , V_252 ) ;
V_18 -> V_21 = V_21 ;
if ( V_250 == 0 ) {
V_18 -> V_54 |= V_87 ;
if ( F_43 ( V_21 ) )
V_18 -> V_54 |= V_89 ;
}
V_19 -> V_64 = V_251 ;
V_20 -> V_69 = V_252 ;
}
int F_85 ( int V_21 )
{
int V_253 , V_254 , V_255 ;
V_255 = F_44 ( V_21 ) ;
V_254 = F_45 ( V_21 ) ;
if ( F_42 ( V_21 ) ) {
V_253 = 0 ;
V_14 . V_118 ++ ;
} else {
V_253 = 1 ;
}
F_84 ( V_182 , V_253 , V_254 , V_255 , V_21 ) ;
F_84 ( V_186 , V_253 , V_254 , V_255 , V_21 ) ;
return 0 ;
}
void F_86 ()
{
V_102 = calloc ( 1 , ( 1 + V_14 . V_105 ) * 1024 ) ;
V_31 = V_102 ;
if ( V_31 == NULL )
F_40 ( - 1 , L_201 ) ;
}
void F_50 ( void )
{
F_80 () ;
F_83 ( & V_157 , & V_158 , & V_159 ) ;
F_83 ( & V_160 , & V_161 , & V_162 ) ;
F_86 () ;
F_48 ( F_85 ) ;
}
void F_87 ()
{
F_75 () ;
F_57 () ;
F_58 () ;
F_50 () ;
if ( V_114 )
F_34 () ;
if ( V_114 )
F_3 ( F_62 , V_186 ) ;
if ( V_114 )
F_3 ( F_68 , V_186 ) ;
F_3 ( F_74 , V_186 ) ;
if ( V_114 )
F_3 ( F_65 , V_186 ) ;
}
int F_88 ( char * * V_256 )
{
T_5 V_257 ;
int V_258 ;
V_258 = F_3 ( F_33 , V_182 ) ;
if ( V_258 )
exit ( V_258 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_54 ( & V_183 , (struct V_184 * ) NULL ) ;
V_257 = F_89 () ;
if ( ! V_257 ) {
F_90 ( V_256 [ 0 ] , V_256 ) ;
} else {
if ( V_257 == - 1 )
F_40 ( 1 , L_202 ) ;
signal ( V_259 , V_260 ) ;
signal ( V_261 , V_260 ) ;
if ( F_91 ( V_257 , & V_258 , 0 ) == - 1 )
F_40 ( V_258 , L_203 ) ;
}
F_3 ( F_33 , V_186 ) ;
F_54 ( & V_187 , (struct V_184 * ) NULL ) ;
F_56 ( & V_187 , & V_183 , & V_90 ) ;
F_47 ( F_27 , V_186 , V_182 ) ;
F_31 ( V_182 ) ;
F_21 ( V_182 ) ;
F_20 () ;
fprintf ( V_29 , L_204 , V_90 . V_91 + V_90 . V_92 / 1000000.0 ) ;
return V_258 ;
}
int F_92 ( void )
{
int V_258 ;
V_258 = F_3 ( F_33 , V_186 ) ;
if ( V_258 )
return V_258 ;
V_258 = F_3 ( F_17 , V_186 ) ;
if ( V_258 )
return V_258 ;
F_19 () ;
return V_258 ;
}
void F_93 ( int V_262 , char * * V_256 )
{
int V_263 ;
V_112 = V_256 [ 0 ] ;
while ( ( V_263 = F_94 ( V_262 , V_256 , L_205 ) ) != - 1 ) {
switch ( V_263 ) {
case 'p' :
V_86 ++ ;
break;
case 'P' :
V_88 ++ ;
break;
case 's' :
V_264 ++ ;
break;
case 'S' :
V_104 ++ ;
break;
case 'v' :
V_114 ++ ;
break;
case 'i' :
V_185 = atoi ( V_265 ) ;
break;
case 'c' :
sscanf ( V_265 , L_206 , & V_37 ) ;
break;
case 'C' :
sscanf ( V_265 , L_206 , & V_38 ) ;
break;
case 'm' :
sscanf ( V_265 , L_206 , & V_39 ) ;
break;
case 'M' :
sscanf ( V_265 , L_206 , & V_40 ) ;
break;
case 'R' :
V_266 ++ ;
break;
case 'T' :
V_227 = atoi ( V_265 ) ;
break;
case 'J' :
V_47 ++ ;
break;
default:
F_77 () ;
}
}
}
int main ( int V_262 , char * * V_256 )
{
F_93 ( V_262 , V_256 ) ;
if ( V_114 )
fprintf ( V_29 , L_207
L_208 ) ;
F_87 () ;
if ( V_264 )
return F_92 () ;
if ( V_262 - V_267 )
return F_88 ( V_256 + V_267 ) ;
else
F_53 () ;
return 0 ;
}
