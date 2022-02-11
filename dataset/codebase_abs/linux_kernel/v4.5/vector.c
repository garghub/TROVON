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
V_16 -> V_8 . V_24 = V_24 ;
F_26 ( V_16 -> V_12 , V_34 ) ;
V_37:
F_30 ( V_32 -> V_44 ( V_18 , V_16 -> V_12 ,
& V_16 -> V_8 . V_45 ) ) ;
return 0 ;
}
static int F_31 ( int V_9 , struct V_2 * V_7 ,
const struct V_17 * V_18 )
{
int V_46 ;
unsigned long V_47 ;
F_32 ( & V_1 , V_47 ) ;
V_46 = F_13 ( V_9 , V_7 , V_18 ) ;
F_33 ( & V_1 , V_47 ) ;
return V_46 ;
}
static int F_34 ( int V_9 , int V_10 ,
struct V_2 * V_7 ,
struct V_48 * V_49 )
{
if ( V_49 && V_49 -> V_18 )
return F_31 ( V_9 , V_7 , V_49 -> V_18 ) ;
if ( V_10 != V_50 &&
F_31 ( V_9 , V_7 , F_35 ( V_10 ) ) == 0 )
return 0 ;
return F_31 ( V_9 , V_7 , V_32 -> V_51 () ) ;
}
static void F_36 ( int V_9 , struct V_2 * V_7 )
{
struct V_52 * V_53 ;
int V_23 , V_24 ;
F_30 ( ! V_7 -> V_8 . V_24 ) ;
V_24 = V_7 -> V_8 . V_24 ;
F_37 (cpu, data->domain, cpu_online_mask)
F_25 ( V_42 , V_23 ) [ V_24 ] = V_54 ;
V_7 -> V_8 . V_24 = 0 ;
F_15 ( V_7 -> V_12 ) ;
if ( ! V_7 -> V_25 && F_29 ( V_7 -> V_14 ) )
return;
V_53 = F_27 ( V_9 ) ;
F_37 (cpu, data->old_domain, cpu_online_mask) {
for ( V_24 = V_20 ; V_24 < V_55 ;
V_24 ++ ) {
if ( F_25 ( V_42 , V_23 ) [ V_24 ] != V_53 )
continue;
F_25 ( V_42 , V_23 ) [ V_24 ] = V_54 ;
break;
}
}
V_7 -> V_25 = 0 ;
}
void F_38 ( struct V_48 * V_49 ,
const struct V_17 * V_18 )
{
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_18 = V_18 ;
}
void F_39 ( struct V_48 * V_56 , struct V_48 * V_57 )
{
if ( V_57 )
* V_56 = * V_57 ;
else
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
}
static void F_40 ( struct V_58 * V_12 ,
unsigned int V_59 , unsigned int V_60 )
{
struct V_2 * V_61 ;
struct V_3 * V_3 ;
unsigned long V_47 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_60 ; V_62 ++ ) {
V_3 = F_41 ( V_63 , V_59 + V_62 ) ;
if ( V_3 && V_3 -> V_5 ) {
F_32 ( & V_1 , V_47 ) ;
F_36 ( V_59 + V_62 , V_3 -> V_5 ) ;
V_61 = V_3 -> V_5 ;
F_42 ( V_3 ) ;
F_33 ( & V_1 , V_47 ) ;
F_12 ( V_61 ) ;
#ifdef F_43
if ( V_59 + V_62 < F_44 () )
V_64 [ V_59 + V_62 ] = NULL ;
#endif
}
}
}
static int F_45 ( struct V_58 * V_12 , unsigned int V_59 ,
unsigned int V_60 , void * V_65 )
{
struct V_48 * V_49 = V_65 ;
struct V_2 * V_7 ;
struct V_3 * V_3 ;
int V_62 , V_46 , V_10 ;
if ( V_66 )
return - V_67 ;
if ( ( V_49 -> V_47 & V_68 ) && V_60 > 1 )
return - V_69 ;
for ( V_62 = 0 ; V_62 < V_60 ; V_62 ++ ) {
V_3 = F_41 ( V_12 , V_59 + V_62 ) ;
F_30 ( ! V_3 ) ;
V_10 = F_46 ( V_3 ) ;
#ifdef F_43
if ( V_59 + V_62 < F_44 () && V_64 [ V_59 + V_62 ] )
V_7 = V_64 [ V_59 + V_62 ] ;
else
#endif
V_7 = F_7 ( V_10 ) ;
if ( ! V_7 ) {
V_46 = - V_70 ;
goto error;
}
V_3 -> V_71 = & V_72 ;
V_3 -> V_5 = V_7 ;
V_3 -> V_73 = V_59 + V_62 ;
V_46 = F_34 ( V_59 + V_62 , V_10 , V_7 , V_49 ) ;
if ( V_46 )
goto error;
}
return 0 ;
error:
F_40 ( V_12 , V_59 , V_62 + 1 ) ;
return V_46 ;
}
int T_1 F_47 ( void )
{
int V_74 ;
if ( V_60 > ( V_55 * V_29 ) )
V_60 = V_55 * V_29 ;
V_74 = ( V_75 + F_44 () ) + 8 * V_29 ;
#if F_48 ( V_76 ) || F_48 ( V_77 )
if ( V_75 <= V_78 )
V_74 += 8 * V_29 ;
else
V_74 += V_75 * 16 ;
#endif
if ( V_74 < V_60 )
V_60 = V_74 ;
return V_79 -> V_80 () ;
}
static void F_49 ( void )
{
int V_62 , V_10 = F_50 ( 0 ) ;
struct V_2 * V_7 ;
for ( V_62 = 0 ; V_62 < F_44 () ; V_62 ++ ) {
V_7 = V_64 [ V_62 ] = F_7 ( V_10 ) ;
F_30 ( ! V_7 ) ;
V_7 -> V_8 . V_24 = F_51 ( V_62 ) ;
F_52 ( V_7 -> V_12 ) ;
F_53 ( V_62 , V_7 ) ;
}
}
static void F_49 ( void ) { }
int T_1 F_54 ( void )
{
F_49 () ;
V_63 = F_55 ( NULL , & V_81 ,
NULL ) ;
F_30 ( V_63 == NULL ) ;
F_56 ( V_63 ) ;
F_57 ( V_63 ) ;
F_58 ( V_63 ) ;
F_30 ( ! F_59 ( & V_34 , V_11 ) ) ;
F_30 ( ! F_59 ( & V_35 , V_11 ) ) ;
F_30 ( ! F_59 ( & V_28 , V_11 ) ) ;
return F_60 () ;
}
static void F_61 ( int V_23 )
{
struct V_2 * V_7 ;
struct V_52 * V_53 ;
int V_9 , V_24 ;
F_62 (irq, desc) {
struct V_3 * V_82 = F_63 ( V_53 ) ;
V_7 = V_2 ( V_82 ) ;
if ( ! V_7 || ! F_64 ( V_23 , V_7 -> V_12 ) )
continue;
V_24 = V_7 -> V_8 . V_24 ;
F_25 ( V_42 , V_23 ) [ V_24 ] = V_53 ;
}
for ( V_24 = 0 ; V_24 < V_55 ; ++ V_24 ) {
V_53 = F_25 ( V_42 , V_23 ) [ V_24 ] ;
if ( F_24 ( V_53 ) )
continue;
V_7 = V_2 ( F_63 ( V_53 ) ) ;
if ( ! F_64 ( V_23 , V_7 -> V_12 ) )
F_25 ( V_42 , V_23 ) [ V_24 ] = V_54 ;
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
unsigned long V_47 ;
int V_23 ;
F_32 ( & V_1 , V_47 ) ;
V_23 = F_16 ( V_7 -> V_12 , V_26 ) ;
V_32 -> V_83 ( F_68 ( V_23 ) , V_7 -> V_8 . V_24 ) ;
F_33 ( & V_1 , V_47 ) ;
return 1 ;
}
void F_69 ( struct V_3 * V_7 )
{
F_70 ( F_5 ( V_7 ) ) ;
F_71 ( V_7 ) ;
F_72 () ;
}
static int F_73 ( struct V_3 * V_3 ,
const struct V_17 * V_84 , bool V_85 )
{
struct V_2 * V_7 = V_3 -> V_5 ;
int V_46 , V_9 = V_3 -> V_9 ;
if ( ! F_74 ( V_86 ) )
return - V_87 ;
if ( ! F_14 ( V_84 , V_26 ) )
return - V_88 ;
V_46 = F_31 ( V_9 , V_7 , V_84 ) ;
return V_46 ? V_46 : V_89 ;
}
static void F_75 ( struct V_2 * V_7 )
{
F_2 ( & V_1 ) ;
F_17 ( V_7 -> V_14 , V_7 -> V_14 , V_26 ) ;
V_7 -> V_25 = 0 ;
if ( ! F_29 ( V_7 -> V_14 ) )
V_32 -> V_83 ( V_7 -> V_14 , V_90 ) ;
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
unsigned V_24 , V_91 ;
F_79 () ;
F_2 ( & V_1 ) ;
V_91 = F_80 () ;
for ( V_24 = V_20 ; V_24 < V_55 ; V_24 ++ ) {
struct V_2 * V_7 ;
struct V_52 * V_53 ;
unsigned int V_92 ;
V_93:
V_53 = F_81 ( V_42 [ V_24 ] ) ;
if ( F_24 ( V_53 ) )
continue;
if ( ! F_82 ( & V_53 -> V_94 ) ) {
F_4 ( & V_1 ) ;
F_83 () ;
F_2 ( & V_1 ) ;
goto V_93;
}
V_7 = V_2 ( F_63 ( V_53 ) ) ;
if ( ! V_7 )
goto V_95;
if ( V_7 -> V_25 ||
! F_64 ( V_91 , V_7 -> V_14 ) )
goto V_95;
if ( V_24 == V_7 -> V_8 . V_24 &&
F_64 ( V_91 , V_7 -> V_12 ) )
goto V_95;
V_92 = F_84 ( V_96 + ( V_24 / 32 * 0x10 ) ) ;
if ( V_92 & ( 1 << ( V_24 % 32 ) ) ) {
V_32 -> V_97 ( V_90 ) ;
goto V_95;
}
F_85 ( V_42 [ V_24 ] , V_54 ) ;
F_86 ( V_91 , V_7 -> V_14 ) ;
V_95:
F_4 ( & V_53 -> V_94 ) ;
}
F_4 ( & V_1 ) ;
F_87 () ;
}
static void F_88 ( struct V_6 * V_8 , unsigned V_24 )
{
unsigned V_91 ;
struct V_2 * V_7 ;
V_7 = F_77 ( V_8 , struct V_2 , V_8 ) ;
if ( F_89 ( ! V_7 -> V_25 ) )
return;
V_91 = F_80 () ;
if ( V_24 == V_7 -> V_8 . V_24 && F_64 ( V_91 , V_7 -> V_12 ) )
F_75 ( V_7 ) ;
}
void F_70 ( struct V_6 * V_8 )
{
F_88 ( V_8 , ~ F_90 () -> V_98 ) ;
}
void F_91 ( struct V_52 * V_53 )
{
struct V_3 * V_99 = F_63 ( V_53 ) ;
struct V_2 * V_7 = V_2 ( V_99 ) ;
struct V_6 * V_8 = V_7 ? & V_7 -> V_8 : NULL ;
if ( ! V_8 )
return;
F_88 ( V_8 , V_8 -> V_24 ) ;
F_2 ( & V_1 ) ;
F_17 ( V_7 -> V_14 , V_7 -> V_14 , V_26 ) ;
while ( ! F_29 ( V_7 -> V_14 ) ) {
F_4 ( & V_1 ) ;
F_4 ( & V_53 -> V_94 ) ;
F_83 () ;
F_2 ( & V_53 -> V_94 ) ;
V_7 = V_2 ( V_99 ) ;
if ( ! V_7 )
return;
F_2 ( & V_1 ) ;
}
F_4 ( & V_1 ) ;
}
static void T_1 F_92 ( int V_100 )
{
int V_62 ;
F_93 ( V_101 ) ;
for ( V_62 = 0 ; V_62 < 8 ; V_62 ++ )
F_94 ( L_1 , F_84 ( V_100 + V_62 * 0x10 ) ) ;
F_94 ( L_2 ) ;
}
static void T_1 F_95 ( void * V_102 )
{
unsigned int V_62 , V_103 , V_104 , V_105 ;
T_4 V_106 ;
F_96 ( L_3 ,
F_80 () , F_97 () ) ;
V_103 = F_84 ( V_107 ) ;
F_98 ( L_4 , V_103 , F_99 () ) ;
V_103 = F_84 ( V_108 ) ;
F_98 ( L_5 , V_103 ) ;
V_104 = F_100 ( V_103 ) ;
V_105 = F_101 () ;
V_103 = F_84 ( V_109 ) ;
F_96 ( L_6 , V_103 , V_103 & V_110 ) ;
if ( F_102 ( V_104 ) ) {
if ( ! F_103 ( V_104 ) ) {
V_103 = F_84 ( V_111 ) ;
F_96 ( L_7 ,
V_103 , V_103 & V_112 ) ;
}
V_103 = F_84 ( V_113 ) ;
F_96 ( L_8 , V_103 ) ;
}
if ( ! F_102 ( V_104 ) || V_105 == 3 ) {
V_103 = F_84 ( V_114 ) ;
F_96 ( L_9 , V_103 ) ;
}
V_103 = F_84 ( V_115 ) ;
F_96 ( L_10 , V_103 ) ;
if ( ! F_104 () ) {
V_103 = F_84 ( V_116 ) ;
F_96 ( L_11 , V_103 ) ;
}
V_103 = F_84 ( V_117 ) ;
F_96 ( L_12 , V_103 ) ;
F_96 ( L_13 ) ;
F_92 ( V_118 ) ;
F_96 ( L_14 ) ;
F_92 ( V_119 ) ;
F_96 ( L_15 ) ;
F_92 ( V_96 ) ;
if ( F_102 ( V_104 ) ) {
if ( V_105 > 3 )
F_105 ( V_120 , 0 ) ;
V_103 = F_84 ( V_120 ) ;
F_96 ( L_16 , V_103 ) ;
}
V_106 = F_106 () ;
F_96 ( L_17 , ( V_121 ) V_106 ) ;
F_96 ( L_18 , ( V_121 ) ( V_106 >> 32 ) ) ;
V_103 = F_84 ( V_122 ) ;
F_96 ( L_19 , V_103 ) ;
if ( V_105 > 3 ) {
V_103 = F_84 ( V_123 ) ;
F_96 ( L_20 , V_103 ) ;
}
V_103 = F_84 ( V_124 ) ;
F_96 ( L_21 , V_103 ) ;
V_103 = F_84 ( V_125 ) ;
F_96 ( L_22 , V_103 ) ;
if ( V_105 > 2 ) {
V_103 = F_84 ( V_126 ) ;
F_96 ( L_23 , V_103 ) ;
}
V_103 = F_84 ( V_127 ) ;
F_96 ( L_24 , V_103 ) ;
V_103 = F_84 ( V_128 ) ;
F_96 ( L_25 , V_103 ) ;
V_103 = F_84 ( V_129 ) ;
F_96 ( L_26 , V_103 ) ;
if ( F_107 ( V_130 ) ) {
V_103 = F_84 ( V_131 ) ;
V_105 = ( V_103 >> 16 ) & 0xff ;
F_96 ( L_27 , V_103 ) ;
V_103 = F_84 ( V_132 ) ;
F_96 ( L_28 , V_103 ) ;
for ( V_62 = 0 ; V_62 < V_105 ; V_62 ++ ) {
V_103 = F_84 ( F_108 ( V_62 ) ) ;
F_96 ( L_29 , V_62 , V_103 ) ;
}
}
F_94 ( L_2 ) ;
}
static void T_1 F_109 ( int V_133 )
{
int V_23 ;
if ( ! V_133 )
return;
F_110 () ;
F_111 (cpu) {
if ( V_23 >= V_133 )
break;
F_112 ( V_23 , F_95 , NULL , 1 ) ;
}
F_113 () ;
}
static void T_1 F_114 ( void )
{
unsigned int V_103 ;
unsigned long V_47 ;
if ( ! F_44 () )
return;
F_96 ( L_30 ) ;
F_32 ( & V_134 , V_47 ) ;
V_103 = F_115 ( 0xa1 ) << 8 | F_115 ( 0x21 ) ;
F_96 ( L_31 , V_103 ) ;
V_103 = F_115 ( 0xa0 ) << 8 | F_115 ( 0x20 ) ;
F_96 ( L_32 , V_103 ) ;
F_116 ( 0x0b , 0xa0 ) ;
F_116 ( 0x0b , 0x20 ) ;
V_103 = F_115 ( 0xa0 ) << 8 | F_115 ( 0x20 ) ;
F_116 ( 0x0a , 0xa0 ) ;
F_116 ( 0x0a , 0x20 ) ;
F_33 ( & V_134 , V_47 ) ;
F_96 ( L_33 , V_103 ) ;
V_103 = F_115 ( 0x4d1 ) << 8 | F_115 ( 0x4d0 ) ;
F_96 ( L_34 , V_103 ) ;
}
static T_1 int F_117 ( char * V_65 )
{
int V_135 = - 1 ;
if ( strcmp ( V_65 , L_35 ) == 0 ) {
V_136 = V_137 ;
} else {
F_118 ( & V_65 , & V_135 ) ;
if ( V_135 >= 0 )
V_136 = V_135 ;
}
return 1 ;
}
static int T_1 F_119 ( void )
{
if ( V_138 == V_139 )
return 0 ;
F_114 () ;
if ( ! V_140 && ! F_120 () )
return 0 ;
F_109 ( V_136 ) ;
F_121 () ;
return 0 ;
}
