int
F_1 ( unsigned int V_1 , T_1 V_2 ,
T_2 * V_3 )
{
T_3 * V_4 ;
F_2 ( V_5 . V_6 ) ;
F_2 ( V_5 . V_7 > 0 ) ;
V_1 = F_3 ( V_1 ) ;
if ( V_2 != V_8 && V_1 != 0 )
F_4 ( L_1 , V_1 ) ;
if ( V_1 == 0 && V_2 == V_8 )
return - V_9 ;
V_4 = F_5 () ;
if ( V_4 == NULL )
return - V_10 ;
if ( V_1 != 0 ) {
F_6 ( V_4 -> V_11 , V_1 * sizeof( V_12 ) ) ;
if ( V_4 -> V_11 == NULL )
goto V_13;
}
V_4 -> V_14 = 1 ;
V_4 -> V_15 = 1 ;
V_4 -> V_16 = V_1 ;
V_4 -> V_17 = V_2 ;
V_4 -> V_18 = F_7 ( F_8 () ,
sizeof( * V_4 -> V_18 [ 0 ] ) ) ;
if ( V_4 -> V_18 == NULL )
goto V_13;
F_9 ( V_19 ) ;
F_10 () ;
F_11 ( & V_5 . V_20 , & V_4 -> V_21 ) ;
F_12 ( & V_4 -> V_22 , & V_5 . V_20 . V_23 ) ;
F_13 () ;
F_14 ( V_19 ) ;
F_15 ( V_3 , V_4 ) ;
return 0 ;
V_13:
if ( V_4 -> V_11 != NULL )
F_16 ( V_4 -> V_11 , V_1 * sizeof( V_12 ) ) ;
if ( V_4 -> V_18 != NULL )
F_17 ( V_4 -> V_18 ) ;
F_18 ( V_4 ) ;
return - V_10 ;
}
int
F_19 ( T_2 V_24 )
{
struct V_25 * V_4 ;
V_12 * V_26 = NULL ;
int * * V_27 = NULL ;
int * V_28 ;
int V_29 = 0 ;
int V_30 = 0 ;
int V_31 ;
F_2 ( V_5 . V_6 ) ;
F_2 ( V_5 . V_7 > 0 ) ;
F_9 ( V_19 ) ;
F_10 () ;
V_4 = F_20 ( & V_24 ) ;
if ( V_4 == NULL ) {
V_29 = - V_32 ;
goto V_33;
}
F_21 (ref, i, eq->eq_refs) {
F_2 ( * V_28 >= 0 ) ;
if ( * V_28 == 0 )
continue;
F_22 ( V_34 , L_2 ,
V_31 , * V_28 ) ;
V_29 = - V_35 ;
goto V_33;
}
V_26 = V_4 -> V_11 ;
V_30 = V_4 -> V_16 ;
V_27 = V_4 -> V_18 ;
F_23 ( & V_4 -> V_21 ) ;
F_24 ( & V_4 -> V_22 ) ;
F_25 ( V_4 ) ;
V_33:
F_13 () ;
F_14 ( V_19 ) ;
if ( V_26 != NULL )
F_16 ( V_26 , V_30 * sizeof( V_12 ) ) ;
if ( V_27 != NULL )
F_17 ( V_27 ) ;
return V_29 ;
}
void
F_26 ( T_3 * V_4 , V_12 * V_36 )
{
int V_37 ;
if ( V_4 -> V_16 == 0 ) {
F_2 ( V_4 -> V_17 != V_8 ) ;
V_4 -> V_17 ( V_36 ) ;
return;
}
F_10 () ;
V_36 -> V_38 = V_4 -> V_15 ++ ;
F_2 ( V_4 -> V_16 == F_27 ( V_4 -> V_16 ) ) ;
V_37 = V_36 -> V_38 & ( V_4 -> V_16 - 1 ) ;
V_4 -> V_11 [ V_37 ] = * V_36 ;
if ( V_4 -> V_17 != V_8 )
V_4 -> V_17 ( V_36 ) ;
if ( F_28 ( & V_5 . V_39 ) )
F_29 ( & V_5 . V_39 ) ;
F_13 () ;
}
static int
F_30 ( T_3 * V_4 , V_12 * V_36 )
{
int V_40 = V_4 -> V_14 & ( V_4 -> V_16 - 1 ) ;
V_12 * V_41 = & V_4 -> V_11 [ V_40 ] ;
int V_29 ;
if ( F_31 ( V_4 -> V_14 , V_41 -> V_38 ) )
return 0 ;
* V_36 = * V_41 ;
F_22 ( V_42 , L_3 ,
V_41 , V_4 -> V_14 , V_4 -> V_16 ) ;
if ( V_4 -> V_14 == V_41 -> V_38 ) {
V_29 = 1 ;
} else {
F_22 ( V_34 , L_4 ,
V_4 -> V_14 , V_41 -> V_38 ) ;
V_29 = - V_43 ;
}
V_4 -> V_14 = V_41 -> V_38 + 1 ;
return V_29 ;
}
int
F_32 ( T_2 V_44 , V_12 * V_45 )
{
int V_46 ;
return F_33 ( & V_44 , 1 , 0 ,
V_45 , & V_46 ) ;
}
int
F_34 ( T_2 V_44 , V_12 * V_45 )
{
int V_46 ;
return F_33 ( & V_44 , 1 , V_47 ,
V_45 , & V_46 ) ;
}
static int
F_35 ( int * V_48 )
__must_hold( &the_lnet.ln_eq_wait_lock
int
F_33 ( T_2 * V_49 , int V_50 , int V_48 ,
V_12 * V_45 , int * V_46 )
{
int V_51 = 1 ;
int V_29 ;
int V_31 ;
F_2 ( V_5 . V_6 ) ;
F_2 ( V_5 . V_7 > 0 ) ;
if ( V_50 < 1 )
return - V_32 ;
F_10 () ;
for (; ; ) {
for ( V_31 = 0 ; V_31 < V_50 ; V_31 ++ ) {
T_3 * V_4 = F_20 ( & V_49 [ V_31 ] ) ;
if ( V_4 == NULL ) {
F_13 () ;
return - V_32 ;
}
V_29 = F_30 ( V_4 , V_45 ) ;
if ( V_29 != 0 ) {
F_13 () ;
* V_46 = V_31 ;
return V_29 ;
}
}
if ( V_51 == 0 )
break;
V_51 = F_35 ( & V_48 ) ;
if ( V_51 < 0 )
break;
}
F_13 () ;
return 0 ;
}
