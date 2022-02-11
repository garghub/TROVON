int F_1 ( void )
{
int V_1 = 0 ;
int V_2 ;
struct V_3 * V_4 = NULL ;
struct V_5 * V_6 ;
unsigned long V_7 ;
V_8 . V_9 = V_10 ;
V_8 . V_11 = F_2 ( L_1 ) ;
if ( ! V_8 . V_11 ) {
V_1 = - V_12 ;
goto V_13;
}
F_3 ( & V_8 . V_14 ) ;
F_4 ( & V_8 . V_15 ) ;
F_3 ( & V_8 . V_16 ) ;
F_4 ( & V_8 . V_17 ) ;
V_8 . V_18 =
( void * ) F_5 ( V_19 | V_20 , 0 ) ;
if ( V_8 . V_18 == NULL ) {
V_1 = - V_12 ;
goto V_13;
}
V_8 . V_21 = V_8 . V_18 ;
V_8 . V_22 =
( void * ) ( ( unsigned long ) V_8 . V_18 +
( V_23 >> 1 ) ) ;
V_8 . V_24 =
( void * ) F_5 ( ( V_19 | V_20 ) , 1 ) ;
if ( V_8 . V_24 == NULL ) {
V_1 = - V_12 ;
goto V_13;
}
V_4 = F_6 ( sizeof( * V_4 ) +
sizeof( struct V_5 ) ,
V_19 ) ;
if ( V_4 == NULL ) {
V_1 = - V_12 ;
goto V_13;
}
F_7 ( & V_4 -> V_25 ) ;
V_6 = (struct V_5 * ) V_4 -> V_6 ;
V_6 -> V_26 . V_27 = V_28 ;
V_6 -> V_29 = V_30 ;
V_6 -> V_31 = F_8 ( V_8 . V_18 ) ;
V_6 -> V_32 = F_8 ( V_8 . V_24 ) ;
V_6 -> V_33 = F_8 (
( void * ) ( ( unsigned long ) V_8 . V_24 +
V_23 ) ) ;
F_9 ( & V_8 . V_15 , V_7 ) ;
F_10 ( & V_4 -> V_34 ,
& V_8 . V_14 ) ;
F_11 ( & V_8 . V_15 , V_7 ) ;
V_1 = F_12 ( V_6 ,
sizeof( struct V_5 ) ) ;
if ( V_1 != 0 ) {
F_9 ( & V_8 . V_15 , V_7 ) ;
F_13 ( & V_4 -> V_34 ) ;
F_11 ( & V_8 . V_15 ,
V_7 ) ;
goto V_13;
}
V_2 = F_14 ( & V_4 -> V_25 , 5 * V_35 ) ;
if ( V_2 == 0 ) {
F_9 ( & V_8 . V_15 ,
V_7 ) ;
F_13 ( & V_4 -> V_34 ) ;
F_11 ( & V_8 . V_15 ,
V_7 ) ;
V_1 = - V_36 ;
goto V_13;
}
F_9 ( & V_8 . V_15 , V_7 ) ;
F_13 ( & V_4 -> V_34 ) ;
F_11 ( & V_8 . V_15 , V_7 ) ;
if ( V_4 -> V_37 . V_38 . V_39 ) {
V_8 . V_9 = V_40 ;
} else {
F_15 ( L_2
L_3 ,
V_30 ) ;
V_1 = - V_41 ;
goto V_13;
}
F_16 ( V_4 ) ;
return 0 ;
V_13:
V_8 . V_9 = V_42 ;
if ( V_8 . V_11 )
F_17 ( V_8 . V_11 ) ;
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
struct V_43 * F_19 ( T_1 V_44 )
{
struct V_43 * V_45 ;
struct V_43 * V_46 = NULL ;
unsigned long V_7 ;
F_9 ( & V_8 . V_17 , V_7 ) ;
F_20 (channel, &vmbus_connection.chn_list, listentry) {
if ( V_45 -> V_47 . V_48 == V_44 ) {
V_46 = V_45 ;
break;
}
}
F_11 ( & V_8 . V_17 , V_7 ) ;
return V_46 ;
}
static void F_21 ( T_1 V_44 )
{
struct V_43 * V_45 ;
unsigned long V_7 ;
V_45 = F_19 ( V_44 ) ;
if ( ! V_45 ) {
F_15 ( L_4 , V_44 ) ;
return;
}
F_9 ( & V_45 -> V_49 , V_7 ) ;
if ( V_45 -> V_50 != NULL )
V_45 -> V_50 ( V_45 -> V_51 ) ;
else
F_15 ( L_5 , V_44 ) ;
F_11 ( & V_45 -> V_49 , V_7 ) ;
}
void F_22 ( unsigned long V_52 )
{
T_1 V_53 ;
T_1 V_54 = V_55 >> 5 ;
int V_56 ;
T_1 V_44 ;
T_1 * V_21 = V_8 . V_21 ;
if ( ! V_21 )
return;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
if ( ! V_21 [ V_53 ] )
continue;
for ( V_56 = 0 ; V_56 < 32 ; V_56 ++ ) {
if ( F_23 ( V_56 ,
( unsigned long * ) & V_21 [ V_53 ] ) ) {
V_44 = ( V_53 << 5 ) + V_56 ;
if ( V_44 == 0 )
continue;
F_21 ( V_44 ) ;
}
}
}
}
int F_12 ( void * V_57 , T_2 V_58 )
{
union V_59 V_60 ;
int V_1 = 0 ;
int V_61 = 0 ;
V_60 . V_62 = 0 ;
V_60 . V_63 . V_64 = V_65 ;
while ( V_61 < 3 ) {
V_1 = F_24 ( V_60 , 1 , V_57 , V_58 ) ;
if ( V_1 != V_66 )
return V_1 ;
V_61 ++ ;
F_25 ( 100 ) ;
}
return V_1 ;
}
int F_26 ( T_1 V_48 )
{
F_27 ( V_48 & 31 ,
( unsigned long * ) V_8 . V_22 +
( V_48 >> 5 ) ) ;
return F_28 () ;
}
