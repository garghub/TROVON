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
#ifdef F_7
char V_12 [ V_13 + 1 ] ;
#endif
F_1 ( V_2 , L_3 , V_10 ) ;
F_4 ( V_2 , V_8 ) ;
F_1 ( V_2 , L_4 ) ;
F_4 ( V_2 , V_9 -> V_14 ) ;
F_1 ( V_2 , L_5 , V_9 -> V_15 ) ;
#ifdef F_7
F_1 ( V_2 , L_4 ) ;
F_4 ( V_2 , V_9 -> V_16 ) ;
memcpy ( V_12 , V_9 -> V_17 , V_13 ) ;
V_12 [ V_13 ] = 0 ;
F_1 ( V_2 , L_6 , V_12 , V_9 -> V_18 ) ;
#endif
F_1 ( V_2 , L_7 ) ;
F_1 ( V_2 , L_8 ,
( unsigned long long ) F_8 ( F_9 ( V_9 ) ) ,
( unsigned long long ) F_8 ( F_10 ( V_9 ) ) ,
( long long ) ( F_8 ( F_9 ( V_9 ) ) - V_11 ) ,
( long long ) ( F_8 ( F_10 ( V_9 ) ) - V_11 ) ) ;
}
static void
F_11 ( struct V_1 * V_2 , struct V_19 * V_20 ,
T_2 V_11 )
{
struct V_7 * V_9 , V_12 ;
unsigned long V_21 = 0 , V_22 ;
struct V_23 * V_24 ;
unsigned long V_25 ;
V_26:
V_22 = 0 ;
F_12 ( & V_20 -> V_27 -> V_28 , V_25 ) ;
V_24 = F_13 ( & V_20 -> V_29 ) ;
while ( V_24 && V_22 < V_21 ) {
V_24 = F_14 ( V_24 ) ;
V_22 ++ ;
}
if ( V_24 ) {
V_9 = F_15 ( V_24 , struct V_7 , V_30 ) ;
V_12 = * V_9 ;
F_16 ( & V_20 -> V_27 -> V_28 , V_25 ) ;
F_6 ( V_2 , V_9 , & V_12 , V_22 , V_11 ) ;
V_21 ++ ;
goto V_26;
}
F_16 ( & V_20 -> V_27 -> V_28 , V_25 ) ;
}
static void
F_17 ( struct V_1 * V_2 , struct V_19 * V_20 , T_2 V_11 )
{
F_1 ( V_2 , L_9 , V_20 ) ;
F_1 ( V_2 , L_10 , V_20 -> V_31 ) ;
F_1 ( V_2 , L_11 , ( unsigned ) V_32 ) ;
F_1 ( V_2 , L_12 ) ;
F_4 ( V_2 , V_20 -> V_33 ) ;
F_1 ( V_2 , L_7 ) ;
#ifdef F_18
F_1 ( V_2 , L_13 ,
( unsigned long long ) F_8 ( V_20 -> V_34 ) ) ;
#endif
F_1 ( V_2 , L_14 ) ;
F_11 ( V_2 , V_20 , V_11 + F_8 ( V_20 -> V_34 ) ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_35 , T_2 V_11 )
{
struct V_36 * V_27 = & F_20 ( V_37 , V_35 ) ;
int V_22 ;
F_1 ( V_2 , L_15 , V_35 ) ;
for ( V_22 = 0 ; V_22 < V_38 ; V_22 ++ ) {
F_1 ( V_2 , L_16 , V_22 ) ;
F_17 ( V_2 , V_27 -> V_39 + V_22 , V_11 ) ;
}
#define F_21 ( T_3 ) \
SEQ_printf(m, " .%-15s: %Lu\n", #x, \
(unsigned long long)(cpu_base->x))
#define F_22 ( T_3 ) \
SEQ_printf(m, " .%-15s: %Lu nsecs\n", #x, \
(unsigned long long)(ktime_to_ns(cpu_base->x)))
#ifdef F_18
F_22 ( V_40 ) ;
F_21 ( V_41 ) ;
F_21 ( V_42 ) ;
F_21 ( V_43 ) ;
F_21 ( V_44 ) ;
F_21 ( V_45 ) ;
#endif
#undef F_21
#undef F_22
#ifdef F_23
# define F_21 ( T_3 ) \
SEQ_printf(m, " .%-15s: %Lu\n", #x, \
(unsigned long long)(ts->x))
# define F_22 ( T_3 ) \
SEQ_printf(m, " .%-15s: %Lu nsecs\n", #x, \
(unsigned long long)(ktime_to_ns(ts->x)))
{
struct V_46 * V_47 = F_24 ( V_35 ) ;
F_21 ( V_48 ) ;
F_22 ( V_49 ) ;
F_21 ( V_50 ) ;
F_21 ( V_51 ) ;
F_21 ( V_52 ) ;
F_21 ( V_53 ) ;
F_22 ( V_54 ) ;
F_22 ( V_55 ) ;
F_22 ( V_56 ) ;
F_22 ( V_57 ) ;
F_22 ( V_58 ) ;
F_21 ( V_59 ) ;
F_21 ( V_60 ) ;
F_22 ( V_61 ) ;
F_1 ( V_2 , L_17 ,
( unsigned long long ) V_62 ) ;
}
#endif
#undef F_21
#undef F_22
F_1 ( V_2 , L_7 ) ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_63 * V_64 , int V_35 )
{
struct V_65 * V_66 = V_64 -> V_67 ;
F_1 ( V_2 , L_18 , V_64 -> V_68 ) ;
if ( V_35 < 0 )
F_1 ( V_2 , L_19 ) ;
else
F_1 ( V_2 , L_20 , V_35 ) ;
F_1 ( V_2 , L_21 ) ;
if ( ! V_66 ) {
F_1 ( V_2 , L_22 ) ;
return;
}
F_1 ( V_2 , L_23 , V_66 -> V_69 ) ;
F_1 ( V_2 , L_24 ,
( unsigned long long ) V_66 -> V_70 ) ;
F_1 ( V_2 , L_25 ,
( unsigned long long ) V_66 -> V_71 ) ;
F_1 ( V_2 , L_26 , V_66 -> V_72 ) ;
F_1 ( V_2 , L_27 , V_66 -> V_73 ) ;
F_1 ( V_2 , L_28 , F_26 ( V_66 ) ) ;
F_1 ( V_2 , L_29 ,
( unsigned long long ) F_8 ( V_66 -> V_74 ) ) ;
F_1 ( V_2 , L_30 ) ;
F_4 ( V_2 , V_66 -> V_75 ) ;
F_1 ( V_2 , L_7 ) ;
if ( V_66 -> V_76 ) {
F_1 ( V_2 , L_31 ) ;
F_4 ( V_2 , V_66 -> V_76 ) ;
F_1 ( V_2 , L_7 ) ;
}
if ( V_66 -> V_77 ) {
F_1 ( V_2 , L_32 ) ;
F_4 ( V_2 , V_66 -> V_77 ) ;
F_1 ( V_2 , L_7 ) ;
}
if ( V_66 -> V_78 ) {
F_1 ( V_2 , L_33 ) ;
F_4 ( V_2 , V_66 -> V_78 ) ;
F_1 ( V_2 , L_7 ) ;
}
if ( V_66 -> V_79 ) {
F_1 ( V_2 , L_34 ) ;
F_4 ( V_2 , V_66 -> V_79 ) ;
F_1 ( V_2 , L_7 ) ;
}
if ( V_66 -> V_80 ) {
F_1 ( V_2 , L_35 ) ;
F_4 ( V_2 , V_66 -> V_80 ) ;
F_1 ( V_2 , L_7 ) ;
}
F_1 ( V_2 , L_36 ) ;
F_4 ( V_2 , V_66 -> V_81 ) ;
F_1 ( V_2 , L_7 ) ;
F_1 ( V_2 , L_37 , V_66 -> V_82 ) ;
F_1 ( V_2 , L_7 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
#ifdef F_28
F_25 ( V_2 , F_29 () , - 1 ) ;
F_1 ( V_2 , L_38 ,
F_30 ( F_31 () ) ) ;
#ifdef F_23
F_1 ( V_2 , L_39 ,
F_30 ( F_32 () ) ) ;
#endif
F_1 ( V_2 , L_7 ) ;
#endif
}
static inline void F_33 ( struct V_1 * V_2 , T_2 V_11 )
{
F_1 ( V_2 , L_40 ) ;
F_1 ( V_2 , L_41 , V_38 ) ;
F_1 ( V_2 , L_42 , ( unsigned long long ) V_11 ) ;
F_1 ( V_2 , L_7 ) ;
}
static int F_34 ( struct V_1 * V_2 , void * V_83 )
{
struct V_84 * V_85 = V_83 ;
if ( V_85 -> V_35 == - 1 && ! V_85 -> V_86 )
F_33 ( V_2 , V_85 -> V_11 ) ;
else if ( ! V_85 -> V_86 )
F_19 ( V_2 , V_85 -> V_35 , V_85 -> V_11 ) ;
#ifdef F_35
else if ( V_85 -> V_35 == - 1 && V_85 -> V_86 )
F_27 ( V_2 ) ;
else
F_25 ( V_2 , F_36 ( V_85 -> V_35 ) , V_85 -> V_35 ) ;
#endif
return 0 ;
}
void F_37 ( void )
{
T_2 V_11 = F_8 ( F_38 () ) ;
int V_35 ;
F_33 ( NULL , V_11 ) ;
F_39 (cpu)
F_19 ( NULL , V_35 , V_11 ) ;
#ifdef F_35
F_27 ( NULL ) ;
F_39 (cpu)
F_25 ( NULL , F_36 ( V_35 ) , V_35 ) ;
#endif
return;
}
static void * F_40 ( struct V_84 * V_85 , T_4 V_34 )
{
for (; V_34 ; V_34 -- ) {
V_85 -> V_35 = F_41 ( V_85 -> V_35 , V_87 ) ;
if ( V_85 -> V_35 >= V_88 ) {
#ifdef F_35
if ( ! V_85 -> V_86 ) {
V_85 -> V_35 = - 1 ;
V_85 -> V_86 = true ;
} else
return NULL ;
#else
return NULL ;
#endif
}
}
return V_85 ;
}
static void * F_42 ( struct V_1 * V_89 , T_4 * V_34 )
{
struct V_84 * V_85 = V_89 -> V_90 ;
if ( ! * V_34 )
V_85 -> V_11 = F_8 ( F_38 () ) ;
V_85 -> V_35 = - 1 ;
V_85 -> V_86 = false ;
return F_40 ( V_85 , * V_34 ) ;
}
static void * F_43 ( struct V_1 * V_89 , void * V_83 , T_4 * V_34 )
{
struct V_84 * V_85 = V_89 -> V_90 ;
++ * V_34 ;
return F_40 ( V_85 , 1 ) ;
}
static void F_44 ( struct V_1 * V_91 , void * V_83 )
{
}
static int F_45 ( struct V_92 * V_92 , struct V_89 * V_93 )
{
return F_46 ( V_93 , & V_94 ,
sizeof( struct V_84 ) ) ;
}
static int T_5 F_47 ( void )
{
struct V_95 * V_96 ;
V_96 = F_48 ( L_43 , 0444 , NULL , & V_97 ) ;
if ( ! V_96 )
return - V_98 ;
return 0 ;
}
