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
if ( V_40 )
V_31 += sprintf ( V_31 , L_18 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_19 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_20 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_21 ) ;
V_31 += sprintf ( V_31 , L_22 ) ;
}
int F_17 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
fprintf ( V_29 , L_23 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
fprintf ( V_29 , L_24 , V_18 -> V_21 , V_18 -> V_41 ) ;
fprintf ( V_29 , L_25 , V_18 -> V_42 ) ;
fprintf ( V_29 , L_26 , V_18 -> V_43 ) ;
fprintf ( V_29 , L_27 , V_18 -> V_44 ) ;
fprintf ( V_29 , L_28 , V_18 -> V_45 ) ;
fprintf ( V_29 , L_29 ,
V_36 , V_18 -> V_46 ) ;
fprintf ( V_29 , L_30 ,
V_37 , V_18 -> V_47 ) ;
fprintf ( V_29 , L_29 ,
V_38 , V_18 -> V_48 ) ;
fprintf ( V_29 , L_30 ,
V_39 , V_18 -> V_49 ) ;
}
if ( V_19 ) {
fprintf ( V_29 , L_31 , V_19 -> V_50 ) ;
fprintf ( V_29 , L_32 , V_19 -> V_51 ) ;
fprintf ( V_29 , L_33 , V_19 -> V_52 ) ;
fprintf ( V_29 , L_34 , V_19 -> V_53 ) ;
}
if ( V_20 ) {
fprintf ( V_29 , L_35 , V_20 -> V_54 ) ;
fprintf ( V_29 , L_36 , V_20 -> V_55 ) ;
fprintf ( V_29 , L_37 , V_20 -> V_56 ) ;
fprintf ( V_29 , L_38 , V_20 -> V_57 ) ;
fprintf ( V_29 , L_39 , V_20 -> V_58 ) ;
}
return 0 ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_59 ;
if ( V_60 && ! ( V_18 -> V_41 & V_61 ) )
return 0 ;
if ( V_62 && ! ( V_18 -> V_41 & V_63 ) )
return 0 ;
V_59 = V_64 . V_65 + V_64 . V_66 / 1000000.0 ;
if ( V_18 == & V_67 . V_68 ) {
if ( V_30 )
V_31 += sprintf ( V_31 , L_40 ) ;
if ( V_30 && V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 )
V_31 += sprintf ( V_31 , L_41 ) ;
if ( V_33 )
V_31 += sprintf ( V_31 , L_4 L_41 ) ;
} else {
if ( V_30 ) {
if ( V_20 )
V_31 += sprintf ( V_31 , L_42 , V_20 -> V_54 ) ;
else
V_31 += sprintf ( V_31 , L_40 ) ;
}
if ( V_30 && V_32 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( V_32 ) {
if ( V_19 )
V_31 += sprintf ( V_31 , L_43 , V_19 -> V_50 ) ;
else
V_31 += sprintf ( V_31 , L_41 ) ;
}
if ( V_33 )
V_31 += sprintf ( V_31 , L_44 , V_18 -> V_21 ) ;
}
if ( V_34 ) {
if ( V_30 || V_32 || V_33 )
V_31 += sprintf ( V_31 , L_4 ) ;
if ( ! V_69 )
V_31 += sprintf ( V_31 , L_45 , 100.0 * V_18 -> V_44 / V_18 -> V_42 ) ;
else
V_31 += sprintf ( V_31 , L_46 ) ;
}
if ( V_35 ) {
if ( ! V_70 ) {
V_31 += sprintf ( V_31 , L_47 ,
1.0 * V_18 -> V_42 / V_71 * V_18 -> V_43 /
V_18 -> V_44 / V_59 ) ;
} else {
if ( V_18 -> V_43 > V_18 -> V_42 || V_18 -> V_44 > V_18 -> V_42 ) {
V_31 += sprintf ( V_31 , L_48 ) ;
} else {
V_31 += sprintf ( V_31 , L_49 ,
1.0 * V_18 -> V_42 /
V_71 * V_18 -> V_43 /
V_18 -> V_44 / V_59 ) ;
}
}
}
V_31 += sprintf ( V_31 , L_50 , 1.0 * V_18 -> V_42 / V_71 / V_59 ) ;
if ( V_36 )
V_31 += sprintf ( V_31 , L_51 , V_18 -> V_46 ) ;
if ( V_37 )
V_31 += sprintf ( V_31 , L_51 , V_18 -> V_47 ) ;
if ( V_38 )
V_31 += sprintf ( V_31 , L_52 , V_18 -> V_48 ) ;
if ( V_39 )
V_31 += sprintf ( V_31 , L_53 , V_18 -> V_49 ) ;
if ( V_34 ) {
if ( ! V_72 )
V_31 += sprintf ( V_31 , L_54 , 100.0 * V_18 -> V_45 / V_18 -> V_42 ) ;
else
V_31 += sprintf ( V_31 , L_46 ) ;
}
if ( ! ( V_18 -> V_41 & V_61 ) )
goto V_73;
if ( V_34 )
V_31 += sprintf ( V_31 , L_54 , 100.0 * V_19 -> V_51 / V_18 -> V_42 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_54 , 100.0 * V_19 -> V_52 / V_18 -> V_42 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_54 , 100.0 * V_19 -> V_53 / V_18 -> V_42 ) ;
if ( ! ( V_18 -> V_41 & V_63 ) )
goto V_73;
if ( V_40 )
V_31 += sprintf ( V_31 , L_54 , 100.0 * V_20 -> V_55 / V_18 -> V_42 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_54 , 100.0 * V_20 -> V_56 / V_18 -> V_42 ) ;
if ( V_34 )
V_31 += sprintf ( V_31 , L_54 , 100.0 * V_20 -> V_57 / V_18 -> V_42 ) ;
if ( V_40 )
V_31 += sprintf ( V_31 , L_54 , 100.0 * V_20 -> V_58 / V_18 -> V_42 ) ;
V_73:
V_31 += sprintf ( V_31 , L_22 ) ;
return 0 ;
}
void F_19 ()
{
fputs ( V_74 , stdout ) ;
V_31 = V_74 ;
}
void F_20 ()
{
fputs ( V_74 , V_29 ) ;
V_31 = V_74 ;
}
void F_21 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_75 ;
if ( ! V_75 || ! V_76 )
F_16 () ;
if ( V_14 . V_77 > 1 )
F_18 ( & V_67 . V_68 , & V_67 . V_78 ,
& V_67 . V_79 ) ;
V_75 = 1 ;
if ( V_76 )
return;
F_3 ( F_18 , V_18 , V_19 , V_20 ) ;
}
void
F_22 ( struct V_6 * V_80 , struct V_6 * V_81 )
{
V_81 -> V_55 = V_80 -> V_55 - V_81 -> V_55 ;
V_81 -> V_56 = V_80 -> V_56 - V_81 -> V_56 ;
V_81 -> V_57 = V_80 -> V_57 - V_81 -> V_57 ;
V_81 -> V_58 = V_80 -> V_58 - V_81 -> V_58 ;
}
void
F_23 ( struct V_5 * V_80 , struct V_5 * V_81 )
{
V_81 -> V_51 = V_80 -> V_51 - V_81 -> V_51 ;
V_81 -> V_52 = V_80 -> V_52 - V_81 -> V_52 ;
V_81 -> V_53 = V_80 -> V_53 - V_81 -> V_53 ;
}
void
F_24 ( struct V_4 * V_80 , struct V_4 * V_81 ,
struct V_5 * V_82 )
{
V_81 -> V_42 = V_80 -> V_42 - V_81 -> V_42 ;
if ( V_81 -> V_42 < ( 1000 * 1000 ) ) {
fprintf ( V_29 , L_55 ) ;
fprintf ( V_29 , L_56 ) ;
fprintf ( V_29 , L_57 ) ;
exit ( - 3 ) ;
}
V_81 -> V_45 = V_80 -> V_45 - V_81 -> V_45 ;
if ( ( V_80 -> V_43 > V_81 -> V_43 ) && ( V_80 -> V_44 > V_81 -> V_44 ) ) {
V_81 -> V_43 = V_80 -> V_43 - V_81 -> V_43 ;
V_81 -> V_44 = V_80 -> V_44 - V_81 -> V_44 ;
} else {
if ( ! V_70 ) {
fprintf ( V_29 , L_58 , V_83 ) ;
fprintf ( V_29 , L_59 ) ;
fprintf ( V_29 , L_60 ) ;
V_70 = 1 ;
}
V_69 = 1 ;
V_72 = 1 ;
}
if ( ( V_81 -> V_44 + V_82 -> V_51 + V_82 -> V_52 + V_82 -> V_53 ) > V_81 -> V_42 )
V_81 -> V_45 = 0 ;
else {
V_81 -> V_45 = V_81 -> V_42 - V_81 -> V_44 - V_82 -> V_51
- V_82 -> V_52 - V_82 -> V_53 ;
}
if ( V_81 -> V_44 == 0 ) {
if ( V_84 > 1 ) fprintf ( V_29 , L_61 , V_81 -> V_21 ) ;
V_81 -> V_44 = 1 ;
}
V_81 -> V_46 = V_80 -> V_46 - V_81 -> V_46 ;
V_81 -> V_46 &= 0xFFFFFFFF ;
V_81 -> V_47 = V_80 -> V_47 - V_81 -> V_47 ;
V_81 -> V_48 = V_80 -> V_48 ;
V_81 -> V_49 = V_80 -> V_49 ;
}
int F_25 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_85 ,
struct V_5 * V_86 , struct V_6 * V_87 )
{
if ( V_18 -> V_41 & V_61 )
F_23 ( V_19 , V_86 ) ;
F_24 ( V_18 , V_85 , V_86 ) ;
if ( V_18 -> V_41 & V_63 )
F_22 ( V_20 , V_87 ) ;
return 0 ;
}
void F_26 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
V_18 -> V_42 = 0 ;
V_18 -> V_43 = 0 ;
V_18 -> V_44 = 0 ;
V_18 -> V_45 = 0 ;
V_18 -> V_46 = 0 ;
V_18 -> V_47 = 0 ;
V_18 -> V_41 = V_61 | V_63 ;
V_19 -> V_51 = 0 ;
V_19 -> V_52 = 0 ;
V_19 -> V_53 = 0 ;
V_20 -> V_55 = 0 ;
V_20 -> V_56 = 0 ;
V_20 -> V_57 = 0 ;
V_20 -> V_58 = 0 ;
}
int F_27 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_67 . V_68 . V_42 += V_18 -> V_42 ;
V_67 . V_68 . V_43 += V_18 -> V_43 ;
V_67 . V_68 . V_44 += V_18 -> V_44 ;
V_67 . V_68 . V_45 += V_18 -> V_45 ;
V_67 . V_68 . V_46 += V_18 -> V_46 ;
V_67 . V_68 . V_47 += V_18 -> V_47 ;
if ( ! ( V_18 -> V_41 & V_61 ) )
return 0 ;
V_67 . V_78 . V_51 += V_19 -> V_51 ;
V_67 . V_78 . V_52 += V_19 -> V_52 ;
V_67 . V_78 . V_53 += V_19 -> V_53 ;
if ( ! ( V_18 -> V_41 & V_63 ) )
return 0 ;
V_67 . V_79 . V_55 += V_20 -> V_55 ;
V_67 . V_79 . V_56 += V_20 -> V_56 ;
V_67 . V_79 . V_57 += V_20 -> V_57 ;
V_67 . V_79 . V_58 += V_20 -> V_58 ;
return 0 ;
}
void F_28 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_26 ( & V_67 . V_68 , & V_67 . V_78 , & V_67 . V_79 ) ;
F_3 ( F_27 , V_18 , V_19 , V_20 ) ;
V_67 . V_68 . V_42 /= V_14 . V_77 ;
V_67 . V_68 . V_43 /= V_14 . V_77 ;
V_67 . V_68 . V_44 /= V_14 . V_77 ;
V_67 . V_68 . V_45 /= V_14 . V_77 ;
V_67 . V_68 . V_46 /= V_14 . V_77 ;
V_67 . V_68 . V_46 &= 0xFFFFFFFF ;
V_67 . V_68 . V_47 /= V_14 . V_77 ;
V_67 . V_78 . V_51 /= V_14 . V_88 ;
V_67 . V_78 . V_52 /= V_14 . V_88 ;
V_67 . V_78 . V_53 /= V_14 . V_88 ;
V_67 . V_79 . V_55 /= V_14 . V_15 ;
V_67 . V_79 . V_56 /= V_14 . V_15 ;
V_67 . V_79 . V_57 /= V_14 . V_15 ;
V_67 . V_79 . V_58 /= V_14 . V_15 ;
}
static unsigned long long F_29 ( void )
{
unsigned int V_89 , V_90 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_89 | ( ( unsigned long long ) V_90 ) << 32 ;
}
int F_30 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) )
return - 1 ;
V_18 -> V_42 = F_29 () ;
if ( V_35 ) {
if ( F_12 ( V_1 , V_91 , & V_18 -> V_43 ) )
return - 3 ;
if ( F_12 ( V_1 , V_92 , & V_18 -> V_44 ) )
return - 4 ;
}
if ( V_36 ) {
if ( F_12 ( V_1 , V_36 , & V_18 -> V_46 ) )
return - 5 ;
V_18 -> V_46 &= 0xFFFFFFFF ;
}
if ( V_37 )
if ( F_12 ( V_1 , V_37 , & V_18 -> V_47 ) )
return - 5 ;
if ( V_38 ) {
if ( F_12 ( V_1 , V_38 , & V_18 -> V_48 ) )
return - 5 ;
V_18 -> V_48 &= 0xFFFFFFFF ;
}
if ( V_39 )
if ( F_12 ( V_1 , V_39 , & V_18 -> V_49 ) )
return - 5 ;
if ( ! ( V_18 -> V_41 & V_61 ) )
return 0 ;
if ( V_34 ) {
if ( F_12 ( V_1 , V_93 , & V_19 -> V_51 ) )
return - 6 ;
if ( F_12 ( V_1 , V_94 , & V_19 -> V_52 ) )
return - 7 ;
}
if ( V_40 )
if ( F_12 ( V_1 , V_95 , & V_19 -> V_53 ) )
return - 8 ;
if ( ! ( V_18 -> V_41 & V_63 ) )
return 0 ;
if ( V_34 ) {
if ( F_12 ( V_1 , V_96 , & V_20 -> V_56 ) )
return - 9 ;
if ( F_12 ( V_1 , V_97 , & V_20 -> V_57 ) )
return - 10 ;
}
if ( V_40 ) {
if ( F_12 ( V_1 , V_98 , & V_20 -> V_55 ) )
return - 11 ;
if ( F_12 ( V_1 , V_99 , & V_20 -> V_58 ) )
return - 12 ;
}
return 0 ;
}
void F_31 ( void )
{
unsigned long long V_25 ;
unsigned int V_100 ;
if ( ! V_101 )
return;
F_12 ( 0 , V_102 , & V_25 ) ;
if ( V_84 > 1 )
fprintf ( V_29 , L_62 , V_25 ) ;
V_100 = ( V_25 >> 40 ) & 0xFF ;
fprintf ( V_29 , L_63 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 8 ) & 0xFF ;
fprintf ( V_29 , L_64 ,
V_100 , V_103 , V_100 * V_103 ) ;
if ( ! V_104 )
goto V_105;
F_12 ( 0 , V_106 , & V_25 ) ;
if ( V_84 > 1 )
fprintf ( V_29 , L_65 , V_25 ) ;
V_100 = ( V_25 >> 56 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_66 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 48 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_67 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 40 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_68 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 32 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_69 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 24 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_70 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 16 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_71 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 8 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_72 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 0 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_73 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_105:
if ( ! V_107 )
return;
F_12 ( 0 , V_108 , & V_25 ) ;
if ( V_84 > 1 )
fprintf ( V_29 , L_74 , V_25 ) ;
V_100 = ( V_25 >> 56 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_75 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 48 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_76 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 40 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_77 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 32 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_78 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 24 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_79 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 16 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_80 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 8 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_81 ,
V_100 , V_103 , V_100 * V_103 ) ;
V_100 = ( V_25 >> 0 ) & 0xFF ;
if ( V_100 )
fprintf ( V_29 , L_82 ,
V_100 , V_103 , V_100 * V_103 ) ;
}
void F_32 ( void )
{
F_33 ( V_3 ) ;
V_3 = NULL ;
V_3 = 0 ;
F_33 ( V_23 ) ;
V_23 = NULL ;
V_22 = 0 ;
free ( V_109 ) ;
free ( V_110 ) ;
free ( V_111 ) ;
V_109 = NULL ;
V_110 = NULL ;
V_111 = NULL ;
free ( V_112 ) ;
free ( V_113 ) ;
free ( V_114 ) ;
V_112 = NULL ;
V_113 = NULL ;
V_114 = NULL ;
free ( V_74 ) ;
V_74 = NULL ;
V_31 = NULL ;
}
int F_34 ( int V_1 )
{
char V_115 [ 64 ] ;
T_3 * V_116 ;
int V_117 ;
sprintf ( V_115 , L_83 , V_1 ) ;
V_116 = fopen ( V_115 , L_84 ) ;
if ( V_116 == NULL ) {
perror ( V_115 ) ;
exit ( 1 ) ;
}
fscanf ( V_116 , L_85 , & V_117 ) ;
fclose ( V_116 ) ;
return ( V_1 == V_117 ) ;
}
int F_35 ( int V_1 )
{
char V_115 [ 64 ] ;
T_3 * V_116 ;
int V_117 ;
sprintf ( V_115 , L_86 , V_1 ) ;
V_116 = fopen ( V_115 , L_84 ) ;
if ( V_116 == NULL ) {
perror ( V_115 ) ;
exit ( 1 ) ;
}
fscanf ( V_116 , L_85 , & V_117 ) ;
fclose ( V_116 ) ;
return ( V_1 == V_117 ) ;
}
int F_36 ( int V_1 )
{
char V_115 [ 80 ] ;
T_3 * V_116 ;
int V_118 ;
sprintf ( V_115 , L_87 , V_1 ) ;
V_116 = fopen ( V_115 , L_84 ) ;
if ( V_116 == NULL ) {
perror ( V_115 ) ;
exit ( 1 ) ;
}
fscanf ( V_116 , L_85 , & V_118 ) ;
fclose ( V_116 ) ;
return V_118 ;
}
int F_37 ( int V_1 )
{
char V_115 [ 80 ] ;
T_3 * V_116 ;
int V_119 ;
sprintf ( V_115 , L_88 , V_1 ) ;
V_116 = fopen ( V_115 , L_84 ) ;
if ( V_116 == NULL ) {
perror ( V_115 ) ;
exit ( 1 ) ;
}
fscanf ( V_116 , L_85 , & V_119 ) ;
fclose ( V_116 ) ;
return V_119 ;
}
int F_38 ( int V_1 )
{
char V_115 [ 80 ] ;
T_3 * V_116 ;
int V_120 , V_121 ;
int V_122 ;
char V_123 ;
sprintf ( V_115 , L_83 , V_1 ) ;
V_116 = fopen ( V_115 , L_84 ) ;
if ( V_116 == NULL ) {
perror ( V_115 ) ;
exit ( 1 ) ;
}
V_122 = fscanf ( V_116 , L_89 , & V_120 , & V_123 , & V_121 ) ;
fclose ( V_116 ) ;
if ( V_122 == 3 )
return 2 ;
else
return 1 ;
}
int F_39 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_124 , struct V_5 * V_125 ,
struct V_6 * V_126 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_85 ;
struct V_5 * V_19 , * V_86 ;
struct V_6 * V_20 , * V_87 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_85 = F_5 ( V_124 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_86 = F_6 ( V_125 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_87 = F_7 ( V_126 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_85 , V_86 , V_87 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_40 ( int (F_4)( int ) )
{
T_3 * V_127 ;
int V_128 ;
int V_10 ;
V_127 = fopen ( V_129 , L_84 ) ;
if ( V_127 == NULL ) {
perror ( V_129 ) ;
exit ( 1 ) ;
}
V_10 = fscanf ( V_127 , L_90 ) ;
if ( V_10 != 0 ) {
perror ( L_91 ) ;
exit ( 1 ) ;
}
while ( 1 ) {
V_10 = fscanf ( V_127 , L_92 , & V_128 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_128 ) ;
if ( V_10 ) {
fclose ( V_127 ) ;
return ( V_10 ) ;
}
}
fclose ( V_127 ) ;
return 0 ;
}
void F_41 ( void )
{
F_32 () ;
F_42 () ;
printf ( L_93 , V_14 . V_77 ) ;
}
int F_43 ( int V_1 )
{
if ( V_14 . V_130 < V_1 )
V_14 . V_130 = V_1 ;
V_14 . V_77 += 1 ;
return 0 ;
}
int F_44 ( int V_1 )
{
F_10 ( V_1 , V_2 , V_3 ) ;
return 0 ;
}
void F_45 ()
{
int V_10 ;
V_131:
V_10 = F_3 ( F_30 , V_132 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_41 () ;
goto V_131;
}
F_46 ( & V_133 , (struct V_134 * ) NULL ) ;
while ( 1 ) {
if ( F_40 ( F_1 ) ) {
F_41 () ;
goto V_131;
}
F_47 ( V_135 ) ;
V_10 = F_3 ( F_30 , V_136 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_41 () ;
goto V_131;
}
F_46 ( & V_137 , (struct V_134 * ) NULL ) ;
F_48 ( & V_137 , & V_133 , & V_64 ) ;
F_39 ( F_25 , V_136 , V_132 ) ;
F_28 ( V_132 ) ;
F_21 ( V_132 ) ;
F_19 () ;
F_47 ( V_135 ) ;
V_10 = F_3 ( F_30 , V_132 ) ;
if ( V_10 < - 1 ) {
exit ( V_10 ) ;
} else if ( V_10 == - 1 ) {
F_41 () ;
goto V_131;
}
F_46 ( & V_133 , (struct V_134 * ) NULL ) ;
F_48 ( & V_133 , & V_137 , & V_64 ) ;
F_39 ( F_25 , V_132 , V_136 ) ;
F_28 ( V_136 ) ;
F_21 ( V_136 ) ;
F_19 () ;
}
}
void F_49 ()
{
struct V_138 V_139 ;
if ( V_138 ( L_94 , & V_139 ) ) {
fprintf ( V_29 , L_95 ) ;
fprintf ( V_29 , L_96 ) ;
exit ( - 5 ) ;
}
}
void F_50 ()
{
if ( F_51 () != 0 ) {
fprintf ( V_29 , L_97 ) ;
exit ( - 6 ) ;
}
}
int F_52 ( unsigned int V_140 , unsigned int V_141 )
{
if ( ! V_142 )
return 0 ;
if ( V_140 != 6 )
return 0 ;
switch ( V_141 ) {
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
int F_53 ( unsigned int V_140 , unsigned int V_141 )
{
if ( ! V_142 )
return 0 ;
if ( V_140 != 6 )
return 0 ;
switch ( V_141 ) {
case 0x3E :
return 1 ;
default:
return 0 ;
}
}
int F_54 ( unsigned int V_140 , unsigned int V_141 )
{
if ( ! V_142 )
return 0 ;
switch ( V_141 ) {
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
return 1 ;
}
return 0 ;
}
double F_55 ( unsigned int V_140 , unsigned int V_141 )
{
if ( F_54 ( V_140 , V_141 ) )
return 100.00 ;
else
return 133.33 ;
}
void F_56 ()
{
unsigned int V_143 , V_144 , V_145 , V_146 , V_147 ;
unsigned int V_148 , V_140 , V_141 , V_149 ;
V_143 = V_144 = V_145 = V_146 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0));
if ( V_144 == 0x756e6547 && V_146 == 0x49656e69 && V_145 == 0x6c65746e )
V_142 = 1 ;
if ( V_84 )
fprintf ( V_29 , L_98 ,
( char * ) & V_144 , ( char * ) & V_146 , ( char * ) & V_145 ) ;
asm("cpuid" : "=a" (fms), "=c" (ecx), "=d" (edx) : "a" (1) : "ebx");
V_140 = ( V_148 >> 8 ) & 0xf ;
V_141 = ( V_148 >> 4 ) & 0xf ;
V_149 = V_148 & 0xf ;
if ( V_140 == 6 || V_140 == 0xf )
V_141 += ( ( V_148 >> 16 ) & 0xf ) << 4 ;
if ( V_84 )
fprintf ( V_29 , L_99 ,
V_147 , V_140 , V_141 , V_149 , V_140 , V_141 , V_149 ) ;
if ( ! ( V_146 & ( 1 << 5 ) ) ) {
fprintf ( V_29 , L_100 ) ;
exit ( 1 ) ;
}
V_144 = V_145 = V_146 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000000));
if ( V_147 < 0x80000007 ) {
fprintf ( V_29 , L_101 , V_147 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000007));
V_150 = V_146 & ( 1 << 8 ) ;
if ( ! V_150 ) {
fprintf ( V_29 , L_102 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x6));
V_35 = V_145 & ( 1 << 0 ) ;
if ( ! V_35 ) {
fprintf ( V_29 , L_103 ) ;
exit ( 1 ) ;
}
V_101 = V_142 && V_150 ;
V_34 = V_142 ;
V_40 = F_54 ( V_140 , V_141 ) ;
V_103 = F_55 ( V_140 , V_141 ) ;
V_107 = F_52 ( V_140 , V_141 ) ;
V_104 = F_53 ( V_140 , V_141 ) ;
}
void F_57 ()
{
fprintf ( V_29 , L_104 ,
V_83 ) ;
exit ( 1 ) ;
}
int F_58 ( const struct V_151 * V_152 )
{
if ( isdigit ( V_152 -> V_153 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_59 ( int V_154 )
{
return 0 ;
}
void F_60 ()
{
int V_155 ;
int V_156 = 0 ;
int V_157 = 0 ;
int V_158 = 0 ;
struct V_159 {
int V_50 ;
int V_160 ;
} * V_161 ;
V_14 . V_77 = 0 ;
V_14 . V_130 = 0 ;
F_40 ( F_43 ) ;
if ( ! V_76 && V_14 . V_77 > 1 )
V_33 = 1 ;
if ( V_84 > 1 )
fprintf ( V_29 , L_105 , V_14 . V_77 , V_14 . V_130 ) ;
V_161 = calloc ( 1 , ( V_14 . V_130 + 1 ) * sizeof( struct V_159 ) ) ;
if ( V_161 == NULL ) {
perror ( L_106 ) ;
exit ( 1 ) ;
}
V_3 = F_61 ( ( V_14 . V_130 + 1 ) ) ;
if ( V_3 == NULL ) {
perror ( L_107 ) ;
exit ( 3 ) ;
}
V_2 = F_62 ( ( V_14 . V_130 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_40 ( F_44 ) ;
V_23 = F_61 ( ( V_14 . V_130 + 1 ) ) ;
if ( V_23 == NULL ) {
perror ( L_107 ) ;
exit ( 3 ) ;
}
V_22 = F_62 ( ( V_14 . V_130 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_155 = 0 ; V_155 <= V_14 . V_130 ; ++ V_155 ) {
int V_162 ;
if ( F_1 ( V_155 ) ) {
if ( V_84 > 1 )
fprintf ( V_29 , L_108 , V_155 ) ;
continue;
}
V_161 [ V_155 ] . V_50 = F_37 ( V_155 ) ;
if ( V_161 [ V_155 ] . V_50 > V_156 )
V_156 = V_161 [ V_155 ] . V_50 ;
V_161 [ V_155 ] . V_160 = F_36 ( V_155 ) ;
if ( V_161 [ V_155 ] . V_160 > V_157 )
V_157 = V_161 [ V_155 ] . V_160 ;
V_162 = F_38 ( V_155 ) ;
if ( V_162 > V_158 )
V_158 = V_162 ;
if ( V_84 > 1 )
fprintf ( V_29 , L_109 ,
V_155 , V_161 [ V_155 ] . V_160 , V_161 [ V_155 ] . V_50 ) ;
}
V_14 . V_16 = V_156 + 1 ;
if ( V_84 > 1 )
fprintf ( V_29 , L_110 ,
V_156 , V_14 . V_16 ) ;
if ( ! V_76 && V_14 . V_16 > 1 )
V_32 = 1 ;
V_14 . V_15 = V_157 + 1 ;
if ( V_84 > 1 )
fprintf ( V_29 , L_111 ,
V_157 , V_14 . V_15 ) ;
if ( ! V_76 && V_14 . V_15 > 1 )
V_30 = 1 ;
V_14 . V_17 = V_158 ;
if ( V_84 > 1 )
fprintf ( V_29 , L_112 , V_158 ) ;
free ( V_161 ) ;
}
void
F_63 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_155 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_155 = 0 ; V_155 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_155 ++ )
( * V_18 ) [ V_155 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_155 = 0 ; V_155 < V_14 . V_16 * V_14 . V_15 ; V_155 ++ )
( * V_19 ) [ V_155 ] . V_50 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_155 = 0 ; V_155 < V_14 . V_15 ; V_155 ++ )
( * V_20 ) [ V_155 ] . V_54 = V_155 ;
return;
error:
perror ( L_113 ) ;
exit ( 1 ) ;
}
void F_64 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_163 , int V_164 ,
int V_165 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_163 , V_164 , V_165 ) ;
V_19 = F_6 ( V_8 , V_164 , V_165 ) ;
V_20 = F_7 ( V_9 , V_165 ) ;
V_18 -> V_21 = V_21 ;
if ( V_163 == 0 ) {
V_18 -> V_41 |= V_61 ;
if ( F_35 ( V_21 ) )
V_18 -> V_41 |= V_63 ;
}
V_19 -> V_50 = V_164 ;
V_20 -> V_54 = V_165 ;
}
int F_65 ( int V_21 )
{
int V_166 , V_167 , V_168 ;
V_168 = F_36 ( V_21 ) ;
V_167 = F_37 ( V_21 ) ;
if ( F_34 ( V_21 ) ) {
V_166 = 0 ;
V_14 . V_88 ++ ;
} else {
V_166 = 1 ;
}
F_64 ( V_132 , V_166 , V_167 , V_168 , V_21 ) ;
F_64 ( V_136 , V_166 , V_167 , V_168 , V_21 ) ;
return 0 ;
}
void F_66 ()
{
V_74 = calloc ( 1 , ( 1 + V_14 . V_77 ) * 128 ) ;
V_31 = V_74 ;
if ( V_31 == NULL ) {
perror ( L_114 ) ;
exit ( - 1 ) ;
}
}
void F_42 ( void )
{
F_60 () ;
F_63 ( & V_109 , & V_110 , & V_111 ) ;
F_63 ( & V_112 , & V_113 , & V_114 ) ;
F_66 () ;
F_40 ( F_65 ) ;
}
void F_67 ()
{
F_56 () ;
F_49 () ;
F_50 () ;
F_42 () ;
if ( V_84 )
F_31 () ;
}
int F_68 ( char * * V_169 )
{
T_4 V_170 ;
int V_171 ;
V_171 = F_3 ( F_30 , V_132 ) ;
if ( V_171 )
exit ( V_171 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_46 ( & V_133 , (struct V_134 * ) NULL ) ;
V_170 = F_69 () ;
if ( ! V_170 ) {
F_70 ( V_169 [ 0 ] , V_169 ) ;
} else {
if ( V_170 == - 1 ) {
perror ( L_115 ) ;
exit ( 1 ) ;
}
signal ( V_172 , V_173 ) ;
signal ( V_174 , V_173 ) ;
if ( F_71 ( V_170 , & V_171 , 0 ) == - 1 ) {
perror ( L_116 ) ;
exit ( V_171 ) ;
}
}
F_3 ( F_30 , V_136 ) ;
F_46 ( & V_137 , (struct V_134 * ) NULL ) ;
F_48 ( & V_137 , & V_133 , & V_64 ) ;
F_39 ( F_25 , V_136 , V_132 ) ;
F_28 ( V_132 ) ;
F_21 ( V_132 ) ;
F_20 () ;
fprintf ( V_29 , L_117 , V_64 . V_65 + V_64 . V_66 / 1000000.0 ) ;
return V_171 ;
}
void F_72 ( int V_175 , char * * V_169 )
{
int V_176 ;
V_83 = V_169 [ 0 ] ;
while ( ( V_176 = F_73 ( V_175 , V_169 , L_118 ) ) != - 1 ) {
switch ( V_176 ) {
case 'p' :
V_60 ++ ;
break;
case 'P' :
V_62 ++ ;
break;
case 'S' :
V_76 ++ ;
break;
case 'v' :
V_84 ++ ;
break;
case 'i' :
V_135 = atoi ( V_177 ) ;
break;
case 'c' :
sscanf ( V_177 , L_119 , & V_36 ) ;
break;
case 's' :
V_36 = 0x34 ;
break;
case 'C' :
sscanf ( V_177 , L_119 , & V_37 ) ;
break;
case 'm' :
sscanf ( V_177 , L_119 , & V_38 ) ;
break;
case 'M' :
sscanf ( V_177 , L_119 , & V_39 ) ;
break;
default:
F_57 () ;
}
}
}
int main ( int V_175 , char * * V_169 )
{
F_72 ( V_175 , V_169 ) ;
if ( V_84 > 1 )
fprintf ( V_29 , L_120
L_121 ) ;
F_67 () ;
if ( V_175 - V_178 )
return F_68 ( V_169 + V_178 ) ;
else
F_45 () ;
return 0 ;
}
