static inline struct V_1 F_1 ( T_1 V_2 , int V_3 )
{
return V_4 [ V_2 ] [ V_3 ] ;
}
struct V_1 F_2 ( T_1 V_5 )
{
int V_6 ;
if ( V_5 == V_7 )
V_6 = V_8 ;
else
V_6 = V_9 ;
return V_4 [ V_5 ] [ V_6 ] ;
}
static bool F_3 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_12 ) {
case V_13 :
case V_14 :
return true ;
case V_15 :
return ( V_11 -> V_16 > 1 ) && ( V_11 -> V_17 == 1 ) ;
default:
return ( V_11 -> V_17 > 1 ) && ( V_11 -> V_16 == 1 ) ;
}
}
static void F_4 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_12 ) {
case V_13 :
case V_14 :
break;
case V_15 :
V_11 -> V_12 = V_18 ;
V_11 -> V_16 = 0 ;
break;
case V_18 :
V_11 -> V_12 = V_15 ;
V_11 -> V_17 = 0 ;
break;
}
}
static int F_5 ( struct V_10 * V_11 )
{
if ( V_11 -> V_19 == ( V_20 * 2 ) )
return V_21 ;
switch ( V_11 -> V_12 ) {
case V_13 :
case V_14 :
break;
case V_15 :
if ( V_11 -> V_22 == ( V_20 - 1 ) )
return V_23 ;
V_11 -> V_22 ++ ;
V_11 -> V_17 ++ ;
break;
case V_18 :
if ( V_11 -> V_22 == 0 )
return V_23 ;
V_11 -> V_22 -- ;
V_11 -> V_16 ++ ;
break;
}
V_11 -> V_19 ++ ;
return V_24 ;
}
static void F_6 ( struct V_10 * V_11 )
{
V_11 -> V_17 = 0 ;
V_11 -> V_16 = 0 ;
V_11 -> V_19 = 0 ;
V_11 -> V_12 = V_13 ;
}
static void F_7 ( struct V_10 * V_11 )
{
V_11 -> V_17 = 0 ;
V_11 -> V_16 = 0 ;
V_11 -> V_12 = V_14 ;
}
static void F_8 ( struct V_10 * V_11 )
{
V_11 -> V_12 = V_11 -> V_22 ? V_18 :
V_15 ;
F_5 ( V_11 ) ;
}
static int F_9 ( struct V_25 * V_26 ,
struct V_25 * V_27 )
{
if ( ! V_27 -> V_28 )
return V_26 -> V_28 ? V_29 :
V_30 ;
if ( F_10 ( V_26 -> V_28 , V_27 -> V_28 ) )
return ( V_26 -> V_28 > V_27 -> V_28 ) ? V_29 :
V_31 ;
if ( F_10 ( V_26 -> V_32 , V_27 -> V_32 ) )
return ( V_26 -> V_32 > V_27 -> V_32 ) ? V_29 :
V_31 ;
if ( F_10 ( V_26 -> V_33 , V_27 -> V_33 ) )
return ( V_26 -> V_33 < V_27 -> V_33 ) ? V_29 :
V_31 ;
return V_30 ;
}
static bool F_11 ( struct V_25 * V_34 ,
struct V_10 * V_11 )
{
int V_35 = V_11 -> V_12 ;
int V_36 = V_11 -> V_22 ;
int V_37 ;
int V_38 ;
switch ( V_11 -> V_12 ) {
case V_13 :
V_37 = F_9 ( V_34 , & V_11 -> V_39 ) ;
if ( V_37 != V_30 )
F_8 ( V_11 ) ;
break;
case V_14 :
V_11 -> V_19 -- ;
if ( ! V_11 -> V_19 )
F_8 ( V_11 ) ;
break;
case V_15 :
case V_18 :
V_37 = F_9 ( V_34 , & V_11 -> V_39 ) ;
if ( V_37 != V_29 )
F_4 ( V_11 ) ;
if ( F_3 ( V_11 ) ) {
F_6 ( V_11 ) ;
break;
}
V_38 = F_5 ( V_11 ) ;
switch ( V_38 ) {
case V_23 :
F_6 ( V_11 ) ;
break;
case V_21 :
F_7 ( V_11 ) ;
break;
}
break;
}
if ( ( V_35 != V_13 ) ||
( V_11 -> V_12 != V_13 ) )
V_11 -> V_39 = * V_34 ;
return V_11 -> V_22 != V_36 ;
}
static void F_12 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
V_43 -> time = F_13 () ;
V_43 -> V_44 = V_41 -> V_45 . V_46 ;
V_43 -> V_47 = V_41 -> V_45 . V_48 ;
V_43 -> V_49 = V_41 -> V_50 . V_49 ;
}
static void F_14 ( struct V_42 * V_51 ,
struct V_42 * V_52 ,
struct V_25 * V_34 )
{
T_2 V_53 = F_15 ( V_52 -> time , V_51 -> time ) ;
T_2 V_54 = F_16 ( F_17 ( T_2 ) , V_52 -> V_44 , V_51 -> V_44 ) ;
T_2 V_55 = F_16 ( F_17 ( T_2 ) , V_52 -> V_47 ,
V_51 -> V_47 ) ;
if ( ! V_53 )
return;
V_34 -> V_32 = F_18 ( V_54 * V_56 , V_53 ) ;
V_34 -> V_28 = F_18 ( V_55 * V_56 , V_53 ) ;
V_34 -> V_33 = F_18 ( V_57 * V_56 ,
V_53 ) ;
}
void F_19 ( struct V_58 * V_59 )
{
struct V_10 * V_11 = F_20 ( V_59 , struct V_10 ,
V_59 ) ;
struct V_40 * V_41 = F_20 ( V_11 , struct V_40 , V_11 ) ;
struct V_1 V_60 = V_4 [ V_11 -> V_61 ] [ V_11 -> V_22 ] ;
F_21 ( V_41 -> V_62 , & V_41 -> V_50 . V_63 ,
V_60 . V_64 , V_60 . V_65 ) ;
V_11 -> V_66 = V_67 ;
}
void V_10 ( struct V_40 * V_41 )
{
struct V_10 * V_11 = & V_41 -> V_11 ;
struct V_42 V_68 ;
struct V_25 V_34 ;
T_3 V_69 ;
switch ( V_11 -> V_66 ) {
case V_70 :
V_69 = F_16 ( F_17 ( T_3 ) , V_41 -> V_50 . V_49 ,
V_11 -> V_71 . V_49 ) ;
if ( V_69 < V_57 )
break;
F_12 ( V_41 , & V_68 ) ;
F_14 ( & V_11 -> V_71 , & V_68 ,
& V_34 ) ;
if ( F_11 ( & V_34 , V_11 ) ) {
V_11 -> V_66 = V_72 ;
F_22 ( & V_11 -> V_59 ) ;
break;
}
case V_67 :
F_12 ( V_41 , & V_11 -> V_71 ) ;
V_11 -> V_66 = V_70 ;
break;
case V_72 :
break;
}
}
