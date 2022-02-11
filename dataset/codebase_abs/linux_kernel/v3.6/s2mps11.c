static int F_1 ( int V_1 )
{
unsigned char V_2 = 0 ;
V_1 /= 6 ;
while ( true ) {
V_1 = V_1 >> 1 ;
if ( V_1 == 0 )
break;
V_2 ++ ;
}
return V_2 ;
}
static T_1 int F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 . V_8 ) ;
struct V_9 * V_10 = F_4 ( V_6 -> V_7 ) ;
struct V_11 V_12 = { } ;
struct V_13 * * V_14 ;
struct V_15 * V_16 ;
int V_17 , V_18 , V_19 ;
unsigned char V_20 , V_21 = 0 ;
if ( ! V_10 ) {
F_5 ( V_4 -> V_7 . V_8 , L_1 ) ;
return - V_22 ;
}
V_16 = F_6 ( & V_4 -> V_7 , sizeof( struct V_15 ) ,
V_23 ) ;
if ( ! V_16 )
return - V_24 ;
V_19 = sizeof( struct V_13 * ) * V_25 ;
V_16 -> V_14 = F_6 ( & V_4 -> V_7 , V_19 , V_23 ) ;
if ( ! V_16 -> V_14 ) {
return - V_24 ;
}
V_14 = V_16 -> V_14 ;
F_7 ( V_4 , V_16 ) ;
V_16 -> V_26 = V_10 -> V_27 ;
V_16 -> V_28 = V_10 -> V_29 ;
V_16 -> V_30 = V_10 -> V_31 ;
V_16 -> V_32 = V_10 -> V_33 ;
V_16 -> V_34 = V_10 -> V_35 ;
V_16 -> V_36 = V_10 -> V_37 ;
V_16 -> V_38 = V_10 -> V_39 ;
V_16 -> V_40 = V_10 -> V_41 ;
V_16 -> V_42 = V_10 -> V_43 ;
V_16 -> V_44 = V_10 -> V_45 ;
V_20 = ( V_16 -> V_40 << 3 ) | ( V_16 -> V_42 << 2 ) |
( V_16 -> V_44 << 1 ) | V_16 -> V_38 ;
if ( V_20 ) {
if ( V_16 -> V_40 )
V_21 |= F_1 ( V_16 -> V_26 ) >> 6 ;
if ( V_16 -> V_42 || V_16 -> V_44 )
V_21 |= F_1 ( V_16 -> V_28 ) >> 4 ;
F_8 ( V_6 , V_46 , V_21 | V_20 ) ;
}
V_21 &= 0x00 ;
V_21 |= F_1 ( V_16 -> V_30 ) >> 6 ;
V_21 |= F_1 ( V_16 -> V_32 ) >> 4 ;
V_21 |= F_1 ( V_16 -> V_34 ) >> 2 ;
V_21 |= F_1 ( V_16 -> V_36 ) ;
F_8 ( V_6 , V_47 , V_21 ) ;
for ( V_17 = 0 ; V_17 < V_25 ; V_17 ++ ) {
V_12 . V_7 = & V_4 -> V_7 ;
V_12 . V_48 = V_6 -> V_48 ;
V_12 . V_49 = V_10 -> V_50 [ V_17 ] . V_51 ;
V_12 . V_52 = V_16 ;
V_14 [ V_17 ] = F_9 ( & V_50 [ V_17 ] , & V_12 ) ;
if ( F_10 ( V_14 [ V_17 ] ) ) {
V_18 = F_11 ( V_14 [ V_17 ] ) ;
F_5 ( & V_4 -> V_7 , L_2 ,
V_17 ) ;
V_14 [ V_17 ] = NULL ;
goto V_53;
}
}
return 0 ;
V_53:
for ( V_17 = 0 ; V_17 < V_25 ; V_17 ++ )
if ( V_14 [ V_17 ] )
F_12 ( V_14 [ V_17 ] ) ;
return V_18 ;
}
static int T_2 F_13 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_14 ( V_4 ) ;
struct V_13 * * V_14 = V_16 -> V_14 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_25 ; V_17 ++ )
if ( V_14 [ V_17 ] )
F_12 ( V_14 [ V_17 ] ) ;
return 0 ;
}
static int T_3 F_15 ( void )
{
return F_16 ( & V_54 ) ;
}
static void T_4 F_17 ( void )
{
F_18 ( & V_54 ) ;
}
