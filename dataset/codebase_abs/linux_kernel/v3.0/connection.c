int F_1 ( void )
{
int V_1 = 0 ;
int V_2 ;
struct V_3 * V_4 = NULL ;
struct V_5 * V_6 ;
unsigned long V_7 ;
if ( V_8 . V_9 != V_10 )
return - 1 ;
V_8 . V_9 = V_11 ;
V_8 . V_12 = F_2 ( L_1 ) ;
if ( ! V_8 . V_12 ) {
V_1 = - 1 ;
goto V_13;
}
F_3 ( & V_8 . V_14 ) ;
F_4 ( & V_8 . V_15 ) ;
F_3 ( & V_8 . V_16 ) ;
F_4 ( & V_8 . V_17 ) ;
V_8 . V_18 =
( void * ) F_5 ( V_19 | V_20 , 0 ) ;
if ( V_8 . V_18 == NULL ) {
V_1 = - 1 ;
goto V_13;
}
V_8 . V_21 = V_8 . V_18 ;
V_8 . V_22 =
( void * ) ( ( unsigned long ) V_8 . V_18 +
( V_23 >> 1 ) ) ;
V_8 . V_24 =
( void * ) F_5 ( ( V_19 | V_20 ) , 1 ) ;
if ( V_8 . V_24 == NULL ) {
V_1 = - 1 ;
goto V_13;
}
V_4 = F_6 ( sizeof( * V_4 ) +
sizeof( struct V_5 ) ,
V_19 ) ;
if ( V_4 == NULL ) {
V_1 = - V_25 ;
goto V_13;
}
F_7 ( & V_4 -> V_26 ) ;
V_6 = (struct V_5 * ) V_4 -> V_6 ;
V_6 -> V_27 . V_28 = V_29 ;
V_6 -> V_30 = V_31 ;
V_6 -> V_32 = F_8 ( V_8 . V_18 ) ;
V_6 -> V_33 = F_8 ( V_8 . V_24 ) ;
V_6 -> V_34 = F_8 (
( void * ) ( ( unsigned long ) V_8 . V_24 +
V_23 ) ) ;
F_9 ( & V_8 . V_15 , V_7 ) ;
F_10 ( & V_4 -> V_35 ,
& V_8 . V_14 ) ;
F_11 ( & V_8 . V_15 , V_7 ) ;
V_1 = F_12 ( V_6 ,
sizeof( struct V_5 ) ) ;
if ( V_1 != 0 ) {
F_9 ( & V_8 . V_15 , V_7 ) ;
F_13 ( & V_4 -> V_35 ) ;
F_11 ( & V_8 . V_15 ,
V_7 ) ;
goto V_13;
}
V_2 = F_14 ( & V_4 -> V_26 , V_36 ) ;
if ( V_2 == 0 ) {
F_9 ( & V_8 . V_15 ,
V_7 ) ;
F_13 ( & V_4 -> V_35 ) ;
F_11 ( & V_8 . V_15 ,
V_7 ) ;
V_1 = - V_37 ;
goto V_13;
}
F_9 ( & V_8 . V_15 , V_7 ) ;
F_13 ( & V_4 -> V_35 ) ;
F_11 ( & V_8 . V_15 , V_7 ) ;
if ( V_4 -> V_38 . V_39 . V_40 ) {
V_8 . V_9 = V_41 ;
} else {
F_15 ( L_2
L_3 ,
V_31 ) ;
V_1 = - 1 ;
goto V_13;
}
F_16 ( V_4 ) ;
return 0 ;
V_13:
V_8 . V_9 = V_10 ;
if ( V_8 . V_12 )
F_17 ( V_8 . V_12 ) ;
if ( V_8 . V_18 ) {
F_18 ( ( unsigned long ) V_8 . V_18 , 0 ) ;
V_8 . V_18 = NULL ;
}
if ( V_8 . V_24 ) {
F_18 ( ( unsigned long ) V_8 . V_24 , 1 ) ;
V_8 . V_24 = NULL ;
}
F_16 ( V_4 ) ;
return V_1 ;
}
int F_19 ( void )
{
int V_1 = 0 ;
struct V_42 * V_6 ;
if ( V_8 . V_9 != V_41 )
return - 1 ;
V_6 = F_6 ( sizeof( struct V_42 ) , V_19 ) ;
if ( ! V_6 )
return - V_25 ;
V_6 -> V_28 = V_43 ;
V_1 = F_12 ( V_6 ,
sizeof( struct V_42 ) ) ;
if ( V_1 != 0 )
goto V_13;
F_18 ( ( unsigned long ) V_8 . V_18 , 0 ) ;
F_18 ( ( unsigned long ) V_8 . V_24 , 1 ) ;
F_17 ( V_8 . V_12 ) ;
V_8 . V_9 = V_10 ;
F_20 ( L_4 ) ;
V_13:
F_16 ( V_6 ) ;
return V_1 ;
}
struct V_44 * F_21 ( T_1 V_45 )
{
struct V_44 * V_46 ;
struct V_44 * V_47 = NULL ;
unsigned long V_7 ;
F_9 ( & V_8 . V_17 , V_7 ) ;
F_22 (channel, &vmbus_connection.chn_list, listentry) {
if ( V_46 -> V_48 . V_49 == V_45 ) {
V_47 = V_46 ;
break;
}
}
F_11 ( & V_8 . V_17 , V_7 ) ;
return V_47 ;
}
static void F_23 ( T_1 V_45 )
{
struct V_44 * V_46 ;
V_46 = F_21 ( V_45 ) ;
if ( V_46 ) {
F_24 ( V_46 ) ;
} else {
F_15 ( L_5 , V_45 ) ;
}
}
void F_25 ( unsigned long V_50 )
{
T_1 V_51 ;
T_1 V_52 = V_53 >> 5 ;
int V_54 ;
T_1 V_45 ;
T_1 * V_21 = V_8 . V_21 ;
if ( ! V_21 )
return;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
if ( ! V_21 [ V_51 ] )
continue;
for ( V_54 = 0 ; V_54 < 32 ; V_54 ++ ) {
if ( F_26 ( V_54 , ( unsigned long * ) & V_21 [ V_51 ] ) ) {
V_45 = ( V_51 << 5 ) + V_54 ;
if ( V_45 == 0 ) {
continue;
}
F_23 ( V_45 ) ;
}
}
}
}
int F_12 ( void * V_55 , T_2 V_56 )
{
union V_57 V_58 ;
V_58 . V_59 = 0 ;
V_58 . V_60 . V_61 = V_62 ;
return F_27 ( V_58 , 1 , V_55 , V_56 ) ;
}
int F_28 ( T_1 V_49 )
{
F_29 ( V_49 & 31 ,
( unsigned long * ) V_8 . V_22 +
( V_49 >> 5 ) ) ;
return F_30 () ;
}
