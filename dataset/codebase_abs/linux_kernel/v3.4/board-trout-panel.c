static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
T_2 V_7 = V_4 [ V_6 ] . V_7 ;
T_2 V_8 = V_4 [ V_6 ] . V_8 ;
if ( V_7 == 0 )
F_2 ( V_8 ) ;
else if ( V_7 == 1 )
F_3 ( V_8 ) ;
else
V_2 -> V_9 ( V_2 , V_8 , V_7 ) ;
}
}
static int F_4 (
struct V_10 * V_11 ,
struct V_1 * V_2 )
{
int V_12 ;
V_2 -> V_13 ( V_2 , 0 ) ;
F_1 ( V_2 , V_14 ,
F_5 ( V_14 ) ) ;
V_2 -> V_13 ( V_2 , 1 ) ;
V_12 = ( V_2 -> V_15 ( V_2 , V_16 ) >> 4 ) & 3 ;
if ( V_12 > 1 ) {
F_6 ( V_17 L_1 ) ;
return - 1 ;
}
return 0 ;
}
static int F_7 (
struct V_10 * V_11 ,
struct V_1 * V_2 )
{
return 0 ;
}
int T_3 F_8 ( void )
{
int V_18 ;
if ( ! F_9 () )
return 0 ;
V_19 = F_10 ( 0 , L_2 ) ;
if ( F_11 ( V_19 ) )
return F_12 ( V_19 ) ;
V_20 = F_10 ( 0 , L_3 ) ;
if ( F_11 ( V_20 ) )
return F_12 ( V_20 ) ;
V_21 = V_22 >= 5 ;
if ( V_21 ) {
T_2 V_23 = F_13 ( 27 , 0 , V_24 ,
V_25 , V_26 ) ;
F_14 ( V_27 , & V_23 , 0 ) ;
} else {
T_2 V_23 = F_13 ( 27 , 1 , V_24 ,
V_25 , V_26 ) ;
F_14 ( V_27 , & V_23 , 0 ) ;
V_28 = F_15 ( NULL , L_4 ) ;
if ( F_11 ( V_28 ) ) {
F_6 ( V_29 L_5
L_6 ) ;
V_28 = NULL ;
}
V_18 = F_16 ( V_28 , 19200000 ) ;
if ( V_18 )
F_6 ( V_29 L_7
L_8 ) ;
}
V_18 = F_17 ( & V_30 ) ;
if ( V_18 )
return V_18 ;
V_31 . V_32 . V_33 = & V_34 ;
return F_17 ( & V_31 ) ;
}
