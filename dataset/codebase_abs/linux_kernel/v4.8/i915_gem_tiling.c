static bool
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
int V_6 ;
if ( V_5 == V_7 )
return true ;
if ( F_2 ( V_2 ) ||
( V_5 == V_8 && F_3 ( V_2 ) ) )
V_6 = 128 ;
else
V_6 = 512 ;
if ( F_4 ( V_2 ) -> V_9 >= 7 ) {
if ( V_3 / 128 > V_10 )
return false ;
} else if ( F_4 ( V_2 ) -> V_9 >= 4 ) {
if ( V_3 / 128 > V_11 )
return false ;
} else {
if ( V_3 > 8192 )
return false ;
if ( F_5 ( V_2 ) ) {
if ( V_4 > V_12 << 20 )
return false ;
} else {
if ( V_4 > V_12 << 19 )
return false ;
}
}
if ( V_3 < V_6 )
return false ;
if ( F_4 ( V_2 ) -> V_9 >= 4 ) {
if ( V_3 & ( V_6 - 1 ) )
return false ;
return true ;
}
if ( V_3 & ( V_3 - 1 ) )
return false ;
return true ;
}
static bool
F_6 ( struct V_13 * V_14 , int V_5 )
{
T_1 V_4 ;
if ( V_5 == V_7 )
return true ;
if ( F_4 ( V_14 -> V_15 . V_2 ) -> V_9 >= 4 )
return true ;
if ( F_5 ( V_14 -> V_15 . V_2 ) ) {
if ( F_7 ( V_14 ) & ~ V_16 )
return false ;
} else {
if ( F_7 ( V_14 ) & ~ V_17 )
return false ;
}
V_4 = F_8 ( V_14 -> V_15 . V_2 , V_14 -> V_15 . V_4 , V_5 ) ;
if ( F_9 ( V_14 ) != V_4 )
return false ;
if ( F_7 ( V_14 ) & ( V_4 - 1 ) )
return false ;
return true ;
}
int
F_10 ( struct V_1 * V_2 , void * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * args = V_18 ;
struct V_22 * V_23 = F_11 ( V_2 ) ;
struct V_13 * V_14 ;
int V_24 = 0 ;
V_14 = F_12 ( F_13 ( V_20 , args -> V_25 ) ) ;
if ( & V_14 -> V_15 == NULL )
return - V_26 ;
if ( ! F_1 ( V_2 ,
args -> V_3 , V_14 -> V_15 . V_4 , args -> V_5 ) ) {
F_14 ( & V_14 -> V_15 ) ;
return - V_27 ;
}
F_15 ( V_23 ) ;
F_16 ( & V_2 -> V_28 ) ;
if ( V_14 -> V_29 || V_14 -> V_30 ) {
V_24 = - V_31 ;
goto V_32;
}
if ( args -> V_5 == V_7 ) {
args -> V_33 = V_34 ;
args -> V_3 = 0 ;
} else {
if ( args -> V_5 == V_35 )
args -> V_33 = V_23 -> V_36 . V_37 ;
else
args -> V_33 = V_23 -> V_36 . V_38 ;
if ( args -> V_33 == V_39 )
args -> V_33 = V_40 ;
if ( args -> V_33 == V_41 )
args -> V_33 = V_42 ;
if ( args -> V_33 == V_43 ) {
args -> V_5 = V_7 ;
args -> V_33 = V_34 ;
args -> V_3 = 0 ;
}
}
if ( args -> V_5 != V_14 -> V_5 ||
args -> V_3 != V_14 -> V_3 ) {
if ( V_14 -> V_44 &&
! F_6 ( V_14 , args -> V_5 ) )
V_24 = F_17 ( F_18 ( V_14 ) ) ;
if ( V_24 == 0 ) {
if ( V_14 -> V_45 &&
V_14 -> V_46 == V_47 &&
V_23 -> V_48 & V_49 ) {
if ( args -> V_5 == V_7 )
F_19 ( V_14 ) ;
if ( V_14 -> V_5 == V_7 )
F_20 ( V_14 ) ;
}
V_14 -> V_50 =
V_14 -> V_51 ||
V_14 -> V_52 != V_53 ;
V_14 -> V_5 = args -> V_5 ;
V_14 -> V_3 = args -> V_3 ;
F_21 ( V_14 ) ;
}
}
args -> V_3 = V_14 -> V_3 ;
args -> V_5 = V_14 -> V_5 ;
if ( F_22 ( V_14 ) ) {
if ( V_14 -> V_54 == NULL ) {
V_14 -> V_54 = F_23 ( F_24 ( V_14 -> V_15 . V_4 >> V_55 ) ,
sizeof( long ) , V_56 ) ;
}
} else {
F_25 ( V_14 -> V_54 ) ;
V_14 -> V_54 = NULL ;
}
V_32:
F_26 ( & V_14 -> V_15 ) ;
F_27 ( & V_2 -> V_28 ) ;
F_28 ( V_23 ) ;
return V_24 ;
}
int
F_29 ( struct V_1 * V_2 , void * V_18 ,
struct V_19 * V_20 )
{
struct V_57 * args = V_18 ;
struct V_22 * V_23 = F_11 ( V_2 ) ;
struct V_13 * V_14 ;
V_14 = F_12 ( F_13 ( V_20 , args -> V_25 ) ) ;
if ( & V_14 -> V_15 == NULL )
return - V_26 ;
F_16 ( & V_2 -> V_28 ) ;
args -> V_5 = V_14 -> V_5 ;
switch ( V_14 -> V_5 ) {
case V_35 :
args -> V_33 = V_23 -> V_36 . V_37 ;
break;
case V_8 :
args -> V_33 = V_23 -> V_36 . V_38 ;
break;
case V_7 :
args -> V_33 = V_34 ;
break;
default:
F_30 ( L_1 ) ;
}
if ( V_23 -> V_48 & V_49 )
args -> V_58 = V_43 ;
else
args -> V_58 = args -> V_33 ;
if ( args -> V_33 == V_39 )
args -> V_33 = V_40 ;
if ( args -> V_33 == V_41 )
args -> V_33 = V_42 ;
F_26 ( & V_14 -> V_15 ) ;
F_27 ( & V_2 -> V_28 ) ;
return 0 ;
}
