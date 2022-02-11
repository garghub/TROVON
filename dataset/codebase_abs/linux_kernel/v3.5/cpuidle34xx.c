static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
struct V_10 * V_11 = & V_12 [ V_9 ] ;
T_1 V_13 = V_11 -> V_13 , V_14 = V_11 -> V_14 ;
F_6 () ;
F_7 ( V_15 , V_13 ) ;
F_7 ( V_16 , V_14 ) ;
if ( F_8 () || F_9 () )
goto V_17;
if ( V_9 == 0 ) {
F_10 ( V_15 , F_3 ) ;
F_10 ( V_16 , F_3 ) ;
}
if ( V_13 == V_18 )
F_11 () ;
F_12 () ;
if ( F_13 ( V_15 ) == V_18 )
F_14 () ;
if ( V_9 == 0 ) {
F_10 ( V_15 , F_1 ) ;
F_10 ( V_16 , F_1 ) ;
}
V_17:
F_15 () ;
return V_9 ;
}
static inline int F_16 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
return F_17 ( V_6 , V_8 , V_9 , F_5 ) ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_7 * V_8 , int V_9 )
{
struct V_10 * V_11 = & V_12 [ V_9 ] ;
T_1 V_19 = V_20 ;
T_1 V_21 = V_20 ;
int V_22 ;
int V_23 = - 1 ;
if ( V_24 ) {
V_19 = V_18 ;
if ( ! F_19 ( V_25 ) )
V_21 = V_18 ;
}
if ( ( V_11 -> V_13 >= V_19 ) &&
( V_11 -> V_14 >= V_21 ) )
return V_9 ;
for ( V_22 = V_9 - 1 ; V_22 >= 0 ; V_22 -- ) {
V_11 = & V_12 [ V_22 ] ;
if ( ( V_11 -> V_13 >= V_19 ) &&
( V_11 -> V_14 >= V_21 ) ) {
V_23 = V_22 ;
break;
}
}
return V_23 ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
int V_26 ;
T_1 V_27 , V_28 = 0 , V_29 = 0 , V_30 ;
struct V_10 * V_11 ;
int V_31 ;
V_30 = F_21 ( V_32 ) ;
if ( V_30 == V_33 ) {
V_26 = V_8 -> V_34 ;
goto V_35;
}
V_11 = & V_12 [ V_9 ] ;
V_27 = V_11 -> V_14 ;
V_28 = V_29 = F_22 ( V_36 ) ;
if ( ( V_28 == V_18 ) &&
( V_27 > V_20 ) )
V_28 = V_20 ;
if ( V_28 != V_29 )
F_7 ( V_36 , V_28 ) ;
V_26 = F_18 ( V_6 , V_8 , V_9 ) ;
V_35:
V_31 = F_16 ( V_6 , V_8 , V_26 ) ;
if ( V_28 != V_29 )
F_7 ( V_36 , V_29 ) ;
return V_31 ;
}
int T_2 F_23 ( void )
{
struct V_5 * V_6 ;
V_15 = F_24 ( L_1 ) ;
V_16 = F_24 ( L_2 ) ;
V_36 = F_24 ( L_3 ) ;
V_32 = F_24 ( L_4 ) ;
if ( ! V_15 || ! V_16 || ! V_36 || ! V_32 )
return - V_37 ;
F_25 ( & V_38 ) ;
V_6 = & F_26 ( V_39 , F_27 () ) ;
V_6 -> V_40 = 0 ;
if ( F_28 ( V_6 ) ) {
F_29 ( V_41 L_5 ,
V_42 ) ;
return - V_43 ;
}
return 0 ;
}
int T_2 F_23 ( void )
{
return 0 ;
}
