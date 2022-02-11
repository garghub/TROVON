static inline bool F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_11 ;
if ( F_1 ( V_8 -> V_1 ) &&
F_3 ( V_10 -> V_12 , L_1 ) ) {
V_13 [ V_8 -> V_1 ] . V_8 . V_14 =
V_15 ;
V_13 [ V_8 -> V_1 ] . V_8 . V_16 =
F_4 ( V_15 ) ;
}
if ( V_8 -> V_1 <= V_4 && F_3 ( V_10 -> V_12 , L_2 ) ) {
V_11 = F_5 ( V_10 -> V_17 ,
V_13 [ V_8 -> V_1 ] . V_18 ,
V_13 [ V_8 -> V_1 ] . V_19 ,
V_13 [ V_8 -> V_1 ] . V_19 ) ;
if ( V_11 ) {
F_6 ( V_10 -> V_6 , L_3 ) ;
return V_11 ;
}
}
return 0 ;
}
static int F_7 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_8 ( V_21 -> V_6 . V_24 ) ;
struct V_9 V_10 = { } ;
struct V_25 * V_26 ;
int V_27 ;
F_9 ( V_21 , V_23 ) ;
V_10 . V_6 = & V_21 -> V_6 ;
V_10 . V_6 -> V_12 = V_23 -> V_6 -> V_12 ;
V_10 . V_28 = V_23 ;
V_10 . V_17 = V_23 -> V_17 ;
for ( V_27 = 0 ; V_27 < F_4 ( V_13 ) ; V_27 ++ ) {
V_26 = F_10 ( & V_21 -> V_6 , & V_13 [ V_27 ] . V_8 ,
& V_10 ) ;
if ( F_11 ( V_26 ) ) {
F_6 ( V_23 -> V_6 , L_4 ,
V_21 -> V_29 ) ;
return F_12 ( V_26 ) ;
}
}
return 0 ;
}
