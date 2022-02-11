void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
struct V_2 * V_2 ( unsigned int V_3 )
{
return F_5 ( V_3 ) ;
}
struct V_2 * F_6 ( struct V_4 * V_4 )
{
return V_4 -> V_5 ;
}
static struct V_2 * F_7 ( unsigned int V_3 , int V_6 )
{
struct V_2 * V_7 ;
V_7 = F_8 ( sizeof( * V_7 ) , V_8 , V_6 ) ;
if ( ! V_7 )
return NULL ;
if ( ! F_9 ( & V_7 -> V_9 , V_8 , V_6 ) )
goto V_10;
if ( ! F_9 ( & V_7 -> V_11 , V_8 , V_6 ) )
goto V_12;
#ifdef F_10
F_11 ( & V_7 -> V_13 ) ;
#endif
return V_7 ;
V_12:
F_12 ( V_7 -> V_9 ) ;
V_10:
F_13 ( V_7 ) ;
return NULL ;
}
struct V_2 * F_14 ( unsigned int V_14 , int V_6 )
{
int V_15 = F_15 ( V_14 , V_6 ) ;
struct V_2 * V_7 ;
if ( V_15 < 0 ) {
if ( V_15 != - V_16 )
return NULL ;
V_7 = V_2 ( V_14 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_7 ( V_14 , V_6 ) ;
if ( V_7 )
F_16 ( V_14 , V_7 ) ;
else
F_17 ( V_14 ) ;
return V_7 ;
}
static void F_18 ( unsigned int V_14 , struct V_2 * V_7 )
{
if ( ! V_7 )
return;
F_16 ( V_14 , NULL ) ;
F_12 ( V_7 -> V_9 ) ;
F_12 ( V_7 -> V_11 ) ;
F_13 ( V_7 ) ;
}
static int
F_19 ( int V_3 , struct V_2 * V_7 , const struct V_17 * V_18 )
{
static int V_19 = V_20 + V_21 ;
static int V_22 = V_21 % 16 ;
int V_23 , V_24 ;
T_1 V_25 ;
if ( V_7 -> V_26 )
return - V_27 ;
if ( ! F_20 ( & V_25 , V_28 ) )
return - V_29 ;
V_24 = - V_30 ;
F_21 ( V_7 -> V_11 ) ;
V_23 = F_22 ( V_18 , V_31 ) ;
while ( V_23 < V_32 ) {
int V_33 , V_34 , V_35 ;
V_36 -> V_37 ( V_23 , V_25 , V_18 ) ;
if ( F_23 ( V_25 , V_7 -> V_9 ) ) {
V_24 = 0 ;
if ( F_24 ( V_25 , V_7 -> V_9 ) )
break;
F_25 ( V_7 -> V_11 , V_7 -> V_9 , V_25 ) ;
V_7 -> V_26 =
F_26 ( V_7 -> V_11 , V_31 ) ;
F_27 ( V_7 -> V_9 , V_7 -> V_9 , V_25 ) ;
break;
}
V_34 = V_19 ;
V_35 = V_22 ;
V_38:
V_34 += 16 ;
if ( V_34 >= V_39 ) {
V_35 = ( V_35 + 1 ) % 16 ;
V_34 = V_20 + V_35 ;
}
if ( F_28 ( V_19 == V_34 ) ) {
F_29 ( V_7 -> V_11 , V_7 -> V_11 , V_25 ) ;
F_25 ( V_25 , V_18 , V_7 -> V_11 ) ;
V_23 = F_22 ( V_25 , V_31 ) ;
continue;
}
if ( F_30 ( V_34 , V_40 ) )
goto V_38;
F_31 (new_cpu, tmp_mask, cpu_online_mask) {
if ( F_32 ( V_41 , V_33 ) [ V_34 ] >
V_42 )
goto V_38;
}
V_19 = V_34 ;
V_22 = V_35 ;
if ( V_7 -> V_34 ) {
F_33 ( V_7 -> V_11 , V_7 -> V_9 ) ;
V_7 -> V_26 =
F_26 ( V_7 -> V_11 , V_31 ) ;
}
F_31 (new_cpu, tmp_mask, cpu_online_mask)
F_32 ( V_41 , V_33 ) [ V_34 ] = V_3 ;
V_7 -> V_34 = V_34 ;
F_33 ( V_7 -> V_9 , V_25 ) ;
V_24 = 0 ;
break;
}
F_12 ( V_25 ) ;
return V_24 ;
}
int F_34 ( int V_3 , struct V_2 * V_7 , const struct V_17 * V_18 )
{
int V_24 ;
unsigned long V_43 ;
F_35 ( & V_1 , V_43 ) ;
V_24 = F_19 ( V_3 , V_7 , V_18 ) ;
F_36 ( & V_1 , V_43 ) ;
return V_24 ;
}
void F_37 ( int V_3 , struct V_2 * V_7 )
{
int V_23 , V_34 ;
unsigned long V_43 ;
F_35 ( & V_1 , V_43 ) ;
F_38 ( ! V_7 -> V_34 ) ;
V_34 = V_7 -> V_34 ;
F_31 (cpu, cfg->domain, cpu_online_mask)
F_32 ( V_41 , V_23 ) [ V_34 ] = V_42 ;
V_7 -> V_34 = 0 ;
F_21 ( V_7 -> V_9 ) ;
if ( F_39 ( ! V_7 -> V_26 ) ) {
F_36 ( & V_1 , V_43 ) ;
return;
}
F_31 (cpu, cfg->old_domain, cpu_online_mask) {
for ( V_34 = V_20 ; V_34 < V_44 ;
V_34 ++ ) {
if ( F_32 ( V_41 , V_23 ) [ V_34 ] != V_3 )
continue;
F_32 ( V_41 , V_23 ) [ V_34 ] = V_42 ;
break;
}
}
V_7 -> V_26 = 0 ;
F_36 ( & V_1 , V_43 ) ;
}
int T_2 F_40 ( void )
{
int V_45 ;
if ( V_46 > ( V_44 * V_32 ) )
V_46 = V_44 * V_32 ;
V_45 = ( V_47 + F_41 () ) + 8 * V_32 ;
#if F_42 ( V_48 ) || F_42 ( V_49 )
if ( V_47 <= V_50 )
V_45 += 8 * V_32 ;
else
V_45 += V_47 * 16 ;
#endif
if ( V_45 < V_46 )
V_46 = V_45 ;
return F_41 () ;
}
int T_2 F_43 ( void )
{
return F_44 () ;
}
static void F_45 ( int V_23 )
{
int V_3 , V_34 ;
struct V_2 * V_7 ;
F_2 ( & V_1 ) ;
F_46 (irq) {
V_7 = V_2 ( V_3 ) ;
if ( ! V_7 )
continue;
if ( ! F_47 ( V_23 , V_7 -> V_9 ) )
continue;
V_34 = V_7 -> V_34 ;
F_32 ( V_41 , V_23 ) [ V_34 ] = V_3 ;
}
for ( V_34 = 0 ; V_34 < V_44 ; ++ V_34 ) {
V_3 = F_32 ( V_41 , V_23 ) [ V_34 ] ;
if ( V_3 <= V_42 )
continue;
V_7 = V_2 ( V_3 ) ;
if ( ! F_47 ( V_23 , V_7 -> V_9 ) )
F_32 ( V_41 , V_23 ) [ V_34 ] = V_42 ;
}
F_4 ( & V_1 ) ;
}
void F_48 ( int V_23 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_41 () ; V_3 ++ )
F_32 ( V_41 , V_23 ) [ V_51 + V_3 ] = V_3 ;
F_45 ( V_23 ) ;
}
int F_49 ( struct V_4 * V_52 )
{
struct V_2 * V_7 = F_6 ( V_52 ) ;
unsigned long V_43 ;
int V_23 ;
F_35 ( & V_1 , V_43 ) ;
V_23 = F_22 ( V_7 -> V_9 , V_31 ) ;
V_36 -> V_53 ( F_50 ( V_23 ) , V_7 -> V_34 ) ;
F_36 ( & V_1 , V_43 ) ;
return 1 ;
}
void F_51 ( struct V_4 * V_52 )
{
F_52 ( F_6 ( V_52 ) ) ;
F_53 ( V_52 ) ;
F_54 () ;
}
int F_55 ( struct V_4 * V_52 , const struct V_17 * V_18 ,
unsigned int * V_54 )
{
struct V_2 * V_7 = F_6 ( V_52 ) ;
unsigned int V_3 = V_52 -> V_3 ;
int V_24 ;
if ( ! F_56 ( V_55 ) )
return - V_56 ;
if ( ! F_26 ( V_18 , V_31 ) )
return - V_57 ;
V_24 = F_34 ( V_3 , V_7 , V_18 ) ;
if ( V_24 )
return V_24 ;
V_24 = V_36 -> V_58 ( V_18 , V_7 -> V_9 , V_54 ) ;
if ( V_24 ) {
if ( F_34 ( V_3 , V_7 , V_52 -> V_59 ) )
F_57 ( L_1 , V_3 ) ;
return V_24 ;
}
F_33 ( V_52 -> V_59 , V_18 ) ;
return 0 ;
}
void F_58 ( struct V_2 * V_7 )
{
T_1 V_60 ;
if ( F_28 ( ! F_20 ( & V_60 , V_28 ) ) ) {
unsigned int V_61 ;
F_31 (i, cfg->old_domain, cpu_online_mask)
V_36 -> V_53 ( F_50 ( V_61 ) ,
V_62 ) ;
} else {
F_27 ( V_60 , V_7 -> V_11 , V_31 ) ;
V_36 -> V_53 ( V_60 , V_62 ) ;
F_12 ( V_60 ) ;
}
V_7 -> V_26 = 0 ;
}
T_3 T_4 void F_59 ( void )
{
unsigned V_34 , V_63 ;
F_54 () ;
F_60 () ;
F_61 () ;
V_63 = F_62 () ;
for ( V_34 = V_20 ; V_34 < V_44 ; V_34 ++ ) {
int V_3 ;
unsigned int V_64 ;
struct V_65 * V_66 ;
struct V_2 * V_7 ;
V_3 = F_63 ( V_41 [ V_34 ] ) ;
if ( V_3 <= V_42 )
continue;
V_66 = F_64 ( V_3 ) ;
if ( ! V_66 )
continue;
V_7 = V_2 ( V_3 ) ;
if ( ! V_7 )
continue;
F_2 ( & V_66 -> V_67 ) ;
if ( V_7 -> V_26 )
goto V_68;
if ( V_34 == V_7 -> V_34 && F_47 ( V_63 , V_7 -> V_9 ) )
goto V_68;
V_64 = F_65 ( V_69 + ( V_34 / 32 * 0x10 ) ) ;
if ( V_64 & ( 1 << ( V_34 % 32 ) ) ) {
V_36 -> V_70 ( V_62 ) ;
goto V_68;
}
F_66 ( V_41 [ V_34 ] , V_42 ) ;
V_68:
F_4 ( & V_66 -> V_67 ) ;
}
F_67 () ;
}
static void F_68 ( struct V_2 * V_7 , unsigned V_34 )
{
unsigned V_63 ;
if ( F_39 ( ! V_7 -> V_26 ) )
return;
V_63 = F_62 () ;
if ( V_34 == V_7 -> V_34 && F_47 ( V_63 , V_7 -> V_9 ) )
F_58 ( V_7 ) ;
}
void F_52 ( struct V_2 * V_7 )
{
F_68 ( V_7 , ~ F_69 () -> V_71 ) ;
}
void F_70 ( int V_3 )
{
struct V_2 * V_7 = V_2 ( V_3 ) ;
if ( ! V_7 )
return;
F_68 ( V_7 , V_7 -> V_34 ) ;
}
int F_71 ( unsigned int V_3 , int V_6 )
{
struct V_2 * V_7 ;
unsigned long V_43 ;
int V_72 ;
V_7 = F_7 ( V_3 , V_6 ) ;
if ( ! V_7 )
return - V_29 ;
F_35 ( & V_1 , V_43 ) ;
V_72 = F_19 ( V_3 , V_7 , V_36 -> V_73 () ) ;
F_36 ( & V_1 , V_43 ) ;
if ( ! V_72 )
F_16 ( V_3 , V_7 ) ;
else
F_18 ( V_3 , V_7 ) ;
return V_72 ;
}
void F_72 ( unsigned int V_3 )
{
struct V_2 * V_7 = V_2 ( V_3 ) ;
F_73 ( V_3 ) ;
F_37 ( V_3 , V_7 ) ;
F_18 ( V_3 , V_7 ) ;
}
static void T_2 F_74 ( int V_74 )
{
int V_61 ;
F_75 ( V_75 ) ;
for ( V_61 = 0 ; V_61 < 8 ; V_61 ++ )
F_76 ( L_2 , F_65 ( V_74 + V_61 * 0x10 ) ) ;
F_76 ( L_3 ) ;
}
static void T_2 F_77 ( void * V_76 )
{
unsigned int V_61 , V_77 , V_78 , V_79 ;
T_5 V_80 ;
F_78 ( L_4 ,
F_62 () , F_79 () ) ;
V_77 = F_65 ( V_81 ) ;
F_80 ( L_5 , V_77 , F_81 () ) ;
V_77 = F_65 ( V_82 ) ;
F_80 ( L_6 , V_77 ) ;
V_78 = F_82 ( V_77 ) ;
V_79 = F_83 () ;
V_77 = F_65 ( V_83 ) ;
F_78 ( L_7 , V_77 , V_77 & V_84 ) ;
if ( F_84 ( V_78 ) ) {
if ( ! F_85 ( V_78 ) ) {
V_77 = F_65 ( V_85 ) ;
F_78 ( L_8 ,
V_77 , V_77 & V_86 ) ;
}
V_77 = F_65 ( V_87 ) ;
F_78 ( L_9 , V_77 ) ;
}
if ( ! F_84 ( V_78 ) || V_79 == 3 ) {
V_77 = F_65 ( V_88 ) ;
F_78 ( L_10 , V_77 ) ;
}
V_77 = F_65 ( V_89 ) ;
F_78 ( L_11 , V_77 ) ;
if ( ! F_86 () ) {
V_77 = F_65 ( V_90 ) ;
F_78 ( L_12 , V_77 ) ;
}
V_77 = F_65 ( V_91 ) ;
F_78 ( L_13 , V_77 ) ;
F_78 ( L_14 ) ;
F_74 ( V_92 ) ;
F_78 ( L_15 ) ;
F_74 ( V_93 ) ;
F_78 ( L_16 ) ;
F_74 ( V_69 ) ;
if ( F_84 ( V_78 ) ) {
if ( V_79 > 3 )
F_87 ( V_94 , 0 ) ;
V_77 = F_65 ( V_94 ) ;
F_78 ( L_17 , V_77 ) ;
}
V_80 = F_88 () ;
F_78 ( L_18 , ( V_95 ) V_80 ) ;
F_78 ( L_19 , ( V_95 ) ( V_80 >> 32 ) ) ;
V_77 = F_65 ( V_96 ) ;
F_78 ( L_20 , V_77 ) ;
if ( V_79 > 3 ) {
V_77 = F_65 ( V_97 ) ;
F_78 ( L_21 , V_77 ) ;
}
V_77 = F_65 ( V_98 ) ;
F_78 ( L_22 , V_77 ) ;
V_77 = F_65 ( V_99 ) ;
F_78 ( L_23 , V_77 ) ;
if ( V_79 > 2 ) {
V_77 = F_65 ( V_100 ) ;
F_78 ( L_24 , V_77 ) ;
}
V_77 = F_65 ( V_101 ) ;
F_78 ( L_25 , V_77 ) ;
V_77 = F_65 ( V_102 ) ;
F_78 ( L_26 , V_77 ) ;
V_77 = F_65 ( V_103 ) ;
F_78 ( L_27 , V_77 ) ;
if ( F_89 ( V_104 ) ) {
V_77 = F_65 ( V_105 ) ;
V_79 = ( V_77 >> 16 ) & 0xff ;
F_78 ( L_28 , V_77 ) ;
V_77 = F_65 ( V_106 ) ;
F_78 ( L_29 , V_77 ) ;
for ( V_61 = 0 ; V_61 < V_79 ; V_61 ++ ) {
V_77 = F_65 ( F_90 ( V_61 ) ) ;
F_78 ( L_30 , V_61 , V_77 ) ;
}
}
F_76 ( L_3 ) ;
}
static void T_2 F_91 ( int V_107 )
{
int V_23 ;
if ( ! V_107 )
return;
F_92 () ;
F_93 (cpu) {
if ( V_23 >= V_107 )
break;
F_94 ( V_23 , F_77 , NULL , 1 ) ;
}
F_95 () ;
}
static void T_2 F_96 ( void )
{
unsigned int V_77 ;
unsigned long V_43 ;
if ( ! F_41 () )
return;
F_78 ( L_31 ) ;
F_35 ( & V_108 , V_43 ) ;
V_77 = F_97 ( 0xa1 ) << 8 | F_97 ( 0x21 ) ;
F_78 ( L_32 , V_77 ) ;
V_77 = F_97 ( 0xa0 ) << 8 | F_97 ( 0x20 ) ;
F_78 ( L_33 , V_77 ) ;
F_98 ( 0x0b , 0xa0 ) ;
F_98 ( 0x0b , 0x20 ) ;
V_77 = F_97 ( 0xa0 ) << 8 | F_97 ( 0x20 ) ;
F_98 ( 0x0a , 0xa0 ) ;
F_98 ( 0x0a , 0x20 ) ;
F_36 ( & V_108 , V_43 ) ;
F_78 ( L_34 , V_77 ) ;
V_77 = F_97 ( 0x4d1 ) << 8 | F_97 ( 0x4d0 ) ;
F_78 ( L_35 , V_77 ) ;
}
static T_2 int F_99 ( char * V_109 )
{
int V_110 = - 1 ;
if ( strcmp ( V_109 , L_36 ) == 0 ) {
V_111 = V_112 ;
} else {
F_100 ( & V_109 , & V_110 ) ;
if ( V_110 >= 0 )
V_111 = V_110 ;
}
return 1 ;
}
static int T_2 F_101 ( void )
{
if ( V_113 == V_114 )
return 0 ;
F_96 () ;
if ( ! V_115 && ! F_102 () )
return 0 ;
F_91 ( V_111 ) ;
F_103 () ;
return 0 ;
}
