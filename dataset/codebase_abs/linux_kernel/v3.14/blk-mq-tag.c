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
V_3 = F_7 ( & V_2 -> V_5 , ( V_7 & V_4 ) ?
V_8 : V_9 ) ;
if ( V_3 < 0 )
return V_10 ;
return V_3 + V_2 -> V_11 ;
}
static unsigned int F_8 ( struct V_1 * V_2 ,
T_1 V_7 )
{
int V_3 ;
if ( F_9 ( ! V_2 -> V_11 ) ) {
F_10 ( 1 ) ;
return V_10 ;
}
V_3 = F_7 ( & V_2 -> V_12 , ( V_7 & V_4 ) ?
V_8 : V_9 ) ;
if ( V_3 < 0 )
return V_10 ;
return V_3 ;
}
unsigned int F_2 ( struct V_1 * V_2 , T_1 V_7 , bool V_13 )
{
if ( ! V_13 )
return F_6 ( V_2 , V_7 ) ;
return F_8 ( V_2 , V_7 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_12 ( V_3 >= V_2 -> V_14 ) ;
F_13 ( & V_2 -> V_5 , V_3 - V_2 -> V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
F_12 ( V_3 >= V_2 -> V_11 ) ;
F_13 ( & V_2 -> V_12 , V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 >= V_2 -> V_11 )
F_11 ( V_2 , V_3 ) ;
else
F_14 ( V_2 , V_3 ) ;
}
static int F_15 ( unsigned V_15 , void * V_16 )
{
unsigned long * V_17 = V_16 ;
F_16 ( V_15 , V_17 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 ,
void (* F_18)( void * , unsigned long * ) , void * V_16 )
{
unsigned long * V_17 ;
T_2 V_18 ;
V_18 = F_19 ( V_2 -> V_14 , V_19 ) / V_19 ;
V_17 = F_20 ( V_18 * sizeof( unsigned long ) , V_20 ) ;
if ( ! V_17 )
return;
F_21 ( & V_2 -> V_5 , F_15 , V_17 ) ;
if ( V_2 -> V_11 )
F_21 ( & V_2 -> V_12 , F_15 ,
V_17 ) ;
F_18 ( V_16 , V_17 ) ;
F_22 ( V_17 ) ;
}
struct V_1 * F_23 ( unsigned int V_21 ,
unsigned int V_12 , int V_22 )
{
unsigned int V_14 , V_23 ;
struct V_1 * V_2 ;
int V_24 ;
if ( V_21 > V_25 ) {
F_24 ( L_1 ) ;
return NULL ;
}
V_2 = F_25 ( sizeof( * V_2 ) , V_26 , V_22 ) ;
if ( ! V_2 )
return NULL ;
V_14 = V_21 - V_12 ;
V_23 = V_14 / F_26 () ;
if ( V_23 < V_27 )
V_23 = V_27 ;
else if ( V_23 > V_28 )
V_23 = V_28 ;
V_2 -> V_14 = V_21 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_29 = V_23 ;
V_2 -> V_30 = F_27 ( 1u , V_23 / 2 ) ;
V_24 = F_28 ( & V_2 -> V_5 , V_2 -> V_14 -
V_2 -> V_11 ,
V_2 -> V_29 ,
V_2 -> V_30 ) ;
if ( V_24 )
goto V_31;
if ( V_12 ) {
V_24 = F_28 ( & V_2 -> V_12 , V_12 ,
1 , 1 ) ;
if ( V_24 )
goto V_32;
}
return V_2 ;
V_32:
F_29 ( & V_2 -> V_5 ) ;
V_31:
F_22 ( V_2 ) ;
return NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_5 ) ;
F_29 ( & V_2 -> V_12 ) ;
F_22 ( V_2 ) ;
}
T_3 F_31 ( struct V_1 * V_2 , char * V_33 )
{
char * V_34 = V_33 ;
unsigned int V_35 ;
if ( ! V_2 )
return 0 ;
V_33 += sprintf ( V_33 , L_2
L_3 , V_2 -> V_14 , V_2 -> V_11 ,
V_2 -> V_30 , V_2 -> V_29 ) ;
V_33 += sprintf ( V_33 , L_4 ,
F_5 ( & V_2 -> V_5 , V_6 ) ,
F_5 ( & V_2 -> V_12 , V_6 ) ) ;
F_32 (cpu) {
V_33 += sprintf ( V_33 , L_5 , V_35 ,
F_5 ( & V_2 -> V_5 , V_35 ) ) ;
}
return V_33 - V_34 ;
}
