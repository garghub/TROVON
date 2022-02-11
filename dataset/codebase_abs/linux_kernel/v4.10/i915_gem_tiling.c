static bool
F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 )
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
if ( F_4 ( V_2 ) >= 7 ) {
if ( V_3 / 128 > V_10 )
return false ;
} else if ( F_4 ( V_2 ) >= 4 ) {
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
if ( F_4 ( V_2 ) >= 4 ) {
if ( V_3 & ( V_6 - 1 ) )
return false ;
return true ;
}
if ( V_3 & ( V_3 - 1 ) )
return false ;
return true ;
}
static bool F_6 ( struct V_13 * V_14 , int V_5 )
{
struct V_1 * V_2 = F_7 ( V_14 -> V_15 -> V_16 ) ;
T_1 V_4 ;
if ( ! F_8 ( V_14 ) )
return true ;
if ( F_4 ( V_2 ) == 3 ) {
if ( V_14 -> V_17 . V_18 & ~ V_19 )
return false ;
} else {
if ( V_14 -> V_17 . V_18 & ~ V_20 )
return false ;
}
V_4 = F_9 ( V_2 , V_14 -> V_4 , V_5 ) ;
if ( V_14 -> V_17 . V_4 < V_4 )
return false ;
if ( V_14 -> V_17 . V_18 & ( V_4 - 1 ) )
return false ;
return true ;
}
static int
F_10 ( struct V_21 * V_22 , int V_5 )
{
struct V_1 * V_2 = F_7 ( V_22 -> V_23 . V_16 ) ;
struct V_13 * V_14 ;
int V_24 ;
if ( V_5 == V_7 )
return 0 ;
if ( F_4 ( V_2 ) >= 4 )
return 0 ;
F_11 (vma, &obj->vma_list, obj_link) {
if ( F_6 ( V_14 , V_5 ) )
continue;
V_24 = F_12 ( V_14 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
int
F_13 ( struct V_25 * V_16 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_29 * args = V_26 ;
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_21 * V_22 ;
int V_30 = 0 ;
F_14 ( V_8 & V_31 ) ;
V_22 = F_15 ( V_28 , args -> V_32 ) ;
if ( ! V_22 )
return - V_33 ;
if ( ! F_1 ( V_2 ,
args -> V_3 , V_22 -> V_23 . V_4 , args -> V_5 ) ) {
F_16 ( V_22 ) ;
return - V_34 ;
}
F_17 ( & V_16 -> V_35 ) ;
if ( V_22 -> V_36 || V_22 -> V_37 ) {
V_30 = - V_38 ;
goto V_30;
}
if ( args -> V_5 == V_7 ) {
args -> V_39 = V_40 ;
args -> V_3 = 0 ;
} else {
if ( args -> V_5 == V_41 )
args -> V_39 = V_2 -> V_42 . V_43 ;
else
args -> V_39 = V_2 -> V_42 . V_44 ;
if ( args -> V_39 == V_45 )
args -> V_39 = V_46 ;
if ( args -> V_39 == V_47 )
args -> V_39 = V_48 ;
if ( args -> V_39 == V_49 ) {
args -> V_5 = V_7 ;
args -> V_39 = V_40 ;
args -> V_3 = 0 ;
}
}
if ( args -> V_5 != F_18 ( V_22 ) ||
args -> V_3 != F_19 ( V_22 ) ) {
V_30 = F_10 ( V_22 , args -> V_5 ) ;
if ( ! V_30 ) {
struct V_13 * V_14 ;
F_17 ( & V_22 -> V_42 . V_50 ) ;
if ( V_22 -> V_42 . V_51 &&
V_22 -> V_42 . V_52 == V_53 &&
V_2 -> V_54 & V_55 ) {
if ( args -> V_5 == V_7 ) {
F_20 ( ! V_22 -> V_42 . V_56 ) ;
F_21 ( V_22 ) ;
V_22 -> V_42 . V_56 = false ;
}
if ( ! F_22 ( V_22 ) ) {
F_20 ( ! V_22 -> V_42 . V_56 ) ;
F_23 ( V_22 ) ;
V_22 -> V_42 . V_56 = true ;
}
}
F_24 ( & V_22 -> V_42 . V_50 ) ;
F_11 (vma, &obj->vma_list, obj_link) {
if ( ! V_14 -> V_57 )
continue;
V_14 -> V_57 -> V_58 = true ;
}
V_22 -> V_59 =
args -> V_3 | args -> V_5 ;
F_25 ( V_22 ) ;
}
}
args -> V_3 = F_19 ( V_22 ) ;
args -> V_5 = F_18 ( V_22 ) ;
if ( F_26 ( V_22 ) ) {
if ( V_22 -> V_60 == NULL ) {
V_22 -> V_60 = F_27 ( F_28 ( V_22 -> V_23 . V_4 >> V_61 ) ,
sizeof( long ) , V_62 ) ;
}
} else {
F_29 ( V_22 -> V_60 ) ;
V_22 -> V_60 = NULL ;
}
V_30:
F_16 ( V_22 ) ;
F_24 ( & V_16 -> V_35 ) ;
return V_30 ;
}
int
F_30 ( struct V_25 * V_16 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_63 * args = V_26 ;
struct V_1 * V_2 = F_7 ( V_16 ) ;
struct V_21 * V_22 ;
int V_30 = - V_33 ;
F_31 () ;
V_22 = F_32 ( V_28 , args -> V_32 ) ;
if ( V_22 ) {
args -> V_5 =
F_33 ( V_22 -> V_59 ) & V_64 ;
V_30 = 0 ;
}
F_34 () ;
if ( F_35 ( V_30 ) )
return V_30 ;
switch ( args -> V_5 ) {
case V_41 :
args -> V_39 = V_2 -> V_42 . V_43 ;
break;
case V_9 :
args -> V_39 = V_2 -> V_42 . V_44 ;
break;
default:
case V_7 :
args -> V_39 = V_40 ;
break;
}
if ( V_2 -> V_54 & V_55 )
args -> V_65 = V_49 ;
else
args -> V_65 = args -> V_39 ;
if ( args -> V_39 == V_45 )
args -> V_39 = V_46 ;
if ( args -> V_39 == V_47 )
args -> V_39 = V_48 ;
return 0 ;
}
