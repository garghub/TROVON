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
int V_12 = 0 ;
struct V_13 V_14 ;
if ( ! V_3 ) {
F_6 ( V_15 , L_1 , V_16 ,
V_2 -> V_5 ) ;
return - V_4 ;
}
V_12 = F_7 ( V_2 , V_3 , V_9 ,
V_10 , & V_11 ) ;
if ( V_12 ) {
F_8 ( V_15 , L_2 ,
V_16 , V_2 -> V_5 , V_9 , V_12 ) ;
return V_12 ;
}
V_14 . V_17 = V_3 [ V_11 ] . V_18 ;
if ( ! V_14 . V_17 ) {
F_6 ( V_15 , L_3 , V_16 ,
V_2 -> V_5 , V_9 ) ;
return - V_4 ;
}
V_14 . V_19 = F_3 ( V_2 -> V_5 ) ;
V_14 . V_5 = V_2 -> V_5 ;
if ( V_14 . V_19 == V_14 . V_17 && V_2 -> V_20 == V_14 . V_17 )
return V_12 ;
F_9 (i, policy->cpus) {
V_14 . V_5 = V_11 ;
F_10 ( & V_14 , V_21 ) ;
}
#ifdef F_11
F_12 ( L_4 , V_14 . V_19 , V_14 . V_17 ) ;
#endif
V_12 = F_13 ( V_8 , V_14 . V_17 * 1000 ) ;
V_14 . V_17 = F_3 ( V_2 -> V_5 ) ;
#ifdef F_14
F_9 (i, policy->cpus) {
struct V_22 * V_23 = & F_15 ( V_24 , V_11 ) ;
if ( ! V_23 -> V_25 ) {
V_23 -> V_26 = F_15 ( V_27 , V_11 ) . V_28 ;
V_23 -> V_25 = V_14 . V_19 ;
}
F_15 ( V_27 , V_11 ) . V_28 =
F_16 ( V_23 -> V_26 , V_23 -> V_25 , V_14 . V_17 ) ;
}
if ( ! V_29 . V_25 ) {
V_29 . V_26 = V_28 ;
V_29 . V_25 = V_14 . V_19 ;
}
V_28 = F_16 ( V_29 . V_26 , V_29 . V_25 ,
V_14 . V_17 ) ;
#endif
F_9 (i, policy->cpus) {
V_14 . V_5 = V_11 ;
F_10 ( & V_14 , V_30 ) ;
}
return V_12 ;
}
static inline void F_17 ( void )
{
if ( F_18 ( & V_31 ) )
F_19 ( V_15 , & V_3 ) ;
}
static int T_1 F_20 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
V_8 = F_21 ( NULL , V_33 ) ;
if ( F_22 ( V_8 ) )
return F_23 ( V_8 ) ;
if ( V_2 -> V_5 >= V_7 ) {
V_32 = - V_4 ;
goto V_34;
}
V_2 -> V_20 = V_2 -> V_35 = V_2 -> V_36 = F_3 ( V_2 -> V_5 ) ;
if ( F_24 ( & V_31 ) == 1 )
V_32 = F_25 ( V_15 , & V_3 ) ;
if ( V_32 ) {
F_6 ( V_15 , L_5 ,
V_16 , V_2 -> V_5 , V_32 ) ;
goto V_34;
}
V_32 = F_26 ( V_2 , V_3 ) ;
if ( V_32 )
goto V_37;
F_27 ( V_3 , V_2 -> V_5 ) ;
V_2 -> V_35 = V_2 -> V_38 . V_39 ;
V_2 -> V_36 = V_2 -> V_38 . V_40 ;
V_2 -> V_20 = F_3 ( V_2 -> V_5 ) ;
if ( F_28 () ) {
V_2 -> V_41 = V_42 ;
F_29 ( V_2 -> V_43 ) ;
}
V_2 -> V_38 . V_44 = 300 * 1000 ;
return 0 ;
V_37:
F_17 () ;
V_34:
F_30 ( V_8 ) ;
return V_32 ;
}
static int F_31 ( struct V_1 * V_2 )
{
F_17 () ;
F_30 ( V_8 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
if ( F_33 () )
V_33 = L_6 ;
else if ( F_34 () )
V_33 = L_7 ;
else if ( F_35 () )
V_33 = L_8 ;
if ( ! V_33 ) {
F_36 ( L_9 , V_16 ) ;
return - V_4 ;
}
V_15 = F_37 ( L_10 ) ;
if ( ! V_15 ) {
F_38 ( L_11 , V_16 ) ;
return - V_4 ;
}
return F_39 ( & V_45 ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_45 ) ;
}
