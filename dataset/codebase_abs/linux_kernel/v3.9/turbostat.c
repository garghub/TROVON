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
if ( V_44 & V_45 )
V_31 += sprintf ( V_31 , L_25 ) ;
if ( V_44 & V_46 )
V_31 += sprintf ( V_31 , L_26 ) ;
if ( V_44 & V_47 )
V_31 += sprintf ( V_31 , L_27 ) ;
if ( V_44 & V_48 )
V_31 += sprintf ( V_31 , L_28 ) ;
if ( V_44 & V_49 )
V_31 += sprintf ( V_31 , L_29 ) ;
if ( V_44 & V_50 )
V_31 += sprintf ( V_31 , L_30 ) ;
V_31 += sprintf ( V_31 , L_31 ) ;
}
int F_17 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
fprintf ( V_29 , L_32 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
fprintf ( V_29 , L_33 , V_18 -> V_21 , V_18 -> V_51 ) ;
fprintf ( V_29 , L_34 , V_18 -> V_52 ) ;
fprintf ( V_29 , L_35 , V_18 -> V_53 ) ;
fprintf ( V_29 , L_36 , V_18 -> V_54 ) ;
fprintf ( V_29 , L_37 , V_18 -> V_55 ) ;
fprintf ( V_29 , L_38 ,
V_37 , V_18 -> V_56 ) ;
fprintf ( V_29 , L_39 ,
V_38 , V_18 -> V_57 ) ;
fprintf ( V_29 , L_38 ,
V_39 , V_18 -> V_58 ) ;
fprintf ( V_29 , L_39 ,
V_40 , V_18 -> V_59 ) ;
if ( V_36 )
fprintf ( V_29 , L_40 , V_18 -> V_60 ) ;
}
if ( V_19 ) {
fprintf ( V_29 , L_41 , V_19 -> V_61 ) ;
fprintf ( V_29 , L_42 , V_19 -> V_62 ) ;
fprintf ( V_29 , L_43 , V_19 -> V_63 ) ;
fprintf ( V_29 , L_44 , V_19 -> V_64 ) ;
fprintf ( V_29 , L_45 , V_19 -> V_65 ) ;
}
if ( V_20 ) {
fprintf ( V_29 , L_46 , V_20 -> V_66 ) ;
fprintf ( V_29 , L_47 , V_20 -> V_67 ) ;
fprintf ( V_29 , L_48 , V_20 -> V_68 ) ;
fprintf ( V_29 , L_49 , V_20 -> V_69 ) ;
fprintf ( V_29 , L_50 , V_20 -> V_70 ) ;
fprintf ( V_29 , L_51 , V_20 -> V_71 ) ;
fprintf ( V_29 , L_52 , V_20 -> V_72 ) ;
fprintf ( V_29 , L_53 , V_20 -> V_73 ) ;
fprintf ( V_29 , L_54 , V_20 -> V_74 ) ;
fprintf ( V_29 , L_55 , V_20 -> V_75 ) ;
fprintf ( V_29 , L_56 , V_20 -> V_76 ) ;
fprintf ( V_29 , L_57 , V_20 -> V_77 ) ;
}
return 0 ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_78 ;
char * V_79 , * V_80 ;
if ( V_81 && ! ( V_18 -> V_51 & V_82 ) )
return 0 ;
if ( V_83 && ! ( V_18 -> V_51 & V_84 ) )
return 0 ;
V_78 = V_85 . V_86 + V_85 . V_87 / 1000000.0 ;
if ( V_18 == & V_88 . V_89 ) {
if ( V_30 )
V_31 += sprintf ( V_31 , L_58 ) ;
if ( V_30 && V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 )
V_31 += sprintf ( V_31 , L_59 ) ;
if ( V_33 )
V_31 += sprintf ( V_31 , L_4 L_59 ) ;
} else {
if ( V_30 ) {
if ( V_20 )
V_31 += sprintf ( V_31 , L_60 , V_20 -> V_66 ) ;
else
V_31 += sprintf ( V_31 , L_58 ) ;
}
if ( V_30 && V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 ) {
if ( V_19 )
V_31 += sprintf ( V_31 , L_61 , V_19 -> V_61 ) ;
else
V_31 += sprintf ( V_31 , L_59 ) ;
}
if ( V_33 )
V_31 += sprintf ( V_31 , L_62 , V_18 -> V_21 ) ;
}
if ( V_34 ) {
if ( V_30 || V_32 || V_33 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( ! V_90 )
V_31 += sprintf ( V_31 , L_63 , 100.0 * V_18 -> V_54 / V_18 -> V_52 ) ;
else
V_31 += sprintf ( V_31 , L_64 ) ;
}
if ( V_35 ) {
if ( ! V_91 ) {
V_31 += sprintf ( V_31 , L_65 ,
1.0 * V_18 -> V_52 / V_92 * V_18 -> V_53 /
V_18 -> V_54 / V_78 ) ;
} else {
if ( V_18 -> V_53 > V_18 -> V_52 || V_18 -> V_54 > V_18 -> V_52 ) {
V_31 += sprintf ( V_31 , L_66 ) ;
} else {
V_31 += sprintf ( V_31 , L_67 ,
1.0 * V_18 -> V_52 /
V_92 * V_18 -> V_53 /
V_18 -> V_54 / V_78 ) ;
}
}
}
V_31 += sprintf ( V_31 , L_68 , 1.0 * V_18 -> V_52 / V_92 / V_78 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_69 , V_18 -> V_60 ) ;
if ( V_37 )
V_31 += sprintf ( V_31 , L_70 , V_18 -> V_56 ) ;
if ( V_38 )
V_31 += sprintf ( V_31 , L_70 , V_18 -> V_57 ) ;
if ( V_39 )
V_31 += sprintf ( V_31 , L_71 , V_18 -> V_58 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_72 , V_18 -> V_59 ) ;
if ( V_34 ) {
if ( ! V_93 )
V_31 += sprintf ( V_31 , L_73 , 100.0 * V_18 -> V_55 / V_18 -> V_52 ) ;
else
V_31 += sprintf ( V_31 , L_64 ) ;
}
if ( ! ( V_18 -> V_51 & V_82 ) )
goto V_94;
if ( V_34 )
V_31 += sprintf ( V_31 , L_73 , 100.0 * V_19 -> V_62 / V_18 -> V_52 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_73 , 100.0 * V_19 -> V_63 / V_18 -> V_52 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_73 , 100.0 * V_19 -> V_64 / V_18 -> V_52 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_74 , V_19 -> V_65 ) ;
if ( ! ( V_18 -> V_51 & V_84 ) )
goto V_94;
if ( V_43 )
V_31 += sprintf ( V_31 , L_74 , V_20 -> V_77 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_73 , 100.0 * V_20 -> V_67 / V_18 -> V_52 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_73 , 100.0 * V_20 -> V_68 / V_18 -> V_52 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_73 , 100.0 * V_20 -> V_69 / V_18 -> V_52 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_73 , 100.0 * V_20 -> V_70 / V_18 -> V_52 ) ;
if ( V_78 < V_95 ) {
V_79 = L_75 ;
V_80 = L_73 ;
} else {
V_79 = L_76 ;
V_80 = L_77 ;
}
if ( V_44 & V_45 )
V_31 += sprintf ( V_31 , V_80 , V_20 -> V_71 * V_96 / V_78 ) ;
if ( V_44 & V_46 )
V_31 += sprintf ( V_31 , V_80 , V_20 -> V_72 * V_96 / V_78 ) ;
if ( V_44 & V_47 )
V_31 += sprintf ( V_31 , V_79 , V_20 -> V_73 * V_96 / V_78 ) ;
if ( V_44 & V_48 )
V_31 += sprintf ( V_31 , V_79 , V_20 -> V_74 * V_96 / V_78 ) ;
if ( V_44 & V_49 )
V_31 += sprintf ( V_31 , V_79 , 100.0 * V_20 -> V_75 * V_97 / V_78 ) ;
if ( V_44 & V_50 )
V_31 += sprintf ( V_31 , V_79 , 100.0 * V_20 -> V_76 * V_97 / V_78 ) ;
V_94:
V_31 += sprintf ( V_31 , L_31 ) ;
return 0 ;
}
void F_19 ()
{
fputs ( V_98 , stdout ) ;
fflush ( stdout ) ;
V_31 = V_98 ;
}
void F_20 ()
{
fputs ( V_98 , V_29 ) ;
V_31 = V_98 ;
}
void F_21 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_99 ;
if ( ! V_99 || ! V_100 )
F_16 () ;
if ( V_14 . V_101 > 1 )
F_18 ( & V_88 . V_89 , & V_88 . V_102 ,
& V_88 . V_103 ) ;
V_99 = 1 ;
if ( V_100 )
return;
F_3 ( F_18 , V_18 , V_19 , V_20 ) ;
}
void
F_22 ( struct V_6 * V_104 , struct V_6 * V_105 )
{
V_105 -> V_67 = V_104 -> V_67 - V_105 -> V_67 ;
V_105 -> V_68 = V_104 -> V_68 - V_105 -> V_68 ;
V_105 -> V_69 = V_104 -> V_69 - V_105 -> V_69 ;
V_105 -> V_70 = V_104 -> V_70 - V_105 -> V_70 ;
V_105 -> V_77 = V_104 -> V_77 ;
F_23 ( V_104 -> V_71 , V_105 -> V_71 ) ;
F_23 ( V_104 -> V_72 , V_105 -> V_72 ) ;
F_23 ( V_104 -> V_73 , V_105 -> V_73 ) ;
F_23 ( V_104 -> V_74 , V_105 -> V_74 ) ;
F_23 ( V_104 -> V_75 , V_105 -> V_75 ) ;
F_23 ( V_104 -> V_76 , V_105 -> V_76 ) ;
}
void
F_24 ( struct V_5 * V_104 , struct V_5 * V_105 )
{
V_105 -> V_62 = V_104 -> V_62 - V_105 -> V_62 ;
V_105 -> V_63 = V_104 -> V_63 - V_105 -> V_63 ;
V_105 -> V_64 = V_104 -> V_64 - V_105 -> V_64 ;
V_105 -> V_65 = V_104 -> V_65 ;
}
void
F_25 ( struct V_4 * V_104 , struct V_4 * V_105 ,
struct V_5 * V_106 )
{
V_105 -> V_52 = V_104 -> V_52 - V_105 -> V_52 ;
if ( V_105 -> V_52 < ( 1000 * 1000 ) ) {
fprintf ( V_29 , L_78 ) ;
fprintf ( V_29 , L_79 ) ;
fprintf ( V_29 , L_80 ) ;
exit ( - 3 ) ;
}
V_105 -> V_55 = V_104 -> V_55 - V_105 -> V_55 ;
if ( ( V_104 -> V_53 > V_105 -> V_53 ) && ( V_104 -> V_54 > V_105 -> V_54 ) ) {
V_105 -> V_53 = V_104 -> V_53 - V_105 -> V_53 ;
V_105 -> V_54 = V_104 -> V_54 - V_105 -> V_54 ;
} else {
if ( ! V_91 ) {
fprintf ( V_29 , L_81 , V_107 ) ;
fprintf ( V_29 , L_82 ) ;
fprintf ( V_29 , L_83 ) ;
V_91 = 1 ;
}
V_90 = 1 ;
V_93 = 1 ;
}
if ( ( V_105 -> V_54 + V_106 -> V_62 + V_106 -> V_63 + V_106 -> V_64 ) > V_105 -> V_52 )
V_105 -> V_55 = 0 ;
else {
V_105 -> V_55 = V_105 -> V_52 - V_105 -> V_54 - V_106 -> V_62
- V_106 -> V_63 - V_106 -> V_64 ;
}
if ( V_105 -> V_54 == 0 ) {
if ( V_108 > 1 ) fprintf ( V_29 , L_84 , V_105 -> V_21 ) ;
V_105 -> V_54 = 1 ;
}
V_105 -> V_56 = V_104 -> V_56 - V_105 -> V_56 ;
V_105 -> V_56 &= 0xFFFFFFFF ;
V_105 -> V_57 = V_104 -> V_57 - V_105 -> V_57 ;
V_105 -> V_58 = V_104 -> V_58 ;
V_105 -> V_59 = V_104 -> V_59 ;
if ( V_36 )
V_105 -> V_60 = V_104 -> V_60 - V_105 -> V_60 ;
}
int F_26 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_109 ,
struct V_5 * V_110 , struct V_6 * V_111 )
{
if ( V_18 -> V_51 & V_82 )
F_24 ( V_19 , V_110 ) ;
F_25 ( V_18 , V_109 , V_110 ) ;
if ( V_18 -> V_51 & V_84 )
F_22 ( V_20 , V_111 ) ;
return 0 ;
}
void F_27 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
V_18 -> V_52 = 0 ;
V_18 -> V_53 = 0 ;
V_18 -> V_54 = 0 ;
V_18 -> V_55 = 0 ;
V_18 -> V_60 = 0 ;
V_18 -> V_56 = 0 ;
V_18 -> V_57 = 0 ;
V_18 -> V_51 = V_82 | V_84 ;
V_19 -> V_62 = 0 ;
V_19 -> V_63 = 0 ;
V_19 -> V_64 = 0 ;
V_19 -> V_65 = 0 ;
V_20 -> V_67 = 0 ;
V_20 -> V_68 = 0 ;
V_20 -> V_69 = 0 ;
V_20 -> V_70 = 0 ;
V_20 -> V_71 = 0 ;
V_20 -> V_74 = 0 ;
V_20 -> V_72 = 0 ;
V_20 -> V_73 = 0 ;
V_20 -> V_75 = 0 ;
V_20 -> V_76 = 0 ;
V_20 -> V_77 = 0 ;
}
int F_28 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_88 . V_89 . V_52 += V_18 -> V_52 ;
V_88 . V_89 . V_53 += V_18 -> V_53 ;
V_88 . V_89 . V_54 += V_18 -> V_54 ;
V_88 . V_89 . V_55 += V_18 -> V_55 ;
V_88 . V_89 . V_56 += V_18 -> V_56 ;
V_88 . V_89 . V_57 += V_18 -> V_57 ;
if ( ! ( V_18 -> V_51 & V_82 ) )
return 0 ;
V_88 . V_102 . V_62 += V_19 -> V_62 ;
V_88 . V_102 . V_63 += V_19 -> V_63 ;
V_88 . V_102 . V_64 += V_19 -> V_64 ;
V_88 . V_102 . V_65 = F_29 ( V_88 . V_102 . V_65 , V_19 -> V_65 ) ;
if ( ! ( V_18 -> V_51 & V_84 ) )
return 0 ;
V_88 . V_103 . V_67 += V_20 -> V_67 ;
V_88 . V_103 . V_68 += V_20 -> V_68 ;
V_88 . V_103 . V_69 += V_20 -> V_69 ;
V_88 . V_103 . V_70 += V_20 -> V_70 ;
V_88 . V_103 . V_71 += V_20 -> V_71 ;
V_88 . V_103 . V_74 += V_20 -> V_74 ;
V_88 . V_103 . V_72 += V_20 -> V_72 ;
V_88 . V_103 . V_73 += V_20 -> V_73 ;
V_88 . V_103 . V_77 = F_29 ( V_88 . V_103 . V_77 , V_20 -> V_77 ) ;
V_88 . V_103 . V_75 += V_20 -> V_75 ;
V_88 . V_103 . V_76 += V_20 -> V_76 ;
return 0 ;
}
void F_30 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_27 ( & V_88 . V_89 , & V_88 . V_102 , & V_88 . V_103 ) ;
F_3 ( F_28 , V_18 , V_19 , V_20 ) ;
V_88 . V_89 . V_52 /= V_14 . V_101 ;
V_88 . V_89 . V_53 /= V_14 . V_101 ;
V_88 . V_89 . V_54 /= V_14 . V_101 ;
V_88 . V_89 . V_55 /= V_14 . V_101 ;
V_88 . V_89 . V_56 /= V_14 . V_101 ;
V_88 . V_89 . V_56 &= 0xFFFFFFFF ;
V_88 . V_89 . V_57 /= V_14 . V_101 ;
V_88 . V_102 . V_62 /= V_14 . V_112 ;
V_88 . V_102 . V_63 /= V_14 . V_112 ;
V_88 . V_102 . V_64 /= V_14 . V_112 ;
V_88 . V_103 . V_67 /= V_14 . V_15 ;
V_88 . V_103 . V_68 /= V_14 . V_15 ;
V_88 . V_103 . V_69 /= V_14 . V_15 ;
V_88 . V_103 . V_70 /= V_14 . V_15 ;
}
static unsigned long long F_31 ( void )
{
unsigned int V_113 , V_114 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_113 | ( ( unsigned long long ) V_114 ) << 32 ;
}
int F_32 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
unsigned long long V_25 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_85 , V_1 ) ;
return - 1 ;
}
V_18 -> V_52 = F_31 () ;
if ( V_35 ) {
if ( F_12 ( V_1 , V_115 , & V_18 -> V_53 ) )
return - 3 ;
if ( F_12 ( V_1 , V_116 , & V_18 -> V_54 ) )
return - 4 ;
}
if ( V_36 ) {
if ( F_12 ( V_1 , V_117 , & V_25 ) )
return - 5 ;
V_18 -> V_60 = V_25 & 0xFFFFFFFF ;
}
if ( V_37 ) {
if ( F_12 ( V_1 , V_37 , & V_25 ) )
return - 5 ;
V_18 -> V_56 = V_25 & 0xFFFFFFFF ;
}
if ( V_38 )
if ( F_12 ( V_1 , V_38 , & V_18 -> V_57 ) )
return - 5 ;
if ( V_39 ) {
if ( F_12 ( V_1 , V_39 , & V_25 ) )
return - 5 ;
V_18 -> V_58 = V_25 & 0xFFFFFFFF ;
}
if ( V_40 )
if ( F_12 ( V_1 , V_40 , & V_18 -> V_59 ) )
return - 5 ;
if ( ! ( V_18 -> V_51 & V_82 ) )
return 0 ;
if ( V_34 ) {
if ( F_12 ( V_1 , V_118 , & V_19 -> V_62 ) )
return - 6 ;
if ( F_12 ( V_1 , V_119 , & V_19 -> V_63 ) )
return - 7 ;
}
if ( V_41 )
if ( F_12 ( V_1 , V_120 , & V_19 -> V_64 ) )
return - 8 ;
if ( V_42 ) {
if ( F_12 ( V_1 , V_121 , & V_25 ) )
return - 9 ;
V_19 -> V_65 = V_122 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
if ( ! ( V_18 -> V_51 & V_84 ) )
return 0 ;
if ( V_34 ) {
if ( F_12 ( V_1 , V_123 , & V_20 -> V_68 ) )
return - 9 ;
if ( F_12 ( V_1 , V_124 , & V_20 -> V_69 ) )
return - 10 ;
}
if ( V_41 ) {
if ( F_12 ( V_1 , V_125 , & V_20 -> V_67 ) )
return - 11 ;
if ( F_12 ( V_1 , V_126 , & V_20 -> V_70 ) )
return - 12 ;
}
if ( V_44 & V_45 ) {
if ( F_12 ( V_1 , V_127 , & V_25 ) )
return - 13 ;
V_20 -> V_71 = V_25 & 0xFFFFFFFF ;
}
if ( V_44 & V_46 ) {
if ( F_12 ( V_1 , V_128 , & V_25 ) )
return - 14 ;
V_20 -> V_72 = V_25 & 0xFFFFFFFF ;
}
if ( V_44 & V_48 ) {
if ( F_12 ( V_1 , V_129 , & V_25 ) )
return - 15 ;
V_20 -> V_74 = V_25 & 0xFFFFFFFF ;
}
if ( V_44 & V_47 ) {
if ( F_12 ( V_1 , V_130 , & V_25 ) )
return - 16 ;
V_20 -> V_73 = V_25 & 0xFFFFFFFF ;
}
if ( V_44 & V_49 ) {
if ( F_12 ( V_1 , V_131 , & V_25 ) )
return - 16 ;
V_20 -> V_75 = V_25 & 0xFFFFFFFF ;
}
if ( V_44 & V_50 ) {
if ( F_12 ( V_1 , V_132 , & V_25 ) )
return - 16 ;
V_20 -> V_76 = V_25 & 0xFFFFFFFF ;
}
if ( V_43 ) {
if ( F_12 ( V_1 , V_133 , & V_25 ) )
return - 17 ;
V_20 -> V_77 = V_122 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
return 0 ;
}
void F_33 ( void )
{
unsigned long long V_25 ;
unsigned int V_134 ;
if ( ! V_135 )
return;
F_12 ( 0 , V_136 , & V_25 ) ;
fprintf ( V_29 , L_86 , V_25 ) ;
V_134 = ( V_25 >> 40 ) & 0xFF ;
fprintf ( V_29 , L_87 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 8 ) & 0xFF ;
fprintf ( V_29 , L_88 ,
V_134 , V_137 , V_134 * V_137 ) ;
F_12 ( 0 , V_138 , & V_25 ) ;
fprintf ( V_29 , L_89 ,
V_25 , V_25 & 0x2 ? L_90 : L_91 ) ;
if ( ! V_139 )
goto V_140;
F_12 ( 0 , V_141 , & V_25 ) ;
fprintf ( V_29 , L_92 , V_25 ) ;
V_134 = ( V_25 >> 56 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_93 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 48 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_94 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 40 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_95 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 32 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_96 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 24 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_97 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 16 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_98 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 8 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_99 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 0 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_100 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_140:
F_12 ( 0 , V_142 , & V_25 ) ;
#define F_34 (1UL << 27)
#define F_35 (1UL << 28)
fprintf ( V_29 , L_101 , V_25 ) ;
fprintf ( V_29 , L_102 ,
( V_25 & F_35 ) ? L_103 : L_104 ,
( V_25 & F_34 ) ? L_105 : L_104 ,
( V_25 & V_143 ) ? L_106 : L_104 ,
( V_25 & V_144 ) ? L_107 : L_104 ,
( V_25 & ( 1 << 15 ) ) ? L_104 : L_108 ,
( unsigned int ) V_25 & 7 ) ;
switch( V_25 & 0x7 ) {
case 0 :
fprintf ( V_29 , L_109 ) ;
break;
case 1 :
fprintf ( V_29 , V_41 ? L_110 : L_109 ) ;
break;
case 2 :
fprintf ( V_29 , V_41 ? L_111 : L_112 ) ;
break;
case 3 :
fprintf ( V_29 , L_113 ) ;
break;
case 4 :
fprintf ( V_29 , L_114 ) ;
break;
case 5 :
fprintf ( V_29 , V_41 ? L_115 : L_116 ) ;
break;
case 7 :
fprintf ( V_29 , L_117 ) ;
break;
default:
fprintf ( V_29 , L_116 ) ;
}
fprintf ( V_29 , L_118 ) ;
if ( ! V_145 )
return;
F_12 ( 0 , V_146 , & V_25 ) ;
fprintf ( V_29 , L_119 , V_25 ) ;
V_134 = ( V_25 >> 56 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_120 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 48 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_121 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 40 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_122 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 32 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_123 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 24 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_124 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 16 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_125 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 8 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_126 ,
V_134 , V_137 , V_134 * V_137 ) ;
V_134 = ( V_25 >> 0 ) & 0xFF ;
if ( V_134 )
fprintf ( V_29 , L_127 ,
V_134 , V_137 , V_134 * V_137 ) ;
}
void F_36 ( void )
{
F_37 ( V_3 ) ;
V_3 = NULL ;
V_3 = 0 ;
F_37 ( V_23 ) ;
V_23 = NULL ;
V_22 = 0 ;
free ( V_147 ) ;
free ( V_148 ) ;
free ( V_149 ) ;
V_147 = NULL ;
V_148 = NULL ;
V_149 = NULL ;
free ( V_150 ) ;
free ( V_151 ) ;
free ( V_152 ) ;
V_150 = NULL ;
V_151 = NULL ;
V_152 = NULL ;
free ( V_98 ) ;
V_98 = NULL ;
V_31 = NULL ;
}
int F_38 ( int V_1 )
{
char V_153 [ 64 ] ;
T_3 * V_154 ;
int V_155 ;
sprintf ( V_153 , L_128 , V_1 ) ;
V_154 = fopen ( V_153 , L_129 ) ;
if ( V_154 == NULL ) {
perror ( V_153 ) ;
exit ( 1 ) ;
}
fscanf ( V_154 , L_130 , & V_155 ) ;
fclose ( V_154 ) ;
return ( V_1 == V_155 ) ;
}
int F_39 ( int V_1 )
{
char V_153 [ 64 ] ;
T_3 * V_154 ;
int V_155 ;
sprintf ( V_153 , L_131 , V_1 ) ;
V_154 = fopen ( V_153 , L_129 ) ;
if ( V_154 == NULL ) {
perror ( V_153 ) ;
exit ( 1 ) ;
}
fscanf ( V_154 , L_130 , & V_155 ) ;
fclose ( V_154 ) ;
return ( V_1 == V_155 ) ;
}
int F_40 ( int V_1 )
{
char V_153 [ 80 ] ;
T_3 * V_154 ;
int V_156 ;
sprintf ( V_153 , L_132 , V_1 ) ;
V_154 = fopen ( V_153 , L_129 ) ;
if ( V_154 == NULL ) {
perror ( V_153 ) ;
exit ( 1 ) ;
}
fscanf ( V_154 , L_130 , & V_156 ) ;
fclose ( V_154 ) ;
return V_156 ;
}
int F_41 ( int V_1 )
{
char V_153 [ 80 ] ;
T_3 * V_154 ;
int V_157 ;
sprintf ( V_153 , L_133 , V_1 ) ;
V_154 = fopen ( V_153 , L_129 ) ;
if ( V_154 == NULL ) {
perror ( V_153 ) ;
exit ( 1 ) ;
}
fscanf ( V_154 , L_130 , & V_157 ) ;
fclose ( V_154 ) ;
return V_157 ;
}
int F_42 ( int V_1 )
{
char V_153 [ 80 ] ;
T_3 * V_154 ;
int V_158 , V_159 ;
int V_160 ;
char V_161 ;
sprintf ( V_153 , L_128 , V_1 ) ;
V_154 = fopen ( V_153 , L_129 ) ;
if ( V_154 == NULL ) {
perror ( V_153 ) ;
exit ( 1 ) ;
}
V_160 = fscanf ( V_154 , L_134 , & V_158 , & V_161 , & V_159 ) ;
fclose ( V_154 ) ;
if ( V_160 == 3 )
return 2 ;
else
return 1 ;
}
int F_43 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_162 , struct V_5 * V_163 ,
struct V_6 * V_164 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_109 ;
struct V_5 * V_19 , * V_110 ;
struct V_6 * V_20 , * V_111 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_109 = F_5 ( V_162 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_110 = F_6 ( V_163 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_111 = F_7 ( V_164 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_109 , V_110 , V_111 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_44 ( int (F_4)( int ) )
{
T_3 * V_165 ;
int V_166 ;
int V_10 ;
V_165 = fopen ( V_167 , L_129 ) ;
if ( V_165 == NULL ) {
perror ( V_167 ) ;
exit ( 1 ) ;
}
V_10 = fscanf ( V_165 , L_135 ) ;
if ( V_10 != 0 ) {
perror ( L_136 ) ;
exit ( 1 ) ;
}
while ( 1 ) {
V_10 = fscanf ( V_165 , L_137 , & V_166 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_166 ) ;
if ( V_10 ) {
fclose ( V_165 ) ;
return ( V_10 ) ;
}
}
fclose ( V_165 ) ;
return 0 ;
}
void F_45 ( void )
{
F_36 () ;
F_46 () ;
printf ( L_138 , V_14 . V_101 ) ;
}
int F_47 ( int V_1 )
{
if ( V_14 . V_168 < V_1 )
V_14 . V_168 = V_1 ;
V_14 . V_101 += 1 ;
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
int V_169 = 0 ;
V_170:
V_169 ++ ;
V_10 = F_3 ( F_32 , V_171 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
if ( V_169 > 1 ) {
exit ( V_10 ) ;
}
F_45 () ;
goto V_170;
}
V_169 = 0 ;
F_50 ( & V_172 , (struct V_173 * ) NULL ) ;
while ( 1 ) {
if ( F_44 ( F_1 ) ) {
F_45 () ;
goto V_170;
}
F_51 ( V_174 ) ;
V_10 = F_3 ( F_32 , V_175 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_45 () ;
goto V_170;
}
F_50 ( & V_176 , (struct V_173 * ) NULL ) ;
F_52 ( & V_176 , & V_172 , & V_85 ) ;
F_43 ( F_26 , V_175 , V_171 ) ;
F_30 ( V_171 ) ;
F_21 ( V_171 ) ;
F_19 () ;
F_51 ( V_174 ) ;
V_10 = F_3 ( F_32 , V_171 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_45 () ;
goto V_170;
}
F_50 ( & V_172 , (struct V_173 * ) NULL ) ;
F_52 ( & V_172 , & V_176 , & V_85 ) ;
F_43 ( F_26 , V_171 , V_175 ) ;
F_30 ( V_175 ) ;
F_21 ( V_175 ) ;
F_19 () ;
}
}
void F_53 ()
{
struct V_177 V_178 ;
if ( V_177 ( L_139 , & V_178 ) ) {
fprintf ( V_29 , L_140 ) ;
fprintf ( V_29 , L_141 ) ;
exit ( - 5 ) ;
}
}
void F_54 ()
{
if ( F_55 () != 0 ) {
fprintf ( V_29 , L_142 ) ;
exit ( - 6 ) ;
}
}
int F_56 ( unsigned int V_179 , unsigned int V_180 )
{
if ( ! V_181 )
return 0 ;
if ( V_179 != 6 )
return 0 ;
switch ( V_180 ) {
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
int F_57 ( unsigned int V_179 , unsigned int V_180 )
{
if ( ! V_181 )
return 0 ;
if ( V_179 != 6 )
return 0 ;
switch ( V_180 ) {
case 0x3E :
return 1 ;
default:
return 0 ;
}
}
int F_58 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
char * V_182 ;
int V_1 ;
if ( ! V_183 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_51 & V_82 ) || ! ( V_18 -> V_51 & V_84 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_85 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_184 , & V_25 ) )
return 0 ;
switch ( V_25 & 0x7 ) {
case V_185 :
V_182 = L_143 ;
break;
case V_186 :
V_182 = L_144 ;
break;
case V_187 :
V_182 = L_145 ;
break;
default:
V_182 = L_146 ;
break;
}
fprintf ( V_29 , L_147 , V_1 , V_25 , V_182 ) ;
return 0 ;
}
void F_59 ( unsigned int V_179 , unsigned int V_180 )
{
unsigned long long V_25 ;
double V_188 ;
if ( ! V_181 )
return;
if ( V_179 != 6 )
return;
switch ( V_180 ) {
case 0x2A :
case 0x3A :
case 0x3C :
case 0x3F :
case 0x45 :
case 0x46 :
V_44 = V_45 | V_46 | V_47 ;
break;
case 0x2D :
case 0x3E :
V_44 = V_45 | V_46 | V_48 | V_49 | V_50 ;
break;
default:
return;
}
if ( F_12 ( 0 , V_189 , & V_25 ) )
return;
V_190 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
V_96 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_97 = 1.0 / ( 1 << ( V_25 >> 16 & 0xF ) ) ;
if ( F_12 ( 0 , V_191 , & V_25 ) )
return;
V_188 = ( ( V_25 >> 0 ) & V_192 ) * V_190 ;
V_95 = 0xFFFFFFFF * V_96 / V_188 ;
if ( V_108 )
fprintf ( V_29 , L_148 , V_95 ) ;
return;
}
int F_60 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_193 ;
int V_1 ;
if ( ! ( V_42 || V_43 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_51 & V_82 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_85 , V_1 ) ;
return - 1 ;
}
if ( V_43 && ( V_18 -> V_51 & V_84 ) ) {
if ( F_12 ( V_1 , V_133 , & V_25 ) )
return 0 ;
V_193 = ( V_25 >> 16 ) & 0x7F ;
fprintf ( V_29 , L_149 ,
V_1 , V_25 , V_122 - V_193 ) ;
#ifdef F_61
if ( F_12 ( V_1 , V_194 , & V_25 ) )
return 0 ;
V_193 = ( V_25 >> 16 ) & 0x7F ;
V_195 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_150 ,
V_1 , V_25 , V_122 - V_193 , V_122 - V_195 ) ;
#endif
}
if ( V_42 ) {
unsigned int V_196 ;
if ( F_12 ( V_1 , V_121 , & V_25 ) )
return 0 ;
V_193 = ( V_25 >> 16 ) & 0x7F ;
V_196 = ( V_25 >> 27 ) & 0xF ;
fprintf ( V_29 , L_151 ,
V_1 , V_25 , V_122 - V_193 , V_196 ) ;
#ifdef F_61
if ( F_12 ( V_1 , V_197 , & V_25 ) )
return 0 ;
V_193 = ( V_25 >> 16 ) & 0x7F ;
V_195 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_152 ,
V_1 , V_25 , V_122 - V_193 , V_122 - V_195 ) ;
#endif
}
return 0 ;
}
void F_62 ( int V_1 , unsigned long long V_25 , char * V_198 )
{
fprintf ( V_29 , L_153 ,
V_1 , V_198 ,
( ( V_25 >> 15 ) & 1 ) ? L_90 : L_91 ,
( ( V_25 >> 0 ) & 0x7FFF ) * V_190 ,
( 1.0 + ( ( ( V_25 >> 22 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 17 ) & 0x1F ) ) * V_97 ,
( ( ( V_25 >> 16 ) & 1 ) ? L_90 : L_91 ) ) ;
return;
}
int F_63 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
double V_199 , V_200 , V_201 ;
if ( ! V_44 )
return 0 ;
if ( ! ( V_18 -> V_51 & V_82 ) || ! ( V_18 -> V_51 & V_84 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_85 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_189 , & V_25 ) )
return - 1 ;
V_199 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
V_200 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_201 = 1.0 / ( 1 << ( V_25 >> 16 & 0xF ) ) ;
if ( V_199 != V_190 )
fprintf ( V_29 , L_154 , V_1 ) ;
if ( V_200 != V_96 )
fprintf ( V_29 , L_155 , V_1 ) ;
if ( V_201 != V_97 )
fprintf ( V_29 , L_156 , V_1 ) ;
if ( V_108 ) {
fprintf ( V_29 , L_157
L_158 , V_1 , V_25 ,
V_199 , V_200 , V_201 ) ;
}
if ( V_44 & V_45 ) {
if ( F_12 ( V_1 , V_191 , & V_25 ) )
return - 5 ;
fprintf ( V_29 , L_159 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_192 ) * V_190 ,
( ( V_25 >> 16 ) & V_192 ) * V_190 ,
( ( V_25 >> 32 ) & V_192 ) * V_190 ,
( ( V_25 >> 48 ) & V_202 ) * V_97 ) ;
if ( F_12 ( V_1 , V_203 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_160 ,
V_1 , V_25 , ( V_25 >> 63 ) & 1 ? L_104 : L_108 ) ;
F_62 ( V_1 , V_25 , L_161 ) ;
fprintf ( V_29 , L_162 ,
V_1 ,
( ( V_25 >> 47 ) & 1 ) ? L_90 : L_91 ,
( ( V_25 >> 32 ) & 0x7FFF ) * V_190 ,
( 1.0 + ( ( ( V_25 >> 54 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 49 ) & 0x1F ) ) * V_97 ,
( ( V_25 >> 48 ) & 1 ) ? L_90 : L_91 ) ;
}
if ( V_44 & V_48 ) {
if ( F_12 ( V_1 , V_204 , & V_25 ) )
return - 6 ;
fprintf ( V_29 , L_163 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_192 ) * V_190 ,
( ( V_25 >> 16 ) & V_192 ) * V_190 ,
( ( V_25 >> 32 ) & V_192 ) * V_190 ,
( ( V_25 >> 48 ) & V_202 ) * V_97 ) ;
if ( F_12 ( V_1 , V_205 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_164 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_104 : L_108 ) ;
F_62 ( V_1 , V_25 , L_165 ) ;
}
if ( V_44 & V_46 ) {
if ( V_108 ) {
if ( F_12 ( V_1 , V_206 , & V_25 ) )
return - 7 ;
fprintf ( V_29 , L_166 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_207 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_167 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_104 : L_108 ) ;
F_62 ( V_1 , V_25 , L_168 ) ;
}
}
if ( V_44 & V_47 ) {
if ( V_108 ) {
if ( F_12 ( V_1 , V_208 , & V_25 ) )
return - 8 ;
fprintf ( V_29 , L_169 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_209 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_170 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_104 : L_108 ) ;
F_62 ( V_1 , V_25 , L_171 ) ;
}
}
return 0 ;
}
int F_64 ( unsigned int V_179 , unsigned int V_180 )
{
if ( ! V_181 )
return 0 ;
switch ( V_180 ) {
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
double F_65 ( unsigned int V_179 , unsigned int V_180 )
{
if ( F_64 ( V_179 , V_180 ) )
return 100.00 ;
else
return 133.33 ;
}
int F_66 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_210 ;
int V_1 ;
if ( ! ( V_42 || V_43 ) )
return 0 ;
if ( ! ( V_18 -> V_51 & V_82 ) || ! ( V_18 -> V_51 & V_84 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_85 , V_1 ) ;
return - 1 ;
}
if ( V_211 != 0 ) {
V_122 = V_211 ;
fprintf ( V_29 , L_172 ,
V_1 , V_122 ) ;
return 0 ;
}
if ( ! V_135 )
goto V_212;
if ( F_12 ( 0 , V_213 , & V_25 ) )
goto V_212;
V_210 = ( V_25 >> 16 ) & 0x7F ;
if ( V_108 )
fprintf ( V_29 , L_173 ,
V_1 , V_25 , V_210 ) ;
if ( V_210 < 85 || V_210 > 120 )
goto V_212;
V_122 = V_210 ;
return 0 ;
V_212:
V_122 = V_214 ;
fprintf ( V_29 , L_174 ,
V_1 , V_122 ) ;
return 0 ;
}
void F_67 ()
{
unsigned int V_215 , V_216 , V_217 , V_218 , V_219 ;
unsigned int V_220 , V_179 , V_180 , V_221 ;
V_215 = V_216 = V_217 = V_218 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0));
if ( V_216 == 0x756e6547 && V_218 == 0x49656e69 && V_217 == 0x6c65746e )
V_181 = 1 ;
if ( V_108 )
fprintf ( V_29 , L_175 ,
( char * ) & V_216 , ( char * ) & V_218 , ( char * ) & V_217 ) ;
asm("cpuid" : "=a" (fms), "=c" (ecx), "=d" (edx) : "a" (1) : "ebx");
V_179 = ( V_220 >> 8 ) & 0xf ;
V_180 = ( V_220 >> 4 ) & 0xf ;
V_221 = V_220 & 0xf ;
if ( V_179 == 6 || V_179 == 0xf )
V_180 += ( ( V_220 >> 16 ) & 0xf ) << 4 ;
if ( V_108 )
fprintf ( V_29 , L_176 ,
V_219 , V_179 , V_180 , V_221 , V_179 , V_180 , V_221 ) ;
if ( ! ( V_218 & ( 1 << 5 ) ) ) {
fprintf ( V_29 , L_177 ) ;
exit ( 1 ) ;
}
V_216 = V_217 = V_218 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000000));
if ( V_219 < 0x80000007 ) {
fprintf ( V_29 , L_178 , V_219 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000007));
V_222 = V_218 & ( 1 << 8 ) ;
if ( ! V_222 ) {
fprintf ( V_29 , L_179 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x6));
V_35 = V_217 & ( 1 << 0 ) ;
V_42 = V_215 & ( 1 << 0 ) ;
V_43 = V_215 & ( 1 << 6 ) ;
V_183 = V_217 & ( 1 << 3 ) ;
if ( V_108 )
fprintf ( V_29 , L_180 ,
V_35 ? L_181 : L_182 ,
V_42 ? L_183 : L_104 ,
V_43 ? L_184 : L_104 ,
V_183 ? L_185 : L_104 ) ;
if ( ! V_35 )
exit ( - 1 ) ;
V_135 = V_181 && V_222 ;
V_34 = V_181 ;
V_36 = V_34 ;
V_41 = F_64 ( V_179 , V_180 ) ;
V_137 = F_65 ( V_179 , V_180 ) ;
V_145 = F_56 ( V_179 , V_180 ) ;
V_139 = F_57 ( V_179 , V_180 ) ;
F_59 ( V_179 , V_180 ) ;
return;
}
void F_68 ()
{
fprintf ( V_29 , L_186 ,
V_107 ) ;
exit ( 1 ) ;
}
int F_69 ( const struct V_223 * V_224 )
{
if ( isdigit ( V_224 -> V_225 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_70 ( int V_226 )
{
return 0 ;
}
void F_71 ()
{
int V_227 ;
int V_228 = 0 ;
int V_229 = 0 ;
int V_230 = 0 ;
struct V_231 {
int V_61 ;
int V_232 ;
} * V_233 ;
V_14 . V_101 = 0 ;
V_14 . V_168 = 0 ;
F_44 ( F_47 ) ;
if ( ! V_100 && V_14 . V_101 > 1 )
V_33 = 1 ;
if ( V_108 > 1 )
fprintf ( V_29 , L_187 , V_14 . V_101 , V_14 . V_168 ) ;
V_233 = calloc ( 1 , ( V_14 . V_168 + 1 ) * sizeof( struct V_231 ) ) ;
if ( V_233 == NULL ) {
perror ( L_188 ) ;
exit ( 1 ) ;
}
V_3 = F_72 ( ( V_14 . V_168 + 1 ) ) ;
if ( V_3 == NULL ) {
perror ( L_189 ) ;
exit ( 3 ) ;
}
V_2 = F_73 ( ( V_14 . V_168 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_44 ( F_48 ) ;
V_23 = F_72 ( ( V_14 . V_168 + 1 ) ) ;
if ( V_23 == NULL ) {
perror ( L_189 ) ;
exit ( 3 ) ;
}
V_22 = F_73 ( ( V_14 . V_168 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_227 = 0 ; V_227 <= V_14 . V_168 ; ++ V_227 ) {
int V_234 ;
if ( F_1 ( V_227 ) ) {
if ( V_108 > 1 )
fprintf ( V_29 , L_190 , V_227 ) ;
continue;
}
V_233 [ V_227 ] . V_61 = F_41 ( V_227 ) ;
if ( V_233 [ V_227 ] . V_61 > V_228 )
V_228 = V_233 [ V_227 ] . V_61 ;
V_233 [ V_227 ] . V_232 = F_40 ( V_227 ) ;
if ( V_233 [ V_227 ] . V_232 > V_229 )
V_229 = V_233 [ V_227 ] . V_232 ;
V_234 = F_42 ( V_227 ) ;
if ( V_234 > V_230 )
V_230 = V_234 ;
if ( V_108 > 1 )
fprintf ( V_29 , L_191 ,
V_227 , V_233 [ V_227 ] . V_232 , V_233 [ V_227 ] . V_61 ) ;
}
V_14 . V_16 = V_228 + 1 ;
if ( V_108 > 1 )
fprintf ( V_29 , L_192 ,
V_228 , V_14 . V_16 ) ;
if ( ! V_100 && V_14 . V_16 > 1 )
V_32 = 1 ;
V_14 . V_15 = V_229 + 1 ;
if ( V_108 > 1 )
fprintf ( V_29 , L_193 ,
V_229 , V_14 . V_15 ) ;
if ( ! V_100 && V_14 . V_15 > 1 )
V_30 = 1 ;
V_14 . V_17 = V_230 ;
if ( V_108 > 1 )
fprintf ( V_29 , L_194 , V_230 ) ;
free ( V_233 ) ;
}
void
F_74 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_227 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_227 = 0 ; V_227 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_227 ++ )
( * V_18 ) [ V_227 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_227 = 0 ; V_227 < V_14 . V_16 * V_14 . V_15 ; V_227 ++ )
( * V_19 ) [ V_227 ] . V_61 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_227 = 0 ; V_227 < V_14 . V_15 ; V_227 ++ )
( * V_20 ) [ V_227 ] . V_66 = V_227 ;
return;
error:
perror ( L_195 ) ;
exit ( 1 ) ;
}
void F_75 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_235 , int V_236 ,
int V_237 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_235 , V_236 , V_237 ) ;
V_19 = F_6 ( V_8 , V_236 , V_237 ) ;
V_20 = F_7 ( V_9 , V_237 ) ;
V_18 -> V_21 = V_21 ;
if ( V_235 == 0 ) {
V_18 -> V_51 |= V_82 ;
if ( F_39 ( V_21 ) )
V_18 -> V_51 |= V_84 ;
}
V_19 -> V_61 = V_236 ;
V_20 -> V_66 = V_237 ;
}
int F_76 ( int V_21 )
{
int V_238 , V_239 , V_240 ;
V_240 = F_40 ( V_21 ) ;
V_239 = F_41 ( V_21 ) ;
if ( F_38 ( V_21 ) ) {
V_238 = 0 ;
V_14 . V_112 ++ ;
} else {
V_238 = 1 ;
}
F_75 ( V_171 , V_238 , V_239 , V_240 , V_21 ) ;
F_75 ( V_175 , V_238 , V_239 , V_240 , V_21 ) ;
return 0 ;
}
void F_77 ()
{
V_98 = calloc ( 1 , ( 1 + V_14 . V_101 ) * 128 ) ;
V_31 = V_98 ;
if ( V_31 == NULL ) {
perror ( L_196 ) ;
exit ( - 1 ) ;
}
}
void F_46 ( void )
{
F_71 () ;
F_74 ( & V_147 , & V_148 , & V_149 ) ;
F_74 ( & V_150 , & V_151 , & V_152 ) ;
F_77 () ;
F_44 ( F_76 ) ;
}
void F_78 ()
{
F_67 () ;
F_53 () ;
F_54 () ;
F_46 () ;
if ( V_108 )
F_33 () ;
if ( V_108 )
F_3 ( F_58 , V_175 ) ;
if ( V_108 )
F_3 ( F_63 , V_175 ) ;
F_3 ( F_66 , V_175 ) ;
if ( V_108 )
F_3 ( F_60 , V_175 ) ;
}
int F_79 ( char * * V_241 )
{
T_4 V_242 ;
int V_243 ;
V_243 = F_3 ( F_32 , V_171 ) ;
if ( V_243 )
exit ( V_243 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_50 ( & V_172 , (struct V_173 * ) NULL ) ;
V_242 = F_80 () ;
if ( ! V_242 ) {
F_81 ( V_241 [ 0 ] , V_241 ) ;
} else {
if ( V_242 == - 1 ) {
perror ( L_197 ) ;
exit ( 1 ) ;
}
signal ( V_244 , V_245 ) ;
signal ( V_246 , V_245 ) ;
if ( F_82 ( V_242 , & V_243 , 0 ) == - 1 ) {
perror ( L_198 ) ;
exit ( V_243 ) ;
}
}
F_3 ( F_32 , V_175 ) ;
F_50 ( & V_176 , (struct V_173 * ) NULL ) ;
F_52 ( & V_176 , & V_172 , & V_85 ) ;
F_43 ( F_26 , V_175 , V_171 ) ;
F_30 ( V_171 ) ;
F_21 ( V_171 ) ;
F_20 () ;
fprintf ( V_29 , L_199 , V_85 . V_86 + V_85 . V_87 / 1000000.0 ) ;
return V_243 ;
}
void F_83 ( int V_247 , char * * V_241 )
{
int V_248 ;
V_107 = V_241 [ 0 ] ;
while ( ( V_248 = F_84 ( V_247 , V_241 , L_200 ) ) != - 1 ) {
switch ( V_248 ) {
case 'p' :
V_81 ++ ;
break;
case 'P' :
V_83 ++ ;
break;
case 'S' :
V_100 ++ ;
break;
case 'v' :
V_108 ++ ;
break;
case 'i' :
V_174 = atoi ( V_249 ) ;
break;
case 'c' :
sscanf ( V_249 , L_201 , & V_37 ) ;
break;
case 'C' :
sscanf ( V_249 , L_201 , & V_38 ) ;
break;
case 'm' :
sscanf ( V_249 , L_201 , & V_39 ) ;
break;
case 'M' :
sscanf ( V_249 , L_201 , & V_40 ) ;
break;
case 'R' :
V_250 ++ ;
break;
case 'T' :
V_211 = atoi ( V_249 ) ;
break;
default:
F_68 () ;
}
}
}
int main ( int V_247 , char * * V_241 )
{
F_83 ( V_247 , V_241 ) ;
if ( V_108 )
fprintf ( V_29 , L_202
L_203 ) ;
F_78 () ;
if ( V_247 - V_251 )
return F_79 ( V_241 + V_251 ) ;
else
F_49 () ;
return 0 ;
}
