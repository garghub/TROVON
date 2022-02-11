void F_1 ( void )
{
static int V_1 = 1 ;
int V_2 ;
if ( V_1 ) {
V_1 = 0 ;
F_2 ( L_1 ) ;
}
V_3 -> V_4 . V_5 . V_6 = 0 ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ ) {
V_3 -> V_4 . V_5 . V_7 [ V_2 ] = V_8 ;
}
}
int F_3 ( struct V_9 T_1 * V_10 )
{
int V_2 ;
int V_11 = 0 ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ ) {
V_11 |=
F_4 ( V_3 -> V_4 . V_5 . V_7 [ V_2 ] , & V_10 -> V_12 [ V_2 ] ) ;
}
V_11 |= F_4 ( V_3 -> V_4 . V_5 . V_6 , & V_10 -> V_13 ) ;
return V_11 ;
}
int F_5 ( struct V_9 T_1 * V_10 )
{
int V_2 ;
int V_11 = 0 ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ ) {
V_11 |=
F_6 ( V_3 -> V_4 . V_5 . V_7 [ V_2 ] , & V_10 -> V_12 [ V_2 ] ) ;
}
V_11 |= F_6 ( V_3 -> V_4 . V_5 . V_6 , & V_10 -> V_13 ) ;
return V_11 ;
}
int F_7 ( struct V_14 T_1 * V_10 )
{
int V_2 ;
int V_11 = 0 ;
int V_15 = F_8 ( V_16 ) ? 2 : 1 ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 += V_15 ) {
V_11 |=
F_4 ( V_3 -> V_4 . V_5 . V_7 [ V_2 ] , & V_10 -> V_12 [ V_2 ] ) ;
}
V_11 |= F_4 ( V_3 -> V_4 . V_5 . V_6 , & V_10 -> V_13 ) ;
return V_11 ;
}
int F_9 ( struct V_14 T_1 * V_10 )
{
int V_2 ;
int V_11 = 0 ;
int V_15 = F_8 ( V_16 ) ? 2 : 1 ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 += V_15 ) {
V_11 |=
F_6 ( V_3 -> V_4 . V_5 . V_7 [ V_2 ] , & V_10 -> V_12 [ V_2 ] ) ;
}
V_11 |= F_6 ( V_3 -> V_4 . V_5 . V_6 , & V_10 -> V_13 ) ;
return V_11 ;
}
