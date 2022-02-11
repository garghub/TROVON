static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_6 - F_3 ( V_2 ) - 1 ;
if ( V_5 != - 1 ) {
unsigned long V_7 ;
F_4 ( & V_8 , V_7 ) ;
F_5 ( & V_4 -> V_9 -> V_10 , 1 << V_5 ) ;
F_6 () ;
F_7 ( & V_8 , V_7 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_6 - F_3 ( V_2 ) - 1 ;
if ( V_5 != - 1 ) {
unsigned long V_7 ;
F_4 ( & V_8 , V_7 ) ;
F_9 ( & V_4 -> V_9 -> V_10 , 1 << V_5 ) ;
F_7 ( & V_8 , V_7 ) ;
}
}
static void F_10 ( unsigned int V_5 , struct V_11 * V_12 )
{
struct V_3 * V_4 = F_11 ( V_12 ) ;
T_1 V_13 , V_10 , V_14 ;
int V_15 ;
for (; ; ) {
V_13 = F_12 ( & V_4 -> V_9 -> V_13 ) ;
V_10 = F_12 ( & V_4 -> V_9 -> V_10 ) ;
V_14 = V_13 & ~ V_10 ;
if ( ! V_14 )
break;
for ( V_15 = 0 ; V_14 != 0 ; ++ V_15 , V_14 <<= 1 ) {
if ( V_14 & 0x80000000 ) {
int V_16 = F_13 ( V_4 -> V_17 , V_15 ) ;
F_14 ( V_16 ) ;
}
}
}
}
static int F_15 ( struct V_18 * V_19 , unsigned int V_16 ,
T_2 V_20 )
{
F_16 ( V_16 , V_21 ) ;
F_17 ( V_16 , V_19 -> V_22 ) ;
F_18 ( V_16 , & V_23 , V_24 ) ;
return 0 ;
}
int T_3 F_19 ( void )
{
struct V_3 * V_4 ;
struct V_18 * V_17 ;
struct V_25 * V_26 ;
int V_27 = - V_28 ;
int V_5 ;
V_26 = F_20 ( NULL , NULL , L_1 ) ;
if ( ! V_26 ) {
F_21 ( V_29 L_2 ) ;
F_22 ( V_26 ) ;
goto V_30;
}
V_5 = F_23 ( V_26 , 0 ) ;
if ( V_5 == V_31 ) {
F_21 ( V_29 L_3 ) ;
F_22 ( V_26 ) ;
goto V_30;
}
V_4 = F_24 ( sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 ) {
F_22 ( V_26 ) ;
V_27 = - V_33 ;
goto V_34;
}
V_4 -> V_9 = F_25 ( V_26 , 0 ) ;
if ( ! V_4 -> V_9 ) {
F_21 ( V_29 L_4 ) ;
goto V_35;
}
F_26 ( & V_4 -> V_9 -> V_10 , ~ 0 ) ;
F_6 () ;
V_17 = F_27 ( V_26 , V_6 , & V_36 , V_4 ) ;
if ( ! V_17 ) {
V_27 = - V_33 ;
goto V_37;
}
V_4 -> V_17 = V_17 ;
F_28 ( V_5 , V_4 ) ;
F_29 ( V_5 , F_10 ) ;
F_22 ( V_26 ) ;
return 0 ;
V_37:
F_30 ( V_4 -> V_9 ) ;
V_35:
F_31 ( ( unsigned long ) V_4 ,
sizeof( struct V_3 ) ) ;
F_22 ( V_26 ) ;
V_34:
F_32 ( V_5 ) ;
V_30:
return V_27 ;
}
