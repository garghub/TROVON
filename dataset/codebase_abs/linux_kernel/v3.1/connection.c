int F_1 ( void )
{
int V_1 = 0 ;
int V_2 ;
struct V_3 * V_4 = NULL ;
struct V_5 * V_6 ;
unsigned long V_7 ;
if ( V_8 . V_9 != V_10 )
return - V_11 ;
V_8 . V_9 = V_12 ;
V_8 . V_13 = F_2 ( L_1 ) ;
if ( ! V_8 . V_13 ) {
V_1 = - V_14 ;
goto V_15;
}
F_3 ( & V_8 . V_16 ) ;
F_4 ( & V_8 . V_17 ) ;
F_3 ( & V_8 . V_18 ) ;
F_4 ( & V_8 . V_19 ) ;
V_8 . V_20 =
( void * ) F_5 ( V_21 | V_22 , 0 ) ;
if ( V_8 . V_20 == NULL ) {
V_1 = - V_14 ;
goto V_15;
}
V_8 . V_23 = V_8 . V_20 ;
V_8 . V_24 =
( void * ) ( ( unsigned long ) V_8 . V_20 +
( V_25 >> 1 ) ) ;
V_8 . V_26 =
( void * ) F_5 ( ( V_21 | V_22 ) , 1 ) ;
if ( V_8 . V_26 == NULL ) {
V_1 = - V_14 ;
goto V_15;
}
V_4 = F_6 ( sizeof( * V_4 ) +
sizeof( struct V_5 ) ,
V_21 ) ;
if ( V_4 == NULL ) {
V_1 = - V_14 ;
goto V_15;
}
F_7 ( & V_4 -> V_27 ) ;
V_6 = (struct V_5 * ) V_4 -> V_6 ;
V_6 -> V_28 . V_29 = V_30 ;
V_6 -> V_31 = V_32 ;
V_6 -> V_33 = F_8 ( V_8 . V_20 ) ;
V_6 -> V_34 = F_8 ( V_8 . V_26 ) ;
V_6 -> V_35 = F_8 (
( void * ) ( ( unsigned long ) V_8 . V_26 +
V_25 ) ) ;
F_9 ( & V_8 . V_17 , V_7 ) ;
F_10 ( & V_4 -> V_36 ,
& V_8 . V_16 ) ;
F_11 ( & V_8 . V_17 , V_7 ) ;
V_1 = F_12 ( V_6 ,
sizeof( struct V_5 ) ) ;
if ( V_1 != 0 ) {
F_9 ( & V_8 . V_17 , V_7 ) ;
F_13 ( & V_4 -> V_36 ) ;
F_11 ( & V_8 . V_17 ,
V_7 ) ;
goto V_15;
}
V_2 = F_14 ( & V_4 -> V_27 , 5 * V_37 ) ;
if ( V_2 == 0 ) {
F_9 ( & V_8 . V_17 ,
V_7 ) ;
F_13 ( & V_4 -> V_36 ) ;
F_11 ( & V_8 . V_17 ,
V_7 ) ;
V_1 = - V_38 ;
goto V_15;
}
F_9 ( & V_8 . V_17 , V_7 ) ;
F_13 ( & V_4 -> V_36 ) ;
F_11 ( & V_8 . V_17 , V_7 ) ;
if ( V_4 -> V_39 . V_40 . V_41 ) {
V_8 . V_9 = V_42 ;
} else {
F_15 ( L_2
L_3 ,
V_32 ) ;
V_1 = - V_43 ;
goto V_15;
}
F_16 ( V_4 ) ;
return 0 ;
V_15:
V_8 . V_9 = V_10 ;
if ( V_8 . V_13 )
F_17 ( V_8 . V_13 ) ;
if ( V_8 . V_20 ) {
F_18 ( ( unsigned long ) V_8 . V_20 , 0 ) ;
V_8 . V_20 = NULL ;
}
if ( V_8 . V_26 ) {
F_18 ( ( unsigned long ) V_8 . V_26 , 1 ) ;
V_8 . V_26 = NULL ;
}
F_16 ( V_4 ) ;
return V_1 ;
}
struct V_44 * F_19 ( T_1 V_45 )
{
struct V_44 * V_46 ;
struct V_44 * V_47 = NULL ;
unsigned long V_7 ;
F_9 ( & V_8 . V_19 , V_7 ) ;
F_20 (channel, &vmbus_connection.chn_list, listentry) {
if ( V_46 -> V_48 . V_49 == V_45 ) {
V_47 = V_46 ;
break;
}
}
F_11 ( & V_8 . V_19 , V_7 ) ;
return V_47 ;
}
static void F_21 ( T_1 V_45 )
{
struct V_44 * V_46 ;
V_46 = F_19 ( V_45 ) ;
if ( V_46 ) {
V_46 -> V_50 ( V_46 -> V_51 ) ;
} else {
F_15 ( L_4 , V_45 ) ;
}
}
void F_22 ( unsigned long V_52 )
{
T_1 V_53 ;
T_1 V_54 = V_55 >> 5 ;
int V_56 ;
T_1 V_45 ;
T_1 * V_23 = V_8 . V_23 ;
if ( ! V_23 )
return;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
if ( ! V_23 [ V_53 ] )
continue;
for ( V_56 = 0 ; V_56 < 32 ; V_56 ++ ) {
if ( F_23 ( V_56 , ( unsigned long * ) & V_23 [ V_53 ] ) ) {
V_45 = ( V_53 << 5 ) + V_56 ;
if ( V_45 == 0 ) {
continue;
}
F_21 ( V_45 ) ;
}
}
}
}
int F_12 ( void * V_57 , T_2 V_58 )
{
union V_59 V_60 ;
V_60 . V_61 = 0 ;
V_60 . V_62 . V_63 = V_64 ;
return F_24 ( V_60 , 1 , V_57 , V_58 ) ;
}
int F_25 ( T_1 V_49 )
{
F_26 ( V_49 & 31 ,
( unsigned long * ) V_8 . V_24 +
( V_49 >> 5 ) ) ;
return F_27 () ;
}
