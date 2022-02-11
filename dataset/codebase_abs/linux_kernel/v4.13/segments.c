static bool F_1 ( unsigned int V_1 )
{
return ( V_1 == V_2
|| V_1 == V_3
|| V_1 == V_4
|| V_1 == V_5 ) ;
}
static void F_2 ( struct V_6 * V_7 , unsigned V_8 , unsigned V_9 )
{
unsigned int V_10 ;
for ( V_10 = V_8 ; V_10 < V_9 ; V_10 ++ ) {
if ( F_1 ( V_10 ) )
continue;
if ( V_7 -> V_11 . V_12 [ V_10 ] . V_13 == 0 )
V_7 -> V_11 . V_12 [ V_10 ] . V_13 |= V_14 ;
V_7 -> V_11 . V_12 [ V_10 ] . type |= 0x1 ;
}
}
void F_3 ( struct V_15 * V_16 )
{
struct V_17 * V_12 = V_16 -> V_18 ;
unsigned long V_19 = ( unsigned long ) & V_16 -> V_20 ;
V_12 [ V_3 ] = V_21 ;
V_12 [ V_4 ] = V_22 ;
V_12 [ V_2 ] . V_23 = 0 ;
V_12 [ V_2 ] . V_24 = 0 ;
V_12 [ V_2 ] . V_25 = 0x67 ;
V_12 [ V_2 ] . V_26 = V_19 & 0xFFFF ;
V_12 [ V_2 ] . V_27 = ( V_19 >> 16 ) & 0xFF ;
V_12 [ V_2 ] . V_28 = V_19 >> 24 ;
V_12 [ V_2 ] . type = 0x9 ;
V_12 [ V_2 ] . V_29 = 0x1 ;
V_12 [ V_2 ] . V_13 = 0x0 ;
V_12 [ V_2 ] . V_30 = 0x0 ;
}
void F_4 ( struct V_6 * V_7 )
{
V_7 -> V_11 . V_12 [ V_31 ] = V_21 ;
V_7 -> V_11 . V_12 [ V_32 ] = V_22 ;
V_7 -> V_11 . V_12 [ V_31 ] . V_13 |= V_14 ;
V_7 -> V_11 . V_12 [ V_32 ] . V_13 |= V_14 ;
}
void F_5 ( const struct V_6 * V_7 , struct V_17 * V_12 )
{
unsigned int V_10 ;
for ( V_10 = V_33 ; V_10 <= V_34 ; V_10 ++ )
V_12 [ V_10 ] = V_7 -> V_11 . V_12 [ V_10 ] ;
}
void F_6 ( const struct V_6 * V_7 , struct V_17 * V_12 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_35 ; V_10 ++ )
if ( ! F_1 ( V_10 ) )
V_12 [ V_10 ] = V_7 -> V_11 . V_12 [ V_10 ] ;
}
void F_7 ( struct V_6 * V_7 , T_1 V_1 , T_1 V_36 , T_1 V_37 )
{
if ( V_1 >= F_8 ( V_7 -> V_11 . V_12 ) ) {
F_9 ( V_7 , L_1 , V_1 ) ;
return;
}
V_7 -> V_11 . V_12 [ V_1 ] . V_23 = V_36 ;
V_7 -> V_11 . V_12 [ V_1 ] . V_24 = V_37 ;
F_2 ( V_7 , V_1 , V_1 + 1 ) ;
V_7 -> V_38 |= V_39 ;
}
void F_10 ( struct V_6 * V_7 , unsigned long V_40 )
{
struct V_17 * V_41 = & V_7 -> V_11 . V_12 [ V_33 ] ;
F_11 ( V_7 , V_41 , V_40 , sizeof( * V_41 ) * V_42 ) ;
F_2 ( V_7 , V_33 , V_34 + 1 ) ;
V_7 -> V_38 |= V_43 ;
}
