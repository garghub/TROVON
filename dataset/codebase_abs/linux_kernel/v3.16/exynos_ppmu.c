void F_1 ( void T_1 * V_1 )
{
F_2 ( V_2 | V_3 , V_1 ) ;
F_2 ( V_4 |
V_5 |
V_6 |
V_7 |
V_8 ,
V_1 + V_9 ) ;
}
void F_3 ( void T_1 * V_1 , unsigned int V_10 ,
unsigned int V_11 )
{
F_2 ( V_11 , V_1 + F_4 ( V_10 ) ) ;
}
void F_5 ( void T_1 * V_1 )
{
F_2 ( V_12 , V_1 ) ;
}
void F_6 ( void T_1 * V_1 )
{
F_2 ( V_13 , V_1 ) ;
}
unsigned int F_7 ( void T_1 * V_1 , unsigned int V_10 )
{
unsigned int V_14 ;
if ( V_10 == V_15 )
V_14 = ( ( F_8 ( V_1 + F_9 ( V_10 ) ) << 8 ) |
F_8 ( V_1 + F_9 ( V_10 + 1 ) ) ) ;
else
V_14 = F_8 ( V_1 + F_9 ( V_10 ) ) ;
return V_14 ;
}
void F_10 ( struct V_16 * V_17 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
void T_1 * V_1 = V_17 -> V_20 [ V_18 ] . V_21 ;
F_1 ( V_1 ) ;
V_17 -> V_20 [ V_18 ] . V_22 [ V_15 ] = V_23 ;
F_3 ( V_1 , V_15 ,
V_17 -> V_20 [ V_18 ] . V_22 [ V_15 ] ) ;
F_5 ( V_1 ) ;
}
}
void F_11 ( struct V_16 * V_17 )
{
int V_18 , V_24 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
void T_1 * V_1 = V_17 -> V_20 [ V_18 ] . V_21 ;
F_6 ( V_1 ) ;
V_17 -> V_20 [ V_18 ] . V_25 = F_8 ( V_1 + V_26 ) ;
for ( V_24 = V_27 ; V_24 < V_28 ; V_24 ++ ) {
if ( V_17 -> V_20 [ V_18 ] . V_22 [ V_24 ] == 0 )
V_17 -> V_20 [ V_18 ] . V_29 [ V_24 ] = 0 ;
else
V_17 -> V_20 [ V_18 ] . V_29 [ V_24 ] =
F_7 ( V_1 , V_24 ) ;
}
}
F_10 ( V_17 ) ;
}
int F_12 ( struct V_16 * V_17 )
{
unsigned int V_29 = 0 ;
int V_18 , V_24 , V_30 = 0 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
for ( V_24 = V_27 ; V_24 < V_28 ; V_24 ++ ) {
if ( V_17 -> V_20 [ V_18 ] . V_29 [ V_24 ] > V_29 ) {
V_29 = V_17 -> V_20 [ V_18 ] . V_29 [ V_24 ] ;
V_30 = V_18 ;
}
}
}
return V_30 ;
}
