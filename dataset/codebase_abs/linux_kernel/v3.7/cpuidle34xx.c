static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = & V_8 [ V_5 ] ;
T_1 V_9 = V_7 -> V_9 , V_10 = V_7 -> V_10 ;
F_2 () ;
F_3 ( V_11 , V_9 ) ;
F_3 ( V_12 , V_10 ) ;
if ( F_4 () || F_5 () )
goto V_13;
if ( V_5 == 0 ) {
F_6 ( V_11 -> V_14 [ 0 ] ) ;
F_6 ( V_12 -> V_14 [ 0 ] ) ;
}
if ( V_9 == V_15 )
F_7 () ;
F_8 () ;
if ( F_9 ( V_11 ) == V_15 )
F_10 () ;
if ( V_5 == 0 ) {
F_11 ( V_11 -> V_14 [ 0 ] ) ;
F_11 ( V_12 -> V_14 [ 0 ] ) ;
}
V_13:
F_12 () ;
return V_5 ;
}
static inline int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
return F_14 ( V_2 , V_4 , V_5 , F_1 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = & V_8 [ V_5 ] ;
T_1 V_16 = V_17 ;
T_1 V_18 = V_17 ;
int V_19 ;
int V_20 = 0 ;
if ( V_21 ) {
V_16 = V_15 ;
if ( ! F_16 ( V_22 ) )
V_18 = V_15 ;
}
if ( ( V_7 -> V_9 >= V_16 ) &&
( V_7 -> V_10 >= V_18 ) )
return V_5 ;
for ( V_19 = V_5 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_7 = & V_8 [ V_19 ] ;
if ( ( V_7 -> V_9 >= V_16 ) &&
( V_7 -> V_10 >= V_18 ) ) {
V_20 = V_19 ;
break;
}
}
return V_20 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_23 ;
T_1 V_24 , V_25 = 0 , V_26 = 0 ;
struct V_6 * V_7 ;
int V_27 ;
if ( F_18 ( V_28 ) == V_29 )
V_23 = V_4 -> V_30 ;
else
V_23 = F_15 ( V_2 , V_4 , V_5 ) ;
V_7 = & V_8 [ V_23 ] ;
V_24 = V_7 -> V_10 ;
V_25 = V_26 = F_19 ( V_31 ) ;
if ( V_23 == 0 ) {
if ( V_25 < V_24 )
V_25 = V_24 ;
} else {
if ( ( V_25 == V_15 ) &&
( V_24 > V_17 ) )
V_25 = V_17 ;
}
if ( V_25 != V_26 )
F_3 ( V_31 , V_25 ) ;
V_27 = F_13 ( V_2 , V_4 , V_23 ) ;
if ( V_25 != V_26 )
F_3 ( V_31 , V_26 ) ;
return V_27 ;
}
int T_2 F_20 ( void )
{
struct V_1 * V_2 ;
V_11 = F_21 ( L_1 ) ;
V_12 = F_21 ( L_2 ) ;
V_31 = F_21 ( L_3 ) ;
V_28 = F_21 ( L_4 ) ;
if ( ! V_11 || ! V_12 || ! V_31 || ! V_28 )
return - V_32 ;
F_22 ( & V_33 ) ;
V_2 = & F_23 ( V_34 , F_24 () ) ;
V_2 -> V_35 = 0 ;
if ( F_25 ( V_2 ) ) {
F_26 ( V_36 L_5 ,
V_37 ) ;
return - V_38 ;
}
return 0 ;
}
