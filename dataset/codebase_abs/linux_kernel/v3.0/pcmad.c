static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 ;
int V_10 ;
int V_11 ;
V_10 = F_6 ( V_7 -> V_12 ) ;
for ( V_11 = 0 ; V_11 < V_7 -> V_11 ; V_11 ++ ) {
F_7 ( V_10 , V_3 -> V_13 + V_14 ) ;
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ ) {
if ( ( F_8 ( V_3 -> V_13 + V_16 ) & 0x3 ) == 0x3 )
break;
}
V_8 [ V_11 ] = F_8 ( V_3 -> V_13 + V_17 ) ;
V_8 [ V_11 ] |= ( F_8 ( V_3 -> V_13 + V_18 ) << 8 ) ;
if ( V_19 -> V_20 )
V_8 [ V_11 ] ^= ( 1 << ( V_21 -> V_22 - 1 ) ) ;
}
return V_11 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
int V_25 ;
struct V_4 * V_5 ;
unsigned long V_13 ;
V_13 = V_24 -> V_26 [ 0 ] ;
F_10 ( V_27 L_1 , V_3 -> V_28 , V_13 ) ;
if ( ! F_11 ( V_13 , V_29 , L_2 ) ) {
F_10 ( V_30 L_3 ) ;
return - V_31 ;
}
F_10 ( V_30 L_4 ) ;
V_3 -> V_13 = V_13 ;
V_25 = F_12 ( V_3 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_13 ( V_3 , sizeof( struct V_32 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_3 -> V_33 = V_21 -> V_34 ;
V_5 = V_3 -> V_35 + 0 ;
V_5 -> type = V_36 ;
V_5 -> V_37 = V_38 | V_39 ;
V_5 -> V_40 = 16 ;
V_5 -> V_41 = 1 ;
V_5 -> V_42 = F_5 ;
V_5 -> V_43 = ( 1 << V_21 -> V_22 ) - 1 ;
V_5 -> V_44 = & V_45 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
F_10 ( V_27 L_5 , V_3 -> V_28 ) ;
if ( V_3 -> V_46 )
F_15 ( V_3 -> V_46 , V_3 ) ;
if ( V_3 -> V_13 )
F_16 ( V_3 -> V_13 , V_29 ) ;
return 0 ;
}
