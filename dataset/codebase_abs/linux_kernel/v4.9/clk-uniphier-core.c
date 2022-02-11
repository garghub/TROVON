static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
const struct V_5 * V_6 )
{
switch ( V_6 -> type ) {
case V_7 :
return F_2 ( V_3 , V_6 -> V_8 ,
& V_6 -> V_6 . V_9 ) ;
case V_10 :
return F_3 ( V_3 , V_6 -> V_8 ,
& V_6 -> V_6 . V_11 ) ;
case V_12 :
return F_4 ( V_3 , V_4 , V_6 -> V_8 ,
& V_6 -> V_6 . V_13 ) ;
case V_14 :
return F_5 ( V_3 , V_4 , V_6 -> V_8 ,
& V_6 -> V_6 . V_15 ) ;
default:
F_6 ( V_3 , L_1 ) ;
return F_7 ( - V_16 ) ;
}
}
static int F_8 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = & V_18 -> V_3 ;
struct V_19 * V_20 ;
const struct V_5 * V_21 , * V_6 ;
struct V_4 * V_4 ;
struct V_22 * V_23 ;
int V_24 = 0 ;
V_6 = F_9 ( V_3 ) ;
if ( F_10 ( ! V_6 ) )
return - V_16 ;
V_23 = F_11 ( V_3 -> V_25 ) ;
V_4 = F_12 ( V_23 ) ;
F_13 ( V_23 ) ;
if ( F_14 ( V_4 ) ) {
F_6 ( V_3 , L_2 ,
F_15 ( V_4 ) ) ;
return F_15 ( V_4 ) ;
}
for ( V_21 = V_6 ; V_21 -> V_8 ; V_21 ++ )
V_24 = F_16 ( V_24 , V_21 -> V_26 + 1 ) ;
V_20 = F_17 ( V_3 ,
sizeof( * V_20 ) + V_24 * sizeof( struct V_1 * ) ,
V_27 ) ;
if ( ! V_20 )
return - V_28 ;
V_20 -> V_29 = V_24 ;
while ( -- V_24 >= 0 )
V_20 -> V_30 [ V_24 ] = F_7 ( - V_16 ) ;
for ( V_21 = V_6 ; V_21 -> V_8 ; V_21 ++ ) {
struct V_1 * V_31 ;
F_18 ( V_3 , L_3 , V_21 -> V_8 , V_21 -> V_26 ) ;
V_31 = F_1 ( V_3 , V_4 , V_21 ) ;
if ( F_14 ( V_31 ) ) {
F_6 ( V_3 , L_4 ,
V_21 -> V_8 , F_15 ( V_31 ) ) ;
return F_15 ( V_31 ) ;
}
if ( V_21 -> V_26 >= 0 )
V_20 -> V_30 [ V_21 -> V_26 ] = V_31 ;
}
return F_19 ( V_3 -> V_25 , V_32 ,
V_20 ) ;
}
static int F_20 ( struct V_17 * V_18 )
{
F_21 ( V_18 -> V_3 . V_25 ) ;
return 0 ;
}
