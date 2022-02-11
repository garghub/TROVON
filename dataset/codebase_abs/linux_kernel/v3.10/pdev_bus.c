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
F_14 ( ( unsigned long ) V_9 , V_12 + V_31 ) ;
V_9 [ V_19 ] = '\0' ;
V_18 -> V_8 . V_32 = F_10 ( V_12 + V_33 ) ;
V_18 -> V_8 . V_25 [ 0 ] . V_15 = V_11 ;
V_18 -> V_8 . V_25 [ 0 ] . V_34 = V_11 +
F_10 ( V_12 + V_35 ) - 1 ;
V_18 -> V_8 . V_25 [ 0 ] . V_36 = V_37 ;
if ( V_21 ) {
V_20 = F_10 ( V_12 + V_38 ) ;
V_18 -> V_8 . V_25 [ 1 ] . V_15 = V_20 ;
V_18 -> V_8 . V_25 [ 1 ] . V_34 = V_20 + V_21 - 1 ;
V_18 -> V_8 . V_25 [ 1 ] . V_36 = V_39 ;
}
F_15 ( L_3 , V_9 , V_11 , V_20 ) ;
F_8 ( & V_18 -> V_7 , & V_40 ) ;
F_11 ( & V_17 ) ;
return 0 ;
}
static T_2 F_16 ( int V_20 , void * V_41 )
{
T_2 V_3 = V_42 ;
while ( 1 ) {
T_1 V_43 = F_10 ( V_12 + V_44 ) ;
switch ( V_43 ) {
case V_45 :
return V_42 ;
case V_46 :
F_9 () ;
break;
case V_47 :
F_12 () ;
break;
}
V_3 = V_48 ;
}
return V_3 ;
}
static int F_17 ( struct V_49 * V_8 )
{
int V_3 ;
struct V_25 * V_50 ;
V_50 = F_18 ( V_8 , V_37 , 0 ) ;
if ( V_50 == NULL )
return - V_51 ;
V_52 = V_50 -> V_15 ;
V_53 = F_19 ( V_50 ) ;
if ( F_20 ( V_52 , V_53 , L_4 ) ) {
F_21 ( & V_8 -> V_18 , L_5 ) ;
return - V_54 ;
}
V_12 = F_22 ( V_52 , V_53 ) ;
if ( V_12 == NULL ) {
V_3 = - V_28 ;
F_21 ( & V_8 -> V_18 , L_6 ) ;
goto V_55;
}
V_50 = F_18 ( V_8 , V_39 , 0 ) ;
if ( V_50 == NULL ) {
V_3 = - V_56 ;
goto V_57;
}
V_58 = V_50 -> V_15 ;
V_3 = F_23 ( V_58 , F_16 ,
V_59 , L_7 , V_8 ) ;
if ( V_3 ) {
F_21 ( & V_8 -> V_18 , L_8 ) ;
goto V_57;
}
F_14 ( V_60 , V_12 + V_44 ) ;
return 0 ;
V_57:
F_24 ( V_12 ) ;
V_55:
F_25 ( V_52 , V_53 ) ;
return V_3 ;
}
static int F_26 ( struct V_49 * V_8 )
{
F_24 ( V_12 ) ;
F_27 ( V_58 , V_8 ) ;
F_25 ( V_52 , V_53 ) ;
return 0 ;
}
