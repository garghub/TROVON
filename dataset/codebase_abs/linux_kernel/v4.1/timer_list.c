static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
char V_4 [ V_5 ] ;
if ( F_2 ( ( unsigned long ) V_3 , V_4 ) < 0 )
F_3 ( V_2 , L_1 , V_3 ) ;
else
F_3 ( V_2 , L_2 , V_4 ) ;
}
static void
F_4 ( struct V_1 * V_2 , struct V_6 * V_7 , struct V_6 * V_8 ,
int V_9 , T_1 V_10 )
{
#ifdef F_5
char V_11 [ V_12 + 1 ] ;
#endif
F_3 ( V_2 , L_3 , V_9 ) ;
F_1 ( V_2 , V_7 ) ;
F_3 ( V_2 , L_4 ) ;
F_1 ( V_2 , V_8 -> V_13 ) ;
F_3 ( V_2 , L_5 , V_8 -> V_14 ) ;
#ifdef F_5
F_3 ( V_2 , L_4 ) ;
F_1 ( V_2 , V_8 -> V_15 ) ;
memcpy ( V_11 , V_8 -> V_16 , V_12 ) ;
V_11 [ V_12 ] = 0 ;
F_3 ( V_2 , L_6 , V_11 , V_8 -> V_17 ) ;
#endif
F_3 ( V_2 , L_7 ) ;
F_3 ( V_2 , L_8 ,
( unsigned long long ) F_6 ( F_7 ( V_8 ) ) ,
( unsigned long long ) F_6 ( F_8 ( V_8 ) ) ,
( long long ) ( F_6 ( F_7 ( V_8 ) ) - V_10 ) ,
( long long ) ( F_6 ( F_8 ( V_8 ) ) - V_10 ) ) ;
}
static void
F_9 ( struct V_1 * V_2 , struct V_18 * V_19 ,
T_1 V_10 )
{
struct V_6 * V_8 , V_11 ;
unsigned long V_20 = 0 , V_21 ;
struct V_22 * V_23 ;
unsigned long V_24 ;
V_25:
V_21 = 0 ;
F_10 ( & V_19 -> V_26 -> V_27 , V_24 ) ;
V_23 = F_11 ( & V_19 -> V_28 ) ;
while ( V_23 && V_21 < V_20 ) {
V_23 = F_12 ( V_23 ) ;
V_21 ++ ;
}
if ( V_23 ) {
V_8 = F_13 ( V_23 , struct V_6 , V_29 ) ;
V_11 = * V_8 ;
F_14 ( & V_19 -> V_26 -> V_27 , V_24 ) ;
F_4 ( V_2 , V_8 , & V_11 , V_21 , V_10 ) ;
V_20 ++ ;
goto V_25;
}
F_14 ( & V_19 -> V_26 -> V_27 , V_24 ) ;
}
static void
F_15 ( struct V_1 * V_2 , struct V_18 * V_19 , T_1 V_10 )
{
F_3 ( V_2 , L_9 , V_19 ) ;
F_3 ( V_2 , L_10 ,
V_19 -> V_30 ) ;
F_3 ( V_2 , L_11 ,
( unsigned long long ) F_6 ( V_19 -> V_31 ) ) ;
F_3 ( V_2 , L_12 ) ;
F_1 ( V_2 , V_19 -> V_32 ) ;
F_3 ( V_2 , L_7 ) ;
#ifdef F_16
F_3 ( V_2 , L_13 ,
( unsigned long long ) F_6 ( V_19 -> V_33 ) ) ;
#endif
F_3 ( V_2 , L_14 ) ;
F_9 ( V_2 , V_19 , V_10 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_34 , T_1 V_10 )
{
struct V_35 * V_26 = & F_18 ( V_36 , V_34 ) ;
int V_21 ;
F_3 ( V_2 , L_15 , V_34 ) ;
for ( V_21 = 0 ; V_21 < V_37 ; V_21 ++ ) {
F_3 ( V_2 , L_16 , V_21 ) ;
F_15 ( V_2 , V_26 -> V_38 + V_21 , V_10 ) ;
}
#define F_19 ( T_2 ) \
SEQ_printf(m, " .%-15s: %Lu\n", #x, \
(unsigned long long)(cpu_base->x))
#define F_20 ( T_2 ) \
SEQ_printf(m, " .%-15s: %Lu nsecs\n", #x, \
(unsigned long long)(ktime_to_ns(cpu_base->x)))
#ifdef F_16
F_20 ( V_39 ) ;
F_19 ( V_40 ) ;
F_19 ( V_41 ) ;
F_19 ( V_42 ) ;
F_19 ( V_43 ) ;
F_20 ( V_44 ) ;
#endif
#undef F_19
#undef F_20
#ifdef F_21
# define F_19 ( T_2 ) \
SEQ_printf(m, " .%-15s: %Lu\n", #x, \
(unsigned long long)(ts->x))
# define F_20 ( T_2 ) \
SEQ_printf(m, " .%-15s: %Lu nsecs\n", #x, \
(unsigned long long)(ktime_to_ns(ts->x)))
{
struct V_45 * V_46 = F_22 ( V_34 ) ;
F_19 ( V_47 ) ;
F_20 ( V_48 ) ;
F_19 ( V_49 ) ;
F_19 ( V_50 ) ;
F_19 ( V_51 ) ;
F_19 ( V_52 ) ;
F_20 ( V_53 ) ;
F_20 ( V_54 ) ;
F_20 ( V_55 ) ;
F_20 ( V_56 ) ;
F_20 ( V_57 ) ;
F_19 ( V_58 ) ;
F_19 ( V_59 ) ;
F_20 ( V_60 ) ;
F_3 ( V_2 , L_17 ,
( unsigned long long ) V_61 ) ;
}
#endif
#undef F_19
#undef F_20
F_3 ( V_2 , L_7 ) ;
}
static void
F_23 ( struct V_1 * V_2 , struct V_62 * V_63 , int V_34 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
F_3 ( V_2 , L_18 , V_63 -> V_67 ) ;
if ( V_34 < 0 )
F_3 ( V_2 , L_19 ) ;
else
F_3 ( V_2 , L_20 , V_34 ) ;
F_3 ( V_2 , L_21 ) ;
if ( ! V_65 ) {
F_3 ( V_2 , L_22 ) ;
return;
}
F_3 ( V_2 , L_23 , V_65 -> V_68 ) ;
F_3 ( V_2 , L_24 ,
( unsigned long long ) V_65 -> V_69 ) ;
F_3 ( V_2 , L_25 ,
( unsigned long long ) V_65 -> V_70 ) ;
F_3 ( V_2 , L_26 , V_65 -> V_71 ) ;
F_3 ( V_2 , L_27 , V_65 -> V_72 ) ;
F_3 ( V_2 , L_28 , V_65 -> V_67 ) ;
F_3 ( V_2 , L_29 ,
( unsigned long long ) F_6 ( V_65 -> V_73 ) ) ;
F_3 ( V_2 , L_30 ) ;
F_1 ( V_2 , V_65 -> V_74 ) ;
F_3 ( V_2 , L_7 ) ;
if ( V_65 -> V_75 ) {
F_3 ( V_2 , L_31 ) ;
F_1 ( V_2 , V_65 -> V_75 ) ;
F_3 ( V_2 , L_7 ) ;
} else {
if ( V_65 -> V_76 ) {
F_3 ( V_2 , L_32 ) ;
F_1 ( V_2 , V_65 -> V_76 ) ;
F_3 ( V_2 , L_7 ) ;
}
if ( V_65 -> V_77 ) {
F_3 ( V_2 , L_33 ) ;
F_1 ( V_2 , V_65 -> V_77 ) ;
F_3 ( V_2 , L_7 ) ;
}
if ( V_65 -> V_78 ) {
F_3 ( V_2 , L_34 ) ;
F_1 ( V_2 , V_65 -> V_78 ) ;
F_3 ( V_2 , L_7 ) ;
}
if ( V_65 -> V_79 ) {
F_3 ( V_2 , L_35 ) ;
F_1 ( V_2 , V_65 -> V_79 ) ;
F_3 ( V_2 , L_7 ) ;
}
}
F_3 ( V_2 , L_36 ) ;
F_1 ( V_2 , V_65 -> V_80 ) ;
F_3 ( V_2 , L_7 ) ;
F_3 ( V_2 , L_37 , V_65 -> V_81 ) ;
F_3 ( V_2 , L_7 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
#ifdef F_25
F_23 ( V_2 , F_26 () , - 1 ) ;
F_3 ( V_2 , L_38 ,
F_27 ( F_28 () ) [ 0 ] ) ;
#ifdef F_21
F_3 ( V_2 , L_39 ,
F_27 ( F_29 () ) [ 0 ] ) ;
#endif
F_3 ( V_2 , L_7 ) ;
#endif
}
static inline void F_30 ( struct V_1 * V_2 , T_1 V_10 )
{
F_3 ( V_2 , L_40 ) ;
F_3 ( V_2 , L_41 , V_37 ) ;
F_3 ( V_2 , L_42 , ( unsigned long long ) V_10 ) ;
F_3 ( V_2 , L_7 ) ;
}
static int F_31 ( struct V_1 * V_2 , void * V_82 )
{
struct V_83 * V_84 = V_82 ;
if ( V_84 -> V_34 == - 1 && ! V_84 -> V_85 )
F_30 ( V_2 , V_84 -> V_10 ) ;
else if ( ! V_84 -> V_85 )
F_17 ( V_2 , V_84 -> V_34 , V_84 -> V_10 ) ;
#ifdef F_32
else if ( V_84 -> V_34 == - 1 && V_84 -> V_85 )
F_24 ( V_2 ) ;
else
F_23 ( V_2 , F_33 ( V_84 -> V_34 ) , V_84 -> V_34 ) ;
#endif
return 0 ;
}
void F_34 ( void )
{
T_1 V_10 = F_6 ( F_35 () ) ;
int V_34 ;
F_30 ( NULL , V_10 ) ;
F_36 (cpu)
F_17 ( NULL , V_34 , V_10 ) ;
#ifdef F_32
F_24 ( NULL ) ;
F_36 (cpu)
F_23 ( NULL , F_33 ( V_34 ) , V_34 ) ;
#endif
return;
}
static void * F_37 ( struct V_83 * V_84 , T_3 V_33 )
{
for (; V_33 ; V_33 -- ) {
V_84 -> V_34 = F_38 ( V_84 -> V_34 , V_86 ) ;
if ( V_84 -> V_34 >= V_87 ) {
#ifdef F_32
if ( ! V_84 -> V_85 ) {
V_84 -> V_34 = - 1 ;
V_84 -> V_85 = true ;
} else
return NULL ;
#else
return NULL ;
#endif
}
}
return V_84 ;
}
static void * F_39 ( struct V_1 * V_88 , T_3 * V_33 )
{
struct V_83 * V_84 = V_88 -> V_89 ;
if ( ! * V_33 )
V_84 -> V_10 = F_6 ( F_35 () ) ;
V_84 -> V_34 = - 1 ;
V_84 -> V_85 = false ;
return F_37 ( V_84 , * V_33 ) ;
}
static void * F_40 ( struct V_1 * V_88 , void * V_82 , T_3 * V_33 )
{
struct V_83 * V_84 = V_88 -> V_89 ;
++ * V_33 ;
return F_37 ( V_84 , 1 ) ;
}
static void F_41 ( struct V_1 * V_90 , void * V_82 )
{
}
static int F_42 ( struct V_91 * V_91 , struct V_88 * V_92 )
{
return F_43 ( V_92 , & V_93 ,
sizeof( struct V_83 ) ) ;
}
static int T_4 F_44 ( void )
{
struct V_94 * V_95 ;
V_95 = F_45 ( L_43 , 0444 , NULL , & V_96 ) ;
if ( ! V_95 )
return - V_97 ;
return 0 ;
}
