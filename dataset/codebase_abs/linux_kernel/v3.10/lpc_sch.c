static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned int V_5 ;
unsigned short V_6 ;
int V_7 , V_8 = 0 ;
int V_9 ;
F_2 ( V_2 , V_10 , & V_5 ) ;
V_6 = 0 ;
if ( ! ( V_5 & ( 1 << 31 ) ) )
F_3 ( & V_2 -> V_2 , L_1 ) ;
else
V_6 = ( unsigned short ) V_5 ;
if ( V_6 == 0 ) {
F_3 ( & V_2 -> V_2 , L_2 ) ;
} else {
V_11 [ V_8 ++ ] = V_12 ;
V_13 . V_14 = V_6 ;
V_13 . V_15 = V_6 + V_16 - 1 ;
}
F_2 ( V_2 , V_17 , & V_5 ) ;
V_6 = 0 ;
if ( ! ( V_5 & ( 1 << 31 ) ) )
F_3 ( & V_2 -> V_2 , L_3 ) ;
else
V_6 = ( unsigned short ) V_5 ;
if ( V_6 == 0 ) {
F_3 ( & V_2 -> V_2 , L_4 ) ;
} else {
V_11 [ V_8 ++ ] = V_18 ;
V_19 . V_14 = V_6 ;
if ( V_4 -> V_20 == V_21 )
V_19 . V_15 = V_6 + V_22 - 1 ;
else
V_19 . V_15 = V_6 + V_23 - 1 ;
}
if ( V_4 -> V_20 == V_24
|| V_4 -> V_20 == V_21 ) {
F_2 ( V_2 , V_25 , & V_5 ) ;
V_6 = 0 ;
if ( ! ( V_5 & ( 1 << 31 ) ) )
F_3 ( & V_2 -> V_2 , L_5 ) ;
else
V_6 = ( unsigned short ) V_5 ;
if ( V_6 == 0 )
F_3 ( & V_2 -> V_2 , L_6 ) ;
else {
V_11 [ V_8 ++ ] = V_26 ;
V_27 . V_14 = V_6 ;
V_27 . V_15 = V_6 + V_28 - 1 ;
}
}
if ( F_4 ( V_8 > F_5 ( V_11 ) ) ) {
F_6 ( & V_2 -> V_2 , L_7 ) ;
return - V_29 ;
}
if ( V_8 == 0 ) {
F_6 ( & V_2 -> V_2 , L_8 ) ;
return - V_29 ;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
V_11 [ V_7 ] . V_4 = V_4 -> V_20 ;
V_9 = F_7 ( & V_2 -> V_2 , 0 , V_11 , V_8 , NULL , 0 , NULL ) ;
if ( V_9 )
F_8 ( & V_2 -> V_2 ) ;
return V_9 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_2 ) ;
}
