static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 ;
void T_1 * V_9 ;
T_2 V_10 ;
unsigned int V_11 , V_12 ;
unsigned int V_13 ;
int V_14 ;
V_8 = & V_15 [ V_4 -> V_16 ] ;
V_12 = V_8 -> V_17 ;
V_14 = F_2 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_8 = F_3 ( & V_2 -> V_18 , sizeof( struct V_7 ) +
sizeof( unsigned int ) * V_12 , V_19 ) ;
if ( ! V_8 )
return - V_20 ;
V_8 -> V_17 = V_12 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 . V_21 . V_18 = & V_2 -> V_18 ;
V_6 . V_21 . V_22 = V_2 -> V_22 ;
V_6 . V_21 . V_23 = V_24 * 16 ;
V_6 . V_21 . V_25 = V_26 | V_27 | V_28 ;
V_10 = F_4 ( V_2 , V_29 ) ;
V_9 = F_5 ( V_2 , V_29 , 0 ) ;
if ( ! V_9 )
return - V_20 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
if ( V_12 == 4 && V_11 == 3 )
V_13 = 7 * V_30 ;
else
V_13 = V_11 * V_30 ;
V_6 . V_21 . V_31 = V_32 ;
V_6 . V_21 . V_33 = 0 ;
V_6 . V_21 . V_34 = V_10 + V_13 ;
V_6 . V_21 . V_35 = V_9 + V_13 ;
V_6 . V_21 . V_36 = 0 ;
F_6 ( & V_2 -> V_18 , L_1 ,
V_6 . V_21 . V_33 , V_6 . V_21 . V_22 , V_6 . V_21 . V_31 ) ;
V_8 -> line [ V_11 ] = F_7 ( & V_6 ) ;
if ( V_8 -> line [ V_11 ] < 0 ) {
F_8 ( & V_2 -> V_18 ,
L_2 ,
V_6 . V_21 . V_33 , V_6 . V_21 . V_22 ,
V_6 . V_21 . V_31 , V_8 -> line [ V_11 ] ) ;
break;
}
}
F_9 ( V_2 , V_8 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_11 ( V_2 ) ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_17 ; V_11 ++ )
F_12 ( V_8 -> line [ V_11 ] ) ;
}
