static void T_1 F_1 ( int V_1 )
{
T_2 * V_2 ;
void * V_3 ;
if ( ! ( V_4 & V_5 ) )
return;
for ( V_3 = V_6 . V_7 ; V_3 < V_6 . V_8 ; V_3 += V_6 . V_9 ) {
V_2 = V_3 ;
if ( V_2 -> type == V_10 ||
V_2 -> type == V_11 )
F_2 ( V_2 , V_1 ) ;
}
}
void T_1 F_3 ( void )
{
unsigned long V_12 ;
int V_13 ;
int V_14 ;
if ( ! F_4 ( V_15 ) )
return;
F_1 ( 1 ) ;
F_5 ( V_16 ) ;
V_14 = F_6 ( ( V_17 << V_18 ) , V_19 ) ;
V_20 = F_7 ( V_14 * sizeof( V_21 ) , V_22 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_20 [ V_13 ] = * F_8 ( V_13 * V_19 ) ;
V_12 = ( unsigned long ) F_9 ( V_13 * V_19 ) ;
F_10 ( F_8 ( V_13 * V_19 ) , * F_8 ( V_12 ) ) ;
}
F_11 () ;
}
void T_1 F_12 ( void )
{
int V_13 ;
int V_14 = F_6 ( ( V_17 << V_18 ) , V_19 ) ;
if ( ! F_4 ( V_15 ) )
return;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_10 ( F_8 ( V_13 * V_19 ) , V_20 [ V_13 ] ) ;
F_13 ( V_20 ) ;
F_11 () ;
F_14 ( V_16 ) ;
F_1 ( 0 ) ;
}
void F_15 ( void )
{
unsigned V_23 ;
V_21 * V_13 = ( V_21 * ) F_9 ( V_24 -> V_25 ) ;
if ( F_4 ( V_15 ) )
return;
V_23 = F_16 ( V_26 - 1 ) - F_16 ( V_27 ) ;
memcpy ( V_13 + F_16 ( V_27 ) ,
V_28 . V_13 + F_16 ( V_27 ) ,
sizeof( V_21 ) * V_23 ) ;
}
void F_17 ( void )
{
V_29 . V_30 = ( V_21 * ) ( unsigned long ) V_24 -> V_25 ;
if ( ! F_4 ( V_15 ) )
V_29 . V_31 = true ;
}
static void T_1 F_18 ( T_2 * V_2 , T_3 V_32 )
{
V_21 * V_13 = ( V_21 * ) F_9 ( V_24 -> V_25 ) ;
unsigned long V_33 = 0 ;
if ( ! ( V_2 -> V_34 & V_35 ) )
V_33 |= V_36 ;
if ( F_19 ( V_13 , V_2 -> V_37 , V_32 , V_2 -> V_38 , V_33 ) )
F_20 ( L_1 ,
V_2 -> V_37 , V_32 ) ;
}
void T_1 F_21 ( T_2 * V_2 )
{
unsigned long V_39 = V_2 -> V_38 << V_18 ;
T_3 V_40 = V_2 -> V_37 ;
if ( F_4 ( V_15 ) )
return F_22 ( V_2 ) ;
F_18 ( V_2 , V_2 -> V_37 ) ;
V_41 -= V_39 ;
if ( ! ( V_40 & ( V_42 - 1 ) ) ) {
V_41 &= V_43 ;
} else {
T_3 V_44 = V_40 & ( V_42 - 1 ) ;
T_3 V_45 = V_41 ;
V_41 = ( V_41 & V_43 ) + V_44 ;
if ( V_41 > V_45 )
V_41 -= V_42 ;
}
if ( V_41 < V_46 ) {
F_20 ( V_47 L_2 ) ;
return;
}
F_18 ( V_2 , V_41 ) ;
V_2 -> V_48 = V_41 ;
}
void T_1 F_23 ( T_2 * V_2 )
{
F_18 ( V_2 , V_2 -> V_48 ) ;
}
void T_4 * T_1 F_24 ( unsigned long V_37 , unsigned long V_39 ,
T_5 type , T_3 V_34 )
{
unsigned long V_49 ;
if ( type == V_50 )
return F_25 ( V_37 , V_39 ) ;
V_49 = F_26 ( V_37 , V_37 + V_39 ) ;
if ( ( V_49 << V_18 ) < V_37 + V_39 ) {
unsigned long V_51 = V_49 << V_18 ;
F_24 ( V_51 , V_39 - ( V_51 - V_37 ) , type , V_34 ) ;
}
if ( ! ( V_34 & V_35 ) )
F_27 ( ( T_3 ) ( unsigned long ) F_9 ( V_37 ) , V_39 ) ;
return ( void T_4 * ) F_9 ( V_37 ) ;
}
void T_1 F_28 ( T_3 V_37 , T_5 V_52 )
{
V_53 = V_37 + sizeof( struct V_54 ) ;
}
void T_1 F_29 ( void )
{
if ( ! F_4 ( V_15 ) )
return;
if ( V_4 & V_5 )
F_30 () ;
}
