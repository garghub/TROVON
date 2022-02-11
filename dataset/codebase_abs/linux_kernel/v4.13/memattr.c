int T_1 F_1 ( void )
{
T_2 * V_1 ;
if ( V_2 . V_3 == V_4 )
return 0 ;
V_1 = F_2 ( V_2 . V_3 , sizeof( * V_1 ) ) ;
if ( ! V_1 ) {
F_3 ( L_1 ,
V_2 . V_3 ) ;
return - V_5 ;
}
if ( V_1 -> V_6 > 1 ) {
F_4 ( L_2 ,
V_1 -> V_6 ) ;
goto V_7;
}
V_8 = sizeof( * V_1 ) + V_1 -> V_9 * V_1 -> V_10 ;
F_5 ( V_2 . V_3 , V_8 ) ;
F_6 ( V_11 , & V_2 . V_12 ) ;
V_7:
F_7 ( V_1 , sizeof( * V_1 ) ) ;
return 0 ;
}
static bool F_8 ( const T_3 * V_13 , T_3 * V_14 )
{
T_4 V_15 = V_13 -> V_16 ;
T_4 V_17 = V_13 -> V_18 << V_19 ;
T_3 * V_20 ;
* V_14 = * V_13 ;
if ( V_13 -> type != V_21 &&
V_13 -> type != V_22 ) {
F_4 ( L_3 ) ;
return false ;
}
if ( ! ( V_13 -> V_23 & ( V_24 | V_25 ) ) ) {
F_4 ( L_4 ) ;
return false ;
}
if ( V_26 > V_27 &&
( ! F_9 ( V_13 -> V_16 ) ||
! F_9 ( V_13 -> V_18 << V_19 ) ) ) {
F_4 ( L_5 ) ;
return false ;
}
F_10 (md) {
T_4 V_28 = V_20 -> V_16 ;
T_4 V_29 = V_20 -> V_18 << V_19 ;
if ( ! ( V_20 -> V_23 & V_30 ) )
continue;
if ( V_20 -> V_31 == 0 ) {
break;
}
if ( V_28 > V_15 || ( V_15 - V_28 ) >= V_29 )
continue;
if ( V_28 + V_29 < V_15 + V_17 ) {
F_4 ( L_6 ) ;
return false ;
}
if ( V_20 -> type != V_13 -> type ) {
F_4 ( L_7 ) ;
return false ;
}
V_14 -> V_31 = V_15 + ( V_20 -> V_31 - V_28 ) ;
return true ;
}
F_4 ( L_8 ) ;
return false ;
}
int T_1 F_11 ( struct V_32 * V_33 ,
T_5 V_34 )
{
T_2 * V_1 ;
int V_35 , V_36 ;
if ( V_8 <= sizeof( * V_1 ) )
return 0 ;
if ( F_12 ( ! F_13 ( V_37 ) ) )
return 0 ;
V_1 = F_14 ( V_2 . V_3 , V_8 , V_38 ) ;
if ( ! V_1 ) {
F_3 ( L_1 ,
V_2 . V_3 ) ;
return - V_5 ;
}
if ( F_13 ( V_39 ) )
F_15 ( L_9 ) ;
for ( V_35 = V_36 = 0 ; V_36 == 0 && V_35 < V_1 -> V_9 ; V_35 ++ ) {
T_3 V_20 ;
unsigned long V_40 ;
bool V_41 ;
char V_42 [ 64 ] ;
V_41 = F_8 ( ( void * ) V_1 -> V_43 + V_35 * V_1 -> V_10 ,
& V_20 ) ;
V_40 = V_20 . V_18 << V_19 ;
if ( F_13 ( V_39 ) || ! V_41 )
F_15 ( L_10 ,
V_41 ? L_11 : L_12 , V_20 . V_16 ,
V_20 . V_16 + V_40 - 1 ,
F_16 ( V_42 , sizeof( V_42 ) , & V_20 ) ) ;
if ( V_41 ) {
V_36 = V_34 ( V_33 , & V_20 ) ;
if ( V_36 )
F_3 ( L_13 ) ;
}
}
F_17 ( V_1 ) ;
return V_36 ;
}
