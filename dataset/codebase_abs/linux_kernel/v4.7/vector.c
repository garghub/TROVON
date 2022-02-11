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
if ( V_16 -> V_25 ||
F_14 ( V_16 -> V_14 , V_26 ) )
return - V_27 ;
F_15 ( V_16 -> V_14 ) ;
F_15 ( V_28 ) ;
V_23 = F_16 ( V_18 , V_26 ) ;
while ( V_23 < V_29 ) {
int V_30 , V_31 ;
V_32 -> V_33 ( V_23 , V_34 , V_18 ) ;
F_17 ( V_35 , V_34 , V_26 ) ;
if ( ! F_14 ( V_35 , V_18 ) )
goto V_36;
if ( F_18 ( V_34 , V_16 -> V_12 ) ) {
if ( F_19 ( V_34 , V_16 -> V_12 ) )
goto V_37;
F_20 ( V_16 -> V_14 , V_16 -> V_12 , V_34 ) ;
V_24 = V_16 -> V_8 . V_24 ;
goto V_38;
}
V_24 = V_19 ;
V_31 = V_22 ;
V_39:
V_24 += 16 ;
if ( V_24 >= V_40 ) {
V_31 = ( V_31 + 1 ) % 16 ;
V_24 = V_20 + V_31 ;
}
if ( F_21 ( V_19 == V_24 ) )
goto V_36;
if ( F_22 ( V_24 , V_41 ) )
goto V_39;
F_23 (new_cpu, vector_searchmask) {
if ( ! F_24 ( F_25 ( V_42 , V_30 ) [ V_24 ] ) )
goto V_39;
}
V_19 = V_24 ;
V_22 = V_31 ;
if ( V_16 -> V_8 . V_24 )
F_26 ( V_16 -> V_14 , V_16 -> V_12 ) ;
F_23 (new_cpu, vector_searchmask)
F_25 ( V_42 , V_30 ) [ V_24 ] = F_27 ( V_9 ) ;
goto V_38;
V_36:
F_28 ( V_28 , V_28 , V_34 ) ;
F_20 ( V_34 , V_18 , V_28 ) ;
V_23 = F_16 ( V_34 , V_26 ) ;
continue;
}
return - V_43 ;
V_38:
F_17 ( V_16 -> V_14 , V_16 -> V_14 , V_26 ) ;
V_16 -> V_25 = ! F_29 ( V_16 -> V_14 ) ;
V_16 -> V_8 . V_44 = V_16 -> V_25 ? V_16 -> V_8 . V_24 : 0 ;
V_16 -> V_8 . V_24 = V_24 ;
F_26 ( V_16 -> V_12 , V_34 ) ;
V_37:
F_30 ( V_32 -> V_45 ( V_18 , V_16 -> V_12 ,
& V_16 -> V_8 . V_46 ) ) ;
return 0 ;
}
static int F_31 ( int V_9 , struct V_2 * V_7 ,
const struct V_17 * V_18 )
{
int V_47 ;
unsigned long V_48 ;
F_32 ( & V_1 , V_48 ) ;
V_47 = F_13 ( V_9 , V_7 , V_18 ) ;
F_33 ( & V_1 , V_48 ) ;
return V_47 ;
}
static int F_34 ( int V_9 , int V_10 ,
struct V_2 * V_7 ,
struct V_49 * V_50 )
{
if ( V_50 && V_50 -> V_18 )
return F_31 ( V_9 , V_7 , V_50 -> V_18 ) ;
if ( V_10 != V_51 &&
F_31 ( V_9 , V_7 , F_35 ( V_10 ) ) == 0 )
return 0 ;
return F_31 ( V_9 , V_7 , V_32 -> V_52 () ) ;
}
static void F_36 ( int V_9 , struct V_2 * V_7 )
{
struct V_53 * V_54 ;
int V_23 , V_24 ;
if ( ! V_7 -> V_8 . V_24 )
return;
V_24 = V_7 -> V_8 . V_24 ;
F_37 (cpu, data->domain, cpu_online_mask)
F_25 ( V_42 , V_23 ) [ V_24 ] = V_55 ;
V_7 -> V_8 . V_24 = 0 ;
F_15 ( V_7 -> V_12 ) ;
if ( ! V_7 -> V_25 && F_29 ( V_7 -> V_14 ) )
return;
V_54 = F_27 ( V_9 ) ;
F_37 (cpu, data->old_domain, cpu_online_mask) {
for ( V_24 = V_20 ; V_24 < V_56 ;
V_24 ++ ) {
if ( F_25 ( V_42 , V_23 ) [ V_24 ] != V_54 )
continue;
F_25 ( V_42 , V_23 ) [ V_24 ] = V_55 ;
break;
}
}
V_7 -> V_25 = 0 ;
}
void F_38 ( struct V_49 * V_50 ,
const struct V_17 * V_18 )
{
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_18 = V_18 ;
}
void F_39 ( struct V_49 * V_57 , struct V_49 * V_58 )
{
if ( V_58 )
* V_57 = * V_58 ;
else
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
}
static void F_40 ( struct V_59 * V_12 ,
unsigned int V_60 , unsigned int V_61 )
{
struct V_2 * V_62 ;
struct V_3 * V_3 ;
unsigned long V_48 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ ) {
V_3 = F_41 ( V_64 , V_60 + V_63 ) ;
if ( V_3 && V_3 -> V_5 ) {
F_32 ( & V_1 , V_48 ) ;
F_36 ( V_60 + V_63 , V_3 -> V_5 ) ;
V_62 = V_3 -> V_5 ;
F_42 ( V_3 ) ;
F_33 ( & V_1 , V_48 ) ;
F_12 ( V_62 ) ;
#ifdef F_43
if ( V_60 + V_63 < F_44 () )
V_65 [ V_60 + V_63 ] = NULL ;
#endif
}
}
}
static int F_45 ( struct V_59 * V_12 , unsigned int V_60 ,
unsigned int V_61 , void * V_66 )
{
struct V_49 * V_50 = V_66 ;
struct V_2 * V_7 ;
struct V_3 * V_3 ;
int V_63 , V_47 , V_10 ;
if ( V_67 )
return - V_68 ;
if ( ( V_50 -> V_48 & V_69 ) && V_61 > 1 )
return - V_70 ;
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ ) {
V_3 = F_41 ( V_12 , V_60 + V_63 ) ;
F_30 ( ! V_3 ) ;
V_10 = F_46 ( V_3 ) ;
#ifdef F_43
if ( V_60 + V_63 < F_44 () && V_65 [ V_60 + V_63 ] )
V_7 = V_65 [ V_60 + V_63 ] ;
else
#endif
V_7 = F_7 ( V_10 ) ;
if ( ! V_7 ) {
V_47 = - V_71 ;
goto error;
}
V_3 -> V_72 = & V_73 ;
V_3 -> V_5 = V_7 ;
V_3 -> V_74 = V_60 + V_63 ;
V_47 = F_34 ( V_60 + V_63 , V_10 , V_7 , V_50 ) ;
if ( V_47 )
goto error;
}
return 0 ;
error:
F_40 ( V_12 , V_60 , V_63 + 1 ) ;
return V_47 ;
}
int T_1 F_47 ( void )
{
int V_75 ;
if ( V_61 > ( V_56 * V_29 ) )
V_61 = V_56 * V_29 ;
V_75 = ( V_76 + F_44 () ) + 8 * V_29 ;
#if F_48 ( V_77 ) || F_48 ( V_78 )
if ( V_76 <= V_79 )
V_75 += 8 * V_29 ;
else
V_75 += V_76 * 16 ;
#endif
if ( V_75 < V_61 )
V_61 = V_75 ;
return V_80 -> V_81 () ;
}
static void F_49 ( void )
{
int V_63 , V_10 = F_50 ( 0 ) ;
struct V_2 * V_7 ;
for ( V_63 = 0 ; V_63 < F_44 () ; V_63 ++ ) {
V_7 = V_65 [ V_63 ] = F_7 ( V_10 ) ;
F_30 ( ! V_7 ) ;
V_7 -> V_8 . V_24 = F_51 ( V_63 ) ;
F_52 ( V_7 -> V_12 ) ;
F_53 ( V_63 , V_7 ) ;
}
}
static void F_49 ( void ) { }
int T_1 F_54 ( void )
{
F_49 () ;
V_64 = F_55 ( NULL , & V_82 ,
NULL ) ;
F_30 ( V_64 == NULL ) ;
F_56 ( V_64 ) ;
F_57 ( V_64 ) ;
F_58 ( V_64 ) ;
F_30 ( ! F_59 ( & V_34 , V_11 ) ) ;
F_30 ( ! F_59 ( & V_35 , V_11 ) ) ;
F_30 ( ! F_59 ( & V_28 , V_11 ) ) ;
return F_60 () ;
}
static void F_61 ( int V_23 )
{
struct V_2 * V_7 ;
struct V_53 * V_54 ;
int V_9 , V_24 ;
F_62 (irq, desc) {
struct V_3 * V_83 = F_63 ( V_54 ) ;
V_7 = V_2 ( V_83 ) ;
if ( ! V_7 || ! F_64 ( V_23 , V_7 -> V_12 ) )
continue;
V_24 = V_7 -> V_8 . V_24 ;
F_25 ( V_42 , V_23 ) [ V_24 ] = V_54 ;
}
for ( V_24 = 0 ; V_24 < V_56 ; ++ V_24 ) {
V_54 = F_25 ( V_42 , V_23 ) [ V_24 ] ;
if ( F_24 ( V_54 ) )
continue;
V_7 = V_2 ( F_63 ( V_54 ) ) ;
if ( ! F_64 ( V_23 , V_7 -> V_12 ) )
F_25 ( V_42 , V_23 ) [ V_24 ] = V_55 ;
}
}
void F_65 ( int V_23 )
{
int V_9 ;
F_66 ( & V_1 ) ;
for ( V_9 = 0 ; V_9 < F_44 () ; V_9 ++ )
F_25 ( V_42 , V_23 ) [ F_51 ( V_9 ) ] = F_27 ( V_9 ) ;
F_61 ( V_23 ) ;
}
static int F_67 ( struct V_3 * V_3 )
{
struct V_2 * V_7 = V_2 ( V_3 ) ;
unsigned long V_48 ;
int V_23 ;
F_32 ( & V_1 , V_48 ) ;
V_23 = F_16 ( V_7 -> V_12 , V_26 ) ;
V_32 -> V_84 ( F_68 ( V_23 ) , V_7 -> V_8 . V_24 ) ;
F_33 ( & V_1 , V_48 ) ;
return 1 ;
}
void F_69 ( struct V_3 * V_7 )
{
F_70 ( F_5 ( V_7 ) ) ;
F_71 ( V_7 ) ;
F_72 () ;
}
static int F_73 ( struct V_3 * V_3 ,
const struct V_17 * V_85 , bool V_86 )
{
struct V_2 * V_7 = V_3 -> V_5 ;
int V_47 , V_9 = V_3 -> V_9 ;
if ( ! F_74 ( V_87 ) )
return - V_88 ;
if ( ! F_14 ( V_85 , V_26 ) )
return - V_89 ;
V_47 = F_31 ( V_9 , V_7 , V_85 ) ;
return V_47 ? V_47 : V_90 ;
}
static void F_75 ( struct V_2 * V_7 )
{
F_2 ( & V_1 ) ;
F_17 ( V_7 -> V_14 , V_7 -> V_14 , V_26 ) ;
V_7 -> V_25 = 0 ;
if ( ! F_29 ( V_7 -> V_14 ) )
V_32 -> V_84 ( V_7 -> V_14 , V_91 ) ;
F_4 ( & V_1 ) ;
}
void F_76 ( struct V_6 * V_8 )
{
struct V_2 * V_7 ;
V_7 = F_77 ( V_8 , struct V_2 , V_8 ) ;
if ( V_7 -> V_25 )
F_75 ( V_7 ) ;
}
T_2 T_3 void F_78 ( void )
{
unsigned V_24 , V_92 ;
F_79 () ;
F_2 ( & V_1 ) ;
V_92 = F_80 () ;
for ( V_24 = V_20 ; V_24 < V_56 ; V_24 ++ ) {
struct V_2 * V_7 ;
struct V_53 * V_54 ;
unsigned int V_93 ;
V_94:
V_54 = F_81 ( V_42 [ V_24 ] ) ;
if ( F_24 ( V_54 ) )
continue;
if ( ! F_82 ( & V_54 -> V_95 ) ) {
F_4 ( & V_1 ) ;
F_83 () ;
F_2 ( & V_1 ) ;
goto V_94;
}
V_7 = V_2 ( F_63 ( V_54 ) ) ;
if ( ! V_7 )
goto V_96;
if ( V_7 -> V_25 ||
! F_64 ( V_92 , V_7 -> V_14 ) )
goto V_96;
if ( V_24 == V_7 -> V_8 . V_24 &&
F_64 ( V_92 , V_7 -> V_12 ) )
goto V_96;
V_93 = F_84 ( V_97 + ( V_24 / 32 * 0x10 ) ) ;
if ( V_93 & ( 1 << ( V_24 % 32 ) ) ) {
V_32 -> V_98 ( V_91 ) ;
goto V_96;
}
F_85 ( V_42 [ V_24 ] , V_55 ) ;
F_86 ( V_92 , V_7 -> V_14 ) ;
V_96:
F_4 ( & V_54 -> V_95 ) ;
}
F_4 ( & V_1 ) ;
F_87 () ;
}
static void F_88 ( struct V_6 * V_8 , unsigned V_24 )
{
unsigned V_92 ;
struct V_2 * V_7 ;
V_7 = F_77 ( V_8 , struct V_2 , V_8 ) ;
if ( F_89 ( ! V_7 -> V_25 ) )
return;
V_92 = F_80 () ;
if ( V_24 == V_7 -> V_8 . V_24 && F_64 ( V_92 , V_7 -> V_12 ) )
F_75 ( V_7 ) ;
}
void F_70 ( struct V_6 * V_8 )
{
F_88 ( V_8 , ~ F_90 () -> V_99 ) ;
}
void F_91 ( struct V_53 * V_54 )
{
struct V_3 * V_100 = F_63 ( V_54 ) ;
struct V_2 * V_7 = V_2 ( V_100 ) ;
struct V_6 * V_8 = V_7 ? & V_7 -> V_8 : NULL ;
unsigned int V_23 ;
if ( ! V_8 )
return;
F_2 ( & V_1 ) ;
F_17 ( V_7 -> V_14 , V_7 -> V_14 , V_26 ) ;
if ( ! V_7 -> V_25 && F_29 ( V_7 -> V_14 ) ) {
F_4 ( & V_1 ) ;
return;
}
if ( V_7 -> V_25 ) {
F_92 ( L_1 ,
V_100 -> V_9 , V_8 -> V_44 ) ;
}
F_23 (cpu, data->old_domain)
F_25 ( V_42 , V_23 ) [ V_8 -> V_44 ] = V_55 ;
F_15 ( V_7 -> V_14 ) ;
V_7 -> V_25 = 0 ;
F_4 ( & V_1 ) ;
}
static void T_1 F_93 ( int V_101 )
{
int V_63 ;
F_94 ( V_102 ) ;
for ( V_63 = 0 ; V_63 < 8 ; V_63 ++ )
F_95 ( L_2 , F_84 ( V_101 + V_63 * 0x10 ) ) ;
F_95 ( L_3 ) ;
}
static void T_1 F_96 ( void * V_103 )
{
unsigned int V_63 , V_104 , V_105 , V_106 ;
T_4 V_107 ;
F_97 ( L_4 ,
F_80 () , F_98 () ) ;
V_104 = F_84 ( V_108 ) ;
F_99 ( L_5 , V_104 , F_100 () ) ;
V_104 = F_84 ( V_109 ) ;
F_99 ( L_6 , V_104 ) ;
V_105 = F_101 ( V_104 ) ;
V_106 = F_102 () ;
V_104 = F_84 ( V_110 ) ;
F_97 ( L_7 , V_104 , V_104 & V_111 ) ;
if ( F_103 ( V_105 ) ) {
if ( ! F_104 ( V_105 ) ) {
V_104 = F_84 ( V_112 ) ;
F_97 ( L_8 ,
V_104 , V_104 & V_113 ) ;
}
V_104 = F_84 ( V_114 ) ;
F_97 ( L_9 , V_104 ) ;
}
if ( ! F_103 ( V_105 ) || V_106 == 3 ) {
V_104 = F_84 ( V_115 ) ;
F_97 ( L_10 , V_104 ) ;
}
V_104 = F_84 ( V_116 ) ;
F_97 ( L_11 , V_104 ) ;
if ( ! F_105 () ) {
V_104 = F_84 ( V_117 ) ;
F_97 ( L_12 , V_104 ) ;
}
V_104 = F_84 ( V_118 ) ;
F_97 ( L_13 , V_104 ) ;
F_97 ( L_14 ) ;
F_93 ( V_119 ) ;
F_97 ( L_15 ) ;
F_93 ( V_120 ) ;
F_97 ( L_16 ) ;
F_93 ( V_97 ) ;
if ( F_103 ( V_105 ) ) {
if ( V_106 > 3 )
F_106 ( V_121 , 0 ) ;
V_104 = F_84 ( V_121 ) ;
F_97 ( L_17 , V_104 ) ;
}
V_107 = F_107 () ;
F_97 ( L_18 , ( V_122 ) V_107 ) ;
F_97 ( L_19 , ( V_122 ) ( V_107 >> 32 ) ) ;
V_104 = F_84 ( V_123 ) ;
F_97 ( L_20 , V_104 ) ;
if ( V_106 > 3 ) {
V_104 = F_84 ( V_124 ) ;
F_97 ( L_21 , V_104 ) ;
}
V_104 = F_84 ( V_125 ) ;
F_97 ( L_22 , V_104 ) ;
V_104 = F_84 ( V_126 ) ;
F_97 ( L_23 , V_104 ) ;
if ( V_106 > 2 ) {
V_104 = F_84 ( V_127 ) ;
F_97 ( L_24 , V_104 ) ;
}
V_104 = F_84 ( V_128 ) ;
F_97 ( L_25 , V_104 ) ;
V_104 = F_84 ( V_129 ) ;
F_97 ( L_26 , V_104 ) ;
V_104 = F_84 ( V_130 ) ;
F_97 ( L_27 , V_104 ) ;
if ( F_108 ( V_131 ) ) {
V_104 = F_84 ( V_132 ) ;
V_106 = ( V_104 >> 16 ) & 0xff ;
F_97 ( L_28 , V_104 ) ;
V_104 = F_84 ( V_133 ) ;
F_97 ( L_29 , V_104 ) ;
for ( V_63 = 0 ; V_63 < V_106 ; V_63 ++ ) {
V_104 = F_84 ( F_109 ( V_63 ) ) ;
F_97 ( L_30 , V_63 , V_104 ) ;
}
}
F_95 ( L_3 ) ;
}
static void T_1 F_110 ( int V_134 )
{
int V_23 ;
if ( ! V_134 )
return;
F_111 () ;
F_112 (cpu) {
if ( V_23 >= V_134 )
break;
F_113 ( V_23 , F_96 , NULL , 1 ) ;
}
F_114 () ;
}
static void T_1 F_115 ( void )
{
unsigned int V_104 ;
unsigned long V_48 ;
if ( ! F_44 () )
return;
F_97 ( L_31 ) ;
F_32 ( & V_135 , V_48 ) ;
V_104 = F_116 ( 0xa1 ) << 8 | F_116 ( 0x21 ) ;
F_97 ( L_32 , V_104 ) ;
V_104 = F_116 ( 0xa0 ) << 8 | F_116 ( 0x20 ) ;
F_97 ( L_33 , V_104 ) ;
F_117 ( 0x0b , 0xa0 ) ;
F_117 ( 0x0b , 0x20 ) ;
V_104 = F_116 ( 0xa0 ) << 8 | F_116 ( 0x20 ) ;
F_117 ( 0x0a , 0xa0 ) ;
F_117 ( 0x0a , 0x20 ) ;
F_33 ( & V_135 , V_48 ) ;
F_97 ( L_34 , V_104 ) ;
V_104 = F_116 ( 0x4d1 ) << 8 | F_116 ( 0x4d0 ) ;
F_97 ( L_35 , V_104 ) ;
}
static T_1 int F_118 ( char * V_66 )
{
int V_136 = - 1 ;
if ( strcmp ( V_66 , L_36 ) == 0 ) {
V_137 = V_138 ;
} else {
F_119 ( & V_66 , & V_136 ) ;
if ( V_136 >= 0 )
V_137 = V_136 ;
}
return 1 ;
}
static int T_1 F_120 ( void )
{
if ( V_139 == V_140 )
return 0 ;
F_115 () ;
if ( ! F_108 ( V_141 ) && ! F_121 () )
return 0 ;
F_110 ( V_137 ) ;
F_122 () ;
return 0 ;
}
