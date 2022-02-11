static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
const char * V_5 = V_2 -> V_6 + V_3 ;
F_2 ( L_1 , ( V_4 - V_3 ) + 1 , V_5 ) ;
}
void F_3 ( bool V_7 ,
void (* raise)( T_1 * V_8 ) )
{
struct V_1 * V_2 ;
int V_9 , V_10 , V_11 = F_4 () ;
if ( F_5 ( 0 , & V_12 ) ) {
F_6 () ;
return;
}
F_7 ( F_8 ( V_13 ) , V_14 ) ;
if ( ! V_7 )
F_9 ( V_11 , F_8 ( V_13 ) ) ;
F_7 ( & V_15 , F_8 ( V_13 ) ) ;
F_10 (cpu, to_cpumask(backtrace_mask)) {
V_2 = & F_11 ( V_16 , V_10 ) ;
F_12 ( & V_2 -> V_17 , V_2 -> V_6 , V_18 ) ;
}
if ( ! F_13 ( F_8 ( V_13 ) ) ) {
F_14 ( L_2 ,
( V_7 ? L_3 : L_4 ) ) ;
raise ( F_8 ( V_13 ) ) ;
}
for ( V_9 = 0 ; V_9 < 10 * 1000 ; V_9 ++ ) {
if ( F_13 ( F_8 ( V_13 ) ) )
break;
F_15 ( 1 ) ;
F_16 () ;
}
F_10 (cpu, &printtrace_mask) {
int V_19 , V_20 = 0 ;
V_2 = & F_11 ( V_16 , V_10 ) ;
V_19 = F_17 ( & V_2 -> V_17 ) ;
if ( ! V_19 )
continue;
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
if ( V_2 -> V_6 [ V_9 ] == '\n' ) {
F_1 ( V_2 , V_20 , V_9 ) ;
V_20 = V_9 + 1 ;
}
}
if ( V_20 < V_19 ) {
F_1 ( V_2 , V_20 , V_19 - 1 ) ;
F_18 ( L_5 ) ;
}
}
F_19 ( 0 , & V_12 ) ;
F_20 () ;
F_6 () ;
}
static int F_21 ( const char * V_21 , T_2 args )
{
struct V_1 * V_2 = F_22 ( & V_16 ) ;
unsigned int V_19 = F_17 ( & V_2 -> V_17 ) ;
F_23 ( & V_2 -> V_17 , V_21 , args ) ;
return F_17 ( & V_2 -> V_17 ) - V_19 ;
}
bool F_24 ( struct V_22 * V_23 )
{
int V_10 = F_25 () ;
if ( F_26 ( V_10 , F_8 ( V_13 ) ) ) {
T_3 V_24 = F_27 ( V_25 ) ;
F_28 ( V_25 , F_21 ) ;
F_29 ( L_6 , V_10 ) ;
F_30 ( V_23 ) ;
F_28 ( V_25 , V_24 ) ;
F_9 ( V_10 , F_8 ( V_13 ) ) ;
return true ;
}
return false ;
}
