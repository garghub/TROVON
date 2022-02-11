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
V_7:
F_6 ( V_1 , sizeof( * V_1 ) ) ;
return 0 ;
}
static bool F_7 ( const T_3 * V_11 , T_3 * V_12 )
{
T_4 V_13 = V_11 -> V_14 ;
T_4 V_15 = V_11 -> V_16 << V_17 ;
T_3 * V_18 ;
* V_12 = * V_11 ;
if ( V_11 -> type != V_19 &&
V_11 -> type != V_20 ) {
F_4 ( L_3 ) ;
return false ;
}
if ( ! ( V_11 -> V_21 & ( V_22 | V_23 ) ) ) {
F_4 ( L_4 ) ;
return false ;
}
if ( V_24 > V_25 &&
( ! F_8 ( V_11 -> V_14 ) ||
! F_8 ( V_11 -> V_16 << V_17 ) ) ) {
F_4 ( L_5 ) ;
return false ;
}
F_9 (md) {
T_4 V_26 = V_18 -> V_14 ;
T_4 V_27 = V_18 -> V_16 << V_17 ;
if ( ! ( V_18 -> V_21 & V_28 ) )
continue;
if ( V_18 -> V_29 == 0 ) {
break;
}
if ( V_26 > V_13 || ( V_13 - V_26 ) >= V_27 )
continue;
if ( V_26 + V_27 < V_13 + V_15 ) {
F_4 ( L_6 ) ;
return false ;
}
if ( V_18 -> type != V_11 -> type ) {
F_4 ( L_7 ) ;
return false ;
}
V_12 -> V_29 = V_13 + ( V_18 -> V_29 - V_26 ) ;
return true ;
}
F_4 ( L_8 ) ;
return false ;
}
int T_1 F_10 ( struct V_30 * V_31 ,
T_5 V_32 )
{
T_2 * V_1 ;
int V_33 , V_34 ;
if ( V_8 <= sizeof( * V_1 ) )
return 0 ;
if ( F_11 ( ! F_12 ( V_35 ) ) )
return 0 ;
V_1 = F_13 ( V_2 . V_3 , V_8 , V_36 ) ;
if ( ! V_1 ) {
F_3 ( L_1 ,
V_2 . V_3 ) ;
return - V_5 ;
}
if ( F_12 ( V_37 ) )
F_14 ( L_9 ) ;
for ( V_33 = V_34 = 0 ; V_34 == 0 && V_33 < V_1 -> V_9 ; V_33 ++ ) {
T_3 V_18 ;
unsigned long V_38 ;
bool V_39 ;
char V_40 [ 64 ] ;
V_39 = F_7 ( ( void * ) V_1 -> V_41 + V_33 * V_1 -> V_10 ,
& V_18 ) ;
V_38 = V_18 . V_16 << V_17 ;
if ( F_12 ( V_37 ) || ! V_39 )
F_14 ( L_10 ,
V_39 ? L_11 : L_12 , V_18 . V_14 ,
V_18 . V_14 + V_38 - 1 ,
F_15 ( V_40 , sizeof( V_40 ) , & V_18 ) ) ;
if ( V_39 )
V_34 = V_32 ( V_31 , & V_18 ) ;
}
F_16 ( V_1 ) ;
return V_34 ;
}
