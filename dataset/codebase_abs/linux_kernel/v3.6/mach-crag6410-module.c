static T_1 int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 , V_6 , V_7 , V_8 , V_9 ;
V_5 = F_2 ( V_2 , 0 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_10 , L_1 , V_5 ) ;
return V_5 ;
}
V_8 = ( V_5 & 0xfe ) >> 2 ;
V_9 = V_5 & 0x3 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_11 ) ; V_6 ++ )
if ( V_8 == V_11 [ V_6 ] . V_8 )
break;
if ( V_6 < F_4 ( V_11 ) ) {
F_5 ( & V_2 -> V_10 , L_2 ,
V_11 [ V_6 ] . V_12 , V_9 + 1 ) ;
for ( V_7 = 0 ; V_7 < V_11 [ V_6 ] . V_13 ; V_7 ++ ) {
if ( ! F_6 ( V_2 -> V_14 ,
& ( V_11 [ V_6 ] . V_15 [ V_7 ] ) ) )
F_3 ( & V_2 -> V_10 ,
L_3 , V_5 ) ;
}
F_7 ( V_11 [ V_6 ] . V_16 ,
V_11 [ V_6 ] . V_17 ) ;
} else {
F_8 ( & V_2 -> V_10 , L_4 ,
V_8 , V_9 + 1 ) ;
}
return 0 ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_18 ) ;
}
