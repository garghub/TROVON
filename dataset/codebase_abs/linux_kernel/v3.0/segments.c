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
if ( ( V_7 -> V_11 . V_12 [ V_10 ] . V_13 & 0x00006000 ) == 0 )
V_7 -> V_11 . V_12 [ V_10 ] . V_13 |= ( V_14 << 13 ) ;
V_7 -> V_11 . V_12 [ V_10 ] . V_13 |= 0x00000100 ;
}
}
void F_3 ( struct V_15 * V_16 )
{
struct V_17 * V_12 = V_16 -> V_18 ;
unsigned long V_19 = ( unsigned long ) & V_16 -> V_20 ;
V_12 [ V_3 ] = V_21 ;
V_12 [ V_4 ] = V_22 ;
V_12 [ V_2 ] . V_23 = 0x00000067 | ( V_19 << 16 ) ;
V_12 [ V_2 ] . V_13 = 0x00008900 | ( V_19 & 0xFF000000 )
| ( ( V_19 >> 16 ) & 0x000000FF ) ;
}
void F_4 ( struct V_6 * V_7 )
{
V_7 -> V_11 . V_12 [ V_24 ] = V_21 ;
V_7 -> V_11 . V_12 [ V_25 ] = V_22 ;
V_7 -> V_11 . V_12 [ V_24 ] . V_13 |= ( V_14 << 13 ) ;
V_7 -> V_11 . V_12 [ V_25 ] . V_13 |= ( V_14 << 13 ) ;
}
void F_5 ( const struct V_6 * V_7 , struct V_17 * V_12 )
{
unsigned int V_10 ;
for ( V_10 = V_26 ; V_10 <= V_27 ; V_10 ++ )
V_12 [ V_10 ] = V_7 -> V_11 . V_12 [ V_10 ] ;
}
void F_6 ( const struct V_6 * V_7 , struct V_17 * V_12 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_28 ; V_10 ++ )
if ( ! F_1 ( V_10 ) )
V_12 [ V_10 ] = V_7 -> V_11 . V_12 [ V_10 ] ;
}
void F_7 ( struct V_6 * V_7 , T_1 V_1 , T_1 V_29 , T_1 V_30 )
{
if ( V_1 >= F_8 ( V_7 -> V_11 . V_12 ) ) {
F_9 ( V_7 , L_1 , V_1 ) ;
return;
}
V_7 -> V_11 . V_12 [ V_1 ] . V_23 = V_29 ;
V_7 -> V_11 . V_12 [ V_1 ] . V_13 = V_30 ;
F_2 ( V_7 , V_1 , V_1 + 1 ) ;
V_7 -> V_31 |= V_32 ;
}
void F_10 ( struct V_6 * V_7 , unsigned long V_33 )
{
struct V_17 * V_34 = & V_7 -> V_11 . V_12 [ V_26 ] ;
F_11 ( V_7 , V_34 , V_33 , sizeof( * V_34 ) * V_35 ) ;
F_2 ( V_7 , V_26 , V_27 + 1 ) ;
V_7 -> V_31 |= V_36 ;
}
