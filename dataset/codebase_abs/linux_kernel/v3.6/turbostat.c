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
if ( V_10 != sizeof *V_25 )
return - 1 ;
return 0 ;
}
void F_16 ( void )
{
if ( V_29 )
V_30 += sprintf ( V_30 , L_2 ) ;
if ( V_29 )
V_30 += sprintf ( V_30 , L_3 ) ;
if ( V_31 )
V_30 += sprintf ( V_30 , L_4 ) ;
if ( V_32 )
V_30 += sprintf ( V_30 , L_5 ) ;
if ( V_29 || V_31 || V_32 )
V_30 += sprintf ( V_30 , L_3 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_6 ) ;
if ( V_34 )
V_30 += sprintf ( V_30 , L_7 ) ;
V_30 += sprintf ( V_30 , L_8 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_9 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_10 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_11 ) ;
if ( V_35 )
V_30 += sprintf ( V_30 , L_12 ) ;
if ( V_35 )
V_30 += sprintf ( V_30 , L_13 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_14 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_15 ) ;
if ( V_35 )
V_30 += sprintf ( V_30 , L_16 ) ;
if ( V_36 )
V_30 += sprintf ( V_30 , L_17 , V_36 ) ;
V_30 += sprintf ( V_30 , L_18 ) ;
}
int F_17 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
fprintf ( V_37 , L_19 , V_18 , V_19 , V_20 ) ;
if ( V_18 ) {
fprintf ( V_37 , L_20 , V_18 -> V_21 , V_18 -> V_38 ) ;
fprintf ( V_37 , L_21 , V_18 -> V_39 ) ;
fprintf ( V_37 , L_22 , V_18 -> V_40 ) ;
fprintf ( V_37 , L_23 , V_18 -> V_41 ) ;
fprintf ( V_37 , L_24 , V_18 -> V_42 ) ;
fprintf ( V_37 , L_25 ,
V_36 , V_18 -> V_43 ) ;
}
if ( V_19 ) {
fprintf ( V_37 , L_26 , V_19 -> V_44 ) ;
fprintf ( V_37 , L_27 , V_19 -> V_45 ) ;
fprintf ( V_37 , L_28 , V_19 -> V_46 ) ;
fprintf ( V_37 , L_29 , V_19 -> V_47 ) ;
}
if ( V_20 ) {
fprintf ( V_37 , L_30 , V_20 -> V_48 ) ;
fprintf ( V_37 , L_31 , V_20 -> V_49 ) ;
fprintf ( V_37 , L_32 , V_20 -> V_50 ) ;
fprintf ( V_37 , L_33 , V_20 -> V_51 ) ;
fprintf ( V_37 , L_34 , V_20 -> V_52 ) ;
}
return 0 ;
}
int F_18 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
double V_53 ;
if ( V_54 && ! ( V_18 -> V_38 & V_55 ) )
return 0 ;
if ( V_56 && ! ( V_18 -> V_38 & V_57 ) )
return 0 ;
V_53 = V_58 . V_59 + V_58 . V_60 / 1000000.0 ;
if ( V_18 == & V_61 . V_62 ) {
if ( V_29 )
V_30 += sprintf ( V_30 , L_35 ) ;
if ( V_29 && V_31 )
V_30 += sprintf ( V_30 , L_3 ) ;
if ( V_31 )
V_30 += sprintf ( V_30 , L_36 ) ;
if ( V_32 )
V_30 += sprintf ( V_30 , L_3 L_36 ) ;
} else {
if ( V_29 ) {
if ( V_20 )
V_30 += sprintf ( V_30 , L_37 , V_20 -> V_48 ) ;
else
V_30 += sprintf ( V_30 , L_35 ) ;
}
if ( V_29 && V_31 )
V_30 += sprintf ( V_30 , L_3 ) ;
if ( V_31 ) {
if ( V_19 )
V_30 += sprintf ( V_30 , L_38 , V_19 -> V_44 ) ;
else
V_30 += sprintf ( V_30 , L_36 ) ;
}
if ( V_32 )
V_30 += sprintf ( V_30 , L_39 , V_18 -> V_21 ) ;
}
if ( V_33 ) {
if ( V_29 || V_31 || V_32 )
V_30 += sprintf ( V_30 , L_3 ) ;
if ( ! V_63 )
V_30 += sprintf ( V_30 , L_40 , 100.0 * V_18 -> V_41 / V_18 -> V_39 ) ;
else
V_30 += sprintf ( V_30 , L_41 ) ;
}
if ( V_34 ) {
if ( ! V_64 ) {
V_30 += sprintf ( V_30 , L_42 ,
1.0 * V_18 -> V_39 / V_65 * V_18 -> V_40 /
V_18 -> V_41 / V_53 ) ;
} else {
if ( V_18 -> V_40 > V_18 -> V_39 || V_18 -> V_41 > V_18 -> V_39 ) {
V_30 += sprintf ( V_30 , L_43 ) ;
} else {
V_30 += sprintf ( V_30 , L_44 ,
1.0 * V_18 -> V_39 /
V_65 * V_18 -> V_40 /
V_18 -> V_41 / V_53 ) ;
}
}
}
V_30 += sprintf ( V_30 , L_45 , 1.0 * V_18 -> V_39 / V_65 / V_53 ) ;
if ( V_33 ) {
if ( ! V_66 )
V_30 += sprintf ( V_30 , L_46 , 100.0 * V_18 -> V_42 / V_18 -> V_39 ) ;
else
V_30 += sprintf ( V_30 , L_41 ) ;
}
if ( ! ( V_18 -> V_38 & V_55 ) )
goto V_67;
if ( V_33 )
V_30 += sprintf ( V_30 , L_46 , 100.0 * V_19 -> V_45 / V_18 -> V_39 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_46 , 100.0 * V_19 -> V_46 / V_18 -> V_39 ) ;
if ( V_35 )
V_30 += sprintf ( V_30 , L_46 , 100.0 * V_19 -> V_47 / V_18 -> V_39 ) ;
if ( ! ( V_18 -> V_38 & V_57 ) )
goto V_67;
if ( V_35 )
V_30 += sprintf ( V_30 , L_46 , 100.0 * V_20 -> V_49 / V_18 -> V_39 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_46 , 100.0 * V_20 -> V_50 / V_18 -> V_39 ) ;
if ( V_33 )
V_30 += sprintf ( V_30 , L_46 , 100.0 * V_20 -> V_51 / V_18 -> V_39 ) ;
if ( V_35 )
V_30 += sprintf ( V_30 , L_46 , 100.0 * V_20 -> V_52 / V_18 -> V_39 ) ;
V_67:
if ( V_36 )
V_30 += sprintf ( V_30 , L_47 , V_18 -> V_43 ) ;
V_30 += sprintf ( V_30 , L_18 ) ;
return 0 ;
}
void F_19 ()
{
fputs ( V_68 , stdout ) ;
V_30 = V_68 ;
}
void F_20 ()
{
fputs ( V_68 , V_37 ) ;
V_30 = V_68 ;
}
void F_21 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
static int V_69 ;
if ( ! V_69 || ! V_70 )
F_16 () ;
if ( V_14 . V_71 > 1 )
F_18 ( & V_61 . V_62 , & V_61 . V_72 ,
& V_61 . V_73 ) ;
V_69 = 1 ;
if ( V_70 )
return;
F_3 ( F_18 , V_18 , V_19 , V_20 ) ;
}
void
F_22 ( struct V_6 * V_74 , struct V_6 * V_75 )
{
V_75 -> V_49 = V_74 -> V_49 - V_75 -> V_49 ;
V_75 -> V_50 = V_74 -> V_50 - V_75 -> V_50 ;
V_75 -> V_51 = V_74 -> V_51 - V_75 -> V_51 ;
V_75 -> V_52 = V_74 -> V_52 - V_75 -> V_52 ;
}
void
F_23 ( struct V_5 * V_74 , struct V_5 * V_75 )
{
V_75 -> V_45 = V_74 -> V_45 - V_75 -> V_45 ;
V_75 -> V_46 = V_74 -> V_46 - V_75 -> V_46 ;
V_75 -> V_47 = V_74 -> V_47 - V_75 -> V_47 ;
}
void
F_24 ( struct V_4 * V_74 , struct V_4 * V_75 ,
struct V_5 * V_76 )
{
V_75 -> V_39 = V_74 -> V_39 - V_75 -> V_39 ;
if ( V_75 -> V_39 < ( 1000 * 1000 ) ) {
fprintf ( V_37 , L_48 ) ;
fprintf ( V_37 , L_49 ) ;
fprintf ( V_37 , L_50 ) ;
exit ( - 3 ) ;
}
V_75 -> V_42 = V_74 -> V_42 - V_75 -> V_42 ;
if ( ( V_74 -> V_40 > V_75 -> V_40 ) && ( V_74 -> V_41 > V_75 -> V_41 ) ) {
V_75 -> V_40 = V_74 -> V_40 - V_75 -> V_40 ;
V_75 -> V_41 = V_74 -> V_41 - V_75 -> V_41 ;
} else {
if ( ! V_64 ) {
fprintf ( V_37 , L_51 , V_77 ) ;
fprintf ( V_37 , L_52 ) ;
fprintf ( V_37 , L_53 ) ;
V_64 = 1 ;
}
V_63 = 1 ;
V_66 = 1 ;
}
if ( ( V_75 -> V_41 + V_76 -> V_45 + V_76 -> V_46 + V_76 -> V_47 ) > V_75 -> V_39 )
V_75 -> V_42 = 0 ;
else {
V_75 -> V_42 = V_75 -> V_39 - V_75 -> V_41 - V_76 -> V_45
- V_76 -> V_46 - V_76 -> V_47 ;
}
if ( V_75 -> V_41 == 0 ) {
if ( V_78 > 1 ) fprintf ( V_37 , L_54 , V_75 -> V_21 ) ;
V_75 -> V_41 = 1 ;
}
V_75 -> V_43 = V_74 -> V_43 ;
}
int F_25 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 , struct V_4 * V_79 ,
struct V_5 * V_80 , struct V_6 * V_81 )
{
if ( V_18 -> V_38 & V_55 )
F_23 ( V_19 , V_80 ) ;
F_24 ( V_18 , V_79 , V_80 ) ;
if ( V_18 -> V_38 & V_57 )
F_22 ( V_20 , V_81 ) ;
return 0 ;
}
void F_26 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
V_18 -> V_39 = 0 ;
V_18 -> V_40 = 0 ;
V_18 -> V_41 = 0 ;
V_18 -> V_42 = 0 ;
V_18 -> V_38 = V_55 | V_57 ;
V_19 -> V_45 = 0 ;
V_19 -> V_46 = 0 ;
V_19 -> V_47 = 0 ;
V_20 -> V_49 = 0 ;
V_20 -> V_50 = 0 ;
V_20 -> V_51 = 0 ;
V_20 -> V_52 = 0 ;
}
int F_27 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
V_61 . V_62 . V_39 += V_18 -> V_39 ;
V_61 . V_62 . V_40 += V_18 -> V_40 ;
V_61 . V_62 . V_41 += V_18 -> V_41 ;
V_61 . V_62 . V_42 += V_18 -> V_42 ;
if ( ! ( V_18 -> V_38 & V_55 ) )
return 0 ;
V_61 . V_72 . V_45 += V_19 -> V_45 ;
V_61 . V_72 . V_46 += V_19 -> V_46 ;
V_61 . V_72 . V_47 += V_19 -> V_47 ;
if ( ! ( V_18 -> V_38 & V_57 ) )
return 0 ;
V_61 . V_73 . V_49 += V_20 -> V_49 ;
V_61 . V_73 . V_50 += V_20 -> V_50 ;
V_61 . V_73 . V_51 += V_20 -> V_51 ;
V_61 . V_73 . V_52 += V_20 -> V_52 ;
return 0 ;
}
void F_28 ( struct V_4 * V_18 , struct V_5 * V_19 ,
struct V_6 * V_20 )
{
F_26 ( & V_61 . V_62 , & V_61 . V_72 , & V_61 . V_73 ) ;
F_3 ( F_27 , V_18 , V_19 , V_20 ) ;
V_61 . V_62 . V_39 /= V_14 . V_71 ;
V_61 . V_62 . V_40 /= V_14 . V_71 ;
V_61 . V_62 . V_41 /= V_14 . V_71 ;
V_61 . V_62 . V_42 /= V_14 . V_71 ;
V_61 . V_72 . V_45 /= V_14 . V_82 ;
V_61 . V_72 . V_46 /= V_14 . V_82 ;
V_61 . V_72 . V_47 /= V_14 . V_82 ;
V_61 . V_73 . V_49 /= V_14 . V_15 ;
V_61 . V_73 . V_50 /= V_14 . V_15 ;
V_61 . V_73 . V_51 /= V_14 . V_15 ;
V_61 . V_73 . V_52 /= V_14 . V_15 ;
}
static unsigned long long F_29 ( void )
{
unsigned int V_83 , V_84 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_83 | ( ( unsigned long long ) V_84 ) << 32 ;
}
int F_30 ( struct V_4 * V_18 , struct V_5 * V_19 , struct V_6 * V_20 )
{
int V_1 = V_18 -> V_21 ;
if ( F_8 ( V_1 ) )
return - 1 ;
V_18 -> V_39 = F_29 () ;
if ( V_34 ) {
if ( F_12 ( V_1 , V_85 , & V_18 -> V_40 ) )
return - 3 ;
if ( F_12 ( V_1 , V_86 , & V_18 -> V_41 ) )
return - 4 ;
}
if ( V_36 )
if ( F_12 ( V_1 , V_36 , & V_18 -> V_43 ) )
return - 5 ;
if ( ! ( V_18 -> V_38 & V_55 ) )
return 0 ;
if ( V_33 ) {
if ( F_12 ( V_1 , V_87 , & V_19 -> V_45 ) )
return - 6 ;
if ( F_12 ( V_1 , V_88 , & V_19 -> V_46 ) )
return - 7 ;
}
if ( V_35 )
if ( F_12 ( V_1 , V_89 , & V_19 -> V_47 ) )
return - 8 ;
if ( ! ( V_18 -> V_38 & V_57 ) )
return 0 ;
if ( V_33 ) {
if ( F_12 ( V_1 , V_90 , & V_20 -> V_50 ) )
return - 9 ;
if ( F_12 ( V_1 , V_91 , & V_20 -> V_51 ) )
return - 10 ;
}
if ( V_35 ) {
if ( F_12 ( V_1 , V_92 , & V_20 -> V_49 ) )
return - 11 ;
if ( F_12 ( V_1 , V_93 , & V_20 -> V_52 ) )
return - 12 ;
}
return 0 ;
}
void F_31 ( void )
{
unsigned long long V_25 ;
unsigned int V_94 ;
if ( ! V_95 )
return;
F_12 ( 0 , V_96 , & V_25 ) ;
V_94 = ( V_25 >> 40 ) & 0xFF ;
fprintf ( V_37 , L_55 ,
V_94 , V_97 , V_94 * V_97 ) ;
V_94 = ( V_25 >> 8 ) & 0xFF ;
fprintf ( V_37 , L_56 ,
V_94 , V_97 , V_94 * V_97 ) ;
if ( V_78 > 1 )
fprintf ( V_37 , L_57 , V_25 ) ;
if ( ! V_98 )
return;
F_12 ( 0 , V_99 , & V_25 ) ;
V_94 = ( V_25 >> 24 ) & 0xFF ;
if ( V_94 )
fprintf ( V_37 , L_58 ,
V_94 , V_97 , V_94 * V_97 ) ;
V_94 = ( V_25 >> 16 ) & 0xFF ;
if ( V_94 )
fprintf ( V_37 , L_59 ,
V_94 , V_97 , V_94 * V_97 ) ;
V_94 = ( V_25 >> 8 ) & 0xFF ;
if ( V_94 )
fprintf ( V_37 , L_60 ,
V_94 , V_97 , V_94 * V_97 ) ;
V_94 = ( V_25 >> 0 ) & 0xFF ;
if ( V_94 )
fprintf ( V_37 , L_61 ,
V_94 , V_97 , V_94 * V_97 ) ;
}
void F_32 ( void )
{
F_33 ( V_3 ) ;
V_3 = NULL ;
V_3 = 0 ;
F_33 ( V_23 ) ;
V_23 = NULL ;
V_22 = 0 ;
free ( V_100 ) ;
free ( V_101 ) ;
free ( V_102 ) ;
V_100 = NULL ;
V_101 = NULL ;
V_102 = NULL ;
free ( V_103 ) ;
free ( V_104 ) ;
free ( V_105 ) ;
V_103 = NULL ;
V_104 = NULL ;
V_105 = NULL ;
free ( V_68 ) ;
V_68 = NULL ;
V_30 = NULL ;
}
int F_34 ( int V_1 )
{
char V_106 [ 64 ] ;
T_3 * V_107 ;
int V_108 ;
sprintf ( V_106 , L_62 , V_1 ) ;
V_107 = fopen ( V_106 , L_63 ) ;
if ( V_107 == NULL ) {
perror ( V_106 ) ;
exit ( 1 ) ;
}
fscanf ( V_107 , L_64 , & V_108 ) ;
fclose ( V_107 ) ;
return ( V_1 == V_108 ) ;
}
int F_35 ( int V_1 )
{
char V_106 [ 64 ] ;
T_3 * V_107 ;
int V_108 ;
sprintf ( V_106 , L_65 , V_1 ) ;
V_107 = fopen ( V_106 , L_63 ) ;
if ( V_107 == NULL ) {
perror ( V_106 ) ;
exit ( 1 ) ;
}
fscanf ( V_107 , L_64 , & V_108 ) ;
fclose ( V_107 ) ;
return ( V_1 == V_108 ) ;
}
int F_36 ( int V_1 )
{
char V_106 [ 80 ] ;
T_3 * V_107 ;
int V_109 ;
sprintf ( V_106 , L_66 , V_1 ) ;
V_107 = fopen ( V_106 , L_63 ) ;
if ( V_107 == NULL ) {
perror ( V_106 ) ;
exit ( 1 ) ;
}
fscanf ( V_107 , L_64 , & V_109 ) ;
fclose ( V_107 ) ;
return V_109 ;
}
int F_37 ( int V_1 )
{
char V_106 [ 80 ] ;
T_3 * V_107 ;
int V_110 ;
sprintf ( V_106 , L_67 , V_1 ) ;
V_107 = fopen ( V_106 , L_63 ) ;
if ( V_107 == NULL ) {
perror ( V_106 ) ;
exit ( 1 ) ;
}
fscanf ( V_107 , L_64 , & V_110 ) ;
fclose ( V_107 ) ;
return V_110 ;
}
int F_38 ( int V_1 )
{
char V_106 [ 80 ] ;
T_3 * V_107 ;
int V_111 , V_112 ;
int V_113 ;
char V_114 ;
sprintf ( V_106 , L_62 , V_1 ) ;
V_107 = fopen ( V_106 , L_63 ) ;
if ( V_107 == NULL ) {
perror ( V_106 ) ;
exit ( 1 ) ;
}
V_113 = fscanf ( V_107 , L_68 , & V_111 , & V_114 , & V_112 ) ;
fclose ( V_107 ) ;
if ( V_113 == 3 )
return 2 ;
else
return 1 ;
}
int F_39 ( int (F_4)( struct V_4 * , struct V_5 * ,
struct V_6 * , struct V_4 * , struct V_5 * ,
struct V_6 * ) , struct V_4 * V_7 ,
struct V_5 * V_8 , struct V_6 * V_9 ,
struct V_4 * V_115 , struct V_5 * V_116 ,
struct V_6 * V_117 )
{
int V_10 , V_11 , V_12 , V_13 ;
for ( V_11 = 0 ; V_11 < V_14 . V_15 ; ++ V_11 ) {
for ( V_12 = 0 ; V_12 < V_14 . V_16 ; ++ V_12 ) {
for ( V_13 = 0 ; V_13 <
V_14 . V_17 ; ++ V_13 ) {
struct V_4 * V_18 , * V_79 ;
struct V_5 * V_19 , * V_80 ;
struct V_6 * V_20 , * V_81 ;
V_18 = F_5 ( V_7 , V_13 , V_12 , V_11 ) ;
if ( F_1 ( V_18 -> V_21 ) )
continue;
V_79 = F_5 ( V_115 , V_13 , V_12 , V_11 ) ;
V_19 = F_6 ( V_8 , V_12 , V_11 ) ;
V_80 = F_6 ( V_116 , V_12 , V_11 ) ;
V_20 = F_7 ( V_9 , V_11 ) ;
V_81 = F_7 ( V_117 , V_11 ) ;
V_10 = F_4 ( V_18 , V_19 , V_20 , V_79 , V_80 , V_81 ) ;
if ( V_10 )
return V_10 ;
}
}
}
return 0 ;
}
int F_40 ( int (F_4)( int ) )
{
T_3 * V_118 ;
int V_119 ;
int V_10 ;
V_118 = fopen ( V_120 , L_63 ) ;
if ( V_118 == NULL ) {
perror ( V_120 ) ;
exit ( 1 ) ;
}
V_10 = fscanf ( V_118 , L_69 ) ;
if ( V_10 != 0 ) {
perror ( L_70 ) ;
exit ( 1 ) ;
}
while ( 1 ) {
V_10 = fscanf ( V_118 , L_71 , & V_119 ) ;
if ( V_10 != 1 )
break;
V_10 = F_4 ( V_119 ) ;
if ( V_10 ) {
fclose ( V_118 ) ;
return ( V_10 ) ;
}
}
fclose ( V_118 ) ;
return 0 ;
}
void F_41 ( void )
{
F_32 () ;
F_42 () ;
printf ( L_72 , V_14 . V_71 ) ;
}
int F_43 ( int V_1 )
{
if ( V_14 . V_121 < V_1 )
V_14 . V_121 = V_1 ;
V_14 . V_71 += 1 ;
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
V_122:
V_10 = F_3 ( F_30 , V_123 ) ;
if ( V_10 ) {
F_41 () ;
goto V_122;
}
F_46 ( & V_124 , (struct V_125 * ) NULL ) ;
while ( 1 ) {
if ( F_40 ( F_1 ) ) {
F_41 () ;
goto V_122;
}
F_47 ( V_126 ) ;
V_10 = F_3 ( F_30 , V_127 ) ;
if ( V_10 ) {
F_41 () ;
goto V_122;
}
F_46 ( & V_128 , (struct V_125 * ) NULL ) ;
F_48 ( & V_128 , & V_124 , & V_58 ) ;
F_39 ( F_25 , V_127 , V_123 ) ;
F_28 ( V_123 ) ;
F_21 ( V_123 ) ;
F_19 () ;
F_47 ( V_126 ) ;
V_10 = F_3 ( F_30 , V_123 ) ;
if ( V_10 ) {
F_41 () ;
goto V_122;
}
F_46 ( & V_124 , (struct V_125 * ) NULL ) ;
F_48 ( & V_124 , & V_128 , & V_58 ) ;
F_39 ( F_25 , V_123 , V_127 ) ;
F_28 ( V_127 ) ;
F_21 ( V_127 ) ;
F_19 () ;
}
}
void F_49 ()
{
struct V_129 V_130 ;
if ( V_129 ( L_73 , & V_130 ) ) {
fprintf ( V_37 , L_74 ) ;
fprintf ( V_37 , L_75 ) ;
exit ( - 5 ) ;
}
}
void F_50 ()
{
if ( F_51 () != 0 ) {
fprintf ( V_37 , L_76 ) ;
exit ( - 6 ) ;
}
}
int F_52 ( unsigned int V_131 , unsigned int V_132 )
{
if ( ! V_133 )
return 0 ;
if ( V_131 != 6 )
return 0 ;
switch ( V_132 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x25 :
case 0x2C :
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3D :
return 1 ;
case 0x2E :
case 0x2F :
default:
return 0 ;
}
}
int F_53 ( unsigned int V_131 , unsigned int V_132 )
{
if ( ! V_133 )
return 0 ;
switch ( V_132 ) {
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3D :
return 1 ;
}
return 0 ;
}
double F_54 ( unsigned int V_131 , unsigned int V_132 )
{
if ( F_53 ( V_131 , V_132 ) )
return 100.00 ;
else
return 133.33 ;
}
void F_55 ()
{
unsigned int V_134 , V_135 , V_136 , V_137 , V_138 ;
unsigned int V_139 , V_131 , V_132 , V_140 ;
V_134 = V_135 = V_136 = V_137 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0));
if ( V_135 == 0x756e6547 && V_137 == 0x49656e69 && V_136 == 0x6c65746e )
V_133 = 1 ;
if ( V_78 )
fprintf ( V_37 , L_77 ,
( char * ) & V_135 , ( char * ) & V_137 , ( char * ) & V_136 ) ;
asm("cpuid" : "=a" (fms), "=c" (ecx), "=d" (edx) : "a" (1) : "ebx");
V_131 = ( V_139 >> 8 ) & 0xf ;
V_132 = ( V_139 >> 4 ) & 0xf ;
V_140 = V_139 & 0xf ;
if ( V_131 == 6 || V_131 == 0xf )
V_132 += ( ( V_139 >> 16 ) & 0xf ) << 4 ;
if ( V_78 )
fprintf ( V_37 , L_78 ,
V_138 , V_131 , V_132 , V_140 , V_131 , V_132 , V_140 ) ;
if ( ! ( V_137 & ( 1 << 5 ) ) ) {
fprintf ( V_37 , L_79 ) ;
exit ( 1 ) ;
}
V_135 = V_136 = V_137 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000000));
if ( V_138 < 0x80000007 ) {
fprintf ( V_37 , L_80 , V_138 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000007));
V_141 = V_137 & ( 1 << 8 ) ;
if ( ! V_141 ) {
fprintf ( V_37 , L_81 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x6));
V_34 = V_136 & ( 1 << 0 ) ;
if ( ! V_34 ) {
fprintf ( V_37 , L_82 ) ;
exit ( 1 ) ;
}
V_95 = V_133 && V_141 ;
V_33 = V_133 ;
V_35 = F_53 ( V_131 , V_132 ) ;
V_97 = F_54 ( V_131 , V_132 ) ;
V_98 = F_52 ( V_131 , V_132 ) ;
}
void F_56 ()
{
fprintf ( V_37 , L_83 ,
V_77 ) ;
exit ( 1 ) ;
}
int F_57 ( const struct V_142 * V_143 )
{
if ( isdigit ( V_143 -> V_144 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_58 ( int V_145 )
{
return 0 ;
}
void F_59 ()
{
int V_146 ;
int V_147 = 0 ;
int V_148 = 0 ;
int V_149 = 0 ;
struct V_150 {
int V_44 ;
int V_151 ;
} * V_152 ;
V_14 . V_71 = 0 ;
V_14 . V_121 = 0 ;
F_40 ( F_43 ) ;
if ( ! V_70 && V_14 . V_71 > 1 )
V_32 = 1 ;
if ( V_78 > 1 )
fprintf ( V_37 , L_84 , V_14 . V_71 , V_14 . V_121 ) ;
V_152 = calloc ( 1 , ( V_14 . V_121 + 1 ) * sizeof( struct V_150 ) ) ;
if ( V_152 == NULL ) {
perror ( L_85 ) ;
exit ( 1 ) ;
}
V_3 = F_60 ( ( V_14 . V_121 + 1 ) ) ;
if ( V_3 == NULL ) {
perror ( L_86 ) ;
exit ( 3 ) ;
}
V_2 = F_61 ( ( V_14 . V_121 + 1 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_40 ( F_44 ) ;
V_23 = F_60 ( ( V_14 . V_121 + 1 ) ) ;
if ( V_23 == NULL ) {
perror ( L_86 ) ;
exit ( 3 ) ;
}
V_22 = F_61 ( ( V_14 . V_121 + 1 ) ) ;
F_9 ( V_22 , V_23 ) ;
for ( V_146 = 0 ; V_146 <= V_14 . V_121 ; ++ V_146 ) {
int V_153 ;
if ( F_1 ( V_146 ) ) {
if ( V_78 > 1 )
fprintf ( V_37 , L_87 , V_146 ) ;
continue;
}
V_152 [ V_146 ] . V_44 = F_37 ( V_146 ) ;
if ( V_152 [ V_146 ] . V_44 > V_147 )
V_147 = V_152 [ V_146 ] . V_44 ;
V_152 [ V_146 ] . V_151 = F_36 ( V_146 ) ;
if ( V_152 [ V_146 ] . V_151 > V_148 )
V_148 = V_152 [ V_146 ] . V_151 ;
V_153 = F_38 ( V_146 ) ;
if ( V_153 > V_149 )
V_149 = V_153 ;
if ( V_78 > 1 )
fprintf ( V_37 , L_88 ,
V_146 , V_152 [ V_146 ] . V_151 , V_152 [ V_146 ] . V_44 ) ;
}
V_14 . V_16 = V_147 + 1 ;
if ( V_78 > 1 )
fprintf ( V_37 , L_89 ,
V_147 , V_14 . V_16 ) ;
if ( ! V_70 && V_14 . V_16 > 1 )
V_31 = 1 ;
V_14 . V_15 = V_148 + 1 ;
if ( V_78 > 1 )
fprintf ( V_37 , L_90 ,
V_148 , V_14 . V_15 ) ;
if ( ! V_70 && V_14 . V_15 > 1 )
V_29 = 1 ;
V_14 . V_17 = V_149 ;
if ( V_78 > 1 )
fprintf ( V_37 , L_91 , V_149 ) ;
free ( V_152 ) ;
}
void
F_62 ( struct V_4 * * V_18 , struct V_5 * * V_19 , struct V_6 * * V_20 )
{
int V_146 ;
* V_18 = calloc ( V_14 . V_17 * V_14 . V_16 *
V_14 . V_15 , sizeof( struct V_4 ) ) ;
if ( * V_18 == NULL )
goto error;
for ( V_146 = 0 ; V_146 < V_14 . V_17 *
V_14 . V_16 * V_14 . V_15 ; V_146 ++ )
( * V_18 ) [ V_146 ] . V_21 = - 1 ;
* V_19 = calloc ( V_14 . V_16 * V_14 . V_15 ,
sizeof( struct V_5 ) ) ;
if ( * V_19 == NULL )
goto error;
for ( V_146 = 0 ; V_146 < V_14 . V_16 * V_14 . V_15 ; V_146 ++ )
( * V_19 ) [ V_146 ] . V_44 = - 1 ;
* V_20 = calloc ( V_14 . V_15 , sizeof( struct V_6 ) ) ;
if ( * V_20 == NULL )
goto error;
for ( V_146 = 0 ; V_146 < V_14 . V_15 ; V_146 ++ )
( * V_20 ) [ V_146 ] . V_48 = V_146 ;
return;
error:
perror ( L_92 ) ;
exit ( 1 ) ;
}
void F_63 ( struct V_4 * V_7 , struct V_5 * V_8 ,
struct V_6 * V_9 , int V_154 , int V_155 ,
int V_156 , int V_21 )
{
struct V_4 * V_18 ;
struct V_5 * V_19 ;
struct V_6 * V_20 ;
V_18 = F_5 ( V_7 , V_154 , V_155 , V_156 ) ;
V_19 = F_6 ( V_8 , V_155 , V_156 ) ;
V_20 = F_7 ( V_9 , V_156 ) ;
V_18 -> V_21 = V_21 ;
if ( V_154 == 0 ) {
V_18 -> V_38 |= V_55 ;
if ( F_35 ( V_21 ) )
V_18 -> V_38 |= V_57 ;
}
V_19 -> V_44 = V_155 ;
V_20 -> V_48 = V_156 ;
}
int F_64 ( int V_21 )
{
int V_157 , V_158 , V_159 ;
V_159 = F_36 ( V_21 ) ;
V_158 = F_37 ( V_21 ) ;
if ( F_34 ( V_21 ) ) {
V_157 = 0 ;
V_14 . V_82 ++ ;
} else {
V_157 = 1 ;
}
F_63 ( V_123 , V_157 , V_158 , V_159 , V_21 ) ;
F_63 ( V_127 , V_157 , V_158 , V_159 , V_21 ) ;
return 0 ;
}
void F_65 ()
{
V_68 = calloc ( 1 , ( 1 + V_14 . V_71 ) * 128 ) ;
V_30 = V_68 ;
if ( V_30 == NULL ) {
perror ( L_93 ) ;
exit ( - 1 ) ;
}
}
void F_42 ( void )
{
F_59 () ;
F_62 ( & V_100 , & V_101 , & V_102 ) ;
F_62 ( & V_103 , & V_104 , & V_105 ) ;
F_65 () ;
F_40 ( F_64 ) ;
}
void F_66 ()
{
F_55 () ;
F_49 () ;
F_50 () ;
F_42 () ;
if ( V_78 )
F_31 () ;
}
int F_67 ( char * * V_160 )
{
T_4 V_161 ;
F_3 ( F_30 , V_123 ) ;
F_11 ( 0 , V_2 , V_3 ) ;
F_46 ( & V_124 , (struct V_125 * ) NULL ) ;
V_161 = F_68 () ;
if ( ! V_161 ) {
F_69 ( V_160 [ 0 ] , V_160 ) ;
} else {
int V_162 ;
if ( V_161 == - 1 ) {
perror ( L_94 ) ;
exit ( 1 ) ;
}
signal ( V_163 , V_164 ) ;
signal ( V_165 , V_164 ) ;
if ( F_70 ( V_161 , & V_162 , 0 ) == - 1 ) {
perror ( L_95 ) ;
exit ( 1 ) ;
}
}
F_3 ( F_30 , V_127 ) ;
F_46 ( & V_128 , (struct V_125 * ) NULL ) ;
F_48 ( & V_128 , & V_124 , & V_58 ) ;
F_39 ( F_25 , V_127 , V_123 ) ;
F_28 ( V_123 ) ;
F_21 ( V_123 ) ;
F_20 () ;
fprintf ( V_37 , L_96 , V_58 . V_59 + V_58 . V_60 / 1000000.0 ) ;
return 0 ;
}
void F_71 ( int V_166 , char * * V_160 )
{
int V_167 ;
V_77 = V_160 [ 0 ] ;
while ( ( V_167 = F_72 ( V_166 , V_160 , L_97 ) ) != - 1 ) {
switch ( V_167 ) {
case 'c' :
V_54 ++ ;
break;
case 'p' :
V_56 ++ ;
break;
case 's' :
V_70 ++ ;
break;
case 'v' :
V_78 ++ ;
break;
case 'i' :
V_126 = atoi ( V_168 ) ;
break;
case 'M' :
sscanf ( V_168 , L_98 , & V_36 ) ;
if ( V_78 > 1 )
fprintf ( V_37 , L_99 , V_36 ) ;
break;
default:
F_56 () ;
}
}
}
int main ( int V_166 , char * * V_160 )
{
F_71 ( V_166 , V_160 ) ;
if ( V_78 > 1 )
fprintf ( V_37 , L_100
L_101 ) ;
F_66 () ;
if ( V_166 - V_169 )
return F_67 ( V_160 + V_169 ) ;
else
F_45 () ;
return 0 ;
}
