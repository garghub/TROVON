static int F_1 ( const void * V_1 , const void * V_2 )
{
const struct V_3 * V_4 = V_1 ;
const struct V_3 * V_5 = V_2 ;
int V_6 , V_7 ;
V_6 = V_4 -> V_8 >> 32 ;
V_7 = V_5 -> V_8 >> 32 ;
return V_6 - V_7 ;
}
static void F_2 ( void )
{
int V_9 ;
unsigned V_10 ;
unsigned V_11 ;
int V_12 ;
T_1 V_13 ;
T_2 V_14 ;
T_1 V_15 ;
T_1 V_16 = V_17 ;
int V_18 ;
struct V_3 V_3 [ 8 ] ;
if ( V_19 )
return;
if ( ! F_3 () )
return;
V_12 = 0 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_20 ) ; V_9 ++ ) {
T_2 V_21 ;
T_3 V_22 ;
T_3 V_23 ;
V_10 = V_20 [ V_9 ] . V_10 ;
V_11 = V_20 [ V_9 ] . V_11 ;
V_21 = F_5 ( V_10 , V_11 , 0 , V_24 ) ;
V_23 = V_21 & 0xffff ;
V_22 = ( V_21 >> 16 ) & 0xffff ;
if ( V_20 [ V_9 ] . V_23 == V_23 &&
V_20 [ V_9 ] . V_22 == V_22 ) {
V_12 = 1 ;
break;
}
}
if ( ! V_12 )
return;
V_14 = V_25 ;
F_6 ( V_14 , V_13 ) ;
if ( ! ( V_13 & ( 1 << 21 ) ) ) {
V_15 = 1ULL << 32 ;
} else {
V_14 = V_26 ;
F_6 ( V_14 , V_13 ) ;
V_15 = F_7 ( V_13 & 0xffffff800000ULL , 1ULL << 32 ) ;
}
if ( V_16 <= V_15 )
V_16 = ( V_15 + 2 * V_27 - 1 ) & V_28 ;
V_18 = 0 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
T_2 V_29 ;
T_1 V_8 ;
T_1 V_30 ;
V_29 = F_5 ( V_10 , V_11 , 1 , 0x80 + ( V_9 << 3 ) ) ;
if ( ! ( V_29 & 3 ) )
continue;
V_8 = ( T_1 ) ( V_29 & 0xffffff00 ) << 8 ;
V_29 = F_5 ( V_10 , V_11 , 1 , 0x84 + ( V_9 << 3 ) ) ;
V_30 = ( ( T_1 ) ( V_29 & 0xffffff00 ) << 8 ) | 0xffff ;
if ( V_30 < V_15 )
continue;
V_3 [ V_18 ] . V_8 = V_8 ;
V_3 [ V_18 ] . V_30 = V_30 ;
V_18 ++ ;
}
if ( ! V_18 )
goto V_31;
F_8 ( V_3 , V_18 , sizeof( struct V_3 ) , F_1 , NULL ) ;
if ( V_3 [ V_18 - 1 ] . V_30 < V_16 )
goto V_31;
if ( V_3 [ 0 ] . V_8 > V_16 + V_32 )
goto V_31;
V_16 = ( V_3 [ 0 ] . V_8 & V_28 ) - V_27 ;
if ( ( V_16 > V_15 ) && F_9 ( V_16 ) )
goto V_31;
V_16 = ( V_3 [ V_18 - 1 ] . V_30 + V_27 ) & V_28 ;
if ( F_9 ( V_16 ) )
goto V_31;
for ( V_9 = 1 ; V_9 < V_18 ; V_9 ++ ) {
V_16 = ( V_3 [ V_9 - 1 ] . V_30 + V_27 ) & V_28 ;
V_13 = V_3 [ V_9 ] . V_8 & V_28 ;
if ( V_13 >= V_16 + V_32 && F_9 ( V_16 ) )
goto V_31;
}
return;
V_31:
V_19 = V_16 ;
}
void F_10 ( void )
{
T_1 V_13 ;
T_2 V_14 ;
if ( ! ( V_33 & V_34 ) )
return;
V_14 = V_35 ;
F_6 ( V_14 , V_13 ) ;
if ( V_13 & V_36 ) {
unsigned V_37 ;
V_37 = ( V_13 >> V_38 ) &
V_39 ;
if ( ! V_40 || V_37 >= 8 ) {
T_1 V_16 = V_13 & V_28 ;
if ( ! V_19 ) {
V_19 = V_16 ;
return;
} else if ( V_19 == V_16 )
return;
}
}
F_2 () ;
if ( ! V_19 ) {
V_33 &= ~ V_34 ;
return;
}
F_11 ( V_41 L_1 ) ;
V_13 &= ~ ( ( V_42 << V_43 ) |
( V_39 << V_38 ) ) ;
V_13 |= V_19 | ( 8 << V_38 ) |
V_36 ;
F_12 ( V_14 , V_13 ) ;
}
static int T_4 F_13 ( const struct V_44 * V_45 )
{
V_33 |= V_34 ;
return 0 ;
}
void T_5 F_14 ( void )
{
F_15 ( V_46 ) ;
}
