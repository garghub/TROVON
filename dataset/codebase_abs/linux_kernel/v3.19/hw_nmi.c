T_1 F_1 ( int V_1 )
{
return ( T_1 ) ( V_2 ) * 1000 * V_1 ;
}
static void F_2 ( struct V_3 * V_4 , int V_5 , int V_6 )
{
const char * V_7 = V_4 -> V_8 + V_5 ;
F_3 ( L_1 , ( V_6 - V_5 ) + 1 , V_7 ) ;
}
void F_4 ( bool V_9 )
{
struct V_3 * V_4 ;
int V_10 ;
int V_11 ;
int V_12 ;
int V_13 = F_5 () ;
if ( F_6 ( 0 , & V_14 ) ) {
F_7 () ;
return;
}
F_8 ( F_9 ( V_15 ) , V_16 ) ;
if ( ! V_9 )
F_10 ( V_13 , F_9 ( V_15 ) ) ;
F_8 ( & V_17 , F_9 ( V_15 ) ) ;
F_11 (cpu, to_cpumask(backtrace_mask)) {
V_4 = & F_12 ( V_18 , V_11 ) ;
F_13 ( & V_4 -> V_19 , V_4 -> V_8 , V_20 ) ;
}
if ( ! F_14 ( F_9 ( V_15 ) ) ) {
F_15 ( L_2 ,
( V_9 ? L_3 : L_4 ) ) ;
V_21 -> V_22 ( F_9 ( V_15 ) , V_23 ) ;
}
for ( V_12 = 0 ; V_12 < 10 * 1000 ; V_12 ++ ) {
if ( F_14 ( F_9 ( V_15 ) ) )
break;
F_16 ( 1 ) ;
F_17 () ;
}
F_11 (cpu, &printtrace_mask) {
int V_24 = 0 ;
V_4 = & F_12 ( V_18 , V_11 ) ;
V_10 = F_18 ( & V_4 -> V_19 ) ;
if ( ! V_10 )
continue;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ ) {
if ( V_4 -> V_8 [ V_12 ] == '\n' ) {
F_2 ( V_4 , V_24 , V_12 ) ;
V_24 = V_12 + 1 ;
}
}
if ( V_24 < V_10 ) {
F_2 ( V_4 , V_24 , V_10 - 1 ) ;
F_19 ( L_5 ) ;
}
}
F_20 ( 0 , & V_14 ) ;
F_21 () ;
F_7 () ;
}
static int F_22 ( const char * V_25 , T_2 args )
{
struct V_3 * V_4 = F_23 ( & V_18 ) ;
unsigned int V_10 = F_18 ( & V_4 -> V_19 ) ;
F_24 ( & V_4 -> V_19 , V_25 , args ) ;
return F_18 ( & V_4 -> V_19 ) - V_10 ;
}
static int
F_25 ( unsigned int V_26 , struct V_27 * V_28 )
{
int V_11 ;
V_11 = F_26 () ;
if ( F_27 ( V_11 , F_9 ( V_15 ) ) ) {
T_3 V_29 = F_28 ( V_30 ) ;
F_29 ( V_30 , F_22 ) ;
F_3 ( V_31 L_6 , V_11 ) ;
F_30 ( V_28 ) ;
F_29 ( V_30 , V_29 ) ;
F_10 ( V_11 , F_9 ( V_15 ) ) ;
return V_32 ;
}
return V_33 ;
}
static int T_4 F_31 ( void )
{
F_32 ( V_34 , F_25 ,
0 , L_7 ) ;
return 0 ;
}
