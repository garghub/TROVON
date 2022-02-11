static void F_1 ( struct V_1 * V_2 )
{
if ( V_3 ) {
F_2 () ;
F_3 ( & V_2 -> V_4 ) ;
}
}
static int F_4 ( struct V_1 * V_2 ,
const char * V_5 , T_1 args )
{
int V_6 ;
T_2 V_7 ;
V_8:
V_7 = F_5 ( & V_2 -> V_7 ) ;
if ( V_7 >= sizeof( V_2 -> V_9 ) - 1 ) {
F_6 ( & V_2 -> V_10 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( ! V_7 )
F_2 () ;
V_6 = F_7 ( V_2 -> V_9 + V_7 , sizeof( V_2 -> V_9 ) - V_7 , V_5 , args ) ;
if ( ! V_6 )
return 0 ;
if ( F_8 ( & V_2 -> V_7 , V_7 , V_7 + V_6 ) != V_7 )
goto V_8;
F_1 ( V_2 ) ;
return V_6 ;
}
static inline void F_9 ( const char * V_11 , int V_7 )
{
F_10 ( L_1 , V_7 , V_11 ) ;
}
static int F_11 ( const char * V_12 , T_2 V_7 )
{
const char * V_13 , * V_14 ;
bool V_15 ;
V_13 = V_12 ;
V_14 = V_12 + V_7 ;
V_15 = true ;
while ( V_13 < V_14 ) {
if ( * V_13 == '\n' ) {
F_9 ( V_12 , V_13 - V_12 + 1 ) ;
V_12 = ++ V_13 ;
V_15 = true ;
continue;
}
if ( ( V_13 + 1 < V_14 ) && F_12 ( V_13 ) ) {
if ( V_15 ) {
V_13 = F_13 ( V_13 ) ;
continue;
}
F_9 ( V_12 , V_13 - V_12 ) ;
V_12 = V_13 ++ ;
V_15 = true ;
continue;
}
V_15 = false ;
V_13 ++ ;
}
if ( V_12 < V_14 && ! V_15 ) {
static const char V_16 [] = V_17 L_2 ;
F_9 ( V_12 , V_14 - V_12 ) ;
F_9 ( V_16 , strlen ( V_16 ) ) ;
}
return V_7 ;
}
static void F_14 ( struct V_1 * V_2 )
{
int V_18 = F_15 ( & V_2 -> V_10 , 0 ) ;
if ( V_18 )
F_10 ( L_3 , V_18 ) ;
}
static void F_16 ( struct V_19 * V_4 )
{
static T_3 V_20 =
F_17 ( V_20 ) ;
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_21 ;
T_2 V_7 ;
int V_22 ;
F_19 ( & V_20 , V_21 ) ;
V_22 = 0 ;
V_23:
V_7 = F_5 ( & V_2 -> V_7 ) ;
if ( ( V_22 && V_22 >= V_7 ) || V_7 > sizeof( V_2 -> V_9 ) ) {
const char * V_24 = L_4 ;
F_9 ( V_24 , strlen ( V_24 ) ) ;
V_7 = 0 ;
}
if ( ! V_7 )
goto V_25;
F_2 () ;
V_22 += F_11 ( V_2 -> V_9 + V_22 , V_7 - V_22 ) ;
if ( F_8 ( & V_2 -> V_7 , V_7 , 0 ) != V_7 )
goto V_23;
V_25:
F_14 ( V_2 ) ;
F_20 ( & V_20 , V_21 ) ;
}
void F_21 ( void )
{
int V_26 ;
F_22 (cpu) {
#ifdef F_23
F_16 ( & F_24 ( V_27 , V_26 ) . V_4 ) ;
#endif
F_16 ( & F_24 ( V_28 , V_26 ) . V_4 ) ;
}
}
void F_25 ( void )
{
if ( F_26 () && F_27 ( & V_29 ) ) {
if ( F_28 () > 1 )
return;
F_29 () ;
F_30 ( & V_29 ) ;
}
F_21 () ;
}
static int F_31 ( const char * V_5 , T_1 args )
{
struct V_1 * V_2 = F_32 ( & V_27 ) ;
return F_4 ( V_2 , V_5 , args ) ;
}
void F_33 ( void )
{
F_34 ( V_30 , V_31 ) ;
}
void F_35 ( void )
{
F_36 ( V_30 , ~ V_31 ) ;
}
static int F_31 ( const char * V_5 , T_1 args )
{
return 0 ;
}
static int F_37 ( const char * V_5 , T_1 args )
{
struct V_1 * V_2 = F_32 ( & V_28 ) ;
return F_4 ( V_2 , V_5 , args ) ;
}
void F_38 ( void )
{
F_39 ( V_30 ) ;
}
void F_40 ( void )
{
F_41 ( V_30 ) ;
}
int F_42 ( const char * V_5 , T_1 args )
{
if ( F_43 ( V_30 ) & V_31 )
return F_31 ( V_5 , args ) ;
if ( F_43 ( V_30 ) & V_32 )
return F_37 ( V_5 , args ) ;
return F_44 ( V_5 , args ) ;
}
void T_4 F_45 ( void )
{
int V_26 ;
F_22 (cpu) {
struct V_1 * V_2 ;
V_2 = & F_24 ( V_28 , V_26 ) ;
F_46 ( & V_2 -> V_4 , F_16 ) ;
#ifdef F_23
V_2 = & F_24 ( V_27 , V_26 ) ;
F_46 ( & V_2 -> V_4 , F_16 ) ;
#endif
}
F_47 () ;
V_3 = 1 ;
F_21 () ;
}
