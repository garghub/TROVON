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
const struct V_17 * V_18 ,
struct V_3 * V_19 )
{
static int V_20 = V_21 + V_22 ;
static int V_23 = V_22 % 16 ;
int V_24 , V_25 ;
if ( V_16 -> V_26 ||
F_14 ( V_16 -> V_14 , V_27 ) )
return - V_28 ;
F_15 ( V_16 -> V_14 ) ;
F_15 ( V_29 ) ;
V_24 = F_16 ( V_18 , V_27 ) ;
while ( V_24 < V_30 ) {
int V_31 , V_32 ;
V_33 -> V_34 ( V_24 , V_35 , V_18 ) ;
F_17 ( V_36 , V_35 , V_27 ) ;
if ( ! F_14 ( V_36 , V_18 ) )
goto V_37;
if ( F_18 ( V_35 , V_16 -> V_12 ) ) {
if ( F_19 ( V_35 , V_16 -> V_12 ) )
goto V_38;
F_20 ( V_16 -> V_14 , V_16 -> V_12 , V_35 ) ;
V_25 = V_16 -> V_8 . V_25 ;
goto V_39;
}
V_25 = V_20 ;
V_32 = V_23 ;
V_40:
V_25 += 16 ;
if ( V_25 >= V_41 ) {
V_32 = ( V_32 + 1 ) % 16 ;
V_25 = V_21 + V_32 ;
}
if ( F_21 ( V_20 == V_25 ) )
goto V_37;
if ( F_22 ( V_25 , V_42 ) )
goto V_40;
F_23 (new_cpu, vector_searchmask) {
if ( ! F_24 ( F_25 ( V_43 , V_31 ) [ V_25 ] ) )
goto V_40;
}
V_20 = V_25 ;
V_23 = V_32 ;
if ( V_16 -> V_8 . V_25 )
F_26 ( V_16 -> V_14 , V_16 -> V_12 ) ;
F_23 (new_cpu, vector_searchmask)
F_25 ( V_43 , V_31 ) [ V_25 ] = F_27 ( V_9 ) ;
goto V_39;
V_37:
F_28 ( V_29 , V_29 , V_35 ) ;
F_20 ( V_35 , V_18 , V_29 ) ;
V_24 = F_16 ( V_35 , V_27 ) ;
continue;
}
return - V_44 ;
V_39:
F_17 ( V_16 -> V_14 , V_16 -> V_14 , V_27 ) ;
V_16 -> V_26 = ! F_29 ( V_16 -> V_14 ) ;
V_16 -> V_8 . V_45 = V_16 -> V_26 ? V_16 -> V_8 . V_25 : 0 ;
V_16 -> V_8 . V_25 = V_25 ;
F_26 ( V_16 -> V_12 , V_35 ) ;
V_38:
F_17 ( V_36 , V_36 , V_18 ) ;
F_30 ( V_33 -> V_46 ( V_36 , V_19 ,
& V_16 -> V_8 . V_47 ) ) ;
return 0 ;
}
static int F_31 ( int V_9 , struct V_2 * V_7 ,
const struct V_17 * V_18 ,
struct V_3 * V_19 )
{
int V_48 ;
unsigned long V_49 ;
F_32 ( & V_1 , V_49 ) ;
V_48 = F_13 ( V_9 , V_7 , V_18 , V_19 ) ;
F_33 ( & V_1 , V_49 ) ;
return V_48 ;
}
static int F_34 ( int V_9 , int V_10 ,
struct V_2 * V_7 ,
struct V_50 * V_51 ,
struct V_3 * V_19 )
{
if ( V_51 && V_51 -> V_18 )
return F_31 ( V_9 , V_7 , V_51 -> V_18 , V_19 ) ;
if ( V_10 != V_52 &&
F_31 ( V_9 , V_7 , F_35 ( V_10 ) , V_19 ) == 0 )
return 0 ;
return F_31 ( V_9 , V_7 , V_33 -> V_53 () , V_19 ) ;
}
static void F_36 ( int V_9 , struct V_2 * V_7 )
{
struct V_54 * V_55 ;
int V_24 , V_25 ;
if ( ! V_7 -> V_8 . V_25 )
return;
V_25 = V_7 -> V_8 . V_25 ;
F_37 (cpu, data->domain, cpu_online_mask)
F_25 ( V_43 , V_24 ) [ V_25 ] = V_56 ;
V_7 -> V_8 . V_25 = 0 ;
F_15 ( V_7 -> V_12 ) ;
if ( ! V_7 -> V_26 && F_29 ( V_7 -> V_14 ) )
return;
V_55 = F_27 ( V_9 ) ;
F_37 (cpu, data->old_domain, cpu_online_mask) {
for ( V_25 = V_21 ; V_25 < V_57 ;
V_25 ++ ) {
if ( F_25 ( V_43 , V_24 ) [ V_25 ] != V_55 )
continue;
F_25 ( V_43 , V_24 ) [ V_25 ] = V_56 ;
break;
}
}
V_7 -> V_26 = 0 ;
}
void F_38 ( struct V_50 * V_51 ,
const struct V_17 * V_18 )
{
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_51 -> V_18 = V_18 ;
}
void F_39 ( struct V_50 * V_58 , struct V_50 * V_59 )
{
if ( V_59 )
* V_58 = * V_59 ;
else
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
}
static void F_40 ( struct V_60 * V_12 ,
unsigned int V_61 , unsigned int V_62 )
{
struct V_2 * V_63 ;
struct V_3 * V_3 ;
unsigned long V_49 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
V_3 = F_41 ( V_65 , V_61 + V_64 ) ;
if ( V_3 && V_3 -> V_5 ) {
F_32 ( & V_1 , V_49 ) ;
F_36 ( V_61 + V_64 , V_3 -> V_5 ) ;
V_63 = V_3 -> V_5 ;
F_42 ( V_3 ) ;
F_33 ( & V_1 , V_49 ) ;
F_12 ( V_63 ) ;
#ifdef F_43
if ( V_61 + V_64 < F_44 () )
V_66 [ V_61 + V_64 ] = NULL ;
#endif
}
}
}
static int F_45 ( struct V_60 * V_12 , unsigned int V_61 ,
unsigned int V_62 , void * V_67 )
{
struct V_50 * V_51 = V_67 ;
struct V_2 * V_7 ;
struct V_3 * V_3 ;
int V_64 , V_48 , V_10 ;
if ( V_68 )
return - V_69 ;
if ( ( V_51 -> V_49 & V_70 ) && V_62 > 1 )
return - V_71 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
V_3 = F_41 ( V_12 , V_61 + V_64 ) ;
F_30 ( ! V_3 ) ;
V_10 = F_46 ( V_3 ) ;
#ifdef F_43
if ( V_61 + V_64 < F_44 () && V_66 [ V_61 + V_64 ] )
V_7 = V_66 [ V_61 + V_64 ] ;
else
#endif
V_7 = F_7 ( V_10 ) ;
if ( ! V_7 ) {
V_48 = - V_72 ;
goto error;
}
V_3 -> V_73 = & V_74 ;
V_3 -> V_5 = V_7 ;
V_3 -> V_75 = V_61 + V_64 ;
V_48 = F_34 ( V_61 + V_64 , V_10 , V_7 , V_51 ,
V_3 ) ;
if ( V_48 )
goto error;
if ( ! V_33 -> V_76 )
F_47 ( V_3 ) ;
}
return 0 ;
error:
F_40 ( V_12 , V_61 , V_64 + 1 ) ;
return V_48 ;
}
int T_1 F_48 ( void )
{
int V_77 ;
if ( V_62 > ( V_57 * V_30 ) )
V_62 = V_57 * V_30 ;
V_77 = ( V_78 + F_44 () ) + 8 * V_30 ;
#if F_49 ( V_79 ) || F_49 ( V_80 )
if ( V_78 <= V_81 )
V_77 += 8 * V_30 ;
else
V_77 += V_78 * 16 ;
#endif
if ( V_77 < V_62 )
V_62 = V_77 ;
return V_82 -> V_83 () ;
}
static void T_1 F_50 ( void )
{
int V_64 , V_10 = F_51 ( 0 ) ;
struct V_2 * V_7 ;
for ( V_64 = 0 ; V_64 < F_44 () ; V_64 ++ ) {
V_7 = V_66 [ V_64 ] = F_7 ( V_10 ) ;
F_30 ( ! V_7 ) ;
V_7 -> V_8 . V_25 = F_52 ( V_64 ) ;
F_53 ( V_7 -> V_12 ) ;
F_54 ( V_64 , V_7 ) ;
}
}
static inline void F_50 ( void ) { }
int T_1 F_55 ( void )
{
struct V_84 * V_85 ;
F_50 () ;
V_85 = F_56 ( L_1 ) ;
F_30 ( ! V_85 ) ;
V_65 = F_57 ( V_85 , & V_86 ,
NULL ) ;
F_30 ( V_65 == NULL ) ;
F_58 ( V_85 ) ;
F_59 ( V_65 ) ;
F_60 ( V_65 ) ;
F_61 ( V_65 ) ;
F_30 ( ! F_62 ( & V_35 , V_11 ) ) ;
F_30 ( ! F_62 ( & V_36 , V_11 ) ) ;
F_30 ( ! F_62 ( & V_29 , V_11 ) ) ;
return F_63 () ;
}
static void F_64 ( int V_24 )
{
struct V_2 * V_7 ;
struct V_54 * V_55 ;
int V_9 , V_25 ;
F_65 (irq, desc) {
struct V_3 * V_87 = F_66 ( V_55 ) ;
V_7 = V_2 ( V_87 ) ;
if ( ! V_7 || ! F_67 ( V_24 , V_7 -> V_12 ) )
continue;
V_25 = V_7 -> V_8 . V_25 ;
F_25 ( V_43 , V_24 ) [ V_25 ] = V_55 ;
}
for ( V_25 = 0 ; V_25 < V_57 ; ++ V_25 ) {
V_55 = F_25 ( V_43 , V_24 ) [ V_25 ] ;
if ( F_24 ( V_55 ) )
continue;
V_7 = V_2 ( F_66 ( V_55 ) ) ;
if ( ! F_67 ( V_24 , V_7 -> V_12 ) )
F_25 ( V_43 , V_24 ) [ V_25 ] = V_56 ;
}
}
void F_68 ( int V_24 )
{
int V_9 ;
F_69 ( & V_1 ) ;
for ( V_9 = 0 ; V_9 < F_44 () ; V_9 ++ )
F_25 ( V_43 , V_24 ) [ F_52 ( V_9 ) ] = F_27 ( V_9 ) ;
F_64 ( V_24 ) ;
}
static int F_70 ( struct V_3 * V_3 )
{
struct V_2 * V_7 = V_2 ( V_3 ) ;
unsigned long V_49 ;
int V_24 ;
F_32 ( & V_1 , V_49 ) ;
V_24 = F_16 ( V_7 -> V_12 , V_27 ) ;
V_33 -> V_88 ( F_71 ( V_24 ) , V_7 -> V_8 . V_25 ) ;
F_33 ( & V_1 , V_49 ) ;
return 1 ;
}
void F_72 ( struct V_3 * V_7 )
{
F_73 ( F_5 ( V_7 ) ) ;
F_74 ( V_7 ) ;
F_75 () ;
}
static int F_76 ( struct V_3 * V_3 ,
const struct V_17 * V_89 , bool V_90 )
{
struct V_2 * V_7 = V_3 -> V_5 ;
int V_48 , V_9 = V_3 -> V_9 ;
if ( ! F_77 ( V_91 ) )
return - V_92 ;
if ( ! F_14 ( V_89 , V_27 ) )
return - V_93 ;
V_48 = F_31 ( V_9 , V_7 , V_89 , V_3 ) ;
return V_48 ? V_48 : V_94 ;
}
static void F_78 ( struct V_2 * V_7 )
{
F_2 ( & V_1 ) ;
F_17 ( V_7 -> V_14 , V_7 -> V_14 , V_27 ) ;
V_7 -> V_26 = 0 ;
if ( ! F_29 ( V_7 -> V_14 ) )
V_33 -> V_88 ( V_7 -> V_14 , V_95 ) ;
F_4 ( & V_1 ) ;
}
void F_79 ( struct V_6 * V_8 )
{
struct V_2 * V_7 ;
V_7 = F_80 ( V_8 , struct V_2 , V_8 ) ;
if ( V_7 -> V_26 )
F_78 ( V_7 ) ;
}
T_2 T_3 void T_4 F_81 ( void )
{
unsigned V_25 , V_96 ;
F_82 () ;
F_2 ( & V_1 ) ;
V_96 = F_83 () ;
for ( V_25 = V_21 ; V_25 < V_57 ; V_25 ++ ) {
struct V_2 * V_7 ;
struct V_54 * V_55 ;
unsigned int V_97 ;
V_98:
V_55 = F_84 ( V_43 [ V_25 ] ) ;
if ( F_24 ( V_55 ) )
continue;
if ( ! F_85 ( & V_55 -> V_99 ) ) {
F_4 ( & V_1 ) ;
F_86 () ;
F_2 ( & V_1 ) ;
goto V_98;
}
V_7 = V_2 ( F_66 ( V_55 ) ) ;
if ( ! V_7 )
goto V_100;
if ( V_7 -> V_26 ||
! F_67 ( V_96 , V_7 -> V_14 ) )
goto V_100;
if ( V_25 == V_7 -> V_8 . V_25 &&
F_67 ( V_96 , V_7 -> V_12 ) )
goto V_100;
V_97 = F_87 ( V_101 + ( V_25 / 32 * 0x10 ) ) ;
if ( V_97 & ( 1 << ( V_25 % 32 ) ) ) {
V_33 -> V_102 ( V_95 ) ;
goto V_100;
}
F_88 ( V_43 [ V_25 ] , V_56 ) ;
F_89 ( V_96 , V_7 -> V_14 ) ;
V_100:
F_4 ( & V_55 -> V_99 ) ;
}
F_4 ( & V_1 ) ;
F_90 () ;
}
static void F_91 ( struct V_6 * V_8 , unsigned V_25 )
{
unsigned V_96 ;
struct V_2 * V_7 ;
V_7 = F_80 ( V_8 , struct V_2 , V_8 ) ;
if ( F_92 ( ! V_7 -> V_26 ) )
return;
V_96 = F_83 () ;
if ( V_25 == V_7 -> V_8 . V_25 && F_67 ( V_96 , V_7 -> V_12 ) )
F_78 ( V_7 ) ;
}
void F_73 ( struct V_6 * V_8 )
{
F_91 ( V_8 , ~ F_93 () -> V_103 ) ;
}
void F_94 ( struct V_54 * V_55 )
{
struct V_3 * V_19 ;
struct V_2 * V_7 ;
struct V_6 * V_8 ;
unsigned int V_24 ;
V_19 = F_41 ( V_65 ,
F_95 ( V_55 ) ) ;
if ( ! V_19 )
return;
V_7 = V_2 ( V_19 ) ;
V_8 = V_7 ? & V_7 -> V_8 : NULL ;
if ( ! V_8 )
return;
F_2 ( & V_1 ) ;
F_17 ( V_7 -> V_14 , V_7 -> V_14 , V_27 ) ;
if ( ! V_7 -> V_26 && F_29 ( V_7 -> V_14 ) ) {
F_4 ( & V_1 ) ;
return;
}
if ( V_7 -> V_26 ) {
F_96 ( L_2 ,
V_19 -> V_9 , V_8 -> V_45 ) ;
}
F_23 (cpu, data->old_domain)
F_25 ( V_43 , V_24 ) [ V_8 -> V_45 ] = V_56 ;
F_15 ( V_7 -> V_14 ) ;
V_7 -> V_26 = 0 ;
F_4 ( & V_1 ) ;
}
static void T_1 F_97 ( int V_104 )
{
int V_64 ;
F_98 ( V_105 ) ;
for ( V_64 = 0 ; V_64 < 8 ; V_64 ++ )
F_99 ( L_3 , F_87 ( V_104 + V_64 * 0x10 ) ) ;
F_99 ( L_4 ) ;
}
static void T_1 F_100 ( void * V_106 )
{
unsigned int V_64 , V_107 , V_108 , V_109 ;
T_5 V_110 ;
F_101 ( L_5 ,
F_83 () , F_102 () ) ;
V_107 = F_87 ( V_111 ) ;
F_103 ( L_6 , V_107 , F_104 () ) ;
V_107 = F_87 ( V_112 ) ;
F_103 ( L_7 , V_107 ) ;
V_108 = F_105 ( V_107 ) ;
V_109 = F_106 () ;
V_107 = F_87 ( V_113 ) ;
F_101 ( L_8 , V_107 , V_107 & V_114 ) ;
if ( F_107 ( V_108 ) ) {
if ( ! F_108 ( V_108 ) ) {
V_107 = F_87 ( V_115 ) ;
F_101 ( L_9 ,
V_107 , V_107 & V_116 ) ;
}
V_107 = F_87 ( V_117 ) ;
F_101 ( L_10 , V_107 ) ;
}
if ( ! F_107 ( V_108 ) || V_109 == 3 ) {
V_107 = F_87 ( V_118 ) ;
F_101 ( L_11 , V_107 ) ;
}
V_107 = F_87 ( V_119 ) ;
F_101 ( L_12 , V_107 ) ;
if ( ! F_109 () ) {
V_107 = F_87 ( V_120 ) ;
F_101 ( L_13 , V_107 ) ;
}
V_107 = F_87 ( V_121 ) ;
F_101 ( L_14 , V_107 ) ;
F_101 ( L_15 ) ;
F_97 ( V_122 ) ;
F_101 ( L_16 ) ;
F_97 ( V_123 ) ;
F_101 ( L_17 ) ;
F_97 ( V_101 ) ;
if ( F_107 ( V_108 ) ) {
if ( V_109 > 3 )
F_110 ( V_124 , 0 ) ;
V_107 = F_87 ( V_124 ) ;
F_101 ( L_18 , V_107 ) ;
}
V_110 = F_111 () ;
F_101 ( L_19 , ( V_125 ) V_110 ) ;
F_101 ( L_20 , ( V_125 ) ( V_110 >> 32 ) ) ;
V_107 = F_87 ( V_126 ) ;
F_101 ( L_21 , V_107 ) ;
if ( V_109 > 3 ) {
V_107 = F_87 ( V_127 ) ;
F_101 ( L_22 , V_107 ) ;
}
V_107 = F_87 ( V_128 ) ;
F_101 ( L_23 , V_107 ) ;
V_107 = F_87 ( V_129 ) ;
F_101 ( L_24 , V_107 ) ;
if ( V_109 > 2 ) {
V_107 = F_87 ( V_130 ) ;
F_101 ( L_25 , V_107 ) ;
}
V_107 = F_87 ( V_131 ) ;
F_101 ( L_26 , V_107 ) ;
V_107 = F_87 ( V_132 ) ;
F_101 ( L_27 , V_107 ) ;
V_107 = F_87 ( V_133 ) ;
F_101 ( L_28 , V_107 ) ;
if ( F_112 ( V_134 ) ) {
V_107 = F_87 ( V_135 ) ;
V_109 = ( V_107 >> 16 ) & 0xff ;
F_101 ( L_29 , V_107 ) ;
V_107 = F_87 ( V_136 ) ;
F_101 ( L_30 , V_107 ) ;
for ( V_64 = 0 ; V_64 < V_109 ; V_64 ++ ) {
V_107 = F_87 ( F_113 ( V_64 ) ) ;
F_101 ( L_31 , V_64 , V_107 ) ;
}
}
F_99 ( L_4 ) ;
}
static void T_1 F_114 ( int V_137 )
{
int V_24 ;
if ( ! V_137 )
return;
F_115 () ;
F_116 (cpu) {
if ( V_24 >= V_137 )
break;
F_117 ( V_24 , F_100 , NULL , 1 ) ;
}
F_118 () ;
}
static void T_1 F_119 ( void )
{
unsigned int V_107 ;
unsigned long V_49 ;
if ( ! F_44 () )
return;
F_101 ( L_32 ) ;
F_32 ( & V_138 , V_49 ) ;
V_107 = F_120 ( 0xa1 ) << 8 | F_120 ( 0x21 ) ;
F_101 ( L_33 , V_107 ) ;
V_107 = F_120 ( 0xa0 ) << 8 | F_120 ( 0x20 ) ;
F_101 ( L_34 , V_107 ) ;
F_121 ( 0x0b , 0xa0 ) ;
F_121 ( 0x0b , 0x20 ) ;
V_107 = F_120 ( 0xa0 ) << 8 | F_120 ( 0x20 ) ;
F_121 ( 0x0a , 0xa0 ) ;
F_121 ( 0x0a , 0x20 ) ;
F_33 ( & V_138 , V_49 ) ;
F_101 ( L_35 , V_107 ) ;
V_107 = F_120 ( 0x4d1 ) << 8 | F_120 ( 0x4d0 ) ;
F_101 ( L_36 , V_107 ) ;
}
static T_1 int F_122 ( char * V_67 )
{
int V_139 = - 1 ;
if ( strcmp ( V_67 , L_37 ) == 0 ) {
V_140 = V_141 ;
} else {
F_123 ( & V_67 , & V_139 ) ;
if ( V_139 >= 0 )
V_140 = V_139 ;
}
return 1 ;
}
static int T_1 F_124 ( void )
{
if ( V_142 == V_143 )
return 0 ;
F_119 () ;
if ( ! F_112 ( V_144 ) && ! F_125 () )
return 0 ;
F_114 ( V_140 ) ;
F_126 () ;
return 0 ;
}
