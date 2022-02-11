static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 , V_5 ;
struct V_6 * V_7 ;
unsigned long V_8 , V_9 = 0 , V_10 = 0 , V_11 = 0 ;
unsigned int V_12 , V_13 ;
V_12 = V_2 -> V_14 ;
V_13 = V_15 [ V_3 ] . V_16 ;
V_8 = V_13 * 1000 ;
V_5 = F_2 ( V_2 -> V_17 , V_8 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_18 ,
L_1 ,
V_8 ) ;
return V_5 ;
}
V_8 = V_5 ;
if ( V_19 ) {
F_5 () ;
V_7 = F_6 ( V_18 , & V_8 ) ;
if ( F_7 ( V_7 ) ) {
F_8 () ;
F_9 ( V_18 , L_2 ,
V_20 , V_13 ) ;
return - V_21 ;
}
V_9 = F_10 ( V_7 ) ;
F_8 () ;
V_11 = V_9 * V_22 / 100 ;
V_10 = F_11 ( V_19 ) ;
}
F_12 ( V_18 , L_3 ,
V_12 / 1000 , V_10 ? V_10 / 1000 : - 1 ,
V_13 / 1000 , V_9 ? V_9 / 1000 : - 1 ) ;
if ( V_19 && ( V_13 > V_12 ) ) {
V_4 = F_13 ( V_19 , V_9 - V_11 , V_9 + V_11 ) ;
if ( V_4 < 0 ) {
F_4 ( V_18 , L_4 ,
V_20 ) ;
return V_4 ;
}
}
V_5 = F_14 ( V_2 -> V_17 , V_13 * 1000 ) ;
if ( V_19 && ( V_13 < V_12 ) ) {
V_4 = F_13 ( V_19 , V_9 - V_11 , V_9 + V_11 ) ;
if ( V_4 < 0 ) {
F_4 ( V_18 , L_5 ,
V_20 ) ;
F_14 ( V_2 -> V_17 , V_12 * 1000 ) ;
return V_4 ;
}
}
return V_5 ;
}
static inline void F_15 ( void )
{
if ( F_16 ( & V_23 ) )
F_17 ( V_18 , & V_15 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_24 ;
V_2 -> V_17 = F_19 ( NULL , L_6 ) ;
if ( F_7 ( V_2 -> V_17 ) )
return F_20 ( V_2 -> V_17 ) ;
if ( ! V_15 ) {
V_24 = F_21 ( V_18 , & V_15 ) ;
if ( V_24 ) {
F_9 ( V_18 ,
L_7 ,
V_20 , V_2 -> V_25 , V_24 ) ;
goto V_26;
}
}
F_22 ( & V_23 ) ;
V_24 = F_23 ( V_2 , V_15 , 300 * 1000 ) ;
if ( ! V_24 )
return 0 ;
F_15 () ;
V_26:
F_24 ( V_2 -> V_17 ) ;
return V_24 ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_25 ) ;
F_15 () ;
F_24 ( V_2 -> V_17 ) ;
return 0 ;
}
static int F_27 ( struct V_27 * V_28 )
{
V_18 = F_28 ( 0 ) ;
if ( ! V_18 ) {
F_29 ( L_8 , V_20 ) ;
return - V_21 ;
}
V_19 = F_30 ( V_18 , L_9 ) ;
if ( F_7 ( V_19 ) ) {
F_29 ( L_10 , V_20 ) ;
V_19 = NULL ;
} else {
if ( F_11 ( V_19 ) < 0 ) {
F_31 ( L_11 ,
V_20 ) ;
F_32 ( V_19 ) ;
V_19 = NULL ;
}
}
return F_33 ( & V_29 ) ;
}
static int F_34 ( struct V_27 * V_28 )
{
return F_35 ( & V_29 ) ;
}
