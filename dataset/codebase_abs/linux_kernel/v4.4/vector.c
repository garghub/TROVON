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
if ( ! F_25 ( F_26 ( V_39 , V_30 ) [ V_31 ] ) )
goto V_36;
}
V_19 = V_31 ;
V_22 = V_32 ;
if ( V_16 -> V_8 . V_31 ) {
F_27 ( V_16 -> V_14 , V_16 -> V_12 ) ;
V_16 -> V_25 =
F_19 ( V_16 -> V_14 , V_28 ) ;
}
F_24 (new_cpu, vector_cpumask, cpu_online_mask)
F_26 ( V_39 , V_30 ) [ V_31 ] = F_28 ( V_9 ) ;
V_16 -> V_8 . V_31 = V_31 ;
F_27 ( V_16 -> V_12 , V_35 ) ;
V_24 = 0 ;
break;
}
if ( ! V_24 ) {
V_24 = V_33 -> V_40 ( V_18 , V_16 -> V_12 ,
& V_16 -> V_8 . V_41 ) ;
}
return V_24 ;
}
static int F_29 ( int V_9 , struct V_2 * V_7 ,
const struct V_17 * V_18 )
{
int V_24 ;
unsigned long V_42 ;
F_30 ( & V_1 , V_42 ) ;
V_24 = F_13 ( V_9 , V_7 , V_18 ) ;
F_31 ( & V_1 , V_42 ) ;
return V_24 ;
}
static int F_32 ( int V_9 , int V_10 ,
struct V_2 * V_7 ,
struct V_43 * V_44 )
{
if ( V_44 && V_44 -> V_18 )
return F_29 ( V_9 , V_7 , V_44 -> V_18 ) ;
if ( V_10 != V_45 &&
F_29 ( V_9 , V_7 , F_33 ( V_10 ) ) == 0 )
return 0 ;
return F_29 ( V_9 , V_7 , V_33 -> V_46 () ) ;
}
static void F_34 ( int V_9 , struct V_2 * V_7 )
{
struct V_47 * V_48 ;
unsigned long V_42 ;
int V_23 , V_31 ;
F_30 ( & V_1 , V_42 ) ;
F_35 ( ! V_7 -> V_8 . V_31 ) ;
V_31 = V_7 -> V_8 . V_31 ;
F_24 (cpu, data->domain, cpu_online_mask)
F_26 ( V_39 , V_23 ) [ V_31 ] = V_49 ;
V_7 -> V_8 . V_31 = 0 ;
F_14 ( V_7 -> V_12 ) ;
if ( F_36 ( ! V_7 -> V_25 ) ) {
F_31 ( & V_1 , V_42 ) ;
return;
}
V_48 = F_28 ( V_9 ) ;
F_24 (cpu, data->old_domain, cpu_online_mask) {
for ( V_31 = V_20 ; V_31 < V_50 ;
V_31 ++ ) {
if ( F_26 ( V_39 , V_23 ) [ V_31 ] != V_48 )
continue;
F_26 ( V_39 , V_23 ) [ V_31 ] = V_49 ;
break;
}
}
V_7 -> V_25 = 0 ;
F_31 ( & V_1 , V_42 ) ;
}
void F_37 ( struct V_43 * V_44 ,
const struct V_17 * V_18 )
{
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_18 = V_18 ;
}
void F_38 ( struct V_43 * V_51 , struct V_43 * V_52 )
{
if ( V_52 )
* V_51 = * V_52 ;
else
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
}
static void F_39 ( struct V_53 * V_12 ,
unsigned int V_54 , unsigned int V_55 )
{
struct V_3 * V_3 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
V_3 = F_40 ( V_57 , V_54 + V_56 ) ;
if ( V_3 && V_3 -> V_5 ) {
F_34 ( V_54 + V_56 , V_3 -> V_5 ) ;
F_12 ( V_3 -> V_5 ) ;
#ifdef F_41
if ( V_54 + V_56 < F_42 () )
V_58 [ V_54 + V_56 ] = NULL ;
#endif
F_43 ( V_3 ) ;
}
}
}
static int F_44 ( struct V_53 * V_12 , unsigned int V_54 ,
unsigned int V_55 , void * V_59 )
{
struct V_43 * V_44 = V_59 ;
struct V_2 * V_7 ;
struct V_3 * V_3 ;
int V_56 , V_24 , V_10 ;
if ( V_60 )
return - V_61 ;
if ( ( V_44 -> V_42 & V_62 ) && V_55 > 1 )
return - V_63 ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
V_3 = F_40 ( V_12 , V_54 + V_56 ) ;
F_35 ( ! V_3 ) ;
V_10 = F_45 ( V_3 ) ;
#ifdef F_41
if ( V_54 + V_56 < F_42 () && V_58 [ V_54 + V_56 ] )
V_7 = V_58 [ V_54 + V_56 ] ;
else
#endif
V_7 = F_7 ( V_10 ) ;
if ( ! V_7 ) {
V_24 = - V_64 ;
goto error;
}
V_3 -> V_65 = & V_66 ;
V_3 -> V_5 = V_7 ;
V_3 -> V_67 = V_54 + V_56 ;
V_24 = F_32 ( V_54 + V_56 , V_10 , V_7 , V_44 ) ;
if ( V_24 )
goto error;
}
return 0 ;
error:
F_39 ( V_12 , V_54 , V_56 + 1 ) ;
return V_24 ;
}
int T_1 F_46 ( void )
{
int V_68 ;
if ( V_55 > ( V_50 * V_29 ) )
V_55 = V_50 * V_29 ;
V_68 = ( V_69 + F_42 () ) + 8 * V_29 ;
#if F_47 ( V_70 ) || F_47 ( V_71 )
if ( V_69 <= V_72 )
V_68 += 8 * V_29 ;
else
V_68 += V_69 * 16 ;
#endif
if ( V_68 < V_55 )
V_55 = V_68 ;
return V_73 -> V_74 () ;
}
static void F_48 ( void )
{
int V_56 , V_10 = F_49 ( 0 ) ;
struct V_2 * V_7 ;
for ( V_56 = 0 ; V_56 < F_42 () ; V_56 ++ ) {
V_7 = V_58 [ V_56 ] = F_7 ( V_10 ) ;
F_35 ( ! V_7 ) ;
V_7 -> V_8 . V_31 = F_50 ( V_56 ) ;
F_51 ( V_7 -> V_12 ) ;
F_52 ( V_56 , V_7 ) ;
}
}
static void F_48 ( void ) { }
int T_1 F_53 ( void )
{
F_48 () ;
V_57 = F_54 ( NULL , & V_75 ,
NULL ) ;
F_35 ( V_57 == NULL ) ;
F_55 ( V_57 ) ;
F_56 ( V_57 ) ;
F_57 ( V_57 ) ;
F_35 ( ! F_58 ( & V_35 , V_11 ) ) ;
return F_59 () ;
}
static void F_60 ( int V_23 )
{
struct V_2 * V_7 ;
struct V_47 * V_48 ;
int V_9 , V_31 ;
F_61 (irq, desc) {
struct V_3 * V_76 = F_62 ( V_48 ) ;
V_7 = V_2 ( V_76 ) ;
if ( ! V_7 || ! F_63 ( V_23 , V_7 -> V_12 ) )
continue;
V_31 = V_7 -> V_8 . V_31 ;
F_26 ( V_39 , V_23 ) [ V_31 ] = V_48 ;
}
for ( V_31 = 0 ; V_31 < V_50 ; ++ V_31 ) {
V_48 = F_26 ( V_39 , V_23 ) [ V_31 ] ;
if ( F_25 ( V_48 ) )
continue;
V_7 = V_2 ( F_62 ( V_48 ) ) ;
if ( ! F_63 ( V_23 , V_7 -> V_12 ) )
F_26 ( V_39 , V_23 ) [ V_31 ] = V_49 ;
}
}
void F_64 ( int V_23 )
{
int V_9 ;
F_65 ( & V_1 ) ;
for ( V_9 = 0 ; V_9 < F_42 () ; V_9 ++ )
F_26 ( V_39 , V_23 ) [ F_50 ( V_9 ) ] = F_28 ( V_9 ) ;
F_60 ( V_23 ) ;
}
static int F_66 ( struct V_3 * V_3 )
{
struct V_2 * V_7 = V_2 ( V_3 ) ;
unsigned long V_42 ;
int V_23 ;
F_30 ( & V_1 , V_42 ) ;
V_23 = F_15 ( V_7 -> V_12 , V_28 ) ;
V_33 -> V_77 ( F_67 ( V_23 ) , V_7 -> V_8 . V_31 ) ;
F_31 ( & V_1 , V_42 ) ;
return 1 ;
}
void F_68 ( struct V_3 * V_7 )
{
F_69 ( F_5 ( V_7 ) ) ;
F_70 ( V_7 ) ;
F_71 () ;
}
static int F_72 ( struct V_3 * V_3 ,
const struct V_17 * V_78 , bool V_79 )
{
struct V_2 * V_7 = V_3 -> V_5 ;
int V_24 , V_9 = V_3 -> V_9 ;
if ( ! F_73 ( V_80 ) )
return - V_81 ;
if ( ! F_19 ( V_78 , V_28 ) )
return - V_82 ;
V_24 = F_29 ( V_9 , V_7 , V_78 ) ;
if ( V_24 ) {
if ( F_29 ( V_9 , V_7 ,
F_74 ( V_3 ) ) )
F_75 ( L_1 , V_9 ) ;
return V_24 ;
}
return V_83 ;
}
static void F_76 ( struct V_2 * V_7 )
{
T_2 V_84 ;
if ( F_21 ( ! F_58 ( & V_84 , V_85 ) ) ) {
unsigned int V_56 ;
F_24 (i, data->old_domain, cpu_online_mask)
V_33 -> V_77 ( F_67 ( V_56 ) ,
V_86 ) ;
} else {
F_20 ( V_84 , V_7 -> V_14 , V_28 ) ;
V_33 -> V_77 ( V_84 , V_86 ) ;
F_10 ( V_84 ) ;
}
V_7 -> V_25 = 0 ;
}
void F_77 ( struct V_6 * V_8 )
{
struct V_2 * V_7 ;
V_7 = F_78 ( V_8 , struct V_2 , V_8 ) ;
if ( V_7 -> V_25 )
F_76 ( V_7 ) ;
}
T_3 T_4 void F_79 ( void )
{
unsigned V_31 , V_87 ;
F_80 () ;
F_2 ( & V_1 ) ;
V_87 = F_81 () ;
for ( V_31 = V_20 ; V_31 < V_50 ; V_31 ++ ) {
struct V_2 * V_7 ;
struct V_47 * V_48 ;
unsigned int V_88 ;
V_89:
V_48 = F_82 ( V_39 [ V_31 ] ) ;
if ( F_25 ( V_48 ) )
continue;
if ( ! F_83 ( & V_48 -> V_90 ) ) {
F_4 ( & V_1 ) ;
F_84 () ;
F_2 ( & V_1 ) ;
goto V_89;
}
V_7 = V_2 ( F_62 ( V_48 ) ) ;
if ( ! V_7 )
goto V_91;
if ( V_7 -> V_25 )
goto V_91;
if ( V_31 == V_7 -> V_8 . V_31 &&
F_63 ( V_87 , V_7 -> V_12 ) )
goto V_91;
V_88 = F_85 ( V_92 + ( V_31 / 32 * 0x10 ) ) ;
if ( V_88 & ( 1 << ( V_31 % 32 ) ) ) {
V_33 -> V_93 ( V_86 ) ;
goto V_91;
}
F_86 ( V_39 [ V_31 ] , V_49 ) ;
V_91:
F_4 ( & V_48 -> V_90 ) ;
}
F_4 ( & V_1 ) ;
F_87 () ;
}
static void F_88 ( struct V_6 * V_8 , unsigned V_31 )
{
unsigned V_87 ;
struct V_2 * V_7 ;
V_7 = F_78 ( V_8 , struct V_2 , V_8 ) ;
if ( F_36 ( ! V_7 -> V_25 ) )
return;
V_87 = F_81 () ;
if ( V_31 == V_7 -> V_8 . V_31 && F_63 ( V_87 , V_7 -> V_12 ) )
F_76 ( V_7 ) ;
}
void F_69 ( struct V_6 * V_8 )
{
F_88 ( V_8 , ~ F_89 () -> V_94 ) ;
}
void F_90 ( int V_9 )
{
struct V_6 * V_8 = V_6 ( V_9 ) ;
if ( V_8 )
F_88 ( V_8 , V_8 -> V_31 ) ;
}
static void T_1 F_91 ( int V_95 )
{
int V_56 ;
F_92 ( V_96 ) ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ )
F_93 ( L_2 , F_85 ( V_95 + V_56 * 0x10 ) ) ;
F_93 ( L_3 ) ;
}
static void T_1 F_94 ( void * V_97 )
{
unsigned int V_56 , V_98 , V_99 , V_100 ;
T_5 V_101 ;
F_95 ( L_4 ,
F_81 () , F_96 () ) ;
V_98 = F_85 ( V_102 ) ;
F_97 ( L_5 , V_98 , F_98 () ) ;
V_98 = F_85 ( V_103 ) ;
F_97 ( L_6 , V_98 ) ;
V_99 = F_99 ( V_98 ) ;
V_100 = F_100 () ;
V_98 = F_85 ( V_104 ) ;
F_95 ( L_7 , V_98 , V_98 & V_105 ) ;
if ( F_101 ( V_99 ) ) {
if ( ! F_102 ( V_99 ) ) {
V_98 = F_85 ( V_106 ) ;
F_95 ( L_8 ,
V_98 , V_98 & V_107 ) ;
}
V_98 = F_85 ( V_108 ) ;
F_95 ( L_9 , V_98 ) ;
}
if ( ! F_101 ( V_99 ) || V_100 == 3 ) {
V_98 = F_85 ( V_109 ) ;
F_95 ( L_10 , V_98 ) ;
}
V_98 = F_85 ( V_110 ) ;
F_95 ( L_11 , V_98 ) ;
if ( ! F_103 () ) {
V_98 = F_85 ( V_111 ) ;
F_95 ( L_12 , V_98 ) ;
}
V_98 = F_85 ( V_112 ) ;
F_95 ( L_13 , V_98 ) ;
F_95 ( L_14 ) ;
F_91 ( V_113 ) ;
F_95 ( L_15 ) ;
F_91 ( V_114 ) ;
F_95 ( L_16 ) ;
F_91 ( V_92 ) ;
if ( F_101 ( V_99 ) ) {
if ( V_100 > 3 )
F_104 ( V_115 , 0 ) ;
V_98 = F_85 ( V_115 ) ;
F_95 ( L_17 , V_98 ) ;
}
V_101 = F_105 () ;
F_95 ( L_18 , ( V_116 ) V_101 ) ;
F_95 ( L_19 , ( V_116 ) ( V_101 >> 32 ) ) ;
V_98 = F_85 ( V_117 ) ;
F_95 ( L_20 , V_98 ) ;
if ( V_100 > 3 ) {
V_98 = F_85 ( V_118 ) ;
F_95 ( L_21 , V_98 ) ;
}
V_98 = F_85 ( V_119 ) ;
F_95 ( L_22 , V_98 ) ;
V_98 = F_85 ( V_120 ) ;
F_95 ( L_23 , V_98 ) ;
if ( V_100 > 2 ) {
V_98 = F_85 ( V_121 ) ;
F_95 ( L_24 , V_98 ) ;
}
V_98 = F_85 ( V_122 ) ;
F_95 ( L_25 , V_98 ) ;
V_98 = F_85 ( V_123 ) ;
F_95 ( L_26 , V_98 ) ;
V_98 = F_85 ( V_124 ) ;
F_95 ( L_27 , V_98 ) ;
if ( F_106 ( V_125 ) ) {
V_98 = F_85 ( V_126 ) ;
V_100 = ( V_98 >> 16 ) & 0xff ;
F_95 ( L_28 , V_98 ) ;
V_98 = F_85 ( V_127 ) ;
F_95 ( L_29 , V_98 ) ;
for ( V_56 = 0 ; V_56 < V_100 ; V_56 ++ ) {
V_98 = F_85 ( F_107 ( V_56 ) ) ;
F_95 ( L_30 , V_56 , V_98 ) ;
}
}
F_93 ( L_3 ) ;
}
static void T_1 F_108 ( int V_128 )
{
int V_23 ;
if ( ! V_128 )
return;
F_109 () ;
F_110 (cpu) {
if ( V_23 >= V_128 )
break;
F_111 ( V_23 , F_94 , NULL , 1 ) ;
}
F_112 () ;
}
static void T_1 F_113 ( void )
{
unsigned int V_98 ;
unsigned long V_42 ;
if ( ! F_42 () )
return;
F_95 ( L_31 ) ;
F_30 ( & V_129 , V_42 ) ;
V_98 = F_114 ( 0xa1 ) << 8 | F_114 ( 0x21 ) ;
F_95 ( L_32 , V_98 ) ;
V_98 = F_114 ( 0xa0 ) << 8 | F_114 ( 0x20 ) ;
F_95 ( L_33 , V_98 ) ;
F_115 ( 0x0b , 0xa0 ) ;
F_115 ( 0x0b , 0x20 ) ;
V_98 = F_114 ( 0xa0 ) << 8 | F_114 ( 0x20 ) ;
F_115 ( 0x0a , 0xa0 ) ;
F_115 ( 0x0a , 0x20 ) ;
F_31 ( & V_129 , V_42 ) ;
F_95 ( L_34 , V_98 ) ;
V_98 = F_114 ( 0x4d1 ) << 8 | F_114 ( 0x4d0 ) ;
F_95 ( L_35 , V_98 ) ;
}
static T_1 int F_116 ( char * V_59 )
{
int V_130 = - 1 ;
if ( strcmp ( V_59 , L_36 ) == 0 ) {
V_131 = V_132 ;
} else {
F_117 ( & V_59 , & V_130 ) ;
if ( V_130 >= 0 )
V_131 = V_130 ;
}
return 1 ;
}
static int T_1 F_118 ( void )
{
if ( V_133 == V_134 )
return 0 ;
F_113 () ;
if ( ! V_135 && ! F_119 () )
return 0 ;
F_108 ( V_131 ) ;
F_120 () ;
return 0 ;
}
