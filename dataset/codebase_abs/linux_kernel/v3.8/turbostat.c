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
V_31 += sprintf ( V_31 , L_10 , V_36 ) ;
if ( V_37 )
V_31 += sprintf ( V_31 , L_11 , V_37 ) ;
if ( V_38 )
V_31 += sprintf ( V_31 , L_12 , V_38 ) ;
if ( V_39 )
V_31 += sprintf ( V_31 , L_13 , V_39 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_14 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_15 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_16 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_17 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_18 ) ;
if ( V_42 )
V_31 += sprintf ( V_31 , L_19 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_20 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_21 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_22 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_23 ) ;
if ( V_43 & V_44 )
V_31 += sprintf ( V_31 , L_24 ) ;
if ( V_43 & V_45 )
V_31 += sprintf ( V_31 , L_25 ) ;
if ( V_43 & V_46 )
V_31 += sprintf ( V_31 , L_26 ) ;
if ( V_43 & V_47 )
V_31 += sprintf ( V_31 , L_27 ) ;
if ( V_43 & V_48 )
V_31 += sprintf ( V_31 , L_28 ) ;
if ( V_43 & V_49 )
V_31 += sprintf ( V_31 , L_29 ) ;
V_31 += sprintf ( V_31 , L_30 ) ;
}
int F_17 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
fprintf ( V_29 , L_31 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
fprintf ( V_29 , L_32 , V_18 -> V_21 , V_18 -> V_50 ) ;
fprintf ( V_29 , L_33 , V_18 -> V_51 ) ;
fprintf ( V_29 , L_34 , V_18 -> V_52 ) ;
fprintf ( V_29 , L_35 , V_18 -> V_53 ) ;
fprintf ( V_29 , L_36 , V_18 -> V_54 ) ;
fprintf ( V_29 , L_37 ,
V_36 , V_18 -> V_55 ) ;
fprintf ( V_29 , L_38 ,
V_37 , V_18 -> V_56 ) ;
fprintf ( V_29 , L_37 ,
V_38 , V_18 -> V_57 ) ;
fprintf ( V_29 , L_38 ,
V_39 , V_18 -> V_58 ) ;
}
if ( V_19 ) {
fprintf ( V_29 , L_39 , V_19 -> V_59 ) ;
fprintf ( V_29 , L_40 , V_19 -> V_60 ) ;
fprintf ( V_29 , L_41 , V_19 -> V_61 ) ;
fprintf ( V_29 , L_42 , V_19 -> V_62 ) ;
fprintf ( V_29 , L_43 , V_19 -> V_63 ) ;
}
if ( V_20 ) {
fprintf ( V_29 , L_44 , V_20 -> V_64 ) ;
fprintf ( V_29 , L_45 , V_20 -> V_65 ) ;
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
}
return 0 ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_76 ;
char * V_77 , * V_78 ;
if ( V_79 && ! ( V_18 -> V_50 & V_80 ) )
return 0 ;
if ( V_81 && ! ( V_18 -> V_50 & V_82 ) )
return 0 ;
V_76 = V_83 . V_84 + V_83 . V_85 / 1000000.0 ;
if ( V_18 == & V_86 . V_87 ) {
if ( V_30 )
V_31 += sprintf ( V_31 , L_56 ) ;
if ( V_30 && V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 )
V_31 += sprintf ( V_31 , L_57 ) ;
if ( V_33 )
V_31 += sprintf ( V_31 , L_4 L_57 ) ;
} else {
if ( V_30 ) {
if ( V_20 )
V_31 += sprintf ( V_31 , L_58 , V_20 -> V_64 ) ;
else
V_31 += sprintf ( V_31 , L_56 ) ;
}
if ( V_30 && V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 ) {
if ( V_19 )
V_31 += sprintf ( V_31 , L_59 , V_19 -> V_59 ) ;
else
V_31 += sprintf ( V_31 , L_57 ) ;
}
if ( V_33 )
V_31 += sprintf ( V_31 , L_60 , V_18 -> V_21 ) ;
}
if ( V_34 ) {
if ( V_30 || V_32 || V_33 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( ! V_88 )
V_31 += sprintf ( V_31 , L_61 , 100.0 * V_18 -> V_53 / V_18 -> V_51 ) ;
else
V_31 += sprintf ( V_31 , L_62 ) ;
}
if ( V_35 ) {
if ( ! V_89 ) {
V_31 += sprintf ( V_31 , L_63 ,
1.0 * V_18 -> V_51 / V_90 * V_18 -> V_52 /
V_18 -> V_53 / V_76 ) ;
} else {
if ( V_18 -> V_52 > V_18 -> V_51 || V_18 -> V_53 > V_18 -> V_51 ) {
V_31 += sprintf ( V_31 , L_64 ) ;
} else {
V_31 += sprintf ( V_31 , L_65 ,
1.0 * V_18 -> V_51 /
V_90 * V_18 -> V_52 /
V_18 -> V_53 / V_76 ) ;
}
}
}
V_31 += sprintf ( V_31 , L_66 , 1.0 * V_18 -> V_51 / V_90 / V_76 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_67 , V_18 -> V_55 ) ;
if ( V_37 )
V_31 += sprintf ( V_31 , L_67 , V_18 -> V_56 ) ;
if ( V_38 )
V_31 += sprintf ( V_31 , L_68 , V_18 -> V_57 ) ;
if ( V_39 )
V_31 += sprintf ( V_31 , L_69 , V_18 -> V_58 ) ;
if ( V_34 ) {
if ( ! V_91 )
V_31 += sprintf ( V_31 , L_70 , 100.0 * V_18 -> V_54 / V_18 -> V_51 ) ;
else
V_31 += sprintf ( V_31 , L_62 ) ;
}
if ( ! ( V_18 -> V_50 & V_80 ) )
goto V_92;
if ( V_34 )
V_31 += sprintf ( V_31 , L_70 , 100.0 * V_19 -> V_60 / V_18 -> V_51 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_70 , 100.0 * V_19 -> V_61 / V_18 -> V_51 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_70 , 100.0 * V_19 -> V_62 / V_18 -> V_51 ) ;
if ( V_41 )
V_31 += sprintf ( V_31 , L_71 , V_19 -> V_63 ) ;
if ( ! ( V_18 -> V_50 & V_82 ) )
goto V_92;
if ( V_42 )
V_31 += sprintf ( V_31 , L_71 , V_20 -> V_75 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_70 , 100.0 * V_20 -> V_65 / V_18 -> V_51 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_70 , 100.0 * V_20 -> V_66 / V_18 -> V_51 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_70 , 100.0 * V_20 -> V_67 / V_18 -> V_51 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_70 , 100.0 * V_20 -> V_68 / V_18 -> V_51 ) ;
if ( V_76 < V_93 ) {
V_77 = L_72 ;
V_78 = L_70 ;
} else {
V_77 = L_73 ;
V_78 = L_74 ;
}
if ( V_43 & V_44 )
V_31 += sprintf ( V_31 , V_78 , V_20 -> V_69 * V_94 / V_76 ) ;
if ( V_43 & V_45 )
V_31 += sprintf ( V_31 , V_78 , V_20 -> V_70 * V_94 / V_76 ) ;
if ( V_43 & V_46 )
V_31 += sprintf ( V_31 , V_77 , V_20 -> V_71 * V_94 / V_76 ) ;
if ( V_43 & V_47 )
V_31 += sprintf ( V_31 , V_77 , V_20 -> V_72 * V_94 / V_76 ) ;
if ( V_43 & V_48 )
V_31 += sprintf ( V_31 , V_77 , 100.0 * V_20 -> V_73 * V_95 / V_76 ) ;
if ( V_43 & V_49 )
V_31 += sprintf ( V_31 , V_77 , 100.0 * V_20 -> V_74 * V_95 / V_76 ) ;
V_92:
V_31 += sprintf ( V_31 , L_30 ) ;
return 0 ;
}
void F_19 ()
{
fputs ( V_96 , stdout ) ;
fflush ( stdout ) ;
V_31 = V_96 ;
}
void F_20 ()
{
fputs ( V_96 , V_29 ) ;
V_31 = V_96 ;
}
void F_21 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_97 ;
if ( ! V_97 || ! V_98 )
F_16 () ;
if ( V_14 . V_99 > 1 )
F_18 ( & V_86 . V_87 , & V_86 . V_100 ,
& V_86 . V_101 ) ;
V_97 = 1 ;
if ( V_98 )
return;
F_3 ( F_18 , V_18 , V_19 , V_20 ) ;
}
void
F_22 ( struct V_6 * V_102 , struct V_6 * V_103 )
{
V_103 -> V_65 = V_102 -> V_65 - V_103 -> V_65 ;
V_103 -> V_66 = V_102 -> V_66 - V_103 -> V_66 ;
V_103 -> V_67 = V_102 -> V_67 - V_103 -> V_67 ;
V_103 -> V_68 = V_102 -> V_68 - V_103 -> V_68 ;
V_103 -> V_75 = V_102 -> V_75 ;
F_23 ( V_102 -> V_69 , V_103 -> V_69 ) ;
F_23 ( V_102 -> V_70 , V_103 -> V_70 ) ;
F_23 ( V_102 -> V_71 , V_103 -> V_71 ) ;
F_23 ( V_102 -> V_72 , V_103 -> V_72 ) ;
F_23 ( V_102 -> V_73 , V_103 -> V_73 ) ;
F_23 ( V_102 -> V_74 , V_103 -> V_74 ) ;
}
void
F_24 ( struct V_5 * V_102 , struct V_5 * V_103 )
{
V_103 -> V_60 = V_102 -> V_60 - V_103 -> V_60 ;
V_103 -> V_61 = V_102 -> V_61 - V_103 -> V_61 ;
V_103 -> V_62 = V_102 -> V_62 - V_103 -> V_62 ;
V_103 -> V_63 = V_102 -> V_63 ;
}
void
F_25 ( struct V_4 * V_102 , struct V_4 * V_103 ,
struct V_5 * V_104 )
{
V_103 -> V_51 = V_102 -> V_51 - V_103 -> V_51 ;
if ( V_103 -> V_51 < ( 1000 * 1000 ) ) {
fprintf ( V_29 , L_75 ) ;
fprintf ( V_29 , L_76 ) ;
fprintf ( V_29 , L_77 ) ;
exit ( - 3 ) ;
}
V_103 -> V_54 = V_102 -> V_54 - V_103 -> V_54 ;
if ( ( V_102 -> V_52 > V_103 -> V_52 ) && ( V_102 -> V_53 > V_103 -> V_53 ) ) {
V_103 -> V_52 = V_102 -> V_52 - V_103 -> V_52 ;
V_103 -> V_53 = V_102 -> V_53 - V_103 -> V_53 ;
} else {
if ( ! V_89 ) {
fprintf ( V_29 , L_78 , V_105 ) ;
fprintf ( V_29 , L_79 ) ;
fprintf ( V_29 , L_80 ) ;
V_89 = 1 ;
}
V_88 = 1 ;
V_91 = 1 ;
}
if ( ( V_103 -> V_53 + V_104 -> V_60 + V_104 -> V_61 + V_104 -> V_62 ) > V_103 -> V_51 )
V_103 -> V_54 = 0 ;
else {
V_103 -> V_54 = V_103 -> V_51 - V_103 -> V_53 - V_104 -> V_60
- V_104 -> V_61 - V_104 -> V_62 ;
}
if ( V_103 -> V_53 == 0 ) {
if ( V_106 > 1 ) fprintf ( V_29 , L_81 , V_103 -> V_21 ) ;
V_103 -> V_53 = 1 ;
}
V_103 -> V_55 = V_102 -> V_55 - V_103 -> V_55 ;
V_103 -> V_55 &= 0xFFFFFFFF ;
V_103 -> V_56 = V_102 -> V_56 - V_103 -> V_56 ;
V_103 -> V_57 = V_102 -> V_57 ;
V_103 -> V_58 = V_102 -> V_58 ;
}
int F_26 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_107 ,
struct V_5 * V_108 , struct V_6 * V_109 )
{
if ( V_18 -> V_50 & V_80 )
F_24 ( V_19 , V_108 ) ;
F_25 ( V_18 , V_107 , V_108 ) ;
if ( V_18 -> V_50 & V_82 )
F_22 ( V_20 , V_109 ) ;
return 0 ;
}
void F_27 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
V_18 -> V_51 = 0 ;
V_18 -> V_52 = 0 ;
V_18 -> V_53 = 0 ;
V_18 -> V_54 = 0 ;
V_18 -> V_55 = 0 ;
V_18 -> V_56 = 0 ;
V_18 -> V_50 = V_80 | V_82 ;
V_19 -> V_60 = 0 ;
V_19 -> V_61 = 0 ;
V_19 -> V_62 = 0 ;
V_19 -> V_63 = 0 ;
V_20 -> V_65 = 0 ;
V_20 -> V_66 = 0 ;
V_20 -> V_67 = 0 ;
V_20 -> V_68 = 0 ;
V_20 -> V_69 = 0 ;
V_20 -> V_72 = 0 ;
V_20 -> V_70 = 0 ;
V_20 -> V_71 = 0 ;
V_20 -> V_73 = 0 ;
V_20 -> V_74 = 0 ;
V_20 -> V_75 = 0 ;
}
int F_28 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_86 . V_87 . V_51 += V_18 -> V_51 ;
V_86 . V_87 . V_52 += V_18 -> V_52 ;
V_86 . V_87 . V_53 += V_18 -> V_53 ;
V_86 . V_87 . V_54 += V_18 -> V_54 ;
V_86 . V_87 . V_55 += V_18 -> V_55 ;
V_86 . V_87 . V_56 += V_18 -> V_56 ;
if ( ! ( V_18 -> V_50 & V_80 ) )
return 0 ;
V_86 . V_100 . V_60 += V_19 -> V_60 ;
V_86 . V_100 . V_61 += V_19 -> V_61 ;
V_86 . V_100 . V_62 += V_19 -> V_62 ;
V_86 . V_100 . V_63 = F_29 ( V_86 . V_100 . V_63 , V_19 -> V_63 ) ;
if ( ! ( V_18 -> V_50 & V_82 ) )
return 0 ;
V_86 . V_101 . V_65 += V_20 -> V_65 ;
V_86 . V_101 . V_66 += V_20 -> V_66 ;
V_86 . V_101 . V_67 += V_20 -> V_67 ;
V_86 . V_101 . V_68 += V_20 -> V_68 ;
V_86 . V_101 . V_69 += V_20 -> V_69 ;
V_86 . V_101 . V_72 += V_20 -> V_72 ;
V_86 . V_101 . V_70 += V_20 -> V_70 ;
V_86 . V_101 . V_71 += V_20 -> V_71 ;
V_86 . V_101 . V_75 = F_29 ( V_86 . V_101 . V_75 , V_20 -> V_75 ) ;
V_86 . V_101 . V_73 += V_20 -> V_73 ;
V_86 . V_101 . V_74 += V_20 -> V_74 ;
return 0 ;
}
void F_30 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_27 ( & V_86 . V_87 , & V_86 . V_100 , & V_86 . V_101 ) ;
F_3 ( F_28 , V_18 , V_19 , V_20 ) ;
V_86 . V_87 . V_51 /= V_14 . V_99 ;
V_86 . V_87 . V_52 /= V_14 . V_99 ;
V_86 . V_87 . V_53 /= V_14 . V_99 ;
V_86 . V_87 . V_54 /= V_14 . V_99 ;
V_86 . V_87 . V_55 /= V_14 . V_99 ;
V_86 . V_87 . V_55 &= 0xFFFFFFFF ;
V_86 . V_87 . V_56 /= V_14 . V_99 ;
V_86 . V_100 . V_60 /= V_14 . V_110 ;
V_86 . V_100 . V_61 /= V_14 . V_110 ;
V_86 . V_100 . V_62 /= V_14 . V_110 ;
V_86 . V_101 . V_65 /= V_14 . V_15 ;
V_86 . V_101 . V_66 /= V_14 . V_15 ;
V_86 . V_101 . V_67 /= V_14 . V_15 ;
V_86 . V_101 . V_68 /= V_14 . V_15 ;
}
static unsigned long long F_31 ( void )
{
unsigned int V_111 , V_112 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_111 | ( ( unsigned long long ) V_112 ) << 32 ;
}
int F_32 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
unsigned long long V_25 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_82 , V_1 ) ;
return - 1 ;
}
V_18 -> V_51 = F_31 () ;
if ( V_35 ) {
if ( F_12 ( V_1 , V_113 , & V_18 -> V_52 ) )
return - 3 ;
if ( F_12 ( V_1 , V_114 , & V_18 -> V_53 ) )
return - 4 ;
}
if ( V_36 ) {
if ( F_12 ( V_1 , V_36 , & V_25 ) )
return - 5 ;
V_18 -> V_55 = V_25 & 0xFFFFFFFF ;
}
if ( V_37 )
if ( F_12 ( V_1 , V_37 , & V_18 -> V_56 ) )
return - 5 ;
if ( V_38 ) {
if ( F_12 ( V_1 , V_38 , & V_25 ) )
return - 5 ;
V_18 -> V_57 = V_25 & 0xFFFFFFFF ;
}
if ( V_39 )
if ( F_12 ( V_1 , V_39 , & V_18 -> V_58 ) )
return - 5 ;
if ( ! ( V_18 -> V_50 & V_80 ) )
return 0 ;
if ( V_34 ) {
if ( F_12 ( V_1 , V_115 , & V_19 -> V_60 ) )
return - 6 ;
if ( F_12 ( V_1 , V_116 , & V_19 -> V_61 ) )
return - 7 ;
}
if ( V_40 )
if ( F_12 ( V_1 , V_117 , & V_19 -> V_62 ) )
return - 8 ;
if ( V_41 ) {
if ( F_12 ( V_1 , V_118 , & V_25 ) )
return - 9 ;
V_19 -> V_63 = V_119 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
if ( ! ( V_18 -> V_50 & V_82 ) )
return 0 ;
if ( V_34 ) {
if ( F_12 ( V_1 , V_120 , & V_20 -> V_66 ) )
return - 9 ;
if ( F_12 ( V_1 , V_121 , & V_20 -> V_67 ) )
return - 10 ;
}
if ( V_40 ) {
if ( F_12 ( V_1 , V_122 , & V_20 -> V_65 ) )
return - 11 ;
if ( F_12 ( V_1 , V_123 , & V_20 -> V_68 ) )
return - 12 ;
}
if ( V_43 & V_44 ) {
if ( F_12 ( V_1 , V_124 , & V_25 ) )
return - 13 ;
V_20 -> V_69 = V_25 & 0xFFFFFFFF ;
}
if ( V_43 & V_45 ) {
if ( F_12 ( V_1 , V_125 , & V_25 ) )
return - 14 ;
V_20 -> V_70 = V_25 & 0xFFFFFFFF ;
}
if ( V_43 & V_47 ) {
if ( F_12 ( V_1 , V_126 , & V_25 ) )
return - 15 ;
V_20 -> V_72 = V_25 & 0xFFFFFFFF ;
}
if ( V_43 & V_46 ) {
if ( F_12 ( V_1 , V_127 , & V_25 ) )
return - 16 ;
V_20 -> V_71 = V_25 & 0xFFFFFFFF ;
}
if ( V_43 & V_48 ) {
if ( F_12 ( V_1 , V_128 , & V_25 ) )
return - 16 ;
V_20 -> V_73 = V_25 & 0xFFFFFFFF ;
}
if ( V_43 & V_49 ) {
if ( F_12 ( V_1 , V_129 , & V_25 ) )
return - 16 ;
V_20 -> V_74 = V_25 & 0xFFFFFFFF ;
}
if ( V_42 ) {
if ( F_12 ( V_1 , V_130 , & V_25 ) )
return - 17 ;
V_20 -> V_75 = V_119 - ( ( V_25 >> 16 ) & 0x7F ) ;
}
return 0 ;
}
void F_33 ( void )
{
unsigned long long V_25 ;
unsigned int V_131 ;
if ( ! V_132 )
return;
F_12 ( 0 , V_133 , & V_25 ) ;
if ( V_106 )
fprintf ( V_29 , L_83 , V_25 ) ;
V_131 = ( V_25 >> 40 ) & 0xFF ;
fprintf ( V_29 , L_84 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 8 ) & 0xFF ;
fprintf ( V_29 , L_85 ,
V_131 , V_134 , V_131 * V_134 ) ;
if ( ! V_135 )
goto V_136;
F_12 ( 0 , V_137 , & V_25 ) ;
if ( V_106 )
fprintf ( V_29 , L_86 , V_25 ) ;
V_131 = ( V_25 >> 56 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_87 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 48 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_88 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 40 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_89 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 32 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_90 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 24 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_91 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 16 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_92 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 8 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_93 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 0 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_94 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_136:
F_12 ( 0 , V_138 , & V_25 ) ;
#define F_34 (1UL << 27)
#define F_35 (1UL << 28)
fprintf ( V_29 , L_95 , V_25 ) ;
fprintf ( V_29 , L_96 ,
( V_25 & F_35 ) ? L_97 : L_98 ,
( V_25 & F_34 ) ? L_99 : L_98 ,
( V_25 & V_139 ) ? L_100 : L_98 ,
( V_25 & V_140 ) ? L_101 : L_98 ,
( V_25 & ( 1 << 15 ) ) ? L_98 : L_102 ,
( unsigned int ) V_25 & 7 ) ;
switch( V_25 & 0x7 ) {
case 0 :
fprintf ( V_29 , L_103 ) ;
break;
case 1 :
fprintf ( V_29 , V_40 ? L_104 : L_103 ) ;
break;
case 2 :
fprintf ( V_29 , V_40 ? L_105 : L_106 ) ;
break;
case 3 :
fprintf ( V_29 , L_107 ) ;
break;
case 4 :
fprintf ( V_29 , L_108 ) ;
break;
case 5 :
fprintf ( V_29 , V_40 ? L_109 : L_110 ) ;
break;
case 7 :
fprintf ( V_29 , L_111 ) ;
break;
default:
fprintf ( V_29 , L_110 ) ;
}
fprintf ( V_29 , L_112 ) ;
if ( ! V_141 )
return;
F_12 ( 0 , V_142 , & V_25 ) ;
if ( V_106 )
fprintf ( V_29 , L_113 , V_25 ) ;
V_131 = ( V_25 >> 56 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_114 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 48 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_115 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 40 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_116 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 32 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_117 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 24 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_118 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 16 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_119 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 8 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_120 ,
V_131 , V_134 , V_131 * V_134 ) ;
V_131 = ( V_25 >> 0 ) & 0xFF ;
if ( V_131 )
fprintf ( V_29 , L_121 ,
V_131 , V_134 , V_131 * V_134 ) ;
}
void F_36 ( void )
{
F_37 ( V_3 ) ;
V_3 = NULL ;
V_3 = 0 ;
F_37 ( V_23 ) ;
V_23 = NULL ;
V_22 = 0 ;
free ( V_143 ) ;
free ( V_144 ) ;
free ( V_145 ) ;
V_143 = NULL ;
V_144 = NULL ;
V_145 = NULL ;
free ( V_146 ) ;
free ( V_147 ) ;
free ( V_148 ) ;
V_146 = NULL ;
V_147 = NULL ;
V_148 = NULL ;
free ( V_96 ) ;
V_96 = NULL ;
V_31 = NULL ;
}
int F_38 ( int V_1 )
{
char V_149 [ 64 ] ;
T_3 * V_150 ;
int V_151 ;
sprintf ( V_149 , L_122 , V_1 ) ;
V_150 = fopen ( V_149 , L_123 ) ;
if ( V_150 == NULL ) {
perror ( V_149 ) ;
exit ( 1 ) ;
}
fscanf ( V_150 , L_124 , & V_151 ) ;
fclose ( V_150 ) ;
return ( V_1 == V_151 ) ;
}
int F_39 ( int V_1 )
{
char V_149 [ 64 ] ;
T_3 * V_150 ;
int V_151 ;
sprintf ( V_149 , L_125 , V_1 ) ;
V_150 = fopen ( V_149 , L_123 ) ;
if ( V_150 == NULL ) {
perror ( V_149 ) ;
exit ( 1 ) ;
}
fscanf ( V_150 , L_124 , & V_151 ) ;
fclose ( V_150 ) ;
return ( V_1 == V_151 ) ;
}
int F_40 ( int V_1 )
{
char V_149 [ 80 ] ;
T_3 * V_150 ;
int V_152 ;
sprintf ( V_149 , L_126 , V_1 ) ;
V_150 = fopen ( V_149 , L_123 ) ;
if ( V_150 == NULL ) {
perror ( V_149 ) ;
exit ( 1 ) ;
}
fscanf ( V_150 , L_124 , & V_152 ) ;
fclose ( V_150 ) ;
return V_152 ;
}
int F_41 ( int V_1 )
{
char V_149 [ 80 ] ;
T_3 * V_150 ;
int V_153 ;
sprintf ( V_149 , L_127 , V_1 ) ;
V_150 = fopen ( V_149 , L_123 ) ;
if ( V_150 == NULL ) {
perror ( V_149 ) ;
exit ( 1 ) ;
}
fscanf ( V_150 , L_124 , & V_153 ) ;
fclose ( V_150 ) ;
return V_153 ;
}
int F_42 ( int V_1 )
{
char V_149 [ 80 ] ;
T_3 * V_150 ;
int V_154 , V_155 ;
int V_156 ;
char V_157 ;
sprintf ( V_149 , L_122 , V_1 ) ;
V_150 = fopen ( V_149 , L_123 ) ;
if ( V_150 == NULL ) {
perror ( V_149 ) ;
exit ( 1 ) ;
}
V_156 = fscanf ( V_150 , L_128 , & V_154 , & V_157 , & V_155 ) ;
fclose ( V_150 ) ;
if ( V_156 == 3 )
return 2 ;
else
return 1 ;
}
int F_43 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_158 , struct V_5 * V_159 ,
struct V_6 * V_160 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_107 ;
struct V_5 * V_19 , * V_108 ;
struct V_6 * V_20 , * V_109 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_107 = F_5 ( V_158 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_108 = F_6 ( V_159 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_109 = F_7 ( V_160 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_107 , V_108 , V_109 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_44 ( int (F_4)( int ) )
{
T_3 * V_161 ;
int V_162 ;
int V_10 ;
V_161 = fopen ( V_163 , L_123 ) ;
if ( V_161 == NULL ) {
perror ( V_163 ) ;
exit ( 1 ) ;
}
V_10 = fscanf ( V_161 , L_129 ) ;
if ( V_10 != 0 ) {
perror ( L_130 ) ;
exit ( 1 ) ;
}
while ( 1 ) {
V_10 = fscanf ( V_161 , L_131 , & V_162 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_162 ) ;
if ( V_10 ) {
fclose ( V_161 ) ;
return ( V_10 ) ;
}
}
fclose ( V_161 ) ;
return 0 ;
}
void F_45 ( void )
{
F_36 () ;
F_46 () ;
printf ( L_132 , V_14 . V_99 ) ;
}
int F_47 ( int V_1 )
{
if ( V_14 . V_164 < V_1 )
V_14 . V_164 = V_1 ;
V_14 . V_99 += 1 ;
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
int V_165 = 0 ;
V_166:
V_165 ++ ;
V_10 = F_3 ( F_32 , V_167 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
if ( V_165 > 1 ) {
exit ( V_10 ) ;
}
F_45 () ;
goto V_166;
}
V_165 = 0 ;
F_50 ( & V_168 , (struct V_169 * ) NULL ) ;
while ( 1 ) {
if ( F_44 ( F_1 ) ) {
F_45 () ;
goto V_166;
}
F_51 ( V_170 ) ;
V_10 = F_3 ( F_32 , V_171 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_45 () ;
goto V_166;
}
F_50 ( & V_172 , (struct V_169 * ) NULL ) ;
F_52 ( & V_172 , & V_168 , & V_83 ) ;
F_43 ( F_26 , V_171 , V_167 ) ;
F_30 ( V_167 ) ;
F_21 ( V_167 ) ;
F_19 () ;
F_51 ( V_170 ) ;
V_10 = F_3 ( F_32 , V_167 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_45 () ;
goto V_166;
}
F_50 ( & V_168 , (struct V_169 * ) NULL ) ;
F_52 ( & V_168 , & V_172 , & V_83 ) ;
F_43 ( F_26 , V_167 , V_171 ) ;
F_30 ( V_171 ) ;
F_21 ( V_171 ) ;
F_19 () ;
}
}
void F_53 ()
{
struct V_173 V_174 ;
if ( V_173 ( L_133 , & V_174 ) ) {
fprintf ( V_29 , L_134 ) ;
fprintf ( V_29 , L_135 ) ;
exit ( - 5 ) ;
}
}
void F_54 ()
{
if ( F_55 () != 0 ) {
fprintf ( V_29 , L_136 ) ;
exit ( - 6 ) ;
}
}
int F_56 ( unsigned int V_175 , unsigned int V_176 )
{
if ( ! V_177 )
return 0 ;
if ( V_175 != 6 )
return 0 ;
switch ( V_176 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x25 :
case 0x2C :
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
return 1 ;
case 0x2E :
case 0x2F :
default:
return 0 ;
}
}
int F_57 ( unsigned int V_175 , unsigned int V_176 )
{
if ( ! V_177 )
return 0 ;
if ( V_175 != 6 )
return 0 ;
switch ( V_176 ) {
case 0x3E :
return 1 ;
default:
return 0 ;
}
}
int F_58 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
char * V_178 ;
int V_1 ;
if ( ! V_179 )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_50 & V_80 ) || ! ( V_18 -> V_50 & V_82 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_82 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_180 , & V_25 ) )
return 0 ;
switch ( V_25 & 0x7 ) {
case V_181 :
V_178 = L_137 ;
break;
case V_182 :
V_178 = L_138 ;
break;
case V_183 :
V_178 = L_139 ;
break;
default:
V_178 = L_140 ;
break;
}
fprintf ( V_29 , L_141 , V_1 , V_25 , V_178 ) ;
return 0 ;
}
void F_59 ( unsigned int V_175 , unsigned int V_176 )
{
unsigned long long V_25 ;
double V_184 ;
if ( ! V_177 )
return;
if ( V_175 != 6 )
return;
switch ( V_176 ) {
case 0x2A :
case 0x3A :
V_43 = V_44 | V_45 | V_46 ;
break;
case 0x2D :
case 0x3E :
V_43 = V_44 | V_45 | V_47 | V_48 | V_49 ;
break;
default:
return;
}
if ( F_12 ( 0 , V_185 , & V_25 ) )
return;
V_186 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
V_94 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_95 = 1.0 / ( 1 << ( V_25 >> 16 & 0xF ) ) ;
if ( F_12 ( 0 , V_187 , & V_25 ) )
return;
V_184 = ( ( V_25 >> 0 ) & V_188 ) * V_186 ;
V_93 = 0xFFFFFFFF * V_94 / V_184 ;
if ( V_106 )
fprintf ( V_29 , L_142 , V_93 ) ;
return;
}
int F_60 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_189 ;
int V_1 ;
if ( ! ( V_41 || V_42 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( ! ( V_18 -> V_50 & V_80 ) )
return 0 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_82 , V_1 ) ;
return - 1 ;
}
if ( V_42 && ( V_18 -> V_50 & V_82 ) ) {
if ( F_12 ( V_1 , V_130 , & V_25 ) )
return 0 ;
V_189 = ( V_25 >> 16 ) & 0x7F ;
fprintf ( V_29 , L_143 ,
V_1 , V_25 , V_119 - V_189 ) ;
#ifdef F_61
if ( F_12 ( V_1 , V_190 , & V_25 ) )
return 0 ;
V_189 = ( V_25 >> 16 ) & 0x7F ;
V_191 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_144 ,
V_1 , V_25 , V_119 - V_189 , V_119 - V_191 ) ;
#endif
}
if ( V_41 ) {
unsigned int V_192 ;
if ( F_12 ( V_1 , V_118 , & V_25 ) )
return 0 ;
V_189 = ( V_25 >> 16 ) & 0x7F ;
V_192 = ( V_25 >> 27 ) & 0xF ;
fprintf ( V_29 , L_145 ,
V_1 , V_25 , V_119 - V_189 , V_192 ) ;
#ifdef F_61
if ( F_12 ( V_1 , V_193 , & V_25 ) )
return 0 ;
V_189 = ( V_25 >> 16 ) & 0x7F ;
V_191 = ( V_25 >> 8 ) & 0x7F ;
fprintf ( V_29 , L_146 ,
V_1 , V_25 , V_119 - V_189 , V_119 - V_191 ) ;
#endif
}
return 0 ;
}
void F_62 ( int V_1 , unsigned long long V_25 , char * V_194 )
{
fprintf ( V_29 , L_147 ,
V_1 , V_194 ,
( ( V_25 >> 15 ) & 1 ) ? L_148 : L_149 ,
( ( V_25 >> 0 ) & 0x7FFF ) * V_186 ,
( 1.0 + ( ( ( V_25 >> 22 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 17 ) & 0x1F ) ) * V_95 ,
( ( ( V_25 >> 16 ) & 1 ) ? L_148 : L_149 ) ) ;
return;
}
int F_63 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
int V_1 ;
double V_195 , V_196 , V_197 ;
if ( ! V_43 )
return 0 ;
if ( ! ( V_18 -> V_50 & V_80 ) || ! ( V_18 -> V_50 & V_82 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_82 , V_1 ) ;
return - 1 ;
}
if ( F_12 ( V_1 , V_185 , & V_25 ) )
return - 1 ;
V_195 = 1.0 / ( 1 << ( V_25 & 0xF ) ) ;
V_196 = 1.0 / ( 1 << ( V_25 >> 8 & 0x1F ) ) ;
V_197 = 1.0 / ( 1 << ( V_25 >> 16 & 0xF ) ) ;
if ( V_195 != V_186 )
fprintf ( V_29 , L_150 , V_1 ) ;
if ( V_196 != V_94 )
fprintf ( V_29 , L_151 , V_1 ) ;
if ( V_197 != V_95 )
fprintf ( V_29 , L_152 , V_1 ) ;
if ( V_106 ) {
fprintf ( V_29 , L_153
L_154 , V_1 , V_25 ,
V_195 , V_196 , V_197 ) ;
}
if ( V_43 & V_44 ) {
if ( F_12 ( V_1 , V_187 , & V_25 ) )
return - 5 ;
fprintf ( V_29 , L_155 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_188 ) * V_186 ,
( ( V_25 >> 16 ) & V_188 ) * V_186 ,
( ( V_25 >> 32 ) & V_188 ) * V_186 ,
( ( V_25 >> 48 ) & V_198 ) * V_95 ) ;
if ( F_12 ( V_1 , V_199 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_156 ,
V_1 , V_25 , ( V_25 >> 63 ) & 1 ? L_98 : L_102 ) ;
F_62 ( V_1 , V_25 , L_157 ) ;
fprintf ( V_29 , L_158 ,
V_1 ,
( ( V_25 >> 47 ) & 1 ) ? L_148 : L_149 ,
( ( V_25 >> 32 ) & 0x7FFF ) * V_186 ,
( 1.0 + ( ( ( V_25 >> 54 ) & 0x3 ) / 4.0 ) ) * ( 1 << ( ( V_25 >> 49 ) & 0x1F ) ) * V_95 ,
( ( V_25 >> 48 ) & 1 ) ? L_148 : L_149 ) ;
}
if ( V_43 & V_47 ) {
if ( F_12 ( V_1 , V_200 , & V_25 ) )
return - 6 ;
fprintf ( V_29 , L_159 ,
V_1 , V_25 ,
( ( V_25 >> 0 ) & V_188 ) * V_186 ,
( ( V_25 >> 16 ) & V_188 ) * V_186 ,
( ( V_25 >> 32 ) & V_188 ) * V_186 ,
( ( V_25 >> 48 ) & V_198 ) * V_95 ) ;
if ( F_12 ( V_1 , V_201 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_160 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_98 : L_102 ) ;
F_62 ( V_1 , V_25 , L_161 ) ;
}
if ( V_43 & V_45 ) {
if ( V_106 ) {
if ( F_12 ( V_1 , V_202 , & V_25 ) )
return - 7 ;
fprintf ( V_29 , L_162 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_203 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_163 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_98 : L_102 ) ;
F_62 ( V_1 , V_25 , L_164 ) ;
}
}
if ( V_43 & V_46 ) {
if ( V_106 ) {
if ( F_12 ( V_1 , V_204 , & V_25 ) )
return - 8 ;
fprintf ( V_29 , L_165 , V_1 , V_25 & 0xF ) ;
if ( F_12 ( V_1 , V_205 , & V_25 ) )
return - 9 ;
fprintf ( V_29 , L_166 ,
V_1 , V_25 , ( V_25 >> 31 ) & 1 ? L_98 : L_102 ) ;
F_62 ( V_1 , V_25 , L_167 ) ;
}
}
return 0 ;
}
int F_64 ( unsigned int V_175 , unsigned int V_176 )
{
if ( ! V_177 )
return 0 ;
switch ( V_176 ) {
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
return 1 ;
}
return 0 ;
}
double F_65 ( unsigned int V_175 , unsigned int V_176 )
{
if ( F_64 ( V_175 , V_176 ) )
return 100.00 ;
else
return 133.33 ;
}
int F_66 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
unsigned long long V_25 ;
unsigned int V_206 ;
int V_1 ;
if ( ! ( V_41 || V_42 ) )
return 0 ;
if ( ! ( V_18 -> V_50 & V_80 ) || ! ( V_18 -> V_50 & V_82 ) )
return 0 ;
V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) ) {
fprintf ( V_29 , L_82 , V_1 ) ;
return - 1 ;
}
if ( V_207 != 0 ) {
V_119 = V_207 ;
fprintf ( V_29 , L_168 ,
V_1 , V_119 ) ;
return 0 ;
}
if ( ! V_132 )
goto V_208;
if ( F_12 ( 0 , V_209 , & V_25 ) )
goto V_208;
V_206 = ( V_25 >> 16 ) & 0x7F ;
if ( V_106 )
fprintf ( V_29 , L_169 ,
V_1 , V_25 , V_206 ) ;
if ( V_206 < 85 || V_206 > 120 )
goto V_208;
V_119 = V_206 ;
return 0 ;
V_208:
V_119 = V_210 ;
fprintf ( V_29 , L_170 ,
V_1 , V_119 ) ;
return 0 ;
}
void F_67 ()
{
unsigned int V_211 , V_212 , V_213 , V_214 , V_215 ;
unsigned int V_216 , V_175 , V_176 , V_217 ;
V_211 = V_212 = V_213 = V_214 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0));
if ( V_212 == 0x756e6547 && V_214 == 0x49656e69 && V_213 == 0x6c65746e )
V_177 = 1 ;
if ( V_106 )
fprintf ( V_29 , L_171 ,
( char * ) & V_212 , ( char * ) & V_214 , ( char * ) & V_213 ) ;
asm("cpuid" : "=a" (fms), "=c" (ecx), "=d" (edx) : "a" (1) : "ebx");
V_175 = ( V_216 >> 8 ) & 0xf ;
V_176 = ( V_216 >> 4 ) & 0xf ;
V_217 = V_216 & 0xf ;
if ( V_175 == 6 || V_175 == 0xf )
V_176 += ( ( V_216 >> 16 ) & 0xf ) << 4 ;
if ( V_106 )
fprintf ( V_29 , L_172 ,
V_215 , V_175 , V_176 , V_217 , V_175 , V_176 , V_217 ) ;
if ( ! ( V_214 & ( 1 << 5 ) ) ) {
fprintf ( V_29 , L_173 ) ;
exit ( 1 ) ;
}
V_212 = V_213 = V_214 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000000));
if ( V_215 < 0x80000007 ) {
fprintf ( V_29 , L_174 , V_215 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000007));
V_218 = V_214 & ( 1 << 8 ) ;
if ( ! V_218 ) {
fprintf ( V_29 , L_175 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x6));
V_35 = V_213 & ( 1 << 0 ) ;
V_41 = V_211 & ( 1 << 0 ) ;
V_42 = V_211 & ( 1 << 6 ) ;
V_179 = V_213 & ( 1 << 3 ) ;
if ( V_106 )
fprintf ( V_29 , L_176 ,
V_35 ? L_177 : L_178 ,
V_41 ? L_179 : L_98 ,
V_42 ? L_180 : L_98 ,
V_179 ? L_181 : L_98 ) ;
if ( ! V_35 )
exit ( - 1 ) ;
V_132 = V_177 && V_218 ;
V_34 = V_177 ;
V_40 = F_64 ( V_175 , V_176 ) ;
V_134 = F_65 ( V_175 , V_176 ) ;
V_141 = F_56 ( V_175 , V_176 ) ;
V_135 = F_57 ( V_175 , V_176 ) ;
F_59 ( V_175 , V_176 ) ;
return;
}
void F_68 ()
{
fprintf ( V_29 , L_182 ,
V_105 ) ;
exit ( 1 ) ;
}
int F_69 ( const struct V_219 * V_220 )
{
if ( isdigit ( V_220 -> V_221 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_70 ( int V_222 )
{
return 0 ;
}
void F_71 ()
{
int V_223 ;
int V_224 = 0 ;
int V_225 = 0 ;
int V_226 = 0 ;
struct V_227 {
int V_59 ;
int V_228 ;
} * V_229 ;
V_14 . V_99 = 0 ;
V_14 . V_164 = 0 ;
F_44 ( F_47 ) ;
if ( ! V_98 && V_14 . V_99 > 1 )
V_33 = 1 ;
if ( V_106 > 1 )
fprintf ( V_29 , L_183 , V_14 . V_99 , V_14 . V_164 ) ;
V_229 = calloc ( 1 , ( V_14 . V_164 + 1 ) * sizeof( struct V_227 ) ) ;
if ( V_229 == NULL ) {
perror ( L_184 ) ;
exit ( 1 ) ;
}
V_3 = F_72 ( ( V_14 . V_164 + 1 ) ) ;
if ( V_3 == NULL ) {
perror ( L_185 ) ;
exit ( 3 ) ;
}
V_2 = F_73 ( ( V_14 . V_164 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_44 ( F_48 ) ;
V_23 = F_72 ( ( V_14 . V_164 + 1 ) ) ;
if ( V_23 == NULL ) {
perror ( L_185 ) ;
exit ( 3 ) ;
}
V_22 = F_73 ( ( V_14 . V_164 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_223 = 0 ; V_223 <= V_14 . V_164 ; ++ V_223 ) {
int V_230 ;
if ( F_1 ( V_223 ) ) {
if ( V_106 > 1 )
fprintf ( V_29 , L_186 , V_223 ) ;
continue;
}
V_229 [ V_223 ] . V_59 = F_41 ( V_223 ) ;
if ( V_229 [ V_223 ] . V_59 > V_224 )
V_224 = V_229 [ V_223 ] . V_59 ;
V_229 [ V_223 ] . V_228 = F_40 ( V_223 ) ;
if ( V_229 [ V_223 ] . V_228 > V_225 )
V_225 = V_229 [ V_223 ] . V_228 ;
V_230 = F_42 ( V_223 ) ;
if ( V_230 > V_226 )
V_226 = V_230 ;
if ( V_106 > 1 )
fprintf ( V_29 , L_187 ,
V_223 , V_229 [ V_223 ] . V_228 , V_229 [ V_223 ] . V_59 ) ;
}
V_14 . V_16 = V_224 + 1 ;
if ( V_106 > 1 )
fprintf ( V_29 , L_188 ,
V_224 , V_14 . V_16 ) ;
if ( ! V_98 && V_14 . V_16 > 1 )
V_32 = 1 ;
V_14 . V_15 = V_225 + 1 ;
if ( V_106 > 1 )
fprintf ( V_29 , L_189 ,
V_225 , V_14 . V_15 ) ;
if ( ! V_98 && V_14 . V_15 > 1 )
V_30 = 1 ;
V_14 . V_17 = V_226 ;
if ( V_106 > 1 )
fprintf ( V_29 , L_190 , V_226 ) ;
free ( V_229 ) ;
}
void
F_74 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_223 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_223 = 0 ; V_223 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_223 ++ )
( * V_18 ) [ V_223 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_223 = 0 ; V_223 < V_14 . V_16 * V_14 . V_15 ; V_223 ++ )
( * V_19 ) [ V_223 ] . V_59 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_223 = 0 ; V_223 < V_14 . V_15 ; V_223 ++ )
( * V_20 ) [ V_223 ] . V_64 = V_223 ;
return;
error:
perror ( L_191 ) ;
exit ( 1 ) ;
}
void F_75 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_231 , int V_232 ,
int V_233 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_231 , V_232 , V_233 ) ;
V_19 = F_6 ( V_8 , V_232 , V_233 ) ;
V_20 = F_7 ( V_9 , V_233 ) ;
V_18 -> V_21 = V_21 ;
if ( V_231 == 0 ) {
V_18 -> V_50 |= V_80 ;
if ( F_39 ( V_21 ) )
V_18 -> V_50 |= V_82 ;
}
V_19 -> V_59 = V_232 ;
V_20 -> V_64 = V_233 ;
}
int F_76 ( int V_21 )
{
int V_234 , V_235 , V_236 ;
V_236 = F_40 ( V_21 ) ;
V_235 = F_41 ( V_21 ) ;
if ( F_38 ( V_21 ) ) {
V_234 = 0 ;
V_14 . V_110 ++ ;
} else {
V_234 = 1 ;
}
F_75 ( V_167 , V_234 , V_235 , V_236 , V_21 ) ;
F_75 ( V_171 , V_234 , V_235 , V_236 , V_21 ) ;
return 0 ;
}
void F_77 ()
{
V_96 = calloc ( 1 , ( 1 + V_14 . V_99 ) * 128 ) ;
V_31 = V_96 ;
if ( V_31 == NULL ) {
perror ( L_192 ) ;
exit ( - 1 ) ;
}
}
void F_46 ( void )
{
F_71 () ;
F_74 ( & V_143 , & V_144 , & V_145 ) ;
F_74 ( & V_146 , & V_147 , & V_148 ) ;
F_77 () ;
F_44 ( F_76 ) ;
}
void F_78 ()
{
F_67 () ;
F_53 () ;
F_54 () ;
F_46 () ;
if ( V_106 )
F_33 () ;
if ( V_106 )
F_3 ( F_58 , V_171 ) ;
if ( V_106 )
F_3 ( F_63 , V_171 ) ;
F_3 ( F_66 , V_171 ) ;
if ( V_106 )
F_3 ( F_60 , V_171 ) ;
}
int F_79 ( char * * V_237 )
{
T_4 V_238 ;
int V_239 ;
V_239 = F_3 ( F_32 , V_167 ) ;
if ( V_239 )
exit ( V_239 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_50 ( & V_168 , (struct V_169 * ) NULL ) ;
V_238 = F_80 () ;
if ( ! V_238 ) {
F_81 ( V_237 [ 0 ] , V_237 ) ;
} else {
if ( V_238 == - 1 ) {
perror ( L_193 ) ;
exit ( 1 ) ;
}
signal ( V_240 , V_241 ) ;
signal ( V_242 , V_241 ) ;
if ( F_82 ( V_238 , & V_239 , 0 ) == - 1 ) {
perror ( L_194 ) ;
exit ( V_239 ) ;
}
}
F_3 ( F_32 , V_171 ) ;
F_50 ( & V_172 , (struct V_169 * ) NULL ) ;
F_52 ( & V_172 , & V_168 , & V_83 ) ;
F_43 ( F_26 , V_171 , V_167 ) ;
F_30 ( V_167 ) ;
F_21 ( V_167 ) ;
F_20 () ;
fprintf ( V_29 , L_195 , V_83 . V_84 + V_83 . V_85 / 1000000.0 ) ;
return V_239 ;
}
void F_83 ( int V_243 , char * * V_237 )
{
int V_244 ;
V_105 = V_237 [ 0 ] ;
while ( ( V_244 = F_84 ( V_243 , V_237 , L_196 ) ) != - 1 ) {
switch ( V_244 ) {
case 'p' :
V_79 ++ ;
break;
case 'P' :
V_81 ++ ;
break;
case 'S' :
V_98 ++ ;
break;
case 'v' :
V_106 ++ ;
break;
case 'i' :
V_170 = atoi ( V_245 ) ;
break;
case 'c' :
sscanf ( V_245 , L_197 , & V_36 ) ;
break;
case 's' :
V_36 = 0x34 ;
break;
case 'C' :
sscanf ( V_245 , L_197 , & V_37 ) ;
break;
case 'm' :
sscanf ( V_245 , L_197 , & V_38 ) ;
break;
case 'M' :
sscanf ( V_245 , L_197 , & V_39 ) ;
break;
case 'R' :
V_246 ++ ;
break;
case 'T' :
V_207 = atoi ( V_245 ) ;
break;
default:
F_68 () ;
}
}
}
int main ( int V_243 , char * * V_237 )
{
F_83 ( V_243 , V_237 ) ;
if ( V_106 )
fprintf ( V_29 , L_198
L_199 ) ;
F_78 () ;
if ( V_243 - V_247 )
return F_79 ( V_237 + V_247 ) ;
else
F_49 () ;
return 0 ;
}
