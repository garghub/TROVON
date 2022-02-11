static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 , * V_6 ;
F_2 (pos, n, &pdev_bus_removed_devices, list) {
F_3 ( & V_5 -> V_7 ) ;
F_4 ( & V_5 -> V_8 ) ;
F_5 ( V_5 ) ;
}
F_2 (pos, n, &pdev_bus_new_devices, list) {
F_3 ( & V_5 -> V_7 ) ;
V_3 = F_6 ( & V_5 -> V_8 ) ;
if ( V_3 )
F_7 ( L_1 ,
V_5 -> V_8 . V_9 ) ;
F_8 ( & V_5 -> V_7 , & V_10 ) ;
}
}
static void F_9 ( void )
{
struct V_4 * V_5 , * V_6 ;
T_1 V_11 ;
V_11 = F_10 ( V_12 + V_13 ) ;
F_2 (pos, n, &pdev_bus_new_devices, list) {
if ( V_5 -> V_14 [ 0 ] . V_15 == V_11 ) {
F_3 ( & V_5 -> V_7 ) ;
F_5 ( V_5 ) ;
return;
}
}
F_2 (pos, n, &pdev_bus_registered_devices, list) {
if ( V_5 -> V_14 [ 0 ] . V_15 == V_11 ) {
F_3 ( & V_5 -> V_7 ) ;
F_8 ( & V_5 -> V_7 , & V_16 ) ;
F_11 ( & V_17 ) ;
return;
}
} ;
F_7 ( L_2 , V_11 ) ;
}
static int F_12 ( void )
{
struct V_4 * V_18 ;
T_1 V_19 ;
T_1 V_20 = - 1 , V_21 ;
int V_22 = 2 ;
T_1 V_11 ;
char * V_9 ;
V_11 = F_10 ( V_12 + V_13 ) ;
V_21 = F_10 ( V_12 + V_23 ) ;
V_19 = F_10 ( V_12 + V_24 ) ;
if ( V_21 )
V_22 ++ ;
V_18 = F_13 ( sizeof( * V_18 ) +
sizeof( struct V_25 ) * V_22 +
V_19 + 1 + sizeof( * V_18 -> V_8 . V_18 . V_26 ) , V_27 ) ;
if ( V_18 == NULL )
return - V_28 ;
V_18 -> V_8 . V_29 = V_22 ;
V_18 -> V_8 . V_25 = (struct V_25 * ) ( V_18 + 1 ) ;
V_18 -> V_8 . V_9 = V_9 = ( char * ) ( V_18 -> V_8 . V_25 + V_22 ) ;
V_18 -> V_8 . V_18 . V_30 = ~ 0 ;
V_18 -> V_8 . V_18 . V_26 = ( void * ) ( V_18 -> V_8 . V_9 + V_19 + 1 ) ;
* V_18 -> V_8 . V_18 . V_26 = ~ 0 ;
#ifdef F_14
F_15 ( ( T_1 ) ( ( V_31 ) V_9 >> 32 ) , V_12 + V_32 ) ;
#endif
F_15 ( ( T_1 ) ( unsigned long ) V_9 , V_12 + V_33 ) ;
V_9 [ V_19 ] = '\0' ;
V_18 -> V_8 . V_34 = F_10 ( V_12 + V_35 ) ;
V_18 -> V_8 . V_25 [ 0 ] . V_15 = V_11 ;
V_18 -> V_8 . V_25 [ 0 ] . V_36 = V_11 +
F_10 ( V_12 + V_37 ) - 1 ;
V_18 -> V_8 . V_25 [ 0 ] . V_38 = V_39 ;
if ( V_21 ) {
V_20 = F_10 ( V_12 + V_40 ) ;
V_18 -> V_8 . V_25 [ 1 ] . V_15 = V_20 ;
V_18 -> V_8 . V_25 [ 1 ] . V_36 = V_20 + V_21 - 1 ;
V_18 -> V_8 . V_25 [ 1 ] . V_38 = V_41 ;
}
F_16 ( L_3 , V_9 , V_11 , V_20 ) ;
F_8 ( & V_18 -> V_7 , & V_42 ) ;
F_11 ( & V_17 ) ;
return 0 ;
}
static T_2 F_17 ( int V_20 , void * V_43 )
{
T_2 V_3 = V_44 ;
while ( 1 ) {
T_1 V_45 = F_10 ( V_12 + V_46 ) ;
switch ( V_45 ) {
case V_47 :
F_9 () ;
V_3 = V_48 ;
break;
case V_49 :
F_12 () ;
V_3 = V_48 ;
break;
case V_50 :
default:
return V_3 ;
}
}
}
static int F_18 ( struct V_51 * V_8 )
{
int V_3 ;
struct V_25 * V_52 ;
V_52 = F_19 ( V_8 , V_39 , 0 ) ;
if ( V_52 == NULL )
return - V_53 ;
V_54 = V_52 -> V_15 ;
V_55 = F_20 ( V_52 ) ;
V_12 = F_21 ( V_54 , V_55 ) ;
if ( V_12 == NULL ) {
V_3 = - V_28 ;
F_22 ( & V_8 -> V_18 , L_4 ) ;
goto V_56;
}
V_52 = F_19 ( V_8 , V_41 , 0 ) ;
if ( V_52 == NULL ) {
V_3 = - V_57 ;
goto V_58;
}
V_59 = V_52 -> V_15 ;
V_3 = F_23 ( V_59 , F_17 ,
V_60 , L_5 , V_8 ) ;
if ( V_3 ) {
F_22 ( & V_8 -> V_18 , L_6 ) ;
goto V_58;
}
F_15 ( V_61 , V_12 + V_46 ) ;
return 0 ;
V_58:
F_24 ( V_12 ) ;
V_56:
F_25 ( V_54 , V_55 ) ;
return V_3 ;
}
