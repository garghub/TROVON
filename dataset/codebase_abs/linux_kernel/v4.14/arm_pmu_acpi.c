static int F_1 ( int V_1 )
{
struct V_2 * V_3 ;
int V_4 , V_5 ;
V_3 = F_2 ( V_1 ) ;
if ( F_3 ( ! V_3 ) )
return - V_6 ;
V_4 = V_3 -> V_7 ;
if ( ! V_4 )
return 0 ;
if ( V_3 -> V_8 & V_9 )
V_5 = V_10 ;
else
V_5 = V_11 ;
return F_4 ( NULL , V_4 , V_5 , V_12 ) ;
}
static void F_5 ( int V_1 )
{
struct V_2 * V_3 ;
int V_4 ;
V_3 = F_2 ( V_1 ) ;
if ( ! V_3 )
return;
V_4 = V_3 -> V_7 ;
F_6 ( V_4 ) ;
}
static int F_7 ( void )
{
int V_13 , V_1 , V_14 , V_15 ;
F_8 (cpu) {
V_13 = F_1 ( V_1 ) ;
if ( V_13 < 0 ) {
V_15 = V_13 ;
F_9 ( L_1 ,
V_1 , V_15 ) ;
goto V_16;
} else if ( V_13 == 0 ) {
F_9 ( L_2 , V_1 ) ;
}
F_10 ( V_17 , V_1 ) = V_13 ;
}
return 0 ;
V_16:
F_8 (cpu) {
V_13 = F_10 ( V_17 , V_1 ) ;
if ( ! V_13 )
continue;
F_5 ( V_1 ) ;
F_8 (irq_cpu) {
if ( F_10 ( V_17 , V_14 ) == V_13 )
F_10 ( V_17 , V_14 ) = 0 ;
}
}
return V_15 ;
}
static struct V_18 * F_11 ( void )
{
unsigned long V_19 = F_12 () ;
struct V_18 * V_20 ;
int V_1 ;
F_8 (cpu) {
V_20 = F_10 ( V_21 , V_1 ) ;
if ( ! V_20 || V_20 -> V_22 != V_19 )
continue;
return V_20 ;
}
V_20 = F_13 () ;
if ( ! V_20 ) {
F_9 ( L_3 ,
F_14 () ) ;
return NULL ;
}
V_20 -> V_22 = V_19 ;
return V_20 ;
}
static int F_15 ( unsigned int V_1 )
{
struct V_18 * V_20 ;
struct V_23 T_1 * V_24 ;
int V_13 ;
if ( F_10 ( V_21 , V_1 ) )
return 0 ;
V_13 = F_10 ( V_17 , V_1 ) ;
V_20 = F_11 () ;
if ( ! V_20 )
return - V_25 ;
F_16 ( V_1 , & V_20 -> V_26 ) ;
F_10 ( V_21 , V_1 ) = V_20 ;
V_24 = V_20 -> V_24 ;
F_10 ( V_24 -> V_13 , V_1 ) = V_13 ;
F_17 ( V_20 , V_1 ) ;
return 0 ;
}
int F_18 ( T_2 V_27 )
{
int V_28 = 0 ;
int V_1 , V_29 ;
if ( V_30 )
return 0 ;
F_8 (cpu) {
struct V_18 * V_20 = F_10 ( V_21 , V_1 ) ;
char * V_31 ;
if ( ! V_20 || V_20 -> V_32 )
continue;
V_29 = V_27 ( V_20 ) ;
if ( V_29 == - V_33 ) {
continue;
} else if ( V_29 ) {
F_9 ( L_4 , V_1 ) ;
return V_29 ;
}
V_31 = V_20 -> V_32 ;
V_20 -> V_32 = F_19 ( V_34 , L_5 , V_31 , V_28 ++ ) ;
if ( ! V_20 -> V_32 ) {
F_9 ( L_6 , V_1 ) ;
return - V_25 ;
}
V_29 = F_20 ( V_20 ) ;
if ( V_29 ) {
F_9 ( L_7 , V_1 ) ;
F_21 ( V_20 -> V_32 ) ;
return V_29 ;
}
}
return 0 ;
}
static int F_22 ( void )
{
int V_29 ;
if ( V_30 )
return 0 ;
V_29 = F_7 () ;
if ( V_29 )
return V_29 ;
V_29 = F_23 ( V_35 ,
L_8 ,
F_15 , NULL ) ;
return V_29 ;
}
