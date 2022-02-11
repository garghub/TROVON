static void F_1 ( struct V_1 * V_2 , const char * V_3 , ... )
{
T_1 args ;
va_start ( args , V_3 ) ;
if ( V_2 )
F_2 ( V_2 , V_3 , args ) ;
else
F_3 ( V_3 , args ) ;
va_end ( args ) ;
}
static void F_4 ( struct V_1 * V_2 , void * V_4 )
{
char V_5 [ V_6 ] ;
if ( F_5 ( ( unsigned long ) V_4 , V_5 ) < 0 )
F_1 ( V_2 , L_1 , V_4 ) ;
else
F_1 ( V_2 , L_2 , V_5 ) ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_7 * V_8 , struct V_7 * V_9 ,
int V_10 , T_2 V_11 )
{
F_1 ( V_2 , L_3 , V_10 ) ;
F_4 ( V_2 , V_8 ) ;
F_1 ( V_2 , L_4 ) ;
F_4 ( V_2 , V_9 -> V_12 ) ;
F_1 ( V_2 , L_5 , V_9 -> V_13 ) ;
F_1 ( V_2 , L_6 ) ;
F_1 ( V_2 , L_7 ,
( unsigned long long ) F_7 ( F_8 ( V_9 ) ) ,
( unsigned long long ) F_7 ( F_9 ( V_9 ) ) ,
( long long ) ( F_7 ( F_8 ( V_9 ) ) - V_11 ) ,
( long long ) ( F_7 ( F_9 ( V_9 ) ) - V_11 ) ) ;
}
static void
F_10 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_2 V_11 )
{
struct V_7 * V_9 , V_16 ;
unsigned long V_17 = 0 , V_18 ;
struct V_19 * V_20 ;
unsigned long V_21 ;
V_22:
V_18 = 0 ;
F_11 ( & V_15 -> V_23 -> V_24 , V_21 ) ;
V_20 = F_12 ( & V_15 -> V_25 ) ;
while ( V_20 && V_18 < V_17 ) {
V_20 = F_13 ( V_20 ) ;
V_18 ++ ;
}
if ( V_20 ) {
V_9 = F_14 ( V_20 , struct V_7 , V_26 ) ;
V_16 = * V_9 ;
F_15 ( & V_15 -> V_23 -> V_24 , V_21 ) ;
F_6 ( V_2 , V_9 , & V_16 , V_18 , V_11 ) ;
V_17 ++ ;
goto V_22;
}
F_15 ( & V_15 -> V_23 -> V_24 , V_21 ) ;
}
static void
F_16 ( struct V_1 * V_2 , struct V_14 * V_15 , T_2 V_11 )
{
F_1 ( V_2 , L_8 , V_15 ) ;
F_1 ( V_2 , L_9 , V_15 -> V_27 ) ;
F_1 ( V_2 , L_10 , V_28 ) ;
F_1 ( V_2 , L_11 ) ;
F_4 ( V_2 , V_15 -> V_29 ) ;
F_1 ( V_2 , L_6 ) ;
#ifdef F_17
F_1 ( V_2 , L_12 ,
( unsigned long long ) F_7 ( V_15 -> V_30 ) ) ;
#endif
F_1 ( V_2 , L_13 ) ;
F_10 ( V_2 , V_15 , V_11 + F_7 ( V_15 -> V_30 ) ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_31 , T_2 V_11 )
{
struct V_32 * V_23 = & F_19 ( V_33 , V_31 ) ;
int V_18 ;
F_1 ( V_2 , L_14 , V_31 ) ;
for ( V_18 = 0 ; V_18 < V_34 ; V_18 ++ ) {
F_1 ( V_2 , L_15 , V_18 ) ;
F_16 ( V_2 , V_23 -> V_35 + V_18 , V_11 ) ;
}
#define F_20 ( T_3 ) \
SEQ_printf(m, " .%-15s: %Lu\n", #x, \
(unsigned long long)(cpu_base->x))
#define F_21 ( T_3 ) \
SEQ_printf(m, " .%-15s: %Lu nsecs\n", #x, \
(unsigned long long)(ktime_to_ns(cpu_base->x)))
#ifdef F_17
F_21 ( V_36 ) ;
F_20 ( V_37 ) ;
F_20 ( V_38 ) ;
F_20 ( V_39 ) ;
F_20 ( V_40 ) ;
F_20 ( V_41 ) ;
#endif
#undef F_20
#undef F_21
#ifdef F_22
# define F_20 ( T_3 ) \
SEQ_printf(m, " .%-15s: %Lu\n", #x, \
(unsigned long long)(ts->x))
# define F_21 ( T_3 ) \
SEQ_printf(m, " .%-15s: %Lu nsecs\n", #x, \
(unsigned long long)(ktime_to_ns(ts->x)))
{
struct V_42 * V_43 = F_23 ( V_31 ) ;
F_20 ( V_44 ) ;
F_21 ( V_45 ) ;
F_20 ( V_46 ) ;
F_20 ( V_47 ) ;
F_20 ( V_48 ) ;
F_20 ( V_49 ) ;
F_21 ( V_50 ) ;
F_21 ( V_51 ) ;
F_21 ( V_52 ) ;
F_21 ( V_53 ) ;
F_21 ( V_54 ) ;
F_20 ( V_55 ) ;
F_20 ( V_56 ) ;
F_21 ( V_57 ) ;
F_1 ( V_2 , L_16 ,
( unsigned long long ) V_58 ) ;
}
#endif
#undef F_20
#undef F_21
F_1 ( V_2 , L_6 ) ;
}
static void
F_24 ( struct V_1 * V_2 , struct V_59 * V_60 , int V_31 )
{
struct V_61 * V_62 = V_60 -> V_63 ;
F_1 ( V_2 , L_17 , V_60 -> V_64 ) ;
if ( V_31 < 0 )
F_1 ( V_2 , L_18 ) ;
else
F_1 ( V_2 , L_19 , V_31 ) ;
F_1 ( V_2 , L_20 ) ;
if ( ! V_62 ) {
F_1 ( V_2 , L_21 ) ;
return;
}
F_1 ( V_2 , L_22 , V_62 -> V_65 ) ;
F_1 ( V_2 , L_23 ,
( unsigned long long ) V_62 -> V_66 ) ;
F_1 ( V_2 , L_24 ,
( unsigned long long ) V_62 -> V_67 ) ;
F_1 ( V_2 , L_25 , V_62 -> V_68 ) ;
F_1 ( V_2 , L_26 , V_62 -> V_69 ) ;
F_1 ( V_2 , L_27 , F_25 ( V_62 ) ) ;
F_1 ( V_2 , L_28 ,
( unsigned long long ) F_7 ( V_62 -> V_70 ) ) ;
F_1 ( V_2 , L_29 ) ;
F_4 ( V_2 , V_62 -> V_71 ) ;
F_1 ( V_2 , L_6 ) ;
if ( V_62 -> V_72 ) {
F_1 ( V_2 , L_30 ) ;
F_4 ( V_2 , V_62 -> V_72 ) ;
F_1 ( V_2 , L_6 ) ;
}
if ( V_62 -> V_73 ) {
F_1 ( V_2 , L_31 ) ;
F_4 ( V_2 , V_62 -> V_73 ) ;
F_1 ( V_2 , L_6 ) ;
}
if ( V_62 -> V_74 ) {
F_1 ( V_2 , L_32 ) ;
F_4 ( V_2 , V_62 -> V_74 ) ;
F_1 ( V_2 , L_6 ) ;
}
if ( V_62 -> V_75 ) {
F_1 ( V_2 , L_33 ) ;
F_4 ( V_2 , V_62 -> V_75 ) ;
F_1 ( V_2 , L_6 ) ;
}
if ( V_62 -> V_76 ) {
F_1 ( V_2 , L_34 ) ;
F_4 ( V_2 , V_62 -> V_76 ) ;
F_1 ( V_2 , L_6 ) ;
}
F_1 ( V_2 , L_35 ) ;
F_4 ( V_2 , V_62 -> V_77 ) ;
F_1 ( V_2 , L_6 ) ;
F_1 ( V_2 , L_36 , V_62 -> V_78 ) ;
F_1 ( V_2 , L_6 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
#ifdef F_27
F_24 ( V_2 , F_28 () , - 1 ) ;
F_1 ( V_2 , L_37 ,
F_29 ( F_30 () ) ) ;
#ifdef F_22
F_1 ( V_2 , L_38 ,
F_29 ( F_31 () ) ) ;
#endif
F_1 ( V_2 , L_6 ) ;
#endif
}
static inline void F_32 ( struct V_1 * V_2 , T_2 V_11 )
{
F_1 ( V_2 , L_39 ) ;
F_1 ( V_2 , L_40 , V_34 ) ;
F_1 ( V_2 , L_41 , ( unsigned long long ) V_11 ) ;
F_1 ( V_2 , L_6 ) ;
}
static int F_33 ( struct V_1 * V_2 , void * V_79 )
{
struct V_80 * V_81 = V_79 ;
if ( V_81 -> V_31 == - 1 && ! V_81 -> V_82 )
F_32 ( V_2 , V_81 -> V_11 ) ;
else if ( ! V_81 -> V_82 )
F_18 ( V_2 , V_81 -> V_31 , V_81 -> V_11 ) ;
#ifdef F_34
else if ( V_81 -> V_31 == - 1 && V_81 -> V_82 )
F_26 ( V_2 ) ;
else
F_24 ( V_2 , F_35 ( V_81 -> V_31 ) , V_81 -> V_31 ) ;
#endif
return 0 ;
}
void F_36 ( void )
{
T_2 V_11 = F_7 ( F_37 () ) ;
int V_31 ;
F_32 ( NULL , V_11 ) ;
F_38 (cpu)
F_18 ( NULL , V_31 , V_11 ) ;
#ifdef F_34
F_26 ( NULL ) ;
F_38 (cpu)
F_24 ( NULL , F_35 ( V_31 ) , V_31 ) ;
#endif
return;
}
static void * F_39 ( struct V_80 * V_81 , T_4 V_30 )
{
for (; V_30 ; V_30 -- ) {
V_81 -> V_31 = F_40 ( V_81 -> V_31 , V_83 ) ;
if ( V_81 -> V_31 >= V_84 ) {
#ifdef F_34
if ( ! V_81 -> V_82 ) {
V_81 -> V_31 = - 1 ;
V_81 -> V_82 = true ;
} else
return NULL ;
#else
return NULL ;
#endif
}
}
return V_81 ;
}
static void * F_41 ( struct V_1 * V_85 , T_4 * V_30 )
{
struct V_80 * V_81 = V_85 -> V_86 ;
if ( ! * V_30 )
V_81 -> V_11 = F_7 ( F_37 () ) ;
V_81 -> V_31 = - 1 ;
V_81 -> V_82 = false ;
return F_39 ( V_81 , * V_30 ) ;
}
static void * F_42 ( struct V_1 * V_85 , void * V_79 , T_4 * V_30 )
{
struct V_80 * V_81 = V_85 -> V_86 ;
++ * V_30 ;
return F_39 ( V_81 , 1 ) ;
}
static void F_43 ( struct V_1 * V_87 , void * V_79 )
{
}
static int F_44 ( struct V_88 * V_88 , struct V_85 * V_89 )
{
return F_45 ( V_89 , & V_90 ,
sizeof( struct V_80 ) ) ;
}
static int T_5 F_46 ( void )
{
struct V_91 * V_92 ;
V_92 = F_47 ( L_42 , 0444 , NULL , & V_93 ) ;
if ( ! V_92 )
return - V_94 ;
return 0 ;
}
