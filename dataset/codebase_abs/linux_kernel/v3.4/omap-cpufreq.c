static int F_1 ( struct V_1 * V_2 )
{
if ( ! V_3 )
return - V_4 ;
return F_2 ( V_2 , V_3 ) ;
}
static unsigned int F_3 ( unsigned int V_5 )
{
unsigned long V_6 ;
if ( V_5 >= V_7 )
return 0 ;
V_6 = F_4 ( V_8 ) / 1000 ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_9 ,
unsigned int V_10 )
{
unsigned int V_11 ;
int V_12 , V_13 = 0 ;
struct V_14 V_15 ;
struct V_16 * V_16 ;
unsigned long V_17 , V_18 = 0 , V_19 = 0 , V_20 = 0 ;
if ( ! V_3 ) {
F_6 ( V_21 , L_1 , V_22 ,
V_2 -> V_5 ) ;
return - V_4 ;
}
V_13 = F_7 ( V_2 , V_3 , V_9 ,
V_10 , & V_11 ) ;
if ( V_13 ) {
F_8 ( V_21 , L_2 ,
V_22 , V_2 -> V_5 , V_9 , V_13 ) ;
return V_13 ;
}
V_15 . V_23 = V_3 [ V_11 ] . V_24 ;
if ( ! V_15 . V_23 ) {
F_6 ( V_21 , L_3 , V_22 ,
V_2 -> V_5 , V_9 ) ;
return - V_4 ;
}
V_15 . V_25 = F_3 ( V_2 -> V_5 ) ;
V_15 . V_5 = V_2 -> V_5 ;
if ( V_15 . V_25 == V_15 . V_23 && V_2 -> V_26 == V_15 . V_23 )
return V_13 ;
F_9 (i, policy->cpus) {
V_15 . V_5 = V_11 ;
F_10 ( & V_15 , V_27 ) ;
}
V_17 = V_15 . V_23 * 1000 ;
if ( V_28 ) {
V_16 = F_11 ( V_21 , & V_17 ) ;
if ( F_12 ( V_16 ) ) {
F_6 ( V_21 , L_4 ,
V_22 , V_15 . V_23 ) ;
return - V_4 ;
}
V_18 = F_13 ( V_16 ) ;
V_20 = V_18 * V_29 / 100 ;
V_19 = F_14 ( V_28 ) ;
}
F_8 ( V_21 , L_5 ,
V_15 . V_25 / 1000 , V_19 ? V_19 / 1000 : - 1 ,
V_15 . V_23 / 1000 , V_18 ? V_18 / 1000 : - 1 ) ;
if ( V_28 && ( V_15 . V_23 > V_15 . V_25 ) ) {
V_12 = F_15 ( V_28 , V_18 - V_20 , V_18 + V_20 ) ;
if ( V_12 < 0 ) {
F_16 ( V_21 , L_6 ,
V_22 ) ;
V_15 . V_23 = V_15 . V_25 ;
goto V_30;
}
}
V_13 = F_17 ( V_8 , V_15 . V_23 * 1000 ) ;
if ( V_28 && ( V_15 . V_23 < V_15 . V_25 ) ) {
V_12 = F_15 ( V_28 , V_18 - V_20 , V_18 + V_20 ) ;
if ( V_12 < 0 ) {
F_16 ( V_21 , L_7 ,
V_22 ) ;
V_13 = F_17 ( V_8 , V_15 . V_25 * 1000 ) ;
V_15 . V_23 = V_15 . V_25 ;
goto V_30;
}
}
V_15 . V_23 = F_3 ( V_2 -> V_5 ) ;
#ifdef F_18
F_9 (i, policy->cpus) {
struct V_31 * V_32 = & F_19 ( V_33 , V_11 ) ;
if ( ! V_32 -> V_17 ) {
V_32 -> V_34 = F_19 ( V_35 , V_11 ) . V_36 ;
V_32 -> V_17 = V_15 . V_25 ;
}
F_19 ( V_35 , V_11 ) . V_36 =
F_20 ( V_32 -> V_34 , V_32 -> V_17 , V_15 . V_23 ) ;
}
if ( ! V_37 . V_17 ) {
V_37 . V_34 = V_36 ;
V_37 . V_17 = V_15 . V_25 ;
}
V_36 = F_20 ( V_37 . V_34 , V_37 . V_17 ,
V_15 . V_23 ) ;
#endif
V_30:
F_9 (i, policy->cpus) {
V_15 . V_5 = V_11 ;
F_10 ( & V_15 , V_38 ) ;
}
return V_13 ;
}
static inline void F_21 ( void )
{
if ( F_22 ( & V_39 ) )
F_23 ( V_21 , & V_3 ) ;
}
static int T_1 F_24 ( struct V_1 * V_2 )
{
int V_40 = 0 ;
V_8 = F_25 ( NULL , V_41 ) ;
if ( F_12 ( V_8 ) )
return F_26 ( V_8 ) ;
if ( V_2 -> V_5 >= V_7 ) {
V_40 = - V_4 ;
goto V_42;
}
V_2 -> V_26 = V_2 -> V_43 = V_2 -> V_44 = F_3 ( V_2 -> V_5 ) ;
if ( F_27 ( & V_39 ) == 1 )
V_40 = F_28 ( V_21 , & V_3 ) ;
if ( V_40 ) {
F_6 ( V_21 , L_8 ,
V_22 , V_2 -> V_5 , V_40 ) ;
goto V_42;
}
V_40 = F_29 ( V_2 , V_3 ) ;
if ( V_40 )
goto V_45;
F_30 ( V_3 , V_2 -> V_5 ) ;
V_2 -> V_43 = V_2 -> V_46 . V_47 ;
V_2 -> V_44 = V_2 -> V_46 . V_48 ;
V_2 -> V_26 = F_3 ( V_2 -> V_5 ) ;
if ( F_31 () ) {
V_2 -> V_49 = V_50 ;
F_32 ( V_2 -> V_51 ) ;
}
V_2 -> V_46 . V_52 = 300 * 1000 ;
return 0 ;
V_45:
F_21 () ;
V_42:
F_33 ( V_8 ) ;
return V_40 ;
}
static int F_34 ( struct V_1 * V_2 )
{
F_21 () ;
F_33 ( V_8 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
if ( F_36 () )
V_41 = L_9 ;
else if ( F_37 () )
V_41 = L_10 ;
else if ( F_38 () )
V_41 = L_11 ;
if ( ! V_41 ) {
F_39 ( L_12 , V_22 ) ;
return - V_4 ;
}
V_21 = F_40 ( L_13 ) ;
if ( ! V_21 ) {
F_41 ( L_14 , V_22 ) ;
return - V_4 ;
}
V_28 = F_42 ( V_21 , L_15 ) ;
if ( F_12 ( V_28 ) ) {
F_41 ( L_16 , V_22 ) ;
V_28 = NULL ;
} else {
if ( F_14 ( V_28 ) < 0 ) {
F_43 ( L_17 ,
V_22 ) ;
F_44 ( V_28 ) ;
V_28 = NULL ;
}
}
return F_45 ( & V_53 ) ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_53 ) ;
}
