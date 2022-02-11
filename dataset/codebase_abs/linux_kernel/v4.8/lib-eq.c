int
F_1 ( unsigned int V_1 , T_1 V_2 ,
T_2 * V_3 )
{
T_3 * V_4 ;
F_2 ( V_5 . V_6 > 0 ) ;
if ( V_1 )
V_1 = F_3 ( V_1 ) ;
if ( V_2 != V_7 && V_1 )
F_4 ( L_1 , V_1 ) ;
if ( ! V_1 && V_2 == V_7 )
return - V_8 ;
V_4 = F_5 () ;
if ( ! V_4 )
return - V_9 ;
if ( V_1 ) {
F_6 ( V_4 -> V_10 , V_1 * sizeof( V_11 ) ) ;
if ( ! V_4 -> V_10 )
goto V_12;
}
V_4 -> V_13 = 1 ;
V_4 -> V_14 = 1 ;
V_4 -> V_15 = V_1 ;
V_4 -> V_16 = V_2 ;
V_4 -> V_17 = F_7 ( F_8 () ,
sizeof( * V_4 -> V_17 [ 0 ] ) ) ;
if ( ! V_4 -> V_17 )
goto V_12;
F_9 ( V_18 ) ;
F_10 () ;
F_11 ( & V_5 . V_19 , & V_4 -> V_20 ) ;
F_12 ( & V_4 -> V_21 , & V_5 . V_19 . V_22 ) ;
F_13 () ;
F_14 ( V_18 ) ;
F_15 ( V_3 , V_4 ) ;
return 0 ;
V_12:
if ( V_4 -> V_10 )
F_16 ( V_4 -> V_10 , V_1 * sizeof( V_11 ) ) ;
if ( V_4 -> V_17 )
F_17 ( V_4 -> V_17 ) ;
F_18 ( V_4 ) ;
return - V_9 ;
}
int
F_19 ( T_2 V_23 )
{
struct V_24 * V_4 ;
V_11 * V_25 = NULL ;
int * * V_26 = NULL ;
int * V_27 ;
int V_28 = 0 ;
int V_29 = 0 ;
int V_30 ;
F_2 ( V_5 . V_6 > 0 ) ;
F_9 ( V_18 ) ;
F_10 () ;
V_4 = F_20 ( & V_23 ) ;
if ( ! V_4 ) {
V_28 = - V_31 ;
goto V_32;
}
F_21 (ref, i, eq->eq_refs) {
F_2 ( * V_27 >= 0 ) ;
if ( ! * V_27 )
continue;
F_22 ( V_33 , L_2 ,
V_30 , * V_27 ) ;
V_28 = - V_34 ;
goto V_32;
}
V_25 = V_4 -> V_10 ;
V_29 = V_4 -> V_15 ;
V_26 = V_4 -> V_17 ;
F_23 ( & V_4 -> V_20 ) ;
F_24 ( & V_4 -> V_21 ) ;
F_18 ( V_4 ) ;
V_32:
F_13 () ;
F_14 ( V_18 ) ;
if ( V_25 )
F_16 ( V_25 , V_29 * sizeof( V_11 ) ) ;
if ( V_26 )
F_17 ( V_26 ) ;
return V_28 ;
}
void
F_25 ( T_3 * V_4 , V_11 * V_35 )
{
int V_36 ;
if ( ! V_4 -> V_15 ) {
F_2 ( V_4 -> V_16 != V_7 ) ;
V_4 -> V_16 ( V_35 ) ;
return;
}
F_10 () ;
V_35 -> V_37 = V_4 -> V_14 ++ ;
F_2 ( V_4 -> V_15 == F_26 ( V_4 -> V_15 ) ) ;
V_36 = V_35 -> V_37 & ( V_4 -> V_15 - 1 ) ;
V_4 -> V_10 [ V_36 ] = * V_35 ;
if ( V_4 -> V_16 != V_7 )
V_4 -> V_16 ( V_35 ) ;
if ( F_27 ( & V_5 . V_38 ) )
F_28 ( & V_5 . V_38 ) ;
F_13 () ;
}
static int
F_29 ( T_3 * V_4 , V_11 * V_35 )
{
int V_39 = V_4 -> V_13 & ( V_4 -> V_15 - 1 ) ;
V_11 * V_40 = & V_4 -> V_10 [ V_39 ] ;
int V_28 ;
if ( F_30 ( V_4 -> V_13 , V_40 -> V_37 ) )
return 0 ;
* V_35 = * V_40 ;
F_22 ( V_41 , L_3 ,
V_40 , V_4 -> V_13 , V_4 -> V_15 ) ;
if ( V_4 -> V_13 == V_40 -> V_37 ) {
V_28 = 1 ;
} else {
F_22 ( V_33 , L_4 ,
V_4 -> V_13 , V_40 -> V_37 ) ;
V_28 = - V_42 ;
}
V_4 -> V_13 = V_40 -> V_37 + 1 ;
return V_28 ;
}
static int
F_31 ( int * V_43 )
__must_hold( &the_lnet.ln_eq_wait_lock
int
F_32 ( T_2 * V_44 , int V_45 , int V_43 ,
V_11 * V_46 , int * V_47 )
{
int V_48 = 1 ;
int V_28 ;
int V_30 ;
F_2 ( V_5 . V_6 > 0 ) ;
if ( V_45 < 1 )
return - V_31 ;
F_10 () ;
for (; ; ) {
for ( V_30 = 0 ; V_30 < V_45 ; V_30 ++ ) {
T_3 * V_4 = F_20 ( & V_44 [ V_30 ] ) ;
if ( ! V_4 ) {
F_13 () ;
return - V_31 ;
}
V_28 = F_29 ( V_4 , V_46 ) ;
if ( V_28 ) {
F_13 () ;
* V_47 = V_30 ;
return V_28 ;
}
}
if ( ! V_48 )
break;
V_48 = F_31 ( & V_43 ) ;
if ( V_48 < 0 )
break;
}
F_13 () ;
return 0 ;
}
