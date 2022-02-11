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
static int F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_7 . V_8 ) ;
struct V_9 * V_10 = F_4 ( V_6 -> V_7 ) ;
struct V_11 V_12 = { } ;
struct V_13 * V_14 ;
int V_15 , V_16 ;
unsigned char V_17 , V_18 = 0 ;
if ( ! V_10 ) {
F_5 ( V_4 -> V_7 . V_8 , L_1 ) ;
return - V_19 ;
}
V_14 = F_6 ( & V_4 -> V_7 , sizeof( struct V_13 ) ,
V_20 ) ;
if ( ! V_14 )
return - V_21 ;
F_7 ( V_4 , V_14 ) ;
V_14 -> V_22 = V_10 -> V_23 ;
V_14 -> V_24 = V_10 -> V_25 ;
V_14 -> V_26 = V_10 -> V_27 ;
V_14 -> V_28 = V_10 -> V_29 ;
V_14 -> V_30 = V_10 -> V_31 ;
V_14 -> V_32 = V_10 -> V_33 ;
V_14 -> V_34 = V_10 -> V_35 ;
V_14 -> V_36 = V_10 -> V_37 ;
V_14 -> V_38 = V_10 -> V_39 ;
V_14 -> V_40 = V_10 -> V_41 ;
V_17 = ( V_14 -> V_36 << 3 ) | ( V_14 -> V_38 << 2 ) |
( V_14 -> V_40 << 1 ) | V_14 -> V_34 ;
if ( V_17 ) {
if ( V_14 -> V_36 )
V_18 |= F_1 ( V_14 -> V_22 ) << 6 ;
if ( V_14 -> V_38 || V_14 -> V_40 )
V_18 |= F_1 ( V_14 -> V_24 ) << 4 ;
F_8 ( V_6 , V_42 , V_18 | V_17 ) ;
}
V_18 &= 0x00 ;
V_18 |= F_1 ( V_14 -> V_26 ) << 6 ;
V_18 |= F_1 ( V_14 -> V_28 ) << 4 ;
V_18 |= F_1 ( V_14 -> V_30 ) << 2 ;
V_18 |= F_1 ( V_14 -> V_32 ) ;
F_8 ( V_6 , V_43 , V_18 ) ;
for ( V_15 = 0 ; V_15 < V_44 ; V_15 ++ ) {
V_12 . V_7 = & V_4 -> V_7 ;
V_12 . V_45 = V_6 -> V_45 ;
V_12 . V_46 = V_10 -> V_47 [ V_15 ] . V_48 ;
V_12 . V_49 = V_14 ;
V_14 -> V_50 [ V_15 ] = F_9 ( & V_47 [ V_15 ] , & V_12 ) ;
if ( F_10 ( V_14 -> V_50 [ V_15 ] ) ) {
V_16 = F_11 ( V_14 -> V_50 [ V_15 ] ) ;
F_5 ( & V_4 -> V_7 , L_2 ,
V_15 ) ;
V_14 -> V_50 [ V_15 ] = NULL ;
goto V_51;
}
}
return 0 ;
V_51:
for ( V_15 = 0 ; V_15 < V_44 ; V_15 ++ )
F_12 ( V_14 -> V_50 [ V_15 ] ) ;
return V_16 ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_14 ( V_4 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_44 ; V_15 ++ )
F_12 ( V_14 -> V_50 [ V_15 ] ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_52 ) ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_52 ) ;
}
