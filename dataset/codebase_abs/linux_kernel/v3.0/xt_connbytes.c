static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 ;
enum V_10 V_11 ;
T_1 V_12 = 0 ;
T_1 V_13 = 0 ;
T_1 V_14 = 0 ;
const struct V_15 * V_16 ;
V_9 = F_2 ( V_2 , & V_11 ) ;
if ( ! V_9 )
return false ;
V_16 = F_3 ( V_9 ) ;
if ( ! V_16 )
return false ;
switch ( V_6 -> V_12 ) {
case V_17 :
switch ( V_6 -> V_18 ) {
case V_19 :
V_12 = V_16 [ V_20 ] . V_21 ;
break;
case V_22 :
V_12 = V_16 [ V_23 ] . V_21 ;
break;
case V_24 :
V_12 = V_16 [ V_20 ] . V_21 ;
V_12 += V_16 [ V_23 ] . V_21 ;
break;
}
break;
case V_25 :
switch ( V_6 -> V_18 ) {
case V_19 :
V_12 = V_16 [ V_20 ] . V_13 ;
break;
case V_22 :
V_12 = V_16 [ V_23 ] . V_13 ;
break;
case V_24 :
V_12 = V_16 [ V_20 ] . V_13 ;
V_12 += V_16 [ V_23 ] . V_13 ;
break;
}
break;
case V_26 :
switch ( V_6 -> V_18 ) {
case V_19 :
V_13 = V_16 [ V_20 ] . V_13 ;
V_14 = V_16 [ V_20 ] . V_21 ;
break;
case V_22 :
V_13 = V_16 [ V_23 ] . V_13 ;
V_14 = V_16 [ V_23 ] . V_21 ;
break;
case V_24 :
V_13 = V_16 [ V_20 ] . V_13 +
V_16 [ V_23 ] . V_13 ;
V_14 = V_16 [ V_20 ] . V_21 +
V_16 [ V_23 ] . V_21 ;
break;
}
if ( V_14 != 0 )
V_12 = F_4 ( V_13 , V_14 ) ;
break;
}
if ( V_6 -> V_27 . V_28 )
return V_12 <= V_6 -> V_27 . V_28 && V_12 >= V_6 -> V_27 . V_29 ;
else
return V_12 >= V_6 -> V_27 . V_29 ;
}
static int F_5 ( const struct V_30 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
int V_31 ;
if ( V_6 -> V_12 != V_17 &&
V_6 -> V_12 != V_25 &&
V_6 -> V_12 != V_26 )
return - V_32 ;
if ( V_6 -> V_18 != V_19 &&
V_6 -> V_18 != V_22 &&
V_6 -> V_18 != V_24 )
return - V_32 ;
V_31 = F_6 ( V_4 -> V_33 ) ;
if ( V_31 < 0 )
F_7 ( L_1 ,
V_4 -> V_33 ) ;
if ( ! F_8 ( V_4 -> V_34 ) ) {
F_9 ( L_2 ) ;
F_10 ( V_4 -> V_34 , true ) ;
}
return V_31 ;
}
static void F_11 ( const struct V_35 * V_4 )
{
F_12 ( V_4 -> V_33 ) ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_36 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_36 ) ;
}
