static void F_1 ( int V_1 , int V_2 )
{
struct V_3 * V_4 = V_5 ;
while ( V_4 -> V_6 != 0 ) {
if ( V_2 == V_4 -> V_6 )
break;
V_4 ++ ;
}
if ( V_4 -> V_6 == 0 ) {
F_2 ( L_1 ,
V_7 , V_2 ) ;
}
if ( V_2 > V_1 ) {
V_8 |= V_9 ;
V_10 = V_4 -> V_11 ;
V_12 = V_4 -> V_13 ;
V_14 = V_4 -> V_15 ;
V_8 = V_4 -> V_16 ;
} else {
V_8 |= V_9 ;
V_14 = V_4 -> V_15 ;
V_12 = V_4 -> V_13 ;
V_10 = V_4 -> V_11 ;
V_8 = V_4 -> V_16 ;
}
}
static int F_3 ( struct V_17 * V_18 ,
unsigned int V_19 ,
unsigned int V_20 )
{
unsigned int V_21 = F_4 ( 0 ) ;
unsigned int V_22 ;
struct V_23 V_24 ;
V_22 = F_5 ( V_19 ) ;
switch ( V_20 ) {
case V_25 :
if ( F_6 ( V_22 ) > V_18 -> V_26 )
V_22 -- ;
break;
case V_27 :
if ( ( F_6 ( V_22 ) > V_19 ) &&
( F_6 ( V_22 - 1 ) >= V_18 -> V_28 ) )
V_22 -- ;
break;
}
V_24 . V_29 = V_21 ;
V_24 . V_30 = F_6 ( V_22 ) ;
V_24 . V_31 = 0 ;
F_7 ( & V_24 , V_32 ) ;
if ( V_24 . V_30 > V_21 )
F_1 ( V_21 , V_24 . V_30 ) ;
V_33 = V_22 ;
if ( V_24 . V_30 < V_21 )
F_1 ( V_21 , V_24 . V_30 ) ;
F_7 ( & V_24 , V_34 ) ;
return 0 ;
}
static int T_1 F_8 ( struct V_17 * V_18 )
{
if ( V_18 -> V_31 != 0 )
return - V_35 ;
V_18 -> V_21 = V_18 -> V_28 = V_18 -> V_26 = F_4 ( 0 ) ;
V_18 -> V_36 . V_37 = 59000 ;
V_18 -> V_36 . V_38 = 287000 ;
V_18 -> V_36 . V_39 = V_40 ;
return 0 ;
}
static int T_1 F_9 ( void )
{
if ( F_10 () )
return F_11 ( & V_41 ) ;
else
return - V_42 ;
}
