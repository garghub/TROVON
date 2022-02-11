void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static struct V_2 * V_2 ( struct V_3 * V_3 )
{
if ( ! V_3 )
return NULL ;
while ( V_3 -> V_4 )
V_3 = V_3 -> V_4 ;
return V_3 -> V_5 ;
}
struct V_6 * F_5 ( struct V_3 * V_3 )
{
struct V_2 * V_7 = V_2 ( V_3 ) ;
return V_7 ? & V_7 -> V_8 : NULL ;
}
struct V_6 * V_6 ( unsigned int V_9 )
{
return F_5 ( F_6 ( V_9 ) ) ;
}
static struct V_2 * F_7 ( int V_10 )
{
struct V_2 * V_7 ;
V_7 = F_8 ( sizeof( * V_7 ) , V_11 , V_10 ) ;
if ( ! V_7 )
return NULL ;
if ( ! F_9 ( & V_7 -> V_12 , V_11 , V_10 ) )
goto V_13;
if ( ! F_9 ( & V_7 -> V_14 , V_11 , V_10 ) )
goto V_15;
return V_7 ;
V_15:
F_10 ( V_7 -> V_12 ) ;
V_13:
F_11 ( V_7 ) ;
return NULL ;
}
static void F_12 ( struct V_2 * V_7 )
{
if ( V_7 ) {
F_10 ( V_7 -> V_12 ) ;
F_10 ( V_7 -> V_14 ) ;
F_11 ( V_7 ) ;
}
}
static int F_13 ( int V_9 , struct V_2 * V_16 ,
const struct V_17 * V_18 )
{
static int V_19 = V_20 + V_21 ;
static int V_22 = V_21 % 16 ;
int V_23 , V_24 ;
if ( V_16 -> V_25 )
return - V_26 ;
V_24 = - V_27 ;
F_14 ( V_16 -> V_14 ) ;
V_23 = F_15 ( V_18 , V_28 ) ;
while ( V_23 < V_29 ) {
int V_30 , V_31 , V_32 ;
V_33 -> V_34 ( V_23 , V_35 , V_18 ) ;
if ( F_16 ( V_35 , V_16 -> V_12 ) ) {
V_24 = 0 ;
if ( F_17 ( V_35 , V_16 -> V_12 ) )
break;
F_18 ( V_16 -> V_14 , V_16 -> V_12 ,
V_35 ) ;
V_16 -> V_25 =
F_19 ( V_16 -> V_14 , V_28 ) ;
F_20 ( V_16 -> V_12 , V_16 -> V_12 , V_35 ) ;
break;
}
V_31 = V_19 ;
V_32 = V_22 ;
V_36:
V_31 += 16 ;
if ( V_31 >= V_37 ) {
V_32 = ( V_32 + 1 ) % 16 ;
V_31 = V_20 + V_32 ;
}
if ( F_21 ( V_19 == V_31 ) ) {
F_22 ( V_16 -> V_14 , V_16 -> V_14 ,
V_35 ) ;
F_18 ( V_35 , V_18 , V_16 -> V_14 ) ;
V_23 = F_15 ( V_35 ,
V_28 ) ;
continue;
}
if ( F_23 ( V_31 , V_38 ) )
goto V_36;
F_24 (new_cpu, vector_cpumask, cpu_online_mask) {
if ( F_25 ( V_39 , V_30 ) [ V_31 ] >
V_40 )
goto V_36;
}
V_19 = V_31 ;
V_22 = V_32 ;
if ( V_16 -> V_8 . V_31 ) {
F_26 ( V_16 -> V_14 , V_16 -> V_12 ) ;
V_16 -> V_25 =
F_19 ( V_16 -> V_14 , V_28 ) ;
}
F_24 (new_cpu, vector_cpumask, cpu_online_mask)
F_25 ( V_39 , V_30 ) [ V_31 ] = V_9 ;
V_16 -> V_8 . V_31 = V_31 ;
F_26 ( V_16 -> V_12 , V_35 ) ;
V_24 = 0 ;
break;
}
if ( ! V_24 ) {
V_24 = V_33 -> V_41 ( V_18 , V_16 -> V_12 ,
& V_16 -> V_8 . V_42 ) ;
}
return V_24 ;
}
static int F_27 ( int V_9 , struct V_2 * V_7 ,
const struct V_17 * V_18 )
{
int V_24 ;
unsigned long V_43 ;
F_28 ( & V_1 , V_43 ) ;
V_24 = F_13 ( V_9 , V_7 , V_18 ) ;
F_29 ( & V_1 , V_43 ) ;
return V_24 ;
}
static int F_30 ( int V_9 , int V_10 ,
struct V_2 * V_7 ,
struct V_44 * V_45 )
{
if ( V_45 && V_45 -> V_18 )
return F_27 ( V_9 , V_7 , V_45 -> V_18 ) ;
if ( V_10 != V_46 &&
F_27 ( V_9 , V_7 , F_31 ( V_10 ) ) == 0 )
return 0 ;
return F_27 ( V_9 , V_7 , V_33 -> V_47 () ) ;
}
static void F_32 ( int V_9 , struct V_2 * V_7 )
{
int V_23 , V_31 ;
unsigned long V_43 ;
F_28 ( & V_1 , V_43 ) ;
F_33 ( ! V_7 -> V_8 . V_31 ) ;
V_31 = V_7 -> V_8 . V_31 ;
F_24 (cpu, data->domain, cpu_online_mask)
F_25 ( V_39 , V_23 ) [ V_31 ] = V_40 ;
V_7 -> V_8 . V_31 = 0 ;
F_14 ( V_7 -> V_12 ) ;
if ( F_34 ( ! V_7 -> V_25 ) ) {
F_29 ( & V_1 , V_43 ) ;
return;
}
F_24 (cpu, data->old_domain, cpu_online_mask) {
for ( V_31 = V_20 ; V_31 < V_48 ;
V_31 ++ ) {
if ( F_25 ( V_39 , V_23 ) [ V_31 ] != V_9 )
continue;
F_25 ( V_39 , V_23 ) [ V_31 ] = V_40 ;
break;
}
}
V_7 -> V_25 = 0 ;
F_29 ( & V_1 , V_43 ) ;
}
void F_35 ( struct V_44 * V_45 ,
const struct V_17 * V_18 )
{
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_18 = V_18 ;
}
void F_36 ( struct V_44 * V_49 , struct V_44 * V_50 )
{
if ( V_50 )
* V_49 = * V_50 ;
else
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
}
static void F_37 ( struct V_51 * V_12 ,
unsigned int V_52 , unsigned int V_53 )
{
struct V_3 * V_3 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
V_3 = F_38 ( V_55 , V_52 + V_54 ) ;
if ( V_3 && V_3 -> V_5 ) {
F_32 ( V_52 + V_54 , V_3 -> V_5 ) ;
F_12 ( V_3 -> V_5 ) ;
#ifdef F_39
if ( V_52 + V_54 < F_40 () )
V_56 [ V_52 + V_54 ] = NULL ;
#endif
F_41 ( V_3 ) ;
}
}
}
static int F_42 ( struct V_51 * V_12 , unsigned int V_52 ,
unsigned int V_53 , void * V_57 )
{
struct V_44 * V_45 = V_57 ;
struct V_2 * V_7 ;
struct V_3 * V_3 ;
int V_54 , V_24 ;
if ( V_58 )
return - V_59 ;
if ( ( V_45 -> V_43 & V_60 ) && V_53 > 1 )
return - V_61 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
V_3 = F_38 ( V_12 , V_52 + V_54 ) ;
F_33 ( ! V_3 ) ;
#ifdef F_39
if ( V_52 + V_54 < F_40 () && V_56 [ V_52 + V_54 ] )
V_7 = V_56 [ V_52 + V_54 ] ;
else
#endif
V_7 = F_7 ( V_3 -> V_10 ) ;
if ( ! V_7 ) {
V_24 = - V_62 ;
goto error;
}
V_3 -> V_63 = & V_64 ;
V_3 -> V_5 = V_7 ;
V_3 -> V_65 = V_52 + V_54 ;
V_24 = F_30 ( V_52 + V_54 , V_3 -> V_10 , V_7 ,
V_45 ) ;
if ( V_24 )
goto error;
}
return 0 ;
error:
F_37 ( V_12 , V_52 , V_54 + 1 ) ;
return V_24 ;
}
int T_1 F_43 ( void )
{
int V_66 ;
if ( V_53 > ( V_48 * V_29 ) )
V_53 = V_48 * V_29 ;
V_66 = ( V_67 + F_40 () ) + 8 * V_29 ;
#if F_44 ( V_68 ) || F_44 ( V_69 )
if ( V_67 <= V_70 )
V_66 += 8 * V_29 ;
else
V_66 += V_67 * 16 ;
#endif
if ( V_66 < V_53 )
V_53 = V_66 ;
return F_40 () ;
}
static void F_45 ( void )
{
int V_54 , V_10 = F_46 ( 0 ) ;
struct V_2 * V_7 ;
for ( V_54 = 0 ; V_54 < F_40 () ; V_54 ++ ) {
V_7 = V_56 [ V_54 ] = F_7 ( V_10 ) ;
F_33 ( ! V_7 ) ;
V_7 -> V_8 . V_31 = F_47 ( V_54 ) ;
F_48 ( V_7 -> V_12 ) ;
F_49 ( V_54 , V_7 ) ;
}
}
static void F_45 ( void ) { }
int T_1 F_50 ( void )
{
F_45 () ;
V_55 = F_51 ( NULL , & V_71 ,
NULL ) ;
F_33 ( V_55 == NULL ) ;
F_52 ( V_55 ) ;
F_53 ( V_55 ) ;
F_54 ( V_55 ) ;
F_33 ( ! F_55 ( & V_35 , V_11 ) ) ;
return F_56 () ;
}
static void F_57 ( int V_23 )
{
int V_9 , V_31 ;
struct V_2 * V_7 ;
F_58 (irq) {
V_7 = V_2 ( F_6 ( V_9 ) ) ;
if ( ! V_7 )
continue;
if ( ! F_59 ( V_23 , V_7 -> V_12 ) )
continue;
V_31 = V_7 -> V_8 . V_31 ;
F_25 ( V_39 , V_23 ) [ V_31 ] = V_9 ;
}
for ( V_31 = 0 ; V_31 < V_48 ; ++ V_31 ) {
V_9 = F_25 ( V_39 , V_23 ) [ V_31 ] ;
if ( V_9 <= V_40 )
continue;
V_7 = V_2 ( F_6 ( V_9 ) ) ;
if ( ! F_59 ( V_23 , V_7 -> V_12 ) )
F_25 ( V_39 , V_23 ) [ V_31 ] = V_40 ;
}
}
void F_60 ( int V_23 )
{
int V_9 ;
F_61 ( & V_1 ) ;
for ( V_9 = 0 ; V_9 < F_40 () ; V_9 ++ )
F_25 ( V_39 , V_23 ) [ F_47 ( V_9 ) ] = V_9 ;
F_57 ( V_23 ) ;
}
static int F_62 ( struct V_3 * V_3 )
{
struct V_2 * V_7 = V_2 ( V_3 ) ;
unsigned long V_43 ;
int V_23 ;
F_28 ( & V_1 , V_43 ) ;
V_23 = F_15 ( V_7 -> V_12 , V_28 ) ;
V_33 -> V_72 ( F_63 ( V_23 ) , V_7 -> V_8 . V_31 ) ;
F_29 ( & V_1 , V_43 ) ;
return 1 ;
}
void F_64 ( struct V_3 * V_7 )
{
F_65 ( F_5 ( V_7 ) ) ;
F_66 ( V_7 ) ;
F_67 () ;
}
static int F_68 ( struct V_3 * V_3 ,
const struct V_17 * V_73 , bool V_74 )
{
struct V_2 * V_7 = V_3 -> V_5 ;
int V_24 , V_9 = V_3 -> V_9 ;
if ( ! F_69 ( V_75 ) )
return - V_76 ;
if ( ! F_19 ( V_73 , V_28 ) )
return - V_77 ;
V_24 = F_27 ( V_9 , V_7 , V_73 ) ;
if ( V_24 ) {
struct V_3 * V_78 = F_6 ( V_9 ) ;
if ( F_27 ( V_9 , V_7 , V_78 -> V_79 ) )
F_70 ( L_1 , V_9 ) ;
return V_24 ;
}
return V_80 ;
}
static void F_71 ( struct V_2 * V_7 )
{
T_2 V_81 ;
if ( F_21 ( ! F_55 ( & V_81 , V_82 ) ) ) {
unsigned int V_54 ;
F_24 (i, data->old_domain, cpu_online_mask)
V_33 -> V_72 ( F_63 ( V_54 ) ,
V_83 ) ;
} else {
F_20 ( V_81 , V_7 -> V_14 , V_28 ) ;
V_33 -> V_72 ( V_81 , V_83 ) ;
F_10 ( V_81 ) ;
}
V_7 -> V_25 = 0 ;
}
void F_72 ( struct V_6 * V_8 )
{
struct V_2 * V_7 ;
V_7 = F_73 ( V_8 , struct V_2 , V_8 ) ;
if ( V_7 -> V_25 )
F_71 ( V_7 ) ;
}
T_3 T_4 void F_74 ( void )
{
unsigned V_31 , V_84 ;
F_75 () ;
V_84 = F_76 () ;
for ( V_31 = V_20 ; V_31 < V_48 ; V_31 ++ ) {
int V_9 ;
unsigned int V_85 ;
struct V_86 * V_87 ;
struct V_2 * V_7 ;
V_9 = F_77 ( V_39 [ V_31 ] ) ;
if ( V_9 <= V_40 )
continue;
V_87 = F_78 ( V_9 ) ;
if ( ! V_87 )
continue;
V_7 = V_2 ( & V_87 -> V_3 ) ;
if ( ! V_7 )
continue;
F_2 ( & V_87 -> V_88 ) ;
if ( V_7 -> V_25 )
goto V_89;
if ( V_31 == V_7 -> V_8 . V_31 &&
F_59 ( V_84 , V_7 -> V_12 ) )
goto V_89;
V_85 = F_79 ( V_90 + ( V_31 / 32 * 0x10 ) ) ;
if ( V_85 & ( 1 << ( V_31 % 32 ) ) ) {
V_33 -> V_91 ( V_83 ) ;
goto V_89;
}
F_80 ( V_39 [ V_31 ] , V_40 ) ;
V_89:
F_4 ( & V_87 -> V_88 ) ;
}
F_81 () ;
}
static void F_82 ( struct V_6 * V_8 , unsigned V_31 )
{
unsigned V_84 ;
struct V_2 * V_7 ;
V_7 = F_73 ( V_8 , struct V_2 , V_8 ) ;
if ( F_34 ( ! V_7 -> V_25 ) )
return;
V_84 = F_76 () ;
if ( V_31 == V_7 -> V_8 . V_31 && F_59 ( V_84 , V_7 -> V_12 ) )
F_71 ( V_7 ) ;
}
void F_65 ( struct V_6 * V_8 )
{
F_82 ( V_8 , ~ F_83 () -> V_92 ) ;
}
void F_84 ( int V_9 )
{
struct V_6 * V_8 = V_6 ( V_9 ) ;
if ( V_8 )
F_82 ( V_8 , V_8 -> V_31 ) ;
}
static void T_1 F_85 ( int V_93 )
{
int V_54 ;
F_86 ( V_94 ) ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ )
F_87 ( L_2 , F_79 ( V_93 + V_54 * 0x10 ) ) ;
F_87 ( L_3 ) ;
}
static void T_1 F_88 ( void * V_95 )
{
unsigned int V_54 , V_96 , V_97 , V_98 ;
T_5 V_99 ;
F_89 ( L_4 ,
F_76 () , F_90 () ) ;
V_96 = F_79 ( V_100 ) ;
F_91 ( L_5 , V_96 , F_92 () ) ;
V_96 = F_79 ( V_101 ) ;
F_91 ( L_6 , V_96 ) ;
V_97 = F_93 ( V_96 ) ;
V_98 = F_94 () ;
V_96 = F_79 ( V_102 ) ;
F_89 ( L_7 , V_96 , V_96 & V_103 ) ;
if ( F_95 ( V_97 ) ) {
if ( ! F_96 ( V_97 ) ) {
V_96 = F_79 ( V_104 ) ;
F_89 ( L_8 ,
V_96 , V_96 & V_105 ) ;
}
V_96 = F_79 ( V_106 ) ;
F_89 ( L_9 , V_96 ) ;
}
if ( ! F_95 ( V_97 ) || V_98 == 3 ) {
V_96 = F_79 ( V_107 ) ;
F_89 ( L_10 , V_96 ) ;
}
V_96 = F_79 ( V_108 ) ;
F_89 ( L_11 , V_96 ) ;
if ( ! F_97 () ) {
V_96 = F_79 ( V_109 ) ;
F_89 ( L_12 , V_96 ) ;
}
V_96 = F_79 ( V_110 ) ;
F_89 ( L_13 , V_96 ) ;
F_89 ( L_14 ) ;
F_85 ( V_111 ) ;
F_89 ( L_15 ) ;
F_85 ( V_112 ) ;
F_89 ( L_16 ) ;
F_85 ( V_90 ) ;
if ( F_95 ( V_97 ) ) {
if ( V_98 > 3 )
F_98 ( V_113 , 0 ) ;
V_96 = F_79 ( V_113 ) ;
F_89 ( L_17 , V_96 ) ;
}
V_99 = F_99 () ;
F_89 ( L_18 , ( V_114 ) V_99 ) ;
F_89 ( L_19 , ( V_114 ) ( V_99 >> 32 ) ) ;
V_96 = F_79 ( V_115 ) ;
F_89 ( L_20 , V_96 ) ;
if ( V_98 > 3 ) {
V_96 = F_79 ( V_116 ) ;
F_89 ( L_21 , V_96 ) ;
}
V_96 = F_79 ( V_117 ) ;
F_89 ( L_22 , V_96 ) ;
V_96 = F_79 ( V_118 ) ;
F_89 ( L_23 , V_96 ) ;
if ( V_98 > 2 ) {
V_96 = F_79 ( V_119 ) ;
F_89 ( L_24 , V_96 ) ;
}
V_96 = F_79 ( V_120 ) ;
F_89 ( L_25 , V_96 ) ;
V_96 = F_79 ( V_121 ) ;
F_89 ( L_26 , V_96 ) ;
V_96 = F_79 ( V_122 ) ;
F_89 ( L_27 , V_96 ) ;
if ( F_100 ( V_123 ) ) {
V_96 = F_79 ( V_124 ) ;
V_98 = ( V_96 >> 16 ) & 0xff ;
F_89 ( L_28 , V_96 ) ;
V_96 = F_79 ( V_125 ) ;
F_89 ( L_29 , V_96 ) ;
for ( V_54 = 0 ; V_54 < V_98 ; V_54 ++ ) {
V_96 = F_79 ( F_101 ( V_54 ) ) ;
F_89 ( L_30 , V_54 , V_96 ) ;
}
}
F_87 ( L_3 ) ;
}
static void T_1 F_102 ( int V_126 )
{
int V_23 ;
if ( ! V_126 )
return;
F_103 () ;
F_104 (cpu) {
if ( V_23 >= V_126 )
break;
F_105 ( V_23 , F_88 , NULL , 1 ) ;
}
F_106 () ;
}
static void T_1 F_107 ( void )
{
unsigned int V_96 ;
unsigned long V_43 ;
if ( ! F_40 () )
return;
F_89 ( L_31 ) ;
F_28 ( & V_127 , V_43 ) ;
V_96 = F_108 ( 0xa1 ) << 8 | F_108 ( 0x21 ) ;
F_89 ( L_32 , V_96 ) ;
V_96 = F_108 ( 0xa0 ) << 8 | F_108 ( 0x20 ) ;
F_89 ( L_33 , V_96 ) ;
F_109 ( 0x0b , 0xa0 ) ;
F_109 ( 0x0b , 0x20 ) ;
V_96 = F_108 ( 0xa0 ) << 8 | F_108 ( 0x20 ) ;
F_109 ( 0x0a , 0xa0 ) ;
F_109 ( 0x0a , 0x20 ) ;
F_29 ( & V_127 , V_43 ) ;
F_89 ( L_34 , V_96 ) ;
V_96 = F_108 ( 0x4d1 ) << 8 | F_108 ( 0x4d0 ) ;
F_89 ( L_35 , V_96 ) ;
}
static T_1 int F_110 ( char * V_57 )
{
int V_128 = - 1 ;
if ( strcmp ( V_57 , L_36 ) == 0 ) {
V_129 = V_130 ;
} else {
F_111 ( & V_57 , & V_128 ) ;
if ( V_128 >= 0 )
V_129 = V_128 ;
}
return 1 ;
}
static int T_1 F_112 ( void )
{
if ( V_131 == V_132 )
return 0 ;
F_107 () ;
if ( ! V_133 && ! F_113 () )
return 0 ;
F_102 ( V_129 ) ;
F_114 () ;
return 0 ;
}
