static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_5 = - V_6 ;
T_1 V_7 , V_8 ;
unsigned long V_9 , V_10 ;
struct V_11 * V_12 ;
V_12 = F_2 ( sizeof( * V_12 ) , V_13 ) ;
if ( ! V_12 )
return - V_14 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 ) {
F_4 ( L_1 ) ;
goto V_15;
}
if ( V_4 -> V_16 == V_17 ) {
V_12 -> V_18 = V_17 ;
V_8 = F_5 ( V_2 , 0 ) ;
V_10 = F_6 ( V_2 , 1 ) ;
V_7 = F_5 ( V_2 , 1 ) ;
V_9 = F_6 ( V_2 , 1 ) ;
} else {
V_12 -> V_18 = V_19 ;
V_7 = F_5 ( V_2 , 0 ) ;
V_9 = F_6 ( V_2 , 0 ) ;
V_8 = F_5 ( V_2 , 1 ) ;
V_10 = F_6 ( V_2 , 1 ) ;
if ( ! V_10 ) {
V_8 = V_7 + V_9 ;
V_10 = V_9 ;
}
}
F_7 ( V_2 ) ;
V_12 -> V_2 = & V_2 -> V_2 ;
V_12 -> V_20 = V_2 -> V_20 ;
V_5 = F_8 ( V_2 , V_21 ) ;
if ( V_5 ) {
F_4 ( L_2 ) ;
goto V_22;
}
V_12 -> V_23 = F_9 ( V_7 , V_9 ) ;
if ( ! V_12 -> V_23 ) {
F_4 ( L_3 ) ;
V_5 = - V_14 ;
goto V_24;
}
V_12 -> V_25 = F_9 ( V_8 , V_10 ) ;
if ( ! V_12 -> V_25 ) {
F_4 ( L_4 ) ;
V_5 = - V_14 ;
goto V_26;
}
V_5 = F_10 ( V_12 ) ;
if ( V_5 )
goto V_27;
F_11 ( V_2 , V_12 ) ;
return 0 ;
V_27:
F_12 ( V_12 -> V_25 ) ;
V_26:
F_12 ( V_12 -> V_23 ) ;
V_24:
F_13 ( V_2 ) ;
V_22:
F_14 ( V_2 ) ;
V_15:
F_15 ( V_12 ) ;
return V_5 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_17 ( V_2 ) ;
F_18 ( V_12 ) ;
F_12 ( V_12 -> V_23 ) ;
F_12 ( V_12 -> V_25 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_11 ( V_2 , NULL ) ;
F_15 ( V_12 ) ;
}
static int F_19 ( void )
{
F_20 ( L_5 , __DATE__ , __TIME__ ) ;
return F_21 ( & V_28 ) ;
}
static void F_22 ( void )
{
F_23 ( & V_28 ) ;
}
