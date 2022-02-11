static bool
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
int V_6 ;
if ( V_5 == V_7 )
return true ;
if ( V_5 > V_8 )
return false ;
if ( F_2 ( V_2 ) ||
( V_5 == V_9 && F_3 ( V_2 ) ) )
V_6 = 128 ;
else
V_6 = 512 ;
if ( F_4 ( V_2 ) -> V_10 >= 7 ) {
if ( V_3 / 128 > V_11 )
return false ;
} else if ( F_4 ( V_2 ) -> V_10 >= 4 ) {
if ( V_3 / 128 > V_12 )
return false ;
} else {
if ( V_3 > 8192 )
return false ;
if ( F_5 ( V_2 ) ) {
if ( V_4 > V_13 << 20 )
return false ;
} else {
if ( V_4 > V_13 << 19 )
return false ;
}
}
if ( V_3 < V_6 )
return false ;
if ( F_4 ( V_2 ) -> V_10 >= 4 ) {
if ( V_3 & ( V_6 - 1 ) )
return false ;
return true ;
}
if ( V_3 & ( V_3 - 1 ) )
return false ;
return true ;
}
static bool F_6 ( struct V_14 * V_15 , int V_5 )
{
struct V_16 * V_17 = F_7 ( V_15 -> V_18 -> V_2 ) ;
T_1 V_4 ;
if ( ! F_8 ( V_15 ) )
return true ;
if ( F_9 ( V_17 ) == 3 ) {
if ( V_15 -> V_19 . V_20 & ~ V_21 )
return false ;
} else {
if ( V_15 -> V_19 . V_20 & ~ V_22 )
return false ;
}
V_4 = F_10 ( V_17 , V_15 -> V_4 , V_5 ) ;
if ( V_15 -> V_19 . V_4 < V_4 )
return false ;
if ( V_15 -> V_19 . V_20 & ( V_4 - 1 ) )
return false ;
return true ;
}
static int
F_11 ( struct V_23 * V_24 , int V_5 )
{
struct V_16 * V_17 = F_7 ( V_24 -> V_25 . V_2 ) ;
struct V_14 * V_15 ;
int V_26 ;
if ( V_5 == V_7 )
return 0 ;
if ( F_9 ( V_17 ) >= 4 )
return 0 ;
F_12 (vma, &obj->vma_list, obj_link) {
if ( F_6 ( V_15 , V_5 ) )
continue;
V_26 = F_13 ( V_15 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
int
F_14 ( struct V_1 * V_2 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * args = V_27 ;
struct V_16 * V_17 = F_7 ( V_2 ) ;
struct V_23 * V_24 ;
int V_31 = 0 ;
F_15 ( V_8 & V_32 ) ;
V_24 = F_16 ( V_29 , args -> V_33 ) ;
if ( ! V_24 )
return - V_34 ;
if ( ! F_1 ( V_2 ,
args -> V_3 , V_24 -> V_25 . V_4 , args -> V_5 ) ) {
F_17 ( V_24 ) ;
return - V_35 ;
}
F_18 ( V_17 ) ;
F_19 ( & V_2 -> V_36 ) ;
if ( V_24 -> V_37 || V_24 -> V_38 ) {
V_31 = - V_39 ;
goto V_31;
}
if ( args -> V_5 == V_7 ) {
args -> V_40 = V_41 ;
args -> V_3 = 0 ;
} else {
if ( args -> V_5 == V_42 )
args -> V_40 = V_17 -> V_43 . V_44 ;
else
args -> V_40 = V_17 -> V_43 . V_45 ;
if ( args -> V_40 == V_46 )
args -> V_40 = V_47 ;
if ( args -> V_40 == V_48 )
args -> V_40 = V_49 ;
if ( args -> V_40 == V_50 ) {
args -> V_5 = V_7 ;
args -> V_40 = V_41 ;
args -> V_3 = 0 ;
}
}
if ( args -> V_5 != F_20 ( V_24 ) ||
args -> V_3 != F_21 ( V_24 ) ) {
V_31 = F_11 ( V_24 , args -> V_5 ) ;
if ( ! V_31 ) {
struct V_14 * V_15 ;
if ( V_24 -> V_51 &&
V_24 -> V_52 == V_53 &&
V_17 -> V_54 & V_55 ) {
if ( args -> V_5 == V_7 )
F_22 ( V_24 ) ;
if ( ! F_23 ( V_24 ) )
F_24 ( V_24 ) ;
}
F_12 (vma, &obj->vma_list, obj_link) {
if ( ! V_15 -> V_56 )
continue;
V_15 -> V_56 -> V_57 = true ;
}
V_24 -> V_58 =
args -> V_3 | args -> V_5 ;
F_25 ( V_24 ) ;
}
}
args -> V_3 = F_21 ( V_24 ) ;
args -> V_5 = F_20 ( V_24 ) ;
if ( F_26 ( V_24 ) ) {
if ( V_24 -> V_59 == NULL ) {
V_24 -> V_59 = F_27 ( F_28 ( V_24 -> V_25 . V_4 >> V_60 ) ,
sizeof( long ) , V_61 ) ;
}
} else {
F_29 ( V_24 -> V_59 ) ;
V_24 -> V_59 = NULL ;
}
V_31:
F_30 ( V_24 ) ;
F_31 ( & V_2 -> V_36 ) ;
F_32 ( V_17 ) ;
return V_31 ;
}
int
F_33 ( struct V_1 * V_2 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_62 * args = V_27 ;
struct V_16 * V_17 = F_7 ( V_2 ) ;
struct V_23 * V_24 ;
V_24 = F_16 ( V_29 , args -> V_33 ) ;
if ( ! V_24 )
return - V_34 ;
args -> V_5 = F_34 ( V_24 -> V_58 ) & V_63 ;
switch ( args -> V_5 ) {
case V_42 :
args -> V_40 = V_17 -> V_43 . V_44 ;
break;
case V_9 :
args -> V_40 = V_17 -> V_43 . V_45 ;
break;
case V_7 :
args -> V_40 = V_41 ;
break;
default:
F_35 ( L_1 ) ;
}
if ( V_17 -> V_54 & V_55 )
args -> V_64 = V_50 ;
else
args -> V_64 = args -> V_40 ;
if ( args -> V_40 == V_46 )
args -> V_40 = V_47 ;
if ( args -> V_40 == V_48 )
args -> V_40 = V_49 ;
F_17 ( V_24 ) ;
return 0 ;
}
