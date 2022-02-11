void F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_4 , false ) ;
F_3 ( V_2 , V_3 ) ;
}
bool F_4 ( struct V_1 * V_2 )
{
return ! V_2 ||
F_5 ( & V_2 -> V_5 , V_6 ) != 0 ;
}
static unsigned int F_6 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_3 ;
V_3 = F_7 ( & V_2 -> V_5 , V_7 ) ;
if ( V_3 < 0 )
return V_8 ;
return V_3 + V_2 -> V_9 ;
}
static unsigned int F_8 ( struct V_1 * V_2 ,
T_1 V_7 )
{
int V_3 ;
if ( F_9 ( ! V_2 -> V_9 ) ) {
F_10 ( 1 ) ;
return V_8 ;
}
V_3 = F_7 ( & V_2 -> V_10 , V_7 ) ;
if ( V_3 < 0 )
return V_8 ;
return V_3 ;
}
unsigned int F_2 ( struct V_1 * V_2 , T_1 V_7 , bool V_11 )
{
if ( ! V_11 )
return F_6 ( V_2 , V_7 ) ;
return F_8 ( V_2 , V_7 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_12 ( V_3 >= V_2 -> V_12 ) ;
F_13 ( & V_2 -> V_5 , V_3 - V_2 -> V_9 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
F_12 ( V_3 >= V_2 -> V_9 ) ;
F_13 ( & V_2 -> V_10 , V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 >= V_2 -> V_9 )
F_11 ( V_2 , V_3 ) ;
else
F_14 ( V_2 , V_3 ) ;
}
static int F_15 ( unsigned V_13 , void * V_14 )
{
unsigned long * V_15 = V_14 ;
F_16 ( V_13 , V_15 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 ,
void (* F_18)( void * , unsigned long * ) , void * V_14 )
{
unsigned long * V_15 ;
T_2 V_16 ;
V_16 = F_19 ( V_2 -> V_12 , V_17 ) / V_17 ;
V_15 = F_20 ( V_16 * sizeof( unsigned long ) , V_18 ) ;
if ( ! V_15 )
return;
F_21 ( & V_2 -> V_5 , F_15 , V_15 ) ;
if ( V_2 -> V_9 )
F_21 ( & V_2 -> V_10 , F_15 ,
V_15 ) ;
F_18 ( V_14 , V_15 ) ;
F_22 ( V_15 ) ;
}
struct V_1 * F_23 ( unsigned int V_19 ,
unsigned int V_10 , int V_20 )
{
unsigned int V_12 , V_21 ;
struct V_1 * V_2 ;
int V_22 ;
if ( V_19 > V_23 ) {
F_24 ( L_1 ) ;
return NULL ;
}
V_2 = F_25 ( sizeof( * V_2 ) , V_24 , V_20 ) ;
if ( ! V_2 )
return NULL ;
V_12 = V_19 - V_10 ;
V_21 = V_12 / F_26 () ;
if ( V_21 < V_25 )
V_21 = V_25 ;
else if ( V_21 > V_26 )
V_21 = V_26 ;
V_2 -> V_12 = V_19 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_27 = V_21 ;
V_2 -> V_28 = F_27 ( 1u , V_21 / 2 ) ;
V_22 = F_28 ( & V_2 -> V_5 , V_2 -> V_12 -
V_2 -> V_9 ,
V_2 -> V_27 ,
V_2 -> V_28 ) ;
if ( V_22 )
goto V_29;
if ( V_10 ) {
V_22 = F_28 ( & V_2 -> V_10 , V_10 ,
1 , 1 ) ;
if ( V_22 )
goto V_30;
}
return V_2 ;
V_30:
F_29 ( & V_2 -> V_5 ) ;
V_29:
F_22 ( V_2 ) ;
return NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_5 ) ;
F_29 ( & V_2 -> V_10 ) ;
F_22 ( V_2 ) ;
}
T_3 F_31 ( struct V_1 * V_2 , char * V_31 )
{
char * V_32 = V_31 ;
int V_33 ;
if ( ! V_2 )
return 0 ;
V_31 += sprintf ( V_31 , L_2
L_3 , V_2 -> V_12 , V_2 -> V_9 ,
V_2 -> V_28 , V_2 -> V_27 ) ;
V_31 += sprintf ( V_31 , L_4 ,
F_5 ( & V_2 -> V_5 , V_6 ) ,
F_5 ( & V_2 -> V_10 , V_6 ) ) ;
F_32 (cpu) {
V_31 += sprintf ( V_31 , L_5 , V_33 ,
F_5 ( & V_2 -> V_5 , V_33 ) ) ;
}
return V_31 - V_32 ;
}
