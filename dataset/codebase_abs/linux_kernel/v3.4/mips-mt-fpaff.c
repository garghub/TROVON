static inline struct V_1 * F_1 ( T_1 V_2 )
{
return V_2 ? F_2 ( V_2 ) : V_3 ;
}
static bool F_3 ( struct V_1 * V_4 )
{
const struct V_5 * V_5 = F_4 () , * V_6 ;
bool V_7 ;
F_5 () ;
V_6 = F_6 ( V_4 ) ;
V_7 = ( V_5 -> V_8 == V_6 -> V_8 ||
V_5 -> V_8 == V_6 -> V_9 ) ;
F_7 () ;
return V_7 ;
}
T_2 long F_8 ( T_1 V_2 , unsigned int V_10 ,
unsigned long T_3 * V_11 )
{
T_4 V_12 , V_13 , V_14 ;
struct V_15 * V_16 ;
struct V_1 * V_4 ;
int V_17 ;
if ( V_10 < sizeof( V_13 ) )
return - V_18 ;
if ( F_9 ( & V_13 , V_11 , sizeof( V_13 ) ) )
return - V_19 ;
F_10 () ;
F_5 () ;
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 ) {
F_7 () ;
F_11 () ;
return - V_20 ;
}
F_12 ( V_4 ) ;
F_7 () ;
if ( ! F_13 ( & V_12 , V_21 ) ) {
V_17 = - V_22 ;
goto V_23;
}
if ( ! F_13 ( & V_13 , V_21 ) ) {
V_17 = - V_22 ;
goto V_24;
}
if ( ! F_13 ( & V_14 , V_21 ) ) {
V_17 = - V_22 ;
goto V_25;
}
V_17 = - V_26 ;
if ( ! F_3 ( V_4 ) && ! F_14 ( V_27 ) )
goto V_28;
V_17 = F_15 ( V_4 ) ;
if ( V_17 )
goto V_28;
F_16 ( & V_4 -> V_29 . V_30 , V_13 ) ;
V_31:
V_16 = F_17 ( V_4 ) ;
if ( F_18 ( V_16 , V_32 ) &&
F_19 ( * V_13 , V_33 ) ) {
F_20 ( * V_14 , * V_13 , V_33 ) ;
V_17 = F_21 ( V_4 , V_14 ) ;
} else {
F_16 ( V_14 , V_13 ) ;
F_22 ( V_16 , V_32 ) ;
V_17 = F_21 ( V_4 , V_13 ) ;
}
if ( ! V_17 ) {
F_23 ( V_4 , V_12 ) ;
if ( ! F_24 ( V_14 , V_12 ) ) {
F_16 ( V_13 , V_12 ) ;
goto V_31;
}
}
V_28:
F_25 ( V_14 ) ;
V_25:
F_25 ( V_13 ) ;
V_24:
F_25 ( V_12 ) ;
V_23:
F_26 ( V_4 ) ;
F_11 () ;
return V_17 ;
}
T_2 long F_27 ( T_1 V_2 , unsigned int V_10 ,
unsigned long T_3 * V_11 )
{
unsigned int V_34 ;
T_5 V_35 ;
int V_17 ;
struct V_1 * V_4 ;
V_34 = sizeof( V_35 ) ;
if ( V_10 < V_34 )
return - V_18 ;
F_10 () ;
F_28 ( & V_36 ) ;
V_17 = - V_20 ;
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 )
goto V_28;
V_17 = F_29 ( V_4 ) ;
if ( V_17 )
goto V_28;
F_30 ( & V_35 , & V_4 -> V_29 . V_30 , V_37 ) ;
V_28:
F_31 ( & V_36 ) ;
F_11 () ;
if ( V_17 )
return V_17 ;
if ( F_32 ( V_11 , & V_35 , V_34 ) )
return - V_19 ;
return V_34 ;
}
static int T_6 F_33 ( char * V_38 )
{
F_34 ( & V_38 , & V_39 ) ;
return 1 ;
}
static T_6 int F_35 ( void )
{
if ( V_39 >= 0 ) {
V_40 = V_39 ;
} else {
V_40 =
( V_41 * ( V_42 / ( 500000 / V_43 ) ) ) / V_43 ;
}
F_36 ( V_44 L_1 ,
V_40 ) ;
return 0 ;
}
