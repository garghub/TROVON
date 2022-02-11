static int T_1 F_1 ( char * V_1 )
{
V_2 = true ;
return 0 ;
}
static void T_1 F_2 ( struct V_3 * V_3 ,
struct V_4 * V_5 , void * V_6 ,
struct V_7 V_8 [] )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_3 -> V_10 ; V_9 ++ ) {
int V_11 = V_3 -> V_12 - ( V_6 - ( void * ) V_3 ) ;
T_2 V_13 , V_14 ;
char * V_15 ;
if ( sizeof( V_13 ) > V_11 )
break;
V_13 = * ( F_3 ( V_13 ) * ) V_6 ;
if ( V_13 + sizeof( V_14 ) > V_11 ||
V_13 < sizeof( V_13 ) + sizeof( V_16 ) ||
* ( V_16 * ) ( V_6 + sizeof( V_13 ) ) == 0 ) {
F_4 ( V_5 , L_1 ,
V_6 - ( void * ) V_3 ) ;
break;
}
V_14 = * ( F_3 ( V_14 ) * ) ( V_6 + V_13 ) ;
if ( V_13 + V_14 > V_11 ||
V_14 < sizeof( V_14 ) ) {
F_4 ( V_5 , L_2 ,
V_6 - ( void * ) V_3 + V_13 ) ;
break;
}
V_15 = F_5 ( ( V_13 - sizeof( V_13 ) ) * 4 + 1 , V_17 ) ;
if ( ! V_15 ) {
F_4 ( V_5 , L_3 ) ;
break;
}
F_6 ( V_15 , V_6 + sizeof( V_13 ) ,
V_13 - sizeof( V_13 ) ) ;
V_8 [ V_9 ] . V_18 = V_15 ;
V_8 [ V_9 ] . V_19 = true ;
V_8 [ V_9 ] . V_20 = V_14 - sizeof( V_14 ) ;
V_8 [ V_9 ] . V_21 . V_22 = V_6 + V_13 + sizeof( V_14 ) ;
if ( ! V_8 [ V_9 ] . V_20 ) {
V_8 [ V_9 ] . V_20 = 1 ;
V_8 [ V_9 ] . V_21 . V_22 = & V_23 ;
}
if ( V_2 ) {
F_7 ( V_5 , L_4 , V_8 [ V_9 ] . V_18 ) ;
F_8 ( V_24 , F_9 () , V_25 ,
16 , 1 , V_8 [ V_9 ] . V_21 . V_22 ,
V_8 [ V_9 ] . V_20 , true ) ;
}
V_6 += V_13 + V_14 ;
}
if ( V_9 != V_3 -> V_10 ) {
F_4 ( V_5 , L_5 , V_9 ,
V_3 -> V_10 ) ;
F_8 ( V_26 , F_9 () , V_25 ,
16 , 1 , V_3 , V_3 -> V_12 , true ) ;
return;
}
F_7 ( V_5 , L_6 , V_9 ) ;
}
static int T_1 F_10 ( struct V_27 * V_28 )
{
T_3 V_29 = F_11 ( struct V_27 , V_3 [ 0 ] ) ;
while ( V_29 + sizeof( struct V_3 ) < V_28 -> V_12 ) {
struct V_3 * V_3 = ( void * ) V_28 + V_29 ;
struct V_7 * V_8 = NULL ;
struct V_4 * V_5 ;
T_3 V_12 ;
int V_30 , V_9 ;
void * V_6 ;
if ( V_29 + V_3 -> V_12 > V_28 -> V_12 ||
V_3 -> V_12 <= sizeof( * V_3 ) ) {
F_12 ( L_7 , V_29 ) ;
return - V_31 ;
}
V_6 = V_3 -> V_32 ;
V_12 = V_3 -> V_12 - sizeof( * V_3 ) ;
V_5 = F_13 ( (struct V_33 * * ) & V_6 , & V_12 ) ;
if ( F_14 ( V_5 ) ) {
F_12 ( L_8 ,
F_15 ( V_5 ) , V_6 - ( void * ) V_3 ) ;
F_8 ( V_26 , F_9 () , V_25 ,
16 , 1 , V_3 , V_3 -> V_12 , true ) ;
V_5 = NULL ;
goto V_34;
}
V_8 = F_16 ( V_3 -> V_10 + 1 , sizeof( * V_8 ) ,
V_17 ) ;
if ( ! V_8 ) {
F_4 ( V_5 , L_9 ) ;
goto V_34;
}
F_2 ( V_3 , V_5 , V_6 , V_8 ) ;
if ( ! V_8 [ 0 ] . V_18 )
goto V_34;
V_30 = F_17 ( V_5 , V_8 ) ;
if ( V_30 )
F_4 ( V_5 , L_10 , V_30 ) ;
for ( V_9 = 0 ; V_8 [ V_9 ] . V_18 ; V_9 ++ )
F_18 ( V_8 [ V_9 ] . V_18 ) ;
V_34:
F_18 ( V_8 ) ;
F_19 ( V_5 ) ;
V_29 += V_3 -> V_12 ;
}
return 0 ;
}
static int T_1 F_20 ( void )
{
struct V_27 * V_28 ;
struct V_35 * V_36 ;
T_2 V_37 ;
T_4 V_38 ;
int V_30 ;
if ( ! F_21 ( V_39 , L_11 ) &&
! F_21 ( V_39 , L_12 ) )
return 0 ;
V_38 = V_40 . V_41 . V_35 ;
while ( V_38 ) {
V_36 = F_22 ( V_38 , sizeof( * V_36 ) ) ;
if ( ! V_36 ) {
F_12 ( L_13 ) ;
return - V_42 ;
}
if ( V_36 -> type != V_43 ) {
V_38 = V_36 -> V_44 ;
F_23 ( V_36 ) ;
continue;
}
V_37 = V_36 -> V_12 ;
F_23 ( V_36 ) ;
V_36 = F_22 ( V_38 , sizeof( * V_36 ) + V_37 ) ;
if ( ! V_36 ) {
F_12 ( L_14 ) ;
return - V_42 ;
}
V_28 = (struct V_27 * ) V_36 -> V_36 ;
if ( V_28 -> V_45 != 1 ) {
F_12 ( L_15 ) ;
F_8 ( V_26 , F_9 () , V_25 ,
16 , 1 , V_28 , V_37 , true ) ;
V_30 = - V_46 ;
} else if ( V_28 -> V_12 != V_37 ) {
F_12 ( L_16 , V_37 ) ;
F_8 ( V_26 , F_9 () , V_25 ,
16 , 1 , V_28 , V_37 , true ) ;
V_30 = - V_31 ;
} else
V_30 = F_10 ( V_28 ) ;
V_36 -> V_12 = 0 ;
F_23 ( V_36 ) ;
F_24 ( V_38 + sizeof( * V_36 ) , V_37 ) ;
return V_30 ;
}
return 0 ;
}
