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
if ( V_34 )
V_31 += sprintf ( V_31 , L_16 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_17 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_18 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_19 ) ;
if ( V_43 )
V_31 += sprintf ( V_31 , L_20 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_21 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_22 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_23 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_24 ) ;
if ( V_44 ) {
V_31 += sprintf ( V_31 , L_25 ) ;
V_31 += sprintf ( V_31 , L_26 ) ;
V_31 += sprintf ( V_31 , L_27 ) ;
}
if ( V_45 & V_46 )
V_31 += sprintf ( V_31 , L_28 ) ;
if ( V_45 & V_47 )
V_31 += sprintf ( V_31 , L_29 ) ;
if ( V_45 & V_48 )
V_31 += sprintf ( V_31 , L_30 ) ;
if ( V_45 & V_49 )
V_31 += sprintf ( V_31 , L_31 ) ;
if ( V_45 & V_50 )
V_31 += sprintf ( V_31 , L_32 ) ;
if ( V_45 & V_51 )
V_31 += sprintf ( V_31 , L_33 ) ;
V_31 += sprintf ( V_31 , L_34 ) ;
}
int F_17 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
fprintf ( V_29 , L_35 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
fprintf ( V_29 , L_36 , V_18 -> V_21 , V_18 -> V_52 ) ;
fprintf ( V_29 , L_37 , V_18 -> V_53 ) ;
fprintf ( V_29 , L_38 , V_18 -> V_54 ) ;
fprintf ( V_29 , L_39 , V_18 -> V_55 ) ;
fprintf ( V_29 , L_40 , V_18 -> V_56 ) ;
fprintf ( V_29 , L_41 ,
V_37 , V_18 -> V_57 ) ;
fprintf ( V_29 , L_42 ,
V_38 , V_18 -> V_58 ) ;
fprintf ( V_29 , L_41 ,
V_39 , V_18 -> V_59 ) ;
fprintf ( V_29 , L_42 ,
V_40 , V_18 -> V_60 ) ;
if ( V_36 )
fprintf ( V_29 , L_43 , V_18 -> V_61 ) ;
}
if ( V_19 ) {
fprintf ( V_29 , L_44 , V_19 -> V_62 ) ;
fprintf ( V_29 , L_45 , V_19 -> V_63 ) ;
fprintf ( V_29 , L_46 , V_19 -> V_64 ) ;
fprintf ( V_29 , L_47 , V_19 -> V_65 ) ;
fprintf ( V_29 , L_48 , V_19 -> V_66 ) ;
}
if ( V_20 ) {
fprintf ( V_29 , L_49 , V_20 -> V_67 ) ;
fprintf ( V_29 , L_50 , V_20 -> V_68 ) ;
fprintf ( V_29 , L_51 , V_20 -> V_69 ) ;
fprintf ( V_29 , L_52 , V_20 -> V_70 ) ;
fprintf ( V_29 , L_53 , V_20 -> V_71 ) ;
fprintf ( V_29 , L_54 , V_20 -> V_72 ) ;
fprintf ( V_29 , L_55 , V_20 -> V_73 ) ;
fprintf ( V_29 , L_56 , V_20 -> V_74 ) ;
fprintf ( V_29 , L_57 , V_20 -> V_75 ) ;
fprintf ( V_29 , L_58 , V_20 -> V_76 ) ;
fprintf ( V_29 , L_59 , V_20 -> V_77 ) ;
fprintf ( V_29 , L_60 , V_20 -> V_78 ) ;
fprintf ( V_29 , L_61 , V_20 -> V_79 ) ;
fprintf ( V_29 , L_62 , V_20 -> V_80 ) ;
fprintf ( V_29 , L_63 , V_20 -> V_81 ) ;
}
return 0 ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_82 ;
char * V_83 , * V_84 ;
if ( V_85 && ! ( V_18 -> V_52 & V_86 ) )
return 0 ;
if ( V_87 && ! ( V_18 -> V_52 & V_88 ) )
return 0 ;
V_82 = V_89 . V_90 + V_89 . V_91 / 1000000.0 ;
if ( V_18 == & V_92 . V_93 ) {
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
V_31 += sprintf ( V_31 , L_66 , V_20 -> V_67 ) ;
else
V_31 += sprintf ( V_31 , L_64 ) ;
}
if ( V_30 && V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 ) {
if ( V_19 )
V_31 += sprintf ( V_31 , L_67 , V_19 -> V_62 ) ;
else
V_31 += sprintf ( V_31 , L_65 ) ;
}
if ( V_33 )
V_31 += sprintf ( V_31 , L_68 , V_18 -> V_21 ) ;
}
if ( V_34 ) {
if ( V_30 || V_32 || V_33 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( ! V_94 )
V_31 += sprintf ( V_31 , L_69 , 100.0 * V_18 -> V_55 / V_18 -> V_53 ) ;
else
V_31 += sprintf ( V_31 , L_70 ) ;
}
if ( V_35 ) {
if ( ! V_95 ) {
V_31 += sprintf ( V_31 , L_71 ,
1.0 * V_18 -> V_53 / V_96 * V_18 -> V_54 /
V_18 -> V_55 / V_82 ) ;
} else {
if ( V_18 -> V_54 > V_18 -> V_53 || V_18 -> V_55 > V_18 -> V_53 ) {
V_31 += sprintf ( V_31 , L_72 ) ;
} else {
V_31 += sprintf ( V_31 , L_73 ,
1.0 * V_18 -> V_53 /
V_96 * V_18 -> V_54 /
V_18 -> V_55 / V_82 ) ;
}
}
}
V_31 += sprintf ( V_31 , L_74 , 1.0 * V_18 -> V_53 / V_96 / V_82 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_75 , V_18 -> V_61 ) ;
if ( V_37 )
V_31 += sprintf ( V_31 , L_76 , V_18 -> V_57 ) ;
if ( V_38 )
V_31 += sprintf ( V_31 , L_76 , V_18 -> V_58 ) ;
if ( V_39 )
V_31 += sprintf ( V_31 , L_77 , V_18 -> V_59 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_78 , V_18 -> V_60 ) ;
if ( V_34 ) {
if ( ! V_97 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_18 -> V_56 / V_18 -> V_53 ) ;
else
V_31 += sprintf ( V_31 , L_70 ) ;
}
if ( ! ( V_18 -> V_52 & V_86 ) )
goto V_98;
if ( V_34 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_19 -> V_63 / V_18 -> V_53 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_19 -> V_64 / V_18 -> V_53 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_19 -> V_65 / V_18 -> V_53 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_80 , V_19 -> V_66 ) ;
if ( ! ( V_18 -> V_52 & V_88 ) )
goto V_98;
if ( V_43 )
V_31 += sprintf ( V_31 , L_80 , V_20 -> V_81 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_68 / V_18 -> V_53 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_69 / V_18 -> V_53 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_70 / V_18 -> V_53 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_71 / V_18 -> V_53 ) ;
if ( V_44 ) {
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_72 / V_18 -> V_53 ) ;
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_73 / V_18 -> V_53 ) ;
V_31 += sprintf ( V_31 , L_79 , 100.0 * V_20 -> V_74 / V_18 -> V_53 ) ;
}
if ( V_82 < V_99 ) {
V_83 = L_81 ;
V_84 = L_79 ;
} else {
V_83 = L_82 ;
V_84 = L_83 ;
}
if ( V_45 & V_46 )
V_31 += sprintf ( V_31 , V_84 , V_20 -> V_75 * V_100 / V_82 ) ;
if ( V_45 & V_47 )
V_31 += sprintf ( V_31 , V_84 , V_20 -> V_76 * V_100 / V_82 ) ;
if ( V_45 & V_48 )
V_31 += sprintf ( V_31 , V_83 , V_20 -> V_77 * V_100 / V_82 ) ;
if ( V_45 & V_49 )
V_31 += sprintf ( V_31 , V_83 , V_20 -> V_78 * V_100 / V_82 ) ;
if ( V_45 & V_50 )
V_31 += sprintf ( V_31 , V_83 , 100.0 * V_20 -> V_79 * V_101 / V_82 ) ;
if ( V_45 & V_51 )
V_31 += sprintf ( V_31 , V_83 , 100.0 * V_20 -> V_80 * V_101 / V_82 ) ;
V_98:
V_31 += sprintf ( V_31 , L_34 ) ;
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
F_18 ( & V_92 . V_93 , & V_92 . V_106 ,
& V_92 . V_107 ) ;
V_103 = 1 ;
if ( V_104 )
return;
F_3 ( F_18 , V_18 , V_19 , V_20 ) ;
}
void
F_22 ( struct V_6 * V_108 , struct V_6 * V_109 )
{
V_109 -> V_68 = V_108 -> V_68 - V_109 -> V_68 ;
V_109 -> V_69 = V_108 -> V_69 - V_109 -> V_69 ;
V_109 -> V_70 = V_108 -> V_70 - V_109 -> V_70 ;
V_109 -> V_71 = V_108 -> V_71 - V_109 -> V_71 ;
V_109 -> V_72 = V_108 -> V_72 - V_109 -> V_72 ;
V_109 -> V_73 = V_108 -> V_73 - V_109 -> V_73 ;
V_109 -> V_74 = V_108 -> V_74 - V_109 -> V_74 ;
V_109 -> V_81 = V_108 -> V_81 ;
F_23 ( V_108 -> V_75 , V_109 -> V_75 ) ;
F_23 ( V_108 -> V_76 , V_109 -> V_76 ) ;
F_23 ( V_108 -> V_77 , V_109 -> V_77 ) ;
F_23 ( V_108 -> V_78 , V_109 -> V_78 ) ;
F_23 ( V_108 -> V_79 , V_109 -> V_79 ) ;
F_23 ( V_108 -> V_80 , V_109 -> V_80 ) ;
}
void
F_24 ( struct V_5 * V_108 , struct V_5 * V_109 )
{
V_109 -> V_63 = V_108 -> V_63 - V_109 -> V_63 ;
V_109 -> V_64 = V_108 -> V_64 - V_109 -> V_64 ;
V_109 -> V_65 = V_108 -> V_65 - V_109 -> V_65 ;
V_109 -> V_66 = V_108 -> V_66 ;
}
void
F_25 ( struct V_4 * V_108 , struct V_4 * V_109 ,
struct V_5 * V_110 )
{
V_109 -> V_53 = V_108 -> V_53 - V_109 -> V_53 ;
if ( V_109 -> V_53 < ( 1000 * 1000 ) ) {
fprintf ( V_29 , L_84 ) ;
fprintf ( V_29 , L_85 ) ;
fprintf ( V_29 , L_86 ) ;
exit ( - 3 ) ;
}
V_109 -> V_56 = V_108 -> V_56 - V_109 -> V_56 ;
if ( ( V_108 -> V_54 > V_109 -> V_54 ) && ( V_108 -> V_55 > V_109 -> V_55 ) ) {
V_109 -> V_54 = V_108 -> V_54 - V_109 -> V_54 ;
V_109 -> V_55 = V_108 -> V_55 - V_109 -> V_55 ;
} else {
if ( ! V_95 ) {
fprintf ( V_29 , L_87 , V_111 ) ;
fprintf ( V_29 , L_88 ) ;
fprintf ( V_29 , L_89 ) ;
V_95 = 1 ;
}
V_94 = 1 ;
V_97 = 1 ;
}
if ( ( V_109 -> V_55 + V_110 -> V_63 + V_110 -> V_64 + V_110 -> V_65 ) > V_109 -> V_53 )
V_109 -> V_56 = 0 ;
else {
V_109 -> V_56 = V_109 -> V_53 - V_109 -> V_55 - V_110 -> V_63
- V_110 -> V_64 - V_110 -> V_65 ;
}
if ( V_109 -> V_55 == 0 ) {
if ( V_112 > 1 ) fprintf ( V_29 , L_90 , V_109 -> V_21 ) ;
V_109 -> V_55 = 1 ;
}
V_109 -> V_57 = V_108 -> V_57 - V_109 -> V_57 ;
V_109 -> V_57 &= 0xFFFFFFFF ;
V_109 -> V_58 = V_108 -> V_58 - V_109 -> V_58 ;
V_109 -> V_59 = V_108 -> V_59 ;
V_109 -> V_60 = V_108 -> V_60 ;
if ( V_36 )
V_109 -> V_61 = V_108 -> V_61 - V_109 -> V_61 ;
}
int F_26 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_113 ,
struct V_5 * V_114 , struct V_6 * V_115 )
{
if ( V_18 -> V_52 & V_86 )
F_24 ( V_19 , V_114 ) ;
F_25 ( V_18 , V_113 , V_114 ) ;
if ( V_18 -> V_52 & V_88 )
F_22 ( V_20 , V_115 ) ;
return 0 ;
}
void F_27 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
V_18 -> V_53 = 0 ;
V_18 -> V_54 = 0 ;
V_18 -> V_55 = 0 ;
V_18 -> V_56 = 0 ;
V_18 -> V_61 = 0 ;
V_18 -> V_57 = 0 ;
V_18 -> V_58 = 0 ;
V_18 -> V_52 = V_86 | V_88 ;
V_19 -> V_63 = 0 ;
V_19 -> V_64 = 0 ;
V_19 -> V_65 = 0 ;
V_19 -> V_66 = 0 ;
V_20 -> V_68 = 0 ;
V_20 -> V_69 = 0 ;
V_20 -> V_70 = 0 ;
V_20 -> V_71 = 0 ;
V_20 -> V_72 = 0 ;
V_20 -> V_73 = 0 ;
V_20 -> V_74 = 0 ;
V_20 -> V_75 = 0 ;
V_20 -> V_78 = 0 ;
V_20 -> V_76 = 0 ;
V_20 -> V_77 = 0 ;
V_20 -> V_79 = 0 ;
V_20 -> V_80 = 0 ;
V_20 -> V_81 = 0 ;
}
int F_28 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_92 . V_93 . V_53 += V_18 -> V_53 ;
V_92 . V_93 . V_54 += V_18 -> V_54 ;
V_92 . V_93 . V_55 += V_18 -> V_55 ;
V_92 . V_93 . V_56 += V_18 -> V_56 ;
V_92 . V_93 . V_57 += V_18 -> V_57 ;
V_92 . V_93 . V_58 += V_18 -> V_58 ;
if ( ! ( V_18 -> V_52 & V_86 ) )
return 0 ;
V_92 . V_106 . V_63 += V_19 -> V_63 ;
V_92 . V_106 . V_64 += V_19 -> V_64 ;
V_92 . V_106 . V_65 += V_19 -> V_65 ;
V_92 . V_106 . V_66 = F_29 ( V_92 . V_106 . V_66 , V_19 -> V_66 ) ;
if ( ! ( V_18 -> V_52 & V_88 ) )
return 0 ;
V_92 . V_107 . V_68 += V_20 -> V_68 ;
V_92 . V_107 . V_69 += V_20 -> V_69 ;
V_92 . V_107 . V_70 += V_20 -> V_70 ;
V_92 . V_107 . V_71 += V_20 -> V_71 ;
V_92 . V_107 . V_72 += V_20 -> V_72 ;
V_92 . V_107 . V_73 += V_20 -> V_73 ;
V_92 . V_107 . V_74 += V_20 -> V_74 ;
V_92 . V_107 . V_75 += V_20 -> V_75 ;
V_92 . V_107 . V_78 += V_20 -> V_78 ;
V_92 . V_107 . V_76 += V_20 -> V_76 ;
V_92 . V_107 . V_77 += V_20 -> V_77 ;
V_92 . V_107 . V_81 = F_29 ( V_92 . V_107 . V_81 , V_20 -> V_81 ) ;
V_92 . V_107 . V_79 += V_20 -> V_79 ;
V_92 . V_107 . V_80 += V_20 -> V_80 ;
return 0 ;
}
void F_30 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_27 ( & V_92 . V_93 , & V_92 . V_106 , & V_92 . V_107 ) ;
F_3 ( F_28 , V_18 , V_19 , V_20 ) ;
V_92 . V_93 . V_53 /= V_14 . V_105 ;
V_92 . V_93 . V_54 /= V_14 . V_105 ;
V_92 . V_93 . V_55 /= V_14 . V_105 ;
V_92 . V_93 . V_56 /= V_14 . V_105 ;
V_92 . V_93 . V_57 /= V_14 . V_105 ;
V_92 . V_93 . V_57 &= 0xFFFFFFFF ;
V_92 . V_93 . V_58 /= V_14 . V_105 ;
V_92 . V_106 . V_63 /= V_14 . V_116 ;
V_92 . V_106 . V_64 /= V_14 . V_116 ;
V_92 . V_106 . V_65 /= V_14 . V_116 ;
V_92 . V_107 . V_68 /= V_14 . V_15 ;
V_92 . V_107 . V_69 /= V_14 . V_15 ;
V_92 . V_107 . V_70 /= V_14 . V_15 ;
V_92 . V_107 . V_71 /= V_14 . V_15 ;
V_92 . V_107 . V_72 /= V_14 . V_15 ;
V_92 . V_107 . V_73 /= V_14 . V_15 ;
V_92 . V_107 . V_74 /= V_14 . V_15 ;
}
static unsigned long long F_31 ( void )
{
unsigned int V_117 , V_118 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_117 | ( ( unsigned long long ) V_118 ) << 32 ;
}
int F_32 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
unsigned long long V_25 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_91 , V_1 ) ;
return - 1 ;
}
V_18 -> V_53 = F_31 () ;
if ( V_35 ) {
if ( F_12 ( V_1 , V_119 , & V_18 -> V_54 ) )
return - 3 ;
if ( F_12 ( V_1 , V_120 , & V_18 -> V_55 ) )
return - 4 ;
}
if ( V_36 ) {
if ( F_12 ( V_1 , V_121 , & V_25 ) )
return - 5 ;
V_18 -> V_61 = V_25 & 0xFFFFFFFF ;
}
if ( V_37 ) {
if ( F_12 ( V_1 , V_37 , & V_25 ) )
return - 5 ;
V_18 -> V_57 = V_25 & 0xFFFFFFFF ;
}
if ( V_38 )
if ( F_12 ( V_1 , V_38 , & V_18 -> V_58 ) )
return - 5 ;
if ( V_39 ) {
if ( F_12 ( V_1 , V_39 , & V_25 ) )
return - 5 ;
V_18 -> V_59 = V_25 & 0xFFFFFFFF ;
}
if ( V_40 )
if ( F_12 ( V_1 , V_40 , & V_18 -> V_60 ) )
return - 5 ;
if ( ! ( V_18 -> V_52 & V_86 ) )
return 0 ;
if ( V_34 ) {
if ( F_12 ( V_1 , V_122 , & V_19 -> V_63 ) )
return - 6 ;
if ( F_12 ( V_1 , V_123 , & V_19 -> V_64 ) )
return - 7 ;
}
if ( V_41 )
if ( F_12 ( V_1 , V_124 , & V_19 -> V_65 ) )
return - 8 ;
if ( V_42 ) {
if ( F_12 ( V_1 , V_125 , & V_25 ) )
return - 9 ;
V_19 -> V_66 = V_126 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
if ( ! ( V_18 -> V_52 & V_88 ) )
return 0 ;
if ( V_34 ) {
if ( F_12 ( V_1 , V_127 , & V_20 -> V_69 ) )
return - 9 ;
if ( F_12 ( V_1 , V_128 , & V_20 -> V_70 ) )
return - 10 ;
}
if ( V_41 ) {
if ( F_12 ( V_1 , V_129 , & V_20 -> V_68 ) )
return - 11 ;
if ( F_12 ( V_1 , V_130 , & V_20 -> V_71 ) )
return - 12 ;
}
if ( V_44 ) {
if ( F_12 ( V_1 , V_131 , & V_20 -> V_72 ) )
return - 13 ;
if ( F_12 ( V_1 , V_132 , & V_20 -> V_73 ) )
return - 13 ;
if ( F_12 ( V_1 , V_133 , & V_20 -> V_74 ) )
return - 13 ;
}
if ( V_45 & V_46 ) {
if ( F_12 ( V_1 , V_134 , & V_25 ) )
return - 13 ;
V_20 -> V_75 = V_25 & 0xFFFFFFFF ;
}
if ( V_45 & V_47 ) {
if ( F_12 ( V_1 , V_135 , & V_25 ) )
return - 14 ;
V_20 -> V_76 = V_25 & 0xFFFFFFFF ;
}
if ( V_45 & V_49 ) {
if ( F_12 ( V_1 , V_136 , & V_25 ) )
return - 15 ;
V_20 -> V_78 = V_25 & 0xFFFFFFFF ;
}
if ( V_45 & V_48 ) {
if ( F_12 ( V_1 , V_137 , & V_25 ) )
return - 16 ;
V_20 -> V_77 = V_25 & 0xFFFFFFFF ;
}
if ( V_45 & V_50 ) {
if ( F_12 ( V_1 , V_138 , & V_25 ) )
return - 16 ;
V_20 -> V_79 = V_25 & 0xFFFFFFFF ;
}
if ( V_45 & V_51 ) {
if ( F_12 ( V_1 , V_139 , & V_25 ) )
return - 16 ;
V_20 -> V_80 = V_25 & 0xFFFFFFFF ;
}
if ( V_43 ) {
if ( F_12 ( V_1 , V_140 , & V_25 ) )
return - 17 ;
V_20 -> V_81 = V_126 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
return 0 ;
}
void F_33 ( void )
{
unsigned long long V_25 ;
unsigned int V_141 ;
if ( ! V_142 )
return;
F_12 ( 0 , V_143 , & V_25 ) ;
fprintf ( V_29 , L_92 , V_25 ) ;
V_141 = ( V_25 >> 40 ) & 0xFF ;
fprintf ( V_29 , L_93 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 8 ) & 0xFF ;
fprintf ( V_29 , L_94 ,
V_141 , V_144 , V_141 * V_144 ) ;
F_12 ( 0 , V_145 , & V_25 ) ;
fprintf ( V_29 , L_95 ,
V_25 , V_25 & 0x2 ? L_96 : L_97 ) ;
if ( ! V_146 )
goto V_147;
F_12 ( 0 , V_148 , & V_25 ) ;
fprintf ( V_29 , L_98 , V_25 ) ;
V_141 = ( V_25 >> 56 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_99 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 48 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_100 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 40 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_101 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 32 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_102 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 24 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_103 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 16 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_104 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 8 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_105 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 0 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_106 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_147:
F_12 ( 0 , V_149 , & V_25 ) ;
#define F_34 (1UL << 27)
#define F_35 (1UL << 28)
fprintf ( V_29 , L_107 , V_25 ) ;
fprintf ( V_29 , L_108 ,
( V_25 & F_35 ) ? L_109 : L_110 ,
( V_25 & F_34 ) ? L_111 : L_110 ,
( V_25 & V_150 ) ? L_112 : L_110 ,
( V_25 & V_151 ) ? L_113 : L_110 ,
( V_25 & ( 1 << 15 ) ) ? L_110 : L_114 ,
( unsigned int ) V_25 & 7 ) ;
switch( V_25 & 0x7 ) {
case 0 :
fprintf ( V_29 , L_115 ) ;
break;
case 1 :
fprintf ( V_29 , V_41 ? L_116 : L_115 ) ;
break;
case 2 :
fprintf ( V_29 , V_41 ? L_117 : L_118 ) ;
break;
case 3 :
fprintf ( V_29 , L_119 ) ;
break;
case 4 :
fprintf ( V_29 , L_120 ) ;
break;
case 5 :
fprintf ( V_29 , V_41 ? L_121 : L_122 ) ;
break;
case 7 :
fprintf ( V_29 , L_123 ) ;
break;
default:
fprintf ( V_29 , L_122 ) ;
}
fprintf ( V_29 , L_124 ) ;
if ( ! V_152 )
return;
F_12 ( 0 , V_153 , & V_25 ) ;
fprintf ( V_29 , L_125 , V_25 ) ;
V_141 = ( V_25 >> 56 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_126 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 48 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_127 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 40 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_128 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 32 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_129 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 24 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_130 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 16 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_131 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 8 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_132 ,
V_141 , V_144 , V_141 * V_144 ) ;
V_141 = ( V_25 >> 0 ) & 0xFF ;
if ( V_141 )
fprintf ( V_29 , L_133 ,
V_141 , V_144 , V_141 * V_144 ) ;
}
void F_36 ( void )
{
F_37 ( V_3 ) ;
V_3 = NULL ;
V_3 = 0 ;
F_37 ( V_23 ) ;
V_23 = NULL ;
V_22 = 0 ;
free ( V_154 ) ;
free ( V_155 ) ;
free ( V_156 ) ;
V_154 = NULL ;
V_155 = NULL ;
V_156 = NULL ;
free ( V_157 ) ;
free ( V_158 ) ;
free ( V_159 ) ;
V_157 = NULL ;
V_158 = NULL ;
V_159 = NULL ;
free ( V_102 ) ;
V_102 = NULL ;
V_31 = NULL ;
}
int F_38 ( int V_1 )
{
char V_160 [ 64 ] ;
T_3 * V_161 ;
int V_162 ;
sprintf ( V_160 , L_134 , V_1 ) ;
V_161 = fopen ( V_160 , L_135 ) ;
if ( V_161 == NULL ) {
perror ( V_160 ) ;
exit ( 1 ) ;
}
fscanf ( V_161 , L_136 , & V_162 ) ;
fclose ( V_161 ) ;
return ( V_1 == V_162 ) ;
}
int F_39 ( int V_1 )
{
char V_160 [ 64 ] ;
T_3 * V_161 ;
int V_162 ;
sprintf ( V_160 , L_137 , V_1 ) ;
V_161 = fopen ( V_160 , L_135 ) ;
if ( V_161 == NULL ) {
perror ( V_160 ) ;
exit ( 1 ) ;
}
fscanf ( V_161 , L_136 , & V_162 ) ;
fclose ( V_161 ) ;
return ( V_1 == V_162 ) ;
}
int F_40 ( int V_1 )
{
char V_160 [ 80 ] ;
T_3 * V_161 ;
int V_163 ;
sprintf ( V_160 , L_138 , V_1 ) ;
V_161 = fopen ( V_160 , L_135 ) ;
if ( V_161 == NULL ) {
perror ( V_160 ) ;
exit ( 1 ) ;
}
fscanf ( V_161 , L_136 , & V_163 ) ;
fclose ( V_161 ) ;
return V_163 ;
}
int F_41 ( int V_1 )
{
char V_160 [ 80 ] ;
T_3 * V_161 ;
int V_164 ;
sprintf ( V_160 , L_139 , V_1 ) ;
V_161 = fopen ( V_160 , L_135 ) ;
if ( V_161 == NULL ) {
perror ( V_160 ) ;
exit ( 1 ) ;
}
fscanf ( V_161 , L_136 , & V_164 ) ;
fclose ( V_161 ) ;
return V_164 ;
}
int F_42 ( int V_1 )
{
char V_160 [ 80 ] ;
T_3 * V_161 ;
int V_165 , V_166 ;
int V_167 ;
char V_168 ;
sprintf ( V_160 , L_134 , V_1 ) ;
V_161 = fopen ( V_160 , L_135 ) ;
if ( V_161 == NULL ) {
perror ( V_160 ) ;
exit ( 1 ) ;
}
V_167 = fscanf ( V_161 , L_140 , & V_165 , & V_168 , & V_166 ) ;
fclose ( V_161 ) ;
if ( V_167 == 3 )
return 2 ;
else
return 1 ;
}
int F_43 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_169 , struct V_5 * V_170 ,
struct V_6 * V_171 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_113 ;
struct V_5 * V_19 , * V_114 ;
struct V_6 * V_20 , * V_115 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_113 = F_5 ( V_169 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_114 = F_6 ( V_170 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_115 = F_7 ( V_171 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_113 , V_114 , V_115 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_44 ( int (F_4)( int ) )
{
T_3 * V_172 ;
int V_173 ;
int V_10 ;
V_172 = fopen ( V_174 , L_135 ) ;
if ( V_172 == NULL ) {
perror ( V_174 ) ;
exit ( 1 ) ;
}
V_10 = fscanf ( V_172 , L_141 ) ;
if ( V_10 != 0 ) {
perror ( L_142 ) ;
exit ( 1 ) ;
}
while ( 1 ) {
V_10 = fscanf ( V_172 , L_143 , & V_173 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_173 ) ;
if ( V_10 ) {
fclose ( V_172 ) ;
return ( V_10 ) ;
}
}
fclose ( V_172 ) ;
return 0 ;
}
void F_45 ( void )
{
F_36 () ;
F_46 () ;
printf ( L_144 , V_14 . V_105 ) ;
}
int F_47 ( int V_1 )
{
if ( V_14 . V_175 < V_1 )
V_14 . V_175 = V_1 ;
V_14 . V_105 += 1 ;
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
int V_176 = 0 ;
V_177:
V_176 ++ ;
V_10 = F_3 ( F_32 , V_178 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
if ( V_176 > 1 ) {
exit ( V_10 ) ;
}
F_45 () ;
goto V_177;
}
V_176 = 0 ;
F_50 ( & V_179 , (struct V_180 * ) NULL ) ;
while ( 1 ) {
if ( F_44 ( F_1 ) ) {
F_45 () ;
goto V_177;
}
F_51 ( V_181 ) ;
V_10 = F_3 ( F_32 , V_182 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_45 () ;
goto V_177;
}
F_50 ( & V_183 , (struct V_180 * ) NULL ) ;
F_52 ( & V_183 , & V_179 , & V_89 ) ;
F_43 ( F_26 , V_182 , V_178 ) ;
F_30 ( V_178 ) ;
F_21 ( V_178 ) ;
F_19 () ;
F_51 ( V_181 ) ;
V_10 = F_3 ( F_32 , V_178 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_45 () ;
goto V_177;
}
F_50 ( & V_179 , (struct V_180 * ) NULL ) ;
F_52 ( & V_179 , & V_183 , & V_89 ) ;
F_43 ( F_26 , V_178 , V_182 ) ;
F_30 ( V_182 ) ;
F_21 ( V_182 ) ;
F_19 () ;
}
}
void F_53 ()
{
struct V_184 V_185 ;
if ( V_184 ( L_145 , & V_185 ) ) {
fprintf ( V_29 , L_146 ) ;
fprintf ( V_29 , L_147 ) ;
exit ( - 5 ) ;
}
}
void F_54 ()
{
if ( F_55 () != 0 ) {
fprintf ( V_29 , L_148 ) ;
exit ( - 6 ) ;
}
}
int F_56 ( unsigned int V_186 , unsigned int V_187 )
{
if ( ! V_188 )
return 0 ;
if ( V_186 != 6 )
return 0 ;
switch ( V_187 ) {
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
return 1 ;
case 0x2E :
case 0x2F :
default:
return 0 ;
}
}
int F_57 ( unsigned int V_186 , unsigned int V_187 )
{
if ( ! V_188 )
return 0 ;
if ( V_186 != 6 )
return 0 ;
switch ( V_187 ) {
case 0x3E :
return 1 ;
default:
return 0 ;
}
}
int F_58 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
char * V_189 ;
int V_1 ;
if ( ! V_190 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_52 & V_86 ) || ! ( V_18 -> V_52 & V_88 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_91 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_191 , & V_25 ) )
return 0 ;
switch ( V_25 & 0x7 ) {
case V_192 :
V_189 = L_149 ;
break;
case V_193 :
V_189 = L_150 ;
break;
case V_194 :
V_189 = L_151 ;
break;
default:
V_189 = L_152 ;
break;
}
fprintf ( V_29 , L_153 , V_1 , V_25 , V_189 ) ;
return 0 ;
}
void F_59 ( unsigned int V_186 , unsigned int V_187 )
{
unsigned long long V_25 ;
double V_195 ;
if ( ! V_188 )
return;
if ( V_186 != 6 )
return;
switch ( V_187 ) {
case 0x2A :
case 0x3A :
case 0x3C :
case 0x3F :
case 0x45 :
case 0x46 :
V_45 = V_46 | V_47 | V_48 ;
break;
case 0x2D :
case 0x3E :
V_45 = V_46 | V_47 | V_49 | V_50 | V_51 ;
break;
default:
return;
}
if ( F_12 ( 0 , V_196 , & V_25 ) )
return;
V_197 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
V_100 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_101 = 1.0 / ( 1 << ( V_25 >> 16 & 0xF ) ) ;
if ( F_12 ( 0 , V_198 , & V_25 ) )
return;
V_195 = ( ( V_25 >> 0 ) & V_199 ) * V_197 ;
V_99 = 0xFFFFFFFF * V_100 / V_195 ;
if ( V_112 )
fprintf ( V_29 , L_154 , V_99 ) ;
return;
}
int F_60 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_200 ;
int V_1 ;
if ( ! ( V_42 || V_43 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_52 & V_86 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_91 , V_1 ) ;
return - 1 ;
}
if ( V_43 && ( V_18 -> V_52 & V_88 ) ) {
if ( F_12 ( V_1 , V_140 , & V_25 ) )
return 0 ;
V_200 = ( V_25 >> 16 ) & 0x7F ;
fprintf ( V_29 , L_155 ,
V_1 , V_25 , V_126 - V_200 ) ;
#ifdef F_61
if ( F_12 ( V_1 , V_201 , & V_25 ) )
return 0 ;
V_200 = ( V_25 >> 16 ) & 0x7F ;
V_202 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_156 ,
V_1 , V_25 , V_126 - V_200 , V_126 - V_202 ) ;
#endif
}
if ( V_42 ) {
unsigned int V_203 ;
if ( F_12 ( V_1 , V_125 , & V_25 ) )
return 0 ;
V_200 = ( V_25 >> 16 ) & 0x7F ;
V_203 = ( V_25 >> 27 ) & 0xF ;
fprintf ( V_29 , L_157 ,
V_1 , V_25 , V_126 - V_200 , V_203 ) ;
#ifdef F_61
if ( F_12 ( V_1 , V_204 , & V_25 ) )
return 0 ;
V_200 = ( V_25 >> 16 ) & 0x7F ;
V_202 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_158 ,
V_1 , V_25 , V_126 - V_200 , V_126 - V_202 ) ;
#endif
}
return 0 ;
}
void F_62 ( int V_1 , unsigned long long V_25 , char * V_205 )
{
fprintf ( V_29 , L_159 ,
V_1 , V_205 ,
( ( V_25 >> 15 ) & 1 ) ? L_96 : L_97 ,
( ( V_25 >> 0 ) & 0x7FFF ) * V_197 ,
( 1.0 + ( ( ( V_25 >> 22 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 17 ) & 0x1F ) ) * V_101 ,
( ( ( V_25 >> 16 ) & 1 ) ? L_96 : L_97 ) ) ;
return;
}
int F_63 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
double V_206 , V_207 , V_208 ;
if ( ! V_45 )
return 0 ;
if ( ! ( V_18 -> V_52 & V_86 ) || ! ( V_18 -> V_52 & V_88 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_91 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_196 , & V_25 ) )
return - 1 ;
V_206 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
V_207 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_208 = 1.0 / ( 1 << ( V_25 >> 16 & 0xF ) ) ;
if ( V_206 != V_197 )
fprintf ( V_29 , L_160 , V_1 ) ;
if ( V_207 != V_100 )
fprintf ( V_29 , L_161 , V_1 ) ;
if ( V_208 != V_101 )
fprintf ( V_29 , L_162 , V_1 ) ;
if ( V_112 ) {
fprintf ( V_29 , L_163
L_164 , V_1 , V_25 ,
V_206 , V_207 , V_208 ) ;
}
if ( V_45 & V_46 ) {
if ( F_12 ( V_1 , V_198 , & V_25 ) )
return - 5 ;
fprintf ( V_29 , L_165 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_199 ) * V_197 ,
( ( V_25 >> 16 ) & V_199 ) * V_197 ,
( ( V_25 >> 32 ) & V_199 ) * V_197 ,
( ( V_25 >> 48 ) & V_209 ) * V_101 ) ;
if ( F_12 ( V_1 , V_210 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_166 ,
V_1 , V_25 , ( V_25 >> 63 ) & 1 ? L_110 : L_114 ) ;
F_62 ( V_1 , V_25 , L_167 ) ;
fprintf ( V_29 , L_168 ,
V_1 ,
( ( V_25 >> 47 ) & 1 ) ? L_96 : L_97 ,
( ( V_25 >> 32 ) & 0x7FFF ) * V_197 ,
( 1.0 + ( ( ( V_25 >> 54 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 49 ) & 0x1F ) ) * V_101 ,
( ( V_25 >> 48 ) & 1 ) ? L_96 : L_97 ) ;
}
if ( V_45 & V_49 ) {
if ( F_12 ( V_1 , V_211 , & V_25 ) )
return - 6 ;
fprintf ( V_29 , L_169 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_199 ) * V_197 ,
( ( V_25 >> 16 ) & V_199 ) * V_197 ,
( ( V_25 >> 32 ) & V_199 ) * V_197 ,
( ( V_25 >> 48 ) & V_209 ) * V_101 ) ;
if ( F_12 ( V_1 , V_212 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_170 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_110 : L_114 ) ;
F_62 ( V_1 , V_25 , L_171 ) ;
}
if ( V_45 & V_47 ) {
if ( V_112 ) {
if ( F_12 ( V_1 , V_213 , & V_25 ) )
return - 7 ;
fprintf ( V_29 , L_172 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_214 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_173 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_110 : L_114 ) ;
F_62 ( V_1 , V_25 , L_174 ) ;
}
}
if ( V_45 & V_48 ) {
if ( V_112 ) {
if ( F_12 ( V_1 , V_215 , & V_25 ) )
return - 8 ;
fprintf ( V_29 , L_175 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_216 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_176 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_110 : L_114 ) ;
F_62 ( V_1 , V_25 , L_177 ) ;
}
}
return 0 ;
}
int F_64 ( unsigned int V_186 , unsigned int V_187 )
{
if ( ! V_188 )
return 0 ;
switch ( V_187 ) {
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
int F_65 ( unsigned int V_186 , unsigned int V_187 )
{
if ( ! V_188 )
return 0 ;
switch ( V_187 ) {
case 0x45 :
return 1 ;
}
return 0 ;
}
double F_66 ( unsigned int V_186 , unsigned int V_187 )
{
if ( F_64 ( V_186 , V_187 ) )
return 100.00 ;
else
return 133.33 ;
}
int F_67 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_217 ;
int V_1 ;
if ( ! ( V_42 || V_43 ) )
return 0 ;
if ( ! ( V_18 -> V_52 & V_86 ) || ! ( V_18 -> V_52 & V_88 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_91 , V_1 ) ;
return - 1 ;
}
if ( V_218 != 0 ) {
V_126 = V_218 ;
fprintf ( V_29 , L_178 ,
V_1 , V_126 ) ;
return 0 ;
}
if ( ! V_142 )
goto V_219;
if ( F_12 ( 0 , V_220 , & V_25 ) )
goto V_219;
V_217 = ( V_25 >> 16 ) & 0x7F ;
if ( V_112 )
fprintf ( V_29 , L_179 ,
V_1 , V_25 , V_217 ) ;
if ( V_217 < 85 || V_217 > 120 )
goto V_219;
V_126 = V_217 ;
return 0 ;
V_219:
V_126 = V_221 ;
fprintf ( V_29 , L_180 ,
V_1 , V_126 ) ;
return 0 ;
}
void F_68 ()
{
unsigned int V_222 , V_223 , V_224 , V_225 , V_226 ;
unsigned int V_227 , V_186 , V_187 , V_228 ;
V_222 = V_223 = V_224 = V_225 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0));
if ( V_223 == 0x756e6547 && V_225 == 0x49656e69 && V_224 == 0x6c65746e )
V_188 = 1 ;
if ( V_112 )
fprintf ( V_29 , L_181 ,
( char * ) & V_223 , ( char * ) & V_225 , ( char * ) & V_224 ) ;
asm("cpuid" : "=a" (fms), "=c" (ecx), "=d" (edx) : "a" (1) : "ebx");
V_186 = ( V_227 >> 8 ) & 0xf ;
V_187 = ( V_227 >> 4 ) & 0xf ;
V_228 = V_227 & 0xf ;
if ( V_186 == 6 || V_186 == 0xf )
V_187 += ( ( V_227 >> 16 ) & 0xf ) << 4 ;
if ( V_112 )
fprintf ( V_29 , L_182 ,
V_226 , V_186 , V_187 , V_228 , V_186 , V_187 , V_228 ) ;
if ( ! ( V_225 & ( 1 << 5 ) ) ) {
fprintf ( V_29 , L_183 ) ;
exit ( 1 ) ;
}
V_223 = V_224 = V_225 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000000));
if ( V_226 < 0x80000007 ) {
fprintf ( V_29 , L_184 , V_226 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000007));
V_229 = V_225 & ( 1 << 8 ) ;
if ( ! V_229 ) {
fprintf ( V_29 , L_185 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x6));
V_35 = V_224 & ( 1 << 0 ) ;
V_42 = V_222 & ( 1 << 0 ) ;
V_43 = V_222 & ( 1 << 6 ) ;
V_190 = V_224 & ( 1 << 3 ) ;
if ( V_112 )
fprintf ( V_29 , L_186 ,
V_35 ? L_187 : L_188 ,
V_42 ? L_189 : L_110 ,
V_43 ? L_190 : L_110 ,
V_190 ? L_191 : L_110 ) ;
if ( ! V_35 )
exit ( - 1 ) ;
V_142 = V_188 && V_229 ;
V_34 = V_188 ;
V_36 = V_34 ;
V_41 = F_64 ( V_186 , V_187 ) ;
V_44 = F_65 ( V_186 , V_187 ) ;
V_144 = F_66 ( V_186 , V_187 ) ;
V_152 = F_56 ( V_186 , V_187 ) ;
V_146 = F_57 ( V_186 , V_187 ) ;
F_59 ( V_186 , V_187 ) ;
return;
}
void F_69 ()
{
fprintf ( V_29 , L_192 ,
V_111 ) ;
exit ( 1 ) ;
}
int F_70 ( const struct V_230 * V_231 )
{
if ( isdigit ( V_231 -> V_232 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_71 ( int V_233 )
{
return 0 ;
}
void F_72 ()
{
int V_234 ;
int V_235 = 0 ;
int V_236 = 0 ;
int V_237 = 0 ;
struct V_238 {
int V_62 ;
int V_239 ;
} * V_240 ;
V_14 . V_105 = 0 ;
V_14 . V_175 = 0 ;
F_44 ( F_47 ) ;
if ( ! V_104 && V_14 . V_105 > 1 )
V_33 = 1 ;
if ( V_112 > 1 )
fprintf ( V_29 , L_193 , V_14 . V_105 , V_14 . V_175 ) ;
V_240 = calloc ( 1 , ( V_14 . V_175 + 1 ) * sizeof( struct V_238 ) ) ;
if ( V_240 == NULL ) {
perror ( L_194 ) ;
exit ( 1 ) ;
}
V_3 = F_73 ( ( V_14 . V_175 + 1 ) ) ;
if ( V_3 == NULL ) {
perror ( L_195 ) ;
exit ( 3 ) ;
}
V_2 = F_74 ( ( V_14 . V_175 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_44 ( F_48 ) ;
V_23 = F_73 ( ( V_14 . V_175 + 1 ) ) ;
if ( V_23 == NULL ) {
perror ( L_195 ) ;
exit ( 3 ) ;
}
V_22 = F_74 ( ( V_14 . V_175 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_234 = 0 ; V_234 <= V_14 . V_175 ; ++ V_234 ) {
int V_241 ;
if ( F_1 ( V_234 ) ) {
if ( V_112 > 1 )
fprintf ( V_29 , L_196 , V_234 ) ;
continue;
}
V_240 [ V_234 ] . V_62 = F_41 ( V_234 ) ;
if ( V_240 [ V_234 ] . V_62 > V_235 )
V_235 = V_240 [ V_234 ] . V_62 ;
V_240 [ V_234 ] . V_239 = F_40 ( V_234 ) ;
if ( V_240 [ V_234 ] . V_239 > V_236 )
V_236 = V_240 [ V_234 ] . V_239 ;
V_241 = F_42 ( V_234 ) ;
if ( V_241 > V_237 )
V_237 = V_241 ;
if ( V_112 > 1 )
fprintf ( V_29 , L_197 ,
V_234 , V_240 [ V_234 ] . V_239 , V_240 [ V_234 ] . V_62 ) ;
}
V_14 . V_16 = V_235 + 1 ;
if ( V_112 > 1 )
fprintf ( V_29 , L_198 ,
V_235 , V_14 . V_16 ) ;
if ( ! V_104 && V_14 . V_16 > 1 )
V_32 = 1 ;
V_14 . V_15 = V_236 + 1 ;
if ( V_112 > 1 )
fprintf ( V_29 , L_199 ,
V_236 , V_14 . V_15 ) ;
if ( ! V_104 && V_14 . V_15 > 1 )
V_30 = 1 ;
V_14 . V_17 = V_237 ;
if ( V_112 > 1 )
fprintf ( V_29 , L_200 , V_237 ) ;
free ( V_240 ) ;
}
void
F_75 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_234 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_234 = 0 ; V_234 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_234 ++ )
( * V_18 ) [ V_234 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_234 = 0 ; V_234 < V_14 . V_16 * V_14 . V_15 ; V_234 ++ )
( * V_19 ) [ V_234 ] . V_62 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_234 = 0 ; V_234 < V_14 . V_15 ; V_234 ++ )
( * V_20 ) [ V_234 ] . V_67 = V_234 ;
return;
error:
perror ( L_201 ) ;
exit ( 1 ) ;
}
void F_76 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_242 , int V_243 ,
int V_244 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_242 , V_243 , V_244 ) ;
V_19 = F_6 ( V_8 , V_243 , V_244 ) ;
V_20 = F_7 ( V_9 , V_244 ) ;
V_18 -> V_21 = V_21 ;
if ( V_242 == 0 ) {
V_18 -> V_52 |= V_86 ;
if ( F_39 ( V_21 ) )
V_18 -> V_52 |= V_88 ;
}
V_19 -> V_62 = V_243 ;
V_20 -> V_67 = V_244 ;
}
int F_77 ( int V_21 )
{
int V_245 , V_246 , V_247 ;
V_247 = F_40 ( V_21 ) ;
V_246 = F_41 ( V_21 ) ;
if ( F_38 ( V_21 ) ) {
V_245 = 0 ;
V_14 . V_116 ++ ;
} else {
V_245 = 1 ;
}
F_76 ( V_178 , V_245 , V_246 , V_247 , V_21 ) ;
F_76 ( V_182 , V_245 , V_246 , V_247 , V_21 ) ;
return 0 ;
}
void F_78 ()
{
V_102 = calloc ( 1 , ( 1 + V_14 . V_105 ) * 256 ) ;
V_31 = V_102 ;
if ( V_31 == NULL ) {
perror ( L_202 ) ;
exit ( - 1 ) ;
}
}
void F_46 ( void )
{
F_72 () ;
F_75 ( & V_154 , & V_155 , & V_156 ) ;
F_75 ( & V_157 , & V_158 , & V_159 ) ;
F_78 () ;
F_44 ( F_77 ) ;
}
void F_79 ()
{
F_68 () ;
F_53 () ;
F_54 () ;
F_46 () ;
if ( V_112 )
F_33 () ;
if ( V_112 )
F_3 ( F_58 , V_182 ) ;
if ( V_112 )
F_3 ( F_63 , V_182 ) ;
F_3 ( F_67 , V_182 ) ;
if ( V_112 )
F_3 ( F_60 , V_182 ) ;
}
int F_80 ( char * * V_248 )
{
T_4 V_249 ;
int V_250 ;
V_250 = F_3 ( F_32 , V_178 ) ;
if ( V_250 )
exit ( V_250 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_50 ( & V_179 , (struct V_180 * ) NULL ) ;
V_249 = F_81 () ;
if ( ! V_249 ) {
F_82 ( V_248 [ 0 ] , V_248 ) ;
} else {
if ( V_249 == - 1 ) {
perror ( L_203 ) ;
exit ( 1 ) ;
}
signal ( V_251 , V_252 ) ;
signal ( V_253 , V_252 ) ;
if ( F_83 ( V_249 , & V_250 , 0 ) == - 1 ) {
perror ( L_204 ) ;
exit ( V_250 ) ;
}
}
F_3 ( F_32 , V_182 ) ;
F_50 ( & V_183 , (struct V_180 * ) NULL ) ;
F_52 ( & V_183 , & V_179 , & V_89 ) ;
F_43 ( F_26 , V_182 , V_178 ) ;
F_30 ( V_178 ) ;
F_21 ( V_178 ) ;
F_20 () ;
fprintf ( V_29 , L_205 , V_89 . V_90 + V_89 . V_91 / 1000000.0 ) ;
return V_250 ;
}
void F_84 ( int V_254 , char * * V_248 )
{
int V_255 ;
V_111 = V_248 [ 0 ] ;
while ( ( V_255 = F_85 ( V_254 , V_248 , L_206 ) ) != - 1 ) {
switch ( V_255 ) {
case 'p' :
V_85 ++ ;
break;
case 'P' :
V_87 ++ ;
break;
case 'S' :
V_104 ++ ;
break;
case 'v' :
V_112 ++ ;
break;
case 'i' :
V_181 = atoi ( V_256 ) ;
break;
case 'c' :
sscanf ( V_256 , L_207 , & V_37 ) ;
break;
case 'C' :
sscanf ( V_256 , L_207 , & V_38 ) ;
break;
case 'm' :
sscanf ( V_256 , L_207 , & V_39 ) ;
break;
case 'M' :
sscanf ( V_256 , L_207 , & V_40 ) ;
break;
case 'R' :
V_257 ++ ;
break;
case 'T' :
V_218 = atoi ( V_256 ) ;
break;
default:
F_69 () ;
}
}
}
int main ( int V_254 , char * * V_248 )
{
F_84 ( V_254 , V_248 ) ;
if ( V_112 )
fprintf ( V_29 , L_208
L_209 ) ;
F_79 () ;
if ( V_254 - V_258 )
return F_80 ( V_248 + V_258 ) ;
else
F_49 () ;
return 0 ;
}
