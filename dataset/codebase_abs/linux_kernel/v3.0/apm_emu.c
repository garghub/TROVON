static void F_1 ( struct V_1 * V_2 )
{
int V_3 = - 1 ;
int V_4 = 0 ;
int V_5 = - 1 ;
int V_6 = 0 ;
int V_7 ;
char V_8 = 0 ;
long V_9 = - 1 ;
long V_10 = 0 ;
unsigned long V_11 = 0 ;
V_2 -> V_12 = V_13 ;
V_2 -> V_14 = V_15 ;
V_2 -> V_16 = V_17 ;
if ( V_18 & V_19 )
V_2 -> V_20 = V_21 ;
else
V_2 -> V_20 = V_22 ;
for ( V_7 = 0 ; V_7 < V_23 ; V_7 ++ ) {
if ( V_24 [ V_7 ] . V_25 & V_26 ) {
V_4 ++ ;
if ( V_3 < 0 )
V_3 = 0 ;
if ( V_9 < 0 )
V_9 = 0 ;
V_3 += ( V_24 [ V_7 ] . V_9 * 100 ) /
V_24 [ V_7 ] . V_27 ;
V_9 += V_24 [ V_7 ] . V_9 ;
V_10 += V_24 [ V_7 ] . V_10 ;
if ( V_11 == 0 )
V_11 = ( V_24 [ V_7 ] . V_25 & V_28 ) ;
V_6 ++ ;
if ( ( V_24 [ V_7 ] . V_25 & V_29 ) )
V_8 ++ ;
}
}
if ( V_4 == 0 )
V_2 -> V_20 = V_21 ;
if ( V_6 ) {
if ( V_10 < 0 ) {
if ( V_11 == V_30 )
V_5 = ( V_9 * 59 ) / ( V_10 * - 1 ) ;
else
V_5 = ( V_9 * 16440 ) / ( V_10 * - 60 ) ;
}
V_3 /= V_6 ;
if ( V_8 > 0 ) {
V_2 -> V_12 = V_31 ;
V_2 -> V_14 = V_32 ;
} else if ( V_3 <= V_33 ) {
V_2 -> V_12 = V_34 ;
V_2 -> V_14 = V_35 ;
} else if ( V_3 <= V_36 ) {
V_2 -> V_12 = V_37 ;
V_2 -> V_14 = V_38 ;
} else {
V_2 -> V_12 = V_39 ;
V_2 -> V_14 = V_40 ;
}
}
V_2 -> V_41 = V_3 ;
V_2 -> time = V_5 ;
}
static int T_1 F_2 ( void )
{
V_42 = F_1 ;
F_3 ( V_43 L_1 ) ;
return 0 ;
}
static void T_2 F_4 ( void )
{
if ( V_42 == F_1 )
V_42 = NULL ;
F_3 ( V_43 L_2 ) ;
}
