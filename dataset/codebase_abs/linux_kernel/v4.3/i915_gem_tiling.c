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
if ( F_4 ( V_14 -> V_15 . V_2 ) -> V_9 == 3 ) {
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
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_13 * V_14 ;
int V_25 = 0 ;
V_14 = F_11 ( F_12 ( V_2 , V_20 , args -> V_26 ) ) ;
if ( & V_14 -> V_15 == NULL )
return - V_27 ;
if ( ! F_1 ( V_2 ,
args -> V_3 , V_14 -> V_15 . V_4 , args -> V_5 ) ) {
F_13 ( & V_14 -> V_15 ) ;
return - V_28 ;
}
F_14 ( & V_2 -> V_29 ) ;
if ( V_14 -> V_30 || V_14 -> V_31 ) {
V_25 = - V_32 ;
goto V_33;
}
if ( args -> V_5 == V_7 ) {
args -> V_34 = V_35 ;
args -> V_3 = 0 ;
} else {
if ( args -> V_5 == V_36 )
args -> V_34 = V_23 -> V_37 . V_38 ;
else
args -> V_34 = V_23 -> V_37 . V_39 ;
if ( args -> V_34 == V_40 )
args -> V_34 = V_41 ;
if ( args -> V_34 == V_42 )
args -> V_34 = V_43 ;
if ( args -> V_34 == V_44 ) {
args -> V_5 = V_7 ;
args -> V_34 = V_35 ;
args -> V_3 = 0 ;
}
}
if ( args -> V_5 != V_14 -> V_5 ||
args -> V_3 != V_14 -> V_3 ) {
if ( V_14 -> V_45 &&
! F_6 ( V_14 , args -> V_5 ) )
V_25 = F_15 ( V_14 ) ;
if ( V_25 == 0 ) {
if ( V_14 -> V_46 &&
V_14 -> V_47 == V_48 &&
V_23 -> V_49 & V_50 ) {
if ( args -> V_5 == V_7 )
F_16 ( V_14 ) ;
if ( V_14 -> V_5 == V_7 )
F_17 ( V_14 ) ;
}
V_14 -> V_51 =
V_14 -> V_52 ||
V_14 -> V_53 != V_54 ;
V_14 -> V_5 = args -> V_5 ;
V_14 -> V_3 = args -> V_3 ;
F_18 ( V_14 ) ;
}
}
args -> V_3 = V_14 -> V_3 ;
args -> V_5 = V_14 -> V_5 ;
if ( F_19 ( V_14 ) ) {
if ( V_14 -> V_55 == NULL ) {
V_14 -> V_55 = F_20 ( F_21 ( V_14 -> V_15 . V_4 >> V_56 ) ,
sizeof( long ) , V_57 ) ;
}
} else {
F_22 ( V_14 -> V_55 ) ;
V_14 -> V_55 = NULL ;
}
V_33:
F_23 ( & V_14 -> V_15 ) ;
F_24 ( & V_2 -> V_29 ) ;
return V_25 ;
}
int
F_25 ( struct V_1 * V_2 , void * V_18 ,
struct V_19 * V_20 )
{
struct V_58 * args = V_18 ;
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_13 * V_14 ;
V_14 = F_11 ( F_12 ( V_2 , V_20 , args -> V_26 ) ) ;
if ( & V_14 -> V_15 == NULL )
return - V_27 ;
F_14 ( & V_2 -> V_29 ) ;
args -> V_5 = V_14 -> V_5 ;
switch ( V_14 -> V_5 ) {
case V_36 :
args -> V_34 = V_23 -> V_37 . V_38 ;
break;
case V_8 :
args -> V_34 = V_23 -> V_37 . V_39 ;
break;
case V_7 :
args -> V_34 = V_35 ;
break;
default:
F_26 ( L_1 ) ;
}
if ( V_23 -> V_49 & V_50 )
args -> V_59 = V_44 ;
else
args -> V_59 = args -> V_34 ;
if ( args -> V_34 == V_40 )
args -> V_34 = V_41 ;
if ( args -> V_34 == V_42 )
args -> V_34 = V_43 ;
F_23 ( & V_14 -> V_15 ) ;
F_24 ( & V_2 -> V_29 ) ;
return 0 ;
}
