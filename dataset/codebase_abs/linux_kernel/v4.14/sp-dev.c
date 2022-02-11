static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( & V_2 -> V_5 , & V_6 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_6 ( & V_2 -> V_5 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static T_1 F_7 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
if ( V_2 -> V_9 )
V_2 -> V_9 ( V_7 , V_2 -> V_10 ) ;
if ( V_2 -> V_11 )
V_2 -> V_11 ( V_7 , V_2 -> V_12 ) ;
return V_13 ;
}
int F_8 ( struct V_1 * V_2 , T_2 V_14 ,
const char * V_15 , void * V_8 )
{
int V_16 ;
if ( ( V_2 -> V_17 == V_2 -> V_18 ) && V_2 -> V_19 -> V_20 ) {
V_2 -> V_10 = V_8 ;
V_2 -> V_9 = V_14 ;
if ( ! V_2 -> V_21 ) {
V_16 = F_9 ( V_2 -> V_18 , F_7 , 0 ,
V_2 -> V_15 , V_2 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_21 = true ;
}
} else {
V_16 = F_9 ( V_2 -> V_18 , V_14 , 0 , V_15 , V_8 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 , T_2 V_14 ,
const char * V_15 , void * V_8 )
{
int V_16 ;
if ( ( V_2 -> V_17 == V_2 -> V_18 ) && V_2 -> V_19 -> V_22 ) {
V_2 -> V_12 = V_8 ;
V_2 -> V_11 = V_14 ;
if ( ! V_2 -> V_21 ) {
V_16 = F_9 ( V_2 -> V_17 , F_7 , 0 ,
V_2 -> V_15 , V_2 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_21 = true ;
}
} else {
V_16 = F_9 ( V_2 -> V_17 , V_14 , 0 , V_15 , V_8 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
void F_11 ( struct V_1 * V_2 , void * V_8 )
{
if ( ( V_2 -> V_17 == V_2 -> V_18 ) && V_2 -> V_19 -> V_20 ) {
if ( ! V_2 -> V_11 ) {
F_12 ( V_2 -> V_18 , V_2 ) ;
V_2 -> V_21 = false ;
}
V_2 -> V_9 = NULL ;
V_2 -> V_10 = NULL ;
} else {
F_12 ( V_2 -> V_18 , V_8 ) ;
}
}
void F_13 ( struct V_1 * V_2 , void * V_8 )
{
if ( ( V_2 -> V_17 == V_2 -> V_18 ) && V_2 -> V_19 -> V_22 ) {
if ( ! V_2 -> V_9 ) {
F_12 ( V_2 -> V_17 , V_2 ) ;
V_2 -> V_21 = false ;
}
V_2 -> V_11 = NULL ;
V_2 -> V_12 = NULL ;
} else {
F_12 ( V_2 -> V_17 , V_8 ) ;
}
}
struct V_1 * F_14 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
V_2 = F_15 ( V_24 , sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_24 = V_24 ;
V_2 -> V_26 = F_16 ( & V_27 ) ;
snprintf ( V_2 -> V_15 , V_28 , L_1 , V_2 -> V_26 ) ;
return V_2 ;
}
int F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
if ( V_2 -> V_19 -> V_22 )
F_18 ( V_2 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 -> V_22 )
F_20 ( V_2 ) ;
F_5 ( V_2 ) ;
}
int F_21 ( struct V_1 * V_2 , T_3 V_29 )
{
int V_16 ;
if ( V_2 -> V_19 -> V_22 ) {
V_16 = F_22 ( V_2 , V_29 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_16 ;
if ( V_2 -> V_19 -> V_22 ) {
V_16 = F_24 ( V_2 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
static int T_4 F_25 ( void )
{
#ifdef F_26
int V_16 ;
V_16 = F_27 () ;
if ( V_16 )
return V_16 ;
return 0 ;
#endif
#ifdef F_28
int V_16 ;
V_16 = F_29 () ;
if ( V_16 )
return V_16 ;
return 0 ;
#endif
return - V_30 ;
}
static void T_5 F_30 ( void )
{
#ifdef F_26
F_31 () ;
#endif
#ifdef F_28
F_32 () ;
#endif
}
