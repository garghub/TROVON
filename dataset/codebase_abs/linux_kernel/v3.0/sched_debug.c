static long long F_1 ( unsigned long long V_1 )
{
if ( ( long long ) V_1 < 0 ) {
V_1 = - V_1 ;
F_2 ( V_1 , 1000000 ) ;
return - V_1 ;
}
F_2 ( V_1 , 1000000 ) ;
return V_1 ;
}
static unsigned long F_3 ( unsigned long long V_1 )
{
if ( ( long long ) V_1 < 0 )
V_1 = - V_1 ;
return F_2 ( V_1 , 1000000 ) ;
}
static void F_4 ( struct V_2 * V_3 , int V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 [ V_4 ] ;
if ( ! V_8 )
return;
#define F_5 ( T_1 ) \
SEQ_printf(m, " .%-30s: %lld\n", #F, (long long)F)
#define F_6 ( T_1 ) \
SEQ_printf(m, " .%-30s: %lld.%06ld\n", #F, SPLIT_NS((long long)F))
F_6 ( V_8 -> V_9 ) ;
F_6 ( V_8 -> V_10 ) ;
F_6 ( V_8 -> V_11 ) ;
#ifdef F_7
F_6 ( V_8 -> V_12 . V_13 ) ;
F_6 ( V_8 -> V_12 . V_14 ) ;
F_6 ( V_8 -> V_12 . V_15 ) ;
F_6 ( V_8 -> V_12 . V_16 ) ;
F_6 ( V_8 -> V_12 . V_17 ) ;
F_6 ( V_8 -> V_12 . V_18 ) ;
F_6 ( V_8 -> V_12 . V_19 ) ;
F_6 ( V_8 -> V_12 . V_20 ) ;
F_6 ( V_8 -> V_12 . V_21 ) ;
F_5 ( V_8 -> V_12 . V_22 ) ;
#endif
F_5 ( V_8 -> V_23 . V_24 ) ;
#undef F_6
#undef F_5
}
static char * F_8 ( struct V_5 * V_6 )
{
if ( F_9 ( V_6 , V_25 , V_26 ) )
return V_25 ;
if ( ! V_6 -> V_27 . V_28 ) {
V_25 [ 0 ] = '\0' ;
return V_25 ;
}
F_10 ( V_6 -> V_27 . V_28 , V_25 , V_26 ) ;
return V_25 ;
}
static void
F_11 ( struct V_2 * V_3 , struct V_29 * V_29 , struct V_30 * V_31 )
{
if ( V_29 -> V_32 == V_31 )
F_12 ( V_3 , L_1 ) ;
else
F_12 ( V_3 , L_2 ) ;
F_12 ( V_3 , L_3 ,
V_31 -> V_33 , V_31 -> V_34 ,
F_13 ( V_31 -> V_8 . V_10 ) ,
( long long ) ( V_31 -> V_35 + V_31 -> V_36 ) ,
V_31 -> V_37 ) ;
#ifdef F_7
F_12 ( V_3 , L_4 ,
F_13 ( V_31 -> V_8 . V_10 ) ,
F_13 ( V_31 -> V_8 . V_11 ) ,
F_13 ( V_31 -> V_8 . V_12 . V_38 ) ) ;
#else
F_12 ( V_3 , L_5 ,
0LL , 0LL , 0LL , 0L , 0LL , 0L , 0LL , 0L ) ;
#endif
#ifdef F_14
F_12 ( V_3 , L_6 , F_8 ( V_5 ( V_31 ) ) ) ;
#endif
F_12 ( V_3 , L_7 ) ;
}
static void F_15 ( struct V_2 * V_3 , struct V_29 * V_29 , int V_39 )
{
struct V_30 * V_40 , * V_31 ;
unsigned long V_41 ;
F_12 ( V_3 ,
L_8
L_9
L_10
L_11
L_12 ) ;
F_16 ( & V_42 , V_41 ) ;
F_17 (g, p) {
if ( ! V_31 -> V_43 || F_18 ( V_31 ) != V_39 )
continue;
F_11 ( V_3 , V_29 , V_31 ) ;
} F_19 ( V_40 , V_31 ) ;
F_20 ( & V_42 , V_41 ) ;
}
void F_21 ( struct V_2 * V_3 , int V_4 , struct V_44 * V_44 )
{
T_2 V_45 = - 1 , V_46 , V_47 = - 1 ,
V_48 , V_49 , V_50 ;
struct V_29 * V_29 = F_22 ( V_4 ) ;
struct V_7 * V_51 ;
unsigned long V_41 ;
#ifdef F_23
F_12 ( V_3 , L_13 , V_4 , F_8 ( V_44 -> V_6 ) ) ;
#else
F_12 ( V_3 , L_14 , V_4 ) ;
#endif
F_12 ( V_3 , L_15 , L_16 ,
F_13 ( V_44 -> V_52 ) ) ;
F_24 ( & V_29 -> V_53 , V_41 ) ;
if ( V_44 -> V_54 )
V_45 = ( F_25 ( V_44 ) ) -> V_10 ;
V_51 = F_26 ( V_44 ) ;
if ( V_51 )
V_47 = V_51 -> V_10 ;
V_46 = V_44 -> V_46 ;
V_49 = F_22 ( 0 ) -> V_55 . V_46 ;
F_27 ( & V_29 -> V_53 , V_41 ) ;
F_12 ( V_3 , L_15 , L_17 ,
F_13 ( V_45 ) ) ;
F_12 ( V_3 , L_15 , L_18 ,
F_13 ( V_46 ) ) ;
F_12 ( V_3 , L_15 , L_19 ,
F_13 ( V_47 ) ) ;
V_48 = V_47 - V_45 ;
F_12 ( V_3 , L_15 , L_20 ,
F_13 ( V_48 ) ) ;
V_50 = V_46 - V_49 ;
F_12 ( V_3 , L_15 , L_21 ,
F_13 ( V_50 ) ) ;
F_12 ( V_3 , L_22 , L_23 ,
V_44 -> V_56 ) ;
F_12 ( V_3 , L_24 , L_25 , V_44 -> V_57 ) ;
F_12 ( V_3 , L_24 , L_26 , V_44 -> V_23 . V_24 ) ;
#ifdef F_23
#ifdef F_28
F_12 ( V_3 , L_15 , L_27 ,
F_13 ( V_44 -> V_58 ) ) ;
F_12 ( V_3 , L_15 , L_28 ,
F_13 ( V_44 -> V_59 ) ) ;
F_12 ( V_3 , L_24 , L_29 ,
V_44 -> V_60 ) ;
F_12 ( V_3 , L_22 , L_30 ,
F_29 ( & V_44 -> V_6 -> V_61 ) ) ;
#endif
F_4 ( V_3 , V_4 , V_44 -> V_6 ) ;
#endif
}
void F_30 ( struct V_2 * V_3 , int V_4 , struct V_62 * V_62 )
{
#ifdef F_31
F_12 ( V_3 , L_31 , V_4 , F_8 ( V_62 -> V_6 ) ) ;
#else
F_12 ( V_3 , L_32 , V_4 ) ;
#endif
#define F_5 ( T_3 ) \
SEQ_printf(m, " .%-30s: %Ld\n", #x, (long long)(rt_rq->x))
#define F_6 ( T_3 ) \
SEQ_printf(m, " .%-30s: %Ld.%06ld\n", #x, SPLIT_NS(rt_rq->x))
F_5 ( V_63 ) ;
F_5 ( V_64 ) ;
F_6 ( V_65 ) ;
F_6 ( V_66 ) ;
#undef F_6
#undef F_5
}
static void F_32 ( struct V_2 * V_3 , int V_4 )
{
struct V_29 * V_29 = F_22 ( V_4 ) ;
unsigned long V_41 ;
#ifdef F_33
{
unsigned int V_67 = V_68 ? : 1 ;
F_12 ( V_3 , L_33 ,
V_4 , V_67 / 1000 , ( V_67 % 1000 ) ) ;
}
#else
F_12 ( V_3 , L_34 , V_4 ) ;
#endif
#define F_5 ( T_3 ) \
SEQ_printf(m, " .%-30s: %Ld\n", #x, (long long)(rq->x))
#define F_6 ( T_3 ) \
SEQ_printf(m, " .%-30s: %Ld.%06ld\n", #x, SPLIT_NS(rq->x))
F_5 ( V_57 ) ;
F_12 ( V_3 , L_35 , L_26 ,
V_29 -> V_23 . V_24 ) ;
F_5 ( V_69 ) ;
F_5 ( V_70 ) ;
F_5 ( V_71 ) ;
F_6 ( V_72 ) ;
F_5 ( V_32 -> V_34 ) ;
F_6 ( clock ) ;
F_5 ( V_73 [ 0 ] ) ;
F_5 ( V_73 [ 1 ] ) ;
F_5 ( V_73 [ 2 ] ) ;
F_5 ( V_73 [ 3 ] ) ;
F_5 ( V_73 [ 4 ] ) ;
#undef F_5
#undef F_6
#ifdef F_7
#define F_5 ( T_4 ) SEQ_printf(m, " .%-30s: %d\n", #n, rq->n);
#define F_34 ( T_4 ) SEQ_printf(m, " .%-30s: %Ld\n", #n, rq->n);
F_5 ( V_74 ) ;
F_5 ( V_75 ) ;
F_5 ( V_76 ) ;
F_5 ( V_77 ) ;
#ifdef F_28
F_34 ( V_78 ) ;
#endif
F_5 ( V_79 ) ;
F_5 ( V_80 ) ;
#undef F_5
#undef F_34
#endif
F_35 ( & V_81 , V_41 ) ;
F_36 ( V_3 , V_4 ) ;
F_37 ( V_3 , V_4 ) ;
F_38 () ;
F_15 ( V_3 , V_29 , V_4 ) ;
F_39 () ;
F_40 ( & V_81 , V_41 ) ;
}
static int F_41 ( struct V_2 * V_3 , void * V_82 )
{
T_5 V_83 , V_84 , V_85 ;
unsigned long V_41 ;
int V_4 ;
F_42 ( V_41 ) ;
V_83 = F_43 ( F_44 () ) ;
V_84 = F_45 () ;
V_85 = F_46 () ;
F_47 ( V_41 ) ;
F_12 ( V_3 , L_36 ,
F_48 () -> V_86 ,
( int ) strcspn ( F_48 () -> V_87 , L_2 ) ,
F_48 () -> V_87 ) ;
#define F_5 ( T_3 ) \
SEQ_printf(m, "%-40s: %Ld\n", #x, (long long)(x))
#define F_6 ( T_3 ) \
SEQ_printf(m, "%-40s: %Ld.%06ld\n", #x, SPLIT_NS(x))
F_6 ( V_83 ) ;
F_6 ( V_84 ) ;
F_6 ( V_85 ) ;
F_5 ( V_88 ) ;
#ifdef F_49
F_5 ( V_89 ) ;
#endif
#undef F_6
#undef F_5
F_12 ( V_3 , L_7 ) ;
F_12 ( V_3 , L_37 ) ;
#define F_5 ( T_3 ) \
SEQ_printf(m, " .%-40s: %Ld\n", #x, (long long)(x))
#define F_6 ( T_3 ) \
SEQ_printf(m, " .%-40s: %Ld.%06ld\n", #x, SPLIT_NS(x))
F_6 ( V_90 ) ;
F_6 ( V_91 ) ;
F_6 ( V_92 ) ;
F_5 ( V_93 ) ;
F_5 ( V_94 ) ;
#undef F_6
#undef F_5
F_12 ( V_3 , L_38 , L_39 ,
V_95 ,
V_96 [ V_95 ] ) ;
F_50 (cpu)
F_32 ( V_3 , V_4 ) ;
F_12 ( V_3 , L_7 ) ;
return 0 ;
}
static void F_51 ( void )
{
F_41 ( NULL , NULL ) ;
}
static int F_52 ( struct V_97 * V_97 , struct V_98 * V_99 )
{
return F_53 ( V_99 , F_41 , NULL ) ;
}
static int T_6 F_54 ( void )
{
struct V_100 * V_101 ;
V_101 = F_55 ( L_40 , 0444 , NULL , & V_102 ) ;
if ( ! V_101 )
return - V_103 ;
return 0 ;
}
void F_56 ( struct V_30 * V_31 , struct V_2 * V_3 )
{
unsigned long V_69 ;
F_12 ( V_3 , L_41 , V_31 -> V_33 , V_31 -> V_34 ,
F_57 ( V_31 ) ) ;
F_12 ( V_3 ,
L_42 ) ;
#define F_58 ( T_1 ) \
SEQ_printf(m, "%-35s:%21Ld\n", #F, (long long)F)
#define F_5 ( T_1 ) \
SEQ_printf(m, "%-35s:%21Ld\n", #F, (long long)p->F)
#define F_59 ( T_1 ) \
SEQ_printf(m, "%-35s:%14Ld.%06ld\n", #F, SPLIT_NS((long long)F))
#define F_6 ( T_1 ) \
SEQ_printf(m, "%-35s:%14Ld.%06ld\n", #F, SPLIT_NS((long long)p->F))
F_6 ( V_8 . V_9 ) ;
F_6 ( V_8 . V_10 ) ;
F_6 ( V_8 . V_11 ) ;
V_69 = V_31 -> V_35 + V_31 -> V_36 ;
#ifdef F_7
F_6 ( V_8 . V_12 . V_13 ) ;
F_6 ( V_8 . V_12 . V_14 ) ;
F_6 ( V_8 . V_12 . V_15 ) ;
F_6 ( V_8 . V_12 . V_16 ) ;
F_6 ( V_8 . V_12 . V_17 ) ;
F_6 ( V_8 . V_12 . V_18 ) ;
F_6 ( V_8 . V_12 . V_19 ) ;
F_6 ( V_8 . V_12 . V_20 ) ;
F_6 ( V_8 . V_12 . V_21 ) ;
F_5 ( V_8 . V_12 . V_22 ) ;
F_6 ( V_8 . V_12 . V_104 ) ;
F_5 ( V_8 . V_12 . V_105 ) ;
F_5 ( V_8 . V_106 ) ;
F_5 ( V_8 . V_12 . V_107 ) ;
F_5 ( V_8 . V_12 . V_108 ) ;
F_5 ( V_8 . V_12 . V_109 ) ;
F_5 ( V_8 . V_12 . V_110 ) ;
F_5 ( V_8 . V_12 . V_111 ) ;
F_5 ( V_8 . V_12 . V_112 ) ;
F_5 ( V_8 . V_12 . V_113 ) ;
F_5 ( V_8 . V_12 . V_114 ) ;
F_5 ( V_8 . V_12 . V_115 ) ;
F_5 ( V_8 . V_12 . V_116 ) ;
F_5 ( V_8 . V_12 . V_117 ) ;
F_5 ( V_8 . V_12 . V_118 ) ;
F_5 ( V_8 . V_12 . V_119 ) ;
F_5 ( V_8 . V_12 . V_120 ) ;
{
T_5 V_121 , V_122 ;
V_121 = V_31 -> V_8 . V_11 ;
if ( V_69 )
F_2 ( V_121 , V_69 ) ;
else
V_121 = - 1LL ;
V_122 = V_31 -> V_8 . V_11 ;
if ( V_31 -> V_8 . V_106 ) {
V_122 = F_60 ( V_122 ,
V_31 -> V_8 . V_106 ) ;
} else {
V_122 = - 1LL ;
}
F_59 ( V_121 ) ;
F_59 ( V_122 ) ;
}
#endif
F_58 ( V_69 ) ;
F_12 ( V_3 , L_43 ,
L_44 , ( long long ) V_31 -> V_35 ) ;
F_12 ( V_3 , L_43 ,
L_45 , ( long long ) V_31 -> V_36 ) ;
F_5 ( V_8 . V_23 . V_24 ) ;
F_5 ( V_123 ) ;
F_5 ( V_37 ) ;
#undef F_6
#undef F_59
#undef F_5
#undef F_58
{
unsigned int V_124 = F_61 () ;
T_5 V_125 , V_126 ;
V_125 = F_62 ( V_124 ) ;
V_126 = F_62 ( V_124 ) ;
F_12 ( V_3 , L_43 ,
L_46 , ( long long ) ( V_126 - V_125 ) ) ;
}
}
void F_63 ( struct V_30 * V_31 )
{
#ifdef F_7
memset ( & V_31 -> V_8 . V_12 , 0 , sizeof( V_31 -> V_8 . V_12 ) ) ;
#endif
}
