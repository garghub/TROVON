static void F_1 ( struct V_1 * V_2 )
{
if ( V_3 ) {
F_2 () ;
F_3 ( & V_2 -> V_4 ) ;
}
}
inline void F_4 ( const char * V_5 , int V_6 )
{
F_5 ( L_1 , V_6 , V_5 ) ;
}
static int F_6 ( const char * V_7 , T_1 V_6 )
{
const char * V_8 , * V_9 ;
bool V_10 ;
V_8 = V_7 ;
V_9 = V_7 + V_6 ;
V_10 = true ;
while ( V_8 < V_9 ) {
if ( * V_8 == '\n' ) {
F_4 ( V_7 , V_8 - V_7 + 1 ) ;
V_7 = ++ V_8 ;
V_10 = true ;
continue;
}
if ( ( V_8 + 1 < V_9 ) && F_7 ( V_8 ) ) {
if ( V_10 ) {
V_8 = F_8 ( V_8 ) ;
continue;
}
F_4 ( V_7 , V_8 - V_7 ) ;
V_7 = V_8 ++ ;
V_10 = true ;
continue;
}
V_10 = false ;
V_8 ++ ;
}
if ( V_7 < V_9 && ! V_10 ) {
static const char V_11 [] = V_12 L_2 ;
F_4 ( V_7 , V_9 - V_7 ) ;
F_4 ( V_11 , strlen ( V_11 ) ) ;
}
return V_6 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_13 = F_10 ( & V_2 -> V_14 , 0 ) ;
if ( V_13 )
F_5 ( L_3 , V_13 ) ;
}
static void F_11 ( struct V_15 * V_4 )
{
static T_2 V_16 =
F_12 ( V_16 ) ;
struct V_1 * V_2 =
F_13 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_17 ;
T_1 V_6 ;
int V_18 ;
F_14 ( & V_16 , V_17 ) ;
V_18 = 0 ;
V_19:
V_6 = F_15 ( & V_2 -> V_6 ) ;
if ( ( V_18 && V_18 >= V_6 ) || V_6 > sizeof( V_2 -> V_20 ) ) {
const char * V_21 = L_4 ;
F_4 ( V_21 , strlen ( V_21 ) ) ;
V_6 = 0 ;
}
if ( ! V_6 )
goto V_22;
F_2 () ;
V_18 += F_6 ( V_2 -> V_20 + V_18 , V_6 - V_18 ) ;
if ( F_16 ( & V_2 -> V_6 , V_6 , 0 ) != V_6 )
goto V_19;
V_22:
F_9 ( V_2 ) ;
F_17 ( & V_16 , V_17 ) ;
}
void F_18 ( void )
{
int V_23 ;
F_19 (cpu) {
#ifdef F_20
F_11 ( & F_21 ( V_24 , V_23 ) . V_4 ) ;
#endif
F_11 ( & F_21 ( V_25 , V_23 ) . V_4 ) ;
}
}
void F_22 ( void )
{
if ( F_23 () && F_24 ( & V_26 ) ) {
if ( F_25 () > 1 )
return;
F_26 () ;
F_27 ( & V_26 ) ;
}
F_18 () ;
}
void F_28 ( void )
{
if ( ( F_29 ( V_27 ) & V_28 ) &&
F_24 ( & V_26 ) ) {
F_30 ( V_27 , V_29 ) ;
} else {
F_30 ( V_27 , V_30 ) ;
}
}
void F_31 ( void )
{
F_32 ( V_27 ,
~ ( V_29 |
V_30 ) ) ;
}
void F_33 ( void )
{
F_34 ( V_27 ) ;
}
void F_35 ( void )
{
F_36 ( V_27 ) ;
}
int F_37 ( const char * V_31 , T_3 args )
{
if ( F_29 ( V_27 ) & V_29 )
return F_38 ( V_31 , args ) ;
if ( F_29 ( V_27 ) & V_28 )
return F_39 ( V_31 , args ) ;
if ( F_29 ( V_27 ) & V_30 )
return F_40 ( V_31 , args ) ;
return F_41 ( V_31 , args ) ;
}
void T_4 F_42 ( void )
{
int V_23 ;
F_19 (cpu) {
struct V_1 * V_2 ;
V_2 = & F_21 ( V_25 , V_23 ) ;
F_43 ( & V_2 -> V_4 , F_11 ) ;
#ifdef F_20
V_2 = & F_21 ( V_24 , V_23 ) ;
F_43 ( & V_2 -> V_4 , F_11 ) ;
#endif
}
F_44 () ;
V_3 = 1 ;
F_18 () ;
}
