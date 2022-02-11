static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = & V_8 [ V_5 ] ;
if ( F_2 () || F_3 () )
goto V_9;
if ( V_7 -> V_10 & V_11 ) {
F_4 ( V_12 -> V_13 [ 0 ] ) ;
} else {
F_5 ( V_12 , V_7 -> V_14 ) ;
F_5 ( V_15 , V_7 -> V_16 ) ;
}
if ( V_7 -> V_14 == V_17 )
F_6 () ;
F_7 () ;
if ( V_7 -> V_14 == V_17 &&
F_8 ( V_12 ) == V_17 )
F_9 () ;
if ( V_7 -> V_10 & V_11 )
F_10 ( V_12 -> V_13 [ 0 ] ) ;
V_9:
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = & V_8 [ V_5 ] ;
T_1 V_18 = V_19 ;
T_1 V_20 = V_19 ;
int V_21 ;
int V_22 = 0 ;
if ( V_23 ) {
V_18 = V_17 ;
if ( ! F_12 ( V_24 ) )
V_20 = V_17 ;
}
if ( ( V_7 -> V_14 >= V_18 ) &&
( V_7 -> V_16 >= V_20 ) )
return V_5 ;
for ( V_21 = V_5 - 1 ; V_21 >= 0 ; V_21 -- ) {
V_7 = & V_8 [ V_21 ] ;
if ( ( V_7 -> V_14 >= V_18 ) &&
( V_7 -> V_16 >= V_20 ) ) {
V_22 = V_21 ;
break;
}
}
return V_22 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_25 , V_26 ;
T_2 V_27 , V_28 ;
struct V_6 * V_7 ;
if ( F_14 ( V_29 ) == V_30 )
V_25 = V_4 -> V_31 ;
else
V_25 = F_11 ( V_2 , V_4 , V_5 ) ;
V_7 = & V_8 [ V_25 ] ;
V_27 = F_15 ( V_32 ) ;
V_28 = V_27 ;
if ( V_27 < V_7 -> V_33 ) {
V_27 = V_7 -> V_33 ;
F_5 ( V_32 , V_27 ) ;
}
V_26 = F_1 ( V_2 , V_4 , V_25 ) ;
if ( V_27 != V_28 )
F_5 ( V_32 , V_28 ) ;
return V_26 ;
}
int T_3 F_16 ( void )
{
V_12 = F_17 ( L_1 ) ;
V_15 = F_17 ( L_2 ) ;
V_32 = F_17 ( L_3 ) ;
V_29 = F_17 ( L_4 ) ;
if ( ! V_12 || ! V_15 || ! V_32 || ! V_29 )
return - V_34 ;
if ( F_18 () )
return F_19 ( & V_35 , NULL ) ;
else
return F_19 ( & V_36 , NULL ) ;
}
