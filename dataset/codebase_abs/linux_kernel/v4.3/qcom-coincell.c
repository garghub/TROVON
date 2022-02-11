static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 , bool V_5 )
{
int V_6 , V_7 , V_8 ;
if ( ! V_5 )
return F_2 ( V_2 -> V_9 ,
V_2 -> V_10 + V_11 , 0 ) ;
for ( V_6 = 0 ; V_6 < F_3 ( V_12 ) ; V_6 ++ )
if ( V_3 == V_12 [ V_6 ] )
break;
if ( V_6 >= F_3 ( V_12 ) ) {
F_4 ( V_2 -> V_13 , L_1 , V_3 ) ;
return - V_14 ;
}
for ( V_7 = 0 ; V_7 < F_3 ( V_15 ) ; V_7 ++ )
if ( V_4 == V_15 [ V_7 ] )
break;
if ( V_7 >= F_3 ( V_15 ) ) {
F_4 ( V_2 -> V_13 , L_2 , V_4 ) ;
return - V_14 ;
}
V_8 = F_2 ( V_2 -> V_9 ,
V_2 -> V_10 + V_16 , V_6 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_13 , L_3 ) ;
return V_8 ;
}
V_8 = F_2 ( V_2 -> V_9 ,
V_2 -> V_10 + V_17 , V_7 ) ;
if ( V_8 )
return V_8 ;
return F_2 ( V_2 -> V_9 ,
V_2 -> V_10 + V_11 ,
V_18 ) ;
}
static int F_5 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_13 . V_23 ;
struct V_1 V_2 ;
T_1 V_3 , V_4 ;
bool V_5 ;
int V_8 ;
V_2 . V_13 = & V_20 -> V_13 ;
V_2 . V_9 = F_6 ( V_20 -> V_13 . V_24 , NULL ) ;
if ( ! V_2 . V_9 ) {
F_4 ( V_2 . V_13 , L_4 ) ;
return - V_14 ;
}
V_8 = F_7 ( V_22 , L_5 , & V_2 . V_10 ) ;
if ( V_8 )
return V_8 ;
V_5 = ! F_8 ( V_22 , L_6 ) ;
if ( V_5 ) {
V_8 = F_7 ( V_22 , L_7 , & V_3 ) ;
if ( V_8 ) {
F_4 ( V_2 . V_13 ,
L_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_22 , L_9 , & V_4 ) ;
if ( V_8 ) {
F_4 ( V_2 . V_13 ,
L_10 ) ;
return V_8 ;
}
}
return F_1 ( & V_2 , V_3 , V_4 , V_5 ) ;
}
