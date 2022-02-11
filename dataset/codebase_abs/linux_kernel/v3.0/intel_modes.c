bool F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 . V_6 -> V_7 ;
T_1 V_8 [] = { 0x0 , 0x0 } ;
T_1 V_9 [ 2 ] ;
struct V_10 V_11 [] = {
{
. V_12 = 0x50 ,
. V_13 = 0 ,
. V_14 = 1 ,
. V_9 = V_8 ,
} ,
{
. V_12 = 0x50 ,
. V_13 = V_15 ,
. V_14 = 1 ,
. V_9 = V_9 ,
}
} ;
return F_2 ( & V_4 -> V_16 [ V_2 ] . V_17 , V_11 , 2 ) == 2 ;
}
int F_3 ( struct V_18 * V_19 ,
struct V_20 * V_17 )
{
struct V_21 * V_21 ;
int V_22 = 0 ;
V_21 = F_4 ( V_19 , V_17 ) ;
if ( V_21 ) {
F_5 ( V_19 , V_21 ) ;
V_22 = F_6 ( V_19 , V_21 ) ;
V_19 -> V_23 . V_24 = NULL ;
F_7 ( V_21 ) ;
}
return V_22 ;
}
void
F_8 ( struct V_18 * V_19 )
{
struct V_25 * V_6 = V_19 -> V_6 ;
struct V_3 * V_4 = V_6 -> V_7 ;
struct V_26 * V_27 ;
int V_28 ;
V_27 = V_4 -> V_29 ;
if ( V_27 == NULL ) {
V_27 = F_9 ( V_6 , V_30 ,
L_1 ,
F_10 ( V_31 ) ) ;
if ( V_27 == NULL )
return;
for ( V_28 = 0 ; V_28 < F_10 ( V_31 ) ; V_28 ++ )
F_11 ( V_27 , V_28 , V_28 - 1 , V_31 [ V_28 ] ) ;
V_4 -> V_29 = V_27 ;
}
F_12 ( V_19 , V_27 , 0 ) ;
}
void
F_13 ( struct V_18 * V_19 )
{
struct V_25 * V_6 = V_19 -> V_6 ;
struct V_3 * V_4 = V_6 -> V_7 ;
struct V_26 * V_27 ;
int V_28 ;
V_27 = V_4 -> V_32 ;
if ( V_27 == NULL ) {
V_27 = F_9 ( V_6 , V_30 ,
L_2 ,
F_10 ( V_33 ) ) ;
if ( V_27 == NULL )
return;
for ( V_28 = 0 ; V_28 < F_10 ( V_33 ) ; V_28 ++ )
F_11 ( V_27 , V_28 , V_28 , V_33 [ V_28 ] ) ;
V_4 -> V_32 = V_27 ;
}
F_12 ( V_19 , V_27 , 0 ) ;
}
