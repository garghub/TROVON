static unsigned int F_1 ( unsigned int V_1 )
{
unsigned long V_2 ;
if ( V_1 >= V_3 )
return 0 ;
V_2 = F_2 ( V_4 ) / 1000 ;
return V_2 ;
}
static int F_3 ( struct V_5 * V_6 , unsigned int V_7 )
{
int V_8 , V_9 ;
struct V_10 * V_11 ;
unsigned long V_12 , V_13 = 0 , V_14 = 0 , V_15 = 0 ;
unsigned int V_16 , V_17 ;
V_16 = F_1 ( V_6 -> V_1 ) ;
V_17 = V_18 [ V_7 ] . V_19 ;
V_12 = V_17 * 1000 ;
V_9 = F_4 ( V_4 , V_12 ) ;
if ( F_5 ( V_9 ) ) {
F_6 ( V_20 ,
L_1 ,
V_12 ) ;
return V_9 ;
}
V_12 = V_9 ;
if ( V_21 ) {
F_7 () ;
V_11 = F_8 ( V_20 , & V_12 ) ;
if ( F_9 ( V_11 ) ) {
F_10 () ;
F_11 ( V_20 , L_2 ,
V_22 , V_17 ) ;
return - V_23 ;
}
V_13 = F_12 ( V_11 ) ;
F_10 () ;
V_15 = V_13 * V_24 / 100 ;
V_14 = F_13 ( V_21 ) ;
}
F_14 ( V_20 , L_3 ,
V_16 / 1000 , V_14 ? V_14 / 1000 : - 1 ,
V_17 / 1000 , V_13 ? V_13 / 1000 : - 1 ) ;
if ( V_21 && ( V_17 > V_16 ) ) {
V_8 = F_15 ( V_21 , V_13 - V_15 , V_13 + V_15 ) ;
if ( V_8 < 0 ) {
F_6 ( V_20 , L_4 ,
V_22 ) ;
return V_8 ;
}
}
V_9 = F_16 ( V_4 , V_17 * 1000 ) ;
if ( V_21 && ( V_17 < V_16 ) ) {
V_8 = F_15 ( V_21 , V_13 - V_15 , V_13 + V_15 ) ;
if ( V_8 < 0 ) {
F_6 ( V_20 , L_5 ,
V_22 ) ;
F_16 ( V_4 , V_16 * 1000 ) ;
return V_8 ;
}
}
return V_9 ;
}
static inline void F_17 ( void )
{
if ( F_18 ( & V_25 ) )
F_19 ( V_20 , & V_18 ) ;
}
static int F_20 ( struct V_5 * V_6 )
{
int V_26 ;
V_4 = F_21 ( NULL , L_6 ) ;
if ( F_9 ( V_4 ) )
return F_22 ( V_4 ) ;
if ( ! V_18 ) {
V_26 = F_23 ( V_20 , & V_18 ) ;
if ( V_26 ) {
F_11 ( V_20 ,
L_7 ,
V_22 , V_6 -> V_1 , V_26 ) ;
goto V_27;
}
}
F_24 ( & V_25 ) ;
V_26 = F_25 ( V_6 , V_18 , 300 * 1000 ) ;
if ( ! V_26 )
return 0 ;
F_17 () ;
V_27:
F_26 ( V_4 ) ;
return V_26 ;
}
static int F_27 ( struct V_5 * V_6 )
{
F_28 ( V_6 -> V_1 ) ;
F_17 () ;
F_26 ( V_4 ) ;
return 0 ;
}
static int F_29 ( struct V_28 * V_29 )
{
V_20 = F_30 ( 0 ) ;
if ( ! V_20 ) {
F_31 ( L_8 , V_22 ) ;
return - V_23 ;
}
V_21 = F_32 ( V_20 , L_9 ) ;
if ( F_9 ( V_21 ) ) {
F_31 ( L_10 , V_22 ) ;
V_21 = NULL ;
} else {
if ( F_13 ( V_21 ) < 0 ) {
F_33 ( L_11 ,
V_22 ) ;
F_34 ( V_21 ) ;
V_21 = NULL ;
}
}
return F_35 ( & V_30 ) ;
}
static int F_36 ( struct V_28 * V_29 )
{
return F_37 ( & V_30 ) ;
}
