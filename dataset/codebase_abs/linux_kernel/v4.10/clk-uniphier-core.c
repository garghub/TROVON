static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
const struct V_5 * V_6 )
{
switch ( V_6 -> type ) {
case V_7 :
return F_2 ( V_3 , V_4 , V_6 -> V_8 ,
& V_6 -> V_6 . V_9 ) ;
case V_10 :
return F_3 ( V_3 , V_6 -> V_8 ,
& V_6 -> V_6 . V_11 ) ;
case V_12 :
return F_4 ( V_3 , V_6 -> V_8 ,
& V_6 -> V_6 . V_13 ) ;
case V_14 :
return F_5 ( V_3 , V_4 , V_6 -> V_8 ,
& V_6 -> V_6 . V_15 ) ;
case V_16 :
return F_6 ( V_3 , V_4 , V_6 -> V_8 ,
& V_6 -> V_6 . V_17 ) ;
default:
F_7 ( V_3 , L_1 ) ;
return F_8 ( - V_18 ) ;
}
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = & V_20 -> V_3 ;
struct V_21 * V_22 ;
const struct V_5 * V_23 , * V_6 ;
struct V_4 * V_4 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
V_6 = F_10 ( V_3 ) ;
if ( F_11 ( ! V_6 ) )
return - V_18 ;
V_25 = F_12 ( V_3 -> V_27 ) ;
V_4 = F_13 ( V_25 ) ;
F_14 ( V_25 ) ;
if ( F_15 ( V_4 ) ) {
F_7 ( V_3 , L_2 ,
F_16 ( V_4 ) ) ;
return F_16 ( V_4 ) ;
}
for ( V_23 = V_6 ; V_23 -> V_8 ; V_23 ++ )
V_26 = F_17 ( V_26 , V_23 -> V_28 + 1 ) ;
V_22 = F_18 ( V_3 ,
sizeof( * V_22 ) + V_26 * sizeof( struct V_1 * ) ,
V_29 ) ;
if ( ! V_22 )
return - V_30 ;
V_22 -> V_31 = V_26 ;
while ( -- V_26 >= 0 )
V_22 -> V_32 [ V_26 ] = F_8 ( - V_18 ) ;
for ( V_23 = V_6 ; V_23 -> V_8 ; V_23 ++ ) {
struct V_1 * V_33 ;
F_19 ( V_3 , L_3 , V_23 -> V_8 , V_23 -> V_28 ) ;
V_33 = F_1 ( V_3 , V_4 , V_23 ) ;
if ( F_15 ( V_33 ) ) {
F_7 ( V_3 , L_4 ,
V_23 -> V_8 , F_16 ( V_33 ) ) ;
return F_16 ( V_33 ) ;
}
if ( V_23 -> V_28 >= 0 )
V_22 -> V_32 [ V_23 -> V_28 ] = V_33 ;
}
return F_20 ( V_3 -> V_27 , V_34 ,
V_22 ) ;
}
static int F_21 ( struct V_19 * V_20 )
{
F_22 ( V_20 -> V_3 . V_27 ) ;
return 0 ;
}
